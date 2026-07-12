#include <global.h>

#include <sysdolphin/sislib.h>
#include <sysdolphin/gobjuserdata.h>
#include <sysdolphin/memory.h>
#include <sysdolphin/tev.h>

#include <dolphin/os.h>
#include <stdarg.h>

#define GX_FALSE 0
#define GX_TRUE 1
#define GX_ENABLE 1
#define GX_DISABLE 0
#define GX_NEVER 0
#define GX_LEQUAL 3
#define GX_GREATER 4
#define GX_AOP_OR 1
#define GX_QUADS 0x80
#define GX_VTXFMT0 0
#define GX_VA_POS 9
#define GX_VA_TEX0 13
#define GX_POS_XYZ 1
#define GX_RGBA6 4
#define GX_DIRECT 1
#define GX_TF_I4 0
#define GX_CLAMP 0
#define GX_TEXMAP0 0
#define GX_TEXCOORD0 0
#define GX_TEVSTAGE0 0
#define GX_TG_MTX2x4 1
#define GX_TG_TEX0 4
#define GX_IDENTITY 60
#define GX_PTIDENTITY 125
#define GX_CULL_NONE 0
#define GX_COLOR_NULL 0xFF
#define GX_BM_BLEND 1
#define GX_BL_SRCALPHA 4
#define GX_BL_INVSRCALPHA 5
#define GX_LO_CLEAR 0
#define GX_CC_ZERO 15
#define GX_CC_C0 2
#define GX_TEV_ADD 0
#define GX_TB_ZERO 0
#define GX_CS_SCALE_1 0
#define GX_TEVPREV 0
#define GX_TEVREG0 1
#define GX_CA_ZERO 7
#define GX_CA_TEXA 4
#define GX_CA_A0 1

extern void OSReport(const char*, ...);
extern void OSPanic(const char*, s32, const char*, ...);

extern HSD_GObj* HSD_GObjGXLink(HSD_GObj* gobj, void (*render_cb)(HSD_GObj*, s32),
                                u8 gx_link, u8 priority);
extern HSD_GObj* GObj_SetupGXLinkMax(HSD_GObj* gobj, void (*render_cb)(HSD_GObj*, s32),
                                     u32 priority);
extern void GObj_SetCamera(HSD_GObj* gobj);

extern HSD_Archive* kar_lbarchive__800596b4(char* path);
extern void kar_lbarchive__80059798(HSD_Archive* archive);

HSD_Archive* kar_sislib_load_archive_wrapper(char* path);
void kar_sislib_release_archive_wrapper(HSD_Archive* archive);

extern u8 kar_sislib_romfont_glyphs_i4_32x32[];

#define GX_WGPIPE ((volatile u8*) 0xCC008000)

typedef struct _GXTexObj {
    u32 x[8];
} GXTexObj;

extern void GXInitTexObj(GXTexObj* obj, void* image_ptr, u16 width, u16 height,
                         u32 format, u32 wrap_s, u32 wrap_t, u8 mipmap);
extern void GXLoadTexObj(GXTexObj* obj, u32 id);
extern void GXSetZMode(u32 enable, u32 func, u32 update);
extern void GXSetViewport(f32 left, f32 top, f32 width, f32 height, f32 near, f32 far);
extern void GXSetScissor(u32 left, u32 top, u32 width, u32 height);
extern void C_MTXOrtho(Mtx mtx, f32 top, f32 bottom, f32 left, f32 right, f32 near, f32 far);
extern void GXSetProjection(Mtx mtx, s32 projection_type);
extern void GXSetCurrentMtx(u32 id);
extern void GXLoadPosMtxImm(MtxPtr mtx, u32 id);
extern void GXSetTexCoordGen2(u16 dst_coord, u32 func, u32 src_param, u32 mtx,
                              u32 normalize, u32 pt_texmtx);
extern void GXSetNumChans(u8 n);
extern void GXClearVtxDesc(void);
extern void GXSetCullMode(u32 mode);
extern void GXSetNumTexGens(u32 n);
extern void GXSetNumTevStages(u8 n);
extern void GXSetVtxAttrFmt(u32 vtxfmt, u32 attr, u32 comp_cnt, u32 comp_type, u8 frac);
extern void GXSetVtxDesc(u32 attr, u32 type);
extern void GXSetTevOrder(u8 stage, u32 coord, u32 map, u32 color);
extern void GXSetBlendMode(u32 type, u32 src_factor, u32 dst_factor, u32 op);
extern void GXSetAlphaCompare(u32 comp0, u8 ref0, u32 op, u32 comp1, u8 ref1);
extern void GXSetColorUpdate(u32 enable);
extern void GXSetAlphaUpdate(u32 enable);
extern void GXSetTevColorIn(u8 stage, u32 a, u32 b, u32 c, u32 d);
extern void GXSetTevColorOp(u8 stage, u32 op, u32 bias, u32 scale, u32 clamp, u32 out_reg);
extern void GXSetTevAlphaIn(u8 stage, u32 a, u32 b, u32 c, u32 d);
extern void GXSetTevAlphaOp(u8 stage, u32 op, u32 bias, u32 scale, u32 clamp, u32 out_reg);
extern void GXSetTevColor(u32 id, GXColor color);
extern void GXBegin(u8 prim, u8 vtxfmt, u16 nverts);

static inline void GXPosition3f32(f32 x, f32 y, f32 z)
{
    *(volatile f32*) GX_WGPIPE = x;
    *(volatile f32*) GX_WGPIPE = y;
    *(volatile f32*) GX_WGPIPE = z;
}

static inline void GXTexCoord2f32(f32 s, f32 t)
{
    *(volatile f32*) GX_WGPIPE = s;
    *(volatile f32*) GX_WGPIPE = t;
}

typedef struct _SisCamWObjDesc {
    char* class_name;
    Vec pos;
    struct _SisCamWObjDesc* next;
} SisCamWObjDesc;

static SisCamWObjDesc HSD_SisLib_camera_eye_desc = {
    NULL,
    { 0.0F, 0.0F, 300.0F },
    NULL,
};

static SisCamWObjDesc HSD_SisLib_camera_interest_desc = {
    NULL,
    { 0.0F, 0.0F, 0.0F },
    NULL,
};

typedef struct _SisCamDesc {
    char* class_name;
    u16 flags;
    u16 projection_type;
    s16 viewport_left;
    s16 viewport_right;
    s16 viewport_top;
    s16 viewport_bottom;
    u16 scissor_left;
    u16 scissor_right;
    u16 scissor_top;
    u16 scissor_bottom;
    HSD_WObjDesc* eye_desc;
    HSD_WObjDesc* interest_desc;
    f32 roll;
    Vec* vector;
    f32 near;
    f32 far;
    f32 fov;
    f32 aspect;
} SisCamDesc;

static SisCamDesc HSD_SisLib_camera_desc = {
    NULL,
    0,
    PROJ_ORTHO,
    0, 0x280, 0, 0x1E0,
    0, 0x280, 0, 0x1E0,
    (HSD_WObjDesc*) &HSD_SisLib_camera_eye_desc,
    (HSD_WObjDesc*) &HSD_SisLib_camera_interest_desc,
    0.0F,
    NULL,
    0.1F,
    32768.0F,
    30.0F, 1.3333F,
};

sislib_UnkAlloc3* lbl_805DE56C;
HSD_Text* lbl_805DE568;
SisBlock* used_head;
SisBlock* free_head;
SisBlock* HSD_SisLib_804D796C;
u32 HSD_SisLib_804D7968;

HSD_Archive* lbl_8059A848[5];
SIS* lbl_8059A85C[5];

static inline u8* HSD_SisLib_BytePtr(void* ptr)
{
    return ptr;
}

void* HSD_SisLib_Alloc(s32 size)
{
    SisBlock* best;
    SisBlock* alloc_tail;
    s32 remainder;
    SisBlock* free_cur;
    SisBlock* alloc_cur;
    SisBlock* search;

    best = NULL;
    alloc_tail = NULL;
    free_cur = free_head;
    alloc_cur = used_head;
    if (size == 0) {
        OSReport("ZERO byte alloc\n");
        OSPanic("sislib.c", 0x61, "");
    }
    remainder = size % 4;
    if (remainder != 0) {
        size += 4 - remainder;
    }
    while (alloc_cur != NULL) {
        alloc_tail = alloc_cur;
        alloc_cur = alloc_cur->next;
    }
    for (;;) {
        if (free_cur->size == size) {
            best = free_cur;
            break;
        }
        if (free_cur->size > size) {
            if (best != NULL) {
                if (best->size > free_cur->size) {
                    best = free_cur;
                }
            } else {
                best = free_cur;
            }
        }
        free_cur = free_cur->next;
        if (free_cur == NULL) {
            break;
        }
    }
    if (best == NULL) {
        OSReport("Memory Empty\n");
        OSPanic("sislib.c", 0x7B, "");
    }

    search = free_head;

    if (search == best) {
        int remaining_size;
        u8* data_ptr;
        SisBlock* next_free;

        data_ptr = (u8*) free_head->data;
        next_free = free_head->next;
        remaining_size = size;
        remaining_size = (free_head->size - remaining_size) - (sizeof(SisBlock));
        if (remaining_size < 0) {
            OSReport("Memory Empty\n");
            OSPanic("sislib.c", 0x84, "");
        }

        free_head = (SisBlock*) (data_ptr + size);
        free_head->next = next_free;
        free_head->data = (HSD_Text*) (free_head + 1);
        free_head->size = remaining_size;
        best->size = size;
    } else {
        while (search->next != best) {
            search = search->next;
        }
        search->next = best->next;
    }
    best->next = NULL;
    if (alloc_tail != NULL) {
        alloc_tail->next = best;
    }
    if (used_head == NULL) {
        used_head = best;
    }
    return best->data;
}

void HSD_SisLib_Free(void* ptr)
{
    SisBlock* free_cur;
    SisBlock* free_tail;
    SisBlock* alloc_prev;
    SisBlock* alloc_cur;

    free_cur = free_head;
    free_tail = NULL;
    alloc_cur = used_head;
    alloc_prev = NULL;
    while (alloc_cur != NULL) {
        if (alloc_cur->data == ptr) {
            break;
        }
        alloc_prev = alloc_cur;
        alloc_cur = alloc_cur->next;
    }
    if (alloc_cur == NULL) {
        return;
    }
    if ((u8*) free_cur == ((u8*) alloc_cur->data + alloc_cur->size)) {
        SisBlock* old_next;
        u32 new_size;

        old_next = free_cur->next;
        new_size = free_cur->size + alloc_cur->size + sizeof(SisBlock);

        if (alloc_prev != NULL) {
            alloc_prev->next = alloc_cur->next;
        } else {
            used_head = alloc_cur->next;
        }
        free_head = alloc_cur;
        alloc_cur->next = old_next;
        free_head->data = (HSD_Text*) (free_head + 1);
        free_head->size = new_size;
        return;
    }
    while (free_cur != NULL) {
        free_tail = free_cur;
        free_cur = free_cur->next;
    }
    if (free_tail != NULL) {
        free_tail->next = alloc_cur;
    }
    if (alloc_prev != NULL) {
        alloc_prev->next = alloc_cur->next;
    } else {
        used_head = alloc_cur->next;
    }
    alloc_cur->next = NULL;
}

void HSD_SisLib_803A5A2C(void* ptr)
{
    HSD_Text* next_text;
    SisBlock* alloc;
    HSD_Text* curr;
    HSD_Text* last;

    last = NULL;
    curr = lbl_805DE568;
    while (curr != NULL) {
        next_text = curr->next;
        if (curr == ptr) {
            if (last != NULL) {
                last->next = next_text;
            } else {
                lbl_805DE568 = next_text;
            }
            alloc = curr->alloc_data;
            if (alloc != NULL) {
                if (alloc->data != NULL) {
                    HSD_SisLib_Free(alloc->data);
                }
                HSD_SisLib_Free(curr->alloc_data);
            }
            if (curr->string_buffer != NULL) {
                HSD_SisLib_Free(curr->string_buffer);
            }
            HSD_SisLib_Free(curr);
            return;
        }
        last = curr;
        curr = next_text;
    }
}

HSD_Text* HSD_SisLib_803A5ACC(int font_idx, s32 context_id, f32 pos_x, f32 pos_y,
                              f32 pos_z, f32 box_w, f32 box_h)
{
    HSD_Text* list_cur;
    HSD_Text* list_tail;
    sislib_UnkAlloc3* cam_entry;
    HSD_GObj* gobj;
    int cam_idx;
    HSD_Text* text;

    cam_idx = context_id;
    list_tail = NULL;
    cam_entry = NULL;
    gobj = NULL;
    list_cur = lbl_805DE568;
    if (cam_idx >= 0) {
        cam_entry = lbl_805DE56C;
        while (1) {
            if (cam_entry->xA == font_idx && --cam_idx < 0) {
                break;
            }

            if (cam_entry == NULL) {
                OSReport("unknow camera\n");
                return NULL;
            }
            cam_entry = cam_entry->x0;
        }
        gobj = HSD_GObjCreate(cam_entry->x8, cam_entry->xC, cam_entry->xD);
        HSD_GObjGXLink(gobj, HSD_SisLib_803A84BC, cam_entry->xE, cam_entry->xF);
    }
    while (list_cur != NULL) {
        list_tail = list_cur;
        list_cur = list_cur->next;
    }
    text = HSD_SisLib_Alloc(0xA0);
    if (lbl_805DE568 == NULL) {
        lbl_805DE568 = text;
    }
    if (list_tail != NULL) {
        list_tail->next = text;
    }
    if (gobj != NULL) {
        HSD_GObjUserDataLink(gobj, cam_entry->x8, HSD_SisLib_803A5A2C, text);
    }
    text->next = NULL;
    text->entity = gobj;
    text->pos_x = pos_x;
    text->pos_y = pos_y;
    text->pos_z = pos_z;
    text->box_size_x = box_w;
    text->box_size_y = box_h;
    text->x14.w = 0.0F;
    text->x14.z = 0.0F;
    text->x14.y = 0.0F;
    text->x14.x = 0.0F;
    text->font_size.y = 1.0F;
    text->font_size.x = 1.0F;
    text->alloc_data = NULL;
    text->string_buffer = 0;
    text->sis_buffer = 0;
    text->bg_color.a = 0;
    text->bg_color.b = 0;
    text->bg_color.g = 0;
    text->bg_color.r = 0;
    text->text_color.a = 0xFF;
    text->text_color.b = 0xFF;
    text->text_color.g = 0xFF;
    text->text_color.r = 0xFF;
    text->x34.y = 1.0F;
    text->x34.x = 1.0F;
    text->x3C.y = 0.0F;
    text->x3C.x = 0.0F;
    text->x46 = 0;
    text->x44 = 0;
    text->default_alignment = 0;
    text->default_fitting = 0;
    text->default_kerning = 0;
    text->x6E = 0;
    text->x6C = 0;
    text->x4E = 0;
    text->hidden = 0;
    text->x4C = 0;
    text->render_callback = 0;
    text->font_idx = font_idx;
    return text;
}

