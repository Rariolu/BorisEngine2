#ifndef _OPS_TEST_H
#define _OPS_TEST_H

#include "BorisOperations.h"
#include <functional>

using test = std::function<bool()>;
using StrTestMap = std::map<String, test>;

double OpsRunAll();
bool CharToLPCSTR();
bool CharToStr();
bool CreateFolder();
bool GetDistance();
bool GetFloatRect();
bool GetSDLRect();
bool IntToLPCSTR();
bool IntToLPCSTRSingleDigit();
bool Lerp();
bool PadNumber();
bool RandomNumber();
bool Round();
bool Split();
bool Vec2Lerp();

String BoolVal(bool b);

#endif