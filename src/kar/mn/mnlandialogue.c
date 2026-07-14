#include "functions.h"
#include <dolphin/mtx/mtxtypes.h>
#include <dolphin/types.h>
#include <kar/gm/gmlanmenu.h>
#include <kar/lb/lbairride.h>
#include <kar/lb/lbarchive.h>
#include <kar/lb/lbvector.h>
#include <kar/mn/mnmenu.h>
#include <sysdolphin/gobj.h>
#include <sysdolphin/jobj.h>

typedef struct MenuContext {
    u8 pad_0000[0x8];
    HSD_GObj* camera_gobj;
    u8 pad_000C[0x1150];
    void* lan_number_scene_models;
    HSD_GObj* lan_number_gobj;
    void* dialogue_scene_models;
    HSD_GObj* dialogue_gobj;
    void* connect_scene_models;
    HSD_GObj* connect_gobj;
    void* wait_scene_models;
    HSD_GObj* wait_gobj;
    void* select_scene_models;
    HSD_GObj* select_gobj;
    void* airride_scene_models;
    HSD_GObj* airride_gobj;
    void* city_scene_models;
    HSD_GObj* city_gobj;
    void* time_scene_models;
    HSD_GObj* time_gobj;
    void* unk_119C;
    void* sboard_bg_scene_models;
    HSD_GObj* sboard_bg_gobj;
} MenuContext;

typedef struct LanDialoguePanel {
    u8 pad_00[0xC];
    HSD_JObj* box0_origin;
    HSD_JObj* box0_right_edge;
    HSD_JObj* box0_bottom_edge;
    HSD_JObj* box1_origin;
    HSD_JObj* box1_right_edge;
    HSD_JObj* box2_origin;
    HSD_JObj* box2_right_edge;
    HSD_JObj* box1_bottom_edge;
    HSD_JObj* dialogue_anim;
    HSD_JObj* choice_anim;
} LanDialoguePanel;

typedef struct LanConnectPanel {
    u8 pad_00[0xC];
    HSD_JObj* indicators[4];
    s32 state;
    s32 timer;
} LanConnectPanel;

typedef struct LanTimePanel {
    u8 pad_00[0xC];
    HSD_JObj* digits[3];
} LanTimePanel;

typedef struct LanSboardBgPanel {
    u8 pad_00[0xC];
    HSD_JObj* jobjs[4];
} LanSboardBgPanel;

char kar_src_mnlandialogue_c[] = "mnlandialogue.c";
char kar_mnlandialogue_scene_models_name[] = "ScMenLanDialogue_scene_models";
char kar_mnlandialogue_connect_scene_models_name[] =
    "ScMenLanConnect_scene_models";
char kar_mnlandialogue_wait_scene_models_name[] =
    "ScMenLanWait_scene_models";
static u32 pad_804AD724 = 0;
char kar_mnlandialogue_select_scene_models_name[] =
    "ScMenLanSelect_scene_models";
static u32 pad_804AD744 = 0;
char kar_mnlandialogue_airride_scene_models_name[] =
    "ScMenLanAirride_scene_models";
char kar_mnlandialogue_city_scene_models_name[] =
    "ScMenLanCity_scene_models";
static u32 pad_804AD784 = 0;
char kar_mnlandialogue_time_scene_models_name[] =
    "ScMenLanTime_scene_models";
static u32 pad_804AD7A4 = 0;
char kar_mnlandialogue_sboard_bg_scene_models_name[] =
    "ScMenSboardBg_scene_models\0\0"
    "bestrapbg_gobj is NULL!\n\0\0\0\0"
    "mnbestrapbg.c\0\0\0"
    "bestrap_kind %d is illegal!\n\0\0\0";

char kar_srcfile_jobj_h_805d6e38[] = "jobj.h";
char lbl_805D6E40[] = "jobj";
char lbl_805D6E48[] = "0";

