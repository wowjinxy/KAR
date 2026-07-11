#include "dolphin/types.h"

typedef s64 OSTime;

typedef struct OSContext
{
    /* 0x000 */ u32 gpr[32];
    /* 0x080 */ u32 cr;
    /* 0x084 */ u32 lr;
    /* 0x088 */ u32 ctr;
    /* 0x08C */ u32 xer;
    /* 0x090 */ f64 fpr[32];
    /* 0x190 */ u32 fpscr_pad;
    /* 0x194 */ u32 fpscr;
    /* 0x198 */ u32 srr0;
    /* 0x19C */ u32 srr1;
    /* 0x1A0 */ u16 mode;
    /* 0x1A2 */ u16 state;
    /* 0x1A4 */ u32 gqr[8];
    /* 0x1C4 */ u32 psf_pad;
    /* 0x1C8 */ f64 psf[32];
} OSContext;

typedef u32 __OSInterrupt;
typedef void (*__OSInterruptHandler)(__OSInterrupt interrupt, OSContext* context);

typedef void (*DSPCallback)(void* task);
typedef struct DSPTaskInfo DSPTaskInfo;

struct DSPTaskInfo
{
    /* 0x00 */ volatile u32 state;
    /* 0x04 */ volatile u32 priority;
    /* 0x08 */ volatile u32 flags;
    /* 0x0C */ u16* iram_mmem_addr;
    /* 0x10 */ u32 iram_length;
    /* 0x14 */ u32 iram_addr;
    /* 0x18 */ u16* dram_mmem_addr;
    /* 0x1C */ u32 dram_length;
    /* 0x20 */ u32 dram_addr;
    /* 0x24 */ u16 dsp_init_vector;
    /* 0x26 */ u16 dsp_resume_vector;
    /* 0x28 */ DSPCallback init_cb;
    /* 0x2C */ DSPCallback res_cb;
    /* 0x30 */ DSPCallback done_cb;
    /* 0x34 */ DSPCallback req_cb;
    /* 0x38 */ DSPTaskInfo* next;
    /* 0x3C */ DSPTaskInfo* prev;
    /* 0x40 */ OSTime t_context;
    /* 0x48 */ OSTime t_task;
};

typedef struct OSAlarm
{
    u8 data[0x28];
} OSAlarm;

typedef void (*OSAlarmHandler)(OSAlarm* alarm, OSContext* context);
typedef void (*DVDLowCallback)(u32 reason);

typedef struct DVDCommand
{
    s32 command;
    void* address;
    u32 length;
    u32 offset;
    DVDLowCallback callback;
} DVDCommand;

extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL level);
extern void OSRegisterVersion(char* version);
extern void __OSSetInterruptHandler(u32 interrupt, __OSInterruptHandler handler);
extern u32 __OSUnmaskInterrupts(u32 mask);
extern u32 __OSMaskInterrupts(u32 mask);
extern void OSClearContext(OSContext* context);
extern void OSSetCurrentContext(OSContext* context);
extern OSTime __OSGetSystemTime(void);
extern void OSCreateAlarm(OSAlarm* alarm);
extern void OSSetAlarm(OSAlarm* alarm, OSTime tick, OSAlarmHandler handler);
extern void OSCancelAlarm(OSAlarm* alarm);
extern BOOL DVDLowSeek(u32 offset, DVDLowCallback callback);
extern void __DVDLowSetWAType(u32 type, s32 seekLoc);
extern void OSInitAlarm(void);

typedef struct DVDBuffer
{
    void* addr;
    u32 length;
    u32 offset;
} DVDBuffer;

extern s32 NextCommandNumber;
extern u32 WorkAroundSeekLocation;
extern OSTime LastReadIssued;
extern BOOL LastCommandWasRead;
extern OSTime LastReadFinished;
extern BOOL FirstRead;

#define __DSPRegs ((volatile u16*)0xCC005000)
#define __DIRegs ((volatile u32*)0xCC006000)
#define OS_BUS_CLOCK (*(volatile u32*)0x800000F8)
#define OSSecondsToTicks(sec) ((OS_BUS_CLOCK / 4) * (sec))
#define OSMillisecondsToTicks(msec) ((msec) * ((OS_BUS_CLOCK / 4) / 1000))

