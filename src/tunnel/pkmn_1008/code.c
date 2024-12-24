#include "../tunnel.h"

void func_802EA694_5E7764(GObj*);

extern AnimationHeader D_802EF750_5EC820;
extern InteractionHandler D_802EF778_5EC848[];
extern InteractionHandler2 D_802EF788_5EC858;
extern PokemonInitData D_802EF7BC_5EC88C;

extern s32 D_803430F8_6401C8;

POKEMON_FUNC(func_802EA490_5E7560)
    s32 blockIndex;
    f32 blockPart;

    while (true) {
        getLevelProgress(&blockIndex, &blockPart);
        if (blockIndex > 3 || blockIndex == 3 && blockPart >= 0.5) {
            break;
        }
        ohWait(1);
    }

    Pokemon_RunCleanup(obj);
    Pokemon_StopAuxProc(obj);
}

POKEMON_FUNC(func_802EA53C_5E760C)
    InteractionHandler2 saved = D_802EF788_5EC858;

    HIDE_POKEMON();
    pokemon->transitionGraph = saved.data;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802EA5D0_5E76A0)
    Pokemon_StartAuxProc(obj, func_802EA490_5E7560);
    SHOW_POKEMON();

    while (!D_803430E8_6401B8.bits.unk_00) {
        pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
        pokemon->transitionGraph = D_802EF778_5EC848;
        Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);
    }

    Pokemon_SetState(obj, func_802EA694_5E7764);
}

POKEMON_FUNC(func_802EA694_5E7764)
    D_803430F8_6401C8 = 1;
    Pokemon_SetAnimation(obj, &D_802EF750_5EC820);
    pokemon->transitionGraph = D_802EF778_5EC848;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

GObj* func_802EA6F8_5E77C8(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnDlLink4(objID, id, block, blockB, spawn, &D_802EF7BC_5EC88C);
}
