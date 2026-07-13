#include <global.h>
#include <sysdolphin/dvdsche.h>

typedef struct kar_dvdsche_stream_scheduler_slot {
    s32 key;
    void (*callback)(s32, void*);
    s32 param;
} kar_dvdsche_stream_scheduler_slot_t;

static kar_dvdsche_stream_scheduler_slot_t
    kar_dvdsche_stream_scheduler_slots[4];
static s32 kar_dvdsche_stream_scheduler_order[4];

static s32 lbl_805DE4C0;
static s32 lbl_805DE4C4;
static s32 lbl_805DE4C8;
static s32 lbl_805DE4CC;
static s32 lbl_805DE4D0;
static u32 lbl_805DE4D4;
static s32 lbl_805DE4D8;

char kar_srcfile_dvdsche_c[] = "dvdsche.c";

void kar_dvdsche_dispatch_stream_scheduler_callbacks(void)
{
    s32 i;
    s32 found;
    kar_dvdsche_stream_scheduler_slot_t* slot;

    if (lbl_805DE4D8 < lbl_805DE4C8 &&
        lbl_805DE4CC != 0)
    {
        slot = &kar_dvdsche_stream_scheduler_slots
                    [kar_dvdsche_stream_scheduler_order[lbl_805DE4D8]];
        if (slot->key <= lbl_805DE4C4) {
            lbl_805DE4D0 = 1;
            slot->callback(slot->param, 0);
            lbl_805DE4CC -= 1;
            return;
        }
    }

    lbl_805DE4CC = lbl_805DE4C4;
    lbl_805DE4D8 += 1;
    if (lbl_805DE4D8 < lbl_805DE4C8) {
        kar_dvdsche_dispatch_stream_scheduler_callbacks();
        return;
    }

    lbl_805DE4D8 = 0;
    if (lbl_805DE4C8 == 0) {
        lbl_805DE4D0 = 0;
        return;
    }

    found = 0;
    for (i = 0; i < lbl_805DE4C8; i++) {
        if (kar_dvdsche_stream_scheduler_slots[kar_dvdsche_stream_scheduler_order[i]]
                .key <= lbl_805DE4C4)
        {
            found = 1;
        }
    }
    if (found) {
        kar_dvdsche_dispatch_stream_scheduler_callbacks();
        return;
    }
    lbl_805DE4D0 = -1;
}

s32 kar_dvdsche_alloc_stream_scheduler_slot(void (*callback)(s32, void*),
                                             s32 param)
{
    u32 enabled;
    s32 newid;
    u32 bit;
    s32 i;
    s32 orderix;
    s32 n;

    newid = -1;
    if (lbl_805DE4C8 >= lbl_805DE4C0) {
        return -1;
    }
    enabled = OSDisableInterrupts();
    n = lbl_805DE4C8;
    lbl_805DE4C8 += 1;
    for (i = 0; i < n; i++) {
        bit = 1 << i;
        if (!(lbl_805DE4D4 & bit)) {
            newid = i;
            lbl_805DE4D4 |= bit;
            break;
        }
    }
    if (newid == -1) {
        OSReport("assertion %s failed.\n", "newid != -1");
        OSPanic("dvdsche.c", 0x43, "newid != -1");
    }
    kar_dvdsche_stream_scheduler_slots[newid].key = 0;
    kar_dvdsche_stream_scheduler_slots[newid].callback = callback;
    kar_dvdsche_stream_scheduler_slots[newid].param = param;
    if (lbl_805DE4D0 == 1) {
        orderix = lbl_805DE4C8;
        for (i = lbl_805DE4C8 - 1; i > (s32) lbl_805DE4D8; i--) {
            kar_dvdsche_stream_scheduler_order[i] =
                kar_dvdsche_stream_scheduler_order[i - 1];
        }
        kar_dvdsche_stream_scheduler_order[orderix] = newid;
        lbl_805DE4D8 += 1;
    } else {
        for (i = lbl_805DE4C8; i > 0; i--) {
            kar_dvdsche_stream_scheduler_order[i] =
                kar_dvdsche_stream_scheduler_order[i - 1];
        }
        kar_dvdsche_stream_scheduler_order[0] = newid;
        kar_dvdsche_dispatch_stream_scheduler_callbacks();
    }
    OSRestoreInterrupts(enabled);
    return newid;
}

void kar_dvdsche_free_stream_scheduler_slot(s32 id)
{
    u32 enabled;
    s32 i;
    s32 orderix;
    s32 n;

    if (!(lbl_805DE4D4 & (1 << id))) {
        OSReport("assertion %s failed.\n", "hsd_DVDScheStreamingFlag & (1 << id)");
        OSPanic("dvdsche.c", 0x7B, "hsd_DVDScheStreamingFlag & (1 << id)");
    }
    enabled = OSDisableInterrupts();
    lbl_805DE4D4 &= ~(1 << id);
    if (lbl_805DE4C8 == 0) {
        OSReport("assertion %s failed.\n", "hsd_DVDScheNStreaming");
        OSPanic("dvdsche.c", 0x81, "hsd_DVDScheNStreaming");
    }
    orderix = -1;
    n = lbl_805DE4C8 - 1;
    lbl_805DE4C8 = n;
    for (i = 0; i <= n; i++) {
        if (kar_dvdsche_stream_scheduler_order[i] == id) {
            orderix = i;
            for (; i < n; i++) {
                kar_dvdsche_stream_scheduler_order[i] =
                    kar_dvdsche_stream_scheduler_order[i + 1];
            }
            break;
        }
    }
    if (orderix == -1) {
        OSReport("assertion %s failed.\n", "orderix != -1");
        OSPanic("dvdsche.c", 0x6B, "orderix != -1");
    }
    if ((s32) lbl_805DE4D8 == orderix) {
        kar_dvdsche_dispatch_stream_scheduler_callbacks();
    } else if ((s32) lbl_805DE4D8 > orderix) {
        lbl_805DE4D8 -= 1;
    }
    OSRestoreInterrupts(enabled);
}

void kar_dvdsche_set_stream_scheduler_slot_key(s32 id, s32 key)
{
    if (id < 0 || id >= lbl_805DE4C0) {
        OSReport("assertion %s failed.\n",
                 "id >= 0 && id < hsd_DVDScheNStreamingMax");
        OSPanic("dvdsche.c", 0x8F, "id >= 0 && id < hsd_DVDScheNStreamingMax");
    }
    if (!(lbl_805DE4D4 & (1 << id))) {
        OSReport("assertion %s failed.\n", "hsd_DVDScheStreamingFlag & (1 << id)");
        OSPanic("dvdsche.c", 0x91, "hsd_DVDScheStreamingFlag & (1 << id)");
    }
    OSDisableInterrupts();
    kar_dvdsche_stream_scheduler_slots[id].key = key;
    if (lbl_805DE4D0 == -1) {
        kar_dvdsche_dispatch_stream_scheduler_callbacks();
    }
    OSRestoreInterrupts(1);
}

void kar_dvdsche_set_stream_scheduler_slot_callback(s32 id,
                                                      void (*callback)(s32,
                                                                        void*))
{
    if (id < 0 || id >= lbl_805DE4C0) {
        OSReport("assertion %s failed.\n",
                 "id >= 0 && id < hsd_DVDScheNStreamingMax");
        OSPanic("dvdsche.c", 0xA0, "id >= 0 && id < hsd_DVDScheNStreamingMax");
    }
    if (!(lbl_805DE4D4 & (1 << id))) {
        OSReport("assertion %s failed.\n", "hsd_DVDScheStreamingFlag & (1 << id)");
        OSPanic("dvdsche.c", 0xA2, "hsd_DVDScheStreamingFlag & (1 << id)");
    }
    OSDisableInterrupts();
    kar_dvdsche_stream_scheduler_slots[id].callback = callback;
    OSRestoreInterrupts(1);
}

char kar_srcfile_synth_c_805dd160[] = "synth.c";

