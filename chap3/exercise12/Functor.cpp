#include "Functor.h"

template <unsigned N, typename F, typename T>
findiff<N, F, T>
findiff_f(const F& f, const T& h)
{
	return findiff<N, F, T>{f, h};
}

int main()
{
	auto d_cosxpsx = findiff_f<1>(cosxpsx{}, 0.001);
	std::cout << "if x == 3, derivative of cos(x) + x^2: "<< d_cosxpsx(3) << std::endl;
	auto dd_cosxpsx = findiff_f<2>(cosxpsx{}, 0.001);
	std::cout << "if x == 3, second derivative of cos(x) + x^2: "<< dd_cosxpsx(3) << std::endl;
	
	auto d_two = findiff_f<1>(two{}, 0.001);
	std::cout << "if x == 3, derivative of 2: "<< d_two(3) << std::endl;
	auto dd_two = findiff_f<2>(two{}, 0.001);
	std::cout << "if x == 3, second derivative of 2: "<< dd_two(3) << std::endl;

	return 0;
}
