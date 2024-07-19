#include "common.h"
#include "os_cache.h"
#include "camera_check/camera_check.h"
#include "unk_end_level_7/unk_end_level_7.h"

#include "ld_addrs.h"

Overlay D_800ABBD0 = OVERLAY(AA18E0);
Overlay D_800ABBF4 = OVERLAY(unk_end_level);
Overlay D_800ABC18 = OVERLAY(camera_check);
Overlay D_800ABC3C = OVERLAY(unk_end_level_3);
Overlay D_800ABC60 = OVERLAY(unk_end_level_5);
Overlay D_800ABC84 = OVERLAY(unk_end_level_6);
Overlay D_800ABCA8 = OVERLAY(photo_check);
Overlay D_800ABCCC = OVERLAY(unk_end_level_7);
Overlay D_800ABCF0 = OVERLAY(unk_end_level_8);
Overlay D_800ABD14 = OVERLAY(more_funcs);
Overlay D_800ABD38 = OVERLAY(unk_level_end_9);
Overlay overlayMenuNewGame = OVERLAY(menu_new_game);
Overlay overlayCredits = OVERLAY(credits);
Overlay D_800ABDA4 = OVERLAY(intro_code);
Overlay D_800ABDC8 = OVERLAY(app_level);
Overlay D_800ABDEC = OVERLAY(world);
Overlay D_800ABE10 = OVERLAY(A74E0);
Overlay D_800ABE34 = OVERLAY(beach_code);
Overlay D_800ABE58 = OVERLAY(_162CB0);
Overlay D_800ABE7C = OVERLAY(tunnel_code);
Overlay D_800ABEA0 = OVERLAY(_1F5E70);
Overlay D_800ABEC4 = OVERLAY(cave_code);
Overlay D_800ABEE8 = OVERLAY(_29A190);
Overlay D_800ABF0C = OVERLAY(river_code);
Overlay D_800ABF30 = OVERLAY(_326C10);
Overlay D_800ABF54 = OVERLAY(volcano_code);
Overlay D_800ABF78 = OVERLAY(_3F63D0);
Overlay D_800ABF9C = OVERLAY(valley_code);
Overlay D_800ABFC0 = OVERLAY(_4A8160);
Overlay D_800ABFE4 = OVERLAY(rainbow_code);

static s32 padding2[1] = { 0 };
s32 D_800AC00C = 0;
s32 D_800AC010 = 0;

extern IdleScript* D_800B0578;

void setIdleScript(IdleScript* arg0) {
    D_800B0578 = arg0;
}

