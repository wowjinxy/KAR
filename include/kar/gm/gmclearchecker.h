#ifndef __GMCLEARCHECKER_H_
#define __GMCLEARCHECKER_H_

#include <dolphin/types.h>

int kar_gmclearchecker__80049c20(u8 type);
u8 kar_gmclearchecker__80049c84(u8 type, u8 index);
u8 kar_gmclearchecker__80049d10(u8 type, u8 index);
u8 kar_gmclearchecker__80049d98(u8 type, u8 index);
u8 kar_gmclearchecker__80049e24(int type, u8 index);
void kar_gmclearchecker__80049ec4(int type, u8 number, u8 *out_index,
                                  u8 *out_value);
void kar_gmclearchecker__80049fcc(s32 type, s32 index);
void kar_gmclearchecker__8004a054(s32 arg0, u8 number);
void kar_gmclearchecker__near_8004a10c(void);
u8 kar_gmclearchecker__8004a130(s32 arg0, u8 number);
s32 kar_gmclearchecker__near_8004a1a4(s32 arg0);
void kar_gmclearchecker__near_8004a2bc(int type);

#endif // !__GMCLEARCHECKER_H_
