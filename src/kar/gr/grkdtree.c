#include "functions.h"
#include <dolphin/mtx/vec.h>
#include <kar/gr/grkdtree.h>
#include <kar/gr/gryaku.h>

typedef struct Ground Ground;
typedef struct GroundData GroundData;
typedef struct GroundStaticCollisionTree GroundStaticCollisionTree;
typedef struct KdQuery KdQuery;
typedef struct KdTree KdTree;
typedef struct KdTreeDynamicKind KdTreeDynamicKind;
typedef struct KdTreeKindView KdTreeKindView;
typedef struct KdTreeStaticKind KdTreeStaticKind;
typedef struct KdListNode KdListNode;

struct GroundStaticCollisionTree {
    void* kdtree;
};

struct GroundData {
    u8 pad_00[0x48];
    GroundStaticCollisionTree* static_collision_tree;
};

struct Ground {
    u8 pad_00[0x08];
    GroundData* data;
    u8 pad_0C[0x6F4];
    void* static_collision_tree;
    void* static_collision_query;
};

struct KdListNode {
    KdListNode* next;
    u16 object_id;
};

struct KdQuery {
    u8 pad_000[0x04];
    u16 kinds[200];
    u16 kind_count;
    u16 kind_index;
    u16 object_index;
};

struct KdTree {
    void** objects;
    u8 pad_004[0x4C];
    s32 kind_count;
    u8* visited_bits;
};

struct KdTreeKindView {
    u8 pad_00[0x08];
    u8 flags;
    u8 pad_09[0x03];
    u16* object_ids;
};

struct KdTreeStaticKind {
    u16 object_id_start;
    u16 object_count;
};

struct KdTreeDynamicKind {
    KdListNode* objects;
    u16 object_count;
};

void kar_lbkdtree_add_obj_kind(void* kdtree, s32 obj_kind);
void* kar_lbkdtree__near_8007125c(void);
void kar_lbkdcoll__80071290(void* query);
void kar_lbkdtree__near_8006fa3c(void* kdtree);
void kar_grrail__near_800e8cc0(Ground* ground);
void kar_grcoursespline_build_segment_spatial_index(Ground* ground);
void kar_grrangespline_build_segment_spatial_index(Ground* ground);
void kar_mpresponse_build_capsule_aabb_center_extents(Vec* start, Vec* end,
                                                      void* aabb);
void kar_lbkdcoll__near_80071810(void* query, void* kdtree, void* aabb);
void kar_lbkdcoll__near_8007133c(void* query, void* kdtree);

char kar_src_grkdtree_804a4180[0x0C] = "grkdtree.c";
char lbl_804A418C[0x1C] = "grChkStaticCollKdtree(gp)";
char kar_src_lbkdtree_804a41a8[0x0C] = "lbkdtree.h";
char lbl_804A41B4[0x42] =
    "lbKdtreeObjGetFlags(kdtree, objKind) & LbKdtree_Flags_Type_Static";
u16 gap_07_804A41F6_data = 0;

static BOOL kar_grkdtree_has_static_collision_tree(Ground* ground)
{
    GroundStaticCollisionTree* static_collision_tree =
        ground->data->static_collision_tree;

    if (static_collision_tree != NULL && static_collision_tree->kdtree != NULL) {
        return TRUE;
    }

    return FALSE;
}

void kar_grkdtree_init_static_collision_tree(Ground* ground)
{
    KdTree* kdtree;

    if (!kar_grkdtree_has_static_collision_tree(ground)) {
        __assert(kar_src_grkdtree_804a4180, 0xC4, lbl_804A418C);
    }

    ground->static_collision_tree =
        ground->data->static_collision_tree->kdtree;
    kdtree = ground->static_collision_tree;
    kdtree->kind_count = 3;

    kar_lbkdtree_add_obj_kind(kdtree, 3);
    kar_lbkdtree_add_obj_kind(kdtree, 4);
    kar_lbkdtree_add_obj_kind(kdtree, 5);
    ground->static_collision_query = kar_lbkdtree__near_8007125c();
}

