#include "common.h"

#include "main_menu.h"

extern GObj* D_800E8334_A0F8C4;
extern GObj* D_800E8338_A0F8C8;
extern GObj* D_800E833C_A0F8CC;
extern GObj* D_800E8340_A0F8D0;
extern GObj* D_800E8344_A0F8D4;
extern GObj* D_800E8348_A0F8D8;
extern GObj* D_800E834C_A0F8DC;
extern GObj* D_800E8350_A0F8E0;
extern GObj* D_800E8354_A0F8E4;
extern GObj* D_800E8358_A0F8E8;
extern GObj* D_800E835C_A0F8EC;
extern GObj* D_800E8360_A0F8F0;

extern Sprite D_802DABC0_sprite;
extern Sprite D_80312238_sprite;
extern Sprite D_803128E0_sprite;
extern Sprite D_80316230_sprite;
extern Sprite D_80319B80_sprite;
extern Sprite D_8031D4D0_sprite;
extern Sprite D_80320E20_sprite;
extern Sprite D_80324770_sprite;
extern Sprite D_803280C0_sprite;
extern Sprite D_8032BA10_sprite;
extern Sprite D_8032F360_sprite;
extern Sprite D_80332CB0_sprite;
extern Sprite D_80336600_sprite;
extern Sprite D_80339F50_sprite;
extern Sprite D_8033D8A0_sprite;
extern Sprite D_8033E210_sprite;
extern Sprite D_8033E938_sprite;
extern Sprite D_8033ECD0_sprite;
extern Sprite D_8033ED70_sprite;
extern Sprite D_8033F498_sprite;
extern Sprite D_8033FBB8_sprite;
extern Sprite D_80341160_sprite;
extern Sprite D_80341790_sprite;
extern Sprite D_80341C70_sprite;
extern Sprite D_80342150_sprite;
extern Sprite D_80342630_sprite;
extern Sprite D_80342B10_sprite;
extern Sprite D_80342FF0_sprite;
extern Sprite D_803434D0_sprite;

void func_800E5F40_A0D4D0(void) {
}

void func_800E5F48_A0D4D8(void) {
    SObj* sobj;

    D_800E8334_A0F8C4 = ohCreateSprite(0xE, ohUpdateDefault, 0, 0x80000000, renDrawSprite, 1, 0x80000000, -1,
                                       &D_802DABC0_sprite, 0, NULL, 1);
    sobj = D_800E8334_A0F8C4->data.sobj;
    sobj->sprite.attr = SP_TEXSHUF | SP_TRANSPARENT;
    sobj->sprite.red = sobj->sprite.green = sobj->sprite.blue = 0x66;
}

void func_800E5FDC_A0D56C(void) {
    GObj* gobj;
    SObj* sobj;

    gobj = D_800E8338_A0F8C8 = ohCreateSprite(0xE, ohUpdateDefault, 0, 0x80000000, renDrawSprite, 1, 0x80000000, -1,
                                              &D_803128E0_sprite, 0, NULL, 1);
    sobj = gobj->data.sobj;
    SET_SPRITE_POS(sobj->sprite, 40, 36);
    sobj->sprite.attr = SP_TEXSHUF | SP_TRANSPARENT;
    omGObjAddSprite(gobj, &D_803128E0_sprite);

    sobj = sobj->next;
    SET_SPRITE_POS(sobj->sprite, 40, 54);
    sobj->sprite.attr = SP_TEXSHUF | SP_TRANSPARENT;
    omGObjAddSprite(gobj, &D_803128E0_sprite);

    sobj = sobj->next;
    SET_SPRITE_POS(sobj->sprite, 40, 166);
    sobj->sprite.attr = SP_TEXSHUF | SP_TRANSPARENT;
    omGObjAddSprite(gobj, &D_803128E0_sprite);

    sobj = sobj->next;
    SET_SPRITE_POS(sobj->sprite, 40, 197);
    sobj->sprite.attr = SP_TEXSHUF | SP_TRANSPARENT;
    omGObjAddSprite(gobj, &D_80312238_sprite);

    sobj = sobj->next;
    SET_SPRITE_POS(sobj->sprite, 39, 168);
    sobj->sprite.attr = SP_TEXSHUF | SP_TRANSPARENT;
    omGObjAddSprite(gobj, &D_80312238_sprite);

    sobj = sobj->next;
    SET_SPRITE_POS(sobj->sprite, 278, 168);
    sobj->sprite.attr = SP_TEXSHUF | SP_TRANSPARENT;
    omGObjAddSprite(gobj, &D_8033ED70_sprite);

    sobj = sobj->next;
    SET_SPRITE_POS(sobj->sprite, 158, 91);
    sobj->sprite.attr = SP_TEXSHUF | SP_TRANSPARENT;
    omGObjAddSprite(gobj, &D_8033ED70_sprite);

    sobj = sobj->next;
    SET_SPRITE_POS(sobj->sprite, 158, 107);
    sobj->sprite.attr = SP_TEXSHUF | SP_TRANSPARENT;
    omGObjAddSprite(gobj, &D_8033ED70_sprite);

    sobj = sobj->next;
    SET_SPRITE_POS(sobj->sprite, 158, 123);
    sobj->sprite.attr = SP_TEXSHUF | SP_TRANSPARENT;
}

