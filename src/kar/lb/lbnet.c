#include "functions.h"
#include <stdarg.h>
#include <dolphin/types.h>
#include <dolphin/ai.h>
#include <dolphin/gx/gx.h>
#include <dolphin/mtx/mtx.h>
#include <dolphin/mtx/vec.h>
#include <dolphin/os.h>
#include <dolphin/pad.h>
#include <kar/gr/grairglider.h>
#include <kar/gr/greventlighthouse.h>
#include <kar/lb/lbvector.h>
#include <sysdolphin/cobj.h>
#include <sysdolphin/lobj.h>
#include <sysdolphin/mtx.h>
#include <sysdolphin/displayfunc.h>
#include <sysdolphin/tev_state.h>
#include <sysdolphin/objalloc.h>

extern char kar_srcfile_lbnet_c_805d540c[8];
#undef assert_line
#define assert_line(line, cond) \
    ((cond) ? ((void) 0) : __assert(kar_srcfile_lbnet_c_805d540c, line, #cond))
#define assert_line_str(line, cond, str) \
    ((cond) ? ((void) 0) : __assert(kar_srcfile_lbnet_c_805d540c, line, str))
static char lbl_8049B0F4[] = "TotalMemorySize == 0";
static char lbl_8049B10C[] =
    "(net_recv == NULL && DebugLap == 0) || (net_recv != NULL && DebugLap == net_recv->lap)";
static char lbl_8049B164[] =
    "net_recv == NULL || net_recv->len == sizeof(LbNetCirculationData)";

#define GX_TEX_S            0
#define GX_TEX_ST           1
#define GX_RGB565           0
#define GX_RGBA4            3
#define GX_RGBA6            4
#define GX_RGBA8            5
#define GX_NONE             0
#define GX_DIRECT           1
#define GX_INDEX8           2
#define GX_QUADS            0x80
#define GX_LINES            0xA8
#define GX_VTXFMT0          0
#define GX_TEVSTAGE0        0
#define GX_TEXCOORD0        0
#define GX_TEXCOORD_NULL    0xff
#define GX_TEXMAP_NULL      0xff
#define GX_COLOR0A0         4
#define GX_COLOR_NULL       0xff
#define GX_SRC_REG          0
#define GX_SRC_VTX          1
#define GX_DF_NONE          0
#define GX_DF_SIGN          1
#define GX_DF_CLAMP         2
#define GX_AF_SPEC          0
#define GX_AF_SPOT          1
#define GX_AF_NONE          2
#define GX_LIGHT_NULL       0
#define GX_PASSCLR          4
#define GX_NEVER             0
#define GX_LESS               1
#define GX_EQUAL               2
#define GX_LEQUAL               3
#define GX_GREATER               4
#define GX_NEQUAL               5
#define GX_GEQUAL               6
#define GX_ALWAYS               7
#define GX_AOP_AND          0
#define GX_AOP_OR           1
#define GX_BM_BLEND         1
#define GX_BM_LOGIC         2
#define GX_BL_ZERO          0
#define GX_BL_ONE           1
#define GX_BL_SRCCLR        2
#define GX_BL_SRCALPHA      4
#define GX_BL_INVSRCALPHA   5
#define GX_LO_CLEAR         0
#define GX_LO_COPY          3
#define GX_LO_NOOP          5
#define GX_CULL_NONE        0
#define GX_CULL_BACK        2
#define GX_PNMTX0           0

void GXSetChanCtrl(u32, u32, u32, u32, u32, u32, u32);
void GXSetNumTexGens(u32);

#define FU32(p, o) (*(u32 *) ((char *) (p) + (o)))
#define FS32(p, o) (*(s32 *) ((char *) (p) + (o)))
#define FF32(p, o) (*(f32 *) ((char *) (p) + (o)))
#define FU8(p, o) (*(u8 *) ((char *) (p) + (o)))
#define FS8(p, o) (*(s8 *) ((char *) (p) + (o)))
#define FU16(p, o) (*(u16 *) ((char *) (p) + (o)))
#define FP(p, o) (*(void **) ((char *) (p) + (o)))

#pragma pack(1)
typedef struct LbNetPadRecord {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    s32 unk3;
    s32 unk7;
    u8 unkB;
    u8 unkC;
    u8 unkD;
    u8 unkE;
    u32 unkF;
    s32 unk13;
    u8 unk17;
    u8 unk18;
} LbNetPadRecord; /* size = 0x19 */
#pragma pack()

typedef struct LbNetInputRecord {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    u32 unk10;
} LbNetInputRecord; /* size = 0x14 */

typedef struct LbNetCirculationData {
    s32 lap;
    s32 len;
    u8 pad8[0x154 - 8];
} LbNetCirculationData;

typedef struct DVDDiskID {
    char gameName[4];
    char company[2];
    u8 diskNumber;
    u8 gameVersion;
    u8 streaming;
    u8 streamingBufSize;
    u8 padding[22];
} DVDDiskID;

extern DVDDiskID *DVDGetCurrentDiskID(void);
extern void kar_gmlanmenu__near_80052f7c(u32 arg0);
extern void kar_gmlanmenu__near_80052fb8(void *arg0, u32 arg1);
extern void kar_diagnostic__803d7e58(void *arg0);
extern void kar_diagnostic__803d7f34(void *arg0);
extern void *kar_lbmemory__near_8005884c(s32 kind, u32 size);
extern void kar_lbheap__80058920(s32 kind, void *ptr);
extern void fn_804889C0(void *arg0);
extern void fn_803D7E20(void *arg0);
extern void fn_804872CC(void *cb1, void *cb2, void *arg2);
extern void fn_804871EC(void);
extern void fn_8048723C(void);
extern void fn_8048763C(void);
extern void fn_80488364(void);
extern void fn_8048841C(void);
extern void fn_8048842C(void);
extern void fn_8048846C(void);
extern void fn_80487B58(void);
extern void fn_80487CC0(void);
extern void fn_80487D00(void);
extern void fn_80487C0C(void);
extern u8 fn_80487C48(void);
extern u8 fn_80487C84(void);
extern u32 fn_80488938(void);
extern void fn_804881DC(void);
extern void fn_8048821C(void);
extern void fn_80488114(void *cb);

extern u32 lbl_805DD628;
extern u32 lbl_805DD62C;
extern s32 lbl_805DD630;
extern s32 *lbl_805DD63C;
extern s32 lbl_805DD640;
extern u16 lbl_805DD644;
extern void kar_lbaudio__near_8006293c(s32 arg0);
extern void HSD_PadReadStatus(void *arg0);
extern void HSD_PadResetRawErrorChannels(void *arg0);
extern u8 HSD_PadGetMappedRawQueueCount(void);
extern void HSD_PadPushMappedRawQueue(void *arg0, s32 arg1, s32 arg2, s32 arg3,
                                       s32 arg4, s32 arg5, s32 arg6, s32 arg7);
extern void HSD_PadFlushMappedQueue();
extern void kar_lbaudio__near_80062900(s32 arg0);
extern void kar_lbaudio__near_80062ae0(void *cb, void *data, s32 arg2, void *arg3, s32 arg4);
extern void kar_textlib__near_800aac90(void);
extern void kar_lbarchive__80059a20(s32 arg0, char *name, s32 **out, char *tag,
                                     s32 arg4, void *arg5);
extern void kar_dbscreenshot__near_8008aa0c(void);
extern void HSD_PadClearMasterStatus();
extern void HSD_PadClearMappedMasterStatus(void);
extern void HSD_PadClearCopyStatus(void);
extern void HSD_PadClearMappedCopyStatus(void);
extern void HSD_PadFlushQueue(s32 arg0);
extern s32 *HSD_RandSeedPtr;

typedef struct HSDPadState {
    u8 pad0[0x11];
    s8 unk11;
    s8 unk12;
    s8 unk13;
    s8 unk14;
    s8 unk15;
    s8 unk16;
    s8 unk17;
    s8 unk18;
    s8 unk19;
} HSDPadState;
extern HSDPadState HSD_PadState;

void fn_8007E8CC(void);
void fn_8008122C(void);
void fn_8007FCDC(void);
void fn_80080714(void);
void fn_80081090(void);
extern void kar_ef_assets__asset_80095d18(void);
void fn_8008294C(void);
void fn_80083CF4(void);
extern void kar_dbcamera__near_80098ad8(void);
void fn_80083DF4(void);
void fn_80084BF0(void);
void fn_8007EF88(void);
extern void kar_dbcamera__near_80096cbc(void);
extern u32 PADRead(PADStatus *status);
extern void VIWaitForRetrace(void);

extern s32 fn_8000A4EC(s32 arg0);
extern void kar_dbscreenshot__near_8008c3ec(u8 arg0, s32 arg1, s32 arg2,
                                             u32 arg3, void *arg4, f32 arg5,
                                             f32 arg6);
void fn_8007EA40(s32 arg0, s32 arg1, s32 arg2);
void fn_8007F72C(s32 arg0);
void fn_8007FC50(void);
void fn_8008062C(s32 arg0);
void fn_80080710(void);
void fn_8008108C(void);
extern void kar_dbcamera__near_80098b28(s32 arg0);
extern void kar_dbcamera__near_80095f10(s32 arg0);
void fn_80083058(s32 arg0);
void fn_80083D8C(s32 arg0);
void fn_80081600(s32 arg0);
void *fn_80083E4C(s32 arg0);
void fn_80085C48(s32 arg0);
void fn_8007EDA8(s32 arg0);
extern void kar_dbscreenshot__near_8008cee8(s32 arg0);
extern void kar_dbcamera__near_80096d34(s32 arg0);
extern void kar_dbmapgravity__near_800aacc0(s32 arg0);

extern void kar_pslist__near_8043a778(s32 arg0, s32 arg1);
extern void kar_pslist__near_8043aa00(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void kar_pslist__near_8043a1cc(void *arg0, s32 arg1);
extern void kar_debugconsole_main__near_8043ffb4(s32 arg0);
extern void kar_debugconsole_main__near_8043ffac(s32 arg0);
extern void kar_debugconsole_main__near_8043fd28(s32 arg0);
extern void kar_debugconsole_main__near_80440130(void *cb1, void *cb2, s32 arg2);
extern void *kar_lbaudio__near_80062a80(void);
extern s32 DBIsDebuggerPresent(void);
extern void *OSAllocFromArenaLo(u32 size, u32 align);
extern void kar_grcoll__803cf058(s32 arg0, s32 arg1);
extern void kar_grcoll__803cd3ac(s32 arg0, void *arg1);
extern void kar_grcoll__803cd2b8(s32 arg0, void *arg1);
extern void kar_grcoll__803d1670(void *arg0, void *arg1);
extern void kar_grcoll__803d1978(void *mtx, f32 x, f32 y, f32 z, ...);
extern void fn_803D1528(void *arg0, void *arg1);
static char *lbl_805DEDE8 = "Gm Timeclear";
static s32 lbl_805DEDEC = 0x80;
static void *lbl_805DEDF0 = (void *) 0xFFFFFFFF;

extern void *kar_gmmain__near_80006c14(void *arg0);
extern void *kar_gmmain__near_80005cbc(void);
extern void *kar_textlib__800ab2d4(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, void *cb);
extern void kar_textlib__near_800aac90(void);
extern void kar_textlib__near_800ab4c0(void *w, s32 x, u32 y);
extern void kar_textlib__near_800ab50c(void *w, void *arg1);
extern void kar_textlib__near_800ab534(void *w, f32 x, f32 y);
extern void kar_textlib__near_800ab55c(void *w, void *arg1, ...);
extern void kar_textlib__near_800ab584(void *w, void *arg1, ...);
extern void kar_textlib__near_800ab5a4(void *w);
extern void kar_textlib__near_800ab78c(void *w, void *fmt, ...);
extern s32 kar_plclearcheckerlib__near_8022c858(s32 arg0);
extern s8 fn_8000A97C(void);
extern s8 fn_8000B1EC(s32 arg0);
extern s8 kar_plclearcheckerlib__8023156c(s32 arg0);
extern s32 kar_plclearcheckerlib__8022eb88(s32 arg0);
extern s8 kar_plclearcheckerlib__802306d4(s32 arg0);
extern s8 kar_plclearcheckerlib__8022eb10(s32 arg0, s32 arg1);
extern s8 kar_plclearcheckerlib__8022ea98(s32 arg0, s32 arg1);
extern s8 kar_plclearchecker_get_state_u32_7d4(s32 arg0);
extern s32 kar_gmmain__near_80005d04(s32 arg0);
extern void *kar_gmglobal__near_8000771c(void);
extern void *kar_gmglobal__near_8000774c(void);

typedef struct LbNetDebugTextHandle {
    void *unk0;
    s32 unk4;
    u8 unk8;
} LbNetDebugTextHandle;
static LbNetDebugTextHandle lbl_80552DD8;
static void *lbl_80552DE8[8];

void fn_8007ED34(void);
void fn_8007EF00(void);
void fn_8007EF44(void);
extern void HSD_VISetUserPreRetraceCallback(void *cb);
extern void HSD_VISetUserPostRetraceCallback(void *cb);
extern char lbl_8049B1E0[];
extern u8 lbl_8049B300[0x5E0];
extern u8 lbl_805D5430;
extern u8 lbl_805D5434;
extern u8 lbl_805D5438;
extern u8 lbl_805D543C;
extern u8 lbl_805D5440;
extern void **lbl_805DD648;
typedef struct LbNetDebugCursor {
    u8 unk0;
    u8 unk1;
    u8 unk2;
} LbNetDebugCursor;
extern LbNetDebugCursor lbl_805DD64C;

typedef struct LbNetDebugPage {
    void *unk0;
    u8 pad1[4];
    u8 unk5;
} LbNetDebugPage;
extern u8 kar_gmracenormal__8000aea8(void);
extern void **HSD_Alloc(s32 size);
extern u32 lbl_8049B8E0[];
void fn_8007E93C(void);
void fn_8007E964(void);
extern u8 lbl_805D5448;
extern u8 lbl_805D5450;
extern u8 lbl_805D5458;
extern u8 lbl_805D5460;
extern u8 lbl_805D5464;
extern u8 lbl_805D546C;
extern u8 lbl_805D5470;
extern u8 lbl_805D5474;
extern u8 jumptable_8049B954[];
extern u8 jumptable_8049B930[];
extern u8 jumptable_8049B9A4[];
extern u8 jumptable_8049B978[];
extern void *kar_plclearchecker_get_player_index_for_slot(s32 arg0);
extern void *kar_plclearchecker_get_player_object(void);
extern void *kar_cmreplay__8022cb74(void *arg0);
void fn_8007FE04(void *arg0);
void fn_8007FE4C(void *arg0);
void fn_8007FEF4(void *arg0);
void fn_8007FC98(void);
void fn_8007FC54(void);
extern s32 fn_8019262C(void);
extern void fn_80192650(void *arg0);
extern void fn_800807E0(void *arg0);
extern void fn_80192528(s32 arg0, s32 arg1);
extern s32 fn_80192688(void);
extern void fn_801926AC(void *arg0, s32 arg1);
void fn_8008115C(s32 arg0, s32 arg1);
extern s8 kar_diag__8000acb0(void);
extern s32 fn_80192950(void *arg0);
void fn_80081208(void *arg0, s32 arg1, void *arg2);
void fn_80080FEC(void);
extern void fn_80009BEC(void);
extern s32 fn_80191C84(void);
extern void kar_dbscreenshot__near_8008c718(u8 arg0);
extern void kar_dbscreenshot__near_8008c63c(u8 arg0);
extern u16 lbl_805D5478[];
extern s32 fn_80192764(void *arg0, u16 *tbl, u16 arg2);
void fn_80080804(void *arg0, s32 arg1);
void fn_80080858(void *arg0, s32 arg1);
void fn_80083D20(void *arg0, u8 arg1);
extern u16 lbl_8049B9D0[8];
extern void kar_mpcoll_refresh_forward_debug_volume_enabled(void *arg0);
void fn_8007F58C(void);
static s32 lbl_805DEE00 = 0x40;
static void *lbl_805DEE04 = (void *) 0xFFFFFFFF;

extern u8 HSD_PadMasterStatus[0x550];
extern LbNetDebugPage lbl_805DD650;
extern u8 lbl_805D5480;
extern u8 lbl_805D5484;
extern u8 lbl_805D5488;
extern u8 lbl_805D548C;
extern u8 lbl_805D5494;
extern u8 lbl_805D5498;
extern u8 lbl_805D549C;
extern u8 lbl_805D54A0;
extern u8 lbl_805D54A4;
extern u8 lbl_805D54A8;
extern u8 lbl_805D54B0;
extern u16 lbl_8049B9F0[];
extern void kar_mpcoll__near_801d1048(void *arg0, void *tbl, u16 arg2, u16 arg3);
extern LbNetDebugPage lbl_805DD658;
extern u32 lbl_805E62E8;
static void *lbl_805DEE40 = (void *) 0xFF;
void fn_80080934(void *arg0);
extern void kar_plclearchecker_get_template_vecs_014_020(void *arg0, f32 *arg1);
extern void kar_plclearchecker_get_template_vec_008(s32 arg0, void *arg1);
extern void kar_vcgenerator__801dffdc(s32 arg0, void *arg1, void *arg2, f32 *arg3,
                                       s32 arg4, s32 arg5, s32 arg6, f32 arg7);
extern void fn_801DB278(void *arg0);
static void *lbl_80552E08[0xE];
static s32 lbl_805D54F0 = 0;
extern void *lbl_805D54F4;
extern u8 lbl_805D54B8;
extern u8 lbl_805D54BC;
extern u8 lbl_805D54C0;
extern s8 fn_801C7CF4(f32 *arg0);
extern u8 lbl_8049BA18[0x44];
extern u8 lbl_805D54F8;
extern u8 lbl_805D54FC;
extern u8 lbl_805D5500;
extern u8 lbl_805D5504;
extern u8 lbl_805D5508;
extern u8 lbl_805D550C;
extern u8 lbl_805D5510;
extern u8 lbl_805D5514;
extern u8 lbl_805D5518;
extern u8 lbl_805D5520;
extern u8 lbl_805D5528;
extern u8 lbl_805D5548;
extern u8 lbl_805D5550;
extern u8 lbl_805D5558;
extern s32 lbl_805D5530;
extern s32 lbl_805D5538;
extern s32 lbl_805D5540;
static s32 *lbl_8049BA60[4] = { &lbl_805D5530, &lbl_805D5538, &lbl_805D5540, NULL };
extern void kar_collision_build_obb_face_data(void *arg0, void *arg1);
extern s32 kar_collision_object_get_max_linked_state(void *arg0);

typedef struct LbNetGeneInfoState {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    s32 unk4;
    s32 unk8;
    void *unkC;
    f32 unk10;
    f32 unk14;
    s32 unk18;
    s32 unk1C;
    u8 pad20[0x9C];
    f32 unkBC;
    f32 unkC0;
    f32 unkC4;
    f32 unkC8;
    f32 unkCC;
    f32 unkD0;
    s32 unkD4;
    u8 pad[0x60];
} LbNetGeneInfoState;
static LbNetGeneInfoState lbl_80552E40;
extern s32 fn_800B8808(void);
extern s32 fn_800B8054(void);
extern void kar_gmmain__near_80005d54(void);
extern u8 lbl_805D5578;
extern u8 lbl_805D5580;
extern u8 lbl_805D5584;
extern u8 lbl_805D558C;
extern u8 lbl_805D5590;
extern u8 lbl_8049BA70[0x24];
extern u8 lbl_805D5598;
extern s32 kar_emupdate__near_8020438c(void *arg0);
extern void kar_emupdate__near_8020435c(void *arg0, s32 *arg1, f32 *arg2);
extern void *kar_emupdate__near_80204374(void *arg0);
extern void *kar_emupdate__near_80204380(void *arg0);
extern void splArcLengthPoint(void *arg0, void *arg1);
extern u8 lbl_805D55A0;
extern u8 lbl_805D55A8;
extern u8 lbl_80557808;
extern u8 lbl_80557814;
extern s32 lbl_805D5570;
extern void *lbl_805D5574;
void fn_800839BC(s32 arg0, f32 *arg1, f32 *arg2);
void fn_80083AAC(f32 *arg0, f32 *arg1, f32 *arg2);
void fn_80083B90(void *arg0, void *arg1);
void fn_80083CBC(void);
extern void kar_grcommon_get_startpos_vectors_by_index(s32 arg0, f32 *arg1, f32 *arg2, f32 *arg3);
extern void kar_grcommon__near_800cee24(f32 *arg0, s32 *arg1);
extern f32 kar_grcommon__near_800d066c(s32 arg0, s32 arg1, f32 arg2, f32 arg3);
typedef struct LbNetSubsystemFlag {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    s8 unk3;
} LbNetSubsystemFlag;
extern LbNetSubsystemFlag lbl_805DD660;
extern void *kar_wneffect__near_8022312c(void *arg0);
typedef struct LbNetGeneInfo2 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    u8 pad28[8];
    u32 unk30;
} LbNetGeneInfo2;
static LbNetGeneInfo2 lbl_80552F78;
void fn_800848E0(void *arg0, s32 arg1);
extern void *lbl_805DEEB8;
extern void *lbl_805DEEBC;
void fn_800841A0(void *win);
extern s32 lbl_805D5648;
extern void *lbl_805D564C;
extern u8 lbl_80552FB0[0x400];
extern u32 HSD_GObjCreate(u32 arg0, u32 arg1, u32 arg2);
extern void HSD_GObjGXLink(u32 gobj, void *cb, u32 arg1, u32 arg2);
extern void fn_801AE4EC(void *arg0);
extern u32 lbl_805E62E0;
static void *lbl_805DEE20 = (void *) 0xFF;
extern void fn_801C81C0(f32 *arg0);
extern void fn_801C8290(void *arg0, f32 *arg1);
extern void fn_8019259C(void *arg0, f32 *arg1);
void fn_80080804(void *arg0, s32 arg1);
void fn_80080858(void *arg0, s32 arg1);
void fn_80083D20(void *arg0, u8 arg1);

static LbNetPadRecord lbl_80552A30[0x14];
static u32 lbl_80552C2C[0x57];
static LbNetInputRecord lbl_80552D88[4];

char kar_upnp_rootdesc_xml_8049ae10[0x2B5];
static char *kar_upnp_rootdesc_xml_ptr_805D5408 = kar_upnp_rootdesc_xml_8049ae10;
static char kar_srcfile_lbnet_c_805d540c[8] = "lbnet.c";

extern void *hsdGObj_p_link_heads[];

#define TotalMemorySize lbl_805DD628
#define DebugLap lbl_805DD62C

void kar_shadow__near_8007b4c8(void *arg0) {
    u32 flag;

    kar_gmlanmenu__near_80052f7c(0x04000000);
    flag = (arg0 == NULL) ? 0U : FU32(arg0, 0x10);
    if (flag != 0U) {
        kar_gmlanmenu__near_80052fb8(arg0, 0x04000000);
    }
}

s32 NetAlloc(void *unused, s32 arg1) {
    s32 result;
    void *block;
    s32 size;

    if (arg1 > 0) {
        kar_diagnostic__803d7e58(lbl_80552A30);
        size = (arg1 + 0x1F) & 0xFFFFFFE0;
        block = kar_lbmemory__near_8005884c(5, size);
        result = (block != NULL) ? FS32(block, 4) : 0;
        TotalMemorySize += size;
        kar_diagnostic__803d7f34(lbl_80552A30);
        return result;
    }
    return 0;
}

void NetFree(void *unused, s32 arg1, s32 arg2) {
    if ((arg1 != 0) && (arg2 > 0)) {
        kar_diagnostic__803d7e58(lbl_80552A30);
        kar_lbheap__80058920(5, (void *) arg1);
        TotalMemorySize -= (arg2 + 0x1F) & 0xFFFFFFE0;
        kar_diagnostic__803d7f34(lbl_80552A30);
    }
}

s32 kar_shadow__near_8007b624(void) {
    return FS32(lbl_80552A30, 0x18) != 0;
}

s32 kar_shadow__near_8007b640(void) {
    return lbl_80552A30[1].unk3;
}

s32 kar_shadow__near_8007b650(void) {
    return lbl_80552A30[1].unk3 != 0;
}

void kar_shadow__near_8007b66c(void) {
    lbl_80552A30[1].unk7 = 0;
    fn_804889C0(lbl_80552A30);
}

void kar_shadow__near_8007b69c(s32 arg0) {
    lbl_80552A30[1].unk7 = arg0;
}

s32 kar_gmlanmenu__8007b6ac(void) {
    u32 val;

    if (lbl_80552A30[1].unk7 != 0) {
        return lbl_80552A30[1].unk7;
    }
    val = fn_80488938();
    switch (val) {
    case 0: return 0;
    case 1: return 1;
    case 2: return 2;
    case 3: return 3;
    case 4: return 4;
    case 5: return 5;
    case 6: return 6;
    case 7: return 7;
    case 8: return 8;
    case 9: return 9;
    case 10: return 0xA;
    default:
        assert_line(0x161, 0);
        return 0;
    }
}

void initBroadbandInfo(void) {
    fn_804871EC();
}

void kar_shadow__near_8007b790(void) {
    fn_8048723C();
}

void kar_gmlanmenu__8007b7b0(void) {
    fn_803D7E20(lbl_80552A30);
    fn_804872CC(NetAlloc, NetFree, kar_upnp_rootdesc_xml_ptr_805D5408);
    FS32(lbl_80552A30, 0x18) = 1;
}

void kar_shadow__near_8007b800(void) {
    fn_8048763C();
}

void kar_gmlanmenu__8007b820(void) {
    fn_80488364();
}

void kar_gmlanmenu__8007b840(void) {
    fn_8048841C();
}

void kar_gmlanmenu__8007b860(void) {
    fn_8048842C();
}

void kar_gmlanmenu__8007b880(void) {
    fn_8048846C();
    assert_line_str(0x1B4, TotalMemorySize == 0, lbl_8049B0F4);
    lbl_80552A30[1].unk7 = 0;
    FS32(lbl_80552A30, 0x18) = 0;
}

void kar_gmlanmenu__8007b8d4(void) {
    fn_80487B58();
}

void kar_shadow__near_8007b8f4(void) {
    fn_80487CC0();
}

void kar_shadow__near_8007b914(void) {
    fn_80487D00();
}

void kar_shadow__near_8007b934(void) {
    fn_80487C0C();
}

u8 kar_shadow__near_8007b954(void) {
    if (lbl_80552A30[1].unkB != 0) {
        return lbl_80552A30[1].unkC;
    }
    return fn_80487C48();
}

u8 kar_shadow__near_8007b990(void) {
    if (lbl_80552A30[1].unkB != 0) {
        return lbl_80552A30[1].unkD;
    }
    return fn_80487C84();
}

s32 kar_shadow__near_8007b9cc(LbNetCirculationData *net_recv, void *out) {
    u8 hist[0x154];
    s32 became_stable;
    s32 sp8[3];
    void *history;
    void *outHistory;
    void *entry;
    s32 count;
    s32 i;
    u8 mine;

    became_stable = 0;
    assert_line_str(0x216, (net_recv == NULL && DebugLap == 0) ||
                        (net_recv != NULL && DebugLap == net_recv->lap), lbl_8049B10C);
    assert_line_str(0x217, net_recv == NULL || net_recv->len == sizeof(LbNetCirculationData), lbl_8049B164);

    if (net_recv != NULL) {
        DebugLap += 1;
    }
    if (lbl_80552A30[1].unkD == 0) {
        kar_lbaudio__near_8006293c(1);
    }

    history = (net_recv != NULL) ? (u8 *) net_recv + 6 : NULL;
    outHistory = (u8 *) out + 6;
    entry = (u8 *) lbl_80552A30 + 0xA8;

    if (lbl_80552A30[1].unkF != 0U) {
        memcpy(hist, entry, 0x14C);
        if (lbl_80552A30[1].unkD == 0) {
            count = 0;
            for (i = 0; i < lbl_80552A30[1].unkC; i++) {
                if (FU8(hist, 0x38 + i * 0x54) != 0) {
                    count++;
                }
            }
            became_stable = (count == lbl_80552A30[1].unkC);
        } else {
            became_stable = 1;
        }
    } else {
        if ((lbl_80552A30[1].unkF == 0U) &&
            ((lbl_80552A30[1].unkB != 0) || (lbl_80552A30[1].unkD == 0))) {
            memset(outHistory, 0, 0x14C);
        } else {
            memcpy(outHistory, history, 0x14C);
        }
        if (FS32(lbl_80552A30, 0x34) == 0) {
            HSD_PadReadStatus(sp8);
            HSD_PadResetRawErrorChannels(sp8);
        }
        mine = HSD_PadGetMappedRawQueueCount();
        if (mine != 0) {
            kar_lbaudio__near_80062900(0);
        }
        if ((lbl_80552A30[1].unkF != 0U) || (lbl_80552A30[1].unkD != 0) ||
            (lbl_80552A30[1].unkB != 0)) {
            memcpy(entry, history, 0x14C);
        }
        lbl_80552A30[1].unkF += 1;
    }
    return became_stable;
}

void kar_shadow__near_8007c888(void) {
    kar_shadow__near_8007b9cc((LbNetCirculationData *) lbl_80552C2C, lbl_80552C2C);
    lbl_80552C2C[0] += 1;
}

void kar_shadow__near_8007c8c8(s8 arg0, u8 arg1, void *arg2, s32 arg_sp0) {
    s32 level;
    s32 kind;
    u8 ver;
    LbNetPadRecord *rec;

    level = OSDisableInterrupts();
    DebugLap = 0U;
    kind = (arg0 == 2) ? 2 : 1;
    lbl_80552A30[1].unk3 = kind;
    lbl_80552A30[1].unkC = (u8) arg0;
    lbl_80552A30[1].unkD = arg1;
    lbl_80552A30[1].unkF = 0U;
    lbl_80552A30[1].unk13 = 0;
    FS32(lbl_80552A30, 0x34) = 0;
    FS32(lbl_80552A30, 0x38) = 1;
    ver = DVDGetCurrentDiskID()->gameVersion;
    FU8(lbl_80552A30, arg1 * 0x19 + 0x44) = ver;
    FU8(lbl_80552A30, 0x3C) = ver;
    if (lbl_80552A30[1].unkD == 0) {
        FS32(lbl_80552A30, 0x40) = *HSD_RandSeedPtr;
    }
    if (arg2 != NULL) {
        rec = &lbl_80552A30[arg1];
        memcpy((u8 *) rec + 0x45, arg2, 0x18);
    }
    HSD_PadClearMasterStatus();
    HSD_PadClearMappedMasterStatus();
    HSD_PadClearCopyStatus();
    HSD_PadClearMappedCopyStatus();
    HSD_PadFlushQueue(1);
    HSD_PadFlushMappedQueue(1);
    HSD_PadState.unk11 = arg1;
    HSD_PadState.unk12 = -1;
    HSD_PadState.unk13 = -1;
    HSD_PadState.unk14 = -1;
    HSD_PadState.unk15 = -1;
    HSD_PadState.unk16 = -1;
    HSD_PadState.unk17 = -1;
    HSD_PadState.unk18 = -1;
    HSD_PadState.unk19 = -1;
    OSRestoreInterrupts(level);
}

void fn_8007CAB0(void *arg0, s32 arg1) {
    u8 kind;
    u8 count;

    count = (lbl_80552A30[1].unkB != 0) ? lbl_80552A30[1].unkD : fn_80487C84();
    kind = (lbl_80552A30[1].unkB != 0) ? lbl_80552A30[1].unkC : fn_80487C48();
    kar_shadow__near_8007c8c8((s8) kind, count, arg0, arg1);
    lbl_80552A30[1].unkB = 0;
    fn_80488114(kar_shadow__near_8007b9cc);
}

void fn_8007CB60(void) {
    kar_shadow__near_8007c8c8(0, 0, NULL, 0);
    lbl_80552C2C[0] = 0U;
    lbl_80552A30[1].unkB = 1;
    lbl_80552C2C[1] = 0x154;
    kar_lbaudio__near_80062ae0(kar_shadow__near_8007c888, lbl_80552C2C, 0,
                                lbl_80552A30, 1);
}

void fn_8007CBB0(void) {
    s32 level;

    if (lbl_80552A30[1].unk3 != 0) {
        level = OSDisableInterrupts();
        lbl_80552A30[1].unk13 = 1;
        HSD_PadFlushMappedQueue(1);
        if (lbl_80552A30[1].unkD == 0) {
            FS32(lbl_80552A30, 0x30) = *HSD_RandSeedPtr;
        }
        OSRestoreInterrupts(level);
    }
}

void fn_8007CC30(void) {
    s32 level;

    if (lbl_80552A30[1].unk3 != 0) {
        level = OSDisableInterrupts();
        if (lbl_80552A30[1].unk13 == 2) {
            lbl_80552A30[1].unk13 = 0;
            *HSD_RandSeedPtr = FS32(lbl_80552A30, 0x30);
        }
        OSRestoreInterrupts(level);
    }
}

void *fn_8007CC90(u8 arg0) {
    return (u8 *) &lbl_80552A30[arg0] + 0x45;
}

void fn_8007CCAC(void) {
    *HSD_RandSeedPtr = FS32(lbl_80552A30, 0x40);
}

void fn_8007CCC4(void) {
    s32 level;

    level = OSDisableInterrupts();
    FS32(lbl_80552A30, 0x34) = 1;
    lbl_80552A30[1].unk3 = 0;
    HSD_PadClearMasterStatus();
    HSD_PadClearMappedMasterStatus();
    HSD_PadClearCopyStatus();
    HSD_PadClearMappedCopyStatus();
    HSD_PadFlushQueue(1);
    HSD_PadFlushMappedQueue(1);
    HSD_PadState.unk11 = 0;
    HSD_PadState.unk12 = 0;
    HSD_PadState.unk13 = 0;
    HSD_PadState.unk14 = 0;
    HSD_PadState.unk15 = 1;
    HSD_PadState.unk16 = 0;
    HSD_PadState.unk17 = 2;
    HSD_PadState.unk18 = 0;
    HSD_PadState.unk19 = 3;
    OSRestoreInterrupts(level);
}

void fn_8007CD6C(void) {
    s32 level;

    level = OSDisableInterrupts();
    FS32(lbl_80552A30, 0x34) = 1;
    lbl_80552A30[1].unk3 = 0;
    HSD_PadClearMasterStatus();
    HSD_PadClearMappedMasterStatus();
    HSD_PadClearCopyStatus();
    HSD_PadClearMappedCopyStatus();
    HSD_PadFlushQueue(1);
    HSD_PadFlushMappedQueue(1);
    HSD_PadState.unk11 = 0;
    HSD_PadState.unk12 = 0;
    HSD_PadState.unk13 = 0;
    HSD_PadState.unk14 = 0;
    HSD_PadState.unk15 = 1;
    HSD_PadState.unk16 = 0;
    HSD_PadState.unk17 = 2;
    HSD_PadState.unk18 = 0;
    HSD_PadState.unk19 = 3;
    OSRestoreInterrupts(level);
}

void fn_8007CE14(void) {
    fn_804881DC();
}

void fn_8007CE34(void) {
    fn_8048821C();
}

void fn_8007CE54(void) {
    FS32(lbl_80552A30, 0x18) = 0;
    lbl_80552A30[1].unk3 = 0;
    lbl_80552A30[1].unk7 = 0;
}

void fn_8007CE70(void) {
    PADStatus pad[4];
    s32 ok;
    s32 idx;

    do {
        VIWaitForRetrace();
        PADRead(pad);
        ok = 1;
        if ((pad[0].err == -2) || (pad[0].err == -3)) {
            ok = 0;
        }
        if ((pad[1].err == -2) || (pad[1].err == -3)) {
            ok = 0;
        }
        if ((pad[2].err == -2) || (pad[2].err == -3)) {
            ok = 0;
        }
        if ((pad[3].err == -2) || (pad[3].err == -3)) {
            ok = 0;
        }
    } while (ok == 0);
    idx = 0;
    if (pad[0].err != 0) {
        idx = 1;
        if (pad[1].err != 0) {
            idx = 2;
            if (pad[2].err != 0) {
                idx = 3;
                if (pad[3].err != 0) {
                    idx = 4;
                }
            }
        }
    }
    lbl_805DD644 = (idx != 4) ? pad[idx].button : 0;
}

void kar_db_assets__asset_8007cf78(void) {
    if (lbl_805DD630 >= 3) {
        kar_textlib__near_800aac90();
        lbl_80552D88[0].unk0 = 0;
        lbl_80552D88[0].unk8 = 0;
        lbl_80552D88[0].unkC = 0;
        lbl_80552D88[0].unk10 = 0;
        lbl_80552D88[1].unk0 = 0;
        lbl_80552D88[1].unk8 = 0;
        lbl_80552D88[1].unkC = 0;
        lbl_80552D88[1].unk10 = 0;
        lbl_80552D88[2].unk0 = 0;
        lbl_80552D88[2].unk8 = 0;
        lbl_80552D88[2].unkC = 0;
        lbl_80552D88[2].unk10 = 0;
        lbl_80552D88[3].unk0 = 0;
        lbl_80552D88[3].unk8 = 0;
        lbl_80552D88[3].unkC = 0;
        lbl_80552D88[3].unk10 = 0;
        lbl_805DD640 = 0;
        kar_lbarchive__80059a20(0, "DbCommon.dat", &lbl_805DD63C,
                                 "dbLoadCommonData", 0, lbl_80552D88);
        kar_dbscreenshot__near_8008aa0c();
        fn_8007E8CC();
        fn_8008122C();
        fn_8007FCDC();
        fn_80080714();
        fn_80081090();
        kar_ef_assets__asset_80095d18();
        fn_8008294C();
        fn_80083CF4();
        kar_dbcamera__near_80098ad8();
        fn_80083DF4();
        fn_80084BF0();
        fn_8007EF88();
        kar_dbcamera__near_80096cbc();
    }
}

void fn_8007D050(void) {
    LbNetInputRecord *rec;
    u8 *entry;
    s32 buttons;
    u32 raw;
    s32 i;

    if (lbl_805DD630 < 3) {
        return;
    }
    rec = lbl_80552D88;
    for (i = 0; i < 4; i++) {
        if (fn_8000A4EC(5) == 1) {
            buttons = 0;
            raw = 0;
        } else {
            entry = HSD_PadMasterStatus + i * 0x44;
            buttons = FS32(entry, 0);
            raw = FU32(entry, 0xC);
        }
        if (buttons & 8) {
            if (buttons & 1) {
                buttons &= ~9;
            }
            if (buttons & 2) {
                buttons &= ~0xA;
            }
        }
        if (buttons & 4) {
            if (buttons & 1) {
                buttons &= ~5;
            }
            if (buttons & 2) {
                buttons &= 0xFFFFFFF9;
            }
        }
        if (raw & 8) {
            if (raw & 1) {
                raw &= ~9;
            }
            if (raw & 2) {
                raw &= ~0xA;
            }
        }
        if (raw & 4) {
            if (raw & 1) {
                raw &= ~5;
            }
            if (raw & 2) {
                raw &= 0xFFFFFFF9;
            }
        }
        rec->unk4 = rec->unk0;
        rec->unk0 = buttons;
        rec->unk8 = rec->unk0 & (rec->unk4 ^ rec->unk0);
        rec->unkC = rec->unk4 & (rec->unk4 ^ rec->unk0);
        rec->unk10 = raw;
        rec++;
    }
    rec = lbl_80552D88;
    for (i = 0; i < 4; i++) {
        entry = HSD_PadMasterStatus + i * 0x44;
        kar_dbscreenshot__near_8008c3ec((u8) i, rec->unk0, rec->unk8, rec->unk10,
                                         entry, FF32(entry, 0x28), FF32(entry, 0x2C));
        rec++;
    }
    rec = lbl_80552D88;
    for (i = 0; i < 4; i++) {
        fn_8007EA40(i, rec->unk0, rec->unk8);
        rec++;
    }
    for (i = 0; i < 4; i++) {
        fn_8007F72C(i);
    }
    fn_8007FC50();
    for (i = 0; i < 4; i++) {
        fn_8008062C(i);
    }
    fn_80080710();
    fn_8008108C();
    for (i = 0; i < 4; i++) {
        u8 *e = (u8 *) &lbl_80552D88[i];
        if (!(FS32(e, 0) & 0x460) && (FS32(e, 8) & 4)) {
            lbl_805DD640 += 1;
            if (lbl_805DD640 >= 0xB) {
                lbl_805DD640 = 0;
            }
        }
    }
    for (i = 0; i < 4; i++) {
        kar_dbcamera__near_80098b28(i);
    }
    for (i = 0; i < 4; i++) {
        kar_dbcamera__near_80095f10(i);
    }
    for (i = 0; i < 4; i++) {
        fn_80083058(i);
    }
    for (i = 0; i < 4; i++) {
        fn_80083D8C(i);
    }
    for (i = 0; i < 4; i++) {
        fn_80081600(i);
    }
    for (i = 0; i < 4; i++) {
        fn_80083E4C(i);
    }
    for (i = 0; i < 4; i++) {
        fn_80085C48(i);
    }
    for (i = 0; i < 4; i++) {
        fn_8007EDA8(i);
    }
    for (i = 0; i < 4; i++) {
        kar_dbscreenshot__near_8008cee8(i);
    }
    for (i = 0; i < 4; i++) {
        kar_dbcamera__near_80096d34(i);
    }
    kar_dbmapgravity__near_800aacc0(7);
}

s32 fn_8007D42C(s32 arg0) {
    return lbl_80552D88[arg0].unk0;
}

s32 fn_8007D440(s32 arg0) {
    return lbl_80552D88[arg0].unk8;
}

u32 fn_8007D458(s32 arg0) {
    return lbl_80552D88[arg0].unk10;
}

s32 fn_8007D470(void) {
    return lbl_805DD640 == 1;
}

s32 fn_8007D484(void) {
    return lbl_805DD640 == 2;
}

s32 fn_8007D498(void) {
    return lbl_805DD640 == 3;
}

s32 fn_8007D4AC(void) {
    return lbl_805DD640 == 4;
}

s32 fn_8007D4C0(void) {
    return lbl_805DD640 == 5;
}

s32 fn_8007D4D4(void) {
    return lbl_805DD640 == 6;
}

s32 fn_8007D4E8(void) {
    return lbl_805DD640 == 7;
}

s32 fn_8007D4FC(void) {
    return lbl_805DD640 == 8;
}

s32 fn_8007D510(void) {
    return lbl_805DD640 == 9;
}

s32 fn_8007D524(void) {
    return lbl_805DD640 == 0xA;
}

s32 fn_8007D538(void) {
    return lbl_805DD63C[9];
}

s32 fn_8007D544(void) {
    return lbl_805DD63C[0xA];
}

s32 fn_8007D550(void) {
    return lbl_805DD63C[0xB];
}

s32 fn_8007D55C(void) {
    return *lbl_805DD63C;
}

s32 *fn_8007D568(void) {
    return (s32 *) lbl_805DD63C[1];
}

s32 *fn_8007D574(void) {
    return (s32 *) lbl_805DD63C[2];
}

s32 fn_8007D580(void) {
    return lbl_805DD63C[3];
}

s32 fn_8007D58C(void) {
    return lbl_805DD63C[0xC];
}

s32 *fn_8007D598(void) {
    return (s32 *) lbl_805DD63C[0xD];
}

s32 *fn_8007D5A4(void) {
    return (s32 *) lbl_805DD63C[0xE];
}

s32 fn_8007D5B0(void) {
    return lbl_805DD63C[4];
}

s32 *fn_8007D5BC(void) {
    return (s32 *) lbl_805DD63C[5];
}

s32 *fn_8007D5C8(void) {
    return (s32 *) lbl_805DD63C[6];
}

s32 *fn_8007D5D4(void) {
    return (s32 *) lbl_805DD63C[7];
}

s32 fn_8007D5E0(void) {
    return lbl_805DD63C[8];
}

s32 fn_8007D5EC(void) {
    return lbl_805DD63C[0xF];
}

s32 fn_8007D5F8(void) {
    return lbl_805DD63C[0x10];
}

s32 fn_8007D604(void) {
    return lbl_805DD63C[0x11];
}

s32 fn_8007D610(void) {
    return lbl_805DD63C[0x12];
}

void fn_8007D61C(void) {
    s32 i;
    s32 j;
    s32 n;
    void *node;

    OSReport("[all PLink num] -- Report --\n");
    for (i = 0; i < 0xA; i++) {
        OSReport("%5d ", i);
    }
    OSReport("\n");
    OSReport("------------------------------------------------------------\n");
    for (j = 0; j < 0x40; j++) {
        n = 0;
        node = hsdGObj_p_link_heads[j];
        while (node != NULL) {
            node = *(void **) ((u8 *) node + 8);
            n += 1;
        }
        OSReport("%5d ", n);
        if ((j % 10) == 9) {
            OSReport("\n");
        }
    }
    OSReport("\n");
}

void fn_8007D714(void) {
}

void fn_8007D718(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5,
                  s32 arg6, s32 arg7) {
    AIStopDMA();
    AIRegisterDMACallback(0);
    HSD_VISetUserPreRetraceCallback(0);
    HSD_VISetUserPostRetraceCallback(0);
    OSReport("%s\n", "DATE Aug 18 2003  TIME 16:53:51", kar_lbaudio__near_80062a80());
    OSReport("%s\n", &lbl_8049B1E0);
    kar_pslist__near_8043a778(arg0, 0x10);
    kar_debugconsole_main__near_8043ffb4(0x1388);
    kar_debugconsole_main__near_8043ffac(lbl_805DD630);
    kar_debugconsole_main__near_8043fd28(arg0);
}

void fn_8007D7F0(s32 arg0, s32 arg1, ...) {
    u32 lo;
    u32 hi;
    va_list va;

    va_start(va, arg1);
    lo = va_arg(va, u32);
    hi = va_arg(va, u32);
    va_end(va);
    AIStopDMA();
    AIRegisterDMACallback(0);
    HSD_VISetUserPreRetraceCallback(0);
    HSD_VISetUserPostRetraceCallback(0);
    OSReport("%s\n", "DATE Aug 18 2003  TIME 16:53:51", kar_lbaudio__near_80062a80());
    OSReport("%s\n", &lbl_8049B1E0);
    kar_pslist__near_8043a778(arg1, 0x10);
    kar_pslist__near_8043aa00(arg0, lo, hi, arg1);
    kar_debugconsole_main__near_8043ffb4(0x1388);
    kar_debugconsole_main__near_8043ffac(lbl_805DD630);
    kar_debugconsole_main__near_8043fd28(arg1);
}

void fn_8007D934(void) {
    void *mem;

    if (DBIsDebuggerPresent() == 0) {
        mem = OSAllocFromArenaLo(0x2000, 4);
        kar_pslist__near_8043a1cc(mem, 0x2000);
        kar_debugconsole_main__near_80440130(fn_8007D718, fn_8007D7F0, 1);
    }
}

void fn_8007D988(void *arg0, void *arg1, void *arg2, void *arg3, f32 scale) {
    Mtx viewMtx;
    Mtx m0;
    Mtx m1;
    Mtx m2;
    Vec delta;
    Vec u;
    Vec cross;
    Vec neg;
    f32 mag;
    u8 blend;

    blend = FU8(arg2, 3);
    GXSetColorUpdate(GX_ENABLE);
    GXSetAlphaUpdate(GX_DISABLE);
    GXSetBlendMode((blend == 0xFF) ? 2 : 0, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA,
                   GX_LO_NOOP);
    GXSetAlphaCompare(GX_GREATER, 0, GX_AOP_AND, GX_GREATER, 0);
    GXSetZMode(GX_ENABLE, GX_LEQUAL, blend == 0xFF);
    GXSetZCompLoc(GX_DISABLE);
    GXSetNumTexGens(0);
    kar_grcoll__803cf058(0, 0);
    GXSetNumTevStages(1);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);
    GXSetTevOp(GX_TEVSTAGE0, GX_PASSCLR);
    kar_grcoll__803cd3ac(4, arg2);
    kar_grcoll__803cd2b8(4, arg3);
    GXSetChanCtrl(GX_COLOR0A0, GX_ENABLE, GX_SRC_REG, GX_SRC_REG,
                  HSD_LObjGetLightMaskDiffuse(), GX_DF_CLAMP, GX_AF_NONE);
    GXSetNumChans(1);
    GXSetCullMode(GX_CULL_BACK);
    HSD_CObjGetCurrent();
    HSD_CObjGetViewingMtx(HSD_CObjGetCurrent(), viewMtx);
    PSMTXScale(m0, scale, scale, scale);
    delta.x = FF32(arg0, 0) - FF32(arg1, 0);
    delta.y = FF32(arg0, 4) - FF32(arg1, 4);
    delta.z = FF32(arg0, 8) - FF32(arg1, 8);
    mag = PSVECMag(&delta);
    if (mag < 0.00001f && mag > -0.00001f) {
        PSMTXIdentity(m0);
        m0[0][0] = -1.0f;
        m0[2][2] = -1.0f;
        PSMTXConcat(m0, viewMtx, m1);
    } else {
        if (delta.x < 0.00001f && delta.x > -0.00001f &&
            delta.y < 0.00001f && delta.y > -0.00001f &&
            delta.z < 0.00001f && delta.z > -0.00001f) {
            u.x = 0.0f;
            u.y = delta.z;
            u.z = 0.0f;
        } else {
            u.x = delta.y;
            u.y = -delta.x;
            u.z = 0.0f;
        }
        kar_lbvector_normalize_with_axis_fallback(&delta, &delta);
        kar_lbvector_normalize_with_axis_fallback(&u, &u);
        cross.x = (delta.x * u.y) - (delta.y * u.x);
        cross.y = (delta.z * u.x) - (delta.x * u.z);
        cross.z = (delta.y * u.z) - (delta.z * u.y);
        PSMTXConcat(m0, viewMtx, m1);
        neg.x = -delta.x;
        neg.y = -delta.y;
        neg.z = -delta.z;
        PSMTXConcat(m0, m0, m0);
    }
    kar_grcoll__803d1978(m0, FF32(arg0, 0), FF32(arg0, 4), FF32(arg0, 8));
    PSMTXConcat(m0, m1, m1);
    kar_grcoll__803d1978(m0, FF32(arg1, 0), FF32(arg1, 4), FF32(arg1, 8));
    PSMTXConcat(m0, m0, m0);
    kar_grcoll__803d1978(m0, (FF32(arg0, 0) + FF32(arg1, 0)) * 0.5f,
                         (FF32(arg0, 4) + FF32(arg1, 4)) * 0.5f,
                         (FF32(arg0, 8) + FF32(arg1, 8)) * 0.5f);
    PSMTXConcat(m0, m2, m2);
    GXClearVtxDesc();
    GXSetArray(9, &lbl_8049B300, 6);
    GXSetArray(0xA, (u8 *) &lbl_8049B300 + 0x1A0, 6);
    GXSetVtxDesc(GX_VA_POS, GX_INDEX8);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_TEX_ST, GX_RGBA4, 0xE);
    GXSetVtxDesc(GX_VA_NRM, GX_INDEX8);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_NRM, GX_TEX_S, GX_RGBA4, 0xE);
    PSMTXConcat(viewMtx, m1, m1);
    GXLoadPosMtxImm(m1, GX_PNMTX0);
    HSD_MtxInverse(m1, m1);
    fn_803D1528(m1, m1);
    GXLoadNrmMtxImm(m1, 0);
    GXCallDisplayList((u8 *) &lbl_8049B300 + 0x340, 0x120);
    GXClearVtxDesc();
    GXSetArray(9, &lbl_8049B300, 6);
    GXSetArray(0xA, (u8 *) &lbl_8049B300 + 0x1A0, 6);
    GXSetVtxDesc(GX_VA_POS, GX_INDEX8);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_TEX_ST, GX_RGBA4, 0xE);
    GXSetVtxDesc(GX_VA_NRM, GX_INDEX8);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_NRM, GX_TEX_S, GX_RGBA4, 0xE);
    PSMTXConcat(viewMtx, m0, m0);
    GXLoadPosMtxImm(m0, GX_PNMTX0);
    HSD_MtxInverse(m0, m0);
    fn_803D1528(m0, m0);
    GXLoadNrmMtxImm(m0, 0);
    GXCallDisplayList((u8 *) &lbl_8049B300 + 0x340, 0x120);
    if (!(mag < 0.00001f && mag > -0.00001f)) {
        GXClearVtxDesc();
        GXSetArray(9, (u8 *) &lbl_8049B300 + 0x460, 6);
        GXSetArray(0xA, (u8 *) &lbl_8049B300 + 0x520, 6);
        GXSetVtxDesc(GX_VA_POS, GX_INDEX8);
        GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_TEX_ST, GX_RGBA4, 0xE);
        GXSetVtxDesc(GX_VA_NRM, GX_INDEX8);
        GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_NRM, GX_TEX_S, GX_RGBA4, 0xE);
        PSMTXConcat(viewMtx, m2, m2);
        GXLoadPosMtxImm(m2, GX_PNMTX0);
        HSD_MtxInverse(m2, m2);
        fn_803D1528(m2, m2);
        GXLoadNrmMtxImm(m2, 0);
        GXCallDisplayList((u8 *) &lbl_8049B300 + 0x580, 0x60);
    }
}

