#include "ThreadManager.h"

ThreadManager* ThreadManager::_instance = NULL;

ThreadManager::ThreadManager()
{

}

ThreadManager::~ThreadManager()
{
	Dispose();
}

ThreadManager* ThreadManager::GetInstance()
{
	if (!_instance)
	{
		return _instance = new ThreadManager();
	}
	return _instance;
}

int ThreadManager::ThreadCount()
{
	return (int)threads.size();
}

void ThreadManager::Dispose()
{
	int j = 0;
	for (StdVec<SDL_Thread*>::iterator i = threads.begin(); i < threads.end(); i++)
	{
		std::cout << ++j << std::endl;
		SDL_WaitThread((*i), NULL);
	}
	threads.clear();
}

void ThreadManager::RunThread(SDL_ThreadFunction method, void* param)
{
	String* n = new String("Thread #" + std::to_string(ThreadCount()));
	LPCSTR name = BorisOperations::String_to_LPCSTR(*n);
	SDL_Thread* threadID = SDL_CreateThread(method, name, param);
	threads.push_back(threadID);
}