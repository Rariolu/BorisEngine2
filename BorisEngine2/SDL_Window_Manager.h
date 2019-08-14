
#ifndef  _SDLWINDOWMANAGER_H
#define _SDLWINDOWMANAGER_H


#include <SDL.h>
#include <string>
#include <iostream>
//#include "Textures\favicon.c"
#include "favicon.c"
#include "BorisConsoleManager.h"
#include "BorisOperations.h"
#include "Aliases.h"
//using namespace std;

//A class which is used to manage the SDL window resources and renderer.
class SDL_Window_Manager
{
	public:
		//A method which attempts to initialise and open a window
		//and returns a boolean that depends on whether or not it
		//was successful.
		bool initWND(String strWNDTitle, int iWidth, int iHeight);
		bool initWND(String windowTitle, int width, int height, Icon icon);
		//A method which checks for an error from within the SDL
		//library and outputs it to the console if there is one.
		void CheckSDLError(int line);
		//A method which returns a pointer to the SDL window.
		SDL_Window* getSDLWindow();
		//A method which returns a pointer to the SDL renderer.
		SDL_Renderer* getSDLRenderer();
		//A method which returns a pointer to the only instance of this class.
		static SDL_Window_Manager* getInstance();

		void SetSDLIcon(Icon icon);
	private:
		//Constructor, private so that an instance can only be created
		//from within this class.
		SDL_Window_Manager();
		//A method which sets the taskbar icon and thumbnail of the window.
		void SetSDLIcon();

		
		//A pointer to the only instance of this class.
		static SDL_Window_Manager* pInstance;
		//A pointer to the SDL window.
		SDL_Window *mainWindow;
		//A pointer to the SDL renderer.
		SDL_Renderer* theRenderer;
		static BorisConsoleManager* BorisConsoleManager;

};

#endif // ! _SDLWINDOWMANAGER_H