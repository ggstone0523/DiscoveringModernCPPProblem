#include "Answer.h"

inline double volumeOfTetrahedron(double cubeOfSide)
{
	double volume = 0.0;

	volume = sqrt(2.0) / 12.0 * cubeOfSide;
	return volume;
}

inline double surfaceAreaOfTetrahedron(double squareOfSide)
{
	double surfaceArea = 0.0;

	surfaceArea = sqrt(3.0) * squareOfSide;
	return surfaceArea;
}

inline double volumeOfCube(double cubeOfSide)
{
	double volume = 0.0;
	
	volume = cubeOfSide;
	return volume;
}

inline double surfaceAreaOfCube(double squareOfSide)
{
	double surfaceArea = 0.0;

	surfaceArea = 6.0 * squareOfSide;
	return surfaceArea;
}

inline double volumeOfOctahedron(double cubeOfSide)
{
	double volume = 0.0;
	
	volume = sqrt(2.0) / 3.0 * cubeOfSide;
	return volume;
}

inline double surfaceAreaOfOctahedron(double squareOfSide)
{
	double surfaceArea = 0.0;

	surfaceArea = 2.0 * sqrt(3.0) * squareOfSide;
	return surfaceArea;
}

inline double volumeOfDodecahedron(double cubeOfSide)
{
	double volume = 0.0;
	
	volume = (15.0 + 7.0 * sqrt(5.0)) / 4.0 * cubeOfSide;
	return volume;
}

inline double surfaceAreaOfDodecahedron(double squareOfSide)
{
	double surfaceArea = 0.0;
	const double pi = 3.141592;

	surfaceArea = 15.0 * squareOfSide * tan(3.0 * pi / 10.0);
	return surfaceArea;
}

inline double volumeOfIcosahedron(double cubeOfSide)
{
	double volume = 0.0;
	
	volume = (3 + sqrt(5.0)) / 12.0 * 5.0 * cubeOfSide;
	return volume;
}

inline double surfaceAreaOfIcosahedron(double squareOfSide)
{
	double surfaceArea = 0.0;

	surfaceArea = 5.0 * sqrt(3.0) * squareOfSide;
	return surfaceArea;
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

	std::cout << "if length of side is " << side << "," << std::endl;
	std::cout << "\n";

	std::cout << "volume of Tetrahedron is " 
		  << volumeOfTetrahedron(cubeOfSide) << std::endl;
	std::cout << "surfaceArea of Tetrahedron is " 
		  << surfaceAreaOfTetrahedron(squareOfSide) << std::endl;
	std::cout << "\n";
	
	std::cout << "volume of cube is "
		  << volumeOfCube(cubeOfSide) << std::endl;
	std::cout << "surfaceArea of cube is "
		  << surfaceAreaOfCube(squareOfSide) << std::endl;
	std::cout << "\n";
	
	std::cout << "volume of Octahedron is "
		  << volumeOfOctahedron(cubeOfSide) << std::endl;
	std::cout << "surfaceArea of Octahedron is "
		  << surfaceAreaOfOctahedron(squareOfSide) << std::endl;
	std::cout << "\n";
	
	std::cout << "volume of Dodecahedron is "
		  << volumeOfDodecahedron(cubeOfSide) << std::endl;
	std::cout << "surfaceArea of Dodecahedron is "
		  << surfaceAreaOfDodecahedron(squareOfSide) << std::endl;
	std::cout << "\n";
	
	std::cout << "volume of Icosahedron is "
		  << volumeOfIcosahedron(cubeOfSide) << std::endl;
	std::cout << "surfaceArea of Icosahedron is "
		  << surfaceAreaOfIcosahedron(squareOfSide) << std::endl;
	std::cout << "\n";

	return 0;
}
