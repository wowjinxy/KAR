#ifndef _dvdsche_h_
#define _dvdsche_h_

#include <global.h>
#include <dolphin/types.h>
#include <sysdolphin/objalloc.h>

typedef struct _AXPBMIX {
    u16 vL;
    u16 vDeltaL;
    u16 vR;
    u16 vDeltaR;
    u16 vAuxAL;
    u16 vDeltaAuxAL;
    u16 vAuxAR;
    u16 vDeltaAuxAR;
    u16 vAuxBL;
    u16 vDeltaAuxBL;
    u16 vAuxBR;
    u16 vDeltaAuxBR;
    u16 vAuxBS;
    u16 vDeltaAuxBS;
    u16 vS;
    u16 vDeltaS;
    u16 vAuxAS;
    u16 vDeltaAuxAS;
} AXPBMIX;

typedef struct _AXPBVE {
    u16 currentVolume;
    u16 currentDelta;
} AXPBVE;

typedef struct _AXPBADDR {
    u16 loopFlag;
    u16 format;
    u32 loopAddressHi;
    u32 loopAddressLo;
    u32 endAddressHi;
    u32 endAddressLo;
    u32 currentAddressHi;
    u32 currentAddressLo;
} AXPBADDR;

typedef struct _AXPBADPCM {
    s16 coefs[16];
    u16 gain;
    u16 pred_scale;
    u16 yn1;
    u16 yn2;
} AXPBADPCM;

typedef struct _AXPBADPCMLOOP {
    u16 loop_pred_scale;
    u16 loop_yn1;
    u16 loop_yn2;
} AXPBADPCMLOOP;

typedef struct _AXPBSRC {
    u16 ratioHi;
    u16 ratioLo;
    u16 currentAddressFrac;
    u16 pad[4];
} AXPBSRC;

typedef struct _AXVPB {
    struct _AXVPB* next;
    struct _AXVPB* prev;
    void* next1;
    u32 priority;
    void* callback;
    u32 userContext;
    u32 index;
    u32 sync;
    /* remaining PB fields not accessed directly by this unit */
    u8 pad20[0x1D6 - 0x20];
} AXVPB;

#define AXVPB_PB_STATE(v) (*(u16*) ((u8*) (v) + 0x146))
#define AXVPB_CURRENT_ADDR(v) (*(u32*) ((u8*) (v) + 0x1B2))
#define AXVPB_ITD_FLAG(v) (*(u16*) ((u8*) (v) + 0x166))
#define AXVPB_ITD_SHIFTL(v) (*(u16*) ((u8*) (v) + 0x16C))
#define AXVPB_ITD_SHIFTR(v) (*(u16*) ((u8*) (v) + 0x16E))
#define AXVPB_ITD_TARGETSHIFTL(v) (*(u16*) ((u8*) (v) + 0x170))
#define AXVPB_ITD_TARGETSHIFTR(v) (*(u16*) ((u8*) (v) + 0x172))

struct HSD_SynthPStreamEntry;

typedef struct HSD_SynthSFXNode {
    /* 0x00 */ s32 sfxID;
    /* 0x04 */ struct HSD_SynthSFXNode* next;
    /* 0x08 */ u8 unk8;
    /* 0x09 */ u8 flags;
    /* 0x0A */ u8 voice_count;
    /* 0x0B */ u8 channel;
    /* 0x0C */ AXVPB* voice[2];
    /* 0x14 */ s16 rearIndex;
    /* 0x16 */ s8 unk16;
    /* 0x17 */ s8 unk17;
    /* 0x18 */ f32 freqBase;
    /* 0x1C */ f32 pitch[2];
    /* 0x24 */ struct HSD_SynthSFXNode* volUpdateNext;
    /* 0x28 */ struct HSD_SynthSFXNode* mixUpdateNext;
    /* 0x2C */ u8 pad2C[2];
    /* 0x2E */ u8 volUpdatePending;
    /* 0x2F */ u8 mixUpdatePending;
    /* 0x30 */ struct HSD_SynthPStreamEntry* pstreamLink;
    struct {
        /* +0x00 */ f32 volume;
        /* +0x04 */ s32 mode;
        /* +0x08 */ union {
            f32 f;
            s32 i;
        } target;
        /* +0x0C */ s32 dbxRaw;
        /* +0x10 */ s32 fadeCount;
        /* +0x14 */ u8 pad[4];
    } user_vol[2]; /* 0x34-0x64 */
    /* 0x64 */ u8 vol1Clamp;
    /* 0x65 */ u8 vol2Clamp;
    /* 0x66 */ u8 pan;
    /* 0x67 */ u8 unk67;
    /* 0x68 */ f32 mixMain;
    /* 0x6C */ f32 mixAuxA;
    /* 0x70 */ f32 mixAuxB;
    /* 0x74 */ AXPBMIX mix;
} HSD_SynthSFXNode; /* size = 0x98 */

