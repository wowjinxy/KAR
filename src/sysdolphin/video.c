#include <global.h>

#include <sysdolphin/video.h>

#define HSD_ANTIALIAS_OVERLAP 4
#define HSD_ANTIALIAS_GARBAGE_SIZE (640 * HSD_ANTIALIAS_OVERLAP * VI_DISPLAY_PIX_SZ)

#define GX_LEQUAL 3
#define GX_CLAMP_TOP 1
#define GX_CLAMP_BOTTOM 2

#define VI_NTSC 0

#define VIPadFrameBufferWidth(width) ((u16) (((u16) (width) + 15) & ~15))

typedef enum _HSD_VIXFBDrawDispStatus {
    HSD_VI_XFB_NONE,
    HSD_VI_XFB_NOUSE,
    HSD_VI_XFB_FREE,
    HSD_VI_XFB_DRAWING,
    HSD_VI_XFB_WAITDONE,
    HSD_VI_XFB_DRAWDONE,
    HSD_VI_XFB_NEXT,
    HSD_VI_XFB_DISPLAY,
    HSD_VI_XFB_COPYEFB,
    HSD_VI_XFB_TERMINATE
} HSD_VIXFBDrawDispStatus;

typedef enum _HSD_VIEFBDrawDispStatus {
    HSD_VI_EFB_FREE,
    HSD_VI_EFB_DRAWDONE,
    HSD_VI_EFB_TERMINATE
} HSD_VIEFBDrawDispStatus;

typedef struct _HSD_VICurrent {
    HSD_VIStatus vi;
    u8 chg_flag;
} HSD_VICurrent;

typedef struct _HSD_VIXFB {
    void* buffer;
    HSD_VIXFBDrawDispStatus status;
    HSD_VICurrent vi_all;
} HSD_VIXFB;

typedef struct _HSD_VIInfo {
    HSD_VICurrent current;

    HSD_VIXFB xfb[HSD_VI_XFB_MAX];

    struct {
        HSD_VIEFBDrawDispStatus status;
        HSD_VICurrent vi_all;
    } efb;

    s32 nb_xfb;

    HSD_VIRetraceCallback pre_cb;
    HSD_VIRetraceCallback post_cb;

    struct {
        s32 waiting;
        s32 arg;
        HSD_VIGXDrawDoneCallback cb;
    } drawdone;

    struct {
        s32 frame_period;
        s32 frame_renew;
    } perf;
} HSD_VIInfo;

extern HSD_VIInfo lbl_80589A80;
extern u8 lbl_80589C80[HSD_ANTIALIAS_GARBAGE_SIZE];

extern s32 lbl_805DE2C8; // vr_count
extern s32 lbl_805DE2CC; // renew_count

extern f32 lbl_805E5B70; // 1.0F

extern char kar_srcfile_video_c_805dcc38[8]; // "video.c"
extern char lbl_80503E80[10];                // "idx != -1"
extern char lbl_80503E8C[0x21]; // "unexpected type of render pass.\n"
extern char lbl_80503EB0[0x2A]; // "_p->xfb[idx].status == HSD_VI_XFB_DRAWING"
extern char lbl_80503EDC[0x2B]; // "_p->xfb[idx].status == HSD_VI_XFB_WAITDONE"

#define _p (&lbl_80589A80)

#define assert_line_named(line, cond, condstr)                               \
    ((cond) ? ((void) 0) : __assert(kar_srcfile_video_c_805dcc38, line, condstr))

extern u32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(u32 level);

extern void VIInit(void);
extern void VIConfigure(GXRenderModeObj* rmode);
extern void VISetBlack(bool black);
extern void VIFlush(void);
extern void VISetNextFrameBuffer(void* fb);
extern void VIWaitForRetrace(void);
extern void VISetPreRetraceCallback(HSD_VIRetraceCallback cb);
extern void VISetPostRetraceCallback(HSD_VIRetraceCallback cb);
extern u32 VIGetTvFormat(void);

