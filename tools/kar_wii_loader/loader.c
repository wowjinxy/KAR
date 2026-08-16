// Copyright 2023 Pablo Stebler
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
// Adapted from https://gist.github.com/stblr/c99aa7bcdc26a0be78b4a50d6dc3359b
// for Kirby Air Ride. This remains an experimental compatibility loader, not a
// native Wii port of the game.

#define KAR_WII_MEM2_TARGET 1
#include "kar/wii_mem2.h"

#ifndef KAR_ADDR_AR_START_DMA
#error KAR_ADDR_AR_START_DMA must be supplied by the build script
#endif
#ifndef KAR_ADDR_AR_INIT
#error KAR_ADDR_AR_INIT must be supplied by the build script
#endif
#ifndef KAR_ADDR_AR_CALLBACK
#error KAR_ADDR_AR_CALLBACK must be supplied by the build script
#endif
#ifndef KAR_ADDR_AR_SIZE
#error KAR_ADDR_AR_SIZE must be supplied by the build script
#endif
#ifndef KAR_ADDR_AR_INTERNAL_SIZE
#error KAR_ADDR_AR_INTERNAL_SIZE must be supplied by the build script
#endif
#ifndef KAR_ADDR_AR_EXPANSION_SIZE
#error KAR_ADDR_AR_EXPANSION_SIZE must be supplied by the build script
#endif
#ifndef KAR_ADDR_AR_STACK_POINTER
#error KAR_ADDR_AR_STACK_POINTER must be supplied by the build script
#endif
#ifndef KAR_ADDR_AR_FREE_BLOCKS
#error KAR_ADDR_AR_FREE_BLOCKS must be supplied by the build script
#endif
#ifndef KAR_ADDR_AR_BLOCK_LENGTH
#error KAR_ADDR_AR_BLOCK_LENGTH must be supplied by the build script
#endif
#ifndef KAR_ADDR_AR_INIT_FLAG
#error KAR_ADDR_AR_INIT_FLAG must be supplied by the build script
#endif
#ifndef KAR_ADDR_OS_CREATE_ALARM
#error KAR_ADDR_OS_CREATE_ALARM must be supplied by the build script
#endif
#ifndef KAR_ADDR_OS_SET_ALARM
#error KAR_ADDR_OS_SET_ALARM must be supplied by the build script
#endif
#ifndef KAR_ADDR_OS_DISABLE_INTERRUPTS
#error KAR_ADDR_OS_DISABLE_INTERRUPTS must be supplied by the build script
#endif
#ifndef KAR_ADDR_OS_RESTORE_INTERRUPTS
#error KAR_ADDR_OS_RESTORE_INTERRUPTS must be supplied by the build script
#endif
#ifndef KAR_ADDR_LBMEMORY_ARAM_LIMIT
#error KAR_ADDR_LBMEMORY_ARAM_LIMIT must be supplied by the build script
#endif
#ifndef KAR_ADDR_GX_TLUT_CLEAR_BITS
#error KAR_ADDR_GX_TLUT_CLEAR_BITS must be supplied by the build script
#endif

#ifdef KAR_TARGET_DOL_ENTRY
#ifndef KAR_ADDR_OS_MASK_INTERRUPTS
#error KAR_ADDR_OS_MASK_INTERRUPTS must be supplied by the build script
#endif
#ifndef KAR_ADDR_DVD_READ_ISSUE
#error KAR_ADDR_DVD_READ_ISSUE must be supplied by the build script
#endif
#ifndef KAR_ADDR_DVD_CALLBACK
#error KAR_ADDR_DVD_CALLBACK must be supplied by the build script
#endif
#endif

#ifndef KAR_DISC_ID_0
#error KAR_DISC_ID_0 through KAR_DISC_ID_5 must be supplied by the build script
#endif
#ifndef KAR_DISC_NUMBER
#error KAR_DISC_NUMBER must be supplied by the build script
#endif
#ifndef KAR_DISC_REVISION
#error KAR_DISC_REVISION must be supplied by the build script
#endif

#ifndef KAR_ENABLE_DOLPHIN_OSREPORT
#define KAR_ENABLE_DOLPHIN_OSREPORT 0
#endif

#define KAR_WII_ARAM_PHYSICAL_START 0x10004000u
#define KAR_WII_ARAM_CACHED_START   0x90004000u
#define KAR_WII_ARAM_SIZE           0x01000000u

#define KAR_WII_MEM2_HEAP_START 0x91004000u
#define KAR_WII_MEM2_HEAP_END   KAR_WII_MEM2_API_ADDRESS

#define KAR_WII_STACK_TOP  0x92000000u
#define KAR_WII_LOADER_BASE 0x93000000u

#define STATIC_ASSERT(condition) __static_assert((condition), #condition)

STATIC_ASSERT(sizeof(KARWiiMem2API) == 0x28);

static void* Memcpy(void* dest, const void* src, u32 size)
{
    u8* out = dest;
    const u8* in = src;

    while (size-- > 0) {
        *out++ = *in++;
    }
    return dest;
}

static u32 AlignDown(u32 value, u32 alignment)
{
    return value / alignment * alignment;
}

static u32 AlignUp(u32 value, u32 alignment)
{
    return AlignDown(value + alignment - 1, alignment);
}