void fn_8007E128(void *arg0, void *arg1, void *arg2) {
    *(f32 *) 0xCC008000 = FF32(arg0, 0);
    *(f32 *) 0xCC008000 = FF32(arg0, 4);
    *(f32 *) 0xCC008000 = FF32(arg0, 8);
    *(f32 *) 0xCC008000 = FU8(arg2, 0);
    *(f32 *) 0xCC008000 = FU8(arg2, 1);
    *(f32 *) 0xCC008000 = FU8(arg2, 2);
    *(f32 *) 0xCC008000 = FU8(arg2, 3);
    *(f32 *) 0xCC008000 = FF32(arg1, 0);
    *(f32 *) 0xCC008000 = FF32(arg1, 4);
    *(f32 *) 0xCC008000 = FF32(arg1, 8);
    *(f32 *) 0xCC008000 = FU8(arg2, 0);
    *(f32 *) 0xCC008000 = FU8(arg2, 1);
    *(f32 *) 0xCC008000 = FU8(arg2, 2);
    *(f32 *) 0xCC008000 = FU8(arg2, 3);
}

s32 fn_8007E1A0(u32 kind, void *center, void *dirA, void *dirB) {
    Vec a;
    Vec b;
    Vec cross;
    f32 x, y, z;

    if (kind == 2U) {
        HSD_StateInvalidate(-1);
        HSD_StateInitDirect(GX_VTXFMT0, 2);
        GXLoadPosMtxImm((MtxPtr) ((u8 *) HSD_CObjGetCurrent() + 0x54), GX_PNMTX0);
        GXSetLineWidth(0xC, 5);
        GXBegin(GX_LINES, GX_VTXFMT0, 6);
        a.x = FF32(dirA, 0);
        a.y = FF32(dirA, 4);
        a.z = FF32(dirA, 8);
        b.x = FF32(dirB, 0);
        b.y = FF32(dirB, 4);
        b.z = FF32(dirB, 8);
        kar_lbvector_cross_normalize(&b, &a, &cross);
        a.x *= 5.0f;
        a.y *= 5.0f;
        a.z *= 5.0f;
        x = FF32(center, 0);
        y = FF32(center, 4);
        z = FF32(center, 8);
        *(f32 *) 0xCC008000 = x;
        *(f32 *) 0xCC008000 = y;
        *(f32 *) 0xCC008000 = z;
        *(f32 *) 0xCC008000 = FU8(&lbl_805D5438, 0);
        *(f32 *) 0xCC008000 = FU8(&lbl_805D5438, 1);
        *(f32 *) 0xCC008000 = FU8(&lbl_805D5438, 2);
        *(f32 *) 0xCC008000 = FU8(&lbl_805D5438, 3);
        *(f32 *) 0xCC008000 = x + a.x;
        *(f32 *) 0xCC008000 = y + a.y;
        *(f32 *) 0xCC008000 = z + a.z;
        *(f32 *) 0xCC008000 = FU8(&lbl_805D5438, 0);
        *(f32 *) 0xCC008000 = FU8(&lbl_805D5438, 1);
        *(f32 *) 0xCC008000 = FU8(&lbl_805D5438, 2);
        *(f32 *) 0xCC008000 = FU8(&lbl_805D5438, 3);
        b.x *= 5.0f;
        b.y *= 5.0f;
        b.z *= 5.0f;
        *(f32 *) 0xCC008000 = x;
        *(f32 *) 0xCC008000 = y;
        *(f32 *) 0xCC008000 = z;
        *(f32 *) 0xCC008000 = FU8(&lbl_805D5434, 0);
        *(f32 *) 0xCC008000 = FU8(&lbl_805D5434, 1);
        *(f32 *) 0xCC008000 = FU8(&lbl_805D5434, 2);
        *(f32 *) 0xCC008000 = FU8(&lbl_805D5434, 3);
        *(f32 *) 0xCC008000 = x + b.x;
        *(f32 *) 0xCC008000 = y + b.y;
        *(f32 *) 0xCC008000 = z + b.z;
        *(f32 *) 0xCC008000 = FU8(&lbl_805D5434, 0);
        *(f32 *) 0xCC008000 = FU8(&lbl_805D5434, 1);
        *(f32 *) 0xCC008000 = FU8(&lbl_805D5434, 2);
        *(f32 *) 0xCC008000 = FU8(&lbl_805D5434, 3);
        cross.x *= 5.0f;
        cross.y *= 5.0f;
        cross.z *= 5.0f;
        *(f32 *) 0xCC008000 = x;
        *(f32 *) 0xCC008000 = y;
        *(f32 *) 0xCC008000 = z;
        *(f32 *) 0xCC008000 = FU8(&lbl_805D5430, 0);
        *(f32 *) 0xCC008000 = FU8(&lbl_805D5430, 1);
        *(f32 *) 0xCC008000 = FU8(&lbl_805D5430, 2);
        *(f32 *) 0xCC008000 = FU8(&lbl_805D5430, 3);
        *(f32 *) 0xCC008000 = x + cross.x;
        *(f32 *) 0xCC008000 = y + cross.y;
        *(f32 *) 0xCC008000 = z + cross.z;
        *(f32 *) 0xCC008000 = FU8(&lbl_805D5430, 0);
        *(f32 *) 0xCC008000 = FU8(&lbl_805D5430, 1);
        *(f32 *) 0xCC008000 = FU8(&lbl_805D5430, 2);
        *(f32 *) 0xCC008000 = FU8(&lbl_805D5430, 3);
    }
    return 0;
}

