#include <global.h>

#include <dolphin/dvd.h>
#include <dolphin/gx/gx.h>
#include <dolphin/os.h>
#include <sysdolphin/class.h>
#include <sysdolphin/aobj_alloc.h>
#include <sysdolphin/displayfunc_alloc.h>
#include <sysdolphin/fobj.h>
#include <sysdolphin/gobjproc.h>
#include <sysdolphin/id.h>
#include <sysdolphin/initialize.h>
#include <sysdolphin/list.h>
#include <sysdolphin/lobj.h>
#include <sysdolphin/memory.h>
#include <sysdolphin/mtx.h>
#include <sysdolphin/objalloc.h>
#include <sysdolphin/random.h>
#include <sysdolphin/robj_alloc.h>
#include <sysdolphin/shadow.h>
#include <sysdolphin/tev_state.h>
#include <sysdolphin/video.h>
#include <sysdolphin/zlist.h>

#include <stdarg.h>

#define OSRoundDown32B(x) (((u32) (x)) & ~(32 - 1))
#define OSRoundUp32B(x)   (((u32) (x) + 32 - 1) & ~(32 - 1))

extern s32 kar_diag__803d3884(OSHeapHandle heap);

extern volatile OSHeapHandle HSD_CurrentHeap;
extern GXRenderModeObj* HSD_RenderMode;
extern s32 HSD_ZBufferFormat;
extern u32 HSD_FIFOSize;
extern s32 HSD_XFBMaxNum;
extern GXColor HSD_ClearColor;

extern void* HSD_XFBs[3];
extern HSD_MemReport HSD_MemReportData;
extern HSD_VIStatus CObjRenderMode;

extern const u32 HSD_DefaultClearColor[2];

extern void _HSD_AObjForgetMemory(void);

char InitializeSourceFile[] = "initialize.c";
char ObjAllocHeaderSourceFile[] = "objalloc.h";
char HSD_NoXfbMemoryMsg[] = "No memory space remains for XFB.\n";
char HSD_NoFifoMemoryMsg[] = "no space remains for gx fifo.\n";

