#include "common.h"
#include "ld_addrs.h"

#include "A0BE70.h"
#include "sys/anim.h"

extern s32 D_800E82F4_A0F884;
extern s32 D_800E82F8_A0F888;
extern s32 D_800E82FC_A0F88C;
extern GObj* D_800E82A8_A0F838;
extern GObj* D_800E8300_A0F890;
extern GObj* D_800E8304_A0F894;
extern GObj* D_800E8308_A0F898;
extern GObj* D_800E830C_A0F89C;
extern GObj* D_800E8310_A0F8A0;
extern GObj* D_800E8314_A0F8A4;
extern GObj* D_800E8318_A0F8A8;
extern GObj* D_800E831C_A0F8AC;
extern s32 D_800E8320_A0F8B0;
extern s32 D_800E8324_A0F8B4;
extern u8 D_800E832B_A0F8BB;
extern u32 D_800E832C_A0F8BC;

extern Sprite D_803051F0;
extern Sprite D_803072A0;
extern Sprite D_80308A00;

extern Texture** D_80359378;
extern UnkEC64Arg3 D_80359A20;
extern AnimCmd* D_80359B30;
extern AnimCmd** D_80359CD0;
extern Texture** D_8036A458;
extern UnkEC64Arg3 D_8037F658;
extern AnimCmd* D_80381D60;
extern AnimCmd** D_80385700;
extern UnkEC64Arg3 D_8038F3E0;
extern Texture** D_8038AD40;
extern AnimCmd* D_8038F9C0;
extern AnimCmd** D_80393AE0;
extern UnkEC64Arg3 D_80393D30;
extern AnimCmd* D_80393DC0;
extern Texture** D_8039BC48;
extern UnkEC64Arg3 D_803A1730;
extern AnimCmd* D_803A1BE0;
extern AnimCmd** D_803A7F90;
extern AnimCmd D_803A80D0;

void func_800E48E0_A0BE70(DObj* dobj, u32 arg1, f32 arg2) {
    s32 temp_f8;
    GObj* gobj;

    if (arg1 == -2 || arg1 == -1) {
        D_800E832B_A0F8BB = 3;
        return;
    }

    temp_f8 = arg2 - 1.0f;
    if (temp_f8 >= 0) {
        gobj = func_800A6C48(arg1, temp_f8);
        if (gobj != NULL) {
            gobj->data.dobj = dobj;
        }
    }
}

void func_800E4960_A0BEF0(GObj* gobj) {
    while (TRUE) {
        if (D_800E832B_A0F8BB == 5) {
            if (D_800E832C_A0F8BC >= 3600.0) {
                D_800E832B_A0F8BB = 1;
            } else if (D_800BF051 == 0 && D_800E832C_A0F8BC > 1.0 && gContInputPressedButtons & (A_BUTTON | START_BUTTON)) {
                D_800E832B_A0F8BB = 4;
            }
        }

        if (D_800E832B_A0F8BB == 5) {
            D_800E832C_A0F8BC++;
        } else if (D_800E832B_A0F8BB == 1 || D_800E832B_A0F8BB == 4) {
            break;
        }

        ohWait(1);
    }

    while (TRUE) {
        ohWait(1);
    }
}

void func_800E4AF8_A0C088(void) {
    D_800E831C_A0F8AC = omAddGObj(0xE, ohUpdateDefault, 0, 0x80000000);
    omCreateProcess(D_800E831C_A0F8AC, func_800E4960_A0BEF0, 0, 1);
}

