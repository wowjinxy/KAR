#ifndef _psdisp_h_
#define _psdisp_h_

#include <dolphin/types.h>
#include <dolphin/gx/gxtypes.h>
#include <dolphin/mtx/mtxtypes.h>

#include <sysdolphin/forward.h>
#include <sysdolphin/jobj.h>

typedef struct HSD_psAppSRT {
    struct HSD_psAppSRT* next;   // 0x00
    HSD_Generator* gp;           // 0x04
    Vec translate;                // 0x08
    Vec rot;                      // 0x14
    u32 unk20;                    // 0x20
    Vec scale;                    // 0x24
    Vec unk30;                    // 0x30
    u8 status;                    // 0x3C
    u8 frameNum;                  // 0x3D
    u16 usedCount;                // 0x3E
    Mtx mmtx;                     // 0x40
    f32 ssx;                      // 0x70
    f32 ssy;                      // 0x74
    void (*freefunc)(struct HSD_psAppSRT* srt); // 0x78
    u16 idnum;                    // 0x7C
    u8 xA2;                       // 0x7E
} HSD_psAppSRT;

struct HSD_Generator {
    HSD_Generator* next;   // 0x00
    u32 kind;              // 0x04
    f32 random;            // 0x08
    f32 count;             // 0x0C
    HSD_JObj* jobj;        // 0x10
    u16 genLife;           // 0x14
    u16 type;              // 0x16
    u8 bank;               // 0x18
    u8 linkNo;             // 0x19
    u8 texGroup;           // 0x1A
    u8 dummy;              // 0x1B
    u16 idnum;             // 0x1C
    u16 life;              // 0x1E
    u8* cmdList;           // 0x20
    Vec pos;               // 0x24
    Vec vel;               // 0x30
    f32 grav;              // 0x3C
    f32 fric;              // 0x40
    f32 size;              // 0x44
    f32 radius;            // 0x48
    f32 angle;             // 0x4C
    u32 numChild;          // 0x50
    HSD_psAppSRT* appsrt;  // 0x54
    void* userfunc;        // 0x58
    int (*callback)(HSD_Generator* gen); // 0x5C
    u8 aux[0x88 - 0x60];   // 0x60
};

struct HSD_Particle {
    HSD_Particle* next;      // 0x00
    u32 kind;                // 0x04
    u8 bank;                 // 0x08
    u8 texGroup;              // 0x09
    u8 poseNum;               // 0x0A
    u8 palNum;                // 0x0B
    u16 sizeCount;            // 0x0C
    u16 primColCount;         // 0x0E
    u16 envColCount;          // 0x10
    GXColor primCol;          // 0x12
    GXColor envCol;           // 0x16
    u16 cmdWait;              // 0x1A
    u8 loopCount;             // 0x1C
    u8 linkNo;                // 0x1D
    u16 idnum;                // 0x1E
    u8* cmdList;              // 0x20
    u16 cmdPtr;               // 0x24
    u16 cmdMarkPtr;           // 0x26
    u16 cmdLoopPtr;           // 0x28
    u16 life;                 // 0x2A
    Vec vel;                  // 0x2C
    f32 grav;                 // 0x38
    f32 fric;                 // 0x3C
    Vec pos;                  // 0x40
    f32 size;                 // 0x4C
    f32 rotate;               // 0x50
    u16 aCmpCount;            // 0x54
    u8 aCmpMode;              // 0x56
    u8 aCmpParam1;            // 0x57
    u8 aCmpParam2;            // 0x58
    u8 pJObjOfs;              // 0x59
    u16 matColCount;          // 0x5A
    u16 ambColCount;          // 0x5C
    u16 rotateCount;          // 0x5E
    f32 sizeTarget;           // 0x60
    f32 rotateTarget;         // 0x64
    f32 spreadRate;           // 0x68
    u16 primColRemain;        // 0x6C
    u16 envColRemain;         // 0x6E
    GXColor primColTarget;    // 0x70
    GXColor envColTarget;     // 0x74
    u16 matColRemain;         // 0x78
    u16 ambColRemain;         // 0x7A
    u16 aCmpRemain;           // 0x7C
    u8 aCmpParam1Target;      // 0x7E
    u8 aCmpParam2Target;      // 0x7F
    u8 matRGB;                // 0x80
    u8 matA;                  // 0x81
    u8 ambRGB;                // 0x82
    u8 ambA;                  // 0x83
    u8 matRGBTarget;          // 0x84
    u8 matATarget;            // 0x85
    u8 ambRGBTarget;          // 0x86
    u8 ambATarget;            // 0x87
    f32 trail;                // 0x88
    HSD_Generator* gen;       // 0x8C
    HSD_psAppSRT* appsrt;     // 0x90
    f32* userdata;            // 0x94
    int (*callback)(HSD_Particle* part); // 0x98
    u16 pauseCount;           // 0x9C
    u16 pad9E;                // 0x9E
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
