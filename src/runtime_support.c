#include "dolphin/types.h"

typedef void (*Destructor)(void*, int);

typedef struct DestructorChain {
    struct DestructorChain* next;
    Destructor destructor;
    void* object;
} DestructorChain;

extern DestructorChain* __global_destructor_chain;

void __register_global_object(void* object, Destructor destructor,
                               DestructorChain* chain)
{
    chain->next = __global_destructor_chain;
    chain->destructor = destructor;
    chain->object = object;
    __global_destructor_chain = chain;
}

extern const char lbl_8048B5A8[];

const char* fn_803AD23C(void)
{
    return lbl_8048B5A8;
}

#pragma exceptions on

void __destroy_arr(void* array, Destructor dtor, unsigned long elem_size,
                    unsigned long count)
{
    char* p = (char*)array + elem_size * count;
    while (count != 0) {
        p -= elem_size;
        dtor(p, -1);
        count--;
    }
}

typedef struct ArrayCookie {
    void* array;
    unsigned long elem_size;
    unsigned long count;
    Destructor dtor;
    unsigned long constructed;
} ArrayCookie;

void __construct_array(void* array, Destructor ctor, Destructor dtor,
                        unsigned long elem_size, unsigned long count)
{
    volatile ArrayCookie cookie;
    char* p = (char*)array;

    cookie.array = array;
    cookie.elem_size = elem_size;
    cookie.count = count;
    cookie.dtor = dtor;
    cookie.constructed = 0;

    while (cookie.constructed < count) {
        ctor(p, 1);
        p += elem_size;
        cookie.constructed++;
    }

    if (cookie.constructed < cookie.count && cookie.dtor != 0) {
        p = (char*)cookie.array + cookie.elem_size * cookie.constructed;
        while (cookie.constructed != 0) {
            p -= cookie.elem_size;
            cookie.dtor(p, -1);
            cookie.constructed--;
        }
    }
}

extern void fn_8038CB78(void*);

void* dtor_803AD3BC(ArrayCookie* this_, short flag)
{
    char* p;

    if (this_ != 0) {
        if (this_->constructed < this_->count && this_->dtor != 0) {
            p = (char*)this_->array + this_->elem_size * this_->constructed;
            while (this_->constructed != 0) {
                p -= this_->elem_size;
                this_->dtor(p, -1);
                this_->constructed--;
            }
        }
        if (flag > 0) {
            fn_8038CB78(this_);
        }
    }
    return this_;
}

#pragma exceptions reset

extern const char lbl_8048B5B8[];

BOOL __throw_catch_compare(const char* pattern, const char* target, int* dist)
{
    const char* p;
    int n;
    char c1, c2;

    *dist = 0;
    if ((p = target) == 0) {
        return TRUE;
    }

    if (*target == 'P') {
        p++;
        if (*p == 'C') {
            p++;
        }
        if (*p == 'V') {
            p++;
        }
        if (*p == 'v') {
            if (*pattern == 'P' || *pattern == '*') {
                return TRUE;
            }
        }
        p = target;
    }

    switch (*pattern) {
    case '*':
    case '!':
        goto star_case;
    }
    goto general;

star_case:
    {
        c1 = *pattern++;
        c2 = *p++;
        if (c1 != c2) {
            return FALSE;
        }

    compare_loop:
        c2 = *p++;
        c1 = *pattern;
        if (c1 != c2) {
            goto mismatch;
        }
        pattern++;
        if (c1 != '!') {
            goto compare_loop;
        }

        n = 0;
        while (*pattern != '!') {
            n = n * 10 - '0' + *pattern++;
        }
        *dist = n;
        return TRUE;

    mismatch:
        while (*pattern++ != '!') { }
        while (*pattern++ != '!') { }
        if (*pattern == 0) {
            return FALSE;
        }
        p = target + 1;
        goto compare_loop;
    }

general:
    for (;;) {
        c1 = *pattern;
        if (c1 == 'P' || c1 == 'R') {
            if (c1 == *p) {
                p++;
                pattern++;
                if (*p == 'C') {
                    if (*pattern == 'C') {
                        pattern++;
                    }
                    p++;
                }
                if (*pattern == 'C') {
                    return FALSE;
                }
                if (*p == 'V') {
                    if (*pattern == 'V') {
                        pattern++;
                    }
                    p++;
                }
                if (*pattern == 'V') {
                    return FALSE;
                }
                continue;
            }
        }
        break;
    }

    while (*pattern == *p) {
        if (*pattern == 0) {
            return TRUE;
        }
        pattern++;
        p++;
    }
    return FALSE;
}

