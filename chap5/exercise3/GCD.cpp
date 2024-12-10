#include "GCD.h"

template <typename I>
constexpr I gcd(I a, I b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int main()
{
	std::cout << "std::gcd(20, 12) = " << std::gcd(20, 12) << std::endl;
	std::cout << "(constexpr)gcd(20, 12) = " << gcd(20, 12) << std::endl;
	std::cout << "gcd_meta<20, 12>::value = " << gcd_meta<20, 12>::value << std::endl;

	return 0;
};
