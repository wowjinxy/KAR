#include "dolphin/types.h"

extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL level);
extern void* memset(void* dst, int val, size_t n);

extern void* OSAllocFromHeap(int heap, u32 size);
extern void OSFreeToHeap(int heap, void* ptr);

extern s32 lbl_805DC978;
extern void* (*lbl_805DCA28)(u32);
extern void (*lbl_805DCA2C)(void*);

typedef struct AXFX_REVSTD_DELAYLINE
{
    s32 inPoint;
    s32 outPoint;
    s32 length;
    f32* inputs;
    f32 lastOutput;
} AXFX_REVSTD_DELAYLINE;

typedef struct AXFX_REVSTD_WORK
{
    AXFX_REVSTD_DELAYLINE AP[6];
    AXFX_REVSTD_DELAYLINE C[6];
    f32 allPassCoeff;
    f32 combCoef[6];
    f32 lpLastout[3];
    f32 level;
    f32 damping;
    s32 preDelayTime;
    f32* preDelayLine[3];
    f32* preDelayPtr[3];
} AXFX_REVSTD_WORK;

typedef struct AXFX_REVERBSTD
{
    AXFX_REVSTD_WORK rv;
    u8 tempDisableFX;
    f32 coloration;
    f32 mix;
    f32 time;
    f32 damping;
    f32 preDelay;
} AXFX_REVERBSTD;

typedef struct AXFX_BUFFERUPDATE
{
    s32* left;
    s32* right;
    s32* surround;
} AXFX_BUFFERUPDATE;

typedef struct AXFX_CHORUS_SRCINFO
{
    s32* dest;
    s32* smpBase;
    s32* old;
    u32 posLo;
    u32 posHi;
    u32 pitchLo;
    u32 pitchHi;
    u32 trigger;
    u32 target;
} AXFX_CHORUS_SRCINFO;

typedef struct AXFX_CHORUS_WORK
{
    s32* lastLeft[3];
    s32* lastRight[3];
    s32* lastSur[3];
    u8 currentLast;
    s32 oldLeft[4];
    s32 oldRight[4];
    s32 oldSur[4];
    u32 currentPosLo;
    u32 currentPosHi;
    s32 pitchOffset;
    u32 pitchOffsetPeriodCount;
    u32 pitchOffsetPeriod;
    AXFX_CHORUS_SRCINFO src;
} AXFX_CHORUS_WORK;

typedef struct AXFX_CHORUS
{
    AXFX_CHORUS_WORK work;
    u32 baseDelay;
    u32 variation;
    u32 period;
} AXFX_CHORUS;

typedef struct AXFX_DELAY
{
    u32 currentSize[3];
    u32 currentPos[3];
    u32 currentFeedback[3];
    u32 currentOutput[3];
    s32* left;
    s32* right;
    s32* sur;
    u32 delay[3];
    u32 feedback[3];
    u32 output[3];
} AXFX_DELAY;

extern int ReverbSTDCreate(AXFX_REVSTD_WORK* rv, f32 coloration, f32 time, f32 mix, f32 damping, f32 predelay);

const f32 value0_3 = 0.3f;
const f32 value0_6 = 0.6f;
const double i2fMagicRvstd = 4503601774854144.0;

