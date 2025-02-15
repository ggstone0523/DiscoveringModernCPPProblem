#include "VectorInherit.h"

int main()
{
	vector a(3);
	ones<double> b{3};

	for(int i = 0; i < a.getsize(); ++i)
		a(i) = i + 1;

	std::cout << "vector a:";
	for(int i = 0; i < a.getsize(); ++i)
		std::cout << " " << a(i);
	std::cout << '\n';
	
	std::cout << "ones b:";
	for(int i = 0; i < b.getsize(); ++i)
		std::cout << " " << b(i);
	std::cout << '\n';
	
	b = 6;
	std::cout << "after b = 6, ones b:";
	for(int i = 0; i < b.getsize(); ++i)
		std::cout << " " << b(i);
	std::cout << '\n';

	return 0;
}
