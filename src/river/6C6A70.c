#include "common.h"
#include "world/world.h"
#include "app_level/app_level.h"
#include "river.h"

extern s32 D_802E3DA0_6CBB80;
extern AnimationHeader D_802E3E04_6CBBE4;
extern AnimationHeader D_802E3E18_6CBBF8;
extern AnimationHeader D_802E3E2C_6CBC0C;
extern InteractionHandler D_802E3E40_6CBC20[];
extern InteractionHandler D_802E3E70_6CBC50[];
extern PokemonInitData D_802E3EA4_6CBC84;
extern PokemonInitData D_802E40B0_6CBE90;
extern AnimationHeader D_802E3EF4_6CBCD4;
extern AnimationHeader D_802E3F08_6CBCE8;
extern AnimationHeader D_802E3F1C_6CBCFC;
extern AnimationHeader D_802E3F30_6CBD10;
extern AnimationHeader D_802E3F44_6CBD24;
extern AnimationHeader D_802E3F58_6CBD38;
extern InteractionHandler D_802E3F6C_6CBD4C[];
extern InteractionHandler D_802E3FCC_6CBDAC[];
extern InteractionHandler D_802E400C_6CBDEC[];
extern InteractionHandler D_802E403C_6CBE1C[];
extern InteractionHandler D_802E406C_6CBE4C[];

void func_802DEDD4_6C6BB4(GObj*);
void func_802DEEA0_6C6C80(GObj*);
void func_802DEF28_6C6D08(GObj*);
void func_802DF154_6C6F34(GObj*);
void func_802DF560_6C7340(GObj*);
void func_802DF5B8_6C7398(GObj*);

POKEMON_FUNC(func_802DEC90_6C6A70)
    pokemon->miscVars[1].field0 = position->v.y * 1;
    getGroundAt(position->v.x, position->v.z, &pokemon->currGround);
    pokemon->miscVars[0].field0 = pokemon->currGround.height + 5.0f;
    Pokemon_SetState(obj, func_802DEDD4_6C6BB4);
}

POKEMON_FUNC(func_802DED0C_6C6AEC)
    Pokemon_SetAnimation(obj, &D_802E3E04_6CBBE4);
    pokemon->transitionGraph = D_802E3E40_6CBC20;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802DED0C_6C6AEC);
}

POKEMON_FUNC(func_802DED68_6C6B48)
    Pokemon_SetAnimation(obj, &D_802E3E18_6CBBF8);
    Pokemon_StartPathProc(obj, func_802DEEA0_6C6C80);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetState(obj, func_802DEDD4_6C6BB4);
}

POKEMON_FUNC(func_802DEDD4_6C6BB4)
    Pokemon_SetAnimation(obj, &D_802E3E2C_6CBC0C);
    pokemon->transitionGraph = D_802E3E70_6CBC50;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802DEE2C_6C6C0C)
    Pokemon_SetAnimation(obj, &D_802E3E18_6CBBF8);
    Pokemon_StartPathProc(obj, func_802DEF28_6C6D08);
    pokemon->transitionGraph = D_802E3E40_6CBC20;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetState(obj, func_802DED0C_6C6AEC);
}

POKEMON_FUNC(func_802DEEA0_6C6C80)
    pokemon->jumpVel = 300.0f;
    Pokemon_Jump(obj, pokemon->miscVars[1].field0 - (position->v.y * 1), 0.0f, 0.0f, 0.0f);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802DEF28_6C6D08)
    pokemon->jumpVel = 90.0f;
    Pokemon_FallToHeight(obj, pokemon->miscVars[0].field0, 0, 0, 0);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

GObj* func_802DEF88_6C6D68(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_Spawn(objID, id, block, blockB, spawn, &D_802E3EA4_6CBC84);
}

POKEMON_FUNC(func_802DEFC0_6C6DA0)
    s32 blockCount;
    f32 blockPart;

    while (true) {
        getLevelProgress(&blockCount, &blockPart);
        if (blockCount < 3 && (blockCount != 2 || !(blockPart >= 0.7))) {
            ohWait(1);
        } else {
            break;
        }
    }
    pokemon->flags &= ~POKEMON_FLAG_40;
    Pokemon_StopAuxProc(obj);
}

