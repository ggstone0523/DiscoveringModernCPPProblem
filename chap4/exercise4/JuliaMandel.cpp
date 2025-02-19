#include "JuliaMandel.h"

inline void sdl_check(bool allclear) { if (!allclear) throw sdl_error(); };

inline void put_pixel(SDL_Surface* screen, int x, int y, uint32_t pixel)
{
	assert(screen->format->BytesPerPixel == 4);
	auto pixel_address= reinterpret_cast<uint32_t*>(screen->pixels) + y * screen->w + x;
	*pixel_address= pixel;
};

void update_screen(SDL_Window* sdlWindow, SDL_Surface* screen, bool is_julia = false, complex<float> k = {0, 0},
		   int xstart = 0, int ystart = 0, int xend = default_xdim, int yend = default_ydim, 
		   int xdim = default_xdim, int ydim = default_ydim, const int max_iter = 30)
{
	SDL_LockSurface(screen);
	for (int y = ystart; y < yend; y++)
		for (int x = xstart; x < xend; x++) {
			mandel_julia_pixel p(screen, x, y, xdim, ydim, max_iter, is_julia, k);
			put_pixel(screen, x, y, p.color());
		}
	SDL_UnlockSurface(screen);
	SDL_UpdateWindowSurface(sdlWindow);
};

SDL_Window* show_screen(const char* str = "Mandel", bool is_julia = false, complex<float> k = {0, 0},
		 	int xdim = default_xdim, int ydim = default_ydim, const int max_iter = 30)
{
	SDL_Window* sdlWindow = SDL_CreateWindow(str,
						 SDL_WINDOWPOS_UNDEFINED,
						 SDL_WINDOWPOS_UNDEFINED,
						 xdim, ydim, 0);
	SDL_Surface* screen = SDL_GetWindowSurface(sdlWindow);
	sdl_check(screen);
	update_screen(sdlWindow, screen, is_julia, k, 0, 0, xdim, ydim, xdim, ydim, max_iter);

	return sdlWindow;
};

int main () 
{
	sdl_check(SDL_Init(SDL_INIT_VIDEO) != -1);
	int xdim = default_xdim, ydim = default_ydim;
	int hxdim = xdim / 2, hydim = ydim / 2;
	int num_threads = thread::hardware_concurrency();
	
	SDL_Window* WindowA = show_screen();
	
	SDL_Window* WindowB = SDL_CreateWindow("Julia",
						 SDL_WINDOWPOS_UNDEFINED,
						 SDL_WINDOWPOS_UNDEFINED,
						 xdim, ydim, 0);
	SDL_Surface* ScreenB = SDL_GetWindowSurface(WindowB);
	sdl_check(ScreenB);

	bool run = true;
	bool is_window_b_alive = true;
	float ci, cj;
	float ratio_xy = static_cast<float>(xdim) / static_cast<float>(ydim);
	while(run) {
		SDL_Event e;
		while(SDL_PollEvent(&e)) {
			if (is_window_b_alive && e.type == SDL_MOUSEMOTION && 
			    SDL_GetWindowID(WindowA) == e.motion.windowID) {
				ci = static_cast<float>(e.motion.x - hxdim) / static_cast<float>(hxdim) * ratio_xy;
				cj = static_cast<float>(hydim - e.motion.y) / static_cast<float>(hydim);
				std::vector<std::thread> threads;
				for(int i = 0; i < num_threads; ++i) {
					threads.emplace_back([&WindowB, &ScreenB,
							      hxdim, hydim, xdim, ydim, ci, cj, i](){
							      update_screen(WindowB, ScreenB, true, {ci, cj},
							      0, ydim / 8 * i, xdim, ydim / 8 * (i + 1), xdim, ydim);
					});
				}
				for(int i = 0; i < num_threads; ++i)
					threads[i].join();
			} else if(e.type == SDL_WINDOWEVENT && e.window.event == SDL_WINDOWEVENT_CLOSE) {
				if(SDL_GetWindowID(WindowA) == e.window.windowID) {
					SDL_DestroyWindow(WindowA);
				} else {
					SDL_DestroyWindow(WindowB);
					is_window_b_alive = false;
				}
			} else if(e.type == SDL_QUIT) {
				run = false;
				break;
			}
		}
	}
	SDL_Quit();

	return 0;
}
