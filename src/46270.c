#include "common.h"
#include "os_cache.h"
#include "sys/dma.h"

extern Overlay D_800ABBD0;
extern Overlay D_800ABDEC;
extern s32 D_800AC00C;
extern s32 D_800B0578;

void func_8009A8C0(s32 arg0) {
    D_800B0578 = arg0;
}

s32 func_8009A8CC(void) {
    return D_800B0578;
}

void func_8009A8D8(s32 arg0) {
    D_800AC00C = arg0;
}

s32 func_8009A8E4(void) {
    return D_800AC00C;
}

#pragma GLOBAL_ASM("asm/nonmatchings/46270/func_8009A8F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/46270/func_8009AE0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/46270/func_8009B2BC.s")

void func_8009B40C(void) {
    s32 i = 0;

    for (i = 0;;) {
        load_overlay(&D_800ABDEC);
        load_overlay(&D_800ABBD0);
        if (func_801DD010(i) != 0) {
            while (TRUE);
        }
        i++;
        if (i == 0x11) {
            while (TRUE);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/46270/start_scene_manager.s")
