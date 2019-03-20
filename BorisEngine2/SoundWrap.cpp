#include "SoundWrap.h"


//SoundWrap::SoundWrap(Sound* sound, int volume)
//{
//	_sound = sound;
//	_volume = volume;
//}

SoundWrap::SoundWrap(Mix_Chunk* sound, int volume)
{
	_sound = sound;
	_volume = volume;
	soundtype = SFX;
}

SoundWrap::SoundWrap(Mix_Music* music, int volume)
{
	_music = music;
	_volume = volume;
	soundtype = MUSIC;
}

SoundWrap::~SoundWrap()
{

}

Mix_Chunk* SoundWrap::GetSound()
{
	return _sound;
}

Mix_Music* SoundWrap::GetMusic()
{
	return _music;
}

SoundType SoundWrap::GetSoundType()
{
	return soundtype;
}

int SoundWrap::GetVolume()
{
	return _volume;
}