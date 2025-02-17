#include "VectorExceptionTest.h"

template <typename E, typename T>
void test_vector_exception(T& test_func)
{
	try {
		test_func();
		throw missing_exception{};
	} catch (const E& e) {
		std::cerr << e.what() << std::endl;
	}
}

int main()
{
	vector<double> a{3}, b{4}, c{3};

	for(int i = 0; i < 4; ++i) {
		if (i == 3)
			b[i] = i + 1;
		else
			a[i] = b[i] = i + 1;
	}

	auto first_test = [&a](){ a[3] = 1; };
	test_vector_exception<index_out_of_range>(first_test);

	auto second_test = [a, b, &c](){ c = a + b; };
	test_vector_exception<size_not_equal>(second_test);
	
	auto third_test = [&a](){ a[2] = 1; };
	test_vector_exception<index_out_of_range>(third_test);

	return 0;
}
