#include <iostream>
#include <cmath>
#include <iomanip>

inline double functionF(double x);
int checkIntervalReverseSign(double start, double end);

inline double functionF(double x)
{
	return sin(5.0 * x) + cos(x);
}

int checkIntervalReverseSign(double start, double end) 
{
	double step = 0.0;
	double prevValue = 0.0;
	double currValue = 0.0;

	step = (end - start) / 100.0;

	prevValue = functionF(start);
	for(double i = start + step; i <= end; i += step) {
		currValue = functionF(i);
		if(std::signbit(prevValue) != std::signbit(currValue))
			return 1;
		prevValue = currValue;
	}

	return 0;
}

int main()
{
	double start = 0.0, end = std::numeric_limits<double>::max(), middle = 0.0;
	int isSignReversed = 0;

	while(end - start >= 1.0e-12) {
		middle = (end + start) / 2.0;

		if(checkIntervalReverseSign(start, middle)) {
			end = middle;
			isSignReversed = 1;
		} else if(checkIntervalReverseSign(middle, end)) {
			start = middle;
			isSignReversed = 1;
		}
		else {
			if(isSignReversed)
				end = middle;
			else {
				std::cerr << "This function not have root!" 
					  << " or root does not exist in this range."
					  << std::endl;
				exit(EXIT_FAILURE);
			}
		}

	}
	
	middle = (end + start) / 2.0;

	std::cout << "sin(5x) + cos(x)'s x is "
		  << std::setprecision(11) << std::setfill('0') 
		  << std::left << std::setw(13) <<start << std::endl;

	return 0;
}
