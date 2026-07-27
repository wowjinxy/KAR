#include "functions.h"
#include <dolphin/mtx/mtxtypes.h>
#include <dolphin/types.h>
#include <kar/gm/gmdiag.h>
#include <kar/vc/vcgenerator.h>

#if defined(VERSION_GKYJ01)
#define plclearchecker_player_template_table lbl_805554C8
#define lbl_805DD898 lbl_805D82F0
#define kar_clobject__near_8018e21c fn_8018AB18
#elif defined(VERSION_GKYP01)
#define plclearchecker_player_template_table lbl_8054D360
#define lbl_805DD898 lbl_805D02E0
#define kar_clobject__near_8018e21c fn_8018EF84
#endif

typedef struct PlClearCheckerTemplate PlClearCheckerTemplate;

struct PlClearCheckerTemplate {
    void* unk_000;
    void* unk_004;
    Vec vec_008;
    Vec vec_014;
    Vec vec_020;
    f32 float_02C;
    f32 float_030;
    f32 float_034;
    f32 float_038;
    void* cl_object;
    void* object_040;
    u32 payload_044[18];
    u8 byte_08C;
    u8 byte_08D;
    u8 byte_08E;
    u8 byte_08F;
    u8 pad_090[0x878];
    volatile u8 flags_908;
    u8 flags_909;
    u8 pad_90A[0x2];
};

typedef struct PlClearCheckerClObjectArgs {
    void* unk_00;
    u8 first_byte;
    u8 pad_05[3];
    u32 player_kind;
    u8 variant;
    u8 pad_0D[3];
    Vec vec_10;
    Vec vec_1C;
    Vec vec_28;
    f32 float_34;
    u32 payload_38[9];
    u8 flags;
    u8 pad_5D[3];
} PlClearCheckerClObjectArgs;

typedef struct PlClearCheckerRuntimeArgs {
    u32 player_kind;
    u8 variant;
    u8 pad_05[3];
    Vec vec_08;
    Vec vec_14;
    Vec vec_20;
    f32 float_2C;
    f32 float_30;
    f32 float_34;
    u32 payload_38[18];
    u8 byte_80;
    u8 flags;
    u8 pad_82[2];
} PlClearCheckerRuntimeArgs;

u64 plclearchecker_player_template_table[0x5A8];

extern s8 lbl_805DD898;

void* kar_clobject__near_8018e21c(void* arg);
void* fn_801C552C(void* arg);
void fn_80192468(void* arg0, s32 arg1, s32 arg2, void* arg3);
void fn_801C863C(void* arg0, s32 arg1, s32 arg2);
s32 fn_801C7EF4(void* arg);
void fn_801C7628(void* arg);
void fn_801C7648(void* arg);
void fn_80191BF8(void* arg);
void fn_80191C18(void* arg);
#define PLCC_TEMPLATE_SIZE 0x90C
#define PLCC_TEMPLATE(slot)                                                           \
    ((PlClearCheckerTemplate*) ((u8*) plclearchecker_player_template_table +          \
                                ((slot) * PLCC_TEMPLATE_SIZE)))

