#include <global.h>

#include <sysdolphin/forward.h>
#include <sysdolphin/rumble.h>

typedef struct PADStatus {
    u16 button;
    s8 stickX;
    s8 stickY;
    s8 substickX;
    s8 substickY;
    u8 triggerLeft;
    u8 triggerRight;
    u8 analogA;
    u8 analogB;
    s8 err;
} PADStatus;

struct HSD_PadData {
    PADStatus stat[4];
    u32 connect_mask;
};

struct HSD_PadStatus {
    u32 button;
    u32 last_button;
    u32 trigger;
    u32 repeat;
    u32 release;
    s32 repeat_count;
    s8 stickX;
    s8 stickY;
    s8 subStickX;
    s8 subStickY;
    u8 analogL;
    u8 analogR;
    u8 analogA;
    u8 analogB;
    f32 nml_stickX;
    f32 nml_stickY;
    f32 nml_subStickX;
    f32 nml_subStickY;
    f32 nml_analogL;
    f32 nml_analogR;
    f32 nml_analogA;
    f32 nml_analogB;
    u8 cross_dir;
    u8 reset_hit;
    s8 unk42;
    s8 err;
};

typedef enum HSD_FlushType {
    HSD_PAD_FLUSH_QUEUE_MERGE,
    HSD_PAD_FLUSH_QUEUE_THROWAWAY,
    HSD_PAD_FLUSH_QUEUE_LEAVE1,
} HSD_FlushType;

typedef struct {
    s8 valid;
    s8 chan;
} HSD_PadPortMap;

typedef struct {
    s32 state;
    u32 tick;
} HSD_PadResetTimer;

struct PadLibData {
    u8 qnum;             //0x00
    u8 qread;            //0x01
    u8 qwrite;           //0x02
    u8 qcount;           //0x03
    HSD_PadData* queue;  //0x04
    u8 qnum2;            //0x08
    u8 qread2;           //0x09
    u8 qwrite2;          //0x0A
    u8 qcount2;          //0x0B
    HSD_PadData* queue2; //0x0C
    u8 qtype;            //0x10
    u8 unk11;            //0x11
    HSD_PadPortMap port[4]; //0x12
    u8 unk1A[2];            //0x1A
    HSD_PadResetTimer reset_timer[4]; //0x1C
    s32 repeat_start;    //0x3C
    s32 repeat_interval; //0x40
    s8 adc_type;         //0x44
    s8 adc_th;           //0x45
    u8 unk46[2];
    f32 adc_angle;       //0x48
    u8 clamp_stickType;  //0x4C
    u8 clamp_stickShift; //0x4D
    s8 clamp_stickMax;   //0x4E
    s8 clamp_stickMin;   //0x4F
    u8 clamp_analogLRShift; //0x50
    u8 clamp_analogLRMax;   //0x51
    u8 clamp_analogLRMin;   //0x52
    u8 clamp_analogABShift; //0x53
    u8 clamp_analogABMax;   //0x54
    u8 clamp_analogABMin;   //0x55
    s8 scale_stick;      //0x56
    u8 scale_analogLR;   //0x57
    u8 scale_analogAB;   //0x58
    u8 cross_dir;        //0x59
    u8 reset_switch_status; //0x5A
    u8 reset_switch;     //0x5B
    u8 unk5C[8];         //0x5C
};

extern PadLibData HSD_PadState;
extern HSD_PadStatus HSD_PadMasterStatus[20];
extern HSD_PadStatus HSD_PadCopyStatus[20];

extern const u32 HSD_PadBit[4]; /* pad_bit */
extern HSD_PadStatus HSD_DefaultPadStatus; /* default_status_data */
extern PadLibData HSD_DefaultPadLibData;    /* default_libinfo_data */

extern u32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(u32 level);
extern u32 OSGetTick(void);
extern bool OSGetResetSwitchState(void);
extern u32 OSGetResetCode(void);
extern int PADRead(PADStatus* status);
extern void PADReset(u32 mask);
extern void PADRecalibrate(u32 mask);
extern void PADInit(void);

extern f64 kar_atan2(f64 y, f64 x); /* atan2 */
extern f64 __frsqrte(f64 x);
extern f64 __fnmsub(f64 a, f64 c, f64 b); /* = b - a*c */
extern f32 __fmadds(f32 a, f32 c, f32 b); /* = a*c + b */

