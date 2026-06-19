#include "functions.h"
#include <dolphin/types.h>
#include <sysdolphin/jobj.h>

#define WNPARTS_MAX_PARTS 10

typedef struct WnParts WnParts;
typedef struct WnModel WnModel;
typedef struct WnPartsStrings WnPartsStrings;

struct WnModel {
    u8 pad_00[0x28];
    HSD_JObj* jobj;
};

struct WnParts {
    WnModel* model;
    s32 kind;
    u8 pad_08[0x14];
    u8 part_num;
    u8 pad_1D[0x4F];
    HSD_JObj** parts;
    u8 pad_70[0xA4];
    void* effect_a;
    void* effect_b;
    u8 pad_11C[0x10];
    f32 timer;
};

struct WnPartsStrings {
    char parts_num_over[0x1C];
    char filename[0x0C];
    char parts_num_not_match[0x20];
};

WnPartsStrings lbl_804B4450 = {
    "weapon parts num over! %d\n",
    "wnparts.c",
    "weapon parts num not match! %d\n",
};
char lbl_805D71C0[] = "0";
const f32 lbl_805E2858[2] = { 9999.0f, 0.0f };

void OSReport(const char* fmt, ...);
u32 HSD_JObjGetFlags(HSD_JObj* jobj);
void* kar_efdata__near_802364e0(void);
void kar_efdata__near_8023641c(void* effect);
void kar_efdata__near_80236778(void* effect);
void kar_efdata__near_80236358(void* effect);

#define LOAD_F32(sym) (*(const f32*) &(sym))

void kar_wnparts__80221914(WnParts* parts)
{
    WnPartsStrings* strings;
    s32 offset;
    HSD_JObj* jobj;
    s32 count;
    HSD_JObj* temp;
    HSD_JObj* parent;

    strings = &lbl_804B4450;
    count = 0;
    jobj = parts->model->jobj;
    if (parts->part_num > WNPARTS_MAX_PARTS) {
        OSReport((char*) strings + 0x00, parts->kind);
        __assert((char*) strings + 0x1C, 0x23, lbl_805D71C0);
    }

    offset = 0;
    while (jobj != NULL) {
        *(HSD_JObj**) ((u8*) parts->parts + offset) = jobj;
        count++;
        offset += sizeof(HSD_JObj*);

        if ((HSD_JObjGetFlags(jobj) & INSTANCE) == 0) {
            if (jobj == NULL) {
                temp = NULL;
            } else {
                temp = jobj->child;
            }
            if (temp != NULL) {
                if (jobj == NULL) {
                    jobj = NULL;
                } else {
                    jobj = jobj->child;
                }
                continue;
            }
        }

        if (jobj == NULL) {
            temp = NULL;
        } else {
            temp = jobj->next;
        }
        if (temp != NULL) {
            if (jobj == NULL) {
                jobj = NULL;
            } else {
                jobj = jobj->next;
            }
            continue;
        }

parent_check:
        if (jobj == NULL) {
            temp = NULL;
        } else {
            temp = jobj->parent;
        }
        if (temp == NULL) {
            jobj = NULL;
            continue;
        }

        if (jobj == NULL) {
            parent = NULL;
        } else {
            parent = jobj->parent;
        }
        if (parent == NULL) {
            temp = NULL;
        } else {
            temp = parent->next;
        }
        if (temp != NULL) {
            if (jobj == NULL) {
                parent = NULL;
            } else {
                parent = jobj->parent;
            }
            if (parent == NULL) {
                jobj = NULL;
            } else {
                jobj = parent->next;
            }
            continue;
        }

        if (jobj == NULL) {
            jobj = NULL;
        } else {
            jobj = jobj->parent;
        }
        goto parent_check;
    }

    if (count != parts->part_num) {
        OSReport((char*) strings + 0x28, parts->kind);
        __assert((char*) strings + 0x1C, 0x45, lbl_805D71C0);
    }
}

void kar_wnparts__near_80221ae0(WnParts* parts, f32 amount)
{
    f32 timer;
    f32 max;
    f32 result;

    timer = parts->timer;
    max = LOAD_F32(lbl_805E2858[0]);
    result = timer + amount;
    parts->timer = result;
    result = parts->timer;
    if (result > max) {
        parts->timer = max;
    }
}

void kar_wnparts__near_80221b04(WnParts* parts)
{
    parts->effect_a = kar_efdata__near_802364e0();
    parts->effect_b = kar_efdata__near_802364e0();
}

void kar_wnparts__near_80221b3c(WnParts* parts)
{
    kar_efdata__near_8023641c(parts->effect_a);
    kar_efdata__near_8023641c(parts->effect_b);
    kar_efdata__near_80236778(parts->effect_a);
    kar_efdata__near_80236778(parts->effect_b);
}

void kar_wnparts__near_80221b84(WnParts* parts)
{
    kar_efdata__near_80236358(parts->effect_a);
}

void kar_wnparts__near_80221ba8(WnParts* parts)
{
    kar_efdata__near_80236358(parts->effect_b);
}
