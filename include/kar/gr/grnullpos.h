#ifndef _KAR_GR_GRNULLPOS_H_
#define _KAR_GR_GRNULLPOS_H_

#include <dolphin/mtx/mtxtypes.h>
#include <dolphin/types.h>

s32 kar_grnullpos_get_global_dead_pos_count(void);
void kar_grnullpos_get_global_dead_pos(s32 index, Vec* pos, Vec* dir,
                                       Vec* scale);

#endif
