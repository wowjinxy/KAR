#include "dolphin/types.h"
#include "dolphin/os.h"
#include "dolphin/pad.h"
#include "dolphin/si.h"

typedef s64 OSTime;

typedef struct OSContext {
    /* 0x000 */ u32 gpr[32];
    /* 0x080 */ u32 cr;
    /* 0x084 */ u32 lr;
    /* 0x088 */ u32 ctr;
    /* 0x08C */ u32 xer;
    /* 0x090 */ f64 fpr[32];
    /* 0x190 */ u32 fpscr_pad;
    /* 0x194 */ u32 fpscr;
    /* 0x198 */ u32 srr0;
    /* 0x19C */ u32 srr1;
    /* 0x1A0 */ u16 mode;
    /* 0x1A2 */ u16 state;
    /* 0x1A4 */ u32 gqr[8];
    /* 0x1C4 */ u32 psf_pad;
    /* 0x1C8 */ f64 psf[32];
} OSContext;

extern void OSClearContext(OSContext* context);
extern void OSSetCurrentContext(OSContext* context);
extern OSTime OSGetTime(void);
extern void* memset(void* dst, int val, size_t n);

typedef struct OSResetFunctionInfo OSResetFunctionInfo;
typedef BOOL (*OSResetFunction)(BOOL);
struct OSResetFunctionInfo {
    OSResetFunction func;
    u32 priority;
    OSResetFunctionInfo* next;
    OSResetFunctionInfo* prev;
};
extern void OSRegisterResetFunction(OSResetFunctionInfo* info);

extern char __PADVersion[];
extern u32 __PADFixBits;

extern vu16 __OSWirelessPadFixMode : 0x800030E0;
extern vu8 __gUnknown800030E3 : 0x800030E3;

#define SI_MAX_CHAN 4

#define SI_ERROR_UNDER_RUN 0x0001
#define SI_ERROR_OVER_RUN 0x0002
#define SI_ERROR_COLLISION 0x0004
#define SI_ERROR_NO_RESPONSE 0x0008

#define SI_TYPE_MASK 0x18000000u
#define SI_TYPE_GC 0x08000000u
#define SI_GC_WIRELESS 0x80000000u
#define SI_GC_NOMOTOR 0x20000000u
#define SI_GC_STANDARD 0x01000000u
#define SI_GC_CONTROLLER (SI_TYPE_GC | SI_GC_STANDARD)
#define SI_WIRELESS_RECEIVED 0x40000000u
#define SI_WIRELESS_IR 0x04000000u
#define SI_WIRELESS_FIX_ID 0x00100000u
#define SI_WIRELESS_LITE 0x00040000u
#define SI_WIRELESS_CONT_MASK 0x00080000u
#define SI_WIRELESS_CONT 0x00000000u

typedef struct PADClampRegion {
    u8 minTrigger;
    u8 maxTrigger;
    s8 minStick;
    s8 maxStick;
    s8 xyStick;
    s8 minSubstick;
    s8 maxSubstick;
    s8 xySubstick;
    s8 radStick;
    s8 radSubstick;
} PADClampRegion;

typedef void (*PADSamplingCallback)(void);
typedef void (*SPECCallback)(s32 chan, PADStatus* status, u32* data);

void PADTypeAndStatusCallback(s32 chan, u32 type);
void PADSetSpec(u32 spec);
void fn_803DCDB8(s32 chan, PADStatus* status, u32* data);
void fn_803DCF2C(s32 chan, PADStatus* status, u32* data);
void fn_803DD0A0(s32 chan, PADStatus* status, u32* data);
BOOL fn_803DD498(BOOL final);
void fn_803DD62C(u32 interrupt, OSContext* context);
PADSamplingCallback PADSetSamplingCallback(PADSamplingCallback callback);

static const PADClampRegion lbl_8048C448 = {
    30, 180, 15, 72, 40, 15, 59, 31, 56, 44,
}; /* ClampRegion */

static inline void ClampTrigger(u8* trigger, u8 min, u8 max) {
    if (*trigger <= min) {
        *trigger = 0;
    } else {
        if (max < *trigger) {
            *trigger = max;
        }
        *trigger -= min;
    }
}

