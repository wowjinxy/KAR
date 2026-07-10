#include <sysdolphin/robj.h>
#include <sysdolphin/id.h>
#include <sysdolphin/util.h>
#include <sysdolphin/mtx.h>

extern HSD_ObjAllocData hsdRObj_alloc_data;
extern HSD_ObjAllocData lbl_8058BC3C;

extern char kar_srcfile_robj_c_805dcc58[7]; // "robj.c"
extern char kar_srcfile_jobj_h_805dcc60[7]; // "jobj.h"
extern char lbl_805DCC68[5];                // "jobj"
extern char lbl_805DCC70[4];                // "obj"
extern char lbl_805DCC74[4];                // "new"
extern char lbl_805DCC7C[7];                // "rvalue"
extern char lbl_805DCC84[2];                // "0"
extern char lbl_80504060[11];               // "rp->u.jobj"

#define assert_line_named(line, cond, condstr)                                \
    ((cond) ? ((void) 0) : __assert(kar_srcfile_robj_c_805dcc58, line, condstr))
#define assert_line_jobjh(line, cond)                                         \
    ((cond) ? ((void) 0) : __assert(kar_srcfile_jobj_h_805dcc60, line, lbl_805DCC68))

extern void memset(void*, int, int);
extern void HSD_Panic(const char* file, s32 line, const char* msg);
extern BOOL hsdObjIsDescendantOf(HSD_Class* cls, HSD_ClassInfo* class_info);

extern void PSMTXCopy(Mtx src, Mtx dst);
extern void PSVECSubtract(Vec* a, Vec* b, Vec* dst);
extern f32 PSVECMag(Vec* vec);
extern f32 PSVECDotProduct(Vec* a, Vec* b);
extern void PSVECCrossProduct(Vec* a, Vec* b, Vec* dst);
extern void PSVECScale(f32 scale, Vec* src, Vec* dst);
extern void HSD_MtxGetRotation(Mtx mtx, Vec* out);
extern void HSD_MtxGetScale(Mtx mtx, Vec* out);
extern void HSD_JObjMakeMatrix(HSD_JObj* jobj);

static inline void robj_JObjSetupMatrix(HSD_JObj* jobj)
{
    BOOL dirty;

    if (jobj == NULL) {
        return;
    }
    assert_line_jobjh(0x25d, jobj);
    dirty = FALSE;
    if (!(jobj->flags & 0x800000) && (jobj->flags & 0x40)) {
        dirty = TRUE;
    }
    if (dirty) {
        HSD_JObjSetupMatrixSub(jobj);
    }
}

void expEvaluate(HSD_Exp* exp, u32 type, void* obj, HSD_ObjUpdateFunc update_func);
void HSD_RvalueRemoveAll(HSD_Rvalue* rvalue);
void HSD_RvalueResolveRefsAll(HSD_Rvalue* rvalue, HSD_RvalueList* list);
void HSD_RObjFree(HSD_RObj* robj);

extern f64 __frsqrte(f64 x);
extern f64 __fnmsub(f64 a, f64 c, f64 b);

extern f64 lbl_805E5CB8;  // 0.5
extern f32 lbl_805E5CC0;  // 1.0f
extern f32 lbl_805E5CD0;  // 1.00000001335e-10f
extern f32 lbl_805E5CD4;  // 0.0f
extern f64 lbl_805E5CD8;  // 3.0
extern f64 lbl_805E5CE0;  // 1.00000001335e-10
extern f32 lbl_805E5CE8;  // 0.017453292f
extern f32 lbl_805E5CEC;  // 57.29578f
extern Vec lbl_8048C548[3]; // {0,0,0}, {1,1,1}, {0,1,0}

static inline f32 robj_sqrtf(f32 x)
{
    volatile f32 y;

    if (x > lbl_805E5CD4) {
        f64 guess = __frsqrte((f64) x);
        guess = lbl_805E5CB8 * guess * __fnmsub(x, guess * guess, lbl_805E5CD8);
        guess = lbl_805E5CB8 * guess * __fnmsub(x, guess * guess, lbl_805E5CD8);
        guess = lbl_805E5CB8 * guess * __fnmsub(x, guess * guess, lbl_805E5CD8);
        y = (f32) (x * guess);
        return y;
    }
    return x;
}

