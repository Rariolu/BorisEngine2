#ifndef _POINTSCOUNTER_H
#define _POINTSCOUNTER_H

#include "DigitSprite.h"

class PointsCounter
{
	public:
		PointsCounter(Font* font);
		PointsCounter(Font* font, int digits);
		~PointsCounter();
		StdVec<DigitSprite*> DigitSprites();
		Vector2 GetPosition();
		int GetValue();
		void SetPosition(float x, float y);
		void SetPosition(Vector2 vec2);
		void SetValue(int val);
	private:
		void UpdateDisplay();
		Vector2 position;
		int digitCount;
		int value = 0;
		StdVec<DigitSprite*> digitSprites;
};

#endif