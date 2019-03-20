#ifndef _GAME_H
#define _GAME_H

#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include"SceneManager.h"
#include "SDL_Window_Manager.h"

//using namespace std;

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
		void Run(std::string startscene);
		virtual void Run() = 0;
		int CreateGameWindow(std::string windowTitle, int width, int height);
		
	private:
		virtual void ResourceSetup(SDL_Renderer* renderer)=0;
		//A pointer to the sdl window.
		SDL_Window* sdlWindow;
		//A pointer to the sdl renderer.
		SDL_Renderer* sdlRenderer;
		//A bool representing whether or not the "Initialise" method has been called.
		bool initialised = false;
		//A pointer to an instance of "SceneManager".
		static SceneManager* sceneManager;
		static BorisConsoleManager* BorisConsoleManager;
};

#endif