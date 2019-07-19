#ifndef _FONTMANAGER_H
#define _FONTMANAGER_H

#include<iostream>
#include<map>
#include"Font.h"

//Create a class used to store pointers to instances of "Font" so that they can be easily accessed when necessary.
class FontManager
{
	public:
		//A method which returns a pointer to the only instance of this class.
		static FontManager* GetInstance();
		//Destructor method.
		~FontManager();
		//Add a pointer to a "Font" instance with a std::string which can later be used to reference it.
		void AddFont(String fontname, Font* font);
		//Give a std::string which representing a pointer to a "Font" instance to be returned.
		Font* GetFont(String fontname);
	private:
		//Constructor method, private so that an instance can't be created outside of this class.
		FontManager();
		//A pointer to the only instance of this class.
		static FontManager* _instance;
		//A map using std::strings as keys and "Font" pointers as values.
		std::map<String, Font*> fonts;
		static BorisConsoleManager* BorisConsoleManager;
};

#endif