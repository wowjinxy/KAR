#include <global.h>

#include <dolphin/mtx/mtxtypes.h>

#include <sysdolphin/cobj.h>
#include <sysdolphin/perf.h>
#include <sysdolphin/pslist.h>

void memset(void*, int, int);
void memcpy(void*, void*, int);

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

typedef struct PSParticleBucket {
    HSD_Particle* head;
    HSD_Particle* tail;
} PSParticleBucket;

HSD_Particle* kar_pslist__near_8043845c(s32 linkNo, void** outHead0, void** outHead1)
{
    HSD_Particle* p;
    HSD_Particle* next;
    HSD_Particle* head0;
    HSD_Particle* head1;
    HSD_Particle* tail0;
    HSD_Particle* tail1;
    HSD_Particle* result;
    PSParticleBucket buckets[16];
    HSD_Particle** heads = activeParticle;
    s32* dirty = (s32*) ((u8*) activeParticle + 0x80);
    s32 bucket;
    s32 i;

    p = heads[linkNo];

    if (!dirty[linkNo]) {
        if (p == NULL) {
            *outHead0 = NULL;
            *outHead1 = NULL;
            return NULL;
        }
        if (p->kind & 8) {
            *outHead0 = p;
        } else {
            *outHead0 = NULL;
        }
        *outHead1 = (void*) ((u32*) ((u8*) activeParticle + 0x100))[linkNo];
        return p;
    }

    dirty[linkNo] = 0;

    if (p == NULL) {
        ((u32*) ((u8*) activeParticle + 0x100))[linkNo] = 0;
        *outHead0 = NULL;
        *outHead1 = NULL;
        return NULL;
    }

    memset(buckets, 0, sizeof(buckets));

    bucket = ((p->kind >> 0x19) & 7) + (((p->kind >> 3) & 1) ^ 1) * 8;
    buckets[bucket].head = p;
    next = p->next;

    while (next != NULL) {
        if ((p->kind ^ next->kind) & 0x0E000008) {
            buckets[bucket].tail = p;
            bucket = ((next->kind >> 0x19) & 7) + (((next->kind >> 3) & 1) ^ 1) * 8;
            if (buckets[bucket].head == NULL) {
                buckets[bucket].head = next;
            } else {
                buckets[bucket].tail->next = next;
            }
        }
        p = next;
        next = next->next;
    }
    buckets[bucket].tail = p;

    head0 = NULL;
    tail0 = NULL;
    for (i = 0; i < 8; i++) {
        if (buckets[i].head != NULL) {
            if (head0 == NULL) {
                head0 = buckets[i].head;
            } else {
                tail0->next = buckets[i].head;
            }
            tail0 = buckets[i].tail;
        }
    }

    head1 = NULL;
    tail1 = NULL;
    for (i = 8; i < 16; i++) {
        if (buckets[i].head != NULL) {
            if (head1 == NULL) {
                head1 = buckets[i].head;
            } else {
                tail1->next = buckets[i].head;
            }
            tail1 = buckets[i].tail;
        }
    }

    result = NULL;
    if (tail0 != NULL) {
        result = head0;
        tail0->next = head1;
    }
    if (tail1 != NULL) {
        if (result == NULL) {
            result = head1;
        }
        tail1->next = NULL;
    }

    heads[linkNo] = result;
    ((u32*) ((u8*) activeParticle + 0x100))[linkNo] = (u32) head1;
    *outHead0 = head0;
    *outHead1 = head1;
    return result;
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

extern HSD_PerfStat HSD_PerfLastStat;
extern f32 lbl_805DE3F8;
extern f32 lbl_805DE3FC;
extern f32 lbl_805DE400;
extern f32 lbl_805DE404;
extern f32 lbl_805DE408;
extern f32 lbl_805DE40C;
extern s32 lbl_805DE410;
extern s32 lbl_805DE414;
extern s32 lbl_805DE418;
extern f32 lbl_805DE41C;
extern f32 lbl_805DE420;
extern f32 lbl_805DE424;

void kar_pslist__near_80439c40(void)
{
    lbl_805DE3F8 = HSD_PerfLastStat.cpu_time;
    lbl_805DE3FC = HSD_PerfLastStat.draw_time;
    lbl_805DE400 = HSD_PerfLastStat.total_time;

    if (lbl_805DE404 < HSD_PerfLastStat.cpu_time || lbl_805DE410-- < 0) {
        lbl_805DE404 = HSD_PerfLastStat.cpu_time;
        lbl_805DE410 = 0x3C;
    }
    if (lbl_805DE408 < HSD_PerfLastStat.draw_time || lbl_805DE414-- < 0) {
        lbl_805DE408 = HSD_PerfLastStat.draw_time;
        lbl_805DE414 = 0x3C;
    }
    if (lbl_805DE40C < HSD_PerfLastStat.total_time || lbl_805DE418-- < 0) {
        lbl_805DE40C = HSD_PerfLastStat.total_time;
        lbl_805DE418 = 0x3C;
    }
    if (lbl_805DE41C < HSD_PerfLastStat.cpu_time) {
        lbl_805DE41C = HSD_PerfLastStat.cpu_time;
    }
    if (lbl_805DE420 < HSD_PerfLastStat.draw_time) {
        lbl_805DE420 = HSD_PerfLastStat.draw_time;
    }
    if (lbl_805DE424 < HSD_PerfLastStat.total_time) {
        lbl_805DE424 = HSD_PerfLastStat.total_time;
    }
}

extern void* lbl_805DCE08;
extern void* lbl_805DCE0C;
extern s32 lbl_805DE428;
extern f32 lbl_805E60C8;

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
    u32 field20; //0x20
    u8 pad24[0x28 - 0x24];
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

void kar_pslist__near_8043a298(u32 newCol, u32 maxLines)
{
    u32 lineCount;
    u32 scanPos;
    u32 marker;

    if (!lbl_8058D198.hi1) {
        return;
    }

    marker = lbl_8058D198.col;
    lineCount = 0;
    scanPos = marker;

    while (lineCount < maxLines && scanPos < lbl_8058D198.size) {
        scanPos++;
        lineCount++;
        marker = lbl_8058D198.buf[(lbl_8058D198.cursor + lbl_8058D198.size - scanPos) % lbl_8058D198.size];
        scanPos += marker;
    }

    lbl_8058D198.field18 = lineCount;
    lbl_8058D198.charCount = scanPos;
    lbl_8058D198.field20 = marker;

    if (newCol < marker) {
        lbl_8058D198.field14 = newCol;
        return;
    }
    lbl_8058D198.field14 = marker;
}

void kar_pslist__near_8043a324(s32 dCol, s32 dLine)
{
    if (!lbl_8058D198.hi1) {
        return;
    }

    if (lbl_8058D198.charCount >= lbl_8058D198.size) {
        s32 newCol = lbl_8058D198.field14 + dCol;

        if (lbl_8058D198.hi1) {
            u32 lineCount = 0;
            u32 scanPos = lbl_8058D198.col;
            u32 marker = lbl_8058D198.col;

            while (lineCount < (u32) dLine && scanPos < lbl_8058D198.size) {
                scanPos++;
                lineCount++;
                marker = lbl_8058D198.buf[(lbl_8058D198.cursor + lbl_8058D198.size - scanPos) % lbl_8058D198.size];
                scanPos += marker;
            }

            lbl_8058D198.field18 = lineCount;
            lbl_8058D198.charCount = scanPos;
            lbl_8058D198.field20 = marker;

            if (newCol < marker) {
                lbl_8058D198.field14 = newCol;
                return;
            }
            lbl_8058D198.field14 = marker;
        }
    } else {
        u32 lineCount = lbl_8058D198.charCount;
        u32 marker = lbl_8058D198.field20;

        if (dLine > 0) {
            u32 n = 0;

            while (n < (u32) dLine && lineCount < lbl_8058D198.size) {
                lineCount++;
                n++;
                marker = lbl_8058D198.buf[(lbl_8058D198.cursor + lbl_8058D198.size - lineCount) % lbl_8058D198.size];
                lineCount += marker;
            }

            lbl_8058D198.charCount = lineCount;
            lbl_8058D198.field18 += n;

            if (dCol >= 0) {
                s32 newCol = lbl_8058D198.field14 + dCol;
                lbl_8058D198.field14 = newCol;
                if (newCol > marker) {
                    lbl_8058D198.field14 = marker;
                }
            } else {
                s32 negCol = -dCol;
                if ((u32) lbl_8058D198.field14 > (u32) negCol) {
                    lbl_8058D198.field14 -= negCol;
                    return;
                }
                lbl_8058D198.field14 = 0;
            }
        } else if (dLine == 0) {
            return;
        } else {
            s32 clampedCol;
            u32 clampedLine;

            if (dCol < 0 && (u32) lbl_8058D198.field14 < (u32) -dCol) {
                clampedCol = 0;
            } else {
                clampedCol = lbl_8058D198.field14 + dCol;
            }
            if (dLine < 0 && lbl_8058D198.field18 < (u32) -dLine) {
                clampedLine = 0;
            } else {
                clampedLine = lbl_8058D198.field18 + dLine;
            }

            if (lbl_8058D198.hi1) {
                u32 n2 = 0;
                u32 marker2 = lbl_8058D198.col;
                u32 pos2 = marker2;

                while (n2 < clampedLine && pos2 < lbl_8058D198.size) {
                    pos2++;
                    n2++;
                    marker2 = lbl_8058D198.buf[(lbl_8058D198.cursor + lbl_8058D198.size - pos2) % lbl_8058D198.size];
                    pos2 += marker2;
                }

                lbl_8058D198.charCount = pos2;
                lbl_8058D198.field18 = n2;
                lbl_8058D198.field20 = marker2;

                if (clampedCol < marker2) {
                    lbl_8058D198.field14 = clampedCol;
                    return;
                }
                lbl_8058D198.field14 = marker2;
            }
        }
    }
}

u8 kar_pslist__near_8043a578(void)
{
    u8 c;

    if (!lbl_8058D198.hi1) {
        return 0;
    }
    if (lbl_8058D198.charCount > lbl_8058D198.size) {
        return 0;
    }
    if (lbl_8058D198.field14 < lbl_8058D198.field20) {
        c = lbl_8058D198.buf[(lbl_8058D198.field14 + (lbl_8058D198.cursor + lbl_8058D198.size - lbl_8058D198.charCount)) % lbl_8058D198.size];
        lbl_8058D198.field14++;
    } else {
        c = 0;
        kar_pslist__near_8043a324(0, -1);
        lbl_8058D198.field14 = 0;
    }
    return c;
}

u8 kar_pslist__near_8043a634(u32 newCol, u32 maxLines)
{
    kar_pslist__near_8043a298(newCol, maxLines);
    return kar_pslist__near_8043a578();
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

typedef struct PADStatus {
    u16 button; //0x00
    s8 stickX; //0x02
    s8 stickY; //0x03
    s8 substickX; //0x04
    s8 substickY; //0x05
    u8 triggerLeft; //0x06
    u8 triggerRight; //0x07
    u8 analogA; //0x08
    u8 analogB; //0x09
    s8 err; //0x0A
    u8 pad0B;
} PADStatus;

typedef struct PSPadMenuState {
    u8 pad00[0x54];
    PADStatus pad[4]; //0x54
    PADStatus padPrev[4]; //0x84
    s32 lastDir; //0xB4
    s32 heldFrames; //0xB8
    u32 dir; //0xBC
    u32 rawDir; //0xC0
    s32 resetHeld; //0xC4
    u8 pad_c8[0xD8 - 0xC8];
} PSPadMenuState;

extern PSPadMenuState lbl_8058D1C0;
extern s32 OSGetResetSwitchState(void);
extern void OSResetSystem(s32 type, s32 flags, s32 unused);
extern u32 PADRead(PADStatus* status);
extern void PADClamp(PADStatus* status);
extern void PADReset(u32 mask);

void kar_pslist__near_8043f5d4(void)
{
    u32 mask;
    s32 idx;
    s32 i;

    if (OSGetResetSwitchState()) {
        lbl_8058D1C0.resetHeld = 1;
    } else if (lbl_8058D1C0.resetHeld) {
        OSResetSystem(1, 0, 0);
        for (;;) {}
    }

    memcpy(lbl_8058D1C0.padPrev, lbl_8058D1C0.pad, 0x30);
    PADRead(lbl_8058D1C0.pad);
    PADClamp(lbl_8058D1C0.pad);

    mask = 0;
    for (i = 0; i < 4; i++) {
        if (lbl_8058D1C0.pad[i].err == -1) {
            mask |= 0x80000000 >> i;
        }
    }
    if (mask != 0) {
        PADReset(mask);
    }

    idx = 0;
    for (i = 0; i < 4; i++) {
        if (lbl_8058D1C0.padPrev[i].err == 0 && lbl_8058D1C0.pad[i].err == 0) {
            break;
        }
        idx = i + 1;
    }

    if (idx == 4) {
        lbl_8058D1C0.dir = 0;
        lbl_8058D1C0.rawDir = 0;
    } else {
        u16 button;
        u16 changed;
        u16 pressed;

        lbl_8058D1C0.lastDir = idx;
        button = lbl_8058D1C0.pad[idx].button;
        changed = button ^ lbl_8058D1C0.padPrev[idx].button;
        lbl_8058D1C0.rawDir = button;
        pressed = button & changed;

        if (pressed == 0 && lbl_8058D1C0.pad[idx].button != 0) {
            lbl_8058D1C0.heldFrames++;
            if (lbl_8058D1C0.heldFrames > 0x1E) {
                pressed = lbl_8058D1C0.pad[idx].button;
            }
        }

        lbl_8058D1C0.dir = pressed;
    }
}
