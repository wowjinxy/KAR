#include "dolphin/types.h"

typedef s64 OSTime;
typedef s32 OSPriority;
typedef struct OSContext OSContext;
typedef u32 __OSInterrupt;
typedef void (*__OSInterruptHandler)(__OSInterrupt interrupt, OSContext* context);

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

typedef struct OSBootInfo
{
    DVDDiskID dvdDiskID;
    u32 magic;
    u32 version;
    u32 memorySize;
    u32 consoleType;
    void* arenaLo;
    void* arenaHi;
    void* FSTLocation;
    u32 FSTMaxLength;
} OSBootInfo;

typedef void (*DVDLowCallback)(u32 reason);

typedef struct DVDCommand
{
    s32 command;
    void* address;
    u32 length;
    u32 offset;
    DVDLowCallback callback;
} DVDCommand;

typedef struct DVDCommandBlock DVDCommandBlock;
typedef void (*DVDCBCallback)(s32 result, DVDCommandBlock* block);

struct DVDCommandBlock
{
    /* 0x00 */ DVDCommandBlock* next;
    /* 0x04 */ DVDCommandBlock* prev;
    /* 0x08 */ u32 command;
    /* 0x0C */ s32 state;
    /* 0x10 */ u32 offset;
    /* 0x14 */ u32 length;
    /* 0x18 */ void* addr;
    /* 0x1C */ u32 currTransferSize;
    /* 0x20 */ u32 transferredSize;
    /* 0x24 */ DVDDiskID* id;
    /* 0x28 */ DVDCBCallback callback;
    /* 0x2C */ void* userData;
};

typedef struct DVDFileInfo
{
    /* 0x00 */ DVDCommandBlock cb;
    /* 0x30 */ u32 startAddr;
    /* 0x34 */ u32 length;
    /* 0x38 */ void (*callback)(s32 result, struct DVDFileInfo* fileInfo);
} DVDFileInfo;

typedef struct DVDBB2
{
    /* 0x00 */ u32 bootFilePosition;
    /* 0x04 */ u32 FSTPosition;
    /* 0x08 */ u32 FSTLength;
    /* 0x0C */ u32 FSTMaxLength;
    /* 0x10 */ void* FSTAddress;
    /* 0x14 */ u32 userPosition;
    /* 0x18 */ u32 userLength;
    /* 0x1C */ u32 padding0;
} DVDBB2;

typedef struct DVDDriveInfo
{
    /* 0x00 */ u16 revisionLevel;
    /* 0x02 */ u16 deviceCode;
    /* 0x04 */ u32 releaseDate;
    /* 0x08 */ u8 padding[24];
} DVDDriveInfo;

typedef void (*DVDCommandCheckerCallback)(u32);
typedef void (*DVDCommandChecker)(DVDCommandBlock*, DVDCommandCheckerCallback);

typedef struct FSTEntry
{
    u32 isDirAndStringOff;
    u32 parentOrPosition;
    u32 nextEntryOrLength;
} FSTEntry;

#define DVD_STATE_FATAL_ERROR -1
#define DVD_STATE_END 0
#define DVD_STATE_BUSY 1
#define DVD_STATE_WAITING 2
#define DVD_STATE_COVER_CLOSED 3
#define DVD_STATE_NO_DISK 4
#define DVD_STATE_COVER_OPEN 5
#define DVD_STATE_WRONG_DISK 6
#define DVD_STATE_MOTOR_STOPPED 7
#define DVD_STATE_PAUSING 8
#define DVD_STATE_IGNORED 9
#define DVD_STATE_CANCELED 10
#define DVD_STATE_RETRY 11

#define DVD_COMMAND_NONE 0
#define DVD_COMMAND_READ 1
#define DVD_COMMAND_SEEK 2
#define DVD_COMMAND_CHANGE_DISK 3
#define DVD_COMMAND_BSREAD 4
#define DVD_COMMAND_READID 5
#define DVD_COMMAND_INITSTREAM 6
#define DVD_COMMAND_CANCELSTREAM 7
#define DVD_COMMAND_STOP_STREAM_AT_END 8
#define DVD_COMMAND_REQUEST_AUDIO_ERROR 9
#define DVD_COMMAND_REQUEST_PLAY_ADDR 10
#define DVD_COMMAND_REQUEST_START_ADDR 11
#define DVD_COMMAND_REQUEST_LENGTH 12
#define DVD_COMMAND_AUDIO_BUFFER_CONFIG 13
#define DVD_COMMAND_INQUIRY 14
#define DVD_COMMAND_BS_CHANGE_DISK 15
#define DVD_COMMAND_UNK_16 16

#define DVD_INTTYPE_TC 1
#define DVD_INTTYPE_DE 2
#define DVD_INTTYPE_CVR 4

#define DVD_MIN_TRANSFER_SIZE 32

extern const char kar_srcfile_dvdfs_c_805dc8d8[];
extern const char lbl_804F94C8[];
extern const char lbl_804F9590[];

#define DVD_ASSERTMSGLINE(line, cond, msg)         \
    if (!(cond))                                   \
    OSPanic(kar_srcfile_dvdfs_c_805dc8d8, line, msg)

#define DVD_ASSERTMSGLINE_DVD(line, cond, msg) \
    if (!(cond))                               \
    OSPanic("dvd.c", line, msg)

volatile u32 __DIRegs[] : (0xCC006000);
volatile u32 __PIRegs[] : (0xCC003000);
#define OS_BUS_CLOCK (*(volatile u32*)0x800000F8)
#define OSSecondsToTicks(sec) ((OS_BUS_CLOCK / 4) * (sec))
#define OSMillisecondsToTicks(msec) ((msec) * ((OS_BUS_CLOCK / 4) / 1000))
#define OSMicrosecondsToTicks(usec) (((usec) * ((OS_BUS_CLOCK / 4) / 125000)) / 8)
#define OSPhysicalToCached(paddr) ((void*)((u32)(0x80000000 + (u32)(paddr))))
#define OSRoundUp32B(x) ((void*)(((u32)(x) + 32 - 1) & ~(32 - 1)))

extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL level);
extern void OSRegisterVersion(char* version);
extern void __OSSetInterruptHandler(u32 interrupt, __OSInterruptHandler handler);
extern u32 __OSUnmaskInterrupts(u32 mask);
extern OSTime __OSGetSystemTime(void);
extern void OSCreateAlarm(OSAlarm* alarm);
extern void OSSetAlarm(OSAlarm* alarm, OSTime tick, OSAlarmHandler handler);
extern void OSInitAlarm(void);
extern void OSInitThreadQueue(OSThreadQueue* queue);
extern void OSSleepThread(OSThreadQueue* queue);
extern void OSWakeupThread(OSThreadQueue* queue);
extern void OSReport(const char* msg, ...);
extern void OSPanic(const char* file, int line, const char* msg, ...);
extern void* OSGetArenaHi(void);
extern void OSSetArenaHi(void* newHi);
extern OSSramEx* __OSLockSramEx(void);
extern void __OSUnlockSramEx(BOOL commit);
extern void DCInvalidateRange(void* addr, u32 nBytes);
extern int memcmp(const void* s1, const void* s2, u32 n);
extern void* memcpy(void* dest, const void* src, u32 n);
extern void* memset(void* dest, int c, u32 n);
extern int strncmp(const char* s1, const char* s2, u32 n);
extern char* strncpy(char* dest, const char* src, u32 n);
extern int fn_803B3870(int c); /* tolower */

extern DVDCommand CommandList_8056CB40[3];
extern void __DVDInitWA(void);
extern void __DVDInterruptHandler(__OSInterrupt interrupt, OSContext* context);
extern void fn_803C437C(void); /* ProcessNextCommand */
extern void fn_803C4470(void* address, u32 length, u32 offset, DVDLowCallback callback); /* Read */
extern void fn_803C4580(void* addr, u32 length, u32 offset, DVDLowCallback callback);     /* SeekTwiceBeforeRead */
extern void AlarmHandlerForTimeout_803C4400(OSAlarm* alarm, OSContext* context);
extern DVDLowCallback Callback_805DDD48;    /* Callback */
extern volatile BOOL StopAtNextInt_805DDD40;     /* StopAtNextInt */
extern volatile BOOL WaitingCoverClose_805DDD5C; /* WaitingCoverClose */
extern volatile BOOL lbl_805DDD60;               /* Breaking */
extern volatile u32 ResetOccurred_805DDD58;      /* ResetOccurred */
extern volatile OSTime LastResetEnd_805DDD50;    /* LastResetEnd */

extern BOOL lbl_805DC8D0; /* FirstRead */

BOOL DVDLowSeek(u32 offset, DVDLowCallback callback);
BOOL DVDLowReadDiskID(DVDDiskID* diskID, DVDLowCallback callback);
__declspec(weak) BOOL DVDLowStopMotor(DVDLowCallback callback);
__declspec(weak) BOOL DVDLowWaitCoverClose(DVDLowCallback callback);
BOOL DVDLowRequestError(DVDLowCallback callback);
BOOL DVDLowInquiry(DVDDriveInfo* info, DVDLowCallback callback);
BOOL DVDLowAudioStream(u32 subcmd, u32 length, u32 offset, DVDLowCallback callback);
BOOL DVDLowRequestAudioStatus(u32 subcmd, DVDLowCallback callback);
BOOL DVDLowAudioBufferConfig(BOOL enable, u32 size, DVDLowCallback callback);
BOOL DVDLowBreak(void);
DVDLowCallback DVDLowClearCallback(void);
void __DVDLowSetWAType(u32 type, s32 seekLoc);