extern void GXSetCopyFilter(u32 aa, const u8 sample_pattern[12][2], u32 vf,
                            const u8 vfilter[7]);
extern void GXSetDispCopyGamma(u32 gamma);
extern void GXSetCopyClear(GXColor clear_clr, u32 clear_z);
extern void GXSetCopyClamp(u32 clamp);
extern u32 GXSetDispCopyYScale(f32 vscale);
extern void GXSetDispCopyDst(u16 wd, u16 ht);
extern void GXCopyDisp(void* dest, u32 clear);
extern void GXPixModeSync(void);
extern void GXWaitDrawDone(void);

extern void fn_803CBDB8(void); // GXSetDrawDone
extern void* fn_803CC0CC(void (*cb)(void)); // GXSetDrawDoneCallback
extern void fn_803CC5C4(u16 left, u16 top, u16 wd, u16 ht); // GXSetDispCopySrc

extern void HSD_StateSetColorUpdate(u32 enable);
extern void HSD_StateSetAlphaUpdate(u32 enable);
extern void HSD_StateSetZMode(u32 enable, s32 func, u32 update);

extern void HSD_Panic(const char* file, s32 line, const char* msg);

static inline s32 HSD_VISearchXFBByStatus(HSD_VIXFBDrawDispStatus status)
{
    s32 i;

    for (i = 0; i < HSD_VI_XFB_MAX; i++) {
        if (_p->xfb[i].status == status) {
            return i;
        }
    }
    return -1;
}

HSD_VIRetraceCallback HSD_VISetUserPreRetraceCallback(HSD_VIRetraceCallback cb)
{
    bool intr;
    HSD_VIRetraceCallback old = _p->pre_cb;

    intr = OSDisableInterrupts();
    _p->pre_cb = cb;
    OSRestoreInterrupts(intr);

    return old;
}

HSD_VIRetraceCallback
HSD_VISetUserPostRetraceCallback(HSD_VIRetraceCallback cb)
{
    bool intr;
    HSD_VIRetraceCallback old = _p->post_cb;

    intr = OSDisableInterrupts();
    _p->post_cb = cb;
    OSRestoreInterrupts(intr);

    return old;
}

HSD_VIGXDrawDoneCallback
HSD_VISetUserGXDrawDoneCallback(HSD_VIGXDrawDoneCallback cb)
{
    bool intr;
    HSD_VIGXDrawDoneCallback old = _p->drawdone.cb;

    intr = OSDisableInterrupts();
    _p->drawdone.cb = cb;
    OSRestoreInterrupts(intr);

    return old;
}

void HSD_VIPreRetraceCB(u32 retraceCount)
{
    s32 idx;
    s32 flush = 0;
    s32 renew = 0;

    idx = HSD_VISearchXFBByStatus(HSD_VI_XFB_NEXT);
    if (idx != -1) {
        HSD_VIXFB* x = &_p->xfb[idx];
        VISetNextFrameBuffer(x->buffer);
        if (x->vi_all.chg_flag) {
            VIConfigure(&x->vi_all.vi.rmode);
            VISetBlack(x->vi_all.vi.black);
        }
        flush = 1;
        renew = 1;
    } else if (_p->nb_xfb == 1 && _p->efb.status == HSD_VI_EFB_DRAWDONE) {
        if ((idx = HSD_VISearchXFBByStatus(HSD_VI_XFB_DISPLAY)) == -1) {
            idx = HSD_VISearchXFBByStatus(HSD_VI_XFB_FREE);
            assert_line_named(0xFC, idx != -1, lbl_80503E80);
            VISetNextFrameBuffer(_p->xfb[idx].buffer);
            flush = 1;
        }
        _p->xfb[idx].status = HSD_VI_XFB_COPYEFB;
        if (_p->efb.vi_all.chg_flag) {
            VIConfigure(&_p->efb.vi_all.vi.rmode);
            VISetBlack(_p->efb.vi_all.vi.black);
            flush = 1;
        }
        renew = 1;
    }

    if (flush) {
        VIFlush();
    }

    {
        if (renew) {
            lbl_805DE2CC++;
        }
        if (++lbl_805DE2C8 >= _p->perf.frame_period) {
            _p->perf.frame_renew = lbl_805DE2CC;
            lbl_805DE2C8 = lbl_805DE2CC = 0;
        }
    }

    if (_p->pre_cb) {
        _p->pre_cb(retraceCount);
    }
}

