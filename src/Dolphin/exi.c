#include "dolphin/types.h"

typedef s64 OSTime;
typedef s16 __OSInterrupt;

typedef struct OSContext
{
    u8 data[0x2C8];
} OSContext;

typedef void (*EXICallback)(s32 chan, OSContext* context);
typedef void (*__OSInterruptHandler)(__OSInterrupt interrupt, OSContext* context);

typedef struct EXIControl
{
    EXICallback exiCallback;
    EXICallback tcCallback;
    EXICallback extCallback;
    vu32 state;
    int immLen;
    u8* immBuf;
    u32 dev;
    u32 id;
    s32 idTime;
    int items;
    struct
    {
        u32 dev;
        EXICallback callback;
    } queue[3];
} EXIControl;

extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL level);
extern OSTime OSGetTime(void);
extern void __OSMaskInterrupts(u32 mask);
extern u32 __OSUnmaskInterrupts(u32 mask);
extern __OSInterruptHandler __OSSetInterruptHandler(__OSInterrupt interrupt, __OSInterruptHandler handler);
extern __OSInterruptHandler __OSGetInterruptHandler(__OSInterrupt interrupt);
extern void OSRegisterVersion(char* version);
extern u32 __OSGetDIConfig(void);
extern u32 OSGetConsoleType(void);
extern void OSClearContext(OSContext* context);
extern void OSSetCurrentContext(OSContext* context);
extern void* memmove(void* dst, const void* src, u32 n);
extern BOOL __OSInIPL;

extern const char __EXIVersionString[];

#define REG_MAX 5
#define REG(chan, idx) (__EXIRegs[((chan) * REG_MAX) + (idx)])
#define __EXIRegs ((vu32*)0xCC006800)

#define STATE_DMA      1
#define STATE_IMM      2
#define STATE_BUSY     3
#define STATE_SELECTED 4
#define STATE_ATTACHED 8
#define STATE_LOCKED   16

#define EXI_0LENGTH_EXILENGTH_MASK 0x03FFFFE0

#define EXI_READ  0
#define EXI_WRITE 1
#define EXI_FREQ_1M 0
#define EXI_FREQ_8M 3

#define OS_BUS_CLOCK (*(vu32*)0x800000F8)
#define OS_TIMER_CLOCK (OS_BUS_CLOCK / 4)
#define OSTicksToMilliseconds(ticks) ((ticks) / (OS_TIMER_CLOCK / 1000))

#define __gUnknown800030C0 ((s32*)0x800030C0)
#define __OSDeviceCode (*(vu16*)0x800030E6)

u32 EXIClearInterrupts(s32 chan, int exi, int tc, int ext);
int EXISync(s32 chan);
s32 EXIGetID(s32 chan, u32 dev, u32* id);
void __OSEnableBarnacle(s32 chan, u32 dev);

static EXIControl Ecb[3];

u32 __EXIProbeBarnacleMagic;
u32 __EXIUartStatus;
u32 __EXIUartDevice;
s32 __EXIUartChannel;
u32 __EXISbssPadding;
static u32 IDSerialPort1;

char* __EXIVersion = (char*)__EXIVersionString;
vu32 __EXISdataPadding = 0;

static void SetExiInterruptMask(s32 chan, EXIControl* exi)
{
    EXIControl* exi2 = &Ecb[2];

    switch (chan)
    {
    case 0:
        if ((exi->exiCallback == 0 && exi2->exiCallback == 0) || (exi->state & STATE_LOCKED))
        {
            __OSMaskInterrupts(0x410000U);
        }
        else
        {
            __OSUnmaskInterrupts(0x410000U);
        }
        break;
    case 1:
        if (exi->exiCallback == 0 || (exi->state & STATE_LOCKED))
        {
            __OSMaskInterrupts(0x80000U);
        }
        else
        {
            __OSUnmaskInterrupts(0x80000U);
        }
        break;
    case 2:
        if (__OSGetInterruptHandler(0x19) == 0 || (exi->state & STATE_LOCKED))
        {
            __OSMaskInterrupts(0x40U);
        }
        else
        {
            __OSUnmaskInterrupts(0x40U);
        }
        break;
    }
}

