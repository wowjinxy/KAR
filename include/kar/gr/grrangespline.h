#ifndef KAR_GR_GRRANGESPLINE_H
#define KAR_GR_GRRANGESPLINE_H

#include <dolphin/mtx/mtxtypes.h>
#include <dolphin/types.h>

typedef struct Ground Ground;
typedef struct RangeConnection RangeConnection;
typedef struct RangeCtPoint RangeCtPoint;

u16* kar_grrangespline_get_ctpoint_pair_table_entry(u16* table,
                                                    s32 range_ctpoint0,
                                                    s32 range_ctpoint1);
void kar_grrangespline_build_sample_cache(Ground* ground);
void kar_grrangespline_init_connection_record(RangeConnection* conn,
                                              s32 range_id, f32 param,
                                              s32 target_ctpoint,
                                              s32 target_connection);
void kar_grrangespline_add_ctpoint_connection(RangeCtPoint* ctpoint,
                                             s32 range_id, f32 param,
                                             s32 target_ctpoint,
                                             s32 target_connection);
void kar_grrangespline_remove_last_ctpoint_connection(RangeCtPoint* ctpoint);
s32 kar_grrangespline_find_best_connected_range_from_ctpoint(
    Ground* ground, RangeCtPoint* ctpoint, RangeCtPoint* prev_ctpoint,
    s32* out_range_id, f32* out_distance, u8* out_forward);
void kar_grrangespline_build_ctpoint_connection_graph(Ground* ground);
void kar_grrangespline_assign_ctpoint_ids_by_endpoint_distance(Ground* ground);
void kar_grrangespline_init(Ground* ground);
void kar_grrangespline_destroy(Ground* ground);
void kar_grrangespline_set_spline_enabled(Ground* ground, s32 range_spl_id,
                                          s32 enabled);
s32 kar_grrangespline_is_spline_enabled(Ground* ground, s32 range_spl_id);
void kar_grrangespline_build_segment_spatial_index(Ground* ground);
s32 kar_grrangespline_query_nearest_enabled_segment(Ground* ground, Vec* pos,
                                                   s32* out_range_id,
                                                   f32* out_param,
                                                   f32* out_distance,
                                                   f32 search_range);
s32 kar_grrangespline_find_nearest_range_position_with_fallback(
    Ground* ground, Vec* pos, s32* out_range_id, f32* out_param);
void kar_grrangespline_get_ctpoint_world_position(Ground* ground,
                                                 s32 ct_point_id, Vec* out);

#endif
