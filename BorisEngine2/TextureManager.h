#ifndef _TEXTUREMANAGER_H
#define _TEXTUREMANAGER_H

// Windows & SDL 
#include <stdlib.h>
/*#include <Windows.h>*/
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

#ifdef __linux__
  #include <SDL2/SDL.h>

  // Image Texture loading library
  #include <SDL2/SDL_image.h>

  // Font loading library
  #include <SDL2/SDL_ttf.h>
#else
  #include <SDL.h>
  #include <SDL_image.h>
  #include <SDL_ttf.h>
#endif

// STL Container & Algorithms
#include <vector>
#include <map>
#include <algorithm>

#include "BorisConsoleManager.h"
#include "Texture.h"

//Create a class used to store pointers to instances of "Texture" so that they can be easily accessed when necessary.
class TextureManager
{
	public:
		//A method which returns a pointer to the only
		//instance of this class.
		static TextureManager* getInstance();
		//A method which adds a texture by loading one from
		//a given file path.
		Texture* AddTexture(String texturename, const char *filename);
		//A method which adds a given texture.
		Texture* AddTexture(String texturename, Texture* texture);
		//A method which returns a pointer to an instance
		//of "Texture" depending on the given name.
		Texture* GetTexture(String textureName);
		Texture* GetTextureOrBlank(String textureName);
		//A method which deletes all stored textures.
		void DeleteTextures();
		//A method which sets the sdl renderer.
		void SetRenderer(SDL_Renderer* renderer);
		//A method which returns the amount of textures
		//that have been stored.
		int Count();
		Texture* BlankTexture();
	private:
		//Constructor, private so that an instance can't be
		//created outside of this class.
		TextureManager();
		//Destructor method.
		~TextureManager();
		//A pointer to the only instance of this class.
		static TextureManager* _instance;
		//A map which uses std::strings (texture names) as keys
		//and pointers to instances of "Texture" as values.
		Dictionary<String, Texture*> textureList;
		//The SDL renderer.
		SDL_Renderer* sdlRenderer;
		static BorisConsoleManager* borisConsoleManager;
};

#endif
