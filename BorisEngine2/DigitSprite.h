#ifndef _DIGITSPRITE_H
#define _DIGITSPRITE_H

#include "Sprite.h"
#include "Font.h"

class DigitSprite : public Sprite
{
	public:
		DigitSprite(Font* font);
		~DigitSprite();
		//Get the number that is currently being displayed.
		int GetDisplayNumber();
		//Set the number that is currently being displayed.
		void SetDisplayNumber(int num);
	private:
		//The number that is currently being displayed.
		int displayNumber = 0;
		Font* digitFont;
};

#endif