#pragma dont_inline on
int EXIImm(s32 chan, void* buf, s32 len, u32 type, EXICallback callback)
{
    EXIControl* exi = &Ecb[chan];
    BOOL enabled;
    u32 data;
    int i;

    enabled = OSDisableInterrupts();

    if ((exi->state & STATE_BUSY) || !(exi->state & STATE_SELECTED))
    {
        OSRestoreInterrupts(enabled);
        return 0;
    }

    exi->tcCallback = callback;
    if (exi->tcCallback)
    {
        EXIClearInterrupts(chan, 0, 1, 0);
        __OSUnmaskInterrupts(0x200000U >> (chan * 3));
    }

    exi->state |= STATE_IMM;
    if (type != 0)
    {
        data = 0;
        for (i = 0; i < len; i++)
        {
            data |= ((u8*)buf)[i] << ((3 - i) * 8);
        }
        __EXIRegs[(chan * 5) + 4] = data;
    }

    exi->immBuf = buf;
    exi->immLen = (type != 1) ? len : 0;
    __EXIRegs[(chan * 5) + 3] = (type << 2) | 1 | ((len - 1) << 4);
    OSRestoreInterrupts(enabled);
    return 1;
}
#pragma dont_inline off

#pragma dont_inline on
int EXIImmEx(s32 chan, void* buf, s32 len, u32 mode)
{
    s32 xLen;

    while (len)
    {
        xLen = (len < 4) ? len : 4;
        if (EXIImm(chan, buf, xLen, mode, 0) == 0)
        {
            return 0;
        }
        if (EXISync(chan) == 0)
        {
            return 0;
        }
        (u8*)buf += xLen;
        len -= xLen;
    }

    return 1;
}
#pragma dont_inline off

#pragma dont_inline on
int EXIDma(s32 chan, void* buf, s32 len, u32 type, EXICallback callback)
{
    EXIControl* exi = &Ecb[chan];
    BOOL enabled;

    enabled = OSDisableInterrupts();
    if ((exi->state & STATE_BUSY) || !(exi->state & STATE_SELECTED))
    {
        OSRestoreInterrupts(enabled);
        return 0;
    }

    exi->tcCallback = callback;
    if ((u32)exi->tcCallback)
    {
        EXIClearInterrupts(chan, 0, 1, 0);
        __OSUnmaskInterrupts(0x200000U >> (chan * 3));
    }

    exi->state |= STATE_DMA;
    __EXIRegs[(chan * 5) + 1] = (u32)buf & EXI_0LENGTH_EXILENGTH_MASK;
    __EXIRegs[(chan * 5) + 2] = len;
    __EXIRegs[(chan * 5) + 3] = (type * 4) | 3;

    OSRestoreInterrupts(enabled);
    return 1;
}
#pragma dont_inline off

static inline void CompleteTransfer(s32 chan)
{
    EXIControl* exi = &Ecb[chan];
    u8* buf;
    u32 data;
    int i;
    int len;

    if (exi->state & STATE_BUSY)
    {
        if (exi->state & STATE_IMM)
        {
            if ((len = exi->immLen) != 0)
            {
                buf = exi->immBuf;
                data = __EXIRegs[(chan * 5) + 4];
                for (i = 0; i < len; i++)
                {
                    *buf++ = data >> ((3 - i) * 8);
                }
            }
        }
        exi->state &= ~STATE_BUSY;
    }
}

int EXISync(s32 chan)
{
    EXIControl* exi = &Ecb[chan];
    int rc = 0;
    BOOL enabled;

    while ((exi->state & STATE_SELECTED))
    {
        if (!(__EXIRegs[(chan * 5) + 3] & 1))
        {
            enabled = OSDisableInterrupts();
            if (exi->state & STATE_SELECTED)
            {
                CompleteTransfer(chan);
                if (__OSGetDIConfig() != 0xFF || (OSGetConsoleType() & 0xf0000000) == 0x20000000 ||
                    exi->immLen != 4 || (__EXIRegs[chan * 5] & 0x70) ||
                    (__EXIRegs[(chan * 5) + 4] != 0x01010000 && __EXIRegs[(chan * 5) + 4] != 0x05070000 &&
                     __EXIRegs[(chan * 5) + 4] != 0x04220001) ||
                    __OSDeviceCode == 0x8200)
                {
                    rc = 1;
                }
            }
            OSRestoreInterrupts(enabled);
            break;
        }
    }

    return rc;
}