s32 DVDConvertPathToEntrynum(const char* pathPtr);
BOOL DVDOpen(const char* fileName, DVDFileInfo* fileInfo);
BOOL DVDClose(DVDFileInfo* fileInfo);
BOOL DVDGetCurrentDir(char* path, u32 maxlen);
void cbForReadAsync(s32 result, DVDCommandBlock* block);
void fn_803C5754(s32 result, DVDCommandBlock* block);
void fn_803C5778(DVDCommandBlock* block, DVDCommandCheckerCallback cb);

void DVDReset(void);
DVDDiskID* DVDGetCurrentDiskID(void);
s32 DVDGetCommandBlockStatus(const DVDCommandBlock* block);
s32 DVDGetDriveStatus(void);
int DVDReadAbsAsyncPrio(DVDCommandBlock* block, void* addr, s32 length, s32 offset, DVDCBCallback callback, s32 prio);
int DVDReadAbsAsyncForBS(DVDCommandBlock* block, void* addr, s32 length, s32 offset, DVDCBCallback callback);
int DVDReadDiskID(DVDCommandBlock* block, DVDDiskID* diskID, DVDCBCallback callback);
int DVDCancelAsync(DVDCommandBlock* block, DVDCBCallback callback);
void fn_803C7C34(s32 result, DVDCommandBlock* block);
s32 DVDCancel(volatile DVDCommandBlock* block);
void __DVDStoreErrorCode(u32 error);
int __DVDPushWaitingQueue(s32 prio, DVDCommandBlock* block);
DVDCommandBlock* __DVDPopWaitingQueue(void);
int __DVDCheckWaitingQueue(void);
int __DVDDequeueWaitingQueue(DVDCommandBlock* block);
void __DVDClearWaitingQueue(void);
int DVDCompareDiskID(const DVDDiskID* id1, const DVDDiskID* id2);
void fn_803C82FC(void);
void __fstLoad(void);

static volatile u32 WorkAroundType = 0;
static u32 WorkAroundSeekLocation_805DDD68 = 0;
OSTime lbl_805DDD70 = 0; /* LastReadFinished */
OSTime lbl_805DDD78 = 0; /* LastReadIssued */
BOOL lbl_805DDD80 = FALSE; /* LastCommandWasRead */
u32 NextCommandNumber_805DDD84 = 0;

static OSAlarm AlarmForTimeout;
static OSAlarm AlarmForBreak;

typedef struct
{
    void* addr;
    u32 length;
    u32 offset;
} DVDBuffer;

#define Prev (*(DVDBuffer*)((u8*)CommandList_8056CB40 + 0xb8))
#define Curr (*(DVDBuffer*)((u8*)CommandList_8056CB40 + 0xc4))

#pragma dont_inline on

BOOL DVDLowRead(void* addr, u32 length, u32 offset, DVDLowCallback callback)
{
    u32 blockNumOfPrevEnd;
    u32 blockNumOfCurrStart;
    OSTime diff;

    __DIRegs[6] = length;
    Curr.addr = addr;
    Curr.length = length;
    Curr.offset = offset;

    if (WorkAroundType == 0) {
        CommandList_8056CB40[0].command = -1;
        NextCommandNumber_805DDD84 = 0;
        fn_803C4470(addr, length, offset, callback);
    } else if (WorkAroundType == 1) {
        if (lbl_805DC8D0) {
            fn_803C4580(addr, length, offset, callback);
        } else {
            DVDDiskID* id;
            u32 cacheBlockSize;

            blockNumOfPrevEnd = (Prev.offset + Prev.length - 1) >> 15;
            blockNumOfCurrStart = Curr.offset >> 15;

            id = DVDGetCurrentDiskID();
            cacheBlockSize = id->streaming ? 5 : 15;

            if ((blockNumOfCurrStart > blockNumOfPrevEnd - 2) ||
                (blockNumOfCurrStart < blockNumOfPrevEnd + cacheBlockSize + 3)) {
                CommandList_8056CB40[0].command = -1;
                NextCommandNumber_805DDD84 = 0;
                fn_803C4470(addr, length, offset, callback);
            } else {
                blockNumOfPrevEnd = ((Prev.offset + Prev.length - 1) >> 15) & 0x1FFFF;
                blockNumOfCurrStart = (Curr.offset >> 15) & 0x1FFFF;

                if (blockNumOfPrevEnd == blockNumOfCurrStart || blockNumOfPrevEnd + 1 == blockNumOfCurrStart) {
                    diff = __OSGetSystemTime() - lbl_805DDD70;
                    if (OSMillisecondsToTicks(5) < diff) {
                        CommandList_8056CB40[0].command = -1;
                        NextCommandNumber_805DDD84 = 0;
                        fn_803C4470(addr, length, offset, callback);
                    } else {
                        CommandList_8056CB40[0].command = 1;
                        CommandList_8056CB40[0].address = addr;
                        CommandList_8056CB40[0].length = length;
                        CommandList_8056CB40[0].offset = offset;
                        CommandList_8056CB40[0].callback = callback;
                        CommandList_8056CB40[1].command = -1;
                        NextCommandNumber_805DDD84 = 0;
                        OSCreateAlarm(&AlarmForTimeout);
                        OSSetAlarm(&AlarmForTimeout, OSMillisecondsToTicks(5) - diff + OSMicrosecondsToTicks(500),
                                   (OSAlarmHandler)fn_803C437C);
                    }
                } else {
                    fn_803C4580(addr, length, offset, callback);
                }
            }
        }
    }

    return TRUE;
}

BOOL DVDLowSeek(u32 offset, DVDLowCallback callback)
{
    OSTime timeout;
    Callback_805DDD48 = callback;
    StopAtNextInt_805DDD40 = FALSE;
    __DIRegs[2] = 0xab000000;
    __DIRegs[3] = offset / 4;
    __DIRegs[7] = 1;
    timeout = OSSecondsToTicks(10);
    OSCreateAlarm(&AlarmForTimeout);
    OSSetAlarm(&AlarmForTimeout, timeout, AlarmHandlerForTimeout_803C4400);
    return TRUE;
}

__declspec(weak) BOOL DVDLowWaitCoverClose(DVDLowCallback callback)
{
    Callback_805DDD48 = callback;
    WaitingCoverClose_805DDD5C = TRUE;
    StopAtNextInt_805DDD40 = FALSE;
    __DIRegs[1] = 2;
    return TRUE;
}

BOOL DVDLowReadDiskID(DVDDiskID* diskID, DVDLowCallback callback)
{
    OSTime timeout;
    Callback_805DDD48 = callback;
    StopAtNextInt_805DDD40 = FALSE;
    __DIRegs[2] = 0xa8000040;
    __DIRegs[3] = 0;
    __DIRegs[4] = sizeof(DVDDiskID);
    __DIRegs[5] = (u32)diskID;
    __DIRegs[6] = sizeof(DVDDiskID);
    __DIRegs[7] = 3;
    timeout = OSSecondsToTicks(10);
    OSCreateAlarm(&AlarmForTimeout);
    OSSetAlarm(&AlarmForTimeout, timeout, AlarmHandlerForTimeout_803C4400);
    return TRUE;
}

__declspec(weak) BOOL DVDLowStopMotor(DVDLowCallback callback)
{
    OSTime timeout;
    Callback_805DDD48 = callback;
    StopAtNextInt_805DDD40 = FALSE;
    __DIRegs[2] = 0xe3000000;
    __DIRegs[7] = 1;
    timeout = OSSecondsToTicks(10);
    OSCreateAlarm(&AlarmForTimeout);
    OSSetAlarm(&AlarmForTimeout, timeout, AlarmHandlerForTimeout_803C4400);
    return TRUE;
}

BOOL DVDLowRequestError(DVDLowCallback callback)
{
    OSTime timeout;
    Callback_805DDD48 = callback;
    StopAtNextInt_805DDD40 = FALSE;
    __DIRegs[2] = 0xe0000000;
    __DIRegs[7] = 1;
    timeout = OSSecondsToTicks(10);
    OSCreateAlarm(&AlarmForTimeout);
    OSSetAlarm(&AlarmForTimeout, timeout, AlarmHandlerForTimeout_803C4400);
    return TRUE;
}

BOOL DVDLowInquiry(DVDDriveInfo* info, DVDLowCallback callback)
{
    OSTime timeout;
    Callback_805DDD48 = callback;
    StopAtNextInt_805DDD40 = FALSE;
    __DIRegs[2] = 0x12000000;
    __DIRegs[4] = sizeof(DVDDriveInfo);
    __DIRegs[5] = (u32)info;
    __DIRegs[6] = sizeof(DVDDriveInfo);
    __DIRegs[7] = 3;
    timeout = OSSecondsToTicks(10);
    OSCreateAlarm(&AlarmForTimeout);
    OSSetAlarm(&AlarmForTimeout, timeout, AlarmHandlerForTimeout_803C4400);
    return TRUE;
}

BOOL DVDLowAudioStream(u32 subcmd, u32 length, u32 offset, DVDLowCallback callback)
{
    OSTime timeout;
    Callback_805DDD48 = callback;
    StopAtNextInt_805DDD40 = FALSE;
    __DIRegs[2] = subcmd | 0xe1000000;
    __DIRegs[3] = offset >> 2;
    __DIRegs[4] = length;
    __DIRegs[7] = 1;
    timeout = OSSecondsToTicks(10);
    OSCreateAlarm(&AlarmForTimeout);
    OSSetAlarm(&AlarmForTimeout, timeout, AlarmHandlerForTimeout_803C4400);
    return TRUE;
}

BOOL DVDLowRequestAudioStatus(u32 subcmd, DVDLowCallback callback)
{
    OSTime timeout;
    Callback_805DDD48 = callback;
    StopAtNextInt_805DDD40 = FALSE;
    __DIRegs[2] = subcmd | 0xe2000000;
    __DIRegs[7] = 1;
    timeout = OSSecondsToTicks(10);
    OSCreateAlarm(&AlarmForTimeout);
    OSSetAlarm(&AlarmForTimeout, timeout, AlarmHandlerForTimeout_803C4400);
    return TRUE;
}

