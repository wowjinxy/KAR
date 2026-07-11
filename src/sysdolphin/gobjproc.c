#include <functions.h>
#include <dolphin/os.h>
#include <sysdolphin/gobj.h>
#include <sysdolphin/gobjproc.h>

typedef s32 (*HSD_DebugExceptionCallback)(s32, s32, void*, void*);
typedef void (*HSD_DebugConsoleCallback)(void*, ...);
typedef void (*HSD_DebugUserCallback)(s32, u32);

typedef struct _HSD_StackFrame {
    struct _HSD_StackFrame* next;
    u32 ret_addr;
} HSD_StackFrame;

extern u8 __files[];
extern u8 hsd_saved_context[];
extern char HSDAssertPanicMessage[8];
extern char GObjProcAssertProc[6];

extern HSD_DebugExceptionCallback HSDDebugExceptionCallback;
extern s32 HSDDebugExceptionCallbackInstalled;
extern HSD_DebugConsoleCallback HSDDebugConsoleCallback;
extern HSD_DebugUserCallback HSDDebugUserCallback;

void HSD_SaveContext(void* arg0);

char HSDAssertFailedFormat[0x18] = "assertion \"%s\" failed";
char HSDPanicReportFormat[0x18] = "%s in %s on line %d.\n";
char GObjProcSourceFile[0xC] = "gobjproc.c";
char GObjProcPriorityAssert[0x2C] = "pri <= HSD_GObjLibInitData.gproc_pri_max";

#pragma push
asm void HSD_SaveContext(void* arg0)
{
    nofralloc
/* 80428398 00425198  7C 70 43 A6 */ mtsprg 0, r3
/* 8042839C 0042519C  3C 60 80 59 */ lis r3, hsd_saved_context@ha
/* 804283A0 004251A0  38 63 BE C8 */ addi r3, r3, hsd_saved_context@l
/* 804283A4 004251A4  BC 03 00 00 */ stmw r0, 0(r3)
/* 804283A8 004251A8  7C 90 42 A6 */ mfsprg r4, 0
/* 804283AC 004251AC  90 83 00 0C */ stw r4, 0xc(r3)
/* 804283B0 004251B0  7C 90 E2 A6 */ mfspr r4, GQR0
/* 804283B4 004251B4  90 83 01 A4 */ stw r4, 0x1a4(r3)
/* 804283B8 004251B8  7C 91 E2 A6 */ mfspr r4, GQR1
/* 804283BC 004251BC  90 83 01 A8 */ stw r4, 0x1a8(r3)
/* 804283C0 004251C0  7C 92 E2 A6 */ mfspr r4, GQR2
/* 804283C4 004251C4  90 83 01 AC */ stw r4, 0x1ac(r3)
/* 804283C8 004251C8  7C 93 E2 A6 */ mfspr r4, GQR3
/* 804283CC 004251CC  90 83 01 B0 */ stw r4, 0x1b0(r3)
/* 804283D0 004251D0  7C 94 E2 A6 */ mfspr r4, GQR4
/* 804283D4 004251D4  90 83 01 B4 */ stw r4, 0x1b4(r3)
/* 804283D8 004251D8  7C 95 E2 A6 */ mfspr r4, GQR5
/* 804283DC 004251DC  90 83 01 B8 */ stw r4, 0x1b8(r3)
/* 804283E0 004251E0  7C 96 E2 A6 */ mfspr r4, GQR6
/* 804283E4 004251E4  90 83 01 BC */ stw r4, 0x1bc(r3)
/* 804283E8 004251E8  7C 97 E2 A6 */ mfspr r4, GQR7
/* 804283EC 004251EC  90 83 01 C0 */ stw r4, 0x1c0(r3)
/* 804283F0 004251F0  7C 80 00 26 */ mfcr r4
/* 804283F4 004251F4  90 83 00 80 */ stw r4, 0x80(r3)
/* 804283F8 004251F8  7C 88 02 A6 */ mflr r4
/* 804283FC 004251FC  90 83 00 84 */ stw r4, 0x84(r3)
/* 80428400 00425200  7C 89 02 A6 */ mfctr r4
/* 80428404 00425204  90 83 00 88 */ stw r4, 0x88(r3)
/* 80428408 00425208  7C 81 02 A6 */ mfxer r4
/* 8042840C 0042520C  90 83 00 8C */ stw r4, 0x8c(r3)
/* 80428410 00425210  7C 9A 02 A6 */ mfsrr0 r4
/* 80428414 00425214  90 83 01 98 */ stw r4, 0x198(r3)
/* 80428418 00425218  7C 9B 02 A6 */ mfsrr1 r4
/* 8042841C 0042521C  90 83 01 9C */ stw r4, 0x19c(r3)
/* 80428420 00425220  A0 83 01 A2 */ lhz r4, 0x1a2(r3)
/* 80428424 00425224  60 84 00 01 */ ori r4, r4, 1
/* 80428428 00425228  B0 83 01 A2 */ sth r4, 0x1a2(r3)
/* 8042842C 0042522C  4B FA C7 90 */ b OSFillFPUContext
}
#pragma pop

