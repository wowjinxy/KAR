#include <sysdolphin/cobj.h>

#include <dolphin/gx/gxtypes.h>

#define DegToRad(x) ((x) * 0.017453292F)
#define COBJ_MTX_DIRTY 0x40000000
#define COBJ_INV_DIRTY 0x80000000

extern HSD_ClassInfo objInfo;
extern GXRenderModeObj lbl_80589A80;
extern s32 lbl_805DCB00;
extern s32 lbl_805DCB04;
extern f32 lbl_805DC8B8;

extern void* hsdNew(HSD_ClassInfo* info);
extern void hsdInitClassInfo(HSD_ClassInfo* class_info,
                             HSD_ClassInfo* parent_info,
                             char* base_class_library, char* type,
                             s32 info_size, s32 class_size);
extern void _HSD_ZListClear(void);
extern void _HSD_ZListSort(void);
extern void _HSD_ZListDisp(void);
extern s32 HSD_GetCurrentRenderPass(void);
extern MtxPtr HSD_MtxAlloc(void);
extern void HSD_MtxFree(MtxPtr mtx);
extern void HSD_AObjRemove(HSD_AObj* aobj);
extern HSD_AObj* HSD_AObjLoadDesc(HSD_AObjDesc* desc);
extern void HSD_AObjInterpretAnim(HSD_AObj* aobj, void* obj,
                                  HSD_ObjUpdateFunc update_func);
extern void HSD_AObjReqAnim(HSD_AObj* aobj, f32 frame);
extern void HSD_WObjInterpretAnim(HSD_WObj* wobj);
extern void HSD_WObjRemoveAnim(HSD_WObj* wobj);
extern void HSD_WObjAddAnim(HSD_WObj* wobj, HSD_WObjAnim* anim);
extern void HSD_WObjReqAnim(HSD_WObj* wobj, f32 frame);
extern void HSD_WObjInit(HSD_WObj* wobj, HSD_WObjDesc* desc);
extern HSD_WObj* HSD_WObjAlloc(void);
extern void HSD_WObjGetPosition(HSD_WObj* wobj, Vec* pos);
extern void HSD_WObjSetPosition(HSD_WObj* wobj, Vec* pos);
extern void kar_displayfunc_draw_viewport_scale_quad(s32 color_update, f32 top,
                                                     f32 bottom,
                                                     s32 alpha_update,
                                                     f32 left,
                                                     s32 tex_enable,
                                                     f32 right, f32 z);
extern void GXSetProjection(Mtx mtx, s32 projection_type);
extern void GXSetViewport(f32 left, f32 top, f32 width, f32 height,
                          f32 near_z, f32 far_z);
extern void GXSetViewportJitter(f32 left, f32 top, f32 width, f32 height,
                                f32 near_z, f32 far_z, u32 field);
extern void GXSetScissor(u32 left, u32 top, u32 width, u32 height);
extern u32 VIGetNextField(void);
extern void C_MTXLookAt(Mtx mtx, Vec* eye, Vec* up, Vec* interest);
extern void C_MTXPerspective(Mtx mtx, f32 fov, f32 aspect, f32 near,
                             f32 far);
extern void C_MTXFrustum(Mtx mtx, f32 top, f32 bottom, f32 left, f32 right,
                         f32 near, f32 far);
extern void C_MTXOrtho(Mtx mtx, f32 top, f32 bottom, f32 left, f32 right,
                       f32 near, f32 far);
extern void PSMTXCopy(Mtx src, Mtx dst);
extern void PSMTXRotAxisRad(Mtx mtx, Vec* axis, f32 rad);
extern void PSMTXMultVecSR(Mtx mtx, Vec* src, Vec* dst);
extern void fn_803D1578(Mtx src, Mtx dst);
extern void PSVECSubtract(Vec* a, Vec* b, Vec* dst);
extern void PSVECNormalize(Vec* src, Vec* dst);
extern f32 PSVECMag(Vec* vec);
extern f32 PSVECDotProduct(Vec* a, Vec* b);
extern void PSVECCrossProduct(Vec* a, Vec* b, Vec* dst);
extern f64 tan(f64 x);
extern f64 atan2(f64 y, f64 x);
extern f64 sqrt(f64 x);

static HSD_CObjInfo* default_class;
static HSD_CObj* current;

