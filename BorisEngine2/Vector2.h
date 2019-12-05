#ifndef _VECTOR2_H
#define _VECTOR2_H

#include "Aliases.h"
#include "SDL.h"
#include "string"

//A struct which represents an onscreen position using an X and Y value.
struct Vector2
{
	Vector2()
	{

	}
	Vector2(float x, float y)
	{
		X = x;
		Y = y;
	}
	float  X;
	float  Y;
	String ToString() const
	{
		return "{" + std::to_string(X) + "," + std::to_string(Y) + "}";
	}
	SDL_Point ToSDLPoint() const
	{
		return{ (int)X,(int)Y };
	}
	Vector2 operator*(float number)
	{
		return{ X * number, Y * number };
	}
	Vector2 operator/(float number)
	{
		return (*this)*(1.0F / number);
	}
	void operator*=(float number)
	{
		X *= number;
		Y *= number;
	}
	Vector2 operator+(Vector2 other)
	{
		return{ X + other.X, Y + other.Y };
	}
	void operator+=(Vector2 other)
	{
		X += other.X;
		Y += other.Y;
	}
	Vector2 operator-()
	{
		return{ -X,-Y };
	}
	Vector2 operator-(Vector2 other)
	{
		return{ X - other.X, Y - other.Y };
	}
	bool operator==(Vector2 other)
	{
		return X == other.X && Y == other.Y;
	}
	bool operator!=(Vector2 other)
	{
		return !(*this == other);
	}
	Vector2 Normalise()
	{
		float h = sqrt(pow(X, 2) + pow(Y, 2));
		return Vector2(X / h, Y / h);
	}
};

#endif