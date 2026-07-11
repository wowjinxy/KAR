#include "functions.h"
#include <dolphin/types.h>
#include <kar/gm/gmglobal.h>
#include <kar/gm/gmlanmenu.h>
#include <kar/gm/gmmain.h>
#include <kar/gm/gmmovieassets.h>
#include <kar/gm/gmracenormal.h>
#include <kar/lb/lbaudio.h>
#include <kar/lb/lbhvqm.h>
#include <kar/lb/lbvector.h>
#include <sysdolphin/gobj_kinds.h>

typedef struct GObj GObj;
typedef struct MovieWork MovieWork;

struct GObj {
    u8 pad_0[0x20];
    u32 field_20;
    u32 field_24;
};

struct MovieWork {
    void* movie;
};

char kar_src_gmspecialmovie_804972f0[] = "gmspecialmovie.c";
u32 lbl_80497304[] = { 0, 0, 0, 0x3F800000, 0 };
u32 lbl_80497318[] = { 0, 0, 0, 0, 0 };
void* lbl_8049732C[] = {
    (void*) 0x00000000, (void*) 0x00000003, (void*) 0x00000280,
    (void*) 0x000001E0, (void*) 0x00000280, (void*) 0x000001E0,
    lbl_80497304,      lbl_80497318,      (void*) 0x00000000,
    (void*) 0x00000000, (void*) 0x00000000, (void*) 0x47000000,
    (void*) 0x00000000, (void*) 0x43F00000, (void*) 0x00000000,
    (void*) 0x44200000,
};
char kar_linkfile_mvhowtoplay_h4m_8049736c[] = "MvHowtoPlay.h4m";
char kar_linkfile_mvhowto3d_h4m_8049737c[] = "MvHowto3d.h4m";
char kar_linkfile_mvhowto2d_h4m_8049738c[] = "MvHowto2d.h4m";
char kar_linkfile_mvhowtoct_h4m_8049739c[] = "MvHowtoCt.h4m";
char kar_linkfile_mvspecnormal_h4m_804973ac[] = "MvSpecNormal.h4m";
char kar_linkfile_mvspechidden_h4m_804973c0[0x18] = "MvSpecHidden.h4m";
char kar_linkfile_mvending_h4m_804973d8[] = "MvEnding.h4m";
u32 lbl_804973E8[] = {
    0x00000E00, 0x006F0000, 0x7400005E, 0x00006704, 0x013C0401,
    0x0C04012F, 0x04014504, 0x014C0401, 0x3F040137, 0x04012A04,
    0x01750401, 0x53200008, 0x21001122, 0x00432300, 0x1A090058,
    0x0A000A0B, 0x001B0C00, 0x2D0D0054, 0x0E00130F, 0x00311000,
    0x1F110055, 0x12004D13, 0x006E1400, 0x2115000F, 0x16000517,
    0x00020700, 0x00010003, 0x06021805, 0x012C0501, 0x3305016A,
    0x05012605, 0x01360501, 0x7205016B, 0x05016305, 0x01010000,
};
u32 lbl_80497474[] = {
    0x00004E00, 0x005B0000, 0x3C00002A, 0x00000C02, 0x00060200,
    0x74020045, 0x24001925, 0x000B2600, 0x0A020007, 0x02006604,
    0x011A0401, 0x24040133, 0x04013904, 0x014C0401, 0x43040159,
    0x04016B20, 0x00002100, 0x0322002F, 0x23005A06, 0x02770501,
    0x20050173, 0x05013D05, 0x01460501, 0x52050163, 0x05016400,
};
void* lbl_804974D8[] = {
    (void*) 0x00003100, (void*) 0x000B0000, (void*) 0x00000028,
    (void*) 0x00003B04, (void*) 0x010A0401, (void*) 0x06040130,
    (void*) 0x04013404, (void*) 0x01350401, (void*) 0x32040174,
    (void*) 0x04012C04, (void*) 0x01720401, (void*) 0x0F040102,
    (void*) 0x04010704, (void*) 0x01150401, (void*) 0x2204011C,
    (void*) 0x04015B20, (void*) 0x00602100, (void*) 0x4D220066,
    (void*) 0x23007705, (void*) 0x01040602, (void*) 0x371A0017,
    (void*) 0x1B00391C, (void*) 0x00211800, (void*) 0x6D1D0044,
    (void*) 0x1E002A1F, (void*) 0x002E1900, (void*) 0x6E16002F,
    (void*) 0x17000803, (void*) 0x00130300, (void*) 0x59030053,
    (void*) 0x03002503, (void*) 0x00550300, (void*) 0x0C080003,
    lbl_804973E8,      lbl_80497474,      lbl_804974D8,
};

