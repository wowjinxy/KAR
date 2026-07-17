#include "functions.h"
#include <dolphin/mtx/vec.h>
#include <dolphin/types.h>
#include <kar/gr/grrangespline.h>
#include <kar/gr/gryaku.h>
#include <kar/lb/lbvector.h>
#include <sysdolphin/memory.h>
#include <sysdolphin/objalloc.h>
#include <sysdolphin/spline.h>

#define GR_RANGE_CONNECT_MAX 10

#define GRRANGE_STR(offset) ((char*) grrangespline_search_lengths + (offset))
#define GRRANGE_GRCOMMON_H GRRANGE_STR(0x48)
#define GRRANGE_RANGE_DATA_MSG GRRANGE_STR(0x54)
#define GRRANGE_RANGE_ID_MSG GRRANGE_STR(0x60)

#define RANGE_DATA_ASSERT(line, data)                                         \
    ((data) ? ((void) 0)                                                      \
            : __assert(GRRANGE_GRCOMMON_H, line, GRRANGE_RANGE_DATA_MSG))
#define RANGE_ID_ASSERT(line, data, id)                                       \
    (((id) >= 0 && (id) < (data)->pairNum)                                    \
         ? ((void) 0)                                                         \
         : __assert(GRRANGE_GRCOMMON_H, line, GRRANGE_RANGE_ID_MSG))
#define RANGE_CTPOINT_ASSERT(line, ground, id)                                \
    (((id) >= 0 && (id) < (ground)->ctpoint_count)                            \
         ? ((void) 0)                                                         \
         : __assert(lbl_804A4540.grcommon_h, line,                           \
                    lbl_804A45D8.ct_point_id))
#define RANGE_PAIR_AT(data, index) (&(data)->pairs[index])
#define RANGE_CACHE_AT(ground, index) (&(ground)->range_cache[index])

typedef struct GroundData GroundData;
typedef struct GroundSplineSets GroundSplineSets;
typedef struct RangeData RangeData;
typedef struct RangeSplinePair RangeSplinePair;
typedef struct RangeCache RangeCache;
typedef struct RangeCacheFlags RangeCacheFlags;
typedef struct JObjTreeNode JObjTreeNode;

typedef struct GrRangeSplineStrings0 {
    char range_order[0x20];
    char grcommon_h[0x0C];
    char range_data[0x0C];
    char range_id[0x38];
} GrRangeSplineStrings0;

typedef struct GrRangeSplineStrings1 {
    char ctpoint_connect_positive[0x1C];
    char range_data[0x0C];
    char ct_point_id[0x30];
    char start_connect[0x30];
    char end_connect[0x2C];
    char start_ne_end[0x18];
    char pair_num_gt_two[0x18];
    char left_linear[0x38];
    char right_linear[0x38];
    char p_ne_neg_one[0x0C];
    char min_ne_neg_one[0x10];
    char lbkdtree_h[0x0C];
    char static_flags[0x44];
    char debug_fmt[0x3C];
    char search_level_assert[0x4C];
} GrRangeSplineStrings1;

struct RangeConnection {
    s32 range_id;
    f32 param;
    RangeConnection* target_connection;
    RangeCtPoint* target_ctpoint;
};

struct RangeCtPoint {
    RangeConnection* connections[GR_RANGE_CONNECT_MAX];
    s32 connect_num;
};

struct RangeSplinePair {
    HSD_Spline* left;
    HSD_Spline* right;
    s32 start_ctpoint_id;
    s32 end_ctpoint_id;
    u8 pad_10[0x08];
};

struct RangeData {
    RangeSplinePair* pairs;
    s32 pairNum;
};

struct RangeCacheFlags {
    u8 enabled : 1;
    u8 other : 7;
};

struct RangeCache {
    u8 type;
    u8 pad_01;
    s16 numcv;
    f32 tension;
    Vec* cv;
    f32 totalLength;
    f32* segLength;
    f32 (*segPoly)[5];
    RangeCacheFlags flags;
    u8 pad_19[3];
};

struct GroundSplineSets {
    void* course;
    RangeData* range;
    void* gravity;
    void* airflow;
    void* conveyer;
    void* item;
    void* vehicle;
};

