//DLL helper lib

#ifndef STDDLLHELPER
#define STDDLLHELPER 1
#include "stdmain.h"

#define IMPORT __declspec(dllimport)
#define EXPORT __declspec(dllexport)
#define CALL __cdecl

#ifdef __cplusplus
  #define EXT extern "C"
#else
  #define EXT extern
#endif

//Self explanatory
//Still need to include the headers tho :,(

#define DECLARE_MODULE_IMPORT(name, type, funcname, ...) EXT IMPORT type CALL _mod_##name##_##funcname(__VA_ARGS__)
#define DECLARE_MODULE_EXPORT(name, type, funcname, ...) EXT EXPORT type CALL _mod_##name##_##funcname(__VA_ARGS__)
#define DECLARE_MODULE(name, ...) DECLARE_MODULE_IMPORT(name, void, init, __VA_ARGS__)

#define IMPLEMENT_MODULE_IMPORT(name, type, funcname, ...) IMPORT type CALL _mod_##name##_##funcname(__VA_ARGS__)
#define IMPLEMENT_MODULE_EXPORT(name, type, funcname, ...) EXPORT type CALL _mod_##name##_##funcname(__VA_ARGS__)
#define IMPLEMENT_MODULE(name, ...) IMPLEMENT_MODULE_IMPORT(name, void, init, __VA_ARGS__)


#define INIT_MODULE(name, ...) _mod_##name##_init(__VA_ARGS__)
#define CALL_MODULE(name, funcname, ...) _mod_##name##_##funcname(__VA_ARGS__)
#endif