void func_800E61C8_A0D758(void) {
    GObj* gobj;
    SObj* sobj;

    gobj = D_800E833C_A0F8CC = ohCreateSprite(0xE, ohUpdateDefault, 0, 0x80000000, renDrawSprite, 1, 0x80000000, -1,
                                              &D_80341790_sprite, 0, NULL, 1);
    sobj = gobj->data.sobj;
    SET_SPRITE_POS(sobj->sprite, 43, 40);
    sobj->sprite.attr = SP_TEXSHUF | SP_TRANSPARENT;
    omGObjAddSprite(gobj, &D_80341160_sprite);

    sobj = sobj->next;
    SET_SPRITE_POS(sobj->sprite, 161, 41);
    sobj->sprite.attr = SP_TEXSHUF | SP_TRANSPARENT;
}

void func_800E6290_A0D820(void) {
    GObj* gobj;
    SObj* sobj;

    gobj = D_800E8340_A0F8D0 = ohCreateSprite(0xE, ohUpdateDefault, 0, 0x80000000, renDrawSprite, 1, 0x80000000, -1,
                                              &D_8033F498_sprite, 0, NULL, 1);
    sobj = gobj->data.sobj;
    SET_SPRITE_POS(sobj->sprite, 43, 73);
    sobj->sprite.red = sobj->sprite.green = sobj->sprite.blue = 0x80;
    sobj->sprite.attr = SP_TEXSHUF | SP_TRANSPARENT;
    omGObjAddSprite(gobj, &D_8033FBB8_sprite);

    sobj = sobj->next;
    SET_SPRITE_POS(sobj->sprite, 43, 89);
    sobj->sprite.red = sobj->sprite.green = sobj->sprite.blue = 0x80;
    sobj->sprite.attr = SP_TEXSHUF | SP_TRANSPARENT;
    omGObjAddSprite(gobj, &D_8033E938_sprite);

    sobj = sobj->next;
    SET_SPRITE_POS(sobj->sprite, 43, 105);
    sobj->sprite.red = sobj->sprite.green = sobj->sprite.blue = 0x80;
    sobj->sprite.attr = SP_TEXSHUF | SP_TRANSPARENT;
    omGObjAddSprite(gobj, &D_8033E210_sprite);

    sobj = sobj->next;
    SET_SPRITE_POS(sobj->sprite, 43, 121);
    sobj->sprite.red = sobj->sprite.green = sobj->sprite.blue = 0x80;
    sobj->sprite.attr = SP_TEXSHUF | SP_TRANSPARENT;
    omGObjAddSprite(gobj, &D_8033ECD0_sprite);

    sobj = sobj->next;
    SET_SPRITE_POS(sobj->sprite, 43, 137);
    sobj->sprite.red = sobj->sprite.green = sobj->sprite.blue = 0x80;
    sobj->sprite.attr = SP_TEXSHUF | SP_TRANSPARENT;
}

void func_800E643C_A0D9CC(SObj* sobj, s8 arg1) {
    if (!arg1) {
        sobj->sprite.red = 0xFF;
        sobj->sprite.green = 0x82;
        sobj->sprite.blue = 0x41;
    } else {
        sobj->sprite.red = 0x80;
        sobj->sprite.green = 0x80;
        sobj->sprite.blue = 0x80;
    }
}