static void FlushDCache(const void* start, u32 size)
{
    u32 address;
    u32 end;

    if (size == 0) {
        return;
    }
    address = AlignDown((u32)start, 0x20);
    end = AlignUp((u32)start + size, 0x20);
    do {
        asm("dcbf 0, %0" : : "rm"(address));
        address += 0x20;
    } while (address < end);
    asm("sync");
}

static void InvalidateDCache(void* start, u32 size)
{
    u32 address;
    u32 end;

    if (size == 0) {
        return;
    }
    address = AlignDown((u32)start, 0x20);
    end = AlignUp((u32)start + size, 0x20);
    do {
        asm("dcbi 0, %0" : : "rm"(address));
        address += 0x20;
    } while (address < end);
}

static void InvalidateICache(void* start, u32 size)
{
    u32 address;
    u32 end;

    if (size == 0) {
        return;
    }
    address = AlignDown((u32)start, 0x20);
    end = AlignUp((u32)start + size, 0x20);
    do {
        asm("icbi 0, %0" : : "m"(address));
        address += 0x20;
    } while (address < end);
    asm("sync; isync");
}

static void WaitMilliseconds(u32 milliseconds)
{
    u32 duration = milliseconds * 60750;
    u32 start;
    u32 current;

    asm volatile("mfspr %0, 268" : "=r"(start));
    current = start;
    while (current - start < duration) {
        asm volatile("mfspr %0, 268" : "=r"(current));
    }
}

static volatile u32* const disr = (u32*)0xCC006000;
static volatile u32* const dicmdbuf0 = (u32*)0xCC006008;
static volatile u32* const dicmdbuf1 = (u32*)0xCC00600C;
static volatile u32* const dicmdbuf2 = (u32*)0xCC006010;
static volatile u32* const dimar = (u32*)0xCC006014;
static volatile u32* const dilength = (u32*)0xCC006018;
static volatile u32* const dicr = (u32*)0xCC00601C;
static volatile u32* const diimmbuf = (u32*)0xCC006020;

static volatile u32* const gpio_out = (u32*)0xCD8000E0;
static volatile u32* const resets = (u32*)0xCD800194;

static BOOL DIReadDiscID(void)
{
    *disr = 0x54;
    *dicmdbuf0 = 0xA8000040;
    *dicmdbuf1 = 0;
    *dicmdbuf2 = 0x20;
    *dimar = 0;
    *dilength = 0x20;
    *dicr = 3;
    InvalidateDCache((void*)0x80000000, 0x20);

    while (*dicr & 1) {
    }
    return !(*disr & 4);
}

static BOOL DIRead(void* dst, u32 size, u32 offset)
{
    *disr = 0x54;
    *dicmdbuf0 = 0xA8000000;
    *dicmdbuf1 = offset >> 2;
    *dicmdbuf2 = size;
    *dimar = (u32)dst & 0x1FFFFFFF;
    *dilength = size;
    *dicr = 3;
    InvalidateDCache(dst, size);

    while (*dicr & 1) {
    }
    return !(*disr & 4);
}

static BOOL DIIsInserted(void)
{
    *dicmdbuf0 = 0xE0000000;
    *diimmbuf = 0;
    *dicr = 1;

    while (*dicr & 1) {
    }
    return !(*diimmbuf & 0x01000000);
}

static void DIReset(void)
{
    *gpio_out &= ~0x10;
    *resets &= ~0x400;
    WaitMilliseconds(1);
    *resets |= 0x400;
}

static BOOL DiscIDMatches(void)
{
    const volatile u8* id = (const volatile u8*)0x80000000;

    return id[0] == KAR_DISC_ID_0 && id[1] == KAR_DISC_ID_1 &&
           id[2] == KAR_DISC_ID_2 && id[3] == KAR_DISC_ID_3 &&
           id[4] == KAR_DISC_ID_4 && id[5] == KAR_DISC_ID_5 &&
           id[6] == KAR_DISC_NUMBER && id[7] == KAR_DISC_REVISION;
}

typedef void (*ApploaderReportFunc)(const char* format, ...);
typedef void (*GameEntryFunc)(void);
typedef void (*ApploaderInitFunc)(ApploaderReportFunc report);
typedef s32 (*ApploaderMainFunc)(void** dst, u32* size, u32* shifted_offset);
typedef GameEntryFunc (*ApploaderCloseFunc)(void);
typedef void (*ApploaderEntryFunc)(ApploaderInitFunc* init,
                                  ApploaderMainFunc* main,
                                  ApploaderCloseFunc* close);

typedef struct ApploaderHeader {
    char revision[0x10];
    ApploaderEntryFunc entry;
    u32 size;
    u32 trailer;
    u8 padding[0x20 - 0x1C];
} ApploaderHeader;

STATIC_ASSERT(sizeof(ApploaderHeader) == 0x20);

static void Report(const char* format, ...)
{
    (void)format;
}

static BOOL last_disc_was_wrong;

