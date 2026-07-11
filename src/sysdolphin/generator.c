#include <global.h>

#include <dolphin/mtx/mtx.h>
#include <dolphin/mtx/vec.h>
#include <kar/math.h>
#include <sysdolphin/cobj.h>
#include <sysdolphin/constants.h>
#include <sysdolphin/list.h>
#include <sysdolphin/memory.h>
#include <sysdolphin/mtx.h>
#include <sysdolphin/object.h>
#include <sysdolphin/particle.h>
#include <sysdolphin/psinterpret.h>
#include <sysdolphin/random.h>

extern void memset(void*, int, int);
extern HSD_SList* HSD_SListAppend(HSD_SList* node, void* data);

extern void kar_psdisp__near_80437cd8(HSD_Generator* gp, s32 status);
extern s32 kar_psdisp__near_80437fcc(HSD_Generator* gp);

extern HSD_CObj* lbl_805DE380; /* psCamera */
extern void* lbl_805DE390;
extern int (*lbl_805DE384)(HSD_Generator* gen);
extern int (*lbl_805DE388)(HSD_Generator* gen);
extern HSD_SList* lbl_805DE370;
extern HSD_Generator* lbl_805DE378;
extern HSD_Generator* lbl_805DE374;
extern HSD_Generator* lbl_805DE37C;
extern u16 lbl_805DCDD0;
extern u16 lbl_805DE364;
extern u16 lbl_805DE35E;

extern f32 HSD_FloatEpsilon[];
extern u32 lbl_8058C608[];
extern HSD_PSCmdList** lbl_8058C708[];
extern void** lbl_8058C408[];

char kar_src_generator_80505230[] = "generator.c";
char lbl_8050523C[] = "psCamera";

extern char kar_srcfile_jobj_h_805dcdd4[7]; /* "jobj.h" */
extern char lbl_805DCDDC[5]; /* "jobj" */

#define assert_line_named(line, cond, condstr) \
    ((cond) ? ((void) 0) : __assert(kar_src_generator_80505230, line, condstr))
#define assert_line_jobjh(line, cond) \
    ((cond) ? ((void) 0) : __assert(kar_srcfile_jobj_h_805dcdd4, line, lbl_805DCDDC))

void kar_generator__804309e8(HSD_Generator* gen);
f32 kar_generator__near_80431c44(f32 x);
f32 kar_generator__near_804320a0(f32 x);
void kar_generator__near_804324ec(u32 mask);
HSD_Generator* kar_generator__near_804328a0(int linkNo, int bank, int kind,
                                            HSD_JObj* jobj);
HSD_Generator* kar_generator__near_8043294c(int linkNo, int bank, int kind,
                                            HSD_JObj* jobj);
HSD_Generator* kar_generator__near_80433098(int linkNo, int bank, int kind,
                                            HSD_JObj* jobj);
void kar_generator__near_80433154(HSD_CObj* cobj);
void kar_generator__near_80433240(void* obj);
void kar_generator__near_8043332c(void);
void kar_generator__near_804333d4(HSD_Particle* pp, f32* x, f32* y, f32* z);
f32 kar_generator__near_804335ac(f32 x);
f32 kar_generator__near_80433a08(f32 x);
void kar_generator__near_80433e54(HSD_Particle* pp, f32* x, f32* y, f32* z);

static inline f32 generator_sqrtf(f32 x)
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

static inline void genDirCone(HSD_Generator* gen, Mtx mtx, f32 fixedAngle)
{
    f32 radius;
    f32 x, y, z;
    f32 r;

    radius = gen->radius;
    if (radius < 0.0F) {
        r = -radius;
    } else {
        r = generator_sqrtf(HSD_Randf()) * radius;
    }

    x = r * kar_generator__near_804320a0(fixedAngle);
    y = r * kar_generator__near_80431c44(fixedAngle);
    z = 0.0F;

    {
        Vec dst;
        PSMTXMultVec(mtx, (Vec*) &x, &dst);
        dst.x += gen->pos.x;
        dst.y += gen->pos.y;
        dst.z += gen->pos.z;
        psGenerateParticle(gen->linkNo, gen->bank, gen->kind, gen->texGroup,
                           gen->cmdList, gen->life, 0, dst.x, dst.y, dst.z,
                           x, y, z, gen->size, gen->grav, gen->fric, gen);
    }
}

