#ifndef _UTIL_H
#define _UTIL_H

#include <SDL.h>
#include <SDL_mixer.h>
#include <string>
#include <iostream>
/*#include <Windows.h>*/
#include "BorisConsoleManager.h"

//A class used to contain gameplay information and settings.
class Util
{
	public:
		//A method which returns a pointer to
		//the only instance of this class.
		static Util* GetInstance();
		//A method which resets the current instance in order to replay the game.
		void Reset();
		//A method which increases the points count by the given amount.
		void IncreasePoints(int amount);
		//A method which returns the amount of points.
		int GetPoints();
		//A method which returns the current sound effects volume.
		int GetSFXVolume();
		//A method which sets the current sound effects volume.
		void SetSFXVolume(int volume);
		//A method which returns the current music volume.
		int GetMusicVolume();
		//A method which sets the current music volume.
		void SetMusicVolume(int volume);
		//A method which returns the name of the currently-playing song.
		String GetCurrentMusic();
		//A method which sets the current song.
		void SetCurrentMusic(String currentmusic);
		//A method which increases the player's health by the given amount
		//(to a maximum of 200).
		void IncreaseHealth(double amount);
		//A method which returns the player's health.
		double GetHealth();
		void SetMaxHealth(double max);
		double GetMaxHealth();
	private:
		//Constructor, private so that an instance can't be made outside the class.
		Util();
		//Destructor method.
		~Util();
		//A pointer to the only instance of this class.
		static Util* _instance;
		//An integer which represents the amount of points.
		int points = 0;
		//An integer which represents the player's health.
		double health = 200;
		//An integer which represents the maximum possible health.
		double max_health = 200;
		//An integer which represents the sound effects volume.
		int sfxvolume = 75;
		//An integer which represents the music volume.
		int musicvolume = 75;
		//A std::string which represents the currently-playing song.
		String currentMusic;
		static BorisConsoleManager* borisConsoleManager;
};

#endif
