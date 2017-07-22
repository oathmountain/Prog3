#include "System.h"
#include <SDL.h>
#include <iostream>
#include "Frame.h"
#include "Sprite.h"
#include "Player.h"

using namespace prog3;
using namespace std;

class enemy : public Sprite {
public:
	enemy(const SDL_Rect& r, const char* p, int i) : Sprite(r, p) { pattern = i; }
	int move = 3;
	int pattern;
	void act() {	
		switch (pattern) {
		case 1:
			if (getRect().x > (sys.getW()-100)) {
				move = -3;
			}
			else if (getRect().x < 10) {
				move = 3;
			}
			getRect().x += move;
			break;
		case 2:
			if (getRect().y > (sys.getH() - 100)) {
				move = -3;
			}
			else if (getRect().y < 10) {
				move = 3;
			}
			getRect().y += move;
			break;
		}
	}
};
int main(int argc, char** argv) {

	cout << "Main" << endl;
	Frame frame;
	Player* p1 = Player::getInstance({ 400,80,100,100 }, "Images/spritesheet.bmp");
	p1->setSpritesheet();
	p1->setSpriteWH(38, 50);
	p1->setSpriteCount(3);
	p1->setSpriteDelay(20);
	Player* p2 = Player::getInstance({ 400,400,100,100 }, "Images/spyro.bmp");

	p2->bindUp(SDLK_w);
	p2->bindDown(SDLK_s);
	p2->bindLeft(SDLK_a);
	p2->bindRight(SDLK_d);
	p2->bindFire(SDLK_f);
	enemy* e1 = new enemy({ 100,200,100,100 }, "Images/spyro.bmp", 1);
	enemy* e2 = new enemy({ 100,400,100,100 }, "Images/spyro.bmp", 2);

	frame.add(p1);
	frame.add(p2);
	frame.add(e1);
	frame.add(e2);
	frame.run();

	return 0;
}