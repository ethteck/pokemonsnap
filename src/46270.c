#include "common.h"
#include "os_cache.h"
#include "sys/dma.h"

#include "ld_addrs.h"

extern Overlay D_800ABBD0;
extern Overlay D_800ABDC8;
extern Overlay D_800ABDEC;
extern Overlay D_800ABE10;
extern Overlay D_800ABE34;
extern Overlay D_800ABE58;
extern Overlay D_800ABE7C;
extern Overlay D_800ABEA0;
extern Overlay D_800ABEC4;
extern Overlay D_800ABEE8;
extern Overlay D_800ABF0C;
extern Overlay D_800ABF30;
extern Overlay D_800ABF54;
extern Overlay D_800ABF78;
extern Overlay D_800ABF9C;
extern Overlay D_800ABFC0;
extern Overlay D_800ABFE4;
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

void func_8009A8F0(s32 levelID) {
    switch (levelID) {
        case 0:
            dmaLoadOverlay(&D_800ABE10);
            dmaReadRom(stage0_extra_ROM_START, stage0_extra_VRAM, stage0_extra_ROM_END - stage0_extra_ROM_START);
            dmaReadRom(magikarp1_ROM_START, magikarp1_VRAM, magikarp1_ROM_END - magikarp1_ROM_START);
            dmaReadRom(magikarp2_ROM_START, magikarp2_VRAM, magikarp2_ROM_END - magikarp2_ROM_START);
            dmaReadRom(pikachu1_ROM_START, pikachu1_VRAM, pikachu1_ROM_END - pikachu1_ROM_START);
            dmaReadRom(pikachu2_ROM_START, pikachu2_VRAM, pikachu2_ROM_END - pikachu2_ROM_START);
            return;
        case 1:
            dmaLoadOverlay(&D_800ABE58);
            dmaReadRom(stage1_extra_ROM_START, stage1_extra_VRAM, stage1_extra_ROM_END - stage1_extra_ROM_START);
            dmaReadRom(magikarp1_ROM_START, magikarp1_VRAM, magikarp1_ROM_END - magikarp1_ROM_START);
            dmaReadRom(magikarp2_ROM_START, magikarp2_VRAM, magikarp2_ROM_END - magikarp2_ROM_START);
            dmaReadRom(pikachu1_ROM_START, pikachu1_VRAM, pikachu1_ROM_END - pikachu1_ROM_START);
            dmaReadRom(pikachu2_ROM_START, pikachu2_VRAM, pikachu2_ROM_END - pikachu2_ROM_START);
            dmaReadRom(zubat1_ROM_START, zubat1_VRAM, zubat1_ROM_END - zubat1_ROM_START);
            dmaReadRom(zubat2_ROM_START, zubat2_VRAM, zubat2_ROM_END - zubat2_ROM_START);
            break;
        case 4:
            dmaLoadOverlay(&D_800ABEA0);
            dmaReadRom(stage4_extra_ROM_START, stage4_extra_VRAM, stage4_extra_ROM_END - stage4_extra_ROM_START);
            dmaReadRom(bulbasaur1_ROM_START, bulbasaur1_VRAM, bulbasaur1_ROM_END - bulbasaur1_ROM_START);
            dmaReadRom(bulbasaur2_ROM_START, bulbasaur2_VRAM, bulbasaur2_ROM_END - bulbasaur2_ROM_START);
            dmaReadRom(magikarp1_ROM_START, magikarp1_VRAM, magikarp1_ROM_END - magikarp1_ROM_START);
            dmaReadRom(magikarp2_ROM_START, magikarp2_VRAM, magikarp2_ROM_END - magikarp2_ROM_START);
            dmaReadRom(pikachu1_ROM_START, pikachu1_VRAM, pikachu1_ROM_END - pikachu1_ROM_START);
            dmaReadRom(pikachu2_ROM_START, pikachu2_VRAM, pikachu2_ROM_END - pikachu2_ROM_START);
            dmaReadRom(zubat1_ROM_START, zubat1_VRAM, zubat1_ROM_END - zubat1_ROM_START);
            dmaReadRom(zubat2_ROM_START, zubat2_VRAM, zubat2_ROM_END - zubat2_ROM_START);
            break;
        case 3:
            dmaLoadOverlay(&D_800ABEE8);
            dmaReadRom(stage3_extra_ROM_START, stage3_extra_VRAM, stage3_extra_ROM_END - stage3_extra_ROM_START);
            dmaReadRom(bulbasaur1_ROM_START, bulbasaur1_VRAM, bulbasaur1_ROM_END - bulbasaur1_ROM_START);
            dmaReadRom(bulbasaur2_ROM_START, bulbasaur2_VRAM, bulbasaur2_ROM_END - bulbasaur2_ROM_START);
            dmaReadRom(magikarp1_ROM_START, magikarp1_VRAM, magikarp1_ROM_END - magikarp1_ROM_START);
            dmaReadRom(magikarp2_ROM_START, magikarp2_VRAM, magikarp2_ROM_END - magikarp2_ROM_START);
            dmaReadRom(pikachu1_ROM_START, pikachu1_VRAM, pikachu1_ROM_END - pikachu1_ROM_START);
            dmaReadRom(pikachu2_ROM_START, pikachu2_VRAM, pikachu2_ROM_END - pikachu2_ROM_START);
            break;
        case 2:
            dmaLoadOverlay(&D_800ABF30);
            dmaReadRom(stage2_extra_ROM_START, stage2_extra_VRAM, stage2_extra_ROM_END - stage2_extra_ROM_START);
            dmaReadRom(magikarp1_ROM_START, magikarp1_VRAM, magikarp1_ROM_END - magikarp1_ROM_START);
            dmaReadRom(magikarp2_ROM_START, magikarp2_VRAM, magikarp2_ROM_END - magikarp2_ROM_START);
            break;
        case 5:
            dmaLoadOverlay(&D_800ABF78);
            dmaReadRom(stage5_extra_ROM_START, stage5_extra_VRAM, stage5_extra_ROM_END - stage5_extra_ROM_START);
            dmaReadRom(magikarp1_ROM_START, magikarp1_VRAM, magikarp1_ROM_END - magikarp1_ROM_START);
            dmaReadRom(magikarp2_ROM_START, magikarp2_VRAM, magikarp2_ROM_END - magikarp2_ROM_START);
            break;
        case 6:
            dmaLoadOverlay(&D_800ABFC0);
            dmaReadRom(stage6_extra_ROM_START, stage6_extra_VRAM, stage6_extra_ROM_END - stage6_extra_ROM_START);
            break;
    }
}