void HSD_SisLib_803A5CC4(HSD_Text* text)
{
    HSD_Text* curr = lbl_805DE568;
    while (curr != NULL) {
        HSD_Text* next = curr->next;
        if (curr == text) {
            if (curr->entity != NULL) {
                HSD_GObjDestroy(curr->entity);
                curr->entity = NULL;
            } else {
                HSD_SisLib_803A5A2C(curr);
            }
            return;
        }
        curr = next;
    }
}

void HSD_SisLib_803A5F50(s32 font_idx)
{
    HSD_Archive** archive_ptr;
    HSD_Text* curr;
    sislib_UnkAlloc3* last;
    sislib_UnkAlloc3* cam_curr;

    curr = lbl_805DE568;
    while (curr != NULL) {
        HSD_Text* next = curr->next;
        if (curr->font_idx == font_idx) {
            if (curr->entity != NULL) {
                HSD_GObjDestroy(curr->entity);
                curr->entity = NULL;
            } else {
                HSD_SisLib_803A5A2C(curr);
            }
        }
        curr = next;
    }

    last = NULL;
    cam_curr = lbl_805DE56C;
    while (cam_curr != NULL) {
        sislib_UnkAlloc3* next = cam_curr->x0;
        if (cam_curr->xA == font_idx) {
            if (cam_curr->x4 != NULL) {
                HSD_GObjDestroy(cam_curr->x4);
                cam_curr->x4 = NULL;
            }
            if (last != NULL) {
                last->x0 = next;
            } else {
                lbl_805DE56C = next;
            }
            HSD_SisLib_Free(cam_curr);
        }
        last = cam_curr;
        cam_curr = next;
    }

    archive_ptr = &lbl_8059A848[font_idx];
    if (*archive_ptr != NULL) {
        kar_sislib_release_archive_wrapper(*archive_ptr);
        *archive_ptr = NULL;
        lbl_8059A85C[font_idx] = NULL;
    }
}

void HSD_SisLib_803A6048(u32 size)
{
    int i;

    HSD_SisLib_804D7968 = size;
    used_head = NULL;
    free_head = HSD_SisLib_804D796C = HSD_Alloc(HSD_SisLib_804D7968);
    free_head->next = NULL;
    free_head->data = (HSD_Text*) (free_head + 1);
    free_head->size = HSD_SisLib_804D7968 - 0xC;
    lbl_805DE568 = NULL;
    lbl_805DE56C = NULL;

    for (i = 0; i < 5; i++) {
        lbl_8059A848[i] = NULL;
        lbl_8059A85C[i] = NULL;
    }
}

void fn_8044F644(void* gobj)
{
    sislib_UnkAlloc3* curr = lbl_805DE56C;
    while (curr != NULL) {
        if (curr->x4 == gobj) {
            curr->x4 = 0U;
            return;
        }
        curr = curr->x0;
    }
}

s32 HSD_SisLib_803A611C(int font_idx, HSD_GObj* parent_gobj, u16 class_id,
                        u8 p_link, u8 p_prio, u8 gx_link, u8 gx_prio,
                        u32 render_prio)
{
    sislib_UnkAlloc3* list_tail;
    int count;
    sislib_UnkAlloc3* entry;
    sislib_UnkAlloc3* list_cur;

    list_tail = NULL;
    count = 0;
    list_cur = lbl_805DE56C;
    while (list_cur != NULL) {
        list_tail = list_cur;
        if (list_cur->xA == font_idx) {
            count += 1;
        }
        list_cur = list_cur->x0;
    }
    entry = HSD_SisLib_Alloc(0x10);
    if (lbl_805DE56C == NULL) {
        lbl_805DE56C = entry;
    }
    if (list_tail != NULL) {
        list_tail->x0 = entry;
    }
    entry->x8 = class_id;
    entry->xC = p_link;
    entry->xD = p_prio;
    entry->xE = gx_link;
    entry->xF = gx_prio;
    entry->xA = font_idx;
    entry->x0 = NULL;
    if (parent_gobj != NULL) {
        entry->x4 = NULL;
    } else {
        entry->x4 = HSD_GObjCreate(class_id, p_link, p_prio);
        if (entry->x4 != NULL) {
            HSD_CObj* cobj = HSD_CObjLoadDesc((HSD_CObjDesc*) &HSD_SisLib_camera_desc);
            if (cobj != NULL) {
                HSD_CObjSetOrtho(cobj, 0.0F, -480.0F, 0.0F, 640.0F);
                HSD_GObjObjectLink(entry->x4, hsdGObj_default_object_kind, cobj);
                GObj_SetupGXLinkMax(entry->x4,
                                    (void (*)(HSD_GObj*, s32)) GObj_SetCamera,
                                    render_prio);
                entry->x4->gxlink_prios = (u64) 1 << gx_link;
                HSD_GObjUserDataLink(entry->x4, class_id, fn_8044F644, entry->x4);
            } else {
                HSD_GObjDestroy(entry->x4);
                entry->x4 = NULL;
            }
        }
    }
    return count;
}

void HSD_SisLib_803A62A0(s32 font_idx, char* archive_name, char* symbol_name)
{
    HSD_Archive* tmp = kar_sislib_load_archive_wrapper(archive_name);
    lbl_8059A848[font_idx] = tmp;
    if (tmp == NULL) {
        OSReport("Cannot open archive %s.\n", archive_name);
        OSPanic("sislib.c", 0x26F, "");
    }
    {
        SIS* sis = HSD_ArchiveGetPublicAddress(lbl_8059A848[font_idx],
                                               symbol_name);
        lbl_8059A85C[font_idx] = sis;
        if (sis == NULL) {
            OSReport("Cannot find symbol %s.\n", symbol_name);
            OSPanic("sislib.c", 0x274, "");
        }
    }
}

void HSD_SisLib_803A6368(HSD_Text* text, s32 sis_idx)
{
    SIS** sis_table;
    s32 i;

    sis_table = (SIS**) lbl_8059A85C[text->font_idx];
    if (sis_table != NULL) {
        text->sis_buffer = sis_table[sis_idx];
    }
    text->x60 = NULL;
    text->current_height = 0.0F;
    text->current_width = 0.0F;
    text->active_color = text->text_color;
    text->x80.x = text->x34.x;
    text->x80.y = text->x34.y;
    text->x78.x = text->x3C.x;
    text->x78.y = text->x3C.y;
    text->x90 = text->x44;
    text->x92 = text->x46;
    text->alignment = text->default_alignment;
    text->kerning = text->default_kerning;
    text->fitting = text->default_fitting;
    text->x6C = 0;
    text->x98 = 0;
    text->x94 = 0;
    text->x4B = 0;
    if (text->string_buffer != NULL) {
        HSD_SisLib_Free(text->string_buffer);
    }
    text->string_buffer = HSD_SisLib_Alloc(0x10);
    i = 0;
    text->x6E = 0x10;
    while (i < text->x6E) {
        text->string_buffer[i] = 0;
        i += 1;
    }
}

u8 kar_debug_romfont_codepoint_table_805098c0[640] = {
    0x20, 0xE3, 0x20, 0xEC, 0x20, 0xF4, 0x21, 0x06, 0x21, 0x04, 0x21, 0x05,
    0x21, 0x07, 0x20, 0xF3, 0x20, 0xF5, 0x20, 0xF6, 0x21, 0x08, 0x20, 0xFD,
    0x20, 0xE6, 0x20, 0xFE, 0x20, 0xE7, 0x20, 0xF0, 0x20, 0x00, 0x20, 0x01,
    0x20, 0x02, 0x20, 0x03, 0x20, 0x04, 0x20, 0x05, 0x20, 0x06, 0x20, 0x07,
    0x20, 0x08, 0x20, 0x09, 0x20, 0xE9, 0x20, 0xEA, 0x21, 0x01, 0x21, 0x00,
    0x21, 0x02, 0x20, 0xEB, 0x21, 0x09, 0x20, 0x0A, 0x20, 0x0B, 0x20, 0x0C,
    0x20, 0x0D, 0x20, 0x0E, 0x20, 0x0F, 0x20, 0x10, 0x20, 0x11, 0x20, 0x12,
    0x20, 0x13, 0x20, 0x14, 0x20, 0x15, 0x20, 0x16, 0x20, 0x17, 0x20, 0x18,
    0x20, 0x19, 0x20, 0x1A, 0x20, 0x1B, 0x20, 0x1C, 0x20, 0x1D, 0x20, 0x1E,
    0x20, 0x1F, 0x20, 0x20, 0x20, 0x21, 0x20, 0x22, 0x20, 0x23, 0x20, 0xF7,
    0x21, 0x03, 0x20, 0xF8, 0x20, 0xED, 0x20, 0xEE, 0x20, 0x24, 0x20, 0x25,
    0x20, 0x26, 0x20, 0x27, 0x20, 0x28, 0x20, 0x29, 0x20, 0x2A, 0x20, 0x2B,
    0x20, 0x2C, 0x20, 0x2D, 0x20, 0x2E, 0x20, 0x2F, 0x20, 0x30, 0x20, 0x31,
    0x20, 0x32, 0x20, 0x33, 0x20, 0x34, 0x20, 0x35, 0x20, 0x36, 0x20, 0x37,
    0x20, 0x38, 0x20, 0x39, 0x20, 0x3A, 0x20, 0x3B, 0x20, 0x3C, 0x20, 0x3D,
    0x20, 0xF9, 0x20, 0xF2, 0x20, 0xFA, 0x20, 0xF1, 0x20, 0x3E, 0x20, 0x3F,
    0x20, 0x40, 0x20, 0x41, 0x20, 0x42, 0x20, 0x43, 0x20, 0x44, 0x20, 0x45,
    0x20, 0x46, 0x20, 0x47, 0x20, 0x48, 0x20, 0x49, 0x20, 0x4A, 0x20, 0x4B,
    0x20, 0x4C, 0x20, 0x4D, 0x20, 0x4E, 0x20, 0x4F, 0x20, 0x50, 0x20, 0x51,
    0x20, 0x52, 0x20, 0x53, 0x20, 0x54, 0x20, 0x55, 0x20, 0x56, 0x20, 0x57,
    0x20, 0x58, 0x20, 0x59, 0x20, 0x5A, 0x20, 0x5B, 0x20, 0x5C, 0x20, 0x5D,
    0x20, 0x5E, 0x20, 0x5F, 0x20, 0x60, 0x20, 0x61, 0x20, 0x62, 0x20, 0x63,
    0x20, 0x64, 0x20, 0x65, 0x20, 0x66, 0x20, 0x67, 0x20, 0x68, 0x20, 0x69,
    0x20, 0x6A, 0x20, 0x6B, 0x20, 0x6C, 0x20, 0x6D, 0x20, 0x6E, 0x20, 0x6F,
    0x20, 0x70, 0x20, 0x71, 0x20, 0x72, 0x20, 0x73, 0x20, 0x74, 0x20, 0x75,
    0x20, 0x76, 0x20, 0x77, 0x20, 0x78, 0x20, 0x79, 0x20, 0x7A, 0x20, 0x7B,
    0x20, 0x7C, 0x20, 0x7D, 0x20, 0x7E, 0x20, 0x7F, 0x20, 0x80, 0x20, 0x81,
    0x20, 0x82, 0x20, 0x83, 0x20, 0x84, 0x20, 0x85, 0x20, 0x86, 0x20, 0x87,
    0x20, 0x88, 0x20, 0x89, 0x20, 0x8A, 0x20, 0x8B, 0x20, 0x8C, 0x20, 0x8D,
    0x20, 0x8E, 0x20, 0x8F, 0x20, 0x90, 0x20, 0x91, 0x20, 0x92, 0x20, 0x93,
    0x20, 0x94, 0x20, 0x95, 0x20, 0x96, 0x20, 0x97, 0x20, 0x98, 0x20, 0x99,
    0x20, 0x9A, 0x20, 0x9B, 0x20, 0x9C, 0x20, 0x9D, 0x20, 0x9E, 0x20, 0x9F,
    0x20, 0xA0, 0x20, 0xA1, 0x20, 0xA2, 0x20, 0xA3, 0x20, 0xA4, 0x20, 0xA5,
    0x20, 0xA6, 0x20, 0xA7, 0x20, 0xA8, 0x20, 0xA9, 0x20, 0xAA, 0x20, 0xAB,
    0x20, 0xAC, 0x20, 0xAD, 0x20, 0xAE, 0x20, 0xAF, 0x20, 0xB0, 0x20, 0xB1,
    0x20, 0xB2, 0x20, 0xB3, 0x20, 0xB4, 0x20, 0xB5, 0x20, 0xB6, 0x20, 0xB7,
    0x20, 0xB8, 0x20, 0xB9, 0x20, 0xBA, 0x20, 0xBB, 0x20, 0xBC, 0x20, 0xBD,
    0x20, 0xBE, 0x20, 0xBF, 0x20, 0xC0, 0x20, 0xC1, 0x20, 0xC2, 0x20, 0xC3,
    0x20, 0xC4, 0x20, 0xC5, 0x20, 0xC6, 0x20, 0xC7, 0x20, 0xC8, 0x20, 0xC9,
    0x20, 0xCA, 0x20, 0xCB, 0x20, 0xCC, 0x20, 0xCD, 0x20, 0xCE, 0x20, 0xCF,
    0x20, 0xD0, 0x20, 0xD1, 0x20, 0xD2, 0x20, 0xD3, 0x20, 0xD4, 0x20, 0xD5,
    0x20, 0xD6, 0x20, 0xD7, 0x20, 0xD8, 0x20, 0xD9, 0x20, 0xDA, 0x20, 0xDB,
    0x20, 0xDC, 0x20, 0xDD, 0x20, 0xDE, 0x20, 0xDF, 0x20, 0xE0, 0x20, 0xE1,
    0x20, 0xE2, 0x20, 0xE4, 0x20, 0xE5, 0x20, 0xEF, 0x20, 0xE8, 0x20, 0xFF,
    0x21, 0x1F, 0x21, 0x0C, 0x21, 0x1C, 0x21, 0x0F, 0x21, 0x16, 0x21, 0x3A,
    0x21, 0x37, 0x21, 0x3B, 0x21, 0x2C, 0x21, 0x1E, 0x21, 0x0A, 0x21, 0x29,
    0x21, 0x3C, 0x21, 0x20, 0x21, 0x21, 0x21, 0x0B, 0x21, 0x34, 0x21, 0x15,
    0x21, 0x1B, 0x21, 0x1D, 0x21, 0x38, 0x21, 0x25, 0x21, 0x19, 0x21, 0x2D,
    0x21, 0x12, 0x21, 0x3E, 0x21, 0x17, 0x21, 0x32, 0x21, 0x33, 0x21, 0x39,
    0x21, 0x0D, 0x21, 0x27, 0x21, 0x2A, 0x20, 0xFB, 0x20, 0xFC, 0x21, 0x0E,
    0x21, 0x26, 0x21, 0x2F, 0x21, 0x3D, 0x21, 0x2E, 0x21, 0x2B, 0x21, 0x11,
    0x21, 0x10, 0x21, 0x13, 0x21, 0x18, 0x21, 0x35, 0x21, 0x1A, 0x21, 0x24,
    0x21, 0x31, 0x21, 0x23, 0x21, 0x36, 0x21, 0x14, 0x21, 0x22, 0x21, 0x30,
    0x21, 0x28, 0x00, 0x00,
};

