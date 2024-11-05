#include "tunnel.h"

void func_802E3B8C_5E0C5C(GObj*);
void func_802E3CC8_5E0D98(GObj*);
void func_802E4234_5E1304(GObj*);
void func_802E3AC8_5E0B98(GObj*);
void func_802E3EE4_5E0FB4(GObj*);
void func_802E3AC8_5E0B98(GObj*);
void func_802E3E44_5E0F14(GObj*);
void func_802E3D80_5E0E50(GObj*);
void func_802E3F8C_5E105C(GObj*);
void func_802E40D4_5E11A4(GObj*);
void func_802E44DC_5E15AC(GObj*);
void func_802E45B4_5E1684(GObj*);
void func_802E4710_5E17E0(GObj*);
void func_802E4668_5E1738(GObj*);
void func_802E4A84_5E1B54(GObj*);
void func_802E487C_5E194C(GObj*);
void func_802E3FD8_5E10A8(GObj*);
void func_802E4434_5E1504(GObj*);
void func_802E4124_5E11F4(GObj*);
void func_802E3A14_5E0AE4(GObj*);
void func_802E3C18_5E0CE8(GObj*);
void func_802E3CA4_5E0D74(GObj*);
void func_802E3E20_5E0EF0(GObj*);
void func_802E49A4_5E1A74(GObj*);
void func_802E480C_5E18DC(GObj*);
void func_802E4844_5E1914(GObj*);
void func_802E4964_5E1A34(GObj*);

s32 D_802EE200_5EB2D0[] = { 0xDC };
s32 D_802EE204_5EB2D4[] = { 0xDD };
s32 D_802EE208_5EB2D8[] = { 0xDE };

AnimationHeader D_802EE20C_5EB2DC = {
    1.0,
    60,
    0x8015EBD0,
    NULL,
    NULL
};

AnimationHeader D_802EE220_5EB2F0 = {
    0.6,
    80,
    0x8015EE30,
    NULL,
    NULL
};

AnimationHeader D_802EE234_5EB304 = {
    1.0,
    60,
    0x8015E8C0,
    0x80160260,
    D_802EE200_5EB2D0
};

AnimationHeader D_802EE248_5EB318 = {
    1.0,
    60,
    0x8015E6A0,
    NULL,
    NULL
};

AnimationHeader D_802EE25C_5EB32C = {
    0.7,
    60,
    0x8015F3B0,
    NULL,
    D_802EE204_5EB2D4
};

AnimationHeader D_802EE270_5EB340 = {
    0.85,
    104,
    0x8015F900,
    NULL,
    D_802EE208_5EB2D8
};

GObj* D_802EE284_5EB354 = NULL;
GObj* D_802EE288_5EB358 = NULL;
GObj* D_802EE28C_5EB35C = NULL;
GObj* D_802EE290_5EB360 = NULL;
GObj* D_802EE294_5EB364 = NULL;

s32 D_802EE298_5EB368 = 0;

AnimationHeader* D_802EE29C_5EB36C = NULL;
s32 D_802EE2A0_5EB370 = 0;

