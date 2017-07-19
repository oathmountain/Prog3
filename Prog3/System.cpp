#include "System.h"
#include <iostream>
#include <SDL.h>

using namespace std;

namespace prog3 {

	System::System()
	{
		SDL_Init(SDL_INIT_EVERYTHING);
		win = SDL_CreateWindow("Prog3", 100,100,w,h,0);
		ren = SDL_CreateRenderer(win, -1, 0);
		TTF_Init();
		font = TTF_OpenFont("c:/Windows/Fonts/Arial.ttf", 24);
		cout << "SDL init" << endl;
	}


	System::~System()
	{
		TTF_CloseFont(font);
		TTF_Quit();
		SDL_DestroyRenderer(ren);
		SDL_DestroyWindow(win);
		SDL_Quit();
		cout << "SDL quit" << endl;
	}

	System sys;
}