BOOL DVDLowAudioBufferConfig(BOOL enable, u32 size, DVDLowCallback callback)
{
    OSTime timeout;
    Callback_805DDD48 = callback;
    StopAtNextInt_805DDD40 = FALSE;
    __DIRegs[2] = 0xe4000000 | (enable != 0 ? 0x10000 : 0) | size;
    __DIRegs[7] = 1;
    timeout = OSSecondsToTicks(10);
    OSCreateAlarm(&AlarmForTimeout);
    OSSetAlarm(&AlarmForTimeout, timeout, AlarmHandlerForTimeout_803C4400);
    return TRUE;
}

void DVDLowReset(void)
{
    u32 reg;
    OSTime resetStart;
    OSTime waitTicks;

    __DIRegs[1] = 2;
    reg = __PIRegs[9];
    __PIRegs[9] = (reg & ~4) | 1;

    resetStart = __OSGetSystemTime();
    waitTicks = OSMicrosecondsToTicks(12);
    while ((__OSGetSystemTime() - resetStart) < waitTicks)
        ;

    __PIRegs[9] = reg | 4 | 1;
    ResetOccurred_805DDD58 = TRUE;
    LastResetEnd_805DDD50 = __OSGetSystemTime();
}

BOOL DVDLowBreak(void)
{
    StopAtNextInt_805DDD40 = TRUE;
    lbl_805DDD60 = TRUE;
    return TRUE;
}

DVDLowCallback DVDLowClearCallback(void)
{
    DVDLowCallback old;
    __DIRegs[1] = 0;
    old = Callback_805DDD48;
    Callback_805DDD48 = NULL;
    return old;
}

void __DVDLowSetWAType(u32 type, s32 seekLoc)
{
    BOOL enabled;

    enabled = OSDisableInterrupts();
    WorkAroundType = type;
    WorkAroundSeekLocation_805DDD68 = seekLoc;
    OSRestoreInterrupts(enabled);
}

#pragma dont_inline off

static OSBootInfo* BootInfo;
static FSTEntry* FstStart;
static char* FstStringStart;
static u32 MaxEntryNum;
static u32 lbl_805DDD98; /* currentDirectory */

OSThreadQueue __DVDThreadQueue;
u32 __DVDLongFileNameFlag;

#define entryIsDir(i) (((FstStart[i].isDirAndStringOff & 0xff000000) == 0) ? FALSE : TRUE)
#define stringOff(i) (FstStart[i].isDirAndStringOff & ~0xff000000)
#define parentDir(i) (FstStart[i].parentOrPosition)
#define nextDir(i) (FstStart[i].nextEntryOrLength)
#define filePosition(i) (FstStart[i].parentOrPosition)
#define fileLength(i) (FstStart[i].nextEntryOrLength)

#pragma dont_inline on

void __DVDFSInit(void)
{
    BootInfo = (OSBootInfo*)OSPhysicalToCached(0);
    FstStart = (FSTEntry*)BootInfo->FSTLocation;
    if (FstStart) {
        MaxEntryNum = FstStart->nextEntryOrLength;
        FstStringStart = (char*)FstStart + (MaxEntryNum * sizeof(FSTEntry));
    }
}

#pragma dont_inline off

static inline BOOL isSame(const char* path, const char* string)
{
    while (*string != '\0') {
        if (fn_803B3870((u8)*path++) != fn_803B3870((u8)*string++)) {
            return FALSE;
        }
    }

    if (*path == '/' || *path == '\0') {
        return TRUE;
    }

    return FALSE;
}

s32 DVDConvertPathToEntrynum(const char* pathPtr)
{
    const char* ptr;
    char* stringPtr;
    BOOL isDir;
    u32 length;
    u32 dirLookAt;
    u32 i;
    const char* extentionStart = NULL;
    BOOL illegal;
    BOOL extention;

    dirLookAt = lbl_805DDD98;

    while (1) {
        if (*pathPtr == '\0') {
            return (s32)dirLookAt;
        } else if (*pathPtr == '/') {
            dirLookAt = 0;
            pathPtr++;
            continue;
        } else if (*pathPtr == '.') {
            if (*(pathPtr + 1) == '.') {
                if (*(pathPtr + 2) == '/') {
                    dirLookAt = parentDir(dirLookAt);
                    pathPtr += 3;
                    continue;
                } else if (*(pathPtr + 2) == '\0') {
                    return (s32)parentDir(dirLookAt);
                }
            } else if (*(pathPtr + 1) == '/') {
                pathPtr += 2;
                continue;
            } else if (*(pathPtr + 1) == '\0') {
                return (s32)dirLookAt;
            }
        }

        if (__DVDLongFileNameFlag == 0) {
            extention = FALSE;
            illegal = FALSE;

            for (ptr = pathPtr; (*ptr != '\0') && (*ptr != '/'); ptr++) {
                if (*ptr == '.') {
                    if ((ptr - pathPtr > 8) || (extention == TRUE)) {
                        illegal = TRUE;
                        break;
                    }
                    extention = TRUE;
                    extentionStart = ptr + 1;
                } else if (*ptr == ' ') {
                    illegal = TRUE;
                }
            }

            if ((extention == TRUE) && (ptr - extentionStart > 3)) {
                illegal = TRUE;
            }

            if (illegal) {
                OSPanic(kar_srcfile_dvdfs_c_805dc8d8, 387, lbl_804F94C8, pathPtr);
            }
        } else {
            for (ptr = pathPtr; (*ptr != '\0') && (*ptr != '/'); ptr++)
                ;
        }

        isDir = (*ptr == '\0') ? FALSE : TRUE;
        length = (u32)(ptr - pathPtr);

        ptr = pathPtr;

        for (i = dirLookAt + 1; i < nextDir(dirLookAt); i = entryIsDir(i) ? nextDir(i) : (i + 1)) {
            if ((entryIsDir(i) == FALSE) && (isDir == TRUE)) {
                continue;
            }

            stringPtr = FstStringStart + stringOff(i);

            if (isSame(ptr, stringPtr) == TRUE) {
                goto next_hier;
            }
        }

        return -1;

    next_hier:
        if (!isDir) {
            return (s32)i;
        }

        dirLookAt = i;
        pathPtr += length + 1;
    }
}

BOOL kar_lbfile__803c51c8(s32 entrynum, DVDFileInfo* fileInfo)
{
    if (entrynum < 0 || (u32)entrynum >= MaxEntryNum || entryIsDir(entrynum)) {
        return FALSE;
    }

    fileInfo->startAddr = filePosition(entrynum);
    fileInfo->length = fileLength(entrynum);
    fileInfo->callback = NULL;
    fileInfo->cb.state = DVD_STATE_END;

    return TRUE;
}

BOOL DVDOpen(const char* fileName, DVDFileInfo* fileInfo)
{
    s32 entry;
    char currentDir[128];

    entry = DVDConvertPathToEntrynum(fileName);

    if (0 > entry) {
        DVDGetCurrentDir(currentDir, 128);
        OSReport(lbl_804F9590, fileName, currentDir);
        return FALSE;
    }

    if (entryIsDir(entry)) {
        return FALSE;
    }

    fileInfo->startAddr = filePosition(entry);
    fileInfo->length = fileLength(entry);
    fileInfo->callback = NULL;
    fileInfo->cb.state = DVD_STATE_END;

    return TRUE;
}

BOOL DVDClose(DVDFileInfo* fileInfo)
{
    DVDCancel((volatile DVDCommandBlock*)&(fileInfo->cb));
    return TRUE;
}

#pragma dont_inline on

u32 fn_803C5328(u32 entry, char* path, u32 maxlen)
{
    char* name;
    u32 loc;
    char* dest;
    u32 remain;
    u32 i;

    if (entry == 0) {
        return 0;
    }

    name = FstStringStart + stringOff(entry);

    if (parentDir(entry) == 0) {
        loc = 0;
    } else {
        loc = fn_803C5328(parentDir(entry), path, maxlen);
    }

    if (loc == maxlen) {
        return loc;
    }

    *(path + loc++) = '/';

    dest = path + loc;
    remain = maxlen - loc;
    i = remain;
    while ((i > 0) && (*name != 0)) {
        *dest++ = *name++;
        i--;
    }
    loc += remain - i;

    return loc;
}

#pragma dont_inline off

BOOL DVDGetCurrentDir(char* path, u32 maxlen)
{
    s32 entrynum = (s32)lbl_805DDD98;
    u32 loc = fn_803C5328((u32)entrynum, path, maxlen);

    if (loc == maxlen) {
        path[maxlen - 1] = '\0';
        return FALSE;
    }

    if (entryIsDir(entrynum)) {
        if (loc == maxlen - 1) {
            path[loc] = '\0';
            return FALSE;
        }

        path[loc++] = '/';
    }

    path[loc] = '\0';
    return TRUE;
}

BOOL DVDReadAsyncPrio(DVDFileInfo* fileInfo, void* addr, s32 length, s32 offset, void (*callback)(s32, DVDFileInfo*),
                      s32 prio)
{
    DVD_ASSERTMSGLINE(0x2e6, (0 <= offset) && (offset <= (s32)fileInfo->length),
                       "DVDReadAsync(): specified area is out of the file  ");

    DVD_ASSERTMSGLINE(0x2ec, (0 <= offset + length) && (offset + length < (s32)fileInfo->length + DVD_MIN_TRANSFER_SIZE),
                       "DVDReadAsync(): specified area is out of the file  ");

    fileInfo->callback = callback;
    DVDReadAbsAsyncPrio(&(fileInfo->cb), addr, length, (s32)(fileInfo->startAddr + offset), cbForReadAsync, prio);
    return TRUE;
}