extern f32 ControllerFloatHalf; /* 0.5F */
extern f64 ControllerDoubleUnsignedBias; /* 4503599627370496.0 */
extern f32 ControllerFloatZero; /* 0.0F */
extern f64 ControllerDoubleHalf; /* 0.5 */
extern f64 ControllerDoubleThree; /* 3.0 */
extern f32 ControllerFloatEpsilon; /* 1.000000013351432e-10F */
extern f32 ControllerFloatPiOver2; /* 1.5707963267948966F */
extern f32 ControllerFloatNegPiOver2; /* -1.5707963267948966F */
extern f64 ControllerDoubleNeg3PiOver4; /* -2.356194490192345 */
extern f64 ControllerDoubleNegPiOver4; /* -0.7853981633974483 */
extern f64 ControllerDoublePiOver4; /* 0.7853981633974483 */
extern f64 ControllerDouble3PiOver4; /* 2.356194490192345 */

#define OS_BUS_CLOCK (*(u32*) 0x800000F8)

static inline f64 u32_to_f64(u32 v)
{
    union {
        struct {
            u32 hi;
            u32 lo;
        } w;
        f64 d;
    } u;
    u.w.hi = 0x43300000;
    u.w.lo = v;
    return u.d - ControllerDoubleUnsignedBias;
}

static inline f32 controller_sqrtf(f32 x)
{
    volatile f32 y;

    if (x > ControllerFloatZero) {
        f64 guess = __frsqrte((f64) x);
        guess = ControllerDoubleHalf * guess * __fnmsub(x, guess * guess, ControllerDoubleThree);
        guess = ControllerDoubleHalf * guess * __fnmsub(x, guess * guess, ControllerDoubleThree);
        guess = ControllerDoubleHalf * guess * __fnmsub(x, guess * guess, ControllerDoubleThree);
        y = (f32) (x * guess);
        return y;
    }
    return x;
}

u8 HSD_PadGetRawQueueCount(void)
{
    PadLibData* p;
    u8 count;
    u32 intr;

    p = &HSD_PadState;
    intr = OSDisableInterrupts();
    count = p->qcount;
    OSRestoreInterrupts(intr);

    return count;
}

u8 HSD_PadGetMappedRawQueueCount(void)
{
    PadLibData* p;
    u8 count;
    u32 intr;

    p = &HSD_PadState;
    intr = OSDisableInterrupts();
    count = p->qcount2;
    OSRestoreInterrupts(intr);

    return count;
}

s32 HSD_PadGetResetSwitch(void)
{
    PadLibData* p = &HSD_PadState;

    return p->reset_switch != 0;
}

void HSD_PadReadStatus(HSD_PadData* now)
{
    PadLibData* p = &HSD_PadState;
    int i;

    now->connect_mask = PADRead(now->stat);

    for (i = 0; i < 4; i++) {
        if (now->stat[i].err == 0 && now->stat[i].button == 0x1600) {
            switch (p->reset_timer[i].state) {
            case 0:
                p->reset_timer[i].state = 1;
                p->reset_timer[i].tick = OSGetTick();
                break;
            case 1: {
                u32 elapsed = OSGetTick() - p->reset_timer[i].tick;
                if (u32_to_f64(elapsed) >=
                    ControllerFloatHalf * u32_to_f64(OS_BUS_CLOCK / 4)) {
                    p->reset_switch = 1;
                    p->reset_timer[i].state = 2;
                }
                break;
            }
            }
        } else {
            p->reset_timer[i].state = 0;
        }
    }
}

void HSD_PadPushRawQueue(int count, PadLibData* p,
                                                 HSD_PadData* queue,
                                                 HSD_PadData* now,
                                                 bool err_check)
{
    PadLibData* base = &HSD_PadState;
    HSD_PadData* qwrite;
    int i, c;

    if (err_check) {
        for (i = 0; i < count; i++) {
            int c;
            for (c = 0; c < 4; c++) {
                if (now[i].stat[c].err == 0) {
                    break;
                }
            }
            if (c == 4) {
                return;
            }
        }
    }

    qwrite = &queue[p->qwrite * count];

    if (p->qcount == p->qnum) {
        switch (base->qtype) {
        case 0: {
            p->qread = (p->qread + 1) % p->qnum;
            queue = &queue[p->qread * count];
            if (p->qnum != 1) {
                for (i = 0; i < count; i++) {
                    for (c = 0; c < 4; c++) {
                        queue[i].stat[c].button |= qwrite[i].stat[c].button;
                    }
                }
            } else {
                for (i = 0; i < count; i++) {
                    for (c = 0; c < 4; c++) {
                        now[i].stat[c].button |= queue[i].stat[c].button;
                    }
                }
            }
            break;
        }
        case 1:
            p->qread = (p->qread + 1) % p->qnum;
            break;
        case 2:
            return;
        }
    } else {
        p->qcount += 1;
    }

    for (i = 0; i < count; i++) {
        qwrite[i] = now[i];
    }
    p->qwrite = (p->qwrite + 1) % p->qnum;
}

