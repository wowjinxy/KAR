#include "dolphin/types.h"

typedef s64 OSTime;
typedef u32 OSTick;
typedef struct OSContext OSContext;

typedef struct OSThreadQueue
{
    void* head;
    void* tail;
} OSThreadQueue;

typedef struct OSAlarm
{
    u8 data[0x28];
} OSAlarm;

typedef void (*OSAlarmHandler)(OSAlarm* alarm, OSContext* context);
typedef void (*DSPCallback)(void* task);
typedef struct DSPTaskInfo DSPTaskInfo;

struct DSPTaskInfo
{
    volatile u32 state;         //0x00
    volatile u32 priority;      //0x04
    volatile u32 flags;         //0x08
    u16* iram_mmem_addr;        //0x0C
    u32 iram_length;            //0x10
    u32 iram_addr;               //0x14
    u16* dram_mmem_addr;        //0x18
    u32 dram_length;            //0x1C
    u32 dram_addr;               //0x20
    u16 dsp_init_vector;        //0x24
    u16 dsp_resume_vector;      //0x26
    DSPCallback init_cb;        //0x28
    DSPCallback res_cb;         //0x2C
    DSPCallback done_cb;        //0x30
    DSPCallback req_cb;         //0x34
    DSPTaskInfo* next;          //0x38
    DSPTaskInfo* prev;          //0x3C
    OSTime t_context;           //0x40
    OSTime t_task;              //0x48
};                              //0x50

typedef void (*EXICallback)(s32 chan, OSContext* context);

typedef struct DVDDiskID
{
    char gameName[4];
    char company[2];
    u8 diskNumber;
    u8 gameVersion;
    u8 streaming;
    u8 streamingBufSize;
    u8 padding[22];
} DVDDiskID;

typedef struct OSSram
{
    u16 checkSum;
    u16 checkSumInv;
    u32 ead0;
    u32 ead1;
    u32 counterBias;
    s8 displayOffsetH;
    u8 ntd;
    u8 language;
    u8 flags;
} OSSram;

typedef struct OSSramEx
{
    u8 flashID[2][12];
    u32 wirelessKeyboardID;
    u16 wirelessPadID[4];
    u8 dvdErrorCode;
    u8 _padding0;
    u8 flashIDCheckSum[2];
    u16 gbs;
    u8 _padding1[2];
} OSSramEx;

typedef struct OSResetFunctionInfo OSResetFunctionInfo;
typedef BOOL (*OSResetFunction)(BOOL);

struct OSResetFunctionInfo
{
    OSResetFunction func;
    u32 priority;
    OSResetFunctionInfo* next;
    OSResetFunctionInfo* prev;
};

typedef void (*CARDCallback)(s32 chan, s32 result);

typedef struct CARDFileInfo
{
    s32 chan;
    s32 fileNo;
    s32 offset;
    s32 length;
    u16 iBlock;
} CARDFileInfo;

typedef struct CARDDir
{
    u8 gameName[4];         //0x00
    u8 company[2];          //0x04
    u8 _padding0;           //0x06
    u8 bannerFormat;        //0x07
    u8 fileName[32];        //0x08
    u32 time;               //0x28
    u32 iconAddr;           //0x2C
    u16 iconFormat;         //0x30
    u16 iconSpeed;          //0x32
    u8 permission;          //0x34
    u8 copyTimes;           //0x35
    u16 startBlock;         //0x36
    u16 length;             //0x38
    u8 _padding1[2];        //0x3A
    u32 commentAddr;        //0x3C
} CARDDir;                 //0x40

typedef struct CARDDirCheck
{
    u8 padding0[56];
    u16 padding1;
    s16 checkCode;
    u16 checkSum;
    u16 checkSumInv;
} CARDDirCheck;

typedef struct CARDControl
{
    /* 0x000 */ BOOL attached;
    /* 0x004 */ s32 result;
    /* 0x008 */ u16 size;
    /* 0x00A */ u16 pageSize;
    /* 0x00C */ s32 sectorSize;
    /* 0x010 */ u16 cBlock;
    /* 0x012 */ u16 vendorID;
    /* 0x014 */ s32 latency;
    /* 0x018 */ u8 id[12];
    /* 0x024 */ int mountStep;
    /* 0x028 */ int formatStep;
    /* 0x02C */ u32 scramble;
    /* 0x030 */ DSPTaskInfo task;
    /* 0x080 */ void* workArea;
    /* 0x084 */ CARDDir* currentDir;
    /* 0x088 */ u16* currentFat;
    /* 0x08C */ OSThreadQueue threadQueue;
    /* 0x094 */ u8 cmd[9];
    /* 0x0A0 */ s32 cmdlen;
    /* 0x0A4 */ volatile u32 mode;
    /* 0x0A8 */ int retry;
    /* 0x0AC */ int repeat;
    /* 0x0B0 */ u32 addr;
    /* 0x0B4 */ void* buffer;
    /* 0x0B8 */ s32 xferred;
    /* 0x0BC */ u16 freeNo;
    /* 0x0BE */ u16 startBlock;
    /* 0x0C0 */ CARDFileInfo* fileInfo;
    /* 0x0C4 */ CARDCallback extCallback;
    /* 0x0C8 */ CARDCallback txCallback;
    /* 0x0CC */ CARDCallback exiCallback;
    /* 0x0D0 */ CARDCallback apiCallback;
    /* 0x0D4 */ CARDCallback xferCallback;
    /* 0x0D8 */ CARDCallback eraseCallback;
    /* 0x0DC */ CARDCallback unlockCallback;
    /* 0x0E0 */ OSAlarm alarm;
    /* 0x108 */ u32 cid;
    /* 0x10C */ const DVDDiskID* diskID;
} CARDControl;

typedef struct CARDDecParam
{
    u8* inputAddr;
    u32 inputLength;
    u32 aramAddr;
    u8* outputAddr;
} CARDDecParam;

typedef struct CARDID
{
    u8 serial[32];
    u16 deviceID;
    u16 size;
    u16 encode;
    u8 padding[470];
    u16 checkSum;
    u16 checkSumInv;
} CARDID;

typedef struct CARDStat
{
    char fileName[32];
    u32 length;
    u32 time;
    u8 gameName[4];
    u8 company[2];
    u8 bannerFormat;
    u32 iconAddr;
    u16 iconFormat;
    u16 iconSpeed;
    u32 commentAddr;
    u32 offsetBanner;
    u32 offsetBannerTlut;
    u32 offsetIcon[8];
    u32 offsetIconTlut;
    u32 offsetData;
} CARDStat;

#define CARD_FILENAME_MAX 32
#define CARD_MAX_FILE 127

#define CARD_ATTR_PUBLIC  0x04u

#define CARD_FAT_CHECKCODE 0x0002u
#define CARD_FAT_CHECKSUMINV 0x0001u
#define CARD_FAT_FREEBLOCKS 0x0003u
#define CARD_FAT_LASTSLOT 0x0004u

#define CARD_SEG_SIZE 0x200u
#define CARD_PAGE_SIZE 0x80u

#define CARD_NUM_SYSTEM_BLOCK 5
#define CARD_SYSTEM_BLOCK_SIZE (8 * 1024u)

#define CARD_MAX_MOUNT_STEP (CARD_NUM_SYSTEM_BLOCK + 2)

#define CARD_STAT_BANNER_C8 1
#define CARD_STAT_BANNER_RGB5A3 2
#define CARD_STAT_BANNER_MASK 3

#define CARD_STAT_ICON_C8 1
#define CARD_STAT_ICON_RGB5A3 2
#define CARD_STAT_ICON_MASK 3

#define CARD_STAT_SPEED_FAST 1
#define CARD_STAT_SPEED_MASK 3

#define CARD_ICON_MAX 8
#define CARD_ICON_WIDTH 32
#define CARD_ICON_HEIGHT 32
#define CARD_BANNER_WIDTH 96
#define CARD_BANNER_HEIGHT 32
#define CARD_READ_SIZE 512
#define CARD_COMMENT_SIZE 64

#define CARD_ENCODE_ANSI 0
#define CARD_ENCODE_SJIS 1

#define CARD_RESULT_UNLOCKED       1
#define CARD_RESULT_READY          0
#define CARD_RESULT_BUSY          -1
#define CARD_RESULT_WRONGDEVICE   -2
#define CARD_RESULT_NOCARD        -3
#define CARD_RESULT_NOFILE        -4
#define CARD_RESULT_IOERROR       -5
#define CARD_RESULT_BROKEN        -6
#define CARD_RESULT_EXIST         -7
#define CARD_RESULT_NOENT         -8
#define CARD_RESULT_INSSPACE      -9
#define CARD_RESULT_NOPERM       -10
#define CARD_RESULT_LIMIT        -11
#define CARD_RESULT_NAMETOOLONG  -12
#define CARD_RESULT_ENCODING     -13
#define CARD_RESULT_CANCELED     -14
#define CARD_RESULT_FATAL_ERROR -128

#define CARDIsValidBlockNo(card, blockNo) ((blockNo) >= CARD_NUM_SYSTEM_BLOCK && (blockNo) < (card)->cBlock)
#define CARDGetDirCheck(dir) ((CARDDirCheck*)&(dir)[CARD_MAX_FILE])
#define CARDGetBannerFormat(stat) (((stat)->bannerFormat) & CARD_STAT_BANNER_MASK)
#define CARDGetIconFormat(stat, n) (((stat)->iconFormat >> (2 * (n))) & CARD_STAT_ICON_MASK)
#define CARDSetIconSpeed(stat, n, f)                                                               \
    ((stat)->iconSpeed =                                                                             \
        (u16)(((stat)->iconSpeed & ~(CARD_STAT_SPEED_MASK << (2 * (n)))) | ((f) << (2 * (n)))))

#define EXI_FREQ_16M 4
#define EXI_READ  0
#define EXI_WRITE 1

#define OS_BASE_CACHED 0x80000000
#define OS_TIMER_CLOCK (__OSBusClock/4)
#define OSTicksToSeconds(ticks) ((ticks) / (OS_TIMER_CLOCK))
#define OSSecondsToTicks(sec) ((sec) * (OS_TIMER_CLOCK))
#define OSMillisecondsToTicks(msec) ((msec) * (OS_TIMER_CLOCK / 1000))
#define OSPhysicalToCached(paddr) ((void*)((u32)(OS_BASE_CACHED + (u32)(paddr))))
#define OSCachedToPhysical(caddr) ((u32)((u32)(caddr) - OS_BASE_CACHED))
#define OSRoundUp32B(x) (((u32)(x) + 32 - 1) & ~(32 - 1))
#define OFFSET(addr, align) (((u32)(addr) & ((align)-1)))

#define __VIRegs ((vu16*)0xCC002000)
#define __OSBusClock (*(u32*)(OS_BASE_CACHED | 0x00F8))

extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL level);
extern OSTick OSGetTick(void);
extern OSTime OSGetTime(void);
extern void OSRegisterVersion(const char* id);
extern u16 OSGetFontEncode(void);
extern void OSInitAlarm(void);
extern void OSCreateAlarm(OSAlarm* alarm);
extern void OSSetAlarm(OSAlarm* alarm, OSTime tick, OSAlarmHandler handler);
extern void OSCancelAlarm(OSAlarm* alarm);
extern void OSRegisterResetFunction(OSResetFunctionInfo* info);
extern void OSInitThreadQueue(OSThreadQueue* queue);
extern void OSSleepThread(OSThreadQueue* queue);
extern void OSWakeupThread(OSThreadQueue* queue);
extern OSSram* __OSLockSram(void);
extern int __OSUnlockSram(int commit);
extern OSSramEx* __OSLockSramEx(void);
extern int __OSUnlockSramEx(int commit);
extern void DCInvalidateRange(void* addr, u32 nBytes);
extern void DCFlushRange(void* addr, u32 nBytes);
extern void kar_diag__near_803d3f54(void* addr, u32 nBytes);
#define DCStoreRange kar_diag__near_803d3f54
extern void DSPInit(void);
extern DSPTaskInfo* DSPAddTask(DSPTaskInfo* task);
extern u32 DSPCheckMailToDSP(void);
extern void DSPSendMailToDSP(u32 mail);

extern int EXISelect(s32 chan, u32 dev, u32 freq);
extern int EXIDeselect(s32 chan);
extern int EXIImm(s32 chan, void* buf, s32 len, u32 type, EXICallback callback);
extern int EXIImmEx(s32 chan, void* buf, s32 len, u32 mode);
extern int EXISync(s32 chan);
extern int EXIDma(s32 chan, void* buf, s32 len, u32 type, EXICallback callback);
extern int EXILock(s32 chan, u32 dev, EXICallback unlockedCallback);
extern int EXIUnlock(s32 chan);
extern int EXIProbe(s32 chan);
extern s32 EXIProbeEx(s32 chan);
extern u32 EXIGetState(s32 chan);
extern s32 EXIGetID(s32 chan, u32 dev, u32* id);
extern int EXIAttach(s32 chan, EXICallback extCallback);
extern int EXIDetach(s32 chan);
extern EXICallback EXISetExiCallback(s32 chan, EXICallback exiCallback);

extern void* memset(void* dst, int val, u32 n);
extern void* memcpy(void* dst, const void* src, u32 n);
extern int memcmp(const void* a, const void* b, u32 n);
extern u32 strlen(const char* s);
extern char* strncpy(char* dst, const char* src, u32 n);

#define __gUnknown800030E3 (*(vu8*)0x800030E3)

CARDControl __CARDBlock[2];

DVDDiskID __CARDDiskNone;

static u16 __CARDEncode;

extern const char __CARDVersionString[];
const char* __CARDVersion = __CARDVersionString;

