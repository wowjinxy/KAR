#ifndef __GMDIAG_H_
#define __GMDIAG_H_

#include <dolphin/types.h>

#if defined(VERSION_GKYJ01)
#define kar_diag__8000acb0 fn_8000AC48
#elif defined(VERSION_GKYP01)
#define kar_diag__8000acb0 fn_8000AE48
#endif

s32 kar_diag__8000acb0(void);

#endif