struct GroundData {
    u8 pad_00[0x1C];
    GroundSplineSets* spline_sets;
};

struct Ground {
    u8 pad_00[0x08];
    GroundData* data;
    u8 pad_0C[0x110];
    RangeData* range_data;
    RangeCache* range_cache;
    RangeCtPoint* ctpoints;
    s32 ctpoint_count;
    void* secondary_cover_lists;
    u16* segment_index;
};

struct JObjTreeNode {
    u8 pad_00[0x08];
    JObjTreeNode* child;
    JObjTreeNode* next;
};

f32 grrangespline_search_lengths[6] = {
    10.0f, 30.0f, 50.0f, 100.0f, 150.0f, 200.0f,
};

char kar_src_grrangespline_804a4530[0x10] = "grrangespline.c";

GrRangeSplineStrings0 lbl_804A4540 = {
    "rangeCtPoint0 < rangeCtPoint1",
    "grcommon.h",
    "rangeData",
    "0 <= range_spl_id && range_spl_id < rangeData->pairNum",
};

char lbl_804A45B0[] = "ctp->connect_num < Gr_RangeConnect_Max";

GrRangeSplineStrings1 lbl_804A45D8 = {
    "ctPoint->connect_num > 0",
    "range->data",
    "0 <= ct_point_id && ct_point_id < range->ctNum",
    "startPoint->connect_num < Gr_RangeConnect_Max",
    "endPoint->connect_num < Gr_RangeConnect_Max",
    "startPoint != endPoint",
    "rangeData->pairNum > 2",
    "grInlGetLeftRangeSpline(gp, i)->type == SPLINE_LINEAR",
    "grInlGetRightRangeSpline(gp, i)->type == SPLINE_LINEAR",
    "p != -1.0F",
    "min != -1.0F",
    "lbkdtree.h",
    "lbKdtreeObjGetFlags(kdtree, objKind) & LbKdtree_Flags_Type_Static",
    "pos = %f, %f, %f, search_range = %f, level = %d, ret = %d\n",
    "search_range == grRangeSearchLevel[level] || ret == GrSearchSpline_Found",
};

HSD_ObjAllocData grrangespline_connection_objalloc_data;

__declspec(section ".sdata") char lbl_805D6120[] = "0";

__declspec(section ".sdata2") const f32 lbl_805DF6E8 = 0.0f;
__declspec(section ".sdata2") const f32 lbl_805DF6EC = 0.5f;
__declspec(section ".sdata2") const f32 lbl_805DF6F0 = 100000000.0f;
__declspec(section ".sdata2") const f32 lbl_805DF6F4 = 1.0f;
__declspec(section ".sdata2") const f32 lbl_805DF6F8 = -1.0f;
__declspec(section ".sdata2") const f64 lbl_805DF700 = 0.5;
__declspec(section ".sdata2") const f64 lbl_805DF708 = 3.0;

extern Vec* kar_lbvector_lerp(Vec* a, Vec* b, Vec* out, f32 t);
extern void kar_lbcolanim__near_8006ba28(HSD_Spline* spline, s32 idx,
                                         Vec* out);
extern f32 kar_lbcolanim__near_8006c180(HSD_Spline* spline, s32 flags,
                                        f32 param0, f32 param1);
extern void kar_mpresponse_build_sphere_aabb_center_extents(Vec* center,
                                                            void* out,
                                                            f32 radius);
extern void kar_mpresponse_build_segment_aabb_center_extents(Vec* a, Vec* b,
                                                             void* out);
extern f32 kar_collision_math_clamp_point_segment_param(Vec* a, Vec* b,
                                                        Vec* pos);
extern void kar_grzonecover_alloc_secondary_cover_lists(Ground* ground,
                                                        s32 count);
extern void kar_grzonecover_append_secondary_cover_hits(Ground* ground,
                                                        s32 id, Vec* a,
                                                        Vec* b);
extern void kar_grzonecover_finalize_secondary_cover_lists(Ground* ground,
                                                           s32 count);
extern s32 kar_grzonecover_find_cover_zone_containing_point(Ground* ground,
                                                           Vec* pos);
extern void* kar_grzonecover_get_secondary_cover_list(Ground* ground,
                                                      s32 id);
