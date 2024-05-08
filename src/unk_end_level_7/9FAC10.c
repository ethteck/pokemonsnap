#include "common.h"
#include "unk_end_level_7.h"

void func_801DCF50_9FAC10(UNK_PTR arg0) {
    s32 sp24;

    while (TRUE) {
        if (D_801EA1F4_A07EB4 != 0) {
            sp24 = contIsPrinterAvailable();
            if (D_801EA200_A07EC0 != sp24) {
                D_801EA1F8_A07EB8 |= 2;
                func_80370C34_8443E4(func_801DF850_9FD510());

                func_80370780_843F30(contIsPrinterAvailable() ? 0 : 1, 0x20);
            } else {
                D_801EA1F8_A07EB8 &= ~2;
            }
            D_801EA200_A07EC0 = sp24;
            if (sp24 != 0) {
                D_801EA1F8_A07EB8 |= 1;
            } else {
                D_801EA1F8_A07EB8 &= ~1;
            }
        }
        ohWait(1);
    }
}

void func_801DD074_9FAD34(u32 arg0) {
    UNUSED s32 pad;
    D_8023086C_A4E52C->sprite.red = arg0;
    D_8023086C_A4E52C->sprite.green = arg0;
    D_8023086C_A4E52C->sprite.blue = arg0;
}

void func_801DD0AC_9FAD6C(s32 arg0) {
    s32 i;

    for (i = 0; i < 4; i++) {
        // TODO: create a macro for setting R/G/B to the same value
        D_80230848_A4E508[i].unk_0->data.sobj->sprite.red = D_80230848_A4E508[i].unk_0->data.sobj->sprite.green = D_80230848_A4E508[i].unk_0->data.sobj->sprite.blue = arg0;
    }

    for (i = 0; i < 6; i++) {
        D_80230818_A4E4D8[i].unk_0->data.sobj->sprite.red = D_80230818_A4E4D8[i].unk_0->data.sobj->sprite.green = D_80230818_A4E4D8[i].unk_0->data.sobj->sprite.blue = arg0;
    }
}

UnkStruct800BEDF8* func_801DD1A8_9FAE68(void) {
    UnkStruct800BEDF8* sp24;

    func_803700A4_843854(0);
    func_801DE04C_9FBD0C(-1, -1);
    func_8036D4A0_840C50(0);
    func_801DDCA8_9FB968(0xD);

    while (TRUE) {
        ohWait(1);
        sp24 = func_800AA38C(0);
        if (sp24->unk_18 & 0x4000) {
            func_801DDCA8_9FB968(8);
            break;
        }
        if (sp24->unk_18 & 0x8000) {
            auPlaySoundWithParams(0xA0, 0x7FFF, 0x40, 0.75f, 0);
            func_801DDCA8_9FB968(0xA);
            break;
        }
    }

    return sp24;
}

void func_801DD270_9FAF30(void) {
    D_801EA1FC_A07EBC = 0x18;
}

GObj* func_801DD28C_9FAF4C(s32 arg0) {
    GObj* gobj;
    SObj* sobj;
    s32 x;
    s32 y;
    Bitmap* bitmap;
    u8* dest;
    u8* src;

    x = ((arg0 % 3) * 66) + 104;
    y = ((arg0 / 3) * 55) + 53;

    gobj = func_80371C68_845418(NULL, 6, &D_801E82A0_A05F60);
    sobj = gobj->data.sobj;
    sobj->sprite.x = x;
    sobj->sprite.y = y;
    D_80230818_A4E4D8[arg0].unk_0 = gobj;

    sobj = func_80371E68_845618(sobj, &D_801E82A0_A05F60);
    sobj->sprite.x = 0x36;
    sobj->sprite.y = 0;

    sobj = func_80371DC0_845570(sobj, &D_801E83D0_A06090);
    sobj->sprite.x = 2;
    sobj->sprite.y = 0;

    sobj = func_80371DC0_845570(sobj, &D_801E83D0_A06090);
    sobj->sprite.x = 2;
    sobj->sprite.y = 0x29;

    sobj = func_80371DC0_845570(sobj, &D_801EA1B0_A07E70);
    sobj->sprite.x = 2;
    sobj->sprite.y = 2;
    D_80230818_A4E4D8[arg0].unk_4 = sobj;

    bitmap = (Bitmap*) func_8036A194_83D944(0x10);
    dest = (u8*) func_8036A194_83D944(0xFD8);
    src = sobj->sprite.bitmap->buf;
    *bitmap = *sobj->sprite.bitmap;
    bitmap->buf = dest;
    sobj->sprite.bitmap = bitmap;
    for (x = 0xFD8; x > 0; src++, dest++, x--) {
        *dest = *src;
    }

    return gobj;
}

