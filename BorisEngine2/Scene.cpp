#include "Scene.h"

FontManager* Scene::fontmanager = FontManager::GetInstance();
TextureManager* Scene::textureManager = TextureManager::getInstance();
SoundManager* Scene::soundManager = SoundManager::GetInstance();

Scene::Scene(String backgroundimagename)
{
	Texture* backTexture = textureManager->GetTexture(backgroundimagename);
	if (backTexture)
	{
		background = AddSprite(backTexture, 0);
		background->SetActive(true);
		background->SetSpriteType(BACKGROUND);
	}
}

Scene::~Scene()
{
	delete renderNow;
	renderNow = NULL;
	DeleteSprites();
}

Sprite* Scene::AddSprite(Texture* texture, int layer)
{
	Sprite* sprite = new Sprite(texture);
	AddRenderable(sprite, layer);
	return sprite;
}

Line* Scene::AddLine(SDL_Point a, SDL_Point b, int layer)
{
	Line* line = new Line(GetRenderer(), a, b);
	AddRenderable(line, layer);
	return line;
}

Line* Scene::AddLine(Vector2 a, Vector2 b, int layer)
{
	SDL_Point sA = { (int)a.X,(int)a.Y };
	SDL_Point sB = { (int)b.X,(int)b.Y };
	return AddLine(sA,sB, layer);
}

void Scene::AddRenderable(Renderable* renderable, int layer)
{
	renderable->SetRenderNow(renderNow);
	renderNow->value = true;
	layers = layer > layers - 1 ? layer + 1 : layers;
	layer = layer > 0 ? layer : 0;
	std::vector<Renderable*>* spriteLayer = GetSpritesOfLayer(layer);
	if (spriteLayer->size() > 0)
	{
		spriteLayer->push_back(renderable);
	}
	else
	{
		std::vector<Renderable*>* spritearray = new std::vector<Renderable*>();
		spritearray->push_back(renderable);
		layered_sprites.insert(make_pair(layer, spritearray));
	}
}

void Scene::DeleteSprites()
{
	for (std::map<int, std::vector<Renderable*>*>::iterator i = layered_sprites.begin(); i != layered_sprites.end(); i++)
	{
		std::vector<Renderable*>* vec = i->second;
		for (std::vector<Renderable*>::iterator j = vec->begin(); j < vec->end(); j++)
		{
			delete (*j);
			(*j) = NULL;
		}
		vec->clear();
		delete vec;
		vec = NULL;
	}
	layered_sprites.clear();
}

float Scene::GetDeltaTime()
{
	float currentTime = (float)SDL_GetTicks();
	float milliseconds = (currentTime - previousTimeStamp) / 60;
	previousTimeStamp = currentTime;
	return milliseconds;
}

SDL_Renderer* Scene::GetRenderer()
{
	return _renderer;
}

std::vector<Renderable*>* Scene::GetSpritesOfLayer(int layer)
{
	std::map<int, std::vector<Renderable*>*>::iterator i = layered_sprites.find(layer);
	if (i != layered_sprites.end())
	{
		return i->second;
	}
	std::vector<Renderable*>* empty = new std::vector<Renderable*>();
	return empty;
}

void Scene::Initialise(SDL_Renderer* renderer)
{
	renderNow->value = true;
	_renderer = renderer;
	initialised = true;
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
	SDL_RenderPresent(_renderer);
	nextscene = "";
	layered_sprites.clear();
	AddRenderable(background, 0);
	if (GetMusicName() != Util::GetInstance()->GetCurrentMusic())
	{
		Mix_HaltMusic();
		if (soundManager->GetSound(GetMusicName()))
		{
			Util::GetInstance()->SetCurrentMusic(GetMusicName());
			soundManager->GetSound(GetMusicName())->Play();
		}
	}
	previouslyInitialised = true;
}

void Scene::DeleteSprite(Sprite* sprite,int layer)
{
	DeleteRenderable(sprite, layer);
}

void Scene::DeleteRenderable(Renderable* renderable, int layer)
{
	std::vector<Renderable*>* renderables = GetSpritesOfLayer(layer);
	for (std::vector<Renderable*>::iterator i = renderables->begin(); i < renderables->end(); i++)
	{
		if ((*i) == renderable)
		{
			renderables->erase(i);
			break;
		}
	}
	delete renderable;
	renderable = NULL;
}

bool Scene::IsPreviouslyInitialised()
{
	return previouslyInitialised;
}

bool Scene::LayerExists(int layer)
{
	std::vector<Renderable*>* sprites = GetSpritesOfLayer(layer);
	return sprites->size() > 0;
}

void Scene::Render()
{
	if (renderNow->value)
	{
		SDL_RenderClear(_renderer);
		if (layered_sprites.size() > 0)
		{
			for (std::map<int, std::vector<Renderable*>*>::iterator layer = layered_sprites.begin(); layer != layered_sprites.end(); layer++)
			{
				std::vector<Renderable*>* sprites = layer->second;
				for (std::vector<Renderable*>::iterator i = sprites->begin(); i < sprites->end(); i++)
				{
					if ((*i)->IsActive())
					{
						(*i)->Render();
					}
				}
			}
		}
		SDL_RenderPresent(_renderer);
		renderNow->value = false;
	}
}

//Launch the scene
String Scene::Run()
{
	if (initialised)
	{
		bool loop = true;
		while (loop && nextscene == "")
		{
			float elapsedTime = GetDeltaTime();
			loop = GetInput();
			if (loop)
			{
				Update(elapsedTime);
				Render();
			}
		}
	}
	return nextscene;
}

void Scene::SetNextScene(String scenename)
{
	nextscene = scenename;
}

String Scene::GetMusicName()
{
	return musicName;
}

void Scene::SetMusicName(String musicname)
{
	musicName = musicname;
}

bool Scene::GetInput()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			//TODO: Add functions for other SDL events (these are good for my current projects).
			case SDL_QUIT:
			{
				return false;
			}
			case SDL_KEYDOWN:
			{
				SDL_Keycode keycode = event.key.keysym.sym;
				if (!KeyDown(keycode))
				{
					return false;
				}
			}
			case SDL_MOUSEBUTTONDOWN:
			{
				SDL_MouseButtonEvent mousebutton = event.button;
				if (!MouseDown(mousebutton))
				{
					return false;
				}
			}
			default:
			{
				break;
			}
		}
	}
	return true;
}

bool Scene::KeyDown(SDL_Keycode key)
{
	return true;
}

bool Scene::MouseDown(SDL_MouseButtonEvent mousebutton)
{
	return true;
}