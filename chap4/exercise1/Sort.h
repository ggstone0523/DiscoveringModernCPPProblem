#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ostream>

struct compAbs_f {
	bool operator()(double a, double b) const
	{
		return std::abs(a) > std::abs(b);
	}
};

std::ostream& operator<<(std::ostream& os, const std::vector<double>& v);