s32 HSD_DebugExceptionCallbackThunk(s32 arg0, s32 exception, void* context, void* arg3)
{
    if (HSDDebugUserCallback != NULL) {
        HSDDebugUserCallback(exception, *(u32*) context);
    }
    HSDDebugExceptionCallback(arg0, exception, context, arg3);
    return 0;
}

#pragma push
#pragma dont_inline on
void __assert(const char* file, unsigned long line, const char* assertion)
{
    OSReport(HSDAssertFailedFormat, assertion);
    HSD_Panic(file, line, HSDAssertPanicMessage);
}

void HSD_Panic(const char* file, s32 line, const char* msg)
{
    if (HSDDebugConsoleCallback != NULL) {
        HSD_SaveContext((void*) file);
        OSReport(HSDPanicReportFormat, msg, file, line);
        HSDDebugConsoleCallback(hsd_saved_context);
    }
    OSPanic(file, line, msg);
}
#pragma pop

HSD_DebugUserCallback HSD_SetDebugExceptionCallback(HSD_DebugUserCallback callback)
{
    HSD_DebugUserCallback old_callback = HSDDebugUserCallback;

    if (HSDDebugExceptionCallbackInstalled == 0) {
        if (HSDDebugExceptionCallback == NULL) {
            HSDDebugExceptionCallback = *(HSD_DebugExceptionCallback*) &__files[0x90];
        }
        *(s32*) &__files[0x90] = (s32) HSD_DebugExceptionCallbackThunk;
        __files[0x5A] = 0;
        HSDDebugExceptionCallbackInstalled = 1;
    }
    HSDDebugUserCallback = callback;
    return old_callback;
}

HSD_DebugConsoleCallback HSD_SetDebugConsoleCallback(HSD_DebugConsoleCallback callback)
{
    HSD_DebugConsoleCallback old_callback = HSDDebugConsoleCallback;
    HSDDebugConsoleCallback = callback;
    return old_callback;
}

u32 HSD_GetStackFrameReturnAddress(s32 depth)
{
    HSD_StackFrame* frame;
    s32 i = 0;
    s32 target;

    frame = *(HSD_StackFrame**) OSGetStackPointer();
    target = depth + 1;
    while ((u32) frame != 0xFFFFFFFF) {
        if (i++ == target) {
            return frame->ret_addr;
        }
        frame = frame->next;
    }
    return 0;
}

