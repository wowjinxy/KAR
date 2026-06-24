#ifndef _gobjuserdata_h_
#define _gobjuserdata_h_

#include <dolphin/types.h>
#include <sysdolphin/gobj.h>

#define HSD_GOBJ_USER_DATA_NONE 0xFF

extern u8 lbl_805DE351;

void HSD_GObjUserDataLink(HSD_GObj* gobj, u8 kind, void (*remove_func)(void*), void* data);
void* HSD_GObjUserDataUnlink(HSD_GObj* gobj);
void HSD_GObjUserDataRemove(HSD_GObj* gobj);

#endif
