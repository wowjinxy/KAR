#include "functions.h"
#include <dolphin/mtx/vec.h>
#include <dolphin/types.h>
#include <kar/em/emanim.h>
#include <kar/lb/lbairride.h>
#include <kar/lb/lbvector.h>
#include <sysdolphin/dobj.h>
#include <sysdolphin/gobj.h>
#include <sysdolphin/jobj.h>
#include <sysdolphin/mobj.h>
#include <sysdolphin/objalloc.h>

#if defined(VERSION_GKYJ01)
#define kar_emanim__near_801ff2bc fn_801FB5AC
#define kar_emanim__near_801ff520 fn_801FB810
#define kar_emanim__near_801ff698 fn_801FB988
#define kar_emanim__near_801ff72c fn_801FBA1C
#define kar_emanim__near_801ff754 fn_801FBA44
#define kar_emanim__near_801ff7b0 fn_801FBAA0
#define kar_emanim__near_801ff80c fn_801FBAFC
#define kar_emanim__near_801ff864 fn_801FBB54
#define kar_emanim__near_801ff884 fn_801FBB74
#define kar_emanim__near_801ff8b4 fn_801FBBA4
#define kar_emanim__near_801ff8d8 fn_801FBBC8
#define kar_emanim__near_801ffccc fn_801FBFBC
#define kar_emanim__near_801ffce4 fn_801FBFD4
#define kar_emanim__near_801ffd78 fn_801FC068
#define kar_emanim__near_801fff84 fn_801FC274
#define kar_emanim__near_801fffa4 fn_801FC294
#define kar_emanim__near_80200004 fn_801FC2F4
#define kar_emanim__near_802000ac fn_801FC39C
#define kar_emanim__near_802000c0 fn_801FC3B0
#define kar_emanim__near_802000d4 fn_801FC3C4
#define kar_emanim__near_8020012c fn_801FC41C
#define kar_emanim__near_80200180 fn_801FC470
#define kar_emanim__near_802001bc fn_801FC4AC
#define kar_emanim__near_80200208 fn_801FC4F8
#define kar_emanim__near_802005e0 fn_801FC8D0
#define kar_emanim__near_80200604 fn_801FC8F4
#define kar_emanim__near_80200638 fn_801FC928
#define kar_emanim__near_8020067c fn_801FC94C
#define kar_emanim__near_802006b4 fn_801FC984
#define kar_emanim__near_8020072c fn_801FC9FC
#define kar_emanim__near_802007e0 fn_801FCAB0
#define kar_emanim__80200838 fn_801FCB08
#define kar_emanim__near_80200ba4 fn_801FCE74
#define kar_emanim__near_80200bd8 fn_801FCEA8
#define kar_emanim__near_80200c04 fn_801FCED4
#define kar_emanim__near_80200d10 fn_801FCFE0
#define kar_emanim__near_80200df4 fn_801FD0C4
#define fn_80200E58 fn_801FD128
#define kar_emanim__near_80201138 fn_801FD408
#define kar_emanim__near_80201180 fn_801FD450
#define kar_emanim__near_80201418 fn_801FD6E8
#define kar_emanim__near_80201498 fn_801FD768
#define kar_emanim__near_8020152c fn_801FD7FC
#define kar_emanim__near_8020174c fn_801FDA1C
#define kar_emanim__near_80201798 fn_801FDA68
#define kar_emanim__near_802017d0 fn_801FDB44
#define kar_emanim__near_802018ec fn_801FDBBC
#define kar_emanim__near_80201904 fn_801FDBD4
#define kar_emanim__near_80201928 fn_801FDBF8
#define kar_emanim__near_80201948 fn_801FDC18
#define kar_emanim__near_80201968 fn_801FDC38
#define kar_emanim__near_802019a0 fn_801FDC70
#define kar_emanim__near_802019fc fn_801FDCCC
#define kar_emanim__near_80201a34 fn_801FDD04
#define kar_emanim__near_80201ad0 fn_801FDDA0
#define kar_emanim__near_80201af4 fn_801FDDC4
#define kar_emanim__near_80201b18 fn_801FDDE8
#define kar_emanim__near_80201b3c fn_801FDE0C
#define kar_emanim__near_80201b6c fn_801FDE38
#define kar_emanim__near_80201ba4 fn_801FDE70
#define kar_emanim__near_80201e18 fn_801FE0E4
#define kar_emanim__near_80201e48 fn_801FE114
#define kar_emanim__near_80201ee8 fn_801FE1B4
#define kar_emanim__near_80201fe8 fn_801FE2B4
#define kar_emanim__near_8020200c fn_801FE2D8
#define kar_emanim__near_80202070 fn_801FE33C
#define kar_emanim__near_802020d4 fn_801FE3A0
#define kar_emanim__near_80202130 fn_801FE3FC
#define kar_emanim__near_80202198 fn_801FE464
#define kar_emanim__near_802025dc fn_801FE8A8
#define kar_emanim__near_80202634 fn_801FE900
#define kar_emanim__near_8020267c fn_801FE948
#define fn_80201488 fn_801FD758
#define fn_80201504 fn_801FD7D4
#define fn_802016AC fn_801FD97C
#define fn_8020172C fn_801FD9FC
#define kar_emparts__802026d4 fn_801FE9A0
#define kar_emparts__80202a40 fn_801FED0C
#define kar_emupdate__near_8020429c fn_80200568
#define kar_emupdate__near_802042fc fn_802005C8
#define fn_801FBA38 fn_801F7D7C
#define fn_801FC398 fn_801F8700
#define fn_801FEE30 fn_801FB2F4
#define fn_80009208 fn_80009180
#define fn_80192110 fn_8018E084
#define fn_80192174 fn_8018E0E8
#define kar_lbkdcoll__near_80072664 fn_80071D78
#define kar_grairglider_is_position_outside_checker_forward_cones fn_800F2C04
#define lbl_804B1D98 lbl_804ACAE0
#define lbl_804B2558 lbl_804AD2A0
#define lbl_804B2768 lbl_804AD4B0
#define lbl_8055A15C lbl_80554C34
#define lbl_8055A188 lbl_80554C60
#define lbl_8055A1B4 lbl_80554C8C
#define lbl_8055A1E0 lbl_80554CB8
#define lbl_805E2260 lbl_805DCB00
#define lbl_805E2264 lbl_805DCB04
#define lbl_805E2268 lbl_805DCB08
#define lbl_805E226C lbl_805DCB0C
#define lbl_805E2248 lbl_805DCAE8
#define lbl_805E2288 lbl_805DCB28
#define lbl_805E22B4 lbl_805DCB54
#define kar_lbcamera__near_80068d68 fn_80068490
#define kar_lbcamera__near_8006a250 fn_80069978
#define kar_lbcamera__near_8006a3f0 fn_80069B18
#define kar_lbcolanim__near_8006ad20 fn_8006A448
#define kar_lbcolanim__near_8006ada4 fn_8006A4CC
#define kar_lbcolanim__near_8006ade0 fn_8006A508
#define kar_lbcolanim__near_8006ae7c fn_8006A5A4
#define kar_collision_update_motion_desc_from_model fn_80186A84
#define kar_collision_object_set_segment_desc fn_80188E94
#define kar_collision_object_free_handle fn_80188BE0
#define kar_collision_object_disable_motion_slot fn_801890F4
#define kar_collision_object_flush_dirty_motion_slots fn_80189120
#define kar_collision_object_update_motion_slot fn_801891C0
#define kar_collision_object_set_system_enabled fn_80189880
#define kar_clobject__near_8018d284 fn_80189B80
#define fn_80192788 fn_8018F058
#define fn_801C8660 fn_801C4D20
#define lbl_805DD880 lbl_805D82D8
#define kar_lbcamera__near_80069f74 fn_8006969C
#define kar_gryakulib_get_clobject_handle fn_800F7054
#define kar_emupdate__near_80204878 fn_80200B44
#define kar_emupdate__near_802049fc fn_80200CC8
#define fn_8020D30C fn_8020951C
#define fn_8020D6C0 fn_802098D0
#define kar_wneffect__near_80223120 fn_8021F250
#define kar_plclearcheckerlib__near_8022d1c0 fn_80229154
#define kar_plclearcheckerlib__near_8022d758 fn_802296EC
#define kar_mpcoll_create_volume_gobj fn_80276378
#define kar_mpcoll_destroy_volume_gobj fn_80276464
#define kar_mpcoll_show_volume_gobj fn_80276484
#define kar_mpcoll_hide_volume_gobj fn_80276494
#define kar_mpcoll_enable_volume_point_test fn_80276540
#define kar_mpcoll_disable_volume_point_test fn_80276550
#elif defined(VERSION_GKYP01)
#define kar_emanim__near_801ff2bc fn_801FFF90
#define kar_emanim__near_801ff520 fn_802001F4
#define kar_emanim__near_801ff698 fn_8020036C
#define kar_emanim__near_801ff72c fn_80200400
#define kar_emanim__near_801ff754 fn_80200428
#define kar_emanim__near_801ff7b0 fn_80200484
#define kar_emanim__near_801ff80c fn_802004E0
#define kar_emanim__near_801ff864 fn_80200538
#define kar_emanim__near_801ff884 fn_80200558
#define kar_emanim__near_801ff8b4 fn_80200588
#define kar_emanim__near_801ff8d8 fn_802005AC
#define kar_emanim__near_801ffccc fn_802009A0
#define kar_emanim__near_801ffce4 fn_802009B8
#define kar_emanim__near_801ffd78 fn_80200A4C
#define kar_emanim__near_801fff84 fn_80200C58
#define kar_emanim__near_801fffa4 fn_80200C78
#define kar_emanim__near_80200004 fn_80200CD8
#define kar_emanim__near_802000ac fn_80200D80
#define kar_emanim__near_802000c0 fn_80200D94
#define kar_emanim__near_802000d4 fn_80200DA8
#define kar_emanim__near_8020012c fn_80200E00
#define kar_emanim__near_80200180 fn_80200E54
#define kar_emanim__near_802001bc fn_80200E90
#define kar_emanim__near_80200208 fn_80200EDC
#define kar_emanim__near_802005e0 fn_802012B4
#define kar_emanim__near_80200604 fn_802012D8
#define kar_emanim__near_80200638 fn_8020130C
#define kar_emanim__near_8020065c fn_80201330
#define kar_emanim__near_8020067c fn_80201350
#define kar_emanim__near_802006b4 fn_80201388
#define kar_emanim__near_8020072c fn_80201400
#define kar_emanim__near_802007e0 fn_802014B4
#define kar_emanim__80200838 fn_8020150C
#define kar_emanim__near_80200ba4 fn_80201878
#define kar_emanim__near_80200bd8 fn_802018AC
#define kar_emanim__near_80200c04 fn_802018D8
#define kar_emanim__near_80200d10 fn_802019E4
#define kar_emanim__near_80200df4 fn_80201AC8
#define fn_80200E58 fn_80201B2C
#define kar_emanim__near_80201138 fn_80201E0C
#define kar_emanim__near_80201180 fn_80201E54
#define kar_emanim__near_80201418 fn_802020EC
#define kar_emanim__near_80201498 fn_8020216C
#define kar_emanim__near_8020152c fn_80202200
#define kar_emanim__near_8020174c fn_80202420
#define kar_emanim__near_80201798 fn_8020246C
#define kar_emanim__near_802017d0 fn_80202418
#define kar_emanim__near_802018ec fn_802025C0
#define kar_emanim__near_80201904 fn_802025D8
#define kar_emanim__near_80201928 fn_802025FC
#define kar_emanim__near_80201948 fn_8020261C
#define kar_emanim__near_80201968 fn_8020263C
#define kar_emanim__near_802019a0 fn_80202674
#define kar_emanim__near_802019fc fn_802026D0
#define kar_emanim__near_80201a34 fn_80202708
#define kar_emanim__near_80201ad0 fn_802027A4
#define kar_emanim__near_80201af4 fn_802027C8
#define kar_emanim__near_80201b18 fn_802027EC
#define kar_emanim__near_80201b3c fn_80202810
#define kar_emanim__near_80201b6c fn_80202840
#define kar_emanim__near_80201ba4 fn_80202878
#define kar_emanim__near_80201e18 fn_80202AEC
#define kar_emanim__near_80201e48 fn_80202B1C
#define kar_emanim__near_80201ee8 fn_80202BBC
#define kar_emanim__near_80201fe8 fn_80202CBC
#define kar_emanim__near_8020200c fn_80202CE0
#define kar_emanim__near_80202070 fn_80202D44
#define kar_emanim__near_802020d4 fn_80202DA8
#define kar_emanim__near_80202130 fn_80202E04
#define kar_emanim__near_80202198 fn_80202E6C
#define kar_emanim__near_802025dc fn_802032B0
#define kar_emanim__near_80202634 fn_80203308
#define kar_emanim__near_8020267c fn_80203350
#define fn_80201488 fn_8020215C
#define fn_80201504 fn_802021D8
#define fn_802016AC fn_80202380
#define fn_8020172C fn_80202400
#define kar_emparts__802026d4 fn_802033A8
#define kar_emparts__80202a40 fn_80203714
#define kar_emupdate__near_8020429c fn_80204EF0
#define kar_emupdate__near_802042fc fn_80204F50
#define fn_801FBA38 fn_801FC760
#define fn_801FC398 fn_801FD0EC
#define fn_801FEE30 fn_801FFCD8
#define fn_80009208 fn_80009390
#define fn_80192110 fn_80196948
#define fn_80192174 fn_801969AC
#define kar_lbkdcoll__near_80072664 fn_80072FA4
#define kar_grairglider_is_position_outside_checker_forward_cones fn_800F5554
#define lbl_804B1D98 lbl_804B7588
#define lbl_804B2558 lbl_804B7D48
#define lbl_804B2768 lbl_804B7F58
#define lbl_8055A15C lbl_8054CACC
#define lbl_8055A188 lbl_8054CAF8
#define lbl_8055A1B4 lbl_8054CB24
#define lbl_8055A1E0 lbl_8054CB50
#define lbl_805E2260 lbl_805D4CF8
#define lbl_805E2264 lbl_805D4CFC
#define lbl_805E2268 lbl_805D4D00
#define lbl_805E226C lbl_805D4D04
#define lbl_805E2248 lbl_805D4CE0
#define lbl_805E2288 lbl_805D4D20
#define lbl_805E22B4 lbl_805D4D4C
#define kar_lbcamera__near_80068d68 fn_800696A8
#define kar_lbcamera__near_8006a250 fn_8006AB90
#define kar_lbcamera__near_8006a3f0 fn_8006AD30
#define kar_lbcolanim__near_8006ad20 fn_8006B660
#define kar_lbcolanim__near_8006ada4 fn_8006B6E4
#define kar_lbcolanim__near_8006ade0 fn_8006B720
#define kar_lbcolanim__near_8006ae7c fn_8006B7BC
#define kar_collision_update_motion_desc_from_model fn_8018AEF0
#define kar_collision_object_set_segment_desc fn_8018D300
#define kar_collision_object_free_handle fn_8018D04C
#define kar_collision_object_disable_motion_slot fn_8018D560
#define kar_collision_object_flush_dirty_motion_slots fn_8018D58C
#define kar_collision_object_update_motion_slot fn_8018D62C
#define kar_collision_object_set_system_enabled fn_8018DCEC
#define kar_clobject__near_8018d284 fn_8018DFEC
#define fn_80192788 fn_801934F0
#define fn_801C8660 fn_801C933C
#define lbl_805DD880 lbl_805D02C8
#define kar_lbcamera__near_80069f74 fn_8006A8B4
#define kar_gryakulib_get_clobject_handle fn_800F99A4
#define kar_emupdate__near_80204878 fn_8020554C
#define kar_emupdate__near_802049fc fn_802056D0
#define fn_8020D30C fn_8020DFE0
#define fn_8020D6C0 fn_8020E394
#define kar_wneffect__near_80223120 fn_80223DF4
#define kar_plclearcheckerlib__near_8022d1c0 fn_8022DE94
#define kar_plclearcheckerlib__near_8022d758 fn_8022E42C
#define kar_mpcoll_create_volume_gobj fn_8027C0D4
#define kar_mpcoll_destroy_volume_gobj fn_8027C1C0
#define kar_mpcoll_show_volume_gobj fn_8027C1E0
#define kar_mpcoll_hide_volume_gobj fn_8027C1F0
#define kar_mpcoll_enable_volume_point_test fn_8027C29C
#define kar_mpcoll_disable_volume_point_test fn_8027C2AC
#endif

