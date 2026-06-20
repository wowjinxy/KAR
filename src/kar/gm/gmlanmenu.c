#include "functions.h"
#include <dolphin/mtx/mtxtypes.h>
#include <dolphin/types.h>

typedef struct GmLanWork GmLanWork;
typedef struct HSD_AObj HSD_AObj;
typedef struct HSD_DObj HSD_DObj;
typedef struct HSD_JObj HSD_JObj;
typedef struct HSD_MObj HSD_MObj;

struct GmLanWork {
    u8 pad_000[0x7C8];
    s8 sboard_bg_kind;
    s8 field_7C9;
    u8 pad_7CA[0x02];
    s32 sboard_child0_visible;
    s32 sboard_child1_visible;
};

struct HSD_DObj {
    u8 pad_00[0x04];
    HSD_DObj* next;
    HSD_MObj* mobj;
};

struct HSD_JObj {
    u8 pad_00[0x08];
    HSD_JObj* next;
    HSD_JObj* parent;
    HSD_JObj* child;
    u32 flags;
    u8 pad_18[0x64];
    HSD_AObj* aobj;
};

#define DOBJ_MOBJ(dobj) ((dobj) != NULL ? (dobj)->mobj : NULL)
#define DOBJ_NEXT(dobj) ((dobj) != NULL ? (dobj)->next : NULL)
#define JOBJ_ANIM_ACTIVE(jobj) \
    ((jobj)->aobj != NULL && (HSD_AObjGetFlags((jobj)->aobj) & 0x40000000) == 0)
#define SETUP_SBOARD_KIND(kind_value)                                            \
    do {                                                                         \
        GmLanWork* work0 = (GmLanWork*) kar_gmmain__near_80006c14();             \
        GmLanWork* work1 = (GmLanWork*) kar_gmmain__near_80006c14();             \
        memset(&((GmLanWork*) kar_gmmain__near_80006c14())->sboard_bg_kind, 0,   \
               0xC);                                                             \
        fn_8013927C();                                                           \
        fn_80139314();                                                           \
        work1->field_7C9 = 0;                                                    \
        work1->sboard_child0_visible = 0;                                        \
        work1->sboard_child1_visible = 0;                                        \
        if ((s32) kar_gmracenormal__8000aea8() == 3) {                           \
            kar_mnbestrapbg_set_sboard_bg_subtitle_pair_visible(1);              \
        } else {                                                                 \
            kar_mnbestrapbg_set_sboard_bg_subtitle_pair_visible(0);              \
        }                                                                        \
        work0->sboard_bg_kind = (kind_value);                                    \
        kar_mnbestrapbg_request_sboard_bg_kind_anim(work0->sboard_bg_kind);      \
    } while (0)

