#include "Lambda.h"

template <unsigned N>
auto findiff_f = [](auto f, auto x, auto h)
{
	auto pf = [&](auto x2)
	{
		return findiff_f<N-1>(f, x2, h);
	};
	return (pf(x + h) - pf(x)) / h;
};

template <>
auto findiff_f<1> = [](auto f, auto x, auto h)
{
	return (f(x + h) - f(x)) / h;
};

int main()
{
	auto two_f = [](auto x){ return 2; };
	auto cosxpsx_f = [](auto x){ return std::cos(x) + (x * x); };

	std::cout << "if x == 3, derivative of cos(x) + x^2: " 
		  << findiff_f<1>(cosxpsx_f, 3, 0.001) << std::endl;
	std::cout << "if x == 3, second derivative of cos(x) + x^2: "
		  << findiff_f<2>(cosxpsx_f, 3, 0.001) << std::endl;
	
	std::cout << "if x == 3, derivative of 2: " 
		  << findiff_f<1>(two_f, 3, 0.001) << std::endl;
	std::cout << "if x == 3, second derivative of 2: " 
		  << findiff_f<2>(two_f, 3, 0.001) << std::endl;

	return 0;
}
