#include "BorisOperations.h"
#include<iostream>

LPCSTR BorisOperations::Char_to_LPCSTR(char c)
{
	std::ostringstream ss;
	ss << c;
	return _strdup(ss.str().c_str());
}

//http://www.cplusplus.com/forum/beginner/4967/
String BorisOperations::CharToString(char c)
{
	String str;
	StringStream ss;
	ss << c;
	ss >> str;
	return str;
}

void BorisOperations::CreateFolder(String dirname)
{
	if (!FileExists(dirname))
	{
		if (CreateDirectory(String_to_LPCSTR(dirname), NULL))
		{
			std::cout << "\"" << dirname << "\" was just created ^_^" << std::endl;
		}
		else
		{
			std::cout << "Failed to create \"" << dirname << "\" for some reason :/" << std::endl;
		}
	}
	else
	{
		std::cout << "\"" << dirname << "\" already exists" << std::endl;
	}
}

//https://stackoverflow.com/questions/4316442/stdofstream-check-if-file-exists-before-writing
bool BorisOperations::FileExists(const String& filename)
{
	struct stat buf;
	return stat(filename.c_str(), &buf) != -1;
}

SDL_Rect BorisOperations::GetExpandedRect(SDL_Rect rect, int expansion)
{
	return { rect.x - expansion, rect.y - expansion, rect.w + (2 * expansion),rect.h + (4 * expansion) };
}

FloatRect BorisOperations::GetFloatRect(SDL_Rect sdlRect)
{
	return { (float)sdlRect.x,(float)sdlRect.y,(float)sdlRect.w,(float)sdlRect.h };
}

SDL_Rect BorisOperations::GetSDLRect(FloatRect frect)
{
	return {Round(frect.X),Round(frect.Y),Round(frect.W),Round(frect.H)};
}

LPCSTR BorisOperations::Int_to_LPCSTR(int num)
{
	if (num < 10 && num > -1)
	{
		return new char[1]{(char)( num + '0')};
	}
	std::cout << num << " isn't between 0 and 9. Needs to be between or equal to these numbers to be valid." << std::endl;
	return "0";
}

String BorisOperations::PadNumber(int num, int idealSize)
{
	String strnumber = std::to_string(num);

	while (strnumber.size() < (decltype(strnumber.size()))idealSize)
	{
		strnumber = "0" + strnumber;
	}
	return strnumber;
}

int BorisOperations::RandomNumber(int min, int max)
{
	return min + (rand() % (max - min + 1));
}

int BorisOperations::Round(float value)
{
	return (int)ceil(value);
}

LPCSTR BorisOperations::String_to_LPCSTR(String str)
{
	std::ostringstream ss;
	ss << str;
	return _strdup(ss.str().c_str());
}

void BorisOperations::WaitForMusicToStop()
{
	int num = 0;
	Mix_HaltMusic();
	while (Mix_Playing(-1) != 0)
	{
		num++;
		std::cout << "Waiting for music to finish. Messaged " << num << " times." << std::endl;
		if (num > 200)
		{
			break;
		}
	}
}

float BorisOperations::Lerp(float a, float b, float f)
{
	return a + f*(b - a);
}

Vector2 BorisOperations::Lerp(Vector2 a, Vector2 b, float f)
{
	float x = Lerp(a.X, b.X, f);
	float y = Lerp(a.Y, b.Y, f);
	return{ x, y };
}

FloatRect BorisOperations::Lerp(FloatRect a, FloatRect b, float f)
{
	float x = Lerp(a.X, b.X, f);
	float y = Lerp(a.Y, b.Y, f);
	float w = Lerp(a.W, b.W, f);
	float h = Lerp(a.H, b.H, f);
	return{ x,y,w,h };
}

float BorisOperations::GetDistance(Vector2 a, Vector2 b)
{
	float xdist = (a.X - b.X);
	float ydist = (a.Y - b.Y);
	return sqrt(pow(xdist, 2) + pow(ydist, 2));
}