#include <global.h>

#include <dolphin/mtx/vec.h>
#include <sysdolphin/jobj.h>
#include <sysdolphin/list.h>
#include <sysdolphin/memory.h>
#include <sysdolphin/mtx.h>
#include <sysdolphin/psinterpret.h>
#include <sysdolphin/pslist.h>

typedef struct HSD_psAppSRT HSD_psAppSRT;

struct HSD_Generator {
    HSD_Generator* next;   //0x00
    u8 pad04[0x08 - 0x04];
    f32 random;             //0x08
    u8 pad0c[0x10 - 0x0c];
    HSD_JObj* jobj;         //0x10
    u16 genLife;            //0x14
    u16 type;               //0x16
    u8 pad18[0x1c - 0x18];
    u16 idnum;              //0x1c
    u8 pad1e[0x24 - 0x1e];
    Vec pos;                //0x24
    Vec vel;                //0x30
    u8 pad3c[0x50 - 0x3c];
    u32 numChild;           //0x50
    HSD_psAppSRT* appsrt;   //0x54
    void* userfunc;         //0x58
    void (*callback)(HSD_Generator* gen); //0x5c
    Vec line;               //0x60 (aux.line: x2,y2,z2)
    u8 pad6c[0x94 - 0x6c];
};

struct HSD_psAppSRT {
    HSD_psAppSRT* next;  //0x00
    HSD_Generator* gp;   //0x04
    Vec translate;       //0x08
    u8 pad14[0x24 - 0x14];
    Vec scale;           //0x24
    u8 pad30[0x3e - 0x30];
    u16 usedCount;       //0x3e
};

struct HSD_Particle {
    HSD_Particle* next; //0x00
};

extern void memset(void*, int, int);

extern HSD_Particle* psInterpretParticle0(HSD_Particle* pp, HSD_Particle* prev);
extern void psKillParticle(void);
extern void psKillGeneratorChild(HSD_Generator* gp);
extern void kar_generator__near_80433154(s32 count);
extern s32 kar_psdisp__near_80437fcc(HSD_Generator* gp);

extern u16 lbl_805DCDD0;

extern HSD_Generator* lbl_805DE378;
extern HSD_Generator* lbl_805DE374;
extern HSD_Generator* lbl_805DE37C;
extern u16 lbl_805DE364;
extern u16 lbl_805DE35E;
extern HSD_SList* lbl_805DE370;
extern void* lbl_805DE380;
extern void* lbl_805DE384;
extern void* lbl_805DE388;
extern void (*lbl_805DE36C)(HSD_Generator* gen, HSD_Generator* gchild, s32 bank,
                             s32 idx);

char kar_src_psinterpret_8050521c[] = "psinterpret.c";

#undef assert_line
#define assert_line(line, cond) \
    ((cond) ? ((void) 0) : __assert(kar_src_psinterpret_8050521c, line, lbl_805DCDC8))

extern char lbl_805DCDC8[8];
extern char kar_srcfile_jobj_h_805dcdd4[7]; /* "jobj.h" */
extern char lbl_805DCDDC[5];                /* "jobj" */

#define assert_line_jobjh(line, cond) \
    ((cond) ? ((void) 0) : __assert(kar_srcfile_jobj_h_805dcdd4, line, lbl_805DCDDC))

f32 lbl_805E5F20 = 0.0F;

static inline void psinterp_JObjSetupMatrix(HSD_JObj* jobj)
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
    if (!dirty) {
        return;
    }
    HSD_JObjSetupMatrixSub(jobj);
}

void psInterpretParticles(u32 flags)
{
    s32 linkNo;

    for (linkNo = 0; linkNo < 32; linkNo++, flags >>= 1) {
        if (!(flags & 0x10000)) {
            HSD_Particle* prev = NULL;
            HSD_Particle* pp = _psListGetFirst(linkNo);

            while (pp != NULL) {
                HSD_Particle* next = pp->next;
                HSD_Particle* ret = psInterpretParticle0(pp, prev);

                if (next != NULL) {
                    if (pp->next == next) {
                        prev = pp;
                    } else if (ret != next) {
                        prev = ret;
                        while (prev->next != next) {
                            assert_line(0x739, prev != NULL);
                            prev = prev->next;
                        }
                    }
                }
                pp = next;
            }
        }
    }
}

