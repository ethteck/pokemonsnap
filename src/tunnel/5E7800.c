#include "tunnel.h"

void func_802EA79C_5E786C(GObj*);
void func_802EA970_5E7A40(GObj*);

extern s32 D_802EF9F4_5ECAC4[];
extern AnimationHeader D_802EFA2C_5ECAFC;
extern AnimationHeader D_802EFA40_5ECB10;

POKEMON_FUNC(func_802EA730_5E7800)
    if (pokemon->behavior == 1) {
        Pokemon_SetState(obj, func_802EA79C_5E786C);
    }
    if (pokemon->behavior == 2) {
        Pokemon_SetState(obj, func_802EA970_5E7A40);
    }

    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802EA79C_5E786C)
    s32 blockIndex;
    f32 blockPart;
    s32 blockIndex2;
    f32 blockPart2;
    s32 blockIndex3;
    f32 blockPart3;

    while (true) {
        getLevelProgress(&blockIndex, &blockPart);
        if (blockIndex > 1 || blockIndex == 1 && blockPart >= 0.9f) {
            break;
        }
        ohWait(1);
    }

    cmdSendCommandToLink(LINK_POKEMON, TUNNEL_CMD_50, obj);
    Pokemon_SetAnimation(obj, &D_802EFA2C_5ECAFC);

    while (true) {
        getLevelProgress(&blockIndex2, &blockPart2);
        if (blockIndex2 > 2 || blockIndex2 == 2 && blockPart2 >= 0.05f) {
            break;
        }
        ohWait(1);
    }

    Pokemon_SetAnimation(obj, &D_802EFA40_5ECB10);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    cmdSendCommandToLink(LINK_POKEMON, TUNNEL_CMD_51, obj);

    while (true) {
        getLevelProgress(&blockIndex3, &blockPart3);
        if (blockIndex3 > 3 || blockIndex3 == 3 && blockPart3 >= 0.15f) {
            break;
        }
        ohWait(1);
    }

    D_802EF9F4_5ECAC4[pokemon->behavior] = 0;
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802EA970_5E7A40)
    s32 blockIndex;
    f32 blockPart;
    s32 blockIndex2;
    f32 blockPart2;
    s32 blockIndex3;
    f32 blockPart3;

    while (true) {
        getLevelProgress(&blockIndex, &blockPart);
        if (blockIndex > 2 || blockIndex == 2 && blockPart >= 0.9f) {
            break;
        }
        ohWait(1);
    }

    cmdSendCommandToLink(LINK_POKEMON, TUNNEL_CMD_52, obj);
    Pokemon_SetAnimation(obj, &D_802EFA2C_5ECAFC);

    while (true) {
        getLevelProgress(&blockIndex2, &blockPart2);
        if (blockIndex2 > 3 || blockIndex2 == 3 && blockPart2 >= 0.05f) {
            break;
        }
        ohWait(1);
    }

    Pokemon_SetAnimation(obj, &D_802EFA40_5ECB10);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    cmdSendCommandToLink(LINK_POKEMON, TUNNEL_CMD_53, obj);

    while (true) {
        getLevelProgress(&blockIndex3, &blockPart3);
        if (blockIndex3 > 5 || blockIndex3 == 5 && blockPart3 >= 0.3f) {
            break;
        }
        ohWait(1);
    }

    D_802EF9F4_5ECAC4[pokemon->behavior] = 0;
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E7800/func_802EAB44_5E7C14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E7800/func_802EADAC_5E7E7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E7800/func_802EAE7C_5E7F4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E7800/func_802EAF18_5E7FE8.s")