#pragma exceptions on

extern void (*lbl_805DC85C)(void);

void unexpected(void)
{
    (*lbl_805DC85C)();
}

extern void (*lbl_805DC858)(void);

void terminate(void)
{
    (*lbl_805DC858)();
}

void set_terminate(void)
{
    (*lbl_805DC858)();
}

extern void abort(void);

void dthandler(void)
{
    abort();
}

#pragma exceptions reset

asm void fn_803AD738(void)
{
    nofralloc
    lwz r0, 0(r12)
    lwz r11, 4(r12)
    lwz r12, 8(r12)
    add r3, r3, r0
    cmpwi r11, 0
    blt skip
    lwzx r12, r3, r12
    lwzx r12, r12, r11
skip:
    mtctr r12
    bctr
}

extern const char lbl_8048B5FC[];

const char* fn_803ADA20(void)
{
    return lbl_8048B5FC;
}

extern const double lbl_8048B608[3];

asm unsigned long __cvt_fp2unsigned(register double d)
{
    nofralloc
    stwu    r1, -0x10(r1)
    lis     r4, lbl_8048B608@h
    ori     r4, r4, lbl_8048B608@l
    li      r3, 0
    lfd     f0, 0(r4)
    lfd     f3, 8(r4)
    lfd     f4, 0x10(r4)
    fcmpu   cr0, f1, f0
    fcmpu   cr6, f1, f3
    blt     cr0, exit
    subi    r3, r3, 1
    bge     cr6, exit
    fcmpu   cr7, f1, f4
    fmr     f2, f1
    blt     cr7, L1
    fsub    f2, f1, f4
L1:
    fctiwz  f2, f2
    stfd    f2, 8(r1)
    lwz     r3, 0xc(r1)
    blt     cr7, exit
    addis   r3, r3, 0x8000
exit:
    addi    r1, r1, 0x10
    blr
}

void _savefpr_14(void);
void _savefpr_15(void);
void _savefpr_16(void);
void _savefpr_17(void);
void _savefpr_18(void);
void _savefpr_19(void);
void _savefpr_20(void);
void _savefpr_21(void);
void _savefpr_22(void);
void _savefpr_23(void);
void _savefpr_24(void);
void _savefpr_25(void);
void _savefpr_26(void);
void _savefpr_27(void);
void _savefpr_28(void);
void _savefpr_29(void);
void _savefpr_30(void);
void _savefpr_31(void);

asm void __save_fpr(void)
{
    nofralloc
_savefpr_14:
    stfd f14, -0x90(r11)
_savefpr_15:
    stfd f15, -0x88(r11)
_savefpr_16:
    stfd f16, -0x80(r11)
_savefpr_17:
    stfd f17, -0x78(r11)
_savefpr_18:
    stfd f18, -0x70(r11)
_savefpr_19:
    stfd f19, -0x68(r11)
_savefpr_20:
    stfd f20, -0x60(r11)
_savefpr_21:
    stfd f21, -0x58(r11)
_savefpr_22:
    stfd f22, -0x50(r11)
_savefpr_23:
    stfd f23, -0x48(r11)
_savefpr_24:
    stfd f24, -0x40(r11)
_savefpr_25:
    stfd f25, -0x38(r11)
_savefpr_26:
    stfd f26, -0x30(r11)
_savefpr_27:
    stfd f27, -0x28(r11)
_savefpr_28:
    stfd f28, -0x20(r11)
_savefpr_29:
    stfd f29, -0x18(r11)
_savefpr_30:
    stfd f30, -0x10(r11)
_savefpr_31:
    stfd f31, -0x8(r11)
    blr
}

