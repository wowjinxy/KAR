#include <global.h>

#include <sysdolphin/forward.h>

#define DEVCOMDEST_SBUF 2
#define DEVCOM_BUF_SIZE 0x4000
#define INIT_N_DEVCOMS 16

struct HSD_DevCom {
    HSD_DevCom* next;
    s32 dcReq;
    s32 file;
    s32 src;
    s32 dest;
    u32 size;
    u16 type;
    u16 cancelflag;
    HSD_DevComCallback callback;
    void* args;
};

typedef struct ARQRequest ARQRequest;
typedef void (*ARQCallback)(ARQRequest*);
struct ARQRequest {
    u8 unk[0x20];
};

typedef struct DVDFileInfo DVDFileInfo;
typedef void (*DVDCallback)(s32, DVDFileInfo*);
struct DVDFileInfo {
    u8 unk[0x40];
};

extern u32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(u32 level);
extern void* HSD_AudioMalloc(u32 size);
extern void ARQPostRequest(ARQRequest* request, u32 owner, u32 type,
                           u32 priority, u32 source, u32 dest, u32 length,
                           ARQCallback callback);
extern void DCInvalidateRange(void* addr, u32 nBytes);
extern void kar_diag__near_803d3f54(void* addr, u32 nBytes); /* DCStoreRange */
extern BOOL kar_lbfile__803c51c8(s32 entrynum, DVDFileInfo* fileInfo); /* DVDFastOpen */
extern BOOL DVDReadAsyncPrio(DVDFileInfo* fileInfo, void* addr, s32 length,
                             s32 offset, DVDCallback callback, s32 prio);
extern void kar_dvdsche_dispatch_stream_scheduler_callbacks(void);

char kar_src_devcom_80508be0[0xC8] =
    "devcom.c\0\0\0\0"
    "dvdDC->size <= DEVCOM_BUF_SIZE\0\0"
    "dvdDC->callback\0"
    "!(HSD_DevComGetDestType(type) == DEVCOMDEST_SBUF && size > DEVCOM_BUF_SIZE)\0"
    "src % 32 == 0\0\0\0"
    "dest % 32 == 0\0\0"
    "size % 32 == 0\0\0"
    "size != 0\0\0\0\0\0\0";

extern s32 lbl_805DD148;
extern char lbl_805DD14C[2];
extern char lbl_805DD150[3];

#define assert_line_named(line, cond, condstr)                               \
    ((cond) ? ((void) 0) : __assert(kar_src_devcom_80508be0, line, condstr))

static HSD_DevCom* devcom_queue_heads[4];
static HSD_DevCom* devcom_queue_tails[4];
static ARQRequest devcom_arq_request_slots_a[2][2];
static s32 devcom_staging_buffers[2][DEVCOM_BUF_SIZE / sizeof(s32)];
static DVDFileInfo devcom_dvd_fileinfo;

static HSD_DevCom* lbl_805DE4A0; /* free devcom list */
static u8 lbl_805DE4A4; /* aramstate */
static u8 lbl_805DE4A5;
static u8 lbl_805DE4A6;
static u8 lbl_805DE4A7;
static s32 lbl_805DE4A8;
static HSD_DevCom* lbl_805DE4AC[2];
static HSD_DevCom* lbl_805DE4B4; /* dvdDC */
static HSD_DevCom* lbl_805DE4B8; /* aramDC */
static u8 lbl_805DE4BC[2]; /* devComRelayBufFlag */
static s32 lbl_805DE4C0;
static s32 lbl_805DE4C4;

void HSD_DevComARAMWakeUp(void);
void HSD_DevComDVDWakeUp(void);

static inline void HSD_DevComUnlink(HSD_DevCom* dc, HSD_DevCom** heads)
{
    HSD_DevCom* curr;
    u32 enabled = OSDisableInterrupts();
    int i = dc->dcReq & 3;

    if (heads[i] == dc) {
        heads[i] = dc->next;
        if (devcom_queue_tails[i] == dc) {
            devcom_queue_tails[i] = NULL;
        }
        goto cleanup;
    }

    for (curr = heads[i]; curr->next != NULL; curr = curr->next) {
        if (curr->next == dc) {
            curr->next = dc->next;
            if (devcom_queue_tails[i] == dc) {
                devcom_queue_tails[i] = curr;
            }
            OSRestoreInterrupts(enabled);
            return;
        }
    }
    assert_line_named(0x79, 0, lbl_805DD14C);

cleanup:
    OSRestoreInterrupts(enabled);
}

