#include "functions.h"
#include <kar/gr/gryaku.h>
#include <sysdolphin/gobj.h>

#define GRVALLEY2_FGM_COUNTER_NUM 10
#ifdef VERSION_GKYP01
#define GRVALLEY2_ASSERT_LOOP_ANIM_LINE 45
#define GRVALLEY2_ASSERT_FGM_COUNT_LINE 51
#else
#define GRVALLEY2_ASSERT_LOOP_ANIM_LINE 41
#define GRVALLEY2_ASSERT_FGM_COUNT_LINE 47
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
    s32 fgm_counters[GRVALLEY2_FGM_COUNTER_NUM];
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
void kar_graudio_update_individual_fgm_timers(Ground* ground, IndividualFgmAll* indiviFgmAll, s32* counters, s32 counter_num);
void kar_grcommon__800db654(Ground* ground, void* bitCounterIdAll, s32 id);
void kar_gryakucommon_create_stage_linked_kind16_yaku(Ground* ground, s32 link);
void kar_gryakubreakcoral_create_stage_linked_kind28_breakcoral(Ground* ground, s32 link);

void kar_grvalley2_init_loop_anim_and_individual_fgm_ids(HSD_GObj* gobj);
void kar_grvalley2_create_stage_common_and_breakcoral_yaku(Ground* ground);
void kar_grvalley2_update_individual_fgm_timers(HSD_GObj* gobj);

GroundCallback kar_grvalley2_callback_table[] = {
    (GroundCallback) kar_grvalley2_init_loop_anim_and_individual_fgm_ids,
    (GroundCallback) kar_grvalley2_create_stage_common_and_breakcoral_yaku,
    (GroundCallback) kar_grvalley2_update_individual_fgm_timers,
};

void kar_grvalley2_init_loop_anim_and_individual_fgm_ids(HSD_GObj* gobj)
{
    Ground* ground = gobj->user_data;
    GroundIndiviParam* indiviParam = ground->data->indiviParam;
    BOOL hasLoopAnim = FALSE;
    s32 i;

    if (indiviParam != NULL && indiviParam->loopAnimAll != NULL) {
        hasLoopAnim = TRUE;
    }

    if (!hasLoopAnim) {
        __assert("grvalley2.c", GRVALLEY2_ASSERT_LOOP_ANIM_LINE,
                 "indiviParam && indiviParam->loopAnimAll");
    }

    kar_granim__800dbe48(ground, indiviParam->loopAnimAll);

    if (indiviParam->indiviFgmAll->indiviFgmNum > GRVALLEY2_FGM_COUNTER_NUM) {
        __assert("grvalley2.c", GRVALLEY2_ASSERT_FGM_COUNT_LINE,
                 "indiviParam->indiviFgmAll->indiviFgmNum <= GrValley2_FgmCounterNum");
    }

    for (i = 0; i < indiviParam->indiviFgmAll->indiviFgmNum; i++) {
        ground->fgm_counters[i] = indiviParam->indiviFgmAll->params[i].initial_counter;
    }
}

void kar_grvalley2_create_stage_common_and_breakcoral_yaku(Ground* ground)
{
    kar_gryakucommon_create_stage_linked_kind16_yaku(ground, 0);
    kar_gryakucommon_create_stage_linked_kind16_yaku(ground, 1);
    kar_gryakubreakcoral_create_stage_linked_kind28_breakcoral(ground, 2);
    kar_gryakubreakcoral_create_stage_linked_kind28_breakcoral(ground, 3);
}

void kar_grvalley2_update_individual_fgm_timers(HSD_GObj* gobj)
{
    Ground* ground = gobj->user_data;
    GroundIndiviParam* indiviParam = ground->data->indiviParam;

    kar_graudio_configure_individual_fgm_tracks(ground, indiviParam->indiviFgmAll);
    kar_graudio_update_individual_fgm_timers(ground, indiviParam->indiviFgmAll,
                                             ground->fgm_counters, GRVALLEY2_FGM_COUNTER_NUM);
}

void kar_grvalley2_start_bit_counter_id0_duration100(void)
{
    Ground* ground = kar_gryaku_current_ground;
    kar_grcommon__800db654(ground, ground->data->indiviParam->bitCounterIdAll, 0);
}
