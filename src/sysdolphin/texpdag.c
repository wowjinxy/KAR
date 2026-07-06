#include <global.h>
#include <sysdolphin/texp.h>
#include <sysdolphin/tobj.h>

char kar_srcfile_texp_c_805dcd70[] = "texp.c";

#define TEXP_ASSERT(line, cond) \
    ((cond) ? ((void) 0) : __assert(kar_srcfile_texp_c_805dcd70, line, #cond))
#define TEXP_ASSERT_S(line, cond, str) \
    ((cond) ? ((void) 0) : __assert(kar_srcfile_texp_c_805dcd70, line, str))

extern char lbl_805DCD78[5];    /* "texp" */
extern char lbl_805DCD80[2];    /* "0" */
extern char lbl_805DCD84[5];    /* "desc" */
extern char lbl_805DCD8C[8];    /* "tevdesc" */
extern char lbl_80504950[10];   /* "texp_list" */
extern char lbl_8050495C[0x19]; /* "texp->cnst.ctype == type" */
extern char lbl_80504978[];     /* "HSD_TExpGetType(texp) == HSD_TE_TEV" */

extern void* hsdAllocMemPiece(u32 size);
extern void hsdFreeMemPiece(void* ptr, s32 size);
extern void HSD_Panic(const char* file, s32 line, const char* msg);
extern void memset(void* ptr, s32 value, u32 size);

extern u32 HSD_StateAssignTev(void);
extern void HSD_SetupTevStage(HSD_TevDesc* tevdesc);
extern void HSD_StateInvalidate(s32 mask);
extern void GXPixModeSync(void);
extern void GXSetTevKColor(u32 id, GXColor color);
extern void GXSetTevColor(u32 id, GXColor color);

#define GX_TEV_SWAP0 0
#define GX_TEV_SWAP1 1
#define GX_TEV_SWAP2 2
#define GX_TEV_SWAP3 3

#define GX_CC_CPREV 0
#define GX_CC_APREV 1
#define GX_CC_C0 2
#define GX_CC_A0 3
#define GX_CC_C1 4
#define GX_CC_A1 5
#define GX_CC_C2 6
#define GX_CC_A2 7
#define GX_CC_TEXC 8
#define GX_CC_TEXA 9
#define GX_CC_RASC 10
#define GX_CC_RASA 11
#define GX_CC_ONE 12
#define GX_CC_HALF 13
#define GX_CC_KONST 14
#define GX_CC_ZERO 15

#define GX_CA_APREV 0
#define GX_CA_A0 1
#define GX_CA_A1 2
#define GX_CA_A2 3
#define GX_CA_TEXA 4
#define GX_CA_RASA 5
#define GX_CA_KONST 6
#define GX_CA_ZERO 7

#define GX_TEV_ADD 0
#define GX_TEV_SUB 1

#define GX_TB_ZERO 0
#define GX_TB_ADDHALF 1
#define GX_TB_SUBHALF 2

#define GX_TC_LINEAR 0

#define GX_CS_SCALE_1 0
#define GX_CS_SCALE_2 1
#define GX_CS_SCALE_4 2
#define GX_CS_DIVIDE_2 3

#define GX_TEV_KCSEL_1 0x00
#define GX_TEV_KCSEL_7_8 0x01
#define GX_TEV_KCSEL_3_4 0x02
#define GX_TEV_KCSEL_5_8 0x03
#define GX_TEV_KCSEL_1_2 0x04
#define GX_TEV_KCSEL_3_8 0x05
#define GX_TEV_KCSEL_1_4 0x06
#define GX_TEV_KCSEL_1_8 0x07
#define GX_TEV_KCSEL_K0 0x0C
#define GX_TEV_KCSEL_K1 0x0D
#define GX_TEV_KCSEL_K2 0x0E
#define GX_TEV_KCSEL_K3 0x0F
#define GX_TEV_KCSEL_K0_R 0x10
#define GX_TEV_KCSEL_K1_R 0x11
#define GX_TEV_KCSEL_K2_R 0x12
#define GX_TEV_KCSEL_K3_R 0x13
#define GX_TEV_KCSEL_K0_G 0x14
#define GX_TEV_KCSEL_K1_G 0x15
#define GX_TEV_KCSEL_K2_G 0x16
#define GX_TEV_KCSEL_K3_G 0x17
#define GX_TEV_KCSEL_K0_B 0x18
#define GX_TEV_KCSEL_K1_B 0x19
#define GX_TEV_KCSEL_K2_B 0x1A
#define GX_TEV_KCSEL_K3_B 0x1B
#define GX_TEV_KCSEL_K0_A 0x1C
#define GX_TEV_KCSEL_K1_A 0x1D
#define GX_TEV_KCSEL_K2_A 0x1E
#define GX_TEV_KCSEL_K3_A 0x1F

#define GX_TEV_KASEL_1 0x00
#define GX_TEV_KASEL_7_8 0x01
#define GX_TEV_KASEL_3_4 0x02
#define GX_TEV_KASEL_5_8 0x03
#define GX_TEV_KASEL_1_2 0x04
#define GX_TEV_KASEL_3_8 0x05
#define GX_TEV_KASEL_1_4 0x06
#define GX_TEV_KASEL_1_8 0x07
#define GX_TEV_KASEL_K0_R 0x10
#define GX_TEV_KASEL_K1_R 0x11
#define GX_TEV_KASEL_K2_R 0x12
#define GX_TEV_KASEL_K3_R 0x13
#define GX_TEV_KASEL_K0_G 0x14
#define GX_TEV_KASEL_K1_G 0x15
#define GX_TEV_KASEL_K2_G 0x16
#define GX_TEV_KASEL_K3_G 0x17
#define GX_TEV_KASEL_K0_B 0x18
#define GX_TEV_KASEL_K1_B 0x19
#define GX_TEV_KASEL_K2_B 0x1A
#define GX_TEV_KASEL_K3_B 0x1B
#define GX_TEV_KASEL_K0_A 0x1C
#define GX_TEV_KASEL_K1_A 0x1D
#define GX_TEV_KASEL_K2_A 0x1E
#define GX_TEV_KASEL_K3_A 0x1F

#define GX_COLOR_NULL 0xFF

#define GX_KCOLOR0 0
#define GX_KCOLOR1 1
#define GX_KCOLOR2 2
#define GX_KCOLOR3 3

#define GX_TEVPREV 0
#define GX_TEVREG0 1
#define GX_TEVREG1 2
#define GX_TEVREG2 3

#define GX_ENABLE 1
#define GX_DISABLE 0
#define GX_TRUE 1
#define GX_FALSE 0

struct HSD_TExpDag {
    HSD_TETev* tev;
    u8 idx;
    u8 nb_dep;
    u8 nb_ref;
    u8 dist;
    struct HSD_TExpDag* depend[8];
};

struct HSD_TExpRes {
    s32 failed;
    s32 texmap;
    s32 cnst_remain;
    struct {
        u8 color;
        u8 alpha;
    } reg[8];
    u8 c_ref[4];
    u8 a_ref[4];
    u8 c_use[4];
    u8 a_use[4];
};

extern u32 lbl_805028E8[];

int HSD_TExpMakeDag(HSD_TExp* root, struct HSD_TExpDag* list);
void HSD_TExpSchedule(int num, struct HSD_TExpDag* list, HSD_TExp** result,
                      struct HSD_TExpRes* resource);
int HSD_TExpSimplify(HSD_TExp* texp_);
int HSD_TExpSimplify2(HSD_TExp* texp_);

static inline bool IsThroughColor(HSD_TExp* texp)
{
    return texp->tev.c_op == GX_TEV_ADD && texp->tev.c_in[0].sel == HSD_TE_0 &&
           texp->tev.c_in[1].sel == HSD_TE_0 && texp->tev.c_bias == 0 &&
           texp->tev.c_scale == 0;
}

static inline bool IsThroughAlpha(HSD_TExp* texp)
{
    return texp->tev.a_op == GX_TEV_ADD && texp->tev.a_in[0].sel == HSD_TE_0 &&
           texp->tev.a_in[1].sel == HSD_TE_0 && texp->tev.a_bias == 0 &&
           texp->tev.a_scale == 0;
}

HSD_TExpType HSD_TExpGetType(HSD_TExp* texp)
{
    if (texp == NULL) {
        return HSD_TE_ZERO;
    }
    if ((u32) texp == (u32) HSD_TEXP_TEX) {
        return HSD_TE_TEX;
    }
    if ((u32) texp == (u32) -2) {
        return HSD_TE_RAS;
    }
    return texp->type;
}

void HSD_TExpRef(HSD_TExp* texp, u8 sel)
{
    HSD_TExpType type = HSD_TExpGetType(texp);
    switch (type) {
    case HSD_TE_TEV:
        if (sel == 1) {
            texp->tev.c_ref += 1;
            return;
        } else {
            texp->tev.a_ref += 1;
            return;
        }
        break;
    case HSD_TE_CNST:
        texp->cnst.ref += 1;
        break;
    }
}

void HSD_TExpUnref(HSD_TExp* texp, u8 sel)
{
    s32 i;
    HSD_TExpType type = HSD_TExpGetType(texp);

    if (type != HSD_TE_CNST) {
        if (type >= HSD_TE_CNST || type != HSD_TE_TEV) {
            return;
        }
        if (sel == 1) {
            if (texp->tev.c_ref != 0) {
                texp->tev.c_ref -= 1;
            }
        } else if (texp->tev.a_ref != 0) {
            texp->tev.a_ref -= 1;
        }

        if (texp->tev.c_ref == 0 && texp->tev.a_ref == 0) {
            for (i = 0; i < 4; i++) {
                HSD_TExpUnref(texp->tev.c_in[i].exp, texp->tev.c_in[i].sel);
                HSD_TExpUnref(texp->tev.a_in[i].exp, texp->tev.a_in[i].sel);
            }
        }
        return;
    }

    if (texp->cnst.ref != 0) {
        texp->cnst.ref -= 1;
        return;
    }
}

HSD_TExp* HSD_TExpFreeList(HSD_TExp* texp_list, HSD_TExpType type, s32 all)
{
    HSD_TExp** handle;
    HSD_TExp* ptr;
    HSD_TExp* next;

    handle = &texp_list;

    if (all != 0) {
        while (*handle != NULL) {
            if (type == HSD_TE_ALL || type == (*handle)->type) {
                switch ((*handle)->type) {
                case HSD_TE_TEV:
                    next = (*handle)->tev.next;
                    switch (HSD_TExpGetType(*handle)) {
                    case HSD_TE_TEV:
                        hsdFreeMemPiece(*handle, sizeof(HSD_TETev));
                        break;
                    case HSD_TE_CNST:
                        hsdFreeMemPiece(*handle, sizeof(HSD_TECnst));
                        break;
                    }
                    *handle = next;
                    continue;
                case HSD_TE_CNST:
                    next = (*handle)->tev.next;
                    switch (HSD_TExpGetType(*handle)) {
                    case HSD_TE_TEV:
                        hsdFreeMemPiece(*handle, sizeof(HSD_TETev));
                        break;
                    case HSD_TE_CNST:
                        hsdFreeMemPiece(*handle, sizeof(HSD_TECnst));
                        break;
                    }
                    *handle = next;
                    continue;
                default:
                    TEXP_ASSERT_S(220, 0, lbl_805DCD80);
                }
            }
            handle = &(*handle)->tev.next;
        }
    } else {
        if (type == HSD_TE_ALL || type == HSD_TE_TEV) {
            for (ptr = texp_list; ptr != NULL; ptr = ptr->tev.next) {
                switch (ptr->type) {
                case HSD_TE_TEV:
                    if (ptr->tev.c_ref == 0 && ptr->tev.c_ref == 0) {
                        HSD_TExpUnref(ptr, 1);
                        HSD_TExpUnref(ptr, 5);
                    }
                    break;
                }
            }
        }

        while (*handle != NULL) {
            if (type == HSD_TE_ALL || type == (*handle)->type) {
                switch ((*handle)->type) {
                case HSD_TE_TEV:
                    if ((*handle)->tev.c_ref != 0 || (*handle)->tev.a_ref != 0)
                    {
                        break;
                    }
                    next = (*handle)->tev.next;
                    switch (HSD_TExpGetType(*handle)) {
                    case HSD_TE_TEV:
                        hsdFreeMemPiece(*handle, sizeof(HSD_TETev));
                        break;
                    case HSD_TE_CNST:
                        hsdFreeMemPiece(*handle, sizeof(HSD_TECnst));
                        break;
                    }
                    *handle = next;
                    continue;
                case HSD_TE_CNST:
                    if ((*handle)->cnst.ref != 0) {
                        break;
                    }
                    next = (*handle)->tev.next;
                    switch (HSD_TExpGetType(*handle)) {
                    case HSD_TE_TEV:
                        hsdFreeMemPiece(*handle, sizeof(HSD_TETev));
                        break;
                    case HSD_TE_CNST:
                        hsdFreeMemPiece(*handle, sizeof(HSD_TECnst));
                        break;
                    }
                    *handle = next;
                    continue;
                default:
                    TEXP_ASSERT_S(268, 0, lbl_805DCD80);
                }
            }
            handle = &(*handle)->tev.next;
        }
    }

    return texp_list;
}

HSD_TExp* HSD_TExpTev(HSD_TExp** texp_list)
{
    s32 i;
    HSD_TExp* texp;

    TEXP_ASSERT_S(295, texp_list, lbl_80504950);
    texp = hsdAllocMemPiece(sizeof(HSD_TETev));
    TEXP_ASSERT(63, texp);
    memset(texp, 0xFF, sizeof(HSD_TETev));
    texp->type = HSD_TE_TEV;
    texp->tev.next = *texp_list;
    *texp_list = texp;
    texp->tev.c_ref = 0;
    texp->tev.a_ref = 0;
    texp->tev.tex = NULL;
    for (i = 0; i < 4; i++) {
        texp->tev.c_in[i].exp = NULL;
        texp->tev.a_in[i].exp = NULL;
    }
    return texp;
}

HSD_TExp* HSD_TExpCnst(void* val, HSD_TEInput comp, HSD_TEType type,
                       HSD_TExp** texp_list)
{
    HSD_TExp* texp;

    TEXP_ASSERT_S(362, texp_list, lbl_80504950);

    texp = *texp_list;
    do {
        while (texp) {
            if (texp->type == HSD_TE_CNST && texp->cnst.val == val &&
                texp->cnst.comp == comp)
            {
                TEXP_ASSERT_S(369, texp->cnst.ctype == type, lbl_8050495C);
                return texp;
            }
            texp = texp->cnst.next;
        }

        if (comp == HSD_TE_0) {
            return NULL;
        }
        texp = hsdAllocMemPiece(sizeof(HSD_TECnst));
        TEXP_ASSERT_S(71, texp, lbl_805DCD78);
        texp->cnst.type = HSD_TE_CNST;
        texp->cnst.next = (*texp_list);
        *texp_list = texp;
        texp->cnst.ref = 0;
        texp->cnst.val = val;
        texp->cnst.comp = comp;
        texp->cnst.ctype = type;
        texp->cnst.reg = 0xFF;
        texp->cnst.idx = 0xFF;
        texp->cnst.range = 0;
        return texp;
    } while (1);

    return texp;
}

void HSD_TExpColorOp(HSD_TExp* texp, s32 op, u32 bias, u32 scale, u8 clamp)
{
    TEXP_ASSERT_S(410, texp, lbl_805DCD78);
    TEXP_ASSERT_S(411, HSD_TExpGetType(texp) == HSD_TE_TEV, lbl_80504978);

    texp->tev.c_op = op;
    texp->tev.c_clamp = (clamp ? GX_ENABLE : GX_DISABLE);
    if (op == GX_TEV_ADD || op == GX_TEV_SUB) {
        texp->tev.c_bias = bias;
        texp->tev.c_scale = scale;
    } else {
        texp->tev.c_bias = 0;
        texp->tev.c_scale = 0;
    }
}

void HSD_TExpAlphaOp(HSD_TExp* texp, s32 op, u32 bias, u32 scale, u8 clamp)
{
    TEXP_ASSERT_S(436, texp, lbl_805DCD78);
    TEXP_ASSERT_S(437, HSD_TExpGetType(texp) == HSD_TE_TEV, lbl_80504978);

    texp->tev.a_op = op;
    texp->tev.a_clamp = (clamp ? GX_ENABLE : GX_DISABLE);
    if (op == GX_TEV_ADD || op == GX_TEV_SUB) {
        texp->tev.a_bias = bias;
        texp->tev.a_scale = scale;
    } else {
        texp->tev.a_bias = 0;
        texp->tev.a_scale = 0;
    }
}

void HSD_TExpColorInSub(HSD_TETev* tev, HSD_TEInput sel, HSD_TExp* exp,
                        s32 idx)
{
    HSD_TEArg prev;
    u8 ksel;

    prev = tev->c_in[idx];
    tev->c_in[idx].type = HSD_TExpGetType(exp);
    tev->c_in[idx].sel = sel;
    tev->c_in[idx].exp = exp;
    tev->c_in[idx].arg = 0xFF;

    switch (sel) {
    case HSD_TE_0:
        tev->c_in[idx].arg = GX_CC_ZERO;
        tev->c_in[idx].type = HSD_TE_ZERO;
        tev->c_in[idx].exp = NULL;
        break;
    case HSD_TE_1:
        tev->c_in[idx].arg = GX_CC_ONE;
        tev->c_in[idx].type = HSD_TE_IMM;
        tev->c_in[idx].exp = NULL;
        break;
    case HSD_TE_4_8:
        tev->c_in[idx].arg = GX_CC_HALF;
        tev->c_in[idx].type = HSD_TE_IMM;
        tev->c_in[idx].exp = NULL;
        break;
    case HSD_TE_1_8:
    case HSD_TE_2_8:
    case HSD_TE_3_8:
    case HSD_TE_5_8:
    case HSD_TE_6_8:
    case HSD_TE_7_8:
        tev->c_in[idx].arg = GX_CC_KONST;
        switch (sel) {
        case HSD_TE_1_8:
            ksel = GX_TEV_KCSEL_1_8;
            break;
        case HSD_TE_2_8:
            ksel = GX_TEV_KCSEL_1_4;
            break;
        case HSD_TE_3_8:
            ksel = GX_TEV_KCSEL_3_8;
            break;
        case HSD_TE_5_8:
            ksel = GX_TEV_KCSEL_5_8;
            break;
        case HSD_TE_6_8:
            ksel = GX_TEV_KCSEL_3_4;
            break;
        case HSD_TE_7_8:
            ksel = GX_TEV_KCSEL_7_8;
            break;
        default:
            TEXP_ASSERT_S(500, 0, lbl_805DCD80);
            break;
        }

        if (tev->kcsel == HSD_TE_UNDEF) {
            tev->kcsel = ksel;
        } else if (tev->kcsel == ksel) {
            HSD_Panic(kar_srcfile_texp_c_805dcd70, 505,
                      "tev can't select multiple konst input.\n");
        }
        tev->c_in[idx].type = HSD_TE_KONST;
        break;

    default: {
        switch (tev->c_in[idx].type) {
        case HSD_TE_ZERO:
            tev->c_in[idx].type = HSD_TE_ZERO;
            tev->c_in[idx].sel = HSD_TE_0;
            tev->c_in[idx].arg = GX_CC_ZERO;
            break;
        case HSD_TE_TEV: {
            u8 swap;
            TEXP_ASSERT(521, sel == HSD_TE_RGB || sel == HSD_TE_A);
            TEXP_ASSERT(523,
                        idx == 3 || sel != HSD_TE_RGB || exp->tev.c_clamp);
            TEXP_ASSERT(524, idx == 3 || sel != HSD_TE_A || exp->tev.a_clamp);
            swap = tev->c_in[idx].sel;
            switch (HSD_TExpGetType(tev->c_in[idx].exp)) {
            case HSD_TE_TEV:
                if (swap == 1) {
                    tev->c_in[idx].exp->tev.c_ref += 1;
                } else {
                    tev->c_in[idx].exp->tev.a_ref += 1;
                }
                break;
            case HSD_TE_CNST:
                tev->c_in[idx].exp->cnst.ref += 1;
                break;
            }
        } break;
        case HSD_TE_CNST: {
            u8 swap;
            tev->c_in[idx].sel = exp->cnst.comp;
            swap = tev->c_in[idx].sel;
            switch (HSD_TExpGetType(tev->c_in[idx].exp)) {
            case HSD_TE_TEV:
                if (swap == 1) {
                    tev->c_in[idx].exp->tev.c_ref += 1;
                } else {
                    tev->c_in[idx].exp->tev.a_ref += 1;
                }
                break;
            case HSD_TE_CNST:
                tev->c_in[idx].exp->cnst.ref += 1;
                break;
            }
        } break;
        case HSD_TE_TEX: {
            u8 swap = HSD_TE_UNDEF;
            switch (sel) {
            case HSD_TE_RGB:
                tev->c_in[idx].arg = GX_CC_TEXC;
                swap = GX_TEV_SWAP0;
                break;
            case HSD_TE_R:
                tev->c_in[idx].arg = GX_CC_TEXC;
                swap = GX_TEV_SWAP1;
                break;
            case HSD_TE_G:
                tev->c_in[idx].arg = GX_CC_TEXC;
                swap = GX_TEV_SWAP2;
                break;
            case HSD_TE_B:
                tev->c_in[idx].arg = GX_CC_TEXC;
                swap = GX_TEV_SWAP3;
                break;
            case HSD_TE_A:
                tev->c_in[idx].arg = GX_CC_TEXA;
                break;
            default:
                TEXP_ASSERT_S(559, 0, lbl_805DCD80);
                break;
            }
            if (tev->tex_swap == HSD_TE_UNDEF) {
                tev->tex_swap = swap;
            } else {
                TEXP_ASSERT(564, swap == HSD_TE_UNDEF || tev->tex_swap == swap);
            }
        } break;
        case HSD_TE_RAS: {
            u8 swap = HSD_TE_UNDEF;
            switch (sel) {
            case HSD_TE_RGB:
                tev->c_in[idx].arg = GX_CC_RASC;
                swap = GX_TEV_SWAP0;
                break;
            case HSD_TE_R:
                tev->c_in[idx].arg = GX_CC_RASC;
                swap = GX_TEV_SWAP1;
                break;
            case HSD_TE_G:
                tev->c_in[idx].arg = GX_CC_RASC;
                swap = GX_TEV_SWAP2;
                break;
            case HSD_TE_B:
                tev->c_in[idx].arg = GX_CC_RASC;
                swap = GX_TEV_SWAP3;
                break;
            case HSD_TE_A:
                tev->c_in[idx].arg = GX_CC_RASA;
                break;
            default:
                TEXP_ASSERT_S(607, 0, lbl_805DCD80);
                break;
            }
            if (tev->ras_swap == HSD_TE_UNDEF) {
                tev->ras_swap = swap;
            } else {
                TEXP_ASSERT(612, swap == HSD_TE_UNDEF || tev->ras_swap == swap);
            }
        } break;
        default:
            TEXP_ASSERT_S(630, 0, lbl_805DCD80);
            break;
        }
    }
    }
    HSD_TExpUnref(prev.exp, prev.sel);
}

void HSD_TExpColorIn(HSD_TExp* texp, HSD_TEInput sel_a, HSD_TExp* exp_a,
                     HSD_TEInput sel_b, HSD_TExp* exp_b, HSD_TEInput sel_c,
                     HSD_TExp* exp_c, HSD_TEInput sel_d, HSD_TExp* exp_d)
{
    HSD_TETev* tev;

    TEXP_ASSERT_S(693, texp, lbl_805DCD78);
    TEXP_ASSERT_S(694, HSD_TExpGetType(texp) == HSD_TE_TEV, lbl_80504978);

    tev = &texp->tev;
    HSD_TExpColorInSub(tev, sel_a, exp_a, 0);
    HSD_TExpColorInSub(tev, sel_b, exp_b, 1);
    HSD_TExpColorInSub(tev, sel_c, exp_c, 2);
    HSD_TExpColorInSub(tev, sel_d, exp_d, 3);
}

void HSD_TExpAlphaInSub(HSD_TETev* tev, HSD_TEInput sel, HSD_TExp* exp,
                        s32 idx)
{
    HSD_TEArg prev;
    u8 ksel;

    prev = tev->a_in[idx];
    tev->a_in[idx].sel = sel;
    tev->a_in[idx].exp = exp;
    tev->a_in[idx].type = HSD_TExpGetType(exp);
    tev->a_in[idx].arg = 0xFF;

    switch (sel) {
    case HSD_TE_0:
        tev->a_in[idx].type = HSD_TE_ZERO;
        tev->a_in[idx].arg = GX_CA_ZERO;
        tev->a_in[idx].exp = NULL;
        break;

    case HSD_TE_1:
    case HSD_TE_1_8:
    case HSD_TE_2_8:
    case HSD_TE_3_8:
    case HSD_TE_4_8:
    case HSD_TE_5_8:
    case HSD_TE_6_8:
    case HSD_TE_7_8:
        tev->a_in[idx].exp = NULL;
        tev->a_in[idx].arg = GX_CA_KONST;
        switch (sel) {
        case HSD_TE_1_8:
            ksel = GX_TEV_KASEL_1_8;
            break;
        case HSD_TE_2_8:
            ksel = GX_TEV_KASEL_1_4;
            break;
        case HSD_TE_3_8:
            ksel = GX_TEV_KASEL_3_8;
            break;
        case HSD_TE_4_8:
            ksel = GX_TEV_KASEL_1_2;
            break;
        case HSD_TE_5_8:
            ksel = GX_TEV_KASEL_5_8;
            break;
        case HSD_TE_6_8:
            ksel = GX_TEV_KASEL_3_4;
            break;
        case HSD_TE_7_8:
            ksel = GX_TEV_KASEL_7_8;
            break;
        default:
            ksel = GX_TEV_KASEL_1;
            break;
        }

        if (tev->kasel == HSD_TE_UNDEF) {
            tev->kasel = ksel;
        } else {
            TEXP_ASSERT(750, tev->kasel == ksel);
        }
        tev->a_in[idx].type = HSD_TE_KONST;
        break;

    default: {
        switch (tev->a_in[idx].type) {
        case HSD_TE_ZERO:
            tev->a_in[idx].exp = NULL;
            tev->a_in[idx].type = HSD_TE_ZERO;
            tev->a_in[idx].sel = HSD_TE_0;
            tev->a_in[idx].arg = GX_CA_ZERO;
            break;
        case HSD_TE_TEV:
            TEXP_ASSERT(773, sel == HSD_TE_A);
            TEXP_ASSERT(774, idx == 3 || exp->tev.a_clamp);
            HSD_TExpRef(tev->a_in[idx].exp, tev->a_in[idx].sel);
            break;
        case HSD_TE_CNST:
            TEXP_ASSERT(778, sel == HSD_TE_A || sel == HSD_TE_X);
            TEXP_ASSERT(779, exp->cnst.comp == HSD_TE_X);
            tev->a_in[idx].sel = HSD_TE_X;
            HSD_TExpRef(tev->a_in[idx].exp, tev->a_in[idx].sel);
            break;
        case HSD_TE_TEX:
            TEXP_ASSERT(784, sel == HSD_TE_A);
            tev->a_in[idx].arg = GX_CA_TEXA;
            break;
        case HSD_TE_RAS:
            TEXP_ASSERT(788, sel == HSD_TE_A);
            tev->a_in[idx].arg = GX_CA_RASA;
            break;
        default:
            TEXP_ASSERT_S(792, 0, lbl_805DCD80);
            break;
        }
    }
    }
    HSD_TExpUnref(prev.exp, prev.sel);
}

void HSD_TExpAlphaIn(HSD_TExp* texp, HSD_TEInput sel_a, HSD_TExp* exp_a,
                     HSD_TEInput sel_b, HSD_TExp* exp_b, HSD_TEInput sel_c,
                     HSD_TExp* exp_c, HSD_TEInput sel_d, HSD_TExp* exp_d)
{
    HSD_TETev* tev;

    TEXP_ASSERT_S(823, texp, lbl_805DCD78);
    TEXP_ASSERT_S(824, HSD_TExpGetType(texp) == HSD_TE_TEV, lbl_80504978);

    tev = &texp->tev;
    HSD_TExpAlphaInSub(tev, sel_a, exp_a, 0);
    HSD_TExpAlphaInSub(tev, sel_b, exp_b, 1);
    HSD_TExpAlphaInSub(tev, sel_c, exp_c, 2);
    HSD_TExpAlphaInSub(tev, sel_d, exp_d, 3);
}

void HSD_TExpOrder(HSD_TExp* texp, HSD_TObj* tex, s32 chan)
{
    TEXP_ASSERT_S(839, texp, lbl_805DCD78);
    TEXP_ASSERT_S(840, HSD_TExpGetType(texp) == HSD_TE_TEV, lbl_80504978);

    texp->tev.tex = tex;
    if (chan == GX_COLOR_NULL) {
        texp->tev.chan = GX_COLOR_NULL;
        return;
    }
    texp->tev.chan = chan;
}

int AssignColorReg(HSD_TETev* tev, int idx, HSD_TExpRes* res)
{
    static u32 acr_a_in[4] = { GX_CC_A0, GX_CC_A1, GX_CC_A2, GX_CC_APREV };
    static u32 acr_c_in[4] = { GX_CC_C0, GX_CC_C1, GX_CC_C2, GX_CC_CPREV };

    HSD_TECnst* cnst;
    int j;

    cnst = &tev->c_in[idx].exp->cnst;
    if (cnst->reg != HSD_TE_UNDEF) {
        if (cnst->reg < 4) {
            return -1;
        }
        tev->c_in[idx].type = HSD_TE_IMM;
        if (cnst->comp == HSD_TE_X) {
            tev->c_in[idx].arg = acr_a_in[cnst->reg - 4];
        } else {
            tev->c_in[idx].arg = acr_c_in[cnst->reg - 4];
        }
        return 0;
    } else {
        if (cnst->comp == HSD_TE_X) {
            for (j = 4; j < 8; ++j) {
                if (res->reg[j].alpha == 0) {
                    res->reg[j].alpha = 1;
                    cnst->reg = j;
                    cnst->idx = 3;
                    tev->c_in[idx].type = HSD_TE_IMM;
                    tev->c_in[idx].arg = acr_a_in[j - 4];
                    return 0;
                }
            }
        } else {
            for (j = 4; j < 8; ++j) {
                if (res->reg[j].color == 0) {
                    res->reg[j].color = 3;
                    cnst->reg = j;
                    cnst->idx = 0;
                    tev->c_in[idx].type = HSD_TE_IMM;
                    tev->c_in[idx].arg = acr_c_in[j - 4];
                    return 0;
                }
            }
        }
    }
    return -1;
}

int AssignColorKonst(HSD_TETev* tev, int idx, HSD_TExpRes* res)
{
    static u32 xsel[4][4] = {
        { GX_TEV_KCSEL_K0_R, GX_TEV_KCSEL_K0_G, GX_TEV_KCSEL_K0_B,
          GX_TEV_KCSEL_K0_A },
        { GX_TEV_KCSEL_K1_R, GX_TEV_KCSEL_K1_G, GX_TEV_KCSEL_K1_B,
          GX_TEV_KCSEL_K1_A },
        { GX_TEV_KCSEL_K2_R, GX_TEV_KCSEL_K2_G, GX_TEV_KCSEL_K2_B,
          GX_TEV_KCSEL_K2_A },
        { GX_TEV_KCSEL_K3_R, GX_TEV_KCSEL_K3_G, GX_TEV_KCSEL_K3_B,
          GX_TEV_KCSEL_K3_A }
    };

    static u32 csel[4] = { GX_TEV_KCSEL_K0, GX_TEV_KCSEL_K1, GX_TEV_KCSEL_K2,
                           GX_TEV_KCSEL_K3 };

    HSD_TECnst* cnst;
    int j;

    cnst = &tev->c_in[idx].exp->cnst;
    if (cnst->reg != HSD_TE_UNDEF) {
        if (cnst->reg >= 4) {
            return -1;
        }
        if (cnst->comp == HSD_TE_X) {
            tev->kcsel = xsel[cnst->reg][cnst->idx];
            tev->c_in[idx].type = HSD_TE_KONST;
            tev->c_in[idx].arg = GX_CC_KONST;
        } else {
            tev->kcsel = csel[cnst->reg];
            tev->c_in[idx].type = HSD_TE_KONST;
            tev->c_in[idx].arg = GX_CC_KONST;
        }
        return 0;
    } else {
        if (cnst->comp == HSD_TE_X) {
            for (j = 1; j < 4; j++) {
                if (res->reg[j].alpha == 0) {
                    res->reg[j].alpha = 1;
                    cnst->reg = j;
                    cnst->idx = 3;
                    tev->kcsel = xsel[cnst->reg][cnst->idx];
                    tev->c_in[idx].type = HSD_TE_KONST;
                    tev->c_in[idx].arg = GX_CC_KONST;
                    return 0;
                }
            }

            for (j = 0; j < 4; j++) {
                if (res->reg[j].color < 3) {
                    cnst->reg = j;
                    cnst->idx = res->reg[j].color++;
                    tev->kcsel = xsel[cnst->reg][cnst->idx];
                    tev->c_in[idx].type = HSD_TE_KONST;
                    tev->c_in[idx].arg = GX_CC_KONST;
                    return 0;
                }
            }
        } else {
            for (j = 0; j < 4; j++) {
                if (res->reg[j].color == 0) {
                    res->reg[j].color = 3;
                    cnst->reg = j;
                    cnst->idx = 0;
                    tev->kcsel = csel[cnst->reg];
                    tev->c_in[idx].type = HSD_TE_KONST;
                    tev->c_in[idx].arg = GX_CC_KONST;
                    return 0;
                }
            }
        }
    }
    return -1;
}

int AssignAlphaKonst(HSD_TETev* tev, int idx, HSD_TExpRes* res)
{
    static u32 sel[4][4] = {
        { GX_TEV_KASEL_K0_R, GX_TEV_KASEL_K0_G, GX_TEV_KASEL_K0_B,
          GX_TEV_KASEL_K0_A },
        { GX_TEV_KASEL_K1_R, GX_TEV_KASEL_K1_G, GX_TEV_KASEL_K1_B,
          GX_TEV_KASEL_K1_A },
        { GX_TEV_KASEL_K2_R, GX_TEV_KASEL_K2_G, GX_TEV_KASEL_K2_B,
          GX_TEV_KASEL_K2_A },
        { GX_TEV_KASEL_K3_R, GX_TEV_KASEL_K3_G, GX_TEV_KASEL_K3_B,
          GX_TEV_KASEL_K3_A }
    };

    HSD_TECnst* cnst;
    int j;

    cnst = &tev->a_in[idx].exp->cnst;
    if (cnst->reg != HSD_TE_UNDEF) {
        if (cnst->reg >= 4) {
            return -1;
        }
        tev->kasel = sel[cnst->reg][cnst->idx];
        tev->a_in[idx].type = HSD_TE_KONST;
        tev->a_in[idx].arg = GX_CA_KONST;
        return 0;
    } else {
        for (j = 1; j < 4; j++) {
            if (res->reg[j].alpha == 0) {
                res->reg[j].alpha = 1;
                cnst->reg = j;
                cnst->idx = 3;
                tev->kasel = sel[cnst->reg][cnst->idx];
                tev->a_in[idx].type = HSD_TE_KONST;
                tev->a_in[idx].arg = GX_CA_KONST;
                return 0;
            }
        }

        for (j = 0; j < 4; j++) {
            if (res->reg[j].color < 3) {
                cnst->reg = j;
                cnst->idx = res->reg[j].color++;
                tev->kasel = sel[cnst->reg][cnst->idx];
                tev->a_in[idx].type = HSD_TE_KONST;
                tev->a_in[idx].arg = GX_CA_KONST;
                return 0;
            }
        }
    }
    return -1;
}

static inline int AssignAlphaReg(HSD_TETev* tev, int idx, HSD_TExpRes* res)
{
    static u32 in[4] = { GX_CA_A0, GX_CA_A1, GX_CA_A2, GX_CA_APREV };

    HSD_TECnst* cnst;
    int j;

    cnst = &tev->a_in[idx].exp->cnst;
    if (cnst->reg != HSD_TE_UNDEF) {
        if (cnst->reg < 4) {
            return -1;
        }
        tev->a_in[idx].type = HSD_TE_IMM;
        tev->a_in[idx].arg = in[cnst->reg - 4];
        return 0;
    } else {
        for (j = 4; j < 8; ++j) {
            if (res->reg[j].alpha == 0) {
                res->reg[j].alpha = 1;
                cnst->reg = j;
                cnst->idx = 3;
                tev->a_in[idx].type = HSD_TE_IMM;
                tev->a_in[idx].arg = in[j - 4];
                return 0;
            }
        }
    }
    return -1;
}

int TExpAssignReg(HSD_TExp* texp, HSD_TExpRes* res)
{
    HSD_TETev* tev;
    int i, val;

    tev = &texp->tev;

    if (tev->c_ref > 0) {
        if (tev->kcsel != HSD_TE_UNDEF) {
            for (i = 0; i < 4; i++) {
                if (tev->c_in[i].type == HSD_TE_CNST) {
                    val = AssignColorReg(tev, i, res);
                    if (val < 0) {
                        TEXP_ASSERT(1149, val >= 0);
                        return val;
                    }
                }
            }
        } else if (IsThroughColor(texp) && tev->c_in[3].type == HSD_TE_CNST) {
            if (AssignColorKonst(tev, 3, res) < 0) {
                val = AssignColorReg(tev, 3, res);
                if (val < 0) {
                    TEXP_ASSERT(1162, val >= 0);
                    return val;
                }
            }
        } else {
            for (i = 0; i < 4; i++) {
                if (tev->c_in[i].type == HSD_TE_CNST) {
                    if (AssignColorKonst(tev, i, res) < 0) {
                        val = AssignColorReg(tev, i, res);
                        if (val < 0) {
                            TEXP_ASSERT(1183, val >= 0);
                            return val;
                        }
                    }
                }
            }
            for (; i < 4; i++) {
                if (tev->c_in[i].type == HSD_TE_CNST) {
                    val = AssignColorReg(tev, i, res);
                    if (val < 0) {
                        TEXP_ASSERT(1192, val >= 0);
                        return val;
                    }
                }
            }
        }
    }

    if (tev->a_ref > 0) {
        if (tev->kasel != HSD_TE_UNDEF) {
            for (i = 0; i < 4; i++) {
                if (tev->a_in[i].type == HSD_TE_CNST) {
                    val = AssignAlphaReg(tev, i, res);
                    if (val < 0) {
                        TEXP_ASSERT(1208, val >= 0);
                        return val;
                    }
                }
            }
        } else {
            if (IsThroughAlpha(texp) && tev->a_in[3].type == HSD_TE_CNST) {
                if (AssignAlphaReg(tev, 3, res) < 0) {
                    val = AssignAlphaKonst(tev, 3, res);
                    if (val < 0) {
                        TEXP_ASSERT(1220, val >= 0);
                        return val;
                    }
                }
            } else {
                for (i = 0; i < 4; i++) {
                    if (tev->a_in[i].type == HSD_TE_CNST) {
                        if (AssignAlphaKonst(tev, i, res) < 0) {
                            val = AssignAlphaReg(tev, i, res);
                            if (val < 0) {
                                TEXP_ASSERT(1233, val >= 0);
                                return val;
                            }
                        }
                    }
                }
                for (; i < 4; i++) {
                    if (tev->a_in[i].type == HSD_TE_CNST) {
                        val = AssignAlphaReg(tev, i, res);
                        if (val < 0) {
                            TEXP_ASSERT(1242, val >= 0);
                            return val;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

void TExp2TevDesc(HSD_TExp* texp, HSD_TExpTevDesc* desc, int* init_cprev,
                   int* init_aprev)
{
    static u32 dst[4] = { GX_TEVREG0, GX_TEVREG1, GX_TEVREG2, GX_TEVPREV };

    HSD_TETev* tev;
    HSD_TevDesc* tevdesc;

    TEXP_ASSERT_S(1298, texp, lbl_805DCD78);
    TEXP_ASSERT_S(1299, desc, lbl_805DCD84);
    TEXP_ASSERT(1300, HSD_TExpGetType(texp) == HSD_TE_TEV);

    tev = &texp->tev;
    tevdesc = &desc->desc;

    tevdesc->next = NULL;
    tevdesc->flags = 1;
    desc->tobj = tev->tex;
    if (tev->tex == NULL) {
        tevdesc->coord = HSD_TE_UNDEF;
        tevdesc->map = HSD_TE_UNDEF;
    }
    tevdesc->color = tev->chan == HSD_TE_UNDEF ? HSD_TE_UNDEF : tev->chan;
    tevdesc->u.tevconf.ras_swap =
        tev->ras_swap == HSD_TE_UNDEF ? 0 : tev->ras_swap;
    tevdesc->u.tevconf.tex_swap =
        tev->tex_swap == HSD_TE_UNDEF ? 0 : tev->tex_swap;
    tevdesc->u.tevconf.kcsel = tev->kcsel == HSD_TE_UNDEF ? 0 : tev->kcsel;
    tevdesc->u.tevconf.kasel = tev->kasel == HSD_TE_UNDEF ? 0 : tev->kasel;

    if ((tev->c_op == HSD_TE_UNDEF) ||
        (tev->c_ref == 0 && tev->a_op != 8 && tev->a_op != 9 &&
         tev->a_op != 0xA && tev->a_op != 0xB && tev->a_op != 0xC &&
         tev->a_op != 0xD))
    {
        tevdesc->u.tevconf.clr_op = GX_TEV_ADD;
        tevdesc->u.tevconf.clr_a = GX_CC_ZERO;
        tevdesc->u.tevconf.clr_b = GX_CC_ZERO;
        tevdesc->u.tevconf.clr_c = GX_CC_ZERO;
        if (*init_cprev != 0) {
            *init_cprev = 0;
            tevdesc->u.tevconf.clr_d = GX_CC_ZERO;
        } else {
            tevdesc->u.tevconf.clr_d = GX_CC_CPREV;
        }
        tevdesc->u.tevconf.clr_scale = 0;
        tevdesc->u.tevconf.clr_bias = 0;
        tevdesc->u.tevconf.clr_clamp = 0;
        tevdesc->u.tevconf.clr_out_reg = 0;
    } else {
        tevdesc->u.tevconf.clr_op = tev->c_op;
        tevdesc->u.tevconf.clr_a =
            tev->c_in[0].arg == HSD_TE_UNDEF ? GX_CC_ZERO : tev->c_in[0].arg;
        tevdesc->u.tevconf.clr_b =
            tev->c_in[1].arg == HSD_TE_UNDEF ? GX_CC_ZERO : tev->c_in[1].arg;
        tevdesc->u.tevconf.clr_c =
            tev->c_in[2].arg == HSD_TE_UNDEF ? GX_CC_ZERO : tev->c_in[2].arg;
        tevdesc->u.tevconf.clr_d =
            tev->c_in[3].arg == HSD_TE_UNDEF ? GX_CC_ZERO : tev->c_in[3].arg;
        tevdesc->u.tevconf.clr_scale =
            tev->c_scale == HSD_TE_UNDEF ? 0 : tev->c_scale;
        tevdesc->u.tevconf.clr_bias =
            tev->c_bias == HSD_TE_UNDEF ? 0 : tev->c_bias;
        tevdesc->u.tevconf.clr_clamp = tev->c_clamp != 0 ? GX_TRUE : GX_FALSE;

        TEXP_ASSERT(1363, tev->c_dst != HSD_TE_UNDEF);
        tevdesc->u.tevconf.clr_out_reg = dst[tev->c_dst];
        if (tevdesc->u.tevconf.clr_out_reg == 0) {
            *init_cprev = 0;
        }
    }

    if (tev->a_op == HSD_TE_UNDEF || tev->a_ref == 0) {
        tevdesc->u.tevconf.alpha_op = GX_TEV_ADD;
        tevdesc->u.tevconf.alpha_a = GX_CA_ZERO;
        tevdesc->u.tevconf.alpha_b = GX_CA_ZERO;
        tevdesc->u.tevconf.alpha_c = GX_CA_ZERO;
        if (*init_aprev != 0) {
            *init_aprev = 0;
            tevdesc->u.tevconf.alpha_d = GX_CA_ZERO;
        } else {
            tevdesc->u.tevconf.alpha_d = GX_CA_APREV;
        }
        tevdesc->u.tevconf.alpha_scale = 0;
        tevdesc->u.tevconf.alpha_bias = 0;
        tevdesc->u.tevconf.alpha_clamp = 0;
        tevdesc->u.tevconf.alpha_out_reg = 0;
    } else {
        tevdesc->u.tevconf.alpha_op = tev->a_op;
        tevdesc->u.tevconf.alpha_a =
            tev->a_in[0].arg == HSD_TE_UNDEF ? GX_CA_ZERO : tev->a_in[0].arg;
        tevdesc->u.tevconf.alpha_b =
            tev->a_in[1].arg == HSD_TE_UNDEF ? GX_CA_ZERO : tev->a_in[1].arg;
        tevdesc->u.tevconf.alpha_c =
            tev->a_in[2].arg == HSD_TE_UNDEF ? GX_CA_ZERO : tev->a_in[2].arg;
        tevdesc->u.tevconf.alpha_d =
            tev->a_in[3].arg == HSD_TE_UNDEF ? GX_CA_ZERO : tev->a_in[3].arg;
        tevdesc->u.tevconf.alpha_scale =
            tev->a_scale == HSD_TE_UNDEF ? 0 : tev->a_scale;
        tevdesc->u.tevconf.alpha_bias =
            tev->a_bias == HSD_TE_UNDEF ? 0 : tev->a_bias;
        tevdesc->u.tevconf.alpha_clamp = tev->a_clamp != 0 ? GX_TRUE : GX_FALSE;

        TEXP_ASSERT(1399, tev->a_dst != HSD_TE_UNDEF);
        tevdesc->u.tevconf.alpha_out_reg = dst[tev->a_dst];
        if (tevdesc->u.tevconf.alpha_out_reg == 0) {
            *init_aprev = 0;
        }
    }
    tevdesc->u.tevconf.mode = GX_TC_LINEAR;
}

static u32 id1[4] = { GX_KCOLOR0, GX_KCOLOR1, GX_KCOLOR2, GX_KCOLOR3 };
static u32 id2[3] = { GX_TEVREG0, GX_TEVREG1, GX_TEVREG2 };

void HSD_TExpSetReg(HSD_TExp* texp)
{
    int i;
    GXColor reg[8];
    u32 changed;
    HSD_TECnst* clist;

    clist = &texp->cnst;
    changed = 0;

    while (clist != NULL) {
        TEXP_ASSERT(1427, clist->type == HSD_TE_CNST);
        if (clist->reg < 8) {
            changed |= 1 << clist->reg;
            if (clist->comp == HSD_TE_RGB) {
                switch (clist->ctype) {
                case HSD_TE_U8: {
                    GXColor col;
                    col = *(GXColor*) clist->val;
                    col.a = reg[clist->reg].a;
                    reg[clist->reg] = col;
                    break;
                }
                case HSD_TE_U32: {
                    u32* ptr = clist->val;
                    reg[clist->reg].r = ptr[0] < 0x100 ? ptr[0] : 0xFF;
                    reg[clist->reg].g = ptr[1] < 0x100 ? ptr[1] : 0xFF;
                    reg[clist->reg].b = ptr[2] < 0x100 ? ptr[2] : 0xFF;
                    break;
                }
                default: {
                    int r;
                    int g;
                    int b;
                    switch (clist->ctype) {
                    case HSD_TE_U16: {
                        u16* ptr = clist->val;
                        r = ptr[0];
                        g = ptr[1];
                        b = ptr[2];
                        break;
                    }
                    case HSD_TE_F32: {
                        f32* ptr = clist->val;
                        r = 0xFF * ptr[0];
                        g = 0xFF * ptr[1];
                        b = 0xFF * ptr[2];
                        break;
                    }
                    default: {
                        f64* ptr = clist->val;
                        r = 0xFF * ptr[0];
                        g = 0xFF * ptr[1];
                        b = 0xFF * ptr[2];
                        break;
                    }
                    }
                    reg[clist->reg].r = r > 0xFF ? 0xFF : r < 0 ? 0 : r;
                    reg[clist->reg].g = g > 0xFF ? 0xFF : g < 0 ? 0 : g;
                    reg[clist->reg].b = b > 0xFF ? 0xFF : b < 0 ? 0 : b;
                }
                }
            } else {
                int x;
                u8 val;
                switch (clist->ctype) {
                case HSD_TE_U8:
                    x = *(u8*) clist->val;
                    val = x;
                    break;
                case HSD_TE_U16: {
                    x = *(u16*) clist->val;
                    val = x > 0xFF ? 0xFF : x < 0 ? 0 : x;
                    break;
                }
                case HSD_TE_U32:
                    x = *(u32*) clist->val;
                    val = x > 0xFF ? 0xFF : x < 0 ? 0 : x;
                    break;
                case HSD_TE_F32:
                    x = 0xFF * *(f32*) clist->val;
                    val = x > 0xFF ? 0xFF : x < 0 ? 0 : x;
                    break;
                default:
                    x = 0xFF * *(f64*) clist->val;
                    val = x > 0xFF ? 0xFF : x < 0 ? 0 : x;
                    break;
                }
                if (clist->reg < 4) {
                    switch (clist->idx) {
                    case 0:
                        reg[clist->reg].r = val;
                        break;
                    case 1:
                        reg[clist->reg].g = val;
                        break;
                    case 2:
                        reg[clist->reg].b = val;
                        break;
                    default:
                        reg[clist->reg].a = val;
                        break;
                    }
                } else if (clist->idx == 3) {
                    reg[clist->reg].a = val;
                } else {
                    reg[clist->reg].r = val;
                    reg[clist->reg].g = val;
                    reg[clist->reg].b = val;
                }
            }
        }
        clist = &clist->next->cnst;
    }
    if (changed != 0) {
        GXPixModeSync();
        for (i = 0; i < 4; i++) {
            if (changed & (1 << i)) {
                GXSetTevKColor(id1[i], reg[i]);
            }
        }
        for (i = 4; i < 7; i++) {
            if (changed & (1 << i)) {
                GXSetTevColor(id2[i - 4], reg[i]);
            }
        }
        HSD_StateInvalidate(0x10);
        GXPixModeSync();
    }
}

void HSD_TExpSetupTev(HSD_TExpTevDesc* tevdesc, HSD_TExp* texp)
{
    HSD_TExpSetReg(texp);
    for (; tevdesc != NULL; tevdesc = (HSD_TExpTevDesc*) tevdesc->desc.next) {
        if (tevdesc->tobj != NULL) {
            tevdesc->desc.map = tevdesc->tobj->map_id;
            tevdesc->desc.coord = tevdesc->tobj->coord;
        }
        HSD_StateAssignTev();
        HSD_SetupTevStage(&tevdesc->desc);
    }
}

int HSD_TExpCompile(HSD_TExp* texp, HSD_TExpTevDesc** tevdesc,
                    HSD_TExp** texp_list)
{
    int num, i, val;
    HSD_TExpRes res;
    HSD_TExp* order[32];
    HSD_TExpDag list[32];
    int init_cprev = 1;
    int init_aprev = 1;

    TEXP_ASSERT_S(1629, tevdesc, lbl_805DCD8C);
    TEXP_ASSERT_S(1630, texp_list, lbl_80504950);

    memset(&res, 0, sizeof(HSD_TExpRes));

    HSD_TExpRef(texp, HSD_TE_RGB);
    HSD_TExpRef(texp, HSD_TE_A);
    HSD_TExpSimplify(texp);

    num = HSD_TExpMakeDag(texp, list);
    HSD_TExpSchedule(num, list, order, &res);
    for (i = 0; i < num; ++i) {
        val = TExpAssignReg(order[i], &res);
        TEXP_ASSERT(1662, val >= 0);
    }

    for (i = num - 1; i >= 0; --i) {
        HSD_TExpSimplify2(order[i]);
    }

    num = HSD_TExpMakeDag(texp, list);
    HSD_TExpSchedule(num, list, order, &res);
    *tevdesc = NULL;
    for (i = 0; i < num; ++i) {
        HSD_TExpTevDesc* tdesc = hsdAllocMemPiece(sizeof(HSD_TExpTevDesc));
        tdesc->desc.stage = lbl_805028E8[i];
        TExp2TevDesc(order[(num - i) - 1], tdesc, &init_cprev, &init_aprev);
        tdesc->desc.next = &(*tevdesc)->desc;
        *tevdesc = tdesc;
    }

    *texp_list = HSD_TExpFreeList(*texp_list, HSD_TE_TEV, 1);
    *texp_list = HSD_TExpFreeList(*texp_list, HSD_TE_CNST, 0);
    return num;
}

void HSD_TExpFreeTevDesc(HSD_TExpTevDesc* tdesc)
{
    HSD_TExpTevDesc* next = tdesc;
    while (next != NULL) {
        HSD_TExpTevDesc* temp = (HSD_TExpTevDesc*) next->desc.next;
        hsdFreeMemPiece(next, sizeof(HSD_TExpTevDesc));
        next = temp;
    }
}

int assign_reg(int num, u32* unused, HSD_TExpDag* list, int* order)
{
    u8 color_refs[4] = { 0 };
    u8 alpha_refs[4] = { 0 };
    HSD_TETev* tev;
    HSD_TExpDag* dag_entry;
    int idx;
    int i;
    int min_color_reg = 4;
    int min_alpha_reg = 4;
    int alpha_ref_count;

    for (idx = num - 1; idx >= 0; idx--) {
        dag_entry = &list[order[idx]];
        tev = dag_entry->tev;

        for (i = 0; i < 4; i++) {
            if (HSD_TExpGetType(tev->c_in[i].exp) == HSD_TE_TEV) {
                if (tev->c_in[i].sel == 1) {
                    color_refs[tev->c_in[i].exp->tev.c_dst] -= 1;
                } else {
                    alpha_refs[tev->c_in[i].exp->tev.a_dst] -= 1;
                }
            }
            if (HSD_TExpGetType(tev->a_in[i].exp) == HSD_TE_TEV) {
                alpha_refs[tev->a_in[i].exp->tev.a_dst] -= 1;
            }
        }

        tev = dag_entry->tev;
        if (tev->c_ref > 0) {
            for (i = 3; i >= 0; i--) {
                if (color_refs[i] == 0) {
                    color_refs[i] = tev->c_ref;
                    tev->c_dst = i;
                    if (min_color_reg > i) {
                        min_color_reg = i;
                    }
                    break;
                }
            }
        }
        alpha_ref_count = tev->a_ref;
        if (alpha_ref_count > 0) {
            for (i = 3; i >= 0; i--) {
                if (alpha_refs[i] == 0) {
                    alpha_refs[i] = alpha_ref_count;
                    tev->a_dst = i;
                    if (min_alpha_reg > i) {
                        min_alpha_reg = i;
                    }
                    break;
                }
            }
        }
    }
    return (4 - min_color_reg) + (4 - min_alpha_reg);
}

void order_dag(int num, u32* dep, u32* full_dep, HSD_TExpDag* list, int depth,
              int idx, u32 done_set, u32 ready_set, int* order, int* min,
              int* min_order)
{
    HSD_TExpDag* dag;
    u32 dep_bits;
    u32 blocked;
    u32 full_bits;
    int score;
    int i;

    done_set |= 1 << idx;
    ready_set &= ~(1 << idx);
    order[depth++] = (u8) idx;

    if (depth == num) {
        score = assign_reg(num, dep, list, order);
        if (score < *min) {
            *min = score;
            for (i = 0; i < num; i++) {
                min_order[i] = order[i];
            }
        }
    } else {
        dep_bits = dep[idx];
        blocked = ready_set | dep_bits;
        full_bits = 0;
        for (i = 0; i < num; i++) {
            if (blocked & (1 << i)) {
                full_bits |= full_dep[i];
            }
        }
        dag = &list[idx];
        ready_set = blocked & ~full_bits;
        if (dag->nb_dep == 1 && (ready_set & dep_bits)) {
            order_dag(num, dep, full_dep, list, depth, dag->depend[0]->idx,
                      done_set, ready_set, order, min, min_order);
        } else {
            for (i = 0; i < num; i++) {
                if (ready_set & (1 << i)) {
                    order_dag(num, dep, full_dep, list, depth, i, done_set,
                              ready_set, order, min, min_order);
                }
            }
        }
    }
}

void CalcDistance(HSD_TExp** tevs, int* dist, HSD_TExp* tev, int num,
                  int depth)
{
    HSD_TExp** p;
    int idx;
    int i;

    p = tevs;
    idx = 0;
    for (i = 0; i < num; i++) {
        if (*p == tev) {
            if (dist[idx] < depth) {
                dist[idx] = depth;
                for (i = 0; i < 4; i++) {
                    if (tev->tev.c_in[i].type == 1) {
                        CalcDistance(tevs, dist, tev->tev.c_in[i].exp, num,
                                     depth + 1);
                    }
                    if (tev->tev.a_in[i].type == 1) {
                        CalcDistance(tevs, dist, tev->tev.a_in[i].exp, num,
                                     depth + 1);
                    }
                }
            }
            return;
        }
        p++;
        idx++;
    }
}

#define HSD_TEXP_MAX_NUM 32

int HSD_TExpMakeDag(HSD_TExp* root, HSD_TExpDag* list)
{
    HSD_TExp* sp94[HSD_TEXP_MAX_NUM];
    int sp14[32];
    HSD_TExp** base;
    HSD_TExpDag* dep_entry;
    HSD_TExpDag* dep_entry2;
    int num;
    int j;
    int i;
    int k;
    int l;
    int last;
    int idx;

    TEXP_ASSERT(238, HSD_TExpGetType(root) == HSD_TE_TEV);

    base = &sp94[0];
    num = 0;
    base[num++] = root;
    for (j = 0; j < num; j++) {
        HSD_TExp* tmp;
        TEXP_ASSERT(246, j < HSD_TEXP_MAX_NUM);
        tmp = sp94[j];
        for (i = 0; i < 4; i++) {
            if (tmp->tev.c_in[i].type == HSD_TE_TEV) {
                for (k = 0; k < num; k++) {
                    if (sp94[k] == tmp->tev.c_in[i].exp) {
                        break;
                    }
                }
                if (k >= num) {
                    base[num++] = tmp->tev.c_in[i].exp;
                }
            }
        }

        for (i = 0; i < 4; i++) {
            if (tmp->tev.a_in[i].type == HSD_TE_TEV) {
                for (k = 0; k < num; k++) {
                    if (base[k] == tmp->tev.a_in[i].exp) {
                        break;
                    }
                }
                if (k >= num) {
                    base[num++] = tmp->tev.a_in[i].exp;
                }
            }
        }
    }

    for (j = 0; j < num; j++) {
        sp14[j] = -1;
    }

    CalcDistance(&sp94[0], &sp14[0], sp94[0], num, 0);
    for (idx = 0; idx < num; idx++) {
        for (j = idx + 1; j < num; j++) {
            if (sp14[j - 1] > sp14[j]) {
                {
                    HSD_TExp* tmp = sp94[j - 1];
                    sp94[j - 1] = sp94[j];
                    sp94[j] = tmp;
                }

                {
                    int tmp = sp14[j - 1];
                    sp14[j - 1] = sp14[j];
                    sp14[j] = tmp;
                }
            }
        }
    }

    for (last = num - 1; last >= 0; last--) {
        HSD_TExp* tmp = sp94[last];
        list[last].idx = (u8) last;
        list[last].nb_ref = 0;
        list[last].nb_dep = 0;
        list[last].tev = &tmp->tev;
        for (idx = 0; idx < 4; idx++) {
            if (tmp->tev.c_in[idx].type == HSD_TE_TEV) {
                HSD_TExp** q = &sp94[last];
                for (l = last; l < num; l++) {
                    if (tmp->tev.c_in[idx].exp == *q) {
                        HSD_TExpDag** deps;
                        u8 dep_count;

                        dep_count = list[last].nb_dep;
                        deps = list[last].depend;
                        dep_entry = &list[l];
                        for (l = 0; l < list[last].nb_dep; l++) {
                            if (*deps == dep_entry) {
                                break;
                            }
                            deps++;
                        }
                        if (l >= (int) list[last].nb_dep) {
                            list[last].depend[list[last].nb_dep++] = dep_entry;
                            dep_entry->nb_ref++;
                        }
                        break;
                    }
                    q++;
                }
                TEXP_ASSERT(325, l < num);
            }
        }

        for (idx = 0; idx < 4; idx++) {
            if (tmp->tev.a_in[idx].type == HSD_TE_TEV) {
                HSD_TExp** r2 = &sp94[last];
                for (l = last; l < num; l++) {
                    if (tmp->tev.a_in[i].exp == *r2) {
                        HSD_TExpDag** deps2;
                        u8 dep_count2 = list[last].nb_dep;
                        deps2 = list[last].depend;
                        dep_entry2 = &list[l];
                        (void) dep_entry2;
                        for (l = 0; l < (int) dep_count2; l++) {
                            if (*deps2 == dep_entry2) {
                                break;
                            }
                            deps2++;
                        }
                        if (l >= list[last].nb_dep) {
                            list[last].depend[list[last].nb_dep++] = &list[l];
                            list[l].nb_ref++;
                        }
                        break;
                    }
                    r2++;
                }
                TEXP_ASSERT(347, l < num);
            }
        }
    }
    return num;
}

static inline void make_dependancy_mtx(int num, HSD_TExpDag* list, u32* dep_mtx)
{
    HSD_TExpDag* dag;
    int i, j;

    for (i = 0; i < num; i++) {
        dep_mtx[i] = 0;
        dag = &list[i];
        for (j = 0; j < dag->nb_dep; j++) {
            dep_mtx[i] |= 1 << dag->depend[j]->idx;
        }
    }
}

static inline void make_full_dependancy_mtx(int num, u32* dep, u32* full)
{
    int i, j, k;
    bool changed;
    u32 bits;
    u32 flag;
    u32 old;

    for (i = 0; i < num; i++) {
        full[i] = dep[i];
    }
    do {
        changed = 0;
        for (j = 0; j < num; j++) {
            flag = 1 << j;
            old = full[j];
            bits = old;
            for (k = 0; k < num; k++) {
                if ((flag & full[k]) != 0) {
                    u32 old = full[k];
                    full[k] |= bits;
                    if (old != full[k]) {
                        changed = 1;
                    }
                }
            }
        }
    } while (changed != 0);
}

void HSD_TExpSchedule(int num, HSD_TExpDag* list, HSD_TExp** result,
                      HSD_TExpRes* resource)
{
    static u32 c_in[4] = { GX_CC_C0, GX_CC_C1, GX_CC_C2, GX_CC_CPREV };
    static u32 a_in[4] = { GX_CC_A0, GX_CC_A1, GX_CC_A2, GX_CC_APREV };
    static u32 args[5] = { GX_CA_A0, GX_CA_A1, GX_CA_A2, GX_CA_APREV };

    u32 dep_mtx[32];
    u32 full_dep_matrix[32];
    u32 order[32];
    u32 min_order[32];

    int i, j;
    int min;

    min = 5;
    memset(min_order, 0, sizeof(min_order));
    make_dependancy_mtx(num, list, dep_mtx);
    make_full_dependancy_mtx(num, dep_mtx, full_dep_matrix);
    order_dag(num, dep_mtx, full_dep_matrix, list, 0, 0, 0, 0, (int*) order,
              &min, (int*) min_order);

    for (i = 0; i < num; i++) {
        result[i] = (HSD_TExp*) list[min_order[i]].tev;
        if (result[i]->tev.c_dst != 0xFF) {
            resource->reg[result[i]->tev.c_dst + 4].color = 3;

            for (j = 0; j < 4; j++) {
                if (HSD_TExpGetType(result[i]->tev.c_in[j].exp) == HSD_TE_TEV)
                {
                    if (result[i]->tev.c_in[j].sel == 1) {
                        result[i]->tev.c_in[j].arg =
                            c_in[result[i]->tev.c_in[j].exp->tev.c_dst];
                    } else {
                        result[i]->tev.c_in[j].arg =
                            a_in[result[i]->tev.c_in[j].exp->tev.c_dst];
                    }
                }
            }
        }
        if (result[i]->tev.a_dst != 0xFF) {
            resource->reg[result[i]->tev.a_dst + 4].alpha = 1;

            for (j = 0; j < 4; j++) {
                if (HSD_TExpGetType(result[i]->tev.a_in[j].exp) == HSD_TE_TEV)
                {
                    result[i]->tev.a_in[j].arg =
                        args[result[i]->tev.a_in[j].exp->tev.a_dst];
                }
            }
        }
    }
}

static HSD_TEArg lbl_zero_arg = { 0x00, 0x07, 0xFF };

int SimplifySrc(HSD_TExp* arg0)
{
    int i;
    bool result;

    result = 0;
    i = 0;

    for (; i < 4; i++) {
        if (arg0->tev.c_in[i].type == HSD_TE_TEV) {
            HSD_TExp* src = arg0->tev.c_in[i].exp;
            u8 sel = arg0->tev.c_in[i].sel;
            if (HSD_TExpSimplify(src) != 0) {
                result = 1;
            }
            if (sel == HSD_TE_RGB) {
                switch (src->tev.c_op) {
                case 0xFF:
                    HSD_TExpUnref(src, sel);
                    result = 1;
                    arg0->tev.c_in[i] = lbl_zero_arg;
                    break;
                case GX_TEV_ADD:
                    if (src->tev.c_in[0].sel == HSD_TE_0 &&
                        src->tev.c_in[1].sel == HSD_TE_0 &&
                        src->tev.c_bias == 0 && src->tev.c_scale == 0)
                    {
                        switch (src->tev.c_in[3].type) {
                        case HSD_TE_TEV:
                            if (src->tev.c_in[3].exp->tev.c_clamp != 0 ||
                                src->tev.c_clamp == 0)
                            {
                                arg0->tev.c_in[i] = src->tev.c_in[3];
                                HSD_TExpRef(arg0->tev.c_in[i].exp,
                                            arg0->tev.c_in[i].sel);
                                HSD_TExpUnref(src, sel);
                                result = 1;
                            }
                            break;
                        case HSD_TE_TEX:
                            if ((arg0->tev.tex == NULL ||
                                 arg0->tev.tex == src->tev.tex) &&
                                (arg0->tev.tex_swap == 0xFF ||
                                 src->tev.tex_swap == 0xFF ||
                                 arg0->tev.tex_swap == src->tev.tex_swap))
                            {
                                arg0->tev.c_in[i] = src->tev.c_in[3];
                                arg0->tev.tex = src->tev.tex;
                                if (arg0->tev.tex_swap == 0xFF) {
                                    arg0->tev.tex_swap = src->tev.tex_swap;
                                }
                                HSD_TExpUnref(src, sel);
                                result = 1;
                            }
                            break;
                        case HSD_TE_RAS:
                            if ((arg0->tev.chan == 0xFF ||
                                 arg0->tev.chan == src->tev.chan) &&
                                (arg0->tev.ras_swap == 0xFF ||
                                 src->tev.ras_swap == 0xFF ||
                                 arg0->tev.ras_swap == src->tev.tex_swap))
                            {
                                arg0->tev.c_in[i] = src->tev.c_in[3];
                                arg0->tev.chan = src->tev.chan;
                                if (arg0->tev.tex_swap == 0xFF) {
                                    arg0->tev.tex_swap = src->tev.tex_swap;
                                }
                                HSD_TExpUnref(src, sel);
                                result = 1;
                            }
                            break;
                        }
                    }
                    break;
                }
            } else {
                switch (src->tev.a_op) {
                case GX_TEV_ADD:
                    break;
                case 0xFF:
                    HSD_TExpUnref(src, sel);
                    result = 1;
                    arg0->tev.c_in[i] = lbl_zero_arg;
                    break;
                }
            }
        }
    }

    for (i = 0; i < 4; i++) {
        if (arg0->tev.a_in[i].type == HSD_TE_TEV) {
            HSD_TExp* src = arg0->tev.a_in[i].exp;
            u8 sel = arg0->tev.a_in[i].sel;
            HSD_TExpSimplify(src);
            switch (src->tev.a_op) {
            case 0xFF:
                HSD_TExpUnref(src, sel);
                result = 1;
                arg0->tev.a_in[i] = lbl_zero_arg;
                break;
            case GX_TEV_ADD:
                if (src->tev.a_in[0].sel == HSD_TE_0 &&
                    src->tev.a_in[1].sel == HSD_TE_0 && src->tev.a_bias == 0 &&
                    src->tev.a_scale == 0)
                {
                    switch (src->tev.a_in[3].type) {
                    case HSD_TE_TEV:
                        arg0->tev.a_in[i] = src->tev.a_in[3];
                        HSD_TExpRef(arg0->tev.a_in[i].exp,
                                    arg0->tev.a_in[i].sel);
                        HSD_TExpUnref(src, sel);
                        result = 1;
                        break;
                    case HSD_TE_TEX:
                        if (arg0->tev.tex == NULL ||
                            arg0->tev.tex == src->tev.tex)
                        {
                            arg0->tev.a_in[i] = src->tev.a_in[3];
                            arg0->tev.tex = src->tev.tex;
                            HSD_TExpUnref(src, sel);
                            result = 1;
                        }
                        break;
                    case HSD_TE_RAS:
                        if (arg0->tev.chan == 0xFF ||
                            arg0->tev.chan == src->tev.chan)
                        {
                            arg0->tev.a_in[i] = src->tev.a_in[3];
                            arg0->tev.chan = src->tev.chan;
                            HSD_TExpUnref(src, sel);
                            result = 1;
                        }
                        break;
                    }
                }
                break;
            }
        }
    }
    return result;
}

#define CLEAR_ARG(arg)                                                       \
    do {                                                                     \
        (arg) = lbl_zero_arg;                                                \
    } while (0)

int SimplifyThis(HSD_TExp* arg0)
{
    int color_tex;
    int alpha_tex;
    int color_ras;
    int alpha_ras;
    int result;
    int changed;
    int i;

    result = 0;
    do {
        color_tex = -1;
        alpha_tex = -1;
        color_ras = -1;
        alpha_ras = -1;

        for (i = 0; i < 4; i++) {
            switch (arg0->tev.c_in[i].type) {
            case HSD_TE_TEX:
                color_tex = i;
                break;
            case HSD_TE_RAS:
                color_ras = i;
                break;
            }
            switch (arg0->tev.a_in[i].type) {
            case HSD_TE_TEX:
                alpha_tex = i;
                break;
            case HSD_TE_RAS:
                alpha_ras = i;
                break;
            }
        }

        if (color_tex == -1 && alpha_tex == -1) {
            arg0->tev.tex = NULL;
            arg0->tev.tex_swap = 0xFF;
        }
        if (color_ras == -1 && alpha_ras == -1) {
            arg0->tev.chan = 0xFF;
            arg0->tev.ras_swap = 0xFF;
        }

        changed = 0;
        if (arg0->tev.a_op == 0xFF || arg0->tev.a_op == 0xE ||
            arg0->tev.a_op == 0xF || arg0->tev.a_op <= 1)
        {
            if (arg0->tev.c_op != 0xFF && arg0->tev.c_ref == 0) {
                arg0->tev.c_op = 0xFF;
                for (i = 0; i < 4; i++) {
                    HSD_TExpUnref(arg0->tev.c_in[i].exp,
                                  arg0->tev.c_in[i].sel);
                    arg0->tev.c_in[i] = lbl_zero_arg;
                }
                changed = 1;
            }

            switch (arg0->tev.c_op) {
            case 0:
            case 1:
                if (arg0->tev.c_in[2].sel == HSD_TE_0) {
                    if (arg0->tev.c_in[1].sel != HSD_TE_0) {
                        HSD_TExpUnref(arg0->tev.c_in[1].exp,
                                      arg0->tev.c_in[1].sel);
                        changed = 1;
                        CLEAR_ARG(arg0->tev.c_in[1]);
                    }
                    if (arg0->tev.c_op == 0 &&
                        arg0->tev.c_in[3].sel == HSD_TE_0)
                    {
                        changed = 1;
                        arg0->tev.c_in[3] = arg0->tev.c_in[0];
                        CLEAR_ARG(arg0->tev.c_in[0]);
                        arg0->tev.c_clamp = 1;
                    }
                }
                if (arg0->tev.c_in[2].sel == HSD_TE_1) {
                    if (arg0->tev.c_in[0].sel != HSD_TE_0) {
                        HSD_TExpUnref(arg0->tev.c_in[0].exp,
                                      arg0->tev.c_in[0].sel);
                        changed = 1;
                        CLEAR_ARG(arg0->tev.c_in[0]);
                    }
                    if (arg0->tev.c_op == 0 &&
                        arg0->tev.c_in[3].sel == HSD_TE_0)
                    {
                        changed = 1;
                        arg0->tev.c_in[3] = arg0->tev.c_in[1];
                        CLEAR_ARG(arg0->tev.c_in[1]);
                        CLEAR_ARG(arg0->tev.c_in[2]);
                    }
                }
                if (arg0->tev.c_in[0].sel == HSD_TE_0 &&
                    arg0->tev.c_in[1].sel == HSD_TE_0 &&
                    arg0->tev.c_in[3].sel == HSD_TE_0 && arg0->tev.c_bias == 0)
                {
                    arg0->tev.c_op = 0xFF;
                    HSD_TExpUnref(arg0->tev.c_in[2].exp,
                                  arg0->tev.c_in[2].sel);
                    changed = 1;
                    CLEAR_ARG(arg0->tev.c_in[2]);
                }
                break;
            case 8:
            case 10:
            case 12:
            case 14:
                if (arg0->tev.c_in[2].sel == HSD_TE_0) {
                    arg0->tev.c_op = 0;
                    HSD_TExpUnref(arg0->tev.c_in[0].exp,
                                  arg0->tev.c_in[0].sel);
                    CLEAR_ARG(arg0->tev.c_in[0]);
                    HSD_TExpUnref(arg0->tev.c_in[1].exp,
                                  arg0->tev.c_in[1].sel);
                    changed = 1;
                    CLEAR_ARG(arg0->tev.c_in[1]);
                } else if (arg0->tev.c_in[0].sel == HSD_TE_0) {
                    arg0->tev.c_op = 0;
                    HSD_TExpUnref(arg0->tev.c_in[1].exp,
                                  arg0->tev.c_in[1].sel);
                    CLEAR_ARG(arg0->tev.c_in[1]);
                    HSD_TExpUnref(arg0->tev.c_in[2].exp,
                                  arg0->tev.c_in[2].sel);
                    changed = 1;
                    CLEAR_ARG(arg0->tev.c_in[2]);
                }
                break;
            case 9:
            case 11:
            case 13:
            case 15:
                if (arg0->tev.c_in[2].sel == HSD_TE_0) {
                    arg0->tev.c_op = 0;
                    HSD_TExpUnref(arg0->tev.c_in[0].exp,
                                  arg0->tev.c_in[0].sel);
                    CLEAR_ARG(arg0->tev.c_in[0]);
                    HSD_TExpUnref(arg0->tev.c_in[1].exp,
                                  arg0->tev.c_in[1].sel);
                    changed = 1;
                    CLEAR_ARG(arg0->tev.c_in[1]);
                } else if (arg0->tev.c_in[0].sel == HSD_TE_0 &&
                           arg0->tev.c_in[1].sel == HSD_TE_0)
                {
                    arg0->tev.c_op = 0;
                    changed = 1;
                    arg0->tev.c_in[0] = arg0->tev.c_in[2];
                    CLEAR_ARG(arg0->tev.c_in[2]);
                }
                break;
            }
        }

        if (arg0->tev.a_op != 0xFF && arg0->tev.a_ref == 0) {
            arg0->tev.a_op = 0xFF;
            for (i = 0; i < 4; i++) {
                HSD_TExpUnref(arg0->tev.a_in[i].exp, arg0->tev.a_in[i].sel);
                CLEAR_ARG(arg0->tev.a_in[i]);
            }
            changed = 1;
        }

        switch (arg0->tev.a_op) {
        case 0:
        case 1:
            if (arg0->tev.a_in[2].sel == HSD_TE_0) {
                if (arg0->tev.a_in[1].sel != HSD_TE_0) {
                    HSD_TExpUnref(arg0->tev.a_in[1].exp,
                                  arg0->tev.a_in[1].sel);
                    changed = 1;
                    CLEAR_ARG(arg0->tev.a_in[1]);
                }
                if (arg0->tev.a_op == 0 && arg0->tev.a_in[3].sel == HSD_TE_0) {
                    changed = 1;
                    arg0->tev.a_in[3] = arg0->tev.a_in[0];
                    CLEAR_ARG(arg0->tev.a_in[0]);
                }
            }
            if (arg0->tev.a_in[2].sel == HSD_TE_1) {
                if (arg0->tev.a_in[0].sel != HSD_TE_0) {
                    HSD_TExpUnref(arg0->tev.a_in[0].exp,
                                  arg0->tev.a_in[0].sel);
                    changed = 1;
                    CLEAR_ARG(arg0->tev.a_in[0]);
                }
                if (arg0->tev.a_op == 0 && arg0->tev.a_in[3].sel == HSD_TE_0) {
                    changed = 1;
                    arg0->tev.a_in[3] = arg0->tev.a_in[1];
                    CLEAR_ARG(arg0->tev.a_in[1]);
                    CLEAR_ARG(arg0->tev.a_in[2]);
                }
            }
            if (arg0->tev.a_in[0].sel == HSD_TE_0 &&
                arg0->tev.a_in[1].sel == HSD_TE_0 &&
                arg0->tev.a_in[3].sel == HSD_TE_0)
            {
                arg0->tev.a_op = 0xFF;
                changed = 1;
            }
            break;

        case 8:
        case 9:
        case 0xA:
        case 0xB:
        case 0xC:
        case 0xD:
            if (arg0->tev.a_in[2].sel == HSD_TE_0) {
                arg0->tev.a_op = 0;
                HSD_TExpUnref(arg0->tev.a_in[0].exp, arg0->tev.a_in[0].sel);
                CLEAR_ARG(arg0->tev.a_in[0]);
                HSD_TExpUnref(arg0->tev.a_in[1].exp, arg0->tev.a_in[1].sel);
                changed = 1;
                CLEAR_ARG(arg0->tev.a_in[1]);
            }
            break;

        case 0xE:
            if (arg0->tev.a_in[2].sel == HSD_TE_0) {
                arg0->tev.a_op = 0;
                HSD_TExpUnref(arg0->tev.a_in[0].exp, arg0->tev.a_in[0].sel);
                CLEAR_ARG(arg0->tev.a_in[0]);
                HSD_TExpUnref(arg0->tev.a_in[1].exp, arg0->tev.a_in[1].sel);
                changed = 1;
                CLEAR_ARG(arg0->tev.a_in[1]);
            } else if (arg0->tev.a_in[0].sel == HSD_TE_0) {
                arg0->tev.a_op = 0;
                HSD_TExpUnref(arg0->tev.a_in[1].exp, arg0->tev.a_in[1].sel);
                CLEAR_ARG(arg0->tev.a_in[1]);
                HSD_TExpUnref(arg0->tev.a_in[2].exp, arg0->tev.a_in[2].sel);
                changed = 1;
                CLEAR_ARG(arg0->tev.a_in[2]);
            }
            break;

        case 0xF:
            if (arg0->tev.a_in[2].sel == HSD_TE_0) {
                arg0->tev.a_op = 0;
                HSD_TExpUnref(arg0->tev.a_in[0].exp, arg0->tev.a_in[0].sel);
                CLEAR_ARG(arg0->tev.a_in[0]);
                HSD_TExpUnref(arg0->tev.a_in[1].exp, arg0->tev.a_in[1].sel);
                changed = 1;
                CLEAR_ARG(arg0->tev.a_in[1]);
            } else if (arg0->tev.a_in[0].sel == HSD_TE_0 &&
                       arg0->tev.a_in[1].sel == HSD_TE_0)
            {
                arg0->tev.a_op = 0;
                changed = 1;
                arg0->tev.a_in[0] = arg0->tev.a_in[2];
                CLEAR_ARG(arg0->tev.a_in[2]);
            }
            break;
        }

        if (changed != 0) {
            result = 1;
        }
    } while (changed != 0);

    return result;
}

int SimplifyByMerge(HSD_TExp* arg0)
{
    HSD_TExp* child;
    int bias;
    int result;
    int merged;
    int i;
    int conflict;
    u8 type;
    u8 child_sel;
    u8 new_op;
    HSD_TEArg tmp_arg;

    result = 0;
    do {
        merged = 0;

        if (arg0->tev.a_op == 0xFF || arg0->tev.a_op == 0xE ||
            arg0->tev.a_op == 0xF || arg0->tev.a_op <= 1)
        {
            if ((arg0->tev.c_op == 0 || arg0->tev.c_op == 1) &&
                arg0->tev.c_in[1].sel == HSD_TE_0 &&
                arg0->tev.c_in[2].sel == HSD_TE_0 &&
                HSD_TExpGetType(arg0->tev.c_in[0].exp) != HSD_TE_CNST &&
                HSD_TExpGetType(arg0->tev.c_in[3].exp) != HSD_TE_CNST)
            {
                if (arg0->tev.c_op == 0 &&
                    arg0->tev.c_in[3].type == HSD_TE_TEV &&
                    ((arg0->tev.c_in[3].sel == HSD_TE_RGB &&
                      arg0->tev.c_in[3].exp->tev.c_clamp != 0) ||
                     (arg0->tev.c_in[3].sel == HSD_TE_A &&
                      arg0->tev.c_in[3].exp->tev.a_clamp != 0)))
                {
                    type = arg0->tev.c_in[0].type;
                    switch (type) {
                    case HSD_TE_TEX:
                    case HSD_TE_RAS:
                        tmp_arg = arg0->tev.c_in[0];
                        arg0->tev.c_in[0] = arg0->tev.c_in[3];
                        arg0->tev.c_in[3] = tmp_arg;
                        break;
                    }
                }

                switch (arg0->tev.c_in[0].type) {
                case HSD_TE_TEV:
                    if (arg0->tev.c_in[0].sel == HSD_TE_RGB) {
                        child = arg0->tev.c_in[0].exp;
                        child_sel = arg0->tev.c_in[0].sel;
                        if ((child->tev.c_op == 0 || child->tev.c_op == 1) &&
                            child->tev.c_in[3].sel == HSD_TE_0 &&
                            child->tev.c_scale == 0)
                        {
                            if (arg0->tev.tex != NULL &&
                                child->tev.tex != NULL &&
                                arg0->tev.tex != child->tev.tex)
                            {
                                conflict = 1;
                            } else if (arg0->tev.chan != 0xFF &&
                                       child->tev.chan != 0xFF &&
                                       arg0->tev.chan != child->tev.chan)
                            {
                                conflict = 1;
                            } else {
                                conflict = 0;
                            }
                            if (conflict == 0) {
                                switch ((s32) child->tev.c_bias) {
                                case 1:
                                    bias = 1;
                                    break;
                                case 2:
                                    bias = -1;
                                    break;
                                default:
                                    bias = 0;
                                    break;
                                }
                                if (child->tev.c_op == 1) {
                                    bias = -bias;
                                }
                                switch ((s32) arg0->tev.c_bias) {
                                case 1:
                                    bias += 1;
                                    break;
                                case 2:
                                    bias -= 1;
                                    break;
                                }
                                switch (bias) {
                                case 0:
                                    arg0->tev.c_bias = 0;
                                    merged = 1;
                                    break;
                                case 1:
                                    arg0->tev.c_bias = 1;
                                    merged = 1;
                                    break;
                                case -1:
                                    arg0->tev.c_bias = 2;
                                    merged = 1;
                                    break;
                                default:
                                    merged = 0;
                                    break;
                                }
                                if (merged != 0) {
                                    if (child->tev.c_op == 1) {
                                        if (arg0->tev.c_op == 0) {
                                            new_op = 1;
                                        } else {
                                            new_op = 0;
                                        }
                                        arg0->tev.c_op = new_op;
                                    }
                                    for (i = 0; i < 3; i++) {
                                        arg0->tev.c_in[i] = child->tev.c_in[i];
                                        HSD_TExpRef(arg0->tev.c_in[i].exp,
                                                    arg0->tev.c_in[i].sel);
                                    }
                                    if (arg0->tev.tex == NULL) {
                                        arg0->tev.tex = child->tev.tex;
                                    }
                                    if (arg0->tev.chan == 0xFF) {
                                        arg0->tev.chan = child->tev.chan;
                                    }
                                    if (arg0->tev.tex_swap == 0xFF) {
                                        arg0->tev.tex_swap =
                                            child->tev.tex_swap;
                                    }
                                    if (arg0->tev.ras_swap == 0xFF) {
                                        arg0->tev.ras_swap =
                                            child->tev.ras_swap;
                                    }
                                    HSD_TExpUnref(child, child_sel);
                                }
                            }
                        }
                    }
                    break;
                case HSD_TE_ZERO:
                    if (arg0->tev.c_in[3].type == HSD_TE_TEV) {
                        child_sel = arg0->tev.c_in[3].sel;
                        if (child_sel == HSD_TE_RGB) {
                            child = arg0->tev.c_in[3].exp;
                            if (child->tev.c_scale == 0 &&
                                (arg0->tev.c_bias == 0 ||
                                 arg0->tev.c_bias != child->tev.c_bias))
                            {
                                if (arg0->tev.tex != NULL &&
                                    child->tev.tex != NULL &&
                                    arg0->tev.tex != child->tev.tex)
                                {
                                    conflict = 1;
                                } else if (arg0->tev.chan != 0xFF &&
                                           child->tev.chan != 0xFF &&
                                           arg0->tev.chan != child->tev.chan)
                                {
                                    conflict = 1;
                                } else {
                                    conflict = 0;
                                }
                                if (conflict == 0) {
                                    merged = 1;
                                    for (i = 0; i < 4; i++) {
                                        arg0->tev.c_in[i] = child->tev.c_in[i];
                                        HSD_TExpRef(arg0->tev.c_in[i].exp,
                                                    arg0->tev.c_in[i].sel);
                                    }
                                    arg0->tev.c_op = child->tev.c_op;
                                    switch ((s32) child->tev.c_bias) {
                                    case 1:
                                        bias = 1;
                                        break;
                                    case 2:
                                        bias = -1;
                                        break;
                                    default:
                                        bias = 0;
                                        break;
                                    }
                                    if (child->tev.c_op == 1) {
                                        bias = -bias;
                                    }
                                    switch ((s32) arg0->tev.c_bias) {
                                    case 1:
                                        bias += 1;
                                        break;
                                    case 2:
                                        bias -= 1;
                                        break;
                                    }
                                    switch (bias) {
                                    case 1:
                                        arg0->tev.c_bias = 1;
                                        break;
                                    case -1:
                                        arg0->tev.c_bias = 2;
                                        break;
                                    default:
                                    case 0:
                                        arg0->tev.c_bias = 0;
                                        break;
                                    }
                                    if (arg0->tev.c_clamp == 0xFF ||
                                        arg0->tev.c_clamp == 0)
                                    {
                                        arg0->tev.c_clamp = child->tev.c_clamp;
                                    }
                                    if (arg0->tev.tex == NULL) {
                                        arg0->tev.tex = child->tev.tex;
                                    }
                                    if (arg0->tev.chan == 0xFF) {
                                        arg0->tev.chan = child->tev.chan;
                                    }
                                    if (arg0->tev.tex_swap == 0xFF) {
                                        arg0->tev.tex_swap =
                                            child->tev.tex_swap;
                                    }
                                    if (arg0->tev.ras_swap == 0xFF) {
                                        arg0->tev.ras_swap =
                                            child->tev.ras_swap;
                                    }
                                    HSD_TExpUnref(child, child_sel);
                                }
                            }
                        }
                    }
                    break;
                }
            }

            if ((arg0->tev.a_op == 0 || arg0->tev.a_op == 1) &&
                arg0->tev.a_in[1].sel == HSD_TE_0 &&
                arg0->tev.a_in[2].sel == HSD_TE_0 &&
                HSD_TExpGetType(arg0->tev.a_in[0].exp) != HSD_TE_CNST &&
                HSD_TExpGetType(arg0->tev.a_in[3].exp) != HSD_TE_CNST)
            {
                if (arg0->tev.a_op == 0 &&
                    arg0->tev.a_in[3].type == HSD_TE_TEV &&
                    arg0->tev.a_in[3].exp->tev.a_clamp != 0)
                {
                    type = arg0->tev.a_in[0].type;
                    switch ((s32) type) {
                    case HSD_TE_TEX:
                    case HSD_TE_RAS:
                        tmp_arg = arg0->tev.a_in[0];
                        arg0->tev.a_in[0] = arg0->tev.a_in[3];
                        arg0->tev.a_in[3] = tmp_arg;
                        break;
                    }
                }

                switch (arg0->tev.a_in[0].type) {
                case HSD_TE_TEV:
                    child = arg0->tev.a_in[0].exp;
                    child_sel = arg0->tev.a_in[0].sel;
                    if ((child->tev.a_op == 0 || child->tev.a_op == 1) &&
                        child->tev.a_in[3].sel == HSD_TE_0 &&
                        child->tev.a_scale == 0)
                    {
                        if (arg0->tev.tex != NULL && child->tev.tex != NULL &&
                            arg0->tev.tex != child->tev.tex)
                        {
                            conflict = 1;
                        } else if (arg0->tev.chan != 0xFF &&
                                   child->tev.chan != 0xFF &&
                                   arg0->tev.chan != child->tev.chan)
                        {
                            conflict = 1;
                        } else {
                            conflict = 0;
                        }
                        if (conflict == 0) {
                            switch ((s32) child->tev.a_bias) {
                            case 1:
                                bias = 1;
                                break;
                            case 2:
                                bias = -1;
                                break;
                            default:
                                bias = 0;
                                break;
                            }
                            if (child->tev.a_op == 1) {
                                bias = -bias;
                            }
                            switch ((s32) arg0->tev.a_bias) {
                            case 1:
                                bias += 1;
                                break;
                            case 2:
                                bias -= 1;
                                break;
                            }
                            switch (bias) {
                            case 0:
                                arg0->tev.a_bias = 0;
                                merged = 1;
                                break;
                            case 1:
                                arg0->tev.a_bias = 1;
                                merged = 1;
                                break;
                            case -1:
                                arg0->tev.a_bias = 2;
                                merged = 1;
                                break;
                            default:
                                merged = 0;
                                break;
                            }
                            if (merged != 0) {
                                if (child->tev.a_op == 1) {
                                    if (arg0->tev.a_op == 0) {
                                        new_op = 1;
                                    } else {
                                        new_op = 0;
                                    }
                                    arg0->tev.a_op = new_op;
                                }
                                for (i = 0; i < 3; i++) {
                                    arg0->tev.a_in[i] = child->tev.a_in[i];
                                    HSD_TExpRef(arg0->tev.a_in[i].exp,
                                                arg0->tev.a_in[i].sel);
                                }
                                if (arg0->tev.tex == NULL) {
                                    arg0->tev.tex = child->tev.tex;
                                }
                                if (arg0->tev.chan == 0xFF) {
                                    arg0->tev.chan = child->tev.chan;
                                }
                                HSD_TExpUnref(child, child_sel);
                            }
                        }
                    }
                    break;
                case HSD_TE_ZERO:
                    if (arg0->tev.a_in[3].type == HSD_TE_TEV) {
                        child = arg0->tev.a_in[3].exp;
                        child_sel = arg0->tev.a_in[3].sel;
                        if (child->tev.a_scale == 0 &&
                            (arg0->tev.a_bias == 0 ||
                             arg0->tev.a_bias != child->tev.a_bias))
                        {
                            if (arg0->tev.tex != NULL &&
                                child->tev.tex != NULL &&
                                arg0->tev.tex != child->tev.tex)
                            {
                                conflict = 1;
                            } else if (arg0->tev.chan != 0xFF &&
                                       child->tev.chan != 0xFF &&
                                       arg0->tev.chan != child->tev.chan)
                            {
                                conflict = 1;
                            } else {
                                conflict = 0;
                            }
                            if (conflict == 0) {
                                merged = 1;
                                for (i = 0; i < 4; i++) {
                                    arg0->tev.a_in[i] = child->tev.a_in[i];
                                    HSD_TExpRef(arg0->tev.a_in[i].exp,
                                                arg0->tev.a_in[i].sel);
                                }
                                arg0->tev.a_op = child->tev.a_op;
                                switch ((s32) child->tev.a_bias) {
                                case 1:
                                    bias = 1;
                                    break;
                                case 2:
                                    bias = -1;
                                    break;
                                default:
                                    bias = 0;
                                    break;
                                }
                                if (child->tev.a_op == 1) {
                                    bias = -bias;
                                }
                                switch ((s32) arg0->tev.a_bias) {
                                case 1:
                                    bias += 1;
                                    break;
                                case 2:
                                    bias -= 1;
                                    break;
                                }
                                switch (bias) {
                                case 1:
                                    arg0->tev.a_bias = 1;
                                    break;
                                case -1:
                                    arg0->tev.a_bias = 2;
                                    break;
                                default:
                                case 0:
                                    arg0->tev.a_bias = 0;
                                    break;
                                }
                                if (arg0->tev.a_clamp == 0xFF ||
                                    arg0->tev.a_clamp == 0)
                                {
                                    arg0->tev.a_clamp = child->tev.a_clamp;
                                }
                                if (arg0->tev.tex == NULL) {
                                    arg0->tev.tex = child->tev.tex;
                                }
                                if (arg0->tev.chan == 0xFF) {
                                    arg0->tev.chan = child->tev.chan;
                                }
                                HSD_TExpUnref(child, child_sel);
                            }
                        }
                    }
                    break;
                }
            }
        }

        if (merged != 0) {
            result = 1;
        }
    } while (merged != 0);

    return result;
}

void CalcTevRange(HSD_TExp* texp)
{
    HSD_TETev* tev = &texp->tev;
    s32 range;

    if (tev->c_in[3].sel == HSD_TE_0) {
        range = 0;
    } else if (HSD_TExpGetType(tev->c_in[3].exp) == HSD_TE_TEV) {
        if (tev->c_in[3].sel == HSD_TE_RGB) {
            if (tev->c_in[3].exp->tev.c_clamp == 1) {
                range = 0x100;
            } else if (tev->c_in[3].exp->tev.c_range == 1) {
                tev->c_range = 1;
                goto alpha;
            } else {
                range = 0x100;
            }
        } else {
            if (tev->c_in[3].exp->tev.a_clamp == 1) {
                range = 0x100;
            } else if (tev->c_in[3].exp->tev.a_range == 1) {
                tev->c_range = 1;
                goto alpha;
            } else {
                range = 0x100;
            }
        }
    } else {
        range = 0x100;
    }

    {
        s32 i;
        for (i = 0; i < 3; i++) {
            if (tev->c_in[i].sel != HSD_TE_0) {
                if (tev->c_op == GX_TEV_SUB) {
                    tev->c_range = 1;
                    goto alpha;
                }
                range += 0x100;
                break;
            }
        }
    }

    if (tev->c_bias == GX_TB_SUBHALF) {
        tev->c_range = 1;
        goto alpha;
    } else if (tev->c_bias == GX_TB_ADDHALF) {
        range += 0x80;
    }

    switch (tev->c_scale) {
    case GX_CS_SCALE_4:
        range <<= 2;
        break;
    case GX_CS_SCALE_2:
        range <<= 1;
        break;
    case GX_CS_DIVIDE_2:
        range /= 2;
        break;
    }
    tev->c_range = (range > 0x100);

alpha:
    if (tev->a_in[3].sel == HSD_TE_0) {
        range = 0;
    } else if (HSD_TExpGetType(tev->a_in[3].exp) == HSD_TE_TEV) {
        if (tev->a_in[3].exp->tev.a_clamp == 1) {
            range = 0x100;
        } else if (tev->a_in[3].exp->tev.a_range == 1) {
            tev->a_range = 1;
            return;
        } else {
            range = 0x100;
        }
    } else {
        range = 0x100;
    }

    {
        s32 i;
        for (i = 0; i < 3; i++) {
            if (tev->a_in[i].sel != HSD_TE_0) {
                if (tev->a_op == GX_TEV_SUB) {
                    tev->a_range = 1;
                    return;
                }
                range += 0x100;
                break;
            }
        }
    }

    if (tev->a_bias == GX_TB_SUBHALF) {
        tev->a_range = 1;
        return;
    } else if (tev->a_bias == GX_TB_ADDHALF) {
        range += 0x80;
    }

    switch (tev->a_scale) {
    case GX_CS_SCALE_4:
        range <<= 2;
        break;
    case GX_CS_SCALE_2:
        range <<= 1;
        break;
    case GX_CS_DIVIDE_2:
        range /= 2;
        break;
    }
    tev->a_range = (range > 0x100);
}

int HSD_TExpSimplify(HSD_TExp* texp_)
{
    HSD_TExp* texp = texp_;
    int res = 0;
    if (HSD_TExpGetType(texp) != HSD_TE_TEV) {
        return 0;
    }
    if (SimplifySrc(texp) != 0) {
        res = 1;
    }
    if (SimplifyThis(texp) != 0) {
        res = 1;
    }
    if (SimplifyByMerge(texp) != 0) {
        res = 1;
    }
    CalcTevRange(texp);
    return res;
}

int HSD_TExpSimplify2(HSD_TExp* texp_)
{
    HSD_TExp* texp = (HSD_TExp*) texp_;
    HSD_TExp* src_exp;
    u8 src_sel;
    int i;

    for (i = 0; i < 4; i++) {
        src_exp = texp->tev.c_in[i].exp;
        src_sel = texp->tev.c_in[i].sel;
        if (texp->tev.c_in[i].type == HSD_TE_TEV && src_sel == 1 &&
            IsThroughColor(src_exp))
        {
            switch (src_exp->tev.c_in[3].type) {
            case HSD_TE_KONST:
                if (texp->tev.kcsel == 0xFF) {
                    texp->tev.kcsel = src_exp->tev.kcsel;
                } else if (texp->tev.kcsel != src_exp->tev.kcsel) {
                    break;
                }
                /* fallthrough */
            case HSD_TE_IMM:
                texp->tev.c_in[i] = src_exp->tev.c_in[3];
                HSD_TExpRef(texp->tev.c_in[i].exp, texp->tev.c_in[i].sel);
                HSD_TExpUnref(src_exp, src_sel);
                break;
            }
        }
    }
    for (i = 0; i < 4; i++) {
        src_exp = texp->tev.a_in[i].exp;
        src_sel = texp->tev.a_in[i].sel;
        if (texp->tev.a_in[i].type == HSD_TE_TEV && IsThroughAlpha(src_exp)) {
            switch (src_exp->tev.a_in[3].type) {
            case HSD_TE_KONST:
                if (texp->tev.kasel == 0xFF) {
                    texp->tev.kasel = src_exp->tev.kasel;
                } else if (texp->tev.kasel != src_exp->tev.kasel) {
                    break;
                }
                /* fallthrough */
            case HSD_TE_IMM:
                texp->tev.a_in[i] = src_exp->tev.a_in[3];
                HSD_TExpRef(texp->tev.a_in[i].exp, texp->tev.a_in[i].sel);
                HSD_TExpUnref(src_exp, src_sel);
                break;
            }
        }
    }
    return 0;
}
