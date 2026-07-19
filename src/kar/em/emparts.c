#include "functions.h"
#include <dolphin/mtx/mtx.h>
#include <dolphin/types.h>
#include <kar/em/emparts.h>
#include <kar/lb/lbvector.h>
#include <sysdolphin/class.h>
#include <sysdolphin/dobj.h>
#include <sysdolphin/gobj.h>
#include <sysdolphin/jobj.h>
#include <sysdolphin/mobj.h>
#include <sysdolphin/tobj.h>

#if defined(VERSION_GKYJ01)
#define lbl_804B2820 lbl_804AD568
#define kar_src_emparts_804b2848 lbl_804AD590
#define lbl_804B28F8 lbl_804AD640
#define lbl_804B2918 lbl_804AD660
#define lbl_805D7120 lbl_805D1B60
#define lbl_805E22C0 lbl_805DCB60
#define lbl_805E22C4 lbl_805DCB64
#define fn_801FD0E0 fn_801F93D0
#define fn_801FD714 fn_801F9A04
#elif defined(VERSION_GKYP01)
#define lbl_804B2820 lbl_804B8010
#define kar_src_emparts_804b2848 lbl_804B8038
#define lbl_804B28F8 lbl_804B80E8
#define lbl_804B2918 lbl_804B8108
#define lbl_805D7120 lbl_805C9B08
#define lbl_805E22C0 lbl_805D4D58
#define lbl_805E22C4 lbl_805D4D5C
#define fn_801FD0E0 fn_801FDDB4
#define fn_801FD714 fn_801FE3E8
#endif

#define EMPARTS_MAX_JOBJ 0x20
#define EMPARTS_MAX_DOBJ 0x40
#define EMPARTS_MAX_TOBJ 0x3C
#define EMPARTS_MAX_MODEL_PARTS 0x0B

typedef struct EmAnimFlagsByte {
    u8 flag_80 : 1;
    u8 flag_40 : 1;
    u8 flag_20 : 1;
    u8 flag_10 : 1;
    u8 flag_08 : 1;
    u8 flag_04 : 1;
    u8 flag_02 : 1;
    u8 flag_01 : 1;
} EmAnimFlagsByte;

typedef struct EmAnimTemplateState {
    u8 pad_000[0x28];
    f32 field_028;
    u8 pad_02C[0x2C];
    f32 field_058;
    u8 pad_05C[0x48];
} EmAnimTemplateState;

typedef struct EmPartsIndexList {
    s32 count;
    u8* indices;
} EmPartsIndexList;

typedef struct EmPartsGroup {
    s32 count;
    EmPartsIndexList* lists;
} EmPartsGroup;

typedef struct EmPartsConfig {
    s32 count[3];
    EmPartsGroup* groups[3];
} EmPartsConfig;

typedef struct EmPartsDesc {
    s32 field_000;
    s32 part_count;
    EmPartsConfig config;
} EmPartsDesc;

typedef struct EmAnimSegmentDesc {
    s32 jobj_index;
    u8 data[0x14];
} EmAnimSegmentDesc;

typedef struct EmAnimSegmentList {
    EmAnimSegmentDesc* entries;
    s32 count;
} EmAnimSegmentList;

typedef struct EmAnimTemplateSource {
    EmAnimTemplateState* state;
    u8 pad_004[0x04];
    EmPartsDesc* parts_desc;
    u8 pad_00C[0x04];
    EmAnimSegmentList* segment_list;
    void* field_014;
} EmAnimTemplateSource;

typedef struct EmAnimInfo {
    u8 pad_000[0x08];
    void* field_008;
} EmAnimInfo;

typedef struct EmAnimMotionResource {
    HSD_AnimJoint* joint_anim;
    HSD_MatAnimJoint* mat_anim;
    u8 pad_008[0x04];
    EmAnimFlagsByte flags_0C;
} EmAnimMotionResource;

typedef struct EmPartsState {
    s16 field_00;
    s16 field_02;
} EmPartsState;

