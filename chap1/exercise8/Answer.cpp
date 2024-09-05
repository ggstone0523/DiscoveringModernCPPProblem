#include "Answer.h"

double meter2yard(double meter)
{
	return meter / 0.9144;
}

double liter2usgallon(double liter)
{
	return liter / 3.785411784;
}

double metersquare2acre(double metersquare)
{
	return metersquare / 4046.8564224;
}

double metercubic2yardcubed(double metercubic)
{
	return metercubic / 0.764554857984;
}

double gram2pound(double gram)
{
	return gram / 453.59237;
}

double yard2meter(double yard)
{
	return yard * 0.9144;
}

double usgallon2liter(double usgallon)
{
	return usgallon * 3.785411784;
}

double acre2metersquare(double acre)
{
	return acre * 4046.8564224;
}

double yardcubed2metercubic(double yardcubed)
{
	return yardcubed * 0.764554857984;
}

double pound2gram(double pound)
{
	return pound * 453.59237;
}

int main(int argc, char* argv[])
{
	double volume = 0.0;
	double epsilon = 1.0e-4;

	assert(argc == 2);

	volume = std::stod(argv[1]);

	assert(fabs(volume - yard2meter(meter2yard(volume))) < epsilon);
	std::cout << volume << " meter is " << meter2yard(volume) << " yard" << std::endl;
	std::cout << meter2yard(volume)
		  << " yard is "
		  << yard2meter(meter2yard(volume)) << " meter\n" << std::endl;
	
	assert(fabs(volume - usgallon2liter(liter2usgallon(volume))) < epsilon);
	std::cout << volume << " liter is " << liter2usgallon(volume) << " usgallon" << std::endl;
	std::cout << liter2usgallon(volume)
		  << " usgallon is "
		  << usgallon2liter(liter2usgallon(volume)) << " liter\n" << std::endl;
	
	assert(fabs(volume - acre2metersquare(metersquare2acre(volume))) < epsilon);
	std::cout << volume 
		  << " metersquare is " << metersquare2acre(volume) << " acre" << std::endl;
	std::cout << metersquare2acre(volume)
		  << " acre is "
		  << acre2metersquare(metersquare2acre(volume)) << " metersquare\n" << std::endl;
	
	assert(fabs(volume - yardcubed2metercubic(metercubic2yardcubed(volume))) < epsilon);
	std::cout << volume 
		  << " metercubic is " << metercubic2yardcubed(volume) << " yardcubed" << std::endl;
	std::cout << metercubic2yardcubed(volume)
		  << " yardcubed is "
		  << yardcubed2metercubic(metercubic2yardcubed(volume)) 
		  << " metercubic\n" << std::endl;
	
	assert(fabs(volume - pound2gram(gram2pound(volume))) < epsilon);
	std::cout << volume << " gram is " << gram2pound(volume) << " pound" << std::endl;
	std::cout << gram2pound(volume)
		  << " pound is "
		  << pound2gram(gram2pound(volume)) << " gram\n" << std::endl;

	return 0;
}
