#include "Rational.h"

int main()
{
	int a = 2, b = 3;
	long c = 4, d = 5;

	rational<int, long> r1{a, c};
	std::cout << "r1<int, long>: " << r1 << std::endl;
	
	rational<int, int> r2{a, b};
	rational<long, long> r3{c, d};
	std::cout << "\nr2<int, int>: " << r2 << std::endl;
	std::cout << "r3<long, long>: " << r3 << std::endl;
	
	std::cout << "r2 + r3: " << (r2 + r3) << std::endl;
	std::cout << "r2 - r3: " << (r2 - r3) << std::endl;
	std::cout << "r2 * r3: " << (r2 * r3) << std::endl;
	std::cout << "r2 / r3: " << (r2 / r3) << std::endl;
	
	std::cout << "r2 += r3: " << (r2 += r3) << std::endl;
	std::cout << "r2 -= r3: " << (r2 -= r3) << std::endl;
	std::cout << "r2 *= r3: " << (r2 *= r3) << std::endl;
	std::cout << "r2 /= r3: " << (r2 /= r3) << std::endl;

	rational<long, long> r4 = {c, d};
	
	std::cout << "\nr4<long, long>: " << r4 << std::endl;
	rational<int, int> r5 = {1, 3};
	std::cout << "\nr5<int, int>: " << r5 << std::endl;
	std::cout << "r5 = r4" << std::endl;
	r5 = r4;
	std::cout << "r4<long, long>: " << r4 << std::endl;
	std::cout << "r5<int, int>: " << r5 << std::endl;
	
	rational<int, int> r6 = {1, 3};
	std::cout << "\nr6<int, int>: " << r6 << std::endl;
	std::cout << "r6 = std::move(r4)" << std::endl;
	r6 = std::move(r4);
	std::cout << "r4<long, long>: " << r4 << std::endl;
	std::cout << "r6<int, int>: " << r6 << std::endl;

	return 0;
}
