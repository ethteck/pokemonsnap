#include "valley.h"

extern EnvSoundData D_802D2740_7ABCD0[0x3A];
extern f32 D_802D2828_7ABDB8;
extern PokemonDef D_802D282C_7ABDBC;
extern s32 D_802D297C_7ABF0C;
extern GObj* D_802D2980_7ABF10;
extern PokemonDef D_802D2984_7ABF14;
extern PokemonDef D_802D2994_7ABF24;
extern PokemonDef D_802D29A4_7ABF34;
extern PokemonDef D_802D29B4_7ABF44;
extern ScreenSettings D_802D29D4_7ABF64;
extern SceneSetup D_802D29F0_7ABF80;
extern UNK_TYPE D_802D2A00_7ABF90;
extern GObj* D_802D3B34_7AD0C4;

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
    EnvSound_Cleanup();
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

void func_802C5DCC_79F35C(s32 arg0) {
}

void func_802C5DD4_79F364(WorldBlock* arg0) {
    WorldBlock* next;

    if (D_802D297C_7ABF0C <= 0) {
        if (arg0->next != NULL) {
            next = arg0->next;
            Items_DisplaceAllItems(
                (arg0->descriptor->worldPos.x - next->descriptor->worldPos.x) * 100.0f,
                (arg0->descriptor->worldPos.y - next->descriptor->worldPos.y) * 100.0f,
                (arg0->descriptor->worldPos.z - next->descriptor->worldPos.z) * 100.0f);
        } else {
            func_802C5D18_79F2A8(END_LEVEL_REASON_FINISH);
        }
    }
}

void func_802C5E68_79F3F8(GObj* obj) {
    DObj* a0;
    Mtx3Float* position;
    GObj* pokemonObj;
    ObjectSpawn spawn;
    WorldBlock* roomA;
    PokemonDef def = D_802D2984_7ABF14;
    UNUSED s32 pad[2];

    if (D_802D2980_7ABF10 == NULL) {
        roomA = getCurrentWorldBlock();
        spawn.id = PokemonID_GOLDEEN;
        spawn.translation.x = 0.0;
        spawn.translation.y = 0.0;
        spawn.translation.z = 0.0;
        spawn.euler.x = 0.0;
        spawn.euler.y = 0.0;
        spawn.euler.z = 0.0;
        spawn.scale.x = 1.0;
        spawn.scale.y = 1.0;
        spawn.scale.z = 1.0;

        pokemonObj = D_802D2980_7ABF10 = pokemonAddOne(roomA, roomA, &spawn, &def);
        if (pokemonObj != NULL) {
            cmdSendCommand(pokemonObj, 0x1F, obj);
            pokemonObj = D_802D2980_7ABF10;
        }

        position = &obj->data.dobj->position;
        a0 = pokemonObj->data.dobj;
        GET_TRANSFORM(a0)->pos.v.x = position->v.x;
        GET_TRANSFORM(a0)->pos.v.y = position->v.y;
        GET_TRANSFORM(a0)->pos.v.z = position->v.z;
    }
}

void func_802C5F70_79F500(GObj* obj) {
    DObj* a0;
    Mtx3Float* position;
    GObj* pokemonObj;
    ObjectSpawn spawn;
    WorldBlock* roomA;
    PokemonDef def = D_802D2994_7ABF24;

    if (D_802D2980_7ABF10 == NULL) {
        roomA = getCurrentWorldBlock();
        spawn.id = PokemonID_ARTICUNO;
        spawn.translation.x = 0.0;
        spawn.translation.y = 0.0;
        spawn.translation.z = 0.0;
        spawn.euler.x = 0.0;
        spawn.euler.y = 0.0;
        spawn.euler.z = 0.0;
        spawn.scale.x = 1.0;
        spawn.scale.y = 1.0;
        spawn.scale.z = 1.0;

        pokemonObj = D_802D2980_7ABF10 = pokemonAddOne(roomA, roomA, &spawn, &def);

        a0 = D_802D2980_7ABF10; // TODO required to match
        GET_POKEMON(pokemonObj)->behavior = 0;

        position = &obj->data.dobj->position;
        a0 = D_802D2980_7ABF10->data.dobj;
        GET_TRANSFORM(a0)->pos.v.x = position->v.x;
        GET_TRANSFORM(a0)->pos.v.y = position->v.y;
        GET_TRANSFORM(a0)->pos.v.z = position->v.z;
    }
}

