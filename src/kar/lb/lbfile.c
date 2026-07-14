#include "functions.h"
#include <dolphin/types.h>
#include <kar/gm/gmglobal.h>
#include <kar/lb/lbarchive.h>
#include <kar/lb/lbfile.h>

typedef struct DVDFileInfo DVDFileInfo;

struct DVDFileInfo {
    u8 cb[0x30];
    u32 startAddr;
    u32 length;
    void (*callback)(s32 result, DVDFileInfo* file_info);
};

char kar_src_lbfile_80498108[] = "lbfile.c";
static u8 gap_07_80498111_data[3];
char lbl_80498114[] = "!cancelflag";
char lbl_80498120[] = "Error : file name too long %s.";
static u8 gap_07_8049813F_data[1];
char lbl_80498140[] =
    "Cannot open file no=%d.\0"
    "file isn't exist %s = %d\n\0\0\0"
    "entry_num != -1\0\0\0\0";

char kar_lbfile_path_buffer[0x20];
char lbl_805D5260[] = "NULL";
static u8 gap_09_805D5265_sdata[3];
char lbl_805D5268[] = "dat";
char lbl_805D526C[] = "0";
static u8 gap_09_805D526E_sdata[2];
s32 lbl_805DD5A8[2];

u32 OSDisableInterrupts(void);
void OSRestoreInterrupts(u32 level);
s32 DVDConvertPathToEntrynum(char* path);
BOOL DVDClose(DVDFileInfo* file_info);
BOOL kar_lbfile__803c51c8(s32 entrynum, DVDFileInfo* file_info);
char* strcpy(char* dest, const char* src);
s32 HSD_DevComRequest(s32 file, u32 src, u32 dest, u32 size, s32 type,
                      s32 pri, HSD_DevComCallback callback, void* args);

void kar_lbfile_async_done_callback(int dc_req, int arg, void* buffer,
                                    BOOL cancelflag)
{
    if (cancelflag != 0) {
        __assert(kar_src_lbfile_80498108, 0x4F, lbl_80498114);
    }

    lbl_805DD5A8[0] = 1;
}

#pragma dont_inline on
s32 kar_lbfile_poll_async_done(void)
{
    kar_lbarchive__near_80059cfc();
    return lbl_805DD5A8[0];
}
#pragma dont_inline off

char* kar_lbfile_build_localized_filename(char* path)
{
    char* dst;
    char* src;
    s32 i;
    s32 lang;

    dst = kar_lbfile_path_buffer;
    src = path;
    i = 0;

    while (*src != '\0' && *src != '.' && *src != '_') {
        if (i > 0x1C) {
            OSReport(lbl_80498120, path);
            __assert(kar_src_lbfile_80498108, 0xAA, lbl_805D5260);
        }

        *dst++ = *src++;
        i++;
    }

    if (*src != '\0' && src[1] != '\0') {
        strcpy(kar_lbfile_path_buffer, path);
    } else if (*src == '.') {
        kar_lbfile_path_buffer[i++] = '.';

        lang = kar_gmglobal__near_80007660();
        switch (lang) {
        case 0:
            strcpy(kar_lbfile_path_buffer + i, lbl_805D5268);
            break;
        case 1:
            strcpy(kar_lbfile_path_buffer + i, lbl_805D5268);
            break;
        default:
            strcpy(kar_lbfile_path_buffer + i, lbl_805D5268);
            break;
        }
    } else if (*src == '_') {
        kar_lbfile_path_buffer[i++] = '.';

        lang = kar_gmglobal__near_80007680();
        switch (lang) {
        case 0:
            strcpy(kar_lbfile_path_buffer + i, lbl_805D5268);
            break;
        case 1:
            strcpy(kar_lbfile_path_buffer + i, lbl_805D5268);
            break;
        default:
            strcpy(kar_lbfile_path_buffer + i, lbl_805D5268);
            break;
        }
    } else {
        kar_lbfile_path_buffer[i++] = '.';
        strcpy(kar_lbfile_path_buffer + i, lbl_805D5268);
    }

    return kar_lbfile_path_buffer;
}