void func_800E4B4C_A0C0DC(GObj* arg0) {
    GObj* gobj = D_800E82A8_A0F838;
    OMCamera* cam = D_800E82A8_A0F838->data.cam;

    D_800E8308_A0F898->fnAnimCallback = func_800E48E0_A0BE70;
    D_800E830C_A0F89C->fnAnimCallback = func_800E48E0_A0BE70;
    cam->animSpeed = 0.5f;
    cam->perspMtx.persp.near = 47.0f;
    animSetCameraAnimation(cam, &D_803A80D0, 0.0f);
    omCreateProcess(gobj, animUpdateCameraAnimation, 1, 1);

    animSetModelTreeAnimation(D_800E8300_A0F890, &D_80381D60, 0.0f);
    animSetModelAnimationSpeed(D_800E8300_A0F890, 0.5f);
    animSetModelTreeTextureAnimation(D_800E8300_A0F890, &D_80385700, 0.0f);
    animSetTextureAnimationSpeed(D_800E8300_A0F890, 0.5f);

    animSetModelTreeAnimation(D_800E8304_A0F894, &D_803A1BE0, 0.0f);
    animSetModelAnimationSpeed(D_800E8304_A0F894, 0.5f);
    animSetModelTreeTextureAnimation(D_800E8304_A0F894, &D_803A7F90, 0.0f);
    animSetTextureAnimationSpeed(D_800E8304_A0F894, 0.5f);

    animSetModelTreeAnimation(D_800E8308_A0F898, &D_80359B30, 0.0f);
    animSetModelAnimationSpeed(D_800E8308_A0F898, 0.5f);
    animSetModelTreeTextureAnimation(D_800E8308_A0F898, &D_80359CD0, 0.0f);
    animSetTextureAnimationSpeed(D_800E8308_A0F898, 0.5f);

    animSetModelTreeAnimation(D_800E830C_A0F89C, &D_8038F9C0, 0.0f);
    animSetModelAnimationSpeed(D_800E830C_A0F89C, 0.5f);
    animSetModelTreeTextureAnimation(D_800E830C_A0F89C, &D_80393AE0, 0.0f);
    animSetTextureAnimationSpeed(D_800E830C_A0F89C, 0.5f);

    animSetModelTreeAnimation(D_800E8310_A0F8A0, &D_80393DC0, 0.0f);
    animSetModelAnimationSpeed(D_800E8310_A0F8A0, 0.5f);

    while (TRUE) {
        ohWait(1);
    }
}

void func_800E4D74_A0C304(void) {
    GObj* gobj;

    gobj = D_800E8300_A0F890 = omAddGObj(0xE, ohUpdateDefault, 0, 0x80000000);
    omLinkGObjDL(gobj, func_800A1608, 4, 0x80000000, -1);
    anim_func_80010230(gobj, &D_8037F658, &D_8036A458, 0, 0x1C, 0, 0);
    func_800A181C(0x78, 0x78, 0x96);
    func_800A18AC(0x3DD, 0x3E8);
    omCreateProcess(gobj, animUpdateModelTreeAnimation, 1, 1);
}

void func_800E4E34_A0C3C4(void) {
    GObj* gobj;

    gobj = D_800E8304_A0F894 = omAddGObj(0xE, ohUpdateDefault, 0, 0x80000000);
    omLinkGObjDL(gobj, func_800A16B0, 4, 0x80000000, -1);
    anim_func_80010230(gobj, &D_803A1730, &D_8039BC48, 0, 0x1C, 0, 0);
    func_800A181C(0x78, 0x78, 0x96);
    func_800A18AC(0x3DD, 0x3E8);
    omCreateProcess(gobj, animUpdateModelTreeAnimation, 1, 1);
}

void func_800E4EF4_A0C484(void) {
    GObj* gobj;

    gobj = D_800E8308_A0F898 = omAddGObj(0xE, ohUpdateDefault, 0, 0x80000000);
    omLinkGObjDL(gobj, func_800A1608, 4, 0x80000000, -1);
    anim_func_80010230(gobj, &D_80359A20, &D_80359378, 0, 0x1C, 0, 0);
    func_800A181C(0x78, 0x78, 0x96);
    func_800A18AC(0x3DD, 0x3E8);
    omCreateProcess(gobj, animUpdateModelTreeAnimation, 1, 1);
}

void func_800E4FB4_A0C544(void) {
    GObj* gobj;

    gobj = D_800E830C_A0F89C = omAddGObj(0xE, ohUpdateDefault, 0, 0x80000000);
    omLinkGObjDL(gobj, func_800A1650, 4, 0x80000000, -1);
    anim_func_80010230(gobj, &D_8038F3E0, &D_8038AD40, 0, 0x1C, 0, 0);
    func_800A181C(0x78, 0x78, 0x96);
    func_800A18AC(0x3DD, 0x3E8);
    omCreateProcess(gobj, animUpdateModelTreeAnimation, 1, 1);
}