void HSD_RObjInitAllocData(void)
{
    HSD_ObjAllocInit(&hsdRObj_alloc_data, sizeof(HSD_RObj), 4);
    HSD_ObjAllocInit(&lbl_8058BC3C, sizeof(HSD_Rvalue), 4);
}

HSD_ObjAllocData* fn_804183D0(void)
{
    return &hsdRObj_alloc_data;
}

HSD_ObjAllocData* fn_804183DC(void)
{
    return &lbl_8058BC3C;
}

void HSD_RObjSetFlags(HSD_RObj* robj, u32 flags)
{
    if (robj != NULL) {
        robj->flags |= flags;
    }
}

HSD_RObj* HSD_RObjGetByType(HSD_RObj* robj, u32 type, u32 subtype)
{
    BOOL has_type;
    HSD_RObj* curr;

    if (robj == NULL) {
        return NULL;
    }

    for (curr = robj; curr != NULL; curr = curr->next) {
        if (curr->flags & 0x80000000) {
            has_type = TRUE;
        } else {
            has_type = FALSE;
        }

        if (has_type) {
            if ((curr->flags & TYPE_MASK) == type &&
                (!subtype || subtype == (curr->flags & 0xFFFFFFF)))
            {
                return curr;
            }
        }
    }

    return NULL;
}

void fn_80418458(void* obj, s32 type, FObjData* val)
{
    HSD_RObj* robj;

    if (obj == NULL) {
        return;
    }

    if (type != TYPE_ROBJ) {
        return;
    }

    robj = (HSD_RObj*) obj;
    if (val->fv >= lbl_805E5CB8) {
        robj->flags = robj->flags | 0x80000000;
        return;
    }
    robj->flags = robj->flags & 0x7fffffff;
}

static inline void HSD_RObjAnim(HSD_RObj* robj)
{
    if (robj == NULL) {
        return;
    }

    HSD_AObjInterpretAnim(robj->aobj, robj, fn_80418458);
}

void HSD_RObjAnimAll(HSD_RObj* robj)
{
    HSD_RObj* curr;

    if (robj == NULL) {
        return;
    }

    for (curr = robj; curr != NULL; curr = curr->next) {
        HSD_RObjAnim(curr);
    }
}

static inline void HSD_RObjRemoveAnimByFlags(HSD_RObj* robj, u32 flags)
{
    if (robj == NULL) {
        return;
    }

    if (robj->aobj != NULL && (flags & 0x80) != 0) {
        HSD_AObjRemove(robj->aobj);
        robj->aobj = NULL;
    }
}

void HSD_RObjRemoveAnimAllByFlags(HSD_RObj* robj, u32 flags)
{
    if (robj == NULL) {
        return;
    }

    for (; robj != NULL; robj = robj->next) {
        HSD_RObjRemoveAnimByFlags(robj, flags);
    }
}

static inline void HSD_RObjReqAnimByFlags(HSD_RObj* robj, f32 startframe, u32 flags)
{
    if (robj == NULL) {
        return;
    }

    if (robj->aobj != NULL && (flags & 0x80) != 0) {
        HSD_AObjReqAnim(robj->aobj, startframe);
    }
}

void HSD_RObjReqAnimAllByFlags(HSD_RObj* robj, f32 startframe, u32 flags)
{
    if (robj == NULL) {
        return;
    }

    for (; robj != NULL; robj = robj->next) {
        HSD_RObjReqAnimByFlags(robj, startframe, flags);
    }
}

void HSD_RObjReqAnimAll(HSD_RObj* robj, f32 startframe)
{
    HSD_RObjReqAnimAllByFlags(robj, startframe, 0x7FF);
}

static inline void HSD_RObjAddAnim(HSD_RObj* robj, HSD_RObjAnimJoint* anim)
{
    if (robj == NULL || anim == NULL) {
        return;
    }

    if (robj->aobj != NULL) {
        HSD_AObjRemove(robj->aobj);
    }
    robj->aobj = HSD_AObjLoadDesc(anim->aobjdesc);
}

