#include "common.h"
#include "world/world.h"
#include "app_level/app_level.h"

typedef struct InteractionHandler3 { // needed for struct copy
    /* 0x00 */ InteractionHandler data[3];
} InteractionHandler3; // size = 0x30

typedef struct InteractionHandler5 { // needed for struct copy
    /* 0x00 */ InteractionHandler data[5];
} InteractionHandler5; // size = 0x30

typedef struct InteractionHandler6 { // needed for struct copy
    /* 0x00 */ InteractionHandler data[6];
} InteractionHandler6; // size = 0x30

extern AnimationHeader D_802C6CD4_649184;
extern AnimationHeader D_802C6CFC_6491AC;
extern AnimationHeader D_802C6CE8_649198;
extern AnimationHeader D_802C6D10_6491C0;
extern AnimationHeader D_802C6D24_6491D4;
extern AnimationHeader D_802C6D38_6491E8;
extern GObj* D_802C6D4C_6491FC[];
extern u8 D_802C6D5C_64920C[]; // size 4?
extern InteractionHandler3 D_802C6D60_649210;
extern InteractionHandler D_802C6D90_649240[];
extern InteractionHandler6 D_802C6DB0_649260;
extern InteractionHandler5 D_802C6E10_6492C0;
extern InteractionHandler5 D_802C6E60_649310;
extern InteractionHandler5 D_802C6EB0_649360;
extern PokemonInitData D_802C6F14_6493C4;
extern GObj* D_802C72A0_649750[];

void func_802C027C_64272C(GObj*);
void func_802C02BC_64276C(GObj*);
void func_802C0330_6427E0(GObj*);
void func_802C03E4_642894(GObj*);
void func_802C04A4_642954(GObj*);
void func_802C05D8_642A88(GObj*);

void func_802C0140_6425F0(GObj* obj, InteractionHandler* arg1) {
    InteractionHandler3 sp38;
    Pokemon* pokemon = GET_POKEMON(obj);

    sp38 = D_802C6D60_649210;
    pokemon = obj->userData;
    pokemon->counter = 30;
    pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = sp38.data;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    while (true) {
        if (Pokemon_HearsPokeFlute(obj)) {
            pokemon->counter = 1;
            pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
            pokemon->transitionGraph = arg1;
            Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);
        } else {
            break;
        }
    }
}

void func_802C0220_6426D0(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_2 | GOBJ_FLAG_HIDDEN;

    if (pokemon->behavior == 1) {
        Pokemon_SetState(obj, func_802C027C_64272C);
    }
    Pokemon_SetState(obj, func_802C02BC_64276C);
}

void func_802C027C_64272C(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->transitionGraph = D_802C6D90_649240;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

void func_802C02BC_64276C(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    while (D_802C6D5C_64920C[pokemon->behavior] == 0) {
        ohWait(1);
    }
    Pokemon_SetState(obj, func_802C0330_6427E0);
}

void func_802C0330_6427E0(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    D_802C6D4C_6491FC[pokemon->behavior] = obj;
    while (D_802C72A0_649750[pokemon->behavior] == 0) {
        ohWait(1);
    }
    pokemon->tangible = true;
    obj->flags = 0;
    Pokemon_StartPathProc(obj, func_802C04A4_642954);
    Pokemon_SetState(obj, func_802C03E4_642894);
}

void func_802C03E4_642894(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);
    InteractionHandler6 sp20;

    sp20 = D_802C6DB0_649260;
    Pokemon_SetAnimation(obj, &D_802C6CD4_649184);
    pokemon->transitionGraph = sp20.data;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED | POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    if (!(pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED)) {
        Pokemon_SetState(obj, func_802C03E4_642894);
    }
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

void func_802C04A4_642954(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0, 1, 0.05f, 0.0f, MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

// clang-format off
void func_802C0510_6429C0(GObj* obj) { \
    Pokemon* pokemon = GET_POKEMON(obj);
    // clang-format on

    Pokemon_ForceAnimation(obj, &D_802C6CE8_649198);
    Pokemon_StartPathProc(obj, func_802C05D8_642A88);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    cmdSendCommand(D_802C72A0_649750[pokemon->behavior], 0x20, obj);
    if (pokemon->behavior < 3) {
        D_802C6D5C_64920C[pokemon->behavior + 1] = 1;
    }
    Pokemon_SetAnimation(obj, &D_802C6D38_6491E8);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

void func_802C05D8_642A88(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);
    if (false) {
        // required to match
    }

    pokemon->hSpeed = 0.0f;
    pokemon->jumpVel = 0.0f;
    Pokemon_FallDownOnGround(obj, -0.6125f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802C0630_642AE0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);
    InteractionHandler5 sp18 = D_802C6E10_6492C0;

    Pokemon_SetAnimation(obj, &D_802C6CFC_6491AC);
    func_802C0140_6425F0(obj, sp18.data);
    Pokemon_SetState(obj, func_802C03E4_642894);
}

void func_802C06BC_642B6C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);
    InteractionHandler5 sp18 = D_802C6E60_649310;

    Pokemon_SetAnimation(obj, &D_802C6D10_6491C0);
    func_802C0140_6425F0(obj, sp18.data);
    Pokemon_SetState(obj, func_802C03E4_642894);
}

void func_802C0748_642BF8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);
    InteractionHandler5 sp18 = D_802C6EB0_649360;

    Pokemon_SetAnimation(obj, &D_802C6D24_6491D4);
    func_802C0140_6425F0(obj, sp18.data);
    Pokemon_SetState(obj, func_802C03E4_642894);
}

GObj* func_802C07D4_642C84(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_Spawn(objID, id, block, blockB, spawn, &D_802C6F14_6493C4);
}
