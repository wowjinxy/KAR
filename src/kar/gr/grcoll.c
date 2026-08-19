#include "functions.h"
#include <dolphin/mtx/mtx.h>
#include <dolphin/mtx/vec.h>
#include <dolphin/types.h>
#include <kar/gr/grcoll.h>
#include <sysdolphin/dobj.h>
#include <sysdolphin/jobj.h>
#include <sysdolphin/memory.h>
#include <sysdolphin/mtx.h>
#include <sysdolphin/pobj.h>

typedef struct GrCollFace GrCollFace;
typedef struct GrCollFaceFlagBits GrCollFaceFlagBits;
typedef struct GrCollDisplayData GrCollDisplayData;
typedef struct GrCollDisplayRecords GrCollDisplayRecords;
typedef struct GrCollDisplayRoot GrCollDisplayRoot;
typedef struct GrCollJoint GrCollJoint;
typedef struct GrCollJointTable GrCollJointTable;
typedef struct GrCollJointTableEntry GrCollJointTableEntry;
typedef struct GrCollPartEntry GrCollPartEntry;
typedef struct GrCollRoot GrCollRoot;
typedef struct GrCollRough GrCollRough;
typedef struct GrCollSourceDescription GrCollSourceDescription;
typedef struct GrCollSourceFace GrCollSourceFace;
typedef struct GrCollSourceJoint GrCollSourceJoint;
typedef struct GrCollSourceZoneFace GrCollSourceZoneFace;
typedef struct GrCollSourceZoneJoint GrCollSourceZoneJoint;
typedef struct GrCollZone GrCollZone;
typedef struct GrCollWalkParts GrCollWalkParts;
typedef struct Ground Ground;
typedef struct GroundData GroundData;

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

struct GrCollZone {
    HSD_JObj* jobj;
    u8 pad_004[0x20];
    u32 kind;
    u8 pad_028[0xB8];
    Mtx transform;
    u8 pad_110[0x30];
};

struct GrCollRough {
    u8 data[0x1C];
};

struct GrCollRoot {
    Vec* verts;
    s32 vert_count;
    GrCollFace* faces;
    s32 face_count;
    GrCollJoint* joints;
    s32 joint_count;
    Vec* zvtx;
    s32 zvtx_count;
    GrCollZone* zones;
    s32 zone_count;
    GrCollRough* rough;
    s32 rough_count;
    GrCollJoint** move_joints;
    s32 move_joint_count;
    GrCollZone** move_zones;
    s32 move_zone_count;
    GrCollRough** move_rough;
    s32 move_rough_count;
};

struct GrCollPartEntry {
    HSD_JObj* jobj;
    HSD_Joint* collision_joint;
};

struct GrCollWalkParts {
    GrCollPartEntry* parts;
    HSD_DObj** links;
    HSD_PObj** extra;
};

struct GrCollSourceFace {
    s32 vertex_indices[3];
    u32 info0;
    u32 info1;
};

struct GrCollSourceJoint {
    s32 jobj_index;
    s32 vertex_start;
    s32 vertex_count;
    s32 face_start;
    s32 face_count;
    u32 unk_14;
    u32 unk_18;
};

struct GrCollSourceZoneFace {
    u8 pad_00[0x14];
    u32 info1;
};

struct GrCollSourceZoneJoint {
    u8 pad_00[0x0C];
    s32 face_start;
    u8 pad_10[0x3C];
};

struct GrCollSourceDescription {
    Vec* verts;
    s32 vert_count;
    GrCollSourceFace* faces;
    s32 face_count;
    GrCollSourceJoint* joints;
    s32 joint_count;
    Vec* zone_verts;
    s32 zone_vert_count;
    GrCollSourceZoneFace* zone_faces;
    s32 zone_face_count;
    GrCollSourceZoneJoint* zone_joints;
    s32 zone_count;
};

struct GrCollJointTableEntry {
    HSD_JObj* jobj;
    void* unk_04;
};

struct GrCollJointTable {
    GrCollJointTableEntry* entries;
};

struct GroundData {
    u8 pad_00[0x18];
    GrCollSourceDescription* collision;
};

