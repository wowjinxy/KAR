#include "dolphin/types.h"

typedef BOOL bool;
#define true 1
#define false 0

typedef enum DSError {
    kUARTError = -0x0001,
    kNoError = 0x0000,
    kStepError = 0x0001,
    kParameterError = 0x0002,
    kEventQueueFull = 0x0100,
    kNoMessageBufferAvailable = 0x0300,
    kMessageBufferOverflow = 0x0301,
    kMessageBufferReadError = 0x0302,
    kDispatchError = 0x0500,
    kInvalidMemory = 0x0700,
    kInvalidRegister = 0x0701,
    kCWDSException = 0x0702,
    kUnsupportedError = 0x0703,
    kInvalidProcessId = 0x0704,
    kInvalidThreadId = 0x0705,
    kOsError = 0x0706,
    kWaitACKError = 0x0800
} DSError;

typedef enum MessageCommandID {
    kDSPing = 0x00,
    kDSConnect = 0x01,
    kDSDisconnect = 0x02,
    kDSReset = 0x03,
    kDSVersions = 0x04,
    kDSSupportMask = 0x05,
    kDSOverride = 0x07,
    kDSReadMemory = 0x10,
    kDSWriteMemory = 0x11,
    kDSReadRegisters = 0x12,
    kDSWriteRegisters = 0x13,
    kDSSetOption = 0x17,
    kDSContinue = 0x18,
    kDSStep = 0x19,
    kDSStop = 0x1A,
    kDSReplyACK = 0x80,
    kDSReplyNAK = 0xFF,
    kDSNotifyStopped = 0x90,
    kDSNotifyException = 0x91,
    kDSWriteFile = 0xD0,
    kDSReadFile = 0xD1,
    kDSOpenFile = 0xD2,
    kDSCloseFile = 0xD3,
    kDSPositionFile = 0xD4
} MessageCommandID;

typedef enum DSReplyError {
    kDSReplyNoError = 0x00,
    kDSReplyError = 0x01,
    kDSReplyPacketSizeError = 0x02,
    kDSReplyCWDSError = 0x03,
    kDSReplyEscapeError = 0x04,
    kDSReplyBadFCS = 0x05,
    kDSReplyOverflow = 0x06,
    kDSReplySequenceMissing = 0x07,
    kDSReplyUnsupportedCommandError = 0x10,
    kDSReplyParameterError = 0x11,
    kDSReplyUnsupportedOptionError = 0x12,
    kDSReplyInvalidMemoryRange = 0x13,
    kDSReplyInvalidRegisterRange = 0x14,
    kDSReplyCWDSException = 0x15,
    kDSReplyNotStopped = 0x16,
    kDSReplyBreakpointsFull = 0x17,
    kDSReplyBreakpointConflict = 0x18,
    kDSReplyOsError = 0x20,
    kDSReplyInvalidProcessId = 0x21,
    kDSReplyInvalidThreadId = 0x22,
    kDSDebugSecurityError = 0x23
} DSReplyError;

typedef enum DSStepType {
    kDSStepIntoCount = 0x00,
    kDSStepIntoRange = 0x01,
    kDSStepOverCount = 0x10,
    kDSStepOverRange = 0x11
} DSStepType;

typedef unsigned int DSMutex;
typedef int MessageBufferID;

#define kMessageBufferSize (0x800 + 0x80)
#define NUM_BUFFERS 3

typedef struct MessageBuffer {
    /* 0x00 */ DSMutex fMutex;
    /* 0x04 */ bool fInUse;
    /* 0x08 */ u32 fLength;
    /* 0x0C */ u32 fPosition;
    /* 0x10 */ u8 fData[kMessageBufferSize];
} MessageBuffer;

typedef struct TRKMsgBufs {
    /* 0x00 */ MessageBuffer buffers[NUM_BUFFERS];
} TRKMsgBufs;

typedef unsigned long NubEventID;

typedef enum NubEventType {
    kNullEvent = 0,
    kShutdownEvent = 1,
    kRequestEvent = 2,
    kBreakpointEvent = 3,
    kExceptionEvent = 4,
    kSupportEvent = 5
} NubEventType;

typedef struct NubEvent {
    /* 0x00 */ int fType;
    /* 0x04 */ NubEventID fID;
    /* 0x08 */ MessageBufferID fMessageBufferID;
} NubEvent;

typedef struct EventQueue {
    /* 0x00 */ u8 pad[4];
    /* 0x04 */ int fCount;
    /* 0x08 */ int fFirst;
    /* 0x0C */ NubEvent fEventList[2];
    /* 0x24 */ NubEventID fEventID;
} EventQueue;

void* TRK_memcpy(void* dst, const void* src, unsigned long n);
void* fn_80003238(void* dest, int val, size_t count); /* memset */
void MWTRACE(int level, const char* fmt, ...);
void fn_803BE624(const char* msg); /* usr_puts_serial */

DSError kar_diagnostic__near_803bff38(void* p1);
DSError kar_diagnostic__803bff30(void* p1);
DSError kar_diagnostic__803bff28(void* p1);

DSError kar_diagnostic__803c2388(const void* bytes, u32 length);

extern bool gTRKBigEndian;
extern TRKMsgBufs lbl_80569E90;

MessageBuffer* TRKGetBuffer(int index);
DSError kar_diag__803be22c(int* bufferIndexPtr, MessageBuffer** destBufPtr);
void kar_diagnostic__803be19c(int index);
void kar_diagnostic__803be15c(MessageBuffer* buf, bool keepData);
DSError kar_diagnostic__803be12c(MessageBuffer* buf, u32 pos);
DSError kar_diagnostic__803be088(MessageBuffer* buf, const void* data, size_t length);
DSError kar_diagnostic__near_803bdffc(MessageBuffer* buf, void* data, size_t length);
DSError TRKInitializeMessageBuffers(void);

DSError kar_diagnostic__803bdf00(MessageBuffer* buffer, const u64 data);
DSError kar_diagnostic__803bde98(MessageBuffer* buffer, const u8* data, int count);
DSError kar_diagnostic__803bdd9c(MessageBuffer* buffer, const u32* data,
                             int count);

DSError kar_diagnostic__803bdcb4(MessageBuffer* buffer, u64* data);
DSError kar_diagnostic__near_803bdc1c(MessageBuffer* buffer, u8* data, int count);
DSError kar_diagnostic__803bdb2c(MessageBuffer* buffer, u32* data, int count);

static inline DSError TRKAppendBuffer1_ui8(MessageBuffer* buffer,
                                           const u8 data)
{
    if (buffer->fPosition >= kMessageBufferSize) {
        return kMessageBufferOverflow;
    }

    buffer->fData[buffer->fPosition++] = data;
    buffer->fLength++;
    return kNoError;
}

static inline DSError TRKAppendBuffer1_ui16(MessageBuffer* buffer,
                                            const u16 data)
{
    u8* bigEndianData;
    u8* byteData;
    u8 swapBuffer[sizeof(data)];

    if (gTRKBigEndian) {
        bigEndianData = (u8*) &data;
    } else {
        byteData = (u8*) &data;
        bigEndianData = swapBuffer;

        bigEndianData[0] = byteData[1];
        bigEndianData[1] = byteData[0];
    }

    return kar_diagnostic__803be088(buffer, (const void*) bigEndianData,
                                    sizeof(data));
}

static inline DSError TRKAppendBuffer1_ui32(MessageBuffer* buffer,
                                            const u32 data)
{
    u8* bigEndianData;
    u8* byteData;
    u8 swapBuffer[sizeof(data)];

    if (gTRKBigEndian) {
        bigEndianData = (u8*) &data;
    } else {
        byteData = (u8*) &data;
        bigEndianData = swapBuffer;

        bigEndianData[0] = byteData[3];
        bigEndianData[1] = byteData[2];
        bigEndianData[2] = byteData[1];
        bigEndianData[3] = byteData[0];
    }

    return kar_diagnostic__803be088(buffer, (const void*) bigEndianData,
                                    sizeof(data));
}

static inline DSError kar_diagnostic__near_803bdffc_impl(MessageBuffer* buf,
                                                         void* data,
                                                         size_t length)
{
    DSError error = kNoError;
    u32 bytesLeft;

    bytesLeft = buf->fLength - buf->fPosition;

    if (length > bytesLeft) {
        error = kMessageBufferReadError;
        length = bytesLeft;
    }

    TRK_memcpy(data, buf->fData + buf->fPosition, length);
    buf->fPosition += length;
    return error;
}

static inline DSError TRKReadBuffer1_ui8(MessageBuffer* buffer, u8* data)
{
    return kar_diagnostic__near_803bdffc_impl(buffer, (void*) data, 1);
}

static inline DSError TRKReadBuffer1_ui16(MessageBuffer* buffer, u16* data)
{
    DSError err;

    u8* bigEndianData;
    u8* byteData;
    u8 swapBuffer[sizeof(*data)];

    if (gTRKBigEndian) {
        bigEndianData = (u8*) data;
    } else {
        bigEndianData = swapBuffer;
    }

    err = kar_diagnostic__near_803bdffc_impl(buffer, (void*) bigEndianData,
                                             sizeof(*data));

    if (!gTRKBigEndian && err == kNoError) {
        byteData = (u8*) data;

        byteData[0] = bigEndianData[1];
        byteData[1] = bigEndianData[0];
    }

    return err;
}

static inline DSError TRKReadBuffer1_ui32(MessageBuffer* buffer, u32* data)
{
    DSError err;

    u8* bigEndianData;
    u8* byteData;
    u8 swapBuffer[sizeof(*data)];

    if (gTRKBigEndian) {
        bigEndianData = (u8*) data;
    } else {
        bigEndianData = swapBuffer;
    }

    err = kar_diagnostic__near_803bdffc_impl(buffer, (void*) bigEndianData,
                                             sizeof(*data));

    if (!gTRKBigEndian && err == kNoError) {
        byteData = (u8*) data;

        byteData[0] = bigEndianData[3];
        byteData[1] = bigEndianData[2];
        byteData[2] = bigEndianData[1];
        byteData[3] = bigEndianData[0];
    }

    return err;
}

extern bool gTRKBigEndian;
extern TRKMsgBufs lbl_80569E90;

DSError TRKInitializeSerialHandler(void);
DSError kar_diag__near_803be368(void);
void TRKGetInput(void);
inline void kar_diag__near_803be434(MessageBufferID bufID);
MessageBufferID kar_diag__803be4e4(void);
extern void* gTRKInputPendingPtr;

void usr_put_initialize(void);

DSError TRKDispatchMessage(MessageBuffer* buffer);
DSError TRKInitializeDispatcher(void);

DSError TRKTargetInterrupt(NubEvent* ev);
DSError TRKTargetSupportRequest(void);
bool TRKTargetStopped(void);
DSError TRKTargetContinue(void);
void TRKTargetSetStopped(bool stopped);
void TRKTargetSetInputPendingPtr(void* ptr);
void InitializeProgramEndTrap(void);
DSError TRKInitializeIntDrivenUART(u32 r3, u32 r4, u32 r5, void* r6);
DSError TRKInitializeTarget(void);

void TRK_board_display(char* str);

