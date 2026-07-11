#ifndef __LBAUDIO_H_
#define __LBAUDIO_H_

#include <dolphin/types.h>

#if defined(VERSION_GKYJ01)
#define kar_lbaudio__near_8005a440 fn_80059B68
#define kar_lbaudio__near_8005a474 fn_80059B9C
#define kar_lbaudio__near_8005a5b0 fn_80059CD8
#define kar_lbaudio__near_8005a608 fn_80059D30
#define kar_lbaudio__near_8005ab84 fn_8005A2AC
#define kar_lbaudio_alloc_weapon_track_subtype_0 fn_8005CAE4
#define kar_lbaudio__near_8005dbc8 fn_8005D2F0
#define kar_lbaudio__near_8005e1a8 fn_8005D8D0
#define kar_lbaudio__near_8005e5d0 fn_8005DCF8
#define kar_lbaudio__near_8005e788 fn_8005DEB0
#define kar_lbaudio_stop_track_handle_chain fn_8005DF00
#define kar_lbaudio_start_track fn_8005E3C8
#define kar_lbaudio__near_80061620 fn_80060D48
#define kar_lbaudio__near_80061658 fn_80060D80
#define kar_lbaudio__near_800616c8 fn_80060DF0
#define kar_lbaudio__near_80061734 fn_80060E5C
#define kar_lbaudio__near_8006176c fn_80060E94
#elif defined(VERSION_GKYP01)
#define kar_lbaudio__near_8005a440 fn_8005AD50
#define kar_lbaudio__near_8005a474 fn_8005AD84
#define kar_lbaudio__near_8005a5b0 fn_8005AEC0
#define kar_lbaudio__near_8005a608 fn_8005AF18
#define kar_lbaudio__near_8005ab84 fn_8005B494
#define kar_lbaudio_alloc_weapon_track_subtype_0 fn_8005DCCC
#define kar_lbaudio__near_8005dbc8 fn_8005E4D8
#define kar_lbaudio__near_8005e1a8 fn_8005EAB8
#define kar_lbaudio__near_8005e5d0 fn_8005EEE0
#define kar_lbaudio__near_8005e788 fn_8005F098
#define kar_lbaudio_stop_track_handle_chain fn_8005F0E8
#define kar_lbaudio_start_track fn_8005F5B0
#define kar_lbaudio__near_80061620 fn_80061F30
#define kar_lbaudio__near_80061658 fn_80061F68
#define kar_lbaudio__near_800616c8 fn_80061FD8
#define kar_lbaudio__near_80061734 fn_80062044
#define kar_lbaudio__near_8006176c fn_8006207C
#endif

void kar_lbaudio__near_8005a440(void);
void kar_lbaudio__near_8005a474(void);
void kar_lbaudio__near_8005a5b0(void);
void kar_lbaudio__near_8005a608(void);
void kar_lbaudio__near_8005ab84(void);
s32 kar_lbaudio_alloc_weapon_track_subtype_0(void);
s32 kar_lbaudio__near_8005dbc8(void);
void kar_lbaudio__near_8005e1a8(s32 arg0);
void kar_lbaudio__near_8005e5d0(void);
void kar_lbaudio__near_8005e788(void);
s32 kar_lbaudio_stop_track_handle_chain(s32 handle);
void kar_lbaudio_start_track(s32 arg0, s32 arg1, s32 arg2);
void kar_lbaudio__near_80061620(void);
void kar_lbaudio__near_80061658(void);
void kar_lbaudio__near_800616c8(void);
void kar_lbaudio__near_80061734(void);
void kar_lbaudio__near_8006176c(u32 sound_id);

#endif