void kar_generator__804309e8(HSD_Generator* gen)
{
    Mtx mtx;
    Mtx billboard;
    f32 speed;
    f32 fterm;

    if (gen->count < 1.0F) {
        return;
    }

    speed = generator_sqrtf(gen->vel.x * gen->vel.x + gen->vel.y * gen->vel.y +
                            gen->vel.z * gen->vel.z);

    PSMTXIdentity(mtx);

    if ((gen->type & 0x100) && gen->jobj != NULL && (gen->type & 0x400) &&
        !(gen->kind & 0x30000)) {
        Mtx jmtx;
        PSMTXCopy(gen->jobj->mtx, jmtx);
        PSVECNormalize((Vec*) jmtx[0], (Vec*) mtx[0]);
        PSVECNormalize((Vec*) jmtx[1], (Vec*) mtx[1]);
        PSVECNormalize((Vec*) jmtx[2], (Vec*) mtx[2]);
    }

    if (gen->kind & 0x8000) {
        assert_line_named(0x22E, lbl_805DE380, lbl_8050523C);

        {
            HSD_WObj* eye = lbl_805DE380->eye_position;
            Vec look, up, right;

            look.x = eye->pos.x - gen->pos.x;
            look.y = eye->pos.y - gen->pos.y;
            look.z = eye->pos.z - gen->pos.z;
            PSVECNormalize(&look, &look);

            HSD_CObjGetUpVector(lbl_805DE380, &up);
            PSVECNormalize(&up, &up);

            PSVECCrossProduct(&up, &look, &right);
            PSVECCrossProduct(&look, &right, &up);

            billboard[0][0] = right.x;
            billboard[1][0] = right.y;
            billboard[2][0] = right.z;
            billboard[0][1] = up.x;
            billboard[1][1] = up.y;
            billboard[2][1] = up.z;
            billboard[0][2] = look.x;
            billboard[1][2] = look.y;
            billboard[2][2] = look.z;
            billboard[0][3] = 0.0F;
            billboard[1][3] = 0.0F;
            billboard[2][3] = 0.0F;
        }
    }

    fterm = 1.0F;
    do {
        switch (gen->kind & 0xF) {
        case 0:
        case 3:
        case 4:
        case 6:
        case 7:
            genDirCone(gen, mtx, gen->angle);
            break;

        case 1: {
            Vec dst;
            f32 rand = HSD_Randf();
            Vec v;
            v.x = gen->vel.x * rand;
            v.y = gen->vel.y * rand;
            v.z = gen->vel.z * rand;
            PSMTXMultVec(mtx, &v, &dst);
            dst.x += gen->pos.x;
            dst.y += gen->pos.y;
            dst.z += gen->pos.z;
            psGenerateParticle(gen->linkNo, gen->bank, gen->kind,
                               gen->texGroup, gen->cmdList, gen->life, 0,
                               dst.x, dst.y, dst.z, v.x, v.y, v.z, gen->size,
                               gen->grav, gen->fric, gen);
            break;
        }

        case 2: {
            f32 angle = (gen->angle >= 0.0F) ? HSD_Randf() : -gen->angle;
            f32 azimuth = HSD_Randf() * 6.283185307179586;
            f32 s = speed * kar_generator__near_804320a0(angle);
            f32 c = speed * kar_generator__near_80431c44(angle);
            Vec v, dst;
            v.x = s * kar_generator__near_80431c44(azimuth);
            v.y = s * kar_generator__near_804320a0(azimuth);
            v.z = c;
            PSMTXMultVec(mtx, &v, &dst);
            dst.x += gen->pos.x;
            dst.y += gen->pos.y;
            dst.z += gen->pos.z;
            psGenerateParticle(gen->linkNo, gen->bank, gen->kind,
                               gen->texGroup, gen->cmdList, gen->life, 0,
                               dst.x, dst.y, dst.z, v.x, v.y, v.z, gen->size,
                               gen->grav, gen->fric, gen);
            break;
        }

        case 5: {
            Vec v, dst;
            v.x = HSD_Randf();
            v.y = HSD_Randf();
            v.z = HSD_Randf();
            PSMTXMultVec(mtx, &v, &dst);
            dst.x += gen->pos.x;
            dst.y += gen->pos.y;
            dst.z += gen->pos.z;
            psGenerateParticle(gen->linkNo, gen->bank, gen->kind,
                               gen->texGroup, gen->cmdList, gen->life, 0,
                               dst.x, dst.y, dst.z, v.x, v.y, v.z, gen->size,
                               gen->grav, gen->fric, gen);
            break;
        }

        case 8: {
            f32 lat = (gen->angle == 0.0F) ? HSD_Randf() * 6.2831855F
                                           : gen->angle * HSD_Randf();
            f32 lon = HSD_Randf() * 6.283185307179586;
            f32 s = speed * kar_generator__near_804320a0(lat);
            f32 c = speed * kar_generator__near_80431c44(lat);
            Vec v, dst;
            v.x = s * kar_generator__near_80431c44(lon);
            v.y = s * kar_generator__near_804320a0(lon);
            v.z = c;
            PSMTXMultVec(mtx, &v, &dst);
            dst.x += gen->pos.x;
            dst.y += gen->pos.y;
            dst.z += gen->pos.z;
            psGenerateParticle(gen->linkNo, gen->bank, gen->kind,
                               gen->texGroup, gen->cmdList, gen->life, 0,
                               dst.x, dst.y, dst.z, v.x, v.y, v.z, gen->size,
                               gen->grav, gen->fric, gen);
            break;
        }

        default:
            if (lbl_805DE388 != NULL) {
                lbl_805DE388(gen);
            }
            break;
        }

        gen->count -= fterm;
    } while (gen->count >= fterm);
}

