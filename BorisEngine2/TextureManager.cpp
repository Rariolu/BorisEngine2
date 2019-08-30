#include "TextureManager.h"

TextureManager* TextureManager::_instance = NULL;

BorisConsoleManager* TextureManager::BorisConsoleManager = BorisConsoleManager::Instance();

TextureManager::TextureManager()
{

}

TextureManager::~TextureManager()
{
	DeleteTextures();
}

TextureManager* TextureManager::getInstance()
{
	if (!_instance)
	{
		return _instance = new TextureManager();
	}
	return _instance;
}

Texture* TextureManager::AddTexture(String textureName, LPCSTR filename)//(LPCSTR textureName, LPCSTR filename)
{
	Texture* texture = new Texture(filename, theSDLRenderer);
	return AddTexture(textureName, texture);
}

Texture* TextureManager::AddTexture(String textureName, Texture* texture)//(LPCSTR textureName, Texture* texture)
{
	Texture* t = GetTexture(textureName);
	if (!t)
	{
		textureList.insert(make_pair(textureName, texture));
		String str = "The current texture count is " + std::to_string(Count());//String(BorisOperations::Int_to_LPCSTR(Count()));
		BorisConsoleManager->Print(str);
		return texture;
	}
	String str = "Unable to add" + textureName + "because a texture of that name has already been added.";
	BorisConsoleManager->Print(str);
	return texture;
}

Texture* TextureManager::GetTexture(String textureName)
{
	Dictionary<String, Texture*>::iterator txt = textureList.find(textureName);
	if (txt != textureList.end())
	{
		return txt->second;
	}
	return NULL;
}

void TextureManager::DeleteTextures()
{
	for (Dictionary<String, Texture*>::iterator txt = textureList.begin(); txt != textureList.end(); txt++)
	{
		if (txt->second)
		{
			delete txt->second;
			txt->second = NULL;
		}
	}
	textureList.clear();
}

void TextureManager::SetRenderer(SDL_Renderer* renderer)
{
	theSDLRenderer = renderer;
}

int TextureManager::Count()
{
	return (int)textureList.size();
}

Texture* TextureManager::BlankTexture()
{
	return Texture::NANTexture(theSDLRenderer);
}