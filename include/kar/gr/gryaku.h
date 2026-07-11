#ifndef KAR_GR_GRYAKU_H
#define KAR_GR_GRYAKU_H

#include <dolphin/mtx/mtxtypes.h>
#include <dolphin/types.h>

struct Ground;
struct _HSD_GObj;

extern struct Ground* kar_gryaku_current_ground;

struct _HSD_GObj* kar_gryaku_create_yaku_from_main_kind(s32 kind);
void fn_80191B4C(void* event, Vec* out);
void fn_801C7628(void* event, Vec* out);

#endif
