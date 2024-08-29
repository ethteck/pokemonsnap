#include "volcano/volcano.h"

extern UnkEC64Arg3 D_80113830[];
extern Texture** D_801138C0[];

extern AnimCmd* D_80113960[];

extern AnimCmd** D_80113990[];

void func_802DD7F0_72E9F0(GObj*);
void func_802DD954_72EB54(GObj*);
void func_802D6B64_727D64(GObj*);
void func_802DDA0C_72EC0C(GObj*);
void func_802DD8F8_72EAF8(GObj*);

AnimationHeader D_802E2F90_734190 = {
    1.5,
    100,
    D_80113960,
    D_80113990,
    NULL
};

InteractionHandler D_802E2FA4_7341A4[] = {
    { VOLCANO_CMD_38, func_802DD954_72EB54, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

PokemonAnimationSetup D_802E2FC4_7341C4 = {
    &D_802E2F90_734190,
    func_802DD7F0_72E9F0,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData D_802E2FD8_7341D8 = {
    D_80113830,
    D_801138C0,
    renderModelTypeBFogged,
    &D_802E2FC4_7341C4,
    { 10, 10, 10 },
    { 0, -300, 0 },
    0,
    0,
    0,
    0,
    0,
    { 0, 0, 0 }
};

POKEMON_FUNC(func_802DD7F0_72E9F0)
    s32 blockIndex;
    f32 blockPart;

    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_HIDDEN | GOBJ_FLAG_2;

    while (true) {
        getLevelProgress(&blockIndex, &blockPart);
        if (blockIndex > 5 || blockIndex == 5 && blockPart >= 0.06) {
            break;
        }
        ohWait(1);
    }

    pokemon->tangible = true;
    obj->flags = 0;
    pokemon->miscVars[0].field1 = 0;
    omCreateProcess(obj, func_802D6B64_727D64, 1, 1);
    Pokemon_StartPathProc(obj, func_802DDA0C_72EC0C);
    Pokemon_SetState(obj, func_802DD8F8_72EAF8);
}

POKEMON_FUNC(func_802DD8F8_72EAF8)
    Pokemon_SetAnimation(obj, &D_802E2F90_734190);
    pokemon->transitionGraph = D_802E2FA4_7341A4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_802DD8F8_72EAF8);
}

POKEMON_FUNC(func_802DD954_72EB54)
    omCreateProcess(obj, func_802D6B2C_727D2C, 1, 1);

    if (!pokemon->miscVars[0].field1 && Pokemon_GetDistance(obj, pokemon->interactionTarget) < 200.0f && func_802D6D6C_727F6C(obj)) {
        pokemon->miscVars[0].field1 = true;
    }

    Pokemon_SetAnimation(obj, &D_802E2F90_734190);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_802DD8F8_72EAF8);
}

POKEMON_FUNC(func_802DDA0C_72EC0C)
    while (pokemon->miscVars[0].field1 == 0) {
        cmdSendCommand(pokemon->miscVars[1].obj, VOLCANO_CMD_34, obj);
        ohWait(randRange(180) + 120);
    }

    cmdSendCommand(pokemon->miscVars[1].obj, VOLCANO_CMD_35, obj);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

GObj* func_802DDA98_72EC98(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnDlLink4(objID, id, block, blockB, spawn, &D_802E2FD8_7341D8);
}