static GameEntryFunc LoadAndRunApploader(void)
{
    ApploaderHeader* const header = (ApploaderHeader*)0x81100000;
    ApploaderInitFunc init;
    ApploaderMainFunc main;
    ApploaderCloseFunc close;
    void* dst;
    u32 size;
    u32 offset;

    last_disc_was_wrong = FALSE;
    if (!DIReadDiscID()) {
        return NULL;
    }
    if (!DiscIDMatches()) {
        last_disc_was_wrong = TRUE;
        return NULL;
    }
    if (!DIRead(header, sizeof(*header), 0x2440)) {
        return NULL;
    }
    if (!DIRead((void*)0x81200000,
                AlignUp(header->size + header->trailer, 0x20), 0x2460)) {
        return NULL;
    }
    InvalidateICache((void*)0x81200000, header->size + header->trailer);

    header->entry(&init, &main, &close);
    init(Report);

    while (main(&dst, &size, &offset)) {
        if (!DIRead(dst, size, offset)) {
            return NULL;
        }
        InvalidateICache(dst, size);
    }
    return close();
}

typedef struct OSAlarm OSAlarm;
typedef void (*OSAlarmHandler)(OSAlarm* alarm, void* context);

struct OSAlarm {
    OSAlarmHandler handler;
    u32 tag;
    s64 fire;
    OSAlarm* prev;
    OSAlarm* next;
    s64 period;
    s64 start;
};

STATIC_ASSERT(sizeof(OSAlarm) == 0x28);

typedef void (*OSCreateAlarmFunc)(OSAlarm* alarm);
typedef void (*OSSetAlarmFunc)(OSAlarm* alarm, s64 ticks,
                               OSAlarmHandler handler);
typedef void (*ARCallback)(void);
typedef BOOL (*OSDisableInterruptsFunc)(void);
typedef void (*OSRestoreInterruptsFunc)(BOOL enabled);

static OSAlarm arq_completion_alarm;
static BOOL arq_completion_alarm_initialized;

static void* ToCachedAddress(u32 address)
{
    return (void*)(address | 0x80000000u);
}

static void CopyToEmulatedAram(u32 mainmem_addr, u32 aram_addr, u32 length)
{
    void* cached_aram = ToCachedAddress(aram_addr);

    Memcpy(cached_aram, (const void*)mainmem_addr, length);
    FlushDCache(cached_aram, length);
}

static void CopyFromEmulatedAram(u32 mainmem_addr, u32 aram_addr, u32 length)
{
    void* cached_aram = ToCachedAddress(aram_addr);

    InvalidateDCache(cached_aram, length);
    Memcpy((void*)mainmem_addr, cached_aram, length);
    FlushDCache((const void*)mainmem_addr, length);
}

static void ARQCompletionAlarmHandler(OSAlarm* alarm, void* context)
{
    ARCallback callback = *(ARCallback*)KAR_ADDR_AR_CALLBACK;

    (void)alarm;
    (void)context;
    if (callback != NULL) {
        callback();
    }
}

static void MyARStartDMA(u32 type, u32 mainmem_addr, u32 aram_addr, u32 length)
{
    OSCreateAlarmFunc create_alarm =
        (OSCreateAlarmFunc)KAR_ADDR_OS_CREATE_ALARM;
    OSSetAlarmFunc set_alarm = (OSSetAlarmFunc)KAR_ADDR_OS_SET_ALARM;

    if (type == 0) {
        CopyToEmulatedAram(mainmem_addr, aram_addr, length);
    } else {
        CopyFromEmulatedAram(mainmem_addr, aram_addr, length);
    }

    /*
     * The SDK queue updates its pending request after ARStartDMA returns.
     * Complete on the next decrementer tick so callbacks preserve the original
     * asynchronous ordering instead of re-entering ARQPostRequest callers.
     */
    if (!arq_completion_alarm_initialized) {
        create_alarm(&arq_completion_alarm);
        arq_completion_alarm_initialized = TRUE;
    }
    set_alarm(&arq_completion_alarm, 1, ARQCompletionAlarmHandler);
}

static u32 MyARInit(u32* stack_index_addr, u32 num_entries)
{
    volatile u32* const lowmem_aram_size = (u32*)0xC00000D0;
    volatile BOOL* init_flag = (BOOL*)KAR_ADDR_AR_INIT_FLAG;
    OSDisableInterruptsFunc disable_interrupts =
        (OSDisableInterruptsFunc)KAR_ADDR_OS_DISABLE_INTERRUPTS;
    OSRestoreInterruptsFunc restore_interrupts =
        (OSRestoreInterruptsFunc)KAR_ADDR_OS_RESTORE_INTERRUPTS;
    OSCreateAlarmFunc create_alarm =
        (OSCreateAlarmFunc)KAR_ADDR_OS_CREATE_ALARM;
    BOOL interrupts_enabled;

    if (*init_flag == TRUE) {
        return KAR_WII_ARAM_PHYSICAL_START;
    }

    interrupts_enabled = disable_interrupts();
    *(ARCallback*)KAR_ADDR_AR_CALLBACK = NULL;
    *(volatile u32*)KAR_ADDR_AR_SIZE = KAR_WII_ARAM_SIZE;
    *(volatile u32*)KAR_ADDR_AR_INTERNAL_SIZE = KAR_WII_ARAM_SIZE;
    *(volatile u32*)KAR_ADDR_AR_EXPANSION_SIZE = 0;
    *(volatile u32*)KAR_ADDR_AR_STACK_POINTER =
        KAR_WII_ARAM_PHYSICAL_START;
    *(volatile u32*)KAR_ADDR_AR_FREE_BLOCKS = num_entries;
    *(u32**)KAR_ADDR_AR_BLOCK_LENGTH = stack_index_addr;
    *init_flag = TRUE;
    *lowmem_aram_size = KAR_WII_ARAM_SIZE;
    FlushDCache((const void*)KAR_ADDR_AR_CALLBACK, 0x20);
    if (!arq_completion_alarm_initialized) {
        create_alarm(&arq_completion_alarm);
        arq_completion_alarm_initialized = TRUE;
    }
    restore_interrupts(interrupts_enabled);
    return KAR_WII_ARAM_PHYSICAL_START;
}

