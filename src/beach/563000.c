#include "common.h"
#include "beach.h"
#include "app_level/app_level.h"

void func_beach_802CB710(GObj* obj);
void func_beach_802CBA48(GObj* obj);
void func_beach_802CBB34(GObj* obj);

extern u8 D_801092F0_86710[];
extern u8 D_80109C10_87030[];
extern u8 D_8010C370_89790[];
extern u8 D_8010CE10_8A230[];
extern u8 D_8010D410_8A830[];
extern u8 D_8010E190_8B5B0[];
extern u8 D_80111AA0_8EEC0[];
extern u8 D_80112F20_90340[];
extern u8 D_80113740_90B60[];
extern u8 D_80114610_91A30[];
extern u8 D_801161D0_935F0[];
extern u8 D_80117C40_95060[];
extern u8 D_801189D0_95DF0[];
extern u8 D_801196C0_96AE0[];
extern u8 D_80119760_96B80[];
extern u8 D_80119800_96C20[];
extern u8 D_801198B0_96CD0[];
extern u8 D_80119960_96D80[];
extern u8 D_80119A00_96E20[];
extern u8 D_8011A1B0_975D0[];
extern u8 D_8011A2B0_976D0[];
extern u8 D_8011A370_97790[];
extern u8 D_8011A440_97860[];
extern u8 D_8011ADE0_98200[];
extern u8 D_8011AEE0_98300[];
extern u8 D_8011AF80_983A0[];
extern u8 D_801397C0_C5C50[];
extern u8 D_80139A40_C5ED0[];
extern u8 D_80139CD0_C6160[];
extern u8 D_8013ACA0_C7130[];
extern u8 D_beach_802CDB20[];
extern u8 D_beach_802CDB24[];
extern u8 D_beach_802CDB30[];
extern u8 D_beach_802CDB34[];
extern u8 D_beach_802CDB3C[];
extern u8 D_beach_802CDB44[];
extern u8 D_beach_802CDB48[];
void func_beach_802CACD4();
void func_beach_802CADCC();
void func_beach_802CAF1C();
void func_beach_802CAFEC(GObj*);
void func_beach_802CB054(GObj*);
void func_beach_802CB36C(GObj*);
void func_beach_802CB3DC(GObj*);
void func_beach_802CB44C(GObj*);
void func_beach_802CB520(GObj*);
void func_beach_802CB784(GObj*);
void func_beach_802CB9E0(GObj*);
void func_beach_802CBC4C(GObj*);
void func_beach_802CBCE0(GObj*);
void func_beach_802CBDA0(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
extern u8 pikachu_materials[];
extern u8 pikachu_model[];
extern u32 D_beach_802CDB50[];
extern PokemonAnimationSetup D_beach_802CE024;
extern PokemonAnimationSetup D_beach_802CE094;

// .data
u32 D_beach_802CDB50[] = {
    0x00000108, 0x0000007F, 0x00000168,
};

AnimationHeader D_beach_802CDB5C = { 0.43f, 40.0f, (AnimCmd**) &D_80112F20_90340, (AnimCmd***) &D_8011A2B0_976D0, NULL };
AnimationHeader D_beach_802CDB70 = { 0.5f, 80.0f, (AnimCmd**) &D_80113740_90B60, (AnimCmd***) &D_8011A370_97790, (s32*) &D_beach_802CDB20 };
AnimationHeader D_beach_802CDB84 = { 0.3f, 63.0f, (AnimCmd**) &D_8010E190_8B5B0, (AnimCmd***) &D_80119A00_96E20, (s32*) &D_beach_802CDB24 };

u32 D_beach_802CDB98[] = {
    0x3EB33333, 0x41400000, (u32) &D_801092F0_86710, (u32) &D_801196C0_96AE0,
    0x00000000,
};

AnimationHeader D_beach_802CDBAC = { 0.6f, 16.0f, (AnimCmd**) &D_8010D410_8A830, (AnimCmd***) &D_80119960_96D80, NULL };
AnimationHeader D_beach_802CDBC0 = { 0.6f, 120.0f, (AnimCmd**) &D_801161D0_935F0, (AnimCmd***) &D_8011ADE0_98200, (s32*) &D_beach_802CDB30 };
AnimationHeader D_beach_802CDBD4 = { 0.3f, 36.0f, (AnimCmd**) &D_80111AA0_8EEC0, (AnimCmd***) &D_8011A1B0_975D0, (s32*) &D_beach_802CDB34 };
AnimationHeader D_beach_802CDBE8 = { 0.4f, 5.0f, (AnimCmd**) &D_8010CE10_8A230, (AnimCmd***) &D_801198B0_96CD0, NULL };
AnimationHeader D_beach_802CDBFC = { 0.4f, 35.0f, (AnimCmd**) &D_8010C370_89790, (AnimCmd***) &D_80119800_96C20, NULL };
AnimationHeader D_beach_802CDC10 = { 0.4f, 75.0f, (AnimCmd**) &D_801189D0_95DF0, (AnimCmd***) &D_8011AF80_983A0, (s32*) &D_beach_802CDB3C };

u32 D_beach_802CDC24[] = {
    0x3F19999A, 0x42800000, (u32) &D_80109C10_87030, (u32) &D_80119760_96B80,
    (u32) &D_beach_802CDB44, 0x3F19999A, 0x41800000, (u32) &D_80117C40_95060,
    (u32) &D_8011AEE0_98300, (u32) &D_beach_802CDB48, 0x3E99999A, 0x427C0000,
    (u32) &D_80114610_91A30, (u32) &D_8011A440_97860, (u32) &D_beach_802CDB50,
};

InteractionHandler D_beach_802CDC60[2] = {
    { 26, (GObjFunc) func_beach_802CB44C, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

InteractionHandler D_beach_802CDC80[2] = {
    { 30, (GObjFunc) func_beach_802CADCC, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

InteractionHandler D_beach_802CDCA0[3] = {
    { 9, (GObjFunc) func_beach_802CAF1C, 0.0f, NULL },
    { 13, (GObjFunc) func_beach_802CAF1C, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

InteractionHandler D_beach_802CDCD0[7] = {
    { 9, (GObjFunc) func_beach_802CAFEC, 0.0f, NULL },
    { 13, (GObjFunc) func_beach_802CAFEC, 0.0f, NULL },
    { 10, (GObjFunc) func_beach_802CAFEC, 0.0f, NULL },
    { 5, (GObjFunc) func_beach_802CB054, 0.0f, NULL },
    { 6, (GObjFunc) func_beach_802CB054, 0.0f, NULL },
    { 7, (GObjFunc) func_beach_802CB054, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

InteractionHandler D_beach_802CDD40[4] = {
    { 9, (GObjFunc) func_beach_802CAFEC, 0.0f, NULL },
    { 13, (GObjFunc) func_beach_802CAFEC, 0.0f, NULL },
    { 10, (GObjFunc) func_beach_802CAFEC, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

InteractionHandler D_beach_802CDD80[11] = {
    { 14, (GObjFunc) func_beach_802CB520, 0.0f, NULL },
    { 15, (GObjFunc) func_beach_802CB520, 0.0f, NULL },
    { 9, (GObjFunc) func_beach_802CB44C, 0.0f, NULL },
    { 13, (GObjFunc) func_beach_802CB44C, 0.0f, NULL },
    { 26, (GObjFunc) func_beach_802CB44C, 0.0f, NULL },
    { 10, (GObjFunc) func_beach_802CB44C, 0.0f, NULL },
    { 5, (GObjFunc) func_beach_802CB784, 0.0f, NULL },
    { 6, (GObjFunc) func_beach_802CB784, 0.0f, NULL },
    { 7, (GObjFunc) func_beach_802CB784, 0.0f, NULL },
    { 35, (GObjFunc) func_beach_802CB874, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

RandomState D_beach_802CDE30[3] = {
    { 1, (GObjFunc) func_beach_802CB36C },
    { 1, (GObjFunc) func_beach_802CB3DC },
    { 0, NULL },
};

InteractionHandler D_beach_802CDE48[3] = {
    { 9, (GObjFunc) func_beach_802CB44C, 0.0f, NULL },
    { 13, (GObjFunc) func_beach_802CB44C, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

InteractionHandler D_beach_802CDE78[8] = {
    { 9, (GObjFunc) func_beach_802CB44C, 0.0f, NULL },
    { 13, (GObjFunc) func_beach_802CB44C, 0.0f, NULL },
    { 10, (GObjFunc) func_beach_802CB44C, 0.0f, NULL },
    { 26, (GObjFunc) func_beach_802CB44C, 0.0f, NULL },
    { 5, (GObjFunc) func_beach_802CB784, 0.0f, NULL },
    { 6, (GObjFunc) func_beach_802CB784, 0.0f, NULL },
    { 7, (GObjFunc) func_beach_802CB784, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

InteractionHandler D_beach_802CDEF8[10] = {
    { 35, (GObjFunc) func_beach_802CB874, 0.0f, NULL },
    { 14, (GObjFunc) func_beach_802CB594, 0.0f, NULL },
    { 9, (GObjFunc) func_beach_802CB44C, 0.0f, NULL },
    { 13, (GObjFunc) func_beach_802CB44C, 0.0f, NULL },
    { 10, (GObjFunc) func_beach_802CB44C, 0.0f, NULL },
    { 26, (GObjFunc) func_beach_802CB44C, 0.0f, NULL },
    { 5, (GObjFunc) func_beach_802CB784, 0.0f, NULL },
    { 6, (GObjFunc) func_beach_802CB784, 0.0f, NULL },
    { 7, (GObjFunc) func_beach_802CB784, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

InteractionHandler D_beach_802CDF98[4] = {
    { 9, (GObjFunc) func_beach_802CB9E0, 0.0f, NULL },
    { 10, (GObjFunc) func_beach_802CB9E0, 0.0f, NULL },
    { 13, (GObjFunc) func_beach_802CB9E0, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

InteractionHandler D_beach_802CDFD8[4] = {
    { 9, (GObjFunc) func_beach_802CBC4C, 0.0f, NULL },
    { 10, (GObjFunc) func_beach_802CBC4C, 0.0f, NULL },
    { 13, (GObjFunc) func_beach_802CBC4C, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

Vec3f D_beach_802CE018 = { 0.0f, 0.0f, 0.0f };
PokemonAnimationSetup D_beach_802CE024 = { (AnimationHeader*) &D_beach_802CDB5C, (GObjFunc) func_beach_802CACD4, 0, "", NULL, NULL };
PokemonInitData D_beach_802CE038 = { (UnkEC64Arg3*) &pikachu_model, (Texture***) &pikachu_materials, (GObjFunc) renderPokemonModelTypeJFogged, (PokemonAnimationSetup*) &D_beach_802CE024, { 2.0f, 2.0f, 2.0f }, { 0.0f, 76.0f, 0.0f }, 22.0f, 37, 0, 0, 0, "" };
u32 D_beach_802CE06C = 0x00000000;
AnimationHeader D_beach_802CE070 = { 0.6f, 112.0f, (AnimCmd**) &D_80139CD0_C6160, (AnimCmd***) &D_8013ACA0_C7130, NULL };

u32 D_beach_802CE084[] = {
    0x0000003A, 0x00000000, 0x00000000, 0x00000000,
};

PokemonAnimationSetup D_beach_802CE094 = { (AnimationHeader*) &D_beach_802CE070, (GObjFunc) func_beach_802CBCE0, 0, "", NULL, NULL };
PokemonInitData D_beach_802CE0A8 = { (UnkEC64Arg3*) &D_80139A40_C5ED0, (Texture***) &D_801397C0_C5C50, (GObjFunc) renderModelTypeDFogged, (PokemonAnimationSetup*) &D_beach_802CE094, { 3.0f, 3.0f, 3.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f, 0, 0, 0, 0, "" };
PokemonDef D_beach_802CE0DC = { 0x3EE, (pokemonInit) func_beach_802CBDA0, (void (*)(GObj*, f32, f32, f32, f32, f32, f32)) pokemonChangeBlock, (void (*)(GObj*)) pokemonRemoveOne };

void func_beach_802CAF90(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_beach_802CDBD4);
    pokemon->transitionGraph = D_beach_802CDCD0;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_beach_802CAF90);
}

void func_beach_802CAFEC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_beach_802CDBC0);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_beach_802CAF90);
}

void func_beach_802CB054(GObj* obj) {
    Pokemon_StartPathProc(obj, func_beach_802CB128);
    Pokemon_SetState(obj, func_beach_802CB08C);
}

void func_beach_802CB08C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_beach_802CDB84);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED | POKEMON_PROCESS_FLAG_PATH_ENDED);
    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_ANIMATION_ENDED) {
        Pokemon_SetState(obj, func_beach_802CB08C);
    }
    pokemon->transitionGraph = D_beach_802CDD40;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_beach_802CAF90);
}

void func_beach_802CB128(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    while (true) {
        if (!Pokemon_HearsPokeFlute(obj)) {
            break;
        }

        ohWait(1);
    }

    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    pokemon->pathProc = NULL;
    omEndProcess(NULL);
}


s32 func_beach_802CB194(GObj* obj) {
    Vec3f sp2C = D_beach_802CE018;
    Pokemon* pokemon = GET_POKEMON(obj);
    WorldBlock* block;
    DObj* model = obj->data.dobj;
    UNUSED s32 pad[1];

    block = getCurrentWorldBlock();
    pokemon->pos1.x = -(block->descriptor->worldPos.x * 100.0f);
    pokemon->pos1.y = -(block->descriptor->worldPos.y * 100.0f);
    pokemon->pos1.z = -(block->descriptor->worldPos.z * 100.0f);
    GetInterpolatedPosition(&sp2C, pokemon->path, 0.99999f);
    pokemon->pos1.x += sp2C.x * 100.0f;
    pokemon->pos1.y += sp2C.y * 100.0f;
    pokemon->pos1.z += sp2C.z * 100.0f;

    if (SQ(pokemon->pos1.x - GET_TRANSFORM(model)->pos.v.x) + SQ(pokemon->pos1.z - GET_TRANSFORM(model)->pos.v.z) < 225000.0f) {
        return false;
    } else {
        return true;
    }
}

void func_beach_802CB2D8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->flags |= POKEMON_FLAG_200;
    pokemon->flags |= POKEMON_FLAG_800;
    Pokemon_StartAuxProc(obj, func_beach_802CB814);
    Pokemon_SetAnimation(obj, &D_beach_802CDB5C);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_beach_802CDD80;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_beach_802CDE30);
}

void func_beach_802CB36C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_beach_802CDB5C);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_beach_802CDD80;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_beach_802CDE30);
}

void func_beach_802CB3DC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_beach_802CDB70);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_beach_802CDD80;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_beach_802CDE30);
}

void func_beach_802CB44C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_beach_802CDBC0);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_beach_802CDE48;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_beach_802CB3DC);
}

void func_beach_802CB4BC() {
}

void func_beach_802CB4C4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 20.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_beach_802CB520(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_beach_802CDBD4);
    Pokemon_StartPathProc(obj, func_beach_802CB6B4);
    pokemon->transitionGraph = D_beach_802CDE78;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_beach_802CB594);
}

// clang-format off
void func_beach_802CB594(GObj* obj) { \
    Pokemon* pokemon = GET_POKEMON(obj);
    // clang-format on
    UNUSED s32 pad[3];

    Pokemon_SetAnimation(obj, &D_beach_802CDBAC);
    Pokemon_StartPathProc(obj, func_beach_802CB710);
    pokemon->transitionGraph = D_beach_802CDEF8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    if (!(pokemon->processFlags & POKEMON_PROCESS_TARGET_REACHED)) {
        Pokemon_SetState(obj, func_beach_802CB36C);
    }
    Pokemon_SetAnimation(obj, &D_beach_802CDC10);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->counter = 17, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_beach_802CDEF8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);
    if (pokemon->interactionTarget == NULL) {
        Pokemon_SetState(obj, func_beach_802CB3DC);
    }
    Pokemon_EatApple(obj);
    pokemon->transitionGraph = D_beach_802CDEF8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_beach_802CB3DC);
}