asm void ReverbSTD_HandleReverb(register s32* sptr, register AXFX_REVSTD_WORK* rv)
{
    nofralloc
    stwu r1, -0x90(r1)
    stmw r17, 0x8(r1)
    stfd f14, 0x58(r1)
    stfd f15, 0x60(r1)
    stfd f16, 0x68(r1)
    stfd f17, 0x70(r1)
    stfd f18, 0x78(r1)
    stfd f19, 0x80(r1)
    stfd f20, 0x88(r1)
    lis r31, value0_3@ha
    lfs f6, value0_3@l(r31)
    lis r31, value0_6@ha
    lfs f9, value0_6@l(r31)
    lis r31, i2fMagicRvstd@ha
    lfd f5, i2fMagicRvstd@l(r31)
    lfs f2, AXFX_REVSTD_WORK.allPassCoeff(rv)
    lfs f11, AXFX_REVSTD_WORK.damping(rv)
    lfs f8, AXFX_REVSTD_WORK.level(rv)
    fmuls f3, f8, f9
    fsubs f4, f9, f3
    lis r30, 0x4330
    stw r30, 0x50(r1)
    li r5, 0
L_803F0458:
    slwi r31, r5, 3
    add r31, r31, rv
    lfs f19, AXFX_REVSTD_WORK.combCoef[0](r31)
    lfs f20, AXFX_REVSTD_WORK.combCoef[1](r31)
    slwi r31, r5, 2
    add r31, r31, rv
    lfs f7, AXFX_REVSTD_WORK.lpLastout[0](r31)
    lwz r27, AXFX_REVSTD_WORK.preDelayLine[0](r31)
    lwz r28, AXFX_REVSTD_WORK.preDelayPtr[0](r31)
    lwz r31, AXFX_REVSTD_WORK.preDelayTime(rv)
    subi r22, r31, 1
    slwi r22, r22, 2
    add r22, r22, r27
    cmpwi cr7, r31, 0
    mulli r31, r5, 0x28
    addi r29, rv, AXFX_REVSTD_WORK.C
    add r29, r29, r31
    addi r30, rv, AXFX_REVSTD_WORK.AP
    add r30, r30, r31
    lwz r21, AXFX_REVSTD_DELAYLINE.inPoint + 0x00(r29)
    lwz r20, AXFX_REVSTD_DELAYLINE.outPoint + 0x00(r29)
    lwz r19, AXFX_REVSTD_DELAYLINE.inPoint + 0x14(r29)
    lwz r18, AXFX_REVSTD_DELAYLINE.outPoint + 0x14(r29)
    lfs f15, AXFX_REVSTD_DELAYLINE.lastOutput + 0x00(r29)
    lfs f16, AXFX_REVSTD_DELAYLINE.lastOutput + 0x14(r29)
    lwz r26, AXFX_REVSTD_DELAYLINE.length + 0x00(r29)
    lwz r25, AXFX_REVSTD_DELAYLINE.length + 0x14(r29)
    lwz r7, AXFX_REVSTD_DELAYLINE.inputs + 0x00(r29)
    lwz r8, AXFX_REVSTD_DELAYLINE.inputs + 0x14(r29)
    lwz r12, AXFX_REVSTD_DELAYLINE.inPoint + 0x00(r30)
    lwz r11, AXFX_REVSTD_DELAYLINE.outPoint + 0x00(r30)
    lwz r10, AXFX_REVSTD_DELAYLINE.inPoint + 0x14(r30)
    lwz r9, AXFX_REVSTD_DELAYLINE.outPoint + 0x14(r30)
    lfs f17, AXFX_REVSTD_DELAYLINE.lastOutput + 0x00(r30)
    lfs f18, AXFX_REVSTD_DELAYLINE.lastOutput + 0x14(r30)
    lwz r24, AXFX_REVSTD_DELAYLINE.length + 0x00(r30)
    lwz r23, AXFX_REVSTD_DELAYLINE.length + 0x14(r30)
    lwz r17, AXFX_REVSTD_DELAYLINE.inputs + 0x00(r30)
    lwz r6, AXFX_REVSTD_DELAYLINE.inputs + 0x14(r30)
    lwz r30, 0(sptr)
    xoris r30, r30, 0x8000
    stw r30, 0x54(r1)
    lfd f12, 0x50(r1)
    fsubs f12, f12, f5
    li r31, 159
    mtctr r31
L_803F0510:
    fmr f13, f12
    beq cr7, L_803F0530
    lfs f13, 0(r28)
    addi r28, r28, 4
    cmpw r28, r22
    stfs f12, -4(r28)
    bne+ L_803F0530
    mr r28, r27
L_803F0530:
    fmadds f8, f19, f15, f13
    lwzu r29, 4(sptr)
    fmadds f9, f20, f16, f13
    stfsx f8, r7, r21
    addi r21, r21, 4
    stfsx f9, r8, r19
    lfsx f14, r7, r20
    addi r20, r20, 4
    lfsx f16, r8, r18
    cmpw r21, r26
    cmpw cr1, r20, r26
    addi r19, r19, 4
    addi r18, r18, 4
    fmr f15, f14
    cmpw cr5, r19, r25
    fadds f14, f14, f16
    cmpw cr6, r18, r25
    bne+ L_803F057C
    li r21, 0
L_803F057C:
    xoris r29, r29, 0x8000
    fmadds f9, f2, f17, f14
    bne+ cr1, L_803F058C
    li r20, 0
L_803F058C:
    stw r29, 0x54(r1)
    bne+ cr5, L_803F0598
    li r19, 0
L_803F0598:
    stfsx f9, r17, r12
    fnmsubs f14, f2, f9, f17
    addi r12, r12, 4
    bne+ cr6, L_803F05AC
    li r18, 0
L_803F05AC:
    lfsx f17, r17, r11
    cmpw cr5, r12, r24
    addi r11, r11, 4
    cmpw cr6, r11, r24
    bne+ cr5, L_803F05C4
    li r12, 0
L_803F05C4:
    bne+ cr6, L_803F05CC
    li r11, 0
L_803F05CC:
    fmuls f14, f14, f6
    lfd f10, 0x50(r1)
    fmadds f14, f11, f7, f14
    fmadds f9, f2, f18, f14
    fmr f7, f14
    stfsx f9, r6, r10
    fnmsubs f14, f2, f9, f18
    fmuls f8, f4, f12
    lfsx f18, r6, r9
    addi r10, r10, 4
    addi r9, r9, 4
    fmadds f14, f3, f14, f8
    cmpw cr5, r10, r23
    cmpw cr6, r9, r23
    fctiwz f14, f14
    bne+ cr5, L_803F0610
    li r10, 0
L_803F0610:
    bne+ cr6, L_803F0618
    li r9, 0
L_803F0618:
    li r31, -4
    fsubs f12, f10, f5
    stfiwx f14, r3, r31
    bdnz L_803F0510
    fmr f13, f12
    beq cr7, L_803F0648
    lfs f13, 0(r28)
    addi r28, r28, 4
    cmpw r28, r22
    stfs f12, -4(r28)
    bne+ L_803F0648
    mr r28, r27
L_803F0648:
    fmadds f8, f19, f15, f13
    fmadds f9, f20, f16, f13
    stfsx f8, r7, r21
    addi r21, r21, 4
    stfsx f9, r8, r19
    lfsx f14, r7, r20
    addi r20, r20, 4
    lfsx f16, r8, r18
    cmpw r21, r26
    cmpw cr1, r20, r26
    addi r19, r19, 4
    addi r18, r18, 4
    fmr f15, f14
    cmpw cr5, r19, r25
    fadds f14, f14, f16
    cmpw cr6, r18, r25
    bne+ L_803F0690
    li r21, 0
L_803F0690:
    fmadds f9, f2, f17, f14
    bne+ cr1, L_803F069C
    li r20, 0
L_803F069C:
    bne+ cr5, L_803F06A4
    li r19, 0
L_803F06A4:
    stfsx f9, r17, r12
    fnmsubs f14, f2, f9, f17
    addi r12, r12, 4
    bne+ cr6, L_803F06B8
    li r18, 0
L_803F06B8:
    lfsx f17, r17, r11
    cmpw cr5, r12, r24
    addi r11, r11, 4
    cmpw cr6, r11, r24
    bne+ cr5, L_803F06D0
    li r12, 0
L_803F06D0:
    bne+ cr6, L_803F06D8
    li r11, 0
L_803F06D8:
    fmuls f14, f14, f6
    fmadds f14, f11, f7, f14
    mulli r31, r5, 0x28
    fmadds f9, f2, f18, f14
    fmr f7, f14
    addi r29, rv, AXFX_REVSTD_WORK.C
    add r29, r29, r31
    stfsx f9, r6, r10
    fnmsubs f14, f2, f9, f18
    fmuls f8, f4, f12
    lfsx f18, r6, r9
    addi r10, r10, 4
    addi r9, r9, 4
    fmadds f14, f3, f14, f8
    cmpw cr5, r10, r23
    cmpw cr6, r9, r23
    fctiwz f14, f14
    bne+ cr5, L_803F0724
    li r10, 0
L_803F0724:
    bne+ cr6, L_803F072C
    li r9, 0
L_803F072C:
    addi r30, rv, AXFX_REVSTD_WORK.AP
    add r30, r30, r31
    stfiwx f14, r0, sptr
    stw r21, AXFX_REVSTD_DELAYLINE.inPoint + 0x00(r29)
    stw r20, AXFX_REVSTD_DELAYLINE.outPoint + 0x00(r29)
    stw r19, AXFX_REVSTD_DELAYLINE.inPoint + 0x14(r29)
    stw r18, AXFX_REVSTD_DELAYLINE.outPoint + 0x14(r29)
    addi sptr, sptr, 4
    stfs f15, AXFX_REVSTD_DELAYLINE.lastOutput + 0x00(r29)
    stfs f16, AXFX_REVSTD_DELAYLINE.lastOutput + 0x14(r29)
    slwi r31, r5, 2
    add r31, r31, rv
    addi r5, r5, 1
    stw r12, AXFX_REVSTD_DELAYLINE.inPoint + 0x00(r30)
    stw r11, AXFX_REVSTD_DELAYLINE.outPoint + 0x00(r30)
    stw r10, AXFX_REVSTD_DELAYLINE.inPoint + 0x14(r30)
    stw r9, AXFX_REVSTD_DELAYLINE.outPoint + 0x14(r30)
    cmpwi r5, 3
    stfs f17, AXFX_REVSTD_DELAYLINE.lastOutput + 0x00(r30)
    stfs f18, AXFX_REVSTD_DELAYLINE.lastOutput + 0x14(r30)
    stfs f7, AXFX_REVSTD_WORK.lpLastout(r31)
    stw r28, AXFX_REVSTD_WORK.preDelayPtr(r31)
    bne L_803F0458
    lfd f14, 0x58(r1)
    lfd f15, 0x60(r1)
    lfd f16, 0x68(r1)
    lfd f17, 0x70(r1)
    lfd f18, 0x78(r1)
    lfd f19, 0x80(r1)
    lfd f20, 0x88(r1)
    lmw r17, 0x8(r1)
    addi r1, r1, 0x90
    blr
}

void ReverbSTDFree(AXFX_REVSTD_WORK* rv)
{
    u8 i;

    for (i = 0; i < 6; i++) {
        lbl_805DCA2C(rv->AP[i].inputs);
    }

    for (i = 0; i < 6; i++) {
        lbl_805DCA2C(rv->C[i].inputs);
    }

    if (rv->preDelayTime) {
        for (i = 0; i < 3; i++) {
            lbl_805DCA2C(rv->preDelayLine[i]);
        }
    }
}

int sndAuxCallbackPrepareReverbSTD(AXFX_REVERBSTD* rev)
{
    int ret;
    BOOL old;

    old = OSDisableInterrupts();
    rev->tempDisableFX = 0;
    ret = ReverbSTDCreate(&rev->rv, rev->coloration, rev->time, rev->mix, rev->damping, rev->preDelay);
    OSRestoreInterrupts(old);
    return ret;
}

int sndAuxCallbackShutdownReverbSTD(AXFX_REVERBSTD* rev)
{
    BOOL old;

    old = OSDisableInterrupts();
    ReverbSTDFree(&rev->rv);
    OSRestoreInterrupts(old);
    return 1;
}

void sndAuxCallbackReverbSTD(AXFX_BUFFERUPDATE* bufferUpdate, AXFX_REVERBSTD* reverb)
{
    if (reverb->tempDisableFX == 0) {
        ReverbSTD_HandleReverb(bufferUpdate->left, &reverb->rv);
    }
}