extern char* __DSPVersion;

static DSPTaskInfo* lbl_805DDD3C; /* __DSP_curr_task */
static DSPTaskInfo* lbl_805DDD38; /* __DSP_first_task */
static DSPTaskInfo* lbl_805DDD34; /* __DSP_last_task */
static DSPTaskInfo* lbl_805DDD30; /* __DSP_tmp_task */
static DSPTaskInfo* lbl_805DDD2C; /* __DSP_rude_task */
static int lbl_805DDD28;          /* __DSP_rude_task_pending */
static BOOL lbl_805DDD20;         /* __DSP_init_flag */

#define __DSP_curr_task lbl_805DDD3C
#define __DSP_first_task lbl_805DDD38
#define __DSP_last_task lbl_805DDD34
#define __DSP_tmp_task lbl_805DDD30
#define __DSP_rude_task lbl_805DDD2C
#define __DSP_rude_task_pending lbl_805DDD28
#define __DSP_init_flag lbl_805DDD20

void __DSPHandler(__OSInterrupt intr, OSContext* context);
void __DSP_exec_task(DSPTaskInfo* curr, DSPTaskInfo* next);
void __DSP_boot_task(DSPTaskInfo* task);
void __DSP_insert_task(DSPTaskInfo* task);
void __DSP_remove_task(DSPTaskInfo* task);
void __DSP_debug_printf(const char* fmt, ...);
void fn_803C4470(void* address, u32 length, u32 offset, DVDLowCallback callback);

#pragma dont_inline on
u32 DSPCheckMailToDSP(void)
{
    return (__DSPRegs[0] & (1 << 15)) >> 15;
}

u32 DSPCheckMailFromDSP(void)
{
    return (__DSPRegs[2] & (1 << 15)) >> 15;
}

u32 DSPReadMailFromDSP(void)
{
    return (__DSPRegs[2] << 16) | __DSPRegs[3];
}

void DSPSendMailToDSP(u32 mail)
{
    __DSPRegs[0] = mail >> 16;
    __DSPRegs[1] = mail & 0xFFFF;
}
#pragma dont_inline off

#pragma push
#pragma force_active on
static char lbl_804F9308[0x80] =
    "<< Dolphin SDK - DSP\trelease build: Sep  5 2002 05:35:13 (0x2301) >>" "\0\0\0\0"
    "DSPInit(): Build Date: %s %s\n" "\0\0\0"
    "Sep  5 2002" "\0"
    "05:35:13" "\0\0\0";
#pragma pop

void DSPInit(void)
{
    BOOL old;
    u16 tmp;

    __DSP_debug_printf(lbl_804F9308 + 0x48, lbl_804F9308 + 0x68, lbl_804F9308 + 0x74);

    if (__DSP_init_flag == 1) {
        return;
    }

    OSRegisterVersion(__DSPVersion);

    old = OSDisableInterrupts();
    __OSSetInterruptHandler(7, __DSPHandler);
    __OSUnmaskInterrupts(0x100);

    tmp = __DSPRegs[5];
    tmp = (tmp & ~0xA8) | 0x800;
    __DSPRegs[5] = tmp;

    tmp = __DSPRegs[5];
    __DSPRegs[5] = tmp = tmp & ~0xAC;

    __DSP_first_task = __DSP_last_task = __DSP_curr_task = __DSP_tmp_task = NULL;
    __DSP_init_flag = 1;

    OSRestoreInterrupts(old);
}

BOOL DSPCheckInit(void)
{
    return __DSP_init_flag;
}

DSPTaskInfo* DSPAddTask(DSPTaskInfo* task)
{
    BOOL old;

    old = OSDisableInterrupts();

    __DSP_insert_task(task);
    task->state = 0;
    task->flags = 1;

    OSRestoreInterrupts(old);
    if (task == __DSP_first_task) {
        __DSP_boot_task(task);
    }
    return task;
}