DSError kar_diagnostic__near_803c046c(void);
void kar_diag__near_803c27b0(u8 value);
u8 kar_diag__near_803c27a0(void);
DSError kar_diag__near_803c27bc(void);
void kar_diag__near_803c2878(u8 value);
DSError kar_diagnostic__near_803c2018(void);
u32 kar_diagnostic__near_803c2144(u32 addr);
void EnableMetroTRKInterrupts(void);
void TRKUARTInterruptHandler(void);
void TRKEXICallBack(short r3, void* ctx);
void ReserveEXI2Port(void);
void UnreserveEXI2Port(void);
void TRKSwapAndGo(void);

typedef struct msgbuf_t {
    /* 0x00 */ u32 msgLength;
    /* 0x04 */ u8 commandId;
} msgbuf_t;

typedef struct FramingState {
    /* 0x00 */ MessageBufferID fBufferID;
    /* 0x04 */ void* fBuffer;
    /* 0x08 */ u32 fReceiveState;
    /* 0x0C */ u32 fEscape;
    /* 0x10 */ u8 pad[0x18 - 0x10];
} FramingState;
extern FramingState lbl_8056B840;

DSError kar_diagnostic__near_803bf6cc(MessageBuffer* b);
DSError kar_diagnostic__803bf654(MessageBuffer* b);
DSError kar_diagnostic__near_803bf5fc(MessageBuffer* b);
DSError kar_diagnostic__near_803bf59c(MessageBuffer* buf);
DSError kar_diagnostic__near_803bf594(MessageBuffer* buf);
DSError kar_diagnostic__near_803bf5a4(MessageBuffer* b);
DSError kar_diagnostic__803bf3a8(MessageBuffer* buf);
DSError kar_diagnostic__803bf1b4(MessageBuffer* b);
DSError kar_diag__803beed4(MessageBuffer* b);
DSError kar_diagnostic__803bec44(MessageBuffer* b);
DSError kar_diagnostic__near_803be824(MessageBuffer* b);
DSError kar_diagnostic__803beb94(MessageBuffer* b);
DSError kar_diagnostic__803be974(MessageBuffer* b);
DSError kar_diagnostic__near_803be8cc(MessageBuffer* b);

DSError TRKInitializeEventQueue(void);
bool TRKGetNextEvent(NubEvent* ev);
DSError kar_diagnostic__803bd764(NubEvent* ev);
static inline void* TRKCopyEvent(void* src, void* dst)
{
    return TRK_memcpy(src, dst, sizeof(NubEvent));
}
void fn_803BD74C(NubEvent* event, int eventType);
void TRKDestructEvent(NubEvent* event);

static inline void TRKHandleRequestEvent(NubEvent* ev)
{
    TRKDispatchMessage(TRKGetBuffer(ev->fMessageBufferID));
}

static inline void TRKHandleSupportEvent(NubEvent* ev)
{
    TRKTargetSupportRequest();
}

static inline void TRKIdle(void)
{
    if (!TRKTargetStopped()) {
        TRKTargetContinue();
    }
}

void TRKNubMainLoop(void)
{
    NubEvent event;
    bool done = false;
    bool gotInput = false;

    while (!done) {
        if (TRKGetNextEvent(&event) != false) {
            gotInput = false;
            switch (event.fType) {
            case kNullEvent:
                break;
            case kRequestEvent:
                TRKHandleRequestEvent(&event);
                break;
            case kShutdownEvent:
                done = true;
                break;
            case kBreakpointEvent:
            case kExceptionEvent:
                TRKTargetInterrupt(&event);
                break;
            case kSupportEvent:
                TRKHandleSupportEvent(&event);
                break;
            }
            TRKDestructEvent(&event);
        } else if (!gotInput || *(u8*) gTRKInputPendingPtr != 0) {
            gotInput = true;
            TRKGetInput();
        } else {
            TRKIdle();
            gotInput = false;
        }
    }
}

void TRKDestructEvent(NubEvent* event)
{
    kar_diagnostic__803be19c(event->fMessageBufferID);
}

void fn_803BD74C(NubEvent* event, int eventType)
{
    event->fType = eventType;
    event->fID = 0;
    event->fMessageBufferID = -1;
}

EventQueue lbl_80569E60;

DSError kar_diagnostic__803bd764(NubEvent* ev)
{
    DSError ret = kNoError;
    int evID;

    kar_diagnostic__803bff30(&lbl_80569E60);

    if (lbl_80569E60.fCount == 2) {
        ret = kEventQueueFull;
    } else {
        evID = (lbl_80569E60.fFirst + lbl_80569E60.fCount) % 2;
        TRKCopyEvent(&lbl_80569E60.fEventList[evID], ev);
        lbl_80569E60.fEventList[evID].fID = lbl_80569E60.fEventID;
        lbl_80569E60.fEventID++;

        if (lbl_80569E60.fEventID < 256) {
            lbl_80569E60.fEventID = 256;
        }

        lbl_80569E60.fCount++;
    }

    kar_diagnostic__803bff28(&lbl_80569E60);
    return ret;
}

bool TRKGetNextEvent(NubEvent* ev)
{
    bool ret = false;

    kar_diagnostic__803bff30(&lbl_80569E60);

    if (lbl_80569E60.fCount > 0) {
        TRKCopyEvent(ev, &lbl_80569E60.fEventList[lbl_80569E60.fFirst]);
        lbl_80569E60.fCount--;
        lbl_80569E60.fFirst++;

        if (lbl_80569E60.fFirst == 2) {
            lbl_80569E60.fFirst = 0;
        }

        ret = true;
    }

    kar_diagnostic__803bff28(&lbl_80569E60);
    return ret;
}

DSError TRKInitializeEventQueue(void)
{
    kar_diagnostic__near_803bff38(&lbl_80569E60);
    kar_diagnostic__803bff30(&lbl_80569E60);
    lbl_80569E60.fCount = 0;
    lbl_80569E60.fFirst = 0;
    lbl_80569E60.fEventID = 0x100;
    kar_diagnostic__803bff28(&lbl_80569E60);
    return kNoError;
}

void TRKNubWelcome(void)
{
    TRK_board_display("MetroTRK for GAMECUBE v2.0");
}

DSError TRKTerminateNub(void)
{
    kar_diag__near_803be368();
    return kNoError;
}

static inline bool TRKInitializeEndian(void)
{
    u8 bendian[4];
    bool result = false;

    gTRKBigEndian = true;

    bendian[0] = 0x12;
    bendian[1] = 0x34;
    bendian[2] = 0x56;
    bendian[3] = 0x78;

    if (*(u32*) bendian == 0x12345678) {
        gTRKBigEndian = true;
    } else if (*(u32*) bendian == 0x78563412) {
        gTRKBigEndian = false;
    } else {
        result = true;
    }

    return result;
}

DSError TRKInitializeNub(void)
{
    DSError result;
    DSError resultTemp;

    result = TRKInitializeEndian();

    MWTRACE(1, "Initialize NUB\n");

    if (result == kNoError) {
        usr_put_initialize();
    }

    if (result == kNoError) {
        result = TRKInitializeEventQueue();
    }

    if (result == kNoError) {
        result = TRKInitializeMessageBuffers();
    }

    if (result == kNoError) {
        result = TRKInitializeDispatcher();
    }

    InitializeProgramEndTrap();

    if (result == kNoError) {
        result = TRKInitializeSerialHandler();
    }

    if (result == kNoError) {
        result = TRKInitializeTarget();
    }

    if (result == kNoError) {
        resultTemp =
            TRKInitializeIntDrivenUART(0xE100, 1, 0, &gTRKInputPendingPtr);
        TRKTargetSetInputPendingPtr(gTRKInputPendingPtr);
        if (resultTemp != kNoError) {
            result = resultTemp;
        }
    }

    return result;
}

DSError kar_diagnostic__803bdae8(MessageBuffer* msg)
{
    DSError result = kar_diagnostic__803c2388(msg->fData, msg->fLength);
    MWTRACE(1, "MessageSend : cc_write returned %ld\n", result);
    return kNoError;
}

DSError kar_diagnostic__803bdb2c(MessageBuffer* buffer, u32* data, int count)
{
    DSError err;
    int i;

    for (i = 0, err = kNoError; err == kNoError && i < count; i++) {
        err = TRKReadBuffer1_ui32(buffer, &data[i]);
    }

    return err;
}

DSError kar_diagnostic__near_803bdc1c(MessageBuffer* buffer, u8* data, int count)
{
    DSError err;
    int i;

    for (i = 0, err = kNoError; err == kNoError && i < count; i++) {
        err = TRKReadBuffer1_ui8(buffer, &data[i]);
    }

    return err;
}

DSError kar_diagnostic__803bdcb4(MessageBuffer* buffer, u64* data)
{
    DSError err;

    u8* bigEndianData;
    u8* byteData;
    u8 swapBuffer[sizeof(*data)];

    if (gTRKBigEndian) {
        bigEndianData = (u8*) data;
    } else {
        bigEndianData = swapBuffer;
    }

    err = kar_diagnostic__near_803bdffc_impl(buffer, bigEndianData,
                                             sizeof(*data));

    if (!gTRKBigEndian && err == kNoError) {
        byteData = (u8*) data;

        byteData[0] = bigEndianData[7];
        byteData[1] = bigEndianData[6];
        byteData[2] = bigEndianData[5];
        byteData[3] = bigEndianData[4];
        byteData[4] = bigEndianData[3];
        byteData[5] = bigEndianData[2];
        byteData[6] = bigEndianData[1];
        byteData[7] = bigEndianData[0];
    }

    return err;
}

static inline DSError kar_diagnostic__803be088_impl(MessageBuffer* buf,
                                                    const void* data,
                                                    size_t length)
{
    DSError error = kNoError;
    u32 bytesLeft;

    bytesLeft = kMessageBufferSize - buf->fPosition;

    if (bytesLeft < length) {
        error = kMessageBufferOverflow;
        length = bytesLeft;
    }

    if (length == 1) {
        buf->fData[buf->fPosition] = ((u8*) data)[0];
    } else {
        TRK_memcpy(buf->fData + buf->fPosition, data, length);
    }

    buf->fPosition += length;
    buf->fLength = buf->fPosition;

    return error;
}

DSError kar_diagnostic__803bdd9c(MessageBuffer* buffer, const u32* data, int count)
{
    DSError err;
    int i;

    for (i = 0, err = kNoError; err == kNoError && i < count; i++) {
        u8* bigEndianData;
        u8* byteData;
        u8 swapBuffer[sizeof(u32)];
        u32 data32 = data[i];

        if (gTRKBigEndian) {
            bigEndianData = (u8*) &data32;
        } else {
            byteData = (u8*) &data32;
            bigEndianData = swapBuffer;

            bigEndianData[0] = byteData[3];
            bigEndianData[1] = byteData[2];
            bigEndianData[2] = byteData[1];
            bigEndianData[3] = byteData[0];
        }

        err = kar_diagnostic__803be088_impl(buffer, bigEndianData, sizeof(u32));
    }

    return err;
}

DSError kar_diagnostic__803bde98(MessageBuffer* buffer, const u8* data, int count)
{
    DSError err;
    int i;

    for (i = 0, err = kNoError; err == kNoError && i < count; i++) {
        err = TRKAppendBuffer1_ui8(buffer, data[i]);
    }

    return err;
}