const f32 lbl_805E0E80 = 0.0f;
const f32 lbl_805E0E84 = 1.0f;
const f32 lbl_805E0E88 = 2.0f;
const f32 lbl_805E0E8C = 3.0f;
const f32 lbl_805E0E90[2] = { 4.0f, 0.0f };
const f32 lbl_805E0E98 = 0.0f;
const f32 lbl_805E0E9C = 1.0f;
const f32 lbl_805E0EA0 = 0.0f;
const f32 lbl_805E0EA4 = 1.0f;
const f32 lbl_805E0EA8 = 0.0f;
const f32 lbl_805E0EAC = 1.0f;
const f32 lbl_805E0EB0[2] = { 2.0f, 0.0f };
const f32 lbl_805E0EB8 = 0.0f;
const f32 lbl_805E0EBC = 1.0f;
const f32 lbl_805E0EC0 = 0.0f;
const f32 lbl_805E0EC4 = 1.0f;
const f32 lbl_805E0EC8 = 2.0f;
const f32 lbl_805E0ECC = 3.0f;
const f64 lbl_805E0ED0 = 4503601774854144.0;
const f32 lbl_805E0ED8 = 0.0f;
const f32 lbl_805E0EDC = 1.0f;

void* fn_80139238(void);

void kar_mnlandialogue_project_box1_origin_to_screen(Vec* out);
void kar_mnlandialogue_project_box1_right_edge_to_screen(Vec* out);
void kar_mnlandialogue_project_box1_bottom_edge_to_screen(Vec* out);

#define LOAD_F32(sym) (*(volatile const f32*) &(sym))

#define PROJECT_DIALOGUE_BOX(out, member)                                      \
    do {                                                                       \
        MenuContext* ctx = fn_801311E0();                                      \
        HSD_GObj* panel_gobj = ctx->dialogue_gobj;                             \
        if (panel_gobj != NULL) {                                              \
            LanDialoguePanel* panel = panel_gobj->user_data;                   \
            HSD_JObj* jobj = panel->member;                                    \
            Vec world;                                                         \
            if (jobj == NULL) {                                                \
                __assert(kar_srcfile_jobj_h_805d6e38, 0x3E4,                  \
                         lbl_805D6E40);                                        \
            }                                                                  \
            world = jobj->translate;                                           \
            ctx = fn_801311E0();                                               \
            if (ctx->camera_gobj != NULL) {                                    \
                kar_lbvector_project_world_to_screen(ctx->camera_gobj->hsd_obj,\
                                                     &world, out, 0);          \
            } else {                                                           \
                __assert(kar_src_mnlandialogue_c, 0x4F, lbl_805D6E48);         \
            }                                                                  \
        }                                                                      \
    } while (0)

#define REQUEST_DIALOGUE_ANIM(name, frame_const)                               \
    void name(void)                                                            \
    {                                                                          \
        HSD_GObj* gobj = fn_801311E0()->dialogue_gobj;                         \
        if (gobj != NULL) {                                                    \
            LanDialoguePanel* panel = gobj->user_data;                         \
            HSD_JObjReqAnimAll(panel->dialogue_anim, LOAD_F32(frame_const));   \
            HSD_JObjAnimAll(panel->dialogue_anim);                             \
        }                                                                      \
    }

#define REQUEST_CHOICE_ANIM(name, frame_const, msg2, msg3)                     \
    void name(void)                                                            \
    {                                                                          \
        HSD_GObj* gobj = fn_801311E0()->dialogue_gobj;                         \
        if (gobj != NULL) {                                                    \
            LanDialoguePanel* panel = gobj->user_data;                         \
            HSD_JObjReqAnimAll(panel->choice_anim, LOAD_F32(frame_const));     \
            HSD_JObjAnimAll(panel->choice_anim);                               \
            kar_gmlanmenu_set_sis_lan_box2_message_id(msg2);                   \
            kar_gmlanmenu_set_sis_lan_box3_message_id(msg3);                   \
        }                                                                      \
    }

#define REQUEST_ROOT_ANIM(name, gobj_field, frame_const)                       \
    void name(void)                                                            \
    {                                                                          \
        HSD_GObj* gobj = fn_801311E0()->gobj_field;                            \
        if (gobj != NULL) {                                                    \
            HSD_JObj* jobj = gobj->hsd_obj;                                    \
            HSD_JObjReqAnimAll(jobj, LOAD_F32(frame_const));                   \
            HSD_JObjAnimAll(jobj);                                             \
        }                                                                      \
    }

