#include <global.h>

#include <sysdolphin/mtx.h>
#include <sysdolphin/object.h>
#include <sysdolphin/particle.h>

extern void memset(void*, int, int);
extern f32 sqrtf(f32);
extern f32 tanf(f32);
extern f64 atan2(f64, f64);
extern f32 HSD_Randf(void);
extern HSD_JObj* HSD_JObjAlloc(void);
extern void HSD_JObjUnref(HSD_JObj* jobj);
extern void OSPanic(const char*, s32, const char*, ...);

extern HSD_Particle* _psListGetFirst(s32 linkNo);
extern void _psListDelete(HSD_Particle* pp, HSD_Particle* prev);
extern void psRemoveParticleAppSRT(HSD_Particle* pp);
extern s32 kar_psdisp__near_80437ddc(HSD_Particle* pp, HSD_psAppSRT* srt);
extern HSD_Particle* kar_psdisp__near_80438084(int arg);
extern void kar_psdisp__near_80438190(void);
extern HSD_Particle* kar_psdisp__near_80438238(HSD_Particle** head,
                                               s32 linkNo, s32 bank, u32 kind,
                                               u16 texGroup);
extern u16 kar_psinterpret__near_80430270(void);
extern void kar_psinterpret__near_8043051c(void);
extern void kar_psinterpret__near_80430394(s16 linkNo);

extern HSD_Particle* hsd_804D0908[0x20];
extern void hsd_8039D048(HSD_Particle* pp);
extern HSD_ObjAllocData hsdParticle_alloc_data;
extern u16 numActiveParticles;
extern int (*psCallback[])(HSD_Particle*);

/* HSD_JObj.flags bit 0x2000000: dirty-tracking suppressed */
#define JOBJ_FLAG_NO_AUTODIRTY 0x2000000

extern char kar_srcfile_jobj_h_805dcdb8[7]; /* "jobj.h" */
extern char lbl_805DCDC0[5];                /* "jobj" */

#define assert_line_jobjh(line, cond) \
    ((cond) ? ((void) 0) : __assert(kar_srcfile_jobj_h_805dcdb8, line, lbl_805DCDC0))

extern char kar_src_object_80504fb0[9]; /* "object.h" */
extern char lbl_80504FBC[0x27];         /* "HSD_OBJ(o)->ref_count != HSD_OBJ_NOREF" */
extern char kar_src_object_805051e8[9]; /* "object.h" */
extern char lbl_805051F4[0x27];         /* "HSD_OBJ(o)->ref_count != HSD_OBJ_NOREF" */

static inline void particle_ref_INC_a(void* o)
{
    if (o != NULL) {
        HSD_OBJ(o)->ref_count++;
        ((HSD_OBJ(o)->ref_count != HSD_OBJ_NOREF))
            ? ((void) 0)
            : __assert(kar_src_object_80504fb0, 93, lbl_80504FBC);
    }
}

static inline void particle_ref_INC_b(void* o)
{
    if (o != NULL) {
        HSD_OBJ(o)->ref_count++;
        ((HSD_OBJ(o)->ref_count != HSD_OBJ_NOREF))
            ? ((void) 0)
            : __assert(kar_src_object_805051e8, 93, lbl_805051F4);
    }
}

static inline void particle_JObjSetupMatrix(HSD_JObj* jobj)
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

static inline BOOL particle_JObjMtxIsDirty(HSD_JObj* jobj)
{
    BOOL result;
    assert_line_jobjh(0x25d, jobj);
    result = FALSE;
    if (!(jobj->flags & 0x800000) && (jobj->flags & 0x40)) {
        result = TRUE;
    }
    return result;
}

static inline void particle_JObjSetMtxDirty(HSD_JObj* jobj)
{
    if (jobj != NULL && !particle_JObjMtxIsDirty(jobj)) {
        HSD_JObjSetMtxDirtySub(jobj);
    }
}

/*
 * particle.c owns six 64-entry per-bank data arrays, laid out contiguously
 * in .bss: ref, texGroupCount, texGroupArray, formGroupArray, cmdListCount,
 * cmdListArray. lbl_8058C208 is 0x200 bytes (ref + texGroupCount packed
 * together); the rest are 0x100 bytes each.
 */
extern void* lbl_8058C208[128];
extern void* lbl_8058C408[64];
extern void* lbl_8058C508[64];
extern void* lbl_8058C608[64];
extern void* lbl_8058C708[64];
extern void* lbl_8058C808[256];

#define BANK_REF(b) (lbl_8058C208[b])
#define BANK_TEXCOUNT(b) (((u32*) lbl_8058C208)[64 + (b)])
#define BANK_TEXARRAY(b) (lbl_8058C408[b])
#define BANK_FORMARRAY(b) (lbl_8058C508[b])
#define BANK_CMDCOUNT(b) (((u32*) lbl_8058C608)[b])
#define BANK_CMDARRAY(b) (lbl_8058C708[b])

extern u16 lbl_805DE358; /* peak/active particle counter */
extern u16 lbl_805DE360;
extern u16 lbl_805DE366;

f32 kar_particle__near_8042bedc(f32 x);
f32 kar_particle__near_8042c338(f32 x);
void kar_particle__near_8042fe34(HSD_JObj* jobj, f32 delta);
void kar_particle__near_8042fee4(HSD_JObj* jobj, f32 delta);
void kar_particle__near_8042ff94(HSD_JObj* jobj, f32 delta);
void kar_particle__near_80430044(HSD_JObj* jobj);
s32 kar_particle__near_804300b4(f32 delta, u8 old);
void kar_particle__near_8043010c(Mtx mtx, Vec* scale, Vec* rotate,
                                  Vec* translate, Vec* arg4);

void kar_particle__8042a734(s32 bank, s32* cmdBank, s32* texBank, void* ref,
                             s32* formBank)
{
    u16 version;

    if (formBank != NULL && *formBank != *texBank) {
        OSPanic("particle.c", 93,
                "illigal form data (strange number of group)\n");
    }

    BANK_REF(bank) = ref;
    BANK_TEXCOUNT(bank) = *texBank;
    BANK_TEXARRAY(bank) = texBank + 1;
    if (formBank != NULL) {
        BANK_FORMARRAY(bank) = formBank + 1;
    } else {
        BANK_FORMARRAY(bank) = NULL;
    }

    version = *(u16*) cmdBank;
    switch (version) {
    case 0:
        BANK_CMDCOUNT(bank) = cmdBank[1];
        BANK_CMDARRAY(bank) = cmdBank + 2;
        break;
    case 0x40:
    case 0x41:
    case 0x42:
    case 0x43: {
        s32 count = cmdBank[1];
        BANK_CMDCOUNT(bank) = cmdBank[2] + count;
        BANK_CMDARRAY(bank) = cmdBank + 3 - count;
        break;
    }
    default:
        OSPanic("particle.c", 123, "psInitDataBanks: unknown version\n");
    }
}

