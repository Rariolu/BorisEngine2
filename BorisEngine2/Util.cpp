#include "Util.h"

Util* Util::_instance = NULL;

BorisConsoleManager* Util::borisConsoleManager = BorisConsoleManager::Instance();

Util::Util()
{
	currentMusic = "";
}

Util::~Util()
{

}

Util* Util::GetInstance()
{
	if (_instance == NULL)
	{
		_instance = new Util();
	}
	return _instance;
}

void Util::Reset()
{
	_instance = new Util();
	_instance->SetMusicVolume(musicvolume);
	_instance->SetSFXVolume(sfxvolume);
}

void Util::IncreasePoints(int amount)
{
	points += amount;
}

int Util::GetPoints()
{
	return points;
}

int Util::GetSFXVolume()
{
	return sfxvolume;
}

void Util::SetSFXVolume(int volume)
{
	sfxvolume = volume;
	borisConsoleManager->Print("SFX volume has been set to " + std::to_string(volume) + ".");
}

int Util::GetMusicVolume()
{
	return musicvolume;
}

void Util::SetMusicVolume(int volume)
{
	musicvolume = volume;
	Mix_VolumeMusic(volume);
	borisConsoleManager->Print("Music volume has been set to " + std::to_string(volume));
}

String Util::GetCurrentMusic()
{
	return currentMusic;
}

void Util::SetCurrentMusic(String currentmusic)
{
	currentMusic = currentmusic;
}

void Util::IncreaseHealth(double amount)
{
	health += amount;
	health = health > max_health ? max_health :
	(
		health < 0 ? 0 : health
	);
	borisConsoleManager->Print("Current health is: " + std::to_string(health) + ".");
}

double Util::GetHealth()
{
	return health;
}

void Util::SetMaxHealth(double max)
{
	max_health = max;
}

double Util::GetMaxHealth()
{
	return max_health;
}
