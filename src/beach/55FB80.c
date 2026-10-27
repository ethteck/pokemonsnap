#include "common.h"
#include "beach.h"

extern AnimCmd* D_801548D0_E0D60[];
extern AnimCmd* D_80156960_E2DF0[];
extern AnimCmd* D_80183D20_1101B0[];
extern AnimCmd** D_80184400_110890[];
extern UnkEC64Arg3 butterfree_model[];
extern Texture** lapras_materials[];
extern UnkEC64Arg3 lapras_model[];

s32 D_beach_802CCD20[] = { SOUND_ID_253 };

AnimationHeader D_beach_802CCD24 = {
    0.3f,
    100.0f,
    D_801548D0_E0D60,
    NULL,
    NULL
};

AnimationHeader D_beach_802CCD38 = {
    0.3f,
    100.0f,
    D_80156960_E2DF0,
    NULL,
    D_beach_802CCD20
};

AnimationHeader D_beach_802CCD4C = {
    0.35f,
    100.0f,
    D_801548D0_E0D60,
    NULL,
    NULL
};

InteractionHandler D_beach_802CCD60[] = {
    { POKEMON_CMD_8, func_beach_802C7CF0, 0.0f, NULL },
    { POKEMON_CMD_12, func_beach_802C7CF0, 0.0f, NULL },
    { POKEMON_CMD_58, NULL, 0.0f, NULL },
};

PokemonAnimationSetup D_beach_802CCD90 = {
    &D_beach_802CCD24,
    func_beach_802C7B10,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData D_beach_802CCDA4 = {
    butterfree_model,
    NULL,
    renderPokemonModelTypeBFogged,
    &D_beach_802CCD90,
    { 1.6f, 1.6f, 1.6f },
    { 0.0f, 0.0f, 0.0f },
    40.0f,
    POKEMON_FLAG_4 | POKEMON_FLAG_2 | POKEMON_FLAG_1,
    0,
    0,
    0,
    { 0, 0, 0 }
};

u32 D_beach_802CCDD8[] = {
    0x00000000, 0x00000000,
};

s32 D_beach_802CCDE0[] = { 0, SOUND_ID_383 };

AnimationHeader D_beach_802CCDE8 = {
    0.5f,
    265.0f,
    D_80183D20_1101B0,
    D_80184400_110890,
    D_beach_802CCDE0
};

s32 D_beach_802CCDFC = 0;
s32 D_beach_802CCE00 = 0;
s32 D_beach_802CCE04 = 0;

AnimationHeader D_beach_802CCE08 = {
    0.0f,
    0.0f,
    D_80183D20_1101B0,
    D_80184400_110890,
    NULL
};

InteractionHandler D_beach_802CCE1C[] = {
    { POKEMON_CMD_24, func_beach_802C8028, 0.0f, NULL },
    { POKEMON_CMD_58, NULL, 0.0f, NULL },
};

PokemonAnimationSetup D_beach_802CCE3C = {
    &D_beach_802CCE08,
    func_beach_802C7E70,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData D_beach_802CCE50 = {
    lapras_model,
    lapras_materials,
    renderPokemonModelTypeIFogged,
    &D_beach_802CCE3C,
    { 3.0f, 3.0f, 3.0f },
    { 0.0f, -40.0f, -150.0f },
    100.0f,
    POKEMON_FLAG_20 | POKEMON_FLAG_4 | POKEMON_FLAG_1,
    0,
    0,
    0,
    { 0, 0, 0 }
};

void func_beach_802C7B10(GObj* obj) {
    UNUSED s32 pad[2];
    DObj* model = obj->data.dobj;
    Pokemon* pokemon = GET_POKEMON(obj);
    f32 one = 1.0f;
    Mtx3Float* position = &GET_TRANSFORM(model)->pos;

    if (1) {
        if (position) {
        } // TODO fake match
        pokemon->miscVars[0].field0 = position->v.y * one;
    }
    Pokemon_SetAnimationAtTime(obj, &D_beach_802CCD24, randFloat() * 100.0f);
    pokemon->pokemonLoopTarget = 1;
    pokemon->lastAnimationFrame = 0.0f;
    Pokemon_StartPathProc(obj, func_beach_802C7C7C);
    Pokemon_SetState(obj, func_beach_802C7BB8);
}

// clang-format off
void func_beach_802C7BB8(GObj* arg0) { \
    Pokemon* pokemon = GET_POKEMON(arg0);
    // clang-format on
    Pokemon_SetAnimation(arg0, &D_beach_802CCD24);
    pokemon->counter = randRange(600) + 60, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_beach_802CCD60;
    Pokemon_WaitForFlag(arg0, POKEMON_PROCESS_WAIT_ENDED);
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_SetAnimation(arg0, &D_beach_802CCD38);
    pokemon->transitionGraph = D_beach_802CCD60;
    Pokemon_WaitForFlag(arg0, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_SetState(arg0, func_beach_802C7BB8);
}

void func_beach_802C7C7C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, randFloat(), 0, 0.1f, 0.0f, MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_beach_802C7CF0(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_StartAuxProc(obj, func_beach_802C7DA0);
    Pokemon_SetAnimation(obj, &D_beach_802CCD4C);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_AUX_ENDED);
    Pokemon_StartAuxProc(obj, func_beach_802C7DEC);
    Pokemon_SetAnimation(obj, &D_beach_802CCD24);
    pokemon->transitionGraph = D_beach_802CCD60;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_AUX_ENDED);
    Pokemon_SetState(obj, func_beach_802C7BB8);
}

void func_beach_802C7DA0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->jumpVel = 300.0f;
    Pokemon_Jump(obj, 400, 0, 0, 0);
    Pokemon_StopAuxProc(obj);
}

