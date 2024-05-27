#include "common.h"
#include "ld_addrs.h"
#include "world/world.h"
#include "app_level/app_level.h"

extern PokemonDef D_8034AB34_82A2A4;
extern s32 D_8034ABD8_82A348;
extern SceneSetup D_8034ABF8_82A368;

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/825E30/func_803466C0_825E30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/825E30/func_803467A4_825F14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/825E30/func_80346898_826008.s")

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/825E30/func_80346968_8260D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/825E30/func_80346994_826104.s")

void func_803469E0_826150(WorldBlock* arg0, WorldBlock* arg1) {
    pokemonsChangeBlock(arg0, arg1, &D_8034AB34_82A2A4);
}

void func_80346A04_826174(WorldBlock* arg0) {
    pokemonRemove(arg0, &D_8034AB34_82A2A4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/825E30/func_80346A28_826198.s")

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/825E30/func_80346AA8_826218.s")

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/825E30/func_80346B0C_82627C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/825E30/func_80346B94_826304.s")

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/825E30/func_80346BD0_826340.s")

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/825E30/func_80346C64_8263D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/825E30/func_80346D50_8264C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/825E30/func_80346EE8_826658.s")

s32 func_80346EF0_826660(s32 arg0) {
    D_8034ABF8_82A368.gtlSetup.heapSize = (uintptr_t) rainbow_code_VRAM - (uintptr_t) _4A8160_VRAM_END;
    gtlSetIntervals(1, 2);
    gtlDisableNearClipping(1);
    omSetupScene(&D_8034ABF8_82A368);

    if (D_8034ABD8_82A348 == 6) {
        return SCENE_RAINBOW;
    }

    if (func_8009BC68() > 0) {
        return SCENE_CAMERA_CHECK;
    }

    func_800AAED0(0x10);
    return SCENE_13;
}
