#include "Polynomial.h"

int main()
{
	polynomial a({3.0, 2.0, 1.0, 0.0}), b = {6.0, 5.0, 4.0}, c(0);
	c = {9.0, 8.0, 0.0, 7.0, 10.0};
	
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;

	return 0;
}
