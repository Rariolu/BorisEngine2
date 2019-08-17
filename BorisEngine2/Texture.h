#ifndef _TEXTURE_H
#define _TEXTURE_H

// Windows & SDL 
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <SDL.h>
// Image Texture loading library
#include <SDL_image.h>
// Font loading library
#include <SDL_ttf.h>

// STL Container & Algorithms
#include <vector>
#include <map>
#include <algorithm>

//Generic texture
#include "NAN.c"

#include "BorisConsoleManager.h"
//using namespace std;

//A class which represents an image.
class Texture
{
	public:
		//Constructor, loads an image from given file path.
		Texture(LPCSTR theFilename, SDL_Renderer *theRenderer);
		//Constructor, sets the sdl texture to the given value.
		Texture(SDL_Texture* texture, SDL_Renderer* theRenderer);
		//Constructor, sets the sdl texture to the given value, checks if texture is template or not.
		Texture(SDL_Texture* texture, SDL_Renderer* renderer, bool isTemplate);
		//Destructor method.
		~Texture();
		//A method which returns the width of the texture.
		int getWidth();
		//A method which returns the height of the texture.
		int getHeight();
		//A method which returns the sdl texture.
		SDL_Texture* getSDLTexture();
		//A method which renders this texture using a given source rectangle and destination rectangle.
		void Render(SDL_Rect* sourceRect, SDL_Rect* destRect);
		//A method which renders this texture using a given source rectangle, destination rectangle,
		//rotation angle and image centre.
		void Render(SDL_Rect* sourceRect, SDL_Rect* destRect, double rotAngle, SDL_Point* spriteCentre);
		//A method which returns a pointer to an instance of "Texture"
		//which resembles a generic, blank texture.
		static Texture* NANTexture(SDL_Renderer* renderer);
	private:
		//A method which attempts to load a given texture and returns
		//a boolean which depends on whether or not the loading 
		//was successful.
		bool LoadTexture(SDL_Texture* texture);
		//A method which returns a generic, blank SDL texture.
		static SDL_Texture* BlankSDLTexture(SDL_Renderer* renderer);
		//A value representing the texture in its SDL context.
		SDL_Texture* sdlTexture;
		//A value representing the width of the texture.
		int width;
		//A value representing the height of the texture.
		int height;
		//A pointer to the sdl renderer.
		SDL_Renderer* mainRenderer;
		static BorisConsoleManager* BorisConsoleManager;
};

#endif // !_TEXTURE_H