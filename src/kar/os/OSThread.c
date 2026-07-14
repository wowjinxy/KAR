#include "dolphin/types.h"

typedef s64 OSTime;
typedef u32 OSTick;
typedef u16 OSError;

typedef struct OSContext {
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

typedef s32 OSPriority;

typedef struct OSThread OSThread;
typedef struct OSMutex OSMutex;

typedef struct OSThreadQueue {
    OSThread* head;
    OSThread* tail;
} OSThreadQueue;

typedef struct OSThreadLink {
    OSThread* next;
    OSThread* prev;
} OSThreadLink;

typedef struct OSMutexQueue {
    OSMutex* head;
    OSMutex* tail;
} OSMutexQueue;

typedef struct OSMutexLink {
    OSMutex* next;
    OSMutex* prev;
} OSMutexLink;

struct OSThread {
    /* 0x000 */ OSContext context;
    /* 0x2C8 */ u16 state;
    /* 0x2CA */ u16 attr;
    /* 0x2CC */ s32 suspend;
    /* 0x2D0 */ OSPriority priority;
    /* 0x2D4 */ OSPriority base;
    /* 0x2D8 */ void* val;
    /* 0x2DC */ OSThreadQueue* queue;
    /* 0x2E0 */ OSThreadLink link;
    /* 0x2E8 */ OSThreadQueue queueJoin;
    /* 0x2F0 */ OSMutex* mutex;
    /* 0x2F4 */ OSMutexQueue queueMutex;
    /* 0x2FC */ OSThreadLink linkActive;
    /* 0x304 */ u8* stackBase;
    /* 0x308 */ u32* stackEnd;
    /* 0x30C */ s32 error;
    /* 0x310 */ void* specific[2];
};

struct OSMutex {
    /* 0x00 */ OSThreadQueue queue;
    /* 0x08 */ OSThread* thread;
    /* 0x0C */ s32 count;
    /* 0x10 */ OSMutexLink link;
};

typedef void (*OSSwitchThreadCallback)(OSThread*, OSThread*);
typedef void (*OSErrorHandler)(OSError error, OSContext* context, ...);

#define OS_THREAD_STATE_READY 1
#define OS_THREAD_STATE_RUNNING 2
#define OS_THREAD_STATE_WAITING 4
#define OS_THREAD_STATE_MORIBUND 8

#define OS_PRIORITY_MIN 0
#define OS_PRIORITY_MAX 31

#define OS_THREAD_STACK_MAGIC 0xDEADBABE

#define IsSuspended(suspend) (suspend > 0)

#define __OSFPUContext (*(OSContext**)0x800000D8)
#define __OSActiveThreadQueue (*(OSThreadQueue*)0x800000DC)
#define __OSCurrentThread (*(OSThread**)0x800000E4)

typedef struct OSSram {
    u16 checkSum;
    u16 checkSumInv;
    u32 ead0;
    u32 ead1;
    u32 counterBias;
    s8 displayOffsetH;
    u8 ntd;
    u8 language;
    u8 flags;
} OSSram;

typedef struct OSSramEx {
    u8 flashID[2][12];
    u32 wirelessKeyboardID;
    u16 wirelessPadID[4];
    u8 dvdErrorCode;
    u8 _padding0;
    u8 flashIDCheckSum[2];
    u16 gbs;
    u8 _padding1[2];
} OSSramEx;

#define SRAM_SIZE (sizeof(OSSram) + sizeof(OSSramEx))

typedef struct SramControl {
    u8 sram[SRAM_SIZE];
    u32 offset;
    BOOL enabled;
    BOOL locked;
    int sync;
    void (*callback)(void);
} SramControl;

#define ENQUEUE_THREAD(thread, queue, link) \
    do { \
        OSThread* __prev = (queue)->tail; \
        if (__prev == NULL) { \
            (queue)->head = (thread); \
        } else { \
            __prev->link.next = (thread); \
        } \
        (thread)->link.prev = __prev; \
        (thread)->link.next = 0; \
        (queue)->tail = (thread); \
    } while (0)

#define DEQUEUE_THREAD(thread, queue, link) \
    do { \
        OSThread* __next = (thread)->link.next; \
        OSThread* __prev = (thread)->link.prev; \
        if (__next == NULL) { \
            (queue)->tail = __prev; \
        } else { \
            __next->link.prev = __prev; \
        } \
        if (__prev == NULL) { \
            (queue)->head = __next; \
        } else { \
            __prev->link.next = __next; \
        } \
    } while (0)

#define ENQUEUE_THREAD_PRIO(thread, queue, link) \
    do { \
        OSThread* __prev; \
        OSThread* __next; \
        for (__next = (queue)->head; __next && (__next->priority <= (thread)->priority); __next = __next->link.next) \
            ; \
        if (__next == NULL) { \
            ENQUEUE_THREAD(thread, queue, link); \
        } else { \
            (thread)->link.next = __next; \
            __prev = __next->link.prev; \
            __next->link.prev = (thread); \
            (thread)->link.prev = __prev; \
            if (__prev == NULL) { \
                (queue)->head = (thread); \
            } else { \
                __prev->link.next = (thread); \
            } \
        } \
    } while (0)

#define DEQUEUE_HEAD(thread, queue, link) \
    do { \
        OSThread* __next = thread->link.next; \
        if (__next == NULL) { \
            (queue)->tail = 0; \
        } else { \
            __next->link.prev = 0; \
        } \
        (queue)->head = __next; \
    } while (0)

extern void* memcpy(void* dst, const void* src, u32 n);
extern BOOL OSDisableInterrupts(void);
extern BOOL OSEnableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL level);
extern void DCFlushRangeNoSync(register void* addr, register u32 nBytes);
extern void ICInvalidateRange(register void* addr, register u32 nBytes);
extern void __sync(void);

