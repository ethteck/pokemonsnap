#include "../tunnel.h"

void func_802E5D94_5E2E64(GObj*);
void func_802E5F98_5E3068(GObj*);
void func_802E61DC_5E32AC(GObj*);
void func_802E5CB0_5E2D80(GObj*);
void func_802E5D6C_5E2E3C(GObj*);
void func_802E5FD8_5E30A8(GObj*);
void func_802E621C_5E32EC(GObj*);

s32 D_802EE990_5EBA60[] = { SOUND_ID_218 };

AnimationHeader D_802EE994_5EBA64 = {
    0.55,
    60,
    0x80161D70,
    0x80163BC0,
    NULL
};

AnimationHeader D_802EE9A8_5EBA78 = {
    0.65,
    25,
    0x80162570,
    NULL,
    NULL
};

AnimationHeader D_802EE9BC_5EBA8C = {
    0.6,
    70,
    0x80162EB0,
    0x80163E20,
    NULL
};

AnimationHeader D_802EE9D0_5EBAA0 = {
    0.6,
    10,
    0x80162960,
    0x80163D40,
    D_802EE990_5EBA60
};

AnimationHeader D_802EE9E4_5EBAB4 = {
    0.65,
    25,
    0x801622F0,
    NULL,
    NULL
};

InteractionHandler D_802EE9F8_5EBAC8[] = {
    { POKEMON_CMD_24, NULL, 0, func_802E5D6C_5E2E3C },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802EEA18_5EBAE8[] = {
    { TUNNEL_CMD_31, func_802E5D94_5E2E64, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802EEA38_5EBB08[] = {
    { TUNNEL_CMD_32, func_802E5FD8_5E30A8, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802EEA58_5EBB28[] = {
    { TUNNEL_CMD_33, func_802E621C_5E32EC, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

PokemonAnimationSetup D_802EEA78_5EBB48 = {
    &D_802EE994_5EBA64,
    func_802E5CB0_5E2D80,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData D_802EEA8C_5EBB5C = {
    0x8032E3D0,
    0x8032C3C0,
    renderPokemonModelTypeBFogged,
    &D_802EEA78_5EBB48,
    { 2.4, 2.4, 2.4 },
    { 0, 47, 0 },
    13,
    POKEMON_FLAG_4 | POKEMON_FLAG_1,
    0,
    0,
    0,
    { 0, 0, 0 }
};

extern s32 D_80343138_640208;

POKEMON_FUNC(func_802E5CB0_5E2D80)
    pokemon->tangible = false;
    pokemon->flags |= POKEMON_FLAG_8;
    pokemon->miscVars->field0 = pokemon->collisionRadius;
    obj->flags |= GOBJ_FLAG_HIDDEN | GOBJ_FLAG_2;

    if (pokemon->behavior == 1) {
        Pokemon_SetState(obj, func_802E5D94_5E2E64);
    }
    if (pokemon->behavior == 2) {
        Pokemon_SetState(obj, func_802E5F98_5E3068);
    }
    if (pokemon->behavior == 3) {
        Pokemon_SetState(obj, func_802E61DC_5E32AC);
    }

    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802E5D6C_5E2E3C)
    D_80343138_640208 = true;
    Pokemon_StopAuxProc(obj);
}

POKEMON_FUNC(func_802E5D94_5E2E64)
    D_802EEEC4_5EBF94 = obj;
    D_80343138_640208 = false;

    pokemon->counter = 60, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    pokemon->tangible = true;
    obj->flags = 0;
    pokemon->collisionRadius = 0.0f;
    Pokemon_SetAnimation(obj, &D_802EE9BC_5EBA8C);

    pokemon->counter = 110, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    cmdSendCommandToLink(LINK_POKEMON, TUNNEL_CMD_43, obj);
    pokemon->transitionGraph = NULL;
    pokemon->collisionRadius = pokemon->miscVars[0].field0;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    pokemon->flags &= ~POKEMON_FLAG_8;
    Pokemon_SetAnimation(obj, &D_802EE9D0_5EBAA0);
    pokemon->transitionGraph = D_802EE9F8_5EBAC8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &D_802EE994_5EBA64);
    pokemon->counter = 30; pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED, pokemon->transitionGraph = D_802EE9F8_5EBAC8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_SetAnimation(obj, &D_802EE9A8_5EBA78);
    pokemon->transitionGraph = D_802EE9F8_5EBAC8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    pokemon->flags |= POKEMON_FLAG_8;
    pokemon->collisionRadius = 0.0f;
    Pokemon_SetAnimation(obj, &D_802EE9E4_5EBAB4);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_HIDDEN | GOBJ_FLAG_2;

    if (D_80343138_640208) {
        D_802EEED0_5EBFA0 = 1;
        cmdSendCommandToLink(LINK_POKEMON, TUNNEL_CMD_32, obj);
        pokemon->transitionGraph = D_802EEA18_5EBAE8;
        Pokemon_WaitForFlag(obj, 0);
    }

    Pokemon_SetState(obj, func_802E5D94_5E2E64);
}

POKEMON_FUNC(func_802E5F98_5E3068)
    pokemon->transitionGraph = D_802EEA38_5EBB08;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802E5FD8_5E30A8)
    D_802EEEC4_5EBF94 = obj;
    D_80343138_640208 = false;

    pokemon->counter = 60, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    pokemon->tangible = true;
    obj->flags = 0;
    pokemon->collisionRadius = 0.0f;
    Pokemon_SetAnimation(obj, &D_802EE9BC_5EBA8C);

    pokemon->counter = 110, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    cmdSendCommandToLink(LINK_POKEMON, TUNNEL_CMD_43, obj);
    pokemon->transitionGraph = NULL;
    pokemon->collisionRadius = pokemon->miscVars[0].field0;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    pokemon->flags &= ~POKEMON_FLAG_8;
    Pokemon_SetAnimation(obj, &D_802EE9D0_5EBAA0);
    pokemon->transitionGraph = D_802EE9F8_5EBAC8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &D_802EE994_5EBA64);
    pokemon->counter = 30; pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED, pokemon->transitionGraph = D_802EE9F8_5EBAC8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_SetAnimation(obj, &D_802EE9A8_5EBA78);
    pokemon->transitionGraph = D_802EE9F8_5EBAC8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    pokemon->flags |= POKEMON_FLAG_8;
    pokemon->collisionRadius = 0.0f;
    Pokemon_SetAnimation(obj, &D_802EE9E4_5EBAB4);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_HIDDEN | GOBJ_FLAG_2;

    if (D_80343138_640208) {
        D_802EEED0_5EBFA0 = 2;
        cmdSendCommandToLink(LINK_POKEMON, TUNNEL_CMD_33, obj);
    } else {
        cmdSendCommandToLink(LINK_POKEMON, TUNNEL_CMD_31, obj);
    }

    Pokemon_SetState(obj, func_802E5F98_5E3068);
}

POKEMON_FUNC(func_802E61DC_5E32AC)
    pokemon->transitionGraph = D_802EEA58_5EBB28;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802E621C_5E32EC)
    D_802EEEC4_5EBF94 = obj;
    D_80343138_640208 = false;

    pokemon->counter = 60, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    pokemon->tangible = true;
    obj->flags = 0;
    pokemon->collisionRadius = 0.0f;
    Pokemon_SetAnimation(obj, &D_802EE9BC_5EBA8C);

    pokemon->counter = 110, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    cmdSendCommandToLink(LINK_POKEMON, TUNNEL_CMD_43, obj);
    pokemon->transitionGraph = NULL;
    pokemon->collisionRadius = pokemon->miscVars[0].field0;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    pokemon->flags &= ~POKEMON_FLAG_8;
    Pokemon_SetAnimation(obj, &D_802EE9D0_5EBAA0);
    pokemon->transitionGraph = D_802EE9F8_5EBAC8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &D_802EE994_5EBA64);
    pokemon->counter = 30; pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED, pokemon->transitionGraph = D_802EE9F8_5EBAC8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_SetAnimation(obj, &D_802EE9A8_5EBA78);
    pokemon->transitionGraph = D_802EE9F8_5EBAC8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    pokemon->flags |= POKEMON_FLAG_8;
    pokemon->collisionRadius = 0.0f;
    Pokemon_SetAnimation(obj, &D_802EE9E4_5EBAB4);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_HIDDEN | GOBJ_FLAG_2;

    if (D_80343138_640208) {
        D_802EEED0_5EBFA0 = 4;
        cmdSendCommandToLink(LINK_POKEMON, TUNNEL_CMD_34, obj);
    } else {
        cmdSendCommandToLink(LINK_POKEMON, TUNNEL_CMD_31, obj);
    }

    Pokemon_SetState(obj, func_802E61DC_5E32AC);
}

GObj* diglett_Spawn(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802EEA8C_5EBB5C);
}

void func_802E6458_5E3528(GObj* obj) {
    if (D_802EEEC4_5EBF94 == obj) {
        D_802EEEC4_5EBF94 = NULL;
    }
    pokemonRemoveOne(obj);
}