void func_beach_802CB6B4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    ohWait(60);
    Pokemon_TurnToTarget(obj, 0.1f, 0);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_beach_802CB710(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 80.0f;
    Pokemon_RunToTarget(obj, 50, 0.1f, MOVEMENT_FLAG_UPDATE_TARGET_POS | MOVEMENT_FLAG_ON_GROUND);
    Pokemon_TurnToTarget(obj, 0.1f, 0);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_beach_802CB784(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_beach_802CDB84);
    Pokemon_StartPathProc(obj, func_beach_802CB128);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED | POKEMON_PROCESS_FLAG_PATH_ENDED);
    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_ANIMATION_ENDED) {
        Pokemon_SetState(obj, func_beach_802CB784);
    }
    Pokemon_SetState(obj, func_beach_802CB3DC);
}

void func_beach_802CB814(GObj* obj) {
    while (func_beach_802CB194(obj)) {
        ohWait(1);
    }

    cmdSendCommand(obj, 0x23, obj);
    Pokemon_StopAuxProc(obj);
}

// clang-format off
void func_beach_802CB874(GObj* obj) { \
    Pokemon* pokemon = GET_POKEMON(obj);
    // clang-format on
    Pokemon_ForceAnimation(obj, &D_beach_802CDB70);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_beach_802CDF98;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_beach_802CDBE8);
    pokemon->transitionGraph = D_beach_802CDF98;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_beach_802CDBAC);
    pokemon->hSpeed = 80.0f;
    Pokemon_StartPathProc(obj, func_beach_802CBB34);
    pokemon->transitionGraph = D_beach_802CDF98;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    pokemon->flags &= ~POKEMON_FLAG_200;
    pokemon->flags &= ~POKEMON_FLAG_800;
    pokemon->specialPoseID = 1;
    Pokemon_SetAnimation(obj, &D_beach_802CDBD4);
    Pokemon_StartPathProc(obj, func_beach_802CBA48);
    pokemon->transitionGraph = D_beach_802CDFD8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_beach_802CDBFC);
    pokemon->transitionGraph = D_beach_802CDFD8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    pokemon->transitionGraph = D_beach_802CDFD8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_beach_802CBB90);
}

