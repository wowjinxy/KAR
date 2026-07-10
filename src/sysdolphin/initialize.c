#include <global.h>

#include <dolphin/gx/gxtypes.h>
#include <sysdolphin/initialize.h>
#include <sysdolphin/objalloc.h>
#include <sysdolphin/video.h>

#include <stdarg.h>

#define OSRoundDown32B(x) (((u32) (x)) & ~(32 - 1))
#define OSRoundUp32B(x)   (((u32) (x) + 32 - 1) & ~(32 - 1))

typedef struct _HSD_MemCallbacks {
    void* (*alloc)(u32 size, u32 align, u32 flags);
    void (*free)(void* ptr);
    void (*clear)(void);
    u32 (*get_remain)(void);
    s32 (*check_own)(void* ptr);
} HSD_MemCallbacks;

extern void DVDInit(void);
extern void* GXInit(void* fifo, u32 size);
extern void VIWaitForRetrace(void);
extern void HSD_IDSetup(void);
extern void HSD_VIInit(HSD_VIStatus* status, void* xfb0, void* xfb1, void* xfb2);

extern void* OSGetArenaLo(void);
extern void* OSGetArenaHi(void);
extern void OSSetArenaLo(void* newLo);
extern void* OSAllocFromArenaLo(u32 size, u32 align);
extern u32 OSGetPhysicalMemSize(void);
extern OSHeapHandle OSCreateHeap(void* lo, void* hi);
extern void OSDestroyHeap(OSHeapHandle heap);
extern void OSSetCurrentHeap(OSHeapHandle heap);
extern void* OSAllocFromHeap(OSHeapHandle heap, u32 size);
extern void OSFreeToHeap(OSHeapHandle heap, void* ptr);
extern s32 kar_diag__803d3884(OSHeapHandle heap);

extern void HSD_Panic(char* file, s32 line, char* msg);
extern void hsdForgetClassLibrary(char* name);
extern void _HSD_MemSetCallbacks(HSD_MemCallbacks* callbacks, u32 size);
extern void _HSD_MemClear(void);
extern u32 _HSD_MemGetRemain(void);

extern void GXInitLightPos(GXLightObj*, f32, f32, f32);
extern void GXInitLightDir(GXLightObj*, f32, f32, f32);
extern void GXInitLightAttn(GXLightObj*, f32, f32, f32, f32, f32, f32);
extern void GXInitLightColor(GXLightObj*, GXColor);
extern void GXLoadLightObjImm(GXLightObj*, s32);
extern s32 HSD_Index2LightID(s32);
extern void HSD_StateInvalidate(s32 mask);
extern void GXSetPixelFmt(s32 pix_fmt, s32 z_fmt);
extern void GXSetFieldMode(u8 field_rendering, u8 half_aspect_ratio);
extern void GXInvalidateVtxCache(void);
extern void GXInvalidateTexAll(void);

extern volatile OSHeapHandle lbl_805DCBB0;
extern GXRenderModeObj* lbl_805DCBB4;
extern s32 lbl_805DCBB8;
extern u32 lbl_805DCBBC;
extern s32 lbl_805DCBC0;
extern GXColor lbl_805DCBC4;

extern void* lbl_80589A48[3];
extern HSD_MemReport lbl_80589A54;
extern HSD_VIStatus lbl_80589A80;

extern const u32 lbl_805E6378[2];

extern void _HSD_AObjForgetMemory(void);
extern void _HSD_DispForgetMemory(void);
extern void fn_8041A7C8(void); /* _HSD_IDForgetMemory */
extern void _HSD_ObjAllocForgetMemory(void);
extern void fn_8041E6A4(void); /* _HSD_RandForgetMemory */
extern void fn_8041A504(void); /* _HSD_RObjForgetMemory */

extern HSD_ObjAllocData* HSD_AObjGetAllocData(void);
extern HSD_ObjAllocData* fn_80403594(void); /* HSD_FObjGetAllocData */
extern HSD_ObjAllocData* fn_8041A53C(void); /* HSD_IDGetAllocData */
extern HSD_ObjAllocData* fn_8041BC54(void); /* HSD_SListGetAllocData */
extern HSD_ObjAllocData* fn_8041BC60(void); /* HSD_DListGetAllocData */
extern HSD_ObjAllocData* HSD_VecGetAllocData(void);
extern HSD_ObjAllocData* HSD_MtxGetAllocData(void);
extern HSD_ObjAllocData* fn_804183D0(void); /* HSD_RObjGetAllocData */
extern HSD_ObjAllocData* fn_804183DC(void); /* HSD_RvalueObjGetAllocData */
extern HSD_ObjAllocData* fn_8041CF1C(void); /* HSD_ShadowGetAllocData */
extern HSD_ObjAllocData* HSD_RenderGetAllocData(void);
extern HSD_ObjAllocData* HSD_ChanGetAllocData(void);
extern HSD_ObjAllocData* HSD_TevRegGetAllocData(void);