s32 fn_8007E40C(u32 kind, void *arg1, void *arg2) {
    f32 x, y, z;

    if (kind == 2U) {
        HSD_StateInvalidate(-1);
        HSD_StateInitDirect(GX_VTXFMT0, 2);
        GXLoadPosMtxImm((MtxPtr) ((u8 *) HSD_CObjGetCurrent() + 0x54), GX_PNMTX0);
        GXSetLineWidth(0xC, 5);
        GXBegin(GX_LINES, GX_VTXFMT0, 2);
        x = FF32(arg1, 0);
        y = FF32(arg1, 4);
        z = FF32(arg1, 8);
        *(f32 *) 0xCC008000 = x;
        *(f32 *) 0xCC008000 = y;
        *(f32 *) 0xCC008000 = z;
        *(f32 *) 0xCC008000 = FU8(&lbl_805D543C, 0);
        *(f32 *) 0xCC008000 = FU8(&lbl_805D543C, 1);
        *(f32 *) 0xCC008000 = FU8(&lbl_805D543C, 2);
        *(f32 *) 0xCC008000 = FU8(&lbl_805D543C, 3);
        *(f32 *) 0xCC008000 = x + FF32(arg2, 0);
        *(f32 *) 0xCC008000 = y + FF32(arg2, 4);
        *(f32 *) 0xCC008000 = z + FF32(arg2, 8);
        *(f32 *) 0xCC008000 = FU8(&lbl_805D543C, 0);
        *(f32 *) 0xCC008000 = FU8(&lbl_805D543C, 1);
        *(f32 *) 0xCC008000 = FU8(&lbl_805D543C, 2);
        *(f32 *) 0xCC008000 = FU8(&lbl_805D543C, 3);
    }
    return 0;
}

