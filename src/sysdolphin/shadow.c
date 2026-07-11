#include <sysdolphin/shadow.h>

#include <dolphin/mtx/mtx.h>
#include <dolphin/mtx/vec.h>
#include <sysdolphin/cobj.h>
#include <sysdolphin/list.h>
#include <sysdolphin/mobj.h>
#include <sysdolphin/tobj.h>

void* HSD_Alloc(s32);
s32 GXGetTexBufferSize(u16, u16, s32, s32, s32);

void makeMatrix(HSD_Shadow* shadow);

extern char ShadowAssertShadow[7]; /* "shadow" */
extern char ShadowAssertZero[2]; /* "0" */
extern char ShadowAssertRect[5]; /* "rect" */

extern const f32 ShadowZero; /* 0.0F */

char ShadowSourceFile[] = "shadow.c";

#define ASSERT_STR(line, cond, str) ((cond) ? ((void) 0) : __assert(ShadowSourceFile, line, str))
#define ASSERT_NAMED(line, cond) ((cond) ? ((void) 0) : __assert(ShadowSourceFile, line, #cond))

void HSD_ShadowInit(HSD_Shadow* shadow)
{
    HSD_ImageDesc* imagedesc;

    ASSERT_STR(0xF5, shadow, ShadowAssertShadow);
    imagedesc = shadow->texture->imagedesc;
    GXSetTexCopySrc(0, 0, imagedesc->width, imagedesc->height);
    GXSetTexCopyDst(imagedesc->width, imagedesc->height, 32, 0);
}

void HSD_ShadowSetSize(HSD_Shadow* shadow, u16 width, u16 height)
{
    u32 size;
    HSD_ImageDesc* imgdesc;

    ASSERT_STR(0x115, shadow, ShadowAssertShadow);
    ASSERT_NAMED(0x116, width > 0);
    ASSERT_NAMED(0x117, height > 0);

    imgdesc = shadow->texture->imagedesc;
    if (imgdesc->img_ptr == NULL || imgdesc->width != width || imgdesc->height != height) {
        if (imgdesc->img_ptr != NULL) {
            HSD_Free(imgdesc->img_ptr);
        }
        size = GXGetTexBufferSize(width, height, 0, 0, 0);
        ASSERT_NAMED(0x122, size > 0);

        imgdesc->img_ptr = HSD_Alloc(size);
        imgdesc->width = width;
        imgdesc->height = height;
        HSD_CObjSetViewportfx4(shadow->camera, ShadowZero, width, ShadowZero, height);
        HSD_CObjSetScissorx4(shadow->camera, 0, width, 0, height);
    }
}

typedef struct _HSD_Chan {
    struct _HSD_Chan* next;
    u32 chan;
    u32 flags;
    GXColor amb_color;
    GXColor mat_color;
    u8 enable;
    u32 amb_src;
    u32 mat_src;
    u32 light_mask;
    u32 diff_fn;
    u32 attn_fn;
    struct _HSD_AObj* aobj;
} HSD_Chan;

HSD_Chan channel = {
    NULL, // next
    4,    // chan
    0,    // flags
    { 0 },    // amb_color
    { 0, 0, 0, 255 }, // mat_color
    FALSE, // enable
    0,     // amb_src
    0,     // mat_src
    0,     // light_mask
    2,     // diff_fn
    2,     // attn_fn
};

extern Mtx HSD_IdentityMtx;
extern f32 HSD_FloatEpsilon[];

extern struct {
    u8 x0_pad[0xC];
    s32 unkC;
} HSD_PerfCurrentStat;

struct {
    u32 unused[29];
} tevstage = {
    0,
    1,
    0,
    0xFF,
    0xFF,
    4,
    0,
    15,
    15,
    15,
    10,
    0,
    0,
    0x1000000,
    0,
    0,
    7,
    7,
    7,
    5,
    0,
    0,
    0x1000000,
};

HSD_PEDesc pedesc = {
    9,
    0,
    0,
    0,
    0,
    4,
    5,
    15,
    7,
    7,
    0,
    7,
};


f32 HSD_CObjGetEyeDistance();
void C_MTXOrtho(void*, f32, f32, f32, f32, f32, f32);
void GXSetViewport(f32, f32, f32, f32, f32, f32);

f32 ShadowOne = 1.0F;
f32 ShadowNegOne = -1.0F;

