//Simulated hardware module headers
//Includes
#ifndef SHWM_INC
#define SHWM_INC 1
#include "stdmain.h"
#include "stddllhelper.h"
#include "stdoutput.h"

//Interrupt convention
typedef struct 
{
    uint64_t code;
    uint64_t sender_guid;
    uint64_t dest_guid;
}
INTERRUPT; // --> 192 bits

//Hardware module
//Defines every running module
typedef struct
{
    //Name of the module
    char name[256];
    //GUID of module
    uint64_t GUID;
    //Is module running?
    bool running;
    //Flag
    uint64_t flag;
} SHWM;


//SHWM declaration
#define DECLARE_SHWM(name)                                                      \
    DECLARE_MODULE_EXPORT(name, void, h_int, INTERRUPT inter);                  \
    DECLARE_MODULE_IMPORT(shwm, void, w_flag, uint64_t w_flag);                 \
    DECLARE_MODULE_IMPORT(shwm, uint64_t, r_flag, uint64_t guid);               \
    DECLARE_MODULE_IMPORT(shwm, void, r_int, INTERRUPT inter);                  \
    DECLARE_MODULE_IMPORT(shwm, SHWM *, register_mod);                          \
    DECLARE_MODULE_IMPORT(shwm, void, unregister_mod, SHWM * self);             \
    DECLARE_MODULE_IMPORT(shwm, void, querry_guid, char * name);                \

#define IMPLEMENT_SHWM(name) IMPLEMENT_MODULE_EXPORT(name, void, h_int, INTERRUPT inter)

DECLARE_MODULE_EXPORT(shwm, void, w_flag, uint64_t w_flag);
DECLARE_MODULE_EXPORT(shwm, uint64_t, r_flag, uint64_t guid);
DECLARE_MODULE_EXPORT(shwm, void, r_int, INTERRUPT inter);
DECLARE_MODULE_EXPORT(shwm, SHWM *, register_mod);
DECLARE_MODULE_EXPORT(shwm, void, unregister_mod, SHWM * self);
DECLARE_MODULE_EXPORT(shwm, void, querry_guid, char * name);


//Pre-defined interrupt codes
#define INT_STOP            (uint64_t)0x0
#define INT_ERROR           (uint64_t)0x1
#define INT_DATA_PASS_FLAG  (uint64_t)0x2
#define INT_UNDEFINED       (uint64_t)0x3
#define INT_SUSPEND         (uint64_t)0x4
#define INT_SUSPEND_WAKE    (uint64_t)0x5

#endif