extern OSContext* OSGetCurrentContext(void);
extern void OSSetCurrentContext(register OSContext* context);
extern void OSClearContext(register OSContext* context);
extern u32 OSSaveContext(register OSContext* context);
extern void OSLoadContext(register OSContext* context);
extern void OSInitContext(OSContext* context, u32 pc, u32 sp);
extern void* OSGetStackPointer(void);
extern void OSClearStack(u8 val);

extern void OSReport(const char* msg, ...);
extern void OSPanic(const char* file, int line, const char* msg, ...);

extern int UnlockSram(int commit, u32 offset);
extern int __OSCheckDeadLock(OSThread* thread);
extern int __OSCheckMutexes(OSThread* thread);
extern void __OSUnlockAllMutex(OSThread* thread);

extern OSErrorHandler __OSErrorTable[];
extern u32 __OSFpscrEnableBits;

extern u8 _stack_end[];
extern u8 _stack_addr[];

#define OS_BASE_CACHED 0x80000000
#define OSPhysicalToCached(paddr) ((void*)((u32)(paddr) + OS_BASE_CACHED))

extern void OSInitThreadQueue(OSThreadQueue* queue);
extern void OSSleepThread(OSThreadQueue* queue);
extern void OSWakeupThread(OSThreadQueue* queue);
extern void OSExitThread(void* val);

static inline void* LockSram(u32 offset);
static inline void OSSetCurrentThread(OSThread* thread);
static inline void __OSSwitchThread(OSThread* nextThread);
static inline void SetRun(OSThread* thread);
static inline void UpdatePriority(OSThread* thread);
static inline BOOL IsMember(OSThreadQueue* queue, OSThread* thread);
static OSThread* SelectThread(int yield);

static SramControl Scb __attribute__((aligned(32)));

static inline void* LockSram(u32 offset) {
    BOOL enabled = OSDisableInterrupts();

    if (Scb.locked) {
        OSRestoreInterrupts(enabled);
        return NULL;
    }
    Scb.enabled = enabled;
    Scb.locked = TRUE;
    return &Scb.sram[offset];
}

u32 kar_osthread__near_803d96b4(void) {
    OSSram* sram;
    u32 on;

    sram = (OSSram*)LockSram(0);
    on = (sram->flags & 0x80) >> 7;
    UnlockSram(FALSE, 0);
    return on;
}

void kar_osthread__near_803d9724(u32 on) {
    OSSram* sram;

    on <<= 7;
    on &= 0x80;

    sram = (OSSram*)LockSram(0);
    if (on == (sram->flags & 0x80)) {
        UnlockSram(FALSE, 0);
        return;
    }

    sram->flags &= ~0x80;
    sram->flags |= on;
    UnlockSram(TRUE, 0);
}

