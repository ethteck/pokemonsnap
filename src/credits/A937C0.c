#include "common.h"
#include "credits.h"

GObj* func_credits_801DCC00(GObj* arg0, Sprite* arg1) {
    return ohCreateSprite(0xE, ohUpdateDefault, 0, 0x80000000, renDrawSprite, 1U, 0x80000000, -1, arg1, 0U, NULL, 1);
}

GObj* func_credits_801DCC70(void) {
    GObj* temp_v0;

    temp_v0 = func_credits_801DCC00(temp_v0, &D_credits_801E6058);
    omGObjAddSprite(temp_v0, &D_credits_801E6430);
    omGObjAddSprite(temp_v0, &D_credits_801E6430);
    omGObjAddSprite(temp_v0, &D_credits_801E67D8);
    omGObjAddSprite(temp_v0, &D_credits_801E67D8);

    return temp_v0;
}

void func_credits_801DCCE4(SObj* arg0) {
    SObj* temp_v0;

    temp_v0 = arg0;
    temp_v0->sprite.x = 0x5A;
    temp_v0->sprite.y = 0x44;

    temp_v0 = arg0->next;
    temp_v0->sprite.x = arg0->sprite.x - 3;
    temp_v0->sprite.y = arg0->sprite.y - 3;

    temp_v0 = temp_v0->next;
    temp_v0->sprite.x = arg0->sprite.x + 0x8C;
    temp_v0->sprite.y = arg0->sprite.y - 3;

    temp_v0 = temp_v0->next;
    temp_v0->sprite.x = arg0->sprite.x;
    temp_v0->sprite.y = arg0->sprite.y - 3;

    temp_v0 = temp_v0->next;
    temp_v0->sprite.x = arg0->sprite.x;
    temp_v0->sprite.y = arg0->sprite.y + 0x69;
}

void func_credits_801DCD60(SObj* arg0) {
    while (arg0) {
        arg0->sprite.attr = SP_TEXSHUF | SP_SCALE | SP_HIDDEN | SP_TRANSPARENT;
        arg0 = arg0->next;
    }
}

void func_credits_801DCD80(SObj* arg0) {
    Bitmap* list;
    u16* buf;
    u8 var_s0;

    list = (Bitmap*) func_8036A194_83D944(sizeof(Bitmap) * 8);
    for (var_s0 = 0; var_s0 < 8u; var_s0++) {
        buf = func_8036A194_83D944(14 * 140 * sizeof(u16));

        list[var_s0] = arg0->sprite.bitmap[var_s0];
        list[var_s0].buf = buf;
    }

    arg0->sprite.bitmap = list;
}