f32 rsmpTab12khz[512] = {
    0.097503662109f, 0.802215576172f, 0.101593017578f, -0.000976562500f, 0.093505859375f,
    0.802032470703f, 0.105804443359f, -0.001037597656f, 0.089599609375f, 0.801696777344f,
    0.110107421875f, -0.001159667969f, 0.085784912109f, 0.801177978516f, 0.114471435547f,
    -0.001281738281f, 0.082031250000f, 0.800476074219f, 0.118927001953f, -0.001403808594f,
    0.078369140625f, 0.799621582031f, 0.123474121094f, -0.001525878906f, 0.074798583984f,
    0.798614501953f, 0.128143310547f, -0.001647949219f, 0.071350097656f, 0.797424316406f,
    0.132873535156f, -0.001770019531f, 0.067962646484f, 0.796051025391f, 0.137695312500f,
    -0.001922607422f, 0.064697265625f, 0.794525146484f, 0.142608642578f, -0.002044677734f,
    0.061492919922f, 0.792846679688f, 0.147613525391f, -0.002197265625f, 0.058349609375f,
    0.790985107422f, 0.152709960938f, -0.002319335938f, 0.055328369141f, 0.788940429688f,
    0.157897949219f, -0.002471923828f, 0.052368164062f, 0.786743164062f, 0.163177490234f,
    -0.002655029297f, 0.049499511719f, 0.784423828125f, 0.168518066406f, -0.002807617188f,
    0.046722412109f, 0.781890869141f, 0.173980712891f, -0.002990722656f, 0.044006347656f,
    0.779205322266f, 0.179504394531f, -0.003143310547f, 0.041412353516f, 0.776367187500f,
    0.185119628906f, -0.003326416016f, 0.038879394531f, 0.773376464844f, 0.190826416016f,
    -0.003509521484f, 0.036407470703f, 0.770233154297f, 0.196594238281f, -0.003692626953f,
    0.034027099609f, 0.766937255859f, 0.202484130859f, -0.003875732422f, 0.031738281250f,
    0.763488769531f, 0.208435058594f, -0.004058837891f, 0.029510498047f, 0.759857177734f,
    0.214447021484f, -0.004272460938f, 0.027374267578f, 0.756103515625f, 0.220550537109f,
    -0.004455566406f, 0.025299072266f, 0.752197265625f, 0.226745605469f, -0.004669189453f,
    0.023315429688f, 0.748168945312f, 0.233001708984f, -0.004852294922f, 0.021392822266f,
    0.743988037109f, 0.239318847656f, -0.005065917969f, 0.019561767578f, 0.739654541016f,
    0.245727539062f, -0.005310058594f, 0.017791748047f, 0.735198974609f, 0.252197265625f,
    -0.005523681641f, 0.016052246094f, 0.730590820312f, 0.258728027344f, -0.005706787109f,
    0.014404296875f, 0.725860595703f, 0.265350341797f, -0.005920410156f, 0.012817382812f,
    0.721008300781f, 0.272033691406f, -0.006164550781f, 0.011322021484f, 0.716003417969f,
    0.278778076172f, -0.006378173828f, 0.009887695312f, 0.710906982422f, 0.285583496094f,
    -0.006561279297f, 0.008514404297f, 0.705657958984f, 0.292449951172f, -0.006774902344f,
    0.007202148438f, 0.700317382812f, 0.299346923828f, -0.007019042969f, 0.005920410156f,
    0.694854736328f, 0.306335449219f, -0.007232666016f, 0.004699707031f, 0.689270019531f,
    0.313385009766f, -0.007415771484f, 0.003570556641f, 0.683563232422f, 0.320465087891f,
    -0.007629394531f, 0.002471923828f, 0.677734375000f, 0.327606201172f, -0.007873535156f,
    0.001434326172f, 0.671844482422f, 0.334777832031f, -0.008087158203f, 0.000457763672f,
    0.665832519531f, 0.341979980469f, -0.008270263672f, -0.000488281250f, 0.659729003906f,
    0.349243164062f, -0.008453369141f, -0.001342773438f, 0.653533935547f, 0.356567382812f,
    -0.008636474609f, -0.002166748047f, 0.647216796875f, 0.363891601562f, -0.008850097656f,
    -0.002960205078f, 0.640838623047f, 0.371276855469f, -0.009033203125f, -0.003692626953f,
    0.634338378906f, 0.378692626953f, -0.009216308594f, -0.004364013672f, 0.627777099609f,
    0.386138916016f, -0.009338378906f, -0.004974365234f, 0.621154785156f, 0.393615722656f,
    -0.009490966797f, -0.005584716797f, 0.614440917969f, 0.401092529297f, -0.009643554688f,
    -0.006134033203f, 0.607635498047f, 0.408599853516f, -0.009796142578f, -0.006652832031f,
    0.600769042969f, 0.416107177734f, -0.009918212891f, -0.007141113281f, 0.593841552734f,
    0.423645019531f, -0.010009765625f, -0.007568359375f, 0.586853027344f, 0.431213378906f,
    -0.010131835938f, -0.007965087891f, 0.579772949219f, 0.438751220703f, -0.010223388672f,
    -0.008331298828f, 0.572662353516f, 0.446319580078f, -0.010284423828f, -0.008666992188f,
    0.565521240234f, 0.453887939453f, -0.010345458984f, -0.008972167969f, 0.558319091797f,
    0.461456298828f, -0.010406494141f, -0.009216308594f, 0.551055908203f, 0.469024658203f,
    -0.010406494141f, -0.009460449219f, 0.543731689453f, 0.476593017578f, -0.010406494141f,
    -0.009674072266f, 0.536407470703f, 0.484130859375f, -0.010375976562f, -0.009857177734f,
    0.529022216797f, 0.491668701172f, -0.010375976562f, -0.010009765625f, 0.521606445312f,
    0.499176025391f, -0.010314941406f, -0.010131835938f, 0.514160156250f, 0.506683349609f,
    -0.010253906250f, -0.010253906250f, 0.506683349609f, 0.514160156250f, -0.010131835938f,
    -0.010314941406f, 0.499176025391f, 0.521606445312f, -0.010009765625f, -0.010375976562f,
    0.491668701172f, 0.529022216797f, -0.009857177734f, -0.010375976562f, 0.484130859375f,
    0.536407470703f, -0.009674072266f, -0.010406494141f, 0.476593017578f, 0.543731689453f,
    -0.009460449219f, -0.010406494141f, 0.469024658203f, 0.551055908203f, -0.009216308594f,
    -0.010406494141f, 0.461456298828f, 0.558319091797f, -0.008972167969f, -0.010345458984f,
    0.453887939453f, 0.565521240234f, -0.008666992188f, -0.010284423828f, 0.446319580078f,
    0.572662353516f, -0.008331298828f, -0.010223388672f, 0.438751220703f, 0.579772949219f,
    -0.007965087891f, -0.010131835938f, 0.431213378906f, 0.586853027344f, -0.007568359375f,
    -0.010009765625f, 0.423645019531f, 0.593841552734f, -0.007141113281f, -0.009918212891f,
    0.416107177734f, 0.600769042969f, -0.006652832031f, -0.009796142578f, 0.408599853516f,
    0.607635498047f, -0.006134033203f, -0.009643554688f, 0.401092529297f, 0.614440917969f,
    -0.005584716797f, -0.009490966797f, 0.393615722656f, 0.621154785156f, -0.004974365234f,
    -0.009338378906f, 0.386138916016f, 0.627777099609f, -0.004364013672f, -0.009216308594f,
    0.378692626953f, 0.634338378906f, -0.003692626953f, -0.009033203125f, 0.371276855469f,
    0.640838623047f, -0.002960205078f, -0.008850097656f, 0.363891601562f, 0.647216796875f,
    -0.002166748047f, -0.008636474609f, 0.356567382812f, 0.653533935547f, -0.001342773438f,
    -0.008453369141f, 0.349243164062f, 0.659729003906f, -0.000488281250f, -0.008270263672f,
    0.341979980469f, 0.665832519531f, 0.000457763672f, -0.008087158203f, 0.334777832031f,
    0.671844482422f, 0.001434326172f, -0.007873535156f, 0.327606201172f, 0.677734375000f,
    0.002471923828f, -0.007629394531f, 0.320465087891f, 0.683563232422f, 0.003570556641f,
    -0.007415771484f, 0.313385009766f, 0.689270019531f, 0.004699707031f, -0.007232666016f,
    0.306335449219f, 0.694854736328f, 0.005920410156f, -0.007019042969f, 0.299346923828f,
    0.700317382812f, 0.007202148438f, -0.006774902344f, 0.292449951172f, 0.705657958984f,
    0.008514404297f, -0.006561279297f, 0.285583496094f, 0.710906982422f, 0.009887695312f,
    -0.006378173828f, 0.278778076172f, 0.716003417969f, 0.011322021484f, -0.006164550781f,
    0.272033691406f, 0.721008300781f, 0.012817382812f, -0.005920410156f, 0.265350341797f,
    0.725860595703f, 0.014404296875f, -0.005706787109f, 0.258728027344f, 0.730590820312f,
    0.016052246094f, -0.005523681641f, 0.252197265625f, 0.735198974609f, 0.017791748047f,
    -0.005310058594f, 0.245727539062f, 0.739654541016f, 0.019561767578f, -0.005065917969f,
    0.239318847656f, 0.743988037109f, 0.021392822266f, -0.004852294922f, 0.233001708984f,
    0.748168945312f, 0.023315429688f, -0.004669189453f, 0.226745605469f, 0.752197265625f,
    0.025299072266f, -0.004455566406f, 0.220550537109f, 0.756103515625f, 0.027374267578f,
    -0.004272460938f, 0.214447021484f, 0.759857177734f, 0.029510498047f, -0.004058837891f,
    0.208435058594f, 0.763488769531f, 0.031738281250f, -0.003875732422f, 0.202484130859f,
    0.766937255859f, 0.034027099609f, -0.003692626953f, 0.196594238281f, 0.770233154297f,
    0.036407470703f, -0.003509521484f, 0.190826416016f, 0.773376464844f, 0.038879394531f,
    -0.003326416016f, 0.185119628906f, 0.776367187500f, 0.041412353516f, -0.003143310547f,
    0.179504394531f, 0.779205322266f, 0.044006347656f, -0.002990722656f, 0.173980712891f,
    0.781890869141f, 0.046722412109f, -0.002807617188f, 0.168518066406f, 0.784423828125f,
    0.049499511719f, -0.002655029297f, 0.163177490234f, 0.786743164062f, 0.052368164062f,
    -0.002471923828f, 0.157897949219f, 0.788940429688f, 0.055328369141f, -0.002319335938f,
    0.152709960938f, 0.790985107422f, 0.058349609375f, -0.002197265625f, 0.147613525391f,
    0.792846679688f, 0.061492919922f, -0.002044677734f, 0.142608642578f, 0.794525146484f,
    0.064697265625f, -0.001922607422f, 0.137695312500f, 0.796051025391f, 0.067962646484f,
    -0.001770019531f, 0.132873535156f, 0.797424316406f, 0.071350097656f, -0.001647949219f,
    0.128143310547f, 0.798614501953f, 0.074798583984f, -0.001525878906f, 0.123474121094f,
    0.799621582031f, 0.078369140625f, -0.001403808594f, 0.118927001953f, 0.800476074219f,
    0.082031250000f, -0.001281738281f, 0.114471435547f, 0.801177978516f, 0.085784912109f,
    -0.001159667969f, 0.110107421875f, 0.801696777344f, 0.089599609375f, -0.001037597656f,
    0.105804443359f, 0.802032470703f, 0.093505859375f, -0.000976562500f, 0.101593017578f,
    0.802215576172f, 0.097503662109f,
};