#define HIDE_PANEL(name, field)                                                \
    void name(void)                                                            \
    {                                                                          \
        HSD_GObj* gobj = fn_801311E0()->field;                                 \
        if (gobj != NULL) {                                                    \
            kar_menu_gobj_userdata_hide(gobj);                                 \
        }                                                                      \
    }

#define SHOW_PANEL(name, field)                                                \
    void name(void)                                                            \
    {                                                                          \
        HSD_GObj* gobj = fn_801311E0()->field;                                 \
        if (gobj != NULL) {                                                    \
            kar_menu_gobj_userdata_show(gobj);                                 \
        }                                                                      \
    }

#define DESTROY_PANEL(name, field)                                             \
    void name(void)                                                            \
    {                                                                          \
        MenuContext* ctx = fn_801311E0();                                      \
        if (ctx->field != NULL) {                                              \
            HSD_GObjDestroy(ctx->field);                                       \
            ctx->field = NULL;                                                 \
        }                                                                      \
    }

#define LOAD_MODELS(name, archive_func, scene_field, model_name)               \
    void name(void)                                                            \
    {                                                                          \
        MenuContext* ctx = fn_801311E0();                                      \
        void* archive = *(void**) archive_func();                              \
        kar_lbarchive__near_80059520(archive, &ctx->scene_field, model_name,   \
                                     0);                                       \
    }

#define EMPTY_PROC(name)                                                       \
    void name(HSD_GObj* gobj)                                                  \
    {                                                                          \
    }

void kar_mnlandialogue_project_box0_origin_to_screen(Vec* out)
{
    PROJECT_DIALOGUE_BOX(out, box0_origin);
}

void kar_mnlandialogue_project_box0_right_edge_to_screen(Vec* out)
{
    PROJECT_DIALOGUE_BOX(out, box0_right_edge);
}

void kar_mnlandialogue_project_box0_bottom_edge_to_screen(Vec* out)
{
    PROJECT_DIALOGUE_BOX(out, box0_bottom_edge);
}

f32 kar_mnlandialogue_get_box1_screen_width(void)
{
    Vec origin;
    Vec right_edge;
    f64 diff;

    kar_mnlandialogue_project_box1_origin_to_screen(&origin);
    kar_mnlandialogue_project_box1_right_edge_to_screen(&right_edge);
    diff = right_edge.x - origin.x;
    diff = __fabs(diff);
    return diff;
}

f32 kar_mnlandialogue_get_box1_screen_height(void)
{
    Vec origin;
    Vec bottom_edge;
    f64 diff;

    kar_mnlandialogue_project_box1_origin_to_screen(&origin);
    kar_mnlandialogue_project_box1_bottom_edge_to_screen(&bottom_edge);
    diff = bottom_edge.y - origin.y;
    diff = __fabs(diff);
    return diff;
}

void kar_mnlandialogue_project_box1_origin_to_screen(Vec* out)
{
    PROJECT_DIALOGUE_BOX(out, box1_origin);
}

void kar_mnlandialogue_project_box1_right_edge_to_screen(Vec* out)
{
    PROJECT_DIALOGUE_BOX(out, box1_right_edge);
}

void kar_mnlandialogue_project_box1_bottom_edge_to_screen(Vec* out)
{
    PROJECT_DIALOGUE_BOX(out, box1_bottom_edge);
}

void kar_mnlandialogue_project_box2_origin_to_screen(Vec* out)
{
    PROJECT_DIALOGUE_BOX(out, box2_origin);
}

REQUEST_DIALOGUE_ANIM(kar_mnlandialogue_request_dialogue_panel_anim0,
                      lbl_805E0E80)
REQUEST_DIALOGUE_ANIM(kar_mnlandialogue_request_dialogue_panel_anim1,
                      lbl_805E0E84)
REQUEST_DIALOGUE_ANIM(kar_mnlandialogue_request_dialogue_panel_anim2,
                      lbl_805E0E88)
REQUEST_DIALOGUE_ANIM(kar_mnlandialogue_request_dialogue_panel_anim3,
                      lbl_805E0E8C)
