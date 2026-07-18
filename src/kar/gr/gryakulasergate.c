#include "functions.h"
#include <dolphin/types.h>
#include <kar/gr/graudio.h>
#include <kar/gr/gryaku.h>
#include <kar/gr/gryakulasergate.h>
#include <sysdolphin/aobj.h>
#include <sysdolphin/gobj.h>
#include <sysdolphin/jobj.h>

typedef struct Ground Ground;
typedef struct GroundJObjEntry GroundJObjEntry;
typedef struct Yaku Yaku;
typedef struct YakuParamLink YakuParamLink;
typedef struct LaserGateParam LaserGateParam;
typedef struct LaserGateCtrlParam LaserGateCtrlParam;
typedef struct LaserGateCtrlData LaserGateCtrlData;
typedef void (*GroundCallback)(void);

#if defined(VERSION_GKYJ01)
#define kar_gryakulib_get_yaku_state_or_none fn_800F68C4
#define kar_graudio_stop_active_fgm_slot fn_800E8FAC
#define LASERGATE_ASSERT_TARGET_COUNT_LINE 0x138
#define LASERGATE_ASSERT_GATE_KIND_LINE 0xF4
#define LASERGATE_ASSERT_AOBJ_LINE 0x7D
#define LASERGATE_ASSERT_CTRL_KIND_LINE 0x198
#define LASERGATE_ZERO lbl_805DA460
#define LASERGATE_ONE lbl_805DA464
#define LASERGATE_ASSERT_AOBJ lbl_805D0D78
#define LASERGATE_ASSERT_ZERO lbl_805D0D80

__declspec(section ".sdata") char lbl_805D0D50[] = "aobj";
__declspec(section ".sdata") char lbl_805D0D58[] = "aobj";
extern char LASERGATE_ASSERT_AOBJ[];
extern char LASERGATE_ASSERT_ZERO[];
__declspec(section ".sdata2") extern const f32 LASERGATE_ZERO;
__declspec(section ".sdata2") extern const f32 LASERGATE_ONE;
#elif defined(VERSION_GKYP01)
#define kar_gryakulib_get_yaku_state_or_none fn_800F9214
#define kar_graudio_stop_active_fgm_slot fn_800EB8DC
#define LASERGATE_ASSERT_TARGET_COUNT_LINE 0x140
#define LASERGATE_ASSERT_GATE_KIND_LINE 0xF8
#define LASERGATE_ASSERT_AOBJ_LINE 0x81
#define LASERGATE_ASSERT_CTRL_KIND_LINE 0x1A8
#define LASERGATE_ZERO lbl_805D24A0
#define LASERGATE_ONE lbl_805D24A4
#define LASERGATE_ASSERT_AOBJ lbl_805C8CE8
#define LASERGATE_ASSERT_ZERO lbl_805C8CF0

__declspec(section ".sdata") char lbl_805C8CC0[] = "aobj";
__declspec(section ".sdata") char lbl_805C8CC8[] = "aobj";
extern char LASERGATE_ASSERT_AOBJ[];
extern char LASERGATE_ASSERT_ZERO[];
__declspec(section ".sdata2") extern const f32 LASERGATE_ZERO;
__declspec(section ".sdata2") extern const f32 LASERGATE_ONE;
#else
#define LASERGATE_ASSERT_TARGET_COUNT_LINE 0x138
#define LASERGATE_ASSERT_GATE_KIND_LINE 0xF4
#define LASERGATE_ASSERT_AOBJ_LINE 0x7D
#define LASERGATE_ASSERT_CTRL_KIND_LINE 0x198
#define LASERGATE_ZERO lbl_805DFA38
#define LASERGATE_ONE lbl_805DFA3C
#define LASERGATE_ASSERT_AOBJ lbl_805D62E8
#define LASERGATE_ASSERT_ZERO lbl_805D62F0

