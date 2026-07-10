#include <global.h>
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

extern u8 lbl_805DE1C4;    /* state_line_width */
extern s32 lbl_805DE1C0;   /* state_line_tex_offsets */
extern s32 lbl_805DE1B4;   /* state_cull_mode */
extern s32 lbl_805DE1B0;   /* state_blend_type */
extern s32 lbl_805DE1AC;   /* state_src_factor */
extern s32 lbl_805DE1A8;   /* state_dst_factor */
extern s32 lbl_805DE1A4;   /* state_logic_op */
extern u8 lbl_805DE1A0;    /* state_z_enable */
extern s32 lbl_805DE19C;   /* state_z_func */
extern u8 lbl_805DE198;    /* state_z_update */
extern u8 lbl_805DE1BC;    /* state_point_size */
extern s32 lbl_805DE1B8;   /* state_point_size_param */
extern s32 lbl_805DE194;   /* state_alpha_comp0 */
extern u8 lbl_805DE190;    /* state_alpha_ref0 */
extern s32 lbl_805DE18C;   /* state_alpha_op */
extern s32 lbl_805DE188;   /* state_alpha_comp1 */
extern u8 lbl_805DE186;    /* state_alpha_ref1 */
extern u8 lbl_805DE185;    /* state_color_update */
extern u8 lbl_805DE184;    /* state_alpha_update */
extern u8 lbl_805DE183;    /* state_enable_dst_alpha */
extern u8 lbl_805DE182;    /* state_dst_alpha */
extern u8 lbl_805DE181;    /* state_before_tex (z-comp-loc) */
extern u8 lbl_805DE180;    /* state_dither */
extern s32 lbl_805DE1CC;   /* prev_num_chans */
extern s32 lbl_805DE1C8;   /* num_tex_gens */
extern s32 lbl_805DE1E0;   /* current_tev */
extern s32 lbl_805DE1D8[2]; /* prev_amb_invalid */
extern s32 lbl_805DE1D0[2]; /* prev_mat_invalid */
extern u32 lbl_805DE1EC;   /* tev-register invalidate mask */

typedef struct {
    GXColorS10 a;
    s32 c;
} TevRegEntry;

extern HSD_Chan lbl_80502300[6];      /* channel-mode templates */
extern TevRegEntry lbl_80502460[4];   /* TevReg[4] */
extern HSD_Chan lbl_80502490[4];      /* prev_ch cache */
extern struct {
    s32 mask;
    void (*func)(void);
} lbl_80502420[8];                    /* invalidate_funcs table */
extern HSD_TevConf lbl_80502550[2][5]; /* simple-tevmode -> full HSD_TevConf */
extern u32 lbl_80502928[16];          /* tev stage -> num (TevStage2Num) */
extern u32 lbl_80502968[4];           /* TevReg index -> GX reg id */
extern u32 lbl_80502978[9];           /* texcoord id -> num (TexCoordID2Num) */
extern HSD_Chan lbl_80502998[4];      /* invalid_prev_ch reset template */
extern u32 lbl_805028E8[16];          /* index -> tev stage (Index2TevStage) */
extern TevOrderCache lbl_80502A58;    /* tev-stage order reset template */
extern HSD_TevConf lbl_80502A64;      /* tev-stage conf reset template */
extern GXColor lbl_805DCA88;          /* dark-matter ambient fallback */

extern struct {
    GXColor ambient;
    GXColor diffuse;
    GXColor specular;
    u8 alpha;
    f32 shininess;
} lbl_80589260;

extern f32 lbl_805E59F8; /* 0.0F */
extern f32 lbl_805E59FC; /* 1.0F */
extern f32 lbl_805E5A00; /* 255.0F */

extern HSD_LObj* HSD_LObjGetActiveByIndex(s32 idx);
extern HSD_LObj* HSD_LObjGetActiveByID(u32 id);
extern void HSD_LObjSetup(HSD_LObj* lobj, GXColor* color, f32 shininess);
extern void HSD_MulColor(GXColor* a, GXColor* b, GXColor* out);
extern void memcpy(void* dst, const void* src, u32 size);

