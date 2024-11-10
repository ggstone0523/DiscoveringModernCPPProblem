//WIP
#include <cstdint>
#include <complex>

// This Class is temporary Class
class SDL_Surface
{};

class julia_pixel
{
	public:
		julia_pixel(SDL_Surface* screen, double r, double i, double x, double y,
				int xdim, int ydim, int max_iter)
			:screen{screen}, max_iter{max_iter}, iter{0}, k{r, i}, c{x, y}
		{
			c *= 2.4f / static_cast<double>(ydim);
			c -= std::complex<double>(1.2 * xdim / ydim + 0.5, 1.2);
			iterate();
		}

		int iterations() const { return iter; }

		uint32_t color() const { return 0; }
	private:
		void iterate()
		{
			std::complex<double> z = c;
			for(; iter < max_iter && std::norm(z) <= 4.0f; iter++)
				z = z * z + k;
		};

		SDL_Surface* screen;
		int max_iter;
		int iter;
		std::complex<double> c;
		std::complex<double> k;
};

int main()
{
	SDL_Surface* testObj = nullptr;
	julia_pixel testPixel{testObj, -0.6, 0.6, 0, 0, 0, 0, 100};

	return 0;
}
