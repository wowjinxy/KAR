#include "functions.h"
#include <dolphin/types.h>
#include <sysdolphin/dobj.h>
#include <sysdolphin/jobj.h>
#include <sysdolphin/mobj.h>
#include <sysdolphin/objalloc.h>

typedef struct VcGenerator VcGenerator;
typedef struct VcGeneratorAssets VcGeneratorAssets;
typedef struct VcGeneratorField4 VcGeneratorField4;
typedef struct VcGeneratorGlobal VcGeneratorGlobal;
typedef struct VcGeneratorRegistryEntry VcGeneratorRegistryEntry;
typedef struct VcFloatC VcFloatC;

struct VcGeneratorField4 {
    u8 pad_0[0x2C];
    void* field_2C;
};

struct VcGenerator {
    s32 audio_handle_0;
    VcGeneratorField4* field_4;
    u8 pad_8[0x10];
    u8 registry_index_18;
    u8 registry_index_19;
    u8 pad_1A[0x2F2];
    f32 field_30C;
    f32 field_310;
    u8 pad_314[0x50C];
    HSD_JObj* jobj_820;
    s32 field_824;
    u8 pad_828[0x34];
    f32 field_85C;
    u8 pad_860[0x40];
    s32 audio_handle_8A0;
    s32 audio_handle_8A4;
};

struct VcGeneratorAssets {
    u8 pad_0[0x18];
    HSD_Joint* joint_18;
};

struct VcGeneratorGlobal {
    u8 pad_0[0x14C];
    f32 field_14C;
    f32 field_150;
    f32 field_154;
    f32 field_158;
    f32 field_15C;
    f32 field_160;
    f32 field_164;
    f32 field_168;
};

struct VcGeneratorRegistryEntry {
    VcGenerator* generator;
    s32 timer;
};

struct VcFloatC {
    u8 pad_0[0xC];
    f32 field_C;
};

extern VcGeneratorAssets* lbl_805DD838;
extern VcGeneratorGlobal* lbl_805DD814;
extern VcGeneratorRegistryEntry* lbl_805DD868;
extern VcGenerator** lbl_805DD870;
extern HSD_ObjAllocData lbl_8055A100;
extern f32 lbl_805E1CA0;

extern s32 kar_lbaudio_stop_track_handle_chain(s32 handle);
extern void fn_80192720(VcGeneratorField4* arg0, GXColor* color);
extern f32 fn_80192048(VcGeneratorField4* arg0);
extern s32 fn_801A8038(void* arg0);

void kar_vcgenerator__near_801dda28(VcGenerator* generator);

void kar_vcgenerator__near_801dd480(VcGenerator* generator)
{
    generator->audio_handle_8A0 = -1;
}

void kar_vcgenerator__near_801dd668(s32* handle)
{
    *handle = -1;
}

void kar_vcgenerator__near_801dd674(VcGenerator* generator)
{
    generator->audio_handle_8A4 = -1;
}

void kar_vcgenerator__near_801dd680(s32* handle)
{
    if (*handle != -1) {
        kar_lbaudio_stop_track_handle_chain(*handle);
        *handle = -1;
    }
}

void kar_vcgenerator__near_801dd9bc(VcGenerator* generator, f32 value)
{
    generator->field_85C = value;
}

void kar_vcgenerator__near_801dd9c4(VcGenerator* generator)
{
    generator->jobj_820 = HSD_JObjLoadJoint(lbl_805DD838->joint_18);
    kar_vcgenerator__near_801dda28(generator);
}

void kar_vcgenerator__near_801dda04(VcGenerator* generator)
{
    RecalcParentTrspBits(generator->jobj_820);
}

void kar_vcgenerator__near_801dda28(VcGenerator* generator)
{
    HSD_DObj* dobj;
    HSD_MObj* mobj;
    GXColor color;

    if (generator->field_4 != NULL) {
        fn_80192720(generator->field_4, &color);
        dobj = HSD_JObjGetDObj(generator->jobj_820->child);
        if (dobj != NULL) {
            mobj = dobj->mobj;
        } else {
            mobj = NULL;
        }
        mobj->mat->diffuse = color;
    }
}

void kar_vcgenerator__near_801dfa74(void* obj)
{
    HSD_ObjFree(&lbl_8055A100, obj);
}

s32 kar_vcgenerator__near_801e024c(VcGenerator* generator)
{
    u8 index = generator->registry_index_18;
    VcGeneratorRegistryEntry* entry;

    if (index != 0x17) {
        entry = &lbl_805DD868[index];
        if (entry->timer > 0) {
            entry->timer--;
        }
        return lbl_805DD868[generator->registry_index_18].timer;
    }
    return -1;
}

VcGenerator* kar_vcgenerator__near_801e02e8(s32 index)
{
    if (lbl_805DD868 != NULL) {
        return lbl_805DD868[index].generator;
    }
    return NULL;
}

VcGenerator* kar_vcgenerator__near_801e0654(s32 index)
{
    if (lbl_805DD870 != NULL) {
        return lbl_805DD870[index];
    }
    return NULL;
}

f32 kar_vcgenerator__near_801e06fc(void)
{
    return lbl_805DD814->field_15C;
}

f32 kar_vcgenerator__near_801e0708(VcGenerator* generator)
{
    if (generator->field_4 != NULL) {
        return fn_80192048(generator->field_4);
    }
    return lbl_805E1CA0;
}

f32 kar_vcgenerator__near_801e073c(void)
{
    return lbl_805DD814->field_168;
}

f32 kar_vcgenerator__near_801e0748(void)
{
    return lbl_805DD814->field_164;
}

f32 kar_vcgenerator__near_801e0754(VcFloatC* value)
{
    return lbl_805DD814->field_160 * value->field_C;
}

f32 kar_vcgenerator__near_801e0768(void)
{
    return lbl_805DD814->field_14C;
}

f32 kar_vcgenerator__near_801e0774(void)
{
    return lbl_805DD814->field_154;
}

f32 kar_vcgenerator__near_801e0780(void)
{
    return lbl_805DD814->field_150;
}

s32 kar_vcgenerator__near_801e078c(VcGenerator* generator)
{
    if (generator->field_4 != NULL) {
        return fn_801A8038(generator->field_4->field_2C);
    }
    return 0;
}
