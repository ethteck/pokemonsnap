#include "common.h"
#include "sp.h"
#include "window.h"

extern Sprite D_80382CE0_856490;
extern Sprite D_803A1360_874B10;
extern Sprite D_803A1B10_8752C0;
extern Sprite D_803A22C0_875A70;
extern Sprite D_803A51A0_878950;
extern Bitmap D_803A6210_8799C0;
extern Sprite D_803A6220_8799D0;
extern Bitmap D_803A6390_879B40;
extern Bitmap D_803A6510_879CC0;

extern Bitmap* D_803A6564_879D14[];
extern s32 D_803A6604_879DB4;
extern s32 D_803A6608_879DB8;
extern s32 D_803A660C_879DBC;
extern UnkCanaryScallop* D_803A6610_879DC0;
extern s32 D_803A6614_879DC4;
extern s32 D_803A6618_879DC8;
extern f32 D_803A661C_879DCC;
extern f32 D_803A6620_879DD0;
extern s32 D_803A6624_879DD4;
extern f32 D_803A6628_879DD8;
extern s32 D_803A662C_879DDC;
extern s32 D_803A6630_879DE0;
extern f32 D_803A6634_879DE4;
extern s32 D_803A6648_879DF8; // xmin
extern s32 D_803A664C_879DFC; // ymin
extern s32 D_803A6650_879E00; // xmax
extern s32 D_803A6654_879E04; // ymax

extern GObj* D_803A6A80_87A230;
extern GObj* D_803A6A84_87A234;
extern GObj* D_803A6A88_87A238;
extern GObj* D_803A6A90_87A240[];
extern GObj* D_803A6B14_87A2C4;
extern f32 D_803A6B18_87A2C8[];
extern UnkCanaryScallop D_803A6BA0_87A350[];
extern s32 D_803A6BE8_87A398[];

void func_80370560_843D10(void) {
    D_803A6608_879DB8 = !D_803A6608_879DB8;
}

void func_80370578_843D28(void) {
    if (D_803A6614_879DC4 != 0) {
        D_803A6614_879DC4 = 0;
    } else {
        D_803A6614_879DC4 = 3;
    }
}

void func_803705A4_843D54(void) {
    while (D_803A6604_879DB4 != 2) {
        ohWait(1);
    }
}

void func_803705F0_843DA0(s32 arg0) {
    D_803A660C_879DBC = arg0 != 0;
}

UnkCanaryScallop* func_80370600_843DB0(void) {
    return D_803A6BA0_87A350;
}

void func_8037060C_843DBC(s32 arg0, s32 arg1) {
    s32 i;

    if (arg1 < 0) {
        arg1 = 0;
    } else if (arg1 > 32) {
        arg1 = 32;
    }

    for (i = 0; i <= 32; i++) {
        if (arg0 && i != arg1) {
            D_803A6A90_87A240[i]->data.sobj->sprite.red = 128;
            D_803A6A90_87A240[i]->data.sobj->sprite.green = 128;
            D_803A6A90_87A240[i]->data.sobj->sprite.blue = 128;
        } else {
            D_803A6A90_87A240[i]->data.sobj->sprite.red = 255;
            D_803A6A90_87A240[i]->data.sobj->sprite.green = 255;
            D_803A6A90_87A240[i]->data.sobj->sprite.blue = 255;
        }
    }
}

void func_80370780_843F30(s32 arg0, s32 arg1) {
    s32 i;

    if (arg1 < 0) {
        arg1 = 0;
    } else if (arg1 > 32) {
        arg1 = 32;
    }

    for (i = 0; i <= 32; i++) {
        if (i == arg1) {
            if (arg0) {
                D_803A6A90_87A240[i]->data.sobj->sprite.red = 128;
                D_803A6A90_87A240[i]->data.sobj->sprite.green = 128;
                D_803A6A90_87A240[i]->data.sobj->sprite.blue = 128;
            } else {
                D_803A6A90_87A240[i]->data.sobj->sprite.red = 255;
                D_803A6A90_87A240[i]->data.sobj->sprite.green = 255;
                D_803A6A90_87A240[i]->data.sobj->sprite.blue = 255;
            }
        }
    }
}

