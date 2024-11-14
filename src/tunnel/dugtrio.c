#include "tunnel.h"

extern PokemonInitData D_802EEBBC_5EBC8C;

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/dugtrio/func_802E6490_5E3560.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/dugtrio/func_802E654C_5E361C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/dugtrio/func_802E6574_5E3644.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/dugtrio/func_802E65B4_5E3684.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/dugtrio/func_802E67B8_5E3888.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/dugtrio/func_802E67F8_5E38C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/dugtrio/func_802E6A30_5E3B00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/dugtrio/func_802E6A70_5E3B40.s")

GObj* dugtrio_Spawn(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    GObj* obj = Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802EEBBC_5EBC8C);
    GET_POKEMON(obj)->tangible = false;
    obj->flags |= GOBJ_FLAG_HIDDEN | GOBJ_FLAG_2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/dugtrio/func_802E6C74_5E3D44.s")
