#include "functions.h"
#include <dolphin/mtx/mtx.h>
#include <dolphin/mtx/vec.h>
#include <dolphin/types.h>
#include <kar/gr/grcoll.h>
#include <sysdolphin/jobj.h>
#include <sysdolphin/memory.h>
#include <sysdolphin/mtx.h>

#define GRCOLL_FACE_STRIDE 0x40
#define GRCOLL_JOINT_STRIDE 0x98
#define GRCOLL_ZONE_STRIDE 0x140
#define GRCOLL_ROUGH_STRIDE 0x1C
#define GRCOLL_SRC_FACE_STRIDE 0x14
#define GRCOLL_SRC_ZONE_FACE_STRIDE 0x18
#define GRCOLL_SRC_JOINT_STRIDE 0x1C
#define GRCOLL_SRC_ZONE_STRIDE 0x4C

#define GET_PTR(base, offset) (*(void**) ((u8*) (base) + (offset)))
#define GET_U32(base, offset) (*(u32*) ((u8*) (base) + (offset)))
#define GET_S32(base, offset) (*(s32*) ((u8*) (base) + (offset)))
#define GET_U8(base, offset) (*(u8*) ((u8*) (base) + (offset)))
#define SET_PTR(base, offset, value) (*(void**) ((u8*) (base) + (offset)) = (value))
#define SET_S32(base, offset, value) (*(s32*) ((u8*) (base) + (offset)) = (value))

typedef struct GrCollFace GrCollFace;
typedef struct GrCollFaceFlagBits GrCollFaceFlagBits;
typedef struct GrCollJoint GrCollJoint;
typedef struct GrCollRoot GrCollRoot;
typedef struct GrCollWalkParts GrCollWalkParts;

struct GrCollFaceFlagBits {
    u8 bit7 : 1;
    u8 bit6 : 1;
    u8 bit5 : 1;
    u8 bit4 : 1;
    u8 bit3 : 1;
    u8 bit2 : 1;
    u8 bit1 : 1;
    u8 bit0 : 1;
};

struct GrCollFace {
    Vec* pos[3];
    Vec normal;
    Vec center;
    Vec extent;
    u32 info0;
    u32 info1;
    GrCollJoint* joint;
    u8 flags;
    u8 pad_3D[3];
};

struct GrCollJoint {
    HSD_JObj* jobj;
    Vec* verts;
    s32 vert_count;
    GrCollFace* faces;
    s32 face_count;
    Vec center;
    Vec extent;
    Mtx mtx;
    Mtx inv_mtx;
    u32 unk_8C;
    u32 unk_90;
    u8 flags;
    u8 pad_95[3];
};

struct GrCollRoot {
    Vec* verts;
    s32 vert_count;
    GrCollFace* faces;
    s32 face_count;
    GrCollJoint* joints;
    s32 joint_count;
    void* zvtx;
    s32 zvtx_count;
    void* zones;
    s32 zone_count;
    void* rough;
    s32 rough_count;
    GrCollJoint** move_joints;
    s32 move_joint_count;
    void** move_zones;
    s32 move_zone_count;
    void** move_rough;
    s32 move_rough_count;
};

struct GrCollWalkParts {
    void* parts;
    void* links;
    void* extra;
};

char lbl_804A3B98[] = "seg move flag!! joint %d face %d\n";
char kar_src_grcoll_804a3bbc[] =
    "grcoll.c\0\0\0"
    "error!! zone %d face %d\n\0\0"
    "gcp %d: total %d\n\0\0"
    "gcp->move_joint_num <= total->move_joint_num\0"
    "gcp->vtx_num <= total->vtx_num\0\0"
    "gcp->face_num <= total->face_num\0"
    "gcp->joint_num <= total->joint_num\0\0"
    "gcp->zvtx_num <= total->zvtx_num\0"
    "gcp->zone_num <= total->zone_num\0"
    "ground.h\0\0\0"
    "0 <= data_kind && data_kind < grGetYakuStaticDataNum(gp)\0"
    "0 <= num && num < grGetYakuCommonDataNum(gp)\0\0"
    "total->zone_num = %d\n\0\0"
    "total->zone_num < Gr_CollZone_NumMax";
char lbl_804A3D90[] =
    "0 <= edgeId && edgeId <= 2\0\0"
    "cgf_all->coll_info & GrCFK_Under\0"
    "cgf_all->coll_info & GrCFK_Wall\0\0"
    "cgf_all->coll_info & GrCFK_Top";

char lbl_805D60B0[] = "0";
char kar_srcfile_jobj_h_805d60b4[] = "jobj.h";
char lbl_805D60BC[] = "jobj";
char kar_src_mplib_805d60c4[] = "mplib.h";

