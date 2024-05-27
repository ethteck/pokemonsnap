#include "common.h"
#include "ld_addrs.h"
#include "world/world.h"
#include "app_level/app_level.h"

extern PokemonDef D_802C6234_6486E4;
extern s32 D_802C6378_648828;
extern SceneSetup D_802C6398_648848;

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6401B0/func_802BDD00_6401B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6401B0/func_802BDDCC_64027C.s")

void func_802BDF34_6403E4(WorldBlock* arg0, WorldBlock* arg1) {
    pokemonAdd(arg0, arg1, &D_802C6234_6486E4);
}

void func_802BDF58_640408(WorldBlock* arg0, WorldBlock* arg1) {
    pokemonsChangeBlock(arg0, arg1, &D_802C6234_6486E4);
}

void func_802BDF7C_64042C(WorldBlock* arg0) {
    pokemonRemove(arg0, &D_802C6234_6486E4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6401B0/func_802BDFA0_640450.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6401B0/func_802BE038_6404E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6401B0/func_802BE09C_64054C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6401B0/func_802BE0A4_640554.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6401B0/func_802BE0AC_64055C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6401B0/func_802BE140_6405F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6401B0/func_802BE22C_6406DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6401B0/func_802BE3A8_640858.s")

s32 func_802BE3B0_640860(s32 arg0) {
    D_802C6398_648848.gtlSetup.heapSize = (uintptr_t) cave_code_VRAM - (uintptr_t) _1F5E70_VRAM_END;
    gtlSetIntervals(1, 2);
    gtlDisableNearClipping(1);
    omSetupScene(&D_802C6398_648848);

    if (D_802C6378_648828 == 6) {
        return SCENE_CAVE;
    }

    if (func_8009BC68() > 0) {
        return SCENE_CAMERA_CHECK;
    }

    func_800AAED0(0x10);

    return SCENE_13;
}
