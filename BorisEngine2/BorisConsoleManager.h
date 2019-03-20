#ifndef _BorisConsoleManager_H
#define _BorisConsoleManager_H

#include "ThreadManager.h"

class BorisConsoleManager
{
public:
	static BorisConsoleManager* Instance();
	void Print(std::string text);
	void Print(char* text);
	//void Print(std::stringstream* ss);
private:
	BorisConsoleManager();
	~BorisConsoleManager();
	static BorisConsoleManager* _instance;
	static int print(void* data);
};

#endif