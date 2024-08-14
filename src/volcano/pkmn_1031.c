#include "volcano/volcano.h"

extern UnkEC64Arg3 D_80114EA0[];
extern Texture** D_801151C0[];
extern AnimCmd* D_80115610[];
extern AnimCmd** D_80115C50[];

void func_802DFA94_730C94(GObj*);
void func_802DFAE4_730CE4(GObj*);
void func_802DFA70_730C70(GObj*);

AnimationHeader D_802E3780_734980 = {
    0.4,
    100,
    D_80115610,
    D_80115C50,
    NULL
};

InteractionHandler D_802E3794_734994[] = {
    { POKEMON_CMD_58, NULL, 0, NULL },
};

PokemonAnimationSetup D_802E37A4_7349A4 = {
    &D_802E3780_734980,
    func_802DFA70_730C70,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData D_802E37B8_7349B8 = {
    D_80114EA0,
    D_801151C0,
    func_802DFAE4_730CE4,
    &D_802E37A4_7349A4,
    { 10, 10, 10 },
    { 0, 0, 0 },
    0,
    0,
    0,
    0,
    0,
    { 0, 0, 0 }
};

void func_802DFA70_730C70(GObj* obj) {
    Pokemon_SetState(obj, func_802DFA94_730C94);
}

void func_802DFA94_730C94(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E3780_734980);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, 0);

    Pokemon_SetState(obj, NULL);
}

void func_802DFAE4_730CE4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    gDPSetTextureLUT(gMainGfxPos[1]++, G_TT_NONE);
    gDPSetCycleType(gMainGfxPos[1]++, G_CYC_2CYCLE);
    renderModelTypeDFogged(obj);
}

GObj* func_802DFB44_730D44(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnDlLink4(objID, id, block, blockB, spawn, &D_802E37B8_7349B8);
}