extern void kar_grzone_build_zone_from_zjoint(GrCollRoot* alloc,
                                              GrCollRoot* total,
                                              GrCollRoot* root,
                                              void* coll_desc,
                                              void* joint_table, s32 index);
extern void kar_grzone_update_zone_world_transform(GrCollRoot* root,
                                                   void* coll_desc,
                                                   s32 index);
extern void kar_grrough__800dc7e4(GrCollRoot* alloc, GrCollRoot* total,
                                  GrCollRoot* root, void* coll_desc,
                                  s32 index);
extern void kar_grrough__near_800dc8e0(GrCollRoot* root, void* coll_desc,
                                       s32 index);
extern s32 kar_grcoll__near_800d1d48(void);
extern void kar_grcoll__near_800d1d98(void);
extern void kar_grcoll__near_800d1dcc(void);
extern s32 kar_collision_math_compare_contact_basis_exact(Mtx lhs, Mtx rhs);
extern s32 kar_collision_math_triangle_normal(Vec* a, Vec* b, Vec* c,
                                              Vec* normal);
extern void kar_mpresponse_expand_aabb_with_point(Vec* min, Vec* max,
                                                  Vec* point);
extern void kar_mpresponse_build_aabb_center_extents(Vec* out, Vec* min,
                                                     Vec* max);
extern void kar_mpresponse_vec3_min_inplace(Vec* lhs, Vec* rhs);
extern void kar_mpresponse_vec3_max_inplace(Vec* lhs, Vec* rhs);
extern void kar_gryaku_get_common_kind_data(void* kind);
extern void kar_grdispbbox_update_jobj_bounds_records(void* data);
extern void kar_grdispbbox_update_visible_parts_for_camera(void* data,
                                                           void* arg1,
                                                           void* arg2,
                                                           void* arg3);
extern u32 GObj_GetFlagFromArray(u32 pass);
extern void kar_granim__near_800dc7a4(void* data, void* out);
extern void* HSD_CObjGetCurrent(void);

static void grcoll_assert_jobj(HSD_JObj* jobj)
{
    if (jobj == NULL) {
        __assert(kar_srcfile_jobj_h_805d60b4, 0x47C, lbl_805D60BC);
    }
    if (((jobj->flags & USER_DEF_MTX) == 0) && ((jobj->flags & MTX_DIRTY) != 0)) {
        HSD_JObjSetupMatrixSub(jobj);
    }
}

void kar_grcoll__800d6290(void* total, void* coll_desc)
{
    s32 i;
    s32 j;
    s32 offset;
    u32 move_flag;
    void* joint;
    void* face;
    void* zone;

    GET_S32(total, 0x04) += GET_S32(coll_desc, 0x04);
    GET_S32(total, 0x0C) += GET_S32(coll_desc, 0x0C);
    GET_S32(total, 0x14) += GET_S32(coll_desc, 0x14);
    GET_S32(total, 0x1C) += GET_S32(coll_desc, 0x1C);
    GET_S32(total, 0x24) += GET_S32(coll_desc, 0x2C);

    offset = 0;
    for (i = 0; i < GET_S32(coll_desc, 0x14); i++) {
        joint = (u8*) GET_PTR(coll_desc, 0x10) + offset;
        face = (u8*) GET_PTR(coll_desc, 0x08) +
               GET_S32(joint, 0x0C) * GRCOLL_SRC_FACE_STRIDE;
        move_flag = (GET_U32(face, 0x10) >> 5) & 1;
        for (j = 0; j < GET_S32(joint, 0x10); j++) {
            if (move_flag != ((GET_U32(face, 0x10) >> 5) & 1)) {
                OSReport(lbl_804A3B98, i, j);
                __assert(kar_src_grcoll_804a3bbc, 0x50, lbl_805D60B0);
            }
            face = (u8*) face + GRCOLL_SRC_FACE_STRIDE;
        }
        if (move_flag != 0) {
            GET_S32(total, 0x34)++;
        }
        offset += GRCOLL_SRC_JOINT_STRIDE;
    }

    offset = 0;
    for (i = 0; i < GET_S32(coll_desc, 0x2C); i++) {
        zone = (u8*) GET_PTR(coll_desc, 0x20) +
               GET_S32((u8*) GET_PTR(coll_desc, 0x28) + offset, 0x0C) *
                   GRCOLL_SRC_ZONE_FACE_STRIDE;
        move_flag = (GET_U32(zone, 0x14) >> 5) & 1;
        for (j = 0; j < 12; j++) {
            if (move_flag != ((GET_U32(zone, 0x14) >> 5) & 1)) {
                OSReport(kar_src_grcoll_804a3bbc + 0x0C, i, j);
                __assert(kar_src_grcoll_804a3bbc, 0x68, lbl_805D60B0);
            }
            zone = (u8*) zone + GRCOLL_SRC_ZONE_FACE_STRIDE;
        }
        if (move_flag != 0) {
            GET_S32(total, 0x3C)++;
        }
        offset += GRCOLL_SRC_ZONE_STRIDE;
    }

    face = GET_PTR(coll_desc, 0x08);
    for (i = 0; i < GET_S32(coll_desc, 0x0C); i++) {
        if ((GET_U32(face, 0x10) & 3) != 0) {
            GET_S32(total, 0x2C)++;
            if ((GET_U32(face, 0x10) & 0x20) == 0x20) {
                GET_S32(total, 0x44)++;
            }
        }
        face = (u8*) face + GRCOLL_SRC_FACE_STRIDE;
    }
}

