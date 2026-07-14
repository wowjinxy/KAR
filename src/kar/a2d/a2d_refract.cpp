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

extern "C" void * kar_a2d_refract__near_80384600(void *arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
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

extern "C" void * kar_a2d_refract__near_80384cf0(void *arg0) {
    (void) arg0;
    return 0;
}

struct RippleGroup {
    char pad0[4];
    s32 unk4;
    char pad8[8];
    f32 unk10, unk14, unk18;
    f32 unk1C, unk20, unk24;
};

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

extern "C" void kar_a2d_refract__near_80384ec4(void *arg0, void *arg1) {
    (void) arg0;
    (void) arg1;
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

extern "C" u8 * kar_a2d_refract__near_803851c4(u8 *arg0, f32 farg0) {
    (void) arg0;
    (void) farg0;
    return 0;
}

extern "C" u8 kar_a2d_refract__near_8038521c(void *arg0, u8 *arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
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
    char pad0[0x50];
    u8 count;
};

extern "C" void kar_a2d_refract__near_803852b4(MultiArr *arg0, s8 arg1, s32 arg2, s32 arg3) {
    u32 idx = arg0->count;
    char *slot = (char *) arg0 + idx * 4;
    *(s32 *) (slot + 8) = arg2;
    idx = arg0->count;
    slot = (char *) arg0 + idx * 4;
    *(s32 *) (slot + 0x28) = arg3;
    idx = arg0->count;
    slot = (char *) arg0 + idx;
    *(s8 *) (slot + 0x48) = arg1;
    arg0->count = arg0->count + 1;
}

extern "C" s32 kar_a2d_refract__near_803852f0(void *arg0, void *arg1, void *arg2, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg_sp0;
    return 0;
}

extern "C" s32 kar_a2d_refract__near_803855bc(void *arg0) {
    (void) arg0;
    return 0;
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

extern "C" void * kar_diag__near_803878e4(void *arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
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

extern "C" void kar_diag__near_80387c28(void **arg0, s32 *arg1, void **arg2) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
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

struct DiagArr {
    char pad0[4];
    u32 count;
    char *base;
};

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
    f32 num = farg0 - base;
    f32 den = arg1[0] - base;
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

extern "C" f32 kar_diag__near_8038b964(f32 *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 farg0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) farg0;
    return 0.0f;
}

extern "C" void * kar_diag__8038b9c0(void *arg0, s8 *arg1, void *arg2, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg_sp0;
    return 0;
}

extern "C" void * fn_8038BB68(void *arg0, s16 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
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

extern "C" void fn_8038BC98(void *arg0) {
    (void) arg0;
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

extern "C" void fn_8038BF28(void *arg0, void *arg1) {
    (void) arg0;
    (void) arg1;
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

extern "C" void * fn_8038CCF8(void *arg0, s32 *arg1, s32 arg2) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    return 0;
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

extern "C" void fn_8038D0E8(void *arg0, u8 arg2) {
    (void) arg0;
    (void) arg2;
}

extern "C" void kar_object__8038d158(void *arg0, s32 arg1, u8 arg2) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
}

extern "C" void fn_8038D20C(void *arg0) {
    (void) arg0;
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

extern "C" void fn_80390288(void *arg0, void *arg1) {
    (void) arg0;
    (void) arg1;
}

extern "C" void kar_diag__803905bc(void *arg0, void *arg1, u32 arg2, void *arg3, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg_sp0;
}

extern "C" void kar_diag__near_803908f4(void *arg0, u32 arg1, void *arg2) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
}

extern "C" void *kar_diag__near_80390974(u32 arg0, void *arg1, void *arg2);

extern "C" void kar_diag__near_80390954(u32 arg0, void *arg1, void *arg2) {
    kar_diag__near_80390974(arg0, arg1, arg2);
}

extern "C" void * kar_diag__near_80390974(u32 arg0, void *arg1, void *arg2) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    return 0;
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

extern "C" void fn_80390C74(void) {

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

extern "C" void fn_803910B0(void **arg0, s32 *arg1, void **arg2, void **arg3, void **arg4, s32 arg_sp0) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg4;
    (void) arg_sp0;
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

extern "C" void fn_803911EC(void ****arg0, s32 *arg1) {
    (void) arg0;
    (void) arg1;
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

}

extern "C" void fn_80391C1C(u16 arg0, u16 arg1, u32 arg2, void *arg3) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
}

extern "C" void fn_80391C70(u16 arg0, u16 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    (void) arg0;
    (void) arg1;
    (void) arg2;
    (void) arg3;
    (void) arg4;
    (void) arg5;
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
