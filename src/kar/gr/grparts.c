#include "functions.h"
#include <dolphin/mtx/vec.h>
#include <dolphin/types.h>
#include <kar/gr/grparts.h>
#include <kar/gr/gryaku.h>
#include <kar/lb/lbvector.h>
#include <sysdolphin/jobj.h>
#include <sysdolphin/memory.h>
#include <sysdolphin/mtx.h>

#define GRPARTS_ZERO 0.0f
#define GRPARTS_EPSILON 0.00001f
#define GRPARTS_NEG_EPSILON -0.00001f
#define GRPARTS_ONE 1.0f
#define GRPARTS_NEG_ONE -1.0f
#define GRPARTS_AABB_EPSILON 0.01f
#define GRPARTS_NEG_AABB_EPSILON -0.01f
#define GRPARTS_FACE_STRIDE 0x40

typedef struct GrPartsAlloc GrPartsAlloc;
typedef struct Ground Ground;
typedef struct GroundData GroundData;
typedef struct GroundPosData GroundPosData;
typedef struct PartConfig PartConfig;

struct GrPartsAlloc {
    void* parts;
    void* links;
    void* extra;
};

struct Ground {
    u8 pad_000[0x08];
    GroundData* data;
    u8 pad_00C[0x6F4];
    void* gr_kdcoll_tree;
    void* gr_kdcoll_query;
};

struct GroundData {
    u8 pad_00[0x20];
    GroundPosData* pos;
    void* enemy;
    void* item;
    void* event_;
};

struct GroundPosData {
    void* unk_00;
    void* startpos;
    void* enemypos;
    u8 pad_0C[0x0C];
    void* itempos;
    void* vehiclepos;
    u8 pad_24[0x0C];
    void* item_areapos;
    void* vehicle_areapos;
};

struct PartConfig {
    void* joint;
    s32 part_count;
    s32 link_count;
    s32 extra_count;
};

char kar_src_grparts_804a3e10[] = "grparts.c";
char lbl_804A3E1C[] = "partsAll->parts";
char kar_src_grcoll_804a3e30[] = "grcoll.h";
char lbl_804A3E3C[] = "!grCollChkFaceIllegal(gcp, id)";
char kar_src_lbkdtree_804a3e5c[] = "lbkdtree.h";
char lbl_804A3E68[] = "tree->cache_id < tree->cache_num";

extern Ground* kar_gryaku_current_ground;

HSD_Joint* kar_lbairride__near_80055da0(void);
void kar_grcoll__near_800d86fc(HSD_JObj* jobj, void* cb_args, s32 type);
void kar_grcoll__near_800d87ec(GrPartsAlloc* parts, void* arg, s32* out);
void kar_grcoll__800d7118(void* gcp, s32 id, Vec* pos, Vec* dir, Vec* scale);
u8 fn_800092B4(void);
u8 kar_diag__8000a2a0(void);
s32 fn_8000A348(void);
s32 kar_grcoursespline__802622e0(void);
s32 fn_80262364(void);
s32 fn_802623E8(void);
s32 fn_8026246C(void);
s32 fn_802624F0(void);
s32 fn_80261ECC(void);
s32 fn_80262574(s32 kind);
f32 kar_math_mtx_sinf_approx(f32 x);
void kar_collision_math_apply_two_transforms(void* a, void* b, Vec* in, Vec* out);
void kar_collision_math_build_transformed_axis_pair(void* a, void* b, Vec* in0,
                                                    Vec* in1, Vec* out0,
                                                    Vec* out1);
f32 kar_grparts__near_800d9190(f32 angle);

#define GET_PTR(base, offset) (*(void**) ((u8*) (base) + (offset)))
#define GET_U32(base, offset) (*(u32*) ((u8*) (base) + (offset)))
#define GET_S32(base, offset) (*(s32*) ((u8*) (base) + (offset)))
#define GET_U8(base, offset) (*(u8*) ((u8*) (base) + (offset)))
#define GET_F32(base, offset) (*(f32*) ((u8*) (base) + (offset)))

static void grparts_copy_vec(Vec* dst, Vec* src)
{
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
}

static void grparts_zero_vec(Vec* v)
{
    v->x = GRPARTS_ZERO;
    v->y = GRPARTS_ZERO;
    v->z = GRPARTS_ZERO;
}

static f32 grparts_absf(f32 value)
{
    if (value < GRPARTS_ZERO) {
        return -value;
    }
    return value;
}

