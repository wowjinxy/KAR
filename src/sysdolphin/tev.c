#include <global.h>

#include <dolphin/gx/gx.h>
#include <sysdolphin/tev.h>

#include <sysdolphin/lobj.h>

HSD_ObjAllocData hsd_rd_alloc_data;
HSD_ObjAllocData hsd_reg_alloc_data;
HSD_ObjAllocData hsd_ch_alloc_data;

typedef struct {
    u32 coord;
    u32 map;
    u32 color;
} TevOrderCache;

TevOrderCache tev_order_cache[16];
HSD_TevConf tev_conf_cache[16];

extern u8 TevStateLineWidth;    /* state_line_width */
extern s32 TevStateLineTexOffsets;   /* state_line_tex_offsets */
extern s32 TevStateCullMode;   /* state_cull_mode */
extern s32 TevStateBlendType;   /* state_blend_type */
extern s32 TevStateSrcFactor;   /* state_src_factor */
extern s32 TevStateDstFactor;   /* state_dst_factor */
extern s32 TevStateLogicOp;   /* state_logic_op */
extern u8 TevStateZEnable;    /* state_z_enable */
extern s32 TevStateZFunc;   /* state_z_func */
extern u8 TevStateZUpdate;    /* state_z_update */
extern u8 TevStatePointSize;    /* state_point_size */
extern s32 TevStatePointTexOffsets;   /* state_point_size_param */
extern s32 TevStateAlphaComp0;   /* state_alpha_comp0 */
extern u8 TevStateAlphaRef0;    /* state_alpha_ref0 */
extern s32 TevStateAlphaOp;   /* state_alpha_op */
extern s32 TevStateAlphaComp1;   /* state_alpha_comp1 */
extern u8 TevStateAlphaRef1;    /* state_alpha_ref1 */
extern u8 TevStateColorUpdate;    /* state_color_update */
extern u8 TevStateAlphaUpdate;    /* state_alpha_update */
extern u8 TevStateEnableDstAlpha;    /* state_enable_dst_alpha */
extern u8 TevStateDstAlpha;    /* state_dst_alpha */
extern u8 TevStateBeforeTex;    /* state_before_tex (z-comp-loc) */
extern u8 TevStateDither;    /* state_dither */
extern s32 TevStatePrevNumChans;   /* prev_num_chans */
extern s32 TevStateNumTexGens;   /* num_tex_gens */
extern s32 TevStateCurrentTev;   /* current_tev */
extern s32 TevStatePrevAmbInvalid[2]; /* prev_amb_invalid */
extern s32 TevStatePrevMatInvalid[2]; /* prev_mat_invalid */
extern u32 TevStateRegisterInvalidateMask;   /* tev-register invalidate mask */

typedef struct {
    GXColorS10 a;
    s32 c;
} TevRegEntry;

extern HSD_Chan TevChannelTemplates[6];      /* channel-mode templates */
extern TevRegEntry TevReg[4];   /* TevReg[4] */
extern HSD_Chan TevPrevChannelCache[4];      /* prev_ch cache */
extern struct {
    s32 mask;
    void (*func)(void);
} TevInvalidateFuncs[8];                    /* invalidate_funcs table */
extern HSD_TevConf TevSimpleModeTable[2][5]; /* simple-tevmode -> full HSD_TevConf */
extern u32 TevStage2Num[16];          /* tev stage -> num (TevStage2Num) */
extern u32 TevRegIDs[4];           /* TevReg index -> GX reg id */
extern u32 TevTexCoordID2Num[9];           /* texcoord id -> num (TexCoordID2Num) */
extern HSD_Chan TevInvalidPrevChannel[4];      /* invalid_prev_ch reset template */
extern u32 TevIndex2Stage[16];          /* index -> tev stage (Index2TevStage) */
extern TevOrderCache TevOrderReset;    /* tev-stage order reset template */
extern HSD_TevConf TevConfReset;      /* tev-stage conf reset template */
extern GXColor TevDarkMatterAmbient;          /* dark-matter ambient fallback */

