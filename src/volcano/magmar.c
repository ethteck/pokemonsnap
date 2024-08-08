#include "volcano/volcano.h"

extern Texture** D_8031F238[];
extern ModelTreeDef D_80323C30[];

extern AnimCmd* D_80133BF0[];
extern AnimCmd* D_80132FD0[];
extern AnimCmd* D_80136140[];
extern AnimCmd* D_80137800[];
extern AnimCmd* D_80138890[];
extern AnimCmd* D_80138FD0[];
extern AnimCmd* D_80139AD0[];
extern AnimCmd* D_8013AB20[];
extern AnimCmd* D_8013C2B0[];
extern AnimCmd* D_8013D460[];

extern AnimCmd** D_8013E640[];
extern AnimCmd** D_8013E770[];
extern AnimCmd** D_8013EE20[];
extern AnimCmd** D_8013ECF0[];
extern AnimCmd** D_8013F190[];
extern AnimCmd** D_8013F480[];
extern AnimCmd** D_8013F6E0[];
extern AnimCmd** D_8013FA30[];

void func_802D73A8_7285A8(GObj*);
void func_802D7E90_729090(GObj*);
void func_802D7510_728710(GObj*);
void func_802D7584_728784(GObj*);
void func_802D75F4_7287F4(GObj*);
void func_802D76F4_7288F4(GObj*);
void func_802D77BC_7289BC(GObj*);
void func_802D7830_728A30(GObj*);
void func_802D7CB4_728EB4(GObj*);
void func_802D7A94_728C94(GObj*);
void func_802D7B54_728D54(GObj*);
void func_802D7A10_728C10(GObj*);
void func_802D78A4_728AA4(GObj*);

s32 D_802E0FC0_7321C0[] = { 0x11b };
s32 D_802E0FC4_7321C4[] = { 0x11c };
s32 D_802E0FC8_7321C8[] = { 0x11d };
s32 D_802E0FCC_7321CC[] = { 0x11e };
s32 D_802E0FD0_7321D0[] = { 0x11f, 0x8d };

AnimationHeader D_802E0FD8_7321D8 = {
    0.45,
    50,
    D_80137800,
    D_8013EE20,
    NULL
};

AnimationHeader D_802E0FEC_7321EC = {
    0.4,
    60,
    D_80138FD0,
    D_8013F190,
    NULL
};

AnimationHeader D_802E1000_732200 = {
    0.6,
    60,
    D_80132FD0,
    D_8013E640,
    NULL
};

AnimationHeader D_802E1014_732214 = {
    1,
    30,
    D_80136140,
    D_8013ECF0,
    NULL
};

AnimationHeader D_802E1028_732228 = {
    0.7,
    90,
    D_8013AB20,
    D_8013F6E0,
    D_802E0FC0_7321C0
};

AnimationHeader D_802E103C_73223C = {
    0.6,
    60,
    D_8013D460,
    NULL,
    D_802E0FC4_7321C4
};

AnimationHeader D_802E1050_732250 = {
    0.5,
    20,
    D_80138890,
    NULL,
    NULL
};

AnimationHeader D_802E1064_732264 = {
    0.35,
    52,
    D_80139AD0,
    D_8013F480,
    D_802E0FC8_7321C8
};

AnimationHeader D_802E1078_732278 = {
    0.35,
    60,
    D_8013C2B0,
    D_8013FA30,
    D_802E0FCC_7321CC
};

AnimationHeader D_802E108C_73228C = {
    0.5,
    145,
    D_80133BF0,
    D_8013E770,
    D_802E0FD0_7321D0
};

s32 D_802E10A0_7322A0 = 0;

InteractionHandler D_802E10A4_7322A4[] = {
    { POKEMON_CMD_30, func_802D7510_728710, NULL, NULL },
    { POKEMON_CMD_58, NULL, NULL, NULL },
};