void kar_osthread__near_803dba28(s8* px, s8* py, s8 max, s8 xy, s8 min) {
    int x = *px;
    int y = *py;
    int signX;
    int signY;
    int d;

    if (0 <= x) {
        signX = 1;
    } else {
        signX = -1;
        x = -x;
    }

    if (0 <= y) {
        signY = 1;
    } else {
        signY = -1;
        y = -y;
    }

    if (x <= min) {
        x = 0;
    } else {
        x -= min;
    }
    if (y <= min) {
        y = 0;
    } else {
        y -= min;
    }

    if (x == 0 && y == 0) {
        *px = *py = 0;
        return;
    }

    if (xy * y <= xy * x) {
        d = xy * x + (max - xy) * y;
        if (xy * max < d) {
            x = (s8)(xy * max * x / d);
            y = (s8)(xy * max * y / d);
        }
    } else {
        d = xy * y + (max - xy) * x;
        if (xy * max < d) {
            x = (s8)(xy * max * x / d);
            y = (s8)(xy * max * y / d);
        }
    }

    *px = (s8)(signX * x);
    *py = (s8)(signY * y);
}

void PADClamp(PADStatus* status) {
    int i;

    for (i = 0; i < 4; i++, status++) {
        if (status->err == PAD_ERR_NONE) {
            kar_osthread__near_803dba28(&status->stickX, &status->stickY, lbl_8048C448.maxStick,
                                         lbl_8048C448.xyStick, lbl_8048C448.minStick);
            kar_osthread__near_803dba28(&status->substickX, &status->substickY, lbl_8048C448.maxSubstick,
                                         lbl_8048C448.xySubstick, lbl_8048C448.minSubstick);
            ClampTrigger(&status->triggerLeft, lbl_8048C448.minTrigger, lbl_8048C448.maxTrigger);
            ClampTrigger(&status->triggerRight, lbl_8048C448.minTrigger, lbl_8048C448.maxTrigger);
        }
    }
}

BOOL lbl_805DDF40; /* Initialized */
u32 lbl_805DDF44; /* EnabledBits */
u32 lbl_805DDF48; /* ResettingBits */
u32 lbl_805DDF4C; /* RecalibrateBits */
u32 lbl_805DDF50; /* WaitingBits */
u32 lbl_805DDF54; /* CheckingBits */
u32 lbl_805DDF58; /* PendingBits */
PADSamplingCallback lbl_805DDF5C; /* SamplingCallback */
BOOL lbl_805DDF60; /* recalibrated */

static u32 lbl_8056E350[4]; /* Type */
static PADStatus lbl_8056E360[4]; /* Origin */
static u32 lbl_8056E390[4]; /* CmdProbeDevice */

char* lbl_805DC9A8 = __PADVersion; /* __PADVersion */
s32 lbl_805DC9AC = 0x20; /* ResettingChan */
u32 lbl_805DC9B0 = PAD_CHAN0_BIT | PAD_CHAN1_BIT | PAD_CHAN2_BIT | PAD_CHAN3_BIT; /* XPatchBits */
u32 lbl_805DC9B4 = 0x300; /* AnalogMode */
u32 lbl_805DC9B8 = PAD_SPEC_5; /* Spec */

SPECCallback lbl_805DC9BC = fn_803DD0A0; /* MakeStatus */

u16 lbl_805DC9C0 = 0x4100; /* CmdReadOrigin */
u16 lbl_805DC9C4 = 0x4200; /* CmdCalibrate */

u32 __PADSpec;

OSResetFunctionInfo lbl_804FC530 = {
    fn_803DD498,
    127,
    NULL,
    NULL,
}; /* ResetFunctionInfo */

static inline void DoReset(void) {
    u32 chanBit;

    lbl_805DC9AC = __cntlzw(lbl_805DDF48);
    if (lbl_805DC9AC != 32) {
        chanBit = PAD_CHAN0_BIT >> lbl_805DC9AC;
        lbl_805DDF48 &= ~chanBit;

        memset(&lbl_8056E360[lbl_805DC9AC], 0, sizeof(PADStatus));
        SIGetTypeAsync(lbl_805DC9AC, PADTypeAndStatusCallback);
    }
}

static inline void PADEnable(s32 chan) {
    u32 cmd;
    u32 chanBit;
    u32 data[2];

    chanBit = PAD_CHAN0_BIT >> chan;
    lbl_805DDF44 |= chanBit;
    SIGetResponse(chan, data);
    cmd = (lbl_805DC9B4 | 0x400000);
    SISetCommand(chan, cmd);
    SIEnablePolling(lbl_805DDF44);
}

