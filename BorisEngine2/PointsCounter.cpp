#include "PointsCounter.h"

PointsCounter::PointsCounter(Font* font) : PointsCounter(font, 4)
{

}

PointsCounter::PointsCounter(Font* font, int digits)
{
	digits = digits >= 1 ? digits : 4;
	digitCount = digits;
	for (int i = 0; i < digits; i++)
	{
		DigitSprite* ds = new DigitSprite(font);
		digitSprites.push_back(ds);
	}
}

PointsCounter::~PointsCounter()
{
	for (int i = 0; i < digitCount; i++)
	{
		if (digitSprites[i])
		{
			delete digitSprites[i];
			digitSprites[i] = NULL;
		}
	}
	digitSprites.clear();
}

StdVec<DigitSprite*> PointsCounter::DigitSprites()
{
	return digitSprites;
}

Vector2 PointsCounter::GetPosition()
{
	return position;
}

int PointsCounter::GetValue()
{
	return value;
}

void PointsCounter::SetPosition(float x, float y)
{
	SetPosition({ x,y });
}

void PointsCounter::SetPosition(Vector2 vec2)
{
	position = vec2;
	int width = digitSprites[0]->GetDimensions().w;
	for (int i = 0; i < digitCount; i++)
	{
		digitSprites[i]->SetPosition(position.X + (i*width), position.Y);
	}
}

void PointsCounter::SetValue(int val)
{
	value = val >= 0 && val <= pow(10,digitCount)-1 ? val : value;
	UpdateDisplay();
}


void PointsCounter::UpdateDisplay()
{
	String str = BorisOperations::PadNumber(value, digitCount);
	for (int i = 0; i < digitCount; i++)
	{
		digitSprites[i]->SetDisplayNumber(str[i]-'0');
	}
}