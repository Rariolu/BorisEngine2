#include "Game.h"

FontManager* Game::fontManager = FontManager::GetInstance();
SceneManager* Game::sceneManager = SceneManager::GetInstance();
TextureManager* Game::textureManager = TextureManager::getInstance();
SDL_Window_Manager* Game::sdlWindowManager = SDL_Window_Manager::getInstance();

BorisConsoleManager* Game::BorisConsoleManager = BorisConsoleManager::Instance();

Game::Game()
{

}

Game::~Game()
{

}

int Game::CreateGameWindow(String windowTitle, int width, int height)
{
	return CreateGameWindow(windowTitle, width, height, favicon);
}

int Game::CreateGameWindow(String windowTitle, int width, int height, Icon icon)
{
	//Attempt to initialise an SDL window.
	if (!sdlWindowManager->initWND(windowTitle, width, height, icon))
	{
		//End the program if the window cannot be initialised.
		return -1;
	}
	return CreateGameWindow(sdlWindowManager);
}

int Game::CreateGameWindow(SDL_Window_Manager* sdlWindowManager)
{
	SDL_Renderer* renderer = sdlWindowManager->getSDLRenderer();
	textureManager->SetRenderer(renderer);
	ResourceSetup(renderer);
	Initialise(sdlWindowManager->getSDLWindow(), renderer);
	Run();
	Dispose();
	return 0;
}

int Game::CreateNewWindow(String windowTitle, int width, int height, Icon icon)
{
	if (initialised)
	{
		// Delete our OpengL context
		SDL_GL_DeleteContext(sdlWindow);
		// Destroy the window
		SDL_DestroyWindow(sdlWindow);
		if (!sdlWindowManager->initWND(windowTitle, width, height, icon))
		{
			return -1;
		}
		SDL_Renderer* renderer = sdlWindowManager->getSDLRenderer();
		textureManager->SetRenderer(renderer);
	}
	return CreateGameWindow(windowTitle, width, height, icon);
}

void Game::Dispose()
{
	// Delete our OpengL context
	SDL_GL_DeleteContext(sdlWindow);

	// Destroy the window
	SDL_DestroyWindow(sdlWindow);

	// Quit IMG system
	IMG_Quit();

	// Shutdown SDL 2
	SDL_Quit();

	ThreadManager::GetInstance()->Dispose();
}

void Game::Initialise(SDL_Window* theSDLWND, SDL_Renderer* theRenderer)
{
	initialised = true;
	sdlWindow = theSDLWND;
	sdlRenderer = theRenderer;
}

void Game::Run(String startscene)
{
	if (initialised)
	{
		String currentscene = startscene;
		while (sceneManager->GetScene(currentscene))
		{
			Scene* scene = sceneManager->GetScene(currentscene);
			scene->Initialise(sdlRenderer);
			BorisConsoleManager->Print(currentscene + " initialised and will run shortly.");
			currentscene = scene->Run();
		}
		BorisConsoleManager->Print("Game has ran out of scenes to run and hence will end.");
	}
}