#include "dolphin/types.h"

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

typedef void (*__OSInterruptHandler)(u32 interrupt, OSContext* context);

extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL level);
extern void OSRegisterVersion(char* version);
extern void __OSSetInterruptHandler(u32 interrupt, __OSInterruptHandler handler);
extern u32 __OSUnmaskInterrupts(u32 mask);
extern void OSClearContext(OSContext* context);
extern void OSSetCurrentContext(OSContext* context);
extern void DCFlushRange(void* addr, u32 nBytes);
extern void DCInvalidateRange(void* addr, u32 nBytes);
extern void* memset(void* dst, int val, size_t n);
extern void kar_diagnostic__near_803c3354(void); /* PPCSync */

volatile u16 __DSPRegs[] : 0xcc005000;

#define DSP_CONTROL_STATUS   5
#define DSP_ARAM_SIZE        9
#define DSP_ARAM_MODE        11
#define DSP_ARAM_REFRESH     13
#define DSP_ARAM_DMA_MM_HI   16
#define DSP_ARAM_DMA_MM_LO   17
#define DSP_ARAM_DMA_ARAM_HI 18
#define DSP_ARAM_DMA_ARAM_LO 19
#define DSP_ARAM_DMA_SIZE_HI 20
#define DSP_ARAM_DMA_SIZE_LO 21

#define OSRoundUp32B(x) (((u32)(x) + 32 - 1) & ~(32 - 1))
#define OSPhysicalToUncached(paddr) ((void*)((u32)(paddr) + 0xC0000000))

extern char __ARVersionString[]; /* "<< Dolphin SDK - AR ... >>" */
extern void (*__AR_Callback)(void);

char* __ARVersion[2] = { __ARVersionString };

BOOL __AR_init_flag;
u32* __AR_BlockLength;
u32 __AR_FreeBlocks;
u32 __AR_StackPointer;
u32 __AR_ExpansionSize;
u32 __AR_InternalSize;
u32 __AR_Size;

void __ARHandler(u32 exception, OSContext* context);
void __ARChecksize(void);

void ARStartDMA(u32 type, u32 mainmem_addr, u32 aram_addr, u32 length)
{
    BOOL old;

    old = OSDisableInterrupts();
    __DSPRegs[DSP_ARAM_DMA_MM_HI] = (u16)((__DSPRegs[DSP_ARAM_DMA_MM_HI] & ~0x03ff) | (u16)(mainmem_addr >> 16));
    __DSPRegs[DSP_ARAM_DMA_MM_LO] = (u16)((__DSPRegs[DSP_ARAM_DMA_MM_LO] & ~0xffe0) | (u16)(mainmem_addr & 0xffff));
    __DSPRegs[DSP_ARAM_DMA_ARAM_HI] = (u16)((__DSPRegs[DSP_ARAM_DMA_ARAM_HI] & ~0x03ff) | (u16)(aram_addr >> 16));
    __DSPRegs[DSP_ARAM_DMA_ARAM_LO] = (u16)((__DSPRegs[DSP_ARAM_DMA_ARAM_LO] & ~0xffe0) | (u16)(aram_addr & 0xffff));
    __DSPRegs[DSP_ARAM_DMA_SIZE_HI] = __DSPRegs[DSP_ARAM_DMA_SIZE_HI] & ~0x8000 | ((type << 0xF) & ~0x7FFF);
    __DSPRegs[DSP_ARAM_DMA_SIZE_HI] = (__DSPRegs[DSP_ARAM_DMA_SIZE_HI] & 0xFFFFFC00) | (length >> 0x10);
    __DSPRegs[DSP_ARAM_DMA_SIZE_LO] = (__DSPRegs[DSP_ARAM_DMA_SIZE_LO] & 0xFFFF001F) | (length & 0x0000FFFF);
    OSRestoreInterrupts(old);
}

u32 ARAlloc(u32 length)
{
    u32 tmp;
    BOOL old;

    old = OSDisableInterrupts();

    tmp = __AR_StackPointer;
    __AR_StackPointer += length;
    *__AR_BlockLength = length;
    __AR_BlockLength += 1;
    __AR_FreeBlocks -= 1;
    OSRestoreInterrupts(old);
    return tmp;
}

u32 ARFree(u32* length)
{
    BOOL old;

    old = OSDisableInterrupts();
    __AR_BlockLength -= 1;
    if (length) {
        *length = *__AR_BlockLength;
    }
    __AR_StackPointer -= *__AR_BlockLength;
    __AR_FreeBlocks += 1;
    OSRestoreInterrupts(old);
    return __AR_StackPointer;
}

