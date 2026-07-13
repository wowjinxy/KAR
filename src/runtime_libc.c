#include "dolphin/types.h"
#include "stdarg.h"

typedef struct ThrowContext ThrowContext;
typedef struct MWExceptionInfo MWExceptionInfo;

asm void ExPPC_UnwindStack(register ThrowContext* context)
{
    nofralloc
    mflr r5
    mfcr r6
    stw r5, 0x0(r3)
    stw r6, 0x4(r3)
    stw r1, 0x8(r3)
    stw r2, 0xc(r3)
    stmw r13, 0x14(r3)
    mffs f0
    stfd f14, 0x60(r3)
    addi r4, r3, 0x68
    psq_stx f14, r0, r4, 0, 0
    stfd f15, 0x70(r3)
    addi r4, r3, 0x78
    psq_stx f15, r0, r4, 0, 0
    stfd f16, 0x80(r3)
    addi r4, r3, 0x88
    psq_stx f16, r0, r4, 0, 0
    stfd f17, 0x90(r3)
    addi r4, r3, 0x98
    psq_stx f17, r0, r4, 0, 0
    stfd f18, 0xa0(r3)
    addi r4, r3, 0xa8
    psq_stx f18, r0, r4, 0, 0
    stfd f19, 0xb0(r3)
    addi r4, r3, 0xb8
    psq_stx f19, r0, r4, 0, 0
    stfd f20, 0xc0(r3)
    addi r4, r3, 0xc8
    psq_stx f20, r0, r4, 0, 0
    stfd f21, 0xd0(r3)
    addi r4, r3, 0xd8
    psq_stx f21, r0, r4, 0, 0
    stfd f22, 0xe0(r3)
    addi r4, r3, 0xe8
    psq_stx f22, r0, r4, 0, 0
    stfd f23, 0xf0(r3)
    addi r4, r3, 0xf8
    psq_stx f23, r0, r4, 0, 0
    stfd f24, 0x100(r3)
    addi r4, r3, 0x108
    psq_stx f24, r0, r4, 0, 0
    stfd f25, 0x110(r3)
    addi r4, r3, 0x118
    psq_stx f25, r0, r4, 0, 0
    stfd f26, 0x120(r3)
    addi r4, r3, 0x128
    psq_stx f26, r0, r4, 0, 0
    stfd f27, 0x130(r3)
    addi r4, r3, 0x138
    psq_stx f27, r0, r4, 0, 0
    stfd f28, 0x140(r3)
    addi r4, r3, 0x148
    psq_stx f28, r0, r4, 0, 0
    stfd f29, 0x150(r3)
    addi r4, r3, 0x158
    psq_stx f29, r0, r4, 0, 0
    stfd f30, 0x160(r3)
    addi r4, r3, 0x168
    psq_stx f30, r0, r4, 0, 0
    stfd f31, 0x170(r3)
    addi r4, r3, 0x178
    psq_stx f31, r0, r4, 0, 0
    stfd f0, 0x180(r3)
    li r3, 0
    blr
}

asm void ExPPC_IsInSpecification(register ThrowContext* context, register int rc)
{
    nofralloc
    lwz r5, 0x0(r3)
    lwz r6, 0x4(r3)
    mtlr r5
    mtcrf 255, r6
    lwz r1, 0x8(r3)
    lwz r2, 0xc(r3)
    lmw r13, 0x14(r3)
    lfd f14, 0x60(r3)
    addi r7, r3, 0x68
    psq_lx f14, r0, r7, 0, 0
    lfd f15, 0x70(r3)
    addi r7, r3, 0x78
    psq_lx f15, r0, r7, 0, 0
    lfd f16, 0x80(r3)
    addi r7, r3, 0x88
    psq_lx f16, r0, r7, 0, 0
    lfd f17, 0x90(r3)
    addi r7, r3, 0x98
    psq_lx f17, r0, r7, 0, 0
    lfd f18, 0xa0(r3)
    addi r7, r3, 0xa8
    psq_lx f18, r0, r7, 0, 0
    lfd f19, 0xb0(r3)
    addi r7, r3, 0xb8
    psq_lx f19, r0, r7, 0, 0
    lfd f20, 0xc0(r3)
    addi r7, r3, 0xc8
    psq_lx f20, r0, r7, 0, 0
    lfd f21, 0xd0(r3)
    addi r7, r3, 0xd8
    psq_lx f21, r0, r7, 0, 0
    lfd f22, 0xe0(r3)
    addi r7, r3, 0xe8
    psq_lx f22, r0, r7, 0, 0
    lfd f23, 0xf0(r3)
    addi r7, r3, 0xf8
    psq_lx f23, r0, r7, 0, 0
    lfd f24, 0x100(r3)
    addi r7, r3, 0x108
    psq_lx f24, r0, r7, 0, 0
    lfd f25, 0x110(r3)
    addi r7, r3, 0x118
    psq_lx f25, r0, r7, 0, 0
    lfd f26, 0x120(r3)
    addi r7, r3, 0x128
    psq_lx f26, r0, r7, 0, 0
    lfd f27, 0x130(r3)
    addi r7, r3, 0x138
    psq_lx f27, r0, r7, 0, 0
    lfd f28, 0x140(r3)
    addi r7, r3, 0x148
    psq_lx f28, r0, r7, 0, 0
    lfd f29, 0x150(r3)
    addi r7, r3, 0x158
    psq_lx f29, r0, r7, 0, 0
    lfd f30, 0x160(r3)
    addi r7, r3, 0x168
    psq_lx f30, r0, r7, 0, 0
    lfd f31, 0x170(r3)
    addi r7, r3, 0x178
    psq_lx f31, r0, r7, 0, 0
    lfd f0, 0x180(r3)
    cmpwi r4, 0
    mr r3, r4
    mtfsf 255, f0
    bnelr
    li r3, 1
    blr
}

asm void ExPPC_LongJump(register MWExceptionInfo* info, register int rc)
{
    nofralloc
    mr r8, r5
    mr r2, r4
    lwz r0, 0x280(r3)
    mtcrf 255, r0
    lmw r13, 0x234(r3)
    addi r7, r3, 0xe8
    psq_lx f14, r0, r7, 0, 0
    lfd f14, 0xe0(r3)
    addi r7, r3, 0xf8
    psq_lx f15, r0, r7, 0, 0
    lfd f15, 0xf0(r3)
    addi r7, r3, 0x108
    psq_lx f16, r0, r7, 0, 0
    lfd f16, 0x100(r3)
    addi r7, r3, 0x118
    psq_lx f17, r0, r7, 0, 0
    lfd f17, 0x110(r3)
    addi r7, r3, 0x128
    psq_lx f18, r0, r7, 0, 0
    lfd f18, 0x120(r3)
    addi r7, r3, 0x138
    psq_lx f19, r0, r7, 0, 0
    lfd f19, 0x130(r3)
    addi r7, r3, 0x148
    psq_lx f20, r0, r7, 0, 0
    lfd f20, 0x140(r3)
    addi r7, r3, 0x158
    psq_lx f21, r0, r7, 0, 0
    lfd f21, 0x150(r3)
    addi r7, r3, 0x168
    psq_lx f22, r0, r7, 0, 0
    lfd f22, 0x160(r3)
    addi r7, r3, 0x178
    psq_lx f23, r0, r7, 0, 0
    lfd f23, 0x170(r3)
    addi r7, r3, 0x188
    psq_lx f24, r0, r7, 0, 0
    lfd f24, 0x180(r3)
    addi r7, r3, 0x198
    psq_lx f25, r0, r7, 0, 0
    lfd f25, 0x190(r3)
    addi r7, r3, 0x1a8
    psq_lx f26, r0, r7, 0, 0
    lfd f26, 0x1a0(r3)
    addi r7, r3, 0x1b8
    psq_lx f27, r0, r7, 0, 0
    lfd f27, 0x1b0(r3)
    addi r7, r3, 0x1c8
    psq_lx f28, r0, r7, 0, 0
    lfd f28, 0x1c0(r3)
    addi r7, r3, 0x1d8
    psq_lx f29, r0, r7, 0, 0
    lfd f29, 0x1d0(r3)
    addi r7, r3, 0x1e8
    psq_lx f30, r0, r7, 0, 0
    lfd f30, 0x1e0(r3)
    addi r7, r3, 0x1f8
    psq_lx f31, r0, r7, 0, 0
    lfd f31, 0x1f0(r3)
    mtlr r8
    lwz r1, 0x28c(r3)
    lwz r3, 0x284(r3)
    lwz r3, 0x0(r3)
    stw r3, 0x0(r1)
    blr
}

