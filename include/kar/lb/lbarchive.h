#ifndef _KAR_LB_LBARCHIVE_H_
#define _KAR_LB_LBARCHIVE_H_

#include <dolphin/types.h>

#if defined(VERSION_GKYJ01)
#define kar_lbarchive__80059a20 fn_80059148
#define kar_lbarchive__near_80059cfc fn_80059424
#elif defined(VERSION_GKYP01)
#define kar_lbarchive__80059a20 fn_8005A330
#define kar_lbarchive__near_80059cfc fn_8005A60C
#endif

void kar_lbarchive__80059a20(s32 arg0, char* archive_name, void* out,
                             char* symbol_name, ...);
void kar_lbarchive__near_80059520(void* archive, void* out, char* name, s32 arg3,
                                  ...);
void kar_lbarchive__near_80059cfc(void);

#endif