extern struct {
    GXColor ambient;
    GXColor diffuse;
    GXColor specular;
    u8 alpha;
    f32 shininess;
} TevMaterialState;

extern f32 TevFloatZero; /* 0.0F */
extern f32 TevFloatOne; /* 1.0F */
extern f32 TevFloat255; /* 255.0F */

extern HSD_LObj* HSD_LObjGetActiveByIndex(s32 idx);
extern HSD_LObj* HSD_LObjGetActiveByID(u32 id);
extern void HSD_LObjSetup(HSD_LObj* lobj, GXColor* color, f32 shininess);
extern void HSD_MulColor(GXColor* a, GXColor* b, GXColor* out);
extern void memcpy(void* dst, const void* src, u32 size);

extern void GXSetLineWidth(u8 width, u32 tex_offsets);
extern void GXSetPointSize(u8 size, u32 tex_offsets);
extern void GXSetDstAlpha(u32 enable, u8 value);
extern void GXSetDither(u32 enable);
extern void GXSetChanCtrl(u32 chan, u32 enable, u32 amb_src, u32 mat_src, u32 light_mask,
                          u32 diff_fn, u32 attn_fn);
extern void GXSetChanAmbColor(u32 chan, GXColor color);
extern void GXSetChanMatColor(u32 chan, GXColor color);
extern void GXSetNumTexGens(u8 n);
extern void GXSetTevSwapMode(u8 stage, u32 ras_swap, u32 tex_swap);
extern void GXSetTevKColorSel(u8 stage, u32 sel);
extern void GXSetTevKAlphaSel(u8 stage, u32 sel);
extern void GXSetTevColorS10(u32 reg, GXColorS10 color);

void HSD_SetupChannelMode(u32 rendermode)
{
    HSD_LObj* lobj;
    HSD_LObj* diffuseLobj;
    s32 i;
    s32 max;
    s32 numChans;
    s32 texFlags;
    s32 usedSpecular = 0;
    s32 usedDiffuseCombined = 0;
    u8 alpha;

    numChans = rendermode & 3;
    if (numChans == 0) {
        numChans = 1;
    }

    texFlags = rendermode & 0x6000;
    if (texFlags == 0) {
        texFlags = numChans << 13;
    }

    if (rendermode & 8) {
        TevChannelTemplates[0].light_mask = HSD_LObjGetLightMaskSpecular();
        HSD_SetupChannel(&TevChannelTemplates[0]);
        usedSpecular = 1;

        max = HSD_LObjGetNbActive();
        for (i = 0; i < max; i++) {
            lobj = HSD_LObjGetActiveByIndex(i);
            if (lobj != NULL) {
                GXColor color = lobj->color;
                HSD_LObjSetup(lobj, &color, TevMaterialState.shininess);
            }
        }
    }

    if (rendermode & 4) {
        diffuseLobj = HSD_LObjGetActiveByID(0x100);
        if (diffuseLobj != NULL && (diffuseLobj->flags & 4)) {
            HSD_MulColor(&TevMaterialState.ambient, &diffuseLobj->color, &TevChannelTemplates[1].amb_color);
        } else {
            TevChannelTemplates[1].amb_color = TevDarkMatterAmbient;
        }
        TevChannelTemplates[1].amb_src = (numChans >> 1) & 1;
        TevChannelTemplates[1].light_mask = HSD_LObjGetLightMaskDiffuse();
        HSD_SetupChannel(&TevChannelTemplates[1]);

        if (texFlags & 0x4000) {
            TevChannelTemplates[2].chan = 3;
            usedDiffuseCombined = 1;
            HSD_SetupChannel(&TevChannelTemplates[3]);
        } else {
            TevChannelTemplates[2].chan = 2;
        }

        TevChannelTemplates[2].light_mask = HSD_LObjGetLightMaskAlpha();
        if (diffuseLobj != NULL && (diffuseLobj->flags & 0x10)) {
            alpha = diffuseLobj->color.a;
        } else {
            alpha = 0;
        }

        if (TevChannelTemplates[2].light_mask != 0) {
            TevChannelTemplates[2].enable = 1;
            TevChannelTemplates[2].amb_color.a = 0xFF;
            TevChannelTemplates[2].mat_color.a = alpha;
        } else {
            TevChannelTemplates[2].enable = 0;
            TevChannelTemplates[2].amb_color.a = alpha;
        }
        HSD_SetupChannel(&TevChannelTemplates[2]);
    } else {
        TevChannelTemplates[4].amb_src = (numChans >> 1) & 1;
        HSD_SetupChannel(&TevChannelTemplates[4]);

        TevChannelTemplates[5].amb_src = (texFlags >> 14) & 1;
        HSD_SetupChannel(&TevChannelTemplates[5]);
    }

    if (usedSpecular != 0) {
        if (usedDiffuseCombined == 0) {
            HSD_DisableChannelLighting(3);
        }
        HSD_StateSetNumChans(2);
    } else if (usedDiffuseCombined != 0) {
        HSD_DisableChannelLighting(1);
        HSD_StateSetNumChans(2);
    } else {
        HSD_DisableChannelLighting(5);
        HSD_StateSetNumChans(1);
    }
}