u32 EXIClearInterrupts(s32 chan, int exi, int tc, int ext)
{
    u32 cpr;
    u32 prev;

    cpr = __EXIRegs[(chan * 5)];
    prev = cpr & 0x7F5;

    if (exi != 0)
    {
        prev |= 2;
    }

    if (tc != 0)
    {
        prev |= 8;
    }

    if (ext != 0)
    {
        prev |= 0x800;
    }

    __EXIRegs[(chan * 5)] = prev;
    return cpr;
}

#pragma dont_inline on
EXICallback EXISetExiCallback(s32 chan, EXICallback exiCallback)
{
    EXIControl* exi = &Ecb[chan];
    EXICallback prev;
    BOOL enabled;

    enabled = OSDisableInterrupts();

    prev = exi->exiCallback;
    exi->exiCallback = exiCallback;
    if (chan != 2)
    {
        SetExiInterruptMask(chan, exi);
    }
    else
    {
        SetExiInterruptMask(0, &Ecb[0]);
    }

    OSRestoreInterrupts(enabled);
    return prev;
}
#pragma dont_inline off

static int __EXIProbe(s32 chan)
{
    EXIControl* exi = &Ecb[chan];
    BOOL enabled;
    int rc;
    u32 cpr;
    s32 t;

    if (chan == 2)
    {
        return 1;
    }

    rc = 1;
    enabled = OSDisableInterrupts();
    cpr = __EXIRegs[(chan * 5)];

    if (!(exi->state & STATE_ATTACHED))
    {
        if (cpr & 0x800)
        {
            EXIClearInterrupts(chan, 0, 0, 1);
            __gUnknown800030C0[chan] = exi->idTime = 0;
        }

        if (cpr & 0x1000)
        {
            t = ((s32)(OSTicksToMilliseconds(OSGetTime()) / 100) + 1);

            if (__gUnknown800030C0[chan] == 0)
            {
                __gUnknown800030C0[chan] = t;
            }

            if (t - (s32)__gUnknown800030C0[chan] < 3)
            {
                rc = 0;
            }
        }
        else
        {
            __gUnknown800030C0[chan] = exi->idTime = 0;
            rc = 0;
        }
    }
    else if (!(cpr & 0x1000) || (cpr & 0x800))
    {
        __gUnknown800030C0[chan] = exi->idTime = 0;
        rc = 0;
    }

    OSRestoreInterrupts(enabled);
    return rc;
}

#pragma dont_inline on
int EXIProbe(s32 chan)
{
    EXIControl* exi = &Ecb[chan];
    int rc;
    u32 id;

    rc = __EXIProbe(chan);
    if (rc && !exi->idTime)
    {
        rc = EXIGetID(chan, 0, &id) ? 1 : 0;
    }

    return rc;
}
#pragma dont_inline off

#pragma dont_inline on
s32 EXIProbeEx(s32 chan)
{
    EXIControl* exi = &Ecb[chan];
    int rc;
    u32 id;

    rc = __EXIProbe(chan);
    if (rc && !exi->idTime)
    {
        rc = EXIGetID(chan, 0, &id) ? 1 : 0;
    }

    if (rc)
    {
        return 1;
    }

    if (__gUnknown800030C0[chan])
    {
        return 0;
    }

    return -1;
}
#pragma dont_inline off

inline int __EXIAttach(s32 chan, EXICallback extCallback)
{
    EXIControl* exi = &Ecb[chan];
    BOOL enabled;

    enabled = OSDisableInterrupts();

    if ((exi->state & STATE_ATTACHED) || !__EXIProbe(chan))
    {
        OSRestoreInterrupts(enabled);
        return 0;
    }

    EXIClearInterrupts(chan, 1, 0, 0);
    exi->extCallback = extCallback;
    __OSUnmaskInterrupts(0x100000U >> (chan * 3));
    exi->state |= STATE_ATTACHED;

    OSRestoreInterrupts(enabled);
    return 1;
}

int EXIAttach(s32 chan, EXICallback extCallback)
{
    EXIControl* exi = &Ecb[chan];
    BOOL enabled;
    int rc;
    int probeRc;
    u32 id;

    probeRc = __EXIProbe(chan);
    if (probeRc && !exi->idTime)
    {
        EXIGetID(chan, 0, &id);
    }

    enabled = OSDisableInterrupts();
    if (exi->idTime == 0)
    {
        OSRestoreInterrupts(enabled);
        return 0;
    }

    rc = __EXIAttach(chan, extCallback);
    OSRestoreInterrupts(enabled);
    return rc;
}