void HSD_VIPostRetraceCB(u32 retraceCount)
{
    s32 idx;
    s32 next;

    if ((next = HSD_VISearchXFBByStatus(HSD_VI_XFB_NEXT)) != -1) {
        if ((idx = HSD_VISearchXFBByStatus(HSD_VI_XFB_DISPLAY)) != -1) {
            _p->xfb[idx].status = HSD_VI_XFB_FREE;
        }
        _p->xfb[next].status = HSD_VI_XFB_DISPLAY;
        if ((idx = HSD_VISearchXFBByStatus(HSD_VI_XFB_DRAWDONE)) != -1) {
            _p->xfb[idx].status = HSD_VI_XFB_NEXT;
        }
    } else if ((idx = HSD_VISearchXFBByStatus(HSD_VI_XFB_COPYEFB)) != -1) {
        HSD_VICopyEFB2XFBPtr(&_p->efb.vi_all.vi, _p->xfb[idx].buffer,
                             HSD_RP_SCREEN);
        _p->xfb[idx].status = HSD_VI_XFB_DISPLAY;
        _p->efb.status = HSD_VI_EFB_FREE;
    }

    if (_p->post_cb) {
        _p->post_cb(retraceCount);
    }
}

void HSD_VIGXDrawDoneCB(void)
{
    _p->drawdone.waiting = 0;

    if (_p->drawdone.cb) {
        _p->drawdone.cb(_p->drawdone.arg);
    }
}

#pragma push
#pragma dont_inline on
s32 HSD_VIGetDrawDoneWaitingFlag(void)
{
    return _p->drawdone.waiting;
}
#pragma pop

static inline void HSD_VICopyEFB2XFBHiResoAA(GXRenderModeObj* rmode)
{
    s32 n_xfb_lines;

    fn_803CC5C4(0, 0, rmode->fbWidth, rmode->efbHeight - HSD_ANTIALIAS_OVERLAP);
    n_xfb_lines = GXSetDispCopyYScale(lbl_805E5B70);
    GXSetDispCopyDst(rmode->fbWidth, n_xfb_lines);
}

void HSD_VICopyEFB2XFBPtr(HSD_VIStatus* vi, void* buffer, HSD_RenderPass rpass)
{
    GXRenderModeObj* rmode = &vi->rmode;
    s32 n_xfb_lines;
    u16 lines;
    u32 offset;

    GXSetCopyFilter(rmode->aa, rmode->sample_pattern, vi->vf, rmode->vfilter);
    GXSetDispCopyGamma(vi->gamma);

    HSD_StateSetColorUpdate(vi->update_clr);
    HSD_StateSetAlphaUpdate(vi->update_alpha);
    HSD_StateSetZMode(vi->update_z, GX_LEQUAL, GX_TRUE);

    GXSetCopyClear(vi->clear_clr, vi->clear_z);

    switch (rpass) {
    case HSD_RP_SCREEN:
        GXSetCopyClamp(GX_CLAMP_TOP | GX_CLAMP_BOTTOM);
        fn_803CC5C4(0, 0, rmode->fbWidth, rmode->efbHeight);
        n_xfb_lines = GXSetDispCopyYScale((f32) (rmode->xfbHeight) /
                                          (f32) (rmode->efbHeight));
        GXSetDispCopyDst(rmode->fbWidth, n_xfb_lines);
        GXCopyDisp(buffer, GX_TRUE);
        break;

    case HSD_RP_TOPHALF:
        HSD_VICopyEFB2XFBHiResoAA(rmode);
        GXSetCopyClamp(GX_CLAMP_TOP);
        lines = rmode->efbHeight - HSD_ANTIALIAS_OVERLAP;
        fn_803CC5C4(0, 0, rmode->fbWidth, lines);
        GXCopyDisp(buffer, GX_TRUE);
        GXPixModeSync();
        return;

    case HSD_RP_BOTTOMHALF:
        HSD_VICopyEFB2XFBHiResoAA(rmode);
        GXSetCopyClamp(GX_CLAMP_BOTTOM);
        lines = rmode->efbHeight - HSD_ANTIALIAS_OVERLAP;
        fn_803CC5C4(0, HSD_ANTIALIAS_OVERLAP, rmode->fbWidth, lines);
        offset = (VIPadFrameBufferWidth(rmode->fbWidth) * lines *
                  (u32) VI_DISPLAY_PIX_SZ);
        GXCopyDisp((void*) ((u32) buffer + offset), GX_TRUE);
        fn_803CC5C4(0, 0, rmode->fbWidth, HSD_ANTIALIAS_OVERLAP);
        GXSetCopyClamp(GX_CLAMP_TOP | GX_CLAMP_BOTTOM);
        GXCopyDisp((void*) lbl_80589C80, GX_TRUE);
        break;

    default:
        HSD_Panic(kar_srcfile_video_c_805dcc38, 0x207, lbl_80503E8C);
    }

    GXPixModeSync();
}

