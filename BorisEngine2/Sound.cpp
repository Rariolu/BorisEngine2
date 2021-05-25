#include "Sound.h"

BorisConsoleManager* Sound::borisConsoleManager = BorisConsoleManager::Instance();

Sound::Sound(const char *filename, SoundType sound_type)
{
	soundType = sound_type;
	switch (soundType)
	{
		case SFX:
		{
			sound = Mix_LoadWAV(filename);
			if (sound == 0)
			{
				String str = "Sound FX '" + String(filename) + "' could not be loaded. " + String(SDL_GetError());
				borisConsoleManager->Print(str);
			}
			else
			{
				Mix_VolumeChunk(sound, Util::GetInstance()->GetSFXVolume());
				String str = "Sound FX '" + String(filename) + "' was successfully loaded. ";
				borisConsoleManager->Print(str);
			}
			break;
		}
		case MUSIC:
		{
			music = Mix_LoadMUS(filename);
			borisConsoleManager->Print(String(Mix_GetError()));
			if (!music)
			{
				String str = "Music '" + String(filename) + "' could not be loaded. " + String(SDL_GetError());
				borisConsoleManager->Print(str);
			}
			else
			{
				String str = "Music '" + String(filename) + "' was successfully loaded. ";
				borisConsoleManager->Print(str);
			}
			break;
		}
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
	SoundWrap* wrap=NULL;
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

