#include "Texture.h"

BorisConsoleManager* Texture::BorisConsoleManager = BorisConsoleManager::Instance();

Texture::Texture(LPCSTR filename, SDL_Renderer* renderer) : Texture(IMG_LoadTexture(renderer,filename),renderer)
{

}

Texture::Texture(SDL_Texture* texture, SDL_Renderer* renderer) : Texture(texture,renderer,false)
{

}

Texture::Texture(SDL_Texture* texture, SDL_Renderer* renderer, bool isTemplate)
{
	mainRenderer = renderer;
	if (!isTemplate)
	{
		LoadTexture(texture);
	}
	else
	{
		sdlTexture = texture;
	}
}

Texture::~Texture()
{
	
}

int Texture::getHeight()
{
	return height;
}

int Texture::getWidth()
{
	return width;
}

SDL_Texture* Texture::getSDLTexture()
{
	return sdlTexture;
}

void Texture::SetSDLRenderer(SDL_Renderer* renderer)
{
	mainRenderer = renderer;
}

bool Texture::LoadTexture(SDL_Texture* texture)
{
	sdlTexture = texture;
	if (sdlTexture)
	{
		SDL_QueryTexture(sdlTexture, NULL, NULL, &width, &height);
		return true;
	}
	if (mainRenderer)
	{
		LoadTexture(BlankSDLTexture(mainRenderer));
		BorisConsoleManager->Print(SDL_GetError());
	}
	return false;
}

Texture* Texture::NANTexture(SDL_Renderer* renderer)
{
	return new Texture(BlankSDLTexture(renderer), renderer,true);
}

SDL_Texture* Texture::BlankSDLTexture(SDL_Renderer* renderer)
{
	SDL_Surface* nansurface = BorisOperations::CreateSurface(NonApplicableTexture.bytes_per_pixel, (void*)NonApplicableTexture.pixel_data, NonApplicableTexture.width, NonApplicableTexture.height, NonApplicableTexture.bytes_per_pixel * 8, NonApplicableTexture.bytes_per_pixel*NonApplicableTexture.width);
	SDL_Texture* nantexture = SDL_CreateTextureFromSurface(renderer, nansurface);
	return nantexture;
}

void Texture::Render(SDL_Rect* sourceRect, SDL_Rect* destRect)
{
	SDL_RenderCopy(mainRenderer, sdlTexture, sourceRect, destRect);
}

void Texture::Render(SDL_Rect* sourceRect, SDL_Rect* destRect, double rotAngle, SDL_Point* spriteCentre)
{
	SDL_RenderCopyEx(mainRenderer, sdlTexture, sourceRect, destRect, rotAngle, spriteCentre, SDL_FLIP_NONE);
}