#include "volcano/volcano.h"

extern AnimCmd* D_80152DA0[];
extern AnimCmd* D_801518F0[];
extern AnimCmd* D_801522E0[];
extern AnimCmd* D_801553E0[];
extern AnimCmd* D_80156930[];
extern AnimCmd* D_80153810[];

extern AnimCmd** D_8015A380[];
extern AnimCmd** D_80158F80[];
extern AnimCmd** D_80159D40[];
extern AnimCmd** D_8015DD50[];
extern AnimCmd** D_8015F2B0[];
extern AnimCmd** D_8015C800[];

void func_802D893C_729B3C(GObj*);
void func_802D89B0_729BB0(GObj*);
void func_802D8018_729218(GObj*);
void func_802D8118_729318(GObj*);
void func_802D7F60_729160(GObj*);
void func_802D8218_729418(GObj*);
void func_802D8288_729488(GObj*);
void func_802D859C_72979C(GObj*);
void func_802D8830_729A30(GObj*);
void func_802D7FA8_7291A8(GObj*);
void func_802D82F8_7294F8(GObj*);
void func_802D8750_729950(GObj*);
void func_802D87C0_7299C0(GObj*);
void func_802D8368_729568(GObj*);
void func_802D85C0_7297C0(GObj*);
void func_802D8868_729A68(GObj*);
void func_802D88D0_729AD0(GObj*);
void func_802D8620_729820(GObj*);
void func_802D86E0_7298E0(GObj*);
void func_802D80BC_7292BC(GObj*);
void func_802D81BC_7293BC(GObj*);
void func_802D842C_72962C(GObj*);
void func_802D8478_729678(GObj*);
void func_802D84FC_7296FC(GObj*);
void func_802D8694_729894(GObj*);

s32 D_802E1510_732710[] = { 0, SOUND_ID_129, SOUND_ID_130 };
s32 D_802E151C_73271C[] = { SOUND_ID_128, SOUND_ID_129, SOUND_ID_130, SOUND_ID_131 };
s32 D_802E152C_73272C[] = { SOUND_ID_347 };
s32 D_802E1530_732730[] = { 0, SOUND_ID_129, SOUND_ID_130 };
s32 D_802E153C_73273C[] = { SOUND_ID_347 };

AnimationHeader D_802E1540_732740 = {
    0.5,
    112,
    D_80152DA0,
    D_8015A380,
    D_802E1510_732710
};

AnimationHeader D_802E1554_732754 = {
    0.5,
    40,
    D_801518F0,
    D_80158F80,
    NULL
};

AnimationHeader D_802E1568_732768 = {
    0.5,
    16,
    D_801522E0,
    D_80159D40,
    D_802E151C_73271C
};

AnimationHeader D_802E157C_73277C = {
    0.5,
    64,
    D_801553E0,
    D_8015DD50,
    D_802E152C_73272C
};

AnimationHeader D_802E1590_732790 = {
    0.5,
    128,
    D_80156930,
    D_8015F2B0,
    D_802E1530_732730
};

AnimationHeader D_802E15A4_7327A4 = {
    0.5,
    64,
    D_80153810,
    D_8015C800,
    D_802E153C_73273C
};