extern s32 kar_grzonecover_get_cover_list_count(void* list);
extern s32 kar_grzonecover_get_cover_list_item(void* list, s32 index);
extern void kar_lbkdtree_insert_obj(void* kdtree, s32 obj_kind, u16 id,
                                    s32 flags, void* aabb);
extern s32 kar_lbkdcoll__near_80071c90(void* world, void* tree, s32 obj_kind,
                                       void* aabb);
extern void kar_lbkdcoll__near_8007133c(void* world, void* tree);

#define LOAD_F32(sym) (*(volatile const f32*) &(sym))

u16* kar_grrangespline_get_ctpoint_pair_table_entry(u16* table,
                                                    s32 range_ctpoint0,
                                                    s32 range_ctpoint1)
{
    u16* table_base;
    s32 point0;
    s32 point1;
    s32 offset;
    s32 half;
    s32 odd;

    table_base = table;
    point1 = range_ctpoint1;
    point0 = range_ctpoint0;

    if (!(point0 < point1)) {
        __assert(kar_src_grrangespline_804a4530, 0x43,
                 lbl_804A4540.range_order);
    }

    if (point1 != 1) {
        offset = point1 - 1;
        if (offset == 0) {
            offset = 1;
        } else {
            half = offset / 2;
            odd = offset & 1;
            if (odd) {
                offset = point1 * half + half + 1;
            } else {
                offset = point1 * half;
            }
        }
        offset += point0;
        return &table_base[offset];
    }

    return &table_base[point0];
}

void kar_grrangespline_build_sample_cache(Ground* ground)
{
    RangeData* rangeData;
    RangeCache* cache;
    HSD_Spline* left;
    HSD_Spline* right;
    HSD_Spline* sample_spline;
    Vec left_pos;
    Vec right_pos;
    Vec delta;
    s32 i;
    s32 j;
    f32 param;

    rangeData = ground->range_data;
    ground->range_cache = HSD_Alloc(rangeData->pairNum * sizeof(RangeCache));

    for (i = 0; i < rangeData->pairNum; i++) {
        cache = &ground->range_cache[i];
        cache->type = 0;
        cache->tension = LOAD_F32(lbl_805DF6E8);

        RANGE_DATA_ASSERT(0x1D, rangeData);
        RANGE_ID_ASSERT(0x1E, rangeData, i);
        left = RANGE_PAIR_AT(rangeData, i)->left;
        cache->numcv = left->numcv;
        sample_spline = left;

        RANGE_DATA_ASSERT(0x1D, rangeData);
        RANGE_ID_ASSERT(0x1E, rangeData, i);
        right = RANGE_PAIR_AT(rangeData, i)->right;
        if (right->numcv > left->numcv) {
            cache->numcv = right->numcv;
            sample_spline = right;
        }

        cache->cv = HSD_Alloc(cache->numcv * sizeof(Vec));
        for (j = 0; j < cache->numcv; j++) {
            param = sample_spline->segLength[j];

            RANGE_DATA_ASSERT(0x1D, rangeData);
            RANGE_ID_ASSERT(0x1E, rangeData, i);
            splArcLengthPoint(&right_pos, RANGE_PAIR_AT(rangeData, i)->right,
                              param);

            RANGE_DATA_ASSERT(0x1D, rangeData);
            RANGE_ID_ASSERT(0x1E, rangeData, i);
            splArcLengthPoint(&left_pos, RANGE_PAIR_AT(rangeData, i)->left,
                              param);

            kar_lbvector_lerp(&right_pos, &left_pos, &cache->cv[j],
                              LOAD_F32(lbl_805DF6EC));
        }

        cache->totalLength = LOAD_F32(lbl_805DF6E8);
        cache->segLength = HSD_Alloc(cache->numcv * sizeof(f32));
        for (j = 0; j < cache->numcv - 1; j++) {
            delta.x = cache->cv[j + 1].x - cache->cv[j].x;
            delta.y = cache->cv[j + 1].y - cache->cv[j].y;
            delta.z = cache->cv[j + 1].z - cache->cv[j].z;
            cache->segLength[j] = cache->totalLength;
            cache->totalLength += PSVECMag(&delta);
        }

        cache->segLength[cache->numcv - 1] = cache->totalLength;
        for (j = 0; j < cache->numcv; j++) {
            cache->segLength[j] /= cache->totalLength;
        }

        cache->segPoly = NULL;
        cache->flags.enabled = 1;
    }
}

