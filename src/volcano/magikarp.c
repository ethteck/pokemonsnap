#include "volcano/volcano.h"

extern UnkEC64Arg3 D_8034FEB8[];
extern AnimCmd* D_800FDC70[];
extern AnimCmd* D_800FAE40[];
extern AnimCmd* D_800FBF50[];
extern AnimCmd* D_800FD080[];

void func_802DF280_730480(GObj*);
void func_802DF338_730538(GObj*);

s32 D_802E35D0_7347D0[] = { SOUND_ID_211 };
s32 D_802E35D4_7347D4[] = { SOUND_ID_210, SOUND_ID_376, SOUND_ID_114 };
s32 D_802E35E0_7347E0[] = { SOUND_ID_211, SOUND_ID_376, SOUND_ID_114 };
s32 D_802E35EC_7347EC[] = { 0, SOUND_ID_376, SOUND_ID_114 };

AnimationHeader D_802E35F8_7347F8 = {
    0.5,
    60,
    D_800FDC70,
    NULL,
    D_802E35D0_7347D0
};

AnimationHeader D_802E360C_73480C = {
    0.5,
    65,
    D_800FAE40,
    NULL,
    D_802E35D4_7347D4
};

AnimationHeader D_802E3620_734820 = {
    0.5,
    59,
    D_800FBF50,
    NULL,
    D_802E35E0_7347E0
};

AnimationHeader D_802E3634_734834 = {
    0.5,
    50,
    D_800FD080,
    NULL,
    D_802E35EC_7347EC
};

InteractionHandler D_802E3648_734848[] = {
    { POKEMON_CMD_58, NULL, 0, NULL },
};

s32 D_802E3658_734858[] = { 0, 0 }; // split here ?

PokemonAnimationSetup D_802E3660_734860 = {
    &D_802E360C_73480C,
    func_802DF280_730480,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData D_802E3674_734874 = {
    D_8034FEB8,
    NULL,
    renderPokemonModelTypeBFogged,
    &D_802E3660_734860,
    { 1.6, 1.6, 1.6 },
    { 0, -40, -11 },
    35,
    POKEMON_FLAG_20 | POKEMON_FLAG_4 | POKEMON_FLAG_1,
    0,
    0,
    0,
    { 0, 0, 0 }
};

void func_802DF280_730480(GObj* obj) {
    UNUSED s32 pad[1];
    DObj* model = obj->data.dobj;
    Mtx4Float* rotation = &GET_TRANSFORM(model)->rot;
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E3634_734834);
    rotation->f[2] = randRange(360) * PI / 180.0f;
    Pokemon_StartPathProc(obj, func_802DF338_730538);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    D_802E0EB4_7320B4 = false;
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

void func_802DF338_730538(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    func_8035E298_4FE6A8(obj);

    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

GObj* func_802DF378_730578(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802E3674_734874);
}
