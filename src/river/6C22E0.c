#include "common.h"
#include "world/world.h"
#include "app_level/app_level.h"
#include "river.h"

extern AnimationHeader D_802E2E44_6CAC24;
extern InteractionHandler D_802E2E58_6CAC38[];
extern InteractionHandler D_802E2E88_6CAC68[];
extern PokemonInitData D_802E2EC4_6CACA4;

void func_802DA590_6C2370(GObj*);
void func_802DA620_6C2400(GObj*);
void func_802DA674_6C2454(GObj*);
void func_802DA73C_6C251C(GObj*);
void func_802DA814_6C25F4(GObj*);

void func_802DA500_6C22E0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    if (pokemon->behavior != 0) {
        Pokemon_SetState(obj, func_802DA814_6C25F4);
    }
    Pokemon_ForceAnimation(obj, &D_802E2E44_6CAC24);
    Pokemon_StartPathProc(obj, func_802DA590_6C2370);
    pokemon->transitionGraph = D_802E2E58_6CAC38;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetState(obj, func_802DA73C_6C251C);
}

void func_802DA590_6C2370(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_StartAuxProc(obj, func_802DA620_6C2400);
    Pokemon_StartAuxProc(obj, func_802DA674_6C2454);
    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0.0f, 1.0f, 0.06666667f, 0, 0);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802DA620_6C2400(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* model = obj->data.dobj;
    Mtx4Float* rotation = &GET_TRANSFORM(model)->rot;

    while (true) {
        rotation->v.y += PI / 90;
        ohWait(1);
    }
}

// clang-format off
void func_802DA674_6C2454(GObj* obj) { \
    Pokemon* pokemon = GET_POKEMON(obj);
    // clang-format on
    DObj* model = obj->data.dobj;
    PokemonTransform* transform = GET_TRANSFORM(model);

    while (1) {
        if (transform) {
            // TODO required to match
        }
        if (transform->pos.v.y > pokemon->currGround.height) {
            break;
        }
        ohWait(1);
    }
    EnvSound_PlaySound(obj, 1, 0x179);
    func_8035E1D4_4FE5E4(obj);

    while (1) {
        if (transform->pos.v.y < pokemon->currGround.height) {
            break;
        }
        ohWait(1);
    }
    EnvSound_PlaySound(obj, 1, 0x17C);
    func_8035E1D4_4FE5E4(obj);

    Pokemon_StopAuxProc(obj);
}

void func_802DA73C_6C251C(GObj* obj) {
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

void func_802DA768_6C2548(GObj* obj) {
    f32 var_f20;
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* model = obj->data.dobj;
    Mtx4Float* rot = &GET_TRANSFORM(model)->rot;

    var_f20 = 60.0f;
    while (var_f20-- != 0.0f) {
        rot->v.y += PI / 30;
        ohWait(1);
    }
    Pokemon_StopAuxProc(obj);
}

void func_802DA814_6C25F4(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    HIDE_POKEMON();
    pokemon->transitionGraph = D_802E2E88_6CAC68;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

void func_802DA864_6C2644(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    SHOW_POKEMON();
    Pokemon_StartPathProc(obj, func_802DA590_6C2370);
    pokemon->transitionGraph = D_802E2E58_6CAC38;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetState(obj, func_802DA73C_6C251C);
}

GObj* func_802DA8CC_6C26AC(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802E2EC4_6CACA4);
}
