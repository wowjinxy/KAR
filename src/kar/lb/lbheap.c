#include "functions.h"
#include <dolphin/types.h>
#include <kar/lb/lbheap.h>
#include <sysdolphin/memory.h>

typedef struct LbHeapConfig LbHeapConfig;
typedef struct LbHeapEntry LbHeapEntry;
typedef struct LbHeapReportData LbHeapReportData;
typedef struct LbHeapState LbHeapState;

struct LbHeapConfig {
    s32 kind;
    s32 type;
    s32 reference_kind;
    u32 size;
};

struct LbHeapEntry {
    s32 hsd_heap;
    void* memory_heap;
    u8* start;
    u32 size;
    s32 type;
    s32 request;
    s32 status;
};

struct LbHeapState {
    u8* main_start;
    u8* main_end;
    u8* aram_start;
    u8* aram_end;
    LbHeapEntry entries[10];
};

struct LbHeapReportData {
    char dat[12];
    char* names[10];
    char header[24];
    char used_fmt[12];
    char free_fmt[16];
    char destroyed_fmt[36];
    char total_fmt[12];
    char range_fmt[12];
    char main_total_fmt[32];
    char aram_total_fmt[32];
    char missing_kind_fmt[40];
};

extern LbHeapConfig kar_lbmemory_heap_config[];

char kar_src_lbheap_80497f60[] = "lbheap.c";
char kar_lbheap_assert_status_create[] = "p->status == LbHeapStatus_Create";
char kar_lbheap_name_hsd[] = "     Hsd";
char kar_lbheap_name_aram[] = "    ARAM";
char kar_lbheap_name_init[] = "    Init";
char kar_lbheap_name_stay[] = "    Stay";
char kar_lbheap_name_allm[] = "    AllM";
char kar_lbheap_name_net[] = "     Net";
char kar_lbheap_name_alla[] = "    AllA";
char kar_lbheap_name_stay2d[] = "  Stay2d";
char kar_lbheap_name_all2d[] = "   All2d";
LbHeapReportData kar_lbheap_report_data = {
    "     Dat",
    { kar_lbheap_name_hsd, kar_lbheap_name_aram, kar_lbheap_name_init,
      kar_lbheap_name_stay, kar_lbheap_name_allm, kar_lbheap_name_net,
      kar_lbheap_name_alla, kar_lbheap_name_stay2d, kar_lbheap_name_all2d,
      (char*) &kar_lbheap_report_data },
    "[lbHeap] -- Report --\n",
    " %5d KB + ",
    " %5d KB( %8d)",
    "                         destroy",
    " / %5d KB ",
    " [%p:%p]\n",
    "MainRAM Total : %5d KB( %8d)\n",
    "   ARAM Total : %5d KB( %8d)\n",
    "[LbHeap] heap_kind %d is not exist!\n",
};
LbHeapState lbheap_state;
char kar_lbheap_report_name_fmt[] = "%s :";

u32 OSDisableInterrupts(void);
void OSRestoreInterrupts(u32 level);
s32 HSD_GetHeap(void);
void HSD_SetHeap(s32 heap);
void HSD_GetNextArena(void** start, void** end);
void* kar_lbmemory_free_to_heap(void* heap, void* ptr);
s32 kar_lbmemory__near_80057924(void* heap);
void* kar_lbmemory__near_80057d14(void* heap, u32 size, void* ptr);
void kar_lbmemory__near_8005811c(void** start, void** end);

void kar_lbheap__80058920(s32 kind, void* ptr)
{
    LbHeapEntry* p;
    u32 interrupts;

    interrupts = OSDisableInterrupts();
    p = (LbHeapEntry*) ((u8*) &lbheap_state + (kind * sizeof(LbHeapEntry)) +
                        0x10);

    if (p->status != 0) {
        __assert(kar_src_lbheap_80497f60, 0x16A,
                 kar_lbheap_assert_status_create);
    }

    if (p->type == 0) {
        s32 heap = HSD_GetHeap();

        HSD_SetHeap(p->hsd_heap);
        HSD_Free(ptr);
        HSD_SetHeap(heap);
    } else {
        kar_lbmemory_free_to_heap(p->memory_heap, ptr);
    }

    OSRestoreInterrupts(interrupts);
}

