#ifndef __GREVENTGENERATOR_H_
#define __GREVENTGENERATOR_H_

#include <dolphin/types.h>

u32 kar_greventgenerator_get_kind_use_count(int kind);
void* kar_greventgenerator_get_current_event_param(void);
s32 kar_greventgenerator_get_current_event_key_frame(void* event);
s32 kar_greventgenerator_get_state_elapsed_frames(void* event);
void kar_greventgenerator_enter_finish_state(void* event);

#endif