void kar_grcoll__800d64b8(GrCollRoot* alloc, GrCollRoot* total,
                          GrCollRoot* root, void* coll_desc,
                          void* joint_table, s32 index)
{
    s32 i;
    s32 src_vertex;
    s32 src_face;
    void* src_joint;
    void* src_vtx;
    void* src_tri;
    GrCollJoint* joint;
    GrCollFace* face;

    src_joint = (u8*) GET_PTR(coll_desc, 0x10) + index * GRCOLL_SRC_JOINT_STRIDE;
    src_vertex = GET_S32(src_joint, 0x04);
    src_face = GET_S32(src_joint, 0x0C);
    joint = (GrCollJoint*) ((u8*) root->joints + index * GRCOLL_JOINT_STRIDE);

    joint->jobj = *(HSD_JObj**) ((u8*) GET_PTR(joint_table, 0x00) +
                                 GET_S32(src_joint, 0x00) * 8);
    joint->verts = root->verts + src_vertex;
    joint->vert_count = GET_S32(src_joint, 0x08);
    joint->faces = root->faces + src_face;
    joint->face_count = GET_S32(src_joint, 0x10);
    SET_S32(joint, 0x8C, GET_S32(src_joint, 0x14));
    SET_S32(joint, 0x90, GET_S32(src_joint, 0x18));

    src_vtx = (u8*) GET_PTR(coll_desc, 0x00) + src_vertex * sizeof(Vec);
    for (i = 0; i < joint->vert_count; i++) {
        joint->verts[i * 2].x = ((Vec*) src_vtx)[i].x;
        joint->verts[i * 2].y = ((Vec*) src_vtx)[i].y;
        joint->verts[i * 2].z = ((Vec*) src_vtx)[i].z;
    }

    src_tri = (u8*) GET_PTR(coll_desc, 0x08) + src_face * GRCOLL_SRC_FACE_STRIDE;
    for (i = 0; i < joint->face_count; i++) {
        face = &joint->faces[i];
        face->pos[0] = root->verts + GET_S32(src_tri, 0x00) * 2;
        face->pos[1] = root->verts + GET_S32(src_tri, 0x04) * 2;
        face->pos[2] = root->verts + GET_S32(src_tri, 0x08) * 2;
        face->info0 = GET_U32(src_tri, 0x0C);
        face->info1 = GET_U32(src_tri, 0x10);
        face->flags |= 0x60;
        face->joint = joint;
        src_tri = (u8*) src_tri + GRCOLL_SRC_FACE_STRIDE;
    }

    if ((joint->faces[0].info1 & 0x20) == 0x20) {
        if (total->move_joint_count < alloc->move_joint_count) {
            OSReport(kar_src_grcoll_804a3bbc + 0x28, alloc->move_joint_count);
            __assert(kar_src_grcoll_804a3bbc, 0xC9,
                     kar_src_grcoll_804a3bbc + 0x3C);
        }
        root->move_joints[root->move_joint_count] = joint;
        root->move_joint_count++;
        alloc->move_joint_count++;
    }
}

void kar_grcoll__near_800d6724(void* root)
{
    SET_S32(root, 0x00, 0);
    SET_S32(root, 0x08, 0);
    SET_S32(root, 0x10, 0);
    SET_S32(root, 0x18, 0);
    SET_S32(root, 0x20, 0);
    SET_S32(root, 0x28, 0);
    SET_S32(root, 0x30, 0);
    SET_S32(root, 0x38, 0);
    SET_S32(root, 0x40, 0);
    SET_S32(root, 0x04, 0);
    SET_S32(root, 0x0C, 0);
    SET_S32(root, 0x14, 0);
    SET_S32(root, 0x1C, 0);
    SET_S32(root, 0x24, 0);
    SET_S32(root, 0x2C, 0);
    SET_S32(root, 0x34, 0);
    SET_S32(root, 0x3C, 0);
    SET_S32(root, 0x44, 0);
}