void func_80370900_8440B0(s32 arg0, s32 arg1) {
    s32 i;

    if (arg1 < 0) {
        arg1 = 0;
    } else if (arg1 > 32) {
        arg1 = 32;
    }

    if (arg0) {
        D_803A6A90_87A240[arg1]->data.sobj->sprite.alpha = 255;
        D_803A6A90_87A240[arg1]->data.sobj->sprite.attr &= ~SP_HIDDEN;
    } else {
        D_803A6A90_87A240[arg1]->data.sobj->sprite.alpha = 0;
        D_803A6A90_87A240[arg1]->data.sobj->sprite.attr |= SP_HIDDEN;
    }
}

void func_80370990_844140(f32 arg0, s32 arg1) {
    s32 i;

    if (arg1 < 0) {
        arg1 = 0;
    } else if (arg1 > 32) {
        arg1 = 32;
    }

    D_803A6A90_87A240[arg1]->data.sobj->sprite.scaley = arg0;
    if (arg0 == 1.0) {
        D_803A6A90_87A240[arg1]->data.sobj->sprite.attr &= ~SP_SCALE;
    } else {
        D_803A6A90_87A240[arg1]->data.sobj->sprite.attr |= SP_SCALE;
    }
}

void func_80370A14_8441C4(UnkCanaryScallop* arg0, char* arg1, s32 arg2) {
    while (arg0->unk_00 != 35) {
        if (arg0->unk_00 == arg2) {
            arg0->unk_04 = arg1;
        }
        arg0++;
    }
}

void func_80370A48_8441F8(void) {
    UnkCanaryScallop* tab;
    f32 f0;

    if (D_803A6610_879DC0 == NULL) {
        return;
    }

    while (D_803A6604_879DB4 != 2) {
        ohWait(1);
    }

    tab = D_803A6610_879DC0;
    while (tab->unk_00 != 35) {
        if (tab->unk_00 <= 32) {
        }
        tab++;
    }

    tab = D_803A6610_879DC0;
    f0 = (D_803A6614_879DC4 + 1) * PI_2;

    while (tab->unk_00 != 35) {
        if (tab->unk_00 <= 32) {
            GObj* obj = D_803A6A90_87A240[tab->unk_00];

            obj->data.sobj->sprite.attr |= SP_SCALE;
            if (D_803A6608_879DB8) {
                obj->data.sobj->sprite.scalex = 1.0f;
            } else {
                obj->data.sobj->sprite.scaley = 1.0f;
            }

            if (D_803A6608_879DB8) {
                obj->data.sobj->unk_54 = obj->data.sobj->sprite.x;
            } else {
                obj->data.sobj->unk_54 = obj->data.sobj->sprite.y;
            }

            if (D_803A660C_879DBC) {
                D_803A6B18_87A2C8[tab->unk_00] = 0.0f;
                do {
                } while (0); // required to match
            } else {
                D_803A6B18_87A2C8[tab->unk_00] = f0;
                f0 -= (f32) (D_803A6614_879DC4 * 90.0 / 9.0) * PI / 180.0f;
            }
        }
        tab++;
    }

    D_803A6604_879DB4 = 0;
    D_803A6610_879DC0 = NULL;
}

