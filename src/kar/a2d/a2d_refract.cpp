#include <dolphin/types.h>
#include <dolphin/gx/gxtypes.h>

extern "C" {
#include <global.h>
}

struct Vec3 {
    f32 x, y, z;
};

struct DVDFileInfo {
    char pad[0x18];
};

struct RefractItem {
    char pad0[0xC];
    f32 unkC, unk10, unk14;
    f32 unk18;
    f32 unk1C;
    s32 unk20;
    u8 unk24;
    u8 unk25;
};

struct RippleWave {
    char pad0[4];
    s32 unk4;
    f32 unk8;
    f32 unkC;
};

struct ListNode {
    ListNode *next;
    ListNode *prev;
};

struct ListHead {
    s32 count;
    ListNode self;
};

static inline void ListHead_Init(ListHead *arg0) {
    ListNode *s = &arg0->self;
    arg0->count = 0;
    s->prev = s;
    s->next = s;
}

extern "C" void * kar_a2d_refract__80383f6c(void *arg0) {
    (void) arg0;
    return 0;
}

extern "C" void kar_a2d_refract__near_803842e8(void *arg0, void *arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void kar_a2d_refract__near_8038447c(void *arg0) {
    (void) arg0;
}

struct HasByteAt25 {
    char pad[0x25];
    u8 unk25;
};

extern "C" u8 fn_80384540(HasByteAt25 *arg0) {
    return arg0->unk25;
}

extern "C" void kar_a2d_refract__near_80384548(void *arg0) {
    (void) arg0;
}

extern "C" void kar_a2d_refract__near_803845f4(s32 *arg0) {
    *arg0 = 0;
}

extern "C" void kar_a2d_refract__near_80384a80(RefractItem **arg0);
extern "C" void fn_8038CB78(void *arg0);

extern "C" RefractItem ** kar_a2d_refract__near_80384600(RefractItem **arg0, s16 arg1) {
    if (arg0 != NULL) {
        if (*arg0 != NULL) {
            kar_a2d_refract__near_80384a80(arg0);
            (*arg0)->unk25 = 1;
            *arg0 = NULL;
        }
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void kar_a2d_refract__near_80384670(s32 ***arg0, s32 arg1, void **arg2, f32 farg0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) farg0;
}

extern "C" void kar_a2d_refract__near_803848e0(s32 ***arg0, s32 arg1, void *arg2, f32 farg0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) farg0;
}

extern "C" void kar_a2d_refract__near_80384a80(RefractItem **arg0) {
    RefractItem *item = *arg0;
    if (item != NULL) {
        item->unk24 = 0;
    }
}

extern "C" void kar_a2d_refract__near_80384a98(RefractItem **arg0) {
    RefractItem *item = *arg0;
    if (item != NULL) {
        item->unk24 = 1;
    }
}

extern "C" void kar_a2d_refract__near_80384ab0(RefractItem **arg0, s32 arg1) {
    RefractItem *item = *arg0;
    if (item != NULL) {
        item->unk20 = arg1;
    }
}

extern "C" void kar_a2d_refract__near_80384ac4(RefractItem **arg0, f32 farg0) {
    RefractItem *item = *arg0;
    if (item != NULL) {
        item->unk1C = farg0;
    }
}

extern "C" void kar_a2d_refract__near_80384ad8(RefractItem **arg0, Vec3 *arg1) {
    RefractItem *item = *arg0;
    if (item != NULL) {
        item->unkC = arg1->x;
        item->unk10 = arg1->y;
        item->unk14 = arg1->z;
    }
}

extern "C" void kar_a2d_refract__near_80384b00(void *arg0, s32 *arg1, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg_sp0;
}

extern "C" void kar_a2d_refract__near_80384bb8(s32 **arg0, s32 **arg1, s32 ***arg2, void **arg3, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg_sp0;
}

struct FreeListMgr {
    char pad[0x600];
    s32 head;
    s32 count;
};

extern "C" s32 *kar_a2d_refract__near_80384cc8(FreeListMgr *arg0) {
    s32 *elem = (s32 *) ((char *) arg0 + arg0->head * 0x30);
    arg0->head = *elem;
    arg0->count -= 1;
    return elem;
}

struct RippleGroup {
    char pad0[4];
    s32 unk4;
    char pad8[8];
    f32 unk10, unk14, unk18;
    f32 unk1C, unk20, unk24;
};

struct RippleGroupObj {
    void *vtbl;
    s32 unk4;
    char pad8[8];
    f32 unk10, unk14, unk18;
    f32 unk1C, unk20, unk24;
    s32 unk28;
    f32 unk2C;
    f32 unk30;
};

extern "C" char lbl_804BCDD8[0x20];
extern "C" char lbl_804BCDF0[0x20];
extern "C" const f32 lbl_805E4DB8; /* ? */
extern "C" const f32 lbl_805E4DBC; /* ? */
extern "C" void *lbl_805DDB80;
extern "C" void kar_a2d_refract__near_80384d5c(RippleGroup *arg0);

extern "C" void * kar_a2d_refract__near_80384cf0(RippleGroupObj *arg0) {
    arg0->vtbl = lbl_804BCDD8;
    lbl_805DDB80 = arg0;
    arg0->vtbl = lbl_804BCDF0;
    arg0->unk28 = 20;
    arg0->unk2C = lbl_805E4DB8;
    arg0->unk30 = lbl_805E4DBC;
    kar_a2d_refract__near_80384d5c((RippleGroup *) arg0);
    return arg0;
}

extern "C" const f32 lbl_805E4DC0; /* 0.0F */

extern "C" void kar_a2d_refract__near_80384d5c(RippleGroup *arg0) {
    arg0->unk4 = 0;
    arg0->unk18 = lbl_805E4DC0;
    arg0->unk14 = lbl_805E4DC0;
    arg0->unk10 = lbl_805E4DC0;
    arg0->unk1C = arg0->unk10;
    arg0->unk20 = arg0->unk14;
    arg0->unk24 = arg0->unk18;
}

extern "C" void kar_a2d_refract__near_80384d90(void *arg0) {
    (void) arg0;
}

extern "C" void kar_a2d_refract__near_80384ea4(RippleWave *arg0, s32 arg1, f32 farg0, f32 farg1) {
    if (farg0 >= arg0->unk8) {
        arg0->unk4 = arg1;
        arg0->unk8 = farg0;
        arg0->unkC = farg1;
    }
}

struct TwoVec3 {
    char pad0[0x10];
    Vec3 a;
    Vec3 b;
};

extern "C" Vec3 kar_a2d_refract__near_80384ec4(TwoVec3 *arg1) {
    Vec3 result;
    result.x = arg1->a.x - arg1->b.x;
    result.y = arg1->a.y - arg1->b.y;
    result.z = arg1->a.z - arg1->b.z;
    return result;
}

extern "C" const f32 lbl_805E4DC4; /* 0.5F */
extern "C" const f32 lbl_805E4DC8; /* -0.01F */
extern "C" const f32 lbl_805E4DCC; /* 0.8F */
extern "C" const f32 lbl_805E4DD0; /* -0.018F */

extern "C" void kar_a2d_refract__near_80384f18(RippleWave *arg0) {
    if (lbl_805E4DC4 >= arg0->unk8) {
        arg0->unk4 = 12;
        arg0->unk8 = lbl_805E4DC4;
        arg0->unkC = lbl_805E4DC8;
    }
}

extern "C" void kar_a2d_refract__near_80384f44(RippleWave *arg0) {
    if (lbl_805E4DCC >= arg0->unk8) {
        arg0->unk4 = 20;
        arg0->unk8 = lbl_805E4DCC;
        arg0->unkC = lbl_805E4DD0;
    }
}

extern "C" void kar_a2d_refract__near_80384f70(u8 *arg0, f32 *arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void kar_a2d_refract__near_80385094(void *arg0, void *arg1) {
    (void) arg0;
    (void) arg1;
}

struct TwoVec3At4 {
    char pad0[4];
    Vec3 v1;
    Vec3 v2;
};

extern "C" void PSVECSubtract(Vec3 *, Vec3 *, Vec3 *);
extern "C" void PSVECAdd(Vec3 *, Vec3 *, Vec3 *);

extern "C" TwoVec3At4 * kar_a2d_refract__near_803851c4(TwoVec3At4 *arg0, f32 farg0) {
    Vec3 local;
    local.x = farg0;
    local.y = farg0;
    local.z = farg0;
    PSVECSubtract(&arg0->v1, &local, &arg0->v1);
    PSVECAdd(&arg0->v2, &local, &arg0->v2);
    return arg0;
}

struct AABB {
    char pad0[4];
    f32 minX, minY, minZ;
    f32 maxX, maxY, maxZ;
};

extern "C" s32 kar_a2d_refract__near_8038521c(AABB *arg0, AABB *arg1) {
    s32 result = 0;
    if (arg0->maxX > arg1->minX) {
        if (arg1->maxX > arg0->minX) {
            if (arg0->maxZ > arg1->minZ) {
                if (arg1->maxZ > arg0->minZ) {
                    if (arg0->maxY > arg1->minY) {
                        if (arg1->maxY > arg0->minY) {
                            result = 1;
                        }
                    }
                }
            }
        }
    }
    return result;
}

struct MultiArrInit {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    char pad0xC[0x28 - 0xC];
    s32 unk28;
    char pad0x2C[0x48 - 0x2C];
    u8 unk48;
    char pad0x49[0x50 - 0x49];
    u8 unk50;
    u8 unk51;
};

extern "C" void kar_a2d_refract__near_8038528c(MultiArrInit *arg0, s8 arg1, s32 arg2, s32 arg3) {
    arg0->unk0 = 0;
    arg0->unk4 = 0;
    arg0->unk50 = 1;
    arg0->unk51 = 1;
    arg0->unk8 = arg2;
    arg0->unk28 = arg3;
    arg0->unk48 = arg1;
}

struct MultiArr {
    char pad0[8];
    s32 arr1[8];
    s32 arr2[8];
    s8 arr3[8];
    u8 count;
};

extern "C" void kar_a2d_refract__near_803852b4(MultiArr *arg0, s8 arg1, s32 arg2, s32 arg3) {
    arg0->arr1[arg0->count] = arg2;
    arg0->arr2[arg0->count] = arg3;
    arg0->arr3[arg0->count] = arg1;
    arg0->count = arg0->count + 1;
}

extern "C" s32 kar_a2d_refract__near_803852f0(void *arg0, void *arg1, void *arg2, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg_sp0;
    return 0;
}

extern "C" s32 kar_a2d_refract__near_803855bc(char *arg0) {
    s32 flags = 64;
    if (*(void **)(arg0 + 0) != 0) {
        flags = 6144;
        if (*(void **)(arg0 + 4) != 0) {
            flags = 3584;
        }
        flags += 64;
    }
    u8 found = 0;
    u32 count = *(u8 *)(arg0 + 0x50);
    for (u32 i = 0; i < count; i++) {
        if (*(u32 *)(arg0 + 0x28) != 0) {
            found = 1;
            flags += 1024;
        } else {
            flags += 2048;
        }
        arg0 += 4;
    }
    if (found != 0) {
        flags += 512;
    }
    return flags;
}

extern "C" void kar_a2d_refract__near_80385630(void *arg0, void *arg1, void *arg2, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg_sp0;
}

extern "C" const f32 lbl_805E4DE0; /* 0.0F */

extern "C" void fn_80385748(Vec3 *arg0) {
    arg0->z = lbl_805E4DE0;
    arg0->y = lbl_805E4DE0;
    arg0->x = lbl_805E4DE0;
}

extern "C" void kar_a2d_refract__near_8038575c(void *arg0) {
    (void) arg0;
}

extern "C" void * fn_803859BC(void *arg0, void *arg1, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg_sp0;
    return 0;
}

struct HasPMFArr {
    char pad0[0xC];
    s32 count;
    void *base;
};

class DummyBase {
public:
    virtual void v00();
};

typedef void (DummyBase::*MemFn)();
extern "C" MemFn const lbl_804F4B60;

#pragma dont_inline on
extern "C" void fn_80385F18(HasPMFArr *arg0) {
    char *p = (char *) arg0->base;
    char *end = p + arg0->count * 112;
    while (p != end) {
        (((DummyBase *) p)->*lbl_804F4B60)();
        p += 112;
    }
}
#pragma dont_inline off

extern "C" void * fn_80385FA0(void *arg0, f32 *arg1, f32 *arg2, void *arg3, f32 farg0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) farg0;
    return 0;
}

extern "C" void * fn_80386C5C(void *arg0, void *arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_80386DAC(void *arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_80386E30(void *arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void * fn_80386EA4(void *arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

struct RefCounted {
    char pad0[0x38];
    s32 count;
};

struct RefHolder {
    char pad0[4];
    RefCounted *unk4;
};

extern "C" void kar_diagnostic__80386f2c(RefHolder *arg0, RefHolder *arg1) {
    if (arg1 != arg0) {
        arg0->unk4 = arg1->unk4;
        arg0->unk4->count += 1;
    }
}

extern "C" void fn_80386F50(u32 *arg0, void *arg1, u32 arg2) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
}

extern "C" void kar_diag__80387688(void *arg0, u32 arg1) {
    (void) arg0;
    (void) arg1;
}

struct DiagArr {
    char pad0[4];
    u32 count;
    char *base;
};

extern "C" void kar_diag__near_80387f20(DiagArr *arg0);
extern "C" void fn_8038CB78(void *arg0);

extern "C" void * kar_diag__near_803878e4(DiagArr *arg0, s16 arg1) {
    if (arg0 != NULL) {
        kar_diag__near_80387f20(arg0);
        if (arg0->base != NULL) {
            fn_8038CB78(arg0->base);
        }
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void kar_diag__near_80387944(void **arg0, void **arg1, void **arg2) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
}

extern "C" void kar_diag__near_803879e4(void **arg0, void **arg1, void **arg2, void *arg3, u8 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg_sp0;
}

extern "C" void kar_diag__near_80387aac(void **arg1, void *arg2) {
    (void) arg1;
    (void) arg2;
}

extern "C" void kar_diag__near_80387b78(void **arg0, s32 *arg1, void **arg2, void **arg3) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
}

extern "C" void kar_diag__near_80387c28(void **arg0, s32 *arg1, ListNode **arg2) {
    ListNode *node = *arg2;
    ListNode *prev = node->prev;
    ListNode *next = node->next;
    *arg2 = prev;
    next->prev = prev;
    node->prev->next = node->next;
    fn_8038CB78(node);
    s32 c = *arg1;
    void *d = *arg2;
    *arg1 = c - 1;
    *arg0 = d;
}

extern "C" void kar_diag__near_80387ca0(void **arg0, s32 *arg1, void **arg2, void **arg3, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg_sp0;
}

extern "C" void kar_diag__near_80387d78(ListHead *arg0) {
    ListHead_Init(arg0);
}

extern "C" void kar_diag__near_80387d90(void **arg0, s32 *arg1, void ***arg2, void **arg3) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
}

extern "C" void kar_diag__near_80387e40(void **arg0, s32 *arg1, void **arg2, void **arg3, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg_sp0;
}

extern "C" void kar_diag__near_80387f08(ListHead *arg0) {
    ListHead_Init(arg0);
}

extern "C" void kar_diag__near_80387f20(DiagArr *arg0) {
    char *end = arg0->base + arg0->count * 112;
    for (char *p = arg0->base; p < end; p += 112) {
    }
    arg0->count = 0;
}

extern "C" void kar_diag__80387f5c(void *arg0, void *arg1, u32 arg2, u8 *arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg_sp0;
}

extern "C" void fn_80388190(ListHead *arg0);
extern "C" void *fn_803881A8(void *arg0, s16 arg1);
extern "C" void __register_global_object(void **, void *(*) (void *, s16), void *);
extern "C" ListHead lbl_805699F4;
extern "C" char lbl_805699E8[0xC];

extern "C" void fn_8038814C(void) {
    fn_80388190(&lbl_805699F4);
    __register_global_object((void **) &lbl_805699F4, fn_803881A8, lbl_805699E8);
}

extern "C" void fn_80388190(ListHead *arg0) {
    ListHead_Init(arg0);
}

extern "C" void * fn_803881A8(void *arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void kar_diag__near_80388220(void ***arg0, void *arg1, void **arg2, void ***arg3) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
}

extern "C" void kar_diag__near_803882e8(void *arg0) {
    (void) arg0;
}

extern "C" void * kar_diag__near_80388388(void *arg0, s32 arg1, s32 arg2, void **arg3, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg_sp0;
    return 0;
}

extern "C" void kar_diag__near_803885f8(void *arg0) {
    (void) arg0;
}

extern "C" void kar_diag__near_8038867c(void *arg0) {
    (void) arg0;
}

extern "C" void kar_diag__near_80388700(void *arg0) {
    (void) arg0;
}

extern "C" void kar_diag__near_80388800(void *arg0) {
    (void) arg0;
}

struct HasPtrAt4 {
    char pad[4];
    char *unk4;
};

extern "C" void kar_diag__near_803888bc(HasPtrAt4 *arg0) {
    fn_80385F18((HasPMFArr *) (arg0->unk4 + 8));
}

extern "C" void * kar_diag__near_803888e4(void *arg0, void *arg1, Vec3 *arg2, void *arg3, void **arg4, f32 farg0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg4;
    (void) farg0;
    return 0;
}

#pragma dont_inline on
extern "C" void kar_diag__near_80388ce8(void *arg0, void *arg1) {
    *(void **) arg0 = arg1;
}
#pragma dont_inline off

extern "C" void * kar_diag__near_80388eb4(void *arg0, void *arg1, void **arg2, void **arg3, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg_sp0;
    return 0;
}

extern "C" void * kar_diag__near_803890c0(void *arg0, void *arg2) {
    (void) arg0;
    (void) arg2;
    return 0;
}

extern "C" void kar_diag__80389218(void *arg0, void *arg1, u32 arg2, void *arg3, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg_sp0;
}

extern "C" void kar_diag__80389960(void *arg0, u32 arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void kar_diag__80389b00(void *arg0, void *arg1, u32 arg2, void *arg3, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg_sp0;
}

extern "C" void kar_diag__8038a12c(void *arg0, u32 arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void kar_diag__8038a2f4(void *arg0, void *arg1, u32 arg2, void *arg3, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg_sp0;
}

extern "C" void kar_diag__8038abf8(void *arg0, u32 arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void kar_diag__8038add4(void *arg0, void *arg1, void *arg2, u8 *arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg_sp0;
}

extern "C" void kar_diag__8038af10(void *arg0, void *arg1, u8 *arg2) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
}

extern "C" void kar_diag__8038b30c(void *arg0, void *arg1, void *arg2, u8 *arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg_sp0;
}

namespace {
extern "C" void *kar_diag__8038b438(void *arg0, void *arg1);
}

extern "C" void kar_diagnostic__8038b408(void *arg0, void *arg1, void *arg2) {
    (void) arg0;
    if (arg1 != NULL) {
        kar_diag__8038b438(arg1, arg2);
    }
}

extern "C" void *kar_diag__8038b438(void *arg0, void *arg1, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg_sp0;
    return 0;
}

extern "C" void kar_diag__8038b5d0(void *arg0, void *arg1, u8 *arg2, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg_sp0;
}

extern "C" void kar_a2d_game_lib__near_802889d0(f32 *, f32 *, f32);

extern "C" void kar_diag__near_8038b844(f32 *arg0, f32 *arg1, f32 farg0) {
    f32 base = arg0[0];
    f32 den = arg1[0] - base;
    f32 num = farg0 - base;
    kar_a2d_game_lib__near_802889d0(arg0 + 1, arg1 + 1, num / den);
}

extern "C" void kar_diag__near_8038b880(void *arg0, void *arg1, f32 farg0) {
    (void) arg0;
    (void) arg1;
    (void) farg0;
}

extern "C" f32 kar_diag__near_8038b8e4(void *arg0, void *arg1, f32 farg0) {
    (void) arg0;
    (void) arg1;
    (void) farg0;
    return 0.0f;
}

extern "C" const f32 lbl_805E4E08; /* 1.0F */
extern "C" const f32 lbl_805E4E0C; /* 3.0F */
extern "C" const f32 lbl_805E4E10; /* 2.0F */

extern "C" f32 kar_diag__near_8038b964(f32 *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 farg0) {
    f32 t = farg0;
    f32 t2 = t * t;
    f32 tm1 = t - lbl_805E4E08;
    f32 at = lbl_805E4E10 * t;
    f32 v2 = *arg2;
    f32 v0 = *arg0;
    f32 cm = lbl_805E4E0C - at;
    f32 tm1sq = tm1 * tm1;
    f32 v1 = *arg1;
    f32 bp = lbl_805E4E08 + at;
    f32 v3 = *arg3;
    f32 h01 = cm * t2;
    f32 tm1t = tm1 * t;
    f32 h00 = bp * tm1sq;
    f32 h10 = t * tm1sq;
    f32 h11 = t * tm1t;
    return v0 * h00 + v2 * h01 + v1 * h10 + v3 * h11;
}

extern "C" void * kar_diag__8038b9c0(void *arg0, s8 *arg1, void *arg2, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg_sp0;
    return 0;
}

extern "C" void fn_8038BDE0(DVDFileInfo *arg0);
extern "C" void *fn_8038BD64(void *arg0, s16 arg1);

struct HasVtblAndFields {
    void *vtbl;
    void *unk4;
    u8 unk8;
    char pad9[3];
    DVDFileInfo fileInfo;
};

extern "C" char lbl_804F4D5C[0x18];

extern "C" HasVtblAndFields * fn_8038BB68(HasVtblAndFields *arg0, s16 arg1) {
    if (arg0 != 0) {
        arg0->vtbl = lbl_804F4D5C;
        fn_8038BDE0(&arg0->fileInfo);
        if (arg0->unk8 == 0) {
            fn_8038CB78(arg0->unk4);
        }
        fn_8038BD64(&arg0->fileInfo, -1);
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void * fn_8038BBE8(void *arg0, s32 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" s32 fn_8038BC80(s32 arg0, s32 arg1) {
    s32 *slot = (s32 *) (arg0 + arg1 * 8);
    return arg0 + slot[3] + 4;
}

struct HasCount4 {
    char pad[4];
    u32 count;
};

extern "C" char lbl_805DC044[4];

extern "C" void fn_8038BC98(HasCount4 *arg0) {
    char *p = (char *) arg0;
    for (u32 i = 0; i < arg0->count; i++) {
        s32 off = *(s32 *)(p + 8);
        OSReport(lbl_805DC044, (char *) arg0 + off);
        p += 8;
    }
}

struct FlagObj9 {
    char pad[9];
    u8 unk9;
};

struct HasFlagObjAt2C {
    char pad[0x2C];
    FlagObj9 *unk2C;
};

extern "C" void fn_8038BD04(void *arg0, HasFlagObjAt2C *arg1) {
    (void) arg0;
    arg1->unk2C->unk9 = 1;
}

struct HasEntryNum {
    char pad[0x3C];
    s32 unk3C;
    void *unk40;
};

extern "C" s32 DVDConvertPathToEntrynum(const s8 *);
extern "C" void *kar_lbkdcoll__near_80073984(s32);
extern "C" void fn_8038BDB4(void *arg0, s32 arg1);

extern "C" void *fn_8038BD14(HasEntryNum *arg0, s8 *arg1) {
    arg0->unk3C = DVDConvertPathToEntrynum(arg1);
    arg0->unk40 = kar_lbkdcoll__near_80073984(arg0->unk3C);
    fn_8038BDB4(arg0, arg0->unk3C);
    return arg0;
}

extern "C" void fn_8038BDE0(DVDFileInfo *arg0);
extern "C" void fn_8038CB78(void *arg0);

extern "C" void *fn_8038BD64(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        fn_8038BDE0((DVDFileInfo *) arg0);
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void kar_lbfile__803c51c8(s32, void *);

extern "C" void fn_8038BDB4(void *arg0, s32 arg1) {
    kar_lbfile__803c51c8(arg1, arg0);
}

extern "C" int DVDClose(DVDFileInfo *fileInfo);

extern "C" void fn_8038BDE0(DVDFileInfo *arg0) {
    DVDClose(arg0);
}

extern "C" u32 fn_8038BE00(void *arg0, void *arg1, u32 arg2, s32 arg3, f32 (*arg4)(u32, void *)) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    return 0;
}

struct HasFieldSet1 {
    char pad0[0x34];
    s32 unk34;
    char pad1[4];
    s32 unk3C;
    u32 unk40;
};

extern "C" s32 kar_lbkdcoll__near_80073834(s32);

extern "C" s32 fn_8038BEB4(HasFieldSet1 *arg0) {
    if (arg0->unk40 != 0) {
        return kar_lbkdcoll__near_80073834(arg0->unk3C);
    }
    return arg0->unk34;
}

struct HasPtrAt2C {
    char pad[0x2C];
    void *unk2C;
};

extern "C" void fn_8038BEEC(HasPtrAt2C *arg0, void *arg1) {
    arg0->unk2C = arg1;
}

struct TexRect {
    void *img;
    s32 unk4;
    s32 unk8;
    u16 unkC;
    u16 unkE;
    u16 w;
    u16 h;
};

extern "C" char lbl_804C0470[0x20];

extern "C" void fn_8038BEF4(TexRect *arg0) {
    arg0->img = lbl_804C0470;
    arg0->unk4 = 0;
    arg0->unk8 = 0;
    arg0->unkC = 0;
    arg0->unkE = 0;
    arg0->w = 640;
    arg0->h = 480;
}

extern "C" void fn_8038BF28(TexRect *arg0, s16 *arg1) {
    arg0->img = lbl_804C0470;
    u16 a = arg1[0];
    arg0->unk4 = 0;
    u16 b = arg1[1];
    arg0->unk8 = 0;
    u16 c = arg1[2];
    u16 d = arg1[3];
    arg0->unkC = a;
    arg0->unkE = b;
    arg0->w = c;
    arg0->h = d;
}

extern "C" void fn_8038BF64(void **arg0, void **arg1, void **arg2, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg_sp0;
}

extern "C" void fn_8038C0E8(void *arg0, void **arg1, void **arg2, void **arg3, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg_sp0;
}

extern "C" void ** fn_8038C35C(void **arg1, void **arg2) {
    (void) arg1;
    (void) arg2;
    return 0;
}

extern "C" char lbl_804F4DB8[0x10];

extern "C" void **fn_8038C434(void **arg0, s16 arg1) {
    if (arg0 != NULL) {
        *arg0 = lbl_804F4DB8;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

extern "C" void * fn_8038C47C(void *arg0, s32 arg1, s32 arg2) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    return 0;
}

#pragma dont_inline on
extern "C" void *fn_8038C560(void *arg0, u32 arg1) {
    *(u32 *) arg0 = arg1;
    return arg0;
}
#pragma dont_inline off

extern "C" void fn_8038C770(void *arg0) {
    (void) arg0;
}

extern "C" void fn_8038C864(void *arg0, u32 arg1, u32 arg2, s32 arg3, u8 arg4) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg4;
}

extern "C" void * fn_8038C8E8(void *arg0, u32 arg1, u8 arg2, s32 arg3) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    return 0;
}

extern "C" void * fn_8038CA48(void *arg0, u32 arg1, u8 arg2, s32 arg3) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    return 0;
}

extern "C" void *lbl_805DDCA0;

extern "C" void fn_8038CB28(u32 arg0) {
    fn_8038C560(lbl_805DDCA0, arg0);
}

extern "C" void fn_8038CB50(u32 arg0) {
    fn_8038C560(lbl_805DDCA0, arg0);
}

#pragma dont_inline on
extern "C" void fn_8038CB78(void *arg0) {
    *(void **) arg0 = arg0;
}
#pragma dont_inline off

struct JointHolder {
    void *vtbl;
    void *unk4;
    void **unk8;
};

extern "C" char lbl_804F4E38[0x18];
extern "C" void *HSD_JObjLoadJoint(void *joint);

extern "C" void *fn_8038CCAC(JointHolder *arg0, void **arg1) {
    arg0->vtbl = lbl_804F4E38;
    arg0->unk8 = arg1;
    arg0->unk4 = HSD_JObjLoadJoint(*arg0->unk8);
    return arg0;
}

extern "C" s32 kar_fl_indirectload__80396f54(s32);

extern "C" void * fn_8038CCF8(JointHolder *arg0, void **arg1, s32 arg2) {
    arg0->vtbl = lbl_804F4E38;
    arg0->unk8 = arg1;
    if (arg2 & 2) {
        arg0->unk4 = (void *) kar_fl_indirectload__80396f54((s32) *arg0->unk8);
    } else {
        arg0->unk4 = HSD_JObjLoadJoint(*arg0->unk8);
    }
    return arg0;
}

extern "C" s32 * fn_8038CD60(void *arg0, s32 *arg1, s32 *arg2, void **arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg_sp0;
    return 0;
}

namespace {
extern "C" s32 *fn_8038CD60(void *arg0, s32 *arg1, s32 *arg2);
}

struct HasTwoPtrs {
    char pad[4];
    s32 *unk4;
    s32 **unk8;
};

extern "C" s32 *fn_8038D0A8(HasTwoPtrs *arg0, s32 *arg1) {
    if (arg1 != NULL) {
        return fn_8038CD60(*arg0->unk8, arg0->unk4, arg1);
    }
    return arg0->unk4;
}

struct HasJointAndArr {
    char pad0[4];
    void *unk4;
    void **unk8;
};

extern "C" void fn_803910B0(void **arg0, s32 *arg1, void **arg2, void **arg3, void **arg4);
extern "C" void HSD_JObjAddAnimAll(void *, void *, void *, void *);
extern "C" void HSD_JObjReqAnimAll(void *, f32);
extern "C" const f32 lbl_805E4E20;

extern "C" void fn_8038D0E8(HasJointAndArr *arg0, s32 *arg1, u8 arg2) {
    void *valueA, *valueB, *valueC;
    fn_803910B0(arg0->unk8, arg1, &valueA, &valueB, &valueC);
    HSD_JObjAddAnimAll(arg0->unk4, valueA, valueB, valueC);
    if (arg2 != 0) {
        HSD_JObjReqAnimAll(arg0->unk4, lbl_805E4E20);
    }
}

extern "C" void kar_object__8038d158(void *arg0, s32 arg1, u8 arg2) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
}

struct HasJObjAt4 {
    char pad[4];
    void *unk4;
};

extern "C" void HSD_JObjDispAll(void *, s32, s32, s32);

extern "C" void fn_8038D20C(HasJObjAt4 *arg0) {
    HSD_JObjDispAll(arg0->unk4, 0, 1, 0);
    HSD_JObjDispAll(arg0->unk4, 0, 4, 0);
    HSD_JObjDispAll(arg0->unk4, 0, 2, 0);
}

extern "C" void * fn_8038D270(void *arg0, void *arg1, s32 arg2, s32 *arg3) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    return 0;
}

extern "C" void * fn_8038D314(void *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg_sp0;
    return 0;
}

extern "C" void fn_8038D3F0(void *arg0, s32 *arg1, void *arg2, void *arg3, void *arg4, void *arg5, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg4;
    (void) arg5;
    (void) arg_sp0;
}

extern "C" u16 fn_8038DA24(void **arg0, u8 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void fn_8038DB14(void *arg0, u8 arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void fn_8038DBC8(void *arg0, u8 arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" f32 fn_8038DD08(u8 arg1) {
    (void) arg1;
    return 0.0f;
}

extern "C" f32 fn_8038DD88(u8 arg1) {
    (void) arg1;
    return 0.0f;
}

extern "C" char lbl_804F4F70[0x24];

extern "C" void *fn_8038DE08(void) {
    return lbl_804F4F70;
}

extern "C" void fn_8038DE14(void) {

}

extern "C" void * fn_8038E2FC(void *arg0, void **arg1, void **arg2, s32 *arg3, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg_sp0;
    return 0;
}

extern "C" void fn_8038E83C(void) {

}

extern "C" void fn_8038E840(void) {

}

extern "C" void * fn_8038E844(void *arg0, void *arg1, void *arg2, void *arg3) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    return 0;
}

extern "C" void * fn_8038EDF8(void *arg0) {
    (void) arg0;
    return 0;
}

extern "C" s32 fn_8038EE94(s32 arg0, s32 arg1, u8 *arg2, u8 *arg3) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    return 0;
}

extern "C" void * kar_diagnostic__8038efe0(void *arg0, void *arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void fn_8038FBE0(f32 *arg0, s32 arg1, s32 arg2, u8 arg3, s32 arg4) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg4;
}

extern "C" void fn_8038FD00(f32 *arg0, s32 arg1, s32 arg2, u8 arg3, s32 arg4) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg4;
}

extern "C" void fn_8038FE20(f32 *arg0, s32 arg1, s32 arg2, u8 arg3, s32 arg4) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg4;
}

extern "C" void fn_8038FF34(f32 *arg0, s32 arg1, s32 arg2, u8 arg3, s32 arg4) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg4;
}