u8 kar_debug_romfont_sjis_inventory_80509b40[640] = {
    0x81, 0x40, 0x81, 0x49, 0x81, 0x68, 0x81, 0x94, 0x81, 0x90, 0x81, 0x93,
    0x81, 0x95, 0x81, 0x66, 0x81, 0x69, 0x81, 0x6A, 0x81, 0x96, 0x81, 0x7B,
    0x81, 0x43, 0x81, 0x7C, 0x81, 0x44, 0x81, 0x5E, 0x82, 0x4F, 0x82, 0x50,
    0x82, 0x51, 0x82, 0x52, 0x82, 0x53, 0x82, 0x54, 0x82, 0x55, 0x82, 0x56,
    0x82, 0x57, 0x82, 0x58, 0x81, 0x46, 0x81, 0x47, 0x81, 0x83, 0x81, 0x81,
    0x81, 0x84, 0x81, 0x48, 0x81, 0x97, 0x82, 0x60, 0x82, 0x61, 0x82, 0x62,
    0x82, 0x63, 0x82, 0x64, 0x82, 0x65, 0x82, 0x66, 0x82, 0x67, 0x82, 0x68,
    0x82, 0x69, 0x82, 0x6A, 0x82, 0x6B, 0x82, 0x6C, 0x82, 0x6D, 0x82, 0x6E,
    0x82, 0x6F, 0x82, 0x70, 0x82, 0x71, 0x82, 0x72, 0x82, 0x73, 0x82, 0x74,
    0x82, 0x75, 0x82, 0x76, 0x82, 0x77, 0x82, 0x78, 0x82, 0x79, 0x81, 0x6D,
    0x81, 0x8F, 0x81, 0x6E, 0x81, 0x4F, 0x81, 0x51, 0x82, 0x81, 0x82, 0x82,
    0x82, 0x83, 0x82, 0x84, 0x82, 0x85, 0x82, 0x86, 0x82, 0x87, 0x82, 0x88,
    0x82, 0x89, 0x82, 0x8A, 0x82, 0x8B, 0x82, 0x8C, 0x82, 0x8D, 0x82, 0x8E,
    0x82, 0x8F, 0x82, 0x90, 0x82, 0x91, 0x82, 0x92, 0x82, 0x93, 0x82, 0x94,
    0x82, 0x95, 0x82, 0x96, 0x82, 0x97, 0x82, 0x98, 0x82, 0x99, 0x82, 0x9A,
    0x81, 0x6F, 0x81, 0x62, 0x81, 0x70, 0x81, 0x60, 0x82, 0x9F, 0x82, 0xA0,
    0x82, 0xA1, 0x82, 0xA2, 0x82, 0xA3, 0x82, 0xA4, 0x82, 0xA5, 0x82, 0xA6,
    0x82, 0xA7, 0x82, 0xA8, 0x82, 0xA9, 0x82, 0xAA, 0x82, 0xAB, 0x82, 0xAC,
    0x82, 0xAD, 0x82, 0xAE, 0x82, 0xAF, 0x82, 0xB0, 0x82, 0xB1, 0x82, 0xB2,
    0x82, 0xB3, 0x82, 0xB4, 0x82, 0xB5, 0x82, 0xB6, 0x82, 0xB7, 0x82, 0xB8,
    0x82, 0xB9, 0x82, 0xBA, 0x82, 0xBB, 0x82, 0xBC, 0x82, 0xBD, 0x82, 0xBE,
    0x82, 0xBF, 0x82, 0xC0, 0x82, 0xC1, 0x82, 0xC2, 0x82, 0xC3, 0x82, 0xC4,
    0x82, 0xC5, 0x82, 0xC6, 0x82, 0xC7, 0x82, 0xC8, 0x82, 0xC9, 0x82, 0xCA,
    0x82, 0xCB, 0x82, 0xCC, 0x82, 0xCD, 0x82, 0xCE, 0x82, 0xCF, 0x82, 0xD0,
    0x82, 0xD1, 0x82, 0xD2, 0x82, 0xD3, 0x82, 0xD4, 0x82, 0xD5, 0x82, 0xD6,
    0x82, 0xD7, 0x82, 0xD8, 0x82, 0xD9, 0x82, 0xDA, 0x82, 0xDB, 0x82, 0xDC,
    0x82, 0xDD, 0x82, 0xDE, 0x82, 0xDF, 0x82, 0xE0, 0x82, 0xE1, 0x82, 0xE2,
    0x82, 0xE3, 0x82, 0xE4, 0x82, 0xE5, 0x82, 0xE6, 0x82, 0xE7, 0x82, 0xE8,
    0x82, 0xE9, 0x82, 0xEA, 0x82, 0xEB, 0x82, 0xEC, 0x82, 0xED, 0x82, 0xF0,
    0x82, 0xF1, 0x83, 0x40, 0x83, 0x41, 0x83, 0x42, 0x83, 0x43, 0x83, 0x44,
    0x83, 0x45, 0x83, 0x46, 0x83, 0x47, 0x83, 0x48, 0x83, 0x49, 0x83, 0x4A,
    0x83, 0x4B, 0x83, 0x4C, 0x83, 0x4D, 0x83, 0x4E, 0x83, 0x4F, 0x83, 0x50,
    0x83, 0x51, 0x83, 0x52, 0x83, 0x53, 0x83, 0x54, 0x83, 0x55, 0x83, 0x56,
    0x83, 0x57, 0x83, 0x58, 0x83, 0x59, 0x83, 0x5A, 0x83, 0x5B, 0x83, 0x5C,
    0x83, 0x5D, 0x83, 0x5E, 0x83, 0x5F, 0x83, 0x60, 0x83, 0x61, 0x83, 0x62,
    0x83, 0x63, 0x83, 0x64, 0x83, 0x65, 0x83, 0x66, 0x83, 0x67, 0x83, 0x68,
    0x83, 0x69, 0x83, 0x6A, 0x83, 0x6B, 0x83, 0x6C, 0x83, 0x6D, 0x83, 0x6E,
    0x83, 0x6F, 0x83, 0x70, 0x83, 0x71, 0x83, 0x72, 0x83, 0x73, 0x83, 0x74,
    0x83, 0x75, 0x83, 0x76, 0x83, 0x77, 0x83, 0x78, 0x83, 0x79, 0x83, 0x7A,
    0x83, 0x7B, 0x83, 0x7C, 0x83, 0x7D, 0x83, 0x7E, 0x83, 0x80, 0x83, 0x81,
    0x83, 0x82, 0x83, 0x83, 0x83, 0x84, 0x83, 0x85, 0x83, 0x86, 0x83, 0x87,
    0x83, 0x88, 0x83, 0x89, 0x83, 0x8A, 0x83, 0x8B, 0x83, 0x8C, 0x83, 0x8D,
    0x83, 0x8E, 0x83, 0x8F, 0x83, 0x92, 0x83, 0x93, 0x83, 0x94, 0x83, 0x95,
    0x83, 0x96, 0x81, 0x41, 0x81, 0x42, 0x81, 0x5B, 0x81, 0x45, 0x81, 0x7E,
    0x8E, 0xFC, 0x89, 0xF1, 0x8E, 0x9E, 0x8A, 0xD4, 0x8C, 0xC2, 0x95, 0xC2,
    0x93, 0xC7, 0x96, 0x7B, 0x91, 0xCC, 0x8E, 0xE6, 0x88, 0xB5, 0x90, 0xE0,
    0x96, 0xBE, 0x8F, 0x91, 0x8F, 0xDA, 0x89, 0x9F, 0x93, 0x64, 0x8C, 0xB9,
    0x8E, 0x77, 0x8E, 0xA6, 0x94, 0xAD, 0x90, 0xB6, 0x8D, 0x9E, 0x91, 0xCF,
    0x8B, 0x76, 0x97, 0xCD, 0x8C, 0xC5, 0x92, 0xE8, 0x93, 0x5F, 0x95, 0xAA,
    0x8A, 0x4A, 0x90, 0xDA, 0x91, 0xB1, 0x81, 0x75, 0x81, 0x76, 0x8A, 0x6D,
    0x90, 0xD8, 0x92, 0x66, 0x96, 0xE2, 0x91, 0xE8, 0x91, 0xBC, 0x8B, 0x40,
    0x8A, 0xED, 0x8B, 0xA3, 0x8D, 0x87, 0x93, 0xAE, 0x8D, 0xEC, 0x90, 0xB3,
    0x92, 0xCA, 0x90, 0x4D, 0x93, 0xAF, 0x8C, 0xA9, 0x8F, 0xEA, 0x92, 0x86,
    0x90, 0xDD, 0x00, 0x00,
};

s32 kar_sislib__near_8044f9d4(HSD_Text* text, s32 idx)
{
    u8** sis_table;
    u8* p;
    s32 count;
    u8 op;

    sis_table = (u8**) lbl_8059A85C[text->font_idx];
    p = sis_table[idx];
    count = 0;
    while (*p != 0) {
        op = *p;
        if (op == 3) {
            count += 1;
        }
        if (op >= 0x20) {
            p += 2;
            continue;
        }
        switch (op) {
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 0xE:
            p += 5;
            break;
        case 0xC:
            p += 4;
            break;
        case 5:
            p += 3;
            break;
        case 0xB:
        default:
            p += 1;
            break;
        }
    }
    return count;
}

#pragma push
#pragma dont_inline on
HSD_Text* HSD_SisLib_803A6754(int font_idx, s32 context_id)
{
    SisBlock* alloc;
    HSD_Text* text;
    HSD_Text* buffer;

    text = HSD_SisLib_803A5ACC(font_idx, context_id, 0.0F, 0.0F, 0.0F, 640.0F,
                               480.0F);
    alloc = HSD_SisLib_Alloc(0x10);
    text->alloc_data = alloc;
    buffer = HSD_SisLib_Alloc(0x80);
    alloc->data = buffer;
    alloc->next = (SisBlock*) buffer;
    alloc->size = 0x80;
    *(u8*) &alloc->next->next = 0;
    *(&alloc->size + 1) = 0;
    HSD_SisLib_803A6368(text, 0);
    text->sis_buffer = (SIS*) alloc->data;
    return text;
}
#pragma pop

