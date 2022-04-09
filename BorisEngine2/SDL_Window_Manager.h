#ifndef  _SDLWINDOWMANAGER_H
#define _SDLWINDOWMANAGER_H

#ifdef __linux__
  #include <SDL2/SDL.h>
  #include <SDL2/SDL_image.h>
#else
  #include <SDL.h>
  #include <SDL_image.h>
#endif

#include "favicon.c"
#include "BorisConsoleManager.h"
#include "BorisOperations.h"
#include "Aliases.h"

//A class which is used to manage the SDL window resources and renderer.
class SDL_Window_Manager
{
	public:
		//A method which returns a pointer to the only instance of this class.
		static SDL_Window_Manager* getInstance();
		//A method which checks for an error from within the SDL
		//library and outputs it to the console if there is one.
		void CheckSDLError(int line);
		void Dispose();
		//A method which attempts to initialise and open a window
		//and returns a boolean that depends on whether or not it
		//was successful.
		bool initWND(String strWNDTitle, int iWidth, int iHeight);
		bool initWND(String windowTitle, int width, int height, Icon icon);
		//A method which returns a pointer to the SDL renderer.
		SDL_Renderer* getSDLRenderer();
		//A method which returns a pointer to the SDL window.
		SDL_Window* getSDLWindow();
		//https://caedesnotes.wordpress.com/2015/04/13/how-to-integrate-your-sdl2-window-icon-or-any-image-into-your-executable/
		void SetSDLIcon(Icon icon);
	private:
		//Constructor, private so that an instance can only be created
		//from within this class.
		SDL_Window_Manager();
		//A method which sets the taskbar icon and thumbnail of the window.
		void SetSDLIcon();
		//A pointer to the only instance of this class.
		static SDL_Window_Manager* instance;
		//A pointer to the SDL window.
		SDL_Window *mainWindow;
		//A pointer to the SDL renderer.
		SDL_Renderer* sdlRenderer;
		static BorisConsoleManager* borisConsoleManager;

};

#endif // ! _SDLWINDOWMANAGER_H