#define EM_ANIM_KIND_AIRRIDE_START 0x18
#define EM_ANIM_KIND_AIRRIDE_END 0x48
#define EM_ANIM_KIND_FADE_FAST_START 0x4C
#define EM_ANIM_KIND_FADE_FAST_END 0x4F
#define EM_ANIM_KIND_EXCLUDED 0x13

typedef struct EmAnimFlagsByte {
    u8 flag_80 : 1;
    u8 flag_40 : 1;
    u8 flag_20 : 1;
    u8 flag_10 : 1;
    u8 flag_08 : 1;
    u8 flag_04 : 1;
    u8 flag_02 : 1;
    u8 flag_01 : 1;
} EmAnimFlagsByte;

typedef struct EmAnimTemplateState {
    u8 pad_000[0x58];
    f32 field_058;
    u8 pad_05C[0x48];
} EmAnimTemplateState;

typedef struct EmAnimSegmentDesc {
    s32 jobj_index;
    u8 data[0x14];
} EmAnimSegmentDesc;

typedef struct EmAnimSegmentList {
    EmAnimSegmentDesc* entries;
    s32 count;
} EmAnimSegmentList;

typedef struct EmAnimTemplateSource {
    EmAnimTemplateState* state;
    u8 pad_004[0x0C];
    EmAnimSegmentList* segment_list;
    void* field_014;
} EmAnimTemplateSource;