char lbl_805D51C8[8] = "0";
void* lbl_805DD578;
GObj* lbl_805DD57C;
GObj* lbl_805DD580[2];
MovieWork* lbl_805DD588[2];
const f32 lbl_805DE900 = 0.0f;
const f32 lbl_805DE904 = 640.0f;
const f32 lbl_805DE908[2] = { 480.0f, 0.0f };

extern u8 HSD_PadCopyStatus[];
void* kar_gmmain__near_80006c14(void);
void kar_lbarchive__near_80059cfc(void);
void HSD_SynthSFXWaitForLoadCompletion(void (*callback)(void));
void fn_80078604(void);
void fn_80078620(void);
s32 GObj_GetFlagFromArray(GObj* gobj);
GObj* HSD_GObjCreate(s32 classifier, s32 p_link, s32 priority);
void HSD_GObjDestroy(GObj* gobj);
void HSD_GObjGXLink(GObj* gobj, void (*callback)(GObj*, GObj*), s32 priority,
                    s32 flags);
void* HSD_CObjLoadDesc(void* desc);
void HSD_GObjObjectLink(GObj* gobj, u8 kind, void* object);
void GObj_SetCamera(GObj* gobj, GObj* camera);
void GObj_SetupGXLinkMax(GObj* gobj, void (*callback)(GObj*, GObj*),
                         s32 priority);
void kar_lbkdcoll__near_80076f8c(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                                 s32 arg4, f32 arg5, f32 arg6, f32 arg7,
                                 f32 arg8);
s32 fn_8027C830(void);
void kar_en_assets__asset_8027c838(void);
MovieWork* fn_8027E574(void);
void fn_8027CCA8(void);
void fn_8027CD10(void);
s32 fn_8027EF64(void);
void kar_en_assets__asset_8027ef6c(void);
void fn_8027F5B4(void);
void fn_8027F610(void);
void kar_pltrick__near_80233a74(void);

#define PLAYER_INPUT(i) (*(u32*) (HSD_PadCopyStatus + ((u8) (i) * 0x44) + 8))
#define LOAD_F32(sym) (*(const f32*) &(sym))
#define CAMERA_GOBJ() (lbl_805DD57C)
#define MOVIE_GOBJ() (lbl_805DD580[0])
#define ENDING_WORK() (lbl_805DD588[0])

#define SETUP_SPECIAL_MOVIE(path_sym)                                         \
    do {                                                                      \
        GObj* camera;                                                         \
                                                                               \
        kar_gmmain__near_80006c14();                                          \
        HSD_SynthSFXWaitForLoadCompletion(kar_lbarchive__near_80059cfc);      \
        kar_lbhvqm_init_movie_system();                                       \
        lbl_805DD578 = kar_lbhvqm_open_movie(path_sym, 1, 0, 0x1C,            \
                                             fn_80078604, fn_80078620);       \
        if (lbl_805DD578 == NULL) {                                           \
            kar_gmmain__near_800064f0();                                      \
        } else {                                                              \
            MOVIE_GOBJ() = HSD_GObjCreate(0x1B, 0x1A, 0);                     \
            HSD_GObjGXLink(MOVIE_GOBJ(), kar_gmspecialmovie__near_80049250,   \
                           0x15, 1);                                          \
            CAMERA_GOBJ() = HSD_GObjCreate(5, 0x1A, 0);                       \
            HSD_GObjObjectLink(CAMERA_GOBJ(),                                \
                               hsdGObj_default_object_kind,                   \
                               HSD_CObjLoadDesc(lbl_8049732C));               \
            GObj_SetupGXLinkMax(CAMERA_GOBJ(), GObj_SetCamera, 5);            \
            camera = CAMERA_GOBJ();                                           \
            camera->field_24 = 0x200000;                                      \
            camera->field_20 = 0;                                             \
            kar_lbhvqm__near_80077ed4(lbl_805DD578);                         \
            kar_movie_assets__8000a498(0x10);                                 \
        }                                                                     \
    } while (0)