#undef assert_line
#define assert_line(line, cond) \
    ((cond) ? (void) 0 : __assert(InitializeSourceFile, line, #cond))

u32 HSD_HeapLo;
u32 HSD_HeapHi;
u32 HSD_NextArenaLo;
u32 HSD_NextArenaHi;
s32 HSD_FillHeapEnabled;
u32 HSD_FillHeapPattern;
void* HSD_GXFifo;
s32 HSD_InitComplete;
s32 HSD_HeapMaxSize;
s32 HSD_HasCustomMemCallbacks;
s32 HSD_InitParamWarned;
s32 HSD_CacheInvalidateFlags;
s32 HSD_CurrentRenderPass;
s32 HSD_PixelFormat;

#define assert_line_objalloc(line, cond) \
    ((cond) ? (void) 0 : __assert(ObjAllocHeaderSourceFile, line, "data"))

char HSD_InvalidMemCallbacksMsg[] = "!iparam_memory_callbacks";
extern char HSD_AssertAddrString[5]; /* "addr" */

#define assert_line_memcb(line) \
    ((HSD_HasCustomMemCallbacks == 0) ? (void) 0 \
                                      : __assert(InitializeSourceFile, \
                                                  line, HSD_InvalidMemCallbacksMsg))
#define assert_line_addr(line, cond) \
    ((cond) ? (void) 0 : __assert(InitializeSourceFile, line, HSD_AssertAddrString))

char HSD_BaseLibraryName[] = "sysdolphin_base_library";
char HSD_InvalidPixFmtMsg[] = "pix_fmt != GX_PF_RGB565_Z16";

#define assert_line_pixfmt(line, cond) \
    ((cond) ? (void) 0 : __assert(InitializeSourceFile, line, HSD_InvalidPixFmtMsg))

void* _HSD_MemAllocDefaultCB(u32 size, u32 align, u32 flags);
void _HSD_MemFreeDefaultCB(void* ptr);
u32 _HSD_MemGetRemainDefaultCB(void);
void _HSD_MemClearDefaultCB(void);
s32 HSD_MemCheckOwnDefaultCB(void* ptr);

void HSD_Init(void)
{
    HSD_VIStatus vi_status;
#ifndef VERSION_GKYP01
    void* fifo;

    DVDInit();
    HSD_AllocateXFB(HSD_XFBMaxNum, HSD_RenderMode);
    fifo = HSD_AllocateFIFO(HSD_FIFOSize);
    HSD_GXFifo = GXInit(fifo, HSD_FIFOSize);
    HSD_MemReportData.gxfifo = HSD_FIFOSize;
#endif
    HSD_OSInit();

    vi_status.rmode = *HSD_RenderMode;
    vi_status.black = GX_TRUE;
    vi_status.vf = GX_TRUE;
    vi_status.gamma = GX_GM_1_0;
    vi_status.clear_clr = *(GXColor*) HSD_DefaultClearColor;
    vi_status.clear_z = GX_MAX_Z24;
    vi_status.update_clr = GX_ENABLE;
    vi_status.update_alpha = GX_ENABLE;
    vi_status.update_z = GX_ENABLE;
    HSD_VIInit(&vi_status, HSD_XFBs[0], HSD_XFBs[1], HSD_XFBs[2]);

    HSD_GXInit();
    HSD_DVDInit();
    HSD_IDSetup();
    VIWaitForRetrace();
    HSD_ObjInit();
    HSD_InitComplete = TRUE;
}

#ifdef VERSION_GKYP01
void HSD_GXSetFifoObj(GXFifoObj* fifo)
{
    HSD_GXFifo = fifo;
    HSD_MemReportData.gxfifo = HSD_FIFOSize;
}
#endif

void HSD_DVDInit(void)
{
}

void** HSD_AllocateXFB(s32 nbuffer, GXRenderModeObj* rmode)
{
    s32 i;
    u32 fb_size;

    if (rmode == NULL) {
        return NULL;
    }

    fb_size = (((rmode->fbWidth + 15) & 0xFFF0) * rmode->xfbHeight) << 1;
    HSD_MemReportData.xfb = fb_size * nbuffer;

    for (i = 0; i < nbuffer; i++) {
        if ((HSD_XFBs[i] = OSAllocFromArenaLo(fb_size, 0x20)) == NULL) {
            HSD_Panic(InitializeSourceFile, 0xF4, HSD_NoXfbMemoryMsg);
        }
    }
    for (i = nbuffer; i < HSD_VI_XFB_MAX; i++) {
        HSD_XFBs[i] = NULL;
    }
    return HSD_XFBs;
}

void* HSD_AllocateFIFO(u32 size)
{
    void* fifo = OSAllocFromArenaLo(size, 0x20);
    if (fifo == NULL) {
        HSD_Panic(InitializeSourceFile, 0x107, HSD_NoFifoMemoryMsg);
    }
    return fifo;
}

void HSD_GXInit(void)
{
    GXLightObj lightobj;
    s32 i;

    GXInitLightPos(&lightobj, 1.0F, 0.0F, 0.0F);
    GXInitLightDir(&lightobj, 1.0F, 0.0F, 0.0F);
    GXInitLightAttn(&lightobj, 1.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F);
    GXInitLightColor(&lightobj, HSD_ClearColor);

    for (i = 0; i < 8; i++) {
        GXLoadLightObjImm(&lightobj, HSD_Index2LightID(i));
    }
    HSD_StateInvalidate(-1);
}

void HSD_OSInit(void)
{
    u32 new_arena_lo;
    u32 new_arena_hi;
    u32 old_arena_lo = (u32) OSGetArenaLo();
    u32 old_arena_hi = (u32) OSGetArenaHi();

    HSD_MemReportData.total = OSGetPhysicalMemSize();
    HSD_MemReportData.system = HSD_MemReportData.total - (u32) OSGetArenaHi() +
                               (u32) OSGetArenaLo() - HSD_MemReportData.xfb -
                               HSD_MemReportData.gxfifo;

    if (!HSD_HasCustomMemCallbacks) {
        HSD_MemCallbacks cb;
        cb.alloc = _HSD_MemAllocDefaultCB;
        cb.free = _HSD_MemFreeDefaultCB;
        cb.get_remain = _HSD_MemGetRemainDefaultCB;
        cb.clear = _HSD_MemClearDefaultCB;
        cb.check_own = HSD_MemCheckOwnDefaultCB;
        _HSD_MemSetCallbacks(&cb, sizeof(cb));

        if (HSD_NextArenaLo != 0 && HSD_NextArenaHi != 0) {
            u32 i;

            HSD_HeapLo = HSD_NextArenaLo;
            HSD_HeapHi = HSD_NextArenaHi;
            HSD_NextArenaLo = 0;
            HSD_NextArenaHi = 0;

            if (HSD_FillHeapEnabled) {
                for (i = 0; i < (HSD_HeapHi - HSD_HeapLo) >> 2; i++) {
                    ((u32*) HSD_HeapLo)[i] = HSD_FillHeapPattern;
                }
            }
            OSSetCurrentHeap(HSD_CurrentHeap = OSCreateHeap((void*) HSD_HeapLo,
                                                          (void*) HSD_HeapHi));
            HSD_MemReportData.heap = HSD_HeapHi - HSD_HeapLo;
            HSD_ObjSetHeap(HSD_MemReportData.heap, NULL);
        } else {
            u32 i;

            new_arena_lo = OSRoundUp32B((u32) OSGetArenaLo());
            new_arena_hi = (u32) OSGetArenaHi();
            HSD_HeapLo = new_arena_lo;
            if (HSD_HeapMaxSize > 0) {
                u32 want = new_arena_lo + HSD_HeapMaxSize;
                HSD_HeapHi = want;
                if (want > new_arena_hi) {
                    HSD_HeapHi = new_arena_hi;
                }
                HSD_HeapHi = OSRoundDown32B(HSD_HeapHi);
            } else {
                HSD_HeapHi = OSRoundDown32B(new_arena_hi);
            }

            if (HSD_FillHeapEnabled) {
                for (i = 0; i < (HSD_HeapHi - HSD_HeapLo) >> 2; i++) {
                    ((u32*) HSD_HeapLo)[i] = HSD_FillHeapPattern;
                }
            }
            OSSetCurrentHeap(HSD_CurrentHeap = OSCreateHeap((void*) HSD_HeapLo,
                                                          (void*) HSD_HeapHi));
            HSD_MemReportData.heap = HSD_HeapHi - HSD_HeapLo;
            HSD_ObjSetHeap(HSD_MemReportData.heap, NULL);
            OSSetArenaLo((void*) HSD_HeapHi);
        }
    }
}

void* _HSD_MemAllocDefaultCB(u32 size, u32 align, u32 flags)
{
    void* addr;

    if (size == 0) {
        return NULL;
    }
    addr = OSAllocFromHeap(HSD_GetHeap(), size);
    assert_line_addr(0x18D, addr);
    return addr;
}

void _HSD_MemFreeDefaultCB(void* ptr)
{
    OSFreeToHeap(HSD_GetHeap(), ptr);
}

u32 _HSD_MemGetRemainDefaultCB(void)
{
    return kar_diag__803d3884(HSD_GetHeap());
}

void _HSD_MemClearDefaultCB(void)
{
    u32 i;

    OSDestroyHeap(HSD_CurrentHeap);
    if (HSD_NextArenaLo != 0 && HSD_NextArenaHi != 0) {
        HSD_HeapLo = HSD_NextArenaLo;
        HSD_HeapHi = HSD_NextArenaHi;
        HSD_NextArenaLo = 0;
        HSD_NextArenaHi = 0;
    }
    if (HSD_FillHeapEnabled) {
        for (i = 0; i < (HSD_HeapHi - HSD_HeapLo) >> 2; i++) {
            ((u32*) HSD_HeapLo)[i] = HSD_FillHeapPattern;
        }
    }
    OSSetCurrentHeap(HSD_CurrentHeap =
                          OSCreateHeap((void*) HSD_HeapLo, (void*) HSD_HeapHi));
}

s32 HSD_MemCheckOwnDefaultCB(void* ptr)
{
    s32 within = 0;
    if (HSD_HeapLo <= (u32) ptr) {
        if ((u32) ptr < HSD_HeapHi) {
            within = 1;
        }
    }
    return within;
}

OSHeapHandle HSD_GetHeap(void)
{
    assert_line_memcb(0x1D1);
    return HSD_CurrentHeap;
}

void HSD_SetHeap(OSHeapHandle handle)
{
    HSD_CurrentHeap = handle;
}

void HSD_SetNextArena(void* lo, void* hi)
{
    assert_line_memcb(0x1ED);

    if ((lo == NULL) != (hi == NULL)) {
        OSReport("missing argument.\n");
    } else {
        HSD_NextArenaLo = (u32) lo;
        HSD_NextArenaHi = (u32) hi;
    }
}

void HSD_GetNextArena(void** lo, void** hi)
{
    assert_line_memcb(0x205);
    if (lo != NULL) {
        *lo = (void*) HSD_HeapLo;
    }
    if (hi != NULL) {
        *hi = (void*) HSD_HeapHi;
    }
}

void HSD_ClearHeap(void)
{
    void (*cb_table[])(void) = {
        _HSD_AObjForgetMemory, _HSD_DispForgetMemory, _HSD_IDForgetMemory,
        _HSD_ObjAllocForgetMemory, _HSD_RandForgetMemory, _HSD_RObjForgetMemory, NULL,
    };
    s32 i;

    hsdForgetClassLibrary(HSD_BaseLibraryName);
    for (i = 0; cb_table[i] != NULL; i++) {
        cb_table[i]();
    }
    HSD_ObjInit();
    _HSD_MemClear();
    HSD_MemReportData.heap = _HSD_MemGetRemain();
}

HSD_RenderPass HSD_GetCurrentRenderPass(void)
{
    return HSD_CurrentRenderPass;
}

void HSD_StartRender(HSD_RenderPass pass)
{
    GXRenderModeObj* rmode = &CObjRenderMode.rmode;

    HSD_CurrentRenderPass = pass;
    if (rmode->aa) {
        GXSetPixelFmt(GX_PF_RGB565_Z16, HSD_ZBufferFormat);
    } else {
        GXSetPixelFmt(HSD_PixelFormat, GX_ZC_LINEAR);
    }
    GXSetFieldMode(rmode->field_rendering, rmode->xfbHeight < rmode->viHeight);

    if (HSD_CacheInvalidateFlags != 0) {
        if (HSD_CacheInvalidateFlags & 1) {
            GXInvalidateVtxCache();
        }
        if (HSD_CacheInvalidateFlags & 2) {
            GXInvalidateTexAll();
        }
        HSD_CacheInvalidateFlags = 0;
    }
}

void HSD_EndRender(void)
{
    (*(volatile s32*) &HSD_CurrentRenderPass) == HSD_RP_OFFSCREEN;
}

void _HSD_NeedCacheInvalidate(u32 flags)
{
    HSD_CacheInvalidateFlags |= flags;
}

void HSD_SetPixelFormat(s32 pix_fmt, s32 z_fmt)
{
    assert_line_pixfmt(0x317, pix_fmt != GX_PF_RGB565_Z16);
    HSD_PixelFormat = pix_fmt;
    HSD_ZBufferFormat = z_fmt;
}

void HSD_ObjInit(void)
{
    HSD_ListInitAllocData();
    HSD_AObjInitAllocData();
    HSD_FObjInitAllocData();
    HSD_IDInitAllocData();
    HSD_VecInitAllocData();
    HSD_MtxInitAllocData();
    HSD_RObjInitAllocData();
    HSD_RenderInitAllocData();
    HSD_ShadowInitAllocData();
    HSD_ZListInitAllocData();
}

static inline u32 HSD_ObjAllocGetUsing(HSD_ObjAllocData* data)
{
    assert_line_objalloc(0xCD, data);
    return data->used;
}

static inline u32 HSD_ObjAllocGetFreed(HSD_ObjAllocData* data)
{
    assert_line_objalloc(0xDD, data);
    return data->free;
}

static inline u32 HSD_ObjAllocGetPeak(HSD_ObjAllocData* data)
{
    assert_line_objalloc(0xED, data);
    return data->peak;
}

void HSD_ObjDumpStat(void)
{
    struct {
        HSD_ObjAllocData* (*func)(void);
        char* label;
    } types[] = { { HSD_AObjGetAllocData, "aobj" },
                  { HSD_FObjGetAllocData, "fobj" },
                  { HSD_IDGetAllocData, "id" },
                  { HSD_SListGetAllocData, "slist" },
                  { HSD_DListGetAllocData, "dlist" },
                  { HSD_VecGetAllocData, "vec" },
                  { HSD_MtxGetAllocData, "mtx" },
                  { HSD_RObjGetAllocData, "robj" },
                  { HSD_RvalueObjGetAllocData, "rval" },
                  { HSD_ShadowGetAllocData, "shadow" },
                  { HSD_RenderGetAllocData, "render" },
                  { HSD_ChanGetAllocData, "chan" },
                  { HSD_TevRegGetAllocData, "tevreg" },
                  { NULL, NULL } };
    s32 i;

    for (i = 0; types[i].label; i++) {
        OSReport("objalloc: %s\tusing %d\tfreed %d\tpeak %d\n", types[i].label,
                 HSD_ObjAllocGetUsing(types[i].func()),
                 HSD_ObjAllocGetFreed(types[i].func()),
                 HSD_ObjAllocGetPeak(types[i].func()));
    }
}

bool HSD_SetInitParameter(HSD_InitParam param, ...)
{
    va_list ap;
    bool ok = FALSE;

    if (HSD_InitComplete) {
        if (!HSD_InitParamWarned) {
            OSReport(
                "init parameter should be set before invoking HSD_Init().\n");
            HSD_InitParamWarned = TRUE;
        }
        return FALSE;
    }

    va_start(ap, param);
    switch (param) {
    case HSD_INIT_FIFO_SIZE: {
        u32 fifo_size = va_arg(ap, u32);
        if (fifo_size > 0) {
            HSD_FIFOSize = fifo_size;
            ok = TRUE;
        }
    } break;

    case HSD_INIT_XFB_MAX_NUM: {
        u32 xfb_max_num = va_arg(ap, u32);
        if (xfb_max_num > 0) {
            HSD_XFBMaxNum = xfb_max_num;
            ok = TRUE;
        }
    } break;

    case HSD_INIT_HEAP_MAX_SIZE: {
        u32 heap_max_size = va_arg(ap, u32);
        if (heap_max_size < OSGetPhysicalMemSize()) {
            HSD_HeapMaxSize = heap_max_size;
            ok = TRUE;
        }
    } break;

    case HSD_INIT_NEXT_ARENA: {
        void* lo = va_arg(ap, void*);
        void* hi = va_arg(ap, void*);
        HSD_NextArenaLo = (u32) lo;
        HSD_NextArenaHi = (u32) hi;
        ok = TRUE;
    } break;

    case HSD_INIT_FILL_PATTERN: {
        u32 pattern = va_arg(ap, u32);
        HSD_FillHeapEnabled = 1;
        HSD_FillHeapPattern = pattern;
        ok = TRUE;
    } break;

    case HSD_INIT_MEMORY_CALLBACKS: {
        HSD_MemCallbacks cb;
        u32 v;
        cb.alloc = va_arg(ap, void*);
        cb.free = va_arg(ap, void*);
        cb.clear = va_arg(ap, void*);
        cb.get_remain = va_arg(ap, void*);
        cb.check_own = va_arg(ap, void*);
        v = va_arg(ap, u32);
        if (v != 0) {
            OSReport("ERROR in HSD_SetInitParameter():\n");
            OSReport(
                "  HSD_INIT_MEMORY_CALLBACKS was given invalid arguments.\n");
        } else {
            _HSD_MemSetCallbacks(&cb, sizeof(cb));
            HSD_HasCustomMemCallbacks = 1;
            ok = TRUE;
        }
    } break;

    case HSD_INIT_RENDER_MODE_OBJ: {
        GXRenderModeObj* rmode = va_arg(ap, GXRenderModeObj*);
        if (rmode != NULL) {
            HSD_RenderMode = rmode;
            ok = TRUE;
        }
    } break;

    case HSD_INIT_HEAP_MAX_NUM: {
        s32 v;
        OSReport("ERROR in HSD_SetInitParameter():\n");
        OSReport("  HSD_INIT_HEAP_MAX_NUM is obsolete since 1.3.0.0. \n");
        v = va_arg(ap, s32);
        if (v == 0) {
            ok = TRUE;
        }
    } break;

    case HSD_INIT_AUDIO_HEAP_SIZE:
        OSReport("ERROR in HSD_SetInitParameter():\n");
        OSReport("  HSD_INIT_AUDIO_HEAP_SIZE is obsolete since 1.3.0.0. \n");
        break;
    }
    va_end(ap);

    return ok;
}