typedef struct __eti_init_info {
    void* eti_start;
    void* eti_end;
    void* code_start;
    unsigned long code_size;
} __eti_init_info;

typedef struct ProcessInfo {
    __eti_init_info* exception_info;
    char* TOC;
    int active;
} ProcessInfo;

static ProcessInfo fragmentinfo_80569A00[1];

void __unregister_fragment(int fragmentID)
{
    ProcessInfo* f;
    if (fragmentID >= 0 && fragmentID < 1) {
        f = &fragmentinfo_80569A00[fragmentID];
        f->exception_info = 0;
        f->TOC = 0;
        f->active = 0;
    }
}

int __register_fragment(__eti_init_info* info, char* TOC)
{
    ProcessInfo* f;
    int i;

    for (i = 0, f = fragmentinfo_80569A00; i < 1; ++i, ++f) {
        if (f->active == 0) {
            f->exception_info = info;
            f->TOC = TOC;
            f->active = 1;
            return i;
        }
    }

    return -1;
}

void __begin_critical_region();
void __end_critical_region();
void __kill_critical_regions();

extern void* memcpy(void* dst, const void* src, size_t n);
extern void* memchr(const void* str, int c, size_t len);
extern int memcmp(const void* str1, const void* str2, size_t len);
extern void* memmove(void* dst, const void* src, size_t len);
extern char* strcpy(char* dst, const char* src);
extern char* strcat(char* dest, const char* src);
extern char* strncpy(char* dst, const char* src, unsigned long n);
extern int strcmp(const char* str1, const char* str2);
extern int strncmp(const char* str1, const char* str2, unsigned long n);
extern char* strchr(const char* str, int chr);
extern unsigned long strlen(const char* s);

extern char lbl_8048B698[];

const char* fn_803AF878(void)
{
    return lbl_8048B698;
}

extern void* OSGetArenaLo(void);
extern void* OSGetArenaHi(void);
extern void OSSetArenaLo(void* newLo);
extern void* OSInitAlloc(void* arenaStart, void* arenaEnd, int maxHeaps);
extern int OSCreateHeap(void* start, void* end);
extern void OSSetCurrentHeap(int heap);
extern void OSFreeToHeap(int heap, void* ptr);
extern void OSReport(const char* msg, ...);

extern s32 lbl_805DC978;
extern char lbl_8048B6B8[];
extern char lbl_8048B6F0[];

void kar_diag__803af884(void* ptr)
{
    void* lo;
    void* hi;
    s32 heap;

    if (lbl_805DC978 == -1) {
        OSReport(lbl_8048B6B8);
        OSReport(lbl_8048B6F0);
        lo = OSGetArenaLo();
        hi = OSGetArenaHi();
        lo = OSInitAlloc(lo, hi, 1);
        OSSetArenaLo(lo);
        hi = (void*) (((u32) hi) & ~0x1F);
        lo = (void*) ((((u32) lo) + 0x1F) & ~0x1F);
        heap = OSCreateHeap(lo, hi);
        OSSetCurrentHeap(heap);
        OSSetArenaLo(hi);
    }

    OSFreeToHeap(lbl_805DC978, ptr);
}

extern void _ExitProcess(void);
extern void __destroy_global_chain(void);
extern void (*_dtors[])(void);
extern void (*__atexit_funcs[64])(void);

static BOOL __aborting;
static s32 __atexit_curr_func;
static void (*__stdio_exit)(void);
static void (*__console_exit)(void);

extern int fn_803B7CD0(int sig);

#pragma push
#pragma dont_inline on
void exit(int code)
{
    void (**dtor)(void);

    if (__aborting == 0) {
        __begin_critical_region(0);
        __end_critical_region(0);
        __destroy_global_chain();
        dtor = _dtors;
        while (*dtor != NULL) {
            (*dtor)();
            dtor++;
        }
        if (__stdio_exit != NULL) {
            __stdio_exit();
            __stdio_exit = NULL;
        }
    }

    __begin_critical_region(0);
    while (__atexit_curr_func > 0) {
        __atexit_funcs[--__atexit_curr_func]();
    }
    __end_critical_region(0);
    __kill_critical_regions();
    if (__console_exit != NULL) {
        __console_exit();
        __console_exit = NULL;
    }
    _ExitProcess();
}
#pragma pop

void abort(void)
{
    fn_803B7CD0(1);
    __aborting = 1;
    __begin_critical_region(0);
    while (__atexit_curr_func > 0) {
        __atexit_funcs[--__atexit_curr_func]();
    }
    __end_critical_region(0);
    __kill_critical_regions();
    if (__console_exit != NULL) {
        __console_exit();
        __console_exit = NULL;
    }
    _ExitProcess();
}

int abs(int j)
{
    return (j < 0) ? -j : j;
}

typedef struct {
    unsigned short open_mode : 2;
    unsigned short io_mode : 3;
    unsigned short buffer_mode : 2;
    unsigned short file_kind : 3;
    unsigned short file_orientation : 2;
    unsigned short binary_io : 1;
} __file_modes;

typedef struct {
    unsigned short io_state : 3;
    unsigned short free_buffer : 1;
    unsigned char eof;
    unsigned char error;
} __file_state;

typedef unsigned short __wchar_t;
typedef unsigned long __file_handle;
typedef unsigned long fpos_t;
typedef void (*__idle_proc)(void);
typedef int (*__pos_proc)(__file_handle file, fpos_t* position, int mode,
                          __idle_proc idle_proc);
typedef int (*__io_proc)(__file_handle file, unsigned char* buff,
                         size_t* count, __idle_proc idle_proc);
typedef int (*__close_proc)(__file_handle file);

typedef struct _IO_FILE {
    __file_handle handle;
    __file_modes mode;
    __file_state state;
    unsigned char char_buffer;
    unsigned char char_buffer_overflow;
    unsigned char ungetc_buffer[4];
    __wchar_t ungetwc_buffer[4];
    unsigned long position;
    unsigned char* buffer;
    unsigned long buffer_size;
    unsigned char* buffer_ptr;
    unsigned long buffer_len;
    unsigned long buffer_alignment;
    unsigned long saved_buffer_len;
    unsigned long buffer_pos;
    __pos_proc position_proc;
    __io_proc read_proc;
    __io_proc write_proc;
    __close_proc close_proc;
    __idle_proc idle_proc;
    struct _IO_FILE* next;
} FILE;