GObj* func_801DD4C4_9FB184(s32 arg0) {
    GObj* gobj;
    SObj* sobj;
    s32 x;
    s32 y;
    Bitmap* bitmap;
    u8* dest;
    u8* src;

    x = ((arg0 % 2) * 0x42) + 0x89;
    y = ((arg0 / 2) * 0x37) + 0x35;

    gobj = func_80371C68_845418(NULL, 6, &D_801E82A0_A05F60);
    sobj = gobj->data.sobj;
    sobj->sprite.x = x;
    sobj->sprite.y = y;
    D_80230848_A4E508[arg0].unk_0 = gobj;

    sobj = func_80371E68_845618(sobj, &D_801E82A0_A05F60);
    sobj->sprite.x = 0x36;
    sobj->sprite.y = 0;

    sobj = func_80371DC0_845570(sobj, &D_801E83D0_A06090);
    sobj->sprite.x = 2;
    sobj->sprite.y = 0;

    sobj = func_80371DC0_845570(sobj, &D_801E83D0_A06090);
    sobj->sprite.x = 2;
    sobj->sprite.y = 0x29;

    sobj = func_80371DC0_845570(sobj, &D_801EA1B0_A07E70);
    sobj->sprite.x = 2;
    sobj->sprite.y = 2;
    D_80230848_A4E508[arg0].unk_4 = sobj;

    bitmap = (Bitmap*) func_8036A194_83D944(0x10);
    dest = (u8*) func_8036A194_83D944(0xFD8);
    src = sobj->sprite.bitmap->buf;
    *bitmap = *sobj->sprite.bitmap;
    bitmap->buf = dest;
    sobj->sprite.bitmap = bitmap;
    for (x = 0xFD8; x > 0; src++, dest++, x--) {
        *dest = *src;
    }

    return gobj;
}

void func_801DD708_9FB3C8(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        func_801DD4C4_9FB184(i);
    }

    for (i = 0; i < 6; i++) {
        func_801DD28C_9FAF4C(i);
    }
}

void func_801DD768_9FB428(s32 arg0) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (arg0 == 0) {
            D_80230848_A4E508[i].unk_0->data.sobj->sprite.attr &= ~SP_HIDDEN;
        } else {
            D_80230848_A4E508[i].unk_0->data.sobj->sprite.attr |= SP_HIDDEN;
        }
    }

    for (i = 0; i < 6; i++) {
        if (arg0 == 1) {
            D_80230818_A4E4D8[i].unk_0->data.sobj->sprite.attr &= ~SP_HIDDEN;
        } else {
            D_80230818_A4E4D8[i].unk_0->data.sobj->sprite.attr |= SP_HIDDEN;
        }
    }
}

