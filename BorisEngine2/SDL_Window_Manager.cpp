#include "SDL_Window_Manager.h"

BorisConsoleManager* SDL_Window_Manager::BorisConsoleManager = BorisConsoleManager::Instance();

SDL_Window_Manager* SDL_Window_Manager::pInstance = NULL;


/*
=================================================================================
Constructor
=================================================================================
*/
SDL_Window_Manager::SDL_Window_Manager()
{

}
/*
=================================================================================
Singleton Design Pattern
=================================================================================
*/
SDL_Window_Manager* SDL_Window_Manager::getInstance()
{
	if (pInstance == NULL)
	{
		pInstance = new SDL_Window_Manager();
	}
	return SDL_Window_Manager::pInstance;
}

/*
=================================================================================
* Initialise the SDL Context with desired Window Title std::string, width and height
* @param strWNDTitle The Window Title std::string
* @param iWidth The width of the window to draw
* @param iHeight The height of the window to draw
=================================================================================
*/
bool SDL_Window_Manager::initWND(String strWNDTitle, int iWidth, int iHeight)
{
	return initWND(strWNDTitle, iWidth, iHeight, favicon);
	//// Initialize SDL's Video subsystem
	//if (SDL_Init(SDL_INIT_VIDEO) < 0)
	//{
	//	BorisConsoleManager->Print("Failed to load SDL");
	//	//cout << "Failed to init SDL\n";
	//	return false;
	//}
	//mainWindow = SDL_CreateWindow(strWNDTitle.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
	//	iWidth, iHeight, SDL_WINDOW_OPENGL);
	//// Check that everything worked out okay
	//if (!mainWindow)
	//{
	//	BorisConsoleManager->Print("Unable to create window.");
	//	//cout << "Unable to create window\n";
	//	CheckSDLError(__LINE__);
	//	return false;
	//}
	//// Get the renderer
	//theRenderer = SDL_CreateRenderer(mainWindow, -1, 0);
	//if (theRenderer)
	//{
	//	std::cout << "Renderer creation succeeded" << std::endl;
	//	SDL_SetRenderDrawColor(theRenderer, 0, 0, 100, 255);
	//	SetSDLIcon();
	//	return true;
	//}
	//std::cout << "Renderer creation failed" << std::endl;
	//return false;
}

bool SDL_Window_Manager::initWND(String windowTitle, int width, int height, Icon icon)
{
	// Initialize SDL's Video subsystem
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		BorisConsoleManager->Print("Failed to load SDL");
		//cout << "Failed to init SDL\n";
		return false;
	}
	mainWindow = SDL_CreateWindow(windowTitle.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		width, height, SDL_WINDOW_OPENGL);

	// Check that everything worked out okay
	if (!mainWindow)
	{
		BorisConsoleManager->Print("Unable to create window.");
		//cout << "Unable to create window\n";
		CheckSDLError(__LINE__);
		return false;
	}
	// Get the renderer
	theRenderer = SDL_CreateRenderer(mainWindow, -1, 0);
	if (theRenderer)
	{
		std::cout << "Renderer creation succeeded" << std::endl;

		SDL_SetRenderDrawColor(theRenderer, 0, 0, 100, 255);
		SetSDLIcon(icon);
		return true;
	}
	std::cout << "Renderer creation failed" << std::endl;
	return false;
}

//https://caedesnotes.wordpress.com/2015/04/13/how-to-integrate-your-sdl2-window-icon-or-any-image-into-your-executable/
void SDL_Window_Manager::SetSDLIcon()
{
	SetSDLIcon(favicon);
}

void SDL_Window_Manager::SetSDLIcon(Icon iconStruct)
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
	amask = (iconStruct.bytes_per_pixel == 3) ? 0 : 0xff000000;
#endif
	SDL_Surface* icon = SDL_CreateRGBSurfaceFrom((void*)iconStruct.pixel_data, iconStruct.width,
		iconStruct.height, iconStruct.bytes_per_pixel * 8, iconStruct.bytes_per_pixel*iconStruct.width,
		rmask, gmask, bmask, amask);

	SDL_SetWindowIcon(getSDLWindow(), icon);

	SDL_FreeSurface(icon);
}

void SDL_Window_Manager::CheckSDLError(int line = -1)
{
	String error = SDL_GetError();

	if (error != "")
	{
		BorisConsoleManager->Print("SLD Error : " + error);
		//std::stringstream ss;
		//ss << "SLD Error : " << error;
		//BorisConsoleManager->Print(&ss);
		//cout << "SLD Error : " << error << std::endl;

		if (line != -1)
		{
			BorisConsoleManager->Print("Line : " + std::to_string(line));
			//cout << "\nLine : " << line << std::endl;
		}
		SDL_ClearError();
	}
}


SDL_Window* SDL_Window_Manager::getSDLWindow()
{
	return mainWindow;
}

SDL_Renderer* SDL_Window_Manager::getSDLRenderer()
{
	return theRenderer;
}