#include <iostream>

template <long N>
struct fibonacci
{
	static const long value = fibonacci<N-1>::value + fibonacci<N-2>::value;
};

template <>
struct fibonacci<0>
{
	static const long value = 0;
};

template <>
struct fibonacci<1>
{
	static const long value = 1;
};
