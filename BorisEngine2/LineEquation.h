#ifndef _LINEEQUATION_H
#define _LINEEQUATION_H

#include "Vector2.h"

struct LineEquation
{
	public:
		LineEquation(float yInt, float grad, float c)
		{
			yIntercept = yInt;
			gradient = grad;
			offset = c;
		}
		LineEquation(Vector2 startPos, Vector2 dir)
		{

		}
		float yIntercept;
		float gradient;
		float offset;
};

#endif