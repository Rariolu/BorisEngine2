#ifndef _EXTERNAL_RESOURCE_MANAGER_H
#define _EXTERNAL_RESOURCE_MANAGER_H

#include"Scene.h"
#include<map>

class ExternalResourceManager
{
	public:
	private:
		static std::map<int, Scene*> _scenes;
};

#endif