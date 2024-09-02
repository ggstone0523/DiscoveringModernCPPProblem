#include "PolygonFormula.h"

double volumeOfTetrahedron(double cubeOfSide)
{
	double volume = 0.0;

	volume = sqrt(2.0) / 12.0 * cubeOfSide;
	return volume;
}

double surfaceAreaOfTetrahedron(double squareOfSide)
{
	double surfaceArea = 0.0;

	surfaceArea = sqrt(3.0) * squareOfSide;
	return surfaceArea;
}

double volumeOfCube(double cubeOfSide)
{
	double volume = 0.0;
	
	volume = cubeOfSide;
	return volume;
}

double surfaceAreaOfCube(double squareOfSide)
{
	double surfaceArea = 0.0;

	surfaceArea = 6.0 * squareOfSide;
	return surfaceArea;
}

double volumeOfOctahedron(double cubeOfSide)
{
	double volume = 0.0;
	
	volume = sqrt(2.0) / 3.0 * cubeOfSide;
	return volume;
}

double surfaceAreaOfOctahedron(double squareOfSide)
{
	double surfaceArea = 0.0;

	surfaceArea = 2.0 * sqrt(3.0) * squareOfSide;
	return surfaceArea;
}

double volumeOfDodecahedron(double cubeOfSide)
{
	double volume = 0.0;
	
	volume = (15.0 + 7.0 * sqrt(5.0)) / 4.0 * cubeOfSide;
	return volume;
}

double surfaceAreaOfDodecahedron(double squareOfSide)
{
	double surfaceArea = 0.0;
	const double pi = 3.141592;

	surfaceArea = 15.0 * squareOfSide * tan(3.0 * pi / 10.0);
	return surfaceArea;
}

double volumeOfIcosahedron(double cubeOfSide)
{
	double volume = 0.0;
	
	volume = (3 + sqrt(5.0)) / 12.0 * 5.0 * cubeOfSide;
	return volume;
}

double surfaceAreaOfIcosahedron(double squareOfSide)
{
	double surfaceArea = 0.0;

	surfaceArea = 5.0 * sqrt(3.0) * squareOfSide;
	return surfaceArea;
}