void _restfpr_14(void);
void _restfpr_15(void);
void _restfpr_16(void);
void _restfpr_17(void);
void _restfpr_18(void);
void _restfpr_19(void);
void _restfpr_20(void);
void _restfpr_21(void);
void _restfpr_22(void);
void _restfpr_23(void);
void _restfpr_24(void);
void _restfpr_25(void);
void _restfpr_26(void);
void _restfpr_27(void);
void _restfpr_28(void);
void _restfpr_29(void);
void _restfpr_30(void);
void _restfpr_31(void);

asm void __restore_fpr(void)
{
    nofralloc
_restfpr_14:
    lfd f14, -0x90(r11)
_restfpr_15:
    lfd f15, -0x88(r11)
_restfpr_16:
    lfd f16, -0x80(r11)
_restfpr_17:
    lfd f17, -0x78(r11)
_restfpr_18:
    lfd f18, -0x70(r11)
_restfpr_19:
    lfd f19, -0x68(r11)
_restfpr_20:
    lfd f20, -0x60(r11)
_restfpr_21:
    lfd f21, -0x58(r11)
_restfpr_22:
    lfd f22, -0x50(r11)
_restfpr_23:
    lfd f23, -0x48(r11)
_restfpr_24:
    lfd f24, -0x40(r11)
_restfpr_25:
    lfd f25, -0x38(r11)
_restfpr_26:
    lfd f26, -0x30(r11)
_restfpr_27:
    lfd f27, -0x28(r11)
_restfpr_28:
    lfd f28, -0x20(r11)
_restfpr_29:
    lfd f29, -0x18(r11)
_restfpr_30:
    lfd f30, -0x10(r11)
_restfpr_31:
    lfd f31, -0x8(r11)
    blr
}

void _savegpr_14(void);
void _savegpr_15(void);
void _savegpr_16(void);
void _savegpr_17(void);
void _savegpr_18(void);
void _savegpr_19(void);
void _savegpr_20(void);
void _savegpr_21(void);
void _savegpr_22(void);
void _savegpr_23(void);
void _savegpr_24(void);
void _savegpr_25(void);
void _savegpr_26(void);
void _savegpr_27(void);
void _savegpr_28(void);
void _savegpr_29(void);
void _savegpr_30(void);
void _savegpr_31(void);

asm void __save_gpr(void)
{
    nofralloc
_savegpr_14:
    stw r14, -0x48(r11)
_savegpr_15:
    stw r15, -0x44(r11)
_savegpr_16:
    stw r16, -0x40(r11)
_savegpr_17:
    stw r17, -0x3c(r11)
_savegpr_18:
    stw r18, -0x38(r11)
_savegpr_19:
    stw r19, -0x34(r11)
_savegpr_20:
    stw r20, -0x30(r11)
_savegpr_21:
    stw r21, -0x2c(r11)
_savegpr_22:
    stw r22, -0x28(r11)
_savegpr_23:
    stw r23, -0x24(r11)
_savegpr_24:
    stw r24, -0x20(r11)
_savegpr_25:
    stw r25, -0x1c(r11)
_savegpr_26:
    stw r26, -0x18(r11)
_savegpr_27:
    stw r27, -0x14(r11)
_savegpr_28:
    stw r28, -0x10(r11)
_savegpr_29:
    stw r29, -0xc(r11)
_savegpr_30:
    stw r30, -0x8(r11)
_savegpr_31:
    stw r31, -0x4(r11)
    blr
}