BOOL kar_lbfile_path_exists(char* path)
{
    s32 entry_num;

    entry_num = DVDConvertPathToEntrynum(kar_lbfile_build_localized_filename(path));
    return entry_num != -1;
}

u32 kar_lbfile_get_size_by_entrynum(s32 entrynum)
{
    DVDFileInfo file_info;
    u32 enabled;
    u32 size;

    enabled = OSDisableInterrupts();
    if (!kar_lbfile__803c51c8(entrynum, &file_info)) {
        OSReport(lbl_80498140, entrynum);
        __assert(kar_src_lbfile_80498108, 0x126, lbl_805D526C);
    }

    size = file_info.length;
    DVDClose(&file_info);
    OSRestoreInterrupts(enabled);

    return size;
}

u32 kar_lbfile_get_size_by_path(char* path)
{
    DVDFileInfo file_info;
    char* localized_path;
    char* file;
    s32 entry_num;
    u32 enabled;
    u32 size;

    file = kar_src_lbfile_80498108;
    localized_path = kar_lbfile_build_localized_filename(path);
    entry_num = DVDConvertPathToEntrynum(localized_path);
    if (entry_num == -1) {
        OSReport(file + 0x50, localized_path, entry_num);
        __assert(file, 0x13C, file + 0x6C);
    }

    enabled = OSDisableInterrupts();
    if (!kar_lbfile__803c51c8(entry_num, &file_info)) {
        OSReport(file + 0x38, entry_num);
        __assert(file, 0x126, lbl_805D526C);
    }

    size = file_info.length;
    DVDClose(&file_info);
    OSRestoreInterrupts(enabled);

    return size;
}

void kar_lbfile_devcom_copy_blocking(s32 src, void* dest, u32 size, s32 pri)
{
    lbl_805DD5A8[0] = 0;
    HSD_DevComRequest(0, src, (u32) dest, size, 0x19, pri,
                      kar_lbfile_async_done_callback, NULL);

    while (kar_lbfile_poll_async_done() == 0) {
    }
}

void kar_lbfile_read_entrynum_async(s32 entrynum, void* dest, u32* size_out,
                                    s32 pri, HSD_DevComCallback callback,
                                    void* args)
{
    DVDFileInfo file_info;
    u32 enabled;
    u32 size;
    s32 type;

    enabled = OSDisableInterrupts();
    if (!kar_lbfile__803c51c8(entrynum, &file_info)) {
        OSReport(lbl_80498140, entrynum);
        __assert(kar_src_lbfile_80498108, 0x126, lbl_805D526C);
    }

    size = file_info.length;
    DVDClose(&file_info);
    OSRestoreInterrupts(enabled);

    *size_out = size;

    type = 0x23;
    if ((u32) dest >= 0x80000000U) {
        type = 0x21;
    }

    HSD_DevComRequest(entrynum, 0, (u32) dest, (*size_out + 0x1F) & ~0x1F,
                      type, pri, callback, args);
}

void kar_lbfile_read_path_blocking(char* path, void* dest, u32* size_out)
{
    DVDFileInfo file_info;
    char* localized_path;
    char* file;
    s32 entry_num;
    u32 enabled;
    u32 size;
    s32 type;

    lbl_805DD5A8[0] = 0;
    file = kar_src_lbfile_80498108;
    localized_path = kar_lbfile_build_localized_filename(path);
    entry_num = DVDConvertPathToEntrynum(localized_path);
    if (entry_num == -1) {
        OSReport(file + 0x50, localized_path, entry_num);
        __assert(file, 0x18A, file + 0x6C);
    }

    enabled = OSDisableInterrupts();
    if (!kar_lbfile__803c51c8(entry_num, &file_info)) {
        OSReport(file + 0x38, entry_num);
        __assert(file, 0x126, lbl_805D526C);
    }

    size = file_info.length;
    DVDClose(&file_info);
    OSRestoreInterrupts(enabled);

    *size_out = size;

    type = 0x23;
    if ((u32) dest >= 0x80000000U) {
        type = 0x21;
    }

    HSD_DevComRequest(entry_num, 0, (u32) dest, (*size_out + 0x1F) & ~0x1F,
                      type, 1, kar_lbfile_async_done_callback, NULL);

    while (kar_lbfile_poll_async_done() == 0) {
    }
}
