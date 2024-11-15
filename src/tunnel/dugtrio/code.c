#include "../tunnel.h"

//extern AnimCmd* diglett_modelanim_look_around[];
//extern AnimCmd* diglett_modelanim_turn[];
//extern AnimCmd* diglett_modelanim_unburrow[];
//extern AnimCmd* diglett_modelanim_rise[];
//extern AnimCmd* diglett_modelanim_burrow[];

void func_802E6574_5E3644(GObj*);
void func_802E67B8_5E3888(GObj*);
void func_802E6A30_5E3B00(GObj*);
void func_802E6490_5E3560(GObj*);
void func_802E654C_5E361C(GObj*);
void func_802E65B4_5E3684(GObj*);
void func_802E67F8_5E38C8(GObj*);
void func_802E6A70_5E3B40(GObj*);

s32 dugtrio_animsounds_rise[] = { SOUND_ID_219 };

AnimationHeader D_802EEAC4_5EBB94 = {
    0.65,
    40,
    0x80165250,
    NULL,
    NULL
};

AnimationHeader D_802EEAD8_5EBBA8 = {
    0.7,
    70,
    0x80165F90,
    NULL,
    NULL
};

AnimationHeader D_802EEAEC_5EBBBC = {
    0.7,
    35,
    0x80167220,
    NULL,
    NULL
};

AnimationHeader D_802EEB00_5EBBD0 = {
    0.7,
    25,
    0x80166B50,
    NULL,
    dugtrio_animsounds_rise
};

AnimationHeader D_802EEB14_5EBBE4 = {
    0.7,
    35,
    0x80165B30,
    NULL,
    NULL
};

