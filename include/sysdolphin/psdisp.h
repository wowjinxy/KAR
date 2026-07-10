#ifndef _psdisp_h_
#define _psdisp_h_

#include <dolphin/types.h>
#include <dolphin/mtx/mtxtypes.h>

#include <sysdolphin/forward.h>

typedef struct HSD_psAppSRT {
    struct HSD_psAppSRT* next;
    HSD_Generator* gp;
    Vec translate;
    Vec rot;
    u32 unk20;
    Vec scale;
    Vec unk30;
    u8 status;
    u8 unk3d;
    u16 usedCount;
    u8 unk40[0x38];
    void (*freefunc)(struct HSD_psAppSRT* srt);
    u16 idnum;
    u8 unk7e;
    u8 unk7f;
} HSD_psAppSRT;

struct HSD_Generator {
    u8 pad00[0x1c];
    u16 idnum;
    u8 pad1e[0x54 - 0x1e];
    HSD_psAppSRT* appsrt;
};

struct HSD_Particle {
    u8 pad00[0x90];
    HSD_psAppSRT* appsrt;
};

s32 kar_psdisp__near_80437bf0(s32 num, s32 size);
void kar_psdisp__near_80437c90(void);
void kar_psdisp__near_80437cd8(HSD_Generator* gp, s32 status);
s32 kar_psdisp__near_80437ddc(HSD_Particle* pp, HSD_psAppSRT* srt);
s32 kar_psdisp__near_80437e18(HSD_Generator* gp, HSD_psAppSRT* srt);
s32 kar_psdisp__near_80437e54(HSD_Particle* pp, HSD_psAppSRT* srt);
s32 kar_psdisp__near_80437ec0(HSD_Generator* gp, HSD_psAppSRT* srt);
s32 psRemoveParticleAppSRT(HSD_Particle* pp);
s32 kar_psdisp__near_80437fcc(HSD_Generator* gp);
s32 kar_psdisp__near_80438084(s32 num);
void kar_psdisp__near_80438190(void);
void* kar_psdisp__near_80438238(void** dst, u32 bank);

#endif