void func_80370C34_8443E4(UnkCanaryScallop* arg0) {
    UnkCanaryScallop* tab;
    s32 i;
    s32 numTabs, tab34_pos;
    f32 f0;

    if (D_803A6610_879DC0 != NULL) {
        if (arg0 == D_803A6610_879DC0) {
            return;
        }
        func_80370A48_8441F8();
        while (D_803A6604_879DB4 != 2) {
            ohWait(1);
        }
    }

    for (i = 0; i < 8; i++) {
        D_803A6BA0_87A350[i].unk_00 = 35;
        D_803A6BE8_87A398[i] = 0;
    }

    numTabs = 0;
    tab34_pos = 0;
    tab = arg0;
    while (tab->unk_00 != 35) {
        if (tab->unk_00 <= 32) {
            numTabs++;
        }
        if (tab->unk_00 == 34) {
            tab34_pos = tab - arg0;
        }
        tab++;
    }

    tab = arg0;
    f0 = 0.0f;
    i = 0;

    while (tab->unk_00 != 35) {
        if (tab->unk_00 <= 32) {
            GObj* obj = D_803A6A90_87A240[tab->unk_00];

            obj->data.sobj->sprite.attr |= SP_SCALE;
            obj->data.sobj->sprite.attr |= SP_HIDDEN;
            if (D_803A6608_879DB8) {
                obj->data.sobj->sprite.scalex = 1.0f;
            } else {
                obj->data.sobj->sprite.scaley = 1.0f;
            }

            obj->data.sobj->sprite.x = 0;
            obj->data.sobj->sprite.y = 25 + i * 24;

            if (D_803A6608_879DB8) {
                obj->data.sobj->unk_54 = obj->data.sobj->sprite.x;
            } else {
                obj->data.sobj->unk_54 = obj->data.sobj->sprite.y;
            }

            if (D_803A660C_879DBC) {
                D_803A6B18_87A2C8[tab->unk_00] = PI_2;
                obj->data.sobj->sprite.attr &= ~SP_HIDDEN;
            } else {
                D_803A6B18_87A2C8[tab->unk_00] = f0;
                f0 -= (f32) (D_803A6614_879DC4 * 90.0 / 9.0) * PI / 180.0f;
            }
            D_803A6BA0_87A350[i++].unk_00 = tab->unk_00;
        } else if (tab->unk_00 == 34) {
            i = tab34_pos - numTabs + 8;
        }
        tab++;
    }

    D_803A6604_879DB4 = 1;
    D_803A6610_879DC0 = arg0;
}

// #pragma GLOBAL_ASM("asm/nonmatchings/window/843D10/func_80370F34_8446E4.s")
void func_80370F34_8446E4(GObj* unused) {
    s32 i;
    GObj* obj;
    s32 s4 = 0;

    while (true) {
        for (i = 0; i <= 32; i++) {
            obj = D_803A6A90_87A240[i];
            if (D_803A6604_879DB4 == 1) {
                if ((obj->data.sobj->sprite.attr ^ 0x4) & 0x14) {
                    D_803A6B18_87A2C8[i] += (f32)((D_803A6614_879DC4 + 1) * 90.0 / 30.0) / PI * 180.0f;
                    if (D_803A660C_879DBC) {
                        D_803A6B18_87A2C8[i] = PI_2;
                    }
                    if (D_803A6B18_87A2C8[i] >= PI_2) {
                        D_803A6B18_87A2C8[i] = PI_2;
                    } else {

                    }
                }
            } else {
            }
        }
        if (s4 == 0) {
            D_803A6604_879DB4 = 2;
        }
        s4 = 0;
        ohWait(1);
    }
}

void func_803713C8_844B78(s32 arg0) {
    D_803A6618_879DC8 = arg0;
}

void func_803713D4_844B84(s32 arg0) {
    D_803A6618_879DC8 |= arg0;
}

void func_803713EC_844B9C(s32 arg0) {
    D_803A6618_879DC8 &= ~arg0;
}

void func_80371408_844BB8(GObj* arg0) {
    f32 var_f0;
    f32 tmp;

    if (D_803A6618_879DC8 & 4) {
        var_f0 = 0.0f;
    } else {
        var_f0 = -40.0f;
    }
    tmp = D_803A661C_879DCC;
    tmp += (var_f0 - tmp) * 0.2;
    arg0->data.sobj->sprite.y = tmp;
    var_f0 = tmp;
    if (1) {
    }
    D_803A661C_879DCC = var_f0;
}