extern void GXSetLineWidth(u8 width, u32 tex_offsets);
extern void GXSetCullMode(u32 mode);
extern void GXSetBlendMode(u32 type, u32 src_factor, u32 dst_factor, u32 op);
extern void GXSetZMode(u32 enable, u32 func, u32 update);
extern void GXSetPointSize(u8 size, u32 tex_offsets);
extern void GXSetAlphaCompare(u32 comp0, u8 ref0, u32 op, u32 comp1, u8 ref1);
extern void GXSetColorUpdate(u32 enable);
extern void GXSetAlphaUpdate(u32 enable);
extern void GXSetDstAlpha(u32 enable, u8 value);
extern void GXSetZCompLoc(u32 before_tex);
extern void GXSetDither(u32 enable);
extern void GXSetNumChans(u8 n);
extern void GXSetChanCtrl(u32 chan, u32 enable, u32 amb_src, u32 mat_src, u32 light_mask,
                          u32 diff_fn, u32 attn_fn);
extern void GXSetChanAmbColor(u32 chan, GXColor color);
extern void GXSetChanMatColor(u32 chan, GXColor color);
extern void GXSetNumTexGens(u8 n);
extern void GXSetNumTevStages(u8 n);
extern void GXSetTevOrder(u8 stage, u32 coord, u32 map, u32 color);
extern void GXSetTevOp(u8 stage, u32 mode);
extern void GXSetTevSwapMode(u8 stage, u32 ras_swap, u32 tex_swap);
extern void GXSetTevKColorSel(u8 stage, u32 sel);
extern void GXSetTevKAlphaSel(u8 stage, u32 sel);
extern void GXSetTevColorOp(u8 stage, u32 op, u32 bias, u32 scale, u32 clamp, u32 out_reg);
extern void GXSetTevColorIn(u8 stage, u32 a, u32 b, u32 c, u32 d);
extern void GXSetTevAlphaOp(u8 stage, u32 op, u32 bias, u32 scale, u32 clamp, u32 out_reg);
extern void GXSetTevAlphaIn(u8 stage, u32 a, u32 b, u32 c, u32 d);
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
        lbl_80502300[0].light_mask = HSD_LObjGetLightMaskSpecular();
        HSD_SetupChannel(&lbl_80502300[0]);
        usedSpecular = 1;

        max = HSD_LObjGetNbActive();
        for (i = 0; i < max; i++) {
            lobj = HSD_LObjGetActiveByIndex(i);
            if (lobj != NULL) {
                GXColor color = lobj->color;
                HSD_LObjSetup(lobj, &color, lbl_80589260.shininess);
            }
        }
    }

    if (rendermode & 4) {
        diffuseLobj = HSD_LObjGetActiveByID(0x100);
        if (diffuseLobj != NULL && (diffuseLobj->flags & 4)) {
            HSD_MulColor(&lbl_80589260.ambient, &diffuseLobj->color, &lbl_80502300[1].amb_color);
        } else {
            lbl_80502300[1].amb_color = lbl_805DCA88;
        }
        lbl_80502300[1].amb_src = (numChans >> 1) & 1;
        lbl_80502300[1].light_mask = HSD_LObjGetLightMaskDiffuse();
        HSD_SetupChannel(&lbl_80502300[1]);

        if (texFlags & 0x4000) {
            lbl_80502300[2].chan = 3;
            usedDiffuseCombined = 1;
            HSD_SetupChannel(&lbl_80502300[3]);
        } else {
            lbl_80502300[2].chan = 2;
        }

        lbl_80502300[2].light_mask = HSD_LObjGetLightMaskAlpha();
        if (diffuseLobj != NULL && (diffuseLobj->flags & 0x10)) {
            alpha = diffuseLobj->color.a;
        } else {
            alpha = 0;
        }

        if (lbl_80502300[2].light_mask != 0) {
            lbl_80502300[2].enable = 1;
            lbl_80502300[2].amb_color.a = 0xFF;
            lbl_80502300[2].mat_color.a = alpha;
        } else {
            lbl_80502300[2].enable = 0;
            lbl_80502300[2].amb_color.a = alpha;
        }
        HSD_SetupChannel(&lbl_80502300[2]);
    } else {
        lbl_80502300[4].amb_src = (numChans >> 1) & 1;
        HSD_SetupChannel(&lbl_80502300[4]);

        lbl_80502300[5].amb_src = (texFlags >> 14) & 1;
        HSD_SetupChannel(&lbl_80502300[5]);
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

    lbl_80589260.ambient = ambient;
    lbl_80589260.diffuse = diffuse;
    lbl_80589260.specular = specular;

    if (alpha <= lbl_805E59F8) {
        clamped = lbl_805E59F8;
    } else if (alpha >= lbl_805E59FC) {
        clamped = lbl_805E59FC;
    }
    lbl_80589260.alpha = (u8) (lbl_805E5A00 * clamped);
}

