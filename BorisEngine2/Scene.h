#ifndef _SCENE_H
#define _SCENE_H

#include<vector>
#include"Sprite.h"
#include"TextureManager.h"
#include"SoundManager.h"
#include"FontManager.h"
#include "Line.h"

//using namespace std;

//An abstract class which is used to represent a scene within the game.
class Scene
{
	public:
		//Constructor, takes a std::string that is used as a key
		//to get the texture for the background.
		Scene(String backgroundimagename);
		//Destructor method.
		~Scene();
		//A method which runs the scene until it is closed
		//and then returns a std::string representing the next
		//scene to be loaded.
		String Run();
		//A method which initialises this scene using a pointer to the sdl renderer.
		//It is virtual so it can be overridden when necessary.
		virtual void Initialise(SDL_Renderer* renderer);
		//A method which creates a sprite using the given texture and then adds it
		//to the given layer before returning it.
		Sprite* AddSprite(Texture* texture, int layer);
		Line* AddLine(SDL_Point a, SDL_Point b, int layer);
		Line* AddLine(Vector2 a, Vector2 b, int layer);
		//Add item to be rendered (an instance of a child class of "Renderable").
		void AddRenderable(Renderable* renderable, int layer);
	protected:
		//A method which sets a value for the next scene
		//to be run and causes this scene to subsequently close.
		void SetNextScene(String scenename);
		//A method which returns the sdl renderer of this scene.
		SDL_Renderer* GetRenderer();
		//A pointer to an instance of "FontManager".
		static FontManager* fontmanager;
		//A pointer to an instance of "SoundManager".
		static SoundManager* soundManager;
		//A pointer to an instance of "TextureManager".
		static TextureManager* textureManager;
		//A method which returns a pointer to an array containing pointers
		//to sprites that are contained on the given layer.
		std::vector<Renderable*>* GetSpritesOfLayer(int layer);
		//A method which returns a boolean representing whether or not
		//there are sprites on a layer determined by a given index.
		bool LayerExists(int layer);
		//A method which returns the name of the song currently playing.
		String GetMusicName();
		//A method which sets the song that is currently playing.
		void SetMusicName(String musicname);
		//A method which removes a sprite from a given layer.
		//I might delete this at some point 'cause "DeleleRenderable"
		//does the same thing.
		void DeleteSprite(Sprite* sprite,int layer);
		//A method which removes a renderable from a given layer.
		void DeleteRenderable(Renderable* renderable, int layer);

		bool IsPreviouslyInitialised();
	private:
		//A pointer to the sdl renderer.
		SDL_Renderer* _renderer;
		//A map which uses integers (layers) as keys
		//and Sprite arrays as values.
		std::map<int, std::vector<Renderable*>*> layered_sprites;
		//A float value that contains the time stamp
		//of the last time that the "GetDeltaTime"
		//method was run.
		float previousTimeStamp = 0;
		//An integer representing the quantity of layers.
		int layers = 1;
		//A boolean which represents whether or not the "Initialise"
		//method has been run.
		bool initialised = false;
		//A method which takes appropriate actions depending on the user's input and returns
		//a boolean representing whether or not to continue running the scene.
		//It is a pure virutal bool as the nature of this method would be completely different
		//depending on the specific child class of this one.
		virtual bool GetInput();

		//In the event of a key being pressed, this method is called with a value representing
		//said key.
		virtual bool KeyDown(SDL_Keycode key);

		//In the event of a mouse button being pressed, this method is called with a value
		//representing said event.
		virtual bool MouseDown(SDL_MouseButtonEvent mousebutton);

		//A method which returns the amount of time that has passed
		//between the previous frame and the current one.
		float GetDeltaTime();
		//A method which is called once per frame, this is a pure virtual method
		//as the nature of this method would be completely different
		//depending on the specific child class of this one.
		virtual void Update(float deltaTime) = 0;
		//A pointer to an instance of "Sprite" which is used to display the background.
		Sprite* background;
		//A method which deletes all sprites.
		void DeleteSprites();
		//A method which renders all the sprites.
		void Render();
		//A value representing the next scene to be played.
		String nextscene = "";
		//A value representing the music that is currently playing.
		String musicName = "";
		BooleanCarrier* renderNow = new BooleanCarrier(true);
		bool previouslyInitialised = false;
};

#endif