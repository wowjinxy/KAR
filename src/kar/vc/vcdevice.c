#include "functions.h"
#include <dolphin/types.h>
#include <sysdolphin/gobj.h>

typedef struct VcDevice VcDevice;
typedef struct VcDeviceConfig VcDeviceConfig;
typedef struct VcDeviceDestroyData VcDeviceDestroyData;
typedef union VcDeviceWord VcDeviceWord;

union VcDeviceWord {
    s32 s;
    f32 f;
};

struct VcDeviceConfig {
    u8 pad_0[0x20];
    u8 field_20[0x38];
    f32 field_58;
    f32 field_5C;
    u8 pad_60[0x9C];
    f32 field_FC;
    u8 pad_100[0x10];
    f32 field_110;
    u8 pad_114[0x48];
    f32 field_15C;
};

struct VcDevice {
    HSD_GObj* gobj_0;
    u8 pad_4[0x38];
    u8 field_3C[0x3C];
    u8 flags_78;
    u8 pad_79[0x273];
    f32 field_2EC;
    f32 field_2F0;
    f32 field_2F4;
    u8 pad_2F8[0x38];
    f32 field_330;
    f32 field_334;
    f32 field_338;
    f32 field_33C;
    u8 pad_340[0x4C];
    f32 field_38C;
    u8 pad_390[0x80];
    void* field_410;
    u8 pad_414[0xE8];
    f32 field_4FC;
    u8 pad_500[0x150];
    VcDeviceConfig* config_650;
    u8 pad_654[0x18];
    s32 field_66C;
    u8 pad_670[0x78];
    f32 field_6E8;
    u8 pad_6EC[0x4C];
    u8 field_738[0xC];
    f32 field_744;
    u8 pad_748[0x4];
    f32 field_74C;
    u8 pad_750[0x18];
    f32 field_768;
    f32 field_76C;
    f32 field_770;
    u8 pad_774[0x160];
    f32 field_8D4;
    u8 pad_8D8[0x2D4];
    s32 field_BAC;
    u8 pad_BB0[0x80];
    u8 flags_C30;
    u8 pad_C31[0x2];
    u8 flags_C33;
    u8 pad_C34[0xC];
    f32 field_C40;
    f32 field_C44;
    VcDeviceWord field_C48;
    f32 field_C4C;
    u8 pad_C50[0x4];
    f32 field_C54;
    u8 pad_C58[0x940];
    s32 field_1598;
    u8 pad_159C[0x5A4];
    s32 field_1B40;
    u8 pad_1B44[0x4];
    VcDeviceWord field_1B48;
    u8 pad_1B4C[0x50];
    volatile s32 field_1B9C;
};

struct VcDeviceDestroyData {
    HSD_GObj* gobj;
    void* field_4;
};

extern f32 lbl_805E1E48;
extern const f32 lbl_805E1EE0;
extern const f32 lbl_805E2060;
extern const f32 lbl_805E2064;
extern const f32 lbl_805E2090;