#define offsetof_cb ((u32) & ((DVDFileInfo*)0)->cb)

void cbForReadAsync(s32 result, DVDCommandBlock* block)
{
    DVDFileInfo* fileInfo;

    fileInfo = (DVDFileInfo*)((char*)block - offsetof_cb);
    if (fileInfo->callback) {
        (fileInfo->callback)(result, fileInfo);
    }
}

s32 DVDReadPrio(DVDFileInfo* fileInfo, void* addr, s32 length, s32 offset, s32 prio)
{
    int result;
    DVDCommandBlock* block;
    s32 state;
    BOOL enabled;
    s32 retVal;

    DVD_ASSERTMSGLINE(0x32c, (0 <= offset) && (offset <= (s32)fileInfo->length),
                       "DVDRead(): specified area is out of the file  ");
    DVD_ASSERTMSGLINE(0x332, (0 <= offset + length) && (offset + length < (s32)fileInfo->length + DVD_MIN_TRANSFER_SIZE),
                       "DVDRead(): specified area is out of the file  ");

    block = &fileInfo->cb;
    result = DVDReadAbsAsyncPrio(block, addr, length, fileInfo->startAddr + offset, fn_803C5754, prio);
    if (result == 0) {
        return -1;
    }
    enabled = OSDisableInterrupts();

    while (1) {
        state = ((volatile DVDCommandBlock*)block)->state;
        if (state == 0) {
            retVal = (s32)block->transferredSize;
            break;
        } else if (state == -1) {
            retVal = -1;
            break;
        } else if (state == 10) {
            retVal = -3;
            break;
        }
        OSSleepThread(&__DVDThreadQueue);
    }

    OSRestoreInterrupts(enabled);
    return retVal;
}

void fn_803C5754(s32 result, DVDCommandBlock* block)
{
    OSWakeupThread(&__DVDThreadQueue);
}

void fn_803C5778(DVDCommandBlock* block, DVDCommandCheckerCallback cb)
{
}

char* __DVDVersion = "<< Dolphin SDK - DVD\trelease build: Oct 29 2002 09:56:49 (0x2301) >>";

static BOOL autoInvalidation = TRUE;
static DVDCommandChecker checkOptionalCommand = fn_803C5778;

static DVDBB2 BB2 __attribute__((aligned(32)));
static DVDDiskID lbl_8056CC40; /* CurrDiskID */
static DVDCommandBlock DummyCommandBlock;
static OSAlarm ResetAlarm;

static DVDCommandBlock* executing;
static DVDDiskID* IDShouldBe;
static OSBootInfo* bootInfo;
static volatile int PauseFlag;
static volatile int PausingFlag;
static int lbl_805DDDBC; /* AutoFinishing */
static BOOL FatalErrorFlag;
static volatile u32 CurrCommand;
static volatile u32 lbl_805DDDC8; /* Canceling */
static void (*lbl_805DDDCC)(s32, DVDCommandBlock*); /* CancelCallback */
static volatile u32 ResumeFromHere;
static volatile u32 CancelLastError;
static u32 lbl_805DDDD8; /* LastError */
static volatile s32 lbl_805DDDDC; /* NumInternalRetry */
static int ResetRequired;
static BOOL FirstTimeInBootrom;
static u32 MotorState;
static int DVDInitialized;
void (*lbl_805DDDEC)(DVDCommandBlock*); /* LastState */

void stateReadingFST();
void cbForStateReadingFST(u32 intType);
static void cbForStateError(u32 intType);
static inline void stateError(u32 error);
void stateTimeout();
void stateGettingError();
u32 CategorizeError(u32 error);
static inline BOOL CheckCancel(u32 resume);
void cbForStateGettingError(u32 intType);
void cbForUnrecoveredError(u32 intType);
void cbForUnrecoveredErrorRetry(u32 intType);
void stateGoToRetry();
void cbForStateGoToRetry(u32 intType);
void stateCheckID();
void stateCheckID3();
void stateCheckID2a();
void stateCheckID2();
void cbForStateCheckID1(u32 intType);
void cbForStateCheckID2(u32 intType);
void cbForStateCheckID3(u32 intType);
void cbForStateCheckID2a(u32 intType);
static void AlarmHandler(OSAlarm* alarm, OSContext* context);
void stateCoverClosed();
void stateCoverClosed_CMD(DVDCommandBlock* command);
void cbForStateCoverClosed(u32 intType);
void stateMotorStopped();
static void cbForStateMotorStopped(u32 intType);
static void stateReady();
static void stateBusy(DVDCommandBlock* block);
void cbForStateBusy(u32 intType);

void DVDInit(void)
{
    if (!DVDInitialized) {
        OSRegisterVersion(__DVDVersion);
        DVDInitialized = TRUE;

        __DVDFSInit();
        __DVDClearWaitingQueue();
        __DVDInitWA();

        bootInfo = (OSBootInfo*)OSPhysicalToCached(0);
        IDShouldBe = &bootInfo->dvdDiskID;

        __OSSetInterruptHandler(0x15, __DVDInterruptHandler);
        __OSUnmaskInterrupts(0x400);
        OSInitThreadQueue(&__DVDThreadQueue);
        __DIRegs[0] = 0x2A;
        __DIRegs[1] = 0;

        if (bootInfo->magic == 0xE5207C22) {
            OSReport("load fst\n");
            __fstLoad();
        } else if (bootInfo->magic == 0x0D15EA5E) {

        } else {
            FirstTimeInBootrom = TRUE;
        }
    }
}

void stateReadingFST()
{
    lbl_805DDDEC = stateReadingFST;
    DVD_ASSERTMSGLINE_DVD(0x295, bootInfo->FSTMaxLength >= BB2.FSTLength,
                           "DVDChangeDisk(): FST in the new disc is too big.   ");
    DVDLowRead(bootInfo->FSTLocation, (u32)(BB2.FSTLength + 0x1F) & 0xFFFFFFE0, BB2.FSTPosition,
               cbForStateReadingFST);
}

static u32 lbl_805DC8F4[1] = {0xFFFFFFFF}; /* DmaCommand */

void cbForStateReadingFST(u32 intType)
{
    DVDCommandBlock* finished;

    if (intType == 16) {
        executing->state = -1;
        stateTimeout();
        return;
    }

    if (intType & DVD_INTTYPE_TC) {
        lbl_805DDDDC = 0;

        __DVDFSInit();
        finished = executing;
        executing = &DummyCommandBlock;
        finished->state = DVD_STATE_END;

        if (finished->callback) {
            finished->callback(0, finished);
        }

        stateReady();
        return;
    }

    stateGettingError();
}

static void cbForStateError(u32 intType)
{
    DVDCommandBlock* finished;

    if (intType == 16) {
        executing->state = -1;
        stateTimeout();
        return;
    }

    fn_803C82FC();

    FatalErrorFlag = TRUE;
    finished = executing;
    executing = &DummyCommandBlock;

    if (finished->callback) {
        (finished->callback)(-1, finished);
    }

    if (lbl_805DDDC8) {
        lbl_805DDDC8 = FALSE;
        if (lbl_805DDDCC)
            (lbl_805DDDCC)(0, finished);
    }

    stateReady();
}

static inline void stateError(u32 error)
{
    __DVDStoreErrorCode(error);
    DVDLowStopMotor(&cbForStateError);
}

void stateTimeout()
{
    __DVDStoreErrorCode(0x01234568);
    DVDReset();
    cbForStateError(0);
}

void stateGettingError()
{
    DVDLowRequestError(cbForStateGettingError);
}

u32 CategorizeError(u32 error)
{
    if (error == 0x20400) {
        lbl_805DDDD8 = error;
        return 1;
    }

    error &= 0x00FFFFFF;
    if (error == 0x62800 || error == 0x23A00 || error == 0xB5A01) {
        return 0;
    }

    lbl_805DDDDC++;
    if (lbl_805DDDDC == 2) {
        if (error == lbl_805DDDD8) {
            lbl_805DDDD8 = error;
            return 1;
        }
        lbl_805DDDD8 = error;
        return 2;
    }

    lbl_805DDDD8 = error;

    if (error == 0x31100 || executing->command == DVD_COMMAND_READID) {
        return 2;
    }

    return 3;
}

static inline BOOL CheckCancel(u32 resume)
{
    DVDCommandBlock* finished;

    if (lbl_805DDDC8) {
        ResumeFromHere = resume;
        lbl_805DDDC8 = FALSE;

        finished = executing;
        executing = &DummyCommandBlock;

        finished->state = 10;

        if (finished->callback)
            (*finished->callback)(-3, finished);

        if (lbl_805DDDCC)
            (lbl_805DDDCC)(0, finished);

        stateReady();
        return TRUE;
    }

    return FALSE;
}