DSError kar_diagnostic__803bdf00(MessageBuffer* buffer, const u64 data)
{
    u8* bigEndianData;
    u8* byteData;
    u8 swapBuffer[sizeof(data)];

    if (gTRKBigEndian) {
        bigEndianData = (u8*) &data;
    } else {
        byteData = (u8*) &data;
        bigEndianData = swapBuffer;

        bigEndianData[0] = byteData[7];
        bigEndianData[1] = byteData[6];
        bigEndianData[2] = byteData[5];
        bigEndianData[3] = byteData[4];
        bigEndianData[4] = byteData[3];
        bigEndianData[5] = byteData[2];
        bigEndianData[6] = byteData[1];
        bigEndianData[7] = byteData[0];
    }

    return kar_diagnostic__803be088_impl(buffer, bigEndianData, sizeof(data));
}

DSError kar_diagnostic__near_803bdffc(MessageBuffer* buf, void* data, size_t length)
{
    DSError error = kNoError;
    unsigned int bytesLeft;

    if (length == 0) {
        return kNoError;
    }

    bytesLeft = buf->fLength - buf->fPosition;

    if (length > bytesLeft) {
        error = kMessageBufferReadError;
        length = bytesLeft;
    }

    TRK_memcpy(data, buf->fData + buf->fPosition, length);
    buf->fPosition += length;
    return error;
}

DSError kar_diagnostic__803be088(MessageBuffer* buf, const void* data, size_t length)
{
    DSError error = kNoError;
    u32 bytesLeft;

    if (length == 0) {
        return kNoError;
    }

    bytesLeft = kMessageBufferSize - buf->fPosition;

    if (bytesLeft < length) {
        error = kMessageBufferOverflow;
        length = bytesLeft;
    }

    if (length == 1) {
        buf->fData[buf->fPosition] = ((u8*) data)[0];
    } else {
        TRK_memcpy(buf->fData + buf->fPosition, data, length);
    }

    buf->fPosition += length;
    buf->fLength = buf->fPosition;

    return error;
}

DSError kar_diagnostic__803be12c(MessageBuffer* buf, u32 pos)
{
    DSError error = kNoError;

    if (pos > kMessageBufferSize) {
        error = kMessageBufferOverflow;
    } else {
        buf->fPosition = pos;

        if (pos > buf->fLength) {
            buf->fLength = pos;
        }
    }

    return error;
}

void kar_diagnostic__803be15c(MessageBuffer* buf, bool keepData)
{
    buf->fLength = 0;
    buf->fPosition = 0;

    if (!keepData) {
        fn_80003238(buf->fData, 0, kMessageBufferSize);
    }
}

void kar_diagnostic__803be19c(int index)
{
    MessageBuffer* b;

    if (index == -1) {
        return;
    }

    if (index >= 0 && index < NUM_BUFFERS) {
        b = &lbl_80569E90.buffers[index];
        kar_diagnostic__803bff30(&b->fMutex);
        b->fInUse = false;
        kar_diagnostic__803bff28(&b->fMutex);
    }
}

MessageBuffer* TRKGetBuffer(int index)
{
    MessageBuffer* buf = NULL;

    if (index >= 0 && index < NUM_BUFFERS) {
        buf = &lbl_80569E90.buffers[index];
    }

    return buf;
}

DSError kar_diag__803be22c(int* bufferIndexPtr, MessageBuffer** destBufPtr)
{
    DSError error = kNoMessageBufferAvailable;
    int i;
    *destBufPtr = NULL;

    for (i = 0; i < NUM_BUFFERS; i++) {
        MessageBuffer* buf = TRKGetBuffer(i);

        kar_diagnostic__803bff30(&buf->fMutex);

        if (!buf->fInUse) {
            kar_diagnostic__803be15c(buf, 1);
            buf->fInUse = true;
            *destBufPtr = buf;
            *bufferIndexPtr = i;
            error = kNoError;
            i = NUM_BUFFERS;
        }

        kar_diagnostic__803bff28(&buf->fMutex);
    }

    if (error == kNoMessageBufferAvailable) {
        fn_803BE624("ERROR : No buffer available\n");
    }

    return error;
}

TRKMsgBufs lbl_80569E90;

DSError TRKInitializeMessageBuffers(void)
{
    int i;

    for (i = 0; i < NUM_BUFFERS; i++) {
        kar_diagnostic__near_803bff38(&lbl_80569E90.buffers[i].fMutex);
        kar_diagnostic__803bff30(&lbl_80569E90.buffers[i].fMutex);
        lbl_80569E90.buffers[i].fInUse = false;
        kar_diagnostic__803bff28(&lbl_80569E90.buffers[i].fMutex);
    }

    return kNoError;
}

DSError kar_diag__near_803be368(void)
{
    return kNoError;
}

extern u8 lbl_8048BC78[];

DSError TRKInitializeSerialHandler(void)
{
    const char* fmt = (const char*) lbl_8048BC78;

    lbl_8056B840.fBufferID = -1;
    lbl_8056B840.fReceiveState = 0;
    lbl_8056B840.fEscape = 0;

    MWTRACE(1, fmt + 0x00, 0x40);
    MWTRACE(1, fmt + 0x24, 0x40);
    MWTRACE(1, fmt + 0x48, 0x40);
    MWTRACE(1, fmt + 0x6c, 0x40);
    MWTRACE(1, fmt + 0x8c, 0x40);
    MWTRACE(1, fmt + 0xac, 0x40);

    return kNoError;
}

inline void kar_diag__near_803be434(MessageBufferID bufID)
{
    NubEvent event;

    fn_803BD74C(&event, kRequestEvent);
    event.fMessageBufferID = bufID;
    lbl_8056B840.fBufferID = -1;
    kar_diagnostic__803bd764(&event);
}

#pragma dont_inline on
void TRKGetInput(void)
{
    MessageBufferID bufID;
    NubEvent event;

    bufID = kar_diag__803be4e4();

    if (bufID != -1) {
        TRKGetBuffer(bufID);
        fn_803BD74C(&event, kRequestEvent);
        event.fMessageBufferID = bufID;
        lbl_8056B840.fBufferID = -1;
        kar_diagnostic__803bd764(&event);
    }
}
#pragma dont_inline reset

void usr_put_initialize(void) {}

DSError TRKDispatchMessage(MessageBuffer* buffer)
{
    DSError result = kDispatchError;
    msgbuf_t* msg = (msgbuf_t*) buffer->fData;

    kar_diagnostic__803be12c(buffer, 0);
    MWTRACE(1, "Dispatch command 0x%08x\n", msg->commandId);

    switch (msg->commandId) {
    case kDSConnect:
        result = kar_diagnostic__near_803bf6cc(buffer);
        break;
    case kDSDisconnect:
        result = kar_diagnostic__803bf654(buffer);
        break;
    case kDSReset:
        result = kar_diagnostic__near_803bf5fc(buffer);
        break;
    case kDSVersions:
        result = kar_diagnostic__near_803bf59c(buffer);
        break;
    case kDSSupportMask:
        result = kar_diagnostic__near_803bf594(buffer);
        break;
    case kDSOverride:
        result = kar_diagnostic__near_803bf5a4(buffer);
        break;
    case kDSReadMemory:
        result = kar_diagnostic__803bf3a8(buffer);
        break;
    case kDSWriteMemory:
        result = kar_diagnostic__803bf1b4(buffer);
        break;
    case kDSReadRegisters:
        result = kar_diag__803beed4(buffer);
        break;
    case kDSWriteRegisters:
        result = kar_diagnostic__803bec44(buffer);
        break;
    case kDSSetOption:
        result = kar_diagnostic__near_803be824(buffer);
        break;
    case kDSContinue:
        result = kar_diagnostic__803beb94(buffer);
        break;
    case kDSStep:
        result = kar_diagnostic__803be974(buffer);
        break;
    case kDSStop:
        result = kar_diagnostic__near_803be8cc(buffer);
        break;
    default:
        break;
    }

    MWTRACE(1, "Dispatch complete err = %ld\n", result);
    return result;
}

DSError TRKInitializeDispatcher(void)
{
    return kNoError;
}

typedef struct RawAckMsg {
    /* 0x00 */ u32 length;
    /* 0x04 */ u8 commandId;
    /* 0x05 */ u8 pad1[3];
    /* 0x08 */ u8 replyError;
    /* 0x09 */ u8 pad2[0x40 - 9];
} RawAckMsg;

extern void* memset(void* dest, int val, unsigned long n);
extern int memcpy(void* dest, const void* src, unsigned long n);
extern unsigned long strlen(const char* s);
extern void OSReport(const char* fmt, ...);
extern void TEA_HotReset(void);

DSError kar_diagnostic__803c2388(const void* bytes, u32 length);

static inline void TRKSendAck(u8 replyError)
{
    RawAckMsg ack;

    memset(&ack, 0, sizeof(ack));
    ack.length = sizeof(ack);
    ack.commandId = kDSReplyACK;
    ack.replyError = replyError;
    kar_diagnostic__803c2388(&ack, sizeof(ack));
}

extern u8 lbl_8048BE48[];

DSError kar_diagnostic__near_803be824(MessageBuffer* buf)
{
    u8 setting = buf->fData[8];
    u8 value = buf->fData[0xC];

    if (setting == 1) {
        fn_803BE624((const char*) lbl_8048BE48 + 0x0);

        if (value != 0) {
            fn_803BE624((const char*) lbl_8048BE48 + 0x20);
        } else {
            fn_803BE624((const char*) lbl_8048BE48 + 0x28);
        }

        kar_diag__near_803c27b0(value);
    }

    TRKSendAck(kDSReplyNoError);
    return kNoError;
}

DSError kar_diagnostic__near_803be8cc(MessageBuffer* buf)
{
    DSReplyError reply;

    switch (kar_diagnostic__near_803c046c()) {
    case kInvalidProcessId:
        reply = kDSReplyInvalidProcessId;
        break;
    case kInvalidThreadId:
        reply = kDSReplyInvalidThreadId;
        break;
    case kOsError:
        reply = kDSReplyOsError;
        break;
    case kNoError:
        reply = kDSReplyNoError;
        break;
    default:
        reply = kDSReplyError;
        break;
    }

    TRKSendAck(reply);
    return kNoError;
}

DSError kar_diagnostic__near_803c076c(u32 count, bool stepOver);
DSError kar_diagnostic__near_803c06b4(u32 rangeStart, u32 rangeEnd, bool stepOver);
u32 kar_diagnostic__near_803c06a4(void);

