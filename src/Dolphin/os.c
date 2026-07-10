#include "dolphin/types.h"
#include <stdarg.h>

extern int vprintf(const char* fmt, va_list args);

#define OS_BASE_CACHED 0x80000000
#define OS_BASE_UNCACHED 0xC0000000
#define OSPhysicalToCached(paddr) ((void*)((u32)(paddr) + OS_BASE_CACHED))

typedef s64 OSTime;
typedef u32 OSTick;
typedef u8 __OSException;
typedef s16 __OSInterrupt;
typedef u32 OSInterruptMask;
typedef u16 OSError;

typedef struct OSContext {
    /* 0x000 */ u32 gpr[32];
    /* 0x080 */ u32 cr;
    /* 0x084 */ u32 lr;
    /* 0x088 */ u32 ctr;
    /* 0x08C */ u32 xer;
    /* 0x090 */ f64 fpr[32];
    /* 0x190 */ u32 fpscr_pad;
    /* 0x194 */ u32 fpscr;
    /* 0x198 */ u32 srr0;
    /* 0x19C */ u32 srr1;
    /* 0x1A0 */ u16 mode;
    /* 0x1A2 */ u16 state;
    /* 0x1A4 */ u32 gqr[8];
    /* 0x1C4 */ u32 psf_pad;
    /* 0x1C8 */ f64 psf[32];
} OSContext;

#define OS_CONTEXT_STATE_EXC 0x02u
#define OS_CONTEXT_STATE_FPSAVED 0x01u

#define OS_CONTEXT_R0 0
#define OS_CONTEXT_R1 4
#define OS_CONTEXT_R2 8
#define OS_CONTEXT_R3 12
#define OS_CONTEXT_R4 16
#define OS_CONTEXT_R5 20
#define OS_CONTEXT_R6 24
#define OS_CONTEXT_R7 28
#define OS_CONTEXT_R8 32
#define OS_CONTEXT_R9 36
#define OS_CONTEXT_R10 40
#define OS_CONTEXT_R11 44
#define OS_CONTEXT_R12 48
#define OS_CONTEXT_R13 52
#define OS_CONTEXT_R14 56
#define OS_CONTEXT_R15 60
#define OS_CONTEXT_R16 64
#define OS_CONTEXT_R17 68
#define OS_CONTEXT_R18 72
#define OS_CONTEXT_R19 76
#define OS_CONTEXT_R20 80
#define OS_CONTEXT_R21 84
#define OS_CONTEXT_R22 88
#define OS_CONTEXT_R23 92
#define OS_CONTEXT_R24 96
#define OS_CONTEXT_R25 100
#define OS_CONTEXT_R26 104
#define OS_CONTEXT_R27 108
#define OS_CONTEXT_R28 112
#define OS_CONTEXT_R29 116
#define OS_CONTEXT_R30 120
#define OS_CONTEXT_R31 124
#define OS_CONTEXT_CR 128
#define OS_CONTEXT_LR 132
#define OS_CONTEXT_CTR 136
#define OS_CONTEXT_XER 140
#define OS_CONTEXT_FPSCR 400
#define OS_CONTEXT_SRR0 408
#define OS_CONTEXT_SRR1 412
#define OS_CONTEXT_MODE 416
#define OS_CONTEXT_STATE 418
#define OS_CONTEXT_GQR0 420
#define OS_CONTEXT_GQR1 424
#define OS_CONTEXT_GQR2 428
#define OS_CONTEXT_GQR3 432
#define OS_CONTEXT_GQR4 436
#define OS_CONTEXT_GQR5 440
#define OS_CONTEXT_GQR6 444
#define OS_CONTEXT_GQR7 448
#define OS_CONTEXT_PSF0 456
#define OS_CONTEXT_PSF1 464
#define OS_CONTEXT_PSF2 472
#define OS_CONTEXT_PSF3 480
#define OS_CONTEXT_PSF4 488
#define OS_CONTEXT_PSF5 496
#define OS_CONTEXT_PSF6 504
#define OS_CONTEXT_PSF7 512
#define OS_CONTEXT_PSF8 520
#define OS_CONTEXT_PSF9 528
#define OS_CONTEXT_PSF10 536
#define OS_CONTEXT_PSF11 544
#define OS_CONTEXT_PSF12 552
#define OS_CONTEXT_PSF13 560
#define OS_CONTEXT_PSF14 568
#define OS_CONTEXT_PSF15 576
#define OS_CONTEXT_PSF16 584
#define OS_CONTEXT_PSF17 592
#define OS_CONTEXT_PSF18 600
#define OS_CONTEXT_PSF19 608
#define OS_CONTEXT_PSF20 616
#define OS_CONTEXT_PSF21 624
#define OS_CONTEXT_PSF22 632
#define OS_CONTEXT_PSF23 640
#define OS_CONTEXT_PSF24 648
#define OS_CONTEXT_PSF25 656
#define OS_CONTEXT_PSF26 664
#define OS_CONTEXT_PSF27 672
#define OS_CONTEXT_PSF28 680
#define OS_CONTEXT_PSF29 688
#define OS_CONTEXT_PSF30 696
#define OS_CONTEXT_PSF31 704

typedef void (*__OSExceptionHandler)(__OSException exception, OSContext* context);
typedef void (*__OSInterruptHandler)(__OSInterrupt interrupt, OSContext* context);
typedef void (*OSErrorHandler)(OSError error, OSContext* context, ...);

typedef struct OSThreadQueue {
    struct OSThread* head;
    struct OSThread* tail;
} OSThreadQueue;

typedef struct OSThreadLink {
    struct OSThread* next;
    struct OSThread* prev;
} OSThreadLink;

typedef struct OSMutexQueue {
    struct OSMutex* head;
    struct OSMutex* tail;
} OSMutexQueue;

typedef struct OSMutexLink {
    struct OSMutex* next;
    struct OSMutex* prev;
} OSMutexLink;

typedef s32 OSPriority;

typedef struct OSThread {
    /* 0x000 */ OSContext context;
    /* 0x2C8 */ u16 state;
    /* 0x2CA */ u16 attr;
    /* 0x2CC */ s32 suspend;
    /* 0x2D0 */ OSPriority priority;
    /* 0x2D4 */ OSPriority base;
    /* 0x2D8 */ void* val;
    /* 0x2DC */ OSThreadQueue* queue;
    /* 0x2E0 */ OSThreadLink link;
    /* 0x2E8 */ OSThreadQueue queueJoin;
    /* 0x2F0 */ struct OSMutex* mutex;
    /* 0x2F4 */ OSMutexQueue queueMutex;
    /* 0x2FC */ OSThreadLink linkActive;
    /* 0x304 */ u8* stackBase;
    /* 0x308 */ u32* stackEnd;
    /* 0x30C */ s32 error;
    /* 0x310 */ void* specific[2];
} OSThread;

typedef struct OSMutex {
    /* 0x00 */ OSThreadQueue queue;
    /* 0x08 */ OSThread* thread;
    /* 0x0C */ s32 count;
    /* 0x10 */ OSMutexLink link;
} OSMutex;

typedef struct OSCond {
    OSThreadQueue queue;
} OSCond;

typedef struct OSAlarm OSAlarm;
typedef void (*OSAlarmHandler)(OSAlarm* alarm, OSContext* context);
struct OSAlarm {
    OSAlarmHandler handler;
    u32 tag;
    OSTime fire;
    OSAlarm* prev;
    OSAlarm* next;
    OSTime period;
    OSTime start;
};

typedef struct {
    OSThreadQueue queueSend;
    OSThreadQueue queueReceive;
    void* msgArray;
    s32 msgCount;
    s32 firstIndex;
    s32 usedCount;
} OSMessageQueue;

typedef struct OSResetFunctionInfo OSResetFunctionInfo;
typedef struct OSResetFunctionQueue {
    OSResetFunctionInfo* head;
    OSResetFunctionInfo* tail;
} OSResetFunctionQueue;

typedef BOOL (*OSResetFunction)(BOOL);

struct OSResetFunctionInfo {
    OSResetFunction func;
    u32 priority;
    OSResetFunctionInfo* next;
    OSResetFunctionInfo* prev;
};

typedef void (*OSResetCallback)(void);

