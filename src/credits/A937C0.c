#include "common.h"
#include "credits.h"

GObj* func_credits_801DCC00(GObj* arg0, Sprite* arg1) {
    return ohCreateSprite(0xE, ohUpdateDefault, 0, 0x80000000, renDrawSprite, 1, 0x80000000, -1, arg1, 0, NULL, 1);
}

GObj* func_credits_801DCC70(void) {
    GObj* gobj = func_credits_801DCC00(gobj, &D_credits_801E6058);

    omGObjAddSprite(gobj, &D_credits_801E6430);
    omGObjAddSprite(gobj, &D_credits_801E6430);
    omGObjAddSprite(gobj, &D_credits_801E67D8);
    omGObjAddSprite(gobj, &D_credits_801E67D8);

    return gobj;
}

void func_credits_801DCCE4(SObj* arg0) {
    SObj* sobj = arg0;

    sobj->sprite.x = 90;
    sobj->sprite.y = 68;

    sobj = arg0->next;
    sobj->sprite.x = arg0->sprite.x - 3;
    sobj->sprite.y = arg0->sprite.y - 3;

    sobj = sobj->next;
    sobj->sprite.x = arg0->sprite.x + 140;
    sobj->sprite.y = arg0->sprite.y - 3;

    sobj = sobj->next;
    sobj->sprite.x = arg0->sprite.x;
    sobj->sprite.y = arg0->sprite.y - 3;

    sobj = sobj->next;
    sobj->sprite.x = arg0->sprite.x;
    sobj->sprite.y = arg0->sprite.y + 105;
}

void func_credits_801DCD60(SObj* arg0) {
    while (arg0 != NULL) {
        arg0->sprite.attr = SP_TEXSHUF | SP_SCALE | SP_HIDDEN | SP_TRANSPARENT;
        arg0 = arg0->next;
    }
}

void func_credits_801DCD80(SObj* sobj) {
    Bitmap* list = (Bitmap*)func_8036A194_83D944(sizeof(Bitmap) * 8);
    u16* buf;
    u8 i;

    for (i = 0; i < 8u; i++) {
        buf = func_8036A194_83D944(14 * 140 * sizeof(u16));

        list[i] = sobj->sprite.bitmap[i];
        list[i].buf = buf;
    }

    sobj->sprite.bitmap = list;
}

void func_credits_801DCE10(void) {
    GObj* gobj;
    SObj* sobj;
    s8 i;

    for (i = 4; i >= 0; i--) {
        gobj = func_credits_801DCC70();
        D_credits_801ECC80[i] = gobj;
        sobj = gobj->data.sobj;
        func_credits_801DCCE4(sobj);
        func_credits_801DCD60(sobj);
        func_credits_801DCD80(sobj);
        func_credits_801DE8A0(sobj, func_credits_801DE8D8());
        func_credits_801DEB74(sobj, 4.0f);
        func_credits_801DEA30(sobj, 4.0f);
        while (sobj != NULL) {
            sobj->sprite.attr &= ~SP_HIDDEN;
            sobj = sobj->next;
        }
    }
}

void func_credits_801DCEF0(GObj* arg0) {
    ohWait(226);

    while (TRUE) {
        if (gContInputPressedButtons & (A_BUTTON | START_BUTTON)) {
            func_800A7470(0, 0, 0);
            func_800A7860(0, 1.0f);
            auSetBGMVolumeSmooth(0, 0, 60);
            ohWait(60);
            func_800067DC();

            while (TRUE) {
                ohWait(1);
            }
        }
        ohWait(1);
    }
}

void func_credits_801DCF94(void) {
    omCreateProcess(D_credits_801ECC80[0], func_credits_801DCEF0, 0, 1);
}

s32 func_credits_801DCFC8(GObj* gobj) {
    SObj* sobj = gobj->data.sobj;

    if (sobj->sprite.attr & SP_HIDDEN &&
        sobj->next->sprite.attr & SP_HIDDEN &&
        sobj->next->next->sprite.attr & SP_HIDDEN) {
        return TRUE;
    }

    return FALSE;
}

void func_credits_801DD018(GObj* gobj) {
    SObj* sobj = gobj->data.sobj;

    while (sobj != NULL) {
        sobj->sprite.x--;
        if (sobj->sprite.x < -259.0) {
            if (D_credits_801ED010 != 0) {
                D_credits_801ED010--;
                if (D_credits_801ED010 == 0) {
                    D_credits_801ECDA4 = 2;
                }
            }
            if (D_credits_801ECDA4 == 1) {
                sobj->sprite.x += 700.0;
                func_credits_801DCAF8(sobj);
            } else {
                sobj->sprite.attr |= SP_HIDDEN;
            }
        }

        sobj = sobj->next;
    }
}

s32 func_credits_801DD12C(GObj* gobj) {
    SObj* sobj = gobj->data.sobj;

    while (sobj != NULL) {
        if (sobj->sprite.x == 90) {
            return 90;
        }
        sobj = sobj->next;
    }

    return 0;
}

void func_credits_801DD168(GObj* gobj) {
    u8 var_s0;

    ohWait(1);
    while (D_credits_801ECDA4 != 1) {
        ohWait(1);
    }

    var_s0 = 0;
    while (TRUE) {
        while (var_s0 != 0) {
            ohWait(1);
            var_s0--;
        }

        if (func_credits_801DCFC8(gobj)) {
            break;
        }

        func_credits_801DD018(gobj);
        var_s0 = func_credits_801DD12C(gobj);
        ohWait(1);
    }

    ohRemoveSprite(gobj);

    while (TRUE) {
        ohWait(1);
    }
}