s32 fn_8007E500(u32 kind, void *arg1, void *arg2) {
    f32 x, y, z;

    if (kind == 2U) {
        HSD_StateInvalidate(-1);
        HSD_StateInitDirect(GX_VTXFMT0, 2);
        GXLoadPosMtxImm((MtxPtr) ((u8 *) HSD_CObjGetCurrent() + 0x54), GX_PNMTX0);
        GXSetLineWidth(0xC, 5);
        GXBegin(GX_LINES, GX_VTXFMT0, 2);
        FF32(arg2, 0) *= 5.0f;
        FF32(arg2, 4) *= 5.0f;
        FF32(arg2, 8) *= 5.0f;
        x = FF32(arg1, 0);
        y = FF32(arg1, 4);
        z = FF32(arg1, 8);
        *(f32 *) 0xCC008000 = x;
        *(f32 *) 0xCC008000 = y;
        *(f32 *) 0xCC008000 = z;
        *(f32 *) 0xCC008000 = FU8(&lbl_805D5440, 0);
        *(f32 *) 0xCC008000 = FU8(&lbl_805D5440, 1);
        *(f32 *) 0xCC008000 = FU8(&lbl_805D5440, 2);
        *(f32 *) 0xCC008000 = FU8(&lbl_805D5440, 3);
        *(f32 *) 0xCC008000 = x + FF32(arg2, 0);
        *(f32 *) 0xCC008000 = y + FF32(arg2, 4);
        *(f32 *) 0xCC008000 = z + FF32(arg2, 8);
        *(f32 *) 0xCC008000 = FU8(&lbl_805D5440, 0);
        *(f32 *) 0xCC008000 = FU8(&lbl_805D5440, 1);
        *(f32 *) 0xCC008000 = FU8(&lbl_805D5440, 2);
        *(f32 *) 0xCC008000 = FU8(&lbl_805D5440, 3);
    }
    return 0;
}

void kar_dbmapzone__8007e61c(void *arg0, void *arg1, void *color, s32 *arg3) {
    Mtx viewMtx;
    u8 blend;

    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_TEX_ST, GX_RGBA6, 0);
    GXSetVtxDesc(GX_VA_NRM, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_NRM, GX_TEX_S, GX_RGBA6, 0);
    HSD_CObjGetCurrent();
    HSD_CObjGetViewingMtx(HSD_CObjGetCurrent(), viewMtx);
    GXLoadPosMtxImm(viewMtx, GX_PNMTX0);
    kar_grcoll__803d1670(viewMtx, viewMtx);
    GXLoadNrmMtxImm(viewMtx, 0);
    GXSetCurrentMtx(GX_PNMTX0);
    blend = FU8(color, 3);
    GXSetColorUpdate(GX_ENABLE);
    GXSetAlphaUpdate(GX_DISABLE);
    GXSetBlendMode((blend == 0xFF) ? 2 : 0, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA,
                   GX_LO_NOOP);
    GXSetAlphaCompare(GX_GREATER, 0, GX_AOP_AND, GX_GREATER, 0);
    GXSetZMode(GX_ENABLE, GX_LEQUAL, blend == 0xFF);
    GXSetZCompLoc(GX_DISABLE);
    GXSetNumTexGens(0);
    kar_grcoll__803cf058(0, 0);
    GXSetNumTevStages(1);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);
    GXSetTevOp(GX_TEVSTAGE0, GX_PASSCLR);
    kar_grcoll__803cd3ac(4, color);
    kar_grcoll__803cd2b8(4, arg3);
    GXSetChanCtrl(GX_COLOR0A0, GX_ENABLE, GX_SRC_REG, GX_SRC_REG,
                  HSD_LObjGetLightMaskDiffuse(), GX_DF_CLAMP, GX_AF_NONE);
    GXSetNumChans(1);
    GXSetCullMode(GX_CULL_BACK);
    GXBegin(GX_QUADS, GX_VTXFMT0, 4);
    *(f32 *) 0xCC008000 = FF32(arg0, 0);
    *(f32 *) 0xCC008000 = FF32(arg0, 4);
    *(f32 *) 0xCC008000 = FF32(arg0, 8);
    *(f32 *) 0xCC008000 = FF32(arg1, 0);
    *(f32 *) 0xCC008000 = FF32(arg1, 4);
    *(f32 *) 0xCC008000 = FF32(arg1, 8);
    *(f32 *) 0xCC008000 = FF32(arg0, 0xC);
    *(f32 *) 0xCC008000 = FF32(arg0, 0x10);
    *(f32 *) 0xCC008000 = FF32(arg0, 0x14);
    *(f32 *) 0xCC008000 = FF32(arg1, 0);
    *(f32 *) 0xCC008000 = FF32(arg1, 4);
    *(f32 *) 0xCC008000 = FF32(arg1, 8);
    *(f32 *) 0xCC008000 = FF32(arg0, 0x18);
    *(f32 *) 0xCC008000 = FF32(arg0, 0x1C);
    *(f32 *) 0xCC008000 = FF32(arg0, 0x20);
    *(f32 *) 0xCC008000 = FF32(arg1, 0);
    *(f32 *) 0xCC008000 = FF32(arg1, 4);
    *(f32 *) 0xCC008000 = FF32(arg1, 8);
    *(f32 *) 0xCC008000 = FF32(arg0, 0x24);
    *(f32 *) 0xCC008000 = FF32(arg0, 0x28);
    *(f32 *) 0xCC008000 = FF32(arg0, 0x2C);
    *(f32 *) 0xCC008000 = FF32(arg1, 0);
    *(f32 *) 0xCC008000 = FF32(arg1, 4);
    *(f32 *) 0xCC008000 = FF32(arg1, 8);
}