InteractionHandler D_802E15B8_7327B8[] = {
    { POKEMON_CMD_9, func_802D8218_729418, 0, NULL },
    { POKEMON_CMD_13, func_802D8288_729488, 0, NULL },
    { POKEMON_CMD_10, func_802D82F8_7294F8, 0, NULL },
    { POKEMON_CMD_14, func_802D8368_729568, 0, NULL },
    { POKEMON_CMD_15, func_802D859C_72979C, 0, NULL },
    { POKEMON_CMD_5, func_802D8620_729820, 0, NULL },
    { POKEMON_CMD_6, func_802D8620_729820, 0, NULL },
    { POKEMON_CMD_7, func_802D8620_729820, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E1648_732848[] = {
    { POKEMON_CMD_9, func_802D8218_729418, 0, NULL },
    { POKEMON_CMD_13, func_802D8288_729488, 0, NULL },
    { POKEMON_CMD_10, func_802D82F8_7294F8, 0, NULL },
    { POKEMON_CMD_14, func_802D8368_729568, 0, NULL },
    { POKEMON_CMD_5, func_802D8620_729820, 0, NULL },
    { POKEMON_CMD_6, func_802D8620_729820, 0, NULL },
    { POKEMON_CMD_7, func_802D8620_729820, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E16C8_7328C8[] = {
    { POKEMON_CMD_9, func_802D8218_729418, 0, NULL },
    { POKEMON_CMD_13, func_802D8288_729488, 0, NULL },
    { POKEMON_CMD_10, func_802D82F8_7294F8, 0, NULL },
    { POKEMON_CMD_14, func_802D8368_729568, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E1718_732918[] = {
    { POKEMON_CMD_9, func_802D8218_729418, 0, NULL },
    { POKEMON_CMD_13, func_802D8288_729488, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E1748_732948[] = {
    { POKEMON_CMD_9, func_802D8218_729418, 0, NULL },
    { POKEMON_CMD_13, func_802D8288_729488, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E1778_732978[] = {
    { POKEMON_CMD_9, func_802D8218_729418, 0, NULL },
    { POKEMON_CMD_13, func_802D8288_729488, 0, NULL },
    { POKEMON_CMD_15, func_802D859C_72979C, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E17B8_7329B8[] = {
    { POKEMON_CMD_9, func_802D8218_729418, 0, NULL },
    { POKEMON_CMD_13, func_802D8288_729488, 0, NULL },
    { POKEMON_CMD_10, func_802D82F8_7294F8, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

RandomState D_802E17F8_7329F8[] = {
    { 100, func_802D7FA8_7291A8 },
    { 100, func_802D8018_729218 },
    { 100, func_802D8118_729318 },
    { 0, NULL },
};

InteractionHandler D_802E1818_732A18[] = {
    { POKEMON_CMD_9, func_802D8750_729950, 0, NULL },
    { POKEMON_CMD_13, func_802D8750_729950, 0, NULL },
    { POKEMON_CMD_10, func_802D87C0_7299C0, 0, NULL },
    { POKEMON_CMD_14, func_802D87C0_7299C0, 0, NULL },
    { POKEMON_CMD_16, func_802D8830_729A30, 4000, NULL },
    { POKEMON_CMD_58, NULL, NULL, NULL },
};

InteractionHandler D_802E1878_732A78[] = {
    { POKEMON_CMD_9, func_802D893C_729B3C, 0, NULL },
    { POKEMON_CMD_13, func_802D893C_729B3C, 0, NULL },
    { POKEMON_CMD_10, func_802D89B0_729BB0, 0, NULL },
    { POKEMON_CMD_14, func_802D89B0_729BB0, 0, NULL },
    { POKEMON_CMD_58, NULL, NULL, NULL },
};

InteractionHandler D_802E18C8_732AC8[] = {
    { POKEMON_CMD_9, func_802D893C_729B3C, 0, NULL },
    { POKEMON_CMD_13, func_802D893C_729B3C, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

PokemonAnimationSetup D_802E18F8_732AF8 = {
    &D_802E1540_732740,
    func_802D7F60_729160,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData D_802E190C_732B0C = {
    rapidash_model,
    rapidash_materials,
    renderPokemonModelTypeI,
    &D_802E18F8_732AF8,
    { 1.2, 1.2, 1.2 },
    { 0, 140, 0 },
    75,
    POKEMON_FLAG_20 | POKEMON_FLAG_4 | POKEMON_FLAG_1,
    0,
    0,
    0,
    { 0, 0, 0 }
};

POKEMON_FUNC(func_802D7F60_729160)
    if (pokemon->behavior != 0) {
        Pokemon_SetState(obj, func_802D86E0_7298E0);
    }
    Pokemon_SetState(obj, func_802D7FA8_7291A8);
}

POKEMON_FUNC(func_802D7FA8_7291A8)
    Pokemon_SetAnimation(obj, &D_802E1540_732740);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E15B8_7327B8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_802E17F8_7329F8);
}

POKEMON_FUNC(func_802D8018_729218)
    Pokemon_SetAnimation(obj, &D_802E1554_732754);
    pokemon->pokemonLoopTarget = 5;
    Pokemon_StartPathProc(obj, func_802D80BC_7292BC);    
    pokemon->transitionGraph = D_802E15B8_7327B8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED | POKEMON_PROCESS_FLAG_PATH_ENDED);
    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED) {
        Pokemon_SetState(obj, func_802D7FA8_7291A8);
    }
    Pokemon_SetStateRandom(obj, D_802E17F8_7329F8);
}

POKEMON_FUNC(func_802D80BC_7292BC)
    pokemon->hSpeed = 40.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802D8118_729318)
    Pokemon_SetAnimation(obj, &D_802E1568_732768);
    pokemon->pokemonLoopTarget = 5;
    Pokemon_StartPathProc(obj, func_802D81BC_7293BC);    
    pokemon->transitionGraph = D_802E15B8_7327B8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED | POKEMON_PROCESS_FLAG_PATH_ENDED);
    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED) {
        Pokemon_SetState(obj, func_802D7FA8_7291A8);
    }
    Pokemon_SetStateRandom(obj, D_802E17F8_7329F8);
}

POKEMON_FUNC(func_802D81BC_7293BC)
    pokemon->hSpeed = 160.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802D8218_729418)
    Pokemon_SetAnimation(obj, &D_802E157C_73277C);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E1718_732918;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802D85C0_7297C0);
}

POKEMON_FUNC(func_802D8288_729488)
    Pokemon_SetAnimation(obj, &D_802E157C_73277C);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E1718_732918;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802D85C0_7297C0);
}

POKEMON_FUNC(func_802D82F8_7294F8)
    Pokemon_ForceAnimation(obj, &D_802E15A4_7327A4);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E1718_732918;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802D7FA8_7291A8);
}

