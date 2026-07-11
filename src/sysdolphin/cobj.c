#include <sysdolphin/cobj.h>

#include <dolphin/gx/gx.h>
#include <dolphin/mtx/mtx.h>
#include <dolphin/mtx/vec.h>
#include <kar/gr/grcoll.h>
#include <kar/math.h>
#include <sysdolphin/gobjproc.h>
#include <sysdolphin/objalloc.h>

#define DegToRad(x) ((x) * 0.017453292F)
#define COBJ_MTX_DIRTY 0x40000000
#define COBJ_INV_DIRTY 0x80000000

extern GXRenderModeObj CObjRenderMode;
extern s32 CObjRefWidth;
extern s32 CObjRefHeight;
extern f32 HSD_FloatMin[]; /* epsilon */
extern HSD_ObjAllocData hsdFObj_alloc_data;

char kar_srcfile_cobj_c[] = "cobj.c";
char CObjAssertCObj[] = "cobj";
char CObjAssertZero[] = "0";

#define ASSERT_COBJ(line)                                                    \
    ((cobj) ? ((void) 0)                                                     \
            : __assert(kar_srcfile_cobj_c, line, CObjAssertCObj))

extern void* hsdNew(HSD_ClassInfo* info);
extern void _HSD_ZListClear(void);
extern void _HSD_ZListSort(void);
extern void _HSD_ZListDisp(void);
extern s32 HSD_GetCurrentRenderPass(void);
extern MtxPtr HSD_MtxAlloc(void);
extern void HSD_MtxFree(MtxPtr mtx);
extern void kar_displayfunc_draw_viewport_scale_quad(s32 color_update, f32 top,
                                                     f32 bottom,
                                                     s32 alpha_update,
                                                     f32 left,
                                                     s32 tex_enable,
                                                     f32 right, f32 z);
extern void GXSetViewportJitter(f32 left, f32 top, f32 width, f32 height,
                                f32 near_z, f32 far_z, u32 field);
extern u32 VIGetNextField(void);
extern void C_MTXPerspective(Mtx mtx, f32 fov, f32 aspect, f32 near,
                             f32 far);
extern void C_MTXFrustum(Mtx mtx, f32 top, f32 bottom, f32 left, f32 right,
                         f32 near, f32 far);
extern void C_MTXOrtho(Mtx mtx, f32 top, f32 bottom, f32 left, f32 right,
                       f32 near, f32 far);

static inline f32 cobj_sqrtf(f32 x)
{
    volatile f32 y;

    if (x > 0.0F) {
        f64 guess = __frsqrte((f64) x);
        guess = 0.5 * guess * __fnmsub(x, guess * guess, 3.0);
        guess = 0.5 * guess * __fnmsub(x, guess * guess, 3.0);
        guess = 0.5 * guess * __fnmsub(x, guess * guess, 3.0);
        y = (f32) (x * guess);
        return y;
    }
    return x;
}

static HSD_CObjInfo* CObjDefaultClass; /* default_class */
static HSD_CObj* CObjCurrent;     /* current */

int CObjLoad(HSD_CObj* cobj, HSD_CObjDesc* desc);
int CObjInit(HSD_Class* obj);
void CObjRelease(HSD_Class* obj);
void CObjAmnesia(HSD_ClassInfo* info);
void CObjInfoInit(void);
void CObjUpdateFunc(void* obj, enum_t type, HSD_ObjData* val);
s32 vec_normalize_check(Vec* src, Vec* dst);
extern Vec CObjDefaultUpVector; /* default up vector */

HSD_CObjInfo hsdCObj = { CObjInfoInit };

static char lbl_dead_805300XX_ref_width[] = "ref_width > 0";
static char lbl_dead_805300XX_ref_height[] = "ref_height > 0";

#define vec_is_zero(vec)                                                    \
    (__fabs((vec)->x) <= HSD_FloatMin[0] && __fabs((vec)->y) <= HSD_FloatMin[0] && \
     __fabs((vec)->z) <= HSD_FloatMin[0])

