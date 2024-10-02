#include "OddIter.h"

int main()
{
	odd_iterator a(1), b(1);

	std::cout << "a: " << *a << std::endl;
	b = ++a;
	std::cout << "(b = ++a) => " << "a: " << *a << ", b: " << *b << std::endl;
	b = a++;
	std::cout << "(b = a++) => " << "a: " << *a << ", b: " << *b << std::endl;
	std::cout << "(a != b) => " << ((a != b) ? "True" : "False") << std::endl;
	std::cout << "(a == b) => " << ((a == b) ? "True" : "False") << std::endl;
	++b;
	std::cout << "(++b) => "<< "a: " << *a << ", b: " << *b << std::endl;
	std::cout << "(a != b) => " << ((a != b) ? "True" : "False") << std::endl;
	std::cout << "(a == b) => " << ((a == b) ? "True" : "False") << std::endl;
	a = 13;
	std::cout << "(a = 13) => " << "a: " << *a << std::endl;

	try {
		odd_iterator c(10);
	} catch (const std::domain_error& e) {
		std::cout << "Error! odd_iterator c(10): " << e.what() << std::endl;
	}

	odd_iterator begin, end(11);
	int sumOfOdds = 0;
	for(; begin != end; ++begin)
		sumOfOdds += *begin;
	std::cout << "Sum of odds range 1 - 9 is " << sumOfOdds << std::endl;

	return 0;
}
