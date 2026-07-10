#include <global.h>
#include <sysdolphin/perf.h>

void memset(void*, int, int);
extern s64 OSGetTime(void);

extern HSD_PerfStat HSD_PerfLastStat;
extern HSD_PerfStat lbl_80504418;     // HSD_PerfCurrentStat

extern u32 lbl_805DE2F0; // start_time, high word
extern u32 lbl_805DE2F4; // start_time, low word

extern char kar_srcfile_perf_c_805dcce0[7]; // "perf.c"
extern char lbl_805DCCE8[7];                // "n < 32"

#define assert_line_named(line, cond, condstr)                                 \
    ((cond) ? ((void) 0) : __assert(kar_srcfile_perf_c_805dcce0, line, condstr))

void HSD_PerfInitStat(void)
{
    HSD_PerfLastStat = lbl_80504418;
    memset(&lbl_80504418, 0, sizeof(HSD_PerfStat));
}

void HSD_PerfSetStartTime(void)
{
    s64 now = OSGetTime();
    lbl_805DE2F4 = (u32) now;
    lbl_805DE2F0 = (u32) (now >> 32);
}

void HSD_PerfSetCPUTime(void)
{
    s64 elapsed = OSGetTime() - (lbl_805DE2F4 | ((s64) lbl_805DE2F0 << 32));
    lbl_80504418.cpu_time = elapsed / (f32) (*(u32*) 0x800000F8 / 4 / 60);
}

void HSD_PerfSetDrawTime(void)
{
    s64 elapsed = OSGetTime() - (lbl_805DE2F4 | ((s64) lbl_805DE2F0 << 32));
    lbl_80504418.draw_time = elapsed / (f32) (*(u32*) 0x800000F8 / 4 / 60);
}

void HSD_PerfSetTotalTime(void)
{
    s64 elapsed = OSGetTime() - (lbl_805DE2F4 | ((s64) lbl_805DE2F0 << 32));
    lbl_80504418.total_time = elapsed / (f32) (*(u32*) 0x800000F8 / 4 / 60);
}

void HSD_PerfCountEnvelopeBlending(s32 n)
{
    assert_line_named(164, n < 32, lbl_805DCCE8);
    lbl_80504418.env_blend[n]++;
}
