#include "../tunnel.h"

extern AnimCmd* D_8015AAE0[];
extern AnimCmd* D_8015A4C0[];

extern AnimCmd** D_8015AEF0[];
extern AnimCmd** D_8015AE40[];

extern UnkEC64Arg3 D_80329A00[];
extern Texture** D_80327110[];

void func_802E70BC_5E418C(GObj*);
void func_802E70FC_5E41CC(GObj*);
void func_802E6E0C_5E3EDC(GObj*);
void func_802E6F48_5E4018(GObj*);
void func_802E6EE8_5E3FB8(GObj*);
void func_802E7014_5E40E4(GObj*);
void func_802E71D4_5E42A4(GObj*);
void func_802E729C_5E436C(GObj*);
void func_802E73D0_5E44A0(GObj*);
void func_802E74A4_5E4574(GObj*);
void func_802E7594_5E4664(GObj*);
void kakuna_InitialState(GObj*);
void func_802E6E7C_5E3F4C(GObj*);
void func_802E6FA8_5E4078(GObj*);
void func_802E7324_5E43F4(GObj*);
void func_802E7504_5E45D4(GObj*);
void func_802E75F4_5E46C4(GObj*);

s32 D_802EEBF0_5EBCC0[] = { SOUND_ID_327 };

AnimationHeader D_802EEBF4_5EBCC4 = {
    0.25,
    40,
    D_8015AAE0,
    D_8015AEF0,
    NULL
};

AnimationHeader D_802EEC08_5EBCD8 = {
    0.25,
    40,
    D_8015A4C0,
    D_8015AE40,
    D_802EEBF0_5EBCC0
};

