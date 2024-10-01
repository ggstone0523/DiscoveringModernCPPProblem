#include <iostream>
#include <cassert>
#include <algorithm>

template <typename T>
class vector_iterator
{
	public:
		using value_type = T;
		using difference_type = int;
		using reference = T&;
		using iterator_category = std::random_access_iterator_tag;

		vector_iterator(T* entry, T* startEntry, int size) 
			: entry{entry}, startEntry{startEntry}, size{size} {}
		
		vector_iterator& operator++()
		{ 
			entry++;
			return *this;
	       	}
		
		vector_iterator& operator--()
		{ 
			entry--;
			return *this;
	       	}

		vector_iterator& operator+=(difference_type n)
		{ 
			entry += n;
			return *this;
	       	}

		vector_iterator operator+(difference_type n)
		{ return vector_iterator(entry + n, startEntry, size); }

		vector_iterator& operator-=(difference_type n)
		{ 
			entry -= n;
			return *this;
	       	}

		vector_iterator operator-(difference_type n)
		{ return vector_iterator(entry - n, startEntry, size); }

		difference_type operator-(const vector_iterator& other)
		{ return entry - other.entry; }

		reference operator*()
		{ return *entry; }
		
		reference operator[](int i)
		{ return entry[i]; }

		bool operator<(const vector_iterator& other)
		{ return entry < other.entry; }
		
		bool operator>(const vector_iterator& other)
		{ return entry > other.entry; }
		
		bool operator>=(const vector_iterator& other)
		{ return entry >= other.entry; }
		
		bool operator<=(const vector_iterator& other)
		{ return entry <= other.entry; }
		
		bool operator==(const vector_iterator& other)
		{ return entry == other.entry; }
		
		bool operator!=(const vector_iterator& other)
		{ return entry != other.entry; }

		bool isOverflow()
		{
			return entry >= (startEntry + size);
		}
		
		bool isUnderflow()
		{
			return entry < startEntry;
		}
	private:
		T* entry;
		T* startEntry;
		int size;
};

template <typename T>
class vector
{
	public:
		explicit vector(int size)
			: my_size{size}, data{new T[my_size]},
			  iterator{vector_iterator<T>(data, data, my_size)},
			  const_iterator{vector_iterator<T>(data, data, my_size)}
	       	{}

		vector(const vector& that)
			: my_size{that.my_size}, data{new T[my_size]} 
		{
			std::copy(&that.data[0], &that.data[that.my_size], &data[0]);
		}

		int size() const { return my_size; }

		T& operator[](int i) const
		{
			check_index(i);
			return data[i];
		}

		vector_iterator<T> begin() { return iterator; }
		
		const vector_iterator<T> begin() const { return const_iterator; }

		vector_iterator<T> end() 
		{ return vector_iterator(data + my_size, data + my_size, 0); }

		~vector() { delete[] data; }
	private:
		void check_index(int i) const
		{
			assert(i >= 0 && i < my_size);
		}

		int my_size;
		T* data;
		vector_iterator<T> iterator;
		const vector_iterator<T> const_iterator;
};