extern void HSD_GObjDestroy(HSD_GObj* gobj);
extern void HSD_JObjClearFlagsAll(void* jobj, u32 flags);
extern void HSD_JObjSetFlagsAll(void* jobj, u32 flags);
extern void fn_801D33CC(VcDevice* device, f32 value);
extern void fn_801D4584(VcDevice* device, void* arg1, f32 value);
extern void fn_801D7E5C(VcDevice* device, f32 value);
extern void fn_801DA028(VcDevice* device, void* arg1);
extern BOOL fn_801E1200(VcDevice* device);
extern void fn_801E1DC0(VcDevice* device);
extern void fn_801E1E6C(VcDevice* device);
extern void fn_801E441C(VcDevice* device);
extern void fn_801E45CC(VcDevice* device);
extern void fn_801E5838(VcDevice* device);
extern void fn_801EF908(VcDevice* device);
extern BOOL fn_801EFB68(VcDevice* device);
extern void kar_collision_object_flush_dirty_motion_slots(void* object);
extern void kar_grairglider_release_spawn_handle(HSD_GObj* gobj);
extern void kar_vcgenerator__near_801dd668(s32* handle);
extern BOOL fn_801EF76C(VcDevice* device);
extern BOOL fn_801F05BC(VcDevice* device);
extern BOOL fn_801FA710(VcDevice* device);
extern BOOL fn_801FAB88(VcDevice* device);
extern BOOL fn_801F9EC4(VcDevice* device);
extern void fn_801FA96C(VcDevice* device);
extern BOOL kar_mpcoll__801cf1b8(VcDevice* device, f32 value);
extern void kar_clobject__near_8018d850(void* object);
extern f32 kar_lbvector_lerp_float_table_sample(void* table, f32 arg1, f32 arg2);
extern void fn_801E6670(VcDevice* device);
extern void fn_801E6D24(VcDevice* device);
extern void fn_801E7154(VcDevice* device);
extern void fn_801FA188(VcDevice* device);
extern void fn_801FA1E8(VcDevice* device);
extern void fn_801FA2BC(VcDevice* device);
extern void kar_mpcoll__near_801cc378(VcDevice* device);
extern void kar_mpcoll__near_801cc480(VcDevice* device);
extern void kar_mpcoll__near_801cd658(VcDevice* device);
extern void kar_mpcoll__near_801cd71c(VcDevice* device);
extern void kar_mpcoll__near_801cdb8c(VcDevice* device);
extern void kar_mpcoll__near_801ce5b4(VcDevice* device);
extern void kar_mpcoll__near_801ce650(VcDevice* device);
extern void kar_mpcoll__near_801d04d8(VcDevice* device);
extern void kar_mpcoll__near_801edd20(VcDevice* device);
extern void kar_mpcoll__near_801eddd0(VcDevice* device);
extern BOOL kar_mpcoll__near_801eec30(VcDevice* device);
extern BOOL kar_mpcoll__near_801eed68(VcDevice* device);
extern void kar_mpcoll__near_801eef30(VcDevice* device);
extern BOOL kar_mpcoll__near_801ef150(VcDevice* device);
extern void kar_mpcoll__near_801ef454(VcDevice* device);
extern BOOL kar_mpcoll__near_801f91b8(VcDevice* device);
extern void kar_mpcoll__near_801f7e54(VcDevice* device);
extern BOOL kar_mpcoll__near_801f9aa8(VcDevice* device);
extern void kar_mpcoll__near_801f8578(VcDevice* device);
extern void kar_mpcoll__near_801f8ef4(VcDevice* device);
extern void kar_mpcoll__near_801f8f44(VcDevice* device);
extern BOOL kar_mpcoll__near_801f8f78(VcDevice* device);
extern void kar_mpcoll__near_801f913c(VcDevice* device);
extern void kar_mpcoll__near_801f9160(VcDevice* device);
extern void kar_mpcoll__near_801f9184(VcDevice* device);
extern void kar_mpcoll__near_801f94a0(VcDevice* device);
extern void kar_mpcoll__near_801f9454(VcDevice* device);
extern void kar_mpcoll__near_801f94c4(VcDevice* device);
extern void kar_mpcoll__near_801f9594(VcDevice* device);
extern void kar_mpcoll__near_801f9738(VcDevice* device);
extern void kar_mpcoll__near_801f9778(VcDevice* device);
extern void kar_mpcoll__near_801f97e4(VcDevice* device);
extern void kar_mpcoll__near_801f99e0(VcDevice* device);
extern void kar_mpcoll__near_801f9a04(VcDevice* device);
extern void kar_mpcoll__near_801f9a6c(VcDevice* device);

void fn_801E57FC(VcDeviceDestroyData* data)
{
    if (data->field_4 == NULL) {
        HSD_GObjDestroy(data->gobj);
    }
}

void fn_801E582C(void)
{
}

void fn_801E5830(void)
{
}

void fn_801E5834(void)
{
}

s32* fn_801E5AB0(HSD_GObj* gobj)
{
    return &((VcDevice*) gobj->user_data)->field_BAC;
}

VcDevice* fn_801E5F14(HSD_GObj* gobj)
{
    return gobj->user_data;
}

BOOL fn_801E7138(VcDevice* device)
{
    device->field_1B9C--;
    return device->field_1B9C == 0;
}