void HSD_PadPushPrimaryRawQueue(HSD_PadData* now, bool err_check)
{
    PadLibData* p = &HSD_PadState;

    HSD_PadPushRawQueue(1, p, p->queue, now, err_check);
}

void HSD_PadPushMappedRawQueue(HSD_PadData* now, bool err_check)
{
    PadLibData* p = &HSD_PadState;

    HSD_PadPushRawQueue(4, (PadLibData*) &p->qnum2,
                                                p->queue2, now, err_check);
}

void HSD_PadResetRawErrorChannels(HSD_PadData* now)
{
    u32 mask = 0;
    int i;

    for (i = 0; i < 4; i++) {
        if (now->stat[i].err == -1) {
            mask |= HSD_PadBit[i];
        }
    }
    if (mask != 0) {
        PADReset(mask);
    }
}

void HSD_PadPollResetSwitch(void)
{
    PadLibData* p = &HSD_PadState;

    if (OSGetResetSwitchState()) {
        p->reset_switch_status = 1;
    } else {
        if (p->reset_switch_status != 0) {
            p->reset_switch = 1;
        }
        p->reset_switch_status = 0;
    }
}

void HSD_PadFlushQueue(HSD_FlushType ftype)
{
    PadLibData* p;
    HSD_PadData* queue;
    HSD_PadData* qread;
    HSD_PadData* qdst;
    u32 intr;
    int c;

    p = &HSD_PadState;
    queue = p->queue;
    intr = OSDisableInterrupts();
    switch (ftype) {
    case HSD_PAD_FLUSH_QUEUE_MERGE:
        for (; p->qcount > 1; p->qcount -= 1) {
            qread = &queue[p->qread];
            p->qread = (p->qread + 1) % p->qnum;
            qdst = &queue[p->qread];
            for (c = 0; c < 4; c++) {
                qdst->stat[c].button |= qread->stat[c].button;
            }
        }
        break;
    case HSD_PAD_FLUSH_QUEUE_THROWAWAY:
        p->qread = p->qwrite;
        p->qcount = 0;
        break;
    case HSD_PAD_FLUSH_QUEUE_LEAVE1:
        if (p->qcount > 1) {
            p->qread = p->qwrite != 0 ? p->qwrite - 1 : p->qnum - 1;
            p->qcount = 1;
        }
        break;
    }
    OSRestoreInterrupts(intr);
}

void HSD_PadFlushMappedQueue(HSD_FlushType ftype)
{
    PadLibData* p;
    HSD_PadData* queue2;
    HSD_PadData* qread;
    HSD_PadData* qdst;
    u32 intr;
    int i, c;

    p = &HSD_PadState;
    queue2 = p->queue2;
    intr = OSDisableInterrupts();
    switch (ftype) {
    case HSD_PAD_FLUSH_QUEUE_MERGE:
        for (; p->qcount2 > 1; p->qcount2 -= 1) {
            qread = &queue2[p->qread2 * 4];
            p->qread2 = (p->qread2 + 1) % p->qnum2;
            qdst = &queue2[p->qread2 * 4];
            for (i = 0; i < 4; i++) {
                for (c = 0; c < 4; c++) {
                    qdst[i].stat[c].button |= qread[i].stat[c].button;
                }
            }
        }
        break;
    case HSD_PAD_FLUSH_QUEUE_THROWAWAY:
        p->qread2 = p->qwrite2;
        p->qcount2 = 0;
        break;
    case HSD_PAD_FLUSH_QUEUE_LEAVE1:
        if (p->qcount2 > 1) {
            p->qread2 = p->qwrite2 != 0 ? p->qwrite2 - 1 : p->qnum2 - 1;
            p->qcount2 = 1;
        }
        break;
    }
    OSRestoreInterrupts(intr);
}

