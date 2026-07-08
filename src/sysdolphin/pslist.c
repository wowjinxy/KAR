#include <global.h>

#include <dolphin/mtx/mtxtypes.h>

#include <sysdolphin/cobj.h>
#include <sysdolphin/pslist.h>

#define PS_NUM_LINK 32

#define GX_FIFO_U8 (*(volatile u8*) 0xCC008000)
#define GX_FIFO_F32 (*(volatile f32*) 0xCC008000)

extern HSD_Particle* lbl_8058CCE8[PS_NUM_LINK];
extern u32 lbl_8058CD68[PS_NUM_LINK * 2];
extern HSD_Particle* lbl_805DE3E8;
extern u16 lbl_805DE366;

#define activeParticle lbl_8058CCE8

char kar_src_pslist_80505390[] = "pslist.c";

#undef assert_line
#define assert_line(line, cond) \
    ((cond) ? ((void) 0) : __assert(kar_src_pslist_80505390, line, #cond))

void _psListDelete(HSD_Particle* pp, HSD_Particle* parent)
{
    lbl_8058CD68[pp->linkNo] = 1;

    if (parent == NULL) {
        assert_line(0x88, activeParticle[pp->linkNo] == pp);
        activeParticle[pp->linkNo] = pp->next;
    } else {
        assert_line(0x8B, parent->next == pp);
        parent->next = pp->next;
    }

    pp->next = lbl_805DE3E8;
    lbl_805DE3E8 = pp;
    lbl_805DE366--;
}

HSD_Particle* _psListGetFirst(s32 linkNo)
{
    assert_line(0x98, linkNo >= 0 && linkNo < PS_NUM_LINK);
    return activeParticle[linkNo];
}

void kar_pslist__near_80438794(u8* color, f32 x, f32 y, f32 w, f32 h)
{
    u8 c0, c1, c2, c3;
    f32 x1, y1;

    GXBegin(0x80, 0, 4);

    c0 = color[0];
    GX_FIFO_F32 = x;
    x1 = x + w;
    c1 = color[1];
    y1 = y + h;
    GX_FIFO_F32 = y;
    c2 = color[2];
    GX_FIFO_U8 = c0;
    c3 = color[3];
    GX_FIFO_U8 = c1;
    GX_FIFO_U8 = c2;
    GX_FIFO_U8 = c3;

    GX_FIFO_F32 = x1;
    GX_FIFO_F32 = y;
    GX_FIFO_U8 = c0;
    GX_FIFO_U8 = c1;
    GX_FIFO_U8 = c2;
    GX_FIFO_U8 = c3;

    GX_FIFO_F32 = x1;
    GX_FIFO_F32 = y1;
    GX_FIFO_U8 = c0;
    GX_FIFO_U8 = c1;
    GX_FIFO_U8 = c2;
    GX_FIFO_U8 = c3;

    GX_FIFO_F32 = x;
    GX_FIFO_F32 = y1;
    GX_FIFO_U8 = c0;
    GX_FIFO_U8 = c1;
    GX_FIFO_U8 = c2;
    GX_FIFO_U8 = c3;
}

extern f32 lbl_805DCDF0;
extern f32 lbl_805DCDF4;
extern u8 lbl_805DCDF8;

void kar_pslist__near_80438c50(f32 lineWidth, f32 pointSize, u8 flag)
{
    Mtx mtx;

    lbl_805DCDF0 = lineWidth;
    lbl_805DCDF4 = pointSize;
    lbl_805DCDF8 = flag;

    HSD_ClearVtxDesc();
    GXSetCurrentMtx(0);
    HSD_CObjGetViewingMtx(HSD_CObjGetCurrent(), mtx);
    GXLoadPosMtxImm(mtx, 0);
    HSD_StateSetLineWidth(lbl_805DCDF8, 5);
    HSD_StateSetPointSize((u8) (lbl_805DCDF8 << 1), 5);
    HSD_SetupRenderMode(0x68000002);
    GXSetVtxAttrFmt(0, 9, 0, 4, 0);
    GXSetVtxAttrFmt(0, 0xb, 1, 5, 0);
    GXSetVtxDesc(9, 1);
    GXSetVtxDesc(0xb, 1);
    HSD_StateSetCullMode(0);
}

void fn_80439480(u8* dst, u32 rowIdx, s32 unused0, u32 unused1, u8* entry)
{
    dst[0] = entry[0];
    dst[1] = (rowIdx & 1) ? entry[2] : entry[1];
}

extern HSD_SList* lbl_805DE3F0;

void kar_pslist__near_8043979c(void)
{
    lbl_805DE3F0 = NULL;
}

extern void* lbl_805DCE00;

void kar_pslist__near_804397a8(void** p)
{
    lbl_805DCE00 = *p;
}

typedef struct PSListEntry {
    void* key;
    s32 priority;
} PSListEntry;

extern void* HSD_Alloc(u32 size);
extern HSD_SList* HSD_SListAppend(HSD_SList* node, void* data);
extern HSD_SList* HSD_SListPrepend(HSD_SList* node, void* data);

void kar_pslist__near_804397b4(void* key)
{
    HSD_SList* list;
    HSD_SList* insertAfter;
    PSListEntry* item;

    insertAfter = NULL;
    for (list = lbl_805DE3F0; list != NULL; list = list->next) {
        item = list->data;
        if (key == item->key) {
            return;
        }
        if (item->priority <= 0x80) {
            insertAfter = list;
        }
    }

    item = HSD_Alloc(8);
    item->key = key;
    item->priority = 0x80;

    if (insertAfter != NULL) {
        HSD_SListAppend(insertAfter, item);
    } else {
        lbl_805DE3F0 = HSD_SListPrepend(lbl_805DE3F0, item);
    }
}

extern void* lbl_805DCE08;
extern void* lbl_805DCE0C;
extern s32 lbl_805DE428;
extern f32 lbl_805E60C8;
extern f32 lbl_805DE41C;
extern f32 lbl_805DE420;
extern f32 lbl_805DE424;

void kar_pslist__near_80439d14(void* a, void* b, s32 enable)
{
    s32 prev = lbl_805DE428;

    lbl_805DCE08 = a;
    lbl_805DCE0C = b;

    if (prev == 0 && enable != 0) {
        lbl_805DE41C = lbl_805E60C8;
        lbl_805DE420 = lbl_805E60C8;
        lbl_805DE424 = lbl_805E60C8;
    }

    lbl_805DE428 = enable;
}

typedef struct PSLogState {
    u8 hi1 : 1; //0x00
    u8 enabled : 1;
    u8 rest : 6;
    u8 pad01[0x13];
    u32 field14; //0x14
    u32 field18; //0x18
    u8 pad1c[0x28 - 0x1C];
} PSLogState;

extern PSLogState lbl_8058D198;

extern void kar_pslist__near_8043a010(s32 count, u8* buf);
extern void HSD_SetDebugExceptionCallback(void (*callback)(s32, u8*));

s32 kar_pslist__near_8043a15c(s32 enable)
{
    u8 flags = *(u8*) &lbl_8058D198;
    s32 wasEnabled = (flags >> 6) & 1;

    if (enable) {
        lbl_8058D198.enabled = 1;
        HSD_SetDebugExceptionCallback(kar_pslist__near_8043a010);
    } else {
        lbl_8058D198.enabled = 0;
        HSD_SetDebugExceptionCallback(NULL);
    }

    return wasEnabled;
}

void kar_pslist__near_8043a264(u32* out1, u32* out2)
{
    if (out1 != NULL) {
        *out1 = lbl_8058D198.field14;
    }
    if (out2 != NULL) {
        *out2 = lbl_8058D198.field18;
    }
}

typedef struct PSFlagDesc {
    u8 pad00[0x10];
    u32 field10; //0x10
} PSFlagDesc;

extern PSFlagDesc lbl_805085FC;
extern PSFlagDesc lbl_805084B0;
extern u32 OSGetPhysicalMemSize(void);

void kar_pslist__near_8043c914(void)
{
    u32 flags = lbl_805085FC.field10;
    u32 memSize = OSGetPhysicalMemSize();

    lbl_805084B0.field10 = ((flags & 0x0FFFFFFF) + memSize) % memSize + 0x80000000;
}

void fn_8043D520(void) {}

void kar_pslist__near_8043d524(void)
{
    lbl_805085FC.field10 = (lbl_805085FC.field10 & 0x0FFFFFF0) | 0x80000000;
}

void fn_8043E018(void) {}

void fn_8043E6E8(void) {}
void fn_8043E6EC(void) {}
void fn_8043E6F0(void) {}
void fn_8043E6F4(void) {}
void fn_8043E6F8(void) {}
void fn_8043E6FC(void) {}
void fn_8043E700(void) {}
void fn_8043E704(void) {}
void fn_8043E708(void) {}
void fn_8043E70C(void) {}
void fn_8043E710(void) {}
void fn_8043E714(void) {}
void fn_8043E718(void) {}
void kar_pslist__near_8043e71c(void) {}

void fn_8043F0A0(void) {}