InteractionHandler D_802E10C4_7322C4[] = {
    { POKEMON_CMD_9, func_802D76F4_7288F4, NULL, NULL },
    { POKEMON_CMD_13, func_802D77BC_7289BC, NULL, NULL },
    { POKEMON_CMD_10, func_802D7830_728A30, NULL, NULL },
    { POKEMON_CMD_15, func_802D7A10_728C10, NULL, NULL },
    { POKEMON_CMD_5, func_802D7A94_728C94, NULL, NULL },
    { POKEMON_CMD_6, func_802D7A94_728C94, NULL, NULL },
    { POKEMON_CMD_7, func_802D7A94_728C94, NULL, NULL },
    { POKEMON_CMD_37, func_802D7CB4_728EB4, NULL, NULL },
    { POKEMON_CMD_58, NULL, NULL, NULL },
};

InteractionHandler D_802E1154_732354[] = {
    { POKEMON_CMD_9, func_802D76F4_7288F4, NULL, NULL },
    { POKEMON_CMD_13, func_802D77BC_7289BC, NULL, NULL },
    { POKEMON_CMD_10, func_802D7830_728A30, NULL, NULL },
    { POKEMON_CMD_15, func_802D7A10_728C10, NULL, NULL },
    { POKEMON_CMD_5, func_802D7A94_728C94, NULL, NULL },
    { POKEMON_CMD_6, func_802D7A94_728C94, NULL, NULL },
    { POKEMON_CMD_7, func_802D7A94_728C94, NULL, NULL },
    { POKEMON_CMD_26, func_802D7B54_728D54, NULL, NULL },
    { POKEMON_CMD_37, func_802D7CB4_728EB4, NULL, NULL },
    { POKEMON_CMD_58, NULL, NULL, NULL },
};

InteractionHandler D_802E11F4_7323F4[] = {
    { POKEMON_CMD_9, func_802D76F4_7288F4, NULL, NULL },
    { POKEMON_CMD_13, func_802D77BC_7289BC, NULL, NULL },
    { POKEMON_CMD_21, func_802D7510_728710, NULL, NULL },
    { POKEMON_CMD_10, func_802D7830_728A30, NULL, NULL },
    { POKEMON_CMD_5, func_802D7A94_728C94, NULL, NULL },
    { POKEMON_CMD_6, func_802D7A94_728C94, NULL, NULL },
    { POKEMON_CMD_7, func_802D7A94_728C94, NULL, NULL },
    { POKEMON_CMD_26, func_802D7B54_728D54, NULL, NULL },
    { POKEMON_CMD_37, func_802D7CB4_728EB4, NULL, NULL },
    { POKEMON_CMD_58, NULL, NULL, NULL },
};

InteractionHandler D_802E1294_732494[] = {
    { POKEMON_CMD_9, func_802D76F4_7288F4, NULL, NULL },
    { POKEMON_CMD_13, func_802D77BC_7289BC, NULL, NULL },
    { POKEMON_CMD_21, func_802D7510_728710, NULL, NULL },
    { POKEMON_CMD_10, func_802D7830_728A30, NULL, NULL },
    { POKEMON_CMD_5, func_802D7A94_728C94, NULL, NULL },
    { POKEMON_CMD_6, func_802D7A94_728C94, NULL, NULL },
    { POKEMON_CMD_7, func_802D7A94_728C94, NULL, NULL },
    { POKEMON_CMD_37, func_802D7CB4_728EB4, NULL, NULL },
    { POKEMON_CMD_58, NULL, NULL, NULL },
};

InteractionHandler D_802E1324_732524[] = {
    { POKEMON_CMD_9, func_802D76F4_7288F4, NULL, NULL },
    { POKEMON_CMD_13, func_802D77BC_7289BC, NULL, NULL },
    { POKEMON_CMD_10, func_802D7830_728A30, NULL, NULL },
    { POKEMON_CMD_37, func_802D7CB4_728EB4, NULL, NULL },
    { POKEMON_CMD_58, NULL, NULL, NULL },
};

