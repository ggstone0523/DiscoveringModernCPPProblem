#include <iostream>
#include <initializer_list>
#include <memory>
#include <cassert>

template <typename T>
class vector_expression;

class vector;

template <typename T>
class ones;

template <typename T>
class vector_expression
{
	public:
		vector_expression(int size) : size{size} {}

		int getsize() { return size; }
		
		const int getsize() const { return size; }

		void setsize(int newsize) { size = newsize; }

		virtual T& operator()(int i) 
		{ 
			assert(i >= 0 && i < getsize());
			return data; 
		}
	private:
		int size;
		T data;
};

class vector : public vector_expression<double>
{
	public:
		vector(int n)
			: vector_expression{n}, data{new double[getsize()]} {}

		vector(const vector& v)
			: vector_expression{v.getsize()}, data{new double[getsize()]} 
		{
			int size = getsize();
			for (unsigned i = 0; i < size; ++i)
				data[i] = v.data[i];
		}

		vector(vector&& v) noexcept
			:vector_expression{v.getsize()}
		{
			int size = getsize();
			for(unsigned i = 0; i < size; ++i)
				data[i] = v.data[i];
			v.data = nullptr;
			v.setsize(0);
		}

		vector(std::initializer_list<double> values)
			: vector_expression{(int)values.size()}, data{new double[getsize()]}
		{
			int count = 0;
			for(auto i : values) {
				data[count] = i;
				count++;
			}
		}

		vector& operator=(std::initializer_list<double> values)
		{
			assert(getsize() == values.size());
			int count = 0;
			for(auto i : values) {
				data[count] = i;
				count++;
			}
			return *this;
		}

		vector& operator=(vector&& src) noexcept
		{
			int size = getsize();
			assert(size == src.getsize());
			for(unsigned i = 0; i < size; ++i)
				data[i] = src.data[i];
			src.data = nullptr;
			src.setsize(0);
			return *this;
		}

		vector& operator=(const vector& src) &
		{
			int size = getsize();
			assert(size == src.getsize());
			for (unsigned i = 0; i < size; ++i)
				data[i] = src.data[i];
			return *this;
		}

		double at(int i)
		{
			assert(i >= 0 && i < getsize());
			return data[i];
		}

		virtual double& operator()(int i) override
		{
			vector_expression::operator()(i);
			return data[i];
		}

		double& operator[](int i) &
		{
			assert(i >= 0 && i < getsize());
			return data[i];
		}
		
		const double& operator[](int i) const&
		{
			assert(i >= 0 && i < getsize());
			return data[i];
		}
	
		double operator[](int i) &&
		{
			assert(i >= 0 && i < getsize());
			return data[i];
		}
	private:
		std::unique_ptr<double[]> data;
};

template <typename T>
class ones : public vector_expression<T>
{
	public:
		ones(int n)
			: vector_expression<T>{n}, data{new T[this->getsize()]} 
		{
			int size = this->getsize();
			for (unsigned i = 0; i < size; ++i)
				data[i] = 1;
		}

		ones(const ones& o)
			: vector_expression<T>{o.getsize()}, data{new T[this->getsize()]} 
		{
			int size = this->getsize();
			for (unsigned i = 0; i < size; ++i)
				data[i] = 1;
		}
		
		ones(ones&& o) noexcept
			: vector_expression<T>{o.getsize()}
		{
			int size = this->getsize();
			for(unsigned i = 0; i < size; ++i)
				data[i] = 1;
			o.data = nullptr;
			o.setsize(0);
		}
		
		ones& operator=(int size)
		{
			this->setsize(size);
			data = std::make_unique<T[]>(this->getsize());
			for(int i = 0; i < size; ++i)
				data[i] = 1;
			return *this;
		}

		T at() { return data; }

		virtual T& operator()(int i) override 
		{
			vector_expression<T>::operator()(i);
		       	return data[i]; 
		}
		
		T & operator[](int i) &
		{
			assert(i >= 0 && i < this->getsize());
			return data[i];
		}
		
		const T& operator[](int i) const&
		{
			assert(i >= 0 && i < this->getsize());
			return data[i];
		}
		
		T operator[](int i) &&
		{
			assert(i >= 0 && i < this->getsize());
			return data[i];
		}
	private:
		std::unique_ptr<T[]> data;
};