DSPTaskInfo* DSPAssertTask(DSPTaskInfo* task)
{
    s32 old;

    old = OSDisableInterrupts();

    if (__DSP_curr_task == task) {
        __DSP_rude_task = task;
        __DSP_rude_task_pending = 1;
        OSRestoreInterrupts(old);
        return task;
    }

    if (task->priority < __DSP_curr_task->priority) {
        __DSP_rude_task = task;
        __DSP_rude_task_pending = 1;
        if (__DSP_curr_task->state == 1) {
            BOOL old2 = OSDisableInterrupts();
            u16 tmp = __DSPRegs[5];
            tmp = (tmp & ~0xA8) | 2;
            __DSPRegs[5] = tmp;
            OSRestoreInterrupts(old2);
        }
        OSRestoreInterrupts(old);
        return task;
    }

    OSRestoreInterrupts(old);
    return NULL;
}

void __DSP_debug_printf(const char* fmt, ...) {}

void __DSPHandler(__OSInterrupt intr, OSContext* context)
{
    OSContext exceptionContext;
    u16 tmp;
    u32 mail;

    tmp = __DSPRegs[5];
    tmp = (tmp & ~0x28) | 0x80;
    __DSPRegs[5] = tmp;

    OSClearContext(&exceptionContext);
    OSSetCurrentContext(&exceptionContext);

    while (DSPCheckMailFromDSP() == 0)
        ;

    mail = DSPReadMailFromDSP();
    if ((__DSP_curr_task->flags & (1 << (31 - 0x1E))) && (mail + 0x232F0000) == 2) {
        mail = 0xDCD10003;
    }

    switch (mail) {
    case 0xDCD10000:
        __DSP_curr_task->state = 1;
        if (__DSP_curr_task->init_cb != NULL) {
            __DSP_curr_task->init_cb(__DSP_curr_task);
        }
        break;
    case 0xDCD10001:
        __DSP_curr_task->state = 1;
        if (__DSP_curr_task->res_cb != NULL) {
            __DSP_curr_task->res_cb(__DSP_curr_task);
        }
        break;
    case 0xDCD10002:
        if (__DSP_rude_task_pending) {
            if (__DSP_curr_task == __DSP_rude_task) {
                DSPSendMailToDSP(0xCDD10003);
                while (DSPCheckMailToDSP() != 0)
                    ;
                __DSP_rude_task = NULL;
                __DSP_rude_task_pending = 0;

                if (__DSP_curr_task->res_cb != NULL) {
                    __DSP_curr_task->res_cb(__DSP_curr_task);
                }
            } else {
                DSPSendMailToDSP(0xCDD10001);
                while (DSPCheckMailToDSP() != 0)
                    ;
                __DSP_exec_task(__DSP_curr_task, __DSP_rude_task);
                __DSP_curr_task->state = 2;
                __DSP_curr_task = __DSP_rude_task;
                __DSP_rude_task = NULL;
                __DSP_rude_task_pending = 0;
            }
        } else {
            if (__DSP_curr_task->next == NULL) {
                if (__DSP_curr_task == __DSP_first_task) {
                    DSPSendMailToDSP(0xCDD10003);
                    while (DSPCheckMailToDSP() != 0)
                        ;
                    if (__DSP_curr_task->res_cb != NULL) {
                        __DSP_curr_task->res_cb(__DSP_curr_task);
                    }
                } else {
                    DSPSendMailToDSP(0xCDD10001);
                    while (DSPCheckMailToDSP() != 0)
                        ;
                    __DSP_exec_task(__DSP_curr_task, __DSP_first_task);
                    __DSP_curr_task->state = 2;
                    __DSP_curr_task = __DSP_first_task;
                }
            } else {
                DSPSendMailToDSP(0xCDD10001);
                while (DSPCheckMailToDSP() != 0)
                    ;
                __DSP_exec_task(__DSP_curr_task, __DSP_curr_task->next);
                __DSP_curr_task->state = 2;
                __DSP_curr_task = __DSP_curr_task->next;
            }
        }
        break;
    case 0xDCD10003:
        if (__DSP_rude_task_pending) {
            if (__DSP_curr_task->done_cb != NULL) {
                __DSP_curr_task->done_cb(__DSP_curr_task);
            }

            DSPSendMailToDSP(0xCDD10001);
            while (DSPCheckMailToDSP() != 0)
                ;
            __DSP_exec_task(NULL, __DSP_rude_task);
            __DSP_remove_task(__DSP_curr_task);
            __DSP_curr_task = __DSP_rude_task;
            __DSP_rude_task = NULL;
            __DSP_rude_task_pending = 0;
        } else {
            if (__DSP_curr_task->next == NULL) {
                if (__DSP_curr_task == __DSP_first_task) {
                    if (__DSP_curr_task->done_cb != NULL) {
                        __DSP_curr_task->done_cb(__DSP_curr_task);
                    }

                    DSPSendMailToDSP(0xCDD10002);
                    while (DSPCheckMailToDSP() != 0)
                        ;
                    __DSP_curr_task->state = 3;
                    __DSP_remove_task(__DSP_curr_task);
                } else {
                    if (__DSP_curr_task->done_cb != NULL) {
                        __DSP_curr_task->done_cb(__DSP_curr_task);
                    }

                    DSPSendMailToDSP(0xCDD10001);
                    while (DSPCheckMailToDSP() != 0)
                        ;
                    __DSP_curr_task->state = 3;
                    __DSP_exec_task(NULL, __DSP_first_task);
                    __DSP_curr_task = __DSP_first_task;
                    __DSP_remove_task(__DSP_last_task);
                }
            } else {
                if (__DSP_curr_task->done_cb != NULL) {
                    __DSP_curr_task->done_cb(__DSP_curr_task);
                }

                DSPSendMailToDSP(0xCDD10001);
                while (DSPCheckMailToDSP() != 0)
                    ;
                __DSP_curr_task->state = 3;
                __DSP_exec_task(NULL, __DSP_curr_task->next);
                __DSP_curr_task = __DSP_curr_task->next;
                __DSP_remove_task(__DSP_curr_task->prev);
            }
        }
        break;
    case 0xDCD10004:
        if (__DSP_curr_task->req_cb != NULL) {
            __DSP_curr_task->req_cb(__DSP_curr_task);
        }
        break;
    }

    OSClearContext(&exceptionContext);
    OSSetCurrentContext(context);
}

