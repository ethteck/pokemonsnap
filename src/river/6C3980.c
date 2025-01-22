#include "common.h"
#include "world/world.h"
#include "app_level/app_level.h"
#include "app_render/app_render.h"
#include "app_render/particle.h"
#include "river.h"

void func_802DBD04_6C3AE4(GObj*);

extern AnimationHeader D_802E339C_6CB17C;
extern AnimationHeader D_802E33B0_6CB190;
extern AnimationHeader D_802E33C4_6CB1A4;
extern AnimationHeader D_802E33D8_6CB1B8;
extern AnimationHeader D_802E33EC_6CB1CC;
extern AnimationHeader D_802E3400_6CB1E0;
extern AnimationHeader D_802E3414_6CB1F4;
extern AnimationHeader D_802E3428_6CB208;
extern AnimationHeader D_802E343C_6CB21C;
extern AnimationHeader D_802E3450_6CB230;
extern RandomState D_802E3474_6CB254;
extern InteractionHandler D_802E3494_6CB274[];
extern InteractionHandler D_802E34D4_6CB2B4[];
extern RandomState D_802E3504_6CB2E4[];
extern InteractionHandler D_802E351C_6CB2FC[];
extern RandomState D_802E356C_6CB34C[];
extern InteractionHandler D_802E3584_6CB364[];
extern RandomState D_802E35D4_6CB3B4[];
extern InteractionHandler D_802E35EC_6CB3CC[];
extern InteractionHandler D_802E360C_6CB3EC[];
extern InteractionHandler D_802E362C_6CB40C[];
extern Vec3f D_802E364C_6CB42C;
extern Vec3f D_802E3658_6CB438;
extern Vec3f D_802E3664_6CB444;
extern PokemonInitData D_802E3684_6CB464;

void func_802DBECC_6C3CAC(GObj*);
void func_802DC05C_6C3E3C(GObj*);
void func_802DC0A4_6C3E84(GObj*);
void func_802DC150_6C3F30(GObj*);
void func_802DC2F4_6C40D4(GObj*);
void func_802DC358_6C4138(GObj*);
void func_802DC404_6C41E4(GObj*);
void func_802DC5A8_6C4388(GObj*);
void func_802DC60C_6C43EC(GObj*);
void func_802DC6BC_6C449C(GObj*);
void func_802DC7AC_6C458C(GObj*);
void func_802DC820_6C4600(GObj*);
void func_802DCA7C_6C485C(GObj*);
void func_802DCBB8_6C4998(GObj*);
void func_802DBDB0_6C3B90(GObj*);

POKEMON_FUNC(func_802DBBA0_6C3980)
    pokemon->miscVars[0].field1 = 0;

    switch (pokemon->behavior) {
        case 1:
            Pokemon_SetState(obj, func_802DBECC_6C3CAC);
            break;
        case 2:
            Pokemon_SetState(obj, func_802DC150_6C3F30);
            break;
        case 3:
            Pokemon_SetState(obj, func_802DC404_6C41E4);
            break;
        case 4:
        case 5:
        case 6:
            Pokemon_SetState(obj, func_802DCBB8_6C4998);
            break;
    }
    Pokemon_SetStateRandom(obj, &D_802E3474_6CB254);
}

void func_802DBC5C_6C3A3C(GObj* obj) {
    Pokemon_SetAnimation(obj, &D_802E339C_6CB17C);
    Pokemon_SetState(obj, func_802DBD04_6C3AE4);
}

void func_802DBC94_6C3A74(GObj* obj) {
    Pokemon_SetAnimation(obj, &D_802E33B0_6CB190);
    Pokemon_SetState(obj, func_802DBD04_6C3AE4);
}

void func_802DBCCC_6C3AAC(GObj* obj) {
    Pokemon_SetAnimation(obj, &D_802E33C4_6CB1A4);
    Pokemon_SetState(obj, func_802DBD04_6C3AE4);
}

