#ifndef  _SOUNDWRAP_H
#define _SOUNDWRAP_H

#ifdef __linux__
  #include <SDL2/SDL.h>
  #include <SDL2/SDL_mixer.h>
#else
  #include <SDL.h>
  #include <SDL_mixer.h>
#endif

//An enumeration which represents the 2 different types of audio.
enum SoundType { SFX, MUSIC };

class SoundWrap
{
	public:
		SoundWrap(Mix_Chunk* sound, int volume);
		SoundWrap(Mix_Music* music, int volume);
		~SoundWrap();
		int GetVolume();
		SoundType GetSoundType();
		Mix_Chunk* GetSound();
		Mix_Music* GetMusic();
	private:
		Mix_Chunk* _sound;
		Mix_Music* _music;
		int _volume;
		SoundType soundtype;
};

#endif // ! _SOUNDWRAP_H
