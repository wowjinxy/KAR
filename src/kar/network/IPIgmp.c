#include "functions.h"
#include <dolphin/types.h>
#include <dolphin/ostime.h>

typedef s64 OSTime;

#define FU8(p, o) (*(u8 *) ((char *) (p) + (o)))
#define FS8(p, o) (*(s8 *) ((char *) (p) + (o)))
#define FU16(p, o) (*(u16 *) ((char *) (p) + (o)))
#define FS16(p, o) (*(s16 *) ((char *) (p) + (o)))
#define FU32(p, o) (*(u32 *) ((char *) (p) + (o)))
#define FS32(p, o) (*(s32 *) ((char *) (p) + (o)))

extern void OSPanic(const char *file, s32 line, const char *msg, ...);

extern void *memcpy(void *dst, const void *src, u32 n);
extern void *memmove(void *dst, const void *src, u32 n);
extern void *memset(void *dst, s32 val, u32 n);
extern s32 sprintf(void *dst, const char *fmt, ...);
extern s32 strcmp(const char *a, const char *b);
extern s32 strncmp(const char *a, const char *b, u32 n);
extern char *strcpy(void *dst, const void *src);
extern char *strcat(void *dst, const void *src);
extern char *strchr(const void *s, s32 c);
extern u32 strlen(const void *s);

#define OS_BUS_CLOCK (*(u32 *) 0x800000F8)

typedef struct OSContext OSContext;
typedef struct OSAlarm OSAlarm;
typedef void (*OSAlarmHandler)(OSAlarm *alarm, OSContext *context);
struct OSAlarm {
    OSAlarmHandler handler;
    u32 tag;
    OSTime fire;
    OSAlarm *prev;
    OSAlarm *next;
    OSTime period;
    OSTime start;
};

extern void OSCreateAlarm(OSAlarm *alarm);
extern void OSSetAlarm(OSAlarm *alarm, OSTime tick, OSAlarmHandler handler);
extern void OSCancelAlarm(OSAlarm *alarm);

typedef struct IPHeader {
    u8 verlen;
    u8 tos;
    u16 len;
    u16 id;
    u16 frag;
    u8 ttl;
    u8 proto;
    u16 sum;
    u8 src[4];
    u8 dst[4];
} IPHeader;

typedef struct IGMP {
    u8 vertype;
    u8 unused;
    u16 sum;
    u8 addr[4];
} IGMP;

typedef struct IPIface {
    s32 type;        /* 0x00 */
    u8 pad04[0x40];  /* 0x04 */
    u8 addr[4];      /* 0x44 */
    u8 pad48[0x0C];  /* 0x48 */
    u8 alias[4];     /* 0x54 */
    u8 pad58[0x10];  /* 0x58 */
    void *(*alloc)(void *iface, s32 size); /* 0x68 */
    s32 (*free)(void *iface, void *ptr, s32 size); /* 0x6C */
} IPIface;

typedef struct IGMPGroup {
    u8 groupAddr[4]; /* 0x00 */
    u8 ifAddr[4];    /* 0x04 */
    OSAlarm alarm;   /* 0x08 */
    s16 refCount;    /* 0x30 */
    u8 pad32[6];     /* 0x32 */
} IGMPGroup; /* size 0x38 */

#define IGMP_MAX_GROUPS 4

static IGMPGroup lbl_805C2A18[IGMP_MAX_GROUPS];

extern u32 lbl_805E6298;
extern IPIface lbl_805BDD20;

static const u32 lbl_805E62C0 = 0xE0000001U;
static const char lbl_805E62C8[8] = "http://";

static s32 lbl_805DE6D0;
static u8 lbl_805C2AF8[0x40];
static u32 lbl_805C3C40[0x2122];

extern s32 fn_8046B564(void *packet, s32 len); /* IPOut */
extern void fn_80468838(u8 *macAddr6, u32 *iface);

typedef struct IFDatagram {
    void *interface;   /* 0x00 */
    void *queue;        /* 0x04 */
    void *linkNext;      /* 0x08 */
    void *linkPrev;      /* 0x0C */
    u8 hwAddr[6];        /* 0x10 */
    u16 type;            /* 0x16 */
    u16 offset;          /* 0x18 */
    u8 dst[4];           /* 0x1A */
    u8 prefix[8];        /* 0x1E */
    u8 prefixLen;        /* 0x26 */
    u8 flag;             /* 0x27 */
    void (*callback)(void *, s32); /* 0x28 */
    void *param;         /* 0x2C */
    s32 nVec;            /* 0x30 */
    void *vecData;       /* 0x34 */
    s32 vecLen;          /* 0x38 */
} IFDatagram; /* size 0x3C */