static inline void HSD_PadClampCheck1(u8* val, u8 shift, u8 min, u8 max)
{
    if (*val < min) {
        *val = 0;
        return;
    }
    if (*val > max) {
        *val = max;
    }
    if (shift != 1) {
        return;
    }
    *val = *val - min;
}

static inline void HSD_PadClampCheck3(s8* x, s8* y, u8 shift, s8 min, s8 max)
{
    f32 r;

    r = controller_sqrtf((f32) *x * (f32) *x + (f32) *y * (f32) *y);

    if (r < min) {
        *y = 0;
        *x = 0;
        return;
    }
    if (r > max) {
        *x = (s8) (((f32) *x * (f32) max) / r);
        *y = (s8) (((f32) *y * (f32) max) / r);
        r = controller_sqrtf((f32) *x * (f32) *x + (f32) *y * (f32) *y);
    }

    if (shift == 1 && r > ControllerFloatEpsilon) {
        *x = (s8) ((f32) *x - (((f32) *x * (f32) min) / r));
        *y = (s8) ((f32) *y - (((f32) *y * (f32) min) / r));
    }
}

void HSD_PadClamp(HSD_PadStatus* mp)
{
    PadLibData* p = &HSD_PadState;

    switch (p->clamp_stickType) {
    case 0:
        HSD_PadClampCheck3(&mp->stickX, &mp->stickY, p->clamp_stickShift,
                           p->clamp_stickMin, p->clamp_stickMax);
        HSD_PadClampCheck3(&mp->subStickX, &mp->subStickY, p->clamp_stickShift,
                           p->clamp_stickMin, p->clamp_stickMax);
        break;
    default:
        break;
    }
    HSD_PadClampCheck1(&mp->analogL, p->clamp_analogLRShift,
                       p->clamp_analogLRMin, p->clamp_analogLRMax);
    HSD_PadClampCheck1(&mp->analogR, p->clamp_analogLRShift,
                       p->clamp_analogLRMin, p->clamp_analogLRMax);
    HSD_PadClampCheck1(&mp->analogA, p->clamp_analogABShift,
                       p->clamp_analogABMin, p->clamp_analogABMax);
    HSD_PadClampCheck1(&mp->analogB, p->clamp_analogABShift,
                       p->clamp_analogABMin, p->clamp_analogABMax);
}

static inline void HSD_PadADConvertCheck1(HSD_PadStatus* mp, s8 x, s8 y, u32 up,
                                    u32 down, u32 left, u32 right)
{
    PadLibData* p = &HSD_PadState;
    f32 r;
    f32 a;
    f32 ha;

    r = controller_sqrtf(__fmadds((f32) x, (f32) x, (f32) y * (f32) y));

    if (ControllerFloatZero == (f32) x) {
        a = (f32) y >= ControllerFloatZero ? ControllerFloatPiOver2 : ControllerFloatNegPiOver2;
    } else {
        a = (f32) kar_atan2(y, x);
    }

    ha = ControllerFloatHalf * p->adc_angle;
    if (r < p->adc_th) {
        return;
    }

    if (a < ControllerDoubleNeg3PiOver4 + ha) {
        mp->button |= left;
    }
    if (a >= ControllerDoubleNeg3PiOver4 - ha && a <= ControllerDoubleNegPiOver4 + ha) {
        mp->button |= down;
    }
    if (a > ControllerDoubleNegPiOver4 - ha && a < ControllerDoublePiOver4 + ha) {
        mp->button |= right;
    }
    if (a >= ControllerDoublePiOver4 - ha && a <= ControllerDouble3PiOver4 + ha) {
        mp->button |= up;
    }
    if (a > ControllerDouble3PiOver4 - ha) {
        mp->button |= left;
    }
}

void HSD_PadADConvert(HSD_PadStatus* mp)
{
    PadLibData* p = &HSD_PadState;

    switch (p->adc_type) {
    case 0:
        HSD_PadADConvertCheck1(mp, mp->stickX, mp->stickY, 0x10000, 0x20000,
                                0x40000, 0x80000);
        HSD_PadADConvertCheck1(mp, mp->subStickX, mp->subStickY, 0x100000,
                                0x200000, 0x400000, 0x800000);
        break;
    default:
        return;
    }
}

