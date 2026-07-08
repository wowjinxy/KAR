#ifndef _particle_h_
#define _particle_h_

#include <dolphin/types.h>
#include <dolphin/gx/gxtypes.h>
#include <dolphin/mtx/mtxtypes.h>

#include <sysdolphin/forward.h>
#include <sysdolphin/jobj.h>

/* size: 0xA0 */
struct HSD_Particle {
    HSD_Particle* next;                     // 0x00
    u32 kind;                               // 0x04
    u8 bank;                                // 0x08
    u8 texGroup;                            // 0x09
    u8 poseNum;                             // 0x0A
    u8 palNum;                              // 0x0B
    u16 sizeCount;                          // 0x0C
    u16 primColCount;                       // 0x0E
    u16 envColCount;                        // 0x10
    GXColor primCol;                        // 0x12
    GXColor envCol;                         // 0x16
    u16 cmdWait;                            // 0x1A
    u8 loopCount;                           // 0x1C
    u8 linkNo;                              // 0x1D
    u16 idnum;                              // 0x1E
    u8* cmdList;                            // 0x20
    u16 cmdPtr;                             // 0x24
    u16 cmdMarkPtr;                         // 0x26
    u16 cmdLoopPtr;                         // 0x28
    u16 life;                               // 0x2A
    Vec vel;                                // 0x2C
    f32 grav;                               // 0x38
    f32 fric;                               // 0x3C
    Vec pos;                                // 0x40
    f32 size;                               // 0x4C
    f32 rotate;                             // 0x50
    u16 aCmpCount;                          // 0x54
    u8 aCmpMode;                            // 0x56
    u8 aCmpParam1;                          // 0x57
    u8 aCmpParam2;                          // 0x58
    u8 pJObjOfs;                            // 0x59
    u16 matColCount;                        // 0x5A
    u16 ambColCount;                        // 0x5C
    u16 rotateCount;                        // 0x5E
    f32 sizeTarget;                         // 0x60
    f32 rotateTarget;                       // 0x64
    f32 spreadRate;                         // 0x68
    u16 primColRemain;                      // 0x6C
    u16 envColRemain;                       // 0x6E
    GXColor primColTarget;                  // 0x70
    GXColor envColTarget;                   // 0x74
    u16 matColRemain;                       // 0x78
    u16 ambColRemain;                       // 0x7A
    u16 aCmpRemain;                         // 0x7C
    u8 aCmpParam1Target;                    // 0x7E
    u8 aCmpParam2Target;                    // 0x7F
    u8 matRGB;                              // 0x80
    u8 matA;                                // 0x81
    u8 ambRGB;                              // 0x82
    u8 ambA;                                // 0x83
    u8 matRGBTarget;                        // 0x84
    u8 matATarget;                          // 0x85
    u8 ambRGBTarget;                        // 0x86
    u8 ambATarget;                          // 0x87
    f32 trail;                              // 0x88
    HSD_Generator* gen;                     // 0x8C
    HSD_psAppSRT* appsrt;                   // 0x90
    f32* userdata;                          // 0x94
    int (*callback)(HSD_Particle* part);    // 0x98
    u16 pauseCount;                         // 0x9C
    u16 pad9E;                              // 0x9E
};

struct HSD_psAppSRT {
    HSD_psAppSRT* next;   // 0x00
    HSD_Generator* gp;    // 0x04
    Vec translate;        // 0x08
    Quaternion rot;       // 0x14
    Vec scale;            // 0x24
    u8 status;            // 0x30
    u8 frameNum;          // 0x31
    u16 usedCount;        // 0x32
    Mtx mmtx;             // 0x34
    f32 ssx;              // 0x64
    f32 ssy;              // 0x68
    f32 x6C;              // 0x6C
    f32 x70;              // 0x70
    f32 x74;              // 0x74
    f32 x78;              // 0x78
    f32 x7C;              // 0x7C
    f32 x80;              // 0x80
    f32 x84;              // 0x84
    f32 x88;              // 0x88
    f32 x8C;              // 0x8C
    f32 x90;              // 0x90
    f32 x94;              // 0x94
    void (*freefunc)(HSD_psAppSRT* appsrt); // 0x9C
    u16 idnum;                              // 0xA0
    s8 xA2;                                 // 0xA2
};