InteractionHandler D_802EE2A4_5EB374[] = {
    { POKEMON_CMD_9, func_802E3B8C_5E0C5C, 0, NULL },
    { POKEMON_CMD_13, func_802E3C18_5E0CE8, 0, NULL },
    { POKEMON_CMD_10, func_802E3CA4_5E0D74, 0, NULL },
    { POKEMON_CMD_14, func_802E3CC8_5E0D98, 0, NULL },
    { POKEMON_CMD_15, func_802E3E20_5E0EF0, 0, NULL },
    { POKEMON_CMD_16, func_802E3FD8_5E10A8, 250, NULL },
    { TUNNEL_CMD_55, func_802E4124_5E11F4, 1000, NULL },
    { TUNNEL_CMD_44, func_802E4434_5E1504, 0, NULL },
    { TUNNEL_CMD_45, func_802E487C_5E194C, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

RandomState D_802EE344_5EB414[] = {
    { 100, func_802E3AC8_5E0B98 },
    { 0, NULL },
};

InteractionHandler D_802EE354_5EB424[] = {
    { TUNNEL_CMD_55, func_802E4124_5E11F4, 1000, NULL },
    { TUNNEL_CMD_44, func_802E4434_5E1504, 0, NULL },
    { TUNNEL_CMD_45, func_802E487C_5E194C, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802EE394_5EB464[] = {
    { TUNNEL_CMD_55, func_802E4124_5E11F4, 1000, NULL },
    { TUNNEL_CMD_44, func_802E4434_5E1504, 0, NULL },
    { TUNNEL_CMD_45, func_802E487C_5E194C, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802EE3D4_5EB4A4[] = {
    { POKEMON_CMD_9, func_802E3B8C_5E0C5C, 0, NULL },
    { POKEMON_CMD_13, func_802E3C18_5E0CE8, 0, NULL },
    { POKEMON_CMD_10, func_802E3CA4_5E0D74, 0, NULL },
    { POKEMON_CMD_14, func_802E3CC8_5E0D98, 0, NULL },
    { TUNNEL_CMD_44, func_802E4434_5E1504, 0, NULL },
    { TUNNEL_CMD_45, func_802E487C_5E194C, 0, NULL },
    { POKEMON_CMD_16, func_802E3FD8_5E10A8, 250, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802EE454_5EB524[] = {
    { POKEMON_CMD_9, func_802E3B8C_5E0C5C, 0, NULL },
    { POKEMON_CMD_13, func_802E3B8C_5E0C5C, 0, NULL },
    { POKEMON_CMD_14, func_802E3CC8_5E0D98, 0, NULL },
    { POKEMON_CMD_16, func_802E3FD8_5E10A8, 250, NULL },
    { TUNNEL_CMD_44, func_802E4434_5E1504, 0, NULL },
    { TUNNEL_CMD_45, func_802E487C_5E194C, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802EE4C4_5EB594[] = {
    { TUNNEL_CMD_44, func_802E4434_5E1504, 0, NULL },
    { TUNNEL_CMD_45, func_802E487C_5E194C, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802EE4F4_5EB5C4[] = {
    { TUNNEL_CMD_44, func_802E4434_5E1504, 0, NULL },
    { TUNNEL_CMD_45, func_802E487C_5E194C, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802EE524_5EB5F4[] = {
    { TUNNEL_CMD_44, func_802E4434_5E1504, 0, NULL },
    { TUNNEL_CMD_45, func_802E487C_5E194C, 0, NULL },
    { POKEMON_CMD_16, func_802E3FD8_5E10A8, 250, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802EE564_5EB634[] = {
    { TUNNEL_CMD_55, func_802E4124_5E11F4, 1000, NULL },
    { TUNNEL_CMD_44, func_802E4434_5E1504, 0, NULL },
    { TUNNEL_CMD_45, func_802E487C_5E194C, 0, NULL },
    { POKEMON_CMD_16, func_802E3FD8_5E10A8, 250, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

POKEMON_FUNC(func_802E39A0_5E0A70)
    while (true) {
        if (gDirectionIndex < 0) {
            cmdSendCommandToLink(LINK_POKEMON, TUNNEL_CMD_55, obj);
        }
        ohWait(1);
    }
}

POKEMON_FUNC(func_802E3A14_5E0AE4)
    pokemon->miscVars[3].field1 = 0;
    pokemon->miscVars[0].obj = NULL;
    pokemon->miscVars[1].field1 = false;
    pokemon->miscVars[2].field0 = pokemon->collisionRadius;
    Pokemon_StartAuxProc(obj, func_802E4234_5E1304);

    switch (pokemon->behavior) {
        case 1:
            Pokemon_StartAuxProc(obj, func_802E39A0_5E0A70);
            D_802EE284_5EB354 = obj;
            break;
        case 2:
            D_802EE288_5EB358 = obj;
            break;
        case 3:
            D_802EE28C_5EB35C = obj;
            break;
    }

    Pokemon_SetState(obj, func_802E3AC8_5E0B98);
}

POKEMON_FUNC(func_802E3AC8_5E0B98)
    pokemon->collisionRadius = pokemon->miscVars[2].field0;
    Pokemon_SetAnimation(obj, &D_802EE220_5EB2F0);
    if (obj == D_802EE290_5EB360) {
        D_802EE29C_5EB36C = &D_802EE220_5EB2F0;
    }
    Pokemon_StartPathProc(obj, NULL);
    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_802EE2A4_5EB374;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    pokemon->miscVars[3].field1 = 0;
    pokemon->transitionGraph = D_802EE2A4_5EB374;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetStateRandom(obj, D_802EE344_5EB414);
}

POKEMON_FUNC(func_802E3B8C_5E0C5C)
    Pokemon_SetAnimation(obj, &D_802EE25C_5EB32C);
    if (obj == D_802EE290_5EB360) {
        D_802EE29C_5EB36C = &D_802EE25C_5EB32C;
    }
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802EE354_5EB424;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_802E3EE4_5E0FB4);
}

POKEMON_FUNC(func_802E3C18_5E0CE8)
    Pokemon_SetAnimation(obj, &D_802EE25C_5EB32C);
    if (obj == D_802EE290_5EB360) {
        D_802EE29C_5EB36C = &D_802EE25C_5EB32C;
    }
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802EE394_5EB464;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_802E3AC8_5E0B98);
}

POKEMON_FUNC(func_802E3CA4_5E0D74)
    Pokemon_SetState(obj, func_802E3B8C_5E0C5C);
}

POKEMON_FUNC(func_802E3CC8_5E0D98)
    pokemon->flags &= ~POKEMON_FLAG_8;
    Pokemon_SetAnimation(obj, &D_802EE20C_5EB2DC);
    if (obj == D_802EE290_5EB360) {
        D_802EE29C_5EB36C = &D_802EE20C_5EB2DC;
    }
    Pokemon_StartPathProc(obj, func_802E3D80_5E0E50);
    pokemon->transitionGraph = D_802EE3D4_5EB4A4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (pokemon->currGround.surfaceType == SURFACE_TYPE_337FB2) {
        Pokemon_SetState(obj, func_802E3AC8_5E0B98);
    }
    Pokemon_SetState(obj, func_802E3E44_5E0F14);
}

POKEMON_FUNC(func_802E3D80_5E0E50)
    Pokemon_TurnToTarget(obj, 0.1f, 0);
    // clang-format off
    Pokemon_SetAnimation(obj, &D_802EE248_5EB318); \
    if (obj == D_802EE290_5EB360) {
        D_802EE29C_5EB36C = &D_802EE248_5EB318;
    }
    // clang-format on
    pokemon->hSpeed = 80.0f;
    Pokemon_RunToTarget(obj, 50.0f, 0.1f, MOVEMENT_FLAG_UPDATE_TARGET_POS | MOVEMENT_FLAG_ON_GROUND);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802E3E20_5E0EF0)
    Pokemon_SetState(obj, func_802E3CC8_5E0D98);
}

POKEMON_FUNC(func_802E3E44_5E0F14)
    Pokemon_SetAnimation(obj, &D_802EE270_5EB340);
    if (obj == D_802EE290_5EB360) {
        D_802EE29C_5EB36C = &D_802EE270_5EB340;
    }

    pokemon->transitionGraph = D_802EE454_5EB524;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    if (pokemon->interactionTarget != NULL) {
        Pokemon_SetState(obj, func_802E3E44_5E0F14);
    }

    Pokemon_SetStateRandom(obj, D_802EE344_5EB414);
}

POKEMON_FUNC(func_802E3EE4_5E0FB4)
    Pokemon_StartPathProc(obj, func_802E3F8C_5E105C);
    Pokemon_SetAnimation(obj, &D_802EE234_5EB304);
    if (obj == D_802EE290_5EB360) {
        D_802EE29C_5EB36C = &D_802EE234_5EB304;
    }
    pokemon->counter = 180, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_802EE2A4_5EB374;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_SetState(obj, func_802E3AC8_5E0B98);
}

POKEMON_FUNC(func_802E3F8C_5E105C)
    Pokemon_TurnToTarget(obj, 0.1f, MOVEMENT_FLAG_TURN_TO_PLAYER | MOVEMENT_FLAG_STOP_WHEN_TURN_COMPLETED | MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802E3FD8_5E10A8)
    pokemon->flags |= POKEMON_FLAG_8;
    if (pokemon->miscVars[3].field1 >= 5) {
        pokemon->collisionRadius = 0.0f;
    } else {
        pokemon->miscVars[3].field1++;
    }
    Pokemon_SetAnimation(obj, &D_802EE234_5EB304);
    if (obj == D_802EE290_5EB360) {
        D_802EE29C_5EB36C = &D_802EE234_5EB304;
    }
    Pokemon_StartPathProc(obj, func_802E40D4_5E11A4);
    pokemon->transitionGraph = D_802EE4C4_5EB594;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (pokemon->processFlags & POKEMON_PROCESS_TARGET_REACHED) {
        Pokemon_SetState(obj, func_802E3AC8_5E0B98);
    }
    // clang-format off
    pokemon->transitionGraph = D_802EE4C4_5EB594; \
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    // clang-format on

    Pokemon_SetState(obj, func_802E3AC8_5E0B98);
}

POKEMON_FUNC(func_802E40D4_5E11A4)
    pokemon->hSpeed = 160.0f;
    Pokemon_RunAwayDefault(obj, 1000.0f);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802E4124_5E11F4)
    pokemon->flags |= POKEMON_FLAG_8;
    Pokemon_StartPathProc(obj, func_802E3F8C_5E105C);
    Pokemon_SetAnimation(obj, &D_802EE234_5EB304);
    if (obj == D_802EE290_5EB360) {
        D_802EE29C_5EB36C = &D_802EE234_5EB304;
    }

    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_802EE4F4_5EB5C4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_802EE524_5EB5F4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_802EE564_5EB634;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_SetState(obj, func_802E3AC8_5E0B98);
}

POKEMON_FUNC(func_802E4234_5E1304)
    s32 i;
    bool s4 = false;
    s32 unused;
    GObj** sp48[] = { &D_802EE284_5EB354, &D_802EE288_5EB358, &D_802EE28C_5EB35C };

    while (!s4) {
        if (D_802EE290_5EB360 == NULL) {
            for (i = 0; i < ARRAY_COUNT(sp48); i++) {
                GObj* obj2 = *(sp48[i]);
                if (obj != obj2 && obj2 != NULL && Pokemon_GetDistance(obj, obj2) < 300.0f) {
                    D_802EE290_5EB360 = obj;
                    pokemon->miscVars[0].obj = obj2;
                    s4 = true;
                    GET_POKEMON(obj2)->miscVars[0].obj = obj;
                }
            }
        } else if (pokemon->miscVars[0].obj != NULL) {
            s4 = true;
            while (!pokemon->miscVars[1].field1) {
                cmdSendCommand(obj, TUNNEL_CMD_44, obj);
                ohWait(1);
            }
        } else if (Pokemon_GetDistance(D_802EE290_5EB360, obj) < 300.0f) {
            pokemon->miscVars[0].obj = D_802EE290_5EB360;
        }
        ohWait(1);
    }

    Pokemon_StopAuxProc(obj);
}

void func_802E43B0_5E1480(GObj* arg0, Vec3f* arg1) {
    Vec3f sp1C = { 0, 0, 0 };
    DObj* dobj;

    if (arg0 == D_802EE294_5EB364) {
        dobj = D_802EE290_5EB360->data.dobj->firstChild->next->next;
    } else {
        dobj = D_802EE290_5EB360->data.dobj->firstChild;
    }

    func_800A5E98(arg1, &sp1C, dobj);
}

POKEMON_FUNC(func_802E4434_5E1504)
    pokemon->miscVars[1].field1 = true;
    pokemon->collisionRadius = pokemon->miscVars[2].field0;
    Pokemon_SetAnimation(obj, &D_802EE234_5EB304);
    Pokemon_StartPathProc(obj, func_802E44DC_5E15AC);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (++D_802EE2A0_5EB370 == 2) {
        cmdSendCommandToLink(LINK_POKEMON, TUNNEL_CMD_45, obj);
    }

    Pokemon_SetState(obj, func_802E45B4_5E1684);
}