void fn_8007E8CC(void) {
    void *w;

    fn_8007E93C();
    fn_8007E964();
    lbl_805DD64C.unk0 = 0xFF;
    lbl_805DD64C.unk1 &= ~0x80;
    lbl_805DD64C.unk2 = 1;
    w = *lbl_805DD648;
    FU8(w, 0x26) |= 0x40;
    w = *lbl_805DD648;
    FU8(w, 0x26) |= 0x80;
}

void fn_8007E93C(void) {
    lbl_805DD64C.unk0 = 0xFF;
    lbl_805DD64C.unk1 &= ~0x80;
    lbl_805DD64C.unk2 = 1;
}

void fn_8007E964(void) {
    s32 cur;
    void *w;

    lbl_805DD648 = HSD_Alloc(4);
    *lbl_805DD648 = kar_textlib__800ab2d4(0, 0x28, 0x14, 0x2B, 5, NULL);
    w = *lbl_805DD648;
    if (w != NULL) {
        FU8(w, 0x26) &= ~0x10;
        cur = FS32(lbl_8049B8E0, (lbl_805DD64C.unk1 >> 4) & 8);
        kar_textlib__near_800ab584(*lbl_805DD648, &cur, lbl_8049B8E0);
        kar_textlib__near_800ab55c(*lbl_805DD648,
                                    (u8 *) lbl_8049B8E0 + ((lbl_805DD64C.unk1 >> 4) & 8));
        kar_textlib__near_800ab534(*lbl_805DD648, 12.0f, 16.0f);
    }
}

void fn_8007EA40(s32 arg0, s32 arg1, s32 arg2) {
    void *w;
    void *base;
    void *gm;
    s32 i;
    s32 cur;
    void *entry;
    u8 flag;
    u32 tmp;

    if ((arg1 & 0x20) && (arg2 & 8)) {
        if (lbl_805DD64C.unk0 == arg0) {
            if ((lbl_805DD64C.unk1 >> 7) & 1) {
                lbl_805DD64C.unk0 = 0xFF;
                lbl_805DD64C.unk1 &= ~0x80;
                w = *lbl_805DD648;
                FU8(w, 0x26) |= 0x40;
                w = *lbl_805DD648;
                FU8(w, 0x26) |= 0x80;
                if (lbl_805DD64C.unk2 != 0) {
                    lbl_805DD64C.unk2 = 0;
                    kar_greventlighthouse_clear_ui_refresh_flag();
                } else {
                    lbl_805DD64C.unk2 = 1;
                    kar_greventlighthouse_set_ui_refresh_flag();
                }
            } else {
                flag = lbl_805DD64C.unk1 | 0x80;
                lbl_805DD64C.unk1 = flag;
                cur = FS32(lbl_8049B8E0, (flag >> 4) & 8);
                kar_textlib__near_800ab584(*lbl_805DD648, &cur, (void *) (u32) flag);
                kar_textlib__near_800ab55c(*lbl_805DD648,
                    (u8 *) lbl_8049B8E0 + ((lbl_805DD64C.unk1 >> 4) & 8));
            }
        } else {
            lbl_805DD64C.unk0 = (u8) arg0;
            w = *lbl_805DD648;
            FU8(w, 0x26) &= ~0x40;
            w = *lbl_805DD648;
            FU8(w, 0x26) &= ~0x80;
            cur = FS32(lbl_8049B8E0, (lbl_805DD64C.unk1 >> 4) & 8);
            kar_textlib__near_800ab584(*lbl_805DD648, &cur, lbl_8049B8E0);
            kar_textlib__near_800ab55c(*lbl_805DD648,
                (u8 *) lbl_8049B8E0 + ((lbl_805DD64C.unk1 >> 4) & 8));
        }
    }
    w = *lbl_805DD648;
    base = (u8 *) kar_gmmain__near_80006c14(lbl_805DD648) + 0x830;
    gm = kar_gmmain__near_80005cbc();
    kar_textlib__near_800ab5a4(w);
    kar_textlib__near_800ab4c0(w, 0, 0U);
    entry = base;
    for (i = 0; i < 4; i++) {
        if (kar_plclearcheckerlib__near_8022c858(i) != 4) {
            kar_textlib__near_800ab78c(w, &lbl_805D5448, i + 1);
            kar_textlib__near_800ab78c(w, &lbl_805D5450, FU8(entry, 0x60));
            tmp = FU8(base, 0x1D + i * 4);
            kar_textlib__near_800ab78c(w, (u8 *) &lbl_8049B8E0 + 0x10, tmp);
            kar_textlib__near_800ab78c(w, (u8 *) &lbl_8049B8E0 + 0x1C, FU8(entry, 0x21C));
            kar_textlib__near_800ab78c(w, (u8 *) &lbl_8049B8E0 + 0x28, FU8(entry, 0x230));
            kar_textlib__near_800ab78c(w, (u8 *) &lbl_8049B8E0 + 0x34, FU8(base, 0x18 + i * 4) + 1);
        } else {
            kar_textlib__near_800ab78c(w, &lbl_805D5458, i + 1);
        }
        if (i < 3) {
            kar_textlib__near_800ab78c(w, &lbl_805D5460, 0);
        }
        entry = (u8 *) entry + 4;
    }
    kar_textlib__near_800ab78c(w, &lbl_805D5460, 0);
    if ((kar_gmmain__near_80005d04(1) != 0 || kar_gmmain__near_80005d04(2) != 0) &&
        (FU32(gm, 8) & 0x20)) {
        kar_textlib__near_800ab78c(w, &lbl_805D5464, 0);
    }
}

void fn_8007ED34(void) {
    if (((lbl_80552DD8.unk8 >> 6) & 3) != 0) {
        return;
    }
    kar_textlib__near_800ab5a4(lbl_80552DD8.unk0);
    kar_textlib__near_800ab4c0(lbl_80552DD8.unk0, 0, 0U);
    kar_textlib__near_800ab78c(lbl_80552DD8.unk0, &lbl_805D546C, lbl_805DEDE8);
}

void fn_8007EDA8(s32 arg0) {
    s32 flags1;
    s32 flags2;
    u32 heldMask;
    u8 field;
    s32 v;

    flags1 = fn_8007D42C(arg0);
    flags2 = fn_8007D440(arg0);
    heldMask = fn_8007D458(arg0);
    if (fn_8007D4FC() != 0) {
        if (!((lbl_80552DD8.unk8 >> 5) & 1)) {
            fn_8007EF44();
        }
        if (flags1 & 0x40) {
            if (heldMask & 2) {
                field = (lbl_80552DD8.unk8 & ~0xC0) |
                        (((((lbl_80552DD8.unk8 >> 6) & 3) + 1) << 6) & 0xC0);
                lbl_80552DD8.unk8 = field;
                if (((field >> 6) & 3) >= 1) {
                    lbl_80552DD8.unk8 = field & ~0xC0;
                }
            }
            if (((lbl_80552DD8.unk8 >> 6) & 3) != 0) {
                return;
            }
            if (heldMask & 4) {
                v = lbl_80552DD8.unk4 + 1;
                lbl_80552DD8.unk4 = v;
                if (v >= 1) {
                    lbl_80552DD8.unk4 = -1;
                }
            } else if (heldMask & 8) {
                v = lbl_80552DD8.unk4 - 1;
                lbl_80552DD8.unk4 = v;
                if (v < -1) {
                    lbl_80552DD8.unk4 = 0;
                }
            }
            if (flags2 & 0x100) {
                fn_80009BEC();
            }
        }
    } else if ((lbl_80552DD8.unk8 >> 5) & 1) {
        fn_8007EF00();
    }
}

void fn_8007FC50(void) {
}

void fn_8007FC54(void) {
    if (lbl_80552DE8[0] != NULL) {
        FU8(lbl_80552DE8[0], 0x26) |= 0x40;
        FU8(lbl_80552DE8[0], 0x26) |= 0x80;
        FU8((u8 *) lbl_80552DE8 + 0x18, 0) &= ~0x10;
    }
}

void fn_8007FC98(void) {
    if (lbl_80552DE8[0] != NULL) {
        FU8(lbl_80552DE8[0], 0x26) &= ~0x40;
        FU8(lbl_80552DE8[0], 0x26) &= ~0x80;
        FU8((u8 *) lbl_80552DE8 + 0x18, 0) |= 0x10;
    }
}

void fn_8007FCDC(void) {
    void *w;

    lbl_80552DE8[1] = (void *) -1;
    FU8((u8 *) lbl_80552DE8 + 0x18, 0) &= ~0xE0;
    lbl_80552DE8[2] = (void *) 9;
    lbl_80552DE8[3] = NULL;
    lbl_80552DE8[5] = NULL;
    w = kar_textlib__800ab2d4(0, 0, 0x14, 0x33, 0xB, fn_8007F58C);
    lbl_80552DE8[0] = w;
    if (w != NULL) {
        FU8(w, 0x26) &= ~0x10;
        kar_textlib__near_800ab584(w, &lbl_805DEE00, lbl_805DEE04, lbl_805DEE00);
        kar_textlib__near_800ab55c(w, &lbl_805DEE04);
        kar_textlib__near_800ab534(w, 12.0f, 16.0f);
        if (lbl_80552DE8[0] != NULL) {
            FU8(lbl_80552DE8[0], 0x26) |= 0x40;
            FU8(lbl_80552DE8[0], 0x26) |= 0x80;
            FU8((u8 *) lbl_80552DE8 + 0x18, 0) &= ~0x10;
        }
    }
}

void fn_8007FE04(void *arg0) {
    void *kart;

    kart = FP(arg0, 0x2C);
    if (fn_80191C84() != 0) {
        kar_dbscreenshot__near_8008c718(FU8(kart, 9));
        return;
    }
    kar_dbscreenshot__near_8008c63c(FU8(kart, 9));
}

void fn_8007FE4C(void *arg0) {
    u16 flags;
    void *kart;

    kart = FP(arg0, 0x2C);
    FU8(kart, 0xA98) += 1;
    if (FU8(kart, 0xA98) >= 6) {
        FU8(kart, 0xA98) = 0;
    }
    FU16(kart, 0xA9C) &= ~0x29;
    flags = FU16(kart, 0xA9C);
    FU16(kart, 0xA9C) = flags | lbl_805D5478[FU8(kart, 0xA98)];
    if (fn_80192764(arg0, lbl_805D5478, flags) != 0) {
        fn_80080804(FP(kart, 0x3F4), FU8(kart, 0xA98));
    }
    fn_80083D20(arg0, (u8) FU16(kart, 0xA9C));
}

void fn_8007FEF4(void *arg0) {
    u16 flags;
    void *kart;

    kart = FP(arg0, 0x2C);
    FU8(kart, 0xA9A) += 1;
    if (FU8(kart, 0xA9A) >= 0xE) {
        FU8(kart, 0xA9A) = 0;
    }
    FU16(kart, 0xA9C) &= ~0x1D6;
    flags = FU16(kart, 0xA9C);
    FU16(kart, 0xA9C) = flags | lbl_8049B9D0[FU8(kart, 0xA9A)];
    if (fn_80192764(arg0, lbl_8049B9D0, flags) != 0) {
        fn_80080858(FP(kart, 0x3F4), FU8(kart, 0xA9A));
    } else {
        kar_mpcoll_refresh_forward_debug_volume_enabled(kart);
    }
    fn_80083D20(arg0, (u8) FU16(kart, 0xA9C));
}

void fn_8007FFB0(void *arg0, u32 arg1) {
    void *kart;

    kart = FP(arg0, 0x2C);
    fn_8007E1A0(arg1, (u8 *) kart + 0x300, (u8 *) kart + 0x324, (u8 *) kart + 0x330);
}

void fn_8007FFE4(void *arg0, u32 arg1) {
    f32 v[3];
    void *kart;

    kart = FP(arg0, 0x2C);
    v[0] = FF32(kart, 0x2DC) * 3.0f;
    v[1] = FF32(kart, 0x2E0) * 3.0f;
    v[2] = FF32(kart, 0x2E4) * 3.0f;
    fn_8007E40C(arg1, (u8 *) kart + 0x300, v);
}

void fn_8008003C(void *arg0, u32 arg1) {
    void *kart;

    kart = FP(arg0, 0x2C);
    fn_8007E1A0(arg1, (u8 *) kart + 0x318, (u8 *) kart + 0x978, (u8 *) kart + 0x984);
}

void fn_80080070(void *arg0, u32 arg1) {
    f32 v[3];
    f32 mag;
    void *kart;

    kart = FP(arg0, 0x2C);
    mag = PSVECMag((Vec *) ((u8 *) kart + 0xA6C));
    if (mag != 0.0f) {
        f32 inv = 1.0f / mag;
        v[0] = FF32(kart, 0xA6C) * inv;
        v[1] = FF32(kart, 0xA70) * inv;
        v[2] = FF32(kart, 0xA74) * inv;
    } else {
        v[0] = v[1] = v[2] = 0.0f;
    }
    fn_8007E500(arg1, (u8 *) kart + 0x300, v);
}

void fn_80080104(void *arg0, void *arg1, void *win, void *labels) {
    f32 v[9];
    s32 mode;
    s32 idx;
    void *table;
    void *label;
    s32 val;
    s32 i;

    kar_textlib__near_800ab78c(win, &lbl_805D5480, 0);
    mode = ((s32) (FU8(&lbl_805DD650, 5) << 0x19) & 0xF8000000) >> 0x1C;
    switch (mode) {
    case 0:
        kar_textlib__near_800ab50c(win, FP(FP(labels, 4), 0));
        kar_textlib__near_800ab78c(win, &lbl_805D5484, FU8(arg0, 8));
        idx = FS32(arg0, 0x1C);
        val = 0;
        kar_textlib__near_800ab50c(win, FP(FP(labels, 4), 8));
        kar_textlib__near_800ab78c(win, &lbl_805D5488, val);
        v[0] = FF32(arg0, 0x2DC);
        v[1] = FF32(arg0, 0x2E0);
        v[2] = FF32(arg0, 0x2E4);
        v[1] = 0.0f;
        kar_textlib__near_800ab50c(win, FP(FP(labels, 4), 0x20));
        kar_textlib__near_800ab78c(win, &lbl_805D548C, PSVECMag((Vec *) v) / 0.0405f);
        if (fn_80192764(arg1, NULL, 0) == 0) {
            kar_textlib__near_800ab50c(win, FP(FP(labels, 4), 0x28));
            label = &lbl_805D5498;
            if ((FU8(arg0, 0xA40) >> 5) & 1) {
                label = &lbl_805D5494;
            }
            kar_textlib__near_800ab78c(win, " %s%s%s%s", label, &lbl_805D5498,
                                        &lbl_805D5498, &lbl_805D5498);
        }
        return;
    case 1:
        kar_textlib__near_800ab50c(win, FP(FP(labels, 4), 0));
        kar_textlib__near_800ab78c(win, &lbl_805D5484, FU8(arg0, 8));
        kar_textlib__near_800ab50c(win, FP(FP(labels, 4), 8));
        kar_textlib__near_800ab78c(win, &lbl_805D5484, FU8(arg0, 0x84));
        kar_textlib__near_800ab50c(win, FP(FP(labels, 4), 0x10));
        kar_textlib__near_800ab78c(win, &lbl_805D5484, FU8(arg0, 0x105));
        kar_textlib__near_800ab50c(win, FP(FP(labels, 4), 0x18));
        kar_textlib__near_800ab78c(win, &lbl_805D5484, FU8(arg0, 0x130));
        kar_textlib__near_800ab50c(win, FP(FP(labels, 4), 0x20));
        kar_textlib__near_800ab78c(win, &lbl_805D5484, FU8(arg0, 0x1B1));
        return;
    case 4:
        kar_textlib__near_800ab50c(win, FP(FP(labels, 4), 0));
        kar_textlib__near_800ab78c(win, &lbl_805D5484, FU8(arg0, 8));
        table = FP(arg0, 0x3F4);
        if (table != NULL) {
            fn_801C81C0(v);
            fn_801C8290(table, v);
        } else {
            fn_8019259C(arg1, v);
            for (i = 1; i < 9; i++) {
                v[i] = 0.0f;
            }
        }
        for (i = 0; i < 9; i++) {
            kar_textlib__near_800ab50c(win, FP(FP(labels, 4), 8 + i * 8));
            kar_textlib__near_800ab78c(win, &lbl_805D54A8, v[i]);
        }
        break;
    }
}