s32 HSD_SisLib_803A67EC(u8* data, u8* string)
{
    s32 has_kerning;
    s32 state;
    s32 state_dot;
    s32 out_idx_digit;
    s32 state_colon;
    s32 state_digit;
    s32 lut_count;
    s32 lut_idx;
    s32 in_idx;
    s32 out_idx;
    u8* char_ptr;
    u8* str_cursor;
    u8* lut_ptr;
    u8* out_ptr;
    u8 cur_char;
    u8 sjis_hi;
    u8 sjis_lo;

    str_cursor = string;
    has_kerning = 0;
    out_idx = 0;
    for (in_idx = 0; in_idx < 0x80; in_idx++, str_cursor++) {
        char_ptr = &string[in_idx];
        cur_char = *char_ptr;
        if (cur_char == '\0') {
            if (has_kerning != 0) {
                data[out_idx] = 0xB;
                out_idx += 1;
            }
            break;
        }
        if (cur_char == ' ') {
            state = has_kerning;
            if (state == 0) {
                data[out_idx++] = 0xA;
                data[out_idx++] = 0xF4;
                data[out_idx++] = 0x0;
                state += 1;
                data[out_idx++] = 0x0;
                data[out_idx++] = 0x0;
            }
            has_kerning = state;
            sjis_hi = 0x81;
            sjis_lo = 0x40;
        } else if (cur_char == '"') {
            data[out_idx] = 0xB;
            out_idx += 1;
            has_kerning = 0;
            sjis_hi = 0x81;
            sjis_lo = 0x68;
        } else if (cur_char == '\'') {
            data[out_idx] = 0xB;
            out_idx += 1;
            has_kerning = 0;
            sjis_hi = 0x81;
            sjis_lo = 0x66;
        } else if (cur_char == ',') {
            data[out_idx] = 0xB;
            out_idx += 1;
            has_kerning = 0;
            sjis_hi = 0x81;
            sjis_lo = 0x43;
        } else if (cur_char == '-') {
            data[out_idx] = 0xB;
            out_idx += 1;
            has_kerning = 0;
            sjis_hi = 0x81;
            sjis_lo = 0x7C;
        } else if (cur_char == '.') {
            state_dot = has_kerning;
            if (state_dot == 0) {
                data[out_idx++] = 0xA;
                data[out_idx++] = 0xF4;
                data[out_idx++] = 0x0;
                state_dot += 1;
                data[out_idx++] = 0x0;
                data[out_idx++] = 0x0;
            }
            has_kerning = state_dot;
            sjis_hi = 0x81;
            sjis_lo = 0x44;
        } else if ((cur_char >= '0') && (cur_char <= '9')) {
            state_digit = has_kerning;
            out_idx_digit = out_idx;
            if (state_digit == 0) {
                data[out_idx_digit++] = 0xA;
                data[out_idx_digit++] = 0xF4;
                data[out_idx_digit++] = 0x0;
                state_digit += 1;
                data[out_idx_digit++] = 0x0;
                data[out_idx_digit++] = 0x0;
            }
            has_kerning = state_digit;
            out_idx = out_idx_digit;
            sjis_hi = 0x82;
            sjis_lo = (u8) *char_ptr + 0x1F;
        } else if (cur_char == ':') {
            state_colon = has_kerning;
            if (state_colon == 0) {
                data[out_idx++] = 0xA;
                data[out_idx++] = 0xF4;
                data[out_idx++] = 0x0;
                state_colon += 1;
                data[out_idx++] = 0x0;
                data[out_idx++] = 0x0;
            }
            has_kerning = state_colon;
            sjis_hi = 0x81;
            sjis_lo = 0x46;
        } else if ((cur_char >= 'A') && (cur_char <= 'Z')) {
            data[out_idx] = 0xB;
            has_kerning = 0;
            out_idx += 1;
            sjis_hi = 0x82;
            sjis_lo = (u8) *char_ptr + 0x1F;
        } else if ((cur_char >= 'a') && (cur_char <= 'z')) {
            data[out_idx] = 0xB;
            has_kerning = 0;
            out_idx += 1;
            sjis_hi = 0x82;
            sjis_lo = (u8) *char_ptr + 0x20;
            (void) sjis_lo;
        } else {
            data[out_idx] = 0xB;
            out_idx += 1;
            has_kerning = 0;
            sjis_hi = (u8) string[in_idx];
            in_idx += 1;
            sjis_lo = str_cursor[1];
            str_cursor += 1;
        }
        lut_count = 0x13F;
        lut_ptr = kar_debug_romfont_sjis_inventory_80509b40;
        lut_idx = 0;
        do {
            if ((sjis_hi == lut_ptr[0]) && (sjis_lo == lut_ptr[1])) {
                out_ptr = kar_debug_romfont_codepoint_table_805098c0 + lut_idx * 2;
                data[out_idx++] = out_ptr[0];
                data[out_idx++] = out_ptr[1];
                break;
            }
            lut_ptr += 2;
            lut_idx += 1;
            lut_count -= 1;
        } while (lut_count != 0);
    }
    data[out_idx] = 0;
    return out_idx;
}

int HSD_SisLib_803A6B98(HSD_Text* text, float x, float y, const char* fmt, ...)
{
    u8 buffer[128];
    u8 encoded[128];
    s32 x_coord;
    s32 y_coord;
    HSD_Text* old_buf;
    SisBlock* alloc;
    s32 encoded_len;
    s32 copied_bytes;
    s32 i;
    s32 tail_count;
    u8* copy_dst;
    u8* copy_src;
    u8* new_buf;
    s32 copy_idx;
    u8* bulk_src;
    u8* tail_src;
    u32 required_size;
    u32 old_size;
    u32 bulk_count;
    u8** cur;
    va_list args;

    encoded_len = 0;
    alloc = text->alloc_data;
    encoded[0] = 0;
    if (fmt) {
        va_start(args, fmt);
        vsnprintf((char*) buffer, -1, fmt, args);
        va_end(args);
        encoded_len = HSD_SisLib_803A67EC(encoded, buffer);
    }

    old_buf = alloc->data;
    old_size = alloc->size;
    required_size =
        (HSD_SisLib_BytePtr(alloc->next) - HSD_SisLib_BytePtr(old_buf)) + 0x11;
    required_size += encoded_len;
    if (old_size < required_size) {
        alloc->size =
            old_size + ((((u32) (required_size - old_size) >> 7U) + 1) << 7);
        new_buf = HSD_SisLib_Alloc((s32) alloc->size);
        copy_src = (u8*) old_buf;
        copy_dst = new_buf;
        copy_idx = 0;
        while (copy_idx < (s32) (((u8*) alloc->next - (u8*) alloc->data) + 1))
        {
            *copy_dst = *copy_src;
            copy_idx += 1;
            copy_src += 1;
            copy_dst += 1;
        }
        alloc->data = (HSD_Text*) new_buf;
        text->sis_buffer = (SIS*) new_buf;
        alloc->next =
            (SisBlock*) (new_buf + ((u8*) alloc->next - (u8*) old_buf));
        HSD_SisLib_Free(old_buf);
    }

    cur = (u8**) &alloc->next;
    *(*cur)++ = 7;
    copied_bytes = 0;
    x_coord = (s16) x;
    *(*cur)++ = (u8) (x_coord >> 8);
    *(*cur)++ = (u8) x_coord;
    y_coord = (s16) y;
    *(*cur)++ = (u8) (y_coord >> 8);
    *(*cur)++ = (u8) y_coord;
    *(*cur)++ = 0xC;
    *(*cur)++ = text->text_color.r;
    *(*cur)++ = text->text_color.g;
    *(*cur)++ = text->text_color.b;
    *(*cur)++ = 0xE;
    *(*cur)++ = (u8) (s32) text->x34.x;
    *(*cur)++ = (u8) (s32) (256.0F * text->x34.x);
    *(*cur)++ = (u8) (s32) text->x34.y;
    *(*cur)++ = (u8) (s32) (256.0F * text->x34.y);

    if (encoded_len > 0) {
        if (encoded_len > 8) {
            bulk_count = (u32) ((encoded_len - 8) + 7) >> 3U;
            bulk_src = encoded;
            if ((encoded_len - 8) > 0) {
                do {
                    copied_bytes += 8;
                    for (i = 0; i < 8; i++) {
                        *(*cur)++ = bulk_src[i];
                    }
                    bulk_src += 8;
                    bulk_count -= 1;
                } while (bulk_count != 0);
            }
        }
        tail_src = encoded + copied_bytes;
        (void) tail_src;
        tail_count = encoded_len - copied_bytes;
        if (copied_bytes < encoded_len) {
            do {
                *(*cur)++ = *tail_src++;
                tail_count -= 1;
            } while (tail_count != 0);
        }
    }
    *(*cur)++ = 0xF;
    *(*cur)++ = 0xD;
    **cur = 0;
    return ((SisAllocHeader*) alloc)->xC++;
}

static inline u8* fn_803A6FEC(u8* sis_data, s32 entry_idx, s32* out_size)
{
    u8 char_size;
    u8* scan_ptr;

    for (;;) {
        switch (*sis_data) {
        case 0:
            return NULL;
        case 12:
            sis_data += 3;
        case 11:
        case 13:
        case 15:
            break;
        case 7:
            entry_idx -= 1;
            if (entry_idx < 0) {
                goto end;
            }
        /* fallthrough */
        case 10:
        case 14:
            sis_data += 4;
            break;
        default:
            sis_data += 1;
            break;
        }
        sis_data += 1;
    }
end:
    if (out_size != NULL) {
        *out_size = 0;
        scan_ptr = sis_data + 0xE;
        do {
            char_size = 0;
            if (*scan_ptr >= 32) {
                char_size = 2;
            } else if (*scan_ptr == 10) {
                char_size = 5;
            } else if (*scan_ptr == 11) {
                char_size = 1;
            }
            *out_size += char_size;
            scan_ptr += char_size;
        } while (char_size != 0);
    }
    return sis_data;
}

