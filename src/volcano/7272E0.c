#include "common.h"
#include "ld_addrs.h"
#include "../world/world.h"
#include "app_level/app_level.h"
#include "app_render/app_render.h"

void func_802D60E0_7272E0(GObj* obj);
void func_802D6780_727980(s32 arg0);

extern EnvSoundData D_802E0C80_731E80[] = {
    { 0x3a, 0, 0xf },
    { 0x3b, 0, 0x12 },
    { 0x3e, 0, 0x12 },
    { 0x3c, 0, 0x23 },
    { 0x3d, 0, 0x23 },
    { 0x11b, 1, 0xa },
    { 0x11c, 1, 0xa },
    { 0x11d, 1, 0xa },
    { 0x11e, 1, 0xa },
    { 0x11f, 1, 0xa },
    { 0x8d, 0, 0xa },
    { 0xbd, 3, 0x1e },
    { 0x8b, 0, 0x16 },
    { 0x78, 0, 0x12 },
    { 0x15b, 1, 0xb },
    { 0x80, 0, 0x8 },
    { 0x81, 0, 0x8 },
    { 0x82, 0, 0x8 },
    { 0x83, 0, 0x8 },
    { 0x112, 1, 0xd },
    { 0x113, 1, 0xd },
    { 0x114, 1, 0xd },
    { 0x115, 1, 0xd },
    { 0x75, 0, 0xb },
    { 0x117, 1, 0x6 },
    { 0x118, 1, 0x6 },
    { 0x119, 1, 0x6 },
    { 0x11a, 1, 0x6 },
    { 0x116, 1, 0x6 },
    { 0x175, 0, 0x5 },
    { 0x86, 0, 0xc },
    { 0x18b, 0, 0xc },
    { 0xd2, 1, 0x7 },
    { 0xd3, 1, 0x7 },
    { 0x178, 0, 0x7 },
    { 0x72, 0, 0x7 },
    { 0x120, 1, 0xf },
    { 0x121, 1, 0xf },
    { 0x122, 1, 0xf },
    { 0xbe, 1, 0x2d },
    { 0xbf, 1, 0x2d },
    { 0x8c, 0, 0x2d },
    { 0x123, 1, 0x7 },
    { 0x124, 1, 0x7 },
    { 0x10e, 1, 0x11 },
    { 0x10f, 1, 0x11 },
    { 0x110, 1, 0x11 },
    { 0x111, 1, 0x11 },
    { 0x184, 0, 0x10 },
};

