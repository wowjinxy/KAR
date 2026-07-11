#include "functions.h"
#include <kar/gm/gmlanmenu.h>
#include <kar/lb/lbarchive.h>
#include <kar/mn/mnmenu.h>
#include <sysdolphin/gobj.h>
#include <sysdolphin/jobj.h>

typedef struct AutodemoContext {
    u8 state;
} AutodemoContext;

typedef struct MenuContext {
    u8 pad_0[0xEAC];
    void* title_bg_scene_models;
    void* title_fg_scene_models;
    HSD_GObj* title_bg_gobj;
    HSD_GObj* title_fg_gobj;
} MenuContext;

typedef struct TitleSceneModels {
    void* bg;
    void* fg;
} TitleSceneModels;

typedef struct TitlePanel {
    u8 pad_0[0xC];
    void* scene_models;
    u16 anim_state;
    u16 field_12;
} TitlePanel;

extern const f32 lbl_805E0D08;
extern const f32 lbl_805E0D0C;

char kar_mntitle_bg_scene_models_name[] = "ScMenTitleBg_scene_models";
char kar_mntitle_fg_scene_models_name[] = "ScMenTitleFg_scene_models";

void** fn_80131284(void);
void fn_80138B10(HSD_JObj* jobj, s32 arg1, void* arg2, f32 arg3, f32 arg4);
AutodemoContext* kar_gmautodemo__near_8000cdbc(void);

void kar_mntitle_load_bg_fg_scene_models(void)
{
    TitleSceneModels* scene_models =
        (TitleSceneModels*) &fn_801311E0()->title_bg_scene_models;

    kar_lbarchive__near_80059520(*fn_80131284(), &scene_models->bg,
                                 kar_mntitle_bg_scene_models_name,
                                 (s32) &scene_models->fg,
                                 kar_mntitle_fg_scene_models_name, 0);
}

void kar_mntitle_proc_update_bg_fg_autodemo_anim(HSD_GObj* gobj)
{
    AutodemoContext* autodemo = kar_gmautodemo__near_8000cdbc();
    HSD_JObj* jobj = gobj->hsd_obj;
    TitlePanel* panel = gobj->user_data;

    HSD_JObjAnimAll(jobj);
    if (panel->anim_state == 0) {
        if (kar_gmlanmenu__near_800547e0(jobj) == 0 || autodemo->state >= 3) {
            panel->anim_state = 1;
            fn_80138B10(jobj, 1, *(void**) panel->scene_models, lbl_805E0D08,
                        lbl_805E0D0C);
        }
    }
}

void kar_mntitle_create_bg_fg_panels(void)
{
    /* MWCC reuses this temp for the pointer and resulting boolean in r30. */
    u32 autodemo_state = (u32) kar_gmautodemo__near_8000cdbc();
    MenuContext* ctx = fn_801311E0();
    HSD_GObj* gobj;
    HSD_JObj* jobj;
    TitlePanel* panel;

    autodemo_state = ((AutodemoContext*) autodemo_state)->state >= 3;

    gobj = fn_801388A8(*(void**) *(void**) ctx->title_bg_scene_models);
    jobj = gobj->hsd_obj;
    HSD_GObjProcCreate(gobj, kar_mntitle_proc_update_bg_fg_autodemo_anim, 1);
    fn_80138B10(jobj, autodemo_state, *(void**) ctx->title_bg_scene_models,
                lbl_805E0D08, lbl_805E0D0C);
    panel = kar_diag__80138a00(gobj, 0xAC);
    panel->scene_models = ctx->title_bg_scene_models;
    panel->anim_state = autodemo_state;
    panel->field_12 = 0;
    ctx->title_bg_gobj = gobj;

    gobj = fn_801388A8(*(void**) *(void**) ctx->title_fg_scene_models);
    jobj = gobj->hsd_obj;
    HSD_GObjProcCreate(gobj, kar_mntitle_proc_update_bg_fg_autodemo_anim, 1);
    fn_80138B10(jobj, autodemo_state, *(void**) ctx->title_fg_scene_models,
                lbl_805E0D08, lbl_805E0D0C);
    panel = kar_diag__80138a00(gobj, 0xAC);
    panel->scene_models = ctx->title_fg_scene_models;
    panel->anim_state = autodemo_state;
    panel->field_12 = 0;
    ctx->title_fg_gobj = gobj;
}

void kar_mntitle_destroy_bg_fg_panels(void)
{
    MenuContext* ctx = fn_801311E0();

    if (ctx->title_bg_gobj != NULL) {
        HSD_GObjDestroy(ctx->title_bg_gobj);
        ctx->title_bg_gobj = NULL;
    }

    if (ctx->title_fg_gobj != NULL) {
        HSD_GObjDestroy(ctx->title_fg_gobj);
        ctx->title_fg_gobj = NULL;
    }
}
