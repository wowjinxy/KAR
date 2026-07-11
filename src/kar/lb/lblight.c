#include "functions.h"
#include <dolphin/mtx/mtxtypes.h>
#include <dolphin/types.h>
#include <sysdolphin/lobj.h>

#define LOBJ_NEXT(lobj) ((lobj) == NULL ? NULL : (lobj)->next)
#define LOBJ_FLOAT_2C(lobj) (*(f32*) ((u8*) (lobj) + 0x2C))

char kar_src_lblight_80497e00[] = "lblight.c";
char kar_lblight_assert_zero[] = "0";

HSD_LObj* kar_lblight__80057514(HSD_LObj* lobj)
{
    while (lobj != NULL) {
        if ((HSD_LObjGetType(lobj) == LOBJ_AMBIENT) &&
            ((HSD_LObjGetFlags(lobj) & 0x20) == 0)) {
            return lobj;
        }

        lobj = LOBJ_NEXT(lobj);
    }

    __assert(kar_src_lblight_80497e00, 0x2E, kar_lblight_assert_zero);
    return NULL;
}

HSD_LObj* kar_lblight__80057598(HSD_LObj* lobj)
{
    while (lobj != NULL) {
        if (((u32) HSD_LObjGetType(lobj) == LOBJ_INFINITE) &&
            ((HSD_LObjGetFlags(lobj) & 0x20) == 0)) {
            return lobj;
        }

        lobj = LOBJ_NEXT(lobj);
    }

    __assert(kar_src_lblight_80497e00, 0x3C, kar_lblight_assert_zero);
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

        if ((HSD_LObjGetFlags(lobj) & 0x40) != 0) {
            __assert(kar_src_lblight_80497e00, 0x59, kar_lblight_assert_zero);
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

        if ((HSD_LObjGetFlags(lobj) & 0x40) != 0) {
            __assert(kar_src_lblight_80497e00, 0x6D, kar_lblight_assert_zero);
        } else {
            LOBJ_FLOAT_2C(lobj) *= scale;
        }
        break;
    case LOBJ_AMBIENT:
    case LOBJ_INFINITE:
        break;
    default:
        __assert(kar_src_lblight_80497e00, 0x75, kar_lblight_assert_zero);
        break;
    }
}
