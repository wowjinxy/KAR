#include "dolphin/types.h"
#include "dolphin/os.h"

typedef s64 OSTime;
typedef u32 OSTick;

typedef struct OSThread
{
    u8 pad_00[0x308];
    u32* stackEnd;
} OSThread;

typedef struct OSCalendarTime
{
    int sec;
    int min;
    int hour;
    int mday;
    int mon;
    int year;
    int wday;
    int yday;

    int msec;
    int usec;
} OSCalendarTime;

extern void* OSGetStackPointer(void);

extern const int DaysToMonth365[12];
extern const int DaysToMonth366[12];

#define OS_CURRENT_THREAD (*(OSThread**)0x800000E4)
#define OS_BUS_CLOCK (*(volatile u32*)0x800000F8)
#define OS_TIME_BIAS (*(OSTime*)0x800030D8)
#define OS_TIME_SPEED (OS_BUS_CLOCK / 4)

#define BIAS 0xB2575

void OSClearStack(u8 val)
{
    u32 pattern = (val << 24) | (val << 16) | (val << 8) | val;
    u32* p;
    u32* end;

    end = (u32*)OSGetStackPointer();

    for (p = OS_CURRENT_THREAD->stackEnd + 1; p < end; p++)
    {
        *p = pattern;
    }
}

asm OSTime OSGetTime(void)
{
    nofralloc
    mftb r3, 269
    mftb r4, 268
    mftb r5, 269
    cmpw r3, r5
    bne OSGetTime
    blr
}

asm OSTick OSGetTick(void)
{
    nofralloc
    mftb r3, 268
    blr
}

OSTime __OSGetSystemTime(void)
{
    BOOL enabled;
    OSTime time;
    OSTime result;

    enabled = OSDisableInterrupts();
    time = OSGetTime() + OS_TIME_BIAS;
    result = time;
    OSRestoreInterrupts(enabled);
    return result;
}

OSTime __OSTimeToSystemTime(OSTime ticks)
{
    BOOL enabled;
    OSTime now;
    OSTime time;

    enabled = OSDisableInterrupts();
    now = ticks;
    time = OS_TIME_BIAS + now;
    OSRestoreInterrupts(enabled);
    return time;
}

void GetDates(int days, OSCalendarTime* td)
{
    int year;
    int daysBeforeYear;
    int leapDays;
    int dayOfYear;
    int isLeap;
    int mon;
    const int* table;

    td->wday = (days + 6) % 7;

    year = days / 365;
    daysBeforeYear = year * 365;

    while (TRUE)
    {
        leapDays = (year >= 1) ? (((year + 3) / 4) - ((year - 1) / 100) + ((year - 1) / 400)) : 0;

        if (days >= daysBeforeYear + leapDays)
        {
            break;
        }

        year--;
        daysBeforeYear -= 365;
    }

    td->year = year;

    dayOfYear = days - (daysBeforeYear + leapDays);
    td->yday = dayOfYear;

    isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    table = isLeap ? DaysToMonth366 : DaysToMonth365;

    mon = 12;
    do
    {
        mon--;
    } while (dayOfYear < table[mon]);

    td->mon = mon;
    td->mday = dayOfYear - table[mon] + 1;
}

void OSTicksToCalendarTime(OSTime ticks, OSCalendarTime* td)
{
    OSTime remainder;
    OSTime daySeconds;
    int days;
    int secOfDay;
    int totalMin;

    remainder = ticks % OS_TIME_SPEED;
    if (remainder < 0)
    {
        remainder += OS_TIME_SPEED;
    }

    td->usec = (int)((remainder * 8) / (OS_TIME_SPEED / 125000) % 1000);
    td->msec = (int)(remainder / (OS_TIME_SPEED / 1000) % 1000);

    daySeconds = ticks - remainder;

    days = (int)((daySeconds / OS_TIME_SPEED / 86400) + BIAS);
    secOfDay = (int)((daySeconds / OS_TIME_SPEED) % 86400);

    if (secOfDay < 0)
    {
        days -= 1;
        secOfDay += 86400;
    }

    GetDates(days, td);

    totalMin = secOfDay / 60;
    td->hour = totalMin / 60;
    td->min = totalMin % 60;
    td->sec = secOfDay % 60;
}
