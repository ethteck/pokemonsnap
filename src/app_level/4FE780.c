#include "common.h"

extern Sprite D_80388E00_529210;
extern UNK_TYPE D_80388F58_529368;
extern Sprite D_80388F60_529370;
extern UNK_TYPE D_803890B8_5294C8;
extern Sprite D_803890C0_5294D0;
extern UNK_TYPE D_80389218_529628;
extern Sprite D_80389220_529630;
extern s32 D_8038A024_52A434;
extern s32 D_8038A028_52A438;
extern s32 D_8038A02C_52A43C;
extern s32 D_8038A030_52A440;
extern UNK_TYPE D_8038A034_52A444[];
extern GObj* D_803B09D8_550DE8;
extern SObj* D_803B0A14_550E24;
extern SObj* D_803B0A18_550E28;
extern SObj* D_803B0A1C_550E2C;

s32 func_8035E370_4FE780(void) {
    return D_8038A028_52A438;
}

s32 func_8035E52C_4FE93C(void);

void func_8035E37C_4FE78C(void) {
    GObj* obj;
    SObj* sobj;

    D_8038A024_52A434 = 0;
    D_8038A028_52A438 = 1;
    D_8038A02C_52A43C = 0;
    D_8038A030_52A440 = 6;

    obj = omAddGObj(OBJID_28, ohUpdateDefault, LINK_0, 0x80000000);
    omLinkGObjDL(obj, renDrawSprite, DL_LINK_1, 0x80000000, -1);
    D_803B09D8_550DE8 = obj;

    sobj = omGObjAddSprite(obj, &D_80388E00_529210);
    spMove(&sobj->sprite, 257, 22);

    D_803B0A14_550E24 = sobj = omGObjAddSprite(obj, &D_80388F60_529370);
    spMove(&sobj->sprite, 286, 24);

    D_803B0A18_550E28 = sobj = omGObjAddSprite(obj, &D_803890C0_5294D0);
    spMove(&sobj->sprite, 278, 24);
    spSetAttribute(&sobj->sprite, SP_HIDDEN);

    D_803B0A1C_550E2C = sobj = omGObjAddSprite(obj, &D_80389220_529630);
    spMove(&sobj->sprite, 270, 24);
    spSetAttribute(&sobj->sprite, SP_HIDDEN);

    func_8035E52C_4FE93C();
}

void func_8035E4D0_4FE8E0(void) {
    if (D_803B09D8_550DE8 != NULL) {
        omDeleteGObj(D_803B09D8_550DE8);
        D_803B09D8_550DE8 = NULL;
    }
}

s32 func_8035E508_4FE918(void) {
    return 60 - func_8009BC68();
}

s32 func_8035E52C_4FE93C(void) {
    s32 ones, tens, hundreds;
    s32 value = 60 - func_8009BC68();

    ones = value % 10;
    tens = (value % 100) / 10;
    hundreds = value / 100;

    D_80388F58_529368 = D_8038A034_52A444[ones];

    if (hundreds == 0) {
        if (tens == 0) {
            spSetAttribute(&D_803B0A18_550E28->sprite, SP_HIDDEN);
        } else {
            D_803890B8_5294C8 = D_8038A034_52A444[tens];
            spClearAttribute(&D_803B0A18_550E28->sprite, SP_HIDDEN);
        }
        spSetAttribute(&D_803B0A1C_550E2C->sprite, SP_HIDDEN);
    } else {
        D_803890B8_5294C8 = D_8038A034_52A444[tens];
        spClearAttribute(&D_803B0A18_550E28->sprite, SP_HIDDEN);
        D_80389218_529628 = D_8038A034_52A444[hundreds];
        spClearAttribute(&D_803B0A1C_550E2C->sprite, SP_HIDDEN);
    }

    if (value == 10) {
        spColor(&D_803B0A14_550E24->sprite, 255, 0, 0, 255);
        spColor(&D_803B0A18_550E28->sprite, 255, 0, 0, 255);
    }

    return value;
}

void func_8035E754_4FEB64(void) {
    D_803B09D8_550DE8->flags = 0;
}

void func_8035E764_4FEB74(void) {
    D_803B09D8_550DE8->flags |= GOBJ_FLAG_HIDDEN;
}