void HSD_SetupPEMode(u32 rendermode, HSD_PEDesc* pe)
{
    if (pe != NULL) {
        HSD_StateSetColorUpdate(pe->flags & 1);
        HSD_StateSetAlphaUpdate(pe->flags & 2);
        HSD_StateSetDstAlpha(pe->flags & 4, pe->dst_alpha);
        HSD_StateSetBlendMode(pe->type, pe->src_factor, pe->dst_factor, pe->logic_op);
        HSD_StateSetZMode(pe->flags & 0x10, pe->z_comp, pe->flags & 0x20);
        HSD_StateSetZCompLoc(pe->flags & 8);
        HSD_StateSetAlphaCompare(pe->alpha_comp0, pe->ref0, pe->alpha_op, pe->alpha_comp1,
                                 pe->ref1);
        HSD_StateSetDither(pe->flags & 0x40);
        return;
    }

    HSD_StateSetColorUpdate(1);
    HSD_StateSetAlphaUpdate(0);
    HSD_StateSetDstAlpha(0, 0);
    HSD_StateSetBlendMode((rendermode & 0x40000000) ? 1 : 0, 4, 5, 0xF);
    HSD_StateSetZMode(1, (rendermode & 0x08000000) ? 7 : 3, (rendermode & 0x20000000) ? 0 : 1);
    if (!(rendermode & 0x20000000) && (rendermode & 0x40000000)) {
        HSD_StateSetZCompLoc(0);
        HSD_StateSetAlphaCompare(4, 0, 0, 4, 0);
    } else {
        HSD_StateSetZCompLoc(1);
        HSD_StateSetAlphaCompare(7, 0, 0, 7, 0);
    }
    HSD_StateSetDither(0);
}

void HSD_SetupRenderModeWithCustomPE(u32 rendermode, HSD_PEDesc* pe)
{
    if (HSD_StateGetNumTevStages() == 0) {
        HSD_TevDesc tevdesc;
        tevdesc.flags = 0;
        tevdesc.stage = HSD_StateAssignTev();
        tevdesc.coord = 0xFF;
        tevdesc.map = 0xFF;
        tevdesc.color = 4;
        HSD_SetupTevStage(&tevdesc);
    }

    HSD_SetupPEMode(rendermode, pe);
    HSD_SetTevRegAll();
    HSD_StateSetNumTevStages();
    HSD_StateSetNumTexGens();
    HSD_SetupChannelMode(rendermode);
}

void HSD_SetupRenderMode(u32 rendermode)
{
    HSD_SetupRenderModeWithCustomPE(rendermode, NULL);
}

void HSD_SetMaterialColor(GXColor ambient, GXColor diffuse, GXColor specular, f32 alpha)
{
    f32 clamped = alpha;

    TevMaterialState.ambient = ambient;
    TevMaterialState.diffuse = diffuse;
    TevMaterialState.specular = specular;

    if (alpha <= TevFloatZero) {
        clamped = TevFloatZero;
    } else if (alpha >= TevFloatOne) {
        clamped = TevFloatOne;
    }
    TevMaterialState.alpha = (u8) (TevFloat255 * clamped);
}