void kar_grrangespline_init_connection_record(RangeConnection* conn,
                                              s32 range_id, f32 param,
                                              s32 target_ctpoint,
                                              s32 target_connection)
{
    conn->range_id = range_id;
    conn->param = param;
    conn->target_ctpoint = (RangeCtPoint*) target_ctpoint;
    conn->target_connection = (RangeConnection*) target_connection;
}

void kar_grrangespline_add_ctpoint_connection(RangeCtPoint* ctpoint,
                                             s32 range_id, f32 param,
                                             s32 target_ctpoint,
                                             s32 target_connection)
{
    RangeConnection* conn;

    if (ctpoint->connect_num >= GR_RANGE_CONNECT_MAX) {
        __assert(kar_src_grrangespline_804a4530, 0xB2, lbl_804A45B0);
    }

    conn = HSD_ObjAlloc(&grrangespline_connection_objalloc_data);
    ctpoint->connections[ctpoint->connect_num] = conn;
    conn->range_id = range_id;
    conn->param = param;
    conn->target_ctpoint = (RangeCtPoint*) target_ctpoint;
    conn->target_connection = (RangeConnection*) target_connection;
    ctpoint->connect_num++;
}

void kar_grrangespline_remove_last_ctpoint_connection(RangeCtPoint* ctpoint)
{
    s32 index;

    if (ctpoint->connect_num <= 0) {
        __assert(kar_src_grrangespline_804a4530, 0xC1,
                 lbl_804A45D8.ctpoint_connect_positive);
    }

    index = ctpoint->connect_num - 1;
    ctpoint->connect_num = index;
    HSD_ObjFree(&grrangespline_connection_objalloc_data,
                ctpoint->connections[index]);
}

s32 kar_grrangespline_find_best_connected_range_from_ctpoint(
    Ground* ground, RangeCtPoint* ctpoint, RangeCtPoint* prev_ctpoint,
    s32* out_range_id, f32* out_distance, u8* out_forward)
{
    RangeConnection* conn;
    RangeConnection* best;
    s32 i;
    f32 dist;

    *out_distance = LOAD_F32(lbl_805DF6F0);
    *out_range_id = -1;
    best = NULL;

    for (i = 0; i < ctpoint->connect_num; i++) {
        conn = ctpoint->connections[i];
        if (conn->target_ctpoint == prev_ctpoint &&
            kar_grrangespline_is_spline_enabled(ground, conn->range_id)) {
            RANGE_DATA_ASSERT(0x1D, ground->range_data);
            RANGE_ID_ASSERT(0x1E, ground->range_data, conn->range_id);
            dist = kar_lbcolanim__near_8006c180(
                (HSD_Spline*) &ground->range_cache[conn->range_id], 0,
                conn->param, conn->target_connection->param);

            if (dist < *out_distance) {
                *out_distance = dist;
                *out_range_id = conn->range_id;
                best = conn;
            }
        }
    }

    if (*out_distance != LOAD_F32(lbl_805DF6F0)) {
        *out_forward = best->param < best->target_connection->param;
    }

    return *out_range_id;
}

