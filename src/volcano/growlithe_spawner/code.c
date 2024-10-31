#include "volcano/volcano.h"

extern UnkEC64Arg3 growlithe_spawner_model[];
extern Texture** growlithe_spawner_materials[];

extern AnimCmd* growlithe_spawner_modelanim[];
extern AnimCmd** growlithe_spawner_matanim[];

void growlithe_spawner_InitialState(GObj*);
void growlithe_spawner_SpawnPokemon(GObj*);
void volcano_CreateSplashFromGrowlitheOrArcanine(GObj*);
void growlithe_spawner_SendCommands(GObj*);
void growlithe_spawner_Idle(GObj*);

__ALIGNER2

AnimationHeader growlithe_spawner_animation = {
    1.5,
    100,
    growlithe_spawner_modelanim,
    growlithe_spawner_matanim,
    NULL
};

InteractionHandler growlithe_spawner_tg_Normal[] = {
    { VOLCANO_CMD_PESTER_BALL_IN_LAVA, growlithe_spawner_SpawnPokemon, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

PokemonAnimationSetup growlithe_spawner_animSetup = {
    &growlithe_spawner_animation,
    growlithe_spawner_InitialState,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData growlithe_spawner_initData = {
    growlithe_spawner_model,
    growlithe_spawner_materials,
    renderModelTypeBFogged,
    &growlithe_spawner_animSetup,
    { 10, 10, 10 },
    { 0, -300, 0 },
    0,
    0,
    0,
    0,
    0,
    { 0, 0, 0 }
};

POKEMON_FUNC(growlithe_spawner_InitialState)
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
    omCreateProcess(obj, volcano_CreateSplashFromGrowlitheOrArcanine, 1, 1);
    Pokemon_StartPathProc(obj, growlithe_spawner_SendCommands);
    Pokemon_SetState(obj, growlithe_spawner_Idle);
}

POKEMON_FUNC(growlithe_spawner_Idle)
    Pokemon_SetAnimation(obj, &growlithe_spawner_animation);
    pokemon->transitionGraph = growlithe_spawner_tg_Normal;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, growlithe_spawner_Idle);
}

POKEMON_FUNC(growlithe_spawner_SpawnPokemon)
    omCreateProcess(obj, volcano_CreateSplashFromGrowlitheSpawner, 1, 1);

    if (!pokemon->miscVars[0].field1 && Pokemon_GetDistance(obj, pokemon->interactionTarget) < 200.0f && volcano_SpawnGrowlitheOrArcanine(obj)) {
        pokemon->miscVars[0].field1 = true;
    }

    Pokemon_SetAnimation(obj, &growlithe_spawner_animation);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, growlithe_spawner_Idle);
}

POKEMON_FUNC(growlithe_spawner_SendCommands)
    while (!pokemon->miscVars[0].field1) {
        cmdSendCommand(pokemon->miscVars[1].obj, VOLCANO_CMD_LAVA_SPLASH_START, obj);
        ohWait(randRange(180) + 120);
    }

    cmdSendCommand(pokemon->miscVars[1].obj, VOLCANO_CMD_LAVA_SPLASH_END, obj);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

GObj* growlithe_spawner_Spawn(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnDlLink4(objID, id, block, blockB, spawn, &growlithe_spawner_initData);
}