void HSD_GObjProcLink_Internal(HSD_GObjProc* proc)
{
    HSD_GObj* gobj = proc->gobj;
    HSD_GObjProc* dst_proc;
    u8 s_link = proc->s_link;
    s32 p_link = gobj->p_link;
    s32 index = p_link + s_link * (hsdGObj_p_link_max.p_link_max + 1);

    if (hsdGObjProc_link_heads[index] != NULL) {
        HSD_GObj* cur_gobj = gobj;

        while (cur_gobj != NULL) {
            dst_proc = cur_gobj->proc;
            while (dst_proc != NULL) {
                if (dst_proc->s_link == s_link) {
                    if (hsdGObjProc_link_heads[index] == dst_proc) {
                        hsdGObjProc_link_heads[index] = proc;
                    }
                    goto insert_at_dst;
                }
                dst_proc = dst_proc->child;
            }
            cur_gobj = cur_gobj->prev;
        }
    } else {
        hsdGObjProc_link_heads[index] = proc;
    }

    while (p_link-- != 0) {
        dst_proc = hsdGObjProc_link_heads[p_link + s_link * (hsdGObj_p_link_max.p_link_max + 1)];
        if (dst_proc != NULL) {
            goto insert_at_dst;
        }
    }

    proc->next = hsdGObjProc_priority_heads[s_link];
    hsdGObjProc_priority_heads[s_link] = proc;
    proc->prev = NULL;
    goto inserted;

insert_at_dst:
    proc->next = dst_proc->next;
    dst_proc->next = proc;
    proc->prev = dst_proc;

inserted:
    if (proc->next != NULL) {
        proc->next->prev = proc;
    }
    proc->child = gobj->proc;
    gobj->proc = proc;
    if (hsdGObj_deferred_action_flags.b0 && proc->prev == hsdGObjProc_current &&
        proc->next == hsdGObjProc_next && s_link == hsdGObjProc_current_s_link) {
        hsdGObjProc_next = proc;
    }
}

void HSD_GObjProcUnlink_Internal(HSD_GObjProc* proc)
{
    HSD_GObj* gobj = proc->gobj;
    s32 p_link = gobj->p_link;
    s32 s_link = proc->s_link;
    s32 index;

    if (hsdGObj_deferred_action_flags.b0 && proc == hsdGObjProc_next) {
        hsdGObjProc_next = proc->next;
    }
    index = p_link + s_link * (hsdGObj_p_link_max.p_link_max + 1);
    if (proc == hsdGObjProc_link_heads[index]) {
        if (proc->prev != NULL && proc->prev->gobj->p_link == p_link) {
            hsdGObjProc_link_heads[index] = proc->prev;
        } else {
            hsdGObjProc_link_heads[index] = NULL;
        }
    }
    if (proc->prev != NULL) {
        proc->prev->next = proc->next;
    } else {
        hsdGObjProc_priority_heads[s_link] = proc->next;
    }
    if (proc->next != NULL) {
        proc->next->prev = proc->prev;
    }
}

HSD_GObjProc* HSD_GObjProcCreate(HSD_GObj* gobj, void (*callback)(HSD_GObj*), u8 priority)
{
    HSD_GObjProc* proc;

    proc = HSD_ObjAlloc(&hsdGObjProc_alloc_data);

    if (proc == NULL) {
        __assert(GObjProcSourceFile, 0x1F, GObjProcAssertProc);
    }
    if (priority > hsdGObj_p_link_max.gproc_pri_max) {
        __assert(GObjProcSourceFile, 0xD8, GObjProcPriorityAssert);
    }

    proc->s_link = priority;
    proc->flags_1 = proc->flags_2 = 0;
    proc->flags_3 = 3;
    proc->gobj = gobj;
    proc->callback = callback;
    HSD_GObjProcLink_Internal(proc);
    return proc;
}

#define HSD_GOBJ_PROC_UNLINK_FROM_GOBJ(proc) \
    do { \
        HSD_GObj* gobj = (proc)->gobj; \
        HSD_GObjProc* cur; \
 \
        HSD_GObjProcUnlink_Internal(proc); \
        if (gobj->proc == (proc)) { \
            gobj->proc = (proc)->child; \
        } else { \
            cur = gobj->proc; \
            while (cur->child != (proc)) { \
                cur = cur->child; \
            } \
            cur->child = (proc)->child; \
        } \
    } while (0)

void HSD_GObjProcRemove(HSD_GObjProc* proc)
{
    if (!hsdGObj_deferred_action_flags.b0 && proc == hsdGObjProc_current) {
        hsdGObj_deferred_action_flags.b2 = TRUE;
        return;
    }

    HSD_GOBJ_PROC_UNLINK_FROM_GOBJ(proc);
    HSD_ObjFree(&hsdGObjProc_alloc_data, proc);
}

void HSD_GObjProcRemoveAll(HSD_GObj* gobj)
{
    HSD_GObjProc* proc = gobj->proc;

    while (proc != NULL) {
        HSD_GObjProc* next = proc->child;
        HSD_GObjProcRemove(proc);
        proc = next;
    }
}
