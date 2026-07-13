#ifndef KAR_LB_LBHVQM_H
#define KAR_LB_LBHVQM_H

#include <dolphin/types.h>

void kar_lbhvqm_init_movie_system(void);
void* kar_lbhvqm_open_movie(char* path, s32 arg1, s32 arg2, s32 arg3,
                            void (*arg4)(void), void (*arg5)(void));
void kar_lbhvqm__near_80077a5c(void);
void kar_lbhvqm__near_80077ed4(void* movie);
s32 kar_lbhvqm__near_80077f14(void* movie);
void kar_lbhvqm__near_80078028(void* movie, s32* arg1, s32* arg2, s32* arg3);
void kar_lbhvqm__near_800780d0(void* movie);
void kar_lbhvqm__near_80078284(void* movie);
void kar_lbhvqm__near_8007859c(void);
s32 kar_lbhvqm__near_8007863c(void);
s32 kar_lbhvqm__near_8007865c(void);
s32 kar_lbhvqm__near_800786d4(void* arg0);
void kar_lbhvqm__near_800786f8(void);
void kar_lbhvqm__near_80078720(void);
void kar_lbhvqm__near_8007875c(void);
void kar_lbhvqm__near_80078990(void);
void kar_lbhvqm__near_80078c3c(void);
void kar_lbhvqm__near_80078c7c(void);
void kar_lbhvqm__near_80078cb0(s32 arg0);
s32 kar_lbhvqm__near_80078cc0(void);
void kar_lbhvqm__near_80078cd0(s32 arg0);
s32 kar_lbhvqm__near_80078ce0(void* arg0);
s32 kar_lbhvqm__near_80078d24(void);
s32 kar_lbhvqm__near_80078e30(void);
void kar_lbhvqm__near_80078e40(s32 arg0);
s32 kar_lbhvqm__near_80078e4c(void);
void kar_lbhvqm__near_80078e5c(void);
s32 kar_lbhvqm__near_8007901c(void);
s32 kar_lbhvqm__near_80079108(void);
void* kar_lbhvqm__near_80079428(s32 kind, void* desc, void* data);

#endif