#define DEFINE_SPECIAL_MOVIE_ASSET(fn_name, path_sym)                         \
    void fn_name(void)                                                         \
    {                                                                         \
        SETUP_SPECIAL_MOVIE(path_sym);                                        \
    }

void kar_gmspecialmovie__near_80049250(GObj* arg0, GObj* gobj);

void kar_gmspecialmovie__80049198(void)
{
    s8 movie = *(s8*) ((u8*) kar_gmmain__near_80006c14() + 0x7C4);

    switch (movie) {
    case 0:
        kar_gmglobal__near_800088c8(0x16);
        break;
    case 1:
        kar_gmglobal__near_800088c8(0x17);
        break;
    case 2:
        kar_gmglobal__near_800088c8(0x18);
        break;
    case 3:
        kar_gmglobal__near_800088c8(0x19);
        break;
    case 4:
        kar_gmglobal__near_800088c8(0x1A);
        break;
    case 5:
        kar_gmglobal__near_800088c8(0x1B);
        break;
    default:
        __assert(kar_src_gmspecialmovie_804972f0, 0x6E, lbl_805D51C8);
        break;
    }
}

void kar_gmspecialmovie__near_80049250(GObj* arg0, GObj* gobj)
{
    if (GObj_GetFlagFromArray(gobj) == 2) {
        s32 x;
        s32 y;
        s32 z;

        kar_lbhvqm__near_80078028(lbl_805DD578, &x, &y, &z);
        kar_lbkdcoll__near_80076f8c(x, y, z, 0x46, 0,
                                    LOAD_F32(lbl_805DE900),
                                    LOAD_F32(lbl_805DE900),
                                    LOAD_F32(lbl_805DE904),
                                    LOAD_F32(lbl_805DE908[0]));
    }
}

void kar_gmspecialmovie__near_800492b8(void)
{
    s32 i;

    kar_gmmain__near_80006c14();
    kar_lbhvqm__near_8007859c();
    if (kar_lbhvqm__near_80077f14(lbl_805DD578) == 0) {
        kar_lbhvqm__near_800780d0(lbl_805DD578);
        lbl_805DD578 = NULL;
        kar_gmmain__near_800064f0();
        return;
    }

    for (i = 0; i < 4; i++) {
        if (kar_gmracenormal__8000aea8() == 3 ||
            kar_gmracenormal__8000aea8() == 4 ||
            kar_gmracenormal__8000aea8() == 5 ||
            kar_gmracenormal__8000aea8() == 6) {
            u32 input = PLAYER_INPUT(i);

            if ((input & 0x1D60) != 0) {
                kar_movie_assets__8000a498(0x100);
                kar_lbaudio__near_80061658();
                kar_lbhvqm__near_80078284(lbl_805DD578);
                return;
            }
            if ((input & 0x200) != 0) {
                kar_movie_assets__8000a498(0x100);
                kar_lbaudio__near_800616c8();
                kar_lbhvqm__near_80078284(lbl_805DD578);
                return;
            }
        } else {
            if ((PLAYER_INPUT(i) & 0x1100) != 0) {
                kar_movie_assets__8000a498(0x100);
                kar_lbaudio__near_80061658();
                kar_lbhvqm__near_80078284(lbl_805DD578);
                return;
            }
        }
    }
}