static inline void HSD_PadScale(HSD_PadStatus* mp)
{
    PadLibData* p = &HSD_PadState;

    mp->nml_stickX = (f32) mp->stickX / (f32) p->scale_stick;
    mp->nml_stickY = (f32) mp->stickY / (f32) p->scale_stick;
    mp->nml_subStickX = (f32) mp->subStickX / (f32) p->scale_stick;
    mp->nml_subStickY = (f32) mp->subStickY / (f32) p->scale_stick;
    mp->nml_analogL = (f32) mp->analogL / (f32) p->scale_analogLR;
    mp->nml_analogR = (f32) mp->analogR / (f32) p->scale_analogLR;
    mp->nml_analogA = (f32) mp->analogA / (f32) p->scale_analogAB;
    mp->nml_analogB = (f32) mp->analogB / (f32) p->scale_analogAB;
}

static inline void HSD_PadCrossDir(HSD_PadStatus* mp)
{
    PadLibData* p = &HSD_PadState;

    switch (p->cross_dir) {
    case 0:
        break;
    case 1:
        if ((mp->button & 0x30000) == 0) {
            return;
        }
        mp->button = mp->button & 0xFFF3FFFF;
        return;
    case 2:
        if ((mp->button & 0xC0000) == 0) {
            return;
        }
        mp->button = mp->button & 0xFFFCFFFF;
        return;
    case 3:
        if ((mp->button & 0x30000) != 0) {
            if ((mp->button & 0xC0000) != 0) {
                if (mp->cross_dir == 1) {
                    mp->button = mp->button & 0xFFF3FFFF;
                    return;
                }
                mp->button = mp->button & 0xFFFCFFFF;
                return;
            } else {
                mp->cross_dir = 1;
                return;
            }
        }
        if ((mp->button & 0xC0000) != 0) {
            mp->cross_dir = 2;
            return;
        }
    }
}

void HSD_PadRenewMasterStatusFromQueue(int count, PadLibData* p,
                                                          HSD_PadData* queue,
                                                          HSD_PadStatus* mp)
{
    PadLibData* base = &HSD_PadState;
    HSD_PadData* qread;
    int i, c;
    u32 intr;

    intr = OSDisableInterrupts();
    if (p->qcount != 0) {
        qread = &queue[p->qread];
        p->qread = (p->qread + 1) % p->qnum;
        p->qcount -= 1;

        for (i = 0; i < count; i++, qread++) {
            u32 mask = qread->connect_mask;

            for (c = 0; c < 4; c++, mp++) {
                mp->last_button = mp->button;
                mp->reset_hit = (mask & HSD_PadBit[c]) != 0;
                mp->unk42 = -1;
                mp->err = qread->stat[c].err;
                if (mp->err == 0) {
                    mp->button = qread->stat[c].button;
                    mp->stickX = qread->stat[c].stickX;
                    mp->stickY = qread->stat[c].stickY;
                    mp->subStickX = qread->stat[c].substickX;
                    mp->subStickY = qread->stat[c].substickY;
                    mp->analogL = qread->stat[c].triggerLeft;
                    mp->analogR = qread->stat[c].triggerRight;
                    mp->analogA = qread->stat[c].analogA;
                    mp->analogB = qread->stat[c].analogB;
                    HSD_PadClamp(mp);
                    HSD_PadADConvert(mp);
                    HSD_PadScale(mp);
                    HSD_PadCrossDir(mp);
                } else if (mp->err == -3) {
                    mp->err = 0;
                } else {
                    mp->button = 0;
                    mp->subStickY = 0;
                    mp->subStickX = 0;
                    mp->stickY = 0;
                    mp->stickX = 0;
                    mp->analogB = 0;
                    mp->analogA = 0;
                    mp->analogR = 0;
                    mp->analogL = 0;
                    mp->nml_subStickY = 0.0F;
                    mp->nml_subStickX = 0.0F;
                    mp->nml_stickY = 0.0F;
                    mp->nml_stickX = 0.0F;
                    mp->nml_analogB = 0.0F;
                    mp->nml_analogA = 0.0F;
                    mp->nml_analogR = 0.0F;
                    mp->nml_analogL = 0.0F;
                }
                mp->trigger = mp->button & (mp->last_button ^ mp->button);
                mp->release = mp->last_button & (mp->last_button ^ mp->button);
                if (mp->last_button ^ mp->button) {
                    mp->repeat = mp->trigger;
                    mp->repeat_count = base->repeat_start;
                } else {
                    s32 repeat_count = mp->repeat_count - 1;
                    mp->repeat_count = repeat_count;
                    if (repeat_count != 0) {
                        mp->repeat = 0;
                    } else {
                        mp->repeat = mp->button;
                        mp->repeat_count = base->repeat_interval;
                    }
                }
            }
        }
    }
    OSRestoreInterrupts(intr);
}

