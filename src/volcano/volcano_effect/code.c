#include "volcano/volcano.h"

extern UnkEC64Arg3 volcano_effect_model[];
extern Texture** volcano_effect_materials[];
extern AnimCmd* volcano_effect_modelanim[];
extern AnimCmd** volcano_effect_matanim[];

void volcano_effect_InitialState(GObj*);
void func_802DF1B4_7303B4(GObj*);
void func_802DF214_730414(GObj*);
void volcano_effect_Type1(GObj*);
void volcano_effect_Type5(GObj*);
void volcano_effect_Type2(GObj*);
void volcano_effect_Type3(GObj*);
void volcano_effect_Type4(GObj*);
void volcano_effect_Type2Inflate(GObj*);

s32 volcano_effect_animsounds_type5[] = { SOUND_ID_58 };
s32 volcano_effect_animsounds_type1[] = { SOUND_ID_62 };
s32 volcano_effect_animsounds_type3[] = { SOUND_ID_59 };

AnimationHeader volcano_effect_animation_type3 = {
    2,
    100,
    volcano_effect_modelanim,
    volcano_effect_matanim,
    volcano_effect_animsounds_type3
};

AnimationHeader volcano_effect_animation_type1 = {
    2,
    100,
    volcano_effect_modelanim,
    volcano_effect_matanim,
    volcano_effect_animsounds_type1
};

AnimationHeader volcano_effect_animation_type5 = {
    2,
    100,
    volcano_effect_modelanim,
    volcano_effect_matanim,
    volcano_effect_animsounds_type5
};

AnimationHeader volcano_effect_animation_type2 = {
    2,
    100,
    volcano_effect_modelanim,
    volcano_effect_matanim,
    NULL
};

InteractionHandler volcano_effect_tg_Type4[] = {
    { VOLCANO_CMD_34, func_802DF1B4_7303B4, 0, NULL },
    { VOLCANO_CMD_35, func_802DF214_730414, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

PokemonAnimationSetup volcano_effect_animSetup = {
    &volcano_effect_animation_type3,
    volcano_effect_InitialState,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData volcano_effect_initData = {
    volcano_effect_model,
    volcano_effect_materials,
    renderModelTypeDFogged,
    &volcano_effect_animSetup,
    { 10, 10, 10 },
    { 0, 0, 0 },
    0,
    0,
    0,
    0,
    0,
    { 0, 0, 0 }
};

POKEMON_FUNC(volcano_effect_InitialState)
    if (pokemon->behavior == 1) {
        Pokemon_SetState(obj, volcano_effect_Type1);
    }
    if (pokemon->behavior == 5) {
        Pokemon_SetState(obj, volcano_effect_Type5);
    }
    if (pokemon->behavior == 2) {
        Pokemon_SetState(obj, volcano_effect_Type2);
    }
    if (pokemon->behavior == 3) {
        Pokemon_SetState(obj, volcano_effect_Type3);
    }
    if (pokemon->behavior == 4) {
        Pokemon_SetState(obj, volcano_effect_Type4);
    }

    Pokemon_ForceAnimation(obj, &volcano_effect_animation_type3);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    animSetModelAndTextureAnimationSpeed(obj, 0.0f);
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(volcano_effect_Type1)
    Pokemon_ForceAnimation(obj, &volcano_effect_animation_type1);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(volcano_effect_Type5)
    Pokemon_ForceAnimation(obj, &volcano_effect_animation_type5);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(volcano_effect_Type2)
    Pokemon_ForceAnimation(obj, &volcano_effect_animation_type2);
    Pokemon_StartPathProc(obj, volcano_effect_Type2Inflate);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(volcano_effect_Type2Inflate)
    while (true) {
        GET_TRANSFORM(model)->scale.v.x *= 1.04;
        GET_TRANSFORM(model)->scale.v.y *= 1.04;
        GET_TRANSFORM(model)->scale.v.z *= 1.04;
        ohWait(1);
    }
}

POKEMON_FUNC(volcano_effect_Type3)
    Pokemon_ForceAnimation(obj, &volcano_effect_animation_type3);
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
    Pokemon_SetState(obj, volcano_effect_Type3);
}

POKEMON_FUNC(volcano_effect_Type4)
    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_HIDDEN | GOBJ_FLAG_2;

    pokemon->transitionGraph = volcano_effect_tg_Type4;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802DF1B4_7303B4)
    pokemon->tangible = true;
    obj->flags = 0;

    Pokemon_ForceAnimation(obj, &volcano_effect_animation_type3);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, volcano_effect_Type4);
}

POKEMON_FUNC(func_802DF214_730414)
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

GObj* volcano_effect_Spawn(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnDlLink4(objID, id, block, blockB, spawn, &volcano_effect_initData);
}
