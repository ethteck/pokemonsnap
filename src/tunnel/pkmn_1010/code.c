#include "../tunnel.h"

void func_802EB014_5E80E4(GObj*);
void func_802EB28C_5E835C(GObj*);
void func_802EB0CC_5E819C(GObj*);

extern AnimationHeader D_802EFAA0_5ECB70;
extern AnimationHeader D_802EFAB4_5ECB84;
extern InteractionHandler2 D_802EFAC8_5ECB98;
extern PokemonInitData D_802EFAFC_5ECBCC;

POKEMON_FUNC(func_802EAFB0_5E8080)
    while (!D_803430E8_6401B8.bits.unk_00) {
        ohWait(1);
    }

    Pokemon_SetState(obj, func_802EB014_5E80E4);
}

POKEMON_FUNC(func_802EB014_5E80E4)
    s32 unused;
    s32 blockIndex;
    f32 blockPart;

    while (true) {
        getLevelProgress(&blockIndex, &blockPart);
        if (blockIndex > 3 || blockIndex == 3 && blockPart >= 0.613) {
            break;
        }
        ohWait(1);
    }

    Pokemon_StartPathProc(obj, func_802EB28C_5E835C);
    Pokemon_SetState(obj, func_802EB0CC_5E819C);
}

POKEMON_FUNC(func_802EB0CC_5E819C)
    InteractionHandler2 saved = D_802EFAC8_5ECB98;
    s32 i, s7;

    pokemon->flags |= POKEMON_FLAG_4;
    Pokemon_SetAnimation(obj, &D_802EFAA0_5ECB70);

    s7 = randRange(2) + 2;
    for (i = 0; i < s7; i++) {
        pokemon->flags |= POKEMON_FLAG_4;
        Pokemon_SetAnimation(obj, &D_802EFAA0_5ECB70);
        pokemon->counter = 6, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
        pokemon->transitionGraph = saved.data;
        Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

        pokemon->flags &= ~(POKEMON_FLAG_4 & 0xFFu); // required to match
        Pokemon_SetAnimation(obj, &D_802EFAB4_5ECB84);
        pokemon->counter = 6, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
        pokemon->transitionGraph = saved.data;
        Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);
    }

    pokemon->flags |= POKEMON_FLAG_4;
    Pokemon_SetAnimation(obj, &D_802EFAA0_5ECB70);
    pokemon->counter = 60, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = saved.data;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_SetState(obj, func_802EB0CC_5E819C);
}

POKEMON_FUNC(func_802EB28C_5E835C)
    s32 blockIndex;
    f32 blockPart;

    while (true) {
        getLevelProgress(&blockIndex, &blockPart);
        if (blockIndex > 4 || blockIndex == 4 && blockPart >= 0.351) {
            break;
        }
        ohWait(1);
    }

    cmdSendCommand(obj, TUNNEL_CMD_47, obj);
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    pokemon->pathProc = NULL;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802EB35C_5E842C)
    Pokemon_SetAnimation(obj, &D_802EFAB4_5ECB84);
    pokemon->flags &= ~POKEMON_FLAG_4;
    Pokemon_SetState(obj, NULL);
}

GObj* func_802EB3A8_5E8478(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_Spawn(objID, id, block, blockB, spawn, &D_802EFAFC_5ECBCC);
}
