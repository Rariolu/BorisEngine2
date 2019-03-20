#include "SceneManager.h"

SceneManager* SceneManager::_instance = NULL;

BorisConsoleManager* SceneManager::BorisConsoleManager = BorisConsoleManager::Instance();

SceneManager::SceneManager()
{

}

SceneManager::~SceneManager()
{

}

SceneManager* SceneManager::GetInstance()
{
	if (_instance == NULL)
	{
		_instance = new SceneManager();
	}
	return _instance;
}

Scene* SceneManager::GetScene(std::string scenename)
{
	std::map<std::string, Scene*>::iterator scene = scenes.find(scenename);
	if (scene != scenes.end())
	{
		return scene->second;
	}
	return NULL;
}

void SceneManager::AddScene(std::string scenename, Scene* scene)
{
	if (!GetScene(scenename) && scenename != "")
	{
		scenes.insert(make_pair(scenename, scene));
	}
	if (scenename == "")
	{
		BorisConsoleManager->Print("Using an empty std::string for a scene name is illegal as this would create a runtime error. Please use a substantive name.");
		//cout << "Using an empty std::string for a scene name is illegal as this would create a runtime error. Please use a substantive name." << endl;
	}
}