#define TRIG_POLY(z, out)                                                     \
    if ((z) <= 0.7853981633974483) {                                          \
        f32 z2 = (z) * (z);                                                   \
        f32 t = z2 * (0.16666669F -                                           \
                     z2 * (0.008332824F - z2 * 0.00019587841F));              \
        out = (z) * (1.0F - t);                                               \
    } else {                                                                  \
        f32 w = (f32) (1.5707963267948966 - (f64) (z));                      \
        f32 w2 = w * w;                                                       \
        f32 t = w2 * (0.49999395F - w2 * (0.04163633F - w2 * 0.0013400711F)); \
        out = 0.9999998F - t;                                                 \
    }

f32 kar_generator__near_80431c44(f32 x)
{
    f32 y;
    f32 poly;
    BOOL neg;

    if (x != 0.0F) {
        y = (f32) ((f64) x + 1.5707963267948966);
        if (y < 0.0F) {
            y = -y;
            neg = TRUE;
            while (y > 6.283185307179586) {
                y = (f32) (y - 6.283185307179586);
            }
            if (y <= 3.141592653589793) {
                if (y <= 1.5707963267948966) {
                    TRIG_POLY(y, poly);
                } else {
                    y = (f32) (3.141592653589793 - (f64) y);
                    TRIG_POLY(y, poly);
                }
                return neg ? -poly : poly;
            } else {
                y = (f32) (y - 3.141592653589793);
                neg = !neg;
                if (y <= 1.5707963267948966) {
                    TRIG_POLY(y, poly);
                } else {
                    y = (f32) (3.141592653589793 - (f64) y);
                    TRIG_POLY(y, poly);
                }
                return neg ? -poly : poly;
            }
        } else {
            neg = FALSE;
            while (y > 6.283185307179586) {
                y = (f32) (y - 6.283185307179586);
            }
            if (y <= 3.141592653589793) {
                if (y <= 1.5707963267948966) {
                    TRIG_POLY(y, poly);
                } else {
                    y = (f32) (3.141592653589793 - (f64) y);
                    TRIG_POLY(y, poly);
                }
                return neg ? -poly : poly;
            } else {
                y = (f32) (y - 3.141592653589793);
                neg = !neg;
                if (y <= 1.5707963267948966) {
                    TRIG_POLY(y, poly);
                } else {
                    y = (f32) (3.141592653589793 - (f64) y);
                    TRIG_POLY(y, poly);
                }
                return neg ? -poly : poly;
            }
        }
    }
    return 1.0F;
}