typedef struct EmAnimKindCallbacks {
    u8 pad_000[0x0C];
    void (*callback_0C)(struct EmAnim*);
    void (*callback_10)(struct EmAnim*);
} EmAnimKindCallbacks;

typedef struct EmAnimInfo {
    u8 pad_000[0x08];
    void* field_008;
} EmAnimInfo;

typedef struct EmAnimMotionResource {
    HSD_AnimJoint* joint_anim;
    HSD_MatAnimJoint* mat_anim;
    u8 pad_008[0x04];
    EmAnimFlagsByte flags_0C;
} EmAnimMotionResource;

typedef struct EmAnimBytecode {
    f32 field_000;
    u8 pad_004[0x04];
    u8* volatile cursor;
} EmAnimBytecode;

typedef struct EmAnimGlobalCamera {
    void* field_000;
    void* field_004;
} EmAnimGlobalCamera;

typedef void (*EmAnimBytecodeCallback)(EmAnim*, EmAnimBytecode*);
typedef void (*EmAnimOpcodeCallback)(EmAnim*, EmAnimBytecode*, s32);

typedef struct EmAnimOpcodeEntry {
    EmAnimBytecodeCallback callback_0;
    EmAnimBytecodeCallback callback_4;
    u8 skip_words;
} EmAnimOpcodeEntry;