#pragma dont_inline on
int EXIDetach(s32 chan)
{
    EXIControl* exi = &Ecb[chan];
    BOOL enabled;

    enabled = OSDisableInterrupts();

    if (!(exi->state & STATE_ATTACHED))
    {
        OSRestoreInterrupts(enabled);
        return 1;
    }

    if ((exi->state & STATE_LOCKED) && (exi->dev == 0))
    {
        OSRestoreInterrupts(enabled);
        return 0;
    }

    exi->state &= ~STATE_ATTACHED;
    __OSMaskInterrupts(0x500000U >> (chan * 3));

    OSRestoreInterrupts(enabled);
    return 1;
}
#pragma dont_inline off

#pragma dont_inline on
int EXISelect(s32 chan, u32 dev, u32 freq)
{
    EXIControl* exi = &Ecb[chan];
    u32 cpr;
    BOOL enabled;

    enabled = OSDisableInterrupts();
    if ((exi->state & STATE_SELECTED) ||
        ((chan != 2) &&
         (((dev == 0) && !(exi->state & STATE_ATTACHED) && (__EXIProbe(chan) == 0)) ||
          !(exi->state & STATE_LOCKED) || (exi->dev != dev))))
    {
        OSRestoreInterrupts(enabled);
        return 0;
    }

    exi->state |= STATE_SELECTED;
    cpr = __EXIRegs[(chan * 5)];
    cpr &= 0x405;
    cpr |= (((1 << dev) << 7) | (freq * 0x10));
    __EXIRegs[(chan * 5)] = cpr;

    if (exi->state & STATE_ATTACHED)
    {
        switch (chan)
        {
        case 0:
            __OSMaskInterrupts(0x100000U);
            break;
        case 1:
            __OSMaskInterrupts(0x20000U);
            break;
        }
    }

    OSRestoreInterrupts(enabled);
    return 1;
}
#pragma dont_inline off

#pragma dont_inline on
int EXIDeselect(s32 chan)
{
    EXIControl* exi = &Ecb[chan];
    u32 cpr;
    BOOL enabled;

    enabled = OSDisableInterrupts();

    if (!(exi->state & STATE_SELECTED))
    {
        OSRestoreInterrupts(enabled);
        return 0;
    }

    exi->state &= ~STATE_SELECTED;
    cpr = __EXIRegs[(chan * 5)];
    __EXIRegs[(chan * 5)] = cpr & 0x405;

    if (exi->state & STATE_ATTACHED)
    {
        switch (chan)
        {
        case 0:
            __OSUnmaskInterrupts(0x100000U);
            break;
        case 1:
            __OSUnmaskInterrupts(0x20000U);
            break;
        }
    }

    OSRestoreInterrupts(enabled);

    if ((chan != 2) && (cpr & 0x80))
    {
        if (__EXIProbe(chan) != 0)
        {
            return 1;
        }
        return 0;
    }

    return 1;
}
#pragma dont_inline off

static void EXIIntrruptHandler(__OSInterrupt interrupt, OSContext* context)
{
    s32 chan = (interrupt - 9) / 3;
    EXIControl* exi = &Ecb[chan];
    EXICallback callback;

    EXIClearInterrupts(chan, 1, 0, 0);

    callback = exi->exiCallback;
    if (callback)
    {
        OSContext exceptionContext;

        OSClearContext(&exceptionContext);
        OSSetCurrentContext(&exceptionContext);
        callback(chan, context);
        OSClearContext(&exceptionContext);
        OSSetCurrentContext(context);
    }
}

static void TCIntrruptHandler(__OSInterrupt interrupt, OSContext* context)
{
    s32 chan = (interrupt - 10) / 3;
    EXIControl* exi = &Ecb[chan];
    EXICallback callback;

    __OSMaskInterrupts(0x80000000U >> interrupt);
    EXIClearInterrupts(chan, 0, 1, 0);

    callback = exi->tcCallback;
    if (callback)
    {
        OSContext exceptionContext;

        exi->tcCallback = NULL;
        CompleteTransfer(chan);

        OSClearContext(&exceptionContext);
        OSSetCurrentContext(&exceptionContext);
        callback(chan, context);
        OSClearContext(&exceptionContext);
        OSSetCurrentContext(context);
    }
}

