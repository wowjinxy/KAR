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
} MessageBuffer; // size = 0x890

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
} NubEvent; // size = 0x0C

typedef struct EventQueue {
    /* 0x00 */ u8 pad[4];
    /* 0x04 */ int fCount;
    /* 0x08 */ int fFirst;
    /* 0x0C */ NubEvent fEventList[2];
    /* 0x24 */ NubEventID fEventID;
} EventQueue; // size = 0x28

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
void kar_diag__near_803be434(MessageBufferID bufID);
MessageBufferID TRKTestForPacket(void);
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

typedef struct msgbuf_t {
    /* 0x00 */ u32 msgLength;
    /* 0x04 */ u8 commandId;
} msgbuf_t;

typedef struct FramingState {
    /* 0x00 */ MessageBufferID fBufferID;
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

void kar_diag__near_803be434(MessageBufferID bufID)
{
    NubEvent event;

    fn_803BD74C(&event, kBreakpointEvent);
    event.fMessageBufferID = bufID;
    lbl_8056B840.fBufferID = -1;
    kar_diagnostic__803bd764(&event);
}

void TRKGetInput(void)
{
    MessageBufferID bufID;

    bufID = TRKTestForPacket();

    if (bufID != -1) {
        TRKGetBuffer(bufID);
        kar_diag__near_803be434(bufID);
    }
}

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