const double i2fMagic = 4503601774854144.0;

asm void do_src1(register AXFX_CHORUS_SRCINFO* src)
{
    nofralloc
    stwu r1, -64(r1)
    stmw r26, 40(r1)
    lwz r4, AXFX_CHORUS_SRCINFO.posLo(src)
    lwz r5, AXFX_CHORUS_SRCINFO.posHi(src)
    lwz r6, AXFX_CHORUS_SRCINFO.pitchLo(src)
    lwz r8, AXFX_CHORUS_SRCINFO.trigger(src)
    lwz r7, AXFX_CHORUS_SRCINFO.target(src)
    lwz r31, AXFX_CHORUS_SRCINFO.smpBase(src)
    lwz r30, AXFX_CHORUS_SRCINFO.dest(src)
    lwz r9, AXFX_CHORUS_SRCINFO.old(src)
    lis r10, 0x4330
    stw r10, 8(r1)
    stw r10, 16(r1)
    stw r10, 24(r1)
    stw r10, 32(r1)
    lis r10, i2fMagic@ha
    lfd f9, i2fMagic@l(r10)
    slwi r10, r5, 2
    lwz r11, 0(r9)
    lwz r29, 4(r9)
    lwz r28, 8(r9)
    lwzx r27, r31, r10
    xoris r11, r11, 0x8000
    xoris r29, r29, 0x8000
    stw r11, 12(r1)
    xoris r28, r28, 0x8000
    stw r29, 20(r1)
    xoris r27, r27, 0x8000
    stw r28, 28(r1)
    lfd f1, 8(r1)
    stw r27, 36(r1)
    lfd f2, 16(r1)
    fsubs f1, f1, f9
    lfd f3, 24(r1)
    fsubs f2, f2, f9
    lfd f4, 32(r1)
    fsubs f3, f3, f9
    fsubs f4, f4, f9
    li r26, -4
    lis r12, rsmpTab12khz@ha
    addi r12, r12, rsmpTab12khz@l
    li r9, 160
    mtctr r9
L_000000AC:
    rlwinm r10, r4, 7, 21, 27
    addc r4, r4, r6
    add r10, r10, r12
    mcrxr cr0
    lfs f5, 0(r10)
    beq L_000000F4
    lfs f6, 4(r10)
    fmuls f10, f1, f5
    lfs f7, 8(r10)
    fmadds f10, f2, f6, f10
    lfs f8, 12(r10)
    fmadds f10, f3, f7, f10
    addi r30, r30, 4
    fmadds f10, f4, f8, f10
    fctiwz f10, f10
    stfiwx f10, r26, r30
    bdnz L_000000AC
    b L_00000160
L_000000F4:
    addi r5, r5, 1
    lfs f6, 4(r10)
    fmuls f10, f1, f5
    cmpw r5, r8
    fmr f1, f2
    lfs f7, 8(r10)
    fmadds f10, f2, f6, f10
    fmr f2, f3
    lfs f8, 12(r10)
    fmadds f10, f3, f7, f10
    addi r30, r30, 4
    fmr f3, f4
    bne+ L_0000012C
    mr r5, r7
L_0000012C:
    fmadds f10, f4, f8, f10
    slwi r9, r5, 2
    bdz L_00000158
    lwzx r10, r9, r31
    fctiwz f10, f10
    xoris r10, r10, 0x8000
    stw r10, 12(r1)
    stfiwx f10, r26, r30
    lfd f4, 8(r1)
    fsubs f4, f4, f9
    b L_000000AC
L_00000158:
    fctiwz f10, f10
    stfiwx f10, r26, r30
L_00000160:
    lwz r9, AXFX_CHORUS_SRCINFO.old(src)
    fctiwz f1, f1
    fctiwz f2, f2
    fctiwz f3, f3
    stfiwx f1, r0, r9
    addi r10, r9, 4
    stfiwx f2, r0, r10
    addi r10, r9, 8
    stfiwx f3, r0, r10
    stw r4, AXFX_CHORUS_SRCINFO.posLo(src)
    stw r5, AXFX_CHORUS_SRCINFO.posHi(src)
    lmw r26, 40(r1)
    addi r1, r1, 64
    blr
}

