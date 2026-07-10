#include <global.h>
#include <sysdolphin/psdisp.h>
#include <sysdolphin/memory.h>

void memset(void*, int, int);

static u16 lbl_805DE35C;
static u16 lbl_805DE360;
static u16 lbl_805DE362;
static u16 lbl_805DE366;
static u16 lbl_805DE3E0;
static HSD_psAppSRT* lbl_805DE3E4;

static struct {
    void* head;
    u32 pad4;
} lbl_805DE3E8;

static void* lbl_8058CCE8[32];
static u32 lbl_8058CD68[64];

s32 kar_psdisp__near_80437bf0(s32 num, s32 size)
{
    HSD_psAppSRT* node;
    s32 i;

    lbl_805DE3E0 = (u16) size;
    lbl_805DE362 = 0;
    lbl_805DE35C = 0;
    lbl_805DE3E4 = NULL;

    for (i = 0; i < num; i++) {
        node = HSD_Alloc(size);
        if (node == NULL) {
            return i;
        }
        memset(node, 0, size);
        node->next = lbl_805DE3E4;
        lbl_805DE3E4 = node;
    }
    return i;
}

void kar_psdisp__near_80437c90(void)
{
    HSD_psAppSRT* node;
    HSD_psAppSRT* next;

    for (node = lbl_805DE3E4; node != NULL; node = next) {
        next = node->next;
        HSD_Free(node);
    }
    lbl_805DE3E4 = NULL;
}

void kar_psdisp__near_80437cd8(HSD_Generator* gp, s32 status)
{
    HSD_psAppSRT* srt;
    u16 idnum;
    u16 used;

    idnum = gp->idnum;
    if (lbl_805DE3E4 == NULL) {
        srt = HSD_Alloc(lbl_805DE3E0);
        lbl_805DE3E4 = srt;
        if (srt != NULL) {
            memset(srt, 0, lbl_805DE3E0);
        }
    }

    srt = lbl_805DE3E4;
    if (srt != NULL) {
        lbl_805DE3E4 = srt->next;
        srt->next = NULL;
        srt->usedCount = 1;
        srt->unk3d = 0;
        srt->status = status;
        srt->translate.z = 0.0F;
        srt->translate.y = 0.0F;
        srt->translate.x = 0.0F;
        srt->rot.z = 0.0F;
        srt->rot.y = 0.0F;
        srt->rot.x = 0.0F;
        srt->scale.z = 1.0F;
        srt->scale.y = 1.0F;
        srt->scale.x = 1.0F;
        srt->unk30.z = 0.0F;
        srt->unk30.y = 0.0F;
        srt->unk30.x = 0.0F;
        srt->freefunc = NULL;
        srt->unk7e = 0;
        srt->gp = NULL;
        srt->idnum = idnum;

        used = lbl_805DE362 + 1;
        lbl_805DE362 = used;
        if (used > lbl_805DE35C) {
            lbl_805DE35C = used;
        }
    }
    gp->appsrt = srt;
}

s32 kar_psdisp__near_80437ddc(HSD_Particle* pp, HSD_psAppSRT* srt)
{
    if (srt == NULL || pp == NULL || pp->appsrt != NULL) {
        return -1;
    }
    pp->appsrt = srt;
    return (u16) ++srt->usedCount;
}

s32 kar_psdisp__near_80437e18(HSD_Generator* gp, HSD_psAppSRT* srt)
{
    if (srt == NULL || gp == NULL || gp->appsrt != NULL) {
        return -1;
    }
    gp->appsrt = srt;
    return (u16) ++srt->usedCount;
}

s32 kar_psdisp__near_80437e54(HSD_Particle* pp, HSD_psAppSRT* srt)
{
    if (srt == NULL || pp == NULL) {
        return -1;
    }
    if (pp->appsrt != NULL) {
        psRemoveParticleAppSRT(pp);
    }
    pp->appsrt = srt;
    return (u16) ++srt->usedCount;
}

