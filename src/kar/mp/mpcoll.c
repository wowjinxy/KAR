#include "functions.h"
#include <dolphin/mtx/mtxtypes.h>
#include <dolphin/types.h>
#include <sysdolphin/objalloc.h>

typedef struct MpCollHandle MpCollHandle;
typedef struct MpCollSphereShape MpCollSphereShape;
typedef struct MpCollReport MpCollReport;
typedef struct MpCollFaceArray MpCollFaceArray;
typedef struct MpCollFaceEntry MpCollFaceEntry;
typedef struct ObjAllocDataStorage ObjAllocDataStorage;

struct MpCollSphereShape {
    u8 pad_00[0x30];
    f32 radius_start;
    f32 radius_end;
};

struct MpCollHandle {
    MpCollHandle* next;
    u8 pad_04[0x04];
    Vec pos;
    Vec vel;
    u8 pad_20[0x0C];
    Vec swept_extents;
    u8 pad_38[0x0C];
    MpCollReport* report;
    u8 pad_48[0x2F4];
    s32 shape_kind;
    MpCollSphereShape* sphere_shape;
    u8 pad_344[0x08];
    u8 flags_34c;
};

struct MpCollFaceEntry {
    u8 pad_00[0x38];
    void* data;
    u8 pad_3C[0x04];
};

struct MpCollFaceArray {
    u8 pad_00[0x08];
    MpCollFaceEntry* entries;
};

struct ObjAllocDataStorage {
    HSD_ObjAllocData alloc;
    u32 pad;
};

char kar_src_mpcoll_c[] = "mpcoll.c";
char kar_src_mpcoll_h[] = "mpcoll.h";
char kar_mpcoll_assert_shape_is_sphere[] =
    "mpCollGetShapeKind(mcp) == Mp_CollShapeKind_Sphere";

HSD_ObjAllocData kar_mpcoll_handle_pool;
HSD_ObjAllocData kar_mpcoll_sphere_shape_pool;
HSD_ObjAllocData kar_mpcoll_sphere_extra_pool_a;
HSD_ObjAllocData kar_mpcoll_sphere_rough_check_pool;
HSD_ObjAllocData kar_mpcoll_report_pool;
HSD_ObjAllocData kar_mpcoll_report_detail_pool;
ObjAllocDataStorage kar_mpcoll_report_subentry_pool;

char lbl_805D7330[] = "0";
const f64 lbl_805E2B40 = 4503601774854144.0;

extern MpCollHandle* lbl_805DD8C4;
extern char kar_mpcoll_report_free_not_found_fmt[];
extern const f32 lbl_805E2B38;

void OSReport(const char* fmt, ...);
void kar_mpcollreport_alloc_contact_lists(MpCollReport* report, s32 arg1);
void kar_mpcollreport_free_contact_lists(MpCollReport* report);
void kar_mpresponse_build_swept_sphere_aabb_center_extents(Vec* pos, Vec* next_pos,
                                                           Vec* extents, f32 radius_start,
                                                           f32 radius_end);

#define LOAD_F32(sym) (*(volatile const f32*) &(sym))

void kar_mpcoll_free_report(MpCollReport* report);
void kar_mpcoll_init_report_subpools(void);

void kar_mpcoll_free_handle(MpCollHandle* handle)
{
    MpCollHandle* cur;

    if (lbl_805DD8C4 == handle) {
        lbl_805DD8C4 = handle->next;
    } else {
        cur = lbl_805DD8C4;
        while (cur != NULL) {
            if (cur->next == handle) {
                cur->next = handle->next;
                goto found;
            }
            cur = cur->next;
        }

        OSReport(kar_mpcoll_report_free_not_found_fmt, handle);
        __assert(kar_src_mpcoll_c, 0x116, lbl_805D7330);
    }

found:
    kar_mpcoll_free_report(handle->report);
    HSD_ObjFree(&kar_mpcoll_handle_pool, handle);
}

MpCollHandle* kar_mpcoll_get_active_list_head(void)
{
    return lbl_805DD8C4;
}

void kar_mpcoll_apply_sphere_motion_response(MpCollHandle* handle)
{
    Vec next_pos;
    MpCollSphereShape* shape;

    if (handle->shape_kind != 0) {
        __assert(kar_src_mpcoll_h, 0xF9, kar_mpcoll_assert_shape_is_sphere);
    }

    shape = handle->sphere_shape;
    next_pos.x = handle->pos.x + handle->vel.x;
    next_pos.y = handle->pos.y + handle->vel.y;
    next_pos.z = handle->pos.z + handle->vel.z;
    kar_mpresponse_build_swept_sphere_aabb_center_extents(
        &handle->pos, &next_pos, &handle->swept_extents, shape->radius_start,
        shape->radius_end);
}

s32 kar_mpcoll_check_special_face_kind3_enabled(MpCollHandle* handle,
                                                MpCollFaceArray* face_array,
                                                s32 index)
{
    MpCollFaceEntry* entry;
    u8* entries;
    s32 offset;
    s32 result = FALSE;

    if (((handle->flags_34c >> 2) & 1) != 0) {
        entries = (u8*) face_array->entries;
        offset = index << 6;
        entry = (MpCollFaceEntry*) (entries + offset);
        if (*(s32*) ((u8*) entry->data + 0x8C) == 3) {
            result = TRUE;
        }
    }

    return result;
}

f32 kar_mpcoll_lerp_sphere_radius(MpCollHandle* handle, f32 t)
{
    MpCollSphereShape* shape;
    f32 start;
    f32 end;
    s32 equal;

    if (handle->shape_kind != 0) {
        __assert(kar_src_mpcoll_h, 0xF9, kar_mpcoll_assert_shape_is_sphere);
    }

    shape = handle->sphere_shape;
    if (handle->shape_kind != 0) {
        __assert(kar_src_mpcoll_h, 0xF9, kar_mpcoll_assert_shape_is_sphere);
    }

    start = handle->sphere_shape->radius_start;
    end = handle->sphere_shape->radius_end;
    equal = start == end;

    if ((f32) !equal != LOAD_F32(lbl_805E2B38)) {
        return t * (shape->radius_end - shape->radius_start) + shape->radius_start;
    }

    return shape->radius_start;
}

void kar_mpcoll_init_report_pool(void)
{
    HSD_ObjAllocInit(&kar_mpcoll_report_pool, 0x1E0, 4);
    kar_mpcoll_init_report_subpools();
}

MpCollReport* kar_mpcoll_alloc_report(void)
{
    MpCollReport* report = HSD_ObjAlloc(&kar_mpcoll_report_pool);

    kar_mpcollreport_alloc_contact_lists(report, 1);
    return report;
}

void kar_mpcoll_free_report(MpCollReport* report)
{
    kar_mpcollreport_free_contact_lists(report);
    HSD_ObjFree(&kar_mpcoll_report_pool, report);
}

void kar_mpcoll_init_report_subpools(void)
{
    HSD_ObjAllocInit(&kar_mpcoll_report_subentry_pool.alloc, 0x2C, 4);
    HSD_ObjAllocInit(&kar_mpcoll_report_detail_pool, 0x370, 4);
}
