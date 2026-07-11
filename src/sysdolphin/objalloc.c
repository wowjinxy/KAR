#include <sysdolphin/objalloc.h>

extern void __assert(const char*, unsigned long, const char*);
extern void* _HSD_MemAlloc(u32 size, u32 align, u32 flags);
extern u32 _HSD_MemGetRemain(void);
extern s32 HSD_GetNbBits(u32 value);

extern objheap HSD_ObjHeap;
extern char ObjAllocAssertData[5];
HSD_ObjAllocData* HSD_ObjAllocDataList[2];
char ObjAllocAssertStrings[0x38] =
    "objalloc.c\0\0align <= 32\0HSD_GetNbBits(align) == 1";

s32 HSD_ObjAllocAddFree(HSD_ObjAllocData* data, u32 num)
{
    u32 total_size;
    u32 size;
    u32 i;
    u8* obj;
    u8* end;
    u8* heap_end;
    u32 remain;

    if (data == NULL) {
        __assert(ObjAllocAssertStrings, 0xEE, ObjAllocAssertData);
    }

    size = data->size;
    total_size = size * num;
    if (HSD_ObjHeap.top != 0) {
        u32 mask = data->align - 1;

        heap_end = (u8*) HSD_ObjHeap.top + HSD_ObjHeap.size;
        obj = (u8*) ((HSD_ObjHeap.curr + mask) & ~mask);
        if (obj > heap_end) {
            return 0;
        }

        remain = heap_end - obj;
        if (remain < total_size) {
            total_size = remain - (remain % size);
        }

        num = total_size / size;
        if (num == 0) {
            return 0;
        }

        end = obj + total_size;
        HSD_ObjHeap.curr = (u32) end;
        HSD_ObjHeap.remain = heap_end - end;
    } else {
        obj = _HSD_MemAlloc(total_size, data->align, 1);
        if (obj == NULL) {
            return 0;
        }
    }

    for (i = 0; i < num - 1; i++) {
        *(HSD_ObjAllocLink**) (obj + (data->size * i)) =
            (HSD_ObjAllocLink*) (obj + (data->size * (i + 1)));
    }
    *(HSD_ObjAllocLink**) (obj + (data->size * i)) = data->freehead;
    data->freehead = (HSD_ObjAllocLink*) obj;
    data->free += num;

    return num;
}

void* HSD_ObjAlloc(HSD_ObjAllocData* data)
{
    HSD_ObjAllocLink* obj;
    u32 remain;

    if (data->num_limit_flag && data->used >= data->num_limit) {
        return NULL;
    }

    if (data->heap_limit_flag) {
        if (data->heap_limit_num == -1) {
            if (HSD_ObjHeap.top != 0) {
                remain = HSD_ObjHeap.remain;
            } else {
                remain = _HSD_MemGetRemain();
            }

            if (remain <= data->heap_limit_size) {
                data->heap_limit_num = data->used + data->free;
            }
        } else {
            if (HSD_ObjHeap.top != 0) {
                remain = HSD_ObjHeap.remain;
            } else {
                remain = _HSD_MemGetRemain();
            }

            if (remain > data->heap_limit_size) {
                data->heap_limit_num = -1;
            }
        }

        if (data->used >= data->heap_limit_num) {
            return NULL;
        }
    }

    if (data->free == 0) {
        HSD_ObjAllocAddFree(data, 1);
        if (data->free == 0) {
            return NULL;
        }
    }

    obj = data->freehead;
    data->freehead = obj->next;
    data->used++;
    data->free--;
    if (data->used > data->peak) {
        data->peak = data->used;
    }

    return obj;
}

void HSD_ObjFree(HSD_ObjAllocData* data, void* obj)
{
    ((HSD_ObjAllocLink*) obj)->next = data->freehead;
    data->freehead = obj;
    data->free++;
    data->used--;
}

void HSD_ObjAllocInit(HSD_ObjAllocData* data, u32 size, u32 align)
{
    HSD_ObjAllocData** cur;
    HSD_ObjAllocData* entry;
    char* assert_base;
    u32 aligned_size;

    assert_base = (char*) &HSD_ObjHeap;
    if (data == NULL) {
        __assert(assert_base + 0x10, 0x182, ObjAllocAssertData);
    }

    if (data != NULL) {
        cur = &HSD_ObjAllocDataList[0];
        while ((entry = *cur) != NULL) {
            if (entry == data) {
                *cur = entry->next;
            } else {
                cur = &entry->next;
            }
        }
    } else {
        HSD_ObjAllocDataList[0] = NULL;
    }

    memset(data, 0, sizeof(HSD_ObjAllocData));
    data->num_limit = -1;
    data->heap_limit_size = 0;
    data->heap_limit_num = -1;

    if (align > 0x20) {
        __assert(assert_base + 0x10, 0x18D, assert_base + 0x1C);
    }
    if (HSD_GetNbBits(align) != 1) {
        __assert(assert_base + 0x10, 0x18E, assert_base + 0x28);
    }

    data->align = align;
    aligned_size = (size + (data->align - 1)) & ~(data->align - 1);
    data->size = aligned_size;
    data->next = HSD_ObjAllocDataList[0];
    HSD_ObjAllocDataList[0] = data;
}

void _HSD_ObjAllocForgetMemory(void)
{
    HSD_ObjAllocDataList[0] = NULL;
}
