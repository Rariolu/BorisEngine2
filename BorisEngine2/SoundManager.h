#ifndef _SOUNDMANAGER_H
#define _SOUNDMANAGER_H

#include<SDL_mixer.h>
#include<iostream>
#include<map>
#include<vector>
#include"Sound.h"

//Create a class used to store pointers to instances of "Sound" so that they can be easily accessed when necessary.
class SoundManager
{
	public:
		//Destructor method.
		~SoundManager();
		//A method which returns a pointer to the only instance of this class.
		static SoundManager* GetInstance();
		//Add a sound using a given file path and sound type.
		void AddSound(String soundName, LPCSTR fileName, SoundType soundtype);
		//Return a pointer to an instance of "Sound" using a given name.
		Sound* GetSound(String soundName);
		//A method that deletes all the stored sounds.
		void DeleteSounds();
		
	private:
		//Constructor, private so that an instance can't be created outside of this class.
		SoundManager();
		//A pointer to the only instance of this class.
		static SoundManager* _instance;
		//A map that uses std::strings (sound names) as keys and pointers
		//to instances of "Sound" as values.
		Dictionary<String, Sound*> sounds;
		//A method which attempts to initialise the instance and returns a boolean
		//representing whether or not it was successful.
		bool Initialise();
		static BorisConsoleManager* BorisConsoleManager;
};

#endif