void HSD_DevComStdCallback(ARQRequest* request)
{
    int i;

    if (request == &devcom_arq_request_slots_a[0][0]) {
        i = 0;
    } else if (request == &devcom_arq_request_slots_a[1][0]) {
        i = 1;
    } else {
        assert_line_named(0xB0, 0, lbl_805DD14C);
    }
    lbl_805DE4A4 = 0;
    lbl_805DE4BC[i] = 0;
    HSD_DevComDVDWakeUp();
    HSD_DevComARAMWakeUp();
}

static inline void HSD_DevComARAMCallback_inline(HSD_DevCom* devcom)
{
    u32 enabled = OSDisableInterrupts();
    devcom->next = lbl_805DE4A0;
    lbl_805DE4A0 = devcom;
    OSRestoreInterrupts(enabled);
}

void HSD_DevComARAMCallback(ARQRequest* request)
{
    int i;
    void* buf;
    HSD_DevComCallback callback;
    HSD_DevCom** heads = devcom_queue_heads;
    ARQRequest* arqbase = (ARQRequest*) ((u8*) heads + 0x20);

    if (lbl_805DE4B8->type == 0x1A) {
        if (request == arqbase) {
            i = 0;
        } else {
            i = 1;
        }
        buf = devcom_staging_buffers[i];
    } else {
        buf = NULL;
    }

    callback = lbl_805DE4B8->callback;
    if (callback != NULL) {
        callback(lbl_805DE4B8->dcReq, (int) lbl_805DE4B8->args, buf,
                 lbl_805DE4B8->cancelflag);
    }

    HSD_DevComUnlink(lbl_805DE4B8, heads);
    HSD_DevComARAMCallback_inline(lbl_805DE4B8);

    if (request == arqbase) {
        i = 0;
    } else if (request == arqbase + 2) {
        i = 1;
    } else {
        assert_line_named(0xB0, 0, lbl_805DD14C);
    }
    lbl_805DE4A4 = 0;
    lbl_805DE4BC[i] = 0;
    HSD_DevComDVDWakeUp();
    HSD_DevComARAMWakeUp();
}

static inline int getRelayBufIdx(void)
{
    int i;
    for (i = 0; i < 2; i++) {
        if (!lbl_805DE4BC[i]) {
            lbl_805DE4BC[i] = 1;
            return i;
        }
    }
    return -1;
}