POKEMON_FUNC(func_802E44DC_5E15AC)
    Vec3f sp3C;

    do {
        ohWait(1);
        pokemon->hSpeed = 320.0f;
        func_802E43B0_5E1480(pokemon->miscVars[0].obj, &sp3C);
        Pokemon_SetTargetPos(obj, sp3C.x, sp3C.z);
    } while (!Pokemon_StepToTargetPos(obj, 0.1f, MOVEMENT_FLAG_ON_GROUND));

    position->v.x = sp3C.x;
    position->v.z = sp3C.z;
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

InteractionHandler D_802EE5CC_5EB69C[] = {
    { POKEMON_CMD_9, NULL, 0, func_802E480C_5E18DC },
    { POKEMON_CMD_13, NULL, 0, func_802E4844_5E1914 },
    { TUNNEL_CMD_45, func_802E49A4_5E1A74, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

POKEMON_FUNC(func_802E45B4_5E1684)
    Pokemon_StartPathProc(obj, func_802E4710_5E17E0);

    while (D_802EE29C_5EB36C == NULL) {
        pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
        pokemon->transitionGraph = D_802EE5CC_5EB69C;
        Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);
    }
    Pokemon_SetState(obj, func_802E4668_5E1738);
}

POKEMON_FUNC(func_802E4668_5E1738)
    pokemon->flags &= ~POKEMON_FLAG_8;
    if (GET_POKEMON(D_802EE290_5EB360)->flags & POKEMON_FLAG_8) {
        pokemon->flags |= POKEMON_FLAG_8;
    }
    Pokemon_SetAnimation(obj, D_802EE29C_5EB36C);

    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_802EE5CC_5EB69C;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_SetState(obj, func_802E4668_5E1738);
}

