#include <iostream>
#include <typeinfo>
#include <tuple>
#include <cassert>

template <typename ...P> struct list_of_types;

template <typename T>
struct list_of_types<T>
{
	using type = T;
};

template <typename T, typename ...P>
struct list_of_types<T, P...>
{
	using type = T;
};

template <int N, typename ...P>
using NthTypeOf = typename std::tuple_element<N, std::tuple<P...>>::type;

template <typename ...T2, typename T, typename ...P>
constexpr auto append(list_of_types<T, P...>)
{
	return list_of_types<T, P..., T2...> {};
};

template <typename T, typename ...P>
constexpr void info(list_of_types<T, P...>)
{
	std::cout << typeid(T).name() << std::endl;
	info(list_of_types<P...>{});
};

template <typename T>
constexpr void info(list_of_types<T>)
{
	std::cout << typeid(T).name() << std::endl;
};

template <typename T, typename ...P>
constexpr int size(list_of_types<T, P...>)
{
	return 1 + size(list_of_types<P...>{});
};

template <typename T>
constexpr int size(list_of_types<T>)
{
	return 1;
};

template <int index, typename ...T2, typename T, typename ...P>
constexpr auto __insert(list_of_types<T, P...>)
{
	if constexpr (index == 0)
		return list_of_types<T2..., T, P...>{};
	else
		return __insert<index - 1, T, T2...>(list_of_types<P...>{});
};

template <int index, typename T, typename ...P>
constexpr auto __reverse__insert(list_of_types<T, P...>)
{
	return __insert<index - 1, T>(list_of_types<P...>{});
}

template <int index, typename ...T2, typename T, typename ...P>
constexpr auto insert(list_of_types<T, P...> list)
{
	const int listSize = size(list);
	assert(0 <= index && index <= listSize);

	if constexpr (index == 0)
		return list_of_types<T2..., T, P...> {};
	else if constexpr (listSize == index)
		return append<T2...>(list);
	else {
		auto copy = __insert<index - 1, T, T2...>(list_of_types<P...>{});
		return __reverse__insert<index>(copy);
	}
};

int main()
{
	list_of_types<void, int> lot{};
	info(lot);
	std::cout << size(lot) << std::endl;

	auto copy = append<int, float>(lot);
	info(copy);
	std::cout << size(copy) << std::endl;

	auto copy2 = insert<2, double>(copy);
	info(copy2);
	std::cout << size(copy2) << std::endl;
	
	return 0;
}
