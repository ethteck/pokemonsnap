#include "volcano.h"

extern EnvSoundData volcano_EnvSounds[] = {
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

PokemonDef volcano_PokemonDefs[] = {
    { PokemonID_MAGMAR,
      func_802D7F28_729128,
      pokemonChangeBlockOnGround,
      pokemonRemoveOne },
    { PokemonID_RAPIDASH,
      func_802D8A5C_729C5C,
      pokemonChangeBlockOnGround,
      pokemonRemoveOne },
    { PokemonID_CHARMANDER,
      func_802D9CB8_72AEB8,
      pokemonChangeBlockOnGround,
      pokemonRemoveOne },
    { PokemonID_VULPIX,
      func_802DAA9C_72BC9C,
      Pokemon_ChangeBlockAndRemove,
      pokemonRemoveOne },
    { PokemonID_CHARMELEON,
      func_802DD214_72E414,
      volcano_CharmeleonChangeBlock,
      pokemonRemoveOne },
    { PokemonID_CHARIZARD,
      func_802DD7AC_72E9AC,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { PokemonID_ARCANINE,
      func_802DC018_72D218,
      pokemonChangeBlockOnGround,
      pokemonRemoveOne },
    { PokemonID_GROWLITHE,
      func_802DB558_72C758,
      pokemonChangeBlockOnGround,
      pokemonRemoveOne },
    { PokemonID_1027,
      func_802DEA44_72FC44,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { PokemonID_1029,
      func_802DE6B4_72F8B4,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { PokemonID_1028,
      func_802DE52C_72F72C,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { PokemonID_1002,
      func_802DED34_72FF34,
      pokemonChangeBlockOnGround,
      pokemonRemoveOne },
    { PokemonID_600,
      func_802DDEC0_72F0C0,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { PokemonID_MOLTRES,
      func_802DE34C_72F54C,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { PokemonID_MAGIKARP,
      func_802DF378_730578,
      pokemonChangeBlockOnGround,
      pokemonRemoveOne },
    { PokemonID_1003,
      func_8035E0D4_4FE4E4,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { PokemonID_1026,
      func_802DDA98_72EC98,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { PokemonID_1030,
      func_802DF240_730440,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { PokemonID_1031,
      func_802DFB44_730D44,
      pokemonChangeBlock,
      NULL },
    { PokemonID_1001,
      func_802DFA38_730C38,
      pokemonChangeBlock,
      pokemonRemoveOne },
    { 0, NULL, NULL, NULL }
};

PokemonDef volcano_MagikarpDef = {
    PokemonID_MAGIKARP,
    func_802DF378_730578,
    pokemonChangeBlockOnGround,
    pokemonRemoveOne
};

RandomState2 volcano_MagikarpProbabilities[] = {
    { 3, volcano_SpawnMagikarp },
    { 7, NULL },
};

u16 D_802E0EB4_7320B4 = 0;
s32 volcano_EndLevelReason = 0;

ScreenSettings volcano_ScreenSettings = {
    D_803B5000,    /* fb1 */
    D_803DA800,    /* fb2 */
    NULL,          /* fb3 */
    NULL,          /* zbuffer */
    SCREEN_WIDTH,  /* width*/
    SCREEN_HEIGHT, /* height */
    0x00000A99     /* flags*/
};

SceneSetup volcano_SceneSetup = {
    {
        0,                /* unk_00*/
        omUpdateAll,      /* fnUpdate */
        omDrawAll,        /* fnDraw */
        _326C10_VRAM_END, /* heapBase */
        0,                /* heapSize */
        1,                /* unk_14 */
        2,                /* numContexts */
        0x5000,           /* dlBufferSize0 */
        0x1400,           /* dlBufferSize1 */
        0x0400,           /* dlBufferSize2 */
        0x0000,           /* dlBufferSize3 */
        0xC800,           /* gfxHeapSize */
        2,                /* unk30 */
        0x4000,           /* rdpOutputBufferSize */
        func_800A1A50,    /* fnPreRender */
        contUpdate        /* fnUpdateInput */
    },
    0,                            /* numOMThreads */
    1024,                         /* omThreadStackSize */
    0,                            /* numOMStacks */
    0,                            /* unk4C */
    0,                            /* numOMProcesses */
    0,                            /* numOMGobjs */
    sizeof(GObj),                 /* objectSize */
    0,                            /* numOMMtx */
    0,                            /* unk60 */
    volcano_func_802D6780_727980, /* unk64 */
    0,                            /* numOMAobjs */
    0,                            /* numOMMobjs */
    0,                            /* numOMDobjs */
    sizeof(DObj),                 /* omDobjSize */
    0,                            /* numOMSobjs */
    0x58,                         /* omSobjSize */
    0,                            /* numOMCameras */
    sizeof(OMCamera),             /* omCameraSize */
    volcano_Init                  /* postInitFunc */
};

PokemonDef volcano_ArcanineDef = {
    PokemonID_ARCANINE,
    func_802DC018_72D218,
    pokemonChangeBlockOnGround,
    pokemonRemoveOne
};

PokemonDef volcano_GrowlitheDef = {
    PokemonID_GROWLITHE,
    func_802DB558_72C758,
    pokemonChangeBlockOnGround,
    pokemonRemoveOne
};

PokemonDef volcano_CharizardDef = {
    PokemonID_CHARIZARD,
    func_802DD7AC_72E9AC,
    pokemonChangeBlockOnGround,
    pokemonRemoveOne
};

PokemonDef volcano_Pokemon1030Def = {
    PokemonID_1030,
    func_802DF240_730440,
    pokemonChangeBlock,
    pokemonRemoveOne
};

u16 D_802E0FA4_7321A4 = 4;

Vec3f D_802E0FA8_7321A8 = { 0, 0, 0 };

void volcano_SpawnMagikarp(GObj* obj) {
    DObj* model;
    Mtx3Float* position;
    GObj* pokemonObj;
    ObjectSpawn spawn;
    WorldBlock* block;
    PokemonDef def = volcano_MagikarpDef;

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

void volcano_HandleCollision(GObj* obj, GroundResult* groundResult) {
    DObj* model = obj->data.dobj;
    Item* item = GET_ITEM(obj);
    s32 i;
    s32 numOptions = ARRAY_COUNT(volcano_MagikarpProbabilities);
    s32 sumWeight;
    s32 randValue;

    if (groundResult->surfaceType != SURFACE_TYPE_00FF00) {
        if (groundResult->surfaceType == SURFACE_TYPE_337FB2 && Vec3fDistance(&GET_TRANSFORM(gPlayerDObj)->pos.v, &model->position.v) > 50.0f) {
            sumWeight = 0;
            for (i = 0; i < numOptions; i++) {
                sumWeight += volcano_MagikarpProbabilities[i].weight;
            }
            randValue = randRange(sumWeight);
            sumWeight = 0;
            for (i = 0; i < numOptions; i++) {
                sumWeight += volcano_MagikarpProbabilities[i].weight;
                if (sumWeight > randValue) {
                    if (volcano_MagikarpProbabilities[i].func != NULL && !D_802E0EB4_7320B4) {
                        volcano_MagikarpProbabilities[i].func(obj);
                        D_802E0EB4_7320B4 = true;
                    }
                    break;
                }
            }
        }
    } else if (item->itemID == ITEM_ID_PESTER_BALL) {
        cmdSendCommandToLink(LINK_POKEMON, POKEMON_CMD_38, obj);
    }
}

void volcano_PokemonAdd(WorldBlock* arg0, WorldBlock* arg1) {
    pokemonAdd(arg0, arg1, volcano_PokemonDefs);
}

void volcano_PokemonChangeBlock(WorldBlock* arg0, WorldBlock* arg1) {
    pokemonsChangeBlock(arg0, arg1, volcano_PokemonDefs);
}

void volcano_PokemonRemove(WorldBlock* arg0) {
    pokemonRemove(arg0, volcano_PokemonDefs);
}

void volcano_InitWorld(void) {
    setHeightMap(&D_8031D4D0_76E6D0);
    createWorld(&D_800FFFB8, OBJID_SKYBOX, OBJID_WORLD_BLOCK_MIN, OBJID_WORLD_BLOCK_MAX, LINK_PLAYER, DL_LINK_3, volcano_PokemonAdd, volcano_PokemonRemove, volcano_PokemonChangeBlock);
    setSkyBoxFollowPlayer();
    func_80363928_503D38(OBJID_128, OBJID_228, LINK_POKEMON, 5);
}

void volcano_EndLevel(s32 endLevelReason) {
    volcano_EndLevelReason = endLevelReason;
    func_800A19D8(endLevelReason);
    PokemonDetector_Disable();
    EnvSound_Cleanup();
    auStopBGM();
    auStopAllSounds();
    destroyWorld();
    func_80356FBC_4F73CC();
    removeMainCamera();
    func_800067DC();
}

void volcano_func_802D64A0_7276A0(GObj* obj) {
}

void volcano_Pause(s32 arg0) {
}

void volcano_ExitBlock(WorldBlock* arg0) {
    WorldBlock* next;

    if (volcano_EndLevelReason <= 0) {
        if (arg0->next != NULL) {
            next = arg0->next;
            Items_DisplaceAllItems(
                (arg0->descriptor->worldPos.x - next->descriptor->worldPos.x) * 100.0f,
                (arg0->descriptor->worldPos.y - next->descriptor->worldPos.y) * 100.0f,
                (arg0->descriptor->worldPos.z - next->descriptor->worldPos.z) * 100.0f);
        } else {
            volcano_EndLevel(END_LEVEL_REASON_FINISH);
        }
    }
}

void volcano_LoadEffects(void) {
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

void volcano_Init(void) {
    s32 i;
    u8 r, g, b;

    volcano_ScreenSettings.zBuffer = gtlMalloc(0x25800, 0x40);
    viApplyScreenSettings(&volcano_ScreenSettings);
    // clang-format off
    for (i = 0; i < ARRAY_COUNT(D_800BE248); i++) { D_800BE228[i] = D_800BE248[i] = 0; }
    // clang-format on
    func_8009CE00();
    omAddGObj(OBJID_0, volcano_func_802D64A0_7276A0, LINK_0, 0x80000000);
    Pokemons_Init();
    volcano_InitWorld();
    getBackgroundColor(&r, &g, &b);
    createMainCameras(r << 0x18 | g << 0x10 | b << 8);
    initUI(volcano_ExitBlock, func_802DFB80_730D80, NULL, 0, volcano_HandleCollision);
    setEndLevelCallback(volcano_EndLevel);
    setPauseCallback(volcano_Pause);
    EnvSound_Init(volcano_EnvSounds, ARRAY_COUNT(volcano_EnvSounds));
    volcano_LoadEffects();
    PokemonDetector_Create();
    PokemonDetector_Enable();
    func_802E0C28_731E28();
}

void volcano_func_802D6780_727980(s32 arg0) {
}

void volcano_func_802D6788_727988(void) {
    if (!gSPImemOkay || !gSPDmemOkay) {
        setPlayerFlag(PFID_21, true);
    }
}

s32 volcano_Start(s32 arg0) {
    volcano_SceneSetup.gtlSetup.heapSize = (uintptr_t) volcano_code_VRAM - (uintptr_t) _326C10_VRAM_END;
    gtlSetIntervals(1, 2);
    gtlDisableNearClipping(1);
    volcano_func_802D6788_727988();
    omSetupScene(&volcano_SceneSetup);
    if (volcano_EndLevelReason == END_LEVEL_REASON_RETRY) {
        return SCENE_VOLCANO;
    }
    if (func_8009BC68() > 0) {
        return SCENE_CAMERA_CHECK;
    }
    func_800AAED0(0x10);
    return SCENE_13;
}

void volcano_SpawnArcanine(GObj* obj) {
    DObj* model;
    Mtx3Float* position;
    GObj* pokemonObj;
    ObjectSpawn spawn;
    WorldBlock* block;
    PokemonDef def = volcano_ArcanineDef;

    block = getCurrentWorldBlock();
    spawn.id = PokemonID_ARCANINE;
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

    position = &GET_TRANSFORM(obj->data.dobj)->pos;
    model = pokemonObj->data.dobj;
    GET_TRANSFORM(model)->pos.v.x = position->v.x;
    GET_TRANSFORM(model)->pos.v.y = position->v.y;
    GET_TRANSFORM(model)->pos.v.z = position->v.z;
    omEndProcess(NULL);
}

void volcano_SpawnGrowlithe(GObj* obj) {
    DObj* model;
    Mtx3Float* position;
    GObj* pokemonObj;
    ObjectSpawn spawn;
    WorldBlock* block;
    PokemonDef def = volcano_GrowlitheDef;

    block = getCurrentWorldBlock();
    spawn.id = PokemonID_GROWLITHE;
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

    position = &GET_TRANSFORM(obj->data.dobj)->pos;
    model = pokemonObj->data.dobj;
    GET_TRANSFORM(model)->pos.v.x = position->v.x;
    GET_TRANSFORM(model)->pos.v.y = position->v.y;
    GET_TRANSFORM(model)->pos.v.z = position->v.z;
    omEndProcess(NULL);
}

void volcano_CharmeleonChangeBlock(GObj* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    pokemonChangeBlockOnGround(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
}

void func_802D6A5C_727C5C(GObj* obj) {
    DObj* model;
    Mtx3Float* position;
    GObj* pokemonObj;
    ObjectSpawn spawn;
    WorldBlock* block;
    PokemonDef def = volcano_CharizardDef;

    block = getCurrentWorldBlock();
    spawn.id = PokemonID_CHARIZARD;
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

    position = &GET_TRANSFORM(obj->data.dobj)->pos;
    model = pokemonObj->data.dobj;
    GET_TRANSFORM(model)->pos.v.x = position->v.x;
    GET_TRANSFORM(model)->pos.v.y = position->v.y;
    GET_TRANSFORM(model)->pos.v.z = position->v.z;
}

void func_802D6B2C_727D2C(GObj* obj) {
    GObj* var;

    var = Pokemon_AddAtGeo(obj, PokemonID_1030, &volcano_Pokemon1030Def);
    GET_POKEMON(var)->behavior = 0;
    omEndProcess(NULL);
}

void func_802D6B64_727D64(GObj* obj) {
    GObj* var;

    var = Pokemon_AddAtGeo(obj, PokemonID_1030, &volcano_Pokemon1030Def);
    GET_POKEMON(var)->behavior = 4;
    GET_POKEMON(obj)->miscVars[1].obj = var;
    omEndProcess(NULL);
}

void func_802D6BB0_727DB0(GObj* obj) {
    GObj* var;

    var = Pokemon_AddAtGeo(obj, PokemonID_1030, &volcano_Pokemon1030Def);
    GET_POKEMON(var)->behavior = 1;
    GET_TRANSFORM(var->data.dobj)->scale.v.x *= 1.5f;
    GET_TRANSFORM(var->data.dobj)->scale.v.y *= 1.5f;
    GET_TRANSFORM(var->data.dobj)->scale.v.z *= 4.0f;
    omEndProcess(NULL);
}

void func_802D6C38_727E38(GObj* obj) {
    GObj* var;

    var = Pokemon_AddAtGeo(obj, PokemonID_1030, &volcano_Pokemon1030Def);
    GET_POKEMON(var)->behavior = 5;
    GET_TRANSFORM(var->data.dobj)->scale.v.x *= 1.5f;
    GET_TRANSFORM(var->data.dobj)->scale.v.y *= 1.5f;
    GET_TRANSFORM(var->data.dobj)->scale.v.z *= 4.0f;
    omEndProcess(NULL);
}

void func_802D6CC0_727EC0(GObj* obj) {
    GObj* var;

    var = Pokemon_AddAtGeo(obj, PokemonID_1030, &volcano_Pokemon1030Def);
    GET_POKEMON(var)->behavior = 5;
    omEndProcess(NULL);
}

void func_802D6CFC_727EFC(GObj* obj) {
    GObj* var;

    var = Pokemon_AddAtGeo(obj, PokemonID_1030, &volcano_Pokemon1030Def);
    GET_POKEMON(var)->behavior = 2;
    GET_TRANSFORM(var->data.dobj)->scale.v.x *= 1.0f;
    GET_TRANSFORM(var->data.dobj)->scale.v.y *= 1.0f;
    GET_TRANSFORM(var->data.dobj)->scale.v.z *= 2.0f;
    omEndProcess(NULL);
}

s32 func_802D6D6C_727F6C(GObj* obj) {
    u16 randomValue;

    randomValue = randRange(10);
    if (D_802E0FA4_7321A4 == 0) {
        return false;
    }
    if (randomValue < 2) {
        // 20 %
        omCreateProcess(obj, volcano_SpawnArcanine, 1, 1);
    } else if (randomValue < 7) {
        // 60 %
        omCreateProcess(obj, volcano_SpawnGrowlithe, 1, 1);
    } else {
        // 20 %
        return false;
    }
    D_802E0FA4_7321A4--;
    return true;
}

void func_802D6E14_728014(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* model = obj->data.dobj;
    f32 hSpeed = pokemon->hSpeed * 0.033;
    f32 yaw = GET_TRANSFORM(model)->rot.f[2];
    f32 speedX = sinf(yaw) * hSpeed;
    f32 speedZ = cosf(yaw) * hSpeed;

    GET_TRANSFORM(model)->pos.v.x += speedX;
    GET_TRANSFORM(model)->pos.v.z += speedZ;
}

void func_802D6EA8_7280A8(GObj* obj, f32 heading) {
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* model = obj->data.dobj;
    f32 hSpeed = pokemon->hSpeed * 0.033;
    f32 speedX = sinf(heading) * hSpeed;
    f32 speedZ = cosf(heading) * hSpeed;

    GET_TRANSFORM(model)->pos.v.x += speedX;
    GET_TRANSFORM(model)->pos.v.z += speedZ;
}

f32 func_802D6F38_728138(f32 x, f32 z) {
    GroundResult result;

    if (getGroundAt(x, z, &result)) {
        return result.height;
    }
    return 0.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/7272E0/func_802D6F68_728168.s")
