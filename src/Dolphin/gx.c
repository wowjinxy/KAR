#include "dolphin/types.h"
#include "dolphin/gx/gxtypes.h"

typedef struct OSContext {
    u32 gpr[32];
    u32 cr;
    u32 lr;
    u32 ctr;
    u32 xer;
    f64 fpr[32];
    u32 fpscr_pad;
    u32 fpscr;
    u32 srr0;
    u32 srr1;
    u16 mode;
    u16 state;
    u32 gqr[8];
    u32 psf_pad;
    f64 psf[32];
} OSContext;
typedef struct OSThread OSThread;
typedef s64 OSTime;
typedef s16 __OSInterrupt;
typedef void (*__OSInterruptHandler)(u32 interrupt, OSContext* context);

extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL level);
extern void OSRegisterVersion(char* version);
extern void __OSSetInterruptHandler(u32 interrupt, __OSInterruptHandler handler);
extern u32 __OSUnmaskInterrupts(u32 mask);
extern void OSClearContext(OSContext* context);
extern void OSSetCurrentContext(OSContext* context);
extern OSTime OSGetTime(void);
extern OSThread* OSGetCurrentThread(void);
extern void OSResumeThread(OSThread* thread);
extern void OSSuspendThread(OSThread* thread);
extern void* memset(void* dst, int val, u32 n);
extern void kar_diagnostic__near_803c3354(void); /* PPCSync */
extern u32 PPCMfhid2(void);
extern void PPCMthid2(u32 hid2);
extern void PPCMtwpar(u32 wpar);
extern s32 VIGetTvFormat(void);

typedef BOOL (*OSResetFunction)(BOOL);
typedef struct OSResetFunctionInfo OSResetFunctionInfo;
struct OSResetFunctionInfo {
    OSResetFunction func;
    u32 priority;
    OSResetFunctionInfo* next;
    OSResetFunctionInfo* prev;
};
extern void OSRegisterResetFunction(OSResetFunctionInfo* info);

typedef struct OSThreadQueue OSThreadQueue;
extern void OSInitThreadQueue(OSThreadQueue* queue);
extern void OSSleepThread(OSThreadQueue* queue);
extern void OSWakeupThread(OSThreadQueue* queue);

#define OS_BUS_CLOCK (*(volatile u32*)0x800000F8)
#define OSPhysicalToUncached(paddr) ((void*)((u32)(paddr) + 0xC0000000))
#define OSPhysicalToCached(paddr) ((void*)((u32)(paddr) + 0x80000000))
#define OSUncachedToPhysical(ucaddr) ((u32)(ucaddr) - 0xC0000000)

#define GXFIFO_ADDR 0xCC008000

typedef union _PPCWGPipe {
    u8 u8;
    u16 u16;
    u32 u32;
    s8 s8;
    s16 s16;
    s32 s32;
    f32 f32;
} PPCWGPipe;

volatile PPCWGPipe GXWGFifo : GXFIFO_ADDR;

#define GX_NONE 0
#define GX_DIRECT 1
#define GX_INDEX8 2
#define GX_INDEX16 3

#define GX_U8 0
#define GX_S8 1
#define GX_U16 2
#define GX_S16 3
#define GX_F32 4
#define GX_RGB565 0
#define GX_RGB8 1
#define GX_RGBX8 2
#define GX_RGBA4 3
#define GX_RGBA6 4
#define GX_RGBA8 5

#define GX_POS_XY 0
#define GX_POS_XYZ 1
#define GX_NRM_XYZ 0
#define GX_NRM_NBT 1
#define GX_NRM_NBT3 2
#define GX_CLR_RGB 0
#define GX_CLR_RGBA 1
#define GX_TEX_S 0
#define GX_TEX_ST 1

#define GX_VTXFMT0 0
#define GX_VTXFMT3 3
#define GX_MAX_VTXFMT 8

#define GX_QUADS 0x80
#define GX_TRIANGLES 0x90
#define GX_TRIANGLESTRIP 0x98
#define GX_TRIANGLEFAN 0xA0
#define GX_LINES 0xA8
#define GX_LINESTRIP 0xB0
#define GX_POINTS 0xB8

#define GX_TEXCOORD0 0
#define GX_TEXCOORD1 1
#define GX_TEXCOORD2 2
#define GX_TEXCOORD3 3
#define GX_TEXCOORD4 4
#define GX_TEXCOORD5 5
#define GX_TEXCOORD6 6
#define GX_TEXCOORD7 7
#define GX_MAX_TEXCOORD 8
#define GX_TEXCOORD_NULL 0xFF

#define GX_TG_MTX3x4 0
#define GX_TG_MTX2x4 1
#define GX_TG_BUMP0 2
#define GX_TG_SRTG 10

#define GX_TG_POS 0
#define GX_TG_NRM 1
#define GX_TG_TEX0 4

#define GX_PNMTX0 0
#define GX_PTIDENTITY 125
#define GX_IDENTITY 60

#define GX_MTX3x4 0
#define GX_MTX2x4 1

#define GX_CULL_NONE 0
#define GX_CULL_FRONT 1
#define GX_CULL_BACK 2
#define GX_CULL_ALL 3

#define GX_TO_ZERO 0

#define GX_PERSPECTIVE 0
#define GX_ORTHOGRAPHIC 1

#define GX_CLIP_ENABLE 0
#define GX_CLIP_DISABLE 1

#define GX_COLOR0 0
#define GX_COLOR1 1
#define GX_ALPHA0 2
#define GX_ALPHA1 3
#define GX_COLOR0A0 4
#define GX_COLOR1A1 5
#define GX_COLOR_ZERO 6
#define GX_ALPHA_BUMP 7
#define GX_ALPHA_BUMPN 8
#define GX_COLOR_NULL 0xFF

#define GX_SRC_REG 0
#define GX_SRC_VTX 1

#define GX_DF_NONE 0
#define GX_DF_SIGN 1
#define GX_DF_CLAMP 2

#define GX_AF_SPEC 0
#define GX_AF_SPOT 1
#define GX_AF_NONE 2

#define GX_LIGHT_NULL 0

#define GX_TEVSTAGE0 0
#define GX_MAX_TEVSTAGE 16

#define GX_MODULATE 0
#define GX_DECAL 1
#define GX_BLEND 2
#define GX_REPLACE 3
#define GX_PASSCLR 4

#define GX_TEVPREV 0
#define GX_TEVREG0 1
#define GX_TEVREG1 2
#define GX_TEVREG2 3

#define GX_CC_CPREV 0
#define GX_CC_APREV 1
#define GX_CC_C0 2
#define GX_CC_A0 3
#define GX_CC_C1 4
#define GX_CC_A1 5
#define GX_CC_C2 6
#define GX_CC_A2 7
#define GX_CC_TEXC 8
#define GX_CC_TEXA 9
#define GX_CC_RASC 10
#define GX_CC_RASA 11
#define GX_CC_ONE 12
#define GX_CC_HALF 13
#define GX_CC_KONST 14
#define GX_CC_ZERO 15

#define GX_CA_APREV 0
#define GX_CA_A0 1
#define GX_CA_A1 2
#define GX_CA_A2 3
#define GX_CA_TEXA 4
#define GX_CA_RASA 5
#define GX_CA_KONST 6
#define GX_CA_ZERO 7

#define GX_TEV_ADD 0
#define GX_TEV_SUB 1

#define GX_TB_ZERO 0
#define GX_TB_ADDHALF 1
#define GX_TB_SUBHALF 2

#define GX_CS_SCALE_1 0
#define GX_CS_SCALE_2 1
#define GX_CS_SCALE_4 2
#define GX_CS_DIVIDE_2 3

#define GX_KCOLOR0 0
#define GX_KCOLOR1 1
#define GX_KCOLOR2 2
#define GX_KCOLOR3 3

#define GX_TEV_KCSEL_1_4 6
#define GX_TEV_KASEL_1 0

#define GX_TEV_SWAP0 0
#define GX_TEV_SWAP1 1
#define GX_TEV_SWAP2 2
#define GX_TEV_SWAP3 3

#define GX_CH_RED 0
#define GX_CH_GREEN 1
#define GX_CH_BLUE 2
#define GX_CH_ALPHA 3

#define GX_NEVER 0
#define GX_LESS 1
#define GX_EQUAL 2
#define GX_LEQUAL 3
#define GX_GREATER 4
#define GX_NEQUAL 5
#define GX_GEQUAL 6
#define GX_ALWAYS 7

#define GX_AOP_AND 0
#define GX_AOP_OR 1
#define GX_AOP_XOR 2
#define GX_AOP_XNOR 3

#define GX_ZT_DISABLE 0
#define GX_ZT_ADD 1
#define GX_ZT_REPLACE 2

#define GX_TF_I4 0x0
#define GX_TF_I8 0x1
#define GX_TF_IA4 0x2
#define GX_TF_IA8 0x3
#define GX_TF_RGB565 0x4
#define GX_TF_RGB5A3 0x5
#define GX_TF_RGBA8 0x6
#define GX_TF_CMPR 0xE
#define GX_TF_C4 0x8
#define GX_TF_C8 0x9
#define GX_TF_C14X2 0xA
#define GX_TF_Z8 0x11
#define GX_TF_Z16 0x13
#define GX_TF_Z24X8 0x16
#define GX_TF_A8 0x27

#define _GX_TF_CTF 0x20
#define _GX_TF_ZTF 0x10
#define GX_CTF_R4 0x20
#define GX_CTF_RA4 0x22
#define GX_CTF_RA8 0x23
#define GX_CTF_YUVA8 0x26
#define GX_CTF_R8 0x28
#define GX_CTF_G8 0x29
#define GX_CTF_B8 0x2A
#define GX_CTF_RG8 0x2B
#define GX_CTF_GB8 0x2C
#define GX_CTF_Z4 0x30
#define GX_CTF_Z8M 0x39
#define GX_CTF_Z8L 0x3A
#define GX_CTF_Z16L 0x3C

#define GX_CLAMP 0
#define GX_REPEAT 1
#define GX_MIRROR 2

#define GX_NEAR 0
#define GX_LINEAR 1
#define GX_NEAR_MIP_NEAR 2
#define GX_LIN_MIP_NEAR 3
#define GX_NEAR_MIP_LIN 4
#define GX_LIN_MIP_LIN 5

#define GX_TEXMAP0 0
#define GX_TEXMAP1 1
#define GX_TEXMAP2 2
#define GX_TEXMAP3 3
#define GX_TEXMAP4 4
#define GX_TEXMAP5 5
#define GX_TEXMAP6 6
#define GX_TEXMAP7 7
#define GX_MAX_TEXMAP 8

#define GX_TEXCACHE_32K 0
#define GX_TEXCACHE_128K 1
#define GX_TEXCACHE_512K 2
#define GX_TEXCACHE_NONE 3

#define GX_TLUT_256 16
#define GX_TLUT_1K 64

#define GX_TL_IA8 0
#define GX_TL_RGB565 1
#define GX_TL_RGB5A3 2

#define GX_ITF_8 0
#define GX_ITF_5 1
#define GX_ITF_4 2
#define GX_ITF_3 3

#define GX_ITB_NONE 0
#define GX_ITM_OFF 0

#define GX_ITW_OFF 0
#define GX_ITW_256 1

#define GX_ITBA_OFF 0

#define GX_INDTEXSTAGE0 0
#define GX_INDTEXSTAGE1 1
#define GX_INDTEXSTAGE2 2
#define GX_INDTEXSTAGE3 3

#define GX_ITS_1 0

#define GX_FOG_NONE 0

#define GX_BM_NONE 0
#define GX_BM_BLEND 1
#define GX_BM_LOGIC 2
#define GX_BM_SUBTRACT 3

#define GX_BL_ZERO 0
#define GX_BL_ONE 1
#define GX_BL_SRCCLR 2
#define GX_BL_INVSRCCLR 3
#define GX_BL_SRCALPHA 4
#define GX_BL_INVSRCALPHA 5
#define GX_BL_DSTALPHA 6
#define GX_BL_INVDSTALPHA 7

#define GX_LO_CLEAR 0
#define GX_LO_SET 15

#define GX_MT_XF_FLUSH 1
#define GX_MT_DL_SAVE_CONTEXT 2
#define GX_MT_ABORT_WAIT_COPYOUT 3
#define GX_MT_NULL 0

#define GX_COPY_PROGRESSIVE 0
#define GX_COPY_INTLC_EVEN 2
#define GX_COPY_INTLC_ODD 3

#define GX_CLAMP_NONE 0
#define GX_CLAMP_TOP 1
#define GX_CLAMP_BOTTOM 2

#define GX_PERF0_VERTICES 0
#define GX_PERF0_CLIP_VTX 1
#define GX_PERF0_CLIP_CLKS 2
#define GX_PERF0_XF_WAIT_IN 3
#define GX_PERF0_XF_WAIT_OUT 4
#define GX_PERF0_XF_XFRM_CLKS 5
#define GX_PERF0_XF_LIT_CLKS 6
#define GX_PERF0_XF_BOT_CLKS 7
#define GX_PERF0_XF_REGLD_CLKS 8
#define GX_PERF0_XF_REGRD_CLKS 9
#define GX_PERF0_CLIP_RATIO 10
#define GX_PERF0_TRIANGLES 11
#define GX_PERF0_TRIANGLES_CULLED 12
#define GX_PERF0_TRIANGLES_PASSED 13
#define GX_PERF0_TRIANGLES_SCISSORED 14
#define GX_PERF0_TRIANGLES_0TEX 15
#define GX_PERF0_TRIANGLES_1TEX 16
#define GX_PERF0_TRIANGLES_2TEX 17
#define GX_PERF0_TRIANGLES_3TEX 18
#define GX_PERF0_TRIANGLES_4TEX 19
#define GX_PERF0_TRIANGLES_5TEX 20
#define GX_PERF0_TRIANGLES_6TEX 21
#define GX_PERF0_TRIANGLES_7TEX 22
#define GX_PERF0_TRIANGLES_8TEX 23
#define GX_PERF0_TRIANGLES_0CLR 24
#define GX_PERF0_TRIANGLES_1CLR 25
#define GX_PERF0_TRIANGLES_2CLR 26
#define GX_PERF0_QUAD_0CVG 27
#define GX_PERF0_QUAD_NON0CVG 28
#define GX_PERF0_QUAD_1CVG 29
#define GX_PERF0_QUAD_2CVG 30
#define GX_PERF0_QUAD_3CVG 31
#define GX_PERF0_QUAD_4CVG 32
#define GX_PERF0_AVG_QUAD_CNT 33
#define GX_PERF0_CLOCKS 34
#define GX_PERF0_NONE 35

#define GX_PERF1_TEXELS 0
#define GX_PERF1_TX_IDLE 1
#define GX_PERF1_TX_REGS 2
#define GX_PERF1_TX_MEMSTALL 3
#define GX_PERF1_TC_CHECK1_2 4
#define GX_PERF1_TC_CHECK3_4 5
#define GX_PERF1_TC_CHECK5_6 6
#define GX_PERF1_TC_CHECK7_8 7
#define GX_PERF1_TC_MISS 8
#define GX_PERF1_VC_ELEMQ_FULL 9
#define GX_PERF1_VC_MISSQ_FULL 10
#define GX_PERF1_VC_MEMREQ_FULL 11
#define GX_PERF1_VC_STATUS7 12
#define GX_PERF1_VC_MISSREP_FULL 13
#define GX_PERF1_VC_STREAMBUF_LOW 14
#define GX_PERF1_VC_ALL_STALLS 15
#define GX_PERF1_VERTICES 16
#define GX_PERF1_FIFO_REQ 17
#define GX_PERF1_CALL_REQ 18
#define GX_PERF1_VC_MISS_REQ 19
#define GX_PERF1_CP_ALL_REQ 20
#define GX_PERF1_CLOCKS 21
#define GX_PERF1_NONE 22

typedef struct _GXVtxDescList {
    u32 attr;
    u32 type;
} GXVtxDescList;

typedef struct _GXVtxAttrFmtList {
    u32 attr;
    u32 cnt;
    u32 type;
    u8 frac;
} GXVtxAttrFmtList;

typedef struct _GXTexObj {
    u32 dummy[8];
} GXTexObj;

typedef struct _GXTexRegion {
    u32 dummy[4];
} GXTexRegion;

typedef struct _GXTlutObj {
    u32 dummy[3];
} GXTlutObj;

typedef struct _GXTlutRegion {
    u32 dummy[4];
} GXTlutRegion;

typedef struct _GXFogAdjTable {
    u16 r[10];
} GXFogAdjTable;

typedef GXTexRegion* (*GXTexRegionCallback)(const GXTexObj* t_obj, u32 id);
typedef GXTlutRegion* (*GXTlutRegionCallback)(u32 idx);

typedef struct __GXTexObjInt_struct {
    u32 mode0;
    u32 mode1;
    u32 image0;
    u32 image3;
    void* userData;
    u32 fmt;
    u32 tlutName;
    u16 loadCnt;
    u8 loadFmt;
    u8 flags;
} __GXTexObjInt;

typedef struct __GXTexRegionInt_struct {
    u32 image1;
    u32 image2;
    u16 sizeEven;
    u16 sizeOdd;
    u8 is32bMipmap;
    u8 isCached;
} __GXTexRegionInt;

typedef struct __GXTlutObjInt_struct {
    u32 tlut;
    u32 loadTlut0;
    u16 numEntries;
} __GXTlutObjInt;

typedef struct __GXTlutRegionInt_struct {
    u32 loadTlut1;
    __GXTlutObjInt tlutObj;
} __GXTlutRegionInt;

typedef struct __GXFifoObj_struct {
    u8* base;
    u8* top;
    u32 size;
    u32 hiWatermark;
    u32 loWatermark;
    void* rdPtr;
    void* wrPtr;
    s32 count;
    u8 bind_cpu;
    u8 bind_gp;
} __GXFifoObj;

typedef struct _GXData {
    u16 vNumNot;
    u16 bpSentNot;
    u16 vNum;
    u16 vLim;
    u32 cpEnable;
    u32 cpStatus;
    u32 cpClr;
    u32 vcdLo;
    u32 vcdHi;
    u32 vatA[8];
    u32 vatB[8];
    u32 vatC[8];
    u32 lpSize;
    u32 matIdxA;
    u32 matIdxB;
    u32 indexBase[4];
    u32 indexStride[4];
    u32 ambColor[2];
    u32 matColor[2];
    u32 suTs0[8];
    u32 suTs1[8];
    u32 suScis0;
    u32 suScis1;
    u32 tref[8];
    u32 iref;
    u32 bpMask;
    u32 IndTexScale0;
    u32 IndTexScale1;
    u32 tevc[16];
    u32 teva[16];
    u32 tevKsel[8];
    u32 cmode0;
    u32 cmode1;
    u32 zmode;
    u32 peCtrl;
    u32 cpDispSrc;
    u32 cpDispSize;
    u32 cpDispStride;
    u32 cpDisp;
    u32 cpTexSrc;
    u32 cpTexSize;
    u32 cpTexStride;
    u32 cpTex;
    u8 cpTexZ;
    u8 pad0[3];
    u32 genMode;
    GXTexRegion TexRegions0[8];
    GXTexRegion TexRegions1[4];
    u32 texRegionRR0;
    u32 texRegionRR1;
    GXTlutRegion TlutRegions[20];
    GXTexRegionCallback texRegionCallback;
    GXTlutRegionCallback tlutRegionCallback;
    u32 nrmType;
    u8 hasNrms;
    u8 hasBiNrms;
    u8 pad1[2];
    u32 projType;
    f32 projMtx[6];
    f32 vpLeft;
    f32 vpTop;
    f32 vpWd;
    f32 vpHt;
    f32 vpNearz;
    f32 vpFarz;
    f32 zOffset;
    f32 zScale;
    u32 tImage0[8];
    u32 tMode0[8];
    u32 texmapId[16];
    u32 tcsManEnab;
    u32 tevTcEnab;
    u32 perf0;
    u32 perf1;
    u32 perfSel;
    u8 inDispList;
    u8 dlSaveContext;
    u8 abtWaitPECopy;
    u8 dirtyVAT;
    u32 dirtyState;
} GXData;

static GXData gxData;
GXData* const gx = &gxData;

void* __memReg;
void* __peReg;
void* __cpReg;
void* __piReg;

static GXFifoObj FifoObj;

typedef void (*GXBreakPtCallback)(void);

u32 lbl_805DDE48; /* __GXOverflowCount */
GXBreakPtCallback lbl_805DDE44; /* BreakPointCB */
u32 lbl_805DDE40; /* GXOverflowSuspendInProgress */
u8 lbl_805DDE3C; /* CPGPLinked */
OSThread* lbl_805DDE38; /* __GXCurrentThread */
__GXFifoObj* lbl_805DDE34; /* GPFifo */
__GXFifoObj* lbl_805DDE30; /* CPUFifo */

#define __GXOverflowCount lbl_805DDE48
#define BreakPointCB lbl_805DDE44
#define GXOverflowSuspendInProgress lbl_805DDE40
#define CPGPLinked lbl_805DDE3C
#define __GXCurrentThread lbl_805DDE38
#define GPFifo lbl_805DDE34
#define CPUFifo lbl_805DDE30

u32 calledOnce;
u32 time_lo;
u32 time_hi;
u32 peCount;

const char* __GXVersion = "<< Dolphin SDK - GX\trelease build: Nov 10 2004 06:27:12 (0x2301) >>";

static OSResetFunctionInfo GXResetFuncInfo;

#define GET_REG_FIELD(reg, size, shift) ((int)((reg) >> (shift)) & ((1 << (size)) - 1))

#define SET_REG_FIELD(reg, size, shift, val) \
    ((reg) = (u32)__rlwimi((u32)(reg), (val), (shift), 32 - (shift) - (size), 31 - (shift)))

#define OLD_SET_REG_FIELD(reg, size, shift, val) \
    ((reg) = ((u32)(reg) & ~(((1u << (size)) - 1) << (shift))) | ((u32)(val) << (shift)))

#define GX_GET_MEM_REG(offset) (*(volatile u16*)((volatile u16*)(__memReg) + (offset)))
#define GX_GET_CP_REG(offset) (*(volatile u16*)((volatile u16*)(__cpReg) + (offset)))
#define GX_GET_PE_REG(offset) (*(volatile u16*)((volatile u16*)(__peReg) + (offset)))
#define GX_GET_PI_REG(offset) (*(volatile u32*)((volatile u32*)(__piReg) + (offset)))

#define GX_SET_MEM_REG(offset, val) (*(volatile u16*)((volatile u16*)(__memReg) + (offset)) = (val))
#define GX_SET_CP_REG(offset, val) (*(volatile u16*)((volatile u16*)(__cpReg) + (offset)) = (val))
#define GX_SET_PE_REG(offset, val) (*(volatile u16*)((volatile u16*)(__peReg) + (offset)) = (val))
#define GX_SET_PI_REG(offset, val) (*(volatile u32*)((volatile u32*)(__piReg) + (offset)) = (val))

#define GX_WRITE_U8(ub) (GXWGFifo.u8 = (u8)(ub))
#define GX_WRITE_U16(us) (GXWGFifo.u16 = (u16)(us))
#define GX_WRITE_U32(ui) (GXWGFifo.u32 = (u32)(ui))
#define GX_WRITE_F32(f) (GXWGFifo.f32 = (f32)(f))

#define GX_WRITE_XF_REG(addr, value) \
    do { \
        GX_WRITE_U8(0x10); \
        GX_WRITE_U32(0x1000 + (addr)); \
        GX_WRITE_U32(value); \
    } while (0)

#define GX_WRITE_XF_REG_F(addr, value) (GX_WRITE_F32(value))

#define GX_WRITE_SOME_REG2(a, b, c, addr) \
    do { \
        s32 regAddr; \
        GX_WRITE_U8(a); \
        GX_WRITE_U8(b); \
        GX_WRITE_U32(c); \
        regAddr = (addr); \
        if (regAddr >= 0 && regAddr < 4) { \
            gx->indexBase[regAddr] = (c); \
        } \
    } while (0)

#define GX_WRITE_SOME_REG3(a, b, c, addr) \
    do { \
        s32 regAddr; \
        GX_WRITE_U8(a); \
        GX_WRITE_U8(b); \
        GX_WRITE_U32(c); \
        regAddr = (addr); \
        if (regAddr >= 0 && regAddr < 4) { \
            gx->indexStride[regAddr] = (c); \
        } \
    } while (0)

#define GX_WRITE_SOME_REG4(a, b, c, addr) \
    do { \
        GX_WRITE_U8(a); \
        GX_WRITE_U8(b); \
        GX_WRITE_U32(c); \
    } while (0)

#define GX_WRITE_RAS_REG(value) \
    do { \
        GX_WRITE_U8(0x61); \
        GX_WRITE_U32(value); \
    } while (0)

u32 fn_803CDC44(const GXTexObj* obj);

GXTexRegion* __GXDefaultTexRegionCallback(const GXTexObj* t_obj, u32 id) {
    id = id % GX_MAX_TEXMAP;
    switch (fn_803CDC44(t_obj)) {
    case GX_TF_C4:
    case GX_TF_C8:
    case GX_TF_C14X2:
        return &gx->TexRegions1[(gx->texRegionRR1++) & 3];
    default:
        return &gx->TexRegions0[(gx->texRegionRR0++) & 7];
    }
}

GXTlutRegion* fn_803C85E8(u32 idx) { /* __GXDefaultTlutRegionCallback */
    if (idx >= 20) {
        return NULL;
    }
    return &gx->TlutRegions[idx];
}

