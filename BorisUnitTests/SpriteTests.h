#ifndef _SPRITE_TESTS_H
#define _SPRITE_TESTS_H

#include "Tests.h"
#include "Sprite.h"
#include "TextureManager.h"
#include "SDL_Window_Manager.h"

double SpriteRunAll();
bool ClickNegative();
bool ClickPositive();
bool CollisionNegative();
bool CollisionPositive();
bool InactiveVsActiveCollision();
bool VelocityNegative();
bool VelocityPositive();

#endif