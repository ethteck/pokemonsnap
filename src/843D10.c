#include "common.h"

#include "sp.h"

void func_80371F30_8456E0(s32, s32, s32, s32);

#pragma GLOBAL_ASM("asm/nonmatchings/843D10/func_80370560_843D10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/843D10/func_80370578_843D28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/843D10/func_803705A4_843D54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/843D10/func_803705F0_843DA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/843D10/func_80370600_843DB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/843D10/func_8037060C_843DBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/843D10/func_80370780_843F30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/843D10/func_80370900_8440B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/843D10/func_80370990_844140.s")

#pragma GLOBAL_ASM("asm/nonmatchings/843D10/func_80370A14_8441C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/843D10/func_80370A48_8441F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/843D10/func_80370C34_8443E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/843D10/func_80370F34_8446E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/843D10/func_803713C8_844B78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/843D10/func_803713D4_844B84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/843D10/func_803713EC_844B9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/843D10/func_80371408_844BB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/843D10/func_8037147C_844C2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/843D10/func_8037154C_844CFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/843D10/func_8037161C_844DCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/843D10/func_8037172C_844EDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/843D10/func_80371738_844EE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/843D10/func_803717A8_844F58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/843D10/func_803717E8_844F98.s")

void func_803719B0_845160(SObj*, s32, s32, s32, s32, s32, s32);
#pragma GLOBAL_ASM("asm/nonmatchings/843D10/func_803719B0_845160.s")

void func_80371C0C_8453BC(GObj* gobj) {
    func_803719B0_845160(gobj->userData.sobj, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    func_80371F30_8456E0(0, SCREEN_WIDTH * 2 - 1, 0, SCREEN_HEIGHT * 2 - 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/843D10/func_80371C68_845418.s")

GObj* func_80371D14_8454C4(void (*gfxFunc)(GObj*), s32 arg1, Sprite* sprite) {
    GObj* gobj = func_8000A410(1 << arg1, 0, arg1 & 0xFF, arg1);

    if (gobj == NULL) {
        return NULL;
    }
    func_8000A8A4(gobj, func_80371C0C_8453BC, 0x1E, arg1, 0x40000000);
    func_8000A0B4(gobj, sprite);
    gobj->userData.rootNode->payloads[0] = NULL;
    gobj->userData.rootNode->payloads[1] = NULL;
    if (gfxFunc != NULL) {
        runGObjProcess(gobj, gfxFunc, 0, 0);
    }
    return gobj;
}

#pragma GLOBAL_ASM("asm/nonmatchings/843D10/func_80371DC0_845570.s")

#pragma GLOBAL_ASM("asm/nonmatchings/843D10/func_80371E68_845618.s")

#pragma GLOBAL_ASM("asm/nonmatchings/843D10/func_80371F30_8456E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/843D10/func_80371F54_845704.s")

#pragma GLOBAL_ASM("asm/nonmatchings/843D10/func_80373670_846E20.s")
