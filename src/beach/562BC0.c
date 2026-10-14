#include "common.h"
#include "beach.h"

extern u8 D_800FD080_7A4A0[];
extern u8 D_beach_802CDA60[];
extern u8 D_beach_802CDA6C[];
extern u8 D_beach_802CDA8C[];
void func_beach_802CAB50(GObj*);
extern PokemonAnimationSetup D_beach_802CDAD8;

// .data
u32 D_beach_802CDAB0 = (u32) &D_beach_802CDA60;
AnimationHeader D_beach_802CDAB4 = { 0.5f, 50.0f, (AnimCmd**) &D_800FD080_7A4A0, NULL, (s32*) &D_beach_802CDA6C };

u32 D_beach_802CDAC8[] = {
    0x0000003A, 0x00000000, 0x00000000, 0x00000000,
};

PokemonAnimationSetup D_beach_802CDAD8 = { (AnimationHeader*) &D_beach_802CDA8C, (GObjFunc) func_beach_802CAB50, 0, "", NULL, NULL };
PokemonInitData D_beach_802CDAEC = { (UnkEC64Arg3*) ((u8*) &D_beach_802CE0DC + 0x81DDC), NULL, (GObjFunc) renderPokemonModelTypeBFogged, (PokemonAnimationSetup*) &D_beach_802CDAD8, { 1.6f, 1.6f, 1.6f }, { 0.0f, -40.0f, -11.0f }, 35.0f, 37, 0, 0, 0, "" };
u32 D_beach_802CDB20 = 0x0000010A;

u32 D_beach_802CDB24[] = {
    0x00000108, 0x0000007F, 0x00000168,
};

u32 D_beach_802CDB30 = 0x00000107;

u32 D_beach_802CDB34[] = {
    0x00000109, 0x00000173,
};

u32 D_beach_802CDB3C[] = {
    0x0000010B, 0x0000010C,
};

u32 D_beach_802CDB44 = 0x00000162;

u32 D_beach_802CDB48[] = {
    0x00000000, 0x0000008A,
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
