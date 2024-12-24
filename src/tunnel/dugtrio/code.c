#include "../tunnel.h"

extern AnimCmd* dugtrio_modelanim_look_around[];
extern AnimCmd* dugtrio_modelanim_turn[];
extern AnimCmd* dugtrio_modelanim_unburrow[];
extern AnimCmd* dugtrio_modelanim_rise[];
extern AnimCmd* dugtrio_modelanim_burrow[];

void dugtrio_FirstIdle(GObj*);
void dugtrio_SecondIdle(GObj*);
void dugtrio_ThirdIdle(GObj*);
void dugtrio_InitialState(GObj*);
void dugtrio_PhotoTaken(GObj*);
void dugtrio_FirstRise(GObj*);
void dugtrio_SecondRise(GObj*);
void dugtrio_ThirdRise(GObj*);

s32 dugtrio_animsounds_rise[] = { SOUND_ID_219 };

AnimationHeader dugtrio_animation_look_around = {
    0.65,
    40,
    dugtrio_modelanim_look_around,
    NULL,
    NULL
};

AnimationHeader dugtrio_animation_turn = {
    0.7,
    70,
    dugtrio_modelanim_turn,
    NULL,
    NULL
};

AnimationHeader dugtrio_animation_unburrow = {
    0.7,
    35,
    dugtrio_modelanim_unburrow,
    NULL,
    NULL
};

AnimationHeader dugtrio_animation_rise = {
    0.7,
    25,
    dugtrio_modelanim_rise,
    NULL,
    dugtrio_animsounds_rise
};

AnimationHeader dugtrio_animation_burrow = {
    0.7,
    35,
    dugtrio_modelanim_burrow,
    NULL,
    NULL
};