DSError kar_diagnostic__803be974(MessageBuffer* buf)
{
    u8 type;
    u32 rangeStart;
    u32 rangeEnd;

    kar_diagnostic__803be12c(buf, 0);

    type = buf->fData[8];
    rangeStart = *(u32*) (buf->fData + 0x10);
    rangeEnd = *(u32*) (buf->fData + 0x14);

    if (type == kDSStepIntoCount || type == kDSStepOverCount) {
        u8 count = buf->fData[0xC];

        if (count < 1) {
            TRKSendAck(kDSReplyParameterError);
            return kNoError;
        }
    } else if (type == kDSStepIntoRange || type == kDSStepOverRange) {
        u32 pc = kar_diagnostic__near_803c06a4();

        if (pc < rangeStart || pc > rangeEnd) {
            TRKSendAck(kDSReplyParameterError);
            return kNoError;
        }
    } else {
        TRKSendAck(kDSReplyUnsupportedOptionError);
        return kNoError;
    }

    if (!TRKTargetStopped()) {
        TRKSendAck(kDSReplyNotStopped);
        return kNoError;
    }

    TRKSendAck(kDSReplyNoError);

    if (type == kDSStepIntoCount || type == kDSStepOverCount) {
        u8 count = buf->fData[0xC];
        kar_diagnostic__near_803c076c(count, type == kDSStepOverCount);
    } else if (type == kDSStepIntoRange || type == kDSStepOverRange) {
        kar_diagnostic__near_803c06b4(rangeStart, rangeEnd,
                                      type == kDSStepOverRange);
    }

    return kNoError;
}

extern u8 lbl_8048BE7C[];

DSError kar_diagnostic__803beb94(MessageBuffer* buf)
{
    MWTRACE(1, (const char*) lbl_8048BE7C);

    if (!TRKTargetStopped()) {
        TRKSendAck(kDSReplyNotStopped);
        return kNoError;
    }

    TRKSendAck(kDSReplyNoError);
    TRKTargetContinue();
    return kNoError;
}

extern u8 lbl_8056B858[];
extern u8 lbl_8048BE48[];

DSError kar_diagnostic__803c15d8(u32 firstRegister, u32 lastRegister,
                                 MessageBuffer* b, size_t* length, bool read);
DSError kar_diagnostic__803c0f9c(u32 firstRegister, u32 lastRegister,
                                 MessageBuffer* b, size_t* length, bool read);
DSError kar_diagnostic__803c110c(u32 firstRegister, u32 lastRegister,
                                 MessageBuffer* b, size_t* length, bool read);
DSError kar_diagnostic__803c0b64(u32 firstRegister, u32 lastRegister,
                                 MessageBuffer* b, size_t* length, bool read);

static inline DSReplyError kar_diagnostic__near_803c0f9c_reply_map(DSError error)
{
    switch (error) {
    case kUnsupportedError:
        return kDSReplyUnsupportedOptionError;
    case kInvalidRegister:
        return kDSReplyInvalidRegisterRange;
    case kCWDSException:
        return kDSReplyCWDSException;
    case kInvalidProcessId:
        return kDSReplyInvalidProcessId;
    case kInvalidThreadId:
        return kDSReplyInvalidThreadId;
    case kOsError:
        return kDSReplyOsError;
    default:
        return kDSReplyCWDSError;
    }
}

DSError kar_diagnostic__803bec44(MessageBuffer* buf)
{
    u8 sp9 = buf->fData[8];
    u16 firstRegister = *(u16*) (buf->fData + 0xC);
    u16 lastRegister = *(u16*) (buf->fData + 0x10);
    DSError error;
    size_t length;

    kar_diagnostic__803be12c(buf, 0);

    if (firstRegister > lastRegister) {
        TRKSendAck(kDSReplyInvalidRegisterRange);
        return kNoError;
    }

    kar_diagnostic__803be12c(buf, 0x40);

    switch (sp9) {
    case 2:
        error = kar_diagnostic__803c0b64(firstRegister, lastRegister, buf,
                                         &length, 0);
        break;
    case 0:
        error = kar_diagnostic__803c15d8(firstRegister, lastRegister, buf,
                                         &length, 0);
        break;
    case 1:
        error = kar_diagnostic__803c110c(firstRegister, lastRegister, buf,
                                         &length, 0);
        break;
    case 4:
        error = kar_diagnostic__803c0f9c(firstRegister, lastRegister, buf,
                                         &length, 0);
        break;
    default:
        error = kUnsupportedError;
        break;
    }

    kar_diagnostic__803be15c(buf, 0);

    if (error == kNoError) {
        RawAckMsg ack;

        memset(&ack, 0, sizeof(ack));
        ack.length = 0x40;
        ack.commandId = kDSReplyACK;
        kar_diagnostic__803c2388(&ack, sizeof(ack));
        return kNoError;
    }

    TRKSendAck(kar_diagnostic__near_803c0f9c_reply_map(error));
    return kNoError;
}

DSError kar_diag__803beed4(MessageBuffer* buf)
{
    u16 firstRegister = *(u16*) (buf->fData + 0xC);
    u16 lastRegister = *(u16*) (buf->fData + 0x10);
    DSError error;
    size_t length;

    if (firstRegister > lastRegister) {
        TRKSendAck(kDSReplyInvalidRegisterRange);
        return kNoError;
    }

    MWTRACE(1, (const char*) lbl_8048BE48 + 0x98, buf->fLength);
    kar_diagnostic__803bde98(buf, buf->fData, 0x40);
    MWTRACE(1, (const char*) lbl_8048BE48 + 0x98, buf->fLength);

    error = kar_diagnostic__803c15d8(0, 0x24, buf, &length, 1);

    MWTRACE(1, (const char*) lbl_8048BE48 + 0xC0, error);
    MWTRACE(1, (const char*) lbl_8048BE48 + 0x98, buf->fLength);

    if (error != kNoError) {
        TRKSendAck(kar_diagnostic__near_803c0f9c_reply_map(error));
        return kNoError;
    }

    error = kar_diagnostic__803bdae8(buf);
    return error;
}

typedef enum MemoryAccessOptions {
    kUserMemory = 0,
    kDebuggerMemory = 1
} MemoryAccessOptions;

DSError fn_803C1718(void* data, u32 start, size_t* length,
                    MemoryAccessOptions accessOptions, bool read);

static inline DSReplyError kar_diagnostic__near_803bf730_reply_map(DSError error)
{
    switch (error) {
    case kCWDSException:
        return kDSReplyCWDSException;
    case kInvalidMemory:
        return kDSReplyInvalidMemoryRange;
    case kInvalidProcessId:
        return kDSReplyInvalidProcessId;
    case kInvalidThreadId:
        return kDSReplyInvalidThreadId;
    case kOsError:
        return kDSReplyOsError;
    default:
        return kDSReplyCWDSError;
    }
}

DSError kar_diagnostic__803bf1b4(MessageBuffer* buf)
{
    u8 sp8 = buf->fData[4];
    u8 sp9 = buf->fData[8];
    u16 spA = *(u16*) (buf->fData + 0xC);
    u32 spC = *(u32*) (buf->fData + 0x10);
    DSError error;
    u8 buffer[0x800] __attribute__((aligned(32)));
    size_t sp10;

    MWTRACE(1, (const char*) lbl_8048BE48 + 0x180, sp8, spC, spA, sp9);

    if (sp9 & 2) {
        TRKSendAck(kDSReplyUnsupportedOptionError);
        return kNoError;
    }

    kar_diagnostic__803be12c(buf, 0x40);
    error = kar_diagnostic__near_803bdffc(buf, buffer, spA);

    sp10 = spA;
    error = fn_803C1718(buffer, spC, &sp10, !(sp9 & 8), 0);

    kar_diagnostic__803be15c(buf, 0);

    if (error == kNoError) {
        spA = sp10;
        kar_diagnostic__803be088(buf, &spA, sizeof(spA));
    }

    if (error != kNoError) {
        TRKSendAck(kar_diagnostic__near_803bf730_reply_map(error));
        return kNoError;
    }

    MWTRACE(1, (const char*) lbl_8048BE48 + 0x60);
    error = kar_diagnostic__803bdae8(buf);
    MWTRACE(1, (const char*) lbl_8048BE48 + 0x80, error);
    return error;
}

DSError kar_diagnostic__803bf3a8(MessageBuffer* buf)
{
    u8 sp8 = buf->fData[4];
    u8 sp9 = buf->fData[8];
    u16 spA = *(u16*) (buf->fData + 0xC);
    u32 spC = *(u32*) (buf->fData + 0x10);
    DSError error;
    u8 buffer[0x800] __attribute__((aligned(32)));
    size_t sp10;

    MWTRACE(1, (const char*) lbl_8048BE48 + 0x1B0, sp8, spC, spA, sp9);

    if (sp9 & 2) {
        TRKSendAck(kDSReplyUnsupportedOptionError);
        return kNoError;
    }

    sp10 = spA;
    error = fn_803C1718(buffer, spC, &sp10, !(sp9 & 8), 1);

    kar_diagnostic__803be15c(buf, 0);

    if (error == kNoError) {
        spA = sp10;
        kar_diagnostic__803be088(buf, &spA, sizeof(spA));
        kar_diagnostic__803be088(buf, buffer, spA);
    }

    if (error != kNoError) {
        TRKSendAck(kar_diagnostic__near_803bf730_reply_map(error));
        return kNoError;
    }

    MWTRACE(1, (const char*) lbl_8048BE48 + 0x60);
    error = kar_diagnostic__803bdae8(buf);
    MWTRACE(1, (const char*) lbl_8048BE48 + 0x80, error);
    return error;
}

DSError kar_diagnostic__near_803bf594(MessageBuffer* buf)
{
    return kNoError;
}

DSError kar_diagnostic__near_803bf59c(MessageBuffer* buf)
{
    return kNoError;
}

DSError kar_diagnostic__near_803bf5a4(MessageBuffer* buf)
{
    TRKSendAck(kDSReplyNoError);
    kar_diagnostic__near_803c2018();
    return kNoError;
}

DSError kar_diagnostic__near_803bf5fc(MessageBuffer* buf)
{
    TRKSendAck(kDSReplyNoError);
    TEA_HotReset();
    return kNoError;
}

DSError kar_diagnostic__803bf654(MessageBuffer* buf)
{
    NubEvent event;

    *(u32*) lbl_8056B858 = 0;
    TRKSendAck(kDSReplyNoError);
    fn_803BD74C(&event, kShutdownEvent);
    kar_diagnostic__803bd764(&event);
    return kNoError;
}

DSError kar_diagnostic__near_803bf6cc(MessageBuffer* buf)
{
    *(u32*) lbl_8056B858 = 1;
    TRKSendAck(kDSReplyNoError);
    return kNoError;
}

DSError kar_diagnostic__803bff28(void* p1)
{
    return kNoError;
}

DSError kar_diagnostic__803bff30(void* p1)
{
    return kNoError;
}

DSError kar_diagnostic__near_803bff38(void* p1)
{
    return kNoError;
}

asm void kar_diagnostic__803bffd8(u32 addr, u32 length)
{
    nofralloc
    lis r5, 0xFFFF
    ori r5, r5, 0xFFF1
    and r5, r5, r3
    subf r3, r5, r3
    add r4, r4, r3
rept:
    dcbst 0, r5
    dcbf 0, r5
    sync
    icbi 0, r5
    addic r5, r5, 0x8
    subic. r4, r4, 0x8
    bge rept
    isync
    blr
}

void fn_803C0010(void* dest, int val, size_t count);


