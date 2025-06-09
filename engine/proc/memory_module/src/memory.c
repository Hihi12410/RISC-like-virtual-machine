#include "..\inc\memory.h"

INTERRUPT _inter;
SHWM * self;

//Entrypoint
IMPLEMENT_MODULE(memory)
{
    self = malloc(sizeof(SHWM));
    if (self == NULL) 
    {
        perror("[ERROR] Error occured while loading memory module!");
        exit(EXIT_FAILURE);
    }
    fprintf(stdout, "[INFO] Memory module loaded.");
    return 0;
}