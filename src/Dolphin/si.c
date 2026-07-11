#include "dolphin/types.h"

typedef s64 OSTime;
typedef struct OSContext OSContext;

typedef struct OSAlarm
{
    u8 data[0x28];
} OSAlarm;

typedef void (*OSAlarmHandler)(OSAlarm* alarm, OSContext* context);
typedef void (*__OSInterruptHandler)(u32 interrupt, OSContext* context);
typedef void (*SITransferCallback)(s32 chan, u32 status, OSContext* context);
typedef void (*SIGetTypeCallback)(s32 chan, u32 type);

extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL level);
extern OSTime __OSGetSystemTime(void);
extern void __OSSetInterruptHandler(u32 interrupt, __OSInterruptHandler handler);
extern u32 __OSUnmaskInterrupts(u32 mask);
extern void OSSetAlarm(OSAlarm* alarm, OSTime tick, OSAlarmHandler handler);
extern void OSCancelAlarm(OSAlarm* alarm);
extern void OSRegisterVersion(char* version);
extern void OSReport(char* fmt, ...);
extern u16 OSGetWirelessID(s32 chan);
extern void OSSetWirelessID(s32 chan, u16 id);
extern u32 VIGetCurrentLine(void);
extern s32 VIGetTvFormat(void);

#define SI_BASE 0xCC006400

typedef struct SIChannel
{
    vu32 outBuf;
    vu32 inBufH;
    vu32 inBufL;
} SIChannel;

#define SI_CHANNELS ((volatile SIChannel*)SI_BASE)

#define SIPOLL (*(vu32*)(SI_BASE + 0x30))
#define SICOMCSR (*(vu32*)(SI_BASE + 0x34))
#define SISR (*(vu32*)(SI_BASE + 0x38))
#define SIIOBUF ((u8*)(SI_BASE + 0x80))

#define OS_BUS_CLOCK (*(u32*)0x800000F8)
#define VI_DCR (*(vu16*)0xCC00206C)

typedef struct SIControl
{
    s32 curChan;
    u32 pollValue;
    u32 inLen;
    void* inBuf;
    SITransferCallback callback;
} SIControl;

typedef struct SIPacket
{
    s32 chan;
    void* outBuf;
    u32 outLen;
    void* inBuf;
    u32 inLen;
    SITransferCallback callback;
    OSTime dueTime;
} SIPacket;

typedef struct SISamplingInfo
{
    u16 lineCount;
    u8 flags;
    u8 pad;
} SISamplingInfo;

char* __SIVersion = "<< Dolphin SDK - SI\trelease build: Sep  5 2002 05:33:08 (0x2301) >>";

static volatile SIControl Si = { -1, 0, 0, 0, 0 };
static s32 Type[4] = { 8, 8, 8, 8 };

