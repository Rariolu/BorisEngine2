#ifndef _FONT_H
#define _FONT_H

#ifdef __linux__
  #include <SDL2/SDL.h>
  #include <SDL2/SDL_ttf.h>
#else
  #include <SDL.h>
  #include <SDL_ttf.h>
#endif

/*#include<Windows.h>*/
#include <iostream>
#include "Texture.h"
#include "BorisConsoleManager.h"

//Create an enumeration for the different possible ways of displaying text.
enum TextType { SOLID, BLENDED, SHADED };

//Create a class representing a specific font.
class Font
{
	public:
		//Constructor, takes file path of font to be loaded, size of the font, and a pointer to the sdl renderer.
		Font(const char *filename,int fontSize,SDL_Renderer* _renderer);
		//Constructor, takes the same parameters as the previous one but also takes sdl colours representing the foreground and background colours.
		Font(const char *filename, int fontSize, SDL_Renderer* _renderer, SDL_Color text_colour, SDL_Color background_colour);
		//Destructor method.
		~Font();
		//A method which creates a texture resembling given text and displays it differently depending on the given "TextType".
		Texture* CreateTextTexture(const char *text, TextType text_type);
		//A method which creates a texture resembling given text and displays it differently depending on the given "TextType".
		Texture* CreateTextTexture(String text, TextType text_type);
		//Returns a pointer to the "TTF_Font" value which represents the font information in the context of the sdl library.
		TTF_Font* GetFont();

	private:
		//A value used for the background colour of the text.
		SDL_Color backgroundColour;
		static BorisConsoleManager* borisConsoleManager;
		//A pointer to the sdl renderer used in the current window.
		SDL_Renderer* renderer;
		//A value used for the foreground colour of the text.
		SDL_Color textColour;
		//A pointer to the "TTF_Font" value which represents the font information in the context of the sdl library.
		TTF_Font* ttfFont;
};

#endif
