#ifndef PLAYER_H
#define PLAYER_H

#include "Sprite.h"
#include "Projectile.h"

namespace prog3 {

	class Player :
		public Sprite
	{
	public:
		static Player* getInstance(const SDL_Rect& r, const char* p) { return new Player(r, p); }
		void mouseUp(const SDL_Event& eve){}
		void mouseDown(const SDL_Event& eve){}
		void keyDown(const SDL_Event& eve);
		void keyUp(const SDL_Event& eve);
		void tick(std::vector<Component*>* comps);
		void collision(Component* other);
		void bindRight(SDL_Keycode a) { kright = a; }
		void bindLeft(SDL_Keycode a) { kleft = a; }
		void bindUp(SDL_Keycode a) { kup = a; }
		void bindDown(SDL_Keycode a) { kdown = a; }
		void bindFire(SDL_Keycode a) { kfire = a; }
		void setHealth(int i) { health = i; }
		void setFireDelay(int i) { firedelay = i; }
		void setSpeed(int i) { speed = i; }
		virtual void perform(std::string) {}
		~Player();
	protected:
		Player(const SDL_Rect& r, const char* p);		
	private:
		bool right, left, up, down, fire = false;
		int delay, health,firedelay, speed;
		SDL_Keycode kright, kleft, kup, kdown, kfire;
		Player(const Player&) = delete;
		const Player& operator=(const Player&) = delete;
	};

}

#endif