asm void do_src2(register AXFX_CHORUS_SRCINFO* src)
{
    nofralloc
    stwu r1, -64(r1)
    stmw r26, 40(r1)
    lwz r4, AXFX_CHORUS_SRCINFO.posLo(src)
    lwz r5, AXFX_CHORUS_SRCINFO.posHi(src)
    lwz r6, AXFX_CHORUS_SRCINFO.pitchLo(src)
    lwz r8, AXFX_CHORUS_SRCINFO.trigger(src)
    lwz r7, AXFX_CHORUS_SRCINFO.target(src)
    lwz r31, AXFX_CHORUS_SRCINFO.smpBase(src)
    lwz r30, AXFX_CHORUS_SRCINFO.dest(src)
    lwz r9, AXFX_CHORUS_SRCINFO.old(src)
    lis r10, 0x4330
    stw r10, 8(r1)
    stw r10, 16(r1)
    stw r10, 24(r1)
    stw r10, 32(r1)
    lis r10, i2fMagic@ha
    lfd f9, i2fMagic@l(r10)
    slwi r10, r5, 2
    lwz r11, 0(r9)
    lwz r29, 4(r9)
    lwz r28, 8(r9)
    lwzx r27, r31, r10
    xoris r11, r11, 0x8000
    xoris r29, r29, 0x8000
    stw r11, 12(r1)
    xoris r28, r28, 0x8000
    stw r29, 20(r1)
    xoris r27, r27, 0x8000
    stw r28, 28(r1)
    lfd f1, 8(r1)
    stw r27, 36(r1)
    lfd f2, 16(r1)
    fsubs f1, f1, f9
    lfd f3, 24(r1)
    fsubs f2, f2, f9
    lfd f4, 32(r1)
    fsubs f3, f3, f9
    fsubs f4, f4, f9
    li r26, -4
    lis r12, rsmpTab12khz@ha
    addi r12, r12, rsmpTab12khz@l
    li r9, 160
    mtctr r9
L_00000244:
    rlwinm r10, r4, 7, 21, 27
    addc r4, r4, r6
    add r10, r10, r12
    mcrxr cr0
    addi r5, r5, 1
    lfs f5, 0(r10)
    beq L_000002C0
    lfs f6, 4(r10)
    fmuls f10, f1, f5
    cmpw r5, r8
    fmr f1, f2
    lfs f7, 8(r10)
    fmadds f10, f2, f6, f10
    fmr f2, f3
    lfs f8, 12(r10)
    fmadds f10, f3, f7, f10
    addi r30, r30, 4
    fmr f3, f4
    bne+ L_00000294
    mr r5, r7
L_00000294:
    fmadds f10, f4, f8, f10
    slwi r9, r5, 2
    bdz L_00000344
    lwzx r10, r9, r31
    fctiwz f10, f10
    xoris r10, r10, 0x8000
    stw r10, 12(r1)
    stfiwx f10, r26, r30
    lfd f4, 8(r1)
    fsubs f4, f4, f9
    b L_00000244
L_000002C0:
    cmpw r5, r8
    lfs f6, 4(r10)
    bne+ L_000002D0
    mr r5, r7
L_000002D0:
    slwi r11, r5, 2
    addi r5, r5, 1
    lwzx r29, r11, r31
    fmuls f10, f1, f5
    cmpw r5, r8
    xoris r29, r29, 0x8000
    fmr f1, f3
    lfs f7, 8(r10)
    stw r29, 12(r1)
    fmadds f10, f2, f6, f10
    lfs f8, 12(r10)
    fmadds f10, f3, f7, f10
    lfd f3, 8(r1)
    fmr f2, f4
    addi r30, r30, 4
    fsubs f3, f3, f9
    bne+ L_00000318
    mr r5, r7
L_00000318:
    fmadds f10, f4, f8, f10
    slwi r9, r5, 2
    bdz L_00000344
    lwzx r10, r9, r31
    fctiwz f10, f10
    xoris r10, r10, 0x8000
    stw r10, 12(r1)
    stfiwx f10, r26, r30
    lfd f4, 8(r1)
    fsubs f4, f4, f9
    b L_00000244
L_00000344:
    fctiwz f10, f10
    stfiwx f10, r26, r30
    lwz r9, AXFX_CHORUS_SRCINFO.old(src)
    fctiwz f1, f1
    fctiwz f2, f2
    fctiwz f3, f3
    stfiwx f1, r0, r9
    addi r10, r9, 4
    stfiwx f2, r0, r10
    addi r10, r9, 8
    stfiwx f3, r0, r10
    stw r4, AXFX_CHORUS_SRCINFO.posLo(src)
    stw r5, AXFX_CHORUS_SRCINFO.posHi(src)
    lmw r26, 40(r1)
    addi r1, r1, 64
    blr
}

int sndAuxCallbackPrepareChorus(AXFX_CHORUS* c)
{
    s32* left;
    s32* right;
    s32* sur;
    u32 i;
    BOOL old;

    old = OSDisableInterrupts();
    c->work.lastLeft[0] = lbl_805DCA28(0x1680);
    if (c->work.lastLeft[0] != NULL) {
        c->work.lastRight[0] = (void*)(c->work.lastLeft[0] + 0x1E0);
        c->work.lastSur[0] = (void*)(c->work.lastRight[0] + 0x1E0);

        for (i = 1; i < 3; i++) {
            c->work.lastLeft[i] = (void*)&c->work.lastLeft[0][i * 0xA0];
            c->work.lastRight[i] = (void*)&c->work.lastRight[0][i * 0xA0];
            c->work.lastSur[i] = (void*)&c->work.lastSur[0][i * 0xA0];
        }

        left = c->work.lastLeft[0];
        right = c->work.lastRight[0];
        sur = c->work.lastSur[0];

        for (i = 0; i < 0x140; i++) {
            *left++ = 0;
            *right++ = 0;
            *sur++ = 0;
        }

        c->work.currentLast = 1;
        c->work.oldLeft[0] = c->work.oldLeft[1] = c->work.oldLeft[2] = c->work.oldLeft[3] = 0;
        c->work.oldRight[0] = c->work.oldRight[1] = c->work.oldRight[2] = c->work.oldRight[3] = 0;
        c->work.oldSur[0] = c->work.oldSur[1] = c->work.oldSur[2] = c->work.oldSur[3] = 0;
        c->work.src.trigger = 0x1E0;
        c->work.src.target = 0;
        OSRestoreInterrupts(old);
        return sndAuxCallbackUpdateSettingsChorus(c);
    }

    OSRestoreInterrupts(old);
    return 0;
}

int sndAuxCallbackShutdownChorus(AXFX_CHORUS* c)
{
    BOOL old;

    old = OSDisableInterrupts();
    lbl_805DCA2C(c->work.lastLeft[0]);
    OSRestoreInterrupts(old);
    return 1;
}

int sndAuxCallbackUpdateSettingsChorus(AXFX_CHORUS* c)
{
    BOOL old;

    old = OSDisableInterrupts();
    c->work.currentPosHi = 0x140 - ((c->baseDelay - 5) << 5);
    c->work.currentPosLo = 0;
    c->work.currentPosHi = (c->work.currentPosHi + ((c->work.currentLast - 1) * 0xA0)) % 480;
    c->work.pitchOffsetPeriod = ((c->period / 5) + 1) & ~(1);
    c->work.pitchOffsetPeriodCount = c->work.pitchOffsetPeriod >> 1;
    c->work.pitchOffset = (c->variation << 0x10) / (c->work.pitchOffsetPeriod * 5);
    OSRestoreInterrupts(old);
    return 1;
}

void sndAuxCallbackChorus(AXFX_BUFFERUPDATE* bufferUpdate, AXFX_CHORUS* chorus)
{
    s32* leftD;
    s32* rightD;
    s32* surD;
    s32* leftS;
    s32* rightS;
    s32* surS;
    u32 i;
    u8 nextCurrentLast;

    nextCurrentLast = (chorus->work.currentLast + 1) % 3;
    leftD = chorus->work.lastLeft[nextCurrentLast];
    rightD = chorus->work.lastRight[nextCurrentLast];
    surD = chorus->work.lastSur[nextCurrentLast];
    leftS = bufferUpdate->left;
    rightS = bufferUpdate->right;
    surS = bufferUpdate->surround;

    for (i = 0; i < 0xA0; i++) {
        *leftD++ = *leftS++;
        *rightD++ = *rightS++;
        *surD++ = *surS++;
    }

    chorus->work.src.pitchHi = (chorus->work.pitchOffset >> 0x10) + 1;
    chorus->work.src.pitchLo = (chorus->work.pitchOffset & 0xFFFF) << 0x10;

    if (--chorus->work.pitchOffsetPeriodCount == 0) {
        chorus->work.pitchOffsetPeriodCount = chorus->work.pitchOffsetPeriod;
        chorus->work.pitchOffset = -chorus->work.pitchOffset;
    }

    for (i = 0; i < 3; i++) {
        chorus->work.src.posHi = chorus->work.currentPosHi;
        chorus->work.src.posLo = chorus->work.currentPosLo;
        switch (i) {
        case 0:
            chorus->work.src.smpBase = chorus->work.lastLeft[0];
            chorus->work.src.dest = bufferUpdate->left;
            chorus->work.src.old = &chorus->work.oldLeft[0];
            break;
        case 1:
            chorus->work.src.smpBase = chorus->work.lastRight[0];
            chorus->work.src.dest = bufferUpdate->right;
            chorus->work.src.old = &chorus->work.oldRight[0];
            break;
        case 2:
            chorus->work.src.smpBase = chorus->work.lastSur[0];
            chorus->work.src.dest = bufferUpdate->surround;
            chorus->work.src.old = &chorus->work.oldSur[0];
            break;
        }
        switch (chorus->work.src.pitchHi) {
        case 0:
            do_src1(&chorus->work.src);
            break;
        case 1:
            do_src2(&chorus->work.src);
            break;
        }
    }

    chorus->work.currentPosHi = (chorus->work.src.posHi % 480);
    chorus->work.currentPosLo = chorus->work.src.posLo;
    chorus->work.currentLast = nextCurrentLast;
}

