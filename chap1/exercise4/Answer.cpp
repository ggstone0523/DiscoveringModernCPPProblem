#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[])
{
	if(argc != 4) {
		std::cerr << "Usage: ./Answer num1 num2 num3" << std::endl;
		exit(EXIT_FAILURE);
	}

	std::vector<double> numArray(3);

	for(int i = 0; i < numArray.size(); i++)
		numArray[i] = std::stod(argv[i + 1]);

	double centerNum = (numArray[0] > numArray[1]) ? 
		(numArray[1] > numArray[2] ? 
		 numArray[1] : 
		 (numArray[0] > numArray[2] ? 
		  numArray[2] : numArray[0])) : 
		(numArray[0] > numArray[2] ? 
		 numArray[0] : 
		 (numArray[1] > numArray[2] ? 
		  numArray[2] : numArray[1]));

	std::cout << "Center number of " 
		  << numArray[0] << " "
		  << numArray[1] << " "
		  << numArray[2] << " is " << centerNum << std::endl;

	return 0;
}