f32 kar_generator__near_804320a0(f32 x)
{
    f32 y;
    f32 poly;
    BOOL neg;

    if (x != 0.0F) {
        if (x < 0.0F) {
            y = -x;
            neg = TRUE;
            while (y > 6.283185307179586) {
                y = (f32) (y - 6.283185307179586);
            }
            if (y <= 3.141592653589793) {
                if (y <= 1.5707963267948966) {
                    TRIG_POLY(y, poly);
                } else {
                    y = (f32) (3.141592653589793 - (f64) y);
                    TRIG_POLY(y, poly);
                }
                return neg ? -poly : poly;
            } else {
                y = (f32) (y - 3.141592653589793);
                neg = !neg;
                if (y <= 1.5707963267948966) {
                    TRIG_POLY(y, poly);
                } else {
                    y = (f32) (3.141592653589793 - (f64) y);
                    TRIG_POLY(y, poly);
                }
                return neg ? -poly : poly;
            }
        } else {
            y = x;
            neg = FALSE;
            while (y > 6.283185307179586) {
                y = (f32) (y - 6.283185307179586);
            }
            if (y <= 3.141592653589793) {
                if (y <= 1.5707963267948966) {
                    TRIG_POLY(y, poly);
                } else {
                    y = (f32) (3.141592653589793 - (f64) y);
                    TRIG_POLY(y, poly);
                }
                return neg ? -poly : poly;
            } else {
                y = (f32) (y - 3.141592653589793);
                neg = !neg;
                if (y <= 1.5707963267948966) {
                    TRIG_POLY(y, poly);
                } else {
                    y = (f32) (3.141592653589793 - (f64) y);
                    TRIG_POLY(y, poly);
                }
                return neg ? -poly : poly;
            }
        }
    }
    return 0.0F;
}

static inline void generator_JObjSetupMatrix(HSD_JObj* jobj)
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

void kar_generator__near_804324ec(u32 mask)
{
    HSD_Generator* gen;
    HSD_Generator* prev;
    HSD_Generator* freed;

    while (lbl_805DE370 != NULL) {
        gen = (HSD_Generator*) lbl_805DE370->data;
        kar_psinterpret__near_8043070c(gen);
        lbl_805DE370 = HSD_SListRemove(lbl_805DE370);
        if (gen->jobj != NULL) {
            HSD_JObjUnref(gen->jobj);
            gen->jobj = NULL;
        }
    }

    freed = NULL;
    lbl_805DE374 = NULL;
    gen = lbl_805DE378;
    while (gen != NULL) {
        if (mask & (1 << (gen->linkNo + 0x10))) {
            lbl_805DE374 = gen;
            gen = gen->next;
            continue;
        }

        if (gen->kind & 0x800) {
            lbl_805DE374 = gen;
            gen = gen->next;
            continue;
        }

        if ((gen->type & 0x100) && gen->jobj != NULL) {
            generator_JObjSetupMatrix(gen->jobj);

            if (gen->type & 0x200) {
                gen->pos.x = gen->jobj->mtx[0][3];
                gen->pos.y = gen->jobj->mtx[1][3];
                gen->pos.z = gen->jobj->mtx[2][3];
            }
            if ((gen->type & 0x800) && gen->appsrt != NULL &&
                gen->appsrt->gp == gen) {
                gen->appsrt->translate.x = gen->jobj->mtx[0][3];
                gen->appsrt->translate.y = gen->jobj->mtx[1][3];
                gen->appsrt->translate.z = gen->jobj->mtx[2][3];
            }
            if ((gen->type & 0x1000) && gen->appsrt != NULL &&
                gen->appsrt->gp == gen) {
                HSD_MtxGetScale(gen->jobj->mtx, &gen->appsrt->scale);
            }
            if ((gen->type & 0x2000) && gen->appsrt != NULL &&
                gen->appsrt->gp == gen) {
                HSD_MtxGetRotation(gen->jobj->mtx, &gen->appsrt->rot);
            }
        }

        if (gen->random >= 0.0F) {
            if (!(gen->random == 0.0F && gen->genLife == 1)) {
                gen->count += HSD_Randf() * gen->random;
            }
        }

        if (gen->count > 0.0F) {
            kar_generator__804309e8(gen);
        }

        freed = NULL;
        if (gen->genLife != 0) {
            gen->genLife -= 1;
            if (gen->genLife == 0) {
                if (gen->type & 0x80) {
                    psKillGeneratorChild(gen);
                }
                if (gen->numChild == 0) {
                    gen->random = 0.0F;
                    gen->genLife = 1;
                    freed = gen;
                } else if ((gen->type & 0x100) && gen->jobj != NULL &&
                          (gen->type & 0x1C0000) && gen->appsrt != NULL &&
                          gen->appsrt->gp == gen &&
                          gen->appsrt->usedCount != 1) {
                    gen->random = 0.0F;
                    gen->genLife = 1;
                    freed = gen;
                }
            }
        }

        if (gen->callback != NULL) {
            gen->callback(gen);
        }

        if (freed == NULL) {
            lbl_805DE374 = gen;
            gen = gen->next;
        } else {
            if (gen->appsrt != NULL) {
                kar_psdisp__near_80437fcc(gen);
            }
            lbl_805DCDD0 -= 1;
            gen->next = lbl_805DE37C;
            lbl_805DE37C = gen;

            if (lbl_805DE374 == NULL) {
                gen = lbl_805DE378 = freed->next;
            } else {
                gen = lbl_805DE374->next = freed->next;
            }
        }
    }
}

