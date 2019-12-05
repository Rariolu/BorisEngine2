#ifndef _CIRCLE_H
#define _CIRCLE_H

#include "Vector2.h"

struct Circle
{
	public:
		Circle(Vector2 _centre, float _radius)
		{
			centre = _centre;
			radius = _radius;
		}
		Vector2 centre;
		float radius;
};

#endif