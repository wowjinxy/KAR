#include <global.h>

#include <sysdolphin/rumble.h>

extern u32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(u32 level);
extern void PADControlMotor(int chan, int command);

typedef struct {
    u8 unk_00[0x11];
    u8 check; // 0x11
    struct {
        s8 valid; // 0x12 + no*2
        s8 chan;  // 0x13 + no*2
    } port[4];
    u8 unk_1A[0x5C - 0x1A];
    u16 max_list;                    // 0x5C
    u8 unk_5E[2];                    // 0x5E
    HSD_PadRumbleListData* freelist; // 0x60
} HSD_PadRumbleGlobals;

extern HSD_PadRumbleGlobals HSD_PadState;
extern HSD_RumbleData HSD_PadRumbleData[4];
extern HSD_RumbleData HSD_DefaultRumbleData;

static inline void HSD_PadRumbleFree(HSD_RumbleData* a, HSD_PadRumbleListData* b)
{
    HSD_PadRumbleListData** r5 = &a->listdatap;

    while ((*r5) != b) {
        r5 = &(*r5)->next;
    }
    *r5 = b->next;
    a->nb_list--;
    b->next = HSD_PadState.freelist;
    HSD_PadState.freelist = b;
}

void HSD_PadRumbleOn(s8 no)
{
    if (HSD_PadState.check == HSD_PadState.port[no].valid) {
        bool intrEnabled = OSDisableInterrupts();
        HSD_RumbleData* r5 = &HSD_PadRumbleData[HSD_PadState.port[no].chan];

        r5->direct_status = 2;
        OSRestoreInterrupts(intrEnabled);
    }
}

void HSD_PadRumbleOffH(s8 no)
{
    if (HSD_PadState.check == HSD_PadState.port[no].valid) {
        bool intrEnabled = OSDisableInterrupts();
        HSD_RumbleData* r5 = &HSD_PadRumbleData[HSD_PadState.port[no].chan];

        r5->direct_status = 1;
        OSRestoreInterrupts(intrEnabled);
    }
}

void HSD_PadRumbleOffN(s8 no)
{
    if (HSD_PadState.check == HSD_PadState.port[no].valid) {
        bool intrEnabled = OSDisableInterrupts();
        HSD_RumbleData* r5 = &HSD_PadRumbleData[HSD_PadState.port[no].chan];

        r5->direct_status = 0;
        OSRestoreInterrupts(intrEnabled);
    }
}

void HSD_PadRumbleRemove(s8 no)
{
    if (HSD_PadState.check == HSD_PadState.port[no].valid) {
        bool r29 = OSDisableInterrupts();
        HSD_RumbleData* r28 = &HSD_PadRumbleData[HSD_PadState.port[no].chan];
        HSD_PadRumbleListData* r4 = r28->listdatap;

        while (r4 != NULL) {
            HSD_PadRumbleListData* r30 = r4->next;
            HSD_PadRumbleFree(r28, r4);
            r4 = r30;
        }
        OSRestoreInterrupts(r29);
    }
}

void HSD_PadRumbleRemoveAll(void)
{
    int i = 0;

    do {
        HSD_PadRumbleRemove(i);
        i++;
    } while (i < 4);
}

void HSD_PadRumbleRemoveId(s8 no, int id)
{
    if (HSD_PadState.check == HSD_PadState.port[no].valid) {
        bool r3 = OSDisableInterrupts();
        HSD_RumbleData* r31 = &HSD_PadRumbleData[HSD_PadState.port[no].chan];
        HSD_PadRumbleListData* r7 = r31->listdatap;

        while (r7 != NULL) {
            HSD_PadRumbleListData* r6 = r7->next;
            if (r7->id == (u32) id) {
                HSD_PadRumbleFree(r31, r7);
            }
            r7 = r6;
        }
        OSRestoreInterrupts(r3);
    }
}

static inline void HSD_PadRumblePause(s8 no, int status)
{
    if (HSD_PadState.check == HSD_PadState.port[no].valid) {
        bool intrEnabled = OSDisableInterrupts();
        HSD_RumbleData* data = &HSD_PadRumbleData[HSD_PadState.port[no].chan];
        HSD_PadRumbleListData* r4 = data->listdatap;

        while (r4 != NULL) {
            HSD_PadRumbleListData* next = r4->next;

            r4->pause = status;
            r4 = next;
        }
        OSRestoreInterrupts(intrEnabled);
    }
}