struct EmAnim {
    HSD_GObj* gobj;
    u8 pad_004[0x08];
    s32 kind;
    EmAnimInfo* field_010;
    EmAnimTemplateSource* field_014;
    u8 pad_018[0x1C];
    s32 field_034;
    u8 pad_038[0x10];
    EmAnimMotionResource* field_048;
    f32 field_04C;
    f32 field_050;
    void* field_054;
    void* field_058;
    u8 pad_05C[0x14];
    u8 field_070[0x238];
    f32 field_2A8;
    f32 field_2AC;
    f32 field_2B0;
    HSD_JObj** field_2B4;
    u8 pad_2B8[0x04];
    HSD_DObj** field_2BC;
    u8 pad_2C0[0x04];
    HSD_TObj** field_2C4;
    u8 pad_2C8[0x24];
    Vec velocity;
    Vec pos;
    u8 pad_304[0x30];
    Vec dir;
    Vec scale;
    u8 pad_34C[0x18];
    f32 alpha;
    EmAnimTemplateState template_state;
    void* field_40C;
    void* collision_object;
    EmPartsConfig* parts_config;
    u8 parts_visible[3];
    u8 pad_41B;
    EmPartsState parts_state[16];
    u8 field_45C[0xF4];
    Vec field_550;
    u8 pad_55C[0x3BC];
    u32 field_918;
    Vec field_91C;
    Vec field_928;
    u32 field_934;
    Vec field_938;
    Vec field_944;
    u8 pad_950[0x04];
    HSD_GObj* volume_gobj;
    u8 pad_958[0x124];
    s32 fade_frames;
    u8 pad_A80[0x10];
    void* field_A90;
    u8 pad_A94[0x20];
    void (*remove_callback)(EmAnim* anim);
    u8 pad_AB8[0x38];
    u32 field_AF0;
    u32 field_AF4;
    u32 field_AF8;
    u32 field_AFC;
    EmAnimFlagsByte flags_B00;
    u8 pad_B01[0x03];
    f32 field_B04;
    EmAnimFlagsByte flags_B08;
    EmAnimFlagsByte flags_B09;
    EmAnimFlagsByte flags_B0A;
    EmAnimFlagsByte flags_B0B;
    u8 pad_B0C[0x1C];
    f32 field_B28;
    Vec field_B2C;
    Vec field_B38;
};

extern HSD_ClassInfo lbl_804996C0;
extern char lbl_804B2820[];

BOOL fn_801FD0E0(Vec* vec);
void fn_801FD714(EmAnim* anim, Vec* dir, Vec* scale);

char kar_src_emparts_804b2848[] =
    "emparts.c\0\0\0"
    "enemy parts model tobj num over!(%d)\n\0\0\0"
    "enemy dobj num over!(%d)\n\0\0\0"
    "enemy parts num over! %d\n\0\0\0"
    "enemy parts num not match!    kind:%d   parts_no:%d   parts_num:%d\n";
char lbl_804B28F8[] = "enemy parts model num over!\n";
char lbl_804B2918[] = "emUpdateWaitAir    distance is Zero\n";
char lbl_805D7120[] = "0";
const f32 lbl_805E22C0 = 0.0f;
const f32 lbl_805E22C4 = 0.05f;

#define LOAD_F32(sym) (*(const f32*) &(sym))

#define EMPARTS_APPLY_TABLE(anim, table, outer_count, action)                 \
    do {                                                                      \
        s32 outer;                                                            \
        EmPartsGroup* group = (table);                                        \
        for (outer = 0; outer < (outer_count); outer++, group++) {            \
            s32 middle;                                                       \
            EmPartsIndexList* list = group->lists;                            \
            for (middle = 0; middle < group->count; middle++, list++) {       \
                s32 inner;                                                    \
                u8* indices = list->indices;                                  \
                for (inner = 0; inner < list->count; inner++, indices++) {    \
                    HSD_DObj* dobj = (anim)->field_2BC[*indices];             \
                    action(dobj, 1);                                          \
                }                                                             \
            }                                                                 \
        }                                                                     \
    } while (0)