void kar_grcoll__800d6774(GrCollRoot* alloc, GrCollRoot* total,
                          GrCollRoot* root, void* coll_desc,
                          void* joint_table)
{
    s32 i;

    root->verts = alloc->verts + alloc->vert_count * 2;
    root->vert_count = GET_S32(coll_desc, 0x04);
    alloc->vert_count += GET_S32(coll_desc, 0x04);
    if (total->vert_count < alloc->vert_count) {
        OSReport(kar_src_grcoll_804a3bbc + 0x28, alloc->vert_count);
        __assert(kar_src_grcoll_804a3bbc, 0x181,
                 kar_src_grcoll_804a3bbc + 0x6C);
    }

    root->faces = alloc->faces + alloc->face_count;
    root->face_count = GET_S32(coll_desc, 0x0C);
    alloc->face_count += GET_S32(coll_desc, 0x0C);
    if (total->face_count < alloc->face_count) {
        OSReport(kar_src_grcoll_804a3bbc + 0x28, alloc->face_count);
        __assert(kar_src_grcoll_804a3bbc, 0x186,
                 kar_src_grcoll_804a3bbc + 0x8C);
    }

    root->joints = alloc->joints + alloc->joint_count;
    root->joint_count = GET_S32(coll_desc, 0x14);
    alloc->joint_count += GET_S32(coll_desc, 0x14);
    if (total->joint_count < alloc->joint_count) {
        OSReport(kar_src_grcoll_804a3bbc + 0x28, alloc->joint_count);
        __assert(kar_src_grcoll_804a3bbc, 0x18B,
                 kar_src_grcoll_804a3bbc + 0xB0);
    }

    root->zvtx = (u8*) alloc->zvtx + alloc->zvtx_count * sizeof(Vec);
    root->zvtx_count = GET_S32(coll_desc, 0x1C);
    alloc->zvtx_count += GET_S32(coll_desc, 0x1C);
    if (total->zvtx_count < alloc->zvtx_count) {
        OSReport(kar_src_grcoll_804a3bbc + 0x28, alloc->zvtx_count);
        __assert(kar_src_grcoll_804a3bbc, 0x190,
                 kar_src_grcoll_804a3bbc + 0xD4);
    }

    root->zones = (u8*) alloc->zones + alloc->zone_count * GRCOLL_ZONE_STRIDE;
    root->zone_count = GET_S32(coll_desc, 0x2C);
    alloc->zone_count += GET_S32(coll_desc, 0x2C);
    if (total->zone_count < alloc->zone_count) {
        OSReport(kar_src_grcoll_804a3bbc + 0x28, alloc->zone_count);
        __assert(kar_src_grcoll_804a3bbc, 0x195,
                 kar_src_grcoll_804a3bbc + 0xF8);
    }

    root->rough = (u8*) alloc->rough + alloc->rough_count * GRCOLL_ROUGH_STRIDE;
    root->rough_count = 0;
    root->move_joints = alloc->move_joints + alloc->move_joint_count;
    root->move_joint_count = 0;
    root->move_zones = alloc->move_zones + alloc->move_zone_count;
    root->move_zone_count = 0;
    root->move_rough = alloc->move_rough + alloc->move_rough_count;
    root->move_rough_count = 0;

    for (i = 0; i < GET_S32(coll_desc, 0x14); i++) {
        kar_grcoll__800d64b8(alloc, total, root, coll_desc, joint_table, i);
    }
    for (i = 0; i < GET_S32(coll_desc, 0x2C); i++) {
        kar_grzone_build_zone_from_zjoint(alloc, total, root, coll_desc,
                                          joint_table, i);
    }
    for (i = 0; i < root->face_count; i++) {
        kar_grrough__800dc7e4(alloc, total, root, coll_desc, i);
    }
}

