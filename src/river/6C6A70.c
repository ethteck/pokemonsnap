#include "common.h"
#include "world/world.h"
#include "app_level/app_level.h"
#include "river.h"

extern PokemonInitData D_802E3EA4_6CBC84;
extern PokemonInitData D_802E40B0_6CBE90;

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C6A70/func_802DEC90_6C6A70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C6A70/func_802DED0C_6C6AEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C6A70/func_802DED68_6C6B48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C6A70/func_802DEDD4_6C6BB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C6A70/func_802DEE2C_6C6C0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C6A70/func_802DEEA0_6C6C80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C6A70/func_802DEF28_6C6D08.s")

GObj* func_802DEF88_6C6D68(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_Spawn(objID, id, block, blockB, spawn, &D_802E3EA4_6CBC84);
}

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C6A70/func_802DEFC0_6C6DA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C6A70/func_802DF078_6C6E58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C6A70/func_802DF0B8_6C6E98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C6A70/func_802DF104_6C6EE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C6A70/func_802DF154_6C6F34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C6A70/func_802DF1F0_6C6FD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C6A70/func_802DF360_6C7140.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C6A70/func_802DF404_6C71E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C6A70/func_802DF478_6C7258.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C6A70/func_802DF4EC_6C72CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C6A70/func_802DF560_6C7340.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C6A70/func_802DF5B8_6C7398.s")

GObj* func_802DF634_6C7414(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802E40B0_6CBE90);
}
