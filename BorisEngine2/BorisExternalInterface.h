#ifndef _EXTERNAL_INTERFACE_H
#define _EXTERNAL_INTERFACE_H

#ifdef EXTERN_TEMPLATES
#define EXTERN_TEMPLATE __declspec(dllexport)
#else
#define EXTERN_TEMPLATE __declspec(dllimport)
#endif

#include<iostream>

extern "C"
{
	//EXTERN_TEMPLATE void 
}

#endif // !1