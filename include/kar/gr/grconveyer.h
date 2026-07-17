#ifndef KAR_GR_GRCONVEYER_H
#define KAR_GR_GRCONVEYER_H

#include <dolphin/mtx/mtxtypes.h>
#include <dolphin/types.h>

typedef struct Ground Ground;

f32 kar_grconveyer__800e8000(void* gcp, Vec* pos, s32 face_id, Vec* out);
f32 kar_grconveyer__800e8338(Vec* pos, s32 face_id, Vec* out);
void kar_grconveyer__near_800e853c(Ground* ground);

#endif