void func_8037147C_844C2C(GObj* arg0) {
    f32 var_f0;
    f32 tmp;
    s32 tmp2;
    s32 tmp3;
    s32 tmp4;
    s32 tmp5;

    if (D_803A6618_879DC8 & 1) {
        var_f0 = 0.0f;
    } else {
        var_f0 = -40.0f;
    }
    tmp3 = D_803A6624_879DD4 + 1;
    tmp = D_803A6620_879DD0;
    tmp2 = tmp3;
    tmp = tmp + (var_f0 - tmp) * 0.2;

    arg0->data.sobj->sprite.y = tmp;
    var_f0 = tmp;
    if (1) {
    }
    D_803A6620_879DD0 = var_f0;

    if (tmp2 < 0) {
        arg0->data.sobj->unk_58->sprite.bitmap = &D_803A6390_879B40;
    } else {
        arg0->data.sobj->unk_58->sprite.bitmap = &D_803A6210_8799C0;
    }
    D_803A6624_879DD4 = (unsigned long long) tmp2;
    tmp4 = 48;
    if (tmp2 > tmp4) {
        tmp4 = -tmp4;
        tmp5 = tmp4;
        if (1) {
            D_803A6624_879DD4 = tmp5;
        }
    }
}

void func_8037154C_844CFC(GObj* arg0) {
    f32 var_f0;
    f32 tmp;
    s32 tmp2;
    s32 tmp3;
    s32 tmp4;
    s32 tmp5;

    if (D_803A6618_879DC8 & 2) {
        var_f0 = 0.0f;
    } else {
        var_f0 = -40.0f;
    }
    tmp3 = D_803A662C_879DDC + 1;
    tmp = D_803A6628_879DD8;
    tmp2 = tmp3;
    tmp = tmp + (var_f0 - tmp) * 0.2;

    arg0->data.sobj->sprite.y = tmp;
    var_f0 = tmp;
    if (1) {
    }
    D_803A6628_879DD8 = var_f0;

    if (tmp2 < 0) {
        arg0->data.sobj->unk_58->sprite.bitmap = &D_803A6510_879CC0;
    } else {
        arg0->data.sobj->unk_58->sprite.bitmap = &D_803A6210_8799C0;
    }
    D_803A662C_879DDC = (unsigned long long) tmp2;
    tmp4 = 48;
    if (tmp2 > tmp4) {
        tmp4 = -tmp4;
        tmp5 = tmp4;
        if (1) {
            D_803A662C_879DDC = tmp5;
        }
    }
}

void func_8037161C_844DCC(void) {
    GObj* obj;
    SObj* sobj;

    obj = func_80371C68_845418(func_8037147C_844C2C, 6, &D_803A1B10_8752C0);
    obj->data.sobj->sprite.x = 96;
    obj->data.sobj->sprite.y = -40;
    sobj = func_80371E68_845618(obj->data.sobj, &D_803A6220_8799D0);
    sobj->sprite.x = 9;
    sobj->sprite.y = 22;
    D_803A6A80_87A230 = obj;

    obj = func_80371C68_845418(func_8037154C_844CFC, 6, &D_803A22C0_875A70);
    obj->data.sobj->sprite.x = 280;
    obj->data.sobj->sprite.y = -40;
    sobj = func_80371E68_845618(obj->data.sobj, &D_803A6220_8799D0);
    sobj->sprite.x = 3;
    sobj->sprite.y = 22;
    D_803A6A84_87A234 = obj;

    obj = func_80371C68_845418(func_80371408_844BB8, 6, &D_803A51A0_878950);
    obj->data.sobj->sprite.x = 124;
    obj->data.sobj->sprite.y = -40;
    D_803A6A88_87A238 = obj;
}

