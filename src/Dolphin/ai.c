#include "dolphin/types.h"

typedef s64 OSTime;
typedef struct OSContext
{
    u8 pad[0x2C8];
} OSContext;

typedef void (*AISCallback)(u32 count);
typedef void (*AIDCallback)(void);
typedef void (*__OSInterruptHandler)(u32 interrupt, OSContext* context);

extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL level);
extern void OSRegisterVersion(char* version);
extern void __OSSetInterruptHandler(u32 interrupt, __OSInterruptHandler handler);
extern u32 __OSUnmaskInterrupts(u32 mask);
extern void OSClearContext(OSContext* context);
extern void OSSetCurrentContext(OSContext* context);
extern OSTime OSGetTime(void);

extern char __AIVersionString[];

#define OS_BUS_CLOCK (*(u32*)0x800000F8)
#define OS_TIMER_CLOCK (OS_BUS_CLOCK / 4)
#define OSNanosecondsToTicks(nsec) (((nsec) * (OS_TIMER_CLOCK / 125000)) / 8000)

#define __AIRegs ((volatile u32*)0xCC006C00)
#define __DSPRegs ((volatile u16*)0xCC005000)

#define AI_STREAM_START 1
#define AI_STREAM_STOP 0
#define AI_SAMPLERATE_32KHZ 0
#define AI_SAMPLERATE_48KHZ 1

AIDCallback AIRegisterDMACallback(AIDCallback callback);
void AIInitDMA(u32 startAddr, u32 length);
void AIStartDMA(void);
void AIStopDMA(void);
void AISetStreamPlayState(u32 state);
u32 AIGetStreamPlayState(void);
void AISetDSPSampleRate(u32 rate);
u32 AIGetDSPSampleRate(void);
void __AI_set_stream_sample_rate(u32 rate);
u32 AIGetStreamSampleRate(void);
void AISetStreamVolLeft(u8 vol);
u8 AIGetStreamVolLeft(void);
void AISetStreamVolRight(u8 vol);
u8 AIGetStreamVolRight(void);
void AIInit(u8* stack);
void __AISHandler(u32 interrupt, OSContext* context);
void __AIDHandler(u32 interrupt, OSContext* context);
asm void __AICallbackStackSwitch(register void* cb);
void __AI_SRC_INIT(void);
AIDCallback __tmp_aid_callback(AIDCallback callback);

AIDCallback __AR_Callback;
OSTime lbl_805DDFF8;
OSTime lbl_805DDFF0;
OSTime lbl_805DDFE8;
OSTime lbl_805DDFE0;
OSTime lbl_805DDFD8;
BOOL lbl_805DDFD4;
BOOL lbl_805DDFD0;
u32 lbl_805DDFCC;
u8* lbl_805DDFC8;
AIDCallback lbl_805DDFC4;
AISCallback lbl_805DDFC0;

typedef struct
{
    char* version;
    u32 unused;
} AIVersionInfo;

AIVersionInfo __AIVersion = { __AIVersionString, 0 };

AIDCallback AIRegisterDMACallback(AIDCallback callback)
{
    AIDCallback old;
    BOOL enabled;

    old = lbl_805DDFC4;
    enabled = OSDisableInterrupts();
    lbl_805DDFC4 = callback;
    OSRestoreInterrupts(enabled);
    return old;
}

void AIInitDMA(u32 startAddr, u32 length)
{
    BOOL enabled;

    enabled = OSDisableInterrupts();
    __DSPRegs[24] = (__DSPRegs[24] & 0xFFFFFC00) | (startAddr >> 16);
    __DSPRegs[25] = (__DSPRegs[25] & 0xFFFF001F) | (startAddr & 0xFFFF);
    __DSPRegs[27] = (__DSPRegs[27] & 0xFFFF8000) | ((length >> 5) & 0xFFFF);
    OSRestoreInterrupts(enabled);
}

void AIStartDMA(void)
{
    __DSPRegs[27] = __DSPRegs[27] | 0x8000;
}

void AIStopDMA(void)
{
    __DSPRegs[27] = __DSPRegs[27] & ~0x8000;
}

void AISetStreamPlayState(u32 state)
{
    BOOL enabled;
    u8 vol_left;
    u8 vol_right;

    if (state != AIGetStreamPlayState())
    {
        if (AIGetStreamSampleRate() == 0 && state == AI_STREAM_START)
        {
            vol_left = AIGetStreamVolRight();
            vol_right = AIGetStreamVolLeft();
            AISetStreamVolRight(0);
            AISetStreamVolLeft(0);
            enabled = OSDisableInterrupts();
            __AI_SRC_INIT();
            __AIRegs[0] = (__AIRegs[0] & ~0x20) | 0x20;
            __AIRegs[0] = (__AIRegs[0] & ~1) | AI_STREAM_START;
            OSRestoreInterrupts(enabled);
            AISetStreamVolLeft(vol_left);
            AISetStreamVolRight(vol_right);
            return;
        }
        __AIRegs[0] = (__AIRegs[0] & ~1) | state;
    }
}

