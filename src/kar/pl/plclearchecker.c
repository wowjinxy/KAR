#include "functions.h"
#include <dolphin/mtx/mtxtypes.h>
#include <dolphin/types.h>
#include <kar/gm/gmdiag.h>
#include <kar/vc/vcgenerator.h>

#if defined(VERSION_GKYJ01)
#define plclearchecker_player_template_table lbl_805554C8
#define lbl_805DD898 lbl_805D82F0
#define kar_clobject__near_8018e21c fn_8018AB18
#define fn_80192468 fn_8018ED38
#define fn_80191BF8 fn_8018E4C8
#define fn_80191C18 fn_8018E4E8
#define fn_801C552C fn_801C1C34
#define fn_801C7648 fn_801C3D10
#define fn_801C7EF4 fn_801C45B4
#define fn_801C863C fn_801C4CFC
#elif defined(VERSION_GKYP01)
#define plclearchecker_player_template_table lbl_8054D360
#define lbl_805DD898 lbl_805D02E0
#define kar_clobject__near_8018e21c fn_8018EF84
#define fn_80192468 fn_801931D0
#define fn_80191BF8 fn_80192960
#define fn_80191C18 fn_80192980
#define fn_801C552C fn_801C6208
#define fn_801C7648 fn_801C8324
#define fn_801C7EF4 fn_801C8BD0
#define fn_801C863C fn_801C9318
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
    u8 payload_044[0x48];
    u8 byte_08C;
    u8 byte_08D;
    u8 byte_08E;
    u8 byte_08F;
    u8 pad_090[0x878];
    volatile u8 flags_908;
    u8 flags_909;
    u8 pad_90A[0x2];
};

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

#define LOAD_U8(base, offset) (*(u8*) ((u8*) (base) + (offset)))
#define LOAD_U32(base, offset) (*(u32*) ((u8*) (base) + (offset)))
#define LOAD_F32(base, offset) (*(f32*) ((u8*) (base) + (offset)))
#define STORE_U8(base, offset, value) (*(u8*) ((u8*) (base) + (offset)) = (value))
#define STORE_U32(base, offset, value) (*(u32*) ((u8*) (base) + (offset)) = (value))
#define STORE_F32(base, offset, value) (*(f32*) ((u8*) (base) + (offset)) = (value))

#define COPY_U32(dst, dst_off, src, src_off) STORE_U32(dst, dst_off, LOAD_U32(src, src_off))
#define COPY_F32(dst, dst_off, src, src_off) STORE_F32(dst, dst_off, LOAD_F32(src, src_off))

#define FILL_CLOBJECT_ARGS(args, template, first_byte, flag_byte)                     \
    do {                                                                             \
        COPY_U32(args, 0x00, template, 0x04);                                        \
        STORE_U8(args, 0x04, first_byte);                                            \
        STORE_U32(args, 0x08, LOAD_U8(template, 0x8E));                              \
        STORE_U8(args, 0x0C, LOAD_U8(template, 0x8F));                               \
        COPY_U32(args, 0x10, template, 0x08);                                        \
        COPY_U32(args, 0x14, template, 0x0C);                                        \
        COPY_U32(args, 0x18, template, 0x10);                                        \
        COPY_U32(args, 0x1C, template, 0x14);                                        \
        COPY_U32(args, 0x20, template, 0x18);                                        \
        COPY_U32(args, 0x24, template, 0x1C);                                        \
        COPY_U32(args, 0x28, template, 0x20);                                        \
        COPY_U32(args, 0x2C, template, 0x24);                                        \
        COPY_U32(args, 0x30, template, 0x28);                                        \
        COPY_F32(args, 0x34, template, 0x2C);                                        \
        COPY_U32(args, 0x38, template, 0x44);                                        \
        COPY_U32(args, 0x3C, template, 0x48);                                        \
        COPY_U32(args, 0x40, template, 0x4C);                                        \
        COPY_U32(args, 0x44, template, 0x50);                                        \
        COPY_U32(args, 0x48, template, 0x54);                                        \
        COPY_U32(args, 0x4C, template, 0x58);                                        \
        COPY_U32(args, 0x50, template, 0x5C);                                        \
        COPY_U32(args, 0x54, template, 0x60);                                        \
        COPY_U32(args, 0x58, template, 0x64);                                        \
        STORE_U8(args, 0x5C, flag_byte);                                             \
    } while (0)