void func_beach_802CB9E0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_beach_802CDBC0);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_beach_802CB874);
}

void func_beach_802CBA48(GObj* obj) {
    f32 temp_f0;
    f32 temp_f20;
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* model;
    Vec3f sp34;

    model = obj->data.dobj;
    ohWait(60);
    GetInterpolatedVelocity(&sp34, pokemon->path, 0.99999f);
    temp_f0 = atan2f(sp34.x, sp34.z);
    temp_f20 = temp_f0 - ((s32) (temp_f0 / 6.2831855f) * 6.2831855f);
    while (Pokemon_Turn(model, temp_f20, 0.13962634f) == 0) {
        ohWait(1);
    }
    pokemon->pathProc = 0;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_beach_802CBB34(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetTargetPos(obj, pokemon->pos1.x, pokemon->pos1.z);
    Pokemon_RunToTargetPos(obj, 0.1f);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_beach_802CBB90(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_beach_802CDBD4);
    pokemon->transitionGraph = D_beach_802CDFD8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_beach_802CDBFC);
    pokemon->transitionGraph = D_beach_802CDFD8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_ForceAnimation(obj, &D_beach_802CDBFC);
    pokemon->transitionGraph = D_beach_802CDFD8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_beach_802CBB90);
}

void func_beach_802CBC4C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_beach_802CDBC0);
    pokemon->transitionGraph = D_beach_802CDFD8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_beach_802CBB90);
}

void func_beach_802CBCA8(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    Pokemon_SpawnOnGround(gObjID, id, roomA, roomB, spawn, &D_beach_802CE038);
}

void func_beach_802CBCE0(GObj* obj) {
    Pokemon_SetState(obj, func_beach_802CBD04);
}

void func_beach_802CBD04(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    cmdSendCommandToLink(LINK_POKEMON, POKEMON_CMD_37, obj);
    ohWait(1);
    EnvSound_PlaySound(obj, 1, 0x34);
    Pokemon_ForceAnimation(obj, &D_beach_802CE070);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    cmdSendCommandToLink(LINK_POKEMON, POKEMON_CMD_38, obj);
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

void func_beach_802CBDA0(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    Pokemon_SpawnDlLink4(gObjID, id, roomA, roomB, spawn, &D_beach_802CE0A8);
}

void func_beach_802CBDD8(GObj* obj) {
    GObj* var;

    var = Pokemon_AddAtGeo(obj, 0x3EEU, &D_beach_802CE0DC);
    GET_POKEMON(var)->behavior = 0;
}
