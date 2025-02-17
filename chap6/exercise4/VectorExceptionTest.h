#include <cassert>
#include <iostream>
#include <memory>
#include <exception>
#include <string>
#include <sstream>

struct index_out_of_range;

struct size_not_equal;

struct missing_exception;

template <typename T>
class vector;

template <typename E, typename T>
void test_vector_exception(T& test_func);

struct index_out_of_range : std::out_of_range
{
	index_out_of_range(const std::string& message = "input index is out of index range")
		: std::out_of_range(message) {}
};

struct size_not_equal : std::length_error
{
	size_not_equal(const std::string& message = "two element's size is not equal")
		: std::length_error(message) {}
};

struct missing_exception : std::logic_error
{
	missing_exception(const std::string& message = "try-catch block miss exception")
		: std::logic_error(message) {}
};

template <typename T>
class vector 
{
	void check_size(int that_size) const 
	{ 
		if(my_size != that_size) {
			std::ostringstream string_stream;
			string_stream << "size " << my_size << " and "
				      << "size " << that_size << " is not equal";
			throw size_not_equal{string_stream.str()};
		}
	}

	void check_index(int i) const 
	{ 
		if(i < 0 || i >= my_size) {
			std::ostringstream string_stream;
			string_stream << "input index " << i
				      << " is out of index range "
				      << "(0 ~ " << my_size - 1 << ")";
			throw index_out_of_range{string_stream.str()};
		}
	}
	public:
		explicit vector(int size) : my_size{size}, data{ new T[my_size] } {}

		vector() : my_size{0}, data{0} {}

		vector(const vector& that) : my_size{that.my_size}, data{new T[my_size]}
		{
			std::copy(&that.data[0], &that.data[that.my_size], &data[0]);
		}

		vector& operator=(const vector& that) 
		{
			check_size(that.my_size);
			std::copy(&that.data[0], &that.data[that.my_size], &data[0]);
			return *this;
		}

		int size() const { return my_size; }

		const T& operator[](int i) const 
		{
			check_index(i);
			return data[i];
		}
		     
		T& operator[](int i) 
		{
			check_index(i);
			return data[i];
		}

		vector operator+(const vector& that) const 
		{
			check_size(that.my_size);
			vector sum(my_size);
			for (int i= 0; i < my_size; ++i) 
				sum[i] = data[i] + that[i];
			return sum;
		}
	private:
		int my_size;
		std::unique_ptr<T[]> data;
};
