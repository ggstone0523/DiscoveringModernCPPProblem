#include <iostream>

template <typename T>
struct cloneable;

class TwoNum;

std::ostream& operator<<(std::ostream& os, const TwoNum& obj);

template <typename T>
struct cloneable
{
	T clone() 
	{ 
		T result = static_cast<const T&>(*this);
		return result;
	}
};

class TwoNum : public cloneable<TwoNum>
{
	public:
		TwoNum(int i, float f) : i{i}, f{f} {}
		
		TwoNum() : i{0}, f{0} {}
		
		void change(int io, float fo)
		{
			i = io;
			f = fo;
		}

		friend std::ostream& operator<<(std::ostream&, const TwoNum&);
	private:
		int i;
		float f;
};