s32 HSD_SisLib_803A70A0(HSD_Text* text, s32 entry_idx, char* fmt, ...)
{
    u8 buffer[128];
    u8 encoded[128];
    s32 old_size;
    HSD_Text* old_buf;
    s32 new_size;
    s32 grow_diff;
    s32 shrink_diff;
    s32 tail_len;
    s32 copy_idx;
    s32 i;
    s32 remainder;
    u32 required_size;
    u32 cur_size;
    u32 bulk_count;
    u8* entry;
    u8* playhead;
    u8* new_buf;
    u8* copy_src;
    u8* copy_dst;
    u8* src;
    u8* dst;
    u8* tail_src;
    SisBlock* alloc;
    s32 result;
    SisBlock* old_end;
    va_list args;

    entry = fn_803A6FEC((u8*) text->sis_buffer, entry_idx, &old_size);
    if (entry != NULL) {
        alloc = text->alloc_data;
        playhead = entry + 0xE;
        if (fmt != NULL) {
            va_start(args, fmt);
            vsnprintf((char*) buffer, -1, fmt, args);
            va_end(args);
            new_size = HSD_SisLib_803A67EC(encoded, buffer);
        } else {
            new_size = 0;
        }
        if (old_size < new_size) {
            old_end = alloc->next;
            grow_diff = new_size - old_size;
            old_buf = alloc->data;
            cur_size = alloc->size;
            tail_len = (u8*) old_end - playhead;
            {
                u32 new_required_size =
                    new_size + ((HSD_SisLib_BytePtr(old_end) -
                                 HSD_SisLib_BytePtr(old_buf)) +
                                1);
                required_size = new_required_size;
            }
            if (cur_size < required_size) {
                alloc->size =
                    cur_size +
                    ((((u32) (required_size - cur_size) >> 7U) + 1) << 7);
                new_buf = HSD_SisLib_Alloc((s32) alloc->size);
                copy_src = (u8*) old_buf;
                copy_dst = new_buf;
                copy_idx = 0;
                while (copy_idx <
                       (s32) (((u8*) alloc->next - (u8*) alloc->data) + 1))
                {
                    *copy_dst = *copy_src;
                    copy_idx += 1;
                    copy_src += 1;
                    copy_dst += 1;
                }
                alloc->data = (HSD_Text*) new_buf;
                text->sis_buffer = (SIS*) new_buf;
                alloc->next =
                    (SisBlock*) (new_buf + ((u8*) old_end - (u8*) old_buf));
                HSD_SisLib_Free(old_buf);
                playhead = (u8*) alloc->next - tail_len;
            }
            dst = &playhead[grow_diff + tail_len];
            src = &playhead[tail_len];
            if (tail_len > 0) {
                bulk_count = (u32) tail_len >> 3U;
                if (bulk_count != 0) {
                    for (; bulk_count != 0; bulk_count--) {
                        for (i = 0; i < 8; i++) {
                            dst[-i] = src[-i];
                        }
                        src -= 8;
                        dst -= 8;
                    }
                    remainder = tail_len & 7;
                    if (remainder == 0) {
                        goto grow_done;
                    }
                } else {
                    remainder = tail_len;
                }
                do {
                    *dst = *src;
                    src -= 1;
                    dst -= 1;
                    remainder -= 1;
                } while (remainder != 0);
            }
        grow_done:
            alloc->next = (SisBlock*) ((u8*) alloc->next + grow_diff);
        } else if (old_size > new_size) {
            shrink_diff = old_size - new_size;
            i = 0;
            tail_len = (u8*) alloc->next - playhead;
            if (tail_len > 0) {
                if (tail_len > 8) {
                    bulk_count = (u32) ((tail_len - 8) + 7) >> 3U;
                    src = &playhead[shrink_diff];
                    if ((tail_len - 8) > 0) {
                        do {
                            dst = &playhead[i];
                            i += 8;
                            for (copy_idx = 0; copy_idx < 8; copy_idx++) {
                                dst[copy_idx] = src[copy_idx];
                            }
                            src += 8;
                            bulk_count -= 1;
                        } while (bulk_count != 0);
                    }
                }
                tail_src = &playhead[shrink_diff + i];
                (void) tail_src;
                remainder = tail_len - i;
                dst = &playhead[i];
                if (i < tail_len) {
                    do {
                        *dst = *tail_src;
                        tail_src += 1;
                        dst += 1;
                        remainder -= 1;
                    } while (remainder != 0);
                }
            }
            alloc->next = (SisBlock*) ((u8*) alloc->next - shrink_diff);
        }
        i = 0;
        if (new_size > 0) {
            if (new_size > 8) {
                bulk_count = (u32) ((new_size - 8) + 7) >> 3U;
                src = encoded;
                if ((new_size - 8) > 0) {
                    do {
                        i += 8;
                        for (copy_idx = 0; copy_idx < 8; copy_idx++) {
                            playhead[copy_idx] = src[copy_idx];
                        }
                        src += 8;
                        playhead += 8;
                        bulk_count -= 1;
                    } while (bulk_count != 0);
                }
            }
            tail_src = encoded + i;
            remainder = new_size - i;
            if (i < new_size) {
                do {
                    *playhead = *tail_src;
                    tail_src += 1;
                    playhead += 1;
                    remainder -= 1;
                } while (remainder != 0);
            }
        }
        *playhead = 0xF;
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

void HSD_SisLib_803A7548(HSD_Text* text, int entry_idx, float scale_x,
                         float scale_y)
{
    u8* entry = fn_803A6FEC((u8*) text->sis_buffer, entry_idx, NULL);
    u8* scale_ptr;
    if (entry != NULL) {
        scale_ptr = entry + 9;
        *++scale_ptr = (u8) scale_x;
        scale_ptr[1] = (u8) (256.0F * scale_x);
        scale_ptr[2] = (u8) scale_y;
        scale_ptr[3] = (u8) (256.0F * scale_y);
    }
}

void HSD_SisLib_803A7684(HSD_Text* text, u8* cursor, u8 flags)
{
    s32 old_x6E;
    s32 new_x6E;
    s32 idx;
    s32 count;
    s32 k;
    s32 pos;
    u32 bulk;
    u8* old_buf;
    u8* src;

    switch (flags & 0x7F) {
    case 1:
        old_x6E = text->x6E;
        if (old_x6E < (s32) (text->x6C + 5)) {
            new_x6E = old_x6E + 0x10;
            old_buf = (u8*) text->string_buffer;
            text->string_buffer = HSD_SisLib_Alloc(new_x6E);
            text->x6E = (u16) new_x6E;
            idx = 0;
            if (old_x6E > 0) {
                src = old_buf;
                count = old_x6E;
                bulk = (u32) count >> 3U;
                if (bulk != 0) {
                    do {
                        for (k = 0; k < 8; k++) {
                            text->string_buffer[idx++] = src[k];
                        }
                        src += 8;
                        bulk -= 1;
                    } while (bulk != 0);
                    count &= 7;
                    if (count == 0) {
                        goto zero_1;
                    }
                }
                do {
                    text->string_buffer[idx++] = *src++;
                    count -= 1;
                } while (count != 0);
            }
        zero_1:
            while (idx < (s32) text->x6E) {
                text->string_buffer[idx++] = 0;
            }
            HSD_SisLib_Free(old_buf);
        }
        pos = text->x6C;
        text->x6C = pos + 1;
        text->string_buffer[pos] = (s8) ((s32) (256.0F * text->x78.x) >> 8);
        pos = text->x6C;
        text->x6C = pos + 1;
        text->string_buffer[pos] = (s8) (256.0F * text->x78.x);
        pos = text->x6C;
        text->x6C = pos + 1;
        text->string_buffer[pos] = (s8) ((s32) (256.0F * text->x78.y) >> 8);
        pos = text->x6C;
        text->x6C = pos + 1;
        text->string_buffer[pos] = (s8) (256.0F * text->x78.y);
        pos = text->x6C;
        text->x6C = pos + 1;
        text->string_buffer[pos] = (s8) flags;
        return;
    case 2:
        old_x6E = text->x6E;
        if (old_x6E < (s32) (text->x6C + 4)) {
            new_x6E = old_x6E + 0x10;
            old_buf = (u8*) text->string_buffer;
            text->string_buffer = HSD_SisLib_Alloc(new_x6E);
            text->x6E = (u16) new_x6E;
            idx = 0;
            if (old_x6E > 0) {
                src = old_buf;
                count = old_x6E;
                bulk = (u32) count >> 3U;
                if (bulk != 0) {
                    do {
                        for (k = 0; k < 8; k++) {
                            text->string_buffer[idx++] = src[k];
                        }
                        src += 8;
                        bulk -= 1;
                    } while (bulk != 0);
                    count &= 7;
                    if (count == 0) {
                        goto zero_2;
                    }
                }
                do {
                    text->string_buffer[idx++] = *src++;
                    count -= 1;
                } while (count != 0);
            }
        zero_2:
            while (idx < (s32) text->x6E) {
                text->string_buffer[idx++] = 0;
            }
            HSD_SisLib_Free(old_buf);
        }
        pos = text->x6C;
        text->x6C = pos + 1;
        text->string_buffer[pos] = (s8) text->active_color.r;
        pos = text->x6C;
        text->x6C = pos + 1;
        text->string_buffer[pos] = (s8) text->active_color.g;
        pos = text->x6C;
        text->x6C = pos + 1;
        text->string_buffer[pos] = (s8) text->active_color.b;
        pos = text->x6C;
        text->x6C = pos + 1;
        text->string_buffer[pos] = (s8) flags;
        return;
    case 3:
        old_x6E = text->x6E;
        if (old_x6E < (s32) (text->x6C + 5)) {
            new_x6E = old_x6E + 0x10;
            old_buf = (u8*) text->string_buffer;
            text->string_buffer = HSD_SisLib_Alloc(new_x6E);
            text->x6E = (u16) new_x6E;
            idx = 0;
            if (old_x6E > 0) {
                src = old_buf;
                count = old_x6E;
                bulk = (u32) count >> 3U;
                if (bulk != 0) {
                    do {
                        for (k = 0; k < 8; k++) {
                            text->string_buffer[idx++] = src[k];
                        }
                        src += 8;
                        bulk -= 1;
                    } while (bulk != 0);
                    count &= 7;
                    if (count == 0) {
                        goto zero_3;
                    }
                }
                do {
                    text->string_buffer[idx++] = *src++;
                    count -= 1;
                } while (count != 0);
            }
        zero_3:
            while (idx < (s32) text->x6E) {
                text->string_buffer[idx++] = 0;
            }
            HSD_SisLib_Free(old_buf);
        }
        pos = text->x6C;
        text->x6C = pos + 1;
        text->string_buffer[pos] = (s8) ((s32) (256.0F * text->x80.x) >> 8);
        pos = text->x6C;
        text->x6C = pos + 1;
        text->string_buffer[pos] = (s8) (256.0F * text->x80.x);
        pos = text->x6C;
        text->x6C = pos + 1;
        text->string_buffer[pos] = (s8) ((s32) (256.0F * text->x80.y) >> 8);
        pos = text->x6C;
        text->x6C = pos + 1;
        text->string_buffer[pos] = (s8) (256.0F * text->x80.y);
        pos = text->x6C;
        text->x6C = pos + 1;
        text->string_buffer[pos] = (s8) flags;
        return;
    case 4:
        old_x6E = text->x6E;
        if (old_x6E < (s32) (text->x6C + 2)) {
            new_x6E = old_x6E + 0x10;
            old_buf = (u8*) text->string_buffer;
            text->string_buffer = HSD_SisLib_Alloc(new_x6E);
            text->x6E = (u16) new_x6E;
            idx = 0;
            if (old_x6E > 0) {
                src = old_buf;
                count = old_x6E;
                bulk = (u32) count >> 3U;
                if (bulk != 0) {
                    do {
                        for (k = 0; k < 8; k++) {
                            text->string_buffer[idx++] = src[k];
                        }
                        src += 8;
                        bulk -= 1;
                    } while (bulk != 0);
                    count &= 7;
                    if (count == 0) {
                        goto zero_4;
                    }
                }
                do {
                    text->string_buffer[idx++] = *src++;
                    count -= 1;
                } while (count != 0);
            }
        zero_4:
            while (idx < (s32) text->x6E) {
                text->string_buffer[idx++] = 0;
            }
            HSD_SisLib_Free(old_buf);
        }
        pos = text->x6C;
        text->x6C = pos + 1;
        text->string_buffer[pos] = (s8) text->alignment;
        pos = text->x6C;
        text->x6C = pos + 1;
        text->string_buffer[pos] = (s8) flags;
        return;
    case 5:
        old_x6E = text->x6E;
        if (old_x6E < (s32) (text->x6C + 5)) {
            new_x6E = old_x6E + 0x10;
            old_buf = (u8*) text->string_buffer;
            (void) old_buf;
            text->string_buffer = HSD_SisLib_Alloc(new_x6E);
            text->x6E = (u16) new_x6E;
            idx = 0;
            if (old_x6E > 0) {
                src = old_buf;
                count = old_x6E;
                bulk = (u32) count >> 3U;
                if (bulk != 0) {
                    do {
                        for (k = 0; k < 8; k++) {
                            text->string_buffer[idx++] = src[k];
                        }
                        src += 8;
                        bulk -= 1;
                    } while (bulk != 0);
                    count &= 7;
                    if (count == 0) {
                        goto zero_5;
                    }
                }
                do {
                    text->string_buffer[idx++] = *src++;
                    count -= 1;
                } while (count != 0);
            }
        zero_5:
            while (idx < (s32) text->x6E) {
                text->string_buffer[idx++] = 0;
            }
            HSD_SisLib_Free(old_buf);
        }
        pos = text->x6C;
        text->x6C = pos + 1;
        text->string_buffer[pos] = (s8) ((u32) cursor >> 0x18U);
        pos = text->x6C;
        text->x6C = pos + 1;
        text->string_buffer[pos] = (s8) (u8) ((u32) cursor >> 0x10U);
        pos = text->x6C;
        text->x6C = pos + 1;
        text->string_buffer[pos] = (s8) (u8) ((u32) cursor >> 8U);
        pos = text->x6C;
        text->x6C = pos + 1;
        text->string_buffer[pos] = (s8) (u32) cursor;
        pos = text->x6C;
        text->x6C = pos + 1;
        text->string_buffer[pos] = (s8) flags;
        return;
    }
}

s32 HSD_SisLib_803A7F0C(HSD_Text* text, s32 flags)
{
    u8 entry;
    s32 flag_hi;
    s32 entry_type;
    s32 entry_flags;
    s32 target_type;
    s32 result;
    s32 remove_size;
    s32 pos;

    flag_hi = flags & 0x80;
    target_type = flags & 0x7F;
    pos = text->x6C;
    result = 0;
    remove_size = 0;
    while (pos >= 0) {
        entry = text->string_buffer[pos];
        entry_type = entry & 0x7F;
        entry_flags = entry & 0x80;
        switch (entry_type) {
        case 1:
            pos -= 4;
            if (target_type == 1) {
                text->x78.x =
                    (f32) * (s16*) (text->string_buffer + pos) * 0.00390625F;
                text->x78.y = (f32) * (s16*) (text->string_buffer + pos + 2) *
                              0.00390625F;
                if (flag_hi == entry_flags) {
                    remove_size = 5;
                }
                goto done;
            }
            break;
        case 2:
            pos -= 3;
            if (target_type == 2) {
                text->active_color.r = text->string_buffer[pos];
                text->active_color.g = text->string_buffer[pos + 1];
                text->active_color.b = text->string_buffer[pos + 2];
                if (flag_hi == entry_flags) {
                    remove_size = 4;
                }
                goto done;
            }
            break;
        case 3:
            pos -= 4;
            if (target_type == 3) {
                text->x80.x =
                    (f32) * (u16*) (text->string_buffer + pos) * 0.00390625F;
                text->x80.y = (f32) * (u16*) (text->string_buffer + pos + 2) *
                              0.00390625F;
                if (flag_hi == entry_flags) {
                    remove_size = 5;
                }
                goto done;
            }
            break;
        case 4:
            pos -= 1;
            if (target_type == 4) {
                text->alignment = text->string_buffer[pos];
                if (flag_hi == entry_flags) {
                    remove_size = 2;
                }
                goto done;
            }
            break;
        case 5:
            pos -= 4;
            if (target_type == 5) {
                result = *(s32*) (text->string_buffer + pos);
                if (flag_hi == entry_flags) {
                    remove_size = 5;
                }
                goto done;
            }
            break;
        }
        pos -= 1;
    }
done:
    if (remove_size != 0) {
        while ((pos + remove_size) < (s32) text->x6C) {
            text->string_buffer[pos] = text->string_buffer[pos + remove_size];
            pos += 1;
        }
        while (pos < (s32) text->x6C) {
            text->string_buffer[pos] = 0;
            pos += 1;
        }
        text->x6C -= remove_size;
    }
    return result;
}

u8 kar_debug_romfont_glyph_metrics_80509dc0[640] = {
    0x04, 0x04, 0x08, 0x0A, 0x04, 0x03, 0x04, 0x03, 0x03, 0x03, 0x04, 0x03,
    0x04, 0x04, 0x04, 0x04, 0x05, 0x03, 0x04, 0x03, 0x04, 0x03, 0x06, 0x05,
    0x04, 0x04, 0x05, 0x03, 0x08, 0x06, 0x08, 0x06, 0x04, 0x03, 0x05, 0x03,
    0x0D, 0x0B, 0x07, 0x06, 0x06, 0x04, 0x08, 0x06, 0x03, 0x01, 0x04, 0x03,
    0x04, 0x03, 0x06, 0x04, 0x04, 0x02, 0x06, 0x04, 0x05, 0x04, 0x06, 0x05,
    0x05, 0x03, 0x04, 0x03, 0x01, 0x00, 0x05, 0x04, 0x04, 0x03, 0x05, 0x04,
    0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x08, 0x09,
    0x07, 0x06, 0x08, 0x07, 0x0A, 0x0A, 0x09, 0x0C, 0x08, 0x06, 0x0C, 0x0C,
    0x01, 0x00, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x07, 0x06, 0x0A, 0x09,
    0x08, 0x07, 0x08, 0x09, 0x07, 0x05, 0x07, 0x06, 0x02, 0x01, 0x07, 0x06,
    0x06, 0x06, 0x07, 0x06, 0x05, 0x05, 0x03, 0x02, 0x05, 0x05, 0x03, 0x02,
    0x06, 0x06, 0x04, 0x04, 0x06, 0x05, 0x03, 0x02, 0x05, 0x03, 0x02, 0x00,
    0x01, 0x00, 0x00, 0x00, 0x04, 0x04, 0x04, 0x00, 0x04, 0x05, 0x04, 0x03,
    0x02, 0x02, 0x02, 0x00, 0x04, 0x04, 0x03, 0x00, 0x04, 0x03, 0x03, 0x00,
    0x05, 0x03, 0x05, 0x03, 0x02, 0x02, 0x02, 0x00, 0x02, 0x02, 0x01, 0x00,
    0x02, 0x02, 0x01, 0x00, 0x02, 0x02, 0x02, 0x00, 0x03, 0x03, 0x03, 0x00,
    0x04, 0x05, 0x01, 0x02, 0x01, 0x00, 0x02, 0x02, 0x02, 0x00, 0x04, 0x04,
    0x03, 0x00, 0x01, 0x01, 0x03, 0x02, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01,
    0x02, 0x01, 0x02, 0x00, 0x02, 0x00, 0x02, 0x01, 0x02, 0x00, 0x02, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01,
    0x02, 0x01, 0x01, 0x00, 0x01, 0x00, 0x03, 0x03, 0x01, 0x01, 0x02, 0x01,
    0x02, 0x02, 0x03, 0x02, 0x04, 0x04, 0x01, 0x01, 0x05, 0x05, 0x02, 0x02,
    0x05, 0x05, 0x02, 0x02, 0x03, 0x03, 0x05, 0x05, 0x02, 0x02, 0x01, 0x00,
    0x02, 0x03, 0x04, 0x04, 0x01, 0x01, 0x02, 0x03, 0x01, 0x01, 0x05, 0x04,
    0x03, 0x01, 0x04, 0x06, 0x01, 0x03, 0x06, 0x05, 0x03, 0x02, 0x05, 0x04,
    0x02, 0x02, 0x04, 0x05, 0x02, 0x01, 0x02, 0x02, 0x02, 0x00, 0x02, 0x02,
    0x01, 0x00, 0x03, 0x02, 0x02, 0x00, 0x01, 0x01, 0x01, 0x00, 0x03, 0x04,
    0x02, 0x00, 0x02, 0x02, 0x01, 0x00, 0x02, 0x01, 0x02, 0x01, 0x02, 0x01,
    0x02, 0x00, 0x02, 0x02, 0x02, 0x00, 0x02, 0x03, 0x01, 0x00, 0x03, 0x02,
    0x02, 0x00, 0x02, 0x02, 0x02, 0x00, 0x05, 0x05, 0x02, 0x02, 0x01, 0x00,
    0x02, 0x02, 0x01, 0x00, 0x09, 0x03, 0x09, 0x02, 0x02, 0x02, 0x01, 0x01,
    0x02, 0x02, 0x03, 0x02, 0x03, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x04, 0x04, 0x00, 0x04, 0x02, 0x04, 0x03, 0x03, 0x00, 0x03, 0x00,
    0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x02, 0x02, 0x04, 0x04, 0x01, 0x01, 0x02, 0x03, 0x02, 0x02, 0x04, 0x04,
    0x02, 0x01, 0x05, 0x05, 0x02, 0x02, 0x06, 0x06, 0x03, 0x04, 0x03, 0x03,
    0x05, 0x05, 0x01, 0x01, 0x05, 0x03, 0x03, 0x03, 0x06, 0x06, 0x03, 0x03,
    0x04, 0x03, 0x02, 0x02, 0x03, 0x00, 0x04, 0x05, 0x04, 0x00, 0x08, 0x08,
    0x02, 0x12, 0x02, 0x13, 0x0C, 0x0D, 0x0C, 0x0D, 0x0B, 0x0A, 0x0D, 0x0C,
    0x0D, 0x0C, 0x07, 0x06, 0x0D, 0x0C, 0x0A, 0x08, 0x00, 0x00, 0x02, 0x01,
    0x01, 0x00, 0x01, 0x01, 0x0F, 0x0F, 0x02, 0x17, 0x01, 0x10, 0x15, 0x00,
    0x01, 0x14, 0x15, 0x00, 0x01, 0x13, 0x13, 0x00, 0x01, 0x12, 0x12, 0x01,
    0x01, 0x12, 0x04, 0x03, 0x04, 0x03, 0x05, 0x04, 0x04, 0x03, 0x01, 0x01,
    0x01, 0x00, 0x04, 0x02, 0x05, 0x05, 0x01, 0x00, 0x04, 0x03, 0x03, 0x02,
    0x08, 0x06, 0x03, 0x02, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x01, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x01, 0x02, 0x02, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x00, 0x00, 0x01, 0x01, 0x01, 0x02,
    0x00, 0x01, 0x00, 0x00,
};

void HSD_SisLib_803A8134(void* cursor, HSD_Text* text, f32* out_width,
                         f32* out_height)
{
    SIS* sis;
    TextGlyphTexture* glyph_tex;
    u8* default_kerning = kar_debug_romfont_glyph_metrics_80509dc0;
    f32 saved_scale_x;
    f32 saved_scale_y;
    f32 saved_spacing;
    u16 kern_enabled;
    u16 saved_x6C;
    u16 glyph_code;
    s32 kern_width;
    s32 clear_idx;
    u32 pop_result;
    TextKerning* kern_data;
    u8 opcode;
    u8 kern_left;
    u8 kern_right;

    saved_scale_x = text->x80.x;
    saved_scale_y = text->x80.y;
    saved_spacing = text->x78.x;
    kern_enabled = text->kerning;
    sis = lbl_8059A85C[text->font_idx];
    saved_x6C = text->x6C;
    if (sis != NULL) {
        glyph_tex = sis->textures;
    }
    *out_width = 0.0F;
    *out_height = 32.0F * text->x80.y;
loop_3:
    opcode = *(u8*) cursor;
    switch (opcode) {
    case 0:
        pop_result = HSD_SisLib_803A7F0C(text, 0x85);
        if (pop_result != 0U) {
            cursor = (u8*) (pop_result + 4);
            goto block_33;
        }
        break;
    case 9:
        HSD_SisLib_803A7684(text, (u8*) cursor, 0x85U);
        /* fallthrough */
    case 8:
        cursor = (u8*) *(s32*) ((u8*) cursor + 1) - 1;
        goto block_33;
    case 14:
        HSD_SisLib_803A7684(text, (u8*) cursor, 0x83U);
        text->x80.x = (f32) * (u16*) ((u8*) cursor + 1) / 256.0F;
        text->x80.y = (f32) * (u16*) ((u8*) cursor + 3) / 256.0F;
        cursor = (u8*) cursor + 4;
        goto block_33;
    case 15:
        HSD_SisLib_803A7F0C(text, 0x83);
        goto block_33;
    case 6:
        cursor = (u8*) cursor + 4;
        goto block_33;
    case 10:
        if (((SisBlock*) text->alloc_data == NULL) || (kern_enabled == 0)) {
            HSD_SisLib_803A7684(text, (u8*) cursor, 0x81U);
            text->x78.x = (f32) * (s16*) ((u8*) cursor + 1) / 256.0F;
        }
        cursor = (u8*) cursor + 4;
        goto block_33;
    case 11:
        if (((SisBlock*) text->alloc_data == NULL) || (kern_enabled == 0)) {
            HSD_SisLib_803A7F0C(text, 0x81);
        }
        goto block_33;
    case 12:
        cursor = (u8*) cursor + 3;
        goto block_33;
    case 5:
        cursor = (u8*) cursor + 2;
        goto block_33;
    case 22:
        kern_enabled = 1;
        goto block_33;
    case 23:
        kern_enabled = 0;
        goto block_33;
    case 26:
        *out_width += text->x80.x * (16.0F + text->x78.x);
        if (*out_height < (32.0F * text->x80.y)) {
            *out_height = 32.0F * text->x80.y;
        }
        goto block_33;
    default:
        if (opcode >= 0x20U) {
            *out_width += text->x80.x * (32.0F + text->x78.x);
            if (kern_enabled != 0) {
                glyph_code = *(u16*) cursor;
                if (glyph_code < 0x4000U) {
                    kern_data = (TextKerning*) (default_kerning +
                                                (((glyph_code - 0x2000) * 2) &
                                                 0x1FFFE));
                } else {
                    kern_data = (TextKerning*) &glyph_tex
                                     ->data[((glyph_code - 0x4000) * 2) & 0x1FFFE];
                }
                kern_right = kern_data->right;
                kern_left = kern_data->left;
                kern_width = kern_left + (kern_right - 2);
                *out_width = -((text->x80.x * (f32) kern_width) - *out_width);
            }
            if (*out_height < (32.0F * text->x80.y)) {
                *out_height = 32.0F * text->x80.y;
            }
            cursor = (u8*) cursor + 1;
        }
        goto block_33;
    }
    goto block_done;
block_33:
    cursor = (u8*) cursor + 1;
    goto loop_3;
block_done:
    *out_width -= text->x78.x;
    text->x80.x = saved_scale_x;
    text->x80.y = saved_scale_y;
    text->x78.x = saved_spacing;
    text->x6C = saved_x6C;
    opcode = 0;
    clear_idx = text->x6C;
    while (clear_idx < (s32) text->x6E) {
        text->string_buffer[clear_idx] = opcode;
        clear_idx += 1;
    }
}

void HSD_SisLib_803A84BC(HSD_GObj* gobj, s32 pass)
{
    HSD_Text* text;
    Mtx m;
    TextKerning* kerning = NULL;
    TextGlyphTexture* textures = NULL;

    Vec2 min;
    Vec2 max;

    u8 saved_alignment;
    u8 saved_fitting;
    u8 saved_color_b;
    u8 saved_color_g;
    u8 saved_color_r;
    f32 saved_spacing_y;
    Vec2 saved_scale;
    Vec2 saved_font_size;
    u16 line_delay;
    u16 char_delay;
    u32 skip_count;
    u16 saved_x6C;
    u8 saved_kerning;

    u8* data = kar_sislib_romfont_glyphs_i4_32x32;
    u8* default_kerning = kar_debug_romfont_glyph_metrics_80509dc0;

    if (gobj != NULL) {
        if (pass == 2U) {
            text = gobj->user_data;
        } else {
            return;
        }
    } else {
        text = (HSD_Text*) pass;
    }
    if (text->hidden == 0 && text->sis_buffer != NULL) {
        u8* sis_cursor = (u8*) text->sis_buffer;
        if (gobj != NULL) {
            SIS* sis = lbl_8059A85C[text->font_idx];
            if (sis != NULL) {
                kerning = sis->kerning;
                textures = sis->textures;
            }
        }
        if (gobj != NULL) {
            if (text->x4C != 0) {
                HSD_StateSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
            } else {
                HSD_StateSetZMode(GX_FALSE, GX_NEVER, GX_FALSE);
            }
            HSD_CObjGetViewingMtx(HSD_CObjGetCurrent(), (MtxPtr) &m);
        } else {
            GXSetZMode(0U, 0U, 0U);
            GXSetViewport(0.0F, 0.0F, 640.0F, 480.0F, 0.0F, 1.0F);
            GXSetScissor(0, 0, 0x280, 0x1E0);
            C_MTXOrtho((MtxPtr) &m, 0.0F, -480.0F, 0.0F, 640.0F, 0.0F, 2.0F);
            GXSetProjection((MtxPtr) &m, 0);
            m[0][0] = 1.0F;
            m[0][1] = 0.0F;
            m[0][2] = 0.0F;
            m[0][3] = 0.0F;
            m[1][0] = 0.0F;
            m[1][1] = 1.0F;
            m[1][2] = 0.0F;
            m[1][3] = 0.0F;
            m[2][0] = 0.0F;
            m[2][1] = 0.0F;
            m[2][2] = 1.0F;
            m[2][3] = -1.0F;
        }
        GXSetCurrentMtx(0);
        GXLoadPosMtxImm((MtxPtr) &m, 0);
        GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_TEX0, GX_IDENTITY,
                          GX_DISABLE, GX_PTIDENTITY);
        if (gobj != NULL) {
            HSD_StateSetNumChans(0);
        } else {
            GXSetNumChans(0U);
        }
        GXClearVtxDesc();
        GXSetCullMode(GX_CULL_NONE);
        GXSetNumTexGens(1U);
        GXSetNumTevStages(1U);
        GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_RGBA6, 0);
        GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
        GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_POS_XYZ, GX_RGBA6, 0);
        GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
        GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR_NULL);
        GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
        GXSetAlphaCompare(GX_GREATER, 0, GX_AOP_OR, GX_GREATER, GX_NEVER);
        GXSetColorUpdate(GX_ENABLE);
        GXSetAlphaUpdate(GX_DISABLE);
        if (gobj != NULL) {
            if (text->render_callback != NULL) {
                text->render_callback(gobj);
            }
        }
        GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO, GX_CC_C0);
        GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_FALSE, GX_TEVPREV);
        GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_FALSE, GX_TEVPREV);
        if (text->bg_color.a != 0) {
            f32 origin_x = text->pos_x;
            f32 origin_y = text->pos_y;
            min.x = origin_x;
            min.y = origin_y;
            max.x = (text->box_size_x * text->font_size.x) + origin_x;
            max.y = (text->box_size_y * text->font_size.y) + origin_y;
            GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_A0);
            GXSetTevColor(GX_TEVREG0, *(GXColor*) &text->bg_color);
            GXBegin(GX_QUADS, GX_VTXFMT0, 4U);
            {
                f32 depth = text->pos_z;
                f32 neg_min_y = -min.y;
                f32 neg_max_y = -max.y;
                GXPosition3f32(min.x, neg_min_y, depth);
                GXTexCoord2f32(0.0F, 0.0F);
                GXPosition3f32(max.x, neg_min_y, depth);
                GXTexCoord2f32(1.0F, 0.0F);
                GXPosition3f32(max.x, neg_max_y, depth);
                GXTexCoord2f32(1.0F, 1.0F);
                GXPosition3f32(min.x, neg_max_y, depth);
                GXTexCoord2f32(0.0F, 1.0F);
            }
        }
        GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_TEXA, GX_CA_A0, GX_CA_ZERO);
        if (text->x4E != 0) {
            min.x = (text->x14.z * text->font_size.x) + text->pos_x;
            max.x = (text->font_size.x * (text->box_size_x - text->x14.w)) + text->pos_x;
            min.y = (text->x14.x * text->font_size.y) + text->pos_y;
            max.y = (text->font_size.y * (text->box_size_y - text->x14.y)) + text->pos_y;
        }
        if (text->alloc_data != NULL) {
            text->x78.x = text->x3C.x;
            text->x78.y = text->x3C.y;
            text->alignment = text->default_alignment;
            text->kerning = text->default_kerning;
            text->fitting = text->default_fitting;
        }
        {
            f32 line_width_out = 0;
            f32 line_height_out;
            f64 half_glyph = 16.0;

            u32 line_started;
            u8 render_done = 0U;
            u8 restart_text;

            do {
            restart_text = 0U;
            text->current_height = 0.0F;
            line_started = 0U;
            saved_kerning = text->kerning;
            saved_font_size = text->x80;
            saved_color_r = text->active_color.r;
            saved_color_g = text->active_color.g;
            saved_color_b = text->active_color.b;
            saved_scale.y = text->x80.y;
            saved_scale.x = text->x78.x;
            saved_alignment = text->alignment;
            saved_spacing_y = text->x78.y;
            saved_fitting = text->fitting;
            line_delay = text->x90;
            char_delay = text->x92;
            skip_count = text->x98;
            saved_x6C = text->x6C;
            while ((sis_cursor != text->x60) || ((u8) text->x4B == 0)) {
                if ((sis_cursor == text->x60) && text->x94) {
                    text->x94--;
                } else {
                    u32 pop_result;
                    s32 clear_idx;
                    f32 x_origin;
                    s16 y_offset;
                    u8 opcode = *sis_cursor;
                    switch (*sis_cursor) {
                        case 0:
                            pop_result = HSD_SisLib_803A7F0C(text, 5);
                            if (pop_result != 0U) {
                                sis_cursor = (u8*) (pop_result + 4);
                                break;
                            }
                            render_done = 1U;
                            break;
                        case 1:
                            text->x60 = NULL;
                            clear_idx = 0;
                            text->active_color = text->text_color;
                            text->x80.x = text->x34.x;
                            text->x80.y = text->x34.y;
                            text->x78.x = text->x3C.x;
                            text->x78.y = text->x3C.y;
                            text->x90 = text->x44;
                            text->x92 = text->x46;
                            text->alignment = text->default_alignment;
                            text->kerning = text->default_kerning;
                            text->fitting = text->default_fitting;
                            text->x94 = 0U;
                            text->x4B = 0U;
                            while (clear_idx < (s32) text->x6E) {
                                *((u8*) text->string_buffer + clear_idx) = 0;
                                clear_idx += 1;
                            }
                            text->x6C = 0;
                            /* fallthrough */
                        case 2:
                            text->x98 = 0;
                            sis_cursor += 1;
                            text->sis_buffer = (SIS*) sis_cursor;
                            restart_text = 1U;
                            break;
                        case 3:
                            if (line_started == 0U) {
                                line_height_out = 32.0F * text->x80.y;
                            }
                            line_started = 0U;
                            text->current_height = (f32) ((text->font_size.y * ((text->x80.y * text->x78.y) + line_height_out)) + text->current_height);
                            if (skip_count != 0U) {
                                skip_count -= 1;
                            } else {
                                text->x98 = (u32) (text->x98 + 1);
                                text->x94 = (u32) char_delay;
                                text->x60 = (void*) (sis_cursor + 1);
                            }
                            break;
                        case 4:
                            if (skip_count != 0U) {
                                skip_count -= 1;
                            } else {
                                text->x98 = (u32) (text->x98 + 1);
                                text->x4B = 1U;
                                text->x60 = (void*) (sis_cursor + 1);
                            }
                            break;
                        case 5:
                            if (skip_count != 0U) {
                                skip_count -= 1;
                            } else {
                                text->x98 = (u32) (text->x98 + 1);
                                text->x94 = *(u16*) (sis_cursor + 1);
                                text->x60 = (void*) (sis_cursor + 3);
                            }
                            sis_cursor += 2;
                            break;
                        case 6:
                            line_delay = *(u16*) (sis_cursor + 1);
                            char_delay = *(u16*) (sis_cursor + 3);
                            sis_cursor += 4;
                            break;
                        case 7:
                            line_started = 1U;
                            HSD_SisLib_803A8134((void*) (sis_cursor + 5), text, &line_width_out, &line_height_out);
                            x_origin = (f32) *(s16*) (sis_cursor + 1);
                            if (((u8) text->fitting == 1) && (text->box_size_x < line_width_out) != 0) {
                                text->x88 = (f32) (text->box_size_x / line_width_out);
                            } else {
                                text->x88 = 1.0F;
                            }
                            switch ((s32) text->alignment) {
                            case 1:
                                text->current_width = (f32) -((0.5F * (line_width_out * text->x88)) - x_origin);
                                break;
                            case 2:
                                text->current_width = (f32) -((line_width_out * text->x88) - x_origin);
                                break;
                            default:
                                text->current_width = x_origin;
                                break;
                            }
                            y_offset = *(s16*) (sis_cursor + 3);
                            sis_cursor += 4;
                            text->current_height = (f32) ((f32) y_offset * text->font_size.y);
                            break;
                        case 9:
                            HSD_SisLib_803A7684(text, sis_cursor, 5U);
                            /* fallthrough */
                        case 8:
                            sis_cursor = (u8*) *(s32*) (sis_cursor + 1) - 1;
                            break;
                        case 10:
                            if (((u32) text->alloc_data == 0U) || (saved_kerning == 0)) {
                                HSD_SisLib_803A7684(text, sis_cursor, 1U);
                                text->x78.x = (f32) ((f32) *(s16*) (sis_cursor + 1) * 0.00390625F);
                                text->x78.y = (f32) ((f32) *(s16*) (sis_cursor + 3) * 0.00390625F);
                            }
                            sis_cursor += 4;
                            break;
                        case 11:
                            if (((u32) text->alloc_data == 0U) || (saved_kerning == 0)) {
                                HSD_SisLib_803A7F0C(text, 1);
                            }
                            break;
                        case 12:
                            HSD_SisLib_803A7684(text, sis_cursor, 2U);
                            text->active_color.r = sis_cursor[1];
                            text->active_color.g = sis_cursor[2];
                            text->active_color.b = sis_cursor[3];
                            sis_cursor += 3;
                            break;
                        case 13:
                            HSD_SisLib_803A7F0C(text, 2);
                            break;
                        case 14:
                            HSD_SisLib_803A7684(text, sis_cursor, 3U);
                            text->x80.x = (f32) ((f32) *(u16*) (sis_cursor + 1) * 0.00390625F);
                            text->x80.y = (f32) ((f32) *(u16*) (sis_cursor + 3) * 0.00390625F);
                            sis_cursor += 4;
                            break;
                        case 15:
                            HSD_SisLib_803A7F0C(text, 3);
                            break;
                        case 16:
                            HSD_SisLib_803A7684(text, sis_cursor, 4U);
                            text->alignment = 1U;
                            break;
                        case 18:
                            HSD_SisLib_803A7684(text, sis_cursor, 4U);
                            text->alignment = 0U;
                            break;
                        case 20:
                            HSD_SisLib_803A7684(text, sis_cursor, 4U);
                            text->alignment = 2U;
                            break;
                        case 17:
                        case 19:
                        case 21:
                            HSD_SisLib_803A7F0C(text, 4);
                            break;
                        case 22:
                            text->kerning = 1U;
                            break;
                        case 23:
                            text->kerning = 0U;
                            break;
                        case 24:
                            text->fitting = 1U;
                            break;
                        case 25:
                            text->fitting = 0U;
                            break;
                        case 26:
                            if (line_started == 0U) {
                                line_started += 1;
                                HSD_SisLib_803A8134(sis_cursor, text, &line_width_out, &line_height_out);
                                if (((u8) text->fitting == 1) && (text->box_size_x < line_width_out)) {
                                    text->current_width = 0.0F;
                                    text->x88 = (f32) (text->box_size_x / line_width_out);
                                } else {
                                    text->x88 = 1.0F;
                                    switch ((s32) text->alignment) {
                                    case 1:
                                        text->current_width = (f32) (0.5F * (text->box_size_x - line_width_out));
                                        break;
                                    case 2:
                                        text->current_width = (f32) (text->box_size_x - line_width_out);
                                        break;
                                    default:
                                        text->current_width = 0.0F;
                                        break;
                                    }
                                }
                            }
                            text->current_width = (f32) (((f64) text->x88 * ((f64) text->x80.x *
                                            (half_glyph + (f64) text->x78.x))) + (f64) text->current_width);
                            if (skip_count != 0U) {
                                skip_count -= 1;
                            } else {
                                text->x98 = (u32) (text->x98 + 1);
                                text->x94 = (u32) line_delay;
                                text->x60 = (void*) (sis_cursor + 1);
                            }
                            break;
                        default:
                            if (opcode >= 0x20U) {
                                u16 glyph_idx;
                                s32 tex_offset;
                                f32 scale_x;
                                f32 glyph_x;
                                if (line_started == 0U) {
                                    line_started += 1;
                                    HSD_SisLib_803A8134(sis_cursor, text, &line_width_out, &line_height_out);
                                    if (((u8) text->fitting == 1) && (text->box_size_x < line_width_out)) {
                                        text->current_width = 0.0F;
                                        text->x88 = (f32) (text->box_size_x / line_width_out);
                                    } else {
                                        text->x88 = 1.0F;
                                        switch (text->alignment) {
                                        case 1:
                                            text->current_width = (f32) (0.5F * (text->box_size_x - line_width_out));
                                            break;
                                        case 2:
                                            text->current_width = (f32) (text->box_size_x - line_width_out);
                                            break;
                                        default:
                                            text->current_width = 0.0F;
                                            break;
                                        }
                                    }
                                }
                                glyph_idx = *(u16*) sis_cursor;
                                if (glyph_idx < 0x4000U) {
                                    tex_offset = glyph_idx - 0x2000;
                                } else {
                                    tex_offset = glyph_idx - 0x4000;
                                }
                                scale_x = text->font_size.x;
                                glyph_x = (text->current_width * scale_x) + text->pos_x;
                                if ((u8) text->kerning != 0) {
                                    if (glyph_idx < 0x4000U) {
                                        glyph_x = -((scale_x * (text->x80.x * (f32) (default_kerning[(tex_offset * 2) & 0x1FFFE] - 1))) - glyph_x);
                                    } else {
                                        glyph_x = -((scale_x * (text->x80.x * (f32) (textures->data[(tex_offset * 2) & 0x1FFFE] - 1))) - glyph_x);
                                    }
                                }
                                {
                                    GXTexObj tex_obj;
                                    f32 glyph_size = 32.0F * text->x80.x;
                                    f32 scale_y = text->font_size.y;
                                    f32 uv_top = 0.0F;
                                    f32 glyph_w = 32.0F * text->x80.x * scale_x;
                                    f32 glyph_y = (scale_y * (line_height_out - glyph_size)) + (text->pos_y + text->current_height);
                                    f32 glyph_h = glyph_size * scale_y;
                                    f32 uv_bottom = 1.0F;
                                    f32 uv_left = 0.0F;
                                    f32 quad_top = glyph_y;
                                    f32 uv_right = 1.0F;
                                    f32 quad_right = (text->x88 * glyph_w) + glyph_x;
                                    f32 quad_bottom = glyph_y + glyph_h;
                                    u8 draw_glyph = 1U;
                                    if ((u8) text->x4E != 0) {
                                        if ((min.x > quad_right) || (max.x < glyph_x) || (min.y > quad_bottom) || (max.y < quad_top)) {
                                            draw_glyph = 0U;
                                        } else {
                                            if (min.x > glyph_x) {
                                                f32 clip_left = min.x - glyph_x;
                                                uv_left = clip_left / glyph_w;
                                                glyph_x += clip_left;
                                            }
                                            if (max.x < quad_right) {
                                                f32 clip_right = quad_right - max.x;
                                                uv_right = 1.0F - (clip_right / glyph_w);
                                                quad_right -= clip_right;
                                            }
                                            if (min.y > quad_top) {
                                                f32 clip_top = min.y - quad_top;
                                                uv_top = clip_top / glyph_h;
                                                quad_top += clip_top;
                                            }
                                            if (max.y < quad_bottom) {
                                                f32 clip_bottom = quad_bottom - max.y;
                                                uv_bottom = 1.0F - (clip_bottom / glyph_h);
                                                quad_bottom -= clip_bottom;
                                            }
                                        }
                                    }
                                    if (draw_glyph != 0U) {
                                        if (glyph_idx < 0x4000U) {
                                            GXInitTexObj(&tex_obj, data + ((tex_offset << 9) & 0x01FFFE00), 0x20U, 0x20U, GX_TF_I4, GX_CLAMP, GX_CLAMP, 0U);
                                        } else {
                                            GXInitTexObj(&tex_obj, HSD_SisLib_BytePtr(kerning) + ((tex_offset << 9) & 0x01FFFE00), 0x20U, 0x20U, GX_TF_I4, GX_CLAMP, GX_CLAMP, 0U);
                                        }
                                        GXLoadTexObj(&tex_obj, GX_TEXMAP0);
                                        GXSetTevColor(GX_TEVREG0, *(GXColor*) &text->active_color);
                                        GXBegin(GX_QUADS, GX_VTXFMT0, 4U);
                                        {
                                            f32 glyph_depth = text->pos_z;
                                            f32 neg_quad_top = -quad_top;
                                            f32 neg_quad_bottom = -quad_bottom;
                                            GXPosition3f32(glyph_x, neg_quad_top, glyph_depth);
                                            GXTexCoord2f32(uv_left, uv_top);
                                            GXPosition3f32(quad_right, neg_quad_top, glyph_depth);
                                            GXTexCoord2f32(uv_right, uv_top);
                                            GXPosition3f32(quad_right, neg_quad_bottom, glyph_depth);
                                            GXTexCoord2f32(uv_right, uv_bottom);
                                            GXPosition3f32(glyph_x, neg_quad_bottom, glyph_depth);
                                            GXTexCoord2f32(uv_left, uv_bottom);
                                        }
                                    }

                                    text->current_width = (f32) ((text->x88 * (text->x80.x * (32.0F + text->x78.x))) + text->current_width);
                                    if ((u8) text->kerning != 0) {
                                        if (glyph_idx < 0x4000U) {
                                            u8* kern_pair = &default_kerning[(tex_offset * 2) & 0x1FFFE];
                                            text->current_width = (f32) -((text->x88 * (text->x80.x * (f32) (kern_pair[0] + (kern_pair[1] - 2)))) - text->current_width);
                                        } else {
                                            u8* kern_pair = &textures->data[(tex_offset * 2) & 0x1FFFE];
                                            text->current_width = (f32) -((text->x88 * (text->x80.x * (f32) (kern_pair[0] + (kern_pair[1] - 2)))) - text->current_width);
                                        }
                                    }
                                    if (skip_count != 0U) {
                                        skip_count -= 1;
                                    } else {
                                        text->x98 = (u32) (text->x98 + 1);
                                        text->x94 = (u32) line_delay;
                                        text->x60 = (void*) (sis_cursor + 2);
                                    }
                                    sis_cursor += 1;
                            }
                        }
                    }
                }
                if ((render_done != 0U) || (restart_text != 0U)) {
                    break;
                }
                sis_cursor++;
            }
            } while ((restart_text != 0U) && (render_done == 0U));
            HSD_StateInvalidate(-1);
            text->active_color.r = saved_color_r;
            text->active_color.g = saved_color_g;
            text->active_color.b = saved_color_b;
            text->x80.x = saved_font_size.x;
            text->x80.y = saved_font_size.y;
            text->x78.x = saved_scale.x;
            text->x78.y = saved_scale.y;
            text->alignment = saved_alignment;
            text->kerning = saved_kerning;
            text->fitting = saved_fitting;
            text->x6C = saved_x6C;
            {
                s32 clear_i = text->x6C;
                while ((s32) clear_i < (s32) text->x6E) {
                    *((u8*) text->string_buffer + clear_i) = 0;
                    clear_i += 1;
                }
            }
        }
    }
}