void __prep_buffer(FILE* file)
{
    file->buffer_ptr = file->buffer;
    file->buffer_len = file->buffer_size;
    file->buffer_len -= file->position & file->buffer_alignment;
    file->buffer_pos = file->position;
}

int __flush_buffer(FILE* file, size_t* bytes_flushed)
{
    size_t len;
    int res;

    len = file->buffer_ptr - file->buffer;
    if (len != 0) {
        file->buffer_len = len;
        res = file->write_proc(file->handle, file->buffer, &file->buffer_len,
                               file->idle_proc);
        if (bytes_flushed != NULL) {
            *bytes_flushed = file->buffer_len;
        }
        if (res != 0) {
            return res;
        }
        file->position += file->buffer_len;
    }

    __prep_buffer(file);
    return 0;
}

#pragma dont_inline on

void __end_critical_region()
{
    return;
}

void __begin_critical_region()
{
    return;
}

void __kill_critical_regions()
{
    return;
}

#pragma dont_inline reset

extern const unsigned char lbl_804F8BF0[256];

int fn_803B3870(int c)
{
    if (c == -1) {
        return -1;
    }
    return lbl_804F8BF0[c & 0xFF];
}

extern const unsigned char lbl_804F8AF0[256];

int fn_803B3894(int c)
{
    return (int) (lbl_804F8AF0[(unsigned char) c] & 0x20);
}

int fn_803B38AC(int c)
{
    return (int) (lbl_804F8AF0[(unsigned char) c] & 0x10);
}

int fn_803B38C4(int c)
{
    return (int) (lbl_804F8AF0[(unsigned char) c] & 0xC0);
}

extern int __fwrite(const void* buffer, size_t memb_size, size_t num_memb,
                    FILE* file);

#pragma push
#pragma dont_inline on
size_t fwrite(const void* buffer, size_t memb_size, size_t num_memb,
              FILE* file)
{
    size_t res;
    __begin_critical_region(2);
    res = __fwrite(buffer, memb_size, num_memb, file);
    __end_critical_region(2);
    return res;
}
#pragma pop

extern int fn_803B4068(FILE* file, long offset, int mode);

int fseek(FILE* file, long offset, int mode)
{
    int res;
    __begin_critical_region(2);
    res = fn_803B4068(file, offset, mode);
    __end_critical_region(2);
    return res;
}

extern u32 lbl_805E5198;

size_t wcstombs(char* dest, const __wchar_t* src, size_t max)
{
    size_t i;

    if (dest == NULL || src == NULL) {
        return 0;
    }

    i = 0;
    while (i <= max) {
        __wchar_t wc = *src;
        int len;
        unsigned char buf[3];

        if (wc == 0) {
            dest[i] = 0;
            return i;
        }
        src++;

        if (wc < 128) {
            len = 1;
        } else if (wc < 2048) {
            len = 2;
        } else {
            len = 3;
        }

        if (i + len > max) {
            break;
        }

        {
            u32 lead_table = lbl_805E5198;
            u32 v = wc;
            unsigned char* p = buf + len;

            if (len == 3) {
                *--p = 0x80 | (v & 0x3F);
                v >>= 6;
            }
            if (len >= 2) {
                *--p = 0x80 | (v & 0x3F);
                v >>= 6;
            }
            *--p = (unsigned char) (v | ((unsigned char*) &lead_table)[len]);
        }

        strncpy(dest + i, (char*) buf, len);
        i += len;
    }

    return i;
}

int memcmp(const void* str1, const void* str2, size_t len)
{
    const u8* s1 = ((const u8*) str1) - 1;
    const u8* s2 = ((const u8*) str2) - 1;
    len++;

    while (--len > 0) {
        if (*++s1 != *++s2) {
            if (*s1 < *s2) {
                return -1;
            } else {
                return 1;
            }
        }
    }

    return 0;
}

void* __memrchr(const void* str, int c, size_t len)
{
    u8 val = (u8) c;
    const u8* p = (const u8*) str + len;
    len++;

    while (--len > 0) {
        if (*--p == val) {
            return (void*) p;
        }
    }

    return NULL;
}

void* memchr(const void* str, int c, size_t len)
{
    u8 val = (u8) c;
    u8* p = ((u8*) str) - 1;
    len++;

    while (--len > 0) {
        if (*++p == val) {
            return p;
        }
    }

    return NULL;
}

#define cps ((unsigned char*) src)
#define cpd ((unsigned char*) dst)
#define lps ((unsigned long*) src)
#define lpd ((unsigned long*) dst)
#define deref_auto_inc(p) *++(p)

extern void __copy_longs_aligned(void* dst, const void* src, size_t n);
extern void __copy_longs_rev_aligned(void* dst, const void* src, size_t n);
extern void __copy_longs_unaligned(void* dst, const void* src, size_t n);
extern void __copy_longs_rev_unaligned(void* dst, const void* src, size_t n);

void* memmove(void* dst, const void* src, size_t len)
{
    u8* csrc;
    u8* cdst;

    int reverse = (u32) src < (u32) dst;

    if (len >= 32) {
        if (((u32) dst ^ (u32) src) & 3) {
            if (!reverse) {
                __copy_longs_unaligned(dst, src, len);
            } else {
                __copy_longs_rev_unaligned(dst, src, len);
            }
        } else {
            if (!reverse) {
                __copy_longs_aligned(dst, src, len);
            } else {
                __copy_longs_rev_aligned(dst, src, len);
            }
        }

        return dst;
    } else {
        if (!reverse) {
            csrc = ((u8*) src) - 1;
            cdst = ((u8*) dst) - 1;
            len++;

            while (--len > 0) {
                *++cdst = *++csrc;
            }
        } else {
            csrc = (u8*) src + len;
            cdst = (u8*) dst + len;
            len++;

            while (--len > 0) {
                *--cdst = *--csrc;
            }
        }
    }

    return dst;
}

void __copy_longs_rev_unaligned(void* dst, const void* src, size_t n)
{
    unsigned long i, v1, v2;
    unsigned int src_offset, left_shift, right_shift;

    cps = ((unsigned char*) src) + n;
    cpd = ((unsigned char*) dst) + n;

    i = ((unsigned long) cpd) & 3;

    if (i) {
        n -= i;

        do {
            *--cpd = *--cps;
        } while (--i);
    }

    src_offset = ((unsigned int) cps) & 3;

    left_shift = src_offset << 3;
    right_shift = 32 - left_shift;

    cps += 4 - src_offset;

    i = n >> 3;

    v1 = *--lps;

    do {
        v2 = *--lps;
        *--lpd = (v2 << left_shift) | (v1 >> right_shift);
        v1 = *--lps;
        *--lpd = (v1 << left_shift) | (v2 >> right_shift);
    } while (--i);

    if (n & 4) {
        v2 = *--lps;
        *--lpd = (v2 << left_shift) | (v1 >> right_shift);
    }

    n &= 3;

    if (n) {
        cps += src_offset;
        do {
            *--cpd = *--cps;
        } while (--n);
    }

    return;
}

