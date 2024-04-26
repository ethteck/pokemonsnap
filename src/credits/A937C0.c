#include "common.h"

typedef struct UnkChartreuseAngler {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ void* unk8;
    /* 0x0C */ s32 unkC;
} UnkChartreuseAngler; // size: 0x80

typedef struct UnkCitronCod {
    /* 0x00 */ u8 pad0[0x44];
    /* 0x44 */ UnkChartreuseAngler* unk44;
} UnkCitronCod;

extern Sprite D_credits_801E8B50;
extern GObj* D_credits_801ECCA0;
extern GObj* D_credits_801ECC80;
extern GObj* D_credits_801ECC98;
extern GObj* D_credits_801ECC9C;

extern u8 D_credits_801ECDA4;
extern s32 D_credits_801ED010;

void func_credits_801DCAF8(SObj*); /* extern */
GObj* func_credits_801DCC00(GObj*, Sprite*);
void func_credits_801DD8C0(SObj*);
void func_credits_801DEB74(void*, float);
void func_credits_801DEA30(void*, float);
void func_credits_801DCEF0(GObj*);
void func_credits_801DE8A0(SObj*, s32);
s32 func_credits_801DE8D8();
void func_credits_801DD540(GObj*); /* extern */

GObj* func_credits_801DCC00(GObj* arg0, Sprite* arg1) {
    return ohCreateSprite(0xE, ohUpdateDefault, 0, 0x80000000, renDrawSprite, 1U, 0x80000000, -1, arg1, 0U, NULL, 1);
}

extern Sprite D_credits_801E6058;
extern Sprite D_credits_801E6430;
extern Sprite D_credits_801E67D8;

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
        list = (Bitmap *)func_8036A194_83D944(sizeof (Bitmap) * 8);

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

#pragma GLOBAL_ASM("asm/nonmatchings/credits/A937C0/func_credits_801DD428.s")

#pragma GLOBAL_ASM("asm/nonmatchings/credits/A937C0/func_credits_801DD49C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/credits/A937C0/func_credits_801DD540.s")

void func_credits_801DD744(void) {
    ohEndAllObjectProcesses(D_credits_801ECC98);
    ohEndAllObjectProcesses(D_credits_801ECC9C);
    omCreateProcess(D_credits_801ECC98, func_credits_801DD540, 0U, 1U);
}

void func_credits_801DD49C(GObj*); /* extern */
extern Sprite D_credits_801E6AA8;

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
    arg0->sprite.attr = 0x201;
}

#pragma GLOBAL_ASM("asm/nonmatchings/credits/A937C0/func_credits_801DD848.s")

#pragma GLOBAL_ASM("asm/nonmatchings/credits/A937C0/func_credits_801DD8C0.s")

void func_credits_801DD930(SObj* arg0) {
    arg0->sprite.attr = 0x201;
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

#pragma GLOBAL_ASM("asm/nonmatchings/credits/A937C0/func_credits_801DD980.s")

#pragma GLOBAL_ASM("asm/nonmatchings/credits/A937C0/func_credits_801DDA60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/credits/A937C0/func_credits_801DDAE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/credits/A937C0/func_credits_801DDB60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/credits/A937C0/func_credits_801DDC0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/credits/A937C0/func_credits_801DDC70.s")