void kar_particle__near_8042a874(s32* cmdBank, s32* texBank, s32* formBank)
{
    s32 num;
    s32 num2;
    s32* ptr;
    s32* base;
    s32 i;
    s32 version;

    version = *(u16*) cmdBank;
    if (version < 0x40) {
        if (version == 0) {
            goto version0;
        }
        goto done_cmd;
    }
    if (version >= 0x44) {
        goto done_cmd;
    }
    goto version40;

version0:
    num2 = ((s32*) cmdBank)[1];
    base = (s32*) ((u8*) cmdBank + 8);
    num = 0;
    if (num2 > 0) {
        for (i = 0; i < num2; i++) {
            ((s32*) cmdBank)[i + 2] += (s32) cmdBank;
        }
    }
    goto done_cmd;

version40:
    num = ((s32*) cmdBank)[1];
    base = (s32*) ((u8*) cmdBank + 12) - num;
    num2 = ((s32*) cmdBank)[2] + num;
    ptr = (s32*) cmdBank;
    i = 0;
    while (i < ((s32*) cmdBank)[2]) {
        if (ptr[3] != 0) {
            ptr[3] += (s32) cmdBank;
        }
        ptr++;
        i++;
    }

done_cmd:
    {
        s32 count = num2 - num;
        ptr = base + num;
        if (num < num2) {
            for (i = 0; i < count; i++) {
                s32* cmd = (s32*) ptr[0];
                if (cmd != NULL) {
                    cmd[2] = cmd[2] & 0xF1FFFFFF;
                    cmd = (s32*) ptr[0];
                    cmd[2] = cmd[2] | 0x08000000;
                }
                ptr++;
            }
        }
    }

    {
        s32 num_groups = ((s32*) texBank)[0];
        s32* groups = (s32*) texBank + 1;
        s32* cur = groups;
        s32 k;

        if (num_groups >= 1) {
            k = num_groups;
            do {
                if (cur[0] != 0) {
                    cur[0] += (s32) texBank;
                }
                cur++;
            } while (--k != 0);
        }

        cur = groups;
        if (num_groups > 0) {
            for (k = 0; k < num_groups; k++) {
                HSD_PSTexGroup* tg = (HSD_PSTexGroup*) cur[0];
                if (tg == NULL) {
                    goto next_group;
                }

                {
                    s32 ti;
                    s32 ofs;
                    for (ti = 0, ofs = 0;
                         (u32) ti < ((HSD_PSTexGroup*) cur[0])->num;
                         ti++, ofs += 4)
                    {
                        u32* entry_ptr =
                            (u32*) ((u8*) ((HSD_PSTexGroup*) cur[0]) + 24 +
                                    ofs);
                        if (*entry_ptr != 0U) {
                            *entry_ptr += (u32) texBank;
                        }
                    }
                    tg = (HSD_PSTexGroup*) cur[0];
                }

                {
                    u32 fmt = tg->fmt;
                    if (fmt != 8 && (fmt - 9) > 1) {
                        goto next_group;
                    }
                }

                if (tg->palflag & 1) {
                    s32 ofs = tg->num * 4 + 24;
                    if (*(u32*) ((u8*) tg + ofs) == 0U) {
                        goto next_group;
                    }
                    *(u32*) ((u8*) tg + ofs) += (u32) texBank;
                } else if (tg->palnum != 0) {
                    s32 ti;
                    s32 ofs;
                    ti = (s32) tg->num;
                    ofs = ti * 4;
                    for (; (u32) ti < ((HSD_PSTexGroup*) cur[0])->num +
                                          ((HSD_PSTexGroup*) cur[0])->palnum;
                         ti++, ofs += 4)
                    {
                        HSD_PSTexGroup* tg2 = (HSD_PSTexGroup*) cur[0];
                        u32* entry_ptr = (u32*) ((u8*) tg2 + 24 + ofs);
                        if (*entry_ptr != 0U) {
                            *entry_ptr += (u32) texBank;
                        }
                    }
                } else {
                    s32 ti;
                    s32 ofs;
                    ti = (s32) tg->num;
                    ofs = ti * 4;
                    for (; (u32) ti < ((HSD_PSTexGroup*) cur[0])->num * 2;
                         ti++, ofs += 4)
                    {
                        HSD_PSTexGroup* tg2 = (HSD_PSTexGroup*) cur[0];
                        u32* entry_ptr = (u32*) ((u8*) tg2 + 24 + ofs);
                        if (*entry_ptr != 0U) {
                            *entry_ptr += (u32) texBank;
                        }
                    }
                }

            next_group:
                cur++;
            }
        }

        if (formBank == NULL) {
            return;
        }
        if (num_groups >= 1) {
            s32* groups2 = (s32*) formBank + 1;

            for (i = 0; i < num_groups; i++) {
                if (groups2[0] == 0) {
                    goto next_form;
                }
                groups2[0] += (s32) formBank;
                {
                    HSD_PSFormGroup* fg = (HSD_PSFormGroup*) groups2[0];
                    u32* p2 = (u32*) fg;
                    s32 fi;
                    for (fi = 0; (u32) fi < fg->num; fi++) {
                        if (p2[1] != 0U) {
                            p2[1] += (u32) formBank;
                        }
                        p2++;
                    }
                }
            next_form:
                groups2++;
            }
        }
    }
}

void kar_particle__8042abe8(s32 bank, s32* cmdBank, s32* texBank, void* ref,
                             s32* formBank)
{
    u16 version;

    if (bank < 0x40) {
        kar_particle__near_8042a874(cmdBank, texBank, formBank);

        if (formBank != NULL && *formBank != *texBank) {
            OSPanic("particle.c", 93,
                    "illigal form data (strange number of group)\n");
        }

        BANK_REF(bank) = ref;
        BANK_TEXCOUNT(bank) = *texBank;
        BANK_TEXARRAY(bank) = texBank + 1;
        if (formBank != NULL) {
            BANK_FORMARRAY(bank) = formBank + 1;
        } else {
            BANK_FORMARRAY(bank) = NULL;
        }

        version = *(u16*) cmdBank;
        switch (version) {
        case 0:
            BANK_CMDCOUNT(bank) = cmdBank[1];
            BANK_CMDARRAY(bank) = cmdBank + 2;
            break;
        case 0x40:
        case 0x41:
        case 0x42:
        case 0x43: {
            s32 count = cmdBank[1];
            BANK_CMDCOUNT(bank) = cmdBank[2] + count;
            BANK_CMDARRAY(bank) = cmdBank + 3 - count;
            break;
        }
        default:
            OSPanic("particle.c", 123, "psInitDataBanks: unknown version\n");
        }
    }
}

void kar_particle__near_8042ad44(void)
{
    kar_psdisp__near_80438084(0);

    lbl_805DE366 = 0;
    lbl_805DE360 = 0;

    memset(lbl_8058C208, 0, sizeof(lbl_8058C208));
    memset(lbl_8058C408, 0, sizeof(lbl_8058C408));
    memset(lbl_8058C508, 0, sizeof(lbl_8058C508));
    memset(lbl_8058C608, 0, sizeof(lbl_8058C608));
    memset(lbl_8058C708, 0, sizeof(lbl_8058C708));

    lbl_805DE358 = 0;
    memset(lbl_8058C808, 0, sizeof(lbl_8058C808));
}

void kar_particle__near_8042b77c(void);

void kar_particle__near_8042af18(void)
{
    psKillParticle();
    kar_psinterpret__near_8043051c();
    kar_psdisp__near_80438190();

    memset(lbl_8058C208, 0, sizeof(lbl_8058C208));
    memset(lbl_8058C408, 0, sizeof(lbl_8058C408));
    memset(lbl_8058C508, 0, sizeof(lbl_8058C508));
    memset(lbl_8058C608, 0, sizeof(lbl_8058C608));
    memset(lbl_8058C708, 0, sizeof(lbl_8058C708));

    kar_particle__near_8042b77c();
}

HSD_Particle* psGenerateParticle0(HSD_Particle** head, int linkNo, int bank,
                                   u32 kind, u16 texGroup, u8* list, int life,
                                   int palflag, f32 x, f32 y, f32 z, f32 vx,
                                   f32 vy, f32 vz, f32 size, f32 grav, f32 fric,
                                   HSD_Generator* gp, int flgInterpret)
{
    HSD_Particle* pp;

    pp = kar_psdisp__near_80438238(head, linkNo, bank, kind, texGroup);
    if (pp == NULL) {
        return NULL;
    }

    if (gp != NULL) {
        pp->idnum = gp->idnum;
    } else {
        pp->idnum = kar_psinterpret__near_80430270();
    }

    pp->appsrt = NULL;
    if (gp != NULL && gp->appsrt != NULL) {
        kar_psdisp__near_80437ddc(pp, gp->appsrt);
    }

    pp->bank = (u8) bank;
    pp->linkNo = (u8) linkNo;
    pp->kind = kind;
    pp->texGroup = (u8) texGroup;
    pp->pos.x = x;
    pp->pos.y = y;
    pp->pos.z = z;
    pp->vel.x = vx;
    pp->vel.y = vy;
    pp->vel.z = vz;
    pp->size = size;
    pp->grav = grav;
    pp->fric = fric;
    pp->life = (u16) (life + 1);
    pp->cmdList = list;
    pp->cmdMarkPtr = 0;
    pp->cmdPtr = 0;

    if (palflag != 0) {
        pp->kind = pp->kind | 0x10;
    }

    pp->cmdWait = (u16) (list != NULL);
    pp->poseNum = 0;
    pp->palNum = 0xFF;
    pp->primCol.a = 0xFF;
    pp->primCol.b = 0xFF;
    pp->primCol.g = 0xFF;
    pp->primCol.r = 0xFF;
    pp->envCol.a = 0;
    pp->envCol.b = 0;
    pp->envCol.g = 0;
    pp->envCol.r = 0;
    pp->envColCount = 0;
    pp->primColCount = 0;
    pp->sizeCount = 0;

    pp->aCmpMode = 0x33;
    pp->aCmpParam1 = (u8) (((kind >> 0x16) & 3) < 2);
    pp->aCmpParam2 = 0xFF;
    pp->aCmpCount = 0;
    pp->rotateCount = 0;
    pp->spreadRate = 0.0F;
    pp->rotateTarget = 0.0F;
    pp->rotate = 0.0F;
    pp->gen = gp;
    if (gp != NULL) {
        gp->numChild = gp->numChild + 1;
    }

    pp->pJObjOfs = 0;
    pp->aCmpRemain = 0;
    pp->matColCount = 0;
    pp->matRGB = 0xFF;
    pp->matA = 0xFF;
    pp->aCmpParam1Target = 0;
    pp->aCmpParam2Target = 0;
    pp->ambColCount = 0;
    pp->ambRGB = 0xFF;
    pp->ambA = 0xFF;
    pp->trail = 1.0F;
    pp->pauseCount = 0;
    pp->userdata = NULL;

    if (gp != NULL) {
        if (gp->userfunc != NULL) {
            if (gp->userfunc->hookCreate != NULL) {
                gp->userfunc->hookCreate(pp);
            }
        }
    }

    pp->callback = NULL;
    if (flgInterpret != 0) {
        psInterpretParticle0(pp, 0);
    }
    return pp;
}