// NONMATCHING: transform update flow is recovered, but the exact register and
// AABB scheduling still needs a focused pass against the asm.
void kar_grcoll__near_800d6a70(GrCollRoot* root, void* coll_desc)
{
    s32 i;
    s32 j;
    s32 offset;
    HSD_JObj* jobj;
    GrCollJoint* joint;
    GrCollFace* face;
    Vec min;
    Vec max;
    Vec root_min;
    Vec root_max;
    s32 normal_ok;
    Vec* src;

    offset = 0;
    for (i = 0; i < root->joint_count; i++) {
        joint = &root->joints[i];
        jobj = joint->jobj;
        grcoll_assert_jobj(jobj);
        PSMTXCopy(jobj->mtx, joint->mtx);
        src = (Vec*) ((u8*) GET_PTR(coll_desc, 0x00) +
                      GET_S32((u8*) GET_PTR(coll_desc, 0x10) + offset, 0x04) *
                          sizeof(Vec));
        for (j = 0; j < joint->vert_count; j++) {
            PSMTXMultVec(jobj->mtx, &src[j], &joint->verts[j * 2]);
        }
        for (j = 0; j < joint->face_count; j++) {
            face = &joint->faces[j];
            normal_ok = kar_collision_math_triangle_normal(
                face->pos[0], face->pos[1], face->pos[2], &face->normal);
            face->flags = (face->flags & 0x7F) | ((normal_ok == 0) << 7);
        }
        for (j = 0; j < joint->vert_count; j++) {
            joint->verts[j * 2 + 1] = joint->verts[j * 2];
        }
        PSMTXCopy(joint->mtx, joint->inv_mtx);
        HSD_MtxInverse(joint->inv_mtx, joint->inv_mtx);
        joint->flags &= 0x7F;

        for (j = 0; j < joint->face_count; j++) {
            face = &joint->faces[j];
            min = *face->pos[0];
            max = min;
            kar_mpresponse_expand_aabb_with_point(&min, &max, face->pos[1]);
            kar_mpresponse_expand_aabb_with_point(&min, &max, face->pos[2]);
            kar_mpresponse_build_aabb_center_extents(&face->center, &min, &max);
            if (j == 0) {
                root_min = min;
                root_max = max;
            } else {
                kar_mpresponse_vec3_min_inplace(&root_min, &min);
                kar_mpresponse_vec3_max_inplace(&root_max, &max);
            }
        }
        kar_mpresponse_build_aabb_center_extents(&joint->center, &root_min,
                                                 &root_max);
        offset += GRCOLL_SRC_JOINT_STRIDE;
    }

    for (i = 0; i < root->zone_count; i++) {
        kar_grzone_update_zone_world_transform(root, coll_desc, i);
    }
    for (i = 0; i < root->rough_count; i++) {
        kar_grrough__near_800dc8e0(root, coll_desc, i);
    }
}

void kar_grcoll__near_800d6d88(GrCollRoot* alloc, GrCollRoot* total,
                               GrCollRoot* root, void* coll_desc,
                               void* joint_table)
{
    kar_grcoll__800d6774(alloc, total, root, coll_desc, joint_table);
    kar_grcoll__near_800d6a70(root, coll_desc);
}

// NONMATCHING: this is the allocator/setup skeleton. The yaku-data loops are
// still raw-offset based until the surrounding ground data structs are named.
void kar_grcoll__800d6dcc(void* ground)
{
    void* total;
    GrCollRoot* alloc;
    GrCollRoot* root;
    void* coll_desc;
    void* joint_table;

    total = (u8*) ground + 0x0C;
    alloc = (GrCollRoot*) ((u8*) ground + 0x54);
    root = (GrCollRoot*) ((u8*) ground + 0x9C);
    kar_grcoll__near_800d6724(total);
    coll_desc = GET_PTR(GET_PTR(ground, 0x08), 0x18);
    kar_grcoll__800d6290(total, coll_desc);

    alloc->verts = HSD_Alloc(GET_S32(total, 0x04) * 0x18);
    alloc->faces = HSD_Alloc(GET_S32(total, 0x0C) * GRCOLL_FACE_STRIDE);
    alloc->joints = HSD_Alloc(GET_S32(total, 0x14) * GRCOLL_JOINT_STRIDE);
    alloc->zvtx = HSD_Alloc(GET_S32(total, 0x1C) * sizeof(Vec));
    alloc->zones = HSD_Alloc(GET_S32(total, 0x24) * GRCOLL_ZONE_STRIDE);
    alloc->rough = HSD_Alloc(GET_S32(total, 0x2C) * GRCOLL_ROUGH_STRIDE);
    alloc->move_joints = HSD_Alloc(GET_S32(total, 0x34) * sizeof(void*));
    alloc->move_zones = HSD_Alloc(GET_S32(total, 0x3C) * sizeof(void*));
    alloc->move_rough = HSD_Alloc(GET_S32(total, 0x44) * sizeof(void*));
    alloc->vert_count = 0;
    alloc->face_count = 0;
    alloc->joint_count = 0;
    alloc->zvtx_count = 0;
    alloc->zone_count = 0;
    alloc->rough_count = 0;
    alloc->move_joint_count = 0;
    alloc->move_zone_count = 0;
    alloc->move_rough_count = 0;

    joint_table = (u8*) ground + 0x104;
    kar_grcoll__near_800d6d88(alloc, (GrCollRoot*) total, root, coll_desc,
                              joint_table);
}

