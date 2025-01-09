#include "valley.h"

extern s32 D_802D2980_7ABF10;
extern GObj* D_802D2D74_7AC304;
extern u16 D_802D2D78_7AC308;
extern GObj* D_802D3FF4_7AD584;
extern s32 D_802D3FF8_7AD588;
extern AnimationHeader D_802EC818_7C5DA8;
extern AnimationHeader D_802EC82C_7C5DBC;
extern AnimationHeader D_802EC840_7C5DD0;
extern AnimationHeader D_802EC854_7C5DE4;
extern u16 D_802EC868_7C5DF8;
extern u16 D_802EC86C_7C5DFC;
extern RandomState D_802EC870_7C5E00;
extern s32 D_802EC890_7C5E20;
// extern ? D_802EC894_7C5E24;
// extern ? D_802EC898_7C5E28;
// extern ? D_802EC8B8_7C5E48;
// extern ? D_802EC8D8_7C5E68;
// extern ? D_802EC8E4_7C5E74;
// extern ? D_802EC914_7C5EA4;
extern PokemonInitData D_802EC934_7C5EC4;

void func_802D1344_7AA8D4(GObj*);
void func_802D1414_7AA9A4(GObj*);
void func_802D1454_7AA9E4(GObj*);
void func_802D156C_7AAAFC(GObj*);
void func_802D1598_7AAB28(GObj*);
void func_802D15BC_7AAB4C(GObj*);
void func_802D17D8_7AAD68(GObj*);
void func_802D18D8_7AAE68(GObj*);
void func_802D19DC_7AAF6C(GObj*);
void func_802D1ACC_7AB05C(GObj*);
void func_802D1B48_7AB0D8(GObj*);
void func_802D1BC8_7AB158(GObj*);
void func_802D1C40_7AB1D0(GObj*);
void func_802D1D4C_7AB2DC(GObj*);
void func_802D1E3C_7AB3CC(GObj*);
void func_802D1EB8_7AB448(GObj*);
void func_802D1FC0_7AB550(GObj*);
void func_802D2128_7AB6B8(GObj*);

POKEMON_FUNC(func_802D1200_7AA790)
    pokemon->miscVars[0].field1 = 0;
    if (pokemon->behavior == 1) {
        Pokemon_SetState(obj, func_802D1454_7AA9E4);
    }
    if (pokemon->behavior == 2) {
        Pokemon_SetState(obj, func_802D1598_7AAB28);
    }
    if (pokemon->behavior == 3) {
        Pokemon_SetState(obj, func_802D1BC8_7AB158);
    }
    Pokemon_SetStateRandom(obj, &D_802EC870_7C5E00);
}

POKEMON_FUNC(func_802D129C_7AA82C)
    Pokemon_ForceAnimation(obj, &D_802EC82C_7C5DBC);
    Pokemon_SetState(obj, func_802D1344_7AA8D4);
}

POKEMON_FUNC(func_802D12D4_7AA864)
    Pokemon_ForceAnimation(obj, &D_802EC840_7C5DD0);
    Pokemon_SetState(obj, func_802D1344_7AA8D4);
}

POKEMON_FUNC(func_802D130C_7AA89C)
    Pokemon_ForceAnimation(obj, &D_802EC854_7C5DE4);
    Pokemon_SetState(obj, func_802D1344_7AA8D4);
}

POKEMON_FUNC(func_802D1344_7AA8D4)
    rotation->v.y = (randRange(360) * PI) / 180.0f;
    Pokemon_StartPathProc(obj, func_802D1414_7AA9A4);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    if (pokemon->behavior == 1) {
        Pokemon_SetState(obj, func_802D1454_7AA9E4);
    }
    D_802D2980_7ABF10 = 0;
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802D1414_7AA9A4)
    func_8035E298_4FE6A8(obj);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802D1454_7AA9E4)
    Vec3f sp34;
    GroundResult ground;

    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_2 | GOBJ_FLAG_HIDDEN;
    pokemon->counter = randRange(180) + 60, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);
    if (D_802D2D78_7AC308) {
        Pokemon_SetState(obj, func_802D156C_7AAAFC);
    }
    sp34.x = position->v.x;
    sp34.z = position->v.z;
    getGroundAt(sp34.x, sp34.z, &ground);
    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);
    sp34.y = ground.height;
    func_8035E174_4FE584(obj, &sp34);
    pokemon->tangible = true;
    obj->flags = 0;
    Pokemon_SetStateRandom(obj, &D_802EC870_7C5E00);
}

POKEMON_FUNC(func_802D156C_7AAAFC)
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802D1598_7AAB28)
    Pokemon_SetState(obj, func_802D15BC_7AAB4C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7AA790/func_802D15BC_7AAB4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7AA790/func_802D16CC_7AAC5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7AA790/func_802D1734_7AACC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7AA790/func_802D17D8_7AAD68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7AA790/func_802D18D8_7AAE68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7AA790/func_802D19DC_7AAF6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7AA790/func_802D1ACC_7AB05C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7AA790/func_802D1B48_7AB0D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7AA790/func_802D1BC8_7AB158.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7AA790/func_802D1C40_7AB1D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7AA790/func_802D1D4C_7AB2DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7AA790/func_802D1E3C_7AB3CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7AA790/func_802D1EB8_7AB448.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7AA790/func_802D1F18_7AB4A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7AA790/func_802D1FC0_7AB550.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7AA790/func_802D2128_7AB6B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7AA790/func_802D21C8_7AB758.s")
