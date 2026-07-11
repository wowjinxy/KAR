#include <global.h>

#include <stdarg.h>

#include <dolphin/mtx/mtxtypes.h>
#include <dolphin/os.h>

#include <sysdolphin/gobj.h>
#include <sysdolphin/cobj.h>
#include <sysdolphin/video.h>

typedef struct OSContext OSContext;

typedef struct {
    u8 pad[0x2FC];
} OSThread;

typedef void (*HSD_DebugConsoleCallback)(void* context, ...);
typedef void (*OSErrorHandler)(s32 error, void* context, ...);

extern void OSLoadContext(OSContext* context);
extern void __OSSetExceptionHandler(s32 exception,
                                    void (*handler)(s32, OSContext*));
extern OSThread* OSCreateThread(OSThread* thread, void* (*func)(void*),
                                void* param, void* stack, u32 stack_size,
                                s32 priority, u16 attr);
extern void OSResumeThread(OSThread* thread);

extern BOOL DBIsDebuggerPresent(void);
extern HSD_DebugConsoleCallback
HSD_SetDebugConsoleCallback(HSD_DebugConsoleCallback callback);
extern OSErrorHandler OSSetErrorHandler(u16 error, OSErrorHandler handler);

extern BOOL HSD_CObjSetCurrent(HSD_CObj* cobj);
extern HSD_GObj* GObj_SetupGXLinkMax(HSD_GObj* gobj,
                                     void (*render_cb)(HSD_GObj*, s32),
                                     u8 priority);

extern void fn_803DCC94(s32 unk0);
extern u32 fn_803DF400(void);
extern void fn_803D586C(const u32* a, const s32* b, const char* msg);

const s32 lbl_805E60E0 = -1;
const u32 lbl_805E60E4 = 0xFF;

extern s32 kar_pslist__near_8043a15c(s32 enable);
extern void kar_pslist__near_8043f5d4(void);
extern void kar_pslist__near_8043f240(void);
extern void kar_pslist__near_8043a778(void* context, s32 max_len);
extern void kar_pslist__near_8043aa00(s32 error, u32 a, u32 b, void* context);
extern void kar_pslist__near_804397b4(void* key);
extern void kar_pslist__near_80439d14(void* a, void* b, s32 enable);
extern void kar_pslist__near_80439d48(void);
extern void kar_pslist__near_80439c40(void);
extern void kar_pslist__near_80439854(void);

typedef struct _DCCallbackNode {
    struct _DCCallbackNode* next;
    u8 pad_04[0xc - 0x4];
    s32 (*func)(struct _DCCallbackNode* node);
} DCCallbackNode;

typedef struct {
    u8 bit0 : 1;
    u8 bit1 : 1;
    u8 running : 1;
    u8 rest : 5;
    u8 pad_01[0x04 - 0x01];
    u32 field_04; //0x04
    u32 field_08; //0x08
    u8 pad_0C[0x14 - 0x0C];
    u32 field_14; //0x14
    u32 field_18; //0x18
    u32 field_1C; //0x1C
    u32 field_20; //0x20
    void* screens[2]; //0x24
    void* alt_screen; //0x2C
    GXRenderModeObj* rmode; //0x30
    s32 cur_screen; //0x34
    s32 screen_count; //0x38
    u32 fb_width; //0x3C
    u32 efb_height; //0x40
    u32 scale_a; //0x44
    u32 scale_b; //0x48
    u8* font; //0x4C
    u32 field_50; //0x50
    u8 pad_54[0xC0 - 0x54];
    u32 buttons; //0xC0
    u32 field_C4; //0xC4
    u8 pad_C8[0xD0 - 0xC8];
    DCCallbackNode* callbacks; //0xD0
    void* value; //0xD4
} DCConsoleState;

extern DCConsoleState lbl_8058D1C0;
u8 lbl_8058D298[0x1000];

typedef struct {
    GXRenderModeObj rmode;
    u8 pad[0x58 - sizeof(GXRenderModeObj)];
} DCVICurrent;

typedef struct {
    void* buffer;
    s32 status;
    DCVICurrent vi_all;
} DCVIXfb;

typedef struct {
    DCVICurrent current;
    DCVIXfb xfb[3];
    struct {
        s32 status;
        DCVICurrent vi_all;
    } efb;
    s32 nb_xfb;
    void* pre_cb;
    void* post_cb;
    struct {
        s32 waiting;
        s32 arg;
        void* cb;
    } drawdone;
    struct {
        s32 frame_period;
        s32 frame_renew;
    } perf;
} DCVIInfo;