u16 __CARDVendorID = 0xFFFF;

extern void* fn_803E45EC(CARDControl* card);
extern CARDDir* kar_diagnostic__803e49f0(CARDControl* card);
extern s32 __CARDUpdateFatBlock(s32 chan, u16* fat, CARDCallback callback);
extern void kar_diagnostic__near_803e7c40(s32 chan, s32 result);
#define __CARDGetFatBlock fn_803E45EC
#define __CARDGetDirBlock kar_diagnostic__803e49f0

void __CARDDefaultApiCallback(s32 chan, s32 result) {}

void __CARDSyncCallback(s32 chan, s32 result) {
    CARDControl* card;
    card = &__CARDBlock[chan];
    OSWakeupThread(&card->threadQueue);
}

void __CARDExtHandler(s32 chan, OSContext* context) {
    CARDControl* card;
    CARDCallback callback;

    card = &__CARDBlock[chan];
    if (card->attached) {
        card->attached = FALSE;
        EXISetExiCallback(chan, 0);
        OSCancelAlarm(&card->alarm);
        callback = card->exiCallback;

        if (callback) {
            card->exiCallback = 0;
            callback(chan, CARD_RESULT_NOCARD);
        }

        if (card->result != CARD_RESULT_BUSY) {
            card->result = CARD_RESULT_NOCARD;
        }

        callback = card->extCallback;
        if (callback && CARD_MAX_MOUNT_STEP <= card->mountStep) {
            card->extCallback = 0;
            callback(chan, CARD_RESULT_NOCARD);
        }
    }
}

s32 Retry(s32 chan);
extern s32 __CARDReadStatus(s32 chan, u8* status);
extern s32 __CARDClearStatus(s32 chan);

void __CARDExiHandler(s32 chan, OSContext* context) {
    CARDControl* card;
    CARDCallback callback;
    u8 status;
    s32 result;

    card = &__CARDBlock[chan];

    OSCancelAlarm(&card->alarm);

    if (!card->attached) {
        return;
    }

    if (!EXILock(chan, 0, 0)) {
        result = CARD_RESULT_FATAL_ERROR;
        goto fatal;
    }

    if ((result = __CARDReadStatus(chan, &status)) < 0 || (result = __CARDClearStatus(chan)) < 0) {
        goto error;
    }

    if ((result = (status & 0x18) ? CARD_RESULT_IOERROR : CARD_RESULT_READY) == CARD_RESULT_IOERROR &&
        --card->retry > 0)
    {
        result = Retry(chan);
        if (result >= 0)
        {
            return;
        }
        goto fatal;
    }

error:
    EXIUnlock(chan);

fatal:
    callback = card->exiCallback;
    if (callback) {
        card->exiCallback = 0;
        callback(chan, result);
    }
}

void __CARDTxHandler(s32 chan, OSContext* context) {
    CARDControl* card;
    CARDCallback callback;
    int err;

    card = &__CARDBlock[chan];
    err = !EXIDeselect(chan);
    EXIUnlock(chan);
    callback = card->txCallback;
    if (callback) {
        card->txCallback = NULL;
        callback(chan, (!err && EXIProbe(chan)) ? CARD_RESULT_READY : CARD_RESULT_NOCARD);
    }
}

void __CARDUnlockedHandler(s32 chan, OSContext* context) {
    CARDControl* card;
    CARDCallback callback;

    card = &__CARDBlock[chan];
    callback = card->unlockCallback;
    if (callback) {
        card->unlockCallback = 0;
        callback(chan, EXIProbe(chan) ? CARD_RESULT_UNLOCKED : CARD_RESULT_NOCARD);
    }
}

s32 __CARDEnableInterrupt(s32 chan, BOOL enable) {
    BOOL err;
    u32 cmd;

    if (!EXISelect(chan, 0, EXI_FREQ_16M)) {
        return CARD_RESULT_NOCARD;
    }

    cmd = enable ? 0x81010000 : 0x81000000;
    err = FALSE;
    err |= !EXIImm(chan, &cmd, 2, EXI_WRITE, NULL);
    err |= !EXISync(chan);
    err |= !EXIDeselect(chan);
    return err ? CARD_RESULT_NOCARD : CARD_RESULT_READY;
}

#pragma dont_inline on
s32 __CARDReadStatus(s32 chan, u8* status) {
    BOOL err;
    u32 cmd;

    if (!EXISelect(chan, 0, EXI_FREQ_16M)) {
        return CARD_RESULT_NOCARD;
    }

    cmd = 0x83000000;
    err = FALSE;
    err |= !EXIImm(chan, &cmd, 2, EXI_WRITE, NULL);
    err |= !EXISync(chan);
    err |= !EXIImm(chan, status, 1, EXI_READ, NULL);
    err |= !EXISync(chan);
    err |= !EXIDeselect(chan);
    return err ? CARD_RESULT_NOCARD : CARD_RESULT_READY;
}
#pragma dont_inline off

#pragma dont_inline on
s32 __CARDClearStatus(s32 chan) {
    BOOL err;
    u32 cmd;

    if (!EXISelect(chan, 0, EXI_FREQ_16M)) {
        return CARD_RESULT_NOCARD;
    }

    cmd = 0x89000000;
    err = FALSE;
    err |= !EXIImm(chan, &cmd, 1, EXI_WRITE, 0);
    err |= !EXISync(chan);
    err |= !EXIDeselect(chan);

    return err ? CARD_RESULT_NOCARD : CARD_RESULT_READY;
}
#pragma dont_inline off

void TimeoutHandler(OSAlarm* alarm, OSContext* context) {
    s32 chan;
    CARDControl* card;
    CARDCallback callback;
    for (chan = 0; chan < 2; ++chan) {
        card = &__CARDBlock[chan];
        if (alarm == &card->alarm) {
            break;
        }
    }

    if (!card->attached) {
        return;
    }

    EXISetExiCallback(chan, NULL);
    callback = card->exiCallback;
    if (callback) {
        card->exiCallback = 0;
        callback(chan, CARD_RESULT_IOERROR);
    }
}

static inline void SetupTimeoutAlarm(CARDControl* card) {
    OSCancelAlarm(&card->alarm);
    switch (card->cmd[0]) {
    case 0xF2:
        OSSetAlarm(&card->alarm, OSMillisecondsToTicks(100),
                   TimeoutHandler);
        break;
    case 0xF3:
        break;
    case 0xF4:
        if (card->pageSize > 0x80) {
            OSSetAlarm(&card->alarm, OSSecondsToTicks((OSTime)2) * (card->cBlock / 0x40),
                       TimeoutHandler);
            break;
        }
    case 0xF1:
        OSSetAlarm(&card->alarm, OSSecondsToTicks((OSTime)2) * (card->sectorSize / 0x2000),
                   TimeoutHandler);
        break;
    }
}

s32 Retry(s32 chan) {
    CARDControl* card;

    card = &__CARDBlock[chan];
    if (!EXISelect(chan, 0, EXI_FREQ_16M)) {
        EXIUnlock(chan);
        return CARD_RESULT_NOCARD;
    }

    SetupTimeoutAlarm(card);

    if (!EXIImmEx(chan, card->cmd, card->cmdlen, EXI_WRITE)) {
        EXIDeselect(chan);
        EXIUnlock(chan);
        return CARD_RESULT_NOCARD;
    }

    if (card->cmd[0] == 0x52 &&
        !EXIImmEx(chan, (u8*)card->workArea + sizeof(CARDID), card->latency, EXI_WRITE))
    {
        EXIDeselect(chan);
        EXIUnlock(chan);
        return CARD_RESULT_NOCARD;
    }

    if (card->mode == 0xffffffff) {
        EXIDeselect(chan);
        EXIUnlock(chan);
        return CARD_RESULT_READY;
    }

    if (!EXIDma(chan, card->buffer, (s32)((card->cmd[0] == 0x52) ? 512 : card->pageSize), card->mode,
                __CARDTxHandler))
    {
        EXIDeselect(chan);
        EXIUnlock(chan);
        return CARD_RESULT_NOCARD;
    }

    return CARD_RESULT_READY;
}

void UnlockedCallback(s32 chan, s32 result) {
    CARDCallback callback;
    CARDControl* card;

    card = &__CARDBlock[chan];
    if (result >= 0) {
        card->unlockCallback = UnlockedCallback;
        if (!EXILock(chan, 0, __CARDUnlockedHandler)) {
            result = CARD_RESULT_READY;
        } else {
            card->unlockCallback = 0;
            result = Retry(chan);
        }
    }

    if (result < 0) {
        switch (card->cmd[0]) {
        case 0x52:
            callback = card->txCallback;
            if (callback) {
                card->txCallback = NULL;
                callback(chan, result);
            }
            break;
        case 0xF2:
        case 0xF4:
        case 0xF1:
            callback = card->exiCallback;
            if (callback) {
                card->exiCallback = 0;
                callback(chan, result);
            }
            break;
        }
    }
}

s32 __CARDStart(s32 chan, CARDCallback txCallback, CARDCallback exiCallback) {
    BOOL enabled;
    CARDControl* card;
    s32 result;

    enabled = OSDisableInterrupts();

    card = &__CARDBlock[chan];
    if (!card->attached) {
        result = CARD_RESULT_NOCARD;
    } else {
        if (txCallback) {
            card->txCallback = txCallback;
        }

        if (exiCallback) {
            card->exiCallback = exiCallback;
        }

        card->unlockCallback = UnlockedCallback;

        if (!EXILock(chan, 0, __CARDUnlockedHandler)) {
            result = CARD_RESULT_BUSY;
        } else {
            card->unlockCallback = 0;

            if (!EXISelect(chan, 0, EXI_FREQ_16M)) {
                EXIUnlock(chan);
                result = CARD_RESULT_NOCARD;
            } else {
                SetupTimeoutAlarm(card);
                result = CARD_RESULT_READY;
            }
        }
    }

    OSRestoreInterrupts(enabled);
    return result;
}

#define AD1(x) ((u8)(((x) >> 17) & 0x7f))
#define AD2(x) ((u8)(((x) >> 9) & 0xff))
#define AD3(x) ((u8)(((x) >> 7) & 0x03))
#define BA(x) ((u8)((x)&0x7f))

#pragma dont_inline on
s32 __CARDReadSegment(s32 chan, CARDCallback callback) {
    CARDControl* card;
    s32 result;

    card = &__CARDBlock[chan];

    card->cmd[0] = 0x52;
    card->cmd[1] = AD1(card->addr);
    card->cmd[2] = AD2(card->addr);
    card->cmd[3] = AD3(card->addr);
    card->cmd[4] = BA(card->addr);
    card->cmdlen = 5;
    card->mode = 0;
    card->retry = 0;

    result = __CARDStart(chan, callback, 0);
    if (result == CARD_RESULT_BUSY) {
        result = CARD_RESULT_READY;
    } else if (result >= 0) {
        if (!EXIImmEx(chan, card->cmd, card->cmdlen, EXI_WRITE) ||
            !EXIImmEx(chan, (u8*)card->workArea + sizeof(CARDID), card->latency, EXI_WRITE) ||
            !EXIDma(chan, card->buffer, 512, card->mode, __CARDTxHandler))
        {
            card->txCallback = NULL;
            EXIDeselect(chan);
            EXIUnlock(chan);
            result = CARD_RESULT_NOCARD;
        } else {
            result = CARD_RESULT_READY;
        }
    }

    return result;
}
#pragma dont_inline off

#pragma dont_inline on
s32 __CARDWritePage(s32 chan, CARDCallback callback) {
    CARDControl* card;
    s32 result;

    card = &__CARDBlock[chan];
    card->cmd[0] = 0xF2;

    if (card->pageSize > 0x80) {
        card->cmd[1] = AD1(card->addr) | 0x80;
    } else {
        card->cmd[1] = AD1(card->addr);
    }

    card->cmd[2] = AD2(card->addr);
    card->cmd[3] = AD3(card->addr);
    card->cmd[4] = BA(card->addr);
    card->cmdlen = 5;
    card->mode = 1;
    card->retry = 3;

    result = __CARDStart(chan, 0, callback);
    if (result == CARD_RESULT_BUSY) {
        result = CARD_RESULT_READY;
    } else if (result >= 0) {
        if (!EXIImmEx(chan, card->cmd, card->cmdlen, EXI_WRITE) ||
            !EXIDma(chan, card->buffer, card->pageSize, card->mode, __CARDTxHandler))
        {
            card->exiCallback = 0;
            EXIDeselect(chan);
            EXIUnlock(chan);
            result = CARD_RESULT_NOCARD;
        } else {
            result = CARD_RESULT_READY;
        }
    }

    return result;
}
#pragma dont_inline off

#pragma dont_inline on
s32 __CARDEraseSector(s32 chan, u32 addr, CARDCallback callback) {
    CARDControl* card;
    s32 result;

    card = &__CARDBlock[chan];

    if (card->pageSize > 0x80) {
        if (callback) {
            callback(chan, 0);
        }
        return 0;
    }

    card->cmd[0] = 0xF1;
    card->cmd[1] = AD1(addr);
    card->cmd[2] = AD2(addr);
    card->cmdlen = 3;
    card->mode = -1;
    card->retry = 3;

    result = __CARDStart(chan, 0, callback);

    if (result == CARD_RESULT_BUSY) {
        result = CARD_RESULT_READY;
    } else if (result >= 0) {
        if (!EXIImmEx(chan, card->cmd, card->cmdlen, EXI_WRITE)) {
            result = CARD_RESULT_NOCARD;
            card->exiCallback = NULL;
        } else {
            result = CARD_RESULT_READY;
        }

        EXIDeselect(chan);
        EXIUnlock(chan);
    }
    return result;
}
#pragma dont_inline off

