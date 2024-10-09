#include "NonCallObjAbs.h"

template <typename T>
decltype(auto) abs(const T& x)
{
	return abs_functor<T>::eval(x);
};

int main()
{
	std::complex<double> x{-4.0, 2.0}, y{4.0, 2.0};
	double z = -5.0;

	std::cout << "abs({-4.0, 2.0}): " << abs(x) << std::endl;
	std::cout << "abs({4.0, 2.0}) : " << abs(y) << std::endl;
	std::cout << "abs(-5.0)       : " << abs(z) << std::endl;

	return 0;
}
