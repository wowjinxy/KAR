#include <global.h>
#include <sysdolphin/memory.h>
#include <sysdolphin/random.h>

extern u32 HSD_RandDefaultSeed;
extern u32* HSD_RandSeedPtr;

s32 HSD_Rand(void)
{
    *HSD_RandSeedPtr = *HSD_RandSeedPtr * 214013 + 2531011;
    return *HSD_RandSeedPtr >> 0x10;
}

f32 HSD_Randf(void)
{
    *HSD_RandSeedPtr = *HSD_RandSeedPtr * 214013 + 2531011;
    return (f32) (*HSD_RandSeedPtr >> 0x10) / (1 << 16);
}

s32 HSD_Randi(s32 max_val)
{
    return max_val * HSD_Rand() / (1 << 16);
}

void _HSD_RandForgetMemory(void)
{
    if (_HSD_MemCheckOwn(HSD_RandSeedPtr)) {
        HSD_RandSeedPtr = &HSD_RandDefaultSeed;
    }
}