struct EmAnim {
    HSD_GObj* gobj;
    u8 pad_004[0x08];
    s32 kind;
    EmAnimInfo* field_010;
    EmAnimTemplateSource* field_014;
    u8 pad_018[0x1C];
    s32 field_034;
    u8 pad_038[0x10];
    EmAnimMotionResource* field_048;
    f32 field_04C;
    f32 field_050;
    void* field_054;
    void* field_058;
    u8 pad_05C[0x14];
    u8 field_070[0x238];
    f32 field_2A8;
    f32 field_2AC;
    f32 field_2B0;
    HSD_JObj** field_2B4;
    u8 pad_2B8[0x04];
    void* field_2BC;
    u8 pad_2C0[0x04];
    void* field_2C4;
    u8 pad_2C8[0x10];
    f32 field_2D8;
    f32 field_2DC;
    u8 pad_2E0[0x18];
    Vec pos;
    u8 pad_304[0x30];
    Vec dir;
    Vec scale;
    u8 pad_34C[0x18];
    f32 alpha;
    EmAnimTemplateState template_state;
    void* field_40C;
    void* collision_object;
    u8 pad_414[0x48];
    u8 field_45C[0x4F8];
    HSD_GObj* volume_gobj;
    u8 pad_958[0x124];
    s32 fade_frames;
    u8 pad_A80[0x10];
    void* field_A90;
    u8 pad_A94[0x20];
    void (*remove_callback)(EmAnim*);
    u8 pad_AB8[0x38];
    u32 field_AF0;
    u32 field_AF4;
    u32 field_AF8;
    u32 field_AFC;
    EmAnimFlagsByte flags_B00;
    u8 pad_B01[0x03];
    f32 field_B04;
    EmAnimFlagsByte flags_B08;
    EmAnimFlagsByte flags_B09;
    EmAnimFlagsByte flags_B0A;
    EmAnimFlagsByte flags_B0B;
};

extern const f32 lbl_805E2248;
extern const f32 lbl_805E2260;
extern const f32 lbl_805E2264;
extern const f32 lbl_805E2268;
extern const f32 lbl_805E226C;
extern const f32 lbl_805E2288;
extern const f32 lbl_805E2290;
extern const f32 lbl_805E22B4;

extern HSD_ObjAllocData lbl_8055A15C;
extern HSD_ObjAllocData lbl_8055A188;
extern HSD_ObjAllocData lbl_8055A1B4;
extern HSD_ObjAllocData lbl_8055A1E0;
extern HSD_GObjProc* hsdGObjProc_current;
extern EmAnimKindCallbacks* lbl_804B1D98[];
extern EmAnimOpcodeEntry lbl_804B2768[];
extern s32 lbl_804B2558[];
extern EmAnimGlobalCamera* lbl_805DD880;

void HSD_MObjSetAlpha(HSD_MObj* mobj, f32 alpha);
void HSD_ObjFree(HSD_ObjAllocData* data, void* obj);
void HSD_GObjObjectRemove(HSD_GObj* gobj);
void HSD_GObjProcRemove(HSD_GObjProc* proc);
void fn_801FBA38(EmAnim* anim);
void fn_801FC398(EmAnim* anim, s32 arg1, f32 arg2, s32 arg3, f32 arg4,
                 f32 arg5);
void fn_801FEE30(HSD_JObj* jobj, f32 alpha);
u8 fn_80009208(void);
void* kar_lbkdcoll__near_80072664(void* arg0);
u32 kar_grairglider_is_position_outside_checker_forward_cones(Vec* pos);
void kar_gmlanmenu__near_80054414(HSD_JObj* jobj, Vec* dir, f32 arg2,
                                  Vec* scale, Vec* pos);
void kar_collision_object_reset_handle(void* object, s32 arg1, f32 arg2,
                                       s32 arg3, s32 arg4);
void kar_emanim__near_80201ba4(EmAnim* anim);
void kar_emanim__near_80201ee8(EmAnim* anim);
void kar_emanim__near_80201fe8(EmAnim* anim);
void kar_emanim__near_802000c0(EmAnim* anim);
void kar_emanim__near_80200208(EmAnim* anim);
void kar_emanim__80200838(EmAnim* anim);
void kar_emanim__near_802011bc(EmAnim* anim, EmAnimBytecode* bytecode);
void kar_emanim__near_8020152c(EmAnim* anim, EmAnimBytecode* bytecode);
void kar_emanim__near_802017d0(EmAnim* anim);
void kar_emanim__near_80201968(EmAnim* anim, EmAnimBytecode* bytecode,
                               s32 opcode);
void kar_emanim__near_802019a0(EmAnim* anim, EmAnimBytecode* bytecode,
                               s32 opcode);
void* kar_emanim__near_802019fc(EmAnim* anim, s32 arg1, s32 arg2);
void* kar_emanim__near_80201a34(EmAnim* anim);
void* kar_emanim__near_80201ad0(EmAnim* anim);
void kar_emanim__near_8020267c(EmAnim* anim);
void kar_emparts__802026d4(EmAnim* anim);
void kar_emparts__80202a40(EmAnim* anim);
void kar_emupdate__near_8020429c(HSD_GObj* gobj);
void kar_emupdate__near_802042fc(HSD_GObj* gobj);
void* kar_cmreplay__8022cb74(s32 player_id);
void fn_80192110(void* replay, void* arg1, void* arg2);
void fn_80192174(void* arg0);
void kar_plclearchecker_get_template_vec_008(s32 slot, Vec* out);
HSD_GObj* kar_mpcoll_create_volume_gobj(s32 arg0);
void kar_mpcoll_destroy_volume_gobj(HSD_GObj* gobj);
void kar_mpcoll_show_volume_gobj(HSD_GObj* gobj);
void kar_mpcoll_hide_volume_gobj(HSD_GObj* gobj);
void kar_mpcoll_enable_volume_point_test(HSD_GObj* gobj);
void kar_mpcoll_disable_volume_point_test(HSD_GObj* gobj);
void* kar_lbcamera__near_80068d68(void* arg0);
void* kar_lbcamera__near_8006a250(void* arg0);
void* kar_lbcamera__near_8006a3f0(void* arg0, void* arg1, s32 arg2,
                                  s32 arg3);
s32 kar_lbcamera__near_80069f74(EmAnim* anim, void* arg1,
                                EmAnimOpcodeCallback callback);
void* kar_lbcolanim__near_8006ad20(void* arg0);
void* kar_lbcolanim__near_8006ada4(void* arg0);
void* kar_lbcolanim__near_8006ade0(void* arg0);
void* kar_lbcolanim__near_8006ae7c(void* arg0, s32 arg1, s32 arg2,
                                   void* arg3);