void HSD_SetMaterialShininess(f32 shininess)
{
    lbl_80589260.shininess = shininess;
}

void HSD_StateSetLineWidth(u8 width, s32 tex_offsets)
{
    if (lbl_805DE1C4 != width || lbl_805DE1C0 != tex_offsets) {
        GXSetLineWidth(width, tex_offsets);
        lbl_805DE1C4 = width;
        lbl_805DE1C0 = tex_offsets;
    }
}

void HSD_StateSetCullMode(s32 mode)
{
    if (lbl_805DE1B4 != mode) {
        GXSetCullMode(mode);
        lbl_805DE1B4 = mode;
    }
}

void HSD_StateSetBlendMode(s32 type, s32 src_factor, s32 dst_factor, s32 op)
{
    if (lbl_805DE1B0 != type || lbl_805DE1AC != src_factor || lbl_805DE1A8 != dst_factor ||
        lbl_805DE1A4 != op)
    {
        GXSetBlendMode(type, src_factor, dst_factor, op);
        lbl_805DE1B0 = type;
        lbl_805DE1AC = src_factor;
        lbl_805DE1A8 = dst_factor;
        lbl_805DE1A4 = op;
    }
}

void HSD_StateSetZMode(u32 enable, s32 func, u32 update)
{
    update = update ? 1 : 0;
    enable = enable ? 1 : 0;

    if (lbl_805DE1A0 != enable || lbl_805DE19C != func || lbl_805DE198 != update) {
        GXSetZMode(enable, func, update);
        lbl_805DE1A0 = (u8) enable;
        lbl_805DE19C = func;
        lbl_805DE198 = (u8) update;
    }
}

void HSD_StateSetPointSize(u8 size, s32 tex_offsets)
{
    if (lbl_805DE1BC != size || lbl_805DE1B8 != tex_offsets) {
        GXSetPointSize(size, tex_offsets);
        lbl_805DE1BC = size;
        lbl_805DE1B8 = tex_offsets;
    }
}

void HSD_StateSetAlphaCompare(s32 comp0, u8 ref0, s32 op, s32 comp1, u8 ref1)
{
    if (lbl_805DE194 != comp0 || lbl_805DE190 != ref0 || lbl_805DE18C != op ||
        lbl_805DE188 != comp1 || lbl_805DE186 != ref1)
    {
        GXSetAlphaCompare(comp0, ref0, op, comp1, ref1);
        lbl_805DE194 = comp0;
        lbl_805DE190 = ref0;
        lbl_805DE18C = op;
        lbl_805DE188 = comp1;
        lbl_805DE186 = ref1;
    }
}

void HSD_StateSetColorUpdate(u32 enable)
{
    enable = enable ? 1 : 0;
    if (lbl_805DE185 != enable) {
        GXSetColorUpdate(enable);
        lbl_805DE185 = (u8) enable;
    }
}

void HSD_StateSetAlphaUpdate(u32 enable)
{
    enable = enable ? 1 : 0;
    if (lbl_805DE184 != enable) {
        GXSetAlphaUpdate(enable);
        lbl_805DE184 = (u8) enable;
    }
}

void HSD_StateSetDstAlpha(u32 enable, u8 value)
{
    enable = enable ? 1 : 0;
    if (lbl_805DE183 != enable || lbl_805DE182 != value) {
        GXSetDstAlpha(enable, value);
        lbl_805DE183 = (u8) enable;
        lbl_805DE182 = value;
    }
}

void HSD_StateSetZCompLoc(u32 before_tex)
{
    before_tex = before_tex ? 1 : 0;
    if (lbl_805DE181 != before_tex) {
        GXSetZCompLoc(before_tex);
        lbl_805DE181 = (u8) before_tex;
    }
}

