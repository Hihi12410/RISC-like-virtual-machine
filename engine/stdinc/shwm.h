//Simulated hardware module headers
//Includes
#ifndef SHWM_INC
#define SHWM_INC 1
#include "stdmain.h"
#include "stddllhelper.h"

//Interrupt convention
typedef struct 
{
    uint64_t code;
    uint64_t sender_guid;
    uint64_t dest_guid;
}
INTERRUPT; // --> 192 bits

//SHWM declaratiom
#define DECLARE_SHWM(name)                                                  \
    DECLARE_MODULE_IMPORT(name, void, int_hand, INTERRUPT inter);           \
    DECLARE_MODULE_IMPORT(name, void, p_flags, uint64_t flag);              \
    DECLARE_MODULE_EXPORT(name, INTERRUPT, r_int);                          \
    DECLARE_MODULE_EXPORT(name, uint64_t, r_flags);                      

//SHWM implementation
#define IMPLEMENT_SHWM_INT_HANDLER IMPLEMENT_MODULE_IMPORT(name, void, int_hand, INTERRUPT inter)
#define IMPLEMENT_SHWM_P_FLAGS IMPLEMENT_MODULE_IMPORT(name, void, p_flags, uint64_t flag)

//Pre-defined interrupt codes
#define INT_STOP            (uint64_t)0x0
#define INT_CLOCK           (uint64_t)0x1
#define INT_ERROR           (uint64_t)0x2
#define INT_DATA_PASS_FLAGS (uint64_t)0x3
#define INT_UNDEFINED       (uint64_t)0x4
#define INT_SUSPEND         (uint64_t)0x5
#define INT_SUSPEND_WAKE    (uint64_t)0x6

//Hardware module
//Defines every running module
typedef struct
{
    //GUID of module
    uint64_t GUID;
    //Is module running?
    bool running;
    //Flags to pass
    uint64_t * p_flags;
    //Flags to read
    uint64_t * r_flags;
    //Raise interrupt inside module
    void * raise_int;
    //Recieve interrupt from module
    void * recv_int;
} SHWM;

#endif