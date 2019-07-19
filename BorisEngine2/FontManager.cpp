#include "FontManager.h"

FontManager* FontManager::_instance = NULL;
BorisConsoleManager* FontManager::BorisConsoleManager = BorisConsoleManager::Instance();

FontManager::FontManager()
{
	if (TTF_Init() != 0)
	{
		String str = "TTF_Init() Failed: " + String(SDL_GetError());
		BorisConsoleManager->Print(str);
		//std::stringstream ss;
		//ss << "TTF_Init() Failed: " << SDL_GetError();
		//BorisConsoleManager->Print(&ss);
		//cout << "TTF_Init() Failed: " << SDL_GetError() << endl;
	}
}

FontManager::~FontManager()
{

}

FontManager* FontManager::GetInstance()
{
	if (_instance == NULL)
	{
		_instance = new FontManager();
	}
	return _instance;
}

void FontManager::AddFont(String fontname, Font* font)
{
	if (!GetFont(fontname))
	{
		fonts.insert(make_pair(fontname, font));
	}
}

Font* FontManager::GetFont(String fontname)
{
	std::map<String, Font*>::iterator font = fonts.find(fontname);
	if (font != fonts.end())
	{
		return font->second;
	}
	return NULL;
}