void func_802DBD04_6C3AE4(GObj* obj) {
    UNUSED s32 pad[1];
    DObj* model = obj->data.dobj;
    Mtx4Float* rot = &GET_TRANSFORM(model)->rot;
    Pokemon* pokemon = GET_POKEMON(obj);

    rot->v.y = (randRange(360) * PI) / 180.0f;
    Pokemon_StartPathProc(obj, func_802DBDB0_6C3B90);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    D_802E28AC_6CA68C = 0;
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

void func_802DBDB0_6C3B90(GObj* obj) {
    UNUSED s32 pad[2];
    DObj* model = obj->data.dobj;
    Pokemon* pokemon = GET_POKEMON(obj);
    Vec3f pos;
    Vec3f vel = D_802E364C_6CB42C;
    DObj* temp_s1 = model->firstChild->firstChild->firstChild->firstChild;
    GroundResult ground;

    ohWait(10);

    while (true) {
        fx_getPosVelDObj(&pos, &vel, temp_s1);
        getGroundAt(pos.x, pos.z, &ground);
        if (pos.y < ground.height) {
            break;
        }
        ohWait(1);
    }
    pos.y = ground.height;
    if (ground.surfaceType == SURFACE_TYPE_337FB2 || ground.surfaceType == SURFACE_TYPE_007F66) {
        func_8035E174_4FE584(obj, &pos);
    }
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802DBECC_6C3CAC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_802E33D8_6CB1B8);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E3494_6CB274;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_802E3504_6CB2E4);
}

void func_802DBF3C_6C3D1C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_802E33EC_6CB1CC);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E3494_6CB274;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_802E3504_6CB2E4);
}

POKEMON_FUNC(func_802DBFAC_6C3D8C)
    Pokemon_StartPathProc(obj, NULL);
    Pokemon_SetAnimation(obj, &D_802E3428_6CB208);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_802E343C_6CB21C);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_802E3450_6CB230);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802DC05C_6C3E3C);
}

POKEMON_FUNC(func_802DC05C_6C3E3C)
    pokemon->miscVars[1].field1 = pokemon->miscVars[0].field1 + 2;
    Pokemon_StartPathProc(obj, func_802DCA7C_6C485C);
    Pokemon_SetState(obj, func_802DC0A4_6C3E84);
}

POKEMON_FUNC(func_802DC0A4_6C3E84)
    Pokemon_SetAnimation(obj, &D_802E3400_6CB1E0);
    pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_AUX_ENDED;
    pokemon->transitionGraph = D_802E34D4_6CB2B4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_AUX_ENDED | POKEMON_PROCESS_FLAG_PATH_ENDED);
    if (!(pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED)) {
        Pokemon_SetState(obj, func_802DC0A4_6C3E84);
    }
    pokemon->miscVars[0].field1 = pokemon->miscVars[1].field1;
    Pokemon_TurnToTarget(obj, 0.1f, 0x20);
    Pokemon_SetState(obj, func_802DC150_6C3F30);
}

void func_802DC150_6C3F30(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_802E33D8_6CB1B8);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E351C_6CB2FC;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_802E356C_6CB34C);
}

void func_802DC1C0_6C3FA0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_802E33EC_6CB1CC);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E351C_6CB2FC;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_802E356C_6CB34C);
}

POKEMON_FUNC(func_802DC230_6C4010)
    cmdSendCommandToLink(3, 0x22, obj);
    Pokemon_StartPathProc(obj, NULL);
    Pokemon_SetAnimation(obj, &D_802E3428_6CB208);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_802E343C_6CB21C);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_802E3450_6CB230);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802DC2F4_6C40D4);
}

POKEMON_FUNC(func_802DC2F4_6C40D4)
    cmdSendCommandToLink(3, 0x22, obj);
    pokemon->miscVars[1].field1 = pokemon->miscVars[0].field1 + 3;
    Pokemon_StartPathProc(obj, func_802DCA7C_6C485C);
    Pokemon_SetState(obj, func_802DC358_6C4138);
}

