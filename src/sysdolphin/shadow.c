#include <sysdolphin/shadow.h>

#include <sysdolphin/cobj.h>
#include <sysdolphin/mobj.h>
#include <sysdolphin/tobj.h>

void HSD_CObjSetScissorx4(struct _HSD_CObj*, s32, u16, s32, u16);        /* extern */
void HSD_CObjSetViewportfx4(struct _HSD_CObj*, f32, f32, f32, f32);      /* extern */
void* HSD_Alloc(s32);
s32 kar_shadow__803cd5b0(u16, u16, s32, s32, s32);        /* GXGetTexBufferSize */

void makeMatrix(HSD_Shadow* shadow);

extern char lbl_805DCD18[7]; /* "shadow" */
extern char lbl_805DCD20[2]; /* "0" */
extern char lbl_805DCD24[5]; /* "rect" */

extern const f32 lbl_805E5DC0; /* 0.0F */

#define ASSERT_STR(line, cond, str) ((cond) ? ((void) 0) : __assert(__FILE__, line, str))

void HSD_ShadowInit(HSD_Shadow* shadow)
{
    HSD_ImageDesc* imagedesc;

    ASSERT_STR(0xF5, shadow, lbl_805DCD18);
    imagedesc = shadow->texture->imagedesc;
    GXSetTexCopySrc(0, 0, imagedesc->width, imagedesc->height);
    GXSetTexCopyDst(imagedesc->width, imagedesc->height, 32, 0);
}