HSD_Archive* kar_sislib_load_archive_wrapper(char* path)
{
    return kar_lbarchive__800596b4(path);
}

void kar_sislib_release_archive_wrapper(HSD_Archive* archive)
{
    kar_lbarchive__80059798(archive);
}

extern void kar_diagnostic__803d7e58(void* mutex); /* OSLockMutex */
extern void kar_diagnostic__803d7f34(void* mutex);  /* OSUnlockMutex */

extern s32 kar_gcpmemcard_calc_save_descriptor_size(void* save_desc);
extern s32 kar_gcpmemcard_compare_generation8(void);

s32 kar_memcard_mount_card_for_preload(s32 chan);
s32 kar_memcard_check_card_for_preload(s32 chan);
s32 kar_memcard_open_current_save_file(void);
s32 kar_memcard_write_region0_tail_then_linear(s32 arg0);
s32 kar_memcard_write_linear_region_payload(s32 arg0);
s32 kar_memcard_write_mirror_region_payload(s32 arg0);
s32 kar_memcard_write_remapped_region_payload(s32 arg0);

typedef struct MemCardRegionRec {
    s32 unk0;
    s32 mode;   //0x04 0=linear, 1=mirror, 2=remapped
    s32 unk8;
    s32 count;  //0x0C
    s32 base_idx; //0x10
    s32 status; //0x14
    s32 unk18;
    s32 dirty;  //0x1C
    s32 unk20;
} MemCardRegionRec; //0x24