static inline void PADDisable(s32 chan) {
    BOOL enabled;
    u32 chanBit;

    enabled = OSDisableInterrupts();
    chanBit = PAD_CHAN0_BIT >> chan;
    SIDisablePolling(chanBit);
    lbl_805DDF44 &= ~chanBit;
    lbl_805DDF50 &= ~chanBit;
    lbl_805DDF54 &= ~chanBit;
    lbl_805DDF58 &= ~chanBit;
    OSSetWirelessID(chan, 0);
    OSRestoreInterrupts(enabled);
}

void kar_osthread__near_803dbc6c(s32 chan) {
    PADStatus* origin;
    u32 chanBit = PAD_CHAN0_BIT >> chan;

    origin = &lbl_8056E360[chan];
    switch (lbl_805DC9B4 & 0x00000700u) {
    case 0x00000000u:
    case 0x00000500u:
    case 0x00000600u:
    case 0x00000700u:
        origin->triggerLeft &= ~15;
        origin->triggerRight &= ~15;
        origin->analogA &= ~15;
        origin->analogB &= ~15;
        break;
    case 0x00000100u:
        origin->substickX &= ~15;
        origin->substickY &= ~15;
        origin->analogA &= ~15;
        origin->analogB &= ~15;
        break;
    case 0x00000200u:
        origin->substickX &= ~15;
        origin->substickY &= ~15;
        origin->triggerLeft &= ~15;
        origin->triggerRight &= ~15;
        break;
    case 0x00000300u:
        break;
    case 0x00000400u:
        break;
    }

    origin->stickX -= 128;
    origin->stickY -= 128;
    origin->substickX -= 128;
    origin->substickY -= 128;

    if (lbl_805DC9B0 & chanBit) {
        if (64 < origin->stickX && (SIGetType(chan) & 0xFFFF0000) == SI_GC_CONTROLLER) {
            origin->stickX = 0;
        }
    }
}

void PADOriginCallback(s32 chan, u32 error, OSContext* context) {
    if (!(error & (SI_ERROR_UNDER_RUN | SI_ERROR_OVER_RUN | SI_ERROR_NO_RESPONSE | SI_ERROR_COLLISION))) {
        kar_osthread__near_803dbc6c(lbl_805DC9AC);
        PADEnable(lbl_805DC9AC);
    }

    DoReset();
}

void PADOriginUpdateCallback(s32 chan, u32 error, OSContext* context) {
    if (!(lbl_805DDF44 & (PAD_CHAN0_BIT >> chan))) {
        return;
    }
    if (!(error & (SI_ERROR_UNDER_RUN | SI_ERROR_OVER_RUN | SI_ERROR_NO_RESPONSE | SI_ERROR_COLLISION))) {
        kar_osthread__near_803dbc6c(chan);
    }
    if (error & SI_ERROR_NO_RESPONSE) {
        PADDisable(chan);
    }
}

void PADProbeCallback(s32 chan, u32 error, OSContext* context) {
    if (!(error & (SI_ERROR_UNDER_RUN | SI_ERROR_OVER_RUN | SI_ERROR_NO_RESPONSE | SI_ERROR_COLLISION))) {
        PADEnable(lbl_805DC9AC);
        lbl_805DDF50 |= PAD_CHAN0_BIT >> lbl_805DC9AC;
    }

    DoReset();
}

