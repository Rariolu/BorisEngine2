#ifndef _ANIMATION_H
#define _ANIMATION_H

#include "Texture.h"

struct Animation
{
	//The textures that are used in order.
	StdVec<Texture*> frames;
	//The amount of time that each frame lasts.
	float frameDuration;
	//The index of the frame currently being used.
	int currentFrame;
	//The amount of time that has accumulated since the last change of frame.
	float delta;
	//Boolean representing whether or not the animation should be repeated after it has been played.
	bool loop = false;
	//Starts animation again.
	void Reset()
	{
		currentFrame = 0;
		delta = 0;
	}
};

#endif