static int CObjLoad(HSD_CObj* cobj, HSD_CObjDesc* desc);
static int CObjInit(HSD_Class* obj);
static void CObjRelease(HSD_Class* obj);
static void CObjAmnesia(HSD_ClassInfo* info);
static void CObjInfoInit(void);
static void CObjUpdateFunc(void* obj, enum_t type, HSD_ObjData* val);

HSD_CObjInfo hsdCObj = { CObjInfoInit };

static Vec lbl_805033C0 = { 0.0F, 0.0F, 0.0F };
static Vec lbl_805033CC = { 0.0F, 1.0F, 0.0F };
static Vec lbl_805033D8 = { 0.0F, 1.0F, 0.0F };

static f32 cobj_abs(f32 val)
{
    if (val < 0.0F) {
        return -val;
    }
    return val;
}

static BOOL vec_is_zero(Vec* vec)
{
    if (cobj_abs(vec->x) > lbl_805DC8B8) {
        return FALSE;
    }
    if (cobj_abs(vec->y) > lbl_805DC8B8) {
        return FALSE;
    }
    if (cobj_abs(vec->z) > lbl_805DC8B8) {
        return FALSE;
    }
    return TRUE;
}

s32 vec_normalize_check(Vec* src, Vec* dst)
{
    if (src == NULL || dst == NULL || vec_is_zero(src)) {
        return -1;
    }
    PSVECNormalize(src, dst);
    return 0;
}

void HSD_CObjSetViewportScale(HSD_CObj* cobj, s32 color_update,
                              s32 alpha_update, s32 tex_enable)
{
    f32 z;
    f32 scale;
    f32 top;
    f32 bottom;
    f32 left;
    f32 right;

    if (cobj == NULL ||
        (color_update == 0 && alpha_update == 0 && tex_enable == 0)) {
        return;
    }

    z = 0.5 * (HSD_CObjGetNear(cobj) + HSD_CObjGetFar(cobj));
    switch (HSD_CObjGetProjectionType(cobj)) {
    case PROJ_PERSPECTIVE:
        top = z * tan(DegToRad(0.5F * cobj->projection_param.perspective.fov));
        bottom = -top;
        right = top * cobj->projection_param.perspective.aspect;
        left = -right;
        break;
    case PROJ_FRUSTRUM:
        scale = z / HSD_CObjGetNear(cobj);
        top = scale * cobj->projection_param.frustrum.top;
        bottom = scale * cobj->projection_param.frustrum.bottom;
        left = scale * cobj->projection_param.frustrum.left;
        right = scale * cobj->projection_param.frustrum.right;
        break;
    case PROJ_ORTHO:
        top = cobj->projection_param.ortho.top;
        bottom = cobj->projection_param.ortho.bottom;
        left = cobj->projection_param.ortho.left;
        right = cobj->projection_param.ortho.right;
        break;
    default:
        top = bottom = left = right = 0.0F;
        break;
    }

    kar_displayfunc_draw_viewport_scale_quad(color_update, top, bottom,
                                             alpha_update, left, tex_enable,
                                             right, -z);
}

void HSD_CObjAddAnim(HSD_CObj* cobj, HSD_CameraAnim* anim)
{
    if (cobj != NULL && anim != NULL) {
        if (cobj->aobj != NULL) {
            HSD_AObjRemove(cobj->aobj);
        }
        cobj->aobj = HSD_AObjLoadDesc(anim->aobjdesc);
        HSD_WObjAddAnim(HSD_CObjGetEyePositionWObj(cobj), anim->eye_anim);
        HSD_WObjAddAnim(HSD_CObjGetInterestWObj(cobj), anim->interest_anim);
    }
}

static void CObjUpdateFunc(void* obj, enum_t type, HSD_ObjData* val)
{
    HSD_CObj* cobj = obj;
    Vec vec;

    if (cobj == NULL) {
        return;
    }

    switch (type) {
    case 1:
        HSD_CObjGetEyePosition(cobj, &vec);
        vec.x = val->fv;
        HSD_CObjSetEyePosition(cobj, &vec);
        break;
    case 2:
        HSD_CObjGetEyePosition(cobj, &vec);
        vec.y = val->fv;
        HSD_CObjSetEyePosition(cobj, &vec);
        break;
    case 3:
        HSD_CObjGetEyePosition(cobj, &vec);
        vec.z = val->fv;
        HSD_CObjSetEyePosition(cobj, &vec);
        break;
    case 5:
    case 6:
    case 7:
        HSD_CObjGetInterest(cobj, &vec);
        vec.x = val->fv;
        HSD_CObjSetInterest(cobj, &vec);
        break;
    case 9:
        HSD_CObjSetRoll(cobj, val->fv);
        break;
    case 10:
        HSD_CObjSetFov(cobj, val->fv);
        break;
    case 11:
        HSD_CObjSetNear(cobj, val->fv);
        break;
    case 12:
        HSD_CObjSetFar(cobj, val->fv);
        break;
    }
}

