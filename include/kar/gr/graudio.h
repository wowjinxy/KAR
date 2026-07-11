#ifndef KAR_GR_GRAUDIO_H
#define KAR_GR_GRAUDIO_H

#include <dolphin/types.h>

struct Ground;
struct IndividualFgmAll;

void kar_graudio_configure_individual_fgm_tracks(struct Ground* ground,
                                                 struct IndividualFgmAll* indiviFgmAll);
void kar_graudio_update_individual_fgm_timers(struct Ground* ground,
                                              struct IndividualFgmAll* indiviFgmAll,
                                              s32* counters, s32 counter_num);

#endif