void fn_803C0010(void* dest, int val, size_t count)
{
    u32 v = (u8) val;
    u32 i;
    union {
        u8* cpd;
        u32* lpd;
    } dstu;

    dstu.cpd = (u8*) dest - 1;

    if (count >= 32) {
        i = ~(u32) dstu.cpd & 3;

        if (i) {
            count -= i;

            do {
                *++(dstu.cpd) = (u8) v;
            } while (--i);
        }

        if (v) {
            v |= ((v << 24) | (v << 16) | (v << 8));
        }

        dstu.lpd = (((u32*) (dstu.cpd + 1)) - 1);
        i = (count >> 5);

        if (i) {
            do {
                *++(dstu.lpd) = v;
                *++(dstu.lpd) = v;
                *++(dstu.lpd) = v;
                *++(dstu.lpd) = v;
                *++(dstu.lpd) = v;
                *++(dstu.lpd) = v;
                *++(dstu.lpd) = v;
                *++(dstu.lpd) = v;
            } while (--i);
        }

        i = ((count & 31) >> 2);

        if (i) {
            do {
                *++(dstu.lpd) = v;
            } while (--i);
        }

        dstu.cpd = (((u8*) (dstu.lpd + 1)) - 1);
        count &= 3;
    }

    if (count) {
        do {
            *++(dstu.cpd) = (u8) v;
        } while (--count);
    }
}

asm u32 kar_diagnostic__near_803c00c8(void)
{
    nofralloc
    mfmsr r3
    blr
}

asm void kar_diagnostic__near_803c00d0(u32 val)
{
    nofralloc
    mtmsr r3
    blr
}

asm void kar_diagnostic__near_803c00d8(void* dest, const void* src, int n,
                                       u32 msrA, u32 msrB)
{
    nofralloc
    mfmsr r8
    li r10, 0
loop:
    cmpw r10, r5
    beq end
    mtmsr r7
    sync
    lbzx r9, r10, r4
    mtmsr r6
    sync
    stbx r9, r10, r3
    addi r10, r10, 1
    b loop
end:
    mtmsr r8
    sync
    blr
}

void TRKTargetSetInputPendingPtr(void* ptr);
void TRKTargetSetStopped(bool stopped);
bool TRKTargetStopped(void);
extern u8 gTRKState[];
extern u8 gTRKCPUState[];
extern u8 gTRKRestoreFlags[];
extern u8 gTRKExceptionStatus[];
extern u8 gTRKSaveState[];
extern u16 TRK_saved_exceptionID;
void TRKSaveExtended1Block(void);
void TRKRestoreExtended1Block(void);
void TRKInterruptHandlerEnableInterrupts(void);
void TRKExceptionHandler(u16 id);

void TRKTargetSetInputPendingPtr(void* ptr)
{
    *(void**) (gTRKState + 0xA0) = ptr;
}

#pragma dont_inline on
void TRKTargetSetStopped(bool stopped)
{
    *(bool*) (gTRKState + 0x98) = stopped;
}
#pragma dont_inline reset

bool TRKTargetStopped(void)
{
    return *(bool*) (gTRKState + 0x98);
}

DSError kar_diagnostic__near_803c046c(void)
{
    *(bool*) (gTRKState + 0x98) = true;
    return kNoError;
}

void TRKPostInterruptEvent(void);
void TRKUARTInterruptHandler(void);

asm void TRKInterruptHandler(u16 exceptionID)
{
    nofralloc
    mtsrr0 r2
    mtsrr1 r4
    mfsprg r4, 3
    mfcr r2
    mtsprg 3, r2
    lis r2, gTRKState@h
    ori r2, r2, gTRKState@l
    lwz r2, 0x8c(r2)
    ori r2, r2, 0x8002
    xori r2, r2, 0x8002
    sync
    mtmsr r2
    sync
    lis r2, TRK_saved_exceptionID@h
    ori r2, r2, TRK_saved_exceptionID@l
    sth r3, 0(r2)
    cmpwi r3, 0x500
    bne notUART
    lis r2, gTRKCPUState@h
    ori r2, r2, gTRKCPUState@l
    mflr r3
    stw r3, 0x42c(r2)
    bl TRKUARTInterruptHandler
    lis r2, gTRKCPUState@h
    ori r2, r2, gTRKCPUState@l
    lwz r3, 0x42c(r2)
    mtlr r3
    lis r2, gTRKState@h
    ori r2, r2, gTRKState@l
    lwz r2, 0xa0(r2)
    lbz r2, 0(r2)
    cmpwi r2, 0
    beq noOutgoingInput
    lis r2, gTRKExceptionStatus@h
    ori r2, r2, gTRKExceptionStatus@l
    lbz r2, 0xc(r2)
    cmpwi r2, 1
    beq noOutgoingInput
    lis r2, gTRKState@h
    ori r2, r2, gTRKState@l
    li r3, 1
    stb r3, 0x9c(r2)
    b notUART
noOutgoingInput:
    lis r2, gTRKSaveState@h
    ori r2, r2, gTRKSaveState@l
    lwz r3, 0x88(r2)
    mtcrf 255, r3
    lwz r3, 0xc(r2)
    lwz r2, 8(r2)
    rfi
notUART:
    lis r2, TRK_saved_exceptionID@h
    ori r2, r2, TRK_saved_exceptionID@l
    lhz r3, 0(r2)
    lis r2, gTRKExceptionStatus@h
    ori r2, r2, gTRKExceptionStatus@l
    lbz r2, 0xc(r2)
    cmpwi r2, 0
    bne TRKExceptionHandler
    lis r2, gTRKCPUState@h
    ori r2, r2, gTRKCPUState@l
    stw r0, 0(r2)
    stw r1, 4(r2)
    mfsprg r0, 1
    stw r0, 8(r2)
    sth r3, 0x2f8(r2)
    sth r3, 0x2fa(r2)
    mfsprg r0, 2
    stw r0, 0xc(r2)
    stmw r4, 0x10(r2)
    mfsrr0 r27
    mflr r28
    mfsprg r29, 3
    mfctr r30
    mfxer r31
    stmw r27, 0x80(r2)
    bl TRKSaveExtended1Block
    lis r2, gTRKExceptionStatus@h
    ori r2, r2, gTRKExceptionStatus@l
    li r3, 1
    stb r3, 0xc(r2)
    lis r2, gTRKState@h
    ori r2, r2, gTRKState@l
    lwz r0, 0x8c(r2)
    sync
    mtmsr r0
    sync
    lwz r0, 0x80(r2)
    mtlr r0
    lwz r0, 0x84(r2)
    mtctr r0
    lwz r0, 0x88(r2)
    mtxer r0
    lwz r0, 0x94(r2)
    mtdsisr r0
    lwz r0, 0x90(r2)
    mtdar r0
    lmw r3, 0xc(r2)
    lwz r0, 0(r2)
    lwz r1, 4(r2)
    lwz r2, 8(r2)
    b TRKPostInterruptEvent
}

asm void TRKExceptionHandler(u16 id)
{
    nofralloc
    addis r2, r0, gTRKExceptionStatus@h
    ori r2, r2, gTRKExceptionStatus@l
    sth r3, 8(r2)
    mfsrr0 r3
    stw r3, 0(r2)
    lhz r3, 8(r2)
    cmpwi r3, 0x200
    beq skip_instr
    cmpwi r3, 0x300
    beq skip_instr
    cmpwi r3, 0x400
    beq skip_instr
    cmpwi r3, 0x600
    beq skip_instr
    cmpwi r3, 0x700
    beq skip_instr
    cmpwi r3, 0x800
    beq skip_instr
    cmpwi r3, 0x1000
    beq skip_instr
    cmpwi r3, 0x1100
    beq skip_instr
    cmpwi r3, 0x1200
    beq skip_instr
    cmpwi r3, 0x1300
    beq skip_instr
    b set
skip_instr:
    mfsrr0 r3
    addi r3, r3, 4
    mtsrr0 r3
set:
    addis r2, r0, gTRKExceptionStatus@h
    ori r2, r2, gTRKExceptionStatus@l
    li r3, 1
    stb r3, 0xd(r2)
    mfsprg r3, 3
    mtcrf 255, r3
    mfsprg r2, 1
    mfsprg r3, 2
    rfi
}

asm void TRKSwapAndGo(void)
{
    nofralloc
    lis r3, gTRKState@h
    ori r3, r3, gTRKState@l
    stmw r0, 0(r3)
    mfmsr r0
    stw r0, 0x8c(r3)
    mflr r0
    stw r0, 0x80(r3)
    mfctr r0
    stw r0, 0x84(r3)
    mfxer r0
    stw r0, 0x88(r3)
    mfdsisr r0
    stw r0, 0x94(r3)
    mfdar r0
    stw r0, 0x90(r3)
    li r1, -0x7ffe
    nor r1, r1, r1
    mfmsr r3
    and r3, r3, r1
    mtmsr r3
    lis r2, gTRKState@h
    ori r2, r2, gTRKState@l
    lwz r2, 0xa0(r2)
    lbz r2, 0(r2)
    cmpwi r2, 0
    beq notInputActivated
    lis r2, gTRKState@h
    ori r2, r2, gTRKState@l
    li r3, 1
    stb r3, 0x9c(r2)
    b TRKInterruptHandlerEnableInterrupts
notInputActivated:
    lis r2, gTRKExceptionStatus@h
    ori r2, r2, gTRKExceptionStatus@l
    li r3, 0
    stb r3, 0xc(r2)
    bl TRKRestoreExtended1Block
    lis r2, gTRKCPUState@h
    ori r2, r2, gTRKCPUState@l
    lmw r27, 0x80(r2)
    mtsrr0 r27
    mtlr r28
    mtcrf 255, r29
    mtctr r30
    mtxer r31
    lmw r3, 0xc(r2)
    lwz r0, 0(r2)
    lwz r1, 4(r2)
    lwz r2, 8(r2)
    rfi
}

asm void TRKInterruptHandlerEnableInterrupts(void)
{
    nofralloc
    lis r2, gTRKState@h
    ori r2, r2, gTRKState@l
    lwz r0, 0x8c(r2)
    sync
    mtmsr r0
    sync
    lwz r0, 0x80(r2)
    mtlr r0
    lwz r0, 0x84(r2)
    mtctr r0
    lwz r0, 0x88(r2)
    mtxer r0
    lwz r0, 0x94(r2)
    mtdsisr r0
    lwz r0, 0x90(r2)
    mtdar r0
    lmw r3, 0xc(r2)
    lwz r0, 0(r2)
    lwz r1, 4(r2)
    lwz r2, 8(r2)
    b TRKPostInterruptEvent
}

DSError fn_803C16CC(void* data, u32 start)
{
    size_t length = 4;
    DSError err = fn_803C1718(data, start, &length, kUserMemory, 1);

    if (err == kNoError && length != 4) {
        err = 0x700;
    }

    return err;
}

asm void gap_03_803C1B08_text(void)
{
    nofralloc
    opword 0x00000000
    opword 0x00000000
}

asm void fn_803C1B10(void)
{
    nofralloc
    twi 31, r0, 0
    blr
}

asm void fn_803C1B18(void)
{
    nofralloc
    twi 31, r0, 0
    blr
}

asm void fn_803C1B20(void)
{
    nofralloc
    twi 31, r0, 0
    blr
}

