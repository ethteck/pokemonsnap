#include "../tunnel.h"

void func_802E5D94_5E2E64(GObj*);
void func_802E5F98_5E3068(GObj*);
void func_802E61DC_5E32AC(GObj*);

extern AnimationHeader D_802EE994_5EBA64;
extern AnimationHeader D_802EE9A8_5EBA78;
extern AnimationHeader D_802EE9BC_5EBA8C;
extern AnimationHeader D_802EE9D0_5EBAA0;
extern AnimationHeader D_802EE9E4_5EBAB4;
extern InteractionHandler D_802EE9F8_5EBAC8[];
extern InteractionHandler D_802EEA18_5EBAE8[];
extern InteractionHandler D_802EEA38_5EBB08[];
extern InteractionHandler D_802EEA58_5EBB28[];
extern PokemonInitData D_802EEA8C_5EBB5C;
extern GObj* D_802EEEC4_5EBF94;
extern s32 D_802EEED0_5EBFA0;

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