static inline s32 HSD_VIGetXFBDrawEnable(void)
{
    bool intr;
    s32 idx = -1;

    if (_p->nb_xfb < 2) {
        goto ret;
    }

    intr = OSDisableInterrupts();

    if ((idx = HSD_VISearchXFBByStatus(HSD_VI_XFB_DRAWING)) == -1) {
        if ((idx = HSD_VISearchXFBByStatus(HSD_VI_XFB_FREE)) != -1) {
            _p->xfb[idx].status = HSD_VI_XFB_DRAWING;
        }
    }

    OSRestoreInterrupts(intr);

ret:
    return idx;
}

static inline s32 HSD_VIWaitXFBDrawEnable(void)
{
    s32 idx = -1;

    if (_p->nb_xfb < 2) {
        goto ret;
    }

    while ((idx = HSD_VIGetXFBDrawEnable()) == -1) {
        VIWaitForRetrace();
    }

ret:
    return idx;
}

static inline void HSD_VISetXFBWaitDone(s32 idx)
{
    bool intr;

    intr = OSDisableInterrupts();

    assert_line_named(0x24E, _p->xfb[idx].status == HSD_VI_XFB_DRAWING,
                      lbl_80503EB0);

    _p->xfb[idx].status = HSD_VI_XFB_WAITDONE;
    _p->xfb[idx].vi_all = _p->current;
    _p->current.chg_flag = 0;

    OSRestoreInterrupts(intr);
}

static inline void HSD_VIGXSetDrawDone(s32 arg)
{
    while (HSD_VIGetDrawDoneWaitingFlag()) {
        GXWaitDrawDone();
    }
    _p->drawdone.waiting = 1;
    _p->drawdone.arg = arg;
    fn_803CBDB8();
}

void HSD_VICopyXFBAsync(HSD_RenderPass rpass)
{
    s32 idx;

    if (_p->nb_xfb < 2) {
        return;
    }

    idx = HSD_VIWaitXFBDrawEnable();
    HSD_VICopyEFB2XFBPtr(&_p->current.vi, _p->xfb[idx].buffer, rpass);
    HSD_VISetXFBWaitDone(idx);

    HSD_VIGXSetDrawDone(idx);
}

void HSD_VIDrawDoneXFB(s32 idx)
{
    bool intr;

    intr = OSDisableInterrupts();

    assert_line_named(0x2D2, _p->xfb[idx].status == HSD_VI_XFB_WAITDONE,
                      lbl_80503EDC);

    _p->xfb[idx].status = HSD_VISearchXFBByStatus(HSD_VI_XFB_NEXT) != -1
                              ? HSD_VI_XFB_DRAWDONE
                              : HSD_VI_XFB_NEXT;

    OSRestoreInterrupts(intr);
}

