#include "Sprite.h"

TextureManager* Sprite::texturemanager = TextureManager::getInstance();
SoundManager* Sprite::soundmanager = SoundManager::GetInstance();
BorisConsoleManager* Sprite::BorisConsoleManager = BorisConsoleManager::Instance();

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

void Sprite::MsgPosition()
{
	String msg = "X: " + std::to_string(position.X) + "; Y: " + std::to_string(position.Y) + "; W: " + std::to_string(position.W) + "; H: " + std::to_string(position.H) + ";";
	BorisConsoleManager->Print(msg);
}

Sprite::~Sprite()
{
	
}

//Make the sprite appear in the window at its given position.
void Sprite::Render()
{
	if (!rotation)
	{
		Render(&dimension, &GetPosition());
	}
	else
	{
		RenderRotated(&dimension, &GetPosition());
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
		texture->Render(source, dest, rotation, &centre);
	}
	else
	{
		texture->Render(NULL, NULL, rotation, &centre);
	}
}

SDL_Rect Sprite::GetPosition()
{
	return BorisOperations::GetSDLRect(position);
}

FloatRect Sprite::GetFloatPosition()
{
	return position;
}

Vector2 Sprite::GetVec2Position()
{
	return{ position.X,position.Y };
}

void Sprite::SetPosition(FloatRect _position)
{
	if (_position != position)
	{
		position = _position;
		centre.x = BorisOperations::Round(position.W / 2);
		centre.y = BorisOperations::Round(position.H / 2);
		SetRenderNow();
	}
}

void Sprite::SetPosition(float x, float y)
{
	SetPosition({x,y,position.W,position.H});
}

void Sprite::SetPosition(Vector2 pos)
{
	SetPosition(pos.X, pos.Y);
}

void Sprite::LerpPosition(FloatRect destination,float f)
{
	SetPosition(BorisOperations::Lerp(position, destination, f));
}

void Sprite::LerpPosition(Vector2 destination, float f)
{
	SetPosition(BorisOperations::Lerp(GetVec2Position(), destination, f));
}

Texture* Sprite::GetTexture()
{
	return texture;
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

SDL_Rect Sprite::GetDimensions()
{
	return dimension;
}

void Sprite::SetDimensions(SDL_Rect _dimension)
{
	//TODO: Fix this operator BS.
	//if (dimension != _dimension)
	{
		dimension = _dimension;
		width = dimension.w;
		height = dimension.h;
		SetRenderNow();
	}
}

void Sprite::SetDimensions(int _width, int _height)
{
	SetDimensions({ 0,0,_width,_height });
}

SDL_Point Sprite::GetCentre()
{
	return centre;
}

//void Sprite::SetCentre(SDL_Point _centre)
//{
//	centre = _centre;
//}

Vector2 Sprite::GetScale()
{
	return scale;
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

float Sprite::GetRotation()
{
	return rotation;
}

void Sprite::SetRotation(float _rotation)
{
	rotation = _rotation;
	SetRenderNow();
}



void Sprite::Translate(Vector2 translation)
{
	SetPosition({( position.X + translation.X),(position.Y + translation.Y),position.W,position.H });
}

bool Sprite::CollidesWith(SDL_Rect* boundary)
{
	return SDL_HasIntersection(&GetPosition(), boundary) != 0;
}

bool Sprite::CollidesWith(Sprite* otherSprite)
{
	if (!IsActive() || !otherSprite->IsActive())
	{
		return false;
	}
	return CollidesWith(&BorisOperations::GetExpandedRect(otherSprite->GetPosition(),10));
}

bool Sprite::Clicked(SDL_Point* mouseposition)
{
	return IsActive() && SDL_PointInRect(mouseposition, &GetPosition());
}

void Sprite::SetSpriteType(SpriteType type)
{
	sprite_type = type;
	SetRenderNow();
}

SpriteType Sprite::GetSpriteType()
{
	return sprite_type;
}

float Sprite::GetDistanceFrom(Sprite* sprite)
{
	return BorisOperations::GetDistance(GetVec2Position(), sprite->GetVec2Position());
}

void Sprite::PlayAnimation(Animation* anim)
{
	if (anim->frames.size() > 0)
	{
		currentAnimation = anim;
		SetTexture(anim->frames[0]);
	}
}

void Sprite::Update(float deltaTime)
{
	if (currentAnimation)
	{
		currentAnimation->delta += deltaTime;
		if (currentAnimation->delta >= currentAnimation->frameDuration)
		{
			currentAnimation->currentFrame++;
			currentAnimation->delta = 0;
			if (currentAnimation->currentFrame >= currentAnimation->frames.size())
			{
				currentAnimation->Reset();
				currentAnimation = NULL;
			}
			else
			{
				SetTexture(currentAnimation->frames[currentAnimation->currentFrame]);
			}
		}
	}
	velocity += constantForce*deltaTime;
	Translate(velocity);
}

Vector2 Sprite::Force()
{
	return constantForce*mass;
}

Vector2 Sprite::GetVelocity()
{
	return velocity;
}

void Sprite::AddConstantForce(Vector2 force)
{
	constantForce += force;
}

float Sprite::GetMass()
{
	return mass;
}

void Sprite::SetMass(float m)
{
	mass = m;
}

void Sprite::ScaleSprite()
{
	SetPosition({ position.X,position.Y,dimension.w*scale.X,dimension.h*scale.Y });
}