void kar_grrangespline_build_ctpoint_connection_graph(Ground* ground)
{
    RangeData* rangeData;
    RangeSplinePair* pair;
    RangeCtPoint* startPoint;
    RangeCtPoint* endPoint;
    RangeConnection* startConn;
    RangeConnection* endConn;
    s32 i;
    s32 ct_count;

    rangeData = ground->range_data;
    ground->secondary_cover_lists = NULL;
    ground->ctpoint_count = 0;

    for (i = 0; i < rangeData->pairNum; i++) {
        pair = &rangeData->pairs[i];
        if (ground->ctpoint_count < pair->start_ctpoint_id) {
            ground->ctpoint_count = pair->start_ctpoint_id;
        }
        if (ground->ctpoint_count < pair->end_ctpoint_id) {
            ground->ctpoint_count = pair->end_ctpoint_id;
        }
    }

    ground->ctpoint_count++;
    ct_count = ground->ctpoint_count + 2;
    ground->ctpoints = HSD_Alloc(ct_count * sizeof(RangeCtPoint));

    for (i = 0; i < ground->ctpoint_count; i++) {
        ground->ctpoints[i].connect_num = 0;
    }

    for (i = 0; i < rangeData->pairNum; i++) {
        pair = &rangeData->pairs[i];
        RANGE_CTPOINT_ASSERT(0xF0, ground, pair->start_ctpoint_id);
        startPoint = &ground->ctpoints[pair->start_ctpoint_id];
        RANGE_CTPOINT_ASSERT(0xF0, ground, pair->end_ctpoint_id);
        endPoint = &ground->ctpoints[pair->end_ctpoint_id];

        if (startPoint->connect_num >= GR_RANGE_CONNECT_MAX) {
            __assert(kar_src_grrangespline_804a4530, 0x124,
                     lbl_804A45D8.start_connect);
        }
        startConn = HSD_ObjAlloc(&grrangespline_connection_objalloc_data);
        startPoint->connections[startPoint->connect_num] = startConn;

        if (endPoint->connect_num >= GR_RANGE_CONNECT_MAX) {
            __assert(kar_src_grrangespline_804a4530, 0x127,
                     lbl_804A45D8.end_connect);
        }
        endConn = HSD_ObjAlloc(&grrangespline_connection_objalloc_data);
        endPoint->connections[endPoint->connect_num] = endConn;

        startConn->range_id = i;
        startConn->param = LOAD_F32(lbl_805DF6E8);
        startConn->target_ctpoint = endPoint;
        startConn->target_connection = endConn;
        endConn->range_id = i;
        endConn->param = LOAD_F32(lbl_805DF6F4);
        endConn->target_ctpoint = startPoint;
        endConn->target_connection = startConn;

        if (startPoint == endPoint) {
            __assert(kar_src_grrangespline_804a4530, 0x12E,
                     lbl_804A45D8.start_ne_end);
        }

        startPoint->connect_num++;
        endPoint->connect_num++;
    }
}

void kar_grrangespline_assign_ctpoint_ids_by_endpoint_distance(Ground* ground)
{
    RangeData* rangeData;
    RangeSplinePair* pair;
    RangeSplinePair* other;
    Vec left_start;
    Vec left_end;
    Vec right_start;
    Vec right_end;
    Vec other_start;
    Vec other_end;
    s32 next_ctpoint;
    s32 i;
    s32 j;

    rangeData = ground->range_data;
    next_ctpoint = 0;

    for (i = 0; i < rangeData->pairNum; i++) {
        pair = &rangeData->pairs[i];

        splArcLengthPoint(&left_start, pair->left, LOAD_F32(lbl_805DF6E8));
        splArcLengthPoint(&left_end, pair->left, LOAD_F32(lbl_805DF6F4));
        splArcLengthPoint(&right_start, pair->right, LOAD_F32(lbl_805DF6E8));
        splArcLengthPoint(&right_end, pair->right, LOAD_F32(lbl_805DF6F4));

        if (pair->start_ctpoint_id == -1) {
            pair->start_ctpoint_id = next_ctpoint++;
        }
        if (pair->end_ctpoint_id == -1) {
            pair->end_ctpoint_id = next_ctpoint++;
        }

        for (j = i + 1; j < rangeData->pairNum; j++) {
            other = &rangeData->pairs[j];
            splArcLengthPoint(&other_start, other->left,
                              LOAD_F32(lbl_805DF6E8));
            splArcLengthPoint(&other_end, other->left,
                              LOAD_F32(lbl_805DF6F4));

            if (PSVECSquareDistance(&left_start, &other_start) <
                LOAD_F32(lbl_805DF6F4)) {
                other->start_ctpoint_id = pair->start_ctpoint_id;
            }
            if (PSVECSquareDistance(&left_end, &other_start) <
                LOAD_F32(lbl_805DF6F4)) {
                other->start_ctpoint_id = pair->end_ctpoint_id;
            }
            if (PSVECSquareDistance(&left_start, &other_end) <
                LOAD_F32(lbl_805DF6F4)) {
                other->end_ctpoint_id = pair->start_ctpoint_id;
            }
            if (PSVECSquareDistance(&left_end, &other_end) <
                LOAD_F32(lbl_805DF6F4)) {
                other->end_ctpoint_id = pair->end_ctpoint_id;
            }
            if (PSVECSquareDistance(&right_start, &other_start) <
                LOAD_F32(lbl_805DF6F4)) {
                other->start_ctpoint_id = pair->start_ctpoint_id;
            }
            if (PSVECSquareDistance(&right_end, &other_start) <
                LOAD_F32(lbl_805DF6F4)) {
                other->start_ctpoint_id = pair->end_ctpoint_id;
            }
            if (PSVECSquareDistance(&right_start, &other_end) <
                LOAD_F32(lbl_805DF6F4)) {
                other->end_ctpoint_id = pair->start_ctpoint_id;
            }
            if (PSVECSquareDistance(&right_end, &other_end) <
                LOAD_F32(lbl_805DF6F4)) {
                other->end_ctpoint_id = pair->end_ctpoint_id;
            }
        }
    }
}