static inline s32 HSD_VIWaitXFBFlush_sub(void)
{
    bool intr;
    s32 val;

    intr = OSDisableInterrupts();

    val = (HSD_VISearchXFBByStatus(HSD_VI_XFB_WAITDONE) != -1 ||
           HSD_VISearchXFBByStatus(HSD_VI_XFB_DRAWDONE) != -1 ||
           HSD_VISearchXFBByStatus(HSD_VI_XFB_NEXT) != -1)
              ? 1
              : 0;

    OSRestoreInterrupts(intr);

    return val;
}

void HSD_VIWaitXFBFlush(void)
{
    if (_p->nb_xfb < 2) {
        return;
    }

    while (HSD_VIWaitXFBFlush_sub()) {
        VIWaitForRetrace();
    }
}

void HSD_VIWaitXFBFlushNoYield(void)
{
    if (_p->nb_xfb < 2) {
        return;
    }

    while (HSD_VIWaitXFBFlush_sub()) {
    }
}

s32 HSD_VIGetXFBLastDrawDone(void)
{
    bool intr;
    s32 idx = -1;

    intr = OSDisableInterrupts();

    if ((idx = HSD_VISearchXFBByStatus(HSD_VI_XFB_WAITDONE)) == -1) {
        if ((idx = HSD_VISearchXFBByStatus(HSD_VI_XFB_DRAWDONE)) == -1) {
            if ((idx = HSD_VISearchXFBByStatus(HSD_VI_XFB_NEXT)) == -1) {
                idx = HSD_VISearchXFBByStatus(HSD_VI_XFB_DISPLAY);
            }
        }
    }

    OSRestoreInterrupts(intr);

    return idx;
}

void HSD_VISetConfigure(GXRenderModeObj* rmode)
{
    _p->current.vi.rmode = *rmode;
    _p->current.chg_flag = 1;
}

void HSD_VISetBlack(bool black)
{
    _p->current.vi.black = black;
    _p->current.chg_flag = 1;
}

void HSD_VIInit(HSD_VIStatus* vi, void* xfb0, void* xfb1, void* xfb2)
{
    s32 i, fbnum, idx;

    VIInit();

    _p->current.vi = *vi;
    _p->current.chg_flag = 0;
    _p->xfb[0].buffer = xfb0;
    _p->xfb[1].buffer = xfb1;
    _p->xfb[2].buffer = xfb2;

    for (i = 0, fbnum = 0; i < HSD_VI_XFB_MAX; i++) {
        _p->xfb[i].vi_all = _p->current;
        if (_p->xfb[i].buffer) {
            fbnum++;
            _p->xfb[i].status = HSD_VI_XFB_FREE;
        } else {
            _p->xfb[i].status = HSD_VI_XFB_NONE;
        }
    }

    _p->nb_xfb = fbnum;

    _p->efb.status = HSD_VI_EFB_FREE;
    _p->efb.vi_all = _p->current;

    VISetPreRetraceCallback(HSD_VIPreRetraceCB);
    VISetPostRetraceCallback(HSD_VIPostRetraceCB);

    _p->pre_cb = NULL;
    _p->post_cb = NULL;

    _p->drawdone.waiting = 0;
    _p->drawdone.arg = 0;

    fn_803CC0CC(HSD_VIGXDrawDoneCB);
    _p->drawdone.cb = NULL;

    _p->perf.frame_period = VIGetTvFormat() == VI_NTSC ? 60 : 50;
    _p->perf.frame_renew = 0;

    VIConfigure(&_p->current.vi.rmode);
    VISetBlack(_p->current.vi.black);
    VIFlush();

    idx = HSD_VISearchXFBByStatus(HSD_VI_XFB_FREE);
    HSD_VICopyEFB2XFBPtr(&_p->current.vi, _p->xfb[idx].buffer, HSD_RP_SCREEN);
}
