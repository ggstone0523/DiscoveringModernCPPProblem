//This Code is not have logic for graphic
#include <cstdint>
#include <complex>

class SDL_Surface
{};

class julia_mandel_pixel
{
	public:
		julia_mandel_pixel(SDL_Surface* screen, double r, double i, double x, double y,
				int xdim, int ydim, int max_iter)
			:screen{screen}, max_iter{max_iter}, iter{0}, k{r, i}, c{x, y}, isThisJulia{true}
		{
			c *= 2.4f / static_cast<double>(ydim);
			c -= std::complex<double>(1.2 * xdim / ydim + 0.5, 1.2);
			iterate();
		}
		
		julia_mandel_pixel(SDL_Surface* screen, double x, double y,
				int xdim, int ydim, int max_iter)
			:screen{screen}, max_iter{max_iter}, iter{0}, k{0.0, 0.0}, c{x, y}, isThisJulia{false}
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
				if(isThisJulia)
					z = z * z + k;
				else
					z = z * z + c;
		};

		SDL_Surface* screen;
		int max_iter;
		int iter;
		std::complex<double> c;
		std::complex<double> k;
		bool isThisJulia;
};