u16 OSGetWirelessID(s32 chan) {
    OSSramEx* sram;
    u16 id;

    sram = (OSSramEx*)LockSram(sizeof(OSSram));
    id = sram->wirelessPadID[chan];
    UnlockSram(FALSE, sizeof(OSSram));
    return id;
}

void OSSetWirelessID(s32 chan, u16 id) {
    OSSramEx* sram;

    sram = (OSSramEx*)LockSram(sizeof(OSSram));
    if (sram->wirelessPadID[chan] != id) {
        sram->wirelessPadID[chan] = id;
        UnlockSram(TRUE, sizeof(OSSram));
        return;
    }
    UnlockSram(FALSE, sizeof(OSSram));
}

extern void __OSSystemCallVectorStart(void);
extern void __OSSystemCallVectorEnd(void);

asm void fn_803D98F8(void) {
entry __OSSystemCallVectorStart
    nofralloc
    mfspr r9, HID0
    ori r10, r9, 0x8
    mtspr HID0, r10
    isync
    sync
    mtspr HID0, r9
    rfi
entry __OSSystemCallVectorEnd
    nop
}

void __OSInitSystemCall(void) {
    void* addr = OSPhysicalToCached(0xC00);

    memcpy(addr, __OSSystemCallVectorStart, (u32)&__OSSystemCallVectorEnd - (u32)&__OSSystemCallVectorStart);
    DCFlushRangeNoSync(addr, 0x100);
    __sync();
    ICInvalidateRange(addr, 0x100);
}

void fn_803D997C(OSThread* from, OSThread* to) {}
static OSSwitchThreadCallback SwitchThreadCallback = fn_803D997C;

static inline void OSSetCurrentThread(OSThread* thread) {
    SwitchThreadCallback(__OSCurrentThread, thread);
    __OSCurrentThread = thread;
}

static OSThreadQueue RunQueue[32] __attribute__((aligned(8)));
static OSThread IdleThread;
static OSThread DefaultThread;
static OSContext IdleContext;
static volatile u32 RunQueueBits;
static volatile int RunQueueHint;
static s32 Reschedule;

void __OSThreadInit(void) {
    OSThread* thread = &DefaultThread;
    OSPriority prio;

    thread->state = OS_THREAD_STATE_RUNNING;
    thread->attr = 1;
    thread->priority = thread->base = 0x10;
    thread->suspend = 0;
    thread->val = (void*)-1;
    thread->mutex = 0;

    OSInitThreadQueue(&thread->queueJoin);
    thread->queueMutex.head = thread->queueMutex.tail = 0;

    __OSFPUContext = (OSContext*)thread;
    OSClearContext(&thread->context);
    OSSetCurrentContext(&thread->context);
    thread->stackBase = (u8*)_stack_addr;
    thread->stackEnd = (u32*)_stack_end;
    *(u32*)thread->stackEnd = OS_THREAD_STACK_MAGIC;
    OSSetCurrentThread(thread);
    OSClearStack(0);
    RunQueueBits = 0;
    RunQueueHint = 0;

    for (prio = 0; prio <= OS_PRIORITY_MAX; prio++) {
        OSInitThreadQueue(&RunQueue[prio]);
    }
    OSInitThreadQueue(&__OSActiveThreadQueue);

    ENQUEUE_THREAD(thread, (&__OSActiveThreadQueue), linkActive);

    OSClearContext(&IdleContext);
    Reschedule = 0;
}

void OSInitThreadQueue(OSThreadQueue* queue) {
    queue->head = queue->tail = 0;
}

OSThread* OSGetCurrentThread(void) {
    return __OSCurrentThread;
}

BOOL kar_osthread__near_803d9af4(OSThread* thread) {
    if (thread->suspend > 0) {
        return TRUE;
    }
    return FALSE;
}

BOOL kar_osthread__near_803d9b10(OSThread* thread) {
    return (thread->state == OS_THREAD_STATE_MORIBUND || thread->state == 0) ? TRUE : FALSE;
}

s32 OSDisableScheduler(void) {
    register BOOL enabled;
    s32 count;

    enabled = OSDisableInterrupts();
    count = Reschedule;
    Reschedule = count + 1;
    OSRestoreInterrupts(enabled);
    return count;
}

