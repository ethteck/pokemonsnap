#include "../rainbow.h"

typedef struct Unks16 {
    /* 0x00 */ s16 unk_00[3];
} Unks16;

extern AnimCmd D_80119A8C_4CBE5C;
extern f32 D_800F5DB0_4A8180;
extern AnimCmd* D_801183E0_4CA7B0;
extern AnimCmd** D_80119050_4CB420;

void func_80348994_828104(GObj*);
void func_80348B34_8282A4(GObj*);
void func_80348DD4_828544(GObj*);
void func_80349084_8287F4(GObj*);


extern u8 D_800F1D10_6F4C0[];
extern u8 D_8012C9E0_4DEDB0[];
extern u8 D_8012D700_4DFAD0[];
extern u8 D_8012EFF0_4E13C0[];
extern u8 D_8012FB60_4E1F30[];
extern u8 D_80131D30_4E4100[];
extern u8 D_80133040_4E5410[];
extern u8 D_801358A0_4E7C70[];
extern u8 D_801368F0_4E8CC0[];
extern u8 D_801394D0_4EB8A0[];
extern u8 D_801395A0_4EB970[];
extern u8 D_80139690_4EBA60[];
extern u8 D_80139770_4EBB40[];
extern u8 D_80139840_4EBC10[];
extern u8 D_80139900_4EBCD0[];
extern u8 D_80139A00_4EBDD0[];
extern u8 D_80139B00_4EBED0[];
void func_80348970_8280E0(GObj*);
void func_80348A04_828174(GObj*);
extern u8 gate_matanim_closed[];
extern u8 gate_matanim_opened[];
extern u8 gate_matanim_opening[];
extern u8 gate_matanim_raise_bar[];
extern u8 gate_materials[];
extern u8 gate_modelanim_closed[];
extern u8 gate_modelanim_opened[];
extern u8 gate_modelanim_opening[];
extern u8 gate_modelanim_raise_bar[];
extern PokemonAnimationSetup D_8034AF64_82A6D4;
extern u32 D_8034AFC0_82A730;
extern u32 D_8034AFC4_82A734;
extern u32 D_8034AFC8_82A738[];
extern u32 D_8034AFD0_82A740;
extern u32 D_8034AFD4_82A744;
extern u32 D_8034AFD8_82A748[];

// .data
AnimationHeader D_8034AED0_82A640 = { 1.0f, 100.0f, (AnimCmd**) &gate_modelanim_closed, (AnimCmd***) &gate_matanim_closed, NULL };
AnimationHeader D_8034AEE4_82A654 = { 1.0f, 100.0f, (AnimCmd**) &gate_modelanim_raise_bar, (AnimCmd***) &gate_matanim_raise_bar, NULL };
AnimationHeader D_8034AEF8_82A668 = { 1.0f, 100.0f, (AnimCmd**) &gate_modelanim_opening, (AnimCmd***) &gate_matanim_opening, NULL };
AnimationHeader D_8034AF0C_82A67C = { 1.0f, 100.0f, (AnimCmd**) &gate_modelanim_opened, (AnimCmd***) &gate_matanim_opened, NULL };
CollisionModel D_8034AF20_82A690 = { 0x3E9, (Collider*) &D_800EDF78_6B728, 1.0f };
GObj* D_8034AF2C_82A69C = NULL;
s32 D_8034AF30_82A6A0 = -1;
s32 D_8034AF34_82A6A4 = 0;
s32 D_8034AF38_82A6A8 = 0;