#define FILL_RUNTIME_ARGS(args, template, flag_byte)                                 \
    do {                                                                             \
        STORE_U32(args, 0x00, LOAD_U8(template, 0x8E));                              \
        STORE_U8(args, 0x04, LOAD_U8(template, 0x8F));                               \
        COPY_U32(args, 0x08, template, 0x08);                                        \
        COPY_U32(args, 0x0C, template, 0x0C);                                        \
        COPY_U32(args, 0x10, template, 0x10);                                        \
        COPY_U32(args, 0x14, template, 0x14);                                        \
        COPY_U32(args, 0x18, template, 0x18);                                        \
        COPY_U32(args, 0x1C, template, 0x1C);                                        \
        COPY_U32(args, 0x20, template, 0x20);                                        \
        COPY_U32(args, 0x24, template, 0x24);                                        \
        COPY_U32(args, 0x28, template, 0x28);                                        \
        COPY_F32(args, 0x2C, template, 0x30);                                        \
        STORE_U8(args, 0x81, flag_byte);                                             \
        COPY_F32(args, 0x30, template, 0x34);                                        \
        COPY_F32(args, 0x34, template, 0x38);                                        \
        COPY_U32(args, 0x38, template, 0x44);                                        \
        COPY_U32(args, 0x3C, template, 0x48);                                        \
        COPY_U32(args, 0x40, template, 0x4C);                                        \
        COPY_U32(args, 0x44, template, 0x50);                                        \
        COPY_U32(args, 0x48, template, 0x54);                                        \
        COPY_U32(args, 0x4C, template, 0x58);                                        \
        COPY_U32(args, 0x50, template, 0x5C);                                        \
        COPY_U32(args, 0x54, template, 0x60);                                        \
        COPY_U32(args, 0x58, template, 0x64);                                        \
        COPY_U32(args, 0x5C, template, 0x68);                                        \
        COPY_U32(args, 0x60, template, 0x6C);                                        \
        COPY_U32(args, 0x64, template, 0x70);                                        \
        COPY_U32(args, 0x68, template, 0x74);                                        \
        COPY_U32(args, 0x6C, template, 0x78);                                        \
        COPY_U32(args, 0x70, template, 0x7C);                                        \
        COPY_U32(args, 0x74, template, 0x80);                                        \
        COPY_U32(args, 0x78, template, 0x84);                                        \
        COPY_U32(args, 0x7C, template, 0x88);                                        \
        STORE_U8(args, 0x80, 0);                                                     \
    } while (0)

void kar_plclearchecker_create_first_player_objects(void)
{
    PlClearCheckerTemplate* template = PLCC_TEMPLATE(0);
    u8 cl_args[0x60];
    u8 runtime_args[0x84];
    u8 cl_flags = 0;
    u8 runtime_flags = 0;

    if (template->unk_000 == (void*) 2) {
        cl_flags |= 0x80;
    }
    cl_flags |= ((template->flags_909 >> 5) & 1) << 6;

    FILL_CLOBJECT_ARGS(cl_args, template, 0, cl_flags);
    template->cl_object = kar_clobject__near_8018e21c(cl_args);

    if (template->unk_000 == (void*) 2) {
        runtime_flags |= 0x40;
    } else {
        runtime_flags |= 0x20;
        if ((s8) kar_diag__8000acb0() != 0 &&
            (s8) kar_vcgenerator__8000af38() != 2) {
            runtime_flags |= 0x10;
        }
    }

    FILL_RUNTIME_ARGS(runtime_args, template, runtime_flags);
    template->object_040 = fn_801C552C(runtime_args);
    fn_80192468(template->cl_object, 0, 2, template->object_040);
}

void kar_plclearchecker_create_current_player_object(s32 slot)
{
    PlClearCheckerTemplate* template = PLCC_TEMPLATE(slot);
    u8 runtime_args[0x84];
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

    FILL_RUNTIME_ARGS(runtime_args, template, runtime_flags);
    template->object_040 = fn_801C552C(runtime_args);
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
