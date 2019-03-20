#ifndef _SCENEMANAGER_H
#define _SCENEMANAGER_H

#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include <string>
#include "Scene.h"
#include "BorisConsoleManager.h"

//using namespace std;
//Create a class used to store pointers to instances of "Scene" so that they can be easily accessed when necessary.
class SceneManager
{
	public:
		//A method which returns the only instance of this class.
		static SceneManager* GetInstance();
		//Destructor method.
		~SceneManager();
		//A method which returns a pointer to a scene of a given name.
		Scene* GetScene(std::string scenename);
		//A method which adds a pointer to a scene using a given name as a key.
		void AddScene(std::string scenename, Scene* scene);
	private:
		//Constructor, private so that an instance can't be created outside of this class.
		SceneManager();
		//A pointer to the only instance of this class.
		static SceneManager* _instance;
		//A map which uses std::strings (scene names) as keys 
		//and "Scene" pointers as values.
		std::map<std::string, Scene*> scenes;
		static BorisConsoleManager* BorisConsoleManager;
};

#endif // !_SCENEMANAGER_H