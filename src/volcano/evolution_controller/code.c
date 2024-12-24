#include "volcano/volcano.h"

extern UnkEC64Arg3 evolution_controller_model[];
extern Texture** evolution_controller_materials[];
extern AnimCmd* evolution_controller_modelanim[];
extern AnimCmd** evolution_controller_matanim[];

void evolution_controller_InitialState(GObj*);
void evolution_controller_CharizardAppeared(GObj*);
void evolution_controller_CharmeleonFellInLava(GObj*);
void evolution_controller_EvolveIntoCharmeleon(GObj*);
void evolution_controller_EvolveIntoCharizard(GObj*);
void evolution_controller_InitialState(GObj*);

__ALIGNER2

s32 evolution_controller_animsounds_charmeleon_evolves[] = { SOUND_ID_60 };
s32 evolution_controller_animsounds_charmander_evolves[] = { SOUND_ID_134 };

AnimationHeader evolution_controller_animation_idle = {
    0.5,
    60,
    evolution_controller_modelanim,
    evolution_controller_matanim,
    NULL
};

AnimationHeader evolution_controller_animation_charmeleon_evolves = {
    0.5,
    60,
    evolution_controller_modelanim,
    evolution_controller_matanim,
    evolution_controller_animsounds_charmeleon_evolves
};

AnimationHeader evolution_controller_animation_charmander_evolves = {
    0.5,
    60,
    evolution_controller_modelanim,
    evolution_controller_matanim,
    evolution_controller_animsounds_charmander_evolves
};

InteractionHandler evolution_controller_tg_Wait[] = {
    { VOLCANO_CMD_CHARMELEON_FELL_IN_LAVA, evolution_controller_CharmeleonFellInLava, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler evolution_controller_tg_Working[] = {
    { VOLCANO_CMD_CHARIZARD_APPEARED, evolution_controller_CharizardAppeared, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

PokemonAnimationSetup evolution_controller_animSetup = {
    &evolution_controller_animation_idle,
    evolution_controller_InitialState,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData evolution_controller_initData = {
    evolution_controller_model,
    evolution_controller_materials,
    renderModelTypeDFogged,
    &evolution_controller_animSetup,
    { 20, 20, 20 },
    { 0, 0, 0 },
    0,
    0,
    0,
    0,
    0,
    { 0, 0, 0 }
};

POKEMON_FUNC(evolution_controller_InitialState)
    if (pokemon->behavior == 1) {
        Pokemon_SetState(obj, evolution_controller_EvolveIntoCharmeleon);
    }

    HIDE_POKEMON();

    pokemon->transitionGraph = evolution_controller_tg_Wait;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

// TODO: figure out if POKEMON_FUNC macro can be used
void evolution_controller_CharmeleonFellInLava(GObj* obj) {
    UNUSED s32 pad[3];
    DObj* model = obj->data.dobj;
    Mtx3Float* position = &GET_TRANSFORM(model)->pos;
    Pokemon* pokemon = GET_POKEMON(obj);
    Mtx3Float* targetPos = &GET_TRANSFORM(pokemon->interactionTarget->data.dobj)->pos;

    if (SQ(position->v.x - targetPos->v.x) + SQ(position->v.z - targetPos->v.z) < 100000.0f) {
        cmdSendCommand(pokemon->interactionTarget, VOLCANO_CMD_CHARMELEON_EVOLVE, obj);
        Pokemon_SetState(obj, evolution_controller_EvolveIntoCharizard);
    }

    Pokemon_SetState(obj, evolution_controller_InitialState);
}

POKEMON_FUNC(evolution_controller_EvolveIntoCharizard)
    pokemon->transitionGraph = evolution_controller_tg_Working;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(evolution_controller_CharizardAppeared)
    SHOW_POKEMON();
    Pokemon_ForceAnimation(obj, &evolution_controller_animation_charmeleon_evolves);
    Pokemon_StartPathProc(obj, NULL);
    cmdSendCommandToLink(LINK_POKEMON, VOLCANO_CMD_UNUSED_CHARIZARD, obj);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(evolution_controller_EvolveIntoCharmeleon)
    SHOW_POKEMON();
    Pokemon_StartPathProc(obj, NULL);
    Pokemon_ForceAnimation(obj, &evolution_controller_animation_charmander_evolves);
    pokemon->counter = 20, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    EnvSound_PlaySound(obj, 1, SOUND_ID_395);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    cmdSendCommandToLink(LINK_POKEMON, VOLCANO_CMD_CHARMANDER_EVOLVE, obj);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

GObj* evolution_controller_Spawn(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnOnGroundDlLink4(objID, id, block, blockB, spawn, &evolution_controller_initData);
}

void func_802DED6C_72FF6C(GObj* obj) {
    PokemonDef def = {
        PokemonID_EVOLUTION_CONTROLLER,
        evolution_controller_Spawn,
        pokemonChangeBlockOnGround,
        pokemonRemoveOne
    };
    GObj* var;

    var = Pokemon_AddAtGeo(obj, PokemonID_LAVA_SPLASH, &def);
    GET_POKEMON(var)->behavior = 1;
}
