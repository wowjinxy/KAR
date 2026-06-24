#include <global.h>

#include <dolphin/gx/gxtypes.h>
#include <sysdolphin/initialize.h>
#include <sysdolphin/video.h>

extern void DVDInit(void);
extern void* GXInit(void* fifo, u32 size);
extern void VIWaitForRetrace(void);
extern void HSD_AllocateXFB(s32 count, GXRenderModeObj* rmode);
extern void HSD_GXInit(void);
extern void HSD_OSInit(void);
extern void HSD_IDSetup(void);
extern void HSD_ObjInit(void);
extern void HSD_VIInit(HSD_VIStatus* status, void* xfb0, void* xfb1, void* xfb2);

extern void* lbl_80589A48[3];
extern HSD_MemReport lbl_80589A54;
extern void* lbl_805DE2A8;
extern s32 lbl_805DE2B0;
extern GXRenderModeObj* lbl_805DCBB4;
extern s32 lbl_805DCBBC;
extern s32 lbl_805DCBC0;
extern const u32 lbl_805E6378[2];

char lbl_80503C60[] = "initialize.c";

void HSD_Init(void)
{
    HSD_VIStatus vi_status;
    void* fifo;

    DVDInit();
    HSD_AllocateXFB(lbl_805DCBC0, lbl_805DCBB4);
    fifo = HSD_AllocateFIFO(lbl_805DCBBC);
    lbl_805DE2A8 = GXInit(fifo, lbl_805DCBBC);
    lbl_80589A54.gxfifo = lbl_805DCBBC;
    HSD_OSInit();

    vi_status.rmode = *lbl_805DCBB4;
    vi_status.black = GX_TRUE;
    vi_status.vf = GX_TRUE;
    vi_status.gamma = GX_GM_1_0;
    vi_status.clear_clr = *(GXColor*) lbl_805E6378;
    vi_status.clear_z = GX_MAX_Z24;
    vi_status.update_clr = GX_ENABLE;
    vi_status.update_alpha = GX_ENABLE;
    vi_status.update_z = GX_ENABLE;
    HSD_VIInit(&vi_status, lbl_80589A48[0], lbl_80589A48[1], lbl_80589A48[2]);

    HSD_GXInit();
    HSD_DVDInit();
    HSD_IDSetup();
    VIWaitForRetrace();
    HSD_ObjInit();
    lbl_805DE2B0 = TRUE;
}

void HSD_DVDInit(void)
{
}