REQUEST_DIALOGUE_ANIM(kar_mnlandialogue_request_dialogue_panel_anim4,
                      lbl_805E0E90[0])

REQUEST_CHOICE_ANIM(kar_mnlandialogue_request_choice_panel_anim0_messages_3_4,
                    lbl_805E0E80, 3, 4)
REQUEST_CHOICE_ANIM(kar_mnlandialogue_request_choice_panel_anim1_messages_3_4,
                    lbl_805E0E84, 3, 4)
REQUEST_CHOICE_ANIM(kar_mnlandialogue_request_choice_panel_anim0_messages_5_6,
                    lbl_805E0E80, 5, 6)
REQUEST_CHOICE_ANIM(kar_mnlandialogue_request_choice_panel_anim1_messages_5_6,
                    lbl_805E0E84, 5, 6)

void kar_mnlandialogue_hide_choice_child_jobj(void)
{
    HSD_GObj* gobj = fn_801311E0()->dialogue_gobj;
    if (gobj != NULL) {
        LanDialoguePanel* panel = gobj->user_data;
        HSD_JObjSetFlagsAll(panel->choice_anim, HIDDEN);
    }
}

void kar_mnlandialogue_hide_panel_show_choice_child_jobj(void)
{
    HSD_GObj* gobj = fn_801311E0()->dialogue_gobj;
    if (gobj != NULL) {
        kar_menu_gobj_userdata_hide(gobj);
        gobj = fn_801311E0()->dialogue_gobj;
        if (gobj != NULL) {
            LanDialoguePanel* panel = gobj->user_data;
            HSD_JObjClearFlagsAll(panel->choice_anim, HIDDEN);
        }
    }
}

SHOW_PANEL(kar_mnlandialogue_show_panel, dialogue_gobj)
EMPTY_PROC(fn_8018436C)
LOAD_MODELS(kar_mnlandialogue_load_dialogue_scene_models, fn_8013909C,
            dialogue_scene_models, kar_mnlandialogue_scene_models_name)

void kar_mnlandialogue_create_dialogue_panel_and_cache_child_jobjs(void)
{
    MenuContext* ctx = fn_801311E0();
    HSD_GObj* gobj =
        fn_801388A8(*(void**) *(void**) ctx->dialogue_scene_models);
    HSD_JObj* jobj = gobj->hsd_obj;
    LanDialoguePanel* panel;

    HSD_GObjProcCreate(gobj, fn_8018436C, 1);
    fn_801389D8(jobj, *(void**) ctx->dialogue_scene_models,
                LOAD_F32(lbl_805E0E80), LOAD_F32(lbl_805E0E84));
    panel = kar_diag__80138a00(gobj, 0xBA);
    panel->box0_origin = kar_lbairride__near_80055af0(gobj, 2);
    panel->box0_right_edge = kar_lbairride__near_80055af0(gobj, 3);
    panel->box0_bottom_edge = kar_lbairride__near_80055af0(gobj, 4);
    panel->box1_origin = kar_lbairride__near_80055af0(gobj, 5);
    panel->box1_right_edge = kar_lbairride__near_80055af0(gobj, 6);
    panel->box2_origin = kar_lbairride__near_80055af0(gobj, 7);
    panel->box2_right_edge = kar_lbairride__near_80055af0(gobj, 8);
    panel->box1_bottom_edge = kar_lbairride__near_80055af0(gobj, 9);
    panel->dialogue_anim = kar_lbairride__near_80055af0(gobj, 13);
    panel->choice_anim = kar_lbairride__near_80055af0(gobj, 10);
    ctx->dialogue_gobj = gobj;
}

DESTROY_PANEL(kar_mnlandialogue_destroy_dialogue_panel, dialogue_gobj)

