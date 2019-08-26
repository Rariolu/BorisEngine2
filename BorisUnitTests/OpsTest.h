#ifndef _OPS_TEST_H
#define _OPS_TEST_H

#include "BorisOperations.h"
#include <functional>

using test = std::function<bool()>;
using StrTestMap = std::map<String, test>;

double OpsRunAll();
bool CharToStr();
bool CharToLPCSTR();
bool GetDistance();
bool GetFloatRect();
bool GetSDLRect();
bool Lerp();

StrTestMap GetOps();
String BoolVal(bool b);

#endif