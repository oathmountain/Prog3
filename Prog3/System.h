#ifndef SYSTEM_H
#define SYSTEM_H
#include <SDL.h>
#include <SDL_ttf.h>

namespace prog3 {

	class System
	{
	public:
		System();
		SDL_Renderer* getRen() { return ren; }
		TTF_Font* getFont() { return font; }
		SDL_Window* getWin() { return win; }
		int getH() { return h; }
		int getW() { return w; }
		~System();
	private:
		int w = 600;
		int h = 500;
		SDL_Window* win;
		SDL_Renderer* ren;
		TTF_Font* font;
	};

	extern System sys;
}
#endif