void __copy_longs_unaligned(void* dst, const void* src, size_t n)
{
    unsigned long i, v1, v2;
    unsigned int src_offset, left_shift, right_shift;

    i = (-(unsigned long) dst) & 3;

    cps = ((unsigned char*) src) - 1;
    cpd = ((unsigned char*) dst) - 1;

    if (i) {
        n -= i;

        do {
            deref_auto_inc(cpd) = deref_auto_inc(cps);
        } while (--i);
    }

    src_offset = ((unsigned int) (cps + 1)) & 3;

    left_shift = src_offset << 3;
    right_shift = 32 - left_shift;

    cps -= src_offset;

    lps = ((unsigned long*) (cps + 1)) - 1;
    lpd = ((unsigned long*) (cpd + 1)) - 1;

    i = n >> 3;

    v1 = deref_auto_inc(lps);

    do {
        v2 = deref_auto_inc(lps);
        deref_auto_inc(lpd) = (v1 << left_shift) | (v2 >> right_shift);
        v1 = deref_auto_inc(lps);
        deref_auto_inc(lpd) = (v2 << left_shift) | (v1 >> right_shift);
    } while (--i);

    if (n & 4) {
        v2 = deref_auto_inc(lps);
        deref_auto_inc(lpd) = (v1 << left_shift) | (v2 >> right_shift);
    }

    cps = ((unsigned char*) (lps + 1)) - 1;
    cpd = ((unsigned char*) (lpd + 1)) - 1;

    n &= 3;

    if (n) {
        cps -= 4 - src_offset;
        do {
            deref_auto_inc(cpd) = deref_auto_inc(cps);
        } while (--n);
    }

    return;
}

void __copy_longs_rev_aligned(void* dst, const void* src, size_t n)
{
    unsigned long i;

    cps = ((unsigned char*) src) + n;
    cpd = ((unsigned char*) dst) + n;

    i = ((unsigned long) cpd) & 3;

    if (i) {
        n -= i;

        do {
            *--cpd = *--cps;
        } while (--i);
    }

    i = n >> 5;

    if (i) {
        do {
            *--lpd = *--lps;
            *--lpd = *--lps;
            *--lpd = *--lps;
            *--lpd = *--lps;
            *--lpd = *--lps;
            *--lpd = *--lps;
            *--lpd = *--lps;
            *--lpd = *--lps;
        } while (--i);
    }

    i = (n & 31) >> 2;

    if (i) {
        do {
            *--lpd = *--lps;
        } while (--i);
    }

    n &= 3;

    if (n) {
        do {
            *--cpd = *--cps;
        } while (--n);
    }

    return;
}

void __copy_longs_aligned(void* dst, const void* src, size_t n)
{
    unsigned long i;

    i = (-(unsigned long) dst) & 3;

    cps = ((unsigned char*) src) - 1;
    cpd = ((unsigned char*) dst) - 1;

    if (i) {
        n -= i;

        do {
            deref_auto_inc(cpd) = deref_auto_inc(cps);
        } while (--i);
    }

    src = ((unsigned long*) (cps + 1)) - 1;
    dst = ((unsigned long*) (cpd + 1)) - 1;

    i = n >> 5;

    if (i) {
        do {
            deref_auto_inc(lpd) = deref_auto_inc(lps);
            deref_auto_inc(lpd) = deref_auto_inc(lps);
            deref_auto_inc(lpd) = deref_auto_inc(lps);
            deref_auto_inc(lpd) = deref_auto_inc(lps);
            deref_auto_inc(lpd) = deref_auto_inc(lps);
            deref_auto_inc(lpd) = deref_auto_inc(lps);
            deref_auto_inc(lpd) = deref_auto_inc(lps);
            deref_auto_inc(lpd) = deref_auto_inc(lps);
        } while (--i);
    }

    i = (n & 31) >> 2;

    if (i) {
        do {
            deref_auto_inc(lpd) = deref_auto_inc(lps);
        } while (--i);
    }

    cps = ((unsigned char*) (lps + 1)) - 1;
    cpd = ((unsigned char*) (lpd + 1)) - 1;

    n &= 3;

    if (n) {
        do {
            deref_auto_inc(cpd) = deref_auto_inc(cps);
        } while (--n);
    }

    return;
}

extern void __close_all(void);

void __stdio_atexit(void)
{
    __stdio_exit = __close_all;
}

typedef struct {
    char* CharStr;
    size_t MaxCharCount;
    size_t CharsWritten;
} __OutStrCtrl;

enum justification_options { left_justification, right_justification, zero_fill };
enum sign_options { only_minus, sign_always, space_holder };
enum argument_options {
    normal_argument,
    char_argument,
    short_argument,
    long_argument,
    long_long_argument,
    long_double_argument,
    wchar_argument
};

typedef struct {
    unsigned char justification_options;
    unsigned char sign_options;
    unsigned char precision_specified;
    unsigned char alternate_form;
    unsigned char argument_options;
    unsigned char conversion_char;
    int field_width;
    int precision;
} print_format;

typedef struct decimal decimal;

static const char* parse_format(const char* format_string, va_list* arg,
                                print_format* format);
static char* long2str(signed long num, char* buff, print_format* format);
static char* longlong2str(signed long long num, char* pBuf,
                          print_format* format);
static char* float2str(va_list arg, char* buff, print_format* format,
                       int unused);
static int __pformatter(void* (*WriteProc)(void*, const char*, size_t),
                        void* WriteProcArg, const char* format_str,
                        va_list arg);
static void* __FileWrite(void* pFile, const char* pBuffer, size_t char_num);
static void* __StringWrite(void* pCtrl, const char* pBuffer, size_t char_num);
void fn_803B5DB4(decimal* dec, int new_length);

extern FILE __files[3];
#define stdout (&__files[1])

int fwide(FILE* stream, int mode);
size_t fwrite(const void* buffer, size_t memb_size, size_t num_memb,
              FILE* file);

int vsnprintf(char* s, size_t n, const char* format, va_list arg);

int sprintf(char* s, const char* format, ...)
{
    int end;
    va_list args;
    __OutStrCtrl osc;
    va_start(args, format);

    osc.CharStr = s;
    osc.MaxCharCount = 0xFFFFFFFF;
    osc.CharsWritten = 0;

    end = __pformatter(&__StringWrite, &osc, format, args);
    if (s != NULL) {
        s[((u32) end < 0xFFFFFFFF) ? end : 0xFFFFFFFE] = '\0';
    }
    return end;
}

int fn_803B4BA0(char* s, size_t n, const char* format, ...)
{
    int end;
    va_list args;
    __OutStrCtrl osc;
    va_start(args, format);

    osc.CharStr = s;
    osc.MaxCharCount = n;
    osc.CharsWritten = 0;

    end = __pformatter(&__StringWrite, &osc, format, args);
    if (s != NULL) {
        s[((u32) end < n) ? end : n - 1] = '\0';
    }
    return end;
}

int vsnprintf(char* s, size_t n, const char* format, va_list arg)
{
    int end;
    __OutStrCtrl osc;
    osc.CharStr = s;
    osc.MaxCharCount = n;
    osc.CharsWritten = 0;

    end = __pformatter(&__StringWrite, &osc, format, arg);
    if (s != NULL) {
        s[((u32) end < n) ? end : n - 1] = '\0';
    }
    return end;
}

int vprintf(const char* format, va_list arg)
{
    int res;
    if (fwide(stdout, -1) >= 0) {
        return -1;
    }

    __begin_critical_region(2);
    res = __pformatter(&__FileWrite, stdout, format, arg);
    __end_critical_region(2);
    return res;
}

int fn_803B4D80(FILE* stream, const char* format, ...)
{
    int res;
    va_list args;
    va_start(args, format);

    if (fwide(stream, -1) >= 0) {
        return -1;
    }

    __begin_critical_region(2);
    res = __pformatter(&__FileWrite, stream, format, args);
    __end_critical_region(2);
    return res;
}

