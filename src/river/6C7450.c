#include "common.h"
#include "world/world.h"
#include "app_level/app_level.h"
#include "river.h"

extern AnimationHeader D_802E4140_6CBF20;
extern AnimationHeader D_802E4154_6CBF34;
extern AnimationHeader D_802E4190_6CBF70;
extern AnimationHeader D_802E4208_6CBFE8;
extern GObj* D_802E4230_6CC010;
extern InteractionHandler D_802E4234_6CC014[];
extern InteractionHandler D_802E42A4_6CC084[];
extern InteractionHandler D_802E42C4_6CC0A4[];
extern InteractionHandler D_802E4314_6CC0F4[];
extern InteractionHandler D_802E4334_6CC114[];
extern PokemonInitData D_802E4378_6CC158;

void func_802DF7D8_6C75B8(GObj*);
void func_802DF6BC_6C749C(GObj*);
void func_802DF758_6C7538(GObj*);
void func_802DF91C_6C76FC(GObj*);
void func_802DF9CC_6C77AC(GObj*);
void func_802DFA30_6C7810(GObj*);
void func_802DFA5C_6C783C(GObj*);
void func_802DFB74_6C7954(GObj*);
void func_802DFC38_6C7A18(GObj*);
void func_802DFDF8_6C7BD8(GObj*);
void func_802DFE4C_6C7C2C(GObj*);

void func_802DF670_6C7450(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    if (pokemon->behavior == 7) {
        Pokemon_SetState(obj, func_802DFA30_6C7810);
    }
    Pokemon_SetState(obj, func_802DF6BC_6C749C);
}

void func_802DF6BC_6C749C(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->specialPoseID = 0;
    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_2 | GOBJ_FLAG_HIDDEN;
    pokemon->transitionGraph = D_802E42A4_6CC084;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

void func_802DF710_6C74F0(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->tangible = TRUE;
    obj->flags = 0;
    Pokemon_StartPathProc(obj, func_802DF7D8_6C75B8);
    Pokemon_SetState(obj, func_802DF758_6C7538);
}

void func_802DF758_6C7538(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->specialPoseID = 4;
    Pokemon_SetAnimation(obj, &D_802E4208_6CBFE8);
    pokemon->transitionGraph = D_802E4234_6CC014;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    cmdSendCommand(D_802E4230_6CC010, 0x29, obj);
    Pokemon_SetState(obj, func_802DF6BC_6C749C);
}

void func_802DF7D8_6C75B8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0, 1, 0.2f, 0.0f, MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802DF844_6C7624(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->specialPoseID = 0;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_SetAnimation(obj, &D_802E4190_6CBF70);
    pokemon->transitionGraph = D_802E4234_6CC014;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_SetState(obj, func_802DF758_6C7538);
}

void func_802DF8C4_6C76A4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->specialPoseID = 0;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_1000;
    Pokemon_StartAuxProc(obj, func_802DF9CC_6C77AC);
    Pokemon_SetState(obj, func_802DF91C_6C76FC);
}

POKEMON_FUNC(func_802DF91C_6C76FC)
    Pokemon_ForceAnimation(obj, &D_802E4154_6CBF34);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_1000 | POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    if (pokemon->processFlags & 1) {
        Pokemon_SetState(obj, func_802DF91C_6C76FC);
    }
    Pokemon_SetAnimation(obj, &D_802E4140_6CBF20);
    pokemon->transitionGraph = D_802E4234_6CC014;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_SetState(obj, func_802DF758_6C7538);
}

void func_802DF9CC_6C77AC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    while (true) {
        if (Pokemon_HearsPokeFlute(obj) == 0) {
            break;
        }
        ohWait(1);
    }
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_1000;
    Pokemon_StopAuxProc(obj);
}

void func_802DFA30_6C7810(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    D_802E4230_6CC010 = obj;
    Pokemon_SetState(obj, func_802DFA5C_6C783C);
}

void func_802DFA5C_6C783C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);
    s32 temp_t8;

    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_2 | GOBJ_FLAG_HIDDEN;
    temp_t8 = randRange(60) + 60;
    pokemon->counter = temp_t8, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_802E4314_6CC0F4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);
    pokemon->tangible = true;
    obj->flags = 0;
    Pokemon_ForceAnimation(obj, &D_802E4140_6CBF20);
    Pokemon_StartPathProc(obj, func_802DFB74_6C7954);
    pokemon->transitionGraph = D_802E42C4_6CC0A4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    pokemon->transitionGraph = D_802E42C4_6CC0A4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_ForceAnimation(obj, &D_802E4140_6CBF20);
    Pokemon_StartPathProc(obj, func_802DFC38_6C7A18);
    pokemon->transitionGraph = D_802E4314_6CC0F4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetState(obj, func_802DFA5C_6C783C);
}

void func_802DFB74_6C7954(GObj* obj) {
    DObj* model = obj->data.dobj;
    PokemonTransform* transform = GET_TRANSFORM(model);
    Mtx3Float* pos = &transform->pos;
    Pokemon* pokemon = GET_POKEMON(obj);
    UNUSED s32 pad[1];
    GroundResult sp30;
    s32 i = 20;

    getGroundAt(pos->v.x, pos->v.z, &sp30);
    pos->v.y = sp30.height - 50.0f;

    while (i--) {
        pos->v.y += 2.5;
        ohWait(1);
    }

    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802DFC38_6C7A18(GObj* obj) {
    DObj* model = obj->data.dobj;
    PokemonTransform* transform = GET_TRANSFORM(model);
    Mtx3Float* pos = &transform->pos;
    Pokemon* pokemon = GET_POKEMON(obj);
    UNUSED s32 pad[1];
    s32 i = 20;

    while (i--) {
        pos->v.y -= 5.0;
        ohWait(1);
    }
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    pokemon->pathProc = NULL;
    omEndProcess(NULL);
}

void func_802DFCD0_6C7AB0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E4190_6CBF70);
    Pokemon_StartPathProc(obj, func_802DFC38_6C7A18);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    cmdSendCommandToLink(3, 0x28, obj);
    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_2 | GOBJ_FLAG_HIDDEN;
    pokemon->transitionGraph = D_802E4334_6CC114;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

void func_802DFD78_6C7B58(GObj* obj) {
    DObj* model = obj->data.dobj;
    PokemonTransform* transform = GET_TRANSFORM(model);
    Mtx3Float* pos = &transform->pos;
    Pokemon* pokemon = GET_POKEMON(obj);
    GroundResult sp1C;

    getGroundAt(pos->v.x, pos->v.z, &sp1C);
    pos->v.y = sp1C.height;
    pokemon->tangible = true;
    obj->flags = 0;
    Pokemon_StartPathProc(obj, func_802DFE4C_6C7C2C);
    Pokemon_SetState(obj, func_802DFDF8_6C7BD8);
}

void func_802DFDF8_6C7BD8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_802E4140_6CBF20);
    pokemon->transitionGraph = 0;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802DFDF8_6C7BD8);
}

void func_802DFE4C_6C7C2C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon = obj->userData;
    ohWait(280);
    auPlaySoundWithParams(0x10A, 0x5800, 0x3C, 0.8f, 0x14);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

GObj* func_802DFEB0_6C7C90(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_Spawn(objID, id, block, blockB, spawn, &D_802E4378_6CC158);
}
