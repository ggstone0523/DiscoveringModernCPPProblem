#include <iostream>
#include <string>
#include <fstream>
#include "../PolygonFormulaFolder/PolygonFormula.h"

inline void writeData(
		std::string polygon, double side, double squareOfSide,
		double cubeOfSide, double volume, double surfaceArea,
		std::ostream& os
		);
void checkOutputFileError(std::ofstream& outputFile);