void HSD_CObjSetViewportScale(HSD_CObj* cobj, s32 color_update,
                              s32 alpha_update, s32 tex_enable)
{
    f32 scale;
    f32 z;
    f32 left;
    f32 right;
    f32 top;
    f32 bottom;

    if (cobj == NULL ||
        (color_update == 0 && alpha_update == 0 && tex_enable == 0)) {
        return;
    }

    z = 0.5 * (HSD_CObjGetNear(cobj) + HSD_CObjGetFar(cobj));
    switch (HSD_CObjGetProjectionType(cobj)) {
    case PROJ_PERSPECTIVE:
        top = z * tan(0.5F * DegToRad(cobj->projection_param.perspective.fov));
        right = top * cobj->projection_param.perspective.aspect;
        bottom = -top;
        left = -right;
        break;
    case PROJ_FRUSTRUM:
        scale = z / HSD_CObjGetNear(cobj);
        right = scale * cobj->projection_param.frustrum.right;
        left = scale * cobj->projection_param.frustrum.left;
        top = scale * cobj->projection_param.frustrum.top;
        bottom = scale * cobj->projection_param.frustrum.bottom;
        break;
    case PROJ_ORTHO:
        right = cobj->projection_param.ortho.right;
        left = cobj->projection_param.ortho.left;
        top = cobj->projection_param.ortho.top;
        bottom = cobj->projection_param.ortho.bottom;
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

void CObjUpdateFunc(void* obj, enum_t type, HSD_ObjData* val)
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
        HSD_CObjGetInterest(cobj, &vec);
        vec.x = val->fv;
        HSD_CObjSetInterest(cobj, &vec);
        break;
    case 6:
        HSD_CObjGetInterest(cobj, &vec);
        vec.x = val->fv;
        HSD_CObjSetInterest(cobj, &vec);
        break;
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
        HSD_AObjInterpretAnim(cobj->aobj, cobj, HSD_COBJ_METHOD(cobj)->update);
        HSD_WObjInterpretAnim(cobj->eye_position);
        HSD_WObjInterpretAnim(cobj->interest);
    }
}

void HSD_CObjReqAnim(HSD_CObj* cobj, f32 frame)
{
    if (cobj == NULL) {
        return;
    }
    if (cobj == NULL) {
        return;
    }
    HSD_AObjReqAnim(cobj->aobj, frame);
    HSD_WObjReqAnim(cobj->eye_position, frame);
    HSD_WObjReqAnim(cobj->interest, frame);
}

static inline s32 makeProjectionMtx(HSD_CObj* cobj, Mtx mtx)
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

BOOL setupTopHalfCamera(HSD_CObj* cobj)
{
    Mtx mtx;
    s32 projection_type;
    f32 h_scale;
    f32 rad;
    f32 t;
    f32 w;
    f32 b;
    f32 top;
    f32 bottom;
    f32 left;
    f32 right;
    f32 width;
    f32 height;

    if (cobj->viewport_top >= CObjRenderMode.efbHeight) {
        return FALSE;
    }

    left = cobj->viewport_left;
    right = cobj->viewport_right;
    top = cobj->viewport_top;
    bottom = cobj->viewport_bottom;
    bottom = bottom < CObjRenderMode.efbHeight ? bottom : CObjRenderMode.efbHeight;
    width = right - left;
    height = bottom - top;
    GXSetScissor(left, top, width, height);

    top = cobj->viewport_top;
    bottom = cobj->viewport_bottom;
    left = cobj->viewport_left;
    right = cobj->viewport_right;
    height = (bottom < CObjRenderMode.efbHeight ? bottom : CObjRenderMode.efbHeight) -
             top;
    h_scale = height / (bottom - top);
    width = right - left;

    GXSetViewport(left, top, width, height, 0.0F, 1.0F);

    switch (cobj->projection_type) {
    case PROJ_PERSPECTIVE:
        rad = DegToRad(0.5 * cobj->projection_param.perspective.fov);
        t = cobj->near * (f32) tan(rad);
        w = t * cobj->projection_param.perspective.aspect;
        b = t * (1.0F - 2.0F * h_scale);
        C_MTXFrustum(mtx, t, b, -w, w, cobj->near, cobj->far);
        projection_type = 0;
        break;
    case PROJ_FRUSTRUM:
        C_MTXFrustum(mtx, cobj->projection_param.frustrum.top,
                     cobj->projection_param.frustrum.top -
                         h_scale * (cobj->projection_param.frustrum.top -
                                    cobj->projection_param.frustrum.bottom),
                     cobj->projection_param.frustrum.left,
                     cobj->projection_param.frustrum.right, cobj->near,
                     cobj->far);
        projection_type = 0;
        break;
    case PROJ_ORTHO:
        C_MTXOrtho(mtx, cobj->projection_param.ortho.top,
                   cobj->projection_param.ortho.top -
                       h_scale * (cobj->projection_param.ortho.top -
                                  cobj->projection_param.ortho.bottom),
                   cobj->projection_param.ortho.left,
                   cobj->projection_param.ortho.right, cobj->near, cobj->far);
        projection_type = 1;
        break;
    }
    GXSetProjection(mtx, projection_type);
    return TRUE;
}

