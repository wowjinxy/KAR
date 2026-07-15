#include "functions.h"
#include <dolphin/types.h>
#include <dolphin/os.h>
#include <dolphin/ostime.h>

typedef s64 OSTime;
typedef u32 OSTick;

typedef struct OSThread OSThread;

typedef struct OSThreadQueue {
    OSThread* head;
    OSThread* tail;
} OSThreadQueue;

typedef struct OSAlarm OSAlarm;
typedef void (*OSAlarmHandler)(OSAlarm*, void*);
struct OSAlarm {
    OSAlarmHandler handler;
    u32 tag;
    OSTime fire;
    OSAlarm* prev;
    OSAlarm* next;
    OSTime period;
    OSTime start;
};

void OSCreateAlarm(OSAlarm* alarm);
void OSSetAlarm(OSAlarm* alarm, OSTime tick, OSAlarmHandler handler);
void OSCancelAlarm(OSAlarm* alarm);
void OSInitThreadQueue(OSThreadQueue* queue);
void OSSleepThread(OSThreadQueue* queue);
void OSWakeupThread(OSThreadQueue* queue);
void OSRegisterResetFunction(void* info);

typedef struct OSResetFunctionInfo {
    s32 (*func)(s32);
    u32 priority;
    void* next;
    void* prev;
} OSResetFunctionInfo;

void* memset(void* dst, int val, u32 n);
void* memcpy(void* dst, const void* src, u32 n);
void* memmove(void* dst, const void* src, u32 n);
s32 memcmp(const void* a, const void* b, u32 n);
u32 strlen(const char* s);
char* strncpy(char* dst, const char* src, u32 n);
s32 sprintf(char* dst, const char* fmt, ...);

#define FS8(p, o) (*(s8*)((char*)(p) + (o)))
#define FU8(p, o) (*(u8*)((char*)(p) + (o)))
#define FS16(p, o) (*(s16*)((char*)(p) + (o)))
#define FU16(p, o) (*(u16*)((char*)(p) + (o)))
#define FS32(p, o) (*(s32*)((char*)(p) + (o)))
#define FU32(p, o) (*(u32*)((char*)(p) + (o)))
#define FPTR(p, o) (*(void**)((char*)(p) + (o)))

typedef struct SONode {
    u8 proto; //0x0
    u8 flag; //0x1
    s16 ref; //0x2
    void* info; //0x4
    u8 mutexRead[0x18]; //0x8
    u8 mutexWrite[0x18]; //0x20
} SONode; //0x38

typedef struct IPInterface {
    char pad0[0x40];
    s32 mtu; //0x40
    char pad44[0x68];
} IPInterface; //0xA8

typedef struct SOInAddr {
    u32 addr;
} SOInAddr;

extern void* fn_8046D8DC(void*, s32*);
extern void fn_8046C6A8(void*, void*);
extern void fn_8046D98C(void*, void*);
extern void fn_8046DA0C(void*, void*);
extern void fn_8046DA8C(void*, s32);
extern void fn_8046E828(void*, void*, void*);
extern s32 fn_804702B8(void);
extern s32 fn_8047033C(void*);
extern void fn_8046CAC4(void);
extern void fn_8046EA64(void);
extern void fn_8046F190(void*, s32);
extern void fn_8046F1F4(s32);
extern s32 fn_8046F320(void*, void*);
extern void fn_8046F42C(void*, u32*, u32*);
extern s32 fn_8046F4B8(void*, u32, s32);
extern void fn_8046F538(void*, u32*, u32*);
extern s32 fn_8046F5C4(void*, u32, s32);
extern s32 fn_8046F64C(void*, void*, s32);
extern s32 fn_8046FC98(void*, s32, s32, void*);
extern s32 fn_8047013C(void*, s32, s32, s32, void*, s32);
extern s32 fn_80470404(u32, s32, s32*, u32);
extern s32 fn_804704E4(void);
extern void fn_804709E4(void*, s32, s32);
extern s32 fn_80471A08(s32);
extern void fn_80471C18(s32);
extern s32 fn_804755EC(void*);
extern s32 fn_80475608(void*, void*);
extern s32 fn_8047567C(void*);
extern s32 fn_804759C0(void*, u32, s32);
extern s32 fn_80475A3C(void*, u32, s32);
extern void fn_80475AC0(void*, u32*, u32*);
extern void fn_80475B4C(void*, u32*, u32*);
extern s32 fn_80475BD8(void*, void*, s32, void*, s32);
extern s32 fn_80475E14(s32, s32, s32, s32);
extern void fn_80475EF8(void*, void*, void (*)(void*, s32), s32);
extern s32 fn_8047623C(s32, s32);
extern s32 fn_80476294(s32, s32);
extern s32 fn_804762EC(s32, s32);
extern s32 fn_80476368(s32, s32);
extern s32 fn_804766F0(s32, s32, s32);
extern s32 fn_80476768(void*, void (*)(void*), s32);
extern s32 fn_80476904(void*);
extern s32 fn_8047697C(s32);
extern s32 fn_80476C44(void*);
extern s32 fn_80476FB0(s32, s32, s32);
extern void fn_80477028(s32, s32, s32*, s32*);
extern s32 fn_8047726C(void*, u32, s32, s32*, u32);
extern void fn_80477450(void*, s32, s32);
extern s32 fn_80477508(void);
extern void fn_8047766C(void*, s32);
extern void fn_80477C10(void*, void*);
extern void fn_80477D60(void*);
extern s32 fn_80478A9C(void*, s32);
extern s32 fn_80478D54(void*, void*);
extern void fn_80478FE4(void*, s32);
extern void fn_803D7E20(void*, u8);
extern void* kar_diagnostic__803d7e58(void*);
extern void kar_diagnostic__803d7f34(void*);
extern s32 fn_8046DC28(s32, void*);

void fn_80479AF0(void);
void fn_8047BEF4(void* arg0);
s32 fn_8047DE78(void);
s32 kar_ipsocket__near_804799d0(void* arg0, void* arg2, s32 arg3, s32 arg4);
s32 kar_ipsocket__near_80479d5c(s32 arg0);
s32 kar_ipsocket__near_8047bf60(void);
s32 kar_ipsocket__near_8047ce0c(s32 arg1, s32 arg2, s32 arg3, void* arg4);
s32 kar_ipsocket__near_8047d06c(s32 arg1, s32 arg2, s32 arg3, void* arg4);
s32 kar_ipsocket__near_8047d2f4(u32 arg1, s32 arg2, s32* arg3, u32 arg4);
u32 kar_ipsocket__near_8047db1c(void);
void kar_ipsocket__near_8047db6c(void);
void kar_ipsocket__near_8047f874(void* arg0);
void kar_ipsocket__near_8047fe2c(void* arg0);
s32 kar_ipsocket__near_804800e4(void* arg0, u32 arg1, u32 arg2);
void kar_ipsocket__near_80480210(void* arg0);
s32 kar_ipsocket__near_80480d88(void* arg0, void* arg1, const char* arg2, const char* arg3);
void kar_ipsocket__near_8048138c(void* arg0, void* arg1);
void kar_ipsocket__near_80481510(void* arg0, u8* arg1);
void kar_ipsocket__near_80481678(void* arg0, void* arg1, s32 arg2);
void kar_ipsocket__near_8048172c(void* arg0);
void kar_ipsocket__near_80481854(void* arg0, void* arg1, s32 arg2);
void kar_ipsocket__near_804819f0(void* arg0);
SONode* kar_ipsocket__near_8047a6a8(s32 arg0, void* arg1);
void kar_ipsocket__8047a950(SONode* arg0);
void* kar_ipsocket__near_8047c54c(void* arg0);
void kar_ipsocket__near_8047c3ec(void* arg0, s32 arg1);
void kar_ipsocket__near_8047fc24(void* arg0, u8* arg1, s16 arg2);
void kar_ipsocket__near_8047feb4(s32 arg0, void* arg1);
void kar_ipsocket__near_8047fcfc(void* arg0, void* arg1);
s32 kar_ipsocket__near_804802e0(void* arg0, void* arg1);
void kar_ipsocket__near_8047f2d8(void* arg0, void* arg1, s32 arg2);
void kar_ipsocket__near_8047f3dc(void* arg0);
void kar_ipsocket__near_8047f4c8(void* arg0);
void kar_ipsocket__near_8047f578(void* arg0);
void kar_ipsocket__near_8047f648(void* arg0);
void kar_ipsocket__near_8047de88(void* arg0, u8 arg1, s8 arg2, s32 arg3, void* arg4);
s32 kar_ipsocket__near_8047fad4(char* arg0, u16 arg1, u8* arg2);
s32 kar_ipsocket__near_8047fb24(char* arg0, u16 arg1, u8* arg2, u8* arg3);
void kar_ipsocket__near_8047dfdc(void* arg0, void* arg1);
void kar_ipsocket__near_8047e574(void* arg0);
void kar_ipsocket__near_8047e6f0(void* arg0);
void kar_ipsocket__near_8047e8bc(void* arg0);
void kar_ipsocket__near_8047ea88(void* arg0, void* arg1);
void kar_ipsocket__near_8047ebfc(void* arg0);
void kar_ipsocket__near_8047ecf8(void* arg0, void* arg1);
void kar_ipsocket__near_8047ee38(void* arg0);
void kar_ipsocket__near_8047efb8(void* arg0);

extern OSThreadQueue lbl_805DE6A8;
extern OSThreadQueue lbl_805DE6B0;
extern void* lbl_805DE650;
extern s32 lbl_805DE658;
extern u32 lbl_805DE65C;
extern s32 lbl_805DE660;
extern void* (*lbl_805DE668)(s32, s32);
extern void (*lbl_805DE66C)(s32, void*, s32);
extern u32 lbl_805DE670;
extern void* lbl_805DE67C;
extern s32 lbl_805DE680;
extern void* lbl_805DE684;
extern s32 lbl_805DE688;
extern s32 lbl_805DE68C;
extern s32 lbl_805DE690;
extern s32 lbl_805DE694;
extern s32 lbl_805DE698;
extern s32 lbl_805DE6A0;
extern s32 lbl_805DE6A4;
extern s32 lbl_805DE6B8;
extern s32 lbl_805DE6BC;

typedef struct DhcpLinkHead {
    void* unk0;
    void* unk4;
} DhcpLinkHead;
extern DhcpLinkHead lbl_805DE674;

static const u32 lbl_805E6298 = 0U;
static const u16 lbl_805E629C[2] = { 0, 0 };
static const u32 lbl_805E62A0 = 0U;
static const u32 lbl_805E62A8 = 0U;
static const u32 lbl_805E62AC = 0U;
static const u32 lbl_805E62B0 = 0U;
static const u32 lbl_805E62B4 = 0U;
static const void* lbl_805E62B8 = (void*)0x0304C023U;

static OSResetFunctionInfo lbl_80534238 = { (s32(*)(s32))fn_8047DE78, 0x6E, 0, 0 };
static char lbl_80534248[] = "%u.%u.%u.%u";
char kar_src_ipsocket_80534254[] = "IPSocket.c";
static char lbl_80534260[] = "PutNode: unknown proto";
static u8 lbl_80534558[0x628] = { 0, 0, 0xFF, 0xFF, 0xFF, 0xFF };

static u8 lbl_805BDD20[0xA8];
static u8 lbl_805BDDC8[0x30];
static u8 lbl_805BDDF8[0x638];
static void* lbl_805BE430[0x10];
static void* lbl_805BE470[0x10];
static SONode lbl_805BE4B0[0x100];
static u8 lbl_805C1CB0[0x798];
static u8 lbl_805C2448[0x530];
static u8 lbl_805C2978[0x38];
static u8 lbl_805C29B0[0x68];

void kar_ipsocket__near_804794d0(void* arg0)
{
    void* cfg;
    u32 tickHz;
    u32 t1, t2, lease;
    OSTime now, tmp;
    s32 pollLen;
    u16 v;

    cfg = (char*)arg0 + 0x3D8;
    fn_804702B8();
    OSCancelAlarm((OSAlarm*)((char*)arg0 + 0x328));
    FS32(arg0, 0x324) = 0;
    OSCancelAlarm((OSAlarm*)((char*)arg0 + 0x350));
    OSCancelAlarm((OSAlarm*)((char*)arg0 + 0x378));
    OSCancelAlarm((OSAlarm*)((char*)arg0 + 0x3A0));

    lease = FU32(cfg, 0x11C);
    t1 = FU32(cfg, 0x124);
    if (t1 == 0 || lease <= t1) {
        t1 = lease >> 1;
    }
    t2 = FU32(cfg, 0x128);
    if (t2 == 0 || lease <= t2) {
        t2 = (u32)(((u64)lease * 7) / 8);
    }
    if (t2 <= t1) {
        t1 = (u32)(((u64)t2 * 8) / 14);
    }
    if (t1 > 0xA) {
        t1 -= 0xA;
        t2 -= 0xA;
        lease -= 0xA;
    }

    now = OSGetTime();
    tickHz = *(u32*)0x800000F8 >> 2;
    FS32(arg0, 0x3CC) = (s32)((u32)now + t2 * tickHz);
    FS32(arg0, 0x3C8) = (s32)((now >> 32) + (u64)t2 * tickHz / 0x100000000ULL);
    FS32(arg0, 0x3D4) = (s32)((u32)now + lease * tickHz);
    FS32(arg0, 0x3D0) = (s32)((now >> 32) + (u64)lease * tickHz / 0x100000000ULL);

    OSSetAlarm((OSAlarm*)((char*)arg0 + 0x350), now + (OSTime)t1 * tickHz, NULL);
    OSSetAlarm((OSAlarm*)((char*)arg0 + 0x378), now + (OSTime)t2 * tickHz, NULL);
    OSSetAlarm((OSAlarm*)((char*)arg0 + 0x3A0), now + (OSTime)lease * tickHz, NULL);

    fn_8046E828(cfg, (char*)cfg + 4, (char*)cfg + 8);
    fn_8046D98C(lbl_805BDD20, (char*)cfg + 0x116);
    if ((u16)FU16(cfg, 0x114) >= 0x44U) {
        fn_8046D8DC(lbl_805BDD20, &pollLen);
        v = FU16(cfg, 0x114);
        if ((s32)v >= pollLen) {
            v = (u16)pollLen;
        }
        fn_8046DA8C(lbl_805BDD20, (s32)v);
    }
    FS32(arg0, 0xF0) = 3;
    ((void (*)(s32))FPTR(arg0, 0x630))(FS32(arg0, 0xF0));
}

void kar_ipsocket__near_80479750(void* arg0)
{
    u32 tickHz, ms;

    if (FS32(arg0, 0xF0) != 0) {
        FS32(arg0, 0xF0) = 0;
        fn_8047033C(arg0);
        OSCancelAlarm((OSAlarm*)((char*)arg0 + 0x328));
        FS32(arg0, 0x324) = 0;
        OSCancelAlarm((OSAlarm*)((char*)arg0 + 0x350));
        OSCancelAlarm((OSAlarm*)((char*)arg0 + 0x378));
        OSCancelAlarm((OSAlarm*)((char*)arg0 + 0x3A0));
        FS32(arg0, 0xF8) &= ~4;
        fn_8046E828(NULL, NULL, NULL);
        fn_8046D98C(lbl_805BDD20, (void*)&lbl_805E62A0);
        memcpy(&lbl_805BE430[3], &lbl_805E6298, 4);
        fn_8046C6A8(lbl_805BDD20, lbl_805BE430);
        ((void (*)(s32))FPTR(arg0, 0x630))(FS32(arg0, 0xF0));
        if (FS32(arg0, 0xF8) & 2) {
            tickHz = *(u32*)0x800000F8 >> 2;
            ms = *(u32*)0x800000F8 / 57266231;
            kar_ipsocket__near_804799d0(arg0, (void*)(u32)ms, tickHz * 0x12C, 0);
        }
    }
}

void kar_ipsocket__near_80479870(void* arg0, s32 arg1)
{
    s32 count;

    memset((char*)arg0 + 0xC, 0, 4);
    fn_8046C6A8(FPTR(arg0, 0), arg0);
    if (arg1 == 0) {
        kar_ipsocket__near_804794d0(lbl_805BDDF8);
        return;
    }
    OSCancelAlarm((OSAlarm*)(lbl_805BDDF8 + 0x328));
    FS32(lbl_805BDDF8, 0x324) = 0;
    OSCancelAlarm((OSAlarm*)(lbl_805BDDF8 + 0x350));
    OSCancelAlarm((OSAlarm*)(lbl_805BDDF8 + 0x378));
    OSCancelAlarm((OSAlarm*)(lbl_805BDDF8 + 0x3A0));
    FS32(lbl_805BDDF8, 0xF8) |= 4;
    count = FS32(lbl_805BDDF8, 0xF4);
    FS32(lbl_805BDDF8, 0xF4) = count + 1;
    if (fn_80478A9C(lbl_805BDDF8, count) < 0) {
        kar_ipsocket__near_80479750(lbl_805BDDF8);
    }
    fn_8046F190(FPTR(arg0, 0), -0x6F);
}

