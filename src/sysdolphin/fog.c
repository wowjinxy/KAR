#include <sysdolphin/fog.h>

#include <sysdolphin/cobj.h>

extern HSD_ClassInfo hsdObj;
extern HSD_Fog* lbl_805DE2E8; // current fog

extern char kar_srcfile_fog_c_805dccc0[6]; // "fog.c"
extern char lbl_805DCCC8[4];               // "fog"
extern char lbl_805DCCD0[4];               // "adj"
extern char lbl_805DCCD4[8];               // "hsd_fog"

extern GXColor lbl_805DCCCC;
extern GXColor lbl_805E6380;

extern char lbl_805042EC[30]; // "You must specify CObj first.\n"

extern char lbl_80504364[0x24]; // "sysdolphin_base_library"

extern f32 lbl_805E5D10; // 0.0F
extern f32 lbl_805E5D14; // 640.0F
extern f32 lbl_805E5D18; // 0.5F
extern f32 lbl_805E5D1C; // -1.0F
extern f32 lbl_805E5D20; // 1.0F
extern f32 lbl_805E5D30; // 255.0F

extern void HSD_Panic(const char* file, s32 line, const char* msg);
extern void* hsdNew(HSD_ClassInfo* info);
extern void hsdInitClassInfo(HSD_ClassInfo* class_info,
                             HSD_ClassInfo* parent_info,
                             char* base_class_library, char* type,
                             s32 info_size, s32 class_size);

extern void GXSetFog(u32 type, f32 startz, f32 endz, f32 nearz, f32 farz,
                    GXColor color);
extern void GXSetFogRangeAdj(u32 enable, u16 center, void* table);
extern void fn_803D09F0(f32* vp);           // GXGetViewportv
extern void fn_803D06DC(f32* ptr);          // GXGetProjectionv
extern void fn_803CF558(void* table, u16 width, Mtx44Ptr projmtx); // GXInitFogAdjTable

typedef struct {
    u16 r[10];
} GXFogAdjTable;

#define assert_line_named(line, cond, condstr)                               \
    ((cond) ? ((void) 0) : __assert(kar_srcfile_fog_c_805dccc0, line, condstr))

void FogInfoInit(void);
void FogAdjInfoInit(void);

extern HSD_FogInfo lbl_80504270;
extern HSD_FogAdjInfo lbl_805042B0;

void kar_fog_set_current_and_apply(HSD_Fog* fog)
{
    lbl_805DE2E8 = fog;
    HSD_FogSet(fog);
}

HSD_Fog* kar_fog_get_current(void)
{
    return lbl_805DE2E8;
}

void HSD_FogSet(HSD_Fog* fog)
{
    HSD_CObj* cobj;
    HSD_FogAdj* fog_adj;
    u32 flags;
    GXFogAdjTable tbl;
    f32 v[6];
    s32 range;
    s32 width;
    Mtx44Ptr mtx;

    if (fog == NULL) {
        GXSetFog(0, lbl_805E5D10, lbl_805E5D10, lbl_805E5D10, lbl_805E5D10, lbl_805E6380);
        return;
    }

    cobj = HSD_CObjGetCurrent();
    if (cobj == NULL) {
        HSD_Panic(kar_srcfile_fog_c_805dccc0, 0x8B, lbl_805042EC);
    }

    GXSetFog(fog->type, fog->start, fog->end * fog->end_scale,
             HSD_CObjGetNear(cobj), HSD_CObjGetFar(cobj), fog->color);

    fog_adj = (fog != NULL) ? fog->fog_adj : NULL;
    flags = HSD_FogAdjGetFlags(fog_adj);
    if (fog_adj != NULL && (flags & 7) != 0) {
        fn_803D09F0(v);

        if (flags & 1) {
            s32 center = (fog_adj != NULL) ? fog_adj->center : -1;
            range = v[0] + v[2] * (center + 320) / lbl_805E5D14;
        } else {
            range = v[0] + v[2] * lbl_805E5D18;
        }

        if (flags & 2) {
            width = (fog_adj != NULL) ? fog_adj->width : -1;
        } else {
            width = (s32) v[2];
        }

        if (flags & 4) {
            mtx = (fog_adj != NULL) ? fog_adj->mtx : NULL;
        } else {
            Mtx44 local_mtx;
            struct {
                f32 x0;
                f32 v[6];
            } proj;

            mtx = local_mtx;
            memset(mtx, 0, sizeof(Mtx44));
            fn_803D06DC((f32*) &proj);
            switch ((s32) proj.x0) {
            case 0:
                mtx[0][0] = proj.v[0];
                mtx[0][2] = proj.v[1];
                mtx[1][1] = proj.v[2];
                mtx[1][2] = proj.v[3];
                mtx[2][2] = proj.v[4];
                mtx[2][3] = proj.v[5];
                mtx[3][2] = lbl_805E5D1C;
                break;
            default:
                mtx[0][0] = proj.v[0];
                mtx[0][3] = proj.v[1];
                mtx[1][1] = proj.v[2];
                mtx[1][3] = proj.v[3];
                mtx[2][2] = proj.v[4];
                mtx[2][3] = proj.v[5];
                mtx[3][3] = lbl_805E5D20;
                break;
            }
        }

        fn_803CF558(&tbl, (u16) width, mtx);
        GXSetFogRangeAdj(1, (u16) range, &tbl);
    } else {
        GXSetFogRangeAdj(0, 0, NULL);
    }
}

