#ifndef __EFCONTROL_H_
#define __EFCONTROL_H_

#include <dolphin/types.h>
#include <sysdolphin/gobj.h>
#include <sysdolphin/jobj.h>

typedef struct EffectCtrl EffectCtrl;

struct EffectCtrl {
    HSD_GObj* gobj;
    s32 anim_resource_id;
    void* field_08;
    s32 anim_index;
    HSD_GObjProc* proc;
};

extern char lbl_8055DA08[];

void kar_efcontrol__near_8023f514(HSD_GObj* gobj);
void kar_efcontrol__near_8023f4e4(void);
void kar_efcontrol__near_8023f8f8(HSD_JObj* jobj, void* joint_anim,
                                  void* mat_anim, void* shape_anim,
                                  s32 flags);

#endif