HSD_Particle* psGenerateParticleID0(HSD_Particle** head, int linkNo, int bank,
                                    int id, int flgInterpret)
{
    HSD_PSCmdList* cl;
    HSD_PSTexGroup* tg;
    s32 palflag;

    if (linkNo < 0 || linkNo >= 0x20) {
        return NULL;
    }
    if (bank < 0 || bank >= 0x40) {
        return NULL;
    }
    if (id >= (s32) BANK_CMDCOUNT(bank)) {
        return NULL;
    }

    cl = ((HSD_PSCmdList**) BANK_CMDARRAY(bank))[id];
    if (cl == NULL) {
        return NULL;
    }

    tg = ((HSD_PSTexGroup**) BANK_TEXARRAY(bank))[cl->texGroup];
    if (tg != NULL) {
        palflag = tg->palflag;
    } else {
        palflag = 0;
    }

    return psGenerateParticle0(head, linkNo, bank, cl->kind, cl->texGroup,
                                cl->cmdList, cl->life, palflag, 0.0F, 0.0F,
                                0.0F, cl->vx, cl->vy, cl->vz, cl->size,
                                cl->grav, cl->fric, NULL, flgInterpret);
}

HSD_Particle* psGenerateParticle(int linkNo, int bank, u32 kind, u16 texGroup,
                                  u8* list, int life, f32 x, f32 y, f32 z,
                                  f32 vx, f32 vy, f32 vz, f32 size, f32 grav,
                                  f32 fric, int palflag, HSD_Generator* gp)
{
    return psGenerateParticle0(NULL, linkNo, bank, kind, texGroup, list, life,
                                palflag, x, y, z, vx, vy, vz, size, grav, fric,
                                gp, 1);
}

void psKillParticle(void)
{
    s32 linkNo;
    HSD_Particle* pp;
    HSD_Particle* next;
    HSD_Particle* cur;
    HSD_Particle* prev;

    for (linkNo = 0; linkNo < 0x20; linkNo++) {
        pp = _psListGetFirst(linkNo);
        while (pp != NULL) {
            next = pp->next;
            prev = NULL;
            for (cur = _psListGetFirst(pp->linkNo); cur != NULL;
                 cur = cur->next)
            {
                if (cur == pp) {
                    if (pp->gen != NULL) {
                        pp->gen->numChild--;
                    }
                    if (pp->appsrt != NULL) {
                        psRemoveParticleAppSRT(pp);
                    }
                    psDeletePntJObjwithParticle(pp);
                    _psListDelete(cur, prev);
                    if (pp->gen != NULL && pp->gen->userfunc != NULL &&
                        pp->gen->userfunc->hookDelete != NULL)
                    {
                        pp->gen->userfunc->hookDelete(pp);
                    }
                    break;
                }
                prev = cur;
            }
            pp = next;
        }
    }
}

void kar_particle__near_8042b5a8(s32 no, HSD_JObj* jobj)
{
    HSD_JObj* old;

    if (no < 0 || no > 0x100) {
        return;
    }

    if (no != 0) {
        old = (HSD_JObj*) lbl_8058C808[no - 1];
        if (old == jobj) {
            return;
        }
        if (old != NULL) {
            HSD_JObjUnref(old);
        }
        lbl_8058C808[no - 1] = jobj;
        particle_ref_INC_a(jobj);
    } else {
        s32 i;
        for (i = 0; i < 0x100; i++) {
            if ((HSD_JObj*) lbl_8058C808[i] == jobj) {
                HSD_JObjUnref((HSD_JObj*) lbl_8058C808[i]);
                lbl_8058C808[i] = NULL;
            }
        }
    }
}

void kar_particle__near_8042b6a0(HSD_JObj* jobj, s32 no)
{
    s32 i;
    HSD_JObj* old;

    if (no < 0 || no > 0x100) {
        return;
    }

    for (i = 0; i < 0x100; i++) {
        if ((HSD_JObj*) lbl_8058C808[i] == jobj) {
            HSD_JObjUnref((HSD_JObj*) lbl_8058C808[i]);
            lbl_8058C808[i] = NULL;
        }
    }

    if (no != 0) {
        old = (HSD_JObj*) lbl_8058C808[no - 1];
        if (old != NULL) {
            HSD_JObjUnref(old);
        }
        lbl_8058C808[no - 1] = jobj;
        particle_ref_INC_a(jobj);
    }
}

void kar_particle__near_8042b77c(void)
{
    s32 i;
    for (i = 0; i < 0x100; i++) {
        if (lbl_8058C808[i] != NULL) {
            HSD_JObjUnref((HSD_JObj*) lbl_8058C808[i]);
            lbl_8058C808[i] = NULL;
        }
    }
}

void psDeletePntJObjwithParticle(HSD_Particle* pp)
{
    HSD_JObj* jobj;
    u32 idx;

    if (pp->kind & 0x8000) {
        idx = (pp->kind >> 10) & 0x1c;
        jobj = *(HSD_JObj**) ((u8*) lbl_8058C808 + idx);
        if (jobj != NULL) {
            HSD_JObjUnref(jobj);
            *(HSD_JObj**) ((u8*) lbl_8058C808 + idx) = NULL;
        }
    }
}

void kar_particle__near_8042b840(u16 idnum, s32 linkNo)
{
    HSD_Particle* pp;
    HSD_Particle* next;

    pp = _psListGetFirst(linkNo);
    while (pp != NULL) {
        next = pp->next;
        if (pp->idnum == idnum) {
            if (pp->gen != NULL) {
                pp->gen->numChild--;
            }
            if (pp->appsrt != NULL) {
                psRemoveParticleAppSRT(pp);
            }
            psDeletePntJObjwithParticle(pp);
            _psListDelete(pp, NULL);
            if (pp->gen != NULL && pp->gen->userfunc != NULL &&
                pp->gen->userfunc->hookDelete != NULL)
            {
                pp->gen->userfunc->hookDelete(pp);
            }
        }
        pp = next;
    }
    kar_psinterpret__near_80430394((s16) linkNo);
}

void psKillGeneratorChild(HSD_Generator* gp)
{
    HSD_Particle* pp;
    HSD_Particle* next;
    u16 idnum = gp->idnum;
    u8 linkNo = gp->linkNo;

    pp = _psListGetFirst(linkNo);
    while (pp != NULL) {
        next = pp->next;
        if (pp->idnum == idnum && pp->gen != NULL && pp->gen == gp) {
            pp->gen->numChild--;
            if (pp->appsrt != NULL) {
                psRemoveParticleAppSRT(pp);
            }
            psDeletePntJObjwithParticle(pp);
            _psListDelete(pp, NULL);
            if (pp->gen->userfunc != NULL &&
                pp->gen->userfunc->hookDelete != NULL)
            {
                pp->gen->userfunc->hookDelete(pp);
            }
        }
        pp = next;
    }
}

void kar_particle__near_8042ba60(HSD_Generator* gp, HSD_PSUserFunc* userfunc)
{
    gp->userfunc = userfunc;
}

void kar_particle__near_8042ba68(HSD_Generator* gen)
{
    HSD_JObj* jobj;

    if (gen == NULL) {
        return;
    }
    if (gen->kind & 0x800) {
        return;
    }
    if (!(gen->type & 0x100)) {
        return;
    }

    jobj = gen->jobj;
    if (jobj == NULL) {
        return;
    }

    particle_JObjSetupMatrix(jobj);

    if (gen->type & 0x200) {
        gen->pos.x = jobj->mtx[0][3];
        gen->pos.y = jobj->mtx[1][3];
        gen->pos.z = jobj->mtx[2][3];
    }

    if ((gen->type & 0x800) && gen->appsrt != NULL && gen->appsrt->gp == gen) {
        gen->appsrt->translate.x = jobj->mtx[0][3];
        gen->appsrt->translate.y = jobj->mtx[1][3];
        gen->appsrt->translate.z = jobj->mtx[2][3];
    }

    if ((gen->type & 0x1000) && gen->appsrt != NULL && gen->appsrt->gp == gen)
    {
        HSD_MtxGetScale(jobj->mtx, &gen->appsrt->scale);
    }

    if (gen->type & 0x2000) {
        HSD_MtxGetRotation(jobj->mtx, (Vec*) &gen->appsrt->rot);
    }
}

u32* kar_particle__near_8042bbd8(u32* pc, u32* out)
{
    extern u32 lbl_805DE368;
    lbl_805DE368 = *pc;
    *out = lbl_805DE368;
    return pc + 1;
}

u8* kar_particle__near_8042bc10(u8* pc, u16* out)
{
    *out = *pc;
    if (!(*out & 0x80)) {
        return pc + 1;
    }
    *out = (u16) ((*out & 0x7F) * 0x100 + pc[1]);
    return pc + 2;
}

