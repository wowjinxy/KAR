#include "functions.h"
#include <kar/gr/gryaku.h>
#include <sysdolphin/gobj.h>

#define GRHEAT2_FGM_COUNTER_NUM 10

#ifdef VERSION_GKYP01
#define GRHEAT2_ASSERT_LOOP_ANIM_LINE 46
#define GRHEAT2_ASSERT_FGM_COUNT_LINE 52
#else
#define GRHEAT2_ASSERT_LOOP_ANIM_LINE 42
#define GRHEAT2_ASSERT_FGM_COUNT_LINE 48
#endif

typedef struct Ground Ground;
typedef struct GroundData GroundData;
typedef struct GroundIndiviParam GroundIndiviParam;
typedef struct IndividualFgmAll IndividualFgmAll;
typedef struct IndividualFgmParam IndividualFgmParam;
typedef void (*GroundCallback)(void);

struct Ground {
    u8 pad_0[0x08];
    GroundData* data;
    u8 pad_C[0x71C];
    s32 fgm_counters[GRHEAT2_FGM_COUNTER_NUM];
};

struct GroundData {
    u8 pad_0[0x08];
    GroundIndiviParam* indiviParam;
};

struct IndividualFgmParam {
    u8 pad_0[0x08];
    s32 initial_counter;
    u8 pad_C[0x04];
};

struct IndividualFgmAll {
    IndividualFgmParam* params;
    s32 indiviFgmNum;
};

struct GroundIndiviParam {
    void* loopAnimAll;
    IndividualFgmAll* indiviFgmAll;
    void* bitCounterIdAll;
};

void kar_granim__800dbe48(Ground* ground, void* loopAnimAll);
void kar_graudio_configure_individual_fgm_tracks(Ground* ground, IndividualFgmAll* indiviFgmAll);
void kar_graudio_update_individual_fgm_timers(Ground* ground, IndividualFgmAll* indiviFgmAll,
                                              s32* counters, s32 counter_num);
void kar_grcommon__800db5d4(Ground* ground, void* bitCounterIdAll, s32 id);
void kar_grcommon__800db654(Ground* ground, void* bitCounterIdAll, s32 id);
void kar_gryakucatchzone_create_stage_linked_kind19_yaku(Ground* ground, s32 link);
void kar_gryakubreakhouse_create_stage_linked_kind54_animfloor(Ground* ground, s32 link);
void kar_gryakubreakhpcoll_create_stage_linked_kind61_timed_anim_audio_cycle(Ground* ground,
                                                                             s32 link);

void kar_grheat2_init_loop_anim_and_individual_fgm_ids(HSD_GObj* gobj);
void kar_grheat2_create_stage_yaku_objects(Ground* ground);
void kar_grheat2_update_individual_fgm_timers(HSD_GObj* gobj);

GroundCallback kar_grheat2_callback_table[] = {
    (GroundCallback) kar_grheat2_init_loop_anim_and_individual_fgm_ids,
    (GroundCallback) kar_grheat2_create_stage_yaku_objects,
    (GroundCallback) kar_grheat2_update_individual_fgm_timers,
};

void kar_grheat2_init_loop_anim_and_individual_fgm_ids(HSD_GObj* gobj)
{
    Ground* ground = gobj->user_data;
    GroundIndiviParam* indiviParam = ground->data->indiviParam;
    BOOL hasLoopAnim = FALSE;
    s32 i;

    if (indiviParam != NULL && indiviParam->loopAnimAll != NULL) {
        hasLoopAnim = TRUE;
    }

    if (!hasLoopAnim) {
        __assert("grheat2.c", GRHEAT2_ASSERT_LOOP_ANIM_LINE,
                 "indiviParam && indiviParam->loopAnimAll");
    }

    kar_granim__800dbe48(ground, indiviParam->loopAnimAll);

    if (indiviParam->indiviFgmAll->indiviFgmNum > GRHEAT2_FGM_COUNTER_NUM) {
        __assert("grheat2.c", GRHEAT2_ASSERT_FGM_COUNT_LINE,
                 "indiviParam->indiviFgmAll->indiviFgmNum <= GrHeat2_FgmCounterNum");
    }

    for (i = 0; i < indiviParam->indiviFgmAll->indiviFgmNum; i++) {
        ground->fgm_counters[i] = indiviParam->indiviFgmAll->params[i].initial_counter;
    }
}

void kar_grheat2_create_stage_yaku_objects(Ground* ground)
{
    kar_gryakucatchzone_create_stage_linked_kind19_yaku(ground, 0);
    kar_gryakubreakhouse_create_stage_linked_kind54_animfloor(ground, 1);
    kar_gryakubreakhpcoll_create_stage_linked_kind61_timed_anim_audio_cycle(ground, 2);
    kar_gryakubreakhpcoll_create_stage_linked_kind61_timed_anim_audio_cycle(ground, 3);
    kar_gryakubreakhpcoll_create_stage_linked_kind61_timed_anim_audio_cycle(ground, 4);
}

void kar_grheat2_update_individual_fgm_timers(HSD_GObj* gobj)
{
    Ground* ground = gobj->user_data;
    GroundIndiviParam* indiviParam = ground->data->indiviParam;

    kar_graudio_configure_individual_fgm_tracks(ground, indiviParam->indiviFgmAll);
    kar_graudio_update_individual_fgm_timers(ground, indiviParam->indiviFgmAll,
                                             ground->fgm_counters, GRHEAT2_FGM_COUNTER_NUM);
}

void kar_grheat2_start_bit_counter_id0_duration500(void)
{
    Ground* ground = kar_gryaku_current_ground;
    kar_grcommon__800db5d4(ground, ground->data->indiviParam->bitCounterIdAll, 0);
}

void kar_grheat2_start_bit_counter_id1_duration100(void)
{
    Ground* ground = kar_gryaku_current_ground;
    kar_grcommon__800db654(ground, ground->data->indiviParam->bitCounterIdAll, 1);
}
