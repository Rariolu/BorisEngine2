#include "MiscTests.h"

StrTestMap miscTests = 
{
	{"GUIOutput",GUIOutput}
};

double MiscRunAll()
{
	double t = RunTests(miscTests);
	return t;
}

bool GUIOutput()
{
	TextureManager* textureManager = TextureManager::getInstance();
	SDL_Window_Manager* sdlWindowManager = SDL_Window_Manager::getInstance();
	textureManager->AddTexture("background", "Textures\\background.png");
	if (sdlWindowManager->initWND("Blep", 800, 800))
	{

		sdlWindowManager->Dispose();
	}
	return false;
}