u32 AIGetStreamPlayState(void)
{
    return __AIRegs[0] & 1;
}

void AISetDSPSampleRate(u32 rate)
{
    BOOL enabled;
    u32 playState;
    u32 afrState;
    u8 vol_left;
    u8 vol_right;

    if (rate != AIGetDSPSampleRate())
    {
        __AIRegs[0] = __AIRegs[0] & 0xFFFFFFBF;
        if (rate == AI_SAMPLERATE_32KHZ)
        {
            vol_left = AIGetStreamVolLeft();
            vol_right = AIGetStreamVolRight();
            playState = AIGetStreamPlayState();
            afrState = AIGetStreamSampleRate();
            AISetStreamVolLeft(0U);
            AISetStreamVolRight(0U);
            enabled = OSDisableInterrupts();
            __AI_SRC_INIT();
            __AIRegs[0] = (__AIRegs[0] & ~0x20) | 0x20;
            __AIRegs[0] = (__AIRegs[0] & ~0x2) | (afrState << 1);
            __AIRegs[0] = (__AIRegs[0] & ~1) | playState;
            __AIRegs[0] |= 0x40;
            OSRestoreInterrupts(enabled);
            AISetStreamVolLeft(vol_left);
            AISetStreamVolRight(vol_right);
        }
    }
}

u32 AIGetDSPSampleRate(void)
{
    return ((__AIRegs[0] >> 6) & 1) ^ 1;
}

void __AI_set_stream_sample_rate(u32 rate)
{
    BOOL enabled;
    u32 playState;
    u8 vol_left;
    u8 vol_right;
    u32 dspSrcState;

    if (rate != AIGetStreamSampleRate())
    {
        playState = AIGetStreamPlayState();
        vol_left = AIGetStreamVolLeft();
        vol_right = AIGetStreamVolRight();
        AISetStreamVolRight(0);
        AISetStreamVolLeft(0);
        dspSrcState = __AIRegs[0] & 0x40;
        __AIRegs[0] = __AIRegs[0] & ~0x40;
        enabled = OSDisableInterrupts();
        __AI_SRC_INIT();
        __AIRegs[0] = __AIRegs[0] | dspSrcState;
        __AIRegs[0] = (__AIRegs[0] & ~0x20) | 0x20;
        __AIRegs[0] = (__AIRegs[0] & ~0x2) | (rate << 1);
        OSRestoreInterrupts(enabled);
        AISetStreamPlayState(playState);
        AISetStreamVolLeft(vol_left);
        AISetStreamVolRight(vol_right);
    }
}

u32 AIGetStreamSampleRate(void)
{
    return (__AIRegs[0] >> 1) & 1;
}

void AISetStreamVolLeft(u8 vol)
{
    __AIRegs[1] = (__AIRegs[1] & ~0xFF) | vol;
}

u8 AIGetStreamVolLeft(void)
{
    return __AIRegs[1] & 0xFF;
}

void AISetStreamVolRight(u8 vol)
{
    __AIRegs[1] = (__AIRegs[1] & ~0xFF00) | (vol << 8);
}

u8 AIGetStreamVolRight(void)
{
    return (__AIRegs[1] >> 8) & 0xFF;
}

void AIInit(u8* stack)
{
    if (lbl_805DDFD0 != TRUE)
    {
        u32 busClock;
        u32 ticksPer125k;

        OSRegisterVersion(__AIVersion.version);

        busClock = OS_BUS_CLOCK;
        ticksPer125k = (busClock / 4) / 125000;
        lbl_805DDFD8 = (31524 * ticksPer125k) / 8000;
        lbl_805DDFE0 = (42024 * ticksPer125k) / 8000;
        lbl_805DDFE8 = (42000 * ticksPer125k) / 8000;
        lbl_805DDFF0 = (63000 * ticksPer125k) / 8000;
        lbl_805DDFF8 = (3000 * ticksPer125k) / 8000;
        __AIRegs[0] = (__AIRegs[0] & ~0x20) | 0x20;
        AISetStreamVolRight(0);
        AISetStreamVolLeft(0);
        __AIRegs[3] = 0;
        __AI_set_stream_sample_rate(AI_SAMPLERATE_48KHZ);
        AISetDSPSampleRate(AI_SAMPLERATE_32KHZ);
        lbl_805DDFC0 = NULL;
        lbl_805DDFC4 = NULL;
        lbl_805DDFC8 = stack;
        __OSSetInterruptHandler(5, __AIDHandler);
        __OSUnmaskInterrupts(0x04000000);
        __OSSetInterruptHandler(8, __AISHandler);
        __OSUnmaskInterrupts(0x800000);
        lbl_805DDFD0 = TRUE;
    }
}

