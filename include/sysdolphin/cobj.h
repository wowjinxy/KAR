#ifndef _cobj_h_
#define _cobj_h_

#include <dolphin/types.h>

#include <sysdolphin/object.h>
#include <sysdolphin/aobj.h>
#include <sysdolphin/wobj.h>

#define PROJ_PERSPECTIVE 1
#define PROJ_FRUSTRUM 2
#define PROJ_ORTHO 3

typedef struct _Scissor {
    u16 left;
    u16 right;
    u16 top;
    u16 bottom;
} Scissor;

typedef struct _HSD_RectS16 {
    s16 xmin;
    s16 xmax;
    s16 ymin;
    s16 ymax;
} HSD_RectS16;

typedef struct _HSD_RectF32 {
    f32 xmin;
    f32 xmax;
    f32 ymin;
    f32 ymax;
} HSD_RectF32;

typedef struct _HSD_CObj {
    HSD_Obj parent;
    u32 flags; //0x08
    union {
        struct {
            f32 viewport_left; //0x0C
            f32 viewport_right; //0x10
            f32 viewport_top; //0x14
            f32 viewport_bottom; //0x18
        };
        HSD_RectF32 viewport;
    };
    union {
        struct {
            u16 scissor_left; //0x1C
            u16 scissor_right; //0x1E
            u16 scissor_top; //0x20
            u16 scissor_bottom; //0x22
        };
        Scissor scissor;
    };
    struct _HSD_WObj* eye_position; //0x24
    struct _HSD_WObj* interest; //0x28
    union {
        f32 roll; //0x2C
        Vec up; //0x2C - 0x34
    } u;
    f32 near; //0x38
    f32 far; //0x3C
    union {
        struct {
            f32 fov;
            f32 aspect;
        } perspective;

        struct {
            f32 top;
            f32 bottom;
            f32 left;
            f32 right;
        } frustrum;

        struct {
            f32 top;
            f32 bottom;
            f32 left;
            f32 right;
        } ortho;
    } projection_param;
    u8 projection_type; //0x50
    Mtx view_mtx; //0x54
    struct _HSD_AObj* aobj; //0x84
    MtxPtr proj_mtx; //0x88
    Vec eye_vector; //0x8C
    u32 unk_98; //0x98, no observed xrefs; class size is 0x9C
} HSD_CObj;

typedef struct _HSD_CObjDesc {
    char* class_name; //0x00
    u16 flags; //0x04
    u16 projection_type; //0x06
    union {
        struct {
            s16 viewport_left; //0x08
            s16 viewport_right; //0x0A
            s16 viewport_top; //0x0C
            s16 viewport_bottom; //0x0E
        };
        HSD_RectS16 viewport;
    };
    union {
        struct {
            u16 scissor_left; //0x10
            u16 scissor_right; //0x12
            u16 scissor_top; //0x14
            u16 scissor_bottom; //0x16
        };
        struct {
            u32 scissor_lr; //0x10
            u32 scissor_tb; //0x14
        };
        Scissor scissor;
    };
    struct _HSD_WObjDesc* eye_desc; //0x18
    struct _HSD_WObjDesc* interest_desc; //0x1C
    f32 roll; //0x20
    Vec* vector; //0x24
    f32 near; //0x28
    f32 far; //0x2C
    union {
        struct {
            f32 fov;
            f32 aspect;
        } perspective;

        struct {
            f32 top;
            f32 bottom;
            f32 left;
            f32 right;
        } frustrum;

        struct {
            f32 top;
            f32 bottom;
            f32 left;
            f32 right;
        } ortho;
    } projection_param;
} HSD_CObjDesc;

typedef struct _HSD_CObjInfo {
    HSD_ObjInfo parent;
    int (*load)(HSD_CObj* cobj, HSD_CObjDesc* desc);
} HSD_CObjInfo;

typedef struct _HSD_CameraAnim {
    struct _HSD_AObjDesc* aobjdesc;
    struct _HSD_WObjAnim* eye_anim;
    struct _HSD_WObjAnim* interest_anim;
} HSD_CameraAnim;

#define HSD_COBJ_INFO(i) ((HSD_CObjInfo*)(i))
#define HSD_COBJ_METHOD(o) HSD_COBJ_INFO(HSD_OBJECT_METHOD(o))