void kar_grkdtree_destroy_static_collision_tree(Ground* ground)
{
    if (!kar_grkdtree_has_static_collision_tree(ground)) {
        __assert(kar_src_grkdtree_804a4180, 0xE5, lbl_804A418C);
    }

    kar_lbkdcoll__80071290(ground->static_collision_query);
    kar_lbkdtree__near_8006fa3c(ground->static_collision_tree);
}

void kar_grkdtree_build_ground_spatial_indexes(Ground* ground)
{
    kar_grrail__near_800e8cc0(ground);
    kar_grcoursespline_build_segment_spatial_index(ground);
    kar_grrangespline_build_segment_spatial_index(ground);
}

void* kar_grkdtree_alloc_query_object(void)
{
    return kar_lbkdtree__near_8007125c();
}

void kar_grkdtree_query_segment_aabb(void* query, Vec* start, Vec* end)
{
    u8 aabb[0x18];

    kar_mpresponse_build_capsule_aabb_center_extents(start, end, aabb);
    kar_lbkdcoll__near_80071810(query,
                                kar_gryaku_current_ground->static_collision_tree,
                                aabb);
}

void kar_grkdtree_reset_query_iterator(void* query)
{
    kar_lbkdcoll__near_8007133c(
        query, kar_gryaku_current_ground->static_collision_tree);
}

// NONMATCHING: control flow is recovered, remaining risk is KDTree type shape.
s32 kar_grkdtree_next_query_object_id_for_kind(void* query, s32 obj_kind)
{
    KdQuery* kd_query = query;
    KdTree* kdtree = kar_gryaku_current_ground->static_collision_tree;
    KdTreeKindView* kind_record;
    KdTreeDynamicKind* dynamic_kind;
    KdTreeStaticKind* static_kind;
    u8* object_kind_data;
    s32 kind_offset;
    void* obj;
    s32 count;
    u16 query_index;
    s32 object_index;
    u16 query_kind;
    s32 id;
    s32 byte_index;
    s32 bit_index;
    u8* visited_bits;
    KdListNode* node;
    s32 i;

    if (kd_query->kind_count == 0) {
        return -1;
    }

    goto init_kind;

next_kind:
    query_index = kd_query->kind_index;
    obj = kdtree->objects[kd_query->kinds[query_index]];
    object_kind_data = (u8*) obj + kind_offset + 0x1C;
    static_kind = (KdTreeStaticKind*) object_kind_data;
    dynamic_kind = (KdTreeDynamicKind*) object_kind_data;

    if (kind_record->flags & 1) {
        count = static_kind->object_count;
    } else {
        count = dynamic_kind->object_count;
    }

    if (count == 0) {
        kd_query->kind_index++;
        goto check_query_index;
    }

    object_index = kd_query->object_index;
    if (object_index < count) {
        goto read_object_id;
    }

    kd_query->kind_index++;
    kd_query->object_index = 0;

check_query_index:
    if (kd_query->kind_index < kd_query->kind_count) {
        goto next_kind;
    }

    return -1;

read_object_id:
    kd_query->object_index = object_index + 1;

    query_kind = kd_query->kinds[kd_query->kind_index];
    obj = kdtree->objects[query_kind];
    object_kind_data = (u8*) obj + kind_offset + 0x1C;
    static_kind = (KdTreeStaticKind*) object_kind_data;
    dynamic_kind = (KdTreeDynamicKind*) object_kind_data;
    if (kind_record->flags & 1) {
        if (kind_record->flags & 1) {
        } else {
            __assert(kar_src_lbkdtree_804a41a8, 0xF9, lbl_804A41B4);
        }
        obj = kdtree->objects[query_kind];
        id = kind_record
                 ->object_ids[static_kind->object_id_start + object_index];
    } else {
        node = dynamic_kind->objects;
        for (i = 0; i < object_index; i++) {
            node = node->next;
        }
        id = node->object_id;
    }

    byte_index = id / 8;
    bit_index = id % 8;
    visited_bits = kdtree->visited_bits;
    if ((visited_bits[byte_index] >> bit_index) & 1) {
        goto next_kind;
    }

    visited_bits[byte_index] |= 1 << bit_index;
    return id;

init_kind:
    kind_record =
        (KdTreeKindView*) ((u8*) kdtree + (obj_kind * 0x0C));
    kind_offset = obj_kind * 0x08;
    goto next_kind;
}