void HSD_CObjAnim(HSD_CObj* cobj)
{
    if (cobj != NULL) {
        HSD_AObjInterpretAnim(cobj->aobj, cobj, CObjUpdateFunc);
        HSD_WObjInterpretAnim(cobj->eye_position);
        HSD_WObjInterpretAnim(cobj->interest);
    }
}

void HSD_CObjReqAnim(HSD_CObj* cobj, f32 frame)
{
    if (cobj != NULL) {
        HSD_AObjReqAnim(cobj->aobj, frame);
        HSD_WObjReqAnim(cobj->eye_position, frame);
        HSD_WObjReqAnim(cobj->interest, frame);
    }
}

static s32 makeProjectionMtx(HSD_CObj* cobj, Mtx mtx)
{
    switch (cobj->projection_type) {
    case PROJ_PERSPECTIVE:
        C_MTXPerspective(mtx, cobj->projection_param.perspective.fov,
                         cobj->projection_param.perspective.aspect,
                         cobj->near, cobj->far);
        return 0;
    case PROJ_FRUSTRUM:
        C_MTXFrustum(mtx, cobj->projection_param.frustrum.top,
                     cobj->projection_param.frustrum.bottom,
                     cobj->projection_param.frustrum.left,
                     cobj->projection_param.frustrum.right, cobj->near,
                     cobj->far);
        return 0;
    case PROJ_ORTHO:
        C_MTXOrtho(mtx, cobj->projection_param.ortho.top,
                   cobj->projection_param.ortho.bottom,
                   cobj->projection_param.ortho.left,
                   cobj->projection_param.ortho.right, cobj->near, cobj->far);
        return 1;
    }
    return 0;
}

static BOOL setupTopHalfCamera(HSD_CObj* cobj)
{
    Mtx mtx;
    f32 height;
    f32 bottom;

    if (cobj->viewport_top >= lbl_80589A80.efbHeight) {
        return FALSE;
    }

    bottom = cobj->viewport_bottom;
    if (bottom > lbl_80589A80.efbHeight) {
        bottom = lbl_80589A80.efbHeight;
    }
    height = bottom - cobj->viewport_top;
    GXSetScissor(cobj->viewport_left, cobj->viewport_top,
                 cobj->viewport_right - cobj->viewport_left, height);
    GXSetViewport(cobj->viewport_left, cobj->viewport_top,
                  cobj->viewport_right - cobj->viewport_left, height, 0.0F,
                  1.0F);
    GXSetProjection(mtx, makeProjectionMtx(cobj, mtx));
    return TRUE;
}

static BOOL setupBottomHalfCamera(HSD_CObj* cobj)
{
    Mtx mtx;
    u32 screen_top;
    f32 top;
    f32 bottom;

    screen_top = lbl_80589A80.efbHeight - 8;
    if (cobj->viewport_bottom < screen_top) {
        return FALSE;
    }

    top = cobj->viewport_top;
    if (top < screen_top) {
        top = screen_top;
    }
    bottom = cobj->viewport_bottom;
    GXSetScissor(cobj->scissor_left, top - screen_top,
                 cobj->scissor_right - cobj->scissor_left,
                 bottom - screen_top - (top - screen_top));
    GXSetViewport(cobj->viewport_left, top - screen_top,
                  cobj->viewport_right - cobj->viewport_left, bottom - top,
                  0.0F, 1.0F);
    GXSetProjection(mtx, makeProjectionMtx(cobj, mtx));
    return TRUE;
}