void kar_grrangespline_init(Ground* ground)
{
    RangeData* rangeData;
    s32 i;

    rangeData = ground->data->spline_sets->range;
    ground->range_data = rangeData;
    if (rangeData == NULL) {
        return;
    }

    if (rangeData->pairNum <= 2) {
        __assert(kar_src_grrangespline_804a4530, 0x189,
                 lbl_804A45D8.pair_num_gt_two);
    }

    for (i = 0; i < rangeData->pairNum; i++) {
        RANGE_DATA_ASSERT(0x1D, rangeData);
        RANGE_ID_ASSERT(0x1E, rangeData, i);
        if (rangeData->pairs[i].left->type != 0) {
            __assert(kar_src_grrangespline_804a4530, 0x18D,
                     lbl_804A45D8.left_linear);
        }

        RANGE_DATA_ASSERT(0x1D, rangeData);
        RANGE_ID_ASSERT(0x1E, rangeData, i);
        if (rangeData->pairs[i].right->type != 0) {
            __assert(kar_src_grrangespline_804a4530, 0x18E,
                     lbl_804A45D8.right_linear);
        }
    }

    kar_grrangespline_build_sample_cache(ground);
    kar_grrangespline_assign_ctpoint_ids_by_endpoint_distance(ground);
    kar_grrangespline_build_ctpoint_connection_graph(ground);
}

void kar_grrangespline_destroy(Ground* ground)
{
    RangeData* rangeData;
    RangeCache* cache;
    RangeCtPoint* ctpoint;
    s32 i;

    rangeData = ground->range_data;
    if (rangeData == NULL) {
        return;
    }

    for (i = 0; i < rangeData->pairNum; i++) {
        cache = &ground->range_cache[i];
        HSD_Free(cache->segLength);
        HSD_Free(cache->cv);
    }
    HSD_Free(ground->range_cache);

    for (i = 0; i < ground->ctpoint_count; i++) {
        ctpoint = &ground->ctpoints[i];
        while (ctpoint->connect_num > 0) {
            kar_grrangespline_remove_last_ctpoint_connection(ctpoint);
        }
    }

    HSD_Free(ground->ctpoints);
    HSD_Free(ground->segment_index);
}

void kar_grrangespline_set_spline_enabled(Ground* ground, s32 range_spl_id,
                                          s32 enabled)
{
    RangeData* rangeData;
    RangeCache* cache;
    s32 current;

    rangeData = ground->range_data;
    RANGE_DATA_ASSERT(0x1D, rangeData);
    RANGE_ID_ASSERT(0x1E, rangeData, range_spl_id);

    cache = &ground->range_cache[range_spl_id];
    current = cache->flags.enabled;
    if (enabled != current) {
        cache->flags.enabled = enabled;
    }
}

s32 kar_grrangespline_is_spline_enabled(Ground* ground, s32 range_spl_id)
{
    RangeData* rangeData;

    rangeData = ground->range_data;
    RANGE_DATA_ASSERT(0x1D, rangeData);
    RANGE_ID_ASSERT(0x1E, rangeData, range_spl_id);

    return ground->range_cache[range_spl_id].flags.enabled;
}

