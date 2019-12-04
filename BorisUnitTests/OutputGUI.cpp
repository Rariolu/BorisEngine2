#include "OutputGUI.h"

BorisConsoleManager* OutputGUI::borisConsoleManager = BorisConsoleManager::Instance();

OutputGUI::OutputGUI() : Scene("background")
{
	
}

OutputGUI::~OutputGUI()
{

}

void OutputGUI::Initialise(SDL_Renderer* renderer)
{
	Scene::Initialise(renderer);
	
}

bool OutputGUI::KeyDown(SDL_Keycode key)
{
	switch (key)
	{
		case SDLK_m:
		{
			char* c = "Bliop";
			Texture* t = textureManager->GetTexture(c);
			if (!t)
			{
				//t = fontmanager->GetFont()
			}
			break;
		}
	}
	return true;
}

void OutputGUI::Update(float deltaTime)
{

}