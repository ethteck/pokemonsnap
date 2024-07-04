#include "common.h"
#include "ld_addrs.h"
#include "../world/world.h"
#include "app_level/app_level.h"

void func_802D6788_727988(void);

extern PokemonDef D_802E0D44_731F44;
extern s32 D_802E0EB8_7320B8;
extern SceneSetup D_802E0ED8_7320D8;

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/7272E0/func_802D60E0_7272E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/7272E0/func_802D61AC_7273AC.s")

void func_802D6344_727544(WorldBlock* arg0, WorldBlock* arg1) {
    pokemonAdd(arg0, arg1, &D_802E0D44_731F44);
}

void func_802D6368_727568(WorldBlock* arg0, WorldBlock* arg1) {
    pokemonsChangeBlock(arg0, arg1, &D_802E0D44_731F44);
}

void func_802D638C_72758C(WorldBlock* arg0) {
    pokemonRemove(arg0, &D_802E0D44_731F44);
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/7272E0/func_802D63B0_7275B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/7272E0/func_802D643C_72763C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/7272E0/func_802D64A0_7276A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/7272E0/func_802D64A8_7276A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/7272E0/func_802D64B0_7276B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/7272E0/func_802D6544_727744.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/7272E0/func_802D6630_727830.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/7272E0/func_802D6780_727980.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/7272E0/func_802D6788_727988.s")

s32 func_802D67C4_7279C4(s32 arg0) {
    D_802E0ED8_7320D8.gtlSetup.heapSize = (uintptr_t)volcano_code_VRAM - (uintptr_t)_326C10_VRAM_END;
    gtlSetIntervals(1, 2);
    gtlDisableNearClipping(1);
    func_802D6788_727988();
    omSetupScene(&D_802E0ED8_7320D8);
    if (D_802E0EB8_7320B8 == 6) {
        return 2;
    }
    if (func_8009BC68() > 0) {
        return 9;
    }
    func_800AAED0(0x10);
    return 0xD;
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/7272E0/func_802D6864_727A64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/7272E0/func_802D693C_727B3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/7272E0/func_802D6A14_727C14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/7272E0/func_802D6A5C_727C5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/7272E0/func_802D6B2C_727D2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/7272E0/func_802D6B64_727D64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/7272E0/func_802D6BB0_727DB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/7272E0/func_802D6C38_727E38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/7272E0/func_802D6CC0_727EC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/7272E0/func_802D6CFC_727EFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/7272E0/func_802D6D6C_727F6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/7272E0/func_802D6E14_728014.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/7272E0/func_802D6EA8_7280A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/7272E0/func_802D6F38_728138.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/7272E0/func_802D6F68_728168.s")