void cbForStateGettingError(u32 intType)
{
    u32 error;
    u32 status;
    u32 errorCategory;
    u32 resume;

    if (intType == 16) {
        executing->state = -1;
        stateTimeout();
        return;
    }

    if (intType & 2) {
        executing->state = -1;
        stateError(0x1234567);
        return;
    }

    error = __DIRegs[8];
    status = error & 0xff000000;

    errorCategory = CategorizeError(error);

    if (errorCategory == 1) {
        executing->state = -1;
        stateError(error);
        return;
    }

    if (errorCategory == 2 || errorCategory == 3) {
        resume = 0;
    } else {
        if (status == 0x01000000)
            resume = 4;
        else if (status == 0x02000000)
            resume = 6;
        else if (status == 0x03000000)
            resume = 3;
        else
            resume = 5;
    }

    if (CheckCancel(resume))
        return;

    if (errorCategory == 2) {
        __DVDStoreErrorCode(error);
        stateGoToRetry();
        return;
    }

    if (errorCategory == 3) {
        if ((error & 0x00ffffff) == 0x00031100) {
            DVDLowSeek(executing->offset, cbForUnrecoveredError);
        } else {
            lbl_805DDDEC(executing);
        }
        return;
    }

    if (status == 0x01000000) {
        executing->state = 5;
        stateMotorStopped();
        return;
    } else if (status == 0x02000000) {
        executing->state = 3;
        stateCoverClosed();
        return;
    } else if (status == 0x03000000) {
        executing->state = 4;
        stateMotorStopped();
        return;
    } else {
        executing->state = -1;
        stateError(0x1234567);
        return;
    }
}

void cbForUnrecoveredError(u32 intType)
{
    if (intType == 16) {
        executing->state = -1;
        stateTimeout();
        return;
    }

    if (intType & 1) {
        stateGoToRetry();
        return;
    }

    DVDLowRequestError(cbForUnrecoveredErrorRetry);
}

void cbForUnrecoveredErrorRetry(u32 intType)
{
    if (intType == 0x10) {
        executing->state = -1;
        stateTimeout();
    } else {
        executing->state = -1;
        if (intType & 2) {
            stateError(0x01234567);
            return;
        }

        stateError(__DIRegs[8]);
    }
}

void stateGoToRetry()
{
    DVDLowStopMotor(cbForStateGoToRetry);
}

void cbForStateGoToRetry(u32 intType)
{
    if (intType == 16) {
        executing->state = -1;
        stateTimeout();
        return;
    }

    if (intType & 2) {
        executing->state = -1;
        stateError(0x1234567);
        return;
    }

    lbl_805DDDDC = 0;

    if (CurrCommand == 4 || CurrCommand == 5 || CurrCommand == 13 || CurrCommand == 15) {
        ResetRequired = TRUE;
    }

    if (!CheckCancel(2)) {
        executing->state = 11;
        stateMotorStopped();
    }
}

void stateCheckID()
{
    switch (CurrCommand) {
    case DVD_COMMAND_CHANGE_DISK:
        if (DVDCompareDiskID(&lbl_8056CC40, executing->id)) {
            memcpy(IDShouldBe, &lbl_8056CC40, sizeof(DVDDiskID));
            executing->state = DVD_STATE_BUSY;
            DCInvalidateRange(&BB2.bootFilePosition, 0x20);
            lbl_805DDDEC = stateCheckID2a;
            stateCheckID2a(executing);
        } else {
            DVDLowStopMotor(cbForStateCheckID1);
        }
        break;
    default:
        if (memcmp(&lbl_8056CC40, IDShouldBe, sizeof(DVDDiskID)) != 0) {
            DVDLowStopMotor(cbForStateCheckID1);
        } else {
            lbl_805DDDEC = stateCheckID3;
            stateCheckID3(executing);
        }
        break;
    }
}

void stateCheckID3()
{
    DVDLowAudioBufferConfig(IDShouldBe->streaming, 0xA, cbForStateCheckID3);
}

void stateCheckID2a()
{
    DVDLowAudioBufferConfig(IDShouldBe->streaming, 0xA, cbForStateCheckID2a);
}

void cbForStateCheckID2a(u32 intType)
{
    if (intType == 16) {
        executing->state = -1;
        stateTimeout();
        return;
    }

    if (intType & DVD_INTTYPE_TC) {
        lbl_805DDDDC = 0;
        stateCheckID2(executing);
        return;
    }

    stateGettingError();
}

void stateCheckID2()
{
    DVDLowRead(&BB2, 0x20, 0x420, cbForStateCheckID2);
}

void cbForStateCheckID1(u32 intType)
{
    if (intType == 16) {
        executing->state = -1;
        stateTimeout();
        return;
    }

    if (intType & DVD_INTTYPE_DE) {
        executing->state = -1;
        stateError(0x01234567);
        return;
    }

    lbl_805DDDDC = 0;

    if (CheckCancel(1) == FALSE) {
        executing->state = DVD_STATE_WRONG_DISK;
        stateMotorStopped();
    }
}

void cbForStateCheckID2(u32 intType)
{
    if (intType == 16) {
        executing->state = -1;
        stateTimeout();
        return;
    }

    if (intType & DVD_INTTYPE_TC) {
        lbl_805DDDDC = 0;
        stateReadingFST();
        return;
    }

    stateGettingError();
}

void cbForStateCheckID3(u32 intType)
{
    if (intType == 16) {
        executing->state = -1;
        stateTimeout();
        return;
    }

    if (intType & DVD_INTTYPE_TC) {
        lbl_805DDDDC = 0;
        if (CheckCancel(0) == FALSE) {
            executing->state = DVD_STATE_BUSY;
            stateBusy(executing);
        }
        return;
    }

    stateGettingError();
}

static void AlarmHandler(OSAlarm* alarm, OSContext* context)
{
    DVDReset();
    DCInvalidateRange(&lbl_8056CC40, sizeof(DVDDiskID));
    lbl_805DDDEC = &stateCoverClosed_CMD;
    stateCoverClosed_CMD(executing);
}

void stateCoverClosed()
{
    DVDCommandBlock* finished;

    switch (CurrCommand) {
    case DVD_COMMAND_BSREAD:
    case DVD_COMMAND_READID:
    case DVD_COMMAND_AUDIO_BUFFER_CONFIG:
    case DVD_COMMAND_BS_CHANGE_DISK:
        __DVDClearWaitingQueue();
        finished = executing;
        executing = &DummyCommandBlock;
        if (finished->callback) {
            finished->callback(-4, finished);
        }
        stateReady();
        break;
    default:
        DVDReset();
        OSCreateAlarm(&ResetAlarm);
        OSSetAlarm(&ResetAlarm, OSMillisecondsToTicks(1150), &AlarmHandler);
        break;
    }
}

void stateCoverClosed_CMD(DVDCommandBlock* command)
{
    DVDLowReadDiskID(&lbl_8056CC40, cbForStateCoverClosed);
}

void cbForStateCoverClosed(u32 intType)
{
    if (intType == 16) {
        executing->state = -1;
        stateTimeout();
        return;
    }

    if (intType & DVD_INTTYPE_TC) {
        lbl_805DDDDC = 0;
        stateCheckID();
        return;
    }

    stateGettingError();
}

void stateMotorStopped()
{
    DVDLowWaitCoverClose(cbForStateMotorStopped);
}

static void cbForStateMotorStopped(u32 intType)
{
    __DIRegs[1] = 0;
    executing->state = DVD_STATE_COVER_CLOSED;
    stateCoverClosed();
}

static void stateReady()
{
    if (__DVDCheckWaitingQueue() == 0) {
        executing = NULL;
        return;
    }

    if (PauseFlag != 0) {
        PausingFlag = 1;
        executing = NULL;
        return;
    }

    executing = __DVDPopWaitingQueue();

    if (FatalErrorFlag) {
        DVDCommandBlock* finished;

        executing->state = DVD_STATE_FATAL_ERROR;
        finished = executing;
        executing = &DummyCommandBlock;
        if (finished->callback) {
            (*finished->callback)(-1, finished);
        }

        stateReady();
        return;
    }

    CurrCommand = executing->command;
    if (ResumeFromHere != 0) {
        switch (ResumeFromHere) {
        case 2:
            executing->state = DVD_STATE_RETRY;
            stateMotorStopped();
            break;
        case 3:
            executing->state = DVD_STATE_NO_DISK;
            stateMotorStopped();
            break;
        case 4:
            executing->state = DVD_STATE_COVER_OPEN;
            stateMotorStopped();
            break;
        case 1:
        case 6:
        case 7:
            executing->state = DVD_STATE_COVER_CLOSED;
            stateCoverClosed();
            break;
        case 5:
            executing->state = DVD_STATE_FATAL_ERROR;
            stateError(CancelLastError);
            break;
        }

        ResumeFromHere = 0;
        return;
    }

    executing->state = DVD_STATE_BUSY;
    stateBusy(executing);
}