void __DSP_exec_task(DSPTaskInfo* curr, DSPTaskInfo* next)
{
    if (curr != NULL) {
        DSPSendMailToDSP((u32)curr->dram_mmem_addr);
        while (DSPCheckMailToDSP() != 0)
            ;
        DSPSendMailToDSP(curr->dram_length);
        while (DSPCheckMailToDSP() != 0)
            ;
        DSPSendMailToDSP(curr->dram_addr);
        while (DSPCheckMailToDSP() != 0)
            ;
    } else {
        DSPSendMailToDSP(0);
        while (DSPCheckMailToDSP() != 0)
            ;
        DSPSendMailToDSP(0);
        while (DSPCheckMailToDSP() != 0)
            ;
        DSPSendMailToDSP(0);
        while (DSPCheckMailToDSP() != 0)
            ;
    }

    DSPSendMailToDSP((u32)next->iram_mmem_addr);
    while (DSPCheckMailToDSP() != 0)
        ;

    DSPSendMailToDSP(next->iram_length);
    while (DSPCheckMailToDSP() != 0)
        ;

    DSPSendMailToDSP(next->iram_addr);
    while (DSPCheckMailToDSP() != 0)
        ;

    if (next->state == 0) {
        DSPSendMailToDSP(next->dsp_init_vector);
        while (DSPCheckMailToDSP() != 0)
            ;
        DSPSendMailToDSP(0);
        while (DSPCheckMailToDSP() != 0)
            ;
        DSPSendMailToDSP(0);
        while (DSPCheckMailToDSP() != 0)
            ;
        DSPSendMailToDSP(0);
        while (DSPCheckMailToDSP() != 0)
            ;
    } else {
        DSPSendMailToDSP(next->dsp_resume_vector);
        while (DSPCheckMailToDSP() != 0)
            ;

        DSPSendMailToDSP((u32)next->dram_mmem_addr);
        while (DSPCheckMailToDSP() != 0)
            ;

        DSPSendMailToDSP(next->dram_length);
        while (DSPCheckMailToDSP() != 0)
            ;

        DSPSendMailToDSP(next->dram_addr);
        while (DSPCheckMailToDSP() != 0)
            ;
    }
}