InteractionHandler D_802E1374_732574[] = {
    { POKEMON_CMD_9, func_802D76F4_7288F4, NULL, NULL },
    { POKEMON_CMD_13, func_802D77BC_7289BC, NULL, NULL },
    { POKEMON_CMD_15, func_802D7A10_728C10, NULL, NULL },
    { POKEMON_CMD_37, func_802D7CB4_728EB4, NULL, NULL },
    { POKEMON_CMD_58, NULL, NULL, NULL },
};

InteractionHandler D_802E13C4_7325C4[] = {
    { POKEMON_CMD_9, func_802D76F4_7288F4, NULL, NULL },
    { POKEMON_CMD_13, func_802D77BC_7289BC, NULL, NULL },
    { POKEMON_CMD_58, NULL, NULL, NULL },
};

InteractionHandler D_802E13F4_7325F4[] = {
    { POKEMON_CMD_9, func_802D76F4_7288F4, NULL, NULL },
    { POKEMON_CMD_13, func_802D77BC_7289BC, NULL, NULL },
    { POKEMON_CMD_37, func_802D7CB4_728EB4, NULL, NULL },
    { POKEMON_CMD_58, NULL, NULL, NULL },
};

InteractionHandler D_802E1434_732634[] = {
    { POKEMON_CMD_9, func_802D76F4_7288F4, NULL, NULL },
    { POKEMON_CMD_13, func_802D77BC_7289BC, NULL, NULL },
    { POKEMON_CMD_10, func_802D7830_728A30, NULL, NULL },
    { POKEMON_CMD_37, func_802D7CB4_728EB4, NULL, NULL },
    { POKEMON_CMD_58, NULL, NULL, NULL },
};

RandomState D_802E1484_732684[] = {
    { 100, func_802D7510_728710 },
    { 100, func_802D7584_728784 },
    { 100, func_802D75F4_7287F4 },
    { 0, NULL },
};

InteractionHandler D_802E14A4_7326A4[] = {
    { POKEMON_CMD_41, func_802D7E90_729090, NULL, NULL },
    { POKEMON_CMD_58, NULL, NULL, NULL },
};

PokemonAnimationSetup D_802E14C4_7326C4 = {
    &D_802E0FD8_7321D8,
    func_802D73A8_7285A8,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData D_802E14D8_7326D8 = {
    D_80323C30,
    D_8031F238,
    renderPokemonModelTypeJFogged,
    &D_802E14C4_7326C4,
    { 1.3, 1.3, 1.3 },
    { 0, 110, 0 },
    68,
    0x25,
    0,
    0,
    0,
    { 0, 0, 0 }
};

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/magmar/func_802D7290_728490.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/magmar/func_802D73A8_7285A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/magmar/func_802D7458_728658.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/magmar/func_802D7510_728710.s")

void func_802D7584_728784(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_802E0FEC_7321EC);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E10C4_7322C4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_802E1484_732684);
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/magmar/func_802D75F4_7287F4.s")

void func_802D7698_728898(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 40.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/magmar/func_802D76F4_7288F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/magmar/func_802D77BC_7289BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/magmar/func_802D7830_728A30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/magmar/func_802D78A4_728AA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/magmar/func_802D798C_728B8C.s")

void func_802D7A10_728C10(GObj* arg0) {
    Pokemon_SetState(arg0, func_802D78A4_728AA4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/magmar/func_802D7A34_728C34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/magmar/func_802D7A94_728C94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/magmar/func_802D7B08_728D08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/magmar/func_802D7B54_728D54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/magmar/func_802D7C30_728E30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/magmar/func_802D7CB4_728EB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/magmar/func_802D7D84_728F84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/magmar/func_802D7E90_729090.s")

GObj* func_802D7F28_729128(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802E14D8_7326D8);
}
