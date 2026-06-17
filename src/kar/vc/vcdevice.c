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

void kar_mpcoll__near_801ef2f4(void)
{
}

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

void fn_801FA184(void)
{
}

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