void kar_gmspecialmovie__near_800493ec(void)
{
    kar_gmmain__near_80006c14();
    if (CAMERA_GOBJ() != NULL) {
        HSD_GObjDestroy(CAMERA_GOBJ());
    }
    if (MOVIE_GOBJ() != NULL) {
        HSD_GObjDestroy(MOVIE_GOBJ());
    }

    MOVIE_GOBJ() = NULL;
    CAMERA_GOBJ() = NULL;
    kar_lbhvqm__near_80077a5c();
    if (kar_gmracenormal__8000aea8() == 9) {
        kar_gmlanmenu__800082a0(0x10);
        kar_gmlanmenu__80008220();
    }
}

DEFINE_SPECIAL_MOVIE_ASSET(kar_movie_assets__asset_80049458,
                           kar_linkfile_mvhowtoplay_h4m_8049736c)
DEFINE_SPECIAL_MOVIE_ASSET(kar_movie_assets__asset_80049554,
                           kar_linkfile_mvhowto3d_h4m_8049737c)
DEFINE_SPECIAL_MOVIE_ASSET(kar_movie_assets__asset_80049650,
                           kar_linkfile_mvhowto2d_h4m_8049738c)
DEFINE_SPECIAL_MOVIE_ASSET(kar_movie_assets__asset_8004974c,
                           kar_linkfile_mvhowtoct_h4m_8049739c)
DEFINE_SPECIAL_MOVIE_ASSET(kar_movie_assets__asset_80049848,
                           kar_linkfile_mvspecnormal_h4m_804973ac)
DEFINE_SPECIAL_MOVIE_ASSET(kar_movie_assets__asset_80049944,
                           kar_linkfile_mvspechidden_h4m_804973c0)

void kar_gmspecialmovie__near_80049a40(void)
{
    kar_lbhvqm__near_8007859c();
    if (fn_8027C830() != 0) {
        kar_gmglobal__near_800088c8(-1);
        kar_gmmain__near_800064f0();
    }
}

void kar_movie_assets__asset_80049a78(void)
{
    void* movie;

    kar_en_assets__asset_8027c838();
    kar_lbhvqm_init_movie_system();
    kar_lbvector__near_8006595c();
    ENDING_WORK() = fn_8027E574();
    movie = kar_lbhvqm_open_movie(kar_linkfile_mvending_h4m_804973d8, 0, 1,
                                  0xE, fn_80078604, fn_80078620);
    ENDING_WORK()->movie = movie;
    if (movie == NULL) {
        kar_gmglobal__near_800088c8(-1);
        kar_gmmain__near_800064f0();
    }
    kar_lbhvqm__near_80077ed4(ENDING_WORK()->movie);
    fn_8027CCA8();
    kar_lbaudio__near_8005e5d0();
    kar_lbaudio__near_8005e1a8(0x2B);
}

void kar_gmspecialmovie__near_80049b08(void)
{
    ENDING_WORK() = fn_8027E574();
    kar_lbhvqm__near_800780d0(ENDING_WORK()->movie);
    ENDING_WORK()->movie = NULL;
    kar_lbhvqm__near_80077a5c();
    kar_lbaudio__near_8005e5d0();
    fn_8027CD10();
    if (kar_gmracenormal__8000aea8() == 0xA) {
        kar_gmlanmenu__800082a0(0x10);
        kar_gmlanmenu__80008220();
    }
}

void kar_gmspecialmovie__near_80049b68(void)
{
    if (fn_8027EF64() != 0) {
        kar_gmglobal__near_800088c8(-1);
        kar_gmmain__near_800064f0();
    }
}

void kar_gmspecialmovie__near_80049b9c(void)
{
    kar_pltrick__near_80233a74();
    kar_lbvector__near_8006595c();
    kar_lbaudio__near_8005ab84();
    kar_lbaudio__near_8005a440();
    kar_lbaudio__near_8005a608();
    kar_en_assets__asset_8027ef6c();
    fn_8027F5B4();
    kar_lbaudio__near_8005e5d0();
    kar_lbaudio__near_8005e1a8(0xC);
}

void kar_gmspecialmovie__near_80049be0(void)
{
    fn_8027F610();
    kar_lbaudio__near_8005e5d0();
    if (kar_gmracenormal__8000aea8() == 0xB) {
        kar_gmlanmenu__800082a0(0x10);
        kar_gmlanmenu__80008220();
    }
}