void HSD_ShadowSetSize(HSD_Shadow* shadow, u16 width, u16 height)
{
    u32 size;
    HSD_ImageDesc* imgdesc;

    ASSERT_STR(0x115, shadow, lbl_805DCD18);
    assert_line(0x116, width > 0);
    assert_line(0x117, height > 0);

    imgdesc = shadow->texture->imagedesc;
    if (imgdesc->img_ptr == NULL || imgdesc->width != width || imgdesc->height != height) {
        if (imgdesc->img_ptr != NULL) {
            HSD_Free(imgdesc->img_ptr);
        }
        size = kar_shadow__803cd5b0(width, height, 0, 0, 0);
        assert_line(0x122, size > 0);

        imgdesc->img_ptr = HSD_Alloc(size);
        imgdesc->width = width;
        imgdesc->height = height;
        HSD_CObjSetViewportfx4(shadow->camera, lbl_805E5DC0, width, lbl_805E5DC0, height);
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

extern Mtx lbl_80503FC0;
extern f32 lbl_805DC8C0[];

extern struct {
    u8 x0_pad[0xC];
    s32 unkC;
} lbl_80504418;

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

f32 lbl_805E5DD0 = 1.0F;
f32 lbl_805E5DD4 = -1.0F;

void HSD_ShadowStartRender(HSD_Shadow* shadow)
{
    Mtx44 sp8;
    HSD_Chan* chan;
    HSD_CObj* camera;
    u8 temp_r0;
    HSD_ImageDesc* imgdesc;
    HSD_SList* var_r26;

    ASSERT_STR(0x159, shadow, lbl_805DCD18);
    assert_line(0x15A, shadow->camera);
    assert_line(0x15B, shadow->texture);
    assert_line(0x15C, shadow->texture->imagedesc);

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
        C_MTXOrtho(&sp8, lbl_805E5DD0, lbl_805E5DC0, lbl_805E5DC0, lbl_805E5DD0, lbl_805E5DD4, lbl_805E5DD0);
        GXSetProjection(&sp8, 1);
        GXSetViewport(lbl_805E5DC0, lbl_805E5DC0, imgdesc->width, imgdesc->height, lbl_805E5DC0, lbl_805E5DD0);
        GXSetScissor(0, 0, imgdesc->width, imgdesc->height);
        GXLoadPosMtxImm(&lbl_80503FC0, 0);
        GXSetCurrentMtx(0, lbl_80504418.unkC++, &lbl_80504418);
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
        if (shadow->objects != NULL && HSD_CObjGetEyeDistance(camera) >= lbl_805DC8C0[0] && HSD_CObjSetCurrent(camera)) {
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
    ASSERT_STR(0x1ED, shadow, lbl_805DCD18);
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
    ASSERT_STR(0x23A, shadow, lbl_805DCD18);
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

HSD_SList* HSD_SListRemove(HSD_SList*);

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

extern void PSMTXCopy(Mtx src, Mtx dst);
extern void PSMTXConcat(Mtx a, Mtx b, Mtx ab);
void C_MTXLightPerspective(Mtx, f32, f32, f32, f32, f32, f32);
void C_MTXLightFrustum(Mtx, f32, f32, f32, f32, f32, f32, f32, f32, f32);
void C_MTXLightOrtho(Mtx, f32, f32, f32, f32, f32, f32, f32, f32);

Mtx lbl_80504678 = {
    { 0.0F, 0.0F, 0.0F, 0.0F },
    { 0.0F, 0.0F, 0.0F, 0.0F },
    { 0.0F, 0.0F, 0.0F, 1.0F },
};

void makeMatrix(HSD_Shadow* shadow)
{
    Mtx Mprj;

    if (HSD_CObjGetEyeDistance(shadow->camera) < lbl_805DC8C0[0]) {
        PSMTXCopy(lbl_80504678, shadow->texture->mtx);
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
        ASSERT_STR(0x2BB, 0, lbl_805DCD20);
    }

    PSMTXConcat(Mprj, shadow->camera->view_mtx, shadow->texture->mtx);
}

f32 fn_803BD3C8(f32, f32); /* atan2f */

f32 lbl_805E5DD8 = 57.29578F;

void HSD_ShadowSetViewingRect(HSD_Shadow* shadow, f32 top, f32 bottom, f32 left, f32 right)
{
    HSD_CObj* camera;
    f32 distance;

    ASSERT_STR(0x2D2, shadow, lbl_805DCD18);

    camera = shadow->camera;
    distance = HSD_CObjGetEyeDistance(camera);
    if (distance < lbl_805DC8C0[0]) {
        return;
    }

    switch (HSD_CObjGetProjectionType(camera)) {
    case PROJ_PERSPECTIVE: {
        f32 width, height;

        if (__fabs(top) > __fabs(bottom)) {
            width = __fabs(top);
        } else {
            width = __fabs(bottom);
        }
        if (__fabs(left) > __fabs(right)) {
            height = __fabs(left);
        } else {
            height = __fabs(right);
        }
        HSD_CObjSetAspect(camera, height / (width + lbl_805DC8C0[0]));
        HSD_CObjSetFov(camera, fn_803BD3C8(width, distance) * lbl_805E5DD8);
    } break;

    case PROJ_FRUSTRUM: {
        f32 scale = HSD_CObjGetNear(camera) / distance;
        if (scale < lbl_805DC8C0[0]) {
            scale = lbl_805DC8C0[0];
        }
        HSD_CObjSetFrustum(camera, scale * top, scale * bottom, scale * left, scale * right);
    } break;

    case PROJ_ORTHO:
        HSD_CObjSetOrtho(camera, top, bottom, left, right);
        break;

    default:
        ASSERT_STR(0x2FF, 0, lbl_805DCD20);
    }
}

extern void PSVECSubtract(Vec* a, Vec* b, Vec* dst);
extern void PSVECNormalize(Vec* src, Vec* dst);
extern f32 PSVECMag(Vec* vec);
extern f32 PSVECDotProduct(Vec* a, Vec* b);
extern void PSVECCrossProduct(Vec* a, Vec* b, Vec* dst);
extern void PSVECScale(f32 scale, Vec* src, Vec* dst);
void HSD_VecGetOrthogonal(Vec*, Vec*);

extern f32 lbl_805DC8B8[]; /* epsilon: direction-normalize threshold */
f32 lbl_805E5DDC = -3.4028235E38F; /* -FLT_MAX */
f32 lbl_805E5DE0[2] = { 3.4028235E38F, 0.0F }; /* +FLT_MAX */

static inline BOOL TryNormalizeChecked(Vec* src, Vec* dst)
{
    if (src == NULL || dst == NULL) {
        return ~0;
    }
    if (__fabs(src->x) <= lbl_805DC8B8[0] && __fabs(src->y) <= lbl_805DC8B8[0] &&
        __fabs(src->z) <= lbl_805DC8B8[0]) {
        return ~0;
    }
    PSVECNormalize(src, dst);
    return 0;
}

void HSD_ViewingRectInit(HSD_ViewingRect* rect, Vec* position, Vec* interest, Vec* upvector, s32 perspective)
{
    ASSERT_STR(0x31E, rect, lbl_805DCD24);

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

    rect->top = rect->right = lbl_805E5DDC;
    rect->bottom = rect->left = lbl_805E5DE0[0];
    rect->perspective = perspective != 0;
}

s32 HSD_ViewingRectCheck(HSD_ViewingRect* rect)
{
    ASSERT_STR(0x33C, rect, lbl_805DCD24);
    if (rect->invalid) {
        return 0;
    }
    return rect->top > rect->bottom && rect->right > rect->left;
}

void HSD_ViewingRectAddRect(HSD_ViewingRect* rect, Vec* position, f32 top, f32 bottom, f32 left, f32 right)
{
    f32 x, y, dot;
    Vec o2p, e2p;

    ASSERT_STR(0x362, rect, lbl_805DCD24);
    assert_line(0x363, position);

    if (rect->invalid) {
        return;
    }

    PSVECSubtract(position, &rect->origin, &o2p);
    dot = PSVECDotProduct(&o2p, &rect->eye_vn);
    if (rect->perspective) {
        f32 scale;

        if (dot <= lbl_805E5DC0) {
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