GObj* func_credits_801DD258(void) {
    GObj* gobj = func_credits_801DCC00(gobj, &D_credits_801E6058);

    omGObjAddSprite(gobj, &D_credits_801E6058);
    omGObjAddSprite(gobj, &D_credits_801E6058);
    omGObjAddSprite(gobj, &D_credits_801E6058);
    omCreateProcess(gobj, func_credits_801DD168, 0, 1);

    return gobj;
}

void func_credits_801DD2D4(SObj* sobj) {
    s16 x = SCREEN_WIDTH;

    while (sobj != NULL) {
        sobj->sprite.x = x;
        sobj->sprite.y = 68;
        sobj = sobj->next;
        x += 175.0;
    }
}

void func_credits_801DD320(SObj* sobj) {
    while (sobj != NULL) {
        sobj->sprite.attr = SP_TEXSHUF | SP_HIDDEN | SP_TRANSPARENT;
        sobj = sobj->next;
    }
}

void func_credits_801DD340(SObj* sobj) {
    Bitmap* list;
    u16* buf;
    u8 i;

    while (sobj != NULL) {
        list = (Bitmap*)func_8036A194_83D944(sizeof(Bitmap) * 8);

        for (i = 0; i < 8u; i++) {
            buf = func_8036A194_83D944(1960 * sizeof(u16));

            list[i] = sobj->sprite.bitmap[i];
            list[i].buf = buf;
        }

        sobj->sprite.bitmap = list;
        sobj = sobj->next;
    }
}

void func_credits_801DD3E0(SObj* sobj) {
    while (sobj != NULL) {
        func_credits_801DE8A0(sobj, func_credits_801DE8D8());
        sobj = sobj->next;
    }
}

void func_credits_801DD428(void) {
    GObj* gobj;
    SObj* sobj;

    gobj = func_credits_801DD258();
    D_credits_801ECC94 = gobj;
    sobj = gobj->data.sobj;
    func_credits_801DD2D4(sobj);
    func_credits_801DD320(sobj);
    func_credits_801DD340(sobj);
    func_credits_801DD3E0(sobj);

    while (sobj != NULL) {
        sobj->unk_54 = 0;
        sobj->sprite.attr &= ~SP_HIDDEN;
        sobj = sobj->next;
    }
}

void func_credits_801DD49C(GObj* arg0) {
    SObj* temp_s0;
    f32 var_f20;

    temp_s0 = arg0->data.sobj;
    var_f20 = temp_s0->sprite.x;

    while (TRUE) {
        var_f20 -= 1.3f;
        if (var_f20 < -16.0f) {
            var_f20 += 16.0f;
        }
        // clang-format off
        temp_s0->sprite.x = var_f20; temp_s0->sprite.y = temp_s0->sprite.y;
        // clang-format on
        ohWait(1);
    }
}

void func_credits_801DD540(GObj* arg0) {
    u8 i;
    SObj* sp44[2];
    f32 sp3C[2];

    for (i = 0; i < ARRAY_COUNT(D_credits_801ECC98); i++) {
        sp44[i] = D_credits_801ECC98[i]->data.sobj;
        sp3C[i] = sp44[i]->sprite.y;
    }

    while (TRUE) {
        if ((sp44[0]->sprite.y < 0)) {
            break;
        }

        sp3C[0] -= 0.5f;
        sp44[0]->sprite.y = sp3C[0];
        sp44[0]->sprite.alpha = (sp44[0]->sprite.y * 255) / 48;

        sp3C[1] += 0.5f;
        sp44[1]->sprite.y = sp3C[1];
        sp44[1]->sprite.alpha = ((0xF0 - sp44[1]->sprite.y) * 255) / 58;

        ohWait(1);
    }

    for (i = 0; i < 2; i++) {
        sp44[i]->sprite.attr |= SP_HIDDEN;
    }

    while (TRUE) {
        ohWait(1);
    }
}

void func_credits_801DD744(void) {
    ohEndAllObjectProcesses(D_credits_801ECC98[0]);
    ohEndAllObjectProcesses(D_credits_801ECC98[1]);
    omCreateProcess(D_credits_801ECC98[0], func_credits_801DD540, 0, 1);
}

GObj* func_credits_801DD790(void) {
    GObj* gobj = func_credits_801DCC00(gobj, &D_credits_801E6AA8);

    omCreateProcess(gobj, func_credits_801DD49C, 0, 1);
    return gobj;
}

void func_credits_801DD7D8(SObj* sobj, u8 arg1) {
    sobj->sprite.width = 336;

    switch (arg1) {
        case 0:
            SET_SPRITE_POS(sobj->sprite, SCREEN_WIDTH, 68 - (sobj->sprite.height * 2));
            return;
        case 1:
            sobj->sprite.x = SCREEN_WIDTH;
            sobj->sprite.y = sobj->sprite.height + 172;
            return;
    }
}

void func_credits_801DD83C(SObj* sobj) {
    sobj->sprite.attr = SP_TEXSHUF | SP_TRANSPARENT;
}

void func_credits_801DD848(void) {
    SObj* temp_s1;
    u8 i;

    for (i = 0; i < ARRAY_COUNT(D_credits_801ECC98); i++) {
        D_credits_801ECC98[i] = func_credits_801DD790();
        temp_s1 = D_credits_801ECC98[i]->data.sobj;
        func_credits_801DD7D8(temp_s1, i);
        func_credits_801DD83C(temp_s1);
    }
}
