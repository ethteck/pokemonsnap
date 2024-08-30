#include "volcano/volcano.h"

extern UnkEC64Arg3 D_800F5490[];
extern Texture** D_800F41D0[];
extern AnimCmd* D_800F55F0[];
extern AnimCmd** D_800F58C0[];

void func_802DEA80_72FC80(GObj*);
void func_802DEBF0_72FDF0(GObj*);
void func_802DEAFC_72FCFC(GObj*);
void func_802DEC78_72FE78(GObj*);
void func_802DEBB0_72FDB0(GObj*);
void func_802DEA80_72FC80(GObj*);

s32 D_802E3410_734610[] = { SOUND_ID_60 };
s32 D_802E3414_734614[] = { SOUND_ID_134 };

AnimationHeader D_802E3418_734618 = {
    0.5,
    60,
    D_800F55F0,
    D_800F58C0,
    NULL
};

AnimationHeader D_802E342C_73462C = {
    0.5,
    60,
    D_800F55F0,
    D_800F58C0,
    D_802E3410_734610
};

AnimationHeader D_802E3440_734640 = {
    0.5,
    60,
    D_800F55F0,
    D_800F58C0,
    D_802E3414_734614
};

InteractionHandler D_802E3454_734654[] = {
    { VOLCANO_CMD_28, func_802DEAFC_72FCFC, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E3474_734674[] = {
    { VOLCANO_CMD_32, func_802DEBF0_72FDF0, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

PokemonAnimationSetup D_802E3494_734694 = {
    &D_802E3418_734618,
    func_802DEA80_72FC80,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData D_802E34A8_7346A8 = {
    D_800F5490,
    D_800F41D0,
    renderModelTypeDFogged,
    &D_802E3494_734694,
    { 20, 20, 20 },
    { 0, 0, 0 },
    0,
    0,
    0,
    0,
    0,
    { 0, 0, 0 }
};

PokemonDef D_802E34DC_7346DC = {
    PokemonID_1002,
    func_802DED34_72FF34,
    pokemonChangeBlockOnGround,
    pokemonRemoveOne
};

POKEMON_FUNC(func_802DEA80_72FC80)
    if (pokemon->behavior == 1) {
        Pokemon_SetState(obj, func_802DEC78_72FE78);
    }

    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_HIDDEN | GOBJ_FLAG_2;

    pokemon->transitionGraph = D_802E3454_734654;
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
        Pokemon_SetState(obj, func_802DEBB0_72FDB0);
    }

    Pokemon_SetState(obj, func_802DEA80_72FC80);
}

POKEMON_FUNC(func_802DEBB0_72FDB0)
    pokemon->transitionGraph = D_802E3474_734674;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802DEBF0_72FDF0)
    pokemon->tangible = true;
    obj->flags = 0;

    Pokemon_ForceAnimation(obj, &D_802E342C_73462C);
    Pokemon_StartPathProc(obj, NULL);
    cmdSendCommandToLink(LINK_POKEMON, VOLCANO_CMD_31, obj);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802DEC78_72FE78)
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

GObj* func_802DED34_72FF34(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnOnGroundDlLink4(objID, id, block, blockB, spawn, &D_802E34A8_7346A8);
}

void func_802DED6C_72FF6C(GObj* obj) {    
    PokemonDef def = D_802E34DC_7346DC;
    GObj* var; 

    var = Pokemon_AddAtGeo(obj, PokemonID_1030, &def);
    GET_POKEMON(var)->behavior = 1;
}