void HSD_SetMaterialShininess(f32 shininess)
{
    TevMaterialState.shininess = shininess;
}

void HSD_StateSetLineWidth(u8 width, s32 tex_offsets)
{
    if (TevStateLineWidth != width || TevStateLineTexOffsets != tex_offsets) {
        GXSetLineWidth(width, tex_offsets);
        TevStateLineWidth = width;
        TevStateLineTexOffsets = tex_offsets;
    }
}

void HSD_StateSetCullMode(s32 mode)
{
    if (TevStateCullMode != mode) {
        GXSetCullMode(mode);
        TevStateCullMode = mode;
    }
}

void HSD_StateSetBlendMode(s32 type, s32 src_factor, s32 dst_factor, s32 op)
{
    if (TevStateBlendType != type || TevStateSrcFactor != src_factor || TevStateDstFactor != dst_factor ||
        TevStateLogicOp != op)
    {
        GXSetBlendMode(type, src_factor, dst_factor, op);
        TevStateBlendType = type;
        TevStateSrcFactor = src_factor;
        TevStateDstFactor = dst_factor;
        TevStateLogicOp = op;
    }
}

void HSD_StateSetZMode(u32 enable, s32 func, u32 update)
{
    update = update ? 1 : 0;
    enable = enable ? 1 : 0;

    if (TevStateZEnable != enable || TevStateZFunc != func || TevStateZUpdate != update) {
        GXSetZMode(enable, func, update);
        TevStateZEnable = (u8) enable;
        TevStateZFunc = func;
        TevStateZUpdate = (u8) update;
    }
}

void HSD_StateSetPointSize(u8 size, s32 tex_offsets)
{
    if (TevStatePointSize != size || TevStatePointTexOffsets != tex_offsets) {
        GXSetPointSize(size, tex_offsets);
        TevStatePointSize = size;
        TevStatePointTexOffsets = tex_offsets;
    }
}

void HSD_StateSetAlphaCompare(s32 comp0, u8 ref0, s32 op, s32 comp1, u8 ref1)
{
    if (TevStateAlphaComp0 != comp0 || TevStateAlphaRef0 != ref0 || TevStateAlphaOp != op ||
        TevStateAlphaComp1 != comp1 || TevStateAlphaRef1 != ref1)
    {
        GXSetAlphaCompare(comp0, ref0, op, comp1, ref1);
        TevStateAlphaComp0 = comp0;
        TevStateAlphaRef0 = ref0;
        TevStateAlphaOp = op;
        TevStateAlphaComp1 = comp1;
        TevStateAlphaRef1 = ref1;
    }
}

void HSD_StateSetColorUpdate(u32 enable)
{
    enable = enable ? 1 : 0;
    if (TevStateColorUpdate != enable) {
        GXSetColorUpdate(enable);
        TevStateColorUpdate = (u8) enable;
    }
}

void HSD_StateSetAlphaUpdate(u32 enable)
{
    enable = enable ? 1 : 0;
    if (TevStateAlphaUpdate != enable) {
        GXSetAlphaUpdate(enable);
        TevStateAlphaUpdate = (u8) enable;
    }
}

void HSD_StateSetDstAlpha(u32 enable, u8 value)
{
    enable = enable ? 1 : 0;
    if (TevStateEnableDstAlpha != enable || TevStateDstAlpha != value) {
        GXSetDstAlpha(enable, value);
        TevStateEnableDstAlpha = (u8) enable;
        TevStateDstAlpha = value;
    }
}

void HSD_StateSetZCompLoc(u32 before_tex)
{
    before_tex = before_tex ? 1 : 0;
    if (TevStateBeforeTex != before_tex) {
        GXSetZCompLoc(before_tex);
        TevStateBeforeTex = (u8) before_tex;
    }
}

void HSD_StateSetDither(u32 enable)
{
    enable = enable ? 1 : 0;
    if (TevStateDither != enable) {
        GXSetDither(enable);
        TevStateDither = (u8) enable;
    }
}