void kar_plclearchecker_create_first_player_objects(void)
{
    PlClearCheckerTemplate* template = PLCC_TEMPLATE(0);
    PlClearCheckerClObjectArgs cl_args;
    PlClearCheckerRuntimeArgs runtime_args;
    u8 cl_flags = 0;
    u8 runtime_flags = 0;

    if (template->unk_000 == (void*) 2) {
        cl_flags |= 0x80;
    }
    cl_flags |= ((template->flags_909 >> 5) & 1) << 6;

    cl_args.unk_00 = template->unk_004;
    cl_args.first_byte = 0;
    cl_args.player_kind = template->byte_08E;
    cl_args.variant = template->byte_08F;
    cl_args.vec_10 = template->vec_008;
    cl_args.vec_1C = template->vec_014;
    cl_args.vec_28 = template->vec_020;
    cl_args.float_34 = template->float_02C;
    cl_args.payload_38[0] = template->payload_044[0];
    cl_args.payload_38[1] = template->payload_044[1];
    cl_args.payload_38[2] = template->payload_044[2];
    cl_args.payload_38[3] = template->payload_044[3];
    cl_args.payload_38[4] = template->payload_044[4];
    cl_args.payload_38[5] = template->payload_044[5];
    cl_args.payload_38[6] = template->payload_044[6];
    cl_args.payload_38[7] = template->payload_044[7];
    cl_args.payload_38[8] = template->payload_044[8];
    cl_args.flags = cl_flags;
    template->cl_object = kar_clobject__near_8018e21c(&cl_args);

    if (template->unk_000 == (void*) 2) {
        runtime_flags |= 0x40;
    } else {
        runtime_flags |= 0x20;
        if ((s8) kar_diag__8000acb0() != 0 &&
            (s8) kar_vcgenerator__8000af38() != 2) {
            runtime_flags |= 0x10;
        }
    }

    runtime_args.player_kind = template->byte_08E;
    runtime_args.variant = template->byte_08F;
    runtime_args.vec_08 = template->vec_008;
    runtime_args.vec_14 = template->vec_014;
    runtime_args.vec_20 = template->vec_020;
    runtime_args.float_2C = template->float_030;
    runtime_args.flags = runtime_flags;
    runtime_args.float_30 = template->float_034;
    runtime_args.float_34 = template->float_038;
    runtime_args.payload_38[0] = template->payload_044[0];
    runtime_args.payload_38[1] = template->payload_044[1];
    runtime_args.payload_38[2] = template->payload_044[2];
    runtime_args.payload_38[3] = template->payload_044[3];
    runtime_args.payload_38[4] = template->payload_044[4];
    runtime_args.payload_38[5] = template->payload_044[5];
    runtime_args.payload_38[6] = template->payload_044[6];
    runtime_args.payload_38[7] = template->payload_044[7];
    runtime_args.payload_38[8] = template->payload_044[8];
    runtime_args.payload_38[9] = template->payload_044[9];
    runtime_args.payload_38[10] = template->payload_044[10];
    runtime_args.payload_38[11] = template->payload_044[11];
    runtime_args.payload_38[12] = template->payload_044[12];
    runtime_args.payload_38[13] = template->payload_044[13];
    runtime_args.payload_38[14] = template->payload_044[14];
    runtime_args.payload_38[15] = template->payload_044[15];
    runtime_args.payload_38[16] = template->payload_044[16];
    runtime_args.payload_38[17] = template->payload_044[17];
    runtime_args.byte_80 = 0;
    template->object_040 = fn_801C552C(&runtime_args);
    fn_80192468(template->cl_object, 0, 2, template->object_040);
}

void kar_plclearchecker_create_current_player_object(s32 slot)
{
    PlClearCheckerTemplate* template = PLCC_TEMPLATE(slot);
    PlClearCheckerRuntimeArgs runtime_args;
    u8 runtime_flags = 0;

    if (template->unk_000 == (void*) 2) {
        runtime_flags |= 0x40;
    } else {
        runtime_flags |= 0x20;
        if ((s8) kar_diag__8000acb0() != 0 &&
            (s8) kar_vcgenerator__8000af38() != 2) {
            runtime_flags |= 0x10;
        }
    }

    runtime_args.player_kind = template->byte_08E;
    runtime_args.variant = template->byte_08F;
    runtime_args.vec_08 = template->vec_008;
    runtime_args.vec_14 = template->vec_014;
    runtime_args.vec_20 = template->vec_020;
    runtime_args.float_2C = template->float_030;
    runtime_args.flags = runtime_flags;
    runtime_args.float_30 = template->float_034;
    runtime_args.float_34 = template->float_038;
    runtime_args.payload_38[0] = template->payload_044[0];
    runtime_args.payload_38[1] = template->payload_044[1];
    runtime_args.payload_38[2] = template->payload_044[2];
    runtime_args.payload_38[3] = template->payload_044[3];
    runtime_args.payload_38[4] = template->payload_044[4];
    runtime_args.payload_38[5] = template->payload_044[5];
    runtime_args.payload_38[6] = template->payload_044[6];
    runtime_args.payload_38[7] = template->payload_044[7];
    runtime_args.payload_38[8] = template->payload_044[8];
    runtime_args.payload_38[9] = template->payload_044[9];
    runtime_args.payload_38[10] = template->payload_044[10];
    runtime_args.payload_38[11] = template->payload_044[11];
    runtime_args.payload_38[12] = template->payload_044[12];
    runtime_args.payload_38[13] = template->payload_044[13];
    runtime_args.payload_38[14] = template->payload_044[14];
    runtime_args.payload_38[15] = template->payload_044[15];
    runtime_args.payload_38[16] = template->payload_044[16];
    runtime_args.payload_38[17] = template->payload_044[17];
    runtime_args.byte_80 = 0;
    template->object_040 = fn_801C552C(&runtime_args);
    fn_801C863C(template->object_040, slot, 3);
}