char kar_src_gmlanmenu_80497bb8[] = "gmlanmenu.c";
char lbl_80497BC4[] = "p->error != LbNetError_None";
void kar_gmlanmenu__80050ea8(void);
void kar_gmlanmenu__80051028(void);
static void* jumptable_80497BE0[10] = {
    kar_gmlanmenu__80050ea8, kar_gmlanmenu__80050ea8,
    kar_gmlanmenu__80050ea8, kar_gmlanmenu__80050ea8,
    kar_gmlanmenu__80050ea8, kar_gmlanmenu__80050ea8,
    kar_gmlanmenu__80050ea8, kar_gmlanmenu__80050ea8,
    kar_gmlanmenu__80050ea8, kar_gmlanmenu__80050ea8,
};
char lbl_80497C08[0x24] = "lbNetIsDisconnectStarted() == TRUE";
static void* jumptable_80497C2C[13] = {
    kar_gmlanmenu__80051028, kar_gmlanmenu__80051028,
    kar_gmlanmenu__80051028, kar_gmlanmenu__80051028,
    kar_gmlanmenu__80051028, kar_gmlanmenu__80051028,
    kar_gmlanmenu__80051028, kar_gmlanmenu__80051028,
    kar_gmlanmenu__80051028, kar_gmlanmenu__80051028,
    kar_gmlanmenu__80051028, kar_gmlanmenu__80051028,
    kar_gmlanmenu__80051028,
};
static void* jumptable_80497C60[14] = {
    kar_gmlanmenu__80051028, kar_gmlanmenu__80051028,
    kar_gmlanmenu__80051028, kar_gmlanmenu__80051028,
    kar_gmlanmenu__80051028, kar_gmlanmenu__80051028,
    kar_gmlanmenu__80051028, kar_gmlanmenu__80051028,
    kar_gmlanmenu__80051028, kar_gmlanmenu__80051028,
    kar_gmlanmenu__80051028, kar_gmlanmenu__80051028,
    kar_gmlanmenu__80051028, (void*) 0,
};
u8 lbl_80497C98[0x10] = { 0, 5, 2, 3, 1, 4, 6, 7, 8 };
s32 lbl_80497CA8[8] = { 0x0E, 0x0E, 0x0E, 0x0E, 2, 4, 6, 0 };
s32 lbl_80497CC8[4] = { 0x0C, 0x0D, 0x0E, 0x0F };
s32 kar_object_slot_remap_table[4] = { 7, 4, 5, 6 };
s32 lbl_80497CE8[8] = { 6, 6, 6, 6, 1, 2, 3, 0 };
s32 lbl_80497D08[8] = { 0x1C, 0x1D, 0x1E, 0x1F, 7, 4, 5, 6 };
u32 lbl_80497D28[0x10] = {
    0,          0,          0, 0, 0, 0, 0, 0,
    0x3F800000, 0x3F800000, 0x3F800000, 0, 0, 0, 0, 0,
};

void* lbl_80537470[20];
void* lbl_805374C0[20];

char lbl_805D51E0[8] = "0";
char kar_srcfile_jobj_h_805d51e8[8] = "jobj.h";
char lbl_805D51F0[8] = "jobj";
char lbl_805D51F8[4] = "Jan";
char lbl_805D51FC[4] = "Feb";
char lbl_805D5200[4] = "Mar";
char lbl_805D5204[4] = "Apr";
char lbl_805D5208[4] = "May";
char lbl_805D520C[4] = "Jun";
char lbl_805D5210[4] = "Jul";
char lbl_805D5214[4] = "Aug";
char lbl_805D5218[4] = "Sep";
char lbl_805D521C[4] = "Oct";
char lbl_805D5220[4] = "Nov";
char lbl_805D5224[4] = "Dec";

void* lbl_805DD5A0[2];

const f32 lbl_805DE960[2] = { 0.0f, 0.0f };
const f32 lbl_805DE968 = 0.0f;
const f32 lbl_805DE96C = 1.0f;

void* memset(void* dst, int val, unsigned long n);
void* kar_gmmain__near_80006c14(void);
void kar_gmlanmenu__near_80051aa4(void);
void kar_gmlanmenu__near_80051f98(void);
void kar_gmlanmenu__near_80051ff8(void);
void kar_gmlanmenu__near_80052028(void);
void kar_gmlanmenu__near_800522b8(void);
void kar_gmlanmenu__near_800524cc(void);
void kar_gmlanmenu__near_800525bc(void);
void kar_gmlanmenu__near_80052844(void** cursor, s32* depth);
void kar_gmlanmenu__near_800528f0(void** cursor, s32* depth);
void kar_gmlanmenu__near_8005299c(HSD_DObj* dobj, HSD_MObj* current);
void kar_gmlanmenu__near_80052ca4(HSD_DObj* dobj, HSD_MObj* current);
void fn_8013927C(void);
void fn_80139314(void);
s8 kar_gmracenormal__8000aea8(void);
void kar_mnbestrapbg_set_sboard_bg_subtitle_pair_visible(s32 visible);
void kar_mnbestrapbg_request_sboard_bg_kind_anim(s32 kind);
void kar_mnbestrapbg_set_sboard_bg_child_pair_visible(s32 child0, s32 child1);
void kar_lbhvqm__near_80078990(void);
void _HSD_StateInvalidateTexCoordGen(HSD_MObj* mobj);
HSD_DObj* HSD_JObjGetDObj(HSD_JObj* jobj);
u32 HSD_AObjGetFlags(HSD_AObj* aobj);
void HSD_MObjSetCurrent(HSD_MObj* mobj, HSD_MObj* current);
void kar_lbvector_cross_normalize(Vec* a, Vec* b, Vec* out);

