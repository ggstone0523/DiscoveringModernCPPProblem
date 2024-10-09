#include "Trapezoid.h"

// generic programming method
template <typename F, typename T>
auto trapezoid(F f, const T& a, const T& b)
{
	int n = 1000;
	T h = (b - a) / n;
	
	T sig = 0;
	for(int i = 1; i < n; i++) 
		sig += f(a + (i * h));

	return (h / 2 * (f(a) + f(b))) + (h * sig);
};

// inheritance method
double trapezoidInherit(functor_base const& f, double a, double b)
{
	int n = 1000;
	double h = (b - a) / n;
	
	double sig = 0;
	for(int i = 1; i < n; i++) 
		sig += f(a + (i * h));

	return (h / 2 * (f(a) + f(b))) + (h * sig);
};

int main()
{
	std::cout << "using generic programming method" << std::endl;
	std::cout << "-----------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "If x in [0, 4], integrate f=exp(3x) using trapezoid rule: " << trapezoid(exp3t{}, 0.0, 4.0) << std::endl;
	std::cout << "If x in [0, 4], integrate (if x < 1, f=sin(x)), (if x >= 1, f=cos(x)) using trapezoid rule: " << trapezoid(sinonecost{}, 0.0, 4.0) << std::endl;
	std::cout << "-----------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "trapezoid(std::sin, 0.0, 2.0): " << "error!" << std::endl;
	std::cout << "trapezoid((double(*)(double))std::sin, 0.0, 2.0): " << trapezoid((double(*)(double))std::sin, 0.0, 2.0) << std::endl;
	std::cout << "-----------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "ext3t{}(4.0) - ext3t{}(0.0): " << exp3t{}(4.0) - exp3t{}(0.0) << std::endl;
	std::cout << "trapezoid(findiff{exp3t{}, 0.001}, 0.0, 4.0): " << trapezoid(findiff{exp3t{}, 0.001}, 0.0, 4.0) << std::endl;

	std::cout << "\nusing inheritance method" << std::endl;
	std::cout << "-----------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "If x in [0, 4], integrate f=exp(3x) using trapezoid rule: " << trapezoidInherit(exp3tInherit{}, 0.0, 4.0) << std::endl;
	std::cout << "If x in [0, 4], integrate (if x < 1, f=sin(x)), (if x >= 1, f=cos(x)) using trapezoid rule: " << trapezoidInherit(sinonecostInherit{}, 0.0, 4.0) << std::endl;
	std::cout << "-----------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "trapezoidInherit(std::sin, 0.0, 2.0): " << "error!" << std::endl;
	std::cout << "trapezoidInherit((double(*)(double))std::sin, 0.0, 2.0): " << "error!" << std::endl;
	std::cout << "-----------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "exp3tInherit{}(4.0) - exp3tInherit{}(0.0): " << exp3tInherit{}(4.0) - exp3tInherit{}(0.0) << std::endl;
	std::cout << "trapezoidInherit(findiffInherit{exp3tInherit{}, 0.001}, 0.0, 4.0): " << trapezoidInherit(findiffInherit{exp3tInherit{}, 0.001}, 0.0, 4.0) << std::endl;
	
	return 0;
}
