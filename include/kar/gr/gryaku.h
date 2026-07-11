#ifndef KAR_GR_GRYAKU_H
#define KAR_GR_GRYAKU_H

#include <dolphin/types.h>

struct Ground;
struct _HSD_GObj;

extern struct Ground* kar_gryaku_current_ground;

struct _HSD_GObj* kar_gryaku_create_yaku_from_main_kind(s32 kind);

#endif
