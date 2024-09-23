#include "common.h"
#include "os_cache.h"
#include "camera_check/camera_check.h"
#include "gallery/gallery.h"
#include "volcano/volcano.h"

#include "ld_addrs.h"

Overlay D_800ABBD0 = OVERLAY(AA18E0);
Overlay overlayWindow = OVERLAY(window);
Overlay overlayCameraCheck = OVERLAY(camera_check);
Overlay overlayOaksLab = OVERLAY(oaks_lab);
Overlay overlayPokemonAlbum = OVERLAY(pokemon_album);
Overlay overlayPokemonReport = OVERLAY(pokemon_report);
Overlay overlayPhotoCheck = OVERLAY(photo_check);
Overlay overlayGallery = OVERLAY(gallery);
Overlay D_800ABCF0 = OVERLAY(unk_end_level_8);
Overlay D_800ABD14 = OVERLAY(more_funcs);
Overlay overlayMainMenu = OVERLAY(main_menu);
Overlay overlayMenuNewGame = OVERLAY(menu_new_game);
Overlay overlayCredits = OVERLAY(credits);
Overlay D_800ABDA4 = OVERLAY(intro_code);
Overlay D_800ABDC8 = OVERLAY(app_level);
Overlay overlayWorld = OVERLAY(world);
Overlay overlayBeachAssets = OVERLAY(beach_assets);
Overlay overlayBeach = OVERLAY(beach_code);
Overlay overlayTunnelAssets = OVERLAY(_162CB0);
Overlay overlayTunnel = OVERLAY(tunnel_code);
Overlay overlayCaveAssets = OVERLAY(_1F5E70);
Overlay overlayCave = OVERLAY(cave_code);
Overlay overlayRiverAssets = OVERLAY(_29A190);
Overlay overlayRiver = OVERLAY(river_code);
Overlay overlayVolcanoAssets = OVERLAY(volcano_assets);
Overlay overlayVolcano = OVERLAY(volcano_code);
Overlay overlayValleyAssets = OVERLAY(_3F63D0);
Overlay overlayValley = OVERLAY(valley_code);
Overlay overlayRainbowAssets = OVERLAY(_4A8160);
Overlay overlayRainbow = OVERLAY(rainbow_code);

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
            dmaLoadOverlay(&overlayBeachAssets);
            dmaReadRom(stage0_extra_ROM_START, stage0_extra_VRAM, stage0_extra_ROM_END - stage0_extra_ROM_START);
            dmaReadRom(magikarp_textures_ROM_START, magikarp_textures_VRAM, magikarp_textures_ROM_END - magikarp_textures_ROM_START);
            dmaReadRom(magikarp2_ROM_START, magikarp2_VRAM, magikarp2_ROM_END - magikarp2_ROM_START);
            dmaReadRom(pikachu1_ROM_START, pikachu1_VRAM, pikachu1_ROM_END - pikachu1_ROM_START);
            dmaReadRom(pikachu2_ROM_START, pikachu2_VRAM, pikachu2_ROM_END - pikachu2_ROM_START);
            return;
        case SCENE_TUNNEL:
            dmaLoadOverlay(&overlayTunnelAssets);
            dmaReadRom(stage1_extra_ROM_START, stage1_extra_VRAM, stage1_extra_ROM_END - stage1_extra_ROM_START);
            dmaReadRom(magikarp_textures_ROM_START, magikarp_textures_VRAM, magikarp_textures_ROM_END - magikarp_textures_ROM_START);
            dmaReadRom(magikarp2_ROM_START, magikarp2_VRAM, magikarp2_ROM_END - magikarp2_ROM_START);
            dmaReadRom(pikachu1_ROM_START, pikachu1_VRAM, pikachu1_ROM_END - pikachu1_ROM_START);
            dmaReadRom(pikachu2_ROM_START, pikachu2_VRAM, pikachu2_ROM_END - pikachu2_ROM_START);
            dmaReadRom(zubat1_ROM_START, zubat1_VRAM, zubat1_ROM_END - zubat1_ROM_START);
            dmaReadRom(zubat2_ROM_START, zubat2_VRAM, zubat2_ROM_END - zubat2_ROM_START);
            break;
        case SCENE_CAVE:
            dmaLoadOverlay(&overlayCaveAssets);
            dmaReadRom(stage4_extra_ROM_START, stage4_extra_VRAM, stage4_extra_ROM_END - stage4_extra_ROM_START);
            dmaReadRom(bulbasaur1_ROM_START, bulbasaur1_VRAM, bulbasaur1_ROM_END - bulbasaur1_ROM_START);
            dmaReadRom(bulbasaur2_ROM_START, bulbasaur2_VRAM, bulbasaur2_ROM_END - bulbasaur2_ROM_START);
            dmaReadRom(magikarp_textures_ROM_START, magikarp_textures_VRAM, magikarp_textures_ROM_END - magikarp_textures_ROM_START);
            dmaReadRom(magikarp2_ROM_START, magikarp2_VRAM, magikarp2_ROM_END - magikarp2_ROM_START);
            dmaReadRom(pikachu1_ROM_START, pikachu1_VRAM, pikachu1_ROM_END - pikachu1_ROM_START);
            dmaReadRom(pikachu2_ROM_START, pikachu2_VRAM, pikachu2_ROM_END - pikachu2_ROM_START);
            dmaReadRom(zubat1_ROM_START, zubat1_VRAM, zubat1_ROM_END - zubat1_ROM_START);
            dmaReadRom(zubat2_ROM_START, zubat2_VRAM, zubat2_ROM_END - zubat2_ROM_START);
            break;
        case SCENE_RIVER:
            dmaLoadOverlay(&overlayRiverAssets);
            dmaReadRom(volcano_extra_ROM_START, volcano_extra_VRAM, volcano_extra_ROM_END - volcano_extra_ROM_START);
            dmaReadRom(bulbasaur1_ROM_START, bulbasaur1_VRAM, bulbasaur1_ROM_END - bulbasaur1_ROM_START);
            dmaReadRom(bulbasaur2_ROM_START, bulbasaur2_VRAM, bulbasaur2_ROM_END - bulbasaur2_ROM_START);
            dmaReadRom(magikarp_textures_ROM_START, magikarp_textures_VRAM, magikarp_textures_ROM_END - magikarp_textures_ROM_START);
            dmaReadRom(magikarp2_ROM_START, magikarp2_VRAM, magikarp2_ROM_END - magikarp2_ROM_START);
            dmaReadRom(pikachu1_ROM_START, pikachu1_VRAM, pikachu1_ROM_END - pikachu1_ROM_START);
            dmaReadRom(pikachu2_ROM_START, pikachu2_VRAM, pikachu2_ROM_END - pikachu2_ROM_START);
            break;
        case SCENE_VOLCANO:
            dmaLoadOverlay(&overlayVolcanoAssets);
            dmaReadRom(stage2_extra_ROM_START, stage2_extra_VRAM, stage2_extra_ROM_END - stage2_extra_ROM_START);
            dmaReadRom(magikarp_textures_ROM_START, magikarp_textures_VRAM, magikarp_textures_ROM_END - magikarp_textures_ROM_START);
            dmaReadRom(magikarp2_ROM_START, magikarp2_VRAM, magikarp2_ROM_END - magikarp2_ROM_START);
            break;
        case SCENE_VALLEY:
            dmaLoadOverlay(&overlayValleyAssets);
            dmaReadRom(stage5_extra_ROM_START, stage5_extra_VRAM, stage5_extra_ROM_END - stage5_extra_ROM_START);
            dmaReadRom(magikarp_textures_ROM_START, magikarp_textures_VRAM, magikarp_textures_ROM_END - magikarp_textures_ROM_START);
            dmaReadRom(magikarp2_ROM_START, magikarp2_VRAM, magikarp2_ROM_END - magikarp2_ROM_START);
            break;
        case SCENE_RAINBOW:
            dmaLoadOverlay(&overlayRainbowAssets);
            dmaReadRom(stage6_extra_ROM_START, stage6_extra_VRAM, stage6_extra_ROM_END - stage6_extra_ROM_START);
            break;
    }
}