void HSD_RObjAddAnimAll(HSD_RObj* robj, HSD_RObjAnimJoint* anim)
{
    HSD_RObj* i;
    HSD_RObjAnimJoint* j;

    if (robj == NULL || anim == NULL) {
        return;
    }

    for (i = robj, j = anim; i != NULL && j != NULL; i = i->next, j = j->next) {
        HSD_RObjAddAnim(i, j);
    }
}

static inline u32 HSD_RObjGetConstraintType(HSD_RObj* robj)
{
    if (robj == NULL) {
        return 0;
    }
    return robj->flags & 0xFFFFFFF;
}

int HSD_RObjGetGlobalPosition(HSD_RObj* robj, int type, Vec* p)
{
    Vec v = lbl_8048C548[0];
    HSD_RObj* rp;
    int n = 0;

    if (robj == NULL) {
        return 0;
    }
    for (rp = robj; rp != NULL; rp = rp->next) {
        if ((rp->flags & TYPE_MASK) == REFTYPE_JOBJ) {
            if ((rp->flags & 0x80000000) != 0 &&
                (u32) type == HSD_RObjGetConstraintType(rp))
            {
                assert_line_named(0x1F2, rp->u.jobj, lbl_80504060);
                robj_JObjSetupMatrix(rp->u.jobj);
                n += 1;
                v.x += rp->u.jobj->mtx[0][3];
                v.y += rp->u.jobj->mtx[1][3];
                v.z += rp->u.jobj->mtx[2][3];
            }
        }
    }
    if (n != 0) {
        f32 f = lbl_805E5CC0 / (f32) n;
        p->x = f * v.x;
        p->y = f * v.y;
        p->z = f * v.z;
    }
    return n;
}

static inline void set_dirup_matrix(Vec* dir_ptr, Vec* uv_ptr, Vec* scale_ptr,
                                    void* obj, HSD_ObjUpdateFunc update_func)
{
    Vec z_vec;
    Vec v;
    f32 kz;
    f32 kdir;

    PSVECCrossProduct(dir_ptr, uv_ptr, &z_vec);
    kdir = robj_sqrtf(lbl_805E5CC0 / (lbl_805E5CD0 + PSVECDotProduct(dir_ptr, dir_ptr)));
    PSVECScale(kdir, dir_ptr, dir_ptr);
    kz = robj_sqrtf(lbl_805E5CC0 / (lbl_805E5CD0 + PSVECDotProduct(&z_vec, &z_vec)));
    PSVECScale(kz, &z_vec, &z_vec);
    PSVECCrossProduct(&z_vec, dir_ptr, uv_ptr);
    v.x = dir_ptr->x * scale_ptr->x;
    v.y = dir_ptr->y * scale_ptr->x;
    v.z = dir_ptr->z * scale_ptr->x;
    update_func(obj, 0x32, (HSD_ObjData*) &v);
    v.x = uv_ptr->x * scale_ptr->y;
    v.y = uv_ptr->y * scale_ptr->y;
    v.z = uv_ptr->z * scale_ptr->y;
    update_func(obj, 0x33, (HSD_ObjData*) &v);
    v.x = z_vec.x * scale_ptr->z;
    v.y = z_vec.y * scale_ptr->z;
    v.z = z_vec.z * scale_ptr->z;
    update_func(obj, 0x34, (HSD_ObjData*) &v);
    update_func(obj, 0x37, NULL);
}

