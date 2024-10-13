#include <iostream>
#include <memory>
#include <complex>

template <typename T, typename ...U>
std::unique_ptr<T> make_unique_user(U&& ...args);