POKEMON_FUNC(func_802E4710_5E17E0)
    bool s1 = false;
    Vec3f sp50;
    Mtx4Float* anotherRotation = &GET_TRANSFORM(pokemon->miscVars[0].obj->data.dobj)->rot;

    while (true) {
        func_802E43B0_5E1480(pokemon->miscVars[0].obj, &sp50);
        position->v.x = sp50.x;
        position->v.y = sp50.y;
        position->v.z = sp50.z;
        if (s1) {
            rotation->f[2] = anotherRotation->f[2];
        } else if (Pokemon_Turn(model, anotherRotation->f[2], 0.034906585f)) {
            s1 = true;
        }
        ohWait(1);
    }
}

POKEMON_FUNC(func_802E480C_5E18DC)
    cmdSendCommand(D_802EE290_5EB360, POKEMON_CMD_9, obj);
    Pokemon_StopAuxProc(obj);
}

POKEMON_FUNC(func_802E4844_5E1914)
    cmdSendCommand(D_802EE290_5EB360, POKEMON_CMD_13, obj);
    Pokemon_StopAuxProc(obj);
}

POKEMON_FUNC(func_802E487C_5E194C)
    InteractionHandler saved[] = {
        { POKEMON_CMD_16, func_802E4964_5E1A34, 250, NULL },
        { POKEMON_CMD_58, NULL, 0, NULL },
    };

    pokemon->collisionRadius = pokemon->miscVars[2].field0;
    Pokemon_StartPathProc(obj, NULL);
    pokemon->flags |= POKEMON_FLAG_8;
    Pokemon_SetAnimation(obj, &D_802EE234_5EB304);
    pokemon->counter = 60, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = saved;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_SetState(obj, func_802E4964_5E1A34);
}