void kar_ipigmp__80481ab4(u32 type, IGMPGroup *arg1) {
    IGMPGroup *group;
    IGMPGroup *p;
    s32 i;
    IFDatagram *packet;
    IPHeader *hdr;
    IGMP *igmp;
    s32 totalLen;

    if (*(u32 *) arg1 == lbl_805E6298) {
        group = NULL;
    } else {
        group = NULL;
        p = lbl_805C2A18;
        for (i = 0; i < IGMP_MAX_GROUPS; i++, p++) {
            if (*(u32 *) arg1 == FU32(p, 0)) {
                group = p;
                break;
            }
        }
    }

    if (group != NULL) {
        packet = (IFDatagram *) lbl_805BDD20.alloc(&lbl_805BDD20, 0x58);
        if (packet != NULL) {
            packet->callback = NULL;
            packet->queue = NULL;
            hdr = (IPHeader *) ((char *) packet + 0x3C);
            packet->interface = NULL;
            hdr->verlen = 0x45;
            hdr->tos = 0;
            igmp = (IGMP *) ((char *) hdr + 0x14);
            hdr->len = (u16) (((hdr->verlen * 4) & 0x3C) + 8);
            hdr->ttl = 1;
            hdr->proto = 2;
            hdr->frag = 0;
            igmp->vertype = (u8) ((type & 0xF) | 0x10);
            igmp->unused = 0;
            switch ((s32) type) {
            case 1:
                memmove(igmp->addr, &lbl_805E6298, 4);
                memmove(hdr->dst, &lbl_805E62C0, 4);
                break;
            case 2:
                memmove(igmp->addr, arg1, 4);
                memmove(hdr->dst, arg1, 4);
                break;
            default:
                OSPanic("IPIgmp.c", 0xA9, "IGMPOut() fatal error.");
                break;
            }
            if (FU32(group, 4) != lbl_805E6298) {
                memmove(hdr->src, &FU32(group, 4), 4);
            } else if (*(u32 *) lbl_805BDD20.addr == lbl_805E6298) {
                memmove(hdr->src, lbl_805BDD20.alias, 4);
            } else {
                memmove(hdr->src, lbl_805BDD20.addr, 4);
            }
            packet->nVec = 1;
            packet->vecData = hdr;
            totalLen = ((hdr->verlen * 4) & 0x3C) + 8;
            packet->vecLen = totalLen;
            packet->param = NULL;
            packet->prefix[7] = 0;
            if (fn_8046B564(packet, totalLen) < 0) {
                lbl_805BDD20.free(&lbl_805BDD20, packet, 0x58);
            }
        }
    }
}

void kar_ipigmp__near_80481ce8(OSAlarm *alarm, OSContext *context) {
    kar_ipigmp__80481ab4(2U, (IGMPGroup *) ((char *) alarm - 8));
}

