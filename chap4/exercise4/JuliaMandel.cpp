//This Code is not have logic for graphic
#include "JuliaMandel.h"

int main()
{
	SDL_Surface* testObj = nullptr;
	julia_mandel_pixel testJuliaPixel1{testObj, -0.6, 0.6, 0, 0, 0, 0, 100};
	julia_mandel_pixel testJuliaPixel2{testObj, 0.353, 0.288, 0, 0, 0, 0, 100};
	julia_mandel_pixel testMandelPixel2{testObj, 0.0, 0.0, 0, 0, 100};

	return 0;
}
