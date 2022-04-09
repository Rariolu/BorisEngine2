#ifndef _LINE_H
#define _LINE_H

#include "Renderable.h"

#ifdef __linux__
  #include <SDL2/SDL_rect.h>
  #include <SDL2/SDL_render.h>
#else
  #include <SDL_rect.h>
  #include <SDL_render.h>
#endif

#include "BorisOperations.h"

class Line : public Renderable
{
	public:
		Line(SDL_Renderer* renderer);
		Line(SDL_Renderer* renderer, SDL_Point pointA,SDL_Point pointB);
		Line(SDL_Renderer* renderer, SDL_Point pointA, SDL_Point pointB,Colour colour);
		~Line();
		void Render();
		void SetColour(Colour colour);
		void ResetCoordinates(SDL_Point pointA, SDL_Point pointB);
	private:
		SDL_Point a;
		SDL_Point b;
		Colour lineColour;
		SDL_Renderer* sdlRenderer;
};

#endif
