#include "WritePolygonData.h"

void checkOutputFileError(std::ofstream& outputFile)
{
	if(!outputFile.good()) {
		std::cerr << "output to file error!" << std::endl;
		exit(EXIT_FAILURE);
	}
}

inline void writeData(
		std::string polygon, double side, double squareOfSide,
		double cubeOfSide, double volume, double surfaceArea,
		std::ofstream& os
		)
{
	os << polygon << " : " << side << " " 
	   << squareOfSide << " " << cubeOfSide << " "
	   << volume << " " << surfaceArea << std::endl;
	checkOutputFileError(os);
}

int main(int argc, char* argv[]) 
{
	if(argc != 2) {
		std::cerr << "Usage: ./volAndSurAreaOfpolyhedron lengthOfSide\n";
		exit(EXIT_FAILURE);
	}

	double side = std::stod(argv[1]);
	double squareOfSide = pow(side, 2);
	double cubeOfSide = pow(side, 3);
	std::ofstream dataFile {"PolygonVolAndSurAreaData.txt"};
	checkOutputFileError(dataFile);

	writeData("Tetrahedron", side, squareOfSide, cubeOfSide, 
			volumeOfTetrahedron(cubeOfSide), 
			surfaceAreaOfTetrahedron(squareOfSide), dataFile);
	
	writeData("Cube", side, squareOfSide, cubeOfSide, 
			volumeOfCube(cubeOfSide), 
			surfaceAreaOfCube(squareOfSide), dataFile);
	
	writeData("Octahedron", side, squareOfSide, cubeOfSide, 
			volumeOfOctahedron(cubeOfSide), 
			surfaceAreaOfOctahedron(squareOfSide), dataFile);
	
	writeData("Dodecahedron", side, squareOfSide, cubeOfSide, 
			volumeOfDodecahedron(cubeOfSide), 
			surfaceAreaOfDodecahedron(squareOfSide), dataFile);
	
	writeData("Icosahedron", side, squareOfSide, cubeOfSide, 
			volumeOfIcosahedron(cubeOfSide), 
			surfaceAreaOfIcosahedron(squareOfSide), dataFile);

	return 0;
}
