#include <iostream>
#include <stdexcept>

class odd_iterator
{
	public:
		odd_iterator(int odd = 1) : odd{odd} 
		{
			if(odd % 2 == 0)
				throw std::domain_error("Value must be odd!");
		}

		odd_iterator& operator=(odd_iterator& that)
		{
			odd = that.odd;
			return *this;
		}
		
		odd_iterator& operator=(const odd_iterator& that)
		{
			odd = that.odd;
			return *this;
		}

		odd_iterator& operator++()
		{
			odd+=2;
			return *this;
		}
		
		odd_iterator operator++(int)
		{
			int temp = odd;
			odd+=2;
			return odd_iterator(temp);
		}

		int& operator*() { return odd; }

		bool operator==(const odd_iterator& that) const
		{
			return odd == that.odd;
		}
		
		bool operator!=(const odd_iterator& that) const
		{
			return odd != that.odd;
		}
		
		odd_iterator& operator=(int newOdd)
		{
			if(newOdd % 2 == 0)
				throw std::domain_error("Value must be odd!");
			odd = newOdd;
			return *this;
		}
	private:
		int odd;
};
