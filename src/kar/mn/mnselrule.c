#include "functions.h"
#include <dolphin/types.h>
#include <dolphin/mtx/mtxtypes.h>
#include <kar/lb/lbairride.h>
#include <kar/lb/lbarchive.h>
#include <kar/mn/mnmenu.h>
#include <sysdolphin/gobj.h>
#include <sysdolphin/jobj.h>

typedef struct MenuContext {
    u8 pad_0[0xDC8];
    HSD_GObj* grid_choice_gobjs[5][5];
    HSD_GObj* grid_choice_alt_gobjs[5][5];
    void* num_scene_models;
    HSD_GObj* num_panel_gobj;
    void* stadium_scene_models;
    HSD_GObj* stadium_panel_gobj;
    void* cursor_scene_models;
    HSD_GObj* cursor_panel_gobj;
} MenuContext;

typedef struct MnSelruleNumPanel {
    u8 pad_0[0xC];
    u8 row;
    u8 col;
    u8 pad_E[2];
    s32 value;
    s8 digit;
    u8 alt_position;
    u8 pad_16[2];
    HSD_JObj* tens_jobj;
    HSD_JObj* ones_jobj;
    HSD_JObj* digit_jobj;
    HSD_JObj* empty_jobj;
} MnSelruleNumPanel;

typedef struct MnSelruleStadiumPanel {
    u8 pad_0[0xC];
    u8 row;
    u8 col;
    u8 index;
    u8 alt_position;
} MnSelruleStadiumPanel;

typedef struct MnSelruleCursorPanel {
    u8 pad_0[0xC];
    HSD_JObj* primary_jobj;
    HSD_JObj* secondary_jobj;
    u8 row;
    u8 col;
    u8 cursor_kind;
    u8 anim_frame;
} MnSelruleCursorPanel;

extern const f32 lbl_805E0CE8;
extern const f32 lbl_805E0CF0;
extern const f32 lbl_805E0D00;
extern const f32 lbl_805E0D04;
extern char kar_srcfile_jobj_h_805d6da0[7];
extern char lbl_805D6DA8[5];
extern char kar_srcfile_jobj_h_805d6db0[7];
extern char lbl_805D6DB8[5];
extern char kar_srcfile_jobj_h_805d6dc0[7];
extern char lbl_805D6DC8[5];

MenuContext* fn_801311E0(void);
void** fn_801311F4(void);
void fn_80179390(s32 row, s32 col, Vec* out);
void fn_80179414(s32 row, s32 col, s32 alt_position, Vec* out);
void fn_80138BA4(HSD_JObj* jobj, s32 frame, f32 rate);

#define ASSERT2(line, cond, file, str)                                         \
    ((cond) ? (void) 0 : __assert((file), (line), (str)))

#define SET_JOBJ_MTX_DIRTY_WITH_FILE(jobj, file, str)                          \
    do {                                                                       \
        if (!((jobj)->flags & 0x02000000)) {                                   \
            if ((jobj) != NULL) {                                              \
                ASSERT2(0x25D, (jobj) != NULL, (file), (str));                 \
                if (((jobj)->flags & 0x00800000) ||                            \
                    !((jobj)->flags & MTX_DIRTY)) {                            \
                    HSD_JObjSetMtxDirtySub(jobj);                              \
                }                                                              \
            }                                                                  \
        }                                                                      \
    } while (0)

#define SET_JOBJ_TRANSLATE_NUM(jobj, pos)                                      \
    do {                                                                       \
        ASSERT2(0x3A9, (jobj) != NULL, kar_srcfile_jobj_h_805d6da0,            \
                lbl_805D6DA8);                                                 \
        (jobj)->translate = (pos);                                             \
        SET_JOBJ_MTX_DIRTY_WITH_FILE(jobj, kar_srcfile_jobj_h_805d6da0,        \
                                     lbl_805D6DA8);                            \
    } while (0)

#define SET_JOBJ_TRANSLATE_STADIUM(jobj, pos)                                  \
    do {                                                                       \
        ASSERT2(0x3A9, (jobj) != NULL, kar_srcfile_jobj_h_805d6db0,            \
                lbl_805D6DB8);                                                 \
        (jobj)->translate = (pos);                                             \
        SET_JOBJ_MTX_DIRTY_WITH_FILE(jobj, kar_srcfile_jobj_h_805d6db0,        \
                                     lbl_805D6DB8);                            \
    } while (0)