void resolveCnsDirUp(HSD_RObj* robj, void* obj, HSD_ObjUpdateFunc update_func)
{
    Vec this_scale = lbl_8048C548[1];
    Vec up = lbl_8048C548[2];
    Vec this_pos = lbl_8048C548[0];
    Vec dir;
    f32 k;

    if (HSD_RObjGetGlobalPosition(robj, 2, &this_pos) != 0) {
        dir.x = ((HSD_JObj*) obj)->mtx[0][3];
        dir.y = ((HSD_JObj*) obj)->mtx[1][3];
        dir.z = ((HSD_JObj*) obj)->mtx[2][3];
        PSVECSubtract(&this_pos, &dir, &this_pos);
        if (HSD_RObjGetGlobalPosition(robj, 3, &up) != 0) {
            PSVECSubtract(&up, &dir, &up);
        } else {
            k = lbl_805E5CC0 - PSVECDotProduct(&this_pos, &up);
            if (fabsf_bitwise(k) < lbl_805E5CE0) {
                up.x = lbl_805E5CD4;
                up.y = lbl_805E5CD4;
                up.z = lbl_805E5CC0;
            }
        }

        if (((HSD_JObj*) obj)->scl != NULL) {
            this_scale = *((HSD_JObj*) obj)->scl;
        }
        set_dirup_matrix(&this_pos, &up, &this_scale, obj, update_func);
    }
}

static inline HSD_RObj* inlined_HSD_RObjGetByType(HSD_RObj* robj, u32 type,
                                                  u32 subtype)
{
    BOOL has_type;
    HSD_RObj* curr;

    if (robj == NULL) {
        return NULL;
    }

    for (curr = robj; curr != NULL; curr = curr->next) {
        if (curr->flags & 0x80000000) {
            has_type = TRUE;
        } else {
            has_type = FALSE;
        }

        if (has_type) {
            if ((curr->flags & TYPE_MASK) == type &&
                (!subtype || subtype == (curr->flags & 0xFFFFFFF)))
            {
                return curr;
            }
        }
    }

    return NULL;
}

static inline f32 HSD_MtxColMagFloat(MtxPtr mtx, int col)
{
    return robj_sqrtf((mtx[0][col] * mtx[0][col]) + (mtx[1][col] * mtx[1][col]) +
                (mtx[2][col] * mtx[2][col]));
}

static inline void HSD_MtxColVec(MtxPtr mtx, int col, Vec* vec)
{
    vec->x = mtx[0][col];
    vec->y = mtx[1][col];
    vec->z = mtx[2][col];
}

extern s32 lbl_8050406C[3]; // {0x32, 0x33, 0x34}

static inline void resolveCnsOrientation(HSD_RObj* robj, void* obj,
                                         HSD_ObjUpdateFunc update_func)
{
    Mtx mtx0;
    f32 sval;
    Vec v;
    HSD_JObj* jobj;
    HSD_RObj* found;
    int i;

    assert_line_named(0x276, obj, lbl_805DCC70);

    found = inlined_HSD_RObjGetByType(robj, REFTYPE_JOBJ, 4);
    if (found == NULL) {
        return;
    }

    assert_line_jobjh(0x47c, found->u.jobj);
    robj_JObjSetupMatrix(found->u.jobj);
    PSMTXCopy(found->u.jobj->mtx, mtx0);
    jobj = obj;

    for (i = 0; i < 3; i++) {
        HSD_MtxColVec(mtx0, i, &v);
        sval = PSVECMag(&v);
        if (sval > lbl_805E5CD0) {
            sval = lbl_805E5CC0 / sval;
        }
        sval *= HSD_MtxColMagFloat(jobj->mtx, i);
        v.x *= sval;
        v.y *= sval;
        v.z *= sval;
        update_func(obj, lbl_8050406C[i], (HSD_ObjData*) &v);
    }
    update_func(obj, 0x37, NULL);
}

static inline BOOL RObjHasLimitReftype(HSD_RObj* robj)
{
    if ((robj->flags & TYPE_MASK) == REFTYPE_LIMIT) {
        return TRUE;
    }
    return FALSE;
}