void kar_ipigmp__near_80481d10(IPIface *arg0, IPHeader *arg1) {
    s32 hlen;
    IGMP *igmp;
    u16 *p;
    u16 sum;
    u32 n;
    u32 groupAddr;
    IGMPGroup *group;
    IGMPGroup *entry;
    s32 i;
    u32 scale;
    s64 t;
    s64 delay;

    hlen = (arg1->verlen * 4) & 0x3C;
    igmp = (IGMP *) ((char *) arg1 + hlen);

    if (arg1->len < hlen + 8) {
        return;
    }
    if (arg1->ttl != 1) {
        return;
    }
    if (*(u32 *) arg1->src == *(u32 *) arg0->addr) {
        return;
    }
    if (*(u32 *) arg1->src == *(u32 *) arg0->alias) {
        return;
    }

    if ((igmp->vertype >> 4) != 1) {
        return;
    }

    p = (u16 *) igmp;
    n = 4;
    sum = 0;
    while (n != 0) {
        sum += *p;
        p++;
        n--;
    }
    sum = (sum & 0xFFFF) + (sum >> 16);
    sum = (sum & 0xFFFF) + (sum >> 16);
    if ((u16) (sum ^ 0xFFFF) != 0) {
        return;
    }

    groupAddr = *(u32 *) igmp->addr;
    if (groupAddr == lbl_805E6298) {
        return;
    }

    switch (igmp->vertype & 0xF) {
    case 1:
        if (groupAddr != lbl_805E6298) {
            return;
        }
        scale = (OS_BUS_CLOCK >> 2) / 500000;
        entry = lbl_805C2A18;
        for (i = 0; i < IGMP_MAX_GROUPS; i++, entry++) {
            if (FU32(entry, 0) != lbl_805E6298 && entry->alarm.handler == 0) {
                t = OSGetTime() + FU32(entry, 0);
                t = (t * scale) / 8;
                delay = t % (s64) ((OS_BUS_CLOCK >> 2) * 0xA);
                if (delay < 0) {
                    delay = -delay;
                }
                OSSetAlarm(&entry->alarm, delay, kar_ipigmp__near_80481ce8);
            }
        }
        return;
    case 2:
        group = NULL;
        entry = lbl_805C2A18;
        for (i = 0; i < IGMP_MAX_GROUPS; i++, entry++) {
            if (groupAddr == FU32(entry, 0)) {
                group = entry;
                break;
            }
        }
        if (group != NULL && *(u32 *) arg1->dst == FU32(group, 0)) {
            OSCancelAlarm(&group->alarm);
        }
        break;
    }
}

void kar_ipigmp__near_80481fe0(s32 *arg0) {
    u8 mac[6];
    const u8 *groupAddr;

    if (*arg0 < 0 || *arg0 >= 5) {
        return;
    }
    groupAddr = (const u8 *) &lbl_805E62C0;
    mac[0] = 1;
    mac[1] = 0;
    mac[2] = 0x5E;
    mac[3] = groupAddr[1] & 0x7F;
    mac[4] = groupAddr[2];
    mac[5] = groupAddr[3];
    fn_80468838(mac, (u32 *) groupAddr);
}

s32 kar_ipigmp__near_80482054(s32 arg0) {
    IGMPGroup *entry;
    s32 i;

    if (arg0 == 0) {
        entry = lbl_805C2A18;
        for (i = 0; i < IGMP_MAX_GROUPS; i++, entry++) {
            if (FU32(entry, 0) != lbl_805E6298) {
                OSCancelAlarm(&entry->alarm);
                memmove(entry, &lbl_805E6298, 4);
            }
        }
    }
    return 1;
}

u32 kar_ipigmp__near_804820d4(u8 *groupAddr, u32 *ifAddr) {
    u8 *entry;
    u8 *end;

    if ((*groupAddr & 0xF0) != 0xE0) {
        return -0xCU;
    }
    if (*(u32 *) groupAddr == lbl_805E62C0) {
        return 4U;
    }
    end = (u8 *) lbl_805C2A18 + 0xE0;
    for (entry = (u8 *) lbl_805C2A18; entry < end; entry += 0x38) {
        if (FU32(entry, 0) == *(u32 *) groupAddr && FU32(entry, 4) == *ifAddr) {
            return (u32) (entry - (u8 *) lbl_805C2A18) / 56;
        }
    }
    return -4U;
}

u32 kar_ipigmp__near_80482180(u8 *groupAddr, u32 *ifAddr) {
    IGMPGroup *entry;
    IGMPGroup *free_entry;
    s32 i;
    u32 addr;
    u8 mac[6];
    u64 t;
    s64 delay;
    u32 scale;

    if ((*groupAddr & 0xF0) != 0xE0) {
        return -0xCU;
    }
    addr = *(u32 *) groupAddr;
    if (addr == lbl_805E62C0) {
        return 4U;
    }

    free_entry = NULL;
    entry = lbl_805C2A18;
    for (i = 0; i < IGMP_MAX_GROUPS; i++, entry++) {
        if (FU32(entry, 0) == addr && FU32(entry, 4) == *ifAddr) {
            entry->refCount++;
            return i;
        }
        if (free_entry == NULL && FU32(entry, 0) == lbl_805E6298) {
            free_entry = entry;
        }
    }

    if (free_entry == NULL) {
        return -7U;
    }

    memmove(free_entry, groupAddr, 4);
    memmove(&FU32(free_entry, 4), ifAddr, 4);
    OSCreateAlarm(&free_entry->alarm);
    free_entry->refCount = 1;

    if (lbl_805BDD20.type < 5 && lbl_805BDD20.type >= 0) {
        mac[0] = 1;
        mac[1] = 0;
        mac[2] = 0x5E;
        mac[3] = groupAddr[1] & 0x7F;
        mac[4] = groupAddr[2];
        mac[5] = groupAddr[3];
        fn_80468838(mac, ifAddr);
    }

    kar_ipigmp__80481ab4(2U, free_entry);

    scale = (OS_BUS_CLOCK >> 2) / 500000;
    t = OSGetTime() + FU32(free_entry, 0);
    t = (t * scale) / 8;
    delay = (s64) t % (s64) ((OS_BUS_CLOCK >> 2) * 0xA);
    if (delay < 0) {
        delay = -delay;
    }
    OSSetAlarm(&free_entry->alarm, delay, kar_ipigmp__near_80481ce8);

    return (u32) (free_entry - lbl_805C2A18);
}

