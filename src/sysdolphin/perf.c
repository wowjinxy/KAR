#include <global.h>
#include <sysdolphin/perf.h>

void memset(void*, int, int);
extern s64 OSGetTime(void);

extern HSD_PerfStat HSD_PerfLastStat;
extern HSD_PerfStat HSD_PerfCurrentStat;

extern u32 PerfStartTimeHi;
extern u32 PerfStartTimeLo;

extern char PerfSourceFile[7];  // "perf.c"
extern char PerfAssertCount[7]; // "n < 32"

#define assert_line_named(line, cond, condstr)                                 \
    ((cond) ? ((void) 0) : __assert(PerfSourceFile, line, condstr))

void HSD_PerfInitStat(void)
{
    HSD_PerfLastStat = HSD_PerfCurrentStat;
    memset(&HSD_PerfCurrentStat, 0, sizeof(HSD_PerfStat));
}

void HSD_PerfSetStartTime(void)
{
    s64 now = OSGetTime();
    PerfStartTimeLo = (u32) now;
    PerfStartTimeHi = (u32) (now >> 32);
}

void HSD_PerfSetCPUTime(void)
{
    s64 elapsed = OSGetTime() - (PerfStartTimeLo | ((s64) PerfStartTimeHi << 32));
    HSD_PerfCurrentStat.cpu_time = elapsed / (f32) (*(u32*) 0x800000F8 / 4 / 60);
}

void HSD_PerfSetDrawTime(void)
{
    s64 elapsed = OSGetTime() - (PerfStartTimeLo | ((s64) PerfStartTimeHi << 32));
    HSD_PerfCurrentStat.draw_time = elapsed / (f32) (*(u32*) 0x800000F8 / 4 / 60);
}

void HSD_PerfSetTotalTime(void)
{
    s64 elapsed = OSGetTime() - (PerfStartTimeLo | ((s64) PerfStartTimeHi << 32));
    HSD_PerfCurrentStat.total_time = elapsed / (f32) (*(u32*) 0x800000F8 / 4 / 60);
}

void HSD_PerfCountEnvelopeBlending(s32 n)
{
    assert_line_named(164, n < 32, PerfAssertCount);
    HSD_PerfCurrentStat.env_blend[n]++;
}