#define REQUEST_CONNECT_STATE(name, state_value)                               \
    void name(void)                                                            \
    {                                                                          \
        MenuContext* ctx = fn_801311E0();                                      \
        HSD_GObj* gobj = ctx->connect_gobj;                                    \
        if (gobj != NULL) {                                                    \
            LanConnectPanel* panel = gobj->user_data;                          \
            HSD_JObj* jobj;                                                    \
            panel->state = state_value;                                        \
            jobj = gobj->hsd_obj;                                              \
            fn_80138B10(jobj, panel->state,                                    \
                        *(void**) ctx->connect_scene_models,                   \
                        LOAD_F32(lbl_805E0E98), LOAD_F32(lbl_805E0E9C));       \
            panel->timer = 0;                                                  \
            HSD_JObjReqAnimAll(jobj, LOAD_F32(lbl_805E0E98));                  \
        }                                                                      \
    }

REQUEST_CONNECT_STATE(kar_mnlandialogue_request_connect_panel_state0_anim, 0)
REQUEST_CONNECT_STATE(kar_mnlandialogue_request_connect_panel_state1_anim, 1)
REQUEST_CONNECT_STATE(kar_mnlandialogue_request_connect_panel_state3_anim, 3)
REQUEST_CONNECT_STATE(kar_mnlandialogue_request_connect_panel_state5_anim, 5)

void kar_mnlandialogue_set_connect_indicator_count(s32 count)
{
    HSD_GObj* gobj = fn_801311E0()->connect_gobj;
    LanConnectPanel* panel;

    if (gobj == NULL) {
        return;
    }

    panel = gobj->user_data;
    HSD_JObjSetFlagsAll(panel->indicators[0], HIDDEN);
    HSD_JObjSetFlagsAll(panel->indicators[1], HIDDEN);
    HSD_JObjSetFlagsAll(panel->indicators[2], HIDDEN);
    HSD_JObjSetFlagsAll(panel->indicators[3], HIDDEN);

    switch (count) {
    case 4:
        HSD_JObjClearFlagsAll(panel->indicators[3], HIDDEN);
    case 3:
        HSD_JObjClearFlagsAll(panel->indicators[2], HIDDEN);
    case 2:
        HSD_JObjClearFlagsAll(panel->indicators[1], HIDDEN);
    case 1:
        HSD_JObjClearFlagsAll(panel->indicators[0], HIDDEN);
        break;
    default:
        HSD_JObjClearFlagsAll(panel->indicators[0], HIDDEN);
        break;
    }
}

HIDE_PANEL(kar_mnlandialogue_hide_connect_panel, connect_gobj)
SHOW_PANEL(kar_mnlandialogue_show_connect_panel, connect_gobj)

void kar_mnlandialogue_proc_update_connect_panel(HSD_GObj* gobj)
{
    HSD_JObj* jobj;
    LanConnectPanel* panel;
    LanConnectPanel* count_panel;
    s32 count;
    s32 i;
    MenuContext* ctx;

    fn_801311E0();
    jobj = gobj->hsd_obj;
    panel = gobj->user_data;
    HSD_JObjAnimAll(jobj);
    panel->timer++;

    switch (panel->state) {
    case 1:
        ctx = fn_801311E0();
        count = 0;
        if (ctx->connect_gobj == NULL) {
            count = 1;
        } else {
            i = count;
            count_panel = ctx->connect_gobj->user_data;
            for (; i < 4; i++) {
                if ((HSD_JObjGetFlags(count_panel->indicators[i]) & HIDDEN) ==
                    0) {
                    count++;
                }
            }
        }
        if (count > 2 && panel->timer >= 9) {
            panel->timer = 0;
            ctx = fn_801311E0();
            {
                HSD_GObj* next_gobj = ctx->connect_gobj;
                if (next_gobj != NULL) {
                    HSD_JObj* root = next_gobj->hsd_obj;
                    LanConnectPanel* next_panel = next_gobj->user_data;
                    next_panel->state = 2;
                    fn_80138B10(root, next_panel->state,
                                *(void**) ctx->connect_scene_models,
                                LOAD_F32(lbl_805E0E98),
                                LOAD_F32(lbl_805E0E9C));
                    HSD_JObjReqAnimAll(root, LOAD_F32(lbl_805E0E98));
                }
            }
        }
    case 3:
        ctx = fn_801311E0();
        count = 0;
        if (ctx->connect_gobj == NULL) {
            count = 1;
        } else {
            i = count;
            count_panel = ctx->connect_gobj->user_data;
            for (; i < 4; i++) {
                if ((HSD_JObjGetFlags(count_panel->indicators[i]) & HIDDEN) ==
                    0) {
                    count++;
                }
            }
        }
        if (count > 3 && panel->timer >= 9) {
            panel->timer = 0;
            ctx = fn_801311E0();
            {
                HSD_GObj* next_gobj = ctx->connect_gobj;
                if (next_gobj != NULL) {
                    HSD_JObj* root = next_gobj->hsd_obj;
                    LanConnectPanel* next_panel = next_gobj->user_data;
                    next_panel->state = 4;
                    fn_80138B10(root, next_panel->state,
                                *(void**) ctx->connect_scene_models,
                                LOAD_F32(lbl_805E0E98),
                                LOAD_F32(lbl_805E0E9C));
                    HSD_JObjReqAnimAll(root, LOAD_F32(lbl_805E0E98));
                }
            }
        }
        break;
    case 5:
        panel->timer = 0;
        break;
    default:
        if (panel->timer == 0x59) {
            panel->timer = 0;
            HSD_JObjReqAnimAll(jobj, LOAD_F32(lbl_805E0E98));
        }
        break;
    }
}

