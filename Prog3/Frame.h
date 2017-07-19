#ifndef FRAME_H
#define FRAME_H
#include <vector>
#include "Component.h"

namespace prog3 {

	class Frame
	{
	public:
		void add(Component* c);
		void run();
		void setFPS(int fps);
		~Frame();
	private:
		std::vector<Component*> comps, temp;
		int FPS = 60;
		int delay;
		const int tickInterval = 1000 / FPS;
		Uint32 nextTick;
	};

}
#endif