static u8 lbl_804FCC48[0xb0] = {
    0x4e, 0x6f, 0x20, 0x72, 0x65, 0x73, 0x70, 0x6f, 0x6e, 0x73, 0x65, 0x00,
    0x4e, 0x36, 0x34, 0x20, 0x63, 0x6f, 0x6e, 0x74, 0x72, 0x6f, 0x6c, 0x6c,
    0x65, 0x72, 0x00, 0x00, 0x4e, 0x36, 0x34, 0x20, 0x6d, 0x69, 0x63, 0x72,
    0x6f, 0x70, 0x68, 0x6f, 0x6e, 0x65, 0x00, 0x00, 0x4e, 0x36, 0x34, 0x20,
    0x6b, 0x65, 0x79, 0x62, 0x6f, 0x61, 0x72, 0x64, 0x00, 0x00, 0x00, 0x00,
    0x4e, 0x36, 0x34, 0x20, 0x6d, 0x6f, 0x75, 0x73, 0x65, 0x00, 0x00, 0x00,
    0x47, 0x61, 0x6d, 0x65, 0x42, 0x6f, 0x79, 0x20, 0x41, 0x64, 0x76, 0x61,
    0x6e, 0x63, 0x65, 0x00, 0x53, 0x74, 0x61, 0x6e, 0x64, 0x61, 0x72, 0x64,
    0x20, 0x63, 0x6f, 0x6e, 0x74, 0x72, 0x6f, 0x6c, 0x6c, 0x65, 0x72, 0x00,
    0x57, 0x69, 0x72, 0x65, 0x6c, 0x65, 0x73, 0x73, 0x20, 0x72, 0x65, 0x63,
    0x65, 0x69, 0x76, 0x65, 0x72, 0x00, 0x00, 0x00, 0x57, 0x61, 0x76, 0x65,
    0x42, 0x69, 0x72, 0x64, 0x20, 0x63, 0x6f, 0x6e, 0x74, 0x72, 0x6f, 0x6c,
    0x6c, 0x65, 0x72, 0x00, 0x4b, 0x65, 0x79, 0x62, 0x6f, 0x61, 0x72, 0x64,
    0x00, 0x00, 0x00, 0x00, 0x53, 0x74, 0x65, 0x65, 0x72, 0x69, 0x6e, 0x67,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

static SISamplingInfo XYNTSC[12] = {
    { 0x00F6, 0x02 }, { 0x000F, 0x12 }, { 0x001E, 0x09 }, { 0x002C, 0x06 },
    { 0x0034, 0x05 }, { 0x0041, 0x04 }, { 0x0057, 0x03 }, { 0x0057, 0x03 },
    { 0x0057, 0x03 }, { 0x0083, 0x02 }, { 0x0083, 0x02 }, { 0x0083, 0x02 },
};

static SISamplingInfo XYPAL[12] = {
    { 0x0128, 0x02 }, { 0x000F, 0x15 }, { 0x001D, 0x0B }, { 0x002D, 0x07 },
    { 0x0034, 0x06 }, { 0x003F, 0x05 }, { 0x004E, 0x04 }, { 0x0068, 0x03 },
    { 0x0068, 0x03 }, { 0x0068, 0x03 }, { 0x0068, 0x03 }, { 0x009C, 0x02 },
};

static SIPacket Packet[4];
static OSAlarm Alarm[4];
static OSTime TypeTime[4];
static OSTime LastXfer[4];
static SIGetTypeCallback TypeCallbackQueue[4][4];
static __OSInterruptHandler PollHandlerTable[4];
static u32 ResponseValid[4];
static u32 ResponseData[4][2];
static u32 PollThreshold[4];
static u32 cmdFixDevice[4];

static u32 wirelessPending;

static u32 SamplingRate;

u32 fn_803E87C8(void);
static void SIInterruptHandler(u32 interrupt, OSContext* context);
BOOL __SITransfer(s32 chan, void* outBuf, s32 outLen, void* inBuf, s32 inLen, SITransferCallback callback);
void fn_803E96CC(OSAlarm* alarm, OSContext* context);
static void GetTypeCallback(s32 chan, u32 status, OSContext* context);
BOOL SIEnablePollingInterrupt(BOOL enable);
BOOL SIGetResponseRaw(s32 chan);
u32 SIGetStatus(s32 chan);
BOOL SITransfer(s32 chan, void* outBuf, s32 outLen, void* inBuf, s32 inLen, SITransferCallback callback,
                OSTime retryDelay);
s32 SIGetType(s32 chan);
void SISetSamplingRate(u32 rate);

BOOL SIBusy(void)
{
    if (Si.curChan != -1) {
        return TRUE;
    }
    return FALSE;
}

BOOL SIIsChanBusy(s32 chan)
{
    BOOL busy = TRUE;
    if (Packet[chan].chan == -1 && Si.curChan != chan) {
        busy = FALSE;
    }
    return busy;
}

u32 fn_803E87C8(void)
{
    u32 comcsr = SICOMCSR;
    u32 sr = SISR;
    s32 chan;

    SICOMCSR = comcsr & ~1 | 0x80000000;

    chan = Si.curChan;
    if (chan != -1) {
        s32 wordCount;
        s32 rem;
        s32 i;
        u32* dst;
        u8* hwSrc;

        LastXfer[chan] = __OSGetSystemTime();

        wordCount = Si.inLen >> 2;
        dst = (u32*)Si.inBuf;
        hwSrc = SIIOBUF;
        for (i = 0; i < wordCount; i++) {
            dst[i] = *(u32*)(hwSrc + i * 4);
        }

        rem = Si.inLen & 3;
        if (rem != 0) {
            u32 word = *(u32*)(hwSrc + wordCount * 4);
            u8* bdst = (u8*)dst + wordCount * 4;
            for (i = 0; i < rem; i++) {
                bdst[i] = (u8)(word >> ((3 - i) * 8));
            }
        }

        if ((SICOMCSR & 0x20000000) == 0) {
            TypeTime[chan] = __OSGetSystemTime();
            sr = 0;
        } else {
            u32 s = sr >> ((3 - chan) * 8);
            sr = s & 0xf;
            if ((s & 8) && !(Type[chan] & 0x80)) {
                Type[chan] = 8;
            }
            if (sr == 0) {
                sr = 4;
            }
        }

        Si.curChan = -1;
    }

    return sr;
}

static void SIInterruptHandler(u32 interrupt, OSContext* context)
{
    static u32 typeCmd;
    u32 comcsr = SICOMCSR;
    u32 sr = SISR;
    s32 curChan = Si.curChan;

    if ((comcsr & 0xC0000000) == 0xC0000000) {
        u32 status = fn_803E87C8();
        SITransferCallback callback = Si.callback;
        s32 i;
        s32 idx = curChan;

        Si.callback = 0;

        for (i = 0; i < 4; i++) {
            idx = (idx + 1) % 4;
            if (Packet[idx].chan != -1) {
                OSTime now = __OSGetSystemTime();
                if (now >= Packet[idx].dueTime) {
                    if (__SITransfer(Packet[idx].chan, Packet[idx].outBuf, Packet[idx].outLen, Packet[idx].inBuf,
                                      Packet[idx].inLen, Packet[idx].callback)) {
                        OSCancelAlarm(&Alarm[idx]);
                        Packet[idx].chan = -1;
                    }
                    break;
                }
            }
        }

        if (callback) {
            callback(curChan, status, context);
        }

        SISR &= 0xF000000 >> (curChan << 3);

        if (Type[curChan] == 0x80) {
            if (SIIsChanBusy(curChan)) {
                SITransfer(curChan, &typeCmd, 1, &Type[curChan], 3, GetTypeCallback,
                           ((OS_BUS_CLOCK / 500000) * 0x41) >> 3);
            }
        }
    }

    if ((comcsr & 0x18000000) == 0x18000000) {
        u32 line = VIGetCurrentLine() + 1;
        u32 poll = Si.pollValue;
        u32 interval = (poll & 0x3ff) >> 1;
        s32 i;

        for (i = 0; i < 4; i++) {
            if (SIGetResponseRaw(i)) {
                PollThreshold[i] = line;
            }
        }

        if ((!(poll & 0x80) || (PollThreshold[0] != 0 && line <= interval + PollThreshold[0])) &&
            (!(poll & 0x40) || (PollThreshold[1] != 0 && line <= interval + PollThreshold[1])) &&
            (!(poll & 0x20) || (PollThreshold[2] != 0 && line <= interval + PollThreshold[2])) &&
            (!(poll & 0x10) || (PollThreshold[3] != 0 && line <= interval + PollThreshold[3]))) {
            for (i = 0; i < 4; i++) {
                PollThreshold[i] = 0;
            }
            for (i = 0; i < 4; i++) {
                if (PollHandlerTable[i]) {
                    PollHandlerTable[i](interrupt, context);
                }
            }
        }
    }
}

#pragma dont_inline on
BOOL SIEnablePollingInterrupt(BOOL enable)
{
    u32 comcsr;
    BOOL old;
    BOOL enabled = OSDisableInterrupts();

    comcsr = SICOMCSR;
    old = (comcsr & 0x8000000) != 0;

    if (!enable) {
        comcsr &= 0xf7ffffff;
    } else {
        PollThreshold[0] = 0;
        comcsr |= 0x8000000;
        PollThreshold[1] = 0;
        PollThreshold[2] = 0;
        PollThreshold[3] = 0;
    }

    SICOMCSR = comcsr & 0x7ffffffe;
    OSRestoreInterrupts(enabled);
    return old;
}
#pragma dont_inline off

BOOL SIRegisterPollingHandler(__OSInterruptHandler handler)
{
    s32 i;
    BOOL enabled = OSDisableInterrupts();

    for (i = 0; i < 4; i++) {
        if (PollHandlerTable[i] == handler) {
            OSRestoreInterrupts(enabled);
            return TRUE;
        }
    }

    for (i = 0; i < 4; i++) {
        if (PollHandlerTable[i] == 0) {
            PollHandlerTable[i] = handler;
            SIEnablePollingInterrupt(TRUE);
            OSRestoreInterrupts(enabled);
            return TRUE;
        }
    }

    OSRestoreInterrupts(enabled);
    return FALSE;
}

BOOL SIUnregisterPollingHandler(__OSInterruptHandler handler)
{
    s32 i;
    s32 count;
    BOOL enabled = OSDisableInterrupts();

    for (i = 0; i < 4; i++) {
        if (PollHandlerTable[i] == handler) {
            PollHandlerTable[i] = 0;

            for (count = 0; count < 4; count++) {
                if (PollHandlerTable[count] != 0) {
                    break;
                }
            }

            if (count == 4) {
                SIEnablePollingInterrupt(FALSE);
            }

            OSRestoreInterrupts(enabled);
            return TRUE;
        }
    }

    OSRestoreInterrupts(enabled);
    return FALSE;
}

void SIInit(void)
{
    s32 chan;

    OSRegisterVersion(__SIVersion);

    Packet[3].chan = -1;
    Packet[2].chan = -1;
    Packet[1].chan = -1;
    Packet[0].chan = -1;

    Si.pollValue = 0;

    SISetSamplingRate(0);

    while (SICOMCSR & 1) {
    }
    SICOMCSR = 0x80000000;

    __OSSetInterruptHandler(0x14, SIInterruptHandler);
    __OSUnmaskInterrupts(0x800);

    for (chan = 0; chan < 4; chan++) {
        SIGetType(chan);
    }
}

BOOL __SITransfer(s32 chan, void* outBuf, s32 outLen, void* inBuf, s32 inLen, SITransferCallback callback)
{
    BOOL enabled = OSDisableInterrupts();
    union {
        u32 val;
        struct
        {
            u32 tcint : 1;
            u32 tcintmsk : 1;
            u32 comerr : 1;
            u32 rdstint : 1;
            u32 rdstintmsk : 1;
            u32 pad2 : 4;
            u32 outlngth : 7;
            u32 pad1 : 1;
            u32 inlngth : 7;
            u32 pad0 : 5;
            u32 channel : 2;
            u32 tstart : 1;
        } f;
    } comcsr;

    if (Si.curChan == -1) {
        u32 wordCount;
        u32 i;
        u32* src;
        u8* hwDst;

        SISR &= 0xF000000 >> (chan << 3);

        Si.curChan = chan;
        Si.inLen = inLen;
        Si.inBuf = inBuf;
        Si.callback = callback;

        wordCount = (outLen + 3) >> 2;
        src = (u32*)outBuf;
        hwDst = SIIOBUF;
        for (i = 0; i < wordCount; i++) {
            *(u32*)(hwDst + i * 4) = src[i];
        }

        comcsr.val = SICOMCSR;
        comcsr.f.tcint = 1;
        comcsr.f.tcintmsk = callback ? 1 : 0;
        comcsr.f.outlngth = (outLen == 0x80) ? 0 : outLen;
        comcsr.f.inlngth = (inLen == 0x80) ? 0 : inLen;
        comcsr.f.channel = chan;
        comcsr.f.tstart = 1;

        SICOMCSR = comcsr.val;

        OSRestoreInterrupts(enabled);
        return TRUE;
    }

    OSRestoreInterrupts(enabled);
    return FALSE;
}

#pragma dont_inline on
u32 SIGetStatus(s32 chan)
{
    u32 status;
    BOOL enabled = OSDisableInterrupts();

    status = SISR >> ((3 - chan) * 8);
    if ((status & 8) && !(Type[chan] & 0x80)) {
        Type[chan] = 8;
    }

    OSRestoreInterrupts(enabled);
    return status;
}
#pragma dont_inline off

void SISetCommand(s32 chan, u32 cmd)
{
    SI_CHANNELS[chan].outBuf = cmd;
}

void SITransferCommands(void)
{
    SISR = 0x80000000;
}

#pragma dont_inline on
u32 SISetXY(u32 x, u32 y)
{
    u32 poll;
    BOOL enabled;

    poll = x << 16;
    poll |= y << 8;

    enabled = OSDisableInterrupts();
    Si.pollValue &= 0xFC0000FF;
    Si.pollValue |= poll;
    poll = Si.pollValue;
    SIPOLL = poll;

    OSRestoreInterrupts(enabled);
    return poll;
}
#pragma dont_inline off

u32 SIEnablePolling(u32 mask)
{
    u32 en;
    BOOL enabled;

    if (mask == 0) {
        return Si.pollValue;
    }

    enabled = OSDisableInterrupts();
    mask = mask >> 24;
    en = mask & 0xf0;
    mask &= (en >> 4) | 0x3fffff0;
    mask &= 0xfc0000ff;
    Si.pollValue &= ~(en >> 4);
    Si.pollValue |= mask;
    mask = Si.pollValue;
    SISR = 0x80000000;
    SIPOLL = mask;
    OSRestoreInterrupts(enabled);

    return mask;
}

u32 SIDisablePolling(u32 mask)
{
    u32 poll;

    if (mask == 0) {
        return Si.pollValue;
    }

    {
        BOOL enabled = OSDisableInterrupts();
        poll = Si.pollValue & ~((mask >> 24) & 0xf0);
        SIPOLL = poll;
        Si.pollValue = poll;
        OSRestoreInterrupts(enabled);
    }

    return poll;
}

BOOL SIGetResponseRaw(s32 chan)
{
    BOOL enabled = OSDisableInterrupts();
    u32 status = SISR >> ((3 - chan) * 8);

    if ((status & 8) && !(Type[chan] & 0x80)) {
        Type[chan] = 8;
    }

    OSRestoreInterrupts(enabled);

    if (status & 0x20) {
        ResponseData[chan][0] = SI_CHANNELS[chan].inBufH;
        ResponseData[chan][1] = SI_CHANNELS[chan].inBufL;
        ResponseValid[chan] = 1;
        return TRUE;
    }

    return FALSE;
}

BOOL SIGetResponse(s32 chan, u32* buf)
{
    BOOL enabled = OSDisableInterrupts();
    u32 status = SIGetStatus(chan);
    BOOL got;

    if (status & 0x20) {
        ResponseData[chan][0] = SI_CHANNELS[chan].inBufH;
        ResponseData[chan][1] = SI_CHANNELS[chan].inBufL;
        ResponseValid[chan] = 1;
    }

    got = ResponseValid[chan];
    ResponseValid[chan] = 0;
    if (got) {
        buf[0] = ResponseData[chan][0];
        buf[1] = ResponseData[chan][1];
    }

    OSRestoreInterrupts(enabled);
    return got;
}

void fn_803E96CC(OSAlarm* alarm, OSContext* context)
{
    s32 chan = alarm - Alarm;
    s32 c = Packet[chan].chan;

    (void)context;

    if (c != -1) {
        if (__SITransfer(c, Packet[chan].outBuf, Packet[chan].outLen, Packet[chan].inBuf, Packet[chan].inLen,
                          Packet[chan].callback)) {
            Packet[chan].chan = -1;
        }
    }
}

BOOL SITransfer(s32 chan, void* outBuf, s32 outLen, void* inBuf, s32 inLen, SITransferCallback callback,
                OSTime retryDelay)
{
    BOOL enabled = OSDisableInterrupts();

    if (Packet[chan].chan == -1 && Si.curChan != chan) {
        OSTime now = __OSGetSystemTime();
        OSTime due = now;

        if (retryDelay != 0) {
            due = LastXfer[chan] + retryDelay;
        }

        if (due > now) {
            OSSetAlarm(&Alarm[chan], due, fn_803E96CC);
        } else if (__SITransfer(chan, outBuf, outLen, inBuf, inLen, callback)) {
            OSRestoreInterrupts(enabled);
            return TRUE;
        }

        Packet[chan].chan = chan;
        Packet[chan].outBuf = outBuf;
        Packet[chan].outLen = outLen;
        Packet[chan].inBuf = inBuf;
        Packet[chan].inLen = inLen;
        Packet[chan].callback = callback;
        Packet[chan].dueTime = due;

        OSRestoreInterrupts(enabled);
        return TRUE;
    }

    OSRestoreInterrupts(enabled);
    return FALSE;
}

static void GetTypeCallback(s32 chan, u32 status, OSContext* context)
{
    u32 chanBit;
    u32 oldPending;
    SIGetTypeCallback* queue;
    s32 i;

    (void)context;

    Type[chan] &= ~0x80;
    Type[chan] |= status;
    TypeTime[chan] = __OSGetSystemTime();

    chanBit = 0x80000000 >> chan;
    oldPending = wirelessPending & chanBit;
    wirelessPending &= ~chanBit;

    if ((status & 0xF) == 0 && (Type[chan] & 0x18000000) == 0x08000000 && (Type[chan] & 0x80000000) != 0 &&
        (Type[chan] & 0x04000000) == 0) {
        u16 id = OSGetWirelessID(chan);
        u32 wid = (u32)id << 8;

        if (oldPending != 0 && (wid & 0x00100000) != 0) {
            cmdFixDevice[chan] = (wid & 0x00CFFF00) | 0x4E100000;
            Type[chan] = 0x80;
            SITransfer(chan, &cmdFixDevice[chan], 3, &Type[chan], 3, GetTypeCallback, 0);
            return;
        }

        if (Type[chan] & 0x00100000) {
            if ((wid & 0x00CFFF00) != (Type[chan] & 0x00CFFF00)) {
                if (!(wid & 0x00100000)) {
                    wid = (Type[chan] & 0x00CFFF00) | 0x00100000;
                    OSSetWirelessID(chan, (u16)(wid >> 8));
                }
                cmdFixDevice[chan] = wid | 0x4E000000;
                Type[chan] = 0x80;
                SITransfer(chan, &cmdFixDevice[chan], 3, &Type[chan], 3, GetTypeCallback, 0);
                return;
            }
        } else if (Type[chan] & 0x40000000) {
            wid = (Type[chan] & 0x00CFFF00) | 0x00100000;
            OSSetWirelessID(chan, (u16)(wid >> 8));
            cmdFixDevice[chan] = wid | 0x4E000000;
            Type[chan] = 0x80;
            SITransfer(chan, &cmdFixDevice[chan], 3, &Type[chan], 3, GetTypeCallback, 0);
            return;
        } else {
            OSSetWirelessID(chan, 0);
        }
    } else {
        OSSetWirelessID(chan, 0);
    }

    queue = TypeCallbackQueue[chan];
    for (i = 0; i < 4; i++) {
        if (queue[i]) {
            SIGetTypeCallback cb = queue[i];
            queue[i] = 0;
            cb(chan, Type[chan]);
        }
    }
}

s32 SIGetType(s32 chan)
{
    static u32 cmdTypeAndStatus;
    BOOL enabled = OSDisableInterrupts();
    s32 type = Type[chan];
    OSTime now = __OSGetSystemTime();
    OSTime elapsed = now - TypeTime[chan];

    if (Si.pollValue & (0x80 >> chan)) {
        if (type != 8) {
            TypeTime[chan] = __OSGetSystemTime();
            OSRestoreInterrupts(enabled);
            return type;
        }
        Type[chan] = 0x80;
        type = 0x80;
    } else {
        if (elapsed < (OSTime)((OS_BUS_CLOCK / 4000) * 50) && type != 8) {
            OSRestoreInterrupts(enabled);
            return type;
        }
        if (elapsed < (OSTime)((OS_BUS_CLOCK / 4000) * 75)) {
            Type[chan] = 0x80;
        } else {
            Type[chan] = 0x80;
            type = 0x80;
        }
    }

    TypeTime[chan] = __OSGetSystemTime();
    SITransfer(chan, &cmdTypeAndStatus, 1, &Type[chan], 3, GetTypeCallback,
               ((OS_BUS_CLOCK / 500000) * 0x41) >> 3);
    OSRestoreInterrupts(enabled);
    return type;
}

s32 SIGetTypeAsync(s32 chan, SIGetTypeCallback callback)
{
    s32 i;
    BOOL enabled = OSDisableInterrupts();
    s32 type = SIGetType(chan);

    if (!(Type[chan] & 0x80)) {
        callback(chan, type);
    } else {
        for (i = 0; i < 4; i++) {
            if (TypeCallbackQueue[chan][i] == callback) {
                break;
            }
            if (TypeCallbackQueue[chan][i] == 0) {
                TypeCallbackQueue[chan][i] = callback;
                break;
            }
        }
    }

    OSRestoreInterrupts(enabled);
    return type;
}

void SISetSamplingRate(u32 rate)
{
    SISamplingInfo* table;
    s32 fmt;
    s32 mult;
    BOOL enabled;

    if (rate > 11) {
        rate = 11;
    }

    enabled = OSDisableInterrupts();
    SamplingRate = rate;

    fmt = VIGetTvFormat();
    switch (fmt) {
    case 0:
    case 2:
    case 5:
        table = XYNTSC;
        break;
    case 1:
        table = XYPAL;
        break;
    default:
        OSReport("SISetSamplingRate: unknown TV format. Use default.");
        rate = 0;
        table = XYNTSC;
        break;
    }

    mult = (VI_DCR & 1) ? 2 : 1;
    SISetXY(mult * table[rate].lineCount, table[rate].flags);

    OSRestoreInterrupts(enabled);
}

void SIRefreshSamplingRate(void)
{
    SISetSamplingRate(SamplingRate);
}

static u8 lbl_804FCD90[0x110] = {
    0x3c, 0x3c, 0x20, 0x44, 0x6f, 0x6c, 0x70, 0x68, 0x69, 0x6e, 0x20, 0x53,
    0x44, 0x4b, 0x20, 0x2d, 0x20, 0x45, 0x58, 0x49, 0x09, 0x72, 0x65, 0x6c,
    0x65, 0x61, 0x73, 0x65, 0x20, 0x62, 0x75, 0x69, 0x6c, 0x64, 0x3a, 0x20,
    0x4d, 0x61, 0x72, 0x20, 0x31, 0x31, 0x20, 0x32, 0x30, 0x30, 0x33, 0x20,
    0x31, 0x31, 0x3a, 0x31, 0x39, 0x3a, 0x30, 0x30, 0x20, 0x28, 0x30, 0x78,
    0x32, 0x33, 0x30, 0x31, 0x29, 0x20, 0x3e, 0x3e, 0x00, 0x00, 0x00, 0x00,
    0x4d, 0x65, 0x6d, 0x6f, 0x72, 0x79, 0x20, 0x43, 0x61, 0x72, 0x64, 0x20,
    0x35, 0x39, 0x00, 0x00, 0x4d, 0x65, 0x6d, 0x6f, 0x72, 0x79, 0x20, 0x43,
    0x61, 0x72, 0x64, 0x20, 0x31, 0x32, 0x33, 0x00, 0x4d, 0x65, 0x6d, 0x6f,
    0x72, 0x79, 0x20, 0x43, 0x61, 0x72, 0x64, 0x20, 0x32, 0x35, 0x31, 0x00,
    0x4d, 0x65, 0x6d, 0x6f, 0x72, 0x79, 0x20, 0x43, 0x61, 0x72, 0x64, 0x20,
    0x35, 0x30, 0x37, 0x00, 0x4d, 0x65, 0x6d, 0x6f, 0x72, 0x79, 0x20, 0x43,
    0x61, 0x72, 0x64, 0x20, 0x31, 0x30, 0x31, 0x39, 0x00, 0x00, 0x00, 0x00,
    0x4d, 0x65, 0x6d, 0x6f, 0x72, 0x79, 0x20, 0x43, 0x61, 0x72, 0x64, 0x20,
    0x32, 0x30, 0x34, 0x33, 0x00, 0x00, 0x00, 0x00, 0x55, 0x53, 0x42, 0x20,
    0x41, 0x64, 0x61, 0x70, 0x74, 0x65, 0x72, 0x00, 0x4e, 0x65, 0x74, 0x20,
    0x43, 0x61, 0x72, 0x64, 0x00, 0x00, 0x00, 0x00, 0x41, 0x72, 0x74, 0x69,
    0x73, 0x74, 0x20, 0x45, 0x74, 0x68, 0x65, 0x72, 0x00, 0x00, 0x00, 0x00,
    0x42, 0x72, 0x6f, 0x61, 0x64, 0x62, 0x61, 0x6e, 0x64, 0x20, 0x41, 0x64,
    0x61, 0x70, 0x74, 0x65, 0x72, 0x00, 0x00, 0x00, 0x53, 0x74, 0x72, 0x65,
    0x61, 0x6d, 0x20, 0x48, 0x61, 0x6e, 0x67, 0x65, 0x72, 0x00, 0x00, 0x00,
    0x49, 0x53, 0x2d, 0x44, 0x4f, 0x4c, 0x2d, 0x56, 0x49, 0x45, 0x57, 0x45,
    0x52, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

static u8 lbl_804FCEA0[0x44] = {
    0x3c, 0x3c, 0x20, 0x44, 0x6f, 0x6c, 0x70, 0x68, 0x69, 0x6e, 0x20, 0x53,
    0x44, 0x4b, 0x20, 0x2d, 0x20, 0x41, 0x58, 0x09, 0x72, 0x65, 0x6c, 0x65,
    0x61, 0x73, 0x65, 0x20, 0x62, 0x75, 0x69, 0x6c, 0x64, 0x3a, 0x20, 0x4d,
    0x61, 0x72, 0x20, 0x31, 0x31, 0x20, 0x32, 0x30, 0x30, 0x33, 0x20, 0x31,
    0x31, 0x3a, 0x31, 0x39, 0x3a, 0x33, 0x39, 0x20, 0x28, 0x30, 0x78, 0x32,
    0x33, 0x30, 0x31, 0x29, 0x20, 0x3e, 0x3e, 0x00,
};

