#include "Util.h"

Util* Util::_instance = NULL;

BorisConsoleManager* Util::BorisConsoleManager = BorisConsoleManager::Instance();

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
	BorisConsoleManager->Print("Current health is: " + std::to_string(_instance->GetHealth()) + ".");
	//cout << "Current health is: " << _instance->GetHealth() << endl;
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
	BorisConsoleManager->Print("SFX volume has been set to " + std::to_string(volume) + ".");
	//cout << "SFX volume has been set to " << volume << "." << endl;
}

int Util::GetMusicVolume()
{
	return musicvolume;
}

void Util::SetMusicVolume(int volume)
{
	musicvolume = volume;
	Mix_VolumeMusic(volume);
	BorisConsoleManager->Print("Music volume has been set to " + std::to_string(volume));
	//cout << "Music volume has been set to " << volume << "." << endl;
}

std::string Util::GetCurrentMusic()
{
	return currentMusic;
}

void Util::SetCurrentMusic(std::string currentmusic)
{
	currentMusic = currentmusic;
}

void Util::IncreaseHealth(int amount)
{
	health += amount;
	if (health > max_health)
	{
		health = max_health;
	}
	if (health < 0)
	{
		health = 0;
	}
	BorisConsoleManager->Print("Current health is: " + std::to_string(health) + ".");
	//cout << "Current health is: " << health << endl;
}

int Util::GetHealth()
{
	return health;
}