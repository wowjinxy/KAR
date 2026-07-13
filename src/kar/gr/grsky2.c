#include "functions.h"
#include <kar/gr/granim.h>
#include <kar/gr/gryaku.h>
#include <sysdolphin/gobj.h>

typedef struct Ground Ground;
typedef struct GroundData GroundData;
typedef struct GroundIndiviParam GroundIndiviParam;
typedef void (*GroundCallback)(void);

struct Ground {
    u8 pad_0[0x08];
    GroundData* data;
};

struct GroundData {
    u8 pad_0[0x08];
    GroundIndiviParam* indiviParam;
};

struct GroundIndiviParam {
    void* loopAnimAll;
};

void kar_gryakudownforcezone_create_stage_linked_kind17_yaku(Ground* ground, s32 link);

void kar_grsky2_init_loop_anim(HSD_GObj* gobj);
void kar_grsky2_create_stage_downforce_gondola_yaku(Ground* ground);

GroundCallback kar_grsky2_callback_table[] = {
    (GroundCallback) kar_grsky2_init_loop_anim,
    (GroundCallback) kar_grsky2_create_stage_downforce_gondola_yaku,
    NULL,
};

void kar_grsky2_init_loop_anim(HSD_GObj* gobj)
{
    Ground* ground = gobj->user_data;
    GroundIndiviParam* indiviParam = ground->data->indiviParam;
    BOOL hasLoopAnim = FALSE;

    if (indiviParam != NULL && indiviParam->loopAnimAll != NULL) {
        hasLoopAnim = TRUE;
    }

    if (!hasLoopAnim) {
        __assert("grsky2.c", 40, "indiviParam && indiviParam->loopAnimAll");
    }

    kar_granim__800dbe48(ground, indiviParam->loopAnimAll);
}

void kar_grsky2_create_stage_downforce_gondola_yaku(Ground* ground)
{
    kar_gryakudownforcezone_create_stage_linked_kind17_yaku(ground, 0);
    kar_gryakucatchzone_create_stage_linked_kind18_yaku(ground, 1);
    kar_gryakugondola_create_stage_linked_kind46_carrier_yaku(ground, 2);
    kar_gryakugondola_create_stage_linked_kind46_carrier_yaku(ground, 3);
    kar_gryakugondola_create_stage_linked_kind46_carrier_yaku(ground, 4);
    kar_gryakugondola_create_stage_linked_kind46_carrier_yaku(ground, 5);
    kar_gryakugondola_create_stage_linked_kind46_carrier_yaku(ground, 6);
    kar_gryakugondola_create_stage_linked_kind46_carrier_yaku(ground, 7);
    kar_gryakugondola_create_stage_linked_kind46_carrier_yaku(ground, 8);
    kar_gryakugondola_create_stage_linked_kind46_carrier_yaku(ground, 9);
    kar_gryakugondola_create_stage_linked_kind47_ground_audio_yaku(ground, 10);
    kar_gryakuanimfloor_create_stage_linked_kind55_reactive_floor(ground, 11);
}