void HSD_CObjSetupViewingMtx(HSD_CObj* cobj)
{
    Vec eye;
    Vec up;
    Vec interest;

    if ((cobj->flags & 2) == 0 && HSD_CObjMtxIsDirty(cobj)) {
        HSD_CObjGetEyePosition(cobj, &eye);
        if (HSD_CObjGetUpVector(cobj, &up) == 0) {
            up.x = 0.0F;
            up.y = 1.0F;
            up.z = 0.0F;
        }
        HSD_CObjGetInterest(cobj, &interest);
        C_MTXLookAt(cobj->view_mtx, &eye, &up, &interest);
        PSVECSubtract(&interest, &eye, &cobj->eye_vector);
        if (!vec_is_zero(&cobj->eye_vector)) {
            PSVECNormalize(&cobj->eye_vector, &cobj->eye_vector);
        }
        cobj->eye_position->flags &= ~2;
        cobj->interest->flags &= ~2;
        HSD_CObjClearFlags(cobj, COBJ_MTX_DIRTY);
        HSD_CObjSetFlags(cobj, COBJ_INV_DIRTY);
    }
}

BOOL HSD_CObjSetCurrent(HSD_CObj* cobj)
{
    Mtx mtx;
    s32 projection_type;
    s32 pass;
    BOOL result;
    f32 x_scale;
    f32 y_scale;
    f32 left;
    f32 top;
    f32 width;
    f32 height;

    if (cobj == NULL) {
        return FALSE;
    }

    pass = HSD_GetCurrentRenderPass();
    _HSD_ZListClear();
    current = cobj;
    result = TRUE;

    switch (pass) {
    case 0:
        x_scale = (f32) lbl_80589A80.fbWidth / (f32) lbl_805DCB00;
        y_scale = (f32) lbl_80589A80.efbHeight / (f32) lbl_805DCB04;
        left = cobj->viewport_left * x_scale;
        top = cobj->viewport_top * y_scale;
        width = cobj->viewport_right * x_scale - left;
        height = cobj->viewport_bottom * y_scale - top;
        if (lbl_80589A80.field_rendering) {
            GXSetViewportJitter(left, top, width, height, 0.0F, 1.0F,
                                VIGetNextField());
        } else {
            GXSetViewport(left, top, width, height, 0.0F, 1.0F);
        }
        left = cobj->scissor_left * x_scale;
        top = cobj->scissor_top * y_scale;
        width = cobj->scissor_right * x_scale - left;
        height = cobj->scissor_bottom * y_scale - top;
        GXSetScissor(left, top, width, height);
        projection_type = makeProjectionMtx(cobj, mtx);
        GXSetProjection(mtx, projection_type);
        break;
    case 1:
        GXSetViewport(cobj->viewport_left, cobj->viewport_top,
                      cobj->viewport_right - cobj->viewport_left,
                      cobj->viewport_bottom - cobj->viewport_top, 0.0F, 1.0F);
        GXSetScissor(cobj->scissor_left, cobj->scissor_top,
                     cobj->scissor_right - cobj->scissor_left,
                     cobj->scissor_bottom - cobj->scissor_top);
        projection_type = makeProjectionMtx(cobj, mtx);
        GXSetProjection(mtx, projection_type);
        break;
    case 2:
        result = setupTopHalfCamera(cobj);
        break;
    case 3:
        result = setupBottomHalfCamera(cobj);
        break;
    default:
        __assert(__FILE__, 0x26F, "0");
        result = FALSE;
        break;
    }

    if (result) {
        HSD_CObjSetupViewingMtx(cobj);
    }
    return result;
}

void HSD_CObjEndCurrent(void)
{
    _HSD_ZListSort();
    _HSD_ZListDisp();
}

HSD_WObj* HSD_CObjGetInterestWObj(HSD_CObj* cobj)
{
    assert_line(0x2C1, cobj);
    return cobj->interest;
}

HSD_WObj* HSD_CObjGetEyePositionWObj(HSD_CObj* cobj)
{
    assert_line(0x2D9, cobj);
    return cobj->eye_position;
}

void HSD_CObjGetInterest(HSD_CObj* cobj, Vec* interest)
{
    assert_line(0x2F1, cobj);
    HSD_WObjGetPosition(HSD_CObjGetInterestWObj(cobj), interest);
}

void HSD_CObjSetInterest(HSD_CObj* cobj, Vec* interest)
{
    assert_line(0x2FD, cobj);
    HSD_WObjSetPosition(HSD_CObjGetInterestWObj(cobj), interest);
}

void HSD_CObjGetEyePosition(HSD_CObj* cobj, Vec* position)
{
    assert_line(0x309, cobj);
    HSD_WObjGetPosition(HSD_CObjGetEyePositionWObj(cobj), position);
}