void resolveLimits(HSD_RObj* robj, void* obj, HSD_ObjUpdateFunc update_func)
{
    HSD_JObj* jobj = (HSD_JObj*) obj;
    HSD_RObj* rp;
    BOOL update_mtx = FALSE;

    assert_line_named(0x29e, jobj, lbl_805DCC68);

    rp = robj;
    while (rp != NULL) {
        if (RObjHasLimitReftype(rp)) {
            break;
        }
        rp = rp->next;
    }

    if (rp != NULL) {
        for (rp = robj; rp != NULL; rp = rp->next) {
            if (RObjHasLimitReftype(rp)) {
                switch (rp->flags & 0xFFFFFFF) {
                default:
                    continue;
                case 1:
                    if (jobj->rotate.x < rp->u.limit) {
                        jobj->rotate.x = rp->u.limit;
                    }
                    break;

                case 2:
                    if (jobj->rotate.x > rp->u.limit) {
                        jobj->rotate.x = rp->u.limit;
                    }
                    break;

                case 3:
                    if (jobj->rotate.y < rp->u.limit) {
                        jobj->rotate.y = rp->u.limit;
                    }
                    break;

                case 4:
                    if (jobj->rotate.y > rp->u.limit) {
                        jobj->rotate.y = rp->u.limit;
                    }
                    break;

                case 5:
                    if (jobj->rotate.z < rp->u.limit) {
                        jobj->rotate.z = rp->u.limit;
                    }
                    break;

                case 6:
                    if (jobj->rotate.z > rp->u.limit) {
                        jobj->rotate.z = rp->u.limit;
                    }
                    break;

                case 7:
                    if (jobj->translate.x < rp->u.limit) {
                        jobj->translate.x = rp->u.limit;
                    }
                    break;

                case 8:
                    if (jobj->translate.x > rp->u.limit) {
                        jobj->translate.x = rp->u.limit;
                    }
                    break;

                case 9:
                    if (jobj->translate.y < rp->u.limit) {
                        jobj->translate.y = rp->u.limit;
                    }
                    break;

                case 10:
                    if (jobj->translate.y > rp->u.limit) {
                        jobj->translate.y = rp->u.limit;
                    }
                    break;

                case 11:
                    if (jobj->translate.y < rp->u.limit) {
                        jobj->translate.y = rp->u.limit;
                    }
                    break;

                case 12:
                    if (jobj->translate.y > rp->u.limit) {
                        jobj->translate.y = rp->u.limit;
                    }
                    break;
                }
                update_mtx = TRUE;
            }
        }
        if (update_mtx) {
            HSD_JObjMakeMatrix(jobj);
        }
    }
}

void HSD_RObjUpdateAll(HSD_RObj* robj, void* obj, HSD_ObjUpdateFunc update_func)
{
    HSD_RObj* rp;
    Vec vec;

    if (robj != NULL) {
        if (HSD_RObjGetGlobalPosition(robj, 1, &vec) != 0) {
            update_func(obj, 0x35, (HSD_ObjData*) &vec);
            update_func(obj, 0x38, NULL);
        }
        resolveCnsDirUp(robj, obj, update_func);
        resolveCnsOrientation(robj, obj, update_func);
        resolveLimits(robj, obj, update_func);

        for (rp = robj; rp != NULL; rp = rp->next) {
            if ((rp->flags & TYPE_MASK) == 0 && (rp->flags & 0x80000000) != 0) {
                expEvaluate(&rp->u.exp, rp->flags & 0xFFFFFFF, obj, update_func);
            }
        }
    }
}

static inline void HSD_RObjResolveRefs(HSD_RObj* robj, HSD_RObjDesc* desc)
{
    if (robj != NULL && desc != NULL) {
        switch (robj->flags & TYPE_MASK) {
        case REFTYPE_JOBJ:
            HSD_JObjUnrefThis(robj->u.jobj);
            robj->u.jobj = HSD_IDGetData((u32) desc->u.joint, NULL);
            assert_line_named(0x330, robj->u.jobj, lbl_805DCC74);
            if (robj->u.jobj != NULL) {
                iref_INC(robj->u.jobj);
            }
            break;
        case REFTYPE_EXP:
            HSD_RvalueResolveRefsAll(robj->u.exp.rvalue, desc->u.exp->rvalue);
            break;
        }
    }
}

void HSD_RObjResolveRefsAll(HSD_RObj* robj, HSD_RObjDesc* desc)
{
    for (; robj != NULL && desc != NULL; robj = robj->next, desc = desc->next) {
        HSD_RObjResolveRefs(robj, desc);
    }
}