void kar_ipsocket__near_80479948(void* arg0)
{
    fn_804702B8();
    OSCancelAlarm((OSAlarm*)((char*)arg0 + 0x328));
    FS32(arg0, 0x324) = 0;
    OSCancelAlarm((OSAlarm*)((char*)arg0 + 0x350));
    OSCancelAlarm((OSAlarm*)((char*)arg0 + 0x378));
    OSCancelAlarm((OSAlarm*)((char*)arg0 + 0x3A0));
    memcpy(&lbl_805BE430[3], (char*)arg0 + 0x3D8, 4);
    fn_8046C6A8(lbl_805BDD20, lbl_805BE430);
}

s32 kar_ipsocket__near_804799d0(void* arg0, void* arg2, s32 arg3, s32 unused)
{
    u8 sp18[8];

    if (FS32(arg0, 0xF0) != 0) {
        return 0;
    }
    FS32(arg0, 0xF0) = 1;
    ((void (*)(s32))FPTR(arg0, 0x630))(FS32(arg0, 0xF0));
    FS32(arg0, 0xF4) = FS32(arg0, 0xF4) + 1;
    fn_8046F64C(arg0, NULL, 0);
    sp18[0] = 8;
    sp18[1] = 2;
    memmove(sp18 + 4, &lbl_805E6298, 4U);
    if (fn_8046F320(arg0, sp18) < 0) {
        return 0;
    }
    switch (FS32(arg0, 0xF0)) {
    case 1:
        FS32(arg0, 0x324) = -1;
        OSCancelAlarm((OSAlarm*)((char*)arg0 + 0x328));
        OSSetAlarm((OSAlarm*)((char*)arg0 + 0x328), (OSTime)(u32)arg2, NULL);
        break;
    case 2:
        fn_80478FE4(arg0, (s32)arg2);
        break;
    }
    return 1;
}

void fn_80479AF0(void)
{
}

s32 kar_ipsocket__near_80479af4(void (*arg0)(s32), s32 arg1)
{
    s32 level;
    s32 ret;
    void (*handler)(s32);
    u32 tickHz;

    level = OSDisableInterrupts();
    if (!(FS32(lbl_805BDDF8, 0xF8) & 1)) {
        memset(lbl_805BDDF8, 0, 0x638);
        FS32(lbl_805BDDF8, 0xF8) |= 3;
        FS32(lbl_805BDDF8, 0x320) = (arg1 <= 0) ? 4 : arg1;
        FS32(lbl_805BDDF8, 0xF4) = OSGetTick();
        OSCreateAlarm((OSAlarm*)(lbl_805BDDF8 + 0x648));
        FPTR(lbl_805BDDF8, 0x674) = (void*)kar_ipsocket__near_80479870;
    }
    handler = (arg0 != NULL) ? arg0 : (void (*)(s32))fn_80479AF0;
    FPTR(lbl_805BDDF8, 0x630) = (void*)handler;
    tickHz = *(u32*)0x800000F8 >> 2;
    ret = kar_ipsocket__near_804799d0(lbl_805BDDF8, (void*)tickHz, 0,
                                       tickHz + OSGetTick() % tickHz);
    OSRestoreInterrupts(level);
    return ret;
}

s32 kar_ipsocket__near_80479bfc(void)
{
    s32 level;
    s32 result;
    s32 count;

    level = OSDisableInterrupts();
    if (FS32(lbl_805BDDF8, 0xF8) & 1) {
        kar_ipsocket__near_80479d5c(0);
        if (FS32(lbl_805BDDF8, 0xF0) != 0 && !(FS32(lbl_805BDDF8, 0xF8) & 4)) {
            OSCancelAlarm((OSAlarm*)(lbl_805BDDF8 + 0x328));
            FPTR(lbl_805BDDF8, 0x324) = NULL;
            OSCancelAlarm((OSAlarm*)(lbl_805BDDF8 + 0x350));
            OSCancelAlarm((OSAlarm*)(lbl_805BDDF8 + 0x378));
            OSCancelAlarm((OSAlarm*)(lbl_805BDDF8 + 0x3A0));
            FS32(lbl_805BDDF8, 0xF8) |= 4;
            count = FS32(lbl_805BDDF8, 0xF4);
            FS32(lbl_805BDDF8, 0xF4) = count + 1;
            if (fn_80478D54(lbl_805BDDF8, (void*)count) < 0) {
                kar_ipsocket__near_80479750(lbl_805BDDF8);
            }
        }
        result = 1;
    } else {
        result = 0;
    }
    OSRestoreInterrupts(level);
    return result;
}

s32 kar_ipsocket__near_80479cd4(void)
{
    s32 count;

    if (FS32(lbl_805BDDF8, 0xF0) < 6) {
        if (FS32(lbl_805BDDF8, 0xF0) < 3) {
            return 0;
        }
        FS32(lbl_805BDDF8, 0xF0) = 7;
        ((void (*)(s32))FPTR(lbl_805BDDF8, 0x630))(FS32(lbl_805BDDF8, 0xF0));
        FPTR(lbl_805BDDF8, 0x324) = NULL;
        count = FS32(lbl_805BDDF8, 0xF4);
        FS32(lbl_805BDDF8, 0xF4) = count + 1;
        fn_80478FE4(lbl_805BDDF8, count);
        return 1;
    }
    return 0;
}

s32 kar_ipsocket__near_80479d5c(s32 arg0)
{
    s32 level;
    s32 result;
    u32 tickHz, ms;

    level = OSDisableInterrupts();
    result = (FS32(lbl_805BDDF8, 0xF8) & 2) != 0;
    if (arg0 != 0) {
        FS32(lbl_805BDDF8, 0xF8) |= 2;
        tickHz = *(u32*)0x800000F8 >> 2;
        ms = *(u32*)0x800000F8 / 57266231;
        kar_ipsocket__near_804799d0(lbl_805BDDF8, (void*)(u32)ms, tickHz * 0x12C, 0);
    } else {
        FS32(lbl_805BDDF8, 0xF8) &= ~2;
    }
    OSRestoreInterrupts(level);
    return result;
}

s32 kar_ipsocket__near_80479e2c(void* arg0)
{
    s32 state;
    s32 level;

    state = FS32(lbl_805BDDF8, 0xF0);
    level = OSDisableInterrupts();
    if (arg0 != NULL) {
        memmove(arg0, lbl_805BDDF8 + 0x3D8, 0x12C);
    }
    OSRestoreInterrupts(level);
    return state;
}

void kar_ipsocket__near_80479ea4(void* arg0, s32 arg1)
{
    u16 r;

    if (arg1 == 0) {
        fn_8046DA0C(lbl_805BDD20, (char*)arg0 + 0xC);
        fn_8046EA64();
        memset((char*)arg0 + 0xC, 0, 4);
        fn_8046C6A8(FPTR(arg0, 0), arg0);
        return;
    }
    lbl_805DE660 += 1;
    if (lbl_805DE660 < 0xA) {
        do {
            lbl_805DE65C = lbl_805DE65C * 0xDEECE66D + 0xB;
            lbl_805DE658 = lbl_805DE65C;
            r = (u16)(lbl_805DE658 & 0xFFFF);
        } while (r < 0x100U || r >= 0xFF00U);
        if (((char*)arg0 + 0xC) != NULL) {
            FU8(arg0, 0xC) = 0xA9;
            FU8(arg0, 0xD) = 0xFE;
            FS8(arg0, 0xE) = (s8)(r >> 8);
            FS8(arg0, 0xF) = (s8)r;
        }
        fn_8046C6A8(FPTR(arg0, 0), arg0);
        return;
    }
    do {
        lbl_805DE65C = lbl_805DE65C * 0xDEECE66D + 0xB;
        lbl_805DE658 = lbl_805DE65C;
        r = (u16)(lbl_805DE658 & 0xFFFF);
    } while (r < 0x100U || r >= 0xFF00U);
    memset((char*)arg0 + 0xC, 0, 4);
    fn_8046C6A8(FPTR(arg0, 0), arg0);
    if (*(void**)&lbl_805BDD20[0x54] != (void*)&lbl_805E6298) {
        fn_8046DA0C((void*)&lbl_805E6298, NULL);
        fn_8046EA64();
    }
}

s32 kar_ipsocket__near_8047a09c(void)
{
    s32 level;
    u16 r;

    level = OSDisableInterrupts();
    if ((lbl_805DE65C | lbl_805DE658) == 0) {
        memcpy((char*)&lbl_805DE658 + 2, &lbl_805BDD20[0x38], 6);
        OSCreateAlarm((OSAlarm*)&lbl_805BE470[4]);
        lbl_805BE470[0xF] = (void*)kar_ipsocket__near_80479ea4;
        do {
            lbl_805DE65C = lbl_805DE65C * 0xDEECE66D + 0xB;
            lbl_805DE658 = lbl_805DE65C;
            r = (u16)(lbl_805DE658 & 0xFFFF);
        } while (r < 0x100U || r >= 0xFF00U);
        if (&lbl_805BE470[3] != NULL) {
            FU8(lbl_805BE470, 0xC) = 0xA9;
            FU8(lbl_805BE470, 0xD) = 0xFE;
            FU8(lbl_805BE470, 0xE) = (u8)(r >> 8);
            FS8(lbl_805BE470, 0xF) = (s8)r;
        }
    } else {
        r = (u16)(lbl_805DE658 & 0xFFFF);
        FU8(lbl_805BE470, 0xC) = 0xA9;
        FU8(lbl_805BE470, 0xD) = 0xFE;
        FU8(lbl_805BE470, 0xE) = (u8)(r >> 8);
        FS8(lbl_805BE470, 0xF) = (s8)r;
    }
    lbl_805DE660 = 0;
    fn_8046C6A8(lbl_805BDD20, lbl_805BE470);
    OSRestoreInterrupts(level);
    return 1;
}

void kar_ipsocket__near_8047a220(void)
{
    s32 level;

    level = OSDisableInterrupts();
    memset(&lbl_805BE470[3], 0, 4);
    fn_8046C6A8(lbl_805BDD20, lbl_805BE470);
    fn_8046DA0C(lbl_805BDD20, (void*)&lbl_805E6298);
    fn_8046EA64();
    OSRestoreInterrupts(level);
}

s32 kar_ipsocket__near_8047a2a0(u8* arg0)
{
    s32 totalLen;
    s32 i;
    u8* opt;
    u8 type;
    u8 len;

    opt = arg0 + 0x14;
    i = 0;
    totalLen = ((arg0[0] * 4) & 0x3C) - 0x14;
    for (;;) {
        if (i >= totalLen) {
            return 0;
        }
        type = opt[i];
        if (type == 0) {
            return 0;
        }
        if (type < 2) {
            len = 1;
        } else {
            if (totalLen <= i + 1) {
                return -0xC;
            }
            len = opt[i + 1];
            if (totalLen < i + len) {
                return -0xC;
            }
        }
        if (type == 0x83 || type == 0x89) {
            if (len < 7) {
                return -0xC;
            }
            if ((opt[i + 2] + 3) <= len) {
                return -0xC;
            }
            return 0;
        }
        i += len;
    }
}

s32 kar_ipsocket__near_8047a368(u8* arg0)
{
    s32 totalLen;
    s32 i;
    u8* opt;
    u8 type;
    u8 len;
    u8* p;
    u8* end;
    u8* q;
    u32 pairs;
    u8 tmp[4];
    u8 tmp2[4];

    if (arg0 == NULL) {
        return -0xC;
    }
    totalLen = ((arg0[0] * 4) & 0x3C) - 0x14;
    if (totalLen <= 0) {
        return 0;
    }
    opt = arg0 + 0x14;
    i = 0;
    for (;;) {
        if (i >= totalLen) {
            return 0;
        }
        p = opt + i;
        type = p[0];
        if (type == 0) {
            return 0;
        }
        if (type < 2) {
            len = 1;
        } else {
            if (totalLen <= i + 1) {
                return -0xC;
            }
            len = p[1];
            if (totalLen < i + len) {
                return -0xC;
            }
        }
        if (type == 0x83 || type == 0x89) {
            s32 dataLen;
            if (len < 7) {
                return -0xC;
            }
            if ((p[2] + 3) <= len) {
                return -0xC;
            }
            p[2] = 4;
            dataLen = (len - 3) & ~3;
            memmove(tmp, arg0 + 0x10, 4U);
            end = p + dataLen;
            q = end - 1;
            memmove(arg0 + 0x10, q, 4U);
            memmove(q, tmp, 4U);
            pairs = (u32)(dataLen - 4) / 2;
            while (pairs >= 4) {
                u8* a = p + pairs + 3;
                u8* b = (end - 5) - pairs;
                memmove(tmp2, a, 4U);
                memmove(a, b, 4U);
                memmove(b, tmp2, 4U);
                pairs -= 4;
            }
            return 0;
        }
        i += len;
    }
}

s32 kar_ipsocket__near_8047a518(u8* arg0, const u8* arg1)
{
    s32 totalLen;
    s32 i;
    u8* opt;
    u8 type;
    u8 len;
    u8* p;
    u8 ptr;

    if (arg0 == NULL || arg1 == 0U) {
        return -0xC;
    }
    totalLen = ((arg0[0] * 4) & 0x3C) - 0x14;
    if (totalLen <= 0) {
        return 0;
    }
    opt = arg0 + 0x14;
    i = 0;
    for (;;) {
        if (i >= totalLen) {
            return 0;
        }
        p = opt + i;
        type = p[0];
        if (type == 0) {
            return 0;
        }
        if (type < 2) {
            len = 1;
        } else {
            if (totalLen <= i + 1) {
                return -0xC;
            }
            len = p[1];
            if (totalLen < i + len) {
                return -0xC;
            }
        }
        if (type == 7) {
            if (len < 7) {
                return -0xC;
            }
            ptr = p[2];
            if ((ptr + 3) <= len) {
                memmove(p + (ptr - 1), arg1, 4);
                p[2] = (u8)(ptr + 4);
            }
            return 0;
        }
        i += len;
    }
}

u32 kar_ipsocket__near_8047a634(s32 arg0, u8* arg1, char* arg2, u32 arg3)
{
    if (arg0 == 2 && arg2 != NULL && arg3 >= 0x10U) {
        sprintf(arg2, lbl_80534248, arg1[0], arg1[1], arg1[2], arg1[3]);
        return (u32)arg2;
    }
    return 0U;
}

SONode* kar_ipsocket__near_8047a6a8(s32 arg0, void* arg1)
{
    void* cur;
    void* nextExpired;
    void* freed;
    s32 level;
    SONode* node;

    freed = NULL;
    cur = lbl_805DE674.unk0;
    for (;;) {
        if (cur == NULL) {
            break;
        }
        if (FPTR(cur, 0x2C8) == NULL || FS16(FPTR(cur, 0x2C8), 2) == 0) {
            void* prev = FPTR(cur, 0x18);
            void* next = FPTR(cur, 0x1C);
            if (prev == NULL) {
                lbl_805DE674.unk4 = next;
            } else {
                FPTR(prev, 0x1C) = next;
            }
            if (next == NULL) {
                lbl_805DE674.unk0 = prev;
            } else {
                FPTR(next, 0x18) = prev;
            }
            FPTR(cur, 0x1C) = freed;
            FPTR(cur, 0x18) = NULL;
            freed = cur;
        }
        cur = FPTR(cur, 0x18);
    }

    while (freed != NULL) {
        void* next = FPTR(freed, 0x18);
        void* info;
        s32 sz1, sz2;
        if (next != NULL) {
            FPTR(next, 0x1C) = NULL;
        }
        sz1 = FS32(freed, 0x1A0);
        info = FPTR(freed, 0x1A4);
        if (sz1 != 0) {
            lbl_805DE66C(2, info, 0);
            level = OSDisableInterrupts();
            lbl_805DE670 -= (u32)info;
            if (lbl_805DE670 == 0U && lbl_805DE68C == 2) {
                OSWakeupThread(&lbl_805DE6A8);
            }
            OSRestoreInterrupts(level);
        }
        if (FS32(freed, 0x11C) != 0) {
            lbl_805DE66C(1, FPTR(freed, 0x120), 0);
            level = OSDisableInterrupts();
            lbl_805DE670 -= (u32)FPTR(freed, 0x120);
            if (lbl_805DE670 == 0U && lbl_805DE68C == 2) {
                OSWakeupThread(&lbl_805DE6A8);
            }
            OSRestoreInterrupts(level);
        }
        lbl_805DE66C(0, freed, 0x2D0);
        level = OSDisableInterrupts();
        lbl_805DE670 -= 0x2D0;
        if (lbl_805DE670 == 0U && lbl_805DE68C == 2) {
            OSWakeupThread(&lbl_805DE6A8);
        }
        OSRestoreInterrupts(level);
        freed = next;
    }

    node = NULL;
    level = OSDisableInterrupts();
    if (arg0 >= 0 && arg0 < 0x100) {
        SONode* n = &lbl_805BE4B0[arg0];
        node = n;
        if (n->ref <= 0 || n->info == NULL) {
            node = NULL;
        } else {
            n->ref = n->ref + 1;
            if (arg1 != NULL) {
                *(void**)arg1 = n->info;
            }
        }
    }
    OSRestoreInterrupts(level);
    return node;
}

