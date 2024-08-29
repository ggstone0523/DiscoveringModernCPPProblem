#include <iostream>
#define ERROR 0 //if 1, narrowing conversion error!
		//if 0, no error occurs!

int main()
{
#if ERROR == 0
	const unsigned c1{4000000000};
	float f1{3};
	std::cout << c1 << std::endl;
	std::cout << f1 << std::endl;
#elif ERROR == 1
	const unsigned c2{-4000000000};
	int i1{1.2};
	bool b1{3};
	std::cout << c2 << std::endl;
	std::cout << i1 << std::endl;
	std::cout << b1 << std::endl;
#endif
	return 0;
}
