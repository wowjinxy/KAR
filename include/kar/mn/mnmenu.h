#ifndef __MNMENU_H_
#define __MNMENU_H_

#include <dolphin/types.h>
#include <sysdolphin/gobj.h>
#include <sysdolphin/jobj.h>

#if defined(VERSION_GKYJ01)
#define fn_801389D8 fn_80135518
#define fn_8013909C fn_80135BB8
#define kar_menu_gobj_userdata_hide fn_801355F0
#define kar_menu_gobj_userdata_show fn_80135608
#elif defined(VERSION_GKYP01)
#define fn_801389D8 fn_8013A5EC
#define fn_8013909C fn_8013ACB0
#define kar_menu_gobj_userdata_hide fn_8013A6C4
#define kar_menu_gobj_userdata_show fn_8013A6DC
#endif

struct MenuContext;

struct MenuContext* fn_801311E0(void);
void** fn_80131284(void);
void* fn_801388A8(void* arg0);
void fn_801389D8(HSD_JObj* jobj, void* arg1, f32 arg2, f32 arg3);
void* kar_diag__80138a00(HSD_GObj* gobj, s32 arg1);
void fn_80138B10(HSD_JObj* jobj, s32 arg1, void* arg2, f32 arg3, f32 arg4);
void* fn_8013909C(void);
void kar_menu_gobj_userdata_hide(HSD_GObj* gobj);
void kar_menu_gobj_userdata_show(HSD_GObj* gobj);

#endif
