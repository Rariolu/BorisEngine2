#include "Scene.h"

FontManager* Scene::fontmanager = FontManager::GetInstance();
SoundManager* Scene::soundManager = SoundManager::GetInstance();
TextureManager* Scene::textureManager = TextureManager::getInstance();

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
	return AddLine(sA, sB, layer);
}

void Scene::AddRenderable(Renderable* renderable, int layer)
{
	renderable->SetRenderNow(renderNow);
	renderNow->value = true;
	layers = layer > layers - 1 ? layer + 1 : layers;
	layer = layer > 0 ? layer : 0;
	StdVec<Renderable*>* spriteLayer = GetSpritesOfLayer(layer);
	if (spriteLayer->size() < 1)
	{
		layered_sprites.insert(make_pair(layer, spriteLayer));
	}
	spriteLayer->push_back(renderable);
}

Sprite* Scene::AddSprite(Texture* texture, int layer)
{
	Sprite* sprite = new Sprite(texture);
	AddRenderable(sprite, layer);
	return sprite;
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

void Scene::SetRenderer(SDL_Renderer* renderer)
{
	_renderer = renderer;
}

void Scene::DeleteRenderable(Renderable* renderable, int layer)
{
	StdVec<Renderable*>* renderables = GetSpritesOfLayer(layer);
	for (StdVec<Renderable*>::iterator i = renderables->begin(); i < renderables->end(); i++)
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

void Scene::DeleteSprite(Sprite* sprite, int layer)
{
	DeleteRenderable(sprite, layer);
}

String Scene::GetMusicName()
{
	return musicName;
}

SDL_Renderer* Scene::GetRenderer()
{
	return _renderer;
}

StdVec<Renderable*>* Scene::GetSpritesOfLayer(int layer)
{
	Dictionary<int, StdVec<Renderable*>*>::iterator i = layered_sprites.find(layer);
	if (i != layered_sprites.end())
	{
		return i->second;
	}
	StdVec<Renderable*>* empty = new StdVec<Renderable*>();
	return empty;
}

bool Scene::IsPreviouslyInitialised()
{
	return previouslyInitialised;
}

bool Scene::LayerExists(int layer)
{
	StdVec<Renderable*>* sprites = GetSpritesOfLayer(layer);
	return sprites->size() > 0;
}

void Scene::SetMusicName(String musicname)
{
	musicName = musicname;
}

void Scene::SetNextScene(String scenename)
{
	nextscene = scenename;
}

void Scene::DeleteSprites()
{
	for (Dictionary<int, StdVec<Renderable*>*>::iterator i = layered_sprites.begin(); i != layered_sprites.end(); i++)
	{
		StdVec<Renderable*>* vec = i->second;
		for (StdVec<Renderable*>::iterator j = vec->begin(); j < vec->end(); j++)
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
				break;
			}
			case SDL_MOUSEBUTTONDOWN:
			{
				SDL_MouseButtonEvent mousebutton = event.button;
				if (!MouseDown(mousebutton))
				{
					return false;
				}
				break;
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

void Scene::Render()
{
	if (renderNow->value)
	{
		SDL_RenderClear(_renderer);
		if (layered_sprites.size() > 0)
		{
			for (Dictionary<int, StdVec<Renderable*>*>::iterator layer = layered_sprites.begin(); layer != layered_sprites.end(); layer++)
			{
				StdVec<Renderable*>* sprites = layer->second;
				for (StdVec<Renderable*>::iterator i = sprites->begin(); i < sprites->end(); i++)
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