typedef struct MemCardSaveDesc {
    u8 pad[0x24];
    s32 region_count; //0x24
    s32 unk28;
} MemCardSaveDesc;

typedef struct MemCardMountCtx {
    u8 pad[0x60];
    MemCardRegionRec* region_table; //0x60
    MemCardSaveDesc* save_desc;     //0x64
} MemCardMountCtx;

s32 lbl_8059A880[0x5D80];

#define MC_BASE ((u8*) lbl_8059A880)
#define MC_S32(off) (*(s32*) (MC_BASE + (off)))
#define MC_PTR(off) (*(void**) (MC_BASE + (off)))

s32 kar_sislib__near_80452790(void)
{
    return MC_S32(0x598);
}

void kar_memcard_mount_check_open_file(s32 chan)
{
    s32 result = kar_memcard_mount_card_for_preload(chan);
    if ((result == 0) || (result == 0xA)) {
        if (kar_memcard_check_card_for_preload(chan) == 0) {
            kar_memcard_open_current_save_file();
        }
    }
}

void kar_memcard_mount_and_check_card(s32 chan)
{
    s32 result = kar_memcard_mount_card_for_preload(chan);
    if ((result == 0) || (result == 0xA)) {
        kar_memcard_check_card_for_preload(chan);
    }
}