u32 ARInit(u32* stack_index_addr, u32 num_entries)
{
    BOOL old;
    u16 refresh;

    if (__AR_init_flag == TRUE) {
        return 0x4000;
    }

    OSRegisterVersion(__ARVersion[0]);

    old = OSDisableInterrupts();
    __AR_Callback = NULL;
    __OSSetInterruptHandler(6, __ARHandler);
    __OSUnmaskInterrupts(0x02000000);
    __AR_StackPointer = 0x4000;
    __AR_FreeBlocks = num_entries;
    __AR_BlockLength = stack_index_addr;
    refresh = __DSPRegs[DSP_ARAM_REFRESH] & 0xFF;

    __DSPRegs[DSP_ARAM_REFRESH] = (u16)((__DSPRegs[DSP_ARAM_REFRESH] & ~0xFF) | (refresh & 0xFF));

    __ARChecksize();
    __AR_init_flag = TRUE;
    OSRestoreInterrupts(old);
    return __AR_StackPointer;
}

void ARReset(void)
{
    __AR_init_flag = FALSE;
}

u32 ARGet_BaseAddressOrSizeOrInternalSize(void)
{
    return __AR_Size;
}

void __ARHandler(u32 exception, OSContext* context)
{
    OSContext exceptionContext;
    u16 tmp;

    tmp = __DSPRegs[DSP_CONTROL_STATUS];
    tmp = (tmp & ~0x88) | 0x20;
    __DSPRegs[DSP_CONTROL_STATUS] = (tmp);
    OSClearContext(&exceptionContext);
    OSSetCurrentContext(&exceptionContext);
    if (__AR_Callback) {
        __AR_Callback();
    }
    OSClearContext(&exceptionContext);
    OSSetCurrentContext(context);
}

static inline void __ARWaitForDMA(void)
{
    while (__DSPRegs[DSP_CONTROL_STATUS] & 0x200)
        ;
}

static inline void __ARClearInterrupt(void)
{
    u16 tmp;

    tmp = __DSPRegs[DSP_CONTROL_STATUS];
    tmp = (tmp & ~0x88) | 0x20;
    __DSPRegs[DSP_CONTROL_STATUS] = (tmp);
}

static inline void __ARWriteDMA(u32 mmem_addr, u32 aram_addr, u32 length)
{
    __DSPRegs[DSP_ARAM_DMA_MM_HI] = (u16)((__DSPRegs[DSP_ARAM_DMA_MM_HI] & ~0x03ff) | (u16)(mmem_addr >> 16));
    __DSPRegs[DSP_ARAM_DMA_MM_LO] = (u16)((__DSPRegs[DSP_ARAM_DMA_MM_LO] & ~0xffe0) | (u16)(mmem_addr & 0xffff));

    __DSPRegs[DSP_ARAM_DMA_ARAM_HI] = (u16)((__DSPRegs[DSP_ARAM_DMA_ARAM_HI] & ~0x03ff) | (u16)(aram_addr >> 16));
    __DSPRegs[DSP_ARAM_DMA_ARAM_LO] = (u16)((__DSPRegs[DSP_ARAM_DMA_ARAM_LO] & ~0xffe0) | (u16)(aram_addr & 0xffff));

    __DSPRegs[DSP_ARAM_DMA_SIZE_HI] = (u16)(__DSPRegs[DSP_ARAM_DMA_SIZE_HI] & ~0x8000);

    __DSPRegs[DSP_ARAM_DMA_SIZE_HI] = (u16)((__DSPRegs[DSP_ARAM_DMA_SIZE_HI] & ~0x03ff) | (u16)(length >> 16));
    __DSPRegs[DSP_ARAM_DMA_SIZE_LO] = (u16)((__DSPRegs[DSP_ARAM_DMA_SIZE_LO] & ~0xffe0) | (u16)(length & 0xffff));

    __ARWaitForDMA();
    __ARClearInterrupt();
}