void expLoadDesc(HSD_Exp* exp, HSD_ExpDesc* desc);
void bcexpLoadDesc(HSD_Exp* exp, HSD_ByteCodeExpDesc* desc);
HSD_RObj* HSD_RObjAlloc(void);

extern char lbl_805040F0[26]; // "unexpected type of robj.\n"

HSD_RObj* HSD_RObjLoadDesc(HSD_RObjDesc* robjdesc)
{
    HSD_RObj* robj;

    if (robjdesc != NULL) {
        robj = HSD_RObjAlloc();
        robj->next = HSD_RObjLoadDesc(robjdesc->next);
        robj->flags = robjdesc->flags;
        switch (robj->flags & TYPE_MASK) {
        case REFTYPE_JOBJ:
            break;
        case REFTYPE_LIMIT:
            switch (robj->flags & 0xFFFFFFF) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
                robj->u.limit = lbl_805E5CE8 * robjdesc->u.limit;
                break;
            default:
                robj->u.limit = robjdesc->u.limit;
                break;
            }
            break;
        case REFTYPE_EXP:
            expLoadDesc(&robj->u.exp, robjdesc->u.exp);
            break;
        case REFTYPE_BYTECODE:
            bcexpLoadDesc(&robj->u.exp, robjdesc->u.bcexp);
            robj->flags &= ~TYPE_MASK;
            break;
        case REFTYPE_IKHINT:
            robj->u.ik_hint.bone_length = robjdesc->u.ik_hint->bone_length;
            robj->u.ik_hint.rotate_x = robjdesc->u.ik_hint->rotate_x;
            break;
        default:
            HSD_Panic(kar_srcfile_robj_c_805dcc58, 0x37d, lbl_805040F0);
            break;
        }
        return robj;
    }
    return NULL;
}

#pragma push
#pragma force_active on
static char HSD_RObj_80406F14[] = "(ptr && nitems) || !ptr";
#pragma pop

void HSD_RObjRemove(HSD_RObj* robj)
{
    if (robj != NULL) {
        switch (robj->flags & TYPE_MASK) {
        case REFTYPE_JOBJ:
            HSD_JObjUnrefThis(robj->u.jobj);
            break;
        case REFTYPE_EXP:
            HSD_RvalueRemoveAll(robj->u.exp.rvalue);
            break;
        }
        HSD_AObjRemove(robj->aobj);
        HSD_RObjFree(robj);
    }
}

void HSD_RObjRemoveAll(HSD_RObj* robj)
{
    HSD_RObj* next;

    for (; robj != NULL; robj = next) {
        next = robj->next;
        HSD_RObjRemove(robj);
    }
}

HSD_RObj* HSD_RObjAlloc(void)
{
    HSD_RObj* new = HSD_ObjAlloc(&hsdRObj_alloc_data);
    assert_line_named(0x3c5, new, lbl_805DCC74);
    memset(new, 0, sizeof(HSD_RObj));
    return new;
}

void HSD_RObjFree(HSD_RObj* robj)
{
    HSD_ObjFree(&hsdRObj_alloc_data, robj);
}

extern f32* lbl_805DE2D8; // arg_buf
extern u32 lbl_805DE2DC;  // arg_buf_size

extern f32 HSD_ByteCodeEval(u8* bytecode, f32* argv, s32 nb_args);
extern void* HSD_Alloc(u32 size);
extern char lbl_805DCC78[4];   // ""
extern char lbl_80504124[164]; // OSReport format string

