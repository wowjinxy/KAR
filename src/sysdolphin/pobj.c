#include <global.h>
#include <dolphin/mtx/mtx.h>
#include <kar/math.h>
#include <sysdolphin/pobj.h>

#include <sysdolphin/id.h>
#include <sysdolphin/gobjproc.h>
#include <sysdolphin/memory.h>
#include <sysdolphin/mtx.h>
#include <sysdolphin/tev.h>

extern HSD_ClassInfo hsdClass;

extern void* hsdNew(HSD_ClassInfo* info);
extern void* hsdAllocMemPiece(s32 size);
extern void hsdInitClassInfo(HSD_ClassInfo* class_info, HSD_ClassInfo* parent_info,
                             char* base_class_library, char* type,
                             s32 info_size, s32 class_size);
extern struct _HSD_ClassInfo* hsdSearchClassInfo(char* class_name);
extern BOOL hsdIsDescendantOf(void* info, void* base);

extern void memset(void*, int, int);
extern void memcpy(void*, const void*, int);

extern void _HSD_NeedCacheInvalidate(u32 flags);

extern HSD_JObj* HSD_JObjGetCurrent(void);
extern void HSD_JObjUnrefThis(HSD_JObj* jobj);

extern void GXClearVtxDesc(void);
extern void GXSetVtxDesc(u32 attr, u32 type);
extern void GXSetVtxAttrFmt(u32 vtxfmt, u32 attr, u32 comp_cnt, u32 comp_type, u8 frac);
extern void GXSetArray(u32 attr, void* base_ptr, u8 stride);
extern void GXBegin(u8 prim, u8 vtxfmt, u16 nverts);
extern void GXCallDisplayList(void* list, u32 nbytes);
extern void GXSetCurrentMtx(u32 id);
extern void GXLoadPosMtxImm(MtxPtr mtx, u32 id);
extern void GXLoadTexMtxImm(MtxPtr mtx, u32 id, u32 type);

extern u32 kar_grcoll__803d1670(Mtx src, Mtx xpose);
extern void GXLoadNrmMtxImm(Mtx mtx, u32 id);

extern BOOL _HSD_MemCheckOwn(void* ptr);
extern void HSD_PerfCountEnvelopeBlending(s32 n);

extern HSD_PObjInfo* PObjCurrentInfo;
extern f32 (*PObjVertexBuffer)[3];
extern f32 (*PObjNormalBuffer)[3];
extern u32 PObjVertexBufferSize;
extern u32 PObjNormalBufferSize;
extern HSD_VtxDescList* PObjPrevVtxDescListArray;
extern HSD_VtxDescList* PObjPrevVtxDesc;

extern struct {
    void* obj;
    u32 mark;
} PObjMtxMark[2];

extern struct {
    u8 pad[0xC];
    s32 unkC;
} HSD_PerfCurrentStat;

extern s32 HSD_Index2PosNrmMtx[10];

void PObjInfoInit(void);

HSD_PObjInfo hsdPObj = { PObjInfoInit };

#define vertex_buffer PObjVertexBuffer
#define normal_buffer PObjNormalBuffer
#define vertex_buffer_size PObjVertexBufferSize
#define normal_buffer_size PObjNormalBufferSize

char kar_srcfile_pobj_c[] = "pobj.c";
char PObjAssertPObj[] = "pobj";

extern char JObjAssertMtx[8];

