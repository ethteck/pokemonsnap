#include "valley.h"

extern AnimationHeader D_802D2D10_7AC2A0;
extern AnimationHeader D_802D2D24_7AC2B4;
extern AnimationHeader D_802D2D38_7AC2C8;
extern AnimationHeader D_802D2D4C_7AC2DC;
extern AnimationHeader D_802D2D60_7AC2F0;
extern GObj* D_802D2D74_7AC304;
extern u16 D_802D2D78_7AC308;
extern InteractionHandler D_802D2D7C_7AC30C[];
extern InteractionHandler D_802D2DAC_7AC33C[];
extern RandomState D_802D2DCC_7AC35C;
extern PokemonInitData D_802D2DF8_7AC388;

void func_802C95E4_7A2B74(GObj*);
void func_802C9750_7A2CE0(GObj*);

void func_802C95C0_7A2B50(GObj* arg0) {
    Pokemon_SetState(arg0, func_802C95E4_7A2B74);
}

void func_802C95E4_7A2B74(GObj* arg0) {
    UNUSED s32 padding[3];
    Pokemon* pokemon = GET_POKEMON(arg0);

    pokemon->tangible = false;
    arg0->flags |= 0x2 | 0x1;
    pokemon->transitionGraph = D_802D2DAC_7AC33C;
    Pokemon_WaitForFlag(arg0, 0);
    Pokemon_SetState(arg0, NULL);
}

void func_802C9634_7A2BC4(GObj* arg0) {
    UNUSED s32 padding[3];
    Pokemon* pokemon = GET_POKEMON(arg0);

    D_802D2D78_7AC308 = 1;
    pokemon->tangible = true;
    arg0->flags = 0;
    Pokemon_SetAnimation(arg0, &D_802D2D10_7AC2A0);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(arg0, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(arg0, func_802C9750_7A2CE0);
}

void func_802C96A0_7A2C30(GObj* arg0) {
    UNUSED s32 padding[3];
    Pokemon* pokemon = GET_POKEMON(arg0);

    Pokemon_SetAnimation(arg0, &D_802D2D24_7AC2B4);
    pokemon->transitionGraph = D_802D2D7C_7AC30C;
    Pokemon_WaitForFlag(arg0, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(arg0, &D_802D2DCC_7AC35C);
}

void func_802C96FC_7A2C8C(GObj* arg0) {
    UNUSED s32 padding[3];
    Pokemon* pokemon = GET_POKEMON(arg0);

    Pokemon_SetAnimation(arg0, &D_802D2D60_7AC2F0);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(arg0, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(arg0, func_802C9750_7A2CE0);
}

void func_802C9750_7A2CE0(GObj* arg0) {
    UNUSED s32 padding[3];
    Pokemon* pokemon = GET_POKEMON(arg0);

    Pokemon_SetAnimation(arg0, &D_802D2D4C_7AC2DC);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(arg0, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(arg0, func_802C96A0_7A2C30);
}

void func_802C97A4_7A2D34(GObj* arg0) {
    UNUSED s32 padding[3];
    Pokemon* pokemon = GET_POKEMON(arg0);

    Pokemon_SetAnimation(arg0, &D_802D2D38_7AC2C8);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(arg0, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(arg0, func_802C96A0_7A2C30);
}

GObj* func_802C97F8_7A2D88(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    D_802D2D74_7AC304 = Pokemon_Spawn(gObjID, id, roomA, roomB, spawn, &D_802D2DF8_7AC388);

    return D_802D2D74_7AC304;
}
