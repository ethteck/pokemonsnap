#include "common.h"

#include "ld_addrs.h"
#include "world/world.h"
#include "app_level/app_level.h"

extern f32 D_802D2828_7ABDB8;
extern PokemonDef D_802D282C_7ABDBC;
extern s32 D_802D297C_7ABF0C;
extern GObj* D_802D2980_7ABF10;
extern PokemonDef D_802D29A4_7ABF34;
extern SceneSetup D_802D29F0_7ABF80;
extern UNK_TYPE D_802D2A00_7ABF90;
extern HeightMap D_8031F9C0_7F8F50;

void func_802C5C20_79F1B0(WorldBlock* arg0, WorldBlock* arg1) {
    pokemonAdd(arg0, arg1, &D_802D282C_7ABDBC);
}

void func_802C5C44_79F1D4(WorldBlock* arg0, WorldBlock* arg1) {
    pokemonsChangeBlock(arg0, arg1, &D_802D282C_7ABDBC);
}

void func_802C5C68_79F1F8(WorldBlock* arg0) {
    pokemonRemove(arg0, &D_802D282C_7ABDBC);
}

void func_802C5C8C_79F21C(void) {
    setHeightMap(&D_8031F9C0_7F8F50);
    createWorld(&D_80100720, 0x63, 0x64, 0x7E, 9, 3, &func_802C5C20_79F1B0, &func_802C5C68_79F1F8, &func_802C5C44_79F1D4);
    setSkyBoxFollowPlayer();
    func_80363928_503D38(0x80, 0xE4, 3, 5);
}

void func_802C5D18_79F2A8(s32 arg0) {
    D_802D297C_7ABF0C = arg0;
    func_800A19D8(arg0);
    PokemonDetector_Disable();
    func_8036650C_50691C();
    auStopBGM();
    auStopAllSounds();
    destroyWorld();
    func_80356FBC_4F73CC();
    removeMainCamera();
    func_800067DC();
}

void func_802C5D7C_79F30C(s32 arg0) {
    D_802D2828_7ABDB8 -= M_PI_F / 45.0f;
    if (D_802D2828_7ABDB8 < 0.0f) {
        D_802D2828_7ABDB8 += 2 * M_PI_F;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/valley/79F1B0/func_802C5DCC_79F35C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/79F1B0/func_802C5DD4_79F364.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/79F1B0/func_802C5E68_79F3F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/79F1B0/func_802C5F70_79F500.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/79F1B0/func_802C606C_79F5FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/79F1B0/func_802C6168_79F6F8.s")

void func_802C6300_79F890(void) {
    void* sp1C;
    void* temp_v0;
    void* temp_v0_2;

    sp1C = func_800A73C0((u32)AB5860_ROM_START, (u32)AB5860_ROM_END);
    temp_v0 = func_800A73C0((u32)AB5980_ROM_START, (u32)AB5980_ROM_END);
    if ((sp1C != NULL) && (temp_v0 != NULL)) {
        func_800A1ED0(3, sp1C, temp_v0);
    }
    sp1C = func_800A73C0((u32)AD0E00_ROM_START, (u32)AD0E00_ROM_END);
    temp_v0_2 = func_800A73C0((u32)AD1640_ROM_START, (u32)AD1640_ROM_END);
    if ((sp1C != NULL) && (temp_v0_2 != NULL)) {
        func_800A1ED0(0, sp1C, temp_v0_2);
    }
    D_80382D10_523120 = func_800A2094(4, 0x64, getMainCamera());
    D_80382D14_523124 = func_800A5E08(0xA);
    func_800A5DF4(0xC0, 0x30);
}

#pragma GLOBAL_ASM("asm/nonmatchings/valley/79F1B0/func_802C63EC_79F97C.s")

void func_802C653C_79FACC(s32 arg0) {
}

s32 func_802C6544_79FAD4(s32 arg0) {
    D_802D2A00_7ABF90 = valley_code_VRAM - _3F63D0_VRAM_END; // TODO OR stage5_extra_VRAM

    gtlSetIntervals(1, 2);
    gtlDisableNearClipping(1);
    omSetupScene(&D_802D29F0_7ABF80);
    if (D_802D297C_7ABF0C == 6) {
        return 5;
    }
    if (func_8009BC68() > 0) {
        return 9;
    }
    func_800AAED0(0x10);
    return 13;
}
