#include <iostream>
#include <typeinfo>
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

template <typename ...T2, typename T, typename ...P>
constexpr auto append(list_of_types<T, P...>);

template <typename T, typename ...P>
constexpr void info(list_of_types<T, P...>);

template <typename T>
constexpr void info(list_of_types<T>);

template <typename T, typename ...P>
constexpr int size(list_of_types<T, P...>);

template <typename T>
constexpr int size(list_of_types<T>);

template <int index, typename ...T2, typename T, typename ...P>
constexpr auto __insert(list_of_types<T, P...>);

template <int index, typename T, typename ...P>
constexpr auto __reverse__insert(list_of_types<T, P...>);

template <int index, typename ...T2, typename T, typename ...P>
constexpr auto insert(list_of_types<T, P...> list);

template <int index, int size, typename ...T2, typename T, typename ...P>
constexpr auto __erase(list_of_types<T, P...>);

template <int index, typename T, typename ...P>
constexpr auto erase(list_of_types<T, P...> list);

template <int start, int end, int size, typename ...T2, typename T, typename ...P>
constexpr auto __erase(list_of_types<T, P...>);

template <int start, int End, typename T, typename ...P>
constexpr auto erase(list_of_types<T, P...> list);