void kar_grrangespline_build_segment_spatial_index(Ground* ground)
{
    RangeData* rangeData;
    RangeCache* cache;
    Ground* current;
    void* kdtree;
    Vec start;
    Vec end;
    u8 aabb[0x18];
    s32 count;
    s32 id;
    s32 i;
    s32 j;

    current = kar_gryaku_current_ground;
    kdtree = *(void**) ((u8*) current + 0x700);
    rangeData = ground->range_data;
    count = 0;
    id = 0;

    if (rangeData == NULL) {
        return;
    }

    for (i = 0; i < rangeData->pairNum; i++) {
        RANGE_DATA_ASSERT(0x1D, rangeData);
        RANGE_ID_ASSERT(0x1E, rangeData, i);
        count += ground->range_cache[i].numcv - 1;
    }

    ground->segment_index = HSD_Alloc(count * sizeof(u32));
    kar_grzonecover_alloc_secondary_cover_lists(ground, count);

    for (i = 0; i < rangeData->pairNum; i++) {
        cache = &ground->range_cache[i];
        for (j = 0; j < cache->numcv - 1; j++) {
            kar_lbcolanim__near_8006ba28((HSD_Spline*) cache, j, &start);
            kar_lbcolanim__near_8006ba28((HSD_Spline*) cache, j + 1, &end);
            kar_mpresponse_build_segment_aabb_center_extents(&start, &end,
                                                             aabb);
            kar_lbkdtree_insert_obj(kdtree, 5, (u16) id, 1, aabb);
            ground->segment_index[id * 2] = i;
            ground->segment_index[id * 2 + 1] = j;
            kar_grzonecover_append_secondary_cover_hits(ground, id, &start,
                                                        &end);
            id++;
        }
    }

    kar_grzonecover_finalize_secondary_cover_lists(ground, count);
}

s32 kar_grrangespline_query_nearest_enabled_segment(Ground* ground, Vec* pos,
                                                   s32* out_range_id,
                                                   f32* out_param,
                                                   f32* out_distance,
                                                   f32 search_range)
{
    Ground* current;
    void* tree;
    void* world;
    u8 aabb[0x18];
    RangeCache* cache;
    Vec start;
    Vec end;
    Vec near_pos;
    s32 range_id;
    s32 segment_id;
    s32 found_limited;
    f32 p;
    f32 dist;

    current = kar_gryaku_current_ground;
    tree = *(void**) ((u8*) current + 0x700);
    world = *(void**) ((u8*) current + 0x704);
    *out_distance = LOAD_F32(lbl_805DF6F8);
    found_limited = 0;

    kar_mpresponse_build_sphere_aabb_center_extents(pos, aabb, search_range);
    if (!kar_lbkdcoll__near_80071c90(world, tree, 5, aabb)) {
        found_limited = 1;
    }
    kar_lbkdcoll__near_8007133c(world, tree);

    if (ground->segment_index == NULL) {
        if (found_limited) {
            return 2;
        }
        return 1;
    }

    range_id = ground->segment_index[0];
    segment_id = ground->segment_index[1];
    RANGE_DATA_ASSERT(0x1D, ground->range_data);
    RANGE_ID_ASSERT(0x1E, ground->range_data, range_id);
    if (!kar_grrangespline_is_spline_enabled(ground, range_id)) {
        return found_limited ? 2 : 0;
    }

    cache = RANGE_CACHE_AT(ground, range_id);
    kar_lbcolanim__near_8006ba28((HSD_Spline*) cache, segment_id, &start);
    kar_lbcolanim__near_8006ba28((HSD_Spline*) cache, segment_id + 1, &end);
    p = kar_collision_math_clamp_point_segment_param(&start, &end, pos);
    *out_param =
        cache->segLength[segment_id] +
        p * (cache->segLength[segment_id + 1] - cache->segLength[segment_id]);
    kar_lbvector_lerp(&start, &end, &near_pos, p);
    dist = PSVECDistance(&near_pos, pos);
    *out_range_id = range_id;
    *out_distance = dist;

    if (found_limited) {
        return 2;
    }
    return *out_distance <= search_range;
}

