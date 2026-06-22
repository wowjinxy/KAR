#include "functions.h"
#include <dolphin/types.h>
#include "kar/gm/gmclearchecker.h"
#include "kar/gm/gmglobal.h"

extern s32 kar_shadow__near_8007b650(void);
extern u32 kar_gmmain__near_80005ce0(void);
extern void kar_lbaudio__near_8006176c(u32 sound_id);
extern u32 kar_plclearcheckerlib__8022fe80(int);
extern u32 kar_greventgenerator_get_kind_use_count(int);
extern int HSD_Randi(int);

#define GMCC_TYPE_COUNT 3
#define GMCC_NUMBER_COUNT 0x78

#define CHECK_TYPE(type, line)                                                 \
  do {                                                                         \
    if ((u8)(type) >= GMCC_TYPE_COUNT) {                                       \
      OSReport("error Clearchecker Type %d\n", (u8)(type));                    \
      assert_line((line), 0);                                                  \
    }                                                                          \
  } while (0)

#define CHECK_NUMBER(number, line)                                             \
  do {                                                                         \
    if ((u8)(number) >= GMCC_NUMBER_COUNT) {                                   \
      OSReport("error Clearchecker Number %d\n", (u8)(number));                \
      assert_line((line), 0);                                                  \
    }                                                                          \
  } while (0)

typedef struct {
  u8 reward_type;
  u8 reward_value;
  u8 clear_kind;
} ClearCheckerRewardEntry;

static ClearCheckerRewardEntry ClearChecker_Type0RewardTable[] = {
    {0x00, 0x00, 0x0E}, {0x00, 0x00, 0x6F}, {0x00, 0x00, 0x74},
    {0x00, 0x00, 0x5E}, {0x00, 0x00, 0x67}, {0x04, 0x01, 0x3C},
    {0x04, 0x01, 0x0C}, {0x04, 0x01, 0x2F}, {0x04, 0x01, 0x45},
    {0x04, 0x01, 0x4C}, {0x04, 0x01, 0x3F}, {0x04, 0x01, 0x37},
    {0x04, 0x01, 0x2A}, {0x04, 0x01, 0x75}, {0x04, 0x01, 0x53},
    {0x20, 0x00, 0x08}, {0x21, 0x00, 0x11}, {0x22, 0x00, 0x43},
    {0x23, 0x00, 0x1A}, {0x09, 0x00, 0x58}, {0x0A, 0x00, 0x0A},
    {0x0B, 0x00, 0x1B}, {0x0C, 0x00, 0x2D}, {0x0D, 0x00, 0x54},
    {0x0E, 0x00, 0x13}, {0x0F, 0x00, 0x31}, {0x10, 0x00, 0x1F},
    {0x11, 0x00, 0x55}, {0x12, 0x00, 0x4D}, {0x13, 0x00, 0x6E},
    {0x14, 0x00, 0x21}, {0x15, 0x00, 0x0F}, {0x16, 0x00, 0x05},
    {0x17, 0x00, 0x02}, {0x07, 0x00, 0x00}, {0x01, 0x00, 0x03},
    {0x06, 0x02, 0x18}, {0x05, 0x01, 0x2C}, {0x05, 0x01, 0x33},
    {0x05, 0x01, 0x6A}, {0x05, 0x01, 0x26}, {0x05, 0x01, 0x36},
    {0x05, 0x01, 0x72}, {0x05, 0x01, 0x6B}, {0x05, 0x01, 0x63},
    {0x05, 0x01, 0x01},
};

static ClearCheckerRewardEntry ClearChecker_Type1RewardTable[] = {
    {0x00, 0x00, 0x4E}, {0x00, 0x00, 0x5B}, {0x00, 0x00, 0x3C},
    {0x00, 0x00, 0x2A}, {0x00, 0x00, 0x0C}, {0x02, 0x00, 0x06},
    {0x02, 0x00, 0x74}, {0x02, 0x00, 0x45}, {0x24, 0x00, 0x19},
    {0x25, 0x00, 0x0B}, {0x26, 0x00, 0x0A}, {0x02, 0x00, 0x07},
    {0x02, 0x00, 0x66}, {0x04, 0x01, 0x1A}, {0x04, 0x01, 0x24},
    {0x04, 0x01, 0x33}, {0x04, 0x01, 0x39}, {0x04, 0x01, 0x4C},
    {0x04, 0x01, 0x43}, {0x04, 0x01, 0x59}, {0x04, 0x01, 0x6B},
    {0x20, 0x00, 0x00}, {0x21, 0x00, 0x03}, {0x22, 0x00, 0x2F},
    {0x23, 0x00, 0x5A}, {0x06, 0x02, 0x77}, {0x05, 0x01, 0x20},
    {0x05, 0x01, 0x73}, {0x05, 0x01, 0x3D}, {0x05, 0x01, 0x46},
    {0x05, 0x01, 0x52}, {0x05, 0x01, 0x63}, {0x05, 0x01, 0x64},
};

