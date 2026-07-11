#include <sysdolphin/fog.h>

#include <sysdolphin/class_new.h>
#include <sysdolphin/cobj.h>
#include <sysdolphin/gobjproc.h>

extern HSD_Fog* FogCurrent;

extern char FogSourceFile[6]; // "fog.c"
extern char FogAssertFog[4];  // "fog"
extern char FogAssertAdj[4];  // "adj"
extern char FogClassName[8];  // "hsd_fog"

extern GXColor FogDefaultColor;
extern GXColor FogZeroColor;

extern char FogMissingCObjMessage[30]; // "You must specify CObj first.\n"

extern char FogClassStringBlock[0x24]; // "sysdolphin_base_library"

extern f32 FogFloatZero;     // 0.0F
extern f32 FogViewportWidth; // 640.0F
extern f32 FogHalf;          // 0.5F
extern f32 FogNegOne;        // -1.0F
extern f32 FogFloatOne;      // 1.0F
extern f32 FogColorScale;    // 255.0F

extern void GXSetFog(u32 type, f32 startz, f32 endz, f32 nearz, f32 farz,
                    GXColor color);
extern void GXSetFogRangeAdj(u32 enable, u16 center, void* table);
extern void GXGetViewportv(f32* vp);
extern void GXGetProjectionv(f32* ptr);
extern void GXInitFogAdjTable(void* table, u16 width, Mtx44Ptr projmtx);

typedef struct {
    u16 r[10];
} GXFogAdjTable;

#define assert_line_named(line, cond, condstr)                               \
    ((cond) ? ((void) 0) : __assert(FogSourceFile, line, condstr))

void FogInfoInit(void);
void FogAdjInfoInit(void);

HSD_FogInfo hsdFog = { FogInfoInit };
HSD_FogAdjInfo hsdFogAdj = { FogAdjInfoInit };

void kar_fog_set_current_and_apply(HSD_Fog* fog)
{
    FogCurrent = fog;
    HSD_FogSet(fog);
}

HSD_Fog* kar_fog_get_current(void)
{
    return FogCurrent;
}

void HSD_FogSet(HSD_Fog* fog)
{
    HSD_CObj* cobj;
    HSD_FogAdj* fog_adj;
    u32 flags;
    f32 v[6];
    s32 range;
    s32 width;
    Mtx44Ptr mtx;
    GXFogAdjTable tbl;

    if (fog == NULL) {
        GXSetFog(0, FogFloatZero, FogFloatZero, FogFloatZero, FogFloatZero,
                 FogZeroColor);
        return;
    }

    cobj = HSD_CObjGetCurrent();
    if (cobj == NULL) {
        HSD_Panic(FogSourceFile, 0x8B, FogMissingCObjMessage);
    }

    GXSetFog(fog->type, fog->start, fog->end * fog->end_scale,
             HSD_CObjGetNear(cobj), HSD_CObjGetFar(cobj), fog->color);

    fog_adj = (fog != NULL) ? fog->fog_adj : NULL;
    flags = HSD_FogAdjGetFlags(fog_adj);
    if (fog_adj == NULL || (flags & 7) == 0) {
        GXSetFogRangeAdj(0, 0, NULL);
        return;
    }

    GXGetViewportv(v);

    if (flags & 1) {
        s32 center = (fog_adj != NULL) ? fog_adj->center : -1;
        range = v[0] + v[2] * (center + 320) / FogViewportWidth;
    } else {
        range = v[0] + v[2] * FogHalf;
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

        memset(local_mtx, 0, sizeof(Mtx44));
        GXGetProjectionv((f32*) &proj);
        switch ((s32) proj.x0) {
        case 0:
            local_mtx[0][0] = proj.v[0];
            local_mtx[0][2] = proj.v[1];
            local_mtx[1][1] = proj.v[2];
            local_mtx[1][2] = proj.v[3];
            local_mtx[2][2] = proj.v[4];
            local_mtx[2][3] = proj.v[5];
            local_mtx[3][2] = FogNegOne;
            break;
        default:
            local_mtx[0][0] = proj.v[0];
            local_mtx[0][3] = proj.v[1];
            local_mtx[1][1] = proj.v[2];
            local_mtx[1][3] = proj.v[3];
            local_mtx[2][2] = proj.v[4];
            local_mtx[2][3] = proj.v[5];
            local_mtx[3][3] = FogFloatOne;
            break;
        }
        mtx = local_mtx;
    }

    GXInitFogAdjTable(&tbl, (u16) width, mtx);
    GXSetFogRangeAdj(1, (u16) range, &tbl);
}

