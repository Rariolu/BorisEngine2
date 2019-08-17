#ifndef _GAME_H
#define _GAME_H

#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include"SceneManager.h"
#include "SDL_Window_Manager.h"
#include "favicon.c"

class Game
{
	public:
		//Constructor method.
		Game();
		//Destructor method.
		~Game();
		//A method which initialises the game class giving it pointers to the current sdl window and renderer.
		void Initialise(SDL_Window* theSDLWND, SDL_Renderer* theRenderer);
		//Dispose of sdl assets.
		void Dispose();
		//Run the gameplay, starting with the scene representing the given scene name.
		void Run(String startscene);
		virtual void Run() = 0;
		int CreateGameWindow(String windowTitle, int width, int height);
		int CreateGameWindow(String windowTitle, int width, int height, Icon icon);
		int CreateGameWindow(SDL_Window_Manager* sdlWindowManager);
	protected:
		static FontManager* fontManager;
		static SceneManager* sceneManager;
		static TextureManager* textureManager;
	private:
		virtual void ResourceSetup(SDL_Renderer* renderer)=0;
		//A pointer to the sdl window.
		SDL_Window* sdlWindow;
		//A pointer to the sdl renderer.
		SDL_Renderer* sdlRenderer;
		//A bool representing whether or not the "Initialise" method has been called.
		bool initialised = false;
		//A pointer to an instance of "SceneManager".

		static BorisConsoleManager* BorisConsoleManager;
};

#endif