#ifndef _OUTPUTGUI_H
#define _OUTPUTGUI_H

#include "Scene.h"

class OutputGUI : public Scene
{
	public:
		OutputGUI();
		~OutputGUI();
		void Initialise(SDL_Renderer* renderer);
	private:
		bool KeyDown(SDL_Keycode key);
		void Update(float deltaTime);
		static BorisConsoleManager* borisConsoleManager;
};

#endif