void _HSD_StateInvalidatePrimitive(void)
{
    TevStatePointSize = 0;
    TevStateCullMode = -1;
    TevStateLineWidth = 0xFF;
}

void _HSD_StateInvalidateVtxAttr(void)
{
    HSD_ClearVtxDesc();
}

void _HSD_StateInvalidateRenderMode(void)
{
    TevStateBlendType = -1;
    TevStateSrcFactor = -1;
    TevStateDstFactor = -1;
    TevStateLogicOp = -1;
    TevStateZEnable = 0xFF;
    TevStateZFunc = -1;
    TevStateZUpdate = 0xFF;
    TevStateAlphaComp0 = -1;
    TevStateAlphaRef0 = 0;
    TevStateAlphaOp = -1;
    TevStateAlphaComp1 = -1;
    TevStateAlphaRef1 = 0;
    TevStateColorUpdate = 0xFF;
    TevStateAlphaUpdate = 0xFF;
    TevStateEnableDstAlpha = 0xFF;
    TevStateDstAlpha = 0;
    TevStateBeforeTex = 0xFF;
    TevStateDither = 0xFF;
}

void HSD_StateInvalidate(s32 mask)
{
    s32 i = 0;
    s32 m;
    while ((m = TevInvalidateFuncs[i].mask) != 0) {
        if (mask & m) {
            TevInvalidateFuncs[i].func();
        }
        i++;
    }
}

void HSD_RenderInitAllocData(void)
{
    HSD_ObjAllocInit(&hsd_rd_alloc_data, 0x1C, 4);
    HSD_ObjAllocInit(&hsd_reg_alloc_data, 0x14, 4);
    HSD_ObjAllocInit(&hsd_ch_alloc_data, 0x30, 4);
}

HSD_ObjAllocData* HSD_RenderGetAllocData(void)
{
    return &hsd_rd_alloc_data;
}

HSD_ObjAllocData* HSD_TevRegGetAllocData(void)
{
    return &hsd_reg_alloc_data;
}

HSD_ObjAllocData* HSD_ChanGetAllocData(void)
{
    return &hsd_ch_alloc_data;
}

static inline bool CompareRGB(GXColor* c0, GXColor* c1)
{
    u32* d0 = (u32*) c0;
    u32* d1 = (u32*) c1;
    return ((*d0 ^ *d1) & 0xFFFFFF00) != 0;
}

static inline bool CompareRGBA(GXColor* c0, GXColor* c1)
{
    u32* d0 = (u32*) c0;
    u32* d1 = (u32*) c1;
    return *d0 != *d1;
}

static inline void CopyRGB(GXColor* dst, GXColor* src)
{
    u32* d = (u32*) dst;
    u32* s = (u32*) src;
    *d = (*d & 0xff) | (*s & 0xffffff00);
}

