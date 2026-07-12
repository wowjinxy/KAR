#include <global.h>

#include <dolphin/mtx/mtxtypes.h>

#include <sysdolphin/cobj.h>
#include <sysdolphin/pslist.h>

void memset(void*, int, int);

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
extern f64 lbl_805E6040;
extern f64 lbl_805E6048;
extern f64 lbl_805E6050;
extern f32 lbl_805E6058;
extern f64 lbl_805E6060;
extern u8 lbl_805053F8[47][13];

f32 kar_pslist__near_80438898(char c, u8* color, f32 x, f32 y)
{
    s32 idx;
    u8* stroke;
    s32 n;

    if (c >= '0' && c <= '9') {
        idx = c - '0';
    } else if (c >= 'A' && c <= 'Z') {
        idx = c - 0x37;
    } else if (c >= 'a' && c <= 'z') {
        idx = c - 0x57;
    } else {
        switch (c) {
        case '.':
            GXBegin(0xB8, 0, 1);
            GX_FIFO_F32 = (f32) (lbl_805E6040 * (f64) lbl_805DCDF0 + x);
            GX_FIFO_F32 = (f32) (lbl_805E6048 * (f64) lbl_805DCDF4 + y);
            GX_FIFO_U8 = color[0];
            GX_FIFO_U8 = color[1];
            GX_FIFO_U8 = color[2];
            GX_FIFO_U8 = color[3];
            return lbl_805DCDF0;
        case ':': {
            f32 xs;
            u8 c0, c1, c2, c3;

            GXBegin(0xB8, 0, 2);
            c0 = color[0];
            c1 = color[1];
            c2 = color[2];
            c3 = color[3];
            xs = (f32) (lbl_805E6040 * (f64) lbl_805DCDF0 + x);
            GX_FIFO_F32 = xs;
            GX_FIFO_F32 = (f32) (lbl_805E6040 * (f64) lbl_805DCDF4 + y);
            GX_FIFO_U8 = c0;
            GX_FIFO_U8 = c1;
            GX_FIFO_U8 = c2;
            GX_FIFO_U8 = c3;
            GX_FIFO_F32 = xs;
            GX_FIFO_F32 = (f32) (lbl_805E6050 * (f64) lbl_805DCDF4 + y);
            GX_FIFO_U8 = c0;
            GX_FIFO_U8 = c1;
            GX_FIFO_U8 = c2;
            GX_FIFO_U8 = c3;
            return lbl_805DCDF0;
        }
        case '-':
            idx = 0x24;
            break;
        case '_':
            idx = 0x25;
            break;
        case '~':
            idx = 0x26;
            break;
        case '>':
            idx = 0x27;
            break;
        case '/':
            idx = 0x28;
            break;
        case '(':
            idx = 0x29;
            break;
        case ')':
            idx = 0x2A;
            break;
        case ',':
            idx = 0x2B;
            break;
        case '<':
            idx = 0x2C;
            break;
        case '+':
            idx = 0x2D;
            break;
        case '$':
            idx = 0x2E;
            break;
        default:
            return lbl_805DCDF0;
        }
    }

    stroke = lbl_805053F8[idx];
    n = 0;

    while (n < 0x29 && stroke[0] != 0xFF) {
        u8 c0 = color[0];
        u8 c1 = color[1];
        u8 c2 = color[2];
        u8 c3 = color[3];
        u8 p0 = stroke[0];
        u8 p1 = stroke[1];

        n += 2;
        stroke += 2;

        GXBegin(0xA8, 0, 2);
        GX_FIFO_F32 = lbl_805DCDF0 * (f32) (lbl_805E6058 * (f64) ((s32) (p0 >> 4) ^ 0x80000000) - (f64) lbl_805E6060) + x;
        GX_FIFO_F32 = lbl_805DCDF4 * (f32) (lbl_805E6058 * (f64) ((p0 & 0xF) ^ 0x80000000) - (f64) lbl_805E6060) + y;
        GX_FIFO_U8 = c0;
        GX_FIFO_U8 = c1;
        GX_FIFO_U8 = c2;
        GX_FIFO_U8 = c3;
        GX_FIFO_F32 = lbl_805DCDF0 * (f32) (lbl_805E6058 * (f64) ((p1 >> 4) ^ 0x80000000) - (f64) lbl_805E6060) + x;
        GX_FIFO_F32 = lbl_805DCDF4 * (f32) (lbl_805E6058 * (f64) ((p1 & 0xF) ^ 0x80000000) - (f64) lbl_805E6060) + y;
        GX_FIFO_U8 = c0;
        GX_FIFO_U8 = c1;
        GX_FIFO_U8 = c2;
        GX_FIFO_U8 = c3;
    }

    return lbl_805DCDF0;
}

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
    u8 pad01[3];
    u8* buf; //0x04
    u32 size; //0x08
    u32 cursor; //0x0C
    u8 pad10; //0x10
    u8 col; //0x11
    u8 pad12[2];
    u32 field14; //0x14
    u32 field18; //0x18
    u32 charCount; //0x1C
    u8 pad20[0x28 - 0x20];
} PSLogState;

