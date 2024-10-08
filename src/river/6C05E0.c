#include "common.h"
#include "ld_addrs.h"
#include "world/world.h"
#include "app_level/app_level.h"
#include "app_render/app_render.h"
#include "river.h"

extern u8 D_802E2620_6CA400;
extern EnvSoundData D_802E2624_6CA404[62];
extern PokemonDef D_802E271C_6CA4FC;
extern s32 D_802E28B4_6CA694;
extern PokemonDef D_802E28B8_6CA698;
extern ScreenSettings D_802E2920_6CA700;
extern SceneSetup D_802E293C_6CA71C;

extern HeightMap D_80321560_709340;

void func_802D8800_6C05E0(WorldBlock* arg0, WorldBlock* arg1) {
    pokemonAdd(arg0, arg1, &D_802E271C_6CA4FC);
}

void func_802D8824_6C0604(WorldBlock* arg0, WorldBlock* arg1) {
    pokemonsChangeBlock(arg0, arg1, &D_802E271C_6CA4FC);
}

void func_802D8848_6C0628(WorldBlock* arg0) {
    pokemonRemove(arg0, &D_802E271C_6CA4FC);
}

void func_802D886C_6C064C(void) {
    setHeightMap(&D_80321560_709340);
    createWorld(&D_8012AC90, 0x63, 0x64, 0x7E, 9, 3, &func_802D8800_6C05E0, &func_802D8848_6C0628, &func_802D8824_6C0604);
    setSkyBoxFollowPlayer();
    func_80363928_503D38(0x80, 0xE4, 3, 5);
}

void func_802D88F8_6C06D8(s32 arg0) {
    D_802E28B4_6CA694 = arg0;
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

void func_802D895C_6C073C(GObj* arg0) {
    if (Items_GetPokeFluteCmd() == 0) {
        auSetBGMChannelVolume(0, 0xA, D_802E2620_6CA400);
    }
    if (D_802E2620_6CA400 != 0) {
        D_802E2620_6CA400--;
    }
}

void func_802D89AC_6C078C(s32 arg0) {
}

void func_802D89B4_6C0794(WorldBlock* arg0) {
    WorldBlock* next;

    if (D_802E28B4_6CA694 <= 0) {
        if (arg0->next != NULL) {
            next = arg0->next;
            Items_DisplaceAllItems(
                (arg0->descriptor->worldPos.x - next->descriptor->worldPos.x) * 100.0f,
                (arg0->descriptor->worldPos.y - next->descriptor->worldPos.y) * 100.0f,
                (arg0->descriptor->worldPos.z - next->descriptor->worldPos.z) * 100.0f);
        } else {
            func_802D88F8_6C06D8(2);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C05E0/func_802D8A48_6C0828.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C05E0/func_802D8B34_6C0914.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C05E0/func_802D8C24_6C0A04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C05E0/func_802D8CF0_6C0AD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C05E0/func_802D8DC4_6C0BA4.s")

void func_802D8E98_6C0C78(GObj*, GroundResult*);
#pragma GLOBAL_ASM("asm/nonmatchings/river/6C05E0/func_802D8E98_6C0C78.s")

void func_802D8FCC_6C0DAC(void) {
    void* sp1C;
    void* temp_v0;
    void* temp_v0_2;

    sp1C = func_800A73C0((u32) AB5860_ROM_START, (u32) AB5860_ROM_END);
    temp_v0 = func_800A73C0((u32) AB5980_ROM_START, (u32) AB5980_ROM_END);
    if (sp1C != NULL && temp_v0 != NULL) {
        func_800A1ED0(3, sp1C, temp_v0);
    }
    sp1C = func_800A73C0((u32) AC8510_ROM_START, (u32) AC8510_ROM_END);
    temp_v0_2 = func_800A73C0((u32) AC8830_ROM_START, (u32) AC8830_ROM_END);
    if (sp1C != NULL && temp_v0_2 != NULL) {
        func_800A1ED0(0, sp1C, temp_v0_2);
    }
    D_80382D10_523120 = func_800A2094(4, 100, getMainCamera());
    D_80382D14_523124 = func_800A5E08(0xA);
    func_800A5DF4(0xC0, 0x30);
}

void func_802D90B8_6C0E98(void) {
    s32 i;
    u8 r, g, b;

    D_802E2920_6CA700.zBuffer = gtlMalloc(0x25800, 0x40);
    viApplyScreenSettings(&D_802E2920_6CA700);
    // clang-format off
    for (i = 0; i < ARRAY_COUNT(D_800BE248); i++) { D_800BE228[i] = D_800BE248[i] = 0; }
    // clang-format on
    func_8009CE00();
    omAddGObj(OBJID_0, func_802D895C_6C073C, LINK_0, 0x80000000);
    Pokemons_Init();
    func_802D886C_6C064C();
    getBackgroundColor(&r, &g, &b);
    createMainCameras(r << 0x18 | g << 0x10 | b << 8);
    initUI(func_802D89B4_6C0794, func_802D92B0_6C1090, NULL, 0, func_802D8E98_6C0C78);
    setEndLevelCallback(func_802D88F8_6C06D8);
    setPauseCallback(func_802D89AC_6C078C);
    EnvSound_Init(D_802E2624_6CA404, ARRAY_COUNT(D_802E2624_6CA404));
    func_802D8FCC_6C0DAC();
    PokemonDetector_Create();
    PokemonDetector_Enable();
    func_802E25C4_6CA3A4();
}

void func_802D9208_6C0FE8(s32 arg0) {
}

s32 func_802D9210_6C0FF0(s32 sceneId) {
    D_802E293C_6CA71C.gtlSetup.heapSize = (uintptr_t) river_code_VRAM - (uintptr_t) _29A190_VRAM_END;
    gtlSetIntervals(1, 2);
    gtlDisableNearClipping(1);
    omSetupScene(&D_802E293C_6CA71C);

    if (D_802E28B4_6CA694 == 6) {
        return SCENE_RIVER;
    }

    if (func_8009BC68() > 0) {
        return SCENE_CAMERA_CHECK;
    }

    func_800AAED0(0x10);

    return SCENE_OAKS_LAB_2;
}