u16 kar_psinterpret__near_80430270(void)
{
    lbl_805DCDD0++;
    if (lbl_805DCDD0 < 0x100) {
        lbl_805DCDD0 = 0x100;
    }
    return lbl_805DCDD0;
}

void kar_psinterpret__near_80430298(s32 count)
{
    s32 i;

    lbl_805DE378 = NULL;
    lbl_805DE37C = NULL;

    for (i = count - 1; i >= 0; i--) {
        HSD_Generator* node = HSD_Alloc(sizeof(HSD_Generator));
        memset(node, 0, sizeof(HSD_Generator));
        if (node == NULL) {
            return;
        }
        node->next = lbl_805DE37C;
        lbl_805DE37C = node;
    }

    lbl_805DE364 = 0;
    lbl_805DE35E = 0;
    lbl_805DE370 = NULL;
    lbl_805DE380 = NULL;
    lbl_805DE388 = NULL;
    lbl_805DE384 = NULL;
    lbl_805DE374 = NULL;
    lbl_805DE36C = NULL;
    lbl_805DCDD0 = 0x100;
}

void kar_psinterpret__near_8043033c(void)
{
    HSD_Generator* node;

    psKillParticle();
    kar_psinterpret__near_8043051c();

    for (node = lbl_805DE37C; node != NULL;) {
        HSD_Generator* next = node->next;
        HSD_Free(node);
        node = next;
    }

    lbl_805DE37C = NULL;
    kar_generator__near_80433154(0);
}

void kar_psinterpret__near_80430394(s16 linkNo)
{
    u16 link = (u16) linkNo;
    HSD_Generator* gen = lbl_805DE378;
    HSD_Generator* next;
    HSD_Generator* cursor;

    lbl_805DE374 = NULL;

    while (gen != NULL) {
        next = gen->next;

        if (gen->idnum == link) {
            cursor = lbl_805DE374;

            if (gen->type & 0x80) {
                psKillGeneratorChild(gen);
            }

            if (gen->numChild != 0) {
                gen->random = lbl_805E5F20;
                gen->genLife = 1;
                cursor = gen;
            } else if ((gen->type & 0x100) && gen->jobj != NULL &&
                       (gen->type & 0x3800) && gen->appsrt != NULL &&
                       gen->appsrt->gp == gen && gen->appsrt->usedCount != 1) {
                gen->random = lbl_805E5F20;
                gen->genLife = 1;
                cursor = gen;
            } else {
                if (gen->callback != NULL) {
                    gen->callback(gen);
                }
                if (cursor == NULL) {
                    lbl_805DE378 = gen->next;
                } else {
                    cursor->next = gen->next;
                }
                if (gen->appsrt != NULL) {
                    kar_psdisp__near_80437fcc(gen);
                }
                gen->next = lbl_805DE37C;
                lbl_805DE37C = gen;
                lbl_805DE364--;
                if (gen->jobj != NULL) {
                    HSD_JObjUnref(gen->jobj);
                    gen->jobj = NULL;
                }
            }
            lbl_805DE374 = cursor;
        } else {
            lbl_805DE374 = gen;
        }
        gen = next;
    }
}

void kar_psinterpret__near_8043051c(void)
{
    HSD_Generator* gen = lbl_805DE378;

    while (gen != NULL) {
        HSD_Generator* next = gen->next;
        HSD_Generator* cursor = lbl_805DE378;

        lbl_805DE374 = NULL;
        while (cursor != NULL) {
            if (cursor == gen) {
                HSD_Generator* prev = lbl_805DE374;

                if (gen->type & 0x80) {
                    psKillGeneratorChild(gen);
                }

                if (gen->numChild != 0) {
                    gen->random = lbl_805E5F20;
                    gen->genLife = 1;
                    prev = gen;
                } else if ((gen->type & 0x100) && gen->jobj != NULL &&
                           (gen->type & 0x3800) && gen->appsrt != NULL &&
                           gen->appsrt->gp == gen &&
                           gen->appsrt->usedCount != 1) {
                    gen->random = lbl_805E5F20;
                    gen->genLife = 1;
                    prev = gen;
                } else {
                    if (gen->callback != NULL) {
                        gen->callback(gen);
                    }
                    if (prev == NULL) {
                        lbl_805DE378 = gen->next;
                    } else {
                        prev->next = gen->next;
                    }
                    if (gen->appsrt != NULL) {
                        kar_psdisp__near_80437fcc(gen);
                    }
                    gen->next = lbl_805DE37C;
                    lbl_805DE37C = gen;
                    lbl_805DE364--;
                    if (gen->jobj != NULL) {
                        HSD_JObjUnref(gen->jobj);
                        gen->jobj = NULL;
                    }
                }
                lbl_805DE374 = prev;
                if (prev != NULL) {
                    while (lbl_805DE374->next != NULL) {
                        lbl_805DE374 = lbl_805DE374->next;
                    }
                } else if (lbl_805DE378 != NULL) {
                    lbl_805DE374 = lbl_805DE378;
                    while (lbl_805DE374->next != NULL) {
                        lbl_805DE374 = lbl_805DE374->next;
                    }
                }
                break;
            }
            lbl_805DE374 = cursor;
            cursor = cursor->next;
        }
        gen = next;
    }

    while (lbl_805DE370 != NULL) {
        lbl_805DE370 = HSD_SListRemove(lbl_805DE370);
    }
}

