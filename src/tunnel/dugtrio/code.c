#include "../tunnel.h"

void func_802E6574_5E3644(GObj*);
void func_802E67B8_5E3888(GObj*);
void func_802E6A30_5E3B00(GObj*);

extern AnimationHeader D_802EEAC4_5EBB94;
extern AnimationHeader D_802EEAD8_5EBBA8;
extern AnimationHeader D_802EEAEC_5EBBBC;
extern AnimationHeader D_802EEB00_5EBBD0;
extern AnimationHeader D_802EEB14_5EBBE4;
extern InteractionHandler D_802EEB28_5EBBF8[];
extern InteractionHandler D_802EEB48_5EBC18[];
extern InteractionHandler D_802EEB68_5EBC38[];
extern InteractionHandler D_802EEB88_5EBC58[];
extern PokemonInitData D_802EEBBC_5EBC8C;

extern s32 D_80343148_640218;
extern s32 D_8034314C_64021C;
extern GObj* D_802EEEC8_5EBF98;

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