void HSD_ShadowStartRender(HSD_Shadow* shadow)
{
    Mtx44 sp8;
    HSD_Chan* chan;
    HSD_CObj* camera;
    u8 temp_r0;
    HSD_ImageDesc* imgdesc;
    HSD_SList* var_r26;

    ASSERT_STR(0x159, shadow, ShadowAssertShadow);
    ASSERT_NAMED(0x15A, shadow->camera);
    ASSERT_NAMED(0x15B, shadow->texture);
    ASSERT_NAMED(0x15C, shadow->texture->imagedesc);

    camera = shadow->camera;
    imgdesc = shadow->texture->imagedesc;
    if (shadow->active) {
        HSD_StateInitTev();
        HSD_SetupTevStageAll(&tevstage);
        HSD_StateSetNumTexGens();
        HSD_SetupPEMode(0, &pedesc);
        channel.mat_color.r = 0xFF;
        channel.mat_color.g = 0xFF;
        channel.mat_color.b = 0xFF;
        HSD_SetupChannelAll(&channel);
        C_MTXOrtho(&sp8, ShadowOne, ShadowZero, ShadowZero, ShadowOne, ShadowNegOne, ShadowOne);
        GXSetProjection(&sp8, 1);
        GXSetViewport(ShadowZero, ShadowZero, imgdesc->width, imgdesc->height, ShadowZero, ShadowOne);
        GXSetScissor(0, 0, imgdesc->width, imgdesc->height);
        GXLoadPosMtxImm(&HSD_IdentityMtx, 0);
        GXSetCurrentMtx(0, HSD_PerfCurrentStat.unkC++, &HSD_PerfCurrentStat);
        HSD_ClearVtxDesc();
        GXSetVtxDesc(9, 1);
        GXSetVtxAttrFmt(0, 9, 0, 0, 0);
        HSD_StateSetCullMode(2);
        GXBegin(0x80, 0, 4);
        *(s8*) 0xCC008000 = 0;
        *(s8*) 0xCC008000 = 1;
        *(s8*) 0xCC008000 = 1;
        *(s8*) 0xCC008000 = 1;
        *(s8*) 0xCC008000 = 1;
        *(s8*) 0xCC008000 = 0;
        *(s8*) 0xCC008000 = 0;
        *(s8*) 0xCC008000 = 0;
        temp_r0 = shadow->intensity;
        channel.mat_color.r = temp_r0;
        channel.mat_color.g = temp_r0;
        channel.mat_color.b = temp_r0;
        HSD_SetupChannelAll(&channel);
        if (shadow->objects != NULL && HSD_CObjGetEyeDistance(camera) >= HSD_FloatEpsilon[0] && HSD_CObjSetCurrent(camera)) {
            GXSetScissor(2, 2, imgdesc->width - 4, imgdesc->height - 4);
            for (var_r26 = shadow->objects; var_r26 != NULL; var_r26 = var_r26->next) {
                HSD_JObjDispAll(var_r26->data, 0, 5, 0x04000000);
            }
            HSD_CObjEndCurrent();
        }
    }
}

void HSD_ShadowEndRender(HSD_Shadow* shadow)
{
    HSD_ImageDesc* imgdesc;
    ASSERT_STR(0x1ED, shadow, ShadowAssertShadow);
    imgdesc = shadow->texture->imagedesc;
    if (imgdesc->img_ptr == NULL) {
        HSD_ShadowSetSize(shadow, imgdesc->width, imgdesc->height);
    }
    GXCopyTex(imgdesc->img_ptr, 1);
    GXPixModeSync();
    GXInvalidateTexAll();
    makeMatrix(shadow);
}

void HSD_ShadowSetActive(HSD_Shadow *shadow, s32 active)
{
    ASSERT_STR(0x23A, shadow, ShadowAssertShadow);
    // skip if already in requested state
    if (shadow->active && active || !shadow->active && !active) {
        return;
    }

    shadow->active = active;
    if (active) {
        HSD_ImageDesc* imgdesc = shadow->texture->imagedesc;
        if (imgdesc->img_ptr == NULL) {
            HSD_ShadowSetSize(shadow, imgdesc->width, imgdesc->height);
        }
        HSD_MObjAddShadowTexture(shadow->texture);
    } else {
        HSD_MObjDeleteShadowTexture(shadow->texture);
    }
}

HSD_SList* HSD_SListPrepend();