static void EXTIntrruptHandler(__OSInterrupt interrupt, OSContext* context)
{
    s32 chan = (interrupt - 11) / 3;
    EXIControl* exi;
    EXICallback callback;

    __OSMaskInterrupts(0x500000U >> (chan * 3));
    exi = &Ecb[chan];
    callback = exi->extCallback;
    exi->state &= ~STATE_ATTACHED;

    if (callback)
    {
        OSContext exceptionContext;

        OSClearContext(&exceptionContext);
        OSSetCurrentContext(&exceptionContext);
        exi->extCallback = NULL;
        callback(chan, context);
        OSClearContext(&exceptionContext);
        OSSetCurrentContext(context);
    }
}

#pragma dont_inline on
void EXIInit(void)
{
    u32 id;

    while (((REG(0, 3) & 1) == 1) || ((REG(1, 3) & 1) == 1) || ((REG(2, 3) & 1) == 1))
    {
    }

    __OSMaskInterrupts(0x7F8000U);
    __EXIRegs[0] = 0;
    __EXIRegs[5] = 0;
    __EXIRegs[10] = 0;
    __EXIRegs[0] = 0x2000;
    __OSSetInterruptHandler(9, EXIIntrruptHandler);
    __OSSetInterruptHandler(10, TCIntrruptHandler);
    __OSSetInterruptHandler(11, EXTIntrruptHandler);
    __OSSetInterruptHandler(12, EXIIntrruptHandler);
    __OSSetInterruptHandler(13, TCIntrruptHandler);
    __OSSetInterruptHandler(14, EXTIntrruptHandler);
    __OSSetInterruptHandler(15, EXIIntrruptHandler);
    __OSSetInterruptHandler(16, TCIntrruptHandler);

    EXIGetID(0, 2, &IDSerialPort1);

    if (__OSInIPL)
    {
        __gUnknown800030C0[0] = __gUnknown800030C0[1] = 0;
        Ecb[0].idTime = Ecb[1].idTime = 0;
        __EXIProbe(0);
        __EXIProbe(1);
    }
    else if (EXIGetID(0, 0, &id) && id == 0x7010000)
    {
        __OSEnableBarnacle(1, 0);
    }
    else if (EXIGetID(1, 0, &id) && id == 0x7010000)
    {
        __OSEnableBarnacle(0, 2);
    }

    OSRegisterVersion(__EXIVersion);
}
#pragma dont_inline off

#pragma dont_inline on
int EXILock(s32 chan, u32 dev, EXICallback unlockedCallback)
{
    EXIControl* exi = &Ecb[chan];
    BOOL enabled;
    int i;

    enabled = OSDisableInterrupts();

    if (exi->state & STATE_LOCKED)
    {
        if (unlockedCallback)
        {
            for (i = 0; i < exi->items; i++)
            {
                if (exi->queue[i].dev == dev)
                {
                    OSRestoreInterrupts(enabled);
                    return 0;
                }
            }
            exi->queue[exi->items].callback = unlockedCallback;
            exi->queue[exi->items].dev = dev;
            exi->items++;
        }
        OSRestoreInterrupts(enabled);
        return 0;
    }

    exi->state |= STATE_LOCKED;
    exi->dev = dev;
    SetExiInterruptMask(chan, exi);
    OSRestoreInterrupts(enabled);
    return 1;
}
#pragma dont_inline off

#pragma dont_inline on
int EXIUnlock(s32 chan)
{
    EXIControl* exi = &Ecb[chan];
    BOOL enabled;
    EXICallback unlockedCallback;

    enabled = OSDisableInterrupts();

    if (!(exi->state & STATE_LOCKED))
    {
        OSRestoreInterrupts(enabled);
        return 0;
    }

    exi->state &= ~STATE_LOCKED;
    SetExiInterruptMask(chan, exi);
    if (exi->items > 0)
    {
        unlockedCallback = exi->queue[0].callback;
        if (--exi->items > 0)
        {
            memmove(&exi->queue[0], &exi->queue[1], exi->items * 8);
        }
        unlockedCallback(chan, 0);
    }

    OSRestoreInterrupts(enabled);
    return 1;
}
#pragma dont_inline off

