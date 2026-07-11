#include "functions.h"
#include <kar/gr/granim.h>
#include <kar/gr/graudio.h>
#include <sysdolphin/gobj.h>

#define GRMACHINE2_FGM_COUNTER_NUM 10
#ifdef VERSION_GKYP01
#define GRMACHINE2_ASSERT_LOOP_ANIM_LINE 47
#define GRMACHINE2_ASSERT_FGM_COUNT_LINE 53
#else
#define GRMACHINE2_ASSERT_LOOP_ANIM_LINE 43
#define GRMACHINE2_ASSERT_FGM_COUNT_LINE 49
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
    s32 fgm_counters[GRMACHINE2_FGM_COUNTER_NUM];
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
};

void kar_gryakudownforcezone_create_stage_linked_kind17_yaku(Ground* ground,
                                                             s32 link);
void kar_gryakugondola_create_stage_linked_kind48_route_yaku(Ground* ground,
                                                             s32 link);
void kar_gryakuanimfloor_create_stage_linked_kind55_reactive_floor(Ground* ground,
                                                                   s32 link);
void kar_gryakubreakcommon_create_stage_linked_kind56_delayed_collision(Ground* ground,
                                                                        s32 link);
void kar_gryakubreakfloor_create_stage_linked_kind30_breakfan(Ground* ground,
                                                              s32 link);

void kar_grmachine2_init_loop_anim_and_individual_fgm_ids(HSD_GObj* gobj);
void kar_grmachine2_create_stage_mechanism_yaku_objects(Ground* ground);
void kar_grmachine2_update_individual_fgm_timers(HSD_GObj* gobj);
void kar_grmachine2_empty_callback(void);

GroundCallback kar_grmachine2_callback_table[] = {
    (GroundCallback) kar_grmachine2_init_loop_anim_and_individual_fgm_ids,
    (GroundCallback) kar_grmachine2_create_stage_mechanism_yaku_objects,
    (GroundCallback) kar_grmachine2_update_individual_fgm_timers,
};

void kar_grmachine2_init_loop_anim_and_individual_fgm_ids(HSD_GObj* gobj)
{
    Ground* ground = gobj->user_data;
    GroundIndiviParam* indiviParam = ground->data->indiviParam;
    BOOL hasLoopAnim = FALSE;
    s32 i;

    if (indiviParam != NULL && indiviParam->loopAnimAll != NULL) {
        hasLoopAnim = TRUE;
    }

    if (!hasLoopAnim) {
        __assert("grmachine2.c", GRMACHINE2_ASSERT_LOOP_ANIM_LINE,
                 "indiviParam && indiviParam->loopAnimAll");
    }

    kar_granim__800dbe48(ground, indiviParam->loopAnimAll);

    if (indiviParam->indiviFgmAll->indiviFgmNum > GRMACHINE2_FGM_COUNTER_NUM) {
        __assert("grmachine2.c", GRMACHINE2_ASSERT_FGM_COUNT_LINE,
                 "indiviParam->indiviFgmAll->indiviFgmNum <= GrMachine2_FgmCounterNum");
    }

    for (i = 0; i < indiviParam->indiviFgmAll->indiviFgmNum; i++) {
        ground->fgm_counters[i] = indiviParam->indiviFgmAll->params[i].initial_counter;
    }
}

void kar_grmachine2_create_stage_mechanism_yaku_objects(Ground* ground)
{
    kar_gryakudownforcezone_create_stage_linked_kind17_yaku(ground, 0);
    kar_gryakugondola_create_stage_linked_kind48_route_yaku(ground, 1);
    kar_gryakuanimfloor_create_stage_linked_kind55_reactive_floor(ground, 2);
    kar_gryakuanimfloor_create_stage_linked_kind55_reactive_floor(ground, 3);
    kar_gryakuanimfloor_create_stage_linked_kind55_reactive_floor(ground, 4);
    kar_gryakubreakcommon_create_stage_linked_kind56_delayed_collision(ground, 5);
    kar_gryakubreakcommon_create_stage_linked_kind56_delayed_collision(ground, 6);
    kar_gryakubreakcommon_create_stage_linked_kind56_delayed_collision(ground, 7);
    kar_gryakubreakcommon_create_stage_linked_kind56_delayed_collision(ground, 8);
    kar_gryakubreakcommon_create_stage_linked_kind56_delayed_collision(ground, 9);
    kar_gryakubreakfloor_create_stage_linked_kind30_breakfan(ground, 10);
    kar_gryakubreakfloor_create_stage_linked_kind30_breakfan(ground, 11);
    kar_gryakubreakfloor_create_stage_linked_kind30_breakfan(ground, 12);
    kar_gryakubreakfloor_create_stage_linked_kind30_breakfan(ground, 13);
    kar_gryakubreakfloor_create_stage_linked_kind30_breakfan(ground, 14);
    kar_gryakubreakfloor_create_stage_linked_kind30_breakfan(ground, 15);
    kar_gryakubreakfloor_create_stage_linked_kind30_breakfan(ground, 16);
    kar_gryakubreakfloor_create_stage_linked_kind30_breakfan(ground, 17);
    kar_gryakubreakfloor_create_stage_linked_kind30_breakfan(ground, 18);
    kar_gryakubreakfloor_create_stage_linked_kind30_breakfan(ground, 19);
    kar_gryakubreakfloor_create_stage_linked_kind30_breakfan(ground, 20);
    kar_gryakubreakfloor_create_stage_linked_kind30_breakfan(ground, 21);
    kar_gryakubreakfloor_create_stage_linked_kind30_breakfan(ground, 22);
    kar_gryakubreakfloor_create_stage_linked_kind30_breakfan(ground, 23);
    kar_gryakubreakfloor_create_stage_linked_kind30_breakfan(ground, 24);
    kar_gryakubreakfloor_create_stage_linked_kind30_breakfan(ground, 25);
    kar_gryakubreakfloor_create_stage_linked_kind30_breakfan(ground, 26);
    kar_gryakubreakfloor_create_stage_linked_kind30_breakfan(ground, 27);
}

void kar_grmachine2_update_individual_fgm_timers(HSD_GObj* gobj)
{
    Ground* ground = gobj->user_data;
    GroundIndiviParam* indiviParam = ground->data->indiviParam;

    kar_graudio_configure_individual_fgm_tracks(ground, indiviParam->indiviFgmAll);
    kar_graudio_update_individual_fgm_timers(ground, indiviParam->indiviFgmAll,
                                             ground->fgm_counters,
                                             GRMACHINE2_FGM_COUNTER_NUM);
}

void kar_grmachine2_empty_callback(void)
{
}

GroundCallback kar_grmachine2_empty_callback_table[] = {
    kar_grmachine2_empty_callback,
    NULL,
    NULL,
    NULL,
};