static inline HSD_Fog* HSD_FogAlloc(void)
{
    HSD_Fog* fog = hsdNew(HSD_CLASS_INFO(&hsdFog));
    assert_line_named(0xD4, fog, FogAssertFog);
    return fog;
}

HSD_Fog* HSD_FogLoadDesc(HSD_FogDesc* desc)
{
    HSD_Fog* fog = HSD_FogAlloc();
    assert_line_named(0xE1, fog, FogAssertFog);
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
            GXGetViewportv(v);
            fog->type = 2; // GX_FOG_LIN
            fog->start = v[4];
            fog->end = v[5];
            fog->color.r = 0xFF;
            fog->color.g = 0xFF;
            fog->color.b = 0xFF;
            fog->color.a = 0xFF;
        }
        fog->end_scale = FogFloatOne;
    }
}

GXColor HSD_FogGetColor(HSD_Fog* fog)
{
    if (fog != NULL) {
        return fog->color;
    }
    return FogDefaultColor;
}

static inline HSD_FogAdj* HSD_FogAdjAlloc(void)
{
    HSD_FogAdj* adj = hsdNew(HSD_CLASS_INFO(&hsdFogAdj));
    assert_line_named(0x12D, adj, FogAssertAdj);
    return adj;
}

HSD_FogAdj* HSD_FogAdjLoadDesc(HSD_FogAdjDesc* desc)
{
    HSD_FogAdj* adj = HSD_FogAdjAlloc();
    assert_line_named(0x13D, adj, FogAssertAdj);
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

void FogUpdateFunc(HSD_Fog* fog, u32 type, HSD_ObjData* val)
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
            if (val->fv <= FogFloatZero) {
                v = FogFloatZero;
            } else if (val->fv >= FogFloatOne) {
                v = FogFloatOne;
            } else {
                v = val->fv;
            }
            fog->color.r = (u8) (FogColorScale * v);
            break;
        }
        case 6: {
            f32 v;
            if (val->fv <= FogFloatZero) {
                v = FogFloatZero;
            } else if (val->fv >= FogFloatOne) {
                v = FogFloatOne;
            } else {
                v = val->fv;
            }
            fog->color.g = (u8) (FogColorScale * v);
            break;
        }
        case 7: {
            f32 v;
            if (val->fv <= FogFloatZero) {
                v = FogFloatZero;
            } else if (val->fv >= FogFloatOne) {
                v = FogFloatOne;
            } else {
                v = val->fv;
            }
            fog->color.b = (u8) (FogColorScale * v);
            break;
        }
        case 8: {
            f32 v;
            if (val->fv <= FogFloatZero) {
                v = FogFloatZero;
            } else if (val->fv >= FogFloatOne) {
                v = FogFloatOne;
            } else {
                v = val->fv;
            }
            fog->color.a = (u8) (FogColorScale * v);
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
    HSD_OBJECT_PARENT_INFO(&hsdFog)->release((HSD_Class*) fog);
}

void FogInfoInit(void)
{
    hsdInitClassInfo(HSD_CLASS_INFO(&hsdFog), &hsdObj, FogClassStringBlock,
                     FogClassName, sizeof(HSD_FogInfo), sizeof(HSD_Fog));
    HSD_CLASS_INFO(&hsdFog)->release = (void*) FogRelease;
    hsdFog.update = FogUpdateFunc;
}

void FogAdjInfoInit(void)
{
    hsdInitClassInfo((HSD_ClassInfo*) ((char*) &hsdFog + 0x40), &hsdObj,
                     (char*) &hsdFog + 0xF4,
                     (char*) &hsdFog + 0x10C, sizeof(HSD_FogAdjInfo),
                     sizeof(HSD_FogAdj));
}
