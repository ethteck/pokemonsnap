#include "valley.h"

extern AnimationHeader D_802D3958_7ACEE8;
extern AnimationHeader D_802D396C_7ACEFC;
extern AnimationHeader D_802D3980_7ACF10;
extern InteractionHandler D_802D3994_7ACF24[];
extern RandomStates3 D_802D39B4_7ACF44;
extern s32 D_802D39CC_7ACF5C;
extern InteractionHandler2 D_802D39D0_7ACF60;
extern InteractionHandler2 D_802D39F0_7ACF80;
extern InteractionHandler2 D_802D3A10_7ACFA0;
extern PokemonInitData D_802D3A44_7ACFD4;
extern GObj* D_802D3B34_7AD0C4;

void func_802CD914_7A6EA4(GObj*);
void func_802CDB40_7A70D0(GObj*);
void func_802CDBD4_7A7164(GObj*);
void func_802CDC68_7A71F8(GObj*);

POKEMON_FUNC(func_802CD7C0_7A6D50)
    switch (pokemon->behavior) {
        case 1:
            Pokemon_SetState(obj, func_802CDB40_7A70D0);
            break;
        case 2:
            Pokemon_SetState(obj, func_802CDBD4_7A7164);
            break;
        default:
            Pokemon_SetState(obj, func_802CDC68_7A71F8);
            break;
    }
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802CD84C_7A6DDC)
    RandomStates3 sp18 = D_802D39B4_7ACF44;

    Pokemon_SetStateRandom(obj, sp18.data);
}

POKEMON_FUNC(func_802CD8A4_7A6E34)
    Pokemon_SetAnimation(obj, &D_802D3958_7ACEE8);
    Pokemon_SetState(obj, func_802CD914_7A6EA4);
}

POKEMON_FUNC(func_802CD8DC_7A6E6C)
    Pokemon_SetAnimation(obj, &D_802D396C_7ACEFC);
    Pokemon_SetState(obj, func_802CD914_7A6EA4);
}

POKEMON_FUNC(func_802CD914_7A6EA4)
    pokemon->transitionGraph = D_802D3994_7ACF24;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED | POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    if (!(pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED)) {
        Pokemon_SetState(obj, func_802CD84C_7A6DDC);
    }
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802CD98C_7A6F1C)
    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0.0f, 1.0f, 0.15f, 0.1f, 0);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802CD9F8_7A6F88)
    f32 sp2C = (2.0f * randFloat()) + 2.0f;

    rotation->v.y = randFloat() * TAU;

    while (true) {
        rotation->v.y += (sp2C * PI) / 180.0f;
        ohWait(1);
    }
}

POKEMON_FUNC(func_802CDA94_7A7024)
    f32 var_f20 = 60.0f;

    while (var_f20-- != 0.0f) {
        rotation->v.y += PI / 30;
        ohWait(1);
    }
    Pokemon_StopAuxProc(obj);
}

POKEMON_FUNC(func_802CDB40_7A70D0)
    InteractionHandler2 sp18 = D_802D39D0_7ACF60;

    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_2 | GOBJ_FLAG_HIDDEN;
    pokemon->transitionGraph = sp18.data;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802CDBD4_7A7164)
    InteractionHandler2 sp18 = D_802D39F0_7ACF80;

    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_2 | GOBJ_FLAG_HIDDEN;
    pokemon->transitionGraph = sp18.data;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802CDC68_7A71F8)
    InteractionHandler2 sp18 = D_802D3A10_7ACFA0;

    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_2 | GOBJ_FLAG_HIDDEN;
    pokemon->transitionGraph = sp18.data;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802CDCFC_7A728C)
    D_802D39CC_7ACF5C++;
    pokemon->counter = D_802D39CC_7ACF5C * 60, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);
    D_802D39CC_7ACF5C -= 1;
    cmdSendCommand(D_802D3B34_7AD0C4, 0x25, obj);
    EnvSound_PlaySound(obj, 1, 0x188);
    pokemon->tangible = true;
    obj->flags = 0;
    Pokemon_SetAnimation(obj, &D_802D3980_7ACF10);
    Pokemon_StartAuxProc(obj, func_802CD9F8_7A6F88);
    Pokemon_StartPathProc(obj, func_802CD98C_7A6F1C);
    pokemon->transitionGraph = D_802D3994_7ACF24;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802CD84C_7A6DDC);
}

GObj* func_802CDE04_7A7394(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_Spawn(objID, id, block, blockB, spawn, &D_802D3A44_7ACFD4);
}

GObj* func_802CDE3C_7A73CC(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_Spawn(objID, id, block, blockB, spawn, &D_802D3A44_7ACFD4);
}
