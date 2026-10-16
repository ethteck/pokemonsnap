#include "common.h"
#include "beach.h"

extern AnimCmd* D_800FAE40_78260[];
extern AnimCmd* D_800FBF50_79370[];
extern AnimCmd* D_800FDC70_7B090[];
extern AnimCmd* D_800FD080_7A4A0[];
extern UnkEC64Arg3 magikarp_model[];

s32 D_beach_802CDA50[] = { SOUND_ID_211 };
s32 D_beach_802CDA54[] = { SOUND_ID_210, SOUND_ID_376, SOUND_ID_114 };
s32 D_beach_802CDA60[] = { SOUND_ID_211, SOUND_ID_376, SOUND_ID_114 };
s32 D_beach_802CDA6C[] = { 0, SOUND_ID_376, SOUND_ID_114 };

AnimationHeader D_beach_802CDA78 = {
    0.5f,
    60.0f,
    D_800FDC70_7B090,
    NULL,
    D_beach_802CDA50
};

AnimationHeader D_beach_802CDA8C = {
    0.5f,
    65.0f,
    D_800FAE40_78260,
    NULL,
    D_beach_802CDA54
};

AnimationHeader D_beach_802CDAA0 = {
    0.5f,
    59.0f,
    D_800FBF50_79370,
    NULL,
    D_beach_802CDA60
};

AnimationHeader D_beach_802CDAB4 = {
    0.5f,
    50.0f,
    D_800FD080_7A4A0,
    NULL,
    D_beach_802CDA6C
};

InteractionHandler D_beach_802CDAC8[] = {
    { POKEMON_CMD_58, NULL, 0.0f, NULL },
};

PokemonAnimationSetup D_beach_802CDAD8 = {
    &D_beach_802CDA8C,
    func_beach_802CAB50,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData D_beach_802CDAEC = {
    magikarp_model,
    NULL,
    renderPokemonModelTypeBFogged,
    &D_beach_802CDAD8,
    { 1.6f, 1.6f, 1.6f },
    { 0.0f, -40.0f, -11.0f },
    35.0f,
    POKEMON_FLAG_20 | POKEMON_FLAG_4 | POKEMON_FLAG_1,
    0,
    0,
    0,
    { 0, 0, 0 }
};

void func_beach_802CAB50(GObj* obj) {
    UNUSED s32 pad[1];
    DObj* model = obj->data.dobj;
    Mtx4Float* rotation = &GET_TRANSFORM(model)->rot;
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_beach_802CDAB4);
    rotation->v.y = randRange(360) * PI / 180.0f;
    Pokemon_StartPathProc(obj, func_beach_802CAC08);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    D_beach_802CC014 = false;
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

void func_beach_802CAC08(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    func_8035E298_4FE6A8(obj);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_beach_802CAC48(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    Pokemon_SpawnOnGround(gObjID, id, roomA, roomB, spawn, &D_beach_802CDAEC);
}

// TODO: potential file split. Pokemon_SpawnOnGround tends to be used at the end of files

void func_beach_802CAC80(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->flags |= POKEMON_FLAG_200;
    pokemon->flags |= POKEMON_FLAG_800;
    pokemon->transitionGraph = D_beach_802CDC60;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

void func_beach_802CACD4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    if (pokemon->behavior == 1) {
        Pokemon_SetState(obj, func_beach_802CAD58);
    }

    if (pokemon->behavior == 4) {
        Pokemon_SetState(obj, func_beach_802CB2D8);
    }
    Pokemon_SetState(obj, func_beach_802CAC80);
    Pokemon_SetState(obj, NULL);
}

void func_beach_802CAD58(GObj* obj) {
    Pokemon_SetState(obj, func_beach_802CAD7C);
}

void func_beach_802CAD7C(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    HIDE_POKEMON();
    pokemon->transitionGraph = D_beach_802CDC80;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

void func_beach_802CADCC(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    SHOW_POKEMON();
    Pokemon_StartPathProc(obj, func_beach_802CAEB0);
    Pokemon_SetState(obj, func_beach_802CAE14);
}

void func_beach_802CAE14(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    SHOW_POKEMON();
    Pokemon_SetAnimation(obj, &D_beach_802CDBAC);
    pokemon->transitionGraph = D_beach_802CDCA0;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    pokemon->specialPoseID = 5;
    Pokemon_SetAnimation(obj, &D_beach_802CDBFC);
    pokemon->transitionGraph = D_beach_802CDCA0;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_beach_802CAF90);
}

void func_beach_802CAEB0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0, 1, 0.033333335f, 0.0f, MOVEMENT_FLAG_UPDATE_TARGET_POS | MOVEMENT_FLAG_ON_GROUND);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(0);
}

void func_beach_802CAF1C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->processFlags |= POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_SetAnimation(obj, &D_beach_802CDBC0);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_SetState(obj, func_beach_802CAE14);
}