static void stateBusy(DVDCommandBlock* block)
{
    DVDCommandBlock* finished;
    lbl_805DDDEC = stateBusy;

    switch (block->command) {
    case DVD_COMMAND_READID:
        __DIRegs[1] = __DIRegs[1];
        block->currTransferSize = 0x20;
        DVDLowReadDiskID(block->addr, cbForStateBusy);
        return;
    case DVD_COMMAND_READ:
    case DVD_COMMAND_BSREAD:
        if (block->length == 0) {
            finished = executing;
            executing = &DummyCommandBlock;
            finished->state = 0;

            if (finished->callback != 0) {
                (*finished->callback)(0, finished);
            }

            stateReady();
        } else {
            __DIRegs[1] = __DIRegs[1];
            block->currTransferSize =
                (block->length - block->transferredSize > 0x80000) ? 0x80000 : (block->length - block->transferredSize);
            DVDLowRead((char*)block->addr + block->transferredSize, block->currTransferSize,
                       block->offset + block->transferredSize, cbForStateBusy);
        }
        return;
    case DVD_COMMAND_SEEK:
        __DIRegs[1] = __DIRegs[1];
        DVDLowSeek(block->offset, cbForStateBusy);
        return;
    case DVD_COMMAND_CHANGE_DISK:
        DVDLowStopMotor(cbForStateBusy);
        return;
    case DVD_COMMAND_BS_CHANGE_DISK:
        DVDLowStopMotor(cbForStateBusy);
        return;
    case DVD_COMMAND_INITSTREAM:
        __DIRegs[1] = __DIRegs[1];
        if (lbl_805DDDBC != 0) {
            executing->currTransferSize = 0;
            DVDLowRequestAudioStatus(0, cbForStateBusy);
            return;
        }
        executing->currTransferSize = 1;
        DVDLowAudioStream(0, block->length, block->offset, cbForStateBusy);
        return;
    case DVD_COMMAND_CANCELSTREAM:
        __DIRegs[1] = __DIRegs[1];
        DVDLowAudioStream(0x10000, 0U, 0U, cbForStateBusy);
        return;
    case DVD_COMMAND_STOP_STREAM_AT_END:
        __DIRegs[1] = __DIRegs[1];
        lbl_805DDDBC = 1;
        DVDLowAudioStream(0, 0U, 0U, cbForStateBusy);
        return;
    case DVD_COMMAND_REQUEST_AUDIO_ERROR:
        __DIRegs[1] = __DIRegs[1];
        DVDLowRequestAudioStatus(0, cbForStateBusy);
        return;
    case DVD_COMMAND_REQUEST_PLAY_ADDR:
        __DIRegs[1] = __DIRegs[1];
        DVDLowRequestAudioStatus(0x10000, cbForStateBusy);
        return;
    case DVD_COMMAND_REQUEST_START_ADDR:
        __DIRegs[1] = __DIRegs[1];
        DVDLowRequestAudioStatus(0x20000, cbForStateBusy);
        return;
    case DVD_COMMAND_REQUEST_LENGTH:
        __DIRegs[1] = __DIRegs[1];
        DVDLowRequestAudioStatus(0x30000, cbForStateBusy);
        return;
    case DVD_COMMAND_AUDIO_BUFFER_CONFIG:
        __DIRegs[1] = __DIRegs[1];
        DVDLowAudioBufferConfig(block->offset, block->length, cbForStateBusy);
        return;
    case DVD_COMMAND_INQUIRY:
        __DIRegs[1] = __DIRegs[1];
        block->currTransferSize = 0x20;
        DVDLowInquiry(block->addr, cbForStateBusy);
        return;
    case DVD_COMMAND_UNK_16:
        __DIRegs[1] = __DIRegs[1];
        DVDLowStopMotor(cbForStateBusy);
        return;
    default:
        checkOptionalCommand(block, cbForStateBusy);
        return;
    }
}

static u32 lbl_804F96F8[3] = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}; /* ImmCommand */

static inline BOOL IsImmCommandWithResult(u32 command)
{
    u32 i;

    if (command == 9 || command == 10 || command == 11 || command == 12) {
        return 1;
    }

    for (i = 0; i < 3; i++) {
        if (command == lbl_804F96F8[i]) {
            return TRUE;
        }
    }

    return FALSE;
}

static inline int IsDmaCommand(u32 command)
{
    u32 i;

    if (command == 1 || command == 4 || command == 5 || command == 14) {
        return 1;
    }

    for (i = 0; i < 1; i++) {
        if (command == lbl_805DC8F4[i]) {
            return TRUE;
        }
    }

    return FALSE;
}

void cbForStateBusy(u32 intType)
{
    DVDCommandBlock* finished;
    s32 result;

    if (intType == 16) {
        executing->state = -1;
        stateTimeout();
        return;
    }

    if ((CurrCommand == DVD_COMMAND_CHANGE_DISK) || (CurrCommand == DVD_COMMAND_BS_CHANGE_DISK)) {
        if (intType & DVD_INTTYPE_DE) {
            executing->state = -1;
            stateError(0x01234567);
            return;
        }

        lbl_805DDDDC = 0;

        if (CurrCommand == DVD_COMMAND_BS_CHANGE_DISK) {
            ResetRequired = 1;
        }

        if (CheckCancel(7) == FALSE) {
            executing->state = DVD_STATE_MOTOR_STOPPED;
            stateMotorStopped();
        }
        return;
    }

    if (IsDmaCommand(CurrCommand)) {
        executing->transferredSize += executing->currTransferSize - __DIRegs[6];
    }

    if (intType & 8) {
        lbl_805DDDC8 = 0;
        finished = executing;
        executing = &DummyCommandBlock;
        finished->state = DVD_STATE_CANCELED;

        if (finished->callback) {
            finished->callback(-3, finished);
        }

        if (lbl_805DDDCC) {
            lbl_805DDDCC(0, finished);
        }

        stateReady();
        return;
    }

    if (intType & 1) {
        lbl_805DDDDC = 0;

        if (CurrCommand == 0x10) {
            MotorState = 1;
            finished = executing;
            executing = &DummyCommandBlock;
            finished->state = 0;

            if (finished->callback != 0) {
                (*finished->callback)(0, finished);
            }

            stateReady();
            return;
        }

        if (CheckCancel(0) != FALSE) {
            return;
        }

        if (IsDmaCommand(CurrCommand)) {
            if (executing->transferredSize != executing->length) {
                stateBusy(executing);
                return;
            }

            finished = executing;
            executing = &DummyCommandBlock;
            finished->state = DVD_STATE_END;
            if (finished->callback) {
                finished->callback(finished->transferredSize, finished);
            }

            stateReady();
            return;
        } else if (IsImmCommandWithResult(CurrCommand)) {
            if (CurrCommand == DVD_COMMAND_REQUEST_START_ADDR || CurrCommand == DVD_COMMAND_REQUEST_PLAY_ADDR) {
                result = __DIRegs[8] * 4;
            } else {
                result = __DIRegs[8];
            }

            finished = executing;
            executing = &DummyCommandBlock;
            finished->state = DVD_STATE_END;
            if (finished->callback) {
                finished->callback(result, finished);
            }

            stateReady();
            return;
        } else if (CurrCommand == DVD_COMMAND_INITSTREAM) {
            if (executing->currTransferSize == 0) {
                if (__DIRegs[8] & 1) {
                    finished = executing;
                    executing = &DummyCommandBlock;
                    finished->state = DVD_STATE_IGNORED;
                    if (finished->callback) {
                        finished->callback(-2, finished);
                    }
                    stateReady();
                    return;
                }

                lbl_805DDDBC = 0;
                executing->currTransferSize = 1;
                DVDLowAudioStream(0, executing->length, executing->offset, cbForStateBusy);
                return;
            }

            finished = executing;
            executing = &DummyCommandBlock;
            finished->state = DVD_STATE_END;
            if (finished->callback) {
                finished->callback(0, finished);
            }

            stateReady();
            return;
        } else {
            finished = executing;
            executing = &DummyCommandBlock;
            finished->state = DVD_STATE_END;
            if (finished->callback) {
                finished->callback(0, finished);
            }

            stateReady();
            return;
        }
    } else {
        if (CurrCommand == 14) {
            executing->state = -1;
            stateError(0x01234567);
            return;
        }

        if ((CurrCommand == 1 || CurrCommand == 4 || CurrCommand == 5 || CurrCommand == 14) &&
            (executing->transferredSize == executing->length)) {

            if (CheckCancel(0)) {
                return;
            }
            finished = executing;
            executing = &DummyCommandBlock;

            finished->state = DVD_STATE_END;
            if (finished->callback) {
                (finished->callback)((s32)finished->transferredSize, finished);
            }
            stateReady();
            return;
        }

        stateGettingError();
    }
}

int DVDReadAbsAsyncPrio(DVDCommandBlock* block, void* addr, s32 length, s32 offset, DVDCBCallback callback, s32 prio)
{
    int result;
    BOOL level;
    int idle;

    block->command = DVD_COMMAND_READ;
    block->addr = addr;
    block->length = length;
    block->offset = offset;
    block->transferredSize = 0;
    block->callback = callback;

    if (autoInvalidation != 0 &&
        (block->command == DVD_COMMAND_READ || block->command == DVD_COMMAND_BSREAD ||
         block->command == DVD_COMMAND_READID || block->command == DVD_COMMAND_INQUIRY)) {
        DCInvalidateRange(block->addr, block->length);
    }

    level = OSDisableInterrupts();

    block->state = DVD_STATE_WAITING;
    result = __DVDPushWaitingQueue(prio, block);
    if (executing == NULL && PauseFlag == 0) {
        stateReady();
    }

    OSRestoreInterrupts(level);
    idle = result;
    return idle;
}

int DVDReadAbsAsyncForBS(DVDCommandBlock* block, void* addr, s32 length, s32 offset, DVDCBCallback callback)
{
    int result;
    BOOL level;
    int idle;

    block->command = DVD_COMMAND_BSREAD;
    block->addr = addr;
    block->length = length;
    block->offset = offset;
    block->transferredSize = 0;
    block->callback = callback;

    if (autoInvalidation != 0 &&
        (block->command == DVD_COMMAND_READ || block->command == DVD_COMMAND_BSREAD ||
         block->command == DVD_COMMAND_READID || block->command == DVD_COMMAND_INQUIRY)) {
        DCInvalidateRange(block->addr, block->length);
    }

    level = OSDisableInterrupts();

    block->state = DVD_STATE_WAITING;
    result = __DVDPushWaitingQueue(2, block);
    if (executing == NULL && PauseFlag == 0) {
        stateReady();
    }

    OSRestoreInterrupts(level);
    idle = result;
    return idle;
}

int DVDReadDiskID(DVDCommandBlock* block, DVDDiskID* diskID, DVDCBCallback callback)
{
    int result;
    BOOL level;
    int idle;

    block->command = DVD_COMMAND_READID;
    block->addr = diskID;
    block->length = 0x20;
    block->offset = 0;
    block->transferredSize = 0;
    block->callback = callback;

    if (autoInvalidation != 0 &&
        (block->command == DVD_COMMAND_READ || block->command == DVD_COMMAND_BSREAD ||
         block->command == DVD_COMMAND_READID || block->command == DVD_COMMAND_INQUIRY)) {
        DCInvalidateRange(block->addr, block->length);
    }

    level = OSDisableInterrupts();

    block->state = DVD_STATE_WAITING;
    result = __DVDPushWaitingQueue(2, block);
    if (executing == NULL && PauseFlag == 0) {
        stateReady();
    }

    OSRestoreInterrupts(level);
    idle = result;
    return idle;
}