void PADTypeAndStatusCallback(s32 chan, u32 type) {
    u32 chanBit;
    u32 recalibrate;
    BOOL rc = TRUE;
    u32 error;

    chanBit = PAD_CHAN0_BIT >> lbl_805DC9AC;
    error = type & 0xFF;

    recalibrate = lbl_805DDF4C & chanBit;
    lbl_805DDF4C &= ~chanBit;

    if (error & (SI_ERROR_UNDER_RUN | SI_ERROR_OVER_RUN | SI_ERROR_NO_RESPONSE | SI_ERROR_COLLISION)) {
        DoReset();
        return;
    }

    type &= ~0xFF;
    lbl_8056E350[lbl_805DC9AC] = type;

    if ((type & SI_TYPE_MASK) != SI_TYPE_GC || !(type & SI_GC_STANDARD)) {
        DoReset();
        return;
    }

    if (lbl_805DC9B8 < PAD_SPEC_2) {
        PADEnable(lbl_805DC9AC);
        DoReset();
        return;
    }

    if (!(type & SI_GC_WIRELESS) || (type & SI_WIRELESS_IR)) {
        if (recalibrate) {
            rc = SITransfer(lbl_805DC9AC, &lbl_805DC9C4, 3, &lbl_8056E360[lbl_805DC9AC], 10, PADOriginCallback, 0);
        } else {
            rc = SITransfer(lbl_805DC9AC, &lbl_805DC9C0, 1, &lbl_8056E360[lbl_805DC9AC], 10, PADOriginCallback, 0);
        }
    } else if ((type & SI_WIRELESS_FIX_ID) && (type & SI_WIRELESS_CONT_MASK) == SI_WIRELESS_CONT &&
               !(type & SI_WIRELESS_LITE)) {
        if (type & SI_WIRELESS_RECEIVED) {
            rc = SITransfer(lbl_805DC9AC, &lbl_805DC9C0, 1, &lbl_8056E360[lbl_805DC9AC], 10, PADOriginCallback, 0);
        } else {
            rc = SITransfer(lbl_805DC9AC, &lbl_8056E390[lbl_805DC9AC], 3, &lbl_8056E360[lbl_805DC9AC], 8,
                             PADProbeCallback, 0);
        }
    }

    if (!rc) {
        lbl_805DDF58 |= chanBit;
        DoReset();
        return;
    }
}

void PADReceiveCheckCallback(s32 chan, u32 type) {
    u32 error;
    u32 chanBit;

    chanBit = PAD_CHAN0_BIT >> chan;

    if (lbl_805DDF44 & chanBit) {
        error = type & 0xFF;
        type &= ~0xFF;

        lbl_805DDF50 &= ~chanBit;
        lbl_805DDF54 &= ~chanBit;

        if (!(error & (SI_ERROR_UNDER_RUN | SI_ERROR_OVER_RUN | SI_ERROR_NO_RESPONSE | SI_ERROR_COLLISION)) &&
            (type & SI_GC_WIRELESS) && (type & SI_WIRELESS_FIX_ID) && (type & SI_WIRELESS_RECEIVED) &&
            !(type & SI_WIRELESS_IR) && (type & SI_WIRELESS_CONT_MASK) == SI_WIRELESS_CONT &&
            !(type & SI_WIRELESS_LITE)) {
            SITransfer(chan, &lbl_805DC9C0, 1, &lbl_8056E360[chan], 10, PADOriginUpdateCallback, 0);
        } else {
            PADDisable(chan);
        }
    }
}

int PADReset(u32 mask) {
    BOOL enabled;
    u32 disableBits;

    enabled = OSDisableInterrupts();
    mask |= lbl_805DDF58;
    lbl_805DDF58 = 0;
    mask &= ~(lbl_805DDF50 | lbl_805DDF54);
    lbl_805DDF48 |= mask;
    disableBits = lbl_805DDF48 & lbl_805DDF44;
    lbl_805DDF44 &= ~mask;

    if (lbl_805DC9B8 == 4) {
        lbl_805DDF4C |= mask;
    }

    SIDisablePolling(disableBits);

    if (lbl_805DC9AC == 0x20) {
        DoReset();
    }

    OSRestoreInterrupts(enabled);
    return 1;
}

BOOL PADRecalibrate(u32 mask) {
    BOOL enabled;
    u32 disableBits;

    enabled = OSDisableInterrupts();

    mask |= lbl_805DDF58;
    lbl_805DDF58 = 0;
    mask &= ~(lbl_805DDF50 | lbl_805DDF54);
    lbl_805DDF48 |= mask;
    disableBits = lbl_805DDF48 & lbl_805DDF44;
    lbl_805DDF44 &= ~mask;

    if (!(__gUnknown800030E3 & 0x40)) {
        lbl_805DDF4C |= mask;
    }

    SIDisablePolling(disableBits);
    if (lbl_805DC9AC == 32) {
        DoReset();
    }

    OSRestoreInterrupts(enabled);
    return 1;
}

