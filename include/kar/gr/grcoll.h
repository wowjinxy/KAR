#ifndef _KAR_GR_GRCOLL_H_
#define _KAR_GR_GRCOLL_H_

#include <dolphin/mtx/mtxtypes.h>
#include <dolphin/types.h>
#include <sysdolphin/jobj.h>

void kar_grcoll__800d6290(void* total, void* coll_desc);
void kar_grcoll__near_800d78b4(void* collision_root, s32 index, Vec* out);
void kar_grcoll__near_800d78e0(void* collision_root, s32 index, Vec* out);
void kar_grcoll__near_800d790c(void* collision_root, s32 index, Vec* out);
void* kar_grcoll__near_800d7940(void* collision_root, s32 index);
void* kar_grcoll__800d7954(void* collision_root, void* jobj);
void* kar_grcoll__800d79c0(void* collision_root, void* jobj, s32* index_out);
void* kar_grcoll__800d7a40(void* collision_root, void* jobj, s32 kind,
                           s32* index_out);
void kar_grcoll__800d7118(void* collision_root, s32 face_id, Vec* pos0,
                          Vec* pos1, Vec* pos2);
void kar_grcoll__near_800d7ad0(void* collision, s32 enabled);
BOOL kar_grcoll__near_800d7b0c(void* collision, s32 enabled);
void kar_grcoll__near_800d7b50(void* collision, s32 enabled);
void kar_grcoll__near_800d86fc(HSD_JObj* jobj, void* cb_args, s32 type);
void kar_grcoll__near_800d87ec(void* parts, void* jobj, s32* out_index);
void kar_grcoll__near_800d8a4c(Vec* out);
void kar_grcoll__near_803d1908(Mtx mtx, Vec* axis, f32 rad);

#endif
