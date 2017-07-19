#include "Sprite.h"
#include <SDL_image.h>
#include "System.h"
#include <iostream>
#include <string>

namespace prog3 {
	Sprite::Sprite(const SDL_Rect& r, const char* p): Component(r)
	{
		ssprite = IMG_Load(p);
		if (ssprite == nullptr) {
			std::cout << "bild hittas inte" << std::endl;
		}
		Uint32 white = SDL_MapRGB(ssprite->format, 255, 255, 255);
		SDL_SetColorKey(ssprite, SDL_ENABLE, white);
		tsprite = SDL_CreateTextureFromSurface(sys.getRen(), ssprite);
		SDL_FreeSurface(ssprite);

		setColltype(1);

	}
	void Sprite::draw() {
		if (!spritesheet) {
			SDL_RenderCopy(sys.getRen(), tsprite, NULL, &getRect());
		}
		else {

			if (spritec < (scount-1) && delay > sdelay) {
				spritec++;
				delay = 0;
			}
			else if(delay > 20){ 
				spritec = 0; 
				delay = 0; 
			}
			SDL_Rect srcrect = { spritec*spritew,spriter*spriteh,spritew,spriteh };
			SDL_RenderCopy(sys.getRen(), tsprite, &srcrect, &getRect());
			delay++;
		}
	}
	
	void Sprite::tick(std::vector<Component*>* comps) {
		act();
		checkOverlap(comps);
	}
	void Sprite::checkOverlap(std::vector<Component*>* comps) {
		SDL_Rect r = getRect();
		for (Component* c : *comps) {
			if (c != this) {
			SDL_Rect r2 = c->getRect();
				if (((r.x <= r2.x +r2.w) && (r.x >= r2.x)) || (((r.x + r.w) >= r2.x) && ((r.x + r.w) <= (r2.x + r2.w)))) {
					if (((r.y >= r2.y) && (r.y <= (r2.y + r2.h))) || (((r.y + r.h) >= r2.y) && ((r.y + r.h) <= (r2.y + r2.h)))) {
					collision(c);
					}
				}
			}
		}
	}
	void Sprite::collision(Component* other) {
		if (getColltype() != other->getColltype()) {
			if ((other->getColltype() == 2) || (other->getColltype() ==3)) {
				other->destroy();
				destroy();
			}
		}
	}

	Sprite::~Sprite()
	{
		SDL_DestroyTexture(tsprite);
	}

}