#pragma push
#pragma force_active on
static char lbl_804F9388[0x140] =
    "DSP is booting task: 0x%08X\n" "\0\0\0\0"
    "__DSP_boot_task()  : IRAM MMEM ADDR: 0x%08X\n" "\0\0\0\0"
    "__DSP_boot_task()  : IRAM DSP ADDR : 0x%08X\n" "\0\0\0\0"
    "__DSP_boot_task()  : IRAM LENGTH   : 0x%08X\n" "\0\0\0\0"
    "__DSP_boot_task()  : DRAM MMEM ADDR: 0x%08X\n" "\0\0\0\0"
    "__DSP_boot_task()  : Start Vector  : 0x%08X\n" "\0\0\0\0"
    "__DSP_add_task() : Added task    : 0x%08X\n" "\0\0\0\0\0";
#pragma pop

void __DSP_boot_task(DSPTaskInfo* task)
{
    volatile u32 mail;

    while (DSPCheckMailFromDSP() == 0)
        ;

    mail = DSPReadMailFromDSP();

    DSPSendMailToDSP(0x80F3A001);
    while (DSPCheckMailToDSP() != 0)
        ;

    DSPSendMailToDSP((u32)task->iram_mmem_addr);
    while (DSPCheckMailToDSP() != 0)
        ;

    DSPSendMailToDSP(0x80F3C002);
    while (DSPCheckMailToDSP() != 0)
        ;

    DSPSendMailToDSP(task->iram_addr & 0xFFFF);
    while (DSPCheckMailToDSP() != 0)
        ;

    DSPSendMailToDSP(0x80F3A002);
    while (DSPCheckMailToDSP() != 0)
        ;

    DSPSendMailToDSP(task->iram_length);
    while (DSPCheckMailToDSP() != 0)
        ;

    DSPSendMailToDSP(0x80F3B002);
    while (DSPCheckMailToDSP() != 0)
        ;

    DSPSendMailToDSP(0);
    while (DSPCheckMailToDSP() != 0)
        ;

    DSPSendMailToDSP(0x80F3D001);
    while (DSPCheckMailToDSP() != 0)
        ;

    DSPSendMailToDSP(task->dsp_init_vector);
    while (DSPCheckMailToDSP() != 0)
        ;

    __DSP_debug_printf(lbl_804F9388 + 0x00, (u32)task);
    __DSP_debug_printf(lbl_804F9388 + 0x20, (u32)task->iram_mmem_addr);
    __DSP_debug_printf(lbl_804F9388 + 0x50, task->iram_addr);
    __DSP_debug_printf(lbl_804F9388 + 0x80, task->iram_length);
    __DSP_debug_printf(lbl_804F9388 + 0xB0, task->dram_length);
    __DSP_debug_printf(lbl_804F9388 + 0xE0, task->dsp_init_vector);
}

void __DSP_insert_task(DSPTaskInfo* task)
{
    DSPTaskInfo* temp;

    if (__DSP_first_task == NULL) {
        __DSP_curr_task = task;
        __DSP_first_task = __DSP_last_task = task;
        task->next = task->prev = NULL;
        return;
    }

    temp = __DSP_first_task;
    while (temp != NULL) {
        if (task->priority < temp->priority) {
            task->prev = temp->prev;
            temp->prev = task;
            task->next = temp;
            if (task->prev == NULL) {
                __DSP_first_task = task;
            } else {
                task->prev->next = task;
            }
            break;
        }
        temp = temp->next;
    }

    if (temp == NULL) {
        __DSP_last_task->next = task;
        task->next = NULL;
        task->prev = __DSP_last_task;
        __DSP_last_task = task;
    }
}