void sndAuxCallbackDelay(AXFX_BUFFERUPDATE* bufferUpdate, AXFX_DELAY* delay)
{
    s32 l;
    s32 r;
    s32 s;
    s32* lBuf;
    s32* rBuf;
    s32* sBuf;
    u32 i;
    s32* left;
    s32* right;
    s32* sur;

    left = bufferUpdate->left;
    right = bufferUpdate->right;
    sur = bufferUpdate->surround;
    lBuf = delay->left + (delay->currentPos[0] * 0xA0);
    rBuf = delay->right + (delay->currentPos[1] * 0xA0);
    sBuf = delay->sur + (delay->currentPos[2] * 0xA0);

    for (i = 0; i < 160; i++) {
        l = *lBuf;
        r = *rBuf;
        s = *sBuf;
        *lBuf++ = *left + ((s32)(l * delay->currentFeedback[0]) >> 7);
        *rBuf++ = *right + ((s32)(r * delay->currentFeedback[1]) >> 7);
        *sBuf++ = *sur + ((s32)(s * delay->currentFeedback[2]) >> 7);
        *left++ = (s32)(l * delay->currentOutput[0]) >> 7;
        *right++ = (s32)(r * delay->currentOutput[1]) >> 7;
        *sur++ = (s32)(s * delay->currentOutput[2]) >> 7;
    }

    delay->currentPos[0] = (s32)((delay->currentPos[0] + 1) % delay->currentSize[0]);
    delay->currentPos[1] = (s32)((delay->currentPos[1] + 1) % delay->currentSize[1]);
    delay->currentPos[2] = (s32)((delay->currentPos[2] + 1) % delay->currentSize[2]);
}

int sndAuxCallbackUpdateSettingsDelay(AXFX_DELAY* delay)
{
    u32 i;
    s32* l;
    s32* r;
    s32* s;
    BOOL old;

    sndAuxCallbackShutdownDelay(delay);
    old = OSDisableInterrupts();

    for (i = 0; i < 3; i++) {
        delay->currentSize[i] = (((delay->delay[i] - 5) << 5) + 0x9F) / 160U;
        delay->currentPos[i] = 0;
        delay->currentFeedback[i] = (delay->feedback[i] << 7) / 100U;
        delay->currentOutput[i] = (delay->output[i] << 7) / 100U;
    }

    delay->left = lbl_805DCA28(delay->currentSize[0] * 0xA0 * 4);
    delay->right = lbl_805DCA28(delay->currentSize[1] * 0xA0 * 4);
    delay->sur = lbl_805DCA28(delay->currentSize[2] * 0xA0 * 4);

    l = delay->left;
    for (i = 0; i < delay->currentSize[0] * 0xA0; i++) {
        *l++ = 0;
    }

    r = delay->right;
    for (i = 0; i < delay->currentSize[1] * 0xA0; i++) {
        *r++ = 0;
    }

    s = delay->sur;
    for (i = 0; i < delay->currentSize[2] * 0xA0; i++) {
        *s++ = 0;
    }

    OSRestoreInterrupts(old);
    return 1;
}

int sndAuxCallbackPrepareDelay(AXFX_DELAY* delay)
{
    BOOL old;

    old = OSDisableInterrupts();
    delay->left = NULL;
    delay->right = NULL;
    delay->sur = NULL;
    OSRestoreInterrupts(old);
    sndAuxCallbackUpdateSettingsDelay(delay);
}

int sndAuxCallbackShutdownDelay(AXFX_DELAY* delay)
{
    BOOL old;

    old = OSDisableInterrupts();
    if (delay->left) {
        lbl_805DCA2C(delay->left);
    }
    if (delay->right) {
        lbl_805DCA2C(delay->right);
    }
    if (delay->sur) {
        lbl_805DCA2C(delay->sur);
    }

    OSRestoreInterrupts(old);
    return 1;
}

void* salMalloc(u32 size)
{
    void* result;
    result = OSAllocFromHeap(lbl_805DC978, size);
    return result;
}

void salFree(void* ptr)
{
    OSFreeToHeap(lbl_805DC978, ptr);
}

void sndSetHooks(void* (*allocFn)(u32), void (*freeFn)(void*))
{
    lbl_805DCA28 = allocFn;
    lbl_805DCA2C = freeFn;
}

typedef struct KarLbhvqmFadeSlot
{
    s16 cur;
    s16 tgt;
} KarLbhvqmFadeSlot;

typedef struct KarLbhvqmMixSlot
{
    void* owner;
    s32 field_0x04;
    s32 field_0x08;
    s32 field_0x0C;
    s32 field_0x10;
    s32 posA;
    s32 posB;
    s32 field_0x1C;
    s32 coef0;
    s32 coef1;
    s32 coef2;
    s32 coef3;
    s32 coef4;
    s32 coef5;
    KarLbhvqmFadeSlot fade[10];
} KarLbhvqmMixSlot;

typedef struct KarLbhvqmVoice
{
    u8 pad_0x00[0x18];
    s32 mixIndex;
} KarLbhvqmVoice;

KarLbhvqmMixSlot lbl_80587A60[64];
u8 lbl_80589260[0x18];

s32 lbl_805DE150[2];
s32 lbl_805DE14C;
s32 lbl_805DE148;

