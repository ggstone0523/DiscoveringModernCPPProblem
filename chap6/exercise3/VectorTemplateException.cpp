#include "VectorTemplateException.h"

int main()
{
	vector<double> a{3}, b{4}, c{3};
	
	for(int i = 0; i < 4; ++i) {
		if (i == 3)
			b[i] = i + 1;
		else
			a[i] = b[i] = i + 1;
	}

	try {
		a[3] = 1;
	} catch (const index_out_of_range& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		c = a + b; 
	} catch (const size_not_equal& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