POKEMON_FUNC(func_802E4964_5E1A34)
    func_802E5094_5E2164();
    cmdSendCommandToLink(LINK_POKEMON, TUNNEL_CMD_46, obj);
    Pokemon_SetState(obj, func_802E4A84_5E1B54);
}

POKEMON_FUNC(func_802E49A4_5E1A74)
    InteractionHandler saved[] = {
        { TUNNEL_CMD_46, func_802E4A84_5E1B54, 0, NULL },
        { POKEMON_CMD_58, NULL, 0, NULL },
    };

    Pokemon_StartPathProc(obj, NULL);
    pokemon->flags |= POKEMON_FLAG_8;
    Pokemon_SetAnimation(obj, &D_802EE234_5EB304);
    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = saved;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_SetState(obj, func_802E49A4_5E1A74);
}

POKEMON_FUNC(func_802E4A84_5E1B54)
    switch (pokemon->behavior) {
        case 1:
            D_802EE284_5EB354 = NULL;
            break;
        case 2:
            D_802EE288_5EB358 = NULL;
            break;
        case 3:
            D_802EE28C_5EB35C = NULL;
            break;
    }
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

PokemonAnimationSetup D_802EE64C_5EB71C = {
    &D_802EE20C_5EB2DC,
    func_802E3A14_5E0AE4,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData D_802EE660_5EB730 = {
    0x8032C180,
    0x80329B40,
    renderPokemonModelTypeDFogged,
    &D_802EE64C_5EB71C,
    { 2.2, 2.2, 2.2 },
    { 0, 250, 0 },
    20,
    POKEMON_FLAG_20 | POKEMON_FLAG_4 | POKEMON_FLAG_1,
    0,
    0,
    0,
    { 0, 0, 0 }
};

GObj* func_802E4AFC_5E1BCC(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802EE660_5EB730);
}
