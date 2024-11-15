#include "../tunnel.h"

void diglett_FirstRise(GObj*);
void diglett_SecondIdle(GObj*);
void diglett_ThirdIdle(GObj*);
void diglett_InitialState(GObj*);
void diglett_PhotoTaken(GObj*);
void diglett_SecondRise(GObj*);
void diglett_ThirdRise(GObj*);

s32 diglett_animsounds_rise[] = { SOUND_ID_218 };

AnimationHeader diglett_animation_look_around = {
    0.55,
    60,
    0x80161D70,
    0x80163BC0,
    NULL
};

AnimationHeader diglett_animation_turn = {
    0.65,
    25,
    0x80162570,
    NULL,
    NULL
};

AnimationHeader diglett_animation_unburrow = {
    0.6,
    70,
    0x80162EB0,
    0x80163E20,
    NULL
};

AnimationHeader diglett_animation_rise = {
    0.6,
    10,
    0x80162960,
    0x80163D40,
    diglett_animsounds_rise
};

AnimationHeader diglett_animation_burrow = {
    0.65,
    25,
    0x801622F0,
    NULL,
    NULL
};

InteractionHandler diglett_tg_ReadyForPhoto[] = {
    { POKEMON_CMD_24, NULL, 0, diglett_PhotoTaken },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler diglett_tg_First[] = {
    { TUNNEL_CMD_FIRST_DIGLETT_SHOW_UP, diglett_FirstRise, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler diglett_tg_Second[] = {
    { TUNNEL_CMD_SECOND_DIGLETT_SHOW_UP, diglett_SecondRise, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler diglett_tg_Third[] = {
    { TUNNEL_CMD_THIRD_DIGLETT_SHOW_UP, diglett_ThirdRise, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

PokemonAnimationSetup diglett_animSetup = {
    &diglett_animation_look_around,
    diglett_InitialState,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData diglett_initData = {
    diglett_model,
    diglett_materials,
    renderPokemonModelTypeBFogged,
    &diglett_animSetup,
    { 2.4, 2.4, 2.4 },
    { 0, 47, 0 },
    13,
    POKEMON_FLAG_4 | POKEMON_FLAG_1,
    0,
    0,
    0,
    { 0, 0, 0 }
};

extern s32 diglett_IsPhotoTaken;

POKEMON_FUNC(diglett_InitialState)
    pokemon->tangible = false;
    pokemon->flags |= POKEMON_FLAG_8;
    pokemon->miscVars->field0 = pokemon->collisionRadius;
    obj->flags |= GOBJ_FLAG_HIDDEN | GOBJ_FLAG_2;

    if (pokemon->behavior == 1) {
        Pokemon_SetState(obj, diglett_FirstRise);
    }
    if (pokemon->behavior == 2) {
        Pokemon_SetState(obj, diglett_SecondIdle);
    }
    if (pokemon->behavior == 3) {
        Pokemon_SetState(obj, diglett_ThirdIdle);
    }

    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(diglett_PhotoTaken)
    diglett_IsPhotoTaken = true;
    Pokemon_StopAuxProc(obj);
}

POKEMON_FUNC(diglett_FirstRise)
    D_802EEEC4_5EBF94 = obj;
    diglett_IsPhotoTaken = false;

    pokemon->counter = 60, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    pokemon->tangible = true;
    obj->flags = 0;
    pokemon->collisionRadius = 0.0f;
    Pokemon_SetAnimation(obj, &diglett_animation_unburrow);

    pokemon->counter = 110, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    cmdSendCommandToLink(LINK_POKEMON, TUNNEL_CMD_43, obj);
    pokemon->transitionGraph = NULL;
    pokemon->collisionRadius = pokemon->miscVars[0].field0;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    pokemon->flags &= ~POKEMON_FLAG_8;
    Pokemon_SetAnimation(obj, &diglett_animation_rise);
    pokemon->transitionGraph = diglett_tg_ReadyForPhoto;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &diglett_animation_look_around);
    pokemon->counter = 30; pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED, pokemon->transitionGraph = diglett_tg_ReadyForPhoto;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_SetAnimation(obj, &diglett_animation_turn);
    pokemon->transitionGraph = diglett_tg_ReadyForPhoto;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    pokemon->flags |= POKEMON_FLAG_8;
    pokemon->collisionRadius = 0.0f;
    Pokemon_SetAnimation(obj, &diglett_animation_burrow);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_HIDDEN | GOBJ_FLAG_2;

    if (diglett_IsPhotoTaken) {
        D_802EEED0_5EBFA0 = 1;
        cmdSendCommandToLink(LINK_POKEMON, TUNNEL_CMD_SECOND_DIGLETT_SHOW_UP, obj);
        pokemon->transitionGraph = diglett_tg_First;
        Pokemon_WaitForFlag(obj, 0);
    }

    Pokemon_SetState(obj, diglett_FirstRise);
}

POKEMON_FUNC(diglett_SecondIdle)
    pokemon->transitionGraph = diglett_tg_Second;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(diglett_SecondRise)
    D_802EEEC4_5EBF94 = obj;
    diglett_IsPhotoTaken = false;

    pokemon->counter = 60, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    pokemon->tangible = true;
    obj->flags = 0;
    pokemon->collisionRadius = 0.0f;
    Pokemon_SetAnimation(obj, &diglett_animation_unburrow);

    pokemon->counter = 110, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    cmdSendCommandToLink(LINK_POKEMON, TUNNEL_CMD_43, obj);
    pokemon->transitionGraph = NULL;
    pokemon->collisionRadius = pokemon->miscVars[0].field0;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    pokemon->flags &= ~POKEMON_FLAG_8;
    Pokemon_SetAnimation(obj, &diglett_animation_rise);
    pokemon->transitionGraph = diglett_tg_ReadyForPhoto;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &diglett_animation_look_around);
    pokemon->counter = 30; pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED, pokemon->transitionGraph = diglett_tg_ReadyForPhoto;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_SetAnimation(obj, &diglett_animation_turn);
    pokemon->transitionGraph = diglett_tg_ReadyForPhoto;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    pokemon->flags |= POKEMON_FLAG_8;
    pokemon->collisionRadius = 0.0f;
    Pokemon_SetAnimation(obj, &diglett_animation_burrow);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_HIDDEN | GOBJ_FLAG_2;

    if (diglett_IsPhotoTaken) {
        D_802EEED0_5EBFA0 = 2;
        cmdSendCommandToLink(LINK_POKEMON, TUNNEL_CMD_THIRD_DIGLETT_SHOW_UP, obj);
    } else {
        cmdSendCommandToLink(LINK_POKEMON, TUNNEL_CMD_FIRST_DIGLETT_SHOW_UP, obj);
    }

    Pokemon_SetState(obj, diglett_SecondIdle);
}

POKEMON_FUNC(diglett_ThirdIdle)
    pokemon->transitionGraph = diglett_tg_Third;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(diglett_ThirdRise)
    D_802EEEC4_5EBF94 = obj;
    diglett_IsPhotoTaken = false;

    pokemon->counter = 60, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    pokemon->tangible = true;
    obj->flags = 0;
    pokemon->collisionRadius = 0.0f;
    Pokemon_SetAnimation(obj, &diglett_animation_unburrow);

    pokemon->counter = 110, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    cmdSendCommandToLink(LINK_POKEMON, TUNNEL_CMD_43, obj);
    pokemon->transitionGraph = NULL;
    pokemon->collisionRadius = pokemon->miscVars[0].field0;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    pokemon->flags &= ~POKEMON_FLAG_8;
    Pokemon_SetAnimation(obj, &diglett_animation_rise);
    pokemon->transitionGraph = diglett_tg_ReadyForPhoto;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &diglett_animation_look_around);
    pokemon->counter = 30; pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED, pokemon->transitionGraph = diglett_tg_ReadyForPhoto;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_SetAnimation(obj, &diglett_animation_turn);
    pokemon->transitionGraph = diglett_tg_ReadyForPhoto;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    pokemon->flags |= POKEMON_FLAG_8;
    pokemon->collisionRadius = 0.0f;
    Pokemon_SetAnimation(obj, &diglett_animation_burrow);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_HIDDEN | GOBJ_FLAG_2;

    if (diglett_IsPhotoTaken) {
        D_802EEED0_5EBFA0 = 4;
        cmdSendCommandToLink(LINK_POKEMON, TUNNEL_CMD_34, obj);
    } else {
        cmdSendCommandToLink(LINK_POKEMON, TUNNEL_CMD_FIRST_DIGLETT_SHOW_UP, obj);
    }

    Pokemon_SetState(obj, diglett_ThirdIdle);
}

GObj* diglett_Spawn(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &diglett_initData);
}

void diglett_Remove(GObj* obj) {
    if (D_802EEEC4_5EBF94 == obj) {
        D_802EEEC4_5EBF94 = NULL;
    }
    pokemonRemoveOne(obj);
}
