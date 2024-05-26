#include "common.h"
#include "../world/world.h"

void func_802CB614_7A4BA4(GObj*);
void func_802CC08C_7A561C(GObj*);
void func_802CC514_7A5AA4(GObj*);

extern AnimationHeader D_802D352C_7ACABC;
extern PokemonInitData D_802D37C0_7ACD50;

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CB080_7A4610.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CB110_7A46A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CB194_7A4724.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CB238_7A47C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CB294_7A4824.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CB338_7A48C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CB394_7A4924.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CB404_7A4994.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CB474_7A4A04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CB550_7A4AE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CB5AC_7A4B3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CB614_7A4BA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CB6F8_7A4C88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CB79C_7A4D2C.s")

void func_802CB7F4_7A4D84(GObj* arg0) {
    updatePokemonState(arg0, func_802CB614_7A4BA4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CB818_7A4DA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CB88C_7A4E1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CB8D8_7A4E68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CB92C_7A4EBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CB9BC_7A4F4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CBA24_7A4FB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CBA90_7A5020.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CBBDC_7A516C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CBC74_7A5204.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CBCDC_7A526C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CBD74_7A5304.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CBE14_7A53A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CBE9C_7A542C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CBF18_7A54A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CBF64_7A54F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CBFDC_7A556C.s")

void func_802CC068_7A55F8(GObj* arg0) {
    updatePokemonState(arg0, func_802CC08C_7A561C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CC08C_7A561C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CC104_7A5694.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CC1E0_7A5770.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CC250_7A57E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CC2B4_7A5844.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CC320_7A58B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CC3B4_7A5944.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CC424_7A59B4.s")

void func_802CC4DC_7A5A6C(GObj* arg0) {
    setPokemonAnimation(arg0, &D_802D352C_7ACABC);
    updatePokemonState(arg0, func_802CC514_7A5AA4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CC514_7A5AA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CC5C0_7A5B50.s")

GObj* func_802CC8A8_7A5E38(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return spawnPokemonOnGround(objID, id, block, blockB, spawn, &D_802D37C0_7ACD50);
}
#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CC8E0_7A5E70.s")
