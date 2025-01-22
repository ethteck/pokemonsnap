#include "../rainbow.h"
#include "app_render/particle.h"

void func_80349E28_829598(GObj*);
void func_803491D4_828944(GObj*);
void func_8034930C_828A7C(GObj*);
void func_803493F4_828B64(GObj*);
void func_80349714_828E84(GObj*);
void func_80349814_828F84(GObj*);
void func_80349B34_8292A4(GObj*);
void func_80349D40_8294B0(GObj*);
void func_80349C18_829388(GObj*);

extern s32 D_8034AE48_82A5B8;
extern s32 D_8034AE4C_82A5BC;
extern AnimationHeader D_8034B098_82A808;
extern AnimationHeader D_8034B0AC_82A81C;
extern AnimationHeader D_8034B0C0_82A830;
extern AnimationHeader D_8034B0E8_82A858;
extern AnimationHeader D_8034B0FC_82A86C;
extern AnimationHeader D_8034B110_82A880;
extern AnimationHeader D_8034B124_82A894;
extern AnimationHeader D_8034B138_82A8A8;
extern AnimationHeader D_8034B160_82A8D0;
extern AnimationHeader D_8034B174_82A8E4;
extern InteractionHandler D_8034B188_82A8F8[];
extern InteractionHandler D_8034B1A8_82A918[];
extern InteractionHandler D_8034B208_82A978[];
extern InteractionHandler D_8034B238_82A9A8[];
extern InteractionHandler D_8034B268_82A9D8[];
extern InteractionHandler D_8034B298_82AA08[];
extern InteractionHandler D_8034B2C8_82AA38[];
extern InteractionHandler D_8034B328_82AA98[];
extern InteractionHandler D_8034B348_82AAB8[];
extern InteractionHandler D_8034B3B8_82AB28[];
extern InteractionHandler D_8034B3E8_82AB58[];
extern InteractionHandler D_8034B418_82AB88[];
extern InteractionHandler D_8034B448_82ABB8[];
extern InteractionHandler D_8034B478_82ABE8[];
extern InteractionHandler D_8034B4E8_82AC58[];
extern f32 D_8034B700_82AE70;
extern Vec3f D_8034B528_82AC98;
extern Vec3f D_8034B534_82ACA4;
extern PokemonInitData D_8034B554_82ACC4;

extern s32 D_80350190_82F900;

POKEMON_FUNC(func_80349180_8288F0)
    pokemon->miscVars[0].field0 = pokemon->collisionRadius;
    Pokemon_StartAuxProc(obj, func_80349E28_829598);
    Pokemon_StartPathProc(obj, func_803491D4_828944);
    Pokemon_SetState(obj, func_8034930C_828A7C);
}

POKEMON_FUNC(func_803491D4_828944)
    DObj* node;
    Vec3f pos;
    Vec3f vel = D_8034B528_82AC98;

    node = D_8034AB94_82A304->data.dobj->firstChild->firstChild;
    while (true) {
        fx_getPosVelDObj(&pos, &vel, node);
        position->v.x = pos.x;
        position->v.y = pos.y;
        if (D_80350190_82F900 == 0 || position->v.z < 2000.0f) {
            position->v.z = pos.z;
        }
        rotation->v.y = atan2f(pos.x, pos.z) + PI;
        ohWait(1);
    }
}

POKEMON_FUNC(func_8034930C_828A7C)
    HIDE_POKEMON();
    pokemon->transitionGraph = D_8034B188_82A8F8;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_8034935C_828ACC)
    SHOW_POKEMON();

    if (gDirectionIndex < 0) {
        Pokemon_SetAnimation(obj, &D_8034B0FC_82A86C);
    } else {
        Pokemon_SetAnimation(obj, &D_8034B0C0_82A830);
    }
    pokemon->transitionGraph = D_8034B1A8_82A918;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_803493F4_828B64);
}

POKEMON_FUNC(func_803493F4_828B64)
    if (D_8034AE48_82A5B8 != 1) {
        Pokemon_ForceAnimation(obj, &D_8034B098_82A808);
    } else {
        Pokemon_ForceAnimation(obj, &D_8034B0AC_82A81C);
    }
    pokemon->transitionGraph = D_8034B1A8_82A918;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_803493F4_828B64);
}

POKEMON_FUNC(func_80349480_828BF0)
    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_8034B208_82A978;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_ForceAnimation(obj, &D_8034B0AC_82A81C);
    pokemon->transitionGraph = D_8034B208_82A978;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_80349480_828BF0);
}

POKEMON_FUNC(func_80349514_828C84)
    Pokemon_SetAnimation(obj, &D_8034B0FC_82A86C);
    pokemon->transitionGraph = D_8034B238_82A9A8;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_8034956C_828CDC)
    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_8034B268_82A9D8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_SetAnimation(obj, &D_8034B0AC_82A81C);
    pokemon->transitionGraph = D_8034B268_82A9D8;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_803495FC_828D6C)
    Pokemon_SetAnimation(obj, &D_8034B0FC_82A86C);
    pokemon->transitionGraph = D_8034B298_82AA08;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_80349654_828DC4)
    pokemon->collisionRadius = 0.0f;
    Pokemon_SetAnimation(obj, &D_8034B0E8_82A858);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    pokemon->collisionRadius = pokemon->miscVars[0].field0;
    Pokemon_SetState(obj, func_80349714_828E84);
}