static void PatchBranch(void* from, const void* to)
{
    u32 instructions[4] = {
        0x3D800000 | (((u32)to >> 16) & 0xFFFF),
        0x618C0000 | ((u32)to & 0xFFFF),
        0x7D8903A6,
        0x4E800420,
    };

    Memcpy(from, instructions, sizeof(instructions));
    FlushDCache(from, sizeof(instructions));
    InvalidateICache(from, sizeof(instructions));
}

static BOOL PatchInstruction(void* address, u32 expected, u32 replacement)
{
    if (*(volatile u32*)address != expected) {
        return FALSE;
    }
    Memcpy(address, &replacement, sizeof(replacement));
    FlushDCache(address, sizeof(replacement));
    InvalidateICache(address, sizeof(replacement));
    return TRUE;
}

static BOOL InstructionsMatch(const void* address, const u32* expected,
                              u32 count)
{
    const volatile u32* instructions = address;
    u32 index;

    for (index = 0; index < count; index++) {
        if (instructions[index] != expected[index]) {
            return FALSE;
        }
    }
    return TRUE;
}

static u32 mem2_heap_cursor;

static void* Mem2Alloc(u32 size, u32 alignment)
{
    u32 address;

    if (alignment == 0) {
        alignment = 0x20;
    }
    if ((alignment & (alignment - 1)) != 0) {
        return NULL;
    }

    address = AlignUp(mem2_heap_cursor, alignment);
    if (address < mem2_heap_cursor || address > KAR_WII_MEM2_HEAP_END ||
        size > KAR_WII_MEM2_HEAP_END - address) {
        return NULL;
    }
    mem2_heap_cursor = address + size;
    return (void*)address;
}

static u32 Mem2Available(void)
{
    return KAR_WII_MEM2_HEAP_END - mem2_heap_cursor;
}

static void InstallMem2API(void)
{
    volatile KARWiiMem2API* api = KAR_WII_MEM2_API;

    mem2_heap_cursor = KAR_WII_MEM2_HEAP_START;
    api->magic = 0;
    api->abi_version = KAR_WII_MEM2_ABI_VERSION;
    api->struct_size = sizeof(*api);
    api->loader_status = KAR_WII_LOADER_BOOTING;
    api->flags = KAR_WII_MEM2_FLAG_ARAM_EMULATED |
                 KAR_WII_MEM2_FLAG_ARQ_CPU_COPY;
    api->aram_cached_start = KAR_WII_ARAM_CACHED_START;
    api->aram_size = KAR_WII_ARAM_SIZE;
    api->heap_start = KAR_WII_MEM2_HEAP_START;
    api->heap_end = KAR_WII_MEM2_HEAP_END;
    api->alloc = Mem2Alloc;
    api->available = Mem2Available;
    FlushDCache((const void*)api, sizeof(*api));
    api->magic = KAR_WII_MEM2_API_MAGIC;
    FlushDCache((const void*)api, sizeof(api->magic));
}

static void SetLoaderStatus(KARWiiLoaderStatus status)
{
    KAR_WII_MEM2_API->loader_status = status;
    FlushDCache((const void*)&KAR_WII_MEM2_API->loader_status,
                sizeof(KAR_WII_MEM2_API->loader_status));
}

#ifdef KAR_TARGET_DOL_ENTRY
/*
 * Minimal IPC client for IOS /dev/di. KAR's GameCube OS has no Wii IPC
 * interrupt handler, so this deliberately polls with the PPC IPC interrupt
 * enable bits clear. Initialization is synchronous before KAR starts; runtime
 * reads use short OSAlarm polls so optical-disc latency never blocks an alarm
 * callback with the game scheduler disabled.
 */
#define IOS_OPEN             1u
#define IOS_IOCTL            6u
#define IOS_OPEN_READ_WRITE  2u
#define IOS_DI_LOW_READ      0x71u
#define IOS_DI_SUCCESS       1
#define IOS_IPC_TIMEOUT_TICKS 607500000u
#define IOS_IPC_POLL_TICKS   60750u
#define IOS_IPC_LATE_POLL_TICKS 607500u
#define KAR_DVD_INTERRUPT_MASK 0x00000400u

typedef void (*DVDLowCallback)(u32 reason);
typedef void (*OSMaskInterruptsFunc)(u32 mask);

typedef struct IOSRequest {
    u32 command;
    s32 result;
    s32 fd;
    u32 args[5];
    u8 padding[0x20];
} IOSRequest;

STATIC_ASSERT(sizeof(IOSRequest) == 0x40);

