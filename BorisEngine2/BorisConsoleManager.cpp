#include "BorisConsoleManager.h"

BorisConsoleManager* BorisConsoleManager::_instance = NULL;
std::function<void(char*)> BorisConsoleManager::printFunction = NULL;

BorisConsoleManager* BorisConsoleManager::Instance()
{
	if (!_instance)
	{
		_instance = new BorisConsoleManager();
	}
	return _instance;
}

void BorisConsoleManager::Print(String text)
{
	Print((char*)BorisOperations::String_to_Str(text));
}

void BorisConsoleManager::Print(char* text)
{
	void* voir = (void*)(text);
	ThreadManager::GetInstance()->RunThread(&print, voir);
}

void BorisConsoleManager::SetPrintFunction(std::function<void(char*)> fn)
{
	printFunction = fn;
}

BorisConsoleManager::BorisConsoleManager()
{
	printFunction = COutPrint;
}

BorisConsoleManager::~BorisConsoleManager()
{

}

void BorisConsoleManager::COutPrint(char* c)
{
	std::cout << std::endl << c << std::endl;
}

int BorisConsoleManager::print(void* data)
{
	char* m = (char*)data;
	//printFunction(m);
	COutPrint(m);
	return 0;
}

//void BorisConsoleManager::Print(std::stringstream* ss)
//{
//	std::string str;
//	*ss >> str;
//	Print(str);
//}
