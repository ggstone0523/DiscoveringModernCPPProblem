#include <iostream>
#include <type_traits>
#include <memory>
#include <initializer_list>

using namespace std;

template <typename T>
using copy_or_cref = conditional_t<is_lvalue_reference_v<T>,
      				   remove_reference_t<T> const&,
				   remove_reference_t<T>>;

template <typename T>
class Vector
{
	public:
		using value_type = T;
		explicit Vector(long unsigned int size) : my_size{size}, data{new T[size]} {}

		Vector(std::initializer_list<T> values)
			: my_size{values.size()}, data{new T[my_size]}
		{
			int i = 0;
			for(auto x : values) {
				data[i] = x;
				++i;
			}
		}

		long unsigned int size() const { return my_size; }

		const T& operator[](int i) const { return data[i]; }
		T& operator[](int i) { return data[i]; }

		template <typename Src>
		Vector& operator=(const Src& that)
		{
			for(int i = 0; i < my_size; ++i)
				data[i] = that[i];
			return *this;
		}
	private:
		long unsigned int my_size;
		std::shared_ptr<T[]> data;
};

template <typename VV1, typename VV2>
class Vector_sum
{
	public:
		using value_type = std::common_type_t<typename remove_reference_t<VV1>::value_type,
		      			      	      typename remove_reference_t<VV2>::value_type>;
		Vector_sum(VV1 v1, VV2 v2) : v1{v1}, v2{v2} {};
		value_type operator[](int i) const { return v1[i] + v2[i]; }
	private:
		VV1 v1;
		VV2 v2;
};

template <typename VV1, typename VV2>
Vector_sum(VV1&&, VV2&&)
	-> Vector_sum<copy_or_cref<VV1>, copy_or_cref<VV2>>;

template <typename T>
struct FlipReferVec {};

template<typename V>
struct FlipReferVec<Vector<V>&>
{
	using type = Vector<V>;
};

template<typename V>
struct FlipReferVec<Vector<V>>
{
	using type = Vector<V>&;
};

template<typename VV1, typename VV2>
struct FlipReferVec<Vector_sum<VV1, VV2>&>
{
	using type = Vector_sum<VV1, VV2>;
};

template<typename VV1, typename VV2>
struct FlipReferVec<Vector_sum<VV1, VV2>>
{
	using type = Vector_sum<VV1, VV2>&;
};

template <typename T>
struct is_vector
	: std::false_type {};

template <typename T>
constexpr bool is_vector_v = is_vector<T>::value;

template <typename T>
struct is_vector<const T>
	: is_vector<T> {};

template <typename VV1, typename VV2>
struct is_vector<Vector_sum<VV1, VV2>>
	: std::true_type {};

template <typename T>
struct is_vector<Vector<T>>
	: std::true_type {};

template <typename V1, typename V2>
auto operator+(V1&& x, V2&& y);