static volatile u32* const ipc_ppc_message = (u32*)0xCD000000;
static volatile u32* const ipc_ppc_control = (u32*)0xCD000004;
static volatile u32* const ipc_arm_message = (u32*)0xCD000008;
static volatile u32* const ipc_ppc_irq_flag = (u32*)0xCD000030;

typedef enum IOSIPCState {
    IOS_IPC_IDLE = 0,
    IOS_IPC_WAIT_ACK,
    IOS_IPC_WAIT_REPLY,
    IOS_IPC_POISONED,
} IOSIPCState;

static volatile IOSRequest ios_request __attribute__((aligned(32)));
static u32 ios_di_command[8] __attribute__((aligned(32)));
static char ios_di_path[0x20] __attribute__((aligned(32))) = "/dev/di";
static s32 ios_di_fd = -1;
static BOOL ios_ipc_failed;
static IOSIPCState ios_ipc_state;
static u32 ios_ipc_start_ticks;
static BOOL ios_ipc_timed_out;
static void* ios_read_dst;
static u32 ios_read_length;

static OSAlarm dvd_completion_alarm;
static BOOL dvd_completion_alarm_initialized;
static u32 dvd_completion_reason;

static u32 PhysicalAddress(const void* address)
{
    return (u32)address & 0x3FFFFFFFu;
}

static void ZeroMemory(void* address, u32 size)
{
    u8* bytes = address;

    while (size-- > 0) {
        *bytes++ = 0;
    }
}

static void SyncMMIO(void)
{
    asm("eieio; sync");
}

static u32 ReadTimeBase(void)
{
    u32 ticks;

    asm volatile("mfspr %0, 268" : "=r"(ticks));
    return ticks;
}

static BOOL WaitForIPCControl(u32 bit)
{
    u32 start;
    u32 current;

    start = ReadTimeBase();
    current = start;
    while ((*ipc_ppc_control & bit) == 0) {
        current = ReadTimeBase();
        if (current - start >= IOS_IPC_TIMEOUT_TICKS) {
            return FALSE;
        }
    }
    return TRUE;
}

static void PrepareIPC(void)
{
    u32 control;

    /* Disable PPC IPC interrupts; KAR has no handler for them. */
    *ipc_ppc_control = 0;
    SyncMMIO();

    control = *ipc_ppc_control;
    if (control & 2) {
        *ipc_ppc_control = 2;
        SyncMMIO();
    }
    if (control & 4) {
        *ipc_ppc_control = 4;
        SyncMMIO();
        *ipc_ppc_control = 8;
        SyncMMIO();
    }
    *ipc_ppc_irq_flag = 0x40000000u;
    SyncMMIO();
}

static BOOL ExecuteIOSRequest(s32* result)
{
    u32 reply;

    if (ios_ipc_failed) {
        return FALSE;
    }

    FlushDCache((const void*)&ios_request, sizeof(ios_request));
    *ipc_ppc_message = PhysicalAddress((const void*)&ios_request);
    SyncMMIO();
    *ipc_ppc_control = 1;
    SyncMMIO();

    if (!WaitForIPCControl(2)) {
        ios_ipc_failed = TRUE;
        return FALSE;
    }
    *ipc_ppc_control = 2;
    SyncMMIO();
    *ipc_ppc_irq_flag = 0x40000000u;
    SyncMMIO();

    if (!WaitForIPCControl(4)) {
        ios_ipc_failed = TRUE;
        return FALSE;
    }
    reply = *ipc_arm_message;
    *ipc_ppc_control = 4;
    SyncMMIO();
    *ipc_ppc_irq_flag = 0x40000000u;
    SyncMMIO();

    InvalidateDCache((void*)&ios_request, sizeof(ios_request));
    asm("sync");
    *result = ios_request.result;

    *ipc_ppc_control = 8;
    SyncMMIO();
    *ipc_ppc_irq_flag = 0x40000000u;
    SyncMMIO();

    if (PhysicalAddress((const void*)reply) !=
        PhysicalAddress((const void*)&ios_request)) {
        ios_ipc_failed = TRUE;
        return FALSE;
    }
    return TRUE;
}

static BOOL WiiDIInit(void)
{
    s32 result;

    PrepareIPC();
    FlushDCache(ios_di_path, sizeof(ios_di_path));
    ZeroMemory((void*)&ios_request, sizeof(ios_request));
    ios_request.command = IOS_OPEN;
    ios_request.args[0] = PhysicalAddress(ios_di_path);
    ios_request.args[1] = IOS_OPEN_READ_WRITE;
    if (!ExecuteIOSRequest(&result) || result < 0) {
        return FALSE;
    }
    ios_di_fd = result;
    return TRUE;
}