void HSD_CObjSetEyePosition(HSD_CObj* cobj, Vec* position)
{
    assert_line(0x315, cobj);
    HSD_WObjSetPosition(HSD_CObjGetEyePositionWObj(cobj), position);
}

s32 HSD_CObjGetEyeVector(HSD_CObj* cobj, Vec* eye)
{
    Vec pos;
    Vec interest;

    if (cobj == NULL || cobj->eye_position == NULL || cobj->interest == NULL) {
        return FALSE;
    }
    if (!HSD_CObjMtxIsDirty(cobj)) {
        *eye = cobj->eye_vector;
        return TRUE;
    }

    HSD_CObjGetEyePosition(cobj, &pos);
    HSD_CObjGetInterest(cobj, &interest);
    PSVECSubtract(&interest, &pos, eye);
    return vec_normalize_check(eye, eye) == 0;
}

f32 HSD_CObjGetEyeDistance(HSD_CObj* cobj)
{
    Vec pos;
    Vec interest;
    Vec eye;

    if (cobj == NULL) {
        return 0.0F;
    }
    HSD_CObjGetEyePosition(cobj, &pos);
    HSD_CObjGetInterest(cobj, &interest);
    PSVECSubtract(&interest, &pos, &eye);
    return PSVECMag(&eye);
}

static f32 upvec2roll(HSD_CObj* cobj, Vec* up)
{
    Vec eye;
    Vec v;
    Mtx mtx;
    f32 dot;

    if (!HSD_CObjGetEyeVector(cobj, &eye)) {
        return 0.0F;
    }
    dot = 1.0F - cobj_abs(PSVECDotProduct(up, &eye));
    if (dot < lbl_805DC8B8) {
        return 0.0F;
    }
    C_MTXLookAt(mtx, &lbl_805033C0, &lbl_805033CC, &eye);
    PSMTXMultVecSR(mtx, up, &v);
    if (v.y == 0.0F) {
        if (-v.x >= 0.0F) {
            return 1.5707964F;
        }
        return -1.5707964F;
    }
    return atan2(-v.x, v.y);
}

static s32 roll2upvec(HSD_CObj* cobj, Vec* up, f32 roll)
{
    Vec eye;
    Vec v0;
    Vec v1;
    Mtx mtx;

    if (!HSD_CObjGetEyeVector(cobj, &eye)) {
        return FALSE;
    }
    if (1.0 - cobj_abs(eye.y) < 0.0001) {
        v0.x = sqrt(eye.y * eye.y + eye.z * eye.z);
        v0.y = eye.y * (-eye.x / v0.x);
        v0.z = eye.z * (-eye.x / v0.x);
    } else {
        v0.y = sqrt(eye.x * eye.x + eye.z * eye.z);
        v0.x = eye.x * (-eye.y / v0.y);
        v0.z = eye.z * (-eye.y / v0.y);
    }
    PSMTXRotAxisRad(mtx, &eye, -roll);
    PSMTXMultVecSR(mtx, &v0, &v1);
    PSVECNormalize(&v1, up);
    return TRUE;
}

s32 HSD_CObjGetUpVector(HSD_CObj* cobj, Vec* up)
{
    if (cobj != NULL && up != NULL) {
        if (cobj->flags & 1) {
            *up = cobj->u.up;
            return TRUE;
        }
        return roll2upvec(cobj, up, cobj->u.roll);
    }
    return FALSE;
}

void HSD_CObjSetUpVector(HSD_CObj* cobj, Vec* up)
{
    Vec normalized;

    if (cobj == NULL || up == NULL) {
        return;
    }
    if (cobj->flags & 1) {
        if (vec_normalize_check(up, &normalized) != 0) {
            OSReport("up vector is zero\n");
            __assert(__FILE__, 0x3E3, "0");
        }
        if (cobj->u.up.x != normalized.x || cobj->u.up.y != normalized.y ||
            cobj->u.up.z != normalized.z) {
            HSD_CObjSetMtxDirty(cobj);
            cobj->u.up = normalized;
        }
    } else {
        HSD_CObjSetRoll(cobj, upvec2roll(cobj, up));
    }
}

s32 HSD_CObjGetLeftVector(HSD_CObj* cobj, Vec* left)
{
    Vec eye;
    Vec up;

    if (cobj == NULL || left == NULL) {
        return FALSE;
    }
    if (HSD_CObjGetEyeVector(cobj, &eye) &&
        HSD_CObjGetUpVector(cobj, &up)) {
        PSVECCrossProduct(&up, &eye, left);
        return vec_normalize_check(left, left) == 0;
    }
    return FALSE;
}