GObj* func_802D7F28_729128(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802D8A5C_729C5C(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802D9CB8_72AEB8(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802DAA9C_72BC9C(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802DD214_72E414(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802DD7AC_72E9AC(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802DC018_72D218(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802DB558_72C758(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802DEA44_72FC44(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802DE6B4_72F8B4(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802DE52C_72F72C(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802DED34_72FF34(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802DDEC0_72F0C0(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802DE34C_72F54C(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802DF378_730578(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_8035E0D4_4FE4E4(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802DDA98_72EC98(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802DF240_730440(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802DFB44_730D44(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802DFA38_730C38(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);

void func_802D6A14_727C14(GObj*, f32, f32, f32, f32, f32, f32);
void func_802D6630_727830(void);

PokemonDef D_802E0D44_731F44[] = {
    { 0x0000007E,
      func_802D7F28_729128,
      pokemonChangeBlockOnGround,
      pokemonRemoveOne },
    { 0x0000004E,
      func_802D8A5C_729C5C,
      pokemonChangeBlockOnGround,
      pokemonRemoveOne },
    { 4,
      func_802D9CB8_72AEB8,
      pokemonChangeBlockOnGround,
      pokemonRemoveOne },
    { 0x25,
      func_802DAA9C_72BC9C,
      Pokemon_ChangeBlockAndRemove,
      pokemonRemoveOne },
    { 5,
      func_802DD214_72E414,
      func_802D6A14_727C14,
      pokemonRemoveOne },
    { 6,
      func_802DD7AC_72E9AC,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { 0x3b,
      func_802DC018_72D218,
      pokemonChangeBlockOnGround,
      pokemonRemoveOne },
    { 0x3a,
      func_802DB558_72C758,
      pokemonChangeBlockOnGround,
      pokemonRemoveOne },
    { 0x403,
      func_802DEA44_72FC44,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { 0x405,
      func_802DE6B4_72F8B4,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { 0x404,
      func_802DE52C_72F72C,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { 0x000003EA,
      func_802DED34_72FF34,
      pokemonChangeBlockOnGround,
      pokemonRemoveOne },
    { 0x00000258,
      func_802DDEC0_72F0C0,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { 0x00000092,
      func_802DE34C_72F54C,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { 0x00000081,
      func_802DF378_730578,
      pokemonChangeBlockOnGround,
      pokemonRemoveOne },
    { 0x000003EB,
      func_8035E0D4_4FE4E4,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { 0x00000402,
      func_802DDA98_72EC98,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { 0x00000406,
      func_802DF240_730440,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { 0x00000407,
      func_802DFB44_730D44,
      pokemonChangeBlock,
      NULL },
    { 0x000003E9,
      func_802DFA38_730C38,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { 0, NULL, NULL, NULL }
};

PokemonDef D_802E0E94_732094 = {
    0x00000081,
    func_802DF378_730578,
    pokemonChangeBlockOnGround,
    pokemonRemoveOne
};

// TODO type
u32 D_802E0EA4_7320A4[] = {
    0x03000000,
    func_802D60E0_7272E0,
    0x07000000,
    0,
};

s16 D_802E0EB4_7320B4[] = { 0, 0 };
s32 D_802E0EB8_7320B8 = 0;

ScreenSettings D_802E0EBC_7320BC = {
    D_803B5000,    /* fb1 */
    D_803DA800,    /* fb2 */
    NULL,          /* fb3 */
    NULL,          /* zbuffer */
    SCREEN_WIDTH,  /* width*/
    SCREEN_HEIGHT, /* height */
    0x00000A99     /* flags*/
};

SceneSetup D_802E0ED8_7320D8 = {
    {
        0,                      /* unk_00*/
        omUpdateAll,            /* fnUpdate */
        omDrawAll,              /* fnDraw */
        _326C10_VRAM_END,       /* heapBase */
        0,                      /* heapSize */
        1,                      /* unk_14 */
        2,                      /* numContexts */
        0x5000,                 /* dlBufferSize0 */
        0x1400,                 /* dlBufferSize1 */
        0x0400,                 /* dlBufferSize2 */
        0x0000,                 /* dlBufferSize3 */
        0xC800,                 /* gfxHeapSize */
        2,                      /* unk30 */
        0x4000,                 /* rdpOutputBufferSize */
        func_800A1A50,          /* fnPreRender */
        contUpdate              /* fnUpdateInput */
    },
    0,                /* numOMThreads */
    1024,             /* omThreadStackSize */
    0,                /* numOMStacks */
    0,                /* unk4C */
    0,                /* numOMProcesses */
    0,                /* numOMGobjs */
    sizeof(GObj),     /* objectSize */
    0,                /* numOMMtx */
    0,                /* unk60 */
    func_802D6780_727980, /* unk64 */
    0,                /* numOMAobjs */
    0,                /* numOMMobjs */
    0,                /* numOMDobjs */
    sizeof(DObj),     /* omDobjSize */
    0,                /* numOMSobjs */
    0x58,             /* omSobjSize */
    0,                /* numOMCameras */
    sizeof(OMCamera), /* omCameraSize */
    func_802D6630_727830     /* postInitFunc */
};

u32 D_802E0F64_732164[] = {
    0x0000003B,
    func_802DC018_72D218,
    pokemonChangeBlockOnGround
};

extern HeightMap D_8031D4D0_76E6D0;
extern WorldSetup D_800FFFB8;

void func_802DFB80_730D80(s32, f32);
void func_802D61AC_7273AC(GObj*, GroundResult*);
void func_802E0C28_731E28(void);

void func_802D60E0_7272E0(GObj* obj) {
    DObj* model;
    Mtx3Float* position;
    GObj* pokemonObj;
    ObjectSpawn spawn;
    WorldBlock* block;
    PokemonDef def = D_802E0E94_732094;

    block = getCurrentWorldBlock();
    spawn.id = PokemonID_MAGIKARP;
    spawn.translation.x = 0.0;
    spawn.translation.y = 0.0;
    spawn.translation.z = 0.0;
    spawn.euler.x = 0.0;
    spawn.euler.y = 0.0;
    spawn.euler.z = 0.0;
    spawn.scale.x = 1.0;
    spawn.scale.y = 1.0;
    spawn.scale.z = 1.0;

    pokemonObj = pokemonAddOne(block, block, &spawn, &def);

    position = &obj->data.dobj->position;
    model = pokemonObj->data.dobj;
    GET_TRANSFORM(model)->pos.v.x = position->v.x;
    GET_TRANSFORM(model)->pos.v.y = position->v.y;
    GET_TRANSFORM(model)->pos.v.z = position->v.z;
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/7272E0/func_802D61AC_7273AC.s")

void func_802D6344_727544(WorldBlock* arg0, WorldBlock* arg1) {
    pokemonAdd(arg0, arg1, D_802E0D44_731F44);
}

void func_802D6368_727568(WorldBlock* arg0, WorldBlock* arg1) {
    pokemonsChangeBlock(arg0, arg1, D_802E0D44_731F44);
}

void func_802D638C_72758C(WorldBlock* arg0) {
    pokemonRemove(arg0, D_802E0D44_731F44);
}

void func_802D63B0_7275B0(void) {
    setHeightMap(&D_8031D4D0_76E6D0);
    createWorld(&D_800FFFB8, OBJID_SKYBOX, OBJID_WORLD_BLOCK_MIN, OBJID_WORLD_BLOCK_MAX, LINK_PLAYER, DL_LINK_3, func_802D6344_727544, func_802D638C_72758C, func_802D6368_727568);
    setSkyBoxFollowPlayer();
    func_80363928_503D38(OBJID_128, OBJID_228, LINK_POKEMON, 5);
}

void func_802D643C_72763C(s32 arg0) {
    D_802E0EB8_7320B8 = arg0;
    func_800A19D8(arg0);
    PokemonDetector_Disable();
    EnvSound_Cleanup();
    auStopBGM();
    auStopAllSounds();
    destroyWorld();
    func_80356FBC_4F73CC();
    removeMainCamera();
    func_800067DC();
}

void func_802D64A0_7276A0(GObj* obj) {
}

void func_802D64A8_7276A8(s32 arg0) {
}

void func_802D64B0_7276B0(WorldBlock* arg0) {
    WorldBlock* next;

    if (D_802E0EB8_7320B8 <= 0) {
        if (arg0->next != NULL) {
            next = arg0->next;
            Items_DisplaceAllItems(
                (arg0->descriptor->worldPos.x - next->descriptor->worldPos.x) * 100.0f,
                (arg0->descriptor->worldPos.y - next->descriptor->worldPos.y) * 100.0f,
                (arg0->descriptor->worldPos.z - next->descriptor->worldPos.z) * 100.0f);
        } else {
            func_802D643C_72763C(2);
        }
    }
}

void func_802D6544_727744(void) {
    void* sp1C;
    void* temp_v0;
    void* temp_v0_2;

    sp1C = func_800A73C0((u32) AB5860_ROM_START, (u32) AB5860_ROM_END);
    temp_v0 = func_800A73C0((u32) AB5980_ROM_START, (u32) AB5980_ROM_END);
    if (sp1C != NULL && temp_v0 != NULL) {
        func_800A1ED0(3, sp1C, temp_v0);
    }
    sp1C = func_800A73C0((u32) ACF6F0_ROM_START, (u32) ACF6F0_ROM_END);
    temp_v0_2 = func_800A73C0((u32) ACF9A0_ROM_START, (u32) ACF9A0_ROM_END);
    if (sp1C != NULL && temp_v0_2 != NULL) {
        func_800A1ED0(0, sp1C, temp_v0_2);
    }
    D_80382D10_523120 = func_800A2094(4, 100, getMainCamera());
    D_80382D14_523124 = func_800A5E08(0xA);
    func_800A5DF4(0xC0, 0x30);
}

void func_802D6630_727830(void) {
    s32 i;
    u8 r, g, b;

    D_802E0EBC_7320BC.zBuffer = gtlMalloc(0x25800, 0x40);
    viApplyScreenSettings(&D_802E0EBC_7320BC);
    // clang-format off
    for (i = 0; i < ARRAY_COUNT(D_800BE248); i++) { D_800BE228[i] = D_800BE248[i] = 0; }
    // clang-format on
    func_8009CE00();
    omAddGObj(0, func_802D64A0_7276A0, 0, 0x80000000);
    Pokemons_Init();
    func_802D63B0_7275B0();
    getBackgroundColor(&r, &g, &b);
    createMainCameras(r << 0x18 | g << 0x10 | b << 8);
    initUI(func_802D64B0_7276B0, func_802DFB80_730D80, NULL, 0, func_802D61AC_7273AC);
    setEndLevelCallback(func_802D643C_72763C);
    setPauseCallback(func_802D64A8_7276A8);
    EnvSound_Init(D_802E0C80_731E80, ARRAY_COUNT(D_802E0C80_731E80));
    func_802D6544_727744();
    PokemonDetector_Create();
    PokemonDetector_Enable();
    func_802E0C28_731E28();
}

void func_802D6780_727980(s32 arg0) {
}

void func_802D6788_727988(void) {
    if (!gSPImemOkay || !gSPDmemOkay) {
        setPlayerFlag(PFID_21, true);
    }
}

s32 func_802D67C4_7279C4(s32 arg0) {
    D_802E0ED8_7320D8.gtlSetup.heapSize = (uintptr_t) volcano_code_VRAM - (uintptr_t) _326C10_VRAM_END;
    gtlSetIntervals(1, 2);
    gtlDisableNearClipping(1);
    func_802D6788_727988();
    omSetupScene(&D_802E0ED8_7320D8);
    if (D_802E0EB8_7320B8 == 6) {
        return SCENE_VOLCANO;
    }
    if (func_8009BC68() > 0) {
        return SCENE_CAMERA_CHECK;
    }
    func_800AAED0(0x10);
    return SCENE_13;
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/7272E0/func_802D6864_727A64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/7272E0/func_802D693C_727B3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/7272E0/func_802D6A14_727C14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/7272E0/func_802D6A5C_727C5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/7272E0/func_802D6B2C_727D2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/7272E0/func_802D6B64_727D64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/7272E0/func_802D6BB0_727DB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/7272E0/func_802D6C38_727E38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/7272E0/func_802D6CC0_727EC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/7272E0/func_802D6CFC_727EFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/7272E0/func_802D6D6C_727F6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/7272E0/func_802D6E14_728014.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/7272E0/func_802D6EA8_7280A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/7272E0/func_802D6F38_728138.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/7272E0/func_802D6F68_728168.s")