IdleScript* getIdleScript(void) {
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
        case SCENE_BEACH:
            dmaLoadOverlay(&D_800ABE10);
            dmaReadRom(stage0_extra_ROM_START, stage0_extra_VRAM, stage0_extra_ROM_END - stage0_extra_ROM_START);
            dmaReadRom(magikarp1_ROM_START, magikarp1_VRAM, magikarp1_ROM_END - magikarp1_ROM_START);
            dmaReadRom(magikarp2_ROM_START, magikarp2_VRAM, magikarp2_ROM_END - magikarp2_ROM_START);
            dmaReadRom(pikachu1_ROM_START, pikachu1_VRAM, pikachu1_ROM_END - pikachu1_ROM_START);
            dmaReadRom(pikachu2_ROM_START, pikachu2_VRAM, pikachu2_ROM_END - pikachu2_ROM_START);
            return;
        case SCENE_TUNNEL:
            dmaLoadOverlay(&D_800ABE58);
            dmaReadRom(stage1_extra_ROM_START, stage1_extra_VRAM, stage1_extra_ROM_END - stage1_extra_ROM_START);
            dmaReadRom(magikarp1_ROM_START, magikarp1_VRAM, magikarp1_ROM_END - magikarp1_ROM_START);
            dmaReadRom(magikarp2_ROM_START, magikarp2_VRAM, magikarp2_ROM_END - magikarp2_ROM_START);
            dmaReadRom(pikachu1_ROM_START, pikachu1_VRAM, pikachu1_ROM_END - pikachu1_ROM_START);
            dmaReadRom(pikachu2_ROM_START, pikachu2_VRAM, pikachu2_ROM_END - pikachu2_ROM_START);
            dmaReadRom(zubat1_ROM_START, zubat1_VRAM, zubat1_ROM_END - zubat1_ROM_START);
            dmaReadRom(zubat2_ROM_START, zubat2_VRAM, zubat2_ROM_END - zubat2_ROM_START);
            break;
        case SCENE_CAVE:
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
        case SCENE_RIVER:
            dmaLoadOverlay(&D_800ABEE8);
            dmaReadRom(stage3_extra_ROM_START, stage3_extra_VRAM, stage3_extra_ROM_END - stage3_extra_ROM_START);
            dmaReadRom(bulbasaur1_ROM_START, bulbasaur1_VRAM, bulbasaur1_ROM_END - bulbasaur1_ROM_START);
            dmaReadRom(bulbasaur2_ROM_START, bulbasaur2_VRAM, bulbasaur2_ROM_END - bulbasaur2_ROM_START);
            dmaReadRom(magikarp1_ROM_START, magikarp1_VRAM, magikarp1_ROM_END - magikarp1_ROM_START);
            dmaReadRom(magikarp2_ROM_START, magikarp2_VRAM, magikarp2_ROM_END - magikarp2_ROM_START);
            dmaReadRom(pikachu1_ROM_START, pikachu1_VRAM, pikachu1_ROM_END - pikachu1_ROM_START);
            dmaReadRom(pikachu2_ROM_START, pikachu2_VRAM, pikachu2_ROM_END - pikachu2_ROM_START);
            break;
        case SCENE_VOLCANO:
            dmaLoadOverlay(&D_800ABF30);
            dmaReadRom(stage2_extra_ROM_START, stage2_extra_VRAM, stage2_extra_ROM_END - stage2_extra_ROM_START);
            dmaReadRom(magikarp1_ROM_START, magikarp1_VRAM, magikarp1_ROM_END - magikarp1_ROM_START);
            dmaReadRom(magikarp2_ROM_START, magikarp2_VRAM, magikarp2_ROM_END - magikarp2_ROM_START);
            break;
        case SCENE_VALLEY:
            dmaLoadOverlay(&D_800ABF78);
            dmaReadRom(stage5_extra_ROM_START, stage5_extra_VRAM, stage5_extra_ROM_END - stage5_extra_ROM_START);
            dmaReadRom(magikarp1_ROM_START, magikarp1_VRAM, magikarp1_ROM_END - magikarp1_ROM_START);
            dmaReadRom(magikarp2_ROM_START, magikarp2_VRAM, magikarp2_ROM_END - magikarp2_ROM_START);
            break;
        case SCENE_RAINBOW:
            dmaLoadOverlay(&D_800ABFC0);
            dmaReadRom(stage6_extra_ROM_START, stage6_extra_VRAM, stage6_extra_ROM_END - stage6_extra_ROM_START);
            break;
    }
}

void func_8009AE0C(u32 sceneId) {
    dmaLoadOverlay(&D_800ABDEC);
    dmaLoadOverlay(&D_800ABDC8);
    switch (sceneId) {
        case SCENE_BEACH:
            dmaLoadOverlay(&D_800ABE34);
            dmaLoadOverlay(&D_800ABE10);
            dmaReadRom(magikarp1_ROM_START, magikarp1_VRAM, magikarp1_ROM_END - magikarp1_ROM_START);
            dmaReadRom(magikarp3_ROM_START, magikarp3_VRAM, magikarp3_ROM_END - magikarp3_ROM_START);
            dmaReadRom(pikachu1_ROM_START, pikachu1_VRAM, pikachu1_ROM_END - pikachu1_ROM_START);
            dmaReadRom(pikachu3_ROM_START, pikachu3_VRAM, pikachu3_ROM_END - pikachu3_ROM_START);
            break;
        case SCENE_TUNNEL:
            dmaLoadOverlay(&D_800ABE7C);
            dmaLoadOverlay(&D_800ABE58);
            dmaReadRom(magikarp1_ROM_START, magikarp1_VRAM, magikarp1_ROM_END - magikarp1_ROM_START);
            dmaReadRom(magikarp3_ROM_START, magikarp3_VRAM, magikarp3_ROM_END - magikarp3_ROM_START);
            dmaReadRom(pikachu1_ROM_START, pikachu1_VRAM, pikachu1_ROM_END - pikachu1_ROM_START);
            dmaReadRom(pikachu3_ROM_START, pikachu3_VRAM, pikachu3_ROM_END - pikachu3_ROM_START);
            dmaReadRom(zubat1_ROM_START, zubat1_VRAM, zubat1_ROM_END - zubat1_ROM_START);
            dmaReadRom(zubat3_ROM_START, zubat3_VRAM, zubat3_ROM_END - zubat3_ROM_START);
            break;
        case SCENE_CAVE:
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
        case SCENE_RIVER:
            dmaLoadOverlay(&D_800ABF0C);
            dmaLoadOverlay(&D_800ABEE8);
            dmaReadRom(bulbasaur1_ROM_START, bulbasaur1_VRAM, bulbasaur1_ROM_END - bulbasaur1_ROM_START);
            dmaReadRom(bulbasaur3_ROM_START, bulbasaur3_VRAM, bulbasaur3_ROM_END - bulbasaur3_ROM_START);
            dmaReadRom(magikarp1_ROM_START, magikarp1_VRAM, magikarp1_ROM_END - magikarp1_ROM_START);
            dmaReadRom(magikarp3_ROM_START, magikarp3_VRAM, magikarp3_ROM_END - magikarp3_ROM_START);
            dmaReadRom(pikachu1_ROM_START, pikachu1_VRAM, pikachu1_ROM_END - pikachu1_ROM_START);
            dmaReadRom(pikachu3_ROM_START, pikachu3_VRAM, pikachu3_ROM_END - pikachu3_ROM_START);
            break;
        case SCENE_VOLCANO:
            dmaLoadOverlay(&D_800ABF54);
            dmaLoadOverlay(&D_800ABF30);
            dmaReadRom(magikarp1_ROM_START, magikarp1_VRAM, magikarp1_ROM_END - magikarp1_ROM_START);
            dmaReadRom(magikarp3_ROM_START, magikarp3_VRAM, magikarp3_ROM_END - magikarp3_ROM_START);
            break;
        case SCENE_VALLEY:
            dmaLoadOverlay(&D_800ABF9C);
            dmaLoadOverlay(&D_800ABF78);
            dmaReadRom(magikarp1_ROM_START, magikarp1_VRAM, magikarp1_ROM_END - magikarp1_ROM_START);
            dmaReadRom(magikarp3_ROM_START, magikarp3_VRAM, magikarp3_ROM_END - magikarp3_ROM_START);
            break;
        case SCENE_RAINBOW:
            dmaLoadOverlay(&D_800ABFE4);
            dmaLoadOverlay(&D_800ABFC0);
            break;
    }
}