void HSD_CObjSetMtxDirty(HSD_CObj* cobj)
{
    cobj->flags |= COBJ_MTX_DIRTY | COBJ_INV_DIRTY;
}

BOOL HSD_CObjMtxIsDirty(HSD_CObj* cobj)
{
    if (cobj->flags & COBJ_MTX_DIRTY) {
        return TRUE;
    }
    if (cobj->eye_position != NULL && (cobj->eye_position->flags & 2)) {
        return TRUE;
    }
    if (cobj->interest != NULL && (cobj->interest->flags & 2)) {
        return TRUE;
    }
    return FALSE;
}

void HSD_CObjGetViewingMtx(HSD_CObj* cobj, Mtx mtx)
{
    PSMTXCopy(HSD_CObjGetViewingMtxPtr(cobj), mtx);
}

MtxPtr HSD_CObjGetInvViewingMtxPtrDirect(HSD_CObj* cobj)
{
    if (cobj->flags & COBJ_INV_DIRTY) {
        if (cobj->proj_mtx == NULL) {
            cobj->proj_mtx = HSD_MtxAlloc();
        }
        fn_803D1578(cobj->view_mtx, cobj->proj_mtx);
        HSD_CObjClearFlags(cobj, COBJ_INV_DIRTY);
    }
    return cobj->proj_mtx;
}

MtxPtr HSD_CObjGetViewingMtxPtr(HSD_CObj* cobj)
{
    HSD_CObjSetupViewingMtx(cobj);
    return cobj->view_mtx;
}

void HSD_CObjSetRoll(HSD_CObj* cobj, f32 roll)
{
    Vec up;

    if (cobj == NULL) {
        return;
    }
    if (cobj->flags & 1) {
        if (roll2upvec(cobj, &up, roll)) {
            HSD_CObjSetUpVector(cobj, &up);
        }
    } else {
        if (cobj->u.roll != roll) {
            HSD_CObjSetMtxDirty(cobj);
        }
        cobj->u.roll = roll;
    }
}

f32 HSD_CObjGetFov(HSD_CObj* cobj)
{
    if (cobj == NULL || cobj->projection_type != PROJ_PERSPECTIVE) {
        return 0.0F;
    }
    return cobj->projection_param.perspective.fov;
}

void HSD_CObjSetFov(HSD_CObj* cobj, f32 fov)
{
    if (cobj != NULL && cobj->projection_type == PROJ_PERSPECTIVE) {
        cobj->projection_param.perspective.fov = fov;
    }
}

f32 HSD_CObjGetAspect(HSD_CObj* cobj)
{
    if (cobj == NULL || cobj->projection_type != PROJ_PERSPECTIVE) {
        return 0.0F;
    }
    return cobj->projection_param.perspective.aspect;
}

void HSD_CObjSetAspect(HSD_CObj* cobj, f32 aspect)
{
    if (cobj != NULL && cobj->projection_type == PROJ_PERSPECTIVE) {
        cobj->projection_param.perspective.aspect = aspect;
    }
}

f32 HSD_CObjGetNear(HSD_CObj* cobj)
{
    if (cobj == NULL) {
        return 0.0F;
    }
    return cobj->near;
}

void HSD_CObjSetNear(HSD_CObj* cobj, f32 near)
{
    if (cobj != NULL) {
        cobj->near = near;
    }
}

f32 HSD_CObjGetFar(HSD_CObj* cobj)
{
    if (cobj == NULL) {
        return 0.0F;
    }
    return cobj->far;
}

void HSD_CObjSetFar(HSD_CObj* cobj, f32 far)
{
    if (cobj != NULL) {
        cobj->far = far;
    }
}

void HSD_CObjGetScissor(HSD_CObj* cobj, Scissor* scissor)
{
    if (cobj != NULL) {
        *scissor = cobj->scissor;
    }
}

void HSD_CObjSetScissor(HSD_CObj* cobj, Scissor* scissor)
{
    if (cobj != NULL) {
        cobj->scissor = *scissor;
    }
}

