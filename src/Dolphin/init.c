#include "dolphin/types.h"
#include "dolphin/ppcarch.h"

extern void (*_ctors[])(void);

static void __init_cpp(void);

void __init_user(void)
{
    __init_cpp();
}

#pragma dont_inline on
#pragma scheduling off
static void __init_cpp(void)
{
    void (**pctor)(void);

    for (pctor = _ctors; *pctor; pctor++)
    {
        (*pctor)();
    }
}
#pragma scheduling reset
#pragma dont_inline reset

void _ExitProcess(void)
{
    PPCHalt();
}