void HSD_DevComARAMWakeUp(void)
{
    HSD_DevCom** heads = devcom_queue_heads;
    u32 enabled;
    int req_idx;
    u32 xfer_size2;
    ARQCallback arq_callback;
    ARQCallback arq_callback2;

    enabled = OSDisableInterrupts();
    if (lbl_805DE4A4 != 0) {
        OSRestoreInterrupts(enabled);
        return;
    }
    lbl_805DE4B8 = heads[3];
    if (heads[3] != NULL) {
        if (lbl_805DE4B8->cancelflag) {
            if (lbl_805DE4B8->callback != NULL) {
                lbl_805DE4B8->callback(lbl_805DE4B8->dcReq,
                                       (s32) lbl_805DE4B8->args, NULL, TRUE);
            }
            HSD_DevComUnlink(lbl_805DE4B8, heads);
            OSRestoreInterrupts(enabled);
            HSD_DevComARAMWakeUp();
            return;
        }
        req_idx = getRelayBufIdx();
        if (req_idx >= 0) {
            if (lbl_805DE4B8->type == 3) {
                u32 xfer_size;
                if (lbl_805DE4B8->size > DEVCOM_BUF_SIZE) {
                    arq_callback = HSD_DevComStdCallback;
                    xfer_size = DEVCOM_BUF_SIZE;
                } else {
                    arq_callback = HSD_DevComARAMCallback;
                    xfer_size = lbl_805DE4B8->size;
                }
                {
                    s32* p = devcom_staging_buffers[req_idx];
                    int i;
                    for (i = 0x1000; i > 0; i--) {
                        *p++ = 0;
                    }
                }
                kar_diag__near_803d3f54(devcom_staging_buffers[req_idx],
                                        DEVCOM_BUF_SIZE);
                ARQPostRequest(&devcom_arq_request_slots_a[req_idx][0], 0, 0,
                              1, (u32) devcom_staging_buffers[req_idx],
                              lbl_805DE4B8->dest, xfer_size, arq_callback);
                lbl_805DE4B8->dest += xfer_size;
                lbl_805DE4B8->size -= xfer_size;
                lbl_805DE4A4 = 1;
            } else if (lbl_805DE4B8->type == 0xB) {
                kar_diag__near_803d3f54((void*) lbl_805DE4B8->src,
                                        lbl_805DE4B8->size);
                ARQPostRequest(&devcom_arq_request_slots_a[req_idx][0], 0, 0,
                              1, lbl_805DE4B8->src, lbl_805DE4B8->dest,
                              lbl_805DE4B8->size, HSD_DevComARAMCallback);
                lbl_805DE4A4 = 1;
            } else if (lbl_805DE4B8->type == 0x19) {
                DCInvalidateRange((void*) lbl_805DE4B8->dest,
                                  lbl_805DE4B8->size);
                ARQPostRequest(&devcom_arq_request_slots_a[req_idx][0], 0, 1,
                              1, lbl_805DE4B8->src, lbl_805DE4B8->dest,
                              lbl_805DE4B8->size, HSD_DevComARAMCallback);
                lbl_805DE4A4 = 1;
            } else if (lbl_805DE4B8->type == 0x1A) {
                DCInvalidateRange(devcom_staging_buffers[req_idx],
                                  DEVCOM_BUF_SIZE);
                ARQPostRequest(&devcom_arq_request_slots_a[req_idx][0], 0, 1,
                              1, lbl_805DE4B8->src,
                              (u32) devcom_staging_buffers[req_idx],
                              lbl_805DE4B8->size, HSD_DevComARAMCallback);
                lbl_805DE4A4 = 1;
            } else if (lbl_805DE4B8->type == 0x1B) {
                DCInvalidateRange(devcom_staging_buffers[req_idx],
                                  DEVCOM_BUF_SIZE);
                if (lbl_805DE4B8->size > DEVCOM_BUF_SIZE) {
                    arq_callback2 = HSD_DevComStdCallback;
                    xfer_size2 = DEVCOM_BUF_SIZE;
                } else {
                    arq_callback2 = HSD_DevComARAMCallback;
                    xfer_size2 = lbl_805DE4B8->size;
                }
                ARQPostRequest(&devcom_arq_request_slots_a[req_idx][1], 0, 1,
                              1, lbl_805DE4B8->src,
                              (u32) devcom_staging_buffers[req_idx],
                              xfer_size2, NULL);
                ARQPostRequest(&devcom_arq_request_slots_a[req_idx][0], 0, 0,
                              1, (u32) devcom_staging_buffers[req_idx],
                              lbl_805DE4B8->dest, xfer_size2, arq_callback2);
                lbl_805DE4B8->src += xfer_size2;
                lbl_805DE4B8->dest += xfer_size2;
                lbl_805DE4B8->size -= xfer_size2;
                lbl_805DE4A4 = 1;
            }
        }
    }
    OSRestoreInterrupts(enabled);
}

void HSD_DevComDVDStdCallback(ARQRequest* request)
{
    int i;

    if (request == &devcom_arq_request_slots_a[0][0]) {
        i = 0;
    } else if (request == &devcom_arq_request_slots_a[1][0]) {
        i = 1;
    } else {
        assert_line_named(0x163, 0, lbl_805DD14C);
    }
    lbl_805DE4BC[i] = 0;
    HSD_DevComDVDWakeUp();
    HSD_DevComARAMWakeUp();
}

void HSD_DevComDVDARAMEndCallback(ARQRequest* request)
{
    HSD_DevCom* dc;
    HSD_DevCom** heads = devcom_queue_heads;
    ARQRequest* arqbase = (ARQRequest*) ((u8*) heads + 0x20);
    int i;

    if (request == arqbase) {
        i = 0;
    } else if (request == arqbase + 2) {
        i = 1;
    } else {
        assert_line_named(0x163, 0, lbl_805DD14C);
    }
    lbl_805DE4BC[i] = 0;
    HSD_DevComDVDWakeUp();
    HSD_DevComARAMWakeUp();

    if (request == arqbase) {
        i = 0;
    } else {
        i = 1;
    }

    dc = lbl_805DE4AC[i];
    if (dc->callback != NULL && lbl_805DE4A8 == 0) {
        dc->callback(dc->dcReq, (int) dc->args, NULL, dc->cancelflag);
    }
    HSD_DevComUnlink(lbl_805DE4B4, heads);
    HSD_DevComARAMCallback_inline(lbl_805DE4AC[i]);
    lbl_805DE4AC[i] = NULL;
}