s32 kar_psdisp__near_80437ec0(HSD_Generator* gp, HSD_psAppSRT* srt)
{
    if (srt == NULL || gp == NULL) {
        return -1;
    }
    if (gp->appsrt != NULL) {
        kar_psdisp__near_80437fcc(gp);
    }
    gp->appsrt = srt;
    return (u16) ++srt->usedCount;
}

s32 psRemoveParticleAppSRT(HSD_Particle* pp)
{
    HSD_psAppSRT* srt;
    s32 count;

    srt = pp->appsrt;
    if (srt == NULL) {
        return -1;
    }
    count = --srt->usedCount;
    if (count == 0) {
        srt = pp->appsrt;
        if (srt->freefunc != NULL) {
            srt->freefunc(srt);
        }
        srt->next = lbl_805DE3E4;
        lbl_805DE3E4 = srt;
        lbl_805DE362--;
    }
    pp->appsrt = NULL;
    return count;
}

s32 kar_psdisp__near_80437fcc(HSD_Generator* gp)
{
    HSD_psAppSRT* srt;
    s32 count;

    srt = gp->appsrt;
    if (srt == NULL) {
        return -1;
    }
    if (srt->gp == gp) {
        srt->gp = NULL;
    }
    srt = gp->appsrt;
    count = --srt->usedCount;
    if (count == 0) {
        srt = gp->appsrt;
        if (srt->freefunc != NULL) {
            srt->freefunc(srt);
        }
        srt->next = lbl_805DE3E4;
        lbl_805DE3E4 = srt;
        lbl_805DE362--;
    }
    gp->appsrt = NULL;
    return count;
}

s32 kar_psdisp__near_80438084(s32 num)
{
    s32 i;
    void* node;

    for (i = 0; i != 32; i++) {
        lbl_8058CCE8[i] = NULL;
        ((u32*) ((u8*) lbl_8058CCE8 + 0x80))[i] = 0;
        ((u32*) ((u8*) lbl_8058CCE8 + 0x100))[i] = 0;
    }

    lbl_805DE3E8.head = NULL;

    for (i = num - 1; i >= 0; i--) {
        node = HSD_Alloc(0xB0);
        memset(node, 0, 0xB0);
        if (node == NULL) {
            return -1;
        }
        *(void**) node = lbl_805DE3E8.head;
        lbl_805DE3E8.head = node;
    }
    return i;
}

void kar_psdisp__near_80438190(void)
{
    void* node;
    void* next;
    s32 i;

    for (node = lbl_805DE3E8.head; node != NULL; node = next) {
        next = *(void**) node;
        HSD_Free(node);
    }
    lbl_805DE3E8.head = NULL;

    for (i = 0; i < 32; i++) {
        for (node = lbl_8058CCE8[i]; node != NULL; node = next) {
            next = *(void**) node;
            HSD_Free(node);
        }
        lbl_8058CCE8[i] = NULL;
        lbl_8058CD68[i] = 0;
        lbl_8058CD68[32 + i] = 0;
    }
}

void* kar_psdisp__near_80438238(void** dst, u32 bank)
{
    void* node;
    void* head;
    u16 used;

    if (lbl_805DE3E8.head == NULL) {
        lbl_805DE3E8.head = HSD_Alloc(0xB0);
        memset(lbl_805DE3E8.head, 0, 0xB0);
    }

    head = lbl_805DE3E8.head;
    if (head == NULL) {
        return NULL;
    }
    node = head;

    used = lbl_805DE366 + 1;
    lbl_805DE366 = used;
    if (used > lbl_805DE360) {
        lbl_805DE360 = used;
    }

    lbl_805DE3E8.head = *(void**) node;
    if (dst == NULL) {
        *(void**) node = lbl_8058CCE8[bank];
        lbl_8058CCE8[bank] = node;
    } else {
        *(void**) node = *dst;
        *dst = node;
    }
    lbl_8058CD68[bank] = 1;
    return node;
}