BOOL fn_803E30BC(BOOL final);
static OSResetFunctionInfo ResetFunctionInfo = {fn_803E30BC, 127};
extern s32 CARDUnmount(s32 chan);
extern void __CARDCheckSum(void* ptr, int length, u16* checksum, u16* checksumInv);
extern void __CARDSetDiskID(const DVDDiskID* id);

void CARDInit(void) {
    int chan;

    if (__CARDBlock[0].diskID && __CARDBlock[1].diskID) {
        return;
    }

    __CARDEncode = OSGetFontEncode();

    OSRegisterVersion(__CARDVersion);

    DSPInit();
    OSInitAlarm();

    for (chan = 0; chan < 2; ++chan) {
        CARDControl* card = &__CARDBlock[chan];

        card->result = CARD_RESULT_NOCARD;
        OSInitThreadQueue(&card->threadQueue);
        OSCreateAlarm(&card->alarm);
    }
    __CARDSetDiskID((void*)OSPhysicalToCached(0));

    OSRegisterResetFunction(&ResetFunctionInfo);
}

u16 __CARDGetFontEncode(void) {
    return __CARDEncode;
}

void __CARDSetDiskID(const DVDDiskID* id) {
    __CARDBlock[0].diskID = id ? id : &__CARDDiskNone;
    __CARDBlock[1].diskID = id ? id : &__CARDDiskNone;
}

#pragma dont_inline on
s32 __CARDGetControlBlock(s32 chan, CARDControl** pcard) {
    BOOL enabled;
    s32 result;
    CARDControl* card;

    card = &__CARDBlock[chan];

    if (chan < 0 || chan >= 2 || card->diskID == 0) {
        return CARD_RESULT_FATAL_ERROR;
    }

    enabled = OSDisableInterrupts();

    if (!card->attached) {
        result = CARD_RESULT_NOCARD;
    } else if (card->result == CARD_RESULT_BUSY) {
        result = CARD_RESULT_BUSY;
    } else {
        card->result = CARD_RESULT_BUSY;
        result = CARD_RESULT_READY;
        card->apiCallback = NULL;
        *pcard = card;
    }

    OSRestoreInterrupts(enabled);
    return result;
}
#pragma dont_inline off

#pragma dont_inline on
s32 __CARDPutControlBlock(CARDControl* card, s32 result) {
    BOOL enabled;

    enabled = OSDisableInterrupts();
    if (card->attached) {
        card->result = result;
    } else if (card->result == CARD_RESULT_BUSY) {
        card->result = result;
    }

    OSRestoreInterrupts(enabled);
    return result;
}
#pragma dont_inline off

#pragma dont_inline on
s32 CARDGetResultCode(s32 chan) {
    CARDControl* card;

    if (chan < 0 || chan >= 2) {
        return CARD_RESULT_FATAL_ERROR;
    }
    card = &__CARDBlock[chan];
    return card->result;
}
#pragma dont_inline off

s32 CARDFreeBlocks(s32 chan, s32* byteNotUsed, s32* filesNotUsed) {
    CARDControl* card;
    s32 result;
    u16* fat;
    CARDDir* dir;
    CARDDir* ent;
    u16 fileNo;

    result = __CARDGetControlBlock(chan, &card);
    if (result < 0) {
        return result;
    }

    fat = __CARDGetFatBlock(card);
    dir = __CARDGetDirBlock(card);
    if (fat == 0 || dir == 0) {
        return __CARDPutControlBlock(card, CARD_RESULT_BROKEN);
    }

    if (byteNotUsed) {
        *byteNotUsed = (s32)(card->sectorSize * fat[CARD_FAT_FREEBLOCKS]);
    }

    if (filesNotUsed) {
        *filesNotUsed = 0;
        for (fileNo = 0; fileNo < CARD_MAX_FILE; fileNo++) {
            ent = &dir[fileNo];
            if (ent->fileName[0] == 0xff) {
                ++*filesNotUsed;
            }
        }
    }

    return __CARDPutControlBlock(card, CARD_RESULT_READY);
}

#pragma dont_inline on
s32 __CARDSync(s32 chan) {
    CARDControl* block;
    s32 result;
    s32 enabled;

    block = &__CARDBlock[chan];
    enabled = OSDisableInterrupts();
    while ((result = CARDGetResultCode(chan)) == CARD_RESULT_BUSY) {
        OSSleepThread(&block->threadQueue);
    }

    OSRestoreInterrupts(enabled);
    return result;
}
#pragma dont_inline off

BOOL fn_803E30BC(BOOL final) {
    if (!final) {
        if (CARDUnmount(0) == CARD_RESULT_BUSY || CARDUnmount(1) == CARD_RESULT_BUSY) {
            return FALSE;
        }
    }

    return TRUE;
}

static u8 CardData[352] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x21, 0x02, 0xFF, 0x00, 0x21, 0x13, 0x06, 0x12, 0x03, 0x12, 0x04,
    0x13, 0x05, 0x00, 0x92, 0x00, 0xFF, 0x00, 0x88, 0xFF, 0xFF, 0x00, 0x89, 0xFF, 0xFF, 0x00, 0x8A, 0xFF, 0xFF, 0x00,
    0x8B, 0xFF, 0xFF, 0x8F, 0x00, 0x02, 0xBF, 0x00, 0x88, 0x16, 0xFC, 0xDC, 0xD1, 0x16, 0xFD, 0x00, 0x00, 0x16, 0xFB,
    0x00, 0x01, 0x02, 0xBF, 0x00, 0x8E, 0x25, 0xFF, 0x03, 0x80, 0xFF, 0x00, 0x02, 0x94, 0x00, 0x27, 0x02, 0xBF, 0x00,
    0x8E, 0x1F, 0xDF, 0x24, 0xFF, 0x02, 0x40, 0x0F, 0xFF, 0x00, 0x98, 0x04, 0x00, 0x00, 0x9A, 0x00, 0x10, 0x00, 0x99,
    0x00, 0x00, 0x8E, 0x00, 0x02, 0xBF, 0x00, 0x94, 0x02, 0xBF, 0x86, 0x44, 0x02, 0xBF, 0x00, 0x88, 0x16, 0xFC, 0xDC,
    0xD1, 0x16, 0xFD, 0x00, 0x03, 0x16, 0xFB, 0x00, 0x01, 0x8F, 0x00, 0x02, 0xBF, 0x00, 0x8E, 0x03, 0x80, 0xCD, 0xD1,
    0x02, 0x94, 0x00, 0x48, 0x27, 0xFF, 0x03, 0x80, 0x00, 0x01, 0x02, 0x95, 0x00, 0x5A, 0x03, 0x80, 0x00, 0x02, 0x02,
    0x95, 0x80, 0x00, 0x02, 0x9F, 0x00, 0x48, 0x00, 0x21, 0x8E, 0x00, 0x02, 0xBF, 0x00, 0x8E, 0x25, 0xFF, 0x02, 0xBF,
    0x00, 0x8E, 0x25, 0xFF, 0x02, 0xBF, 0x00, 0x8E, 0x25, 0xFF, 0x02, 0xBF, 0x00, 0x8E, 0x00, 0xC5, 0xFF, 0xFF, 0x03,
    0x40, 0x0F, 0xFF, 0x1C, 0x9F, 0x02, 0xBF, 0x00, 0x8E, 0x00, 0xC7, 0xFF, 0xFF, 0x02, 0xBF, 0x00, 0x8E, 0x00, 0xC6,
    0xFF, 0xFF, 0x02, 0xBF, 0x00, 0x8E, 0x00, 0xC0, 0xFF, 0xFF, 0x02, 0xBF, 0x00, 0x8E, 0x20, 0xFF, 0x03, 0x40, 0x0F,
    0xFF, 0x1F, 0x5F, 0x02, 0xBF, 0x00, 0x8E, 0x21, 0xFF, 0x02, 0xBF, 0x00, 0x8E, 0x23, 0xFF, 0x12, 0x05, 0x12, 0x06,
    0x02, 0x9F, 0x80, 0xB5, 0x00, 0x21, 0x27, 0xFC, 0x03, 0xC0, 0x80, 0x00, 0x02, 0x9D, 0x00, 0x88, 0x02, 0xDF, 0x27,
    0xFE, 0x03, 0xC0, 0x80, 0x00, 0x02, 0x9C, 0x00, 0x8E, 0x02, 0xDF, 0x2E, 0xCE, 0x2C, 0xCF, 0x00, 0xF8, 0xFF, 0xCD,
    0x00, 0xF9, 0xFF, 0xC9, 0x00, 0xFA, 0xFF, 0xCB, 0x26, 0xC9, 0x02, 0xC0, 0x00, 0x04, 0x02, 0x9D, 0x00, 0x9C, 0x02,
    0xDF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

static u32 next = 1;

static inline u32 exnor_1st(u32 data, u32 rshift) {
    u32 wk;
    u32 work;
    u32 i;

    work = data;
    for (i = 0; i < rshift; i++) {
        wk = ~(work ^ (work >> 7) ^ (work >> 15) ^ (work >> 23));
        work = (work >> 1) | ((wk << 30) & 0x40000000);
    }

    return work;
}

static inline u32 exnor(u32 data, u32 lshift) {
    u32 wk;
    u32 work;
    u32 i;

    work = data;
    for (i = 0; i < lshift; i++) {
        wk = ~(work ^ (work << 7) ^ (work << 15) ^ (work << 23));
        work = (work << 1) | ((wk >> 30) & 0x00000002);
    }

    return work;
}

u32 fn_803E310C(u32 data) {
    u32 wk;
    u32 i;
    u32 k = 0;
    u32 j = 1;

    wk = 0;
    for (i = 0; i < 32; i++) {
        if (i > 15) {
            if (i == 31)
                wk |= (((data & (0x01 << 31)) >> 31) & 0x01);
            else {
                wk |= ((data & (0x01 << i)) >> j);
                j += 2;
            }
        } else {
            wk |= ((data & (0x01 << i)) << (31 - i - k));
            k++;
        }
    }

    return wk;
}

#define SEC_AD1(x) ((u8)(((x) >> 29) & 0x03))
#define SEC_AD2(x) ((u8)(((x) >> 21) & 0xff))
#define SEC_AD3(x) ((u8)(((x) >> 19) & 0x03))
#define SEC_BA(x) ((u8)(((x) >> 12) & 0x7f))

s32 fn_803E3278(s32 chan, u32 data, void* rbuf, s32 rlen, int mode) {
    CARDControl* card;
    BOOL err;
    u8 cmd[5];

    card = &__CARDBlock[chan];
    if (!EXISelect(chan, 0, EXI_FREQ_16M))
        return CARD_RESULT_NOCARD;

    data &= 0xfffff000;
    memset(cmd, 0, 5);
    cmd[0] = 0x52;
    if (mode == 0) {
        cmd[1] = SEC_AD1(data);
        cmd[2] = SEC_AD2(data);
        cmd[3] = SEC_AD3(data);
        cmd[4] = SEC_BA(data);
    } else {
        cmd[1] = (u8)((data & 0xff000000) >> 24);
        cmd[2] = (u8)((data & 0x00ff0000) >> 16);
    }

    err = FALSE;
    err |= !EXIImmEx(chan, cmd, 5, 1);
    err |= !EXIImmEx(chan, (u8*)card->workArea + (u32)sizeof(CARDID), card->latency, 1);
    err |= !EXIImmEx(chan, rbuf, rlen, 0);
    err |= !EXIDeselect(chan);

    return err ? CARD_RESULT_NOCARD : CARD_RESULT_READY;
}

static inline u32 GetInitVal(void) {
    u32 tmp;
    u32 tick;

    tick = OSGetTick();
    next = tick;
    tmp = 0x7fec8000;
    next = (next * 0x41C64E6D) + 0x3039;
    tmp |= (next / 0x10000) & 0x7FFF;
    tmp &= 0xfffff000;
    return tmp;
}

s32 fn_803E33BC(void) {
    u32 tick;
    u32 wk;
    s32 tmp;
    u32 max;

    wk = 1;
    max = 0;
    tick = OSGetTick();
    next = tick;

    next = (next * 0x41C64E6D) + 0x3039;
    tmp = (next / 0x10000) & 0x7FFF;
    tmp &= 0x0000001f;
    tmp += 1;
    while ((tmp < 4) && (max < 10)) {
        tick = OSGetTick();
        tmp = (s32)(tick << wk);
        wk++;
        if (wk > 16)
            wk = 1;
        next = (u32)tmp;
        next = (next * 0x41C64E6D) + 0x3039;
        tmp = (next / 0x10000) & 0x7FFF;
        tmp &= 0x0000001f;
        tmp += 1;
        max++;
    }

    if (tmp < 4)
        tmp = 4;

    return tmp;
}

void fn_803E3FD8(void* _task);
void fn_803E4048(void* _task);
extern void __CARDMountCallback(s32 chan, s32 result);

