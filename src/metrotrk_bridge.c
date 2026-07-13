#include "dolphin/types.h"

typedef struct OSContext OSContext;
typedef s16 __OSInterrupt;
typedef void (*__OSInterruptHandler)(__OSInterrupt interrupt, OSContext* context);
typedef void (*EXICallback)(s32 chan, OSContext* context);

typedef enum AmcExiError {
    AMC_EXI_NO_ERROR = 0,
    AMC_EXI_UNSELECTED
} AmcExiError;

extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL level);
extern void __OSMaskInterrupts(u32 mask);
extern u32 __OSUnmaskInterrupts(u32 mask);
extern void __OSSetInterruptHandler(u32 interrupt, __OSInterruptHandler handler);

#define __EXIRegs ((vu32*)0xCC006800)
#define __PIRegs ((vu32*)0xCC003000)

#define ALIGN_PREV(X, N) ((X) & ~((N)-1))
#define ALIGN_NEXT(X, N) ALIGN_PREV(((X) + (N)-1), N)

void DBGHandler(__OSInterrupt interrupt, OSContext* context);
void MWCallback(u32 interrupt, OSContext* context);
BOOL DBGReadStatus(void* param_1);
BOOL DBGWrite(u32 param1, u32* data, s32 byte_size);
BOOL DBGRead(u32 param1, u32* data, s32 byte_size);
BOOL DBGReadMailbox(void* param1);
BOOL DBGEXIImm(void* data, s32 byte_size, u32 write);

static inline BOOL DBGEXISelect(u32 v)
{
    u32 regs = __EXIRegs[10];
    regs &= 0x405;
    regs |= 0x80 | (v << 4);
    __EXIRegs[10] = regs;
    return TRUE;
}

static inline BOOL DBGEXIDeselect(void)
{
    __EXIRegs[10] &= 0x405;
    return TRUE;
}

static inline BOOL DBGEXISync(void)
{
    while (__EXIRegs[13] & 1) {}
    return TRUE;
}

void EXI2_Init(volatile unsigned char** inputPendingPtrRef, EXICallback monitorCallback) {}

void EXI2_EnableInterrupts(void) {}

int EXI2_Poll(void)
{
    return 0;
}

AmcExiError EXI2_ReadN(void* bytes, unsigned long length)
{
    return AMC_EXI_NO_ERROR;
}

AmcExiError EXI2_WriteN(const void* bytes, unsigned long length)
{
    return AMC_EXI_NO_ERROR;
}

void EXI2_Reserve(void) {}

void EXI2_Unreserve(void) {}

int AMC_IsStub(void)
{
    return 1;
}

void DBClose(void) {}

void DBOpen(void) {}

static u8 lbl_805DCA30[8] = { 0x80 }; /* SendCount */

int DBWrite(const void* data, u32 size)
{
    u32 value;
    u32 busyFlag;
    BOOL enabled;

    enabled = OSDisableInterrupts();
    do {
        BOOL error = FALSE;
        if (!DBGEXISelect(4)) {
            busyFlag = 0;
        } else {
            u32 status = 0x40000000;
            error |= !DBGEXIImm((u8*)&status, 2, 1);
            error |= !DBGEXISync();
            error |= !DBGEXIImm(&busyFlag, sizeof(busyFlag), 0);
            error |= !DBGEXISync();
            error |= !DBGEXIDeselect();
        }
    } while (busyFlag & 2);

    ++lbl_805DCA30[0];

    value = 0;
    if (lbl_805DCA30[0] & 1) {
        value = 0x1000;
    }
    while (!DBGWrite(value | 0x1C000, (u32*)data, ALIGN_NEXT(size, 4))) {}

    do {
        BOOL error = FALSE;
        if (!DBGEXISelect(4)) {
            busyFlag = 0;
        } else {
            u32 status = 0x40000000;
            error |= !DBGEXIImm((u8*)&status, 2, 1);
            error |= !DBGEXISync();
            error |= !DBGEXIImm(&busyFlag, sizeof(busyFlag), 0);
            error |= !DBGEXISync();
            error |= !DBGEXIDeselect();
        }
    } while (busyFlag & 2);

    value = (lbl_805DCA30[0] << 0x10) | 0x1F000000 | size;
    {
        BOOL error = FALSE;
        u32 mbox;
        while (1) {
            if (!DBGEXISelect(4)) {
                error = TRUE;
            } else {
                mbox = (value & 0x1FFFFFFF) | 0xC0000000;
                error = !DBGEXIImm((u8*)&mbox, sizeof(mbox), 1);
                error |= !DBGEXISync();
                error |= !DBGEXIDeselect();
                error = !error;
            }
            if (!error) {
                break;
            }
        }
    }

    do {
        while (!DBGReadStatus(&busyFlag)) {}
    } while (busyFlag & 2);

    OSRestoreInterrupts(enabled);

    return 0;
}

static u8 EXIInputFlag;
static u8* pEXIInputFlag;
static s32 RecvDataLeng;
static u32 SendMailData;
static void (*DBGCallback)(u32, OSContext*);
static __OSInterruptHandler MTRCallback;

int DBRead(void* param1, u32 param2)
{
    BOOL enabled;
    u32 lVar3 = 0;

    enabled = OSDisableInterrupts();
    if (SendMailData & 0x10000) {
        lVar3 = 0x1000;
    }
    DBGRead(lVar3 + 0x1E000, param1, param2 + 3U & 0xFFFFFFFC);
    RecvDataLeng = 0;
    EXIInputFlag = 0;
    OSRestoreInterrupts(enabled);
    return 0;
}

