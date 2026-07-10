#include <sysdolphin/util.h>

extern objheap lbl_80504018;

void HSD_MulColor(GXColor* arg0, GXColor* arg1, GXColor* dest)
{
    dest->r = (arg0->r * arg1->r) / 255U;
    dest->g = (arg0->g * arg1->g) / 255U;
    dest->b = (arg0->b * arg1->b) / 255U;
    dest->a = (arg0->a * arg1->a) / 255U;
}

u32 HSD_GetNbBits(u32 c)
{
    int ret = 0;
    int i;

    for (i = 0; i < 32; i++) {
        if ((c) & (1 << i)) {
            ret++;
        }
    }
    return ret;
}

void HSD_ObjSetHeap(u32 size, void* ptr)
{
    lbl_80504018.curr = (u32) ptr;
    lbl_80504018.top = (u32) ptr;
    lbl_80504018.remain = size;
    lbl_80504018.size = size;
}
