#ifndef _TESTS_H
#define _TESTS_H

#include "BorisOperations.h"
#include <functional>

using test = std::function<bool()>;
using StrTestMap = std::map<String, test>;

double RunTests(StrTestMap tests);

#endif