asm void fn_803C1B28(void)
{
    nofralloc
    twi 31, r0, 0
    blr
}

asm void TRKSaveExtended1Block(void)
{
    nofralloc
    lis r2, gTRKCPUState@h
    ori r2, r2, gTRKCPUState@l
    mfsr r16, 0
    mfsr r17, 1
    mfsr r18, 2
    mfsr r19, 3
    mfsr r20, 4
    mfsr r21, 5
    mfsr r22, 6
    mfsr r23, 7
    mfsr r24, 8
    mfsr r25, 9
    mfsr r26, 10
    mfsr r27, 11
    mfsr r28, 12
    mfsr r29, 13
    mfsr r30, 14
    mfsr r31, 15
    stmw r16, 0x1a8(r2)
    mftb r10, 268
    mftb r11, 269
    mfspr r12, hid0
    mfspr r13, hid1
    mfsrr1 r14
    mfspr r15, pvr
    mfibatu r16, 0
    mfibatl r17, 0
    mfibatu r18, 1
    mfibatl r19, 1
    mfibatu r20, 2
    mfibatl r21, 2
    mfibatu r22, 3
    mfibatl r23, 3
    mfdbatu r24, 0
    mfdbatl r25, 0
    mfdbatu r26, 1
    mfdbatl r27, 1
    mfdbatu r28, 2
    mfdbatl r29, 2
    mfdbatu r30, 3
    mfdbatl r31, 3
    stmw r10, 0x1e8(r2)
    mfsdr1 r22
    mfdar r23
    mfdsisr r24
    mfsprg r25, 0
    mfsprg r26, 1
    mfsprg r27, 2
    mfsprg r28, 3
    li r29, 0
    mfspr r30, iabr
    mfear r31
    stmw r22, 0x25c(r2)
    mfspr r20, 912
    mfspr r21, 913
    mfspr r22, 914
    mfspr r23, 915
    mfspr r24, 916
    mfspr r25, 917
    mfspr r26, 918
    mfspr r27, 919
    mfspr r28, 920
    mfspr r29, 921
    mfspr r30, 922
    mfspr r31, 923
    stmw r20, 0x2fc(r2)
    b common
    mfspr r16, 928
    mfspr r17, 935
    mfspr r18, 936
    mfspr r19, 937
    mfspr r20, 938
    mfspr r21, 939
    mfspr r22, 940
    mfspr r23, 941
    mfspr r24, 942
    mfspr r25, 943
    mfspr r26, 944
    mfspr r27, 951
    mfspr r28, 959
    mfspr r29, 1014
    mfspr r30, 1015
    mfspr r31, 1023
    stmw r16, 0x2b8(r2)
common:
    mfspr r19, 1013
    mfspr r20, 953
    mfspr r21, 954
    mfspr r22, 957
    mfspr r23, 958
    mfspr r24, 955
    mfspr r25, 952
    mfspr r26, 956
    mfspr r27, 1020
    mfspr r28, 1021
    mfspr r29, 1022
    mfspr r30, 1019
    mfspr r31, 1017
    stmw r19, 0x284(r2)
    blr
    mfspr r25, 976
    mfspr r26, 977
    mfspr r27, 978
    mfspr r28, 979
    mfspr r29, 980
    mfspr r30, 981
    mfspr r31, 982
    stmw r25, 0x240(r2)
    mfdec r31
    stw r31, 0x278(r2)
    blr
}

asm void TRKRestoreExtended1Block(void)
{
    nofralloc
    lis r2, gTRKCPUState@h
    ori r2, r2, gTRKCPUState@l
    lis r5, gTRKRestoreFlags@h
    ori r5, r5, gTRKRestoreFlags@l
    lbz r3, 0(r5)
    lbz r6, 1(r5)
    li r0, 0
    stb r0, 0(r5)
    stb r0, 1(r5)
    cmpwi r3, 0
    beq noTbrRestore
    lwz r24, 0x1e8(r2)
    lwz r25, 0x1ec(r2)
    mttbl r24
    mttbu r25
noTbrRestore:
    lmw r20, 0x2fc(r2)
    mtspr 912, r20
    mtspr 913, r21
    mtspr 914, r22
    mtspr 915, r23
    mtspr 916, r24
    mtspr 917, r25
    mtspr 918, r26
    mtspr 919, r27
    mtspr 920, r28
    mtspr 922, r30
    mtspr 923, r31
    b common
    lmw r26, 0x2e0(r2)
    mtspr 944, r26
    mtspr 951, r27
    mtspr 1014, r29
    mtspr 1015, r30
    mtspr 1023, r31
common:
    lmw r19, 0x284(r2)
    mtspr 1013, r19
    mtspr 953, r20
    mtspr 954, r21
    mtspr 957, r22
    mtspr 958, r23
    mtspr 955, r24
    mtspr 952, r25
    mtspr 956, r26
    mtspr 1020, r27
    mtspr 1021, r28
    mtspr 1022, r29
    mtspr 1019, r30
    mtspr 1017, r31
    b noDecRestoreBlock
    cmpwi r6, 0
    beq noDecRestore
    lwz r26, 0x278(r2)
    mtdec r26
noDecRestore:
    lmw r25, 0x240(r2)
    mtspr 976, r25
    mtspr 977, r26
    mtspr 978, r27
    mtspr 979, r28
    mtspr 980, r29
    mtspr 981, r30
    mtspr 982, r31
noDecRestoreBlock:
    lmw r16, 0x1a8(r2)
    mtsr 0, r16
    mtsr 1, r17
    mtsr 2, r18
    mtsr 3, r19
    mtsr 4, r20
    mtsr 5, r21
    mtsr 6, r22
    mtsr 7, r23
    mtsr 8, r24
    mtsr 9, r25
    mtsr 10, r26
    mtsr 11, r27
    mtsr 12, r28
    mtsr 13, r29
    mtsr 14, r30
    mtsr 15, r31
    lmw r12, 0x1f0(r2)
    mtspr hid0, r12
    mtspr hid1, r13
    mtsrr1 r14
    mtspr pvr, r15
    mtibatu 0, r16
    mtibatl 0, r17
    mtibatu 1, r18
    mtibatl 1, r19
    mtibatu 2, r20
    mtibatl 2, r21
    mtibatu 3, r22
    mtibatl 3, r23
    mtdbatu 0, r24
    mtdbatl 0, r25
    mtdbatu 1, r26
    mtdbatl 1, r27
    mtdbatu 2, r28
    mtdbatl 2, r29
    mtdbatu 3, r30
    mtdbatl 3, r31
    lmw r22, 0x25c(r2)
    mtsdr1 r22
    mtdar r23
    mtdsisr r24
    mtsprg 0, r25
    mtsprg 1, r26
    mtsprg 2, r27
    mtsprg 3, r28
    mtspr iabr, r30
    mtear r31
    blr
}

asm void TRKUARTInterruptHandler(void)
{
    nofralloc
    blr
}

DSError kar_diag__803be22c(int* bufferIndexPtr, MessageBuffer** destBufPtr);
void kar_diagnostic__803be19c(int index);
DSError kar_diagnostic__near_803c089c(MessageBuffer* buf);
DSError kar_diagnostic__near_803c0818(MessageBuffer* buf);
DSError kar_diag__803bfb08(MessageBuffer* b, int* bufferId, u32 p1, u32 p2, int p3);

DSError kar_diagnostic__near_803bff40(u8 cmdId)
{
    DSError result;
    int spC;
    MessageBuffer* buffer;
    int sp8;

    result = kar_diag__803be22c(&spC, &buffer);

    if (result == kNoError) {
        if (cmdId == kDSNotifyStopped) {
            kar_diagnostic__near_803c089c(buffer);
        } else {
            kar_diagnostic__near_803c0818(buffer);
        }

        result = kar_diag__803bfb08(buffer, &sp8, 2, 3, 1);

        if (result == kNoError) {
            kar_diagnostic__803be19c(sp8);
        }

        kar_diagnostic__803be19c(spC);
    }

    return result;
}

typedef struct GDEVCommTable {
    /* 0x00 */ void (*initialize_func)(void* ptr, void* callback);
    /* 0x04 */ void (*initinterrupts_func)(void);
    /* 0x08 */ void (*shutdown_func)(void);
    /* 0x0C */ int (*peek_func)(void);
    /* 0x10 */ int (*read_func)(void* data, u32 limit);
    /* 0x14 */ int (*write_func)(const void* data, u32 length);
    /* 0x18 */ void (*open_func)(void);
    /* 0x1C */ void (*close_func)(void);
    /* 0x20 */ void (*pre_continue_func)(void);
    /* 0x24 */ void (*post_stop_func)(void);
} GDEVCommTable;

extern GDEVCommTable gDBCommTable;

int fn_803C2400(void)
{
    return gDBCommTable.peek_func();
}

DSError fn_803C23C4(void* data, u32 limit)
{
    int result = gDBCommTable.read_func(data, limit);
    return !result ? kNoError : kUARTError;
}

DSError kar_diagnostic__803c2388(const void* bytes, u32 length)
{
    int result = gDBCommTable.write_func(bytes, length);
    return !result ? kNoError : kUARTError;
}

#pragma dont_inline on
void fn_803C2430(void)
{
    extern bool TRK_Use_BBA;

    if (!TRK_Use_BBA) {
        if (gDBCommTable.initinterrupts_func != NULL) {
            gDBCommTable.initinterrupts_func();
        }
    }
}
#pragma dont_inline reset

void EnableMetroTRKInterrupts(void)
{
    fn_803C2430();
}

#pragma dont_inline on
void UnreserveEXI2Port(void)
{
    gDBCommTable.pre_continue_func();
}
#pragma dont_inline reset

#pragma dont_inline on
void ReserveEXI2Port(void)
{
    gDBCommTable.post_stop_func();
}
#pragma dont_inline reset

DSError TRKInitializeIntDrivenUART(u32 r3, u32 r4, u32 r5, void* r6)
{
    gDBCommTable.initialize_func(r6, TRKEXICallBack);
    gDBCommTable.open_func();
    return kNoError;
}

void EnableEXI2Interrupts(void);
extern void OSEnableScheduler(void);
void TRKLoadContext(void* ctx, u32 val);

void TRKEXICallBack(short r3, void* ctx)
{
    OSEnableScheduler();
    TRKLoadContext(ctx, 0x500);
}

asm void TRKLoadContext(void* ctx, u32 val)
{
    nofralloc
    lwz r0, 0(r3)
    lwz r1, 4(r3)
    lwz r2, 8(r3)
    lhz r5, 0x1a2(r3)
    rlwinm. r6, r5, 0, 30, 30
    beq defaultGprs
    rlwinm r5, r5, 0, 31, 29
    sth r5, 0x1a2(r3)
    lmw r5, 0x14(r3)
    b afterGprs
defaultGprs:
    lmw r13, 0x34(r3)
afterGprs:
    mr r31, r3
    mr r3, r4
    lwz r4, 0x80(r31)
    mtcrf 255, r4
    lwz r4, 0x84(r31)
    mtlr r4
    lwz r4, 0x88(r31)
    mtctr r4
    lwz r4, 0x8c(r31)
    mtxer r4
    mfmsr r4
    rlwinm r4, r4, 0, 17, 15
    rlwinm r4, r4, 0, 31, 29
    mtmsr r4
    mtsprg 1, r2
    lwz r4, 0xc(r31)
    mtsprg 2, r4
    lwz r4, 0x10(r31)
    mtsprg 3, r4
    lwz r2, 0x198(r31)
    lwz r4, 0x19c(r31)
    lwz r31, 0x7c(r31)
    b TRKInterruptHandler
}