extern DCVIInfo lbl_80589A80;

u32 lbl_805DE430;
s32 lbl_805DE434;
extern s32 lbl_805DE480;

extern u8 kar_debugconsole_font_i4_8x14[];
extern char lbl_80507308[];

typedef struct _DCInstallNode {
    struct _DCInstallNode* next;
    s32 (*func)(struct _DCInstallNode* node);
} DCInstallNode;

void* kar_debugconsole_main__8043f820(void)
{
    char* base = lbl_80507308;
    u32 prev;
    u32 v;
    u32 seed;

#define DC_WAIT_FOR(target)                                                  \
    do {                                                                     \
        seed = fn_803DF400();                                                \
        do {                                                                 \
            v = fn_803DF400();                                               \
        } while (v == seed);                                                 \
        prev = v;                                                            \
        do {                                                                 \
            kar_pslist__near_8043f5d4();                                     \
            do {                                                             \
                v = fn_803DF400();                                           \
            } while (v == prev);                                             \
            prev = v;                                                        \
        } while (lbl_8058D1C0.buttons != (target));                          \
    } while (0)

    fn_803DCC94(0);

    if (lbl_805DE434 == 0) {
        DC_WAIT_FOR(0);
        DC_WAIT_FOR(0x70);
        DC_WAIT_FOR(0);
        DC_WAIT_FOR(0x808);
        DC_WAIT_FOR(0);
        DC_WAIT_FOR(0x104);
        DC_WAIT_FOR(0);
        DC_WAIT_FOR(0x201);
        DC_WAIT_FOR(0);
        DC_WAIT_FOR(0x402);
    } else if (lbl_805DE430 != 0) {
        u32 target = fn_803DF400() + lbl_805DE430;
        do {
            v = fn_803DF400();
        } while (target > v);
    }

#undef DC_WAIT_FOR

    VIConfigure(lbl_8058D1C0.rmode);
    VISetPreRetraceCallback(NULL);
    VISetPostRetraceCallback(NULL);
    VISetBlack(FALSE);

    if (lbl_805DE434 == 0) {
        DCCallbackNode* old = lbl_8058D1C0.callbacks;
        DCInstallNode* node;

        while (old != NULL) {
            DCCallbackNode* next = old->next;
            old->next = NULL;
            old = next;
        }

        lbl_8058D1C0.callbacks = NULL;
        if ((node = (DCInstallNode*) (base + 0xf6c)) != NULL) {
            node->next = NULL;
            lbl_8058D1C0.callbacks = (DCCallbackNode*) node;
            if (node->func != NULL) {
                node->func(node);
            }
        }
        lbl_8058D1C0.running = 1;
    } else {
        DCCallbackNode* old = lbl_8058D1C0.callbacks;
        DCInstallNode* node;

        while (old != NULL) {
            DCCallbackNode* next = old->next;
            old->next = NULL;
            old = next;
        }

        lbl_8058D1C0.callbacks = NULL;
        if ((node = (DCInstallNode*) (base + 0xf58)) != NULL) {
            node->next = NULL;
            lbl_8058D1C0.callbacks = (DCCallbackNode*) node;
            if (node->func != NULL) {
                node->func(node);
            }
        }
        lbl_8058D1C0.running = 1;
    }

    kar_pslist__near_8043f240();

    VISetNextFrameBuffer(lbl_8058D1C0.screens[lbl_8058D1C0.cur_screen]);

    VIFlush();

    prev = fn_803DF400();
    do {
        v = fn_803DF400();
    } while (v == prev);
    prev = v;

    while (lbl_8058D1C0.callbacks != NULL) {
        DCCallbackNode* node;
        s32 r;

        kar_pslist__near_8043f5d4();

        do {
            lbl_8058D1C0.running = 0;
            node = lbl_8058D1C0.callbacks;

            do {
                if (node->func != NULL) {
                    r = node->func(node);
                    if (r != 0) {
                        goto do_swap;
                    }
                }
                node = node->next;
            } while (node != NULL && !lbl_8058D1C0.running);
        } while (lbl_8058D1C0.running);

        r = 0;

    do_swap:
        if (r != 0) {
            lbl_8058D1C0.cur_screen =
                (lbl_8058D1C0.cur_screen + 1) % lbl_8058D1C0.screen_count;
            kar_pslist__near_8043f240();
            VISetNextFrameBuffer(
                lbl_8058D1C0.screens[lbl_8058D1C0.cur_screen]);
            VIFlush();
        }

        do {
            v = fn_803DF400();
        } while (v == prev);
        prev = v;
    }

    OSPanic(base + 0x1598, 0x946, base + 0x15ac);
    return NULL;
}