#if 0
s32 func_8009B2BC(void) {
    s32 i;
    u32* VRAM_START = (u32*)0x80400000;

    if (!contIsPrinterAvailable()) {
        return -3;
    }

    osWritebackDCache(VRAM_START, 0x400000);
    for (i = 0; i < 0x100000 - 4; i++) {
        VRAM_START[i] = 0x55555555;
    }
    osInvalDCache(VRAM_START, 0x400000);
    for (i = 0; i < 0x100000 - 4; i++) {
        if (VRAM_START[i] != 0x55555555) {
            return -1;
        }
    }

    osWritebackDCache(VRAM_START, 0x400000);
    for (i = 0; i < 0x100000 - 4; i++) {
        VRAM_START[i] = 0xAAAAAAAA;
    }
    osInvalDCache(VRAM_START, 0x400000);
    for (i = 0; i < 0x100000 - 4; i++) {
        if (VRAM_START[i] != 0xAAAAAAAA) {
            return -1;
        }
    }

    return 0;
}
#endif
s32 func_8009B2BC(void);
#pragma GLOBAL_ASM("asm/nonmatchings/app_render/46270/func_8009B2BC.s")

void func_8009B40C(void) {
    s32 i;

    for (i = 0; i < 0x11; i++) {
        dmaLoadOverlay(&D_800ABDEC);
        dmaLoadOverlay(&D_800ABBD0);
        if (func_801DD010_AA2050(i) != 0) {
            PANIC();
        }
    }

    PANIC();
}

