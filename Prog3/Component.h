#ifndef COMPONENT_H
#define COMPONENT_H
#include <SDL.h>
#include <vector>
#include <SDL_image.h>
namespace prog3 {

	class Component
	{
	public:
		virtual void draw() = 0;
		virtual ~Component();
		virtual SDL_Rect& getRect() { return rect; }
		virtual int getColltype() { return colltype; }
		virtual void setColltype(int i) { colltype = i; }
		virtual void destroy() { bdestroy = true; }
		virtual void mouseDown(const SDL_Event&) {}
		virtual void mouseUp(const SDL_Event&) {}
		virtual void keyDown(const SDL_Event&) {}
		virtual void keyUp(const SDL_Event&) {}
		virtual void act(){}
		virtual bool isDestroy() { return bdestroy; }
		virtual bool getShoot() { return shoot; }
		virtual void setShoot(bool b) { shoot = b; }
		virtual void collision(Component* other){}
		virtual void tick(std::vector<Component*>* comps){}
	protected:
		Component(const SDL_Rect& r);
	private:
		SDL_Rect rect;
		bool bdestroy = false;
		bool shoot = false;
		int colltype = 0;
		Component(const Component&) = delete;
		const Component& operator=(const Component&) = delete;		
	};
}
#endif