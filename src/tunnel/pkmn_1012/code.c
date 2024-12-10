#include "../tunnel.h"

void func_802EC6CC_5E979C(GObj*);

extern GObj* D_802EFFD0_5ED0A0;
extern AnimationHeader D_802EFFD4_5ED0A4;
extern AnimationHeader D_802EFFE8_5ED0B8;
extern InteractionHandler2 D_802EFFFC_5ED0CC;
extern PokemonInitData D_802F0030_5ED100;

POKEMON_FUNC(func_802EC400_5E94D0)
    InteractionHandler2 saved = D_802EFFFC_5ED0CC;

    pokemon->counter = 6, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    Pokemon_SetAnimation(obj, &D_802EFFD4_5ED0A4);
    pokemon->transitionGraph = &saved;    
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);
    
    if (D_803430E8_6401B8.bits.unk_00) {
        Pokemon_SetState(obj, func_802EC6CC_5E979C);
    }

    Pokemon_SetState(obj, func_802EC400_5E94D0);
}

POKEMON_FUNC(func_802EC4E8_5E95B8)
    Pokemon_SetAnimation(obj, &D_802EFFE8_5ED0B8);
    pokemon->counter = randRange(randRange(6) + 1) + 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);
    
    Pokemon_SetAnimation(obj, &D_802EFFD4_5ED0A4);
    pokemon->counter = randRange(randRange(30) + 1) + 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_SetState(obj, func_802EC4E8_5E95B8);
}

POKEMON_FUNC(func_802EC5B0_5E9680)
    s32 i;

    i = 9;
    while (i--) {
        Pokemon_SetAnimation(obj, &D_802EFFE8_5ED0B8);
        pokemon->counter = randRange(randRange(6) + 1) + 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
        pokemon->transitionGraph = NULL;
        Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);
        
        Pokemon_SetAnimation(obj, &D_802EFFD4_5ED0A4);
        pokemon->counter = randRange(randRange(30) + 1) + 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
        pokemon->transitionGraph = NULL;
        Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);
    }

    if (D_802EF484_5EC554 != NULL) {
        cmdSendCommand(D_802EF484_5EC554, TUNNEL_CMD_49, obj);
    }

    Pokemon_SetState(obj, func_802EC6CC_5E979C);
}

POKEMON_FUNC(func_802EC6CC_5E979C)
    Pokemon_ForceAnimation(obj, &D_802EFFE8_5ED0B8);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802EC6CC_5E979C);
}

GObj* func_802EC720_5E97F0(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    D_802EFFD0_5ED0A0 = Pokemon_SpawnDlLink4(gObjID, id, roomA, roomB, spawn, &D_802F0030_5ED100);

    return D_802EFFD0_5ED0A0;
}