BOOL setupBottomHalfCamera(HSD_CObj* cobj)
{
    Mtx mtx;
    s32 projection_type;
    u32 screen_top;
    f32 h_scale;
    f32 rad;
    f32 t;
    f32 w;
    f32 top_frustum;
    f32 top;
    f32 bottom;
    f32 left;
    f32 right;
    f32 width;
    f32 height;
    f32 h;

    screen_top = CObjRenderMode.efbHeight - 8;
    if (cobj->viewport_bottom < screen_top) {
        return FALSE;
    }

    top = cobj->scissor_top;
    left = cobj->scissor_left;
    right = cobj->scissor_right;
    top = (top > screen_top ? top : screen_top) - screen_top;
    bottom = cobj->scissor_bottom - screen_top;
    width = right - left;
    height = bottom - top;
    GXSetScissor(left, top, width, height);

    top = cobj->viewport_top;
    left = cobj->viewport_left;
    right = cobj->viewport_right;
    top = top > screen_top ? top : screen_top;
    bottom = cobj->viewport_bottom;
    width = right - left;
    height = bottom - cobj->viewport_top;

    top = top - screen_top;
    h = (bottom - screen_top) - top;
    h_scale = h / height;
    GXSetViewport(left, top, width, h, 0.0F, 1.0F);

    switch (cobj->projection_type) {
    case PROJ_PERSPECTIVE:
        rad = DegToRad(0.5 * cobj->projection_param.perspective.fov);
        t = cobj->near * (f32) tan(rad);
        w = t * cobj->projection_param.perspective.aspect;
        top_frustum = t * __fmadds(2.0F, h_scale, -1.0F);
        C_MTXFrustum(mtx, top_frustum, -t, -w, w, cobj->near, cobj->far);
        projection_type = 0;
        break;
    case PROJ_FRUSTRUM:
        projection_type = 0;
        C_MTXFrustum(mtx,
                     __fmadds(h_scale,
                              cobj->projection_param.frustrum.top -
                                  cobj->projection_param.frustrum.bottom,
                              cobj->projection_param.frustrum.bottom),
                     cobj->projection_param.frustrum.bottom,
                     cobj->projection_param.frustrum.left,
                     cobj->projection_param.frustrum.right, cobj->near,
                     cobj->far);
        break;
    case PROJ_ORTHO:
        projection_type = 1;
        C_MTXOrtho(mtx,
                   __fmadds(h_scale,
                            cobj->projection_param.ortho.top -
                                cobj->projection_param.ortho.bottom,
                            cobj->projection_param.ortho.bottom),
                   cobj->projection_param.ortho.bottom,
                   cobj->projection_param.ortho.left,
                   cobj->projection_param.ortho.right, cobj->near, cobj->far);
        break;
    }
    GXSetProjection(mtx, projection_type);
    return TRUE;
}

static inline s32 vec_normalize_check_inline(Vec* src, Vec* dst)
{
    if (src == NULL || dst == NULL) {
        return -1;
    }
    if (vec_is_zero(src)) {
        return -1;
    }
    PSVECNormalize(src, dst);
    return 0;
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
        vec_normalize_check_inline(&cobj->eye_vector, &cobj->eye_vector);
        cobj->eye_position->flags &= ~2;
        cobj->interest->flags &= ~2;
        HSD_CObjClearFlags(cobj, COBJ_MTX_DIRTY);
        HSD_CObjSetFlags(cobj, COBJ_INV_DIRTY);
    }
}

static char CObjUnknownRenderPass[] = "unkown type of render pass.\n";

char CObjAssertEyePos[] = "cobj->eyepos";
char CObjAssertInterest[] = "cobj->interest";