s32 __CARDUnlock(s32 chan, u8 flashID[12]) {
    u32 init_val;
    u32 data;

    s32 dummy;
    s32 rlen;
    u32 rshift;

    u32 wk, wk1;
    u32 Ans1 = 0;
    u32* dp;
    u8 rbuf[64];
    u32 para1A = 0;
    u32 para1B = 0;
    u32 para2A = 0;
    u32 para2B = 0;

    CARDControl* card;
    DSPTaskInfo* task;
    CARDDecParam* param;
    u8* input;
    u8* output;

    card = &__CARDBlock[chan];
    task = &card->task;
    param = (CARDDecParam*)card->workArea;
    input = (u8*)((u8*)param + sizeof(CARDDecParam));
    input = (u8*)OSRoundUp32B(input);
    output = input + 32;

    init_val = GetInitVal();

    dummy = fn_803E33BC();
    rlen = dummy;
    if (fn_803E3278(chan, init_val, rbuf, rlen, 0) < 0)
        return CARD_RESULT_NOCARD;

    rshift = (u32)(dummy * 8 + 1);
    wk = exnor_1st(init_val, rshift);
    wk1 = ~(wk ^ (wk >> 7) ^ (wk >> 15) ^ (wk >> 23));
    card->scramble = (wk | ((wk1 << 31) & 0x80000000));
    card->scramble = fn_803E310C(card->scramble);
    dummy = fn_803E33BC();
    rlen = 20 + dummy;
    data = 0;
    if (fn_803E3278(chan, data, rbuf, rlen, 1) < 0)
        return CARD_RESULT_NOCARD;

    dp = (u32*)rbuf;
    para1A = *dp++;
    para1B = *dp++;
    Ans1 = *dp++;
    para2A = *dp++;
    para2B = *dp++;
    para1A = (para1A ^ card->scramble);
    rshift = 32;
    wk = exnor(card->scramble, rshift);
    wk1 = ~(wk ^ (wk << 7) ^ (wk << 15) ^ (wk << 23));
    card->scramble = (wk | ((wk1 >> 31) & 0x00000001));

    para1B = (para1B ^ card->scramble);
    rshift = 32;
    wk = exnor(card->scramble, rshift);
    wk1 = ~(wk ^ (wk << 7) ^ (wk << 15) ^ (wk << 23));
    card->scramble = (wk | ((wk1 >> 31) & 0x00000001));

    Ans1 ^= card->scramble;
    rshift = 32;
    wk = exnor(card->scramble, rshift);
    wk1 = ~(wk ^ (wk << 7) ^ (wk << 15) ^ (wk << 23));
    card->scramble = (wk | ((wk1 >> 31) & 0x00000001));

    para2A = (para2A ^ card->scramble);
    rshift = 32;
    wk = exnor(card->scramble, rshift);
    wk1 = ~(wk ^ (wk << 7) ^ (wk << 15) ^ (wk << 23));
    card->scramble = (wk | ((wk1 >> 31) & 0x00000001));

    para2B = (para2B ^ card->scramble);
    rshift = (u32)(dummy * 8);
    wk = exnor(card->scramble, rshift);
    wk1 = ~(wk ^ (wk << 7) ^ (wk << 15) ^ (wk << 23));
    card->scramble = (wk | ((wk1 >> 31) & 0x00000001));

    rshift = 32 + 1;
    wk = exnor(card->scramble, rshift);
    wk1 = ~(wk ^ (wk << 7) ^ (wk << 15) ^ (wk << 23));
    card->scramble = (wk | ((wk1 >> 31) & 0x00000001));

    *(u32*)&input[0] = para2A;
    *(u32*)&input[4] = para2B;

    param->inputAddr = input;
    param->inputLength = 8;
    param->outputAddr = output;
    param->aramAddr = 0;

    DCFlushRange(input, 8);
    DCInvalidateRange(output, 4);
    DCFlushRange(param, sizeof(CARDDecParam));

    task->priority = 255;
    task->iram_mmem_addr = (u16*)OSCachedToPhysical(CardData);
    task->iram_length = 0x160;
    task->iram_addr = 0;
    task->dsp_init_vector = 0x10;
    task->init_cb = fn_803E3FD8;
    task->res_cb = NULL;
    task->done_cb = fn_803E4048;
    task->req_cb = NULL;
    DSPAddTask(task);

    dp = (u32*)flashID;
    *dp++ = para1A;
    *dp++ = para1B;
    *dp = Ans1;

    return CARD_RESULT_READY;
}

void fn_803E3FD8(void* _task) {
    s32 chan;
    CARDControl* card;
    DSPTaskInfo* task;
    CARDDecParam* param;

    task = _task;
    for (chan = 0; chan < 2; ++chan) {
        card = &__CARDBlock[chan];
        if ((DSPTaskInfo*)&card->task == task)
            break;
    }

    param = (CARDDecParam*)card->workArea;

    DSPSendMailToDSP(0xff000000);
    while (DSPCheckMailToDSP())
        ;

    DSPSendMailToDSP((u32)param);
    while (DSPCheckMailToDSP())
        ;
}

void fn_803E4048(void* _task) {
    u8 rbuf[64];
    u32 data;
    s32 dummy;
    s32 rlen;
    u32 rshift;

    u8 unk;
    u32 wk, wk1;
    u32 Ans2;

    s32 chan;
    CARDControl* card;
    s32 result;
    DSPTaskInfo* task;
    CARDDecParam* param;

    u8* input;
    u8* output;
    task = _task;
    for (chan = 0; chan < 2; ++chan) {
        card = &__CARDBlock[chan];
        if ((DSPTaskInfo*)&card->task == task)
            break;
    }

    param = (CARDDecParam*)card->workArea;
    input = (u8*)((u8*)param + sizeof(CARDDecParam));
    input = (u8*)OSRoundUp32B(input);
    output = input + 32;

    Ans2 = *(u32*)output;
    dummy = fn_803E33BC();
    rlen = dummy;
    data = ((Ans2 ^ card->scramble) & 0xffff0000);
    if (fn_803E3278(chan, data, rbuf, rlen, 1) < 0) {
        EXIUnlock(chan);
        __CARDMountCallback(chan, CARD_RESULT_NOCARD);
        return;
    }

    rshift = (u32)((dummy + 4 + card->latency) * 8 + 1);
    wk = exnor(card->scramble, rshift);
    wk1 = ~(wk ^ (wk << 7) ^ (wk << 15) ^ (wk << 23));
    card->scramble = (wk | ((wk1 >> 31) & 0x00000001));

    dummy = fn_803E33BC();
    rlen = dummy;
    data = (((Ans2 << 16) ^ card->scramble) & 0xffff0000);
    if (fn_803E3278(chan, data, rbuf, rlen, 1) < 0) {
        EXIUnlock(chan);
        __CARDMountCallback(chan, CARD_RESULT_NOCARD);
        return;
    }

    result = __CARDReadStatus(chan, &unk);
    if (!EXIProbe(chan)) {
        EXIUnlock(chan);
        __CARDMountCallback(chan, CARD_RESULT_NOCARD);
        return;
    }

    if (result == CARD_RESULT_READY && !(unk & 0x40)) {
        EXIUnlock(chan);
        result = CARD_RESULT_IOERROR;
    }

    __CARDMountCallback(chan, result);
}

void fn_803E436C(s32 chan, s32 result) {
    CARDControl* card;
    CARDCallback callback;

    card = &__CARDBlock[chan];

    if ((result >= 0)) {
        card->xferred += 0x200;
        card->addr += 0x200;
        card->buffer = (u8*)card->buffer + 0x200;

        if (--card->repeat > 0) {
            result = __CARDReadSegment(chan, fn_803E436C);
            if (result >= 0) {
                return;
            }
        }
    }

    if (!card->apiCallback) {
        __CARDPutControlBlock(card, result);
    }

    callback = card->xferCallback;
    if (callback) {
        card->xferCallback = NULL;
        callback(chan, result);
    }
}

#pragma dont_inline on
s32 __CARDRead(s32 chan, u32 addr, s32 length, void* dst, CARDCallback callback) {
    CARDControl* card;

    card = &__CARDBlock[chan];
    if (card->attached == 0) {
        return CARD_RESULT_NOCARD;
    }
    card->xferCallback = callback;
    card->repeat = (length / 512u);
    card->addr = addr;
    card->buffer = dst;
    return __CARDReadSegment(chan, fn_803E436C);
}
#pragma dont_inline off

void fn_803E44AC(s32 chan, s32 result) {
    CARDControl* card;
    CARDCallback callback;

    card = &__CARDBlock[chan];
    if (result >= 0) {
        card->xferred += card->pageSize;
        card->addr += card->pageSize;
        card->buffer = (u8*)card->buffer + card->pageSize;

        if (--card->repeat > 0) {
            result = __CARDWritePage(chan, fn_803E44AC);
            if (result >= 0) {
                return;
            }
        }
    }

    if (!card->apiCallback) {
        __CARDPutControlBlock(card, result);
    }

    callback = card->xferCallback;
    if (callback) {
        card->xferCallback = NULL;
        callback(chan, result);
    }
}

#pragma dont_inline on
s32 __CARDWrite(s32 chan, u32 addr, s32 length, void* dst, CARDCallback callback) {
    CARDControl* card;
    card = &__CARDBlock[chan];

    if (card->attached == 0) {
        return CARD_RESULT_NOCARD;
    }
    card->xferCallback = callback;
    card->repeat = (length / card->pageSize);
    card->addr = addr;
    card->buffer = dst;
    return __CARDWritePage(chan, fn_803E44AC);
}
#pragma dont_inline off

void* fn_803E45EC(CARDControl* card) {
    return card->currentFat;
}

void fn_803E45F4(s32 chan, s32 result) {
    CARDControl* card;
    CARDCallback callback;
    u16* fat0;
    u16* fat1;

    card = &__CARDBlock[chan];

    if (result >= 0) {
        fat0 = (u16*)((u8*)card->workArea + 0x6000);
        fat1 = (u16*)((u8*)card->workArea + 0x8000);

        if (card->currentFat == fat0) {
            card->currentFat = fat1;
            memcpy(fat1, fat0, 0x2000);
        } else {
            card->currentFat = fat0;
            memcpy(fat0, fat1, 0x2000);
        }
    }

    if (!card->apiCallback)
        __CARDPutControlBlock(card, result);

    callback = card->eraseCallback;
    if (callback) {
        card->eraseCallback = NULL;
        callback(chan, result);
    }
}

void fn_803E46C8(s32 chan, s32 result) {
    CARDControl* card = &__CARDBlock[chan];
    CARDCallback callback;
    u16* fat;
    u32 addr;

    if (result < 0)
        goto error;

    fat = fn_803E45EC(card);
    addr = ((u32)fat - (u32)card->workArea) / CARD_SYSTEM_BLOCK_SIZE * card->sectorSize;
    result = __CARDWrite(chan, addr, CARD_SYSTEM_BLOCK_SIZE, fat, fn_803E45F4);
    if (result < 0)
        goto error;

    return;

error:
    if (!card->apiCallback)
        __CARDPutControlBlock(card, result);

    callback = card->eraseCallback;
    if (callback) {
        card->eraseCallback = NULL;
        callback(chan, result);
    }
}

#pragma dont_inline on
s32 __CARDAllocBlock(s32 chan, u32 cBlock, CARDCallback callback) {
    CARDControl* card;
    u16* fat;
    u16 iBlock;
    u16 startBlock;
    u16 prevBlock;
    u16 count;

    card = &__CARDBlock[chan];
    if (!card->attached)
        return CARD_RESULT_NOCARD;

    fat = card->currentFat;
    if (fat[3] < cBlock)
        return CARD_RESULT_INSSPACE;

    fat[3] -= cBlock;
    startBlock = 0xFFFF;
    iBlock = fat[4];
    count = 0;
    while (0 < cBlock) {
        if (card->cBlock - 5 < ++count)
            return CARD_RESULT_BROKEN;

        iBlock++;
        if (!CARDIsValidBlockNo(card, iBlock))
            iBlock = 5;

        if (fat[iBlock] == 0x0000u) {
            if (startBlock == 0xFFFF)
                startBlock = iBlock;
            else
                fat[prevBlock] = iBlock;
            prevBlock = iBlock;
            fat[iBlock] = 0xFFFF;
            --cBlock;
        }
    }

    fat[4] = iBlock;
    card->startBlock = startBlock;
    return __CARDUpdateFatBlock(chan, fat, callback);
}
#pragma dont_inline off

#pragma dont_inline on
s32 __CARDFreeBlock(s32 chan, u16 nBlock, CARDCallback callback) {
    CARDControl* card;
    u16* fat;
    u16 nextBlock;

    card = &__CARDBlock[chan];
    if (!card->attached)
        return CARD_RESULT_NOCARD;

    fat = card->currentFat;
    while (nBlock != 0xFFFF) {
        if (!CARDIsValidBlockNo(card, nBlock))
            return CARD_RESULT_BROKEN;

        nextBlock = fat[nBlock];
        fat[nBlock] = 0;
        nBlock = nextBlock;
        ++fat[3];
    }

    return __CARDUpdateFatBlock(chan, fat, callback);
}
#pragma dont_inline off

#pragma dont_inline on
s32 __CARDUpdateFatBlock(s32 chan, u16* fat, CARDCallback callback) {
    CARDControl* card;
    u32 addr;

    card = &__CARDBlock[chan];
    ++fat[2];
    __CARDCheckSum(fat + 2, 0x1FFC, fat, fat + 1);
    DCStoreRange(fat, 0x2000);
    card->eraseCallback = callback;
    addr = (((char*)fat - (char*)card->workArea) / 8192u) * card->sectorSize;
    return __CARDEraseSector(chan, addr, fn_803E46C8);
}
#pragma dont_inline off

#pragma dont_inline on
CARDDir* kar_diagnostic__803e49f0(CARDControl* card) {
    return card->currentDir;
}
#pragma dont_inline off

void fn_803E49F8(s32 chan, s32 result) {
    CARDControl* card = &__CARDBlock[chan];
    CARDCallback callback;

    if (result >= 0) {
        CARDDir* dir0 = (CARDDir*)((u8*)card->workArea + 0x2000);
        CARDDir* dir1 = (CARDDir*)((u8*)card->workArea + 0x4000);

        if (card->currentDir == dir0) {
            card->currentDir = dir1;
            memcpy(dir1, dir0, 0x2000);
        } else {
            card->currentDir = dir0;
            memcpy(dir0, dir1, 0x2000);
        }
    }

    if (!card->apiCallback)
        __CARDPutControlBlock(card, result);

    callback = card->eraseCallback;
    if (callback) {
        card->eraseCallback = NULL;
        callback(chan, result);
    }
}