static BOOL grparts_is_near_zero_vec(Vec* v)
{
    return v->x < GRPARTS_EPSILON && v->x > GRPARTS_NEG_EPSILON &&
           v->y < GRPARTS_EPSILON && v->y > GRPARTS_NEG_EPSILON &&
           v->z < GRPARTS_EPSILON && v->z > GRPARTS_NEG_EPSILON;
}

static void* grparts_get_stage_pos_table(Ground* ground, s32 table_offset,
                                         s32 (*get_id)(void))
{
    GroundPosData* pos = ground->data->pos;
    void* table = GET_PTR(pos, table_offset);

    if (table == NULL) {
        return NULL;
    }

    return (u8*) table + get_id() * 0xC;
}

void kar_grparts__800d8a60(GrPartsAlloc* parts, HSD_JObj* root, void* arg,
                           s32 part_count, s32 link_count, s32 extra_count)
{
    s32 part_index = 0;
    s32 link_index = 0;
    s32 extra_index = 0;
    s32 coll_index = 0;
    void* walk_args[4];

    parts->parts = HSD_Alloc(part_count * 8);
    parts->links = HSD_Alloc(link_count * 4);
    parts->extra = HSD_Alloc(extra_count * 4);

    if (parts->parts == NULL) {
        __assert(kar_src_grparts_804a3e10, 0x82, lbl_804A3E1C);
    }

    walk_args[0] = parts;
    walk_args[1] = &part_index;
    walk_args[2] = &link_index;
    walk_args[3] = &extra_index;
    HSD_JObjWalkTree(root, (HSD_JObjWalkTreeCallback) kar_grcoll__near_800d86fc,
                     (f32**) walk_args);

    kar_grcoll__near_800d87ec(parts, arg, &coll_index);
}

void kar_grparts__near_800d8b40(GrPartsAlloc* parts)
{
    if (parts->parts != NULL) {
        HSD_Free(parts->parts);
    }
    if (parts->links != NULL) {
        HSD_Free(parts->links);
    }
    if (parts->extra != NULL) {
        HSD_Free(parts->extra);
    }
}

void kar_grparts__near_800d8b98(void* ground)
{
    void* desc_holder = GET_PTR(GET_PTR(ground, 0x8), 0xC);

    if (desc_holder != NULL) {
        PartConfig* config = *(PartConfig**) desc_holder;

        kar_grparts__800d8a60((GrPartsAlloc*) ((u8*) ground + 0x104),
                              GET_PTR(GET_PTR(ground, 0), 0x28),
                              config->joint, config->part_count,
                              config->link_count, config->extra_count);
    } else {
        kar_grparts__800d8a60((GrPartsAlloc*) ((u8*) ground + 0x104),
                              GET_PTR(GET_PTR(ground, 0), 0x28),
                              kar_lbairride__near_80055da0(), 1, 0, 0);
    }
}

void kar_grparts__near_800d8c28(void* ground)
{
    void* ptr = GET_PTR(ground, 0x104);

    if (ptr != NULL) {
        HSD_Free(ptr);
    }
    ptr = GET_PTR(ground, 0x108);
    if (ptr != NULL) {
        HSD_Free(ptr);
    }
    ptr = GET_PTR(ground, 0x10C);
    if (ptr != NULL) {
        HSD_Free(ptr);
    }
}

void kar_grparts__near_800d8c80(Vec* rot, Vec* out_z, Vec* out_y)
{
    Mtx m;

    HSD_MkRotationMtx(m, rot);
    out_y->x = m[0][1];
    out_y->y = m[1][1];
    out_y->z = m[2][1];
    out_z->x = m[0][2];
    out_z->y = m[1][2];
    out_z->z = m[2][2];
    kar_lbvector_normalize_with_axis_fallback(out_y, out_y);
    kar_lbvector_normalize_with_axis_fallback(out_z, out_z);
}

s32 kar_grparts__near_800d8d0c(void)
{
    return (s8) fn_800092B4() > 1;
}

void kar_grparts__near_800d8d44(void* gcp, Vec* pos, s32 id, Vec* out_delta,
                                Vec* in_axis0, Vec* in_axis1, Vec* out_axis0,
                                Vec* out_axis1)
{
    u8* face = (u8*) GET_PTR(gcp, 8) + id * GRPARTS_FACE_STRIDE;

    if ((GET_U32(face, 0x34) & 0x20) != 0) {
        Vec transformed;
        void* transform = GET_PTR(face, 0x38);

        kar_collision_math_apply_two_transforms((u8*) transform + 0x5C,
                                                (u8*) transform + 0x2C, pos,
                                                &transformed);
        kar_collision_math_build_transformed_axis_pair(
            (u8*) transform + 0x5C, (u8*) transform + 0x2C, in_axis0, in_axis1,
            out_axis0, out_axis1);

        out_delta->x = transformed.x - pos->x;
        out_delta->y = transformed.y - pos->y;
        out_delta->z = transformed.z - pos->z;
        if (grparts_is_near_zero_vec(out_delta)) {
            grparts_zero_vec(out_delta);
        } else {
            kar_lbvector_normalize_with_axis_fallback(out_delta, out_delta);
        }
    } else {
        grparts_zero_vec(out_delta);
        grparts_copy_vec(out_axis0, in_axis0);
        grparts_copy_vec(out_axis1, in_axis1);
    }
}