#define SET_JOBJ_TRANSLATE_CURSOR(jobj, pos)                                   \
    do {                                                                       \
        ASSERT2(0x3A9, (jobj) != NULL, kar_srcfile_jobj_h_805d6dc0,            \
                lbl_805D6DC8);                                                 \
        (jobj)->translate = (pos);                                             \
        SET_JOBJ_MTX_DIRTY_WITH_FILE(jobj, kar_srcfile_jobj_h_805d6dc0,        \
                                     lbl_805D6DC8);                            \
    } while (0)

#define SET_JOBJ_SCALE_CURSOR(jobj, scale_vec)                                 \
    do {                                                                       \
        ASSERT2(0x316, (jobj) != NULL, kar_srcfile_jobj_h_805d6dc0,            \
                lbl_805D6DC8);                                                 \
        (jobj)->scale = (scale_vec);                                           \
        SET_JOBJ_MTX_DIRTY_WITH_FILE(jobj, kar_srcfile_jobj_h_805d6dc0,        \
                                     lbl_805D6DC8);                            \
    } while (0)

#define UPDATE_NUM_PANEL_JOBJS(panel)                                          \
    do {                                                                       \
        if ((panel)->value <= 0) {                                             \
            HSD_JObjSetFlagsAll((panel)->ones_jobj, HIDDEN);                  \
            HSD_JObjSetFlagsAll((panel)->tens_jobj, HIDDEN);                  \
            HSD_JObjSetFlagsAll((panel)->digit_jobj, HIDDEN);                 \
            HSD_JObjClearFlagsAll((panel)->empty_jobj, HIDDEN);               \
        } else {                                                               \
            HSD_JObjClearFlagsAll((panel)->ones_jobj, HIDDEN);                \
            HSD_JObjClearFlagsAll((panel)->tens_jobj, HIDDEN);                \
            HSD_JObjClearFlagsAll((panel)->digit_jobj, HIDDEN);               \
            HSD_JObjSetFlagsAll((panel)->empty_jobj, HIDDEN);                 \
            if ((panel)->value >= 10) {                                        \
                fn_80138BA4((panel)->tens_jobj,                               \
                            ((panel)->value % 100) / 10, lbl_805E0CE8);       \
            } else {                                                           \
                HSD_JObjSetFlagsAll((panel)->tens_jobj, HIDDEN);              \
            }                                                                  \
            fn_80138BA4((panel)->ones_jobj, (panel)->value % 10,              \
                        lbl_805E0CE8);                                        \
            fn_80138BA4((panel)->digit_jobj, (panel)->digit,                  \
                        lbl_805E0CE8);                                        \
        }                                                                      \
    } while (0)

char kar_mnselrule_bgm2d_scene_models_name[] = "ScMenSelruleBgm2d_scene_models";
char kar_mnselrule_bgct_scene_models_name[] = "ScMenSelruleBgCt_scene_models";
char kar_mnselrule_panel_scene_models_name[] = "ScMenSelrulePanel_scene_models";
char kar_mnselrule_fpos_scene_models_name[] = "ScMenSelruleFpos_scene_models";
char kar_mnselrule_frame_scene_models_name[] = "ScMenSelruleFrame_scene_models";
char kar_mnselrule_frame2_scene_models_name[] = "ScMenSelruleFrame2_scene_models";
char kar_mnselrule_cpos_scene_models_name[] = "ScMenSelruleCpos_scene_models";
char kar_mnselrule_contents_scene_models_name[] =
    "ScMenSelruleContents_scene_models";
char kar_mnselrule_num_scene_models_name[] = "ScMenSelruleNum_scene_models";
char kar_mnselrule_stadium_scene_models_name[] =
    "ScMenSelruleStadium_scene_models";
char kar_mnselrule_cursor_scene_models_name[] =
    "ScMenSelruleCursor_scene_models";

void kar_mnselrule_destroy_grid_choice_gobjs_all_slots(void)
{
    MenuContext* ctx;
    s32 row;
    s32 col;

    for (row = 0; row < 5; row++) {
        for (col = 0; col < 5; col++) {
            ctx = fn_801311E0();
            if (ctx->grid_choice_gobjs[row][col] != NULL) {
                HSD_GObjDestroy(ctx->grid_choice_gobjs[row][col]);
                ctx->grid_choice_gobjs[row][col] = NULL;
            }

            ctx = fn_801311E0();
            if (ctx->grid_choice_alt_gobjs[row][col] != NULL) {
                HSD_GObjDestroy(ctx->grid_choice_alt_gobjs[row][col]);
                ctx->grid_choice_alt_gobjs[row][col] = NULL;
            }
        }
    }
}

