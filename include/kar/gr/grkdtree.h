#ifndef KAR_GR_GRKDTREE_H
#define KAR_GR_GRKDTREE_H

#include <dolphin/mtx/mtxtypes.h>
#include <dolphin/types.h>

struct Ground;

void kar_grkdtree_init_static_collision_tree(struct Ground* ground);
void kar_grkdtree_destroy_static_collision_tree(struct Ground* ground);
void kar_grkdtree_build_ground_spatial_indexes(struct Ground* ground);
void* kar_grkdtree_alloc_query_object(void);
void kar_grkdtree_query_segment_aabb(void* query, Vec* start, Vec* end);
void kar_grkdtree_reset_query_iterator(void* query);
s32 kar_grkdtree_next_query_object_id_for_kind(void* query, s32 obj_kind);

#endif
