#include "functions.h"
#include <kar/lb/lbarchive.h>
#include <kar/mn/mnlandialogue.h>
#include <kar/mn/mnlannumber.h>
#include <kar/mn/mnmenu.h>
#include <sysdolphin/gobj.h>
#include <sysdolphin/jobj.h>

#if defined(VERSION_GKYJ01)
#define fn_801389D8 fn_80135518
#define fn_8013909C fn_80135BB8
#define kar_lbairride__near_80055af0 fn_80055218
#define kar_lbvector_project_world_to_screen fn_80063BD4
#define kar_mnlandialogue_project_box0_origin_to_screen fn_80180408
#define kar_mnlandialogue_project_box0_right_edge_to_screen fn_801804BC
#define kar_mnlandialogue_project_box0_bottom_edge_to_screen fn_80180570
#elif defined(VERSION_GKYP01)
#define fn_801389D8 fn_8013A5EC
#define fn_8013909C fn_8013ACB0
#define kar_lbairride__near_80055af0 fn_80056190
#define kar_lbvector_project_world_to_screen fn_80064DEC
#define kar_mnlandialogue_project_box0_origin_to_screen fn_80184A54
#define kar_mnlandialogue_project_box0_right_edge_to_screen fn_80184B08
#define kar_mnlandialogue_project_box0_bottom_edge_to_screen fn_80184BBC
#endif

typedef struct MenuContext {
    u8 pad_0[0x8];
    HSD_GObj* camera_gobj;
    u8 pad_C[0x1150];
    void* lan_number_scene_models;
    HSD_GObj* lan_number_gobj;
} MenuContext;

typedef struct LanNumberPanel {
    u8 pad_0[0xC];
    HSD_JObj* box_origin;
    HSD_JObj* box_right_edge;
    HSD_JObj* box_bottom_edge;
    HSD_JObj* detail;
} LanNumberPanel;

void fn_801389D8(HSD_JObj* jobj, void* arg1, f32 arg2, f32 arg3);
void* fn_8013909C(void);
HSD_JObj* kar_lbairride__near_80055af0(HSD_GObj* gobj, s32 id);
void kar_lbvector_project_world_to_screen(void* cobj, Vec* world, Vec* screen, s32 arg3);

#define PROJECT_BOX_TO_SCREEN(out, member)                                      \
    do {                                                                        \
        MenuContext* ctx = fn_801311E0();                                       \
        HSD_GObj* panel_gobj = ctx->lan_number_gobj;                            \
        if (panel_gobj != NULL) {                                               \
            LanNumberPanel* panel = panel_gobj->user_data;                      \
            HSD_JObj* jobj = panel->member;                                     \
            Vec world;                                                          \
            if (jobj == NULL) {                                                 \
                __assert("jobj.h", 996, "jobj");                               \
            }                                                                   \
            world = jobj->translate;                                            \
            ctx = fn_801311E0();                                                \
            if (ctx->camera_gobj != NULL) {                                     \
                kar_lbvector_project_world_to_screen(ctx->camera_gobj->hsd_obj, \
                                                     &world, out, 0);           \
            } else {                                                            \
                __assert("mnlannumber.c", 117, "0");                           \
            }                                                                   \
        }                                                                       \
    } while (0)

void kar_mnlannumber_project_box_origin_to_screen(Vec* out)
{
    PROJECT_BOX_TO_SCREEN(out, box_origin);
}

void kar_mnlannumber_project_box_right_edge_to_screen(Vec* out)
{
    PROJECT_BOX_TO_SCREEN(out, box_right_edge);
}

void kar_mnlannumber_project_box_bottom_edge_to_screen(Vec* out)
{
    PROJECT_BOX_TO_SCREEN(out, box_bottom_edge);
}

void kar_mnlannumber_request_panel_anim0(void)
{
    HSD_JObj* jobj = fn_801311E0()->lan_number_gobj->hsd_obj;
    HSD_JObjReqAnimAll(jobj, 0.0f);
    HSD_JObjAnimAll(jobj);
}

void kar_mnlannumber_request_panel_anim1(void)
{
    HSD_JObj* jobj = fn_801311E0()->lan_number_gobj->hsd_obj;
    HSD_JObjReqAnimAll(jobj, 1.0f);
    HSD_JObjAnimAll(jobj);
}

static const f32 lbl_805E0E78[2] = { 2.0f, 0.0f };

void kar_mnlannumber_request_panel_anim2(void)
{
    HSD_JObj* jobj = fn_801311E0()->lan_number_gobj->hsd_obj;
    HSD_JObjReqAnimAll(jobj, lbl_805E0E78[0]);
    HSD_JObjAnimAll(jobj);
}

void kar_mnlannumber_hide_panel(void)
{
    HSD_GObj* gobj = fn_801311E0()->lan_number_gobj;
    if (gobj != NULL) {
        kar_menu_gobj_userdata_hide(gobj);
    }
}

void kar_mnlannumber_show_panel(void)
{
    HSD_GObj* gobj = fn_801311E0()->lan_number_gobj;
    if (gobj != NULL) {
        kar_menu_gobj_userdata_show(gobj);
    }
}

void fn_80183874(HSD_GObj* gobj)
{
}

void kar_mnlannumber_load_scene_models(void)
{
    MenuContext* ctx = fn_801311E0();
    void* archive = *(void**) fn_8013909C();

    kar_lbarchive__near_80059520(archive, &ctx->lan_number_scene_models,
                                 "ScMenLanNumber_scene_models", 0);
}

void kar_mnlannumber_create_panel_and_cache_child_jobjs(void)
{
    MenuContext* ctx = fn_801311E0();
    HSD_GObj* gobj = fn_801388A8(*(void**) *(void**) ctx->lan_number_scene_models);
    HSD_JObj* jobj = gobj->hsd_obj;
    LanNumberPanel* panel;

    HSD_GObjProcCreate(gobj, fn_80183874, 1);
    fn_801389D8(jobj, *(void**) ctx->lan_number_scene_models, 0.0f, 1.0f);
    panel = kar_diag__80138a00(gobj, 0xBA);
    panel->box_origin = kar_lbairride__near_80055af0(gobj, 8);
    panel->box_right_edge = kar_lbairride__near_80055af0(gobj, 9);
    panel->box_bottom_edge = kar_lbairride__near_80055af0(gobj, 10);
    panel->detail = kar_lbairride__near_80055af0(gobj, 4);
    ctx->lan_number_gobj = gobj;
}

void kar_mnlannumber_destroy_panel(void)
{
    MenuContext* ctx = fn_801311E0();
    HSD_GObj* gobj = ctx->lan_number_gobj;

    if (gobj != NULL) {
        HSD_GObjDestroy(gobj);
        ctx->lan_number_gobj = NULL;
    }
}

f32 kar_mnlandialogue_get_box0_screen_width(void)
{
    Vec origin;
    Vec right_edge;
    f64 diff;

    kar_mnlandialogue_project_box0_origin_to_screen(&origin);
    kar_mnlandialogue_project_box0_right_edge_to_screen(&right_edge);
    diff = right_edge.x - origin.x;
    diff = __fabs(diff);
    return diff;
}

f32 kar_mnlandialogue_get_box0_screen_height(void)
{
    Vec origin;
    Vec bottom_edge;
    f64 diff;

    kar_mnlandialogue_project_box0_origin_to_screen(&origin);
    kar_mnlandialogue_project_box0_bottom_edge_to_screen(&bottom_edge);
    diff = bottom_edge.y - origin.y;
    diff = __fabs(diff);
    return diff;
}