void kar_grcoll__near_800d7060(void* ground)
{
    void* ptr;

    ptr = GET_PTR(ground, 0x54);
    if (ptr != NULL) {
        HSD_Free(ptr);
    }
    ptr = GET_PTR(ground, 0x5C);
    if (ptr != NULL) {
        HSD_Free(ptr);
    }
    ptr = GET_PTR(ground, 0x64);
    if (ptr != NULL) {
        HSD_Free(ptr);
    }
    ptr = GET_PTR(ground, 0x74);
    if (ptr != NULL) {
        HSD_Free(ptr);
    }
    ptr = GET_PTR(ground, 0x74);
    if (ptr != NULL) {
        HSD_Free(ptr);
    }
    ptr = GET_PTR(ground, 0x7C);
    if (ptr != NULL) {
        HSD_Free(ptr);
    }
    ptr = GET_PTR(ground, 0x84);
    if (ptr != NULL) {
        HSD_Free(ptr);
    }
    ptr = GET_PTR(ground, 0x94);
    if (ptr != NULL) {
        HSD_Free(ptr);
    }
    ptr = GET_PTR(ground, 0x94);
    if (ptr != NULL) {
        HSD_Free(ptr);
    }
}

void kar_grcoll__800d7118(void* collision_root, s32 face_id, Vec* pos0,
                          Vec* pos1, Vec* pos2)
{
    GrCollFace* face;

    face = &((GrCollRoot*) collision_root)->faces[face_id];
    *pos0 = *face->pos[0];
    *pos1 = *face->pos[1];
    *pos2 = *face->pos[2];
}

void kar_grcoll__800d717c(void* collision_root, s32 face_id, s32 edge_id,
                          Vec* pos0, Vec* pos1)
{
    GrCollFace* face;
    Vec* a;
    Vec* b;

    if ((edge_id < 0) || (edge_id >= 3)) {
        __assert(kar_src_grcoll_804a3bbc, 0x26E, lbl_804A3D90);
    }
    face = &((GrCollRoot*) collision_root)->faces[face_id];
    a = face->pos[edge_id];
    b = face->pos[(edge_id + 1) % 3];
    if (b < a) {
        Vec* temp = a;
        a = b;
        b = temp;
    }
    *pos0 = *a;
    *pos1 = *b;
}

// NONMATCHING: display-list setup path not yet reconstructed.
void kar_grcoll__near_800d7b8c(void* root, s32 pass)
{
    (void) root;
    (void) pass;
}

// NONMATCHING: moving-joint update is structurally correct, but division and
// call scheduling do not yet match.
void kar_grcoll__near_800d7268(GrCollRoot* root, void* coll_desc, s32 index)
{
    HSD_JObj* jobj;
    GrCollJoint* joint;

    joint = &root->joints[index];
    jobj = joint->jobj;
    grcoll_assert_jobj(jobj);
    if (kar_collision_math_compare_contact_basis_exact(joint->mtx, jobj->mtx) == 0) {
        kar_grcoll__near_800d6a70(root, coll_desc);
    } else if ((joint->flags & 0x80) != 0) {
        joint->flags &= 0x7F;
    }
}

void kar_grcoll__near_800d7648(GrCollRoot* root, void* coll_desc)
{
    s32 i;
    s32 index;

    for (i = 0; i < root->move_joint_count; i++) {
        index = (s32) ((u8*) root->move_joints[i] - (u8*) root->joints);
        index = index / GRCOLL_JOINT_STRIDE;
        kar_grcoll__near_800d7268(root, coll_desc, index);
    }
    for (i = 0; i < root->move_zone_count; i++) {
        index = (s32) ((u8*) root->move_zones[i] - (u8*) root->zones);
        index = index / GRCOLL_ZONE_STRIDE;
        kar_grzone_update_zone_world_transform(root, coll_desc, index);
    }
    for (i = 0; i < root->move_rough_count; i++) {
        index = (s32) ((u8*) root->move_rough[i] - (u8*) root->rough);
        index = index / GRCOLL_ROUGH_STRIDE;
        kar_grrough__near_800dc8e0(root, coll_desc, index);
    }
}

void kar_grcoll__near_800d777c(void* ground)
{
    kar_grcoll__near_800d7648((GrCollRoot*) ((u8*) ground + 0x9C),
                              GET_PTR(GET_PTR(ground, 0x08), 0x18));
}

void kar_grcoll__near_800d78b4(void* collision_root, s32 index, Vec* out)
{
    Mtx* mtx;

    mtx = (Mtx*) ((u8*) ((GrCollRoot*) collision_root)->zones +
                  index * GRCOLL_ZONE_STRIDE + 0xE0);
    out->x = (*mtx)[0][2];
    out->y = (*mtx)[1][2];
    out->z = (*mtx)[2][2];
}