POKEMON_FUNC(func_802DC358_6C4138)
    Pokemon_SetAnimation(obj, &D_802E3400_6CB1E0);
    pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_AUX_ENDED;
    pokemon->transitionGraph = D_802E34D4_6CB2B4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_AUX_ENDED | POKEMON_PROCESS_FLAG_PATH_ENDED);
    if (!(pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED)) {
        Pokemon_SetState(obj, func_802DC358_6C4138);
    }
    pokemon->miscVars[0].field1 = pokemon->miscVars[1].field1;
    Pokemon_TurnToTarget(obj, 0.1f, 0x20);
    Pokemon_SetState(obj, func_802DC404_6C41E4);
}

void func_802DC404_6C41E4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_802E33D8_6CB1B8);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E3584_6CB364;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_802E35D4_6CB3B4);
}

void func_802DC474_6C4254(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_802E33EC_6CB1CC);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E3584_6CB364;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_802E35D4_6CB3B4);
}

void func_802DC4E4_6C42C4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    cmdSendCommandToLink(3, 0x23, obj);
    Pokemon_StartPathProc(obj, NULL);
    Pokemon_SetAnimation(obj, &D_802E3428_6CB208);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_802E343C_6CB21C);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_802E3450_6CB230);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802DC5A8_6C4388);
}

void func_802DC5A8_6C4388(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    cmdSendCommandToLink(3, 0x23, obj);
    pokemon->miscVars[1].field1 = pokemon->miscVars[0].field1 + 1;
    Pokemon_StartPathProc(obj, func_802DCA7C_6C485C);
    Pokemon_SetState(obj, func_802DC60C_6C43EC);
}

POKEMON_FUNC(func_802DC60C_6C43EC)
    Pokemon_SetAnimation(obj, &D_802E3400_6CB1E0);
    pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_AUX_ENDED;
    pokemon->transitionGraph = D_802E34D4_6CB2B4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_AUX_ENDED | POKEMON_PROCESS_FLAG_PATH_ENDED);
    if (!(pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED)) {
        Pokemon_SetState(obj, func_802DC60C_6C43EC);
    }
    do {
        ohWait(1);
    } while (pokemon->processFlags & POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED);
    pokemon->miscVars[0].field1 = pokemon->miscVars[1].field1;
    Pokemon_SetState(obj, func_802DC6BC_6C449C);
}

POKEMON_FUNC(func_802DC6BC_6C449C)
    Pokemon_SetAnimation(obj, &D_802E3414_6CB1F4);
    Pokemon_ResetPathPos(obj);
    Pokemon_StartPathProc(obj, func_802DC7AC_6C458C);
    Pokemon_StartAuxProc(obj, func_802DC820_6C4600);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    switch (pokemon->behavior) {
        case 1:
            cmdSendCommandToLink(3, 0x24, obj);
            break;
        case 2:
            cmdSendCommandToLink(3, 0x25, obj);
            break;
        default:
            cmdSendCommandToLink(3, 0x26, obj);
            break;
    }

    D_802E28B0_6CA690 = 1;
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802DC7AC_6C458C)
    Pokemon_FollowPath(obj, pokemon->path->paramPoints[pokemon->miscVars[0].field1], 1.0f, 0.1f, 0.0f, 0x10);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802DC820_6C4600(GObj* obj) {
    DObj* model = obj->data.dobj;
    Mtx3Float* position = &GET_TRANSFORM(model)->pos;
    Mtx4Float* rotation = &GET_TRANSFORM(model)->rot;
    Pokemon* pokemon = GET_POKEMON(obj);
    Vec3f sp94 = D_802E3658_6CB438;
    GroundResult ground;
    Vec3f sp74;
    WorldBlock* block;
    f32 temp_f0;
    f32 temp_f22;
    f32 temp_f24;
    f32 var_f20;
    bool var_s1;
    f32 new_var;

    var_s1 = false;
    block = getCurrentWorldBlock();
    sp74.x = -(block->descriptor->worldPos.x * 100.0f);
    sp74.z = -(block->descriptor->worldPos.z * 100.0f);
    getGroundAt(position->v.x, position->v.z, &ground);
    position->v.y = ground.height;
    sp74.y = position->v.y;
    GetInterpolatedPosition(&sp94, pokemon->path, 0.99999f);
    sp74.x += sp94.x * 100.0f;
    sp74.z += sp94.z * 100.0f;
    getGroundAt(sp74.x, sp74.z, &ground);
    sp74.y -= ground.height - 330.0f;
    temp_f0 = sp74.y + 200.0f;
    var_f20 = asinf(sp74.y / temp_f0);

    new_var = (1.0f / pokemon->path->duration) * 0.1f;
    new_var = (1.0f - pokemon->path->paramPoints[pokemon->miscVars[0].field1]) / new_var;
    temp_f24 = (PI - var_f20) / new_var;
    while (var_f20 < PI) {
        var_f20 += temp_f24;
        temp_f22 = __sinf(var_f20 - temp_f24);
        position->v.y += temp_f0 * (__sinf(var_f20) - temp_f22);
        if (!var_s1 && position->v.y < ground.height) {
            sp74.x = position->v.x;
            sp74.y = ground.height;
            sp74.z = position->v.z;
            EnvSound_PlaySound(obj, 1, 0x17E);
            func_8035E174_4FE584(obj, &sp74);
            var_s1 = true;
        }
        ohWait(1);
    }
    Pokemon_StopAuxProc(obj);
}

