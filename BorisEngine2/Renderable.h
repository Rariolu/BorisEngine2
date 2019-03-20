#ifndef _RENDERABLE_H
#define _RENDERABLE_H

#include "BooleanCarrier.h"

struct Colour
{
	int R;
	int G;
	int B;
	int A;
	bool operator==(const Colour& other) const
	{
		return R == other.R && G == other.G && B == other.B && A == other.A;
	}
	bool operator!=(const Colour& other) const
	{
		return !(*this == other);
	}
};

//A class used (like an interface in C#) to represent all
//classes that are "renderable". At the time of writing,
//the comprehensive list of classes that inherit this one
//includes Sprite and Line.
class Renderable
{
	public:
		virtual void Render()=0;
		virtual bool IsActive()
		{
			return isActive;
		}
		virtual void SetActive(bool active)
		{
			if (active != isActive)
			{
				isActive = active;
				SetRenderNow();
			}
		}
		void SetRenderNow(BooleanCarrier* carrier)
		{
			sceneRenderNow = carrier;
		}
	protected:
		void SetRenderNow()
		{
			if (sceneRenderNow)
			{
				sceneRenderNow->value = true;
			}
		}
		BooleanCarrier* sceneRenderNow;
	private:
		bool isActive = true;

};

#endif