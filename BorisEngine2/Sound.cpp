#include "Sound.h"

BorisConsoleManager* Sound::BorisConsoleManager = BorisConsoleManager::Instance();

Sound::Sound(LPCSTR filename, SoundType sound_type)
{
	soundType = sound_type;
	switch (soundType)
	{
		case SFX:
		{
			sound = Mix_LoadWAV(filename);
			if (sound == 0)
			{
				std::string str = "Sound FX '" + std::string(filename) + "' could not be loaded. " + std::string(SDL_GetError());
				BorisConsoleManager->Print(str);
				//std::stringstream ss;
				//ss << "Sound FX '" << filename << "' could not be loaded. " << SDL_GetError();
				//BorisConsoleManager->Print(&ss);
				//cout << "Sound FX '" << filename << "' could not be loaded. " << SDL_GetError() << endl;
			}
			else
			{
				Mix_VolumeChunk(sound, Util::GetInstance()->GetSFXVolume());
				std::string str = "Sound FX '" + std::string(filename) + "' was successfully loaded. ";
				BorisConsoleManager->Print(str);
				//std::stringstream ss;
				//ss << "Sound FX '" << filename << "' was successfully loaded. ";
				//BorisConsoleManager->Print(&ss);
				//cout << "Sound FX '" << filename << "' was successfully loaded. " << endl;
			}
		}
		break;
		case MUSIC:
		{
			music = Mix_LoadMUS(filename);
			BorisConsoleManager->Print(std::string(Mix_GetError()));
			//std::stringstream ss;
			//ss << Mix_GetError();
			//BorisConsoleManager->Print(&ss);
			//cout << Mix_GetError() << endl;
			if (music == 0)
			{
				String str = "Music '" + String(filename) + "' could not be loaded. " + String(SDL_GetError());
				BorisConsoleManager->Print(str);
				//std::stringstream ss;
				//ss << "Music '" << filename << "' could not be loaded. " << SDL_GetError();
				//BorisConsoleManager->Print(&ss);
				//cout << "Music '" << filename << "' could not be loaded. " << SDL_GetError() << endl;
			}
			else
			{
				String str = "Music '" + String(filename) + "' was successfully loaded. ";
				BorisConsoleManager->Print(str);
				//std::stringstream ss;
				//ss << "Music '" << filename << "' was successfully loaded. ";
				//BorisConsoleManager->Print(&ss);
				//cout << "Music '" << filename << "' was successfully loaded. " << endl;
			}
		}
		break;
	default:
		break;
	}
}

Sound::~Sound()
{

}

SoundType Sound::GetSoundType()
{
	return soundType;
}

void Sound::Play()
{
	switch (soundType)
	{
	case SFX:
	{
		Play(Util::GetInstance()->GetSFXVolume());
	}
	break;
	case MUSIC:
	{
		Play(Util::GetInstance()->GetMusicVolume());
	}
	break;
	}
}

void Sound::Play(int volume)
{
	SoundWrap* wrap = NULL;
	switch (soundType)
	{
	case SFX:
		wrap = new SoundWrap(sound, volume);
		break;
	case MUSIC:
		wrap = new SoundWrap(music, volume);
		break;
	}
	if (wrap)
	{
		void* voir = (void*)wrap;
		ThreadManager::GetInstance()->RunThread(&play, voir);
	}
}

int Sound::play(void* data)
{
	try
	{
		SoundWrap* soundwrap = (SoundWrap*)data;
		int volume = soundwrap->GetVolume();
		switch (soundwrap->GetSoundType())
		{
		case SFX:
		{
			if (soundwrap->GetSound())
			{
				Mix_VolumeChunk(soundwrap->GetSound(), volume);
				Mix_PlayChannel(-1, soundwrap->GetSound(), 0);
			}
		}
		break;
		case MUSIC:
		{
			if (soundwrap->GetMusic())
			{
				Mix_VolumeMusic(volume);
				Mix_PlayMusic(soundwrap->GetMusic(), -1);
			}
		}
		break;
		}
		return 0;
	}
	catch (std::exception err)
	{
		return -1;
	}
}

Mix_Chunk* Sound::GetSound()
{
	return sound;
}

Mix_Music* Sound::GetMusic()
{
	return music;
}