void func_8037172C_844EDC(s32 arg0) {
    D_803A6630_879DE0 = arg0;
}

void func_80371738_844EE8(GObj* arg0) {
    f32 var_f0;
    f32 tmp;

    if (D_803A6630_879DE0) {
        var_f0 = 0.0f;
    } else {
        var_f0 = -180.0f;
    }
    tmp = D_803A6634_879DE4;
    tmp += (var_f0 - tmp) * 0.15;
    arg0->data.sobj->sprite.x = tmp;
    var_f0 = tmp;
    if (1) {
    }
    D_803A6634_879DE4 = var_f0;
}

char* func_803717A8_844F58(UnkCanaryScallop* arg0, s32 arg1) {
    while (arg0->unk_00 != 35) {
        if (arg1 == arg0->unk_00) {
            return arg0->unk_04;
        }
        arg0++;
    }
    return "";
}

void func_803717E8_844F98(void) {
    GObj* obj;
    GObj* tabObj;
    s32 i;

    obj = func_80371C68_845418(func_80371738_844EE8, 6, &D_803A1360_874B10);
    obj->data.sobj->sprite.x = -180;
    obj->data.sobj->sprite.y = 0;
    obj->data.sobj->sprite.attr |= SP_SCALE | SP_TRANSPARENT;
    obj->data.sobj->sprite.scalex = 23.0f;
    obj->data.sobj->sprite.scaley = 60.0f;
    obj->data.sobj->sprite.alpha = 178;
    D_803A6B14_87A2C4 = obj;

    for (i = 0; i <= 32; i++) {
        tabObj = func_80371D14_8454C4(i != 0 ? NULL : func_80370F34_8446E4, 6, &D_80382CE0_856490);
        tabObj->data.sobj->sprite.bitmap = D_803A6564_879D14[i];
        tabObj->data.sobj->sprite.x = 0;
        tabObj->data.sobj->sprite.y = 20 + i * 30;
        tabObj->data.sobj->sprite.attr &= ~SP_SCALE;
        tabObj->data.sobj->sprite.attr |= SP_HIDDEN;
        tabObj->data.sobj->sprite.scalex = 1.0f;
        tabObj->data.sobj->sprite.scaley = 1.0f;
        D_803A6A90_87A240[i] = tabObj;
        D_803A6B18_87A2C8[i] = 0.0001f;
    }

    D_803A6604_879DB4 = 2;
    D_803A6610_879DC0 = 0;
    func_8037161C_844DCC();
}

// split file ?

void func_803719B0_845160(SObj* arg0, s32 x, s32 y, s32 r, s32 g, s32 b, s32 a) {
    s32 origX;
    s32 origY;
    u32 origR;
    u32 origG;
    u32 origB;
    u32 origA;

    while (arg0 != NULL) {
        if (!(arg0->sprite.attr & SP_HIDDEN)) {
            origX = arg0->sprite.x;
            origY = arg0->sprite.y;
            origR = arg0->sprite.red;
            origG = arg0->sprite.green;
            origB = arg0->sprite.blue;
            origA = arg0->sprite.alpha;
            arg0->sprite.rsp_dl_next = gMainGfxPos[0];
            arg0->sprite.x += x;
            arg0->sprite.y += y;
            if (!(arg0->sprite.attr & 0x4000)) {
                arg0->sprite.red = (arg0->sprite.red * r) / 255;
                arg0->sprite.green = (arg0->sprite.green * g) / 255;
                arg0->sprite.blue = (arg0->sprite.blue * b) / 255;
                arg0->sprite.alpha = (arg0->sprite.alpha * a) / 255;
            }
            func_80373670_846E20(&arg0->sprite);
            *gMainGfxPos = arg0->sprite.rsp_dl_next - 1;
            if (arg0->unk_58 != NULL) {
                func_803719B0_845160(
                    arg0->unk_58,
                    arg0->sprite.x, arg0->sprite.y,
                    arg0->sprite.red, arg0->sprite.green, arg0->sprite.blue, arg0->sprite.alpha);
            }
            arg0->sprite.x = origX;
            arg0->sprite.y = origY;
            arg0->sprite.red = origR;
            arg0->sprite.green = origG;
            arg0->sprite.blue = origB;
            arg0->sprite.alpha = origA;
        }
        arg0 = arg0->next;
    }
}

