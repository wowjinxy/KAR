#include <dolphin/types.h>

extern "C" {
#include <global.h>
}

struct Vec3 {
    f32 x, y, z;
};

struct NamePair {
    void *a;
    void *b;
};

struct TopRideKirby {
    void **vtable; //0x00
};

struct TopRideCpuInputReader {
    void *vtable;              //0x00
    TopRideKirby *kirby;       //0x04
    Vec3 heading;               //0x08
    s32 reaction_budget;         //0x14
    s32 x18;                      //0x18
    s32 difficulty;                 //0x1C
    f32 steer_noise;                 //0x20
    s32 x24;                          //0x24
    s32 hold_frames;                   //0x28
    s32 x2c;                            //0x2C
    u8 debug_draw;                       //0x30
    u8 x31[3];                            //0x31
    f32 steer_hist[9];                     //0x34
    f32 last_steer;                         //0x58
    s32 hist_index;                          //0x5C
    u8 last_charge;                           //0x60
    u8 x61[3];                                 //0x61
    s32 x64;                                    //0x64
    s32 prev_state;                              //0x68
    s32 reseed_timer;                             //0x6C
    s32 lowspeed_frames;                           //0x70
    TopRideKirby *kirby_dup;                        //0x74
};

struct ClassMeta {
    void *owner;
    u32 size;
    void *p1;
    u32 stride;
    void *p2;
    u32 z1;
    void *p3;
    u32 z2;
    void *p4;
    u32 z3;
    u32 z4;
};

extern "C" {
f32 HSD_Randf(void);
extern f32 lbl_805E39D8;
extern f32 lbl_805E39C0;
void *kar_diag__803ad760(s32, s32, void *, void *, s32);
void *kar_diag__near_803882e8(...);

extern void *lbl_804BD254[]; // base reader vtable

extern void *lbl_805D95E0;
extern void *lbl_805D95E8;
extern void *lbl_805D95F8;
extern void *lbl_805D9600;
extern void *lbl_805D95B0;
extern void *lbl_805D95B8;
}

extern NamePair lbl_805D96B0, lbl_805D96B8;
extern NamePair lbl_805D96D8, lbl_805D96E0;
extern NamePair lbl_805D96E8, lbl_805D96F0;
extern NamePair lbl_805D9708, lbl_805D9710;
extern NamePair lbl_805D96C0, lbl_805D96C8;
extern NamePair lbl_805D9768, lbl_805D9770;
extern NamePair lbl_805D9690, lbl_805D96A0;
extern NamePair lbl_805D9758, lbl_805D9760;
extern NamePair lbl_805D9780, lbl_805D9788;
extern NamePair lbl_805D95C0, lbl_805D95C8;

static char lbl_804D7CB4[] = "GrenadeMgr::Grenade";
static char lbl_804D7CC8[] = "ObjCollect<GrenadeMgr::Grenade>";
static ClassMeta lbl_804D7CE8 = {&lbl_805D96B0, 0x54, &lbl_805D95E0, 0x14, &lbl_805D95E8, 0, &lbl_805D95F8, 0, &lbl_805D9600, 0, 0};

static char lbl_804D7D14[] = "KirbyHandle";
static char lbl_804D7D20[] = "ObjCollect<KirbyHandle>";
static ClassMeta lbl_804D7D38 = {&lbl_805D96C8, 0x54, &lbl_805D95E0, 0x14, &lbl_805D95E8, 0, &lbl_805D95F8, 0, &lbl_805D9600, 0, 0};

static char lbl_804D7D74[] = "MineMgr::Mine";
static char lbl_804D7D84[] = "ObjCollect<MineMgr::Mine>";
static ClassMeta lbl_804D7DA0 = {&lbl_805D96D8, 0x54, &lbl_805D95E0, 0x14, &lbl_805D95E8, 0, &lbl_805D95F8, 0, &lbl_805D9600, 0, 0};