void _restgpr_14(void);
void _restgpr_15(void);
void _restgpr_16(void);
void _restgpr_17(void);
void _restgpr_18(void);
void _restgpr_19(void);
void _restgpr_20(void);
void _restgpr_21(void);
void _restgpr_22(void);
void _restgpr_23(void);
void _restgpr_24(void);
void _restgpr_25(void);
void _restgpr_26(void);
void _restgpr_27(void);
void _restgpr_28(void);
void _restgpr_29(void);
void _restgpr_30(void);
void _restgpr_31(void);

asm void __restore_gpr(void)
{
    nofralloc
_restgpr_14:
    lwz r14, -0x48(r11)
_restgpr_15:
    lwz r15, -0x44(r11)
_restgpr_16:
    lwz r16, -0x40(r11)
_restgpr_17:
    lwz r17, -0x3c(r11)
_restgpr_18:
    lwz r18, -0x38(r11)
_restgpr_19:
    lwz r19, -0x34(r11)
_restgpr_20:
    lwz r20, -0x30(r11)
_restgpr_21:
    lwz r21, -0x2c(r11)
_restgpr_22:
    lwz r22, -0x28(r11)
_restgpr_23:
    lwz r23, -0x24(r11)
_restgpr_24:
    lwz r24, -0x20(r11)
_restgpr_25:
    lwz r25, -0x1c(r11)
_restgpr_26:
    lwz r26, -0x18(r11)
_restgpr_27:
    lwz r27, -0x14(r11)
_restgpr_28:
    lwz r28, -0x10(r11)
_restgpr_29:
    lwz r29, -0xc(r11)
_restgpr_30:
    lwz r30, -0x8(r11)
_restgpr_31:
    lwz r31, -0x4(r11)
    blr
}

asm void __div2u(void)
{
    nofralloc
    cmpwi   cr0, r3, 0
    cntlzw  r0, r3
    cntlzw  r9, r4
    bne     cr0, lab1
    addi    r0, r9, 32
lab1:
    cmpwi   cr0, r5, 0
    cntlzw  r9, r5
    cntlzw  r10, r6
    bne     cr0, lab2
    addi    r9, r10, 32
lab2:
    cmpw    cr0, r0, r9
    subfic  r10, r0, 64
    bgt     cr0, lab9
    addi    r9, r9, 1
    subfic  r9, r9, 64
    add     r0, r0, r9
    subf    r9, r9, r10
    mtctr   r9
    cmpwi   cr0, r9, 32
    addi    r7, r9, -32
    blt     cr0, lab3
    srw     r8, r3, r7
    li      r7, 0
    b       lab4
lab3:
    srw     r8, r4, r9
    subfic  r7, r9, 32
    slw     r7, r3, r7
    or      r8, r8, r7
    srw     r7, r3, r9
lab4:
    cmpwi   cr0, r0, 32
    addic   r9, r0, -32
    blt     cr0, lab5
    slw     r3, r4, r9
    li      r4, 0
    b       lab6
lab5:
    slw     r3, r3, r0
    subfic  r9, r0, 32
    srw     r9, r4, r9
    or      r3, r3, r9
    slw     r4, r4, r0
lab6:
    li      r10, -1
    addic   r7, r7, 0
lab7:
    adde    r4, r4, r4
    adde    r3, r3, r3
    adde    r8, r8, r8
    adde    r7, r7, r7
    subfc   r0, r6, r8
    subfe.  r9, r5, r7
    blt     cr0, lab8
    mr      r8, r0
    mr      r7, r9
    addic   r0, r10, 1
lab8:
    bdnz    lab7
    adde    r4, r4, r4
    adde    r3, r3, r3
    blr
lab9:
    li      r4, 0
    li      r3, 0
    blr
}