void HSD_ShadowAddObject(HSD_Shadow* shadow, HSD_Obj* obj)
{
    HSD_SList* cur;

    if (shadow == NULL || obj == NULL) {
        return;
    }
    for (cur = shadow->objects; cur != NULL; cur = cur->next) {
        if (cur->data == obj) {
            return;
        }
    }
    shadow->objects = HSD_SListPrepend(shadow->objects, obj);
    if (obj != NULL) {
        obj->ref_count += 1;
        if (obj->ref_count == (u16) -1) {
            __assert("object.h", 0x5D, "HSD_OBJ(o)->ref_count != HSD_OBJ_NOREF");
        }
    }
}

void HSD_ShadowDeleteObject(HSD_Shadow* shadow, struct _HSD_JObj* jobj)
{
    if (shadow == NULL) {
        return;
    }
    if (jobj != NULL) {
        HSD_SList* list = (HSD_SList*) shadow;
        while (list->next != NULL) {
            if (list->next->data == jobj) {
                HSD_JObjUnref(jobj);
                list->next = HSD_SListRemove(list->next);
                break;
            }
            list = list->next;
        }
    } else {
        while (shadow->objects != NULL) {
            HSD_JObjUnref(shadow->objects->data);
            shadow->objects = HSD_SListRemove(shadow->objects);
        }
    }
}

void C_MTXLightPerspective(Mtx, f32, f32, f32, f32, f32, f32);
void C_MTXLightFrustum(Mtx, f32, f32, f32, f32, f32, f32, f32, f32, f32);
void C_MTXLightOrtho(Mtx, f32, f32, f32, f32, f32, f32, f32, f32);

Mtx ShadowProjectionFallbackMtx = {
    { 0.0F, 0.0F, 0.0F, 0.0F },
    { 0.0F, 0.0F, 0.0F, 0.0F },
    { 0.0F, 0.0F, 0.0F, 1.0F },
};

void makeMatrix(HSD_Shadow* shadow)
{
    Mtx Mprj;

    if (HSD_CObjGetEyeDistance(shadow->camera) < HSD_FloatEpsilon[0]) {
        PSMTXCopy(ShadowProjectionFallbackMtx, shadow->texture->mtx);
        return;
    }

    switch (HSD_CObjGetProjectionType(shadow->camera)) {
    case PROJ_PERSPECTIVE:
        C_MTXLightPerspective(Mprj, shadow->camera->projection_param.perspective.fov,
                              shadow->camera->projection_param.perspective.aspect,
                              shadow->scaleS, shadow->scaleT, shadow->transS, shadow->transT);
        break;

    case PROJ_FRUSTRUM:
        C_MTXLightFrustum(Mprj, shadow->camera->projection_param.frustrum.top,
                          shadow->camera->projection_param.frustrum.bottom,
                          shadow->camera->projection_param.frustrum.left,
                          shadow->camera->projection_param.frustrum.right,
                          shadow->camera->near, shadow->scaleS, shadow->scaleT,
                          shadow->transS, shadow->transT);
        break;

    case PROJ_ORTHO:
        C_MTXLightOrtho(Mprj, shadow->camera->projection_param.ortho.top,
                        shadow->camera->projection_param.ortho.bottom,
                        shadow->camera->projection_param.ortho.left,
                        shadow->camera->projection_param.ortho.right,
                        shadow->scaleS, shadow->scaleT, shadow->transS, shadow->transT);
        break;

    default:
        ASSERT_STR(0x2BB, 0, ShadowAssertZero);
    }

    PSMTXConcat(Mprj, shadow->camera->view_mtx, shadow->texture->mtx);
}

f32 kar_atan2(f32, f32); /* atan2f */

f32 ShadowRadToDeg = 57.29578F;

void HSD_ShadowSetViewingRect(HSD_Shadow* shadow, f32 top, f32 bottom, f32 left, f32 right)
{
    HSD_CObj* camera;
    f32 distance;

    ASSERT_STR(0x2D2, shadow, ShadowAssertShadow);

    camera = shadow->camera;
    distance = HSD_CObjGetEyeDistance(camera);
    if (distance < HSD_FloatEpsilon[0]) {
        return;
    }

    switch (HSD_CObjGetProjectionType(camera)) {
    case PROJ_PERSPECTIVE: {
        f32 width, height;

        if (__fabs(bottom) < __fabs(top)) {
            width = __fabs(top);
        } else {
            width = __fabs(bottom);
        }
        if (__fabs(right) < __fabs(left)) {
            height = __fabs(left);
        } else {
            height = __fabs(right);
        }
        HSD_CObjSetAspect(camera, height / (width + HSD_FloatEpsilon[0]));
        HSD_CObjSetFov(camera, kar_atan2(width, distance) * ShadowRadToDeg);
    } break;

    case PROJ_ORTHO:
        HSD_CObjSetOrtho(camera, top, bottom, left, right);
        break;

    case PROJ_FRUSTRUM: {
        f32 scale = HSD_CObjGetNear(camera) / distance;
        if (scale < HSD_FloatEpsilon[0]) {
            scale = HSD_FloatEpsilon[0];
        }
        HSD_CObjSetFrustum(camera, scale * top, scale * bottom, scale * left, scale * right);
    } break;

    default:
        ASSERT_STR(0x2FF, 0, ShadowAssertZero);
    }
}