__declspec(section ".sdata") char LASERGATE_ASSERT_AOBJ[] = "aobj";
__declspec(section ".sdata") char LASERGATE_ASSERT_ZERO[] = "0";
__declspec(section ".sdata2") extern const f32 LASERGATE_ZERO;
__declspec(section ".sdata2") extern const f32 LASERGATE_ONE;
#endif

#define YAKU_KIND_LASERGATE 0x39
#define YAKU_KIND_LASERGATE_CTRL 0x3A
#define LASERGATE_CTRL_MAX_GOBJS 4
#define JOBJ_HIDDEN 0x10

struct GroundJObjEntry {
    HSD_JObj* jobj;
    u8 pad_04[0x04];
};

struct Ground {
    u8 pad_000[0x104];
    GroundJObjEntry* jobjs;
};

struct YakuParamLink {
    void* param;
    u8 pad_04[0x10];
    void* fgm_param;
};

struct Yaku {
    void* owner;
    s32 kind;
    YakuParamLink* param_link;
    u8 pad_0C[0x68];
    s32 state;
    u8 pad_78[0xA0];
    u8 fgm_entry[0x08];
    u8 pad_120[0x10];
};

struct LaserGateCtrlParam {
    s32* switch_ids;
    s32 switch_count;
    s32* target_gobj_ids;
    s32 target_count;
};

struct LaserGateParam {
    s32 joint_index;
    s32 hide_joint_index;
    u8 pad_08[0x08];
    void* path_nodes;
};

struct LaserGateCtrlData {
    void* ptrs[5];
    char src[0x14];
    char assert_gate_kind[0x24];
    char assert_target_count[0x4C];
    char ground_src[0x0C];
    char assert_ctrl_kind[0x28];
};

#define YAKU_PARAM(yaku, type) ((type*) ((yaku)->param_link->param))
#define YAKU_FGM_ENTRY(yaku) ((void*) ((u8*) (yaku) + 0x118))
#define YAKU_FGM_ENTRY_COUNT(yaku) (*(s32*) ((u8*) (yaku) + 0x11C))
#define YAKU_LINKED_GOBJ(yaku, index) (*(HSD_GObj**) ((u8*) (yaku) + 0x130 + (index) * 4))
#define YAKU_LASERGATE_FRAME(yaku) (*(f32*) ((u8*) (yaku) + 0x130))
#define LASERGATE_COMMON_BASE kar_gryakubreakcommon_kind57_lasergate_callback_table
#define LASERGATE_SRC(base) ((base) + 0x88)
#define LASERGATE_ASSERT_GATE_KIND(base) ((base) + 0x9C)
#define LASERGATE_ASSERT_TARGET_COUNT(base) ((base) + 0xC0)
#define LASERGATE_GROUND_SRC(base) ((base) + 0x10C)
#define LASERGATE_ASSERT_CTRL_KIND(base) ((base) + 0x118)

extern char kar_gryakubreakcommon_kind57_lasergate_callback_table[];
void kar_grswitch__near_800e86cc(void* ground, HSD_GObj* target, s32 zone_id);
void kar_gryakuaudio_configure_fgm_track_from_joint(HSD_GObj* gobj,
                                                    s32 joint_index,
                                                    s32 use_yaku_anchor);
s32 kar_gryakulib_get_yaku_state_or_none(HSD_GObj* gobj);
void kar_graudio_stop_active_fgm_slot(void* entry);
void kar_gryaku_set_path_node_motion(Yaku* yaku, s32 state, void* path_nodes,
                                     s32 joint_index, s32 arg4, f32 start,
                                     f32 end, f32 arg7);
void kar_gryakubreakfloor_init_kind32_breakfloor(HSD_GObj* gobj,
                                                 HSD_GObj* ground_gobj);

GroundCallback kar_gryakulasergate_kind58_ctrl_callback_table[] = {
    NULL,
    NULL,
    NULL,
    NULL,
    (GroundCallback) kar_gryakulasergate_update_kind58_ctrl_target_reset_to_idle,
    NULL,
    NULL,
    NULL,
};

