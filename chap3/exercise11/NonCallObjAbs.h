#include <iostream>
#include <complex>

template <typename T>
struct abs_functor
{
	typedef T result_type;

	static T eval(const T& x)
	{
		return x < T(0) ? -x : x;
	}
};

template <typename T>
struct abs_functor<std::complex<T>>
{
	typedef T result_type;

	static T eval(const std::complex<T>& x)
	{
		return sqrt(real(x)*real(x) + imag(x)*imag(x));
	}
};

template <typename T>
decltype(auto) abs(const T& x);
