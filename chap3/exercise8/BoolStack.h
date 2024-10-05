#include <iostream>
#include <stdexcept>
#include <string>

template <typename T, size_t N>
	requires(N > 0)
class stack
{
	public:
		stack() : index{-1}, arr{new T[N]} {}

		T top() { return arr[index]; };

		void pop()
		{
			if(empty())
				throw std::underflow_error("Stack underflow!");
			index -= 1;
		}

		void push(T newElement)
		{
			if(full())
				throw std::overflow_error("Stack overflow!");
			index += 1; 
			arr[index] = newElement;
		}

		void clear() { index = -1; }

		unsigned size() { return index + 1; }

		bool full() { return size() == N; }

		bool empty() { return index == -1; }
		
		~stack() { delete[] arr; }
	private:
		T* arr;
		int index;
};

template <size_t N>
class stack<bool, N>
{
	public:
		stack()
			: index{-1}, 
			  arr{new unsigned char[(N / 8) + (((N % 8) == 0) ? 0 : 1)]}, shift{7}
		{}

		bool top() { return (arr[index] >> shift) & 1; }

		void pop()
		{
			if(empty())
				throw std::underflow_error("Stack underflow!");
			if(shift == 0) {
				index -= 1;
				shift = 7;
			} else
				shift -= 1;
		}

		void push(bool newElement)
		{
			if(full())
				throw std::overflow_error("Stack overflow!");
			if(shift == 7) {
				index += 1;
				shift = 0;
			} else
				shift += 1;

			unsigned char mask = (1 << shift);
			arr[index] = (newElement ? (arr[index] | mask) : (arr[index] & ~(mask)));
		}

		void clear() 
		{ 
			index = -1;
			shift = 7;
		}

		unsigned size() { return (index * 8) + (shift + 1); }

		bool full() { return size() == N; }

		bool empty() { return size() == 0; }

		~stack() { delete[] arr; }
	private:
		unsigned char* arr;
		int index;
		unsigned char shift;
};