void fn_801E811C(VcDevice* device)
{
    device->field_C40 = lbl_805E1E48;
}

void fn_801E8128(void)
{
}

void fn_801E9E68(void)
{
}

void fn_801EC114(void)
{
}

void fn_801EB898(VcDevice* device, f32 value)
{
    device->field_C40 += value;
    device->field_38C += value;
}

void kar_mpcoll__near_801ed748(void)
{
}

void kar_mpcoll__near_801ee670(VcDevice* device)
{
    device->field_C48.s = -1;
    device->field_C4C = lbl_805E1EE0;
}

void fn_801EE77C(void)
{
}

void fn_801EF96C(VcDevice* device)
{
    device->field_1B40++;
}

void fn_801EE8D4(void)
{
}

void fn_801EEA7C(void)
{
}

void fn_801EEBE0(void)
{
}

void fn_801EEBE4(void)
{
}

void fn_801EEBE8(void)
{
}

void fn_801EEF78(void)
{
}

#pragma push
#pragma dont_inline on
void kar_mpcoll__near_801ef2f4(void)
{
}
#pragma pop

void fn_801EFC98(void)
{
}

void fn_801EFF14(void)
{
}

void fn_801F0130(void)
{
}

void fn_801F0260(void)
{
}

void fn_801F03C0(void)
{
}

void fn_801F04E4(void)
{
}

void fn_801F0530(void)
{
}

void fn_801F0594(void)
{
}

void fn_801F0598(void)
{
}

void fn_801F06A0(void)
{
}

void fn_801F0BA8(void)
{
}

void fn_801F0BAC(void)
{
}

void fn_801F0C40(void)
{
}

void fn_801F0C44(void)
{
}

void fn_801F0C48(void)
{
}

void fn_801F3C84(VcDevice* device)
{
    device->field_C44 = lbl_805E2064;
    device->field_C48.f = lbl_805E2064;
}

void fn_801F4E64(VcDevice* device)
{
    device->field_8D4 = lbl_805E2064;
    device->field_C54 = lbl_805E2064;
}

void fn_801F5AD4(VcDevice* device)
{
    device->field_6E8 = device->config_650->field_FC;
}

f32 fn_801F5C14(VcDevice* device)
{
    return device->field_C48.f;
}

void fn_801F5FC8(VcDevice* device, f32 value)
{
    device->field_C44 += value;
}

void fn_801F8A28(void)
{
}

void fn_801F8B6C(void)
{
}

void fn_801F8D04(void)
{
}

void fn_801F8E60(void)
{
}

void fn_801F8E64(void)
{
}

void fn_801F8E68(void)
{
}

void fn_801F937C(void)
{
}

void fn_801F93C8(void)
{
}

void fn_801F942C(void)
{
}

void fn_801F9430(void)
{
}

void kar_mpcoll__near_801f949c(void)
{
}

void kar_mpcoll__near_801f9734(void)
{
}

void fn_801F99DC(void)
{
}

void fn_801F9E00(void)
{
}

void fn_801F9E04(void)
{
}

void fn_801F9E98(void)
{
}

void fn_801F9E9C(void)
{
}

void fn_801F9EA0(void)
{
}

#pragma push
#pragma dont_inline on
void fn_801FA184(void)
{
}
#pragma pop

BOOL fn_801FA064(VcDevice* device)
{
    return device->field_66C != 0;
}

void fn_801FA9DC(void)
{
}

void fn_801FACB8(void)
{
}

void fn_801FAF4C(void)
{
}

void fn_801FB148(void)
{
}

void fn_801FB2EC(void)
{
}

void fn_801FB3FC(void)
{
}

void fn_801FC8E8(void)
{
}

VcDevice* fn_801FC294(HSD_GObj* gobj)
{
    return gobj->user_data;
}

#pragma push
#pragma dont_inline on
void fn_801E6828(VcDevice* device)
{
    kar_mpcoll__near_801ce650(device);
}

void fn_801E6EB4(VcDevice* device)
{
    kar_mpcoll__near_801ce5b4(device);
}

void fn_801E6F98(VcDevice* device)
{
    kar_mpcoll__near_801ce650(device);
}

void fn_801EB95C(VcDevice* device)
{
    kar_mpcoll__near_801cc378(device);
}