/* size: 0xC */
typedef struct HSD_PSUserFunc {
    int (*hookCreate)(HSD_Particle* part);
    int (*hookDelete)(HSD_Particle* part);
    int (*setUserData)(HSD_Particle* part, u8 unk1, f32 unk2);
} HSD_PSUserFunc;

typedef struct _auxDisc {
    f32 minAngle;
    f32 maxAngle;
} auxDisc;

typedef struct _auxLine {
    f32 x2;
    f32 y2;
    f32 z2;
} auxLine;

typedef struct _auxTornado {
    f32 vel;
} auxTornado;

typedef struct _auxRect {
    f32 x;
    f32 y;
    f32 z;
    f32 xx;
    f32 xy;
    f32 xz;
    f32 yx;
    f32 yy;
    f32 yz;
    f32 zx;
    f32 zy;
    f32 zz;
    u16 flag;
} auxRect;

typedef struct _auxCone {
    f32 minAngle;
    f32 maxAngle;
    f32 height;
} auxCone;

typedef struct _auxSphere {
    f32 speed;
    f32 latMid;
    f32 latRange;
    f32 lonMid;
    f32 lonRange;
} auxSphere;

/* size: 0x88 */
struct HSD_Generator {
    HSD_Generator* next;               // 0x00
    u32 kind;                          // 0x04
    f32 random;                        // 0x08
    f32 count;                         // 0x0C
    HSD_JObj* jobj;                    // 0x10
    u16 genLife;                       // 0x14
    u16 type;                          // 0x16
    u8 bank;                           // 0x18
    u8 linkNo;                         // 0x19
    u8 texGroup;                       // 0x1A
    u8 dummy;                          // 0x1B
    u16 idnum;                         // 0x1C
    u16 life;                          // 0x1E
    u8* cmdList;                       // 0x20
    Vec pos;                           // 0x24
    Vec vel;                           // 0x30
    f32 grav;                          // 0x3C
    f32 fric;                          // 0x40
    f32 size;                          // 0x44
    f32 radius;                        // 0x48
    f32 angle;                         // 0x4C
    u32 numChild;                      // 0x50
    HSD_psAppSRT* appsrt;              // 0x54
    HSD_PSUserFunc* userfunc;          // 0x58
    int (*callback)(HSD_Generator* gen); // 0x5C
    union {
        auxDisc disc;
        auxLine line;
        auxTornado tornado;
        auxRect rect;
        auxCone cone;
        auxSphere sphere;
    } aux;                              // 0x60
};

/* size: 0x1C */
typedef struct HSD_PSTexGroup {
    u32 num;
    u32 fmt;
    u32 tlutfmt;
    u32 width;
    u32 height;
    u16 palnum;
    u16 palflag;
    u8* texTable[1];
} HSD_PSTexGroup;

/* size: 0x8 */
typedef struct HSD_PSFormGroup {
    u32 num;
    u8* formTable[1];
} HSD_PSFormGroup;

/* size: 0x40 */
typedef struct HSD_PSCmdList {
    u16 type;
    u16 texGroup;
    u16 genLife;
    u16 life;
    u32 kind;
    f32 grav;
    f32 fric;
    f32 vx;
    f32 vy;
    f32 vz;
    f32 radius;
    f32 angle;
    f32 random;
    f32 size;
    f32 param1;
    f32 param2;
    f32 param3;
    u8 cmdList[1];
} HSD_PSCmdList;

HSD_Particle* psGenerateParticle0(HSD_Particle** head, int linkNo, int bank,
                                   u32 kind, u16 texGroup, u8* list, int life,
                                   int palflag, f32 x, f32 y, f32 z, f32 vx,
                                   f32 vy, f32 vz, f32 size, f32 grav, f32 fric,
                                   HSD_Generator* gp, int flgInterpret);
HSD_Particle* psGenerateParticleID0(HSD_Particle** head, int linkNo, int bank,
                                    int id, int flgInterpret);
HSD_Particle* psGenerateParticle(int linkNo, int bank, u32 kind, u16 texGroup,
                                  u8* list, int life, f32 x, f32 y, f32 z,
                                  f32 vx, f32 vy, f32 vz, f32 size, f32 grav,
                                  f32 fric, int palflag, HSD_Generator* gp);
void psKillParticle(void);
void psDeletePntJObjwithParticle(HSD_Particle* pp);
void psKillGeneratorChild(HSD_Generator* gp);
void psInterpretParticle0(HSD_Particle* pp, int startCmdPtr);

#endif