void HSD_CObjSetScissorx4(HSD_CObj* cobj, s32 left, u16 right, s32 top,
                          u16 bottom)
{
    if (cobj != NULL) {
        cobj->scissor_left = left;
        cobj->scissor_right = right;
        cobj->scissor_top = top;
        cobj->scissor_bottom = bottom;
    }
}

void HSD_CObjGetViewport(HSD_CObj* cobj, HSD_RectS16* viewport)
{
    if (cobj != NULL) {
        viewport->xmin = cobj->viewport_left;
        viewport->xmax = cobj->viewport_right;
        viewport->ymin = cobj->viewport_top;
        viewport->ymax = cobj->viewport_bottom;
    }
}

void HSD_CObjGetViewportf(HSD_CObj* cobj, HSD_RectF32* viewport)
{
    if (cobj != NULL) {
        *viewport = cobj->viewport;
    }
}

void HSD_CObjSetViewport(HSD_CObj* cobj, HSD_RectS16* viewport)
{
    if (cobj != NULL) {
        cobj->viewport_left = viewport->xmin;
        cobj->viewport_right = viewport->xmax;
        cobj->viewport_top = viewport->ymin;
        cobj->viewport_bottom = viewport->ymax;
    }
}

void HSD_CObjSetViewportf(HSD_CObj* cobj, HSD_RectF32* viewport)
{
    if (cobj != NULL) {
        cobj->viewport = *viewport;
    }
}

void HSD_CObjSetViewportfx4(HSD_CObj* cobj, f32 left, f32 right, f32 top,
                            f32 bottom)
{
    if (cobj != NULL) {
        cobj->viewport_left = left;
        cobj->viewport_right = right;
        cobj->viewport_top = top;
        cobj->viewport_bottom = bottom;
    }
}

s32 HSD_CObjGetProjectionType(HSD_CObj* cobj)
{
    if (cobj == NULL) {
        return PROJ_PERSPECTIVE;
    }
    return cobj->projection_type;
}

void HSD_CObjSetProjectionType(HSD_CObj* cobj, u32 projection_type)
{
    if (cobj != NULL) {
        cobj->projection_type = projection_type;
    }
}

void HSD_CObjSetFrustum(HSD_CObj* cobj, f32 top, f32 bottom, f32 left,
                        f32 right)
{
    if (cobj != NULL) {
        cobj->projection_type = PROJ_FRUSTRUM;
        cobj->projection_param.frustrum.top = top;
        cobj->projection_param.frustrum.bottom = bottom;
        cobj->projection_param.frustrum.left = left;
        cobj->projection_param.frustrum.right = right;
    }
}

void HSD_CObjSetOrtho(HSD_CObj* cobj, f32 top, f32 bottom, f32 left,
                      f32 right)
{
    if (cobj != NULL) {
        cobj->projection_type = PROJ_ORTHO;
        cobj->projection_param.ortho.top = top;
        cobj->projection_param.ortho.bottom = bottom;
        cobj->projection_param.ortho.left = left;
        cobj->projection_param.ortho.right = right;
    }
}

void HSD_CObjSetFlags(HSD_CObj* cobj, u32 flags)
{
    if (cobj != NULL) {
        cobj->flags |= flags;
    }
}

void HSD_CObjClearFlags(HSD_CObj* cobj, u32 flags)
{
    if (cobj != NULL) {
        cobj->flags &= ~flags;
    }
}

HSD_CObj* HSD_CObjGetCurrent(void)
{
    return current;
}

HSD_CObj* HSD_CObjAlloc(void)
{
    HSD_CObj* cobj;

    cobj = hsdNew((HSD_ClassInfo*) (default_class != NULL ? default_class
                                                           : &hsdCObj));
    assert_line(0x850, cobj);
    return cobj;
}

static void CObjResetFlags(HSD_CObj* cobj, u32 flags)
{
    if (cobj != NULL) {
        cobj->flags = (cobj->flags & (COBJ_MTX_DIRTY | COBJ_INV_DIRTY)) |
                      flags;
    }
}

