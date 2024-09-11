#include "Polynomial.h"

int main()
{
	polynomial a(3), b(4), c(3), d(3), e(3);
	a = {3, -2, 1, 1};
	b = {4, -1, 3, 0, -2};
	c = (a + b);
	d = (a - b);
	e = b;
	
	std::cout << a << std::endl;
	std::cout << e << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;

	return 0;
}