extern void PSVECScale(f32 scale, Vec* src, Vec* dst);
void HSD_VecGetOrthogonal(Vec*, Vec*);

extern f32 HSD_FloatMin[]; /* direction-normalize threshold */
f32 ShadowNegFloatMax = -3.4028235E38F; /* -FLT_MAX */
f32 ShadowFloatMaxPair[2] = { 3.4028235E38F, 0.0F }; /* +FLT_MAX */

static inline BOOL TryNormalizeChecked(Vec* src, Vec* dst)
{
    if (src == NULL || dst == NULL) {
        return ~0;
    }
    if (__fabs(src->x) <= HSD_FloatMin[0] && __fabs(src->y) <= HSD_FloatMin[0] &&
        __fabs(src->z) <= HSD_FloatMin[0]) {
        return ~0;
    }
    PSVECNormalize(src, dst);
    return 0;
}

void HSD_ViewingRectInit(HSD_ViewingRect* rect, Vec* position, Vec* interest, Vec* upvector, s32 perspective)
{
    ASSERT_STR(0x31E, rect, ShadowAssertRect);

    rect->invalid = 0;
    rect->origin = *position;
    PSVECSubtract(interest, position, &rect->eye_v);
    if (TryNormalizeChecked(&rect->eye_v, &rect->eye_vn) < 0) {
        rect->invalid = 1;
        return;
    }

    PSVECCrossProduct(&rect->eye_vn, upvector, &rect->right_v);
    if (TryNormalizeChecked(&rect->right_v, &rect->right_v) < 0) {
        HSD_VecGetOrthogonal(&rect->eye_vn, &rect->right_v);
        PSVECNormalize(&rect->right_v, &rect->right_v);
    }
    PSVECCrossProduct(&rect->right_v, &rect->eye_vn, &rect->up_v);
    rect->distance = PSVECMag(&rect->eye_v);

    rect->top = rect->right = ShadowNegFloatMax;
    rect->bottom = rect->left = ShadowFloatMaxPair[0];
    rect->perspective = perspective != 0;
}

s32 HSD_ViewingRectCheck(HSD_ViewingRect* rect)
{
    ASSERT_STR(0x33C, rect, ShadowAssertRect);
    return !rect->invalid && rect->top > rect->bottom && rect->right > rect->left;
}

void HSD_ViewingRectAddRect(HSD_ViewingRect* rect, Vec* position, f32 top, f32 bottom, f32 left, f32 right)
{
    f32 x, y, dot;
    Vec o2p, e2p;

    ASSERT_STR(0x362, rect, ShadowAssertRect);
    ASSERT_NAMED(0x363, position);

    if (rect->invalid) {
        return;
    }

    PSVECSubtract(position, &rect->origin, &o2p);
    dot = PSVECDotProduct(&o2p, &rect->eye_vn);
    if (rect->perspective) {
        f32 scale;

        if (dot <= ShadowZero) {
            return;
        }
        scale = rect->distance / dot;
        PSVECScale(scale, &o2p, &o2p);
        PSVECSubtract(&o2p, &rect->eye_v, &e2p);
        x = PSVECDotProduct(&rect->right_v, &e2p);
        y = PSVECDotProduct(&rect->up_v, &e2p);

        top *= scale;
        bottom *= scale;
        left *= scale;
        right *= scale;
    } else {
        Vec tmp;
        PSVECScale(dot, &rect->eye_vn, &tmp);
        PSVECSubtract(&o2p, &tmp, &e2p);
        x = PSVECDotProduct(&rect->right_v, &e2p);
        y = PSVECDotProduct(&rect->up_v, &e2p);
    }

    if (x + right > rect->right) {
        rect->right = x + right;
    }
    if (x + left < rect->left) {
        rect->left = x + left;
    }
    if (y + top > rect->top) {
        rect->top = y + top;
    }
    if (y + bottom < rect->bottom) {
        rect->bottom = y + bottom;
    }
}

#pragma push
#pragma force_active on
static char unused[] = "a > 0.0F";
#pragma pop