void kar_plclearchecker_get_template_vec_008(s32 slot, Vec* out)
{
    *out = PLCC_TEMPLATE(slot)->vec_008;
}

void kar_plclearchecker_set_template_vec_008(s32 slot, Vec* value)
{
    PLCC_TEMPLATE(slot)->vec_008 = *value;
}

void kar_plclearchecker_get_template_vecs_014_020(s32 slot, Vec* out0,
                                                  Vec* out1)
{
    *out0 = PLCC_TEMPLATE(slot)->vec_014;
    *out1 = PLCC_TEMPLATE(slot)->vec_020;
}

void kar_plclearchecker_set_template_vecs_014_020(s32 slot, Vec* value0,
                                                  Vec* value1)
{
    PLCC_TEMPLATE(slot)->vec_014 = *value0;
    PLCC_TEMPLATE(slot)->vec_020 = *value1;
}

f32 kar_plclearchecker_get_template_float_030(s32 slot)
{
    return PLCC_TEMPLATE(slot)->float_030;
}

void kar_plclearchecker_set_template_float_02c_030(s32 slot, f32 value)
{
    PLCC_TEMPLATE(slot)->float_02C = value;
    PLCC_TEMPLATE(slot)->float_030 = value;
}

u8 kar_plclearchecker_get_template_byte_08c(s32 slot)
{
    return PLCC_TEMPLATE(slot)->byte_08C;
}

void kar_plclearchecker_set_template_byte_08c(s32 slot, u8 value)
{
    PLCC_TEMPLATE(slot)->byte_08C = value;
}

u8 kar_plclearchecker_get_template_byte_08d(s32 slot)
{
    return PLCC_TEMPLATE(slot)->byte_08D;
}

s32 kar_plclearchecker_get_player_index_for_slot(s32 slot)
{
    if (slot != 4) {
        return *(&lbl_805DD898 + slot);
    }
    return 5;
}

void kar_plclearchecker_set_slot_player_index(s32 slot, s32 player_index)
{
    PLCC_TEMPLATE(slot)->byte_08D = player_index;
    if (player_index != 4) {
        *(&lbl_805DD898 + player_index) = slot;
    }
}

s32 kar_plclearchecker_get_runtime_status(s32 slot)
{
    void* object = PLCC_TEMPLATE(slot)->object_040;

    if (object != NULL) {
        return fn_801C7EF4(object);
    }
    return 0;
}

void kar_plclearchecker_begin_object_action(s32 slot)
{
    PlClearCheckerTemplate* template = PLCC_TEMPLATE(slot);

    if (template->object_040 != NULL) {
        fn_801C7628(template->object_040);
    } else {
        fn_80191BF8(template->cl_object);
    }
}

void kar_plclearchecker_end_object_action(s32 slot)
{
    PlClearCheckerTemplate* template = PLCC_TEMPLATE(slot);

    if (template->object_040 != NULL) {
        fn_801C7648(template->object_040);
    } else {
        fn_80191C18(template->cl_object);
    }
}