void func_800E5074_A0C604(void) {
    GObj* gobj;

    gobj = D_800E8310_A0F8A0 = omAddGObj(0xE, ohUpdateDefault, 0, 0x80000000);
    omLinkGObjDL(gobj, func_800A15D8, 4, 0x80000000, -1);
    anim_func_80010230(gobj, &D_80393D30, NULL, 0, 0x1C, 0, 0);
    func_800A181C(0x78, 0x78, 0x96);
    func_800A18AC(0x3DD, 0x3E8);
    omCreateProcess(gobj, animUpdateModelTreeAnimation, 1, 1);
}

void func_800E5130_A0C6C0(GObj* gobj) {
    SObj* sobj = gobj->userData;
    f32 color;

    sobj->sprite.red = sobj->sprite.green = sobj->sprite.blue = sobj->sprite.alpha = 0;

    sobj->sprite.attr &= ~SP_HIDDEN;;

    for (color = 0.0f; color < 255.0f; color += 8.5f, ohWait(1)) {
        sobj->sprite.red = sobj->sprite.green = sobj->sprite.blue = sobj->sprite.alpha = color;
    }

    ohWait(180);

    for (color = 255.0f; color >= 8.5f; color -= 8.5f, ohWait(1)) {
        sobj->sprite.red = sobj->sprite.green = sobj->sprite.blue = sobj->sprite.alpha = color;
    }

    sobj->sprite.attr |= SP_HIDDEN;
    omEndProcess(NULL);
}

void func_800E5330_A0C8C0(SObj* sobj) {
    omCreateProcess(sobj->obj, func_800E5130_A0C6C0, 0, 1);
    sobj->obj->userData = sobj;
}

void func_800E5370_A0C900(GObj* arg0) {
    SObj* sobj0 = arg0->data.sobj;
    SObj* sobj1 = sobj0->next;
    SObj* sobj2 = sobj1->next;

    sobj0->sprite.attr |= SP_HIDDEN;
    sobj1->sprite.attr |= SP_HIDDEN;
    sobj2->sprite.attr |= SP_HIDDEN;

    while (TRUE) {
        switch (D_800E832C_A0F8BC) {
            case 0xD2:
                func_800E5330_A0C8C0(sobj1);
                break;
            case 0x1E0:
                func_800E5330_A0C8C0(sobj0);
                break;
            case 0x2EE:
                func_800E5330_A0C8C0(sobj2);
                break;
        }
        ohWait(1);
    }
}

void func_800E5468_A0C9F8(void) {
    SObj* sobj;

    D_800E8318_A0F8A8 = ohCreateSprite(0x1F, ohUpdateDefault, 0, 0x80000000, renDrawSprite, 1, 0x80000000, -1,
                             &D_803051F0, 0, func_800E5370_A0C900, 1);

    sobj = D_800E8318_A0F8A8->data.sobj;
    SET_SPRITE_POS(sobj->sprite, 98, 68);
    sobj->sprite.attr = SP_TEXSHUF | SP_TRANSPARENT;
    omGObjAddSprite(D_800E8318_A0F8A8, &D_803072A0);

    sobj = sobj->next;
    SET_SPRITE_POS(sobj->sprite, 96, 103);
    sobj->sprite.attr = SP_TEXSHUF | SP_TRANSPARENT;
    omGObjAddSprite(D_800E8318_A0F8A8, &D_80308A00);

    sobj = sobj->next;
    SET_SPRITE_POS(sobj->sprite, 71, 112);
    sobj->sprite.attr = SP_TEXSHUF | SP_TRANSPARENT;
}

void func_800E5574_A0CB04(GObj*);
#pragma GLOBAL_ASM("asm/nonmatchings/A0BE70/func_800E5574_A0CB04.s")
// void func_800E5574_A0CB04(s32 arg0) {
//     func_800AB9A4();
//     auSetBGMVolume(0, 0x7F00);
//     auSetBGMVolume(1, 0x7F00);