void HSD_CObjEraseScreen(HSD_CObj* cobj, s32 enable_color, s32 enable_alpha, s32 enable_depth);
void HSD_CObjSetViewportScale(HSD_CObj* cobj, s32 color_update, s32 alpha_update, s32 tex_enable);
void HSD_CObjRemoveAnim(HSD_CObj* cobj);
HSD_WObj* HSD_CObjGetEyePositionWObj(HSD_CObj* cobj);
HSD_WObj* HSD_CObjGetInterestWObj(HSD_CObj* cobj);
void HSD_CObjGetEyePosition(HSD_CObj* cobj, Vec* position);
void HSD_CObjSetEyePosition(HSD_CObj* cobj, Vec* position);
void HSD_CObjGetInterest(HSD_CObj* cobj, Vec* interest);
void HSD_CObjSetInterest(HSD_CObj* cobj, Vec* interest);
s32 HSD_CObjGetEyeVector(HSD_CObj* cobj, Vec* eye);
f32 HSD_CObjGetEyeDistance(HSD_CObj* cobj);
s32 HSD_CObjGetUpVector(HSD_CObj* cobj, Vec* up);
void HSD_CObjSetUpVector(HSD_CObj* cobj, Vec* up);
s32 HSD_CObjGetLeftVector(HSD_CObj* cobj, Vec* left);
void HSD_CObjSetMtxDirty(HSD_CObj* cobj);
BOOL HSD_CObjMtxIsDirty(HSD_CObj* cobj);
void HSD_CObjGetViewingMtx(HSD_CObj* cobj, Mtx mtx);
MtxPtr HSD_CObjGetInvViewingMtxPtrDirect(HSD_CObj* cobj);
MtxPtr HSD_CObjGetViewingMtxPtr(HSD_CObj* cobj);
void HSD_CObjSetRoll(HSD_CObj* cobj, f32 roll);
f32 HSD_CObjGetFov(HSD_CObj* cobj);
void HSD_CObjSetFov(HSD_CObj* cobj, f32 fov);
f32 HSD_CObjGetAspect(HSD_CObj* cobj);
void HSD_CObjSetAspect(HSD_CObj* cobj, f32 aspect);
f32 HSD_CObjGetNear(HSD_CObj* cobj);
void HSD_CObjSetNear(HSD_CObj* cobj, f32 near);
f32 HSD_CObjGetFar(HSD_CObj* cobj);
void HSD_CObjSetFar(HSD_CObj* cobj, f32 far);
void HSD_CObjGetScissor(HSD_CObj* cobj, Scissor* scissor);
void HSD_CObjSetScissor(HSD_CObj* cobj, Scissor* scissor);
void HSD_CObjSetScissorx4(HSD_CObj* cobj, s32 left, u16 right, s32 top, u16 bottom);
void HSD_CObjGetViewport(HSD_CObj* cobj, HSD_RectS16* viewport);
void HSD_CObjGetViewportf(HSD_CObj* cobj, HSD_RectF32* viewport);
void HSD_CObjSetViewport(HSD_CObj* cobj, HSD_RectS16* viewport);
void HSD_CObjSetViewportf(HSD_CObj* cobj, HSD_RectF32* viewport);
void HSD_CObjSetViewportfx4(HSD_CObj* cobj, f32 left, f32 right, f32 top, f32 bottom);
s32 HSD_CObjGetProjectionType(HSD_CObj* cobj);
void HSD_CObjSetProjectionType(HSD_CObj* cobj, u32 projection_type);
void HSD_CObjSetFrustum(HSD_CObj* cobj, f32 top, f32 bottom, f32 left, f32 right);
void HSD_CObjSetOrtho(HSD_CObj* cobj, f32 top, f32 bottom, f32 left, f32 right);
void HSD_CObjSetFlags(HSD_CObj* cobj, u32 flags);
void HSD_CObjClearFlags(HSD_CObj* cobj, u32 flags);
HSD_CObj* HSD_CObjGetCurrent(void);
HSD_CObj* HSD_CObjAlloc(void);
HSD_CObj* HSD_CObjLoadDesc(HSD_CObjDesc* desc);

#endif
