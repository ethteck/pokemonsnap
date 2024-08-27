#include "volcano/volcano.h"

extern AnimCmd* D_8018A750[];
extern AnimCmd* D_80188E30[];
extern AnimCmd* D_801893F0[];
extern AnimCmd* D_80189FF0[];
extern AnimCmd* D_801883C0[];

extern AnimCmd** D_8018B670[];
extern AnimCmd** D_8018B3E0[];
extern AnimCmd** D_8018B4A0[];
extern AnimCmd** D_8018B5A0[];
extern AnimCmd** D_8018B320[];

void func_802DD2E0_72E4E0(GObj*);
void func_802DD500_72E700(GObj*);
void func_802DD570_72E770(GObj*);
void func_802DD5E0_72E7E0(GObj*);
void func_802DD740_72E940(GObj*);
void func_802DD6D4_72E8D4(GObj*);
void func_802DD328_72E528(GObj*);
void func_802DD3B0_72E5B0(GObj*);
void func_802DD4A4_72E6A4(GObj*);
void func_802DD67C_72E87C(GObj*);

s32 D_802E2E50_734050[] = { SOUND_ID_190 };
s32 D_802E2E54_734054[] = { SOUND_ID_190 };
s32 D_802E2E58_734058[] = { SOUND_ID_191 };
s32 D_802E2E5C_73405C[] = { 0, SOUND_ID_140 };

AnimationHeader D_802E2E64_734064 = {
    0.45,
    135,
    D_8018A750,
    D_8018B670,
    D_802E2E50_734050
};

AnimationHeader D_802E2E78_734078 = {
    0.6,
    60,
    D_80188E30,
    D_8018B3E0,
    NULL
};

AnimationHeader D_802E2E8C_73408C = {
    0.55,
    125,
    D_801893F0,
    D_8018B4A0,
    D_802E2E54_734054
};

AnimationHeader D_802E2EA0_7340A0 = {
    0.45,
    60,
    D_80189FF0,
    D_8018B5A0,
    D_802E2E58_734058
};

AnimationHeader D_802E2EB4_7340B4 = {
    0.6,
    150,
    D_801883C0,
    D_8018B320,
    D_802E2E5C_73405C
};

InteractionHandler D_802E2EC8_7340C8[] = {
    { POKEMON_CMD_9, func_802DD5E0_72E7E0, 0, NULL },
    { POKEMON_CMD_10, func_802DD740_72E940, 0, NULL },
    { POKEMON_CMD_13, func_802DD6D4_72E8D4, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E2F08_734108[] = {
    { POKEMON_CMD_31, func_802DD328_72E528, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

RandomState D_802E2F28_734128[] = {
    { 1, func_802DD500_72E700 },
    { 1, func_802DD570_72E770 },
    { 0, NULL },
};

PokemonAnimationSetup D_802E2F40_734140 = {
    &D_802E2E78_734078,
    func_802DD2E0_72E4E0,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData D_802E2F54_734154 = {
    charizard_model,
    charizard_materials,
    renderPokemonModelTypeIFogged,
    &D_802E2F40_734140,
    { 3.5, 3.5, 3.5 },
    { 0, 1088, 0 },
    76,
    POKEMON_FLAG_20 | POKEMON_FLAG_4 | POKEMON_FLAG_1,
    0,
    0,
    0,
    { 0, 0, 0 }
};

POKEMON_FUNC(func_802DD2E0_72E4E0)
    obj->flags |= GOBJ_FLAG_HIDDEN;
    cmdSendCommandToLink(LINK_POKEMON, POKEMON_CMD_32, obj);
    Pokemon_SetState(obj, func_802DD328_72E528);
}

POKEMON_FUNC(func_802DD328_72E528)
    cmdSendCommand(gObjPlayer, PLAYER_CMD_SHAKE_CAMERA, obj);
    obj->flags = 0;
    Pokemon_SetAnimation(obj, &D_802E2E64_734064);
    Pokemon_StartPathProc(obj, func_802DD3B0_72E5B0);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_802DD500_72E700);
}

POKEMON_FUNC(func_802DD3B0_72E5B0)
    GroundResult result;

    Pokemon_TurnToTarget(obj, TAU, MOVEMENT_FLAG_TURN_TO_PLAYER);
    Pokemon_StartAuxProc(obj, func_802DD4A4_72E6A4);
    getGroundAt(position->v.x, position->v.z, &result);
    while (position->v.y + 50.0f < result.height) {
        position->v.y += 5.0f;
        ohWait(1);
    }

    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802DD4A4_72E6A4)
    s32 waitTimer = 48;

    while (waitTimer--) {
        ohWait(1);
    }

    omCreateProcess(obj, func_802D6CFC_727EFC, 1, 1);
    Pokemon_StopAuxProc(obj);
}

POKEMON_FUNC(func_802DD500_72E700)
    Pokemon_ForceAnimation(obj, &D_802E2E78_734078);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E2EC8_7340C8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetStateRandom(obj, D_802E2F28_734128);
}

POKEMON_FUNC(func_802DD570_72E770)
    Pokemon_ForceAnimation(obj, &D_802E2E8C_73408C);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E2EC8_7340C8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetStateRandom(obj, D_802E2F28_734128);
}

POKEMON_FUNC(func_802DD5E0_72E7E0)
    Pokemon_SetAnimation(obj, &D_802E2EA0_7340A0);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    
    Pokemon_SetAnimation(obj, &D_802E2EB4_7340B4);
    Pokemon_StartPathProc(obj, func_802DD67C_72E87C);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetStateRandom(obj, D_802E2F28_734128);
}

POKEMON_FUNC(func_802DD67C_72E87C)
    while (true) {
        Pokemon_TurnToTarget(obj, PI / 180, MOVEMENT_FLAG_TURN_TO_PLAYER);
        ohWait(1);
    }
}

POKEMON_FUNC(func_802DD6D4_72E8D4)
    Pokemon_SetAnimation(obj, &D_802E2EB4_7340B4);
    Pokemon_StartPathProc(obj, func_802DD67C_72E87C);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetStateRandom(obj, D_802E2F28_734128);
}

POKEMON_FUNC(func_802DD740_72E940)
    Pokemon_SetAnimation(obj, &D_802E2EB4_7340B4);
    Pokemon_StartPathProc(obj, func_802DD67C_72E87C);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_802DD500_72E700);
}

GObj* func_802DD7AC_72E9AC(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802E2F54_734154);
}