static char lbl_804D7DCC[] = "EmberMgr::Ember";
static char lbl_804D7DDC[] = "ObjCollect<EmberMgr::Ember>";
static ClassMeta lbl_804D7DF8 = {&lbl_805D96E8, 0x54, &lbl_805D95E0, 0x14, &lbl_805D95E8, 0, &lbl_805D95F8, 0, &lbl_805D9600, 0, 0};

static char lbl_804D7E7C[] = "MissileMgr::Missile";
static char lbl_804D7E90[] = "ObjCollect<MissileMgr::Missile>";
static ClassMeta lbl_804D7EB0 = {&lbl_805D9708, 0x54, &lbl_805D95E0, 0x14, &lbl_805D95E8, 0, &lbl_805D95F8, 0, &lbl_805D9600, 0, 0};

static char lbl_804D7C80[] = "Singleton<Route>";
static char lbl_805D9698[] = "Route";
static ClassMeta lbl_804D7C94 = {&lbl_805D9690, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

static char lbl_804D847C[] = "Singleton<EnemyMgr>";
static char lbl_804D8470[] = "EnemyMgr";
static ClassMeta lbl_804D8490 = {&lbl_805D9758, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

static char lbl_804D8618[] = "ObjCollect<CpuObstacleMgr::CpuObstacle>";
static char lbl_804D85FC[] = "CpuObstacleMgr::CpuObstacle";

static struct {
    void *owner;
    char file[0x14];
    char cond[0x10];
} lbl_804D8640 = {&lbl_805D9768, "a2d_cpu_kirby.cpp", "cpuLevel_ <= 4"};

static char lbl_804D8670[] = "Course::ControlPolicy";
static char lbl_805D9778[] = "BG3000";
static ClassMeta lbl_804D8688 = {&lbl_805D9780, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

static char lbl_804D7964[] = "Singleton<Course>";
static ClassMeta lbl_804D7978 = {&lbl_805D95C0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

NamePair lbl_805D96B0 = {&lbl_804D7CC8, 0};
NamePair lbl_805D96B8 = {&lbl_804D7CB4, &lbl_804D7CE8};
NamePair lbl_805D96C0 = {&lbl_804D7D20, 0};
NamePair lbl_805D96C8 = {&lbl_804D7D14, &lbl_804D7D38};
NamePair lbl_805D96D8 = {&lbl_804D7D84, 0};
NamePair lbl_805D96E0 = {&lbl_804D7D74, &lbl_804D7DA0};
NamePair lbl_805D96E8 = {&lbl_804D7DDC, 0};
NamePair lbl_805D96F0 = {&lbl_804D7DCC, &lbl_804D7DF8};
NamePair lbl_805D9708 = {&lbl_804D7E90, 0};
NamePair lbl_805D9710 = {&lbl_804D7E7C, &lbl_804D7EB0};
NamePair lbl_805D9690 = {&lbl_804D7C80, 0};
NamePair lbl_805D96A0 = {&lbl_805D9698, &lbl_804D7C94};
NamePair lbl_805D9758 = {&lbl_804D847C, 0};
NamePair lbl_805D9760 = {&lbl_804D8470, &lbl_804D8490};
NamePair lbl_805D9768 = {&lbl_804D8618, 0};
NamePair lbl_805D9770 = {&lbl_804D85FC, &lbl_804D8640};
NamePair lbl_805D9780 = {&lbl_804D8670, 0};
NamePair lbl_805D9788 = {&lbl_805D9778, &lbl_804D8688};
NamePair lbl_805D95C0 = {&lbl_804D7964, 0};
NamePair lbl_805D95C8 = {&lbl_805D95B8, &lbl_804D7978};
s32 lbl_805D9790 = 1;

// difficulty tuning table
static f32 lbl_804D7F48[0x14A] = {
    20.0f, 60.0f, 1.0f, 20.0f, 20.0f, 20.0f, 30.0f, 0.0f, 5.0f, 20.0f,
    0.0f, 5.0f, 90.0f, 5.0f, 15.0f, 10.0f, 12.0f, 180.0f, 4.0f, 1.0f,
    2.0f, 3.0f, 5.0f, 6.0f, 7.0f, 8.0f, 30.0f, 27.0f, 30.0f, 35.0f,
    25.0f, 40.0f, 20.0f, 15.0f, 45.0f, 1.0f, 0.5f, 1.0f, 1.0f, 0.1f,
    3.0f, 0.1f, 0.1f, 3.0f, 1.0f, 0.5f, 0.1f, 1.0f, 1.0f, 0.1f,
    3.0f, 0.1f, 3.0f, 1.0f, 0.5f, 1.0f, 0.1f, 1.0f, 0.1f, 0.1f,
    3.0f, 3.0f, 0.0f, 4.0f, 4.0f, 4.0f, 30.0f, 60.0f, 60.0f, 45.0f,
    30.0f, 10.0f, 0.0f, 0.0f, 10.0f, 20.0f, 40.0f, 100.0f, 0.0f, 10.0f,
    20.0f, 40.0f, 100.0f, 0.0f, 8.0f, 15.0f, 40.0f, 100.0f, 0.0f, 20.0f,
    40.0f, 70.0f, 100.0f, 0.0f, 20.0f, 50.0f, 70.0f, 100.0f, 80.0f, 65.0f,
    50.0f, 0.0f, -70.0f, 100.0f, 70.0f, 30.0f, 0.0f, 4.0f, 1.59329e-10f,
    240.45805f, 7.3798206e28f, 7.3212463e28f, -9.73549e-26f, 1.9361832e31f,
    1.7161157e25f, 3.036214e29f, 1.8913171e28f, 9.740617e26f, 4.955644e28f,
    1.8013005e25f, 917.8029f, 1.601967e-19f, 6.162976e-33f, -8.0610115e-26f,
    -1.4678591e-27f, -3.005369e-37f, -1.467567e-27f, -1.0566681e-24f,
    -4.809183e-27f, -2.784617e-37f, -3.0059426e-37f, -5.8375707e-29f,
    -4.539616e-33f, -7.2443723e-37f, -6.3039925e-37f, -6.362759e-37f,
    -4.0318227e-38f, 6.626667e16f, 4.174572e24f, 1.59329e-10f, -5.6868283e-37f,
    -6.7448006e-37f, -1.9138403e-26f, -5.839124e-32f, -4.2897056e-38f,
    -8.6090955e-32f, -1.2174182e-30f, -4.3044607e-38f, 6.2149675e17f,
    1.59329e-10f, -5.6868283e-37f, -6.7448006e-37f, -1.9138403e-26f,
    -1.15833155e-32f, -4.2889136e-38f, -3.0058753e-37f, -3.5549855e-38f,
    -2.520038e-37f, -3.621689e-28f, -2.5200472e-37f, 6.4287788e16f,
    6.2149675e17f, 1.59329e-10f, -6.5804823e-31f, -5.839124e-32f,
    -4.2897056e-38f, -8.6090955e-32f, -1.2174182e-30f, -4.3044607e-38f,
    6.2149675e17f, -6.5804823e-31f, -1.15833155e-32f, 6.4287788e16f,
    5.7646075e17f, 1.59329e-10f, -7.479465e-37f, -5.7456354e-37f,
    -6.5804823e-31f, -5.839124e-32f, -4.2897056e-38f, -8.6090955e-32f,
    -1.2174182e-30f, -4.3044607e-38f, 6.2149675e17f, -7.479465e-37f,
    -5.7456354e-37f, -6.5804823e-31f, -1.15833155e-32f, 6.4287788e16f,
    5.7646075e17f, 1.59329e-10f, -7.3913225e-37f, -6.5804823e-31f,
    -5.839124e-32f, -4.2897056e-38f, -8.6090955e-32f, -1.2174182e-30f,
    -4.3044607e-38f, 6.2149675e17f, -7.3913225e-37f, -6.5804823e-31f,
    -1.15833155e-32f, 6.4287788e16f, 5.7646075e17f, -6.5804823e-31f,
    -5.9510958e-37f, -7.1268085e-37f, -2.4907452e-37f, -4.203316e-27f,
    -3.4321645e-37f, -3.8168386e-33f, -1.0556707e-24f, 5.7646075e17f,
    -7.505792e-31f, -1.1439657e-32f, -6.5390618e-37f, -7.449851e-37f,
    6.48415e16f, 1.59329e-10f, -1.664129e-37f, -1.7963989e-37f,
    -5.745626e-37f, 6.162976e-33f, 1.59329e-10f, -1.664129e-37f,
    -1.7963989e-37f, -5.745626e-37f, -8.1638445e-26f, 1.3324003e33f,
    7.230473e13f, 1.1562569e15f, 7.397523e16f, 0.0f, 1.59329e-10f,
    -1.664129e-37f, -1.7963989e-37f, -5.745626e-37f, -8.1638506e-26f,
    1.9311555e13f, 1.119589e34f, 1.59329e-10f, -1.664129e-37f,
    -1.7963989e-37f, -5.745626e-37f, -8.1638445e-26f, 16.407965f,
    7.762522e22f, 1.119589e34f, 1.59329e-10f, -1.664129e-37f,
    -1.7963989e-37f, -5.745626e-37f, -8.1638445e-26f, 1.1562571e15f,
    -3.7226385e-27f, 0.0f, 1.59329e-10f, -1.664129e-37f, -1.7964041e-37f,
    -7.3031654e-37f, 6.162976e-33f, 1.59329e-10f, -7.03865e-37f,
    -1.2176422e-30f, -3.9083694e-30f, 6.4842053e16f, 2.1423942e25f,
    -2.9804418e20f, -4528.313f, 4.170794e25f, 1.59329e-10f, -7.03865e-37f,
    -2.960936e-37f, -3.4315725e-37f, -1.0750507e-24f, 6.2149675e17f,
    1.59329e-10f, -6.068864e-37f, -6.656616e-37f, -6.362759e-37f,
    -8.669894e-37f, -3.4315725e-37f, -1.0750507e-24f, 6.2149675e17f,
    1.59329e-10f, -6.5804823e-31f, -2.6964572e-37f, -1.1439657e-32f,
    4.654567e16f, 0.0f, 1.59329e-10f, -4.203316e-27f, -3.4315725e-37f,
    -1.0750507e-24f, 6.2149675e17f, 1.59329e-10f, -5.6868283e-37f,
    -6.7448006e-37f, -8.935539e-28f, -1.0750507e-24f, 6.2149675e17f,
    1.59329e-10f, -7.788409e-37f, -7.670887e-37f, -8.935539e-28f,
    -1.0750507e-24f, 6.2149675e17f, 1.59329e-10f, -7.0092954e-37f,
    -6.776501e-37f, 4.654567e16f, 0.0f, 1.59329e-10f, -1.3364717e-29f,
    -2.9609428e-37f, -3.4311712e-37f, -5.95126e-37f, -2.9462498e-37f,
    -1.14396576e-32f, 4.654567e16f, 0.0f, -6.7741804e-37f, -6.6566166e-37f,
    -4.4541176e-26f, -7.771275e-25f, -1.7596385e-37f, -7.244391e-37f,
    -5.745632e-37f, -4.0330726e-38f, -8.258388e-31f,
};

static char lbl_804D7888[0x1C];

// CPU input-reader vtable
static void *lbl_804D8710[0x12];

static char lbl_804D8694[] = "GROUND_JUMP_UK*";

extern "C" void kar_a2d_cpu_kirby__near_802ed9a8(void *arg0) {
    s32 id = *(s32 *) ((char *) arg0 + 0x5C);
    kar_diag__803ad760(id, 0, &lbl_805D96F0, &lbl_805D96E8, 0);
}

extern "C" void kar_a2d_cpu_kirby__near_802ed9dc(void *arg0) {
    s32 id = *(s32 *) ((char *) arg0 + 0x5C);
    kar_diag__803ad760(id, 0, &lbl_805D96E0, &lbl_805D96D8, 0);
}

extern "C" void kar_a2d_cpu_kirby__near_802eda10(void *arg0) {
    s32 id = *(s32 *) ((char *) arg0 + 0x5C);
    kar_diag__803ad760(id, 0, &lbl_805D9710, &lbl_805D9708, 0);
}

extern "C" void kar_a2d_cpu_kirby__near_802eda44(void *arg0) {
    s32 id = *(s32 *) ((char *) arg0 + 0x5C);
    kar_diag__803ad760(id, 0, &lbl_805D96B8, &lbl_805D96B0, 0);
}

extern "C" s32 fn_802EF80C() {
    return 0;
}

extern "C" u8 kar_a2d_cpu_kirby__near_802eebe4(TopRideCpuInputReader *reader, f32 threshold) {
    if (reader->steer_noise < threshold || (u32) reader->reseed_timer == 0) {
        reader->steer_noise = lbl_805E39D8 * HSD_Randf();
        reader->reseed_timer = (u32) lbl_804D7F48[0x11];
        return 1;
    }
    return 0;
}

extern "C" void kar_a2d_cpu_kirby__near_802eec54(TopRideCpuInputReader *reader, TopRideKirby *kirby) {
    u8 rolled;
    f32 *table = &lbl_804D7F48[0x49];

    if (reader->steer_noise < *(f32 *) ((char *) kirby + 0xB4) * table[reader->difficulty] ||
        (u32) reader->reseed_timer == 0) {
        reader->steer_noise = lbl_805E39D8 * HSD_Randf();
        reader->reseed_timer = (u32) lbl_804D7F48[0x11];
        rolled = 1;
    } else {
        rolled = 0;
    }
    if (rolled != 0 && reader->hold_frames == 0) {
        reader->hold_frames = 5;
    }
}

extern "C" void *kar_a2d_cpu_kirby__802eed00(TopRideCpuInputReader *reader, TopRideKirby *kirby, u32 difficulty) {
    typedef s32 (*KirbyMethod)(TopRideKirby *);
    char *base = (char *) lbl_804D7888;
    f32 *table;
    s32 slot;

    reader->vtable = lbl_804BD254;
    reader->kirby = kirby;
    reader->vtable = lbl_804D8710;
    reader->heading.x = lbl_805E39C0;
    reader->heading.y = lbl_805E39C0;
    reader->heading.z = lbl_805E39C0;
    reader->reaction_budget = 0;
    reader->steer_noise = lbl_805E39C0;
    reader->x24 = 0;
    reader->hold_frames = 0;
    reader->x2c = 0;
    reader->last_charge = 0;
    reader->x64 = 0;
    reader->prev_state = 0;
    reader->reseed_timer = 0;
    reader->lowspeed_frames = 0;
    reader->debug_draw = 0;

    {
        TopRideKirby *k = reader->kirby;
        slot = ((KirbyMethod)(k->vtable[0x30 / 4]))(k);
    }
    {
        TopRideKirby *k = reader->kirby;
        reader->x18 = ((KirbyMethod)(k->vtable[0x38 / 4]))(k);
    }
    table = (f32 *) (base + 0x6C0);
    reader->reaction_budget = (u32) table[reader->x18 + 0x12];
    reader->difficulty = difficulty;
    if ((u32) reader->difficulty > 4) {
        __assert(base + 0xDC4, 0x3ED, base + 0xDD8);
    }
    table[slot + 0x3E] = (f32) reader->difficulty;
    reader->steer_hist[0] = 0.0f;
    reader->steer_hist[1] = 0.0f;
    reader->steer_hist[2] = 0.0f;
    reader->steer_hist[3] = 0.0f;
    reader->steer_hist[4] = 0.0f;
    reader->steer_hist[5] = 0.0f;
    reader->steer_hist[6] = 0.0f;
    reader->steer_hist[7] = 0.0f;
    reader->steer_hist[8] = 0.0f;
    reader->hist_index = 0;
    reader->last_steer = 0.0f;
    reader->kirby_dup = kirby;
    *(f32 *) ((char *) kirby + 0x2C) = table[reader->difficulty + 0x62] / 100.0f;
    return reader;
}