void expEvaluate(HSD_Exp* exp, u32 type, void* obj, HSD_ObjUpdateFunc update_func)
{
    HSD_Rvalue* rvalue;
    HSD_JObj* jobj;
    Vec scale;
    Vec sp2C;
    f32* cur_arg;
    int cur_bit;
    HSD_ObjData sp1C;

    if (exp->nb_args == -1) {
        u32 nb_args = 0;
        HSD_Rvalue* rvalue2;
        for (rvalue2 = exp->rvalue; rvalue2 != NULL; rvalue2 = rvalue2->next) {
            nb_args += HSD_GetNbBits(rvalue2->flags);
        }
        exp->nb_args = nb_args;
    }
    if (lbl_805DE2D8 == NULL) {
        if (lbl_805DE2DC == 0) {
            lbl_805DE2DC = 100;
        }
        lbl_805DE2D8 = HSD_Alloc(lbl_805DE2DC * sizeof(f32));
    }
    if (lbl_805DE2DC < exp->nb_args) {
        OSReport(lbl_80504124, exp->nb_args, lbl_805DE2DC);
        HSD_Panic(kar_srcfile_robj_c_805dcc58, 0x41b, lbl_805DCC78);
    }
    cur_arg = lbl_805DE2D8;
    for (rvalue = exp->rvalue; rvalue != NULL; rvalue = rvalue->next) {
        jobj = rvalue->jobj;
        assert_line_named(0x424, jobj, lbl_805DCC68);
        robj_JObjSetupMatrix(rvalue->jobj);
        for (cur_bit = 1; cur_bit && cur_bit <= rvalue->flags; cur_bit <<= 1) {
            switch (rvalue->flags & cur_bit) {
            case 0x1:
                *cur_arg++ = lbl_805E5CEC * jobj->rotate.x;
                break;
            case 0x2:
                *cur_arg++ = lbl_805E5CEC * jobj->rotate.y;
                break;
            case 0x4:
                *cur_arg++ = lbl_805E5CEC * jobj->rotate.z;
                break;
            case 0x8:
                break;
            case 0x10:
                *cur_arg++ = jobj->translate.x;
                break;
            case 0x20:
                *cur_arg++ = jobj->translate.y;
                break;
            case 0x40:
                *cur_arg++ = jobj->translate.z;
                break;
            case 0x80:
                *cur_arg++ = jobj->scale.x;
                break;
            case 0x100:
                *cur_arg++ = jobj->scale.y;
                break;
            case 0x200:
                *cur_arg++ = jobj->scale.z;
                break;
            case 0x400:
            case 0x800:
                break;
            case 0x10000:
                HSD_MtxGetRotation(jobj->mtx, &sp2C);
                *cur_arg++ = lbl_805E5CEC * sp2C.x;
                break;
            case 0x20000:
                HSD_MtxGetRotation(jobj->mtx, &sp2C);
                *cur_arg++ = lbl_805E5CEC * sp2C.y;
                break;
            case 0x40000:
                HSD_MtxGetRotation(jobj->mtx, &sp2C);
                *cur_arg++ = lbl_805E5CEC * sp2C.z;
                break;
            case 0x100000:
                *cur_arg++ = jobj->mtx[0][3];
                break;
            case 0x200000:
                *cur_arg++ = jobj->mtx[1][3];
                break;
            case 0x400000:
                *cur_arg++ = jobj->mtx[2][3];
                break;
            case 0x800000:
                HSD_MtxGetScale(jobj->mtx, &scale);
                *cur_arg++ = scale.x;
                break;
            case 0x1000000:
                HSD_MtxGetScale(jobj->mtx, &scale);
                *cur_arg++ = scale.y;
                break;
            case 0x2000000:
                HSD_MtxGetScale(jobj->mtx, &scale);
                *cur_arg++ = scale.z;
                break;
            }
        }
    }
    if (exp->is_bytecode) {
        sp1C.fv = HSD_ByteCodeEval(exp->expr.bytecode, lbl_805DE2D8, exp->nb_args);
    } else {
        sp1C.fv = exp->expr.func(lbl_805DE2D8);
    }
    if (type - 1 <= 2) {
        sp1C.fv = sp1C.fv * lbl_805E5CE8;
    }
    update_func(obj, type, &sp1C);
}

f32 fn_8041A0EC(void* unused)
{
    return lbl_805E5CD4;
}

static inline HSD_Rvalue* HSD_RvalueAlloc(void)
{
    HSD_Rvalue* rvalue = HSD_ObjAlloc(&lbl_8058BC3C);
    assert_line_named(0x485, rvalue, lbl_805DCC7C);
    memset(rvalue, 0, sizeof(HSD_Rvalue));
    return rvalue;
}

