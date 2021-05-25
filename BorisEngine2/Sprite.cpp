#include "Sprite.h"

TextureManager* Sprite::texturemanager = TextureManager::getInstance();
SoundManager* Sprite::soundmanager = SoundManager::GetInstance();
BorisConsoleManager* Sprite::borisConsoleManager = BorisConsoleManager::Instance();

Sprite::Sprite(String textureName) : Sprite(texturemanager->GetTexture(textureName))
{

}

Sprite::Sprite(Texture* _texture)
{
	if (_texture)
	{
		texture = _texture;
		int textureWidth = texture->getWidth();
		int textureHeight = texture->getHeight();
		SetDimensions(textureWidth, textureHeight);
		SetPosition({ 0,0,(float)textureWidth,(float)textureHeight });
	}
	scale = { 1,1 };
	SetRotation(0);
}

Sprite::~Sprite()
{

}

//void Sprite::AddConstantForce(Vector2 force)
//{
//	constantForce += force;
//}

//void Sprite::AddImpulseForce(Vector2 force)
//{
//	velocity += force;
//}

bool Sprite::CollidesWith(SDL_Rect* boundary)
{
	const SDL_Rect myCurrentPos = GetPosition();
	return SDL_HasIntersection(&myCurrentPos, boundary) != 0;
}

bool Sprite::CollidesWith(Sprite* otherSprite)
{
	if (!IsActive() || !otherSprite->IsActive())
	{
		return false;
	}
	SDL_Rect expandedRect = BorisOperations::GetExpandedRect(otherSprite->GetPosition(), 2);
	return CollidesWith(&expandedRect);
}

bool Sprite::Clicked(SDL_Point* mouseposition)
{
	const SDL_Rect myCurrentPos = GetPosition();
	return IsActive() && SDL_PointInRect(mouseposition, &myCurrentPos);
}

Vector2 Sprite::Force()
{
	return constantForce*mass;
}

SDL_Point Sprite::GetCentre()
{
	return BorisOperations::Vector2ToSDLPoint(GetFloatCentre());
}

SDL_Rect Sprite::GetDimensions()
{
	return dimension;
}

float Sprite::GetDistanceFrom(Sprite* sprite)
{
	return BorisOperations::GetDistance(GetVec2Position(), sprite->GetVec2Position());
}

Vector2 Sprite::GetFloatCentre()
{
	return{ position.X + (position.W / 2),position.Y + (position.H / 2) };
}

FloatRect Sprite::GetFloatPosition()
{
	return position;
}

float Sprite::GetMass()
{
	return mass;
}

SDL_Rect Sprite::GetPosition()
{
	return BorisOperations::GetSDLRect(position);
}

float Sprite::GetRotation()
{
	return rotation;
}

SpriteType Sprite::GetSpriteType()
{
	return sprite_type;
}

Vector2 Sprite::GetScale()
{
	return scale;
}

Texture* Sprite::GetTexture()
{
	return texture;
}

Vector2 Sprite::GetVec2Position()
{
	return{ position.X,position.Y };
}

//Vector2 Sprite::GetVelocity()
//{
//	return velocity;
//}

void Sprite::LerpPosition(FloatRect destination, float f)
{
	SetPosition(BorisOperations::Lerp(position, destination, f));
}

void Sprite::LerpPosition(Vector2 destination, float f)
{
	SetPosition(BorisOperations::Lerp(GetVec2Position(), destination, f));
}

void Sprite::MsgPosition()
{
	String msg = "X: " + std::to_string(position.X) + "; Y: " + std::to_string(position.Y) + "; W: " + std::to_string(position.W) + "; H: " + std::to_string(position.H) + ";";
	borisConsoleManager->Print(msg);
}

void Sprite::PlayAnimation(Animation* anim)
{
	if (anim)
	{
		if (anim->frames.size() > 0)
		{
			currentAnimation = anim;
			SetTexture(anim->frames[0]);
		}
	}
}

//void Sprite::ReconcileCollisionForces(Sprite* otherSprite)
//{
//	Vector2 result = -(Force() + otherSprite->Force());
//	SetVelocity(result / mass);
//	otherSprite->SetVelocity(result / otherSprite->GetMass());
//}

