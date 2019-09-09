#ifndef _BorisConsoleManager_H
#define _BorisConsoleManager_H

#include "ThreadManager.h"
#include <functional>

class BorisConsoleManager
{
	public:
		static BorisConsoleManager* Instance();
		void Print(String text);
		void Print(char* text);
		void SetPrintFunction(std::function<void(char*)> fn);
		//void Print(std::stringstream* ss);
	private:
		BorisConsoleManager();
		~BorisConsoleManager();
		static void COutPrint(char* c);
		static BorisConsoleManager* _instance;
		static int print(void* data);
		static std::function<void(char*)> printFunction;
};

#endif