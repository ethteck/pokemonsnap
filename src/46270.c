#include "common.h"
#include "os_cache.h"
#include "camera_check/camera_check.h"

#include "ld_addrs.h"

extern Overlay D_800ABBD0;
extern Overlay D_800ABC18;
extern Overlay D_800ABC3C;
extern Overlay D_800ABC60;
extern Overlay D_800ABC84;
extern Overlay D_800ABCA8;
extern Overlay D_800ABCCC;
extern Overlay D_800ABCF0;
extern Overlay D_800ABD14;
extern Overlay D_800ABD38;
extern Overlay D_800ABD5C;
extern Overlay D_800ABD80;
extern Overlay D_800ABDA4;
extern Overlay D_800ABDC8;
extern Overlay D_800ABDEC;
extern Overlay D_800ABBF4;
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
extern s32 D_800AC010;
extern s32 D_800B0578;

#define VPK_VRAM 0x802B5000 // TODO SHIFT hard-coded VRAM

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

s32 func_8009B2BC(void);
#pragma GLOBAL_ASM("asm/nonmatchings/46270/func_8009B2BC.s")

void func_8009B40C(void) {
    s32 i;

    for (i = 0; i < 0x11; i++) {
        dmaLoadOverlay(&D_800ABDEC);
        dmaLoadOverlay(&D_800ABBD0);
        if (func_801DD010(i) != 0) {
            PANIC();
        }
    }

    PANIC();
}

void start_scene_manager(s32 arg0) {
    u32 var_s0;
    s32 sp38;
    s32 sp34;

    func_80022300(6);
    func_800AAF20();
    dmaLoadOverlay(&D_800ABD14);
    dmaLoadOverlay(&D_800ABDA4);
    dmaReadVPK((u32*) AA0B80_ROM_START, VPK_VRAM);
    func_800E1C5C_AA0A0C();
    if (func_8009B2BC() == 0) {
        func_8009B40C();
    }
    func_800222F4(func_800BFCA0_5CB40(9) == 0);
    func_800BFC18_5CAB8(&sp38, &sp34);
    viSetScreenOffsets(sp38, sp38, sp34, sp34);

    var_s0 = 8;

    while (TRUE) {
        gtlSetIntervals(1, 1);
        func_8009A8C0(0);

        switch (var_s0) {
            case 7:
            case 10:
            case 16:
                break;
            case 21:
                func_800AAF20();
                func_8009A8D8(1);
                var_s0 = D_800AC010 == 0 ? 0 : 1;
                D_800AC010 = (D_800AC010 + 1) % 2;
                break;
            case 0:
                func_800AAF20();
                func_8009AE0C(0);
                setLevelId(0);
                var_s0 = func_802C4740_55C7B0(var_s0);
                break;
            case 1:
                func_800AAF20();
                func_8009AE0C(1);
                setLevelId(1);
                var_s0 = func_802E2BB8_5DFC88(var_s0);
                break;
            case 4:
                func_800AAF20();
                func_8009AE0C(4);
                setLevelId(4);
                var_s0 = func_802BE3B0_640860(var_s0);
                break;
            case 3:
                func_800AAF20();
                func_8009AE0C(3);
                setLevelId(3);
                var_s0 = func_802D9210_6C0FF0(var_s0);
                break;
            case 2:
                func_800AAF20();
                func_8009AE0C(2);
                setLevelId(2);
                var_s0 = func_802D67C4_7279C4(var_s0);
                break;
            case 5:
                func_800AAF20();
                func_8009AE0C(5);
                setLevelId(5);
                var_s0 = func_802C6544_79FAD4(var_s0);
                break;
            case 6:
                func_800AAF20();
                func_8009AE0C(6);
                setLevelId(6);
                var_s0 = func_80346EF0_826660(var_s0);
                break;
            case 9:
                func_800AAF20();
                dmaLoadOverlay(&D_800ABBF4);
                dmaLoadOverlay(&D_800ABC18);
                var_s0 = func_camera_check_801DCACC(var_s0);
                break;
            case 11:
            case 13:
                func_800AAF20();
                dmaLoadOverlay(&D_800ABDEC);
                dmaLoadOverlay(&D_800ABBF4);
                dmaLoadOverlay(&D_800ABC3C);
                var_s0 = func_800E1AD8_8A72F8(var_s0);
                break;
            case 12:
                func_800AAF20();
                dmaLoadOverlay(&D_800ABDEC);
                dmaLoadOverlay(&D_800ABBF4);
                dmaLoadOverlay(&D_800ABC60);
                var_s0 = func_801DCCA0_9A6EF0(var_s0);
                break;
            case 14:
                func_800AAF20();
                dmaLoadOverlay(&D_800ABDEC);
                dmaLoadOverlay(&D_800ABBF4);
                dmaLoadOverlay(&D_800ABC84);
                var_s0 = func_801DCC74_9D35E4(var_s0);
                break;
            case 15:
                func_800AAF20();
                dmaLoadOverlay(&D_800ABBF4);
                dmaLoadOverlay(&D_800ABCA8);
                var_s0 = func_801DCC74_98C6E4(var_s0);
                break;
            case 22:
                func_800AAF20();
            case 23:
                dmaLoadOverlay(&D_800ABDEC);
                dmaLoadOverlay(&D_800ABBF4);
                dmaLoadOverlay(&D_800ABCCC);
                var_s0 = func_801DCEBC_9FAB7C(var_s0);
                break;
            case 24:
                dmaLoadOverlay(&D_800ABDEC);
                dmaLoadOverlay(&D_800ABBF4);
                dmaLoadOverlay(&D_800ABCF0);
                var_s0 = func_801DD09C_A08C8C(var_s0);
                break;
            case 17:
            case 18:
            case 19:
            case 20:
                func_800AAF20();
                dmaLoadOverlay(&D_800ABDEC);
                dmaLoadOverlay(&D_800ABBF4);
                dmaLoadOverlay(&D_800ABD80);
                var_s0 = func_801DCB24_A936E4(var_s0);
                break;
            case 8:
                setLevelId(0);
                func_800AAF20();
                dmaReadVPK((u32*) A0F830_ROM_START, VPK_VRAM);
                dmaLoadOverlay(&D_800ABD38);
                var_s0 = func_800E4830_A0BDC0(var_s0);
                if (var_s0 == 0) {
                    dmaLoadOverlay(&D_800ABDEC);
                    dmaLoadOverlay(&D_800ABBF4);
                    dmaLoadOverlay(&D_800ABD5C);
                    var_s0 = func_800E218C_A5D53C(var_s0);
                }
                func_8009A8D8(0);
                break;
        }
    }
}
