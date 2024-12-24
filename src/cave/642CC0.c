#include "common.h"
#include "world/world.h"
#include "app_level/app_level.h"
#include "cave.h"

extern AnimationHeader D_802C6F60_649410;
extern AnimationHeader D_802C6F74_649424;
extern AnimationHeader D_802C6F88_649438;
extern AnimationHeader D_802C6F9C_64944C;
extern AnimationHeader D_802C6FB0_649460;
extern PokemonDef D_802C6FC4_649474;
extern InteractionHandler D_802C6FD4_649484[];
extern RandomState D_802C7014_6494C4;
extern PokemonInitData D_802C7040_6494F0;
extern AnimationHeader D_802C708C_64953C;
extern AnimationHeader D_802C70A0_649550;
extern AnimationHeader D_802C70B4_649564;
extern AnimationHeader D_802C70C8_649578;
extern AnimationHeader D_802C70DC_64958C;
extern InteractionHandler D_802C70F0_6495A0[];
extern RandomState D_802C7120_6495D0;
extern PokemonInitData D_802C714C_6495FC;
extern PokemonInitData D_802C7194_649644;

void func_802C0960_642E10(GObj*);
void func_802C09C4_642E74(GObj*);
void func_802C0A28_642ED8(GObj*);
void func_802C0A8C_642F3C(GObj*);
void func_802C0AF0_642FA0(GObj*);
void func_802C0CD8_643188(GObj*);
void func_802C0E28_6432D8(GObj*);
void func_802C0F30_6433E0(GObj*);
void func_802C1178_643628(GObj*);
void func_802C1288_643738(GObj*);

void evolveIntoMuk(GObj* obj) {
    GObj* muk;
    PokemonDef def = D_802C6FC4_649474;

    muk = Pokemon_AddAtGeo(obj, PokemonID_MUK, &def);

    GET_TRANSFORM(muk->data.dobj)->rot.v.y = GET_TRANSFORM(obj->data.dobj)->rot.v.y;
    omEndProcess(NULL);
}

void func_802C0888_642D38(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->miscVars[1].field1 = 0;
    pokemon->miscVars[0].field1 = 0;
    HIDE_POKEMON();

    if (pokemon->behavior == 3) {
        Pokemon_SetState(obj, func_802C0960_642E10);
    }
    if (pokemon->behavior == 4) {
        Pokemon_SetState(obj, func_802C09C4_642E74);
    }
    if (pokemon->behavior == 5) {
        Pokemon_SetState(obj, func_802C0A28_642ED8);
    }
    if (pokemon->behavior == 6) {
        Pokemon_SetState(obj, func_802C0A8C_642F3C);
    }
    Pokemon_SetState(obj, func_802C0AF0_642FA0);
}

void func_802C0960_642E10(GObj* obj) {
    while (!(D_8033E138_6C05E8.unk_00_3)) {
        ohWait(1);
    }
    Pokemon_SetState(obj, func_802C0AF0_642FA0);
}

void func_802C09C4_642E74(GObj* obj) {
    while (!(D_8033E138_6C05E8.unk_00_4)) {
        ohWait(1);
    }
    Pokemon_SetState(obj, func_802C0AF0_642FA0);
}

void func_802C0A28_642ED8(GObj* obj) {
    while (!(D_8033E138_6C05E8.unk_00_5)) {
        ohWait(1);
    }
    Pokemon_SetState(obj, func_802C0AF0_642FA0);
}

void func_802C0A8C_642F3C(GObj* obj) {
    while (!(D_8033E138_6C05E8.unk_00_6)) {
        ohWait(1);
    }
    Pokemon_SetState(obj, func_802C0AF0_642FA0);
}

void func_802C0AF0_642FA0(GObj* obj) {
    DObj* dobj = obj->data.dobj;
    Pokemon* pokemon = GET_POKEMON(obj);

    SHOW_POKEMON();
    Pokemon_StartPathProc(obj, NULL);
    Pokemon_SetAnimation(obj, &D_802C6F60_649410);
    animSetTextureAnimationSpeed(obj, (pokemon->miscVars[0].field1 * dobj->animSpeed) / 2);
    if (pokemon->miscVars[1].field1 == 0) {
        pokemon->miscVars[0].field1 = 0;
    }
    pokemon->transitionGraph = D_802C6FD4_649484;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, &D_802C7014_6494C4);
}