void func_8009AE0C(u32 sceneId) {
    dmaLoadOverlay(&overlayWorld);
    dmaLoadOverlay(&D_800ABDC8);
    switch (sceneId) {
        case SCENE_BEACH:
            dmaLoadOverlay(&overlayBeach);
            dmaLoadOverlay(&overlayBeachAssets);
            dmaReadRom(magikarp_textures_ROM_START, magikarp_textures_VRAM, magikarp_textures_ROM_END - magikarp_textures_ROM_START);
            dmaReadRom(magikarp_model_ROM_START, magikarp_model_VRAM, magikarp_model_ROM_END - magikarp_model_ROM_START);
            dmaReadRom(pikachu1_ROM_START, pikachu1_VRAM, pikachu1_ROM_END - pikachu1_ROM_START);
            dmaReadRom(pikachu3_ROM_START, pikachu3_VRAM, pikachu3_ROM_END - pikachu3_ROM_START);
            break;
        case SCENE_TUNNEL:
            dmaLoadOverlay(&overlayTunnel);
            dmaLoadOverlay(&overlayTunnelAssets);
            dmaReadRom(magikarp_textures_ROM_START, magikarp_textures_VRAM, magikarp_textures_ROM_END - magikarp_textures_ROM_START);
            dmaReadRom(magikarp_model_ROM_START, magikarp_model_VRAM, magikarp_model_ROM_END - magikarp_model_ROM_START);
            dmaReadRom(pikachu1_ROM_START, pikachu1_VRAM, pikachu1_ROM_END - pikachu1_ROM_START);
            dmaReadRom(pikachu3_ROM_START, pikachu3_VRAM, pikachu3_ROM_END - pikachu3_ROM_START);
            dmaReadRom(zubat1_ROM_START, zubat1_VRAM, zubat1_ROM_END - zubat1_ROM_START);
            dmaReadRom(zubat3_ROM_START, zubat3_VRAM, zubat3_ROM_END - zubat3_ROM_START);
            break;
        case SCENE_CAVE:
            dmaLoadOverlay(&overlayCave);
            dmaLoadOverlay(&overlayCaveAssets);
            dmaReadRom(bulbasaur1_ROM_START, bulbasaur1_VRAM, bulbasaur1_ROM_END - bulbasaur1_ROM_START);
            dmaReadRom(bulbasaur3_ROM_START, bulbasaur3_VRAM, bulbasaur3_ROM_END - bulbasaur3_ROM_START);
            dmaReadRom(magikarp_textures_ROM_START, magikarp_textures_VRAM, magikarp_textures_ROM_END - magikarp_textures_ROM_START);
            dmaReadRom(magikarp_model_ROM_START, magikarp_model_VRAM, magikarp_model_ROM_END - magikarp_model_ROM_START);
            dmaReadRom(pikachu1_ROM_START, pikachu1_VRAM, pikachu1_ROM_END - pikachu1_ROM_START);
            dmaReadRom(pikachu3_ROM_START, pikachu3_VRAM, pikachu3_ROM_END - pikachu3_ROM_START);
            dmaReadRom(zubat1_ROM_START, zubat1_VRAM, zubat1_ROM_END - zubat1_ROM_START);
            dmaReadRom(zubat3_ROM_START, zubat3_VRAM, zubat3_ROM_END - zubat3_ROM_START);
            break;
        case SCENE_RIVER:
            dmaLoadOverlay(&overlayRiver);
            dmaLoadOverlay(&overlayRiverAssets);
            dmaReadRom(bulbasaur1_ROM_START, bulbasaur1_VRAM, bulbasaur1_ROM_END - bulbasaur1_ROM_START);
            dmaReadRom(bulbasaur3_ROM_START, bulbasaur3_VRAM, bulbasaur3_ROM_END - bulbasaur3_ROM_START);
            dmaReadRom(magikarp_textures_ROM_START, magikarp_textures_VRAM, magikarp_textures_ROM_END - magikarp_textures_ROM_START);
            dmaReadRom(magikarp_model_ROM_START, magikarp_model_VRAM, magikarp_model_ROM_END - magikarp_model_ROM_START);
            dmaReadRom(pikachu1_ROM_START, pikachu1_VRAM, pikachu1_ROM_END - pikachu1_ROM_START);
            dmaReadRom(pikachu3_ROM_START, pikachu3_VRAM, pikachu3_ROM_END - pikachu3_ROM_START);
            break;
        case SCENE_VOLCANO:
            dmaLoadOverlay(&overlayVolcano);
            dmaLoadOverlay(&overlayVolcanoAssets);
            dmaReadRom(magikarp_textures_ROM_START, magikarp_textures_VRAM, magikarp_textures_ROM_END - magikarp_textures_ROM_START);
            dmaReadRom(magikarp_model_ROM_START, magikarp_model_VRAM, magikarp_model_ROM_END - magikarp_model_ROM_START);
            break;
        case SCENE_VALLEY:
            dmaLoadOverlay(&overlayValley);
            dmaLoadOverlay(&overlayValleyAssets);
            dmaReadRom(magikarp_textures_ROM_START, magikarp_textures_VRAM, magikarp_textures_ROM_END - magikarp_textures_ROM_START);
            dmaReadRom(magikarp_model_ROM_START, magikarp_model_VRAM, magikarp_model_ROM_END - magikarp_model_ROM_START);
            break;
        case SCENE_RAINBOW:
            dmaLoadOverlay(&overlayRainbow);
            dmaLoadOverlay(&overlayRainbowAssets);
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
        dmaLoadOverlay(&overlayWorld);
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
    dmaReadVPK0((u32*) AA0B80_ROM_START, VPK_VRAM);
    func_800E1C5C_AA0A0C();
    if (func_8009B2BC() == 0) {
        func_8009B40C();
    }
    auSetSoundQuality(checkPlayerFlag(PFID_9) == 0);
    func_800BFC18_5CAB8(&sp38, &sp34);
    viSetScreenOffsets(sp38, sp38, sp34, sp34);

    sceneId = SCENE_MAIN_MENU;

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
                sceneId = volcano_Start(sceneId);
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
                dmaLoadOverlay(&overlayWindow);
                dmaLoadOverlay(&overlayCameraCheck);
                sceneId = func_camera_check_801DCACC(sceneId);
                break;
            case SCENE_OAKS_LAB:
            case SCENE_OAKS_LAB_2:
                func_800AAF20();
                dmaLoadOverlay(&overlayWorld);
                dmaLoadOverlay(&overlayWindow);
                dmaLoadOverlay(&overlayOaksLab);
                sceneId = func_oaks_lab_800E1AD8(sceneId);
                break;
            case SCENE_ALBUM:
                func_800AAF20();
                dmaLoadOverlay(&overlayWorld);
                dmaLoadOverlay(&overlayWindow);
                dmaLoadOverlay(&overlayPokemonAlbum);
                sceneId = func_801DCCA0_9A6EF0(sceneId);
                break;
            case SCENE_REPORT:
                func_800AAF20();
                dmaLoadOverlay(&overlayWorld);
                dmaLoadOverlay(&overlayWindow);
                dmaLoadOverlay(&overlayPokemonReport);
                sceneId = func_801DCC74_9D35E4(sceneId);
                break;
            case SCENE_PHOTO_CHECK:
                func_800AAF20();
                dmaLoadOverlay(&overlayWindow);
                dmaLoadOverlay(&overlayPhotoCheck);
                sceneId = func_801DCC74_98C6E4(sceneId);
                break;
            case SCENE_GALLERY:
                func_800AAF20();
            case SCENE_GALLERY_2:
                dmaLoadOverlay(&overlayWorld);
                dmaLoadOverlay(&overlayWindow);
                dmaLoadOverlay(&overlayGallery);
                sceneId = func_801DCEBC_9FAB7C(sceneId);
                break;
            case SCENE_24:
                dmaLoadOverlay(&overlayWorld);
                dmaLoadOverlay(&overlayWindow);
                dmaLoadOverlay(&D_800ABCF0);
                sceneId = func_801DD09C_A08C8C(sceneId);
                break;
            case SCENE_CREDITS_17:
            case SCENE_CREDITS_18:
            case SCENE_CREDITS_19:
            case SCENE_CREDITS_20:
                func_800AAF20();
                dmaLoadOverlay(&overlayWorld);
                dmaLoadOverlay(&overlayWindow);
                dmaLoadOverlay(&overlayCredits);
                sceneId = func_credits_801DCB24(sceneId);
                break;
            case SCENE_MAIN_MENU:
                setLevelId(SCENE_BEACH);
                func_800AAF20();
                dmaReadVPK0((u32*) A0F830_ROM_START, VPK_VRAM);
                dmaLoadOverlay(&overlayMainMenu);
                sceneId = func_800E4830_A0BDC0(sceneId);
                if (sceneId == SCENE_BEACH) {
                    dmaLoadOverlay(&overlayWorld);
                    dmaLoadOverlay(&overlayWindow);
                    dmaLoadOverlay(&overlayMenuNewGame);
                    sceneId = menu_new_game_entry(sceneId);
                }
                func_8009A8D8(0);
                break;
        }
    }
}
