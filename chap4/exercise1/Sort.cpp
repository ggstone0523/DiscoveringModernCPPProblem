#include "Sort.h"

std::ostream& operator<<(std::ostream& os, const std::vector<double>& v)
{
	for(auto item : v)
		os << item << ' ';
	return os;
};

int main()
{
	std::vector<double> v1 = {-9.3, -7.4, -3.8, -0.4, 1.3, 3.9, 5.4, 8.2};
	std::vector<double> v2 = {-9.3, -7.4, -3.8, -0.4, 1.3, 3.9, 5.4, 8.2};

	std::cout << "Sort using functor:\n"
		  << "before: " << v1 << std::endl;
	compAbs_f compAbs_o{};
	std::sort(v1.begin(), v1.end(), compAbs_o);
	std::cout << "after: " << v1 << std::endl;

	std::cout << "\nSort using lambda expression:\n"	
		  << "before: " << v2 << std::endl;
	std::sort(v2.begin(), v2.end(), 
			[](double a, double b){ return std::abs(a) > std::abs(b); });
	std::cout << "after: " << v2 << std::endl;

	return 0;
}