u32 kar_ipigmp__near_80482420(u8 *groupAddr, u32 *ifAddr) {
    IGMPGroup *entry;
    s32 i;
    u32 addr;

    if ((*groupAddr & 0xF0) != 0xE0) {
        return -0xCU;
    }
    addr = *(u32 *) groupAddr;
    if (addr == lbl_805E62C0) {
        return 4U;
    }
    entry = lbl_805C2A18;
    for (i = 0; i < IGMP_MAX_GROUPS; i++, entry++) {
        if (FU32(entry, 0) == addr && FU32(entry, 4) == *ifAddr) {
            entry->refCount--;
            if (entry->refCount <= 0) {
                OSCancelAlarm(&entry->alarm);
                memmove(entry, &lbl_805E6298, 4);
            }
            return i;
        }
    }
    return -4U;
}

s32 kar_ipigmp__near_80482524(void *arg0) {
    s32 i;
    u32 mask;
    IGMPGroup *entry;

    entry = lbl_805C2A18;
    for (i = 0; i < IGMP_MAX_GROUPS; i++, entry++) {
        mask = 1U << i;
        if (FU16(arg0, 6) & mask) {
            kar_ipigmp__near_80482420((u8 *) entry, &FU32(entry, 4));
            FU16(arg0, 6) &= ~mask;
        }
    }
    return 0;
}

extern const char lbl_805DD238[6];

#pragma dont_inline on
u8 *kar_ipigmp__near_80482598(void *arg0, u8 *arg1) {
    u8 *p;
    s32 i;

    p = arg1 + sprintf(arg1, "%8.8x-%4.4x-%4.4x-%2.2x%2.2x-", FU32(arg0, 0), FU16(arg0, 4), FU16(arg0, 6), FU8(arg0, 8), FU8(arg0, 9));
    for (i = 0; i < 6; i++) {
        p += sprintf(p, lbl_805DD238, FU8(arg0, 0xA + i));
    }
    return arg1;
}
#pragma dont_inline off

extern s32 fn_803B3894(s8 c);
extern s32 fn_803B3870(s8 c);
extern s32 fn_803B38AC(s8 c);
extern s32 fn_803B38C4(s8 c);

#pragma dont_inline on
s32 kar_ipigmp__near_8048263c(u8 *arg0, u8 *arg1) {
    s32 i;
    s32 j;
    u8 c;
    u8 nibble;
    u8 byte;
    s32 haveHigh;

    j = 0;
    byte = 0;
    haveHigh = 0;
    for (i = 0; i < 0x24; i++) {
        c = arg0[i];
        if (i == 8) {
            if (c != '-') {
                return -1;
            }
            continue;
        }
        if (fn_803B3894((s8) c) == 0) {
            return -1;
        }
        if (fn_803B38AC((s8) c) == 0) {
            nibble = (u8) fn_803B3870((s8) c);
        } else {
            nibble = (u8) (c - 0x57);
        }
        if (haveHigh) {
            byte = (byte << 4) | nibble;
            arg1[j] = byte;
            j += 1;
        } else {
            byte = nibble;
        }
        haveHigh = !haveHigh;
    }
    return 0;
}
#pragma dont_inline off