void kar_particle__near_8042bc40(f32 angle, f32 vx, f32 vy, f32 vz,
                                  HSD_Generator* gen)
{
    HSD_JObj* jobj = gen->jobj;
    f32 dx, dy, dz;
    f32 azimuth1, azimuth2;
    f32 sin1, cos1, sin2, cos2;
    f32 speed;
    f32 randAngle;
    f32 sinR, cosR;
    f32 sinAngle, cosAngle;

    dz = jobj->mtx[2][3] + vz;
    dx = jobj->mtx[0][3] + vx;
    dy = jobj->mtx[1][3] + vy;

    if (__fabsf(dz) >= 1.1754944e-38F) {
        azimuth1 = (f32) atan2(dy, dz);
    } else if (dy < 0.0F) {
        azimuth1 = -1.5707964F;
    } else {
        azimuth1 = 1.5707964F;
    }

    sin1 = kar_particle__near_8042c338(azimuth1);
    cos1 = kar_particle__near_8042bedc(azimuth1);

    dy = dy * sin1 + dz * cos1;

    if (__fabsf(dy) >= 1.1754944e-38F) {
        azimuth2 = (f32) atan2(dx, dy);
    } else if (dx < 0.0F) {
        azimuth2 = -1.5707964F;
    } else {
        azimuth2 = 1.5707964F;
    }

    sin2 = kar_particle__near_8042c338(azimuth2);
    cos2 = kar_particle__near_8042bedc(azimuth2);

    speed = gen->vel.z * gen->vel.z + gen->vel.x * gen->vel.x +
            gen->vel.y * gen->vel.y;
    if (speed > 0.0F) {
        speed = sqrtf(speed);
    }

    randAngle = (f32) (3.141592653589793 * HSD_Randf() * 2.0);
    sinAngle = speed * kar_particle__near_8042c338(angle);
    sinR = sinAngle * kar_particle__near_8042bedc(randAngle);
    cosR = sinAngle * kar_particle__near_8042c338(randAngle);
    cosAngle = speed * kar_particle__near_8042bedc(angle);

    gen->vel.x = sinR * cos2 + cosAngle * sin2;
    gen->vel.y =
        cos2 * (cosAngle * sin1) + (sin2 * (-sinR * sin1) + cosR * cos1);
    gen->vel.z =
        cos2 * (cosAngle * cos1) + (sin2 * (-sinR * cos1) - cosR * sin1);
}

static inline f32 particle_trig_poly(f32 z)
{
    f32 z2 = z * z;
    if (z <= 0.7853981633974483F) {
        return z *
               (1.0F -
                z2 * (0.16666669F - z2 * (0.008332824F - z2 * 0.00019587841F)));
    } else {
        f32 w = (f32) (1.5707963267948966 - (f64) z);
        f32 w2 = w * w;
        return 0.9999998F -
               w2 * (0.49999395F - w2 * (0.04163633F - w2 * 0.0013400711F));
    }
}

f32 kar_particle__near_8042bedc(f32 x)
{
    f32 y;
    f32 z;
    BOOL neg = FALSE;

    if (x == 0.0F) {
        return 1.0F;
    }

    y = (f32) ((f64) x + 1.5707963267948966);
    if (y < 0.0F) {
        y = -y;
        neg = TRUE;
    }

    while (y > 6.283185307179586) {
        y = (f32) (y - 6.283185307179586);
    }

    if (y <= 3.141592653589793) {
        z = y;
    } else {
        z = (f32) (y - 3.141592653589793);
        neg = !neg;
    }

    if (z > 1.5707963267948966) {
        z = (f32) (3.141592653589793 - (f64) z);
    }

    {
        f32 poly = particle_trig_poly(z);
        return neg ? -poly : poly;
    }
}

f32 kar_particle__near_8042c338(f32 x)
{
    f32 y = x;
    f32 z;
    BOOL neg = FALSE;

    if (x == 0.0F) {
        return 0.0F;
    }

    if (y < 0.0F) {
        y = -y;
        neg = TRUE;
    }

    while (y > 6.283185307179586) {
        y = (f32) (y - 6.283185307179586);
    }

    if (y <= 3.141592653589793) {
        z = y;
    } else {
        z = (f32) (y - 3.141592653589793);
        neg = !neg;
    }

    if (z > 1.5707963267948966) {
        z = (f32) (3.141592653589793 - (f64) z);
    }

    {
        f32 poly = particle_trig_poly(z);
        return neg ? -poly : poly;
    }
}

void kar_particle__near_8042c784(f32 angle, HSD_Particle* pp)
{
    f32 vx, vy, vz;
    f32 azimuth1, azimuth2;
    f32 sin1, cos1, sin2, cos2;
    f32 speed;
    f32 randAngle;
    f32 sinR, cosR;
    f32 sinAngle, cosAngle;

    vz = pp->vel.z;
    vx = pp->vel.x;
    vy = pp->vel.y;

    if (__fabsf(vz) >= 1.1754944e-38F) {
        azimuth1 = (f32) atan2(vy, vz);
    } else if (vy < 0.0F) {
        azimuth1 = -1.5707964F;
    } else {
        azimuth1 = 1.5707964F;
    }

    sin1 = kar_particle__near_8042c338(azimuth1);
    cos1 = kar_particle__near_8042bedc(azimuth1);

    vy = vy * sin1 + vz * cos1;

    if (__fabsf(vy) >= 1.1754944e-38F) {
        azimuth2 = (f32) atan2(vx, vy);
    } else if (vx < 0.0F) {
        azimuth2 = -1.5707964F;
    } else {
        azimuth2 = 1.5707964F;
    }

    sin2 = kar_particle__near_8042c338(azimuth2);
    cos2 = kar_particle__near_8042bedc(azimuth2);

    speed = pp->vel.z * pp->vel.z + pp->vel.x * pp->vel.x +
            pp->vel.y * pp->vel.y;
    if (speed > 0.0F) {
        speed = sqrtf(speed);
    }

    randAngle = (f32) (3.141592653589793 * HSD_Randf() * 2.0);
    sinAngle = speed * kar_particle__near_8042c338(angle);
    sinR = sinAngle * kar_particle__near_8042bedc(randAngle);
    cosR = sinAngle * kar_particle__near_8042c338(randAngle);
    cosAngle = speed * kar_particle__near_8042bedc(angle);

    pp->vel.x = sinR * cos2 + cosAngle * sin2;
    pp->vel.y =
        cos2 * (cosAngle * sin1) + (sin2 * (-sinR * sin1) + cosR * cos1);
    pp->vel.z =
        cos2 * (cosAngle * cos1) + (sin2 * (-sinR * cos1) - cosR * sin1);
}

void kar_particle__near_8042c9fc(HSD_JObj* jobj, HSD_Particle* pp)
{
    f32 dx, dy, dz;
    f32 distSq;

    if (jobj == NULL) {
        return;
    }

    particle_JObjSetupMatrix(jobj);

    dx = jobj->mtx[0][3] - pp->pos.x;
    dy = jobj->mtx[1][3] - pp->pos.y;
    dz = jobj->mtx[2][3] - pp->pos.z;

    distSq = dz * dz + dx * dx + dy * dy;
    if (distSq != 0.0F) {
        f32 speedSq = pp->vel.z * pp->vel.z + pp->vel.x * pp->vel.x +
                      pp->vel.y * pp->vel.y;
        f32 speed = speedSq;
        if (speedSq > 0.0F) {
            speed = sqrtf(speedSq);
        }
        {
            f32 scale = speed / distSq;
            pp->vel.x = dx * scale;
            pp->vel.y = dy * scale;
            pp->vel.z = dz * scale;
        }
    }
}

s32 kar_particle__near_8042cba4(f32 force, f32 range, HSD_JObj* jobj,
                                 HSD_Particle* pp)
{
    f32 dx, dy, dz;
    f32 distSq;

    if (jobj == NULL || range < 0.0F) {
        return 0;
    }

    particle_JObjSetupMatrix(jobj);

    dx = jobj->mtx[0][3] - pp->pos.x;
    dy = jobj->mtx[1][3] - pp->pos.y;
    dz = jobj->mtx[2][3] - pp->pos.z;

    distSq = dz * dz + dx * dx + dy * dy;
    if (distSq < range * range) {
        return 1;
    }
    if (distSq == 0.0F) {
        return 0;
    }
    {
        f32 scale = force / distSq;
        pp->vel.x += scale * dx;
        pp->vel.y += scale * dy;
        pp->vel.z += scale * dz;
    }
    return 0;
}

/* -------------------------------------------------------------------- */
/* psInterpretParticle0 - per-particle bytecode interpreter/tick.       */
/* -------------------------------------------------------------------- */

