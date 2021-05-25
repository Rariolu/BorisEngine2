#include "SoundManager.h"

SoundManager* SoundManager::_instance = NULL;

BorisConsoleManager* SoundManager::borisConsoleManager = BorisConsoleManager::Instance();

SoundManager::SoundManager()
{
	Initialise();
}

bool SoundManager::Initialise()
{
	if (SDL_Init(SDL_INIT_AUDIO) != 0)
	{
		String str = "SDL_Init_AUDIO Failed: " + String(SDL_GetError());
		borisConsoleManager->Print(str);
		return false;
	}
	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 4096) != 0)
	{
		String str = "Mix_OpenAudio Failed: " + String(SDL_GetError());
		borisConsoleManager->Print(str);
		return false;
	}
	return true;
}

SoundManager::~SoundManager()
{
	DeleteSounds();
	Mix_CloseAudio();
	Mix_Quit();
}

SoundManager* SoundManager::GetInstance()
{
	if (_instance == NULL)
	{
		_instance = new SoundManager();
	}
	return _instance;
}

Sound* SoundManager::GetSound(String soundname)//(LPCSTR soundname)
{
	Dictionary<String, Sound*>::iterator sound = sounds.find(soundname);
	if (sound != sounds.end())
	{
		return sound->second;
	}
	return NULL;
}

void SoundManager::AddSound(String soundname, const char *filename, SoundType soundtype)
{
	if (!GetSound(soundname))
	{
		Sound* newsound = new Sound(filename,soundtype);
		sounds.insert(make_pair(soundname, newsound));
	}
}

void SoundManager::DeleteSounds()
{
	for (Dictionary<String, Sound*>::iterator sound = sounds.begin(); sound != sounds.end(); ++sound)//(map<LPCSTR, Sound*>::iterator sound = sounds.begin(); sound != sounds.end(); ++sound)
	{
		delete sound->second;
	}
}
