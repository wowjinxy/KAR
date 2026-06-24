#ifndef __MNLANNUMBER_H_
#define __MNLANNUMBER_H_

#include <dolphin/mtx/mtxtypes.h>
#include <dolphin/types.h>

void kar_mnlannumber_project_box_origin_to_screen(Vec* out);
void kar_mnlannumber_project_box_right_edge_to_screen(Vec* out);
void kar_mnlannumber_project_box_bottom_edge_to_screen(Vec* out);
void kar_mnlannumber_request_panel_anim0(void);
void kar_mnlannumber_request_panel_anim1(void);
void kar_mnlannumber_request_panel_anim2(void);
void kar_mnlannumber_hide_panel(void);
void kar_mnlannumber_show_panel(void);
void kar_mnlannumber_load_scene_models(void);
void kar_mnlannumber_create_panel_and_cache_child_jobjs(void);
void kar_mnlannumber_destroy_panel(void);

#endif