InteractionHandler dugtrio_tg_ReadyForPhoto[] = {
    { POKEMON_CMD_24, NULL, 0, dugtrio_PhotoTaken },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler dugtrio_tg_First[] = {
    { TUNNEL_CMD_FIRST_DUGTRIO_SHOW_UP, dugtrio_FirstRise, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler dugtrio_tg_Second[] = {
    { TUNNEL_CMD_SECOND_DUGTRIO_SHOW_UP, dugtrio_SecondRise, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler dugtrio_tg_Third[] = {
    { TUNNEL_CMD_THIRD_DUGTRIO_SHOW_UP, dugtrio_ThirdRise, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

PokemonAnimationSetup dugtrio_animSetup = {
    &dugtrio_animation_look_around,
    dugtrio_InitialState,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData dugtrio_initData = {
    dugtrio_model,
    NULL,
    renderPokemonModelTypeBFogged,
    &dugtrio_animSetup,
    { 1.7, 1.7, 1.7 },
    { 0, 118, 0 },
    47,
    POKEMON_FLAG_4 | POKEMON_FLAG_1,
    0,
    0,
    0,
    { 0, 0, 0 }
};

extern s32 dugtrio_IsPhotoTaken;
extern s32 dugtrio_MissedPhotoCount;

POKEMON_FUNC(dugtrio_InitialState)
    pokemon->flags |= POKEMON_FLAG_8;
    pokemon->miscVars->field0 = pokemon->collisionRadius;
    HIDE_POKEMON();

    if (pokemon->behavior == 1) {
        Pokemon_SetState(obj, dugtrio_FirstIdle);
    }
    if (pokemon->behavior == 2) {
        Pokemon_SetState(obj, dugtrio_SecondIdle);
    }
    if (pokemon->behavior == 3) {
        Pokemon_SetState(obj, dugtrio_ThirdIdle);
    }

    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(dugtrio_PhotoTaken)
    dugtrio_IsPhotoTaken = true;
    Pokemon_StopAuxProc(obj);
}

POKEMON_FUNC(dugtrio_FirstIdle)
    pokemon->transitionGraph = dugtrio_tg_First;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(dugtrio_FirstRise)
    D_802EEEC8_5EBF98 = obj;
    dugtrio_IsPhotoTaken = false;

    pokemon->counter = 60, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    SHOW_POKEMON();
    pokemon->collisionRadius = 0.0f;
    Pokemon_SetAnimation(obj, &dugtrio_animation_unburrow);

    pokemon->counter = 48, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    cmdSendCommandToLink(LINK_POKEMON, TUNNEL_CMD_43, obj);
    pokemon->transitionGraph = NULL;
    pokemon->collisionRadius = pokemon->miscVars[0].field0;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    pokemon->flags &= ~POKEMON_FLAG_8;
    Pokemon_SetAnimation(obj, &dugtrio_animation_rise);
    pokemon->transitionGraph = dugtrio_tg_ReadyForPhoto;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &dugtrio_animation_look_around);
    pokemon->counter = 30; pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED, pokemon->transitionGraph = dugtrio_tg_ReadyForPhoto;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_SetAnimation(obj, &dugtrio_animation_turn);
    pokemon->transitionGraph = dugtrio_tg_ReadyForPhoto;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    pokemon->flags |= POKEMON_FLAG_8;
    pokemon->collisionRadius = 0.0f;
    Pokemon_SetAnimation(obj, &dugtrio_animation_burrow);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    HIDE_POKEMON();

    if (dugtrio_IsPhotoTaken) {
        D_802EEED0_5EBFA0 = 8;
        cmdSendCommandToLink(LINK_POKEMON, TUNNEL_CMD_SECOND_DUGTRIO_SHOW_UP, obj);
    } else {
        cmdSendCommandToLink(LINK_POKEMON, TUNNEL_CMD_FIRST_DIGLETT_SHOW_UP, obj);
    }

    Pokemon_SetState(obj, dugtrio_FirstIdle);
}

POKEMON_FUNC(dugtrio_SecondIdle)
    pokemon->transitionGraph = dugtrio_tg_Second;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(dugtrio_SecondRise)
    dugtrio_MissedPhotoCount = 0;
    D_802EEEC8_5EBF98 = obj;
    dugtrio_IsPhotoTaken = false;

    pokemon->counter = 60, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    SHOW_POKEMON();
    pokemon->collisionRadius = 0.0f;
    Pokemon_SetAnimation(obj, &dugtrio_animation_unburrow);

    pokemon->counter = 48, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    cmdSendCommandToLink(LINK_POKEMON, TUNNEL_CMD_43, obj);
    pokemon->transitionGraph = NULL;
    pokemon->collisionRadius = pokemon->miscVars[0].field0;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    pokemon->flags &= ~POKEMON_FLAG_8;
    Pokemon_SetAnimation(obj, &dugtrio_animation_rise);
    pokemon->transitionGraph = dugtrio_tg_ReadyForPhoto;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &dugtrio_animation_look_around);
    pokemon->counter = 30; pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED, pokemon->transitionGraph = dugtrio_tg_ReadyForPhoto;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_SetAnimation(obj, &dugtrio_animation_turn);
    pokemon->transitionGraph = dugtrio_tg_ReadyForPhoto;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    pokemon->flags |= POKEMON_FLAG_8;
    pokemon->collisionRadius = 0.0f;
    Pokemon_SetAnimation(obj, &dugtrio_animation_burrow);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    HIDE_POKEMON();

    if (dugtrio_IsPhotoTaken) {
        D_802EEED0_5EBFA0 = 0x10;
        D_802EEEC8_5EBF98 = NULL;
        cmdSendCommandToLink(LINK_POKEMON, TUNNEL_CMD_THIRD_DUGTRIO_SHOW_UP, obj);
    } else {
        if (dugtrio_MissedPhotoCount != 0) {
            cmdSendCommandToLink(LINK_POKEMON, TUNNEL_CMD_FIRST_DIGLETT_SHOW_UP, obj);
        }
        dugtrio_MissedPhotoCount++;
    }

    Pokemon_SetState(obj, dugtrio_SecondIdle);
}

POKEMON_FUNC(dugtrio_ThirdIdle)
    pokemon->transitionGraph = dugtrio_tg_Third;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(dugtrio_ThirdRise)
    D_802EEEC8_5EBF98 = obj;

    pokemon->counter = 60, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    SHOW_POKEMON();
    pokemon->collisionRadius = 0.0f;
    Pokemon_SetAnimation(obj, &dugtrio_animation_unburrow);

    pokemon->counter = 48, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    cmdSendCommandToLink(LINK_POKEMON, TUNNEL_CMD_43, obj);
    pokemon->transitionGraph = NULL;
    pokemon->collisionRadius = pokemon->miscVars[0].field0;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    pokemon->flags &= ~POKEMON_FLAG_8;
    Pokemon_SetAnimation(obj, &dugtrio_animation_rise);
    pokemon->transitionGraph = dugtrio_tg_ReadyForPhoto;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &dugtrio_animation_look_around);
    pokemon->counter = 30; pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED, pokemon->transitionGraph = dugtrio_tg_ReadyForPhoto;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_SetAnimation(obj, &dugtrio_animation_turn);
    pokemon->transitionGraph = dugtrio_tg_ReadyForPhoto;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    pokemon->flags |= POKEMON_FLAG_8;
    pokemon->collisionRadius = 0.0f;
    Pokemon_SetAnimation(obj, &dugtrio_animation_burrow);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    HIDE_POKEMON();

    Pokemon_SetState(obj, NULL);
}

GObj* dugtrio_Spawn(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    GObj* obj = Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &dugtrio_initData);
    GET_POKEMON(obj)->tangible = false;
    obj->flags |= GOBJ_FLAG_HIDDEN | GOBJ_FLAG_2;
}

void dugtrio_Remove(GObj* obj) {
    if (D_802EEEC8_5EBF98 == obj) {
        D_802EEEC8_5EBF98 = NULL;
    }
    pokemonRemoveOne(obj);
}
