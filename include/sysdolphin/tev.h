#ifndef _tev_h_
#define _tev_h_

#include <global.h>

#include <sysdolphin/objalloc.h>
#include <sysdolphin/mobj.h>
#include <sysdolphin/texp.h>
#include <sysdolphin/tev_state.h>
#include <sysdolphin/tev_stage.h>

typedef struct _HSD_Chan {
    struct _HSD_Chan* next;
    s32 chan;
    u32 flags;
    GXColor amb_color;
    GXColor mat_color;
    u8 enable;
    s32 amb_src;
    s32 mat_src;
    s32 light_mask;
    s32 diff_fn;
    s32 attn_fn;
    void* unk2C;
} HSD_Chan;

void HSD_SetupChannelMode(u32 rendermode);
void HSD_SetupPEMode(u32 rendermode, HSD_PEDesc* pe);
void HSD_SetupRenderModeWithCustomPE(u32 rendermode, HSD_PEDesc* pe);
void HSD_SetupRenderMode(u32 rendermode);
void HSD_SetMaterialColor(GXColor ambient, GXColor diffuse, GXColor specular, f32 alpha);
void HSD_SetMaterialShininess(f32 shininess);
void HSD_StateSetLineWidth(u8 width, s32 tex_offsets);
void HSD_StateSetCullMode(s32 mode);
void HSD_StateSetBlendMode(s32 type, s32 src_factor, s32 dst_factor, s32 op);
void HSD_StateSetZMode(u32 enable, s32 func, u32 update);
void HSD_StateSetPointSize(u8 size, s32 tex_offsets);
void HSD_StateSetAlphaCompare(s32 comp0, u8 ref0, s32 op, s32 comp1, u8 ref1);
void HSD_StateSetColorUpdate(u32 enable);
void HSD_StateSetAlphaUpdate(u32 enable);
void HSD_StateSetDstAlpha(u32 enable, u8 value);
void HSD_StateSetZCompLoc(u32 before_tex);
void HSD_StateSetDither(u32 enable);
void _HSD_StateInvalidatePrimitive(void);
void _HSD_StateInvalidateVtxAttr(void);
void _HSD_StateInvalidateRenderMode(void);

void HSD_SetupChannel(HSD_Chan* ch);
void HSD_DisableChannelLighting(s32 chan);
void HSD_StateSetNumChans(s32 num);
void HSD_SetupChannelAll(HSD_Chan* channel);
s32 HSD_StateAssignTexGen(s32 coord);
void HSD_StateSetNumTexGens(void);
void HSD_StateInitTev(void);
s32 HSD_StateGetNumTevStages(void);
void HSD_StateSetNumTevStages(void);
s32 HSD_Channel2Num(s32 chan);
void HSD_SetTevRegAll(void);
void _HSD_StateInvalidateColorChannel(void);
void _HSD_StateInvalidateTevStage(void);
void fn_803F9890(void);
void fn_803F98B0(void);
void _HSD_StateInvalidateTevRegister(u32 mask);
void _HSD_StateInvalidateTexCoordGen(u32* obj, u32 mask);

#endif