extern PSLogState lbl_8058D198;

extern void HSD_SetDebugExceptionCallback(void (*callback)(u8*, u32));
extern void OSDisableInterrupts(void);
extern void OSRestoreInterrupts();

void kar_pslist__near_8043a010(u8* src, u32 count)
{
    u8* buf;
    u32 size;
    u32 cursor;
    u8 col;
    u8* p;

    OSDisableInterrupts();

    p = src;
    cursor = lbl_8058D198.cursor;
    buf = lbl_8058D198.buf;
    size = lbl_8058D198.size;
    col = lbl_8058D198.col;

    for (; count > 0; count--) {
        char c = *p;

        if (c == 0xD) {
        } else if (c < 0xD) {
            if (c == 0xA) {
                if (col != 0 || buf[(cursor + size - 1) % size] != 0) {
                    buf[cursor] = col;
                    col = 0;
                    lbl_8058D198.charCount++;
                    lbl_8058D198.field18++;
                    cursor = (cursor + 1) % size;
                }
            } else {
                col++;
                buf[cursor] = c;
                if (col == 0x36) {
                    cursor = (cursor + 1) % size;
                    buf[cursor] = col;
                    col = 0;
                    lbl_8058D198.charCount++;
                    lbl_8058D198.field18++;
                }
                lbl_8058D198.charCount++;
                cursor = (cursor + 1) % size;
            }
        } else {
            col++;
            buf[cursor] = c;
            if (col == 0x36) {
                cursor = (cursor + 1) % size;
                buf[cursor] = col;
                col = 0;
                lbl_8058D198.charCount++;
                lbl_8058D198.field18++;
            }
            lbl_8058D198.charCount++;
            cursor = (cursor + 1) % size;
        }
        p++;
    }

    lbl_8058D198.cursor = cursor;
    lbl_8058D198.col = col;

    OSRestoreInterrupts();
}

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

void kar_pslist__near_8043a1cc(u8* buf, u32 size)
{
    memset(&lbl_8058D198, 0, 0x24);
    lbl_8058D198.buf = buf;
    lbl_8058D198.size = size;
    memset(buf, 0, size);
    lbl_8058D198.hi1 = 1;
    lbl_8058D198.enabled = 1;
    HSD_SetDebugExceptionCallback(kar_pslist__near_8043a010);
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

extern char lbl_80507308[];
extern void OSReport(const char*, ...);
extern u32 OSGetPhysicalMemSize(void);

void kar_pslist__near_8043a778(u32* ctx, s32 maxDepth)
{
    char* const base = lbl_80507308;
    u32* frame;
    s32 depth;

    OSReport(base + 0x8CC);
    OSReport(base + 0x904);

    frame = (u32*) ctx[1];

    for (depth = 0; frame != NULL && frame != (u32*) 0xFFFFFFFF && depth < maxDepth;
         frame = (u32*) *frame, depth++) {
        if ((u32) frame < 0x80000000) {
            break;
        }
        if ((u32) frame + 8 > 0x80000000 + OSGetPhysicalMemSize()) {
            break;
        }
        OSReport(base + 0x924, frame, frame[0], frame[1]);
    }
}

typedef struct PSFlagDesc {
    u8 pad00[0x10];
    u32 field10; //0x10
} PSFlagDesc;

extern PSFlagDesc lbl_805085FC;
extern PSFlagDesc lbl_805084B0;

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
