#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "Sprite.h"

namespace prog3 {
	class Projectile :
		public Sprite
	{
	public:
		static Projectile* getInstance(const SDL_Rect& r, const char* p) { return new Projectile(r, p); }
		~Projectile();
		void tick(std::vector<Component*>* comps);
		void collision(Component* other);
	protected:
		Projectile(const SDL_Rect& r, const char* p);
	private:
		Projectile(const Projectile&) = delete;
		const Projectile& operator=(const Projectile&) = delete;
	};
}
#endif