POKEMON_FUNC(func_802D8368_729568)
    Pokemon_ForceAnimation(obj, &D_802E15A4_7327A4);
    Pokemon_StartPathProc(obj, func_802D842C_72962C);
    pokemon->transitionGraph = D_802E1718_732918;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_StartPathProc(obj, func_802D8478_729678);
    pokemon->transitionGraph = D_802E1648_732848;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (!(pokemon->processFlags & POKEMON_PROCESS_TARGET_REACHED)) {
        Pokemon_SetState(obj, func_802D7FA8_7291A8);
    }
    Pokemon_SetState(obj, func_802D84FC_7296FC);
}

POKEMON_FUNC(func_802D842C_72962C)
    Pokemon_TurnToTarget(obj, 0.1f, 0);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802D8478_729678)
    Pokemon_SetAnimation(obj, &D_802E1568_732768);
    pokemon->hSpeed = 160.0f;
    Pokemon_RunToTarget(obj, 50.0f, 0.1f, MOVEMENT_FLAG_UPDATE_TARGET_POS | MOVEMENT_FLAG_ON_GROUND);
    Pokemon_TurnToTarget(obj, 0.1f, 0);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802D84FC_7296FC)
    if (pokemon->interactionTarget == NULL) {
        Pokemon_SetState(obj, func_802D7FA8_7291A8);
    }

    Pokemon_SetAnimation(obj, &D_802E1590_732790);
    pokemon->transitionGraph = D_802E16C8_7328C8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    if (pokemon->interactionTarget != NULL) {
        Pokemon_SetState(obj, func_802D84FC_7296FC);
    }
    Pokemon_SetState(obj, func_802D85C0_7297C0);
}

POKEMON_FUNC(func_802D859C_72979C)
    Pokemon_SetState(obj, func_802D8368_729568);
}

POKEMON_FUNC(func_802D85C0_7297C0)
    pokemon->apple = NULL;
    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_802E1778_732978;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_SetState(obj, func_802D7FA8_7291A8);
}

POKEMON_FUNC(func_802D8620_729820)
    Pokemon_SetAnimation(obj, &D_802E1554_732754);
    Pokemon_StartPathProc(obj, func_802D8694_729894);
    pokemon->transitionGraph = D_802E1748_732948;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_SetState(obj, func_802D7FA8_7291A8);
}

POKEMON_FUNC(func_802D8694_729894)
    Pokemon_TurnToTarget(obj, 0.1f, MOVEMENT_FLAG_TURN_TO_PLAYER | MOVEMENT_FLAG_STOP_WHEN_TURN_COMPLETED | MOVEMENT_FLAG_STOP_WHEN_FLUTE_STOPPED_PLAYING | MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802D86E0_7298E0)
    Pokemon_SetAnimation(obj, &D_802E1540_732740);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E1818_732A18;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802D86E0_7298E0);
}

POKEMON_FUNC(func_802D8750_729950)
    Pokemon_SetAnimation(obj, &D_802E157C_73277C);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E1818_732A18;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802D8830_729A30);
}

POKEMON_FUNC(func_802D87C0_7299C0)
    Pokemon_ForceAnimation(obj, &D_802E15A4_7327A4);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E1818_732A18;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802D8830_729A30);
}

POKEMON_FUNC(func_802D8830_729A30)
    Pokemon_StartPathProc(obj, func_802D88D0_729AD0);
    Pokemon_SetState(obj, func_802D8868_729A68);
}

POKEMON_FUNC(func_802D8868_729A68)
    Pokemon_SetAnimation(obj, &D_802E1568_732768);
    pokemon->transitionGraph = D_802E1878_732A78;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802D88D0_729AD0)
    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0, 1, 0.15f, 0.0f, MOVEMENT_FLAG_UPDATE_TARGET_POS | MOVEMENT_FLAG_ON_GROUND);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802D893C_729B3C)
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_ForceAnimation(obj, &D_802E157C_73277C);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_SetState(obj, func_802D8868_729A68);
}

POKEMON_FUNC(func_802D89B0_729BB0)
    InteractionHandler saved[3] = D_802E18C8_732AC8;

    pokemon->processFlags |= POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_ForceAnimation(obj, &D_802E15A4_7327A4);
    pokemon->transitionGraph = saved;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_SetState(obj, func_802D8868_729A68);
}

GObj* func_802D8A5C_729C5C(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802E190C_732B0C);
}