//     while (TRUE) {
//         switch (D_800E832C_A0F8BC) {
//             case 0x1:
//                 auPlaySong(0, 0x19);
//                 auSetBGMVolume(1, 0x1000);
//                 auPlaySong(1, 0x14);
//                 D_800E82F4_A0F884 = auPlaySoundWithParams(0x2C, 0x2000, 0x40, 1.0f, 30);
//                 break;
//             case 0x2:
//                 auSetBGMVolumeSmooth(1, 0x6400, 0x3C);
//                 func_800AB700(D_800E82F4_A0F884, 0x2000, 0x4800, 60);
//                 break;
//             case 0x46:
//                 func_800AB700(D_800E82F4_A0F884, 0x4800, 0x2000, 600);
//                 func_800AB41C(D_800E82F4_A0F884, 0x40, 0, 0x190);
//                 break;
//             case 0x2EE:
//                 auPlaySoundWithParams(0x18, 0x3800, 0, 1.0f, 0);
//                 func_800AB700(D_800E82F4_A0F884, 0x2000, 0x400, 90);
//                 break;
//             case 0x318:
//                 auPlaySoundWithParams(0x18, 0x6800, 0x40, 1.0f, 0);
//                 break;
//             case 0x348:
//                 auPlaySoundWithParams(0x18, 0x3800, 0x7F, 1.0f, 0);
//                 auStopSound(D_800E82F4_A0F884);
//                 break;
//             case 0x370:
//                 auPlaySoundWithParams(0x18, 0x2000, 0x40, 1.0f, 0);
//                 break;
//             case 0x398:
//                 auPlaySoundWithParams(0x18, 0x2000, 0x40, 1.0f, 0);
//                 break;
//             case 0x3C0:
//                 auPlaySoundWithParams(0x18, 0x3800, 0x40, 1.0f, 0);
//                 break;
//             case 0x3E8:
//                 auPlaySoundWithParams(0x18, 0x4000, 0x40, 1.0f, 0);
//                 break;
//             case 0x410:
//                 auPlaySoundWithParams(0x18, 0x3800, 0x40, 1.0f, 0);
//                 break;
//             case 0x438:
//                 auPlaySoundWithParams(0x18, 0x4000, 0x40, 1.0f, 0);
//                 break;
//             case 0x456:
//                 auPlaySoundWithParams(0x18, 0x3000, 0x40, 1.0f, 0);
//                 break;
//             case 0x69A:
//                 D_800E82F8_A0F888 = auPlaySoundWithParams(0x12, 0x6800, 0x14, 1.0f, 0xA);
//                 auSetBGMVolumeSmooth(1, 0, 30);
//                 break;
//             case 0x6A4:
//                 func_800AB41C(D_800E82F8_A0F888, 0x18, 0x5E, 30);
//                 break;
//             case 0x6CC:
//                 D_800E82FC_A0F88C = auPlaySoundWithParams(0x75, 0x3800, 40, 1.0f, 30);
//                 break;
//             case 0x6D6:
//                 func_800AB41C(D_800E82FC_A0F88C, 0x2C, 0x7C, 0x14);
//                 break;
//             case 0x726:
//                 auPlaySoundWithParams(0x12, 0x4000, 0x40, 0.9f, 0x14);
//                 break;
//             case 0x76C:
//             case 0x7A8:
//             case 0x7E4:
//             case 0x85C:
//             case 0x898:
//             case 0x8D4:
//                 auPlaySoundWithParams(0, 0x7FFF, 0x40, 1.0f, 0xA);
//                 break;
//             case 0x910:
//                 D_800E82F8_A0F888 = auPlaySoundWithParams(0x9B, 0x6000, 0x36, 0.7f, 40);
//                 break;
//             case 0x91A:
//                 func_800AB41C(D_800E82F8_A0F888, 0x36, 0xE, 0x28);
//                 break;
//             case 0x942:
//                 auPlaySoundWithParams(0x9B, 0x4800, 0x18, 0.7f, 0x14);
//                 break;
//             case 0x96A:
//                 auPlaySoundWithParams(0x9B, 0x3C00, 0x5E, 1.0f, 30);
//                 break;
//             case 0x992:
//                 auPlaySoundWithParams(0x9B, 0x2C00, 0xE, 0.7f, 30);
//                 break;
//             case 0x9B0:
//                 auPlaySoundWithParams(0x9B, 0x2000, 0x54, 0.68f, 30);
//                 break;
//             case 0x9C4:
//                 auPlaySoundWithParams(0x9B, 0x1800, 0x2C, 0.65f, 40);
//                 break;
//             case 0xAAA:
//                 auSetBGMVolumeSmooth(1, 0x6400, 120);
//                 break;
//             case 0xD56:
//                 auPlaySoundWithParams(0x12, 0x1C00, 0x40, 0.9f, 30);
//                 break;
//         }