void __DSP_remove_task(DSPTaskInfo* task)
{
    task->flags = 0;
    task->state = 3;

    if (__DSP_first_task == task) {
        if (task->next != NULL) {
            __DSP_first_task = task->next;
            task->next->prev = NULL;
        } else {
            __DSP_first_task = __DSP_last_task = __DSP_curr_task = NULL;
        }
        return;
    }

    if (__DSP_last_task == task) {
        __DSP_last_task = task->prev;
        task->prev->next = NULL;
        __DSP_curr_task = __DSP_first_task;
        return;
    }

    __DSP_curr_task = task->next;
    task->prev->next = task->next;
    task->next->prev = task->prev;
}

static u8 lbl_8056BE00[0x800];
static u8 lbl_8056C600[0x20];
static u8 lbl_8056C620[0x500];
static u8 lbl_8056CB20[0x20];
static DVDCommand CommandList_8056CB40[3];
static u8 unk_8056CB7C[0x2C];

static BOOL lbl_805DDD60;              /* Breaking */
static BOOL WaitingCoverClose_805DDD5C;
static BOOL ResetOccurred_805DDD58;
static OSTime LastResetEnd_805DDD50;
static DVDLowCallback lbl_805DDD4C;    /* ResetCoverCallback */
static DVDLowCallback Callback_805DDD48;
static u32 lbl_805DDD44;               /* LastLength */
static BOOL StopAtNextInt_805DDD40;

void __DVDInitWA(void)
{
    NextCommandNumber = 0;
    CommandList_8056CB40[0].command = -1;
    __DVDLowSetWAType(0, 0);
    OSInitAlarm();
}

void __DVDInterruptHandler(__OSInterrupt interrupt, OSContext* context)
{
    DVDLowCallback cb;
    OSContext exceptionContext;
    u32 cause = 0;
    u32 reg;
    u32 intr;
    u32 mask;
    DVDBuffer* prev = (DVDBuffer*)((u8*)CommandList_8056CB40 + 0xb8);
    DVDBuffer* curr = (DVDBuffer*)((u8*)CommandList_8056CB40 + 0xc4);

    if (LastCommandWasRead) {
        LastReadFinished = __OSGetSystemTime();
        FirstRead = FALSE;
        prev->addr = curr->addr;
        prev->length = curr->length;
        prev->offset = curr->offset;

        if (StopAtNextInt_805DDD40 == TRUE) {
            cause |= 8;
        }
    }

    LastCommandWasRead = FALSE;
    StopAtNextInt_805DDD40 = FALSE;
    reg = __DIRegs[0];
    mask = reg & 0x2a;
    intr = (reg & 0x54) & (mask << 1);

    if (intr & 0x40) {
        cause |= 8;
    }

    if (intr & 0x10) {
        cause |= 1;
    }

    if (intr & 4) {
        cause |= 2;
    }

    if (cause) {
        ResetOccurred_805DDD58 = FALSE;
        OSCancelAlarm((OSAlarm*)((u8*)CommandList_8056CB40 + 0x68));
    }

    __DIRegs[0] = intr | mask;

    if (ResetOccurred_805DDD58 && (__OSGetSystemTime() - LastResetEnd_805DDD50) < OSMillisecondsToTicks(200)) {
        reg = __DIRegs[1];
        mask = reg & 0x2;
        intr = (reg & 4) & (mask << 1);
        if (intr & 4) {
            if (lbl_805DDD4C != NULL) {
                lbl_805DDD4C(4);
            }
            lbl_805DDD4C = NULL;
        }

        __DIRegs[1] = __DIRegs[1];
    } else if (WaitingCoverClose_805DDD5C) {
        reg = __DIRegs[1];
        mask = reg & 2;
        intr = (reg & 4) & (mask << 1);

        if (intr & 4) {
            cause |= 4;
        }

        __DIRegs[1] = intr | mask;
        WaitingCoverClose_805DDD5C = FALSE;
    } else {
        __DIRegs[1] = 0;
    }

    if ((cause & 8) && !lbl_805DDD60) {
        cause &= ~8;
    }

    if (cause & 1) {
        s32 n = NextCommandNumber;

        if (CommandList_8056CB40[n].command == 1) {
            NextCommandNumber++;
            fn_803C4470(CommandList_8056CB40[n].address, CommandList_8056CB40[n].length,
                        CommandList_8056CB40[n].offset, CommandList_8056CB40[n].callback);
            return;
        } else if (CommandList_8056CB40[n].command == 2) {
            NextCommandNumber++;
            DVDLowSeek(CommandList_8056CB40[n].offset, CommandList_8056CB40[n].callback);
            return;
        }
    } else {
        CommandList_8056CB40[0].command = -1;
        NextCommandNumber = 0;
    }

    OSClearContext(&exceptionContext);
    OSSetCurrentContext(&exceptionContext);

    if (cause) {
        cb = Callback_805DDD48;
        Callback_805DDD48 = NULL;
        if (cb != NULL) {
            cb(cause);
        }

        lbl_805DDD60 = FALSE;
    }

    OSClearContext(&exceptionContext);
    OSSetCurrentContext(context);
}