asm void __div2i(void)
{
    nofralloc
    stwu     r1, -16(r1)
    rlwinm.  r9, r3, 0, 0, 0
    beq      cr0, positive1
    subfic   r4, r4, 0
    subfze   r3, r3
positive1:
    stw      r9, 8(r1)
    rlwinm.  r10, r5, 0, 0, 0
    beq      cr0, positive2
    subfic   r6, r6, 0
    subfze   r5, r5
positive2:
    stw      r10, 12(r1)
    cmpwi    cr0, r3, 0
    cntlzw   r0, r3
    cntlzw   r9, r4
    bne      cr0, lab1
    addi     r0, r9, 32
lab1:
    cmpwi    cr0, r5, 0
    cntlzw   r9, r5
    cntlzw   r10, r6
    bne      cr0, lab2
    addi     r9, r10, 32
lab2:
    cmpw     cr0, r0, r9
    subfic   r10, r0, 64
    bgt      cr0, lab9
    addi     r9, r9, 1
    subfic   r9, r9, 64
    add      r0, r0, r9
    subf     r9, r9, r10
    mtctr    r9
    cmpwi    cr0, r9, 32
    addi     r7, r9, -32
    blt      cr0, lab3
    srw      r8, r3, r7
    li       r7, 0
    b        lab4
lab3:
    srw      r8, r4, r9
    subfic   r7, r9, 32
    slw      r7, r3, r7
    or       r8, r8, r7
    srw      r7, r3, r9
lab4:
    cmpwi    cr0, r0, 32
    addic    r9, r0, -32
    blt      cr0, lab5
    slw      r3, r4, r9
    li       r4, 0
    b        lab6
lab5:
    slw      r3, r3, r0
    subfic   r9, r0, 32
    srw      r9, r4, r9
    or       r3, r3, r9
    slw      r4, r4, r0
lab6:
    li       r10, -1
    addic    r7, r7, 0
lab7:
    adde     r4, r4, r4
    adde     r3, r3, r3
    adde     r8, r8, r8
    adde     r7, r7, r7
    subfc    r0, r6, r8
    subfe.   r9, r5, r7
    blt      cr0, lab8
    mr       r8, r0
    mr       r7, r9
    addic    r0, r10, 1
lab8:
    bdnz     lab7
    adde     r4, r4, r4
    adde     r3, r3, r3
    lwz      r9, 8(r1)
    lwz      r10, 12(r1)
    xor.     r7, r9, r10
    beq      no_adjust
    cmpwi    cr0, r9, 0
    subfic   r4, r4, 0
    subfze   r3, r3
no_adjust:
    b        func_end
lab9:
    li       r4, 0
    li       r3, 0
func_end:
    addi     r1, r1, 16
    blr
}

asm void __mod2u(void)
{
    nofralloc
    cmpwi    cr0, r3, 0
    cntlzw   r0, r3
    cntlzw   r9, r4
    bne      cr0, lab1
    addi     r0, r9, 32
lab1:
    cmpwi    cr0, r5, 0
    cntlzw   r9, r5
    cntlzw   r10, r6
    bne      cr0, lab2
    addi     r9, r10, 32
lab2:
    cmpw     cr0, r0, r9
    subfic   r10, r0, 64
    bgtlr
    addi     r9, r9, 1
    subfic   r9, r9, 64
    add      r0, r0, r9
    subf     r9, r9, r10
    mtctr    r9
    cmpwi    cr0, r9, 32
    addi     r7, r9, -32
    blt      cr0, lab3
    srw      r8, r3, r7
    li       r7, 0
    b        lab4
lab3:
    srw      r8, r4, r9
    subfic   r7, r9, 32
    slw      r7, r3, r7
    or       r8, r8, r7
    srw      r7, r3, r9
lab4:
    cmpwi    cr0, r0, 32
    addic    r9, r0, -32
    blt      cr0, lab5
    slw      r3, r4, r9
    li       r4, 0
    b        lab6
lab5:
    slw      r3, r3, r0
    subfic   r9, r0, 32
    srw      r9, r4, r9
    or       r3, r3, r9
    slw      r4, r4, r0
lab6:
    li       r10, -1
    addic    r7, r7, 0
lab7:
    adde     r4, r4, r4
    adde     r3, r3, r3
    adde     r8, r8, r8
    adde     r7, r7, r7
    subfc    r0, r6, r8
    subfe.   r9, r5, r7
    blt      cr0, lab8
    mr       r8, r0
    mr       r7, r9
    addic    r0, r10, 1
lab8:
    bdnz     lab7
    mr       r4, r8
    mr       r3, r7
    blr
lab9:
    blr
}