static inline HSD_Fog* HSD_FogAlloc(void)
{
    HSD_Fog* fog = hsdNew(HSD_CLASS_INFO(&lbl_80504270));
    assert_line_named(0xD4, fog, lbl_805DCCC8);
    return fog;
}

HSD_Fog* HSD_FogLoadDesc(HSD_FogDesc* desc)
{
    HSD_Fog* fog = HSD_FogAlloc();
    assert_line_named(0xE1, fog, lbl_805DCCC8);
    HSD_FogInit(fog, desc);
    if (desc->fogadjdesc != NULL) {
        fog->fog_adj = HSD_FogAdjLoadDesc(desc->fogadjdesc);
    }
    return fog;
}

void HSD_FogInit(HSD_Fog* fog, HSD_FogDesc* desc)
{
    if (fog != NULL) {
        if (desc != NULL) {
            fog->type = desc->type;
            fog->start = desc->start;
            fog->end = desc->end;
            fog->color = desc->color;
        } else {
            f32 v[6];
            fn_803D09F0(v);
            fog->type = 2; // GX_FOG_LIN
            fog->start = v[4];
            fog->end = v[5];
            fog->color.r = 0xFF;
            fog->color.g = 0xFF;
            fog->color.b = 0xFF;
            fog->color.a = 0xFF;
        }
        fog->end_scale = lbl_805E5D20;
    }
}

GXColor HSD_FogGetColor(HSD_Fog* fog)
{
    if (fog != NULL) {
        return fog->color;
    }
    return lbl_805DCCCC;
}

static inline HSD_FogAdj* HSD_FogAdjAlloc(void)
{
    HSD_FogAdj* adj = hsdNew(HSD_CLASS_INFO(&lbl_805042B0));
    assert_line_named(0x12D, adj, lbl_805DCCD0);
    return adj;
}

HSD_FogAdj* HSD_FogAdjLoadDesc(HSD_FogAdjDesc* desc)
{
    HSD_FogAdj* adj = HSD_FogAdjAlloc();
    assert_line_named(0x13D, adj, lbl_805DCCD0);
    HSD_FogAdjInit(adj, desc);
    return adj;
}

void HSD_FogAdjInit(HSD_FogAdj* adj, HSD_FogAdjDesc* desc)
{
    if (adj != NULL) {
        if (desc != NULL) {
            adj->flags = desc->flags;
            adj->width = desc->width;
            adj->center = desc->center;
            memcpy(adj->mtx, desc->mtx, sizeof(Mtx44));
        } else {
            adj->flags = 0;
            adj->width = 0;
            adj->center = 0;
            memset(adj->mtx, 0, sizeof(Mtx44));
        }
    }
}

u32 HSD_FogAdjGetFlags(HSD_FogAdj* fog_adj)
{
    if (fog_adj != NULL) {
        return fog_adj->flags;
    }
    return 0;
}

