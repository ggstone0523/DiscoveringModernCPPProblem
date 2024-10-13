#include "MakeUnique.h"

template <typename T, typename ...U>
std::unique_ptr<T> make_unique_user(U&& ...args)
{
	return std::unique_ptr<T>{new T{std::forward<U>(args)...}};
};

int main()
{
	auto unique = make_unique_user<std::complex<int>>(5, 4);
	std::cout << unique->real() << ", " << unique->imag() << std::endl;
	return 0;
}
