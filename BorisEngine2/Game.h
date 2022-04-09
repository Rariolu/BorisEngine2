#ifndef _GAME_H
#define _GAME_H

#ifdef __linux__
  #include <SDL2/SDL.h>
  #include <SDL2/SDL_image.h>
#else
  #include <SDL.h>
  #include <SDL_image.h>
#endif

#include <iostream>
#include "SceneManager.h"
#include "SDL_Window_Manager.h"
#include "favicon.c"

class Game
{
	public:
		//Constructor method.
		Game();
		//Destructor method.
		~Game();
		int CreateGameWindow(String windowTitle, int width, int height);
		int CreateGameWindow(String windowTitle, int width, int height, Icon icon);
		int CreateGameWindow(SDL_Window_Manager* sdlWindowManager);
		int CreateNewWindow(String windowTitle, int width, int height, Icon icon);
		//Dispose of sdl assets.
		void Dispose();
		//A method which initialises the game class giving it pointers to the current sdl window and renderer.
		void Initialise(SDL_Window* theSDLWND, SDL_Renderer* theRenderer);
		//Run the gameplay, starting with the scene representing the given scene name.
		void Run(String startscene);
		virtual void Run() = 0;
	protected:
		static FontManager* fontManager;
		//A pointer to an instance of "SceneManager".
		static SceneManager* sceneManager;
		static SDL_Window_Manager* sdlWindowManager;
		static TextureManager* textureManager;
	private:
		virtual void ResourceSetup(SDL_Renderer* renderer)=0;
		static BorisConsoleManager* borisConsoleManager;
		//A bool representing whether or not the "Initialise" method has been called.
		bool initialised = false;
		//A pointer to the sdl renderer.
		SDL_Renderer* sdlRenderer;
		//A pointer to the sdl window.
		SDL_Window* sdlWindow;
};

#endif
