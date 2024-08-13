#include "volcano/volcano.h"

extern UnkEC64Arg3 D_801140C0[];
extern Texture** D_80114150[];

extern AnimCmd* D_80114210[];
extern AnimCmd* D_80114280[];
extern AnimCmd* D_80114300[];

extern AnimCmd** D_80114240[];
extern AnimCmd** D_801142C0[];
extern AnimCmd** D_80114330[];

void func_802DE3FC_72F5FC(GObj* obj);
void func_802DE450_72F650(GObj* obj);
void func_802DE4C0_72F6C0(GObj* obj);
void func_802DE390_72F590(GObj*);

s32 D_802E31F0_7343F0[] = { SOUND_ID_61 };

AnimationHeader D_802E31F4_7343F4 = {
    1.0,
    100,
    D_80114210,
    D_80114240,
    NULL
};

AnimationHeader D_802E3208_734408 = {
    1.0,
    100,
    D_80114280,
    D_801142C0,
    D_802E31F0_7343F0
};

AnimationHeader D_802E321C_73441C = {
    1.0,
    100,
    D_80114300,
    D_80114330,
    NULL
};

InteractionHandler D_802E3230_734430[] = {
    { POKEMON_CMD_58, NULL, 0, NULL },
};

PokemonAnimationSetup D_802E3240_734440 = {
    &D_802E31F4_7343F4,
    func_802DE390_72F590,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData koffingSmokeData = {
    D_801140C0,
    D_80114150,
    renderPokemonModelTypeDFogged,
    &D_802E3240_734440,
    { 30, 30, 30 },
    { 0, 0, 0 },
    0,
    POKEMON_FLAG_4,
    0,
    0,
    0,
    { 0, 0, 0 }
};

void func_802DE390_72F590(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_802E31F4_7343F4);
    Pokemon_StartPathProc(obj, func_802DE4C0_72F6C0);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_802DE3FC_72F5FC);
}

void func_802DE3FC_72F5FC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_802E3208_734408);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_802DE450_72F650);
}

void func_802DE450_72F650(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E321C_73441C);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    cmdSendCommandToLink(LINK_POKEMON, POKEMON_CMD_33, obj);
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

void func_802DE4C0_72F6C0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0, 1, 0.05f, 0.0f, MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

GObj* func_802DE52C_72F72C(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    return Pokemon_Spawn(gObjID, id, roomA, roomB, spawn, &koffingSmokeData);
}
