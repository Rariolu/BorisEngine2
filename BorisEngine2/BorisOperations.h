#ifndef _BorisOperations_H
#define _BorisOperations_H

#include "Vector2.h"
#include "FloatRect.h"
#include <cstring>
#include <iostream>
#include <sstream>
#include <Windows.h>
#include <SDL_mixer.h>
#include <vector>
#include <map>
#include <algorithm>

//A namespace used to contain a bunch of miscellaneous subroutines.
namespace BorisOperations
{
	//A method which returns an LPCSTR value representing a character.
	LPCSTR Char_to_LPCSTR(char c);
	//A method which returns a std::string representing a character.
	String CharToString(char c);
	//A method which creates a given directory if
	//it doesn't already exist.
	bool CreateFolder(String dirname);
	//A method which returns a boolean representing
	//whether or not a given file path exists.
	bool FileExists(const String &filename);
	//Get the distance between two points.
	float GetDistance(Vector2 a, Vector2 b);
	//A method which returns an SDL_Rect which has been augmented by a given amount.
	SDL_Rect GetExpandedRect(SDL_Rect rect, int expansion);
	//Get a FloatRect value from a given SDL_Rect value.
	FloatRect GetFloatRect(SDL_Rect sdlRect);
	//Get an SDL_Rect value from a given FloatRect value.
	SDL_Rect GetSDLRect(FloatRect frect);
	//A method which returns an LPCSTR value representing a given integer.
	LPCSTR Int_to_LPCSTR(int num);
	float Lerp(float a, float b, float f);
	Vector2 Lerp(Vector2 a, Vector2 b, float f);
	FloatRect Lerp(FloatRect a, FloatRect b, float f);
	//A method which returns a std::string representing a given number
	//padded with 0s to show a given amount of digits.
	String PadNumber(int num, int idealsize);
	//A method which returns a random number between the two given values.
	int RandomNumber(int min, int max);
	//A method which rounds a float value and returns the resulting integer.
	int Round(float value);
	//Separates a string using a given value to separate the segments.
	//https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
	StdVec<String> Split(String str, String delimiter);
	//A method which returns an LPCSTR value representing a std::string.
	LPCSTR String_to_LPCSTR(String str);
	//A method which loops until there is no audio playing on
	//any sdl audio channels.
	void WaitForMusicToStop();
}

#endif