void HSD_SetupChannel(HSD_Chan* ch)
{
    s32 chan;
    s32 idx;
    s32 no;

    if (ch == NULL || ch->chan == 0xFF) {
        return;
    }

    chan = ch->chan;
    idx = chan & 3;
    no = chan & 1;

    if (ch->enable != 0 && ch->amb_src == 0) {
        if (TevStatePrevAmbInvalid[no] != 0) {
            TevStatePrevAmbInvalid[no] = 0;
            GXSetChanAmbColor(no + 4, ch->amb_color);
            TevPrevChannelCache[no].amb_color = ch->amb_color;
        } else if (chan == 4 || chan == 5) {
            if (CompareRGBA(&ch->amb_color, &TevPrevChannelCache[no].amb_color)) {
                TevPrevChannelCache[no].amb_color = ch->amb_color;
                goto set_amb;
            }
        } else if (chan == 0 || chan == 1) {
            if (CompareRGB(&ch->amb_color, &TevPrevChannelCache[no].amb_color)) {
                CopyRGB(&TevPrevChannelCache[no].amb_color, &ch->amb_color);
                goto set_amb;
            }
        } else if (ch->amb_color.a != TevPrevChannelCache[no].amb_color.a) {
            TevPrevChannelCache[no].amb_color.a = ch->amb_color.a;
        set_amb:
            GXSetChanAmbColor(chan, ch->amb_color);
        }
    }

    if (ch->mat_src == 0) {
        if (TevStatePrevMatInvalid[no] != 0) {
            TevStatePrevMatInvalid[no] = 0;
            GXSetChanMatColor(no + 4, ch->mat_color);
            TevPrevChannelCache[no].mat_color = ch->mat_color;
        } else if (chan == 4 || chan == 5) {
            if (CompareRGBA(&ch->mat_color, &TevPrevChannelCache[no].mat_color)) {
                TevPrevChannelCache[no].mat_color = ch->mat_color;
                goto set_mat;
            }
        } else if (chan == 0 || chan == 1) {
            if (CompareRGB(&ch->mat_color, &TevPrevChannelCache[no].mat_color)) {
                CopyRGB(&TevPrevChannelCache[no].mat_color, &ch->mat_color);
                goto set_mat;
            }
        } else if (ch->mat_color.a != TevPrevChannelCache[no].mat_color.a) {
            TevPrevChannelCache[no].mat_color.a = ch->mat_color.a;
        set_mat:
            GXSetChanMatColor(chan, ch->mat_color);
        }
    }

    if (ch->enable != TevPrevChannelCache[idx].enable || ch->amb_src != TevPrevChannelCache[idx].amb_src ||
        ch->mat_src != TevPrevChannelCache[idx].mat_src ||
        ch->light_mask != TevPrevChannelCache[idx].light_mask ||
        ch->diff_fn != TevPrevChannelCache[idx].diff_fn || ch->attn_fn != TevPrevChannelCache[idx].attn_fn)
    {
        GXSetChanCtrl(chan, ch->enable, ch->amb_src, ch->mat_src, ch->light_mask, ch->diff_fn,
                      ch->attn_fn);
        TevPrevChannelCache[idx].enable = ch->enable;
        TevPrevChannelCache[idx].amb_src = ch->amb_src;
        TevPrevChannelCache[idx].mat_src = ch->mat_src;
        TevPrevChannelCache[idx].light_mask = ch->light_mask;
        TevPrevChannelCache[idx].diff_fn = ch->diff_fn;
        TevPrevChannelCache[idx].attn_fn = ch->attn_fn;

        if (chan == 4 || chan == 5) {
            TevPrevChannelCache[idx + 2].enable = ch->enable;
            TevPrevChannelCache[idx + 2].amb_src = ch->amb_src;
            TevPrevChannelCache[idx + 2].mat_src = ch->mat_src;
            TevPrevChannelCache[idx + 2].light_mask = ch->light_mask;
            TevPrevChannelCache[idx + 2].diff_fn = ch->diff_fn;
            TevPrevChannelCache[idx + 2].attn_fn = ch->attn_fn;
        }
    }
}

void HSD_DisableChannelLighting(s32 chan)
{
    s32 idx = chan & 3;

    if (chan >= 4 && chan < 6) {
        HSD_Chan* c0 = &TevPrevChannelCache[idx];
        HSD_Chan* c2 = c0 + 2;

        if (c0->enable != 0 || c2->enable != 0) {
            c2->enable = 0;
            c0->enable = 0;
            c2->light_mask = 0;
            c0->light_mask = 0;
            c2->amb_src = c0->amb_src;
            c2->mat_src = c0->mat_src;
            c2->diff_fn = c0->diff_fn;
            c2->attn_fn = c0->attn_fn;
            GXSetChanCtrl(chan, 0, c0->amb_src, c0->mat_src, 0, c0->diff_fn, c0->attn_fn);
        }
    } else {
        HSD_Chan* c = &TevPrevChannelCache[idx];
        if (c->enable != 0) {
            c->enable = 0;
            c->light_mask = 0;
            GXSetChanCtrl(chan, 0, c->amb_src, c->mat_src, 0, c->diff_fn, c->attn_fn);
        }
    }
}

void HSD_StateSetNumChans(s32 num)
{
    if (TevStatePrevNumChans != num) {
        GXSetNumChans(num);
        TevStatePrevNumChans = num;
    }
}