void kar_grcoll__near_800d78e0(void* collision_root, s32 index, Vec* out)
{
    Mtx* mtx;

    mtx = (Mtx*) ((u8*) ((GrCollRoot*) collision_root)->zones +
                  index * GRCOLL_ZONE_STRIDE + 0xE0);
    out->x = (*mtx)[0][1];
    out->y = (*mtx)[1][1];
    out->z = (*mtx)[2][1];
}

void kar_grcoll__near_800d790c(void* collision_root, s32 index, Vec* out)
{
    HSD_MtxGetTranslate((MtxPtr) ((u8*) ((GrCollRoot*) collision_root)->zones +
                                  index * GRCOLL_ZONE_STRIDE + 0xE0),
                        out);
}

void* kar_grcoll__near_800d7940(void* collision_root, s32 index)
{
    return (u8*) ((GrCollRoot*) collision_root)->zones +
           index * GRCOLL_ZONE_STRIDE + 0x110;
}

void* kar_grcoll__800d7954(void* collision_root, void* jobj)
{
    s32 i;
    s32 offset;
    s32 count;
    void* joint;

    offset = 0;
    count = GET_S32(collision_root, 0x14);
    if (0 < count) {
        for (i = 0; i < count; i++) {
            joint = (u8*) GET_PTR(collision_root, 0x10) + offset;
            if (GET_PTR(joint, 0x00) == jobj) {
                return joint;
            }
            offset += GRCOLL_JOINT_STRIDE;
        }
    }
    __assert(kar_src_grcoll_804a3bbc, 0x332, lbl_805D60B0);
    return NULL;
}

void* kar_grcoll__800d79c0(void* collision_root, void* jobj, s32* index_out)
{
    s32 i;
    void* zone;
    GrCollRoot* root = collision_root;

    for (i = 0; i < root->zone_count; i++) {
        zone = (u8*) root->zones + i * GRCOLL_ZONE_STRIDE;
        if (GET_PTR(zone, 0x00) == jobj) {
            if (index_out != NULL) {
                *index_out = i;
            }
            return zone;
        }
    }
    __assert(kar_src_grcoll_804a3bbc, 0x34E, lbl_805D60B0);
    return NULL;
}

void* kar_grcoll__800d7a40(void* collision_root, void* jobj, s32 kind,
                           s32* index_out)
{
    s32 i;
    void* zone;
    GrCollRoot* root = collision_root;

    for (i = 0; i < root->zone_count; i++) {
        zone = (u8*) root->zones + i * GRCOLL_ZONE_STRIDE;
        if ((GET_PTR(zone, 0x00) == jobj) &&
            (kind == (s32) (GET_U32(zone, 0x24) & 0x1FFFFFF))) {
            if (index_out != NULL) {
                *index_out = i;
            }
            return zone;
        }
    }
    __assert(kar_src_grcoll_804a3bbc, 0x36C, lbl_805D60B0);
    return NULL;
}

void kar_grcoll__near_800d7ad0(void* collision, s32 enabled)
{
    s32 i;
    s32 offset;
    s32 flag_offset;
    u8* faces;

    offset = 0;
    for (i = 0; i < GET_S32(collision, 0x10); i++) {
        flag_offset = offset + 0x3C;
        offset += GRCOLL_FACE_STRIDE;
        faces = GET_PTR(collision, 0x0C);
        ((GrCollFaceFlagBits*) &faces[flag_offset])->bit6 = enabled;
    }
}

BOOL kar_grcoll__near_800d7b0c(void* collision, s32 enabled)
{
    s32 i;
    s32 offset;
    u8* faces;

    offset = 0;
    for (i = 0; i < GET_S32(collision, 0x10); i++) {
        faces = GET_PTR(collision, 0x0C);
        if (((faces[offset + 0x3C] >> 6) & 1) != enabled) {
            return FALSE;
        }
        offset += GRCOLL_FACE_STRIDE;
    }
    return TRUE;
}

void kar_grcoll__near_800d7b50(void* collision, s32 enabled)
{
    s32 i;
    s32 offset;
    s32 flag_offset;
    u8* faces;

    offset = 0;
    for (i = 0; i < GET_S32(collision, 0x10); i++) {
        flag_offset = offset + 0x3C;
        offset += GRCOLL_FACE_STRIDE;
        faces = GET_PTR(collision, 0x0C);
        ((GrCollFaceFlagBits*) &faces[flag_offset])->bit5 = enabled;
    }
}