//Make the sprite appear in the window at its given position.
void Sprite::Render()
{
	//RenderRotated(&dimension, &GetPosition());
	if (!rotation)
	{
		SDL_Rect myCurrentPos = GetPosition();
		Render(&dimension, &myCurrentPos);
	}
	else
	{
		SDL_Rect myCurrentPos = GetPosition();
		RenderRotated(&dimension, &myCurrentPos);
	}
}

void Sprite::Render(SDL_Rect* source, SDL_Rect* dest)
{
	if (GetSpriteType() == REGULAR)
	{
		texture->Render(source, dest);
	}
	else
	{
		texture->Render(NULL, NULL);
	}
}

void Sprite::RenderRotated(SDL_Rect* source, SDL_Rect* dest)
{
	if (GetSpriteType() == REGULAR)
	{
		SDL_Point myCurrentCenter = GetCentre();
		texture->Render(source, dest, rotation, &myCurrentCenter);
	}
	else
	{
		SDL_Point myCurrentCenter = GetCentre();
		texture->Render(NULL, NULL, rotation, &myCurrentCenter);
	}
}

void Sprite::SetAbsoluteScale(Vector2 _scale)
{
	scale.X = _scale.X;
	scale.Y = _scale.Y;
	ScaleSprite();
}

void Sprite::SetAbsoluteScale(float x, float y)
{
	SetAbsoluteScale({ x,y });
}

void Sprite::SetDimensions(SDL_Rect _dimension)
{
	if (!SDL_RectEquals(&dimension, &_dimension))
	{
		dimension = _dimension;
		SetRenderNow();
	}
}

void Sprite::SetDimensions(int _width, int _height)
{
	SetDimensions({ 0,0,_width,_height });
}

void Sprite::SetMass(float m)
{
	mass = m;
}

void Sprite::SetPosition(FloatRect _position)
{
	if (_position != position)
	{
		position = _position;
		//centre.x = BorisOperations::Round(position.W / 2);
		//centre.y = BorisOperations::Round(position.H / 2);
		SetRenderNow();
	}
}

void Sprite::SetPosition(int x, int y)
{
	SetPosition((float)x, (float)y);
}

void Sprite::SetPosition(float x, float y)
{
	SetPosition({x,y,position.W,position.H});
}

void Sprite::SetPosition(Vector2 pos)
{
	SetPosition(pos.X, pos.Y);
}

void Sprite::SetRotation(float _rotation)
{
	rotation = _rotation;
	SetRenderNow();
}

void Sprite::SetScale(Vector2 _scale)
{
	scale.X *= _scale.X;
	scale.Y *= _scale.Y;
	ScaleSprite();
}

void Sprite::SetScale(float x, float y)
{
	SetScale({ x,y });
}

void Sprite::SetSpriteType(SpriteType type)
{
	sprite_type = type;
	SetRenderNow();
}

void Sprite::SetTexture(Texture* _texture)
{
	if (texture != _texture)
	{
		texture = _texture;
		if (texture)
		{
			SetDimensions(texture->getWidth(), texture->getHeight());
		}
		SetRenderNow();
	}
}

void Sprite::SetTexture(String textureName)
{
	SetTexture(texturemanager->GetTexture(textureName));
}

//void Sprite::SetVelocity(Vector2 vel)
//{
//	velocity = vel;
//}

void Sprite::Translate(Vector2 translation)
{
	SetPosition({( position.X + translation.X),(position.Y + translation.Y),position.W,position.H });
}

void Sprite::Update(float deltaTime)
{
	if (currentAnimation)
	{
		currentAnimation->delta += deltaTime;
		if (currentAnimation->delta >= currentAnimation->frameDuration)
		{
			currentAnimation->currentFrame+=(int)(currentAnimation->delta/currentAnimation->frameDuration);
			currentAnimation->delta = 0;
			if (currentAnimation->currentFrame >= (int)currentAnimation->frames.size())
			{
				currentAnimation->Reset();
				if (currentAnimation->loop)
				{
					SetTexture(currentAnimation->frames[0]);
				}
				else
				{
					currentAnimation = NULL;
				}
			}
			else
			{
				SetTexture(currentAnimation->frames[currentAnimation->currentFrame]);
			}
		}
	}
	/*velocity += constantForce*deltaTime;
	Translate(velocity*deltaTime);*/
}

void Sprite::ScaleSprite()
{
	SetPosition({ position.X,position.Y,dimension.w*scale.X,dimension.h*scale.Y });
}
