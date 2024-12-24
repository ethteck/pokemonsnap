#include "../tunnel.h"

void func_802EC078_5E9148(GObj*);
void func_802EBFDC_5E90AC(GObj*);
void func_802EC178_5E9248(GObj*);
void func_802EC294_5E9364(GObj*);
void func_802EC23C_5E930C(GObj*);

// TODO remove this when data is migrated
struct TempStruct {
    int v[5];
};

extern AnimationHeader D_802EFEBC_5ECF8C;
extern AnimationHeader D_802EFED0_5ECFA0;
extern AnimationHeader D_802EFEE4_5ECFB4;
extern AnimationHeader D_802EFEF8_5ECFC8;
extern EggStruct D_802EFF14_5ECFE4;
extern GObj* D_802EFF28_5ECFF8;
extern InteractionHandler D_802EFF2C_5ECFFC[];
extern InteractionHandler2 D_802EFF4C_5ED01C;
extern struct TempStruct D_802EFF6C_5ED03C;
extern PokemonInitData D_802EFF94_5ED064;

POKEMON_FUNC(func_802EBF40_5E9010)
    InteractionHandler2 saved = D_802EFF4C_5ED01C;

    pokemon->miscVars[0].field1 = 0;

    HIDE_POKEMON();

    pokemon->transitionGraph = saved.data;
    Pokemon_WaitForFlag(obj, 0);

    Pokemon_SetState(obj, func_802EBFDC_5E90AC);
}

POKEMON_FUNC(func_802EBFDC_5E90AC)
    SHOW_POKEMON();
    Pokemon_SetAnimation(obj, &D_802EFEBC_5ECF8C);
    pokemon->transitionGraph = D_802EFF2C_5ECFFC;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802EC040_5E9110)
    Pokemon_SetAnimation(obj, &D_802EFEF8_5ECFC8);
    Pokemon_SetState(obj, func_802EC078_5E9148);
}

POKEMON_FUNC(func_802EC078_5E9148)
    D_803430E8_6401B8.bits.unk_01 = true;
    Pokemon_StartAuxProc(obj, func_802EC178_5E9248);
    Pokemon_SetAnimation(obj, &D_802EFED0_5ECFA0);
    pokemon->counter = 180, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_StartPathProc(obj, func_802EC294_5E9364);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    cmdSendCommandToLink(LINK_POKEMON, TUNNEL_CMD_28, obj);
    Pokemon_SetAnimation(obj, &D_802EFEE4_5ECFB4);
    Pokemon_StartPathProc(obj, func_802EC23C_5E930C);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    D_802EFF28_5ECFF8 = NULL;
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802EC178_5E9248)
    s32 i, j;
    struct TempStruct sp2C = D_802EFF6C_5ED03C;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < sp2C.v[i]; j++) {
            ohWait(1);
        }
        EnvSound_PlaySound(obj, 1, SOUND_ID_137);
    }

    Pokemon_StopAuxProc(obj);
}

POKEMON_FUNC(func_802EC23C_5E930C)
    func_80362414_502824(pokemon, &D_802EFF14_5ECFE4, 0.016666668f);

    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802EC294_5E9364)
    Mtx3Float* targetPos = &GET_TRANSFORM(D_802EFBA4_5ECC74->data.dobj)->pos;
    f32 targetX = targetPos->v.x;
    f32 targetY = targetPos->v.y - 120.0f;
    f32 targetZ = targetPos->v.z;

    Pokemon_SetTargetPos(obj, targetX, targetZ);

    while (true) {
        Pokemon_StepToTargetPos(obj, TAU, 0);
        if (targetY - position->v.y < 10.0f) {
            position->v.y = targetY;
            break;
        }

        position->v.y += 10.0f;
        ohWait(1);
    }

    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802EC398_5E9468)
    D_802EFF28_5ECFF8 = NULL;
    pokemonRemoveOne(obj);
}

GObj* func_802EC3BC_5E948C(s32 gObjID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    D_802EFF28_5ECFF8 = Pokemon_Spawn(gObjID, id, block, blockB, spawn, &D_802EFF94_5ED064);

    return D_802EFF28_5ECFF8;
}