s32 OSEnableScheduler(void) {
    register BOOL enabled;
    s32 count;

    enabled = OSDisableInterrupts();
    count = Reschedule;
    Reschedule = count - 1;
    OSRestoreInterrupts(enabled);
    return count;
}

static inline void SetRun(OSThread* thread) {
    thread->queue = &RunQueue[thread->priority];
    ENQUEUE_THREAD(thread, thread->queue, link);
    RunQueueBits |= 1 << (OS_PRIORITY_MAX - thread->priority);
    RunQueueHint = 1;
}

#pragma dont_inline on
void kar_osthread__near_803d9bc4(OSThread* thread) {
    OSThreadQueue* queue;

    queue = thread->queue;

    DEQUEUE_THREAD(thread, queue, link);

    if (!queue->head) {
        RunQueueBits &= ~(1 << (OS_PRIORITY_MAX - thread->priority));
    }
    thread->queue = NULL;
}
#pragma dont_inline off

s32 __OSGetEffectivePriority(OSThread* thread) {
    s32 priority = thread->base;
    OSMutex* mutex;

    for (mutex = thread->queueMutex.head; mutex; mutex = mutex->link.next) {
        OSThread* blocked = mutex->queue.head;
        if (blocked && blocked->priority < priority) {
            priority = blocked->priority;
        }
    }
    return priority;
}

OSThread* kar_osthread__near_803d9c68(OSThread* thread, s32 priority) {
    switch (thread->state) {
    case OS_THREAD_STATE_READY:
        kar_osthread__near_803d9bc4(thread);
        thread->priority = priority;
        SetRun(thread);
        break;
    case OS_THREAD_STATE_WAITING:
        DEQUEUE_THREAD(thread, thread->queue, link);
        thread->priority = priority;

        ENQUEUE_THREAD_PRIO(thread, thread->queue, link);

        if (thread->mutex) {
            return thread->mutex->thread;
        }
        break;
    case OS_THREAD_STATE_RUNNING:
        RunQueueHint = 1;
        thread->priority = priority;
        break;
    }
    return 0;
}

static inline void UpdatePriority(OSThread* thread) {
    s32 priority;

    while (1) {
        if (thread->suspend > 0) {
            break;
        }
        priority = __OSGetEffectivePriority(thread);
        if (thread->priority == priority) {
            break;
        }
        thread = kar_osthread__near_803d9c68(thread, priority);
        if (thread == 0) {
            break;
        }
    }
}

void kar_osthread__near_803d9e28(OSThread* thread, s32 priority) {
    while (1) {
        if (thread->suspend > 0 || thread->priority <= priority) {
            break;
        }
        thread = kar_osthread__near_803d9c68(thread, priority);
        if (thread == 0) {
            break;
        }
    }
}

static inline void __OSSwitchThread(OSThread* nextThread) {
    OSSetCurrentThread(nextThread);
    OSSetCurrentContext(&nextThread->context);
    OSLoadContext(&nextThread->context);
}

static OSThread* SelectThread(int yield) {
    OSContext* currentContext;
    OSThread* currentThread;
    OSThread* nextThread;
    OSPriority priority;
    OSThreadQueue* queue;

    if (Reschedule > 0) {
        return NULL;
    }

    currentContext = OSGetCurrentContext();
    currentThread = OSGetCurrentThread();

    if (currentContext != &currentThread->context) {
        return NULL;
    }

    if (currentThread) {
        if (currentThread->state == 2) {
            if (yield == 0) {
                priority = __cntlzw(RunQueueBits);
                if (currentThread->priority <= priority) {
                    return NULL;
                }
            }
            currentThread->state = OS_THREAD_STATE_READY;
            SetRun(currentThread);
        }
        if (!(currentThread->context.state & 2) && (OSSaveContext(&currentThread->context) != 0)) {
            return NULL;
        }
    }

    if (RunQueueBits == 0) {
        OSSetCurrentThread(NULL);
        OSSetCurrentContext(&IdleContext);
        do {
            OSEnableInterrupts();
            while (RunQueueBits == 0)
                ;
            OSDisableInterrupts();
        } while (RunQueueBits == 0);
        OSClearContext(&IdleContext);
    }

    RunQueueHint = 0;
    priority = __cntlzw(RunQueueBits);

    queue = &RunQueue[priority];
    nextThread = queue->head;

    DEQUEUE_HEAD(nextThread, queue, link);

    if (!queue->head) {
        RunQueueBits &= ~(1 << (OS_PRIORITY_MAX - priority));
    }
    nextThread->queue = 0;
    nextThread->state = OS_THREAD_STATE_RUNNING;
    __OSSwitchThread(nextThread);
    return nextThread;
}

