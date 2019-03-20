#include "TextureManager.h"

TextureManager* TextureManager::_instance = NULL;

BorisConsoleManager* TextureManager::BorisConsoleManager = BorisConsoleManager::Instance();

TextureManager::TextureManager()
{

}

TextureManager::~TextureManager()
{
	//DeleteTextures();
}

TextureManager* TextureManager::getInstance()
{
	if (_instance == NULL)
	{
		_instance = new TextureManager();
	}
	return _instance;
}

void TextureManager::AddTexture(std::string textureName,Texture* texture)//(LPCSTR textureName, Texture* texture)
{
	if (!GetTexture(textureName))
	{
		textureList.insert(make_pair(textureName, texture));
	}
	else
	{
		std::string str = "Unable to add" + textureName + "because a texture of that name has already been added.";
		BorisConsoleManager->Print(str);
	}
	std::string str = "The current texture count is " + std::string(BorisOperations::Int_to_LPCSTR(Count()));
	BorisConsoleManager->Print(str);
}

void TextureManager::AddTexture(std::string textureName, LPCSTR filename)//(LPCSTR textureName, LPCSTR filename)
{
	Texture* texture = new Texture(filename, theSDLRenderer);
	AddTexture(textureName, texture);
}

Texture* TextureManager::GetTexture(std::string textureName)
{
	std::map<std::string, Texture*>::iterator txt = textureList.find(textureName);
	if (txt != textureList.end())
	{
		return txt->second;
	}
	return NULL;
}

void TextureManager::DeleteTextures()
{
	for (std::map<std::string, Texture*>::iterator txt = textureList.begin(); txt != textureList.end(); txt++)
	{
		delete txt->second;
	}
	textureList.clear();
}

void TextureManager::SetRenderer(SDL_Renderer* renderer)
{
	theSDLRenderer = renderer;
}

int TextureManager::Count()
{
	return textureList.size();
}