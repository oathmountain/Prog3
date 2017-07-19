#include "Player.h"

namespace prog3 {
	Player::Player(const SDL_Rect& r, const char* p):Sprite(r,p)
	{
		setColltype(2);
		kright = SDLK_RIGHT;
		kleft = SDLK_LEFT;
		kup = SDLK_UP;
		kdown = SDLK_DOWN;
		kfire = SDLK_SPACE;
		health = 1;
		firedelay = 60;
		speed = 5;
	}

	void Player::keyDown(const SDL_Event& eve) 
	{
		if (kright == eve.key.keysym.sym) {
			right = true;
		}
		else if (kleft == eve.key.keysym.sym) {
			left = true;
		}
		else if (kup == eve.key.keysym.sym) {
			up = true;
		}
		else if (kdown == eve.key.keysym.sym) {
			down = true;
		}
		else if (kfire == eve.key.keysym.sym) {
			fire = true;
		}
	}
	void Player::keyUp(const SDL_Event& eve)
	{
		if (kright == eve.key.keysym.sym) {
			right = false;
		}
		else if(kleft == eve.key.keysym.sym){
			left = false;
		}
		else if (kup == eve.key.keysym.sym) {
			up = false;
		}
		else if (kdown == eve.key.keysym.sym) {
			down = false;
		}
		else if (kfire == eve.key.keysym.sym) {
			fire = false;
		}
	}

	void Player::tick(std::vector<Component*>* comps) {
		if (delay > 0) {// handle firedelay if required
			delay -= 1;
			setShoot(false);
		}
		if (fire || right || left || up || down) { // if a binded key is pressed, see which was press and act acordingly
			if (fire && delay == 0) {// fire
				delay = firedelay;
				setShoot(true);
			}
			if (right && !left) {//move right
				getRect().x += speed;
			}
			else if (left && !right) {//move left
				getRect().x -= speed;
			}if (up && !down) {//move up
				getRect().y -= speed;
			}
			else if (down && !up) {//move down
				getRect().y += speed;
			}
		}
	}

	void Player::collision(Component* other) {
		std::cout << "collision" << std::endl;
		if (getColltype() != other->getColltype()) {
			if ((other->getColltype() == 1)) {
				other->destroy();
				health -= 1;
				if (health == 0) {
					destroy();
				}
			}
		}
	}
	Player::~Player()
	{
	}

}