void HSD_PadRenewMasterStatus(void)
{
    PadLibData* p = &HSD_PadState;

    HSD_PadRenewMasterStatusFromQueue(1, p, p->queue,
                                                          &HSD_PadMasterStatus[0]);
}

void HSD_PadRenewMappedMasterStatus(void)
{
    PadLibData* p = &HSD_PadState;
    int i;

    HSD_PadRenewMasterStatusFromQueue(
        4, (PadLibData*) &p->qnum2, p->queue2, &HSD_PadMasterStatus[4]);

    for (i = 0; i < 4; i++) {
        s8 valid = p->port[i].valid;
        HSD_PadStatus tmp;

        if (valid == -1) {
            tmp = HSD_DefaultPadStatus;
        } else {
            s8 chan = p->port[i].chan;
            tmp = HSD_PadMasterStatus[(valid + 1) * 4 + chan];
            HSD_PadMasterStatus[(valid + 1) * 4 + chan].unk42 = i;
        }

        HSD_PadMasterStatus[i] = tmp;
    }
}

void HSD_PadCopyStatusWithRepeat(int count, HSD_PadStatus* mp,
                                                   HSD_PadStatus* cp)
{
    PadLibData* p = &HSD_PadState;
    int i, c;

    for (i = 0; i < count; i++) {
        for (c = 0; c < 4; c++, mp++, cp++) {
            cp->last_button = cp->button;
            cp->err = mp->err;
            cp->reset_hit = mp->reset_hit;
            cp->unk42 = -1;
            if (cp->err == 0) {
                cp->button = mp->button;
                cp->stickX = mp->stickX;
                cp->stickY = mp->stickY;
                cp->subStickX = mp->subStickX;
                cp->subStickY = mp->subStickY;
                cp->analogL = mp->analogL;
                cp->analogR = mp->analogR;
                cp->analogA = mp->analogA;
                cp->analogB = mp->analogB;
                cp->nml_stickX = mp->nml_stickX;
                cp->nml_stickY = mp->nml_stickY;
                cp->nml_subStickX = mp->nml_subStickX;
                cp->nml_subStickY = mp->nml_subStickY;
                cp->nml_analogL = mp->nml_analogL;
                cp->nml_analogR = mp->nml_analogR;
                cp->nml_analogA = mp->nml_analogA;
                cp->nml_analogB = mp->nml_analogB;
            } else {
                cp->button = 0;
                cp->subStickY = 0;
                cp->subStickX = 0;
                cp->stickY = 0;
                cp->stickX = 0;
                cp->analogB = 0;
                cp->analogA = 0;
                cp->analogR = 0;
                cp->analogL = 0;
                cp->nml_subStickY = 0.0F;
                cp->nml_subStickX = 0.0F;
                cp->nml_stickY = 0.0F;
                cp->nml_stickX = 0.0F;
                cp->nml_analogB = 0.0F;
                cp->nml_analogA = 0.0F;
                cp->nml_analogR = 0.0F;
                cp->nml_analogL = 0.0F;
            }
            cp->trigger = cp->button & (cp->last_button ^ cp->button);
            cp->release = cp->last_button & (cp->last_button ^ cp->button);
            if (cp->last_button ^ cp->button) {
                cp->repeat = cp->trigger;
                cp->repeat_count = p->repeat_start;
            } else {
                s32 repeat_count = cp->repeat_count - 1;
                cp->repeat_count = repeat_count;
                if (repeat_count != 0) {
                    cp->repeat = 0;
                } else {
                    cp->repeat = cp->button;
                    cp->repeat_count = p->repeat_interval;
                }
            }
        }
    }
}

void HSD_PadRenewCopyStatus(void)
{
    HSD_PadCopyStatusWithRepeat(1, &HSD_PadMasterStatus[0],
                                                  &HSD_PadCopyStatus[0]);
}