static int CObjLoad(HSD_CObj* cobj, HSD_CObjDesc* desc)
{
    cobj->flags = desc->flags;
    CObjResetFlags(cobj, desc->flags);
    HSD_CObjSetViewport(cobj, &desc->viewport);
    HSD_CObjSetScissor(cobj, &desc->scissor);
    HSD_WObjInit(cobj->eye_position, desc->eye_desc);
    HSD_WObjInit(cobj->interest, desc->interest_desc);
    HSD_CObjSetNear(cobj, desc->near);
    HSD_CObjSetFar(cobj, desc->far);
    if (desc->flags & 1) {
        if (desc->vector != NULL) {
            HSD_CObjSetUpVector(cobj, desc->vector);
        } else {
            HSD_CObjSetUpVector(cobj, &lbl_805033D8);
        }
    } else {
        HSD_CObjSetRoll(cobj, desc->roll);
    }

    switch (desc->projection_type) {
    case PROJ_PERSPECTIVE:
        HSD_CObjSetProjectionType(cobj, PROJ_PERSPECTIVE);
        cobj->projection_param.perspective.fov =
            desc->projection_param.perspective.fov;
        cobj->projection_param.perspective.aspect =
            desc->projection_param.perspective.aspect;
        break;
    case PROJ_FRUSTRUM:
        HSD_CObjSetFrustum(cobj, desc->projection_param.frustrum.top,
                           desc->projection_param.frustrum.bottom,
                           desc->projection_param.frustrum.left,
                           desc->projection_param.frustrum.right);
        break;
    case PROJ_ORTHO:
        HSD_CObjSetOrtho(cobj, desc->projection_param.ortho.top,
                         desc->projection_param.ortho.bottom,
                         desc->projection_param.ortho.left,
                         desc->projection_param.ortho.right);
        break;
    default:
        assert_line(0x7D0, 0);
        break;
    }
    return 0;
}

HSD_CObj* HSD_CObjLoadDesc(HSD_CObjDesc* desc)
{
    HSD_ClassInfo* info;
    HSD_CObj* cobj;

    if (desc == NULL) {
        return NULL;
    }
    if (desc->class_name == NULL ||
        (info = hsdSearchClassInfo(desc->class_name)) == NULL) {
        cobj = HSD_CObjAlloc();
    } else {
        cobj = hsdNew(info);
        assert_line(0x7F7, cobj);
    }
    HSD_COBJ_METHOD(cobj)->load(cobj, desc);
    return cobj;
}

static int CObjInit(HSD_Class* obj)
{
    HSD_CObj* cobj;
    s32 result;

    result = HSD_OBJECT_PARENT_INFO(&hsdCObj)->init(obj);
    if (result < 0) {
        return result;
    }

    cobj = (HSD_CObj*) obj;
    HSD_CObjSetMtxDirty(cobj);
    cobj->eye_position = HSD_WObjAlloc();
    cobj->interest = HSD_WObjAlloc();
    return 0;
}

static void ref_DEC_destroy(HSD_Obj* obj)
{
    if (obj != NULL) {
        obj->ref_count--;
        if (obj->ref_count == 0) {
            HSD_CLASS_METHOD(obj)->release((HSD_Class*) obj);
            HSD_CLASS_METHOD(obj)->destroy((HSD_Class*) obj);
        }
    }
}

static void CObjRelease(HSD_Class* obj)
{
    HSD_CObj* cobj;

    cobj = (HSD_CObj*) obj;
    HSD_AObjRemove(cobj->aobj);
    ref_DEC_destroy((HSD_Obj*) HSD_CObjGetEyePositionWObj(cobj));
    ref_DEC_destroy((HSD_Obj*) HSD_CObjGetInterestWObj(cobj));
    if (cobj->proj_mtx != NULL) {
        HSD_MtxFree(cobj->proj_mtx);
    }
    HSD_OBJECT_PARENT_INFO(&hsdCObj)->release(obj);
}

static void CObjAmnesia(HSD_ClassInfo* info)
{
    if (info == HSD_CLASS_INFO(default_class)) {
        default_class = NULL;
    }
    if (info == HSD_CLASS_INFO(&hsdCObj)) {
        current = NULL;
    }
    HSD_OBJECT_PARENT_INFO(&hsdCObj)->amnesia(info);
}

static void CObjInfoInit(void)
{
    hsdInitClassInfo(HSD_CLASS_INFO(&hsdCObj), &objInfo,
                     "sysdolphin_base_library", "hsd_cobj",
                     sizeof(HSD_CObjInfo), sizeof(HSD_CObj));
    HSD_CLASS_INFO(&hsdCObj)->init = CObjInit;
    HSD_CLASS_INFO(&hsdCObj)->release = CObjRelease;
    HSD_CLASS_INFO(&hsdCObj)->amnesia = CObjAmnesia;
    hsdCObj.load = CObjLoad;
}
