#ifndef __GMCLEARCHECKER_H_
#define __GMCLEARCHECKER_H_

#include <dolphin/types.h>

int ClearChecker_GetRewardCount(u8 mode);
u8 ClearChecker_GetClearKindFromRewardKind(u8 mode, u8 reward_kind);
u8 ClearChecker_GetRewardTypeFromRewardKind(u8 mode, u8 reward_kind);
u8 ClearChecker_GetRewardValueFromRewardKind(u8 mode, u8 reward_kind);
u8 ClearChecker_CheckUnlocked(int mode, u8 reward_kind);
void ClearChecker_FindRewardByClearKind(int mode, u8 clear_kind,
                                        u8 *out_reward_kind,
                                        u8 *out_reward_value);
void ClearChecker_SetNewUnlockNoSfx(s32 mode, s32 clear_kind);
void ClearChecker_SetNewUnlock(s32 mode, u8 clear_kind);
void ClearChecker_MarkUnlockSfxPlayedThisFrame(void);
u8 ClearChecker_GetClearKindFlags(s32 mode, u8 clear_kind);
s32 ClearChecker_HasPendingUnlock(s32 mode);
void ClearChecker_ShuffleRewardSlots(int mode);

#endif // !__GMCLEARCHECKER_H_