void kar_grcoll__near_800d7d70(void* collision_root, s32 enabled)
{
    s32 i;
    s32 j;
    s32 joint_offset;
    s32 face_offset;
    s32 flag_offset;
    void* joint;
    u8* faces;

    joint_offset = 0;
    for (i = 0; i < GET_S32(collision_root, 0x14); i++) {
        face_offset = 0;
        joint = (u8*) GET_PTR(collision_root, 0x10) + joint_offset;
        for (j = 0; j < GET_S32(joint, 0x10); j++) {
            faces = GET_PTR(joint, 0x0C);
            flag_offset = face_offset + 0x3C;
            face_offset += GRCOLL_FACE_STRIDE;
            ((GrCollFaceFlagBits*) &faces[flag_offset])->bit6 = enabled;
        }
        joint_offset += GRCOLL_JOINT_STRIDE;
    }
}

void kar_grcoll__near_800d7dd4(void* root, void* a, void* b, void* c,
                               u32 pass)
{
    void* data;
    void* jobj;
    u32 flags;

    data = GET_PTR(root, 0x2C);
    if (GET_PTR(GET_PTR(data, 0x08), 0x0C) != NULL) {
        if (pass == 0) {
            if (((u32) GET_U8(data, 0x71C) >> 7) != 0) {
                kar_grdispbbox_update_jobj_bounds_records(data);
            }
            kar_grdispbbox_update_visible_parts_for_camera(data, a, b, c);
        }
        jobj = GET_PTR(root, 0x28);
        flags = GObj_GetFlagFromArray(pass);
        HSD_JObjDispAll(jobj, NULL, flags, 0);
    }
}

// NONMATCHING: full-screen fog/overlay draw path not yet reconstructed.
void kar_grcoll__near_800d7e78(void* cobj, void* params)
{
    (void) cobj;
    (void) params;
}

void kar_grcoll__near_800d8148(void* ground, u32 pass)
{
    void* data;
    void* cobj;
    u8 params[16];
    u32 flags;

    data = GET_PTR(ground, 0x2C);
    if (GET_PTR(data, 0xF4) != NULL) {
        if (kar_grcoll__near_800d1d48() == 0) {
            kar_grcoll__near_800d1dcc();
        }
        flags = GObj_GetFlagFromArray(pass);
        HSD_JObjDispAll(GET_PTR(data, 0xF4), NULL, flags, 0);
        if (pass == 0) {
            kar_granim__near_800dc7a4(data, params);
            cobj = HSD_CObjGetCurrent();
            kar_grcoll__near_800d7e78(cobj, params);
        }
        if (kar_grcoll__near_800d1d48() == 0) {
            kar_grcoll__near_800d1d98();
        }
    }
}

// NONMATCHING: large debug-display dispatcher, currently intentionally stubbed.
void kar_grcoll__near_800d81e4(void* ground, s32 pass)
{
    (void) ground;
    (void) pass;
}

void kar_grcoll__near_800d86fc(HSD_JObj* jobj, void* cb_args, s32 type)
{
    GrCollWalkParts* parts;
    s32* jobj_count;
    s32* dobj_count;
    s32* mobj_count;
    void** args;
    void* dobj;
    void* mobj;

    (void) type;
    args = cb_args;
    parts = args[0];
    jobj_count = args[1];
    dobj_count = args[2];
    mobj_count = args[3];

    if (jobj != NULL) {
        dobj = HSD_JObjGetDObj(jobj);
        SET_PTR((u8*) parts->parts + *jobj_count * 8, 0x00, jobj);
        *jobj_count = *jobj_count + 1;
        while (dobj != NULL) {
            SET_PTR((u8*) parts->links + *dobj_count * 4, 0x00, dobj);
            mobj = GET_PTR(dobj, 0x0C);
            while (mobj != NULL) {
                SET_PTR((u8*) parts->extra + *mobj_count * 4, 0x00, mobj);
                mobj = GET_PTR(mobj, 0x04);
                *mobj_count = *mobj_count + 1;
            }
            dobj = GET_PTR(dobj, 0x04);
            *dobj_count = *dobj_count + 1;
        }
    }
}

void kar_grcoll__near_800d87ec(void* parts_arg, void* jobj, s32* out_index)
{
    void* child;
    GrCollWalkParts* parts = parts_arg;

    if (jobj != NULL) {
        SET_PTR((u8*) parts->parts + *out_index * 8, 0x04, jobj);
        *out_index = *out_index + 1;
        for (child = GET_PTR(jobj, 0x08); child != NULL;
             child = GET_PTR(child, 0x0C)) {
            kar_grcoll__near_800d87ec(parts, child, out_index);
        }
    }
}

void kar_grcoll__near_800d8a4c(Vec* out)
{
    ((s32*) out)[0] = 0;
    ((s32*) out)[1] = 0;
    ((s32*) out)[2] = 0;
}
