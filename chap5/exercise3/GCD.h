#include <iostream>
#include <numeric>

template <int A, int B>
struct gcd_meta {
	static int const value = gcd_meta<B, A % B>::value;
};

template <int A>
struct gcd_meta <A, 0> {
	static int const value = A;
};

template <typename I>
constexpr I gcd(I a, I b);