void func_credits_801DCE10(void) {
    GObj* temp_v0;
    SObj* sobj;
    s8 var_s2;

    for (var_s2 = 4; var_s2 >= 0; var_s2--) {
        temp_v0 = func_credits_801DCC70();
        (&D_credits_801ECC80)[var_s2] = temp_v0;
        sobj = temp_v0->data.sobj;
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
    ohWait(0xE2);

    while (1) {
        if (gContInputPressedButtons & 0x9000) {
            func_800A7470(0, 0, 0);
            func_800A7860(0, 1.0f);
            auSetBGMVolumeSmooth(0, 0U, 0x3CU);
            ohWait(0x3C);
            func_800067DC();

            while (1) {
                ohWait(1);
            }
        }
        ohWait(1);
    }
}

void func_credits_801DCF94(void) {
    omCreateProcess(D_credits_801ECC80, func_credits_801DCEF0, 0U, 1U);
}

s32 func_credits_801DCFC8(GObj* arg0) {
    SObj* temp_v0;

    temp_v0 = arg0->data.sobj;
    if (temp_v0->sprite.attr & SP_HIDDEN) {
        if ((temp_v0->next->sprite.attr & SP_HIDDEN) && (temp_v0->next->next->sprite.attr & SP_HIDDEN)) {
            return 1;
        }
    }

    return 0;
}

void func_credits_801DD018(GObj* arg0) {
    SObj* var_s0;

    var_s0 = arg0->data.sobj;
    while (var_s0 != NULL) {
        var_s0->sprite.x -= 1;
        if (var_s0->sprite.x < -259.0) {
            if (D_credits_801ED010 != 0) {
                D_credits_801ED010--;
                if (D_credits_801ED010 == 0) {
                    D_credits_801ECDA4 = 2;
                }
            }
            if (D_credits_801ECDA4 == 1) {
                var_s0->sprite.x += 700.0;
                func_credits_801DCAF8(var_s0);
            } else {
                var_s0->sprite.attr |= SP_HIDDEN;
            }
        }

        var_s0 = var_s0->next;
    }
}

s32 func_credits_801DD12C(GObj* arg0) {
    SObj* sobj;

    sobj = arg0->data.sobj;
    while (sobj != NULL) {
        if (sobj->sprite.x == 90) {
            return 90;
        }
        sobj = sobj->next;
    }

    return 0;
}

void func_credits_801DD168(GObj* arg0) {
    s32 var_s0;

    ohWait(1);
    while (D_credits_801ECDA4 != 1) {
        ohWait(1);
    }

    var_s0 = 0;
    while (1) {
        while (var_s0 != 0) {
            ohWait(1);
            var_s0 = (var_s0 - 1) & 0xFF;
        }

        if (func_credits_801DCFC8(arg0)) {
            break;
        }

        func_credits_801DD018(arg0);
        var_s0 = func_credits_801DD12C(arg0) & 0xFF;
        ohWait(1);
    }

    ohRemoveSprite(arg0);

    while (1) {
        ohWait(1);
    }
}

GObj* func_credits_801DD258(void) {
    GObj* temp_v0;

    temp_v0 = func_credits_801DCC00(temp_v0, &D_credits_801E6058);
    omGObjAddSprite(temp_v0, &D_credits_801E6058);
    omGObjAddSprite(temp_v0, &D_credits_801E6058);
    omGObjAddSprite(temp_v0, &D_credits_801E6058);
    omCreateProcess(temp_v0, func_credits_801DD168, 0U, 1U);

    return temp_v0;
}

void func_credits_801DD2D4(SObj* arg0) {
    s16 var_v0;

    var_v0 = 320;
    while (arg0 != NULL) {
        arg0->sprite.x = var_v0;
        arg0->sprite.y = 68;
        arg0 = arg0->next;
        var_v0 += 175.0;
    }
}

void func_credits_801DD320(SObj* arg0) {
    while (arg0) {
        arg0->sprite.attr = SP_TEXSHUF | SP_HIDDEN | SP_TRANSPARENT;
        arg0 = arg0->next;
    }
}

void func_credits_801DD340(SObj* arg0) {
    Bitmap* list;
    u16* buf;
    u8 i;

    while (arg0 != NULL) {
        list = (Bitmap*) func_8036A194_83D944(sizeof(Bitmap) * 8);

        for (i = 0; i < 8u; i++) {
            buf = func_8036A194_83D944(1960 * sizeof(u16));

            list[i] = arg0->sprite.bitmap[i];
            list[i].buf = buf;
        }

        arg0->sprite.bitmap = list;
        arg0 = arg0->next;
    }
}

void func_credits_801DD3E0(SObj* arg0) {
    while (arg0 != NULL) {
        func_credits_801DE8A0(arg0, func_credits_801DE8D8());
        arg0 = arg0->next;
    }
}

void func_credits_801DD428(void) {
    GObj* temp_v0;
    SObj* var_s0;

    temp_v0 = func_credits_801DD258();
    D_credits_801ECC94 = temp_v0;
    var_s0 = temp_v0->data.sobj;
    func_credits_801DD2D4(var_s0);
    func_credits_801DD320(var_s0);
    func_credits_801DD340(var_s0);
    func_credits_801DD3E0(var_s0);

    while (var_s0 != NULL) {
        var_s0->unk54 = 0;
        var_s0->sprite.attr &= ~SP_HIDDEN;
        var_s0 = var_s0->next;
    }
}

#if 1
#pragma GLOBAL_ASM("asm/nonmatchings/credits/A937C0/func_credits_801DD49C.s")
#else
// TODO: there should be a file split after this and before the next rodata
void func_credits_801DD49C(GObj* arg0) {
    SObj* temp_s0;
    f32 var_f20;

    temp_s0 = arg0->data.sobj;
    var_f20 = temp_s0->sprite.x;

    while (1) {
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
#endif

void func_credits_801DD540(GObj* arg0) {
    u8 i;
    SObj* sp44[2];
    f32 sp3C[2];

    for (i = 0; i < 2; i++) {
        sp44[i] = D_credits_801ECC98[i]->data.sobj;
        sp3C[i] = sp44[i]->sprite.y;
    }

    while (1) {
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
        sp44[i]->sprite.attr |= 4;
    }

    while (1) {
        ohWait(1);
    }
}

void func_credits_801DD744(void) {
    ohEndAllObjectProcesses(D_credits_801ECC98[0]);
    ohEndAllObjectProcesses(D_credits_801ECC98[1]);
    omCreateProcess(D_credits_801ECC98[0], func_credits_801DD540, 0U, 1U);
}

GObj* func_credits_801DD790(void) {
    GObj* sp1C;

    sp1C = func_credits_801DCC00(sp1C, &D_credits_801E6AA8);
    omCreateProcess(sp1C, func_credits_801DD49C, 0U, 1U);
    return sp1C;
}

void func_credits_801DD7D8(SObj* arg0, u8 arg1) {
    arg0->sprite.width = 0x150;

    switch (arg1) { /* irregular */
        case 0:
            // clang-format off
            // TODO: look into setPos(x, y) macro
            arg0->sprite.x = 0x140; arg0->sprite.y = 0x44 - (arg0->sprite.height * 2);
            // clang-format on
            return;
        case 1:
            arg0->sprite.x = 0x140;
            arg0->sprite.y = arg0->sprite.height + 0xAC;
            return;
    }
}

void func_credits_801DD83C(SObj* arg0) {
    arg0->sprite.attr = SP_TEXSHUF | SP_TRANSPARENT;
}

void func_credits_801DD848(void) {
    SObj* temp_s1;
    u8 i;

    for (i = 0; i < 2; i++) {
        D_credits_801ECC98[i] = func_credits_801DD790();
        temp_s1 = D_credits_801ECC98[i]->data.sobj;
        func_credits_801DD7D8(temp_s1, i);
        func_credits_801DD83C(temp_s1);
    }
}

void func_credits_801DD8C0(SObj* arg0) {
    switch (D_credits_801ECDA0) {
        case SCENE_CREDITS_17:
        case SCENE_CREDITS_18:
        case SCENE_CREDITS_20:
            arg0->sprite.x = 0x60;
            arg0->sprite.y = 0xF0;
            break;

        case SCENE_CREDITS_19:
            arg0->sprite.x = 0x140;
            arg0->sprite.y = 0x78 - ((s16) arg0->sprite.height / 2);
            break;
    }
}

void func_credits_801DD930(SObj* arg0) {
    arg0->sprite.attr = SP_TEXSHUF | SP_TRANSPARENT;
}

void func_credits_801DD93C(void) {
    GObj* sp1C;
    SObj* temp_a0;
    GObj* temp_v0;

    temp_v0 = func_credits_801DCC00(sp1C, &D_credits_801E8B50);
    D_credits_801ECCA0 = temp_v0;
    temp_a0 = temp_v0->data.sobj;
    func_credits_801DD8C0(temp_a0);
    func_credits_801DD930(temp_a0);
}

void func_credits_801DD980(void) {
    SObj* temp_s0;
    s32 temp_v0;

    temp_s0 = D_credits_801ECCA0->data.sobj;
    switch (D_credits_801ECDA0) {
        case SCENE_CREDITS_17:
        case SCENE_CREDITS_18:
        case SCENE_CREDITS_20:
            while (1) {
                temp_s0->sprite.y -= 1;
                if (temp_s0->sprite.y < 0x71) {
                    break;
                }
                ohWait(1);
            }
            temp_s0->sprite.y = 0x70;
            break;

        case SCENE_CREDITS_19:
            while (1) {
                temp_s0->sprite.x -= 1;
                temp_v0 = 0xA0 - (temp_s0->sprite.width / 2);
                if (temp_s0->sprite.x < temp_v0) {
                    break;
                }
                ohWait(1);
            }
            temp_s0->sprite.x = temp_v0;
            break;
    }
}

void func_credits_801DDA60(void) {
    u8 var_s1;
    SObj* temp_s0;

    temp_s0 = D_credits_801ECCA0->data.sobj;
    var_s1 = 0xFF;
    while (1) {
        var_s1 -= 5;
        if (var_s1 >= 0xA) {
            temp_s0->sprite.red = temp_s0->sprite.green = temp_s0->sprite.blue = var_s1;
        } else {
            temp_s0->sprite.attr |= 4;
            ohWait(1);
            break;
        }

        ohWait(1);
        ohWait(1);
    }
}

void func_credits_801DDAE8(u8 arg0) {
    switch (D_credits_801ECDA0) {
        case SCENE_CREDITS_17:
        case SCENE_CREDITS_18:
        case SCENE_CREDITS_20:
            func_credits_801DCE10();
            D_credits_801ECDA4 = 0;
            break;

        case SCENE_CREDITS_19:
            D_credits_801ECDA4 = 0;
            func_credits_801DD428();
            func_credits_801DD848();
            break;
    }

    func_credits_801DD93C();
}

void func_credits_801DDB60(void) {
    UnkChartreuseAngler* var_s0;
    f32 var_f20;

    if (D_credits_801ECDA0 == SCENE_CREDITS_19) {
        var_f20 = 0.44f;
    } else {
        var_f20 = 0.5f;
    }

    var_s0 = D_credits_801ECCB0;
    while (var_s0->unkC != 0) {
        var_s0->unk4 = (f32) (var_s0->unk4 - var_f20);
        func_8036CBA0_840350(var_s0->unkC, var_s0->unk0, (s32) var_s0->unk4);
        var_s0++;
    }
}

UnkChartreuseAngler* func_credits_801DDC0C(void) {
    UnkChartreuseAngler* var_v1;

    var_v1 = D_credits_801ECCB0;
    while (var_v1->unkC != 0) {
        if (var_v1->unk4 < -18.0f) {
            break;
        }

        var_v1++;
    }

    if (var_v1->unkC == 0) {
        return NULL;
    }

    return var_v1;
}

void func_credits_801DDC70(void) {
    UnkChartreuseAngler* var_s0;
    f32 var_f20;
    s16 var_s1;
    s32 temp_v0;

    var_f20 = 0.0f;
    var_s0 = D_credits_801ECCB0;

    for (var_s1 = 0; var_s1 < 0xE; var_s1++) {
        var_s0->unk4 = var_f20;
        var_s0->unk0 = 0xA0;
        var_f20 += 18.0f;
        func_8036D4A0_840C50(0);
        temp_v0 = func_8036AC6C_83E41C(var_s0->unk0, (s32) var_s0->unk4, 0xFC, 0xF, 0x400);
        var_s0->unkC = temp_v0;
        func_8036CB58_840308(temp_v0, 0xC);
        func_8036B734_83EEE4(var_s0->unkC);
        func_8036B9EC_83F19C(var_s0->unkC, 0, 0);
        func_8036B870_83F020(var_s0->unkC, 0, 0, 0, 0, 0);
        var_s0++;
    }
    var_s0->unkC = 0;
    var_s0->unk0 = 0;
    var_s0->unk4 = 0.0f;
}