static void* __StringWrite(void* pCtrl, const char* pBuffer, size_t char_num)
{
    size_t chars;
    __OutStrCtrl* ctrl = (__OutStrCtrl*) pCtrl;

    chars = ((ctrl->CharsWritten + char_num) <= ctrl->MaxCharCount)
                ? char_num
                : ctrl->MaxCharCount - ctrl->CharsWritten;
    memcpy(ctrl->CharStr + ctrl->CharsWritten, pBuffer, chars);
    ctrl->CharsWritten += chars;
    return (void*) 1;
}

static void* __FileWrite(void* pFile, const char* pBuffer, size_t char_num)
{
    return (fwrite(pBuffer, 1, char_num, (FILE*) pFile) == char_num ? pFile
                                                                    : 0);
}

static int __pformatter(void* (*WriteProc)(void*, const char*, size_t),
                        void* WriteProcArg, const char* format_str,
                        va_list arg)
{
    int num_chars, chars_written, field_width;
    const char* format_ptr;
    const char* curr_format;
    print_format format;
    signed long long_num;
    signed long long long_long_num;
    char buff[512];
    char* buff_ptr;
    char* string_end;
    char fill_char = ' ';

    format_ptr = format_str;
    chars_written = 0;

    while (*format_ptr) {
        if (!(curr_format = strchr(format_ptr, '%'))) {
            num_chars = strlen(format_ptr);
            chars_written += num_chars;

            if (num_chars &&
                !(*WriteProc)(WriteProcArg, format_ptr, num_chars))
            {
                return -1;
            }

            break;
        }

        num_chars = curr_format - format_ptr;
        chars_written += num_chars;

        if (num_chars && !(*WriteProc)(WriteProcArg, format_ptr, num_chars)) {
            return -1;
        }

        format_ptr = curr_format;
        format_ptr = parse_format(format_ptr, (va_list*) arg, &format);

        switch (format.conversion_char) {
        case 'd':
        case 'i':
            if (format.argument_options == long_argument) {
                long_num = va_arg(arg, signed long);
            } else if (format.argument_options == long_long_argument) {
                long_long_num = va_arg(arg, signed long long);
            } else {
                long_num = va_arg(arg, int);
            }

            if (format.argument_options == short_argument) {
                long_num = (signed short) long_num;
            }

            if (format.argument_options == char_argument) {
                long_num = (signed char) long_num;
            }

            if (format.argument_options == long_long_argument) {
                if (!(buff_ptr =
                          longlong2str(long_long_num, buff + 512, &format)))
                {
                    goto conversion_error;
                }
            } else {
                if (!(buff_ptr = long2str(long_num, buff + 512, &format))) {
                    goto conversion_error;
                }
            }

            num_chars = buff + 512 - 1 - buff_ptr;
            break;

        case 'o':
        case 'u':
        case 'x':
        case 'X':
            if (format.argument_options == long_argument) {
                long_num = va_arg(arg, unsigned long);
            } else if (format.argument_options == long_long_argument) {
                long_long_num = va_arg(arg, signed long long);
            } else {
                long_num = va_arg(arg, unsigned int);
            }

            if (format.argument_options == short_argument) {
                long_num = (unsigned short) long_num;
            }

            if (format.argument_options == char_argument) {
                long_num = (unsigned char) long_num;
            }

            if (format.argument_options == long_long_argument) {
                if (!(buff_ptr =
                          longlong2str(long_long_num, buff + 512, &format)))
                {
                    goto conversion_error;
                }
            } else {
                if (!(buff_ptr = long2str(long_num, buff + 512, &format))) {
                    goto conversion_error;
                }
            }

            num_chars = buff + 512 - 1 - buff_ptr;
            break;

        case 'f':
        case 'e':
        case 'E':
        case 'g':
        case 'G':
            if (!(buff_ptr = float2str(arg, buff + 512, &format, 0))) {
                goto conversion_error;
            }

            num_chars = buff + 512 - 1 - buff_ptr;
            break;

        case 's':
            if (format.argument_options == wchar_argument) {
                __wchar_t* wcs_ptr = va_arg(arg, __wchar_t*);

                if (wcs_ptr == NULL) {
                    wcs_ptr = (__wchar_t*) "";
                }

                if ((num_chars = wcstombs(buff, wcs_ptr, sizeof(buff))) < 0) {
                    goto conversion_error;
                }

                buff_ptr = &buff[0];
            } else {
                buff_ptr = va_arg(arg, char*);
            }

            if (buff_ptr == NULL) {
                buff_ptr = "";
            }

            if (format.alternate_form) {
                num_chars = (unsigned char) *buff_ptr++;

                if (format.precision_specified && num_chars > format.precision)
                {
                    num_chars = format.precision;
                }
            } else if (format.precision_specified) {
                num_chars = format.precision;

                if ((string_end = (char*) memchr((unsigned char*) buff_ptr, 0,
                                                 num_chars)) != 0)
                {
                    num_chars = string_end - buff_ptr;
                }
            } else {
                num_chars = strlen(buff_ptr);
            }

            break;

        case 'n':
            buff_ptr = va_arg(arg, char*);

            switch (format.argument_options) {
            case normal_argument:
                *(int*) buff_ptr = chars_written;
                break;
            case short_argument:
                *(signed short*) buff_ptr = chars_written;
                break;
            case long_argument:
                *(signed long*) buff_ptr = chars_written;
                break;
            case long_long_argument:
                *(signed long long*) buff_ptr = chars_written;
                break;
            }

            continue;

        case 'c':
            buff_ptr = buff;
            *buff_ptr = va_arg(arg, int);
            num_chars = 1;
            break;

        case '%':
            buff_ptr = buff;
            *buff_ptr = '%';
            num_chars = 1;
            break;

        case 0xFF:
        default:
        conversion_error:
            num_chars = strlen(curr_format);
            chars_written += num_chars;

            if (num_chars &&
                !(*WriteProc)(WriteProcArg, curr_format, num_chars))
            {
                return -1;
            }

            return chars_written;
            break;
        }

        field_width = num_chars;

        if (format.justification_options != left_justification) {
            fill_char =
                (format.justification_options == zero_fill) ? '0' : ' ';

            if (((*buff_ptr == '+') || (*buff_ptr == '-')) &&
                (fill_char == '0'))
            {
                if ((*WriteProc)(WriteProcArg, buff_ptr, 1) == 0) {
                    return -1;
                }

                ++buff_ptr;
                num_chars--;
            }

            while (field_width < format.field_width) {
                if ((*WriteProc)(WriteProcArg, &fill_char, 1) == 0) {
                    return -1;
                }

                ++field_width;
            }
        }

        if (num_chars && !(*WriteProc)(WriteProcArg, buff_ptr, num_chars)) {
            return -1;
        }

        if (format.justification_options == left_justification) {
            while (field_width < format.field_width) {
                char blank = ' ';

                if ((*WriteProc)(WriteProcArg, &blank, 1) == 0) {
                    return -1;
                }

                ++field_width;
            }
        }

        chars_written += field_width;
    }

    return chars_written;
}

typedef struct decimal {
    char sign;
    char unk1;
    short exp;
    struct {
        unsigned char length;
        unsigned char text[36];
        unsigned char unk41;
    } sig;
} decimal;

typedef struct decform {
    char style;
    char unk1;
    short digits;
} decform;

extern void fn_803B1114(const decform* f, double x, decimal* d);

