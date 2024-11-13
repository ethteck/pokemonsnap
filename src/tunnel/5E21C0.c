#include "tunnel.h"

void func_802E53DC_5E24AC(GObj*);
void func_802E5668_5E2738(GObj*);
void func_802E583C_5E290C(GObj*);
void func_802E53B8_5E2488(GObj*);
void func_802E55D8_5E26A8(GObj*);
void func_802E5644_5E2714(GObj*);
void func_802E54B4_5E2584(GObj*);
void func_802E5818_5E28E8(GObj*);
void func_802E5244_5E2314(GObj*);
void func_802E5448_5E2518(GObj*);
void func_802E54F0_5E25C0(GObj*);
void func_802E556C_5E263C(GObj*);
void func_802E56D8_5E27A8(GObj*);
void func_802E58B0_5E2980(GObj*);

extern AnimationHeader D_802EE7EC_5EB8BC;
extern AnimationHeader D_802EE800_5EB8D0;
extern AnimationHeader D_802EE814_5EB8E4;
extern AnimationHeader D_802EE828_5EB8F8;
extern InteractionHandler D_802EE83C_5EB90C[];
extern InteractionHandler D_802EE88C_5EB95C[];
extern InteractionHandler D_802EE8B0_5EB980[];
extern InteractionHandler D_802EE900_5EB9D0[];
extern GObj* D_802EE8AC_5EB97C;
extern PokemonInitData D_802EE95C_5EBA2C;

extern GObj* D_802EEECC_5EBF9C;

POKEMON_FUNC(func_802E50F0_5E21C0)
    ohWait(260);
    pokemon->collisionOffset.x = 54.0f;
    Pokemon_StopAuxProc(obj);
}

POKEMON_FUNC(func_802E5134_5E2204)
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802E5160_5E2230)
    if (pokemon->behavior == 1) {
        Pokemon_SetState(obj, func_802E53B8_5E2488);
    }
    if (pokemon->behavior == 2) {
        Pokemon_SetState(obj, func_802E55D8_5E26A8);
    }
    if (pokemon->behavior == 3) {
        Pokemon_SetState(obj, func_802E5644_5E2714);
    }
    if (pokemon->behavior == 4) {
        Pokemon_SetState(obj, func_802E54B4_5E2584);
    }
    if (pokemon->behavior == 5) {
        Pokemon_SetState(obj, func_802E5818_5E28E8);
    }

    Pokemon_SetState(obj, func_802E5244_5E2314);
}

POKEMON_FUNC(func_802E5244_5E2314)
    Pokemon_SetAnimation(obj, &D_802EE7EC_5EB8BC);
    pokemon->transitionGraph = D_802EE83C_5EB90C;
    Pokemon_WaitForFlag(obj, 0);

    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802E529C_5E236C)
    Pokemon_StartPathProc(obj, NULL);
    Pokemon_StartAuxProc(obj, func_802E50F0_5E21C0);
    Pokemon_SetAnimation(obj, &D_802EE800_5EB8D0);
    pokemon->counter = 159, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    switch (pokemon->behavior) {
        case 1:
            cmdSendCommandToLink(LINK_POKEMON, TUNNEL_CMD_37, obj);
            break;
        case 4:
            cmdSendCommand(D_802EEECC_5EBF9C, TUNNEL_CMD_37, obj);
            break;
        default:
            cmdSendCommandToLink(LINK_POKEMON, TUNNEL_CMD_39, obj);
            break;
    }
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &D_802EE814_5EB8E4);
    pokemon->transitionGraph = D_802EE88C_5EB95C;
    Pokemon_WaitForFlag(obj, 0);

    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802E53B8_5E2488)
    Pokemon_SetState(obj, func_802E53DC_5E24AC);
}

POKEMON_FUNC(func_802E53DC_5E24AC)
    Pokemon_SetAnimation(obj, &D_802EE828_5EB8F8);
    Pokemon_StartPathProc(obj, func_802E5448_5E2518);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_SetState(obj, func_802E529C_5E236C);
}

POKEMON_FUNC(func_802E5448_5E2518)
    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0, 1, 0.033333335f, 0.0f, MOVEMENT_FLAG_UPDATE_TARGET_POS | MOVEMENT_FLAG_ON_GROUND);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802E54B4_5E2584)
    pokemon->flags |= POKEMON_FLAG_200;
    D_802EE8AC_5EB97C = obj;
    Pokemon_SetState(obj, func_802E54F0_5E25C0);
}

POKEMON_FUNC(func_802E54F0_5E25C0)
    Pokemon_SetAnimation(obj, &D_802EE828_5EB8F8);
    Pokemon_StartPathProc(obj, func_802E556C_5E263C);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    cmdSendCommandToLink(LINK_POKEMON, TUNNEL_CMD_40, obj);
    Pokemon_SetState(obj, func_802E529C_5E236C);
}

POKEMON_FUNC(func_802E556C_5E263C)
    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0, 1, 0.043333337f, 0.0f, MOVEMENT_FLAG_UPDATE_TARGET_POS | MOVEMENT_FLAG_ON_GROUND);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802E55D8_5E26A8)
    Pokemon_SetAnimation(obj, &D_802EE7EC_5EB8BC);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802EE83C_5EB90C;
    Pokemon_WaitForFlag(obj, 0);

    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802E5644_5E2714)
    Pokemon_SetState(obj, func_802E5668_5E2738);
}