static inline HSD_JObj* emparts_next_jobj(HSD_JObj* jobj)
{
    HSD_JObj* next;
    HSD_JObj* parent;

    if ((HSD_JObjGetFlags(jobj) & INSTANCE) == 0) {
        next = jobj != NULL ? jobj->child : NULL;
        if (next != NULL) {
            return jobj != NULL ? jobj->child : NULL;
        }
    }

    next = jobj != NULL ? jobj->next : NULL;
    if (next != NULL) {
        return jobj != NULL ? jobj->next : NULL;
    }

    while (TRUE) {
        next = jobj != NULL ? jobj->parent : NULL;
        if (next == NULL) {
            return NULL;
        }

        parent = jobj != NULL ? jobj->parent : NULL;
        next = parent != NULL ? parent->next : NULL;
        if (next != NULL) {
            parent = jobj != NULL ? jobj->parent : NULL;
            return parent != NULL ? parent->next : NULL;
        }

        jobj = jobj != NULL ? jobj->parent : NULL;
    }
}

void kar_emparts__802026d4(EmAnim* anim)
{
    HSD_JObj* jobj;
    char* strings;
    s32 jobj_count;
    s32 dobj_count;
    s32 tobj_count;
    s32 jobj_offset;
    s32 dobj_offset;
    s32 tobj_offset;

    strings = lbl_804B2820;
    jobj = anim->gobj->hsd_obj;
    jobj_count = 0;
    dobj_count = 0;
    tobj_count = 0;
    jobj_offset = 0;
    dobj_offset = 0;
    tobj_offset = 0;

    if (anim->field_014->parts_desc->part_count >= EMPARTS_MAX_JOBJ) {
        OSReport(&strings[0x78], anim->kind);
        __assert(&strings[0x28], 0x58, lbl_805D7120);
    }

    while (jobj != NULL) {
        HSD_DObj* dobj;
        s32 model_dobj_count;

        *(HSD_JObj**) ((u8*) anim->field_2B4 + jobj_offset) = jobj;
        dobj = HSD_JObjGetDObj(jobj);
        HSD_JObjGetFlags(jobj);
        *(HSD_JObj**) ((u8*) anim->field_2B4 + jobj_offset) = jobj;
        model_dobj_count = 0;

        while (dobj != NULL) {
            HSD_MObj* mobj;
            HSD_TObj* tobj;

            if (dobj_count >= EMPARTS_MAX_DOBJ) {
                OSReport(strings, anim->kind);
                __assert(&strings[0x28], 0x2A, lbl_805D7120);
            }

            *(HSD_DObj**) ((u8*) anim->field_2BC + dobj_offset) = dobj;
            mobj = dobj != NULL ? dobj->mobj : NULL;
            if (mobj != NULL) {
                tobj = HSD_MObjGetTObj(mobj);
                hsdChangeClass((HSD_Class*) mobj, &lbl_804996C0);

                while (tobj != NULL) {
                    if (tobj_count >= EMPARTS_MAX_TOBJ) {
                        OSReport(&strings[0x34], anim->kind);
                        __assert(&strings[0x28], 0x3A, lbl_805D7120);
                    }

                    *(HSD_TObj**) ((u8*) anim->field_2C4 + tobj_offset) =
                        tobj;
                    tobj = HSD_TObjGetNext(tobj);
                    tobj_offset += sizeof(HSD_TObj*);
                    tobj_count++;
                }
            }

            dobj = dobj != NULL ? dobj->next : NULL;
            dobj_offset += sizeof(HSD_DObj*);
            dobj_count++;
            model_dobj_count++;
        }

        if (model_dobj_count >= 0x80) {
            OSReport(&strings[0x5C], anim->kind);
            __assert(&strings[0x28], 0x4A, lbl_805D7120);
        }

        jobj = emparts_next_jobj(jobj);
        jobj_offset += sizeof(HSD_JObj*);
        jobj_count++;
    }

    if (jobj_count != anim->field_014->parts_desc->part_count) {
        OSReport(&strings[0x94], anim->kind, jobj_count,
                 anim->field_014->parts_desc->part_count);
        __assert(&strings[0x28], 0x7C, lbl_805D7120);
    }

    anim->field_918 = 0;
    anim->field_91C = anim->dir;
    anim->field_928 = anim->scale;
    anim->field_934 = 0;
    anim->field_938 = anim->dir;
    anim->field_944 = anim->scale;
}

