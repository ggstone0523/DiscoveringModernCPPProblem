#include <iostream>
#include <memory>
#include <vector>
#include <cassert>
#include <type_traits>

namespace math {
	template <typename Vector>
	concept VectorLike = 
		requires (Vector v)
	{
		requires std::is_same_v<decltype(v.size()), int>;
		typename Vector::value_type;
		v[0];
	};

	class my_vector {
		public:
			using value_type = double;

			my_vector(int n) : dataSize{n}, data{new double[dataSize]} {};

			my_vector(my_vector const & v)
			: dataSize{v.size()}, data{new double[dataSize]}
			{
				for(int i = 0; i < dataSize; ++i)
					data[i] = v.data[i];
			};

			template <typename Vector>
				requires VectorLike<Vector>
			my_vector(Vector const& v)
			: dataSize{v.size()}, data{new double[dataSize]}
			{
				for(int i = 0; i < dataSize; ++i)
					data[i] = v[i];
			};

			my_vector& operator=(my_vector const& v)
			{
				assert(dataSize == v.size());

				for(int i = 0; i < dataSize; ++i)
					data[i] = v.data[i];
				return *this;
			};

			template <typename Vector>
				requires VectorLike<Vector>
			my_vector& operator=(Vector const& v)
			{
				assert(dataSize == v.size());
			
				for(int i = 0; i < dataSize; ++i)
					data[i] = v[i];
				return *this;
			};

			value_type& operator()(int i)
			{
				return data[i];
			};
		
			value_type& operator[](int i)
			{
				return data[i];
			};

			int size() const { return dataSize; };

			value_type operator()(int i) const
			{
				return data[i];
			};
		
			value_type operator[](int i) const
			{
				return data[i];
			};
		private:
			int dataSize;
			std::shared_ptr<double[]> data;
	};

	template <typename Scalar, typename Vector>
	class scalar_times_vector_expression
	{
		public:
			using value_type = std::common_type_t<typename Vector::value_type,
			      				      Scalar>;
		
			scalar_times_vector_expression(Scalar s, Vector v) : s{s}, v{v} {};
			int size() const { return v.size(); };
			value_type operator[](int const i) const { return s * v[i]; };
		private:
			const Scalar s;
			const Vector v;
	};

	template <typename V1, typename V2>
	class vector_plus_vector_expression
	{
		public:
			using value_type = std::common_type_t<typename V1::value_type,
			      				      typename V2::value_type>;
		
			vector_plus_vector_expression(V1 v1, V2 v2) : v1{v1}, v2{v2} 
			{
				dataSize = v1.size();
			};
			
			int size() const { return dataSize; };
			value_type operator[](int const i) const { return v1[i] + v2[i]; };
		private:
			const V1 v1;
			const V2 v2;
			int dataSize;
	};

	template <typename Scalar, typename Vector>
		requires VectorLike<Vector>
	scalar_times_vector_expression<Scalar, Vector>
	operator*(Scalar const& s, Vector const& v)
	{
		return scalar_times_vector_expression<Scalar, Vector>(s, v);
	};

	template <typename V1, typename V2>
		requires VectorLike<V1> && VectorLike<V2>
	vector_plus_vector_expression<V1, V2>
	operator+(V1 const& v1, V2 const& v2)
	{
		assert(v1.size() == v2.size());
		return vector_plus_vector_expression<V1, V2>(v1, v2);
	};
};
