#ifndef _POINTSCOUNTER_H
#define _POINTSCOUNTER_H

#include "DigitSprite.h"

class PointsCounter
{
	public:
		PointsCounter(Font* font);
		PointsCounter(Font* font, int digits);
		~PointsCounter();
		int GetValue();
		void SetValue(int val);
		Vector2 GetPosition();
		void SetPosition(float x, float y);
		void SetPosition(Vector2 vec2);
		std::vector<DigitSprite*> DigitSprites();
	private:
		void UpdateDisplay();
		Vector2 position;
		int digitCount;
		int value = 0;
		std::vector<DigitSprite*> digitSprites;
};

#endif