void kar_mnselrule_set_num_panel_alt_position_on(void)
{
    HSD_GObj* gobj = fn_801311E0()->num_panel_gobj;
    MnSelruleNumPanel* panel;
    HSD_JObj* jobj;
    Vec pos;

    if (gobj != NULL) {
        panel = gobj->user_data;
        panel->alt_position = 1;
        fn_80179414(panel->row, panel->col, panel->alt_position, &pos);
        jobj = gobj->hsd_obj;
        SET_JOBJ_TRANSLATE_NUM(jobj, pos);
    }
}

void kar_mnselrule_set_num_panel_alt_position_off(void)
{
    HSD_GObj* gobj = fn_801311E0()->num_panel_gobj;
    MnSelruleNumPanel* panel;
    HSD_JObj* jobj;
    Vec pos;

    if (gobj != NULL) {
        panel = gobj->user_data;
        panel->alt_position = 0;
        fn_80179414(panel->row, panel->col, panel->alt_position, &pos);
        jobj = gobj->hsd_obj;
        SET_JOBJ_TRANSLATE_NUM(jobj, pos);
    }
}

void kar_mnselrule_update_num_panel_digits(s32 value, s8 digit)
{
    HSD_GObj* gobj = fn_801311E0()->num_panel_gobj;
    MnSelruleNumPanel* panel;

    if (gobj != NULL) {
        panel = gobj->user_data;
        panel->value = value;
        panel->digit = digit;
        UPDATE_NUM_PANEL_JOBJS(panel);
    }
}

void kar_mnselrule_proc_update_num_panel(HSD_GObj* gobj)
{
    HSD_JObj* jobj = gobj->hsd_obj;
    MnSelruleNumPanel* panel = gobj->user_data;
    Vec pos;

    HSD_JObjAnimAll(jobj);
    fn_80179414(panel->row, panel->col, panel->alt_position, &pos);
    SET_JOBJ_TRANSLATE_NUM(jobj, pos);
}

void kar_mnselrule_load_num_scene_models(void)
{
    MenuContext* ctx = fn_801311E0();

    kar_lbarchive__near_80059520(*fn_801311F4(), &ctx->num_scene_models,
                                 kar_mnselrule_num_scene_models_name, 0);
}

void kar_mnselrule_create_num_panel(s8 row, s8 col, s8 value, s8 digit)
{
    MenuContext* ctx = fn_801311E0();
    HSD_GObj* gobj;
    HSD_JObj* jobj;
    MnSelruleNumPanel* panel;
    Vec pos;

    gobj = fn_801388A8(*(void**) *(void**) ctx->num_scene_models);
    jobj = gobj->hsd_obj;
    HSD_GObjProcCreate(gobj, kar_mnselrule_proc_update_num_panel, 2);
    fn_801389D8(jobj, *(void**) ctx->num_scene_models, lbl_805E0CE8,
                lbl_805E0CE8);

    panel = kar_diag__80138a00(gobj, 0xA9);
    panel->row = row;
    panel->col = col;
    panel->value = value;
    panel->digit = digit;
    panel->alt_position = 0;
    panel->tens_jobj = kar_lbairride__near_80055af0(gobj, 3);
    panel->ones_jobj = kar_lbairride__near_80055af0(gobj, 2);
    panel->digit_jobj = kar_lbairride__near_80055af0(gobj, 4);
    panel->empty_jobj = kar_lbairride__near_80055af0(gobj, 1);
    UPDATE_NUM_PANEL_JOBJS(panel);
    fn_80179414(row, col, panel->alt_position, &pos);
    SET_JOBJ_TRANSLATE_NUM(jobj, pos);
    ctx->num_panel_gobj = gobj;
}

void kar_mnselrule_destroy_num_panel(void)
{
    MenuContext* ctx = fn_801311E0();

    if (ctx->num_panel_gobj != NULL) {
        HSD_GObjDestroy(ctx->num_panel_gobj);
        ctx->num_panel_gobj = NULL;
    }
}

void kar_mnselrule_set_stadium_panel_alt_position_on(void)
{
    HSD_GObj* gobj = fn_801311E0()->stadium_panel_gobj;
    MnSelruleStadiumPanel* panel;
    HSD_JObj* jobj;
    Vec pos;

    if (gobj != NULL) {
        panel = gobj->user_data;
        panel->alt_position = 1;
        fn_80179414(panel->row, panel->col, panel->alt_position, &pos);
        jobj = gobj->hsd_obj;
        SET_JOBJ_TRANSLATE_STADIUM(jobj, pos);
    }
}

