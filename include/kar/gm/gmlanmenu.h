#ifndef __GMLANMENU_H_
#define __GMLANMENU_H_

#include <dolphin/types.h>

void kar_gmlanmenu__80008220(void);
void kar_gmlanmenu__800082a0(s32 arg0);
void kar_gmlanmenu_show_lan_bg_panel(void);
void kar_gmlanmenu_set_sis_lan_box0_message_id_adjusted(s32 id);
void kar_gmlanmenu_set_sis_lan_box1_message_id(s32 id);
void kar_gmlanmenu_set_sis_lan_box2_message_id(s32 id);
void kar_gmlanmenu_set_sis_lan_box3_message_id(s32 id);
void kar_gmlanmenu_set_sis_lan_box4_message_id(s32 id);
void kar_gmlanmenu__80277748(void);
s32 kar_gmlanmenu__near_800547e0(void* jobj);

#endif
