#ifndef _ANIMATION_H
#define _ANIMATION_H

#include "Texture.h"

//A collection of textures that are set at regular intervals.
struct Animation
{
	//The index of the frame currently being used.
	int currentFrame = 0;
	//The amount of time that has accumulated since the last change of frame.
	float delta = 0;
	//The amount of time that each frame lasts.
	float frameDuration;
	//The textures that are used in order.
	StdVec<Texture*> frames;
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