void kar_mpcoll__near_801edd00(VcDevice* device)
{
    kar_mpcoll__near_801cd658(device);
}

void kar_mpcoll__near_801eddb0(VcDevice* device)
{
    kar_mpcoll__near_801cdb8c(device);
}

void kar_mpcoll__near_801eecb0(VcDevice* device)
{
    fn_801E1E6C(device);
}

void kar_mpcoll__near_801eedf8(void)
{
    kar_mpcoll__near_801ef2f4();
}

void kar_mpcoll__near_801eee94(VcDevice* device)
{
    kar_mpcoll__near_801edd20(device);
}

void fn_801EF74C(VcDevice* device)
{
    kar_mpcoll__near_801ef454(device);
}

void fn_801F03C4(VcDevice* device)
{
    fn_801E441C(device);
}

void fn_801F03E4(VcDevice* device)
{
    fn_801E45CC(device);
}

void fn_801F04C4(VcDevice* device)
{
    fn_801E6670(device);
}

void fn_801F059C(VcDevice* device)
{
    fn_801E6828(device);
}

void fn_801F0844(void)
{
    kar_mpcoll__near_801ef2f4();
}

void fn_801F0A34(VcDevice* device)
{
    fn_801E7154(device);
}

void fn_801F0AC8(VcDevice* device)
{
    kar_mpcoll__near_801eddd0(device);
}

void fn_801F0BB0(VcDevice* device)
{
    fn_801E6D24(device);
}

void fn_801F0BD0(VcDevice* device)
{
    fn_801E6EB4(device);
}

void fn_801F0C4C(VcDevice* device)
{
    fn_801E6F98(device);
}

void fn_801F5F24(VcDevice* device, f32 value)
{
    kar_mpcoll__near_801cc378(device);
}

void kar_mpcoll__near_801f8518(VcDevice* device)
{
    kar_mpcoll__near_801cd71c(device);
}

void kar_mpcoll__near_801f8538(VcDevice* device)
{
    kar_mpcoll__near_801d04d8(device);
}

void kar_mpcoll__near_801f8558(VcDevice* device)
{
    kar_mpcoll__near_801cdb8c(device);
}

void kar_mpcoll__near_801f8a2c(VcDevice* device)
{
    kar_mpcoll__near_801f7e54(device);
}

void kar_mpcoll__near_801f8e6c(VcDevice* device)
{
    kar_mpcoll__near_801ce650(device);
}

void kar_mpcoll__near_801f8ed4(VcDevice* device)
{
    fn_801E1E6C(device);
}

void kar_mpcoll__near_801f8f24(VcDevice* device)
{
    fn_801E1DC0(device);
}

void kar_mpcoll__near_801f9058(VcDevice* device)
{
    kar_mpcoll__near_801f913c(device);
}

void kar_mpcoll__near_801f9078(VcDevice* device)
{
    kar_mpcoll__near_801f9160(device);
}

void kar_mpcoll__near_801f9098(VcDevice* device)
{
    kar_mpcoll__near_801f9184(device);
}

void kar_mpcoll__near_801f911c(void)
{
    fn_801FA184();
}

void kar_mpcoll__near_801f9258(VcDevice* device)
{
    kar_mpcoll__near_801f8ef4(device);
}

void kar_mpcoll__near_801f9278(VcDevice* device)
{
    kar_mpcoll__near_801f8f24(device);
}

void kar_mpcoll__near_801f9298(VcDevice* device)
{
    kar_mpcoll__near_801f8f44(device);
}

void kar_mpcoll__near_801f935c(VcDevice* device)
{
    fn_801E6670(device);
}

void kar_mpcoll__near_801f9434(VcDevice* device)
{
    fn_801E6828(device);
}

void kar_mpcoll__near_801f990c(VcDevice* device)
{
    kar_mpcoll__near_801f99e0(device);
}

void kar_mpcoll__near_801f992c(VcDevice* device)
{
    kar_mpcoll__near_801f9a04(device);
}

void kar_mpcoll__near_801f994c(VcDevice* device)
{
    kar_mpcoll__near_801f9a6c(device);
}