BOOL PADInit(void) {
    s32 chan;
    if (lbl_805DDF40) {
        return 1;
    }

    OSRegisterVersion(lbl_805DC9A8);

    if (__PADSpec) {
        PADSetSpec(__PADSpec);
    }

    lbl_805DDF40 = TRUE;

    if (__PADFixBits != 0) {
        OSTime time = OSGetTime();
        __OSWirelessPadFixMode =
            (u16)((((time)&0xffff) + ((time >> 16) & 0xffff) + ((time >> 32) & 0xffff) + ((time >> 48) & 0xffff)) &
                  0x3fffu);

        lbl_805DDF4C = PAD_CHAN0_BIT | PAD_CHAN1_BIT | PAD_CHAN2_BIT | PAD_CHAN3_BIT;
    }

    for (chan = 0; chan < SI_MAX_CHAN; ++chan) {
        lbl_8056E390[chan] = (0x4D << 24) | (chan << 22) | ((__OSWirelessPadFixMode & 0x3fffu) << 8);
    }

    SIRefreshSamplingRate();
    OSRegisterResetFunction(&lbl_804FC530);

    return PADReset(PAD_CHAN0_BIT | PAD_CHAN1_BIT | PAD_CHAN2_BIT | PAD_CHAN3_BIT);
}

u32 PADRead(PADStatus* status) {
    BOOL enabled;
    s32 chan;
    u32 data[2];
    u32 chanBit;
    u32 sr;
    u32 motor;

    enabled = OSDisableInterrupts();
    motor = 0;

    for (chan = 0; chan < 4; chan++, status++) {
        chanBit = PAD_CHAN0_BIT >> chan;

        if (lbl_805DDF58 & chanBit) {
            PADReset(0);
            status->err = PAD_ERR_NOT_READY;
            memset(status, 0, 10);
        } else if ((lbl_805DDF48 & chanBit) || lbl_805DC9AC == chan) {
            status->err = PAD_ERR_NOT_READY;
            memset(status, 0, 10);
        } else if (!(lbl_805DDF44 & chanBit)) {
            status->err = PAD_ERR_NO_CONTROLLER;
            memset(status, 0, 10);
        } else if (SIIsChanBusy(chan)) {
            status->err = PAD_ERR_TRANSFER;
            memset(status, 0, 10);
        } else {
            sr = SIGetStatus(chan);
            if (sr & SI_ERROR_NO_RESPONSE) {
                SIGetResponse(chan, data);

                if (lbl_805DDF50 & chanBit) {
                    status->err = PAD_ERR_NONE;
                    memset(status, 0, 10);

                    if (!(lbl_805DDF54 & chanBit)) {
                        lbl_805DDF54 |= chanBit;
                        SIGetTypeAsync(chan, PADReceiveCheckCallback);
                    }
                } else {
                    PADDisable(chan);
                    status->err = PAD_ERR_NO_CONTROLLER;
                    memset(status, 0, 10);
                }
            } else {
                if (!(SIGetType(chan) & SI_GC_NOMOTOR)) {
                    motor |= chanBit;
                }

                if (!SIGetResponse(chan, data)) {
                    status->err = PAD_ERR_TRANSFER;
                    memset(status, 0, 10);
                } else if (data[0] & 0x80000000) {
                    status->err = PAD_ERR_TRANSFER;
                    memset(status, 0, 10);
                } else {
                    lbl_805DC9BC(chan, status, data);

                    if (status->button & 0x2000) {
                        status->err = PAD_ERR_TRANSFER;
                        memset(status, 0, 10);

                        SITransfer(chan, &lbl_805DC9C0, 1, &lbl_8056E360[chan], 10, PADOriginUpdateCallback, 0);
                    } else {
                        status->err = PAD_ERR_NONE;

                        status->button &= ~0x0080;
                    }
                }
            }
        }
    }

    OSRestoreInterrupts(enabled);
    return motor;
}

void fn_803DCC94(u32 msec) {
    SISetSamplingRate(msec);
}

void PADControlMotor(s32 chan, u32 command) {
    BOOL enabled;
    u32 chanBit;

    enabled = OSDisableInterrupts();
    chanBit = PAD_CHAN0_BIT >> chan;
    if ((lbl_805DDF44 & chanBit) && !(SIGetType(chan) & SI_GC_NOMOTOR)) {
        if (lbl_805DC9B8 < PAD_SPEC_2 && command == PAD_MOTOR_STOP_HARD) {
            command = PAD_MOTOR_STOP;
        }
        SISetCommand(chan, (0x40 << 16) | lbl_805DC9B4 | (command & (0x00000001 | 0x00000002)));
        SITransferCommands();
    }

    OSRestoreInterrupts(enabled);
}

