#include "SpriteTests.h"

StrTestMap spriteTests =
{
	{"AnimationCheck",AnimationCheck},
	{"AnimationSkipFrame",AnimationSkipFrame},
	{"Centre",Centre},
	{"CentreXShifted",CentreXShifted},
	{"CentreXYShifted",CentreXYShifted},
	{"CentreYShifted",CentreYShifted},
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
String block3Name = "block3";

double SpriteRunAll()
{
	SDL_Window_Manager* sdlWindowManager = SDL_Window_Manager::getInstance();
	if (sdlWindowManager->initWND("Blep", 800, 800))
	{
		textureManager->SetRenderer(sdlWindowManager->getSDLRenderer());
		textureManager->AddTexture(block1Name, "Textures\\block1.png");
		textureManager->AddTexture(block2Name, "Textures\\block2.png");
		textureManager->AddTexture(block3Name, "Textures\\block3.png");
		double t = RunTests(spriteTests);

		// Delete our OpengL context
		SDL_GL_DeleteContext(sdlWindowManager->getSDLWindow());

		// Destroy the window
		SDL_DestroyWindow(sdlWindowManager->getSDLWindow());

		// Quit IMG system
		IMG_Quit();

		// Shutdown SDL 2
		SDL_Quit();

		return t;
	}
	return 0;
}

double SpriteTestsSize()
{
	return (double)spriteTests.size();
}

bool AnimationCheck()
{
	Animation anim;
	anim.frameDuration = 0.25F;
	Texture* b1 = textureManager->GetTexture(block1Name);
	Texture* b2 = textureManager->GetTexture(block2Name);
	Texture* b3 = textureManager->GetTexture(block3Name);
	anim.frames.push_back(b2);
	anim.frames.push_back(b3);
	Sprite s1(b1);
	s1.PlayAnimation(&anim);
	Texture* firstFrame = s1.GetTexture();
	s1.Update(0.26F);
	Texture* secondFrame = s1.GetTexture();
	bool firstCorrect = firstFrame == b2 && firstFrame != b1;
	bool secondCorrect = secondFrame == b3;
	return firstCorrect && secondCorrect;
}

bool AnimationSkipFrame()
{
	Animation anim;
	anim.frameDuration = 0.25F;
	Texture* b1 = textureManager->GetTexture(block1Name);
	Texture* b2 = textureManager->GetTexture(block2Name);
	Texture* b3 = textureManager->GetTexture(block3Name);
	anim.frames.push_back(b2);
	anim.frames.push_back(b3);
	anim.frames.push_back(b1);
	Sprite s1(b1);
	s1.PlayAnimation(&anim);
	Texture* firstFrame = s1.GetTexture();
	s1.Update(0.51F);
	Texture* secondFrame = s1.GetTexture();
	bool firstCorrect = firstFrame == b2 && firstFrame != b1;
	bool secondCorrect = secondFrame == b1;
	return firstCorrect && secondCorrect;
}

bool Centre()
{
	Sprite s1(block1Name);
	s1.SetPosition({ 0,0,80,80 });
	SDL_Point centre = s1.GetCentre();
	SDL_Point test = { 40,40 };
	return (centre.x == test.x) && (centre.y == test.y);
}

bool CentreXShifted()
{
	Sprite s1(block1Name);
	s1.SetPosition({ 10,0,80,80 });
	SDL_Point centre = s1.GetCentre();
	SDL_Point test = { 50,40 };
	return (centre.x == test.x) && (centre.y == test.y);
}

bool CentreXYShifted()
{
	Sprite s1(block1Name);
	s1.SetPosition({ 10,10,80,80 });
	SDL_Point centre = s1.GetCentre();
	SDL_Point test = { 50,50 };
	return (centre.x == test.x) && (centre.y == test.y);
}

bool CentreYShifted()
{
	Sprite s1(block1Name);
	s1.SetPosition({ 0,10,80,80 });
	SDL_Point centre = s1.GetCentre();
	SDL_Point test = { 40,50 };
	return (centre.x == test.x) && (centre.y == test.y);
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
	FloatRect pos = { 0.5F,0.5F,(float)s1.GetDimensions().w ,(float)s1.GetDimensions().h };
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