BOOL HSD_CObjSetCurrent(HSD_CObj* cobj)
{
    Mtx mtx;
    s32 projection_type;
    s32 pass;
    BOOL result;
    f64 x_scale;
    f64 y_scale;
    f32 left;
    f32 top;
    f32 width;
    f32 height;

    if (cobj == NULL) {
        return FALSE;
    }

    pass = HSD_GetCurrentRenderPass();
    _HSD_ZListClear();
    CObjCurrent = cobj;
    result = TRUE;

    switch (pass) {
    case 0:
        x_scale = CObjRenderMode.fbWidth / (f64) CObjRefWidth;
        y_scale = CObjRenderMode.efbHeight / (f64) CObjRefHeight;
        left = cobj->viewport_left * x_scale;
        top = cobj->viewport_top * y_scale;
        width = cobj->viewport_right * x_scale - left;
        height = cobj->viewport_bottom * y_scale - top;
        if (CObjRenderMode.field_rendering) {
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
        result = setupTopHalfCamera(cobj);
        break;
    case 2:
        result = setupBottomHalfCamera(cobj);
        break;
    case 3:
        GXSetViewport(cobj->viewport_left, cobj->viewport_top,
                      cobj->viewport_right - cobj->viewport_left,
                      cobj->viewport_bottom - cobj->viewport_top, 0.0F, 1.0F);
        GXSetScissor(cobj->scissor_left, cobj->scissor_top,
                     cobj->scissor_right - cobj->scissor_left,
                     cobj->scissor_bottom - cobj->scissor_top);
        projection_type = makeProjectionMtx(cobj, mtx);
        GXSetProjection(mtx, projection_type);
        break;
    default:
        HSD_Panic(kar_srcfile_cobj_c, 0x29C, CObjUnknownRenderPass);
        return FALSE;
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
    ASSERT_COBJ(0x2C1);
    return cobj->interest;
}

HSD_WObj* HSD_CObjGetEyePositionWObj(HSD_CObj* cobj)
{
    ASSERT_COBJ(0x2D9);
    return cobj->eye_position;
}

void HSD_CObjGetInterest(HSD_CObj* cobj, Vec* interest)
{
    ASSERT_COBJ(0x2F1);
    HSD_WObjGetPosition(HSD_CObjGetInterestWObj(cobj), interest);
}

void HSD_CObjSetInterest(HSD_CObj* cobj, Vec* interest)
{
    ASSERT_COBJ(0x2FD);
    HSD_WObjSetPosition(HSD_CObjGetInterestWObj(cobj), interest);
}

void HSD_CObjGetEyePosition(HSD_CObj* cobj, Vec* position)
{
    ASSERT_COBJ(0x309);
    HSD_WObjGetPosition(HSD_CObjGetEyePositionWObj(cobj), position);
}

void HSD_CObjSetEyePosition(HSD_CObj* cobj, Vec* position)
{
    ASSERT_COBJ(0x315);
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
    return vec_normalize_check_inline(eye, eye) == 0;
}

f32 HSD_CObjGetEyeDistance(HSD_CObj* cobj)
{
    Vec pos;
    Vec interest;
    Vec eye;

    if (cobj == NULL) {
        return 0.0F;
    }
    if (cobj->eye_position == NULL) {
        __assert(kar_srcfile_cobj_c, 0x352, CObjAssertEyePos);
    }
    if (cobj->interest == NULL) {
        __assert(kar_srcfile_cobj_c, 0x353, CObjAssertInterest);
    }
    HSD_CObjGetEyePosition(cobj, &pos);
    HSD_CObjGetInterest(cobj, &interest);
    PSVECSubtract(&interest, &pos, &eye);
    return PSVECMag(&eye);
}

static Vec CObjZeroVector = { 0.0F, 0.0F, 0.0F };
static Vec CObjUnitYVector = { 0.0F, 1.0F, 0.0F };

f32 upvec2roll(HSD_CObj* cobj, Vec* up)
{
    Vec eye;
    Vec v;
    Mtx mtx;
    f32 dot;

    if (!HSD_CObjGetEyeVector(cobj, &eye)) {
        return 0.0F;
    }
    dot = 1.0F - __fabs(PSVECDotProduct(up, &eye));
    if (dot < HSD_FloatMin[0]) {
        return 0.0F;
    }
    C_MTXLookAt(mtx, &CObjZeroVector, &CObjUnitYVector, &eye);
    PSMTXMultVecSR(mtx, up, &v);
    if (v.y == 0.0F) {
        if (-v.x >= 0.0F) {
            return 1.5707964F;
        }
        return -1.5707964F;
    }
    return kar_atan2(-v.x, v.y);
}

s32 roll2upvec(HSD_CObj* cobj, Vec* up, f32 roll)
{
    Vec eye;
    Vec v0;
    Vec v1;
    Mtx mtx;

    if (!HSD_CObjGetEyeVector(cobj, &eye)) {
        return FALSE;
    }
    if (1.0 - __fabs(eye.y) < 0.0001) {
        v0.x = cobj_sqrtf(eye.y * eye.y + eye.z * eye.z);
        v0.y = eye.y * (-eye.x / v0.x);
        v0.z = eye.z * (-eye.x / v0.x);
    } else {
        v0.y = cobj_sqrtf(eye.x * eye.x + eye.z * eye.z);
        v0.x = eye.x * (-eye.y / v0.y);
        v0.z = eye.z * (-eye.y / v0.y);
    }
    kar_grcoll__near_803d1908(mtx, &eye, -roll);
    PSMTXMultVecSR(mtx, &v0, &v1);
    PSVECNormalize(&v1, up);
    return TRUE;
}

#pragma push
#pragma dont_inline on
s32 HSD_CObjGetUpVector(HSD_CObj* cobj, Vec* up)
{
    if (cobj == NULL || up == NULL) {
        return FALSE;
    }
    if (cobj->flags & 1) {
        *up = cobj->u.up;
        return TRUE;
    }
    return roll2upvec(cobj, up, cobj->u.roll);
}
#pragma pop

void HSD_CObjSetUpVector(HSD_CObj* cobj, Vec* up)
{
    Vec normalized;

    if (cobj == NULL || up == NULL) {
        return;
    }
    if (cobj->flags & 1) {
        if (vec_normalize_check_inline(up, &normalized) != 0) {
            OSReport("illegal up vector.");
            __assert(kar_srcfile_cobj_c, 0x3E3, CObjAssertZero);
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

static char lbl_dead_805300XX_hsdIsDescendantOf[] =
    "hsdIsDescendantOf(info, &hsdCObj)";

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
        return vec_normalize_check_inline(left, left) == 0;
    }
    return FALSE;
}

void HSD_CObjSetMtxDirty(HSD_CObj* cobj)
{
    cobj->flags |= COBJ_MTX_DIRTY | COBJ_INV_DIRTY;
}

BOOL HSD_CObjMtxIsDirty(HSD_CObj* cobj)
{
    return (cobj->flags & COBJ_MTX_DIRTY) ||
           (cobj->eye_position != NULL && (cobj->eye_position->flags & 2)) ||
           (cobj->interest != NULL && (cobj->interest->flags & 2));
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
        PSMTXInverse(cobj->view_mtx, cobj->proj_mtx);
        HSD_CObjClearFlags(cobj, COBJ_INV_DIRTY);
    }
    return cobj->proj_mtx;
}

#pragma push
#pragma dont_inline on
MtxPtr HSD_CObjGetViewingMtxPtr(HSD_CObj* cobj)
{
    HSD_CObjSetupViewingMtx(cobj);
    return cobj->view_mtx;
}
#pragma pop

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

s32 vec_normalize_check(Vec* src, Vec* dst)
{
    if (src == NULL || dst == NULL) {
        return -1;
    }
    if (vec_is_zero(src)) {
        return -1;
    }
    PSVECNormalize(src, dst);
    return 0;
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
    if (cobj == NULL || cobj->projection_type != PROJ_PERSPECTIVE) {
        return;
    }
    cobj->projection_param.perspective.fov = fov;
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
    if (cobj == NULL || cobj->projection_type != PROJ_PERSPECTIVE) {
        return;
    }
    cobj->projection_param.perspective.aspect = aspect;
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
    return CObjCurrent;
}

HSD_CObj* HSD_CObjAlloc(void)
{
    HSD_CObj* cobj;

    cobj = hsdNew((HSD_ClassInfo*) (CObjDefaultClass != NULL ? CObjDefaultClass
                                                           : &hsdCObj));
    ASSERT_COBJ(0x7A3);
    return cobj;
}

static inline void CObjResetFlags(HSD_CObj* cobj, u32 flags)
{
    if (cobj == NULL) {
        return;
    }
    cobj->flags = (cobj->flags & (COBJ_MTX_DIRTY | COBJ_INV_DIRTY)) |
                  (flags & ~(COBJ_MTX_DIRTY | COBJ_INV_DIRTY));
}

int CObjLoad(HSD_CObj* cobj, HSD_CObjDesc* desc)
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
            HSD_CObjSetUpVector(cobj, &CObjDefaultUpVector);
        }
    } else {
        HSD_CObjSetRoll(cobj, desc->roll);
    }

    switch (desc->projection_type) {
    case PROJ_PERSPECTIVE:
    {
        f32 fov = desc->projection_param.perspective.fov;
        f32 aspect = desc->projection_param.perspective.aspect;
        if (cobj != NULL) {
            cobj->projection_type = PROJ_PERSPECTIVE;
            cobj->projection_param.perspective.fov = fov;
            cobj->projection_param.perspective.aspect = aspect;
        }
        break;
    }
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
        __assert(kar_srcfile_cobj_c, 0x7D1, CObjAssertZero);
        break;
    }
    return 0;
}