#define ASSERT_POBJ(line, cond) \
    ((cond) ? ((void) 0) : __assert(kar_srcfile_pobj_c, line, #cond))
#define ASSERT_POBJ_MSG(line, cond, msg) \
    ((cond) ? ((void) 0) : __assert(kar_srcfile_pobj_c, line, msg))

#define GX_WGPIPE ((volatile u8*) 0xCC008000)

static inline void GXPosition3f32(f32 x, f32 y, f32 z)
{
    *(volatile f32*) GX_WGPIPE = x;
    *(volatile f32*) GX_WGPIPE = y;
    *(volatile f32*) GX_WGPIPE = z;
}

static inline void GXNormal3f32(f32 x, f32 y, f32 z)
{
    *(volatile f32*) GX_WGPIPE = x;
    *(volatile f32*) GX_WGPIPE = y;
    *(volatile f32*) GX_WGPIPE = z;
}

static inline void GXMatrixIndex1u8(u8 idx)
{
    *(volatile u8*) GX_WGPIPE = idx;
}

static inline void GXTexCoord1x8(u8 idx)
{
    *(volatile u8*) GX_WGPIPE = idx;
}

static inline void GXTexCoord1x16(u16 idx)
{
    *(volatile u16*) GX_WGPIPE = idx;
}

static inline void GXColor1x8(u8 idx)
{
    *(volatile u8*) GX_WGPIPE = idx;
}

static inline void GXColor1x16(u16 idx)
{
    *(volatile u16*) GX_WGPIPE = idx;
}

static inline void GXColor1u16(u16 clr)
{
    *(volatile u16*) GX_WGPIPE = clr;
}

static inline void GXColor3u8(u8 r, u8 g, u8 b)
{
    *(volatile u8*) GX_WGPIPE = r;
    *(volatile u8*) GX_WGPIPE = g;
    *(volatile u8*) GX_WGPIPE = b;
}

static inline void GXColor4u8(u8 r, u8 g, u8 b, u8 a)
{
    *(volatile u8*) GX_WGPIPE = r;
    *(volatile u8*) GX_WGPIPE = g;
    *(volatile u8*) GX_WGPIPE = b;
    *(volatile u8*) GX_WGPIPE = a;
}

static inline void GXEnd(void)
{
}

#define pobj_min(x, y) (x < y ? x : y)
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

void HSD_PObjRemoveAnimAllByFlags(HSD_PObj* pobj, u32 flags)
{
    if (pobj != NULL) {
        HSD_PObj* cur;
        for (cur = pobj; cur != NULL; cur = cur->next) {
            if (cur != NULL && flags & POBJ_ANIM) {
                HSD_AObjRemove(cur->aobj);
                cur->aobj = NULL;
            }
        }
    }
}

static inline void HSD_PObjAddAnim(HSD_PObj* pobj, HSD_ShapeAnim* shapeanim)
{
    if (pobj != NULL) {
        if (pobj->aobj != NULL) {
            HSD_AObjRemove(pobj->aobj);
        }
        pobj->aobj = HSD_AObjLoadDesc(shapeanim->aobjdesc);
    }
}

void HSD_PObjAddAnimAll(HSD_PObj* pobj, HSD_ShapeAnim* shapeanim)
{
    HSD_PObj* po;
    HSD_ShapeAnim* sa;

    if (pobj == NULL || shapeanim == NULL) {
        return;
    }

    for (po = pobj, sa = shapeanim; po != NULL; po = po->next, sa = next_p(sa)) {
        HSD_PObjAddAnim(po, sa);
    }
}

void HSD_PObjReqAnimAllByFlags(HSD_PObj* pobj, f32 startframe, u32 flags)
{
    HSD_PObj* cur;
    if (pobj == NULL) {
        return;
    }
    for (cur = pobj; cur != NULL; cur = cur->next) {
        if (cur != NULL && flags & POBJ_ANIM) {
            HSD_AObjReqAnim(cur->aobj, startframe);
        }
    }
}

void PObjUpdateFunc(void* obj, enum_t type, FObjData* val)
{
    HSD_PObj* pobj = HSD_POBJ(obj);
    if (pobj == NULL) {
        return;
    }

    if (pobj_type(pobj) == POBJ_SHAPEANIM) {
        HSD_ShapeSet* shape_set = pobj->u.shape_set;
        if (shape_set->flags & SHAPESET_ADDITIVE) {
            shape_set->blend.bp[type - HSD_A_S_W0] = val->fv;
        } else {
            shape_set->blend.bl = val->fv;
        }
    }
}

void HSD_PObjAnimAll(HSD_PObj* pobj)
{
    HSD_PObj* pp;

    if (pobj != NULL) {
        for (pp = pobj; pp != NULL; pp = pp->next) {
            if (pp != NULL) {
                HSD_AObjInterpretAnim(pp->aobj, pp, HSD_POBJ_METHOD(pp)->update);
            }
        }
    }
}

s32 PObjLoad(HSD_PObj* pobj, HSD_PObjDesc* desc)
{
    pobj->next = HSD_PObjLoadDesc(desc->next);
    pobj->verts = desc->verts;
    pobj->flags = desc->flags;
    pobj->n_display = desc->n_display;
    pobj->display = desc->display;

    switch (pobj_type(pobj)) {
    case POBJ_SHAPEANIM: {
        HSD_ShapeSetDesc* sdesc = desc->u.shape_set;
        HSD_ShapeSet* shape_set = hsdAllocMemPiece(sizeof(HSD_ShapeSet));
        ASSERT_POBJ(0x1E5, shape_set);
        memset(shape_set, 0, sizeof(HSD_ShapeSet));
        shape_set->flags = sdesc->flags;
        shape_set->nb_shape = sdesc->nb_shape;
        shape_set->nb_vertex_index = sdesc->nb_vertex_index;
        shape_set->vertex_desc = sdesc->vertex_desc;
        shape_set->vertex_idx_list = sdesc->vertex_idx_list;
        shape_set->nb_normal_index = sdesc->nb_normal_index;
        shape_set->normal_desc = sdesc->normal_desc;
        shape_set->normal_idx_list = sdesc->normal_idx_list;
        if (shape_set->flags & SHAPESET_ADDITIVE) {
            s32 i;
            shape_set->blend.bp = (f32*) HSD_Alloc(shape_set->nb_shape * sizeof(f32));
            for (i = 0; i < shape_set->nb_shape; i++) {
                shape_set->blend.bp[i] = 0.0f;
            }
        } else {
            shape_set->blend.bl = 0.0f;
        }
        pobj->u.shape_set = shape_set;
        break;
    }

    case POBJ_ENVELOPE: {
        HSD_EnvelopeDesc** edesc_p = desc->u.envelope_p;
        HSD_SList* list = NULL;
        HSD_SList** list_p = &list;

        if (edesc_p != NULL) {
            while (*edesc_p != NULL) {
                HSD_Envelope* envelope = NULL;
                HSD_Envelope** env_p = &envelope;
                HSD_EnvelopeDesc* edesc = *edesc_p;

                while (edesc->joint != NULL) {
                    HSD_Envelope* envelope = hsdAllocMemPiece(sizeof(HSD_Envelope));
                    ASSERT_POBJ(0x1AC, envelope);
                    memset(envelope, 0, sizeof(HSD_Envelope));
                    *env_p = envelope;
                    (*env_p)->weight = edesc->weight;
                    env_p = &((*env_p)->next);
                    edesc++;
                }

                *list_p = HSD_SListAlloc();
                (*list_p)->data = envelope;
                list_p = &((*list_p)->next);
                edesc_p++;
            }
        }
        pobj->u.envelope_list = list;
        break;
    }

    case POBJ_SKIN:
        break;

    default:
        HSD_Panic(__FILE__, 0x22D, "pobj: unexected type.\n");
    }

    _HSD_NeedCacheInvalidate(1);

    return 0;
}

HSD_PObj* HSD_PObjLoadDesc(HSD_PObjDesc* pobjdesc)
{
    if (pobjdesc != NULL) {
        HSD_PObj* pobj;
        HSD_ClassInfo* info;

        if (!pobjdesc->class_name ||
            !(info = (HSD_ClassInfo*) hsdSearchClassInfo(pobjdesc->class_name))) {
            pobj = HSD_PObjAlloc();
        } else {
            pobj = hsdNew(info);
            ASSERT_POBJ_MSG(0x24A, pobj, PObjAssertPObj);
        }
        HSD_POBJ_METHOD(pobj)->load(pobj, pobjdesc);
        return pobj;
    } else {
        return NULL;
    }
}

void HSD_PObjRemoveAll(HSD_PObj* pobj)
{
    HSD_PObj* next;

    while (pobj != NULL) {
        next = pobj->next;
        if (pobj != NULL) {
            HSD_CLASS_METHOD(pobj)->release((HSD_Class*) pobj);
            HSD_CLASS_METHOD(pobj)->destroy((HSD_Class*) pobj);
        }
        pobj = next;
    }
}

char PObjAssertDescendant[] = "hsdIsDescendantOf(info, &hsdPObj)";

void HSD_PObjSetCurrent(HSD_PObjInfo* info)
{
    if (info != NULL) {
        ASSERT_POBJ_MSG(0x28E, hsdIsDescendantOf(info, &hsdPObj), PObjAssertDescendant);
    }
    PObjCurrentInfo = info;
}

HSD_PObjInfo* HSD_PObjGetCurrent(void)
{
    return PObjCurrentInfo ? PObjCurrentInfo : &hsdPObj;
}

HSD_PObj* HSD_PObjAlloc(void)
{
    HSD_PObj* pobj = hsdNew((HSD_ClassInfo*) HSD_PObjGetCurrent());
    ASSERT_POBJ_MSG(0x2AC, pobj, PObjAssertPObj);
    return pobj;
}

#define ASSERT_REF_COUNT(line, cond) \
    ((cond) ? ((void) 0) \
            : __assert("object.h", line, "HSD_OBJ(o)->ref_count_individual != 0"))

void HSD_PObjResolveRefsAll(HSD_PObj* pobj, HSD_PObjDesc* pdesc)
{
    while (pobj != NULL && pdesc != NULL) {
        if (pobj != NULL && pdesc != NULL) {
            switch (pobj_type(pobj)) {
            case POBJ_ENVELOPE: {
                HSD_SList* list = pobj->u.envelope_list;
                HSD_EnvelopeDesc** edesc_p = pdesc->u.envelope_p;

                if (list != NULL && edesc_p != NULL) {
                    for (; list != NULL && *edesc_p != NULL; list = list->next, edesc_p++) {
                        HSD_Envelope* env = list->data;
                        HSD_EnvelopeDesc* edesc = *edesc_p;

                        while (env != NULL && edesc->joint != NULL) {
                            HSD_JObjUnrefThis(env->jobj);
                            env->jobj = HSD_IDGetDataFromTable(NULL, (u32) edesc->joint, NULL);
                            ASSERT_POBJ(0x2CD, env->jobj);
                            if (env->jobj != NULL) {
                                HSD_OBJ(env->jobj)->ref_count_individual++;
                                ASSERT_REF_COUNT(0x9E,
                                                 HSD_OBJ(env->jobj)->ref_count_individual != 0);
                            }
                            env = env->next;
                            edesc++;
                        }
                    }
                }
                break;
            }

            case POBJ_SKIN:
                HSD_JObjUnrefThis(pobj->u.jobj);
                pobj->u.jobj = NULL;
                if (pdesc->u.joint != NULL) {
                    pobj->u.jobj = HSD_IDGetDataFromTable(NULL, (u32) pdesc->u.joint, NULL);
                    ASSERT_POBJ(0x2E8, pobj->u.jobj);
                    if (pobj->u.jobj != NULL) {
                        HSD_OBJ(pobj->u.jobj)->ref_count_individual++;
                        ASSERT_REF_COUNT(0x9E, HSD_OBJ(pobj->u.jobj)->ref_count_individual != 0);
                    }
                }
                break;

            default:
                break;
            }
        }
        pobj = pobj->next;
        pdesc = pdesc->next;
    }
}

void HSD_ClearVtxDesc(void)
{
    GXClearVtxDesc();
    PObjPrevVtxDescListArray = 0;
    PObjPrevVtxDesc = 0;
}

char PObjAssertVertexXYZ[] = "shape_set->vertex_desc->comp_cnt == GX_POS_XYZ";
char PObjUnexpectedVertexType[] = "unexpected vertex type.\n";

void get_shape_vertex_xyz(HSD_ShapeSet* shape_set, s32 shape_id, s32 arrayidx,
                                 f32 dst[3])
{
    u8* index_array = shape_set->vertex_idx_list[shape_id];
    s32 idx;
    void* src_base;

    if (shape_set->vertex_desc->attr_type == GX_INDEX16) {
        idx = index_array[arrayidx * 2];
        idx = (idx << 8) + index_array[arrayidx * 2 + 1];
    } else {
        idx = index_array[arrayidx];
    }

    ASSERT_POBJ_MSG(0x43D, shape_set->vertex_desc->comp_cnt == GX_POS_XYZ,
                    PObjAssertVertexXYZ);
    src_base = ((u8*) shape_set->vertex_desc->vertex) + idx * shape_set->vertex_desc->stride;

    if (shape_set->vertex_desc->comp_type == GX_F32) {
        memcpy(dst, src_base, sizeof(f32[3]));
    } else {
        s32 decimal_point = 1 << shape_set->vertex_desc->frac;
        switch (shape_set->vertex_desc->comp_type) {
        case GX_U8: {
            u8* src = src_base;
            dst[0] = (f32) src[0] / decimal_point;
            dst[1] = (f32) src[1] / decimal_point;
            dst[2] = (f32) src[2] / decimal_point;
        } break;

        case GX_S8: {
            s8* src = src_base;
            dst[0] = (f32) src[0] / decimal_point;
            dst[1] = (f32) src[1] / decimal_point;
            dst[2] = (f32) src[2] / decimal_point;
        } break;

        case GX_U16: {
            u16* src = src_base;
            dst[0] = (f32) src[0] / decimal_point;
            dst[1] = (f32) src[1] / decimal_point;
            dst[2] = (f32) src[2] / decimal_point;
        } break;

        case GX_S16: {
            s16* src = src_base;
            dst[0] = (f32) src[0] / decimal_point;
            dst[1] = (f32) src[1] / decimal_point;
            dst[2] = (f32) src[2] / decimal_point;
        } break;

        default:
            HSD_Panic(kar_srcfile_pobj_c, 0x468, PObjUnexpectedVertexType);
        }
    }
}

char PObjAssertNormalXYZ[] = "shape_set->normal_desc->comp_cnt == GX_NRM_XYZ";
char PObjUnexpectedNormalType[] = "unexpected normal type.";

void get_shape_normal_xyz(HSD_ShapeSet* shape_set, s32 shape_id, s32 arrayidx,
                                 f32 dst[3])
{
    u8* index_array = shape_set->normal_idx_list[shape_id];
    s32 idx;
    void* src_base;

    if (shape_set->normal_desc->attr_type == GX_INDEX16) {
        idx = index_array[arrayidx * 2];
        idx = (idx << 8) + index_array[arrayidx * 2 + 1];
    } else {
        idx = index_array[arrayidx];
    }

    ASSERT_POBJ_MSG(0x47C, shape_set->normal_desc->comp_cnt == GX_NRM_XYZ,
                    PObjAssertNormalXYZ);
    src_base = ((u8*) shape_set->normal_desc->vertex) + idx * shape_set->normal_desc->stride;

    if (shape_set->normal_desc->comp_type == GX_F32) {
        memcpy(dst, src_base, sizeof(f32[3]));
    } else {
        s32 decimal_point = 1 << shape_set->normal_desc->frac;
        switch (shape_set->normal_desc->comp_type) {
        case GX_U8: {
            u8* src = src_base;
            dst[0] = (f32) src[0] / decimal_point;
            dst[1] = (f32) src[1] / decimal_point;
            dst[2] = (f32) src[2] / decimal_point;
        } break;
        case GX_S8: {
            s8* src = src_base;
            dst[0] = (f32) src[0] / decimal_point;
            dst[1] = (f32) src[1] / decimal_point;
            dst[2] = (f32) src[2] / decimal_point;
        } break;
        case GX_U16: {
            u16* src = src_base;
            dst[0] = (f32) src[0] / decimal_point;
            dst[1] = (f32) src[1] / decimal_point;
            dst[2] = (f32) src[2] / decimal_point;
        } break;
        case GX_S16: {
            s16* src = src_base;
            dst[0] = (f32) src[0] / decimal_point;
            dst[1] = (f32) src[1] / decimal_point;
            dst[2] = (f32) src[2] / decimal_point;
        } break;
        default:
            HSD_Panic(kar_srcfile_pobj_c, 0x4A7, PObjUnexpectedNormalType);
        }
    }
}

void get_shape_nbt_xyz(HSD_ShapeSet* shape_set, s32 shape_id, s32 arrayidx, f32* dst)
{
    u8* index_array = shape_set->normal_idx_list[shape_id];
    s32 i, idx;
    void* src_base;

    ASSERT_POBJ(0x4B4, shape_set->normal_desc->attr == GX_VA_NBT);

    if (shape_set->normal_desc->attr_type == GX_INDEX16) {
        idx = index_array[arrayidx * 2];
        idx = (idx << 8) + index_array[arrayidx * 2 + 1];
    } else {
        idx = index_array[arrayidx];
    }

    ASSERT_POBJ_MSG(0x4BD, shape_set->normal_desc->comp_cnt == GX_NRM_XYZ,
                    PObjAssertNormalXYZ);

    src_base = ((u8*) shape_set->normal_desc->vertex) + idx * shape_set->normal_desc->stride;

    if (shape_set->normal_desc->comp_type == GX_F32) {
        memcpy(dst, src_base, sizeof(f32[9]));
    } else {
        s32 decimal_point = 1 << shape_set->normal_desc->frac;
        switch (shape_set->normal_desc->comp_type) {
        case GX_U8:
            for (i = 0; i < 9; i++) {
                dst[i] = (f32) ((u8*) src_base)[i] / decimal_point;
            }
            break;
        case GX_S8:
            for (i = 0; i < 9; i++) {
                dst[i] = (f32) ((s8*) src_base)[i] / decimal_point;
            }
            break;
        case GX_U16:
            for (i = 0; i < 9; i++) {
                dst[i] = (f32) ((u16*) src_base)[i] / decimal_point;
            }
            break;
        case GX_S16:
            for (i = 0; i < 9; i++) {
                dst[i] = (f32) ((s16*) src_base)[i] / decimal_point;
            }
            break;
        default:
            HSD_Panic(kar_srcfile_pobj_c, 0x4DC, PObjUnexpectedNormalType);
        }
    }
}

char PObjUnsupportedAttr[] = "attr(%d) is not supported by sysdolphin\n";

void interpretShapeAnimDisplayList(HSD_PObj* pobj, f32 (*vertex)[3], f32 (*normal)[3])
{
    u8* dl = pobj->display;
    s32 length = pobj->n_display << 5;
    s32 l;

    for (l = 0; l + 3 < length;) {
        s32 n = dl[1] << 8 | dl[2];
        s32 m = 3;
        s32 i, j;

        if ((dl[0] & GX_OPCODE_MASK) == GX_NOP) {
            break;
        }
        GXBegin(dl[0] & GX_OPCODE_MASK, dl[0] & GX_VAT_MASK, n);
        for (i = 0; i < n; i++) {
            for (j = 0;; j++) {
                HSD_VtxDescList* desc = &pobj->verts[j];
                if (desc->attr == GX_VA_NULL) {
                    break;
                } else {
                    u16 idx = dl[m++];
                    switch (desc->attr) {
                    case GX_VA_PNMTXIDX:
                    case GX_VA_TEX0MTXIDX:
                    case GX_VA_TEX1MTXIDX:
                    case GX_VA_TEX2MTXIDX:
                    case GX_VA_TEX3MTXIDX:
                    case GX_VA_TEX4MTXIDX:
                    case GX_VA_TEX5MTXIDX:
                    case GX_VA_TEX6MTXIDX:
                    case GX_VA_TEX7MTXIDX:
                        GXMatrixIndex1u8(idx);
                        break;

                    case GX_VA_POS:
                        if (desc->attr_type == GX_INDEX16) {
                            idx = (idx << 8) | dl[m++];
                        }
                        GXPosition3f32(vertex[idx][0], vertex[idx][1], vertex[idx][2]);
                        break;

                    case GX_VA_NRM:
                        if (desc->attr_type == GX_INDEX16) {
                            idx = (idx << 8) | dl[m++];
                        }
                        GXNormal3f32(normal[idx][0], normal[idx][1], normal[idx][2]);
                        break;

                    case GX_VA_NBT:
                        if (desc->attr_type == GX_INDEX16) {
                            idx = (idx << 8) | dl[m++];
                        }
                        idx *= 3;
                        GXNormal3f32(normal[idx + 0][0], normal[idx + 0][1], normal[idx + 0][2]);
                        GXNormal3f32(normal[idx + 1][0], normal[idx + 1][1], normal[idx + 1][2]);
                        GXNormal3f32(normal[idx + 2][0], normal[idx + 2][1], normal[idx + 2][2]);
                        break;

                    case GX_VA_TEX0:
                    case GX_VA_TEX1:
                    case GX_VA_TEX2:
                    case GX_VA_TEX3:
                    case GX_VA_TEX4:
                    case GX_VA_TEX5:
                    case GX_VA_TEX6:
                    case GX_VA_TEX7:
                        if (desc->attr_type == GX_INDEX16) {
                            idx = (idx << 8) | dl[m++];
                            GXTexCoord1x16(idx);
                        } else {
                            GXTexCoord1x8(idx);
                        }
                        break;

                    case GX_VA_CLR0:
                    case GX_VA_CLR1:
                        if (desc->attr_type == GX_INDEX16) {
                            idx = (idx << 8) | dl[m++];
                            GXColor1x16(idx);
                        } else if (desc->attr_type == GX_INDEX8) {
                            GXColor1x8(idx);
                        } else {
                            switch (desc->comp_type) {
                            case GX_RGB565:
                            case GX_RGBA4:
                                GXColor1u16((idx << 8) | dl[m++]);
                                break;
                            case GX_RGB8:
                            case GX_RGBA6:
                                GXColor3u8(idx, dl[m], dl[m + 1]);
                                m += 2;
                                break;
                            case GX_RGBA8:
                            case GX_RGBX8:
                                GXColor4u8(idx, dl[m], dl[m + 1], dl[m + 2]);
                                m += 3;
                                break;
                            }
                        }
                        break;
                    default:
                        if (desc->attr_type == GX_INDEX16) {
                            idx = (idx << 8) | dl[m++];
                        }
                        OSReport(PObjUnsupportedAttr, desc->attr);
                        break;
                    }
                }
            }
        }
        GXEnd();
        l += m;
        dl += m;
    }
}

void drawShapeAnim(HSD_PObj* pobj)
{
    HSD_ShapeSet* shape_set = pobj->u.shape_set;
    f32 blend;
    s32 shape_id, i;
    s32 blend_nbt;

    if (vertex_buffer_size == 0) {
        vertex_buffer_size = HSD_DEFAULT_MAX_SHAPE_VERTICES;
        vertex_buffer = HSD_Alloc(vertex_buffer_size * sizeof(f32[3]));
    }
    ASSERT_POBJ(0x56E, vertex_buffer_size >= shape_set->nb_vertex_index);
    if (shape_set->normal_desc && normal_buffer_size == 0) {
        normal_buffer_size = HSD_DEFAULT_MAX_SHAPE_NORMALS;
        normal_buffer = HSD_Alloc(normal_buffer_size * sizeof(f32[3]));
    }

    if (shape_set->normal_desc) {
        if (shape_set->normal_desc->attr == GX_VA_NRM) {
            ASSERT_POBJ(0x577, normal_buffer_size >= shape_set->nb_normal_index);
            blend_nbt = 0;
        } else {
            ASSERT_POBJ(0x57A, normal_buffer_size >= shape_set->nb_normal_index * 3);
            blend_nbt = 1;
        }
    }

    if (shape_set->flags & SHAPESET_AVERAGE) {
        s32 blend_int;

        blend = shape_set->blend.bl;
        blend_int = (s32) blend;
        shape_id = pobj_min((blend_int < 0 ? 0 : blend_int), shape_set->nb_shape - 1);
        blend = pobj_min(MAX(0.0, blend - (f32) shape_id), 1.0f);
        for (i = 0; i < shape_set->nb_vertex_index; i++) {
            f32 s0[3], s1[3];

            get_shape_vertex_xyz(shape_set, shape_id, i, s0);
            get_shape_vertex_xyz(shape_set, pobj_min(shape_id + 1, shape_set->nb_shape - 1), i, s1);
            vertex_buffer[i][0] = __fmadds(blend, s1[0] - s0[0], s0[0]);
            vertex_buffer[i][1] = __fmadds(blend, s1[1] - s0[1], s0[1]);
            vertex_buffer[i][2] = __fmadds(blend, s1[2] - s0[2], s0[2]);
        }
        if (shape_set->nb_normal_index) {
            if (blend_nbt) {
                for (i = 0; i < shape_set->nb_normal_index; i++) {
                    f32 s0[9], s1[9];
                    s32 j, idx = i * 3;

                    get_shape_nbt_xyz(shape_set, shape_id, i, s0);
                    get_shape_nbt_xyz(shape_set, pobj_min(shape_id + 1, shape_set->nb_shape - 1), i, s1);
                    for (j = 0; j < 9; j++) {
                        normal_buffer[idx][j] = __fmadds(blend, s1[j] - s0[j], s0[j]);
                    }
                }
            } else {
                for (i = 0; i < shape_set->nb_normal_index; i++) {
                    f32 s0[3], s1[3];

                    get_shape_normal_xyz(shape_set, shape_id, i, s0);
                    get_shape_normal_xyz(shape_set, pobj_min(shape_id + 1, shape_set->nb_shape - 1), i, s1);
                    normal_buffer[i][0] = __fmadds(blend, s1[0] - s0[0], s0[0]);
                    normal_buffer[i][1] = __fmadds(blend, s1[1] - s0[1], s0[1]);
                    normal_buffer[i][2] = __fmadds(blend, s1[2] - s0[2], s0[2]);
                }
            }
        }
    } else {
        s32 j;
        f32* blend_bp = shape_set->blend.bp;
        for (i = 0; i < shape_set->nb_vertex_index; i++) {
            get_shape_vertex_xyz(shape_set, 0, i, vertex_buffer[i]);
            for (j = 0; j < shape_set->nb_shape; j++) {
                f32 b = MAX(0.0, blend_bp[j]);
                f32 s[3];

                get_shape_vertex_xyz(shape_set, j + 1, i, s);
                vertex_buffer[i][0] = __fmadds(s[0], b, vertex_buffer[i][0]);
                vertex_buffer[i][1] = __fmadds(s[1], b, vertex_buffer[i][1]);
                vertex_buffer[i][2] = __fmadds(s[2], b, vertex_buffer[i][2]);
            }
        }
        if (shape_set->nb_normal_index) {
            if (blend_nbt) {
                for (i = 0; i < shape_set->nb_normal_index; i++) {
                    s32 idx = i * 3;
                    get_shape_nbt_xyz(shape_set, 0, i, normal_buffer[idx]);
                    for (j = 0; j < shape_set->nb_shape; j++) {
                        f32 b = MAX(0.0, blend_bp[j]);
                        f32 s[9];

                        get_shape_nbt_xyz(shape_set, j + 1, i, s);
                        normal_buffer[idx][0] = __fmadds(s[0], b, normal_buffer[idx][0]);
                        normal_buffer[idx][1] = __fmadds(s[1], b, normal_buffer[idx][1]);
                        normal_buffer[idx][2] = __fmadds(s[2], b, normal_buffer[idx][2]);
                        normal_buffer[idx][3] = __fmadds(s[3], b, normal_buffer[idx][3]);
                        normal_buffer[idx][4] = __fmadds(s[4], b, normal_buffer[idx][4]);
                        normal_buffer[idx][5] = __fmadds(s[5], b, normal_buffer[idx][5]);
                        normal_buffer[idx][6] = __fmadds(s[6], b, normal_buffer[idx][6]);
                        normal_buffer[idx][7] = __fmadds(s[7], b, normal_buffer[idx][7]);
                        normal_buffer[idx][8] = __fmadds(s[8], b, normal_buffer[idx][8]);
                    }
                }
            } else {
                for (i = 0; i < shape_set->nb_normal_index; i++) {
                    get_shape_normal_xyz(shape_set, 0, i, normal_buffer[i]);
                    for (j = 0; j < shape_set->nb_shape; j++) {
                        f32 b = MAX(0.0, blend_bp[j]);
                        f32 s[3];

                        get_shape_normal_xyz(shape_set, j + 1, i, s);
                        normal_buffer[i][0] = __fmadds(s[0], b, normal_buffer[i][0]);
                        normal_buffer[i][1] = __fmadds(s[1], b, normal_buffer[i][1]);
                        normal_buffer[i][2] = __fmadds(s[2], b, normal_buffer[i][2]);
                    }
                }
            }
        }
    }
    interpretShapeAnimDisplayList(pobj, vertex_buffer, normal_buffer);
}

void HSD_PObjClearMtxMark(void* obj, u32 mark)
{
    s32 i;

    for (i = 0; i < 2; i++) {
        PObjMtxMark[i].obj = obj;
        PObjMtxMark[i].mark = mark;
    }
}

static inline PObjSetupFlag GetSetupFlags(HSD_JObj* jobj)
{
    PObjSetupFlag flags = SETUP_NONE;

    if (jobj->flags & LIGHTING) {
        flags |= SETUP_NORMAL;
    }
    if (_HSD_TObjGetCurrentByType(NULL, TEX_COORD_REFLECTION)) {
        flags |= SETUP_NORMAL | SETUP_REFLECTION;
    }
    if (_HSD_TObjGetCurrentByType(NULL, TEX_COORD_HILIGHT)) {
        flags |= SETUP_NORMAL | SETUP_HIGHLIGHT;
    }
    return flags;
}

static inline void SetupRigidModelMtx(HSD_PObj* pobj, Mtx vmtx, Mtx pmtx, u32 rendermode)
{
    HSD_JObj* jobj = HSD_JObjGetCurrent();
    void* mtx_obj = PObjMtxMark[0].obj;
    u32 mtx_mark = PObjMtxMark[0].mark;

    if (mtx_obj != jobj || mtx_mark != HSD_MTX_RIGID) {
        PObjSetupFlag flags;
        Mtx n;

        GXSetCurrentMtx(GX_PNMTX0);
        GXLoadPosMtxImm(pmtx, GX_PNMTX0);
        HSD_PerfCurrentStat.unkC++;

        flags = GetSetupFlags(jobj);
        if (flags & SETUP_NORMAL) {
            if (!kar_grcoll__803d1670(pmtx, n)) {
                PSMTXCopy(pmtx, n);
            }
            if (jobj->flags & LIGHTING) {
                GXLoadNrmMtxImm(n, GX_PNMTX0);
                HSD_PerfCurrentStat.unkC++;
            }
            if (flags & SETUP_NORMAL_PROJECTION) {
                GXLoadTexMtxImm(n, GX_TEXMTX0, GX_MTX3x4);
                HSD_PerfCurrentStat.unkC++;
            }
        }
    }
}

void SetupSharedVtxModelMtx(HSD_PObj* pobj, Mtx vmtx, Mtx pmtx, u32 rendermode)
{
    HSD_JObj* jobj;
    Mtx n0, n1, m;
    PObjSetupFlag flags = SETUP_NONE;

    jobj = HSD_JObjGetCurrent();
    {
        void* mtx0_obj = PObjMtxMark[0].obj;
        u32 mtx0_mark = PObjMtxMark[0].mark;
        if (mtx0_obj != jobj || mtx0_mark != HSD_MTX_RIGID) {
            flags |= SETUP_JOINT0;
        }
    }
    {
        void* mtx1_obj = PObjMtxMark[1].obj;
        u32 mtx1_mark = PObjMtxMark[1].mark;
        if (mtx1_obj != pobj->u.jobj || mtx1_mark != HSD_MTX_RIGID) {
            flags |= SETUP_JOINT1;
        }
    }

    if (flags == SETUP_NONE) {
        return;
    }

    flags |= GetSetupFlags(jobj);

    if (flags & SETUP_JOINT0) {
        GXSetCurrentMtx(GX_PNMTX0);
        GXLoadPosMtxImm(pmtx, GX_PNMTX0);
        HSD_PerfCurrentStat.unkC++;

        if (flags & SETUP_NORMAL) {
            if (!kar_grcoll__803d1670(pmtx, n0)) {
                PSMTXCopy(pmtx, n0);
            }
            if (jobj->flags & LIGHTING) {
                GXLoadNrmMtxImm(n0, GX_PNMTX0);
                HSD_PerfCurrentStat.unkC++;
            }
            if (flags & SETUP_NORMAL_PROJECTION) {
                GXLoadTexMtxImm(n0, GX_TEXMTX0, GX_MTX3x4);
                HSD_PerfCurrentStat.unkC++;
            }
        }
    }
    if (flags & SETUP_JOINT1) {
        HSD_JObjSetupMatrix(pobj->u.jobj);
        PSMTXConcat(vmtx, pobj->u.jobj->mtx, m);
        GXLoadPosMtxImm(m, GX_PNMTX1);
        HSD_PerfCurrentStat.unkC++;

        if (flags & SETUP_NORMAL) {
            if (!kar_grcoll__803d1670(m, n1)) {
                PSMTXCopy(m, n1);
            }
            if (jobj->flags & LIGHTING) {
                GXLoadNrmMtxImm(n1, GX_PNMTX1);
                HSD_PerfCurrentStat.unkC++;
            }
            if (flags & SETUP_NORMAL_PROJECTION) {
                GXLoadTexMtxImm(n1, GX_TEXMTX1, GX_MTX3x4);
                HSD_PerfCurrentStat.unkC++;
            }
        }
    }
}

void SetupEnvelopeModelMtx(HSD_PObj* pobj, Mtx vmtx, Mtx pmtx, u32 rendermode)
{
    HSD_JObj* jobj;
    HSD_SList* list;
    s32 MtxIdx;
    MtxPtr right;
    Mtx mtx;
    PObjSetupFlag flags;

    jobj = HSD_JObjGetCurrent();
    HSD_PObjClearMtxMark(NULL, HSD_MTX_ENVELOPE);
    flags = GetSetupFlags(jobj);
    right = _HSD_mkEnvelopeModelNodeMtx(jobj, mtx);

    for (MtxIdx = 0, list = pobj->u.envelope_list; MtxIdx < 10 && list != NULL;
         MtxIdx++, list = list->next) {
        Mtx tmp2, tmp;
        MtxPtr mtxp;
        HSD_Envelope* envelope = list->data;
        s32 mtx_no = HSD_Index2PosNrmMtx[MtxIdx];
        s32 perf = 0;

        ASSERT_POBJ(0x71C, envelope);
        if (envelope->weight >= 1.0f) {
            HSD_JObjSetupMatrix(envelope->jobj);
            if (right) {
                PSMTXConcat(envelope->jobj->mtx, envelope->jobj->envelopemtx, tmp2);
                mtxp = tmp2;
            } else {
                mtxp = envelope->jobj->mtx;
            }
        } else {
            tmp2[0][0] = tmp2[0][1] = tmp2[0][2] = tmp2[0][3] = tmp2[1][0] = tmp2[1][1] =
                tmp2[1][2] = tmp2[1][3] = tmp2[2][0] = tmp2[2][1] = tmp2[2][2] = tmp2[2][3] = 0.0f;
            while (envelope != NULL) {
                HSD_JObj* jp;

                ASSERT_POBJ(0x730, envelope->jobj);
                jp = envelope->jobj;
                HSD_JObjSetupMatrix(jp);
                ASSERT_POBJ_MSG(0x733, jp->mtx, JObjAssertMtx);
                ASSERT_POBJ(0x734, jp->envelopemtx);

                PSMTXConcat(jp->mtx, jp->envelopemtx, tmp);
                HSD_MtxScaledAdd(tmp, tmp2, tmp2, envelope->weight);
                perf++;
                envelope = envelope->next;
            }
            mtxp = tmp2;
        }
        HSD_PerfCountEnvelopeBlending(perf);
        if (right) {
            PSMTXConcat(mtxp, right, tmp2);
            mtxp = tmp2;
        }
        PSMTXConcat(vmtx, mtxp, tmp);
        GXLoadPosMtxImm(tmp, mtx_no);
        HSD_PerfCurrentStat.unkC++;

        if (flags & SETUP_NORMAL) {
            if (!kar_grcoll__803d1670(tmp, tmp2)) {
                PSMTXCopy(tmp, tmp2);
            }
            if (jobj->flags & LIGHTING) {
                GXLoadNrmMtxImm(tmp2, mtx_no);
                HSD_PerfCurrentStat.unkC++;
            }
            if (flags & SETUP_NORMAL_PROJECTION) {
                GXLoadTexMtxImm(tmp2, HSD_Index2TexMtx(MtxIdx), GX_MTX3x4);
                HSD_PerfCurrentStat.unkC++;
            }
        }
    }
}

void PObjSetupMtx(HSD_PObj* pobj, Mtx vmtx, Mtx pmtx, u32 rendermode)
{
    switch (pobj_type(pobj)) {
    case POBJ_SKIN:
        if (!pobj->u.jobj) {
            SetupRigidModelMtx(pobj, vmtx, pmtx, rendermode);
        } else {
            SetupSharedVtxModelMtx(pobj, vmtx, pmtx, rendermode);
        }
        break;
    case POBJ_SHAPEANIM:
        SetupRigidModelMtx(pobj, vmtx, pmtx, rendermode);
        break;
    case POBJ_ENVELOPE:
        SetupEnvelopeModelMtx(pobj, vmtx, pmtx, rendermode);
        break;
    }
}

char PObjAssertShapeSet[] = "pobj->u.shape_set";

void HSD_PObjDisp(HSD_PObj* pobj, Mtx vmtx, Mtx pmtx, u32 rendermode)
{
    if (pobj->flags & POBJ_HIDE) {
        return;
    }

    switch (pobj->flags & (POBJ_CULLFRONT | POBJ_CULLBACK)) {
    case 0x0:
        HSD_StateSetCullMode(GX_CULL_NONE);
        break;
    case POBJ_CULLFRONT:
        HSD_StateSetCullMode(GX_CULL_FRONT);
        break;
    case POBJ_CULLBACK:
        HSD_StateSetCullMode(GX_CULL_BACK);
        break;
    case POBJ_CULLFRONT | POBJ_CULLBACK:
        return;
    }

    HSD_POBJ_METHOD(pobj)->setup_mtx(pobj, vmtx, pmtx, rendermode);

    if (pobj_type(pobj) == POBJ_SHAPEANIM) {
        HSD_VtxDescList* desc;

        for (desc = pobj->verts; desc->attr != GX_VA_NULL; desc++) {
            if (desc->attr_type != GX_DIRECT) {
                switch (desc->attr) {
                case GX_VA_POS:
                case GX_VA_NRM:
                case GX_VA_NBT:
                    break;
                default:
                    GXSetArray(desc->attr, desc->vertex, desc->stride);
                }
            }
        }
        PObjPrevVtxDescListArray = 0;
        GXClearVtxDesc();
        for (desc = pobj->verts; desc->attr != GX_VA_NULL; desc++) {
            switch (desc->attr) {
            case GX_VA_NRM:
            case GX_VA_POS:
            case GX_VA_NBT:
                GXSetVtxDesc(desc->attr, GX_DIRECT);
                GXSetVtxAttrFmt(GX_VTXFMT0, desc->attr, desc->comp_cnt, GX_F32, 0);
                break;

            case GX_VA_PNMTXIDX:
            case GX_VA_TEX0MTXIDX:
            case GX_VA_TEX1MTXIDX:
            case GX_VA_TEX2MTXIDX:
            case GX_VA_TEX3MTXIDX:
            case GX_VA_TEX4MTXIDX:
            case GX_VA_TEX5MTXIDX:
            case GX_VA_TEX6MTXIDX:
            case GX_VA_TEX7MTXIDX:
                GXSetVtxDesc(desc->attr, desc->attr_type);
                break;

            default:
                GXSetVtxDesc(desc->attr, desc->attr_type);
                GXSetVtxAttrFmt(GX_VTXFMT0, desc->attr, desc->comp_cnt, desc->comp_type,
                                desc->frac);
            }
        }
        PObjPrevVtxDesc = 0;

        ASSERT_POBJ_MSG(0x77D, pobj->u.shape_set, PObjAssertShapeSet);
        drawShapeAnim(pobj);
    } else {
        HSD_VtxDescList* desc;

        if (PObjPrevVtxDescListArray != pobj->verts) {
            for (desc = pobj->verts; desc->attr != GX_VA_NULL; desc++) {
                if (desc->attr_type != GX_DIRECT) {
                    GXSetArray(desc->attr, desc->vertex, desc->stride);
                }
            }
            PObjPrevVtxDescListArray = pobj->verts;
        }

        if (PObjPrevVtxDesc != pobj->verts) {
            GXClearVtxDesc();
            for (desc = pobj->verts; desc->attr != GX_VA_NULL; desc++) {
                GXSetVtxDesc(desc->attr, desc->attr_type);
                switch (desc->attr) {
                case GX_VA_PNMTXIDX:
                case GX_VA_TEX0MTXIDX:
                case GX_VA_TEX1MTXIDX:
                case GX_VA_TEX2MTXIDX:
                case GX_VA_TEX3MTXIDX:
                case GX_VA_TEX4MTXIDX:
                case GX_VA_TEX5MTXIDX:
                case GX_VA_TEX6MTXIDX:
                case GX_VA_TEX7MTXIDX:
                    break;
                default:
                    GXSetVtxAttrFmt(GX_VTXFMT0, desc->attr, desc->comp_cnt, desc->comp_type,
                                    desc->frac);
                }
            }
            PObjPrevVtxDesc = pobj->verts;
        }

        GXCallDisplayList(pobj->display, pobj->n_display << 5);
    }
}

void PObjRelease(HSD_Class* o)
{
    HSD_PObj* pobj = HSD_POBJ(o);

    if (pobj->aobj != NULL) {
        HSD_AObjRemove(pobj->aobj);
    }

    switch (pobj_type(pobj)) {
    case POBJ_SHAPEANIM: {
        HSD_ShapeSet* shape_set = pobj->u.shape_set;
        if (shape_set != NULL) {
            if (shape_set->flags & SHAPESET_ADDITIVE) {
                HSD_Free(shape_set->blend.bp);
            }
            if (shape_set != NULL) {
                hsdFreeMemPiece(shape_set, sizeof(HSD_ShapeSet));
            }
        }
        break;
    }
    case POBJ_ENVELOPE: {
        HSD_SList* list;
        for (list = pobj->u.envelope_list; list != NULL; list = HSD_SListRemove(list)) {
            HSD_Envelope* env = list->data;
            while (env != NULL) {
                HSD_Envelope* next = env->next;
                HSD_JObjUnrefThis(env->jobj);
                if (env != NULL) {
                    hsdFreeMemPiece(env, sizeof(HSD_Envelope));
                }
                env = next;
            }
        }
        break;
    }
    case POBJ_SKIN:
        HSD_JObjUnrefThis(pobj->u.jobj);
        break;
    default:
        break;
    }
    HSD_PARENT_INFO(&hsdPObj)->release(o);
}

void PObjAmnesia(HSD_ClassInfo* info)
{
    if (info == (HSD_ClassInfo*) PObjCurrentInfo) {
        PObjCurrentInfo = NULL;
    }
    if (info == HSD_CLASS_INFO(&hsdPObj)) {
        if (_HSD_MemCheckOwn(vertex_buffer)) {
            vertex_buffer = NULL;
            vertex_buffer_size = 0;
        }
        if (_HSD_MemCheckOwn(normal_buffer)) {
            normal_buffer = NULL;
            normal_buffer_size = 0;
        }
        PObjPrevVtxDescListArray = NULL;
        PObjPrevVtxDesc = NULL;
    }
    HSD_PARENT_INFO(&hsdPObj)->amnesia(info);
}

void PObjInfoInit(void)
{
    hsdInitClassInfo(HSD_CLASS_INFO(&hsdPObj), HSD_CLASS_INFO(&hsdClass),
                     "sysdolphin_base_library", "hsd_pobj", sizeof(HSD_PObjInfo),
                     sizeof(HSD_PObj));
    HSD_CLASS_INFO(&hsdPObj)->release = PObjRelease;
    HSD_CLASS_INFO(&hsdPObj)->amnesia = PObjAmnesia;
    HSD_POBJ_INFO(&hsdPObj)->disp = HSD_PObjDisp;
    HSD_POBJ_INFO(&hsdPObj)->setup_mtx = PObjSetupMtx;
    HSD_POBJ_INFO(&hsdPObj)->load = PObjLoad;
    HSD_POBJ_INFO(&hsdPObj)->update = PObjUpdateFunc;
}