#pragma dont_inline on
s32 kar_ipigmp__near_80482730(void *arg0, void *arg1) {
    u32 a0, a1;
    u16 b0, b1;
    u8 c0, c1;
    s32 i;

    a0 = FU32(arg0, 0);
    a1 = FU32(arg1, 0);
    if (a0 != a1) {
        if (a0 < a1) {
            return -1;
        }
        return 1;
    }
    b0 = FU16(arg0, 4);
    b1 = FU16(arg1, 4);
    if (b0 != b1) {
        if (b0 < b1) {
            return -1;
        }
        return 1;
    }
    b0 = FU16(arg0, 6);
    b1 = FU16(arg1, 6);
    if (b0 != b1) {
        if (b0 < b1) {
            return -1;
        }
        return 1;
    }
    c0 = FU8(arg0, 8);
    c1 = FU8(arg1, 8);
    if (c0 != c1) {
        if (c0 < c1) {
            return -1;
        }
        return 1;
    }
    c0 = FU8(arg0, 9);
    c1 = FU8(arg1, 9);
    if (c0 != c1) {
        if (c0 < c1) {
            return -1;
        }
        return 1;
    }
    for (i = 0xA; i <= 0xF; i++) {
        c0 = FU8(arg0, i);
        c1 = FU8(arg1, i);
        if (c0 < c1) {
            return -1;
        }
        if (c0 > c1) {
            return 1;
        }
    }
    return 0;
}
#pragma dont_inline off

extern void fn_8046D7FC(s32 zero, u32 *out);
extern void fn_8046D86C(s32 zero, u32 *out); /* IPGetAddr */
extern void fn_8046D78C(s32 zero, u32 *out);

void kar_ipigmp__near_804828c4(u32 *arg0) {
    fn_8046D7FC(0, arg0);
    if (*arg0 == 0) {
        fn_8046D86C(0, arg0);
    }
}

void kar_ipigmp__near_80482910(u32 *arg0) {
    u32 tmp;

    fn_8046D7FC(0, &tmp);
    if (tmp == 0) {
        fn_8046D86C(0, &tmp);
        if (tmp != 0) {
            *arg0 = 0xFFFF0000;
            return;
        }
    }
    fn_8046D78C(0, arg0);
}

static s32 IsSpaceOrTab(u8 c) {
    s32 r;
    s8 sc;

    sc = (s8) c;
    r = 1;
    if (sc != 0x20) {
        if (sc != 9) {
            r = 0;
        }
    }
    return r;
}

u8 *fn_80482980(u8 *arg0, u8 **arg1) {
    u8 *p;

    p = arg0;
    while (IsSpaceOrTab(*p)) {
        p += 1;
    }
    if (p[0] == 0xD && p[1] == 0xA) {
        if (!IsSpaceOrTab(p[2])) {
            *arg1 = NULL;
            return p + 2;
        }
        p += 2;
        while (IsSpaceOrTab(*p)) {
            p += 1;
        }
        *arg1 = p;
        return p;
    }
    *arg1 = p;
    return p;
}

static const char lbl_80534C08_str[] = "-.!%*_+`'~";
#define lbl_80534C08 ((const u8 *) lbl_80534C08_str)

u8 *kar_ipigmp__near_80482a3c(u8 *arg0, u8 **arg1, s32 *arg2) {
    u8 *p;
    s8 c;

    p = arg0;
    *arg1 = NULL;
    *arg2 = 0;
    for (;;) {
        c = (s8) *p;
        if (c == 0) {
            break;
        }
        if (!(fn_803B38C4(c) != 0 || fn_803B38AC(c) != 0 || strchr((const char *) lbl_80534C08, c) != NULL)) {
            break;
        }
        if (*arg1 == NULL) {
            *arg1 = p;
        }
        p += 1;
        *arg2 += 1;
    }
    return p;
}

extern const char lbl_805DD240[];
extern const char lbl_805DD248[];

u8 *kar_ipigmp__near_80482b08(u8 *arg0) {
    u8 *p;

    p = arg0;
    for (;;) {
        if ((s8) p[0] == 0xD) {
            if ((s8) p[1] == 0xA) {
                if (IsSpaceOrTab(p[2])) {
                    p += 1;
                    continue;
                }
                return p + 2;
            }
        } else if ((s8) p[0] == 0) {
            return p;
        }
        p += 1;
    }
}