void func_8009AE0C(u32 arg0) {
    dmaLoadOverlay(&D_800ABDEC);
    dmaLoadOverlay(&D_800ABDC8);
    switch (arg0) {
        case 0:
            dmaLoadOverlay(&D_800ABE34);
            dmaLoadOverlay(&D_800ABE10);
            dmaReadRom(magikarp1_ROM_START, magikarp1_VRAM, magikarp1_ROM_END - magikarp1_ROM_START);
            dmaReadRom(magikarp3_ROM_START, magikarp3_VRAM, magikarp3_ROM_END - magikarp3_ROM_START);
            dmaReadRom(pikachu1_ROM_START, pikachu1_VRAM, pikachu1_ROM_END - pikachu1_ROM_START);
            dmaReadRom(pikachu3_ROM_START, pikachu3_VRAM, pikachu3_ROM_END - pikachu3_ROM_START);
            break;
        case 1:
            dmaLoadOverlay(&D_800ABE7C);
            dmaLoadOverlay(&D_800ABE58);
            dmaReadRom(magikarp1_ROM_START, magikarp1_VRAM, magikarp1_ROM_END - magikarp1_ROM_START);
            dmaReadRom(magikarp3_ROM_START, magikarp3_VRAM, magikarp3_ROM_END - magikarp3_ROM_START);
            dmaReadRom(pikachu1_ROM_START, pikachu1_VRAM, pikachu1_ROM_END - pikachu1_ROM_START);
            dmaReadRom(pikachu3_ROM_START, pikachu3_VRAM, pikachu3_ROM_END - pikachu3_ROM_START);
            dmaReadRom(zubat1_ROM_START, zubat1_VRAM, zubat1_ROM_END - zubat1_ROM_START);
            dmaReadRom(zubat3_ROM_START, zubat3_VRAM, zubat3_ROM_END - zubat3_ROM_START);
            break;
        case 4:
            dmaLoadOverlay(&D_800ABEC4);
            dmaLoadOverlay(&D_800ABEA0);
            dmaReadRom(bulbasaur1_ROM_START, bulbasaur1_VRAM, bulbasaur1_ROM_END - bulbasaur1_ROM_START);
            dmaReadRom(bulbasaur3_ROM_START, bulbasaur3_VRAM, bulbasaur3_ROM_END - bulbasaur3_ROM_START);
            dmaReadRom(magikarp1_ROM_START, magikarp1_VRAM, magikarp1_ROM_END - magikarp1_ROM_START);
            dmaReadRom(magikarp3_ROM_START, magikarp3_VRAM, magikarp3_ROM_END - magikarp3_ROM_START);
            dmaReadRom(pikachu1_ROM_START, pikachu1_VRAM, pikachu1_ROM_END - pikachu1_ROM_START);
            dmaReadRom(pikachu3_ROM_START, pikachu3_VRAM, pikachu3_ROM_END - pikachu3_ROM_START);
            dmaReadRom(zubat1_ROM_START, zubat1_VRAM, zubat1_ROM_END - zubat1_ROM_START);
            dmaReadRom(zubat3_ROM_START, zubat3_VRAM, zubat3_ROM_END - zubat3_ROM_START);
            break;
        case 3:
            dmaLoadOverlay(&D_800ABF0C);
            dmaLoadOverlay(&D_800ABEE8);
            dmaReadRom(bulbasaur1_ROM_START, bulbasaur1_VRAM, bulbasaur1_ROM_END - bulbasaur1_ROM_START);
            dmaReadRom(bulbasaur3_ROM_START, bulbasaur3_VRAM, bulbasaur3_ROM_END - bulbasaur3_ROM_START);
            dmaReadRom(magikarp1_ROM_START, magikarp1_VRAM, magikarp1_ROM_END - magikarp1_ROM_START);
            dmaReadRom(magikarp3_ROM_START, magikarp3_VRAM, magikarp3_ROM_END - magikarp3_ROM_START);
            dmaReadRom(pikachu1_ROM_START, pikachu1_VRAM, pikachu1_ROM_END - pikachu1_ROM_START);
            dmaReadRom(pikachu3_ROM_START, pikachu3_VRAM, pikachu3_ROM_END - pikachu3_ROM_START);
            break;
        case 2:
            dmaLoadOverlay(&D_800ABF54);
            dmaLoadOverlay(&D_800ABF30);
            dmaReadRom(magikarp1_ROM_START, magikarp1_VRAM, magikarp1_ROM_END - magikarp1_ROM_START);
            dmaReadRom(magikarp3_ROM_START, magikarp3_VRAM, magikarp3_ROM_END - magikarp3_ROM_START);
            break;
        case 5:
            dmaLoadOverlay(&D_800ABF9C);
            dmaLoadOverlay(&D_800ABF78);
            dmaReadRom(magikarp1_ROM_START, magikarp1_VRAM, magikarp1_ROM_END - magikarp1_ROM_START);
            dmaReadRom(magikarp3_ROM_START, magikarp3_VRAM, magikarp3_ROM_END - magikarp3_ROM_START);
            break;
        case 6:
            dmaLoadOverlay(&D_800ABFE4);
            dmaLoadOverlay(&D_800ABFC0);
            break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/46270/func_8009B2BC.s")

void func_8009B40C(void) {
    s32 i = 0;

    for (i = 0;;) {
        dmaLoadOverlay(&D_800ABDEC);
        dmaLoadOverlay(&D_800ABBD0);
        if (func_801DD010(i) != 0) {
            PANIC();
        }
        i++;
        if (i == 0x11) {
            PANIC();
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/46270/start_scene_manager.s")
