#include "common.h"
#include "ld_addrs.h"

extern s32 D_802EE130_5EB200;
extern SceneSetup D_802EE150_5EB220;

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5DF5D0/func_802E2500_5DF5D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5DF5D0/func_802E25D4_5DF6A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5DF5D0/func_802E273C_5DF80C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5DF5D0/func_802E2760_5DF830.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5DF5D0/func_802E2784_5DF854.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5DF5D0/func_802E27A8_5DF878.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5DF5D0/func_802E2840_5DF910.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5DF5D0/func_802E28A4_5DF974.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5DF5D0/func_802E28AC_5DF97C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5DF5D0/func_802E28B4_5DF984.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5DF5D0/func_802E2948_5DFA18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5DF5D0/func_802E2A34_5DFB04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5DF5D0/func_802E2BB0_5DFC80.s")

s32 func_802E2BB8_5DFC88(s32 arg0) {
    D_802EE150_5EB220.gtlSetup.heapSize = (uintptr_t) tunnel_code_VRAM - (uintptr_t) _162CB0_VRAM_END;
    gtlSetIntervals(1, 2);
    gtlDisableNearClipping(1);
    omSetupScene(&D_802EE150_5EB220);

    switch (D_802EE130_5EB200) {
        case 6:
            return SCENE_TUNNEL;
        case 7:
        case 8:
            return SCENE_8;
    }

    if (func_8009BC68() > 0) {
        return SCENE_CAMERA_CHECK;
    }

    func_800AAED0(0x10);
    return SCENE_13;
}



#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5DF5D0/func_802E2C70_5DFD40.s")