u8 *kar_ipigmp__near_80482b64(u8 *arg0, u8 **arg1, s32 *arg2) {
    u8 *p;
    u8 *tokStart;
    s32 tokLen;
    s8 c;
    s32 match;
    u8 *slash;
    u8 *hostStart;
    u8 *portStart;

    p = arg0;
    tokStart = NULL;
    tokLen = 0;
    *arg1 = NULL;
    *arg2 = 0;
    for (;;) {
        c = (s8) *p;
        if (c == 0) {
            break;
        }
        if (!(fn_803B38C4(c) != 0 || fn_803B38AC(c) != 0 || strchr((const char *) lbl_80534C08, c) != NULL)) {
            break;
        }
        if (tokStart == NULL) {
            tokStart = p;
        }
        tokLen += 1;
        p += 1;
    }
    if (tokStart == NULL) {
        return p;
    }
    if (tokLen == 4 && strncmp((const char *) tokStart, lbl_805DD240, 4) == 0) {
        match = 1;
    } else if (tokLen == 3 && strncmp((const char *) tokStart, lbl_805DD248, 3) == 0) {
        match = 1;
    } else {
        match = 0;
    }
    if (!match) {
        return NULL;
    }
    if (*p != '/') {
        return NULL;
    }
    slash = p + 1;
    hostStart = NULL;
    while (fn_803B38AC((s8) *slash) != 0) {
        if (hostStart == NULL) {
            hostStart = slash;
        }
        slash += 1;
    }
    if (hostStart == NULL) {
        return slash;
    }
    if (*slash != '.') {
        return slash;
    }
    portStart = slash + 1;
    hostStart = NULL;
    while (fn_803B38AC((s8) *portStart) != 0) {
        if (hostStart == NULL) {
            hostStart = portStart;
        }
        portStart += 1;
    }
    if (hostStart == NULL) {
        return portStart;
    }
    *arg1 = arg0;
    *arg2 = portStart - arg0;
    return portStart;
}

u8 *kar_ipigmp__near_80482d48(u8 *arg0, const char *arg1, u8 **arg2, s32 *arg3) {
    u8 *p;

    p = arg0;
    *arg2 = NULL;
    *arg3 = 0;
    while ((s8) *p != 0 && strchr(arg1, (s8) *p) == NULL) {
        p += 1;
    }
    *arg2 = arg0;
    *arg3 = p - arg0;
    return p;
}

u8 *kar_ipigmp__near_80482dc4(u8 *arg0, u8 *arg1) {
    u8 *line;
    u8 *tokStart;
    u8 *tokEnd;
    s32 tokLen;
    u8 *a;
    u8 *b;
    u32 idx;
    s32 cmp;
    u8 *end;
    u8 *p;

    line = arg0;
restart:
    tokStart = NULL;
    p = line;
    tokLen = 0;
    while (IsSpaceOrTab(*p) == 0 && (s8) *p != 0 &&
           (fn_803B38C4((s8) *p) != 0 || fn_803B38AC((s8) *p) != 0 || strchr((const char *) lbl_80534C08, (s8) *p) != NULL)) {
        if (tokStart == NULL) {
            tokStart = p;
        }
        tokLen += 1;
        p += 1;
    }
    if (tokLen > 0) {
        a = tokStart;
        b = arg1;
        idx = 0;
        cmp = 0;
        for (;;) {
            if (idx >= (u32) tokLen) {
                cmp = 0;
                break;
            }
            {
                u8 ca = *a++;
                u8 cb = *b++;
                s32 va = fn_803B3870((s8) ca);
                s32 vb = fn_803B3870((s8) cb);
                if (va < vb) {
                    cmp = -1;
                    break;
                } else if (va > vb) {
                    cmp = 1;
                    break;
                } else if (va == 0) {
                    cmp = 0;
                    break;
                }
            }
            idx += 1;
        }
        if (cmp == 0 && (s8) arg1[tokLen] == 0) {
            tokEnd = fn_80482980(p, &tokStart);
            if (tokEnd[0] == 0xD && tokEnd[1] == 0xA) {
                if (!IsSpaceOrTab(tokEnd[2])) {
                    end = NULL;
                } else {
                    tokEnd += 2;
                    while (IsSpaceOrTab(*tokEnd)) {
                        tokEnd += 1;
                    }
                    end = tokEnd;
                }
            } else if ((s8) tokEnd[0] == 0) {
                end = tokEnd;
            } else {
                while (!(tokEnd[0] == 0xD && tokEnd[1] == 0xA && IsSpaceOrTab(tokEnd[2]) != 0) && (s8) tokEnd[0] != 0) {
                    tokEnd += 1;
                }
                end = tokEnd;
            }
            if (end == NULL) {
                return &tokStart[tokLen];
            }
            return tokEnd;
        }
    }

    goto check_semi;
    for (;;) {
        if ((s8) *p == 0) {
            p = NULL;
            break;
        }
        if ((s8) *p == 0xD && p[1] == 0xA) {
            if (!IsSpaceOrTab(p[2])) {
                p = NULL;
                break;
            }
            p += 2;
        }
        p += 1;
check_semi:
        if ((s8) *p == 0x3B) {
            break;
        }
    }
    if (p == NULL) {
        return NULL;
    }
    p = fn_80482980(p, &tokStart);
    if (tokStart == NULL) {
        /* fall through */
    } else if ((s8) *tokStart != 0x3B) {
        tokStart = NULL;
    } else {
        p = fn_80482980(p + 1, &tokStart);
    }
    line = p;
    if (tokStart == NULL) {
        return NULL;
    }
    goto restart;
}