void HSD_PadRenewMappedCopyStatus(void)
{
    PadLibData* p = &HSD_PadState;
    HSD_PadStatus* mp = (HSD_PadStatus*) ((u8*) p + 0x64);
    HSD_PadStatus* cp = (HSD_PadStatus*) ((u8*) p + 0x5B4);
    HSD_PadStatus tmp;
    int i;

    HSD_PadCopyStatusWithRepeat(4, mp + 4, cp + 4);

    for (i = 0; i < 4; i++) {
        s8 valid = p->port[i].valid;

        if (valid == -1) {
            tmp = HSD_DefaultPadStatus;
        } else {
            s8 chan = p->port[i].chan;
            tmp = mp[(valid + 1) * 4 + chan];
            mp[(valid + 1) * 4 + chan].unk42 = i;
        }

        cp[i] = tmp;
    }
}

void HSD_PadClearMasterStatus(void)
{
    HSD_PadStatus* dst = HSD_PadMasterStatus;
    int i;

    for (i = 0; i < 4; i++, dst++) {
        *dst = HSD_DefaultPadStatus;
    }
}

void HSD_PadClearMappedMasterStatus(void)
{
    HSD_PadStatus* dst = &HSD_PadMasterStatus[4];
    int g, i;

    for (g = 0; g < 4; g++) {
        for (i = 0; i < 4; i++, dst++) {
            *dst = HSD_DefaultPadStatus;
        }
    }
}

void HSD_PadClearCopyStatus(void)
{
    HSD_PadStatus* dst = HSD_PadCopyStatus;
    int i;

    for (i = 0; i < 4; i++, dst++) {
        *dst = HSD_DefaultPadStatus;
    }
}

void HSD_PadClearMappedCopyStatus(void)
{
    HSD_PadStatus* dst = &HSD_PadCopyStatus[4];
    int g, i;

    for (g = 0; g < 4; g++) {
        for (i = 0; i < 4; i++, dst++) {
            *dst = HSD_DefaultPadStatus;
        }
    }
}

void HSD_PadReset(void)
{
    PadLibData* p;
    u32 intr;
    int i;

    p = &HSD_PadState;
    intr = OSDisableInterrupts();

    HSD_PadRumbleRemoveAll();

    for (i = 0; i < 4; i++) {
        HSD_PadRumbleOffN(i);
    }

    HSD_PadFlushQueue(HSD_PAD_FLUSH_QUEUE_THROWAWAY);
    HSD_PadFlushMappedQueue(HSD_PAD_FLUSH_QUEUE_THROWAWAY);

    PADRecalibrate(0xF0000000);

    p->unk11 = 0;
    p->port[0].valid = 0;
    p->port[0].chan = 0;
    p->port[1].valid = 0;
    p->port[1].chan = 1;
    p->port[2].valid = 0;
    p->port[2].chan = 2;
    p->port[3].valid = 0;
    p->port[3].chan = 3;
    p->reset_switch = 0;
    OSRestoreInterrupts(intr);
}

void HSD_PadInit(u8 qnum, HSD_PadData* queue, HSD_PadData* queue2, u16 nb_list,
                 HSD_PadRumbleListData* listdatap)
{
    PadLibData* p = &HSD_PadState;
    int i;

    *p = HSD_DefaultPadLibData;
    p->qnum = qnum;
    p->queue = queue;
    p->qnum2 = qnum;
    p->queue2 = queue2;

    if (OSGetResetCode() == 0x80000000) {
        p->reset_timer[0].state = 2;
        p->reset_timer[1].state = 2;
        p->reset_timer[2].state = 2;
        p->reset_timer[3].state = 2;
    }

    HSD_PadRumbleInit(nb_list, listdatap);

    {
        HSD_PadStatus* dst = HSD_PadMasterStatus;
        for (i = 0; i < 4; i++, dst++) {
            *dst = HSD_DefaultPadStatus;
        }
    }
    {
        HSD_PadStatus* dst = &HSD_PadMasterStatus[4];
        int g;
        for (g = 0; g < 4; g++) {
            for (i = 0; i < 4; i++, dst++) {
                *dst = HSD_DefaultPadStatus;
            }
        }
    }
    {
        HSD_PadStatus* dst = HSD_PadCopyStatus;
        for (i = 0; i < 4; i++, dst++) {
            *dst = HSD_DefaultPadStatus;
        }
    }
    {
        HSD_PadStatus* dst = &HSD_PadCopyStatus[4];
        int g;
        for (g = 0; g < 4; g++) {
            for (i = 0; i < 4; i++, dst++) {
                *dst = HSD_DefaultPadStatus;
            }
        }
    }

    PADInit();
}