InteractionHandler D_8034AF3C_82A6AC[2] = {
    { 16, (GObjFunc) func_80348A04_828174, 5000.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

Unks16 D_8034AF5C_82A6CC = { { 151, 0x3E9, 0 } };
PokemonAnimationSetup D_8034AF64_82A6D4 = { (AnimationHeader*) &D_8034AED0_82A640, (GObjFunc) func_80348970_8280E0, 0, "", NULL, NULL };
PokemonInitData D_8034AF78_82A6E8 = { (UnkEC64Arg3*) &D_800F1D10_6F4C0, (Texture***) &gate_materials, (GObjFunc) renderModelTypeDFogged, (PokemonAnimationSetup*) &D_8034AF64_82A6D4, { 10.0f, 10.0f, 10.0f }, { 0.0f, 0.0f, 0.0f }, 0.01f, 0, 0, 0, 0, "" };
PokemonDef D_8034AFAC_82A71C = { 0x3E9, (pokemonInit) func_80348FB8_828728, (void (*)(GObj*, f32, f32, f32, f32, f32, f32)) pokemonChangeBlock, (void (*)(GObj*)) pokemonRemoveOne };
u32 D_8034AFBC_82A72C = 0x00000000;
u32 D_8034AFC0_82A730 = 0x0000015D;
u32 D_8034AFC4_82A734 = 0x0000015F;

u32 D_8034AFC8_82A738[] = {
    0x0000015E, 0x00000093,
};

u32 D_8034AFD0_82A740 = 0x0000015D;
u32 D_8034AFD4_82A744 = 0x0000015F;

u32 D_8034AFD8_82A748[] = {
    0x00000160, 0x00000091, 0x3F000000, 0x428C0000,
    (u32) &D_8012EFF0_4E13C0, (u32) &D_80139690_4EBA60, 0x00000000, 0x3F266666,
    0x43070000, (u32) &D_801368F0_4E8CC0, (u32) &D_80139B00_4EBED0, (u32) &D_8034AFC0_82A730,
    0x3F4CCCCD, 0x430C0000, (u32) &D_801358A0_4E7C70, (u32) &D_80139A00_4EBDD0,
    (u32) &D_8034AFC4_82A734, 0x3F19999A, 0x42DC0000, (u32) &D_80133040_4E5410,
    (u32) &D_80139900_4EBCD0, (u32) &D_8034AFC8_82A738, 0x3F000000, 0x42200000,
    (u32) &D_8012C9E0_4DEDB0, (u32) &D_801394D0_4EB8A0, 0x00000000, 0x3F000000,
    0x42A00000, (u32) &D_8012D700_4DFAD0, (u32) &D_801395A0_4EB970, (u32) &D_8034AFD0_82A740,
    0x3F000000, 0x42B40000, (u32) &D_80131D30_4E4100, (u32) &D_80139840_4EBC10,
    (u32) &D_8034AFD4_82A744, 0x3F400000, 0x43480000, (u32) &D_8012FB60_4E1F30,
    (u32) &D_80139770_4EBB40, (u32) &D_8034AFD8_82A748,
};

u32 D_8034B080_82A7F0[] = {
    0x00000000, 0x00000094,
};

u32 D_8034B088_82A7F8[] = {
    0x00000000, 0x0000009B,
};

POKEMON_FUNC(func_80348970_8280E0)
    Pokemon_SetState(obj, func_80348994_828104);
}

POKEMON_FUNC(func_80348994_828104)
    Pokemon_SetAnimation(obj, &D_8034AED0_82A640);
    Pokemon_StartPathProc(obj, func_80348B34_8282A4);
    pokemon->transitionGraph = D_8034AF3C_82A6AC;
    Pokemon_WaitForFlag(obj, 0);

    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_80348A04_828174)
    cmdSendCommand(gObjPlayer, PLAYER_CMD_9, NULL);
    auPlaySound(SOUND_ID_38);
    Pokemon_SetAnimation(obj, &D_8034AEE4_82A654);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED | POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED) {
        Pokemon_SetState(obj, func_80348DD4_828544);
    }
    auPlaySound(SOUND_ID_40);
    D_8034AF30_82A6A0 = auPlaySound(SOUND_ID_39);
    Pokemon_SetAnimation(obj, &D_8034AEF8_82A668);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED | POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED) {
        Pokemon_SetState(obj, func_80348DD4_828544);
    }
    Pokemon_SetAnimation(obj, &D_8034AF0C_82A67C);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED | POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED) {
        Pokemon_SetState(obj, func_80348DD4_828544);
    }
    Pokemon_SetState(obj, func_80348DD4_828544);
}

POKEMON_FUNC(func_80348B34_8282A4)
    while (position->v.z > 0.0f) {
        position->v.z -= 5.0f;
        ohWait(1);
    }
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_80348BDC_82834C(DObj* arg0, s32 arg1, f32 arg2) {
    if (arg1 == -2 || arg1 == -1) {
        D_8034AF34_82A6A4 = 1;
    }
}

POKEMON_FUNC(func_80348C08_828378)
    f32 fader;
    s32 i;
    u32 vol;

    f32 steps = 240;
    fader = 1.0f;

    for (i = 239; i > 0; i--) {
        fader += -1.0f / steps;
        vol = 32512.0f * fader;
        auSetBGMVolume(0, vol);
        auSetBGMVolume(1, vol);
        ohWait(1);
    }

    auSetBGMVolume(0, 0);
    auSetBGMVolume(1, 0);
    Pokemon_StopAuxProc(obj);
}