POKEMON_FUNC(func_802E5668_5E2738)
    Pokemon_SetAnimation(obj, &D_802EE828_5EB8F8);
    Pokemon_StartPathProc(obj, func_802E56D8_5E27A8);
    pokemon->transitionGraph = D_802EE8B0_5EB980;
    Pokemon_WaitForFlag(obj, 0);

    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802E56D8_5E27A8)
    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0, 0, 0.033333335f, 0.0f, MOVEMENT_FLAG_UPDATE_TARGET_POS | MOVEMENT_FLAG_ON_GROUND); // BUG? start = end = 0
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802E5748_5E2818)
    Pokemon_StartPathProc(obj, NULL);
    Pokemon_StartAuxProc(obj, func_802E50F0_5E21C0);
    Pokemon_SetAnimation(obj, &D_802EE800_5EB8D0);
    pokemon->counter = 159, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    cmdSendCommandToLink(LINK_POKEMON, TUNNEL_CMD_39, obj);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &D_802EE814_5EB8E4);
    pokemon->transitionGraph = D_802EE88C_5EB95C;
    Pokemon_WaitForFlag(obj, 0);

    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802E5818_5E28E8)
    Pokemon_SetState(obj, func_802E583C_5E290C);
}

POKEMON_FUNC(func_802E583C_5E290C)
    Pokemon_SetAnimation(obj, &D_802EE7EC_5EB8BC);
    Pokemon_StartPathProc(obj, func_802E58B0_5E2980);
    pokemon->transitionGraph = D_802EE900_5EB9D0;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_SetState(obj, func_802E5244_5E2314);
}

POKEMON_FUNC(func_802E58B0_5E2980)
    s32 blockCount;
    f32 blockPart;

    while (true) {
        getLevelProgress(&blockCount, &blockPart);
        if (blockCount < 6 && (blockCount != 5 || !(blockPart >= 0.35f))) {
            ohWait(1);
        } else {
            break;
        }
    }
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    pokemon->pathProc = NULL;
    omEndProcess(NULL);
}
typedef struct UnkBlueShark2 {
    /* 0x0 */ u16 unk0;
    /* 0x2 */ u16 unk2;
    /* 0x0 */ u16 unk4;
    /* 0x2 */ u16 unk6;
} UnkBlueShark2; // size: 0x4

extern UnkBlueShark2 D_802EE940_5EBA10;

void Pokemon_WaitForFlag(GObj* obj, s32 flags);

#define SET_ANIM_FRAME(obj, pokemon, frame, flag) \
    pokemon->pokemonLoopTarget = 1; \
    pokemon->lastAnimationFrame = frame; \
    pokemon->transitionGraph = NULL; \
    Pokemon_WaitForFlag(obj, flag);

POKEMON_FUNC(func_802E5968_5E2A38)
    InterpData* path;
    f32 eyex, eyey, eyez;
    s32 i;
    Vec3f* point;
    WorldBlock* block;
    UnkBlueShark2 sp2C = D_802EE940_5EBA10;

    Pokemon_StartPathProc(obj, NULL);
    Pokemon_ForceAnimationAtTime(obj, &D_802EE800_5EB8D0, 0.0f);
    SET_ANIM_FRAME(obj, pokemon, 170.0f, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_RemovePokemons(&sp2C);
    cmdSendCommand(gObjPlayer, PLAYER_CMD_8, obj);
    ohWait(1);

    path = pokemon->path;
    for (i = 1; i < path->numPoints; i++) {
        block = getCurrentWorldBlock();
        point = path->points;

        gMainCamera->viewMtx.lookAt.at.x = -(block->descriptor->worldPos.x * 100.0f);
        gMainCamera->viewMtx.lookAt.at.y = -(block->descriptor->worldPos.y * 100.0f);
        gMainCamera->viewMtx.lookAt.at.z = -(block->descriptor->worldPos.z * 100.0f);

        gMainCamera->viewMtx.lookAt.at.x += point->x * 100.0f;
        gMainCamera->viewMtx.lookAt.at.y += point->y * 100.0f;
        gMainCamera->viewMtx.lookAt.at.z += point->z * 100.0f;

        eyex = -(block->descriptor->worldPos.x * 100.0f);
        eyey = -(block->descriptor->worldPos.y * 100.0f);
        eyez = -(block->descriptor->worldPos.z * 100.0f);

        point = &path->points[i];
        eyex += (point->x * 100.0f);
        eyey += (point->y * 100.0f);
        eyez += (point->z * 100.0f);

        gMainCamera->viewMtx.lookAt.eye.x = eyex;
        gMainCamera->viewMtx.lookAt.eye.y = eyey;
        gMainCamera->viewMtx.lookAt.eye.z = eyez;

        if (i == path->numPoints - 1) {
            break;
        }

        Pokemon_ForceAnimationAtTime(obj, &D_802EE800_5EB8D0, 130.0f);
        SET_ANIM_FRAME(obj, pokemon, 170.0f, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    }

    auPlaySoundWithParams(SOUND_ID_60, 0x7000, 64, 1.0f, 0);
    Pokemon_ForceAnimationAtTime(obj, &D_802EE800_5EB8D0, 130.0f);

    SET_ANIM_FRAME(obj, pokemon, 220.0f, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    cmdSendCommandToLink(LINK_POKEMON, TUNNEL_CMD_54, obj);
    Pokemon_SetAnimation(obj, &D_802EE814_5EB8E4);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, NULL);
}

GObj* electrode_Spawn(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802EE95C_5EBA2C);
}