void kar_mnselrule_set_stadium_panel_alt_position_off(void)
{
    HSD_GObj* gobj = fn_801311E0()->stadium_panel_gobj;
    MnSelruleStadiumPanel* panel;
    HSD_JObj* jobj;
    Vec pos;

    if (gobj != NULL) {
        panel = gobj->user_data;
        panel->alt_position = 0;
        fn_80179414(panel->row, panel->col, panel->alt_position, &pos);
        jobj = gobj->hsd_obj;
        SET_JOBJ_TRANSLATE_STADIUM(jobj, pos);
    }
}

void kar_mnselrule_set_stadium_panel_index_anim(s8 index)
{
    HSD_GObj* gobj = fn_801311E0()->stadium_panel_gobj;

    if (gobj != NULL) {
        fn_80138BA4(gobj->hsd_obj, index, lbl_805E0CF0);
    }
}

void kar_mnselrule_proc_update_stadium_panel(HSD_GObj* gobj)
{
    HSD_JObj* jobj = gobj->hsd_obj;
    MnSelruleStadiumPanel* panel = gobj->user_data;
    Vec pos;

    HSD_JObjAnimAll(jobj);
    fn_80179414(panel->row, panel->col, 0, &pos);
    SET_JOBJ_TRANSLATE_STADIUM(jobj, pos);
}

void kar_mnselrule_load_stadium_scene_models(void)
{
    MenuContext* ctx = fn_801311E0();

    kar_lbarchive__near_80059520(*fn_801311F4(), &ctx->stadium_scene_models,
                                 kar_mnselrule_stadium_scene_models_name, 0);
}

void kar_mnselrule_create_stadium_panel(s8 row, s8 col, s8 index)
{
    MenuContext* ctx = fn_801311E0();
    HSD_GObj* gobj;
    HSD_JObj* jobj;
    MnSelruleStadiumPanel* panel;
    Vec pos;

    gobj = fn_801388A8(*(void**) *(void**) ctx->stadium_scene_models);
    jobj = gobj->hsd_obj;
    HSD_GObjProcCreate(gobj, kar_mnselrule_proc_update_stadium_panel, 2);
    fn_801389D8(jobj, *(void**) ctx->stadium_scene_models, (f32) index,
                lbl_805E0CF0);
    panel = kar_diag__80138a00(gobj, 0xAA);
    panel->row = row;
    panel->col = col;
    panel->index = index;
    panel->alt_position = 0;
    fn_80179414(row, col, 0, &pos);
    SET_JOBJ_TRANSLATE_STADIUM(jobj, pos);
    ctx->stadium_panel_gobj = gobj;
}

void kar_mnselrule_destroy_stadium_panel(void)
{
    MenuContext* ctx = fn_801311E0();

    if (ctx->stadium_panel_gobj != NULL) {
        HSD_GObjDestroy(ctx->stadium_panel_gobj);
        ctx->stadium_panel_gobj = NULL;
    }
}

void kar_mnselrule_show_cursor_primary_jobj(void)
{
    HSD_GObj* gobj = fn_801311E0()->cursor_panel_gobj;

    if (gobj != NULL) {
        HSD_JObjClearFlagsAll(((MnSelruleCursorPanel*) gobj->user_data)->primary_jobj,
                              HIDDEN);
    }
}

void kar_mnselrule_hide_cursor_primary_jobj(void)
{
    HSD_GObj* gobj = fn_801311E0()->cursor_panel_gobj;

    if (gobj != NULL) {
        HSD_JObjSetFlagsAll(((MnSelruleCursorPanel*) gobj->user_data)->primary_jobj,
                            HIDDEN);
    }
}

void kar_mnselrule_show_cursor_secondary_jobj(void)
{
    HSD_GObj* gobj = fn_801311E0()->cursor_panel_gobj;

    if (gobj != NULL) {
        HSD_JObjClearFlagsAll(
            ((MnSelruleCursorPanel*) gobj->user_data)->secondary_jobj, HIDDEN);
    }
}

void kar_mnselrule_hide_cursor_secondary_jobj(void)
{
    HSD_GObj* gobj = fn_801311E0()->cursor_panel_gobj;

    if (gobj != NULL) {
        HSD_JObjSetFlagsAll(((MnSelruleCursorPanel*) gobj->user_data)->secondary_jobj,
                            HIDDEN);
    }
}