void fn_80080514(void *win) {
    void *category;
    void *entry;
    s32 count;
    s32 i;
    void *node;

    kar_textlib__near_800ab5a4(NULL);
    kar_textlib__near_800ab4c0(win, 0, 0U);
    category = ((void **) (u32) fn_8007D55C())[(FU8(&lbl_805DD650, 5) << 0x19 & (s32) 0xF8000000) >> 0x1C];
    count = FS32(category, 0);
    entry = FP(category, 4);
    for (i = 0; i < count; i++) {
        kar_textlib__near_800ab50c(win, FP(entry, 0));
        kar_textlib__near_800ab78c(win, &lbl_805D5488, FU8(entry, 4));
        entry = (u8 *) entry + 8;
    }
    node = FP(hsdGObj_p_link_heads, 0x28);
    while (node != NULL) {
        fn_80080104(FP(node, 0x2C), node, win, category);
        node = FP(node, 8);
    }
    node = FP(hsdGObj_p_link_heads, 0x80);
    while (node != NULL) {
        if (FU16(node, 0) == 0x11 && (FU8(FP(node, 0x2C), 0x824) >> 4 & 1)) {
            fn_80080104(node, win, category, NULL);
        }
        node = FP(node, 8);
    }
}

void fn_8008062C(s32 arg0) {
    u8 field;
    s8 mode;

    if ((fn_8007D42C(arg0) & 0x20) && (fn_8007D440(arg0) & 1)) {
        field = (FU8(&lbl_805DD650, 5) & ~0x78) |
                (((((FU8(&lbl_805DD650, 5) << 0x19 & (s32) 0xF8000000) >> 0x1C) + 1) << 3) & 0x78);
        FU8(&lbl_805DD650, 5) = field;
        mode = (s8) (field << 0x19 & (s32) 0xF8000000) >> 0x1C;
        if (mode >= 5) {
            FU8(&lbl_805DD650, 5) = field | 0x78;
        }
        mode = (s8) (FU8(&lbl_805DD650, 5) << 0x19 & (s32) 0xF8000000) >> 0x1C;
        if (mode == -1) {
            FU8(lbl_805DD650.unk0, 0x26) |= 0x40;
            FU8(lbl_805DD650.unk0, 0x26) |= 0x80;
        } else {
            FU8(lbl_805DD650.unk0, 0x26) &= ~0x40;
            FU8(lbl_805DD650.unk0, 0x26) &= ~0x80;
        }
        fn_80080FEC();
    }
}

void fn_80080710(void) {
}

void fn_80080714(void) {
    void *w;

    FU8(&lbl_805DD650, 5) |= 0x78;
    w = kar_textlib__800ab2d4(0, 0x14, 0x28, 0x46, 6, fn_80080514);
    lbl_805DD650.unk0 = w;
    if (w != NULL) {
        FU8(w, 0x26) &= ~0x10;
        kar_textlib__near_800ab584(w, &lbl_805E62E0, lbl_805DEE20, lbl_805E62E0);
        kar_textlib__near_800ab55c(w, &lbl_805DEE20);
        kar_textlib__near_800ab534(w, 9.0f, 12.0f);
        FU8(lbl_805DD650.unk0, 0x26) |= 0x40;
        FU8(lbl_805DD650.unk0, 0x26) |= 0x80;
    }
}

void fn_800807E0(void *arg0) {
    fn_801AE4EC(FP(arg0, 0x2C));
}

void fn_80080804(void *arg0, s32 arg1) {
    u16 old;
    u16 cur;
    void *kart;

    kart = FP(arg0, 0x2C);
    old = FU16(kart, 0x1BBC);
    FU16(kart, 0x1BBC) &= ~0x29;
    cur = FU16(kart, 0x1BBC);
    FU16(kart, 0x1BBC) = cur | FU8(&lbl_805D54B0, arg1);
    fn_80083D20((void *) (u32) FU16(kart, 0x1BBC), (u8) cur);
}

void fn_80080858(void *arg0, s32 arg1) {
    u16 old;
    u16 cur;
    void *kart;

    kart = FP(arg0, 0x2C);
    old = FU16(kart, 0x1BBC);
    FU16(kart, 0x1BBC) &= ~0x1D6;
    cur = FU16(kart, 0x1BBC);
    FU16(kart, 0x1BBC) = cur | lbl_8049B9F0[(u8) arg1];
    kar_mpcoll__near_801d1048(kart, lbl_8049B9F0, cur, old);
    fn_80083D20(arg0, (u8) FU16(kart, 0x1BBC));
}

void fn_800808D0(void *arg0, u32 arg1) {
    void *kart;

    kart = FP(arg0, 0x2C);
    fn_8007E1A0(arg1, (u8 *) kart + 0x3E8, (u8 *) kart + 0x418, (u8 *) kart + 0x424);
}

void fn_80080904(void *arg0, u32 arg1) {
    void *kart;

    kart = FP(arg0, 0x2C);
    fn_8007E40C(arg1, (u8 *) kart + 0x3E8, (u8 *) kart + 0x324);
}

void fn_80080934(void *win) {
    void *category;
    void *entry;
    void *node;
    void *kart;
    s32 count;
    s32 i;
    s32 mode;

    kar_textlib__near_800ab5a4(NULL);
    kar_textlib__near_800ab4c0(win, 0, 0U);
    category = ((void **) (u32) fn_8007D5B0())[(FU8(&lbl_805DD658, 5) << 0x19 & (s32) 0xF8000000) >> 0x1C];
    count = FS32(category, 0);
    entry = FP(category, 4);
    for (i = 0; i < count; i++) {
        kar_textlib__near_800ab50c(win, FP(entry, 0));
        kar_textlib__near_800ab78c(win, &lbl_805D54B8, FU8(entry, 4));
        entry = (u8 *) entry + 8;
    }
    node = FP(hsdGObj_p_link_heads, 0x24);
    while (node != NULL) {
        kart = FP(node, 0x2C);
        kar_textlib__near_800ab78c(win, &lbl_805D54BC, 0);
        mode = (FU8(&lbl_805DD658, 5) << 0x19 & (s32) 0xF8000000) >> 0x1C;
        switch (mode) {
        case 0:
            kar_textlib__near_800ab50c(win, FP(FP(category, 4), 0));
            kar_textlib__near_800ab78c(win, &lbl_805D54C0, fn_801C7CF4((f32 *) kart));
            break;
        case 1:
            kar_textlib__near_800ab50c(win, FP(FP(category, 4), 0));
            kar_textlib__near_800ab78c(win, &lbl_805D54C0, fn_801C7CF4((f32 *) kart));
            break;
        case 2:
            kar_textlib__near_800ab50c(win, FP(FP(category, 4), 0));
            kar_textlib__near_800ab78c(win, &lbl_805D54C0, fn_801C7CF4((f32 *) kart));
            break;
        case 3:
            kar_textlib__near_800ab50c(win, FP(FP(category, 4), 0));
            kar_textlib__near_800ab78c(win, &lbl_805D54C0, fn_801C7CF4((f32 *) kart));
            break;
        case 4:
            kar_textlib__near_800ab50c(win, FP(FP(category, 4), 0));
            kar_textlib__near_800ab78c(win, &lbl_805D54C0, fn_801C7CF4((f32 *) kart));
            break;
        }
        node = FP(node, 8);
    }
}

void fn_8007EF00(void) {
    if (lbl_80552DD8.unk0 != NULL) {
        FU8(lbl_80552DD8.unk0, 0x26) |= 0x40;
        FU8(lbl_80552DD8.unk0, 0x26) |= 0x80;
        lbl_80552DD8.unk8 &= ~0x20;
    }
}

void fn_8007EF44(void) {
    if (lbl_80552DD8.unk0 != NULL) {
        FU8(lbl_80552DD8.unk0, 0x26) &= ~0x40;
        FU8(lbl_80552DD8.unk0, 0x26) &= ~0x80;
        lbl_80552DD8.unk8 |= 0x20;
    }
}

void fn_8007EF88(void) {
    void *w;

    lbl_80552DD8.unk4 = -1;
    lbl_80552DD8.unk8 &= ~0xC0;
    w = kar_textlib__800ab2d4(0, 0, 0x14, 0x14, 1, fn_8007ED34);
    lbl_80552DD8.unk0 = w;
    if (w != NULL) {
        FU8(w, 0x26) &= ~0x10;
        kar_textlib__near_800ab584(w, &lbl_805DEDEC, lbl_805DEDF0, lbl_805DEDEC);
        kar_textlib__near_800ab55c(w, &lbl_805DEDF0);
        kar_textlib__near_800ab534(w, 12.0f, 16.0f);
        if (lbl_80552DD8.unk0 != NULL) {
            FU8(lbl_80552DD8.unk0, 0x26) |= 0x40;
            FU8(lbl_80552DD8.unk0, 0x26) |= 0x80;
            lbl_80552DD8.unk8 &= ~0x20;
        }
    }
}

void fn_8007F0A0(void) {
    void *gm;
    s32 *ptr;
    s32 i;
    s32 j;
    s32 col;
    s32 row;
    s32 val;

    gm = kar_gmglobal__near_8000771c();
    kar_gmmain__near_80006c14(NULL);
    ptr = fn_8007D5A4();
    for (i = 0; i < 9; i++) {
        kar_textlib__near_800ab4c0(*lbl_80552DE8, 0, i);
        kar_textlib__near_800ab78c(*lbl_80552DE8, &lbl_805D5470, ptr[i]);
    }
    row = 4;
    for (i = 1; i < 9; i++) {
        col = 0xB;
        for (j = 0; j < 4; j++) {
            val = 0;
            if ((kar_plclearcheckerlib__near_8022c858(j) == 0 ||
                 (kar_plclearcheckerlib__near_8022c858(j) == 1 && fn_8000A97C() != 0)) &&
                i <= 8) {
                val = kar_plclearchecker_get_state_u32_7d4(j);
            }
            kar_textlib__near_800ab4c0(*lbl_80552DE8, col, i);
            kar_textlib__near_800ab78c(*lbl_80552DE8, &lbl_805D5474, val);
            col += 7;
        }
        val = 0;
        if (i <= 8) {
            val = FS32(gm, 0xF4 + row);
        }
        kar_textlib__near_800ab4c0(*lbl_80552DE8, (4 * 7) + 0xB, i);
        kar_textlib__near_800ab78c(*lbl_80552DE8, &lbl_805D5474, val);
        row += 4;
    }
}

void fn_8007F2E8(void) {
    void *gm;
    s32 *ptr;
    s32 i;
    s32 j;
    s32 col;
    s32 row;
    s32 val;

    gm = kar_gmglobal__near_8000774c();
    kar_gmmain__near_80006c14(NULL);
    ptr = fn_8007D598();
    for (i = 0; i < 0xB; i++) {
        kar_textlib__near_800ab4c0(*lbl_80552DE8, 0, i);
        kar_textlib__near_800ab78c(*lbl_80552DE8, &lbl_805D5470, ptr[i]);
    }
    row = 4;
    for (i = 1; i < 0xB; i++) {
        col = 0xB;
        for (j = 0; j < 4; j++) {
            val = 0;
            if ((kar_plclearcheckerlib__near_8022c858(j) == 0 ||
                 (kar_plclearcheckerlib__near_8022c858(j) == 1 && fn_8000A97C() != 0)) &&
                i <= 0xA) {
                val = kar_plclearcheckerlib__80231510(j);
            }
            kar_textlib__near_800ab4c0(*lbl_80552DE8, col, i);
            kar_textlib__near_800ab78c(*lbl_80552DE8, &lbl_805D5474, val);
            col += 7;
        }
        val = 0;
        if (i <= 0xA) {
            val = FS32(gm, 0xFA + row);
        }
        kar_textlib__near_800ab4c0(*lbl_80552DE8, (4 * 7) + 0xB, i);
        kar_textlib__near_800ab78c(*lbl_80552DE8, &lbl_805D5474, val);
        row += 4;
    }
}

void fn_8007F58C(void) {
    s32 sel;
    u8 mode;

    kar_textlib__near_800ab5a4(*lbl_80552DE8);
    kar_textlib__near_800ab4c0(*lbl_80552DE8, 0, 0U);
    sel = (FU8((u8 *) lbl_80552DE8 + 0x18, 0) >> 5) & 7;
    switch (sel) {
    case 0:
        kar_textlib__near_800ab78c(*lbl_80552DE8, &lbl_805D5470,
            FU8((u8 *) fn_8007D538() + (s32) lbl_80552DE8[1] * 4, 4));
        return;
    case 1:
        kar_textlib__near_800ab78c(*lbl_80552DE8, &lbl_805D5470,
            FU8(fn_8007D544(), (s32) lbl_80552DE8[2] * 4));
        return;
    case 2:
        kar_textlib__near_800ab78c(*lbl_80552DE8, &lbl_805D5470,
            FU8(fn_8007D550(), (s32) lbl_80552DE8[3] * 4));
        return;
    case 3:
        kar_textlib__near_800ab78c(*lbl_80552DE8, &lbl_805D5470,
            FU8(fn_8007D580(), (s32) lbl_80552DE8[4] * 4));
        return;
    case 4:
        kar_textlib__near_800ab78c(*lbl_80552DE8, &lbl_805D5470,
            FU8(fn_8007D58C(), (s32) lbl_80552DE8[5] * 4));
        return;
    case 5:
        mode = kar_gmracenormal__8000aea8();
        if (mode == 4) {
            fn_8007F0A0();
        } else if (mode == 6) {
            fn_8007F2E8();
        }
        return;
    }
}