int DBQueryData(void)
{
    BOOL enabled;

    EXIInputFlag = 0;
    if (RecvDataLeng == 0) {
        u32 local_8[2];

        enabled = OSDisableInterrupts();

        DBGReadStatus(local_8);
        if (local_8[0] & 1) {
            DBGReadMailbox(local_8);
            local_8[0] &= ~0xE0000000;
            if ((local_8[0] & 0x1F000000) == 0x1F000000) {
                SendMailData = local_8[0];
                RecvDataLeng = local_8[0] & 0x7FFF;
                EXIInputFlag = 1;
            }
        }

        OSRestoreInterrupts(enabled);
    }
    return RecvDataLeng;
}

int DBInitInterrupts(void)
{
    __OSMaskInterrupts(0x18000);
    __OSMaskInterrupts(0x40);
    DBGCallback = MWCallback;
    __OSSetInterruptHandler(0x19, DBGHandler);
    __OSUnmaskInterrupts(0x40);
}

void DBInitComm(int* inputFlagPtr, int* mtrCallback)
{
    BOOL enabled;

    enabled = OSDisableInterrupts();
    pEXIInputFlag = &EXIInputFlag;
    *inputFlagPtr = (int)pEXIInputFlag;
    MTRCallback = (__OSInterruptHandler)mtrCallback;
    __OSMaskInterrupts(0x18000);
    __EXIRegs[10] = 0;
    OSRestoreInterrupts(enabled);
}

void DBGHandler(__OSInterrupt interrupt, OSContext* context)
{
    __PIRegs[0] = 0x1000;
    if (DBGCallback) {
        (*DBGCallback)(interrupt, context);
    }
}

void MWCallback(u32 interrupt, OSContext* context)
{
    EXIInputFlag = 1;
    if (MTRCallback) {
        (*MTRCallback)(0, context);
    }
}

BOOL DBGReadStatus(void* param_1)
{
    BOOL error = FALSE;
    u32 value;

    if (!DBGEXISelect(4)) {
        return FALSE;
    }

    value = 0x40000000;
    error |= !DBGEXIImm((u8*)&value, 2, 1);
    error |= !DBGEXISync();
    error |= !DBGEXIImm(param_1, sizeof(param_1), 0);
    error |= !DBGEXISync();
    error |= !DBGEXIDeselect();

    return !error;
}

BOOL DBGWrite(u32 param1, u32* data, s32 byte_size)
{
    BOOL error = FALSE;
    u32* dataPtr = data;
    u32 value;
    u32 nextWord;

    if (!DBGEXISelect(4)) {
        return FALSE;
    }

    value = (param1 & 0x1FFFC) << 8 | 0xA0000000;
    error = !DBGEXIImm((u8*)&value, sizeof(value), 1);
    error |= !DBGEXISync();

    while (byte_size != 0) {
        nextWord = *dataPtr++;

        error |= !DBGEXIImm((u8*)&nextWord, sizeof(nextWord), 1);
        error |= !DBGEXISync();

        byte_size -= 4;
        if (byte_size < 0) {
            byte_size = 0;
        }
    }

    error |= !DBGEXIDeselect();

    return !error;
}

BOOL DBGRead(u32 param1, u32* data, s32 byte_size)
{
    BOOL error = FALSE;
    u32* dataPtr = data;
    u32 writeValue;
    u32 readValue;

    if (!DBGEXISelect(4)) {
        return FALSE;
    }

    writeValue = (u32)(param1 << 8) & 0x1FFFC00 | 0x20000000;
    error |= !DBGEXIImm((u8*)&writeValue, sizeof(writeValue), 1);
    error |= !DBGEXISync();

    while (byte_size != 0) {
        error |= !DBGEXIImm((u8*)&readValue, sizeof(readValue), 0);
        error |= !DBGEXISync();

        *dataPtr++ = readValue;

        byte_size -= 4;
        if (byte_size < 0) {
            byte_size = 0;
        }
    }
    error |= !DBGEXIDeselect();

    return !error;
}

BOOL DBGReadMailbox(void* param1)
{
    BOOL error = FALSE;
    u32 local_c;

    if (!DBGEXISelect(4)) {
        return FALSE;
    }

    local_c = 0x60000000;
    error |= !DBGEXIImm((u8*)&local_c, 2, 1);
    error |= !DBGEXISync();
    error |= !DBGEXIImm(param1, sizeof(param1), 0);
    error |= !DBGEXISync();
    error |= !DBGEXIDeselect();

    return !error;
}

BOOL DBGEXIImm(void* data, s32 byte_size, u32 write)
{
    u32 writeVal;
    u32 readVal;
    int i;

    if (write) {
        writeVal = 0;
        for (i = 0; i < byte_size; ++i) {
            writeVal |= ((u8*)data)[i] << ((3 - i) << 3);
        }
        __EXIRegs[14] = writeVal;
    }

    __EXIRegs[13] = 1 | (write << 2) | ((byte_size - 1U) << 4);

    DBGEXISync();
    if (!write) {
        u8* dataPtr = (u8*)data;
        readVal = __EXIRegs[14];
        for (i = 0; i < byte_size; ++i) {
            *dataPtr++ = readVal >> ((3 - i) << 3);
        }
    }

    return TRUE;
}

__declspec(weak) int Hu_IsStub(void)
{
    return 0;
}