static inline void cbForCancelStreamSync(s32 result, DVDCommandBlock* block)
{
    block->transferredSize = (u32)result;
    OSWakeupThread(&__DVDThreadQueue);
}

int DVDCancelStreamAsync(DVDCommandBlock* block, DVDCBCallback callback)
{
    int result;
    BOOL level;
    int idle;

    block->command = DVD_COMMAND_CANCELSTREAM;
    block->callback = callback;
    if (autoInvalidation != 0 &&
        (block->command == DVD_COMMAND_READ || block->command == DVD_COMMAND_BSREAD ||
         block->command == DVD_COMMAND_READID || block->command == DVD_COMMAND_INQUIRY)) {
        DCInvalidateRange(block->addr, block->length);
    }

    level = OSDisableInterrupts();

    block->state = DVD_STATE_WAITING;
    result = __DVDPushWaitingQueue(1, block);
    if (executing == NULL && PauseFlag == 0) {
        stateReady();
    }

    OSRestoreInterrupts(level);
    idle = result;
    return idle;
}

static inline void cbForInquirySync(s32 result, DVDCommandBlock* block)
{
    OSWakeupThread(&__DVDThreadQueue);
}

int DVDInquiryAsync(DVDCommandBlock* block, DVDDriveInfo* info, DVDCBCallback callback)
{
    int result;
    BOOL level;
    int idle;

    block->command = DVD_COMMAND_INQUIRY;
    block->addr = info;
    block->length = 0x20;
    block->transferredSize = 0;
    block->callback = callback;
    if (autoInvalidation != 0 &&
        (block->command == DVD_COMMAND_READ || block->command == DVD_COMMAND_BSREAD ||
         block->command == DVD_COMMAND_READID || block->command == DVD_COMMAND_INQUIRY)) {
        DCInvalidateRange(block->addr, block->length);
    }

    level = OSDisableInterrupts();

    block->state = DVD_STATE_WAITING;
    result = __DVDPushWaitingQueue(2, block);
    if (executing == NULL && PauseFlag == 0) {
        stateReady();
    }

    OSRestoreInterrupts(level);
    idle = result;
    return idle;
}

#pragma dont_inline on

void DVDReset(void)
{
    DVDLowReset();
    __DIRegs[0] = 0x2A;
    __DIRegs[1] = __DIRegs[1];
    ResetRequired = 0;
    ResumeFromHere = 0;
}

#pragma dont_inline off

s32 DVDGetCommandBlockStatus(const DVDCommandBlock* block)
{
    BOOL enabled;
    s32 retVal;

    enabled = OSDisableInterrupts();

    if (block->state == 3) {
        retVal = 1;
    } else {
        retVal = block->state;
    }

    OSRestoreInterrupts(enabled);
    return retVal;
}

s32 DVDGetDriveStatus(void)
{
    BOOL enabled = OSDisableInterrupts();
    s32 retVal;

    if (FatalErrorFlag != FALSE) {
        retVal = DVD_STATE_FATAL_ERROR;
    } else {
        if (PausingFlag != FALSE) {
            retVal = DVD_STATE_PAUSING;
        } else {
            if (executing == NULL) {
                retVal = DVD_STATE_END;
            } else if (executing == &DummyCommandBlock) {
                retVal = DVD_STATE_END;
            } else {
                retVal = DVDGetCommandBlockStatus((DVDCommandBlock*)executing);
            }
        }
    }
    OSRestoreInterrupts(enabled);
    return retVal;
}

BOOL DVDSetAutoInvalidation(BOOL autoInval)
{
    BOOL prev;

    prev = autoInvalidation;
    autoInvalidation = autoInval;
    return prev;
}

void DVDResume(void)
{
    BOOL level;

    level = OSDisableInterrupts();
    PauseFlag = 0;
    if (PausingFlag != 0) {
        PausingFlag = 0;
        stateReady();
    }
    OSRestoreInterrupts(level);
}

int DVDCancelAsync(DVDCommandBlock* block, DVDCBCallback callback)
{
    BOOL enabled;
    DVDLowCallback old;
    DVDCommandBlock* finished;

    enabled = OSDisableInterrupts();

    switch (block->state) {
    case DVD_STATE_FATAL_ERROR:
    case DVD_STATE_END:
    case DVD_STATE_CANCELED:
        if (callback)
            (*callback)(0, block);
        break;
    case DVD_STATE_BUSY:
        if (lbl_805DDDC8) {
            OSRestoreInterrupts(enabled);
            return FALSE;
        }

        lbl_805DDDC8 = TRUE;
        lbl_805DDDCC = callback;
        if (block->command == DVD_COMMAND_BSREAD || block->command == DVD_COMMAND_READ) {
            DVDLowBreak();
        }
        break;
    case DVD_STATE_WAITING:
        __DVDDequeueWaitingQueue(block);
        block->state = DVD_STATE_CANCELED;

        if (block->callback)
            (block->callback)(-3, block);

        if (callback)
            (*callback)(0, block);
        break;
    case DVD_STATE_COVER_CLOSED:
        switch (block->command) {
        case DVD_COMMAND_READID:
        case DVD_COMMAND_BSREAD:
        case DVD_COMMAND_AUDIO_BUFFER_CONFIG:
        case DVD_COMMAND_BS_CHANGE_DISK:
            if (callback)
                (*callback)(0, block);
            break;

        default:
            if (lbl_805DDDC8) {
                OSRestoreInterrupts(enabled);
                return FALSE;
            }
            lbl_805DDDC8 = TRUE;
            lbl_805DDDCC = callback;
            break;
        }
        break;
    case DVD_STATE_NO_DISK:
    case DVD_STATE_COVER_OPEN:
    case DVD_STATE_WRONG_DISK:
    case DVD_STATE_MOTOR_STOPPED:
    case DVD_STATE_RETRY:
        old = DVDLowClearCallback();

        if (old != cbForStateMotorStopped) {
            OSRestoreInterrupts(enabled);
            return FALSE;
        }

        if (block->state == DVD_STATE_NO_DISK)
            ResumeFromHere = 3;
        if (block->state == DVD_STATE_COVER_OPEN)
            ResumeFromHere = 4;
        if (block->state == DVD_STATE_WRONG_DISK)
            ResumeFromHere = 1;
        if (block->state == DVD_STATE_RETRY)
            ResumeFromHere = 2;
        if (block->state == DVD_STATE_MOTOR_STOPPED)
            ResumeFromHere = 7;

        finished = executing;
        executing = &DummyCommandBlock;

        block->state = DVD_STATE_CANCELED;
        if (block->callback) {
            (block->callback)(-3, block);
        }

        if (callback) {
            (callback)(0, block);
        }
        stateReady();
        break;
    }

    OSRestoreInterrupts(enabled);
    return TRUE;
}

s32 DVDCancel(volatile DVDCommandBlock* block)
{
    int result;
    s32 state;
    u32 command;
    BOOL enabled;

    result = DVDCancelAsync((DVDCommandBlock*)block, fn_803C7C34);
    if (result == 0) {
        return -1;
    }

    enabled = OSDisableInterrupts();
    while (1) {
        state = block->state;
        if (state == DVD_STATE_END || state == DVD_STATE_FATAL_ERROR || state == DVD_STATE_CANCELED) {
            break;
        }

        if (state == DVD_STATE_COVER_CLOSED) {
            command = block->command;
            if ((command == DVD_COMMAND_BSREAD) || (command == DVD_COMMAND_READID) ||
                (command == DVD_COMMAND_AUDIO_BUFFER_CONFIG) || (command == DVD_COMMAND_BS_CHANGE_DISK)) {
                break;
            }
        }
        OSSleepThread(&__DVDThreadQueue);
    }

    OSRestoreInterrupts(enabled);
    return 0;
}

void fn_803C7C34(s32 result, DVDCommandBlock* block)
{
    OSWakeupThread(&__DVDThreadQueue);
}

DVDDiskID* DVDGetCurrentDiskID(void)
{
    return (DVDDiskID*)OSPhysicalToCached(0);
}

BOOL DVDCheckDisk(void)
{
    BOOL enabled;
    s32 retVal;
    s32 state;
    u32 coverReg;

    enabled = OSDisableInterrupts();

    if (FatalErrorFlag) {
        state = -1;
    } else if (PausingFlag) {
        state = 8;
    } else {
        if (executing == NULL) {
            state = 0;
        } else if (executing == &DummyCommandBlock) {
            state = 0;
        } else {
            state = executing->state;
        }
    }

    switch (state) {
    case DVD_STATE_BUSY:
    case DVD_STATE_IGNORED:
    case DVD_STATE_CANCELED:
    case DVD_STATE_WAITING:
        retVal = TRUE;
        break;
    case DVD_STATE_FATAL_ERROR:
    case DVD_STATE_RETRY:
    case DVD_STATE_MOTOR_STOPPED:
    case DVD_STATE_COVER_CLOSED:
    case DVD_STATE_NO_DISK:
    case DVD_STATE_COVER_OPEN:
    case DVD_STATE_WRONG_DISK:
        retVal = FALSE;
        break;
    case DVD_STATE_END:
    case DVD_STATE_PAUSING:
        coverReg = __DIRegs[1];
        if (((coverReg >> 2) & 1) || (coverReg & 1)) {
            retVal = FALSE;
        } else if (ResumeFromHere != 0) {
            retVal = FALSE;
        } else {
            retVal = TRUE;
        }
    }

    OSRestoreInterrupts(enabled);
    return retVal;
}