struct Ground {
    u8 pad_000[0x08];
    GroundData* data;
    GrCollRoot totals;
    GrCollRoot allocations;
    GrCollRoot collision;
    u8 pad_0E4[0x20];
    GrCollJointTable joint_table;
};

struct GrCollDisplayRecords {
    u8 pad_00[0x0C];
    void* entries;
};

struct GrCollDisplayData {
    u8 pad_000[0x08];
    GrCollDisplayRecords* bounds;
    u8 pad_00C[0xE8];
    HSD_JObj* overlay_jobj;
    u8 pad_0F8[0x624];
    u8 flags;
};

struct GrCollDisplayRoot {
    u8 pad_00[0x28];
    HSD_JObj* jobj;
    GrCollDisplayData* data;
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

void kar_grcoll__800d6290(void* total_arg, void* coll_desc_arg)
{
    s32 i;
    s32 j;
    u32 move_flag;
    GrCollSourceFace* face;
    GrCollSourceJoint* joint;
    GrCollSourceZoneFace* zone;
    GrCollRoot* total = total_arg;
    GrCollSourceDescription* coll_desc = coll_desc_arg;

    total->vert_count += coll_desc->vert_count;
    total->face_count += coll_desc->face_count;
    total->joint_count += coll_desc->joint_count;
    total->zvtx_count += coll_desc->zone_vert_count;
    total->zone_count += coll_desc->zone_count;

    for (i = 0; i < coll_desc->joint_count; i++) {
        joint = &coll_desc->joints[i];
        face = &coll_desc->faces[joint->face_start];
        move_flag = (face->info1 >> 5) & 1;
        for (j = 0; j < joint->face_count; j++) {
            if (move_flag != ((face->info1 >> 5) & 1)) {
                OSReport(lbl_804A3B98, i, j);
                __assert(kar_src_grcoll_804a3bbc, 0x50, lbl_805D60B0);
            }
            face++;
        }
        if (move_flag != 0) {
            total->move_joint_count++;
        }
    }

    for (i = 0; i < coll_desc->zone_count; i++) {
        zone = &coll_desc
                    ->zone_faces[coll_desc->zone_joints[i].face_start];
        move_flag = (zone->info1 >> 5) & 1;
        for (j = 0; j < 12; j++) {
            if (move_flag != ((zone->info1 >> 5) & 1)) {
                OSReport(kar_src_grcoll_804a3bbc + 0x0C, i, j);
                __assert(kar_src_grcoll_804a3bbc, 0x68, lbl_805D60B0);
            }
            zone++;
        }
        if (move_flag != 0) {
            total->move_zone_count++;
        }
    }

    face = coll_desc->faces;
    for (i = 0; i < coll_desc->face_count; i++) {
        if ((face->info1 & 3) != 0) {
            total->rough_count++;
            if ((face->info1 & 0x20) == 0x20) {
                total->move_rough_count++;
            }
        }
        face++;
    }
}

void kar_grcoll__800d64b8(GrCollRoot* alloc, GrCollRoot* total,
                          GrCollRoot* root,
                          GrCollSourceDescription* coll_desc,
                          GrCollJointTable* joint_table, s32 index)
{
    s32 i;
    s32 src_vertex;
    s32 src_face;
    GrCollSourceJoint* src_joint;
    Vec* src_vtx;
    GrCollSourceFace* src_tri;
    GrCollJoint* joint;
    GrCollFace* face;

    src_joint = &coll_desc->joints[index];
    src_vertex = src_joint->vertex_start;
    src_face = src_joint->face_start;
    joint = &root->joints[index];

    joint->jobj = joint_table->entries[src_joint->jobj_index].jobj;
    joint->verts = root->verts + src_vertex;
    joint->vert_count = src_joint->vertex_count;
    joint->faces = root->faces + src_face;
    joint->face_count = src_joint->face_count;
    joint->unk_8C = src_joint->unk_14;
    joint->unk_90 = src_joint->unk_18;

    src_vtx = &coll_desc->verts[src_vertex];
    for (i = 0; i < joint->vert_count; i++) {
        joint->verts[i * 2].x = src_vtx[i].x;
        joint->verts[i * 2].y = src_vtx[i].y;
        joint->verts[i * 2].z = src_vtx[i].z;
    }

    src_tri = &coll_desc->faces[src_face];
    for (i = 0; i < joint->face_count; i++) {
        face = &joint->faces[i];
        face->pos[0] = root->verts + src_tri->vertex_indices[0] * 2;
        face->pos[1] = root->verts + src_tri->vertex_indices[1] * 2;
        face->pos[2] = root->verts + src_tri->vertex_indices[2] * 2;
        face->info0 = src_tri->info0;
        face->info1 = src_tri->info1;
        face->flags |= 0x60;
        face->joint = joint;
        src_tri++;
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

void kar_grcoll__near_800d6724(GrCollRoot* root)
{
    root->verts = NULL;
    root->faces = NULL;
    root->joints = NULL;
    root->zvtx = NULL;
    root->zones = NULL;
    root->rough = NULL;
    root->move_joints = NULL;
    root->move_zones = NULL;
    root->move_rough = NULL;
    root->vert_count = 0;
    root->face_count = 0;
    root->joint_count = 0;
    root->zvtx_count = 0;
    root->zone_count = 0;
    root->rough_count = 0;
    root->move_joint_count = 0;
    root->move_zone_count = 0;
    root->move_rough_count = 0;
}

void kar_grcoll__800d6774(GrCollRoot* alloc, GrCollRoot* total,
                          GrCollRoot* root,
                          GrCollSourceDescription* coll_desc,
                          GrCollJointTable* joint_table)
{
    s32 i;

    root->verts = alloc->verts + alloc->vert_count * 2;
    root->vert_count = coll_desc->vert_count;
    alloc->vert_count += coll_desc->vert_count;
    if (total->vert_count < alloc->vert_count) {
        OSReport(kar_src_grcoll_804a3bbc + 0x28, alloc->vert_count);
        __assert(kar_src_grcoll_804a3bbc, 0x181,
                 kar_src_grcoll_804a3bbc + 0x6C);
    }

    root->faces = alloc->faces + alloc->face_count;
    root->face_count = coll_desc->face_count;
    alloc->face_count += coll_desc->face_count;
    if (total->face_count < alloc->face_count) {
        OSReport(kar_src_grcoll_804a3bbc + 0x28, alloc->face_count);
        __assert(kar_src_grcoll_804a3bbc, 0x186,
                 kar_src_grcoll_804a3bbc + 0x8C);
    }

    root->joints = alloc->joints + alloc->joint_count;
    root->joint_count = coll_desc->joint_count;
    alloc->joint_count += coll_desc->joint_count;
    if (total->joint_count < alloc->joint_count) {
        OSReport(kar_src_grcoll_804a3bbc + 0x28, alloc->joint_count);
        __assert(kar_src_grcoll_804a3bbc, 0x18B,
                 kar_src_grcoll_804a3bbc + 0xB0);
    }

    root->zvtx = alloc->zvtx + alloc->zvtx_count;
    root->zvtx_count = coll_desc->zone_vert_count;
    alloc->zvtx_count += coll_desc->zone_vert_count;
    if (total->zvtx_count < alloc->zvtx_count) {
        OSReport(kar_src_grcoll_804a3bbc + 0x28, alloc->zvtx_count);
        __assert(kar_src_grcoll_804a3bbc, 0x190,
                 kar_src_grcoll_804a3bbc + 0xD4);
    }

    root->zones = alloc->zones + alloc->zone_count;
    root->zone_count = coll_desc->zone_count;
    alloc->zone_count += coll_desc->zone_count;
    if (total->zone_count < alloc->zone_count) {
        OSReport(kar_src_grcoll_804a3bbc + 0x28, alloc->zone_count);
        __assert(kar_src_grcoll_804a3bbc, 0x195,
                 kar_src_grcoll_804a3bbc + 0xF8);
    }

    root->rough = alloc->rough + alloc->rough_count;
    root->rough_count = 0;
    root->move_joints = alloc->move_joints + alloc->move_joint_count;
    root->move_joint_count = 0;
    root->move_zones = alloc->move_zones + alloc->move_zone_count;
    root->move_zone_count = 0;
    root->move_rough = alloc->move_rough + alloc->move_rough_count;
    root->move_rough_count = 0;

    for (i = 0; i < coll_desc->joint_count; i++) {
        kar_grcoll__800d64b8(alloc, total, root, coll_desc, joint_table, i);
    }
    for (i = 0; i < coll_desc->zone_count; i++) {
        kar_grzone_build_zone_from_zjoint(alloc, total, root, coll_desc,
                                          joint_table, i);
    }
    for (i = 0; i < root->face_count; i++) {
        kar_grrough__800dc7e4(alloc, total, root, coll_desc, i);
    }
}

// NONMATCHING: transform update flow is recovered, but the exact register and
// AABB scheduling still needs a focused pass against the asm.
void kar_grcoll__near_800d6a70(GrCollRoot* root,
                               GrCollSourceDescription* coll_desc)
{
    s32 i;
    s32 j;
    HSD_JObj* jobj;
    GrCollJoint* joint;
    GrCollFace* face;
    Vec min;
    Vec max;
    Vec root_min;
    Vec root_max;
    s32 normal_ok;
    Vec* src;

    for (i = 0; i < root->joint_count; i++) {
        joint = &root->joints[i];
        jobj = joint->jobj;
        grcoll_assert_jobj(jobj);
        PSMTXCopy(jobj->mtx, joint->mtx);
        src = &coll_desc->verts[coll_desc->joints[i].vertex_start];
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
    }

    for (i = 0; i < root->zone_count; i++) {
        kar_grzone_update_zone_world_transform(root, coll_desc, i);
    }
    for (i = 0; i < root->rough_count; i++) {
        kar_grrough__near_800dc8e0(root, coll_desc, i);
    }
}

void kar_grcoll__near_800d6d88(GrCollRoot* alloc, GrCollRoot* total,
                               GrCollRoot* root,
                               GrCollSourceDescription* coll_desc,
                               GrCollJointTable* joint_table)
{
    kar_grcoll__800d6774(alloc, total, root, coll_desc, joint_table);
    kar_grcoll__near_800d6a70(root, coll_desc);
}

// NONMATCHING: this is the allocator/setup skeleton. The yaku-data loops are
// still raw-offset based until the surrounding ground data structs are named.
void kar_grcoll__800d6dcc(Ground* ground)
{
    GrCollRoot* alloc;
    GrCollRoot* root;
    GrCollRoot* total;
    GrCollSourceDescription* coll_desc;

    total = &ground->totals;
    alloc = &ground->allocations;
    root = &ground->collision;
    kar_grcoll__near_800d6724(total);
    coll_desc = ground->data->collision;
    kar_grcoll__800d6290(total, coll_desc);

    alloc->verts = HSD_Alloc(total->vert_count * sizeof(Vec) * 2);
    alloc->faces = HSD_Alloc(total->face_count * sizeof(GrCollFace));
    alloc->joints = HSD_Alloc(total->joint_count * sizeof(GrCollJoint));
    alloc->zvtx = HSD_Alloc(total->zvtx_count * sizeof(Vec));
    alloc->zones = HSD_Alloc(total->zone_count * sizeof(GrCollZone));
    alloc->rough = HSD_Alloc(total->rough_count * sizeof(GrCollRough));
    alloc->move_joints =
        HSD_Alloc(total->move_joint_count * sizeof(GrCollJoint*));
    alloc->move_zones =
        HSD_Alloc(total->move_zone_count * sizeof(GrCollZone*));
    alloc->move_rough =
        HSD_Alloc(total->move_rough_count * sizeof(GrCollRough*));
    alloc->vert_count = 0;
    alloc->face_count = 0;
    alloc->joint_count = 0;
    alloc->zvtx_count = 0;
    alloc->zone_count = 0;
    alloc->rough_count = 0;
    alloc->move_joint_count = 0;
    alloc->move_zone_count = 0;
    alloc->move_rough_count = 0;

    kar_grcoll__near_800d6d88(alloc, total, root, coll_desc,
                              &ground->joint_table);
}

void kar_grcoll__near_800d7060(Ground* ground)
{
    GrCollRoot* alloc = &ground->allocations;

    if (alloc->verts != NULL) {
        HSD_Free(alloc->verts);
    }
    if (alloc->faces != NULL) {
        HSD_Free(alloc->faces);
    }
    if (alloc->joints != NULL) {
        HSD_Free(alloc->joints);
    }
    if (alloc->zones != NULL) {
        HSD_Free(alloc->zones);
    }
    if (alloc->zones != NULL) {
        HSD_Free(alloc->zones);
    }
    if (alloc->rough != NULL) {
        HSD_Free(alloc->rough);
    }
    if (alloc->move_joints != NULL) {
        HSD_Free(alloc->move_joints);
    }
    if (alloc->move_rough != NULL) {
        HSD_Free(alloc->move_rough);
    }
    if (alloc->move_rough != NULL) {
        HSD_Free(alloc->move_rough);
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
void kar_grcoll__near_800d7268(GrCollRoot* root,
                               GrCollSourceDescription* coll_desc, s32 index)
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

void kar_grcoll__near_800d7648(GrCollRoot* root,
                               GrCollSourceDescription* coll_desc)
{
    s32 i;
    s32 index;

    for (i = 0; i < root->move_joint_count; i++) {
        index = root->move_joints[i] - root->joints;
        kar_grcoll__near_800d7268(root, coll_desc, index);
    }
    for (i = 0; i < root->move_zone_count; i++) {
        index = root->move_zones[i] - root->zones;
        kar_grzone_update_zone_world_transform(root, coll_desc, index);
    }
    for (i = 0; i < root->move_rough_count; i++) {
        index = root->move_rough[i] - root->rough;
        kar_grrough__near_800dc8e0(root, coll_desc, index);
    }
}

void kar_grcoll__near_800d777c(Ground* ground)
{
    kar_grcoll__near_800d7648(&ground->collision, ground->data->collision);
}

void kar_grcoll__near_800d78b4(void* collision_root, s32 index, Vec* out)
{
    Mtx* mtx;

    mtx = &((GrCollRoot*) collision_root)->zones[index].transform;
    out->x = (*mtx)[0][2];
    out->y = (*mtx)[1][2];
    out->z = (*mtx)[2][2];
}

void kar_grcoll__near_800d78e0(void* collision_root, s32 index, Vec* out)
{
    Mtx* mtx;

    mtx = &((GrCollRoot*) collision_root)->zones[index].transform;
    out->x = (*mtx)[0][1];
    out->y = (*mtx)[1][1];
    out->z = (*mtx)[2][1];
}

void kar_grcoll__near_800d790c(void* collision_root, s32 index, Vec* out)
{
    HSD_MtxGetTranslate(
        ((GrCollRoot*) collision_root)->zones[index].transform, out);
}

void* kar_grcoll__near_800d7940(void* collision_root, s32 index)
{
    return ((GrCollRoot*) collision_root)->zones[index].pad_110;
}

void* kar_grcoll__800d7954(void* collision_root, void* jobj)
{
    s32 i;
    GrCollJoint* joint;
    GrCollRoot* root = collision_root;

    if (0 < root->joint_count) {
        for (i = 0; i < root->joint_count; i++) {
            joint = &root->joints[i];
            if (joint->jobj == jobj) {
                return joint;
            }
        }
    }
    __assert(kar_src_grcoll_804a3bbc, 0x332, lbl_805D60B0);
    return NULL;
}

void* kar_grcoll__800d79c0(void* collision_root, void* jobj, s32* index_out)
{
    s32 i;
    GrCollZone* zone;
    GrCollRoot* root = collision_root;

    for (i = 0; i < root->zone_count; i++) {
        zone = &root->zones[i];
        if (zone->jobj == jobj) {
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
    GrCollZone* zone;
    GrCollRoot* root = collision_root;

    for (i = 0; i < root->zone_count; i++) {
        zone = &root->zones[i];
        if (zone->jobj == jobj && (s32) (zone->kind & 0x01FFFFFF) == kind) {
            if (index_out != NULL) {
                *index_out = i;
            }
            return zone;
        }
    }
    __assert(kar_src_grcoll_804a3bbc, 0x36C, lbl_805D60B0);
    return NULL;
}

void kar_grcoll__near_800d7ad0(void* collision_arg, s32 enabled)
{
    s32 i;
    GrCollJoint* collision = collision_arg;

    for (i = 0; i < collision->face_count; i++) {
        ((GrCollFaceFlagBits*) &collision->faces[i].flags)->bit6 = enabled;
    }
}

BOOL kar_grcoll__near_800d7b0c(void* collision_arg, s32 enabled)
{
    s32 i;
    GrCollJoint* collision = collision_arg;

    for (i = 0; i < collision->face_count; i++) {
        if (((collision->faces[i].flags >> 6) & 1) != enabled) {
            return FALSE;
        }
    }
    return TRUE;
}

void kar_grcoll__near_800d7b50(void* collision_arg, s32 enabled)
{
    s32 i;
    GrCollJoint* collision = collision_arg;

    for (i = 0; i < collision->face_count; i++) {
        ((GrCollFaceFlagBits*) &collision->faces[i].flags)->bit5 = enabled;
    }
}

void kar_grcoll__near_800d7d70(GrCollRoot* collision_root, s32 enabled)
{
    s32 i;
    s32 j;
    GrCollJoint* joint;

    for (i = 0; i < collision_root->joint_count; i++) {
        joint = &collision_root->joints[i];
        for (j = 0; j < joint->face_count; j++) {
            ((GrCollFaceFlagBits*) &joint->faces[j].flags)->bit6 = enabled;
        }
    }
}

void kar_grcoll__near_800d7dd4(void* root, void* a, void* b, void* c,
                               u32 pass)
{
    GrCollDisplayRoot* display_root = root;
    GrCollDisplayData* data;
    u32 flags;

    data = display_root->data;
    if (data->bounds->entries != NULL) {
        if (pass == 0) {
            if (((u32) data->flags >> 7) != 0) {
                kar_grdispbbox_update_jobj_bounds_records(data);
            }
            kar_grdispbbox_update_visible_parts_for_camera(data, a, b, c);
        }
        flags = GObj_GetFlagFromArray(pass);
        HSD_JObjDispAll(display_root->jobj, NULL, flags, 0);
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
    GrCollDisplayRoot* display_root = ground;
    GrCollDisplayData* data;
    void* cobj;
    u8 params[16];
    u32 flags;

    data = display_root->data;
    if (data->overlay_jobj != NULL) {
        if (kar_grcoll__near_800d1d48() == 0) {
            kar_grcoll__near_800d1dcc();
        }
        flags = GObj_GetFlagFromArray(pass);
        HSD_JObjDispAll(data->overlay_jobj, NULL, flags, 0);
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
    HSD_DObj* dobj;
    HSD_PObj* pobj;

    (void) type;
    args = cb_args;
    parts = args[0];
    jobj_count = args[1];
    dobj_count = args[2];
    mobj_count = args[3];

    if (jobj != NULL) {
        dobj = HSD_JObjGetDObj(jobj);
        parts->parts[*jobj_count].jobj = jobj;
        *jobj_count = *jobj_count + 1;
        while (dobj != NULL) {
            parts->links[*dobj_count] = dobj;
            pobj = dobj->pobj;
            while (pobj != NULL) {
                parts->extra[*mobj_count] = pobj;
                pobj = pobj->next;
                *mobj_count = *mobj_count + 1;
            }
            dobj = dobj->next;
            *dobj_count = *dobj_count + 1;
        }
    }
}

void kar_grcoll__near_800d87ec(void* parts_arg, void* jobj, s32* out_index)
{
    HSD_Joint* child;
    HSD_Joint* joint = jobj;
    GrCollWalkParts* parts = parts_arg;

    if (joint != NULL) {
        parts->parts[*out_index].collision_joint = joint;
        *out_index = *out_index + 1;
        for (child = joint->child; child != NULL; child = child->next) {
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