static inline void HSD_RvalueRemove(HSD_Rvalue* rvalue)
{
    if (rvalue != NULL) {
        HSD_JObjUnrefThis(rvalue->jobj);
        HSD_ObjFree(&lbl_8058BC3C, rvalue);
    }
}

void HSD_RvalueRemoveAll(HSD_Rvalue* rvalue)
{
    HSD_Rvalue* next;

    for (; rvalue != NULL; rvalue = next) {
        next = rvalue->next;
        HSD_RvalueRemove(rvalue);
    }
}

static inline HSD_Rvalue* loadRvalue(HSD_RvalueList* list)
{
    HSD_Rvalue* rp;
    HSD_Rvalue rv;

    rv.next = NULL;
    rp = &rv;
    if (list == NULL) {
        return NULL;
    } else {
        for (; list->joint != NULL; list++) {
            rp->next = HSD_RvalueAlloc();
            rp->next->flags = list->flags;
            rp = rp->next;
        }
    }
    return rv.next;
}

void expLoadDesc(HSD_Exp* exp, HSD_ExpDesc* desc)
{
    memset(exp, 0, sizeof(HSD_Exp));
    if (desc != NULL) {
        if (desc->func != NULL) {
            exp->expr.func = desc->func;
        } else {
            exp->expr.func = fn_8041A0EC;
        }
        exp->rvalue = loadRvalue(desc->rvalue);
        exp->nb_args = -1;
    }
}

void bcexpLoadDesc(HSD_Exp* exp, HSD_ByteCodeExpDesc* desc)
{
    memset(exp, 0, sizeof(HSD_Exp));
    if (desc != NULL) {
        if (desc->bytecode != NULL) {
            exp->expr.bytecode = desc->bytecode;
        } else {
            exp->expr.bytecode = NULL;
        }
        exp->rvalue = loadRvalue(desc->rvalue);
        exp->nb_args = -1;
        exp->is_bytecode = 1;
    }
}

static inline void HSD_RvalueResolveRefs(HSD_Rvalue* rvalue, HSD_RvalueList* list)
{
    if (rvalue != NULL && list != NULL) {
        HSD_JObjUnrefThis(rvalue->jobj);
        rvalue->jobj = HSD_IDGetData((u32) list->joint, NULL);
        assert_line_named(0x4F2, rvalue->jobj, lbl_805DCC7C);
        if (rvalue->jobj != NULL) {
            iref_INC(rvalue->jobj);
        }
    }
}

void HSD_RvalueResolveRefsAll(HSD_Rvalue* rvalue, HSD_RvalueList* list)
{
    if (list == NULL) {
        return;
    }
    for (; rvalue != NULL && list->joint != NULL; rvalue = rvalue->next, list++) {
        HSD_RvalueResolveRefs(rvalue, list);
    }
}

void HSD_RObjSetConstraintObj(HSD_RObj* robj, void* o)
{
    if (robj != NULL) {
        if (robj->u.jobj != NULL) {
            HSD_JObjUnrefThis(robj->u.jobj);
            robj->u.jobj = NULL;
        }

        if (hsdObjIsDescendantOf((HSD_Class*) &((HSD_JObj*) o)->object,
                                (HSD_ClassInfo*) &hsdJObj))
        {
            robj->u.jobj = o;
            if (o != NULL) {
                iref_INC(o);
            }
        } else {
            OSReport("constraint only support jobj target.\n");
            assert_line_named(0x51D, 0, lbl_805DCC84);
        }
    }
}

extern BOOL _HSD_MemCheckOwn(void* ptr);

void fn_8041A504(void* low, void* high)
{
    if (_HSD_MemCheckOwn(lbl_805DE2D8)) {
        lbl_805DE2D8 = 0;
        lbl_805DE2DC = 0;
    }
}

extern HSD_ObjAllocData lbl_8058BC68;

HSD_ObjAllocData* fn_8041A53C(void)
{
    return &lbl_8058BC68;
}