LaserGateCtrlData kar_gryakulasergate_kind58_ctrl_callback_table_ptr = {
    {
        kar_gryakulasergate_kind58_ctrl_callback_table,
        NULL,
        NULL,
        NULL,
        NULL,
    },
    "gryakulasergate.c",
    "gyp->kind == Gr_YakuKind_LaserGate",
    "0 < param->targetNum && param->targetNum <= GrYakuLaserGateCtrl_GObjNumMax",
    "ground.h",
    "gyp->kind == Gr_YakuKind_LaserGateCtrl",
};

void kar_gryakulasergate_init_kind58_lasergate_ctrl(HSD_GObj* gobj,
                                                    HSD_GObj* ground_gobj)
{
    Yaku* yaku;
    LaserGateCtrlParam* param;
    void* ground;
    char* assert_base;
    s32 valid;
    s32 i;
    s32 offset;

    yaku = gobj->user_data;
    ground = ground_gobj->user_data;
    assert_base = LASERGATE_COMMON_BASE;
    param = YAKU_PARAM(yaku, LaserGateCtrlParam);

    for (i = 0, offset = 0; i < param->switch_count;) {
        kar_grswitch__near_800e86cc(ground, gobj,
                                    *(s32*) ((u8*) param->switch_ids + offset));
        offset += 4;
        i++;
    }

    valid = 0;
    if (param->target_count > 0) {
        if (param->target_count <= LASERGATE_CTRL_MAX_GOBJS) {
            valid = 1;
        }
    }
    if (valid == 0) {
        __assert(LASERGATE_SRC(assert_base), LASERGATE_ASSERT_TARGET_COUNT_LINE,
                 LASERGATE_ASSERT_TARGET_COUNT(assert_base));
    }

    for (i = 0, offset = 0; i < LASERGATE_CTRL_MAX_GOBJS; i++, offset += 4) {
        HSD_GObj* cursor;
        s32 index;
        s32 target_id;

        YAKU_LINKED_GOBJ(yaku, i) = NULL;
        if (i >= param->target_count) {
            continue;
        }

        target_id = *(s32*) ((u8*) param->target_gobj_ids + offset);
        cursor = hsdGObj_p_link_heads[8];
        index = 0;
        goto check_cursor;
    search_cursor:
            if (target_id == index) {
                goto found_cursor;
            }
            cursor = cursor->next;
            index++;
    check_cursor:
        if (cursor != NULL) {
            goto search_cursor;
        }
        __assert(LASERGATE_GROUND_SRC(assert_base), 0x96C, LASERGATE_ASSERT_ZERO);
        cursor = NULL;
    found_cursor:
        YAKU_LINKED_GOBJ(yaku, i) = cursor;
    }

    if (yaku->param_link->fgm_param != NULL) {
        kar_gryakuaudio_configure_fgm_track_from_joint(gobj, -1, 0);
    }

    kar_gryakulasergate_start_kind58_ctrl_idle_wait_motion(gobj);
}

void kar_gryakulasergate_start_kind58_ctrl_idle_wait_motion(HSD_GObj* gobj)
{
    Yaku* yaku = gobj->user_data;
    f32 zero;

    if (YAKU_FGM_ENTRY_COUNT(yaku) > 0) {
        kar_graudio_play_fgm_entry_id(YAKU_FGM_ENTRY(yaku), 0);
    }

    zero = LASERGATE_ZERO;
    kar_gryaku_set_path_node_motion(yaku, 0, (void*) -1, -1, 0, zero, zero,
                                    zero);
}

void kar_gryakulasergate_update_kind58_ctrl_target_reset_to_idle(HSD_GObj* gobj)
{
    Yaku* yaku;
    LaserGateCtrlParam* param;
    s32 i;

    yaku = gobj->user_data;
    param = YAKU_PARAM(yaku, LaserGateCtrlParam);
    for (i = 0; i < param->target_count; i++) {
        if (kar_gryakulib_get_yaku_state_or_none(YAKU_LINKED_GOBJ(yaku, i)) == 0) {
            kar_gryakulasergate_start_kind58_ctrl_idle_wait_motion(gobj);
        }
    }
}

