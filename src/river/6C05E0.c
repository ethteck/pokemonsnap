#include "common.h"
#include "ld_addrs.h"
#include "../world/world.h"

extern PokemonDef D_802E271C_6CA4FC;
extern s32 D_802E28B4_6CA694;
extern SceneSetup D_802E293C_6CA71C;

void func_802D8800_6C05E0(WorldBlock* arg0, WorldBlock* arg1) {
    pokemonAdd(arg0, arg1, &D_802E271C_6CA4FC);
}

void func_802D8824_6C0604(WorldBlock* arg0, WorldBlock* arg1) {
    pokemonsChangeBlock(arg0, arg1, &D_802E271C_6CA4FC);
}

void func_802D8848_6C0628(WorldBlock* arg0) {
    pokemonRemove(arg0, &D_802E271C_6CA4FC);
}

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C05E0/func_802D886C_6C064C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C05E0/func_802D88F8_6C06D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C05E0/func_802D895C_6C073C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C05E0/func_802D89AC_6C078C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C05E0/func_802D89B4_6C0794.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C05E0/func_802D8A48_6C0828.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C05E0/func_802D8B34_6C0914.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C05E0/func_802D8C24_6C0A04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C05E0/func_802D8CF0_6C0AD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C05E0/func_802D8DC4_6C0BA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C05E0/func_802D8E98_6C0C78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C05E0/func_802D8FCC_6C0DAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C05E0/func_802D90B8_6C0E98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C05E0/func_802D9208_6C0FE8.s")

s32 func_802D9210_6C0FF0(s32 sceneId) {
    D_802E293C_6CA71C.gtlSetup.heapSize = (uintptr_t) river_code_VRAM - (uintptr_t) _29A190_VRAM_END;
    gtlSetIntervals(1, 2);
    gtlDisableNearClipping(1);
    omSetupScene(&D_802E293C_6CA71C);

    if (D_802E28B4_6CA694 == 6) {
        return SCENE_RIVER;
    }

    if (func_8009BC68() > 0) {
        return SCENE_CAMERA_CHECK;
    }

    func_800AAED0(0x10);

    return SCENE_OAKS_LAB_2;
}