void __AISHandler(u32 interrupt, OSContext* context)
{
    OSContext exceptionContext;

    __AIRegs[0] |= 8;
    OSClearContext(&exceptionContext);
    OSSetCurrentContext(&exceptionContext);
    if (lbl_805DDFC0)
    {
        lbl_805DDFC0(__AIRegs[2]);
    }
    OSClearContext(&exceptionContext);
    OSSetCurrentContext(context);
}

void __AIDHandler(u32 interrupt, OSContext* context)
{
    OSContext exceptionContext;
    u16 tmp;

    tmp = __DSPRegs[5];
    tmp = (tmp & ~0xA0) | 8;
    __DSPRegs[5] = tmp;
    OSClearContext(&exceptionContext);
    OSSetCurrentContext(&exceptionContext);
    if (lbl_805DDFC4 && !lbl_805DDFD4)
    {
        lbl_805DDFD4 = TRUE;
        if (lbl_805DDFC8)
        {
            __AICallbackStackSwitch(lbl_805DDFC4);
        }
        else
        {
            lbl_805DDFC4();
        }
        lbl_805DDFD4 = FALSE;
    }
    OSClearContext(&exceptionContext);
    OSSetCurrentContext(context);
}

asm void __AICallbackStackSwitch(register void* cb)
{
    nofralloc
    mflr r0
    stw r0, 0x4(r1)
    stwu r1, -0x18(r1)
    stw r31, 0x14(r1)
    mr r31, r3
    lis r5, lbl_805DDFCC@ha
    addi r5, r5, lbl_805DDFCC@l
    stw r1, 0x0(r5)
    lis r5, lbl_805DDFC8@ha
    addi r5, r5, lbl_805DDFC8@l
    lwz r1, 0x0(r5)
    subi r1, r1, 0x8
    mtlr r31
    blrl
    lis r5, lbl_805DDFCC@ha
    addi r5, r5, lbl_805DDFCC@l
    lwz r1, 0x0(r5)
    lwz r0, 0x1c(r1)
    lwz r31, 0x14(r1)
    addi r1, r1, 0x18
    mtlr r0
    blr
}

void __AI_SRC_INIT(void)
{
    OSTime rising32khz = 0;
    OSTime rising48khz = 0;
    OSTime diff = 0;
    OSTime temp = 0;
    u32 temp0;
    u32 temp1;
    u32 done = 0;

    while (!done)
    {
        __AIRegs[0] = (__AIRegs[0] & ~0x20) | 0x20;
        __AIRegs[0] = (__AIRegs[0] & ~0x2) | 0;
        __AIRegs[0] = (__AIRegs[0] & ~1) | AI_STREAM_START;
        temp0 = __AIRegs[2];
        while (temp0 == __AIRegs[2])
        {
        }
        rising32khz = OSGetTime();
        __AIRegs[0] = (__AIRegs[0] & ~0x2) | 0x2;
        __AIRegs[0] = (__AIRegs[0] & ~1) | AI_STREAM_START;
        temp1 = __AIRegs[2];
        while (temp1 == __AIRegs[2])
        {
        }
        rising48khz = OSGetTime();
        diff = rising48khz - rising32khz;
        __AIRegs[0] = (__AIRegs[0] & ~0x2) | 0;
        __AIRegs[0] = (__AIRegs[0] & ~1) | AI_STREAM_STOP;
        if (diff < lbl_805DDFD8 - lbl_805DDFF8)
        {
            temp = lbl_805DDFE8;
            done = 1;
        }
        else if (diff >= lbl_805DDFD8 + lbl_805DDFF8 && diff < lbl_805DDFE0 - lbl_805DDFF8)
        {
            temp = lbl_805DDFF0;
            done = 1;
        }
        else
        {
            done = 0;
        }
    }
    while (rising48khz + temp > OSGetTime())
    {
    }
}

AIDCallback __tmp_aid_callback(AIDCallback callback)
{
    AIDCallback old;
    BOOL enabled;

    old = __AR_Callback;
    enabled = OSDisableInterrupts();
    __AR_Callback = callback;
    OSRestoreInterrupts(enabled);
    return old;
}
