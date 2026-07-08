#ifndef _sislib_h_
#define _sislib_h_

#include <dolphin/types.h>
#include <dolphin/mtx/mtxtypes.h>
#include <dolphin/gx/gxtypes.h>

#include <sysdolphin/gobj.h>
#include <sysdolphin/cobj.h>
#include <sysdolphin/wobj.h>
#include <sysdolphin/archive.h>

typedef struct _Vec2 {
    f32 x, y;
} Vec2;

typedef struct _Vec4 {
    f32 x, y, z, w;
} Vec4;

typedef struct _TextGlyphTexture {
    u8 data[512];
} TextGlyphTexture;

struct TextKerning {
    u8 left;
    u8 right;
};

typedef struct _SIS {
    TextKerning* kerning;
    TextGlyphTexture* textures;
} SIS;

struct SisBlock {
    SisBlock* next;
    HSD_Text* data;
    u32 size;
};

typedef struct _SisAllocHeader {
    void* x0;
    void* x4;
    u32 x8;
    u32 xC;
} SisAllocHeader;

struct HSD_Text {
    f32 pos_x;
    f32 pos_y;
    f32 pos_z;
    f32 box_size_x;
    f32 box_size_y;
    Vec4 x14;
    Vec2 font_size;
    GXColor bg_color;
    GXColor text_color;
    Vec2 x34;
    Vec2 x3C;
    u16 x44;
    u16 x46;
    u8 default_fitting;
    u8 default_kerning;
    u8 default_alignment;
    u8 x4B;
    u8 x4C;
    u8 hidden;
    u8 x4E;
    u8 font_idx;
    HSD_Text* next;
    HSD_GObj* entity;
    void (*render_callback)(void*);
    SIS* sis_buffer;
    void* x60;
    SisBlock* alloc_data;
    u8* string_buffer;
    u16 x6C;
    u16 x6E;
    f32 current_width;
    f32 current_height;
    Vec2 x78;
    Vec2 x80;
    f32 x88;
    GXColor active_color;
    u16 x90;
    u16 x92;
    u32 x94;
    u32 x98;
    u8 fitting;
    u8 kerning;
    u8 alignment;
    u8 x9F;
};

struct sislib_UnkAlloc3 {
    sislib_UnkAlloc3* x0;
    HSD_GObj* x4;
    u16 x8;
    u16 xA;
    u8 xC;
    u8 xD;
    u8 xE;
    u8 xF;
};

extern SIS* lbl_8059A85C[5];

extern SisBlock* free_head;
extern SisBlock* used_head;
extern HSD_Text* lbl_805DE568;
extern sislib_UnkAlloc3* lbl_805DE56C;

void* HSD_SisLib_Alloc(s32 size);
void HSD_SisLib_Free(void* ptr);
void HSD_SisLib_803A5A2C(void* ptr);
HSD_Text* HSD_SisLib_803A5ACC(int font_idx, s32 context_id, f32 pos_x, f32 pos_y,
                              f32 pos_z, f32 box_w, f32 box_h);
void HSD_SisLib_803A5CC4(HSD_Text* text);
void HSD_SisLib_803A5F50(s32 font_idx);
void HSD_SisLib_803A6048(u32 size);
s32 HSD_SisLib_803A611C(int font_idx, HSD_GObj* parent_gobj, u16 class_id,
                        u8 p_link, u8 p_prio, u8 gx_link, u8 gx_prio,
                        u32 render_prio);
void HSD_SisLib_803A62A0(s32 font_idx, char* archive_name, char* symbol_name);
void HSD_SisLib_803A6368(HSD_Text* text, s32 sis_idx);
HSD_Text* HSD_SisLib_803A6754(int font_idx, s32 context_id);
s32 HSD_SisLib_803A67EC(u8* data, u8* string);
int HSD_SisLib_803A6B98(HSD_Text* text, float x, float y, const char* fmt, ...);
s32 HSD_SisLib_803A70A0(HSD_Text* text, s32 entry_idx, char* fmt, ...);
void HSD_SisLib_803A7548(HSD_Text* text, int entry_idx, float scale_x, float scale_y);
void HSD_SisLib_803A7684(HSD_Text* text, u8* cursor, u8 flags);
s32 HSD_SisLib_803A7F0C(HSD_Text* text, s32 flags);
void HSD_SisLib_803A8134(void* cursor, HSD_Text* text, f32* out_width, f32* out_height);
void HSD_SisLib_803A84BC(HSD_GObj* gobj, s32 pass);

#endif