// NONMATCHING: real flow recovered, but the transformed-face path still needs
// stronger local types before matching work is useful.
f32 kar_grparts__near_800d8edc(f32 angle, Vec* dir, void* gcp, s32 id,
                               Vec* pos)
{
    u8* face = (u8*) GET_PTR(gcp, 8) + id * GRPARTS_FACE_STRIDE;
    Vec normal;
    f32 len;

    if ((GET_U8(face, 0x3C) & 0x80) != 0) {
        __assert(kar_src_grcoll_804a3e30, 0xDD, lbl_804A3E3C);
    }

    len = PSVECMag(dir);
    if (len > GRPARTS_EPSILON) {
        f32 sin_angle = kar_grparts__near_800d9190(angle);
        f32 dot;

        kar_lbvector_normalize_with_axis_fallback(dir, &normal);
        normal.x *= GRPARTS_NEG_ONE;
        normal.y *= GRPARTS_NEG_ONE;
        normal.z *= GRPARTS_NEG_ONE;
        dot = normal.x * GET_F32(face, 0xC) + normal.y * GET_F32(face, 0x10) +
              normal.z * GET_F32(face, 0x14);

        if (dot < sin_angle) {
            if (dot > GRPARTS_ZERO) {
                len *= dot / sin_angle;
            } else {
                len *= dot;
            }
        }
    } else {
        len = GRPARTS_ZERO;
    }

    if ((GET_U32(face, 0x34) & 0x20) != 0) {
        Vec transformed;
        Vec delta;
        Vec axis0 = { GRPARTS_ZERO, GRPARTS_ZERO, GRPARTS_ONE };
        Vec axis1 = { GRPARTS_ZERO, GRPARTS_ONE, GRPARTS_ZERO };
        void* transform = GET_PTR(face, 0x38);

        kar_collision_math_apply_two_transforms((u8*) transform + 0x5C,
                                                (u8*) transform + 0x2C, pos,
                                                &transformed);
        kar_collision_math_build_transformed_axis_pair(
            (u8*) transform + 0x5C, (u8*) transform + 0x2C, &axis0, &axis1,
            &axis0, &axis1);

        delta.x = transformed.x - pos->x;
        delta.y = transformed.y - pos->y;
        delta.z = transformed.z - pos->z;
        if (grparts_is_near_zero_vec(&delta)) {
            grparts_zero_vec(&delta);
        } else {
            kar_lbvector_normalize_with_axis_fallback(&delta, &delta);
        }

        len += delta.x * GET_F32(face, 0xC) + delta.y * GET_F32(face, 0x10) +
               delta.z * GET_F32(face, 0x14);
    }

    if (len < GRPARTS_ZERO) {
        len = GRPARTS_ZERO;
    }
    return len;
}

f32 kar_grparts__near_800d9190(f32 angle)
{
    return kar_math_mtx_sinf_approx(angle);
}

