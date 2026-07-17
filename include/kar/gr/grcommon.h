#ifndef KAR_GR_GRCOMMON_H
#define KAR_GR_GRCOMMON_H

#include <dolphin/mtx/mtxtypes.h>
#include <dolphin/types.h>

struct GlobalDeadEntry;
struct Ground;

void kar_grcommon__800ceeb8(Vec* pos, s32 pos_id,
                            struct GlobalDeadEntry* out);
f32 kar_grcommon__near_800d066c(s32 a, s32 b, f32 c, f32 d);
void kar_grcommon_get_conveyerpos_vectors_by_index(s32 index, Vec* pos,
                                                   Vec* vec1, Vec* vec2);
s32 kar_grcommon_get_conveyerpos_num(void);
void kar_grcommon__800db5d4(struct Ground* ground, void* bitCounterIdAll, s32 id);
void kar_grcommon__800db654(struct Ground* ground, void* bitCounterIdAll, s32 id);

#endif