void kar_debugconsole_main__near_8043fd04(s32 exception, OSContext* context)
{
    OSLoadContext(context);
}

char lbl_805088CC[] =
    "Debug console invoked before\ninitializing sysdolphin baselib.";

void kar_debugconsole_main__near_8043fd28(void* value)
{
    s32 last;
    s32 n;
    s32 i;
    void* buf;

    kar_pslist__near_8043a15c(0);
    memset(&lbl_8058D1C0, 0, sizeof(lbl_8058D1C0));

    HSD_VIWaitXFBFlushNoYield();
    last = HSD_VIGetXFBLastDrawDone();

    if (last != -1) {
        lbl_8058D1C0.alt_screen = lbl_80589A80.xfb[last].buffer;
    }

    n = lbl_80589A80.nb_xfb;
    buf = NULL;
    for (i = 0; i < n; i++) {
        if (i == last) {
            continue;
        }
        buf = lbl_80589A80.xfb[i].buffer;
        lbl_8058D1C0.screens[0] = buf;
        if (buf != NULL) {
            break;
        }
    }

    i++;
    buf = NULL;
    for (; i < n; i++) {
        if (i == last) {
            continue;
        }
        buf = lbl_80589A80.xfb[i].buffer;
        lbl_8058D1C0.screens[1] = buf;
        if (buf != NULL) {
            break;
        }
    }

    if (lbl_8058D1C0.screens[0] == NULL) {
        u32* alt = (u32*) &lbl_8058D1C0.alt_screen;
        if (alt != NULL) {
            lbl_8058D1C0.screens[0] = lbl_8058D1C0.alt_screen;
            *alt = 0;
        }
    }

    if (lbl_8058D1C0.screens[0] == NULL) {
        fn_803D586C(&lbl_805E60E4, &lbl_805E60E0, lbl_805088CC);
    } else {
        u32 count = lbl_8058D1C0.screens[1] != NULL ? 2 : 1;
        u32 w;
        u32 h;

        lbl_8058D1C0.rmode = (GXRenderModeObj*) &lbl_80589A80;
        lbl_8058D1C0.screen_count = count;
        lbl_8058D1C0.cur_screen = 0;

        w = lbl_80589A80.current.rmode.fbWidth;
        lbl_8058D1C0.fb_width = w;
        lbl_8058D1C0.scale_a = ((u16) (w + 15)) >> 4;

        h = lbl_80589A80.current.rmode.xfbHeight;
        lbl_8058D1C0.efb_height = h;

        lbl_8058D1C0.field_04 = 0;
        lbl_8058D1C0.field_08 = h;
        lbl_8058D1C0.scale_b = lbl_8058D1C0.scale_a * h;
        lbl_8058D1C0.field_18 = 0;
        lbl_8058D1C0.field_14 = 0;
        lbl_8058D1C0.field_20 = (w - 40) / 11;
        lbl_8058D1C0.field_1C = (h - 80) / 14;
        lbl_8058D1C0.font = kar_debugconsole_font_i4_8x14;
        lbl_8058D1C0.field_50 = 0;
        lbl_8058D1C0.field_C4 = 0;
    }

    lbl_8058D1C0.value = value;

    __OSSetExceptionHandler(8, kar_debugconsole_main__near_8043fd04);

    {
        OSThread thread;
        OSCreateThread(&thread,
                       (void* (*)(void*)) kar_debugconsole_main__8043f820,
                       NULL, &lbl_8058D298[0x1000 - 4], 0x1000, 0, 1);
        OSResumeThread(&thread);
    }
}

void kar_debugconsole_main__near_8043ffac(s32 value)
{
    lbl_805DE434 = value;
}

void kar_debugconsole_main__near_8043ffb4(u32 size)
{
    lbl_805DE430 = (size + 15) >> 4;
}

void kar_debugconsole_main__near_8043ffc4(void* context, ...)
{
    kar_pslist__near_8043a778(context, 0x10);
    kar_debugconsole_main__near_8043fd28(context);
}