static BOOL BeginWiiDIRead(void* dst, u32 length, u32 byte_offset)
{
    u32 start = (u32)dst;
    u32 end = start + length;

    if (ios_ipc_failed || ios_ipc_state != IOS_IPC_IDLE || ios_di_fd < 0 ||
        length == 0 || (start & 0x1F) != 0 ||
        (length & 0x1F) != 0 || (byte_offset & 3) != 0 || end < start ||
        !((start >= 0x80000000u && end <= 0x81800000u) ||
          (start >= KAR_WII_ARAM_CACHED_START &&
           end <= KAR_WII_MEM2_API_ADDRESS))) {
        return FALSE;
    }

    ZeroMemory(ios_di_command, sizeof(ios_di_command));
    ios_di_command[0] = IOS_DI_LOW_READ << 24;
    ios_di_command[1] = length;
    ios_di_command[2] = byte_offset >> 2;
    FlushDCache(ios_di_command, sizeof(ios_di_command));
    FlushDCache(dst, length);

    ZeroMemory((void*)&ios_request, sizeof(ios_request));
    ios_request.command = IOS_IOCTL;
    ios_request.fd = ios_di_fd;
    ios_request.args[0] = IOS_DI_LOW_READ;
    ios_request.args[1] = PhysicalAddress(ios_di_command);
    ios_request.args[2] = sizeof(ios_di_command);
    ios_request.args[3] = PhysicalAddress(dst);
    ios_request.args[4] = length;

    ios_read_dst = dst;
    ios_read_length = length;
    ios_ipc_start_ticks = ReadTimeBase();
    ios_ipc_timed_out = FALSE;
    ios_ipc_state = IOS_IPC_WAIT_ACK;
    FlushDCache((const void*)&ios_request, sizeof(ios_request));
    *ipc_ppc_message = PhysicalAddress((const void*)&ios_request);
    SyncMMIO();
    *ipc_ppc_control = 1;
    SyncMMIO();
    return TRUE;
}

static void DVDReadCompletionAlarmHandler(OSAlarm* alarm, void* context)
{
    DVDLowCallback callback =
        *(DVDLowCallback*)KAR_ADDR_DVD_CALLBACK;
    volatile BOOL* stop_at_next_interrupt =
        (BOOL*)(KAR_ADDR_DVD_CALLBACK - 8);
    volatile BOOL* breaking =
        (BOOL*)(KAR_ADDR_DVD_CALLBACK + 0x18);
    u32 reason = dvd_completion_reason;
    BOOL was_stopped = *stop_at_next_interrupt;
    BOOL was_breaking = *breaking;

    (void)alarm;
    (void)context;
    *(DVDLowCallback*)KAR_ADDR_DVD_CALLBACK = NULL;
    *stop_at_next_interrupt = FALSE;

    if (was_stopped && was_breaking) {
        reason = 8;
    } else if (reason == 1) {
        *dilength = 0;
    }

    if (callback != NULL) {
        callback(reason);
    }
    *breaking = FALSE;
}

static void MarkRuntimeDIReadFailed(void)
{
    ios_ipc_failed = TRUE;
    dvd_completion_reason = 0x10;
    SetLoaderStatus(KAR_WII_LOADER_IOS_DI_READ_FAILED);
}

static void DVDReadIPCAlarmHandler(OSAlarm* alarm, void* context)
{
    OSSetAlarmFunc set_alarm = (OSSetAlarmFunc)KAR_ADDR_OS_SET_ALARM;
    s32 result;
    u32 reply;
    BOOL reply_matches;

    if (ios_ipc_state == IOS_IPC_WAIT_ACK &&
        (*ipc_ppc_control & 2) != 0) {
        *ipc_ppc_control = 2;
        SyncMMIO();
        *ipc_ppc_irq_flag = 0x40000000u;
        SyncMMIO();
        ios_ipc_state = IOS_IPC_WAIT_REPLY;
    }

    if (ios_ipc_state == IOS_IPC_WAIT_REPLY &&
        (*ipc_ppc_control & 4) != 0) {
        reply = *ipc_arm_message;
        *ipc_ppc_control = 4;
        SyncMMIO();
        *ipc_ppc_irq_flag = 0x40000000u;
        SyncMMIO();

        reply_matches =
            PhysicalAddress((const void*)reply) ==
            PhysicalAddress((const void*)&ios_request);
        if (reply_matches) {
            InvalidateDCache((void*)&ios_request, sizeof(ios_request));
            asm("sync");
            result = ios_request.result;
        } else {
            result = -1;
        }

        *ipc_ppc_control = 8;
        SyncMMIO();
        *ipc_ppc_irq_flag = 0x40000000u;
        SyncMMIO();

        if (!reply_matches) {
            ios_ipc_state = IOS_IPC_POISONED;
            MarkRuntimeDIReadFailed();
            return;
        }

        InvalidateDCache(ios_read_dst, ios_read_length);
        asm("sync");
        ios_ipc_state = IOS_IPC_IDLE;
        ios_read_dst = NULL;
        ios_read_length = 0;
        if (ios_ipc_timed_out || result != IOS_DI_SUCCESS) {
            MarkRuntimeDIReadFailed();
        } else {
            dvd_completion_reason = 1;
        }
        DVDReadCompletionAlarmHandler(alarm, context);
        return;
    }

    if (ios_ipc_state == IOS_IPC_IDLE ||
        ios_ipc_state == IOS_IPC_POISONED) {
        MarkRuntimeDIReadFailed();
        return;
    }

    if (!ios_ipc_timed_out &&
        ReadTimeBase() - ios_ipc_start_ticks >= IOS_IPC_TIMEOUT_TICKS) {
        /*
         * IOS may still DMA into the caller's buffer after a timeout. Keep the
         * callback and buffer owned until the late reply has been reaped.
         */
        ios_ipc_timed_out = TRUE;
        MarkRuntimeDIReadFailed();
    }

    set_alarm(alarm,
              ios_ipc_timed_out ? IOS_IPC_LATE_POLL_TICKS
                                : IOS_IPC_POLL_TICKS,
              DVDReadIPCAlarmHandler);
}