void fn_8007F72C(s32 arg0) {
    s32 flags1;
    s32 flags2;
    u32 heldMask;
    void *slot;
    void *replay;
    s32 mode;
    s32 v;

    flags1 = fn_8007D42C(arg0);
    flags2 = fn_8007D440(arg0);
    heldMask = fn_8007D458(arg0);
    if ((flags1 & 0x400) && (flags2 & 8) &&
        kar_plclearchecker_get_player_index_for_slot(arg0) != (void *) 5) {
        replay = kar_cmreplay__8022cb74(NULL);
        fn_8007FE04(replay);
    }
    if ((flags1 & 0x400) && (flags2 & 2)) {
        slot = NULL;
        do {
            replay = kar_cmreplay__8022cb74(slot);
            if (replay != NULL) {
                fn_8007FE4C(replay);
            }
            slot = (u8 *) slot + 1;
        } while (slot < (void *) 5);
    }
    if ((flags1 & 0x400) && (flags2 & 1) &&
        kar_plclearchecker_get_player_index_for_slot(arg0) != (void *) 5) {
        replay = kar_cmreplay__8022cb74(NULL);
        fn_8007FEF4(replay);
    }
    if (fn_8007D470() != 0) {
        if (!((FU8((u8 *) lbl_80552DE8 + 0x18, 0) >> 4) & 1)) {
            fn_8007FC98();
        }
        if (flags1 & 0x40) {
            mode = (FU8((u8 *) lbl_80552DE8 + 0x18, 0) >> 5) & 7;
            if (heldMask & 2) {
                mode += 1;
                if (mode > 5) {
                    mode = 0;
                }
            } else if (heldMask & 1) {
                mode -= 1;
                if (mode < 0) {
                    mode = 5;
                }
            }
            FU8((u8 *) lbl_80552DE8 + 0x18, 0) =
                (FU8((u8 *) lbl_80552DE8 + 0x18, 0) & ~0xE0) | ((mode << 5) & 0xE0);
            switch (mode) {
            case 0:
                v = FS32(lbl_80552DE8, 4);
                if (heldMask & 4) {
                    v += 1;
                    if (v > 0xB) {
                        v = -1;
                    }
                } else if (heldMask & 8) {
                    v -= 1;
                    if (v < -1) {
                        v = 0xB;
                    }
                }
                FS32(lbl_80552DE8, 4) = v;
                if (flags2 & 0x100) {
                    slot = kar_plclearchecker_get_player_index_for_slot(arg0);
                    if (slot != (void *) 5 && kar_plclearchecker_get_player_object() != NULL) {
                        replay = kar_cmreplay__8022cb74(slot);
                        if (fn_8019262C() != 0) {
                            if (FS32(lbl_80552DE8, 4) != 0xB) {
                                fn_80192650(replay);
                                return;
                            }
                            fn_800807E0(replay);
                            return;
                        }
                    }
                }
                break;
            case 1:
                v = FS32(lbl_80552DE8, 8);
                if (heldMask & 4) {
                    v += 1;
                    if (v > 9) {
                        v = 0;
                    }
                } else if (heldMask & 8) {
                    v -= 1;
                    if (v < 0) {
                        v = 9;
                    }
                }
                FS32(lbl_80552DE8, 8) = v;
                if (heldMask & 0x300) {
                    slot = kar_plclearchecker_get_player_index_for_slot(arg0);
                    if (slot != (void *) 5) {
                        s32 dir = (heldMask & 0x100) ? 1 : -1;
                        if (FS32(lbl_80552DE8, 8) == 9) {
                            s32 k;
                            for (k = 0; k <= 8; k++) {
                                kar_cmreplay__8022cb74(slot);
                                fn_80192528(k, dir);
                            }
                            return;
                        }
                        kar_cmreplay__8022cb74(slot);
                        fn_80192528(FS32(lbl_80552DE8, 8), dir);
                        return;
                    }
                }
                break;
            case 2:
                v = FS32(lbl_80552DE8, 0xC);
                if (heldMask & 4) {
                    v += 1;
                    if (v > 3) {
                        v = 0;
                    }
                } else if (heldMask & 8) {
                    v -= 1;
                    if (v < 0) {
                        v = 3;
                    }
                }
                FS32(lbl_80552DE8, 0xC) = v;
                if (flags2 & 0x100) {
                    slot = kar_plclearchecker_get_player_index_for_slot(arg0);
                    if (slot != (void *) 5 && kar_plclearchecker_get_player_object() != NULL) {
                        replay = kar_cmreplay__8022cb74(slot);
                        if (fn_80192688() != 0) {
                            fn_801926AC(replay, FS32(lbl_80552DE8, 0xC));
                            return;
                        }
                    }
                }
                break;
            case 3:
                v = FS32(lbl_80552DE8, 0x10);
                if (heldMask & 4) {
                    v += 1;
                    if (v > 0x19) {
                        v = 0;
                    }
                } else if (heldMask & 8) {
                    v -= 1;
                    if (v < 0) {
                        v = 0x19;
                    }
                }
                FS32(lbl_80552DE8, 0x10) = v;
                if ((flags2 & 0x100) &&
                    kar_plclearchecker_get_player_index_for_slot(arg0) != (void *) 5) {
                    fn_8008115C(FS32(lbl_80552DE8, 0x10), arg0);
                    return;
                }
                break;
            case 4:
                v = FS32(lbl_80552DE8, 0x14);
                if (heldMask & 4) {
                    v += 1;
                    if (v > 1) {
                        v = 0;
                    }
                } else if (heldMask & 8) {
                    v -= 1;
                    if (v < 0) {
                        v = 1;
                    }
                }
                FS32(lbl_80552DE8, 0x14) = v;
                if (flags2 & 0x100) {
                    void *idx = kar_plclearchecker_get_player_index_for_slot(arg0);
                    void *obj = kar_plclearchecker_get_player_object();
                    if (obj != NULL) {
                        replay = kar_cmreplay__8022cb74(idx);
                        if (kar_diag__8000acb0() != 0 && fn_80192950(replay) == 0) {
                            fn_80081208(obj, FS32(lbl_80552DE8, 0x14), idx);
                            return;
                        }
                    }
                }
                break;
            }
        }
    } else if ((FU8((u8 *) lbl_80552DE8 + 0x18, 0) >> 4) & 1) {
        fn_8007FC54();
    }
}

void fn_80080FEC(void) {
    u8 field;
    s8 mode;

    field = (FU8(&lbl_805DD658, 5) & ~0x78) |
            (((((FU8(&lbl_805DD658, 5) << 0x19 & (s32) 0xF8000000) >> 0x1C) + 1) << 3) & 0x78);
    FU8(&lbl_805DD658, 5) = field;
    mode = (s8) (field << 0x19 & (s32) 0xF8000000) >> 0x1C;
    if (mode >= 5) {
        FU8(&lbl_805DD658, 5) = field | 0x78;
    }
    mode = (s8) (FU8(&lbl_805DD658, 5) << 0x19 & (s32) 0xF8000000) >> 0x1C;
    if (mode == -1) {
        FU8(lbl_805DD658.unk0, 0x26) |= 0x40;
        FU8(lbl_805DD658.unk0, 0x26) |= 0x80;
        return;
    }
    FU8(lbl_805DD658.unk0, 0x26) &= ~0x40;
    FU8(lbl_805DD658.unk0, 0x26) &= ~0x80;
}

void fn_8008108C(void) {
}

void fn_80081090(void) {
    void *w;

    FU8(&lbl_805DD658, 5) |= 0x78;
    w = kar_textlib__800ab2d4(0, 0x14, 0x8C, 0x46, 0x18, fn_80080934);
    lbl_805DD658.unk0 = w;
    if (w != NULL) {
        FU8(w, 0x26) &= ~0x10;
        kar_textlib__near_800ab584(w, &lbl_805E62E8, lbl_805DEE40, lbl_805E62E8);
        kar_textlib__near_800ab55c(w, &lbl_805DEE40);
        kar_textlib__near_800ab534(w, 9.0f, 12.0f);
        FU8(lbl_805DD658.unk0, 0x26) |= 0x40;
        FU8(lbl_805DD658.unk0, 0x26) |= 0x80;
    }
}

void fn_8008115C(s32 arg0, s32 arg1) {
    u8 vec[4];
    f32 tpl[2];
    f32 v;

    kar_plclearchecker_get_template_vecs_014_020(tpl, &v);
    kar_plclearchecker_get_template_vec_008(arg0, vec);
    kar_vcgenerator__801dffdc(arg1, vec, tpl, &v, -1, -1, 0, 1.0f);
}

void fn_800811CC(s32 arg0) {
    memcpy((void *) (u32) arg0, (void *) (u32) fn_8007D580(), 0x68);
}

void fn_80081208(void *arg0, s32 arg1, void *arg2) {
    fn_801DB278(FP(arg0, 0x2C));
}

void fn_8008122C(void) {
    void *w;

    FU8(lbl_80552E08[0], 0x33) = 0;
    FU8(lbl_80552E08[0], 0) &= ~0x80;
    lbl_80552E08[2] = (void *) -1;
    lbl_80552E08[1] = NULL;
    FU8(lbl_80552E08[0], 0x30) = 0;
    FU8(lbl_80552E08[0], 0x31) = 0;
    FU8(lbl_80552E08[0], 0x32) = 0;
    FU8(lbl_80552E08[0], 0x33) = 1;
    lbl_80552E08[9] = NULL;
    lbl_80552E08[0xA] = NULL;
    lbl_80552E08[3] = NULL;
    memset(&lbl_80552E08[4], 0, 0x14);
    lbl_80552E08[0xB] = NULL;
    w = kar_textlib__800ab2d4(0, 0, 0x14, 0x14, 1, NULL);
    lbl_80552E08[0xB] = w;
    if (w != NULL) {
        FU8(w, 0x26) &= ~0x10;
        kar_textlib__near_800ab584(w, &lbl_805D54F0);
        kar_textlib__near_800ab55c(w, &lbl_805D54F4);
        kar_textlib__near_800ab534(w, 12.0f, 16.0f);
        FU8(lbl_80552E08[0xB], 0x26) |= 0x40;
        FU8(lbl_80552E08[0xB], 0x26) |= 0x80;
    }
}

void fn_8008134C(void) {
    void *win;
    void *table;
    s32 len;
    s32 pad;

    win = lbl_80552E08[0xB];
    if (win != NULL &&
        ((s32) lbl_80552E08[1] != (s32) lbl_80552E08[2] || (s32) lbl_80552E08[9] != 0)) {
        table = (void *) (u32) fn_8007D5EC();
        kar_textlib__near_800ab5a4(win);
        kar_textlib__near_800ab4c0(win, 0, 0U);
        switch ((s32) (u32) lbl_80552E08[3]) {
        case 0:
            if ((s32) lbl_80552E08[9] == 2) {
                kar_textlib__near_800ab78c(win, &lbl_8049BA18);
            } else {
                void *name = FP(table, (s32) lbl_80552E08[1] * 4);
                len = strlen((s32) (u32) name);
                pad = 0x11 - len;
                kar_textlib__near_800ab78c(win, &lbl_805D54F8, name);
                if (pad > 0) {
                    kar_textlib__near_800ab4c0(win, len + pad, 0U);
                    switch ((s32) (u32) lbl_80552E08[0xA]) {
                    case 0: kar_textlib__near_800ab78c(win, &lbl_805D54FC); break;
                    case 1: kar_textlib__near_800ab78c(win, &lbl_805D5500); break;
                    case 2: kar_textlib__near_800ab78c(win, &lbl_805D5504); break;
                    case 3: kar_textlib__near_800ab78c(win, &lbl_805D5508); break;
                    case 4: kar_textlib__near_800ab78c(win, &lbl_805D550C); break;
                    case 5: kar_textlib__near_800ab78c(win, &lbl_805D5510); break;
                    }
                }
                lbl_80552E08[9] = NULL;
            }
            break;
        case 1:
            kar_textlib__near_800ab78c(win, (u8 *) &lbl_8049BA18 + 0x10);
            goto shared;
        case 2:
            kar_textlib__near_800ab78c(win, (u8 *) &lbl_8049BA18 + 0x1C);
            goto shared;
        case 3:
            kar_textlib__near_800ab78c(win, (u8 *) &lbl_8049BA18 + 0x2C);
            goto shared;
        case 4:
            kar_textlib__near_800ab78c(win, (u8 *) &lbl_8049BA18 + 0x38);
shared:
            if (FS32(&lbl_80552E08[(s32) (u32) lbl_80552E08[3]], 0xC) != 0) {
                kar_textlib__near_800ab4c0(win, 0x11, 0U);
                kar_textlib__near_800ab78c(win, &lbl_805D5514);
            } else {
                kar_textlib__near_800ab4c0(win, 0x10, 0U);
                kar_textlib__near_800ab78c(win, &lbl_805D5518);
            }
            lbl_80552E08[9] = NULL;
            break;
        }
        lbl_80552E08[2] = lbl_80552E08[1];
    }
}

void fn_80082250(void *arg0, u32 arg1) {
    void *kart;

    kart = FP(arg0, 0x2C);
    fn_8007E1A0(arg1, (u8 *) kart + 0xDC, (u8 *) kart + 0x100, (u8 *) kart + 0x10C);
}

void fn_80082284(void *arg0, u32 arg1) {
    void *kart;

    kart = FP(arg0, 0x2C);
    fn_8007E40C(arg1, (u8 *) kart + 0xDC, (u8 *) kart + 0xC4);
}

s32 fn_800822B4(void) {
    return (FU8(lbl_80552E08[0], 0) >> 7) & 1;
}

void fn_800822C4(void) {
    FU8(lbl_80552E08[0], 0) &= ~0x80;
    if (lbl_80552E08[0xB] != NULL) {
        FU8(lbl_80552E08[0xB], 0x26) |= 0x40;
        FU8(lbl_80552E08[0xB], 0x26) |= 0x80;
    }
}

void fn_80082308(void) {
    u8 field;

    field = FU8(lbl_80552E08[0], 0) | 0x80;
    lbl_80552E08[3] = NULL;
    FU8(lbl_80552E08[0], 0) = field;
    memset(&lbl_80552E08[4], 0, 0x14);
    lbl_80552E08[9] = (void *) 1;
    if (lbl_80552E08[0xB] != NULL) {
        FU8(lbl_80552E08[0xB], 0x26) &= ~0x40;
        FU8(lbl_80552E08[0xB], 0x26) &= ~0x80;
    }
}

s32 fn_8008238C(void *arg0, u32 arg1, f32 farg0) {
    void *color;
    f32 scale;
    void *pt;

    if (FS32(arg0, 0) != 0 && !(FU8(arg0, 0x33) & 1)) {
        s32 sel = (FU8(arg0, 0x30) >> 3) & 0x1F;
        color = (sel == 8) ? &lbl_805D5528 : (sel == 9) ? &lbl_805D5548 : &lbl_805D5520;
        if (FU8(color, 3) == 0xFF ? 1 : 0) {
        }
        if (FU8(color, 3) == 0xFF) {
            scale = (FU8(arg0, 0x33) >> 1 & 1) ? FF32(arg0, 0x18) : FF32(arg0, 0x18) * farg0;
            pt = FP(arg0, 0x50);
            fn_8007D988((u8 *) arg0 + 0x40, pt, (u8 *) color + 4, pt, scale);
            return 1;
        }
    }
    return 0;
}

s32 fn_80082480(void *arg0, u32 arg1, f32 farg0) {
    void *color;
    void *pt;

    color = lbl_8049BA60[FS32(arg0, 0)];
    if (FU8(color, 3) == 0xFF) {
        pt = FP(arg0, 0x28);
        fn_8007D988((u8 *) arg0 + 0x1C, pt, (u8 *) color + 4, pt, FF32(arg0, 0x10) * farg0);
        return 1;
    }
    return 0;
}

s32 fn_8008252C(void *arg0, s32 arg1, u32 arg2, f32 farg0) {
    void *color;
    void *pt;
    s32 idx;

    idx = (FS32(arg0, 0) == 2) ? 2 : arg1;
    color = lbl_8049BA60[idx];
    if (FU8(color, 3) == 0xFF) {
        pt = FP(arg0, 0x28);
        fn_8007D988((u8 *) arg0 + 0x1C, pt, color, (u8 *) color + 4, FF32(arg0, 0x10) * farg0);
        return 1;
    }
    return 0;
}

s32 fn_800825E8(void *arg0, u32 arg1, f32 farg0) {
    void *pt;
    f32 scale;

    if (FS32(arg0, 0) != 0 && FU8(&lbl_805D5550, 3) == 0xFF) {
        scale = (FU8(arg0, 0x33) >> 1 & 1) ? FF32(arg0, 0x18) : FF32(arg0, 0x18) * farg0;
        pt = FP(arg0, 0x50);
        fn_8007D988((u8 *) arg0 + 0x40, pt, (u8 *) &lbl_805D5550 + 4, pt, scale);
        return 1;
    }
    return 0;
}

s32 fn_800826A4(void *arg0, u32 arg1, f32 farg0) {
    u8 faces[0x150];
    void *face;
    s32 i;
    f32 scale;
    void *pt;

    if (FS32(arg0, 4) != 0 && FU8(&lbl_805D5558, 3) == 0xFF) {
        if (FS32(arg0, 0) == 1) {
            Vec d;
            d.x = FF32(arg0, 0x44) - FF32(arg0, 0x54);
            d.y = FF32(arg0, 0x48) - FF32(arg0, 0x58);
            d.z = FF32(arg0, 0x4C) - FF32(arg0, 0x5C);
            if (PSVECMag(&d) < 0.00001f) {
                kar_collision_build_obb_face_data(arg0, faces);
                face = faces;
                for (i = 0; i < 6; i++) {
                    kar_dbmapzone__8007e61c((u8 *) face + 0xC, face, &lbl_805D5558,
                                             (s32 *) ((u8 *) &lbl_805D5558 + 4));
                    face = (u8 *) face + 0x3C;
                }
                return 1;
            }
        }
        scale = (FU8(arg0, 0x37) >> 1 & 1) ? FF32(arg0, 0x1C) : FF32(arg0, 0x1C) * farg0;
        pt = FP(arg0, 0x54);
        fn_8007D988((u8 *) arg0 + 0x44, pt, &lbl_805D5558,
                    (s32 *) ((u8 *) &lbl_805D5558 + 4), scale);
        return 1;
    }
    return 0;
}

