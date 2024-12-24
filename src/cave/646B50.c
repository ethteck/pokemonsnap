#include "common.h"

#include "world/world.h"
#include "app_level/app_level.h"
#include "cave.h"

extern AnimationHeader D_802C7B10_649FC0;
extern AnimationHeader D_802C7B24_649FD4;
extern AnimationHeader D_802C7B38_649FE8;
extern GObj* D_802C7B4C_649FFC;
extern InteractionHandler D_802C7B50_64A000[];
extern PokemonInitData D_802C7B9C_64A04C;

void func_802C4820_646CD0(GObj*);
void func_802C493C_646DEC(GObj*);

void func_802C46A0_646B50(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    HIDE_POKEMON();
    pokemon->transitionGraph = D_802C7B50_64A000;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

void func_802C46F0_646BA0(GObj* obj) {
    DObj* dobj = obj->data.dobj;
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* interactionTarget;

    interactionTarget = pokemon->interactionTarget->data.dobj;
    GET_TRANSFORM(dobj)->pos.v.x = GET_TRANSFORM(interactionTarget)->pos.v.x;
    GET_TRANSFORM(dobj)->pos.v.y = GET_TRANSFORM(interactionTarget)->pos.v.y;
    GET_TRANSFORM(dobj)->pos.v.z = GET_TRANSFORM(interactionTarget)->pos.v.z;
    D_8033E138_6C05E8.unk_01_2 = true;
    SHOW_POKEMON();
    Pokemon_ForceAnimation(obj, &D_802C7B10_649FC0);
    Pokemon_TurnToTarget(obj, 1.0f, 0x20);
    Pokemon_StartPathProc(obj, func_802C4820_646CD0);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_802C7B38_649FE8);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_802C7B24_649FD4);
    Pokemon_StartPathProc(obj, func_802C493C_646DEC);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    D_802C7B4C_649FFC = NULL;
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

void func_802C4820_646CD0(GObj* obj) {
    DObj* dobj = obj->data.dobj;
    Pokemon* pokemon = GET_POKEMON(obj);
    PokemonTransform* playerTransform;
    PokemonTransform* objTransform;
    f32 temp_f0;
    f32 var_f20;

    var_f20 = 500.0f;

    playerTransform = GET_TRANSFORM(gPlayerDObj);
    objTransform = GET_TRANSFORM(dobj);
    pokemon->pos1.x = objTransform->pos.v.x;
    pokemon->pos1.z = objTransform->pos.v.z;

    while (var_f20 > 0.0f) {
        temp_f0 = atan2f(pokemon->pos1.x - playerTransform->pos.v.x, pokemon->pos1.z - playerTransform->pos.v.z);
        objTransform->pos.v.x = (__sinf(temp_f0) * var_f20) + pokemon->pos1.x;
        objTransform->pos.v.z = (__cosf(temp_f0) * var_f20) + pokemon->pos1.z;
        var_f20 -= 16.666666f;
        ohWait(1);
    }

    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802C493C_646DEC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0, 1, 0.075f, 0.0f, MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

GObj* func_802C49A8_646E58(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    D_802C7B4C_649FFC = Pokemon_Spawn(gObjID, id, roomA, roomB, spawn, &D_802C7B9C_64A04C);

    return D_802C7B4C_649FFC;
}