void HSD_StateSetDither(u32 enable)
{
    enable = enable ? 1 : 0;
    if (lbl_805DE180 != enable) {
        GXSetDither(enable);
        lbl_805DE180 = (u8) enable;
    }
}

void _HSD_StateInvalidatePrimitive(void)
{
    lbl_805DE1BC = 0;
    lbl_805DE1B4 = -1;
    lbl_805DE1C4 = 0xFF;
}

void _HSD_StateInvalidateVtxAttr(void)
{
    HSD_ClearVtxDesc();
}

void _HSD_StateInvalidateRenderMode(void)
{
    lbl_805DE1B0 = -1;
    lbl_805DE1AC = -1;
    lbl_805DE1A8 = -1;
    lbl_805DE1A4 = -1;
    lbl_805DE1A0 = 0xFF;
    lbl_805DE19C = -1;
    lbl_805DE198 = 0xFF;
    lbl_805DE194 = -1;
    lbl_805DE190 = 0;
    lbl_805DE18C = -1;
    lbl_805DE188 = -1;
    lbl_805DE186 = 0;
    lbl_805DE185 = 0xFF;
    lbl_805DE184 = 0xFF;
    lbl_805DE183 = 0xFF;
    lbl_805DE182 = 0;
    lbl_805DE181 = 0xFF;
    lbl_805DE180 = 0xFF;
}

void HSD_StateInvalidate(s32 mask)
{
    s32 i = 0;
    s32 m;
    while ((m = lbl_80502420[i].mask) != 0) {
        if (mask & m) {
            lbl_80502420[i].func();
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
        if (lbl_805DE1D8[no] != 0) {
            lbl_805DE1D8[no] = 0;
            GXSetChanAmbColor(no + 4, ch->amb_color);
            lbl_80502490[no].amb_color = ch->amb_color;
        } else if (chan == 4 || chan == 5) {
            if (CompareRGBA(&ch->amb_color, &lbl_80502490[no].amb_color)) {
                lbl_80502490[no].amb_color = ch->amb_color;
                goto set_amb;
            }
        } else if (chan == 0 || chan == 1) {
            if (CompareRGB(&ch->amb_color, &lbl_80502490[no].amb_color)) {
                CopyRGB(&lbl_80502490[no].amb_color, &ch->amb_color);
                goto set_amb;
            }
        } else if (ch->amb_color.a != lbl_80502490[no].amb_color.a) {
            lbl_80502490[no].amb_color.a = ch->amb_color.a;
        set_amb:
            GXSetChanAmbColor(chan, ch->amb_color);
        }
    }

    if (ch->mat_src == 0) {
        if (lbl_805DE1D0[no] != 0) {
            lbl_805DE1D0[no] = 0;
            GXSetChanMatColor(no + 4, ch->mat_color);
            lbl_80502490[no].mat_color = ch->mat_color;
        } else if (chan == 4 || chan == 5) {
            if (CompareRGBA(&ch->mat_color, &lbl_80502490[no].mat_color)) {
                lbl_80502490[no].mat_color = ch->mat_color;
                goto set_mat;
            }
        } else if (chan == 0 || chan == 1) {
            if (CompareRGB(&ch->mat_color, &lbl_80502490[no].mat_color)) {
                CopyRGB(&lbl_80502490[no].mat_color, &ch->mat_color);
                goto set_mat;
            }
        } else if (ch->mat_color.a != lbl_80502490[no].mat_color.a) {
            lbl_80502490[no].mat_color.a = ch->mat_color.a;
        set_mat:
            GXSetChanMatColor(chan, ch->mat_color);
        }
    }

    if (ch->enable != lbl_80502490[idx].enable || ch->amb_src != lbl_80502490[idx].amb_src ||
        ch->mat_src != lbl_80502490[idx].mat_src ||
        ch->light_mask != lbl_80502490[idx].light_mask ||
        ch->diff_fn != lbl_80502490[idx].diff_fn || ch->attn_fn != lbl_80502490[idx].attn_fn)
    {
        GXSetChanCtrl(chan, ch->enable, ch->amb_src, ch->mat_src, ch->light_mask, ch->diff_fn,
                      ch->attn_fn);
        lbl_80502490[idx].enable = ch->enable;
        lbl_80502490[idx].amb_src = ch->amb_src;
        lbl_80502490[idx].mat_src = ch->mat_src;
        lbl_80502490[idx].light_mask = ch->light_mask;
        lbl_80502490[idx].diff_fn = ch->diff_fn;
        lbl_80502490[idx].attn_fn = ch->attn_fn;

        if (chan == 4 || chan == 5) {
            lbl_80502490[idx + 2].enable = ch->enable;
            lbl_80502490[idx + 2].amb_src = ch->amb_src;
            lbl_80502490[idx + 2].mat_src = ch->mat_src;
            lbl_80502490[idx + 2].light_mask = ch->light_mask;
            lbl_80502490[idx + 2].diff_fn = ch->diff_fn;
            lbl_80502490[idx + 2].attn_fn = ch->attn_fn;
        }
    }
}

void HSD_DisableChannelLighting(s32 chan)
{
    s32 idx = chan & 3;

    if (chan >= 4 && chan < 6) {
        HSD_Chan* c0 = &lbl_80502490[idx];
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
        HSD_Chan* c = &lbl_80502490[idx];
        if (c->enable != 0) {
            c->enable = 0;
            c->light_mask = 0;
            GXSetChanCtrl(chan, 0, c->amb_src, c->mat_src, 0, c->diff_fn, c->attn_fn);
        }
    }
}

void HSD_StateSetNumChans(s32 num)
{
    if (lbl_805DE1CC != num) {
        GXSetNumChans(num);
        lbl_805DE1CC = num;
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
        num = lbl_80502978[coord];
    }

    if (num > lbl_805DE1C8) {
        lbl_805DE1C8 = num;
    }
    return num;
}

void HSD_StateSetNumTexGens(void)
{
    GXSetNumTexGens(lbl_805DE1C8);
    lbl_805DE1C8 = 0;
}

void HSD_StateInitTev(void)
{
    lbl_805DE1E0 = 0;
}

s32 HSD_StateGetNumTevStages(void)
{
    return lbl_805DE1E0;
}

u32 HSD_StateAssignTev(void)
{
    s32 cur = lbl_805DE1E0;
    lbl_805DE1E0 = cur + 1;
    return lbl_805028E8[cur];
}

void HSD_StateSetNumTevStages(void)
{
    GXSetNumTevStages(lbl_805DE1E0);
    lbl_805DE1E0 = 0;
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
        fresh = &lbl_80502550[stage != 0][desc->u.tevop.tevmode];
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
        u32 tmp = lbl_80502928[td->stage];
        if ((s32) tmp > num) {
            num = tmp;
        }
        HSD_SetupTevStage(td);
    }

    lbl_805DE1E0 = num;
    GXSetNumTevStages(num);
    lbl_805DE1E0 = 0;
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
        if (lbl_80502460[i].c != 0) {
            GXSetTevColorS10(lbl_80502968[i], lbl_80502460[i].a);
            lbl_80502460[i].c = 0;
        }
    }
}

