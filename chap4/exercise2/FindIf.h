#include <iostream>
#include <vector>
#include <algorithm>

template <class C, typename T>
requires std::is_same<typename C::value_type, T>::value
auto find_first_multiple(const C& vi, T i);