POKEMON_FUNC(func_802DCA7C_6C485C)
    Pokemon_ResetPathPos(obj);

    Pokemon_FollowPath(
        obj,
        pokemon->path->paramPoints[pokemon->miscVars[0].field1],
        pokemon->path->paramPoints[pokemon->miscVars[1].field1],
        0.06666667f, 0.0f, POKEMON_PROCESS_FLAG_PATH_ENDED | POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802DCB0C_6C48EC)
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_SetAnimation(obj, &D_802E3428_6CB208);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_802E343C_6CB21C);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_802E3450_6CB230);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_StopAuxProc(obj);
}

void func_802DCBB8_6C4998(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    HIDE_POKEMON();
    switch (pokemon->behavior) {
        case 4:
            pokemon->transitionGraph = D_802E35EC_6CB3CC;
            Pokemon_WaitForFlag(obj, 0);
            break;
        case 5:
            pokemon->transitionGraph = D_802E360C_6CB3EC;
            Pokemon_WaitForFlag(obj, 0);
            break;
        default:
            pokemon->transitionGraph = D_802E362C_6CB40C;
            Pokemon_WaitForFlag(obj, 0);
            break;
    }
    Pokemon_SetState(obj, NULL);
}

void func_802DCC6C_6C4A4C(GObj* obj) {
    DObj* model = obj->data.dobj;
    Mtx3Float* pos = &GET_TRANSFORM(model)->pos;
    Mtx4Float* rot = &GET_TRANSFORM(model)->rot;
    Pokemon* pokemon = GET_POKEMON(obj);
    Vec3f sp8C = D_802E3664_6CB444;
    GroundResult ground;
    WorldBlock* block;
    s32 i;
    s32 flag = POKEMON_PROCESS_FLAG_ANIMATION_ENDED;

    for (i = 0; i < pokemon->path->numPoints; i++) {
        HIDE_POKEMON();
        ohWait(75);
        if (!(pokemon->playerDist < 500.0)) {
            SHOW_POKEMON();
            if (0) {
                // todo required to match
            }
            block = getCurrentWorldBlock();
            pos->v.x = -(block->descriptor->worldPos.x * 100.0f);
            pos->v.z = -(block->descriptor->worldPos.z * 100.0f);
            GetInterpolatedPosition(&sp8C, pokemon->path, pokemon->path->paramPoints[i]);
            pos->v.x += sp8C.x * 100.0f;
            pos->v.z += sp8C.z * 100.0f;
            getGroundAt(pos->v.x, pos->v.z, &ground);
            pos->v.y = ground.height;
            func_8035E174_4FE584(obj, &pos->v);
            Pokemon_ForceAnimation(obj, &D_802E339C_6CB17C);
            rot->v.y = (randRange(360) * PI) / 180.0f;
            Pokemon_StartPathProc(obj, func_802DBDB0_6C3B90);
            pokemon->transitionGraph = NULL;
            Pokemon_WaitForFlag(obj, flag);
        }
    }
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

GObj* func_802DCEB0_6C4C90(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802E3684_6CB464);
}