void func_800E6480_A0DA10(void) {
    s8 sp5F;
    s8 sp5E;
    s8 sp5D;
    UNUSED s32 pad;
    GObj* gobj;
    SObj* sobj;

    sp5F = checkPlayerFlag(PFID_9);
    sp5E = checkPlayerFlag(PFID_ZOOM_SWITCH);
    sp5D = checkPlayerFlag(PFID_INVERTED_Y);

    gobj = D_800E8358_A0F8E8 = ohCreateSprite(0xE, ohUpdateDefault, 0, 0x80000000, renDrawSprite, 1, 0x80000000, -1,
                                              &D_80342FF0_sprite, 0, NULL, 1);
    sobj = gobj->data.sobj;
    SET_SPRITE_POS(sobj->sprite, 163, 89);
    func_800E643C_A0D9CC(sobj, sp5F);
    sobj->sprite.attr = SP_TEXSHUF | SP_TRANSPARENT;
    omGObjAddSprite(gobj, &D_80342150_sprite);

    sobj = sobj->next;
    SET_SPRITE_POS(sobj->sprite, 222, 89);
    func_800E643C_A0D9CC(sobj, sp5F == 0);
    sobj->sprite.attr = SP_TEXSHUF | SP_TRANSPARENT;

    gobj = D_800E835C_A0F8EC = ohCreateSprite(0xE, ohUpdateDefault, 0, 0x80000000, renDrawSprite, 1, 0x80000000, -1,
                                              &D_80341C70_sprite, 0, NULL, 1);
    sobj = gobj->data.sobj;
    SET_SPRITE_POS(sobj->sprite, 163, 105);
    func_800E643C_A0D9CC(sobj, sp5E);
    sobj->sprite.attr = SP_TEXSHUF | SP_TRANSPARENT;
    omGObjAddSprite(gobj, &D_803434D0_sprite);

    sobj = sobj->next;
    SET_SPRITE_POS(sobj->sprite, 222, 105);
    func_800E643C_A0D9CC(sobj, sp5E == 0);
    sobj->sprite.attr = SP_TEXSHUF | SP_TRANSPARENT;

    gobj = D_800E8360_A0F8F0 = ohCreateSprite(0xE, ohUpdateDefault, 0, 0x80000000, renDrawSprite, 1, 0x80000000, -1,
                                              &D_80342B10_sprite, 0, NULL, 1);
    sobj = gobj->data.sobj;
    SET_SPRITE_POS(sobj->sprite, 163, 121);
    func_800E643C_A0D9CC(sobj, sp5D);
    sobj->sprite.attr = SP_TEXSHUF | SP_TRANSPARENT;
    omGObjAddSprite(gobj, &D_80342630_sprite);

    sobj = sobj->next;
    SET_SPRITE_POS(sobj->sprite, 222, 121);
    func_800E643C_A0D9CC(sobj, sp5D == 0);
    sobj->sprite.attr = SP_TEXSHUF | SP_TRANSPARENT;
}

void func_800E672C_A0DCBC(void) {
    GObj* gobj;
    SObj* sobj;

    gobj = D_800E8344_A0F8D4 = ohCreateSprite(0xE, ohUpdateDefault, 0, 0x80000000, renDrawSprite, 1, 0x80000000, -1,
                                              &D_8032F360_sprite, 0, NULL, 1);
    sobj = gobj->data.sobj;
    SET_SPRITE_POS(sobj->sprite, 41, 168);
    sobj->sprite.attr = SP_TEXSHUF | SP_HIDDEN | SP_TRANSPARENT;
    omGObjAddSprite(gobj, &D_80339F50_sprite);

    sobj = sobj->next;
    SET_SPRITE_POS(sobj->sprite, 41, 168);
    sobj->sprite.attr = SP_TEXSHUF | SP_HIDDEN | SP_TRANSPARENT;
    omGObjAddSprite(gobj, &D_803280C0_sprite);

    sobj = sobj->next;
    SET_SPRITE_POS(sobj->sprite, 41, 168);
    sobj->sprite.attr = SP_TEXSHUF | SP_HIDDEN | SP_TRANSPARENT;
    omGObjAddSprite(gobj, &D_80316230_sprite);

    sobj = sobj->next;
    SET_SPRITE_POS(sobj->sprite, 41, 168);
    sobj->sprite.attr = SP_TEXSHUF | SP_HIDDEN | SP_TRANSPARENT;
    omGObjAddSprite(gobj, &D_8032BA10_sprite);

    sobj = sobj->next;
    SET_SPRITE_POS(sobj->sprite, 41, 168);
    sobj->sprite.attr = SP_TEXSHUF | SP_HIDDEN | SP_TRANSPARENT;
}

