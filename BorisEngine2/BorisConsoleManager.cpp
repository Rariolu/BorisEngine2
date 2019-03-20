#include "BorisConsoleManager.h"

BorisConsoleManager* BorisConsoleManager::_instance = NULL;

BorisConsoleManager::BorisConsoleManager()
{

}

BorisConsoleManager::~BorisConsoleManager()
{

}

BorisConsoleManager* BorisConsoleManager::Instance()
{
	if (!_instance)
	{
		_instance = new BorisConsoleManager();
	}
	return _instance;
}

int BorisConsoleManager::print(void* data)
{
	//try
	//{
	//	char* m = (char*)data;
	//	cout << endl << m << endl;
	//}
	//catch (exception err)
	//{
	//	return -1;
	//}
	char* m = (char*)data;
	std::cout << std::endl << m << std::endl;
	return 0;
}

void BorisConsoleManager::Print(std::string text)
{
	Print((char*)BorisOperations::String_to_LPCSTR(text));
}

void BorisConsoleManager::Print(char* text)
{
	void* voir = (void*)(text);
	ThreadManager::GetInstance()->RunThread(&print, voir);
}

//void BorisConsoleManager::Print(std::stringstream* ss)
//{
//	std::string str;
//	*ss >> str;
//	Print(str);
//}