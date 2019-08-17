#ifndef _ANIMATION_H
#define _ANIMATION_H

#include "Texture.h"

struct Animation
{
	std::vector<Texture*> frames;
	float frameDuration;
	int currentFrame;
	float delta;
	void Reset()
	{
		currentFrame = 0;
		delta = 0;
	}
};

#endif