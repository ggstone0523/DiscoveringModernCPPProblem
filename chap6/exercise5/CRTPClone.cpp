#include "CRTPClone.h"

std::ostream& operator<<(std::ostream& os, const TwoNum& obj)
{
	os << "(" << obj.i << ", " << obj.f << ")";
	return os;
};

int main()
{
	TwoNum a{1, 3.2}, b;

	std::cout << "a: " << a << '\n';
	std::cout << "b: " << b << '\n';

	b = a.clone();
	std::cout << "after b = a.clone()\n";
	std::cout << "a: " << a << '\n';
	std::cout << "b: " << b << '\n';
	
	TwoNum c = b.clone();
	std::cout << "after TwoNum c = b.clone()\n";
	std::cout << "a: " << a << '\n';
	std::cout << "b: " << b << '\n';
	std::cout << "c: " << c << '\n';

	b.change(3, 9.6);
	std::cout << "after b.change(3, 9.6)\n";
	std::cout << "a: " << a << '\n';
	std::cout << "b: " << b << '\n';
	std::cout << "c: " << c << '\n';
	
	c.change(7, 22.4);
	std::cout << "after c.change(7, 22.4)\n";
	std::cout << "a: " << a << '\n';
	std::cout << "b: " << b << '\n';
	std::cout << "c: " << c << '\n';

	return 0;
}