void func_801DD860_9FB520(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (func_801E0F88_9FEC48(i)) {
            D_80230848_A4E508[i].unk_0->data.sobj->sprite.attr &= ~SP_HIDDEN;
        } else {
            D_80230848_A4E508[i].unk_0->data.sobj->sprite.attr |= SP_HIDDEN;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_7/9FAC10/func_801DD8F8_9FB5B8.s")

void func_801DDC50_9FB910(s32 arg0) {
    func_80374714_847EC4(func_801E0F88_9FEC48(arg0), &D_80230848_A4E508[arg0].unk_4->sprite);
}

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_7/9FAC10/func_801DDCA8_9FB968.s")

void func_801DE04C_9FBD0C(s32 arg0, s32 arg1) {
    SObj* sobj;

    sobj = D_80230870_A4E530->data.sobj;
    if ((arg0 < 0) || (arg1 < 0)) {
        sobj->sprite.attr |= 4;
    } else {
        SET_SPRITE_POS(sobj->sprite, arg0, arg1);
        sobj->sprite.attr &= ~4;
    }
}

GObj* func_801DE0B8_9FBD78() {
    GObj* gobj;
    SObj* sobj;
    s32 i;
    Bitmap* bitmap;
    u8* dest;
    u8* src;

    gobj = func_80371C68_845418(NULL, 6, &D_801E82A0_A05F60);
    sobj = gobj->data.sobj;
    sobj->sprite.x = 0;
    sobj->sprite.y = 0;
    sobj->sprite.attr |= SP_HIDDEN;

    sobj = func_80371E68_845618(sobj, &D_801E82A0_A05F60);
    sobj->sprite.x = 0x36;
    sobj->sprite.y = 0;

    sobj = func_80371DC0_845570(sobj, &D_801E83D0_A06090);
    sobj->sprite.x = 2;
    sobj->sprite.y = 0;

    sobj = func_80371DC0_845570(sobj, &D_801E83D0_A06090);
    sobj->sprite.x = 2;
    sobj->sprite.y = 0x29;

    sobj = func_80371DC0_845570(sobj, &D_801EA1B0_A07E70);
    sobj->sprite.x = 2;
    sobj->sprite.y = 2;
    D_80230870_A4E530 = gobj;
    D_80230874_A4E534 = sobj;

    bitmap = (Bitmap*) func_8036A194_83D944(0x10);
    dest = (u8*) func_8036A194_83D944(0xFD8);
    src = sobj->sprite.bitmap->buf;
    *bitmap = *sobj->sprite.bitmap;
    bitmap->buf = dest;
    sobj->sprite.bitmap = bitmap;
    for (i = 0xFD8; i > 0; src++, dest++, i--) {
        *dest = *src;
    }

    return gobj;
}

void func_801DE290_9FBF50(s32 arg0) {
    if (arg0) {
        D_80230870_A4E530->data.sobj->sprite.attr &= ~4;
    } else {
        D_80230870_A4E530->data.sobj->sprite.attr |= 4;
    }
}

void func_801DE2E0_9FBFA0(PhotoData* arg0) {
    func_80374714_847EC4(arg0, &D_80230874_A4E534->sprite);
}

void func_801DE318_9FBFD8(s32 arg0) {
    switch (arg0) {
        case 0:
            D_8023086C_A4E52C->sprite = D_801E8FB0_A06C70;
            break;
        case 1:
            D_8023086C_A4E52C->sprite = D_801E8890_A06550;
            break;
        case 2:
            D_8023086C_A4E52C->sprite = D_801E8D50_A06A10;
            break;
    }
    D_80230868_A4E528->data.sobj->unk_58 = NULL;

    // TODO: figure out what field this is. SObj's size should match the SceneSetup field
    *(s32*) ((uintptr_t) D_80230868_A4E528->data.sobj + sizeof(SObj)) = 0;

    D_80230868_A4E528->data.sobj->sprite.width = SCREEN_WIDTH;
    D_80230868_A4E528->data.sobj->sprite.height = SCREEN_HEIGHT;
    D_80230868_A4E528->data.sobj->sprite.istep = 0;
}
void func_801DE4A0_9FC160(void) {
    s32 i;

    for (i = 10; i >= 0; i--) {
        func_801DD0AC_9FAD6C((i * 0xFF) / 10);
        func_801DD074_9FAD34((i * 0xFF) / 10);
        ohWait(1);
    }
    func_801DD074_9FAD34(0U);
    func_801DD0AC_9FAD6C(0);
}

void func_801DE538_9FC1F8(void) {
    s32 i;

    for (i = 0; i < 10; i++) {
        func_801DD074_9FAD34((i * 0xFF) / 10);
        func_801DD0AC_9FAD6C((i * 0xFF) / 10);
        ohWait(1);
    }

    func_801DD074_9FAD34(0xFF);
    func_801DD0AC_9FAD6C(0xFF);
}

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_7/9FAC10/func_801DE5D0_9FC290.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_7/9FAC10/func_801DE804_9FC4C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_7/9FAC10/func_801DE87C_9FC53C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_7/9FAC10/func_801DEE88_9FCB48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_7/9FAC10/func_801DF078_9FCD38.s")

void func_801DF788_9FD448(void) {
    GObj* obj;
    SObj* sobj;

    D_80230890_A4E550 = func_801DC904_9FA5C4();
    func_800A85E8(func_801DF078_9FCD38, 6, 0, 0);
    func_800A85E8(func_801DCF50_9FAC10, 6, 0, 0);
    obj = func_80371D14_8454C4(NULL, 6, &D_801E8FB0_A06C70);
    sobj = obj->data.sobj;
    sobj->sprite.width = SCREEN_WIDTH;
    sobj->sprite.height = SCREEN_HEIGHT;
    sobj->sprite.istep = 0;
    D_80230868_A4E528 = obj;
    D_8023086C_A4E52C = sobj;
    func_801DD074_9FAD34(0);
}