void fn_803E4AC8(s32 chan, s32 result) {
    CARDControl* card = &__CARDBlock[chan];
    CARDCallback callback;
    CARDDir* dir;
    u32 addr;

    if (result >= 0) {
        dir = kar_diagnostic__803e49f0(card);
        addr = ((u32)dir - (u32)card->workArea) / 0x2000 * card->sectorSize;
        result = __CARDWrite(chan, addr, 0x2000, dir, fn_803E49F8);
        if (result >= 0)
            return;
    }

    if (!card->apiCallback)
        __CARDPutControlBlock(card, result);

    callback = card->eraseCallback;
    if (callback) {
        card->eraseCallback = NULL;
        callback(chan, result);
    }
}

#pragma dont_inline on
s32 __CARDUpdateDir(s32 chan, CARDCallback callback) {
    CARDControl* card;
    CARDDirCheck* check;
    u32 addr;
    CARDDir* dir;

    card = &__CARDBlock[chan];
    if (!card->attached)
        return CARD_RESULT_NOCARD;

    dir = card->currentDir;
    check = CARDGetDirCheck(dir);
    ++check->checkCode;
    __CARDCheckSum(dir, 0x2000 - sizeof(u32), &check->checkSum, &check->checkSumInv);
    DCStoreRange(dir, 0x2000);

    card->eraseCallback = callback;
    addr = ((u32)dir - (u32)card->workArea) / 0x2000 * card->sectorSize;
    return __CARDEraseSector(chan, addr, fn_803E4AC8);
}
#pragma dont_inline off

#pragma dont_inline on
void __CARDCheckSum(void* ptr, int length, u16* checksum, u16* checksumInv) {
    u16* p;
    int i;

    length /= sizeof(u16);
    *checksum = *checksumInv = 0;
    for (i = 0, p = ptr; i < length; i++, p++) {
        *checksum += *p;
        *checksumInv += ~*p;
    }

    if (*checksum == 0xFFFF)
        *checksum = 0;

    if (*checksumInv == 0xFFFF)
        *checksumInv = 0;
}
#pragma dont_inline off

s32 kar_diagnostic__near_803e4e04(CARDControl* card) {
    CARDID* id;
    u16 checksum;
    u16 checksumInv;
    OSSramEx* sramEx;
    OSTime rand;
    int i;

    id = card->workArea;

    if (id->deviceID != 0 || id->size != card->size)
        return CARD_RESULT_BROKEN;

    __CARDCheckSum(id, sizeof(CARDID) - sizeof(u32), &checksum, &checksumInv);
    if (id->checkSum != checksum || id->checkSumInv != checksumInv)
        return CARD_RESULT_BROKEN;

    rand = *(OSTime*)&id->serial[12];
    sramEx = __OSLockSramEx();
    for (i = 0; i < 12; i++) {
        rand = (rand * 1103515245 + 12345) >> 16;
        if (id->serial[i] != (u8)(sramEx->flashID[card - __CARDBlock][i] + rand)) {
            __OSUnlockSramEx(FALSE);
            return CARD_RESULT_BROKEN;
        }
        rand = ((rand * 1103515245 + 12345) >> 16) & 0x7FFF;
    }

    __OSUnlockSramEx(FALSE);

    if (id->encode != __CARDGetFontEncode())
        return CARD_RESULT_ENCODING;

    return CARD_RESULT_READY;
}

s32 kar_diagnostic__near_803e5088(CARDControl* card, int* pcurrent) {
    CARDDir* dir[2];
    CARDDirCheck* check[2];
    u16 checkSum;
    u16 checkSumInv;
    int i;
    int errors;
    int current;

    current = errors = 0;
    for (i = 0; i < 2; i++) {
        dir[i] = (CARDDir*)((u8*)card->workArea + (1 + i) * CARD_SYSTEM_BLOCK_SIZE);
        check[i] = CARDGetDirCheck(dir[i]);
        __CARDCheckSum(dir[i], CARD_SYSTEM_BLOCK_SIZE - sizeof(u32), &checkSum, &checkSumInv);
        if (check[i]->checkSum != checkSum || check[i]->checkSumInv != checkSumInv) {
            ++errors;
            current = i;
            card->currentDir = 0;
        }
    }

    if (0 == errors) {
        if (card->currentDir == 0) {
            if ((check[0]->checkCode - check[1]->checkCode) < 0)
                current = 0;
            else
                current = 1;
            card->currentDir = dir[current];
            memcpy(dir[current], dir[current ^ 1], CARD_SYSTEM_BLOCK_SIZE);
        } else {
            current = (card->currentDir == dir[0]) ? 0 : 1;
        }
    }

    if (pcurrent)
        *pcurrent = current;

    return errors;
}

s32 kar_diagnostic__near_803e52c8(CARDControl* card, int* pcurrent) {
    u16* fat[2];
    u16* fatp;
    u16 nBlock;
    u16 cFree;
    int i;
    u16 checkSum;
    u16 checkSumInv;
    int errors;
    int current;

    current = errors = 0;
    for (i = 0; i < 2; i++) {
        fatp = fat[i] = (u16*)((u8*)card->workArea + (3 + i) * CARD_SYSTEM_BLOCK_SIZE);

        __CARDCheckSum(&fatp[CARD_FAT_CHECKCODE], CARD_SYSTEM_BLOCK_SIZE - sizeof(u32), &checkSum, &checkSumInv);
        if (fatp[0] != checkSum || fatp[CARD_FAT_CHECKSUMINV] != checkSumInv) {
            ++errors;
            current = i;
            card->currentFat = 0;
            continue;
        }

        cFree = 0;
        for (nBlock = CARD_NUM_SYSTEM_BLOCK; nBlock < card->cBlock; nBlock++) {
            if (fatp[nBlock] == 0)
                cFree++;
        }

        if (cFree != fatp[CARD_FAT_FREEBLOCKS]) {
            ++errors;
            current = i;
            card->currentFat = 0;
            continue;
        }
    }

    if (0 == errors) {
        if (card->currentFat == 0) {
            if (((s16)fat[0][CARD_FAT_CHECKCODE] - (s16)fat[1][CARD_FAT_CHECKCODE]) < 0)
                current = 0;
            else
                current = 1;
            card->currentFat = fat[current];
            memcpy(fat[current], fat[current ^ 1], CARD_SYSTEM_BLOCK_SIZE);
        } else
            current = (card->currentFat == fat[0]) ? 0 : 1;
    }

    if (pcurrent)
        *pcurrent = current;

    return errors;
}

#pragma dont_inline on
s32 __CARDVerify(CARDControl* card) {
    s32 result;
    int errors;

    result = kar_diagnostic__near_803e4e04(card);
    if (result < 0)
        return result;

    errors = kar_diagnostic__near_803e5088(card, NULL);
    errors += kar_diagnostic__near_803e52c8(card, NULL);
    switch (errors) {
    case 0:
        return CARD_RESULT_READY;
    case 1:
        return CARD_RESULT_BROKEN;
    default:
        return CARD_RESULT_BROKEN;
    }
}
#pragma dont_inline off

s32 CARDCheckExAsync(s32 chan, s32* xferBytes, CARDCallback callback) {
    CARDControl* card;
    CARDDir* dir[2];
    u16* fat[2];
    u16* map;
    s32 result;
    int errors;
    int currentFat;
    int currentDir;
    s32 fileNo;
    u16 iBlock;
    u16 cBlock;
    u16 cFree;
    BOOL updateFat = FALSE;
    BOOL updateDir = FALSE;
    BOOL updateOrphan = FALSE;

    if (xferBytes) {
        *xferBytes = 0;
    }

    result = __CARDGetControlBlock(chan, &card);
    if (result < 0) {
        return result;
    }

    result = kar_diagnostic__near_803e4e04(card);
    if (result < 0) {
        return __CARDPutControlBlock(card, result);
    }

    errors = kar_diagnostic__near_803e5088(card, &currentDir);
    errors += kar_diagnostic__near_803e52c8(card, &currentFat);
    if (1 < errors) {
        return __CARDPutControlBlock(card, CARD_RESULT_BROKEN);
    }

    dir[0] = (CARDDir*)((u8*)card->workArea + (1 + 0) * CARD_SYSTEM_BLOCK_SIZE);
    dir[1] = (CARDDir*)((u8*)card->workArea + (1 + 1) * CARD_SYSTEM_BLOCK_SIZE);
    fat[0] = (u16*)((u8*)card->workArea + (3 + 0) * CARD_SYSTEM_BLOCK_SIZE);
    fat[1] = (u16*)((u8*)card->workArea + (3 + 1) * CARD_SYSTEM_BLOCK_SIZE);

    switch (errors) {
    case 0:
        break;
    case 1:
        if (!card->currentDir) {
            card->currentDir = dir[currentDir];
            memcpy(dir[currentDir], dir[currentDir ^ 1], CARD_SYSTEM_BLOCK_SIZE);
            updateDir = TRUE;
        } else {
            card->currentFat = fat[currentFat];
            memcpy(fat[currentFat], fat[currentFat ^ 1], CARD_SYSTEM_BLOCK_SIZE);
            updateFat = TRUE;
        }
        break;
    }

    map = fat[currentFat ^ 1];
    memset(map, 0, CARD_SYSTEM_BLOCK_SIZE);

    for (fileNo = 0; fileNo < CARD_MAX_FILE; fileNo++) {
        CARDDir* ent;

        ent = &card->currentDir[fileNo];
        if (ent->gameName[0] == 0xff) {
            continue;
        }

        for (iBlock = ent->startBlock, cBlock = 0; iBlock != 0xFFFF && cBlock < ent->length;
             iBlock = card->currentFat[iBlock], ++cBlock)
        {
            if (!CARDIsValidBlockNo(card, iBlock) || 1 < ++map[iBlock]) {
                return __CARDPutControlBlock(card, CARD_RESULT_BROKEN);
            }
        }

        if (cBlock != ent->length || iBlock != 0xFFFF) {
            return __CARDPutControlBlock(card, CARD_RESULT_BROKEN);
        }
    }

    cFree = 0;
    for (iBlock = CARD_NUM_SYSTEM_BLOCK; iBlock < card->cBlock; iBlock++) {
        u16 nextBlock;

        nextBlock = card->currentFat[iBlock];
        if (map[iBlock] == 0) {
            if (nextBlock != 0) {
                card->currentFat[iBlock] = 0;
                updateOrphan = TRUE;
            }
            cFree++;
        } else if (!CARDIsValidBlockNo(card, nextBlock) && nextBlock != 0xFFFF) {
            return __CARDPutControlBlock(card, CARD_RESULT_BROKEN);
        }
    }

    if (cFree != card->currentFat[CARD_FAT_FREEBLOCKS]) {
        card->currentFat[CARD_FAT_FREEBLOCKS] = cFree;
        updateOrphan = TRUE;
    }

    if (updateOrphan) {
        __CARDCheckSum(&card->currentFat[CARD_FAT_CHECKCODE], CARD_SYSTEM_BLOCK_SIZE - sizeof(u32),
                       &card->currentFat[0],
                       &card->currentFat[CARD_FAT_CHECKSUMINV]);
    }

    memcpy(fat[currentFat ^ 1], fat[currentFat], CARD_SYSTEM_BLOCK_SIZE);

    if (updateDir) {
        if (xferBytes) {
            *xferBytes = CARD_SYSTEM_BLOCK_SIZE;
        }
        return __CARDUpdateDir(chan, callback);
    }

    if (updateFat | updateOrphan) {
        if (xferBytes) {
            *xferBytes = CARD_SYSTEM_BLOCK_SIZE;
        }
        return __CARDUpdateFatBlock(chan, card->currentFat, callback);
    }

    __CARDPutControlBlock(card, CARD_RESULT_READY);
    if (callback) {
        BOOL enabled = OSDisableInterrupts();
        callback(chan, CARD_RESULT_READY);
        OSRestoreInterrupts(enabled);
    }
    return CARD_RESULT_READY;
}

s32 CARDCheck(s32 chan) {
    s32 xferBytes;
    s32 result = CARDCheckExAsync(chan, &xferBytes, __CARDSyncCallback);
    if (result < 0 || xferBytes == 0) {
        return result;
    }

    return __CARDSync(chan);
}

static u32 SectorSizeTable[8] = {
    8 * 1024, 16 * 1024, 32 * 1024, 64 * 1024, 128 * 1024, 256 * 1024, 0, 0,
};

static u32 LatencyTable[8] = {
    4, 8, 16, 32, 64, 128, 256, 512,
};

BOOL kar_diagnostic__near_803e5bbc(u32 id) {
    u32 size;
    s32 sectorSize;
    if (id & (0xFFFF0000) && (id != 0x80000004 || __CARDVendorID == 0xFFFF)) {
        return FALSE;
    }

    if ((id & 3) != 0) {
        return FALSE;
    }

    size = id & 0xfc;
    switch (size) {
    case 4:
    case 8:
    case 16:
    case 32:
    case 64:
    case 128:
        break;
    default:
        return FALSE;
    }

    sectorSize = SectorSizeTable[(id & 0x00003800) >> 11];
    if (sectorSize == 0) {
        return FALSE;
    }

    if ((size * 1024 * 1024 / 8) / sectorSize < 8) {
        return FALSE;
    }

    return TRUE;
}