static char* float2str(va_list arg, char* buff, print_format* format,
                       int unused)
{
    decimal dec;
    decform form;
    char* p;
    char* q;
    int n, digits, sign;
    int int_digits, frac_digits;
    double num;

    if (format->argument_options == long_double_argument) {
        num = va_arg(arg, long double);
    } else {
        num = va_arg(arg, double);
    }

    if (format->precision > 509) {
        return 0;
    }

    form.style = 0;
    form.digits = 0x20;
    fn_803B1114(&form, num, &dec);
    p = (char*) dec.sig.text + dec.sig.length;

    while (dec.sig.length > 1 && *--p == '0') {
        --dec.sig.length;
        ++dec.exp;
    }

    switch (*dec.sig.text) {
    case '0':
        dec.exp = 0;
        break;
    case 'I':
        if (num < 0) {
            p = buff - 5;
            strcpy(p, "-Inf");
        } else {
            p = buff - 4;
            strcpy(p, "Inf");
        }

        return p;

    case 'N':
        p = buff - 4;
        strcpy(p, "NaN");

        return p;
    }

    dec.exp += dec.sig.length - 1;
    p = buff;
    *--p = 0;

    switch (format->conversion_char) {
    case 'g':
    case 'G':

        if (dec.sig.length > format->precision) {
            fn_803B5DB4(&dec, format->precision);
        }

        if (dec.exp < -4 || dec.exp >= format->precision) {
            if (format->alternate_form) {
                --format->precision;
            } else {
                format->precision = dec.sig.length - 1;
            }

            if (format->conversion_char == 'g') {
                format->conversion_char = 'e';
            } else {
                format->conversion_char = 'E';
            }

            goto e_format;
        }

        if (format->alternate_form) {
            format->precision -= dec.exp + 1;
        } else {
            if ((format->precision = dec.sig.length - (dec.exp + 1)) < 0) {
                format->precision = 0;
            }
        }

        goto f_format;

    case 'e':
    case 'E':
    e_format:

        if (dec.sig.length > format->precision + 1) {
            fn_803B5DB4(&dec, format->precision + 1);
        }

        n = dec.exp;
        sign = '+';

        if (n < 0) {
            n = -n;
            sign = '-';
        }

        for (digits = 0; n || digits < 2; ++digits) {
            *--p = n % 10 + '0';
            n /= 10;
        }

        *--p = sign;
        *--p = format->conversion_char;

        if (buff - p + format->precision > 509) {
            return 0;
        }

        if (dec.sig.length < format->precision + 1) {
            for (n = format->precision + 1 - dec.sig.length + 1; --n;) {
                *--p = '0';
            }
        }

        for (n = dec.sig.length, q = (char*) dec.sig.text + dec.sig.length;
             --n;)
        {
            *--p = *--q;
        }

        if (format->precision || format->alternate_form) {
            *--p = '.';
        }

        *--p = *dec.sig.text;

        if (dec.sign) {
            *--p = '-';
        } else if (format->sign_options == sign_always) {
            *--p = '+';
        } else if (format->sign_options == space_holder) {
            *--p = ' ';
        }

        break;

    case 'f':
    f_format:

        if ((frac_digits = -dec.exp + dec.sig.length - 1) < 0) {
            frac_digits = 0;
        }

        if (frac_digits > format->precision) {
            fn_803B5DB4(&dec,
                       dec.sig.length - (frac_digits - format->precision));

            if ((frac_digits = -dec.exp + dec.sig.length - 1) < 0) {
                frac_digits = 0;
            }
        }

        if ((int_digits = dec.exp + 1) < 0) {
            int_digits = 0;
        }

        if (int_digits + frac_digits > 509) {
            return 0;
        }

        q = (char*) dec.sig.text + dec.sig.length;

        for (digits = 0; digits < (format->precision - frac_digits); ++digits)
        {
            *--p = '0';
        }

        for (digits = 0; digits < frac_digits && digits < dec.sig.length;
             ++digits)
        {
            *--p = *--q;
        }

        for (; digits < frac_digits; ++digits) {
            *--p = '0';
        }

        if (format->precision || format->alternate_form) {
            *--p = '.';
        }

        if (int_digits) {
            for (digits = 0; digits < int_digits - dec.sig.length; ++digits) {
                *--p = '0';
            }

            for (; digits < int_digits; ++digits) {
                *--p = *--q;
            }
        } else {
            *--p = '0';
        }

        if (dec.sign) {
            *--p = '-';
        } else if (format->sign_options == sign_always) {
            *--p = '+';
        } else if (format->sign_options == space_holder) {
            *--p = ' ';
        }

        break;
    }

    return p;
}

void fn_803B5DB4(decimal* dec, int new_length)
{
    char c;
    char* p;
    int carry;

    if (new_length < 0) {
    return_zero:
        dec->exp = 0;
        dec->sig.length = 1;
        *dec->sig.text = '0';
        return;
    }

    if (new_length >= dec->sig.length) {
        return;
    }

    p = (char*) dec->sig.text + new_length + 1;
    c = *--p - '0';

    if (c == 5) {
        char* q = &((char*) dec->sig.text)[dec->sig.length];

        while (--q > p && *q == '0')
            ;
        carry = (q == p) ? p[-1] & 1 : 1;
    } else {
        carry = (c > 5);
    }

    while (new_length != 0) {
        c = *--p - '0' + carry;

        if ((carry = (c > 9)) != 0 || c == 0) {
            --new_length;
        } else {
            *p = c + '0';
            break;
        }
    }

    if (carry != 0) {
        dec->exp += 1;
        dec->sig.length = 1;
        *dec->sig.text = '1';
        return;
    } else if (new_length == 0) {
        goto return_zero;
    }

    dec->sig.length = new_length;
}

static char* longlong2str(signed long long num, char* pBuf,
                          print_format* format)
{
    unsigned long long unsigned_num, base;
    char* p;
    int n, digits;
    int minus = 0;
    unsigned_num = num;
    minus = 0;
    p = pBuf;
    *--p = 0;
    digits = 0;

    if (!num && !format->precision &&
        !(format->alternate_form && format->conversion_char == 'o'))
    {
        return p;
    }

    switch (format->conversion_char) {
    case 'd':
    case 'i':
        base = 10;

        if (num < 0) {
            unsigned_num = -unsigned_num;
            minus = 1;
        }
        break;
    case 'o':
        base = 8;
        format->sign_options = only_minus;
        break;
    case 'u':
        base = 10;
        format->sign_options = only_minus;
        break;
    case 'x':
    case 'X':
        base = 16;
        format->sign_options = only_minus;
        break;
    }

    do {
        n = unsigned_num % base;
        unsigned_num /= base;

        if (n < 10) {
            n += '0';
        } else {
            n -= 10;
            if (format->conversion_char == 'x') {
                n += 'a';
            } else {
                n += 'A';
            }
        }

        *--p = n;
        ++digits;
    } while (unsigned_num != 0);

    if (base == 8 && format->alternate_form && *p != '0') {
        *--p = '0';
        ++digits;
    }

    if (format->justification_options == zero_fill) {
        format->precision = format->field_width;

        if (minus || format->sign_options != only_minus) {
            --format->precision;
        }

        if (base == 16 && format->alternate_form) {
            format->precision -= 2;
        }
    }

    if (pBuf - p + format->precision > 509) {
        return 0;
    }

    while (digits < format->precision) {
        *--p = '0';
        ++digits;
    }

    if (base == 16 && format->alternate_form) {
        *--p = format->conversion_char;
        *--p = '0';
    }

    if (minus) {
        *--p = '-';
    } else if (format->sign_options == sign_always) {
        *--p = '+';
    } else if (format->sign_options == space_holder) {
        *--p = ' ';
    }

    return p;
}