void HSD_DevComDVDMemCallback(s32 result, DVDFileInfo* unused)
{
    HSD_DevCom* dc;
    u32 enabled;

    if (result == -1) {
        lbl_805DE4A8 = 1;
        return;
    }
    if (lbl_805DE4B4->size > 0x80000) {
        lbl_805DE4B4->src += 0x80000;
        lbl_805DE4B4->dest += 0x80000;
        lbl_805DE4B4->size -= 0x80000;
        lbl_805DE4A5 = 0;
        HSD_DevComDVDWakeUp();
        return;
    }
    if (lbl_805DE4B4->callback != NULL && lbl_805DE4A8 == 0) {
        lbl_805DE4B4->callback(lbl_805DE4B4->dcReq, (int) lbl_805DE4B4->args,
                               NULL, lbl_805DE4B4->cancelflag);
    }
    HSD_DevComUnlink(lbl_805DE4B4, devcom_queue_heads);
    dc = lbl_805DE4B4;
    enabled = OSDisableInterrupts();
    dc->next = lbl_805DE4A0;
    lbl_805DE4A0 = dc;
    OSRestoreInterrupts(enabled);
    lbl_805DE4A5 = 0;
    HSD_DevComDVDWakeUp();
}

void HSD_DevComDVDCallback(s32 result, DVDFileInfo* unused)
{
    HSD_DevCom* dc;
    u32 enabled;
    u16 type;
    char* file = kar_src_devcom_80508be0;
    HSD_DevCom** heads = devcom_queue_heads;

    if (result == -1) {
        lbl_805DE4A8 = 1;
    }
    type = lbl_805DE4B4->type;
    if (type == 0x22) {
        (lbl_805DE4B4->size <= DEVCOM_BUF_SIZE)
            ? ((void) 0)
            : __assert(file, 0x19E, file + 0xC);
        (lbl_805DE4B4->callback) ? ((void) 0) : __assert(file, 0x19F, file + 0x2C);
        if (lbl_805DE4A8 == 0) {
            lbl_805DE4B4->callback(lbl_805DE4B4->dcReq,
                                   (s32) lbl_805DE4B4->args,
                                   devcom_staging_buffers[lbl_805DE4A6],
                                   lbl_805DE4B4->cancelflag);
        }
        HSD_DevComUnlink(lbl_805DE4B4, heads);
        dc = lbl_805DE4B4;
        enabled = OSDisableInterrupts();
        dc->next = lbl_805DE4A0;
        lbl_805DE4A0 = dc;
        OSRestoreInterrupts(enabled);
        lbl_805DE4A5 = 0;
        lbl_805DE4BC[lbl_805DE4A6] = 0;
        HSD_DevComDVDWakeUp();
        HSD_DevComARAMWakeUp();
    } else if (type == 0x23) {
        lbl_805DE4A7 = lbl_805DE4A6;
        if (lbl_805DE4B4->size > DEVCOM_BUF_SIZE) {
            ARQPostRequest(&devcom_arq_request_slots_a[lbl_805DE4A6][0], 0, 0,
                          1, (u32) devcom_staging_buffers[lbl_805DE4A6],
                          lbl_805DE4B4->dest, DEVCOM_BUF_SIZE,
                          HSD_DevComDVDStdCallback);
            lbl_805DE4B4->src += DEVCOM_BUF_SIZE;
            lbl_805DE4B4->dest += DEVCOM_BUF_SIZE;
            lbl_805DE4B4->size -= DEVCOM_BUF_SIZE;
            lbl_805DE4A5 = 0;
            HSD_DevComDVDWakeUp();
            return;
        }
        lbl_805DE4AC[lbl_805DE4A6] = lbl_805DE4B4;
        ARQPostRequest(&devcom_arq_request_slots_a[lbl_805DE4A6][0], 0, 0, 1,
                      (u32) devcom_staging_buffers[lbl_805DE4A6],
                      lbl_805DE4B4->dest, lbl_805DE4B4->size,
                      HSD_DevComDVDARAMEndCallback);
    }
}