static inline void __ARReadDMA(u32 mmem_addr, u32 aram_addr, u32 length)
{
    __DSPRegs[DSP_ARAM_DMA_MM_HI] = (u16)((__DSPRegs[DSP_ARAM_DMA_MM_HI] & ~0x03ff) | (u16)(mmem_addr >> 16));
    __DSPRegs[DSP_ARAM_DMA_MM_LO] = (u16)((__DSPRegs[DSP_ARAM_DMA_MM_LO] & ~0xffe0) | (u16)(mmem_addr & 0xffff));

    __DSPRegs[DSP_ARAM_DMA_ARAM_HI] = (u16)((__DSPRegs[DSP_ARAM_DMA_ARAM_HI] & ~0x03ff) | (u16)(aram_addr >> 16));
    __DSPRegs[DSP_ARAM_DMA_ARAM_LO] = (u16)((__DSPRegs[DSP_ARAM_DMA_ARAM_LO] & ~0xffe0) | (u16)(aram_addr & 0xffff));

    __DSPRegs[DSP_ARAM_DMA_SIZE_HI] = (u16)(__DSPRegs[DSP_ARAM_DMA_SIZE_HI] | 0x8000);

    __DSPRegs[DSP_ARAM_DMA_SIZE_HI] = (u16)((__DSPRegs[DSP_ARAM_DMA_SIZE_HI] & ~0x03ff) | (u16)(length >> 16));
    __DSPRegs[DSP_ARAM_DMA_SIZE_LO] = (u16)((__DSPRegs[DSP_ARAM_DMA_SIZE_LO] & ~0xffe0) | (u16)(length & 0xffff));

    __ARWaitForDMA();
    __ARClearInterrupt();
}

