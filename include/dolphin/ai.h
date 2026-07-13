#ifndef _AI_H_
#define _AI_H_

#include <dolphin/types.h>

typedef void (*AISCallback)(u32 count);
typedef void (*AIDCallback)(void);

AIDCallback AIRegisterDMACallback(AIDCallback callback);
void AIInitDMA(u32 startAddr, u32 length);
void AIStartDMA(void);
void AIStopDMA(void);
AIDCallback __tmp_aid_callback(AIDCallback callback);

#endif
