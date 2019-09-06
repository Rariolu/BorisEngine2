#include "OpsTest.h"

StrTestMap ops =
{
	{"CharToLPCSTR",CharToLPCSTR},
	{"CharToStr",CharToStr},
	{"CreateFolder",CreateFolder},
	{"FloatRectLerp",FloatRectLerp},
	{"GetDistanceX",GetDistanceX},
	{"GetDistanceXY",GetDistanceXY},
	{"GetDistanceY",GetDistanceY},
	{"GetFloatRect",GetFloatRect},
	{"GetSDLRect",GetSDLRect},
	{"IntToLPCSTR",IntToLPCSTR},
	{"IntToLPCSTRSingleDigit",IntToLPCSTRSingleDigit},
	{"Lerp",Lerp},
	{"PadNumber",PadNumber},
	{"RandomNumber",RandomNumber},
	{"Round",Round},
	{"Split",Split},
	{"StringToLPCSTR",StringToLPCSTR},
	{"Vec2Lerp",Vec2Lerp},
	{"Vec2ToSDLPoint",Vec2ToSDLPoint }
};

double OpsRunAll()
{
	return RunTests(ops);
}

double OpsSize()
{
	return (double)ops.size();
}

bool CharToLPCSTR()
{
	char c = 't';
	LPCSTR lpcstrC = BorisOperations::Char_to_LPCSTR(c);
	LPCSTR test = "t";
	return !lstrcmp(lpcstrC, test);
}

bool CharToStr()
{
	char c = 't';
	String strC = BorisOperations::CharToString(c);
	String test = "t";
	return strC == test;
}

bool CreateFolder()
{
	String folder = "C:\\tests\\Folder";
	int number = 0;
	String folderComplete;
	do
	{
		folderComplete = folder + std::to_string(number++);
	}
	while (BorisOperations::FileExists(folderComplete));

	BorisOperations::CreateFolder(folderComplete);
	return BorisOperations::FileExists(folderComplete);
}

bool FloatRectLerp()
{
	FloatRect a = { 0,0,50,100 };
	FloatRect b = { 5,5,100,200 };
	FloatRect c = { 2.5F,2.5F,75,150 };
	FloatRect result = BorisOperations::Lerp(a, b, 0.5F);
	return result == c;
}

bool GetDistanceX()
{
	float d = 4;
	Vector2 a = { 0,0 };
	Vector2 b = { d,0 };
	return BorisOperations::GetDistance(a, b) == d;
}

bool GetDistanceXY()
{
	float d = 4;
	float hyp = sqrt(2 * pow(d, 2));
	Vector2 a = { 0,0 };
	Vector2 b = { d,d };
	return BorisOperations::GetDistance(a, b) == hyp;
}

bool GetDistanceY()
{
	float d = 4;
	Vector2 a = { 0,0 };
	Vector2 b = { 0,d };
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

bool IntToLPCSTR()
{
	int n = 56;
	LPCSTR lpcstrN = BorisOperations::Int_to_LPCSTR(n);
	LPCSTR test = "56";
	return !lstrcmp(lpcstrN, test);
}

bool IntToLPCSTRSingleDigit()
{
	int n = 5;
	LPCSTR lpcstrN = BorisOperations::Int_to_LPCSTR(n);
	LPCSTR test = "5";
	return !lstrcmp(lpcstrN, test);
}

bool Lerp()
{
	float a = 0;
	float b = 5;
	float c = 2.5F;
	float result = BorisOperations::Lerp(a, b, 0.5F);
	return result == c;
}

bool PadNumber()
{
	int n = 4;
	String strN = "0004";
	String result = BorisOperations::PadNumber(n, 4);
	return strN == result;
}

bool RandomNumber()
{
	int min = 50;
	int max = 2000;
	int iterations = 5;
	StdVec<int> numbers;
	for (int i = 0; i < iterations; i++)
	{
		int number = BorisOperations::RandomNumber(min, max);
		numbers.push_back(number);
	}
	int matches = 0;
	for (int i = 0; i < (int)numbers.size()-1; i++)
	{
		for (int j = i + 1; j < (int)numbers.size(); j++)
		{
			matches += numbers[i] == numbers[j];
		}
	}
	return matches < (iterations * 2);
}

bool Round()
{
	float num1 = 0.4F;
	float num2 = 0.6F;
	float num3 = 0.5F;
	float num4 = 1.0F;
	float rnum1 = (float)BorisOperations::Round(num1);
	float rnum2 = (float)BorisOperations::Round(num2);
	float rnum3 = (float)BorisOperations::Round(num3);
	float rnum4 = (float)BorisOperations::Round(num4);
	return (rnum1 == 0) && (rnum2 == 1) && (rnum3 == 1) && (rnum4 == 1);
}

bool Split()
{
	StdVec<String> test =
	{
		"Hello"
		"world,"
		"this",
		"is",
		"a",
		"test."
	};
	String delimiter = " ";
	String sentence;
	for (int i = 0; i < (int)test.size(); i++)
	{
		sentence += test[i];
		if (i < (int)test.size() - 1)
		{
			sentence += delimiter;
		}
	}
	StdVec<String> segments = BorisOperations::Split(sentence, delimiter);
	return segments == test;
}

bool StringToLPCSTR()
{
	String str = "Hello World.";
	LPCSTR lpcstr = BorisOperations::String_to_LPCSTR(str);
	LPCSTR test = "Hello World.";
	return !lstrcmp(lpcstr, test);
}

bool Vec2Lerp()
{
	Vector2 a = { 0,0 };
	Vector2 b = { 5,5 };
	Vector2 c = {2.5F, 2.5F};
	Vector2 result = BorisOperations::Lerp(a, b, 0.5F);
	return result == c;
}

bool Vec2ToSDLPoint()
{
	Vector2 vec2 = { 1.5F, 1.4F };
	SDL_Point result = BorisOperations::Vector2ToSDLPoint(vec2);
	SDL_Point test = { 2,1 };
	return BorisOperations::SDL_PointEquals(&result, &test);
}