static inline BOOL generator_ref_DEC(void* o)
{
    BOOL ret;
    if ((ret = (HSD_OBJ(o)->ref_count == HSD_OBJ_NOREF))) {
        return ret;
    }
    return HSD_OBJ(o)->ref_count-- == 0;
}

static inline void generator_hsdDelete(void* object)
{
    if (object != NULL) {
        HSD_CLASS_METHOD(object)->release((HSD_Class*) object);
        HSD_CLASS_METHOD(object)->destroy((HSD_Class*) object);
    }
}

HSD_Generator* kar_generator__near_804328a0(int linkNo, int bank, int kind,
                                            HSD_JObj* jobj)
{
    HSD_Generator* gen = kar_generator__near_8043294c(linkNo, bank, kind, jobj);

    if (gen == NULL) {
        return NULL;
    }

    if (gen != NULL) {
        gen->jobj = jobj;
        if (jobj != NULL && jobj != NULL) {
            ref_INC(jobj);
        }
    }

    gen->type |= (gen->kind & 0x20000) ? 0x500 : 0x700;

    return gen;
}

HSD_Generator* kar_generator__near_8043294c(int linkNo, int bank, int kind,
                                            HSD_JObj* jobj)
{
    HSD_Generator* gen;

    if (bank >= 0x40) {
        return NULL;
    }
    if (linkNo >= 0x20) {
        return NULL;
    }
    if (kind >= (int) lbl_8058C608[bank]) {
        return NULL;
    }
    if (lbl_8058C708[bank][kind] == NULL) {
        return NULL;
    }

    if (lbl_805DE37C == NULL) {
        lbl_805DE37C = (HSD_Generator*) HSD_Alloc(0x94);
        memset(lbl_805DE37C, 0, 0x94);
    }

    gen = lbl_805DE37C;
    if (gen != NULL) {
        lbl_805DE364 += 1;
        if (lbl_805DE364 > lbl_805DE35E) {
            lbl_805DE35E = lbl_805DE364;
        }

        lbl_805DE37C = gen->next;
        if (lbl_805DE374 != NULL) {
            lbl_805DE374->next = gen->next;
        } else {
            lbl_805DE378 = gen->next;
        }

        lbl_805DCDD0 += 1;
        if (lbl_805DCDD0 < 0x100) {
            lbl_805DCDD0 = 0x100;
        }

        gen->idnum = lbl_805DCDD0;
        gen->numChild = 0;
        gen->appsrt = NULL;
        gen->callback = NULL;
    }

    if (gen == NULL) {
        return NULL;
    }

    gen->type = lbl_8058C708[bank][kind]->type;
    gen->bank = bank;
    gen->linkNo = linkNo;
    gen->kind = lbl_8058C708[bank][kind]->kind;
    gen->texGroup = (u8) lbl_8058C708[bank][kind]->texGroup;
    gen->life = lbl_8058C708[bank][kind]->life;
    gen->genLife = lbl_8058C708[bank][kind]->genLife;

    gen->pos.x = 0.0F;
    gen->pos.y = 0.0F;
    gen->pos.z = 0.0F;
    gen->vel.x = lbl_8058C708[bank][kind]->vx;
    gen->vel.y = lbl_8058C708[bank][kind]->vy;
    gen->vel.z = lbl_8058C708[bank][kind]->vz;
    gen->grav = lbl_8058C708[bank][kind]->grav;
    gen->fric = lbl_8058C708[bank][kind]->fric;
    gen->size = lbl_8058C708[bank][kind]->size;
    gen->cmdList = lbl_8058C708[bank][kind]->cmdList;
    gen->radius = lbl_8058C708[bank][kind]->radius;
    gen->angle = lbl_8058C708[bank][kind]->angle;
    gen->random = lbl_8058C708[bank][kind]->random;

    if (gen->kind & 0x100) {
        if (gen->random >= 0.0F) {
            f32 v = 1.0F + gen->random;
            gen->count = (v <= HSD_FloatEpsilon[0]) ? 0.0F : 1.0F;
        } else {
            gen->count = 1.0F - HSD_FloatEpsilon[0];
        }
    } else {
        if (gen->random >= 0.0F) {
            gen->count = HSD_Randf();
        } else {
            gen->count = 0.0F;
        }
    }

    if (lbl_8058C408[bank][gen->texGroup] != NULL) {
        if (((HSD_Generator*) lbl_8058C408[bank][gen->texGroup])->type != 0) {
            gen->kind |= 0x10;
        }
    }

    gen->jobj = NULL;
    gen->numChild = 0;

    switch (gen->type & 0xF) {
    case 0:
    case 3:
    case 4:
        if (lbl_8058C708[bank][kind]->param1 == 0.0F &&
            lbl_8058C708[bank][kind]->param2 == 0.0F) {
            gen->aux.disc.minAngle = 0.0F;
            gen->aux.disc.maxAngle = 6.2831855F;
        } else {
            gen->aux.disc.minAngle = lbl_8058C708[bank][kind]->param1;
            gen->aux.disc.maxAngle = lbl_8058C708[bank][kind]->param2;
        }
        break;

    case 1:
        gen->aux.line.x2 = lbl_8058C708[bank][kind]->param1;
        gen->aux.line.y2 = lbl_8058C708[bank][kind]->param2;
        gen->aux.line.z2 = lbl_8058C708[bank][kind]->param3;
        break;

    case 2:
        break;

    case 6:
    case 7:
        if (lbl_8058C708[bank][kind]->param1 == 0.0F &&
            lbl_8058C708[bank][kind]->param2 == 0.0F) {
            gen->aux.cone.minAngle = 0.0F;
            gen->aux.cone.maxAngle = 6.2831855F;
        } else {
            gen->aux.cone.minAngle = lbl_8058C708[bank][kind]->param1;
            gen->aux.cone.maxAngle = lbl_8058C708[bank][kind]->param2;
        }
        gen->aux.cone.height = lbl_8058C708[bank][kind]->param3;
        break;

    case 5: {
        f32 zero = 0.0F;

        gen->aux.rect.x = lbl_8058C708[bank][kind]->param1;
        gen->aux.rect.xx = lbl_8058C708[bank][kind]->param1;
        gen->aux.rect.y = lbl_8058C708[bank][kind]->param2;
        gen->aux.rect.yy = lbl_8058C708[bank][kind]->param2;
        gen->aux.rect.z = lbl_8058C708[bank][kind]->param3;
        gen->aux.rect.zz = lbl_8058C708[bank][kind]->param3;
        gen->aux.rect.zy = zero;
        gen->aux.rect.zx = zero;
        gen->aux.rect.yz = zero;
        gen->aux.rect.yx = zero;
        gen->aux.rect.xz = zero;
        gen->aux.rect.xy = zero;
        gen->aux.rect.flag = 0;

        if (lbl_8058C708[bank][kind]->param1 < 0.0F) {
            gen->aux.rect.flag |= 1;
        }
        if (lbl_8058C708[bank][kind]->param2 < 0.0F) {
            gen->aux.rect.flag |= 2;
        }
        if (lbl_8058C708[bank][kind]->param3 < 0.0F) {
            gen->aux.rect.flag |= 4;
        }
        break;
    }

    case 8: {
        f32 speed = generator_sqrtf(gen->vel.x * gen->vel.x +
                                    gen->vel.y * gen->vel.y +
                                    gen->vel.z * gen->vel.z);
        f32 horiz = generator_sqrtf(gen->vel.x * gen->vel.x +
                                    gen->vel.z * gen->vel.z);
        f32 lat, lon;

        gen->aux.sphere.speed = speed;

        if (__fabsf(horiz) < HSD_FloatMin[0]) {
            lat = (gen->vel.y >= 0.0F) ? 1.5707963F : -1.5707963F;
        } else {
            lat = (f32) kar_atan2(gen->vel.y, horiz);
        }
        gen->aux.sphere.latMid = lat;

        if (__fabsf(gen->vel.x) < HSD_FloatMin[0]) {
            lon = (gen->vel.x >= 0.0F) ? 1.5707963F : -1.5707963F;
        } else {
            lon = (f32) kar_atan2(gen->vel.z, gen->vel.x);
        }
        gen->aux.sphere.lonMid = lon;

        gen->aux.sphere.latRange = lbl_8058C708[bank][kind]->param1;
        if (gen->aux.sphere.latRange < 0.0F) {
            gen->aux.sphere.latRange = -gen->aux.sphere.latRange;
            gen->aux.sphere.speed = -gen->aux.sphere.speed;
        }
        gen->aux.sphere.lonRange = lbl_8058C708[bank][kind]->param2;
        break;
    }

    default:
        if (lbl_805DE384 != NULL) {
            lbl_805DE384(gen);
        }
        break;
    }

    if (gen->type & 0x100) {
        gen->type |= 0x800;
        kar_psdisp__near_80437cd8(gen, 0);
        if (gen->appsrt != NULL) {
            gen->appsrt->xA2 = 1;
            gen->appsrt->gp = gen;
        }
    }

    return gen;
}