void func_80371C0C_8453BC(GObj* gobj) {
    func_803719B0_845160(gobj->data.sobj, 0, 0, 255, 255, 255, 255);
    func_80371F30_8456E0(0, SCREEN_WIDTH * 2 - 1, 0, SCREEN_HEIGHT * 2 - 1);
}

GObj* func_80371C68_845418(void (*func)(GObj*), s32 link, Sprite* sprite) {
    GObj* obj;

    obj = omAddGObj(1 << link, 0, link, link);
    if (obj == NULL) {
        return NULL;
    }
    omLinkGObjDL(obj, func_80371C0C_8453BC, 30, link, 0x40000000);
    omGObjAddSprite(obj, sprite);
    obj->data.sobj->unk_58 = NULL;
    obj->data.sobj->unk_5C = NULL;
    if (func != NULL) {
        omCreateProcess(obj, func, 1, 0);
    }
    return obj;
}

GObj* func_80371D14_8454C4(void (*func)(GObj*), s32 link, Sprite* sprite) {
    GObj* obj;

    obj = omAddGObj(1 << link, 0, link, link);
    if (obj == NULL) {
        return NULL;
    }
    omLinkGObjDL(obj, func_80371C0C_8453BC, 30, link, 0x40000000);
    omGObjAddSprite(obj, sprite);
    obj->data.sobj->unk_58 = NULL;
    obj->data.sobj->unk_5C = NULL;
    if (func != NULL) {
        omCreateProcess(obj, func, 0, 0);
    }
    return obj;
}

SObj* func_80371DC0_845570(SObj* arg0, Sprite* arg1) {
    SObj* temp_v0;

    temp_v0 = omGetSObj();
    if (arg0->next != NULL) {
        arg0->next->prev = temp_v0;
    }
    temp_v0->prev = arg0;
    temp_v0->next = arg0->next;
    arg0->next = temp_v0;
    temp_v0->obj = arg0->obj;
    temp_v0->unk_5C = arg0->unk_5C;
    temp_v0->unk_58 = NULL;
    temp_v0->sprite = *arg1;
    temp_v0->unk_54 = 0;
    return temp_v0;
}

SObj* func_80371E68_845618(SObj* arg0, Sprite* arg1) {
    SObj* temp_v0;
    SObj* var_a0;
    SObj* var_v1;

    temp_v0 = omGetSObj();
    if (arg0->unk_58 != NULL) {
        var_a0 = arg0->unk_58;
        var_v1 = arg0->unk_58->next;
        while (var_v1 != NULL) {
            var_a0 = var_v1;
            var_v1 = var_v1->next;
        }
        var_a0->next = temp_v0;
        temp_v0->prev = var_a0;
    } else {
        arg0->unk_58 = temp_v0;
        temp_v0->prev = NULL;
    }
    temp_v0->obj = arg0->obj;
    temp_v0->unk_5C = arg0;
    temp_v0->unk_58 = NULL;
    temp_v0->next = NULL;
    temp_v0->sprite = *arg1;
    temp_v0->unk_54 = 0;
    return temp_v0;
}

void func_80371F30_8456E0(s32 xMin, s32 xMax, s32 yMin, s32 yMax) {
    D_803A6648_879DF8 = xMin;
    D_803A664C_879DFC = yMin;
    D_803A6650_879E00 = xMax;
    D_803A6654_879E04 = yMax;
}

#pragma GLOBAL_ASM("asm/nonmatchings/window/843D10/func_80371F54_845704.s")
