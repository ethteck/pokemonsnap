#include "valley.h"
#include "app_render/particle.h"

extern EnvSoundData D_802D2740_7ABCD0[0x3A];
extern f32 D_802D2828_7ABDB8;
extern PokemonDef D_802D282C_7ABDBC;
extern s32 D_802D297C_7ABF0C;
extern GObj* D_802D2980_7ABF10;
extern PokemonDef D_802D2984_7ABF14;
extern PokemonDef D_802D2994_7ABF24;
extern PokemonDef D_802D29A4_7ABF34;
extern RandomState2 D_802D29B4_7ABF44[4];
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

void func_802C5D7C_79F30C(GObj* arg0) {
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

        a0 = (DObj*) D_802D2980_7ABF10; // TODO required to match
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

        a0 = (DObj*) D_802D2980_7ABF10; // TODO required to match
        GET_POKEMON(pokemonObj)->behavior = 0;

        position = &obj->data.dobj->position;
        a0 = D_802D2980_7ABF10->data.dobj;
        GET_TRANSFORM(a0)->pos.v.x = position->v.x;
        GET_TRANSFORM(a0)->pos.v.y = position->v.y;
        GET_TRANSFORM(a0)->pos.v.z = position->v.z;
    }
}

void func_802C6168_79F6F8(GObj* obj, GroundResult* ground) {
    DObj* model = obj->data.dobj;
    Item* item = GET_ITEM(obj);
    s32 i;
    s32 numOptions = ARRAY_COUNT(D_802D29B4_7ABF44);
    s32 sumWeight;
    s32 randValue;

    switch (ground->surfaceType) {
        case SURFACE_TYPE_0019FF:
            if (D_802D3B34_7AD0C4 != NULL && item->itemID == ITEM_ID_PESTER_BALL) {
                cmdSendCommand(D_802D3B34_7AD0C4, 43, NULL);
                return;
            }
            break;
        case SURFACE_TYPE_337FB2:
            if (Vec3fDistance(&GET_TRANSFORM(gPlayerDObj)->pos.v, &model->position.v) > 500.0f) {
                sumWeight = 0;
                for (i = 0; i < numOptions; i++) {
                    sumWeight += D_802D29B4_7ABF44[i].weight;
                }
                randValue = randRange(sumWeight);
                sumWeight = 0;
                for (i = 0; i < numOptions; i++) {
                    sumWeight += D_802D29B4_7ABF44[i].weight;
                    if (sumWeight > randValue) {
                        if (D_802D29B4_7ABF44[i].func != NULL) {
                            D_802D29B4_7ABF44[i].func(obj);
                        }
                        break;
                    }
                }
                return;
            }
            break;
    }
}

void func_802C6300_79F890(void) {
    void* scriptDesc;
    void* spritesDesc;

    scriptDesc = func_800A73C0((u32) fx_script_common_ROM_START, (u32) fx_script_common_ROM_END);
    spritesDesc = func_800A73C0((u32) fx_img_common_ROM_START, (u32) fx_img_common_ROM_END);
    if (scriptDesc != NULL && spritesDesc != NULL) {
        fx_setupBankID(3, scriptDesc, spritesDesc);
    }
    scriptDesc = func_800A73C0((u32) fx_script_valley_ROM_START, (u32) fx_script_valley_ROM_END);
    spritesDesc = func_800A73C0((u32) fx_img_valley_ROM_START, (u32) fx_img_valley_ROM_END);
    if ((scriptDesc != NULL) && (spritesDesc != NULL)) {
        fx_setupBankID(0, scriptDesc, spritesDesc);
    }
    D_80382D10_523120 = func_800A2094(4, 100, getMainCamera());
    D_80382D14_523124 = fx_allocEffects(10);
    fx_setDitherModes(0xC0, 0x30);
}

void func_802C63EC_79F97C(void) {
    s32 i;
    u8 r, g, b;

    D_802D29D4_7ABF64.zBuffer = gtlMalloc(0x25800, 0x40);
    viApplyScreenSettings(&D_802D29D4_7ABF64);
    // clang-format off
    for (i = 0; i < ARRAY_COUNT(fx_SpriteBanksNum); i++) { fx_ScriptBanksNum[i] = fx_SpriteBanksNum[i] = 0; }
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
    D_802D2A00_7ABF90 = valley_code_VRAM - valley_assets_VRAM_END; // TODO OR valley_extra_VRAM

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
