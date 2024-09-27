#include <iostream>
#include <string>
#include <sstream>
#include <initializer_list>

template <typename T>
std::string to_string(T arg);

template <typename T>
std::string __to_tuple_string(T arg);

template <typename T, typename ...P>
std::string __to_tuple_string(T arg, P ...args);

template <typename ...P>
std::string to_tuple_string(P ...args);

template <typename ...P>
std::string to_tuple_string2(P ...args);

template <typename T>
std::string to_string(T arg, std::string marks);

template <typename ...P>
std::string __to_tuple_string3(P& ...args);

template <typename ...P>
std::string to_tuple_string3(P ...args);
