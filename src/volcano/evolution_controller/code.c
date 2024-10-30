#include "volcano/volcano.h"

extern UnkEC64Arg3 evolution_controller_model[];
extern Texture** evolution_controller_materials[];
extern AnimCmd* evolution_controller_modelanim[];
extern AnimCmd** evolution_controller_matanim[];

void evolution_controller_InitialState(GObj*);
void func_802DEBF0_72FDF0(GObj*);
void func_802DEAFC_72FCFC(GObj*);
void evolution_controller_EvolveIntoCharmeleon(GObj*);
void evolution_controller_EvolveIntoCharizard(GObj*);
void evolution_controller_InitialState(GObj*);

s32 D_802E3410_734610[] = { SOUND_ID_60 };
s32 D_802E3414_734614[] = { SOUND_ID_134 };

AnimationHeader D_802E3418_734618 = {
    0.5,
    60,
    evolution_controller_modelanim,
    evolution_controller_matanim,
    NULL
};

AnimationHeader D_802E342C_73462C = {
    0.5,
    60,
    evolution_controller_modelanim,
    evolution_controller_matanim,
    D_802E3410_734610
};

AnimationHeader D_802E3440_734640 = {
    0.5,
    60,
    evolution_controller_modelanim,
    evolution_controller_matanim,
    D_802E3414_734614
};

InteractionHandler evolution_controller_tg_Wait[] = {
    { VOLCANO_CMD_CHARMELEON_FELL_IN_LAVA, func_802DEAFC_72FCFC, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E3474_734674[] = {
    { VOLCANO_CMD_CHARIZARD_APPEARED, func_802DEBF0_72FDF0, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

PokemonAnimationSetup evolution_controller_animSetup = {
    &D_802E3418_734618,
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

    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_HIDDEN | GOBJ_FLAG_2;

    pokemon->transitionGraph = evolution_controller_tg_Wait;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

// TODO: figure out if POKEMON_FUNC macro can be used
void func_802DEAFC_72FCFC(GObj* obj) {
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
    pokemon->transitionGraph = D_802E3474_734674;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802DEBF0_72FDF0)
    pokemon->tangible = true;
    obj->flags = 0;

    Pokemon_ForceAnimation(obj, &D_802E342C_73462C);
    Pokemon_StartPathProc(obj, NULL);
    cmdSendCommandToLink(LINK_POKEMON, VOLCANO_CMD_UNUSED_CHARIZARD, obj);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(evolution_controller_EvolveIntoCharmeleon)
    pokemon->tangible = true;
    obj->flags = 0;

    Pokemon_StartPathProc(obj, NULL);
    Pokemon_ForceAnimation(obj, &D_802E3440_734640);
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