void kar_collision_update_motion_desc_from_model(void* desc, f32 arg1);
void kar_collision_object_set_segment_desc(void* handle, s32 index,
                                           HSD_JObj* jobj,
                                           EmAnimSegmentDesc* desc);
void kar_collision_object_free_handle(void* handle);
void kar_collision_object_disable_motion_slot(void* handle, u32 slot);
void kar_collision_object_flush_dirty_motion_slots(void* handle);
void kar_collision_object_update_motion_slot(void* handle, void* arg1,
                                             HSD_JObj* jobj);
void kar_collision_object_set_system_enabled(BOOL enabled);
void kar_clobject__near_8018d284(void* object, void* handle);
void* fn_80192788(HSD_GObj* gobj);
void* fn_801C8660(HSD_GObj* gobj);
void* kar_wneffect__near_80223120(HSD_GObj* gobj);
void* kar_emupdate__near_80204878(HSD_GObj* gobj);
void* kar_gryakulib_get_clobject_handle(HSD_GObj* gobj);
BOOL kar_emupdate__near_802049fc(s32 kind);
void fn_8020D30C(EmAnim* anim, s32 arg1, f32 arg2);
void fn_8020D6C0(EmAnim* anim, s32 arg1, s32 arg2, s32 arg3);
void kar_plclearcheckerlib__near_8022d1c0(s32 player_id);
void kar_plclearcheckerlib__near_8022d758(s32 player_id, s32 kind);

static void emanim_set_dobj_alpha(HSD_DObj* dobj, f32 alpha)
{
    while (dobj != NULL) {
        if (dobj->mobj != NULL) {
            HSD_MObjSetAlpha(dobj->mobj, alpha);
        }
        dobj = dobj->next;
    }
}

void kar_emanim__near_801ff2bc(HSD_JObj* jobj, f32 alpha)
{
    while (jobj != NULL) {
        emanim_set_dobj_alpha(jobj->u.dobj, alpha);
        if (jobj->child != NULL) {
            kar_emanim__near_801ff2bc(jobj->child, alpha);
        }
        jobj = jobj->next;
    }
}

void kar_emanim__near_801ff520(HSD_GObj* gobj)
{
    EmAnim* anim = gobj->user_data;

    if (anim->alpha < lbl_805E2260) {
        f32 step;

        kar_emanim__near_801ff2bc(gobj->hsd_obj, anim->alpha);
        if (anim->kind >= EM_ANIM_KIND_FADE_FAST_START &&
            anim->kind < EM_ANIM_KIND_FADE_FAST_END) {
            step = lbl_805E2264;
        } else {
            step = lbl_805E2268;
        }

        anim->alpha += step;
        if (anim->alpha > lbl_805E2260) {
            anim->alpha = lbl_805E2260;
        }
        return;
    }

    HSD_ObjFree(&lbl_8055A15C, anim->field_2B4);
    HSD_ObjFree(&lbl_8055A188, anim->field_2BC);
    HSD_ObjFree(&lbl_8055A1B4, anim->field_2C4);
    HSD_GObjObjectRemove(anim->gobj);
    kar_emanim__near_80201fe8(anim);
    fn_801FBA38(anim);
    kar_emanim__near_8020267c(anim);
    kar_emparts__802026d4(anim);
    kar_emparts__80202a40(anim);
    kar_gmlanmenu__near_80054414(anim->gobj->hsd_obj, &anim->dir,
                                 anim->field_2D8, &anim->scale, &anim->pos);
    kar_emanim__near_80201ee8(anim);
    kar_collision_object_reset_handle(anim->collision_object, 0,
                                      anim->field_2DC, 2, 0);
    kar_emanim__near_80201ba4(anim);

    if (anim->remove_callback != NULL) {
        anim->remove_callback(anim);
    } else {
        fn_801FC398(anim, anim->field_034, anim->field_2A8, 0x10,
                    anim->field_2B0, 0.0f);
    }
    HSD_GObjProcRemove(hsdGObjProc_current);
}

void kar_emanim__near_801ff698(HSD_GObj* gobj)
{
    EmAnim* anim = gobj->user_data;

    if (anim->alpha > lbl_805E226C) {
        kar_emanim__near_801ff2bc(gobj->hsd_obj, anim->alpha);
        anim->alpha -= lbl_805E2260 / anim->fade_frames;
        if (anim->alpha < lbl_805E226C) {
            anim->alpha = lbl_805E226C;
        }
    } else {
        kar_emupdate__near_802042fc(anim->gobj);
    }
}

BOOL kar_emanim__near_801ff72c(HSD_GObj* gobj)
{
    EmAnim* anim = gobj->user_data;
    BOOL result;

    result = FALSE;
    if (anim->alpha <= lbl_805E226C) {
        result = TRUE;
    }
    return result;
}

void kar_emanim__near_801ff754(EmAnim* anim)
{
    kar_emupdate__near_8020429c(anim->gobj);
    anim->alpha = lbl_805E2268;
    fn_801FEE30(anim->gobj->hsd_obj, anim->alpha);
    HSD_GObjProcCreate(anim->gobj, kar_emanim__near_801ff520, 0);
}

void kar_emanim__near_801ff7b0(EmAnim* anim)
{
    kar_emupdate__near_8020429c(anim->gobj);
    anim->alpha = lbl_805E2260;
    fn_801FEE30(anim->gobj->hsd_obj, anim->alpha);
    HSD_GObjProcCreate(anim->gobj, kar_emanim__near_801ff698, 0);
}

BOOL kar_emanim__near_801ff80c(s32 player_id, void* arg1, void* arg2)
{
    void* replay = kar_cmreplay__8022cb74(player_id);

    if (replay != NULL) {
        fn_80192110(replay, arg1, arg2);
        return FALSE;
    }
    return TRUE;
}

#pragma dont_inline on
void kar_emanim__near_801ff864(void* arg0, s32 arg1)
{
    fn_80192174(arg0);
}
#pragma dont_inline reset

BOOL kar_emanim__near_801ff884(EmAnim* anim)
{
    s32 kind = anim->kind;

    if (kind >= 0 && kind < EM_ANIM_KIND_AIRRIDE_START) {
        return kind != EM_ANIM_KIND_EXCLUDED;
    }
    return FALSE;
}

BOOL kar_emanim__near_801ff8b4(EmAnim* anim)
{
    s32 kind = anim->kind;

    if (kind >= EM_ANIM_KIND_AIRRIDE_START &&
        kind < EM_ANIM_KIND_AIRRIDE_END) {
        return TRUE;
    }
    return FALSE;
}

f32 kar_emanim__near_801ffccc(EmAnim* anim)
{
    f32 result = anim->template_state.field_058;

    if (result < lbl_805E2268) {
        result = lbl_805E2268;
    }
    return result;
}