LOAD_MODELS(kar_mnlandialogue_load_connect_scene_models, fn_8013909C,
            connect_scene_models, kar_mnlandialogue_connect_scene_models_name)

void kar_mnlandialogue_create_connect_panel_and_cache_child_jobjs(void)
{
    MenuContext* ctx = fn_801311E0();
    HSD_GObj* gobj =
        fn_801388A8(*(void**) *(void**) ctx->connect_scene_models);
    HSD_JObj* jobj = gobj->hsd_obj;
    LanConnectPanel* panel;

    HSD_GObjProcCreate(gobj, kar_mnlandialogue_proc_update_connect_panel, 1);
    fn_801389D8(jobj, *(void**) ctx->connect_scene_models,
                LOAD_F32(lbl_805E0E98), LOAD_F32(lbl_805E0E9C));
    panel = kar_diag__80138a00(gobj, 0xBA);
    panel->indicators[0] = kar_lbairride__near_80055af0(gobj, 1);
    panel->indicators[1] = kar_lbairride__near_80055af0(gobj, 2);
    panel->indicators[2] = kar_lbairride__near_80055af0(gobj, 3);
    panel->indicators[3] = kar_lbairride__near_80055af0(gobj, 4);
    panel->state = 0;
    panel->timer = 0;
    ctx->connect_gobj = gobj;
}

DESTROY_PANEL(kar_mnlandialogue_destroy_connect_panel, connect_gobj)
HIDE_PANEL(kar_mnlandialogue_hide_wait_panel, wait_gobj)
SHOW_PANEL(kar_mnlandialogue_show_wait_panel, wait_gobj)

void kar_mnlandialogue_proc_anim_wait_panel(HSD_GObj* gobj)
{
    HSD_JObjAnimAll(gobj->hsd_obj);
}

LOAD_MODELS(kar_mnlandialogue_load_wait_scene_models, fn_8013909C,
            wait_scene_models, kar_mnlandialogue_wait_scene_models_name)

void kar_mnlandialogue_create_wait_panel(void)
{
    MenuContext* ctx = fn_801311E0();
    HSD_GObj* gobj = fn_801388A8(*(void**) *(void**) ctx->wait_scene_models);
    HSD_JObj* jobj = gobj->hsd_obj;

    HSD_GObjProcCreate(gobj, kar_mnlandialogue_proc_anim_wait_panel, 1);
    fn_801389D8(jobj, *(void**) ctx->wait_scene_models,
                LOAD_F32(lbl_805E0EA0), LOAD_F32(lbl_805E0EA4));
    kar_diag__80138a00(gobj, 0xBA);
    ctx->wait_gobj = gobj;
}

DESTROY_PANEL(kar_mnlandialogue_destroy_wait_panel, wait_gobj)

REQUEST_ROOT_ANIM(kar_mnlandialogue_request_select_panel_anim0, select_gobj,
                  lbl_805E0EA8)
REQUEST_ROOT_ANIM(kar_mnlandialogue_request_select_panel_anim1, select_gobj,
                  lbl_805E0EAC)