extern void HSD_ListInitAllocData(void);
extern void HSD_AObjInitAllocData(void);
extern void HSD_FObjInitAllocData(void);
extern void HSD_IDInitAllocData(void);
extern void HSD_VecInitAllocData(void);
extern void HSD_MtxInitAllocData(void);
extern void HSD_RObjInitAllocData(void);
extern void HSD_RenderInitAllocData(void);
extern void HSD_ShadowInitAllocData(void);
extern void HSD_ZListInitAllocData(void);

char kar_src_initialize_80503c60[] = "initialize.c";
char kar_src_objalloc_80503d18[] = "objalloc.h";
char lbl_80503C70[] = "No memory space remains for XFB.\n";
char lbl_80503C94[] = "no space remains for gx fifo.\n";

#undef assert_line
#define assert_line(line, cond) \
    ((cond) ? (void) 0 : __assert(kar_src_initialize_80503c60, line, #cond))

u32 lbl_805DE290;
u32 lbl_805DE294;
u32 lbl_805DE298;
u32 lbl_805DE29C;
s32 lbl_805DE2A0;
u32 lbl_805DE2A4;
void* lbl_805DE2A8;
s32 lbl_805DE2B0;
s32 lbl_805DE2B4;
s32 lbl_805DE2B8;
s32 lbl_805DE2BC;
s32 lbl_805DE2C0;
s32 lbl_805DE2C4;
s32 lbl_805DE2AC;

#define assert_line_objalloc(line, cond) \
    ((cond) ? (void) 0 : __assert(kar_src_objalloc_80503d18, line, "data"))

char lbl_80503CB4[] = "!iparam_memory_callbacks";
extern char lbl_805DCBC8[5]; /* "addr" */

#define assert_line_memcb(line) \
    ((lbl_805DE2B8 == 0) ? (void) 0 \
                                     : __assert(kar_src_initialize_80503c60, \
                                                 line, lbl_80503CB4))
#define assert_line_addr(line, cond) \
    ((cond) ? (void) 0 : __assert(kar_src_initialize_80503c60, line, lbl_805DCBC8))

char lbl_80503CE4[] = "sysdolphin_base_library";
char lbl_80503CFC[] = "pix_fmt != GX_PF_RGB565_Z16";

#define assert_line_pixfmt(line, cond) \
    ((cond) ? (void) 0 : __assert(kar_src_initialize_80503c60, line, lbl_80503CFC))

void* _HSD_MemAllocDefaultCB(u32 size, u32 align, u32 flags);
void _HSD_MemFreeDefaultCB(void* ptr);
u32 _HSD_MemGetRemainDefaultCB(void);
void _HSD_MemClearDefaultCB(void);
s32 fn_80410310(void* ptr);

void HSD_Init(void)
{
    HSD_VIStatus vi_status;
    void* fifo;

    DVDInit();
    HSD_AllocateXFB(lbl_805DCBC0, lbl_805DCBB4);
    fifo = HSD_AllocateFIFO(lbl_805DCBBC);
    lbl_805DE2A8 = GXInit(fifo, lbl_805DCBBC);
    lbl_80589A54.gxfifo = lbl_805DCBBC;
    HSD_OSInit();

    vi_status.rmode = *lbl_805DCBB4;
    vi_status.black = GX_TRUE;
    vi_status.vf = GX_TRUE;
    vi_status.gamma = GX_GM_1_0;
    vi_status.clear_clr = *(GXColor*) lbl_805E6378;
    vi_status.clear_z = GX_MAX_Z24;
    vi_status.update_clr = GX_ENABLE;
    vi_status.update_alpha = GX_ENABLE;
    vi_status.update_z = GX_ENABLE;
    HSD_VIInit(&vi_status, lbl_80589A48[0], lbl_80589A48[1], lbl_80589A48[2]);

    HSD_GXInit();
    HSD_DVDInit();
    HSD_IDSetup();
    VIWaitForRetrace();
    HSD_ObjInit();
    lbl_805DE2B0 = TRUE;
}

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
    lbl_80589A54.xfb = fb_size * nbuffer;

    for (i = 0; i < nbuffer; i++) {
        if ((lbl_80589A48[i] = OSAllocFromArenaLo(fb_size, 0x20)) == NULL) {
            HSD_Panic(kar_src_initialize_80503c60, 0xF4, lbl_80503C70);
        }
    }
    for (i = nbuffer; i < HSD_VI_XFB_MAX; i++) {
        lbl_80589A48[i] = NULL;
    }
    return lbl_80589A48;
}

void* HSD_AllocateFIFO(u32 size)
{
    void* fifo = OSAllocFromArenaLo(size, 0x20);
    if (fifo == NULL) {
        HSD_Panic(kar_src_initialize_80503c60, 0x107, lbl_80503C94);
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
    GXInitLightColor(&lightobj, lbl_805DCBC4);

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

    lbl_80589A54.total = OSGetPhysicalMemSize();
    lbl_80589A54.system = lbl_80589A54.total - (u32) OSGetArenaHi() +
                           (u32) OSGetArenaLo() - lbl_80589A54.xfb -
                           lbl_80589A54.gxfifo;

    if (!lbl_805DE2B8) {
        HSD_MemCallbacks cb;
        cb.alloc = _HSD_MemAllocDefaultCB;
        cb.free = _HSD_MemFreeDefaultCB;
        cb.get_remain = _HSD_MemGetRemainDefaultCB;
        cb.clear = _HSD_MemClearDefaultCB;
        cb.check_own = fn_80410310;
        _HSD_MemSetCallbacks(&cb, sizeof(cb));

        if (lbl_805DE298 != 0 && lbl_805DE29C != 0) {
            u32 i;

            lbl_805DE290 = lbl_805DE298;
            lbl_805DE294 = lbl_805DE29C;
            lbl_805DE298 = 0;
            lbl_805DE29C = 0;

            if (lbl_805DE2A0) {
                for (i = 0; i < (lbl_805DE294 - lbl_805DE290) >> 2; i++) {
                    ((u32*) lbl_805DE290)[i] = lbl_805DE2A4;
                }
            }
            OSSetCurrentHeap(lbl_805DCBB0 = OSCreateHeap((void*) lbl_805DE290,
                                                          (void*) lbl_805DE294));
            lbl_80589A54.heap = lbl_805DE294 - lbl_805DE290;
            HSD_ObjSetHeap(lbl_80589A54.heap, NULL);
        } else {
            u32 i;

            new_arena_lo = OSRoundUp32B((u32) OSGetArenaLo());
            new_arena_hi = (u32) OSGetArenaHi();
            lbl_805DE290 = new_arena_lo;
            if (lbl_805DE2B4 > 0) {
                u32 want = new_arena_lo + lbl_805DE2B4;
                lbl_805DE294 = want;
                if (want > new_arena_hi) {
                    lbl_805DE294 = new_arena_hi;
                }
                lbl_805DE294 = OSRoundDown32B(lbl_805DE294);
            } else {
                lbl_805DE294 = OSRoundDown32B(new_arena_hi);
            }

            if (lbl_805DE2A0) {
                for (i = 0; i < (lbl_805DE294 - lbl_805DE290) >> 2; i++) {
                    ((u32*) lbl_805DE290)[i] = lbl_805DE2A4;
                }
            }
            OSSetCurrentHeap(lbl_805DCBB0 = OSCreateHeap((void*) lbl_805DE290,
                                                          (void*) lbl_805DE294));
            lbl_80589A54.heap = lbl_805DE294 - lbl_805DE290;
            HSD_ObjSetHeap(lbl_80589A54.heap, NULL);
            OSSetArenaLo((void*) lbl_805DE294);
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

    OSDestroyHeap(lbl_805DCBB0);
    if (lbl_805DE298 != 0 && lbl_805DE29C != 0) {
        lbl_805DE290 = lbl_805DE298;
        lbl_805DE294 = lbl_805DE29C;
        lbl_805DE298 = 0;
        lbl_805DE29C = 0;
    }
    if (lbl_805DE2A0) {
        for (i = 0; i < (lbl_805DE294 - lbl_805DE290) >> 2; i++) {
            ((u32*) lbl_805DE290)[i] = lbl_805DE2A4;
        }
    }
    OSSetCurrentHeap(lbl_805DCBB0 =
                          OSCreateHeap((void*) lbl_805DE290, (void*) lbl_805DE294));
}

s32 fn_80410310(void* ptr)
{
    s32 within = 0;
    if (lbl_805DE290 <= (u32) ptr) {
        if ((u32) ptr < lbl_805DE294) {
            within = 1;
        }
    }
    return within;
}

OSHeapHandle HSD_GetHeap(void)
{
    assert_line_memcb(0x1D1);
    return lbl_805DCBB0;
}

void HSD_SetHeap(OSHeapHandle handle)
{
    lbl_805DCBB0 = handle;
}

void kar_initialize__80410384(void* lo, void* hi)
{
    assert_line_memcb(0x1ED);

    if ((lo == NULL) != (hi == NULL)) {
        OSReport("missing argument.\n");
    } else {
        lbl_805DE298 = (u32) lo;
        lbl_805DE29C = (u32) hi;
    }
}

void HSD_GetNextArena(void** lo, void** hi)
{
    assert_line_memcb(0x205);
    if (lo != NULL) {
        *lo = (void*) lbl_805DE290;
    }
    if (hi != NULL) {
        *hi = (void*) lbl_805DE294;
    }
}

void HSD_ClearHeap(void)
{
    void (*cb_table[])(void) = {
        _HSD_AObjForgetMemory, _HSD_DispForgetMemory, fn_8041A7C8,
        _HSD_ObjAllocForgetMemory, fn_8041E6A4, fn_8041A504, NULL,
    };
    s32 i;

    hsdForgetClassLibrary(lbl_80503CE4);
    for (i = 0; cb_table[i] != NULL; i++) {
        cb_table[i]();
    }
    HSD_ObjInit();
    _HSD_MemClear();
    lbl_80589A54.heap = _HSD_MemGetRemain();
}

HSD_RenderPass HSD_GetCurrentRenderPass(void)
{
    return lbl_805DE2C4;
}

void HSD_StartRender(HSD_RenderPass pass)
{
    GXRenderModeObj* rmode = &lbl_80589A80.rmode;

    lbl_805DE2C4 = pass;
    if (rmode->aa) {
        GXSetPixelFmt(GX_PF_RGB565_Z16, lbl_805DCBB8);
    } else {
        GXSetPixelFmt(lbl_805DE2AC, GX_ZC_LINEAR);
    }
    GXSetFieldMode(rmode->field_rendering, rmode->xfbHeight < rmode->viHeight);

    if (lbl_805DE2C0 != 0) {
        if (lbl_805DE2C0 & 1) {
            GXInvalidateVtxCache();
        }
        if (lbl_805DE2C0 & 2) {
            GXInvalidateTexAll();
        }
        lbl_805DE2C0 = 0;
    }
}

void HSD_EndRender(void)
{
    (*(volatile s32*) &lbl_805DE2C4) == HSD_RP_OFFSCREEN;
}

void _HSD_NeedCacheInvalidate(u32 flags)
{
    lbl_805DE2C0 |= flags;
}

void kar_initialize__80410600(s32 pix_fmt, s32 z_fmt)
{
    assert_line_pixfmt(0x317, pix_fmt != GX_PF_RGB565_Z16);
    lbl_805DE2AC = pix_fmt;
    lbl_805DCBB8 = z_fmt;
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
                  { fn_80403594, "fobj" },
                  { fn_8041A53C, "id" },
                  { fn_8041BC54, "slist" },
                  { fn_8041BC60, "dlist" },
                  { HSD_VecGetAllocData, "vec" },
                  { HSD_MtxGetAllocData, "mtx" },
                  { fn_804183D0, "robj" },
                  { fn_804183DC, "rval" },
                  { fn_8041CF1C, "shadow" },
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

    if (lbl_805DE2B0) {
        if (!lbl_805DE2BC) {
            OSReport(
                "init parameter should be set before invoking HSD_Init().\n");
            lbl_805DE2BC = TRUE;
        }
        return FALSE;
    }

    va_start(ap, param);
    switch (param) {
    case HSD_INIT_FIFO_SIZE: {
        u32 fifo_size = va_arg(ap, u32);
        if (fifo_size > 0) {
            lbl_805DCBBC = fifo_size;
            ok = TRUE;
        }
    } break;

    case HSD_INIT_XFB_MAX_NUM: {
        u32 xfb_max_num = va_arg(ap, u32);
        if (xfb_max_num > 0) {
            lbl_805DCBC0 = xfb_max_num;
            ok = TRUE;
        }
    } break;

    case HSD_INIT_HEAP_MAX_SIZE: {
        u32 heap_max_size = va_arg(ap, u32);
        if (heap_max_size < OSGetPhysicalMemSize()) {
            lbl_805DE2B4 = heap_max_size;
            ok = TRUE;
        }
    } break;

    case HSD_INIT_NEXT_ARENA: {
        void* lo = va_arg(ap, void*);
        void* hi = va_arg(ap, void*);
        lbl_805DE298 = (u32) lo;
        lbl_805DE29C = (u32) hi;
        ok = TRUE;
    } break;

    case HSD_INIT_FILL_PATTERN: {
        u32 pattern = va_arg(ap, u32);
        lbl_805DE2A0 = 1;
        lbl_805DE2A4 = pattern;
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
            lbl_805DE2B8 = 1;
            ok = TRUE;
        }
    } break;

    case HSD_INIT_RENDER_MODE_OBJ: {
        GXRenderModeObj* rmode = va_arg(ap, GXRenderModeObj*);
        if (rmode != NULL) {
            lbl_805DCBB4 = rmode;
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