extern u8 _db_stack_addr[];
int InitMetroTRKCommTable(int hwId);
void TRK_main(void);

asm void InitMetroTRK(void)
{
    nofralloc
    subi r1, r1, 4
    stw r3, 0(r1)
    lis r3, gTRKCPUState@h
    ori r3, r3, gTRKCPUState@l
    stmw r0, 0(r3)
    lwz r4, 0(r1)
    addi r1, r1, 4
    stw r1, 4(r3)
    stw r4, 0xc(r3)
    mflr r4
    stw r4, 0x84(r3)
    stw r4, 0x80(r3)
    mfcr r4
    stw r4, 0x88(r3)
    mfmsr r4
    ori r3, r4, 0x8000
    xori r3, r3, 0x8000
    mtmsr r3
    mtsrr1 r4
    bl TRKSaveExtended1Block
    lis r3, gTRKCPUState@h
    ori r3, r3, gTRKCPUState@l
    lmw r0, 0(r3)
    li r0, 0
    mtspr iabr, r0
    mtspr 1013, r0
    lis r1, _db_stack_addr@h
    ori r1, r1, _db_stack_addr@l
    mr r3, r5
    bl InitMetroTRKCommTable
    cmpwi r3, 1
    bne initCommTableSuccess
    lwz r4, 0x84(r3)
    mtlr r4
    lmw r0, 0(r3)
    blr
initCommTableSuccess:
    b TRK_main
}

asm void gap_03_803C1F34_text(void)
{
    nofralloc
    blr
}

extern u8 lbl_8056BDE0[];

DSError TRKInitializeTarget(void)
{
    *(bool*) (gTRKState + 0x98) = true;
    *(u32*) (gTRKCPUState + 0x8c) = kar_diagnostic__near_803c00c8();
    *(u32*) lbl_8056BDE0 = 0xE0000000;
    return kNoError;
}

u32 kar_diagnostic__near_803c2144(u32 addr)
{
    if (addr >= *(u32*) lbl_8056BDE0 &&
        addr < *(u32*) lbl_8056BDE0 + 0x4000 &&
        (*(u32*) (gTRKCPUState + 0x238) & 3))
    {
        return addr;
    }

    return ((addr & 0x3FFFFFFF) | 0x80000000);
}

extern u8 gTRKInterruptVectorTable[];

static u32 kar_diagnostic__near_803c2018_isrOffsets[] = {
    0x100, 0x200, 0x300, 0x400, 0x500, 0x600, 0x700,
    0x800, 0x900, 0xC00, 0xD00, 0xF00, 0x1300, 0x1400, 0x1700
};

DSError kar_diagnostic__near_803c2018(void)
{
    int i;
    u32 data;

    data = *(u32*) kar_diagnostic__near_803c2144(0x44);

    for (i = 0; i <= 14; i++) {
        if ((data & (1 << i)) != 0) {
            u32 offset = kar_diagnostic__near_803c2018_isrOffsets[i];
            u32 destPtr = kar_diagnostic__near_803c2144(offset);

            TRK_memcpy((void*) destPtr,
                      (void*) (gTRKInterruptVectorTable + offset), 0x100);
            kar_diagnostic__803bffd8(destPtr, 0x100);
        }
    }

    return kNoError;
}

DSError TRKSwapAndGo_decl(void);
extern u8 gTRKState[];

DSError TRKTargetContinue(void)
{
    TRKTargetSetStopped(false);
    UnreserveEXI2Port();
    TRKSwapAndGo();
    ReserveEXI2Port();
    return kNoError;
}

typedef struct ExcStatusWords {
    u32 w0, w4, w8, wC;
} ExcStatusWords;

#pragma dont_inline on
DSError kar_diagnostic__803c15d8(u32 firstRegister, u32 lastRegister,
                                 MessageBuffer* b, size_t* length, bool read)
{
    DSError error;
    u32 count;
    u32* data;
    ExcStatusWords tempExceptionStatus;

    if (lastRegister > 0x24) {
        return kInvalidRegister;
    }

    tempExceptionStatus = *(ExcStatusWords*) gTRKExceptionStatus;
    *(u8*) (gTRKExceptionStatus + 0xD) = 0;

    data = (u32*) gTRKCPUState + firstRegister;
    count = (lastRegister - firstRegister) + 1;
    *length = count * sizeof(u32);

    if (read) {
        error = kar_diagnostic__803bdd9c(b, data, count);
    } else {
        error = kar_diagnostic__803bdb2c(b, data, count);
    }

    if (*(u8*) (gTRKExceptionStatus + 0xD)) {
        *length = 0;
        error = kCWDSException;
    }

    *(ExcStatusWords*) gTRKExceptionStatus = tempExceptionStatus;
    return error;
}
#pragma dont_inline reset

typedef struct TRKStepStatus {
    /* 0x00 */ bool active;
    /* 0x04 */ u32 type;
    /* 0x08 */ u32 count;
    /* 0x0C */ u32 rangeStart;
    /* 0x10 */ u32 rangeEnd;
} TRKStepStatus;

extern TRKStepStatus lbl_804F9274;
extern u8 lbl_8048C160[];

u32 kar_diagnostic__near_803c06a4(void)
{
    return *(u32*) (gTRKCPUState + 0x80);
}

DSError kar_diagnostic__near_803c076c(u32 count, bool stepOver)
{
    if (stepOver) {
        return kUnsupportedError;
    }

    lbl_804F9274.count = count;
    lbl_804F9274.type = kDSStepIntoCount;
    lbl_804F9274.active = true;

    MWTRACE(1, (const char*) lbl_8048C160, lbl_804F9274.type);

    *(u32*) (gTRKCPUState + 0x1f8) |= 0x400;

    if (lbl_804F9274.type == kDSStepIntoCount ||
        lbl_804F9274.type == kDSStepOverCount)
    {
        lbl_804F9274.count--;
    }

    TRKTargetSetStopped(false);
    return kNoError;
}

DSError kar_diagnostic__near_803c06b4(u32 rangeStart, u32 rangeEnd, bool stepOver)
{
    if (stepOver) {
        return kUnsupportedError;
    }

    lbl_804F9274.rangeStart = rangeStart;
    lbl_804F9274.rangeEnd = rangeEnd;
    lbl_804F9274.type = kDSStepIntoRange;
    lbl_804F9274.active = true;

    MWTRACE(1, (const char*) lbl_8048C160, lbl_804F9274.type);

    *(u32*) (gTRKCPUState + 0x1f8) |= 0x400;

    if (lbl_804F9274.type == kDSStepIntoCount ||
        lbl_804F9274.type == kDSStepOverCount)
    {
        lbl_804F9274.count--;
    }

    TRKTargetSetStopped(false);
    return kNoError;
}

extern u8 PPCHalt[];
extern u8 EndofProgramInstruction[];
extern void ICInvalidateRange(void* addr, u32 len);
extern void DCFlushRange(void* addr, u32 len);

void InitializeProgramEndTrap(void)
{
    TRK_memcpy(PPCHalt + 4, EndofProgramInstruction, 4);
    ICInvalidateRange(PPCHalt + 4, 4);
    DCFlushRange(PPCHalt + 4, 4);
}

extern u8 lbl_8048C184[];

void TRK_board_display(char* str)
{
    OSReport((const char*) lbl_8048C184, str);
}

static int TRK_mainError;

#pragma dont_inline on
void TRK_main(void)
{
    MWTRACE(1, "TRK_main\n");
    TRK_mainError = TRKInitializeNub();

    if (!TRK_mainError) {
        TRKNubWelcome();
        TRKNubMainLoop();
    }

    TRK_mainError = TRKTerminateNub();
}
#pragma dont_inline reset

void kar_diagnostic__near_803bf730(u32 val)
{
    *(u32*) lbl_8056B858 = val;
}

u32 kar_diagnostic__near_803bf73c(void)
{
    return *(u32*) lbl_8056B858;
}

void fn_803BE624(const char* msg)
{
    u32 saved;
    bool done = false;

    while (!done) {
        char c = *msg++;

        if (c == 0) {
            done = true;
        } else {
            saved = kar_diagnostic__near_803bf73c();
            kar_diagnostic__near_803bf730(0);
            OSReport("%c", c);
            kar_diagnostic__near_803bf730(saved);
        }
    }
}

extern u8 lbl_8048BC78[];

MessageBufferID kar_diag__803be4e4(void)
{
    int bytesAvailable;
    int bufferIndex;
    MessageBuffer* buffer;
    DSError err;
    u32 msgLength;
    u8 header[0x40];
    u8 body[0x800];

    bytesAvailable = fn_803C2400();

    if (bytesAvailable <= 0) {
        return -1;
    }

    err = kar_diag__803be22c(&bufferIndex, &buffer);
    MWTRACE(4, (const char*) lbl_8048BC78 + 0xD0, err);

    kar_diagnostic__803be12c(buffer, 0);
    fn_803C23C4(header, 0x40);
    kar_diagnostic__803bde98(buffer, header, 0x40);

    msgLength = *(u32*) header;

    if ((s32) (msgLength - 0x40) > 0) {
        DSError readErr;

        MWTRACE(1, (const char*) lbl_8048BC78 + 0xF4);
        readErr = fn_803C23C4(body, msgLength - 0x40);

        if (readErr == kNoError) {
            kar_diagnostic__803bde98(buffer, body, msgLength);
        } else {
            MWTRACE(8, (const char*) lbl_8048BC78 + 0x110);
            kar_diagnostic__803be19c(err);
            bufferIndex = -1;
        }
    }

    MWTRACE(1, (const char*) lbl_8048BC78 + 0x16C, bufferIndex);
    return bufferIndex;
}

DSError fn_803C16CC(void* data, u32 start);

#pragma dont_inline on
void TRKPostInterruptEvent(void)
{
    NubEvent event;
    u32 inst;
    int eventType;
    u32 exceptionID;

    if (*(s32*) (gTRKState + 0x9C)) {
        *(u32*) (gTRKState + 0x9C) = 0;
        return;
    }

    exceptionID = *(u32*) (gTRKCPUState + 0x2F8) & 0xFFFF;

    switch (exceptionID) {
    case 0xD00:
    case 0x700:
        fn_803C16CC(&inst, *(u32*) (gTRKCPUState + 0x80));

        if (inst == 0x0FE00000) {
            eventType = kSupportEvent;
        } else {
            eventType = kBreakpointEvent;
        }
        break;
    default:
        eventType = kExceptionEvent;
        break;
    }

    fn_803BD74C(&event, eventType);
    kar_diagnostic__803bd764(&event);
}
#pragma dont_inline reset