void HSD_DevComDVDWakeUp(void)
{
    u32 enabled;
    int i;
    int buf_idx;
    u32 xfer_size;

    if (lbl_805DE4A8 == 0) {
        enabled = OSDisableInterrupts();
        if (lbl_805DE4A5 != 0) {
            OSRestoreInterrupts(enabled);
            return;
        }
        lbl_805DE4A5 = 1;
        if (devcom_queue_heads[0] == NULL) {
            kar_dvdsche_dispatch_stream_scheduler_callbacks();
        }
        lbl_805DE4A5 = 0;
        for (i = 0; i < 3; i++) {
            if ((lbl_805DE4B4 = devcom_queue_heads[i])) {
                if (lbl_805DE4B4->cancelflag) {
                    if (lbl_805DE4B4->callback != NULL) {
                        lbl_805DE4B4->callback(lbl_805DE4B4->dcReq,
                                               (s32) lbl_805DE4B4->args, NULL,
                                               TRUE);
                    }
                    HSD_DevComUnlink(lbl_805DE4B4, devcom_queue_heads);
                    OSRestoreInterrupts(enabled);
                    HSD_DevComDVDWakeUp();
                    return;
                }
                kar_lbfile__803c51c8(lbl_805DE4B4->file, &devcom_dvd_fileinfo);
                if (lbl_805DE4B4->type == 0x21) {
                    xfer_size = 0x80000;
                    if (lbl_805DE4B4->size < 0x80000) {
                        xfer_size = lbl_805DE4B4->size;
                    }
                    DVDReadAsyncPrio(&devcom_dvd_fileinfo,
                                    (void*) lbl_805DE4B4->dest, xfer_size,
                                    lbl_805DE4B4->src, HSD_DevComDVDMemCallback,
                                    2);
                    lbl_805DE4A5 = 1;
                    OSRestoreInterrupts(enabled);
                    return;
                }
                buf_idx = getRelayBufIdx();
                if (buf_idx >= 0) {
                    lbl_805DE4A6 = buf_idx;
                    xfer_size = DEVCOM_BUF_SIZE;
                    if (lbl_805DE4B4->size < DEVCOM_BUF_SIZE) {
                        xfer_size = lbl_805DE4B4->size;
                    }
                    DVDReadAsyncPrio(&devcom_dvd_fileinfo,
                                    devcom_staging_buffers[buf_idx], xfer_size,
                                    lbl_805DE4B4->src, HSD_DevComDVDCallback,
                                    2);
                    lbl_805DE4A5 = 1;
                    OSRestoreInterrupts(enabled);
                    return;
                }
            }
        }
        OSRestoreInterrupts(enabled);
    }
}

static inline int HSD_DevComGetDestType(int type)
{
    return type & 7;
}

static inline void DevComLinkNext(HSD_DevCom* dc)
{
    int i;
    for (i = 1; i < INIT_N_DEVCOMS - 1; i++) {
        dc[i].next = &dc[i] + 1;
    }
    dc[i].next = NULL;
}

s32 HSD_DevComRequest(s32 file, u32 src, u32 dest, u32 size, s32 type,
                      s32 pri, HSD_DevComCallback cb, void* args)
{
    char* srcfile = kar_src_devcom_80508be0;
    u32 enabled;
    HSD_DevCom* dc;
    s32 result;

    enabled = OSDisableInterrupts();
    if ((dc = lbl_805DE4A0)) {
        lbl_805DE4A0 = dc->next;
        OSRestoreInterrupts(enabled);
    } else {
        dc = HSD_AudioMalloc(sizeof(HSD_DevCom) * INIT_N_DEVCOMS);
        DevComLinkNext(dc);
        lbl_805DE4A0 = &dc[1];
        OSRestoreInterrupts(enabled);
    }

    (dc) ? ((void) 0) : __assert(srcfile, 0x22B, lbl_805DD150);
    (!(HSD_DevComGetDestType(type) == DEVCOMDEST_SBUF &&
       size > DEVCOM_BUF_SIZE))
        ? ((void) 0)
        : __assert(srcfile, 0x22C, srcfile + 0x3C);
    (src % 32 == 0) ? ((void) 0) : __assert(srcfile, 0x22D, srcfile + 0x88);
    (dest % 32 == 0) ? ((void) 0) : __assert(srcfile, 0x22E, srcfile + 0x98);
    (size % 32 == 0) ? ((void) 0) : __assert(srcfile, 0x22F, srcfile + 0xA8);
    (size != 0) ? ((void) 0) : __assert(srcfile, 0x230, srcfile + 0xB8);

    pri = (type & 0x38) == 0x20 ? pri : 3;

    dc->file = file;
    dc->src = src;
    dc->dest = dest;
    dc->size = size;
    dc->type = type;
    dc->cancelflag = 0;
    dc->callback = cb;
    dc->args = args;

    enabled = OSDisableInterrupts();
    result = lbl_805DD148 + pri;
    dc->dcReq = result;
    lbl_805DD148 += 4;
    if (devcom_queue_tails[pri] != NULL) {
        devcom_queue_tails[pri]->next = dc;
    }
    devcom_queue_tails[pri] = dc;
    dc->next = NULL;
    if (devcom_queue_heads[pri] == NULL) {
        devcom_queue_heads[pri] = dc;
        HSD_DevComDVDWakeUp();
        HSD_DevComARAMWakeUp();
    }
    OSRestoreInterrupts(enabled);

    return result;
}

void kar_dvdsche_configure_stream_scheduler(s32 count, s32 pri)
{
    u32 enabled = OSDisableInterrupts();
    lbl_805DE4C0 = count;
    lbl_805DE4C4 = pri;
    OSRestoreInterrupts(enabled);
}