static char* long2str(signed long num, char* buff, print_format* format)
{
    unsigned long unsigned_num, base;
    char* p;
    int n, digits;
    int minus = 0;
    volatile print_format* vformat = format;
    unsigned_num = num;
    minus = 0;

    p = buff;
    *--p = 0;
    digits = 0;

    if (!num && !format->precision &&
        !(format->alternate_form && format->conversion_char == 'o'))
    {
        return p;
    }

    switch (format->conversion_char) {
    case 'd':
    case 'i':
        base = 10;

        if (num < 0) {
            unsigned_num = -unsigned_num;
            minus = 1;
        }
        break;

    case 'o':
        base = 8;
        format->sign_options = only_minus;
        break;

    case 'u':
        base = 10;
        format->sign_options = only_minus;
        break;

    case 'x':
    case 'X':
        base = 16;
        format->sign_options = only_minus;
        break;
    }

    do {
        n = unsigned_num % base;
        unsigned_num /= base;

        if (n < 10) {
            n += '0';
        } else {
            n -= 10;

            if (vformat->conversion_char == 'x') {
                n += 'a';
            } else {
                n += 'A';
            }
        }

        *--p = n;
        ++digits;
    } while (unsigned_num != 0);

    if (base == 8 && format->alternate_form && *p != '0') {
        *--p = '0';
        ++digits;
    }

    if (format->justification_options == zero_fill) {
        format->precision = format->field_width;

        if (minus || format->sign_options != only_minus) {
            --format->precision;
        }

        if (base == 16 && format->alternate_form) {
            format->precision -= 2;
        }
    }

    if (buff - p + format->precision > 509) {
        return (0);
    }

    while (digits < format->precision) {
        *--p = '0';
        ++digits;
    }

    if (base == 16 && format->alternate_form) {
        *--p = format->conversion_char;
        *--p = '0';
    }

    if (minus) {
        *--p = '-';
    } else if (format->sign_options == sign_always) {
        *--p = '+';
    } else if (format->sign_options == space_holder) {
        *--p = ' ';
    }

    return p;
}

static const char* parse_format(const char* format_string, va_list* arg,
                                print_format* format)
{
    print_format f;
    const char* s = format_string;
    int c;
    int flag_found;
    f.justification_options = right_justification;
    f.sign_options = only_minus;
    f.precision_specified = 0;
    f.alternate_form = 0;
    f.argument_options = normal_argument;
    f.field_width = 0;
    f.precision = 0;

    if ((c = *++s) == '%') {
        f.conversion_char = c;
        *format = f;
        return ((const char*) s + 1);
    }

    for (;;) {
        flag_found = 1;

        switch (c) {
        case '-':
            f.justification_options = left_justification;
            break;
        case '+':
            f.sign_options = sign_always;
            break;
        case ' ':
            if (f.sign_options != sign_always) {
                f.sign_options = space_holder;
            }
            break;
        case '#':
            f.alternate_form = 1;
            break;
        case '0':
            if (f.justification_options != left_justification) {
                f.justification_options = zero_fill;
            }
            break;
        default:
            flag_found = 0;
            break;
        }

        if (flag_found) {
            c = *++s;
        } else {
            break;
        }
    }

    if (c == '*') {
        if ((f.field_width = va_arg(*arg, int)) < 0) {
            f.justification_options = left_justification;
            f.field_width = -f.field_width;
        }

        c = *++s;
    } else {
        while (fn_803B38AC(c)) {
            f.field_width = (f.field_width * 10) + (c - '0');
            c = *++s;
        }
    }

    if (f.field_width > 509) {
        f.conversion_char = 0xFF;
        *format = f;
        return ((const char*) s + 1);
    }

    if (c == '.') {
        f.precision_specified = 1;

        if ((c = *++s) == '*') {
            if ((f.precision = va_arg(*arg, int)) < 0) {
                f.precision_specified = 0;
            }

            c = *++s;
        } else {
            while (fn_803B38AC(c)) {
                f.precision = (f.precision * 10) + (c - '0');
                c = *++s;
            }
        }
    }

    flag_found = 1;

    switch (c) {
    case 'h':
        f.argument_options = short_argument;

        if (s[1] == 'h') {
            f.argument_options = char_argument;
            c = *++s;
        }

        break;

    case 'l':
        f.argument_options = long_argument;

        if (s[1] == 'l') {
            f.argument_options = long_long_argument;
            c = *++s;
        }

        break;

    case 'L':
        f.argument_options = long_double_argument;
        break;
    default:
        flag_found = 0;
        break;
    }

    if (flag_found) {
        c = *++s;
    }

    f.conversion_char = c;

    switch (c) {
    case 'd':
    case 'i':
    case 'u':
    case 'o':
    case 'x':
    case 'X':
        if (f.argument_options == long_double_argument) {
            f.conversion_char = 0xFF;
            break;
        }

        if (!f.precision_specified) {
            f.precision = 1;
        } else if (f.justification_options == zero_fill) {
            f.justification_options = right_justification;
        }
        break;

    case 'f':
        if (f.argument_options == short_argument ||
            f.argument_options == long_long_argument)
        {
            f.conversion_char = 0xFF;
            break;
        }

        if (!f.precision_specified) {
            f.precision = 6;
        }
        break;

    case 'g':
    case 'G':
        if (!f.precision) {
            f.precision = 1;
        }

    case 'e':
    case 'E':
        if (f.argument_options == short_argument ||
            f.argument_options == long_long_argument ||
            f.argument_options == char_argument)
        {
            f.conversion_char = 0xFF;
            break;
        }

        if (!f.precision_specified) {
            f.precision = 6;
        }
        break;

    case 'p':
        f.conversion_char = 'x';
        f.alternate_form = 1;
        f.argument_options = long_argument;
        f.precision = 8;
        break;

    case 'c':
        if (f.argument_options == long_argument) {
            f.argument_options = wchar_argument;
        } else {
            if (f.precision_specified || f.argument_options != normal_argument)
            {
                f.conversion_char = 0xFF;
            }
        }

        break;

    case 's':
        if (f.argument_options == long_argument) {
            f.argument_options = wchar_argument;
        } else {
            if (f.argument_options != normal_argument) {
                f.conversion_char = 0xFF;
            }
        }

        break;

    case 'n':
        if (f.argument_options == long_double_argument) {
            f.conversion_char = 0xFF;
        }

        break;

    default:
        f.conversion_char = 0xFF;
        break;
    }

    *format = f;
    return ((const char*) s + 1);
}

static const unsigned int K1 = 0x80808080L;
static const unsigned int K2 = 0xfefefeffL;

char* strchr(const char* str, int chr)
{
    const unsigned char* p = (unsigned char*) str - 1;
    unsigned long int c = ((unsigned long int) chr & 0xffu);
    unsigned long int ch;
    while ((ch = *++p)) {
        if (ch == c) {
            return ((char*) p);
        }
    }
    return c ? 0 : (char*) p;
}

int strncmp(const char* str1, const char* str2, unsigned long n)
{
    const unsigned char* p1 = (unsigned char*) str1 - 1;
    const unsigned char* p2 = (unsigned char*) str2 - 1;
    unsigned long c1, c2;

    n++;
    while (--n) {
        if ((c1 = *++p1) != (c2 = *++p2)) {
            return ((int) c1 - (int) c2);
        } else {
            if (!c1) {
                break;
            }
        }
    }
    return (0);
}