void HSD_PadRumblePauseAll(void)
{
    int i;
    for (i = 0; i < 4; i++) {
        HSD_PadRumblePause((u8) i, 1);
    }
}

void HSD_PadRumbleActiveAll(void)
{
    int i;
    for (i = 0; i < 4; i++) {
        HSD_PadRumblePause((u8) i, 0);
    }
}

static inline void HSD_PadRumbleInsertSorted(HSD_PadRumbleListData** r6,
                                              HSD_PadRumbleListData* r7)
{
    HSD_PadRumbleListData* r5;

    while ((r5 = *r6) != NULL && r5->pri <= r7->pri) {
        r6 = &r5->next;
    }
    r7->next = r5;
    *r6 = r7;
}

int HSD_PadRumbleAdd(s8 no, int id, int frame, int pri, void* listp)
{
    HSD_PadRumbleGlobals* base = &HSD_PadState;
    int result = 0;

    if (base->check == HSD_PadState.port[no].valid) {
        bool intrEnabled = OSDisableInterrupts();
        HSD_RumbleData* data = &HSD_PadRumbleData[HSD_PadState.port[no].chan];
        HSD_PadRumbleListData* freeEntry = base->freelist;

        if (freeEntry != NULL && data->nb_list < base->max_list) {
            base->freelist = freeEntry->next;
            freeEntry->id = id;
            freeEntry->pause = 0;
            freeEntry->pri = pri;
            freeEntry->status = 0;
            freeEntry->loop_count = 0;
            freeEntry->wait = 0;
            freeEntry->frame = frame;
            freeEntry->stack = NULL;
            freeEntry->headp = listp;
            freeEntry->listp = listp;
            HSD_PadRumbleInsertSorted(&data->listdatap, freeEntry);
            data->nb_list++;
            result = 1;
        }
        OSRestoreInterrupts(intrEnabled);
    }
    return result;
}

int HSD_PadRumbleInterpret1(HSD_PadRumbleListData* a, u8* b)
{
    if (a->pause == 1) {
        return 0;
    }
    while (a->wait == 0) {
        switch ((*(u8*) a->listp >> 5) & 7) {
        case 0:
            if (a->frame == -2) {
                return 1;
            }
            a->listp = a->headp;
            break;
        case 1:
            a->status = 2;
            a->wait = *a->listp & 0x1FFF;
            a->listp++;
            break;
        case 2:
            a->status = 1;
            a->wait = *a->listp & 0x1FFF;
            a->listp++;
            break;
        case 3:
            a->status = 0;
            a->wait = *a->listp & 0x1FFF;
            a->listp++;
            break;
        case 4:
            a->loop_count = *a->listp & 0x1FFF;
            a->listp++;
            a->stack = a->listp;
            break;
        case 5:
            if (--a->loop_count != 0) {
                a->listp = a->stack;
            } else {
                a->listp++;
            }
            break;
        }
    }
    *b = a->status;
    a->wait--;
    if (a->frame != -1 && a->frame != -2) {
        if (--a->frame == 0) {
            return 1;
        }
    }
    return 0;
}

void HSD_PadRumbleInterpret(void)
{
    HSD_RumbleData* r30 = HSD_PadRumbleData;
    HSD_PadRumbleListData* r29;
    HSD_PadRumbleListData* r28;
    int i;

    for (i = 0; i < 4; i++, r30++) {
        r30->status = r30->direct_status;
        r29 = r30->listdatap;
        while (r29 != NULL) {
            r28 = r29->next;

            if (HSD_PadRumbleInterpret1(r29, &r30->status) != 0) {
                HSD_PadRumbleFree(r30, r29);
            }
            r29 = r28;
        }
        if (r30->status != r30->last_status) {
            switch (r30->status) {
            case 0:
                PADControlMotor(i, 2);
                break;
            case 1:
                PADControlMotor(i, 0);
                break;
            case 2:
                PADControlMotor(i, 1);
                break;
            }
            r30->last_status = r30->status;
        }
    }
}

void HSD_PadRumbleInit(u16 a, HSD_PadRumbleListData* b)
{
    int i;

    HSD_PadState.max_list = a;
    HSD_PadState.freelist = b;
    if (a != 0) {
        for (i = 0; i < a - 1; i++) {
            HSD_PadState.freelist[i].next = &HSD_PadState.freelist[i + 1];
        }
        HSD_PadState.freelist[i].next = NULL;
    }
    for (i = 0; i < 4; i++) {
        HSD_PadRumbleData[i] = HSD_DefaultRumbleData;
    }
}