void kar_ipsocket__8047a950(SONode* arg0)
{
    s32 level;
    void* info;
    u8 proto;

    proto = 0;
    info = NULL;
    level = OSDisableInterrupts();
    arg0->ref -= 1;
    if (arg0->ref == 0) {
        info = arg0->info;
        if (info != NULL) {
            arg0->info = NULL;
            proto = arg0->proto;
            arg0->proto = 0;
        }
    }
    OSRestoreInterrupts(level);
    if (info != NULL) {
        switch (proto) {
        case 17:
            if (FU32(info, 0xD4) != 0) {
                lbl_805DE66C(5, FPTR(info, 0xD8), 0);
                level = OSDisableInterrupts();
                lbl_805DE670 -= (u32)FPTR(info, 0xD8);
                if (lbl_805DE670 == 0U && lbl_805DE68C == 2) {
                    OSWakeupThread(&lbl_805DE6A8);
                }
                OSRestoreInterrupts(level);
            }
            if (FU32(info, 0xE4) != 0) {
                lbl_805DE66C(4, FPTR(info, 0xE8), 0);
                level = OSDisableInterrupts();
                lbl_805DE670 -= (u32)FPTR(info, 0xE8);
                if (lbl_805DE670 == 0U && lbl_805DE68C == 2) {
                    OSWakeupThread(&lbl_805DE6A8);
                }
                OSRestoreInterrupts(level);
            }
            lbl_805DE66C(3, info, 0xF0);
            level = OSDisableInterrupts();
            lbl_805DE670 -= 0xF0;
            if (lbl_805DE670 == 0U && lbl_805DE68C == 2) {
                OSWakeupThread(&lbl_805DE6A8);
            }
            OSRestoreInterrupts(level);
            return;
        case 6:
            if (FU32(info, 0x1A0) != 0) {
                lbl_805DE66C(2, FPTR(info, 0x1A4), 0);
                level = OSDisableInterrupts();
                lbl_805DE670 -= (u32)FPTR(info, 0x1A4);
                if (lbl_805DE670 == 0U && lbl_805DE68C == 2) {
                    OSWakeupThread(&lbl_805DE6A8);
                }
                OSRestoreInterrupts(level);
            }
            if (FU32(info, 0x11C) != 0) {
                lbl_805DE66C(1, FPTR(info, 0x120), 0);
                level = OSDisableInterrupts();
                lbl_805DE670 -= (u32)FPTR(info, 0x120);
                if (lbl_805DE670 == 0U && lbl_805DE68C == 2) {
                    OSWakeupThread(&lbl_805DE6A8);
                }
                OSRestoreInterrupts(level);
            }
            lbl_805DE66C(0, info, 0x2D0);
            level = OSDisableInterrupts();
            lbl_805DE670 -= 0x2D0;
            if (lbl_805DE670 == 0U && lbl_805DE68C == 2) {
                OSWakeupThread(&lbl_805DE6A8);
            }
            OSRestoreInterrupts(level);
            return;
        default:
            OSPanic(kar_src_ipsocket_80534254, 0x213, lbl_80534260);
            break;
        }
    }
}

s32 kar_ipsocket__near_8047ac54(const u32* arg0, const u32* arg1)
{
    const u32* a0;
    const u32* a1;
    void* dst0;
    void* dst1;

    if (lbl_805DE68C != 1) {
        return -0x27;
    }
    a0 = (arg0 != NULL) ? arg0 : &lbl_805E6298;
    dst0 = (char*)lbl_805BE4B0 + 0x3F90;
    memmove(dst0, a0, 4U);
    a1 = (arg1 != NULL) ? arg1 : &lbl_805E6298;
    dst1 = (char*)lbl_805BE4B0 + 0x3F94;
    memmove(dst1, a1, 4U);
    fn_80477D60((char*)lbl_805BE4B0 + 0x3800);
    if (FU32(lbl_805BE4B0, 0x3F90) != lbl_805E6298) {
        fn_80477C10((char*)lbl_805BE4B0 + 0x3800, dst0);
    } else if (FU32(lbl_805BE4B0, 0x3F94) != lbl_805E6298) {
        fn_80477C10((char*)lbl_805BE4B0 + 0x3800, dst1);
    }
    FS32(lbl_805BE4B0, 0x3930) |= 4;
    return 0;
}

s32 kar_ipsocket__near_8047ad40(u32* arg0, u32* arg1)
{
    s32 level;
    s32 result;

    level = OSDisableInterrupts();
    if (lbl_805DE68C != 1) {
        result = -0x27;
    } else {
        if (arg0 != NULL) {
            memcpy(arg0, lbl_805C1CB0 + 0x790, 4);
        }
        if (arg1 != NULL) {
            memcpy(arg1, lbl_805C1CB0 + 0x794, 4);
        }
        result = 0;
    }
    OSRestoreInterrupts(level);
    return result;
}

void kar_ipsocket__near_8047ade8(s32 arg0)
{
    u32 tmpA, tmpB;
    void* dstA;
    void* dstB;

    switch (arg0) {
    case 3: {
        s32 level;
        s32 result;
        u32 rd1, rd2;

        kar_ipsocket__near_80479e2c(NULL);
        level = OSDisableInterrupts();
        if (lbl_805DE68C != 1) {
            result = -0x27;
        } else {
            memcpy(&rd1, lbl_805BE4B0 + 0x3F90, 4);
            memcpy(&rd2, lbl_805BE4B0 + 0x3F94, 4);
            result = 0;
        }
        OSRestoreInterrupts(level);
        if (result != 0) {
            return;
        }
        if (rd1 == lbl_805E6298 && rd2 == lbl_805E6298) {
            if (lbl_805DE68C != 1) {
                return;
            }
            tmpA = 0;
            tmpB = 0;
        } else if (lbl_805DE68C == 1) {
            tmpA = rd1;
            tmpB = rd2;
        } else {
            return;
        }
        dstA = (char*)lbl_805BE4B0 + 0x3F90;
        memmove(dstA, &tmpA, 4U);
        dstB = (char*)lbl_805BE4B0 + 0x3F94;
        memmove(dstB, &tmpB, 4U);
        fn_80477D60((char*)lbl_805BE4B0 + 0x3800);
        if (FU32(lbl_805BE4B0, 0x3F90) != lbl_805E6298) {
            fn_80477C10((char*)lbl_805BE4B0 + 0x3800, dstA);
        } else if (FU32(lbl_805BE4B0, 0x3F94) != lbl_805E6298) {
            fn_80477C10((char*)lbl_805BE4B0 + 0x3800, dstB);
        }
        FS32(lbl_805BE4B0, 0x3930) |= 4;
        return;
    }
    case 0:
        fn_8046DA8C(NULL, lbl_805DE694);
        if (lbl_805DE68C == 2) {
            OSWakeupThread(&lbl_805DE6A8);
        }
        break;
    }
}

void kar_ipsocket__near_8047b020(void)
{
    if (lbl_805DE6BC == 0) {
        lbl_805DE6BC = 1;
        OSRegisterResetFunction(&lbl_80534238);
    }
    fn_80471A08(4);
    if (lbl_805DE68C == 0) {
        if (kar_ipsocket__near_8047db1c() != 0U || kar_ipsocket__near_80479e2c(NULL) != 0) {
            lbl_805DE6B8 = 1;
            return;
        }
        fn_80471C18(1);
    }
}

s32 kar_ipsocket__near_8047b0a0(void* arg0)
{
    void* iface;
    s32 mtu;
    s32 level;

    iface = lbl_805BE4B0 + 0x3D60;
    if (FU16(arg0, 0) != 0 || FU16(arg0, 2) != 0x100) {
        return -0x1C;
    }
    if (fn_80471A08(4) == 0) {
        return -0x1C;
    }
    if (lbl_805DE68C != 0) {
        return -0x1C;
    }
    mtu = FS32(arg0, 0x2C);
    if (mtu > 0) {
        s32 clamped = (mtu > 0x5DC) ? 0x5DC : mtu;
        if (clamped < 0x44) {
            mtu = 0x44;
        } else if (mtu > 0x5DC) {
            mtu = 0x5DC;
        }
    } else {
        mtu = 0x5DC;
    }
    lbl_805DE694 = mtu;
    fn_8046DA8C(NULL, mtu);
    mtu = FS32(arg0, 0x30);
    if (mtu > 0) {
        if (mtu < 0x1C) {
            mtu = 0x1C;
        }
        lbl_805DE698 = mtu;
    } else {
        lbl_805DE698 = 0;
    }
    if (FS32(arg0, 0x38) != 0 || FS32(arg0, 0x3C) != 0) {
        lbl_805DE6A4 = FS32(arg0, 0x3C);
        lbl_805DE6A0 = FS32(arg0, 0x38);
    } else {
        u32 tickHz = *(u32*)0x800000F8 >> 2;
        lbl_805DE6A4 = tickHz * 0x64;
        lbl_805DE6A0 = 0;
    }
    OSInitThreadQueue(&lbl_805DE6A8);
    OSInitThreadQueue(&lbl_805DE6B0);
    lbl_805DE668 = (void* (*)(s32, s32))FPTR(arg0, 4);
    lbl_805DE66C = (void (*)(s32, void*, s32))FPTR(arg0, 8);
    lbl_805DE690 = FS32(arg0, 0xC);
    if (lbl_805DE6B8 == 0) {
        s32 sndbuf = FS32(arg0, 0x24);
        s32 rcvbuf = FS32(arg0, 0x28);
        if (sndbuf != 0) {
            void* p;
            lbl_805DE680 = sndbuf;
            p = lbl_805DE668(6, sndbuf);
            if (p != NULL) {
                level = OSDisableInterrupts();
                lbl_805DE670 += sndbuf;
                OSRestoreInterrupts(level);
            }
            lbl_805DE67C = p;
            fn_8047766C(lbl_805DE67C, lbl_805DE680);
        }
        if (rcvbuf != 0) {
            void* p;
            lbl_805DE688 = rcvbuf;
            p = lbl_805DE668(7, rcvbuf);
            if (p != NULL) {
                level = OSDisableInterrupts();
                lbl_805DE670 += rcvbuf;
                OSRestoreInterrupts(level);
            }
            lbl_805DE684 = p;
            fn_804709E4(lbl_805DE684, lbl_805DE688, mtu);
        }
        fn_8046F1F4(0);
    }
    if (lbl_805DE6B8 == 0) {
        if (lbl_805DE690 & 2) {
            lbl_805DE690 &= ~0x8000;
            if (kar_ipsocket__near_804800e4(NULL, FU32(arg0, 0x40), FU32(arg0, 0x44)) != 0) {
                goto cleanup_release;
            }
            if (lbl_805DE67C != NULL) {
                lbl_805DE66C(6, lbl_805DE67C, 0);
                level = OSDisableInterrupts();
                lbl_805DE670 -= lbl_805DE680;
                if (lbl_805DE670 == 0U && lbl_805DE68C == 2) {
                    OSWakeupThread(&lbl_805DE6A8);
                }
                OSRestoreInterrupts(level);
            }
            if (lbl_805DE684 != NULL) {
                lbl_805DE66C(7, lbl_805DE684, 0);
                level = OSDisableInterrupts();
                lbl_805DE670 -= lbl_805DE688;
                if (lbl_805DE670 == 0U && lbl_805DE68C == 2) {
                    OSWakeupThread(&lbl_805DE6A8);
                }
                OSRestoreInterrupts(level);
            }
            return -0x1C;
        }
        if (lbl_805DE690 & 1) {
            if (kar_ipsocket__near_80479af4(kar_ipsocket__near_8047ade8, FS32(arg0, 0x50)) == 0) {
                lbl_805DE6B8 = 1;
            }
            kar_ipsocket__near_80479d5c(0);
        } else if (FU32(arg0, 0x10) != 0U) {
            if (kar_ipsocket__near_8047db1c() == 0U) {
                fn_8046E828((char*)arg0 + 0x10, (char*)arg0 + 0x14, (char*)arg0 + 0x18);
            } else {
                lbl_805DE6B8 = 1;
            }
        }
    }
cleanup_release:
    if (lbl_805DE6B8 == 0) {
        fn_8046CAC4();
    }
    if (lbl_805DE690 & 0x8000) {
        kar_ipsocket__near_8047a09c();
    }
    lbl_805DE674.unk4 = NULL;
    lbl_805DE674.unk0 = NULL;
    memset(lbl_805BE4B0 + 0x3800, 0, 0x798);
    FS32(lbl_805BE4B0, 0x3E70) = 0;
    FPTR(lbl_805BE4B0, 0x3D60) = lbl_805BE4B0 + 0x3D70;
    FPTR(iface, 4) = lbl_805BE4B0 + 0x3E70;
    FS32(iface, 8) = 2;
    FS16(iface, 0xA) = 4;
    FPTR(iface, 0xC) = lbl_805BE4B0 + 0x3F00;
    if (lbl_805DE68C == 1) {
        void* dstA = lbl_805BE4B0 + 0x3F90;
        void* dstB = lbl_805BE4B0 + 0x3F94;
        memmove(dstA, (char*)arg0 + 0x1C, 4U);
        memmove(dstB, (char*)arg0 + 0x20, 4U);
        fn_80477D60(lbl_805BE4B0 + 0x3800);
        if (FU32(lbl_805BE4B0, 0x3F90) != lbl_805E6298) {
            fn_80477C10(lbl_805BE4B0 + 0x3800, dstA);
        } else if (FU32(lbl_805BE4B0, 0x3F94) != lbl_805E6298) {
            fn_80477C10(lbl_805BE4B0 + 0x3800, dstB);
        }
        FS32(lbl_805BE4B0, 0x3930) |= 4;
    }
    lbl_805DE68C = 1;
    return 0;
}

s32 kar_ipsocket__near_8047b578(void)
{
    s32 i;
    SONode* node;
    void* cur;
    void* next;
    s32 level;

    if (lbl_805DE68C != 1) {
        return -0x27;
    }
    lbl_805DE68C = 2;
    kar_ipsocket__near_8047db6c();
    node = lbl_805BE4B0;
    for (i = 0; i < 0x100; i++, node++) {
        if (node->ref != 0) {
            switch (node->proto) {
            case 17:
                kar_ipsocket__near_8047bf60();
                break;
            case 6: {
                s32 one = 1, zero = 0;
                kar_ipsocket__near_8047d2f4(0xFFFFU, 0x80, &zero, 8);
                kar_ipsocket__near_8047bf60();
                break;
            }
            }
        }
    }
    cur = lbl_805DE650;
    while (cur != NULL) {
        if (FPTR(cur, 0x94) == (void*)fn_8047BEF4) {
            fn_80476C44(cur);
        }
        cur = FPTR(cur, 0x18);
    }
    kar_ipsocket__near_8047a6a8(-1, NULL);
    if (lbl_805DE690 & 0x8000) {
        kar_ipsocket__near_8047a220();
    }
    fn_80477D60(lbl_805C1CB0);
    if (lbl_805DE6B8 == 0) {
        if (lbl_805DE690 & 2) {
            kar_ipsocket__near_80480210(NULL);
            while (FS32(lbl_805C2448, 4) != 0) {
            }
        } else if (lbl_805DE690 & 1) {
            level = OSDisableInterrupts();
            kar_ipsocket__near_80479bfc();
            while (kar_ipsocket__near_80479e2c(NULL) != 0) {
                OSSleepThread(&lbl_805DE6A8);
            }
            OSRestoreInterrupts(level);
        } else {
            fn_8046E828(NULL, NULL, NULL);
            fn_8046D98C(lbl_805BDD20, (void*)&lbl_805E62A0);
        }
    }
    if (lbl_805DE67C != NULL) {
        lbl_805DE66C(6, lbl_805DE67C, 0);
        level = OSDisableInterrupts();
        lbl_805DE670 -= lbl_805DE680;
        if (lbl_805DE670 == 0U && lbl_805DE68C == 2) {
            OSWakeupThread(&lbl_805DE6A8);
        }
        OSRestoreInterrupts(level);
    }
    if (lbl_805DE684 != NULL) {
        lbl_805DE66C(7, lbl_805DE684, 0);
        level = OSDisableInterrupts();
        lbl_805DE670 -= lbl_805DE688;
        if (lbl_805DE670 == 0U && lbl_805DE68C == 2) {
            OSWakeupThread(&lbl_805DE6A8);
        }
        OSRestoreInterrupts(level);
    }
    level = OSDisableInterrupts();
    while (lbl_805DE670 != 0U) {
        OSSleepThread(&lbl_805DE6A8);
    }
    OSRestoreInterrupts(level);
    if (lbl_805DE6B8 == 0) {
        fn_80471C18(1);
        fn_8046CAC4();
    }
    lbl_805DE68C = 0;
    return 0;
}