void fn_8041B620(HSD_Fog* fog, u32 type, HSD_ObjData* val)
{
    if (fog != NULL) {
        switch (type) {
        case 1:
            fog->start = val->fv;
            break;
        case 2:
            fog->end = val->fv;
            break;
        case 5: {
            f32 v;
            if (val->fv <= lbl_805E5D10) {
                v = lbl_805E5D10;
            } else if (val->fv >= lbl_805E5D20) {
                v = lbl_805E5D20;
            } else {
                v = val->fv;
            }
            fog->color.r = (u8) (lbl_805E5D30 * v);
            break;
        }
        case 6: {
            f32 v;
            if (val->fv <= lbl_805E5D10) {
                v = lbl_805E5D10;
            } else if (val->fv >= lbl_805E5D20) {
                v = lbl_805E5D20;
            } else {
                v = val->fv;
            }
            fog->color.g = (u8) (lbl_805E5D30 * v);
            break;
        }
        case 7: {
            f32 v;
            if (val->fv <= lbl_805E5D10) {
                v = lbl_805E5D10;
            } else if (val->fv >= lbl_805E5D20) {
                v = lbl_805E5D20;
            } else {
                v = val->fv;
            }
            fog->color.b = (u8) (lbl_805E5D30 * v);
            break;
        }
        case 8: {
            f32 v;
            if (val->fv <= lbl_805E5D10) {
                v = lbl_805E5D10;
            } else if (val->fv >= lbl_805E5D20) {
                v = lbl_805E5D20;
            } else {
                v = val->fv;
            }
            fog->color.a = (u8) (lbl_805E5D30 * v);
            break;
        }
        case 20: {
            s32 v = (s32) val->fv;
            HSD_FogAdj* adj = (fog != NULL) ? fog->fog_adj : NULL;
            if (adj != NULL) {
                if (v <= -0x140) {
                    adj->center = -0x140;
                } else if (v >= 0x140) {
                    adj->center = 0x140;
                } else {
                    adj->center = v;
                }
            }
            break;
        }
        case 21: {
            s32 v = (s32) val->fv;
            HSD_FogAdj* adj = (fog != NULL) ? fog->fog_adj : NULL;
            if (adj != NULL) {
                if (v <= 0) {
                    adj->width = 0;
                } else if (v >= 0x280) {
                    adj->width = 0x280;
                } else {
                    adj->width = v;
                }
            }
            break;
        }
        }
    }
}

static inline bool ref_DEC(void* o)
{
    bool ret;
    if ((ret = (HSD_OBJ(o)->ref_count == HSD_OBJ_NOREF))) {
        return ret;
    }
    return HSD_OBJ(o)->ref_count-- == 0;
}

void FogRelease(HSD_Fog* fog)
{
    HSD_FogAdj* adj = fog->fog_adj;
    if (adj != NULL) {
        if (ref_DEC(adj)) {
            if (adj != NULL) {
                HSD_OBJECT_METHOD(adj)->release((HSD_Class*) adj);
                HSD_OBJECT_METHOD(adj)->destroy((HSD_Class*) adj);
            }
        }
    }
    HSD_AObjRemove(fog->aobj);
    HSD_OBJECT_PARENT_INFO(&lbl_80504270)->release((HSD_Class*) fog);
}

void FogInfoInit(void)
{
    hsdInitClassInfo(HSD_CLASS_INFO(&lbl_80504270), &hsdObj, lbl_80504364,
                     lbl_805DCCD4, sizeof(HSD_FogInfo), sizeof(HSD_Fog));
    HSD_CLASS_INFO(&lbl_80504270)->release = (void*) FogRelease;
    lbl_80504270.update = fn_8041B620;
}

void FogAdjInfoInit(void)
{
    hsdInitClassInfo((HSD_ClassInfo*) ((char*) &lbl_80504270 + 0x40), &hsdObj,
                     (char*) &lbl_80504270 + 0xF4,
                     (char*) &lbl_80504270 + 0x10C, sizeof(HSD_FogAdjInfo),
                     sizeof(HSD_FogAdj));
}