s32 kar_emanim__near_801ffce4(EmAnim* anim, f32 max_distance)
{
    s32 i;
    s32 result;

    result = -1;
    for (i = 0; i < 4; i++) {
        if (kar_cmreplay__8022cb74(i) != NULL) {
            Vec pos;
            f32 distance;

            kar_plclearchecker_get_template_vec_008(i, &pos);
            distance = PSVECDistance(&pos, &anim->pos);
            if (distance < max_distance) {
                max_distance = distance;
                result = i;
            }
        }
    }

    return result;
}

void kar_emanim__near_801fff84(s32 slot, Vec* out)
{
    kar_plclearchecker_get_template_vec_008(slot, out);
}

f32 kar_emanim__near_801fffa4(s32 slot, Vec* pos)
{
    if (kar_cmreplay__8022cb74(slot) != NULL) {
        Vec player_pos;

        kar_plclearchecker_get_template_vec_008(slot, &player_pos);
        return PSVECDistance(&player_pos, pos);
    }

    return lbl_805E2248;
}

void kar_emanim__near_80200004(EmAnim* anim)
{
    s32 kind = anim->kind;

    if ((((kind > -1) && (kind < EM_ANIM_KIND_AIRRIDE_END)) ||
         ((kind >= EM_ANIM_KIND_FADE_FAST_START) &&
          (kind < EM_ANIM_KIND_FADE_FAST_END))) &&
        anim->volume_gobj == NULL) {
        HSD_GObj* volume = kar_mpcoll_create_volume_gobj(0);
        BOOL created = volume != NULL;

        anim->volume_gobj = volume;
        if (created) {
            if (anim->kind < EM_ANIM_KIND_FADE_FAST_END) {
                if (anim->kind >= EM_ANIM_KIND_FADE_FAST_START) {
                    kar_mpcoll_enable_volume_point_test(
                        *(HSD_GObj* volatile*) &anim->volume_gobj);
                    goto done_point_test;
                }
            }
            kar_mpcoll_disable_volume_point_test(
                *(HSD_GObj* volatile*) &anim->volume_gobj);

        done_point_test:
            kar_emanim__near_802000c0(anim);
            kar_emanim__near_80200208(anim);
        }
    }
}

void kar_emanim__near_802000ac(EmAnim* anim)
{
    anim->flags_B0B.flag_10 = TRUE;
}

void kar_emanim__near_802000c0(EmAnim* anim)
{
    anim->flags_B0B.flag_10 = FALSE;
}

void kar_emanim__near_802000d4(EmAnim* anim)
{
    if (anim->volume_gobj == NULL) {
        anim->volume_gobj = kar_mpcoll_create_volume_gobj(0);
    }

    anim->flags_B0B.flag_10 = FALSE;
    kar_emanim__near_80200208(anim);
}

void kar_emanim__near_8020012c(EmAnim* anim)
{
    HSD_GObj* volume = anim->volume_gobj;

    if (volume != NULL) {
        if (anim->flags_B0B.flag_10 && anim->flags_B09.flag_20) {
            kar_mpcoll_show_volume_gobj(volume);
        } else {
            kar_mpcoll_hide_volume_gobj(volume);
        }
    }
}

void kar_emanim__near_80200180(EmAnim* anim, BOOL visible)
{
    HSD_GObj* volume = anim->volume_gobj;

    if (volume != NULL) {
        if (visible) {
            kar_mpcoll_show_volume_gobj(volume);
        } else {
            kar_mpcoll_hide_volume_gobj(volume);
        }
    }
}

void kar_emanim__near_802001bc(EmAnim* anim)
{
    if (anim->volume_gobj != NULL) {
        kar_mpcoll_destroy_volume_gobj(anim->volume_gobj);
        anim->volume_gobj = NULL;
        anim->flags_B0B.flag_20 = FALSE;
    }
}

u32 kar_emanim__near_802005e0(EmAnim* anim)
{
    return kar_grairglider_is_position_outside_checker_forward_cones(
        &anim->pos);
}

void kar_emanim__near_80200604(EmAnim* anim)
{
    anim->field_A90 = kar_lbkdcoll__near_80072664(anim->field_A90);
}

s32 kar_emanim__near_80200638(void)
{
    return (s8) fn_80009208();
}

#if !defined(VERSION_GKYJ01)
BOOL kar_emanim__near_8020065c(EmAnim* anim)
{
    BOOL result;
    s32 value;

    result = FALSE;
    value = anim->field_034;
    if (value >= 0xE) {
        goto done;
    }
    if (value < 0xB) {
        goto done;
    }
    result = TRUE;

done:
    return result;
}
#endif

void kar_emanim__near_8020067c(EmAnim* anim)
{
    anim->field_40C = HSD_ObjAlloc(&lbl_8055A1E0);
}

void kar_emanim__near_802006b4(EmAnim* anim)
{
    EmAnimKindCallbacks* callbacks;

    anim->template_state = *anim->field_014->state;
    callbacks = lbl_804B1D98[anim->kind];
    if (callbacks->callback_0C != NULL) {
        callbacks->callback_0C(anim);
    }
}

void kar_emanim__near_8020072c(EmAnim* anim)
{
    EmAnimKindCallbacks* callbacks;

    anim->template_state = *anim->field_014->state;
    callbacks = lbl_804B1D98[anim->kind];
    if (callbacks->callback_0C != NULL) {
        callbacks->callback_0C(anim);
    }
    callbacks = lbl_804B1D98[anim->kind];
    if (callbacks->callback_10 != NULL) {
        callbacks->callback_10(anim);
    }
}

void kar_emanim__near_802007e0(void)
{
    s32 max;
    s32 i;

    max = 0;
    for (i = 0; i < 0x4F; i++) {
        if (max < lbl_804B2558[i]) {
            max = lbl_804B2558[i];
        }
    }

    HSD_ObjAllocInit(&lbl_8055A1E0, max, 4);
}

void kar_emanim__near_80200ba4(EmAnim* anim)
{
    kar_emanim__80200838(anim);
    kar_emanim__near_802017d0(anim);
}

void kar_emanim__near_80200bd8(EmAnim* anim)
{
    HSD_JObjRemoveAnimAllByFlags(anim->gobj->hsd_obj, 1);
}