HSD_Generator* kar_generator__near_80433098(int linkNo, int bank, int kind,
                                            HSD_JObj* jobj)
{
    HSD_Generator* gen = kar_generator__near_8043294c(linkNo, bank, kind, jobj);

    if (gen == NULL) {
        return NULL;
    }

    if (gen != NULL) {
        gen->jobj = jobj;
        if (jobj != NULL && jobj != NULL) {
            ref_INC(jobj);
        }
    }

    gen->type |= (gen->kind & 0x20000) ? 0x500 : 0x700;
    lbl_805DE370 = HSD_SListAppend(lbl_805DE370, gen);

    return gen;
}

void kar_generator__near_80433154(HSD_CObj* cobj)
{
    HSD_CObj* old = lbl_805DE380;

    if (old != NULL) {
        if (old != NULL && generator_ref_DEC(old)) {
            generator_hsdDelete(old);
        }
    }

    if (cobj != NULL) {
        ref_INC(cobj);
    }

    lbl_805DE380 = cobj;
}

void kar_generator__near_80433240(void* obj)
{
    void* old = lbl_805DE390;

    if (old != NULL) {
        if (old != NULL && generator_ref_DEC(old)) {
            generator_hsdDelete(old);
        }
    }

    if (obj != NULL) {
        ref_INC(obj);
    }

    lbl_805DE390 = obj;
}

