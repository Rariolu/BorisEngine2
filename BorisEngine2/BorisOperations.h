#ifndef _BorisOperations_H
#define _BorisOperations_H

#include "Circle.h"
#include "FloatRect.h"
#include <cstring>
#include <sstream>
/*#include <Windows.h>*/
#include <SDL.h>
#include <SDL_mixer.h>
#include <algorithm>

//A namespace used to contain a bunch of miscellaneous subroutines.
namespace BorisOperations
{
	//Return "true" if b is true and "false" if b is false.
	String BoolToString(bool b);
	//A method which returns an const char * value representing a character.
	const char * Char_to_Str(char c);
	//A method which returns a std::string representing a character.
	String CharToString(char c);
	//A method which creates a given directory if
	//it doesn't already exist.
	bool CreateFolder(String dirname);
	SDL_Surface* CreateSurface(unsigned int bytesPerPixel, void *pixels, int width, int height, int depth, int pitch);
	//A method which returns a boolean representing
	//whether or not a given file path exists.
	//https://stackoverflow.com/questions/4316442/stdofstream-check-if-file-exists-before-writing
	bool FileExists(const String &filename);
	//Get the distance between two points.
	float GetDistance(Vector2 a, Vector2 b);
	//A method which returns an SDL_Rect which has been augmented by a given amount.
	SDL_Rect GetExpandedRect(SDL_Rect rect, int expansion);
	//Get a FloatRect value from a given SDL_Rect value.
	FloatRect GetFloatRect(SDL_Rect sdlRect);
	//Get an SDL_Rect value from a given FloatRect value.
	SDL_Rect GetSDLRect(FloatRect frect);
	//A method which returns an const char * value representing a given integer.
	const char * Int_to_Str(int num);
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
	//Returns true if both points have the same memory address
	//or if their X and Y values are identical.
	bool SDL_PointEquals(SDL_Point* a, SDL_Point* b);
	//Separates a string using a given value to separate the segments.
	//https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
	StdVec<String> Split(String str, String delimiter);
	//A method which returns an const char * value representing a std::string.
	const char * String_to_Str(String str);
	//Converts a Vector2 into SDL_Point
	//by rounding the X and Y values.
	SDL_Point Vector2ToSDLPoint(Vector2 vec2);
	//A method which loops until there is no audio playing on
	//any sdl audio channels.
	void WaitForMusicToStop();

	bool LineIntersectsCircle(Vector2 lineStartPosition, Vector2 lineDirection, Circle circle);
}

#endif