#pragma dont_inline on
u32 EXIGetState(s32 chan)
{
    EXIControl* exi = &Ecb[chan];
    return exi->state;
}
#pragma dont_inline off

static void UnlockedHandler(s32 chan, OSContext* context)
{
    u32 id;
    EXIGetID(chan, 0, &id);
}

s32 EXIGetID(s32 chan, u32 dev, u32* id)
{
    EXIControl* exi = &Ecb[chan];
    int err;
    u32 cmd;
    s32 startTime;
    BOOL enabled;

    if (chan == 0 && dev == 2 && IDSerialPort1 != 0)
    {
        *id = IDSerialPort1;
        return 1;
    }

    if ((chan < 2) && (dev == 0))
    {
        if ((__EXIProbe(chan) == 0))
        {
            return 0;
        }

        if (exi->idTime == __gUnknown800030C0[chan])
        {
            *id = exi->id;
            return exi->idTime;
        }

        if (!__EXIAttach(chan, NULL))
        {
            return 0;
        }

        startTime = __gUnknown800030C0[chan];
    }

    enabled = OSDisableInterrupts();

    err = !EXILock(chan, dev, (chan < 2 && dev == 0) ? &UnlockedHandler : NULL);
    if (err == 0)
    {
        err = !EXISelect(chan, dev, 0);
        if (err == 0)
        {
            cmd = 0;
            err |= !EXIImm(chan, &cmd, 2, 1, 0);
            err |= !EXISync(chan);
            err |= !EXIImm(chan, id, 4, 0, 0);
            err |= !EXISync(chan);
            err |= !EXIDeselect(chan);
        }

        EXIUnlock(chan);
    }

    OSRestoreInterrupts(enabled);

    if ((chan < 2) && (dev == 0))
    {
        EXIDetach(chan);
        enabled = OSDisableInterrupts();
        err |= __gUnknown800030C0[chan] != startTime;

        if (!err)
        {
            exi->id = *id;
            exi->idTime = startTime;
        }

        OSRestoreInterrupts(enabled);

        if (err)
        {
            return 0;
        }

        return exi->idTime;
    }

    if (err)
    {
        return 0;
    }

    return 1;
}

#pragma dont_inline on
s32 EXIGetType(s32 chan, u32 dev, u32* type)
{
    u32 _type;
    s32 probe;

    probe = EXIGetID(chan, dev, &_type);

    if (!probe)
    {
        return probe;
    }

    switch (_type & ~0xFF)
    {
    case 0x04020300:
    case 0x04020200:
    case 0x04020100:
    case 0x04060000:
        *type = (_type & ~0xFF);
        return probe;
    default:
        switch (_type & ~0xFFFF)
        {
        case 0x00000000:
            if (!(_type & 0x3803))
            {
                switch (_type & 0xFC)
                {
                case 0x04:
                case 0x08:
                case 0x10:
                case 0x20:
                case 0x40:
                case 0x80:
                    *type = _type & 0xFC;
                    return probe;
                }
            }
            break;
        case 0x05070000:
            *type = 0x05070000;
            return probe;
        }

        *type = _type;
        return probe;
    }
}
#pragma dont_inline off

#pragma dont_inline on
#pragma scheduling on
BOOL ProbeBarnacle(s32 chan, u32 dev, u32* revision)
{
    int err;
    u32 cmd;

    if (chan != 2 && dev == 0 && !EXIAttach(chan, NULL))
    {
        return FALSE;
    }

    err = !EXILock(chan, dev, NULL);
    if (!err)
    {
        err = !EXISelect(chan, dev, EXI_FREQ_1M);
        if (!err)
        {
            cmd = 0x20011300;
            err = FALSE;
            err |= !EXIImm(chan, &cmd, sizeof(cmd), EXI_WRITE, NULL);
            err |= !EXISync(chan);
            err |= !EXIImm(chan, revision, sizeof(revision), EXI_READ, NULL);
            err |= !EXISync(chan);
            err |= !EXIDeselect(chan);
        }

        EXIUnlock(chan);
    }

    if (chan != 2 && dev == 0)
    {
        EXIDetach(chan);
    }

    if (err)
    {
        return FALSE;
    }

    if (*revision != 0xFFFFFFFF)
    {
        return TRUE;
    }

    return FALSE;
}
#pragma scheduling reset
#pragma dont_inline off