void* kar_lbheap__near_800589e4(s32 kind, u32 size, void* ptr)
{
    LbHeapEntry* p;
    u32 interrupts;

    interrupts = OSDisableInterrupts();
    p = (LbHeapEntry*) ((u8*) &lbheap_state + (kind * sizeof(LbHeapEntry)) +
                        0x10);

    if (kind == 0 || kind == 1) {
        ptr = NULL;
    } else {
        ptr = kar_lbmemory__near_80057d14(p->memory_heap, size, ptr);
    }

    OSRestoreInterrupts(interrupts);
    return ptr;
}

void kar_lbheap__near_80058a80(void)
{
    u8* data_base = (u8*) kar_lbmemory_heap_config;
    char** names;
    u8* heap;
    LbHeapEntry* p;
    s32 i;

    OSReport((char*) (data_base + 0x160));

    heap = (u8*) &lbheap_state;
    names = (char**) (data_base + 0x138);
    for (i = 0; i < 10; i++) {
        OSReport(kar_lbheap_report_name_fmt, *names);
        p = (LbHeapEntry*) (heap + 0x10);
        if (*(s32*) (heap + 0x28) == 0) {
            s32 free_size;

            if (p->type == 0) {
                free_size = kar_diag__803d3884(p->hsd_heap);
            } else {
                free_size = kar_lbmemory__near_80057924(p->memory_heap);
            }

            OSReport((char*) (data_base + 0x178),
                     (u32) (p->size - free_size) >> 10);
            OSReport((char*) (data_base + 0x184), free_size / 1024,
                     free_size);
        } else {
            OSReport((char*) (data_base + 0x194));
        }

        OSReport((char*) (data_base + 0x1B8), p->size >> 10, p->size);
        OSReport((char*) (data_base + 0x1C4), p->start, p->start + p->size);

        names++;
        heap += sizeof(LbHeapEntry);
    }

    i = lbheap_state.main_end - lbheap_state.main_start;
    OSReport((char*) (data_base + 0x1D0), i / 1024, i);

    i = lbheap_state.aram_end - lbheap_state.aram_start;
    OSReport((char*) (data_base + 0x1F0), i / 1024, i);
}

void kar_lbheap__near_80058be8(void)
{
    LbHeapConfig* config;
    LbHeapEntry* p;
    s32 kind;
    s32 i;

    HSD_GetNextArena((void**) &lbheap_state.main_start,
                     (void**) &lbheap_state.main_end);
    kar_lbmemory__near_8005811c((void**) &lbheap_state.aram_start,
                                (void**) &lbheap_state.aram_end);

    p = lbheap_state.entries;
    for (i = 0; i < 2; i++) {
        p[0].hsd_heap = -1;
        p[0].memory_heap = (void*) -1;
        p[0].start = NULL;
        p[0].size = 0;
        p[0].type = 1;
        p[0].request = 1;
        p[0].status = 1;
        p[1].hsd_heap = -1;
        p[1].memory_heap = (void*) -1;
        p[1].start = NULL;
        p[1].size = 0;
        p[1].type = 1;
        p[1].request = 1;
        p[1].status = 1;
        p[2].hsd_heap = -1;
        p[2].memory_heap = (void*) -1;
        p[2].start = NULL;
        p[2].size = 0;
        p[2].type = 1;
        p[2].request = 1;
        p[2].status = 1;
        p[3].hsd_heap = -1;
        p[3].memory_heap = (void*) -1;
        p[3].start = NULL;
        p[3].size = 0;
        p[3].type = 1;
        p[3].request = 1;
        p[3].status = 1;
        p[4].hsd_heap = -1;
        p[4].memory_heap = (void*) -1;
        p[4].start = NULL;
        p[4].size = 0;
        p[4].type = 1;
        p[4].request = 1;
        p[4].status = 1;
        p += 5;
    }

    config = kar_lbmemory_heap_config;
    while ((kind = config->kind) != 10) {
        p = &lbheap_state.entries[kind];

        p->type = config->type;
        p->size = config->size;

        if (config->reference_kind == 10) {
            switch (p->type) {
            case 1:
                p->start = lbheap_state.main_start;
                break;
            case 2:
                p->start = lbheap_state.main_end - p->size;
                break;
            case 4:
                p->start = lbheap_state.aram_start;
                break;
            }
        } else {
            LbHeapEntry* ref =
                &lbheap_state.entries[config->reference_kind];

            switch (p->type) {
            case 1:
                p->start = ref->start + ref->size;
                break;
            case 2:
                p->start = ref->start - p->size;
                break;
            case 4:
                p->start = ref->start + ref->size;
                break;
            }
        }

        config++;
    }
}
