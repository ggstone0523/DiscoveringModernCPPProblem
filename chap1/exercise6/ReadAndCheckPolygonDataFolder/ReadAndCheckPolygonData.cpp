#include "ReadAndCheckPolygonData.h"

bool isEqual(double first, double second)
{
	return fabs(first - second) < 1e-3;
}

void checkInputFileError(std::ifstream& inputFile)
{
	if(!inputFile.good()) {
		std::cerr << "input from file error!" << std::endl;
		exit(EXIT_FAILURE);
	}
}

int main()
{
	std::string polygonName;
	double side = 0.0;
	double squareOfSide = 0.0;
	double cubeOfSide = 0.0;
	double volume = 0.0;
	double surfaceArea = 0.0;
	int funcHashValue = 0;
	char twoDot = ':';
	std::unordered_map<std::string, int> funcHash;
	std::ifstream dataFile{"../PolygonVolAndSurAreaData.txt"};
	checkInputFileError(dataFile);
	std::function<double(double)> funcArray[] = {
		volumeOfTetrahedron,
		surfaceAreaOfTetrahedron,
		volumeOfCube,
		surfaceAreaOfCube,
		volumeOfOctahedron,
		surfaceAreaOfOctahedron,
		volumeOfDodecahedron,
		surfaceAreaOfDodecahedron,
		volumeOfIcosahedron,
		surfaceAreaOfIcosahedron
	};

	funcHash["Tetrahedron"] = 0;
	funcHash["Cube"] = 1;
	funcHash["Octahedron"]= 2;
	funcHash["Dodecahedron"] = 3;
	funcHash["Icosahedron"]= 4;

	while(true) {
		dataFile >> polygonName >> twoDot
			 >> side  >> squareOfSide
			 >> cubeOfSide >> volume
			 >> surfaceArea;

		if(dataFile.eof())
			break;
		checkInputFileError(dataFile);

		funcHashValue = funcHash[polygonName];
		if(isEqual(volume, funcArray[funcHashValue * 2](cubeOfSide)))
			std::cout << polygonName << "\'s volume:\n"
				  << "calculation result and stored result are same!"
				  << std::endl;
		else
			std::cout << polygonName << "\'s volume:\n"
				  << "calculation result and stored result are different!"
				  << std::endl;
		if(isEqual(surfaceArea, funcArray[funcHashValue * 2 + 1](squareOfSide)))
			std::cout << polygonName << "\'s surfaceArea:\n"
				  << "calculation result and stored result are same!"
				  << std::endl;
		else
			std::cout << polygonName << "\'s surfaceArea:\n"
				  << "calculation result and stored result are different!"
				  << std::endl;
		std::cout << "\n";
	}

	return 0;
}