void _HSD_StateInvalidateColorChannel(void)
{
    memcpy(&lbl_80502490, &lbl_80502998, sizeof(lbl_80502490));
    lbl_805DE1D8[0] = 1;
    lbl_805DE1D8[1] = 1;
    lbl_805DE1D0[0] = 1;
    lbl_805DE1D0[1] = 1;
    lbl_805DE1CC = -1;
}

void _HSD_StateInvalidateTevStage(void)
{
    s32 i;
    lbl_805DE1E0 = 0;
    for (i = 0; i < 16; i++) {
        tev_order_cache[i].coord = lbl_80502A58.coord;
        tev_order_cache[i].map = lbl_80502A58.map;
        tev_order_cache[i].color = lbl_80502A58.color;
        tev_conf_cache[i] = lbl_80502A64;
    }
}

void fn_803F9890(void)
{
    lbl_80502460[0].c = 0;
    lbl_80502460[1].c = 0;
    lbl_80502460[2].c = 0;
    lbl_80502460[3].c = 0;
}

void fn_803F98B0(void)
{
    lbl_805DE1C8 = 0;
}

void _HSD_StateInvalidateTevRegister(u32 mask)
{
    lbl_805DE1EC = mask;
}

void _HSD_StateInvalidateTexCoordGen(u32* obj, u32 mask)
{
    if (obj == NULL) {
        return;
    }
    obj[1] |= mask;
}
