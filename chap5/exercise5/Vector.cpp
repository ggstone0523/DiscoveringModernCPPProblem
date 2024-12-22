#include "Vector.h"

int main()
{
	math::my_vector v(5);
	math::my_vector w(5);

	for(int i = 0; i < v.size(); ++i)
		v[i] = (double)i;

	w = 5.0 * v;
	for(int i = 0; i < v.size(); ++i)
		std::cout << w[i] << " ";

	w = 5.0 * (7.0 * v);
	std::cout << '\n';
	for(int i = 0; i < v.size(); ++i)
		std::cout << w[i] << " ";

	w = v + 7.0 * v;
	std::cout << '\n';
	for(int i = 0; i < v.size(); ++i)
		std::cout << w[i] << " ";
	std::cout << '\n';

	return 0;
}
