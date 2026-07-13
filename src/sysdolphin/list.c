#include <sysdolphin/list.h>

extern HSD_ObjAllocData hsdSList_alloc_data; // slist_alloc_data
extern HSD_ObjAllocData hsdDList_alloc_data; // dlist_alloc_data

extern char ListSourceFile[7]; // "list.c"
extern char ListAssertList[5]; // "list"
extern char ListAssertNext[5]; // "next"
extern char ListAssertPrev[5]; // "prev"

#define assert_line_named(line, cond, condstr)                                 \
    ((cond) ? ((void) 0) : __assert(ListSourceFile, line, condstr))

void HSD_ListInitAllocData()
{
    HSD_ObjAllocInit(&hsdSList_alloc_data, sizeof(HSD_SList), 4);
    HSD_ObjAllocInit(&hsdDList_alloc_data, sizeof(HSD_DList), 4);
}

HSD_ObjAllocData* HSD_SListGetAllocData()
{
    return &hsdSList_alloc_data;
}

HSD_ObjAllocData* HSD_DListGetAllocData()
{
    return &hsdDList_alloc_data;
}

HSD_SList *HSD_SListAlloc()
{
    HSD_SList *list;

    list = HSD_ObjAlloc(&hsdSList_alloc_data);
    assert_line_named(76, list, ListAssertList);

    memset(list, 0, sizeof(HSD_SList));
    return list;
}

void HSD_SListAppend(HSD_SList* list, void* data)
{
    HSD_SList* next = HSD_SListAlloc();
    next->data = data;
    HSD_SListAppendList(list, next);
}

void HSD_SListPrepend(HSD_SList* list, void* data)
{
    HSD_SList* next = HSD_SListAlloc();
    next->data = data;
    HSD_SListPrependList(list, next);
}

HSD_SList* HSD_SListAppendList(HSD_SList* list, HSD_SList* next)
{
    assert_line_named(179, next, ListAssertNext);
    if (list != NULL) {
        next->next = list->next;
        list->next = next;
        return list;
    }
    next->next = NULL;
    return next;
}

HSD_SList *HSD_SListPrependList(HSD_SList *list, HSD_SList *prev)
{
    assert_line_named(202, prev, ListAssertPrev);
    prev->next = list;
    return prev;
}

HSD_SList *HSD_SListRemove(HSD_SList *list)
{
    HSD_SList *next;

    if (list != NULL) {
        next = list->next;
        HSD_ObjFree(&hsdSList_alloc_data, list);
        return next;
    }

    return NULL;
}
