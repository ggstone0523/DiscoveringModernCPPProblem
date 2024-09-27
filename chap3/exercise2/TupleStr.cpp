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

template <typename ...P>
std::string to_tuple_string2(P ...args)
{
	std::stringstream os;
	std::initializer_list init{(to_string(args))...};
	os << '(';
	for(auto i : init)
		os << i << ", ";
        os.seekp(-2, std::ios::cur);
	os << ')';
	return os.str();	
}

template <typename T>
std::string to_string(T arg, std::string marks)
{
	std::stringstream os;
	os << arg << marks;
	return os.str();
}

template <typename ...P>
std::string __to_tuple_string3(P& ...args)
{

	return (to_string(args, ", ") + ...);
}

template <typename ...P>
std::string to_tuple_string3(P ...args)
{
	std::stringstream os;
	os << '(';
	os << __to_tuple_string3(args...);
        os.seekp(-2, std::ios::cur);
	os << ')';
	return os.str();
}

int main()
{
	std::string s1, s2, s3;

	s1 = to_tuple_string(1, -3.14, 'a', "hello", "hi", "my", "name", "is", "choi", "yusun");
	std::cout << "variadic template: " << s1 << std::endl;
	
	s2 = to_tuple_string2(1, -3.14, 'a', "hello", "hi", "my", "name", "is", "choi", "yusun");
	std::cout << " initializer list: " << s2 << std::endl;
	
	s3 = to_tuple_string3(1, -3.14, 'a', "hello", "hi", "my", "name", "is", "choi", "yusun");
	std::cout << "  fold expression: " << s3 << std::endl;

	return 0;
}
