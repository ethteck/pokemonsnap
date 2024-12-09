#include "tunnel.h"

void func_802EA79C_5E786C(GObj*);
void func_802EA970_5E7A40(GObj*);

extern int D_802EF9F0_5ECAC0;
extern CollisionModel D_802EF9E4_5ECAB4;
extern GObj* D_802EF9F4_5ECAC4[];
extern AnimationHeader D_802EFA2C_5ECAFC;
extern AnimationHeader D_802EFA40_5ECB10;
extern PokemonInitData D_802EFA68_5ECB38;

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

    D_802EF9F4_5ECAC4[pokemon->behavior] = NULL;
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

    D_802EF9F4_5ECAC4[pokemon->behavior] = NULL;
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

s32 func_802EAB44_5E7C14(GObj* obj, DObj* node, Vec3f* inPos, Vec3f* inVel, Vec3f* outPos, Vec3f* outVel) {
    Mtx3Float pos;
    Mtx4Float rot;
    Mtx3Float scale;
    Mtx4f mtx;
    Mtx4f mtx2;
    f32 yaw;
    int unuded;

    if (obj == NULL) {
        return -1;
    }

    pos = GET_TRANSFORM(obj->data.dobj)->pos;
    rot = GET_TRANSFORM(obj->data.dobj)->rot;
    scale = GET_TRANSFORM(obj->data.dobj)->scale;
    yaw = rot.v.y;
    hal_rotate_rpy_translate_scale_f(mtx, pos.v.x, pos.v.y, pos.v.z,
                                     0.0f, rot.v.y, 0.0f,
                                     scale.v.x, scale.v.x, scale.v.x);

    pos = node->position;
    rot = node->rotation;
    scale = node->scale;
    hal_rotate_rpy_translate_scale_f(mtx2, pos.v.x, pos.v.y, pos.v.z,
                                     rot.v.x, rot.v.y, rot.v.z,
                                     scale.v.x, scale.v.y, scale.v.z);

    guMtxCatF(mtx2, mtx, mtx);
    
    pos.v.x = mtx[3][0];
    pos.v.y = mtx[3][1];
    pos.v.z = mtx[3][2];
    rot.v.y += yaw;

    if (StaticObject_CollideOne(inPos, inVel, outPos, outVel, &D_802EF9E4_5ECAB4, pos.v, rot.v)) {
        return PokemonID_1009;
    }

    return -1;
}

s32 func_802EADAC_5E7E7C(GObj* obj, Vec3f* inPos, Vec3f* inVel, Vec3f* outPos, Vec3f* outVel) {
    DObj* node1;
    DObj* node2;

    if (obj == NULL ||
        obj->data.dobj == NULL ||
        obj->data.dobj->firstChild == NULL ||
        obj->data.dobj->firstChild->firstChild == NULL ||
        obj->data.dobj->firstChild->firstChild->next == NULL) {
        return -1;
    }

    node1 = obj->data.dobj->firstChild->firstChild;
    node2 = node1->next;

    if (func_802EAB44_5E7C14(obj, node1, inPos, inVel, outPos, outVel) >= 0) {
        return PokemonID_1009;
    }

    if (func_802EAB44_5E7C14(obj, node2, inPos, inVel, outPos, outVel) >= 0) {
        return PokemonID_1009;
    }

    return -1;
}

s32 func_802EAE7C_5E7F4C(Vec3f* inPos, Vec3f* inVel, Vec3f* outPos, Vec3f* outVel) {
    s32 res;

    if (D_802EF9F4_5ECAC4[1] != NULL) {
        res = func_802EADAC_5E7E7C(D_802EF9F4_5ECAC4[1], inPos, inVel, outPos, outVel);
        if (res >= 0) {
            return res;
        }
    }

    if (D_802EF9F4_5ECAC4[2] != NULL) {
        res = func_802EADAC_5E7E7C(D_802EF9F4_5ECAC4[2], inPos, inVel, outPos, outVel);
        if (res >= 0) {
            return res;
        }
    }

    return -1;
}

GObj* func_802EAF18_5E7FE8(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    GObj* obj;
    Pokemon* pokemon;

    obj = Pokemon_SpawnDlLink4(objID, id, block, blockB, spawn, &D_802EFA68_5ECB38);
    if (obj == NULL) {
        return NULL;
    }

    pokemon = GET_POKEMON(obj);
    D_802EF9F4_5ECAC4[pokemon->behavior] = obj;
    if (!D_802EF9F0_5ECAC0) {
        InitOneCollisionModel(&D_802EF9E4_5ECAB4);
        Items_func_8035CA1C(func_802EAE7C_5E7F4C);
        D_802EF9F0_5ECAC0 = true;
    }

    return obj;
}
