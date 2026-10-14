#include "../rainbow.h"


void func_80349F88_8296F8(GObj*);

extern u8 D_800F5490_72C40[];
extern u8 evolution_controller_matanim[];
extern u8 evolution_controller_materials[];
extern u8 evolution_controller_modelanim[];
void func_80349F00_829670(GObj*);
extern PokemonAnimationSetup D_8034B5A4_82AD14;

// .data
AnimationHeader D_8034B590_82AD00 = { 0.5f, 60.0f, (AnimCmd**) &evolution_controller_modelanim, (AnimCmd***) &evolution_controller_matanim, NULL };
PokemonAnimationSetup D_8034B5A4_82AD14 = { (AnimationHeader*) &D_8034B590_82AD00, (GObjFunc) func_80349F00_829670, 0, "", NULL, NULL };
PokemonInitData D_8034B5B8_82AD28 = { (UnkEC64Arg3*) &D_800F5490_72C40, (Texture***) &evolution_controller_materials, (GObjFunc) renderPokemonModelTypeDFogged, (PokemonAnimationSetup*) &D_8034B5A4_82AD14, { 10.0f, 10.0f, 10.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f, 0, 0, 0, 0, "" };
PokemonDef D_8034B5EC_82AD5C = { 0x3EA, (pokemonInit) func_8034A064_8297D4, (void (*)(GObj*, f32, f32, f32, f32, f32, f32)) pokemonChangeBlock, (void (*)(GObj*)) pokemonRemoveOne };

POKEMON_FUNC(func_80349F00_829670)
    cmdSendCommand(gObjPlayer, PLAYER_CMD_SHAKE_CAMERA, obj);
    Pokemon_ForceAnimation(obj, &D_8034B590_82AD00);
    Pokemon_StartPathProc(obj, func_80349F88_8296F8);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_80349F88_8296F8)
    Mtx3Float* scale = &GET_TRANSFORM(model)->scale;

    while (true) {
        Pokemon_TurnToTarget(obj, TAU, MOVEMENT_FLAG_TURN_TO_PLAYER);
        scale->v.x *= 1.1;
        scale->v.y *= 1.1;
        scale->v.z *= 1.1;
        rotation->v.y += 3.0f;
        ohWait(1);
    }
}

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
