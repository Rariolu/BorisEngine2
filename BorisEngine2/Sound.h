#ifndef  _SOUND_H
#define _SOUND_H

#include <stdlib.h>
/*#include <Windows.h>*/
#include <iostream>
#include <cstdlib>
#include <SDL.h>
#include<SDL.h>
#include<SDL_mixer.h>
#include <string>
#include <iostream>
#include <fstream>
#include"Util.h"

#include "SoundWrap.h"
#include "BorisConsoleManager.h"

//An enumeration which represents the 2 different types of audio.
//enum SoundType { SFX, MUSIC };

class Sound
{
	public:
		//Constructor, takes the file path of an audio file and the type of the audio.
		Sound(const char *filename, SoundType sound_type);
		//Destructor method.
		~Sound();
		//A method which returns the SoundType of this instance.
		SoundType GetSoundType();
		//A method which plays the audio using the default
		//volume of its given time.
		void Play();
		//A method which plays the audio using the given volume.
		void Play(int volume);

		Mix_Chunk* GetSound();

		Mix_Music* GetMusic();
	private:
		//A value representing the sound type of this instance.
		SoundType soundType;
		//A value which represents a pointer to the sound effect in its SDL context.
		Mix_Chunk* sound = NULL;
		//A value which represents a pointer to the music in its SDL context.
		Mix_Music* music = NULL;

		static int play(void* data);
		static BorisConsoleManager* borisConsoleManager;
};

#endif // ! _SOUND_H
