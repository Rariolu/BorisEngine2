#ifndef _FLOATRECT_H
#define _FLOATRECT_H

//A struct representing a rectangle using float values for X,Y, Width, and Height.
struct FloatRect
{
	float X;
	float Y;
	float W;
	float H;
	bool operator==(const FloatRect& other) const
	{
		return X == other.X && Y == other.Y && W == other.W && H == other.H;
	}
	bool operator!=(const FloatRect& other) const
	{
		return !(*this == other);
	}
};

#endif