void func_800E6880_A0DE10(void) {
    GObj* gobj;
    SObj* sobj;

    D_800E8348_A0F8D8 = ohCreateSprite(0xE, ohUpdateDefault, 0, 0x80000000, renDrawSprite, 1, 0x80000000, -1,
                                       &D_80332CB0_sprite, 0, NULL, 1);
    sobj = D_800E8348_A0F8D8->data.sobj;
    SET_SPRITE_POS(sobj->sprite, 41, 168);
    sobj->sprite.attr = SP_TEXSHUF | SP_HIDDEN | SP_TRANSPARENT;

    gobj = D_800E834C_A0F8DC = ohCreateSprite(0xE, ohUpdateDefault, 0, 0x80000000, renDrawSprite, 1, 0x80000000, -1,
                                              &D_8033D8A0_sprite, 0, NULL, 1);
    sobj = gobj->data.sobj;
    SET_SPRITE_POS(sobj->sprite, 41, 168);
    sobj->sprite.attr = SP_TEXSHUF | SP_HIDDEN | SP_TRANSPARENT;
    omGObjAddSprite(gobj, &D_80336600_sprite);

    sobj = sobj->next;
    SET_SPRITE_POS(sobj->sprite, 41, 168);
    sobj->sprite.attr = SP_TEXSHUF | SP_HIDDEN | SP_TRANSPARENT;

    gobj = D_800E8350_A0F8E0 = ohCreateSprite(0xE, ohUpdateDefault, 0, 0x80000000, renDrawSprite, 1, 0x80000000, -1,
                                              &D_80320E20_sprite, 0, NULL, 1);
    sobj = gobj->data.sobj;
    SET_SPRITE_POS(sobj->sprite, 41, 168);
    sobj->sprite.attr = SP_TEXSHUF | SP_HIDDEN | SP_TRANSPARENT;
    omGObjAddSprite(gobj, &D_80324770_sprite);

    sobj = sobj->next;
    SET_SPRITE_POS(sobj->sprite, 41, 168);
    sobj->sprite.attr = SP_TEXSHUF | SP_HIDDEN | SP_TRANSPARENT;

    gobj = D_800E8354_A0F8E4 = ohCreateSprite(0xE, ohUpdateDefault, 0, 0x80000000, renDrawSprite, 1, 0x80000000, -1,
                                              &D_8031D4D0_sprite, 0, NULL, 1);
    sobj = gobj->data.sobj;
    SET_SPRITE_POS(sobj->sprite, 41, 168);
    sobj->sprite.attr = SP_TEXSHUF | SP_HIDDEN | SP_TRANSPARENT;
    omGObjAddSprite(gobj, &D_80319B80_sprite);

    sobj = sobj->next;
    SET_SPRITE_POS(sobj->sprite, 41, 168);
    sobj->sprite.attr = SP_TEXSHUF | SP_HIDDEN | SP_TRANSPARENT;
}

void func_800E6ADC_A0E06C(void) {
    func_800E5F48_A0D4D8();
    func_800E5FDC_A0D56C();
    func_800E61C8_A0D758();
    func_800E6290_A0D820();
    func_800E6480_A0DA10();
    func_800E672C_A0DCBC();
    func_800E6880_A0DE10();
}

s32 func_800E6B2C_A0E0BC(void) {
    func_800E6ADC_A0E06C();
    func_800E7F98_A0F528();
    omDeleteGObj(D_800E8334_A0F8C4);
    omDeleteGObj(D_800E8338_A0F8C8);
    omDeleteGObj(D_800E833C_A0F8CC);
    omDeleteGObj(D_800E8340_A0F8D0);
    omDeleteGObj(D_800E8344_A0F8D4);
    omDeleteGObj(D_800E8348_A0F8D8);
    omDeleteGObj(D_800E834C_A0F8DC);
    omDeleteGObj(D_800E8350_A0F8E0);
    omDeleteGObj(D_800E8354_A0F8E4);
    omDeleteGObj(D_800E8358_A0F8E8);
    omDeleteGObj(D_800E835C_A0F8EC);
    omDeleteGObj(D_800E8360_A0F8F0);
    return 12;
}