s32 kar_ipsocket__near_8047b888(s32 arg0, s32 arg1, s32 arg2)
{
    SONode* node;
    s32 idx;
    void* a;
    void* b;
    void* c;
    s32 sizeArg;
    s32 res;
    s32 level;

    if (lbl_805DE68C != 1) {
        return -0x27;
    }
    if (arg0 != 2) {
        return -5;
    }
    if (arg2 != 0) {
        return -0x44;
    }
    kar_ipsocket__near_8047a6a8(-1, NULL);

    level = OSDisableInterrupts();
    node = lbl_805BE4B0;
    idx = 0;
    while (node->ref != 0 && idx < 0x1F) {
        node++;
        idx++;
    }
    OSRestoreInterrupts(level);
    if (node->ref != 0) {
        return -0x21;
    }

    sizeArg = lbl_805DE698;
    if (sizeArg == 0) {
        s32 mtu;
        fn_8046D8DC(NULL, &mtu);
        sizeArg = (mtu - 0x28) * 2;
    }

    a = NULL;
    b = NULL;
    c = NULL;
    switch (arg1) {
    case 1:
        a = lbl_805DE668(0, 0x2D0);
        if (a != NULL) {
            level = OSDisableInterrupts();
            lbl_805DE670 += 0x2D0;
            OSRestoreInterrupts(level);
        }
        b = lbl_805DE668(1, sizeArg);
        if (b != NULL) {
            level = OSDisableInterrupts();
            lbl_805DE670 += sizeArg;
            OSRestoreInterrupts(level);
        }
        c = lbl_805DE668(2, sizeArg);
        if (c != NULL) {
            level = OSDisableInterrupts();
            lbl_805DE670 += sizeArg;
            OSRestoreInterrupts(level);
        }
        res = fn_80475BD8(a, b, sizeArg, c, sizeArg);
        if (res >= 0) {
            fn_80477450(a, lbl_805DE6A0, lbl_805DE6A4);
        }
        break;
    case 2:
        b = lbl_805DE668(3, 0xF0);
        if (b != NULL) {
            level = OSDisableInterrupts();
            lbl_805DE670 += 0xF0;
            OSRestoreInterrupts(level);
        }
        c = lbl_805DE668(4, 0x5B2);
        if (c != NULL) {
            level = OSDisableInterrupts();
            lbl_805DE670 += 0x5B2;
            OSRestoreInterrupts(level);
        }
        a = lbl_805DE668(5, 0x1000);
        if (a != NULL) {
            level = OSDisableInterrupts();
            lbl_805DE670 += 0x1000;
            OSRestoreInterrupts(level);
        }
        res = fn_8046F64C(b, a, 0x1000);
        if (res >= 0) {
            res = fn_8046F5C4(b, (u32)c, 0x5B2);
        }
        break;
    default:
        return -0x45;
    }

    if (res < 0) {
        if (arg1 == 1) {
            if (a != NULL) {
                lbl_805DE66C(0, a, 0x2D0);
                level = OSDisableInterrupts();
                lbl_805DE670 -= 0x2D0;
                if (lbl_805DE670 == 0U && lbl_805DE68C == 2) {
                    OSWakeupThread(&lbl_805DE6A8);
                }
                OSRestoreInterrupts(level);
            }
            if (b != NULL) {
                lbl_805DE66C(1, b, sizeArg);
                level = OSDisableInterrupts();
                lbl_805DE670 -= sizeArg;
                if (lbl_805DE670 == 0U && lbl_805DE68C == 2) {
                    OSWakeupThread(&lbl_805DE6A8);
                }
                OSRestoreInterrupts(level);
            }
            if (c != NULL) {
                lbl_805DE66C(2, c, sizeArg);
                level = OSDisableInterrupts();
                lbl_805DE670 -= sizeArg;
                if (lbl_805DE670 == 0U && lbl_805DE68C == 2) {
                    OSWakeupThread(&lbl_805DE6A8);
                }
                OSRestoreInterrupts(level);
            }
        } else {
            if (b != NULL) {
                lbl_805DE66C(3, b, 0xF0);
                level = OSDisableInterrupts();
                lbl_805DE670 -= 0xF0;
                if (lbl_805DE670 == 0U && lbl_805DE68C == 2) {
                    OSWakeupThread(&lbl_805DE6A8);
                }
                OSRestoreInterrupts(level);
            }
            if (c != NULL) {
                lbl_805DE66C(4, c, 0x5B2);
                level = OSDisableInterrupts();
                lbl_805DE670 -= 0x5B2;
                if (lbl_805DE670 == 0U && lbl_805DE68C == 2) {
                    OSWakeupThread(&lbl_805DE6A8);
                }
                OSRestoreInterrupts(level);
            }
            if (a != NULL) {
                lbl_805DE66C(5, a, 0x1000);
                level = OSDisableInterrupts();
                lbl_805DE670 -= 0x1000;
                if (lbl_805DE670 == 0U && lbl_805DE68C == 2) {
                    OSWakeupThread(&lbl_805DE6A8);
                }
                OSRestoreInterrupts(level);
            }
        }
        kar_ipsocket__8047a950(node);
        kar_ipsocket__8047a950(node);
        return -0x31;
    }
    node->flag = 0;
    fn_803D7E20(&node->mutexRead, 0);
    fn_803D7E20(&node->mutexWrite, 0);
    if (arg1 == 1) {
        FPTR(a, 0x2C8) = node;
        node->proto = 6;
        node->info = a;
    } else {
        node->proto = 0x11;
        node->info = b;
    }
    kar_ipsocket__8047a950(node);
    return idx;
}

void fn_8047BEF4(void* arg0)
{
    void* self;

    self = FPTR(arg0, 0x2C8);
    if (self != NULL) {
        FS16(self, 2) = FS16(self, 2) - 1;
    }
    if (lbl_805DE674.unk4 == NULL) {
        lbl_805DE674.unk0 = arg0;
    } else {
        FPTR(lbl_805DE674.unk4, 0x18) = arg0;
    }
    FPTR(arg0, 0x1C) = lbl_805DE674.unk4;
    FPTR(arg0, 0x18) = NULL;
    lbl_805DE674.unk4 = arg0;
}

void kar_ipsocket__near_8047bf3c(s32 arg0)
{
    fn_80476C44((void*)(arg0 - 0x280));
}

s32 kar_ipsocket__near_8047bf60(void)
{
    return 0;
}

s32 kar_ipsocket__near_8047c3b8(void)
{
    if (lbl_805DE68C != 1) {
        return -0x27;
    }
    return kar_ipsocket__near_8047bf60();
}

void kar_ipsocket__near_8047c3ec(void* arg0, s32 arg1)
{
}

void* kar_ipsocket__near_8047c54c(void* arg0)
{
    return NULL;
}

s32 kar_ipsocket__near_8047c7d0(s32 arg1)
{
    s32 backlog;
    SONode* node;
    void* info;
    s32 result;

    backlog = arg1;
    if (lbl_805DE68C != 1) {
        return -0x27;
    }
    if (backlog < 1) {
        backlog = 1;
    }
    node = kar_ipsocket__near_8047a6a8((s32)&info, &info);
    if (node == NULL || info == NULL) {
        return -8;
    }
    switch (FU8(info, 0)) {
    case 17:
        result = -0x3F;
        break;
    case 6:
        result = fn_80475E14(0, 0, 0, 0);
        switch (result) {
        case 0:
            while (backlog-- > 0) {
                if (kar_ipsocket__near_8047c54c(info) == NULL) {
                    break;
                }
            }
            break;
        case -7:
            result = -0x2A;
            break;
        default:
            result = -0x1C;
            break;
        }
        break;
    default:
        result = -8;
        break;
    }
    kar_ipsocket__8047a950(node);
    return result;
}

s32 kar_ipsocket__near_8047c8fc(u8* arg1)
{
    return -8;
}

s32 kar_ipsocket__near_8047cbbc(u8* arg1)
{
    SONode* node;
    void* info;
    s32 result;

    if (lbl_805DE68C != 1) {
        return -0x27;
    }
    if (arg1 == NULL || arg1[0] < 8U) {
        return -0x1C;
    }
    node = kar_ipsocket__near_8047a6a8((s32)&info, &info);
    if (node == NULL || info == NULL) {
        return -8;
    }
    switch (FU8(info, 0)) {
    case 17:
        result = fn_8046F320(info, arg1);
        break;
    case 6:
        result = fn_8047567C(info);
        break;
    default:
        kar_ipsocket__8047a950(node);
        return -8;
    }
    kar_ipsocket__8047a950(node);
    switch (result) {
    case 0:
        return 0;
    case -5:
        return -3;
    case -13:
        return -5;
    default:
        return -0x1C;
    }
}

s32 kar_ipsocket__near_8047cce0(s32 arg1)
{
    SONode* node;
    void* info;
    s32 result;

    if (lbl_805DE68C != 1) {
        return -0x27;
    }
    if (arg1 >= 3 || arg1 < 0) {
        return -0x1C;
    }
    node = kar_ipsocket__near_8047a6a8((s32)&info, &info);
    if (node == NULL || info == NULL) {
        return -8;
    }
    switch (FU8(info, 0)) {
    case 17:
        result = 0;
        break;
    case 6:
        result = fn_8047697C(arg1);
        break;
    default:
        kar_ipsocket__8047a950(node);
        return -8;
    }
    kar_ipsocket__8047a950(node);
    if (result == -8 || result == 0) {
        return 0;
    }
    if (result == -4) {
        return -0x38;
    }
    return -0x1C;
}

void kar_ipsocket__near_8047cde4(void)
{
    kar_ipsocket__near_8047ce0c(0, 0, 0, NULL);
}

s32 kar_ipsocket__near_8047ce0c(s32 arg1, s32 arg2, s32 arg3, void* arg4)
{
    s32 flags;
    SONode* node;
    void* info;
    s32 result;

    flags = arg3;
    if (lbl_805DE68C != 1) {
        return -0x27;
    }
    if (arg4 != NULL && *(u8*)arg4 < 8U) {
        return -0x1C;
    }
    node = kar_ipsocket__near_8047a6a8((s32)&info, &info);
    if (node == NULL || info == NULL) {
        return -8;
    }
    switch (FU8(info, 0)) {
    case 17:
        if (flags & ~6) {
            kar_ipsocket__8047a950(node);
            return -0x3F;
        }
        kar_diagnostic__803d7e58((char*)node + 8);
        if (FU32(node, 4) == 0U) {
            result = -8;
        } else {
            if (node->flag & 4) {
                flags |= 4;
            }
            result = fn_8047013C(info, arg1, arg2, 0, arg4, flags);
        }
        kar_diagnostic__803d7f34((char*)node + 8);
        break;
    case 6:
        if (flags & ~7) {
            kar_ipsocket__8047a950(node);
            return -0x3F;
        }
        if (arg4 != NULL && fn_80475608(info, arg4) < 0) {
            kar_ipsocket__8047a950(node);
            return -8;
        }
        kar_diagnostic__803d7e58((char*)node + 8);
        if (FU32(node, 4) == 0U) {
            result = -8;
        } else {
            if (node->flag & 4) {
                flags |= 4;
            }
            if (!(flags & 1)) {
                result = fn_804766F0(arg1, arg2, flags);
            } else {
                result = fn_80476FB0(arg1, arg2, flags);
            }
        }
        kar_diagnostic__803d7f34((char*)node + 8);
        break;
    default:
        kar_ipsocket__8047a950(node);
        return -8;
    }
    kar_ipsocket__8047a950(node);
    if (result < 0) {
        switch (result) {
        case -9:
        case -1:
            result = -6;
            break;
        case -8:
        case -4:
            result = -0x38;
            break;
        case -16:
            result = -0x1B;
            break;
        case -19:
        case -10:
            result = -0x4C;
            break;
        case -18:
        case -11:
        case -3:
            result = -0xF;
            break;
        default:
            result = -0x1C;
            break;
        }
    }
    return result;
}

void kar_ipsocket__near_8047d044(void)
{
    kar_ipsocket__near_8047d06c(0, 0, 0, NULL);
}

s32 kar_ipsocket__near_8047d06c(s32 arg1, s32 arg2, s32 arg3, void* arg4)
{
    s32 flags;
    SONode* node;
    void* info;
    s32 result;

    flags = arg3;
    if (lbl_805DE68C != 1) {
        return -0x27;
    }
    if (arg4 != NULL && *(u8*)arg4 < 8U) {
        return -0x1C;
    }
    node = kar_ipsocket__near_8047a6a8((s32)&info, &info);
    if (node == NULL || info == NULL) {
        return -8;
    }
    switch (FU8(info, 0)) {
    case 17:
        if (flags != 0) {
            kar_ipsocket__8047a950(node);
            return -0x3F;
        }
        kar_diagnostic__803d7e58((char*)node + 0x20);
        if (FU32(node, 4) == 0U) {
            result = -8;
        } else {
            result = fn_8046FC98(info, arg1, arg2, arg4);
        }
        kar_diagnostic__803d7f34((char*)node + 0x20);
        break;
    case 6:
        if (flags & ~5) {
            kar_ipsocket__8047a950(node);
            return -0x3F;
        }
        kar_diagnostic__803d7e58((char*)node + 0x20);
        if (FU32(node, 4) == 0U) {
            result = -8;
        } else {
            if (node->flag & 4) {
                flags |= 4;
            }
            switch (flags) {
            case 0:
                result = fn_804762EC(arg1, arg2);
                break;
            case 1:
                result = fn_80476368(arg1, arg2);
                break;
            case 4:
                result = fn_8047623C(arg1, arg2);
                break;
            case 5:
                result = fn_80476294(arg1, arg2);
                break;
            default:
                result = -8;
                break;
            }
        }
        kar_diagnostic__803d7f34((char*)node + 0x20);
        break;
    default:
        kar_ipsocket__8047a950(node);
        return -8;
    }
    kar_ipsocket__8047a950(node);
    if (result < 0) {
        switch (result) {
        case -13:
            result = -5;
            break;
        case -6:
            result = -0x11;
            break;
        case -17:
            result = -0x23;
            break;
        case -2:
            result = -0x28;
            break;
        case -7:
            result = -0x2A;
            break;
        case -9:
        case -1:
            result = -6;
            break;
        case -8:
        case -4:
            result = -0x38;
            break;
        case -16:
            result = -0x1B;
            break;
        case -10:
            result = -0x4C;
            break;
        case -18:
        case -11:
        case -3:
            result = -0xF;
            break;
        case -12:
            result = -0x1C;
            break;
        case -19:
            result = -0x26;
            break;
        default:
            result = -8;
            break;
        }
    }
    return result;
}

s32 kar_ipsocket__near_8047d2f4(u32 arg1, s32 arg2, s32* arg3, u32 arg4)
{
    SONode* node;
    void* info;
    s32 result;

    node = kar_ipsocket__near_8047a6a8((s32)&info, &info);
    if (node == NULL || info == NULL) {
        return -8;
    }
    switch (FU8(info, 0)) {
    case 17:
        if (arg1 != (u32)-1) {
            result = fn_80470404(arg1, arg2, arg3, arg4);
        } else {
            result = fn_8047726C(info, arg1, arg2, arg3, arg4);
        }
        break;
    case 6:
        if (arg1 != (u32)-1) {
            result = fn_8047726C(info, arg1, arg2, arg3, arg4);
        } else {
            result = fn_8047726C(info, arg1, arg2, arg3, arg4);
        }
        break;
    default:
        kar_ipsocket__8047a950(node);
        return -8;
    }
    kar_ipsocket__8047a950(node);
    switch (result) {
    case 0:
        return 0;
    case -14:
        return -0x33;
    case -7:
        return -0x31;
    default:
        return -0x1C;
    }
}

s32 kar_ipsocket__near_8047d9a4(void)
{
    if (lbl_805DE68C != 1) {
        return -0x27;
    }
    return kar_ipsocket__near_8047d2f4(0, 0, NULL, 0);
}

s32 kar_ipsocket__near_8047d9d8(s32 arg0, s32 arg1, ...)
{
    SONode* node;
    void* info;
    s32 result;

    if (lbl_805DE68C != 1) {
        return -0x27;
    }
    node = kar_ipsocket__near_8047a6a8((s32)&info, &info);
    if (node == NULL || info == NULL) {
        return -8;
    }
    if (FU8(info, 0) != 0x11 && FU8(info, 0) != 6) {
        result = -0xC;
    } else {
        switch (arg1) {
        case 3:
            result = node->flag;
            break;
        case 4:
            result = 0;
            node->flag = 4;
            break;
        default:
            result = -0xC;
            break;
        }
    }
    kar_ipsocket__8047a950(node);
    if (result >= 0) {
        return result;
    }
    return -0x1C;
}