s32 CARDProbeEx(s32 chan, s32* memSize, s32* sectorSize) {
    u32 id;
    CARDControl* card;
    BOOL enabled;
    s32 result;
    int probe;

    if (chan < 0 || 2 <= chan)
        return CARD_RESULT_FATAL_ERROR;

    if (__gUnknown800030E3 & 0x80) {
        return CARD_RESULT_NOCARD;
    }

    card = &__CARDBlock[chan];
    enabled = OSDisableInterrupts();

    probe = EXIProbeEx(chan);
    if (probe == -1)
        result = CARD_RESULT_NOCARD;
    else if (probe == 0)
        result = CARD_RESULT_BUSY;
    else if (card->attached) {
        if (card->mountStep < 1)
            result = CARD_RESULT_BUSY;
        else {
            if (memSize)
                *memSize = card->size;

            if (sectorSize)
                *sectorSize = card->sectorSize;

            result = CARD_RESULT_READY;
        }
    }
    else if ((EXIGetState(chan) & 8))
        result = CARD_RESULT_WRONGDEVICE;
    else if (!EXIGetID(chan, 0, &id))
        result = CARD_RESULT_BUSY;
    else if (kar_diagnostic__near_803e5bbc(id)) {
        if (memSize)
            *memSize = (s32)(id & 0xfc);

        if (sectorSize)
            *sectorSize = SectorSizeTable[(id & 0x00003800) >> 11];
        result = CARD_RESULT_READY;
    } else {
        result = CARD_RESULT_WRONGDEVICE;
    }

    OSRestoreInterrupts(enabled);
    return result;
}

void fn_803E6534(s32 chan, s32 result);

s32 kar_diagnostic__near_803e5e04(s32 chan) {
    CARDControl* card;
    u32 id;
    u8 status;
    s32 result;
    OSSramEx* sram;
    int i;
    u8 checkSum;
    int step;

    card = &__CARDBlock[chan];
    if (card->mountStep == 0) {
        if (EXIGetID(chan, 0, &id) == 0) {
            result = CARD_RESULT_NOCARD;
        } else if (kar_diagnostic__near_803e5bbc(id)) {
            result = CARD_RESULT_READY;
        } else {
            result = CARD_RESULT_WRONGDEVICE;
        }

        if (result < 0)
            goto error;

        card->cid = id;
        card->size = (u16)(id & 0xFC);

        card->sectorSize = SectorSizeTable[(id & 0x00003800) >> 11];

        card->cBlock = (u16)((card->size * 1024 * 1024 / 8) / card->sectorSize);

        card->latency = LatencyTable[(id & 0x00000700) >> 8];

        card->pageSize = 128;

        result = __CARDClearStatus(chan);
        if (result < 0)
            goto error;

        result = __CARDReadStatus(chan, &status);
        if (result < 0)
            goto error;

        if (!EXIProbe(chan)) {
            result = CARD_RESULT_NOCARD;
            goto error;
        }

        if (!(status & 0x40)) {
            result = __CARDUnlock(chan, card->id);
            if (result < 0)
                goto error;

            checkSum = 0;
            sram = __OSLockSramEx();
            for (i = 0; i < 12; i++) {
                sram->flashID[chan][i] = card->id[i];
                checkSum += card->id[i];
            }
            sram->flashIDCheckSum[chan] = (u8)~checkSum;
            __OSUnlockSramEx(TRUE);

            return result;
        } else {
            card->mountStep = 1;

            checkSum = 0;
            sram = __OSLockSramEx();
            for (i = 0; i < 12; i++)
                checkSum += sram->flashID[chan][i];

            __OSUnlockSramEx(FALSE);
            if (sram->flashIDCheckSum[chan] != (u8)~checkSum) {
                result = CARD_RESULT_IOERROR;
                goto error;
            }
        }
    }

    if (card->mountStep == 1) {
        if (card->cid == 0x80000004) {
            u16 vendorID;

            sram = __OSLockSramEx();
            vendorID = *(u16*)sram->flashID[chan];
            __OSUnlockSramEx(FALSE);

            if (__CARDVendorID == 0xFFFF || vendorID != __CARDVendorID) {
                result = CARD_RESULT_WRONGDEVICE;
                goto error;
            }
        }

        card->mountStep = 2;

        result = __CARDEnableInterrupt(chan, TRUE);
        if (result < 0)
            goto error;

        EXISetExiCallback(chan, __CARDExiHandler);
        EXIUnlock(chan);
        DCInvalidateRange(card->workArea, 5 * 8 * 1024);
    }

    step = card->mountStep - 2;
    result = __CARDRead(chan, (u32)card->sectorSize * step, CARD_SYSTEM_BLOCK_SIZE,
                        (u8*)card->workArea + (CARD_SYSTEM_BLOCK_SIZE * step), __CARDMountCallback);
    if (result < 0)
        __CARDPutControlBlock(card, result);
    return result;

error:
    EXIUnlock(chan);
    fn_803E6534(chan, result);
    return result;
}

void __CARDMountCallback(s32 chan, s32 result) {
    CARDControl* card;
    CARDCallback callback;

    card = &__CARDBlock[chan];
    switch (result) {
    case CARD_RESULT_READY:
        if (++card->mountStep < CARD_MAX_MOUNT_STEP) {
            result = kar_diagnostic__near_803e5e04(chan);
            if (0 <= result)
                return;
        } else
            result = __CARDVerify(card);
        break;
    case CARD_RESULT_UNLOCKED:
        card->unlockCallback = __CARDMountCallback;
        if (!EXILock(chan, 0, __CARDUnlockedHandler)) {
            return;
        }
        card->unlockCallback = 0;

        result = kar_diagnostic__near_803e5e04(chan);
        if (result >= 0)
            return;
        break;
    case CARD_RESULT_IOERROR:
    case CARD_RESULT_NOCARD:
        {
            BOOL enabled2 = OSDisableInterrupts();
            if (card->attached) {
                EXISetExiCallback(chan, 0);
                EXIDetach(chan);
                OSCancelAlarm(&card->alarm);
                card->attached = FALSE;
                card->result = result;
                card->mountStep = 0;
            }
            OSRestoreInterrupts(enabled2);
        }
        break;
    }

    callback = card->apiCallback;
    card->apiCallback = NULL;
    __CARDPutControlBlock(card, result);
    callback(chan, result);
}

s32 CARDMountAsync(s32 chan, void* workArea, CARDCallback detachCallback, CARDCallback attachCallback) {
    CARDControl* card;
    BOOL enabled;

    if (chan < 0 || 2 <= chan)
        return CARD_RESULT_FATAL_ERROR;

    if (__gUnknown800030E3 & 0x80) {
        return CARD_RESULT_NOCARD;
    }

    card = &__CARDBlock[chan];

    enabled = OSDisableInterrupts();
    if (card->result == CARD_RESULT_BUSY) {
        OSRestoreInterrupts(enabled);
        return CARD_RESULT_BUSY;
    }

    if (!card->attached && (EXIGetState(chan) & 0x08)) {
        OSRestoreInterrupts(enabled);
        return CARD_RESULT_WRONGDEVICE;
    }

    card->result = CARD_RESULT_BUSY;
    card->workArea = workArea;
    card->extCallback = detachCallback;
    card->apiCallback = attachCallback ? attachCallback : __CARDDefaultApiCallback;
    card->exiCallback = 0;

    if (!card->attached && !EXIAttach(chan, __CARDExtHandler)) {
        card->result = CARD_RESULT_NOCARD;
        OSRestoreInterrupts(enabled);
        return CARD_RESULT_NOCARD;
    }

    card->mountStep = 0;
    card->attached = TRUE;
    EXISetExiCallback(chan, 0);
    OSCancelAlarm(&card->alarm);

    card->currentDir = 0;
    card->currentFat = 0;

    OSRestoreInterrupts(enabled);

    card->unlockCallback = __CARDMountCallback;
    if (!EXILock(chan, 0, __CARDUnlockedHandler))
        return CARD_RESULT_READY;

    card->unlockCallback = 0;
    return kar_diagnostic__near_803e5e04(chan);
}

s32 kar_diagnostic__803e64ec(s32 chan, void* workArea, CARDCallback detachCallback) {
    s32 result = CARDMountAsync(chan, workArea, detachCallback, __CARDSyncCallback);

    if (result < 0)
        return result;
    return __CARDSync(chan);
}

void fn_803E6534(s32 chan, s32 result) {
    CARDControl* card;
    BOOL enabled;

    card = &__CARDBlock[chan];
    enabled = OSDisableInterrupts();
    if (card->attached) {
        EXISetExiCallback(chan, 0);
        EXIDetach(chan);
        OSCancelAlarm(&card->alarm);
        card->attached = FALSE;
        card->result = result;
        card->mountStep = 0;
    }
    OSRestoreInterrupts(enabled);
}

s32 CARDUnmount(s32 chan) {
    CARDControl* card;
    s32 result;
    BOOL enabled;

    result = __CARDGetControlBlock(chan, &card);
    if (result < 0)
        return result;

    enabled = OSDisableInterrupts();
    if (card->attached) {
        EXISetExiCallback(chan, 0);
        EXIDetach(chan);
        OSCancelAlarm(&card->alarm);
        card->attached = FALSE;
        card->result = CARD_RESULT_NOCARD;
        card->mountStep = 0;
    }
    OSRestoreInterrupts(enabled);
    return CARD_RESULT_READY;
}

void fn_803E667C(s32 chan, s32 result) {
    CARDControl* card;
    CARDCallback callback;

    card = &__CARDBlock[chan];
    if (result < 0)
        goto error;

    ++card->formatStep;
    if (card->formatStep < CARD_NUM_SYSTEM_BLOCK) {
        result = __CARDEraseSector(chan, (u32)card->sectorSize * card->formatStep, fn_803E667C);
        if (result >= 0)
            return;
    } else if (card->formatStep < 2 * CARD_NUM_SYSTEM_BLOCK) {
        int step = card->formatStep - CARD_NUM_SYSTEM_BLOCK;
        result = __CARDWrite(chan, (u32)card->sectorSize * step, CARD_SYSTEM_BLOCK_SIZE,
                             (u8*)card->workArea + (CARD_SYSTEM_BLOCK_SIZE * step), fn_803E667C);
        if (result >= 0)
            return;
    } else {
        card->currentDir = (CARDDir*)((u8*)card->workArea + (1 + 0) * CARD_SYSTEM_BLOCK_SIZE);
        memcpy(card->currentDir, (u8*)card->workArea + (1 + 1) * CARD_SYSTEM_BLOCK_SIZE, CARD_SYSTEM_BLOCK_SIZE);
        card->currentFat = (u16*)((u8*)card->workArea + (3 + 0) * CARD_SYSTEM_BLOCK_SIZE);
        memcpy(card->currentFat, (u8*)card->workArea + (3 + 1) * CARD_SYSTEM_BLOCK_SIZE, CARD_SYSTEM_BLOCK_SIZE);
    }

error:
    callback = card->apiCallback;
    card->apiCallback = NULL;
    __CARDPutControlBlock(card, result);
    callback(chan, result);
}

s32 __CARDFormatRegionAsync(s32 chan, u16 encode, CARDCallback callback) {
    CARDControl* card;
    CARDID* id;
    CARDDir* dir;
    u16* fat;
    s16 i;
    s32 result;
    OSSram* sram;
    OSSramEx* sramEx;
    u16 dvdstatus;
    OSTime time;
    OSTime rand;

    result = __CARDGetControlBlock(chan, &card);
    if (result < 0)
        return result;

    id = (CARDID*)card->workArea;
    memset(id, 0xff, CARD_SYSTEM_BLOCK_SIZE);
    dvdstatus = __VIRegs[55];

    id->encode = encode;
    sram = __OSLockSram();
    *(u32*)&id->serial[20] = sram->counterBias;
    *(u32*)&id->serial[24] = sram->language;
    __OSUnlockSram(FALSE);

    rand = time = OSGetTime();

    sramEx = __OSLockSramEx();
    for (i = 0; i < 12; i++) {
        rand = (rand * 1103515245 + 12345) >> 16;
        id->serial[i] = (u8)(sramEx->flashID[chan][i] + rand);
        rand = ((rand * 1103515245 + 12345) >> 16) & 0x7FFF;
    }
    __OSUnlockSramEx(FALSE);

    *(u32*)&id->serial[28] = dvdstatus;
    *(OSTime*)&id->serial[12] = time;

    id->deviceID = 0;
    id->size = card->size;
    __CARDCheckSum(id, sizeof(CARDID) - sizeof(u32), &id->checkSum, &id->checkSumInv);

    for (i = 0; i < 2; i++) {
        CARDDirCheck* check;

        dir = (CARDDir*)((u8*)card->workArea + (1 + i) * CARD_SYSTEM_BLOCK_SIZE);
        memset(dir, 0xff, CARD_SYSTEM_BLOCK_SIZE);
        check = CARDGetDirCheck(dir);
        check->checkCode = i;
        __CARDCheckSum(dir, CARD_SYSTEM_BLOCK_SIZE - sizeof(u32), &check->checkSum, &check->checkSumInv);
    }

    for (i = 0; i < 2; i++) {
        fat = (u16*)((u8*)card->workArea + (3 + i) * CARD_SYSTEM_BLOCK_SIZE);
        memset(fat, 0x00, CARD_SYSTEM_BLOCK_SIZE);
        fat[CARD_FAT_CHECKCODE] = (u16)i;
        fat[CARD_FAT_FREEBLOCKS] = (u16)(card->cBlock - CARD_NUM_SYSTEM_BLOCK);
        fat[CARD_FAT_LASTSLOT] = CARD_NUM_SYSTEM_BLOCK - 1;
        __CARDCheckSum(&fat[CARD_FAT_CHECKCODE], CARD_SYSTEM_BLOCK_SIZE - sizeof(u32), &fat[0],
                       &fat[CARD_FAT_CHECKSUMINV]);
    }

    card->apiCallback = callback ? callback : __CARDDefaultApiCallback;
    DCStoreRange(card->workArea, 5 * 8 * 1024);

    card->formatStep = 0;
    result = __CARDEraseSector(chan, (u32)card->sectorSize * card->formatStep, fn_803E667C);
    if (result < 0)
        __CARDPutControlBlock(card, result);
    return result;
}