void kar_gryakulasergate_trigger_kind58_ctrl_open_linked_gates(void* target)
{
    HSD_GObj* gobj;
    Yaku* yaku;
    LaserGateCtrlParam* param;
    char* assert_base;
    s32 i;

    gobj = target;
    yaku = gobj->user_data;
    assert_base = LASERGATE_COMMON_BASE;
    if (yaku->kind != YAKU_KIND_LASERGATE_CTRL) {
        __assert(LASERGATE_SRC(assert_base), LASERGATE_ASSERT_CTRL_KIND_LINE,
                 LASERGATE_ASSERT_CTRL_KIND(assert_base));
    }

    param = YAKU_PARAM(yaku, LaserGateCtrlParam);
    for (i = 0; i < param->target_count; i++) {
        HSD_GObj* gate_gobj;
        Yaku* gate_yaku;

        gate_gobj = YAKU_LINKED_GOBJ(yaku, i);
        gate_yaku = gate_gobj->user_data;
        if (gate_yaku->kind != YAKU_KIND_LASERGATE) {
            __assert(LASERGATE_SRC(assert_base), LASERGATE_ASSERT_GATE_KIND_LINE,
                     LASERGATE_ASSERT_GATE_KIND(assert_base));
        }

        if (gate_yaku->state == 0) {
            Ground* ground;
            LaserGateParam* gate_param;
            HSD_JObj* jobj;
            HSD_AObj* aobj;
            f32 zero;

            gate_yaku = gate_gobj->user_data;
            ground = kar_gryaku_current_ground;
            gate_param = YAKU_PARAM(gate_yaku, LaserGateParam);
            jobj = ground->jobjs[gate_param->joint_index].jobj;
            aobj = jobj->aobj;
            if (aobj == NULL) {
                __assert(LASERGATE_SRC(assert_base), LASERGATE_ASSERT_AOBJ_LINE,
                         LASERGATE_ASSERT_AOBJ);
            }

            YAKU_LASERGATE_FRAME(gate_yaku) = aobj->curr_frame;
            HSD_JObjSetFlags(ground->jobjs[gate_param->hide_joint_index].jobj,
                             JOBJ_HIDDEN);
            zero = LASERGATE_ZERO;
            kar_gryaku_set_path_node_motion(gate_yaku, 1, gate_param->path_nodes,
                                            gate_param->joint_index, 0, zero,
                                            LASERGATE_ONE, zero);
        }
    }

    yaku = gobj->user_data;
    if (YAKU_FGM_ENTRY_COUNT(yaku) > 0) {
        kar_graudio_stop_active_fgm_slot(YAKU_FGM_ENTRY(yaku));
    }

    {
        f32 zero = LASERGATE_ZERO;
        kar_gryaku_set_path_node_motion(yaku, 1, (void*) -1, -1, 0, zero, zero,
                                        zero);
    }
}

s32 kar_gryakulasergate_test_kind58_ctrl_has_idle_gate_target(HSD_GObj* gobj)
{
    Yaku* yaku;
    LaserGateCtrlParam* param;
    s32 i;
    s32 valid;

    yaku = gobj->user_data;
    param = YAKU_PARAM(yaku, LaserGateCtrlParam);
    for (i = 0; i < param->target_count; i++) {
        Yaku* gate_yaku = YAKU_LINKED_GOBJ(yaku, i)->user_data;

        switch (gate_yaku->state) {
        case 0:
            valid = 1;
            break;
        default:
            valid = 0;
            break;
        }
        if (valid != 0) {
            return 1;
        }
    }

    return 0;
}

void kar_gryakulasergate_create_stage_linked_kind32_breakfloor(struct Ground* ground,
                                                               s32 link)
{
    HSD_GObj* gobj = kar_gryaku_create_yaku_from_main_kind(0x20);
    kar_gryakubreakfloor_init_kind32_breakfloor(gobj, (HSD_GObj*) ground);
}
