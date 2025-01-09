#include "valley.h"

extern GObj* D_802D2FF0_7AC580;
extern AnimationHeader D_802D3A80_7AD010;
extern AnimationHeader D_802D3A94_7AD024;
extern AnimationHeader D_802D3AA8_7AD038;
extern AnimationHeader D_802D3ABC_7AD04C;
extern AnimationHeader D_802D3AD0_7AD060;
extern AnimationHeader D_802D3AE4_7AD074;
extern AnimationHeader D_802D3AF8_7AD088;
extern AnimationHeader D_802D3B0C_7AD09C;
extern AnimationHeader D_802D3B20_7AD0B0;
extern GObj* D_802D3B34_7AD0C4;
extern InteractionHandler D_802D3B38_7AD0C8[];
extern InteractionHandler D_802D3B68_7AD0F8[];
extern InteractionHandler D_802D3B98_7AD128[];
extern InteractionHandler D_802D3BC8_7AD158[];
extern PokemonInitData D_802D3C0C_7AD19C;

void func_802CDEA4_7A7434(GObj*);

POKEMON_FUNC(func_802CDE80_7A7410)
    Pokemon_SetState(obj, func_802CDEA4_7A7434);
}

POKEMON_FUNC(func_802CDEA4_7A7434)
    Pokemon_SetAnimation(obj, &D_802D3A80_7AD010);
    pokemon->transitionGraph = D_802D3B38_7AD0C8;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802CDEFC_7A748C)
    EnvSound_PlaySound(obj, 1, SOUND_ID_30);
    Pokemon_SetAnimation(obj, &D_802D3AE4_7AD074);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802CDEA4_7A7434);
}

POKEMON_FUNC(func_802CDF68_7A74F8)
    EnvSound_PlaySound(obj, 1, SOUND_ID_30);
    Pokemon_SetAnimation(obj, &D_802D3AE4_7AD074);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_802D3A94_7AD024);
    pokemon->transitionGraph = D_802D3B68_7AD0F8;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802CDFFC_7A758C)
    EnvSound_PlaySound(obj, 1, SOUND_ID_30);
    Pokemon_SetAnimation(obj, &D_802D3AF8_7AD088);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_802D3AA8_7AD038);
    pokemon->transitionGraph = D_802D3B98_7AD128;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802CE090_7A7620)
    EnvSound_PlaySound(obj, 1, SOUND_ID_30);
    Pokemon_SetAnimation(obj, &D_802D3B0C_7AD09C);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_802D3ABC_7AD04C);
    pokemon->transitionGraph = D_802D3BC8_7AD158;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802CE124_7A76B4)
    EnvSound_PlaySound(obj, 1, SOUND_ID_30);
    Pokemon_SetAnimation(obj, &D_802D3B20_7AD0B0);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_802D3AD0_7AD060);
    if (D_802D2FF0_7AC580 != NULL) {
        cmdSendCommand(D_802D2FF0_7AC580, 0x1C, obj);
    }
    Pokemon_SetState(obj, NULL);
}

GObj* func_802CE1B8_7A7748(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    D_802D3B34_7AD0C4 = Pokemon_SpawnDlLink4(gObjID, id, roomA, roomB, spawn, &D_802D3C0C_7AD19C);

    return D_802D3B34_7AD0C4;
}
