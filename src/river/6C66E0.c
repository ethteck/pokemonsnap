#include "common.h"

#include "world/world.h"
#include "app_level/app_level.h"
#include "river.h"

extern PokemonInitData D_802E3D68_6CBB48;
extern PokemonInitData D_802E3DCC_6CBBAC;
extern GObj* D_8033F5C8_7273A8;

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C66E0/func_802DE900_6C66E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C66E0/func_802DE958_6C6738.s")

GObj* func_802DE9C0_6C67A0(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    D_8033F5C8_7273A8 = Pokemon_SpawnDlLink4(gObjID, id, roomA, roomB, spawn, &D_802E3D68_6CBB48);

    return D_8033F5C8_7273A8;
}

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C66E0/func_802DEA00_6C67E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C66E0/func_802DEB00_6C68E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C66E0/func_802DEBB8_6C6998.s")

GObj* func_802DEC50_6C6A30(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_Spawn(objID, id, block, blockB, spawn, &D_802E3DCC_6CBBAC);
}
