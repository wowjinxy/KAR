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

static void Run(void)
{
    GameEntryFunc game_entry;

    /* Enable the GameCube-compatible MMIO aliases while remaining in Wii mode. */
    *access_protection &= ~1;
    *arm_irq_mask &= ~(1 << 18);
    *audio_control = 0;

    InstallMem2API();
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
