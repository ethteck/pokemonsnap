#include "common.h"
#include "ld_addrs.h"

extern ScreenSettings D_801E4250_9AE4A0;
extern SceneSetup D_801E426C_9AE4BC;

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_5/9A6B10/func_801DC8C0_9A6B10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_5/9A6B10/func_801DC904_9A6B54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_5/9A6B10/func_801DCA14_9A6C64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_5/9A6B10/func_801DCA48_9A6C98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_5/9A6B10/func_801DCBF4_9A6E44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_5/9A6B10/func_801DCC74_9A6EC4.s")

s32 func_801DCCA0_9A6EF0(s32 sceneId) {
    UNUSED s32 pad[3];

    viApplyScreenSettings(&D_801E4250_9AE4A0);
    D_801E426C_9AE4BC.gtlSetup.heapSize = (uintptr_t) unk_end_level_VRAM - (uintptr_t) unk_end_level_5_VRAM_END;
    gtlDisableNearClipping(1);
    omSetupScene(&D_801E426C_9AE4BC);
    func_800AAED0(0x100000);

    return D_800AF3C0;
}
