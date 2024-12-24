#include "rainbow.h"

typedef struct Unks16 {
    /* 0x00 */ s16 unk_00[3];
} Unks16;

extern AnimCmd D_80119A8C;
extern f32 D_800F5DB0;
extern AnimCmd* D_801183E0;
extern AnimCmd** D_80119050;

void func_80348994_828104(GObj*);
void func_80348B34_8282A4(GObj*);
void func_80348DD4_828544(GObj*);
void func_80349084_8287F4(GObj*);

extern AnimationHeader D_8034AED0_82A640;
extern AnimationHeader D_8034AEE4_82A654;
extern AnimationHeader D_8034AEF8_82A668;
extern AnimationHeader D_8034AF0C_82A67C;
extern CollisionModel D_8034AF20_82A690;
extern GObj* D_8034AF2C_82A69C;
extern s32 D_8034AF30_82A6A0;
extern s32 D_8034AF34_82A6A4;
extern InteractionHandler D_8034AF3C_82A6AC[];
extern Unks16 D_8034AF5C_82A6CC;
extern PokemonInitData D_8034AF78_82A6E8;
extern PokemonDef D_8034AFAC_82A71C;

void func_80348970_8280E0(GObj* obj) {
    Pokemon_SetState(obj, func_80348994_828104);
}

void func_80348994_828104(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_8034AED0_82A640);
    Pokemon_StartPathProc(obj, func_80348B34_8282A4);
    pokemon->transitionGraph = D_8034AF3C_82A6AC;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

// clang-format off
void func_80348A04_828174(GObj* obj) { \
    UNUSED s32 pad[3]; \
    Pokemon* pokemon = GET_POKEMON(obj);
    // clang-format on

    cmdSendCommand(gObjPlayer, 9, NULL);
    auPlaySound(0x26);
    Pokemon_SetAnimation(obj, &D_8034AEE4_82A654);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED | POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED) {
        Pokemon_SetState(obj, func_80348DD4_828544);
    }
    auPlaySound(0x28);
    D_8034AF30_82A6A0 = auPlaySound(0x27);
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

void func_80348B34_8282A4(GObj* obj) {
    UNUSED s32 pad[2];
    DObj* dobj = obj->data.dobj;
    Pokemon* pokemon = GET_POKEMON(obj);
    PokemonTransform* transform = GET_TRANSFORM(dobj);

    while (transform->pos.v.z > 0.0f) {
        transform->pos.v.z -= 5.0f;
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

void func_80348C08_828378(GObj* obj) {
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

void func_80348D48_8284B8(GObj* obj) {
    s32 i;

    for (i = 0; i < 280; i++) {
        ohWait(1);
    }

    auPlaySound(0x29);

    if (D_8034AF30_82A6A0 != -1 && auPlayingSound[D_8034AF30_82A6A0] != -1) {
        auStopSound(D_8034AF30_82A6A0);
    }
    Pokemon_StopAuxProc(obj);
}

void func_80348DD4_828544(GObj* obj) {
    UNUSED s32 pad[4];
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
    animSetCameraAnimation(cam, &D_80119A8C, 0.0f);
    omCreateProcess(camObj, animUpdateCameraAnimation, 1U, 1U);
    setSkyBoxAnimationSpeed(D_800F5DB0);
    playerObj = PlayerModel_Init();
    if (playerObj == NULL) {
        cmdSendCommand(gObjPlayer, 7, NULL);
        omEndProcess(NULL);
    }
    PlayerModel_SetAnimation(&D_801183E0, &D_80119050, 0.0f, 0.5f);
    D_8034AF34_82A6A4 = 0;
    playerObj->fnAnimCallback = func_80348BDC_82834C;

    for (i = 0; D_8034AF34_82A6A4 == 0 && i < 1200; i++) {
        ohWait(1);
    }

    auStopAllSounds();
    cmdSendCommand(gObjPlayer, 6, NULL);
    omEndProcess(NULL);
    Pokemon_SetState(obj, NULL);
}

GObj* func_80348FB8_828728(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnDlLink4(objID, id, block, blockB, spawn, &D_8034AF78_82A6E8);
}

// TODO needs Mtx4Float to have a vec3f
#ifdef NON_MATCHING
s32 func_80348FF0_828760(Vec3f* arg0, Vec3f* arg1, Vec3f* arg2, Vec3f* arg3) {
    PokemonTransform* temp_v0;
    Mtx3Float* temp_t0;
    Mtx3Float* temp_t1;

    if (D_8034AF2C_82A69C == NULL) {
        return -1;
    }
    temp_v0 = GET_TRANSFORM(D_8034AF2C_82A69C->data.dobj);
    temp_t1 = &GET_TRANSFORM(D_8034AF2C_82A69C->data.dobj)->rot;
    if (StaticObject_CollideOne(arg0, arg1, arg2, arg3, &D_8034AF20_82A690, temp_v0->pos.v, temp_t1->v)) {
        return PokemonID_GATE;
    }
    return -1;
}
#else
s32 func_80348FF0_828760(Vec3f* arg0, Vec3f* arg1, Vec3f* arg2, Vec3f* arg3);
#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/8280E0/func_80348FF0_828760.s")
#endif

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
