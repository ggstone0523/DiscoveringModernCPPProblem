#include "FindIf.h"

template <class C, typename T>
requires std::is_same<typename C::value_type, T>::value
auto find_first_multiple(const C& vi, T i)
{
	return std::find_if(std::begin(vi), std::end(vi),
			[i](T x){ return (x % i == 0); });
};

int main()
{
	std::vector<int> vi{12, 3, 15, 5, 7, 9};
	for(int i = 2; i < 10; ++i) {
		auto it = find_first_multiple(vi, i);
		if(it != std::end(vi))
			std::cout << "The first multiple of " << i << " is " << *it << std::endl;
		else
			std::cout << "There is no multiple of " << i << std::endl;
	}

	return 0;
}