void PADSetSpec(u32 spec) {
    __PADSpec = 0;

    switch (spec) {
    case PAD_SPEC_0:
        lbl_805DC9BC = fn_803DCDB8;
        break;
    case PAD_SPEC_1:
        lbl_805DC9BC = fn_803DCF2C;
        break;
    case PAD_SPEC_2:
    case PAD_SPEC_3:
    case PAD_SPEC_4:
    case PAD_SPEC_5:
        lbl_805DC9BC = fn_803DD0A0;
        break;
    }
    lbl_805DC9B8 = spec;
}

void fn_803DCDB8(s32 chan, PADStatus* status, u32* data) {
    status->button = 0;
    status->button |= ((data[0] >> 16) & 0x0008) ? PAD_BUTTON_A : 0;
    status->button |= ((data[0] >> 16) & 0x0020) ? PAD_BUTTON_B : 0;
    status->button |= ((data[0] >> 16) & 0x0100) ? PAD_BUTTON_X : 0;
    status->button |= ((data[0] >> 16) & 0x0001) ? PAD_BUTTON_Y : 0;
    status->button |= ((data[0] >> 16) & 0x0010) ? PAD_BUTTON_START : 0;
    status->stickX = (s8)(data[1] >> 16);
    status->stickY = (s8)(data[1] >> 24);
    status->substickX = (s8)(data[1]);
    status->substickY = (s8)(data[1] >> 8);
    status->triggerLeft = (u8)(data[0] >> 8);
    status->triggerRight = (u8)data[0];
    status->analogA = 0;
    status->analogB = 0;
    if (170 <= status->triggerLeft) {
        status->button |= PAD_TRIGGER_L;
    }
    if (170 <= status->triggerRight) {
        status->button |= PAD_TRIGGER_R;
    }
    status->stickX -= 128;
    status->stickY -= 128;
    status->substickX -= 128;
    status->substickY -= 128;
}

void fn_803DCF2C(s32 chan, PADStatus* status, u32* data) {
    status->button = 0;
    status->button |= ((data[0] >> 16) & 0x0080) ? PAD_BUTTON_A : 0;
    status->button |= ((data[0] >> 16) & 0x0100) ? PAD_BUTTON_B : 0;
    status->button |= ((data[0] >> 16) & 0x0020) ? PAD_BUTTON_X : 0;
    status->button |= ((data[0] >> 16) & 0x0010) ? PAD_BUTTON_Y : 0;
    status->button |= ((data[0] >> 16) & 0x0200) ? PAD_BUTTON_START : 0;

    status->stickX = (s8)(data[1] >> 16);
    status->stickY = (s8)(data[1] >> 24);
    status->substickX = (s8)(data[1]);
    status->substickY = (s8)(data[1] >> 8);

    status->triggerLeft = (u8)(data[0] >> 8);
    status->triggerRight = (u8)data[0];

    status->analogA = 0;
    status->analogB = 0;

    if (170 <= status->triggerLeft) {
        status->button |= PAD_TRIGGER_L;
    }
    if (170 <= status->triggerRight) {
        status->button |= PAD_TRIGGER_R;
    }

    status->stickX -= 128;
    status->stickY -= 128;
    status->substickX -= 128;
    status->substickY -= 128;
}

static inline s8 ClampS8(s8 var, s8 org) {
    if (0 < org) {
        s8 min = (s8)(-128 + org);
        if (var < min) {
            var = min;
        }
    } else if (org < 0) {
        s8 max = (s8)(127 + org);
        if (max < var) {
            var = max;
        }
    }
    return var -= org;
}

static inline u8 ClampU8(u8 var, u8 org) {
    if (var < org) {
        var = org;
    }
    return var -= org;
}

