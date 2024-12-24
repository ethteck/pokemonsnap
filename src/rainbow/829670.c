#include "common.h"
#include "../world/world.h"
#include "app_level/app_level.h"
#include "rainbow.h"

extern PokemonInitData D_8034B5B8_82AD28;
extern PokemonDef D_8034B5EC_82AD5C;
extern AnimationHeader D_8034B590_82AD00;

void func_80349F88_8296F8(GObj*);

void func_80349F00_829670(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    cmdSendCommand(gObjPlayer, 3, obj);
    Pokemon_ForceAnimation(obj, &D_8034B590_82AD00);
    Pokemon_StartPathProc(obj, func_80349F88_8296F8);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/829670/func_80349F88_8296F8.s")

GObj* func_8034A064_8297D4(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnDlLink4(objID, id, block, blockB, spawn, &D_8034B5B8_82AD28);
}

void func_8034A09C_82980C(GObj* obj) {
    DObj* model;
    GObj* pokemonObj;
    WorldBlock* block;
    ObjectSpawn spawn;
    Mtx3Float* position;
    PokemonDef def = D_8034B5EC_82AD5C;

    block = getCurrentWorldBlock();
    spawn.id = PokemonID_EVOLUTION_CONTROLLER;
    spawn.translation.x = 0.0;
    spawn.translation.y = 0.0;
    spawn.translation.z = 0.0;
    spawn.euler.x = 0.0;
    spawn.euler.y = 0.0;
    spawn.euler.z = 0.0;
    spawn.scale.x = 1.0;
    spawn.scale.y = 1.0;
    spawn.scale.z = 1.0;

    pokemonObj = pokemonAddOne(block, block, &spawn, &def);
    position = &GET_TRANSFORM(obj->data.dobj)->pos;
    model = pokemonObj->data.dobj;
    GET_TRANSFORM(model)->pos.v.x = position->v.x;
    GET_TRANSFORM(model)->pos.v.y = position->v.y;
    GET_TRANSFORM(model)->pos.v.z = position->v.z;
    GET_TRANSFORM(model)->rot.v.x = 90.0f;
    omEndProcess(NULL);
}