void kar_emanim__near_80200c04(EmAnim* anim, f32 frame, f32 rate)
{
    HSD_JObj* child;
    HSD_JObj* jobj;
    u32 mask;
    EmAnimMotionResource* resource;

    resource = anim->field_048;
    jobj = anim->gobj->hsd_obj;
    anim->field_2B0 = rate;

    HSD_JObjRemoveAnimAll(jobj);
    if (jobj == NULL) {
        child = NULL;
    } else {
        child = jobj->child;
    }
    kar_lbairride__near_8005523c(child, anim->field_010->field_008);
    HSD_JObjAddAnimAll(jobj, resource->joint_anim, resource->mat_anim, NULL);
    HSD_JObjReqAnimAllByFlags(jobj, 0x15, frame);

    if (resource->mat_anim != NULL) {
        mask = 0xFFFF;
    } else {
        mask = 0xFB7F;
    }

    if (resource->flags_0C.flag_40) {
        kar_lbairride__near_800550f4(jobj, mask);
    }

    kar_lbairride__near_800550bc(jobj, mask, rate);
    anim->field_2A8 = frame - rate;
    anim->field_2AC = lbl_805E2288;
}

BOOL kar_emanim__near_80200d10(EmAnim* anim)
{
    return kar_lbairride__near_80054cd4(anim->gobj->hsd_obj);
}

void kar_emanim__near_80200df4(EmAnim* anim, s32 index, f32 rate)
{
    HSD_JObj* jobj = anim->field_2B4[index];

    if (jobj != NULL) {
        if (anim->field_048->mat_anim != NULL) {
            kar_lbairride__near_800550bc(jobj, 0xFFFF, rate);
        } else {
            kar_lbairride__near_800550bc(jobj, 0xFB7F, rate);
        }
    }
}

void fn_80200E58(EmAnim* anim, EmAnimBytecode* bytecode)
{
    u32 mode = *(u32*) bytecode->cursor & 0x03FFFFFF;

    switch (mode) {
    case 0:
        anim->flags_B00.flag_40 = TRUE;
        anim->field_B04 = bytecode->field_000;
        break;
    case 1:
        anim->flags_B00.flag_20 = TRUE;
        break;
    }

    bytecode->cursor += 4;
}

void kar_emanim__near_80201138(EmAnim* anim, void* arg1)
{
    EmAnimBytecode* bytecode = arg1;
    u32 value = *(u32*) bytecode->cursor;

    kar_collision_object_disable_motion_slot(anim->collision_object,
                                             value & 0x03FFFFFF);
    bytecode->cursor += 4;
}

void kar_emanim__near_80201180(EmAnim* anim, void* arg1)
{
    EmAnimBytecode* bytecode = arg1;

    kar_collision_object_flush_dirty_motion_slots(anim->collision_object);
    bytecode->cursor += 4;
}

void kar_emanim__near_80201418(EmAnim* anim, EmAnimBytecode* bytecode)
{
    u8* cursor;
    u32 word;
    s32 arg0;
    s32 arg1;

    cursor = bytecode->cursor;
    if (((*cursor >> 1) & 1) != 0) {
        word = *(u32*) cursor;
        arg0 = (word >> 13) & 0xFFF;
        arg1 = *(u16*) (cursor + 2) & 0x1FFF;
        kar_emanim__near_801ff864((void*) arg0, arg1);
    } else {
        word = *(u32*) cursor;
        arg0 = (word >> 13) & 0xFFF;
        arg1 = *(u16*) (cursor + 2) & 0x1FFF;
        kar_emanim__near_801ff864((void*) arg0, arg1);
    }

    bytecode->cursor += 4;
}

void fn_80201488(EmAnim* anim, EmAnimBytecode* bytecode)
{
    bytecode->cursor += 4;
}

void kar_emanim__near_80201498(EmAnim* anim, EmAnimBytecode* bytecode)
{
    u8* cursor;
    s32 arg1;
    u32 value;

    cursor = bytecode->cursor;
    value = (*(u32*) cursor >> 7) & 0xFFFF;
    arg1 = (*(u16*) cursor >> 7) & 7;
    bytecode->cursor = cursor + 4;
    bytecode->cursor += 4;
    fn_8020D30C(anim, arg1, lbl_805E2290 * (f32) value);
}

void fn_80201504(EmAnim* anim, EmAnimBytecode* bytecode)
{
    bytecode->cursor += 4;
    bytecode->cursor += 4;
    bytecode->cursor += 4;
}

#pragma dont_inline on
void kar_emanim__near_8020152c(EmAnim* anim, EmAnimBytecode* bytecode)
{
    u8* cursor;
    s32 arg2;
    s32 arg1;

    cursor = bytecode->cursor;
    arg2 = (*(u16*) cursor >> 2) & 0xFF;
    bytecode->cursor = cursor + 4;
    cursor = bytecode->cursor;
    arg1 = *(s32*) cursor;
    bytecode->cursor = cursor + 4;
    fn_8020D6C0(anim, arg1, arg2, 1);
}
#pragma dont_inline reset

void fn_8020172C(EmAnim* anim, EmAnimBytecode* bytecode)
{
    anim->flags_B0A.flag_02 = TRUE;
    bytecode->cursor += 4;
}

void kar_emanim__near_8020174c(EmAnim* anim, EmAnimBytecode* bytecode)
{
    u8* cursor;
    u32 value;

    cursor = bytecode->cursor;
    value = *(u32*) cursor;
    kar_emanim__near_802019fc(anim, (*(u16*) cursor >> 2) & 0xFF,
                              value & 0x3FFFF);
    bytecode->cursor += 4;
}

void fn_802016AC(EmAnim* anim, EmAnimBytecode* bytecode)
{
    u8* cursor = bytecode->cursor;

    switch (*cursor & 3) {
    case 0:
        anim->field_AF0 = *(u32*) cursor & 0x00FFFFFF;
        break;
    case 1:
        anim->field_AF4 = *(u32*) cursor & 0x00FFFFFF;
        break;
    case 2:
        anim->field_AF8 = *(u32*) cursor & 0x00FFFFFF;
        break;
    case 3:
        anim->field_AFC = *(u32*) cursor & 0x00FFFFFF;
        break;
    }

    bytecode->cursor += 4;
}

void kar_emanim__near_802018ec(EmAnim* anim, void* arg1)
{
    anim->field_054 = arg1;
    anim->field_058 = NULL;
    anim->field_04C = lbl_805E22B4;
}

void* kar_emanim__near_80201904(EmAnim* anim)
{
    return kar_lbcamera__near_80068d68(&anim->field_04C);
}

void kar_emanim__near_80201928(EmAnim* anim, void* bytecode)
{
    kar_emanim__near_802011bc(anim, bytecode);
}