void func_beach_802C7DEC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->jumpVel = 90.0f;
    Pokemon_Fall(obj, 400, 0, 0, 0);
    Pokemon_StopAuxProc(obj);
}

void func_beach_802C7E38(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    Pokemon_Spawn(gObjID, id, roomA, roomB, spawn, &D_beach_802CCDA4);
}

// TODO: potential file split

void func_beach_802C7E70(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    HIDE_POKEMON();
    if (pokemon->behavior == 2) {
        pokemon = pokemon;
        Pokemon_SetState(obj, func_beach_802C816C);
    }
    if (pokemon->behavior == 4) {
        pokemon = pokemon;
        Pokemon_SetState(obj, func_beach_802C81C4);
    }
    if (pokemon->behavior == 5) {
        Pokemon_SetState(obj, func_beach_802C821C);
    }
    Pokemon_SetState(obj, func_beach_802C7F1C);
}

void func_beach_802C7F1C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_StartAuxProc(obj, func_beach_802C7F74);
    pokemon->transitionGraph = D_beach_802CCE1C;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

void func_beach_802C7F74(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    HIDE_POKEMON();
    Pokemon_ForceAnimation(obj, &D_beach_802CCE08);
    pokemon->counter = randRange(600) + 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    Pokemon_WaitForFlagNoInteraction(obj, POKEMON_PROCESS_WAIT_ENDED);
    SHOW_POKEMON();
    Pokemon_ForceAnimation(obj, &D_beach_802CCDE8);
    Pokemon_WaitForFlagNoInteraction(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_StartAuxProc(obj, func_beach_802C7F74);
    Pokemon_StopAuxProc(obj);
}

void func_beach_802C8028(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    if (pokemon->behavior == 0) {
        pokemon = pokemon;
        Pokemon_SetState(obj, func_beach_802C80BC);
    }
    if (pokemon->behavior == 1) {
        pokemon = pokemon;
        Pokemon_SetState(obj, func_beach_802C80F0);
    }
    if (pokemon->behavior == 2) {
        Pokemon_SetState(obj, func_beach_802C8124);
    }
    Pokemon_SetState(obj, NULL);
}

void func_beach_802C80BC(GObj* obj) {
    D_beach_802CCDFC++;
    Pokemon_SetState(obj, NULL);
}

void func_beach_802C80F0(GObj* obj) {
    D_beach_802CCE00++;
    Pokemon_SetState(obj, NULL);
}

void func_beach_802C8124(GObj* obj) {
    D_beach_802CCE00++;
    D_beach_802CCE04++;
    Pokemon_SetState(obj, NULL);
}

void func_beach_802C816C(GObj* obj) {
    while (true) {
        if (D_beach_802CCDFC > 0) {
            break;
        }

        ohWait(1);
    }

    Pokemon_SetState(obj, func_beach_802C7F1C);
}

void func_beach_802C81C4(GObj* obj) {
    while (true) {
        if (D_beach_802CCE00 > 0) {
            break;
        }

        ohWait(1);
    }

    Pokemon_SetState(obj, func_beach_802C7F1C);
}

void func_beach_802C821C(GObj* obj) {
    while (true) {
        if (D_beach_802CCE04 > 0) {
            break;
        }

        ohWait(1);
    }

    Pokemon_SetState(obj, func_beach_802C7F1C);
}

void func_beach_802C8274(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    Pokemon_Spawn(gObjID, id, roomA, roomB, spawn, &D_beach_802CCE50);
}