POKEMON_FUNC(func_803496BC_828E2C)
    Pokemon_SetAnimation(obj, &D_8034B0FC_82A86C);
    pokemon->transitionGraph = D_8034B2C8_82AA38;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_80349714_828E84)
    HIDE_POKEMON();
    Pokemon_StartPathProc(obj, func_803491D4_828944);
    pokemon->transitionGraph = D_8034B328_82AA98;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_8034977C_828EEC)
    SHOW_POKEMON();
    if (gDirectionIndex < 0) {
        Pokemon_SetAnimation(obj, &D_8034B174_82A8E4);
    } else {
        Pokemon_SetAnimation(obj, &D_8034B138_82A8A8);
    }
    pokemon->transitionGraph = D_8034B348_82AAB8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_80349814_828F84);
}

POKEMON_FUNC(func_80349814_828F84)
    if (D_8034AE4C_82A5BC != 1) {
        Pokemon_ForceAnimation(obj, &D_8034B110_82A880);
    } else {
        Pokemon_ForceAnimation(obj, &D_8034B124_82A894);
    }
    pokemon->transitionGraph = D_8034B348_82AAB8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_80349814_828F84);
}

POKEMON_FUNC(func_803498A0_829010)
    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_8034B3B8_82AB28;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_ForceAnimation(obj, &D_8034B124_82A894);
    pokemon->transitionGraph = D_8034B3B8_82AB28;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_803498A0_829010);
}

POKEMON_FUNC(func_80349934_8290A4)
    Pokemon_SetAnimation(obj, &D_8034B174_82A8E4);
    pokemon->transitionGraph = D_8034B3E8_82AB58;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_8034998C_8290FC)
    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_8034B418_82AB88;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_SetAnimation(obj, &D_8034B124_82A894);
    pokemon->transitionGraph = D_8034B418_82AB88;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_80349A1C_82918C)
    Pokemon_SetAnimation(obj, &D_8034B174_82A8E4);
    pokemon->transitionGraph = D_8034B448_82ABB8;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_80349A74_8291E4)
    pokemon->collisionRadius = 0.0f;
    Pokemon_SetAnimation(obj, &D_8034B160_82A8D0);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    pokemon->collisionRadius = pokemon->miscVars[0].field0;
    Pokemon_SetState(obj, func_80349B34_8292A4);
}

POKEMON_FUNC(func_80349ADC_82924C)
    Pokemon_SetAnimation(obj, &D_8034B174_82A8E4);
    pokemon->transitionGraph = D_8034B478_82ABE8;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_80349B34_8292A4)
    HIDE_POKEMON();
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_8034B4E8_82AC58;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_80349B98_829308)
    SHOW_POKEMON();
    Pokemon_SetAnimation(obj, &D_8034B174_82A8E4);
    Pokemon_StartPathProc(obj, func_80349C18_829388);
    pokemon->transitionGraph = D_8034B4E8_82AC58;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetState(obj, func_80349D40_8294B0);
}

POKEMON_FUNC(func_80349C18_829388)
    DObj* node;
    Vec3f sp48;
    Vec3f sp3C = D_8034B534_82ACA4;

    node = D_8034AB94_82A304->data.dobj->firstChild->firstChild;
    fx_getPosVelDObj(&sp48, &sp3C, node);
    position->v.z = sp48.z;
    while (true) {
        fx_getPosVelDObj(&sp48, &sp3C, node);
        position->v.x = sp48.x;
        position->v.y = sp48.y;
        position->v.z += 15.0f;

        if (position->v.z > 2000.0f) {
            break;
        }

        ohWait(1);
    }

    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_80349D40_8294B0)
    Pokemon_StartPathProc(obj, func_803491D4_828944);
    Pokemon_SetAnimation(obj, &D_8034B110_82A880);
    pokemon->transitionGraph = D_8034B4E8_82AC58;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_80349DB0_829520)
    cmdSendCommand(D_8034AB94_82A304, POKEMON_CMD_9, obj);
    Pokemon_StopAuxProc(obj);
}

POKEMON_FUNC(func_80349DE8_829558)
    cmdSendCommand(D_8034AB94_82A304, POKEMON_CMD_13, obj);
    Pokemon_StopAuxProc(obj);
}

static void nullsub(void) {
}

POKEMON_FUNC(func_80349E28_829598)
    while (true) {
        if (gDirectionIndex < 0) {
            cmdSendCommand(D_8034AB98_82A308, RAINBOW_CMD_32, obj);
        } else {
            cmdSendCommand(D_8034AB98_82A308, RAINBOW_CMD_33, obj);
        }
        ohWait(1);
    }
}

GObj* func_80349EB8_829628(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnDlLink4(objID, id, block, blockB, spawn, &D_8034B554_82ACC4);
}
