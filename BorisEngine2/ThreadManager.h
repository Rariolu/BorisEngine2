#ifndef _THREAD_MANAGER_H
#define _THREAD_MANAGER_H

#ifdef __linux__
  #include <SDL2/SDL.h>
#else
  #include <SDL.h>
#endif

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
		StdVec<SDL_Thread*> threads;
		static ThreadManager* _instance;
};

#endif
