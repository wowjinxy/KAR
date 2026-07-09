#include "dolphin/types.h"

extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL level);
extern void OSRegisterVersion(char* version);

extern void ARStartDMA(u32 type, u32 mainmem_addr, u32 aram_addr, u32 length);

typedef void (*ARQDMAHandler)(void);
extern ARQDMAHandler __tmp_aid_callback(ARQDMAHandler callback);

typedef void (*ARQCallback)(u32 pointerToARQRequest);

typedef struct ARQRequest ARQRequest;
struct ARQRequest
{
    /* 0x00 */ ARQRequest* next;
    /* 0x04 */ u32 owner;
    /* 0x08 */ u32 type;
    /* 0x0C */ u32 priority;
    /* 0x10 */ u32 source;
    /* 0x14 */ u32 dest;
    /* 0x18 */ u32 length;
    /* 0x1C */ ARQCallback callback;
};

#define ARQ_DMA_ALIGNMENT     32
#define ARQ_TYPE_MRAM_TO_ARAM 0
#define ARQ_TYPE_ARAM_TO_MRAM 1
#define ARQ_PRIORITY_LOW      0
#define ARQ_PRIORITY_HIGH     1

extern char lbl_804FC9A0[]; /* "<< Dolphin SDK - ARQ ... >>" */

char* lbl_805DC9E8[2] = { lbl_804FC9A0 }; /* __ARQVersion */

BOOL lbl_805DE044;        /* __ARQ_init_flag */
u32 lbl_805DE040;         /* __ARQChunkSize */
ARQCallback lbl_805DE03C; /* __ARQCallbackLo */
ARQCallback lbl_805DE038; /* __ARQCallbackHi */
ARQRequest* lbl_805DE034; /* __ARQRequestPendingLo */
ARQRequest* lbl_805DE030; /* __ARQRequestPendingHi */
ARQRequest* lbl_805DE02C; /* __ARQRequestTailLo */
ARQRequest* lbl_805DE028; /* __ARQRequestQueueLo */
ARQRequest* lbl_805DE024; /* __ARQRequestTailHi */
ARQRequest* lbl_805DE020; /* __ARQRequestQueueHi */

void __ARQInterruptServiceRoutine(void);

static inline void __ARQPopTaskQueueHi(void)
{
    if (lbl_805DE020)
    {
        if (lbl_805DE020->type == 0)
        {
            ARStartDMA(lbl_805DE020->type, lbl_805DE020->source, lbl_805DE020->dest, lbl_805DE020->length);
        }
        else
        {
            ARStartDMA(lbl_805DE020->type, lbl_805DE020->dest, lbl_805DE020->source, lbl_805DE020->length);
        }
        lbl_805DE038 = lbl_805DE020->callback;
        lbl_805DE030 = lbl_805DE020;
        lbl_805DE020 = lbl_805DE020->next;
    }
}

void __ARQServiceQueueLo(void)
{
    if (lbl_805DE034 == 0 && lbl_805DE028)
    {
        lbl_805DE034 = lbl_805DE028;
        lbl_805DE028 = lbl_805DE028->next;
    }

    if (lbl_805DE034)
    {
        if (lbl_805DE034->length <= lbl_805DE040)
        {
            if (lbl_805DE034->type == 0)
            {
                ARStartDMA(lbl_805DE034->type, lbl_805DE034->source, lbl_805DE034->dest, lbl_805DE034->length);
            }
            else
            {
                ARStartDMA(lbl_805DE034->type, lbl_805DE034->dest, lbl_805DE034->source, lbl_805DE034->length);
            }
            lbl_805DE03C = lbl_805DE034->callback;
        }
        else if (lbl_805DE034->type == 0)
        {
            ARStartDMA(lbl_805DE034->type, lbl_805DE034->source, lbl_805DE034->dest, lbl_805DE040);
        }
        else
        {
            ARStartDMA(lbl_805DE034->type, lbl_805DE034->dest, lbl_805DE034->source, lbl_805DE040);
        }

        lbl_805DE034->length -= lbl_805DE040;
        lbl_805DE034->source += lbl_805DE040;
        lbl_805DE034->dest += lbl_805DE040;
    }
}

void __ARQCallbackHack(u32 unused)
{
}

void __ARQInterruptServiceRoutine(void)
{
    if (lbl_805DE038)
    {
        lbl_805DE038((u32)lbl_805DE030);
        lbl_805DE030 = NULL;
        lbl_805DE038 = NULL;
    }
    else if (lbl_805DE03C)
    {
        lbl_805DE03C((u32)lbl_805DE034);
        lbl_805DE034 = NULL;
        lbl_805DE03C = NULL;
    }

    __ARQPopTaskQueueHi();

    if (lbl_805DE030 == 0)
    {
        __ARQServiceQueueLo();
    }
}

void ARQInit(void)
{
    if (lbl_805DE044 != TRUE)
    {
        OSRegisterVersion(lbl_805DC9E8[0]);

        lbl_805DE020 = lbl_805DE028 = NULL;
        lbl_805DE040 = 0x1000;
        __tmp_aid_callback(__ARQInterruptServiceRoutine);
        lbl_805DE030 = NULL;
        lbl_805DE034 = NULL;
        lbl_805DE038 = NULL;
        lbl_805DE03C = NULL;
        lbl_805DE044 = TRUE;
    }
}

void ARQPostRequest(ARQRequest* request, u32 owner, u32 type, u32 priority, u32 source, u32 dest, u32 length, ARQCallback callback)
{
    BOOL level;

    request->next = NULL;
    request->owner = owner;
    request->type = type;
    request->source = source;
    request->dest = dest;
    request->length = length;
    if (callback)
    {
        request->callback = callback;
    }
    else
    {
        request->callback = __ARQCallbackHack;
    }

    level = OSDisableInterrupts();
    switch (priority)
    {
    case ARQ_PRIORITY_LOW:
        if (lbl_805DE028)
        {
            lbl_805DE02C->next = request;
        }
        else
        {
            lbl_805DE028 = request;
        }
        lbl_805DE02C = request;
        break;
    case ARQ_PRIORITY_HIGH:
        if (lbl_805DE020)
        {
            lbl_805DE024->next = request;
        }
        else
        {
            lbl_805DE020 = request;
        }
        lbl_805DE024 = request;
        break;
    }

    if ((lbl_805DE030 == 0) && (lbl_805DE034 == 0))
    {
        __ARQPopTaskQueueHi();
        if (lbl_805DE030 == 0)
        {
            __ARQServiceQueueLo();
        }
    }

    OSRestoreInterrupts(level);
}