static ClearCheckerRewardEntry ClearChecker_Type2RewardTable[] = {
    {0x00, 0x00, 0x31}, {0x00, 0x00, 0x0B}, {0x00, 0x00, 0x00},
    {0x00, 0x00, 0x28}, {0x00, 0x00, 0x3B}, {0x04, 0x01, 0x0A},
    {0x04, 0x01, 0x06}, {0x04, 0x01, 0x30}, {0x04, 0x01, 0x34},
    {0x04, 0x01, 0x35}, {0x04, 0x01, 0x32}, {0x04, 0x01, 0x74},
    {0x04, 0x01, 0x2C}, {0x04, 0x01, 0x72}, {0x04, 0x01, 0x0F},
    {0x04, 0x01, 0x02}, {0x04, 0x01, 0x07}, {0x04, 0x01, 0x15},
    {0x04, 0x01, 0x22}, {0x04, 0x01, 0x1C}, {0x04, 0x01, 0x5B},
    {0x20, 0x00, 0x60}, {0x21, 0x00, 0x4D}, {0x22, 0x00, 0x66},
    {0x23, 0x00, 0x77}, {0x05, 0x01, 0x04}, {0x06, 0x02, 0x37},
    {0x1A, 0x00, 0x17}, {0x1B, 0x00, 0x39}, {0x1C, 0x00, 0x21},
    {0x18, 0x00, 0x6D}, {0x1D, 0x00, 0x44}, {0x1E, 0x00, 0x2A},
    {0x1F, 0x00, 0x2E}, {0x19, 0x00, 0x6E}, {0x16, 0x00, 0x2F},
    {0x17, 0x00, 0x08}, {0x03, 0x00, 0x13}, {0x03, 0x00, 0x59},
    {0x03, 0x00, 0x53}, {0x03, 0x00, 0x25}, {0x03, 0x00, 0x55},
    {0x03, 0x00, 0x0C}, {0x08, 0x00, 0x03},
};

static ClearCheckerRewardEntry *ClearChecker_RewardTables[] = {
    ClearChecker_Type0RewardTable,
    ClearChecker_Type1RewardTable,
    ClearChecker_Type2RewardTable,
};

static u8 ClearChecker_RewardTableCounts[] = {
    ARRAY_SIZE(ClearChecker_Type0RewardTable),
    ARRAY_SIZE(ClearChecker_Type1RewardTable),
    ARRAY_SIZE(ClearChecker_Type2RewardTable),
};

static u32 ClearChecker_LastUnlockSfxFrame = 0;

static inline ClearCheckerRewardEntry *GetClearCheckerRewardTable(u8 type) {
  CHECK_TYPE(type, 0x37);
  return ClearChecker_RewardTables[type];
}

int ClearChecker_GetRewardCount(u8 mode) {
  CHECK_TYPE(mode, 0x41);
  return ClearChecker_RewardTableCounts[mode];
}

u8 ClearChecker_GetClearKindFromRewardKind(u8 mode, u8 reward_kind) {
  ClearCheckerRewardEntry *entry =
      &GetClearCheckerRewardTable(mode)[reward_kind];
  return entry->clear_kind;
}

u8 ClearChecker_GetRewardTypeFromRewardKind(u8 mode, u8 reward_kind) {
  ClearCheckerRewardEntry *entry =
      &GetClearCheckerRewardTable(mode)[reward_kind];
  return entry->reward_type;
}

u8 ClearChecker_GetRewardValueFromRewardKind(u8 mode, u8 reward_kind) {
  ClearCheckerRewardEntry *entry =
      &GetClearCheckerRewardTable(mode)[reward_kind];
  return entry->reward_value;
}

u8 ClearChecker_CheckUnlocked(int mode, u8 reward_kind) {
  ClearCheckerRewardEntry *entry =
      &GetClearCheckerRewardTable(mode)[reward_kind];
  GmGlobalSaveData *save = kar_gmglobal__800076a0(mode);
  return (save->clearchecker_flags[entry->clear_kind] & 8) >> 3;
}