#pragma push
#pragma optimization_level 0
#pragma optimizewithasm off

asm void __mod2i(void)
{
    nofralloc
    cmpwi    cr7, r3, 0
    bge      cr7, positive1
    subfic   r4, r4, 0
    subfze   r3, r3
positive1:
    cmpwi    cr0, r5, 0
    bge      cr0, positive2
    subfic   r6, r6, 0
    subfze   r5, r5
positive2:
    cmpwi    cr0, r3, 0
    cntlzw   r0, r3
    cntlzw   r9, r4
    bne      cr0, lab1
    addi     r0, r9, 32
lab1:
    cmpwi    cr0, r5, 0
    cntlzw   r9, r5
    cntlzw   r10, r6
    bne      cr0, lab2
    addi     r9, r10, 32
lab2:
    cmpw     cr0, r0, r9
    subfic   r10, r0, 64
    bgt      cr0, lab9
    addi     r9, r9, 1
    subfic   r9, r9, 64
    add      r0, r0, r9
    subf     r9, r9, r10
    mtctr    r9
    cmpwi    cr0, r9, 32
    addi     r7, r9, -32
    blt      cr0, lab3
    srw      r8, r3, r7
    li       r7, 0
    b        lab4
lab3:
    srw      r8, r4, r9
    subfic   r7, r9, 32
    slw      r7, r3, r7
    or       r8, r8, r7
    srw      r7, r3, r9
lab4:
    cmpwi    cr0, r0, 32
    addic    r9, r0, -32
    blt      cr0, lab5
    slw      r3, r4, r9
    li       r4, 0
    b        lab6
lab5:
    slw      r3, r3, r0
    subfic   r9, r0, 32
    srw      r9, r4, r9
    or       r3, r3, r9
    slw      r4, r4, r0
lab6:
    li       r10, -1
    addic    r7, r7, 0
lab7:
    adde     r4, r4, r4
    adde     r3, r3, r3
    adde     r8, r8, r8
    adde     r7, r7, r7
    subfc    r0, r6, r8
    subfe.   r9, r5, r7
    blt      cr0, lab8
    mr       r8, r0
    mr       r7, r9
    addic    r0, r10, 1
lab8:
    bdnz     lab7
    mr       r4, r8
    mr       r3, r7
lab9:
    bgelr    cr7
    subfic   r4, r4, 0
    subfze   r3, r3
    blr
}
#pragma pop

asm void __shl2i(void)
{
    nofralloc
    subfic  r8, r5, 32
    subic   r9, r5, 32
    slw     r3, r3, r5
    srw     r10, r4, r8
    or      r3, r3, r10
    slw     r10, r4, r9
    or      r3, r3, r10
    slw     r4, r4, r5
    blr
}

asm void __shr2u(void)
{
    nofralloc
    subfic  r8, r5, 32
    subic   r9, r5, 32
    srw     r4, r4, r5
    slw     r10, r3, r8
    or      r4, r4, r10
    srw     r10, r3, r9
    or      r4, r4, r10
    srw     r3, r3, r5
    blr
}

