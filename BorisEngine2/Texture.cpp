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
		BorisConsoleManager->Print(String(SDL_GetError()));
	}
	return false;
}

Texture* Texture::NANTexture(SDL_Renderer* renderer)
{
	return new Texture(BlankSDLTexture(renderer), renderer,true);
}

SDL_Texture* Texture::BlankSDLTexture(SDL_Renderer* renderer)
{
		// these masks are needed to tell SDL_CreateRGBSurface(From)
		// to assume the data it gets is byte-wise RGB(A) data
		Uint32 rmask, gmask, bmask, amask;
	#if SDL_BYTEORDER == SDL_BIG_ENDIAN
		int shift = (my_icon.bytes_per_pixel == 3) ? 8 : 0;
		rmask = 0xff000000 >> shift;
		gmask = 0x00ff0000 >> shift;
		bmask = 0x0000ff00 >> shift;
		amask = 0x000000ff >> shift;
	#else // little endian, like x86
		rmask = 0x000000ff;
		gmask = 0x0000ff00;
		bmask = 0x00ff0000;
		amask = (NonApplicableTexture.bytes_per_pixel == 3) ? 0 : 0xff000000;
	#endif
		SDL_Surface* nansurface = SDL_CreateRGBSurfaceFrom((void*)NonApplicableTexture.pixel_data, NonApplicableTexture.width,
			NonApplicableTexture.height, NonApplicableTexture.bytes_per_pixel * 8, NonApplicableTexture.bytes_per_pixel*NonApplicableTexture.width,
			rmask, gmask, bmask, amask);

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