void __OSReschedule(void) {
    if (RunQueueHint != 0) {
        SelectThread(0);
    }
}

int OSCreateThread(OSThread* thread, void* (*func)(void*), void* param, void* stack, u32 stackSize, OSPriority priority, u16 attr) {
    BOOL enabled;
    u32 sp;
    int i;

    if ((priority < OS_PRIORITY_MIN) || (priority > OS_PRIORITY_MAX)) {
        return 0;
    }

    thread->state = OS_THREAD_STATE_READY;
    thread->attr = attr & 1U;
    thread->base = priority;
    thread->priority = priority;
    thread->suspend = 1;
    thread->val = (void*)-1;
    thread->mutex = 0;
    OSInitThreadQueue(&thread->queueJoin);
    OSInitThreadQueue((OSThreadQueue*)&thread->queueMutex);
    sp = (u32)stack;
    sp &= ~7;
    sp -= 8;
    ((u32*)sp)[0] = 0;
    ((u32*)sp)[1] = 0;
    OSInitContext(&thread->context, (u32)func, sp);
    thread->context.lr = (u32)OSExitThread;
    thread->context.gpr[3] = (u32)param;
    thread->stackBase = stack;
    thread->stackEnd = (void*)((u32)stack - stackSize);
    *thread->stackEnd = OS_THREAD_STACK_MAGIC;
    thread->error = 0;
    for (i = 0; i < 2; i++) {
        thread->specific[i] = NULL;
    }
    enabled = OSDisableInterrupts();

    if (__OSErrorTable[16] != NULL) {
        thread->context.srr1 |= 0x900;
        thread->context.state |= 1;
        thread->context.fpscr = (__OSFpscrEnableBits & 0xf8) | 4;
        for (i = 0; i < 32; ++i) {
            *(u64*)&thread->context.fpr[i] = (u64)0xffffffffffffffffLL;
            *(u64*)&thread->context.psf[i] = (u64)0xffffffffffffffffLL;
        }
    }

    ENQUEUE_THREAD(thread, (&__OSActiveThreadQueue), linkActive);

    OSRestoreInterrupts(enabled);
    return 1;
}

void OSExitThread(void* val) {
    BOOL enabled = OSDisableInterrupts();
    OSThread* currentThread = OSGetCurrentThread();

    OSClearContext(&currentThread->context);
    if (currentThread->attr & 1) {
        DEQUEUE_THREAD(currentThread, (&__OSActiveThreadQueue), linkActive);
        currentThread->state = 0;
    } else {
        currentThread->state = 8;
        currentThread->val = val;
    }
    __OSUnlockAllMutex(currentThread);
    OSWakeupThread(&currentThread->queueJoin);
    RunQueueHint = 1;
    if (RunQueueHint != 0) {
        SelectThread(0);
    }
    OSRestoreInterrupts(enabled);
}

void OSCancelThread(OSThread* thread) {
    BOOL enabled = OSDisableInterrupts();

    switch (thread->state) {
    case OS_THREAD_STATE_READY:
        if (thread->suspend <= 0) {
            kar_osthread__near_803d9bc4(thread);
        }
        break;
    case OS_THREAD_STATE_RUNNING:
        RunQueueHint = 1;
        break;
    case OS_THREAD_STATE_WAITING:
        DEQUEUE_THREAD(thread, thread->queue, link);
        thread->queue = 0;
        if ((thread->suspend <= 0) && (thread->mutex)) {
            UpdatePriority(thread->mutex->thread);
        }
        break;
    default:
        OSRestoreInterrupts(enabled);
        return;
    }
    OSClearContext(&thread->context);
    if (thread->attr & 1) {
        DEQUEUE_THREAD(thread, (&__OSActiveThreadQueue), linkActive);
        thread->state = 0;
    } else {
        thread->state = 8;
    }
    __OSUnlockAllMutex(thread);
    OSWakeupThread(&thread->queueJoin);
    __OSReschedule();
    OSRestoreInterrupts(enabled);
}