REQUEST_ROOT_ANIM(kar_mnlandialogue_request_select_panel_anim2, select_gobj,
                  lbl_805E0EB0[0])
HIDE_PANEL(kar_mnlandialogue_hide_select_panel, select_gobj)
SHOW_PANEL(kar_mnlandialogue_show_select_panel, select_gobj)
EMPTY_PROC(fn_80184EC0)
LOAD_MODELS(kar_mnlandialogue_load_select_scene_models, fn_8013909C,
            select_scene_models, kar_mnlandialogue_select_scene_models_name)

void kar_mnlandialogue_create_select_panel(void)
{
    MenuContext* ctx = fn_801311E0();
    HSD_GObj* gobj =
        fn_801388A8(*(void**) *(void**) ctx->select_scene_models);
    HSD_JObj* jobj = gobj->hsd_obj;

    HSD_GObjProcCreate(gobj, fn_80184EC0, 1);
    fn_801389D8(jobj, *(void**) ctx->select_scene_models,
                LOAD_F32(lbl_805E0EA8), LOAD_F32(lbl_805E0EAC));
    kar_diag__80138a00(gobj, 0xBA);
    ctx->select_gobj = gobj;
}

DESTROY_PANEL(kar_mnlandialogue_destroy_select_panel, select_gobj)

REQUEST_ROOT_ANIM(kar_mnlandialogue_request_airride_panel_anim0, airride_gobj,
                  lbl_805E0EB8)
REQUEST_ROOT_ANIM(kar_mnlandialogue_request_airride_panel_anim1, airride_gobj,
                  lbl_805E0EBC)
HIDE_PANEL(kar_mnlandialogue_hide_airride_panel, airride_gobj)
SHOW_PANEL(kar_mnlandialogue_show_airride_panel, airride_gobj)
EMPTY_PROC(fn_801850D8)
LOAD_MODELS(kar_mnlandialogue_load_airride_scene_models, fn_8013909C,
            airride_scene_models, kar_mnlandialogue_airride_scene_models_name)

void kar_mnlandialogue_create_airride_panel(void)
{
    MenuContext* ctx = fn_801311E0();
    HSD_GObj* gobj =
        fn_801388A8(*(void**) *(void**) ctx->airride_scene_models);
    HSD_JObj* jobj = gobj->hsd_obj;

    HSD_GObjProcCreate(gobj, fn_801850D8, 1);
    fn_801389D8(jobj, *(void**) ctx->airride_scene_models,
                LOAD_F32(lbl_805E0EB8), LOAD_F32(lbl_805E0EBC));
    kar_diag__80138a00(gobj, 0xBA);
    ctx->airride_gobj = gobj;
}

DESTROY_PANEL(kar_mnlandialogue_destroy_airride_panel, airride_gobj)

REQUEST_ROOT_ANIM(kar_mnlandialogue_request_city_panel_anim0, city_gobj,
                  lbl_805E0EC0)
REQUEST_ROOT_ANIM(kar_mnlandialogue_request_city_panel_anim1, city_gobj,
                  lbl_805E0EC4)
REQUEST_ROOT_ANIM(kar_mnlandialogue_request_city_panel_anim2, city_gobj,
                  lbl_805E0EC8)
REQUEST_ROOT_ANIM(kar_mnlandialogue_request_city_panel_anim3, city_gobj,
                  lbl_805E0ECC)
HIDE_PANEL(kar_mnlandialogue_hide_city_panel, city_gobj)
SHOW_PANEL(kar_mnlandialogue_show_city_panel, city_gobj)
EMPTY_PROC(fn_80185388)
LOAD_MODELS(kar_mnlandialogue_load_city_scene_models, fn_8013909C,
            city_scene_models, kar_mnlandialogue_city_scene_models_name)

void kar_mnlandialogue_create_city_panel(void)
{
    MenuContext* ctx = fn_801311E0();
    HSD_GObj* gobj = fn_801388A8(*(void**) *(void**) ctx->city_scene_models);
    HSD_JObj* jobj = gobj->hsd_obj;

    HSD_GObjProcCreate(gobj, fn_80185388, 1);
    fn_801389D8(jobj, *(void**) ctx->city_scene_models,
                LOAD_F32(lbl_805E0EC0), LOAD_F32(lbl_805E0EC4));
    kar_diag__80138a00(gobj, 0xBA);
    ctx->city_gobj = gobj;
}