DSError TRKTargetInterrupt(NubEvent* event)
{
    DSError result = kNoError;

    switch (event->fType) {
    case kBreakpointEvent:
    case kExceptionEvent:
        TRKTargetSetStopped(true);
        result = kar_diagnostic__near_803bff40(kDSNotifyStopped);
        break;
    default:
        break;
    }

    return result;
}

extern u32 OSDisableInterrupts(void);
extern u32 OSRestoreInterrupts(u32 level);
extern void EXI2_Init(void* ptr, void* callback);
extern void EXI2_EnableInterrupts(void);
extern int EXI2_Poll(void);
extern DSError EXI2_ReadN(void* bytes, u32 length);
extern int EXI2_WriteN(const void* bytes, u32 length);
extern void EXI2_Reserve(void);
extern void EXI2_Unreserve(void);

typedef struct DSMutex2 {
    /* 0x00 */ u32 state;
} DSMutex2;

void kar_diagnostic__near_803c3318(DSMutex2* m)
{
}

void kar_diagnostic__803c32e8(DSMutex2* m)
{
    m->state = OSDisableInterrupts();
}

void kar_diagnostic__803c32c4(DSMutex2* m)
{
    OSRestoreInterrupts(m->state);
}

typedef struct RingBuffer {
    /* 0x00 */ u8* readPtr;
    /* 0x04 */ u8* writePtr;
    /* 0x08 */ u8* base;
    /* 0x0C */ u32 capacity;
    /* 0x10 */ u32 count;
    /* 0x14 */ u32 free;
    /* 0x18 */ DSMutex2 mutex;
} RingBuffer;

#pragma dont_inline on
void kar_diagnostic__near_803c2ed0(RingBuffer* ring, void* buffer, u32 size)
{
    ring->base = buffer;
    ring->capacity = size;
    ring->readPtr = buffer;
    ring->writePtr = buffer;
    ring->count = 0;
    ring->free = size;
    kar_diagnostic__near_803c3318(&ring->mutex);
}
#pragma dont_inline reset

u32 kar_diagnostic__803c2f20(RingBuffer* ring)
{
    return ring->count;
}

#pragma dont_inline on
DSError kar_diagnostic__803c2cc0(RingBuffer* ring, void* dest, u32 len)
{
    u32 contig;

    if (len > ring->count) {
        return kUARTError;
    }

    kar_diagnostic__803c32e8(&ring->mutex);

    contig = ring->capacity - (ring->readPtr - ring->base);

    if (len < contig) {
        memcpy(dest, ring->readPtr, len);
        ring->readPtr += len;
    } else {
        memcpy(dest, ring->readPtr, contig);
        memcpy((u8*) dest + contig, ring->base, len - contig);
        ring->readPtr = ring->base + (len - contig);
    }

    if (ring->readPtr - ring->base == ring->capacity) {
        ring->readPtr = ring->base;
    }

    ring->free += len;
    ring->count -= len;

    kar_diagnostic__803c32c4(&ring->mutex);
    return kNoError;
}
#pragma dont_inline reset

#pragma dont_inline on
DSError kar_diagnostic__803c2dc8(RingBuffer* ring, const void* src, u32 len)
{
    u32 contig;

    if (len > ring->free) {
        return kUARTError;
    }

    kar_diagnostic__803c32e8(&ring->mutex);

    contig = ring->capacity - (ring->writePtr - ring->base);

    if (contig >= len) {
        memcpy(ring->writePtr, src, len);
        ring->writePtr += len;
    } else {
        memcpy(ring->writePtr, src, contig);
        memcpy(ring->base, (const u8*) src + contig, len - contig);
        ring->writePtr = ring->base + (len - contig);
    }

    if (ring->writePtr - ring->base == ring->capacity) {
        ring->writePtr = ring->base;
    }

    ring->free -= len;
    ring->count += len;

    kar_diagnostic__803c32c4(&ring->mutex);
    return kNoError;
}
#pragma dont_inline reset

extern u8 lbl_8056BDF8[];

u8 kar_diag__near_803c27a0(void)
{
    return lbl_8056BDF8[0];
}

void kar_diag__near_803c27b0(u8 value)
{
    lbl_8056BDF8[0] = value;
}

extern RingBuffer lbl_8056C600;
extern u8 lbl_8056BE00[];
extern BOOL lbl_805DDD08;

DSError ddh_cc_initinterrupts(void)
{
    EXI2_EnableInterrupts();
    return kNoError;
}

#pragma dont_inline on
DSError ddh_cc_peek(void)
{
    u8 buf[0x800];
    int bytes = EXI2_Poll();
    DSError err;

    if (bytes <= 0) {
        return kNoError;
    }

    err = EXI2_ReadN(buf, bytes);

    if (err == kNoError) {
        kar_diagnostic__803c2dc8(&lbl_8056C600, buf, bytes);
        return bytes;
    }

    return -0x2719;
}
#pragma dont_inline reset

DSError ddh_cc_post_stop(void)
{
    EXI2_Reserve();
    return kNoError;
}

DSError ddh_cc_pre_continue(void)
{
    EXI2_Unreserve();
    return kNoError;
}

extern u8 lbl_8048C288[];

DSError ddh_cc_write(const void* data, u32 length)
{
    const u8* ptr = (const u8*) data;
    u32 remaining = length;

    if (!lbl_805DDD08) {
        MWTRACE(8, (const char*) lbl_8048C288 + 0x00);
        return -0x2711;
    }

    MWTRACE(8, (const char*) lbl_8048C288 + 0x14, data, length);

    while (remaining > 0) {
        int written;

        MWTRACE(1, (const char*) lbl_8048C288 + 0x40, remaining);
        written = EXI2_WriteN(ptr, remaining);

        if (written == 0) {
            break;
        }

        ptr += written;
        remaining -= written;
    }

    return kNoError;
}

extern u8 lbl_8048C2E4[];
extern u8 lbl_8048C30C[];

#pragma dont_inline on
DSError ddh_cc_read(void* dest, u32 length)
{
    DSError readErr = kNoError;

    if (!lbl_805DDD08) {
        return -0x2711;
    }

    MWTRACE(1, (const char*) lbl_8048C2E4 + 0x00, length, length);

    while (kar_diagnostic__803c2f20(&lbl_8056C600) < length) {
        u8 buf[0x800];
        int bytes;

        readErr = kNoError;
        bytes = EXI2_Poll();

        if (bytes != 0) {
            readErr = EXI2_ReadN(buf, bytes);

            if (readErr == kNoError) {
                kar_diagnostic__803c2dc8(&lbl_8056C600, buf, bytes);
            }
        }
    }

    if (readErr != kNoError) {
        MWTRACE(8, (const char*) lbl_8048C30C + 0x00, readErr);
        return readErr;
    }

    return kar_diagnostic__803c2cc0(&lbl_8056C600, dest, length);
}
#pragma dont_inline reset

DSError ddh_cc_close(void)
{
    return kNoError;
}

DSError ddh_cc_open(void)
{
    if (lbl_805DDD08) {
        return -0x2715;
    }

    lbl_805DDD08 = TRUE;
    return kNoError;
}

DSError ddh_cc_shutdown(void)
{
    return kNoError;
}

extern u8 lbl_8048C33C[];
extern u8 lbl_8048C350[];

DSError ddh_cc_initialize(void* ptr, void* callback)
{
    MWTRACE(1, (const char*) lbl_8048C33C);
    EXI2_Init(ptr, callback);
    MWTRACE(1, (const char*) lbl_8048C350);
    kar_diagnostic__near_803c2ed0(&lbl_8056C600, lbl_8056BE00, 0x800);
    return kNoError;
}

extern RingBuffer lbl_8056CB20;
extern u8 lbl_8056C620[];
extern BOOL lbl_805DDD10;
extern int DBInitInterrupts(void);
extern int DBQueryData(void);
extern int DBRead(void* param1, u32 param2);
extern int DBWrite(const void* data, u32 size);
extern void DBClose(void);
extern void DBOpen(void);
extern void DBInitComm(int* inputFlagPtr, int* mtrCallback);

DSError gdev_cc_initinterrupts(void)
{
    DBInitInterrupts();
    return kNoError;
}

#pragma dont_inline on
DSError gdev_cc_peek(void)
{
    u8 buf[0x500];
    int bytes = DBQueryData();
    DSError err;

    if (bytes <= 0) {
        return kNoError;
    }

    err = DBRead(buf, bytes);

    if (err == kNoError) {
        kar_diagnostic__803c2dc8(&lbl_8056CB20, buf, bytes);
        return bytes;
    }

    return -0x2719;
}
#pragma dont_inline reset

DSError gdev_cc_post_stop(void)
{
    DBOpen();
    return kNoError;
}

DSError gdev_cc_pre_continue(void)
{
    DBClose();
    return kNoError;
}

extern u8 lbl_8048C368[];

DSError gdev_cc_write(const void* data, u32 length)
{
    const u8* ptr = (const u8*) data;
    u32 remaining = length;

    if (!lbl_805DDD10) {
        MWTRACE(8, (const char*) lbl_8048C368 + 0x00);
        return -0x2711;
    }

    MWTRACE(8, (const char*) lbl_8048C368 + 0x14, data, length);

    while (remaining > 0) {
        int written;

        MWTRACE(1, (const char*) lbl_8048C368 + 0x40, remaining);
        written = DBWrite(ptr, remaining);

        if (written == 0) {
            break;
        }

        ptr += written;
        remaining -= written;
    }

    return kNoError;
}

extern u8 lbl_8048C3C4[];
extern u8 lbl_8048C3EC[];

#pragma dont_inline on
DSError gdev_cc_read(void* dest, u32 length)
{
    DSError readErr = kNoError;

    if (!lbl_805DDD10) {
        return -0x2711;
    }

    MWTRACE(1, (const char*) lbl_8048C3C4 + 0x00, length, length);

    while (kar_diagnostic__803c2f20(&lbl_8056CB20) < length) {
        u8 buf[0x800];
        int bytes;

        readErr = kNoError;
        bytes = DBQueryData();

        if (bytes != 0) {
            readErr = DBRead(buf, bytes);

            if (readErr == kNoError) {
                kar_diagnostic__803c2dc8(&lbl_8056CB20, buf, bytes);
            }
        }
    }

    if (readErr != kNoError) {
        MWTRACE(8, (const char*) lbl_8048C3EC + 0x00, readErr);
        return readErr;
    }

    return kar_diagnostic__803c2cc0(&lbl_8056CB20, dest, length);
}
#pragma dont_inline reset

DSError gdev_cc_close(void)
{
    return kNoError;
}

DSError gdev_cc_open(void)
{
    if (lbl_805DDD10) {
        return -0x2715;
    }

    lbl_805DDD10 = TRUE;
    return kNoError;
}

DSError gdev_cc_shutdown(void)
{
    return kNoError;
}

extern u8 lbl_8048C41C[];
extern u8 lbl_8048C430[];

DSError gdev_cc_initialize(void* ptr, void* callback)
{
    MWTRACE(1, (const char*) lbl_8048C41C);
    DBInitComm(ptr, callback);
    MWTRACE(1, (const char*) lbl_8048C430);
    kar_diagnostic__near_803c2ed0(&lbl_8056CB20, lbl_8056C620, 0x500);
    return kNoError;
}

void MWTRACE(int level, const char* fmt, ...)
{
}
