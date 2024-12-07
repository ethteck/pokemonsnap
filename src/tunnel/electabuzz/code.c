#include "../tunnel.h"

void func_802E9C3C_5E6D0C(GObj*);
void func_802E9C60_5E6D30(GObj*);
void func_802E9C98_5E6D68(GObj*);
void func_802E9D04_5E6DD4(GObj*);
void func_802E9C18_5E6CE8(GObj*);
void func_802E9BEC_5E6CBC(GObj*);
void func_802E9F80_5E7050(GObj*);
void func_802E9538_5E6608(GObj*);
void func_802E968C_5E675C(GObj*);
void func_802E9A48_5E6B18(GObj*);
void func_802E9A94_5E6B64(GObj*);
void func_802E9B90_5E6C60(GObj*);
void func_802E9D70_5E6E40(GObj*);
void func_802E9DD8_5E6EA8(GObj*);
void func_802EA030_5E7100(GObj*);
void func_802EA098_5E7168(GObj*);
void func_802EA21C_5E72EC(GObj*);
void func_802EA3A0_5E7470(GObj*);
void func_802EA344_5E7414(GObj*);

extern AnimationHeader D_802EF338_5EC408;
extern AnimationHeader D_802EF34C_5EC41C;
extern AnimationHeader D_802EF360_5EC430;
extern AnimationHeader D_802EF374_5EC444;
extern AnimationHeader D_802EF388_5EC458;
extern AnimationHeader D_802EF39C_5EC46C;
extern AnimationHeader D_802EF3B0_5EC480;
extern AnimationHeader D_802EF3C4_5EC494;
extern AnimationHeader D_802EF3D8_5EC4A8;
extern InteractionHandler D_802EF3EC_5EC4BC[];
extern RandomState D_802EF44C_5EC51C[];
extern InteractionHandler D_802EF464_5EC534[];
extern GObj* D_802EF484_5EC554;
extern GObj* D_802EF488_5EC558;
extern InteractionHandler D_802EF48C_5EC55C[];
extern InteractionHandler D_802EF4EC_5EC5BC[];
extern InteractionHandler D_802EF51C_5EC5EC[];
extern InteractionHandler D_802EF54C_5EC61C[];
extern InteractionHandler D_802EF59C_5EC66C[];
extern InteractionHandler D_802EF5CC_5EC69C[];
extern InteractionHandler D_802EF61C_5EC6EC[];
extern InteractionHandler D_802EF64C_5EC71C[];
extern InteractionHandler D_802EF68C_5EC75C[];
extern s32 D_802EF6AC_5EC77C;
extern InteractionHandler D_802EF6B0_5EC780[];
extern PokemonInitData D_802EF714_5EC7E4;

extern GObj* D_802EFFD0_5ED0A0;
extern GObj* D_802F0070_5ED140;

POKEMON_FUNC(func_802E93D0_5E64A0)
    if (pokemon->behavior == 1) {
        Pokemon_SetState(obj, func_802E9C18_5E6CE8);
    }

    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_HIDDEN | GOBJ_FLAG_2;

    pokemon->transitionGraph = D_802EF464_5EC534;

    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802E944C_5E651C)
    if (pokemon->behavior == 2 || pokemon->behavior == 3) {
        if (D_803430E8_6401B8.bits.unk_01) {
            Pokemon_SetState(obj, func_802E9BEC_5E6CBC);
        } else {
            if (pokemon->behavior == 2) {
                D_802EF484_5EC554 = obj;
            } else {
                D_802EF488_5EC558 = obj;
            }

            pokemon->tangible = true;
            obj->flags = 0;
            Pokemon_SetState(obj, func_802E9F80_5E7050);
        }
    }

    if (!(D_803430E8_6401B8.bits.unk_01)) {
        Pokemon_SetState(obj, func_802E9BEC_5E6CBC);
    }

    pokemon->tangible = true;
    obj->flags = 0;
    Pokemon_SetState(obj, func_802E9538_5E6608);
}

POKEMON_FUNC(func_802E9538_5E6608)
    pokemon->flags |= POKEMON_FLAG_200;
    pokemon->flags |= POKEMON_FLAG_800;

    Pokemon_SetAnimation(obj, &D_802EF338_5EC408);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_802EF48C_5EC55C;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    pokemon->transitionGraph = D_802EF3EC_5EC4BC;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetStateRandom(obj, D_802EF44C_5EC51C);
}

POKEMON_FUNC(func_802E95E8_5E66B8)
    Pokemon_SetAnimation(obj, &D_802EF34C_5EC41C);
    pokemon->pokemonLoopTarget = 5;
    Pokemon_StartPathProc(obj, func_802E968C_5E675C);

    pokemon->transitionGraph = D_802EF3EC_5EC4BC;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED | POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED) {
        Pokemon_SetState(obj, func_802E9538_5E6608);
    }
    
    Pokemon_SetStateRandom(obj, D_802EF44C_5EC51C);
}