static void MyDVDLowReadIssue(void* dst, u32 length, u32 byte_offset,
                              DVDLowCallback callback)
{
    OSMaskInterruptsFunc mask_interrupts =
        (OSMaskInterruptsFunc)KAR_ADDR_OS_MASK_INTERRUPTS;
    OSCreateAlarmFunc create_alarm =
        (OSCreateAlarmFunc)KAR_ADDR_OS_CREATE_ALARM;
    OSSetAlarmFunc set_alarm = (OSSetAlarmFunc)KAR_ADDR_OS_SET_ALARM;

    mask_interrupts(KAR_DVD_INTERRUPT_MASK);
    *(volatile BOOL*)(KAR_ADDR_DVD_CALLBACK - 8) = FALSE;

    if (ios_ipc_state != IOS_IPC_IDLE) {
        ios_ipc_state = IOS_IPC_POISONED;
        MarkRuntimeDIReadFailed();
        return;
    }

    *(DVDLowCallback*)KAR_ADDR_DVD_CALLBACK = callback;
    if (!dvd_completion_alarm_initialized) {
        create_alarm(&dvd_completion_alarm);
        dvd_completion_alarm_initialized = TRUE;
    }
    if (!BeginWiiDIRead(dst, length, byte_offset)) {
        MarkRuntimeDIReadFailed();
        set_alarm(&dvd_completion_alarm, 1, DVDReadCompletionAlarmHandler);
        return;
    }
    set_alarm(&dvd_completion_alarm, IOS_IPC_POLL_TICKS,
              DVDReadIPCAlarmHandler);
}
#endif

static BOOL PatchGame(void)
{
    static const u32 ar_start_dma_signature[] = {
        0x7C0802A6, 0x90010004, 0x9421FFD8, 0x93E10024,
    };
    static const u32 ar_init_signature[] = {
        0x7C0802A6, 0x90010004, 0x9421FFE0, 0x93E1001C,
    };
    static const u32 os_create_alarm_signature[] = {
        0x38000000, 0x90030000, 0x90030004, 0x4E800020,
    };
    static const u32 os_set_alarm_signature[] = {
        0x7C0802A6, 0x90010004, 0x9421FFC8, 0xBF610024,
    };
    static const u32 os_disable_interrupts_signature[] = {
        0x7C6000A6, 0x5464045E, 0x7C800124, 0x54638FFE,
    };
    static const u32 os_restore_interrupts_signature[] = {
        0x2C030000, 0x7C8000A6, 0x4182000C, 0x60858000,
    };
#ifdef KAR_TARGET_DOL_ENTRY
    static const u32 dvd_read_issue_signature[] = {
        0x7C0802A6, 0x90010004, 0x38000000, 0x9421FFD8,
    };

    if (!InstructionsMatch((const void*)KAR_ADDR_DVD_READ_ISSUE,
                           dvd_read_issue_signature, 4)) {
        return FALSE;
    }
#endif

    if (!InstructionsMatch((const void*)KAR_ADDR_AR_START_DMA,
                           ar_start_dma_signature, 4) ||
        !InstructionsMatch((const void*)KAR_ADDR_AR_INIT,
                           ar_init_signature, 4) ||
        !InstructionsMatch((const void*)KAR_ADDR_OS_CREATE_ALARM,
                           os_create_alarm_signature, 4) ||
        !InstructionsMatch((const void*)KAR_ADDR_OS_SET_ALARM,
                           os_set_alarm_signature, 4) ||
        !InstructionsMatch((const void*)KAR_ADDR_OS_DISABLE_INTERRUPTS,
                           os_disable_interrupts_signature, 4) ||
        !InstructionsMatch((const void*)KAR_ADDR_OS_RESTORE_INTERRUPTS,
                           os_restore_interrupts_signature, 4) ||
        *(volatile u32*)KAR_ADDR_LBMEMORY_ARAM_LIMIT != 0x7C661B78 ||
        *(volatile u32*)KAR_ADDR_GX_TLUT_CLEAR_BITS != 0x80830004) {
        return FALSE;
    }

    PatchBranch((void*)KAR_ADDR_AR_START_DMA, MyARStartDMA);
    PatchBranch((void*)KAR_ADDR_AR_INIT, MyARInit);
#ifdef KAR_TARGET_DOL_ENTRY
    PatchBranch((void*)KAR_ADDR_DVD_READ_ISSUE, MyDVDLowReadIssue);
#endif
    return PatchInstruction((void*)KAR_ADDR_LBMEMORY_ARAM_LIMIT,
                            0x7C661B78, /* mr r6, r3 */
                            0x3CC31000  /* addis r6, r3, 0x1000 */) &&
           PatchInstruction((void*)KAR_ADDR_GX_TLUT_CLEAR_BITS,
                            0x80830004, /* lwz r4, 4(r3) */
                            0x38800000  /* li r4, 0 */);
}

static volatile u32* const audio_control = (u32*)0xCC006C00;
static volatile u32* const arm_irq_mask = (u32*)0xCD80003C;
static volatile u32* const access_protection = (u32*)0xCD800070;
static u32* const console_type = (u32*)0x8000002C;

