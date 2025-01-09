#include "common.h"
#include "world/world.h"
#include "app_level/app_level.h"
#include "river.h"

extern RandomState D_802E3048_6CAE28[];
extern PokemonInitData D_802E3074_6CAE54;
extern PokemonInitData D_802E312C_6CAF0C;

extern PokemonDef D_802E3008_6CADE8;
extern PokemonDef D_802E3018_6CADF8;
extern InteractionHandler D_802E3028_6CAE08[];
extern AnimationHeader D_802E30CC_6CAEAC;
extern InteractionHandler D_802E30E0_6CAEC0[];

void func_802DADD8_6C2BB8(GObj*);
void func_802DAE68_6C2C48(GObj*);
void func_802DAED4_6C2CB4(GObj*);

void func_802DA9E0_6C27C0(GObj* obj) {
    DObj* model;
    Mtx3Float* position;
    GObj* pokemonObj;
    ObjectSpawn spawn;
    WorldBlock* block;
    Pokemon* pokemon = GET_POKEMON(obj);
    PokemonDef def = D_802E3008_6CADE8;

    block = getCurrentWorldBlock();
    spawn.id = PokemonID_SHELLDER;
    spawn.translation.x = 0.0;
    spawn.translation.y = 0.0;
    spawn.translation.z = 0.0;
    spawn.euler.x = 0.0;
    spawn.euler.y = 0.0;
    spawn.euler.z = 0.0;
    spawn.scale.x = 1.0;
    spawn.scale.y = 1.0;
    spawn.scale.z = 1.0;
    spawn.path = pokemon->path;

    pokemonObj = pokemonAddOne(block, block, &spawn, &def);

    position = &GET_TRANSFORM(obj->data.dobj)->pos;
    model = pokemonObj->data.dobj;
    GET_TRANSFORM(model)->pos.v.x = position->v.x;
    GET_TRANSFORM(model)->pos.v.y = position->v.y;
    GET_TRANSFORM(model)->pos.v.z = position->v.z;
    omEndProcess(NULL);
}

void func_802DAACC_6C28AC(GObj* obj) {
    DObj* model;
    Mtx3Float* position;
    GObj* pokemonObj;
    ObjectSpawn spawn;
    WorldBlock* block;
    Pokemon* pokemon = GET_POKEMON(obj);
    PokemonDef def = D_802E3018_6CADF8;

    block = getCurrentWorldBlock();
    spawn.id = PokemonID_CLOYSTER;
    spawn.translation.x = 0.0;
    spawn.translation.y = 0.0;
    spawn.translation.z = 0.0;
    spawn.euler.x = 0.0;
    spawn.euler.y = 0.0;
    spawn.euler.z = 0.0;
    spawn.scale.x = 1.0;
    spawn.scale.y = 1.0;
    spawn.scale.z = 1.0;
    spawn.path = pokemon->path;

    pokemonObj = pokemonAddOne(block, block, &spawn, &def);

    position = &GET_TRANSFORM(obj->data.dobj)->pos;
    model = pokemonObj->data.dobj;
    GET_TRANSFORM(model)->pos.v.x = position->v.x;
    GET_TRANSFORM(model)->pos.v.y = position->v.y;
    GET_TRANSFORM(model)->pos.v.z = position->v.z;
    omEndProcess(NULL);
}

void func_802DABB8_6C2998(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    obj->flags |= GOBJ_FLAG_HIDDEN;
    pokemon->transitionGraph = D_802E3028_6CAE08;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

void func_802DAC04_6C29E4(GObj* obj) {
    Pokemon_SetStateRandom(obj, D_802E3048_6CAE28);
}

void func_802DAC28_6C2A08(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    omCreateProcess(obj, func_802DA9E0_6C27C0, 1, 1);
    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

void func_802DACA8_6C2A88(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    omCreateProcess(obj, func_802DAACC_6C28AC, 1, 1);
    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

GObj* func_802DAD28_6C2B08(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnDlLink4(objID, id, block, blockB, spawn, &D_802E3074_6CAE54);
}

void func_802DAD60_6C2B40(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_802E30CC_6CAEAC);
    Pokemon_StartPathProc(obj, func_802DADD8_6C2BB8);
    pokemon->transitionGraph = D_802E30E0_6CAEC0;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

void func_802DADD8_6C2BB8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_StartAuxProc(obj, func_802DAE68_6C2C48);
    Pokemon_StartAuxProc(obj, func_802DAED4_6C2CB4);
    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0.0f, 1.0f, 0.06666667f, 0, 0);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802DAE68_6C2C48(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* model = obj->data.dobj;
    Mtx4Float* rotation = &GET_TRANSFORM(model)->rot;

    while (true) {
        rotation->v.y += PI / 60;
        ohWait(1);
    }
}

// clang-format off
void func_802DAED4_6C2CB4(GObj* obj) { \
    DObj* model = obj->data.dobj; \
    Mtx3Float* pos = &GET_TRANSFORM(model)->pos; \
    Pokemon* pokemon = GET_POKEMON(obj);
    // clang-format on

    while (true) {
        if (pokemon->currGround.height < pos->v.y + 180.0f) {
            break;
        }
        ohWait(1);
    }

    EnvSound_PlaySound(obj, 1, 0x179);
    func_8035E1D4_4FE5E4(obj);
    ohWait(180);

    while (true) {
        if (pos->v.y < pokemon->currGround.height) {
            break;
        }
        ohWait(1);
    }

    EnvSound_PlaySound(obj, 1, 0x17C);
    func_8035E1D4_4FE5E4(obj);
    Pokemon_StopAuxProc(obj);
}

void func_802DAFB8_6C2D98(GObj* obj) {
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

GObj* func_802DB064_6C2E44(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802E312C_6CAF0C);
}