asm void __shr2i(void)
{
    nofralloc
    subfic  r8, r5, 0x20
    addic.  r9, r5, -0x20
    srw     r4, r4, r5
    slw     r10, r3, r8
    or      r4, r4, r10
    sraw    r10, r3, r9
    ble     shr2i_end
    or      r4, r4, r10
shr2i_end:
    sraw    r3, r3, r5
    blr
}

asm void __cvt_sll_flt(void)
{
    nofralloc
    stwu    r1, -0x10(r1)
    clrrwi. r5, r3, 31
    beq     L1
    subfic  r4, r4, 0
    subfze  r3, r3
L1:
    or.     r7, r3, r4
    li      r6, 0
    beq     L4
    cntlzw  r7, r3
    cntlzw  r8, r4
    extlwi  r9, r7, 5, 26
    srawi   r9, r9, 31
    and     r9, r9, r8
    add     r7, r7, r9
    subfic  r8, r7, 32
    addic   r9, r7, -32
    slw     r3, r3, r7
    srw     r10, r4, r8
    or      r3, r3, r10
    slw     r10, r4, r9
    or      r3, r3, r10
    slw     r4, r4, r7
    subf    r6, r7, r6
    clrlwi  r7, r4, 21
    cmpwi   r7, 0x400
    addi    r6, r6, 0x43e
    blt     L2
    bgt     L3
    rlwinm. r7, r4, 0, 20, 20
    beq     L2
L3:
    addic   r4, r4, 0x800
    addze   r3, r3
    addze   r6, r6
L2:
    rotrwi  r4, r4, 11
    rlwimi  r4, r3, 21, 0, 10
    extrwi  r3, r3, 20, 1
    slwi    r6, r6, 20
    or      r3, r6, r3
    or      r3, r5, r3
L4:
    stw     r3, 8(r1)
    stw     r4, 12(r1)
    lfd     f1, 8(r1)
    frsp    f1, f1
    addi    r1, r1, 16
    blr
}

asm u64 __cvt_dbl_usll(double x)
{
    nofralloc
    stwu    r1, -16(r1)
    stfd    f1, 8(r1)
    lwz     r3, 8(r1)
    lwz     r4, 12(r1)
    rlwinm   r5, r3, 12, 21, 31
    cmpli    cr0, 0, r5, 1023
    bge      cr0, not_fraction
    li       r3, 0
    li       r4, 0
    b        func_end
not_fraction:
    mr       r6, r3
    rlwinm   r3, r3, 0, 12, 31
    oris     r3, r3, 0x0010
    addi     r5, r5, -1075
    cmpwi    cr0, r5, 0
    bge      cr0, left
    neg      r5, r5
    subfic   r8, r5, 32
    subic    r9, r5, 32
    srw      r4, r4, r5
    slw      r10, r3, r8
    or       r4, r4, r10
    srw      r10, r3, r9
    or       r4, r4, r10
    srw      r3, r3, r5
    b        around
left:
    cmpwi    cr0, r5, 10
    ble+     no_overflow
    rlwinm.  r6, r6, 0, 0, 0
    beq      cr0, max_positive
    lis      r3, 0x8000
    li       r4, 0
    b        func_end
max_positive:
    lis      r3, 0x7FFF
    ori      r3, r3, 0xFFFF
    li       r4, -1
    b        func_end
no_overflow:
    subfic   r8, r5, 32
    subic    r9, r5, 32
    slw      r3, r3, r5
    srw      r10, r4, r8
    or       r3, r3, r10
    slw      r10, r4, r9
    or       r3, r3, r10
    slw      r4, r4, r5
around:
    rlwinm.  r6, r6, 0, 0, 0
    beq      cr0, positive
    subfic   r4, r4, 0
    subfze   r3, r3
positive:
func_end:
    addi    r1, r1, 16
    blr
}

#pragma cplusplus on
asm char* GetR2(void)
{
    nofralloc
    mr r3, r2
    blr
}
#pragma cplusplus reset