extern "C" void kar_diag__80390048(void *arg0, void *arg1, void *arg2, u8 *arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg_sp0;
}

extern "C" void kar_diagnostic__80390258(void *arg0, void *arg1, void *arg2) {
    (void) arg0;
    if (arg1 != NULL) {
        kar_diag__near_80388ce8(arg1, arg2);
    }
}

struct RefractRecordPayload {
    s32 unk4, unk8, unkC;
    f32 unk10, unk14, unk18, unk1C, unk20, unk24;
    s32 unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44;
    s32 unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64;
    u8 unk68, unk69, unk6A, unk6B, unk6C, unk6D, unk6E, unk6F;
};

struct RefractRecord {
    void *next;
    RefractRecordPayload payload;
};

struct BigRefractObj {
    RefractRecord rec0, rec1, rec2;
    f32 tail0, tail1, tail2;
};

extern "C" void fn_80390288(BigRefractObj *arg0, BigRefractObj *arg1) {
    arg0->rec0.payload = arg1->rec0.payload;
    arg0->rec1.payload = arg1->rec1.payload;
    arg0->rec2.payload = arg1->rec2.payload;
    arg0->tail0 = arg1->tail0;
    arg0->tail1 = arg1->tail1;
    arg0->tail2 = arg1->tail2;
}