//         if (D_800E832B_A0F8BB == 1) {
//             auSetBGMVolumeSmooth(1, 0, 0x78);
//             auSetBGMVolumeSmooth(0, 0, 0x78);
//             break;
//         } else if (D_800E832B_A0F8BB == 4) {
//             auSetBGMVolumeSmooth(1, 0, 30);
//             auSetBGMVolumeSmooth(0, 0, 30);
//             break;
//         }

//         ohWait(1);
//     }

//     ohWait(1);

//     while (TRUE) {
//         ohWait(1);

//     }
// }

void func_800E5C38_A0D1C8(void) {
    D_800E8314_A0F8A4 = omAddGObj(0xE, ohUpdateDefault, 0, 0x80000000);
    omCreateProcess(D_800E8314_A0F8A4, func_800E5574_A0CB04, 0, 1);
}

void func_800E5C8C_A0D21C(void) {
    void* sp1C;
    void* temp_a2;

    sp1C = func_800A73C0((u32) ADEC60_ROM_START, (u32) ADEC60_ROM_END);
    temp_a2 = func_800A73C0((u32) ADEDF0_ROM_START, (u32) ADEDF0_ROM_END);
    if (sp1C != NULL && temp_a2 != NULL) {
        func_800A1ED0(0, sp1C, temp_a2);
    }
    D_800E8320_A0F8B0 = func_800A2094(4, 100, D_800E82A8_A0F838->data.cam);
    D_800E8324_A0F8B4 = func_800A5E08(0xA);
    func_800A5DF4(0xC0, 0x30);
}

void func_800E5D2C_A0D2BC(void) {
    GObj* temp_v0;

    func_800E4D74_A0C304();
    func_800E4E34_A0C3C4();
    func_800E4EF4_A0C484();
    func_800E4FB4_A0C544();
    func_800E5074_A0C604();
    func_800E5468_A0C9F8();
    func_800E5C38_A0D1C8();
    func_800E4AF8_A0C088();
    D_800E832B_A0F8BB = 0;
    D_800E832C_A0F8BC = 0;
    temp_v0 = omAddGObj(0xE, ohUpdateDefault, 0, 0x80000000);
    omCreateProcess(temp_v0, func_800E4B4C_A0C0DC, 0, 1);
    D_800E832B_A0F8BB = 5;
    func_800E1930_A08EC0(0, 0, 0, 0, 1.0f);

    while (D_800E832B_A0F8BB != 1 && D_800E832B_A0F8BB != 4) {
        ohWait(1);
    }

    if (D_800E832B_A0F8BB == 1) {
        func_800AB918(0x5A);
        func_800E1930_A08EC0(1, 0, 0, 0, 1.5f);
        auStopAllSounds();
        auStopBGM();
    } else if (D_800E832B_A0F8BB == 4) {
        func_800AB918(0x1E);
        func_800E1930_A08EC0(1, 0, 0, 0, 0.5f);
        auStopAllSounds();
        auStopBGM();
    }
    omDeleteGObj(D_800E8300_A0F890);
    omDeleteGObj(D_800E8304_A0F894);
    omDeleteGObj(D_800E8308_A0F898);
    omDeleteGObj(D_800E830C_A0F89C);
    omDeleteGObj(D_800E8310_A0F8A0);
    omDeleteGObj(D_800E82A8_A0F838);
    omDeleteGObj(D_800E8318_A0F8A8);
    omDeleteGObj(D_800E8314_A0F8A4);
    omDeleteGObj(D_800E831C_A0F8AC);
    omDeleteGObj(temp_v0);
}
