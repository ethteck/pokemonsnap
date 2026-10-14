#include "common.h"
#include "beach.h"

extern u8 D_8017BB20_107FB0[];
extern u8 D_8017DA60_109EF0[];
extern u8 D_8017E2E0_10A770[];
extern u8 D_8017E740_10ABD0[];
extern u8 D_8017EBA0_10B030[];
extern u8 D_8017F080_10B510[];
extern u8 D_8017F8B0_10BD40[];
extern u8 D_8017FEF0_10C380[];
extern u8 D_80180910_10CDA0[];
extern u8 D_80181880_10DD10[];
extern u8 D_801820B0_10E540[];
extern u8 D_80182150_10E5E0[];
extern u8 D_801821C0_10E650[];
extern u8 D_80182230_10E6C0[];
extern u8 D_80182310_10E7A0[];
extern u8 D_801823C0_10E850[];
extern u8 D_beach_802CC0F0[];
extern u8 D_beach_802CC0F4[];
extern u8 D_beach_802CC0F8[];
extern u8 D_beach_802CC0FC[];
void func_beach_802C56C8(GObj*);
void func_beach_802C5884(GObj*);
void func_beach_802C58B8(GObj*);
void func_beach_802C58EC(GObj*);
void func_beach_802C59C0(GObj*);
void func_beach_802C5A94(GObj*);
extern u8 snorlax_materials[];
extern u8 snorlax_model[];
extern u32 D_beach_802CC100;
extern u32 D_beach_802CC104[];
extern PokemonAnimationSetup D_beach_802CC2DC;

// .data
u32 D_beach_802CC100 = 0x00000129;

u32 D_beach_802CC104[] = {
    0x00000128, 0x0000007D,
};

AnimationHeader D_beach_802CC10C = { 0.1f, 25.0f, (AnimCmd**) &D_8017EBA0_10B030, (AnimCmd***) &D_80182230_10E6C0, (s32*) &D_beach_802CC0F0 };
AnimationHeader D_beach_802CC120 = { 0.2f, 8.0f, (AnimCmd**) &D_8017E740_10ABD0, (AnimCmd***) &D_801821C0_10E650, NULL };
AnimationHeader D_beach_802CC134 = { 0.15f, 40.0f, (AnimCmd**) &D_8017F8B0_10BD40, (AnimCmd***) &D_80182310_10E7A0, (s32*) &D_beach_802CC0F4 };
AnimationHeader D_beach_802CC148 = { 0.23f, 24.0f, (AnimCmd**) &D_8017FEF0_10C380, NULL, (s32*) &D_beach_802CC0F8 };
AnimationHeader D_beach_802CC15C = { 0.2f, 20.0f, (AnimCmd**) &D_8017F080_10B510, NULL, (s32*) &D_beach_802CC0FC };
AnimationHeader D_beach_802CC170 = { 0.2f, 36.0f, (AnimCmd**) &D_80181880_10DD10, NULL, NULL };
AnimationHeader D_beach_802CC184 = { 0.42f, 71.0f, (AnimCmd**) &D_80180910_10CDA0, (AnimCmd***) &D_801823C0_10E850, (s32*) &D_beach_802CC100 };
AnimationHeader D_beach_802CC198 = { 0.2f, 71.0f, (AnimCmd**) &D_8017BB20_107FB0, NULL, NULL };
AnimationHeader D_beach_802CC1AC = { 0.2f, 19.0f, (AnimCmd**) &D_8017DA60_109EF0, (AnimCmd***) &D_801820B0_10E540, (s32*) &D_beach_802CC104 };
AnimationHeader D_beach_802CC1C0 = { 0.2f, 8.0f, (AnimCmd**) &D_8017E2E0_10A770, (AnimCmd***) &D_80182150_10E5E0, NULL };

