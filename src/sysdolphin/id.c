#include <sysdolphin/id.h>

#include <dolphin/types.h>

extern HSD_ObjAllocData lbl_8058BC68; // hsd_iddata
extern HSD_IDTable lbl_8058BC94;      // default_table

extern char lbl_805DCC88[5]; // "id.c"
extern char lbl_805DCC90[6]; // "entry"

void HSD_IDInitAllocData(void)
{
    HSD_ObjAllocInit(&lbl_8058BC68, sizeof(IDEntry), 4);
}

void HSD_IDSetup(void)
{
    memset(&lbl_8058BC94, 0, sizeof(HSD_IDTable));
}

inline u32 hash(u32 id)
{
    return id % 0x65;
}

inline IDEntry* IDEntryAlloc()
{
    IDEntry* entry;

    entry = HSD_ObjAlloc(&lbl_8058BC68);
    if (entry == NULL) {
        __assert(lbl_805DCC88, 67, lbl_805DCC90);
    }
    memset(entry, 0, sizeof(IDEntry));

    return entry;
}

void HSD_IDInsertToTable(HSD_IDTable* table, u32 id, void* data)
{
    IDEntry* entry;

    if (table == NULL) {
        table = &lbl_8058BC94;
    }

    entry = table->table[hash(id)];
    while (entry != NULL) {
        if (entry->id == id)
            break;
        entry = entry->next;
    }

    if (entry != NULL) {
        entry->id = id;
        entry->data = data;
    } else {
        entry = IDEntryAlloc();
        entry->id = id;
        entry->data = data;
        entry->next = table->table[hash(id)];
        table->table[hash(id)] = entry;
    }
}

inline void IDEntryFree(IDEntry* entry) {
    HSD_ObjFree(&lbl_8058BC68, entry);
}

void HSD_IDRemoveByIDFromTable(HSD_IDTable* table, u32 id) {
    IDEntry* entry;
    IDEntry* prev;

    if (table == NULL) {
        table = &lbl_8058BC94;
    }

    prev = NULL;
    for (entry = table->table[hash(id)]; entry != NULL; entry = entry->next) {
        if (entry->id == id) {
            if (prev != NULL) {
                prev->next = entry->next;
            } else {
                table->table[hash(id)] = entry->next;
            }
            IDEntryFree(entry);
            return;
        }
        prev = entry;
    }
}

void* HSD_IDGetDataFromTable(HSD_IDTable* table, u32 id, s32* success)
{
    IDEntry* entry;

    if (table == NULL) {
        table = &lbl_8058BC94;
    }

    entry = table->table[hash(id)];
    while (entry != NULL) {
        if (entry->id == id) {
            if (success != NULL) {
                *success = 1;
            }
            return entry->data;
        }
        entry = entry->next;
    }

    if (success != NULL) {
        *success = 0;
    }
    return NULL;
}

void fn_8041A7C8(void* low, void* high)
{
    memset(&lbl_8058BC94, 0, sizeof(HSD_IDTable));
}
