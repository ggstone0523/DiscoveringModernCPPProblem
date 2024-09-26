#include "ToString.h"

template <typename T>
std::string to_string(const T& arg)
{
	std::stringstream strs;
	strs << std::setprecision(8) << arg;

	return strs.str();
}

int main()
{
	std::string s;

	double minusPi = -3.141592;
	s = to_string<double>(minusPi);
	std::cout << std::right << std::setw(9) << "minusPi: " << s << ", "
		  << std::right << std::setw(15) << "minusPi's type: " 
		  << typeid(s).name() << std::endl;
	
	char c = 'A';
	s = to_string<char>(c);
	std::cout << std::right << std::setw(9) << "c: " << s 
		  << std::right << std::setw(10) << ", "
		  << std::right << std::setw(16) << "c's type: " 
		  << typeid(s).name() << std::endl;

	return 0;
}
