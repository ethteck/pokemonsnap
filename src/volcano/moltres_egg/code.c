#include "volcano/volcano.h"

extern UnkEC64Arg3 D_8014F080[];
extern AnimCmd* D_8014E550[];
extern AnimCmd* D_8014E650[];

void func_802DDAD0_72ECD0(GObj*);
void func_802DDB60_72ED60(GObj*);
void func_802DDB04_72ED04(GObj*);
void func_802DDC30_72EE30(GObj*);
void func_802DDCA0_72EEA0(GObj*);
void func_802DDD04_72EF04(GObj*);
void func_802D6C38_727E38(GObj*);
void func_802DDE00_72F000(GObj*);
void func_802D6BB0_727DB0(GObj*);

AnimationHeader D_802E3010_734210 = {
    0.5,
    60,
    D_8014E550,
    NULL,
    NULL
};

AnimationHeader D_802E3024_734224 = {
    0.5,
    60,
    D_8014E650,
    NULL,
    NULL
};

InteractionHandler D_802E3038_734238[] = {
    { POKEMON_CMD_9, func_802DDB60_72ED60, 0, NULL },
    { POKEMON_CMD_13, func_802DDB60_72ED60, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

f32 D_802E3068_734268[] = { 0 };

PokemonAnimationSetup D_802E306C_73426C = {
    &D_802E3010_734210,
    func_802DDAD0_72ECD0,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData D_802E3080_734280 = {
    D_8014F080,
    NULL,
    renderPokemonModelTypeBFogged,
    &D_802E306C_73426C,
    { 1.7, 1.7, 1.7 },
    { 0, 123, 0 },
    60,
    POKEMON_FLAG_40 | POKEMON_FLAG_20 | POKEMON_FLAG_4 | POKEMON_FLAG_1,
    0,
    0,
    0,
    { 0, 0, 0 }
};

POKEMON_FUNC(func_802DDAD0_72ECD0)
    pokemon->forbiddenGround = D_802E3068_734268;
    Pokemon_SetState(obj, func_802DDB04_72ED04);
}

POKEMON_FUNC(func_802DDB04_72ED04)
    Pokemon_SetAnimation(obj, &D_802E3010_734210);
    pokemon->transitionGraph = D_802E3038_734238;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_802DDB04_72ED04);
}

POKEMON_FUNC(func_802DDB60_72ED60)
    if (pokemon->playerDist < 1200.0f) {
        Pokemon_SetAnimation(obj, &D_802E3024_734224);
        Pokemon_StartPathProc(obj, func_802DDC30_72EE30);
        pokemon->transitionGraph = NULL;
        Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    } else {
        Pokemon_SetAnimation(obj, &D_802E3010_734210);
        Pokemon_StartPathProc(obj, func_802DDCA0_72EEA0);
        pokemon->transitionGraph = NULL;
        Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
        Pokemon_SetState(obj, func_802DDB04_72ED04);
    }

    Pokemon_SetState(obj, func_802DDD04_72EF04);
}

POKEMON_FUNC(func_802DDC30_72EE30)
    pokemon->hSpeed = 200.0f;
    pokemon->jumpVel = 300.0f;
    pokemon->facingYaw = PI;
    Pokemon_FallDownOnGround(obj, -9.8f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802DDCA0_72EEA0)
    pokemon->hSpeed = 0.0f;
    pokemon->jumpVel = 100.0f;
    pokemon->facingYaw = 0.0f;
    Pokemon_FallDownOnGround(obj, -9.8f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802DDD04_72EF04)
    omCreateProcess(obj, func_802D6C38_727E38, 1, 1);
    Pokemon_SetAnimation(obj, &D_802E3024_734224);
    Pokemon_StartPathProc(obj, func_802DDE00_72F000);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    omCreateProcess(obj, func_802D6BB0_727DB0, 1, 1);
    pokemon->counter = 6, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    cmdSendCommandToLink(LINK_POKEMON, POKEMON_CMD_30, obj);
    
    pokemon->counter = 2, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802DDE00_72F000)
    s32 i;

    for (i = 0; i < 100; i++) {
        position->v.y -= 3.0f;
        rotation->f[2] += PI / 180.0f;
        ohWait(1);
    }

    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    pokemon->pathProc = FALSE;
    omEndProcess(NULL);
}

GObj* func_802DDEC0_72F0C0(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802E3080_734280);
}
