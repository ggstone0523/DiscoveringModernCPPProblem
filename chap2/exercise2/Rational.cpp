#include "Rational.h"

int main()
{
	rational d = 4;
	std::cout << "d: " << d << std::endl;

	rational a{1, 2}, b{3, 5}, c{2, 3}, e{1}, f{1}, g{1}, h{1};
	e = a + b;
	f = a - b;
	g = a * b;
	h = a / b;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "a + b = " << e << std::endl;
	std::cout << "a - b = " << f << std::endl;
	std::cout << "a * b = " << g << std::endl;
	std::cout << "a / b = " << h << std::endl;
	std::cout << a << " + " << c << " = " << a + c << std::endl;
	std::cout << a << " - " << c << " = " << a - c << std::endl;
	std::cout << a << " * " << c << " = " << a * c << std::endl;
	std::cout << a << " / " << c << " = " << a / c << std::endl;
	
	rational i{1, 4}, j{1, 5};
	std::cout << "i: " << i << std::endl;
	std::cout << "j: " << j << std::endl;
	i += j;
	std::cout << "i += j; i = " << i << ", j = " << j << std::endl;
	i -= j;
	std::cout << "i -= j; i = " << i << ", j = " << j << std::endl;
	i *= j;
	std::cout << "i *= j; i = " << i << ", j = " << j << std::endl;
	i /= j;
	std::cout << "i /= j; i = " << i << ", j = " << j << std::endl;
	
	rational k{0, 3}, l{-2, 3}, m{5, -7};
	std::cout << "k: " << k << std::endl;
	std::cout << "l: " << l << std::endl;
	std::cout << "m: " << m << std::endl;
	std::cout << l << " + " << m << " = " << l + m << std::endl;
	std::cout << l << " - " << m << " = " << l - m << std::endl;
	std::cout << k << " * " << l << " = " << k * l << std::endl;
	std::cout << l << " / " << m << " = " << l / m << std::endl;

	return 0;
}
