#include "SpriteTests.h"

StrTestMap spriteTests =
{
	{"ClickNegative",ClickNegative},
	{"ClickPositive",ClickPositive},
	{"CollisionNegative",CollisionNegative},
	{"CollisionPositive",CollisionPositive},
	{"InactiveVsActiveCollision",InactiveVsActiveCollision},
	{"VelocityNegative",VelocityNegative},
	{"VelocityPositive",VelocityPositive}
};

TextureManager* textureManager = TextureManager::getInstance();

String block1Name = "block1";
String block2Name = "block2";

double SpriteRunAll()
{
	SDL_Window_Manager* sdlWindowManager = SDL_Window_Manager::getInstance();
	if (sdlWindowManager->initWND("Blep", 800, 800))
	{
		textureManager->SetRenderer(sdlWindowManager->getSDLRenderer());
		textureManager->AddTexture(block1Name, "Textures\\block1.png");
		textureManager->AddTexture(block2Name, "Textures\\block2.png");
		return RunTests(spriteTests);
	}
	return 1;
}

bool ClickNegative()
{
	Sprite s1(block1Name);
	s1.SetActive(true);
	SDL_Point p = { s1.GetDimensions().w + 3,s1.GetDimensions().h + 3 };
	return !s1.Clicked(&p);
}

bool ClickPositive()
{
	Sprite s1(block1Name);
	s1.SetActive(true);
	SDL_Point p = { s1.GetDimensions().w / 2,s1.GetDimensions().h / 2 };
	return s1.Clicked(&p);
}

bool CollisionNegative()
{
	Sprite s1(block1Name);
	Sprite s2(block2Name);
	s1.SetActive(true);
	s2.SetPosition(s1.GetDimensions().w + 5, s1.GetDimensions().h + 5);
	s2.SetActive(true);
	return !s1.CollidesWith(&s2);
}

bool CollisionPositive()
{
	Sprite s1(block1Name);
	Sprite s2(block2Name);
	s1.SetActive(true);
	s2.SetPosition(s1.GetDimensions().w/2, s1.GetDimensions().h/2);
	s2.SetActive(true);
	return s1.CollidesWith(&s2);
}

bool InactiveVsActiveCollision()
{
	Sprite s1(block1Name);
	Sprite s2(block2Name);
	Sprite s3(block2Name);
	s1.SetActive(true);
	s2.SetPosition(s1.GetDimensions().w / 2, s1.GetDimensions().h / 2);
	s2.SetActive(true);
	s3.SetPosition(s1.GetDimensions().w / 2, s1.GetDimensions().h / 2);
	s3.SetActive(false);
	return s1.CollidesWith(&s2) && (!s1.CollidesWith(&s3));
}

bool VelocityNegative()
{
	Sprite s1(block1Name);
	Vector2 v = { 1,1 };
	s1.SetVelocity(v);
	s1.Update(1);
	FloatRect pos = { 0.5F,0.5F,s1.GetDimensions().w ,s1.GetDimensions().h };
	return s1.GetFloatPosition() != pos;
}

bool VelocityPositive()
{
	Sprite s1(block1Name);
	Vector2 v = { 1,1 };
	s1.SetVelocity(v);
	s1.Update(0.5);
	FloatRect pos = s1.GetFloatPosition();
	pos.X = 0.5F;
	pos.Y = 0.5F;
	return s1.GetFloatPosition() == pos;
}