void GXSetMisc(u32 token, u32 val);
void __GXFifoInit(void);
void GXInitFifoBase(GXFifoObj* fifo, void* base, u32 size);
void GXSetCPUFifo(GXFifoObj* fifo);
void GXSetGPFifo(GXFifoObj* fifo);
void __GXPEInit(void);
void __GXFlushTextureState(void);
void GXInitTexCacheRegion(GXTexRegion* region, u8 is_32b_mipmap, u32 tmem_even, u32 size_even, u32 tmem_odd, u32 size_odd);
void GXInitTlutRegion(GXTlutRegion* region, u32 tmem_addr, u32 tlut_size);
void __GXSetTmemConfig(u32 config);
void __GXInitGX(void);
void GXSetTexCoordGen2(u32 dst_coord, u32 func, u32 src_param, u32 mtx, BOOL normalize, u32 pt_texmtx);
void GXSetNumTexGens(u8 nTexGens);
void GXClearVtxDesc(void);
void GXInvalidateVtxCache(void);
void GXSetArray(u32 attr, void* base_ptr, u8 stride);
void GXSetVtxAttrFmtv(u32 vtxfmt, const GXVtxAttrFmtList* list);
void GXSetLineWidth(u8 width, u32 texOffsets);
void GXSetPointSize(u8 pointSize, u32 texOffsets);
void GXEnableTexOffsets(u32 coord, u8 line_enable, u8 point_enable);
void GXLoadPosMtxImm(const f32 mtx[3][4], u32 id);
void kar_grcoll__803d078c(const f32 mtx[3][4], u32 id); /* GXLoadNrmMtxImm */
void GXSetCurrentMtx(u32 id);
void GXLoadTexMtxImm(const f32 mtx[][4], u32 id, u32 type);
void GXSetViewport(f32 left, f32 top, f32 wd, f32 ht, f32 nearz, f32 farz);
void GXSetProjectionv(const f32* ptr);
void GXSetCoPlanar(BOOL enable);
void GXSetCullMode(u32 mode);
void GXSetClipMode(u32 mode);
void GXSetScissor(u32 left, u32 top, u32 wd, u32 ht);
void GXSetScissorBoxOffset(s32 x_off, s32 y_off);
void GXSetNumChans(u8 nChans);
void GXSetChanCtrl(s32 chan, u8 enable, u32 amb_src, u32 mat_src, u32 light_mask, u32 diff_fn, s32 attn_fn);
void kar_grcoll__803cd2b8(u32 chan, GXColor amb_color); /* GXSetChanAmbColor */
void kar_grcoll__803cd3ac(u32 chan, GXColor mat_color); /* GXSetChanMatColor */
void GXInvalidateTexAll(void);
GXTexRegionCallback fn_803CE0CC(GXTexRegionCallback f); /* GXSetTexRegionCallback */
GXTlutRegionCallback fn_803CE0E0(GXTlutRegionCallback f); /* GXSetTlutRegionCallback */
void GXSetTevOrder(u32 stage, u32 coord, u32 map, u32 color);
void GXSetNumTevStages(u8 nStages);
void GXSetTevOp(u32 id, u32 mode);
void GXSetAlphaCompare(u32 comp0, u8 ref0, u32 op, u32 comp1, u8 ref1);
void GXSetZTexture(u32 op, u32 fmt, u32 bias);
void GXSetTevKColorSel(s32 stage, u32 sel);
void GXSetTevKAlphaSel(s32 stage, u32 sel);
void GXSetTevSwapMode(u32 stage, u32 ras_sel, u32 tex_sel);
void GXSetTevSwapModeTable(u32 table, u32 red, u32 green, u32 blue, u32 alpha);
void GXSetTevDirect(u32 tev_stage);
void GXSetNumIndStages(u8 nIndStages);
void GXSetIndTexCoordScale(u32 ind_stage, u32 scale_s, u32 scale_t);
void GXSetFog(u32 type, f32 startz, f32 endz, f32 nearz, f32 farz, GXColor color);
void GXSetFogRangeAdj(u8 enable, u16 center, const GXFogAdjTable* table);
void GXSetBlendMode(u32 type, u32 src_factor, u32 dst_factor, u32 op);
void GXSetColorUpdate(u8 update_enable);
void GXSetAlphaUpdate(u8 update_enable);
void GXSetZMode(u8 compare_enable, u32 func, u8 update_enable);
void GXSetZCompLoc(u8 before_tex);
void GXSetPixelFmt(u32 pix_fmt, u32 z_fmt);
void GXSetDither(u8 dither);
void GXSetDstAlpha(u8 enable, u8 alpha);
void GXSetFieldMask(u8 odd_mask, u8 even_mask);
void GXSetFieldMode(u8 field_mode, u8 half_aspect_ratio);
void fn_803CC5C4(u16 left, u16 top, u16 wd, u16 ht); /* GXSetDispCopySrc */
void GXSetDispCopyDst(u16 wd, u16 ht);
u32 GXSetDispCopyYScale(f32 vscale);
void GXSetCopyClamp(u32 clamp);
void GXSetCopyClear(GXColor clear_clr, u32 clear_z);
void GXSetCopyFilter(u8 aa, const u8 sample_pattern[12][2], u8 vf, const u8 vfilter[7]);
void GXSetDispCopyGamma(u32 gamma);
void GXSetDispCopyFrame2Field(u32 mode);
void GXClearBoundingBox(void);
void fn_803CBEC0(u32 func, u8 threshold); /* GXPokeAlphaMode */
void fn_803CBED4(u32 mode); /* GXPokeAlphaRead */
void fn_803CBEE8(BOOL update_enable); /* GXPokeAlphaUpdate */
void GXPokeBlendMode(u32 type, u32 src_factor, u32 dst_factor, u32 op);
void fn_803CBF8C(BOOL update_enable); /* GXPokeColorUpdate */
void fn_803CBFA8(BOOL enable, u8 alpha); /* GXPokeDstAlpha */
void fn_803CBFBC(BOOL dither); /* GXPokeDither */
void fn_803CBFD8(BOOL compare_enable, u32 func, BOOL update_enable); /* GXPokeZMode */
void fn_803D0BA4(u32 perf0, u32 perf1); /* GXSetGPMetric */
void fn_803D13EC(void); /* GXClearGPMetric */

static inline u32 __GXReadMEMCounterU32(u32 regAddrL, u32 regAddrH) {
    u32 ctrH0;
    u32 ctrH1;
    u32 ctrL;

    ctrH0 = GX_GET_MEM_REG(regAddrH);
    do {
        ctrH1 = ctrH0;
        ctrL = GX_GET_MEM_REG(regAddrL);
        ctrH0 = GX_GET_MEM_REG(regAddrH);
    } while (ctrH0 != ctrH1);

    return (ctrH0 << 0x10) | ctrL;
}

extern void __GXAbort(void);

static int __GXShutdown(BOOL final) {
    u32 reg;
    u32 peCountNew;
    OSTime timeNew;
    OSTime timeOld;

    if (!final) {
        if (!calledOnce) {
            peCount = __GXReadMEMCounterU32(0x28, 0x27);
            timeNew = OSGetTime();
            time_hi = (u32)(timeNew >> 32);
            time_lo = (u32)timeNew;
            calledOnce = 1;
            return 0;
        }

        timeNew = OSGetTime();
        peCountNew = __GXReadMEMCounterU32(0x28, 0x27);
        timeOld = (OSTime)(((u64)time_hi << 32) | time_lo);

        if (timeNew - timeOld < 10) {
            return 0;
        }

        if (peCountNew != peCount) {
            peCount = peCountNew;
            time_hi = (u32)(timeNew >> 32);
            time_lo = (u32)timeNew;
            return 0;
        }
    } else {
        GX_WRITE_U32(0);
        GX_WRITE_U32(0);
        GX_WRITE_U32(0);
        GX_WRITE_U32(0);
        GX_WRITE_U32(0);
        GX_WRITE_U32(0);
        GX_WRITE_U32(0);
        GX_WRITE_U32(0);

        kar_diagnostic__near_803c3354(); /* PPCSync */

        reg = 0;
        GX_SET_CP_REG(1, reg);

        reg = 3;
        GX_SET_CP_REG(2, reg);

        gx->abtWaitPECopy = 1;

        __GXAbort();
    }

    return 1;
}

static GXVtxAttrFmtList GXDefaultVATList[] = {
    { 9 /* GX_VA_POS */, GX_POS_XYZ, GX_F32, 0 },
    { 10 /* GX_VA_NRM */, GX_NRM_XYZ, GX_F32, 0 },
    { 11 /* GX_VA_CLR0 */, GX_CLR_RGBA, GX_RGBA8, 0 },
    { 12 /* GX_VA_CLR1 */, GX_CLR_RGBA, GX_RGBA8, 0 },
    { 13 /* GX_VA_TEX0 */, GX_TEX_ST, GX_F32, 0 },
    { 14 /* GX_VA_TEX1 */, GX_TEX_ST, GX_F32, 0 },
    { 15 /* GX_VA_TEX2 */, GX_TEX_ST, GX_F32, 0 },
    { 16 /* GX_VA_TEX3 */, GX_TEX_ST, GX_F32, 0 },
    { 17 /* GX_VA_TEX4 */, GX_TEX_ST, GX_F32, 0 },
    { 18 /* GX_VA_TEX5 */, GX_TEX_ST, GX_F32, 0 },
    { 19 /* GX_VA_TEX6 */, GX_TEX_ST, GX_F32, 0 },
    { 20 /* GX_VA_TEX7 */, GX_TEX_ST, GX_F32, 0 },
    { 0xff /* GX_VA_NULL */, 0, 0, 0 },
};

static f32 GXDefaultProjData[] = { 1.0f, 0.0f, 1.0f, 0.0f, -1.0f, -2.0f, 0.0f };

static u32 GXTexRegionAddrTable[] = {
    0x00000, 0x10000, 0x20000, 0x30000, 0x40000, 0x50000, 0x60000, 0x70000, 0x08000, 0x18000,
    0x28000, 0x38000, 0x48000, 0x58000, 0x68000, 0x78000, 0x00000, 0x90000, 0x20000, 0xB0000,
    0x40000, 0x98000, 0x60000, 0xB8000, 0x80000, 0x10000, 0xA0000, 0x30000, 0x88000, 0x50000,
    0xA8000, 0x70000,
};

GXFifoObj* GXInit(void* base, u32 size) {
    u32 i;
    u32 reg;
    static u32 resetFuncRegistered;

    OSRegisterVersion((char*)__GXVersion);

    gx->inDispList = FALSE;
    gx->dlSaveContext = TRUE;
    gx->abtWaitPECopy = 1;
    gx->tcsManEnab = FALSE;
    gx->tevTcEnab = FALSE;

    GXSetMisc(GX_MT_XF_FLUSH, 0);

    __cpReg = OSPhysicalToUncached(0xC000000);
    __piReg = OSPhysicalToUncached(0xC003000);
    __peReg = OSPhysicalToUncached(0xC001000);
    __memReg = OSPhysicalToUncached(0xC004000);
    __GXFifoInit();
    GXInitFifoBase(&FifoObj, base, size);
    GXSetCPUFifo(&FifoObj);
    GXSetGPFifo(&FifoObj);

    if (!resetFuncRegistered) {
        OSRegisterResetFunction(&GXResetFuncInfo);
        resetFuncRegistered = 1;
    }

    __GXPEInit();
    reg = PPCMfhid2();
    PPCMtwpar(OSUncachedToPhysical((void*)GXFIFO_ADDR));
    reg |= 0x40000000;
    PPCMthid2(reg);

    gx->genMode = 0;
    SET_REG_FIELD(gx->genMode, 8, 24, 0);
    gx->bpMask = 255;
    SET_REG_FIELD(gx->bpMask, 8, 24, 0x0F);
    gx->lpSize = 0;
    SET_REG_FIELD(gx->lpSize, 8, 24, 0x22);

    for (i = 0; i < 16; ++i) {
        gx->tevc[i] = 0;
        gx->teva[i] = 0;
        gx->tref[i / 2] = 0;
        gx->texmapId[i] = GX_TEXMAP_NULL;
        SET_REG_FIELD(gx->tevc[i], 8, 24, 0xC0 + i * 2);
        SET_REG_FIELD(gx->teva[i], 8, 24, 0xC1 + i * 2);
        SET_REG_FIELD(gx->tevKsel[i / 2], 8, 24, 0xF6 + i / 2);
        SET_REG_FIELD(gx->tref[i / 2], 8, 24, 0x28 + i / 2);
    }

    gx->iref = 0;
    SET_REG_FIELD(gx->iref, 8, 24, 0x27);

    for (i = 0; i < 8; ++i) {
        gx->suTs0[i] = 0;
        gx->suTs1[i] = 0;
        SET_REG_FIELD(gx->suTs0[i], 8, 24, 0x30 + i * 2);
        SET_REG_FIELD(gx->suTs1[i], 8, 24, 0x31 + i * 2);
    }

    SET_REG_FIELD(gx->suScis0, 8, 24, 0x20);
    SET_REG_FIELD(gx->suScis1, 8, 24, 0x21);
    SET_REG_FIELD(gx->cmode0, 8, 24, 0x41);
    SET_REG_FIELD(gx->cmode1, 8, 24, 0x42);
    SET_REG_FIELD(gx->zmode, 8, 24, 0x40);
    SET_REG_FIELD(gx->peCtrl, 8, 24, 0x43);
    SET_REG_FIELD(gx->cpTex, 2, 7, 0);

    gx->zScale = 1.6777216E7f;
    gx->zOffset = 0.0f;
    gx->dirtyState = 0;
    gx->dirtyVAT = FALSE;

    reg = OS_BUS_CLOCK / 500;
    __GXFlushTextureState();
    GX_WRITE_RAS_REG((reg >> 11) | 0x400 | 0x69000000);

    __GXFlushTextureState();
    GX_WRITE_RAS_REG((reg / 0x1080) | 0x200 | 0x46000000);

    for (i = 0; i < 8; i++) {
        GXInitTexCacheRegion(&gx->TexRegions0[i], GX_FALSE, GXTexRegionAddrTable[i],
                              GX_TEXCACHE_32K, GXTexRegionAddrTable[i + 8], GX_TEXCACHE_32K);
    }
    for (i = 0; i < 4; i++) {
        GXInitTexCacheRegion(&gx->TexRegions1[i], GX_FALSE, GXTexRegionAddrTable[i + 16],
                              GX_TEXCACHE_32K, GXTexRegionAddrTable[i + 24], GX_TEXCACHE_32K);
    }

    for (i = 0; i < 16; i++) {
        GXInitTlutRegion(&gx->TlutRegions[i], 0xC0000 + 0x2000 * i, GX_TLUT_256);
    }
    for (i = 0; i < 4; i++) {
        GXInitTlutRegion(&gx->TlutRegions[i + 16], 0xE0000 + 0x8000 * i, GX_TLUT_1K);
    }

    reg = 0;
    GX_SET_CP_REG(3, reg);

    SET_REG_FIELD(gx->perfSel, 4, 4, 0);
    GX_WRITE_U8(0x8);
    GX_WRITE_U8(0x20);
    GX_WRITE_U32(gx->perfSel);

    GX_WRITE_XF_REG(6, 0);
    GX_WRITE_RAS_REG(0x23000000);
    GX_WRITE_RAS_REG(0x24000000);
    GX_WRITE_RAS_REG(0x67000000);

    __GXSetTmemConfig(2);
    __GXInitGX();

    return &FifoObj;
}

static GXRenderModeObj GXNtsc480IntDf = {
    0, 640, 480, 480, 40, 0, 640, 480, 0, 0, 0,
    { { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 } },
    { 0, 0, 21, 22, 21, 0, 0 }
};
static GXRenderModeObj GXPal528IntDf = {
    1, 640, 528, 528, 40, 0, 640, 528, 0, 0, 0,
    { { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 } },
    { 0, 0, 21, 22, 21, 0, 0 }
};
static GXRenderModeObj GXEurgb60Hz480IntDf = {
    0, 640, 480, 480, 40, 0, 640, 480, 0, 0, 0,
    { { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 } },
    { 0, 0, 21, 22, 21, 0, 0 }
};
static GXRenderModeObj GXMpal480IntDf = {
    2, 640, 480, 480, 40, 0, 640, 480, 0, 0, 0,
    { { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 }, { 6, 6 } },
    { 0, 0, 21, 22, 21, 0, 0 }
};