// NONMATCHING: broadphase collision face test. The exact candidate iteration is
// still in generated asm and needs typed KD-tree structures.
s32 kar_grparts__near_800d95dc(f32 max_t, Vec* start, Vec* dir, Vec* aabb,
                               void* gcp, s32 id, u32 flags, u32 allow_backface,
                               f32* out_t, Vec* out_pos)
{
    u8* face = (u8*) GET_PTR(gcp, 8) + id * GRPARTS_FACE_STRIDE;
    f32 dist;

    if (grparts_absf(GET_F32(face, 0x18) - aabb->x) >
        GRPARTS_AABB_EPSILON + GET_F32(face, 0x24) + GET_F32(aabb, 0xC)) {
        return FALSE;
    }
    if (grparts_absf(GET_F32(face, 0x1C) - aabb->y) >
        GRPARTS_AABB_EPSILON + GET_F32(face, 0x28) + GET_F32(aabb, 0x10)) {
        return FALSE;
    }
    if (grparts_absf(GET_F32(face, 0x20) - aabb->z) >
        GRPARTS_AABB_EPSILON + GET_F32(face, 0x2C) + GET_F32(aabb, 0x14)) {
        return FALSE;
    }

    if ((flags & GET_U32(face, 0x30)) == 0 || (GET_U8(face, 0x3C) & 0x40) == 0 ||
        (GET_U8(face, 0x3C) & 0x80) != 0) {
        return FALSE;
    }

    dist = dir->x * GET_F32(face, 0xC) + dir->y * GET_F32(face, 0x10) +
           dir->z * GET_F32(face, 0x14);
    if (dist > GRPARTS_EPSILON || dist > GRPARTS_NEG_EPSILON) {
        return FALSE;
    }

    if (allow_backface != 0 && (GET_U32(face, 0x30) & 1) == 0 &&
        (GET_U32(face, 0x34) & 0x8000) == 0) {
        return FALSE;
    }

    out_t[0] = GRPARTS_ZERO;
    grparts_copy_vec(out_pos, start);
    return max_t >= GRPARTS_ZERO;
}

// NONMATCHING: segment-vs-ground broadphase scan not yet typed.
s32 kar_grparts__near_800d9958(void* gcp, Vec* start, Vec* end, u32 flags,
                               u32 allow_backface, Vec* out_pos)
{
    out_pos->x = end->x;
    out_pos->y = end->y;
    out_pos->z = end->z;
    (void) gcp;
    (void) start;
    (void) flags;
    (void) allow_backface;
    return -1;
}

// NONMATCHING: swept-sphere broadphase scan not yet typed.
s32 kar_grparts__near_800d9e34(f32 radius, f32 arg1, void* gcp, Vec* start,
                               Vec* end, u32 flags, s32 use_grid, Vec* out_pos,
                               Vec* out_hit)
{
    (void) radius;
    (void) arg1;
    (void) gcp;
    (void) start;
    (void) end;
    (void) flags;
    (void) use_grid;
    grparts_zero_vec(out_pos);
    grparts_zero_vec(out_hit);
    return -1;
}

void* kar_grparts__near_800da3d4(Ground* ground)
{
    return grparts_get_stage_pos_table(ground, 0x4, kar_grcoursespline__802622e0);
}

void* kar_grparts__near_800da424(Ground* ground)
{
    return grparts_get_stage_pos_table(ground, 0x8, fn_80262364);
}

void* kar_grparts__near_800da474(Ground* ground)
{
    return grparts_get_stage_pos_table(ground, 0x18, fn_802623E8);
}

void* kar_grparts__near_800da4c4(Ground* ground)
{
    if (ground->data->enemy == NULL) {
        return NULL;
    }
    return (u8*) ground->data->enemy + fn_80262364() * 0x18;
}

void* kar_grparts__near_800da518(Ground* ground)
{
    if (ground->data->item == NULL || kar_diag__8000a2a0() != 0) {
        return NULL;
    }
    return (u8*) ground->data->item + fn_802623E8() * 0x14;
}

void* kar_grparts__near_800da578(Ground* ground)
{
    return grparts_get_stage_pos_table(ground, 0x30, fn_8026246C);
}

void* kar_grparts__near_800da5c8(Ground* ground)
{
    return grparts_get_stage_pos_table(ground, 0x20, fn_802624F0);
}

void* kar_grparts__near_800da618(Ground* ground)
{
    return grparts_get_stage_pos_table(ground, 0x34, fn_802624F0);
}

void* kar_grparts__near_800da668(Ground* ground)
{
    if (fn_80262574(fn_80261ECC()) == 0 || fn_8000A348() == 0) {
        return NULL;
    }
    return ground->data->event_;
}

// NONMATCHING: point-vs-special-face broadphase scan not yet typed.
s32 kar_grparts__near_800da6bc(Vec* pos, void* data, u32 kind)
{
    (void) pos;
    (void) data;
    (void) kind;
    return -1;
}

// NONMATCHING: point query for kind 0x1e faces not yet typed.
s32 kar_grparts__near_800daa54(void* data, Vec* pos)
{
    (void) data;
    (void) pos;
    return -1;
}

// NONMATCHING: point query for kind 0x22/special flagged faces not yet typed.
s32 kar_grparts__near_800dae00(Vec* pos, void* data)
{
    (void) pos;
    (void) data;
    return -1;
}

void kar_grparts__near_800db1a8(s32* list, s32 count)
{
    s32 i;

    for (i = 0; i < count; i++) {
        list[i] = 0;
    }
}