InteractionHandler D_802EEC1C_5EBCEC[] = {
    { POKEMON_CMD_8, func_802E6E7C_5E3F4C, 0, NULL },
    { POKEMON_CMD_12, func_802E6E7C_5E3F4C, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802EEC4C_5EBD1C[] = {
    { TUNNEL_CMD_29, func_802E6FA8_5E4078, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802EEC6C_5EBD3C[] = {
    { TUNNEL_CMD_38, func_802E6FA8_5E4078, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802EEC8C_5EBD5C[] = {
    { POKEMON_CMD_8, func_802E7504_5E45D4, 0, NULL },
    { POKEMON_CMD_12, func_802E7504_5E45D4, 0, NULL },
    { TUNNEL_CMD_51, func_802E75F4_5E46C4, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802EECCC_5EBD9C[] = {
    { TUNNEL_CMD_51, func_802E75F4_5E46C4, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802EECEC_5EBDBC[] = {
    { TUNNEL_CMD_39, func_802E7324_5E43F4, 0, NULL },
    { TUNNEL_CMD_37, func_802E7324_5E43F4, 0, NULL },
    { TUNNEL_CMD_51, func_802E75F4_5E46C4, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

PokemonAnimationSetup kakuna_animSetup = {
    &D_802EEBF4_5EBCC4,
    kakuna_InitialState,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData kakuna_initData = {
    D_80329A00,
    D_80327110,
    renderPokemonModelTypeBFogged,
    &kakuna_animSetup,
    { 2.2, 2.2, 2.2 },
    { 0, 152, -8.8 },
    32,
    POKEMON_FLAG_4 | POKEMON_FLAG_2 | POKEMON_FLAG_1,
    0,
    0,
    0,
    { 0, 0, 0 }
};

POKEMON_FUNC(kakuna_InitialState)
    pokemon->miscVars[0].field0 = position->v.y * 1;
    getGroundAt(position->v.x, position->v.z, &pokemon->currGround);
    pokemon->miscVars[1].field0 = pokemon->currGround.height + 25.0f;

    if (pokemon->behavior == 2) {
        Pokemon_SetState(obj, func_802E70BC_5E418C);
    }
    if (pokemon->behavior == 3) {
        Pokemon_SetState(obj, func_802E70FC_5E41CC);
    }
    pokemon->transitionGraph = D_802EEC4C_5EBD1C;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802E6D90_5E3E60)
    Pokemon_SetAnimation(obj, &D_802EEBF4_5EBCC4);
    pokemon->counter = randRange(300) + 60, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_802EEC1C_5EBCEC;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_SetState(obj, func_802E6E0C_5E3EDC);
}

POKEMON_FUNC(func_802E6E0C_5E3EDC)
    Pokemon_SetAnimation(obj, &D_802EEC08_5EBCD8);
    Pokemon_StartPathProc(obj, func_802E6F48_5E4018);
    pokemon->transitionGraph = D_802EEC1C_5EBCEC;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802E6E7C_5E3F4C)
    Pokemon_SetAnimation(obj, &D_802EEC08_5EBCD8);
    Pokemon_StartPathProc(obj, func_802E6EE8_5E3FB8);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_SetState(obj, func_802E6D90_5E3E60);
}

POKEMON_FUNC(func_802E6EE8_5E3FB8)
    pokemon->jumpVel = 300.0f;
    Pokemon_Jump(obj, 400.0f, 0, 0, 0);
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    pokemon->pathProc = NULL;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802E6F48_5E4018)
    pokemon->jumpVel = 90.0f;
    Pokemon_FallToHeight(obj, pokemon->miscVars[1].field0, 0, 0, 0);
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    pokemon->pathProc = NULL;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802E6FA8_5E4078)
    Pokemon_SetAnimation(obj, &D_802EEC08_5EBCD8);
    Pokemon_StartPathProc(obj, func_802E7014_5E40E4);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_SetState(obj, func_802E6D90_5E3E60);
}

POKEMON_FUNC(func_802E7014_5E40E4)
    pokemon->jumpVel = 0;
    Pokemon_FallToHeight(obj, pokemon->miscVars[1].field0, 20.0f, 0, 3000.0f);

    pokemon->jumpVel = 100.0f;
    Pokemon_Jump(obj, 50.0f, 0, 0, 0);

    Pokemon_FallToHeight(obj, pokemon->miscVars[1].field0, 0, 0, 0);

    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    pokemon->pathProc = NULL;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802E70BC_5E418C)
    pokemon->transitionGraph = D_802EEC6C_5EBD3C;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802E70FC_5E41CC)
    s32 blockCount;
    f32 blockPart;

    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_HIDDEN | GOBJ_FLAG_2;
    obj->flags |= GOBJ_FLAG_2;

    while (true) {
        getLevelProgress(&blockCount, &blockPart);
        if (blockCount < 1 && (blockCount != 0 || !(blockPart >= 0.85f))) {
            ohWait(1);
        } else {
            break;
        }
    }

    pokemon->tangible = true;
    obj->flags = 0;
    goto label; label:; // TODO fake match
    obj->flags &= ~GOBJ_FLAG_2;

    Pokemon_SetState(obj, func_802E71D4_5E42A4);
}

POKEMON_FUNC(func_802E71D4_5E42A4)
    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_HIDDEN | GOBJ_FLAG_2;

    pokemon->counter = randRange(300) + 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_802EECEC_5EBDBC;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    pokemon->tangible = true;
    obj->flags = 0;

    Pokemon_SetAnimation(obj, &D_802EEBF4_5EBCC4);
    Pokemon_StartPathProc(obj, func_802E729C_5E436C);
    pokemon->transitionGraph = D_802EECEC_5EBDBC;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_SetState(obj, func_802E71D4_5E42A4);
}

POKEMON_FUNC(func_802E729C_5E436C)
    pokemon->jumpVel = 270.0f;
    Pokemon_Fall(obj, 400.0f, 0, 0, 0);
    ohWait(60);
    Pokemon_Jump(obj, 400.0f, 0, 0, 0);

    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    pokemon->pathProc = NULL;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802E7324_5E43F4)
    pokemon->tangible = true;
    obj->flags = 0;

    Pokemon_SetAnimation(obj, &D_802EEC08_5EBCD8);
    Pokemon_StartPathProc(obj, func_802E73D0_5E44A0);
    pokemon->transitionGraph = D_802EECCC_5EBD9C;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_StartPathProc(obj, func_802E74A4_5E4574);
    pokemon->transitionGraph = D_802EEC8C_5EBD5C;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_SetState(obj, func_802E71D4_5E42A4);
}

POKEMON_FUNC(func_802E73D0_5E44A0)
    pokemon->jumpVel = 0;
    Pokemon_FallToHeight(obj, pokemon->miscVars[1].field0, 20.0f, 0, 3000.0f);
    pokemon->jumpVel = 100.0f;
    Pokemon_Jump(obj, 50.0f, 0, 0, 0);
    Pokemon_FallToHeight(obj, pokemon->miscVars[1].field0, 0, 0, 0);

    pokemon->counter = 90, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    pokemon->pathProc = NULL;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802E74A4_5E4574)
    pokemon->jumpVel = 300.0f;
    Pokemon_JumpToHeight(obj, pokemon->miscVars[0].field0, 0, 0, 0);

    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    pokemon->pathProc = NULL;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802E7504_5E45D4)
    Pokemon_StartPathProc(obj, func_802E7594_5E4664);
    pokemon->transitionGraph = D_802EECCC_5EBD9C;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_StartPathProc(obj, func_802E74A4_5E4574);
    pokemon->transitionGraph = D_802EEC8C_5EBD5C;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_SetState(obj, func_802E71D4_5E42A4);
}

POKEMON_FUNC(func_802E7594_5E4664)
    pokemon->jumpVel = 300.0f;
    Pokemon_Jump(obj, 400.0f, 0, 0, 0);

    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    pokemon->pathProc = NULL;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802E75F4_5E46C4)
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

GObj* kakuna_Spawn(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_Spawn(objID, id, block, blockB, spawn, &kakuna_initData);
}