void kar_mpcoll__near_801f9b64(VcDevice* device)
{
    kar_mpcoll__near_801f9738(device);
}

void fn_801F9B84(VcDevice* device)
{
    kar_mpcoll__near_801f9778(device);
}

void fn_801F9BA4(VcDevice* device)
{
    kar_mpcoll__near_801f97e4(device);
}

void fn_801F9CA4(VcDevice* device)
{
    fn_801E7154(device);
}

void fn_801F9D20(VcDevice* device)
{
    kar_mpcoll__near_801f8578(device);
}

void fn_801F9E08(VcDevice* device)
{
    fn_801E6D24(device);
}

void fn_801F9E28(VcDevice* device)
{
    fn_801E6EB4(device);
}

void fn_801F9EA4(VcDevice* device)
{
    fn_801E6F98(device);
}

void fn_801FA004(VcDevice* device)
{
    fn_801FA188(device);
}

void fn_801FA024(VcDevice* device)
{
    fn_801FA1E8(device);
}

void fn_801FA044(VcDevice* device)
{
    fn_801FA2BC(device);
}

void fn_801FA1C8(VcDevice* device)
{
    kar_mpcoll__near_801cc480(device);
}

void fn_801FA5C0(VcDevice* device)
{
    fn_801FA2BC(device);
}

void fn_801FA6B0(VcDevice* device)
{
    kar_mpcoll__near_801f94a0(device);
}

void fn_801FA6D0(VcDevice* device)
{
    kar_mpcoll__near_801f94c4(device);
}

void fn_801FA6F0(VcDevice* device)
{
    kar_mpcoll__near_801f9594(device);
}

void fn_801FB324(VcDevice* device)
{
    fn_801E45CC(device);
}
#pragma pop

void kar_mpcoll__near_801ee758(VcDevice* device)
{
    if (fn_801E1200(device)) {
        return;
    }
}

void kar_mpcoll__near_801eea58(VcDevice* device)
{
    if (fn_801E1200(device)) {
        return;
    }
}

void kar_mpcoll__near_801eee18(VcDevice* device)
{
    if (kar_mpcoll__near_801eec30(device)) {
        return;
    }
}

void kar_mpcoll__near_801eef7c(VcDevice* device)
{
    if (kar_mpcoll__near_801ef150(device)) {
        return;
    }
}

void fn_801EF97C(VcDevice* device)
{
    if (fn_801EFB68(device)) {
        return;
    }
}

void fn_801EFC9C(VcDevice* device)
{
    if (fn_801EF76C(device)) {
        return;
    }
}

void fn_801F0864(VcDevice* device)
{
    if (fn_801F05BC(device)) {
        return;
    }
}

f32 fn_801F5A60(VcDevice* device)
{
    f32 value = device->field_744 + device->config_650->field_58;

    if (value > lbl_805E2060) {
        return lbl_805E2060;
    }
    return value;
}

void fn_801F65C0(VcDevice* device)
{
    fn_801DA028(device, device->field_738);
}

void kar_mpcoll__near_801f8784(VcDevice* device)
{
    kar_vcgenerator__near_801dd668(&device->field_1598);
}

void kar_mpcoll__near_801f8a04(VcDevice* device)
{
    if (fn_801E1200(device)) {
        return;
    }
}

void kar_mpcoll__near_801f8ce0(VcDevice* device)
{
    if (fn_801E1200(device)) {
        return;
    }
}

void kar_mpcoll__near_801f913c(VcDevice* device)
{
    if (kar_mpcoll__near_801f91b8(device)) {
        return;
    }
}

void kar_mpcoll__near_801f9160(VcDevice* device)
{
    fn_801F5F24(device, device->field_4FC);
}

void kar_mpcoll__near_801f94a0(VcDevice* device)
{
    if (fn_801F9EC4(device)) {
        return;
    }
}

void kar_mpcoll__near_801f99e0(VcDevice* device)
{
    if (kar_mpcoll__near_801f9aa8(device)) {
        return;
    }
}

void fn_801FA9E0(VcDevice* device)
{
    if (fn_801FAB88(device)) {
        return;
    }
}

void fn_801FACBC(VcDevice* device)
{
    if (fn_801FA710(device)) {
        return;
    }
}

