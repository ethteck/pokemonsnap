#include "common.h"
#include "world/world.h"
#include "app_level/app_level.h"

void func_802E4B64_5E1C34(GObj*);
void func_802E4DA4_5E1E74(GObj*);
void func_802E4C6C_5E1D3C(GObj*);
void func_802E4D54_5E1E24(GObj*);
void func_802E4EC8_5E1F98(GObj*);
void func_802E4E2C_5E1EFC(GObj*);
void func_802E5008_5E20D8(GObj*);
void func_802E4B40_5E1C10(GObj*);
void func_802E4BD4_5E1CA4(GObj*);
void func_802E4CBC_5E1D8C(GObj*);
void func_802E4EA4_5E1F74(GObj*);
void func_802E4F4C_5E201C(GObj*);

s32 D_802EE6A0_5EB770[] = { 353 };

AnimationHeader D_802EE6A4_5EB774 = {
    0.5,
    59,
    0x80181F40,
    NULL,
    D_802EE6A0_5EB770
};

InteractionHandler D_802EE6B8_5EB788[] = {
    { POKEMON_CMD_14, func_802E4DA4_5E1E74, 0, NULL },
    { POKEMON_CMD_15, func_802E4EA4_5E1F74, 0, NULL },
    { POKEMON_CMD_16, func_802E4F4C_5E201C, 250, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

RandomState D_802EE6F8_5EB7C8[] = {
    { 100, func_802E4B64_5E1C34 },
    { 100, func_802E4BD4_5E1CA4 },
    { 100, func_802E4CBC_5E1D8C },
    { 0, NULL },
};

InteractionHandler D_802EE718_5EB7E8[] = {
    { POKEMON_CMD_14, func_802E4DA4_5E1E74, 0, NULL },
    { POKEMON_CMD_16, func_802E4F4C_5E201C, 250, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802EE748_5EB818[] = {
    { POKEMON_CMD_14, func_802E4DA4_5E1E74, 0, NULL },
    { POKEMON_CMD_16, func_802E4F4C_5E201C, 250, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802EE778_5EB848[] = {
    { POKEMON_CMD_58, NULL, 0, NULL },
};

PokemonAnimationSetup D_802EE788_5EB858 = {
    &D_802EE6A4_5EB774,
    func_802E4B40_5E1C10,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData D_802EE79C_5EB86C = {
    0x8033FE00,
    NULL,
    renderPokemonModelTypeBFogged,
    &D_802EE788_5EB858,
    { 2.2, 2.2, 2.2 },
    { 0, 320, 0 },
    42,
    POKEMON_FLAG_20 | POKEMON_FLAG_4 | POKEMON_FLAG_1,
    0,
    0,
    0,
    { 0, 0, 0 }
};

POKEMON_FUNC(func_802E4B40_5E1C10)
    Pokemon_SetState(obj, func_802E4B64_5E1C34);
}

POKEMON_FUNC(func_802E4B64_5E1C34)
    Pokemon_SetAnimation(obj, &D_802EE6A4_5EB774);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802EE6B8_5EB788;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetStateRandom(obj, D_802EE6F8_5EB7C8);
}

POKEMON_FUNC(func_802E4BD4_5E1CA4)
    Pokemon_SetAnimation(obj, &D_802EE6A4_5EB774);
    Pokemon_StartPathProc(obj, func_802E4C6C_5E1D3C);
    pokemon->transitionGraph = D_802EE6B8_5EB788;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED | POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED) {
        Pokemon_SetState(obj, func_802E4B64_5E1C34);
    }
    
    Pokemon_SetStateRandom(obj, D_802EE6F8_5EB7C8);
}

POKEMON_FUNC(func_802E4C6C_5E1D3C)
    pokemon->hSpeed = 20.0f;
    Pokemon_RunInCirclesDefault(obj, 500.0f);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802E4CBC_5E1D8C)
    Pokemon_SetAnimation(obj, &D_802EE6A4_5EB774);
    Pokemon_StartPathProc(obj, func_802E4D54_5E1E24);
    pokemon->transitionGraph = D_802EE6B8_5EB788;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED | POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED) {
        Pokemon_SetState(obj, func_802E4B64_5E1C34);
    }
    
    Pokemon_SetStateRandom(obj, D_802EE6F8_5EB7C8);
}

POKEMON_FUNC(func_802E4D54_5E1E24)
    pokemon->hSpeed = 20.0f;
    Pokemon_RunInCirclesDefault(obj, 500.0f);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802E4DA4_5E1E74)
    Pokemon_StartPathProc(obj, func_802E4E2C_5E1EFC);
    pokemon->transitionGraph = D_802EE718_5EB7E8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (!(pokemon->processFlags & POKEMON_PROCESS_TARGET_REACHED)) {
        Pokemon_SetState(obj, func_802E4B64_5E1C34);
    }
    
    Pokemon_SetState(obj, func_802E4EC8_5E1F98);
}

POKEMON_FUNC(func_802E4E2C_5E1EFC)
    Pokemon_TurnToTarget(obj, 0.1f, 0);
    pokemon->hSpeed = 80.0f;
    Pokemon_RunToTarget(obj, 50.0f, 0.1f, MOVEMENT_FLAG_UPDATE_TARGET_POS | MOVEMENT_FLAG_ON_GROUND);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802E4EA4_5E1F74)
    Pokemon_SetState(obj, func_802E4DA4_5E1E74);
}

POKEMON_FUNC(func_802E4EC8_5E1F98)
    Pokemon_SetAnimation(obj, &D_802EE6A4_5EB774);
    pokemon->transitionGraph = D_802EE748_5EB818;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    if (pokemon->interactionTarget != NULL) {
        Pokemon_SetState(obj, func_802E4EC8_5E1F98);
    }
    
    Pokemon_SetStateRandom(obj, D_802EE6F8_5EB7C8);
}

POKEMON_FUNC(func_802E4F4C_5E201C)
    Pokemon_SetAnimation(obj, &D_802EE6A4_5EB774);
    Pokemon_StartPathProc(obj, func_802E5008_5E20D8);
    pokemon->transitionGraph = D_802EE778_5EB848;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (pokemon->processFlags & POKEMON_PROCESS_TARGET_REACHED) {
        Pokemon_SetState(obj, func_802E4B64_5E1C34);
    }
    
    pokemon->transitionGraph = D_802EE778_5EB848;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_802E4B64_5E1C34);
}

POKEMON_FUNC(func_802E5008_5E20D8)
    pokemon->hSpeed = 160.0f;
    Pokemon_RunAwayDefault(obj, 1500.0f);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

GObj* magneton_Spawn(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802EE79C_5EB86C);
}

void tunnel_SpawnMagneton(GObj* obj) {
    GObj* var;
    PokemonDef def = {
        PokemonID_MAGNETON,
        magneton_Spawn,
        pokemonChangeBlockOnGround,
        pokemonRemoveOne
    };

    var = Pokemon_AddAtGeo(obj, PokemonID_MAGNETON, &def);
    GET_POKEMON(var)->behavior = 0;
}