void HSD_SetupChannelAll(HSD_Chan* channel)
{
    s32 num = 0;
    while (channel != NULL) {
        s32 temp = HSD_Channel2Num(channel->chan);
        if (temp > num) {
            num = temp;
        }
        HSD_SetupChannel(channel);
        channel = channel->next;
    }
    HSD_StateSetNumChans((u8) num);
}

s32 HSD_StateAssignTexGen(s32 coord)
{
    s32 num;

    if (coord == 0xFF) {
        num = 0;
    } else {
        num = TevTexCoordID2Num[coord];
    }

    if (num > TevStateNumTexGens) {
        TevStateNumTexGens = num;
    }
    return num;
}

void HSD_StateSetNumTexGens(void)
{
    GXSetNumTexGens(TevStateNumTexGens);
    TevStateNumTexGens = 0;
}

void HSD_StateInitTev(void)
{
    TevStateCurrentTev = 0;
}

s32 HSD_StateGetNumTevStages(void)
{
    return TevStateCurrentTev;
}

u32 HSD_StateAssignTev(void)
{
    s32 cur = TevStateCurrentTev;
    TevStateCurrentTev = cur + 1;
    return TevIndex2Stage[cur];
}

void HSD_StateSetNumTevStages(void)
{
    GXSetNumTevStages(TevStateCurrentTev);
    TevStateCurrentTev = 0;
}

void HSD_SetupTevStage(HSD_TevDesc* desc)
{
    u32 stage = desc->stage;
    TevOrderCache* order = &tev_order_cache[stage];
    HSD_TevConf* cache = &tev_conf_cache[stage];
    HSD_TevConf* fresh;

    if (order->coord != desc->coord || order->map != desc->map || order->color != desc->color) {
        order->coord = desc->coord;
        order->map = desc->map;
        order->color = desc->color;
        GXSetTevOrder(stage, desc->coord, desc->map, desc->color);
    }

    if (desc->flags == 0) {
        fresh = &TevSimpleModeTable[stage != 0][desc->u.tevop.tevmode];
    } else {
        fresh = &desc->u.tevconf;
    }

    if (cache->clr_op != fresh->clr_op || cache->ras_swap != fresh->ras_swap ||
        cache->tex_swap != fresh->tex_swap)
    {
        cache->clr_op = fresh->clr_op;
        cache->ras_swap = fresh->ras_swap;
        cache->tex_swap = fresh->tex_swap;
        GXSetTevSwapMode(stage, fresh->ras_swap, fresh->tex_swap);
    }

    if (cache->kcsel != fresh->kcsel) {
        cache->kcsel = fresh->kcsel;
        GXSetTevKColorSel(stage, fresh->kcsel);
    }

    if (cache->kasel != fresh->kasel) {
        cache->kasel = fresh->kasel;
        GXSetTevKAlphaSel(stage, fresh->kasel);
    }

    if (cache->clr_op != fresh->clr_op || cache->clr_out_reg != fresh->clr_out_reg ||
        cache->clr_scale != fresh->clr_scale || cache->clr_clamp != fresh->clr_clamp ||
        cache->clr_bias != fresh->clr_bias)
    {
        cache->clr_op = fresh->clr_op;
        cache->clr_bias = fresh->clr_bias;
        cache->clr_scale = fresh->clr_scale;
        cache->clr_clamp = fresh->clr_clamp;
        cache->clr_out_reg = fresh->clr_out_reg;
        GXSetTevColorOp(stage, fresh->clr_op, fresh->clr_bias, fresh->clr_scale,
                        fresh->clr_clamp, fresh->clr_out_reg);
    }

    if (cache->clr_a != fresh->clr_a || cache->clr_b != fresh->clr_b ||
        cache->clr_c != fresh->clr_c || cache->clr_d != fresh->clr_d)
    {
        cache->clr_a = fresh->clr_a;
        cache->clr_b = fresh->clr_b;
        cache->clr_c = fresh->clr_c;
        cache->clr_d = fresh->clr_d;
        GXSetTevColorIn(stage, fresh->clr_a, fresh->clr_b, fresh->clr_c, fresh->clr_d);
    }

    if (cache->alpha_op != fresh->alpha_op || cache->alpha_bias != fresh->alpha_bias ||
        cache->alpha_scale != fresh->alpha_scale || cache->alpha_clamp != fresh->alpha_clamp ||
        cache->alpha_out_reg != fresh->alpha_out_reg)
    {
        cache->alpha_op = fresh->alpha_op;
        cache->alpha_bias = fresh->alpha_bias;
        cache->alpha_scale = fresh->alpha_scale;
        cache->alpha_clamp = fresh->alpha_clamp;
        cache->alpha_out_reg = fresh->alpha_out_reg;
        GXSetTevAlphaOp(stage, fresh->alpha_op, fresh->alpha_bias, fresh->alpha_scale,
                        fresh->alpha_clamp, fresh->alpha_out_reg);
    }

    if (cache->alpha_a != fresh->alpha_a || cache->alpha_b != fresh->alpha_b ||
        cache->alpha_c != fresh->alpha_c || cache->alpha_d != fresh->alpha_d)
    {
        cache->alpha_a = fresh->alpha_a;
        cache->alpha_b = fresh->alpha_b;
        cache->alpha_c = fresh->alpha_c;
        cache->alpha_d = fresh->alpha_d;
        GXSetTevAlphaIn(stage, fresh->alpha_a, fresh->alpha_b, fresh->alpha_c, fresh->alpha_d);
    }
}