#pragma scheduling on
void __OSEnableBarnacle(s32 chan, u32 dev)
{
    u32 id;

    if (!EXIGetID(chan, dev, &id))
    {
        return;
    }

    switch (id)
    {
    case 0x04:
    case 0x08:
    case 0x10:
    case 0x20:
    case 0x01010000:
    case 0x01020000:
    case 0x02020000:
    case 0x03010000:
    case 0x04020100:
    case 0x04020200:
    case 0x04020300:
    case 0x04220000:
    case 0x04040404:
    case 0x04060000:
    case 0x04120000:
    case 0x04130000:
    case 0x80000004:
    case 0x80000008:
    case 0x80000010:
    case 0x80000020:
    case 0xFFFFFFFF:
        break;
    default:
        if (ProbeBarnacle(chan, dev, &id))
        {
            __EXIUartChannel = chan;
            __EXIUartDevice = dev;
            __EXIUartStatus = __EXIProbeBarnacleMagic = 0xA5FF005A;
            break;
        }
    }
}
#pragma scheduling reset
#pragma dont_inline off

#pragma scheduling on
int InitializeUART(void)
{
    if (__EXIProbeBarnacleMagic == 0xA5FF005A)
    {
        return 0;
    }

    if ((OSGetConsoleType() & 0x10000000) == 0)
    {
        __EXIUartStatus = 0;
        return 2;
    }

    __EXIUartChannel = 0;
    __EXIUartDevice = 1;
    __EXIUartStatus = 0xA5FF005A;
    return 0;
}
#pragma scheduling reset
#pragma dont_inline off

static inline int QueueLength(void)
{
    u32 cmd;

    if (EXISelect(__EXIUartChannel, __EXIUartDevice, 3) == 0)
    {
        return -1;
    }

    cmd = 0x20010000;
    EXIImm(__EXIUartChannel, &cmd, sizeof(cmd), EXI_WRITE, 0);
    EXISync(__EXIUartChannel);
    EXIImm(__EXIUartChannel, &cmd, 1, EXI_READ, 0);
    EXISync(__EXIUartChannel);
    EXIDeselect(__EXIUartChannel);
    return 0x10 - (cmd >> 0x18);
}

#pragma scheduling on
int WriteUARTN(void* buf, u32 len)
{
    BOOL enabled;
    u32 cmd;
    s32 xLen;
    int qLen;
    char* ptr;
    int locked;
    int error;

    if ((__EXIUartStatus - 0xA5FF0000) != 0x5A)
    {
        return 2;
    }

    enabled = OSDisableInterrupts();
    locked = EXILock(__EXIUartChannel, __EXIUartDevice, 0);
    if (locked == 0)
    {
        OSRestoreInterrupts(enabled);
        return 0;
    }
    else
    {
        ptr = (char*)buf;
    }

    while ((u32)ptr - (u32)buf < len)
    {
        if (*(s8*)ptr == 0xA)
        {
            *ptr = 0xD;
        }
        ptr++;
    }
    error = 0;
    cmd = 0xA0010000;

    while (len != 0)
    {
        qLen = QueueLength();
        if (qLen < 0)
        {
            error = 3;
            break;
        }

        if ((qLen >= 0xC) || (qLen >= len))
        {
            if (EXISelect(__EXIUartChannel, __EXIUartDevice, EXI_FREQ_8M) == 0)
            {
                error = 3;
                break;
            }

            EXIImm(__EXIUartChannel, &cmd, sizeof(cmd), EXI_WRITE, 0);
            EXISync(__EXIUartChannel);

            while ((qLen != 0) && (len != 0))
            {
                if ((qLen < 4) && (qLen < len))
                {
                    break;
                }

                xLen = len < 4 ? (long)len : 4;

                EXIImm(__EXIUartChannel, buf, xLen, EXI_WRITE, 0);
                (char*)buf += xLen;
                len -= xLen;
                qLen -= xLen;
                EXISync(__EXIUartChannel);
            }
            EXIDeselect(__EXIUartChannel);
        }
    }

    EXIUnlock(__EXIUartChannel);
    OSRestoreInterrupts(enabled);
    return error;
}
#pragma scheduling reset