void fn_801FD0BC(VcDevice* device)
{
    kar_collision_object_flush_dirty_motion_slots(device->field_410);
}

void fn_801FECD4(void* jobj)
{
    HSD_JObjClearFlagsAll(jobj, 0x10);
}

void fn_801FECF8(void* jobj)
{
    HSD_JObjSetFlagsAll(jobj, 0x10);
}

void fn_801FED1C(VcDevice* device)
{
    kar_grairglider_release_spawn_handle(device->gobj_0);
}

void kar_mpcoll__near_801ed720(VcDevice* device, f32 scale)
{
    device->field_330 = device->field_768 * scale;
    device->field_334 = device->field_76C * scale;
    device->field_338 = device->field_770 * scale;
}

void kar_mpcoll__near_801ef5c4(VcDevice* device)
{
    fn_801D4584(device, device->field_3C, device->field_1B48.f);
}

void fn_801F61E4(VcDevice* device, f32 arg1, f32 arg2)
{
    if ((device->flags_C33 & 1) == 0) {
        device->field_C44 += arg2;
    }
    device->field_38C += arg1;
}

void kar_mpcoll__near_801f85bc(VcDevice* device)
{
    fn_801D33CC(device, device->config_650->field_110);
}

void fn_801FA440(VcDevice* device)
{
    fn_801D4584(device, device->field_3C, device->field_1B48.f);
}

void fn_801FC670(HSD_GObj* gobj)
{
    kar_clobject__near_8018d850(((VcDevice*) gobj->user_data)->field_410);
}

void fn_801FD6EC(VcDevice* device, f32 scale)
{
    device->field_2EC = device->field_334 * scale;
    device->field_2F0 = device->field_338 * scale;
    device->field_2F4 = device->field_33C * scale;
}

f32 fn_801F5FD8(VcDevice* device)
{
    f32 value = device->field_C44;

    if (!(value > lbl_805E2064)) {
        return lbl_805E2064;
    }

    value /= device->field_C40;
    if (value > lbl_805E2060) {
        return lbl_805E2060;
    }
    return value;
}

BOOL fn_801EF7A4(VcDevice* device)
{
    return kar_mpcoll__801cf1b8(device, device->config_650->field_15C) == 0;
}

f32 fn_801F605C(VcDevice* device)
{
    return kar_lbvector_lerp_float_table_sample(device->config_650->field_20, lbl_805E2090,
                                                lbl_805E2060);
}

void fn_801F633C(VcDevice* device)
{
    fn_801D7E5C(device, device->field_74C * device->config_650->field_5C);
}

void kar_mpcoll__near_801ef338(VcDevice* device)
{
    if ((device->flags_C30 >> 6) & 1) {
        kar_mpcoll__near_801cc480(device);
    }
}

void fn_801EFEE8(VcDevice* device)
{
    if ((device->flags_78 >> 6) & 1) {
        kar_mpcoll__near_801eef30(device);
    }
}

void fn_801F0234(VcDevice* device)
{
    if ((device->flags_78 >> 6) & 1) {
        fn_801E5838(device);
    }
}

void fn_801F0568(VcDevice* device)
{
    if ((device->flags_78 >> 6) & 1) {
        fn_801EF908(device);
    }
}

void kar_mpcoll__near_801f9400(VcDevice* device)
{
    if ((device->flags_78 >> 6) & 1) {
        fn_801FA96C(device);
    }
}

void fn_801FAF20(VcDevice* device)
{
    if ((device->flags_78 >> 6) & 1) {
        kar_mpcoll__near_801f9454(device);
    }
}

void fn_801FB3D0(VcDevice* device)
{
    if ((device->flags_78 >> 6) & 1) {
        fn_801E5838(device);
    }
}

void kar_mpcoll__near_801eecd0(VcDevice* device)
{
    if (device->field_1B48.s == 0) {
        if (kar_mpcoll__near_801eed68(device)) {
            return;
        }
    }
}

void kar_mpcoll__near_801f8ef4(VcDevice* device)
{
    if (device->field_1B48.s == 0) {
        if (kar_mpcoll__near_801f8f78(device)) {
            return;
        }
    }
}