s32 kar_ipigmp__near_804830a4(u8 *arg0) {
    u8 *p;
    u8 *tokStart;
    s32 tokLen;
    s8 c;
    s32 match;
    u8 *urlEnd;
    u8 *digStart;
    s32 digLen;
    s32 value;

    p = arg0;
    tokStart = NULL;
    tokLen = 0;
    for (;;) {
        c = (s8) *p;
        if (c == 0) {
            break;
        }
        if (fn_803B38C4(c) != 0) {
            if (tokStart == NULL) {
                tokStart = p;
            }
            tokLen += 1;
            p += 1;
            continue;
        }
        if (fn_803B38AC(c) != 0) {
            if (tokStart == NULL) {
                tokStart = p;
            }
            tokLen += 1;
            p += 1;
            continue;
        }
        if (strchr((const char *) lbl_80534C08, c) != NULL) {
            if (tokStart == NULL) {
                tokStart = p;
            }
            tokLen += 1;
            p += 1;
            continue;
        }
        break;
    }
    if (tokStart == NULL) {
        return -1;
    }
    if (tokLen == 4 && strncmp((const char *) tokStart, lbl_805DD240, 4) == 0) {
        match = 1;
    } else if (tokLen == 3 && strncmp((const char *) tokStart, lbl_805DD248, 3) == 0) {
        match = 1;
    } else {
        match = 0;
    }
    if (!match) {
        return -1;
    }

    urlEnd = kar_ipigmp__near_80482b64(arg0, &tokStart, &tokLen);
    if (tokStart == NULL) {
        return -1;
    }
    if (!IsSpaceOrTab(*urlEnd)) {
        return -1;
    }

    digStart = urlEnd + 1;
    digLen = 0;
    while (fn_803B38AC((s8) *digStart) != 0) {
        digStart += 1;
        digLen += 1;
    }
    if (digLen != 3) {
        return -1;
    }
    if (!IsSpaceOrTab(digStart[0])) {
        return -1;
    }

    digStart = urlEnd + 1;
    value = 0;
    while (digLen > 0) {
        value = ((s8) *digStart) + value * 0xA - 0x30;
        digStart += 1;
        digLen -= 1;
    }
    return value;
}

s32 fn_80483C1C(u8 *arg0) {
    return kar_ipigmp__near_804830a4(arg0);
}

u8 *fn_804859C8(void *arg0, u8 *arg1) {
    return kar_ipigmp__near_80482598(arg0, arg1);
}

s32 fn_804859E8(u8 *arg0, u8 *arg1) {
    return kar_ipigmp__near_8048263c(arg0, arg1);
}

s32 fn_80485AB8(void *arg0, void *arg1) {
    return kar_ipigmp__near_80482730(arg0, arg1);
}

s32 fn_8048530C(void) {
    return lbl_805DE6D0;
}

void *fn_804858FC(void) {
    return lbl_805C2AF8;
}

s32 fn_8048841C(void) {
    return FS32(lbl_805C3C40, 0xF8);
}

s32 fn_804881C0(void) {
    return FS32(lbl_805C3C40, 0x90) == 1 ? 1 : 0;
}
