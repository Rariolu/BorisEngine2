#ifndef _ALIASES_H
#define _ALIASES_H

#include <iostream>
#include <vector>
#include <map>

//Class aliases

using String = std::string;
using StringStream = std::stringstream;

template<typename T>
using StdVec = std::vector<T>;

template<typename T, typename U>
using Dictionary = std::map<T, U>;

#endif