#include "common.h"
#include "ld_addrs.h"
#include "../world/world.h"
#include "app_level/app_level.h"
#include "app_render/app_render.h"

extern PokemonDef D_802E0D44_731F44;
extern s32 D_802E0EB8_7320B8;
extern SceneSetup D_802E0ED8_7320D8;
extern s32 D_802E0EB8_7320B8;
extern HeightMap D_8031D4D0_76E6D0;
extern WorldSetup D_800FFFB8;
extern PokemonDef D_802E0E94_732094;
extern ScreenSettings D_802E0EBC_7320BC;
extern EnvSoundData D_802E0C80_731E80[0x31];

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
    pokemonAdd(arg0, arg1, &D_802E0D44_731F44);
}

void func_802D6368_727568(WorldBlock* arg0, WorldBlock* arg1) {
    pokemonsChangeBlock(arg0, arg1, &D_802E0D44_731F44);
}

void func_802D638C_72758C(WorldBlock* arg0) {
    pokemonRemove(arg0, &D_802E0D44_731F44);
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