POKEMON_FUNC(func_802E968C_5E675C)
    pokemon->hSpeed = 20.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802E96E8_5E67B8)
    Pokemon_StartPathProc(obj, NULL);
    Pokemon_SetAnimation(obj, &D_802EF3B0_5EC480);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &D_802EF3C4_5EC494);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &D_802EF3D8_5EC4A8);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &D_802EF34C_5EC41C);
    Pokemon_StartPathProc(obj, func_802E9A48_5E6B18);
    pokemon->transitionGraph = D_802EF4EC_5EC5BC;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_SetAnimation(obj, &D_802EF39C_5EC46C);
    pokemon->transitionGraph = D_802EF4EC_5EC5BC;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
        
    Pokemon_SetState(obj, func_802E9538_5E6608);
}

POKEMON_FUNC(func_802E97EC_5E68BC)
    Pokemon_StartPathProc(obj, NULL);
    Pokemon_SetAnimation(obj, &D_802EF374_5EC444);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
        
    Pokemon_SetState(obj, func_802E9538_5E6608);
}

POKEMON_FUNC(func_802E9854_5E6924)
    Pokemon_SetAnimation(obj, &D_802EF34C_5EC41C);
    Pokemon_StartPathProc(obj, func_802E9A48_5E6B18);
    pokemon->transitionGraph = D_802EF51C_5EC5EC;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_SetAnimation(obj, &D_802EF39C_5EC46C);
    pokemon->transitionGraph = D_802EF51C_5EC5EC;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
        
    Pokemon_SetState(obj, func_802E9538_5E6608);
}

POKEMON_FUNC(func_802E98F4_5E69C4)
    Pokemon_SetAnimation(obj, &D_802EF34C_5EC41C);
    Pokemon_StartPathProc(obj, func_802E9A48_5E6B18);
    pokemon->transitionGraph = D_802EF54C_5EC61C;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_StartPathProc(obj, func_802E9A94_5E6B64);
    Pokemon_SetAnimation(obj, &D_802EF360_5EC430);
    pokemon->transitionGraph = D_802EF54C_5EC61C;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_StartPathProc(obj, NULL);
    if (!(pokemon->processFlags & POKEMON_PROCESS_TARGET_REACHED)) {
        Pokemon_SetState(obj, func_802E9538_5E6608);
    }
    if (pokemon->interactionTarget == NULL) {
        Pokemon_SetState(obj, func_802E9538_5E6608);
    }

    Pokemon_SetAnimation(obj, &D_802EF388_5EC458);
    pokemon->counter = 48, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_802EF59C_5EC66C;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_EatApple(obj);
    pokemon->transitionGraph = D_802EF59C_5EC66C;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
        
    Pokemon_SetState(obj, func_802E9538_5E6608);
}

POKEMON_FUNC(func_802E9A48_5E6B18)
    Pokemon_TurnToTarget(obj, 0.1f, 0);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802E9A94_5E6B64)
    pokemon->hSpeed = 100.0f;
    Pokemon_RunToTarget(obj, 100.0f, 0.1f, MOVEMENT_FLAG_UPDATE_TARGET_POS | MOVEMENT_FLAG_ON_GROUND);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

static void nullsub(void) {

}

POKEMON_FUNC(func_802E9AF8_5E6BC8)
    Pokemon_SetAnimation(obj, &D_802EF360_5EC430);
    Pokemon_StartPathProc(obj, func_802E9B90_5E6C60);
    pokemon->transitionGraph = D_802EF5CC_5EC69C;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (pokemon->processFlags & POKEMON_PROCESS_TARGET_REACHED) {
        Pokemon_SetState(obj, func_802E9538_5E6608);
    }
        
    Pokemon_SetState(obj, func_802E9AF8_5E6BC8);
}

POKEMON_FUNC(func_802E9B90_5E6C60)
    pokemon->hSpeed = 100.0f;
    Pokemon_RunAwayFromTarget(obj, 1000.0f, 0.1f, MOVEMENT_FLAG_UPDATE_TARGET_POS | MOVEMENT_FLAG_ON_GROUND);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802E9BEC_5E6CBC)
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802E9C18_5E6CE8)
    Pokemon_SetState(obj, func_802E9C3C_5E6D0C);
}

POKEMON_FUNC(func_802E9C3C_5E6D0C)
    Pokemon_SetState(obj, func_802E9C60_5E6D30);
}

POKEMON_FUNC(func_802E9C60_5E6D30)
    Pokemon_StartPathProc(obj, func_802E9C98_5E6D68);
    Pokemon_SetState(obj, func_802E9D04_5E6DD4);
}

POKEMON_FUNC(func_802E9C98_5E6D68)
    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0, 1, 0.033333335f, 0.0f, MOVEMENT_FLAG_UPDATE_TARGET_POS | MOVEMENT_FLAG_ON_GROUND);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802E9D04_5E6DD4)
    pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_SetAnimation(obj, &D_802EF360_5EC430);
    pokemon->transitionGraph = D_802EF61C_5EC6EC;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
        
    Pokemon_SetState(obj, func_802E9D70_5E6E40);
}