s32 fn_803E6E18(s32 chan) {
    s32 result = __CARDFormatRegionAsync(chan, __CARDGetFontEncode(), __CARDSyncCallback);
    if (result < 0) {
        return result;
    }

    return __CARDSync(chan);
}

#pragma dont_inline on
BOOL __CARDCompareFileName(CARDDir* ent, const char* fileName) {
    char* entName = (char*)ent->fileName;
    char c1;
    char c2;
    int n = CARD_FILENAME_MAX;

    while (--n >= 0) {
        if ((c1 = *entName++) != (c2 = *fileName++))
            return FALSE;
        else if (c2 == '\0')
            return TRUE;
    }

    if (*fileName == '\0')
        return TRUE;
    return FALSE;
}
#pragma dont_inline off

#pragma dont_inline on
s32 __CARDAccess(CARDControl* card, CARDDir* ent) {
    const DVDDiskID* diskID = card->diskID;

    if (ent->gameName[0] == 0xFF)
        return CARD_RESULT_NOFILE;

    if (diskID == &__CARDDiskNone
     || (memcmp(ent->gameName, diskID->gameName, sizeof(ent->gameName)) == 0
      && memcmp(ent->company, diskID->company, sizeof(ent->company)) == 0))
        return CARD_RESULT_READY;

    return CARD_RESULT_NOPERM;
}
#pragma dont_inline off

#pragma dont_inline on
s32 __CARDIsPublic(CARDDir* ent) {
    if (ent->fileName[0] == 0xff)
        return CARD_RESULT_NOFILE;

    if (!(ent->permission & CARD_ATTR_PUBLIC))
        return CARD_RESULT_NOPERM;

    return CARD_RESULT_READY;
}
#pragma dont_inline off

#pragma dont_inline on
s32 __CARDGetFileNo(CARDControl* card, const char* fileName, s32* pfileNo) {
    CARDDir* dir;
    CARDDir* ent;
    s32 fileNo;
    s32 result;

    if (!card->attached)
        return CARD_RESULT_NOCARD;

    dir = kar_diagnostic__803e49f0(card);
    for (fileNo = 0; fileNo < CARD_MAX_FILE; fileNo++) {
        const DVDDiskID* diskID;
        ent = &dir[fileNo];

        if (ent->gameName[0] == 0xFF)
            result = CARD_RESULT_NOFILE;
        else {
            diskID = card->diskID;
            if (diskID == &__CARDDiskNone
             || (memcmp(ent->gameName, diskID->gameName, sizeof(ent->gameName)) == 0
              && memcmp(ent->company, diskID->company, sizeof(ent->company)) == 0))
                result = CARD_RESULT_READY;
            else
                result = CARD_RESULT_NOPERM;
        }

        if (result < 0)
            continue;
        if (__CARDCompareFileName(ent, fileName)) {
            *pfileNo = fileNo;
            return CARD_RESULT_READY;
        }
    }

    return CARD_RESULT_NOFILE;
}
#pragma dont_inline off

s32 CARDOpen(s32 chan, const char* fileName, CARDFileInfo* fileInfo) {
    CARDControl* card;
    s32 fileNo;
    s32 result;
    CARDDir* dir;
    CARDDir* ent;

    fileInfo->chan = -1;
    result = __CARDGetControlBlock(chan, &card);
    if (result < 0)
        return result;

    if (!card->attached)
        result = CARD_RESULT_NOCARD;
    else {
        dir = kar_diagnostic__803e49f0(card);
        for (fileNo = 0; fileNo < CARD_MAX_FILE; fileNo++) {
            const DVDDiskID* diskID;
            ent = &dir[fileNo];

            if (ent->gameName[0] == 0xFF)
                result = CARD_RESULT_NOFILE;
            else {
                diskID = card->diskID;
                if (diskID == &__CARDDiskNone
                 || (memcmp(ent->gameName, diskID->gameName, sizeof(ent->gameName)) == 0
                  && memcmp(ent->company, diskID->company, sizeof(ent->company)) == 0))
                    result = CARD_RESULT_READY;
                else
                    result = CARD_RESULT_NOPERM;
            }

            if (result < 0)
                continue;
            if (__CARDCompareFileName(ent, fileName))
                break;
        }

        if (fileNo >= CARD_MAX_FILE)
            result = CARD_RESULT_NOFILE;
    }

    if (result >= 0) {
        dir = kar_diagnostic__803e49f0(card);
        ent = &dir[fileNo];
        if (!CARDIsValidBlockNo(card, ent->startBlock))
            result = CARD_RESULT_BROKEN;
        else {
            fileInfo->chan = chan;
            fileInfo->fileNo = fileNo;
            fileInfo->offset = 0;
            fileInfo->iBlock = ent->startBlock;
        }
    }

    return __CARDPutControlBlock(card, result);
}

s32 CARDClose(CARDFileInfo* fileInfo) {
    CARDControl* card;
    s32 result;

    result = __CARDGetControlBlock(fileInfo->chan, &card);
    if (result < 0)
        return result;

    fileInfo->chan = -1;
    return __CARDPutControlBlock(card, CARD_RESULT_READY);
}

#pragma dont_inline on
BOOL kar_diagnostic__near_803e72b8(CARDControl* card, s32 fileNo) {
    return FALSE;
}
#pragma dont_inline off

void kar_diagnostic__near_803e72c0(s32 chan, s32 result) {
    CARDControl* card;
    CARDDir* dir;
    CARDDir* ent;
    CARDCallback callback;

    card = &__CARDBlock[chan];
    callback = card->apiCallback;
    card->apiCallback = NULL;

    if (result >= 0) {
        dir = kar_diagnostic__803e49f0(card);
        ent = &dir[card->freeNo];
        memcpy(ent->gameName, card->diskID->gameName, sizeof(ent->gameName));
        memcpy(ent->company, card->diskID->company, sizeof(ent->company));
        ent->permission = 4;
        ent->copyTimes = 0;

        ent->startBlock = (u16)card->startBlock;
        ent->bannerFormat = 0;
        ent->iconAddr = -1;
        ent->iconFormat = 0;
        ent->iconSpeed = 0;
        ent->commentAddr = -1;

        CARDSetIconSpeed(ent, 0, CARD_STAT_SPEED_FAST);
        card->fileInfo->offset = 0;
        card->fileInfo->iBlock = ent->startBlock;
        ent->time = OSTicksToSeconds(OSGetTime());
        result = __CARDUpdateDir(chan, callback);
        if (result < 0) {
            goto after;
        }
    } else {
after:;
        __CARDPutControlBlock(card, result);
        if (callback) {
            callback(chan, result);
        }
    }
}

s32 CARDCreateAsync(s32 chan, const char* fileName, u32 size, CARDFileInfo* fileInfo, CARDCallback callback) {
    CARDControl* card;
    CARDDir* dir;
    CARDDir* ent;
    u16 fileNo;
    u16 freeNo;
    u16* fat;
    s32 result;

    if (strlen(fileName) > (u32)CARD_FILENAME_MAX) {
        return CARD_RESULT_NAMETOOLONG;
    }

    result = __CARDGetControlBlock(chan, &card);
    if (result < 0) {
        return result;
    }

    if (size <= 0 || (size % card->sectorSize) != 0) {
        return CARD_RESULT_FATAL_ERROR;
    }

    freeNo = (u16)-1;
    dir = kar_diagnostic__803e49f0(card);
    for (fileNo = 0; fileNo < CARD_MAX_FILE; fileNo++) {
        ent = &dir[fileNo];
        if (ent->gameName[0] == 0xff) {
            if (freeNo == (u16)-1) {
                freeNo = fileNo;
            }
        } else if (memcmp(ent->gameName, card->diskID->gameName, sizeof(ent->gameName)) == 0 &&
                             memcmp(ent->company, card->diskID->company, sizeof(ent->company)) == 0 &&
                             __CARDCompareFileName(ent, fileName)) {
            return __CARDPutControlBlock(card, CARD_RESULT_EXIST);
        }
    }

    if (freeNo == (u16)-1) {
        return __CARDPutControlBlock(card, CARD_RESULT_NOENT);
    }

    fat = __CARDGetFatBlock(card);
    if (card->sectorSize * fat[CARD_FAT_FREEBLOCKS] < size) {
        return __CARDPutControlBlock(card, CARD_RESULT_INSSPACE);
    }

    card->apiCallback = callback ? callback : __CARDDefaultApiCallback;
    card->freeNo = freeNo;
    ent = &dir[freeNo];
    ent->length = (u16)(size / card->sectorSize);
    strncpy((char*)ent->fileName, fileName, CARD_FILENAME_MAX);

    card->fileInfo = fileInfo;
    fileInfo->chan = chan;
    fileInfo->fileNo = freeNo;

    result = __CARDAllocBlock(chan, size / card->sectorSize, kar_diagnostic__near_803e72c0);
    if (result < 0) {
        return __CARDPutControlBlock(card, result);
    }
    return result;
}

s32 kar_diagnostic__near_803e7610(s32 chan, const char* fileName, u32 size, CARDFileInfo* fileInfo) {
    s32 result = CARDCreateAsync(chan, fileName, size, fileInfo, __CARDSyncCallback);
    if (result < 0) {
        return result;
    }

    return __CARDSync(chan);
}

#define TRUNC(n, a) (((u32)(n)) & ~((a)-1))

s32 __CARDSeek(CARDFileInfo* fileInfo, s32 length, s32 offset, CARDControl** pcard) {
    CARDControl* card;
    CARDDir* dir;
    CARDDir* ent;
    s32 result;
    u16* fat;

    result = __CARDGetControlBlock(fileInfo->chan, &card);
    if (result < 0)
        return result;

    if (!CARDIsValidBlockNo(card, fileInfo->iBlock) || card->cBlock * card->sectorSize <= fileInfo->offset)
        return __CARDPutControlBlock(card, CARD_RESULT_FATAL_ERROR);

    dir = kar_diagnostic__803e49f0(card);
    ent = &dir[fileInfo->fileNo];

    if (ent->length * card->sectorSize <= offset || ent->length * card->sectorSize < offset + length)
        return __CARDPutControlBlock(card, CARD_RESULT_LIMIT);

    card->fileInfo = fileInfo;
    fileInfo->length = length;
    if (offset < fileInfo->offset) {
        fileInfo->offset = 0;
        fileInfo->iBlock = ent->startBlock;
        if (!CARDIsValidBlockNo(card, fileInfo->iBlock))
            return __CARDPutControlBlock(card, CARD_RESULT_BROKEN);
    }

    fat = __CARDGetFatBlock(card);
    while (fileInfo->offset < TRUNC(offset, card->sectorSize)) {
        fileInfo->offset += card->sectorSize;
        fileInfo->iBlock = fat[fileInfo->iBlock];
        if (!CARDIsValidBlockNo(card, fileInfo->iBlock))
            return __CARDPutControlBlock(card, CARD_RESULT_BROKEN);
    }

    fileInfo->offset = offset;

    *pcard = card;
    return CARD_RESULT_READY;
}

void kar_diagnostic__near_803e7810(s32 chan, s32 result) {
    CARDControl* card;
    CARDCallback callback;
    u16* fat;
    CARDFileInfo* fileInfo;
    s32 length;

    card = &__CARDBlock[chan];
    if (result < 0)
        goto error;

    fileInfo = card->fileInfo;
    if (fileInfo->length < 0) {
        result = CARD_RESULT_CANCELED;
        goto error;
    }

    length = TRUNC(fileInfo->offset + card->sectorSize, card->sectorSize) - fileInfo->offset;
    fileInfo->length -= length;
    if (fileInfo->length <= 0)
        goto error;

    fat = __CARDGetFatBlock(card);
    fileInfo->offset += length;
    fileInfo->iBlock = fat[fileInfo->iBlock];
    if (!CARDIsValidBlockNo(card, fileInfo->iBlock)) {
        result = CARD_RESULT_BROKEN;
        goto error;
    }

    result = __CARDRead(chan, card->sectorSize * (u32)fileInfo->iBlock,
                        (fileInfo->length < card->sectorSize) ? fileInfo->length : card->sectorSize, card->buffer,
                        kar_diagnostic__near_803e7810);
    if (result < 0)
        goto error;

    return;

error:
    callback = card->apiCallback;
    card->apiCallback = NULL;
    __CARDPutControlBlock(card, result);
    callback(chan, result);
}

s32 CARDReadAsync(CARDFileInfo* fileInfo, void* buf, s32 length, s32 offset, CARDCallback callback) {
    CARDControl* card;
    s32 result;
    CARDDir* dir;
    CARDDir* ent;

    if (OFFSET(offset, CARD_SEG_SIZE) != 0 || OFFSET(length, CARD_SEG_SIZE) != 0)
        return CARD_RESULT_FATAL_ERROR;

    result = __CARDSeek(fileInfo, length, offset, &card);
    if (result < 0)
        return result;

    dir = kar_diagnostic__803e49f0(card);
    ent = &dir[fileInfo->fileNo];
    result = __CARDAccess(card, ent);
    if (result == CARD_RESULT_NOPERM) {
        result = __CARDIsPublic(ent);
    }
    if (result < 0)
        return __CARDPutControlBlock(card, result);

    DCInvalidateRange(buf, (u32)length);
    card->apiCallback = callback ? callback : __CARDDefaultApiCallback;

    offset = (s32)OFFSET(fileInfo->offset, card->sectorSize);
    length = (length < card->sectorSize - offset) ? length : card->sectorSize - offset;
    result = __CARDRead(fileInfo->chan, card->sectorSize * (u32)fileInfo->iBlock + offset, length, buf,
                        kar_diagnostic__near_803e7810);
    if (result < 0)
        __CARDPutControlBlock(card, result);
    return result;
}

