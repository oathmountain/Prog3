#include "Frame.h"
#include <SDL.h>
#include "System.h"
#include <iostream>
#include "Projectile.h"
namespace prog3{

	void Frame::add(Component* c) {
		comps.push_back(c);
	}

	void Frame::run() {
		bool goOn = true;
		while (goOn) {
			nextTick = SDL_GetTicks() + tickInterval;
			SDL_Event eve;
			while (SDL_PollEvent(&eve)) {
				switch (eve.type) {
				case SDL_MOUSEBUTTONDOWN:
					for (Component* c : comps)
						c->mouseDown(eve);
					break;
				case SDL_MOUSEBUTTONUP:
					for (Component* c : comps)
						c->mouseUp(eve);
					break;
				case SDL_KEYDOWN:
					for (Component* c : comps)
						c->keyDown(eve);
					break;
				case SDL_KEYUP:
					for (Component* c : comps)
						c->keyUp(eve);
					break;
				case SDL_QUIT:
					goOn = false;
					break;
				}//switch
			}//inner while

			 //sets backgroundcolor
			SDL_SetRenderDrawColor(sys.getRen(), 255, 255, 255, 0);
			SDL_RenderClear(sys.getRen());

			for (unsigned i = 0; i < comps.size();i++) {
				if (comps[i]->isDestroy()) {
					if (comps[i]->getColltype() == 2) {
						goOn = false;
					}
					Component* c = comps[i];
					comps.erase(comps.begin()+i);
					delete c;
				}
			}
			//tick all components

			//draw all components
			for (Component* c : comps){
				c->draw();
			}
			Projectile* p1 = nullptr;
			for (Component* c : comps) {
				c->tick(&comps);
				if (c->getShoot() == true) {
					p1 = Projectile::getInstance({ c->getRect().x,c->getRect().y + 20,30,30 }, "Images/spyro.bmp");
					temp.push_back(p1);
					}
				}
			for(Component* c : temp){
				add(c);
			}
			temp.clear();
			SDL_RenderPresent(sys.getRen());

			//delays the loop to get a max FPS
			delay = nextTick - SDL_GetTicks();
			if (delay > 0) {
				SDL_Delay(delay);
			}
		}//outerWhile
	}//run

	void Frame::setFPS(int fps) {
		FPS = fps;
	}
	Frame::~Frame()
	{
		for (Component* c : comps) {
			delete c;
		}
	}

}