void kar_generator__near_8043332c(void)
{
    void* old = lbl_805DE390;

    if (old != NULL) {
        if (old != NULL && generator_ref_DEC(old)) {
            generator_hsdDelete(old);
        }
        lbl_805DE390 = NULL;
    }
}

void kar_generator__near_804333d4(HSD_Particle* pp, f32* x, f32* y, f32* z)
{
    HSD_Generator* gen = pp->gen;

    if (gen == NULL) {
        *x = pp->pos.x;
        *y = pp->pos.y;
        *z = pp->pos.z;
    } else {
        f32 sinGrav = kar_generator__near_80433a08(pp->grav);
        f32 sinFric = kar_generator__near_80433a08(pp->fric);
        f32 cosGrav = kar_generator__near_804335ac(pp->grav);
        f32 cosFric = kar_generator__near_804335ac(pp->fric);
        f32 dz = pp->vel.z - gen->aux.disc.minAngle;
        f32 radius = gen->radius;
        f32 dx = pp->vel.x - gen->grav;
        f32 angle = gen->angle;
        f32 t;
        f32 azimuth;
        f32 sinA, cosA;

        if (radius < 0.0F) {
            radius = -radius;
        }
        if (angle < 0.0F) {
            angle = -angle;
        }

        t = (f32) tan(angle);
        radius = (dz * t + radius) * pp->vel.y;

        azimuth = dx;
        cosA = kar_generator__near_804335ac(azimuth);
        sinA = kar_generator__near_80433a08(azimuth);

        *x = gen->pos.x + (radius * cosA) * cosFric +
            ((radius * sinA) * (-sinGrav) * cosFric +
             (-radius * sinA) * (-cosGrav) * sinFric);
        *y = gen->pos.y + ((radius * sinA) * sinFric) * cosGrav +
            (radius * cosA) * sinFric * sinGrav;
        *z = gen->pos.z + (radius * cosA) * sinFric;
    }
}