typedef struct OSSram {
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

typedef struct OSSramEx {
    u8 flashID[2][12];
    u32 wirelessKeyboardID;
    u16 wirelessPadID[4];
    u8 dvdErrorCode;
    u8 _padding0;
    u8 flashIDCheckSum[2];
    u16 gbs;
    u8 _padding1[2];
} OSSramEx;

#define SRAM_SIZE (sizeof(OSSram) + sizeof(OSSramEx))

typedef struct SramControl {
    u8 sram[SRAM_SIZE];
    u32 offset;
    BOOL enabled;
    BOOL locked;
    int sync;
    void (*callback)();
} SramControl;

typedef struct OSFontHeader {
    u16 fontType;
    u16 firstChar;
    u16 lastChar;
    u16 invalChar;
    u16 ascent;
    u16 descent;
    u16 width;
    u16 leading;
    u16 cellWidth;
    u16 cellHeight;
    u32 sheetSize;
    u16 sheetFormat;
    u16 sheetColumn;
    u16 sheetRow;
    u16 sheetWidth;
    u16 sheetHeight;
    u16 widthTable;
    u32 sheetImage;
    u32 sheetFullSize;
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
} OSFontHeader;

typedef struct {
    BOOL valid;
    u32 restartCode;
    u32 bootDol;
    void* regionStart;
    void* regionEnd;
    int argsUseDefault;
    void* argsAddr;
} OSExecParams;

typedef struct DVDDiskID {
    char gameName[4];
    char company[2];
    u8 diskNumber;
    u8 gameVersion;
    u8 streaming;
    u8 streamingBufSize;
    u8 padding[22];
} DVDDiskID;

typedef struct OSBootInfo {
    DVDDiskID diskID;
    u32 magic;
    u32 version;
    u32 memorySize;
    u32 consoleType;
    void* arenaLo;
    void* arenaHi;
    void* FSTLocation;
    u32 FSTMaxLength;
} OSBootInfo;

typedef struct DVDCommandBlock DVDCommandBlock;
typedef void (*DVDCBCallback)(s32 result, DVDCommandBlock* block);
struct DVDCommandBlock {
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

typedef struct DVDDriveInfo {
    /* 0x00 */ u16 revisionLevel;
    /* 0x02 */ u16 deviceCode;
    /* 0x04 */ u32 releaseDate;
    /* 0x08 */ u8 padding[24];
} DVDDriveInfo;

typedef struct Cell Cell;
typedef struct HeapDesc HeapDesc;
struct Cell {
    Cell* prev;
    Cell* next;
    s32 size;
};

struct HeapDesc {
    s32 size;
    Cell* free;
    Cell* allocated;
};

#define OS_CONSOLE_RETAIL 0x00000000
#define OS_CONSOLE_DEVELOPMENT 0x10000000
#define OS_CONSOLE_TDEV 0x20000000
#define OS_CONSOLE_EMULATOR 0x10000000
#define OS_CONSOLE_PC_EMULATOR 0x10000001
#define OS_CONSOLE_ARTHUR 0x10000002
#define OS_CONSOLE_MINNOW 0x10000003

#define __OS_EXCEPTION_SYSTEM_RESET 0
#define __OS_EXCEPTION_MACHINE_CHECK 1
#define __OS_EXCEPTION_DSI 2
#define __OS_EXCEPTION_ISI 3
#define __OS_EXCEPTION_EXTERNAL_INTERRUPT 4
#define __OS_EXCEPTION_ALIGNMENT 5
#define __OS_EXCEPTION_PROGRAM 6
#define __OS_EXCEPTION_FLOATING_POINT 7
#define __OS_EXCEPTION_DECREMENTER 8
#define __OS_EXCEPTION_SYSTEM_CALL 9
#define __OS_EXCEPTION_TRACE 10
#define __OS_EXCEPTION_PERFORMACE_MONITOR 11
#define __OS_EXCEPTION_BREAKPOINT 12
#define __OS_EXCEPTION_SYSTEM_INTERRUPT 13
#define __OS_EXCEPTION_THERMAL_INTERRUPT 14
#define __OS_EXCEPTION_MEMORY_PROTECTION 15
#define __OS_EXCEPTION_FLOATING_POINT_EXCEPTION 16
#define __OS_EXCEPTION_MAX (__OS_EXCEPTION_THERMAL_INTERRUPT + 1)

#define __OS_INTERRUPT_MEM_0 0
#define __OS_INTERRUPT_MEM_1 1
#define __OS_INTERRUPT_MEM_2 2
#define __OS_INTERRUPT_MEM_3 3
#define __OS_INTERRUPT_MEM_ADDRESS 4
#define __OS_INTERRUPT_DSP_AI 5
#define __OS_INTERRUPT_DSP_ARAM 6
#define __OS_INTERRUPT_DSP_DSP 7
#define __OS_INTERRUPT_AI_AI 8
#define __OS_INTERRUPT_EXI_0_EXI 9
#define __OS_INTERRUPT_EXI_0_TC 10
#define __OS_INTERRUPT_EXI_0_EXT 11
#define __OS_INTERRUPT_EXI_1_EXI 12
#define __OS_INTERRUPT_EXI_1_TC 13
#define __OS_INTERRUPT_EXI_1_EXT 14
#define __OS_INTERRUPT_EXI_2_EXI 15
#define __OS_INTERRUPT_EXI_2_TC 16
#define __OS_INTERRUPT_PI_CP 17
#define __OS_INTERRUPT_PI_PE_TOKEN 18
#define __OS_INTERRUPT_PI_PE_FINISH 19
#define __OS_INTERRUPT_PI_SI 20
#define __OS_INTERRUPT_PI_DI 21
#define __OS_INTERRUPT_PI_RSW 22
#define __OS_INTERRUPT_PI_ERROR 23
#define __OS_INTERRUPT_PI_VI 24
#define __OS_INTERRUPT_PI_DEBUG 25
#define __OS_INTERRUPT_PI_HSP 26
#define __OS_INTERRUPT_MAX 32

#define OS_INTERRUPTMASK(interrupt) (0x80000000u >> (interrupt))
#define OS_INTERRUPTMASK_MEM_0 OS_INTERRUPTMASK(__OS_INTERRUPT_MEM_0)
#define OS_INTERRUPTMASK_MEM_1 OS_INTERRUPTMASK(__OS_INTERRUPT_MEM_1)
#define OS_INTERRUPTMASK_MEM_2 OS_INTERRUPTMASK(__OS_INTERRUPT_MEM_2)
#define OS_INTERRUPTMASK_MEM_3 OS_INTERRUPTMASK(__OS_INTERRUPT_MEM_3)
#define OS_INTERRUPTMASK_MEM_ADDRESS OS_INTERRUPTMASK(__OS_INTERRUPT_MEM_ADDRESS)
#define OS_INTERRUPTMASK_MEM_RESET \
    (OS_INTERRUPTMASK_MEM_0 | OS_INTERRUPTMASK_MEM_1 | OS_INTERRUPTMASK_MEM_2 | OS_INTERRUPTMASK_MEM_3)
#define OS_INTERRUPTMASK_MEM \
    (OS_INTERRUPTMASK_MEM_0 | OS_INTERRUPTMASK_MEM_1 | OS_INTERRUPTMASK_MEM_2 | OS_INTERRUPTMASK_MEM_3 | OS_INTERRUPTMASK_MEM_ADDRESS)
#define OS_INTERRUPTMASK_DSP_AI OS_INTERRUPTMASK(__OS_INTERRUPT_DSP_AI)
#define OS_INTERRUPTMASK_DSP_ARAM OS_INTERRUPTMASK(__OS_INTERRUPT_DSP_ARAM)
#define OS_INTERRUPTMASK_DSP_DSP OS_INTERRUPTMASK(__OS_INTERRUPT_DSP_DSP)
#define OS_INTERRUPTMASK_DSP (OS_INTERRUPTMASK_DSP_AI | OS_INTERRUPTMASK_DSP_ARAM | OS_INTERRUPTMASK_DSP_DSP)
#define OS_INTERRUPTMASK_AI_AI OS_INTERRUPTMASK(__OS_INTERRUPT_AI_AI)
#define OS_INTERRUPTMASK_AI (OS_INTERRUPTMASK_AI_AI)
#define OS_INTERRUPTMASK_EXI_0_EXI OS_INTERRUPTMASK(__OS_INTERRUPT_EXI_0_EXI)
#define OS_INTERRUPTMASK_EXI_0_TC OS_INTERRUPTMASK(__OS_INTERRUPT_EXI_0_TC)
#define OS_INTERRUPTMASK_EXI_0_EXT OS_INTERRUPTMASK(__OS_INTERRUPT_EXI_0_EXT)
#define OS_INTERRUPTMASK_EXI_0 (OS_INTERRUPTMASK_EXI_0_EXI | OS_INTERRUPTMASK_EXI_0_TC | OS_INTERRUPTMASK_EXI_0_EXT)
#define OS_INTERRUPTMASK_EXI_1_EXI OS_INTERRUPTMASK(__OS_INTERRUPT_EXI_1_EXI)
#define OS_INTERRUPTMASK_EXI_1_TC OS_INTERRUPTMASK(__OS_INTERRUPT_EXI_1_TC)
#define OS_INTERRUPTMASK_EXI_1_EXT OS_INTERRUPTMASK(__OS_INTERRUPT_EXI_1_EXT)
#define OS_INTERRUPTMASK_EXI_1 (OS_INTERRUPTMASK_EXI_1_EXI | OS_INTERRUPTMASK_EXI_1_TC | OS_INTERRUPTMASK_EXI_1_EXT)
#define OS_INTERRUPTMASK_EXI_2_EXI OS_INTERRUPTMASK(__OS_INTERRUPT_EXI_2_EXI)
#define OS_INTERRUPTMASK_EXI_2_TC OS_INTERRUPTMASK(__OS_INTERRUPT_EXI_2_TC)
#define OS_INTERRUPTMASK_EXI_2 (OS_INTERRUPTMASK_EXI_2_EXI | OS_INTERRUPTMASK_EXI_2_TC)
#define OS_INTERRUPTMASK_EXI \
    (OS_INTERRUPTMASK_EXI_0_EXI | OS_INTERRUPTMASK_EXI_0_TC | OS_INTERRUPTMASK_EXI_0_EXT | \
     OS_INTERRUPTMASK_EXI_1_EXI | OS_INTERRUPTMASK_EXI_1_TC | OS_INTERRUPTMASK_EXI_1_EXT | \
     OS_INTERRUPTMASK_EXI_2_EXI | OS_INTERRUPTMASK_EXI_2_TC)
#define OS_INTERRUPTMASK_PI_PE_TOKEN OS_INTERRUPTMASK(__OS_INTERRUPT_PI_PE_TOKEN)
#define OS_INTERRUPTMASK_PI_PE_FINISH OS_INTERRUPTMASK(__OS_INTERRUPT_PI_PE_FINISH)
#define OS_INTERRUPTMASK_PI_PE (OS_INTERRUPTMASK_PI_PE_TOKEN | OS_INTERRUPTMASK_PI_PE_FINISH)
#define OS_INTERRUPTMASK_PI_CP OS_INTERRUPTMASK(__OS_INTERRUPT_PI_CP)
#define OS_INTERRUPTMASK_PI_SI OS_INTERRUPTMASK(__OS_INTERRUPT_PI_SI)
#define OS_INTERRUPTMASK_PI_DI OS_INTERRUPTMASK(__OS_INTERRUPT_PI_DI)
#define OS_INTERRUPTMASK_PI_RSW OS_INTERRUPTMASK(__OS_INTERRUPT_PI_RSW)
#define OS_INTERRUPTMASK_PI_ERROR OS_INTERRUPTMASK(__OS_INTERRUPT_PI_ERROR)
#define OS_INTERRUPTMASK_PI_VI OS_INTERRUPTMASK(__OS_INTERRUPT_PI_VI)
#define OS_INTERRUPTMASK_PI_DEBUG OS_INTERRUPTMASK(__OS_INTERRUPT_PI_DEBUG)
#define OS_INTERRUPTMASK_PI_HSP OS_INTERRUPTMASK(__OS_INTERRUPT_PI_HSP)
#define OS_INTERRUPTMASK_PI \
    (OS_INTERRUPTMASK_PI_CP | OS_INTERRUPTMASK_PI_SI | OS_INTERRUPTMASK_PI_DI | OS_INTERRUPTMASK_PI_RSW | \
     OS_INTERRUPTMASK_PI_ERROR | OS_INTERRUPTMASK_PI_VI | OS_INTERRUPTMASK_PI_PE_TOKEN | \
     OS_INTERRUPTMASK_PI_PE_FINISH | OS_INTERRUPTMASK_PI_DEBUG | OS_INTERRUPTMASK_PI_HSP)

#define OS_DBINTERFACE_ADDR 0x00000040
#define DB_EXCEPTIONRET_OFFSET 0xC
#define DB_EXCEPTIONDEST_OFFSET 0x8
#define OS_CURRENTCONTEXT_PADDR 0x00C0
#define OS_EXCEPTIONTABLE_ADDR 0x3000
#define OS_DBJUMPPOINT_ADDR 0x60

#define OS_RESET_RESTART 0
#define OS_RESET_HOTRESET 1
#define OS_RESET_SHUTDOWN 2

#define OS_ERROR_MACHINE_CHECK 1
#define __OS_ERROR_MAX 17

#define OS_FONT_ENCODE_ANSI 0u
#define OS_FONT_ENCODE_SJIS 1u
#define OS_FONT_ENCODE_MAX 5u
#define OS_FONT_ROM_SIZE_ANSI 0x03000
#define OS_FONT_ROM_SIZE_SJIS 0x4D000

extern void* memset(void* dst, int val, u32 n);
extern void* memcpy(void* dst, const void* src, u32 n);

extern u32 PPCMfhid2(void);
extern void PPCMthid2(u32);
extern u32 PPCMfhid0(void);
extern void PPCMthid0(u32);
extern u32 PPCMfl2cr(void);
extern void PPCMtl2cr(u32);
extern u32 PPCMfmsr(void);
extern void PPCMtmsr(u32);
extern void PPCMtdec(u32);
extern void PPCHalt(void);
extern void PPCMtmmcr0(u32);
extern void PPCMtmmcr1(u32);
extern void PPCMtpmc1(u32);
extern void PPCMtpmc2(u32);
extern void PPCMtpmc3(u32);
extern void PPCMtpmc4(u32);
extern u32 PPCMffpscr(void);
extern void PPCMtfpscr(u32);
extern void PPCDisableSpeculation(void);
extern void PPCSetFpNonIEEEMode(void);

extern void DBPrintf(char*, ...);
extern u32 __DBIsExceptionMarked(u8 exception);

extern void __sync(void);

extern void EXIInit(void);
extern void SIInit(void);
extern void DVDInit(void);
extern void DVDSetAutoInvalidation(BOOL);
extern void DVDResume(void);
typedef void (*EXICallback)(s32 chan, OSContext* context);
extern int EXILock(s32 chan, u32 dev, EXICallback unlockedCallback);
extern int EXIUnlock(s32 chan);
extern int EXISelect(s32 chan, u32 dev, u32 freq);
extern int EXIDeselect(s32 chan);
extern int EXIImm(s32 chan, void* buf, s32 len, u32 type, EXICallback callback);
extern int EXIImmEx(s32 chan, void* buf, s32 len, u32 mode);
extern int EXIDma(s32 chan, void* buf, s32 len, u32 type, EXICallback callback);
extern int EXISync(s32 chan);
extern BOOL __PADDisableRecalibration(BOOL disable);
extern void DVDInquiryAsync(DVDCommandBlock* block, DVDDriveInfo* info, DVDCBCallback callback);
extern void EnableMetroTRKInterrupts(void);

extern void OSInitThreadQueue(OSThreadQueue* queue);
extern void OSSleepThread(OSThreadQueue* queue);
extern void OSWakeupThread(OSThreadQueue* queue);
extern OSThread* OSGetCurrentThread(void);
extern s32 OSEnableScheduler(void);
extern s32 OSDisableScheduler(void);
extern void OSCancelThread(OSThread* thread);
extern void __OSThreadInit(void);
extern s32 __OSGetEffectivePriority(OSThread* thread);
extern void kar_osthread__near_803d9e28(OSThread* thread, s32 priority); /* __OSPromoteThread */
extern void __OSReschedule(void);
extern OSTime __OSGetSystemTime(void);
extern OSTime kar_osthread__near_803db59c(OSTime time); /* __OSTimeToSystemTime */
#define __OSActiveThreadQueue (*(OSThreadQueue*)0x800000DC)
volatile OSTime __OSLastInterruptTime;
volatile __OSInterrupt __OSLastInterrupt;
volatile u32 __OSLastInterruptSrr0;
#define DSP_ARAM_DMA_MM_HI 16
#define DSP_ARAM_DMA_MM_LO 17
#define DSP_DMA_START_HI 24
#define DSP_DMA_START_LO 25
extern OSTick OSGetTick(void);

void* OSGetArenaHi(void);
void* OSGetArenaLo(void);
void OSSetArenaHi(void* newHi);
void OSSetArenaLo(void* newLo);
void OSReport(const char* msg, ...);
void OSPanic(const char* file, int line, const char* msg, ...);
BOOL OSDisableInterrupts(void);
BOOL OSEnableInterrupts(void);
BOOL OSRestoreInterrupts(BOOL level);
void __OSGetExecParams(OSExecParams* params);
void __OSInitSystemCall(void);
void OSInitAlarm(void);
void __OSModuleInit(void);
void __OSInterruptInit(void);
__OSInterruptHandler __OSSetInterruptHandler(__OSInterrupt interrupt, __OSInterruptHandler handler);
__OSInterruptHandler __OSGetInterruptHandler(__OSInterrupt interrupt);
void __OSResetSWInterruptHandler(s16 exception, OSContext* context);
void __OSContextInit(void);
void __OSCacheInit(void);
void __OSInitSram(void);
void __OSInitAudioSystem(void);
void __OSStopAudioSystem(void);
void __OSInitMemoryProtection(void);
u32 OSGetResetCode(void);
u32 OSGetConsoleType(void);
void DCInvalidateRange(register void* addr, register u32 nBytes);
void DCFlushRange(register void* addr, register u32 nBytes);
void DCFlushRangeNoSync(register void* addr, register u32 nBytes);
void ICInvalidateRange(register void* addr, register u32 nBytes);
void ICFlashInvalidate(void);
void ICEnable(void);
void DCEnable(void);
void L2GlobalInvalidate(void);
void LCDisable(void);
u32 OSSaveContext(register OSContext* context);
void OSLoadContext(register OSContext* context);
void OSClearContext(register OSContext* context);
OSContext* OSGetCurrentContext(void);
void OSSetCurrentContext(register OSContext* context);
void OSSaveFPUContext(register OSContext* fpucontext);
void OSDumpContext(OSContext* context);
OSErrorHandler OSSetErrorHandler(OSError error, OSErrorHandler handler);
void __OSUnhandledException(__OSException exception, OSContext* context, u32 dsisr, u32 dar);
void OSRegisterVersion(const char* id);
void OSRegisterResetFunction(OSResetFunctionInfo* info);
u16 OSGetFontEncode(void);
u32 OSLoadFont(OSFontHeader* fontData, void* tmp);
__OSExceptionHandler __OSSetExceptionHandler(__OSException exception, __OSExceptionHandler handler);
__OSExceptionHandler __OSGetExceptionHandler(__OSException exception);
int __OSReadROM(void* buffer, s32 length, s32 offset);
OSSram* __OSLockSram(void);
int __OSUnlockSram(int commit);

static void ClearArena(void);
static void InquiryCallback(s32, DVDCommandBlock* block);
static void OSExceptionInit(void);
static asm void __OSDBIntegrator(void);
static asm void OSExceptionVector(void);

const char* __OSVersion = "<< Dolphin SDK - OS\trelease build: Mar 17 2003 04:20:41 (0x2301) >>";
static DVDDriveInfo DriveInfo;
static DVDCommandBlock DriveBlock;
OSExecParams __OSRebootParams;
void* __OSSavedRegionStart;
void* __OSSavedRegionEnd;

extern u32 __DVDLongFileNameFlag;
extern u32 __PADSpec;
#define __OSDeviceCode (*(vu16*)0x800030E6)

extern u8 __ArenaLo[];
extern char _stack_addr[];
extern u8 __ArenaHi[];

static OSBootInfo* BootInfo;
static u32* BI2DebugFlag;
static u32 BI2DebugFlagHolder;

OSTime __OSStartTime;
BOOL __OSInIPL;
__OSExceptionHandler* OSExceptionTable;
BOOL AreWeInitialized;
f32 ZeroPS[2];
f64 ZeroF;
BOOL __OSIsGcam;

asm void __OSFPRInit(void) {
    nofralloc

    mfmsr r3
    ori r3, r3, 0x2000
    mtmsr r3

    mfspr r3, 920
    rlwinm. r3, r3, 3, 0x1f, 0x1f
    beq skip_ps_init

    lis r3, ZeroPS@ha
    addi r3, r3, ZeroPS@l
    psq_l f0, 0(r3), 0, 0
    ps_mr f1, f0
    ps_mr f2, f0
    ps_mr f3, f0
    ps_mr f4, f0
    ps_mr f5, f0
    ps_mr f6, f0
    ps_mr f7, f0
    ps_mr f8, f0
    ps_mr f9, f0
    ps_mr f10, f0
    ps_mr f11, f0
    ps_mr f12, f0
    ps_mr f13, f0
    ps_mr f14, f0
    ps_mr f15, f0
    ps_mr f16, f0
    ps_mr f17, f0
    ps_mr f18, f0
    ps_mr f19, f0
    ps_mr f20, f0
    ps_mr f21, f0
    ps_mr f22, f0
    ps_mr f23, f0
    ps_mr f24, f0
    ps_mr f25, f0
    ps_mr f26, f0
    ps_mr f27, f0
    ps_mr f28, f0
    ps_mr f29, f0
    ps_mr f30, f0
    ps_mr f31, f0

skip_ps_init:
    lfd f0, ZeroF(r0)
    fmr f1, f0
    fmr f2, f0
    fmr f3, f0
    fmr f4, f0
    fmr f5, f0
    fmr f6, f0
    fmr f7, f0
    fmr f8, f0
    fmr f9, f0
    fmr f10, f0
    fmr f11, f0
    fmr f12, f0
    fmr f13, f0
    fmr f14, f0
    fmr f15, f0
    fmr f16, f0
    fmr f17, f0
    fmr f18, f0
    fmr f19, f0
    fmr f20, f0
    fmr f21, f0
    fmr f22, f0
    fmr f23, f0
    fmr f24, f0
    fmr f25, f0
    fmr f26, f0
    fmr f27, f0
    fmr f28, f0
    fmr f29, f0
    fmr f30, f0
    fmr f31, f0

    mtfsf 0xff, f0
    blr
}

u32 OSGetConsoleType(void) {
    if (!BootInfo || BootInfo->consoleType == 0) {
        return OS_CONSOLE_ARTHUR;
    }
    return BootInfo->consoleType;
}

static void DisableWriteGatherPipe(void) {
    u32 hid2;

    hid2 = PPCMfhid2();
    hid2 &= ~0x40000000;
    PPCMthid2(hid2);
}

static void ClearArena(void) {
    if (OSGetResetCode() != 0x80000000) {
        memset(OSGetArenaLo(), 0, (u32)OSGetArenaHi() - (u32)OSGetArenaLo());
        return;
    }

    __OSSavedRegionStart = *(void**)0x812FDFF0;
    __OSSavedRegionEnd = *(void**)0x812FDFEC;

    if (__OSSavedRegionStart == NULL) {
        memset(OSGetArenaLo(), 0, (u32)OSGetArenaHi() - (u32)OSGetArenaLo());
        return;
    }

    if ((u32)OSGetArenaLo() < (u32)__OSSavedRegionStart) {
        if ((u32)OSGetArenaHi() <= (u32)__OSSavedRegionStart) {
            memset(OSGetArenaLo(), 0, (u32)OSGetArenaHi() - (u32)OSGetArenaLo());
            return;
        }

        memset(OSGetArenaLo(), 0, (u32)__OSSavedRegionStart - (u32)OSGetArenaLo());

        if ((u32)OSGetArenaHi() > (u32)__OSSavedRegionEnd) {
            memset(__OSSavedRegionEnd, 0, (u32)OSGetArenaHi() - (u32)__OSSavedRegionEnd);
        }
    }
}

static void InquiryCallback(s32 result, DVDCommandBlock* block) {
    switch (block->state) {
    case 0:
        __OSDeviceCode = (u16)(0x8000 | DriveInfo.deviceCode);
        break;
    default:
        __OSDeviceCode = 1;
        break;
    }
}

void OSInit(void) {
    u32 consoleType;
    void* bi2StartAddr;

    if (AreWeInitialized == FALSE) {
        AreWeInitialized = TRUE;

        __OSStartTime = __OSGetSystemTime();
        OSDisableInterrupts();

        PPCMtmmcr0(0);
        PPCMtmmcr1(0);
        PPCMtpmc1(0);
        PPCMtpmc2(0);
        PPCMtpmc3(0);
        PPCMtpmc4(0);
        PPCDisableSpeculation();
        PPCSetFpNonIEEEMode();

        BootInfo = (OSBootInfo*)OSPhysicalToCached(0);
        BI2DebugFlag = 0;
        __DVDLongFileNameFlag = 0;

        bi2StartAddr = (void*)(*(u32*)OSPhysicalToCached(0xF4));
        if (bi2StartAddr) {
            BI2DebugFlag = (void*)((char*)bi2StartAddr + 0xC);
            __PADSpec = ((u32*)bi2StartAddr)[9];
            *(u8*)OSPhysicalToCached(0x30E8) = *BI2DebugFlag;
            *(u8*)OSPhysicalToCached(0x30E9) = __PADSpec;
        } else if (BootInfo->arenaHi) {
            BI2DebugFlagHolder = *(u8*)OSPhysicalToCached(0x30E8);
            BI2DebugFlag = &BI2DebugFlagHolder;
            __PADSpec = *(u8*)OSPhysicalToCached(0x30E9);
        }

        __DVDLongFileNameFlag = 1;

        OSSetArenaLo((!BootInfo->arenaLo) ? &__ArenaLo : BootInfo->arenaLo);
        if ((!BootInfo->arenaLo) && (BI2DebugFlag) && (*(u32*)BI2DebugFlag < 2)) {
            OSSetArenaLo((void*)(((u32)(char*)&_stack_addr + 0x1F) & 0xFFFFFFE0));
        }
        OSSetArenaHi((!BootInfo->arenaHi) ? &__ArenaHi : BootInfo->arenaHi);

        OSExceptionInit();
        __OSInitSystemCall();
        OSInitAlarm();
        __OSModuleInit();
        __OSInterruptInit();
        __OSSetInterruptHandler(0x16, __OSResetSWInterruptHandler);
        __OSContextInit();
        __OSCacheInit();
        EXIInit();
        SIInit();
        __OSInitSram();
        __OSThreadInit();
        __OSInitAudioSystem();

        DisableWriteGatherPipe();

        if (!__OSInIPL) {
            __OSInitMemoryProtection();
        }

        OSReport("\nDolphin OS\n");
        OSReport("Kernel built : %s %s\n", "Mar 17 2003", "04:20:41");
        OSReport("Console Type : ");

        consoleType = OSGetConsoleType();
        switch (consoleType & 0xF0000000) {
        case OS_CONSOLE_RETAIL:
            OSReport("Retail %d\n", consoleType);
            break;
        case OS_CONSOLE_DEVELOPMENT:
        case OS_CONSOLE_TDEV:
            switch (consoleType & 0x0FFFFFFF) {
            case OS_CONSOLE_EMULATOR:
                OSReport("Mac Emulator\n");
                break;
            case OS_CONSOLE_PC_EMULATOR:
                OSReport("PC Emulator\n");
                break;
            case OS_CONSOLE_ARTHUR:
                OSReport("EPPC Arthur\n");
                break;
            case OS_CONSOLE_MINNOW:
                OSReport("EPPC Minnow\n");
                break;
            default:
                OSReport("Development HW%d (%08x)\n", (consoleType & 0xFFFFFFF) - 3, consoleType);
                break;
            }
            break;
        default:
            OSReport("%08x\n", consoleType);
            break;
        }

        OSReport("Memory %d MB\n", (u32)BootInfo->memorySize >> 0x14U);
        OSReport("Arena : 0x%x - 0x%x\n", OSGetArenaLo(), OSGetArenaHi());
        OSRegisterVersion(__OSVersion);

        if (BI2DebugFlag && ((*BI2DebugFlag) >= 2)) {
            EnableMetroTRKInterrupts();
        }

        ClearArena();
        OSEnableInterrupts();

        if (!__OSInIPL) {
            DVDInit();

            if (__OSIsGcam) {
                __OSDeviceCode = 0x9000;
                return;
            }

            DCInvalidateRange(&DriveInfo, sizeof(DriveInfo));
            DVDInquiryAsync(&DriveBlock, &DriveInfo, InquiryCallback);
        }
    }
}

#define NOP 0x60000000

void OSDefaultExceptionHandler(register __OSException exception, register OSContext* context);
void __OSEVStart(void);
void __OSEVEnd(void);
void __OSEVSetNumber(void);
void __DBVECTOR(void);
void __OSDBINTSTART(void);
void __OSDBINTEND(void);
void __OSDBJUMPEND(void);

static u32 __OSExceptionLocations[] = {
    0x00000100, 0x00000200, 0x00000300, 0x00000400, 0x00000500, 0x00000600, 0x00000700, 0x00000800,
    0x00000900, 0x00000C00, 0x00000D00, 0x00000F00, 0x00001300, 0x00001400, 0x00001700,
};

static void OSExceptionInit(void) {
    __OSException exception;
    void* destAddr;

    u32* opCodeAddr;
    u32 oldOpCode;

    u8* handlerStart;
    u32 handlerSize;

    opCodeAddr = (u32*)__OSEVSetNumber;
    oldOpCode = *opCodeAddr;
    handlerStart = (u8*)__OSEVStart;
    handlerSize = (u32)((u8*)__OSEVEnd - (u8*)__OSEVStart);

    destAddr = (void*)OSPhysicalToCached(OS_DBJUMPPOINT_ADDR);
    if (*(u32*)destAddr == 0) {
        DBPrintf("Installing OSDBIntegrator\n");
        memcpy(destAddr, (void*)__OSDBINTSTART, (u32)__OSDBINTEND - (u32)__OSDBINTSTART);
        DCFlushRangeNoSync(destAddr, (u32)__OSDBINTEND - (u32)__OSDBINTSTART);
        __sync();
        ICInvalidateRange(destAddr, (u32)__OSDBINTEND - (u32)__OSDBINTSTART);
    }

    for (exception = 0; exception < __OS_EXCEPTION_MAX; exception++) {
        if (BI2DebugFlag && (*BI2DebugFlag >= 2) && __DBIsExceptionMarked(exception)) {
            DBPrintf(">>> OSINIT: exception %d commandeered by TRK\n", exception);
            continue;
        }

        *opCodeAddr = oldOpCode | exception;

        if (__DBIsExceptionMarked(exception)) {
            DBPrintf(">>> OSINIT: exception %d vectored to debugger\n", exception);
            memcpy((void*)__DBVECTOR, (void*)__OSDBINTEND, (u32)__OSDBJUMPEND - (u32)__OSDBINTEND);
        } else {
            u32* ops = (u32*)__DBVECTOR;
            int cb;

            for (cb = 0; cb < (u32)__OSDBJUMPEND - (u32)__OSDBINTEND; cb += sizeof(u32)) {
                *ops++ = NOP;
            }
        }

        destAddr = (void*)OSPhysicalToCached(__OSExceptionLocations[(u32)exception]);
        memcpy(destAddr, handlerStart, handlerSize);
        DCFlushRangeNoSync(destAddr, handlerSize);
        __sync();
        ICInvalidateRange(destAddr, handlerSize);
    }
    OSExceptionTable = (void*)OSPhysicalToCached(OS_EXCEPTIONTABLE_ADDR);

    for (exception = 0; exception < __OS_EXCEPTION_MAX; exception++) {
        __OSSetExceptionHandler(exception, OSDefaultExceptionHandler);
    }

    *opCodeAddr = oldOpCode;

    DBPrintf("Exceptions initialized...\n");
}

static asm void __OSDBIntegrator(void) {
    nofralloc
entry __OSDBINTSTART
    li r5, OS_DBINTERFACE_ADDR
    mflr r3
    stw r3, DB_EXCEPTIONRET_OFFSET(r5)
    lwz r3, DB_EXCEPTIONDEST_OFFSET(r5)
    oris r3, r3, 0x8000
    mtlr r3
    li r3, 0x30
    mtmsr r3
    blr
entry __OSDBINTEND
}

asm void fn_803D2C78(void) {
    nofralloc
    bla OS_DBJUMPPOINT_ADDR
entry __OSDBJUMPEND
}

#pragma dont_inline on
__OSExceptionHandler __OSSetExceptionHandler(__OSException exception, __OSExceptionHandler handler) {
    __OSExceptionHandler oldHandler;

    oldHandler = OSExceptionTable[exception];
    OSExceptionTable[exception] = handler;
    return oldHandler;
}

__OSExceptionHandler __OSGetExceptionHandler(__OSException exception) {
    return OSExceptionTable[exception];
}
#pragma dont_inline off

static asm void OSExceptionVector(void) {
    nofralloc

entry __OSEVStart
    mtsprg 0, r4

    lwz r4, OS_CURRENTCONTEXT_PADDR

    stw r3, OS_CONTEXT_R3(r4)
    mfsprg r3, 0
    stw r3, OS_CONTEXT_R4(r4)
    stw r5, OS_CONTEXT_R5(r4)

    lhz r3, OS_CONTEXT_STATE(r4)
    ori r3, r3, OS_CONTEXT_STATE_EXC
    sth r3, OS_CONTEXT_STATE(r4)

    mfcr r3
    stw r3, OS_CONTEXT_CR(r4)
    mflr r3
    stw r3, OS_CONTEXT_LR(r4)
    mfctr r3
    stw r3, OS_CONTEXT_CTR(r4)
    mfxer r3
    stw r3, OS_CONTEXT_XER(r4)
    mfsrr0 r3
    stw r3, OS_CONTEXT_SRR0(r4)
    mfsrr1 r3
    stw r3, OS_CONTEXT_SRR1(r4)
    mr r5, r3

entry __DBVECTOR
    nop

    mfmsr r3
    ori r3, r3, 0x30
    mtsrr1 r3

entry __OSEVSetNumber
    addi r3, 0, 0x0000

    lwz r4, 0xD4

    rlwinm. r5, r5, 0, 30, 30
    bne recoverable
    addis r5, 0, OSDefaultExceptionHandler@ha
    addi r5, r5, OSDefaultExceptionHandler@l
    mtsrr0 r5
    rfi

recoverable:
    rlwinm r5, r3, 2, 22, 29
    lwz r5, OS_EXCEPTIONTABLE_ADDR(r5)
    mtsrr0 r5

    rfi

entry __OSEVEnd
    nop
}

asm void OSDefaultExceptionHandler(register __OSException exception, register OSContext* context) {
    nofralloc
    stw r0, OS_CONTEXT_R0(context)
    stw r1, OS_CONTEXT_R1(context)
    stw r2, OS_CONTEXT_R2(context)
    stmw r6, OS_CONTEXT_R6(context)
    mfspr r0, GQR1
    stw r0, OS_CONTEXT_GQR1(context)
    mfspr r0, GQR2
    stw r0, OS_CONTEXT_GQR2(context)
    mfspr r0, GQR3
    stw r0, OS_CONTEXT_GQR3(context)
    mfspr r0, GQR4
    stw r0, OS_CONTEXT_GQR4(context)
    mfspr r0, GQR5
    stw r0, OS_CONTEXT_GQR5(context)
    mfspr r0, GQR6
    stw r0, OS_CONTEXT_GQR6(context)
    mfspr r0, GQR7
    stw r0, OS_CONTEXT_GQR7(context)
    mfdsisr r5
    mfdar r6

    stwu r1, -8(r1)
    b __OSUnhandledException
}

void __OSPSInit(void) {
    PPCMthid2(PPCMfhid2() | 0x80000000 | 0x20000000);
    ICFlashInvalidate();
    __sync();

    asm {
        li r3, 0
        mtspr GQR0, r3
        mtspr GQR1, r3
        mtspr GQR2, r3
        mtspr GQR3, r3
        mtspr GQR4, r3
        mtspr GQR5, r3
        mtspr GQR6, r3
        mtspr GQR7, r3
    }
}

#define __DIRegs ((vu32*)0xCC006000)

u32 __OSGetDIConfig(void) {
    return (__DIRegs[9] & 0xFF);
}

void OSRegisterVersion(const char* id) {
    OSReport("%s\n", id);
}

typedef struct {
    OSAlarm* head;
    OSAlarm* tail;
} OSAlarmQueue;

static void InsertAlarm(OSAlarm* alarm, OSTime fire, OSAlarmHandler handler);
static void DecrementerExceptionCallback(register __OSException exception, register OSContext* context);
static asm void DecrementerExceptionHandler(register __OSException exception, register OSContext* context);

static OSAlarmQueue AlarmQueue;

static void SetTimer(OSAlarm* alarm) {
    OSTime delta = alarm->fire - __OSGetSystemTime();

    if (delta < 0) {
        PPCMtdec(0);
    } else if (delta < 0x80000000) {
        PPCMtdec((u32)delta);
    } else {
        PPCMtdec(0x7fffffff);
    }
}

void OSInitAlarm(void) {
    if (__OSGetExceptionHandler(8) != DecrementerExceptionHandler) {
        AlarmQueue.head = AlarmQueue.tail = NULL;
        __OSSetExceptionHandler(8, DecrementerExceptionHandler);
    }
}

void OSCreateAlarm(OSAlarm* alarm) {
    alarm->handler = 0;
    alarm->tag = 0;
}

static void InsertAlarm(OSAlarm* alarm, OSTime fire, OSAlarmHandler handler) {
    OSAlarm* next;
    OSAlarm* prev;

    if (0 < alarm->period) {
        OSTime time = __OSGetSystemTime();

        fire = alarm->start;
        if (alarm->start < time) {
            fire += alarm->period * ((time - alarm->start) / alarm->period + 1);
        }
    }

    alarm->handler = handler;
    alarm->fire = fire;

    for (next = AlarmQueue.head; next; next = next->next) {
        if (next->fire <= fire) {
            continue;
        }

        alarm->prev = next->prev;
        next->prev = alarm;
        alarm->next = next;
        prev = alarm->prev;

        if (prev) {
            prev->next = alarm;
        } else {
            AlarmQueue.head = alarm;
            SetTimer(alarm);
        }

        return;
    }

    alarm->next = 0;
    prev = AlarmQueue.tail;
    AlarmQueue.tail = alarm;
    alarm->prev = prev;

    if (prev) {
        prev->next = alarm;
    } else {
        AlarmQueue.head = AlarmQueue.tail = alarm;
        SetTimer(alarm);
    }
}

void OSSetAlarm(OSAlarm* alarm, OSTime tick, OSAlarmHandler handler) {
    BOOL enabled;
    enabled = OSDisableInterrupts();
    alarm->period = 0;
    InsertAlarm(alarm, __OSGetSystemTime() + tick, handler);
    OSRestoreInterrupts(enabled);
}

void fn_803D3148(OSAlarm* alarm, OSTime start, OSTime period, OSAlarmHandler handler) {
    BOOL enabled;
    enabled = OSDisableInterrupts();
    alarm->period = period;
    alarm->start = kar_osthread__near_803db59c(start);
    InsertAlarm(alarm, 0, handler);
    OSRestoreInterrupts(enabled);
}

void OSCancelAlarm(OSAlarm* alarm) {
    OSAlarm* next;
    BOOL enabled;

    enabled = OSDisableInterrupts();

    if (alarm->handler == 0) {
        OSRestoreInterrupts(enabled);
        return;
    }

    next = alarm->next;
    if (next == 0) {
        AlarmQueue.tail = alarm->prev;
    } else {
        next->prev = alarm->prev;
    }
    if (alarm->prev) {
        alarm->prev->next = next;
    } else {
        AlarmQueue.head = next;
        if (next) {
            SetTimer(next);
        }
    }
    alarm->handler = 0;
    OSRestoreInterrupts(enabled);
}

static void DecrementerExceptionCallback(register __OSException exception, register OSContext* context) {
    OSAlarm* alarm;
    OSAlarm* next;
    OSAlarmHandler handler;
    OSTime time;
    OSContext exceptionContext;

    time = __OSGetSystemTime();
    alarm = AlarmQueue.head;
    if (alarm == 0) {
        OSLoadContext(context);
    }

    if (time < alarm->fire) {
        SetTimer(alarm);
        OSLoadContext(context);
    }

    next = alarm->next;
    AlarmQueue.head = next;
    if (next == 0) {
        AlarmQueue.tail = 0;
    } else {
        next->prev = 0;
    }

    handler = alarm->handler;
    alarm->handler = 0;
    if (0 < alarm->period) {
        InsertAlarm(alarm, 0, handler);
    }

    if (AlarmQueue.head) {
        SetTimer(AlarmQueue.head);
    }

    OSDisableScheduler();
    OSClearContext(&exceptionContext);
    OSSetCurrentContext(&exceptionContext);
    handler(alarm, context);
    OSClearContext(&exceptionContext);
    OSSetCurrentContext(context);
    OSEnableScheduler();
    __OSReschedule();
    OSLoadContext(context);
}

static asm void DecrementerExceptionHandler(register __OSException exception, register OSContext* context) {
    nofralloc
    stw r0, OS_CONTEXT_R0(context)
    stw r1, OS_CONTEXT_R1(context)
    stw r2, OS_CONTEXT_R2(context)
    stmw r6, OS_CONTEXT_R6(context)
    mfspr r0, GQR1
    stw r0, OS_CONTEXT_GQR1(context)
    mfspr r0, GQR2
    stw r0, OS_CONTEXT_GQR2(context)
    mfspr r0, GQR3
    stw r0, OS_CONTEXT_GQR3(context)
    mfspr r0, GQR4
    stw r0, OS_CONTEXT_GQR4(context)
    mfspr r0, GQR5
    stw r0, OS_CONTEXT_GQR5(context)
    mfspr r0, GQR6
    stw r0, OS_CONTEXT_GQR6(context)
    mfspr r0, GQR7
    stw r0, OS_CONTEXT_GQR7(context)
    stwu r1, -8(r1)
    b DecrementerExceptionCallback
}

Cell* fn_803D3560(Cell* list, Cell* cell) {
    Cell* prev;
    Cell* next;

    for (next = list, prev = NULL; next != 0; prev = next, next = next->next) {
        if (cell <= next) {
            break;
        }
    }

    cell->next = next;
    cell->prev = prev;
    if (next) {
        next->prev = cell;
        if ((u8*)cell + cell->size == (u8*)next) {
            cell->size += next->size;
            next = next->next;
            cell->next = next;
            if (next) {
                next->prev = cell;
            }
        }
    }
    if (prev) {
        prev->next = cell;
        if ((u8*)prev + prev->size == (u8*)cell) {
            prev->size += cell->size;
            prev->next = next;
            if (next) {
                next->prev = prev;
            }
        }
        return list;
    }
    return cell;
}

volatile int lbl_805DC978 = -1;

static HeapDesc* lbl_805DDEB0;
static int lbl_805DDEB4;
static void* lbl_805DDEB8;
static void* lbl_805DDEBC;

static Cell* DLExtract(Cell* list, Cell* cell) {
    if (cell->next) {
        cell->next->prev = cell->prev;
    }
    if (cell->prev == NULL) {
        return cell->next;
    }
    cell->prev->next = cell->next;
    return list;
}

static Cell* DLAddFront(Cell* list, Cell* cell) {
    cell->next = list;
    cell->prev = 0;
    if (list) {
        list->prev = cell;
    }
    return cell;
}

void* OSAllocFromHeap(int heap, u32 size) {
    HeapDesc* hd;
    Cell* cell;
    Cell* newCell;
    s32 leftoverSize;

    hd = &lbl_805DDEB0[heap];
    size += 0x20;
    size = (size + 0x1F) & 0xFFFFFFE0;

    for (cell = hd->free; cell != NULL; cell = cell->next) {
        if ((signed)size <= (signed)cell->size) {
            break;
        }
    }

    if (cell == NULL) {
        return NULL;
    }

    leftoverSize = cell->size - size;
    if (leftoverSize < 0x40U) {
        hd->free = DLExtract(hd->free, cell);
    } else {
        cell->size = size;
        newCell = (void*)((u8*)cell + size);
        newCell->size = leftoverSize;
        newCell->prev = cell->prev;
        newCell->next = cell->next;
        if (newCell->next != NULL) {
            newCell->next->prev = newCell;
        }
        if (newCell->prev != NULL) {
            newCell->prev->next = newCell;
        } else {
            hd->free = newCell;
        }
    }

    hd->allocated = DLAddFront(hd->allocated, cell);
    return (u8*)cell + 0x20;
}

void OSFreeToHeap(int heap, void* ptr) {
    HeapDesc* hd;
    Cell* cell;

    cell = (void*)((u32)ptr - 0x20);
    hd = &lbl_805DDEB0[heap];
    hd->allocated = DLExtract(hd->allocated, cell);
    hd->free = fn_803D3560(hd->free, cell);
}

int OSSetCurrentHeap(int heap) {
    int prev;

    prev = lbl_805DC978;
    lbl_805DC978 = heap;
    return prev;
}

void* OSInitAlloc(void* arenaStart, void* arenaEnd, int maxHeaps) {
    u32 arraySize;
    int i;
    HeapDesc* hd;

    arraySize = maxHeaps * sizeof(HeapDesc);
    lbl_805DDEB0 = arenaStart;
    lbl_805DDEB4 = maxHeaps;

    for (i = 0; i < lbl_805DDEB4; i++) {
        hd = &lbl_805DDEB0[i];
        hd->size = -1;
        hd->free = hd->allocated = 0;
    }
    lbl_805DC978 = -1;
    arenaStart = (void*)((u32)((char*)lbl_805DDEB0 + arraySize));
    arenaStart = (void*)(((u32)arenaStart + 0x1F) & 0xFFFFFFE0);
    lbl_805DDEB8 = arenaStart;
    lbl_805DDEBC = (void*)((u32)arenaEnd & 0xFFFFFFE0);
    return arenaStart;
}

int OSCreateHeap(void* start, void* end) {
    int heap;
    HeapDesc* hd;
    Cell* cell;

    start = (void*)(((u32)start + 0x1FU) & ~((32) - 1));
    end = (void*)(((u32)end) & ~((32) - 1));

    for (heap = 0; heap < lbl_805DDEB4; heap++) {
        hd = &lbl_805DDEB0[heap];
        if (hd->size < 0) {
            hd->size = (u32)end - (u32)start;
            cell = start;
            cell->prev = 0;
            cell->next = 0;
            cell->size = hd->size;
            hd->free = cell;
            hd->allocated = 0;
            return heap;
        }
    }
    return -1;
}

void OSDestroyHeap(int heap) {
    lbl_805DDEB0[heap].size = -1;
}

#define ASSERTREPORT(line, cond) \
    if (!(cond)) { \
        OSReport("OSCheckHeap: Failed " #cond " in %d", line); \
        return -1; \
    }

#define OFFSET(addr, align) (((u32)(addr) & ((align) - 1)))
#define ALIGNMENT 32
#define InRange(cell, arenaStart, arenaEnd) \
    ((u32)arenaStart <= (u32)cell) && ((u32)cell < (u32)arenaEnd)
#define HEADERSIZE 32u
#define MINOBJSIZE 64u

s32 kar_diag__803d3884(int heap) {
    HeapDesc* hd;
    Cell* cell;
    s32 total = 0;
    s32 free = 0;

    ASSERTREPORT(893, lbl_805DDEB0);
    ASSERTREPORT(894, 0 <= heap && heap < lbl_805DDEB4);
    hd = &lbl_805DDEB0[heap];
    ASSERTREPORT(897, 0 <= hd->size);

    ASSERTREPORT(899, hd->allocated == NULL || hd->allocated->prev == NULL);

    for (cell = hd->allocated; cell; cell = cell->next) {
        ASSERTREPORT(902, InRange(cell, lbl_805DDEB8, lbl_805DDEBC));
        ASSERTREPORT(903, OFFSET(cell, ALIGNMENT) == 0);
        ASSERTREPORT(904, cell->next == NULL || cell->next->prev == cell);
        ASSERTREPORT(905, MINOBJSIZE <= cell->size);
        ASSERTREPORT(906, OFFSET(cell->size, ALIGNMENT) == 0);
        total += cell->size;
        ASSERTREPORT(909, 0 < total && total <= hd->size);
    }

    ASSERTREPORT(917, hd->free == NULL || hd->free->prev == NULL);

    for (cell = hd->free; cell; cell = cell->next) {
        ASSERTREPORT(920, InRange(cell, lbl_805DDEB8, lbl_805DDEBC));
        ASSERTREPORT(921, OFFSET(cell, ALIGNMENT) == 0);
        ASSERTREPORT(922, cell->next == NULL || cell->next->prev == cell);
        ASSERTREPORT(923, MINOBJSIZE <= cell->size);
        ASSERTREPORT(924, OFFSET(cell->size, ALIGNMENT) == 0);
        ASSERTREPORT(925, cell->next == NULL || (char*)cell + cell->size < (char*)cell->next);
        total += cell->size;
        free = (cell->size + free);
        free -= HEADERSIZE;
        ASSERTREPORT(929, 0 < total && total <= hd->size);
    }
    ASSERTREPORT(936, total == hd->size);
    return free;
}

#define ROUND(n, a) (((u32)(n) + (a) - 1) & ~((a) - 1))
#define TRUNC(n, a) (((u32)(n)) & ~((a) - 1))

static void* __OSArenaHi;
static void* __OSArenaLo = (void*)-1;

void* OSGetArenaHi(void) {
    return __OSArenaHi;
}

void* OSGetArenaLo(void) {
    return __OSArenaLo;
}

void OSSetArenaHi(void* newHi) {
    __OSArenaHi = newHi;
}

void OSSetArenaLo(void* newLo) {
    __OSArenaLo = newLo;
}

void* OSAllocFromArenaLo(u32 size, u32 align) {
    void* ptr;
    u8* arenaLo;

    ptr = OSGetArenaLo();
    arenaLo = ptr = (void*)ROUND(ptr, align);
    arenaLo += size;
    arenaLo = (u8*)ROUND(arenaLo, align);
    OSSetArenaLo(arenaLo);
    return ptr;
}

void* kar_diag__near_803d3c30(u32 size, u32 align) {
    void* ptr;
    u8* arenaHi;

    arenaHi = OSGetArenaHi();
    arenaHi = (u8*)TRUNC(arenaHi, align);
    arenaHi -= size;
    arenaHi = ptr = (void*)TRUNC(arenaHi, align);
    OSSetArenaHi(arenaHi);
    return ptr;
}

#define __DSPRegs ((volatile u16*)0xCC005000)
#define __DSPWorkBuffer (void*)0x81000000

static u8 DSPInitCode[128] = {
    0x02, 0x9F, 0x00, 0x10, 0x02, 0x9F, 0x00, 0x33, 0x02, 0x9F, 0x00, 0x34, 0x02, 0x9F, 0x00, 0x35,
    0x02, 0x9F, 0x00, 0x36, 0x02, 0x9F, 0x00, 0x37, 0x02, 0x9F, 0x00, 0x38, 0x02, 0x9F, 0x00, 0x39,
    0x12, 0x06, 0x12, 0x03, 0x12, 0x04, 0x12, 0x05, 0x00, 0x80, 0x80, 0x00, 0x00, 0x88, 0xFF, 0xFF,
    0x00, 0x84, 0x10, 0x00, 0x00, 0x64, 0x00, 0x1D, 0x02, 0x18, 0x00, 0x00, 0x81, 0x00, 0x1C, 0x1E,
    0x00, 0x44, 0x1B, 0x1E, 0x00, 0x84, 0x08, 0x00, 0x00, 0x64, 0x00, 0x27, 0x19, 0x1E, 0x00, 0x00,
    0x00, 0xDE, 0xFF, 0xFC, 0x02, 0xA0, 0x80, 0x00, 0x02, 0x9C, 0x00, 0x28, 0x16, 0xFC, 0x00, 0x54,
    0x16, 0xFD, 0x43, 0x48, 0x00, 0x21, 0x02, 0xFF, 0x02, 0xFF, 0x02, 0xFF, 0x02, 0xFF, 0x02, 0xFF,
    0x02, 0xFF, 0x02, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

void __OSInitAudioSystem(void) {
    u8 errFlag;
    u16 reg16;
    u32 start_tick;

    memcpy((void*)((u32)OSGetArenaHi() - 0x80), __DSPWorkBuffer, sizeof(DSPInitCode));
    memcpy(__DSPWorkBuffer, (void*)DSPInitCode, sizeof(DSPInitCode));
    DCFlushRange(__DSPWorkBuffer, sizeof(DSPInitCode));

    __DSPRegs[9] = 0x43;

    __DSPRegs[5] = 0x8AC;
    __DSPRegs[5] |= 1;

    while (__DSPRegs[5] & 1)
        ;
    __DSPRegs[0] = 0;

    while (((__DSPRegs[2] << 16) | __DSPRegs[3]) & 0x80000000)
        ;

    *(u32*)&__DSPRegs[16] = 0x1000000;
    *(u32*)&__DSPRegs[18] = 0;
    *(u32*)&__DSPRegs[20] = 0x20;

    reg16 = __DSPRegs[5];
    while (!(reg16 & 0x20))
        reg16 = __DSPRegs[5];

    __DSPRegs[5] = reg16;

    start_tick = OSGetTick();
    while ((s32)(OSGetTick() - start_tick) < 0x892)
        ;

    *(u32*)&__DSPRegs[16] = 0x1000000;
    *(u32*)&__DSPRegs[18] = 0;
    *(u32*)&__DSPRegs[20] = 0x20;

    reg16 = __DSPRegs[5];
    while (!(reg16 & 0x20)) {
        reg16 = __DSPRegs[5];
    }
    __DSPRegs[5] = reg16;

    __DSPRegs[5] &= ~0x800;
    while ((__DSPRegs[5]) & 0x400)
        ;

    __DSPRegs[5] &= ~4;
    errFlag = 0;

    reg16 = __DSPRegs[2];

    while (!(reg16 & 0x8000)) {
        reg16 = __DSPRegs[2];
    }

    reg16 != 0x81800;
    __DSPRegs[5] |= 4;
    __DSPRegs[5] = 0x8AC;
    __DSPRegs[5] |= 1;
    while (__DSPRegs[5] & 1)
        ;

    memcpy(__DSPWorkBuffer, (void*)((u32)OSGetArenaHi() - 0x80), sizeof(DSPInitCode));
}

void __OSStopAudioSystem(void) {
    u16 reg16;
    u32 start_tick;

#define waitUntil(load, mask) \
    reg16 = (load); \
    while (reg16 & (mask)) { \
        reg16 = (load); \
    }

    __DSPRegs[5] = 0x804;
    reg16 = __DSPRegs[27];
    __DSPRegs[27] = reg16 & ~0x8000;
    waitUntil(__DSPRegs[5], 0x400);
    waitUntil(__DSPRegs[5], 0x200);
    __DSPRegs[5] = 0x8ac;
    __DSPRegs[0] = 0;

    while (((__DSPRegs[2] << 16) | __DSPRegs[3]) & 0x80000000)
        ;

    start_tick = OSGetTick();
    while ((s32)(OSGetTick() - start_tick) < 0x2c)
        ;

    reg16 = __DSPRegs[5];
    __DSPRegs[5] = reg16 | 1;
    waitUntil(__DSPRegs[5], 0x001);

#undef waitUntil
}

asm void DCEnable(void) {
    nofralloc
    sync
    mfspr r3, HID0
    ori r3, r3, 0x4000
    mtspr HID0, r3
    blr
}

asm void DCInvalidateRange(register void* addr, register u32 nBytes) {
    nofralloc
    cmplwi nBytes, 0
    blelr
    clrlwi r5, addr, 27
    add nBytes, nBytes, r5
    addi nBytes, nBytes, 31
    srwi nBytes, nBytes, 5
    mtctr nBytes

L1:
    dcbi r0, addr
    addi addr, addr, 32
    bdnz L1
    blr
}

asm void DCFlushRange(register void* addr, register u32 nBytes) {
    nofralloc
    cmplwi nBytes, 0
    blelr
    clrlwi r5, addr, 27
    add nBytes, nBytes, r5
    addi nBytes, nBytes, 31
    srwi nBytes, nBytes, 5
    mtctr nBytes

L1:
    dcbf r0, addr
    addi addr, addr, 32
    bdnz L1
    sc
    blr
}

asm void kar_diag__near_803d3f54(register void* addr, register u32 nBytes) {
    nofralloc
    cmplwi nBytes, 0
    blelr
    clrlwi r5, addr, 27
    add nBytes, nBytes, r5
    addi nBytes, nBytes, 31
    srwi nBytes, nBytes, 5
    mtctr nBytes

L1:
    dcbst r0, addr
    addi addr, addr, 32
    bdnz L1
    sc
    blr
}

asm void DCFlushRangeNoSync(register void* addr, register u32 nBytes) {
    nofralloc
    cmplwi nBytes, 0
    blelr
    clrlwi r5, addr, 27
    add nBytes, nBytes, r5
    addi nBytes, nBytes, 31
    srwi nBytes, nBytes, 5
    mtctr nBytes

L1:
    dcbf r0, addr
    addi addr, addr, 32
    bdnz L1
    blr
}

asm void ICInvalidateRange(register void* addr, register u32 nBytes) {
    nofralloc
    cmplwi nBytes, 0
    blelr
    clrlwi r5, addr, 27
    add nBytes, nBytes, r5
    addi nBytes, nBytes, 31
    srwi nBytes, nBytes, 5
    mtctr nBytes

L1:
    icbi r0, addr
    addi addr, addr, 32
    bdnz L1
    sync
    isync
    blr
}

asm void ICFlashInvalidate(void) {
    nofralloc
    mfspr r3, HID0
    ori r3, r3, 0x800
    mtspr HID0, r3
    blr
}

asm void ICEnable(void) {
    nofralloc
    isync
    mfspr r3, HID0
    ori r3, r3, 0x8000
    mtspr HID0, r3
    blr
}

asm void LCDisable(void) {
    nofralloc
    lis r3, 0xe000
    li r4, 0x200
    mtctr r4
L1:
    dcbi r0, r3
    addi r3, r3, 32
    bdnz L1
    mfspr r4, 920
    rlwinm r4, r4, 0, 4, 2
    mtspr 920, r4
    blr
}

#pragma dont_inline on
void L2GlobalInvalidate(void) {
    __sync();
    PPCMtl2cr(PPCMfl2cr() & ~0x80000000);
    __sync();
    PPCMtl2cr(PPCMfl2cr() | 0x00200000);
    while (PPCMfl2cr() & 0x00000001u)
        ;

    PPCMtl2cr(PPCMfl2cr() & ~0x00200000);
    while (PPCMfl2cr() & 0x00000001u) {
        DBPrintf(">>> L2 INVALIDATE : SHOULD NEVER HAPPEN\n");
    }
}
#pragma dont_inline off

#define HID2_DCHERR 0x00800000
#define HID2_DNCERR 0x00400000
#define HID2_DCMERR 0x00200000
#define HID2_DQOERR 0x00100000
#define SRR1_DMA_BIT 0x00200000

void DMAErrorHandler(OSError error, OSContext* context, ...) {
    u32 hid2 = PPCMfhid2();

    OSReport("Machine check received\n");
    OSReport("HID2 = 0x%x   SRR1 = 0x%x\n", hid2, context->srr1);
    if (!(hid2 & (HID2_DCHERR | HID2_DNCERR | HID2_DCMERR | HID2_DQOERR)) || !(context->srr1 & SRR1_DMA_BIT)) {
        OSReport("Machine check was not DMA/locked cache related\n");
        OSDumpContext(context);
        PPCHalt();
    }

    OSReport("DMAErrorHandler(): An error occurred while processing DMA.\n");
    OSReport("The following errors have been detected and cleared :\n");

    if (hid2 & HID2_DCHERR) {
        OSReport("\t- Requested a locked cache tag that was already in the cache\n");
    }

    if (hid2 & HID2_DNCERR) {
        OSReport("\t- DMA attempted to access normal cache\n");
    }

    if (hid2 & HID2_DCMERR) {
        OSReport("\t- DMA missed in data cache\n");
    }

    if (hid2 & HID2_DQOERR) {
        OSReport("\t- DMA queue overflowed\n");
    }

    PPCMthid2(hid2);
}

#define HID0_ICE 0x00008000
#define HID0_DCE 0x00004000
#define L2CR_L2E 0x80000000
#define L2CR_L2I 0x00200000
#define MSR_IR 0x20
#define MSR_DR 0x10

void __OSCacheInit(void) {
    if (!(PPCMfhid0() & HID0_ICE)) {
        ICEnable();
        DBPrintf("L1 i-caches initialized\n");
    }

    if (!(PPCMfhid0() & HID0_DCE)) {
        DCEnable();
        DBPrintf("L1 d-caches initialized\n");
    }

    if (!(PPCMfl2cr() & L2CR_L2E)) {
        u32 oldMSR;
        oldMSR = PPCMfmsr();
        __sync();
        PPCMtmsr(MSR_IR | MSR_DR);
        __sync();
        __sync();
        PPCMtl2cr(PPCMfl2cr() & ~0x80000000);
        __sync();
        L2GlobalInvalidate();
        PPCMtmsr(oldMSR);
        PPCMtl2cr((PPCMfl2cr() | L2CR_L2E) & ~L2CR_L2I);
        DBPrintf("L2 cache initialized\n");
    }

    OSSetErrorHandler(OS_ERROR_MACHINE_CHECK, DMAErrorHandler);
    DBPrintf("Locked cache machine check handler installed\n");
}

#define __OSCurrentContext (*(OSContext**)0x800000D4)
#define __OSFPUContext (*(OSContext**)0x800000D8)

static asm void __OSLoadFPUContext(register u32 dummy, register OSContext* fpucontext) {
    nofralloc
    lhz r5, fpucontext->state
    clrlwi. r5, r5, 31
    beq L_return

    lfd fp0, OS_CONTEXT_FPSCR(fpucontext)
    mtfsf 0xFF, fp0
    mfspr r5, 920
    rlwinm. r5, r5, 3, 31, 31
    beq L_regular_FPRs

    psq_l fp0, OS_CONTEXT_PSF0(fpucontext), 0, 0
    psq_l fp1, OS_CONTEXT_PSF1(fpucontext), 0, 0
    psq_l fp2, OS_CONTEXT_PSF2(fpucontext), 0, 0
    psq_l fp3, OS_CONTEXT_PSF3(fpucontext), 0, 0
    psq_l fp4, OS_CONTEXT_PSF4(fpucontext), 0, 0
    psq_l fp5, OS_CONTEXT_PSF5(fpucontext), 0, 0
    psq_l fp6, OS_CONTEXT_PSF6(fpucontext), 0, 0
    psq_l fp7, OS_CONTEXT_PSF7(fpucontext), 0, 0
    psq_l fp8, OS_CONTEXT_PSF8(fpucontext), 0, 0
    psq_l fp9, OS_CONTEXT_PSF9(fpucontext), 0, 0
    psq_l fp10, OS_CONTEXT_PSF10(fpucontext), 0, 0
    psq_l fp11, OS_CONTEXT_PSF11(fpucontext), 0, 0
    psq_l fp12, OS_CONTEXT_PSF12(fpucontext), 0, 0
    psq_l fp13, OS_CONTEXT_PSF13(fpucontext), 0, 0
    psq_l fp14, OS_CONTEXT_PSF14(fpucontext), 0, 0
    psq_l fp15, OS_CONTEXT_PSF15(fpucontext), 0, 0
    psq_l fp16, OS_CONTEXT_PSF16(fpucontext), 0, 0
    psq_l fp17, OS_CONTEXT_PSF17(fpucontext), 0, 0
    psq_l fp18, OS_CONTEXT_PSF18(fpucontext), 0, 0
    psq_l fp19, OS_CONTEXT_PSF19(fpucontext), 0, 0
    psq_l fp20, OS_CONTEXT_PSF20(fpucontext), 0, 0
    psq_l fp21, OS_CONTEXT_PSF21(fpucontext), 0, 0
    psq_l fp22, OS_CONTEXT_PSF22(fpucontext), 0, 0
    psq_l fp23, OS_CONTEXT_PSF23(fpucontext), 0, 0
    psq_l fp24, OS_CONTEXT_PSF24(fpucontext), 0, 0
    psq_l fp25, OS_CONTEXT_PSF25(fpucontext), 0, 0
    psq_l fp26, OS_CONTEXT_PSF26(fpucontext), 0, 0
    psq_l fp27, OS_CONTEXT_PSF27(fpucontext), 0, 0
    psq_l fp28, OS_CONTEXT_PSF28(fpucontext), 0, 0
    psq_l fp29, OS_CONTEXT_PSF29(fpucontext), 0, 0
    psq_l fp30, OS_CONTEXT_PSF30(fpucontext), 0, 0
    psq_l fp31, OS_CONTEXT_PSF31(fpucontext), 0, 0

L_regular_FPRs:
    lfd fp0, fpucontext->fpr[0]
    lfd fp1, fpucontext->fpr[1]
    lfd fp2, fpucontext->fpr[2]
    lfd fp3, fpucontext->fpr[3]
    lfd fp4, fpucontext->fpr[4]
    lfd fp5, fpucontext->fpr[5]
    lfd fp6, fpucontext->fpr[6]
    lfd fp7, fpucontext->fpr[7]
    lfd fp8, fpucontext->fpr[8]
    lfd fp9, fpucontext->fpr[9]
    lfd fp10, fpucontext->fpr[10]
    lfd fp11, fpucontext->fpr[11]
    lfd fp12, fpucontext->fpr[12]
    lfd fp13, fpucontext->fpr[13]
    lfd fp14, fpucontext->fpr[14]
    lfd fp15, fpucontext->fpr[15]
    lfd fp16, fpucontext->fpr[16]
    lfd fp17, fpucontext->fpr[17]
    lfd fp18, fpucontext->fpr[18]
    lfd fp19, fpucontext->fpr[19]
    lfd fp20, fpucontext->fpr[20]
    lfd fp21, fpucontext->fpr[21]
    lfd fp22, fpucontext->fpr[22]
    lfd fp23, fpucontext->fpr[23]
    lfd fp24, fpucontext->fpr[24]
    lfd fp25, fpucontext->fpr[25]
    lfd fp26, fpucontext->fpr[26]
    lfd fp27, fpucontext->fpr[27]
    lfd fp28, fpucontext->fpr[28]
    lfd fp29, fpucontext->fpr[29]
    lfd fp30, fpucontext->fpr[30]
    lfd fp31, fpucontext->fpr[31]
L_return:
    blr
}

static asm void __OSSaveFPUContext(register u32 dummy1, register u32 dummy2, register OSContext* fpucontext) {
    nofralloc

    lhz r3, fpucontext->state
    ori r3, r3, 1
    sth r3, fpucontext->state

    stfd fp0, fpucontext->fpr[0]
    stfd fp1, fpucontext->fpr[1]
    stfd fp2, fpucontext->fpr[2]
    stfd fp3, fpucontext->fpr[3]
    stfd fp4, fpucontext->fpr[4]
    stfd fp5, fpucontext->fpr[5]
    stfd fp6, fpucontext->fpr[6]
    stfd fp7, fpucontext->fpr[7]
    stfd fp8, fpucontext->fpr[8]
    stfd fp9, fpucontext->fpr[9]
    stfd fp10, fpucontext->fpr[10]
    stfd fp11, fpucontext->fpr[11]
    stfd fp12, fpucontext->fpr[12]
    stfd fp13, fpucontext->fpr[13]
    stfd fp14, fpucontext->fpr[14]
    stfd fp15, fpucontext->fpr[15]
    stfd fp16, fpucontext->fpr[16]
    stfd fp17, fpucontext->fpr[17]
    stfd fp18, fpucontext->fpr[18]
    stfd fp19, fpucontext->fpr[19]
    stfd fp20, fpucontext->fpr[20]
    stfd fp21, fpucontext->fpr[21]
    stfd fp22, fpucontext->fpr[22]
    stfd fp23, fpucontext->fpr[23]
    stfd fp24, fpucontext->fpr[24]
    stfd fp25, fpucontext->fpr[25]
    stfd fp26, fpucontext->fpr[26]
    stfd fp27, fpucontext->fpr[27]
    stfd fp28, fpucontext->fpr[28]
    stfd fp29, fpucontext->fpr[29]
    stfd fp30, fpucontext->fpr[30]
    stfd fp31, fpucontext->fpr[31]

    mffs fp0
    stfd fp0, OS_CONTEXT_FPSCR(fpucontext)

    lfd fp0, fpucontext->fpr[0]

    mfspr r3, 920
    rlwinm. r3, r3, 3, 31, 31
    bc 12, 2, L_return2

    psq_st fp0, OS_CONTEXT_PSF0(fpucontext), 0, 0
    psq_st fp1, OS_CONTEXT_PSF1(fpucontext), 0, 0
    psq_st fp2, OS_CONTEXT_PSF2(fpucontext), 0, 0
    psq_st fp3, OS_CONTEXT_PSF3(fpucontext), 0, 0
    psq_st fp4, OS_CONTEXT_PSF4(fpucontext), 0, 0
    psq_st fp5, OS_CONTEXT_PSF5(fpucontext), 0, 0
    psq_st fp6, OS_CONTEXT_PSF6(fpucontext), 0, 0
    psq_st fp7, OS_CONTEXT_PSF7(fpucontext), 0, 0
    psq_st fp8, OS_CONTEXT_PSF8(fpucontext), 0, 0
    psq_st fp9, OS_CONTEXT_PSF9(fpucontext), 0, 0
    psq_st fp10, OS_CONTEXT_PSF10(fpucontext), 0, 0
    psq_st fp11, OS_CONTEXT_PSF11(fpucontext), 0, 0
    psq_st fp12, OS_CONTEXT_PSF12(fpucontext), 0, 0
    psq_st fp13, OS_CONTEXT_PSF13(fpucontext), 0, 0
    psq_st fp14, OS_CONTEXT_PSF14(fpucontext), 0, 0
    psq_st fp15, OS_CONTEXT_PSF15(fpucontext), 0, 0
    psq_st fp16, OS_CONTEXT_PSF16(fpucontext), 0, 0
    psq_st fp17, OS_CONTEXT_PSF17(fpucontext), 0, 0
    psq_st fp18, OS_CONTEXT_PSF18(fpucontext), 0, 0
    psq_st fp19, OS_CONTEXT_PSF19(fpucontext), 0, 0
    psq_st fp20, OS_CONTEXT_PSF20(fpucontext), 0, 0
    psq_st fp21, OS_CONTEXT_PSF21(fpucontext), 0, 0
    psq_st fp22, OS_CONTEXT_PSF22(fpucontext), 0, 0
    psq_st fp23, OS_CONTEXT_PSF23(fpucontext), 0, 0
    psq_st fp24, OS_CONTEXT_PSF24(fpucontext), 0, 0
    psq_st fp25, OS_CONTEXT_PSF25(fpucontext), 0, 0
    psq_st fp26, OS_CONTEXT_PSF26(fpucontext), 0, 0
    psq_st fp27, OS_CONTEXT_PSF27(fpucontext), 0, 0
    psq_st fp28, OS_CONTEXT_PSF28(fpucontext), 0, 0
    psq_st fp29, OS_CONTEXT_PSF29(fpucontext), 0, 0
    psq_st fp30, OS_CONTEXT_PSF30(fpucontext), 0, 0
    psq_st fp31, OS_CONTEXT_PSF31(fpucontext), 0, 0

L_return2:
    blr
}

asm void OSSaveFPUContext(register OSContext* fpucontext) {
    nofralloc
    addi r5, fpucontext, 0
    b __OSSaveFPUContext
}

asm void OSSetCurrentContext(register OSContext* context) {
    nofralloc

    addis r4, r0, 0x8000

    stw context, 0x00D4(r4)

    clrlwi r5, context, 2
    stw r5, 0x00C0(r4)

    lwz r5, 0x00D8(r4)
    cmpw r5, context
    bne L_disableFPU

    lwz r6, context->srr1
    ori r6, r6, 0x2000
    stw r6, context->srr1
    mfmsr r6
    ori r6, r6, 2
    mtmsr r6
    blr

L_disableFPU:
    lwz r6, context->srr1
    rlwinm r6, r6, 0, 19, 17
    stw r6, context->srr1
    mfmsr r6
    rlwinm r6, r6, 0, 19, 17
    ori r6, r6, 2
    mtmsr r6
    isync
    blr
}

OSContext* OSGetCurrentContext(void) {
    return (OSContext*)__OSCurrentContext;
}

asm u32 OSSaveContext(register OSContext* context) {
    nofralloc
    stmw r13, context->gpr[13]
    mfspr r0, GQR1
    stw r0, context->gqr[1]
    mfspr r0, GQR2
    stw r0, context->gqr[2]
    mfspr r0, GQR3
    stw r0, context->gqr[3]
    mfspr r0, GQR4
    stw r0, context->gqr[4]
    mfspr r0, GQR5
    stw r0, context->gqr[5]
    mfspr r0, GQR6
    stw r0, context->gqr[6]
    mfspr r0, GQR7
    stw r0, context->gqr[7]
    mfcr r0
    stw r0, context->cr
    mflr r0
    stw r0, context->lr
    stw r0, context->srr0
    mfmsr r0
    stw r0, context->srr1
    mfctr r0
    stw r0, context->ctr
    mfxer r0
    stw r0, context->xer
    stw r1, context->gpr[1]
    stw r2, context->gpr[2]
    li r0, 0x1
    stw r0, context->gpr[3]
    li r3, 0
    blr
}

extern BOOL OSDisableInterrupts(void);

asm void OSLoadContext(register OSContext* context) {
    nofralloc

    lis r4, OSDisableInterrupts@ha
    lwz r6, context->srr0
    addi r5, r4, OSDisableInterrupts@l
    cmplw r6, r5
    ble L_notInRAS
    lis r4, (OSDisableInterrupts + 0xc)@ha
    addi r0, r4, (OSDisableInterrupts + 0xc)@l
    cmplw r6, r0
    bge L_notInRAS
    stw r5, context->srr0

L_notInRAS:

    lwz r0, context->gpr[0]
    lwz r1, context->gpr[1]
    lwz r2, context->gpr[2]

    lhz r4, context->state
    rlwinm. r5, r4, 0, 30, 30
    beq L_notexc
    rlwinm r4, r4, 0, 31, 29
    sth r4, context->state
    lmw r5, context->gpr[5]
    b L_misc
L_notexc:
    lmw r13, context->gpr[13]
L_misc:

    lwz r4, context->gqr[1]
    mtspr GQR1, r4
    lwz r4, context->gqr[2]
    mtspr GQR2, r4
    lwz r4, context->gqr[3]
    mtspr GQR3, r4
    lwz r4, context->gqr[4]
    mtspr GQR4, r4
    lwz r4, context->gqr[5]
    mtspr GQR5, r4
    lwz r4, context->gqr[6]
    mtspr GQR6, r4
    lwz r4, context->gqr[7]
    mtspr GQR7, r4

    lwz r4, context->cr
    mtcr r4
    lwz r4, context->lr
    mtlr r4
    lwz r4, context->ctr
    mtctr r4
    lwz r4, context->xer
    mtxer r4

    mfmsr r4
    rlwinm r4, r4, 0, 17, 15
    rlwinm r4, r4, 0, 31, 29
    mtmsr r4

    lwz r4, context->srr0
    mtsrr0 r4
    lwz r4, context->srr1
    mtsrr1 r4

    lwz r4, context->gpr[4]
    lwz r3, context->gpr[3]

    rfi
}

asm u32 OSGetStackPointer(void) {
    nofralloc
    mr r3, r1
    blr
}

asm int fn_803D4738(register u32 pc, register u32 newsp) {
    nofralloc
    mflr r0
    mr r5, r1
    stwu r5, -8(newsp)
    mr r1, newsp
    stw r0, 4(r5)
    mtlr pc
    blrl
    lwz r5, 0(r1)
    lwz r0, 4(r5)
    mtlr r0
    mr r1, r5
    blr
}

void OSClearContext(register OSContext* context) {
    context->mode = 0;
    context->state = 0;
    if (context == __OSFPUContext)
        __OSFPUContext = NULL;
}

asm void OSInitContext(register OSContext* context, register u32 pc, register u32 newsp) {
    nofralloc

    stw pc, OS_CONTEXT_SRR0(context)
    stw newsp, OS_CONTEXT_R1(context)
    li r11, 0
    ori r11, r11, 0x00008000 | 0x00000020 | 0x00000010 | 0x00000002 | 0x00001000
    stw r11, OS_CONTEXT_SRR1(context)
    li r0, 0x0
    stw r0, OS_CONTEXT_CR(context)
    stw r0, OS_CONTEXT_XER(context)

    stw r2, OS_CONTEXT_R2(context)
    stw r13, OS_CONTEXT_R13(context)

    stw r0, OS_CONTEXT_R3(context)
    stw r0, OS_CONTEXT_R4(context)
    stw r0, OS_CONTEXT_R5(context)
    stw r0, OS_CONTEXT_R6(context)
    stw r0, OS_CONTEXT_R7(context)
    stw r0, OS_CONTEXT_R8(context)
    stw r0, OS_CONTEXT_R9(context)
    stw r0, OS_CONTEXT_R10(context)
    stw r0, OS_CONTEXT_R11(context)
    stw r0, OS_CONTEXT_R12(context)

    stw r0, OS_CONTEXT_R14(context)
    stw r0, OS_CONTEXT_R15(context)
    stw r0, OS_CONTEXT_R16(context)
    stw r0, OS_CONTEXT_R17(context)
    stw r0, OS_CONTEXT_R18(context)
    stw r0, OS_CONTEXT_R19(context)
    stw r0, OS_CONTEXT_R20(context)
    stw r0, OS_CONTEXT_R21(context)
    stw r0, OS_CONTEXT_R22(context)
    stw r0, OS_CONTEXT_R23(context)
    stw r0, OS_CONTEXT_R24(context)
    stw r0, OS_CONTEXT_R25(context)
    stw r0, OS_CONTEXT_R26(context)
    stw r0, OS_CONTEXT_R27(context)
    stw r0, OS_CONTEXT_R28(context)
    stw r0, OS_CONTEXT_R29(context)
    stw r0, OS_CONTEXT_R30(context)
    stw r0, OS_CONTEXT_R31(context)

    stw r0, OS_CONTEXT_GQR0(context)
    stw r0, OS_CONTEXT_GQR1(context)
    stw r0, OS_CONTEXT_GQR2(context)
    stw r0, OS_CONTEXT_GQR3(context)
    stw r0, OS_CONTEXT_GQR4(context)
    stw r0, OS_CONTEXT_GQR5(context)
    stw r0, OS_CONTEXT_GQR6(context)
    stw r0, OS_CONTEXT_GQR7(context)

    b OSClearContext
}

void OSDumpContext(OSContext* context) {
    u32 i;
    u32* p;

    OSReport("------------------------- Context 0x%08x -------------------------\n", context);

    for (i = 0; i < 16; ++i) {
        OSReport("r%-2d  = 0x%08x (%14d)  r%-2d  = 0x%08x (%14d)\n", i, context->gpr[i], context->gpr[i], i + 16,
                 context->gpr[i + 16], context->gpr[i + 16]);
    }

    OSReport("LR   = 0x%08x                   CR   = 0x%08x\n", context->lr, context->cr);
    OSReport("SRR0 = 0x%08x                   SRR1 = 0x%08x\n", context->srr0, context->srr1);

    OSReport("\nGQRs----------\n");
    for (i = 0; i < 4; ++i) {
        OSReport("gqr%d = 0x%08x \t gqr%d = 0x%08x\n", i, context->gqr[i], i + 4, context->gqr[i + 4]);
    }

    if (context->state & OS_CONTEXT_STATE_FPSAVED) {
        OSContext* currentContext;
        OSContext fpucontext;
        BOOL enabled;

        enabled = OSDisableInterrupts();
        currentContext = OSGetCurrentContext();
        OSClearContext(&fpucontext);
        OSSetCurrentContext(&fpucontext);

        OSReport("\n\nFPRs----------\n");
        for (i = 0; i < 32; i += 2) {
            OSReport("fr%d \t= %d \t fr%d \t= %d\n", i, (u32)context->fpr[i], i + 1, (u32)context->fpr[i + 1]);
        }
        OSReport("\n\nPSFs----------\n");
        for (i = 0; i < 32; i += 2) {
            OSReport("ps%d \t= 0x%x \t ps%d \t= 0x%x\n", i, (u32)context->psf[i], i + 1, (u32)context->psf[i + 1]);
        }

        OSClearContext(&fpucontext);
        OSSetCurrentContext(currentContext);
        OSRestoreInterrupts(enabled);
    }

    OSReport("\nAddress:      Back Chain    LR Save\n");
    for (i = 0, p = (u32*)context->gpr[1]; p && (u32)p != 0xffffffff && i++ < 16; p = (u32*)*p) {
        OSReport("0x%08x:   0x%08x    0x%08x\n", p, p[0], p[1]);
    }
}

static asm void OSSwitchFPUContext(register __OSException exception, register OSContext* context) {
    nofralloc
    mfmsr r5
    ori r5, r5, 0x2000
    mtmsr r5
    isync
    lwz r5, OS_CONTEXT_SRR1(context)
    ori r5, r5, 0x2000
    mtsrr1 r5
    addis r3, r0, 0x8000
    lwz r5, 0x00D8(r3)
    stw context, 0x00D8(r3)
    cmpw r5, r4
    beq L_restoreAndExit
    cmpwi r5, 0x0
    beq L_loadNewFPUContext
    bl __OSSaveFPUContext
L_loadNewFPUContext:
    bl __OSLoadFPUContext
L_restoreAndExit:
    lwz r3, OS_CONTEXT_CR(context)
    mtcr r3
    lwz r3, OS_CONTEXT_LR(context)
    mtlr r3
    lwz r3, OS_CONTEXT_SRR0(context)
    mtsrr0 r3
    lwz r3, OS_CONTEXT_CTR(context)
    mtctr r3
    lwz r3, OS_CONTEXT_XER(context)
    mtxer r3
    lhz r3, context->state
    rlwinm r3, r3, 0, 31, 29
    sth r3, context->state
    lwz r5, OS_CONTEXT_R5(context)
    lwz r3, OS_CONTEXT_R3(context)
    lwz r4, OS_CONTEXT_R4(context)
    rfi
}

void __OSContextInit(void) {
    __OSSetExceptionHandler(__OS_EXCEPTION_FLOATING_POINT, OSSwitchFPUContext);
    __OSFPUContext = NULL;
    DBPrintf("FPU-unavailable handler installed\n");
}

asm void OSFillFPUContext(register OSContext* context) {
    nofralloc
    mfmsr r5
    ori r5, r5, 0x2000
    mtmsr r5
    isync

    stfd fp0, context->fpr[0]
    stfd fp1, context->fpr[1]
    stfd fp2, context->fpr[2]
    stfd fp3, context->fpr[3]
    stfd fp4, context->fpr[4]
    stfd fp5, context->fpr[5]
    stfd fp6, context->fpr[6]
    stfd fp7, context->fpr[7]
    stfd fp8, context->fpr[8]
    stfd fp9, context->fpr[9]
    stfd fp10, context->fpr[10]
    stfd fp11, context->fpr[11]
    stfd fp12, context->fpr[12]
    stfd fp13, context->fpr[13]
    stfd fp14, context->fpr[14]
    stfd fp15, context->fpr[15]
    stfd fp16, context->fpr[16]
    stfd fp17, context->fpr[17]
    stfd fp18, context->fpr[18]
    stfd fp19, context->fpr[19]
    stfd fp20, context->fpr[20]
    stfd fp21, context->fpr[21]
    stfd fp22, context->fpr[22]
    stfd fp23, context->fpr[23]
    stfd fp24, context->fpr[24]
    stfd fp25, context->fpr[25]
    stfd fp26, context->fpr[26]
    stfd fp27, context->fpr[27]
    stfd fp28, context->fpr[28]
    stfd fp29, context->fpr[29]
    stfd fp30, context->fpr[30]
    stfd fp31, context->fpr[31]

    mffs fp0
    stfd fp0, OS_CONTEXT_FPSCR(context)

    lfd fp0, context->fpr[0]

    mfspr r5, 920
    rlwinm. r5, r5, 3, 31, 31
    bc 12, 2, L_return3

    psq_st fp0, OS_CONTEXT_PSF0(context), 0, 0
    psq_st fp1, OS_CONTEXT_PSF1(context), 0, 0
    psq_st fp2, OS_CONTEXT_PSF2(context), 0, 0
    psq_st fp3, OS_CONTEXT_PSF3(context), 0, 0
    psq_st fp4, OS_CONTEXT_PSF4(context), 0, 0
    psq_st fp5, OS_CONTEXT_PSF5(context), 0, 0
    psq_st fp6, OS_CONTEXT_PSF6(context), 0, 0
    psq_st fp7, OS_CONTEXT_PSF7(context), 0, 0
    psq_st fp8, OS_CONTEXT_PSF8(context), 0, 0
    psq_st fp9, OS_CONTEXT_PSF9(context), 0, 0
    psq_st fp10, OS_CONTEXT_PSF10(context), 0, 0
    psq_st fp11, OS_CONTEXT_PSF11(context), 0, 0
    psq_st fp12, OS_CONTEXT_PSF12(context), 0, 0
    psq_st fp13, OS_CONTEXT_PSF13(context), 0, 0
    psq_st fp14, OS_CONTEXT_PSF14(context), 0, 0
    psq_st fp15, OS_CONTEXT_PSF15(context), 0, 0
    psq_st fp16, OS_CONTEXT_PSF16(context), 0, 0
    psq_st fp17, OS_CONTEXT_PSF17(context), 0, 0
    psq_st fp18, OS_CONTEXT_PSF18(context), 0, 0
    psq_st fp19, OS_CONTEXT_PSF19(context), 0, 0
    psq_st fp20, OS_CONTEXT_PSF20(context), 0, 0
    psq_st fp21, OS_CONTEXT_PSF21(context), 0, 0
    psq_st fp22, OS_CONTEXT_PSF22(context), 0, 0
    psq_st fp23, OS_CONTEXT_PSF23(context), 0, 0
    psq_st fp24, OS_CONTEXT_PSF24(context), 0, 0
    psq_st fp25, OS_CONTEXT_PSF25(context), 0, 0
    psq_st fp26, OS_CONTEXT_PSF26(context), 0, 0
    psq_st fp27, OS_CONTEXT_PSF27(context), 0, 0
    psq_st fp28, OS_CONTEXT_PSF28(context), 0, 0
    psq_st fp29, OS_CONTEXT_PSF29(context), 0, 0
    psq_st fp30, OS_CONTEXT_PSF30(context), 0, 0
    psq_st fp31, OS_CONTEXT_PSF31(context), 0, 0

L_return3:
    blr
}

OSErrorHandler __OSErrorTable[__OS_ERROR_MAX];

#define FPSCR_VE 0x00000080
#define FPSCR_OE 0x00000040
#define FPSCR_UE 0x00000020
#define FPSCR_ZE 0x00000010
#define FPSCR_XE 0x00000008
#define FPSCR_ENABLE (FPSCR_VE | FPSCR_OE | FPSCR_UE | FPSCR_ZE | FPSCR_XE)
#define FPSCR_NI 0x00000004
#define FPSCR_VXVC 0x00080000
#define FPSCR_VXIMZ 0x00100000
#define FPSCR_VXZDZ 0x00200000
#define FPSCR_VXIDI 0x00400000
#define FPSCR_VXISI 0x00800000
#define FPSCR_VXSNAN 0x01000000
#define FPSCR_VXSOFT 0x00000400
#define FPSCR_VXSQRT 0x00000200
#define FPSCR_VXCVI 0x00000100
#define FPSCR_XX 0x02000000
#define FPSCR_ZX 0x04000000
#define FPSCR_UX 0x08000000
#define FPSCR_OX 0x10000000
#define FPSCR_FX 0x80000000
#define FPSCR_FI 0x00020000

#define MSR_FP 0x00002000
#define MSR_FE0 0x00000800
#define MSR_FE1 0x00000100
#define MSR_RI 0x00000002

#define __OS_EXCEPTION_FLOATING_POINT_EXCEPTION 16

u32 lbl_805DC988 = FPSCR_ENABLE;

void OSReport(const char* msg, ...) {
    va_list marker;
    va_start(marker, msg);
    vprintf(msg, marker);
    va_end(marker);
}

void OSPanic(const char* file, int line, const char* msg, ...) {
    va_list marker;
    u32 i;
    u32* p;

    OSDisableInterrupts();
    va_start(marker, msg);
    vprintf(msg, marker);
    va_end(marker);
    OSReport(" in \"%s\" on line %d.\n", file, line);

    OSReport("\nAddress:      Back Chain    LR Save\n");
    for (i = 0, p = (u32*)OSGetStackPointer(); p && (u32)p != 0xffffffff && i++ < 16; p = (u32*)*p) {
        OSReport("0x%08x:   0x%08x    0x%08x\n", p, p[0], p[1]);
    }

    PPCHalt();
}

OSErrorHandler OSSetErrorHandler(OSError error, OSErrorHandler handler) {
    OSErrorHandler oldHandler;
    int enabled;
    u32 msr;
    u32 fpscr;
    OSThread* thread;
    int i;

    enabled = OSDisableInterrupts();
    oldHandler = __OSErrorTable[error];
    __OSErrorTable[error] = handler;

    if (error == __OS_EXCEPTION_FLOATING_POINT_EXCEPTION) {
        msr = PPCMfmsr();
        PPCMtmsr(msr | MSR_FP);
        fpscr = PPCMffpscr();

        if (handler) {
            for (thread = __OSActiveThreadQueue.head; thread; thread = thread->linkActive.next) {
                thread->context.srr1 |= MSR_FE0 | MSR_FE1;
                if ((thread->context.state & OS_CONTEXT_STATE_FPSAVED) == 0) {
                    thread->context.state |= OS_CONTEXT_STATE_FPSAVED;
                    for (i = 0; i < 32; ++i) {
                        *(u64*)&thread->context.fpr[i] = (u64)0xffffffffffffffffLL;
                        *(u64*)&thread->context.psf[i] = (u64)0xffffffffffffffffLL;
                    }
                    thread->context.fpscr = FPSCR_NI;
                }
                thread->context.fpscr |= lbl_805DC988 & FPSCR_ENABLE;
                thread->context.fpscr &= ~(FPSCR_VXVC | FPSCR_VXIMZ | FPSCR_VXZDZ | FPSCR_VXIDI | FPSCR_VXISI |
                                            FPSCR_VXSNAN | FPSCR_VXSOFT | FPSCR_VXSQRT | FPSCR_VXCVI | FPSCR_XX |
                                            FPSCR_ZX | FPSCR_UX | FPSCR_OX | FPSCR_FX | FPSCR_FI);
            }
            fpscr |= lbl_805DC988 & FPSCR_ENABLE;
            msr |= MSR_FE0 | MSR_FE1;
        } else {
            for (thread = __OSActiveThreadQueue.head; thread; thread = thread->linkActive.next) {
                thread->context.srr1 &= ~(MSR_FE0 | MSR_FE1);
                thread->context.fpscr &= ~FPSCR_ENABLE;
                thread->context.fpscr &= ~(FPSCR_VXVC | FPSCR_VXIMZ | FPSCR_VXZDZ | FPSCR_VXIDI | FPSCR_VXISI |
                                            FPSCR_VXSNAN | FPSCR_VXSOFT | FPSCR_VXSQRT | FPSCR_VXCVI | FPSCR_XX |
                                            FPSCR_ZX | FPSCR_UX | FPSCR_OX | FPSCR_FX | FPSCR_FI);
            }
            fpscr &= ~FPSCR_ENABLE;
            msr &= ~(MSR_FE0 | MSR_FE1);
        }

        fpscr &= ~(FPSCR_VXVC | FPSCR_VXIMZ | FPSCR_VXZDZ | FPSCR_VXIDI | FPSCR_VXISI | FPSCR_VXSNAN | FPSCR_VXSOFT |
                   FPSCR_VXSQRT | FPSCR_VXCVI | FPSCR_XX | FPSCR_ZX | FPSCR_UX | FPSCR_OX | FPSCR_FX | FPSCR_FI);

        PPCMtfpscr(fpscr);
        PPCMtmsr(msr);
    }

    OSRestoreInterrupts(enabled);
    return oldHandler;
}

void __OSUnhandledException(__OSException exception, OSContext* context, u32 dsisr, u32 dar) {
    OSTime now;
    u32 fpscr;
    u32 msr;

    now = OSGetTime();

    if (!(context->srr1 & MSR_RI)) {
        OSReport("Non-recoverable Exception %d", exception);
    } else {
        if (exception == __OS_EXCEPTION_PROGRAM && (context->srr1 & (0x80000000 >> 11)) &&
            __OSErrorTable[__OS_EXCEPTION_FLOATING_POINT_EXCEPTION] != 0) {
            exception = __OS_EXCEPTION_FLOATING_POINT_EXCEPTION;

            msr = PPCMfmsr();
            PPCMtmsr(msr | 0x2000);

            if (__OSFPUContext) {
                OSSaveFPUContext((OSContext*)__OSFPUContext);
            }

            fpscr = PPCMffpscr();
            fpscr &= ~(FPSCR_VXVC | FPSCR_VXIMZ | FPSCR_VXZDZ | FPSCR_VXIDI | FPSCR_VXISI | FPSCR_VXSNAN |
                       FPSCR_VXSOFT | FPSCR_VXSQRT | FPSCR_VXCVI | FPSCR_XX | FPSCR_ZX | FPSCR_UX | FPSCR_OX |
                       FPSCR_FX | FPSCR_FI);
            PPCMtfpscr(fpscr);

            PPCMtmsr(msr);

            if (__OSFPUContext == context) {
                OSDisableScheduler();
                __OSErrorTable[exception](exception, context, dsisr, dar);
                context->srr1 &= ~0x2000;
                __OSFPUContext = NULL;

                context->fpscr &= ~(FPSCR_VXVC | FPSCR_VXIMZ | FPSCR_VXZDZ | FPSCR_VXIDI | FPSCR_VXISI |
                                     FPSCR_VXSNAN | FPSCR_VXSOFT | FPSCR_VXSQRT | FPSCR_VXCVI | FPSCR_XX | FPSCR_ZX |
                                     FPSCR_UX | FPSCR_OX | FPSCR_FX | FPSCR_FI);
                OSEnableScheduler();
                __OSReschedule();
            } else {
                context->srr1 &= ~0x2000;
                __OSFPUContext = NULL;
            }

            OSLoadContext(context);
        }

        if (__OSErrorTable[exception]) {
            OSDisableScheduler();
            __OSErrorTable[exception](exception, context, dsisr, dar);
            OSEnableScheduler();
            __OSReschedule();
            OSLoadContext(context);
        }
        if (exception == __OS_EXCEPTION_DECREMENTER) {
            OSLoadContext(context);
        }
        OSReport("Unhandled Exception %d", exception);
    }
    OSReport("\n");
    OSDumpContext(context);
    OSReport("\nDSISR = 0x%08x                   DAR  = 0x%08x\n", dsisr, dar);
    OSReport("TB = 0x%016llx\n", now);

    switch (exception) {
    case __OS_EXCEPTION_DSI:
        OSReport("\nInstruction at 0x%x (read from SRR0) attempted to access "
                 "invalid address 0x%x (read from DAR)\n",
                 context->srr0, dar);
        break;
    case __OS_EXCEPTION_ISI:
        OSReport("\nAttempted to fetch instruction from invalid address 0x%x "
                 "(read from SRR0)\n",
                 context->srr0);
        break;
    case __OS_EXCEPTION_ALIGNMENT:
        OSReport("\nInstruction at 0x%x (read from SRR0) attempted to access "
                 "unaligned address 0x%x (read from DAR)\n",
                 context->srr0, dar);
        break;
    case __OS_EXCEPTION_PROGRAM:
        OSReport("\nProgram exception : Possible illegal instruction/operation "
                 "at or around 0x%x (read from SRR0)\n",
                 context->srr0, dar);
        break;
    case __OS_EXCEPTION_MEMORY_PROTECTION:
        OSReport("\n");
        OSReport("AI DMA Address =   0x%04x%04x\n", __DSPRegs[DSP_DMA_START_HI], __DSPRegs[DSP_DMA_START_LO]);
        OSReport("ARAM DMA Address = 0x%04x%04x\n", __DSPRegs[DSP_ARAM_DMA_MM_HI], __DSPRegs[DSP_ARAM_DMA_MM_LO]);
        OSReport("DI DMA Address =   0x%08x\n", __DIRegs[5]);
        break;
    }

    OSReport("\nLast interrupt (%d): SRR0 = 0x%08x  TB = 0x%016llx\n", __OSLastInterrupt, __OSLastInterruptSrr0,
             __OSLastInterruptTime);
    PPCHalt();
}

typedef char* (*ParseStringCallback)(u16, char*, OSFontHeader**, int*);

static OSFontHeader* FontDataAnsi;
static OSFontHeader* FontDataSjis;
static int FixedPitch;
static ParseStringCallback ParseString;
static u16 FontEncode = 0xFFFF;

extern void DCStoreRange(register void* addr, register u32 nBytes);

void fn_803D5394(int fontImg, u32 cellHeight, u32 cellWidth, u8* colorIndex, u32 col, int y, int stride,
                  u8* string) {
}

void fn_803D5770(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u16 fbb, u32 j, u32 k, u32 l, u32 m, u32 n,
                  u32 o, u32 p) {
}

void fn_803D586C(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32* i, u32* j, u32 k, u32 l, u32 m, u32 n,
                  u32 o, u32 p) {
}

void fn_803D59C0(void) {
}

static u16 HankakuToCode[]
    = { 0x20C, 0x20D, 0x20E, 0x20F, 0x210, 0x211, 0x212, 0x213,
        0x214, 0x215, 0x216, 0x217, 0x218, 0x219, 0x21A, 0x21B,
        0x21C, 0x21D, 0x21E, 0x21F, 0x220, 0x221, 0x222, 0x223,
        0x224, 0x225, 0x226, 0x227, 0x228, 0x229, 0x22A, 0x22B,
        0x22C, 0x22D, 0x22E, 0x22F, 0x230, 0x231, 0x232, 0x233,
        0x234, 0x235, 0x236, 0x237, 0x238, 0x239, 0x23A, 0x23B,
        0x23C, 0x23D, 0x23E, 0x23F, 0x240, 0x241, 0x242, 0x243,
        0x244, 0x245, 0x246, 0x247, 0x248, 0x249, 0x24A, 0x24B,
        0x24C, 0x24D, 0x24E, 0x24F, 0x250, 0x251, 0x252, 0x253,
        0x254, 0x255, 0x256, 0x257, 0x258, 0x259, 0x25A, 0x25B,
        0x25C, 0x25D, 0x25E, 0x25F, 0x260, 0x261, 0x262, 0x263,
        0x264, 0x265, 0x266, 0x267, 0x268, 0x269, 0x26A, 0x20C,
        0x20C, 0x20C, 0x20C, 0x20C, 0x20C, 0x20C, 0x20C, 0x20C,
        0x20C, 0x20C, 0x20C, 0x20C, 0x20C, 0x20C, 0x20C, 0x20C,
        0x20C, 0x20C, 0x20C, 0x20C, 0x20C, 0x20C, 0x20C, 0x20C,
        0x20C, 0x20C, 0x20C, 0x20C, 0x20C, 0x20C, 0x20C, 0x20C,
        0x20C, 0x26B, 0x26C, 0x26D, 0x26E, 0x26F, 0x270, 0x271,
        0x272, 0x273, 0x274, 0x275, 0x276, 0x277, 0x278, 0x279,
        0x27A, 0x27B, 0x27C, 0x27D, 0x27E, 0x27F, 0x280, 0x281,
        0x282, 0x283, 0x284, 0x285, 0x286, 0x287, 0x288, 0x289,
        0x28A, 0x28B, 0x28C, 0x28D, 0x28E, 0x28F, 0x290, 0x291,
        0x292, 0x293, 0x294, 0x295, 0x296, 0x297, 0x298, 0x299,
        0x29A, 0x29B, 0x29C, 0x29D, 0x29E, 0x29F, 0x2A0, 0x2A1,
        0x2A2, 0x2A3, 0x2A4, 0x2A5, 0x2A6, 0x2A7, 0x2A8, 0x2A9 };

static BOOL IsSjisTrailByte(u8 c) {
    return (0x40 <= c && c <= 0xFC) && (c != 0x7F);
}

static int fn_803D6044(u16 code) {
    if (code >= 0x20 && code <= 0xDF) {
        return HankakuToCode[code - 0x20];
    }

    if (code > 0x889E && code <= 0x9872) {
        int i = ((code >> 8) - 0x88) * 188;
        int j = (code & 0xFF);

        if (!IsSjisTrailByte(j)) {
            return 0;
        }

        j -= 0x40;
        if (j >= 0x40) {
            j--;
        }

        return (i + j + 0x2BE);
    }

    return 0;
}

static void fn_803D61E0(u8* s, u8* d) {
    int i;
    int j;
    int k;
    int p;
    int q;
    int r7;
    int r25;
    int cnt;
    int os;
    unsigned int flag;
    unsigned int code;

    os = *(int*)(s + 0x4);
    r7 = *(int*)(s + 0x8);
    r25 = *(int*)(s + 0xC);

    q = 0;
    flag = 0;
    p = 16;

    do {
        if (flag == 0) {
            code = *(u32*)(s + p);
            p += sizeof(u32);
            flag = sizeof(u32) * 8;
        }

        if (code & 0x80000000) {
            d[q++] = s[r25++];
        } else {
            j = s[r7] << 8 | s[r7 + 1];
            r7 += sizeof(u16);

            k = q - (j & 0x0FFF);
            cnt = j >> 12;
            if (cnt == 0) {
                cnt = s[r25++] + 0x12;
            } else {
                cnt += 2;
            }

            for (i = 0; i < cnt; i++, q++, k++) {
                d[q] = d[k - 1];
            }
        }

        code <<= 1;
        flag--;
    } while (q < os);
}

char* fn_803D676C(const char* string, void* image, s32 pos, s32 stride, s32* width) {
    u16 encode;
    OSFontHeader* font;
    u8* src;
    u8* dst;
    int fontCode;
    int sheet;
    int numChars;
    int row;
    int column;
    int x;
    int y;
    int offsetSrc;
    int offsetDst;
    u8* colorIndex;
    u8* imageSrc;

    encode = OSGetFontEncode();
    string = ParseString(encode, (char*)string, &font, &fontCode);
    colorIndex = &font->c0;

    sheet = fontCode / (font->sheetColumn * font->sheetRow);
    numChars = fontCode - (sheet * (font->sheetColumn * font->sheetRow));
    row = numChars / font->sheetColumn;
    column = numChars - (row * font->sheetColumn);
    row *= font->cellHeight;
    column *= font->cellWidth;

    imageSrc = (u8*)font + font->sheetImage;
    imageSrc += ((sheet * font->sheetSize) >> 1);

    for (y = 0; y < font->cellHeight; y++) {
        for (x = 0; x < font->cellWidth; x++) {
            src = imageSrc + (((font->sheetWidth / 8) * 32) / 2) * ((row + y) / 8);
            src += ((column + x) / 8) * 16;
            src += ((row + y) % 8) * 2;
            src += ((column + x) % 8) / 4;

            offsetSrc = (column + x) % 4;

            dst = (u8*)image + ((y / 8) * (((stride * 4) / 8) * 32));
            dst += (((pos + x) / 8) * 32);
            dst += ((y % 8) * 4);
            dst += ((pos + x) % 8) / 2;

            offsetDst = (pos + x) % 2;

            *dst |= colorIndex[*src >> (6 - (offsetSrc * 2)) & 3] & ((offsetDst != 0) ? 0x0F : 0xF0);
        }
    }

    if (width != 0) {
        *width = ((u8*)font + font->widthTable)[fontCode];
    }

    return (char*)string;
}

static void fn_803D6A70(OSFontHeader* font, u8* src, u8* dst) {
    int i;
    u8* colorIndex = &font->c0;

    if (font->sheetFormat == 0 /* GX_TF_I4 */) {
        for (i = (s32)(font->sheetFullSize) / 2 - 1; i >= 0; i--) {
            dst[i * 2 + 0] = colorIndex[src[i] >> 6 & 3] & 0xF0 | colorIndex[src[i] >> 4 & 3] & 0x0F;
            dst[i * 2 + 1] = colorIndex[src[i] >> 2 & 3] & 0xF0 | colorIndex[src[i] >> 0 & 3] & 0x0F;
        }
    } else if (font->sheetFormat == 2 /* GX_TF_IA4 */) {
        for (i = (s32)(font->sheetFullSize) / 4 - 1; i >= 0; i--) {
            dst[i * 4 + 0] = colorIndex[src[i] >> 6 & 3];
            dst[i * 4 + 1] = colorIndex[src[i] >> 4 & 3];
            dst[i * 4 + 2] = colorIndex[src[i] >> 2 & 3];
            dst[i * 4 + 3] = colorIndex[src[i] >> 0 & 3];
        }
    }

    DCStoreRange(dst, font->sheetFullSize);
}

static u32 GetFontSize(u8* buf) {
    if (buf[0] == 'Y' && buf[1] == 'a' && buf[2] == 'y') {
        return *(u32*)(buf + 0x4);
    }

    return 0;
}

static void fn_803D63AC(void* buf, int length, int offset) {
    int len;
    while (length > 0) {
        len = (length <= 0x100) ? length : 0x100;
        length -= len;

        while (!__OSReadROM(buf, len, offset))
            ;

        offset += len;
        (u8*)buf += len;
    }
}

static u32 ReadFont(void* img, u16 encode, void* fontData) {
    u32 size;

    if (encode == OS_FONT_ENCODE_SJIS) {
        fn_803D63AC(img, OS_FONT_ROM_SIZE_SJIS, 0x1AFF00);
    } else {
        fn_803D63AC(img, OS_FONT_ROM_SIZE_ANSI, 0x1FCF00);
    }

    size = GetFontSize(img);
    if (size == 0) {
        return 0;
    }

    fn_803D61E0(img, fontData);
    return size;
}

u16 OSGetFontEncode(void) {
    if (FontEncode != 0xFFFF) {
        return FontEncode;
    }

    FontEncode = OS_FONT_ENCODE_ANSI;

    return FontEncode;
}

u32 OSLoadFont(OSFontHeader* fontData, void* tmp) {
    u16 encode;
    u32 size;

    encode = OSGetFontEncode();
    switch (encode) {
    case 0:
        FontDataAnsi = fontData;
        size = ReadFont(tmp, 0, FontDataAnsi);
        break;
    case 1:
        FontDataSjis = fontData;
        size = ReadFont(tmp, 1, FontDataSjis);
        break;
    default:
        size = 0;
        break;
    }

    return size;
}

int OSInitFont(OSFontHeader* fontData) {
    u16 encode;
    u32 size;
    void* tmp;
    u8* img;

    encode = OSGetFontEncode();
    switch (encode) {
    case 0:
        tmp = (void*)((u8*)fontData + 0x1D120);
        FontDataAnsi = fontData;
        size = ReadFont(tmp, 0, FontDataAnsi);
        if (size == 0) {
            return 0;
        }

        img = (u8*)FontDataAnsi + FontDataAnsi->sheetImage;
        FontDataAnsi->sheetImage = (((u32)FontDataAnsi->sheetImage) + 32 - 1) & ~(32 - 1);
        fn_803D6A70(FontDataAnsi, img, (u8*)FontDataAnsi + FontDataAnsi->sheetImage);
        break;
    case 1:
        tmp = (void*)((u8*)fontData + 0xD3F00);
        FontDataSjis = fontData;
        size = ReadFont(tmp, 1, FontDataSjis);
        if (size == 0) {
            return 0;
        }

        img = (u8*)FontDataSjis + FontDataSjis->sheetImage;
        FontDataSjis->sheetImage = (((u32)FontDataSjis->sheetImage) + 32 - 1) & ~(32 - 1);
        fn_803D6A70(FontDataSjis, img, (u8*)FontDataSjis + FontDataSjis->sheetImage);
        break;
    default:
        break;
    }

    return 1;
}

char* OSGetFontTexture(const char* string, void** image, s32* x, s32* y, s32* width) {
    OSFontHeader* font;
    u16 encode;
    int fontCode;
    int sheet;
    int numChars;
    int row;
    int column;

    encode = OSGetFontEncode();
    string = ParseString(encode, (char*)string, &font, &fontCode);
    sheet = fontCode / (font->sheetColumn * font->sheetRow);
    ((u32*)image)[0] = (u32)font + font->sheetImage + (font->sheetSize * sheet);
    numChars = fontCode - (sheet * (font->sheetColumn * font->sheetRow));
    row = numChars / font->sheetColumn;
    column = numChars - (row * font->sheetColumn);
    *x = column * font->cellWidth;
    *y = row * font->cellHeight;

    if (width != 0) {
        *width = ((u8*)font + font->widthTable)[fontCode];
    }
    return (char*)string;
}

static __OSInterruptHandler* InterruptHandlerTable;

#define OS_GLOBAL_MASK (*(OSInterruptMask*)0x800000C4)
#define OS_LOCAL_MASK (*(OSInterruptMask*)0x800000C8)
#define __PIRegs ((volatile u32*)0xCC003000)
#define __MEMRegs ((volatile u16*)0xCC004000)
#define __EXIRegs ((volatile u32*)0xCC006800)
#define __AIRegs ((volatile u32*)0xCC006C00)

extern OSInterruptMask __OSMaskInterrupts(OSInterruptMask global);
extern OSInterruptMask __OSUnmaskInterrupts(OSInterruptMask global);
OSInterruptMask SetInterruptMask(OSInterruptMask mask, OSInterruptMask current);

static OSInterruptMask InterruptPrioTable[] = {
    OS_INTERRUPTMASK_PI_ERROR,
    OS_INTERRUPTMASK_PI_DEBUG,
    OS_INTERRUPTMASK_MEM,
    OS_INTERRUPTMASK_PI_RSW,
    OS_INTERRUPTMASK_PI_VI,
    OS_INTERRUPTMASK_PI_PE,
    OS_INTERRUPTMASK_PI_HSP,
    OS_INTERRUPTMASK_DSP_ARAM | OS_INTERRUPTMASK_DSP_DSP | OS_INTERRUPTMASK_AI | OS_INTERRUPTMASK_EXI |
        OS_INTERRUPTMASK_PI_SI | OS_INTERRUPTMASK_PI_DI,
    OS_INTERRUPTMASK_DSP_AI,
    OS_INTERRUPTMASK_PI_CP,
    0xFFFFFFFF,
};

asm BOOL OSDisableInterrupts(void) {
    nofralloc
    mfmsr r3
    rlwinm r4, r3, 0, 17, 15
    mtmsr r4
    rlwinm r3, r3, 17, 31, 31
    blr
}

asm BOOL OSEnableInterrupts(void) {
    nofralloc
    mfmsr r3
    ori r4, r3, 0x8000
    mtmsr r4
    rlwinm r3, r3, 17, 31, 31
    blr
}

asm BOOL OSRestoreInterrupts(register BOOL level) {
    nofralloc
    cmpwi level, 0
    mfmsr r4
    beq L_disable
    ori r5, r4, 0x8000
    b L_restore
L_disable:
    rlwinm r5, r4, 0, 17, 15
L_restore:
    mtmsr r5
    rlwinm r3, r4, 17, 31, 31
    blr
}

#pragma dont_inline on
__OSInterruptHandler __OSSetInterruptHandler(__OSInterrupt interrupt, __OSInterruptHandler handler) {
    __OSInterruptHandler oldHandler;

    oldHandler = InterruptHandlerTable[interrupt];
    InterruptHandlerTable[interrupt] = handler;
    return oldHandler;
}

__OSInterruptHandler __OSGetInterruptHandler(__OSInterrupt interrupt) {
    return InterruptHandlerTable[interrupt];
}
#pragma dont_inline off

static void ExternalInterruptHandler(register __OSException exception, register OSContext* context);

void __OSInterruptInit(void) {
    InterruptHandlerTable = (void*)OSPhysicalToCached(0x3040);

    memset(InterruptHandlerTable, 0, __OS_INTERRUPT_MAX * sizeof(__OSInterruptHandler));

    OS_GLOBAL_MASK = 0;
    OS_LOCAL_MASK = 0;

    __PIRegs[1] = 0xf0;

    __OSMaskInterrupts(OS_INTERRUPTMASK_MEM | OS_INTERRUPTMASK_DSP | OS_INTERRUPTMASK_AI | OS_INTERRUPTMASK_EXI |
                        OS_INTERRUPTMASK_PI);

    __OSSetExceptionHandler(4, ExternalInterruptHandler);
}

OSInterruptMask SetInterruptMask(OSInterruptMask mask, OSInterruptMask current) {
    u32 reg;

    switch (__cntlzw(mask)) {
    case __OS_INTERRUPT_MEM_0:
    case __OS_INTERRUPT_MEM_1:
    case __OS_INTERRUPT_MEM_2:
    case __OS_INTERRUPT_MEM_3:
    case __OS_INTERRUPT_MEM_ADDRESS:
        reg = 0;
        if (!(current & OS_INTERRUPTMASK_MEM_0))
            reg |= 0x1;
        if (!(current & OS_INTERRUPTMASK_MEM_1))
            reg |= 0x2;
        if (!(current & OS_INTERRUPTMASK_MEM_2))
            reg |= 0x4;
        if (!(current & OS_INTERRUPTMASK_MEM_3))
            reg |= 0x8;
        if (!(current & OS_INTERRUPTMASK_MEM_ADDRESS))
            reg |= 0x10;
        __MEMRegs[0x0000000e] = (u16)reg;
        mask &= ~OS_INTERRUPTMASK_MEM;
        break;
    case __OS_INTERRUPT_DSP_AI:
    case __OS_INTERRUPT_DSP_ARAM:
    case __OS_INTERRUPT_DSP_DSP:
        reg = __DSPRegs[0x00000005];
        reg &= ~0x1F8;
        if (!(current & OS_INTERRUPTMASK_DSP_AI))
            reg |= 0x10;
        if (!(current & OS_INTERRUPTMASK_DSP_ARAM))
            reg |= 0x40;
        if (!(current & OS_INTERRUPTMASK_DSP_DSP))
            reg |= 0x100;
        __DSPRegs[0x00000005] = (u16)reg;
        mask &= ~OS_INTERRUPTMASK_DSP;
        break;
    case __OS_INTERRUPT_AI_AI:
        reg = __AIRegs[0];
        reg &= ~0x2C;
        if (!(current & OS_INTERRUPTMASK_AI_AI))
            reg |= 0x4;
        __AIRegs[0] = reg;
        mask &= ~OS_INTERRUPTMASK_AI;
        break;
    case __OS_INTERRUPT_EXI_0_EXI:
    case __OS_INTERRUPT_EXI_0_TC:
    case __OS_INTERRUPT_EXI_0_EXT:
        reg = __EXIRegs[0];
        reg &= ~0x2C0F;
        if (!(current & OS_INTERRUPTMASK_EXI_0_EXI))
            reg |= 0x1;
        if (!(current & OS_INTERRUPTMASK_EXI_0_TC))
            reg |= 0x4;
        if (!(current & OS_INTERRUPTMASK_EXI_0_EXT))
            reg |= 0x400;
        __EXIRegs[0] = reg;
        mask &= ~OS_INTERRUPTMASK_EXI_0;
        break;
    case __OS_INTERRUPT_EXI_1_EXI:
    case __OS_INTERRUPT_EXI_1_TC:
    case __OS_INTERRUPT_EXI_1_EXT:
        reg = __EXIRegs[5];
        reg &= ~0xC0F;

        if (!(current & OS_INTERRUPTMASK_EXI_1_EXI))
            reg |= 0x1;
        if (!(current & OS_INTERRUPTMASK_EXI_1_TC))
            reg |= 0x4;
        if (!(current & OS_INTERRUPTMASK_EXI_1_EXT))
            reg |= 0x400;
        __EXIRegs[5] = reg;
        mask &= ~OS_INTERRUPTMASK_EXI_1;
        break;
    case __OS_INTERRUPT_EXI_2_EXI:
    case __OS_INTERRUPT_EXI_2_TC:
        reg = __EXIRegs[10];
        reg &= ~0xF;
        if (!(current & OS_INTERRUPTMASK_EXI_2_EXI))
            reg |= 0x1;
        if (!(current & OS_INTERRUPTMASK_EXI_2_TC))
            reg |= 0x4;

        __EXIRegs[10] = reg;
        mask &= ~OS_INTERRUPTMASK_EXI_2;
        break;
    case __OS_INTERRUPT_PI_CP:
    case __OS_INTERRUPT_PI_SI:
    case __OS_INTERRUPT_PI_DI:
    case __OS_INTERRUPT_PI_RSW:
    case __OS_INTERRUPT_PI_ERROR:
    case __OS_INTERRUPT_PI_VI:
    case __OS_INTERRUPT_PI_DEBUG:
    case __OS_INTERRUPT_PI_PE_TOKEN:
    case __OS_INTERRUPT_PI_PE_FINISH:
    case __OS_INTERRUPT_PI_HSP:
        reg = 0xF0;

        if (!(current & OS_INTERRUPTMASK_PI_CP)) {
            reg |= 0x800;
        }
        if (!(current & OS_INTERRUPTMASK_PI_SI)) {
            reg |= 0x8;
        }
        if (!(current & OS_INTERRUPTMASK_PI_DI)) {
            reg |= 0x4;
        }
        if (!(current & OS_INTERRUPTMASK_PI_RSW)) {
            reg |= 0x2;
        }
        if (!(current & OS_INTERRUPTMASK_PI_ERROR)) {
            reg |= 0x1;
        }
        if (!(current & OS_INTERRUPTMASK_PI_VI)) {
            reg |= 0x100;
        }
        if (!(current & OS_INTERRUPTMASK_PI_DEBUG)) {
            reg |= 0x1000;
        }
        if (!(current & OS_INTERRUPTMASK_PI_PE_TOKEN)) {
            reg |= 0x200;
        }
        if (!(current & OS_INTERRUPTMASK_PI_PE_FINISH)) {
            reg |= 0x400;
        }
        if (!(current & OS_INTERRUPTMASK_PI_HSP)) {
            reg |= 0x2000;
        }
        __PIRegs[1] = reg;
        mask &= ~OS_INTERRUPTMASK_PI;
        break;
    default:
        break;
    }
    return mask;
}

#pragma dont_inline on
OSInterruptMask __OSMaskInterrupts(OSInterruptMask global) {
    BOOL enabled;
    OSInterruptMask prev;
    OSInterruptMask local;
    OSInterruptMask mask;

    enabled = OSDisableInterrupts();
    prev = OS_GLOBAL_MASK;
    local = OS_LOCAL_MASK;
    mask = ~(prev | local) & global;
    global |= prev;
    OS_GLOBAL_MASK = global;
    while (mask) {
        mask = SetInterruptMask(mask, global | local);
    }
    OSRestoreInterrupts(enabled);
    return prev;
}

OSInterruptMask __OSUnmaskInterrupts(OSInterruptMask global) {
    BOOL enabled;
    OSInterruptMask prev;
    OSInterruptMask local;
    OSInterruptMask mask;

    enabled = OSDisableInterrupts();
    prev = OS_GLOBAL_MASK;
    local = OS_LOCAL_MASK;
    mask = (prev | local) & global;
    global = prev & ~global;
    OS_GLOBAL_MASK = global;
    while (mask) {
        mask = SetInterruptMask(mask, global | local);
    }
    OSRestoreInterrupts(enabled);
    return prev;
}
#pragma dont_inline off

void __OSDispatchInterrupt(__OSException exception, OSContext* context) {
    u32 intsr;
    u32 reg;
    OSInterruptMask cause;
    OSInterruptMask unmasked;
    OSInterruptMask* prio;
    __OSInterrupt interrupt;
    __OSInterruptHandler handler;

    intsr = __PIRegs[0];
    intsr &= ~0x00010000;

    if (intsr == 0 || (intsr & __PIRegs[1]) == 0) {
        OSLoadContext(context);
    }

    cause = 0;

    if (intsr & 0x00000080) {
        reg = __MEMRegs[15];
        if (reg & 0x1)
            cause |= OS_INTERRUPTMASK_MEM_0;
        if (reg & 0x2)
            cause |= OS_INTERRUPTMASK_MEM_1;
        if (reg & 0x4)
            cause |= OS_INTERRUPTMASK_MEM_2;
        if (reg & 0x8)
            cause |= OS_INTERRUPTMASK_MEM_3;
        if (reg & 0x10)
            cause |= OS_INTERRUPTMASK_MEM_ADDRESS;
    }

    if (intsr & 0x00000040) {
        reg = __DSPRegs[5];
        if (reg & 0x8)
            cause |= OS_INTERRUPTMASK_DSP_AI;
        if (reg & 0x20)
            cause |= OS_INTERRUPTMASK_DSP_ARAM;
        if (reg & 0x80)
            cause |= OS_INTERRUPTMASK_DSP_DSP;
    }

    if (intsr & 0x00000020) {
        reg = __AIRegs[0];
        if (reg & 0x8)
            cause |= OS_INTERRUPTMASK_AI_AI;
    }

    if (intsr & 0x00000010) {
        reg = __EXIRegs[0];
        if (reg & 0x2)
            cause |= OS_INTERRUPTMASK_EXI_0_EXI;
        if (reg & 0x8)
            cause |= OS_INTERRUPTMASK_EXI_0_TC;
        if (reg & 0x800)
            cause |= OS_INTERRUPTMASK_EXI_0_EXT;
        reg = __EXIRegs[5];
        if (reg & 0x2)
            cause |= OS_INTERRUPTMASK_EXI_1_EXI;
        if (reg & 0x8)
            cause |= OS_INTERRUPTMASK_EXI_1_TC;
        if (reg & 0x800)
            cause |= OS_INTERRUPTMASK_EXI_1_EXT;
        reg = __EXIRegs[10];
        if (reg & 0x2)
            cause |= OS_INTERRUPTMASK_EXI_2_EXI;
        if (reg & 0x8)
            cause |= OS_INTERRUPTMASK_EXI_2_TC;
    }

    if (intsr & 0x00002000)
        cause |= OS_INTERRUPTMASK_PI_HSP;
    if (intsr & 0x00001000)
        cause |= OS_INTERRUPTMASK_PI_DEBUG;
    if (intsr & 0x00000400)
        cause |= OS_INTERRUPTMASK_PI_PE_FINISH;
    if (intsr & 0x00000200)
        cause |= OS_INTERRUPTMASK_PI_PE_TOKEN;
    if (intsr & 0x00000100)
        cause |= OS_INTERRUPTMASK_PI_VI;
    if (intsr & 0x00000008)
        cause |= OS_INTERRUPTMASK_PI_SI;
    if (intsr & 0x00000004)
        cause |= OS_INTERRUPTMASK_PI_DI;
    if (intsr & 0x00000002)
        cause |= OS_INTERRUPTMASK_PI_RSW;
    if (intsr & 0x00000800)
        cause |= OS_INTERRUPTMASK_PI_CP;
    if (intsr & 0x00000001)
        cause |= OS_INTERRUPTMASK_PI_ERROR;

    unmasked = cause & ~(OS_GLOBAL_MASK | OS_LOCAL_MASK);
    if (unmasked) {
        for (prio = InterruptPrioTable;; ++prio) {
            if (unmasked & *prio) {
                interrupt = (__OSInterrupt)__cntlzw(unmasked & *prio);
                break;
            }
        }

        handler = __OSGetInterruptHandler(interrupt);
        if (handler) {
            if (__OS_INTERRUPT_MEM_ADDRESS < interrupt) {
                __OSLastInterrupt = interrupt;
                __OSLastInterruptTime = OSGetTime();
                __OSLastInterruptSrr0 = context->srr0;
            }
            OSDisableScheduler();
            handler(interrupt, context);
            OSEnableScheduler();
            __OSReschedule();
            OSLoadContext(context);
        }
    }

    OSLoadContext(context);
}

static asm void ExternalInterruptHandler(register __OSException exception, register OSContext* context) {
    nofralloc
    stw r0, OS_CONTEXT_R0(context)
    stw r1, OS_CONTEXT_R1(context)
    stw r2, OS_CONTEXT_R2(context)
    stmw r6, OS_CONTEXT_R6(context)
    mfspr r0, GQR1
    stw r0, OS_CONTEXT_GQR1(context)
    mfspr r0, GQR2
    stw r0, OS_CONTEXT_GQR2(context)
    mfspr r0, GQR3
    stw r0, OS_CONTEXT_GQR3(context)
    mfspr r0, GQR4
    stw r0, OS_CONTEXT_GQR4(context)
    mfspr r0, GQR5
    stw r0, OS_CONTEXT_GQR5(context)
    mfspr r0, GQR6
    stw r0, OS_CONTEXT_GQR6(context)
    mfspr r0, GQR7
    stw r0, OS_CONTEXT_GQR7(context)
    stwu r1, -0x8(r1)
    b __OSDispatchInterrupt
}

void __OSModuleInit(void) {
    *(u32*)0x800030CC = 0;
    *(u32*)0x800030C8 = 0;
    *(u32*)0x800030D0 = 0;
}

void OSInitMessageQueue(OSMessageQueue* mq, void* msgArray, s32 msgCount) {
    OSInitThreadQueue(&mq->queueSend);
    OSInitThreadQueue(&mq->queueReceive);
    mq->msgArray = msgArray;
    mq->msgCount = msgCount;
    mq->firstIndex = 0;
    mq->usedCount = 0;
}

int OSSendMessage(OSMessageQueue* mq, void* msg, s32 flags) {
    BOOL enabled;
    s32 lastIndex;

    enabled = OSDisableInterrupts();
    while (mq->msgCount <= mq->usedCount) {
        if (!(flags & 1)) {
            OSRestoreInterrupts(enabled);
            return 0;
        }
        OSSleepThread(&mq->queueSend);
    }
    lastIndex = (mq->firstIndex + mq->usedCount) % mq->msgCount;
    ((u32*)mq->msgArray)[lastIndex] = (u32)msg;
    mq->usedCount++;
    OSWakeupThread(&mq->queueReceive);
    OSRestoreInterrupts(enabled);
    return 1;
}

int OSReceiveMessage(OSMessageQueue* mq, void* msg, s32 flags) {
    BOOL enabled = OSDisableInterrupts();

    while (mq->usedCount == 0) {
        if (!(flags & 1)) {
            OSRestoreInterrupts(enabled);
            return 0;
        }
        OSSleepThread(&mq->queueReceive);
    }
    if (msg != NULL) {
        *(u32*)msg = ((u32*)mq->msgArray)[mq->firstIndex];
    }

    mq->firstIndex = (mq->firstIndex + 1) % mq->msgCount;
    mq->usedCount--;
    OSWakeupThread(&mq->queueSend);
    OSRestoreInterrupts(enabled);
    return 1;
}

u32 OSGetPhysicalMemSize(void) {
    return *(u32*)0x80000028;
}

u32 OSGetConsoleSimulatedMemSize(void) {
    return *(u32*)0x800000F0;
}

BOOL OSOnReset(BOOL final) {
    if (final) {
        __MEMRegs[8] = 0xFF;
        __OSMaskInterrupts(OS_INTERRUPTMASK_MEM_RESET);
    }
    return TRUE;
}

static OSResetFunctionInfo ResetFunctionInfo = { OSOnReset, 0x7F, NULL, NULL };

static void MEMIntrruptHandler(__OSInterrupt interrupt, OSContext* context) {
    u32 addr;
    u32 cause;

    cause = __MEMRegs[0xf];
    addr = (((u32)__MEMRegs[0x12] & 0x3ff) << 16) | __MEMRegs[0x11];
    __MEMRegs[0x10] = 0;

    if (__OSErrorTable[__OS_EXCEPTION_MEMORY_PROTECTION]) {
        __OSErrorTable[__OS_EXCEPTION_MEMORY_PROTECTION](__OS_EXCEPTION_MEMORY_PROTECTION, context, cause, addr);
        return;
    }

    __OSUnhandledException(__OS_EXCEPTION_MEMORY_PROTECTION, context, cause, addr);
}

static asm void Config24MB(void) {
    nofralloc
    li r7, 0x0
    lis r4, 0x0
    addi r4, r4, 0x2
    lis r3, 0x8000
    addi r3, r3, 0x1ff
    lis r6, 0x100
    addi r6, r6, 0x2
    lis r5, 0x8100
    addi r5, r5, 0xff
    isync
    mtdbatu 0, r7
    mtdbatl 0, r4
    mtdbatu 0, r3
    isync
    mtibatu 0, r7
    mtibatl 0, r4
    mtibatu 0, r3
    isync
    mtdbatu 2, r7
    mtdbatl 2, r6
    mtdbatu 2, r5
    isync
    mtibatu 2, r7
    mtibatl 2, r6
    mtibatu 2, r5
    isync
    mfmsr r3
    ori r3, r3, 0x30
    mtsrr1 r3
    mflr r3
    mtsrr0 r3
    rfi
}

static asm void Config48MB(void) {
    nofralloc
    li r7, 0x0
    lis r4, 0x0
    addi r4, r4, 0x2
    lis r3, 0x8000
    addi r3, r3, 0x3ff
    lis r6, 0x200
    addi r6, r6, 0x2
    lis r5, 0x8200
    addi r5, r5, 0x1ff
    isync
    mtdbatu 0, r7
    mtdbatl 0, r4
    mtdbatu 0, r3
    isync
    mtibatu 0, r7
    mtibatl 0, r4
    mtibatu 0, r3
    isync
    mtdbatu 2, r7
    mtdbatl 2, r6
    mtdbatu 2, r5
    isync
    mtibatu 2, r7
    mtibatl 2, r6
    mtibatu 2, r5
    isync
    mfmsr r3
    ori r3, r3, 0x30
    mtsrr1 r3
    mflr r3
    mtsrr0 r3
    rfi
}

static asm void RealMode(register u32 addr) {
    nofralloc
    clrlwi addr, addr, 2
    mtsrr0 addr
    mfmsr addr
    rlwinm addr, addr, 0, 28, 25
    mtsrr1 addr
    rfi
}

void __OSInitMemoryProtection(void) {
    BOOL enabled;
    u32 size;

    size = OSGetConsoleSimulatedMemSize();
    enabled = OSDisableInterrupts();

    __MEMRegs[16] = 0;
    __MEMRegs[8] = 0xFF;

    __OSMaskInterrupts(OS_INTERRUPTMASK_MEM_0 | OS_INTERRUPTMASK_MEM_1 | OS_INTERRUPTMASK_MEM_2 |
                        OS_INTERRUPTMASK_MEM_3);
    __OSSetInterruptHandler(__OS_INTERRUPT_MEM_0, MEMIntrruptHandler);
    __OSSetInterruptHandler(__OS_INTERRUPT_MEM_1, MEMIntrruptHandler);
    __OSSetInterruptHandler(__OS_INTERRUPT_MEM_2, MEMIntrruptHandler);
    __OSSetInterruptHandler(__OS_INTERRUPT_MEM_3, MEMIntrruptHandler);
    __OSSetInterruptHandler(__OS_INTERRUPT_MEM_ADDRESS, MEMIntrruptHandler);
    OSRegisterResetFunction(&ResetFunctionInfo);

    if (OSGetConsoleSimulatedMemSize() < OSGetPhysicalMemSize() && OSGetConsoleSimulatedMemSize() == 0x1800000) {
        DCInvalidateRange((void*)0x81800000, 0x1800000);
        __MEMRegs[20] = 2;
    }

    if (size <= 0x1800000) {
        RealMode((u32)&Config24MB);
    } else if (size <= 0x3000000) {
        RealMode((u32)&Config48MB);
    }

    __OSUnmaskInterrupts(OS_INTERRUPTMASK_MEM_ADDRESS);
    OSRestoreInterrupts(enabled);
}

#define ENQUEUE_MUTEX(mutex, queue, link) \
    do { \
        OSMutex* __prev = (queue)->tail; \
        if (__prev == NULL) { \
            (queue)->head = (mutex); \
        } else { \
            __prev->link.next = (mutex); \
        } \
        (mutex)->link.prev = __prev; \
        (mutex)->link.next = 0; \
        (queue)->tail = (mutex); \
    } while (0);

#define DEQUEUE_MUTEX(mutex, queue, link) \
    do { \
        OSMutex* __next = (mutex)->link.next; \
        OSMutex* __prev = (mutex)->link.prev; \
        if (__next == NULL) { \
            (queue)->tail = __prev; \
        } else { \
            __next->link.prev = __prev; \
        } \
        if (__prev == NULL) { \
            (queue)->head = __next; \
        } else { \
            __prev->link.next = __next; \
        } \
    } while (0);

#define DEQUEUE_HEAD(mutex, queue, link) \
    do { \
        OSMutex* __next = mutex->link.next; \
        if (__next == NULL) { \
            (queue)->tail = 0; \
        } else { \
            __next->link.prev = 0; \
        } \
        (queue)->head = __next; \
    } while (0);

void fn_803D7E20(OSMutex* mutex) {
    OSInitThreadQueue(&mutex->queue);
    mutex->thread = 0;
    mutex->count = 0;
}

void kar_diagnostic__803d7e58(OSMutex* mutex) {
    BOOL enabled = OSDisableInterrupts();
    OSThread* currentThread = OSGetCurrentThread();

    while (1) {
        OSThread* ownerThread = mutex->thread;
        if (ownerThread == 0) {
            mutex->thread = currentThread;
            mutex->count++;
            ENQUEUE_MUTEX(mutex, &currentThread->queueMutex, link);
            break;
        } else if (ownerThread == currentThread) {
            mutex->count++;
            break;
        } else {
            currentThread->mutex = mutex;
            kar_osthread__near_803d9e28(mutex->thread, currentThread->priority);
            OSSleepThread(&mutex->queue);
            currentThread->mutex = NULL;
        }
    }
    OSRestoreInterrupts(enabled);
}

void kar_diagnostic__803d7f34(OSMutex* mutex) {
    BOOL enabled = OSDisableInterrupts();
    OSThread* currentThread = OSGetCurrentThread();

    if (mutex->thread == currentThread) {
        if (!--mutex->count) {
            DEQUEUE_MUTEX(mutex, &currentThread->queueMutex, link);
            mutex->thread = 0;

            if (currentThread->priority < currentThread->base) {
                currentThread->priority = __OSGetEffectivePriority(currentThread);
            }
            OSWakeupThread(&mutex->queue);
        }
    }
    OSRestoreInterrupts(enabled);
}

void __OSUnlockAllMutex(OSThread* thread) {
    OSMutex* mutex;

    while (thread->queueMutex.head) {
        mutex = thread->queueMutex.head;
        DEQUEUE_HEAD(mutex, &thread->queueMutex, link);
        mutex->count = 0;
        mutex->thread = 0;
        OSWakeupThread(&mutex->queue);
    }
}

static int IsMember(OSMutexQueue* queue, OSMutex* mutex) {
    OSMutex* member = queue->head;

    while (member) {
        if (mutex == member) {
            return 1;
        }
        member = member->link.next;
    }
    return 0;
}

int __OSCheckMutex(OSMutex* mutex) {
    OSThread* thread;
    OSThreadQueue* queue;
    s32 priority;

    priority = 0;
    queue = &mutex->queue;

    if (queue->head != NULL && queue->head->link.prev != NULL) {
        return 0;
    }
    if (queue->tail != NULL && queue->tail->link.next != NULL) {
        return 0;
    }
    thread = queue->head;
    while (thread) {
        if (thread->link.next != NULL && (thread != thread->link.next->link.prev)) {
            return 0;
        }
        if (thread->link.prev != NULL && (thread != thread->link.prev->link.next)) {
            return 0;
        }
        if (thread->state != 4) {
            return 0;
        }
        if (thread->priority < priority) {
            return 0;
        }
        priority = thread->priority;
        thread = thread->link.next;
    }
    if (mutex->thread) {
        if (mutex->count <= 0) {
            return 0;
        }
    } else if (mutex->count != 0) {
        return 0;
    }
    return 1;
}

int __OSCheckDeadLock(OSThread* thread) {
    OSMutex* mutex = thread->mutex;

    while (mutex && mutex->thread) {
        if (mutex->thread == thread) {
            return 1;
        }
        mutex = mutex->thread->mutex;
    }
    return 0;
}

int __OSCheckMutexes(OSThread* thread) {
    OSMutex* mutex = thread->queueMutex.head;

    while (mutex) {
        if (mutex->thread != thread) {
            return 0;
        }
        if (__OSCheckMutex(mutex) == 0) {
            return 0;
        }
        mutex = mutex->link.next;
    }
    return 1;
}

asm void fn_803D8218(register u32 lr) {
    nofralloc
    sync
    isync
    mtlr lr
    blr
}

static u32 lbl_805DDEF8;

void fn_803D8228(void) {
    lbl_805DDEF8 = 1;
}

static void* SaveStart;
static void* SaveEnd;

void __OSReboot(u32 resetCode, u32 bootDol) {
    OSContext exceptionContext;
    char* argvToPass;

    OSDisableInterrupts();
    OSSetArenaLo((void*)0x81280000);
    OSSetArenaHi((void*)0x812f0000);
    OSClearContext(&exceptionContext);
    OSSetCurrentContext(&exceptionContext);
    argvToPass = NULL;
    DVDInit();
    DVDSetAutoInvalidation(TRUE);
    DVDResume();
    lbl_805DDEF8 = 0;
    __OSMaskInterrupts(0xFFFFFFE0);
    __OSUnmaskInterrupts(0x400);
    OSEnableInterrupts();
}

typedef struct OSResetFunctionQueue2 {
    OSResetFunctionInfo* head;
    OSResetFunctionInfo* tail;
} OSResetFunctionQueue2;

#define ENQUEUE_INFO_PRIO(info, queue) \
    do { \
        OSResetFunctionInfo* __prev; \
        OSResetFunctionInfo* __next; \
        for (__next = (queue)->head; __next && (__next->priority <= (info)->priority); __next = __next->next) \
            ; \
        if (__next == 0) { \
            OSResetFunctionInfo* __prev2 = (queue)->tail; \
            if (__prev2 == 0) { \
                (queue)->head = (info); \
            } else { \
                __prev2->next = (info); \
            } \
            (info)->prev = __prev2; \
            (info)->next = 0; \
            (queue)->tail = (info); \
        } else { \
            (info)->next = __next; \
            __prev = __next->prev; \
            __next->prev = (info); \
            (info)->prev = __prev; \
            if (__prev == 0) { \
                (queue)->head = (info); \
            } else { \
                __prev->next = (info); \
            } \
        } \
    } while (0);

static OSResetFunctionQueue2 ResetFunctionQueue;

void OSRegisterResetFunction(OSResetFunctionInfo* info) {
    ENQUEUE_INFO_PRIO(info, &ResetFunctionQueue);
}

int fn_803D85F8(BOOL final) {
    OSResetFunctionInfo* info;
    int err;
    u32 priority;

    priority = 0;
    err = 0;

    for (info = ResetFunctionQueue.head; info != 0;) {
        if (err != 0 && priority != info->priority)
            break;
        err |= !info->func(final);
        priority = info->priority;
        info = info->next;
    }

    err |= !__OSSyncSram();
    if (err) {
        return 0;
    }
    return 1;
}

static asm void Reset(u32 resetCode) {
    nofralloc
    b L1
L0:
    mfspr r8, HID0
    ori r8, r8, 0x8
    mtspr HID0, r8
    isync
    sync
    nop
    b L2
L1:
    b L3
L2:
    mftb r5, 268
L2b:
    mftb r6, 268
    subf r7, r5, r6
    cmplwi r7, 0x1124
    blt L2b
    nop
    b L4
L3:
    b L5
L4:
    lis r8, 0xcc00
    ori r8, r8, 0x3000
    li r4, 0x3
    stw r4, 0x24(r8)
    stw r3, 0x24(r8)
    nop
    b L6
L5:
    b L7
L6:
    nop
    b L6
L7:
    b L0
}

void __OSDoHotReset(u32 resetCode) {
    OSDisableInterrupts();
    *(vu16*)0xCC002002 = 0;
    ICFlashInvalidate();
    Reset(resetCode * 8);
}

void OSResetSystem(BOOL reset, u32 resetCode, BOOL forceMenu) {
    OSSram* sram;
    BOOL disableRecalibration;
    OSThread* thread;
    OSThread* next;

    OSDisableScheduler();
    __OSStopAudioSystem();

    if (reset == OS_RESET_SHUTDOWN) {
        disableRecalibration = __PADDisableRecalibration(TRUE);
    }

    do {
    } while (!fn_803D85F8(FALSE));
    do {
    } while (!__OSSyncSram());

    OSDisableInterrupts();

    if (reset == OS_RESET_RESTART && forceMenu) {
        sram = __OSLockSram();
        sram->flags |= 0x40;
        __OSUnlockSram(1);
    }

    fn_803D85F8(TRUE);

    LCDisable();

    if (reset == OS_RESET_RESTART) {
        OSDisableInterrupts();
        *(vu16*)0xCC002002 = 0;
        ICFlashInvalidate();
        Reset(resetCode * 8);
    } else if (reset == OS_RESET_SHUTDOWN) {
        __PADDisableRecalibration(disableRecalibration);
    } else if (reset == OS_RESET_HOTRESET) {
        for (thread = __OSActiveThreadQueue.head; thread; thread = next) {
            next = thread->linkActive.next;
            switch (thread->state) {
            case 1:
            case 4:
                OSCancelThread(thread);
                continue;
            default:
                continue;
            }
        }
        OSEnableScheduler();
        __OSReboot(resetCode, forceMenu);
    }

    for (thread = __OSActiveThreadQueue.head; thread; thread = next) {
        next = thread->linkActive.next;
        switch (thread->state) {
        case 1:
        case 4:
            OSCancelThread(thread);
            continue;
        default:
            continue;
        }
    }

    memset(OSPhysicalToCached(0x40), 0, 0x8c);
    memset(OSPhysicalToCached(0xd4), 0, 0x14);
    memset(OSPhysicalToCached(0xf4), 0, 0x4);
    memset(OSPhysicalToCached(0x3000), 0, 0xc0);
    memset(OSPhysicalToCached(0x30c8), 0, 0xc);
    memset(OSPhysicalToCached(0x30e2), 0, 1);
    __PADDisableRecalibration(disableRecalibration);
}

u32 OSGetResetCode(void) {
    if (*(u8*)OSPhysicalToCached(0x30E2)) {
        return *(u32*)OSPhysicalToCached(0);
    }
    return (__PIRegs[9] & 0xFFFFFFF8) / 8;
}

static OSResetCallback ResetCallback;
static BOOL Down;
static BOOL LastState;
static OSTime HoldUp;
static OSTime HoldDown;

void __OSResetSWInterruptHandler(s16 exception, OSContext* context) {
    OSResetCallback callback;

    HoldDown = __OSGetSystemTime();
    while (__OSGetSystemTime() - HoldDown < 400 && !(__PIRegs[0] & 0x00010000)) {
        ;
    }
    if (!(__PIRegs[0] & 0x00010000)) {
        LastState = Down = TRUE;
        __OSMaskInterrupts(0x200);
        if (ResetCallback) {
            callback = ResetCallback;
            ResetCallback = NULL;
            callback();
        }
    }
    __PIRegs[0] = 2;
}

BOOL OSGetResetButtonState(void) {
    BOOL enabled = OSDisableInterrupts();
    int state;
    u32 reg;
    OSTime now;

    now = __OSGetSystemTime();

    reg = __PIRegs[0];
    if (!(reg & 0x00010000)) {
        if (!Down) {
            Down = TRUE;
            state = HoldUp ? TRUE : FALSE;
            HoldDown = now;
        } else {
            state = HoldUp || (400 < now - HoldDown) ? TRUE : FALSE;
        }
    } else if (Down) {
        Down = FALSE;
        state = LastState;
        if (state) {
            HoldUp = now;
        } else {
            HoldUp = 0;
        }
    } else if (HoldUp && (now - HoldUp < 40)) {
        state = TRUE;
    } else {
        state = FALSE;
        HoldUp = 0;
    }

    LastState = state;

    if (*(u8*)0x800030E3 & 0x1F) {
        OSTime fire = (*(u8*)0x800030E3 & 0x1F) * 60;
        fire = __OSStartTime + (fire * 4000);
        if (fire < now) {
            now -= fire;
            now = (now / 4000) / 2;
            if ((now & 1) == 0) {
                state = TRUE;
            } else {
                state = FALSE;
            }
        }
    }

    OSRestoreInterrupts(enabled);
    return state;
}

int OSGetResetSwitchState(void) {
    return OSGetResetButtonState();
}

static SramControl Scb_8056D900;

int WriteSram(void* buffer, u32 offset, u32 size);

void fn_803D8DA8(s32 chan, OSContext* context) {
    Scb_8056D900.sync =
        WriteSram(&Scb_8056D900.sram[Scb_8056D900.offset], Scb_8056D900.offset, SRAM_SIZE - Scb_8056D900.offset);
    if (Scb_8056D900.sync != 0) {
        Scb_8056D900.offset = SRAM_SIZE;
    }
}

int WriteSram(void* buffer, u32 offset, u32 size) {
    int err;
    u32 cmd;

    if (!EXILock(0, 1, fn_803D8DA8)) {
        return 0;
    }
    if (!EXISelect(0, 1, 3)) {
        EXIUnlock(0);
        return 0;
    }
    offset <<= 6;
    cmd = ((offset + 0x100) | 0xA0000000);
    err = 0;
    err |= !EXIImm(0, &cmd, 4, 1, 0);
    err |= !EXISync(0);
    err |= !EXIImmEx(0, buffer, size, 1);
    err |= !EXIDeselect(0);
    EXIUnlock(0);
    return !err;
}

static int ReadSram(void* buffer) {
    int err;
    u32 cmd;

    DCInvalidateRange(buffer, SRAM_SIZE);
    if (!EXILock(0, 1, NULL)) {
        return 0;
    }
    if (!EXISelect(0, 1, 3)) {
        EXIUnlock(0);
        return 0;
    }
    cmd = 0x20000100;
    err = 0;
    err |= !EXIImm(0, &cmd, 4, 1, 0);
    err |= !EXISync(0);
    err |= !EXIDma(0, buffer, SRAM_SIZE, 0, NULL);
    err |= !EXISync(0);
    err |= !EXIDeselect(0);
    EXIUnlock(0);
    return !err;
}

void __OSInitSram(void) {
    Scb_8056D900.locked = Scb_8056D900.enabled = FALSE;
    Scb_8056D900.sync = ReadSram(&Scb_8056D900);
    Scb_8056D900.offset = SRAM_SIZE;
}

static void* LockSram(u32 offset) {
    BOOL enabled;

    enabled = OSDisableInterrupts();
    if (Scb_8056D900.locked) {
        OSRestoreInterrupts(enabled);
        return NULL;
    }
    Scb_8056D900.enabled = enabled;
    Scb_8056D900.locked = TRUE;
    return &Scb_8056D900.sram[offset];
}

OSSram* __OSLockSram(void) {
    return (OSSram*)LockSram(0);
}

OSSramEx* __OSLockSramEx(void) {
    return (OSSramEx*)LockSram(sizeof(OSSram));
}

int UnlockSram(int commit, u32 offset) {
    u16* p;

    if (commit != 0) {
        if (offset == 0) {
            OSSram* sram = (OSSram*)Scb_8056D900.sram;
            if (2u < (sram->flags & 3)) {
                sram->flags &= ~3;
            }

            sram->checkSum = sram->checkSumInv = 0;
            for (p = (u16*)&sram->counterBias; p < ((u16*)&Scb_8056D900.sram[0x14]); p++) {
                sram->checkSum += *p;
                sram->checkSumInv += ~(*p);
            }
        }
        if (offset < Scb_8056D900.offset) {
            Scb_8056D900.offset = offset;
        }

        Scb_8056D900.sync = WriteSram(&Scb_8056D900.sram[Scb_8056D900.offset], Scb_8056D900.offset,
                                       SRAM_SIZE - Scb_8056D900.offset);
        if (Scb_8056D900.sync != 0) {
            Scb_8056D900.offset = SRAM_SIZE;
        }
    }
    Scb_8056D900.locked = FALSE;
    OSRestoreInterrupts(Scb_8056D900.enabled);
    return Scb_8056D900.sync;
}

int __OSUnlockSram(int commit) {
    return UnlockSram(commit, 0);
}

int __OSUnlockSramEx(int commit) {
    return UnlockSram(commit, sizeof(OSSram));
}

int __OSSyncSram(void) {
    return Scb_8056D900.sync;
}

int __OSReadROM(void* buffer, s32 length, s32 offset) {
    int err;
    u32 cmd;

    DCInvalidateRange(buffer, length);
    if (EXILock(0, 1, NULL) == 0) {
        return 0;
    }
    if (EXISelect(0, 1, 3) == 0) {
        EXIUnlock(0);
        return 0;
    }
    cmd = offset << 6;
    err = 0;
    err |= !EXIImm(0, &cmd, 4, 1, 0);
    err |= !EXISync(0);
    err |= !EXIDma(0, buffer, length, 0, NULL);
    err |= !EXISync(0);
    err |= !EXIDeselect(0);
    EXIUnlock(0);
    return !err;
}

u32 OSGetSoundMode(void) {
    OSSram* sram = __OSLockSram();
    u32 mode = (sram->flags & 4) ? 1 : 0;

    UnlockSram(0, 0);
    return mode;
}

void OSSetSoundMode(u32 mode) {
    OSSram* sram;

    mode *= 4;
    mode &= 4;
    sram = __OSLockSram();
    if (mode == (sram->flags & 4)) {
        UnlockSram(0, 0);
        return;
    }
    sram->flags &= 0xFFFFFFFB;
    sram->flags |= mode;
    UnlockSram(1, 0);
}