void kar_psinterpret__near_8043070c(HSD_Generator* gen)
{
    HSD_JObj* jobj;

    if (!(gen->type & 0x100)) {
        return;
    }

    jobj = gen->jobj;
    if (jobj == NULL) {
        return;
    }

    psinterp_JObjSetupMatrix(jobj);

    if (gen->type & 0x200) {
        gen->pos.x = gen->jobj->mtx[0][3];
        gen->pos.y = gen->jobj->mtx[1][3];
        gen->pos.z = gen->jobj->mtx[2][3];
    }

    if ((gen->type & 0x800) && gen->appsrt != NULL && gen->appsrt->gp == gen) {
        gen->appsrt->translate.x = gen->jobj->mtx[0][3];
        gen->appsrt->translate.y = gen->jobj->mtx[1][3];
        gen->appsrt->translate.z = gen->jobj->mtx[2][3];
    }

    if ((gen->type & 0x1000) && gen->appsrt != NULL && gen->appsrt->gp == gen) {
        HSD_MtxGetScale(gen->jobj->mtx, &gen->appsrt->scale);
    }

    {
        Vec tmp;
        f32 axisXx, axisXy, axisXz;
        f32 axisYx, axisYy, axisYz;
        f32 axisZx, axisZy, axisZz;
        f32 velX, velY, velZ;

        tmp.x = jobj->mtx[0][0];
        tmp.y = jobj->mtx[1][0];
        tmp.z = jobj->mtx[2][0];
        PSVECNormalize(&tmp, &tmp);
        axisXx = tmp.x;
        axisXy = tmp.y;
        axisXz = tmp.z;

        tmp.x = jobj->mtx[0][1];
        tmp.y = jobj->mtx[1][1];
        tmp.z = jobj->mtx[2][1];
        PSVECNormalize(&tmp, &tmp);
        axisYx = tmp.x;
        axisYy = tmp.y;
        axisYz = tmp.z;

        tmp.x = jobj->mtx[0][2];
        tmp.y = jobj->mtx[1][2];
        tmp.z = jobj->mtx[2][2];
        PSVECNormalize(&tmp, &tmp);
        axisZx = tmp.x;
        axisZy = tmp.y;
        axisZz = tmp.z;

        velX = gen->vel.x;
        velY = gen->vel.y;
        velZ = gen->vel.z;

        gen->vel.x = axisXx * velX + axisYx * velY + axisZx * velZ;
        gen->vel.y = axisXy * velX + axisYy * velY + axisZy * velZ;
        gen->vel.z = axisXz * velX + axisYz * velY + axisZz * velZ;
    }

    if ((gen->type & 0xF) == 1) {
        f32 lineY = gen->line.y;
        f32 lineX = gen->line.x;
        f32 lineZ = gen->line.z;

        gen->line.x = jobj->mtx[0][1] * lineY + jobj->mtx[0][0] * lineX +
                      jobj->mtx[0][2] * lineZ;
        gen->line.y = jobj->mtx[1][1] * lineY + jobj->mtx[1][0] * lineX +
                      jobj->mtx[1][2] * lineZ;
        gen->line.z = jobj->mtx[2][1] * lineY + jobj->mtx[2][0] * lineX +
                      jobj->mtx[2][2] * lineZ;
    }
}