void ClearChecker_FindRewardByClearKind(int mode, u8 clear_kind,
                                        u8 *out_reward_kind,
                                        u8 *out_reward_value) {
  GmGlobalSaveData *save = kar_gmglobal__800076a0(mode);

  if ((save->clearchecker_flags[clear_kind] & 6) != 0) {
    int i;
    for (i = 0; i < ClearChecker_GetRewardCount(mode); i++) {
      ClearCheckerRewardEntry *entry;

      entry = &GetClearCheckerRewardTable(mode)[(u8)i];
      if (clear_kind == entry->clear_kind) {
        *out_reward_kind = i;
        *out_reward_value = entry->reward_value;
        return;
      }
    }
  }

  *out_reward_kind = -1;
}

void ClearChecker_SetNewUnlockNoSfx(s32 mode, s32 clear_kind) {
  GmGlobalSaveData *save = kar_gmglobal__800076a0(mode);

  if (kar_shadow__near_8007b650() != 0) {
    return;
  }
  CHECK_NUMBER(clear_kind, 148);
  save->clearchecker_flags[(u8)clear_kind] |= 1;
}

void ClearChecker_SetNewUnlock(s32 mode, u8 clear_kind) {
  GmGlobalSaveData *save = kar_gmglobal__800076a0(mode);

  if (kar_shadow__near_8007b650() != 0) {
    return;
  }
  CHECK_NUMBER(clear_kind, 165);
  if ((save->clearchecker_flags[clear_kind] & 5) == 0) {
    u32 frame = kar_gmmain__near_80005ce0();
    if (ClearChecker_LastUnlockSfxFrame != frame) {
      kar_lbaudio__near_8006176c(0x10008);
      ClearChecker_LastUnlockSfxFrame = kar_gmmain__near_80005ce0();
    }
  }
  save->clearchecker_flags[clear_kind] |= 1;
}

void ClearChecker_MarkUnlockSfxPlayedThisFrame(void) {
  ClearChecker_LastUnlockSfxFrame = kar_gmmain__near_80005ce0();
}

u8 ClearChecker_GetClearKindFlags(s32 mode, u8 clear_kind) {
  GmGlobalSaveData *save = kar_gmglobal__800076a0(mode);

  CHECK_NUMBER(clear_kind, 198);
  return save->clearchecker_flags[clear_kind];
}

s32 ClearChecker_HasPendingUnlock(s32 mode) {
  GmGlobalSaveData *save = kar_gmglobal__800076a0(mode);
  s32 i;

  if (kar_shadow__near_8007b650() != 0) {
    return 0;
  }

  for (i = 0; i < GMCC_NUMBER_COUNT; i++) {
    u8 flags = save->clearchecker_flags[i];
    if ((flags & 4) == 0 && (flags & 1) != 0) {
      return 1;
    }
  }

  return 0;
}

void ClearChecker_ShuffleRewardSlots(int mode) {
  GmGlobalSaveData *save = kar_gmglobal__800076a0(mode);
  const int arrSize = ARRAY_SIZE(save->pad_0);
  int i;
  int r30;

  for (i = 0; i < 120; i++) {
    save->pad_0[i] = -1;
  }

  switch ((u8)mode) {
  case 0:
    r30 = 1;
    save->pad_0[ClearChecker_Type0RewardTable[0x24].clear_kind] = 0x77;
    break;
  case 1:
    r30 = 1;
    save->pad_0[ClearChecker_Type1RewardTable[0x19].clear_kind] = 0x77;
    break;
  case 2:
    r30 = 3;
    save->pad_0[ClearChecker_Type2RewardTable[0x1e].clear_kind] = 0;
    save->pad_0[ClearChecker_Type2RewardTable[0x22].clear_kind] = 0xb;
    save->pad_0[ClearChecker_Type2RewardTable[0x1a].clear_kind] = 0x77;
    break;
  }

  for (i = 0; i < arrSize; i++) {
    if (i != 119 && ((u8)mode != 2 || (i != 0 && i != 0xb))) {
      int j;
      int rand = HSD_Randi((arrSize - i) - r30);
      for (j = 0; j < arrSize; j++) {
        if (save->pad_0[j] == 0xff) {
          if (rand <= 0) {
            save->pad_0[j] = i;
            break;
          }
          rand--;
        }
      }

      if (j == arrSize) {
        for (j = 0; j < arrSize; j++) {
          if (save->pad_0[j] == 0xff) {
            save->pad_0[j] = i;
            break;
          }
        }
      }
    }
  }
}