// clang-format off
void func_802C0BB0_643060(GObj* obj) { \
    DObj* dobj = obj->data.dobj; \
    Pokemon* pokemon = GET_POKEMON(obj);
    // clang-format on
    s32 i = 2;

    Pokemon_StartPathProc(obj, func_802C0CD8_643188);

    while (i--) {
        Pokemon_SetAnimation(obj, &D_802C6F74_649424);
        animSetTextureAnimationSpeed(obj, (pokemon->miscVars[0].field1 * dobj->animSpeed) / 2);
        if (pokemon->miscVars[1].field1 == 0) {
            pokemon->miscVars[0].field1 = 0;
        }
        pokemon->transitionGraph = D_802C6FD4_649484;
        Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED | POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
        if (pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED) {
            Pokemon_SetState(obj, func_802C0AF0_642FA0);
        }
    }

    Pokemon_SetStateRandom(obj, &D_802C7014_6494C4);
}

void func_802C0CD8_643188(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 20.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802C0D34_6431E4(GObj* obj) {
    DObj* dobj = obj->data.dobj;
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_StartPathProc(obj, NULL);
    Pokemon_SetAnimation(obj, &D_802C6F88_649438);
    animSetTextureAnimationSpeed(obj, (pokemon->miscVars[0].field1 * dobj->animSpeed) / 2);
    if (pokemon->miscVars[1].field1 == 0) {
        pokemon->miscVars[0].field1 = 0;
    }
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    pokemon->miscVars[1].field1 = 180;
    if (pokemon->miscVars[0].field1 == 0) {
        Pokemon_StartAuxProc(obj, func_802C0E28_6432D8);
    }
    pokemon->miscVars[0].field1++;
    if (pokemon->miscVars[0].field1 >= 3) {
        Pokemon_SetState(obj, func_802C0F30_6433E0);
    }
    Pokemon_SetState(obj, func_802C0AF0_642FA0);
}

void func_802C0E28_6432D8(GObj* obj) {
    s32 temp_t8;
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->miscVars[1].field1--;
    while (pokemon->miscVars[1].field1 != 0) {
        ohWait(1);
        pokemon->miscVars[1].field1--;
    }
    Pokemon_StopAuxProc(obj);
}

void func_802C0E80_643330(GObj* obj) {
    DObj* dobj = obj->data.dobj;
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_StartPathProc(obj, NULL);
    Pokemon_SetAnimation(obj, &D_802C6F9C_64944C);
    animSetTextureAnimationSpeed(obj, (pokemon->miscVars[0].field1 * dobj->animSpeed) / 2);
    if (pokemon->miscVars[1].field1 == 0) {
        pokemon->miscVars[0].field1 = 0;
    }
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802C0AF0_642FA0);
}

void func_802C0F30_6433E0(GObj* obj) {
    DObj* dobj = obj->data.dobj;
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802C6FB0_649460);
    animSetTextureAnimationSpeed(obj, (pokemon->miscVars[0].field1 * dobj->animSpeed) / 2);
    if (pokemon->miscVars[1].field1 == 0) {
        pokemon->miscVars[0].field1 = 0;
    }
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    omCreateProcess(obj, evolveIntoMuk, 1, 1);
    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

void func_802C1018_6434C8(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    switch (pokemon->behavior) {
        case 1:
            D_8033E138_6C05E8.unk_00_3 = true;
            break;
        case 2:
            D_8033E138_6C05E8.unk_00_4 = true;
            break;
        case 3:
            D_8033E138_6C05E8.unk_00_5 = true;
            break;
        case 4:
            D_8033E138_6C05E8.unk_00_6 = true;
            break;
    }
    Pokemon_StopAuxProc(obj);
}

GObj* func_802C10C8_643578(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802C7040_6494F0);
}

void func_802C1100_6435B0(GObj* obj) {
    Pokemon_SetState(obj, func_802C1178_643628);
}

void func_802C1124_6435D4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802C70DC_64958C);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802C1178_643628);
}

void func_802C1178_643628(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_StartPathProc(obj, NULL);
    Pokemon_SetAnimation(obj, &D_802C708C_64953C);
    pokemon->transitionGraph = D_802C70F0_6495A0;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, &D_802C7120_6495D0);
}

void func_802C11E8_643698(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_StartPathProc(obj, func_802C1288_643738);
    Pokemon_SetAnimation(obj, &D_802C70A0_649550);
    pokemon->pokemonLoopTarget = 5;
    pokemon->transitionGraph = D_802C70F0_6495A0;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED | POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED) {
        Pokemon_SetState(obj, func_802C1178_643628);
    }
    Pokemon_SetStateRandom(obj, &D_802C7120_6495D0);
}

void func_802C1288_643738(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 20.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.01f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802C12E4_643794(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_StartPathProc(obj, NULL);
    Pokemon_SetAnimation(obj, &D_802C70B4_649564);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802C1178_643628);
}

void func_802C134C_6437FC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_StartPathProc(obj, NULL);
    Pokemon_SetAnimation(obj, &D_802C70C8_649578);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802C1178_643628);
}

GObj* func_802C13B4_643864(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802C714C_6495FC);
}

GObj* func_802C13EC_64389C(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802C7194_649644);
}
