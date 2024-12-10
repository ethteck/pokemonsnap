#include "../tunnel.h"

void func_802ECA2C_5E9AFC(GObj*);
void func_802EC760_5E9830(GObj*);
void func_802ECA2C_5E9AFC(GObj*);

extern GObj* D_802F0070_5ED140;
extern AnimationHeader D_802F0074_5ED144;
extern AnimationHeader D_802F0088_5ED158;
extern InteractionHandler2 D_802F009C_5ED16C;
extern PokemonInitData D_802F00D0_5ED1A0;

POKEMON_FUNC(func_802EC760_5E9830)
    InteractionHandler2 saved = D_802F009C_5ED16C;

    pokemon->counter = 6, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    Pokemon_SetAnimation(obj, &D_802F0074_5ED144);
    pokemon->transitionGraph = &saved;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    if (D_803430E8_6401B8.bits.unk_00) {
        Pokemon_SetState(obj, func_802ECA2C_5E9AFC);
    }

    Pokemon_SetState(obj, func_802EC760_5E9830);
}

POKEMON_FUNC(func_802EC848_5E9918)
    Pokemon_SetAnimation(obj, &D_802F0088_5ED158);
    pokemon->counter = randRange(randRange(6) + 1) + 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_SetAnimation(obj, &D_802F0074_5ED144);
    pokemon->counter = randRange(randRange(30) + 1) + 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_SetState(obj, func_802EC848_5E9918);
}

POKEMON_FUNC(func_802EC910_5E99E0)
    s32 i;

    i = 9;
    while (i--) {
        Pokemon_SetAnimation(obj, &D_802F0088_5ED158);
        pokemon->counter = randRange(randRange(6) + 1) + 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
        pokemon->transitionGraph = NULL;
        Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

        Pokemon_SetAnimation(obj, &D_802F0074_5ED144);
        pokemon->counter = randRange(randRange(30) + 1) + 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
        pokemon->transitionGraph = NULL;
        Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);
    }

    if (D_802EF488_5EC558 != NULL) {
        cmdSendCommand(D_802EF488_5EC558, TUNNEL_CMD_49, obj);
    }

    Pokemon_SetState(obj, func_802ECA2C_5E9AFC);
}

POKEMON_FUNC(func_802ECA2C_5E9AFC)
    Pokemon_ForceAnimation(obj, &D_802F0088_5ED158);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802ECA2C_5E9AFC);
}

GObj* func_802ECA80_5E9B50(s32 gObjID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    D_802F0070_5ED140 = Pokemon_SpawnDlLink4(gObjID, id, block, blockB, spawn, &D_802F00D0_5ED1A0);

    return D_802F0070_5ED140;
}