extern "C" void kar_diag__803905bc(void *arg0, void *arg1, u32 arg2, void *arg3, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg_sp0;
}

extern "C" void kar_diag__near_803908f4(char *arg0, u32 arg1, void *arg2) {
    while (arg1 != 0) {
        fn_80390288((BigRefractObj *) arg0, (BigRefractObj *) arg2);
        arg0 += 348;
        arg1 -= 1;
    }
}

extern "C" void *kar_diag__near_80390974(u32 arg0, char *arg1, char *arg2);

extern "C" void kar_diag__near_80390954(u32 arg0, void *arg1, void *arg2) {
    kar_diag__near_80390974(arg0, (char *) arg1, (char *) arg2);
}

extern "C" void * kar_diag__near_80390974(u32 arg0, char *arg1, char *arg2) {
    while (arg1 > (char *) arg0) {
        arg2 -= 348;
        arg1 -= 348;
        fn_80390288((BigRefractObj *) arg2, (BigRefractObj *) arg1);
    }
    return arg2;
}

extern "C" void kar_diag__803909d8(void *arg0, u32 arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void ** fn_80390B3C(void **arg0) {
    (void) arg0;
    return 0;
}

extern "C" u32 fn_80390BE0(void *arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

extern "C" void GXSetNumChans(u32);
extern "C" void GXSetChanCtrl(u32, u32, u32, u32, u32, u32, u32);
extern "C" void GXSetTexCoordGen2(u32, u32, u32, u32, u32, u32);
extern "C" void GXSetBlendMode(u32, u32, u32, u32);
extern "C" void GXSetNumTexGens(u32);
extern "C" void GXSetNumTevStages(u32);
extern "C" void GXSetTevOrder(u32, u32, u32, u32);
extern "C" void GXSetTevColorIn(u32, u32, u32, u32, u32);
extern "C" void fn_803CEC68(u32, u32, u32, u32, u32, u32);
extern "C" void GXSetTevAlphaIn(u32, u32, u32, u32, u32);
extern "C" void fn_803CECD0(u32, u32, u32, u32, u32, u32);

extern "C" void fn_80390C74(void) {
    GXSetNumChans(1);
    GXSetChanCtrl(4, 0, 0, 0, 0, 0, 2);
    GXSetTexCoordGen2(0, 1, 4, 60, 0, 125);
    GXSetBlendMode(1, 4, 5, 0);
    GXSetNumTexGens(1);
    GXSetNumTevStages(1);
    GXSetTevOrder(0, 0, 0, 255);
    GXSetTevColorIn(0, 15, 8, 2, 15);
    fn_803CEC68(0, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(0, 7, 4, 1, 7);
    fn_803CECD0(0, 0, 0, 0, 1, 0);
}

extern "C" void fn_80390D74(void *arg0, s32 arg1, s32 arg2, s16 arg3) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
}

extern "C" void fn_80390EB0(void *arg0, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    (void) arg0;
    (void) arg2;
    (void) arg3;
    (void) arg4;
    (void) arg5;
}

extern "C" const f32 lbl_805E4EB8; /* 24.0F */

extern "C" u32 fn_80391080(RippleWave *arg0) {
    return (u32) (lbl_805E4EB8 * arg0->unk8);
}

extern "C" void fn_803910AC(void) {

}

extern "C" void fn_803910B0(void **arg0, s32 *arg1, void **arg2, void **arg3, void **arg4) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg4;
}

extern "C" s32 fn_803911B8(u32 **arg0) {
    u32 *p = *arg0;
    if (p == NULL) {
        return 0;
    }
    s32 count = 0;
    while (*p != 0) {
        p += 1;
        count += 1;
    }
    return count;
}

extern "C" u8 kar_fl_indirectload__80391f10(void *, void *);
extern "C" char lbl_805DC0AC[4];

extern "C" void fn_803911EC(void ***arg0, void *arg1) {
    void **p;
    p = *arg0;
    while (*p != 0) {
        char *inner = (char *) *(void **) *p;
        void *header = *(void **)(inner - 4);
        if (header == 0) {
            header = lbl_805DC0AC;
        }
        if (kar_fl_indirectload__80391f10(arg1, header)) {
            break;
        }
        p += 1;
    }
}

struct HasArrAt8 {
    char pad[8];
    u32 *unk8;
};

extern "C" s32 fn_80391264(HasArrAt8 *arg0) {
    u32 *p = arg0->unk8;
    if (p == NULL) {
        return 0;
    }
    s32 count = 0;
    while (*p != 0) {
        p += 1;
        count += 1;
    }
    return count;
}

extern "C" void fn_80391298(void *arg0, void *arg1, void *arg2, void *arg3, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg_sp0;
}

extern "C" void fn_80391644(void *arg0, s32 arg_sp0) {
    (void) arg0;
    (void) arg_sp0;
}

extern "C" void fn_803919FC(u32 arg1) {
    (void) arg1;
}

extern "C" void fn_80391B1C(void) {
    GXSetBlendMode(1, 4, 5, 0);
    GXSetNumTexGens(1);
    GXSetChanCtrl(4, 0, 0, 0, 0, 0, 2);
    GXSetNumChans(1);
    GXSetTexCoordGen2(0, 1, 4, 60, 0, 125);
    GXSetNumTevStages(1);
    GXSetTevOrder(0, 0, 0, 255);
    GXSetTevColorIn(0, 15, 15, 12, 8);
    fn_803CEC68(0, 0, 0, 0, 1, 0);
    GXSetTevAlphaIn(0, 7, 7, 6, 4);
    fn_803CECD0(0, 0, 0, 0, 1, 0);
}

typedef struct _GXTexObj {
    u32 dummy[8];
} GXTexObj;

typedef struct _GXTlutObj {
    u32 dummy[3];
} GXTlutObj;

extern "C" void GXInitTexObj(void *, void *, u16, u16, u32, u32, u32, u8);
extern "C" void GXLoadTexObj(void *, u32);
extern "C" void GXInitTlutObj(void *, void *, u32, u16);
extern "C" void GXLoadTlut(void *, u32);
extern "C" void GXInitTexObjCI(void *, void *, u16, u16, u32, u32, u32, u32);

extern "C" void fn_80391C1C(u32 arg0, u32 arg1, u32 arg2, void *arg3) {
    GXTexObj tex;
    GXInitTexObj(&tex, arg3, (u16) arg0, (u16) arg1, arg2, 0, 0, 0);
    GXLoadTexObj(&tex, 0);
}

extern "C" void fn_80391C70(u32 arg0, u32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    volatile s32 unused[2];
    GXTlutObj tlut;
    GXInitTlutObj(&tlut, (void *) arg5, arg4, 0);
    GXLoadTlut(&tlut, 0);
    unused[0] = 0;
    GXTexObj tex;
    GXInitTexObjCI(&tex, (void *) arg3, (u16) arg0, (u16) arg1, arg2, 0, 0, 0);
    GXLoadTexObj(&tex, 0);
}

extern "C" void fn_80391D14(void *arg0, s32 arg1, s32 arg2) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
}

extern "C" char lbl_804F5174[0x1C];

extern "C" void **fn_80391EB8(void **arg0, s16 arg1) {
    if (arg0 != NULL) {
        *arg0 = lbl_804F5174;
        if (arg1 > 0) {
            fn_8038CB78(arg0);
        }
    }
    return arg0;
}

struct HasWH {
    char pad[4];
    u16 w;
    u16 h;
};

extern "C" u16 fn_80391F00(HasWH *arg0) {
    return arg0->w;
}

extern "C" u16 fn_80391F08(HasWH *arg0) {
    return arg0->h;
}