s32 fn_80082838(void *arg0, u32 arg1, f32 farg0) {
    s32 hit;
    s32 i;
    void *elem;
    s32 mode;

    hit = 0;
    elem = FP(arg0, 0xC);
    for (i = 0; i < FS32(arg0, 8); i++) {
        if (fn_8008238C(elem, arg1, FF32(arg0, 0x6C)) != 0) {
            hit = 1;
        }
        elem = (u8 *) elem + 0xC8;
    }
    mode = kar_collision_object_get_max_linked_state(arg0);
    elem = FP(arg0, 0x14);
    if (mode == 0) {
        for (i = 0; i < FS32(arg0, 0x10); i++) {
            if (fn_80082480(elem, arg1, FF32(arg0, 0x6C)) != 0) {
                hit = 1;
            }
            elem = (u8 *) elem + 0x44;
        }
    } else {
        for (i = 0; i < FS32(arg0, 0x10); i++) {
            if (fn_8008252C(elem, mode, arg1, FF32(arg0, 0x6C)) != 0) {
                hit = 1;
            }
            elem = (u8 *) elem + 0x44;
        }
    }
    return hit;
}

void fn_8008294C(void) {
    void *w;

    FU8(&lbl_80552E40, 0x137) = 0;
    lbl_80552E40.unk0 &= ~0x80;
    lbl_80552E40.unk18 = -1;
    lbl_80552E40.unk10 = 0;
    lbl_80552E40.unk8 = 0;
    lbl_80552E40.unk4 = 0;
    lbl_80552E40.unkC = NULL;
    FU8(&lbl_80552E40, 0x134) = 0;
    FU8(&lbl_80552E40, 0x135) = 0;
    FU8(&lbl_80552E40, 0x136) = 0;
    FU8(&lbl_80552E40, 0x137) = 1;
    lbl_80552E40.unkD4 = -1;
    lbl_80552E40.unk18 = 0;
    w = kar_textlib__800ab2d4(0, 0, 0x14, 0x14, 2, NULL);
    lbl_80552E40.unk18 = (s32) (u32) w;
    if (w != NULL) {
        FU8(w, 0x26) &= ~0x10;
        kar_textlib__near_800ab584(w, &lbl_805D5570);
        kar_textlib__near_800ab55c(w, &lbl_805D5574);
        kar_textlib__near_800ab534(w, 12.0f, 16.0f);
        FU8((void *) (u32) lbl_80552E40.unk18, 0x26) |= 0x40;
        FU8((void *) (u32) lbl_80552E40.unk18, 0x26) |= 0x80;
    }
    memset((u8 *) &lbl_80552E40 + 0x1C, 0, 0xA0);
    memset((u8 *) &lbl_80552E40 + 0xBC, 0, 0x18);
}

void fn_80082A84(void) {
    Vec eye;
    Vec interest;
    Vec up;
    Vec left;
    Vec dir;
    Vec target;
    void *cobj;

    fn_800B8808();
    cobj = (void *) (u32) fn_800B8054();
    HSD_CObjGetInterest(cobj, &interest);
    HSD_CObjGetEyePosition(cobj, &eye);
    HSD_CObjGetUpVector(cobj, &up);
    HSD_CObjGetLeftVector(cobj, &left);
    dir.x = interest.x - eye.x;
    dir.y = interest.y - eye.y;
    dir.z = interest.z - eye.z;
    kar_lbvector_normalize_with_axis_fallback(&dir, &dir);
    target.x = 10.0f * dir.x + eye.x;
    target.y = 10.0f * dir.y + eye.y;
    target.z = 10.0f * dir.z + eye.z;
}

void fn_80082C1C(void) {
    if ((void *) (u32) lbl_80552E40.unk18 != NULL) {
    }
}

void fn_80083058(s32 arg0) {
    (void) arg0;
}

void fn_80083644(void *arg0, u32 arg1) {
    void *kart;

    kart = FP(arg0, 0x2C);
    fn_8007E1A0(arg1, (u8 *) kart + 0x2F8, (u8 *) kart + 0x334, (u8 *) kart + 0x340);
}

void fn_80083678(void) {
    u8 *p;
    s32 i;

    p = (u8 *) &lbl_80552E40;
    for (i = 0; i < 4; i++) {
        if (FU8(p, 0x1C) != 0) {
            fn_8007E1A0(2U, p + 0x20, p + 0x2C, p + 0x38);
        }
        p += 0x28;
    }
}

void fn_800836E4(void *arg0, u32 arg1) {
    void *kart;

    kart = FP(arg0, 0x2C);
    fn_8007E40C(arg1, (u8 *) kart + 0x2F8, (u8 *) kart + 0x2EC);
}

s32 fn_80083714(void) {
    return (FU8(&lbl_80552E40, 0) >> 7) & 1;
}

void fn_80083724(void) {
    lbl_80552E40.unk0 &= ~0x80;
    if ((void *) (u32) lbl_80552E40.unk18 != NULL) {
        FU8((void *) (u32) lbl_80552E40.unk18, 0x26) |= 0x40;
        FU8((void *) (u32) lbl_80552E40.unk18, 0x26) |= 0x80;
    }
}

void fn_80083768(void) {
    lbl_80552E40.unk0 |= 0x80;
    if ((void *) (u32) lbl_80552E40.unk18 != NULL) {
        FU8((void *) (u32) lbl_80552E40.unk18, 0x26) &= ~0x40;
        FU8((void *) (u32) lbl_80552E40.unk18, 0x26) &= ~0x80;
    }
}

s32 fn_800837AC(void) {
    return (FU8(&lbl_80552E40, 0) >> 5) & 3;
}

void fn_800837BC(void) {
    lbl_80552E40.unk18 = -1;
    lbl_80552E40.unk0 &= ~0x60;
}

void fn_800837DC(void) {
    lbl_80552E40.unk0 = (lbl_80552E40.unk0 & ~0x60) | 0x20;
    if ((void *) (u32) lbl_80552E40.unk18 != NULL) {
        FU8((void *) (u32) lbl_80552E40.unk18, 0x26) &= ~0x40;
        FU8((void *) (u32) lbl_80552E40.unk18, 0x26) &= ~0x80;
        kar_textlib__near_800ab5a4((void *) (u32) lbl_80552E40.unk18);
        kar_textlib__near_800ab4c0((void *) (u32) lbl_80552E40.unk18, 0, 0U);
        if ((lbl_80552E40.unk0 >> 4) & 1) {
            kar_textlib__near_800ab78c((void *) (u32) lbl_80552E40.unk18, "Gene Info Pause Mode");
            return;
        }
        kar_textlib__near_800ab78c((void *) (u32) lbl_80552E40.unk18, "Gene Info Mode");
    }
}

void fn_80083894(void) {
    if ((lbl_80552E40.unk0 >> 4) & 1) {
        lbl_80552E40.unk0 &= ~0x10;
    } else {
        lbl_80552E40.unk0 |= 0x10;
    }
    lbl_80552E40.unk0 = (lbl_80552E40.unk0 & ~0x60) | 0x20;
    if ((void *) (u32) lbl_80552E40.unk18 != NULL) {
        FU8((void *) (u32) lbl_80552E40.unk18, 0x26) &= ~0x40;
        FU8((void *) (u32) lbl_80552E40.unk18, 0x26) &= ~0x80;
        kar_textlib__near_800ab5a4((void *) (u32) lbl_80552E40.unk18);
        kar_textlib__near_800ab4c0((void *) (u32) lbl_80552E40.unk18, 0, 0U);
        if ((lbl_80552E40.unk0 >> 4) & 1) {
            kar_textlib__near_800ab78c((void *) (u32) lbl_80552E40.unk18, "Gene Info Pause Mode");
            return;
        }
        kar_textlib__near_800ab78c((void *) (u32) lbl_80552E40.unk18, "Gene Info Mode");
    }
}

s32 fn_8008397C(void) {
    return (FU8(&lbl_80552E40, 0) >> 3) & 1;
}

void fn_8008398C(void) {
    FU8(&lbl_80552E40, 0) &= ~8;
}

void fn_800839A4(void) {
    FU8(&lbl_80552E40, 0) |= 8;
}

void fn_800839BC(s32 arg0, f32 *arg1, f32 *arg2) {
    Vec a;
    Vec b;
    s32 ca;
    s32 cb;

    kar_grcommon_get_startpos_vectors_by_index(0, &a.x, &a.y, &a.z);
    kar_grcommon__near_800cee24(&a.x, &ca);
    kar_grairglider_get_slot_enemy_position(arg0, &b);
    kar_grcommon__near_800cee24(&b.x, &cb);
    *arg1 = kar_grcommon__near_800d066c(ca, cb, 0.0f, 0.0f);
    *arg2 = kar_grcommon__near_800d066c(cb, ca, 0.0f, 0.0f);
    if (*arg1 > 0.0f) {
        *arg1 = (11.428572f * *arg1) / 100.0f;
    }
    if (*arg2 > 0.0f) {
        *arg2 = (11.428572f * *arg2) / 100.0f;
    }
}

void fn_80083AAC(f32 *arg0, f32 *arg1, f32 *arg2) {
    Vec a;
    s32 ca;
    s32 cb;

    kar_grcommon_get_startpos_vectors_by_index(0, &a.x, &a.y, &a.z);
    kar_grcommon__near_800cee24(&a.x, &ca);
    kar_grcommon__near_800cee24(arg0, &cb);
    *arg1 = kar_grcommon__near_800d066c(ca, cb, 0.0f, 0.0f);
    *arg2 = kar_grcommon__near_800d066c(cb, ca, 0.0f, 0.0f);
    if (*arg1 > 0.0f) {
        *arg1 = (11.428572f * *arg1) / 100.0f;
    }
    if (*arg2 > 0.0f) {
        *arg2 = (11.428572f * *arg2) / 100.0f;
    }
}

void fn_80083B90(void *arg0, void *arg1) {
    lbl_80552E40.unkBC = FF32(arg0, 0);
    lbl_80552E40.unkC0 = FF32(arg0, 4);
    lbl_80552E40.unkC4 = FF32(arg0, 8);
    lbl_80552E40.unkC8 = FF32(arg1, 0);
    lbl_80552E40.unkCC = FF32(arg1, 4);
    lbl_80552E40.unkD0 = FF32(arg1, 8);
}

void fn_80083BCC(void) {
    if (kar_emupdate__near_8020438c((void *) (u32) lbl_80552E40.unkC) == 0) {
        lbl_80552E40.unkC = 0;
        lbl_80552E40.unkC4 = 0.0f;
        lbl_80552E40.unkC0 = 0.0f;
        lbl_80552E40.unkBC = 0.0f;
        lbl_80552E40.unkD0 = 0.0f;
        lbl_80552E40.unkCC = 0.0f;
        lbl_80552E40.unkC8 = 0.0f;
        return;
    }
    if (lbl_80552E40.unkBC != lbl_80552E40.unkC8 || lbl_80552E40.unkC0 != lbl_80552E40.unkCC ||
        lbl_80552E40.unkC4 != lbl_80552E40.unkD0) {
        HSD_StateInvalidate(-1);
        HSD_StateInitDirect(GX_VTXFMT0, 2);
        GXLoadPosMtxImm((MtxPtr) ((u8 *) HSD_CObjGetCurrent() + 0x54), GX_PNMTX0);
        GXSetLineWidth(0xC, 5);
        GXBegin(GX_LINES, GX_VTXFMT0, 2);
        fn_8007E128(&lbl_80552E40.unkBC, &lbl_80552E40.unkC8, &lbl_805D5430);
    }
}

void fn_80083CBC(void) {
    kar_gmmain__near_80005d04(0);
    if (kar_gmmain__near_80005d04(0) == 0) {
        kar_gmmain__near_80005d78(0);
    }
}

void fn_80083CF4(void) {
    lbl_805DD660.unk3 = 0;
    lbl_805DD660.unk0 = 0;
    lbl_805DD660.unk1 = 0;
    lbl_805DD660.unk2 = 0;
    lbl_805DD660.unk3 = 1;
}

void fn_80083D20(void *arg0, u8 arg1) {
    void *node;

    node = FP(hsdGObj_p_link_heads, 0x38);
    while (node != NULL) {
        if (arg0 == kar_wneffect__near_8022312c(node)) {
            FU8(FP(node, 0x2C), 0x218) = arg1;
        }
        node = FP(node, 8);
    }
}

void fn_80083D8C(s32 arg0) {
    (void) arg0;
}

void fn_80083D90(void *arg0, u32 arg1) {
    void *kart;

    kart = FP(arg0, 0x2C);
    fn_8007E1A0(arg1, (u8 *) kart + 0xAC, (u8 *) kart + 0xD0, (u8 *) kart + 0xDC);
}

void fn_80083DC4(void *arg0, u32 arg1) {
    void *kart;

    kart = FP(arg0, 0x2C);
    fn_8007E40C(arg1, (u8 *) kart + 0xAC, (u8 *) kart + 0x94);
}

void fn_80083DF4(void) {
    lbl_80552F78.unk18 = 0;
    lbl_80552F78.unk20 = 0;
    lbl_80552F78.unk24 = 0;
    lbl_80552F78.unk0 = 1;
    lbl_80552F78.unk4 = 1;
    lbl_80552F78.unk8 = 1;
    lbl_80552F78.unkC = 0;
    lbl_80552F78.unk14 = 0;
    lbl_80552F78.unk10 = 0;
    lbl_80552F78.unk30 = 0;
    fn_800848E0(&lbl_80552F78, 0);
}

void *fn_80083E4C(s32 arg0) {
    (void) arg0;
    return NULL;
}

void fn_800848E0(void *arg0, s32 arg1) {
    void *w;

    (void) arg0;
    (void) arg1;
    if (lbl_80552F78.unk14 == 0) {
        w = kar_textlib__800ab2d4(0, 0, 0x14, 0x48, 0xD, fn_800841A0);
        lbl_80552F78.unk14 = (s32) (u32) w;
        if (w != NULL) {
            FU8(w, 0x26) &= ~0x10;
            kar_textlib__near_800ab584(w, &lbl_805DEEB8);
            kar_textlib__near_800ab55c(w, &lbl_805DEEBC);
            kar_textlib__near_800ab534(w, 9.0f, 16.0f);
            FU8((void *) (u32) lbl_80552F78.unk14, 0x26) |= 0x40;
            FU8((void *) (u32) lbl_80552F78.unk14, 0x26) |= 0x80;
        }
    }
}

void fn_800849B8(u32 arg1) {
    (void) arg1;
}

void fn_80084B80(void) {
    u32 gobj;

    if (lbl_80552F78.unk30 == 0) {
        gobj = HSD_GObjCreate(0x24, 0x3F, 0);
        if (gobj != 0U) {
            HSD_GObjGXLink(gobj, fn_800849B8, 0x24, 1);
        }
        lbl_80552F78.unk30 = gobj;
    }
}

void fn_80084BF0(void) {
    void *w;

    memset(lbl_80552FB0, 0, 0x94);
    FS32(lbl_80552FB0, 0x3C) = 0;
    FS32(lbl_80552FB0, 0x40) = -1;
    FP(lbl_80552FB0, 0x44) = NULL;
    w = kar_textlib__800ab2d4(0, 0, 0x14, 0x17, 4, NULL);
    FP(lbl_80552FB0, 0x44) = w;
    if (w != NULL) {
        FU8(w, 0x26) &= ~0x10;
        kar_textlib__near_800ab584(w, &lbl_805D5648);
        kar_textlib__near_800ab55c(w, &lbl_805D564C);
        kar_textlib__near_800ab534(w, 12.0f, 16.0f);
        FU8(FP(lbl_80552FB0, 0x44), 0x26) |= 0x40;
        FU8(FP(lbl_80552FB0, 0x44), 0x26) |= 0x80;
    }
    HSD_ObjAllocInit((HSD_ObjAllocData *) (lbl_80552FB0 + 0x94), 0x8C, 4);
    HSD_ObjAllocInit((HSD_ObjAllocData *) (lbl_80552FB0 + 0xC0), 0x3000, 4);
    HSD_ObjAllocInit((HSD_ObjAllocData *) (lbl_80552FB0 + 0xEC), 0x41EB0, 4);
}

void kar_diag__80084d0c(void) {
}

void fn_80084FA0(s32 arg0) {
    (void) arg0;
}

void fn_80085674(s32 arg0) {
    (void) arg0;
}

void fn_80085C48(s32 arg0) {
    (void) arg0;
}

s32 fn_80085D0C(void) {
    return 0;
}

void fn_80085D1C(s32 arg0) {
    (void) arg0;
}

void fn_800841A0(void *win) {
    (void) win;
}

void fn_80081600(s32 arg0) {
    (void) arg0;
}






