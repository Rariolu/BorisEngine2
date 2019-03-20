#ifndef _THREAD_MANAGER_H
#define _THREAD_MANAGER_H

#include "SDL.h"
#include "BorisOperations.h"
#include <iostream>
#include <vector>


class ThreadManager
{
	public:
		static ThreadManager* GetInstance();
		int ThreadCount();
		void Dispose();
		void RunThread(SDL_ThreadFunction method, void* param);
	private:
		ThreadManager();
		~ThreadManager();
		std::vector<SDL_Thread*> threads;
		static ThreadManager* _instance;
};

#endif