u32 kar_ipsocket__near_8047db1c(void)
{
    s32 v;
    fn_8046D7FC(0, &v);
    return (u32)v;
}

void kar_ipsocket__near_8047db48(void)
{
    OSWakeupThread(&lbl_805DE6B0);
}

void kar_ipsocket__near_8047db6c(void)
{
    OSWakeupThread(&lbl_805DE6B0);
}

s32 kar_ipsocket__near_8047db90(s32* arg0, u32 arg1, s32 arg2, s32 arg3)
{
    s32* p;
    u32 i;
    s32 level;
    s32 ready;
    OSAlarm alarm;
    s32 haveTimeout;

    if (lbl_805DE68C != 1) {
        return -0x27;
    }
    if (arg1 > 0x100U) {
        return -0x1C;
    }

    level = OSDisableInterrupts();
    p = arg0;
    for (i = 0; i < arg1; i++, p += 2) {
        s32 fd = p[0];
        p[1] = (p[1] & 0xFFFF0000) | 0;
        if (fd >= 0 && fd < 0x100) {
            SONode* n = &lbl_805BE4B0[fd];
            if (n->ref > 0 && n->info != NULL) {
                n->ref++;
            }
        }
    }
    OSRestoreInterrupts(level);

    haveTimeout = (arg2 != 0 || arg3 != -1);
    if (haveTimeout && arg3 != -1) {
        OSCreateAlarm(&alarm);
        OSSetAlarm(&alarm, 0, NULL);
    }

    level = OSDisableInterrupts();
    ready = 0;
    while (lbl_805DE68C == 1) {
        p = arg0;
        for (i = 0; i < arg1; i++, p += 2) {
            s32 fd = p[0];
            void* info = NULL;
            if (fd >= 0 && fd < 0x100) {
                SONode* n = &lbl_805BE4B0[fd];
                if (n->ref > 0 && n->info != NULL) {
                    info = n->info;
                }
            }
            if (info != NULL) {
                s16 want = (s16)(p[1] | 0xE0);
                s16 got;
                switch (FU8(info, 0)) {
                case 17:
                    got = want & fn_804704E4();
                    break;
                case 6:
                    got = want & fn_80477508();
                    break;
                default:
                    got = 0;
                    break;
                }
                if (got != 0) {
                    p[1] = (p[1] & 0xFFFF) | ((u32)got << 16);
                    ready++;
                }
            }
        }
        if (ready <= 0 && haveTimeout) {
            OSSleepThread(&lbl_805DE6B0);
            continue;
        }
        break;
    }
    OSRestoreInterrupts(level);
    if (haveTimeout && arg3 != -1) {
        OSCancelAlarm(&alarm);
    }

    p = arg0;
    for (i = 0; i < arg1; i++, p += 2) {
        s32 fd = p[0];
        if (fd >= 0 && fd < 0x100) {
            SONode* n = &lbl_805BE4B0[fd];
            if (n->ref > 0 && n->info != NULL) {
                level = OSDisableInterrupts();
                n->ref--;
                OSRestoreInterrupts(level);
                kar_ipsocket__8047a950(n);
            }
        }
    }
    return ready;
}

s32 fn_8047DE78(void)
{
    lbl_805DE68C = 3;
    return 1;
}

void kar_ipsocket__near_8047de88(void* arg0, u8 arg1, s8 arg2, s32 arg3, void* arg4)
{
    void* iface;
    void* pkt;
    s32 len;
    s32 level;
    u16 mru;

    len = arg3;
    iface = FPTR(arg0, 0x260);
    level = OSDisableInterrupts();
    if (arg1 == 1 || arg1 == 5) {
        OSCancelAlarm((OSAlarm*)((char*)arg0 + 0x238));
        OSSetAlarm((OSAlarm*)((char*)arg0 + 0x238), 3, NULL);
    }
    mru = FU16(FPTR(iface, 0x58), 0x288);
    if ((s32)mru < len + 4) {
        len = mru - 4;
    }
    pkt = ((void* (*)(void*, s32))FPTR(iface, 0x68))(iface, len + 0x42);
    if (pkt != NULL) {
        void* hdr = (char*)pkt + 0x3C;
        FU16(hdr, 0) = FU16(arg0, 0);
        FU8(hdr, 2) = arg1;
        FS8(hdr, 3) = arg2;
        FS16(hdr, 4) = (s16)(len + 4);
        memmove((char*)hdr + 6, arg4, len);
        FS32(pkt, 0x30) = 1;
        FPTR(pkt, 0x34) = hdr;
        FS32(pkt, 0x38) = len + 6;
        FS32(pkt, 0x28) = 0;
        FS32(pkt, 0x2C) = 0;
        FU16(pkt, 0x10) = 0x8864;
        FU8(pkt, 0x25) = 0;
        FS32(pkt, 4) = 0;
        ((void (*)(void*, void*, s32))FPTR(iface, 0x60))(iface, pkt, 0);
    }
    OSRestoreInterrupts(level);
}

void kar_ipsocket__near_8047dfdc(void* arg0, void* arg1)
{
    s32 valid = ((s32 (*)(void*))FPTR(arg0, 0x264))(arg0);
    s32 state = FS32(arg0, 4);
    if (valid == 0) {
        switch (state) {
        case 2:
            kar_ipsocket__near_8047de88(arg0, 6, FU8(arg0, 9), 0U, NULL);
            return;
        case 3:
            FS32(arg0, 0xC) = 0;
            FS32(arg0, 0x10) = 0xA;
            FS32(arg0, 0x14) = 2;
            FS32(arg0, 0x18) = 5;
            FU8(arg0, 8) = FU8(arg0, 8) + 1;
            if (FS32(arg0, 0x10) > 0) {
                FS32(arg0, 0x10) -= 1;
                kar_ipsocket__near_8047de88(arg0, 1, FU8(arg0, 8), FS32(arg0, 0x230), (char*)arg0 + 0x21C);
            }
            FS32(arg0, 0x18) = 5;
            kar_ipsocket__near_8047de88(arg0, 2, FU8(arg1, 1), FS16(arg1, 2) - 4, (char*)arg1 + 4);
            FS32(arg0, 4) = 8;
            return;
        case 6:
            FS32(arg0, 0x18) = 5;
            kar_ipsocket__near_8047de88(arg0, 2, FU8(arg1, 1), FS16(arg1, 2) - 4, (char*)arg1 + 4);
            FS32(arg0, 4) = 8;
            return;
        case 7:
            FS32(arg0, 0x18) = 5;
            kar_ipsocket__near_8047de88(arg0, 2, FU8(arg1, 1), FS16(arg1, 2) - 4, (char*)arg1 + 4);
            ((void (*)(void*))FPTR(arg0, 0x274))(arg0);
            FS32(arg0, 4) = 9;
            return;
        case 8:
            FS32(arg0, 0x18) = 5;
            kar_ipsocket__near_8047de88(arg0, 2, FU8(arg1, 1), FS16(arg1, 2) - 4, (char*)arg1 + 4);
            return;
        case 9:
            OSCancelAlarm((OSAlarm*)((char*)arg0 + 0x238));
            ((void (*)(void*))FPTR(arg0, 0x278))(arg0);
            if (FS32(arg0, 0x10) > 0) {
                FS32(arg0, 0x10) -= 1;
                kar_ipsocket__near_8047de88(arg0, 1, FU8(arg0, 8), FS32(arg0, 0x230), (char*)arg0 + 0x21C);
            }
            FS32(arg0, 0x18) = 5;
            kar_ipsocket__near_8047de88(arg0, 2, FU8(arg1, 1), FS16(arg1, 2) - 4, (char*)arg1 + 4);
            FS32(arg0, 4) = 8;
            return;
        default:
            return;
        }
    } else if (valid == -1) {
        switch (state) {
        case 2:
            kar_ipsocket__near_8047de88(arg0, 6, FU8(arg0, 9), 0U, NULL);
            return;
        case 3:
            FS32(arg0, 0xC) = 0;
            FS32(arg0, 0x10) = 0xA;
            FS32(arg0, 0x14) = 2;
            FS32(arg0, 0x18) = 5;
            FU8(arg0, 8) = FU8(arg0, 8) + 1;
            if (FS32(arg0, 0x10) > 0) {
                FS32(arg0, 0x10) -= 1;
                kar_ipsocket__near_8047de88(arg0, 1, FU8(arg0, 8), FS32(arg0, 0x230), (char*)arg0 + 0x21C);
            }
            kar_ipsocket__near_8047de88(arg0, 4, FU8(arg1, 1), FS16(arg1, 2) - 4, (char*)arg1 + 4);
            FS32(arg0, 4) = 6;
            return;
        case 6:
        case 7:
            kar_ipsocket__near_8047de88(arg0, 4, FU8(arg1, 1), FS16(arg1, 2) - 4, (char*)arg1 + 4);
            return;
        case 8:
            kar_ipsocket__near_8047de88(arg0, 4, FU8(arg1, 1), FS16(arg1, 2) - 4, (char*)arg1 + 4);
            FS32(arg0, 4) = 6;
            return;
        case 9:
            OSCancelAlarm((OSAlarm*)((char*)arg0 + 0x238));
            ((void (*)(void*))FPTR(arg0, 0x278))(arg0);
            if (FS32(arg0, 0x10) > 0) {
                FS32(arg0, 0x10) -= 1;
                kar_ipsocket__near_8047de88(arg0, 1, FU8(arg0, 8), FS32(arg0, 0x230), (char*)arg0 + 0x21C);
            }
            kar_ipsocket__near_8047de88(arg0, 4, FU8(arg1, 1), FS16(arg1, 2) - 4, (char*)arg1 + 4);
            FS32(arg0, 4) = 6;
            return;
        }
    } else {
        switch (state) {
        case 2:
            kar_ipsocket__near_8047de88(arg0, 6, FU8(arg0, 9), 0U, NULL);
            return;
        case 3:
            FS32(arg0, 0xC) = 0;
            FS32(arg0, 0x10) = 0xA;
            FS32(arg0, 0x14) = 2;
            FS32(arg0, 0x18) = 5;
            FU8(arg0, 8) = FU8(arg0, 8) + 1;
            if (FS32(arg0, 0x10) > 0) {
                FS32(arg0, 0x10) -= 1;
                kar_ipsocket__near_8047de88(arg0, 1, FU8(arg0, 8), FS32(arg0, 0x230), (char*)arg0 + 0x21C);
            }
            FS32(arg0, 0x18) -= 1;
            kar_ipsocket__near_8047de88(arg0, 3, FU8(arg1, 1), FS16(arg1, 2) - 4, (char*)arg1 + 4);
            FS32(arg0, 4) = 6;
            return;
        case 6:
        case 7:
            FS32(arg0, 0x18) -= 1;
            kar_ipsocket__near_8047de88(arg0, 3, FU8(arg1, 1), FS16(arg1, 2) - 4, (char*)arg1 + 4);
            return;
        case 8:
            FS32(arg0, 0x18) -= 1;
            kar_ipsocket__near_8047de88(arg0, 3, FU8(arg1, 1), FS16(arg1, 2) - 4, (char*)arg1 + 4);
            FS32(arg0, 4) = 6;
            return;
        case 9:
            OSCancelAlarm((OSAlarm*)((char*)arg0 + 0x238));
            ((void (*)(void*))FPTR(arg0, 0x278))(arg0);
            if (FS32(arg0, 0x10) > 0) {
                FS32(arg0, 0x10) -= 1;
                kar_ipsocket__near_8047de88(arg0, 1, FU8(arg0, 8), FS32(arg0, 0x230), (char*)arg0 + 0x21C);
            }
            FS32(arg0, 0x18) -= 1;
            kar_ipsocket__near_8047de88(arg0, 3, FU8(arg1, 1), FS16(arg1, 2) - 4, (char*)arg1 + 4);
            FS32(arg0, 4) = 6;
            return;
        }
    }
}

void kar_ipsocket__near_8047e574(void* arg0)
{
    if (((s32 (*)(void*))FPTR(arg0, 0x268))(arg0) != 0) {
        s32 state = FS32(arg0, 4);
        switch (state) {
        case 2:
        case 3:
            kar_ipsocket__near_8047de88(arg0, 6, FU8(arg0, 9), 0U, NULL);
            return;
        case 6:
            FS32(arg0, 0xC) = 0;
            FS32(arg0, 0x10) = 0xA;
            FS32(arg0, 0x14) = 2;
            FS32(arg0, 0x18) = 5;
            FU8(arg0, 8) = FU8(arg0, 8) + 1;
            FS32(arg0, 4) = 7;
            return;
        case 7:
            if (FS32(arg0, 0x10) > 0) {
                FS32(arg0, 0x10) -= 1;
                kar_ipsocket__near_8047de88(arg0, 1, FU8(arg0, 8), FS32(arg0, 0x230), (char*)arg0 + 0x21C);
            }
            return;
        case 8: {
            u8 id = FU8(arg0, 8);
            FU8(arg0, 8) = id + 1;
            FS32(arg0, 0xC) = 0;
            FS32(arg0, 0x10) = 0xA;
            FS32(arg0, 0x14) = 2;
            FS32(arg0, 0x18) = 5;
            ((void (*)(void*, u8))FPTR(arg0, 0x274))(arg0, id);
            FS32(arg0, 4) = 9;
            return;
        }
        case 9:
            if (FS32(arg0, 0x10) > 0) {
                FS32(arg0, 0x10) -= 1;
                kar_ipsocket__near_8047de88(arg0, 1, FU8(arg0, 8), FS32(arg0, 0x230), (char*)arg0 + 0x21C);
            }
            FS32(arg0, 4) = 6;
            return;
        }
    }
}

void kar_ipsocket__near_8047e6f0(void* arg0)
{
    s32 valid = ((s32 (*)(void*))FPTR(arg0, 0x26C))(arg0);
    s32 state = FS32(arg0, 4);
    if (valid == 0) {
        return;
    }
    switch (state) {
    case 2:
    case 3:
        kar_ipsocket__near_8047de88(arg0, 6, FU8(arg0, 9), 0U, NULL);
        return;
    case 6:
        FS32(arg0, 0xC) = 0;
        FS32(arg0, 0x10) = 0xA;
        FS32(arg0, 0x14) = 2;
        FS32(arg0, 0x18) = 5;
        FU8(arg0, 8) = FU8(arg0, 8) + 1;
        if (FS32(arg0, 0x10) > 0) {
            FS32(arg0, 0x10) -= 1;
            kar_ipsocket__near_8047de88(arg0, 1, FU8(arg0, 8), FS32(arg0, 0x230), (char*)arg0 + 0x21C);
            return;
        }
        return;
    case 7:
        if (FS32(arg0, 0x10) > 0) {
            FS32(arg0, 0x10) -= 1;
            kar_ipsocket__near_8047de88(arg0, 1, FU8(arg0, 8), FS32(arg0, 0x230), (char*)arg0 + 0x21C);
            return;
        }
        return;
    case 8:
        FS32(arg0, 0xC) = 0;
        FS32(arg0, 0x10) = 0xA;
        FS32(arg0, 0x14) = 2;
        FS32(arg0, 0x18) = 5;
        FU8(arg0, 8) = FU8(arg0, 8) + 1;
        if (FS32(arg0, 0x10) > 0) {
            FS32(arg0, 0x10) -= 1;
            kar_ipsocket__near_8047de88(arg0, 1, FU8(arg0, 8), FS32(arg0, 0x230), (char*)arg0 + 0x21C);
            return;
        }
        return;
    case 9:
        OSCancelAlarm((OSAlarm*)((char*)arg0 + 0x238));
        ((void (*)(void*))FPTR(arg0, 0x278))(arg0);
        if (FS32(arg0, 0x10) > 0) {
            FS32(arg0, 0x10) -= 1;
            kar_ipsocket__near_8047de88(arg0, 1, FU8(arg0, 8), FS32(arg0, 0x230), (char*)arg0 + 0x21C);
        }
        FS32(arg0, 4) = 6;
        return;
    }
}

void kar_ipsocket__near_8047e8bc(void* arg0)
{
    kar_ipsocket__near_8047e6f0(arg0);
}

void kar_ipsocket__near_8047ea88(void* arg0, void* arg1)
{
    s32 state;

    FU8(arg0, 9) = FU8(arg1, 1);
    state = FS32(arg0, 4);
    switch (state) {
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        kar_ipsocket__near_8047de88(arg0, 6, FU8(arg0, 9), 0, NULL);
        return;
    case 7:
    case 8:
        kar_ipsocket__near_8047de88(arg0, 6, FU8(arg0, 9), 0, NULL);
        FS32(arg0, 4) = 6;
        return;
    case 9:
        OSCancelAlarm((OSAlarm*)((char*)arg0 + 0x238));
        ((void (*)(void*))FPTR(arg0, 0x278))(arg0);
        FS32(arg0, 0xC) = 0;
        FS32(arg0, 0x10) = 0;
        FS32(arg0, 0x14) = 0;
        FS32(arg0, 0x18) = 0;
        kar_ipsocket__near_8047de88(arg0, 6, FU8(arg0, 9), 0, NULL);
        FS32(arg0, 4) = 5;
        return;
    default:
        return;
    }
}

