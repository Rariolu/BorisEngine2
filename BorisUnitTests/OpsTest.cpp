#include "OpsTest.h"

StrTestMap ops;

double OpsRunAll()
{
	StrTestMap theOps = GetOps();
	if (theOps.size() > 0)
	{
		double count = 0;
		for (StrTestMap::iterator i = theOps.begin(); i != theOps.end(); i++)
		{
			bool r = i->second();
			count += r;
			std::cout << i->first << ": " << BoolVal(r) << ";" << std::endl;
		}
		return count / theOps.size();
	}
	return 1;
}

bool CharToStr()
{
	char c = 't';
	String strC = BorisOperations::CharToString(c);
	String test = "t";
	return strC == test;
}

bool CharToLPCSTR()
{
	char c = 't';
	LPCSTR lpcstrC = BorisOperations::Char_to_LPCSTR(c);
	LPCSTR test = "t";
	return lpcstrC == test;
}

bool GetDistance()
{
	float d = 4;
	Vector2 a = { 0,0 };
	Vector2 b = { d,0 };
	return BorisOperations::GetDistance(a, b) == d;
}

bool GetFloatRect()
{
	SDL_Rect sdlrect = { 1,45,56,3 };
	FloatRect result = BorisOperations::GetFloatRect(sdlrect);
	FloatRect test = { 1,45,56,3 };
	return result == test;
}

bool GetSDLRect()
{
	float x = 1.5F;
	float y = 45.3F;
	float w = 56.7F;
	float h = 3.2F;
	FloatRect floatrect = { x,y,w,h };
	SDL_Rect result = BorisOperations::GetSDLRect(floatrect);
	SDL_Rect test = {BorisOperations::Round(x),BorisOperations::Round(y),BorisOperations::Round(w),BorisOperations::Round(h)};
	return SDL_RectEquals(&result, &test) != 0;
}

bool Lerp()
{

}

String BoolVal(bool b)
{
	return b ? "true" : "false";
}

StrTestMap GetOps()
{
	if (ops.size() < 1)
	{
		return ops =
		{
			{ "CharToStr",CharToStr},
			{"CharToLPCSTR",CharToLPCSTR},
			{"GetDistance",GetDistance},
			{"GetFloatRect",GetFloatRect},
			{"GetSDLRect",GetSDLRect},
			{"Lerp",Lerp}
		};
	}
	return ops;
}