int kar_osthread__near_803da558(OSThread* thread, void* val) {
    BOOL enabled = OSDisableInterrupts();

    if (!(thread->attr & 1) && (thread->state != OS_THREAD_STATE_MORIBUND) && (thread->queueJoin.head == NULL)) {
        OSThread* active;
        BOOL isActive;

        OSSleepThread(&thread->queueJoin);

        isActive = FALSE;
        if (thread->state != 0) {
            for (active = __OSActiveThreadQueue.head; active; active = active->linkActive.next) {
                if (thread == active) {
                    isActive = TRUE;
                    break;
                }
            }
        }
        if (isActive == 0) {
            OSRestoreInterrupts(enabled);
            return 0;
        }
    }
    if (thread->state == OS_THREAD_STATE_MORIBUND) {
        if (val) {
            *(s32*)val = (s32)thread->val;
        }
        DEQUEUE_THREAD(thread, (&__OSActiveThreadQueue), linkActive);
        thread->state = 0;
        OSRestoreInterrupts(enabled);
        return 1;
    }
    OSRestoreInterrupts(enabled);
    return 0;
}

s32 OSResumeThread(OSThread* thread) {
    BOOL enabled = OSDisableInterrupts();
    s32 suspendCount;

    suspendCount = thread->suspend--;
    if (thread->suspend < 0) {
        thread->suspend = 0;
    } else if (thread->suspend == 0) {
        switch (thread->state) {
        case OS_THREAD_STATE_READY:
            thread->priority = __OSGetEffectivePriority(thread);
            SetRun(thread);
            break;
        case OS_THREAD_STATE_WAITING:
            DEQUEUE_THREAD(thread, thread->queue, link);
            thread->priority = __OSGetEffectivePriority(thread);
            ENQUEUE_THREAD_PRIO(thread, thread->queue, link);
            if (thread->mutex) {
                UpdatePriority(thread->mutex->thread);
            }
        }
        __OSReschedule();
    }
    OSRestoreInterrupts(enabled);
    return suspendCount;
}

s32 OSSuspendThread(OSThread* thread) {
    BOOL enabled = OSDisableInterrupts();
    s32 suspendCount;

    suspendCount = thread->suspend++;
    if (suspendCount == 0) {
        switch (thread->state) {
        case OS_THREAD_STATE_RUNNING:
            RunQueueHint = 1;
            thread->state = 1;
            break;
        case OS_THREAD_STATE_READY:
            kar_osthread__near_803d9bc4(thread);
            break;
        case OS_THREAD_STATE_WAITING:
            DEQUEUE_THREAD(thread, thread->queue, link);
            thread->priority = 0x20;
            ENQUEUE_THREAD(thread, thread->queue, link);
            if (thread->mutex) {
                UpdatePriority(thread->mutex->thread);
            }
            break;
        }
        __OSReschedule();
    }
    OSRestoreInterrupts(enabled);
    return suspendCount;
}

void OSSleepThread(OSThreadQueue* queue) {
    BOOL enabled = OSDisableInterrupts();
    OSThread* currentThread = OSGetCurrentThread();

    currentThread->state = OS_THREAD_STATE_WAITING;
    currentThread->queue = queue;
    ENQUEUE_THREAD_PRIO(currentThread, queue, link);
    RunQueueHint = 1;
    __OSReschedule();
    OSRestoreInterrupts(enabled);
}

void OSWakeupThread(OSThreadQueue* queue) {
    BOOL enabled = OSDisableInterrupts();

    while (queue->head) {
        OSThread* thread = queue->head;

        DEQUEUE_HEAD(thread, queue, link);

        thread->state = OS_THREAD_STATE_READY;
        if (thread->suspend <= 0) {
            SetRun(thread);
        }
    }
    __OSReschedule();
    OSRestoreInterrupts(enabled);
}

int kar_osthread__near_803dac80(OSThreadQueue* queue) {
    OSThread* thread;

    if ((queue->head != NULL) && (queue->head->link.prev != NULL)) {
        return 0;
    }
    if ((queue->tail != NULL) && (queue->tail->link.next != NULL)) {
        return 0;
    }
    thread = queue->head;
    while (thread) {
        if ((thread->link.next != NULL) && (thread != thread->link.next->link.prev)) {
            return 0;
        }
        if ((thread->link.prev != NULL) && (thread != thread->link.prev->link.next)) {
            return 0;
        }
        thread = thread->link.next;
    }
    return 1;
}