s32 lbl_80501150[752] = {
    0x00000001, 0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001,
    0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001,
    0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001,
    0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001,
    0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001, 0x00010001,
    0x00010001, 0x00020002, 0x00020002, 0x00020002, 0x00020002, 0x00020002,
    0x00020002, 0x00020002, 0x00020002, 0x00020002, 0x00020002, 0x00020002,
    0x00020002, 0x00020002, 0x00020002, 0x00020002, 0x00020002, 0x00020002,
    0x00020003, 0x00030003, 0x00030003, 0x00030003, 0x00030003, 0x00030003,
    0x00030003, 0x00030003, 0x00030003, 0x00030003, 0x00030003, 0x00030003,
    0x00030003, 0x00040004, 0x00040004, 0x00040004, 0x00040004, 0x00040004,
    0x00040004, 0x00040004, 0x00040004, 0x00040004, 0x00040005, 0x00050005,
    0x00050005, 0x00050005, 0x00050005, 0x00050005, 0x00050005, 0x00050005,
    0x00050006, 0x00060006, 0x00060006, 0x00060006, 0x00060006, 0x00060006,
    0x00060006, 0x00070007, 0x00070007, 0x00070007, 0x00070007, 0x00070007,
    0x00070007, 0x00080008, 0x00080008, 0x00080008, 0x00080008, 0x00080008,
    0x00090009, 0x00090009, 0x00090009, 0x00090009, 0x0009000A, 0x000A000A,
    0x000A000A, 0x000A000A, 0x000A000A, 0x000B000B, 0x000B000B, 0x000B000B,
    0x000B000C, 0x000C000C, 0x000C000C, 0x000C000C, 0x000D000D, 0x000D000D,
    0x000D000D, 0x000D000E, 0x000E000E, 0x000E000E, 0x000E000F, 0x000F000F,
    0x000F000F, 0x00100010, 0x00100010, 0x00100011, 0x00110011, 0x00110011,
    0x00120012, 0x00120012, 0x00120013, 0x00130013, 0x00130013, 0x00140014,
    0x00140014, 0x00150015, 0x00150015, 0x00160016, 0x00160016, 0x00170017,
    0x00170018, 0x00180018, 0x00180019, 0x00190019, 0x001A001A, 0x001A001A,
    0x001B001B, 0x001B001C, 0x001C001C, 0x001D001D, 0x001D001E, 0x001E001E,
    0x001F001F, 0x00200020, 0x00200021, 0x00210021, 0x00220022, 0x00230023,
    0x00230024, 0x00240025, 0x00250026, 0x00260026, 0x00270027, 0x00280028,
    0x00290029, 0x002A002A, 0x002B002B, 0x002C002C, 0x002D002D, 0x002E002E,
    0x002F002F, 0x00300031, 0x00310032, 0x00320033, 0x00330034, 0x00350035,
    0x00360037, 0x00370038, 0x00380039, 0x003A003A, 0x003B003C, 0x003D003D,
    0x003E003F, 0x003F0040, 0x00410042, 0x00420043, 0x00440045, 0x00460046,
    0x00470048, 0x0049004A, 0x004B004B, 0x004C004D, 0x004E004F, 0x00500051,
    0x00520053, 0x00540055, 0x00560057, 0x00580059, 0x005A005B, 0x005C005D,
    0x005E005F, 0x00600061, 0x00620064, 0x00650066, 0x00670068, 0x006A006B,
    0x006C006D, 0x006F0070, 0x00710072, 0x00740075, 0x00760078, 0x0079007B,
    0x007C007E, 0x007F0080, 0x00820083, 0x00850087, 0x0088008A, 0x008B008D,
    0x008F0090, 0x00920094, 0x00950097, 0x0099009B, 0x009C009E, 0x00A000A2,
    0x00A400A6, 0x00A800AA, 0x00AB00AD, 0x00AF00B2, 0x00B400B6, 0x00B800BA,
    0x00BC00BE, 0x00C000C3, 0x00C500C7, 0x00CA00CC, 0x00CE00D1, 0x00D300D6,
    0x00D800DB, 0x00DD00E0, 0x00E200E5, 0x00E700EA, 0x00ED00F0, 0x00F200F5,
    0x00F800FB, 0x00FE0101, 0x01040107, 0x010A010D, 0x01100113, 0x0116011A,
    0x011D0120, 0x01240127, 0x012A012E, 0x01310135, 0x0138013C, 0x01400143,
    0x0147014B, 0x014F0153, 0x0157015B, 0x015F0163, 0x0167016B, 0x016F0173,
    0x0178017C, 0x01800185, 0x0189018E, 0x01930197, 0x019C01A1, 0x01A601AB,
    0x01AF01B4, 0x01BA01BF, 0x01C401C9, 0x01CE01D4, 0x01D901DF, 0x01E401EA,
    0x01EF01F5, 0x01FB0201, 0x0207020D, 0x02130219, 0x021F0226, 0x022C0232,
    0x02390240, 0x0246024D, 0x0254025B, 0x02620269, 0x02700277, 0x027E0286,
    0x028D0295, 0x029D02A4, 0x02AC02B4, 0x02BC02C4, 0x02CC02D5, 0x02DD02E6,
    0x02EE02F7, 0x03000309, 0x0312031B, 0x0324032D, 0x03370340, 0x034A0354,
    0x035D0367, 0x0371037C, 0x03860390, 0x039B03A6, 0x03B103BB, 0x03C703D2,
    0x03DD03E9, 0x03F40400, 0x040C0418, 0x04240430, 0x043D0449, 0x04560463,
    0x0470047D, 0x048A0498, 0x04A504B3, 0x04C104CF, 0x04DD04EC, 0x04FA0509,
    0x05180527, 0x05360546, 0x05550565, 0x05750586, 0x059605A6, 0x05B705C8,
    0x05D905EB, 0x05FC060E, 0x06200632, 0x06440657, 0x066A067D, 0x069006A4,
    0x06B706CB, 0x06DF06F4, 0x0708071D, 0x07320748, 0x075D0773, 0x0789079F,
    0x07B607CD, 0x07E407FB, 0x0813082B, 0x0843085C, 0x0874088E, 0x08A708C1,
    0x08DA08F5, 0x090F092A, 0x09450961, 0x097D0999, 0x09B509D2, 0x09EF0A0D,
    0x0A2A0A48, 0x0A670A86, 0x0AA50AC5, 0x0AE50B05, 0x0B250B47, 0x0B680B8A,
    0x0BAC0BCF, 0x0BF20C15, 0x0C390C5D, 0x0C820CA7, 0x0CCC0CF2, 0x0D190D3F,
    0x0D670D8E, 0x0DB70DDF, 0x0E080E32, 0x0E5C0E87, 0x0EB20EDD, 0x0F090F36,
    0x0F630F91, 0x0FBF0FEE, 0x101D104D, 0x107D10AE, 0x10DF1111, 0x11441177,
    0x11AB11DF, 0x1214124A, 0x128012B7, 0x12EE1326, 0x135F1399, 0x13D3140D,
    0x14491485, 0x14C214FF, 0x153E157D, 0x15BC15FD, 0x163E1680, 0x16C31706,
    0x174A178F, 0x17D5181C, 0x186318AC, 0x18F5193F, 0x198A19D5, 0x1A221A6F,
    0x1ABE1B0D, 0x1B5D1BAE, 0x1C001C53, 0x1CA71CFC, 0x1D521DA9, 0x1E011E5A,
    0x1EB41F0F, 0x1F6B1FC8, 0x20262086, 0x20E62148, 0x21AA220E, 0x227322D9,
    0x234123A9, 0x2413247E, 0x24EA2557, 0x25C62636, 0x26A7271A, 0x278E2803,
    0x287A28F2, 0x296B29E6, 0x2A622AE0, 0x2B5F2BDF, 0x2C612CE5, 0x2D6A2DF1,
    0x2E792F03, 0x2F8E301B, 0x30AA313A, 0x31CC325F, 0x32F5338C, 0x342534BF,
    0x355B35FA, 0x369A373C, 0x37DF3885, 0x392C39D6, 0x3A813B2F, 0x3BDE3C90,
    0x3D433DF9, 0x3EB13F6A, 0x402640E5, 0x41A54268, 0x432C43F4, 0x44BD4589,
    0x46574727, 0x47FA48D0, 0x49A84A82, 0x4B5F4C3E, 0x4D204E05, 0x4EEC4FD6,
    0x50C351B2, 0x52A45399, 0x5491558C, 0x5689578A, 0x588D5994, 0x5A9D5BAA,
    0x5CBA5DCD, 0x5EE35FFC, 0x61196238, 0x635C6482, 0x65AC66D9, 0x680A693F,
    0x6A776BB2, 0x6CF26E35, 0x6F7B70C6, 0x72147366, 0x74BC7616, 0x777478D6,
    0x7A3D7BA7, 0x7D167E88, 0x7FFF817B, 0x82FB847F, 0x86088795, 0x89278ABE,
    0x8C598DF9, 0x8F9E9148, 0x92F694AA, 0x96639820, 0x99E39BAB, 0x9D799F4C,
    0xA124A302, 0xA4E5A6CE, 0xA8BCAAB0, 0xACAAAEAA, 0xB0B0B2BC, 0xB4CEB6E5,
    0xB904BB28, 0xBD53BF84, 0xC1BCC3FA, 0xC63FC88B, 0xCADDCD37, 0xCF97D1FE,
    0xD46DD6E3, 0xD960DBE4, 0xDE70E103, 0xE39EE641, 0xE8EBEB9E, 0xEE58F11B,
    0xF3E6F6B9, 0xF994FC78, 0xFF640000, 0x00000000, 0x00000000, 0xFFFFFFFF,
    0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFE, 0xFFFFFFFE, 0xFFFFFFFE, 0xFFFFFFFD,
    0xFFFFFFFD, 0xFFFFFFFC, 0xFFFFFFFC, 0xFFFFFFFC, 0xFFFFFFFB, 0xFFFFFFFB,
    0xFFFFFFFB, 0xFFFFFFFA, 0xFFFFFFFA, 0xFFFFFFF9, 0xFFFFFFF9, 0xFFFFFFF9,
    0xFFFFFFF8, 0xFFFFFFF8, 0xFFFFFFF7, 0xFFFFFFF7, 0xFFFFFFF6, 0xFFFFFFF6,
    0xFFFFFFF6, 0xFFFFFFF5, 0xFFFFFFF5, 0xFFFFFFF4, 0xFFFFFFF4, 0xFFFFFFF3,
    0xFFFFFFF3, 0xFFFFFFF2, 0xFFFFFFF2, 0xFFFFFFF2, 0xFFFFFFF1, 0xFFFFFFF1,
    0xFFFFFFF0, 0xFFFFFFF0, 0xFFFFFFEF, 0xFFFFFFEF, 0xFFFFFFEE, 0xFFFFFFEE,
    0xFFFFFFED, 0xFFFFFFEC, 0xFFFFFFEC, 0xFFFFFFEB, 0xFFFFFFEB, 0xFFFFFFEA,
    0xFFFFFFEA, 0xFFFFFFE9, 0xFFFFFFE9, 0xFFFFFFE8, 0xFFFFFFE7, 0xFFFFFFE7,
    0xFFFFFFE6, 0xFFFFFFE6, 0xFFFFFFE5, 0xFFFFFFE4, 0xFFFFFFE4, 0xFFFFFFE3,
    0xFFFFFFE2, 0xFFFFFFE2, 0xFFFFFFE1, 0xFFFFFFE0, 0xFFFFFFDF, 0xFFFFFFDF,
    0xFFFFFFDE, 0xFFFFFFDD, 0xFFFFFFDC, 0xFFFFFFDC, 0xFFFFFFDB, 0xFFFFFFDA,
    0xFFFFFFD9, 0xFFFFFFD8, 0xFFFFFFD8, 0xFFFFFFD7, 0xFFFFFFD6, 0xFFFFFFD5,
    0xFFFFFFD4, 0xFFFFFFD3, 0xFFFFFFD2, 0xFFFFFFD1, 0xFFFFFFD0, 0xFFFFFFCF,
    0xFFFFFFCE, 0xFFFFFFCD, 0xFFFFFFCC, 0xFFFFFFCA, 0xFFFFFFC9, 0xFFFFFFC8,
    0xFFFFFFC7, 0xFFFFFFC5, 0xFFFFFFC4, 0xFFFFFFC3, 0xFFFFFFC1, 0xFFFFFFC0,
    0xFFFFFFBE, 0xFFFFFFBD, 0xFFFFFFBB, 0xFFFFFFB9, 0xFFFFFFB8, 0xFFFFFFB6,
    0xFFFFFFB4, 0xFFFFFFB2, 0xFFFFFFB0, 0xFFFFFFAD, 0xFFFFFFAB, 0xFFFFFFA9,
    0xFFFFFFA6, 0xFFFFFFA3, 0xFFFFFFA0, 0xFFFFFF9D, 0xFFFFFF9A, 0xFFFFFF96,
    0xFFFFFF92, 0xFFFFFF8D, 0xFFFFFF88, 0xFFFFFF82, 0xFFFFFF7B, 0xFFFFFF74,
    0xFFFFFF6A, 0xFFFFFF5D, 0xFFFFFF4C, 0xFFFFFF2E, 0xFFFFFC78, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x0000FFFF,
    0xFFFFFFFF, 0xFFFFFFFF, 0xFFFEFFFE, 0xFFFEFFFE, 0xFFFDFFFD, 0xFFFDFFFC,
    0xFFFCFFFC, 0xFFFBFFFB, 0xFFFAFFFA, 0xFFFAFFF9, 0xFFF9FFF8, 0xFFF8FFF7,
    0xFFF7FFF6, 0xFFF5FFF5, 0xFFF4FFF4, 0xFFF3FFF2, 0xFFF2FFF1, 0xFFF0FFEF,
    0xFFEFFFEE, 0xFFEDFFEC, 0xFFEBFFEB, 0xFFEAFFE9, 0xFFE8FFE7, 0xFFE6FFE5,
    0xFFE4FFE3, 0xFFE2FFE1, 0xFFE0FFDE, 0xFFDDFFDC, 0xFFDBFFDA, 0xFFD8FFD7,
    0xFFD6FFD4, 0xFFD3FFD1, 0xFFD0FFCE, 0xFFCCFFCB, 0xFFC9FFC7, 0xFFC6FFC4,
    0xFFC2FFC0, 0xFFBEFFBC, 0xFFBAFFB7, 0xFFB5FFB3, 0xFFB0FFAE, 0xFFABFFA8,
    0xFFA6FFA3, 0xFFA0FF9C, 0xFF99FF96, 0xFF92FF8E, 0xFF8AFF86, 0xFF82FF7D,
    0xFF78FF73, 0xFF6EFF68, 0xFF61FF5A, 0xFF53FF4B, 0xFF42FF37, 0xFF2CFF1F,
    0xFF0FFEFB, 0xFEE2FEBF, 0xFE83FC40, 0xFFC3FFC3, 0xFFC4FFC5, 0xFFC5FFC6,
    0xFFC6FFC7, 0xFFC8FFC8, 0xFFC9FFC9, 0xFFCAFFCB, 0xFFCBFFCC, 0xFFCCFFCD,
    0xFFCEFFCE, 0xFFCFFFCF, 0xFFD0FFD0, 0xFFD1FFD1, 0xFFD2FFD2, 0xFFD3FFD3,
    0xFFD4FFD4, 0xFFD5FFD5, 0xFFD6FFD6, 0xFFD7FFD7, 0xFFD8FFD8, 0xFFD9FFD9,
    0xFFDAFFDA, 0xFFDAFFDB, 0xFFDBFFDC, 0xFFDCFFDD, 0xFFDDFFDD, 0xFFDEFFDE,
    0xFFDFFFDF, 0xFFE0FFE0, 0xFFE0FFE1, 0xFFE1FFE1, 0xFFE2FFE2, 0xFFE3FFE3,
    0xFFE3FFE4, 0xFFE4FFE4, 0xFFE5FFE5, 0xFFE5FFE6, 0xFFE6FFE6, 0xFFE7FFE7,
    0xFFE7FFE8, 0xFFE8FFE8, 0xFFE9FFE9, 0xFFE9FFEA, 0xFFEAFFEA, 0xFFEBFFEB,
    0xFFEBFFEC, 0xFFECFFEC, 0xFFECFFED, 0xFFEDFFED, 0xFFEEFFEE, 0xFFEEFFEE,
    0xFFEFFFEF, 0xFFEFFFEF, 0xFFF0FFF0, 0xFFF0FFF0, 0xFFF1FFF1, 0xFFF1FFF1,
    0xFFF2FFF2, 0xFFF2FFF2, 0xFFF3FFF3, 0xFFF3FFF3, 0xFFF3FFF4, 0xFFF4FFF4,
    0xFFF4FFF5, 0x00010101, 0x01010102, 0x02020203, 0x03040405, 0x05060708,
    0x090A0B0C, 0x0E101214, 0x16191C20, 0x24282D32, 0x39404750, 0x5A65717F,
    0x8FA0B4CA, 0xE3FF0000,
};