void psInterpretParticle0(HSD_Particle* pp, int prevIsSet)
{
    HSD_Particle* prev = prevIsSet ? pp : NULL;
    u8* pc;
    u32 operand;
    u8 opcode;
    u8 cls;
    HSD_Particle* child;
    HSD_PSCmdList* cl;
    HSD_PSTexGroup* tg;

    if (pp->kind & 0x800) {
        return;
    }

    if (pp->sizeCount != 0) {
        pp->size += (pp->sizeTarget - pp->size) / (f32) pp->sizeCount;
        pp->sizeCount--;
    }

    if (pp->primColCount != 0) {
        pp->primColRemain--;
        if (pp->primColRemain == 0) {
            pp->primColCount = 0;
            pp->primCol = pp->primColTarget;
        }
    }

    if (pp->envColCount != 0) {
        pp->envColRemain--;
        if (pp->envColRemain == 0) {
            pp->envColCount = 0;
            pp->envCol = pp->envColTarget;
        }
    }

    if (pp->matColCount != 0) {
        pp->matColRemain--;
        if (pp->matColRemain == 0) {
            pp->matColCount = 0;
            pp->matRGB = pp->matRGBTarget;
            pp->matA = pp->matATarget;
        }
    }

    if (pp->ambColCount != 0) {
        pp->ambColRemain--;
        if (pp->ambColRemain == 0) {
            pp->ambColCount = 0;
            pp->ambRGB = pp->ambRGBTarget;
            pp->ambA = pp->ambATarget;
        }
    }

    if (pp->aCmpCount != 0) {
        pp->aCmpRemain--;
        if (pp->aCmpRemain == 0) {
            pp->aCmpCount = 0;
            pp->aCmpParam1 = pp->aCmpParam1Target;
            pp->aCmpParam2 = pp->aCmpParam2Target;
        }
    }

    if (pp->rotateCount != 0) {
        pp->rotate += (pp->rotateTarget - pp->rotate) / (f32) pp->rotateCount;
        pp->rotateCount--;
    }

    if (pp->cmdWait == 0) {
        goto do_life;
    }
    if (--pp->cmdWait != 0) {
        goto do_life;
    }

    operand = 0;
    pc = pp->cmdList + pp->cmdPtr;

    for (;;) {
        opcode = *pc++;

        if (opcode < 0x80) {
            operand = opcode & 0x1F;
            if (opcode & 0x20) {
                operand = (operand << 8) + *pc++;
            }
            switch (opcode & 0xC0) {
            case 0x00:
                break;
            case 0x40: {
                u8 pn = *pc++;
                pp->poseNum = pn;
                {
                    HSD_PSTexGroup** tga;
                    HSD_PSTexGroup* texGrp;
                    u8 bank = pp->bank;
                    u8 tgIdx = pp->texGroup;

                    tga = (HSD_PSTexGroup**) BANK_TEXARRAY(bank);
                    texGrp = tga[tgIdx];
                    if (texGrp != NULL && texGrp->texTable != NULL) {
                        if (texGrp->texTable[pp->poseNum] != NULL) {
                            pp->kind |= 0x400;
                        }
                    }
                }
                break;
            }
            }
        } else {
            operand = 0;
            cls = opcode & 0xF8;
            if (cls > 0x98) {
                cls = opcode & 0xF0;
                if (cls != 0xC0 && cls != 0xD0) {
                    cls = opcode;
                }
            }

            switch (cls) {
            case 0x80: {
                u32 v;
                if (opcode & 1) {
                    pc = (u8*) kar_particle__near_8042bbd8((u32*) pc, &v);
                    pp->pos.x = *(f32*) &v;
                }
                if (opcode & 2) {
                    pc = (u8*) kar_particle__near_8042bbd8((u32*) pc, &v);
                    pp->pos.y = *(f32*) &v;
                }
                if (opcode & 4) {
                    pc = (u8*) kar_particle__near_8042bbd8((u32*) pc, &v);
                    pp->pos.z = *(f32*) &v;
                }
                break;
            }

            case 0x88: {
                u32 v;
                if (opcode & 1) {
                    pc = (u8*) kar_particle__near_8042bbd8((u32*) pc, &v);
                    pp->pos.x += *(f32*) &v;
                }
                if (opcode & 2) {
                    pc = (u8*) kar_particle__near_8042bbd8((u32*) pc, &v);
                    pp->pos.y += *(f32*) &v;
                }
                if (opcode & 4) {
                    pc = (u8*) kar_particle__near_8042bbd8((u32*) pc, &v);
                    pp->pos.z += *(f32*) &v;
                }
                break;
            }

            case 0x90: {
                u32 v;
                if (opcode & 1) {
                    pc = (u8*) kar_particle__near_8042bbd8((u32*) pc, &v);
                    pp->vel.x = *(f32*) &v;
                }
                if (opcode & 2) {
                    pc = (u8*) kar_particle__near_8042bbd8((u32*) pc, &v);
                    pp->vel.y = *(f32*) &v;
                }
                if (opcode & 4) {
                    pc = (u8*) kar_particle__near_8042bbd8((u32*) pc, &v);
                    pp->vel.z = *(f32*) &v;
                }
                break;
            }

            case 0x98: {
                u32 v;
                if (opcode & 1) {
                    pc = (u8*) kar_particle__near_8042bbd8((u32*) pc, &v);
                    pp->vel.x += *(f32*) &v;
                }
                if (opcode & 2) {
                    pc = (u8*) kar_particle__near_8042bbd8((u32*) pc, &v);
                    pp->vel.y += *(f32*) &v;
                }
                if (opcode & 4) {
                    pc = (u8*) kar_particle__near_8042bbd8((u32*) pc, &v);
                    pp->vel.z += *(f32*) &v;
                }
                break;
            }

            case 0xA0: {
                u32 v;
                pc = kar_particle__near_8042bc10(pc, &pp->sizeCount);
                pc = (u8*) kar_particle__near_8042bbd8((u32*) pc, &v);
                pp->sizeTarget = *(f32*) &v;
                if (pp->sizeCount == 0) {
                    pp->size = pp->sizeTarget;
                }
                break;
            }

            case 0xA1:
                pp->kind &= ~0x400;
                break;

            case 0xA2: {
                u32 v;
                pc = (u8*) kar_particle__near_8042bbd8((u32*) pc, &v);
                pp->grav = *(f32*) &v;
                if (pp->grav == 0.0F) {
                    pp->kind &= ~1;
                } else {
                    pp->kind |= 1;
                }
                break;
            }

            case 0xA3: {
                u32 v;
                pc = (u8*) kar_particle__near_8042bbd8((u32*) pc, &v);
                pp->fric = *(f32*) &v;
                if (pp->fric == 1.0F) {
                    pp->kind &= ~2;
                } else {
                    pp->kind |= 2;
                }
                break;
            }

            case 0xA4: {
                s32 linkNo = pp->linkNo;
                s32 bank = pp->bank;
                s32 idx;
                s32 palflag;

                idx = (pc[0] << 8) + pc[1];
                pc += 2;

                if (linkNo >= 8 || bank >= 65 ||
                    idx >= (s32) BANK_CMDCOUNT(bank))
                {
                    child = NULL;
                } else {
                    cl = ((HSD_PSCmdList**) BANK_CMDARRAY(bank))[idx];
                    if (cl == NULL) {
                        child = NULL;
                    } else {
                        tg = ((HSD_PSTexGroup**) BANK_TEXARRAY(bank))
                                 [cl->texGroup];
                        palflag = (tg != NULL) ? tg->palflag : 0;
                        child = psGenerateParticle0(
                            NULL, linkNo, bank, cl->kind, cl->texGroup,
                            cl->cmdList, cl->life, palflag, 0.0F, 0.0F, 0.0F,
                            cl->vx, cl->vy, cl->vz, cl->size, cl->grav,
                            cl->fric, NULL, 0);
                    }
                }
                if (child != NULL) {
                    child->idnum = pp->idnum;
                    child->gen = pp->gen;
                    if (pp->gen != NULL) {
                        pp->gen->numChild++;
                    }
                    kar_psdisp__near_80437ddc(child, pp->appsrt);
                    child->pos.x = pp->pos.x;
                    child->pos.y = pp->pos.y;
                    child->pos.z = pp->pos.z;
                    psInterpretParticle0(child, 1);
                }
                break;
            }

            case 0xA6: {
                s32 baseLife = (pc[0] << 8) + pc[1];
                s32 randomRange = (pc[2] << 8) + pc[3];
                pc += 4;
                pp->life = (u16) (baseLife +
                                   (s32) ((f32) randomRange * HSD_Randf()));
                break;
            }

            case 0xA7: {
                u8 threshold = *pc++;
                if (threshold >= (s32) (256.0F * HSD_Randf())) {
                    pp->life = 1;
                    goto exit_loop;
                }
                break;
            }

            case 0xA8: {
                u32 v;
                f32 f;
                pc = (u8*) kar_particle__near_8042bbd8((u32*) pc, &v);
                f = *(f32*) &v;
                pp->pos.x += 2.0F * f * HSD_Randf() - f;
                pc = (u8*) kar_particle__near_8042bbd8((u32*) pc, &v);
                f = *(f32*) &v;
                pp->pos.y += 2.0F * f * HSD_Randf() - f;
                pc = (u8*) kar_particle__near_8042bbd8((u32*) pc, &v);
                f = *(f32*) &v;
                pp->pos.z += 2.0F * f * HSD_Randf() - f;
                break;
            }

            case 0xA9: {
                u32 v;
                pc = (u8*) kar_particle__near_8042bbd8((u32*) pc, &v);
                kar_particle__near_8042c784(*(f32*) &v, pp);
                break;
            }

            case 0xAA: {
                s32 baseIdx = (pc[0] << 8) + pc[1];
                s32 randomRange = (pc[2] << 8) + pc[3];
                s32 idx;
                s32 linkNo, bank, palflag;
                pc += 4;

                idx = baseIdx + (s32) ((f32) randomRange * HSD_Randf());

                linkNo = pp->linkNo;
                bank = pp->bank;
                if (linkNo >= 8 || bank >= 65 ||
                    idx >= (s32) BANK_CMDCOUNT(bank))
                {
                    child = NULL;
                } else {
                    cl = ((HSD_PSCmdList**) BANK_CMDARRAY(bank))[idx];
                    if (cl == NULL) {
                        child = NULL;
                    } else {
                        tg = ((HSD_PSTexGroup**) BANK_TEXARRAY(bank))
                                 [cl->texGroup];
                        palflag = (tg != NULL) ? tg->palflag : 0;
                        child = psGenerateParticle0(
                            NULL, linkNo, bank, cl->kind, cl->texGroup,
                            cl->cmdList, cl->life, palflag, 0.0F, 0.0F, 0.0F,
                            cl->vx, cl->vy, cl->vz, cl->size, cl->grav,
                            cl->fric, NULL, 0);
                    }
                }
                if (child != NULL) {
                    child->pos.x = pp->pos.x;
                    child->pos.y = pp->pos.y;
                    child->pos.z = pp->pos.z;
                    child->idnum = pp->idnum;
                    child->gen = pp->gen;
                    if (pp->gen != NULL) {
                        pp->gen->numChild++;
                    }
                    if (pp->appsrt != NULL) {
                        kar_psdisp__near_80437ddc(child, pp->appsrt);
                    }
                    psInterpretParticle0(child, 1);
                }
                break;
            }

            case 0xAB: {
                u32 v;
                pc = (u8*) kar_particle__near_8042bbd8((u32*) pc, &v);
                pp->vel.x *= *(f32*) &v;
                pp->vel.y *= *(f32*) &v;
                pp->vel.z *= *(f32*) &v;
                break;
            }

            case 0xAC: {
                u32 v;
                f32 range;
                pc = kar_particle__near_8042bc10(pc, &pp->sizeCount);
                pc = (u8*) kar_particle__near_8042bbd8((u32*) pc, &v);
                pp->sizeTarget = *(f32*) &v;
                pc = (u8*) kar_particle__near_8042bbd8((u32*) pc, &v);
                range = *(f32*) &v;
                pp->sizeTarget += range * HSD_Randf();
                if (pp->sizeCount == 0) {
                    pp->size = pp->sizeTarget;
                }
                break;
            }

            case 0xAD:
                pp->kind |= 0x80;
                break;

            case 0xAE:
                pp->kind &= ~(0x20 | 0x40);
                break;

            case 0xAF:
                pp->kind &= ~0x40;
                pp->kind |= 0x20;
                break;

            case 0xB0:
                pp->kind &= ~0x20;
                pp->kind |= 0x40;
                break;

            case 0xB1:
                pp->kind |= (0x20 | 0x40);
                break;

            case 0xB2: {
                HSD_psAppSRT* srt = pp->appsrt;
                if (srt == NULL) {
                    break;
                }
                if ((u8) srt->xA2 != 0) {
                    break;
                }
                kar_particle__near_8042ba68(srt->gp);
                srt = pp->appsrt;
                kar_particle__near_8043010c(srt->mmtx, &srt->scale,
                                             (Vec*) &srt->rot, &srt->translate,
                                             NULL);
                {
                    f32 x = pp->pos.x, y = pp->pos.y, z = pp->pos.z;
                    pp->pos.x = srt->mmtx[0][1] * y + srt->mmtx[0][0] * x +
                                srt->mmtx[0][2] * z + srt->mmtx[0][3];
                    pp->pos.y = srt->mmtx[1][1] * y + srt->mmtx[1][0] * x +
                                srt->mmtx[1][2] * z + srt->mmtx[1][3];
                    pp->pos.z = srt->mmtx[2][1] * y + srt->mmtx[2][0] * x +
                                srt->mmtx[2][2] * z + srt->mmtx[2][3];
                }
                psRemoveParticleAppSRT(pp);
                break;
            }

            case 0xB3: {
                s32 step;
                if (pp->aCmpCount != 0) {
                    step = ((s32) pp->aCmpRemain << 16) / (s32) pp->aCmpCount;
                    pp->aCmpParam1 =
                        (u8) ((((s32) pp->aCmpParam1Target << 16) +
                               step * ((s32) pp->aCmpParam1 -
                                       (s32) pp->aCmpParam1Target)) >>
                              16);
                    pp->aCmpParam2 =
                        (u8) ((((s32) pp->aCmpParam2Target << 16) +
                               step * ((s32) pp->aCmpParam2 -
                                       (s32) pp->aCmpParam2Target)) >>
                              16);
                }
                pc = kar_particle__near_8042bc10(pc, &pp->aCmpCount);
                pp->aCmpMode = *pc++;
                pp->aCmpParam1Target = *pc++;
                pp->aCmpParam2Target = *pc++;
                if (pp->aCmpCount == 0) {
                    pp->aCmpParam1 = pp->aCmpParam1Target;
                    pp->aCmpParam2 = pp->aCmpParam2Target;
                    pp->aCmpRemain = 0;
                } else {
                    pp->aCmpRemain = pp->aCmpCount;
                }
                break;
            }

            case 0xB4:
                pp->kind |= 0x200;
                break;

            case 0xB5:
                pp->kind &= ~0x200;
                break;

            case 0xB6: {
                u32 v;
                pc = kar_particle__near_8042bc10(pc, &pp->rotateCount);
                pc = (u8*) kar_particle__near_8042bbd8((u32*) pc, &v);
                pp->rotateTarget += *(f32*) &v;
                if (pp->rotateCount == 0) {
                    pp->rotate = pp->rotateTarget;
                }
                break;
            }

            case 0xB7: {
                s32 idx = *pc++;
                HSD_JObj* jobj;
                f32 vmagsq, vmag;
                f32 dx, dy, dz, distsq, dist;

                jobj = (HSD_JObj*) hsd_804D0908[idx + pp->pJObjOfs];
                if (jobj == NULL) {
                    break;
                }
                kar_particle__near_80430044(jobj);
                vmagsq = pp->vel.x * pp->vel.x + pp->vel.y * pp->vel.y +
                         pp->vel.z * pp->vel.z;
                dx = jobj->mtx[0][3] - pp->pos.x;
                dy = jobj->mtx[1][3] - pp->pos.y;
                dz = jobj->mtx[2][3] - pp->pos.z;
                vmag = sqrtf(vmagsq);
                distsq = dy * dy + dx * dx + dz * dz;
                if (distsq == 0.0F) {
                    break;
                }
                dist = sqrtf(distsq);
                {
                    f32 scale = vmag / dist;
                    pp->vel.x = dx * scale;
                    pp->vel.y = dy * scale;
                    pp->vel.z = dz * scale;
                }
                break;
            }

            case 0xB8: {
                s32 idx = *pc++;
                u32 v;
                f32 force, range;
                HSD_JObj* jobj;
                pc = (u8*) kar_particle__near_8042bbd8((u32*) pc, &v);
                force = *(f32*) &v;
                pc = (u8*) kar_particle__near_8042bbd8((u32*) pc, &v);
                range = *(f32*) &v;
                jobj = (HSD_JObj*) hsd_804D0908[idx + pp->pJObjOfs];
                if (kar_particle__near_8042cba4(force, range, jobj, pp) != 0) {
                    pp->life = 1;
                    goto exit_loop;
                }
                break;
            }

            case 0xB9: {
                s32 linkNo = pp->linkNo;
                s32 bank = pp->bank;
                s32 idx;
                s32 palflag;

                idx = (pc[0] << 8) + pc[1];
                pc += 2;

                if (linkNo >= 8 || bank >= 65 ||
                    idx >= (s32) BANK_CMDCOUNT(bank))
                {
                    child = NULL;
                } else {
                    cl = ((HSD_PSCmdList**) BANK_CMDARRAY(bank))[idx];
                    if (cl == NULL) {
                        child = NULL;
                    } else {
                        tg = ((HSD_PSTexGroup**) BANK_TEXARRAY(bank))
                                 [cl->texGroup];
                        palflag = (tg != NULL) ? tg->palflag : 0;
                        child = psGenerateParticle0(
                            NULL, linkNo, bank, cl->kind, cl->texGroup,
                            cl->cmdList, cl->life, palflag, 0.0F, 0.0F, 0.0F,
                            cl->vx, cl->vy, cl->vz, cl->size, cl->grav,
                            cl->fric, NULL, 0);
                    }
                }
                if (child != NULL) {
                    child->pos.x = pp->pos.x;
                    child->pos.y = pp->pos.y;
                    child->pos.z = pp->pos.z;
                    child->vel.x = pp->vel.x;
                    child->vel.y = pp->vel.y;
                    child->vel.z = pp->vel.z;
                    child->idnum = pp->idnum;
                    child->gen = pp->gen;
                    if (pp->gen != NULL) {
                        pp->gen->numChild++;
                    }
                    if (pp->appsrt != NULL) {
                        kar_psdisp__near_80437ddc(child, pp->appsrt);
                    }
                    psInterpretParticle0(child, 1);
                }
                break;
            }

            case 0xBA:
            case 0xBB: {
                GXColor* target =
                    (cls == 0xBA) ? &pp->primColTarget : &pp->envColTarget;
                u16* count =
                    (cls == 0xBA) ? &pp->primColCount : &pp->envColCount;
                u16* remain =
                    (cls == 0xBA) ? &pp->primColRemain : &pp->envColRemain;
                GXColor* cur = (cls == 0xBA) ? &pp->primCol : &pp->envCol;
                s32 step;
                s8 delta;
                f32 randv;

                if (*count != 0) {
                    step = ((s32) *remain << 16) / (s32) *count;
                    cur->r =
                        (u8) ((((s32) target->r << 16) +
                               step * ((s32) cur->r - (s32) target->r)) >>
                              16);
                    cur->g =
                        (u8) ((((s32) target->g << 16) +
                               step * ((s32) cur->g - (s32) target->g)) >>
                              16);
                    cur->b =
                        (u8) ((((s32) target->b << 16) +
                               step * ((s32) cur->b - (s32) target->b)) >>
                              16);
                    cur->a =
                        (u8) ((((s32) target->a << 16) +
                               step * ((s32) cur->a - (s32) target->a)) >>
                              16);
                }

                randv = HSD_Randf();
                delta = (s8) *pc++;
                target->r = (u8) kar_particle__near_804300b4(
                    randv * (f32) (delta * 2), target->r);
                randv = HSD_Randf();
                delta = (s8) *pc++;
                target->g = (u8) kar_particle__near_804300b4(
                    randv * (f32) (delta * 2), target->g);
                randv = HSD_Randf();
                delta = (s8) *pc++;
                target->b = (u8) kar_particle__near_804300b4(
                    randv * (f32) (delta * 2), target->b);
                randv = HSD_Randf();
                delta = (s8) *pc++;
                target->a = (u8) kar_particle__near_804300b4(
                    randv * (f32) (delta * 2), target->a);

                if (*count == 0) {
                    *cur = *target;
                } else {
                    *remain = *count;
                }
                break;
            }

            case 0xBC: {
                s32 randRange;
                pp->poseNum = *pc++;
                randRange = *pc++;
                pp->poseNum = (u8) (s32) ((f32) randRange * HSD_Randf() +
                                           (f32) pp->poseNum);
                {
                    u8 bank = pp->bank;
                    u8 tgIdx = pp->texGroup;
                    HSD_PSTexGroup** tga =
                        (HSD_PSTexGroup**) BANK_TEXARRAY(bank);
                    HSD_PSTexGroup* texGrp = tga[tgIdx];
                    if (texGrp != NULL && texGrp->texTable != NULL) {
                        if (texGrp->texTable[pp->poseNum] != NULL) {
                            pp->kind |= 0x400;
                        }
                    }
                }
                break;
            }

            case 0xBD: {
                u32 v;
                f32 baseSpeed, randomRange, targetSpeed, mag;
                pc = (u8*) kar_particle__near_8042bbd8((u32*) pc, &v);
                baseSpeed = *(f32*) &v;
                pc = (u8*) kar_particle__near_8042bbd8((u32*) pc, &v);
                randomRange = *(f32*) &v;
                targetSpeed = baseSpeed + randomRange * HSD_Randf();
                mag = pp->vel.x * pp->vel.x + pp->vel.y * pp->vel.y +
                      pp->vel.z * pp->vel.z;
                mag = sqrtf(mag);
                if (mag > 0.0F) {
                    targetSpeed /= mag;
                    pp->vel.x *= targetSpeed;
                    pp->vel.y *= targetSpeed;
                    pp->vel.z *= targetSpeed;
                }
                break;
            }

            case 0xBE: {
                u32 v;
                pc = (u8*) kar_particle__near_8042bbd8((u32*) pc, &v);
                pp->vel.x *= *(f32*) &v;
                pc = (u8*) kar_particle__near_8042bbd8((u32*) pc, &v);
                pp->vel.y *= *(f32*) &v;
                pc = (u8*) kar_particle__near_8042bbd8((u32*) pc, &v);
                pp->vel.z *= *(f32*) &v;
                break;
            }

            case 0xBF: {
                u8 idx = *pc++;
                pp->kind |= (((idx + pp->pJObjOfs) & 7) << 12) | 0x8000;
                break;
            }

            case 0xC0:
            case 0xD0: {
                GXColor* target =
                    (cls == 0xC0) ? &pp->primColTarget : &pp->envColTarget;
                u16* count =
                    (cls == 0xC0) ? &pp->primColCount : &pp->envColCount;
                u16* remain =
                    (cls == 0xC0) ? &pp->primColRemain : &pp->envColRemain;
                GXColor* cur = (cls == 0xC0) ? &pp->primCol : &pp->envCol;
                s32 step;

                if (*count != 0) {
                    step = ((s32) *remain << 16) / (s32) *count;
                    cur->r =
                        (u8) ((((s32) target->r << 16) +
                               step * ((s32) cur->r - (s32) target->r)) >>
                              16);
                    cur->g =
                        (u8) ((((s32) target->g << 16) +
                               step * ((s32) cur->g - (s32) target->g)) >>
                              16);
                    cur->b =
                        (u8) ((((s32) target->b << 16) +
                               step * ((s32) cur->b - (s32) target->b)) >>
                              16);
                    cur->a =
                        (u8) ((((s32) target->a << 16) +
                               step * ((s32) cur->a - (s32) target->a)) >>
                              16);
                }
                pc = kar_particle__near_8042bc10(pc, count);
                *target = *cur;
                if (opcode & 1) {
                    target->r = *pc++;
                }
                if (opcode & 2) {
                    target->g = *pc++;
                }
                if (opcode & 4) {
                    target->b = *pc++;
                }
                if (opcode & 8) {
                    target->a = *pc++;
                }
                if (*count == 0) {
                    *cur = *target;
                    *remain = 0;
                } else {
                    *remain = *count;
                }
                break;
            }

            case 0xE1: {
                s32 idx = *pc++;
                if (idx == 0) {
                    pp->callback = NULL;
                } else {
                    pp->callback = psCallback[idx - 1];
                }
                break;
            }

            case 0xEC: {
                s32 idx = *pc++;
                u32 v;
                pc = (u8*) kar_particle__near_8042bbd8((u32*) pc, &v);
                if (pp->gen != NULL && pp->gen->userfunc != NULL &&
                    pp->gen->userfunc->setUserData != NULL)
                {
                    pp->gen->userfunc->setUserData(pp, (u8) idx, *(f32*) &v);
                } else if (pp->userdata != NULL) {
                    pp->userdata[idx] = *(f32*) &v;
                }
                break;
            }

            case 0xE2:
                pp->kind |= 8;
                break;

            case 0xE3:
                pp->palNum = *pc++;
                break;

            case 0xE4: {
                u8 mode = *pc++ & 3;
                switch (mode) {
                case 0:
                    pp->kind &= ~0x40000;
                    break;
                case 1:
                    pp->kind |= 0x40000;
                    break;
                case 2:
                    pp->kind ^= 0x40000;
                    break;
                case 3:
                    if (HSD_Randf() < 0.5F) {
                        pp->kind &= ~0x40000;
                    } else {
                        pp->kind |= 0x40000;
                    }
                    break;
                }
                break;
            }

            case 0xE5: {
                u8 mode = *pc++ & 3;
                switch (mode) {
                case 0:
                    pp->kind &= ~0x80000;
                    break;
                case 1:
                    pp->kind |= 0x80000;
                    break;
                case 2:
                    pp->kind ^= 0x80000;
                    break;
                case 3:
                    if (HSD_Randf() < 0.5F) {
                        pp->kind &= ~0x80000;
                    } else {
                        pp->kind |= 0x80000;
                    }
                    break;
                }
                break;
            }

            case 0xE6:
                pp->kind |= 0x200000;
                break;

            case 0xE7:
                pp->kind &= ~0x200000;
                break;

            case 0xE8: {
                u32 v;
                pc = (u8*) kar_particle__near_8042bbd8((u32*) pc, &v);
                if (*(f32*) &v < 0.0F) {
                    pp->kind &= ~0x100000;
                } else {
                    pp->kind |= 0x100000;
                    pp->trail = *(f32*) &v;
                }
                break;
            }

            case 0xEA:
            case 0xEB: {
                u8* rgb = (cls == 0xEA) ? &pp->matRGB : &pp->ambRGB;
                u8* a = (cls == 0xEA) ? &pp->matA : &pp->ambA;
                u8* rgbTarget =
                    (cls == 0xEA) ? &pp->matRGBTarget : &pp->ambRGBTarget;
                u8* aTarget =
                    (cls == 0xEA) ? &pp->matATarget : &pp->ambATarget;
                u16* count =
                    (cls == 0xEA) ? &pp->matColCount : &pp->ambColCount;
                u16* remain =
                    (cls == 0xEA) ? &pp->matColRemain : &pp->ambColRemain;
                s32 step;
                u8 flags;

                if (*count != 0) {
                    step = ((s32) *remain << 16) / (s32) *count;
                    *rgb = (u8) ((((s32) *rgbTarget << 16) +
                                  step * ((s32) *rgb - (s32) *rgbTarget)) >>
                                 16);
                    *a = (u8) ((((s32) *aTarget << 16) +
                                step * ((s32) *a - (s32) *aTarget)) >>
                               16);
                }
                pc = kar_particle__near_8042bc10(pc, count);
                flags = *pc++;
                *rgbTarget = *rgb;
                if (flags & 1) {
                    *rgbTarget = *pc++;
                }
                if (flags & 8) {
                    *aTarget = *pc++;
                }
                if (*count == 0) {
                    *rgb = *rgbTarget;
                    *remain = 0;
                } else {
                    *remain = *count;
                }
                break;
            }

            case 0xED: {
                u32 v;
                f32 baseVal, rangeVal, result;
                s32 timing;
                pc = (u8*) kar_particle__near_8042bbd8((u32*) pc, &v);
                baseVal = *(f32*) &v;
                pc = (u8*) kar_particle__near_8042bbd8((u32*) pc, &v);
                rangeVal = *(f32*) &v;
                timing = *pc++;

                if (timing != 0) {
                    s32 randi = (s32) ((f32) (timing + 1) * HSD_Randf());
                    result = baseVal + rangeVal * (f32) randi / (f32) timing;
                } else {
                    result = baseVal + rangeVal * HSD_Randf();
                }
                pp->rotateTarget += result;
                pp->rotate += result;
                break;
            }

            case 0xFA:
                pp->loopCount = *pc++;
                pp->cmdLoopPtr = (u16) (pc - pp->cmdList);
                break;

            case 0xFB:
                if (--pp->loopCount != 0) {
                    pc = pp->cmdList + pp->cmdLoopPtr;
                }
                break;

            case 0xFC:
                pp->cmdMarkPtr = (u16) (pc - pp->cmdList);
                break;

            case 0xFD:
                pc = pp->cmdList + pp->cmdMarkPtr;
                break;

            case 0xFE:
            case 0xFF:
                pp->life = 1;
                goto exit_loop;

            default:
                break;
            }
        }

        if (operand != 0) {
            break;
        }
    }

exit_loop:
    pp->cmdPtr = (u16) (pc - pp->cmdList);
    pp->cmdWait = (u16) operand;

do_life:
    if (--pp->life == 0) {
        if (pp->gen != NULL && pp->gen->userfunc != NULL &&
            pp->gen->userfunc->hookDelete != NULL)
        {
            pp->gen->userfunc->hookDelete(pp);
        }

        if (prev == NULL) {
            hsd_804D0908[pp->linkNo] = pp->next;
        } else {
            prev->next = pp->next;
        }

        if (pp->gen != NULL) {
            pp->gen->numChild--;
        }
        if (pp->appsrt != NULL) {
            psRemoveParticleAppSRT(pp);
        }

        hsd_8039D048(pp);
        HSD_ObjFree(&hsdParticle_alloc_data, pp);
        numActiveParticles--;
        return;
    }

    if (pp->kind & 4) {
        HSD_Generator* gp = pp->gen;
        f32 sinA, sinB, cosA, cosB;
        f32 R;
        f32 d, e, nd, vz;

        sinA = kar_particle__near_8042c338(pp->grav);
        sinB = kar_particle__near_8042c338(pp->fric);
        cosA = kar_particle__near_8042bedc(pp->grav);
        cosB = kar_particle__near_8042bedc(pp->fric);

        pp->vel.z += gp->aux.tornado.vel;

        R = __fabsf(gp->radius);
        R = pp->vel.z * tanf(__fabsf(gp->angle)) + R;

        pp->vel.x += gp->grav;
        R *= pp->vel.y;

        d = R * kar_particle__near_8042bedc(pp->vel.x);
        e = R * kar_particle__near_8042c338(pp->vel.x);
        nd = -d;
        vz = pp->vel.z;

        pp->pos.x = gp->pos.x + (d * cosB + vz * sinB);
        pp->pos.y =
            gp->pos.y + (cosB * (vz * sinA) + (sinB * (nd * sinA) + e * cosA));
        pp->pos.z =
            gp->pos.z + (cosB * (vz * cosA) + (sinB * (nd * cosA) - e * sinA));
    } else {
        if (pp->kind & 1) {
            pp->vel.y -= pp->grav;
        }
        if (pp->kind & 2) {
            pp->vel.x *= pp->fric;
            pp->vel.y *= pp->fric;
            pp->vel.z *= pp->fric;
        }
        pp->pos.x += pp->vel.x;
        pp->pos.y += pp->vel.y;
        pp->pos.z += pp->vel.z;
    }

    if (pp->kind & 0x8000) {
        s32 jobjIdx = (pp->kind >> 12) & 7;
        HSD_JObj* jobj;

        if (hsd_804D0908[jobjIdx] == NULL) {
            HSD_JObj* newJObj = HSD_JObjAlloc();
            if (newJObj != NULL) {
                kar_particle__near_8042b5a8(jobjIdx + 1, newJObj);
                HSD_JObjUnref(newJObj);
            }
        }

        jobj = (HSD_JObj*) hsd_804D0908[jobjIdx];
        if (jobj != NULL) {
            kar_particle__near_80430044(jobj);
            jobj = (HSD_JObj*) hsd_804D0908[jobjIdx];
            kar_particle__near_8042ff94(jobj, pp->pos.x - jobj->mtx[0][3]);
            jobj = (HSD_JObj*) hsd_804D0908[jobjIdx];
            kar_particle__near_8042fee4(jobj, pp->pos.y - jobj->mtx[1][3]);
            jobj = (HSD_JObj*) hsd_804D0908[jobjIdx];
            kar_particle__near_8042fe34(jobj, pp->pos.z - jobj->mtx[2][3]);
        }
    }

    if (pp->callback != NULL) {
        if (pp->callback(pp) == -1) {
            goto do_life;
        }
    }
}