void kar_emparts__80202a40(EmAnim* anim)
{
    s32 i;
    EmPartsConfig* config;
    s16 inactive;
    s16 invalid;

    config = &anim->field_014->parts_desc->config;
    anim->parts_config = config;
    for (i = 0; i < 3; i++) {
        if (config->count[i] > EMPARTS_MAX_MODEL_PARTS) {
            OSReport(lbl_804B28F8);
            __assert(kar_src_emparts_804b2848, 0x96, lbl_805D7120);
        }
        anim->parts_visible[i] = TRUE;
        kar_emparts__near_80202c80(&anim->parts_config, i, &anim->pad_2B8);
    }

    if (anim->parts_config != NULL) {
        inactive = -2;
        invalid = -1;
        for (i = 0; i < anim->parts_config->count[0]; i++) {
            anim->parts_state[i].field_02 = inactive;
            anim->parts_state[i].field_00 = invalid;
        }
        for (i = 0; i < anim->parts_config->count[1]; i++) {
            anim->parts_state[i].field_02 = inactive;
            anim->parts_state[i].field_00 = invalid;
        }
        for (i = 0; i < anim->parts_config->count[2]; i++) {
            anim->parts_state[i].field_02 = inactive;
            anim->parts_state[i].field_00 = invalid;
        }
        kar_emparts__near_80202b88(anim);
    }
}

void kar_emparts__near_80202b88(EmAnim* anim)
{
    s32 group_index;
    s32 i;

    if (anim->parts_config != NULL) {
        for (group_index = 0; group_index < 3; group_index++) {
            for (i = 0; i < anim->parts_config->count[group_index]; i++) {
                kar_emparts__near_80202c18(anim, i, -1);
            }
        }
    }
}

void kar_emparts__near_80202c18(EmAnim* anim, s32 index, s32 value)
{
    s32 i;

    if (value != anim->parts_state[index].field_02) {
        anim->parts_state[index].field_02 = value;
        for (i = 0; i < 3; i++) {
            kar_emparts__near_80202c80(&anim->parts_config, i,
                                       &anim->pad_2B8);
        }
    }
}

void kar_emparts__near_80202c80(void* config_arg, s32 kind, void* tables_arg)
{
    EmPartsConfig** config_ptr;
    EmPartsConfig* config;
    EmPartsGroup* group;
    HSD_DObj*** tables;
    s32 outer;

    config_ptr = config_arg;
    config = *config_ptr;
    tables = tables_arg;
    group = config->groups[kind];

    if (group != NULL) {
        for (outer = 0; outer < config->count[kind]; outer++, group++) {
            s32 middle;
            s32 list_offset;

            for (middle = 0, list_offset = 0; middle < group->count;
                 middle++, list_offset += sizeof(EmPartsIndexList)) {
                s32 inner;
                EmPartsIndexList* list;
                u8* indices;

                list = (EmPartsIndexList*) ((u8*) group->lists + list_offset);
                indices = list->indices;

                for (inner = 0; inner < list->count; inner++, indices++) {
                    HSD_DObjSetFlags(tables[1][*indices], 1);
                }
            }
        }
        *((u8*) config_ptr + 4 + kind) = FALSE;
    }
}