void kar_mnselrule_set_cursor_anim_frame(s8 frame)
{
    MenuContext* ctx = fn_801311E0();
    HSD_GObj* gobj = ctx->cursor_panel_gobj;
    MnSelruleCursorPanel* panel;

    if (gobj != NULL) {
        panel = gobj->user_data;
        panel->anim_frame = frame;
        fn_80138B10(gobj->hsd_obj, frame, *(void**) ctx->cursor_scene_models,
                    lbl_805E0D00, lbl_805E0D04);
    }
}

void kar_mnselrule_set_cursor_grid_position(s8 row, s8 col, s8 cursor_kind)
{
    HSD_GObj* gobj = fn_801311E0()->cursor_panel_gobj;
    MnSelruleCursorPanel* panel;
    HSD_JObj* jobj;
    Vec pos;
    Vec scale;

    if (gobj != NULL) {
        jobj = gobj->hsd_obj;
        panel = gobj->user_data;
        panel->row = row;
        panel->col = col;
        panel->cursor_kind = cursor_kind + 1;
        fn_80179414(panel->row, panel->col, panel->cursor_kind, &pos);
        SET_JOBJ_TRANSLATE_CURSOR(jobj, pos);
        fn_80179390(panel->row, panel->col, &scale);
        SET_JOBJ_SCALE_CURSOR(jobj, scale);
    }
}

void kar_mnselrule_hide_cursor_panel(void)
{
    HSD_GObj* gobj = fn_801311E0()->cursor_panel_gobj;

    if (gobj != NULL) {
        kar_menu_gobj_userdata_hide(gobj);
    }
}

void kar_mnselrule_show_cursor_panel(void)
{
    HSD_GObj* gobj = fn_801311E0()->cursor_panel_gobj;

    if (gobj != NULL) {
        kar_menu_gobj_userdata_show(gobj);
    }
}

void kar_mnselrule_proc_update_cursor_panel(HSD_GObj* gobj)
{
    HSD_JObj* jobj = gobj->hsd_obj;
    MnSelruleCursorPanel* panel = gobj->user_data;
    Vec pos;
    Vec scale;

    HSD_JObjAnimAll(jobj);
    fn_80179414(panel->row, panel->col, panel->cursor_kind, &pos);
    SET_JOBJ_TRANSLATE_CURSOR(jobj, pos);
    fn_80179390(panel->row, panel->col, &scale);
    SET_JOBJ_SCALE_CURSOR(jobj, scale);
}

void kar_mnselrule_load_cursor_scene_models(void)
{
    MenuContext* ctx = fn_801311E0();

    kar_lbarchive__near_80059520(*fn_801311F4(), &ctx->cursor_scene_models,
                                 kar_mnselrule_cursor_scene_models_name, 0);
}

void kar_mnselrule_create_cursor_panel(s8 row, s8 col, s8 cursor_kind, s8 frame)
{
    MenuContext* ctx = fn_801311E0();
    HSD_GObj* gobj;
    HSD_JObj* jobj;
    MnSelruleCursorPanel* panel;
    Vec pos;
    Vec scale;

    gobj = fn_801388A8(*(void**) *(void**) ctx->cursor_scene_models);
    jobj = gobj->hsd_obj;
    HSD_GObjProcCreate(gobj, kar_mnselrule_proc_update_cursor_panel, 2);
    fn_80138B10(jobj, frame, *(void**) ctx->cursor_scene_models, lbl_805E0D00,
                lbl_805E0D04);

    panel = kar_diag__80138a00(gobj, 0xAB);
    panel->secondary_jobj = kar_lbairride__near_80055af0(gobj, 5);
    panel->primary_jobj = kar_lbairride__near_80055af0(gobj, 3);
    panel->row = row;
    panel->col = col;
    panel->cursor_kind = cursor_kind + 1;
    panel->anim_frame = frame;
    fn_80179414(row, col, panel->cursor_kind, &pos);
    SET_JOBJ_TRANSLATE_CURSOR(jobj, pos);
    fn_80179390(row, col, &scale);
    SET_JOBJ_SCALE_CURSOR(jobj, scale);
    ctx->cursor_panel_gobj = gobj;
}

void kar_mnselrule_destroy_cursor_panel(void)
{
    MenuContext* ctx = fn_801311E0();

    if (ctx->cursor_panel_gobj != NULL) {
        HSD_GObjDestroy(ctx->cursor_panel_gobj);
        ctx->cursor_panel_gobj = NULL;
    }
}