static inline BOOL IsMember(OSThreadQueue* queue, OSThread* thread) {
    OSThread* member = queue->head;

    while (member) {
        if (thread == member) {
            return TRUE;
        }
        member = member->link.next;
    }
    return FALSE;
}

#define ASSERTREPORT(line, cond) \
    if (!(cond)) { \
        OSReport("OSCheckActiveThreads: Failed " #cond " in %d\n", line); \
        OSPanic(__FILE__, line, ""); \
    }

s32 kar_osthread__803dad1c(void) {
    OSThread* thread;
    s32 prio;
    s32 cThread;
    BOOL enabled;

    cThread = 0;
    enabled = OSDisableInterrupts();

    for (prio = 0; prio <= OS_PRIORITY_MAX; prio++) {
        if (RunQueueBits & (1 << (OS_PRIORITY_MAX - prio))) {
            ASSERTREPORT(1476, RunQueue[prio].head != NULL && RunQueue[prio].tail != NULL);
        } else {
            ASSERTREPORT(1481, RunQueue[prio].head == NULL && RunQueue[prio].tail == NULL);
        }
        ASSERTREPORT(1483, kar_osthread__near_803dac80(&RunQueue[prio]));
    }

    ASSERTREPORT(1488, __OSActiveThreadQueue.head == NULL || __OSActiveThreadQueue.head->linkActive.prev == NULL);
    ASSERTREPORT(1490, __OSActiveThreadQueue.tail == NULL || __OSActiveThreadQueue.tail->linkActive.next == NULL);

    thread = __OSActiveThreadQueue.head;
    while (thread) {
        cThread++;
        ASSERTREPORT(1498, thread->linkActive.next == NULL || thread == thread->linkActive.next->linkActive.prev);
        ASSERTREPORT(1500, thread->linkActive.prev == NULL || thread == thread->linkActive.prev->linkActive.next);
        ASSERTREPORT(1503, *(thread->stackEnd) == OS_THREAD_STACK_MAGIC);
        ASSERTREPORT(1506, OS_PRIORITY_MIN <= thread->priority && thread->priority <= OS_PRIORITY_MAX + 1);
        ASSERTREPORT(1507, 0 <= thread->suspend);
        ASSERTREPORT(1508, kar_osthread__near_803dac80(&thread->queueJoin));

        switch (thread->state) {
        case OS_THREAD_STATE_READY:
            if (thread->suspend <= 0) {
                ASSERTREPORT(1514, thread->queue == &RunQueue[thread->priority]);
                ASSERTREPORT(1515, IsMember(&RunQueue[thread->priority], thread));
                ASSERTREPORT(1516, thread->priority == __OSGetEffectivePriority(thread));
            }
            break;
        case OS_THREAD_STATE_RUNNING:
            ASSERTREPORT(1520, !IsSuspended(thread->suspend));
            ASSERTREPORT(1521, thread->queue == NULL);
            ASSERTREPORT(1522, thread->priority == __OSGetEffectivePriority(thread));
            break;
        case OS_THREAD_STATE_WAITING:
            ASSERTREPORT(1525, thread->queue != NULL);
            ASSERTREPORT(1526, kar_osthread__near_803dac80(thread->queue));
            ASSERTREPORT(1527, IsMember(thread->queue, thread));
            if (thread->suspend <= 0) {
                ASSERTREPORT(1530, thread->priority == __OSGetEffectivePriority(thread));
            } else {
                ASSERTREPORT(1534, thread->priority == 32);
            }
            ASSERTREPORT(1536, !__OSCheckDeadLock(thread));
            break;
        case OS_THREAD_STATE_MORIBUND:
            ASSERTREPORT(1540, thread->queueMutex.head == NULL && thread->queueMutex.tail == NULL);
            break;
        default:
            OSReport("OSCheckActiveThreads: Failed. unkown thread state (%d) of thread %p\n", thread->state, thread);
            OSPanic(__FILE__, 1546, "");
        }
        ASSERTREPORT(1551, __OSCheckMutexes(thread));
        thread = thread->linkActive.next;
    }
    OSRestoreInterrupts(enabled);
    return cThread;
}
