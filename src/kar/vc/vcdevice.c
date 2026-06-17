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
    u8 pad_0[0xFC];
    f32 field_FC;
};

struct VcDevice {
    u8 pad_0[0x38C];
    f32 field_38C;
    u8 pad_390[0x2C0];
    VcDeviceConfig* config_650;
    u8 pad_654[0x18];
    s32 field_66C;
    u8 pad_670[0x78];
    f32 field_6E8;
    u8 pad_6EC[0x1E8];
    f32 field_8D4;
    u8 pad_8D8[0x2D4];
    s32 field_BAC;
    u8 pad_BB0[0x90];
    f32 field_C40;
    f32 field_C44;
    VcDeviceWord field_C48;
    f32 field_C4C;
    u8 pad_C50[0x4];
    f32 field_C54;
    u8 pad_C58[0xEE8];
    s32 field_1B40;
    u8 pad_1B44[0x58];
    volatile s32 field_1B9C;
};

struct VcDeviceDestroyData {
    HSD_GObj* gobj;
    void* field_4;
};

extern f32 lbl_805E1E48;
extern const f32 lbl_805E1EE0;
extern const f32 lbl_805E2064;

extern void HSD_GObjDestroy(HSD_GObj* gobj);
extern void fn_801E1DC0(VcDevice* device);
extern void fn_801E1E6C(VcDevice* device);
extern void fn_801E441C(VcDevice* device);
extern void fn_801E45CC(VcDevice* device);
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
extern void kar_mpcoll__near_801ef454(VcDevice* device);
extern void kar_mpcoll__near_801f7e54(VcDevice* device);
extern void kar_mpcoll__near_801f8578(VcDevice* device);
extern void kar_mpcoll__near_801f8ef4(VcDevice* device);
extern void kar_mpcoll__near_801f8f44(VcDevice* device);
extern void kar_mpcoll__near_801f913c(VcDevice* device);
extern void kar_mpcoll__near_801f9160(VcDevice* device);
extern void kar_mpcoll__near_801f9184(VcDevice* device);
extern void kar_mpcoll__near_801f94a0(VcDevice* device);
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

void fn_801F5F24(VcDevice* device)
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