void HSD_SetupTevStageAll(HSD_TevDesc* desc)
{
    s32 num = 0;
    HSD_TevDesc* td;

    for (td = desc; td != NULL; td = td->next) {
        u32 tmp = TevStage2Num[td->stage];
        if ((s32) tmp > num) {
            num = tmp;
        }
        HSD_SetupTevStage(td);
    }

    TevStateCurrentTev = num;
    GXSetNumTevStages(num);
    TevStateCurrentTev = 0;
}

s32 HSD_Channel2Num(s32 chan)
{
    switch (chan) {
    case 0:
        return 1;
    case 1:
        return 2;
    case 2:
        return 1;
    case 3:
        return 2;
    case 4:
        return 1;
    case 5:
        return 2;
    case 0xFF:
        return 0;
    default:
        assert_line(0x481, 0);
        return 0;
    }
}

void HSD_SetTevRegAll(void)
{
    s32 i;
    for (i = 0; i < 4; i++) {
        if (TevReg[i].c != 0) {
            GXSetTevColorS10(TevRegIDs[i], TevReg[i].a);
            TevReg[i].c = 0;
        }
    }
}

void _HSD_StateInvalidateColorChannel(void)
{
    memcpy(&TevPrevChannelCache, &TevInvalidPrevChannel, sizeof(TevPrevChannelCache));
    TevStatePrevAmbInvalid[0] = 1;
    TevStatePrevAmbInvalid[1] = 1;
    TevStatePrevMatInvalid[0] = 1;
    TevStatePrevMatInvalid[1] = 1;
    TevStatePrevNumChans = -1;
}

void _HSD_StateInvalidateTevStage(void)
{
    s32 i;
    TevStateCurrentTev = 0;
    for (i = 0; i < 16; i++) {
        tev_order_cache[i].coord = TevOrderReset.coord;
        tev_order_cache[i].map = TevOrderReset.map;
        tev_order_cache[i].color = TevOrderReset.color;
        tev_conf_cache[i] = TevConfReset;
    }
}

void _HSD_StateInvalidateTevRegisterAll(void)
{
    TevReg[0].c = 0;
    TevReg[1].c = 0;
    TevReg[2].c = 0;
    TevReg[3].c = 0;
}

void _HSD_StateInvalidateTexCoordGenAll(void)
{
    TevStateNumTexGens = 0;
}

void _HSD_StateInvalidateTevRegister(u32 mask)
{
    TevStateRegisterInvalidateMask = mask;
}

void _HSD_StateInvalidateTexCoordGen(u32* obj, u32 mask)
{
    if (obj == NULL) {
        return;
    }
    obj[1] |= mask;
}
