#include "Projectile.h"


namespace prog3 {
	Projectile::Projectile(const SDL_Rect& r, const char* p) :Sprite(r, p)
	{
		setColltype(3);
	}

	void Projectile::tick(std::vector<Component*>* comps) {
		getRect().x -= 5;
		if (getRect().x < -20) {
			destroy();
		}
		checkOverlap(comps);
	}

	void Projectile::collision(Component* other) {
		std::cout << "collision" << std::endl;
		if (getColltype() != other->getColltype()) {
			if ((other->getColltype() == 1)) {
				other->destroy();
				destroy();
			}
		}
	}
	Projectile::~Projectile()
	{
	}
}