HSD_CObj* HSD_CObjLoadDesc(HSD_CObjDesc* desc)
{
    HSD_ClassInfo* info;
    HSD_CObj* cobj;

    if (desc != NULL) {
        if (desc->class_name == NULL ||
            (info = hsdSearchClassInfo(desc->class_name)) == NULL) {
            cobj = HSD_CObjAlloc();
        } else {
            cobj = hsdNew(info);
            ASSERT_COBJ(0x7F8);
        }
        HSD_COBJ_METHOD(cobj)->load(cobj, desc);
        return cobj;
    }
    return NULL;
}

int CObjInit(HSD_Class* obj)
{
    HSD_CObj* cobj;
    s32 result;

    result = HSD_OBJECT_PARENT_INFO(&hsdCObj)->init(obj);
    if (result < 0) {
        return result;
    }

    cobj = (HSD_CObj*) obj;
    if (cobj != NULL) {
        HSD_CObjSetMtxDirty(cobj);
    }
    cobj->eye_position = HSD_WObjAlloc();
    cobj->interest = HSD_WObjAlloc();
    return 0;
}

static inline bool ref_DEC(void* o)
{
    bool ret;
    if ((ret = (HSD_OBJ(o)->ref_count == HSD_OBJ_NOREF))) {
        return ret;
    }
    return HSD_OBJ(o)->ref_count-- == 0;
}