void start_scene_manager(s32 arg0) {
    u32 sceneId;
    s32 sp38;
    s32 sp34;

    auSetReverbType(AL_FX_CUSTOM);
    func_800AAF20();
    dmaLoadOverlay(&D_800ABD14);
    dmaLoadOverlay(&D_800ABDA4);
    dmaReadVPK((u32*) AA0B80_ROM_START, VPK_VRAM);
    func_800E1C5C_AA0A0C();
    if (func_8009B2BC() == 0) {
        func_8009B40C();
    }
    auSetSoundQuality(checkPlayerFlag(PFID_9) == 0);
    func_800BFC18_5CAB8(&sp38, &sp34);
    viSetScreenOffsets(sp38, sp38, sp34, sp34);

    sceneId = SCENE_8;

    while (true) {
        gtlSetIntervals(1, 1);
        setIdleScript(NULL);

        switch (sceneId) {
            case SCENE_7:
            case SCENE_10:
            case SCENE_16:
                break;
            case SCENE_21:
                func_800AAF20();
                func_8009A8D8(1);
                sceneId = D_800AC010 == 0 ? SCENE_BEACH : SCENE_TUNNEL;
                D_800AC010 = (D_800AC010 + 1) % 2;
                break;
            case SCENE_BEACH:
                func_800AAF20();
                func_8009AE0C(SCENE_BEACH);
                setLevelId(SCENE_BEACH);
                sceneId = func_beach_802C4740(sceneId);
                break;
            case SCENE_TUNNEL:
                func_800AAF20();
                func_8009AE0C(SCENE_TUNNEL);
                setLevelId(SCENE_TUNNEL);
                sceneId = func_802E2BB8_5DFC88(sceneId);
                break;
            case SCENE_CAVE:
                func_800AAF20();
                func_8009AE0C(SCENE_CAVE);
                setLevelId(SCENE_CAVE);
                sceneId = func_802BE3B0_640860(sceneId);
                break;
            case SCENE_RIVER:
                func_800AAF20();
                func_8009AE0C(SCENE_RIVER);
                setLevelId(SCENE_RIVER);
                sceneId = func_802D9210_6C0FF0(sceneId);
                break;
            case SCENE_VOLCANO:
                func_800AAF20();
                func_8009AE0C(SCENE_VOLCANO);
                setLevelId(SCENE_VOLCANO);
                sceneId = func_802D67C4_7279C4(sceneId);
                break;
            case SCENE_VALLEY:
                func_800AAF20();
                func_8009AE0C(SCENE_VALLEY);
                setLevelId(SCENE_VALLEY);
                sceneId = func_802C6544_79FAD4(sceneId);
                break;
            case SCENE_RAINBOW:
                func_800AAF20();
                func_8009AE0C(SCENE_RAINBOW);
                setLevelId(SCENE_RAINBOW);
                sceneId = func_80346EF0_826660(sceneId);
                break;
            case SCENE_CAMERA_CHECK:
                func_800AAF20();
                dmaLoadOverlay(&D_800ABBF4);
                dmaLoadOverlay(&D_800ABC18);
                sceneId = func_camera_check_801DCACC(sceneId);
                break;
            case SCENE_11:
            case SCENE_13:
                func_800AAF20();
                dmaLoadOverlay(&D_800ABDEC);
                dmaLoadOverlay(&D_800ABBF4);
                dmaLoadOverlay(&D_800ABC3C);
                sceneId = func_oaks_lab_800E1AD8(sceneId);
                break;
            case SCENE_12:
                func_800AAF20();
                dmaLoadOverlay(&D_800ABDEC);
                dmaLoadOverlay(&D_800ABBF4);
                dmaLoadOverlay(&D_800ABC60);
                sceneId = func_801DCCA0_9A6EF0(sceneId);
                break;
            case SCENE_14:
                func_800AAF20();
                dmaLoadOverlay(&D_800ABDEC);
                dmaLoadOverlay(&D_800ABBF4);
                dmaLoadOverlay(&D_800ABC84);
                sceneId = func_801DCC74_9D35E4(sceneId);
                break;
            case SCENE_15:
                func_800AAF20();
                dmaLoadOverlay(&D_800ABBF4);
                dmaLoadOverlay(&D_800ABCA8);
                sceneId = func_801DCC74_98C6E4(sceneId);
                break;
            case SCENE_22:
                func_800AAF20();
            case SCENE_23:
                dmaLoadOverlay(&D_800ABDEC);
                dmaLoadOverlay(&D_800ABBF4);
                dmaLoadOverlay(&D_800ABCCC);
                sceneId = func_801DCEBC_9FAB7C(sceneId);
                break;
            case SCENE_24:
                dmaLoadOverlay(&D_800ABDEC);
                dmaLoadOverlay(&D_800ABBF4);
                dmaLoadOverlay(&D_800ABCF0);
                sceneId = func_801DD09C_A08C8C(sceneId);
                break;
            case SCENE_CREDITS_17:
            case SCENE_CREDITS_18:
            case SCENE_CREDITS_19:
            case SCENE_CREDITS_20:
                func_800AAF20();
                dmaLoadOverlay(&D_800ABDEC);
                dmaLoadOverlay(&D_800ABBF4);
                dmaLoadOverlay(&overlayCredits);
                sceneId = func_credits_801DCB24(sceneId);
                break;
            case SCENE_8:
                setLevelId(SCENE_BEACH);
                func_800AAF20();
                dmaReadVPK((u32*) A0F830_ROM_START, VPK_VRAM);
                dmaLoadOverlay(&D_800ABD38);
                sceneId = func_800E4830_A0BDC0(sceneId);
                if (sceneId == SCENE_BEACH) {
                    dmaLoadOverlay(&D_800ABDEC);
                    dmaLoadOverlay(&D_800ABBF4);
                    dmaLoadOverlay(&overlayMenuNewGame);
                    sceneId = menu_new_game_entry(sceneId);
                }
                func_8009A8D8(0);
                break;
        }
    }
}