void __GXInitGX(void) {
    GXRenderModeObj* rmode;
    f32 identity_mtx[3][4];
    GXColor clear = { 64, 64, 64, 255 };
    GXColor black = { 0, 0, 0, 0 };
    GXColor white = { 255, 255, 255, 255 };
    u32 i;

    switch (VIGetTvFormat()) {
    case 0:
        rmode = &GXNtsc480IntDf;
        break;
    case 1:
        rmode = &GXPal528IntDf;
        break;
    case 2:
        rmode = &GXMpal480IntDf;
        break;
    case 5:
        rmode = &GXEurgb60Hz480IntDf;
        break;
    default:
        rmode = &GXNtsc480IntDf;
        break;
    }

    GXSetCopyClear(clear, 0xFFFFFF);
    GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_TEX0, 0x3C, GX_FALSE, GX_PTIDENTITY);
    GXSetTexCoordGen2(GX_TEXCOORD1, GX_TG_MTX2x4, GX_TG_TEX0 + 1, 0x3C, GX_FALSE, GX_PTIDENTITY);
    GXSetTexCoordGen2(GX_TEXCOORD2, GX_TG_MTX2x4, GX_TG_TEX0 + 2, 0x3C, GX_FALSE, GX_PTIDENTITY);
    GXSetTexCoordGen2(GX_TEXCOORD3, GX_TG_MTX2x4, GX_TG_TEX0 + 3, 0x3C, GX_FALSE, GX_PTIDENTITY);
    GXSetTexCoordGen2(GX_TEXCOORD4, GX_TG_MTX2x4, GX_TG_TEX0 + 4, 0x3C, GX_FALSE, GX_PTIDENTITY);
    GXSetTexCoordGen2(GX_TEXCOORD5, GX_TG_MTX2x4, GX_TG_TEX0 + 5, 0x3C, GX_FALSE, GX_PTIDENTITY);
    GXSetTexCoordGen2(GX_TEXCOORD6, GX_TG_MTX2x4, GX_TG_TEX0 + 6, 0x3C, GX_FALSE, GX_PTIDENTITY);
    GXSetTexCoordGen2(GX_TEXCOORD7, GX_TG_MTX2x4, GX_TG_TEX0 + 7, 0x3C, GX_FALSE, GX_PTIDENTITY);
    GXSetNumTexGens(1);
    GXClearVtxDesc();
    GXInvalidateVtxCache();

    for (i = 9; i <= 24; i++) {
        GXSetArray(i, gx, 0);
    }

    for (i = GX_VTXFMT0; i < GX_MAX_VTXFMT; i++) {
        GXSetVtxAttrFmtv(i, GXDefaultVATList);
    }

    GXSetLineWidth(6, GX_TO_ZERO);
    GXSetPointSize(6, GX_TO_ZERO);
    GXEnableTexOffsets(GX_TEXCOORD0, 0, 0);
    GXEnableTexOffsets(GX_TEXCOORD1, 0, 0);
    GXEnableTexOffsets(GX_TEXCOORD2, 0, 0);
    GXEnableTexOffsets(GX_TEXCOORD3, 0, 0);
    GXEnableTexOffsets(GX_TEXCOORD4, 0, 0);
    GXEnableTexOffsets(GX_TEXCOORD5, 0, 0);
    GXEnableTexOffsets(GX_TEXCOORD6, 0, 0);
    GXEnableTexOffsets(GX_TEXCOORD7, 0, 0);
    identity_mtx[0][0] = 1.0f;
    identity_mtx[0][1] = 0.0f;
    identity_mtx[0][2] = 0.0f;
    identity_mtx[0][3] = 0.0f;
    identity_mtx[1][0] = 0.0f;
    identity_mtx[1][1] = 1.0f;
    identity_mtx[1][2] = 0.0f;
    identity_mtx[1][3] = 0.0f;
    identity_mtx[2][0] = 0.0f;
    identity_mtx[2][1] = 0.0f;
    identity_mtx[2][2] = 1.0f;
    identity_mtx[2][3] = 0.0f;
    GXLoadPosMtxImm(identity_mtx, GX_PNMTX0);
    kar_grcoll__803d078c(identity_mtx, GX_PNMTX0);
    GXSetCurrentMtx(GX_PNMTX0);
    GXLoadTexMtxImm(identity_mtx, GX_IDENTITY, GX_MTX3x4);
    GXLoadTexMtxImm(identity_mtx, GX_PTIDENTITY, GX_MTX3x4);
    GXSetViewport(0.0f, 0.0f, rmode->fbWidth, rmode->xfbHeight, 0.0f, 1.0f);
    GXSetProjectionv(GXDefaultProjData);
    GXSetCoPlanar(GX_DISABLE);
    GXSetCullMode(GX_CULL_BACK);
    GXSetClipMode(GX_CLIP_ENABLE);
    GXSetScissor(0, 0, rmode->fbWidth, rmode->efbHeight);
    GXSetScissorBoxOffset(0, 0);
    GXSetNumChans(0);
    GXSetChanCtrl(GX_COLOR0A0, GX_DISABLE, GX_SRC_REG, GX_SRC_VTX, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    kar_grcoll__803cd2b8(GX_COLOR0A0, black);
    kar_grcoll__803cd3ac(GX_COLOR0A0, white);
    GXSetChanCtrl(GX_COLOR1A1, GX_DISABLE, GX_SRC_REG, GX_SRC_VTX, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    kar_grcoll__803cd2b8(GX_COLOR1A1, black);
    kar_grcoll__803cd3ac(GX_COLOR1A1, white);
    GXInvalidateTexAll();
    fn_803CE0CC(__GXDefaultTexRegionCallback);
    fn_803CE0E0(fn_803C85E8);

    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
    GXSetTevOrder(GX_TEVSTAGE0 + 1, GX_TEXCOORD1, GX_TEXMAP1, GX_COLOR0A0);
    GXSetTevOrder(GX_TEVSTAGE0 + 2, GX_TEXCOORD2, GX_TEXMAP2, GX_COLOR0A0);
    GXSetTevOrder(GX_TEVSTAGE0 + 3, GX_TEXCOORD3, GX_TEXMAP3, GX_COLOR0A0);
    GXSetTevOrder(GX_TEVSTAGE0 + 4, GX_TEXCOORD4, GX_TEXMAP4, GX_COLOR0A0);
    GXSetTevOrder(GX_TEVSTAGE0 + 5, GX_TEXCOORD5, GX_TEXMAP5, GX_COLOR0A0);
    GXSetTevOrder(GX_TEVSTAGE0 + 6, GX_TEXCOORD6, GX_TEXMAP6, GX_COLOR0A0);
    GXSetTevOrder(GX_TEVSTAGE0 + 7, GX_TEXCOORD7, GX_TEXMAP7, GX_COLOR0A0);
    GXSetTevOrder(GX_TEVSTAGE0 + 8, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
    GXSetTevOrder(GX_TEVSTAGE0 + 9, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
    GXSetTevOrder(GX_TEVSTAGE0 + 10, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
    GXSetTevOrder(GX_TEVSTAGE0 + 11, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
    GXSetTevOrder(GX_TEVSTAGE0 + 12, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
    GXSetTevOrder(GX_TEVSTAGE0 + 13, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
    GXSetTevOrder(GX_TEVSTAGE0 + 14, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
    GXSetTevOrder(GX_TEVSTAGE0 + 15, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);

    GXSetNumTevStages(1);
    GXSetTevOp(GX_TEVSTAGE0, GX_REPLACE);
    GXSetAlphaCompare(GX_ALWAYS, 0, GX_AOP_AND, GX_ALWAYS, 0);
    GXSetZTexture(GX_ZT_DISABLE, GX_TF_Z8, 0);

    for (i = GX_TEVSTAGE0; i < GX_MAX_TEVSTAGE; i++) {
        GXSetTevKColorSel(i, GX_TEV_KCSEL_1_4);
        GXSetTevKAlphaSel(i, GX_TEV_KASEL_1);
        GXSetTevSwapMode(i, GX_TEV_SWAP0, GX_TEV_SWAP0);
    }

    GXSetTevSwapModeTable(GX_TEV_SWAP0, GX_CH_RED, GX_CH_GREEN, GX_CH_BLUE, GX_CH_ALPHA);
    GXSetTevSwapModeTable(GX_TEV_SWAP1, GX_CH_RED, GX_CH_RED, GX_CH_RED, GX_CH_ALPHA);
    GXSetTevSwapModeTable(GX_TEV_SWAP2, GX_CH_GREEN, GX_CH_GREEN, GX_CH_GREEN, GX_CH_ALPHA);
    GXSetTevSwapModeTable(GX_TEV_SWAP3, GX_CH_BLUE, GX_CH_BLUE, GX_CH_BLUE, GX_CH_ALPHA);

    GXSetTevDirect(GX_TEVSTAGE0);

    GXSetNumIndStages(0);
    GXSetIndTexCoordScale(GX_INDTEXSTAGE0, GX_ITS_1, GX_ITS_1);
    GXSetIndTexCoordScale(GX_INDTEXSTAGE1, GX_ITS_1, GX_ITS_1);
    GXSetIndTexCoordScale(GX_INDTEXSTAGE2, GX_ITS_1, GX_ITS_1);
    GXSetIndTexCoordScale(GX_INDTEXSTAGE3, GX_ITS_1, GX_ITS_1);

    GXSetFog(GX_FOG_NONE, 0.0f, 1.0f, 0.1f, 1.0f, black);
    GXSetFogRangeAdj(GX_DISABLE, 0, NULL);
    GXSetBlendMode(GX_BM_NONE, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
    GXSetColorUpdate(GX_ENABLE);
    GXSetAlphaUpdate(GX_ENABLE);
    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
    GXSetZCompLoc(GX_TRUE);
    GXSetDither(GX_ENABLE);
    GXSetDstAlpha(GX_DISABLE, 0);
    GXSetPixelFmt(GX_PF_RGB8_Z24, GX_ZC_LINEAR);
    GXSetFieldMask(GX_ENABLE, GX_ENABLE);
    GXSetFieldMode(rmode->field_rendering,
                   ((rmode->viHeight == 2 * rmode->xfbHeight) ? GX_ENABLE : GX_DISABLE));

    fn_803CC5C4(0, 0, rmode->fbWidth, rmode->efbHeight);
    GXSetDispCopyDst(rmode->fbWidth, rmode->efbHeight);
    GXSetDispCopyYScale((f32)(rmode->xfbHeight) / (f32)(rmode->efbHeight));
    GXSetCopyClamp(GX_CLAMP_TOP | GX_CLAMP_BOTTOM);
    GXSetCopyFilter(rmode->aa, rmode->sample_pattern, GX_TRUE, rmode->vfilter);
    GXSetDispCopyGamma(GX_GM_1_0);
    GXSetDispCopyFrame2Field(GX_COPY_PROGRESSIVE);
    GXClearBoundingBox();

    fn_803CBF8C(GX_TRUE);
    fn_803CBEE8(GX_TRUE);
    fn_803CBFBC(GX_FALSE);
    GXPokeBlendMode(GX_BM_NONE, GX_BL_ZERO, GX_BL_ONE, GX_LO_SET);
    fn_803CBEC0(GX_ALWAYS, 0);
    fn_803CBED4(1);
    fn_803CBFA8(GX_DISABLE, 0);
    fn_803CBFD8(GX_TRUE, GX_ALWAYS, GX_TRUE);

    fn_803D0BA4(GX_PERF0_NONE, GX_PERF1_NONE);
    fn_803D13EC();
}

void GXInitFifoLimits(GXFifoObj* fifo, u32 hiWatermark, u32 loWatermark);
void GXInitFifoPtrs(GXFifoObj* fifo, void* readPtr, void* writePtr);
void __GXFifoLink(u8 en);
void __GXFifoReadEnable(void);
void __GXFifoReadDisable(void);
void __GXWriteFifoIntEnable(u8 hiWatermarkEn, u8 loWatermarkEn);
void __GXWriteFifoIntReset(u8 hiWatermarkClr, u8 loWatermarkClr);
GXFifoObj* fn_803CA01C(void);
GXFifoObj* fn_803CA024(void);

void GXCPInterruptHandler(u32 interrupt, OSContext* context) {
    OSContext exceptionContext;

    gx->cpStatus = GX_GET_CP_REG(0);

    if (GET_REG_FIELD(gx->cpEnable, 1, 3) && GET_REG_FIELD(gx->cpStatus, 1, 1)) {
        OSResumeThread(__GXCurrentThread);
        GXOverflowSuspendInProgress = 0;
        __GXWriteFifoIntReset(1, 1);
        __GXWriteFifoIntEnable(1, 0);
    }

    if (GET_REG_FIELD(gx->cpEnable, 1, 2) && GET_REG_FIELD(gx->cpStatus, 1, 0)) {
        __GXOverflowCount++;
        __GXWriteFifoIntEnable(0, 1);
        __GXWriteFifoIntReset(1, 0);
        GXOverflowSuspendInProgress = 1;
        OSSuspendThread(__GXCurrentThread);
    }

    if (GET_REG_FIELD(gx->cpEnable, 1, 5) && GET_REG_FIELD(gx->cpStatus, 1, 4)) {
        SET_REG_FIELD(gx->cpEnable, 1, 5, 0);
        GX_SET_CP_REG(1, gx->cpEnable);
        if (BreakPointCB != NULL) {
            OSClearContext(&exceptionContext);
            OSSetCurrentContext(&exceptionContext);
            BreakPointCB();
            OSClearContext(&exceptionContext);
            OSSetCurrentContext(context);
        }
    }
}

void GXInitFifoBase(GXFifoObj* fifo, void* base, u32 size) {
    __GXFifoObj* realFifo = (__GXFifoObj*)fifo;

    realFifo->base = base;
    realFifo->top = (u8*)base + size - 4;
    realFifo->size = size;
    realFifo->count = 0;
    GXInitFifoLimits(fifo, size - 0x4000, (size >> 1) & ~0x1F);
    GXInitFifoPtrs(fifo, base, base);
}

void GXInitFifoPtrs(GXFifoObj* fifo, void* readPtr, void* writePtr) {
    __GXFifoObj* realFifo = (__GXFifoObj*)fifo;
    BOOL enabled;

    enabled = OSDisableInterrupts();
    realFifo->rdPtr = readPtr;
    realFifo->wrPtr = writePtr;
    realFifo->count = (u8*)writePtr - (u8*)readPtr;
    if (realFifo->count < 0) {
        realFifo->count += realFifo->size;
    }
    OSRestoreInterrupts(enabled);
}

void GXInitFifoLimits(GXFifoObj* fifo, u32 hiWatermark, u32 loWatermark) {
    __GXFifoObj* realFifo = (__GXFifoObj*)fifo;

    realFifo->hiWatermark = hiWatermark;
    realFifo->loWatermark = loWatermark;
}

void GXSetCPUFifo(GXFifoObj* fifo) {
    __GXFifoObj* realFifo = (__GXFifoObj*)fifo;
    BOOL enabled = OSDisableInterrupts();

    CPUFifo = realFifo;
    if (CPUFifo == GPFifo) {
        u32 reg = 0;

        GX_SET_PI_REG(3, (u32)realFifo->base & 0x3FFFFFFF);
        GX_SET_PI_REG(4, (u32)realFifo->top & 0x3FFFFFFF);
        SET_REG_FIELD(reg, 21, 5, (u32)realFifo->wrPtr >> 5);
        SET_REG_FIELD(reg, 1, 26, 0);
        GX_SET_PI_REG(5, reg);

        __GXWriteFifoIntReset(1, 1);
        __GXWriteFifoIntEnable(1, 0);
        __GXFifoLink(1);
    } else {
        u32 reg;

        if (CPGPLinked) {
            __GXFifoLink(0);
        }

        __GXWriteFifoIntEnable(0, 0);
        reg = 0;
        GX_SET_PI_REG(3, (u32)realFifo->base & 0x3FFFFFFF);
        GX_SET_PI_REG(4, (u32)realFifo->top & 0x3FFFFFFF);
        SET_REG_FIELD(reg, 21, 5, (u32)realFifo->wrPtr >> 5);
        SET_REG_FIELD(reg, 1, 26, 0);
        GX_SET_PI_REG(5, reg);
    }

    kar_diagnostic__near_803c3354(); /* PPCSync */
    OSRestoreInterrupts(enabled);
}

void GXSetGPFifo(GXFifoObj* fifo) {
    __GXFifoObj* realFifo = (__GXFifoObj*)fifo;
    BOOL enabled = OSDisableInterrupts();

    __GXFifoReadDisable();
    __GXWriteFifoIntEnable(0, 0);
    GPFifo = realFifo;

    GX_SET_CP_REG(16, (u32)realFifo->base & 0xFFFF);
    GX_SET_CP_REG(18, (u32)realFifo->top & 0xFFFF);
    GX_SET_CP_REG(24, realFifo->count & 0xFFFF);
    GX_SET_CP_REG(26, (u32)realFifo->wrPtr & 0xFFFF);
    GX_SET_CP_REG(28, (u32)realFifo->rdPtr & 0xFFFF);
    GX_SET_CP_REG(20, (u32)realFifo->hiWatermark & 0xFFFF);
    GX_SET_CP_REG(22, (u32)realFifo->loWatermark & 0xFFFF);
    GX_SET_CP_REG(17, ((u32)realFifo->base & 0x3FFFFFFF) >> 16);
    GX_SET_CP_REG(19, ((u32)realFifo->top & 0x3FFFFFFF) >> 16);
    GX_SET_CP_REG(25, realFifo->count >> 16);
    GX_SET_CP_REG(27, ((u32)realFifo->wrPtr & 0x3FFFFFFF) >> 16);
    GX_SET_CP_REG(29, ((u32)realFifo->rdPtr & 0x3FFFFFFF) >> 16);
    GX_SET_CP_REG(21, (u32)realFifo->hiWatermark >> 16);
    GX_SET_CP_REG(23, (u32)realFifo->loWatermark >> 16);

    kar_diagnostic__near_803c3354(); /* PPCSync */

    if (CPUFifo == GPFifo) {
        __GXWriteFifoIntEnable(1, 0);
        __GXFifoLink(1);
    } else {
        __GXWriteFifoIntEnable(0, 0);
        __GXFifoLink(0);
    }

    __GXWriteFifoIntReset(1, 1);
    __GXFifoReadEnable();
    OSRestoreInterrupts(enabled);
}

#pragma scheduling off
GXBreakPtCallback fn_803C9D94(GXBreakPtCallback cb) {
    GXBreakPtCallback oldcb = BreakPointCB;
    BOOL enabled = OSDisableInterrupts();

    BreakPointCB = cb;
    OSRestoreInterrupts(enabled);
    return oldcb;
}
#pragma scheduling reset

void __GXFifoInit(void) {
    __OSSetInterruptHandler(0x11, (__OSInterruptHandler)GXCPInterruptHandler);
    __OSUnmaskInterrupts(0x4000);
    __GXCurrentThread = OSGetCurrentThread();
    GXOverflowSuspendInProgress = FALSE;
    CPUFifo = NULL;
    GPFifo = NULL;
}

void __GXFifoReadEnable(void) {
    OLD_SET_REG_FIELD(gx->cpEnable, 1, 0, 1);
    GX_SET_CP_REG(1, gx->cpEnable);
}

void __GXFifoReadDisable(void) {
    OLD_SET_REG_FIELD(gx->cpEnable, 1, 0, 0);
    GX_SET_CP_REG(1, gx->cpEnable);
}

void __GXFifoLink(u8 en) {
    OLD_SET_REG_FIELD(gx->cpEnable, 1, 4, (en != 0) ? 1 : 0);
    GX_SET_CP_REG(1, gx->cpEnable);
}

void __GXWriteFifoIntEnable(u8 hiWatermarkEn, u8 loWatermarkEn) {
    OLD_SET_REG_FIELD(gx->cpEnable, 1, 2, hiWatermarkEn);
    OLD_SET_REG_FIELD(gx->cpEnable, 1, 3, loWatermarkEn);
    GX_SET_CP_REG(1, gx->cpEnable);
}

void __GXWriteFifoIntReset(u8 hiWatermarkClr, u8 loWatermarkClr) {
    OLD_SET_REG_FIELD(gx->cpClr, 1, 0, hiWatermarkClr);
    OLD_SET_REG_FIELD(gx->cpClr, 1, 1, loWatermarkClr);
    GX_SET_CP_REG(2, gx->cpClr);
}

void fn_803C9F1C(void) {
    GXFifoObj* gpFifo;
    GXFifoObj* cpuFifo;
    void* base;
    GXFifoObj dummyFifo;

    gpFifo = fn_803CA024();
    if (gpFifo == NULL) {
        return;
    }

    cpuFifo = fn_803CA01C();
    base = ((__GXFifoObj*)gpFifo)->base;

    dummyFifo = *gpFifo;
    GXInitFifoPtrs(&dummyFifo, base, base);
    GXSetGPFifo(&dummyFifo);
    if (cpuFifo == gpFifo) {
        GXSetCPUFifo(&dummyFifo);
    }
    GXInitFifoPtrs(gpFifo, base, base);
    GXSetGPFifo(gpFifo);
    if (cpuFifo == gpFifo) {
        GXSetCPUFifo(cpuFifo);
    }
}

GXFifoObj* fn_803CA01C(void) {
    return (GXFifoObj*)CPUFifo;
}

GXFifoObj* fn_803CA024(void) {
    return (GXFifoObj*)GPFifo;
}

void __GXSetMatrixIndex(u32 matIdxAttr);

void __GXXfVtxSpecs(void) {
    u32 nCols = 0;
    u32 nNrm;
    u32 nTex = 0;
    u32 reg;

    nCols += GET_REG_FIELD(gx->vcdLo, 2, 13) ? 1 : 0;
    nCols += GET_REG_FIELD(gx->vcdLo, 2, 15) ? 1 : 0;

    nNrm = gx->hasBiNrms ? 2 : gx->hasNrms ? 1 : 0;

    nTex += GET_REG_FIELD(gx->vcdHi, 2, 0) ? 1 : 0;
    nTex += GET_REG_FIELD(gx->vcdHi, 2, 2) ? 1 : 0;
    nTex += GET_REG_FIELD(gx->vcdHi, 2, 4) ? 1 : 0;
    nTex += GET_REG_FIELD(gx->vcdHi, 2, 6) ? 1 : 0;
    nTex += GET_REG_FIELD(gx->vcdHi, 2, 8) ? 1 : 0;
    nTex += GET_REG_FIELD(gx->vcdHi, 2, 10) ? 1 : 0;
    nTex += GET_REG_FIELD(gx->vcdHi, 2, 12) ? 1 : 0;
    nTex += GET_REG_FIELD(gx->vcdHi, 2, 14) ? 1 : 0;

    reg = (nCols) | (nNrm << 2) | (nTex << 4);
    GX_WRITE_XF_REG(8, reg);
    gx->bpSentNot = 1;
}

static inline void SETVCDATTR(u32 Attr, u32 Type) {
    switch (Attr) {
    case GX_VA_PNMTXIDX:   OLD_SET_REG_FIELD(gx->vcdLo, 1, 0, Type); break;
    case GX_VA_TEX0MTXIDX: OLD_SET_REG_FIELD(gx->vcdLo, 1, 1, Type); break;
    case GX_VA_TEX1MTXIDX: OLD_SET_REG_FIELD(gx->vcdLo, 1, 2, Type); break;
    case GX_VA_TEX2MTXIDX: OLD_SET_REG_FIELD(gx->vcdLo, 1, 3, Type); break;
    case GX_VA_TEX3MTXIDX: OLD_SET_REG_FIELD(gx->vcdLo, 1, 4, Type); break;
    case GX_VA_TEX4MTXIDX: OLD_SET_REG_FIELD(gx->vcdLo, 1, 5, Type); break;
    case GX_VA_TEX5MTXIDX: OLD_SET_REG_FIELD(gx->vcdLo, 1, 6, Type); break;
    case GX_VA_TEX6MTXIDX: OLD_SET_REG_FIELD(gx->vcdLo, 1, 7, Type); break;
    case GX_VA_TEX7MTXIDX: OLD_SET_REG_FIELD(gx->vcdLo, 1, 8, Type); break;
    case GX_VA_POS:        OLD_SET_REG_FIELD(gx->vcdLo, 2, 9, Type); break;
    case GX_VA_NRM:
        if (Type != GX_NONE) {
            gx->hasNrms = 1;
            gx->hasBiNrms = 0;
            gx->nrmType = Type;
        } else {
            gx->hasNrms = 0;
        }
        break;
    case GX_VA_NBT:
        if (Type != GX_NONE) {
            gx->hasBiNrms = 1;
            gx->hasNrms = 0;
            gx->nrmType = Type;
        } else {
            gx->hasBiNrms = 0;
        }
        break;
    case GX_VA_CLR0: OLD_SET_REG_FIELD(gx->vcdLo, 2, 13, Type); break;
    case GX_VA_CLR1: OLD_SET_REG_FIELD(gx->vcdLo, 2, 15, Type); break;
    case GX_VA_TEX0: OLD_SET_REG_FIELD(gx->vcdHi, 2, 0, Type); break;
    case GX_VA_TEX1: OLD_SET_REG_FIELD(gx->vcdHi, 2, 2, Type); break;
    case GX_VA_TEX2: OLD_SET_REG_FIELD(gx->vcdHi, 2, 4, Type); break;
    case GX_VA_TEX3: OLD_SET_REG_FIELD(gx->vcdHi, 2, 6, Type); break;
    case GX_VA_TEX4: OLD_SET_REG_FIELD(gx->vcdHi, 2, 8, Type); break;
    case GX_VA_TEX5: OLD_SET_REG_FIELD(gx->vcdHi, 2, 10, Type); break;
    case GX_VA_TEX6: OLD_SET_REG_FIELD(gx->vcdHi, 2, 12, Type); break;
    case GX_VA_TEX7: OLD_SET_REG_FIELD(gx->vcdHi, 2, 14, Type); break;
    }
}

void GXSetVtxDesc(u32 attr, u32 type) {
    SETVCDATTR(attr, type);
    if (gx->hasNrms || gx->hasBiNrms) {
        OLD_SET_REG_FIELD(gx->vcdLo, 2, 11, gx->nrmType);
    } else {
        OLD_SET_REG_FIELD(gx->vcdLo, 2, 11, 0);
    }
    gx->dirtyState |= 8;
}

void fn_803CA4D4(const GXVtxDescList* attrPtr) {
    while (attrPtr->attr != GX_VA_NULL) {
        SETVCDATTR(attrPtr->attr, attrPtr->type);
        attrPtr++;
    }

    if (gx->hasNrms || gx->hasBiNrms) {
        OLD_SET_REG_FIELD(gx->vcdLo, 2, 11, gx->nrmType);
    } else {
        OLD_SET_REG_FIELD(gx->vcdLo, 2, 11, 0);
    }
    gx->dirtyState |= 8;
}

#pragma push
#pragma dont_inline on
void __GXSetVCD(void) {
    GX_WRITE_SOME_REG4(8, 0x50, gx->vcdLo, -12);
    GX_WRITE_SOME_REG4(8, 0x60, gx->vcdHi, -12);
    __GXXfVtxSpecs();
}
#pragma pop

void __GXCalculateVLim(void) {
    static u8 tbl1[] = { 0, 4, 1, 2 };
    static u8 tbl2[] = { 0, 8, 1, 2 };
    static u8 tbl3[] = { 0, 12, 1, 2 };

    u32 nc = 0;
    u32 vlm;
    u32 b;
    u32 vl;
    u32 vh;
    u32 va;

    if (gx->vNum != 0) {
        vl = gx->vcdLo;
        vh = gx->vcdHi;
        va = gx->vatA[0];
        nc = GET_REG_FIELD(va, 1, 9);

        vlm  = GET_REG_FIELD(vl, 1, 0);
        vlm += (u8)GET_REG_FIELD(vl, 1, 1);
        vlm += (u8)GET_REG_FIELD(vl, 1, 2);
        vlm += (u8)GET_REG_FIELD(vl, 1, 3);
        vlm += (u8)GET_REG_FIELD(vl, 1, 4);
        vlm += (u8)GET_REG_FIELD(vl, 1, 5);
        vlm += (u8)GET_REG_FIELD(vl, 1, 6);
        vlm += (u8)GET_REG_FIELD(vl, 1, 7);
        vlm += (u8)GET_REG_FIELD(vl, 1, 8);
        vlm += tbl3[(u8)GET_REG_FIELD(vl, 2, 9)];

        if (nc == 1) {
            b = 3;
        } else {
            b = 1;
        }

        vlm += tbl3[(u8)GET_REG_FIELD(vl, 2, 11)] * b;
        vlm += tbl1[(u8)GET_REG_FIELD(vl, 2, 13)];
        vlm += tbl1[(u8)GET_REG_FIELD(vl, 2, 15)];
        vlm += tbl2[(u8)GET_REG_FIELD(vh, 2, 0)];
        vlm += tbl2[(u8)GET_REG_FIELD(vh, 2, 2)];
        vlm += tbl2[(u8)GET_REG_FIELD(vh, 2, 4)];
        vlm += tbl2[(u8)GET_REG_FIELD(vh, 2, 6)];
        vlm += tbl2[(u8)GET_REG_FIELD(vh, 2, 8)];
        vlm += tbl2[(u8)GET_REG_FIELD(vh, 2, 10)];
        vlm += tbl2[(u8)GET_REG_FIELD(vh, 2, 12)];
        vlm += tbl2[(u8)GET_REG_FIELD(vh, 2, 14)];
        gx->vLim = vlm;
    }
}

void fn_803CA9C0(u32 attr, u32* type) {
    u32 cpType;

    switch (attr) {
    case GX_VA_PNMTXIDX:   cpType = GET_REG_FIELD(gx->vcdLo, 1, 0); break;
    case GX_VA_TEX0MTXIDX: cpType = GET_REG_FIELD(gx->vcdLo, 1, 1); break;
    case GX_VA_TEX1MTXIDX: cpType = GET_REG_FIELD(gx->vcdLo, 1, 2); break;
    case GX_VA_TEX2MTXIDX: cpType = GET_REG_FIELD(gx->vcdLo, 1, 3); break;
    case GX_VA_TEX3MTXIDX: cpType = GET_REG_FIELD(gx->vcdLo, 1, 4); break;
    case GX_VA_TEX4MTXIDX: cpType = GET_REG_FIELD(gx->vcdLo, 1, 5); break;
    case GX_VA_TEX5MTXIDX: cpType = GET_REG_FIELD(gx->vcdLo, 1, 6); break;
    case GX_VA_TEX6MTXIDX: cpType = GET_REG_FIELD(gx->vcdLo, 1, 7); break;
    case GX_VA_TEX7MTXIDX: cpType = GET_REG_FIELD(gx->vcdLo, 1, 8); break;
    case GX_VA_POS:        cpType = GET_REG_FIELD(gx->vcdLo, 2, 9); break;
    case GX_VA_NRM:        cpType = gx->hasNrms ? GET_REG_FIELD(gx->vcdLo, 2, 11) : 0; break;
    case GX_VA_NBT:        cpType = gx->hasBiNrms ? GET_REG_FIELD(gx->vcdLo, 2, 11) : 0; break;
    case GX_VA_CLR0:       cpType = GET_REG_FIELD(gx->vcdLo, 2, 13); break;
    case GX_VA_CLR1:       cpType = GET_REG_FIELD(gx->vcdLo, 2, 15); break;
    case GX_VA_TEX0:       cpType = GET_REG_FIELD(gx->vcdHi, 2, 0);  break;
    case GX_VA_TEX1:       cpType = GET_REG_FIELD(gx->vcdHi, 2, 2);  break;
    case GX_VA_TEX2:       cpType = GET_REG_FIELD(gx->vcdHi, 2, 4);  break;
    case GX_VA_TEX3:       cpType = GET_REG_FIELD(gx->vcdHi, 2, 6);  break;
    case GX_VA_TEX4:       cpType = GET_REG_FIELD(gx->vcdHi, 2, 8);  break;
    case GX_VA_TEX5:       cpType = GET_REG_FIELD(gx->vcdHi, 2, 10); break;
    case GX_VA_TEX6:       cpType = GET_REG_FIELD(gx->vcdHi, 2, 12); break;
    case GX_VA_TEX7:       cpType = GET_REG_FIELD(gx->vcdHi, 2, 14); break;
    default: cpType = 0; break;
    }
    *type = cpType;
}

#pragma dont_inline on
void fn_803CAB74(GXVtxDescList* vcd) {
    u32 attr;

    for (attr = GX_VA_PNMTXIDX; attr <= GX_VA_TEX7; attr++) {
        vcd[attr].attr = attr;
        fn_803CA9C0(attr, &vcd[attr].type);
    }

    vcd[attr].attr = GX_VA_NBT;
    fn_803CA9C0(GX_VA_NBT, &vcd[attr].type);

    attr++;
    vcd[attr].attr = GX_VA_NULL;
}
#pragma dont_inline reset

void GXClearVtxDesc(void) {
    gx->vcdLo = 0;
    OLD_SET_REG_FIELD(gx->vcdLo, 2, 9, 1);
    gx->vcdHi = 0;
    gx->hasNrms = 0;
    gx->hasBiNrms = 0;
    gx->dirtyState |= 8;
}

static inline void SETVAT(u32* va, u32* vb, u32* vc, u32 attr, u32 cnt, u32 type, u8 shft) {
    switch (attr) {
    case GX_VA_POS:
        OLD_SET_REG_FIELD(*va, 1, 0, cnt);
        OLD_SET_REG_FIELD(*va, 3, 1, type);
        OLD_SET_REG_FIELD(*va, 5, 4, shft);
        break;
    case GX_VA_NRM:
    case GX_VA_NBT:
        OLD_SET_REG_FIELD(*va, 3, 10, type);
        if (cnt == GX_NRM_NBT3) {
            OLD_SET_REG_FIELD(*va, 1, 9, 1);
            OLD_SET_REG_FIELD(*va, 1, 31, 1);
        } else {
            OLD_SET_REG_FIELD(*va, 1, 9, cnt);
            OLD_SET_REG_FIELD(*va, 1, 31, 0);
        }
        break;
    case GX_VA_CLR0:
        OLD_SET_REG_FIELD(*va, 1, 13, cnt);
        OLD_SET_REG_FIELD(*va, 3, 14, type);
        break;
    case GX_VA_CLR1:
        OLD_SET_REG_FIELD(*va, 1, 0x11, cnt);
        OLD_SET_REG_FIELD(*va, 3, 18, type);
        break;
    case GX_VA_TEX0:
        OLD_SET_REG_FIELD(*va, 1, 0x15, cnt);
        OLD_SET_REG_FIELD(*va, 3, 0x16, type);
        OLD_SET_REG_FIELD(*va, 5, 0x19, shft);
        break;
    case GX_VA_TEX1:
        OLD_SET_REG_FIELD(*vb, 1, 0, cnt);
        OLD_SET_REG_FIELD(*vb, 3, 1, type);
        OLD_SET_REG_FIELD(*vb, 5, 4, shft);
        break;
    case GX_VA_TEX2:
        OLD_SET_REG_FIELD(*vb, 1, 9, cnt);
        OLD_SET_REG_FIELD(*vb, 3, 10, type);
        OLD_SET_REG_FIELD(*vb, 5, 13, shft);
        break;
    case GX_VA_TEX3:
        OLD_SET_REG_FIELD(*vb, 1, 18, cnt);
        OLD_SET_REG_FIELD(*vb, 3, 19, type);
        OLD_SET_REG_FIELD(*vb, 5, 22, shft);
        break;
    case GX_VA_TEX4:
        OLD_SET_REG_FIELD(*vb, 1, 27, cnt);
        OLD_SET_REG_FIELD(*vb, 3, 28, type);
        OLD_SET_REG_FIELD(*vc, 5, 0, shft);
        break;
    case GX_VA_TEX5:
        OLD_SET_REG_FIELD(*vc, 1, 5, cnt);
        OLD_SET_REG_FIELD(*vc, 3, 6, type);
        OLD_SET_REG_FIELD(*vc, 5, 9, shft);
        break;
    case GX_VA_TEX6:
        OLD_SET_REG_FIELD(*vc, 1, 14, cnt);
        OLD_SET_REG_FIELD(*vc, 3, 15, type);
        OLD_SET_REG_FIELD(*vc, 5, 18, shft);
        break;
    case GX_VA_TEX7:
        OLD_SET_REG_FIELD(*vc, 1, 23, cnt);
        OLD_SET_REG_FIELD(*vc, 3, 24, type);
        OLD_SET_REG_FIELD(*vc, 5, 27, shft);
        break;
    }
}

void GXSetVtxAttrFmt(u32 vtxfmt, u32 attr, u32 cnt, u32 type, u8 frac) {
    u32* va;
    u32* vb;
    u32* vc;

    va = &gx->vatA[vtxfmt];
    vb = &gx->vatB[vtxfmt];
    vc = &gx->vatC[vtxfmt];
    SETVAT(va, vb, vc, attr, cnt, type, frac);

    gx->dirtyState |= 0x10;
    gx->dirtyVAT |= (u8)(1 << (u8)vtxfmt);
}

void GXSetVtxAttrFmtv(u32 vtxfmt, const GXVtxAttrFmtList* list) {
    u32* va;
    u32* vb;
    u32* vc;

    va = &gx->vatA[vtxfmt];
    vb = &gx->vatB[vtxfmt];
    vc = &gx->vatC[vtxfmt];

    while (list->attr != GX_VA_NULL) {
        SETVAT(va, vb, vc, list->attr, list->cnt, list->type, list->frac);
        list++;
    }
    gx->dirtyState |= 0x10;
    gx->dirtyVAT |= (u8)(1 << (u8)vtxfmt);
}

void __GXSetVAT(void) {
    s32 i;
    u32 dirty = gx->dirtyVAT;

    i = 0;
    do {
        if (dirty & (1 << i)) {
            GX_WRITE_SOME_REG4(8, i | 0x70, gx->vatA[i], i - 12);
            GX_WRITE_SOME_REG4(8, i | 0x80, gx->vatB[i], i - 12);
            GX_WRITE_SOME_REG4(8, i | 0x90, gx->vatC[i], i - 12);
        }
        i++;
    } while (i < 8);

    gx->dirtyVAT = 0;
}

static inline u8 GetFracForNrm(u32 type) {
    u8 frac;

    switch (type) {
    case GX_S8:
        frac = 6;
        break;
    case GX_S16:
        frac = 14;
        break;
    default:
    case GX_U16:
        frac = 0;
        break;
    }

    return frac;
}

void fn_803CB3A8(u32 fmt, u32 attr, u32* cnt, u32* type, u8* frac) {
    u32* va;
    u32* vb;
    u32* vc;

    va = &gx->vatA[fmt];
    vb = &gx->vatB[fmt];
    vc = &gx->vatC[fmt];

    switch (attr) {
    case GX_VA_POS:
        *cnt  = GET_REG_FIELD(*va, 1, 0);
        *type = GET_REG_FIELD(*va, 3, 1);
        *frac = (u8)(*va >> 4) & 0x1F;
        return;
    case GX_VA_NRM:
    case GX_VA_NBT:
        *cnt = GET_REG_FIELD(*va, 1, 9);
        if (*cnt == GX_TEX_ST && (u8)(*va >> 0x1F) != 0) {
            *cnt = GX_NRM_NBT3;
        }
        *type = GET_REG_FIELD(*va, 3, 10);
        *frac = GetFracForNrm(*type);
        return;
    case GX_VA_CLR0:
        *cnt  = GET_REG_FIELD(*va, 1, 13);
        *type = GET_REG_FIELD(*va, 3, 14);
        *frac = 0;
        return;
    case GX_VA_CLR1:
        *cnt  = GET_REG_FIELD(*va, 1, 17);
        *type = GET_REG_FIELD(*va, 3, 18);
        *frac = 0;
        return;
    case GX_VA_TEX0:
        *cnt  = GET_REG_FIELD(*va, 1, 21);
        *type = GET_REG_FIELD(*va, 3, 22);
        *frac = (u8)(*va >> 0x19) & 0x1F;
        return;
    case GX_VA_TEX1:
        *cnt  = GET_REG_FIELD(*vb, 1, 0);
        *type = GET_REG_FIELD(*vb, 3, 1);
        *frac = (u8)(*vb >> 4) & 0x1F;
        return;
    case GX_VA_TEX2:
        *cnt  = GET_REG_FIELD(*vb, 1, 9);
        *type = GET_REG_FIELD(*vb, 3, 10);
        *frac = (u8)(*vb >> 0xD) & 0x1F;
        return;
    case GX_VA_TEX3:
        *cnt  = GET_REG_FIELD(*vb, 1, 18);
        *type = GET_REG_FIELD(*vb, 3, 19);
        *frac = (u8)(*vb >> 0x16) & 0x1F;
        return;
    case GX_VA_TEX4:
        *cnt  = GET_REG_FIELD(*vb, 1, 27);
        *type = GET_REG_FIELD(*vb, 3, 28);
        *frac = GET_REG_FIELD(*vc, 5, 0);
        return;
    case GX_VA_TEX5:
        *cnt = GET_REG_FIELD(*vc, 1, 5);
        *type = GET_REG_FIELD(*vc, 3, 6);
        *frac = (u8)(*vc >> 9) & 0x1F;
        return;
    case GX_VA_TEX6:
        *cnt = GET_REG_FIELD(*vc, 1, 14);
        *type = GET_REG_FIELD(*vc, 3, 15);
        *frac = (u8)(*vc >> 0x12) & 0x1F;
        return;
    case GX_VA_TEX7:
        *cnt  = GET_REG_FIELD(*vc, 1, 23);
        *type = GET_REG_FIELD(*vc, 3, 24);
        *frac = (int)(*vc >> 0x1B);
        return;
    default:
        *cnt = GX_TEX_ST;
        *type = GX_RGB565;
        *frac = 0;
        return;
    }
}

#pragma dont_inline on
void fn_803CB628(u32 fmt, GXVtxAttrFmtList* vat) {
    u32 attr;

    for (attr = GX_VA_POS; attr <= GX_VA_TEX7; attr++) {
        vat->attr = attr;
        fn_803CB3A8(fmt, attr, &vat->cnt, &vat->type, &vat->frac);
        vat++;
    }

    vat->attr = GX_VA_NULL;
}
#pragma dont_inline reset

void GXSetArray(u32 attr, void* base_ptr, u8 stride) {
    u32 cpAttr;
    u32 phyAddr;

    if (attr == GX_VA_NBT) {
        attr = GX_VA_NRM;
    }

    cpAttr = attr - GX_VA_POS;
    phyAddr = (u32)base_ptr & 0x3FFFFFFF;

    GX_WRITE_SOME_REG2(8, cpAttr | 0xA0, phyAddr, cpAttr - 12);
    GX_WRITE_SOME_REG3(8, cpAttr | 0xB0, stride, cpAttr - 12);
}

void GXInvalidateVtxCache(void) {
    GX_WRITE_U8(0x48);
}

void GXSetTexCoordGen2(u32 dst_coord, u32 func, u32 src_param, u32 mtx, BOOL normalize, u32 pt_texmtx) {
    u32 reg = 0;
    u32 row;
    u32 form;
    u32 mtxIdAttr;

    form = 0;
    row = 5;
    switch (src_param) {
    case GX_TG_POS:     row = 0; form = 1; break;
    case GX_TG_NRM:     row = 1; form = 1; break;
    case 2 /* GX_TG_BINRM */:   row = 3; form = 1; break;
    case 3 /* GX_TG_TANGENT */: row = 4; form = 1; break;
    case 19 /* GX_TG_COLOR0 */:  row = 2; break;
    case 20 /* GX_TG_COLOR1 */:  row = 2; break;
    case GX_TG_TEX0:    row = 5; break;
    case 5 /* GX_TG_TEX1 */:    row = 6; break;
    case 6 /* GX_TG_TEX2 */:    row = 7; break;
    case 7 /* GX_TG_TEX3 */:    row = 8; break;
    case 8 /* GX_TG_TEX4 */:    row = 9; break;
    case 9 /* GX_TG_TEX5 */:    row = 10; break;
    case 10 /* GX_TG_TEX6 */:   row = 11; break;
    case 11 /* GX_TG_TEX7 */:   row = 12; break;
    default:
        break;
    }

    switch (func) {
    case GX_TG_MTX2x4:
        OLD_SET_REG_FIELD(reg, 1, 1, 0);
        OLD_SET_REG_FIELD(reg, 1, 2, form);
        OLD_SET_REG_FIELD(reg, 3, 4, 0);
        OLD_SET_REG_FIELD(reg, 5, 7, row);
        break;
    case GX_TG_MTX3x4:
        OLD_SET_REG_FIELD(reg, 1, 1, 1);
        OLD_SET_REG_FIELD(reg, 1, 2, form);
        OLD_SET_REG_FIELD(reg, 3, 4, 0);
        OLD_SET_REG_FIELD(reg, 5, 7, row);
        break;
    case GX_TG_BUMP0:
    case 3 /* GX_TG_BUMP1 */:
    case 4 /* GX_TG_BUMP2 */:
    case 5 /* GX_TG_BUMP3 */:
    case 6 /* GX_TG_BUMP4 */:
    case 7 /* GX_TG_BUMP5 */:
    case 8 /* GX_TG_BUMP6 */:
    case 9 /* GX_TG_BUMP7 */:
        OLD_SET_REG_FIELD(reg, 1, 1, 0);
        OLD_SET_REG_FIELD(reg, 1, 2, form);
        OLD_SET_REG_FIELD(reg, 3, 4, 1);
        OLD_SET_REG_FIELD(reg, 5, 7, row);
        OLD_SET_REG_FIELD(reg, 3, 12, src_param - 12);
        OLD_SET_REG_FIELD(reg, 3, 15, func - 2);
        break;
    case GX_TG_SRTG:
        OLD_SET_REG_FIELD(reg, 1, 1, 0);
        OLD_SET_REG_FIELD(reg, 1, 2, form);
        if (src_param == 19 /* GX_TG_COLOR0 */) {
            OLD_SET_REG_FIELD(reg, 3, 4, 2);
        } else {
            OLD_SET_REG_FIELD(reg, 3, 4, 3);
        }
        OLD_SET_REG_FIELD(reg, 5, 7, 2);
        break;
    default:
        break;
    }

    GX_WRITE_XF_REG(dst_coord + 0x40, reg);
    reg = 0;
    OLD_SET_REG_FIELD(reg, 6, 0, pt_texmtx - 64);
    OLD_SET_REG_FIELD(reg, 1, 8, normalize);
    GX_WRITE_XF_REG(dst_coord + 0x50, reg);

    switch (dst_coord) {
    case GX_TEXCOORD0: OLD_SET_REG_FIELD(gx->matIdxA, 6, 6, mtx);  break;
    case GX_TEXCOORD1: OLD_SET_REG_FIELD(gx->matIdxA, 6, 12, mtx); break;
    case GX_TEXCOORD2: OLD_SET_REG_FIELD(gx->matIdxA, 6, 18, mtx); break;
    case GX_TEXCOORD3: OLD_SET_REG_FIELD(gx->matIdxA, 6, 24, mtx); break;
    case GX_TEXCOORD4: OLD_SET_REG_FIELD(gx->matIdxB, 6, 0, mtx);  break;
    case GX_TEXCOORD5: OLD_SET_REG_FIELD(gx->matIdxB, 6, 6, mtx);  break;
    case GX_TEXCOORD6: OLD_SET_REG_FIELD(gx->matIdxB, 6, 12, mtx); break;
    default:           OLD_SET_REG_FIELD(gx->matIdxB, 6, 18, mtx); break;
    }

    mtxIdAttr = dst_coord + 1;
    __GXSetMatrixIndex(mtxIdAttr);
}

void GXSetNumTexGens(u8 nTexGens) {
    OLD_SET_REG_FIELD(gx->genMode, 4, 0, nTexGens);
    GX_WRITE_XF_REG(0x3F, nTexGens);
    gx->dirtyState |= 4;
}

typedef void (*GXDrawSyncCallback)(u16 token);
typedef void (*GXDrawDoneCallback)(void);

static GXDrawSyncCallback lbl_805DDE60; /* TokenCB */
static GXDrawDoneCallback lbl_805DDE64; /* DrawDoneCB */
static u8 lbl_805DDE58; /* DrawDone */
static u8 lbl_805DDE5C[12]; /* FinishQueue (OSThreadQueue) */

#define TokenCB lbl_805DDE60
#define DrawDoneCB lbl_805DDE64
#define DrawDone lbl_805DDE58
#define FinishQueue lbl_805DDE5C

void GXSetMisc(u32 token, u32 val) {
    switch (token) {
    case GX_MT_XF_FLUSH:
        gx->vNum = val;
        gx->vNumNot = !gx->vNum;
        gx->bpSentNot = 1;

        if (gx->vNum != 0) {
            gx->dirtyState |= 8;
        }
        break;
    case GX_MT_DL_SAVE_CONTEXT:
        gx->dlSaveContext = (val != 0);
        break;
    case GX_MT_ABORT_WAIT_COPYOUT:
        gx->abtWaitPECopy = (val != 0);
        break;
    case GX_MT_NULL:
        break;
    default:
        break;
    }
}

void __GXSetDirtyState(void);

static inline void GXFlush(void) {
    if (gx->dirtyState) {
        __GXSetDirtyState();
    }

    GX_WRITE_U32(0);
    GX_WRITE_U32(0);
    GX_WRITE_U32(0);
    GX_WRITE_U32(0);
    GX_WRITE_U32(0);
    GX_WRITE_U32(0);
    GX_WRITE_U32(0);
    GX_WRITE_U32(0);

    kar_diagnostic__near_803c3354(); /* PPCSync */
}

static inline void __GXAbortWait(u32 clocks) {
    OSTime time0;
    OSTime time1;

    time0 = OSGetTime();
    do {
        time1 = OSGetTime();
    } while (time1 - time0 <= (clocks / 4));
}

static inline void __GXAbortWaitPECopyDone(void) {
    u32 peCnt0;
    u32 peCnt1;

    peCnt0 = __GXReadMEMCounterU32(0x28, 0x27);
    do {
        peCnt1 = peCnt0;
        __GXAbortWait(32);

        peCnt0 = __GXReadMEMCounterU32(0x28, 0x27);
    } while (peCnt0 != peCnt1);
}

void __GXAbort(void) {
    if (gx->abtWaitPECopy && fn_803CA024() != NULL) {
        __GXAbortWaitPECopyDone();
    }

    ((volatile u32*)__piReg)[0x18 / 4] = 1;
    __GXAbortWait(200);
    ((volatile u32*)__piReg)[0x18 / 4] = 0;
    __GXAbortWait(20);
}

void fn_803CBC48(void) { /* GXAbortFrame */
    __GXAbort();
    fn_803C9F1C();
}

void fn_803CBDB8(void) { /* GXSetDrawDone */
    u32 reg;
    BOOL enabled;

    enabled = OSDisableInterrupts();
    reg = 0x45000002;
    GX_WRITE_RAS_REG(reg);
    GXFlush();
    DrawDone = 0;
    OSRestoreInterrupts(enabled);
}

void GXWaitDrawDone(void) {
    BOOL enabled;

    enabled = OSDisableInterrupts();
    while (!DrawDone) {
        OSSleepThread((OSThreadQueue*)FinishQueue);
    }
    OSRestoreInterrupts(enabled);
}

void GXPixModeSync(void) {
    GX_WRITE_RAS_REG(gx->peCtrl);
    gx->bpSentNot = 0;
}

void fn_803CBEC0(u32 func, u8 threshold) { /* GXPokeAlphaMode */
    u32 reg;

    reg = (func << 8) | threshold;
    GX_SET_PE_REG(3, reg);
}

void fn_803CBED4(u32 mode) { /* GXPokeAlphaRead */
    u32 reg;

    reg = 0;
    OLD_SET_REG_FIELD(reg, 2, 0, mode);
    OLD_SET_REG_FIELD(reg, 1, 2, 1);
    GX_SET_PE_REG(4, reg);
}

void fn_803CBEE8(BOOL update_enable) { /* GXPokeAlphaUpdate */
    u32 reg;

    reg = GX_GET_PE_REG(1);
    OLD_SET_REG_FIELD(reg, 1, 4, update_enable);
    GX_SET_PE_REG(1, reg);
}

void GXPokeBlendMode(u32 type, u32 src_factor, u32 dst_factor, u32 op) {
    u32 reg;

    reg = GX_GET_PE_REG(1);
    OLD_SET_REG_FIELD(reg, 1, 0, (type == GX_BM_BLEND) || (type == GX_BM_SUBTRACT));
    OLD_SET_REG_FIELD(reg, 1, 11, (type == GX_BM_SUBTRACT));
    OLD_SET_REG_FIELD(reg, 1, 1, (type == GX_BM_LOGIC));
    OLD_SET_REG_FIELD(reg, 4, 12, op);
    OLD_SET_REG_FIELD(reg, 3, 8, src_factor);
    OLD_SET_REG_FIELD(reg, 3, 5, dst_factor);
    OLD_SET_REG_FIELD(reg, 8, 24, 0x41);
    GX_SET_PE_REG(1, reg);
}

void fn_803CBF8C(BOOL update_enable) { /* GXPokeColorUpdate */
    u32 reg;

    reg = GX_GET_PE_REG(1);
    OLD_SET_REG_FIELD(reg, 1, 3, update_enable);
    GX_SET_PE_REG(1, reg);
}

void fn_803CBFA8(BOOL enable, u8 alpha) { /* GXPokeDstAlpha */
    u32 reg = 0;

    OLD_SET_REG_FIELD(reg, 8, 0, alpha);
    OLD_SET_REG_FIELD(reg, 1, 8, enable);
    GX_SET_PE_REG(2, reg);
}

void fn_803CBFBC(BOOL dither) { /* GXPokeDither */
    u32 reg;

    reg = GX_GET_PE_REG(1);
    OLD_SET_REG_FIELD(reg, 1, 2, dither);
    GX_SET_PE_REG(1, reg);
}

void fn_803CBFD8(BOOL compare_enable, u32 func, BOOL update_enable) { /* GXPokeZMode */
    u32 reg = 0;

    OLD_SET_REG_FIELD(reg, 1, 0, compare_enable);
    OLD_SET_REG_FIELD(reg, 3, 1, func);
    OLD_SET_REG_FIELD(reg, 1, 4, update_enable);
    GX_SET_PE_REG(0, reg);
}

GXDrawSyncCallback fn_803CC000(GXDrawSyncCallback cb) { /* GXSetDrawSyncCallback */
    GXDrawSyncCallback oldcb;
    BOOL enabled;

    oldcb = TokenCB;
    enabled = OSDisableInterrupts();
    TokenCB = cb;
    OSRestoreInterrupts(enabled);
    return oldcb;
}

void GXTokenInterruptHandler(u32 interrupt, OSContext* context) {
    u16 token;
    OSContext exceptionContext;
    u32 reg;

    token = GX_GET_PE_REG(7);
    if (TokenCB != NULL) {
        OSClearContext(&exceptionContext);
        OSSetCurrentContext(&exceptionContext);
        TokenCB(token);
        OSClearContext(&exceptionContext);
        OSSetCurrentContext(context);
    }
    reg = GX_GET_PE_REG(5);
    OLD_SET_REG_FIELD(reg, 1, 2, 1);
    GX_SET_PE_REG(5, reg);
}

GXDrawDoneCallback fn_803CC0CC(GXDrawDoneCallback cb) { /* GXSetDrawDoneCallback */
    GXDrawDoneCallback oldcb;
    BOOL enabled;

    oldcb = DrawDoneCB;
    enabled = OSDisableInterrupts();
    DrawDoneCB = cb;
    OSRestoreInterrupts(enabled);
    return oldcb;
}

void GXFinishInterruptHandler(u32 interrupt, OSContext* context) {
    OSContext exceptionContext;
    u32 reg;

    reg = GX_GET_PE_REG(5);
    OLD_SET_REG_FIELD(reg, 1, 3, 1);
    GX_SET_PE_REG(5, reg);
    DrawDone = 1;
    if (DrawDoneCB != NULL) {
        OSClearContext(&exceptionContext);
        OSSetCurrentContext(&exceptionContext);
        DrawDoneCB();
        OSClearContext(&exceptionContext);
        OSSetCurrentContext(context);
    }
    OSWakeupThread((OSThreadQueue*)FinishQueue);
}

void __GXPEInit(void) {
    u32 reg;
    __OSSetInterruptHandler(0x12, (__OSInterruptHandler)GXTokenInterruptHandler);
    __OSSetInterruptHandler(0x13, (__OSInterruptHandler)GXFinishInterruptHandler);
    OSInitThreadQueue((OSThreadQueue*)FinishQueue);
    __OSUnmaskInterrupts(0x2000);
    __OSUnmaskInterrupts(0x1000);
    reg = GX_GET_PE_REG(5);
    OLD_SET_REG_FIELD(reg, 1, 2, 1);
    OLD_SET_REG_FIELD(reg, 1, 3, 1);
    OLD_SET_REG_FIELD(reg, 1, 0, 1);
    OLD_SET_REG_FIELD(reg, 1, 1, 1);
    GX_SET_PE_REG(5, reg);
}

void __GXSetSUTexRegs(void);
void __GXUpdateBPMask(void);
void __GXSendFlushPrim(void);
void fn_803CC5A0(void); /* __GXSetGenMode */

#pragma dont_inline on
void __GXSetDirtyState(void) {
    u32 dState = gx->dirtyState;

    if (dState & 1) {
        __GXSetSUTexRegs();
    }
    if (dState & 2) {
        __GXUpdateBPMask();
    }
    if (dState & 4) {
        fn_803CC5A0();
    }
    if (dState & 8) {
        __GXSetVCD();
    }
    if (dState & 0x10) {
        __GXSetVAT();
    }
    if (dState & 0x18) {
        __GXCalculateVLim();
    }

    gx->dirtyState = 0;
}
#pragma dont_inline reset

void GXBegin(u32 type, u32 vtxfmt, u16 nverts) {
    if (gx->dirtyState != 0) {
        __GXSetDirtyState();
    }

    if (*(u32*)&gx->vNumNot == 0) {
        __GXSendFlushPrim();
    }
    GX_WRITE_U8(vtxfmt | type);
    GX_WRITE_U16(nverts);
}

#pragma dont_inline on
void __GXSendFlushPrim(void) {
    u32 i;
    u32 numD = gx->vNum * gx->vLim;

    GX_WRITE_U8(0x98);
    GX_WRITE_U16(gx->vNum);
    for (i = 0; i < numD; i += 4) {
        GX_WRITE_U32(0);
    }
    gx->bpSentNot = 1;
}
#pragma dont_inline reset

void GXSetLineWidth(u8 width, u32 texOffsets) {
    OLD_SET_REG_FIELD(gx->lpSize, 8, 0, width);
    OLD_SET_REG_FIELD(gx->lpSize, 3, 16, texOffsets);
    GX_WRITE_RAS_REG(gx->lpSize);
    gx->bpSentNot = 0;
}

void GXSetPointSize(u8 pointSize, u32 texOffsets) {
    OLD_SET_REG_FIELD(gx->lpSize, 8, 8, pointSize);
    OLD_SET_REG_FIELD(gx->lpSize, 3, 19, texOffsets);
    GX_WRITE_RAS_REG(gx->lpSize);
    gx->bpSentNot = 0;
}

void GXEnableTexOffsets(u32 coord, u8 line_enable, u8 point_enable) {
    OLD_SET_REG_FIELD(gx->suTs0[coord], 1, 18, line_enable);
    OLD_SET_REG_FIELD(gx->suTs0[coord], 1, 19, point_enable);
    GX_WRITE_RAS_REG(gx->suTs0[coord]);
    gx->bpSentNot = 0;
}

void GXSetCullMode(u32 mode) {
    u32 hwMode;

    switch (mode) {
    case GX_CULL_FRONT: hwMode = GX_CULL_BACK;  break;
    case GX_CULL_BACK:  hwMode = GX_CULL_FRONT; break;
    default:            hwMode = mode;          break;
    }

    OLD_SET_REG_FIELD(gx->genMode, 2, 14, hwMode);
    gx->dirtyState |= 4;
}

void GXSetCoPlanar(BOOL enable) {
    u32 reg;

    OLD_SET_REG_FIELD(gx->genMode, 1, 19, enable);
    reg = 0xFE080000;
    GX_WRITE_RAS_REG(reg);
    GX_WRITE_RAS_REG(gx->genMode);
}

void fn_803CC5A0(void) { /* __GXSetGenMode */
    GX_WRITE_RAS_REG(gx->genMode);
    gx->bpSentNot = 0;
}

void fn_803CD70C(s32 fmt, u16 wd, u16 ht, u32* rowTiles, u32* colTiles, u32* cmpTiles); /* __GetImageTileCount */

void fn_803CC5C4(u16 left, u16 top, u16 wd, u16 ht) { /* GXSetDispCopySrc */
    gx->cpDispSrc = 0;
    OLD_SET_REG_FIELD(gx->cpDispSrc, 10, 0, left);
    OLD_SET_REG_FIELD(gx->cpDispSrc, 10, 10, top);
    OLD_SET_REG_FIELD(gx->cpDispSrc, 8, 24, 0x49);

    gx->cpDispSize = 0;
    OLD_SET_REG_FIELD(gx->cpDispSize, 10, 0, wd - 1);
    OLD_SET_REG_FIELD(gx->cpDispSize, 10, 10, ht - 1);
    OLD_SET_REG_FIELD(gx->cpDispSize, 8, 24, 0x4A);
}

void GXSetTexCopySrc(u16 left, u16 top, u16 wd, u16 ht) {
    gx->cpTexSrc = 0;
    OLD_SET_REG_FIELD(gx->cpTexSrc, 10, 0, left);
    OLD_SET_REG_FIELD(gx->cpTexSrc, 10, 10, top);
    OLD_SET_REG_FIELD(gx->cpTexSrc, 8, 24, 0x49);

    gx->cpTexSize = 0;
    OLD_SET_REG_FIELD(gx->cpTexSize, 10, 0, wd - 1);
    OLD_SET_REG_FIELD(gx->cpTexSize, 10, 10, ht - 1);
    OLD_SET_REG_FIELD(gx->cpTexSize, 8, 24, 0x4A);
}

void GXSetDispCopyDst(u16 wd, u16 ht) {
    u16 stride;

    stride = (int)wd * 2;
    gx->cpDispStride = 0;
    OLD_SET_REG_FIELD(gx->cpDispStride, 10, 0, (stride >> 5));
    OLD_SET_REG_FIELD(gx->cpDispStride, 8, 24, 0x4D);
}

void GXSetTexCopyDst(u16 wd, u16 ht, s32 fmt, u8 mipmap) {
    u32 rowTiles;
    u32 colTiles;
    u32 cmpTiles;
    u32 peTexFmt;
    u32 peTexFmtH;

    gx->cpTexZ = 0;
    peTexFmt = fmt & 0xF;

    if (fmt == GX_TF_Z16) {
        peTexFmt = 0xB;
    }

    switch (fmt) {
    case GX_TF_I4:
    case GX_TF_I8:
    case GX_TF_IA4:
    case GX_TF_IA8:
    case GX_CTF_YUVA8:
        OLD_SET_REG_FIELD(gx->cpTex, 2, 15, 3);
        break;
    default:
        OLD_SET_REG_FIELD(gx->cpTex, 2, 15, 2);
        break;
    }

    gx->cpTexZ = (fmt & _GX_TF_ZTF) == _GX_TF_ZTF;
    peTexFmtH = (peTexFmt >> 3) & 1;
    OLD_SET_REG_FIELD(gx->cpTex, 1, 3, peTexFmtH);
    peTexFmt = peTexFmt & 7;
    fn_803CD70C(fmt, wd, ht, &rowTiles, &colTiles, &cmpTiles);

    gx->cpTexStride = 0;
    OLD_SET_REG_FIELD(gx->cpTexStride, 10, 0, rowTiles * cmpTiles);
    OLD_SET_REG_FIELD(gx->cpTexStride, 8, 24, 0x4D);
    OLD_SET_REG_FIELD(gx->cpTex, 1, 9, mipmap);
    OLD_SET_REG_FIELD(gx->cpTex, 3, 4, peTexFmt);
}

void GXSetDispCopyFrame2Field(u32 mode) {
    OLD_SET_REG_FIELD(gx->cpDisp, 2, 12, mode);
    OLD_SET_REG_FIELD(gx->cpTex, 2, 12, 0);
}

void GXSetCopyClamp(u32 clamp) {
    u8 clmpB;
    u8 clmpT;

    clmpT = (clamp & GX_CLAMP_TOP) == 1;
    clmpB = (clamp & GX_CLAMP_BOTTOM) == 2;

    OLD_SET_REG_FIELD(gx->cpDisp, 1, 0, clmpT);
    OLD_SET_REG_FIELD(gx->cpDisp, 1, 1, clmpB);

    OLD_SET_REG_FIELD(gx->cpTex, 1, 0, clmpT);
    OLD_SET_REG_FIELD(gx->cpTex, 1, 1, clmpB);
}

u32 GXSetDispCopyYScale(f32 vscale) {
    u8 enable;
    u32 iScale;
    u32 iScaleD;
    u32 ht;
    u32 realHt;
    u32 reg;

    iScale = (u32)(256.0f / vscale) & 0x1FF;
    enable = (iScale != 256);

    reg = 0;
    OLD_SET_REG_FIELD(reg, 9, 0, iScale);
    OLD_SET_REG_FIELD(reg, 8, 24, 0x4E);
    GX_WRITE_RAS_REG(reg);
    gx->bpSentNot = 0;
    OLD_SET_REG_FIELD(gx->cpDisp, 1, 10, enable);
    ht = (u32)GET_REG_FIELD(gx->cpDispSize, 10, 10) + 1;

    realHt = (((ht - 1) * 0x100) / iScale) + 1;
    iScaleD = iScale;
    if (iScaleD > 0x80 && iScaleD < 0x100) {
        while (iScaleD % 2 == 0) {
            iScaleD /= 2;
        }
        if (ht % iScaleD == 0) {
            realHt++;
        }
    }
    if (realHt > 0x400) {
        realHt = 0x400;
    }

    return realHt;
}

void GXSetCopyClear(GXColor clear_clr, u32 clear_z) {
    u32 reg;

    reg = 0;
    OLD_SET_REG_FIELD(reg, 8, 0, clear_clr.r);
    OLD_SET_REG_FIELD(reg, 8, 8, clear_clr.a);
    OLD_SET_REG_FIELD(reg, 8, 24, 0x4F);
    GX_WRITE_RAS_REG(reg);

    reg = 0;
    OLD_SET_REG_FIELD(reg, 8, 0, clear_clr.b);
    OLD_SET_REG_FIELD(reg, 8, 8, clear_clr.g);
    OLD_SET_REG_FIELD(reg, 8, 24, 0x50);
    GX_WRITE_RAS_REG(reg);

    reg = 0;
    OLD_SET_REG_FIELD(reg, 24, 0, clear_z);
    OLD_SET_REG_FIELD(reg, 8, 24, 0x51);
    GX_WRITE_RAS_REG(reg);
    gx->bpSentNot = 0;
}

void GXSetCopyFilter(u8 aa, const u8 sample_pattern[12][2], u8 vf, const u8 vfilter[7]) {
    u32 msLoc[4];
    u32 coeff0;
    u32 coeff1;

    if (aa != 0) {
        msLoc[0] = 0;
        OLD_SET_REG_FIELD(msLoc[0], 4, 0, sample_pattern[0][0]);
        OLD_SET_REG_FIELD(msLoc[0], 4, 4, sample_pattern[0][1]);
        OLD_SET_REG_FIELD(msLoc[0], 4, 8, sample_pattern[1][0]);
        OLD_SET_REG_FIELD(msLoc[0], 4, 12, sample_pattern[1][1]);
        OLD_SET_REG_FIELD(msLoc[0], 4, 16, sample_pattern[2][0]);
        OLD_SET_REG_FIELD(msLoc[0], 4, 20, sample_pattern[2][1]);
        OLD_SET_REG_FIELD(msLoc[0], 8, 24, 1);

        msLoc[1] = 0;
        OLD_SET_REG_FIELD(msLoc[1], 4, 0, sample_pattern[3][0]);
        OLD_SET_REG_FIELD(msLoc[1], 4, 4, sample_pattern[3][1]);
        OLD_SET_REG_FIELD(msLoc[1], 4, 8, sample_pattern[4][0]);
        OLD_SET_REG_FIELD(msLoc[1], 4, 12, sample_pattern[4][1]);
        OLD_SET_REG_FIELD(msLoc[1], 4, 16, sample_pattern[5][0]);
        OLD_SET_REG_FIELD(msLoc[1], 4, 20, sample_pattern[5][1]);
        OLD_SET_REG_FIELD(msLoc[1], 8, 24, 2);

        msLoc[2] = 0;
        OLD_SET_REG_FIELD(msLoc[2], 4, 0, sample_pattern[6][0]);
        OLD_SET_REG_FIELD(msLoc[2], 4, 4, sample_pattern[6][1]);
        OLD_SET_REG_FIELD(msLoc[2], 4, 8, sample_pattern[7][0]);
        OLD_SET_REG_FIELD(msLoc[2], 4, 12, sample_pattern[7][1]);
        OLD_SET_REG_FIELD(msLoc[2], 4, 16, sample_pattern[8][0]);
        OLD_SET_REG_FIELD(msLoc[2], 4, 20, sample_pattern[8][1]);
        OLD_SET_REG_FIELD(msLoc[2], 8, 24, 3);

        msLoc[3] = 0;
        OLD_SET_REG_FIELD(msLoc[3], 4, 0, sample_pattern[9][0]);
        OLD_SET_REG_FIELD(msLoc[3], 4, 4, sample_pattern[9][1]);
        OLD_SET_REG_FIELD(msLoc[3], 4, 8, sample_pattern[10][0]);
        OLD_SET_REG_FIELD(msLoc[3], 4, 12, sample_pattern[10][1]);
        OLD_SET_REG_FIELD(msLoc[3], 4, 16, sample_pattern[11][0]);
        OLD_SET_REG_FIELD(msLoc[3], 4, 20, sample_pattern[11][1]);
        OLD_SET_REG_FIELD(msLoc[3], 8, 24, 4);
    } else {
        msLoc[0] = 0x01666666;
        msLoc[1] = 0x02666666;
        msLoc[2] = 0x03666666;
        msLoc[3] = 0x04666666;
    }

    GX_WRITE_RAS_REG(msLoc[0]);
    GX_WRITE_RAS_REG(msLoc[1]);
    GX_WRITE_RAS_REG(msLoc[2]);
    GX_WRITE_RAS_REG(msLoc[3]);

    coeff0 = 0;
    OLD_SET_REG_FIELD(coeff0, 8, 24, 0x53);
    coeff1 = 0;
    OLD_SET_REG_FIELD(coeff1, 8, 24, 0x54);

    if (vf != 0) {
        OLD_SET_REG_FIELD(coeff0, 6, 0, vfilter[0]);
        OLD_SET_REG_FIELD(coeff0, 6, 6, vfilter[1]);
        OLD_SET_REG_FIELD(coeff0, 6, 12, vfilter[2]);
        OLD_SET_REG_FIELD(coeff0, 6, 18, vfilter[3]);
        OLD_SET_REG_FIELD(coeff1, 6, 0, vfilter[4]);
        OLD_SET_REG_FIELD(coeff1, 6, 6, vfilter[5]);
        OLD_SET_REG_FIELD(coeff1, 6, 12, vfilter[6]);
    } else {
        OLD_SET_REG_FIELD(coeff0, 6, 0, 0);
        OLD_SET_REG_FIELD(coeff0, 6, 6, 0);
        OLD_SET_REG_FIELD(coeff0, 6, 12, 21);
        OLD_SET_REG_FIELD(coeff0, 6, 18, 22);
        OLD_SET_REG_FIELD(coeff1, 6, 0, 21);
        OLD_SET_REG_FIELD(coeff1, 6, 6, 0);
        OLD_SET_REG_FIELD(coeff1, 6, 12, 0);
    }

    GX_WRITE_RAS_REG(coeff0);
    GX_WRITE_RAS_REG(coeff1);
    gx->bpSentNot = 0;
}

void GXSetDispCopyGamma(u32 gamma) {
    OLD_SET_REG_FIELD(gx->cpDisp, 2, 7, gamma);
}

void GXCopyDisp(void* dest, u8 clear) {
    u32 reg;
    u32 tempPeCtrl;
    u32 phyAddr;
    u8 changePeCtrl;

    if (clear) {
        reg = gx->zmode;
        OLD_SET_REG_FIELD(reg, 1, 0, 1);
        OLD_SET_REG_FIELD(reg, 3, 1, 7);
        GX_WRITE_RAS_REG(reg);

        reg = gx->cmode0;
        OLD_SET_REG_FIELD(reg, 1, 0, 0);
        OLD_SET_REG_FIELD(reg, 1, 1, 0);
        GX_WRITE_RAS_REG(reg);
    }

    changePeCtrl = FALSE;

    if ((clear || (u32)GET_REG_FIELD(gx->peCtrl, 3, 0) == 3) && (u32)GET_REG_FIELD(gx->peCtrl, 1, 6) == 1) {
        changePeCtrl = TRUE;
        tempPeCtrl = gx->peCtrl;
        OLD_SET_REG_FIELD(tempPeCtrl, 1, 6, 0);
        GX_WRITE_RAS_REG(tempPeCtrl);
    }

    GX_WRITE_RAS_REG(gx->cpDispSrc);
    GX_WRITE_RAS_REG(gx->cpDispSize);
    GX_WRITE_RAS_REG(gx->cpDispStride);

    phyAddr = (u32)dest & 0x3FFFFFFF;
    reg = 0;
    OLD_SET_REG_FIELD(reg, 21, 0, phyAddr >> 5);
    OLD_SET_REG_FIELD(reg, 8, 24, 0x4B);
    GX_WRITE_RAS_REG(reg);

    OLD_SET_REG_FIELD(gx->cpDisp, 1, 11, clear);
    OLD_SET_REG_FIELD(gx->cpDisp, 1, 14, 1);
    OLD_SET_REG_FIELD(gx->cpDisp, 8, 24, 0x52);
    GX_WRITE_RAS_REG(gx->cpDisp);

    if (clear) {
        GX_WRITE_RAS_REG(gx->zmode);
        GX_WRITE_RAS_REG(gx->cmode0);
    }

    if (changePeCtrl) {
        GX_WRITE_RAS_REG(gx->peCtrl);
    }

    gx->bpSentNot = 0;
}

void GXCopyTex(void* dest, u8 clear) {
    u32 reg;
    u32 tempPeCtrl;
    u32 phyAddr;
    u8 changePeCtrl;

    if (clear) {
        reg = gx->zmode;
        OLD_SET_REG_FIELD(reg, 1, 0, 1);
        OLD_SET_REG_FIELD(reg, 3, 1, 7);
        GX_WRITE_RAS_REG(reg);

        reg = gx->cmode0;
        OLD_SET_REG_FIELD(reg, 1, 0, 0);
        OLD_SET_REG_FIELD(reg, 1, 1, 0);
        GX_WRITE_RAS_REG(reg);
    }

    changePeCtrl = 0;
    tempPeCtrl = gx->peCtrl;

    if (gx->cpTexZ && ((tempPeCtrl & 7) != 3)) {
        changePeCtrl = 1;
        OLD_SET_REG_FIELD(tempPeCtrl, 3, 0, 3);
    }

    if ((clear || ((u32)(tempPeCtrl & 7) == 3)) && ((u32)((tempPeCtrl >> 6) & 1) == 1)) {
        changePeCtrl = 1;
        OLD_SET_REG_FIELD(tempPeCtrl, 1, 6, 0);
    }

    if (changePeCtrl) {
        GX_WRITE_RAS_REG(tempPeCtrl);
    }

    GX_WRITE_RAS_REG(gx->cpTexSrc);
    GX_WRITE_RAS_REG(gx->cpTexSize);
    GX_WRITE_RAS_REG(gx->cpTexStride);

    phyAddr = (u32)dest & 0x3FFFFFFF;
    reg = 0;
    OLD_SET_REG_FIELD(reg, 21, 0, phyAddr >> 5);
    OLD_SET_REG_FIELD(reg, 8, 24, 0x4B);
    GX_WRITE_RAS_REG(reg);

    OLD_SET_REG_FIELD(gx->cpTex, 1, 11, clear);
    OLD_SET_REG_FIELD(gx->cpTex, 1, 14, 0);
    OLD_SET_REG_FIELD(gx->cpTex, 8, 24, 0x52);
    GX_WRITE_RAS_REG(gx->cpTex);

    if (clear) {
        GX_WRITE_RAS_REG(gx->zmode);
        GX_WRITE_RAS_REG(gx->cmode0);
    }

    if (changePeCtrl) {
        GX_WRITE_RAS_REG(gx->peCtrl);
    }

    gx->bpSentNot = 0;
}

void GXClearBoundingBox(void) {
    u32 reg;

    reg = 0x550003FF;
    GX_WRITE_RAS_REG(reg);
    reg = 0x560003FF;
    GX_WRITE_RAS_REG(reg);
    gx->bpSentNot = 0;
}

typedef struct __GXLightObjInt_struct {
    u32 reserved[3];
    u32 Color;
    f32 a[3];
    f32 k[3];
    f32 lpos[3];
    f32 ldir[3];
} __GXLightObjInt;

extern f32 fn_803BD560(f32 x); /* cosf */

void GXInitLightAttn(GXLightObj* lt_obj, f32 a0, f32 a1, f32 a2, f32 k0, f32 k1, f32 k2) {
    __GXLightObjInt* obj = (__GXLightObjInt*)lt_obj;

    obj->a[0] = a0;
    obj->a[1] = a1;
    obj->a[2] = a2;
    obj->k[0] = k0;
    obj->k[1] = k1;
    obj->k[2] = k2;
}

void GXInitLightSpot(GXLightObj* lt_obj, f32 cutoff, u32 spot_func) {
    f32 a0, a1, a2;
    f32 d;
    f32 cr;
    f32 r;
    __GXLightObjInt* obj = (__GXLightObjInt*)lt_obj;

    if (cutoff <= 0.0f || cutoff > 90.0f) {
        spot_func = 0; /* GX_SP_OFF */
    }

    r = (3.1415927f * cutoff) / 180.0f;
    cr = fn_803BD560(r);

    switch (spot_func) {
    case 1: /* GX_SP_FLAT */
        a0 = -1000.0f * cr;
        a1 = 1000.0f;
        a2 = 0.0f;
        break;
    case 2: /* GX_SP_COS */
        a1 = 1.0f / (1.0f - cr);
        a0 = -cr * a1;
        a2 = 0.0f;
        break;
    case 3: /* GX_SP_COS2 */
        a2 = 1.0f / (1.0f - cr);
        a0 = 0.0f;
        a1 = -cr * a2;
        break;
    case 4: /* GX_SP_SHARP */
        d = 1.0f / ((1.0f - cr) * (1.0f - cr));
        a0 = (cr * (cr - 2.0f)) * d;
        a1 = 2.0f * d;
        a2 = -d;
        break;
    case 5: /* GX_SP_RING1 */
        d = 1.0f / ((1.0f - cr) * (1.0f - cr));
        a2 = -4.0f * d;
        a0 = a2 * cr;
        a1 = (4.0f * (1.0f + cr)) * d;
        break;
    case 6: /* GX_SP_RING2 */
        d = 1.0f / ((1.0f - cr) * (1.0f - cr));
        a0 = 1.0f - ((2.0f * cr * cr) * d);
        a1 = (4.0f * cr) * d;
        a2 = -2.0f * d;
        break;
    case 0: /* GX_SP_OFF */
    default:
        a0 = 1.0f;
        a1 = 0.0f;
        a2 = 0.0f;
        break;
    }
    obj->a[0] = a0;
    obj->a[1] = a1;
    obj->a[2] = a2;
}

void GXInitLightDistAttn(GXLightObj* lt_obj, f32 ref_dist, f32 ref_br, u32 dist_func) {
    f32 k0, k1, k2;
    __GXLightObjInt* obj = (__GXLightObjInt*)lt_obj;

    if (ref_dist < 0.0f) {
        dist_func = 0; /* GX_DA_OFF */
    }
    if (ref_br <= 0.0f || ref_br >= 1.0f) {
        dist_func = 0; /* GX_DA_OFF */
    }

    switch (dist_func) {
    case 1: /* GX_DA_GENTLE */
        k0 = 1.0f;
        k1 = (1.0f - ref_br) / (ref_br * ref_dist);
        k2 = 0.0f;
        break;
    case 2: /* GX_DA_MEDIUM */
        k0 = 1.0f;
        k1 = (0.5f * (1.0f - ref_br)) / (ref_br * ref_dist);
        k2 = (0.5f * (1.0f - ref_br)) / (ref_br * ref_dist * ref_dist);
        break;
    case 3: /* GX_DA_STEEP */
        k0 = 1.0f;
        k1 = 0.0f;
        k2 = (1.0f - ref_br) / (ref_br * ref_dist * ref_dist);
        break;
    case 0: /* GX_DA_OFF */
    default:
        k0 = 1.0f;
        k1 = 0.0f;
        k2 = 0.0f;
        break;
    }

    obj->k[0] = k0;
    obj->k[1] = k1;
    obj->k[2] = k2;
}

void GXInitLightPos(GXLightObj* lt_obj, f32 x, f32 y, f32 z) {
    __GXLightObjInt* obj = (__GXLightObjInt*)lt_obj;

    obj->lpos[0] = x;
    obj->lpos[1] = y;
    obj->lpos[2] = z;
}

void GXInitLightDir(GXLightObj* lt_obj, f32 nx, f32 ny, f32 nz) {
    __GXLightObjInt* obj = (__GXLightObjInt*)lt_obj;

    obj->ldir[0] = -nx;
    obj->ldir[1] = -ny;
    obj->ldir[2] = -nz;
}

void GXInitLightColor(GXLightObj* lt_obj, GXColor color) {
    __GXLightObjInt* obj = (__GXLightObjInt*)lt_obj;

    obj->Color = *(u32*)&color;
}

void GXLoadLightObjImm(const GXLightObj* lt_obj, u32 light) {
    u32 addr;
    u32 idx;

    idx = 31 - __cntlzw(light);
    idx &= 7;
    addr = idx * 0x10 + 0x600;
    GX_WRITE_U8(0x10);
    GX_WRITE_U32(addr | 0xF0000);

    {
        register const GXLightObj* src = lt_obj;
        register void* dest = (void*)GXFIFO_ADDR;
        register u32 zero, color;
        register f32 a0_a1, a2_k0, k1_k2;
        register f32 px_py, pz_dx, dy_dz;

        asm {
            lwz     color, 12(src)
            xor     zero, zero, zero
            psq_l   a0_a1, 16(src), 0, 0
            psq_l   a2_k0, 24(src), 0, 0
            psq_l   k1_k2, 32(src), 0, 0
            psq_l   px_py, 40(src), 0, 0
            psq_l   pz_dx, 48(src), 0, 0
            psq_l   dy_dz, 56(src), 0, 0

            stw     zero,  0(dest)
            stw     zero,  0(dest)
            stw     zero,  0(dest)
            stw     color, 0(dest)
            psq_st  a0_a1, 0(dest), 0, 0
            psq_st  a2_k0, 0(dest), 0, 0
            psq_st  k1_k2, 0(dest), 0, 0
            psq_st  px_py, 0(dest), 0, 0
            psq_st  pz_dx, 0(dest), 0, 0
            psq_st  dy_dz, 0(dest), 0, 0
        }
    }

    gx->bpSentNot = 1;
}

void kar_grcoll__803cd2b8(u32 chan, GXColor amb_color) { /* GXSetChanAmbColor */
    u32 reg;
    u32 rgb;
    u32 colIdx;

    switch (chan) {
    case GX_COLOR0:
        reg = gx->ambColor[GX_COLOR0];
        rgb = *(u32*)&amb_color >> 8;
        OLD_SET_REG_FIELD(reg, 24, 8, rgb);
        colIdx = 0;
        break;
    case GX_COLOR1:
        reg = gx->ambColor[GX_COLOR1];
        rgb = *(u32*)&amb_color >> 8;
        OLD_SET_REG_FIELD(reg, 24, 8, rgb);
        colIdx = 1;
        break;
    case GX_ALPHA0:
        reg = gx->ambColor[GX_COLOR0];
        OLD_SET_REG_FIELD(reg, 8, 0, amb_color.a);
        colIdx = 0;
        break;
    case GX_ALPHA1:
        reg = gx->ambColor[GX_COLOR1];
        OLD_SET_REG_FIELD(reg, 8, 0, amb_color.a);
        colIdx = 1;
        break;
    case GX_COLOR0A0:
        reg = *(u32*)&amb_color;
        colIdx = 0;
        break;
    case GX_COLOR1A1:
        reg = *(u32*)&amb_color;
        colIdx = 1;
        break;
    default:
        return;
    }

    GX_WRITE_XF_REG(colIdx + 10, reg);
    gx->bpSentNot = 1;
    gx->ambColor[colIdx] = reg;
}

void kar_grcoll__803cd3ac(u32 chan, GXColor mat_color) { /* GXSetChanMatColor */
    u32 reg;
    u32 rgb;
    u32 colIdx;

    switch (chan) {
    case GX_COLOR0:
        reg = gx->matColor[GX_COLOR0];
        rgb = *(u32*)&mat_color >> 8;
        OLD_SET_REG_FIELD(reg, 24, 8, rgb);
        colIdx = 0;
        break;
    case GX_COLOR1:
        reg = gx->matColor[GX_COLOR1];
        rgb = *(u32*)&mat_color >> 8;
        OLD_SET_REG_FIELD(reg, 24, 8, rgb);
        colIdx = 1;
        break;
    case GX_ALPHA0:
        reg = gx->matColor[GX_COLOR0];
        OLD_SET_REG_FIELD(reg, 8, 0, mat_color.a);
        colIdx = 0;
        break;
    case GX_ALPHA1:
        reg = gx->matColor[GX_COLOR1];
        OLD_SET_REG_FIELD(reg, 8, 0, mat_color.a);
        colIdx = 1;
        break;
    case GX_COLOR0A0:
        reg = *(u32*)&mat_color;
        colIdx = 0;
        break;
    case GX_COLOR1A1:
        reg = *(u32*)&mat_color;
        colIdx = 1;
        break;
    default:
        return;
    }

    GX_WRITE_XF_REG(colIdx + 12, reg);
    gx->bpSentNot = 1;
    gx->matColor[colIdx] = reg;
}

void GXSetNumChans(u8 nChans) {
    OLD_SET_REG_FIELD(gx->genMode, 3, 4, nChans);
    GX_WRITE_XF_REG(9, nChans);
    gx->dirtyState |= 4;
}

void GXSetChanCtrl(s32 chan, u8 enable, u32 amb_src, u32 mat_src, u32 light_mask, u32 diff_fn, s32 attn_fn) {
    u32 reg;
    u32 idx;

    idx = chan & 0x3;

    reg = 0;
    OLD_SET_REG_FIELD(reg, 1, 1, enable);
    OLD_SET_REG_FIELD(reg, 1, 0, mat_src);
    OLD_SET_REG_FIELD(reg, 1, 6, amb_src);

    OLD_SET_REG_FIELD(reg, 2, 7, (attn_fn == 0) ? 0 : diff_fn);
    OLD_SET_REG_FIELD(reg, 1, 9, (attn_fn != 2));
    OLD_SET_REG_FIELD(reg, 1, 10, (attn_fn != 0));

    OLD_SET_REG_FIELD(reg, 4, 2, light_mask & 0xF);
    OLD_SET_REG_FIELD(reg, 4, 11, (light_mask >> 4) & 0xF);

    GX_WRITE_XF_REG(idx + 14, reg);

    if (chan == GX_COLOR0A0) {
        GX_WRITE_XF_REG(16, reg);
    } else if (chan == GX_COLOR1A1) {
        GX_WRITE_XF_REG(17, reg);
    }

    gx->bpSentNot = 1;
}

u32 kar_shadow__803cd5b0(u16 width, u16 height, u32 format, u8 mipmap, u8 max_lod) { /* GXGetTexBufferSize */
    u32 tileShiftX;
    u32 tileShiftY;
    u32 tileBytes;
    u32 bufferSize;
    u32 nx;
    u32 ny;
    u32 level;

    switch (format) {
    case GX_TF_I4:
    case GX_TF_C4:
    case GX_TF_CMPR:
    case GX_CTF_R4:
    case GX_CTF_Z4:
        tileShiftX = 3;
        tileShiftY = 3;
        break;
    case GX_TF_I8:
    case GX_TF_IA4:
    case GX_TF_C8:
    case GX_TF_Z8:
    case GX_CTF_RA4:
    case GX_TF_A8:
    case GX_CTF_R8:
    case GX_CTF_G8:
    case GX_CTF_B8:
    case GX_CTF_Z8M:
    case GX_CTF_Z8L:
        tileShiftX = 3;
        tileShiftY = 2;
        break;
    case GX_TF_IA8:
    case GX_TF_RGB565:
    case GX_TF_RGB5A3:
    case GX_TF_RGBA8:
    case GX_TF_C14X2:
    case GX_TF_Z16:
    case GX_TF_Z24X8:
    case GX_CTF_RA8:
    case GX_CTF_RG8:
    case GX_CTF_GB8:
    case GX_CTF_Z16L:
        tileShiftX = 2;
        tileShiftY = 2;
        break;
    default:
        tileShiftX = tileShiftY = 0;
        break;
    }

    if (format == GX_TF_RGBA8 || format == GX_TF_Z24X8) {
        tileBytes = 64;
    } else {
        tileBytes = 32;
    }

    if (mipmap == GX_TRUE) {
        bufferSize = 0;
        for (level = 0; level < max_lod; level++) {
            nx = (width + (1 << tileShiftX) - 1) >> tileShiftX;
            ny = (height + (1 << tileShiftY) - 1) >> tileShiftY;
            bufferSize += tileBytes * (nx * ny);
            if (width == 1 && height == 1) {
                break;
            }
            width = (width > 1) ? width >> 1 : 1;
            height = (height > 1) ? height >> 1 : 1;
        }
    } else {
        nx = (width + (1 << tileShiftX) - 1) >> tileShiftX;
        ny = (height + (1 << tileShiftY) - 1) >> tileShiftY;
        bufferSize = nx * ny * tileBytes;
    }

    return bufferSize;
}

void fn_803CD70C(s32 fmt, u16 wd, u16 ht, u32* rowTiles, u32* colTiles, u32* cmpTiles) { /* __GetImageTileCount */
    u32 texRowShift;
    u32 texColShift;

    switch (fmt) {
    case GX_TF_I4:
    case GX_TF_C4:
    case GX_TF_CMPR:
    case GX_CTF_R4:
    case GX_CTF_Z4:
        texRowShift = 3;
        texColShift = 3;
        break;
    case GX_TF_I8:
    case GX_TF_IA4:
    case GX_TF_C8:
    case GX_TF_Z8:
    case GX_CTF_RA4:
    case GX_TF_A8:
    case GX_CTF_R8:
    case GX_CTF_G8:
    case GX_CTF_B8:
    case GX_CTF_Z8M:
    case GX_CTF_Z8L:
        texRowShift = 3;
        texColShift = 2;
        break;
    case GX_TF_IA8:
    case GX_TF_RGB565:
    case GX_TF_RGB5A3:
    case GX_TF_RGBA8:
    case GX_TF_C14X2:
    case GX_TF_Z16:
    case GX_TF_Z24X8:
    case GX_CTF_RA8:
    case GX_CTF_RG8:
    case GX_CTF_GB8:
    case GX_CTF_Z16L:
        texRowShift = 2;
        texColShift = 2;
        break;
    default:
        texRowShift = texColShift = 0;
        break;
    }

    if (wd == 0) {
        wd = 1;
    }
    if (ht == 0) {
        ht = 1;
    }
    *rowTiles = (wd + (1 << texRowShift) - 1) >> texRowShift;
    *colTiles = (ht + (1 << texColShift) - 1) >> texColShift;
    *cmpTiles = (fmt == GX_TF_RGBA8 || fmt == GX_TF_Z24X8) ? 2 : 1;
}

static u8 GX2HWFiltConv[6] = { 0x00, 0x04, 0x01, 0x05, 0x02, 0x06 };

void GXInitTexObj(GXTexObj* obj, void* image_ptr, u16 width, u16 height, u32 format, u32 wrap_s, u32 wrap_t, u8 mipmap) {
    u32 imageBase;
    u32 maxLOD;
    u16 rowT;
    u16 colT;
    u32 rowC;
    u32 colC;
    __GXTexObjInt* t = (__GXTexObjInt*)obj;

    memset(t, 0, 0x20);
    OLD_SET_REG_FIELD(t->mode0, 2, 0, wrap_s);
    OLD_SET_REG_FIELD(t->mode0, 2, 2, wrap_t);
    OLD_SET_REG_FIELD(t->mode0, 1, 4, 1);

    if (mipmap) {
        u8 lmax;
        t->flags |= 1;

        if (format == 8 || format == 9 || format == 10) {
            OLD_SET_REG_FIELD(t->mode0, 3, 5, 5);
        } else {
            OLD_SET_REG_FIELD(t->mode0, 3, 5, 6);
        }

        if (width > height) {
            maxLOD = 31 - __cntlzw(width);
        } else {
            maxLOD = 31 - __cntlzw(height);
        }

        lmax = 16.0f * maxLOD;
        OLD_SET_REG_FIELD(t->mode1, 8, 8, lmax);
    } else {
        OLD_SET_REG_FIELD(t->mode0, 3, 5, 4);
    }

    t->fmt = format;
    OLD_SET_REG_FIELD(t->image0, 10, 0, width - 1);
    OLD_SET_REG_FIELD(t->image0, 10, 10, height - 1);
    OLD_SET_REG_FIELD(t->image0, 4, 20, format & 0xF);
    imageBase = (u32)((u32)image_ptr >> 5) & 0x01FFFFFF;
    OLD_SET_REG_FIELD(t->image3, 21, 0, imageBase);

    switch (format & 0xF) {
    case GX_TF_I4:
    case 8:
        t->loadFmt = 1;
        rowT = 3;
        colT = 3;
        break;
    case GX_TF_I8:
    case GX_TF_IA4:
    case 9:
        t->loadFmt = 2;
        rowT = 3;
        colT = 2;
        break;
    case GX_TF_IA8:
    case GX_TF_RGB565:
    case GX_TF_RGB5A3:
    case 10:
        t->loadFmt = 2;
        rowT = 2;
        colT = 2;
        break;
    case GX_TF_RGBA8:
        t->loadFmt = 3;
        rowT = 2;
        colT = 2;
        break;
    case GX_TF_CMPR:
        t->loadFmt = 0;
        rowT = 3;
        colT = 3;
        break;
    default:
        t->loadFmt = 2;
        rowT = 2;
        colT = 2;
        break;
    }

    rowC = (width + (1 << rowT) - 1) >> rowT;
    colC = (height + (1 << colT) - 1) >> colT;
    t->loadCnt = (rowC * colC) & 0x7FFF;
    t->flags |= 2;
}

void GXInitTexObjCI(GXTexObj* obj, void* image_ptr, u16 width, u16 height, u32 format, u32 wrap_s, u32 wrap_t, u8 mipmap, u32 tlut_name) {
    __GXTexObjInt* t = (__GXTexObjInt*)obj;

    GXInitTexObj(obj, image_ptr, width, height, format, wrap_s, wrap_t, mipmap);
    t->flags &= 0xFFFFFFFD;
    t->tlutName = tlut_name;
}

void fn_803CDA90(GXTexObj* obj, u32 min_filt, s32 mag_filt, f32 min_lod, f32 max_lod, f32 lod_bias, u8 bias_clamp, u8 do_edge_lod, u32 max_aniso) { /* GXInitTexObjLOD */
    u8 lbias;
    u8 lmin;
    u8 lmax;
    __GXTexObjInt* t = (__GXTexObjInt*)obj;

    if (lod_bias < -4.0f) {
        lod_bias = -4.0f;
    } else if (lod_bias >= 4.0f) {
        lod_bias = 3.99f;
    }

    lbias = 32.0f * lod_bias;
    OLD_SET_REG_FIELD(t->mode0, 8, 9, lbias);
    OLD_SET_REG_FIELD(t->mode0, 1, 4, (mag_filt == GX_LINEAR) ? 1 : 0);
    OLD_SET_REG_FIELD(t->mode0, 3, 5, GX2HWFiltConv[min_filt]);
    OLD_SET_REG_FIELD(t->mode0, 1, 8, do_edge_lod ? 0 : 1);
    OLD_SET_REG_FIELD(t->mode0, 1, 17, 0);
    OLD_SET_REG_FIELD(t->mode0, 1, 18, 0);
    OLD_SET_REG_FIELD(t->mode0, 2, 19, max_aniso);
    OLD_SET_REG_FIELD(t->mode0, 1, 21, bias_clamp);

    if (min_lod < 0.0f) {
        min_lod = 0.0f;
    } else if (min_lod > 10.0f) {
        min_lod = 10.0f;
    }
    lmin = 16.0f * min_lod;
    if (max_lod < 0.0f) {
        max_lod = 0.0f;
    } else if (max_lod > 10.0f) {
        max_lod = 10.0f;
    }
    lmax = 16.0f * max_lod;
    OLD_SET_REG_FIELD(t->mode1, 8, 0, lmin);
    OLD_SET_REG_FIELD(t->mode1, 8, 8, lmax);
}

u16 fn_803CDC24(const GXTexObj* obj) { /* GXGetTexObjWidth */
    const __GXTexObjInt* t = (const __GXTexObjInt*)obj;
    return (u32)GET_REG_FIELD(t->image0, 10, 0) + 1;
}

u16 fn_803CDC34(const GXTexObj* obj) { /* GXGetTexObjHeight */
    const __GXTexObjInt* t = (const __GXTexObjInt*)obj;
    return (u32)GET_REG_FIELD(t->image0, 10, 10) + 1;
}

u32 fn_803CDC44(const GXTexObj* obj) { /* GXGetTexObjFmt */
    const __GXTexObjInt* t = (const __GXTexObjInt*)obj;
    return t->fmt;
}

static u8 GXTexMode0Ids[8] = { 0x80, 0x81, 0x82, 0x83, 0xA0, 0xA1, 0xA2, 0xA3 };
static u8 GXTexMode1Ids[8] = { 0x84, 0x85, 0x86, 0x87, 0xA4, 0xA5, 0xA6, 0xA7 };
static u8 GXTexImage0Ids[8] = { 0x88, 0x89, 0x8A, 0x8B, 0xA8, 0xA9, 0xAA, 0xAB };
static u8 GXTexImage1Ids[8] = { 0x8C, 0x8D, 0x8E, 0x8F, 0xAC, 0xAD, 0xAE, 0xAF };
static u8 GXTexImage2Ids[8] = { 0x90, 0x91, 0x92, 0x93, 0xB0, 0xB1, 0xB2, 0xB3 };
static u8 GXTexImage3Ids[8] = { 0x94, 0x95, 0x96, 0x97, 0xB4, 0xB5, 0xB6, 0xB7 };
static u8 GXTexTlutIds[8] = { 0x98, 0x99, 0x9A, 0x9B, 0xB8, 0xB9, 0xBA, 0xBB };

void GXLoadTexObjPreLoaded(GXTexObj* obj, GXTexRegion* region, u32 id) {
    __GXTlutRegionInt* tlr;
    __GXTexObjInt* t = (__GXTexObjInt*)obj;
    __GXTexRegionInt* r = (__GXTexRegionInt*)region;

    OLD_SET_REG_FIELD(t->mode0, 8, 24, GXTexMode0Ids[id]);
    OLD_SET_REG_FIELD(t->mode1, 8, 24, GXTexMode1Ids[id]);
    OLD_SET_REG_FIELD(t->image0, 8, 24, GXTexImage0Ids[id]);
    OLD_SET_REG_FIELD(r->image1, 8, 24, GXTexImage1Ids[id]);
    OLD_SET_REG_FIELD(r->image2, 8, 24, GXTexImage2Ids[id]);
    OLD_SET_REG_FIELD(t->image3, 8, 24, GXTexImage3Ids[id]);

    GX_WRITE_RAS_REG(t->mode0);
    GX_WRITE_RAS_REG(t->mode1);
    GX_WRITE_RAS_REG(t->image0);
    GX_WRITE_RAS_REG(r->image1);
    GX_WRITE_RAS_REG(r->image2);
    GX_WRITE_RAS_REG(t->image3);

    if (!(t->flags & 2)) {
        tlr = (__GXTlutRegionInt*)gx->tlutRegionCallback(t->tlutName);

        OLD_SET_REG_FIELD(tlr->tlutObj.tlut, 8, 24, GXTexTlutIds[id]);
        GX_WRITE_RAS_REG(tlr->tlutObj.tlut);
    }

    gx->tImage0[id] = t->image0;
    gx->tMode0[id] = t->mode0;
    gx->dirtyState |= 1;
    gx->bpSentNot = 0;
}

void GXLoadTexObj(GXTexObj* obj, u32 id) {
    GXTexRegion* r;

    r = gx->texRegionCallback(obj, id);
    GXLoadTexObjPreLoaded(obj, r, id);
}

void GXInitTlutObj(GXTlutObj* tlut_obj, void* lut, u32 fmt, u16 n_entries) {
    __GXTlutObjInt* t = (__GXTlutObjInt*)tlut_obj;

    t->tlut = 0;
    OLD_SET_REG_FIELD(t->tlut, 2, 10, fmt);
    OLD_SET_REG_FIELD(t->loadTlut0, 21, 0, ((u32)lut & 0x3FFFFFFF) >> 5);
    OLD_SET_REG_FIELD(t->loadTlut0, 8, 24, 0x64);
    t->numEntries = n_entries;
}

void GXLoadTlut(GXTlutObj* tlut_obj, u32 tlut_name) {
    __GXTlutRegionInt* r;
    u32 tlut_offset;
    __GXTlutObjInt* t = (__GXTlutObjInt*)tlut_obj;

    r = (__GXTlutRegionInt*)gx->tlutRegionCallback(tlut_name);

    __GXFlushTextureState();
    GX_WRITE_RAS_REG(t->loadTlut0);
    GX_WRITE_RAS_REG(r->loadTlut1);
    __GXFlushTextureState();
    tlut_offset = r->loadTlut1 & 0x3FF;
    OLD_SET_REG_FIELD(t->tlut, 10, 0, tlut_offset);
    r->tlutObj = *t;
}

void GXInitTexCacheRegion(GXTexRegion* region, u8 is_32b_mipmap, u32 tmem_even, u32 size_even, u32 tmem_odd, u32 size_odd) {
    u32 WidthExp2;
    __GXTexRegionInt* t = (__GXTexRegionInt*)region;

    switch (size_even) {
    case GX_TEXCACHE_32K:
        WidthExp2 = 3;
        break;
    case GX_TEXCACHE_128K:
        WidthExp2 = 4;
        break;
    case GX_TEXCACHE_512K:
        WidthExp2 = 5;
        break;
    default:
        break;
    }

    t->image1 = 0;
    OLD_SET_REG_FIELD(t->image1, 15, 0, tmem_even >> 5);
    OLD_SET_REG_FIELD(t->image1, 3, 15, WidthExp2);
    OLD_SET_REG_FIELD(t->image1, 3, 18, WidthExp2);
    OLD_SET_REG_FIELD(t->image1, 1, 21, 0);

    switch (size_odd) {
    case GX_TEXCACHE_32K:
        WidthExp2 = 3;
        break;
    case GX_TEXCACHE_128K:
        WidthExp2 = 4;
        break;
    case GX_TEXCACHE_512K:
        WidthExp2 = 5;
        break;
    case GX_TEXCACHE_NONE:
        WidthExp2 = 0;
        break;
    default:
        break;
    }

    t->image2 = 0;
    OLD_SET_REG_FIELD(t->image2, 15, 0, tmem_odd >> 5);
    OLD_SET_REG_FIELD(t->image2, 3, 15, WidthExp2);
    OLD_SET_REG_FIELD(t->image2, 3, 18, WidthExp2);
    t->is32bMipmap = is_32b_mipmap;
    t->isCached = 1;
}

void GXInitTlutRegion(GXTlutRegion* region, u32 tmem_addr, u32 tlut_size) {
    __GXTlutRegionInt* t = (__GXTlutRegionInt*)region;

    t->loadTlut1 = 0;
    tmem_addr -= 0x80000;
    OLD_SET_REG_FIELD(t->loadTlut1, 10, 0, tmem_addr >> 9);
    OLD_SET_REG_FIELD(t->loadTlut1, 11, 10, tlut_size);
    OLD_SET_REG_FIELD(t->loadTlut1, 8, 24, 0x65);
}

void GXInvalidateTexAll(void) {
    u32 reg0;
    u32 reg1;

    reg0 = 0x66001000;
    reg1 = 0x66001100;
    __GXFlushTextureState();
    GX_WRITE_RAS_REG(reg0);
    GX_WRITE_RAS_REG(reg1);
    __GXFlushTextureState();
}

GXTexRegionCallback fn_803CE0CC(GXTexRegionCallback f) { /* GXSetTexRegionCallback */
    GXTexRegionCallback oldcb = gx->texRegionCallback;

    gx->texRegionCallback = f;
    return oldcb;
}

GXTlutRegionCallback fn_803CE0E0(GXTlutRegionCallback f) { /* GXSetTlutRegionCallback */
    GXTlutRegionCallback oldcb = gx->tlutRegionCallback;

    gx->tlutRegionCallback = f;
    return oldcb;
}

#pragma dont_inline on
void fn_803CE0F4(u32 tmap, u32 tcoord) { /* __SetSURegs */
    u32 w;
    u32 h;
    u8 s_bias;
    u8 t_bias;

    w = GET_REG_FIELD(gx->tImage0[tmap], 10, 0);
    h = GET_REG_FIELD(gx->tImage0[tmap], 10, 10);
    OLD_SET_REG_FIELD(gx->suTs0[tcoord], 16, 0, w);
    OLD_SET_REG_FIELD(gx->suTs1[tcoord], 16, 0, h);
    s_bias = GET_REG_FIELD(gx->tMode0[tmap], 2, 0) == 1;
    t_bias = GET_REG_FIELD(gx->tMode0[tmap], 2, 2) == 1;
    OLD_SET_REG_FIELD(gx->suTs0[tcoord], 1, 16, s_bias);
    OLD_SET_REG_FIELD(gx->suTs1[tcoord], 1, 16, t_bias);
    GX_WRITE_RAS_REG(gx->suTs0[tcoord]);
    GX_WRITE_RAS_REG(gx->suTs1[tcoord]);
    gx->bpSentNot = 0;
}
#pragma dont_inline reset

void __GXSetSUTexRegs(void) {
    u32 nStages;
    u32 nIndStages;
    u32 i;
    u32 map;
    u32 tmap;
    u32 coord;
    u32* ptref;

    if (gx->tcsManEnab != 0xFF) {
        nStages = GET_REG_FIELD(gx->genMode, 4, 10) + 1;
        nIndStages = GET_REG_FIELD(gx->genMode, 3, 16);
        for (i = 0; i < nIndStages; i++) {
            switch (i) {
            case 0:
                tmap = GET_REG_FIELD(gx->iref, 3, 0);
                coord = GET_REG_FIELD(gx->iref, 3, 3);
                break;
            case 1:
                tmap = GET_REG_FIELD(gx->iref, 3, 6);
                coord = GET_REG_FIELD(gx->iref, 3, 9);
                break;
            case 2:
                tmap = GET_REG_FIELD(gx->iref, 3, 12);
                coord = GET_REG_FIELD(gx->iref, 3, 15);
                break;
            case 3:
                tmap = GET_REG_FIELD(gx->iref, 3, 18);
                coord = GET_REG_FIELD(gx->iref, 3, 21);
                break;
            }
            if (!(gx->tcsManEnab & (1 << coord))) {
                fn_803CE0F4(tmap, coord);
            }
        }

        for (i = 0; i < nStages; i++) {
            ptref = &gx->tref[i / 2];
            map = gx->texmapId[i];
            tmap = map & 0xFFFFFEFF;
            if (i & 1) {
                coord = GET_REG_FIELD(*ptref, 3, 15);
            } else {
                coord = GET_REG_FIELD(*ptref, 3, 3);
            }
            if ((tmap != 0xFF) && !(gx->tcsManEnab & (1 << coord)) && (gx->tevTcEnab & (1 << i))) {
                fn_803CE0F4(tmap, coord);
            }
        }
    }
}

void __GXSetTmemConfig(u32 config) {
    switch (config) {
    case 1:
        GX_WRITE_RAS_REG(0x8c0d8000);
        GX_WRITE_RAS_REG(0x900dc000);

        GX_WRITE_RAS_REG(0x8d0d8800);
        GX_WRITE_RAS_REG(0x910dc800);

        GX_WRITE_RAS_REG(0x8e0d9000);
        GX_WRITE_RAS_REG(0x920dd000);

        GX_WRITE_RAS_REG(0x8f0d9800);
        GX_WRITE_RAS_REG(0x930dd800);

        GX_WRITE_RAS_REG(0xac0da000);
        GX_WRITE_RAS_REG(0xb00de000);

        GX_WRITE_RAS_REG(0xad0da800);
        GX_WRITE_RAS_REG(0xb10de800);

        GX_WRITE_RAS_REG(0xae0db000);
        GX_WRITE_RAS_REG(0xb20df000);

        GX_WRITE_RAS_REG(0xaf0db800);
        GX_WRITE_RAS_REG(0xb30df800);
        break;
    case 0:
    default:
        GX_WRITE_RAS_REG(0x8c0d8000);
        GX_WRITE_RAS_REG(0x900dc000);

        GX_WRITE_RAS_REG(0x8d0d8400);
        GX_WRITE_RAS_REG(0x910dc400);

        GX_WRITE_RAS_REG(0x8e0d8800);
        GX_WRITE_RAS_REG(0x920dc800);

        GX_WRITE_RAS_REG(0x8f0d8c00);
        GX_WRITE_RAS_REG(0x930dcc00);

        GX_WRITE_RAS_REG(0xac0d9000);
        GX_WRITE_RAS_REG(0xb00dd000);

        GX_WRITE_RAS_REG(0xad0d9400);
        GX_WRITE_RAS_REG(0xb10dd400);

        GX_WRITE_RAS_REG(0xae0d9800);
        GX_WRITE_RAS_REG(0xb20dd800);

        GX_WRITE_RAS_REG(0xaf0d9c00);
        GX_WRITE_RAS_REG(0xb30ddc00);
        break;
    }
}

#pragma dont_inline on
void GXSetTevIndirect(u32 tev_stage, u32 ind_stage, u32 format, u32 bias_sel, u32 matrix_sel, u32 wrap_s, u32 wrap_t, u8 add_prev, u8 utc_lod, u32 alpha_sel) {
    u32 reg;

    reg = 0;
    OLD_SET_REG_FIELD(reg, 2, 0, ind_stage);
    OLD_SET_REG_FIELD(reg, 2, 2, format);
    OLD_SET_REG_FIELD(reg, 3, 4, bias_sel);
    OLD_SET_REG_FIELD(reg, 2, 7, alpha_sel);
    OLD_SET_REG_FIELD(reg, 4, 9, matrix_sel);
    OLD_SET_REG_FIELD(reg, 3, 13, wrap_s);
    OLD_SET_REG_FIELD(reg, 3, 16, wrap_t);
    OLD_SET_REG_FIELD(reg, 1, 19, utc_lod);
    OLD_SET_REG_FIELD(reg, 1, 20, add_prev);
    OLD_SET_REG_FIELD(reg, 8, 24, tev_stage + 16);
    GX_WRITE_RAS_REG(reg);
    gx->bpSentNot = 0;
}
#pragma dont_inline reset

void fn_803CE604(u32 mtx_id, const f32 offset[2][3], s8 scale_exp) { /* GXSetIndTexMtx */
    s32 mtx[6];
    u32 reg;
    u32 id;

    switch (mtx_id) {
    case 1: /* GX_ITM_0 */
    case 2: /* GX_ITM_1 */
    case 3: /* GX_ITM_2 */
        id = mtx_id - 1;
        break;
    case 5: /* GX_ITM_S0 */
    case 6: /* GX_ITM_S1 */
    case 7: /* GX_ITM_S2 */
        id = mtx_id - 5;
        break;
    case 9: /* GX_ITM_T0 */
    case 10: /* GX_ITM_T1 */
    case 11: /* GX_ITM_T2 */
        id = mtx_id - 9;
        break;
    default:
        id = 0;
        break;
    }

    mtx[0] = (int)(1024.0f * offset[0][0]) & 0x7FF;
    mtx[1] = (int)(1024.0f * offset[1][0]) & 0x7FF;
    scale_exp += 17;
    reg = 0;
    OLD_SET_REG_FIELD(reg, 11, 0, mtx[0]);
    OLD_SET_REG_FIELD(reg, 11, 11, mtx[1]);
    OLD_SET_REG_FIELD(reg, 2, 22, scale_exp & 3);
    OLD_SET_REG_FIELD(reg, 8, 24, id * 3 + 6);
    GX_WRITE_RAS_REG(reg);

    mtx[2] = (int)(1024.0f * offset[0][1]) & 0x7FF;
    mtx[3] = (int)(1024.0f * offset[1][1]) & 0x7FF;
    reg = 0;
    OLD_SET_REG_FIELD(reg, 11, 0, mtx[2]);
    OLD_SET_REG_FIELD(reg, 11, 11, mtx[3]);
    OLD_SET_REG_FIELD(reg, 2, 22, (scale_exp >> 2) & 3);
    OLD_SET_REG_FIELD(reg, 8, 24, id * 3 + 7);
    GX_WRITE_RAS_REG(reg);

    mtx[4] = (int)(1024.0f * offset[0][2]) & 0x7FF;
    mtx[5] = (int)(1024.0f * offset[1][2]) & 0x7FF;
    reg = 0;
    OLD_SET_REG_FIELD(reg, 11, 0, mtx[4]);
    OLD_SET_REG_FIELD(reg, 11, 11, mtx[5]);
    OLD_SET_REG_FIELD(reg, 2, 22, (scale_exp >> 4) & 3);
    OLD_SET_REG_FIELD(reg, 8, 24, id * 3 + 8);
    GX_WRITE_RAS_REG(reg);

    gx->bpSentNot = 0;
}

void GXSetIndTexCoordScale(u32 ind_stage, u32 scale_s, u32 scale_t) {
    switch (ind_stage) {
    case GX_INDTEXSTAGE0:
        OLD_SET_REG_FIELD(gx->IndTexScale0, 4, 0, scale_s);
        OLD_SET_REG_FIELD(gx->IndTexScale0, 4, 4, scale_t);
        OLD_SET_REG_FIELD(gx->IndTexScale0, 8, 24, 0x25);
        GX_WRITE_RAS_REG(gx->IndTexScale0);
        break;
    case GX_INDTEXSTAGE1:
        OLD_SET_REG_FIELD(gx->IndTexScale0, 4, 8, scale_s);
        OLD_SET_REG_FIELD(gx->IndTexScale0, 4, 12, scale_t);
        OLD_SET_REG_FIELD(gx->IndTexScale0, 8, 24, 0x25);
        GX_WRITE_RAS_REG(gx->IndTexScale0);
        break;
    case GX_INDTEXSTAGE2:
        OLD_SET_REG_FIELD(gx->IndTexScale1, 4, 0, scale_s);
        OLD_SET_REG_FIELD(gx->IndTexScale1, 4, 4, scale_t);
        OLD_SET_REG_FIELD(gx->IndTexScale1, 8, 24, 0x26);
        GX_WRITE_RAS_REG(gx->IndTexScale1);
        break;
    case GX_INDTEXSTAGE3:
        OLD_SET_REG_FIELD(gx->IndTexScale1, 4, 8, scale_s);
        OLD_SET_REG_FIELD(gx->IndTexScale1, 4, 12, scale_t);
        OLD_SET_REG_FIELD(gx->IndTexScale1, 8, 24, 0x26);
        GX_WRITE_RAS_REG(gx->IndTexScale1);
        break;
    default:
        break;
    }
    gx->bpSentNot = 0;
}

void fn_803CE8E0(u32 ind_stage, u32 tex_coord, u32 tex_map) { /* GXSetIndTexOrder */
    switch (ind_stage) {
    case GX_INDTEXSTAGE0:
        OLD_SET_REG_FIELD(gx->iref, 3, 0, tex_map);
        OLD_SET_REG_FIELD(gx->iref, 3, 3, tex_coord);
        break;
    case GX_INDTEXSTAGE1:
        OLD_SET_REG_FIELD(gx->iref, 3, 6, tex_map);
        OLD_SET_REG_FIELD(gx->iref, 3, 9, tex_coord);
        break;
    case GX_INDTEXSTAGE2:
        OLD_SET_REG_FIELD(gx->iref, 3, 12, tex_map);
        OLD_SET_REG_FIELD(gx->iref, 3, 15, tex_coord);
        break;
    case GX_INDTEXSTAGE3:
        OLD_SET_REG_FIELD(gx->iref, 3, 18, tex_map);
        OLD_SET_REG_FIELD(gx->iref, 3, 21, tex_coord);
        break;
    default:
        break;
    }
    GX_WRITE_RAS_REG(gx->iref);
    gx->dirtyState |= 3;
    gx->bpSentNot = 0;
}

void GXSetNumIndStages(u8 nIndStages) {
    OLD_SET_REG_FIELD(gx->genMode, 3, 16, nIndStages);
    gx->dirtyState |= 6;
}

void GXSetTevDirect(u32 tev_stage) {
    GXSetTevIndirect(tev_stage, GX_INDTEXSTAGE0, GX_ITF_8, GX_ITB_NONE, GX_ITM_OFF, GX_ITW_OFF, GX_ITW_OFF, GX_FALSE, GX_FALSE, GX_ITBA_OFF);
}

void __GXUpdateBPMask(void) {
    u32 mask;
    u32 tmap;
    u32 i;

    mask = 0;
    for (i = 0; i < GET_REG_FIELD(gx->genMode, 3, 16); i++) {
        switch (i) {
        case 0:
            tmap = GET_REG_FIELD(gx->iref, 3, 0);
            break;
        case 1:
            tmap = GET_REG_FIELD(gx->iref, 3, 6);
            break;
        case 2:
            tmap = GET_REG_FIELD(gx->iref, 3, 12);
            break;
        case 3:
            tmap = GET_REG_FIELD(gx->iref, 3, 18);
            break;
        }
        mask |= 1 << tmap;
    }

    if ((u8)gx->bpMask != mask) {
        OLD_SET_REG_FIELD(gx->bpMask, 8, 0, mask);
        GX_WRITE_RAS_REG(gx->bpMask);
        gx->bpSentNot = 0;
    }
}

#pragma dont_inline on
void __GXFlushTextureState(void) {
    GX_WRITE_RAS_REG(gx->bpMask);
    gx->bpSentNot = 0;
}
#pragma dont_inline reset

static struct {
    u32 rid : 8;
    u32 dest : 2;
    u32 shift : 2;
    u32 clamp : 1;
    u32 sub : 1;
    u32 bias : 2;
    u32 sela : 4;
    u32 selb : 4;
    u32 selc : 4;
    u32 seld : 4;
} TEVCOpTableST0[5] = {
    { 192, 0, 0, 1, 0, 0, 15, 8, 10, 15 },
    { 192, 0, 0, 1, 0, 0, 10, 8, 9, 15 },
    { 192, 0, 0, 1, 0, 0, 10, 12, 8, 15 },
    { 192, 0, 0, 1, 0, 0, 15, 15, 15, 8 },
    { 192, 0, 0, 1, 0, 0, 15, 15, 15, 10 },
};

static struct {
    u32 rid : 8;
    u32 dest : 2;
    u32 shift : 2;
    u32 clamp : 1;
    u32 sub : 1;
    u32 bias : 2;
    u32 sela : 4;
    u32 selb : 4;
    u32 selc : 4;
    u32 seld : 4;
} TEVCOpTableST1[5] = {
    { 192, 0, 0, 1, 0, 0, 15, 8, 0, 15 },
    { 192, 0, 0, 1, 0, 0, 0, 8, 9, 15 },
    { 192, 0, 0, 1, 0, 0, 0, 12, 8, 15 },
    { 192, 0, 0, 1, 0, 0, 15, 15, 15, 8 },
    { 192, 0, 0, 1, 0, 0, 15, 15, 15, 0 },
};

static struct {
    u32 rid : 8;
    u32 dest : 2;
    u32 shift : 2;
    u32 clamp : 1;
    u32 sub : 1;
    u32 bias : 2;
    u32 sela : 3;
    u32 selb : 3;
    u32 selc : 3;
    u32 seld : 3;
    u32 swap : 2;
    u32 mode : 2;
} TEVAOpTableST0[5] = {
    { 193, 0, 0, 1, 0, 0, 7, 4, 5, 7, 0, 0 },
    { 193, 0, 0, 1, 0, 0, 7, 7, 7, 5, 0, 0 },
    { 193, 0, 0, 1, 0, 0, 7, 4, 5, 7, 0, 0 },
    { 193, 0, 0, 1, 0, 0, 7, 7, 7, 4, 0, 0 },
    { 193, 0, 0, 1, 0, 0, 7, 7, 7, 5, 0, 0 },
};

static struct {
    u32 rid : 8;
    u32 dest : 2;
    u32 shift : 2;
    u32 clamp : 1;
    u32 sub : 1;
    u32 bias : 2;
    u32 sela : 3;
    u32 selb : 3;
    u32 selc : 3;
    u32 seld : 3;
    u32 swap : 2;
    u32 mode : 2;
} TEVAOpTableST1[5] = {
    { 193, 0, 0, 1, 0, 0, 7, 4, 0, 7, 0, 0 },
    { 193, 0, 0, 1, 0, 0, 7, 7, 7, 0, 0, 0 },
    { 193, 0, 0, 1, 0, 0, 7, 4, 0, 7, 0, 0 },
    { 193, 0, 0, 1, 0, 0, 7, 7, 7, 4, 0, 0 },
    { 193, 0, 0, 1, 0, 0, 7, 7, 7, 0, 0, 0 },
};

void GXSetTevOp(u32 id, u32 mode) {
    u32* ctmp;
    u32* atmp;
    u32 tevReg;

    if (id == GX_TEVSTAGE0) {
        ctmp = (u32*)TEVCOpTableST0 + mode;
        atmp = (u32*)TEVAOpTableST0 + mode;
    } else {
        ctmp = (u32*)TEVCOpTableST1 + mode;
        atmp = (u32*)TEVAOpTableST1 + mode;
    }

    tevReg = gx->tevc[id];
    tevReg = (*ctmp & ~0xFF000000) | (tevReg & 0xFF000000);
    GX_WRITE_RAS_REG(tevReg);
    gx->tevc[id] = tevReg;

    tevReg = gx->teva[id];
    tevReg = (*atmp & ~0xFF00000F) | (tevReg & 0xFF00000F);
    GX_WRITE_RAS_REG(tevReg);
    gx->teva[id] = tevReg;

    gx->bpSentNot = 0;
}

void GXSetTevColorIn(u32 stage, u32 a, u32 b, u32 c, u32 d) {
    u32 tevReg;

    tevReg = gx->tevc[stage];
    SET_REG_FIELD(tevReg, 4, 12, a);
    SET_REG_FIELD(tevReg, 4, 8, b);
    SET_REG_FIELD(tevReg, 4, 4, c);
    SET_REG_FIELD(tevReg, 4, 0, d);

    GX_WRITE_RAS_REG(tevReg);
    gx->tevc[stage] = tevReg;
    gx->bpSentNot = 0;
}

void GXSetTevAlphaIn(u32 stage, u32 a, u32 b, u32 c, u32 d) {
    u32 tevReg;

    tevReg = gx->teva[stage];
    SET_REG_FIELD(tevReg, 3, 13, a);
    SET_REG_FIELD(tevReg, 3, 10, b);
    SET_REG_FIELD(tevReg, 3, 7, c);
    SET_REG_FIELD(tevReg, 3, 4, d);

    GX_WRITE_RAS_REG(tevReg);
    gx->teva[stage] = tevReg;
    gx->bpSentNot = 0;
}

void fn_803CEC68(u32 stage, u32 op, u32 bias, u32 scale, u8 clamp, u32 out_reg) { /* GXSetTevColorOp */
    u32 tevReg;

    tevReg = gx->tevc[stage];
    SET_REG_FIELD(tevReg, 1, 18, op & 1);
    if (op <= 1) {
        SET_REG_FIELD(tevReg, 2, 20, scale);
        SET_REG_FIELD(tevReg, 2, 16, bias);
    } else {
        SET_REG_FIELD(tevReg, 2, 20, (op >> 1) & 3);
        SET_REG_FIELD(tevReg, 2, 16, 3);
    }
    SET_REG_FIELD(tevReg, 1, 19, clamp & 0xFF);
    SET_REG_FIELD(tevReg, 2, 22, out_reg);

    GX_WRITE_RAS_REG(tevReg);
    gx->tevc[stage] = tevReg;
    gx->bpSentNot = 0;
}

void fn_803CECD0(u32 stage, u32 op, u32 bias, u32 scale, u8 clamp, u32 out_reg) { /* GXSetTevAlphaOp */
    u32 tevReg;

    tevReg = gx->teva[stage];
    SET_REG_FIELD(tevReg, 1, 18, op & 1);
    if (op <= 1) {
        SET_REG_FIELD(tevReg, 2, 20, scale);
        SET_REG_FIELD(tevReg, 2, 16, bias);
    } else {
        SET_REG_FIELD(tevReg, 2, 20, (op >> 1) & 3);
        SET_REG_FIELD(tevReg, 2, 16, 3);
    }
    SET_REG_FIELD(tevReg, 1, 19, clamp & 0xFF);
    SET_REG_FIELD(tevReg, 2, 22, out_reg);

    GX_WRITE_RAS_REG(tevReg);
    gx->teva[stage] = tevReg;
    gx->bpSentNot = 0;
}

void GXSetTevColor(u32 id, GXColor color) {
    u32 regRA;
    u32 regBG;

    regRA = (0xE0 + id * 2) << 24;
    SET_REG_FIELD(regRA, 8, 0, color.r);
    SET_REG_FIELD(regRA, 8, 12, color.a);

    regBG = (0xE1 + id * 2) << 24;
    SET_REG_FIELD(regBG, 8, 0, color.b);
    SET_REG_FIELD(regBG, 8, 12, color.g);

    GX_WRITE_RAS_REG(regRA);
    GX_WRITE_RAS_REG(regBG);
    GX_WRITE_RAS_REG(regBG);
    GX_WRITE_RAS_REG(regBG);

    gx->bpSentNot = 0;
}

void GXSetTevColorS10(u32 id, GXColorS10 color) {
    u32 regRA;
    u32 regBG;

    regRA = (0xE0 + id * 2) << 24;
    SET_REG_FIELD(regRA, 11, 0, color.r & 0x7FF);
    SET_REG_FIELD(regRA, 11, 12, color.a & 0x7FF);

    regBG = (0xE1 + id * 2) << 24;
    SET_REG_FIELD(regBG, 11, 0, color.b & 0x7FF);
    SET_REG_FIELD(regBG, 11, 12, color.g & 0x7FF);

    GX_WRITE_RAS_REG(regRA);
    GX_WRITE_RAS_REG(regBG);
    GX_WRITE_RAS_REG(regBG);
    GX_WRITE_RAS_REG(regBG);

    gx->bpSentNot = 0;
}

void GXSetTevKColor(u32 id, GXColor color) {
    u32 regRA;
    u32 regBG;

    regRA = (0xE0 + id * 2) << 24;
    SET_REG_FIELD(regRA, 8, 0, color.r);
    SET_REG_FIELD(regRA, 8, 12, color.a);
    SET_REG_FIELD(regRA, 4, 20, 8);

    regBG = (0xE1 + id * 2) << 24;
    SET_REG_FIELD(regBG, 8, 0, color.b);
    SET_REG_FIELD(regBG, 8, 12, color.g);
    SET_REG_FIELD(regBG, 4, 20, 8);

    GX_WRITE_RAS_REG(regRA);
    GX_WRITE_RAS_REG(regBG);

    gx->bpSentNot = 0;
}

void GXSetTevKColorSel(s32 stage, u32 sel) {
    u32* Kreg;

    Kreg = &gx->tevKsel[stage >> 1];
    if (stage & 1) {
        OLD_SET_REG_FIELD(*Kreg, 5, 14, sel);
    } else {
        OLD_SET_REG_FIELD(*Kreg, 5, 4, sel);
    }

    GX_WRITE_RAS_REG(*Kreg);
    gx->bpSentNot = 0;
}

void GXSetTevKAlphaSel(s32 stage, u32 sel) {
    u32* Kreg;

    Kreg = &gx->tevKsel[stage >> 1];
    if (stage & 1) {
        OLD_SET_REG_FIELD(*Kreg, 5, 19, sel);
    } else {
        OLD_SET_REG_FIELD(*Kreg, 5, 9, sel);
    }

    GX_WRITE_RAS_REG(*Kreg);
    gx->bpSentNot = 0;
}

void GXSetTevSwapMode(u32 stage, u32 ras_sel, u32 tex_sel) {
    u32* pTevReg;

    pTevReg = &gx->teva[stage];
    OLD_SET_REG_FIELD(*pTevReg, 2, 0, ras_sel);
    OLD_SET_REG_FIELD(*pTevReg, 2, 2, tex_sel);

    GX_WRITE_RAS_REG(*pTevReg);
    gx->bpSentNot = 0;
}

void GXSetTevSwapModeTable(u32 table, u32 red, u32 green, u32 blue, u32 alpha) {
    u32* Kreg;

    Kreg = &gx->tevKsel[table * 2];
    SET_REG_FIELD(*Kreg, 2, 0, red);
    SET_REG_FIELD(*Kreg, 2, 2, green);

    GX_WRITE_RAS_REG(*Kreg);

    Kreg = &gx->tevKsel[table * 2 + 1];
    SET_REG_FIELD(*Kreg, 2, 0, blue);
    SET_REG_FIELD(*Kreg, 2, 2, alpha);

    GX_WRITE_RAS_REG(*Kreg);
    gx->bpSentNot = 0;
}

void kar_grcoll__803cf058(void) { /* GXSetTevClampMode */
}

void GXSetAlphaCompare(u32 comp0, u8 ref0, u32 op, u32 comp1, u8 ref1) {
    u32 reg;

    reg = 0xF3000000;

    OLD_SET_REG_FIELD(reg, 8, 0, ref0);
    OLD_SET_REG_FIELD(reg, 8, 8, ref1);
    OLD_SET_REG_FIELD(reg, 3, 16, comp0);
    OLD_SET_REG_FIELD(reg, 3, 19, comp1);
    OLD_SET_REG_FIELD(reg, 2, 22, op);

    GX_WRITE_RAS_REG(reg);
    gx->bpSentNot = 0;
}

void GXSetZTexture(u32 op, u32 fmt, u32 bias) {
    u32 zenv0;
    u32 zenv1;
    u32 type;

    zenv0 = 0;
    OLD_SET_REG_FIELD(zenv0, 24, 0, bias);
    OLD_SET_REG_FIELD(zenv0, 8, 24, 0xF4);

    zenv1 = 0;
    switch (fmt) {
    case GX_TF_Z8:
        type = 0;
        break;
    case GX_TF_Z16:
        type = 1;
        break;
    case GX_TF_Z24X8:
        type = 2;
        break;
    default:
        type = 2;
        break;
    }

    OLD_SET_REG_FIELD(zenv1, 2, 0, type);
    OLD_SET_REG_FIELD(zenv1, 2, 2, op);
    OLD_SET_REG_FIELD(zenv1, 8, 24, 0xF5);

    GX_WRITE_RAS_REG(zenv0);
    GX_WRITE_RAS_REG(zenv1);
    gx->bpSentNot = 0;
}

void GXSetTevOrder(u32 stage, u32 coord, u32 map, u32 color) {
    u32* ptref;
    u32 tmap;
    u32 tcoord;
    static s32 c2r[] = { 0, 1, 0, 1, 0, 1, 7, 5, 6 };

    ptref = &gx->tref[stage / 2];
    gx->texmapId[stage] = map;

    tmap = map & ~GX_TEX_DISABLE;
    tmap = (tmap >= GX_MAX_TEXMAP) ? GX_TEXMAP0 : tmap;

    if (coord >= GX_MAX_TEXCOORD) {
        tcoord = GX_TEXCOORD0;
        gx->tevTcEnab = gx->tevTcEnab & ~(1 << stage);
    } else {
        tcoord = coord;
        gx->tevTcEnab = gx->tevTcEnab | (1 << stage);
    }

    if (stage & 1) {
        OLD_SET_REG_FIELD(*ptref, 3, 12, tmap);
        OLD_SET_REG_FIELD(*ptref, 3, 15, tcoord);
        OLD_SET_REG_FIELD(*ptref, 3, 19, (color == GX_COLOR_NULL) ? 7 : c2r[color]);
        OLD_SET_REG_FIELD(*ptref, 1, 18, (map != GX_TEXMAP_NULL && !(map & GX_TEX_DISABLE)));
    } else {
        OLD_SET_REG_FIELD(*ptref, 3, 0, tmap);
        OLD_SET_REG_FIELD(*ptref, 3, 3, tcoord);
        OLD_SET_REG_FIELD(*ptref, 3, 7, (color == GX_COLOR_NULL) ? 7 : c2r[color]);
        OLD_SET_REG_FIELD(*ptref, 1, 6, (map != GX_TEXMAP_NULL && !(map & GX_TEX_DISABLE)));
    }

    GX_WRITE_RAS_REG(*ptref);
    gx->bpSentNot = 0;
    gx->dirtyState |= 1;
}

void GXSetNumTevStages(u8 nStages) {
    OLD_SET_REG_FIELD(gx->genMode, 4, 10, nStages - 1);
    gx->dirtyState |= 4;
}

extern f32 sqrtf(f32 x);

void GXSetFog(u32 type, f32 startz, f32 endz, f32 nearz, f32 farz, GXColor color) {
    u32 fogclr;
    u32 fog0;
    u32 fog1;
    u32 fog2;
    u32 fog3;
    f32 A;
    f32 B;
    f32 B_mant;
    f32 C;
    f32 a;
    f32 c;
    u32 B_expn;
    u32 b_m;
    u32 b_s;
    u32 a_hex;
    u32 c_hex;
    u32 fsel;
    u32 proj;
    u32 rgba;

    fogclr = 0;
    fog0 = 0;
    fog1 = 0;
    fog2 = 0;
    fog3 = 0;

    fsel = type & 7;
    proj = (type >> 3) & 1;

    if (proj) {
        if (farz == nearz || endz == startz) {
            a = 0.0f;
            c = 0.0f;
        } else {
            A = (1.0f / (endz - startz));
            a = A * (farz - nearz);
            c = A * (startz - nearz);
        }
    } else {
        if (farz == nearz || endz == startz) {
            A = 0.0f;
            B = 0.5f;
            C = 0.0f;
        } else {
            A = (farz * nearz) / ((farz - nearz) * (endz - startz));
            B = farz / (farz - nearz);
            C = startz / (endz - startz);
        }

        B_mant = B;
        B_expn = 0;
        while (B_mant > 1.0) {
            B_mant /= 2.0f;
            B_expn++;
        }
        while (B_mant > 0.0f && B_mant < 0.5) {
            B_mant *= 2.0f;
            B_expn--;
        }

        a = A / (f32)(1 << (B_expn + 1));
        b_m = 8.388638e6f * B_mant;
        b_s = B_expn + 1;
        c = C;

        OLD_SET_REG_FIELD(fog1, 24, 0, b_m);
        OLD_SET_REG_FIELD(fog1, 8, 24, 0xEF);

        OLD_SET_REG_FIELD(fog2, 5, 0, b_s);
        OLD_SET_REG_FIELD(fog2, 8, 24, 0xF0);
    }

    a_hex = *(u32*)&a;
    c_hex = *(u32*)&c;

    OLD_SET_REG_FIELD(fog0, 11, 0, (a_hex >> 12) & 0x7FF);
    OLD_SET_REG_FIELD(fog0, 8, 11, (a_hex >> 23) & 0xFF);
    OLD_SET_REG_FIELD(fog0, 1, 19, (a_hex >> 31));
    OLD_SET_REG_FIELD(fog0, 8, 24, 0xEE);

    OLD_SET_REG_FIELD(fog3, 11, 0, (c_hex >> 12) & 0x7FF);
    OLD_SET_REG_FIELD(fog3, 8, 11, (c_hex >> 23) & 0xFF);
    OLD_SET_REG_FIELD(fog3, 1, 19, (c_hex >> 31));

    OLD_SET_REG_FIELD(fog3, 1, 20, proj);
    OLD_SET_REG_FIELD(fog3, 3, 21, fsel);
    OLD_SET_REG_FIELD(fog3, 8, 24, 0xF1);

    rgba = *(u32*)&color;
    OLD_SET_REG_FIELD(fogclr, 24, 0, rgba >> 8);
    OLD_SET_REG_FIELD(fogclr, 8, 24, 0xF2);

    GX_WRITE_RAS_REG(fog0);
    GX_WRITE_RAS_REG(fog1);
    GX_WRITE_RAS_REG(fog2);
    GX_WRITE_RAS_REG(fog3);
    GX_WRITE_RAS_REG(fogclr);

    gx->bpSentNot = 0;
}

void fn_803CF558(GXFogAdjTable* table, u16 width, const f32 projmtx[4][4]) { /* GXInitFogAdjTable */
    f32 xi;
    f32 iw;
    f32 rangeVal;
    f32 nearZ;
    f32 sideX;
    u32 i;

    if (0.0f == projmtx[3][3]) {
        nearZ = projmtx[2][3] / (projmtx[2][2] - 1.0f);
        sideX = nearZ / projmtx[0][0];
    } else {
        sideX = 1.0f / projmtx[0][0];
        nearZ = 1.73205f * sideX;
    }

    iw = 2.0f / width;
    for (i = 0; i < 10; i++) {
        xi = (i + 1) << 5;
        xi *= iw;
        xi *= sideX;
        rangeVal = sqrtf(1.0f + ((xi * xi) / (nearZ * nearZ)));
        table->r[i] = (u32)(256.0f * rangeVal) & 0xFFF;
    }
}

void GXSetFogRangeAdj(u8 enable, u16 center, const GXFogAdjTable* table) {
    u32 i;
    u32 range_adj;
    u32 range_c;

    if (enable) {
        for (i = 0; i < 10; i += 2) {
            range_adj = 0;
            OLD_SET_REG_FIELD(range_adj, 12, 0, table->r[i]);
            OLD_SET_REG_FIELD(range_adj, 12, 12, table->r[i + 1]);
            OLD_SET_REG_FIELD(range_adj, 8, 24, (i >> 1) + 0xE9);
            GX_WRITE_RAS_REG(range_adj);
        }
    }
    range_c = 0;
    OLD_SET_REG_FIELD(range_c, 10, 0, center + 342);
    OLD_SET_REG_FIELD(range_c, 1, 10, enable);
    OLD_SET_REG_FIELD(range_c, 8, 24, 0xE8);
    GX_WRITE_RAS_REG(range_c);
    gx->bpSentNot = 0;
}

void GXSetBlendMode(u32 type, u32 src_factor, u32 dst_factor, u32 op) {
    u32 reg;

    reg = gx->cmode0;

    SET_REG_FIELD(reg, 1, 11, (type == GX_BM_SUBTRACT));
    SET_REG_FIELD(reg, 1, 0, type);
    SET_REG_FIELD(reg, 1, 1, (type == GX_BM_LOGIC));
    SET_REG_FIELD(reg, 4, 12, op);
    SET_REG_FIELD(reg, 3, 8, src_factor);
    SET_REG_FIELD(reg, 3, 5, dst_factor);
    GX_WRITE_RAS_REG(reg);

    gx->cmode0 = reg;
    gx->bpSentNot = 0;
}

void GXSetColorUpdate(u8 update_enable) {
    u32 reg;

    reg = gx->cmode0;

    SET_REG_FIELD(reg, 1, 3, update_enable);
    GX_WRITE_RAS_REG(reg);

    gx->cmode0 = reg;
    gx->bpSentNot = 0;
}

void GXSetAlphaUpdate(u8 update_enable) {
    u32 reg;

    reg = gx->cmode0;

    SET_REG_FIELD(reg, 1, 4, update_enable);
    GX_WRITE_RAS_REG(reg);

    gx->cmode0 = reg;
    gx->bpSentNot = 0;
}

void GXSetZMode(u8 compare_enable, u32 func, u8 update_enable) {
    u32 reg;

    reg = gx->zmode;

    SET_REG_FIELD(reg, 1, 0, compare_enable);
    SET_REG_FIELD(reg, 3, 1, func);
    SET_REG_FIELD(reg, 1, 4, update_enable);
    GX_WRITE_RAS_REG(reg);

    gx->zmode = reg;
    gx->bpSentNot = 0;
}

void GXSetZCompLoc(u8 before_tex) {
    OLD_SET_REG_FIELD(gx->peCtrl, 1, 6, before_tex);
    GX_WRITE_RAS_REG(gx->peCtrl);
    gx->bpSentNot = 0;
}

void GXSetPixelFmt(u32 pix_fmt, u32 z_fmt) {
    u32 oldPeCtrl;
    u8 aa;
    static u32 p2f[8] = { 0, 1, 2, 3, 4, 4, 4, 5 };

    oldPeCtrl = gx->peCtrl;
    OLD_SET_REG_FIELD(gx->peCtrl, 3, 0, p2f[pix_fmt]);
    OLD_SET_REG_FIELD(gx->peCtrl, 3, 3, z_fmt);

    if (oldPeCtrl != gx->peCtrl) {
        GX_WRITE_RAS_REG(gx->peCtrl);
        if (pix_fmt == GX_PF_RGB565_Z16) {
            aa = 1;
        } else {
            aa = 0;
        }
        OLD_SET_REG_FIELD(gx->genMode, 1, 9, aa);
        gx->dirtyState |= 4;
    }

    if (p2f[pix_fmt] == 4) {
        OLD_SET_REG_FIELD(gx->cmode1, 2, 9, (pix_fmt - 4) & 0x3);
        OLD_SET_REG_FIELD(gx->cmode1, 8, 24, 0x42);
        GX_WRITE_RAS_REG(gx->cmode1);
    }

    gx->bpSentNot = 0;
}

void GXSetDither(u8 dither) {
    u32 reg;

    reg = gx->cmode0;

    SET_REG_FIELD(reg, 1, 2, dither);
    GX_WRITE_RAS_REG(reg);

    gx->cmode0 = reg;
    gx->bpSentNot = 0;
}

void GXSetDstAlpha(u8 enable, u8 alpha) {
    u32 reg;

    reg = gx->cmode1;

    SET_REG_FIELD(reg, 8, 0, alpha);
    SET_REG_FIELD(reg, 1, 8, enable);
    GX_WRITE_RAS_REG(reg);

    gx->cmode1 = reg;
    gx->bpSentNot = 0;
}

void GXSetFieldMask(u8 odd_mask, u8 even_mask) {
    u32 reg;

    reg = 0;
    OLD_SET_REG_FIELD(reg, 1, 0, even_mask);
    OLD_SET_REG_FIELD(reg, 1, 1, odd_mask);
    OLD_SET_REG_FIELD(reg, 8, 24, 0x44);
    GX_WRITE_RAS_REG(reg);
    gx->bpSentNot = 0;
}

void GXSetFieldMode(u8 field_mode, u8 half_aspect_ratio) {
    u32 reg;

    OLD_SET_REG_FIELD(gx->lpSize, 1, 22, half_aspect_ratio);
    GX_WRITE_RAS_REG(gx->lpSize);
    __GXFlushTextureState();
    reg = field_mode | 0x68000000;
    GX_WRITE_RAS_REG(reg);
    __GXFlushTextureState();
}

extern f32 fn_803BD53C(f32 x); /* sinf */

static GXVtxDescList vcd[27];
static GXVtxAttrFmtList vat[27];

static f32 idata[12][3] = {
    { -0.5257311f, 0.0f, 0.8506508f },
    { 0.5257311f, 0.0f, 0.8506508f },
    { -0.5257311f, 0.0f, -0.8506508f },
    { 0.5257311f, 0.0f, -0.8506508f },
    { 0.0f, 0.8506508f, 0.5257311f },
    { 0.0f, 0.8506508f, -0.5257311f },
    { 0.0f, -0.8506508f, 0.5257311f },
    { 0.0f, -0.8506508f, -0.5257311f },
    { 0.8506508f, 0.5257311f, 0.0f },
    { -0.8506508f, 0.5257311f, 0.0f },
    { 0.8506508f, -0.5257311f, 0.0f },
    { -0.8506508f, -0.5257311f, 0.0f },
};

static u8 index[20][3] = {
    { 0, 4, 1 },
    { 0, 9, 4 },
    { 9, 5, 4 },
    { 4, 5, 8 },
    { 4, 8, 1 },
    { 8, 10, 1 },
    { 8, 3, 10 },
    { 5, 3, 8 },
    { 5, 2, 3 },
    { 2, 7, 3 },
    { 7, 10, 3 },
    { 7, 6, 10 },
    { 7, 11, 6 },
    { 11, 0, 6 },
    { 0, 1, 6 },
    { 6, 1, 10 },
    { 9, 0, 11 },
    { 9, 11, 2 },
    { 9, 2, 5 },
    { 7, 2, 11 },
};

#define normalize(v) \
    do { \
        f32 d_ = sqrtf(((v)[0] * (v)[0]) + ((v)[1] * (v)[1]) + ((v)[2] * (v)[2])); \
        (v)[0] /= d_; \
        (v)[1] /= d_; \
        (v)[2] /= d_; \
    } while (0)

void fn_803CFB3C(u8 depth, f32 v0[3], f32 v1[3], f32 v2[3]) { /* Subdivide */
    f32 v01[3];
    f32 v12[3];
    f32 v20[3];
    u32 i;

    if (depth == 0) {
        GXBegin(GX_TRIANGLES, GX_VTXFMT3, 3);
        GX_WRITE_F32(v0[0]);
        GX_WRITE_F32(v0[1]);
        GX_WRITE_F32(v0[2]);
        GX_WRITE_F32(v0[0]);
        GX_WRITE_F32(v0[1]);
        GX_WRITE_F32(v0[2]);
        GX_WRITE_F32(v1[0]);
        GX_WRITE_F32(v1[1]);
        GX_WRITE_F32(v1[2]);
        GX_WRITE_F32(v1[0]);
        GX_WRITE_F32(v1[1]);
        GX_WRITE_F32(v1[2]);
        GX_WRITE_F32(v2[0]);
        GX_WRITE_F32(v2[1]);
        GX_WRITE_F32(v2[2]);
        GX_WRITE_F32(v2[0]);
        GX_WRITE_F32(v2[1]);
        GX_WRITE_F32(v2[2]);
        return;
    }

    for (i = 0; i < 3; i++) {
        v01[i] = v0[i] + v1[i];
        v12[i] = v1[i] + v2[i];
        v20[i] = v2[i] + v0[i];
    }

    normalize(v01);
    normalize(v12);
    normalize(v20);
    fn_803CFB3C(depth - 1, v0, v01, v20);
    fn_803CFB3C(depth - 1, v1, v12, v01);
    fn_803CFB3C(depth - 1, v2, v20, v12);
    fn_803CFB3C(depth - 1, v01, v12, v20);
}

void fn_803CFEF0(u8 numMajor, u8 numMinor) { /* GXDrawSphere */
    u32 ttype;
    f32 radius = 1.0f;
    f32 majorStep = 3.1415927f / numMajor;
    f32 minorStep = 6.2831855f / numMinor;
    s32 i, j;
    f32 a, b;
    f32 r0, r1;
    f32 z0, z1;
    f32 c;
    f32 x, y;

    fn_803CA9C0(GX_VA_TEX0, &ttype);
    fn_803CAB74(vcd);
    fn_803CB628(GX_VTXFMT3, vat);
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_NRM, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT3, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT3, GX_VA_NRM, GX_NRM_XYZ, GX_F32, 0);

    if (ttype != GX_NONE) {
        GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
        GXSetVtxAttrFmt(GX_VTXFMT3, GX_VA_TEX0, GX_TEX_ST, GX_RGBA6, 0);
    }

    for (i = 0; i < numMajor; i++) {
        a = i * majorStep;
        b = a + majorStep;
        r0 = radius * fn_803BD53C(a);
        r1 = radius * fn_803BD53C(b);
        z0 = radius * fn_803BD560(a);
        z1 = radius * fn_803BD560(b);
        GXBegin(GX_TRIANGLESTRIP, GX_VTXFMT3, (numMinor + 1) * 2);
        for (j = 0; j <= numMinor; j++) {
            c = j * minorStep;
            x = fn_803BD560(c);
            y = fn_803BD53C(c);
            GX_WRITE_F32(x * r1);
            GX_WRITE_F32(y * r1);
            GX_WRITE_F32(z1);
            GX_WRITE_F32((x * r1) / radius);
            GX_WRITE_F32((y * r1) / radius);
            GX_WRITE_F32(z1 / radius);
            if (ttype != GX_NONE) {
                GX_WRITE_F32((f32)j / (f32)numMinor);
                GX_WRITE_F32((f32)(i + 1) / (f32)numMajor);
            }
            GX_WRITE_F32(x * r0);
            GX_WRITE_F32(y * r0);
            GX_WRITE_F32(z0);
            GX_WRITE_F32((x * r0) / radius);
            GX_WRITE_F32((y * r0) / radius);
            GX_WRITE_F32(z0 / radius);
            if (ttype != GX_NONE) {
                GX_WRITE_F32((f32)j / (f32)numMinor);
                GX_WRITE_F32((f32)i / (f32)numMajor);
            }
        }
    }
    fn_803CA4D4(vcd);
    GXSetVtxAttrFmtv(GX_VTXFMT3, vat);
}

void fn_803D026C(u8 depth) { /* GXDrawSphere1 */
    s32 i;

    fn_803CAB74(vcd);
    fn_803CB628(GX_VTXFMT3, vat);
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_NRM, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT3, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT3, GX_VA_NRM, GX_NRM_XYZ, GX_F32, 0);

    for (i = 19; i >= 0; i--) {
        fn_803CFB3C(depth, idata[index[i][0]], idata[index[i][1]], idata[index[i][2]]);
    }

    fn_803CA4D4(vcd);
    GXSetVtxAttrFmtv(GX_VTXFMT3, vat);
}

void fn_803D0380(void) {
}

void GXCallDisplayList(void* list, u32 nbytes) {
    if (gx->dirtyState != 0) {
        __GXSetDirtyState();
    }

    if (*(u32*)&gx->vNumNot == 0) {
        __GXSendFlushPrim();
    }

    GX_WRITE_U8(0x40); /* GX_CMD_CALL_DL */
    GX_WRITE_U32((u32)list);
    GX_WRITE_U32(nbytes);
}

void fn_803D03F4(f32 x, f32 y, f32 z, const f32 mtx[3][4], const f32* pm, const f32* vp, f32* sx, f32* sy, f32* sz) { /* GXProject */
    f32 peyeX;
    f32 peyeY;
    f32 peyeZ;
    f32 xc;
    f32 yc;
    f32 zc;
    f32 wc;

    peyeX = mtx[0][3] + ((mtx[0][2] * z) + ((mtx[0][0] * x) + (mtx[0][1] * y)));
    peyeY = mtx[1][3] + ((mtx[1][2] * z) + ((mtx[1][0] * x) + (mtx[1][1] * y)));
    peyeZ = mtx[2][3] + ((mtx[2][2] * z) + ((mtx[2][0] * x) + (mtx[2][1] * y)));
    if (pm[0] == 0.0f) {
        xc = (peyeX * pm[1]) + (peyeZ * pm[2]);
        yc = (peyeY * pm[3]) + (peyeZ * pm[4]);
        zc = pm[6] + (peyeZ * pm[5]);
        wc = 1.0f / -peyeZ;
    } else {
        xc = pm[2] + (peyeX * pm[1]);
        yc = pm[4] + (peyeY * pm[3]);
        zc = pm[6] + (peyeZ * pm[5]);
        wc = 1.0f;
    }
    *sx = (vp[2] / 2.0f) + (vp[0] + (wc * (xc * vp[2] / 2.0f)));
    *sy = (vp[3] / 2.0f) + (vp[1] + (wc * (-yc * vp[3] / 2.0f)));
    *sz = vp[5] + (wc * (zc * (vp[5] - vp[4])));
}

void GXSetProjection(const f32 mtx[4][4], u32 type) {
    gx->projType = type;
    gx->projMtx[0] = mtx[0][0];
    gx->projMtx[2] = mtx[1][1];
    gx->projMtx[4] = mtx[2][2];
    gx->projMtx[5] = mtx[2][3];
    if (type == GX_ORTHOGRAPHIC) {
        gx->projMtx[1] = mtx[0][3];
        gx->projMtx[3] = mtx[1][3];
    } else {
        gx->projMtx[1] = mtx[0][2];
        gx->projMtx[3] = mtx[1][2];
    }

    GX_WRITE_U8(0x10);
    GX_WRITE_U32(0x00061020);
    GX_WRITE_F32(gx->projMtx[0]);
    GX_WRITE_F32(gx->projMtx[1]);
    GX_WRITE_F32(gx->projMtx[2]);
    GX_WRITE_F32(gx->projMtx[3]);
    GX_WRITE_F32(gx->projMtx[4]);
    GX_WRITE_F32(gx->projMtx[5]);
    GX_WRITE_U32(gx->projType);
    gx->bpSentNot = 1;
}

void GXSetProjectionv(const f32* ptr) {
    gx->projType = (ptr[0] == 0.0f) ? GX_PERSPECTIVE : GX_ORTHOGRAPHIC;
    gx->projMtx[0] = ptr[1];
    gx->projMtx[1] = ptr[2];
    gx->projMtx[2] = ptr[3];
    gx->projMtx[3] = ptr[4];
    gx->projMtx[4] = ptr[5];
    gx->projMtx[5] = ptr[6];

    GX_WRITE_U8(0x10);
    GX_WRITE_U32(0x00061020);
    GX_WRITE_F32(gx->projMtx[0]);
    GX_WRITE_F32(gx->projMtx[1]);
    GX_WRITE_F32(gx->projMtx[2]);
    GX_WRITE_F32(gx->projMtx[3]);
    GX_WRITE_F32(gx->projMtx[4]);
    GX_WRITE_F32(gx->projMtx[5]);
    GX_WRITE_U32(gx->projType);
    gx->bpSentNot = 1;
}

void fn_803D06DC(f32* ptr) { /* GXGetProjectionv */
    ptr[0] = ((u32)gx->projType != GX_PERSPECTIVE) ? 1.0f : 0.0f;
    ptr[1] = gx->projMtx[0];
    ptr[2] = gx->projMtx[1];
    ptr[3] = gx->projMtx[2];
    ptr[4] = gx->projMtx[3];
    ptr[5] = gx->projMtx[4];
    ptr[6] = gx->projMtx[5];
}

void GXLoadPosMtxImm(const f32 mtx[3][4], u32 id) {
    u32 reg;
    u32 addr;

    addr = id * 4;
    reg = addr | 0xB0000;

    GX_WRITE_U8(0x10);
    GX_WRITE_U32(reg);

    {
        register const f32 (*m)[4] = mtx;
        register void* dest = (void*)GXFIFO_ADDR;
        register f32 a00_a01, a02_a03, a10_a11, a12_a13, a20_a21, a22_a23;

        asm {
            psq_l a00_a01, 0x00(m), 0, 0
            psq_l a02_a03, 0x08(m), 0, 0
            psq_l a10_a11, 0x10(m), 0, 0
            psq_l a12_a13, 0x18(m), 0, 0
            psq_l a20_a21, 0x20(m), 0, 0
            psq_l a22_a23, 0x28(m), 0, 0
            psq_st a00_a01, 0(dest), 0, 0
            psq_st a02_a03, 0(dest), 0, 0
            psq_st a10_a11, 0(dest), 0, 0
            psq_st a12_a13, 0(dest), 0, 0
            psq_st a20_a21, 0(dest), 0, 0
            psq_st a22_a23, 0(dest), 0, 0
        }
    }
}

void kar_grcoll__803d078c(const f32 mtx[3][4], u32 id) { /* GXLoadNrmMtxImm */
    u32 reg;
    u32 addr;

    addr = id * 3 + 0x400;
    reg = addr | 0x80000;

    GX_WRITE_U8(0x10);
    GX_WRITE_U32(reg);

    {
        register const f32 (*m)[4] = mtx;
        register void* dest = (void*)GXFIFO_ADDR;
        register f32 a00_a01, a02, a10_a11, a12, a20_a21, a22;

        asm {
            psq_l  a00_a01, 0x00(m), 0, 0
            lfs    a02, 0x08(m)
            psq_l  a10_a11, 0x10(m), 0, 0
            lfs    a12, 0x18(m)
            psq_l  a20_a21, 0x20(m), 0, 0
            lfs    a22, 0x28(m)
            psq_st a00_a01, 0(dest), 0, 0
            stfs   a02, 0(dest)
            psq_st a10_a11, 0(dest), 0, 0
            stfs   a12, 0(dest)
            psq_st a20_a21, 0(dest), 0, 0
            stfs   a22, 0(dest)
        }
    }
}

void GXSetCurrentMtx(u32 id) {
    OLD_SET_REG_FIELD(gx->matIdxA, 6, 0, id);
    __GXSetMatrixIndex(GX_VA_PNMTXIDX);
}

void GXLoadTexMtxImm(const f32 mtx[][4], u32 id, u32 type) {
    u32 reg;
    u32 addr;
    u32 count;

    if (id >= GX_PTTEXMTX0) {
        addr = (id - GX_PTTEXMTX0) * 4 + 0x500;
    } else {
        addr = id * 4;
    }
    count = (type == GX_MTX2x4) ? 8 : 12;
    reg = addr | ((count - 1) << 16);

    GX_WRITE_U8(0x10);
    GX_WRITE_U32(reg);

    if (type == GX_MTX3x4) {
        register const f32 (*m)[4] = mtx;
        register void* dest = (void*)GXFIFO_ADDR;
        register f32 a00_a01, a02_a03, a10_a11, a12_a13, a20_a21, a22_a23;

        asm {
            psq_l a00_a01, 0x00(m), 0, 0
            psq_l a02_a03, 0x08(m), 0, 0
            psq_l a10_a11, 0x10(m), 0, 0
            psq_l a12_a13, 0x18(m), 0, 0
            psq_l a20_a21, 0x20(m), 0, 0
            psq_l a22_a23, 0x28(m), 0, 0
            psq_st a00_a01, 0(dest), 0, 0
            psq_st a02_a03, 0(dest), 0, 0
            psq_st a10_a11, 0(dest), 0, 0
            psq_st a12_a13, 0(dest), 0, 0
            psq_st a20_a21, 0(dest), 0, 0
            psq_st a22_a23, 0(dest), 0, 0
        }
    } else {
        register const f32 (*m)[4] = mtx;
        register void* dest = (void*)GXFIFO_ADDR;
        register f32 a00_a01, a02_a03, a10_a11, a12_a13;

        asm {
            psq_l a00_a01, 0x00(m), 0, 0
            psq_l a02_a03, 0x08(m), 0, 0
            psq_l a10_a11, 0x10(m), 0, 0
            psq_l a12_a13, 0x18(m), 0, 0
            psq_st a00_a01, 0(dest), 0, 0
            psq_st a02_a03, 0(dest), 0, 0
            psq_st a10_a11, 0(dest), 0, 0
            psq_st a12_a13, 0(dest), 0, 0
        }
    }
}

void GXSetViewportJitter(f32 left, f32 top, f32 wd, f32 ht, f32 nearz, f32 farz, u32 field) {
    f32 sx;
    f32 sy;
    f32 sz;
    f32 ox;
    f32 oy;
    f32 oz;
    f32 zmin;
    f32 zmax;
    u32 reg;

    if (field == 0) {
        top -= 0.5f;
    }

    gx->vpLeft = left;
    gx->vpTop = top;
    gx->vpWd = wd;
    gx->vpHt = ht;
    gx->vpNearz = nearz;
    gx->vpFarz = farz;

    sx = gx->vpWd / 2.0f;
    sy = -gx->vpHt / 2.0f;
    ox = 342.0f + (gx->vpLeft + (gx->vpWd / 2.0f));
    oy = 342.0f + (gx->vpTop + (gx->vpHt / 2.0f));

    zmin = gx->vpNearz * gx->zScale;
    zmax = gx->vpFarz * gx->zScale;

    sz = zmax - zmin;
    oz = zmax + gx->zOffset;

    reg = 0x5101A;
    GX_WRITE_U8(0x10);
    GX_WRITE_U32(reg);
    GX_WRITE_XF_REG_F(26, sx);
    GX_WRITE_XF_REG_F(27, sy);
    GX_WRITE_XF_REG_F(28, sz);
    GX_WRITE_XF_REG_F(29, ox);
    GX_WRITE_XF_REG_F(30, oy);
    GX_WRITE_XF_REG_F(31, oz);

    gx->bpSentNot = 1;
}

void GXSetViewport(f32 left, f32 top, f32 wd, f32 ht, f32 nearz, f32 farz) {
    GXSetViewportJitter(left, top, wd, ht, nearz, farz, 1);
}

void fn_803D09F0(f32* vp) { /* GXGetViewportv */
    vp[0] = gx->vpLeft;
    vp[1] = gx->vpTop;
    vp[2] = gx->vpWd;
    vp[3] = gx->vpHt;
    vp[4] = gx->vpNearz;
    vp[5] = gx->vpFarz;
}

void GXSetScissor(u32 left, u32 top, u32 wd, u32 ht) {
    u32 tp;
    u32 lf;
    u32 bm;
    u32 rt;

    tp = top + 342;
    lf = left + 342;
    bm = tp + ht - 1;
    rt = lf + wd - 1;

    OLD_SET_REG_FIELD(gx->suScis0, 11, 0, tp);
    OLD_SET_REG_FIELD(gx->suScis0, 11, 12, lf);
    OLD_SET_REG_FIELD(gx->suScis1, 11, 0, bm);
    OLD_SET_REG_FIELD(gx->suScis1, 11, 12, rt);

    GX_WRITE_RAS_REG(gx->suScis0);
    GX_WRITE_RAS_REG(gx->suScis1);
    gx->bpSentNot = 0;
}

void GXSetScissorBoxOffset(s32 x_off, s32 y_off) {
    u32 reg = 0;
    u32 hx;
    u32 hy;

    hx = (u32)(x_off + 342) >> 1;
    hy = (u32)(y_off + 342) >> 1;

    OLD_SET_REG_FIELD(reg, 10, 0, hx);
    OLD_SET_REG_FIELD(reg, 10, 10, hy);
    OLD_SET_REG_FIELD(reg, 8, 24, 0x59);
    GX_WRITE_RAS_REG(reg);
    gx->bpSentNot = 0;
}

void GXSetClipMode(u32 mode) {
    GX_WRITE_XF_REG(5, mode);
    gx->bpSentNot = 1;
}

void __GXSetMatrixIndex(u32 matIdxAttr) {
    if (matIdxAttr < GX_VA_TEX4MTXIDX) {
        GX_WRITE_SOME_REG4(8, 0x30, gx->matIdxA, -12);
        GX_WRITE_XF_REG(24, gx->matIdxA);
    } else {
        GX_WRITE_SOME_REG4(8, 0x40, gx->matIdxB, -12);
        GX_WRITE_XF_REG(25, gx->matIdxB);
    }
    gx->bpSentNot = 1;
}

void fn_803D0BA4(u32 perf0, u32 perf1) { /* GXSetGPMetric */
    u32 reg;

    switch (gx->perf0) {
    case GX_PERF0_VERTICES:
    case GX_PERF0_CLIP_VTX:
    case GX_PERF0_CLIP_CLKS:
    case GX_PERF0_XF_WAIT_IN:
    case GX_PERF0_XF_WAIT_OUT:
    case GX_PERF0_XF_XFRM_CLKS:
    case GX_PERF0_XF_LIT_CLKS:
    case GX_PERF0_XF_BOT_CLKS:
    case GX_PERF0_XF_REGLD_CLKS:
    case GX_PERF0_XF_REGRD_CLKS:
    case GX_PERF0_CLIP_RATIO:
    case GX_PERF0_CLOCKS:
        reg = 0;
        GX_WRITE_XF_REG(6, reg);
        break;
    case GX_PERF0_TRIANGLES:
    case GX_PERF0_TRIANGLES_CULLED:
    case GX_PERF0_TRIANGLES_PASSED:
    case GX_PERF0_TRIANGLES_SCISSORED:
    case GX_PERF0_TRIANGLES_0TEX:
    case GX_PERF0_TRIANGLES_1TEX:
    case GX_PERF0_TRIANGLES_2TEX:
    case GX_PERF0_TRIANGLES_3TEX:
    case GX_PERF0_TRIANGLES_4TEX:
    case GX_PERF0_TRIANGLES_5TEX:
    case GX_PERF0_TRIANGLES_6TEX:
    case GX_PERF0_TRIANGLES_7TEX:
    case GX_PERF0_TRIANGLES_8TEX:
    case GX_PERF0_TRIANGLES_0CLR:
    case GX_PERF0_TRIANGLES_1CLR:
    case GX_PERF0_TRIANGLES_2CLR:
        reg = 0x23000000;
        GX_WRITE_RAS_REG(reg);
        break;
    case GX_PERF0_QUAD_0CVG:
    case GX_PERF0_QUAD_NON0CVG:
    case GX_PERF0_QUAD_1CVG:
    case GX_PERF0_QUAD_2CVG:
    case GX_PERF0_QUAD_3CVG:
    case GX_PERF0_QUAD_4CVG:
    case GX_PERF0_AVG_QUAD_CNT:
        reg = 0x24000000;
        GX_WRITE_RAS_REG(reg);
        break;
    case GX_PERF0_NONE:
        break;
    default:
        break;
    }

    switch (gx->perf1) {
    case GX_PERF1_TEXELS:
    case GX_PERF1_TX_IDLE:
    case GX_PERF1_TX_REGS:
    case GX_PERF1_TX_MEMSTALL:
    case GX_PERF1_TC_CHECK1_2:
    case GX_PERF1_TC_CHECK3_4:
    case GX_PERF1_TC_CHECK5_6:
    case GX_PERF1_TC_CHECK7_8:
    case GX_PERF1_TC_MISS:
    case GX_PERF1_CLOCKS:
        reg = 0x67000000;
        GX_WRITE_RAS_REG(reg);
        break;
    case GX_PERF1_VC_ELEMQ_FULL:
    case GX_PERF1_VC_MISSQ_FULL:
    case GX_PERF1_VC_MEMREQ_FULL:
    case GX_PERF1_VC_STATUS7:
    case GX_PERF1_VC_MISSREP_FULL:
    case GX_PERF1_VC_STREAMBUF_LOW:
    case GX_PERF1_VC_ALL_STALLS:
    case GX_PERF1_VERTICES:
        OLD_SET_REG_FIELD(gx->perfSel, 4, 4, 0);
        GX_WRITE_SOME_REG4(8, 0x20, gx->perfSel, -12);
        break;
    case GX_PERF1_FIFO_REQ:
    case GX_PERF1_CALL_REQ:
    case GX_PERF1_VC_MISS_REQ:
    case GX_PERF1_CP_ALL_REQ:
        reg = 0;
        GX_SET_CP_REG(3, reg);
        break;
    case GX_PERF1_NONE:
        break;
    default:
        break;
    }

    gx->perf0 = perf0;
    switch (gx->perf0) {
    case GX_PERF0_VERTICES:
        reg = 0x273;
        GX_WRITE_XF_REG(6, reg);
        break;
    case GX_PERF0_CLIP_VTX: reg = 0x14A; GX_WRITE_XF_REG(6, reg); break;
    case GX_PERF0_CLIP_CLKS: reg = 0x16B; GX_WRITE_XF_REG(6, reg); break;
    case GX_PERF0_XF_WAIT_IN: reg = 0x84; GX_WRITE_XF_REG(6, reg); break;
    case GX_PERF0_XF_WAIT_OUT: reg = 0xC6; GX_WRITE_XF_REG(6, reg); break;
    case GX_PERF0_XF_XFRM_CLKS: reg = 0x210; GX_WRITE_XF_REG(6, reg); break;
    case GX_PERF0_XF_LIT_CLKS: reg = 0x252; GX_WRITE_XF_REG(6, reg); break;
    case GX_PERF0_XF_BOT_CLKS: reg = 0x231; GX_WRITE_XF_REG(6, reg); break;
    case GX_PERF0_XF_REGLD_CLKS: reg = 0x1AD; GX_WRITE_XF_REG(6, reg); break;
    case GX_PERF0_XF_REGRD_CLKS: reg = 0x1CE; GX_WRITE_XF_REG(6, reg); break;
    case GX_PERF0_CLOCKS: reg = 0x21; GX_WRITE_XF_REG(6, reg); break;
    case GX_PERF0_CLIP_RATIO: reg = 0x153; GX_WRITE_XF_REG(6, reg); break;
    case GX_PERF0_TRIANGLES: reg = 0x2300AE7F; GX_WRITE_RAS_REG(reg); break;
    case GX_PERF0_TRIANGLES_CULLED: reg = 0x23008E7F; GX_WRITE_RAS_REG(reg); break;
    case GX_PERF0_TRIANGLES_PASSED: reg = 0x23009E7F; GX_WRITE_RAS_REG(reg); break;
    case GX_PERF0_TRIANGLES_SCISSORED: reg = 0x23001E7F; GX_WRITE_RAS_REG(reg); break;
    case GX_PERF0_TRIANGLES_0TEX: reg = 0x2300AC3F; GX_WRITE_RAS_REG(reg); break;
    case GX_PERF0_TRIANGLES_1TEX: reg = 0x2300AC7F; GX_WRITE_RAS_REG(reg); break;
    case GX_PERF0_TRIANGLES_2TEX: reg = 0x2300ACBF; GX_WRITE_RAS_REG(reg); break;
    case GX_PERF0_TRIANGLES_3TEX: reg = 0x2300ACFF; GX_WRITE_RAS_REG(reg); break;
    case GX_PERF0_TRIANGLES_4TEX: reg = 0x2300AD3F; GX_WRITE_RAS_REG(reg); break;
    case GX_PERF0_TRIANGLES_5TEX: reg = 0x2300AD7F; GX_WRITE_RAS_REG(reg); break;
    case GX_PERF0_TRIANGLES_6TEX: reg = 0x2300ADBF; GX_WRITE_RAS_REG(reg); break;
    case GX_PERF0_TRIANGLES_7TEX: reg = 0x2300ADFF; GX_WRITE_RAS_REG(reg); break;
    case GX_PERF0_TRIANGLES_8TEX: reg = 0x2300AE3F; GX_WRITE_RAS_REG(reg); break;
    case GX_PERF0_TRIANGLES_0CLR: reg = 0x2300A27F; GX_WRITE_RAS_REG(reg); break;
    case GX_PERF0_TRIANGLES_1CLR: reg = 0x2300A67F; GX_WRITE_RAS_REG(reg); break;
    case GX_PERF0_TRIANGLES_2CLR: reg = 0x2300AA7F; GX_WRITE_RAS_REG(reg); break;
    case GX_PERF0_QUAD_0CVG: reg = 0x2402C0C6; GX_WRITE_RAS_REG(reg); break;
    case GX_PERF0_QUAD_NON0CVG: reg = 0x2402C16B; GX_WRITE_RAS_REG(reg); break;
    case GX_PERF0_QUAD_1CVG: reg = 0x2402C0E7; GX_WRITE_RAS_REG(reg); break;
    case GX_PERF0_QUAD_2CVG: reg = 0x2402C108; GX_WRITE_RAS_REG(reg); break;
    case GX_PERF0_QUAD_3CVG: reg = 0x2402C129; GX_WRITE_RAS_REG(reg); break;
    case GX_PERF0_QUAD_4CVG: reg = 0x2402C14A; GX_WRITE_RAS_REG(reg); break;
    case GX_PERF0_AVG_QUAD_CNT: reg = 0x2402C1AD; GX_WRITE_RAS_REG(reg); break;
    case GX_PERF0_NONE: break;
    default: break;
    }

    gx->perf1 = perf1;
    switch (gx->perf1) {
    case GX_PERF1_TEXELS: reg = 0x67000042; GX_WRITE_RAS_REG(reg); break;
    case GX_PERF1_TX_IDLE: reg = 0x67000084; GX_WRITE_RAS_REG(reg); break;
    case GX_PERF1_TX_REGS: reg = 0x67000063; GX_WRITE_RAS_REG(reg); break;
    case GX_PERF1_TX_MEMSTALL: reg = 0x67000129; GX_WRITE_RAS_REG(reg); break;
    case GX_PERF1_TC_MISS: reg = 0x67000252; GX_WRITE_RAS_REG(reg); break;
    case GX_PERF1_CLOCKS: reg = 0x67000021; GX_WRITE_RAS_REG(reg); break;
    case GX_PERF1_TC_CHECK1_2: reg = 0x6700014B; GX_WRITE_RAS_REG(reg); break;
    case GX_PERF1_TC_CHECK3_4: reg = 0x6700018D; GX_WRITE_RAS_REG(reg); break;
    case GX_PERF1_TC_CHECK5_6: reg = 0x670001CF; GX_WRITE_RAS_REG(reg); break;
    case GX_PERF1_TC_CHECK7_8: reg = 0x67000211; GX_WRITE_RAS_REG(reg); break;
    case GX_PERF1_VC_ELEMQ_FULL: OLD_SET_REG_FIELD(gx->perfSel, 4, 4, 2); GX_WRITE_SOME_REG4(8, 0x20, gx->perfSel, -12); break;
    case GX_PERF1_VC_MISSQ_FULL: OLD_SET_REG_FIELD(gx->perfSel, 4, 4, 3); GX_WRITE_SOME_REG4(8, 0x20, gx->perfSel, -12); break;
    case GX_PERF1_VC_MEMREQ_FULL: OLD_SET_REG_FIELD(gx->perfSel, 4, 4, 4); GX_WRITE_SOME_REG4(8, 0x20, gx->perfSel, -12); break;
    case GX_PERF1_VC_STATUS7: OLD_SET_REG_FIELD(gx->perfSel, 4, 4, 5); GX_WRITE_SOME_REG4(8, 0x20, gx->perfSel, -12); break;
    case GX_PERF1_VC_MISSREP_FULL: OLD_SET_REG_FIELD(gx->perfSel, 4, 4, 6); GX_WRITE_SOME_REG4(8, 0x20, gx->perfSel, -12); break;
    case GX_PERF1_VC_STREAMBUF_LOW: OLD_SET_REG_FIELD(gx->perfSel, 4, 4, 7); GX_WRITE_SOME_REG4(8, 0x20, gx->perfSel, -12); break;
    case GX_PERF1_VC_ALL_STALLS: OLD_SET_REG_FIELD(gx->perfSel, 4, 4, 9); GX_WRITE_SOME_REG4(8, 0x20, gx->perfSel, -12); break;
    case GX_PERF1_VERTICES: OLD_SET_REG_FIELD(gx->perfSel, 4, 4, 8); GX_WRITE_SOME_REG4(8, 0x20, gx->perfSel, -12); break;
    case GX_PERF1_FIFO_REQ: reg = 2; GX_SET_CP_REG(3, reg); break;
    case GX_PERF1_CALL_REQ: reg = 3; GX_SET_CP_REG(3, reg); break;
    case GX_PERF1_VC_MISS_REQ: reg = 4; GX_SET_CP_REG(3, reg); break;
    case GX_PERF1_CP_ALL_REQ: reg = 5; GX_SET_CP_REG(3, reg); break;
    case GX_PERF1_NONE: break;
    default: break;
    }

    gx->bpSentNot = 0;
}

void fn_803D13EC(void) { /* GXClearGPMetric */
    u32 reg;

    reg = 4;
    GX_SET_CP_REG(2, reg);
}
