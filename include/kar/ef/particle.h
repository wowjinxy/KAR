#ifndef __PARTICLE_H_
#define __PARTICLE_H_

#include <dolphin/types.h>

void kar_particle__near_8042b5a8(u8 id, void* particle);
void kar_particle__near_8042ba60(void* particle, void* callbacks);
s32 kar_particle__8042a734(u16 id, void* particle, void* arg2, void* arg3,
                           void* arg4);

#endif
