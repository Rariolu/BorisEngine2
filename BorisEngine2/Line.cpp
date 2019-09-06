#include "Line.h"

Line::Line(SDL_Renderer* renderer) : Line(renderer,{0,0},{0,0})
{

}

Line::Line(SDL_Renderer* renderer, SDL_Point pointA, SDL_Point pointB) : Line(renderer,pointA,pointB,{0,0,0,255})
{
	
}

Line::Line(SDL_Renderer* renderer, SDL_Point pointA, SDL_Point pointB, Colour colour) : sdlRenderer(renderer), a(pointA), b(pointB), lineColour(colour)
{

}

Line::~Line()
{

}

void Line::Render()
{
	SDL_SetRenderDrawColor(sdlRenderer, lineColour.R, lineColour.G, lineColour.B, lineColour.A);
	SDL_RenderDrawLine(sdlRenderer, a.x, a.y, b.x, b.y);
}

void Line::SetColour(Colour colour)
{
	if (colour != lineColour)
	{
		lineColour = colour;
		SetRenderNow();
	}
}

void Line::ResetCoordinates(SDL_Point pointA, SDL_Point pointB)
{
	if ((!BorisOperations::SDL_PointEquals(&a,&pointA)) || (!BorisOperations::SDL_PointEquals(&b,&pointB)))
	{
		a = pointA;
		b = pointB;
		SetRenderNow();
	}
}