int strcmp(const char* str1, const char* str2)
{
    register unsigned char* left = (unsigned char*) str1;
    register unsigned char* right = (unsigned char*) str2;
    unsigned int k1, k2, align, l1, r1, x;
    int result;

    l1 = *left;
    r1 = *right;
    result = (int) l1 - (int) r1;
    if (result) {
        return l1 - r1;
    }

    if ((align = ((unsigned int) left & 3u)) != ((unsigned int) right & 3u)) {
        goto bytecopy;
    }
    if (align) {
        if (l1 == 0u) {
            return (0);
        }
        for (align = 3u - align; align; align--) {
            l1 = *(++left);
            r1 = *(++right);
            result = (int) l1 - (int) r1;
            if (result) {
                return result;
            }
            if (l1 == 0u) {
                return (0);
            }
        }
        left++;
        right++;
    }

    k1 = K1;
    k2 = K2;

    l1 = *(unsigned int*) left;
    r1 = *(unsigned int*) right;
    x = l1 + k2;
    if (x & k1) {
        goto adjust;
    }
    while (l1 == r1) {
        left += sizeof(unsigned int);
        l1 = *((unsigned int*) left);
        right += sizeof(unsigned int);
        r1 = *((unsigned int*) right);
        x = l1 + k2;
        if (x & k1) {
            goto adjust;
        }
    }

    if (l1 > r1) {
        return 1;
    } else {
        return -1;
    }

adjust:
    l1 = *left;
    r1 = *right;
    result = (int) l1 - (int) r1;
    if (result) {
        return (int) l1 - (int) r1;
    }
bytecopy:
    if (l1 == 0u) {
        return (0);
    }
    for (;;) {
        r1 = *(++left);
        l1 = *(++right);
        result = (int) r1 - (int) l1;
        if (result) {
            return result;
        }
        if (r1 == 0u) {
            return (0);
        }
    }
}

char* strcat(char* dest, const char* src)
{
    unsigned char* d;
    src--;
    d = (unsigned char*) dest - 1;
    while (*++d)
        ;
    --d;
    while ((*++d = *++src) != 0)
        ;
    return dest;
}

char* strncpy(char* dst, const char* src, unsigned long n)
{
    const unsigned char* p = (const unsigned char*) src - 1;
    unsigned char* q = (unsigned char*) dst - 1;

    n++;
    while (--n) {
        if (!(*++q = *++p)) {
            while (--n) {
                *++q = 0u;
            }
            break;
        }
    }
    return (dst);
}

char* strcpy(char* dst, const char* src)
{
    register unsigned char *destb, *fromb;
    register unsigned int w, t, align;
    register unsigned int k1;
    register unsigned int k2;

    fromb = (unsigned char*) src;
    destb = (unsigned char*) dst;

    if ((align = ((unsigned int) fromb & 3u)) != ((unsigned int) destb & 3u)) {
        goto bytecopy;
    }

    if (align) {
        if ((*destb = *fromb) == 0) {
            return (dst);
        }
        for (align = 3u - align; align; align--) {
            if ((*(++destb) = *(++fromb)) == 0) {
                return (dst);
            }
        }
        ++destb;
        ++fromb;
    }

    k1 = K1;
    k2 = K2;

    w = *((unsigned int*) (fromb));
    t = w + k2;
    t &= k1;
    if (t) {
        goto bytecopy;
    }

    destb -= sizeof(int);

    for (;;) {
        destb += sizeof(int);
        *((unsigned int*) (destb)) = w;

        fromb += sizeof(int);
        w = *((unsigned int*) (fromb));

        t = w + k2;
        t & w;
        t &= k1;
        if (t) {
            goto adjust;
        }
    }

adjust:
    destb += sizeof(int);
bytecopy:
    if ((*destb = *fromb) == 0) {
        return (dst);
    }
    for (;;) {
        if ((*(++destb) = *(++fromb)) == 0) {
            return (dst);
        }
    }
}

unsigned long(strlen)(const char* s)
{
    unsigned long k = -1;
    unsigned char* p = (unsigned char*) s - 1;
    do {
        k++;
    } while (*++p);

    return k;
}

extern void (*lbl_80569E48[])(int);

int fn_803B7CD0(int sig)
{
    void (*handler)(int);

    if (sig < 1 || sig > 6) {
        return -1;
    }

    __begin_critical_region(4);
    handler = lbl_80569E48[sig - 1];
    if (handler != (void (*)(int)) 1) {
        lbl_80569E48[sig - 1] = 0;
    }
    __end_critical_region(4);

    if (handler == (void (*)(int)) 1) {
        return 0;
    } else if (handler == 0) {
        if (sig == 1) {
            exit(0);
        }
    } else {
        handler(sig);
    }

    return 0;
}

int fwide(FILE* stream, int mode)
{
    int orientation;

    if (stream == NULL || stream->mode.file_kind == 0) {
        return 0;
    }

    orientation = stream->mode.file_orientation;
    switch (orientation) {
    case 0:
        if (mode > 0) {
            stream->mode.file_orientation = 2;
        } else if (mode < 0) {
            stream->mode.file_orientation = 1;
        }

        return mode;

    case 2:
        return 1;

    case 1:
        return -1;
    }

    return 0;
}

extern double fn_803B9A0C(double x);
extern double fn_803B9D1C(double x);
extern double fn_803B9F80(double x);
extern double fn_803BA210(double x);
extern double fn_803BA434(double x);
extern double fn_803BA770(double x);
extern double fn_803BA9EC(double x);
extern double fn_803BAAFC(double x);
extern double fn_803BCCD0(double x);
extern double fn_803B3C64(double x);

double sin(double x);
double tan(double x);

double fn_803BD388(double x)
{
    return fn_803B9A0C(x);
}

double fn_803BD3A8(double x)
{
    return fn_803B9D1C(x);
}

double fn_803BD3C8(double x)
{
    return fn_803B9F80(x);
}

double kar_axdriver__803bd3e8(double x)
{
    return fn_803BA210(x);
}

double kar_axdriver__near_803bd408(double x)
{
    return fn_803BA434(x);
}

double kar_axdriver__near_803bd428(double x)
{
    return fn_803BA770(x);
}

double kar_axdriver__near_803bd448(double x)
{
    return fn_803BA9EC(x);
}

#pragma push
#pragma dont_inline on
double kar_axdriver__803bd468(double x)
{
    return fn_803BAAFC(x);
}
#pragma pop

asm f32 fn_803BD488(register f64 x)
{
    nofralloc
    fabs f1, f1
    blr
}

f32 fn_803BD4F4(double x)
{
    return (f32) kar_axdriver__803bd468(x);
}

f32 fn_803BD518(double x)
{
    return (f32) tan(x);
}

f32 fn_803BD53C(double x)
{
    return (f32) sin(x);
}

f32 fn_803BD560(double x)
{
    return (f32) fn_803BCCD0(x);
}

double fn_803BD584(double x)
{
    return fn_803B3C64(x);
}

int fn_803BD5A4(const char* a, const char* b)
{
    signed char ca, la, cb, lb;

    for (;;) {
        ca = *a++;
        la = (ca == -1) ? -1 : (signed char) lbl_804F8BF0[(unsigned char) ca];
        cb = *b++;
        lb = (cb == -1) ? -1 : (signed char) lbl_804F8BF0[(unsigned char) cb];

        if (la < lb) {
            return -1;
        }
        if (la > lb) {
            return 1;
        }
        if (la == 0) {
            return 0;
        }
    }
}