s32 kar_memcard_decode_icon_sector_header(u8* data, s32* arg1, s32* arg2, s32* arg3, s32* arg4,
                                          s32* arg5)
{
    if (arg2 != NULL) {
        *arg2 = (data[0] << 8) | data[1];
    }
    if (arg3 != NULL) {
        *arg3 = data[2];
    }
    if (arg1 != NULL) {
        *arg1 = data[3];
    }
    if (arg4 != NULL) {
        *arg4 = (data[4] >> 6) & 3;
    }
    if (arg5 != NULL) {
        *arg5 = data[4] & 0x3F;
        *arg5 = (*arg5 << 8) | data[5];
        *arg5 = (*arg5 << 8) | data[6];
    }
    return 1;
}

s32 kar_memcard_get_preload_block_size(s32 chan)
{
    u8* base = MC_BASE;
    if ((chan < 0) || (chan > 1)) {
        chan = 0;
    }
    base = base + chan * 0x1C;
    return *(s32*) (base + 0x608);
}

s32 kar_sislib__near_80453398(s32 chan)
{
    u8* base = MC_BASE;
    if ((chan < 0) || (chan > 1)) {
        chan = 0;
    }
    base = base + chan * 0x1C;
    return *(s32*) (base + 0x614);
}

s32 kar_sislib__near_804533c4(s32 chan)
{
    u8* base = MC_BASE;
    if ((chan < 0) || (chan > 1)) {
        chan = 0;
    }
    base = base + chan * 0x1C;
    return *(s32*) (base + 0x600);
}

s32 kar_sislib__near_804533f0(void)
{
    s32 val;
    void* mutex = MC_BASE + 0x5A0;

    kar_diagnostic__803d7e58(mutex);
    val = MC_S32(0x59C);
    kar_diagnostic__803d7f34(mutex);
    return val;
}

s32 kar_memcard_get_icon_preload_tail_bytes(void* save_desc, s32 divisor)
{
    return divisor - ((kar_gcpmemcard_calc_save_descriptor_size(save_desc) % divisor) + 0x20);
}

#pragma push
#pragma dont_inline on
s32 kar_memcard_clamp_icon_preload_length(s32* arg0, void* save_desc, s32 divisor)
{
    s32 val = *arg0;
    s32 tail = kar_memcard_get_icon_preload_tail_bytes(save_desc, divisor);
    if (val >= tail) {
        val = tail;
    }
    return val;
}
#pragma pop

void kar_memcard_refresh_linear_region_state(s32 arg0)
{
    u8* base;
    MemCardMountCtx* ctx;
    MemCardRegionRec* region_table;
    MemCardSaveDesc* save_desc;
    s32 chan;
    s32 last_field;
    MemCardRegionRec* rec;
    s32 base_idx;
    s32 i;
    s32 idx;

    base = MC_BASE;
    ctx = MC_PTR(0x0);
    chan = MC_S32(0x50C);
    region_table = ctx->region_table;
    save_desc = ctx->save_desc;
    last_field = 0;

    if (arg0 == 0) {
        s32 region_count = save_desc->region_count;
        if (*(s32*) (base + 0x9614 + (region_count - 1) * 4) == 0) {
            rec = (MemCardRegionRec*) ((u8*) region_table + arg0 * 0x24 + chan * 4);
            rec->dirty = 2;
            rec->status = 0;
            return;
        }
        last_field = *(s32*) (base + 0x7624 + region_count * 4);
    }

    rec = (MemCardRegionRec*) ((u8*) region_table + arg0 * 0x24);
    base_idx = rec->base_idx;
    for (i = 0; i < rec->count; i++) {
        idx = i + base_idx;
        if (((i > 0) || (arg0 == 0)) && (last_field != *(s32*) (base + 0x7628 + idx * 4))) {
            rec = (MemCardRegionRec*) ((u8*) region_table + arg0 * 0x24 + chan * 4);
            rec->dirty = 2;
            rec->status = 0;
            return;
        }
        last_field = *(s32*) (base + 0x7628 + idx * 4);
        if (*(s32*) (base + 0x9614 + idx * 4) == 0) {
            rec = (MemCardRegionRec*) ((u8*) region_table + arg0 * 0x24 + chan * 4);
            rec->dirty = 2;
            rec->status = 0;
            return;
        }
    }
    rec = (MemCardRegionRec*) ((u8*) region_table + arg0 * 0x24 + chan * 4);
    rec->dirty = 0;
    rec->status = last_field;
}

static s32 lbl_805E6280 = -1;
static s32 lbl_805E6284 = -1;
static s32 lbl_805E6288 = 1;
static s32 lbl_805E628C = 1;

s32 kar_memcard_resolve_mirror_region_side(s32 arg0)
{
    u8* base;
    s32 status[2];
    s32 flag[2];
    MemCardMountCtx* ctx;
    MemCardRegionRec* rec;
    s32 side;
    s32 i;
    s32 idx;

    base = MC_BASE;
    ctx = MC_PTR(0x0);
    rec = (MemCardRegionRec*) ((u8*) ctx->region_table + arg0 * 0x24);
    status[0] = lbl_805E6280;
    status[1] = lbl_805E6284;
    flag[0] = lbl_805E6288;
    flag[1] = lbl_805E628C;

    for (side = 0; side < 2; side++) {
        for (i = 0; i < rec->count; i++) {
            idx = rec->base_idx + side * rec->count + i;
            if (*(s32*) (base + 0x9614 + idx * 4) == 0) {
                flag[side] = 0;
                status[side] = -1;
                break;
            }
            if ((i > 0) && (*(s32*) (base + 0x7628 + idx * 4) != status[side])) {
                flag[side] = 0;
                status[side] = -1;
                break;
            }
            status[side] = *(s32*) (base + 0x7628 + idx * 4);
        }
    }

    if ((flag[0] != 0) && (flag[1] != 0)) {
        if (status[0] == status[1]) {
            return 0;
        }
        {
            s32 gen = kar_gcpmemcard_compare_generation8();
            s32 t = (-gen) & ~gen;
            return (t >> 31) + 2;
        }
    }
    if ((flag[0] != 0) && (flag[1] == 0)) {
        return 1;
    }
    if ((flag[0] == 0) && (flag[1] != 0)) {
        return 2;
    }
    return -1;
}

s32 kar_memcard_write_linear_or_region0(s32 arg0)
{
    if (arg0 == 0) {
        return kar_memcard_write_region0_tail_then_linear(arg0);
    }
    return kar_memcard_write_linear_region_payload(arg0);
}

#pragma push
#pragma dont_inline on
s32 kar_memcard_write_region_by_mode(s32 arg0)
{
    void* p = MC_PTR(0x0);
    s32 mode;
    p = *(void**) ((u8*) p + 0x60);
    p = (u8*) p + arg0 * 0x24;
    mode = *(s32*) ((u8*) p + 4);

    if (mode != 1) {
        goto check2;
    }
    return kar_memcard_write_mirror_region_payload(arg0);
check2:
    if (mode != 2) {
        goto check3;
    }
    return kar_memcard_write_remapped_region_payload(arg0);
check3:
    if (mode == 0) {
        return kar_memcard_write_linear_or_region0(arg0);
    }
    return 0;
}
#pragma pop