void CObjRelease(HSD_Class* obj)
{
    HSD_CObj* cobj;
    HSD_WObj* eye_position;
    HSD_WObj* interest;

    cobj = (HSD_CObj*) obj;
    HSD_AObjRemove(cobj->aobj);
    eye_position = HSD_CObjGetEyePositionWObj(cobj);
    if (eye_position != NULL) {
        if (ref_DEC(eye_position) && eye_position != NULL) {
            HSD_CLASS_METHOD(eye_position)->release((HSD_Class*) eye_position);
            HSD_CLASS_METHOD(eye_position)->destroy((HSD_Class*) eye_position);
        }
    }
    interest = HSD_CObjGetInterestWObj(cobj);
    if (interest != NULL) {
        if (ref_DEC(interest) && interest != NULL) {
            HSD_CLASS_METHOD(interest)->release((HSD_Class*) interest);
            HSD_CLASS_METHOD(interest)->destroy((HSD_Class*) interest);
        }
    }
    if (cobj->proj_mtx != NULL) {
        HSD_MtxFree(cobj->proj_mtx);
    }
    HSD_OBJECT_PARENT_INFO(&hsdCObj)->release(obj);
}

void CObjAmnesia(HSD_ClassInfo* info)
{
    if (info == HSD_CLASS_INFO(CObjDefaultClass)) {
        CObjDefaultClass = NULL;
    }
    if (info == HSD_CLASS_INFO(&hsdCObj)) {
        CObjCurrent = NULL;
    }
    HSD_OBJECT_PARENT_INFO(&hsdCObj)->amnesia(info);
}

Vec CObjDefaultUpVector = { 0.0F, 1.0F, 0.0F };

void CObjInfoInit(void)
{
    hsdInitClassInfo(HSD_CLASS_INFO(&hsdCObj), &hsdObj,
                     "sysdolphin_base_library", "hsd_cobj",
                     sizeof(HSD_CObjInfo), sizeof(HSD_CObj));
    HSD_CLASS_INFO(&hsdCObj)->init = CObjInit;
    HSD_CLASS_INFO(&hsdCObj)->release = CObjRelease;
    HSD_CLASS_INFO(&hsdCObj)->amnesia = CObjAmnesia;
    hsdCObj.load = CObjLoad;
    hsdCObj.update = CObjUpdateFunc;
}

HSD_ObjAllocData* HSD_FObjGetAllocData(void)
{
    return &hsdFObj_alloc_data;
}