s32 kar_diagnostic__803e7a88(CARDFileInfo* fileInfo, void* buf, s32 length, s32 offset) {
    s32 result = CARDReadAsync(fileInfo, buf, length, offset, __CARDSyncCallback);
    if (result < 0) {
        return result;
    }

    return __CARDSync(fileInfo->chan);
}

void kar_diagnostic__near_803e7ad0(s32 chan, s32 result) {
    CARDControl* card;
    CARDCallback callback;
    u16* fat;
    CARDDir* dir;
    CARDDir* ent;
    CARDFileInfo* fileInfo;

    card = &__CARDBlock[chan];
    if (result >= 0) {
        fileInfo = card->fileInfo;
        if (fileInfo->length < 0) {
            result = CARD_RESULT_CANCELED;
            goto after;
        }
        fileInfo->length -= card->sectorSize;
        if (fileInfo->length <= 0) {
            dir = kar_diagnostic__803e49f0(card);
            ent = dir + fileInfo->fileNo;
            ent->time = OSGetTime() / (__OSBusClock / 4);
            callback = card->apiCallback;
            card->apiCallback = NULL;
            result = __CARDUpdateDir(chan, callback);
            goto check;
        } else {
            fat = __CARDGetFatBlock(card);
            fileInfo->offset += card->sectorSize;
            fileInfo->iBlock = fat[fileInfo->iBlock];
            if ((fileInfo->iBlock < 5) || (fileInfo->iBlock >= card->cBlock)) {
                result = CARD_RESULT_BROKEN;
                goto after;
            }
            result = __CARDEraseSector(chan, card->sectorSize * fileInfo->iBlock, kar_diagnostic__near_803e7c40);
check:;
            if (result < 0) {
                goto after;
            }
        }
    } else {
after:;
        callback = card->apiCallback;
        card->apiCallback = NULL;
        __CARDPutControlBlock(card, result);
        callback(chan, result);
    }
}

void kar_diagnostic__near_803e7c40(s32 chan, s32 result) {
    CARDControl* card;
    CARDCallback callback;
    CARDFileInfo* fileInfo;

    card = &__CARDBlock[chan];
    if (result >= 0) {
        fileInfo = card->fileInfo;
        result = __CARDWrite(chan, card->sectorSize * fileInfo->iBlock, card->sectorSize, card->buffer,
                             kar_diagnostic__near_803e7ad0);
        if (result < 0) {
            goto after;
        }
    } else {
after:;
        callback = card->apiCallback;
        card->apiCallback = NULL;
        __CARDPutControlBlock(card, result);
        callback(chan, result);
    }
}

s32 CARDWriteAsync(CARDFileInfo* fileInfo, void* buf, s32 length, s32 offset, CARDCallback callback) {
    CARDControl* card;
    s32 result;
    CARDDir* dir;
    CARDDir* ent;

    result = __CARDSeek(fileInfo, length, offset, &card);
    if (result < 0) {
        return result;
    }

    if (OFFSET(offset, card->sectorSize) != 0 || OFFSET(length, card->sectorSize) != 0)
        return __CARDPutControlBlock(card, CARD_RESULT_FATAL_ERROR);

    dir = kar_diagnostic__803e49f0(card);
    ent = &dir[fileInfo->fileNo];
    result = __CARDAccess(card, ent);
    if (result < 0)
        return __CARDPutControlBlock(card, result);

    DCStoreRange((void*)buf, (u32)length);
    card->apiCallback = callback ? callback : __CARDDefaultApiCallback;
    card->buffer = (void*)buf;

    result = __CARDEraseSector(fileInfo->chan, card->sectorSize * (u32)fileInfo->iBlock, kar_diagnostic__near_803e7c40);
    if (result < 0)
        __CARDPutControlBlock(card, result);
    return result;
}

s32 kar_diagnostic__803e7e04(CARDFileInfo* fileInfo, void* buf, s32 length, s32 offset) {
    s32 result = CARDWriteAsync(fileInfo, buf, length, offset, __CARDSyncCallback);
    if (result < 0) {
        return result;
    }

    return __CARDSync(fileInfo->chan);
}

void kar_diagnostic__near_803e7e4c(s32 chan, s32 result) {
    CARDControl* card;
    CARDCallback callback;

    card = &__CARDBlock[chan];
    callback = card->apiCallback;
    card->apiCallback = NULL;

    if (result < 0)
        goto error;

    result = __CARDFreeBlock(chan, card->startBlock, callback);
    if (result < 0)
        goto error;
    return;

error:
    __CARDPutControlBlock(card, result);
    if (callback)
        callback(chan, result);
}

s32 CARDDeleteAsync(s32 chan, const char* fileName, CARDCallback callback) {
    CARDControl* card;
    s32 fileNo;
    s32 result;
    CARDDir* dir;
    CARDDir* ent;

    result = __CARDGetControlBlock(chan, &card);
    if (result < 0)
        return result;
    result = __CARDGetFileNo(card, fileName, &fileNo);
    if (result < 0)
        return __CARDPutControlBlock(card, result);
    if (kar_diagnostic__near_803e72b8(card, fileNo))
        return __CARDPutControlBlock(card, CARD_RESULT_BUSY);

    dir = kar_diagnostic__803e49f0(card);
    ent = &dir[fileNo];
    card->startBlock = ent->startBlock;
    memset(ent, 0xff, sizeof(CARDDir));

    card->apiCallback = callback ? callback : __CARDDefaultApiCallback;
    result = __CARDUpdateDir(chan, kar_diagnostic__near_803e7e4c);
    if (result < 0)
        __CARDPutControlBlock(card, result);
    return result;
}

s32 CARDDelete(s32 chan, const char* fileName) {
    s32 result = CARDDeleteAsync(chan, fileName, __CARDSyncCallback);
    if (result < 0)
        return result;

    return __CARDSync(chan);
}

s32 kar_diagnostic__near_803e8048(CARDDir* ent, CARDStat* stat) {
    u32 offset;
    BOOL iconTlut;
    int i;

    offset = ent->iconAddr;
    if (offset == 0xffffffff) {
        stat->bannerFormat = 0;
        stat->iconFormat = 0;
        stat->iconSpeed = 0;
        offset = 0;
    }

    iconTlut = FALSE;
    switch (CARDGetBannerFormat(ent)) {
    case CARD_STAT_BANNER_C8:
        stat->offsetBanner = offset;
        offset += CARD_BANNER_WIDTH * CARD_BANNER_HEIGHT;
        stat->offsetBannerTlut = offset;
        offset += 2 * 256;
        break;
    case CARD_STAT_BANNER_RGB5A3:
        stat->offsetBanner = offset;
        offset += 2 * CARD_BANNER_WIDTH * CARD_BANNER_HEIGHT;
        stat->offsetBannerTlut = 0xffffffff;
        break;
    default:
        stat->offsetBanner = 0xffffffff;
        stat->offsetBannerTlut = 0xffffffff;
        break;
    }

    for (i = 0; i < CARD_ICON_MAX; ++i) {
        switch (CARDGetIconFormat(ent, i)) {
        case CARD_STAT_ICON_C8:
            stat->offsetIcon[i] = offset;
            offset += CARD_ICON_WIDTH * CARD_ICON_HEIGHT;
            iconTlut = TRUE;
            break;
        case CARD_STAT_ICON_RGB5A3:
            stat->offsetIcon[i] = offset;
            offset += 2 * CARD_ICON_WIDTH * CARD_ICON_HEIGHT;
            break;
        default:
            stat->offsetIcon[i] = 0xffffffff;
            break;
        }
    }

    if (iconTlut) {
        stat->offsetIconTlut = offset;
        offset += 2 * 256;
    } else {
        stat->offsetIconTlut = 0xffffffff;
    }
    stat->offsetData = offset;
    return 0;
}

s32 CARDGetStatus(s32 chan, s32 fileNo, CARDStat* stat) {
    CARDControl* card;
    CARDDir* dir;
    CARDDir* ent;
    s32 result;

    if (fileNo < 0 || CARD_MAX_FILE <= fileNo)
        return CARD_RESULT_FATAL_ERROR;

    result = __CARDGetControlBlock(chan, &card);
    if (result < 0)
        return result;

    dir = kar_diagnostic__803e49f0(card);
    ent = &dir[fileNo];
    result = __CARDAccess(card, ent);
    if (result == CARD_RESULT_NOPERM) {
        result = __CARDIsPublic(ent);
    }

    if (result >= 0) {
        memcpy(stat->gameName, ent->gameName, sizeof(stat->gameName));
        memcpy(stat->company, ent->company, sizeof(stat->company));
        stat->length = (u32)ent->length * card->sectorSize;
        memcpy(stat->fileName, ent->fileName, CARD_FILENAME_MAX);
        stat->time = ent->time;

        stat->bannerFormat = ent->bannerFormat;
        stat->iconAddr = ent->iconAddr;
        stat->iconFormat = ent->iconFormat;
        stat->iconSpeed = ent->iconSpeed;
        stat->commentAddr = ent->commentAddr;

        kar_diagnostic__near_803e8048(ent, stat);
    }

    return __CARDPutControlBlock(card, result);
}

s32 CARDSetStatusAsync(s32 chan, s32 fileNo, CARDStat* stat, CARDCallback callback) {
    CARDControl* card;
    CARDDir* dir;
    CARDDir* ent;
    s32 result;

    if (fileNo < 0 || CARD_MAX_FILE <= fileNo ||
        (stat->iconAddr != 0xffffffff && CARD_READ_SIZE <= stat->iconAddr) ||
        (stat->commentAddr != 0xffffffff &&
         CARD_SYSTEM_BLOCK_SIZE - CARD_COMMENT_SIZE < stat->commentAddr % CARD_SYSTEM_BLOCK_SIZE))
    {
        return CARD_RESULT_FATAL_ERROR;
    }

    result = __CARDGetControlBlock(chan, &card);
    if (result < 0)
        return result;

    dir = kar_diagnostic__803e49f0(card);
    ent = &dir[fileNo];
    result = __CARDAccess(card, ent);
    if (result < 0)
        return __CARDPutControlBlock(card, result);

    ent->bannerFormat = stat->bannerFormat;
    ent->iconAddr = stat->iconAddr;
    ent->iconFormat = stat->iconFormat;
    ent->iconSpeed = stat->iconSpeed;
    ent->commentAddr = stat->commentAddr;
    kar_diagnostic__near_803e8048(ent, stat);

    if (ent->iconAddr == 0xffffffff) {
        CARDSetIconSpeed(ent, 0, CARD_STAT_SPEED_FAST);
    }

    ent->time = (u32)OSTicksToSeconds(OSGetTime());
    result = __CARDUpdateDir(chan, callback);
    if (result < 0)
        __CARDPutControlBlock(card, result);
    return result;
}

s32 kar_diagnostic__803e84e0(s32 chan, s32 fileNo, CARDStat* stat) {
    s32 result = CARDSetStatusAsync(chan, fileNo, stat, __CARDSyncCallback);
    if (result < 0) {
        return result;
    }

    return __CARDSync(chan);
}

s32 fn_803E8528(s32 chan, const char* old, const char* new, CARDCallback callback) {
    CARDControl* card;
    CARDDir* dir;
    CARDDir* ent;
    s32 result;
    int fileNo;
    int newNo;
    int oldNo;

    if (old[0] == 0xFF || new[0] == 0xFF || old[0] == 0 || new[0] == 0)
        return CARD_RESULT_FATAL_ERROR;
    if (CARD_FILENAME_MAX < (u32)strlen(old) || CARD_FILENAME_MAX < (u32)strlen(new))
        return CARD_RESULT_NAMETOOLONG;

    result = __CARDGetControlBlock(chan, &card);
    if (result < 0)
        return result;

    newNo = oldNo = -1;
    dir = kar_diagnostic__803e49f0(card);
    for (fileNo = 0; fileNo < CARD_MAX_FILE; fileNo++) {
        ent = &dir[fileNo];
        if (ent->gameName[0] == 0xFF)
            continue;

        if (memcmp(ent->gameName, card->diskID->gameName, sizeof(ent->gameName)) != 0
         || memcmp(ent->company, card->diskID->company, sizeof(ent->company)) != 0)
            continue;

        if (__CARDCompareFileName(ent, old))
            oldNo = fileNo;
        if (__CARDCompareFileName(ent, new))
            newNo = fileNo;
    }

    if (oldNo == -1)
        return __CARDPutControlBlock(card, CARD_RESULT_NOFILE);
    if (newNo != -1)
        return __CARDPutControlBlock(card, CARD_RESULT_EXIST);

    ent = &dir[oldNo];
    result = __CARDAccess(card, ent);
    if (result < 0)
        return __CARDPutControlBlock(card, result);

    strncpy((char*)ent->fileName, new, CARD_FILENAME_MAX);
    ent->time = (u32)OSTicksToSeconds(OSGetTime());

    result = __CARDUpdateDir(chan, callback);
    if (result < 0)
        __CARDPutControlBlock(card, result);

    return result;
}

s32 fn_803E8724(s32 chan, const char* old, const char* new) {
    s32 result = fn_803E8528(chan, old, new, __CARDSyncCallback);
    if (result < 0)
        return result;

    return __CARDSync(chan);
}