#ifdef KAR_TARGET_DOL_ENTRY
typedef struct FstEntry {
    u32 type_and_name_offset;
    u32 offset_or_parent;
    u32 size_or_next;
} FstEntry;

STATIC_ASSERT(sizeof(FstEntry) == 0xC);

static BOOL NormalizeWiiFstFileOffsets(void)
{
    FstEntry* fst = *(FstEntry**)0x80000038;
    u32 fst_size = *(u32*)0x8000003C;
    u32 fst_address = (u32)fst;
    u32 entry_count;
    u32 string_table_offset;
    u32 index;

    if (fst_address < 0x80000000 || fst_address >= 0x81800000 ||
        fst_size < sizeof(FstEntry) || fst_size > 0x81800000 - fst_address) {
        return FALSE;
    }

    entry_count = fst[0].size_or_next;
    if ((fst[0].type_and_name_offset >> 24) != 1 ||
        fst[0].offset_or_parent != 0 || entry_count == 0 ||
        entry_count > fst_size / sizeof(FstEntry)) {
        return FALSE;
    }

    string_table_offset = entry_count * sizeof(FstEntry);
    for (index = 1; index < entry_count; index++) {
        u32 type = fst[index].type_and_name_offset >> 24;
        u32 name_offset = fst[index].type_and_name_offset & 0x00FFFFFF;

        if (name_offset >= fst_size - string_table_offset) {
            return FALSE;
        }
        if (type == 0) {
            if (fst[index].offset_or_parent > 0x3FFFFFFF) {
                return FALSE;
            }
            fst[index].offset_or_parent <<= 2;
        } else if (type == 1) {
            if (fst[index].offset_or_parent >= index ||
                fst[index].size_or_next <= index ||
                fst[index].size_or_next > entry_count) {
                return FALSE;
            }
        } else {
            return FALSE;
        }
    }

    FlushDCache(fst, fst_size);
    KAR_WII_MEM2_API->flags |= KAR_WII_MEM2_FLAG_FST_BYTE_OFFSETS;
    FlushDCache((const void*)&KAR_WII_MEM2_API->flags,
                sizeof(KAR_WII_MEM2_API->flags));
    return TRUE;
}
#endif

static void Run(void)
{
    GameEntryFunc game_entry;

    /* Enable the GameCube-compatible MMIO aliases while remaining in Wii mode. */
    *access_protection &= ~1;
#ifdef KAR_TARGET_DOL_ENTRY
    /* IOS owns DI for decrypting partition reads in the merged-disc path. */
    *arm_irq_mask |= 1 << 18;
#else
    /* The standalone path owns DI directly and keeps Starlet away from it. */
    *arm_irq_mask &= ~(1 << 18);
#endif
    *audio_control = 0;

    InstallMem2API();
#ifdef KAR_TARGET_DOL_ENTRY
    if (!WiiDIInit()) {
        SetLoaderStatus(KAR_WII_LOADER_IOS_DI_INIT_FAILED);
        for (;;) {
        }
    }
    KAR_WII_MEM2_API->flags |= KAR_WII_MEM2_FLAG_IOS_DI_READS;
    FlushDCache((const void*)&KAR_WII_MEM2_API->flags,
                sizeof(KAR_WII_MEM2_API->flags));
    SetLoaderStatus(KAR_WII_LOADER_LOADING_GAME);
    if (!DiscIDMatches()) {
        SetLoaderStatus(KAR_WII_LOADER_WRONG_DISC);
        for (;;) {
        }
    }
    game_entry = (GameEntryFunc)KAR_TARGET_DOL_ENTRY;
    if (!NormalizeWiiFstFileOffsets()) {
        SetLoaderStatus(KAR_WII_LOADER_FST_FAILED);
        for (;;) {
        }
    }
#else
    for (;;) {
        SetLoaderStatus(KAR_WII_LOADER_LOADING_GAME);
        game_entry = LoadAndRunApploader();
        if (game_entry != NULL) {
            break;
        }

        if (last_disc_was_wrong) {
            SetLoaderStatus(KAR_WII_LOADER_WRONG_DISC);
            while (DIIsInserted()) {
                WaitMilliseconds(100);
            }
        } else {
            SetLoaderStatus(KAR_WII_LOADER_WAITING_FOR_DISC);
            while (!DIIsInserted()) {
                WaitMilliseconds(100);
            }
            DIReset();
        }
    }
#endif

    SetLoaderStatus(KAR_WII_LOADER_PATCHING_GAME);
    if (!PatchGame()) {
        SetLoaderStatus(KAR_WII_LOADER_PATCH_FAILED);
        for (;;) {
        }
    }

#if KAR_ENABLE_DOLPHIN_OSREPORT
    *console_type = 0x10000006;
#else
    (void)console_type;
#endif

    SetLoaderStatus(KAR_WII_LOADER_RUNNING_GAME);
    (*game_entry)();

    for (;;) {
    }
}

asm void Start(void)
{
    nofralloc

    lis r1, KAR_WII_STACK_TOP@h
    ori r1, r1, KAR_WII_STACK_TOP@l
    bl Run

loop:
    b loop

    /* Dolphin scans for this unreachable instruction to select Wii mode. */
    mtspr 1011, r3
}