POKEMON_FUNC(func_80348D48_8284B8)
    s32 i;

    for (i = 0; i < 280; i++) {
        ohWait(1);
    }

    auPlaySound(SOUND_ID_41);

    if (D_8034AF30_82A6A0 != -1 && auPlayingSound[D_8034AF30_82A6A0] != -1) {
        auStopSound(D_8034AF30_82A6A0);
    }
    Pokemon_StopAuxProc(obj);
}

POKEMON_FUNC(func_80348DD4_828544)
    GObj* camObj;
    GObj* playerObj;
    OMCamera* cam;
    s32 i;
    Unks16 sp30;

    sp30 = D_8034AF5C_82A6CC;

    Pokemon_StartAuxProc(obj, func_80348C08_828378);
    Pokemon_StartAuxProc(obj, func_80348D48_8284B8);
    Items_RemoveFlyingItems();
    resetMainCameraSettings();
    Msg_Reset();
    Pokemon_RemovePokemons(&sp30);
    ohWait(1);
    Camera_StartCutScene(obj, NULL, 0.0f);
    if (D_8034AB94_82A304 != NULL) {
        ohResumeObjectProcesses(D_8034AB94_82A304);
    }
    D_8034AF38_82A6A8 = 1;
    cam = getMainCamera();
    camObj = cam->obj;
    ohPauseObjectProcesses(camObj);
    cam->animSpeed = 0.5f;
    animSetCameraAnimation(cam, &D_80119A8C_4CBE5C, 0.0f);
    omCreateProcess(camObj, animUpdateCameraAnimation, 1, 1);
    setSkyBoxAnimationSpeed(D_800F5DB0_4A8180);
    playerObj = PlayerModel_Init();
    if (playerObj == NULL) {
        cmdSendCommand(gObjPlayer, PLAYER_CMD_7, NULL);
        omEndProcess(NULL);
    }
    PlayerModel_SetAnimation(&D_801183E0_4CA7B0, &D_80119050_4CB420, 0.0f, 0.5f);
    D_8034AF34_82A6A4 = 0;
    playerObj->fnAnimCallback = func_80348BDC_82834C;

    for (i = 0; D_8034AF34_82A6A4 == 0 && i < 1200; i++) {
        ohWait(1);
    }

    auStopAllSounds();
    cmdSendCommand(gObjPlayer, PLAYER_CMD_FINISH, NULL);
    omEndProcess(NULL);
    Pokemon_SetState(obj, NULL);
}

GObj* func_80348FB8_828728(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnDlLink4(objID, id, block, blockB, spawn, &D_8034AF78_82A6E8);
}

s32 func_80348FF0_828760(Vec3f* arg0, Vec3f* arg1, Vec3f* arg2, Vec3f* arg3) {
    DObj* model;
    Mtx3Float* position;
    Mtx4Float* rotation;

    if (D_8034AF2C_82A69C == NULL) {
        return -1;
    }

    model = D_8034AF2C_82A69C->data.dobj;
    position = &GET_TRANSFORM(model)->pos;
    rotation = &GET_TRANSFORM(model)->rot;
    if (StaticObject_CollideOne(arg0, arg1, arg2, arg3, &D_8034AF20_82A690, position->v, rotation->v)) {
        return PokemonID_GATE;
    }
    return -1;
}

void func_80349084_8287F4(GObj* obj) {
    Pokemon* pokemon;
    DObj* model;
    GObj* pokemonObj;
    ObjectSpawn spawn;
    WorldBlock* block;
    PokemonDef def = D_8034AFAC_82A71C;

    block = getCurrentWorldBlock();
    spawn.id = PokemonID_GATE;
    spawn.translation.x = 0.0;
    spawn.translation.y = 0.0;
    spawn.translation.z = 0.0;
    spawn.euler.x = 0.0;
    spawn.euler.y = PI;
    spawn.euler.z = 0.0;
    spawn.scale.x = 1.0;
    spawn.scale.y = 1.0;
    spawn.scale.z = 1.0;

    pokemonObj = pokemonAddOne(block, block, &spawn, &def);
    D_8034AF2C_82A69C = pokemonObj;
    pokemon = GET_POKEMON(D_8034AB94_82A304);

    model = pokemonObj->data.dobj;
    GET_TRANSFORM(model)->pos.v.x = 0.0f;
    GET_TRANSFORM(model)->pos.v.y = 0.0f;
    GET_TRANSFORM(model)->pos.v.z = 10000.0f;
    InitOneCollisionModel(&D_8034AF20_82A690);
    Items_func_8035CA1C(&func_80348FF0_828760);
    omEndProcess(NULL);
}
