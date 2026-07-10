#ifndef _video_h_
#define _video_h_

#include <global.h>

#include <dolphin/gx/gxtypes.h>
#include <sysdolphin/forward.h>

#define HSD_VI_XFB_MAX 3

#define VI_DISPLAY_PIX_SZ 2

typedef struct _HSD_VIStatus {
    GXRenderModeObj rmode;
    u32 black;
    u8 vf;
    u32 gamma;
    GXColor clear_clr;
    u32 clear_z;
    u8 update_clr;
    u8 update_alpha;
    u8 update_z;
} HSD_VIStatus;

typedef enum _HSD_RenderPass {
    HSD_RP_SCREEN,
    HSD_RP_TOPHALF,
    HSD_RP_BOTTOMHALF,
    HSD_RP_OFFSCREEN,
    HSD_RP_NUM
} HSD_RenderPass;

typedef void (*HSD_VIRetraceCallback)(u32);
typedef void (*HSD_VIGXDrawDoneCallback)(int);

HSD_VIRetraceCallback HSD_VISetUserPreRetraceCallback(HSD_VIRetraceCallback cb);
HSD_VIRetraceCallback HSD_VISetUserPostRetraceCallback(HSD_VIRetraceCallback cb);
HSD_VIGXDrawDoneCallback HSD_VISetUserGXDrawDoneCallback(HSD_VIGXDrawDoneCallback cb);
s32 HSD_VIGetDrawDoneWaitingFlag(void);
void HSD_VICopyEFB2XFBPtr(HSD_VIStatus* vi, void* buffer, HSD_RenderPass rpass);
void HSD_VICopyXFBAsync(HSD_RenderPass rpass);
void HSD_VIDrawDoneXFB(s32 idx);
void HSD_VIWaitXFBFlush(void);
void HSD_VIWaitXFBFlushNoYield(void);
s32 HSD_VIGetXFBLastDrawDone(void);
void HSD_VISetConfigure(GXRenderModeObj* rmode);
void HSD_VISetBlack(bool black);
void HSD_VIInit(HSD_VIStatus* vi, void* xfb0, void* xfb1, void* xfb2);

#endif
