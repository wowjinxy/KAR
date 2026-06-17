#include "functions.h"
#include <dolphin/mtx/mtxtypes.h>
#include <dolphin/types.h>
#include <sysdolphin/lobj.h>

#define LOBJ_NEXT(lobj) ((lobj) == NULL ? NULL : (lobj)->next)
#define LOBJ_FLOAT_2C(lobj) (*(f32*) ((u8*) (lobj) + 0x2C))

char kar_src_lblight_80497e00[] = "lblight.c";
char lbl_805D5238[] = "0";

u32 kar_lblight__803fdacc(HSD_LObj* lobj);
void HSD_LObjGetPosition(HSD_LObj* lobj, Vec* pos);
void HSD_LObjSetPosition(HSD_LObj* lobj, Vec* pos);
void HSD_LObjGetInterest(HSD_LObj* lobj, Vec* interest);
void HSD_LObjSetInterest(HSD_LObj* lobj, Vec* interest);

HSD_LObj* kar_lblight__80057514(HSD_LObj* lobj)
{
    while (lobj != NULL) {
        if ((HSD_LObjGetType(lobj) == LOBJ_AMBIENT) &&
            ((kar_lblight__803fdacc(lobj) & 0x20) == 0)) {
            return lobj;
        }

        lobj = LOBJ_NEXT(lobj);
    }

    __assert(kar_src_lblight_80497e00, 0x2E, lbl_805D5238);
    return NULL;
}

HSD_LObj* kar_lblight__80057598(HSD_LObj* lobj)
{
    while (lobj != NULL) {
        if (((u32) HSD_LObjGetType(lobj) == LOBJ_INFINITE) &&
            ((kar_lblight__803fdacc(lobj) & 0x20) == 0)) {
            return lobj;
        }

        lobj = LOBJ_NEXT(lobj);
    }

    __assert(kar_src_lblight_80497e00, 0x3C, lbl_805D5238);
    return NULL;
}

void kar_lblight__80057620(HSD_LObj* lobj, f32 scale)
{
    Vec vec;

    switch (HSD_LObjGetType(lobj)) {
    case LOBJ_POINT:
        HSD_LObjGetPosition(lobj, &vec);
        vec.x *= scale;
        vec.y *= scale;
        vec.z *= scale;
        HSD_LObjSetPosition(lobj, &vec);

        if ((kar_lblight__803fdacc(lobj) & 0x40) != 0) {
            __assert(kar_src_lblight_80497e00, 0x59, lbl_805D5238);
        } else {
            LOBJ_FLOAT_2C(lobj) *= scale;
        }
        break;
    case LOBJ_SPOT:
        HSD_LObjGetPosition(lobj, &vec);
        vec.x *= scale;
        vec.y *= scale;
        vec.z *= scale;
        HSD_LObjSetPosition(lobj, &vec);

        HSD_LObjGetInterest(lobj, &vec);
        vec.x *= scale;
        vec.y *= scale;
        vec.z *= scale;
        HSD_LObjSetInterest(lobj, &vec);

        if ((kar_lblight__803fdacc(lobj) & 0x40) != 0) {
            __assert(kar_src_lblight_80497e00, 0x6D, lbl_805D5238);
        } else {
            LOBJ_FLOAT_2C(lobj) *= scale;
        }
        break;
    case LOBJ_AMBIENT:
    case LOBJ_INFINITE:
        break;
    default:
        __assert(kar_src_lblight_80497e00, 0x75, lbl_805D5238);
        break;
    }
}