// NONMATCHING: wrapper shape is clear, but call/return scheduling differs.
void kar_gmlanmenu__near_80051d7c(void)
{
    kar_gmlanmenu__near_80051aa4();
}

// NONMATCHING: behavior matches the menu background setup; remaining diff is
// register allocation around repeated kar_gmmain__near_80006c14 calls.
void kar_gmlanmenu__near_80051d9c(void)
{
    SETUP_SBOARD_KIND(0);
    kar_gmlanmenu__near_80051f98();
    kar_gmlanmenu__near_80051ff8();
    kar_lbhvqm__near_80078990();
}

// NONMATCHING: same helperized setup as 80051D9C.
void kar_gmlanmenu__near_80051e44(void)
{
    SETUP_SBOARD_KIND(1);
    kar_gmlanmenu__near_80051f98();
    kar_gmlanmenu__near_80051ff8();
    kar_lbhvqm__near_80078990();
}

// NONMATCHING: same helperized setup as 80051D9C, with the extra mode-2 refresh.
void kar_gmlanmenu__near_80051eec(void)
{
    SETUP_SBOARD_KIND(2);
    kar_gmlanmenu__near_800524cc();
    kar_gmlanmenu__near_80051f98();
    kar_gmlanmenu__near_80051ff8();
    kar_lbhvqm__near_80078990();
}

void kar_gmlanmenu__near_80051f98(void)
{
    GmLanWork* work = (GmLanWork*) kar_gmmain__near_80006c14();

    switch (work->sboard_bg_kind) {
    case 0:
        kar_gmlanmenu__near_80052028();
        break;
    case 1:
        kar_gmlanmenu__near_800522b8();
        break;
    case 2:
        kar_gmlanmenu__near_800525bc();
        break;
    }
}

void kar_gmlanmenu__near_80051ff8(void)
{
    GmLanWork* work = (GmLanWork*) kar_gmmain__near_80006c14();
    kar_mnbestrapbg_set_sboard_bg_child_pair_visible(work->sboard_child0_visible,
                                                     work->sboard_child1_visible);
}

// NONMATCHING: behavior is the same first-child/next-sibling traversal; target
// uses pointer arithmetic on the stack cursor a little differently.
void kar_gmlanmenu__near_80052844(void** cursor, s32* depth)
{
    u8* node = *cursor;
    s32 count = *depth;
    void* next;

    if (*(void**) (node + 0x0) != NULL) {
        lbl_80537470[count] = node;
        count++;
        next = *(void**) (node + 0x0);
    } else if (*(void**) (node + 0x4) != NULL) {
        next = *(void**) (node + 0x4);
    } else {
        for (;;) {
            if (count == 0) {
                next = NULL;
                break;
            }

            count--;
            node = lbl_80537470[count];
            if (*(void**) (node + 0x4) != NULL) {
                next = *(void**) (node + 0x4);
                break;
            }
        }
    }

    *cursor = next;
    *depth = count;
}

// NONMATCHING: same traversal as 80052844, using the alternate child/sibling
// offsets and stack.
void kar_gmlanmenu__near_800528f0(void** cursor, s32* depth)
{
    u8* node = *cursor;
    s32 count = *depth;
    void* next;

    if (*(void**) (node + 0x8) != NULL) {
        lbl_805374C0[count] = node;
        count++;
        next = *(void**) (node + 0x8);
    } else if (*(void**) (node + 0xC) != NULL) {
        next = *(void**) (node + 0xC);
    } else {
        for (;;) {
            if (count == 0) {
                next = NULL;
                break;
            }

            count--;
            node = lbl_805374C0[count];
            if (*(void**) (node + 0xC) != NULL) {
                next = *(void**) (node + 0xC);
                break;
            }
        }
    }

    *cursor = next;
    *depth = count;
}