s32 kar_grrangespline_find_nearest_range_position_with_fallback(
    Ground* ground, Vec* pos, s32* out_range_id, f32* out_param)
{
    f32 dist;
    f32 last_range;
    f32 search_range;
    s32 level;
    s32 ret;

    if (kar_grzonecover_find_cover_zone_containing_point(ground, pos) != -1) {
        ret = kar_grrangespline_query_nearest_enabled_segment(
            ground, pos, out_range_id, out_param, &dist,
            grrangespline_search_lengths[0]);
        if (ret == 1) {
            return 1;
        }
    }

    ret = kar_grrangespline_query_nearest_enabled_segment(
        ground, pos, out_range_id, out_param, &dist,
        grrangespline_search_lengths[2]);
    if (ret == 0) {
        return 1;
    }
    if (ret == 1) {
        last_range = dist;
        for (level = 3; level <= 5; level++) {
            search_range = last_range + 1.0f;
            if (search_range >= grrangespline_search_lengths[level]) {
                search_range = grrangespline_search_lengths[level];
            }
            ret = kar_grrangespline_query_nearest_enabled_segment(
                ground, pos, out_range_id, out_param, &last_range,
                search_range);
            if (search_range != grrangespline_search_lengths[level] &&
                ret == 0) {
                OSReport(lbl_804A45D8.debug_fmt, pos->x, pos->y, pos->z,
                         search_range, level, ret);
                __assert(kar_src_grrangespline_804a4530, 0x349,
                         lbl_804A45D8.search_level_assert);
            }
            if (ret == 0) {
                return 1;
            }
            if (ret == 2) {
                __assert(kar_src_grrangespline_804a4530, 0x356,
                         lbl_805D6120);
            }
        }
        return 0;
    }
    if (ret == 2) {
        last_range = dist;
        for (level = 0; level <= 1; level++) {
            search_range = last_range + 1.0f;
            if (search_range >= grrangespline_search_lengths[level]) {
                search_range = grrangespline_search_lengths[level];
            }
            ret = kar_grrangespline_query_nearest_enabled_segment(
                ground, pos, out_range_id, out_param, &last_range,
                search_range);
            if (search_range != grrangespline_search_lengths[level] &&
                ret == 0) {
                OSReport(lbl_804A45D8.debug_fmt, pos->x, pos->y, pos->z,
                         search_range, level, ret);
                __assert(kar_src_grrangespline_804a4530, 0x349,
                         lbl_804A45D8.search_level_assert);
            }
            if (ret == 0) {
                return 1;
            }
            if (ret == 2) {
                __assert(kar_src_grrangespline_804a4530, 0x356,
                         lbl_805D6120);
            }
        }
        __assert(kar_src_grrangespline_804a4530, 0x384, lbl_805D6120);
        return 1;
    }

    __assert(kar_src_grrangespline_804a4530, 0x38A, lbl_805D6120);
    return 0;
}

void kar_grrangespline_get_ctpoint_world_position(Ground* ground,
                                                 s32 ct_point_id, Vec* out)
{
    RangeCtPoint* ctpoint;
    RangeConnection* conn;
    s32 range_id;

    if (ground->range_data == NULL) {
        __assert(lbl_804A4540.grcommon_h, 0xEF, lbl_804A45D8.range_data);
    }
    RANGE_CTPOINT_ASSERT(0xF0, ground, ct_point_id);

    ctpoint = &ground->ctpoints[ct_point_id];
    conn = ctpoint->connections[0];
    range_id = conn->range_id;
    RANGE_DATA_ASSERT(0x1D, ground->range_data);
    RANGE_ID_ASSERT(0x1E, ground->range_data, range_id);

    splArcLengthPoint(out, (HSD_Spline*) &ground->range_cache[range_id],
                      conn->param);
}

void kar_grnullpos_collect_jobj_tree_nodes(JObjTreeNode* node,
                                           JObjTreeNode** out, s32* count)
{
    JObjTreeNode* child;

    if (node == NULL) {
        return;
    }

    out[*count] = node;
    (*count)++;

    child = node->child;
    while (child != NULL) {
        kar_grnullpos_collect_jobj_tree_nodes(child, out, count);
        child = child->next;
    }
}
