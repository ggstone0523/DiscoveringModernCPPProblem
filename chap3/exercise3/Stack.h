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