void kar_ipsocket__near_8047ebfc(void* arg0)
{
    s32 state = FS32(arg0, 4);
    switch (state) {
    case 4:
        OSCancelAlarm((OSAlarm*)((char*)arg0 + 0x238));
        ((void (*)(void*))FPTR(arg0, 0x280))(arg0);
        FS32(arg0, 4) = 2;
        return;
    case 5:
        OSCancelAlarm((OSAlarm*)((char*)arg0 + 0x238));
        ((void (*)(void*))FPTR(arg0, 0x280))(arg0);
        FS32(arg0, 4) = 3;
        return;
    case 7:
        FS32(arg0, 4) = 6;
        return;
    case 9:
        OSCancelAlarm((OSAlarm*)((char*)arg0 + 0x238));
        ((void (*)(void*))FPTR(arg0, 0x278))(arg0);
        if (FS32(arg0, 0x10) > 0) {
            FS32(arg0, 0x10) -= 1;
            kar_ipsocket__near_8047de88(arg0, 1, FU8(arg0, 8), FS32(arg0, 0x230), (char*)arg0 + 0x21C);
        }
        FS32(arg0, 4) = 6;
        return;
    }
}

void kar_ipsocket__near_8047ecf8(void* arg0, void* arg1)
{
    FU8(arg0, 0xA) = FU8(arg0, 0xA) + 1;
    kar_ipsocket__near_8047de88(arg0, 7, FU8(arg0, 0xA), FS16(arg1, 2), NULL);
}

void kar_ipsocket__near_8047ee38(void* arg0)
{
    s32 state = FS32(arg0, 4);
    switch (state) {
    case 2:
    case 3:
        OSCancelAlarm((OSAlarm*)((char*)arg0 + 0x238));
        ((void (*)(void*))FPTR(arg0, 0x280))(arg0);
        return;
    case 4:
        OSCancelAlarm((OSAlarm*)((char*)arg0 + 0x238));
        ((void (*)(void*))FPTR(arg0, 0x280))(arg0);
        FS32(arg0, 4) = 2;
        return;
    case 5:
    case 6:
    case 7:
    case 8:
        OSCancelAlarm((OSAlarm*)((char*)arg0 + 0x238));
        ((void (*)(void*))FPTR(arg0, 0x280))(arg0);
        FS32(arg0, 4) = 3;
        return;
    case 9:
        OSCancelAlarm((OSAlarm*)((char*)arg0 + 0x238));
        ((void (*)(void*))FPTR(arg0, 0x278))(arg0);
        FS32(arg0, 0xC) = 0;
        FS32(arg0, 0x10) = 0xA;
        FS32(arg0, 0x14) = 2;
        FS32(arg0, 0x18) = 5;
        FU8(arg0, 8) = FU8(arg0, 8) + 1;
        FS32(arg0, 4) = 5;
        return;
    default:
        return;
    }
}

void kar_ipsocket__near_8047efb8(void* arg0)
{
    kar_ipsocket__near_8047ee38(arg0);
}

void kar_ipsocket__near_8047f138(void* arg0, void* arg1, s32 arg2)
{
    u16 len;
    u8 code;

    if (arg0 == NULL || arg2 < 4) {
        return;
    }
    len = FU16(arg1, 2);
    if (arg2 < (s32)len) {
        return;
    }
    if (len < 4U) {
        return;
    }
    code = FU8(arg1, 0);
    switch (code) {
    case 1:
        kar_ipsocket__near_8047dfdc(arg0, arg1);
        return;
    case 2:
        if (FU8(arg1, 1) == FU8(arg0, 8)) {
            OSCancelAlarm((OSAlarm*)((char*)arg0 + 0x238));
            kar_ipsocket__near_8047e574(arg0);
        }
        return;
    case 3:
        if (FU8(arg1, 1) == FU8(arg0, 8)) {
            OSCancelAlarm((OSAlarm*)((char*)arg0 + 0x238));
            kar_ipsocket__near_8047e6f0(arg0);
        }
        return;
    case 4:
        if (FU8(arg1, 1) == FU8(arg0, 8)) {
            OSCancelAlarm((OSAlarm*)((char*)arg0 + 0x238));
            kar_ipsocket__near_8047e8bc(arg0);
        }
        return;
    case 5:
        kar_ipsocket__near_8047ea88(arg0, arg1);
        return;
    case 6:
        if (FU8(arg1, 1) == FU8(arg0, 8)) {
            OSCancelAlarm((OSAlarm*)((char*)arg0 + 0x238));
            kar_ipsocket__near_8047ebfc(arg0);
        }
        return;
    case 7:
        kar_ipsocket__near_8047ee38(arg0);
        return;
    case 8:
        kar_ipsocket__near_8047efb8(arg0);
        return;
    case 9:
        FU8(arg0, 0xB) = FU8(arg1, 1);
        if (FS32(arg0, 4) != 9) {
            return;
        }
        kar_ipsocket__near_8047de88(arg0, 0xA, FU8(arg0, 0xB), FS16(arg1, 2) - 4, (char*)arg1 + 4);
        return;
    default:
        kar_ipsocket__near_8047ecf8(arg0, arg1);
        return;
    }
}

void kar_ipsocket__near_8047f2d8(void* arg0, void* arg1, s32 arg2)
{
    u16 proto;

    if (arg2 < 2) {
        return;
    }
    proto = FU16(arg1, 0);
    switch (proto) {
    case 0xC021:
        kar_ipsocket__near_8047f138(FPTR(arg0, 0x58), (char*)arg1 + 2, arg2 - 2);
        return;
    case 0x8021:
        kar_ipsocket__near_8047f138(FPTR(arg0, 0x5C), (char*)arg1 + 2, arg2 - 2);
        return;
    case 0xC023:
        kar_ipsocket__near_80481678(arg0, (char*)arg1 + 2, arg2 - 2);
        return;
    case 0xC223:
        kar_ipsocket__near_80481854(arg0, (char*)arg1 + 2, arg2 - 2);
        return;
    case 0x21:
        fn_8046B2A8((char*)arg1 + 2, arg2 - 2);
        return;
    default: {
        void* lcp = FPTR(arg0, 0x58);
        if (FS32(lcp, 4) == 9) {
            FU8(lcp, 0xA) = FU8(lcp, 0xA) + 1;
            kar_ipsocket__near_8047de88(lcp, 8, FU8(lcp, 0xA), FU16(arg1, 0), (char*)arg1 + 2);
        }
        break;
    }
    }
}

void kar_ipsocket__near_8047f3dc(void* arg0)
{
    s32 state = FS32(arg0, 4);
    switch (state) {
    case 0:
        ((void (*)(void*))FPTR(arg0, 0x27C))(arg0);
        FS32(arg0, 4) = 1;
        return;
    case 2:
        FS32(arg0, 0xC) = 0;
        FS32(arg0, 0x10) = 0xA;
        FS32(arg0, 0x14) = 2;
        FS32(arg0, 0x18) = 5;
        FU8(arg0, 8) = FU8(arg0, 8) + 1;
        if (FS32(arg0, 0x10) > 0) {
            FS32(arg0, 0x10) -= 1;
            kar_ipsocket__near_8047de88(arg0, 1, FU8(arg0, 8), FS32(arg0, 0x230), (char*)arg0 + 0x21C);
        }
        FS32(arg0, 4) = 6;
        return;
    case 4:
        FS32(arg0, 4) = 5;
        return;
    default:
        return;
    }
}

void kar_ipsocket__near_8047f4c8(void* arg0)
{
    s32 state = FS32(arg0, 4);
    switch (state) {
    case 0:
        FS32(arg0, 4) = 2;
        return;
    case 1:
        FS32(arg0, 0xC) = 0;
        FS32(arg0, 0x10) = 0xA;
        FS32(arg0, 0x14) = 2;
        FS32(arg0, 0x18) = 5;
        FU8(arg0, 8) = FU8(arg0, 8) + 1;
        if (FS32(arg0, 0x10) > 0) {
            FS32(arg0, 0x10) -= 1;
            kar_ipsocket__near_8047de88(arg0, 1, FU8(arg0, 8), FS32(arg0, 0x230), (char*)arg0 + 0x21C);
        }
        FS32(arg0, 4) = 6;
        return;
    }
}

void kar_ipsocket__near_8047f578(void* arg0)
{
    s32 state = FS32(arg0, 4);
    switch (state) {
    case 2:
    case 4:
        FS32(arg0, 4) = 0;
        return;
    case 3:
        ((void (*)(void*))FPTR(arg0, 0x27C))(arg0);
        FS32(arg0, 4) = 1;
        return;
    case 5:
    case 6:
    case 7:
    case 8:
        FS32(arg0, 4) = 1;
        return;
    case 9:
        OSCancelAlarm((OSAlarm*)((char*)arg0 + 0x238));
        ((void (*)(void*))FPTR(arg0, 0x278))(arg0);
        FS32(arg0, 4) = 1;
        return;
    default:
        return;
    }
}

void kar_ipsocket__near_8047f648(void* arg0)
{
    switch (FU32(arg0, 4)) {
    case 1:
        OSCancelAlarm((OSAlarm*)((char*)arg0 + 0x238));
        ((void (*)(void*))FPTR(arg0, 0x280))(arg0);
        FS32(arg0, 4) = 0;
        return;
    case 3:
        FS32(arg0, 4) = 2;
        return;
    case 5:
        FS32(arg0, 4) = 4;
        return;
    case 6:
    case 7:
    case 8:
        FS32(arg0, 0xC) = 0;
        FS32(arg0, 0x10) = 0xA;
        FS32(arg0, 0x14) = 2;
        FS32(arg0, 0x18) = 5;
        FU8(arg0, 8) = FU8(arg0, 8) + 1;
        if (FS32(arg0, 0x14) > 0) {
            FS32(arg0, 0x14) -= 1;
            kar_ipsocket__near_8047de88(arg0, 5, FU8(arg0, 8), 0, NULL);
        }
        FS32(arg0, 4) = 4;
        return;
    case 9:
        OSCancelAlarm((OSAlarm*)((char*)arg0 + 0x238));
        ((void (*)(void*))FPTR(arg0, 0x278))(arg0);
        FS32(arg0, 0xC) = 0;
        FS32(arg0, 0x10) = 0xA;
        FS32(arg0, 0x14) = 2;
        FS32(arg0, 0x18) = 5;
        FU8(arg0, 8) = FU8(arg0, 8) + 1;
        if (FS32(arg0, 0x14) > 0) {
            FS32(arg0, 0x14) -= 1;
            kar_ipsocket__near_8047de88(arg0, 5, FU8(arg0, 8), 0, NULL);
        }
        FS32(arg0, 4) = 4;
        return;
    default:
        return;
    }
}

void kar_ipsocket__near_8047f874(void* arg0)
{
    void* lcp;
    s32 haveRetry;

    lcp = (char*)arg0 - 0x238;
    FS32(lcp, 0xC) = FS32(lcp, 0xC) + 1;
    switch (FS32(lcp, 4)) {
    case 4:
        haveRetry = 0;
        if (FS32(lcp, 0x14) > 0) {
            FS32(lcp, 0x14) -= 1;
            kar_ipsocket__near_8047de88(lcp, 5, FU8(lcp, 8), 0U, NULL);
            haveRetry = 1;
        }
        if (!haveRetry) {
            OSCancelAlarm((OSAlarm*)((char*)lcp + 0x238));
            ((void (*)(void*))FPTR(lcp, 0x280))(lcp);
            FS32(lcp, 4) = 2;
        }
        return;
    case 5:
        haveRetry = 0;
        if (FS32(lcp, 0x14) > 0) {
            FS32(lcp, 0x14) -= 1;
            kar_ipsocket__near_8047de88(lcp, 5, FU8(lcp, 8), 0U, NULL);
            haveRetry = 1;
        }
        if (!haveRetry) {
            OSCancelAlarm((OSAlarm*)((char*)lcp + 0x238));
            ((void (*)(void*))FPTR(lcp, 0x280))(lcp);
            FS32(lcp, 4) = 3;
        }
        return;
    case 6:
        haveRetry = 0;
        if (FS32(lcp, 0x10) > 0) {
            FS32(lcp, 0x10) -= 1;
            kar_ipsocket__near_8047de88(lcp, 1, FU8(lcp, 8), FS32(lcp, 0x230), (char*)lcp + 0x21C);
            haveRetry = 1;
        }
        if (!haveRetry) {
            OSCancelAlarm((OSAlarm*)((char*)lcp + 0x238));
            ((void (*)(void*))FPTR(lcp, 0x280))(lcp);
            FS32(lcp, 4) = 3;
        }
        return;
    case 7:
        haveRetry = 0;
        if (FS32(lcp, 0x10) > 0) {
            FS32(lcp, 0x10) -= 1;
            kar_ipsocket__near_8047de88(lcp, 1, FU8(lcp, 8), FS32(lcp, 0x230), (char*)lcp + 0x21C);
            haveRetry = 1;
        }
        if (haveRetry) {
            FS32(lcp, 4) = 6;
            return;
        }
        OSCancelAlarm((OSAlarm*)((char*)lcp + 0x238));
        ((void (*)(void*))FPTR(lcp, 0x280))(lcp);
        FS32(lcp, 4) = 3;
        return;
    case 8:
        haveRetry = 0;
        if (FS32(lcp, 0x10) > 0) {
            FS32(lcp, 0x10) -= 1;
            kar_ipsocket__near_8047de88(lcp, 1, FU8(lcp, 8), FS32(lcp, 0x230), (char*)lcp + 0x21C);
            haveRetry = 1;
        }
        if (!haveRetry) {
            OSCancelAlarm((OSAlarm*)((char*)lcp + 0x238));
            ((void (*)(void*))FPTR(lcp, 0x280))(lcp);
            FS32(lcp, 4) = 3;
        }
        return;
    }
}

s32 kar_ipsocket__near_8047fad4(char* arg0, u16 arg1, u8* arg2)
{
    u8 optLen;
    u8* next;

    optLen = arg2[1];
    next = arg2 + optLen;
    memmove(arg2, next, (arg0 + arg1) - (char*)next);
    return arg1 - optLen;
}

s32 kar_ipsocket__near_8047fb24(char* arg0, u16 arg1, u8* arg2, u8* arg3)
{
    u8 optLen = arg3[1];
    memmove(arg2 + optLen, arg2, (arg0 + arg1) - (char*)arg2);
    memmove(arg2, arg3, optLen);
    return arg1 + optLen;
}

s32 kar_ipsocket__near_8047fb9c(void* arg0, void* arg1, void* arg2, s32 arg3, u32 arg4)
{
    if (kar_ipsocket__near_80480d88(arg1, arg0, (const char*)arg3, (const char*)arg4) == 0) {
        return 0;
    }
    kar_ipsocket__near_8048138c(arg2, arg0);
    FPTR(arg1, 0x284) = arg2;
    FPTR(arg2, 0x284) = NULL;
    FPTR(arg0, 0x58) = arg1;
    FPTR(arg0, 0x5C) = arg2;
    return 1;
}

void kar_ipsocket__near_8047fc24(void* arg0, u8* arg1, s16 arg2)
{
    s32 level;
    void* pkt;
    void* hdr;

    level = OSDisableInterrupts();
    pkt = ((void* (*)(void*, s32))FPTR(arg0, 0x68))(arg0, 0x42);
    hdr = (char*)pkt + 0x3C;
    if (pkt != NULL) {
        FU16(pkt, 0x3C) = 0x11;
        FU8(hdr, 1) = 0xA7;
        FS16(hdr, 2) = arg2;
        FS32(hdr, 4) = 0;
        FS32(pkt, 0x30) = 1;
        FPTR(pkt, 0x34) = hdr;
        FS32(pkt, 0x38) = 6;
        FS32(pkt, 0x28) = 0;
        FS32(pkt, 0x2C) = 0;
        FU16(pkt, 0x10) = 0x8863;
        FU8(pkt, 0x25) = 0;
        memmove((char*)pkt + 0x12, arg1, 6U);
        FS32(pkt, 4) = 0;
        ((void (*)(void*, void*))FPTR(lbl_80534558, 0x624))(arg0, pkt);
    }
    OSRestoreInterrupts(level);
}

