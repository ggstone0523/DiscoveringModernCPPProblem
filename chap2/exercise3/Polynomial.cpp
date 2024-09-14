#include "Polynomial.h"

polynomial makeQuadFunc(double c2, double c1, double c0)
{
	std::cout << "c2: " << c2 << ", c1: " << c1 << ", c0: " << c0 << std::endl;

	return polynomial({c2, c1, c0});
}

int main()
{
	polynomial a(2), b{3};
	a = makeQuadFunc(3.0, 0.0, 1.0);
	b = a;
	
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;

	return 0;
}