f32 kar_generator__near_804335ac(f32 x)
{
    f32 y;
    f32 poly;
    BOOL neg;

    if (x != 0.0F) {
        y = (f32) ((f64) x + 1.5707963267948966);
        if (y < 0.0F) {
            y = -y;
            neg = TRUE;
            while (y > 6.283185307179586) {
                y = (f32) (y - 6.283185307179586);
            }
            if (y <= 3.141592653589793) {
                if (y <= 1.5707963267948966) {
                    TRIG_POLY(y, poly);
                } else {
                    y = (f32) (3.141592653589793 - (f64) y);
                    TRIG_POLY(y, poly);
                }
                return neg ? -poly : poly;
            } else {
                y = (f32) (y - 3.141592653589793);
                neg = !neg;
                if (y <= 1.5707963267948966) {
                    TRIG_POLY(y, poly);
                } else {
                    y = (f32) (3.141592653589793 - (f64) y);
                    TRIG_POLY(y, poly);
                }
                return neg ? -poly : poly;
            }
        } else {
            neg = FALSE;
            while (y > 6.283185307179586) {
                y = (f32) (y - 6.283185307179586);
            }
            if (y <= 3.141592653589793) {
                if (y <= 1.5707963267948966) {
                    TRIG_POLY(y, poly);
                } else {
                    y = (f32) (3.141592653589793 - (f64) y);
                    TRIG_POLY(y, poly);
                }
                return neg ? -poly : poly;
            } else {
                y = (f32) (y - 3.141592653589793);
                neg = !neg;
                if (y <= 1.5707963267948966) {
                    TRIG_POLY(y, poly);
                } else {
                    y = (f32) (3.141592653589793 - (f64) y);
                    TRIG_POLY(y, poly);
                }
                return neg ? -poly : poly;
            }
        }
    }
    return 1.0F;
}

f32 kar_generator__near_80433a08(f32 x)
{
    f32 y;
    f32 poly;
    BOOL neg;

    if (x != 0.0F) {
        if (x < 0.0F) {
            y = -x;
            neg = TRUE;
            while (y > 6.283185307179586) {
                y = (f32) (y - 6.283185307179586);
            }
            if (y <= 3.141592653589793) {
                if (y <= 1.5707963267948966) {
                    TRIG_POLY(y, poly);
                } else {
                    y = (f32) (3.141592653589793 - (f64) y);
                    TRIG_POLY(y, poly);
                }
                return neg ? -poly : poly;
            } else {
                y = (f32) (y - 3.141592653589793);
                neg = !neg;
                if (y <= 1.5707963267948966) {
                    TRIG_POLY(y, poly);
                } else {
                    y = (f32) (3.141592653589793 - (f64) y);
                    TRIG_POLY(y, poly);
                }
                return neg ? -poly : poly;
            }
        } else {
            y = x;
            neg = FALSE;
            while (y > 6.283185307179586) {
                y = (f32) (y - 6.283185307179586);
            }
            if (y <= 3.141592653589793) {
                if (y <= 1.5707963267948966) {
                    TRIG_POLY(y, poly);
                } else {
                    y = (f32) (3.141592653589793 - (f64) y);
                    TRIG_POLY(y, poly);
                }
                return neg ? -poly : poly;
            } else {
                y = (f32) (y - 3.141592653589793);
                neg = !neg;
                if (y <= 1.5707963267948966) {
                    TRIG_POLY(y, poly);
                } else {
                    y = (f32) (3.141592653589793 - (f64) y);
                    TRIG_POLY(y, poly);
                }
                return neg ? -poly : poly;
            }
        }
    }
    return 0.0F;
}

#pragma push
#pragma dont_inline on
void kar_generator__near_80433e54(HSD_Particle* pp, f32* x, f32* y, f32* z)
{
    HSD_psAppSRT* srt;
    Mtx mtx;
    Vec v;

    kar_generator__near_804333d4(pp, x, y, z);

    srt = pp->appsrt;
    HSD_MtxSRT(mtx, &srt->scale, &srt->rot, &srt->translate, NULL);

    v.x = *x;
    v.y = *y;
    v.z = *z;
    PSMTXMultVec(mtx, &v, &v);

    *x = v.x;
    *y = v.y;
    *z = v.z;
}
#pragma pop
