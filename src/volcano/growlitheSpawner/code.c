#include "volcano/volcano.h"

extern UnkEC64Arg3 growlitheSpawner_model[];
extern Texture** growlitheSpawner_materials[];

extern AnimCmd* growlitheSpawner_modelanim[];
extern AnimCmd** growlitheSpawner_matanim[];

void growlitheSpawner_InitialState(GObj*);
void growlitheSpawner_SpawnPokemon(GObj*);
void func_802D6B64_727D64(GObj*);
void growlitheSpawner_SendCommands(GObj*);
void growlitheSpawner_Idle(GObj*);

AnimationHeader growlitheSpawner_animation = {
    1.5,
    100,
    growlitheSpawner_modelanim,
    growlitheSpawner_matanim,
    NULL
};

InteractionHandler growlitheSpawner_tg_Normal[] = {
    { VOLCANO_CMD_38, growlitheSpawner_SpawnPokemon, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

PokemonAnimationSetup growlitheSpawner_animSetup = {
    &growlitheSpawner_animation,
    growlitheSpawner_InitialState,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData growlitheSpawner_initData = {
    growlitheSpawner_model,
    growlitheSpawner_materials,
    renderModelTypeBFogged,
    &growlitheSpawner_animSetup,
    { 10, 10, 10 },
    { 0, -300, 0 },
    0,
    0,
    0,
    0,
    0,
    { 0, 0, 0 }
};

POKEMON_FUNC(growlitheSpawner_InitialState)
    s32 blockIndex;
    f32 blockPart;

    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_HIDDEN | GOBJ_FLAG_2;

    while (true) {
        getLevelProgress(&blockIndex, &blockPart);
        if (blockIndex > 5 || blockIndex == 5 && blockPart >= 0.06) {
            break;
        }
        ohWait(1);
    }

    pokemon->tangible = true;
    obj->flags = 0;
    pokemon->miscVars[0].field1 = false;
    omCreateProcess(obj, func_802D6B64_727D64, 1, 1);
    Pokemon_StartPathProc(obj, growlitheSpawner_SendCommands);
    Pokemon_SetState(obj, growlitheSpawner_Idle);
}

POKEMON_FUNC(growlitheSpawner_Idle)
    Pokemon_SetAnimation(obj, &growlitheSpawner_animation);
    pokemon->transitionGraph = growlitheSpawner_tg_Normal;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, growlitheSpawner_Idle);
}

POKEMON_FUNC(growlitheSpawner_SpawnPokemon)
    omCreateProcess(obj, func_802D6B2C_727D2C, 1, 1);

    if (!pokemon->miscVars[0].field1 && Pokemon_GetDistance(obj, pokemon->interactionTarget) < 200.0f && func_802D6D6C_727F6C(obj)) {
        pokemon->miscVars[0].field1 = true;
    }

    Pokemon_SetAnimation(obj, &growlitheSpawner_animation);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, growlitheSpawner_Idle);
}

POKEMON_FUNC(growlitheSpawner_SendCommands)
    while (!pokemon->miscVars[0].field1) {
        cmdSendCommand(pokemon->miscVars[1].obj, VOLCANO_CMD_34, obj);
        ohWait(randRange(180) + 120);
    }

    cmdSendCommand(pokemon->miscVars[1].obj, VOLCANO_CMD_35, obj);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

GObj* growlitheSpawner_Spawn(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnDlLink4(objID, id, block, blockB, spawn, &growlitheSpawner_initData);
}
