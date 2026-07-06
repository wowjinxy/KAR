#include <global.h>
#include <sysdolphin/random.h>

extern u32 lbl_805DCD30;
extern u32* lbl_805DCD38;

extern s32 _HSD_MemCheckOwn(void* ptr);

s32 HSD_Rand(void)
{
    *lbl_805DCD38 = *lbl_805DCD38 * 214013 + 2531011;
    return *lbl_805DCD38 >> 0x10;
}

f32 HSD_Randf(void)
{
    *lbl_805DCD38 = *lbl_805DCD38 * 214013 + 2531011;
    return (f32) (*lbl_805DCD38 >> 0x10) / (1 << 16);
}

s32 HSD_Randi(s32 max_val)
{
    return max_val * HSD_Rand() / (1 << 16);
}

void fn_8041E6A4(void)
{
    if (_HSD_MemCheckOwn(lbl_805DCD38)) {
        lbl_805DCD38 = &lbl_805DCD30;
    }
}