InteractionHandler D_802EEB28_5EBBF8[] = {
    { POKEMON_CMD_24, NULL, 0, func_802E654C_5E361C },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802EEB48_5EBC18[] = {
    { TUNNEL_CMD_34, func_802E65B4_5E3684, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802EEB68_5EBC38[] = {
    { TUNNEL_CMD_35, func_802E67F8_5E38C8, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802EEB88_5EBC58[] = {
    { TUNNEL_CMD_36, func_802E6A70_5E3B40, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

PokemonAnimationSetup dugtrio_animSetup = {
    &D_802EEAC4_5EBB94,
    func_802E6490_5E3560,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData D_802EEBBC_5EBC8C = {
    0x80330670,
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

extern s32 D_80343148_640218;
extern s32 D_8034314C_64021C;

POKEMON_FUNC(func_802E6490_5E3560)
    pokemon->tangible = false;
    pokemon->flags |= POKEMON_FLAG_8;
    pokemon->miscVars->field0 = pokemon->collisionRadius;
    obj->flags |= GOBJ_FLAG_HIDDEN | GOBJ_FLAG_2;

    if (pokemon->behavior == 1) {
        Pokemon_SetState(obj, func_802E6574_5E3644);
    }
    if (pokemon->behavior == 2) {
        Pokemon_SetState(obj, func_802E67B8_5E3888);
    }
    if (pokemon->behavior == 3) {
        Pokemon_SetState(obj, func_802E6A30_5E3B00);
    }

    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802E654C_5E361C)
    D_80343148_640218 = true;
    Pokemon_StopAuxProc(obj);
}

POKEMON_FUNC(func_802E6574_5E3644)
    pokemon->transitionGraph = D_802EEB48_5EBC18;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802E65B4_5E3684)
    D_802EEEC8_5EBF98 = obj;
    D_80343148_640218 = false;

    pokemon->counter = 60, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    pokemon->tangible = true;
    obj->flags = 0;
    pokemon->collisionRadius = 0.0f;
    Pokemon_SetAnimation(obj, &D_802EEAEC_5EBBBC);

    pokemon->counter = 48, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    cmdSendCommandToLink(LINK_POKEMON, TUNNEL_CMD_43, obj);
    pokemon->transitionGraph = NULL;
    pokemon->collisionRadius = pokemon->miscVars[0].field0;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    pokemon->flags &= ~POKEMON_FLAG_8;
    Pokemon_SetAnimation(obj, &D_802EEB00_5EBBD0);
    pokemon->transitionGraph = D_802EEB28_5EBBF8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &D_802EEAC4_5EBB94);
    pokemon->counter = 30; pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED, pokemon->transitionGraph = D_802EEB28_5EBBF8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_SetAnimation(obj, &D_802EEAD8_5EBBA8);
    pokemon->transitionGraph = D_802EEB28_5EBBF8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    pokemon->flags |= POKEMON_FLAG_8;
    pokemon->collisionRadius = 0.0f;
    Pokemon_SetAnimation(obj, &D_802EEB14_5EBBE4);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_HIDDEN | GOBJ_FLAG_2;

    if (D_80343148_640218) {
        D_802EEED0_5EBFA0 = 8;
        cmdSendCommandToLink(LINK_POKEMON, TUNNEL_CMD_35, obj);
    } else {
        cmdSendCommandToLink(LINK_POKEMON, TUNNEL_CMD_FIRST_DIGLETT_SHOW_UP, obj);
    }

    Pokemon_SetState(obj, func_802E6574_5E3644);
}

POKEMON_FUNC(func_802E67B8_5E3888)
    pokemon->transitionGraph = D_802EEB68_5EBC38;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802E67F8_5E38C8)
    D_8034314C_64021C = 0;
    D_802EEEC8_5EBF98 = obj;
    D_80343148_640218 = false;

    pokemon->counter = 60, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    pokemon->tangible = true;
    obj->flags = 0;
    pokemon->collisionRadius = 0.0f;
    Pokemon_SetAnimation(obj, &D_802EEAEC_5EBBBC);

    pokemon->counter = 48, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    cmdSendCommandToLink(LINK_POKEMON, TUNNEL_CMD_43, obj);
    pokemon->transitionGraph = NULL;
    pokemon->collisionRadius = pokemon->miscVars[0].field0;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    pokemon->flags &= ~POKEMON_FLAG_8;
    Pokemon_SetAnimation(obj, &D_802EEB00_5EBBD0);
    pokemon->transitionGraph = D_802EEB28_5EBBF8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &D_802EEAC4_5EBB94);
    pokemon->counter = 30; pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED, pokemon->transitionGraph = D_802EEB28_5EBBF8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_SetAnimation(obj, &D_802EEAD8_5EBBA8);
    pokemon->transitionGraph = D_802EEB28_5EBBF8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    pokemon->flags |= POKEMON_FLAG_8;
    pokemon->collisionRadius = 0.0f;
    Pokemon_SetAnimation(obj, &D_802EEB14_5EBBE4);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_HIDDEN | GOBJ_FLAG_2;

    if (D_80343148_640218) {
        D_802EEED0_5EBFA0 = 0x10;
        D_802EEEC8_5EBF98 = 0;
        cmdSendCommandToLink(LINK_POKEMON, TUNNEL_CMD_36, obj);
    } else {
        if (D_8034314C_64021C != 0) {
            cmdSendCommandToLink(LINK_POKEMON, TUNNEL_CMD_FIRST_DIGLETT_SHOW_UP, obj);
        }
        D_8034314C_64021C++;
    }

    Pokemon_SetState(obj, func_802E67B8_5E3888);
}

POKEMON_FUNC(func_802E6A30_5E3B00)
    pokemon->transitionGraph = D_802EEB88_5EBC58;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802E6A70_5E3B40)
    D_802EEEC8_5EBF98 = obj;

    pokemon->counter = 60, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    pokemon->tangible = true;
    obj->flags = 0;
    pokemon->collisionRadius = 0.0f;
    Pokemon_SetAnimation(obj, &D_802EEAEC_5EBBBC);

    pokemon->counter = 48, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    cmdSendCommandToLink(LINK_POKEMON, TUNNEL_CMD_43, obj);
    pokemon->transitionGraph = NULL;
    pokemon->collisionRadius = pokemon->miscVars[0].field0;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    pokemon->flags &= ~POKEMON_FLAG_8;
    Pokemon_SetAnimation(obj, &D_802EEB00_5EBBD0);
    pokemon->transitionGraph = D_802EEB28_5EBBF8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &D_802EEAC4_5EBB94);
    pokemon->counter = 30; pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED, pokemon->transitionGraph = D_802EEB28_5EBBF8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_SetAnimation(obj, &D_802EEAD8_5EBBA8);
    pokemon->transitionGraph = D_802EEB28_5EBBF8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    pokemon->flags |= POKEMON_FLAG_8;
    pokemon->collisionRadius = 0.0f;
    Pokemon_SetAnimation(obj, &D_802EEB14_5EBBE4);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_HIDDEN | GOBJ_FLAG_2;

    Pokemon_SetState(obj, NULL);
}

GObj* dugtrio_Spawn(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    GObj* obj = Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802EEBBC_5EBC8C);
    GET_POKEMON(obj)->tangible = false;
    obj->flags |= GOBJ_FLAG_HIDDEN | GOBJ_FLAG_2;
}

void func_802E6C74_5E3D44(GObj* obj) {
    if (D_802EEEC8_5EBF98 == obj) {
        D_802EEEC8_5EBF98 = NULL;
    }
    pokemonRemoveOne(obj);
}
