#ifndef SPRITE_H
#define SPRITE_H
#include "Component.h"
#include <SDL_image.h>
#include <string>
#include <iostream>

namespace prog3 {

	class Sprite :
		public Component
	{
	public:
		static Sprite* getInstance(const SDL_Rect& r, const char* p) { return new Sprite(r, p); }
		void draw();
		void tick(std::vector<Component*>* comps);
		void setSpritesheet() { spritesheet = true; }
		void setSpriteWH(int w, int h) { spritew = w; spriteh = h; }
		void setSpriteCount(int c) { scount = c; }
		void setSpriteDelay(int d) { sdelay = d; }
		void checkOverlap(std::vector<Component*>* comps);
		void collision(Component* other);
		~Sprite();
	protected:
		Sprite(const SDL_Rect& r, const char* p);
	private:
		bool spritesheet = false;
		int spritec, spriter, delay,sdelay,spritew,spriteh,scount = 0;
		SDL_Texture* tsprite;
		SDL_Surface* ssprite;
		Sprite(const Sprite&) = delete;
		const Sprite& operator=(const Sprite&) = delete;
	};

}

#endif