#include "OddRange.h"

int main()
{
	for(int i : odd_range(7, 27))
		std::cout << i << "\n";
	return 0;
}