void func_802C606C_79F5FC(GObj* obj) {
    DObj* a0;
    Mtx3Float* position;
    ObjectSpawn spawn;
    WorldBlock* roomA;
    PokemonDef def = D_802D29A4_7ABF34;
    GObj* pokemonObj;

    if (D_802D2980_7ABF10 == NULL) {
        roomA = getCurrentWorldBlock();
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

        pokemonObj = D_802D2980_7ABF10 = pokemonAddOne(roomA, roomA, &spawn, &def);

        a0 = D_802D2980_7ABF10; // TODO required to match
        GET_POKEMON(pokemonObj)->behavior = 0;

        position = &obj->data.dobj->position;
        a0 = D_802D2980_7ABF10->data.dobj;
        GET_TRANSFORM(a0)->pos.v.x = position->v.x;
        GET_TRANSFORM(a0)->pos.v.y = position->v.y;
        GET_TRANSFORM(a0)->pos.v.z = position->v.z;
    }
}

void func_802C6168_79F6F8(void*);
#pragma GLOBAL_ASM("asm/nonmatchings/valley/79F1B0/func_802C6168_79F6F8.s")

void func_802C6300_79F890(void) {
    void* sp1C;
    void* temp_v0;
    void* temp_v0_2;

    sp1C = func_800A73C0((u32) AB5860_ROM_START, (u32) AB5860_ROM_END);
    temp_v0 = func_800A73C0((u32) AB5980_ROM_START, (u32) AB5980_ROM_END);
    if ((sp1C != NULL) && (temp_v0 != NULL)) {
        func_800A1ED0(3, sp1C, temp_v0);
    }
    sp1C = func_800A73C0((u32) AD0E00_ROM_START, (u32) AD0E00_ROM_END);
    temp_v0_2 = func_800A73C0((u32) AD1640_ROM_START, (u32) AD1640_ROM_END);
    if ((sp1C != NULL) && (temp_v0_2 != NULL)) {
        func_800A1ED0(0, sp1C, temp_v0_2);
    }
    D_80382D10_523120 = func_800A2094(4, 0x64, getMainCamera());
    D_80382D14_523124 = func_800A5E08(0xA);
    func_800A5DF4(0xC0, 0x30);
}

void func_802C63EC_79F97C(void) {
    s32 i;
    u8 r, g, b;

    D_802D29D4_7ABF64.zBuffer = gtlMalloc(0x25800, 0x40);
    viApplyScreenSettings(&D_802D29D4_7ABF64);
    // clang-format off
    for (i = 0; i < ARRAY_COUNT(D_800BE248); i++) { D_800BE228[i] = D_800BE248[i] = 0; }
    // clang-format on
    func_8009CE00();
    omAddGObj(OBJID_0, func_802C5D7C_79F30C, LINK_0, 0x80000000);
    Pokemons_Init();
    func_802C5C8C_79F21C();
    getBackgroundColor(&r, &g, &b);
    createMainCameras(r << 0x18 | g << 0x10 | b << 8);
    initUI(func_802C5DD4_79F364, func_802C6B30_7A00C0, NULL, 0, func_802C6168_79F6F8);
    setEndLevelCallback(func_802C5D18_79F2A8);
    setPauseCallback(func_802C5DCC_79F35C);
    EnvSound_Init(D_802D2740_7ABCD0, ARRAY_COUNT(D_802D2740_7ABCD0));
    func_802C6300_79F890();
    PokemonDetector_Create();
    PokemonDetector_Enable();
    func_802C6AD4_7A0064();
}

void func_802C653C_79FACC(s32 arg0) {
}

s32 func_802C6544_79FAD4(s32 arg0) {
    D_802D2A00_7ABF90 = valley_code_VRAM - _3F63D0_VRAM_END; // TODO OR stage5_extra_VRAM

    gtlSetIntervals(1, 2);
    gtlDisableNearClipping(1);
    omSetupScene(&D_802D29F0_7ABF80);
    if (D_802D297C_7ABF0C == 6) {
        return SCENE_VALLEY;
    }
    if (func_8009BC68() > 0) {
        return SCENE_CAMERA_CHECK;
    }
    func_800AAED0(0x10);
    return SCENE_OAKS_LAB_2;
}
