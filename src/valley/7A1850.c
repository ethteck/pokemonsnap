#include "common.h"
#include "../world/world.h"

extern PokemonInitData D_802D2CB4_7AC244;

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A1850/func_802C82C0_7A1850.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A1850/func_802C8354_7A18E4.s")

void func_802C840C_7A199C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    func_8036148C_50189C(obj, 0.1f, 0x2A);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A1850/func_802C8458_7A19E8.s")

void func_802C84D0_7A1A60(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setNodePosToNegRoom(obj);
    pokemonPathLoop(obj, 0, 1, 0.033333335f, 0.0f, 3U);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A1850/func_802C853C_7A1ACC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A1850/func_802C8594_7A1B24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A1850/func_802C8650_7A1BE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A1850/func_802C8704_7A1C94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A1850/func_802C8764_7A1CF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A1850/func_802C8828_7A1DB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A1850/func_802C88C4_7A1E54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A1850/func_802C892C_7A1EBC.s")

void func_802C8998_7A1F28(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 20.0f;
    func_80361110_501520(obj, 500.0f, 0.1f, 1);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A1850/func_802C89F4_7A1F84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A1850/func_802C8A4C_7A1FDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A1850/func_802C8B38_7A20C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A1850/func_802C8C08_7A2198.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A1850/func_802C8C70_7A2200.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A1850/func_802C8D30_7A22C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A1850/func_802C8E54_7A23E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A1850/func_802C8EA8_7A2438.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A1850/func_802C8F50_7A24E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A1850/func_802C903C_7A25CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A1850/func_802C90E4_7A2674.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A1850/func_802C91AC_7A273C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A1850/func_802C931C_7A28AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A1850/func_802C9408_7A2998.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A1850/func_802C94A4_7A2A34.s")

GObj* func_802C957C_7A2B0C(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return spawnPokemonOnGround(objID, id, block, blockB, spawn, &D_802D2CB4_7AC244);
}