HSD_MObj* kar_gmlanmenu__near_80052c40(HSD_DObj* dobj)
{
    return DOBJ_MOBJ(dobj);
}

void kar_gmlanmenu__near_80052c58(HSD_DObj* dobj)
{
    _HSD_StateInvalidateTexCoordGen(DOBJ_MOBJ(dobj));
}

HSD_DObj* HSD_DObjGetNext(HSD_DObj* dobj)
{
    return DOBJ_NEXT(dobj);
}

void kar_gmlanmenu__near_80052f48(HSD_DObj* dobj, HSD_MObj* current)
{
    HSD_MObjSetCurrent(DOBJ_MOBJ(dobj), current);
}

void kar_gmlanmenu__near_80052f7c(HSD_JObj* jobj, HSD_MObj* current)
{
    HSD_DObj* dobj = HSD_JObjGetDObj(jobj);

    if (dobj != NULL) {
        kar_gmlanmenu__near_8005299c(dobj, current);
    }
}

HSD_JObj* kar_gmlanmenu__near_80053740(HSD_JObj* jobj)
{
    if (jobj == NULL) {
        return NULL;
    }
    return jobj->next;
}

HSD_JObj* kar_gmlanmenu__near_80053758(HSD_JObj* jobj)
{
    if (jobj == NULL) {
        return NULL;
    }
    return jobj->child;
}

void kar_gmlanmenu__near_80053770(HSD_JObj* jobj, HSD_MObj* current)
{
    HSD_DObj* dobj = HSD_JObjGetDObj(jobj);

    if (dobj != NULL) {
        kar_gmlanmenu__near_80052ca4(dobj, current);
    }
}

// NONMATCHING: matrix contents are correct; remaining diff is stack/register
// layout around the normalized cross vector.
void kar_gmlanmenu__near_80054320(Mtx out, Vec* z_axis, Vec* y_axis, Vec* trans,
                                  Vec* scale)
{
    Vec x_axis;

    kar_lbvector_cross_normalize(y_axis, z_axis, &x_axis);
    out[0][0] = x_axis.x * scale->x;
    out[1][0] = x_axis.y * scale->x;
    out[2][0] = x_axis.z * scale->x;
    out[0][1] = y_axis->x * scale->y;
    out[1][1] = y_axis->y * scale->y;
    out[2][1] = y_axis->z * scale->y;
    out[0][2] = z_axis->x * scale->z;
    out[1][2] = z_axis->y * scale->z;
    out[2][2] = z_axis->z * scale->z;
    out[0][3] = trans->x;
    out[1][3] = trans->y;
    out[2][3] = trans->z;
}

void fn_800528EC(void) {}

void fn_80052998(void) {}

s32 kar_gmlanmenu__near_80054798(HSD_JObj* jobj)
{
    s32 active = 0;

    if (JOBJ_ANIM_ACTIVE(jobj)) {
        active = 1;
    }

    return active;
}

// NONMATCHING: behavior-level DFS for "any visible animation still active";
// target uses an iterative traversal with parent/child/sibling stepping.
s32 kar_gmlanmenu__near_800547e0(HSD_JObj* jobj)
{
    HSD_JObj* child;

    if (jobj == NULL || (jobj->flags & 0x1000) != 0) {
        return 0;
    }

    if (JOBJ_ANIM_ACTIVE(jobj)) {
        return 1;
    }

    for (child = jobj->child; child != NULL; child = child->next) {
        if (kar_gmlanmenu__near_800547e0(child) != 0) {
            return 1;
        }
    }

    return 0;
}
