#include "TupleStr.h"

template <typename T>
std::string to_string(T arg)
{
	std::stringstream os;
	os << arg;
	return os.str();
}

template <typename T>
std::string __to_tuple_string(T arg)
{
	return to_string(arg);
}

template <typename T, typename ...P>
std::string __to_tuple_string(T arg, P ...args)
{
	return to_string(arg) + ", " + __to_tuple_string(args...);
}

template <typename ...P>
std::string to_tuple_string(P ...args)
{
	std::string s;
	s += '(';
	s += __to_tuple_string(args...);
	s += ')';

	return s;
}

int main()
{
	std::string s;
	s = to_tuple_string(1, "hello", "hi", "my", "name", "is", "choi", "yusun");

	std::cout << s << std::endl;

	return 0;
}