void kar_ipsocket__near_8047fcfc(void* arg0, void* arg1)
{
    s32 level;
    void* pkt;

    level = OSDisableInterrupts();
    OSCancelAlarm((OSAlarm*)((char*)arg1 + 0x10));
    OSSetAlarm((OSAlarm*)((char*)arg1 + 0x10), 3, NULL);
    if (FU8(arg1, 0) == 0xA7) {
        kar_ipsocket__near_8047fc24(arg0, (u8*)arg1 + 0x38, FS16(arg1, 2));
    } else {
        pkt = ((void* (*)(void*, s32))FPTR(arg0, 0x68))(arg0, 0x3C);
        FU8(arg1, 0x3F) = FU8(arg1, 0);
        FU16(arg1, 0x40) = FU16(arg1, 2);
        FU16(arg1, 0x42) = FU16(arg1, 0x61A);
        if (pkt != NULL) {
            s32 len = FU16(arg1, 0x61A) + 6;
            FS32(pkt, 0x30) = 1;
            FPTR(pkt, 0x34) = (char*)arg1 + 0x3E;
            FS32(pkt, 0x38) = len;
            FS32(pkt, 0x28) = 0;
            FS32(pkt, 0x2C) = 0;
            FU16(pkt, 0x10) = 0x8863;
            FU8(pkt, 0x25) = 0;
            memmove((char*)pkt + 0x12, (char*)arg1 + 0x38, 6U);
            FS32(pkt, 4) = 0;
            ((void (*)(void*, void*))FPTR(arg1, 0x624))(arg0, pkt);
        }
    }
    OSRestoreInterrupts(level);
}

void kar_ipsocket__near_8047fe2c(void* arg0)
{
    void* self;
    u16 tries;

    self = (char*)arg0 - 0x10;
    tries = FU16(self, 0x60C) + 1;
    FU16(self, 0x61C) = tries;
    if (tries > 6U) {
        fn_8046F190(FPTR(self, 0x620), -0x67);
        OSCancelAlarm((OSAlarm*)((char*)self + 0x10));
        FS32(arg0, -0x10) = 0;
        FU16(self, 2) = 0xFFFF;
        FU16(self, 4) = 0xFFFF;
        FS32(FPTR(self, 0x620), 0x40) = 0x5DC;
        return;
    }
    kar_ipsocket__near_8047fcfc(FPTR(self, 0x620), self);
}

void kar_ipsocket__near_8047feb4(s32 arg0, void* arg1)
{
    u16 sum;
    u16 proto;

    if (FU16(arg1, 0x10) != 0x800 || fn_8046DC28(arg0, (char*)arg1 + 0x18) == 0) {
        FU8(arg1, 0x1C) = 0x11;
        FU8(arg1, 0x1D) = FU8(lbl_80534558, 0);
        FU16(arg1, 0x1E) = FU16(lbl_80534558, 2);
        sum = 0;
        FU16(arg1, 0x20) = 0;
        proto = FU16(arg1, 0x10);
        switch (proto) {
        case 0x800:
            FU16(arg1, 0x22) = 0x21;
            FU16(arg1, 0x24) = 8;
            FU16(arg1, 0x10) = 0x8864;
            break;
        case 0x8864:
            FU16(arg1, 0x24) = 6;
            break;
        default:
            FU16(arg1, 0x24) = 0;
            break;
        }
        if (FU16(arg1, 0x10) == 0x8864) {
            memmove((char*)arg1 + 0x12, lbl_80534558 + 0x38, 6U);
        }
    }
    ((void (*)(s32, void*))FPTR(lbl_80534558, 0x624))(arg0, arg1);
}

s32 kar_ipsocket__near_804800e4(void* arg0, u32 arg1, u32 arg2)
{
    void* iface;
    void* oldOut;

    if (FU16(lbl_80534558, 2) != 0xFFFFU) {
        return 0;
    }
    iface = (arg0 != NULL) ? arg0 : lbl_805BDD20;
    if (kar_ipsocket__near_8047fb9c(iface, lbl_805C2448, lbl_805C2448 + 0x298, arg1, arg2) == 0) {
        return 0;
    }
    FS32(lbl_805C2448, 0x288) = 0x5D4;
    FU8(lbl_80534558, 0) = 9;
    FU16(lbl_80534558, 0x61A) = 4;
    FU16(lbl_80534558, 2) = 0;
    memset(lbl_80534558 + 0x38, 0xFF, 6);
    OSCreateAlarm((OSAlarm*)(lbl_80534558 + 0x10));
    FU16(lbl_80534558, 0x61C) = 0;
    FU16(lbl_80534558, 0x3E) = 0x11;
    FU8(lbl_80534558, 0x3F) = FU8(lbl_80534558, 0);
    FU16(lbl_80534558, 0x40) = FU16(lbl_80534558, 2);
    FU16(lbl_80534558, 0x42) = FU16(lbl_80534558, 0x61A);
    FU16(lbl_80534558, 0x44) = 0x101;
    FU16(lbl_80534558, 0x46) = 0;
    FPTR(lbl_80534558, 0x620) = iface;
    oldOut = FPTR(iface, 0x60);
    FPTR(lbl_80534558, 0x624) = oldOut;
    FPTR(iface, 0x60) = (void*)kar_ipsocket__near_8047feb4;
    kar_ipsocket__near_8047fcfc(iface, lbl_80534558);
    return 1;
}

void kar_ipsocket__near_80480210(void* arg0)
{
    void* iface;
    void* lcp;

    iface = (arg0 != NULL) ? arg0 : lbl_805BDD20;
    lcp = FPTR(iface, 0x58);
    if (lcp != NULL && FU16(lbl_80534558, 2) != 0xFFFFU && FU8(lbl_80534558, 0) == 0) {
        kar_ipsocket__near_8047f648(lcp);
        while (FS32(lcp, 4) == 4) {
        }
        kar_ipsocket__near_8047f578(lcp);
        FU16(lbl_80534558, 0x61C) = 0;
        FU8(lbl_80534558, 0) = 0xA7;
        kar_ipsocket__near_8047fcfc(iface, lbl_80534558);
    }
    if (FPTR(iface, 0x60) == (void*)kar_ipsocket__near_8047feb4) {
        FPTR(iface, 0x60) = FPTR(lbl_80534558, 0x624);
    }
}

s32 kar_ipsocket__near_804802e0(void* arg0, void* arg1)
{
    s32 err;
    u16 gotHost, gotAc;
    u16 offset;
    u8* tag;

    tag = (u8*)arg1 + 6;
    err = 0;
    gotAc = 0;
    gotHost = 0;
    offset = FU16(arg0, 0x61A);
    while (tag < (u8*)arg1 + FU16(arg1, 4)) {
        u16 type = FU16(tag, 0);
        if (type == 0) {
            break;
        }
        switch (type) {
        case 0x102:
            if (!gotHost && FU8(arg0, 0) == 9) {
                gotHost = 1;
                memmove((char*)arg0 + offset + 0x44, tag, FU16(tag, 2) + 4);
                offset = FU16(tag, 2) + offset + 4;
            }
            break;
        case 0x104:
            if (!gotAc && FU8(arg0, 0) == 9) {
                gotAc = 1;
                memmove((char*)arg0 + offset + 0x44, tag, FU16(tag, 2) + 4);
                offset = FU16(tag, 2) + offset + 4;
            }
            break;
        case 0x201:
            err = -0x68;
            break;
        case 0x202:
            err = -0x69;
            break;
        case 0x203:
            err = -0x6A;
            break;
        }
        tag = tag + FU16(tag, 2) + 4;
    }
    if (err == 0) {
        FU16(arg0, 0x61A) = offset;
    }
    return err;
}

void kar_ipsocket__near_80480454(void* arg0, void* arg1, s32 arg2, s32 arg3)
{
    void* tag0;

    tag0 = (char*)arg1 + 0xE;
    if (arg2 < 0x14) {
        return;
    }
    if (arg2 < FU16(tag0, 4) + 0x14) {
        return;
    }
    if (FU8(arg1, 0xE) != 0x11) {
        return;
    }
    switch (FU16(arg1, 0xC)) {
    case 0x8863:
        switch (FU8(tag0, 1)) {
        case 7:
            if (FU8(lbl_80534558, 0) == 9 && FU16(tag0, 2) == 0) {
                s32 err = kar_ipsocket__near_804802e0(lbl_80534558, tag0);
                if (err == 0) {
                    FU8(lbl_80534558, 0) = 0x19;
                    memmove(lbl_80534558 + 0x38, (char*)arg1 + 6, 6U);
                    kar_ipsocket__near_8047fcfc(arg0, lbl_80534558);
                    return;
                }
                fn_8046F190(FPTR(lbl_80534558, 0x620), err);
                OSCancelAlarm((OSAlarm*)(lbl_80534558 + 0x10));
                FU8(lbl_80534558, 0) = 0;
                FU16(lbl_80534558, 2) = 0xFFFF;
                FU16(lbl_80534558, 4) = 0xFFFF;
                FS32(FPTR(lbl_80534558, 0x620), 0x40) = 0x5DC;
                return;
            }
            break;
        case 0x65:
            if (FU8(lbl_80534558, 0) == 0x19 && memcmp(lbl_80534558 + 0x38, (char*)arg1 + 6, 6) == 0) {
                if (kar_ipsocket__near_804802e0(lbl_80534558, tag0) == 0 && FU16(tag0, 2) != 0xFFFFU) {
                    FU8(lbl_80534558, 0) = 0;
                    FU16(lbl_80534558, 2) = FU16(tag0, 2);
                    OSCancelAlarm((OSAlarm*)(lbl_80534558 + 0x10));
                    kar_ipsocket__near_8047f3dc(FPTR(arg0, 0x58));
                    kar_ipsocket__near_8047f4c8(FPTR(arg0, 0x58));
                    return;
                }
                fn_8046F190(FPTR(lbl_80534558, 0x620), 0);
                OSCancelAlarm((OSAlarm*)(lbl_80534558 + 0x10));
                FU8(lbl_80534558, 0) = 0;
                FU16(lbl_80534558, 2) = 0xFFFF;
                FU16(lbl_80534558, 4) = 0xFFFF;
                FS32(FPTR(lbl_80534558, 0x620), 0x40) = 0x5DC;
                return;
            }
            break;
        case 0xA7: {
            u16 sess = FU16(tag0, 2);
            if (sess != 0xFFFFU) {
                if (sess == FU16(lbl_80534558, 2) && memcmp(lbl_80534558 + 0x38, (char*)arg1 + 6, 6) == 0) {
                    if (FU8(lbl_80534558, 0) == 0xA7) {
                        OSCancelAlarm((OSAlarm*)(lbl_80534558 + 0x10));
                        FU8(lbl_80534558, 0) = 0;
                        FU16(lbl_80534558, 2) = 0xFFFF;
                        FU16(lbl_80534558, 4) = 0xFFFF;
                        FS32(FPTR(lbl_80534558, 0x620), 0x40) = 0x5DC;
                        return;
                    }
                    if (FU8(lbl_80534558, 0) == 0) {
                        u16 saved;
                        kar_ipsocket__near_8047f578(FPTR(arg0, 0x58));
                        kar_ipsocket__near_80480210(arg0);
                        fn_8046F190(FPTR(lbl_80534558, 0x620), -0x6E);
                        saved = FU16(lbl_80534558, 2);
                        OSCancelAlarm((OSAlarm*)(lbl_80534558 + 0x10));
                        FU8(lbl_80534558, 0) = 0;
                        FU16(lbl_80534558, 2) = 0xFFFF;
                        FU16(lbl_80534558, 4) = saved;
                        if (saved != 0xFFFFU) {
                            memmove(lbl_80534558 + 6, lbl_80534558 + 0x38, 6U);
                        }
                        FS32(FPTR(lbl_80534558, 0x620), 0x40) = 0x5DC;
                        return;
                    }
                }
                if (sess == FU16(lbl_80534558, 4) && memcmp(lbl_80534558 + 6, (char*)arg1 + 6, 6) == 0) {
                    kar_ipsocket__near_8047fc24(arg0, (u8*)arg1 + 6, sess);
                    return;
                }
            }
            break;
        }
        }
        break;
    case 0x8864:
        if (FU16(tag0, 2) != 0xFFFFU && FU8(lbl_80534558, 0) == 0 && FU8(tag0, 1) == 0 &&
            memcmp(lbl_80534558 + 0x38, (char*)arg1 + 6, 6) == 0 &&
            FU16(tag0, 2) == FU16(lbl_80534558, 2)) {
            kar_ipsocket__near_8047f2d8(arg0, (char*)tag0 + 6, FU16(tag0, 4));
        }
        break;
    }
}

s32 kar_ipsocket__near_804807ac(void* arg0, void* arg1, u8 arg2)
{
    s32 nak;
    s32 rej;
    u16 mru;
    u16 auth;
    u8 authId;
    u8* opt;
    u8* end;
    u16 len;

    authId = arg2;
    nak = 0;
    rej = 0;
    opt = (u8*)arg1 + 4;
    mru = FU16(arg0, 0x288);
    auth = 0;
    len = FU16(arg1, 2) - 4;
    end = opt + len;

    while (opt < end) {
        u8 type = opt[0];
        switch (type) {
        case 1:
            if (opt[1] != 4) {
                return -3;
            }
            mru = FU16(opt, 2);
            if (mru < 0x80U) {
                nak = 1;
            }
            break;
        case 3: {
            u8 l = opt[1];
            u16 proto;
            if (l < 4U) {
                return -3;
            }
            proto = FU16(opt, 2);
            auth = proto;
            switch (proto) {
            case 0xC023:
                if (l != 4) {
                    return -3;
                }
                break;
            case 0xC223:
                if (l != 5) {
                    return -3;
                }
                authId = opt[4];
                if (authId != 5) {
                    nak = 1;
                }
                break;
            default:
                nak = 1;
                break;
            }
            break;
        }
        default:
            rej = 1;
            break;
        }
        opt += opt[1];
    }

    if (rej) {
        u8* p = (u8*)arg1 + 4;
        while (p < end) {
            u8 type = p[0];
            if (type == 3) {
                len = kar_ipsocket__near_8047fad4((char*)arg1 + 4, len, p);
            } else {
                p += p[1];
                continue;
            }
            p += p[1];
        }
        FU16(arg1, 2) = len + 4;
        return -1;
    }
    if (nak && FS32(arg0, 0x18) <= 0) {
        u8* p = (u8*)arg1 + 4;
        while (p < end) {
            u8 type = p[0];
            if (type == 1) {
                if (mru >= 0x80U) {
                    len = kar_ipsocket__near_8047fad4((char*)arg1 + 4, len, p);
                } else {
                    p += p[1];
                    continue;
                }
            } else if (type == 3) {
                if (auth == 0xC023) {
                    len = kar_ipsocket__near_8047fad4((char*)arg1 + 4, len, p);
                } else if (auth == 0xC223 && authId == 5) {
                    len = kar_ipsocket__near_8047fad4((char*)arg1 + 4, len, p);
                } else {
                    p += p[1];
                    continue;
                }
            } else {
                p += p[1];
                continue;
            }
            p += p[1];
        }
        FU16(arg1, 2) = len + 4;
        return -1;
    }
    if (nak) {
        u8* p = (u8*)arg1 + 4;
        while (p < end) {
            u8 type = p[0];
            if (type == 1) {
                if (mru < 0x80U) {
                    FU16(p, 2) = 0x80;
                    p += p[1];
                    continue;
                }
                len = kar_ipsocket__near_8047fad4((char*)arg1 + 4, len, p);
            } else if (type == 3) {
                if (auth == 0xC223 && authId != 5) {
                    p[4] = 5;
                    p += p[1];
                    continue;
                }
                len = kar_ipsocket__near_8047fb24((char*)arg1 + 4, kar_ipsocket__near_8047fad4((char*)arg1 + 4, len, p), p, (u8*)&lbl_805E62B8);
                p += p[1];
                continue;
            } else {
                p += p[1];
                continue;
            }
            p += p[1];
        }
        FU16(arg1, 2) = len + 4;
        return -2;
    }
    FU16(arg0, 0x288) = mru;
    FU16(arg0, 0x28A) = auth;
    return 0;
}

s32 kar_ipsocket__near_80480b50(void* arg0, void* arg1)
{
    if (FU16(arg1, 2) != FS32(arg0, 0x230) + 4 || memcmp((char*)arg1 + 4, (char*)arg0 + 0x21C, FS32(arg0, 0x230)) != 0) {
        return 0;
    }
    return 1;
}

s32 fn_80480BA4(void* arg1)
{
    u8* p = (u8*)arg1 + 4;
    u8* end = p + (u16)(FU16(arg1, 2) - 4);
    while (p < end) {
        p += p[1];
    }
    return 1;
}

s32 kar_ipsocket__near_80480bd4(void* arg0, void* arg1)
{
    u8* p;
    u8* end;
    u8* own;

    p = (u8*)arg1 + 4;
    end = p + (u16)(FU16(arg1, 2) - 4);
    own = (u8*)arg0 + 0x21C;
    while (p < end) {
        for (;;) {
            if (p[0] == own[0]) {
                FS32(arg0, 0x230) = kar_ipsocket__near_8047fad4((char*)arg0 + 0x21C, FS32(arg0, 0x230), own);
                p += p[1];
                break;
            }
            if ((u8*)arg0 + FS32(arg0, 0x230) + 0x21C <= own) {
                return 0;
            }
            own += own[1];
        }
    }
    return 1;
}

