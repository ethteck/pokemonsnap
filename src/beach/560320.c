#include "common.h"
#include "beach.h"

extern u8 D_80159E60_E62F0[];
extern u8 D_8015BC10_E80A0[];
extern u8 D_8015CBC0_E9050[];
extern u8 D_8015EBA0_EB030[];
extern u8 D_8015FD10_EC1A0[];
extern u8 D_801617D0_EDC60[];
extern u8 D_beach_802CCE90[];
extern u8 D_beach_802CCE9C[];
extern u8 D_beach_802CCEA0[];
extern u8 doduo_materials[];
extern u8 doduo_model[];
void func_beach_802C82B0(GObj*);
void func_beach_802C8354(GObj*);
void func_beach_802C84A4(GObj*);
extern PokemonAnimationSetup D_beach_802CCF64;

// .data
AnimationHeader D_beach_802CCEB0 = { 1.0f, 80.0f, (AnimCmd**) &D_80159E60_E62F0, NULL, (s32*) &D_beach_802CCE90 };
AnimationHeader D_beach_802CCEC4 = { 1.0f, 120.0f, (AnimCmd**) &D_8015EBA0_EB030, NULL, (s32*) &D_beach_802CCE9C };
AnimationHeader D_beach_802CCED8 = { 0.5f, 65.0f, (AnimCmd**) &D_8015BC10_E80A0, (AnimCmd***) &D_801617D0_EDC60, NULL };
AnimationHeader D_beach_802CCEEC = { 1.0f, 136.0f, (AnimCmd**) &D_8015CBC0_E9050, NULL, NULL };
AnimationHeader D_beach_802CCF00 = { 1.0f, 72.0f, (AnimCmd**) &D_8015FD10_EC1A0, NULL, (s32*) &D_beach_802CCEA0 };

InteractionHandler D_beach_802CCF14[3] = {
    { 9, (GObjFunc) func_beach_802C84A4, 0.0f, NULL },
    { 13, (GObjFunc) func_beach_802C84A4, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

InteractionHandler D_beach_802CCF44[2] = {
    { 16, (GObjFunc) func_beach_802C8354, 1000.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

PokemonAnimationSetup D_beach_802CCF64 = { (AnimationHeader*) &D_beach_802CCEB0, (GObjFunc) func_beach_802C82B0, 0, "", NULL, NULL };
PokemonInitData D_beach_802CCF78 = { (UnkEC64Arg3*) &doduo_model, (Texture***) &doduo_materials, (GObjFunc) renderPokemonModelTypeBFogged, (PokemonAnimationSetup*) &D_beach_802CCF64, { 2.0f, 2.0f, 2.0f }, { 0.0f, 300.0f, 0.0f }, 40.0f, 37, 0, 0, 0, "" };
u32 D_beach_802CCFAC = 0x00000000;

u32 D_beach_802CCFB0[] = {
    0x00000100, 0x0000007C,
};

u32 D_beach_802CCFB8[] = {
    0x00000101, 0x0000007C,
};

void func_beach_802C82B0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    obj->flags |= GOBJ_FLAG_HIDDEN;
    Pokemon_StartPathProc(obj, func_beach_802C8438);
    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    pokemon->transitionGraph = D_beach_802CCF44;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

void func_beach_802C8354(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->flags |= POKEMON_FLAG_200;
    obj->flags = 0;
    pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_SetAnimation(obj, &D_beach_802CCF00);
    pokemon->transitionGraph = D_beach_802CCF14;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_beach_802C83D0);
}

void func_beach_802C83D0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_beach_802CCEB0);
    pokemon->transitionGraph = D_beach_802CCF14;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, 0);
}

void func_beach_802C8438(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0, 1.0f, 0.1f, 0.0f, MOVEMENT_FLAG_UPDATE_TARGET_POS | MOVEMENT_FLAG_ON_GROUND);
    pokemon->pathProc = 0;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(0);
}

void func_beach_802C84A4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->processFlags |= POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_SetAnimation(obj, &D_beach_802CCEC4);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_beach_802CCED8);
    pokemon->counter = 120, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);
    Pokemon_SetAnimation(obj, &D_beach_802CCEEC);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_SetState(obj, func_beach_802C83D0);
}

void func_beach_802C8570(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    Pokemon_SpawnOnGround(gObjID, id, roomA, roomB, spawn, &D_beach_802CCF78);
}