typedef struct HSD_SynthBankRange {
    /* 0x00 */ s32 base;
    /* 0x04 */ s32 top;
} HSD_SynthBankRange;

typedef struct HSD_SynthPStreamEntry {
    /* 0x00 */ struct HSD_SynthPStreamEntry* next; /* free-list link */
    /* 0x04 */ struct HSD_SynthSFXNode* node;       /* owning node back-ref */
    /* 0x08 */ s32 entrynum;
    /* 0x0C */ s32 schedulerSlot;
    /* 0x10 */ s16 bufIdx;
    /* 0x12 */ u8 pad12[10];
    /* 0x1C */ s32 bufTableHeadIx;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
} HSD_SynthPStreamEntry;

extern void* OSAllocFromHeap(u32 heap, u32 size);
extern void OSFreeToHeap(u32 heap, void* ptr);
extern u32 OSDisableInterrupts(void);
extern u32 OSRestoreInterrupts(u32 level);
extern void OSReport(const char*, ...);
extern void OSPanic(const char*, s32, const char*, ...);
extern u32 OSGetSoundMode(void);
extern void OSSetSoundMode(u32 mode);
#define OSRoundUp32B(x) (((u32) (x) + 32 - 1) & ~(32 - 1))
extern void* memcpy(void*, const void*, u32);
extern f64 sin(f64);

extern void AISetDSPSampleRate(s32 unk, s32 rate);
extern void AISetStreamPlayState(s32);
extern void AISetStreamVolLeft(f32);
extern void AISetStreamVolRight(f32);
extern void* ARAlloc(s32);
extern void AXFreeVoice(AXVPB*);
extern AXVPB* AXAcquireVoice(u32 priority, void* callback, u32 userContext);
extern u64 AXInitEx(void*, s8*);
extern void AXRegisterCallback(void (*)(void));

extern void fn_803ED0CC(s32);
extern void fn_803ED76C(void (*)(void), void (*)(void));
extern void fn_803EE7F4(AXVPB*, s32);
extern void fn_803EEB68(AXVPB*);
extern void fn_803EEBCC(u16, u16);
extern void fn_803EEC28(AXVPB*, s16*);
extern void fn_803EEC80(AXVPB*, s16);
extern void fn_803EECCC(AXVPB*, void*);
extern void fn_803EEDDC(AXVPB*, u32);
extern void fn_803EEE28(AXVPB*, void*, s32);
extern void fn_803EEE7C(AXVPB*, s32, s32, s32);
extern void fn_803EEED0(AXVPB*, s32, s32);
extern void fn_803EEF24(AXVPB*, void*);
extern void fn_803EEFC8(AXVPB*, u32*);
extern void fn_803EF0F8(AXVPB*, void*);
extern void hwSetPitch(f32);
extern void hwSetVolume(u16*, s32, s32, u16);
extern f64 kar_axdriver__803bd3e8(f64, f64);
extern void kar_axdriver__803ec47c(AXVPB*, s32);
extern void kar_axdriver__803ee8b8(AXVPB*, s32);
extern f64 kar_axdriver__near_803bd428(void);

extern s32 HSD_DevComRequest(s32 entrynum, s32 offset, void* dst, u32 length,
                              s32 priority, s32 sync,
                              void (*callback)(s32, void*, s32, s32),
                              void* userdata);

extern void* HSD_GObjObjectLink(void* gobj, u8 kind, void* obj);
extern void* HSD_GObjObjectUnlink(void* gobj);

s32 kar_dvdsche_alloc_stream_scheduler_slot(void (*callback)(s32, void*),
                                             s32 param);
void kar_dvdsche_free_stream_scheduler_slot(s32 id);
void kar_dvdsche_set_stream_scheduler_slot_key(s32 id, s32 key);
void kar_dvdsche_set_stream_scheduler_slot_callback(s32 id,
                                                     void (*callback)(s32,
                                                                       void*));
void kar_dvdsche_dispatch_stream_scheduler_callbacks(void);

#endif