s32 kar_ipsocket__near_80480c90(void* arg0)
{
    void* iface;
    u16 mru;
    u16 auth;

    iface = FPTR(arg0, 0x260);
    mru = FU16(arg0, 0x288);
    if ((s32)mru < FS32(iface, 0x40)) {
        FS32(iface, 0x40) = mru;
    }
    auth = FU16(arg0, 0x28A);
    switch (auth) {
    case 0xC023:
        kar_ipsocket__near_8048172c(FPTR(arg0, 0x260));
        break;
    case 0xC223:
        kar_ipsocket__near_804819f0(FPTR(arg0, 0x260));
        break;
    default:
        kar_ipsocket__near_8047f4c8(FPTR(arg0, 0x284));
        break;
    }
    return 1;
}

s32 kar_ipsocket__near_80480d10(void* arg0)
{
    kar_ipsocket__near_8047f578(FPTR(arg0, 0x284));
    return 1;
}

s32 kar_ipsocket__near_80480d38(void* arg0)
{
    kar_ipsocket__near_8047f3dc(FPTR(arg0, 0x284));
    return 1;
}

s32 kar_ipsocket__near_80480d60(void* arg0)
{
    kar_ipsocket__near_8047f648(FPTR(arg0, 0x284));
    return 1;
}

s32 kar_ipsocket__near_80480d88(void* arg0, void* arg1, const char* arg2, const char* arg3)
{
    memset(arg0, 0, 0x298);
    FU16(arg0, 0) = 0xC021;
    OSCreateAlarm((OSAlarm*)((char*)arg0 + 0x238));
    FPTR(arg0, 0x260) = arg1;
    FPTR(arg0, 0x264) = (void*)kar_ipsocket__near_804807ac;
    FPTR(arg0, 0x268) = (void*)kar_ipsocket__near_80480b50;
    FPTR(arg0, 0x26C) = (void*)fn_80480BA4;
    FPTR(arg0, 0x270) = (void*)kar_ipsocket__near_80480bd4;
    FPTR(arg0, 0x274) = (void*)kar_ipsocket__near_80480c90;
    FPTR(arg0, 0x278) = (void*)kar_ipsocket__near_80480d10;
    FPTR(arg0, 0x27C) = (void*)kar_ipsocket__near_80480d38;
    FPTR(arg0, 0x280) = (void*)kar_ipsocket__near_80480d60;
    FU16(arg0, 0x288) = 0x5DC;
    if (arg2 != NULL) {
        if (strlen(arg2) > 0xFFU) {
            fn_8046F190(NULL, -0x6C);
            return 0;
        }
        strncpy((char*)arg0 + 0x1C, arg2, 0x100);
    }
    if (arg3 != NULL) {
        if (strlen(arg3) > 0xFFU) {
            fn_8046F190(NULL, -0x6C);
            return 0;
        }
        strncpy((char*)arg0 + 0x11C, arg3, 0x100);
    }
    return 1;
}

s32 kar_ipsocket__near_80480edc(void* arg0, void* arg1)
{
    s32 nak;
    u16 addr;
    u8* opt;
    u8* end;
    u16 len;

    nak = 0;
    opt = (u8*)arg1 + 4;
    addr = 0;
    len = FU16(arg1, 2) - 4;
    end = opt + len;

    while (opt < end) {
        if (opt[0] != 3) {
            nak = 1;
            break;
        }
        if (opt[1] != 6) {
            return -3;
        }
        addr = FU16(opt, 2);
        if (addr == 0U) {
            nak = 1;
            break;
        }
        opt += opt[1];
    }
    if (nak) {
        u8* p = opt;
        while (p < end) {
            if (p[0] != 3) {
                p += p[1];
                continue;
            }
            if (addr != 0U) {
                len = kar_ipsocket__near_8047fad4((char*)arg1 + 4, len, p);
            } else {
                p += p[1];
                continue;
            }
            p += p[1];
        }
        FU16(arg1, 2) = len + 4;
        return -1;
    }
    FS32(arg0, 0x290) = addr;
    return 0;
}

s32 kar_ipsocket__near_80481008(void* arg0, void* arg1)
{
    if (FU16(arg1, 2) != FS32(arg0, 0x230) + 4 || memcmp((char*)arg1 + 4, (char*)arg0 + 0x21C, FS32(arg0, 0x230)) != 0) {
        return 0;
    }
    return 1;
}

s32 kar_ipsocket__near_8048105c(void* arg0, void* arg1)
{
    u8* p;
    u8* end;
    u8* own;
    u8 optCode;

    p = (u8*)arg1 + 4;
    end = p + (u16)(FU16(arg1, 2) - 4);
    while (p < end) {
        optCode = p[0];
        if (optCode == 0x81 || optCode == 3 || optCode == 0x83) {
            if (p[1] != 6) {
                return 0;
            }
            own = (u8*)arg0 + 0x21C;
            {
                u8* q = own;
                u8* qend = (u8*)arg0 + FS32(arg0, 0x230) + 0x21C;
                while (q < qend) {
                    if (optCode == q[0]) {
                        if (optCode == 0x81 || optCode == 3 || optCode == 0x83) {
                            FS32(q, 2) = FS32(p, 2);
                        }
                        break;
                    }
                    q += q[1];
                }
                if (qend <= q) {
                    memmove(p, p + p[1], 0);
                    FU16(arg0, 0x230) = FU16(arg0, 0x230) + p[1];
                }
            }
        }
        p += p[1];
    }
    return 1;
}

s32 kar_ipsocket__near_80481184(void* arg0, void* arg1)
{
    u8* p;
    u8* end;
    u8* own;

    p = (u8*)arg1 + 4;
    end = p + (u16)(FU16(arg1, 2) - 4);
    own = (u8*)arg0 + 0x21C;
    while (p < end) {
        for (;;) {
            if (p[0] == own[0]) {
                FS32(arg0, 0x230) = kar_ipsocket__near_8047fad4((char*)arg0 + 0x21C, FS32(arg0, 0x230), own);
                p += p[1];
                break;
            }
            if ((u8*)arg0 + FS32(arg0, 0x230) + 0x21C <= own) {
                return 0;
            }
            own += own[1];
        }
    }
    return 1;
}

s32 kar_ipsocket__near_80481240(void* arg0)
{
    u8* opt;
    u8* end;
    u8* mtuOpt = NULL;
    u8* addrOpt = NULL;
    u8* peerOpt = NULL;
    u32 rd1, rd2;
    void* srcOpt;

    opt = (u8*)arg0 + 0x21C;
    end = (u8*)arg0 + FS32(arg0, 0x230) + 0x21C;
    while (opt < end) {
        switch (opt[0]) {
        case 3:
            addrOpt = opt + 2;
            break;
        case 0x81:
            mtuOpt = opt + 2;
            break;
        case 0x83:
            peerOpt = opt + 2;
            break;
        }
        opt += opt[1];
    }
    srcOpt = (FU32(arg0, 0x290) != 0U) ? (char*)arg0 + 0x290 : (void*)&lbl_805E62A0;
    fn_8046E828(addrOpt, (void*)&lbl_805E62A0, srcOpt);
    if (kar_ipsocket__near_8047ad40(&rd1, &rd2) == 0) {
        if (rd1 == lbl_805E6298 && rd2 == lbl_805E6298) {
            kar_ipsocket__near_8047ac54((u32*)mtuOpt, (u32*)peerOpt);
        } else {
            kar_ipsocket__near_8047ac54(&rd1, &rd2);
        }
    }
    return 1;
}

s32 kar_ipsocket__near_8048134c(void)
{
    fn_8046E828(NULL, NULL, NULL);
    return 1;
}

s32 fn_8048137C(void)
{
    return 1;
}

s32 fn_80481384(void)
{
    return 1;
}

void kar_ipsocket__near_8048138c(void* arg0, void* arg1)
{
    void* opt;

    memset(arg0, 0, 0x298);
    FU16(arg0, 0) = 0x8021;
    OSCreateAlarm((OSAlarm*)((char*)arg0 + 0x238));
    FPTR(arg0, 0x260) = arg1;
    FPTR(arg0, 0x264) = (void*)kar_ipsocket__near_80480edc;
    FPTR(arg0, 0x268) = (void*)kar_ipsocket__near_80481008;
    FPTR(arg0, 0x26C) = (void*)kar_ipsocket__near_8048105c;
    FPTR(arg0, 0x270) = (void*)kar_ipsocket__near_80481184;
    FPTR(arg0, 0x274) = (void*)kar_ipsocket__near_80481240;
    FPTR(arg0, 0x278) = (void*)kar_ipsocket__near_8048134c;
    FPTR(arg0, 0x27C) = (void*)fn_8048137C;
    FPTR(arg0, 0x280) = (void*)fn_80481384;

    opt = (char*)arg0 + FS32(arg0, 0x230) + 0x21C;
    FU8(opt, 0) = 3;
    FU8(opt, 1) = 6;
    FS32(opt, 2) = 0;
    FS32(arg0, 0x230) += 6;
    opt = (char*)arg0 + FS32(arg0, 0x230) + 0x21C;
    FU8(opt, 0) = 0x81;
    FU8(opt, 1) = 6;
    FS32(opt, 2) = 0;
    FS32(arg0, 0x230) += 6;
    opt = (char*)arg0 + FS32(arg0, 0x230) + 0x21C;
    FU8(opt, 0) = 0x83;
    FU8(opt, 1) = 6;
    FS32(opt, 2) = 0;
    FS32(arg0, 0x230) += 6;
}

void kar_ipsocket__near_804814c4(void* arg0)
{
    void* pap;
    s32 retries;

    pap = (char*)arg0 - 8;
    retries = FS32(arg0, 0x28) + 1;
    FS32(pap, 0x30) = retries;
    if (retries < 5) {
        kar_ipsocket__near_80481510(FPTR(pap, 0x34), NULL);
        return;
    }
    kar_ipsocket__near_8047f648(FPTR(FPTR(pap, 0x34), 0x58));
}

void kar_ipsocket__near_80481510(void* arg0, u8* arg1)
{
    void* lcp;
    s32 level;
    u8 peerLen;
    u8 passLen;
    s32 dataLen;
    void* pkt;
    u8* p;

    lcp = FPTR(arg0, 0x58);
    level = OSDisableInterrupts();
    peerLen = strlen((char*)lcp + 0x1C);
    passLen = strlen((char*)lcp + 0x11C);
    dataLen = peerLen + passLen + 2;
    OSCancelAlarm((OSAlarm*)((char*)arg1 + 8));
    OSSetAlarm((OSAlarm*)((char*)arg1 + 8), (OSTime)(3 << FS32(arg1, 0x30)), NULL);
    pkt = ((void* (*)(void*, s32))FPTR(arg0, 0x68))(arg0, dataLen + 0x42);
    if (pkt != NULL) {
        FU16(pkt, 0x3C) = 0xC023;
        FU8(pkt, 0x3E) = 1;
        p = (u8*)pkt + 0x43;
        FU8(pkt, 0x3F) = FU8(arg1, 0);
        FS16(pkt, 0x40) = (s16)(dataLen + 4);
        FU8(pkt, 0x42) = peerLen;
        memmove(p, (char*)lcp + 0x1C, peerLen);
        p += peerLen;
        *p = passLen;
        memmove(p + 1, (char*)lcp + 0x11C, passLen);
        FS32(pkt, 0x30) = 1;
        dataLen += 6;
        FPTR(pkt, 0x34) = (char*)pkt + 0x3C;
        FS32(pkt, 0x38) = dataLen;
        FS32(pkt, 0x28) = 0;
        FS32(pkt, 0x2C) = 0;
        FU16(pkt, 0x10) = 0x8864;
        FU8(pkt, 0x25) = 0;
        FS32(pkt, 4) = 0;
        ((void (*)(void*, void*, s32))FPTR(arg0, 0x60))(arg0, pkt, dataLen);
    }
    OSRestoreInterrupts(level);
}

void kar_ipsocket__near_80481678(void* arg0, void* arg1, s32 arg2)
{
    u16 len;
    u8 code;

    if (arg2 < 4) {
        return;
    }
    len = FU16(arg1, 2);
    if (arg2 < (s32)len) {
        return;
    }
    if (len < 4U) {
        return;
    }
    if (FU8(arg1, 1) == lbl_805C2978[0]) {
        code = FU8(arg1, 0);
        switch (code) {
        case 2:
            OSCancelAlarm((OSAlarm*)&lbl_805C2978[8]);
            kar_ipsocket__near_8047f4c8(FPTR(arg0, 0x5C));
            return;
        case 3:
            fn_8046F190(NULL, -0x6C);
            OSCancelAlarm((OSAlarm*)&lbl_805C2978[8]);
            kar_ipsocket__near_8047f648(FPTR(arg0, 0x58));
            break;
        }
    }
}

void kar_ipsocket__near_8048172c(void* arg0)
{
    FPTR(lbl_805C2978, 0x34) = arg0;
    OSCancelAlarm((OSAlarm*)&lbl_805C2978[8]);
    lbl_805C2978[0] = lbl_805C2978[0] + 1;
    FS32(lbl_805C2978, 0x30) = 0;
    kar_ipsocket__near_80481510(arg0, lbl_805C2978);
}

void kar_ipsocket__near_80481790(void* arg0, void* arg1)
{
    s32 level;
    void* pkt;

    level = OSDisableInterrupts();
    pkt = ((void* (*)(void*, s32))FPTR(arg0, 0x68))(arg0, FU16(arg1, 2) + 0x3E);
    if (pkt != NULL) {
        s32 len;
        FU16(pkt, 0x3C) = 0xC223;
        memmove((char*)pkt + 0x3E, arg1, FU16(arg1, 2));
        FS32(pkt, 0x30) = 1;
        FPTR(pkt, 0x34) = (char*)pkt + 0x3C;
        len = FU16(arg1, 2) + 2;
        FS32(pkt, 0x38) = len;
        FS32(pkt, 0x28) = 0;
        FS32(pkt, 0x2C) = 0;
        FU16(pkt, 0x10) = 0x8864;
        FU8(pkt, 0x25) = 0;
        FS32(pkt, 4) = 0;
        ((void (*)(void*, void*, s32, s32))FPTR(arg0, 0x60))(arg0, pkt, 0, len);
    }
    OSRestoreInterrupts(level);
}

void kar_ipsocket__near_80481854(void* arg0, void* arg1, s32 arg2)
{
    void* lcp;
    u16 len;
    u8 code;

    lcp = FPTR(arg0, 0x58);
    if (arg2 < 4) {
        return;
    }
    len = FU16(arg1, 2);
    if (arg2 < (s32)len) {
        return;
    }
    if (len < 4U) {
        return;
    }
    code = FU8(arg1, 0);
    switch (code) {
    case 1: {
        u8 valLen;
        FU8(lbl_805C29B0, 4) = FU8(arg1, 1);
        FU8(lbl_805C29B0, 0) = 1;
        valLen = FU8(arg1, 4);
        if (FU16(arg1, 2) >= (u32)(valLen + 5)) {
            u8 nameLen = strlen((char*)lcp + 0x1C);
            u8 secretLen = strlen((char*)lcp + 0x11C);
            void* md5;
            u8* out;
            FU16(arg1, 0) = 2;
            FU16(arg1, 2) = nameLen + 0x15;
            FU16(arg1, 4) = 0x10;
            md5 = &lbl_805C29B0[8];
            fn_80469628(md5);
            fn_80469668(md5, (char*)arg1 + 1, 1U);
            fn_80469668(md5, (char*)lcp + 0x11C, secretLen);
            out = (u8*)arg1 + 5;
            fn_80469668(md5, out, valLen);
            fn_80469758(out, md5);
            memmove((char*)arg1 + 0x15, (char*)lcp + 0x1C, nameLen);
            kar_ipsocket__near_80481790(arg0, arg1);
            return;
        }
        break;
    }
    case 3:
        if (lbl_805C29B0[0] != 0 && lbl_805C29B0[4] == FU8(arg1, 1)) {
            kar_ipsocket__near_8047f4c8(FPTR(arg0, 0x5C));
            return;
        }
        break;
    case 4:
        if (lbl_805C29B0[0] != 0 && lbl_805C29B0[4] == FU8(arg1, 1)) {
            fn_8046F190(arg0, -0x6C);
            kar_ipsocket__near_8047f648(FPTR(arg0, 0x58));
        }
        break;
    }
}

void kar_ipsocket__near_804819f0(void* arg0)
{
    FPTR(lbl_805C29B0, 0x60) = arg0;
    FU32(lbl_805C29B0, 0) = 0;
}

s32 kar_ipsocket__near_80481a08(u16* arg0)
{
    u16* w = arg0;
    s32 sum = 0;
    s32 nleft = 16;

    while (nleft > 1) {
        sum += *w++;
        nleft -= 2;
    }
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += sum >> 16;
    return (u16)(sum ^ 0xFFFF);
}




