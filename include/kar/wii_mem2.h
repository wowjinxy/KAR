#ifndef KAR_WII_MEM2_H
#define KAR_WII_MEM2_H

#include "dolphin/types.h"

/*
 * Fixed ABI published by the experimental Wii-mode loader.
 *
 * The API page is deliberately outside both the emulated ARAM range and the
 * loader stack. Allocations are persistent bump allocations; there is no free
 * operation in ABI version 1.
 *
 * MEM2 is not mapped in GameCube mode. Define KAR_WII_MEM2_TARGET only for a
 * build that is required to run through the Wii-mode loader; this makes an
 * accidental availability probe in a normal GameCube build a compile error
 * instead of a possible DSI exception.
 */
#define KAR_WII_MEM2_API_ADDRESS 0x91EFF000u
#define KAR_WII_MEM2_API_MAGIC   0x4B415232u /* "KAR2" */
#define KAR_WII_MEM2_ABI_VERSION 1

#define KAR_WII_MEM2_FLAG_ARAM_EMULATED 0x00000001u
#define KAR_WII_MEM2_FLAG_ARQ_CPU_COPY   0x00000002u
#define KAR_WII_MEM2_FLAG_FST_BYTE_OFFSETS 0x00000004u
#define KAR_WII_MEM2_FLAG_IOS_DI_READS 0x00000008u

typedef enum KARWiiLoaderStatus {
    KAR_WII_LOADER_BOOTING = 0,
    KAR_WII_LOADER_WAITING_FOR_DISC = 1,
    KAR_WII_LOADER_WRONG_DISC = 2,
    KAR_WII_LOADER_LOADING_GAME = 3,
    KAR_WII_LOADER_PATCHING_GAME = 4,
    KAR_WII_LOADER_RUNNING_GAME = 5,
    KAR_WII_LOADER_PATCH_FAILED = 6,
    KAR_WII_LOADER_FST_FAILED = 7,
    KAR_WII_LOADER_IOS_DI_INIT_FAILED = 8,
    KAR_WII_LOADER_IOS_DI_READ_FAILED = 9,
} KARWiiLoaderStatus;

typedef void* (*KARWiiMem2AllocFn)(u32 size, u32 alignment);
typedef u32 (*KARWiiMem2AvailableFn)(void);

typedef struct KARWiiMem2API {
    u32 magic;
    u16 abi_version;
    u16 struct_size;
    volatile u32 loader_status;
    u32 flags;
    u32 aram_cached_start;
    u32 aram_size;
    u32 heap_start;
    u32 heap_end;
    KARWiiMem2AllocFn alloc;
    KARWiiMem2AvailableFn available;
} KARWiiMem2API;

#if defined(KAR_WII_MEM2_TARGET) && KAR_WII_MEM2_TARGET
#define KAR_WII_MEM2_API \
    ((volatile KARWiiMem2API*)KAR_WII_MEM2_API_ADDRESS)

static inline BOOL KARWiiMem2IsReady(void)
{
    return KAR_WII_MEM2_API->magic == KAR_WII_MEM2_API_MAGIC &&
           KAR_WII_MEM2_API->abi_version == KAR_WII_MEM2_ABI_VERSION;
}
#endif

#endif /* KAR_WII_MEM2_H */
