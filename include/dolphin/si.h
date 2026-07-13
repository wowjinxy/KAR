#ifndef _SI_H_
#define _SI_H_

#include <dolphin/types.h>

typedef void (*__OSInterruptHandler)(u32 interrupt, struct OSContext* context);
typedef void (*SITransferCallback)(s32 chan, u32 status,
                                   struct OSContext* context);
typedef void (*SIGetTypeCallback)(s32 chan, u32 type);

BOOL SIBusy(void);
BOOL SIIsChanBusy(s32 chan);
u32 SIGetStatus(s32 chan);
void SISetCommand(s32 chan, u32 cmd);
void SITransferCommands(void);
u32 SIEnablePolling(u32 mask);
u32 SIDisablePolling(u32 mask);
BOOL SIGetResponse(s32 chan, u32* buf);
BOOL SITransfer(s32 chan, void* outBuf, s32 outLen, void* inBuf, s32 inLen,
                SITransferCallback callback, s64 retryDelay);
s32 SIGetType(s32 chan);
s32 SIGetTypeAsync(s32 chan, SIGetTypeCallback callback);
void SISetSamplingRate(u32 rate);
void SIRefreshSamplingRate(void);
BOOL SIRegisterPollingHandler(__OSInterruptHandler handler);
BOOL SIUnregisterPollingHandler(__OSInterruptHandler handler);

#endif
