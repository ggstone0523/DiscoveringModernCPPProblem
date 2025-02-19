#include <cstdlib>
#include <cstdint>
#include <cassert>
#include <complex>
#include <SDL2/SDL.h>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;

const int default_xdim = 1200;
const int default_ydim = 800;

struct sdl_error;
class mandel_julia_pixel;

inline void sdl_check(bool allclear);
inline void put_pixel(SDL_Surface* screen, int x, int y, uint32_t pixel);
void update_screen(SDL_Window* sdlWindow, SDL_Surface* screen, bool is_julia, complex<float> k,
		   int xstart, int ystart, int xend, int yend, int xdim, int ydim, const int max_iter);
SDL_Window* show_screen(const char* str, bool is_julia, complex<float> k, int xdim, int ydim, const int max_iter);

struct sdl_error {};

class mandel_julia_pixel
{
	public:
		mandel_julia_pixel(SDL_Surface* screen, int x, int y, int xdim, int ydim, 
				int max_iter, bool is_julia = false, complex<float> k = {0, 0})
			: screen(screen), max_iter(max_iter), iter(0), c(x, y), is_julia(is_julia), k(k)
		{
			if(is_julia) {
				c *= 2.4f * 1.2f / static_cast<float>(ydim);
				c -= complex<float>(1.2 * xdim / ydim * 1.2, 1.2 * 1.2);
			} else {
				c *= 2.4f / static_cast<float>(ydim);
				c -= complex<float>(1.2 * xdim / ydim + 0.5, 1.2);
			}
			iterate();
		}

		int iterations() const { return iter; }
		uint32_t color() const 
		{
			if (iter == max_iter) return SDL_MapRGB(screen->format, 255, 255, 255);
			const int ci= 512 * iter / max_iter;
			return iter < max_iter/2 ? SDL_MapRGB(screen->format, 255-ci, 255, 255)
						 : SDL_MapRGB(screen->format, 0, 510-ci, 510-ci);
		}
	private:
		void iterate()
		{
			complex<float> z = c;
			for (; iter < max_iter && norm(z) <= 4.0f; iter++)
				if(is_julia)
					z = z * z + k;
				else
					z = z * z + c;
		};
		
		SDL_Surface* screen;
		const int max_iter;
		int iter;
		complex<float> c, k;
		bool is_julia;
};