void fn_803DD0A0(s32 chan, PADStatus* status, u32* data) {
    PADStatus* origin;

    status->button = (u16)((data[0] >> 16) & PAD_ALL);
    status->stickX = (s8)(data[0] >> 8);
    status->stickY = (s8)(data[0]);

    switch (lbl_805DC9B4 & 0x00000700) {
    case 0x00000000:
    case 0x00000500:
    case 0x00000600:
    case 0x00000700:
        status->substickX = (s8)(data[1] >> 24);
        status->substickY = (s8)(data[1] >> 16);
        status->triggerLeft = (u8)(((data[1] >> 12) & 0x0f) << 4);
        status->triggerRight = (u8)(((data[1] >> 8) & 0x0f) << 4);
        status->analogA = (u8)(((data[1] >> 4) & 0x0f) << 4);
        status->analogB = (u8)(((data[1] >> 0) & 0x0f) << 4);
        break;
    case 0x00000100:
        status->substickX = (s8)(((data[1] >> 28) & 0x0f) << 4);
        status->substickY = (s8)(((data[1] >> 24) & 0x0f) << 4);
        status->triggerLeft = (u8)(data[1] >> 16);
        status->triggerRight = (u8)(data[1] >> 8);
        status->analogA = (u8)(((data[1] >> 4) & 0x0f) << 4);
        status->analogB = (u8)(((data[1] >> 0) & 0x0f) << 4);
        break;
    case 0x00000200:
        status->substickX = (s8)(((data[1] >> 28) & 0x0f) << 4);
        status->substickY = (s8)(((data[1] >> 24) & 0x0f) << 4);
        status->triggerLeft = (u8)(((data[1] >> 20) & 0x0f) << 4);
        status->triggerRight = (u8)(((data[1] >> 16) & 0x0f) << 4);
        status->analogA = (u8)(data[1] >> 8);
        status->analogB = (u8)(data[1] >> 0);
        break;
    case 0x00000300:
        status->substickX = (s8)(data[1] >> 24);
        status->substickY = (s8)(data[1] >> 16);
        status->triggerLeft = (u8)(data[1] >> 8);
        status->triggerRight = (u8)(data[1] >> 0);
        status->analogA = 0;
        status->analogB = 0;
        break;
    case 0x00000400:
        status->substickX = (s8)(data[1] >> 24);
        status->substickY = (s8)(data[1] >> 16);
        status->triggerLeft = 0;
        status->triggerRight = 0;
        status->analogA = (u8)(data[1] >> 8);
        status->analogB = (u8)(data[1] >> 0);
        break;
    }

    status->stickX -= 128;
    status->stickY -= 128;
    status->substickX -= 128;
    status->substickY -= 128;

    origin = &lbl_8056E360[chan];
    status->stickX = ClampS8(status->stickX, origin->stickX);
    status->stickY = ClampS8(status->stickY, origin->stickY);
    status->substickX = ClampS8(status->substickX, origin->substickX);
    status->substickY = ClampS8(status->substickY, origin->substickY);
    status->triggerLeft = ClampU8(status->triggerLeft, origin->triggerLeft);
    status->triggerRight = ClampU8(status->triggerRight, origin->triggerRight);
}

static inline BOOL PADSync(void) {
    return lbl_805DDF48 == 0 && (s32)lbl_805DC9AC == 32 && !SIBusy();
}

BOOL fn_803DD498(BOOL final) {
    BOOL sync;

    if (lbl_805DDF5C) {
        PADSetSamplingCallback(NULL);
    }

    if (!final) {
        sync = PADSync();
        if (!lbl_805DDF60 && sync) {
            lbl_805DDF60 = PADRecalibrate(PAD_CHAN0_BIT | PAD_CHAN1_BIT | PAD_CHAN2_BIT | PAD_CHAN3_BIT);
            return FALSE;
        }
        return sync;
    } else {
        lbl_805DDF60 = FALSE;
    }

    return TRUE;
}

void fn_803DD62C(u32 interrupt, OSContext* context) {
    OSContext exceptionContext;

    if (lbl_805DDF5C) {
        OSClearContext(&exceptionContext);
        OSSetCurrentContext(&exceptionContext);
        lbl_805DDF5C();
        OSClearContext(&exceptionContext);
        OSSetCurrentContext(context);
    }
}

PADSamplingCallback PADSetSamplingCallback(PADSamplingCallback callback) {
    PADSamplingCallback prev;

    prev = lbl_805DDF5C;
    lbl_805DDF5C = callback;
    if (callback) {
        SIRegisterPollingHandler(fn_803DD62C);
    } else {
        SIUnregisterPollingHandler(fn_803DD62C);
    }

    return prev;
}

BOOL __PADDisableRecalibration(BOOL disable) {
    BOOL enabled;
    BOOL prev;

    enabled = OSDisableInterrupts();
    prev = (__gUnknown800030E3 & 0x40) ? TRUE : FALSE;
    __gUnknown800030E3 = __gUnknown800030E3 & 0xBF;
    if (disable) {
        __gUnknown800030E3 |= 0x40;
    }

    OSRestoreInterrupts(enabled);
    return prev;
}