void kar_lbhvqm_calc_movie_audio_mix_coefficients(KarLbhvqmMixSlot* slot)
{
    s32 a;
    s32 b;
    s32 invA;
    s32 invB;
    s16* tbl16;
    s32* tbl32;

    a = slot->posA;
    b = slot->posB;
    invA = 0x7F - a;
    invB = 0x7F - b;

    if (lbl_805DE150[0] == 3) {
        tbl16 = (s16*)lbl_80501150;
        slot->coef0 = tbl16[0x98c / 2 + a];
        slot->coef1 = tbl16[0x98c / 2 + invA];
        slot->coef2 = tbl16[0x98c / 2 + invB];
        slot->coef3 = tbl16[0x98c / 2 + b];
        slot->coef4 = tbl16[0xa8c / 2 + invA];
        slot->coef5 = tbl16[0xa8c / 2 + a];
    } else {
        tbl32 = (s32*)((u8*)lbl_80501150 + 0x78c);
        slot->coef0 = tbl32[a];
        slot->coef1 = tbl32[invA];
        slot->coef2 = tbl32[invB];
        slot->coef3 = tbl32[b];
    }
}

void kar_lbhvqm_init_movie_audio_mix_table(void)
{
    s32 i;
    KarLbhvqmMixSlot* slot;

    for (i = 0, slot = lbl_80587A60; i < 0x40; i++, slot++) {
        slot->field_0x04 = 0x50000000;
        slot->field_0x08 = 0;
        slot->field_0x0C = -0x3C0;
        slot->field_0x10 = -0x3C0;
        slot->posA = 0x40;
        slot->posB = 0x7F;
        slot->field_0x1C = 0;
        slot->fade[9].cur = 0;
        slot->fade[8].cur = 0;
        slot->fade[7].cur = 0;
        slot->fade[6].cur = 0;
        slot->fade[5].cur = 0;
        slot->fade[4].cur = 0;
        slot->fade[3].cur = 0;
        slot->fade[2].cur = 0;
        slot->fade[1].cur = 0;
        slot->fade[0].cur = 0;
        kar_lbhvqm_calc_movie_audio_mix_coefficients(slot);
    }

    lbl_805DE148 = 0;
    lbl_805DE14C = 0;
    lbl_805DE150[0] = 1;
}

void kar_lbhvqm_attach_movie_audio_voice_mix(void* voice, u32 flags, s32 pitch, s32 field_0x0C, s32 field_0x10,
                                              s32 field_0x14, s32 field_0x18, s32 field_0x1C)
{
}

void kar_lbhvqm_detach_movie_audio_voice_mix(KarLbhvqmVoice* voice)
{
    lbl_80587A60[voice->mixIndex].owner = NULL;
}

void kar_lbhvqm_update_movie_audio_mix_faders(void)
{
}