void __ARChecksize(void)
{
    u8 test_data_pad[63];
    u8 dummy_data_pad[63];
    u8 buffer_pad[63];
    u8 save_pad_1[63];
    u8 save_pad_2[63];
    u8 save_pad_3[63];
    u8 save_pad_4[63];
    u8 save_pad_5[63];
    u32* test_data;
    u32* dummy_data;
    u32* buffer;
    u32* save1;
    u32* save2;
    u32* save3;
    u32* save4;
    u32* save5;
    u16 ARAM_mode = 0;
    u32 ARAM_size = 0;
    u32 i;

    while (!(__DSPRegs[DSP_ARAM_MODE] & 1))
        ;

    ARAM_mode = 3;
    ARAM_size = __AR_InternalSize = 0x1000000;
    __DSPRegs[DSP_ARAM_SIZE] = ((__DSPRegs[DSP_ARAM_SIZE] & 0xFFFFFFC0) | 3) | 0x20;

    test_data = (u32*)(OSRoundUp32B((u32)(test_data_pad)));
    dummy_data = (u32*)(OSRoundUp32B((u32)(dummy_data_pad)));
    buffer = (u32*)(OSRoundUp32B((u32)(buffer_pad)));

    save1 = (u32*)(OSRoundUp32B((u32)(save_pad_1)));
    save2 = (u32*)(OSRoundUp32B((u32)(save_pad_2)));
    save3 = (u32*)(OSRoundUp32B((u32)(save_pad_3)));
    save4 = (u32*)(OSRoundUp32B((u32)(save_pad_4)));
    save5 = (u32*)(OSRoundUp32B((u32)(save_pad_5)));

    for (i = 0; i < 8; i++) {
        *(test_data + i) = 0xDEADBEEF;
        *(dummy_data + i) = 0xBAD0BAD0;
    }

    DCFlushRange((void*)test_data, 0x20);
    DCFlushRange((void*)dummy_data, 0x20);

    __AR_ExpansionSize = 0;

    DCInvalidateRange((void*)save1, 0x20);
    __ARReadDMA((u32)save1, ARAM_size + 0, 0x20);
    kar_diagnostic__near_803c3354();

    __ARWriteDMA((u32)test_data, ARAM_size + 0x0000000, 0x20);

    memset((void*)buffer, 0, 0x20);
    DCFlushRange((void*)buffer, 0x20);

    __ARReadDMA((u32)buffer, ARAM_size + 0x0000000, 0x20);
    kar_diagnostic__near_803c3354();

    if (buffer[0] == test_data[0]) {
        DCInvalidateRange((void*)save2, 0x20);
        __ARReadDMA((u32)save2, ARAM_size + 0x0200000, 0x20);
        kar_diagnostic__near_803c3354();

        DCInvalidateRange((void*)save3, 0x20);
        __ARReadDMA((u32)save3, ARAM_size + 0x1000000, 0x20);
        kar_diagnostic__near_803c3354();

        DCInvalidateRange((void*)save4, 0x20);
        __ARReadDMA((u32)save4, ARAM_size + 0x0000200, 0x20);
        kar_diagnostic__near_803c3354();

        DCInvalidateRange((void*)save5, 0x20);
        __ARReadDMA((u32)save5, ARAM_size + 0x0400000, 0x20);
        kar_diagnostic__near_803c3354();

        __ARWriteDMA((u32)dummy_data, ARAM_size + 0x0200000, 0x20);
        __ARWriteDMA((u32)test_data, ARAM_size + 0x0000000, 0x20);

        memset((void*)buffer, 0, 0x20);
        DCFlushRange((void*)buffer, 0x20);

        __ARReadDMA((u32)buffer, ARAM_size + 0x0200000, 0x20);
        kar_diagnostic__near_803c3354();

        if (buffer[0] == test_data[0]) {
            __ARWriteDMA((u32)save1, ARAM_size + 0x0000000, 0x20);

            ARAM_mode |= 0 << 1;
            ARAM_size += 0x0200000;
            __AR_ExpansionSize = 0x0200000;
        } else {
            __ARWriteDMA((u32)dummy_data, ARAM_size + 0x1000000, 0x20);
            __ARWriteDMA((u32)test_data, ARAM_size + 0x0000000, 0x20);

            memset((void*)buffer, 0, 0x20);
            DCFlushRange((void*)buffer, 0x20);

            __ARReadDMA((u32)buffer, ARAM_size + 0x1000000, 0x20);
            kar_diagnostic__near_803c3354();

            if (buffer[0] == test_data[0]) {
                __ARWriteDMA((u32)save1, ARAM_size + 0x0000000, 0x20);
                __ARWriteDMA((u32)save2, ARAM_size + 0x0200000, 0x20);

                ARAM_mode |= 4 << 1;
                ARAM_size += 0x0400000;
                __AR_ExpansionSize = 0x0400000;
            } else {
                __ARWriteDMA((u32)dummy_data, ARAM_size + 0x0000200, 0x20);
                __ARWriteDMA((u32)test_data, ARAM_size + 0x0000000, 0x20);

                memset((void*)buffer, 0, 0x20);
                DCFlushRange((void*)buffer, 0x20);

                __ARReadDMA((u32)buffer, ARAM_size + 0x0000200, 0x20);
                kar_diagnostic__near_803c3354();

                if (buffer[0] == test_data[0]) {
                    __ARWriteDMA((u32)save1, ARAM_size + 0x0000000, 0x20);
                    __ARWriteDMA((u32)save2, ARAM_size + 0x0200000, 0x20);
                    __ARWriteDMA((u32)save3, ARAM_size + 0x1000000, 0x20);

                    ARAM_mode |= 8 << 1;
                    ARAM_size += 0x0800000;
                    __AR_ExpansionSize = 0x0800000;
                } else {
                    __ARWriteDMA((u32)dummy_data, ARAM_size + 0x0400000, 0x20);

                    __ARWriteDMA((u32)test_data, ARAM_size + 0x0000000, 0x20);

                    memset((void*)buffer, 0, 0x20);
                    DCFlushRange((void*)buffer, 0x20);

                    __ARReadDMA((u32)buffer, ARAM_size + 0x0400000, 0x20);
                    kar_diagnostic__near_803c3354();

                    if (buffer[0] == test_data[0]) {
                        __ARWriteDMA((u32)save1, ARAM_size + 0x0000000, 0x20);
                        __ARWriteDMA((u32)save2, ARAM_size + 0x0200000, 0x20);
                        __ARWriteDMA((u32)save3, ARAM_size + 0x1000000, 0x20);
                        __ARWriteDMA((u32)save4, ARAM_size + 0x0000200, 0x20);

                        ARAM_mode |= 12 << 1;
                        ARAM_size += 0x1000000;
                        __AR_ExpansionSize = 0x1000000;
                    } else {
                        __ARWriteDMA((u32)save1, ARAM_size + 0x0000000, 0x20);
                        __ARWriteDMA((u32)save2, ARAM_size + 0x0200000, 0x20);
                        __ARWriteDMA((u32)save3, ARAM_size + 0x1000000, 0x20);
                        __ARWriteDMA((u32)save4, ARAM_size + 0x0000200, 0x20);
                        __ARWriteDMA((u32)save5, ARAM_size + 0x0400000, 0x20);

                        ARAM_mode |= 16 << 1;
                        ARAM_size += 0x2000000;
                        __AR_ExpansionSize = 0x2000000;
                    }
                }
            }
        }

        __DSPRegs[DSP_ARAM_SIZE] = (u16)((__DSPRegs[DSP_ARAM_SIZE] & ~(0x07 | 0x38)) | ARAM_mode);
    }

    *(u32*)OSPhysicalToUncached(0x00D0) = ARAM_size;
    __AR_Size = ARAM_size;
}
