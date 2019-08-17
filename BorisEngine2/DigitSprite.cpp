#include "DigitSprite.h"

DigitSprite::DigitSprite(Font* font) : Sprite(texturemanager->AddTexture("digitSprite_0",font->CreateTextTexture("0",SOLID)))
{
	digitFont = font;
}

DigitSprite::~DigitSprite()
{

}

int DigitSprite::GetDisplayNumber()
{
	return displayNumber;
}

void DigitSprite::SetDisplayNumber(int num)
{
	displayNumber = num;
	if (digitFont)
	{
		String str = "digitSprite_" + std::to_string(num);
		Texture* t = texturemanager->GetTexture(str);
		if (!t)
		{
			t = texturemanager->AddTexture(str,digitFont->CreateTextTexture(std::to_string(num), SOLID));
		}
		SetTexture(t);
	}
}