void kar_debugconsole_main__near_80440044(s32 error, void* context, ...)
{
    va_list ap;
    u32 a;
    u32 b;

    va_start(ap, context);
    a = va_arg(ap, u32);
    b = va_arg(ap, u32);

    kar_pslist__near_8043a778(context, 0x10);
    kar_pslist__near_8043aa00(error, a, b, context);
    kar_debugconsole_main__near_8043fd28(context);
}

void kar_debugconsole_main__near_80440130(HSD_DebugConsoleCallback console_cb,
                                          OSErrorHandler handler,
                                          u32 invert_mask)
{
    u16 i;
    s32 enable;

    if (console_cb == NULL) {
        console_cb = kar_debugconsole_main__near_8043ffc4;
    }
    if (handler == NULL) {
        handler = kar_debugconsole_main__near_80440044;
    }

    if (!DBIsDebuggerPresent()) {
        HSD_SetDebugConsoleCallback(console_cb);
    }

    for (i = 0; i < 17; i++) {
        switch (i) {
        case 4:
        case 7:
        case 8:
        case 9:
        case 16:
            enable = 0;
            break;
        case 6:
        case 10:
        case 12:
            if (DBIsDebuggerPresent()) {
                continue;
            }
            enable = 1;
            break;
        default:
            enable = 1;
            break;
        }

        if ((1 << i) & invert_mask) {
            enable = !enable;
        }

        if (enable) {
            OSSetErrorHandler(i, handler);
        }
    }
}

char lbl_80508948[] = "unsupported no. of special purpose register (%d).";

s32 kar_debugconsole_main__near_80440240(s32 reg)
{
    switch (reg) {
    default:
        OSReport(lbl_80508948, reg);
        return 0;
    }
}

void kar_debugconsole_main__near_80440718(HSD_GObj* gobj)
{
    HSD_CObjSetCurrent((HSD_CObj*) gobj->hsd_obj);
    kar_pslist__near_80439c40();
    kar_pslist__near_80439854();
}

typedef struct _DCCamWObjDesc {
    char* class_name;
    Vec pos;
    struct _DCCamWObjDesc* next;
} DCCamWObjDesc;

DCCamWObjDesc lbl_80508980 = {
    NULL,
    {0.0F, 0.0F, 1.0F},
    NULL,
};

DCCamWObjDesc lbl_80508994 = {
    NULL,
    {0.0F, 0.0F, 0.0F},
    NULL,
};

typedef struct _DCCamDesc {
    char* class_name;
    u16 flags;
    u16 projection_type;
    s16 viewport_left;
    s16 viewport_right;
    s16 viewport_top;
    s16 viewport_bottom;
    u16 scissor_left;
    u16 scissor_right;
    u16 scissor_top;
    u16 scissor_bottom;
    DCCamWObjDesc* eye_desc;
    DCCamWObjDesc* interest_desc;
    f32 roll;
    Vec* vector;
    f32 near;
    f32 far;
    f32 top;
    f32 bottom;
    f32 left;
    f32 right;
} DCCamDesc;

DCCamDesc lbl_805089A8 = {
    NULL,
    0,
    3,
    0, 0x280, 0, 0x1E0,
    0, 0x280, 0, 0x1E0,
    &lbl_80508980,
    &lbl_80508994,
    0.0F,
    NULL,
    0.0F,
    32768.0F,
    -445.0F, 35.0F, -20.0F, 620.0F,
};

HSD_GObj* kar_debugconsole_main__near_80440744(u16 classifier, u8 p_link,
                                               u8 priority, u8 gx_prio)
{
    HSD_GObj* gobj = HSD_GObjCreate(classifier, p_link, priority);
    HSD_CObj* cobj;

    if (gobj == NULL) {
        return NULL;
    }

    cobj = HSD_CObjLoadDesc((HSD_CObjDesc*) &lbl_805089A8);
    HSD_GObjObjectLink(gobj, hsdGObj_default_object_kind, cobj);
    GObj_SetupGXLinkMax(gobj,
                        (void (*)(HSD_GObj*, s32))
                            kar_debugconsole_main__near_80440718,
                        gx_prio);
    kar_pslist__near_804397b4(kar_pslist__near_80439d48);
    kar_pslist__near_80439d14((void*) 4, (void*) 1, 0);
    return gobj;
}

s32 kar_debugconsole_main__near_804407d8(void)
{
    return lbl_805DE480;
}
