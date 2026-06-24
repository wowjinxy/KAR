#ifndef __MNLANDIALOGUE_H_
#define __MNLANDIALOGUE_H_

#include <dolphin/mtx/mtxtypes.h>
#include <dolphin/types.h>

void kar_mnlandialogue_show_panel(void);
void kar_mnlandialogue_show_connect_panel(void);
void kar_mnlandialogue_show_wait_panel(void);
void kar_mnlandialogue_show_select_panel(void);
void kar_mnlandialogue_show_airride_panel(void);
void kar_mnlandialogue_show_city_panel(void);
void kar_mnlandialogue_show_time_panel(void);
void kar_mnlandialogue_request_connect_panel_state0_anim(void);
void kar_mnlandialogue_project_box0_origin_to_screen(Vec* out);
void kar_mnlandialogue_project_box0_right_edge_to_screen(Vec* out);
void kar_mnlandialogue_project_box0_bottom_edge_to_screen(Vec* out);
f32 kar_mnlandialogue_get_box0_screen_width(void);
f32 kar_mnlandialogue_get_box0_screen_height(void);

#endif
