#ifndef _ALIASES_H
#define _ALIASES_H

#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <vector>

//Class aliases

template<typename T>
using queue = std::queue<T>;

template<typename T, typename U>
using Dictionary = std::map<T, U>;

template<typename T>
using list = std::list<T>;

using String = std::string;
using StringStream = std::stringstream;

template<typename T>
using StdVec = std::vector<T>;

#endif