void fn_803C437C(void)
{
    s32 n = NextCommandNumber;

    if (CommandList_8056CB40[n].command == 1) {
        NextCommandNumber++;
        fn_803C4470(CommandList_8056CB40[n].address, CommandList_8056CB40[n].length, CommandList_8056CB40[n].offset,
                    CommandList_8056CB40[n].callback);
    } else if (CommandList_8056CB40[n].command == 2) {
        NextCommandNumber++;
        DVDLowSeek(CommandList_8056CB40[n].offset, CommandList_8056CB40[n].callback);
    }
}

void AlarmHandlerForTimeout_803C4400(OSAlarm* alarm, OSContext* context)
{
    DVDLowCallback cb;
    OSContext exceptionContext;

    __OSMaskInterrupts(0x400);
    OSClearContext(&exceptionContext);
    OSSetCurrentContext(&exceptionContext);
    cb = Callback_805DDD48;
    Callback_805DDD48 = NULL;
    if (cb != NULL) {
        cb(0x10);
    }

    OSClearContext(&exceptionContext);
    OSSetCurrentContext(context);
}

void fn_803C4470(void* address, u32 length, u32 offset, DVDLowCallback callback)
{
    u8* cmdBase;

    Callback_805DDD48 = callback;
    StopAtNextInt_805DDD40 = FALSE;
    LastCommandWasRead = TRUE;
    LastReadIssued = __OSGetSystemTime();

    __DIRegs[2] = 0xa8000000;
    __DIRegs[3] = offset / 4;
    __DIRegs[4] = length;
    __DIRegs[5] = (u32)address;
    __DIRegs[6] = length;
    lbl_805DDD44 = length;
    __DIRegs[7] = 3;

    cmdBase = (u8*)CommandList_8056CB40;
    if (length > 0xa00000) {
        OSCreateAlarm((OSAlarm*)(cmdBase + 0x68));
        OSSetAlarm((OSAlarm*)(cmdBase + 0x68), OSSecondsToTicks(20), AlarmHandlerForTimeout_803C4400);
    } else {
        OSCreateAlarm((OSAlarm*)(cmdBase + 0x68));
        OSSetAlarm((OSAlarm*)(cmdBase + 0x68), OSSecondsToTicks(10), AlarmHandlerForTimeout_803C4400);
    }
}

void fn_803C4580(void* addr, u32 length, u32 offset, DVDLowCallback callback)
{
    u32 newOffset;

    if ((offset & ~0x7FFF) == 0) {
        newOffset = 0;
    } else {
        newOffset = (offset & ~0x7FFF) + WorkAroundSeekLocation;
    }

    CommandList_8056CB40[0].command = 2;
    CommandList_8056CB40[0].offset = newOffset;
    CommandList_8056CB40[0].callback = callback;
    CommandList_8056CB40[1].command = 1;
    CommandList_8056CB40[1].address = addr;
    CommandList_8056CB40[1].length = length;
    CommandList_8056CB40[1].offset = offset;
    CommandList_8056CB40[1].callback = callback;
    CommandList_8056CB40[2].command = -1;
    NextCommandNumber = 0;
    DVDLowSeek(newOffset, callback);
}