DESTROY_PANEL(kar_mnlandialogue_destroy_city_panel, city_gobj)

void kar_mnlandialogue_update_time_panel_digits(s32 time)
{
    HSD_GObj* gobj = fn_801311E0()->time_gobj;
    LanTimePanel* panel;
    s32 value;

    if (gobj == NULL) {
        return;
    }

    panel = gobj->user_data;
    if (time < 0) {
        time = 0;
    }

    value = time % 1000;
    HSD_JObjReqAnimAll(panel->digits[0], (f32) (value % 10));
    HSD_JObjReqAnimAll(panel->digits[1], (f32) ((value / 10) % 10));
    HSD_JObjReqAnimAll(panel->digits[2], (f32) ((value / 100) % 10));
    HSD_JObjAnimAll(panel->digits[0]);
    HSD_JObjAnimAll(panel->digits[1]);
    HSD_JObjAnimAll(panel->digits[2]);
}

HIDE_PANEL(kar_mnlandialogue_hide_time_panel, time_gobj)
SHOW_PANEL(kar_mnlandialogue_show_time_panel, time_gobj)
EMPTY_PROC(fn_80185684)
LOAD_MODELS(kar_mnlandialogue_load_time_scene_models, fn_8013909C,
            time_scene_models, kar_mnlandialogue_time_scene_models_name)

void kar_mnlandialogue_create_time_panel_and_cache_digit_jobjs(void)
{
    MenuContext* ctx = fn_801311E0();
    HSD_GObj* gobj = fn_801388A8(*(void**) *(void**) ctx->time_scene_models);
    HSD_JObj* jobj = gobj->hsd_obj;
    LanTimePanel* panel;

    HSD_GObjProcCreate(gobj, fn_80185684, 1);
    fn_801389D8(jobj, *(void**) ctx->time_scene_models,
                LOAD_F32(lbl_805E0ED8), LOAD_F32(lbl_805E0EDC));
    panel = kar_diag__80138a00(gobj, 0xBA);
    panel->digits[0] = kar_lbairride__near_80055af0(gobj, 1);
    panel->digits[1] = kar_lbairride__near_80055af0(gobj, 2);
    panel->digits[2] = kar_lbairride__near_80055af0(gobj, 3);
    ctx->time_gobj = gobj;
}

DESTROY_PANEL(kar_mnlandialogue_destroy_time_panel, time_gobj)

void kar_mnlandialogue_proc_anim_sboard_bg_panel(HSD_GObj* gobj)
{
    HSD_JObjAnimAll(gobj->hsd_obj);
}

LOAD_MODELS(kar_mnlandialogue_load_sboard_bg_scene_models, fn_80139238,
            sboard_bg_scene_models,
            kar_mnlandialogue_sboard_bg_scene_models_name)

void kar_mnlandialogue_create_sboard_bg_panel_and_cache_child_jobjs(void)
{
    MenuContext* ctx = fn_801311E0();
    HSD_GObj* gobj =
        fn_801388A8(*(void**) *(void**) ctx->sboard_bg_scene_models);
    LanSboardBgPanel* panel;

    panel = kar_diag__80138a00(gobj, 0xC3);
    panel->jobjs[0] = kar_lbairride__near_80055af0(gobj, 0x14);
    panel->jobjs[1] = kar_lbairride__near_80055af0(gobj, 0x13);
    panel->jobjs[2] = kar_lbairride__near_80055af0(gobj, 0x0D);
    panel->jobjs[3] = kar_lbairride__near_80055af0(gobj, 0x12);
    HSD_GObjProcCreate(gobj, kar_mnlandialogue_proc_anim_sboard_bg_panel, 1);
    ctx->sboard_bg_gobj = gobj;
}

DESTROY_PANEL(kar_mnlandialogue_destroy_sboard_bg_panel, sboard_bg_gobj)