void func_802DF078_6C6E58(GObj* obj) {
    Pokemon_StartAuxProc(obj, func_802DEFC0_6C6DA0);
    D_802E3DA0_6CBB80 = 0;
    Pokemon_SetState(obj, func_802DF154_6C6F34);
}

POKEMON_FUNC(func_802DF0B8_6C6E98)
    s32 i = 144;

    while (i--) {
        ohWait(1);
    }
    D_802E3DA0_6CBB80 = 0;
    Pokemon_StopAuxProc(obj);
}

POKEMON_FUNC(func_802DF104_6C6EE4)
    s32 i = 280;

    while (i--) {
        ohWait(1);
    }
    D_802E3DA0_6CBB80 = 1;
    Pokemon_StopAuxProc(obj);
}

POKEMON_FUNC(func_802DF154_6C6F34)
    pokemon->flags |= POKEMON_FLAG_8;
    Pokemon_ForceAnimation(obj, &D_802E3EF4_6CBCD4);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->counter = 30, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);
    pokemon->transitionGraph = D_802E3F6C_6CBD4C;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802DF1F0_6C6FD0)
    Pokemon_StartPathProc(obj, NULL);
    Pokemon_SetAnimation(obj, &D_802E3EF4_6CBCD4);
    animSetModelAndTextureAnimationSpeed(obj, model->animSpeed * 8);
    pokemon->transitionGraph = D_802E3F6C_6CBD4C;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_ForceAnimation(obj, &D_802E3EF4_6CBCD4);
    animSetModelAndTextureAnimationSpeed(obj, model->animSpeed * 8);
    pokemon->transitionGraph = D_802E3F6C_6CBD4C;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_ForceAnimation(obj, &D_802E3EF4_6CBCD4);
    animSetModelAndTextureAnimationSpeed(obj, model->animSpeed * 4);
    pokemon->transitionGraph = D_802E3F6C_6CBD4C;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_ForceAnimation(obj, &D_802E3EF4_6CBCD4);
    animSetModelAndTextureAnimationSpeed(obj, model->animSpeed * 2);
    pokemon->transitionGraph = D_802E3F6C_6CBD4C;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802DF154_6C6F34);
}

POKEMON_FUNC(func_802DF360_6C7140)
    Pokemon_StartAuxProc(obj, func_802DF104_6C6EE4);
    Pokemon_SetAnimation(obj, &D_802E3F44_6CBD24);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_802E3FCC_6CBDAC;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);
    Pokemon_SetState(obj, func_802DF5B8_6C7398);
}

POKEMON_FUNC(func_802DF404_6C71E4)
    Pokemon_SetAnimation(obj, &D_802E3F08_6CBCE8);
    Pokemon_StartPathProc(obj, func_802DF560_6C7340);
    pokemon->transitionGraph = D_802E403C_6CBE1C;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetState(obj, func_802DF5B8_6C7398);
}

POKEMON_FUNC(func_802DF478_6C7258)
    Pokemon_SetAnimation(obj, &D_802E3F1C_6CBCFC);
    Pokemon_StartPathProc(obj, func_802DF560_6C7340);
    pokemon->transitionGraph = D_802E400C_6CBDEC;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetState(obj, func_802DF5B8_6C7398);
}

POKEMON_FUNC(func_802DF4EC_6C72CC)
    Pokemon_SetAnimation(obj, &D_802E3F30_6CBD10);
    Pokemon_StartPathProc(obj, func_802DF560_6C7340);
    pokemon->transitionGraph = D_802E406C_6CBE4C;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetState(obj, func_802DF5B8_6C7398);
}

POKEMON_FUNC(func_802DF560_6C7340)
    pokemon->flags &= ~POKEMON_FLAG_8;
    Pokemon_TurnToTarget(obj, 0.1f, 0x2E);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802DF5B8_6C7398)
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_802E3F58_6CBD38);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_StartAuxProc(obj, func_802DF0B8_6C6E98);
    Pokemon_SetState(obj, func_802DF154_6C6F34);
}

GObj* func_802DF634_6C7414(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802E40B0_6CBE90);
}