void __DVDPrepareResetAsync(DVDCBCallback callback)
{
    BOOL enabled;
    BOOL enabled2;
    BOOL enabled3;
    DVDCommandBlock* p;

    enabled = OSDisableInterrupts();

    __DVDClearWaitingQueue();

    if (lbl_805DDDC8) {
        lbl_805DDDCC = callback;
    } else {
        if (executing) {
            executing->callback = NULL;
        }

        enabled2 = OSDisableInterrupts();

        enabled3 = OSDisableInterrupts();
        PauseFlag = 1;
        if (executing == NULL) {
            PausingFlag = 1;
        }
        OSRestoreInterrupts(enabled3);

        while ((p = __DVDPopWaitingQueue()) != NULL) {
            DVDCancelAsync(p, NULL);
        }

        if (executing) {
            DVDCancelAsync(executing, callback);
        } else {
            if (callback) {
                callback(0, NULL);
            }
        }

        enabled3 = OSDisableInterrupts();
        PauseFlag = 0;
        if (PausingFlag != 0) {
            PausingFlag = 0;
            stateReady();
        }
        OSRestoreInterrupts(enabled3);

        OSRestoreInterrupts(enabled2);
    }

    OSRestoreInterrupts(enabled);
}

static struct
{
    DVDCommandBlock* next;
    DVDCommandBlock* prev;
} WaitingQueue[4];

void __DVDClearWaitingQueue(void)
{
    u32 i;
    DVDCommandBlock* q;

    for (i = 0; i < 4; i++) {
        q = (DVDCommandBlock*)&WaitingQueue[i].next;
        q->next = q;
        q->prev = q;
    }
}

int __DVDPushWaitingQueue(s32 prio, DVDCommandBlock* block)
{
    BOOL enabled = OSDisableInterrupts();
    DVDCommandBlock* q = (DVDCommandBlock*)&WaitingQueue[prio];

    q->prev->next = block;
    block->prev = q->prev;
    block->next = q;
    q->prev = block;
    OSRestoreInterrupts(enabled);
    return 1;
}

DVDCommandBlock* __DVDPopWaitingQueue(void)
{
    u32 i;
    BOOL enabled;
    DVDCommandBlock* q;
    DVDCommandBlock* tmp;

    enabled = OSDisableInterrupts();
    for (i = 0; i < 4; i++) {
        q = (DVDCommandBlock*)&WaitingQueue[i];
        if (q->next != q) {
            OSRestoreInterrupts(enabled);

            enabled = OSDisableInterrupts();
            q = (DVDCommandBlock*)&WaitingQueue[i];
            tmp = q->next;
            q->next = tmp->next;
            tmp->next->prev = q;
            OSRestoreInterrupts(enabled);
            tmp->next = 0;
            tmp->prev = 0;
            return tmp;
        }
    }

    OSRestoreInterrupts(enabled);
    return NULL;
}

int __DVDCheckWaitingQueue(void)
{
    u32 i;
    BOOL enabled;
    DVDCommandBlock* q;

    enabled = OSDisableInterrupts();
    for (i = 0; i < 4; i++) {
        q = (DVDCommandBlock*)&WaitingQueue[i];
        if (q->next != q) {
            OSRestoreInterrupts(enabled);
            return 1;
        }
    }

    OSRestoreInterrupts(enabled);
    return 0;
}

int __DVDDequeueWaitingQueue(DVDCommandBlock* block)
{
    BOOL enabled;
    DVDCommandBlock* prev;
    DVDCommandBlock* next;

    enabled = OSDisableInterrupts();
    prev = block->prev;
    next = block->next;
    if (prev == NULL || next == NULL) {
        OSRestoreInterrupts(enabled);
        return 0;
    }
    prev->next = next;
    next->prev = prev;
    OSRestoreInterrupts(enabled);
    return 1;
}

static u32 lbl_804F97B0[18] = { /* ErrorTable */
    0x00000000, 0x00023A00, 0x00062800, 0x00030200, 0x00031100, 0x00052000, 0x00052001, 0x00052100, 0x00052400,
    0x00052401, 0x00052402, 0x000B5A01, 0x00056300, 0x00020401, 0x00020400, 0x00040800, 0x00100007, 0x00000000,
};

#define DIDNT_MATCH 29

#pragma dont_inline on

static u8 ErrorCode2Num(u32 errorCode)
{
    u32 i;

    for (i = 0; i < 18; i++) {
        if (errorCode == lbl_804F97B0[i]) {
            return i;
        }
    }

    if (errorCode >= 0x100000 && errorCode <= 0x100008) {
        return 17;
    }

    return DIDNT_MATCH;
}

#pragma dont_inline off

void __DVDStoreErrorCode(u32 error)
{
    OSSramEx* sram;
    u8 num;
    u32 statusCode;
    u32 errorCode;

    if (error == 0x01234567) {
        num = (u8)-1;
    } else if (error == 0x01234568) {
        num = (u8)-2;
    } else {
        statusCode = (error >> 24) & 0xFF;
        errorCode = error & 0x00FFFFFF;
        num = ErrorCode2Num(errorCode);
        if (statusCode >= 6) {
            statusCode = 6;
        }
        num = statusCode * 30 + num;
    }

    sram = __OSLockSramEx();
    sram->dvdErrorCode = num;
    __OSUnlockSramEx(TRUE);
}

int DVDCompareDiskID(const DVDDiskID* id1, const DVDDiskID* id2)
{
    if (id1->gameName[0] != 0 && id2->gameName[0] != 0 && strncmp(id1->gameName, id2->gameName, 4) != 0) {
        return 0;
    }

    if (id1->company[0] == 0 || id2->company[0] == 0 || strncmp(id1->company, id2->company, 2) != 0) {
        return 0;
    }

    if (id1->diskNumber != 0xFF && id2->diskNumber != 0xFF && id1->diskNumber != id2->diskNumber) {
        return 0;
    }

    if (id1->gameVersion != 0xFF && id2->gameVersion != 0xFF && id1->gameVersion != id2->gameVersion) {
        return 0;
    }

    return 1;
}

static void (*lbl_805DDDF0)(void);

void fn_803C82FC(void)
{
    if (lbl_805DDDF0) {
        lbl_805DDDF0();
    }
}

static u8 bb2Buf[63];

static u32 lbl_805DDDF8;
static DVDBB2* bb2;
static DVDDiskID* idTmp;

static void cb(s32 result, DVDCommandBlock* block)
{
    if (result > 0) {
        switch (lbl_805DDDF8) {
        case 0:
            lbl_805DDDF8 = 1;
            DVDReadAbsAsyncForBS(block, bb2, 0x20, 0x420, cb);
            return;
        case 1:
            lbl_805DDDF8 = 2;
            DVDReadAbsAsyncForBS(block, bb2->FSTAddress, (bb2->FSTLength + 0x1F) & 0xFFFFFFE0, bb2->FSTPosition, cb);
        default:
            return;
        }
    }

    if (result == -1) {
        return;
    } else if (result == -4) {
        lbl_805DDDF8 = 0;
        DVDReset();
        DVDReadDiskID(block, idTmp, cb);
    }
}

void __fstLoad(void)
{
    OSBootInfo* bootInfoLocal;
    DVDDiskID* id;
    u8 idTmpBuf[63];
    s32 state;
    void* arenaHi;
    static DVDCommandBlock block;

    arenaHi = OSGetArenaHi();
    bootInfoLocal = (OSBootInfo*)OSPhysicalToCached(0);
    idTmp = (DVDDiskID*)OSRoundUp32B(idTmpBuf);
    bb2 = (DVDBB2*)OSRoundUp32B(bb2Buf);

    DVDReset();
    DVDReadDiskID(&block, idTmp, cb);

    while (1) {
        state = DVDGetDriveStatus();
        if (state == 0) {
            break;
        }

        switch (state) {
        case DVD_STATE_FATAL_ERROR:
            break;
        case DVD_STATE_BUSY:
            break;
        case DVD_STATE_WAITING:
            break;
        case DVD_STATE_COVER_CLOSED:
            break;
        case DVD_STATE_NO_DISK:
            break;
        case DVD_STATE_COVER_OPEN:
            break;
        case DVD_STATE_MOTOR_STOPPED:
            break;
        }
    }

    bootInfoLocal->FSTLocation = (void*)bb2->FSTAddress;
    bootInfoLocal->FSTMaxLength = bb2->FSTMaxLength;
    id = &bootInfoLocal->dvdDiskID;
    memcpy(id, idTmp, 0x20);
    OSReport("\n");
    OSReport("  Game Name ... %c%c%c%c\n", id->gameName[0], id->gameName[1], id->gameName[2], id->gameName[3]);
    OSReport("  Company ..... %c%c\n", id->company[0], id->company[1]);
    OSReport("  Disk # ...... %d\n", id->diskNumber);
    OSReport("  Game ver .... %d\n", id->gameVersion);
    OSReport("  Streaming ... %s\n", !(id->streaming) ? "OFF" : "ON");
    OSReport("\n");
    OSSetArenaHi(bb2->FSTAddress);
}

const char kar_srcfile_dvdfs_c_805dc8d8[] = "dvdfs.c";
const char lbl_804F94C8[] = "DVDConvertEntrynumToPath(possibly DVDOpen or DVDChangeDir or DVDOpenDir): "
                             "specified directory or file (%s) doesn't match standard 8.3 format. This is a "
                             "temporary restriction and will be removed soon\n";
const char lbl_804F9590[] = "Warning: DVDOpen(): file '%s' was not found under %s.\n";
