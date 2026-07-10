#ifndef _rumble_h_
#define _rumble_h_

#include <dolphin/types.h>

#include <sysdolphin/forward.h>

struct HSD_PadRumbleListData {
    HSD_PadRumbleListData* next;
    u32 id;
    u8 pause;
    u8 pri;
    u8 status;
    u16 loop_count;
    u16 wait;
    s32 frame;
    u16* stack;
    u16* listp;
    u16* headp;
};

struct HSD_RumbleData {
    u8 last_status;
    u8 status;
    u8 direct_status;
    u16 nb_list;
    HSD_PadRumbleListData* listdatap;
};

struct RumbleCommand {
    u16 op;
    u16 frame;
};

union HSD_Rumble {
    u16 def;
    RumbleCommand command;
};

void HSD_PadRumbleOn(s8 no);
void HSD_PadRumbleOffH(s8 no);
void HSD_PadRumbleOffN(s8 no);
void HSD_PadRumbleRemove(s8 no);
void HSD_PadRumbleRemoveAll(void);
void HSD_PadRumbleRemoveId(s8 no, int id);
void HSD_PadRumblePauseAll(void);
void HSD_PadRumbleActiveAll(void);
int HSD_PadRumbleAdd(s8 no, int id, int frame, int pri, void* listp);
int HSD_PadRumbleInterpret1(HSD_PadRumbleListData* a, u8* b);
void HSD_PadRumbleInterpret(void);
void HSD_PadRumbleInit(u16 a, HSD_PadRumbleListData* b);

#endif