void kar_emparts__near_80202d60(EmAnim* anim, s32 mode)
{
    EmPartsConfig* config;

    config = anim->parts_config;
    switch (mode) {
    case 0:
        if (config != NULL && config->groups[0] != NULL) {
            EMPARTS_APPLY_TABLE(anim, config->groups[0], config->count[0],
                                HSD_DObjClearFlags);
            anim->parts_visible[0] = TRUE;
        }
        if (config != NULL && config->groups[1] != NULL) {
            EMPARTS_APPLY_TABLE(anim, config->groups[1], config->count[1],
                                HSD_DObjSetFlags);
            anim->parts_visible[1] = FALSE;
        }
        if (config != NULL && config->groups[2] != NULL) {
            EMPARTS_APPLY_TABLE(anim, config->groups[2], config->count[2],
                                HSD_DObjSetFlags);
            anim->parts_visible[2] = FALSE;
        }
        break;
    case 1:
        if (config != NULL && config->groups[0] != NULL) {
            EMPARTS_APPLY_TABLE(anim, config->groups[0], config->count[0],
                                HSD_DObjSetFlags);
            anim->parts_visible[0] = FALSE;
        }
        if (config != NULL && config->groups[1] != NULL) {
            EMPARTS_APPLY_TABLE(anim, config->groups[1], config->count[1],
                                HSD_DObjClearFlags);
            anim->parts_visible[1] = TRUE;
        }
        if (config != NULL && config->groups[2] != NULL) {
            EMPARTS_APPLY_TABLE(anim, config->groups[2], config->count[2],
                                HSD_DObjSetFlags);
            anim->parts_visible[2] = FALSE;
        }
        break;
    case 2:
        if (config != NULL && config->groups[0] != NULL) {
            EMPARTS_APPLY_TABLE(anim, config->groups[0], config->count[0],
                                HSD_DObjSetFlags);
            anim->parts_visible[0] = FALSE;
        }
        if (config != NULL && config->groups[1] != NULL) {
            EMPARTS_APPLY_TABLE(anim, config->groups[1], config->count[1],
                                HSD_DObjSetFlags);
            anim->parts_visible[1] = FALSE;
        }
        if (config != NULL && config->groups[2] != NULL) {
            EMPARTS_APPLY_TABLE(anim, config->groups[2], config->count[2],
                                HSD_DObjClearFlags);
            anim->parts_visible[2] = TRUE;
        }
        break;
    }
}

void kar_emparts__near_8020335c(EmAnim* anim)
{
    Mtx mtx;
    Vec axis;
    Vec out;
    Vec cross;

    cross.x = anim->scale.y * anim->dir.z - anim->scale.z * anim->dir.y;
    cross.y = anim->scale.z * anim->dir.x - anim->scale.x * anim->dir.z;
    cross.z = anim->scale.x * anim->dir.y - anim->scale.y * anim->dir.x;
    axis = cross;

    mtx[0][0] = axis.x;
    mtx[0][1] = anim->scale.x;
    mtx[0][2] = anim->dir.x;
    mtx[0][3] = LOAD_F32(lbl_805E22C0);
    mtx[1][0] = axis.y;
    mtx[1][1] = anim->scale.y;
    mtx[1][2] = anim->dir.y;
    mtx[1][3] = LOAD_F32(lbl_805E22C0);
    mtx[2][0] = axis.z;
    mtx[2][1] = anim->scale.z;
    mtx[2][2] = anim->dir.z;
    mtx[2][3] = LOAD_F32(lbl_805E22C0);

    PSMTXMultVec(mtx, &anim->field_550, &out);
    anim->pos.x += out.x;
    anim->pos.y += out.y;
    anim->pos.z += out.z;
}

void kar_emparts__near_80203458(EmAnim* anim)
{
    Vec dir;
    f32 speed;

    if (fn_801FD0E0(&anim->velocity) == FALSE) {
        if (LOAD_F32(lbl_805E22C0) != anim->field_B28) {
            anim->field_B28 -= LOAD_F32(lbl_805E22C4);
            if (anim->field_B28 > LOAD_F32(lbl_805E22C0)) {
                kar_lbvector_lerp(&anim->field_B38, &anim->field_B2C, &dir,
                                  anim->field_B28);
                if (fn_801FD0E0(&dir) != FALSE) {
                    dir = anim->field_B2C;
                }
                kar_lbvector_normalize_with_axis_fallback(&dir, &dir);
                fn_801FD714(anim, &dir, &anim->scale);
            } else {
                anim->field_B28 = LOAD_F32(lbl_805E22C0);
                fn_801FD714(anim, &anim->field_B38, &anim->scale);
            }
        }

        speed = anim->template_state.field_028;
        anim->velocity.x = anim->dir.x * speed;
        anim->velocity.y = anim->dir.y * speed;
        anim->velocity.z = anim->dir.z * speed;
    }
}
