#include "dolphin/types.h"

asm u32 PPCMfmsr(void)
{
    nofralloc
    mfmsr r3
    blr
}

asm void PPCMtmsr(u32 msr)
{
    nofralloc
    mtmsr r3
    blr
}

asm u32 PPCMfhid0(void)
{
    nofralloc
    mfspr r3, HID0
    blr
}

asm void PPCMthid0(u32 hid0)
{
    nofralloc
    mtspr HID0, r3
    blr
}

asm u32 PPCMfl2cr(void)
{
    nofralloc
    mfspr r3, L2CR
    blr
}

asm void PPCMtl2cr(u32 l2cr)
{
    nofralloc
    mtspr L2CR, r3
    blr
}

asm void PPCMtdec(u32 dec)
{
    nofralloc
    mtdec r3
    blr
}

asm void kar_diagnostic__near_803c3354(void)
{
    nofralloc
    sc
    blr
}

asm void PPCHalt(void)
{
    nofralloc
    sync
_halt:
    nop
    li r3, 0
    nop
    b _halt
}

asm void PPCMtmmcr0(u32 mmcr0)
{
    nofralloc
    mtspr MMCR0, r3
    blr
}

asm void PPCMtmmcr1(u32 mmcr1)
{
    nofralloc
    mtspr MMCR1, r3
    blr
}

asm void PPCMtpmc1(u32 pmc1)
{
    nofralloc
    mtspr PMC1, r3
    blr
}

asm void PPCMtpmc2(u32 pmc2)
{
    nofralloc
    mtspr PMC2, r3
    blr
}

asm void PPCMtpmc3(u32 pmc3)
{
    nofralloc
    mtspr PMC3, r3
    blr
}

asm void PPCMtpmc4(u32 pmc4)
{
    nofralloc
    mtspr PMC4, r3
    blr
}

asm u32 PPCMffpscr(void)
{
    nofralloc
    stwu r1, -0x18(r1)
    stfd f31, 0x10(r1)
    mffs f31
    stfd f31, 8(r1)
    lwz r3, 0xc(r1)
    lfd f31, 0x10(r1)
    addi r1, r1, 0x18
    blr
}

asm void PPCMtfpscr(u32 fpscr)
{
    nofralloc
    stwu r1, -0x20(r1)
    stfd f31, 0x18(r1)
    li r4, 0
    stw r4, 0x10(r1)
    stw r3, 0x14(r1)
    lfd f31, 0x10(r1)
    mtfsf 255, f31
    lfd f31, 0x18(r1)
    addi r1, r1, 0x20
    blr
}

asm u32 PPCMfhid2(void)
{
    nofralloc
    mfspr r3, 920
    blr
}

asm void PPCMthid2(u32 hid2)
{
    nofralloc
    mtspr 920, r3
    blr
}

asm void PPCMtwpar(u32 wpar)
{
    nofralloc
    mtspr WPAR, r3
    blr
}

void PPCDisableSpeculation(void)
{
    PPCMthid0(PPCMfhid0() | 0x200);
}

asm void PPCSetFpNonIEEEMode(void)
{
    nofralloc
    mtfsb1 29
    blr
}