void kar_emanim__near_80201948(EmAnim* anim, void* bytecode)
{
    kar_emanim__near_8020152c(anim, bytecode);
}

void kar_emanim__near_80201798(EmAnim* anim, void* arg1)
{
    EmAnimBytecode* bytecode = arg1;

    kar_emanim__near_80201a34(anim);
    bytecode->cursor += 4;
}

void kar_emanim__near_80201968(EmAnim* anim, EmAnimBytecode* bytecode,
                               s32 opcode)
{
    opcode -= 0x19;
    lbl_804B2768[opcode].callback_0(anim, bytecode);
}

void kar_emanim__near_802019a0(EmAnim* anim, EmAnimBytecode* bytecode,
                               s32 opcode)
{
    EmAnimOpcodeEntry* entry = &lbl_804B2768[opcode - 0x19];

    if (entry->callback_4 != NULL) {
        entry->callback_4(anim, bytecode);
    } else {
        bytecode->cursor += entry->skip_words * sizeof(u32);
    }
}

void* kar_emanim__near_802019fc(EmAnim* anim, s32 arg1, s32 arg2)
{
    return kar_lbcamera__near_8006a3f0(anim->field_070,
                                       lbl_805DD880->field_004, arg1, arg2);
}

void* kar_emanim__near_80201a34(EmAnim* anim)
{
    return kar_lbcamera__near_8006a250(anim->field_070);
}

void kar_emanim__near_80201a58(EmAnim* anim)
{
    EmAnimOpcodeCallback callback;

    if ((void*) anim->field_070 == kar_emanim__near_80201ad0(anim)) {
        callback = kar_emanim__near_80201968;
        goto run;
    }

    callback = kar_emanim__near_802019a0;
    goto run;

    do {
    run:
        kar_lbcamera__near_8006a250(anim->field_070);
    } while (kar_lbcamera__near_80069f74(anim, anim->field_070, callback) !=
             FALSE);
}

void* kar_emanim__near_80201ad0(EmAnim* anim)
{
    return kar_lbcolanim__near_8006ad20(anim->field_070);
}

void* kar_emanim__near_80201af4(EmAnim* anim)
{
    return kar_lbcolanim__near_8006ada4(anim->field_070);
}

void* kar_emanim__near_80201b18(EmAnim* anim)
{
    return kar_lbcolanim__near_8006ade0(anim->field_070);
}

void* kar_emanim__near_80201b3c(EmAnim* anim, void* arg1)
{
    return kar_lbcolanim__near_8006ae7c(anim->field_070, 0, 0, arg1);
}

void kar_emanim__near_80201b6c(EmAnim* anim)
{
    if (anim->field_014->field_014 != NULL) {
        kar_collision_update_motion_desc_from_model(anim->field_45C,
                                                    anim->field_2DC);
    }
}

void kar_emanim__near_80201e18(EmAnim* anim, void* unused, s32 index)
{
    kar_collision_object_update_motion_slot(anim->collision_object,
                                            unused,
                                            anim->field_2B4[index]);
}

void kar_emanim__near_80201e48(EmAnim* anim)
{
    s32 offset;
    EmAnimSegmentList* segment_list;
    s32 i;

    offset = 0;
    i = 0;
    segment_list = anim->field_014->segment_list;
    while (i < segment_list->count) {
        EmAnimSegmentDesc* desc =
            (EmAnimSegmentDesc*) ((u8*) segment_list->entries + offset);

        kar_collision_object_set_segment_desc(
            anim->collision_object, i, anim->field_2B4[desc->jobj_index],
            (EmAnimSegmentDesc*) ((u8*) desc + 4));
        offset += sizeof(EmAnimSegmentDesc);
        i++;
    }

    anim->flags_B08.flag_20 = FALSE;
}

void kar_emanim__near_80201fe8(EmAnim* anim)
{
    kar_collision_object_free_handle(anim->collision_object);
}

void kar_emanim__near_8020200c(EmAnim* anim)
{
    HSD_GObj* gobj;

    kar_collision_object_set_system_enabled(FALSE);
    gobj = hsdGObj_p_link_heads[0xA];
    while (gobj != NULL) {
        kar_clobject__near_8018d284(anim->collision_object, fn_80192788(gobj));
        gobj = gobj->next;
    }
}

void kar_emanim__near_80202070(EmAnim* anim)
{
    HSD_GObj* gobj;

    kar_collision_object_set_system_enabled(FALSE);
    gobj = hsdGObj_p_link_heads[9];
    while (gobj != NULL) {
        kar_clobject__near_8018d284(anim->collision_object, fn_801C8660(gobj));
        gobj = gobj->next;
    }
}

void kar_emanim__near_802020d4(EmAnim* anim)
{
    HSD_GObj* gobj;

    gobj = hsdGObj_p_link_heads[0xE];
    while (gobj != NULL) {
        kar_clobject__near_8018d284(anim->collision_object,
                                    kar_wneffect__near_80223120(gobj));
        gobj = gobj->next;
    }
}

void kar_emanim__near_80202130(EmAnim* anim)
{
    HSD_GObj* gobj;

    gobj = hsdGObj_p_link_heads[0xC];
    while (gobj != NULL) {
        if (anim->gobj != gobj) {
            kar_clobject__near_8018d284(anim->collision_object,
                                        kar_emupdate__near_80204878(gobj));
        }
        gobj = gobj->next;
    }
}

void kar_emanim__near_80202198(EmAnim* anim)
{
    HSD_GObj* gobj;

    kar_collision_object_set_system_enabled(FALSE);
    gobj = hsdGObj_p_link_heads[8];
    while (gobj != NULL) {
        kar_clobject__near_8018d284(
            anim->collision_object, kar_gryakulib_get_clobject_handle(gobj));
        gobj = gobj->next;
    }
}

void kar_emanim__near_802025dc(EmAnim* anim, s32 player_id)
{
    if (player_id != 5 && kar_emupdate__near_802049fc(anim->kind) != FALSE) {
        kar_plclearcheckerlib__near_8022d758(player_id, anim->kind);
    }
}

void kar_emanim__near_80202634(EmAnim* anim, s32 player_id)
{
    if (player_id != 5 && kar_emupdate__near_802049fc(anim->kind) != FALSE) {
        kar_plclearcheckerlib__near_8022d1c0(player_id);
    }
}

void kar_emanim__near_8020267c(EmAnim* anim)
{
    anim->field_2B4 = HSD_ObjAlloc(&lbl_8055A15C);
    anim->field_2BC = HSD_ObjAlloc(&lbl_8055A188);
    anim->field_2C4 = HSD_ObjAlloc(&lbl_8055A1B4);
}
