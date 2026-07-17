#include "functions.h"
#include <dolphin/mtx/vec.h>
#include <kar/gr/grkdtree.h>
#include <kar/gr/gryaku.h>

typedef struct Ground Ground;
typedef struct GroundData GroundData;
typedef struct GroundStaticCollisionTree GroundStaticCollisionTree;
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

#define QUERY_KIND_COUNT(query) (*(u16*) ((u8*) (query) + 0x194))
#define QUERY_KIND_INDEX(query) (*(u16*) ((u8*) (query) + 0x196))
#define QUERY_OBJECT_INDEX(query) (*(u16*) ((u8*) (query) + 0x198))
#define QUERY_KIND_AT(query, index) \
    (*(u16*) ((u8*) (query) + 0x04 + ((index) * sizeof(u16))))

#define TREE_OBJECTS(tree) (*(void***) ((u8*) (tree) + 0x00))
#define TREE_KIND_FLAGS(tree, kind) (*(u8*) ((u8*) (tree) + ((kind) * 0x0C) + 0x08))
#define TREE_KIND_LIST(tree, kind) (*(u16**) ((u8*) (tree) + ((kind) * 0x0C) + 0x0C))
#define TREE_VISITED_BITS(tree) (*(u8**) ((u8*) (tree) + 0x54))
#define TREE_OBJECT_KIND_FIELD(obj, kind, offset) \
    (*(u16*) ((u8*) (obj) + ((kind) * 0x08) + (offset)))
#define TREE_OBJECT_KIND_PTR(obj, kind, offset) \
    (*(void**) ((u8*) (obj) + ((kind) * 0x08) + (offset)))

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
    void* kdtree;

    if (!kar_grkdtree_has_static_collision_tree(ground)) {
        __assert(kar_src_grkdtree_804a4180, 0xC4, lbl_804A418C);
    }

    ground->static_collision_tree =
        ground->data->static_collision_tree->kdtree;
    kdtree = ground->static_collision_tree;
    *(s32*) ((u8*) kdtree + 0x50) = 3;

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
    void* kdtree = kar_gryaku_current_ground->static_collision_tree;
    u8* kind_record;
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

    if (QUERY_KIND_COUNT(query) == 0) {
        return -1;
    }

    goto init_kind;

next_kind:
    query_index = QUERY_KIND_INDEX(query);
    obj = TREE_OBJECTS(kdtree)[QUERY_KIND_AT(query, query_index)];

    if (*(u8*) (kind_record + 0x08) & 1) {
        count = *(u16*) ((u8*) obj + kind_offset + 0x1E);
    } else {
        count = *(u16*) ((u8*) obj + kind_offset + 0x20);
    }

    if (count == 0) {
        QUERY_KIND_INDEX(query)++;
        goto check_query_index;
    }

    object_index = QUERY_OBJECT_INDEX(query);
    if (object_index < count) {
        goto read_object_id;
    }

    QUERY_KIND_INDEX(query)++;
    QUERY_OBJECT_INDEX(query) = 0;

check_query_index:
    if (QUERY_KIND_INDEX(query) < QUERY_KIND_COUNT(query)) {
        goto next_kind;
    }

    return -1;

read_object_id:
    QUERY_OBJECT_INDEX(query) = object_index + 1;

    query_kind = QUERY_KIND_AT(query, QUERY_KIND_INDEX(query));
    obj = TREE_OBJECTS(kdtree)[query_kind];
    if (*(u8*) (kind_record + 0x08) & 1) {
        if (*(u8*) (kind_record + 0x08) & 1) {
        } else {
            __assert(kar_src_lbkdtree_804a41a8, 0xF9, lbl_804A41B4);
        }
        obj = TREE_OBJECTS(kdtree)[query_kind];
        id = (*(u16**) (kind_record + 0x0C))
            [*(u16*) ((u8*) obj + kind_offset + 0x1C) + object_index];
    } else {
        node = *(KdListNode**) ((u8*) obj + kind_offset + 0x1C);
        for (i = 0; i < object_index; i++) {
            node = node->next;
        }
        id = node->object_id;
    }

    byte_index = id / 8;
    bit_index = id % 8;
    visited_bits = TREE_VISITED_BITS(kdtree);
    if ((visited_bits[byte_index] >> bit_index) & 1) {
        goto next_kind;
    }

    visited_bits[byte_index] |= 1 << bit_index;
    return id;

init_kind:
    kind_record = (u8*) kdtree + (obj_kind * 0x0C);
    kind_offset = obj_kind * 0x08;
    goto next_kind;
}