InteractionHandler D_beach_802CC1D4[6] = {
    { 9, (GObjFunc) func_beach_802C5884, 0.0f, NULL },
    { 13, (GObjFunc) func_beach_802C58B8, 0.0f, NULL },
    { 5, (GObjFunc) func_beach_802C58EC, 0.0f, NULL },
    { 6, (GObjFunc) func_beach_802C59C0, 0.0f, NULL },
    { 7, (GObjFunc) func_beach_802C5A94, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

InteractionHandler D_beach_802CC234[3] = {
    { 6, (GObjFunc) func_beach_802C5A20, 0.0f, NULL },
    { 7, (GObjFunc) func_beach_802C5AF4, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

InteractionHandler D_beach_802CC264[3] = {
    { 5, (GObjFunc) func_beach_802C594C, 0.0f, NULL },
    { 7, (GObjFunc) func_beach_802C5AF4, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

InteractionHandler D_beach_802CC294[3] = {
    { 5, (GObjFunc) func_beach_802C594C, 0.0f, NULL },
    { 6, (GObjFunc) func_beach_802C5A20, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

RandomState D_beach_802CC2C4[3] = {
    { 100, (GObjFunc) func_beach_802C5700 },
    { 100, (GObjFunc) func_beach_802C5828 },
    { 0, NULL },
};

PokemonAnimationSetup D_beach_802CC2DC = { (AnimationHeader*) &D_beach_802CC10C, (GObjFunc) func_beach_802C56C8, 0, "", NULL, NULL };
PokemonInitData D_beach_802CC2F0 = { (UnkEC64Arg3*) &snorlax_model, (Texture***) &snorlax_materials, (GObjFunc) renderPokemonModelTypeJFogged, (PokemonAnimationSetup*) &D_beach_802CC2DC, { 1.5f, 1.5f, 1.5f }, { 0.0f, 82.0f, 0.0f }, 105.0f, 53, 54, 0, 0, "" };

u32 D_beach_802CC324[] = {
    0x00000000, 0x00000000, 0x00000000,
};

u32 D_beach_802CC330 = 0x0000012B;
u32 D_beach_802CC334 = 0x0000012C;
u32 D_beach_802CC338 = 0x0000012A;
u32 D_beach_802CC33C = 0x0000012E;

void func_beach_802C5620(GObj* arg0) {
    UNUSED s32 pad[4];
    s32 sp34;
    f32 sp30;

    while (true) {
        getLevelProgress(&sp34, &sp30);
        if (sp34 > 3 || (sp34 == 3 && sp30 >= 0.3)) {
            break;
        }
        ohWait(1);
    }
    Pokemon_RunCleanup(arg0);
    Pokemon_StopAuxProc(arg0);
}

void func_beach_802C56C8(GObj* obj) {
    Pokemon_StartAuxProc(obj, func_beach_802C5620);
    Pokemon_SetState(obj, func_beach_802C5700);
}

void func_beach_802C5700(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->flags |= POKEMON_FLAG_8;
    Pokemon_SetAnimation(obj, &D_beach_802CC10C);
    pokemon->transitionGraph = D_beach_802CC1D4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_beach_802CC2C4);
}

// clang-format off
void func_beach_802C5768(GObj* obj) { \
    Pokemon* pokemon = GET_POKEMON(obj);
    // clang-format on
    if (obj) {
    } // required to match
    Pokemon_ForceAnimation(obj, &D_beach_802CC120);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_ForceAnimation(obj, &D_beach_802CC1AC);
    pokemon->flags &= ~POKEMON_FLAG_8;
    pokemon->transitionGraph = D_beach_802CC1D4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_ForceAnimation(obj, &D_beach_802CC1C0);
    pokemon->flags |= POKEMON_FLAG_8;
    pokemon->transitionGraph = D_beach_802CC1D4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_beach_802CC2C4);
}

void func_beach_802C5828(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_beach_802CC134);
    pokemon->transitionGraph = D_beach_802CC1D4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_beach_802C5700);
}

void func_beach_802C5884(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->flags |= POKEMON_FLAG_8;
    Pokemon_SetState(obj, func_beach_802C5768);
}

void func_beach_802C58B8(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->flags |= POKEMON_FLAG_8;
    Pokemon_SetState(obj, func_beach_802C5828);
}

void func_beach_802C58EC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->flags &= ~POKEMON_FLAG_8;
    Pokemon_SetAnimation(obj, &D_beach_802CC148);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_beach_802C594C);
}

void func_beach_802C594C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_beach_802CC170);
    Pokemon_StartPathProc(obj, func_beach_802C5B68);
    pokemon->transitionGraph = D_beach_802CC234;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetState(obj, func_beach_802C5BD4);
}

void func_beach_802C59C0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->flags &= ~POKEMON_FLAG_8;
    Pokemon_SetAnimation(obj, &D_beach_802CC148);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_beach_802C5A20);
}

void func_beach_802C5A20(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_beach_802CC184);
    Pokemon_StartPathProc(obj, func_beach_802C5B68);
    pokemon->transitionGraph = D_beach_802CC264;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetState(obj, func_beach_802C5BD4);
}

void func_beach_802C5A94(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->flags &= ~POKEMON_FLAG_8;
    Pokemon_SetAnimation(obj, &D_beach_802CC148);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_beach_802C5AF4);
}

void func_beach_802C5AF4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_beach_802CC198);
    Pokemon_StartPathProc(obj, func_beach_802C5B68);
    pokemon->transitionGraph = D_beach_802CC294;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetState(obj, func_beach_802C5BD4);
}

void func_beach_802C5B68(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    while (1) {
        if (!Pokemon_HearsPokeFlute(obj)) {
            break;
        }

        ohWait(1);
    }

    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    pokemon->pathProc = NULL;
    omEndProcess(NULL);
}

void func_beach_802C5BD4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_beach_802CC15C);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_beach_802C5700);
}

void func_beach_802C5C28(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    Pokemon_SpawnOnGround(gObjID, id, roomA, roomB, spawn, &D_beach_802CC2F0);
}