#define ASSERT_SYNTH(line, cond) \
    ((cond) ? ((void) 0) : __assert(kar_srcfile_synth_c_805dd160, line, #cond))
#define ASSERT_SYNTH_MSG(line, cond, msg) \
    ((cond) ? ((void) 0) : __assert(kar_srcfile_synth_c_805dd160, line, msg))
#define ASSERT_SYNTH_REPORT(line, cond, ...)                                  \
    ((cond) ? (void) 0                                                        \
            : (OSReport(__VA_ARGS__),                                         \
               __assert(kar_srcfile_synth_c_805dd160, line, #cond)))

#define USERVOL_NUM 2
#define USERPAN_NUM 2
#define HSD_SYNTHSFXNODE_MAX 0x40

static s32 HSD_Synth_804D6018 = -1;

static HSD_SynthSFXNode lbl_80597660[HSD_SYNTHSFXNODE_MAX];
static u32 hsd_SynthSFXBankNum;
static u32 hsd_SynthSFXBankAREnd;

static volatile s32 HSD_Synth_804D772C;
static s32 HSD_Synth_804D7738;
static s32 HSD_Synth_804D775C;

static s32 lbl_805DE4E0;

static HSD_SynthSFXNode* lbl_805DE504; /* vol-update pending list head */
static HSD_SynthSFXNode* lbl_805DE508; /* mix-update pending list head */
static HSD_SynthSFXNode* lbl_805DE50C; /* rear-link update list head */

static HSD_SynthSFXNode* lbl_805DE514; /* bmb free list */
static HSD_SynthSFXNode* lbl_805DE518;
static HSD_SynthSFXNode* lbl_805DE51C;
static HSD_SynthPStreamEntry* lbl_805DE520; /* pstream entry free list */
static HSD_SynthPStreamEntry* lbl_805DE524; /* pstream entry active list */

static s32 lbl_805DE528;
static u32 lbl_805DE52C;
static s32 lbl_805DE530;
static s32 lbl_805DE534;
static s32 lbl_805DE538; /* sound mode */
static s32 lbl_805DE53C;
static void* (*lbl_805DE4E4)(s32);
static void (*lbl_805DE4E8)(void*);
static s32 lbl_805DE4EC;
static s32 lbl_805DE4F0;
static s32 lbl_805DE4F4;
static void (*lbl_805DE4F8)(s32);
static void (*lbl_805DE4FC)(u32);
static void (*lbl_805DE500)(s32);
static s32 lbl_805DE510;

/* lbl_80596DA0: hsd_SynthSFXLoadBuf[8] (0x20) + free-voice hash heads[0x20] (0x80) */
static u32 lbl_80596DA0[0x28];
#define hsd_SynthSFXLoadBuf lbl_80596DA0
#define HSD_Synth_804C29E0 ((void**) (lbl_80596DA0 + 8))

static struct {
    s32 entrynum;
    s32 bankID;
    s32 unk8;
    s32 unkC;
} lbl_80596E40[0x20];

static s32 lbl_80597040[0x20]; /* hsd_SynthSFXBank[0x20] */
static void* lbl_80597040_2[0x20]; /* free-voice-bank hash heads, adjacent */
#define hsd_SynthSFXBank lbl_80597040
#define HSD_Synth_804C2AE0 lbl_80597040_2

static s32 lbl_80597140[0x38];
#define hsd_SynthSFXBankHead lbl_80597140

typedef struct {
    u32 unk0;
    u8 pad4[0x18];
    u8 unk1C;
    u8 pad1D[3];
    HSD_SynthSFXNode* unk20;
    u8 pad24[0x1C];
} lbl_80597220_t;
static lbl_80597220_t lbl_80597220[0x11];

static HSD_SynthSFXNode lbl_80597660[HSD_SYNTHSFXNODE_MAX];
static f32 lbl_80599C60[0x100];
static AXVPB* lbl_8059A060[0x40];

typedef struct {
    f32 volume;
    s32 mode;
    union {
        f32 f;
        s32 i;
    } target;
    s32 dbxRaw;
    s32 duration;
    s32 delay;
} HSD_SynthVolFader;
static HSD_SynthVolFader lbl_8059A160;
static HSD_SynthVolFader lbl_8059A178[0x40];
#define HSD_SYNTHPSTREAM_MAX 4
static HSD_SynthPStreamEntry lbl_8059A178_pstpool[HSD_SYNTHPSTREAM_MAX];

static HSD_ObjAllocData lbl_8059A818;

static AXPBSRC lbl_8050932C = { 1, 0, 0, { 0, 0, 0, 0 } };

static char lbl_805DD168[] = "p";
static s32 lbl_805DD16C = 0;
static char lbl_805DD174[] = "0";
static s32 lbl_805DD178 = -0x03880000;
static s32 lbl_805DD17C = -1;
static s8 lbl_805DD180[4] = "bmb";
static s8 lbl_805DD184[8] = "bmbnext";
static u32 lbl_805DD18C[2] = { 0, 0 };
static f32 lbl_805DD194 = 1.0f;
static s8 lbl_805DD198[6] = "entry";
static void* lbl_805DD158;

static f32 lbl_805DC890;
static f32 lbl_805DC894;

static char lbl_805093B0[] = "flag == 0 || flag == 1";

static void* lbl_805DE548; /* current SFX load dest pointer */
static u32* lbl_805DE544;  /* current SFX load source parse pointer */
static void* lbl_805DE540; /* default (silence) sample bank base */
static void* lbl_805DE54C; /* max SFX bank heap boundary */
static u8 lbl_805DE550;

void HSD_SynthSFXLoadNewProc(void);
void HSD_SynthSFXFreeVoice(HSD_SynthSFXNode* node);
void HSD_SynthSFXStopBank(s32 bankID);
void HSD_SynthSFXStopRange(u32 lo, u32 hi);
void HSD_SynthSFXKeyOff(s32 id);
void HSD_SynthSFXUpdatePitch(HSD_SynthSFXNode* node);
void HSD_SynthSFXUpdateVolume(HSD_SynthSFXNode* node);
void HSD_SynthSFXInitMix(HSD_SynthSFXNode* node);
void HSD_SynthSFXUpdateMix(HSD_SynthSFXNode* node, s32 interpolate);
void HSD_SynthSFXMixShort(HSD_SynthSFXNode* node, s32 unused);
void HSD_SynthSFXLinkUpdateRearPitch(HSD_SynthSFXNode* rear, u16 unused);
void HSD_SynthSFXVolFaderProc(void);
void HSD_SynthSFXMixEnvelope(void);
void HSD_SynthCallback(void);
void HSD_SynthPStreamHakoDataCallback(s32 pstreamID);
void HSD_SynthPStreamLinkBeatMarker(s32 pstreamID, void* markerData, s32 count);
void HSD_SynthPStreamHakoExtHeaderCallback(s32 pstreamID, void* header);
void HSD_SynthPStreamFirstHakoDataCallback(s32 pstreamID, void* addr);
void HSD_SynthPStreamFirstHakoExtHeaderCallback(s32 pstreamID, void* header);
void HSD_SynthPStreamFirstHakoHeaderCallback(s32 pstreamID);
void HSD_SynthPStreamHeaderCallback(s32 pstreamID, void* header);
void dropcallback(void* dropped);

static inline HSD_SynthSFXNode* getNode(s32 id)
{
    HSD_SynthSFXNode* node = &lbl_80597660[id & (HSD_SYNTHSFXNODE_MAX - 1)];
    if (id > 0 && node->sfxID == id) {
        return node;
    }
    return NULL;
}

void HSD_AudioSetMallocFreeProc(void* (*mallocProc)(s32), void (*freeProc)(void*))
{
    lbl_805DE4E4 = mallocProc;
    lbl_805DE4E8 = freeProc;
}

void* HSD_AudioMalloc(u32 size)
{
    void* p = lbl_805DE4E4(size);
    ASSERT_SYNTH_MSG(0x29, p, lbl_805DD168);
    return p;
}

void HSD_AudioFree(void* ptr)
{
    lbl_805DE4E8(ptr);
}

struct kar_dvdsche_sfxentry {
    void* next;
    s32 id;
    s32 base;
    s32 count;
    u8 samples[0x40];
};

void HSD_SynthSFXSampleLoadCallback(s32 result, s32 length, void* addr,
                                     s32 cancelflag)
{
    u32 enabled;
    s32 i;

    if (lbl_805DE4F4 == 0) {
        u32 header_size = hsd_SynthSFXLoadBuf[0];
        u32 data_bytes = header_size - 0x10;
        s32 src_idx = (data_bytes >> 2) - 1;
        u32 total;
        u32 shift;
        u32 dnw;
        s32 bankID;
        void** pp;
        s32 count;
        s32 base;

        total = hsd_SynthSFXLoadBuf[2] * 8 + header_size;
        total = (total + 0x37) & ~0x1F;
        shift = (total - data_bytes) >> 2;
        for (i = src_idx; i >= 0; i--) {
            ((u32*) lbl_805DE548)[i + shift] = ((u32*) lbl_805DE548)[i];
        }
        dnw = total - header_size;
        *(u32*) ((u8*) lbl_805DE548 + (dnw & ~3)) = hsd_SynthSFXLoadBuf[4];
        ((u32*) lbl_805DE548)[(dnw >> 2) + 1] = hsd_SynthSFXLoadBuf[5];
        ((u32*) lbl_805DE548)[(dnw >> 2) + 2] = hsd_SynthSFXLoadBuf[6];
        ((u32*) lbl_805DE548)[(dnw >> 2) + 3] = hsd_SynthSFXLoadBuf[7];
        lbl_805DE544 = (u32*) ((u8*) lbl_805DE548 + (dnw & ~3));

        bankID = lbl_80596E40[0].bankID;
        pp = &HSD_Synth_804C2AE0[bankID];
        while (*pp != NULL) {
            pp = *pp;
        }
        *pp = lbl_805DE548;

        ((struct kar_dvdsche_sfxentry*) lbl_805DE548)->next = NULL;
        ((struct kar_dvdsche_sfxentry*) lbl_805DE548)->id = lbl_80596E40[0].entrynum;
        count = hsd_SynthSFXLoadBuf[2];
        base = hsd_SynthSFXLoadBuf[3];
        ((struct kar_dvdsche_sfxentry*) lbl_805DE548)->base = base;
        ((struct kar_dvdsche_sfxentry*) lbl_805DE548)->count = count;
        lbl_805DE548 = (u8*) lbl_805DE548 + 0x18;
        for (i = 0; i < count; i++) {
            s32 n;
            s32 nbytes;
            s32 k;
            s32 offset;
            s32 id;
            void** bucket;
            struct kar_dvdsche_sfxentry* nn;

            n = *lbl_805DE544;
            nbytes = (n << 6) + 8;
            memcpy((u8*) lbl_805DE548 + 8, lbl_805DE544, nbytes);
            offset = 0;
            for (k = 0; k < n; k++) {
                u8* e = (u8*) lbl_805DE548 + offset;
                if (e + 0x10 != NULL) {
                    *(u32*) (e + 0x14) += hsd_SynthSFXBank[bankID] * 2;
                } else {
                    *(u32*) (e + 0x14) = (u32) lbl_805DE540;
                }
                *(u32*) ((u8*) lbl_805DE548 + offset + 0x18) +=
                    hsd_SynthSFXBank[bankID] * 2;
                *(u32*) ((u8*) lbl_805DE548 + offset + 0x1C) +=
                    hsd_SynthSFXBank[bankID] * 2;
                offset += 0x40;
            }
            nn = (struct kar_dvdsche_sfxentry*) lbl_805DE548;
            id = base + i;
            nn->id = id;
            bucket = &HSD_Synth_804C29E0[id & 0x1F];
            nn->next = *bucket;
            *bucket = nn;
            lbl_805DE544 += ((u32) nbytes & ~3) >> 2;
            lbl_805DE548 = (u8*) lbl_805DE548 + ((((n << 6) + 0x10)) & ~3);
        }
        if (lbl_80596E40[0].unk8 != 0) {
            ((void (*)(s32, s32)) lbl_80596E40[0].unk8)(lbl_80596E40[0].entrynum,
                                                          lbl_80596E40[0].unkC);
        }
        hsd_SynthSFXBank[bankID] += hsd_SynthSFXLoadBuf[1];
    } else {
        if (lbl_805DE548 != NULL) {
            OSFreeToHeap(HSD_Synth_804D6018, lbl_805DE548);
        }
        lbl_805DE4F4 = 0;
    }
    enabled = OSDisableInterrupts();
    lbl_805DE4F0 -= 1;
    for (i = 0; i < lbl_805DE4F0; i++) {
        lbl_80596E40[i] = lbl_80596E40[i + 1];
    }
    HSD_SynthSFXLoadNewProc();
    OSRestoreInterrupts(enabled);
}

void HSD_SynthSFXHeaderLoadCallback(s32 result, s32 length, void* addr,
                                     s32 cancelflag)
{
    s32 bankID;
    s32 header_size;
    void* p;
    u32 alloc_size;

    if (lbl_805DE4F4 == 0) {
        bankID = lbl_80596E40[0].bankID;

        ASSERT_SYNTH_REPORT(
            0x14F,
            hsd_SynthSFXBankHead[bankID + 1] - hsd_SynthSFXBank[bankID] >=
                (s32) hsd_SynthSFXLoadBuf[1],
            "Can't load SFX file; bank(id=%d) buffer overflow.\n",
            lbl_80596E40[0].bankID);

        alloc_size = hsd_SynthSFXLoadBuf[2] * 8 + 0x18;
        header_size = hsd_SynthSFXLoadBuf[0];
        p = lbl_805DE4E4(OSRoundUp32B(alloc_size + header_size));
        ASSERT_SYNTH_REPORT(0x29, p, "audio heap overflow. size = %u\n",
                             OSRoundUp32B(alloc_size + header_size));
        lbl_805DE548 = p;
        HSD_DevComRequest(lbl_80596E40[0].entrynum, 0x20, lbl_805DE548,
                           OSRoundUp32B(header_size - 0x10), 0x21, 1, NULL, 0);
        HSD_DevComRequest(
            lbl_80596E40[0].entrynum, OSRoundUp32B(header_size + 0x10),
            (void*) hsd_SynthSFXBank[bankID], hsd_SynthSFXLoadBuf[1], 0x23, 1,
            (void (*)(s32, void*, s32, s32)) HSD_SynthSFXSampleLoadCallback,
            NULL);
        return;
    }
    lbl_805DE548 = NULL;
    HSD_SynthSFXSampleLoadCallback(0, 0, NULL, 0);
}

void HSD_SynthSFXLoadNewProc(void)
{
    if (lbl_805DE4F0 != 0) {
        u32 enabled = OSDisableInterrupts();
        lbl_805DD16C = HSD_DevComRequest(
            lbl_80596E40[0].entrynum, 0, hsd_SynthSFXLoadBuf, 0x20, 0x21, 1,
            (void (*)(s32, void*, s32, s32)) HSD_SynthSFXHeaderLoadCallback,
            NULL);
        OSRestoreInterrupts(enabled);
    }
}

s32 HSD_SynthSFXLoad(const s8* filename, s32 bankID, s32 flags, s32 mode)
{
    s32 entrynum;
    u32 enabled;

    ASSERT_SYNTH_REPORT(0x18F, bankID >= 0 && bankID < lbl_805DE4EC,
                         "max=%d: invalid bankID = %d; filename = %s\n",
                         lbl_805DE4EC, bankID, filename);

    entrynum = DVDConvertPathToEntrynum(filename);

    while (lbl_805DE4F0 >= 0x20) {
        ASSERT_SYNTH_MSG(0x193, 0, lbl_805DD174);
    }

    enabled = OSDisableInterrupts();
    lbl_80596E40[lbl_805DE4F0].entrynum = entrynum;
    lbl_80596E40[lbl_805DE4F0].bankID = bankID;
    lbl_80596E40[lbl_805DE4F0].unk8 = flags;
    lbl_80596E40[lbl_805DE4F0].unkC = mode;
    lbl_805DE4F0 += 1;

    if (lbl_805DE4F0 == 1) {
        HSD_SynthSFXLoadNewProc();
    }

    OSRestoreInterrupts(enabled);
    return entrynum;
}

void HSD_SynthSFXWaitForLoadCompletion(void (*callback)(void))
{
    while (lbl_805DE4F0 != 0) {
        callback();
    }
}

s32 HSD_SynthSFXGetPendingLoadCount(void)
{
    return lbl_805DE4F0 - lbl_805DE4F4;
}

s32 HSD_SynthSFXNewBank(s32 size)
{
    s32 base;
    u32 top;

    if (lbl_805DE4EC >= 0x20) {
        return -1;
    }
    base = hsd_SynthSFXBank[lbl_805DE4EC];
    top = size + base;
    if (top > (u32) lbl_805DE54C) {
        return -1;
    }
    hsd_SynthSFXBankHead[lbl_805DE4EC] = base;
    hsd_SynthSFXBankHead[lbl_805DE4EC + 1] = top;
    lbl_805DE4EC += 1;
    return lbl_805DE4EC - 1;
}

s32 HSD_SynthSFXBankClear(s32 bankID)
{
    void* cur;
    u32 enabled = OSDisableInterrupts();

    if (bankID < 0 || bankID >= lbl_805DE4EC) {
        OSRestoreInterrupts(enabled);
        return -1;
    }
    HSD_SynthSFXStopBank(bankID);
    while ((cur = HSD_Synth_804C2AE0[bankID]) != NULL) {
        struct kar_dvdsche_sfxentry* e = cur;
        s32 i;
        for (i = 0; i < e->count; i++) {
            s32 id = e->base + i;
            void** bucket = &HSD_Synth_804C29E0[id & 0x1F];
            void* p;
            while ((p = *bucket) != NULL) {
                if (((struct kar_dvdsche_sfxentry*) p)->id == id) {
                    *bucket = ((struct kar_dvdsche_sfxentry*) p)->next;
                    break;
                }
                bucket = p;
            }
        }
        HSD_Synth_804C2AE0[bankID] = e->next;
        lbl_805DE4E8(e);
    }
    hsd_SynthSFXBank[bankID] = hsd_SynthSFXBankHead[bankID];
    OSRestoreInterrupts(enabled);
    return 0;
}

s32 HSD_SynthVolToDBx(f32 vol)
{
    s32 dbx;

    if (vol < 0.000030199517f) {
        return lbl_805DD178;
    }
    if (vol >= 1.0f) {
        if (vol == 1.0f) {
            return 0;
        }
    }
    dbx = (s32) (5692384.633202305 * kar_axdriver__near_803bd428());
    if (dbx < lbl_805DD178) {
        dbx = lbl_805DD178;
    }
    return dbx;
}

f32 HSD_SynthDBxToVol(s32 dbx)
{
    if (dbx <= lbl_805DD178) {
        return 0.0f;
    }
    if (dbx >= 0) {
        return 1.0f;
    }
    return (f32) kar_axdriver__803bd3e8(1.75673301162265e-07 * (f64) dbx,
                                         1.75673301162265e-07);
}

u32 HSD_SynthGetSoundMode(void)
{
    return lbl_805DE538;
}

void HSD_SynthSetSoundMode(s32 mode)
{
    s32 i;
    u32 enabled;

    lbl_805DE538 = mode;
    switch (mode) {
    case 2:
    case 4:
        fn_803ED0CC(1);
        break;
    case 3:
        fn_803ED0CC(2);
        break;
    default:
        fn_803ED0CC(0);
        break;
    }
    OSSetSoundMode(mode != 0);
    enabled = OSDisableInterrupts();
    for (i = 0; i < HSD_SYNTHSFXNODE_MAX; i++) {
        if (lbl_80597660[i].sfxID > 0) {
            HSD_SynthSFXUpdateMix(&lbl_80597660[i], 1);
        }
    }
    OSRestoreInterrupts(enabled);
}

void HSD_SynthInitPantable(s32 mode)
{
    s32 i;

    switch (mode) {
    case 0:
        for (i = 0; i < 0xFF; i++) {
            f32 x = 0.003937008f * (f32) i;
            f32 result;
            if (x > 0.0f) {
                f32 y0 = __frsqrte(x);
                f32 y1 = 0.5f * y0 * (3.0f - x * y0 * y0);
                f32 y2 = 0.5f * y1 * (3.0f - x * y1 * y1);
                f32 y3 = 0.5f * y2 * (3.0f - x * y2 * y2);
                f32 y4 = 0.5f * y3 * (3.0f - x * y3 * y3);
                result = x * y4;
            } else if (x == 0.0f) {
                result = 0.0f;
            } else {
                result = lbl_805DC890;
            }
            lbl_80599C60[i] = result;
        }
        break;
    case 1:
        for (i = 0; i <= 0xFE; i++) {
            lbl_80599C60[i] = (f32) sin(0.006184237507066522 * (f64) i);
        }
        break;
    case 2:
        for (i = 0; i < 0xFF; i++) {
            lbl_80599C60[i] = (f32) i / 254.0f;
        }
        break;
    }
    lbl_80599C60[0xFF] = lbl_80599C60[0xFE];
}

void HSD_SynthSFXFreeVoice(HSD_SynthSFXNode* node)
{
    HSD_SynthSFXNode** it;
    s32 i;
    u32 enabled = OSDisableInterrupts();

    if (!(node->flags & 1) && node->pstreamLink == NULL &&
        lbl_805DE4F8 != NULL)
    {
        lbl_805DE4F8(node->sfxID);
    }

    if (node->volUpdatePending) {
        it = &lbl_805DE504;
        while (*it != NULL) {
            if (*it == node) {
                node->volUpdatePending = 0;
                *it = node->volUpdateNext;
                break;
            }
            it = &(*it)->volUpdateNext;
        }
    }
    if (node->mixUpdatePending) {
        it = &lbl_805DE508;
        while (*it != NULL) {
            if (*it == node) {
                node->mixUpdatePending = 0;
                *it = node->mixUpdateNext;
                break;
            }
            it = &(*it)->mixUpdateNext;
        }
    }
    if (node->rearIndex != -1) {
        HSD_SynthSFXNode** rit = &lbl_805DE50C;
        HSD_SynthSFXNode* rear = &lbl_80597660[node->rearIndex];
        while (*rit != NULL) {
            if (*rit == rear) {
                *rit = (HSD_SynthSFXNode*) rear->pstreamLink;
                break;
            }
            rit = (HSD_SynthSFXNode**) &(*rit)->pstreamLink;
        }
    }

    if (node->pstreamLink != NULL) {
        HSD_SynthPStreamEntry* pst = node->pstreamLink;
        HSD_SynthPStreamEntry** pit;

        if (pst->schedulerSlot >= 0) {
            kar_dvdsche_free_stream_scheduler_slot(pst->schedulerSlot);
        }
        for (pit = &lbl_805DE524; *pit != NULL && *pit != pst; pit = &(*pit)->next) {
        }
        if (*pit != NULL) {
            for (; (*pit)->next != NULL;) {
                HSD_SynthPStreamEntry* e = *pit;
                s16 buf = e->bufIdx;
                if (buf != -2) {
                    HSD_SynthSFXNode** hit =
                        (HSD_SynthSFXNode**) &lbl_80597220[buf].unk20;
                    while (*hit != NULL) {
                        HSD_SynthSFXNode* h = *hit;
                        *hit = h->next;
                        h->next = lbl_805DE514;
                        lbl_805DE514 = h;
                    }
                }
            }
            *pit = (*pit)->next;
        }
        pst->next = lbl_805DE520;
        lbl_805DE520 = pst;
    }

    for (i = 0; i <= (node->rearIndex == -1 ? 0 : 1); i++) {
        HSD_SynthSFXNode* base = (i == 0) ? node : &lbl_80597660[node->rearIndex];
        s32 j;
        for (j = 0; j < base->voice_count; j++) {
            AXFreeVoice(base->voice[j]);
            lbl_80597660[base->voice[j]->index].sfxID = 0;
        }
    }
    OSRestoreInterrupts(enabled);
}

void dropcallback(void* dropped)
{
    AXVPB* voice = dropped;
    HSD_SynthSFXNode* node;
    u32 enabled;
    s32 i;

    enabled = OSDisableInterrupts();

    node = &lbl_80597660[voice->index];

    for (i = 0; i < lbl_805DE4E0; i++) {
        if (lbl_8059A060[i] == voice) {
            lbl_8059A060[i] = NULL;
            break;
        }
    }

    if (node->sfxID == 0) {
        OSRestoreInterrupts(enabled);
        return;
    }

    if (node->sfxID == -1) {
        node = &lbl_80597660[node->voice[0]->index];
    }

    if (!(node->flags & 1) && node->pstreamLink == NULL && lbl_805DE4F8 != NULL) {
        lbl_805DE4F8(node->sfxID);
    }

    for (i = 0; i < node->voice_count; i++) {
        AXVPB* v = node->voice[i];
        if (v != voice) {
            lbl_8059A060[lbl_805DE4E0++] = v;
        }
        lbl_80597660[node->voice[i]->index].sfxID = 0;
    }

    OSRestoreInterrupts(enabled);
}

s32 HSD_SynthSFXStart(s32 sfxID, s32 vol, s32 volMode, s32 vol2, s32 vol2Mode,
                       u8 priority, u8 itd, u8 channel, f32 pitch1, f32 pitch2,
                       f32 pitchRatio, u8 unk16, s32 mixMode, s32 rearFlag,
                       s32 pan, s32 spanUnused)
{
    struct kar_dvdsche_sfxentry* entry;
    AXVPB* voices[2];
    HSD_SynthSFXNode* node;
    HSD_SynthSFXNode* rear = NULL;
    u32 enabled;
    s32 voiceIdx;
    s32 rearBucket;
    s32 index;
    s32 dup;
    s32 i;
    u32 uid;

    rearBucket = rearFlag;
    if (lbl_805DE538 != 4) {
        rearBucket = 0;
    }

    enabled = OSDisableInterrupts();
    entry = (struct kar_dvdsche_sfxentry*) HSD_Synth_804C29E0[sfxID & 0x1F];
    while (entry != NULL) {
        if (entry->id == sfxID) {
            break;
        }
        entry = entry->next;
    }
    if (entry == NULL) {
        OSRestoreInterrupts(enabled);
        return -1;
    }

    dup = 0;
    for (voiceIdx = 0; voiceIdx < entry->count * (rearBucket + 1); voiceIdx++) {
        voices[voiceIdx] = AXAcquireVoice(mixMode + 1, dropcallback, 0);
        if (voices[voiceIdx] == NULL) {
            for (i = voiceIdx - 1; i >= 0; i--) {
                if (voices[i] != NULL) {
                    AXFreeVoice(voices[i]);
                }
            }
            OSRestoreInterrupts(enabled);
            return -1;
        }
    }
    for (i = 0; i < entry->count * (rearBucket + 1); i++) {
        s32 j;
        for (j = i + 1; j < entry->count * (rearBucket + 1); j++) {
            if (voices[i] == voices[j]) {
                dup = 1;
            }
        }
    }
    if (dup) {
        for (i = 0; i < entry->count * (rearBucket + 1); i++) {
            if (voices[i] != NULL) {
                AXFreeVoice(voices[i]);
            }
        }
        OSRestoreInterrupts(enabled);
        return -1;
    }

    if (entry->count == 1 && rearBucket != 0) {
        rear = NULL;
    }
    if (entry->count == 2) {
        lbl_80597660[voices[1]->index].sfxID = -1;
        lbl_80597660[voices[1]->index].voice[0] = voices[0];
    }

    uid = voices[0]->index;
    node = &lbl_80597660[uid];
    node->unk16 = (s8) unk16;
    node->sfxID = sfxID;
    node->flags = 0;
    node->voice_count = (u8) entry->count;
    node->channel = channel;
    node->voice[0] = voices[0];
    node->voice[1] = voices[1];
    node->freqBase = (f32) entry->base / 32000.0f;
    node->pitch[0] = 1.0f;
    node->pitch[1] = 1.0f;

    if (volMode == 0) {
        node->user_vol[0].volume = 0.003921569f * (f32) vol;
        node->user_vol[0].target.f = node->user_vol[0].volume;
    } else {
        s32 raw = vol << 0x10;
        f32 v;
        if (raw <= lbl_805DD178) {
            v = 0.0f;
        } else if (raw >= 0) {
            v = 1.0f;
        } else {
            v = (f32) kar_axdriver__803bd3e8(1.75673301162265e-07 * (f64) raw,
                                              1.75673301162265e-07);
        }
        node->user_vol[0].volume = v;
        node->user_vol[0].target.i = raw;
    }
    node->user_vol[0].mode = volMode;

    if (vol2Mode == 0) {
        node->user_vol[1].volume = 0.003921569f * (f32) vol2;
        node->user_vol[1].target.f = node->user_vol[1].volume;
    } else {
        s32 raw = vol2 << 0x10;
        f32 v;
        if (raw <= lbl_805DD178) {
            v = 0.0f;
        } else if (raw >= 0) {
            v = 1.0f;
        } else {
            v = (f32) kar_axdriver__803bd3e8(1.75673301162265e-07 * (f64) raw,
                                              1.75673301162265e-07);
        }
        node->user_vol[1].volume = v;
        node->user_vol[1].target.i = raw;
    }
    node->user_vol[1].mode = vol2Mode;

    node->vol1Clamp = priority < 0xFE ? priority : 0xFE;
    node->vol2Clamp = itd < 0xFE ? itd : 0xFE;
    node->pan = channel;
    node->unk67 = 0;
    node->mixMain = pitch1;
    node->mixAuxA = pitch2;
    node->mixAuxB = pitchRatio;

    node->rearIndex = -1;
    if (rearBucket != 0 && rear != NULL) {
        s16 rearIdx = (s16) rear->voice[0]->index;
        node->rearIndex = rearIdx;
        rear->rearIndex = (s16) uid;
        rear->voice_count = node->voice_count;
    }

    lbl_8050932C.ratioHi = (u16) (65536.0f * node->freqBase);
    lbl_8050932C.ratioLo = 0;

    for (i = 0; i < entry->count; i++) {
        u8* sample = entry->samples + i * 0x40;
        kar_axdriver__803ec47c(voices[i], mixMode);
        fn_803EEC28(voices[i], (s16*) &node->user_vol[0].mode);
        fn_803EE7F4(voices[i], 2);
        fn_803EEFC8(voices[i], (u32*) &lbl_8050932C);
        fn_803EECCC(voices[i], sample);
        fn_803EEF24(voices[i], sample + 0x10);
        fn_803EF0F8(voices[i], sample + 0x38);
        if (lbl_805DE538 == 1) {
            fn_803EEB68(voices[i]);
        }
        kar_axdriver__803ee8b8(voices[i], 1);
    }

    HSD_SynthSFXUpdateVolume(node);
    HSD_SynthSFXInitMix(node);
    HSD_SynthSFXUpdateMix(node, 0);
    HSD_SynthSFXMixShort(node, 0);

    index = lbl_805DE510 + 0x40;
    lbl_805DE510 = index;
    if (index < 0) {
        lbl_805DE510 = 0x40;
    }
    node->sfxID = lbl_805DE510 + uid;
    OSRestoreInterrupts(enabled);
    return node->sfxID;
}

static inline void releasePStreamLink(HSD_SynthSFXNode* node)
{
    HSD_SynthPStreamEntry* pst = node->pstreamLink;
    HSD_SynthPStreamEntry** pit;

    if (pst->schedulerSlot >= 0) {
        kar_dvdsche_free_stream_scheduler_slot(pst->schedulerSlot);
    }
    for (pit = &lbl_805DE524; *pit != NULL && *pit != pst; pit = &(*pit)->next) {
    }
    if (*pit != NULL) {
        for (; (*pit)->next != NULL;) {
            HSD_SynthPStreamEntry* e = *pit;
            s16 buf = e->bufIdx;
            if (buf != -2) {
                HSD_SynthSFXNode** hit = (HSD_SynthSFXNode**) &lbl_80597220[buf].unk20;
                while (*hit != NULL) {
                    HSD_SynthSFXNode* h = *hit;
                    *hit = h->next;
                    h->next = lbl_805DE514;
                    lbl_805DE514 = h;
                }
            }
        }
        *pit = (*pit)->next;
    }
    pst->next = lbl_805DE520;
    lbl_805DE520 = pst;
}

void HSD_SynthSFXKeyOff(s32 id)
{
    HSD_SynthSFXNode* node;
    s32 i;
    u32 enabled = OSDisableInterrupts();

    node = getNode(id);
    if (node != NULL) {
        if (node->flags & 8) {
            HSD_SynthSFXFreeVoice(node);
        } else if (!(node->flags & 1)) {
            node->flags |= 1;
            HSD_SynthSFXUpdateVolume(node);
            for (i = 0; i < node->voice_count; i++) {
                kar_axdriver__803ec47c(node->voice[i], 1);
            }
            if (node->pstreamLink != NULL) {
                releasePStreamLink(node);
                node->pstreamLink = NULL;
            }
        }
    }
    OSRestoreInterrupts(enabled);
}

void HSD_SynthSFXStopRange(u32 lo, u32 hi)
{
    s32 i;
    u32 enabled = OSDisableInterrupts();

    for (i = 0; i < HSD_SYNTHSFXNODE_MAX; i++) {
        HSD_SynthSFXNode* node = &lbl_80597660[i];
        if (node->sfxID > 0) {
            u32 addr = AXVPB_CURRENT_ADDR(node->voice[0]);
            if (addr >= lo && addr < hi) {
                HSD_SynthSFXFreeVoice(node);
            }
        }
    }
    OSRestoreInterrupts(enabled);
}

#pragma push
#pragma dont_inline on
void HSD_SynthSFXStopBank(s32 bankID)
{
    HSD_SynthSFXStopRange(hsd_SynthSFXBankHead[bankID] * 2,
                           hsd_SynthSFXBankHead[bankID + 1] * 2);
}
#pragma pop

void HSD_SynthSFXPause(s32 id)
{
    HSD_SynthSFXNode* node;
    u32 enabled = OSDisableInterrupts();

    node = getNode(id);
    if (node != NULL) {
        node->flags |= 2;
        HSD_SynthSFXUpdateVolume(node);
        if (node->flags & 8) {
            node->flags |= 6;
        }
    }
    OSRestoreInterrupts(enabled);
}

void HSD_SynthSFXResume(s32 id)
{
    HSD_SynthSFXNode* node;
    u32 enabled = OSDisableInterrupts();

    node = getNode(id);
    if (node != NULL) {
        if (node->flags & 2) {
            node->flags &= ~6;
            HSD_SynthSFXUpdatePitch(node);
            HSD_SynthSFXUpdateVolume(node);
        }
    }
    OSRestoreInterrupts(enabled);
}

s32 HSD_SynthSFXCheck(s32 id)
{
    HSD_SynthSFXNode* node;
    s32 i;
    s32 result = id;
    u32 enabled = OSDisableInterrupts();

    node = getNode(id);
    if (node != NULL) {
        if (node->flags & 1) {
            result = -1;
        } else if (!(node->flags & 8)) {
            for (i = 0; i < node->voice_count; i++) {
                if (AXVPB_PB_STATE(node->voice[i]) == 0) {
                    result = -1;
                }
            }
        }
    } else {
        result = -1;
    }
    OSRestoreInterrupts(enabled);
    return result;
}

void HSD_SynthSetVolFader(s32 vol, s32 fadeFrames, s32 flag, s32 dbMode, s32 id)
{
    HSD_SynthSFXNode* node;
    u32 enabled = OSDisableInterrupts();

    node = getNode(id);
    if (node != NULL) {
        s32 frames;
        s32 changed = 0;

        ASSERT_SYNTH(0x7EB, flag >= 0 && flag < USERVOL_NUM);

        frames = fadeFrames < 1 ? 1 : fadeFrames;
        if (dbMode == 0) {
            node->user_vol[flag].target.f = (f32) (0.00392156862745098 * (f64) vol);
            if (node->user_vol[flag].volume != node->user_vol[flag].target.f) {
                node->user_vol[flag].fadeCount = frames;
                changed = 1;
            }
        } else {
            f32 curDbxVol;
            s32 dbx;
            s32 raw;
            f32 v;

            curDbxVol = node->user_vol[flag].volume;
            if (curDbxVol < 0.000030199517f) {
                dbx = lbl_805DD178;
            } else if (curDbxVol == 1.0f) {
                dbx = 0;
            } else {
                dbx = (s32) (5692384.633202305 * kar_axdriver__near_803bd428());
                if (dbx < lbl_805DD178) {
                    dbx = lbl_805DD178;
                }
            }
            node->user_vol[flag].dbxRaw = dbx;
            raw = vol << 0x10;
            node->user_vol[flag].target.i = raw;
            if (raw <= lbl_805DD178) {
                v = 0.0f;
            } else if (raw >= 0) {
                v = 1.0f;
            } else {
                v = (f32) kar_axdriver__803bd3e8(1.75673301162265e-07 * (f64) raw,
                                                  1.75673301162265e-07);
            }
            if (curDbxVol != v) {
                changed = 1;
                node->user_vol[flag].fadeCount = frames;
            }
        }
        node->user_vol[flag].mode = dbMode;
        if (changed) {
            HSD_SynthSFXUpdateVolume(node);
        }
    }
    OSRestoreInterrupts(enabled);
}

void HSD_SynthSFXSetPan(s32 id, u8 pan, s32 flag)
{
    HSD_SynthSFXNode* node;
    u32 enabled = OSDisableInterrupts();

    node = getNode(id);
    if (node != NULL) {
        ASSERT_SYNTH(0x80F, flag >= 0 && flag < USERPAN_NUM);
        if (pan > 0xFE) {
            pan = 0xFE;
        }
        if (flag == 0) {
            node->vol1Clamp = pan;
        } else {
            node->vol2Clamp = pan;
        }
        HSD_SynthSFXUpdateMix(node, 1);
    }
    OSRestoreInterrupts(enabled);
}

void HSD_SynthSFXSetSPan(s32 id, s8 span, s32 flag)
{
    HSD_SynthSFXNode* node;
    u32 enabled = OSDisableInterrupts();

    node = getNode(id);
    if (node != NULL) {
        ASSERT_SYNTH(0x824, flag >= 0 && flag < USERPAN_NUM);
        if (flag == 0) {
            node->pan = span;
        } else {
            node->unk67 = span;
        }
        HSD_SynthSFXUpdateMix(node, 1);
    }
    OSRestoreInterrupts(enabled);
}

void HSD_SynthSFXSetMix(s32 id, f32 mixMain, f32 mixAuxA, f32 mixAuxB)
{
    HSD_SynthSFXNode* node;
    u32 enabled = OSDisableInterrupts();

    node = getNode(id);
    if (node != NULL) {
        node->mixMain = mixMain;
        node->mixAuxA = mixAuxA;
        node->mixAuxB = mixAuxB;
        HSD_SynthSFXUpdateMix(node, 1);
    }
    OSRestoreInterrupts(enabled);
}

void HSD_SynthSFXLinkUpdateRearPitch(HSD_SynthSFXNode* rear, u16 unused)
{
    HSD_SynthSFXNode* it = lbl_805DE50C;

    ASSERT_SYNTH_MSG(0x845, rear->sfxID == -2, "rearEntry->sfxID == -2");
    while (it != NULL) {
        if (it == rear) {
            return;
        }
        it = (HSD_SynthSFXNode*) it->pstreamLink;
    }
    rear->pstreamLink = (HSD_SynthPStreamEntry*) lbl_805DE50C;
    lbl_805DE50C = rear;
}

void HSD_SynthSFXUpdatePitch(HSD_SynthSFXNode* node)
{
    f32 pitch;
    s32 i;

    if (node->sfxID != -2) {
        if (node->flags & 4) {
            pitch = 0.0f;
        } else {
            pitch = node->pitch[1] * (node->freqBase * node->pitch[0]);
        }
    } else {
        pitch = node->mixAuxB;
        if (AXVPB_PB_STATE(node->voice[0]) == 0) {
            for (i = 0; i < node->voice_count; i++) {
                kar_axdriver__803ee8b8(node->voice[i], 1);
            }
        }
    }
    if (!(node->flags & 8)) {
        for (i = 0; i < node->voice_count; i++) {
            s32 dirty = (node->voice[i]->sync & 0x40000) != 0;
            hwSetPitch(pitch);
            if (dirty) {
                node->voice[i]->sync &= ~0x40000;
                node->voice[i]->sync |= 0x40000;
            }
        }
    }
    if (node->sfxID != -2 && node->rearIndex != -1) {
        HSD_SynthSFXNode* rear = &lbl_80597660[node->rearIndex];
        ASSERT_SYNTH_MSG(0x86F, rear->sfxID == -2, "rearEntry->sfxID == -2");
        rear->mixAuxB = pitch;
        HSD_SynthSFXLinkUpdateRearPitch(rear, 0);
    }
}

#pragma push
#pragma dont_inline on
void HSD_SynthSFXSetPitch(s32 id, s32 flag, f32 ratio)
{
    HSD_SynthSFXNode* node = &lbl_80597660[id & (HSD_SYNTHSFXNODE_MAX - 1)];
    u32 enabled = OSDisableInterrupts();

    if (!(id > 0 && node->sfxID == id)) {
        node = NULL;
    }
    if (node != NULL && !(node->flags & 1)) {
        ASSERT_SYNTH_MSG(0x88A, flag == 0 || flag == 1, lbl_805093B0);
        node->pitch[flag] = ratio;
        HSD_SynthSFXUpdatePitch(node);
    }
    OSRestoreInterrupts(enabled);
}
#pragma pop

void HSD_SynthSFXSetPriority(s32 id, s32 prio)
{
    HSD_SynthSFXNode* node;
    s32 i;
    u32 enabled = OSDisableInterrupts();

    node = getNode(id);
    if (node != NULL && !(node->flags & 1)) {
        for (i = 0; i < node->voice_count; i++) {
            kar_axdriver__803ec47c(node->voice[i], prio);
        }
    }
    OSRestoreInterrupts(enabled);
}

static inline s32 tickFader(HSD_SynthVolFader* f)
{
    if (f->delay != 0) {
        f->delay -= 1;
        return 1;
    }
    if (f->duration == 0) {
        return 0;
    }
    if (f->mode == 0) {
        f->volume = (f->volume * ((f32) f->duration - 1.0f)) / (f32) f->duration +
                    f->target.f / (f32) f->duration;
    } else {
        s32 dbx = (s32) (((f32) f->dbxRaw * ((f32) f->duration - 1.0f)) /
                              (f32) f->duration +
                          (f32) f->target.i / (f32) f->duration);
        f->dbxRaw = dbx;
        if (dbx <= lbl_805DD178) {
            f->volume = 0.0f;
        } else if (dbx >= 0) {
            f->volume = 1.0f;
        } else {
            f->volume = (f32) kar_axdriver__803bd3e8(1.75673301162265e-07 * (f64) dbx,
                                                       1.75673301162265e-07);
        }
    }
    f->duration -= 1;
    return f->duration != 0;
}

void HSD_SynthSFXVolFaderProc(void)
{
    u32 enabled = OSDisableInterrupts();
    s32 masterActive = 0;
    s32 group;
    HSD_SynthSFXNode** it;

    if (lbl_8059A160.duration != 0) {
        masterActive = tickFader(&lbl_8059A160);
    }

    for (group = 0; group < 2; group++) {
        s32 bit;
        if (lbl_805DD18C[group] != 0) {
            for (bit = 0; bit < 0x20; bit++) {
                s32 chan = group * 0x20 + bit;
                if (lbl_805DD18C[group] & (1 << bit)) {
                    if (!tickFader(&lbl_8059A178[chan])) {
                        lbl_805DD18C[group] &= ~(1 << bit);
                    }
                }
            }
        }
    }

    it = &lbl_805DE504;
    while (*it != NULL) {
        HSD_SynthSFXNode* node = *it;
        s32 changed = 0;
        s32 uv;
        s32 vol;
        s32 delta;
        s32 i;
        HSD_SynthSFXNode* rear = NULL;

        if (node->sfxID <= 0) {
            node->volUpdatePending = 0;
            *it = node->volUpdateNext;
            continue;
        }

        for (uv = 0; uv < USERVOL_NUM; uv++) {
            if (node->user_vol[uv].fadeCount != 0) {
                if (tickFader((HSD_SynthVolFader*) &node->user_vol[uv])) {
                    changed = 1;
                }
            }
        }
        if (lbl_8059A178[node->channel].duration != 0) {
            changed = 1;
        }
        if (masterActive && node->channel < 0x3F) {
            changed = 1;
        }

        if (!(node->flags & 3)) {
            f32 masterVol = node->channel < 0x3F
                                 ? lbl_805DD194 * lbl_8059A160.volume
                                 : lbl_805DD194;
            vol = (s32) (32767.0f * (node->user_vol[1].volume *
                                      (node->user_vol[0].volume *
                                       (lbl_8059A178[node->channel].volume *
                                        masterVol))));
        } else {
            vol = 0;
            changed = 0;
        }
        delta = (vol - node->mix.vDeltaL) / 160;
        if (delta > 0x14) {
            delta = 0x14;
        } else if (delta < -0x14) {
            delta = -0x14;
        }
        for (i = 0; i < node->voice_count; i++) {
            fn_803EEC80(node->voice[i], (s16) delta);
        }
        node->mix.vDeltaL = (u16) (node->mix.vDeltaL + delta * 0xA0);

        if (node->rearIndex != -1) {
            rear = &lbl_80597660[node->rearIndex];
            /* rear-channel volume ramp mirrors the primary node's */
            rear->mix.vDeltaL = node->mix.vDeltaL;
            if (node->mix.vL != vol || node->mix.vDeltaR != delta) {
                changed = 1;
            }
            node->mix.vL = (u16) vol;
            node->mix.vDeltaR = (s16) delta;
        }
        if (delta == 0 && (changed == 0 || (f32) vol == 0.0f)) {
            node->mix.vDeltaL = (u16) vol;
            for (i = 0; i < node->voice_count; i++) {
                node->voice[i]->sync &= ~0x400;
                fn_803EEC28(node->voice[i], (s16*) &vol);
            }
            if (rear != NULL) {
                rear->mix.vL = (u16) vol;
                rear->mix.vDeltaR = 0;
            }
            if (changed == 0) {
                u8 flags;
                node->volUpdatePending = 0;
                *it = node->volUpdateNext;
                flags = node->flags;
                if (flags & 1) {
                    if (node->rearIndex == -1 || vol == 0) {
                        HSD_SynthSFXFreeVoice(node);
                    }
                } else if ((flags & 6) == 2) {
                    node->flags = flags | 6;
                    for (i = 0; i < node->voice_count; i++) {
                        HSD_SynthSFXUpdatePitch(node);
                    }
                    if (lbl_805DE500 != NULL && node->pstreamLink == NULL) {
                        lbl_805DE500(node->sfxID);
                    }
                }
                continue;
            }
        }
        it = &node->volUpdateNext;
    }
    OSRestoreInterrupts(enabled);
}

void HSD_SynthSFXUpdateVolume(HSD_SynthSFXNode* node)
{
    u32 enabled = OSDisableInterrupts();
    if (!node->volUpdatePending && !(node->flags & 8)) {
        node->volUpdatePending = 1;
        node->volUpdateNext = lbl_805DE504;
        lbl_805DE504 = node;
    }
    OSRestoreInterrupts(enabled);
}

static inline void updateMixEnvelopeStep(u16* target, u16* current, s16* out)
{
    s16 delta = (s16) ((*target - *current) / 160);
    if (delta > 0x14) {
        delta = 0x14;
    } else if (delta < -0x14) {
        delta = -0x14;
    }
    out[1] = delta;
    if (delta != 0) {
        out[0] = *current;
        *current = (u16) (*current + delta * 0xA0);
    } else {
        out[0] = *target;
        *current = *target;
    }
}

void HSD_SynthSFXMixEnvelope(void)
{
    u32 enabled = OSDisableInterrupts();
    HSD_SynthSFXNode** it = &lbl_805DE508;

    while (*it != NULL) {
        HSD_SynthSFXNode* node = *it;
        s32 anyActive = 0;
        s32 voice;

        for (voice = 0; voice <= (node->rearIndex == -1 ? 0 : 1); voice++) {
            HSD_SynthSFXNode* base = voice == 0 ? node : &lbl_80597660[node->rearIndex];
            u16 sp8[4 * 9];
            u16* target = (u16*) &base->mix.vL;
            u16* current = (u16*) &base->mix.vL + 0x18;
            s32 i;
            s32 changed = 0;

            for (i = 0; i < 9; i++) {
                s16 out[2];
                updateMixEnvelopeStep(&target[i * 2], &current[i * 2], out);
                sp8[i * 4] = out[0];
                sp8[i * 4 + 1] = out[1];
                if (out[1] != 0) {
                    changed = 1;
                }
            }
            hwSetVolume(sp8, 0, 0, 0);

            if (voice == 1 && base->voice_count == 1 && changed == 0) {
                node->volUpdatePending = 1;
                node->volUpdateNext = lbl_805DE504;
                lbl_805DE504 = node;
                anyActive = 1;
            }
            anyActive |= changed;
        }
        if (!anyActive) {
            *it = node->mixUpdateNext;
            node->mixUpdatePending = 0;
        } else {
            it = &node->mixUpdateNext;
        }
    }
    OSRestoreInterrupts(enabled);
}

void HSD_SynthSFXMixShort(HSD_SynthSFXNode* node, s32 unused)
{
    HSD_SynthSFXNode** it = &lbl_805DE508;

    while (*it != NULL) {
        if (*it == node) {
            u16 sp[9 * 2];
            s32 voice;

            for (voice = 0; voice <= (node->rearIndex == -1 ? 0 : 1); voice++) {
                HSD_SynthSFXNode* base = voice == 0 ? node : &lbl_80597660[node->rearIndex];
                u16* mixVals = (u16*) &base->mix.vL;
                s32 i;
                for (i = 0; i < 9; i++) {
                    sp[i * 2] = mixVals[i * 2];
                    sp[i * 2 + 1] = 0;
                }
                hwSetVolume(sp, 0, 0, 0);
            }
            *it = node->mixUpdateNext;
            node->mixUpdatePending = 0;
            return;
        }
        it = &(*it)->mixUpdateNext;
    }
}

void HSD_SynthSFXInitMix(HSD_SynthSFXNode* node)
{
    s32 i;

    for (i = 0; i <= (node->rearIndex == -1 ? 0 : 1); i++) {
        HSD_SynthSFXNode* base = i == 0 ? node : &lbl_80597660[node->rearIndex];
        u16* mix = (u16*) &base->mix;
        s32 j;
        for (j = 0; j < 18; j++) {
            mix[j] = 0;
        }
        if (i != 0) {
            u32* uv = (u32*) &base->user_vol[0];
            s32 k;
            for (k = 0; k < 10; k++) {
                uv[k] = 0;
            }
        }
    }
}

void HSD_SynthSFXUpdateMix(HSD_SynthSFXNode* node, s32 interpolate)
{
    /* KAR extended mix engine (mono/stereo/quad/surround pan curves + rear
       channel) - equal-power pan table lookups omitted; residual pan/mix
       state is approximated. */
    f32 l = 23169.768f;
    f32 r = 23169.768f;

    if (node->voice_count == 1) {
        node->mix.vL = (u16) (l * node->mixMain);
        node->mix.vR = (u16) (r * node->mixMain);
        node->mix.vAuxAL = (u16) (l * node->mixAuxA);
        node->mix.vAuxAR = (u16) (r * node->mixAuxA);
        node->mix.vAuxBL = (u16) (l * node->mixAuxB);
        node->mix.vAuxBR = (u16) (r * node->mixAuxB);
    } else {
        l /= 2;
        node->mix.vL = (u16) (l * node->mixMain);
        node->mix.vR = (u16) (l * node->mixMain);
        node->mix.vAuxAL = (u16) (l * node->mixAuxA);
        node->mix.vAuxAR = (u16) (l * node->mixAuxA);
        node->mix.vAuxBL = (u16) (l * node->mixAuxB);
        node->mix.vAuxBR = (u16) (l * node->mixAuxB);
    }

    if (interpolate == 0) {
        HSD_SynthSFXMixShort(node, 0);
    } else {
        u32 enabled = OSDisableInterrupts();
        if (!node->mixUpdatePending && !(node->flags & 8)) {
            node->mixUpdatePending = 1;
            node->mixUpdateNext = lbl_805DE508;
            lbl_805DE508 = node;
        }
        OSRestoreInterrupts(enabled);
    }
}

void HSD_SynthSFXUpdateAllVolume(s32 vol, u16 fadeFrames, s32 channel,
                                  s32 dbMode)
{
    HSD_SynthVolFader* f;
    s32 frames;
    s32 changed = 0;
    u32 enabled;

    if (channel < 0 || channel >= 0x40) {
        return;
    }
    f = &lbl_8059A178[channel];
    enabled = OSDisableInterrupts();
    frames = fadeFrames < 1 ? 1 : fadeFrames;
    if (dbMode == 0) {
        f32 target = (f32) (0.00392156862745098 * (f64) vol);
        if (f->volume != target) {
            f->duration = frames;
            changed = 1;
        }
        f->target.f = target;
    } else {
        s32 dbx;
        s32 raw;
        f32 v;
        if (f->volume < 0.000030199517f) {
            dbx = lbl_805DD178;
        } else if (f->volume == 1.0f) {
            dbx = 0;
        } else {
            dbx = (s32) (5692384.633202305 * kar_axdriver__near_803bd428());
            if (dbx < lbl_805DD178) {
                dbx = lbl_805DD178;
            }
        }
        f->dbxRaw = dbx;
        raw = vol << 0x10;
        f->target.i = raw;
        if (raw <= lbl_805DD178) {
            v = 0.0f;
        } else if (raw >= 0) {
            v = 1.0f;
        } else {
            v = (f32) kar_axdriver__803bd3e8(1.75673301162265e-07 * (f64) raw,
                                              1.75673301162265e-07);
        }
        if (f->volume != v) {
            changed = 1;
            f->duration = frames;
        }
    }
    f->mode = dbMode;
    if (changed) {
        s32 i;
        u32 enabled2;
        lbl_805DD18C[channel / 32] |= 1 << (channel & 0x1F);
        enabled2 = OSDisableInterrupts();
        for (i = 0; i < HSD_SYNTHSFXNODE_MAX; i++) {
            HSD_SynthSFXNode* node = &lbl_80597660[i];
            if (node->sfxID > 0 && node->channel == channel) {
                HSD_SynthSFXUpdateVolume(node);
            }
        }
        OSRestoreInterrupts(enabled2);
    }
    OSRestoreInterrupts(enabled);
}

void HSD_SynthSFXSetMasterVolume(s32 vol, u16 fadeFrames, s32 dbMode)
{
    s32 frames;
    s32 changed = 0;
    u32 enabled = OSDisableInterrupts();

    frames = fadeFrames == 0 ? 1 : fadeFrames;
    if (dbMode == 0) {
        f32 target = (f32) (0.00392156862745098 * (f64) vol);
        lbl_8059A160.target.f = target;
        if (lbl_8059A160.volume != target) {
            lbl_8059A160.duration = frames;
            changed = 1;
        }
    } else {
        s32 dbx;
        s32 raw;
        f32 v;
        if (lbl_8059A160.volume < 0.000030199517f) {
            dbx = lbl_805DD178;
        } else if (lbl_8059A160.volume == 1.0f) {
            dbx = 0;
        } else {
            dbx = (s32) (5692384.633202305 * kar_axdriver__near_803bd428());
            if (dbx < lbl_805DD178) {
                dbx = lbl_805DD178;
            }
        }
        raw = vol << 0x10;
        lbl_8059A160.target.i = raw;
        if (raw <= lbl_805DD178) {
            v = 0.0f;
        } else if (raw >= 0) {
            v = 1.0f;
        } else {
            v = (f32) kar_axdriver__803bd3e8(1.75673301162265e-07 * (f64) raw,
                                              1.75673301162265e-07);
        }
        if (lbl_8059A160.volume != v) {
            lbl_8059A160.duration = frames;
            changed = 1;
        }
    }
    lbl_8059A160.mode = dbMode;
    if (changed) {
        s32 i;
        u32 enabled2 = OSDisableInterrupts();
        for (i = 0; i < HSD_SYNTHSFXNODE_MAX; i++) {
            HSD_SynthSFXNode* node = &lbl_80597660[i];
            if (node->sfxID > 0) {
                HSD_SynthSFXUpdateVolume(node);
            }
        }
        OSRestoreInterrupts(enabled2);
    }
    OSRestoreInterrupts(enabled);
}

void HSD_SynthSFXSetDriverInactivatedCallback(void (*callback)(s32))
{
    lbl_805DE4F8 = callback;
}

void HSD_SynthSFXSetDriverMasterClockCallback(void (*callback)(u32))
{
    lbl_805DE4FC = callback;
}

void HSD_SynthSFXSetDriverPauseCallback(void (*callback)(s32))
{
    lbl_805DE500 = callback;
}

void HSD_SynthCallback(void)
{
    s32 i;
    u32 enabled;
    s32 base;

    base = HSD_Synth_804D775C % 8 * 8;

    enabled = OSDisableInterrupts();

    while (lbl_805DE4E0-- > 0) {
        if (lbl_8059A060[lbl_805DE4E0] != 0) {
            AXFreeVoice(lbl_8059A060[lbl_805DE4E0]);
        }
    }
    lbl_805DE4E0 = 0;

    for (i = 0; i < 8; i++) {
        HSD_SynthSFXNode* node = &lbl_80597660[base + i];
        if (node->sfxID > 0) {
            if (!(node->flags & 8) && AXVPB_PB_STATE(node->voice[0]) == 0 &&
                (node->voice_count == 1 || AXVPB_PB_STATE(node->voice[1]) == 0))
            {
                HSD_SynthSFXFreeVoice(node);
            }
        }
    }

    HSD_SynthSFXVolFaderProc();

    if (lbl_805DE4FC != NULL) {
        lbl_805DE4FC(HSD_Synth_804D775C);
    }

    HSD_SynthSFXMixEnvelope();
    HSD_Synth_804D775C++;
    OSRestoreInterrupts(enabled);
}

void HSD_SynthPStreamHakoDataCallback(s32 pstreamID)
{
    HSD_SynthSFXNode* node = getNode(pstreamID);
    HSD_SynthPStreamEntry* pst;

    if (node == NULL) {
        return;
    }
    pst = node->pstreamLink;
    if (pst != NULL) {
        s32 buf = pst->bufTableHeadIx;
        HSD_SynthSFXNode** hit = (HSD_SynthSFXNode**) &lbl_80597220[pst->bufIdx].unk20;
        while (*hit != NULL) {
            hit = (HSD_SynthSFXNode**) &(*hit)->next;
        }
        *hit = (HSD_SynthSFXNode*) (u32) buf;
        lbl_80597220[buf].unk1C = (u8) 0;
        pst->bufTableHeadIx += 1;
        kar_dvdsche_set_stream_scheduler_slot_key(pst->schedulerSlot, pst->bufTableHeadIx);
        if (lbl_80597220[pst->entrynum].unk0 == (u32) -1) {
            kar_dvdsche_free_stream_scheduler_slot(pst->schedulerSlot);
            pst->schedulerSlot = -1;
        }
        pst->bufIdx = -1;
    }
}

void HSD_SynthPStreamLinkBeatMarker(s32 pstreamID, void* markerData, s32 count)
{
    HSD_SynthSFXNode* node = getNode(pstreamID);
    HSD_SynthPStreamEntry* pst;

    if (node == NULL) {
        return;
    }
    pst = node->pstreamLink;
    if (pst != NULL) {
        /* KAR's block-memory-buffer ("bmb"/"bmbnext") allocator is not
           reproduced here; beat markers are dropped. */
        (void) markerData;
        (void) count;
        lbl_80597220[pst->bufIdx].unk1C = 0;
    }
}

void HSD_SynthPStreamHakoExtHeaderCallback(s32 pstreamID, void* header)
{
    HSD_SynthSFXNode* node = getNode(pstreamID);
    HSD_SynthPStreamEntry* pst;

    if (node == NULL) {
        return;
    }
    pst = node->pstreamLink;
    if (pst != NULL) {
        s32 buf = pst->bufIdx;
        u8 nBeats = lbl_80597220[pst->bufTableHeadIx].unk1C;
        s32 base = lbl_80597220[buf].unk0;

        if (nBeats > 0) {
            HSD_DevComRequest(pst->entrynum, base + 0x20, NULL,
                               ((nBeats * 8) + 0x1F) & ~0x1F, 0x22, 0,
                               (void (*)(s32, void*, s32, s32))
                                   HSD_SynthPStreamLinkBeatMarker,
                               (void*) (u32) pstreamID);
        }
        HSD_DevComRequest(pst->entrynum,
                           base + (((nBeats * 8) + 0x1F) & ~0x1F) + 0x20,
                           (void*) (lbl_805DE534 + (pst->bufTableHeadIx << 0x10)),
                           lbl_80597220[buf].unk0, 0x23, 0,
                           (void (*)(s32, void*, s32, s32))
                               HSD_SynthPStreamHakoDataCallback,
                           (void*) (u32) pstreamID);
    }
}

void HSD_SynthPStreamHakoHeaderCallback(s32 pstreamID)
{
    HSD_SynthSFXNode* node;
    HSD_SynthPStreamEntry* pst;
    u32 enabled = OSDisableInterrupts();

    node = getNode(pstreamID);
    if (node != NULL) {
        pst = node->pstreamLink;
        if (pst != NULL) {
            s32 base;
            s32 i;
            s32 freeBuf = -1;

            for (i = 0; i < lbl_805DE53C; i++) {
                if (lbl_80597220[i].unk0 == (u32) -1 && i != lbl_805DE528) {
                    lbl_805DE528 = i;
                }
            }
            base = lbl_80597220[lbl_805DE528].unk0;
            if (base == -1) {
                ASSERT_SYNTH_MSG(0xD4C, 0, lbl_805DD174);
            }
            pst->bufTableHeadIx = lbl_805DE528;
            HSD_DevComRequest(pst->entrynum, base, &lbl_80597220[lbl_805DE528], 0x20,
                               0x21, 0,
                               (void (*)(s32, void*, s32, s32))
                                   HSD_SynthPStreamHakoExtHeaderCallback,
                               (void*) (u32) pstreamID);
        }
    }
    OSRestoreInterrupts(enabled);
}

void HSD_SynthPStreamMasterClockCallback(void)
{
    /* KAR's per-frame pstream double-buffer scheduler. Not fully
       reproduced; this is a structurally partial best-effort port. */
    HSD_SynthPStreamEntry* pst = lbl_805DE524;

    while (pst != NULL) {
        HSD_SynthSFXNode* node = pst->node;
        if (!(node->flags & 8)) {
            u32 pos = AXVPB_CURRENT_ADDR(node->voice[0]);
            u32 base = lbl_805DE534 * 2;
            if (pos >= base) {
                u32 idx = (pos - base) >> 0x11;
                (void) idx;
            }
        }
        pst = pst->next;
    }
}

void HSD_SynthPStreamFirstHakoDataCallback(s32 pstreamID, void* addr)
{
    /* KAR's first-buffer streaming continuation. Not fully reproduced
       (double-buffer swap / next-buffer scheduling logic); intentionally
       left as a partial best-effort port. */
    HSD_SynthSFXNode* node = getNode(pstreamID);
    HSD_SynthPStreamEntry* pst;

    (void) addr;
    if (node == NULL) {
        return;
    }
    pst = node->pstreamLink;
    if (pst != NULL) {
        pst->bufIdx = -1;
    }
}

void HSD_SynthPStreamFirstHakoExtHeaderCallback(s32 pstreamID, void* header)
{
    HSD_SynthSFXNode* node = getNode(pstreamID);
    HSD_SynthPStreamEntry* pst;

    (void) header;
    if (node == NULL) {
        return;
    }
    pst = node->pstreamLink;
    if (pst != NULL) {
        s32 buf = pst->bufTableHeadIx;
        u8 nBeats = lbl_80597220[buf].unk1C;
        s32 base = lbl_80597220[buf].unk0;

        if (nBeats > 0) {
            HSD_DevComRequest(pst->entrynum, 0xA0, NULL,
                               ((nBeats * 8) + 0x1F) & ~0x1F, 0x22, 0,
                               (void (*)(s32, void*, s32, s32))
                                   HSD_SynthPStreamFirstHakoExtHeaderCallback,
                               (void*) (u32) pstreamID);
        }
        HSD_DevComRequest(pst->entrynum,
                           (((nBeats * 8) + 0x1F) & ~0x1F) + 0xA0,
                           (void*) (lbl_805DE534 + (buf << 0x10)), base, 0x23,
                           0,
                           (void (*)(s32, void*, s32, s32))
                               HSD_SynthPStreamFirstHakoDataCallback,
                           (void*) (u32) pstreamID);
    }
}

void HSD_SynthPStreamFirstHakoHeaderCallback(s32 pstreamID)
{
    HSD_SynthSFXNode* node = getNode(pstreamID);
    HSD_SynthPStreamEntry* pst;

    if (node == NULL) {
        return;
    }
    pst = node->pstreamLink;
    if (pst != NULL) {
        s32 buf = pst->bufTableHeadIx;
        u8 nBeats = lbl_80597220[buf].unk1C;

        if (nBeats > 0) {
            HSD_DevComRequest(pst->entrynum, 0xA0, NULL,
                               ((nBeats * 8) + 0x1F) & ~0x1F, 0x22, 0,
                               (void (*)(s32, void*, s32, s32))
                                   HSD_SynthPStreamFirstHakoExtHeaderCallback,
                               (void*) (u32) pstreamID);
        }
        HSD_DevComRequest(pst->entrynum,
                           (((nBeats * 8) + 0x1F) & ~0x1F) + 0xA0,
                           (void*) (lbl_805DE534 + (buf << 0x10)),
                           lbl_80597220[buf].unk0, 0x23, 0,
                           (void (*)(s32, void*, s32, s32))
                               HSD_SynthPStreamFirstHakoDataCallback,
                           (void*) (u32) pstreamID);
    }
}

void HSD_SynthPStreamHeaderCallback(s32 pstreamID, void* header)
{
    HSD_SynthSFXNode* node = getNode(pstreamID);

    if (node != NULL) {
        u32* entry = header;
        s32 i;

        node->voice_count = (u8) entry[3];
        if (node->voice_count == 2) {
            node->voice[1] = AXAcquireVoice(0x1D, dropcallback, 0);
            ASSERT_SYNTH_MSG(0xE3D, node->voice[1], "entry->voice[1]");
        }
        node->freqBase = 0.00003125f * (f32) entry[2];
        for (i = 0; i < node->voice_count; i++) {
            lbl_8050932C.ratioHi = (u16) (65536.0f * node->freqBase);
            fn_803EECCC(node->voice[i], &entry[i * 14 + 4]);
            fn_803EEF24(node->voice[i], &entry[i * 14 + 8]);
        }
        node->pstreamLink->bufTableHeadIx =
            (node->pstreamLink->bufTableHeadIx + 2) % 3;
        HSD_DevComRequest(node->pstreamLink->entrynum, 0x80,
                           &lbl_80597220[node->pstreamLink->bufTableHeadIx], 0x20,
                           0x21, 0,
                           (void (*)(s32, void*, s32, s32))
                               HSD_SynthPStreamFirstHakoHeaderCallback,
                           NULL);
    }
}

void HSD_SynthPStreamStartCallback(s32 pstreamID)
{
    HSD_SynthSFXNode* node = getNode(pstreamID);

    ASSERT_SYNTH_MSG(0xE6B, node != NULL, "entry");
    HSD_DevComRequest(node->pstreamLink->entrynum, 0, NULL, 0x80, 0x22, 0,
                       (void (*)(s32, void*, s32, s32))
                           HSD_SynthPStreamHeaderCallback,
                       (void*) (u32) pstreamID);
}

s32 HSD_SynthPStreamStart(s32 entrynum, s16 vol, s32 volMode, s16 vol2,
                           s32 vol2Mode, u8 priority, u8 itd, u8 channel,
                           f32 pitch1, f32 pitch2, f32 mixMain, f32 mixAuxA,
                           f32 mixAuxB, s32 unused, s32 useRear, s32 unused2)
{
    HSD_SynthSFXNode* node;
    HSD_SynthPStreamEntry* pst;
    AXVPB* voice;
    u32 index;
    u32 enabled;

    if (entrynum < 0) {
        return 0;
    }
    if (channel < 0 || channel >= 0x40) {
        return 0;
    }
    enabled = OSDisableInterrupts();
    if (lbl_805DE538 != 4) {
        useRear = 0;
    }
    voice = AXAcquireVoice(0x1F, dropcallback, 0);
    index = voice->index;
    node = &lbl_80597660[index];

    pst = lbl_805DE520;
    if (pst != NULL) {
        lbl_805DE520 = pst->next;
    }
    node->pstreamLink = pst;
    pst->entrynum = entrynum;
    pst->node = node;
    pst->bufIdx = -2;
    pst->unk20 = 0;
    pst->unk24 = 0;
    pst->next = lbl_805DE524;
    lbl_805DE524 = pst;

    lbl_805DE510 += 0x40;
    if (lbl_805DE510 < 0) {
        lbl_805DE510 = 0x40;
    }
    node->sfxID = lbl_805DE510 + index;
    node->unk8 = 0;
    node->flags = 8;
    node->voice_count = 1;
    node->channel = channel;
    node->voice[0] = voice;
    node->rearIndex = -1;
    node->pitch[0] = pitch1;
    node->pitch[1] = pitch2;

    if (volMode == 0) {
        node->user_vol[0].volume = 0.003921569f * (f32) vol;
        node->user_vol[0].target.f = node->user_vol[0].volume;
    } else {
        s32 raw = vol << 0x10;
        f32 v;
        if (raw <= lbl_805DD178) {
            v = 0.0f;
        } else if (raw >= 0) {
            v = 1.0f;
        } else {
            v = (f32) kar_axdriver__803bd3e8(1.75673301162265e-07 * (f64) raw,
                                              1.75673301162265e-07);
        }
        node->user_vol[0].volume = v;
        node->user_vol[0].target.i = raw;
    }
    node->user_vol[0].mode = volMode;

    if (vol2Mode == 0) {
        node->user_vol[1].volume = 0.003921569f * (f32) vol2;
        node->user_vol[1].target.f = node->user_vol[1].volume;
    } else {
        s32 raw = vol2 << 0x10;
        f32 v;
        if (raw <= lbl_805DD178) {
            v = 0.0f;
        } else if (raw >= 0) {
            v = 1.0f;
        } else {
            v = (f32) kar_axdriver__803bd3e8(1.75673301162265e-07 * (f64) raw,
                                              1.75673301162265e-07);
        }
        node->user_vol[1].volume = v;
        node->user_vol[1].target.i = raw;
    }
    node->user_vol[1].mode = vol2Mode;
    node->vol1Clamp = priority;
    node->vol2Clamp = itd;
    node->pan = channel;
    node->unk67 = (s8) unused;
    node->mixMain = mixAuxA;
    node->mixAuxA = mixAuxB;
    node->mixAuxB = 0.0f;

    if (useRear != 0) {
        AXVPB* rearVoice = AXAcquireVoice(0x1F, dropcallback, 0);
        u32 rearIdx = rearVoice->index;
        HSD_SynthSFXNode* rearNode = &lbl_80597660[rearIdx];
        rearNode->sfxID = -2;
        rearNode->rearIndex = (s16) index;
        node->rearIndex = (s16) rearIdx;
        rearNode->voice_count = 1;
        rearNode->voice[0] = rearVoice;
    } else {
        node->rearIndex = -1;
    }
    pst->schedulerSlot = kar_dvdsche_alloc_stream_scheduler_slot(
        (void (*)(s32, void*)) HSD_SynthPStreamStartCallback, node->sfxID);
    OSRestoreInterrupts(enabled);
    return node->sfxID;
}

void HSD_SynthStreamPause(void)
{
    AISetStreamPlayState(0);
}

void HSD_SynthStreamResume(void)
{
    AISetStreamPlayState(1);
}

void HSD_SynthStreamSetVolume(f32 volume)
{
    s32 i;
    u32 enabled;

    lbl_805DD194 = volume;
    AISetStreamVolLeft(volume * (f32) lbl_805DE530);
    AISetStreamVolRight(lbl_805DD194 * (f32) lbl_805DE530);
    enabled = OSDisableInterrupts();
    for (i = 0; i < HSD_SYNTHSFXNODE_MAX; i++) {
        HSD_SynthSFXNode* node = &lbl_80597660[i];
        if (node->sfxID > 0) {
            HSD_SynthSFXUpdateVolume(node);
        }
    }
    OSRestoreInterrupts(enabled);
}

void HSD_SynthInit(s32 heapSize, s32 pstNum, s32 pstBufNum)
{
    s32 i;

    AXInitEx(0, 0);
    ASSERT_SYNTH_REPORT(0xF72, pstNum >= 1 && pstNum <= HSD_SYNTHPSTREAM_MAX,
                         "HSD_AudioInit*: pstNum out of range.\n");
    ASSERT_SYNTH_REPORT(0xF73, pstBufNum >= 1 && pstBufNum <= 3,
                         "HSD_AudioInit*: pstBufNum out of range.\n");
    kar_dvdsche_configure_stream_scheduler(pstNum, pstBufNum);
    lbl_805DE53C = pstNum * (pstBufNum + 1) + 1;
    AISetDSPSampleRate(0, pstNum * (pstBufNum + 1));
    lbl_805DE540 = ARAlloc(0x500);
    HSD_DevComRequest(0, 0, lbl_805DE540, 0x500, 3, 0, NULL, 0);
    lbl_805DE540 = (void*) ((s32) lbl_805DE540 * 2);
    hsd_SynthSFXBankHead[0] = (s32) ARAlloc(heapSize);
    fn_803ED76C(HSD_SynthCallback, HSD_SynthCallback);
    lbl_805DE530 = 0xFF;
    AISetStreamVolLeft(lbl_805DD194 * (f32) lbl_805DE530);
    AISetStreamVolRight(lbl_805DD194 * (f32) lbl_805DE530);

    lbl_8059A160.volume = 1.0f;
    lbl_8059A160.target.f = 1.0f;
    lbl_8059A160.duration = 0;
    for (i = 0; i < 0x40; i++) {
        lbl_8059A178[i].volume = 1.0f;
        lbl_8059A178[i].target.f = 1.0f;
        lbl_8059A178[i].duration = 0;
    }

    lbl_805DE54C = (void*) (hsd_SynthSFXBankHead[0] + heapSize);
    lbl_805DE534 = (s32) ARAlloc(lbl_805DE53C << 0x10);
    lbl_805DE538 = OSGetSoundMode();

    for (i = 0; i < 0xFF; i++) {
        f32 x = 0.003937008f * (f32) i;
        f32 result;
        if (x > 0.0f) {
            f32 y0 = __frsqrte(x);
            f32 y1 = 0.5f * y0 * (3.0f - x * y0 * y0);
            f32 y2 = 0.5f * y1 * (3.0f - x * y1 * y1);
            f32 y3 = 0.5f * y2 * (3.0f - x * y2 * y2);
            f32 y4 = 0.5f * y3 * (3.0f - x * y3 * y3);
            result = x * y4;
        } else {
            result = 0.0f;
        }
        lbl_80599C60[i] = result;
    }
    lbl_80599C60[0xFF] = lbl_80599C60[0xFE];

    lbl_805DE520 = NULL;
    for (i = pstNum - 1; i >= 0; i--) {
        lbl_8059A178_pstpool[i].next = lbl_805DE520;
        lbl_805DE520 = &lbl_8059A178_pstpool[i];
    }

    for (i = 0; i < lbl_805DE53C; i++) {
        lbl_80597220[i % 0x11].unk0 = (u32) -1;
    }
}

void HSD_SObjLib_803A44A4(void)
{
    HSD_ObjAllocInit(&lbl_8059A818, 0x9C, 4);
}

void HSD_SObjLib_803A4740(void* sobjArg)
{
    struct kar_sobj {
        void* x0;
        struct kar_sobj* next;
        struct kar_sobj* prev;
        void* gobj;
    }* sobj = sobjArg;
    struct kar_sobj* next;

    while (sobj != NULL) {
        next = sobj->next;
        if (sobj->prev != NULL || sobj->next != NULL) {
            if (sobj->prev != NULL) {
                sobj->prev->next = sobj->next;
            } else {
                HSD_GObjObjectUnlink(sobj->gobj);
                HSD_GObjObjectLink(sobj->gobj, lbl_805DE550, sobj->next);
                sobj->next->prev = NULL;
            }
            if (sobj->next != NULL) {
                sobj->next->prev = sobj->prev;
            } else {
                sobj->prev->next = NULL;
            }
            sobj->next = NULL;
            sobj->prev = NULL;
        } else if (*(void**) ((u8*) sobj->gobj + 0x28) == sobj) {
            HSD_GObjObjectUnlink(sobj->gobj);
        }
        HSD_ObjFree(&lbl_8059A818, sobj);
        sobj = next;
    }
}
