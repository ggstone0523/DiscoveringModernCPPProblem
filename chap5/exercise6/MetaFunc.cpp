#include "MetaFunc.h"

template <typename ...T2, typename T, typename ...P>
constexpr auto append(list_of_types<T, P...>)
{
	return list_of_types<T, P..., T2...> {};
};

template <typename T, typename ...P>
constexpr void info(list_of_types<T, P...>)
{
	std::cout << typeid(T).name() << " ";
	info(list_of_types<P...>{});
};

template <typename T>
constexpr void info(list_of_types<T>)
{
	std::cout << typeid(T).name() << '\n';
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

template <int index, int size, typename ...T2, typename T, typename ...P>
constexpr auto __erase(list_of_types<T, P...>)
{
	if constexpr (size == 1 && index == 0)
		return list_of_types<T2...>{};
	else if constexpr (size == 1)
		return list_of_types<T2..., T, P...>{};
	else if constexpr (index == 0)
		return __erase<index - 1, size - 1, T2...>(list_of_types<P...>{});
	else
		return __erase<index - 1, size - 1, T2..., T>(list_of_types<P...>{});
};

template <int index, typename T, typename ...P>
constexpr auto erase(list_of_types<T, P...> list)
{
	const int listSize = size(list);

	if constexpr ((0 > index) || (index >= listSize))
		return list;
	else if constexpr (listSize == 1 && index == 0)
		return list;
	else if constexpr (index == 0)
		return list_of_types<P...>{};
	else
		return __erase<index - 1, listSize - 1, T>(list_of_types<P...>{});
};

template <int start, int end, int size, typename ...T2, typename T, typename ...P>
constexpr auto __erase(list_of_types<T, P...>)
{
	if constexpr ((size == 1) && (end == 0))
		return list_of_types<T2...>{};
	else if constexpr (size == 1)
		return list_of_types<T2..., T, P...>{};
	else if constexpr (start <= 0 && end >= 0)
		return __erase<start - 1, end - 1, size - 1, T2...>(list_of_types<P...>{});
	else
		return __erase<start - 1, end - 1, size - 1, T2..., T>(list_of_types<P...>{});
};

template <int start, int End, typename T, typename ...P>
constexpr auto erase(list_of_types<T, P...> list)
{
	const int listSize = size(list);
	const int end = End - 1;
	
	if constexpr ((0 > start || start >= listSize) || (0 > end || end >= listSize))
		return list;
	else if constexpr ((End <= start) || ((End == listSize) && (start == 0)))
		return list;
	else if constexpr (end == start)
		return erase<start>(list);
	else if constexpr (start == 0)
		return __erase<start - 1, end - 1, listSize - 1>(list_of_types<P...>{});
	else
		return __erase<start - 1, end - 1, listSize - 1, T>(list_of_types<P...>{});
}

int main()
{
	list_of_types<void, int> lot{};
	info(lot);
	std::cout << size(lot) << std::endl;

	auto copy = append<void, float>(lot);
	info(copy);
	std::cout << size(copy) << std::endl;

	auto copy2 = insert<2, double>(copy);
	info(copy2);
	std::cout << size(copy2) << std::endl;
	
	auto copy3 = erase<2>(copy2);
	info(copy3);
	std::cout << size(copy3) << std::endl;
	
	auto copy4 = erase<2, 4>(copy3);
	info(copy4);
	std::cout << size(copy4) << std::endl;
	
	return 0;
}
