//To check if code is being compiled on x64 targets.
//If not, prematurely stop compilation.

#ifndef X64CHECK
#define X64CHECK 1
#include "stdmain.h"
static_assert(sizeof(void*) == 8, "This code requires a 64-bit platform");
#endif