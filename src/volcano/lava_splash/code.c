#include "volcano/volcano.h"

extern UnkEC64Arg3 lava_splash_model[];
extern Texture** lava_splash_materials[];
extern AnimCmd* lava_splash_modelanim[];
extern AnimCmd** lava_splash_matanim[];

void lava_splash_InitialState(GObj*);
void func_802DF1B4_7303B4(GObj*);
void func_802DF214_730414(GObj*);
void lava_splash_Type1(GObj*);
void lava_splash_Type5(GObj*);
void lava_splash_Type2(GObj*);
void lava_splash_Type3(GObj*);
void lava_splash_Type4(GObj*);
void lava_splash_Type2Inflate(GObj*);

s32 lava_splash_animsounds_type5[] = { SOUND_ID_58 };
s32 lava_splash_animsounds_type1[] = { SOUND_ID_62 };
s32 lava_splash_animsounds_type3[] = { SOUND_ID_59 };

AnimationHeader lava_splash_animation_type3 = {
    2,
    100,
    lava_splash_modelanim,
    lava_splash_matanim,
    lava_splash_animsounds_type3
};

AnimationHeader lava_splash_animation_type1 = {
    2,
    100,
    lava_splash_modelanim,
    lava_splash_matanim,
    lava_splash_animsounds_type1
};

AnimationHeader lava_splash_animation_type5 = {
    2,
    100,
    lava_splash_modelanim,
    lava_splash_matanim,
    lava_splash_animsounds_type5
};

AnimationHeader lava_splash_animation_type2 = {
    2,
    100,
    lava_splash_modelanim,
    lava_splash_matanim,
    NULL
};

InteractionHandler lava_splash_tg_Type4[] = {
    { VOLCANO_CMD_34, func_802DF1B4_7303B4, 0, NULL },
    { VOLCANO_CMD_35, func_802DF214_730414, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

PokemonAnimationSetup lava_splash_animSetup = {
    &lava_splash_animation_type3,
    lava_splash_InitialState,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData lava_splash_initData = {
    lava_splash_model,
    lava_splash_materials,
    renderModelTypeDFogged,
    &lava_splash_animSetup,
    { 10, 10, 10 },
    { 0, 0, 0 },
    0,
    0,
    0,
    0,
    0,
    { 0, 0, 0 }
};

POKEMON_FUNC(lava_splash_InitialState)
    if (pokemon->behavior == 1) {
        Pokemon_SetState(obj, lava_splash_Type1);
    }
    if (pokemon->behavior == 5) {
        Pokemon_SetState(obj, lava_splash_Type5);
    }
    if (pokemon->behavior == 2) {
        Pokemon_SetState(obj, lava_splash_Type2);
    }
    if (pokemon->behavior == 3) {
        Pokemon_SetState(obj, lava_splash_Type3);
    }
    if (pokemon->behavior == 4) {
        Pokemon_SetState(obj, lava_splash_Type4);
    }

    Pokemon_ForceAnimation(obj, &lava_splash_animation_type3);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    animSetModelAndTextureAnimationSpeed(obj, 0.0f);
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(lava_splash_Type1)
    Pokemon_ForceAnimation(obj, &lava_splash_animation_type1);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(lava_splash_Type5)
    Pokemon_ForceAnimation(obj, &lava_splash_animation_type5);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(lava_splash_Type2)
    Pokemon_ForceAnimation(obj, &lava_splash_animation_type2);
    Pokemon_StartPathProc(obj, lava_splash_Type2Inflate);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(lava_splash_Type2Inflate)
    while (true) {
        GET_TRANSFORM(model)->scale.v.x *= 1.04;
        GET_TRANSFORM(model)->scale.v.y *= 1.04;
        GET_TRANSFORM(model)->scale.v.z *= 1.04;
        ohWait(1);
    }
}

POKEMON_FUNC(lava_splash_Type3)
    Pokemon_ForceAnimation(obj, &lava_splash_animation_type3);
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
    Pokemon_SetState(obj, lava_splash_Type3);
}

POKEMON_FUNC(lava_splash_Type4)
    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_HIDDEN | GOBJ_FLAG_2;

    pokemon->transitionGraph = lava_splash_tg_Type4;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802DF1B4_7303B4)
    pokemon->tangible = true;
    obj->flags = 0;

    Pokemon_ForceAnimation(obj, &lava_splash_animation_type3);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, lava_splash_Type4);
}

POKEMON_FUNC(func_802DF214_730414)
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

GObj* lava_splash_Spawn(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnDlLink4(objID, id, block, blockB, spawn, &lava_splash_initData);
}