POKEMON_FUNC(func_802E9D70_5E6E40)
    D_802EF6AC_5EC77C = 1;
    Pokemon_SetAnimation(obj, &D_802EF338_5EC408);
    pokemon->transitionGraph = D_802EF64C_5EC71C;
    Pokemon_WaitForFlag(obj, 0);
        
    Pokemon_SetState(obj, func_802E9DD8_5E6EA8);
}

POKEMON_FUNC(func_802E9DD8_5E6EA8)
    Pokemon_SetAnimation(obj, &D_802EF3B0_5EC480);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &D_802EF3C4_5EC494);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
        
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802E9E54_5E6F24)
    InteractionHandler* tg;

    if (D_802EF6AC_5EC77C) {
        tg = D_802EF68C_5EC75C;
    } else {
        tg = NULL;
    }

    pokemon->processFlags |= POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_SetAnimation(obj, &D_802EF3B0_5EC480);
    pokemon->transitionGraph = tg;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &D_802EF3C4_5EC494);
    pokemon->transitionGraph = tg;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &D_802EF3D8_5EC4A8);
    pokemon->transitionGraph = tg;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
        
    Pokemon_SetState(obj, func_802E9D04_5E6DD4);
}

POKEMON_FUNC(func_802E9F20_5E6FF0)
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_SetAnimation(obj, &D_802EF374_5EC444);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
        
    Pokemon_SetState(obj, func_802E9D04_5E6DD4);
}

POKEMON_FUNC(func_802E9F80_5E7050)
    f32 yaw = rotation->f[2];

    Pokemon_SetAnimation(obj, &D_802EF338_5EC408);
    Pokemon_StartPathProc(obj, func_802EA098_5E7168);

    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);
    
    rotation->f[2] = yaw;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_SetState(obj, func_802EA030_5E7100);
}

POKEMON_FUNC(func_802EA030_5E7100)
    Pokemon_SetAnimation(obj, &D_802EF338_5EC408);
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    pokemon->transitionGraph = D_802EF6B0_5EC780;    
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
        
    Pokemon_SetState(obj, func_802EA030_5E7100);
}

POKEMON_FUNC(func_802EA098_5E7168)
    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0, 1, 0.06666667f, 0.1f, MOVEMENT_FLAG_TURN_GRADUALLY | MOVEMENT_FLAG_ON_GROUND);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802EA108_5E71D8)
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_SetAnimation(obj, &D_802EF3B0_5EC480);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    
    Pokemon_SetAnimation(obj, &D_802EF3C4_5EC494);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &D_802EF3D8_5EC4A8);
    pokemon->transitionGraph = D_802EF6B0_5EC780;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
        
    Pokemon_SetState(obj, func_802EA21C_5E72EC);
}

POKEMON_FUNC(func_802EA1B4_5E7284)
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_SetAnimation(obj, &D_802EF374_5EC444);
    pokemon->transitionGraph = D_802EF6B0_5EC780;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
        
    Pokemon_SetState(obj, func_802EA21C_5E72EC);
}

POKEMON_FUNC(func_802EA21C_5E72EC)
    pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_SetAnimation(obj, &D_802EF360_5EC430);
    pokemon->transitionGraph = D_802EF6B0_5EC780;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_StartPathProc(obj, func_802EA3A0_5E7470);
    Pokemon_SetAnimation(obj, &D_802EF39C_5EC46C);
    pokemon->counter = 60, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_802EF6B0_5EC780;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    cmdSendCommand(gObjPlayer, PLAYER_CMD_SHAKE_CAMERA, obj);
    if (pokemon->behavior == 2) {
        cmdSendCommand(D_802EFFD0_5ED0A0, TUNNEL_CMD_48, obj);
    } else {
        cmdSendCommand(D_802F0070_5ED140, TUNNEL_CMD_48, obj);
    }

    pokemon->transitionGraph = D_802EF6B0_5EC780;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
        
    Pokemon_SetState(obj, func_802EA344_5E7414);
}

POKEMON_FUNC(func_802EA344_5E7414)
    Pokemon_SetAnimation(obj, &D_802EF338_5EC408);
    pokemon->transitionGraph = D_802EF6B0_5EC780;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
        
    Pokemon_SetState(obj, func_802EA344_5E7414);
}

POKEMON_FUNC(func_802EA3A0_5E7470)
    Pokemon_TurnToTarget(obj, 0.1f, MOVEMENT_FLAG_TURN_TO_PLAYER);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802EA3EC_5E74BC)
    EnvSound_PlaySound(obj, 1, SOUND_ID_361);
    Pokemon_StopAuxProc(obj);
}

static void nullsub2(void) {

}

GObj* electabuzz_Spawn(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802EF714_5EC7E4);
}

POKEMON_FUNC(func_802EA45C_5E752C)
    if (pokemon->behavior != 0) {
        pokemonRemoveOne(obj);
    }
}
