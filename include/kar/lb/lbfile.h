#ifndef _KAR_LB_LBFILE_H_
#define _KAR_LB_LBFILE_H_

#include <dolphin/types.h>
#include <sysdolphin/forward.h>

extern char kar_lbfile_path_buffer[0x20];

void kar_lbfile_async_done_callback(int dc_req, int arg, void* buffer,
                                    BOOL cancelflag);
s32 kar_lbfile_poll_async_done(void);
char* kar_lbfile_build_localized_filename(char* path);
BOOL kar_lbfile_path_exists(char* path);
u32 kar_lbfile_get_size_by_entrynum(s32 entrynum);
u32 kar_lbfile_get_size_by_path(char* path);
void kar_lbfile_devcom_copy_blocking(s32 src, void* dest, u32 size, s32 pri);
void kar_lbfile_read_entrynum_async(s32 entrynum, void* dest, u32* size_out,
                                    s32 pri, HSD_DevComCallback callback,
                                    void* args);
void kar_lbfile_read_path_blocking(char* path, void* dest, u32* size_out);
void kar_lbfile_wait_for_group6_loads(void);
void kar_lbfile_queue_resource_set_mode1(void);
void kar_lbfile_queue_resource_set_mode3(void);
s32* kar_lbfile_get_resource_load_config(void);
void kar_lbfile_queue_startup_resource_loads(void);

#endif
