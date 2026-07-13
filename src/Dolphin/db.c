#include "dolphin/db.h"
#include "dolphin/os.h"
#include "dolphin/ppcarch.h"
#include "functions.h"

typedef struct DBInterface
{
    u32 present;
    u32 exceptionMask;
} DBInterface;

u32 DBVerbose;
DBInterface* __DBInterface;

char DBExceptionDestinationString[] = "DBExceptionDestination\n";

asm void __DBExceptionDestinationAux(void);
asm void __DBExceptionDestination(void);

void DBInit(void)
{
    __DBInterface = (DBInterface*)0x80000040;
    *(u32*)0x80000048 = (u32)__DBExceptionDestination + 0x80000000;
    DBVerbose = 1;
}

BOOL DBIsDebuggerPresent(void)
{
    if (__DBInterface == 0)
        return 0;
    return __DBInterface->present;
}

asm void __DBExceptionDestinationAux(void)
{
    nofralloc
    mflr r0
    lis r3, DBExceptionDestinationString@ha
    stw r0, 0x4(r1)
    addi r3, r3, DBExceptionDestinationString@l
    crclr 6
    stwu r1, -0x18(r1)
    stw r31, 0x14(r1)
    lwz r4, 0xc0(r0)
    addis r31, r4, 0x8000
    bl OSReport
    mr r3, r31
    bl OSDumpContext
    bl PPCHalt
    lwz r0, 0x1c(r1)
    lwz r31, 0x14(r1)
    addi r1, r1, 0x18
    mtlr r0
    blr
}

asm void __DBExceptionDestination(void)
{
    nofralloc
    mfmsr r3
    ori r3, r3, 0x30
    mtmsr r3
    b __DBExceptionDestinationAux
}

BOOL __DBIsExceptionMarked(u8 exception)
{
    return __DBInterface->exceptionMask & (1 << exception);
}

void DBPrintf(char* msg, ...)
{
}