void kar_particle__near_8042fe34(HSD_JObj* jobj, f32 delta)
{
    assert_line_jobjh(0x46b, jobj);
    jobj->translate.z += delta;
    if (!(jobj->flags & JOBJ_FLAG_NO_AUTODIRTY)) {
        particle_JObjSetMtxDirty(jobj);
    }
}

void kar_particle__near_8042fee4(HSD_JObj* jobj, f32 delta)
{
    assert_line_jobjh(0x460, jobj);
    jobj->translate.y += delta;
    if (!(jobj->flags & JOBJ_FLAG_NO_AUTODIRTY)) {
        particle_JObjSetMtxDirty(jobj);
    }
}

void kar_particle__near_8042ff94(HSD_JObj* jobj, f32 delta)
{
    assert_line_jobjh(0x455, jobj);
    jobj->translate.x += delta;
    if (!(jobj->flags & JOBJ_FLAG_NO_AUTODIRTY)) {
        particle_JObjSetMtxDirty(jobj);
    }
}

void kar_particle__near_80430044(HSD_JObj* jobj)
{
    particle_JObjSetupMatrix(jobj);
}

s32 kar_particle__near_804300b4(f32 delta, u8 old)
{
    f32 v = (f32) old + delta;
    if (v < 0.0F) {
        v = 0.0F;
    }
    if (v > 255.0F) {
        v = 255.0F;
    }
    return (s32) v;
}

void kar_particle__near_8043010c(Mtx mtx, Vec* scale, Vec* rotate,
                                  Vec* translate, Vec* arg4)
{
    HSD_MtxSRT(mtx, scale, rotate, translate, arg4);
}

void kar_particle__near_8043012c(HSD_Generator* gen, HSD_JObj* jobj)
{
    if (gen != NULL) {
        gen->jobj = jobj;
        if (jobj != NULL) {
            particle_ref_INC_b(jobj);
        }
    }
}

HSD_JObj* kar_particle__near_80430190(HSD_JObj** slot)
{
    return *slot;
}
