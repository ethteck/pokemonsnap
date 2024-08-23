#include "volcano/volcano.h"

extern UnkEC64Arg3 D_80114660[];
extern Texture** D_80114710[];
extern AnimCmd* D_80114840[];
extern AnimCmd** D_80114980[];

void func_802DEDE0_72FFE0(GObj*);
void func_802DF1B4_7303B4(GObj*);
void func_802DF214_730414(GObj*);
void func_802DEEE0_7300E0(GObj*);
void func_802DEF4C_73014C(GObj*);
void func_802DEFB8_7301B8(GObj*);
void func_802DF0B4_7302B4(GObj*);
void func_802DF164_730364(GObj*);
void func_802DF028_730228(GObj*);

s32 D_802E34F0_7346F0[] = { SOUND_ID_58 };
s32 D_802E34F4_7346F4[] = { SOUND_ID_62 };
s32 D_802E34F8_7346F8[] = { SOUND_ID_59 };

AnimationHeader D_802E34FC_7346FC = {
    2,
    100,
    D_80114840,
    D_80114980,
    D_802E34F8_7346F8
};

AnimationHeader D_802E3510_734710 = {
    2,
    100,
    D_80114840,
    D_80114980,
    D_802E34F4_7346F4
};

AnimationHeader D_802E3524_734724 = {
    2,
    100,
    D_80114840,
    D_80114980,
    D_802E34F0_7346F0
};

AnimationHeader D_802E3538_734738 = {
    2,
    100,
    D_80114840,
    D_80114980,
    NULL
};

InteractionHandler D_802E354C_73474C[] = {
    { POKEMON_CMD_34, func_802DF1B4_7303B4, 0, NULL },
    { POKEMON_CMD_35, func_802DF214_730414, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

PokemonAnimationSetup D_802E357C_73477C = {
    &D_802E34FC_7346FC,
    func_802DEDE0_72FFE0,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData D_802E3590_734790 = {
    D_80114660,
    D_80114710,
    renderModelTypeDFogged,
    &D_802E357C_73477C,
    { 10, 10, 10 },
    { 0, 0, 0 },
    0,
    0,
    0,
    0,
    0,
    { 0, 0, 0 }
};

POKEMON_FUNC(func_802DEDE0_72FFE0)
    if (pokemon->behavior == 1) {
        Pokemon_SetState(obj, func_802DEEE0_7300E0);
    }
    if (pokemon->behavior == 5) {
        Pokemon_SetState(obj, func_802DEF4C_73014C);
    }
    if (pokemon->behavior == 2) {
        Pokemon_SetState(obj, func_802DEFB8_7301B8);
    }
    if (pokemon->behavior == 3) {
        Pokemon_SetState(obj, func_802DF0B4_7302B4);
    }
    if (pokemon->behavior == 4) {
        Pokemon_SetState(obj, func_802DF164_730364);
    }

    Pokemon_ForceAnimation(obj, &D_802E34FC_7346FC);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    animSetModelAndTextureAnimationSpeed(obj, 0.0f);
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802DEEE0_7300E0)
    Pokemon_ForceAnimation(obj, &D_802E3510_734710);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802DEF4C_73014C)
    Pokemon_ForceAnimation(obj, &D_802E3524_734724);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802DEFB8_7301B8)
    Pokemon_ForceAnimation(obj, &D_802E3538_734738);
    Pokemon_StartPathProc(obj, func_802DF028_730228);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802DF028_730228)
    while (true) {
        GET_TRANSFORM(model)->scale.v.x *= 1.04;
        GET_TRANSFORM(model)->scale.v.y *= 1.04;
        GET_TRANSFORM(model)->scale.v.z *= 1.04;
        ohWait(1);
    }
}

POKEMON_FUNC(func_802DF0B4_7302B4)
    Pokemon_ForceAnimation(obj, &D_802E34FC_7346FC);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_HIDDEN | GOBJ_FLAG_2;

    pokemon->counter = randRange(180) + 60, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    pokemon->tangible = true;
    obj->flags = 0;
    Pokemon_SetState(obj, func_802DF0B4_7302B4);
}

POKEMON_FUNC(func_802DF164_730364)
    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_HIDDEN | GOBJ_FLAG_2;

    pokemon->transitionGraph = D_802E354C_73474C;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802DF1B4_7303B4)
    pokemon->tangible = true;
    obj->flags = 0;

    Pokemon_ForceAnimation(obj, &D_802E34FC_7346FC);

    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802DF164_730364);
}

POKEMON_FUNC(func_802DF214_730414)
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

GObj* func_802DF240_730440(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnDlLink4(objID, id, block, blockB, spawn, &D_802E3590_734790);
}
