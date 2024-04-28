#include "common.h"

extern char D_801C5EB4_98B6D4[];
extern char D_801C5EDC_98B6FC[];
extern char D_801C5F20_98B740[];
extern char D_801C5F54_98B774[];
extern char D_801C5FA4_98B7C4[];
extern char D_801C5FE4_98B804[];
extern char D_801C6028_98B848[];
extern char D_801C6054_98B874[];
extern char D_801C6090_98B8B0[];
extern char D_801C60DC_98B8FC[];
extern char D_801C6138_98B958[];
extern char D_801C616C_98B98C[];
extern char D_801C61C8_98B9E8[];
extern char D_801C6200_98BA20[];
extern char D_801C6248_98BA68[];
extern char D_801C6284_98BAA4[];
extern char D_801C62BC_98BADC[];
extern char D_801C62EC_98BB0C[];
extern char D_801C6334_98BB54[];
extern char D_801C6360_98BB80[];
extern char D_801C6398_98BBB8[];
extern char D_801C63F4_98BC14[];
extern char D_801C6428_98BC48[];
extern char D_801C6454_98BC74[];
extern char D_801C648C_98BCAC[];
extern char D_801C64DC_98BCFC[];
extern char D_801C6528_98BD48[];
extern char D_801C657C_98BD9C[];
extern char D_801C65D8_98BDF8[];
extern char D_801C65E8_98BE08[];
extern char D_801C664C_98BE6C[];
extern char D_801C6688_98BEA8[];
extern char D_801C66C0_98BEE0[];
extern char D_801C66EC_98BF0C[];
extern char D_801C6738_98BF58[];
extern char D_801C6770_98BF90[];
extern char D_801C67B8_98BFD8[];
extern char D_801C67FC_98C01C[];
extern char D_801C6820_98C040[];
extern char D_801C685C_98C07C[];
extern char D_801C6880_98C0A0[];
extern char D_801C68D8_98C0F8[];
extern char D_801C692C_98C14C[];
extern char D_801C6968_98C188[];
extern char D_801C69AC_98C1CC[];
extern char D_801C69E0_98C200[];
extern char D_801C6A18_98C238[];
extern char D_801C6A50_98C270[];

s32 D_80195D10 = 0;
s32 D_80195D14 = 0;

s32 func_800E1B40_8A7360(void);
s32 func_800E4578_8A9D98(s32, char**, s32, s32);
void func_800E1D68_8A7588(u32 arg0);
void func_800E1D1C_8A753C(s32 arg0);

void func_800E44A0_8A9CC0(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/func_800E44A8_8A9CC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/func_800E4578_8A9D98.s")

void func_800E4674_8A9E94(void) {
}

void func_800E467C_8A9E9C(void) {
    s32 temp_v0;

    char* sp54[] = {
        "\\w\\1\\LHello there\\t, %s!\nI'm Oak, the Pokεmon professor.",
        NULL,
    };

    char* sp3C[] = {
        "\\2The reason I invited you here\nis \\Mthis PKMN Report.",
        "I'd like for you to take\npictures of Pokεmon\nfor the PKMN Report.",
        "H\\3\\Mere on Pokεmon Island,\nwild Pokεmon can be\nfound everywhere.",
        "T\\4his is my new invention:\nthe \\MZERO-ONE Vehicle. You\ncan take this on your trip.",
        "\\6The ZERO-ONE Vehicle\nconstantly moves toward \\Mthe\nGOAL GATE!",
        NULL,
    };

    char* sp34[] = {
        "Shall I repeat this information?\n\\a Yes, please.\n\\b No, thank you.",
        NULL,
    };

    char* sp2C[] = {
        "\\5I'll teach you how to take\npictures in the first course. I'm\ncounting on you, %s!",
        NULL,
    };

    temp_v0 = func_800E1B40_8A7360();
    func_800E4578_8A9D98(temp_v0, sp54, 0, 1);

    while (1) {
        func_800E4578_8A9D98(temp_v0, sp3C, 0, 1);
        if (!func_800E4578_8A9D98(temp_v0, sp34, 1, 0)) {
            break;
        }
        auPlaySound(0x53U);
    }

    auPlaySound(0x4DU);
    func_800E4578_8A9D98(temp_v0, sp2C, 0, 1);
    func_800E1D68_8A7588(0);
    func_800E1D1C_8A753C(0);
}

//s32 func_800E1B40_8A7360();                         /* extern */
//? func_800E4578_8A9D98(s32, ? *, ?, ?);             /* extern */
//extern ? D_80195D48_95B568;

void func_800E47C0_8A9FE0(void) {
    char*unused;
        char* sp1C[] = {
        "I've been expecting you,\n%s! The Pokεmon\nAcademy has officially\n",
        "announced the record for the\nhighest photo score!",
        "Now you can compete to see\nhow many total points you\ncan get.",
        "I have arranged it so that you\ncan see the \\hChallenge Score\\p\nfor each course.",
        "Good luck, %s!\nDo your best to beat all of the\n\\hCHALLENGE SCORES\\p!",
            NULL,
        };
    func_800E4578_8A9D98(func_800E1B40_8A7360(), sp1C, 0, 1);
}

void func_800E482C_8AA04C(void) {
    char*unused;
    char* sp1C[] = {
        "I have been waiting for\nyou, %s. I expect\nyou to take good pictures.",
        0x00000000,
    };
    func_800E4578_8A9D98(func_800E1B40_8A7360(), sp1C, 0, 1);
}


void func_800E4878_8AA098(void) {
    s32 var;
    char* sp1C[] = {
        "Are you going to take\nPokεmon pictures?\nGood luck, %s!",
        0x00000000,
    };

    var = func_800E1B40_8A7360();
    func_800E4578_8A9D98(var, sp1C, 0, 1);
}

void func_803705F0(int);
void*func_800E3230_8A8A50(void);
void func_80370C34_8443E4(void*);
void func_80370900_8440B0(int, int);
void func_80370990_844140(f32, int);

void func_800E48C4_8AA0E4(void) {
    s32 var_s0;

    auPlaySound(0x52U);
    func_803705F0(1);
    func_80370C34_8443E4(func_800E3230_8A8A50());
    func_80370900_8440B0(1, 3);
    func_80370990_844140(0.1f, 3);

    var_s0 = 1;
    do {
        func_80370990_844140((f32) var_s0 / 30.0f, 3);
        var_s0 += 1;
        ohWait(1);
    } while (var_s0 != 0x1E);

    func_80370990_844140(1.0f, 3);
}

void func_800E4974_8AA194(void) {
    s32 sp2C;

    char* sp20[] = {
        "How have you been, %s?\nI have completed part of\nmy research.",
        "This Album is a gift for you!",
        0x00000000,
    };
    char* sp18[] = {
        "You can put any picture in\nthis Album. It's just for you!",
        0x00000000,
    };

    sp2C = func_800E1B40_8A7360();
    func_800E4578_8A9D98(sp2C, sp20, 2, 1);
    func_800E48C4_8AA0E4();
    func_80374F30_8486E0(sp2C, 1);
    func_800E4578_8A9D98(sp2C, sp18, 0, 1);
}


void func_800E4A10_8AA230(void) {
    s32 var_s0;

    auPlaySound(0x52U);
    func_803705F0(1);
    func_80370C34_8443E4(func_800E3230_8A8A50());
    func_80370900_8440B0(1, 2);
    func_80370990_844140(0.1f, 2);

    var_s0 = 1;
    do {
        func_80370990_844140( var_s0 / 30.0f, 2);
        var_s0 += 1;
        ohWait(1);
    } while (var_s0 != 0x1E);

    func_80370990_844140(1.0f, 2);
}

void func_800E4AC0_8AA2E0(void) {
    s32 var;
    char* sp18[] = {
        "I saw the pictures taken\nby %s.",
        "I saved those pictures in\nthe PKMN Report.",
        "I'll help you out once you have\nmore Pokεmon pictures.",
        "Good luck, %s!\nOh! I have arranged it so that\nyou can see the PKMN Report.",
        NULL,
    };

    var = func_800E1B40_8A7360();
    func_800E4578_8A9D98(var, sp18, 0, 1);
    func_800E4A10_8AA230();
}

char* D_80195D98_95B5B8[] = {
    D_801C5EB4_98B6D4,
    0x00000000,
};


char* D_80195DA0_95B5C0[] = {
    D_801C5EDC_98B6FC,
    0x00000000,
};

char* D_80195DA8_95B5C8[] = {
    D_801C5F20_98B740,
    D_801C5F54_98B774,
    D_801C5FA4_98B7C4,
    0x00000000,
};

char* D_80195DB8_95B5D8[] = {
    D_801C5FE4_98B804,
    0x00000000,
};

char* D_80195DC0_95B5E0[] = {
    D_801C6028_98B848,
    0x00000000,
};

char* D_80195DC8_95B5E8[] = {
    D_801C6054_98B874,
    0x00000000,
};

char* D_80195DD0_95B5F0[] = {
    D_801C6090_98B8B0,
    D_801C60DC_98B8FC,
    0x00000000,
};

char* D_80195DDC_95B5FC[] = {
    D_801C6138_98B958,
    D_801C616C_98B98C,
    D_801C61C8_98B9E8,
    D_801C6200_98BA20,
    D_801C6248_98BA68,
    D_801C6284_98BAA4,
    D_801C62BC_98BADC,
    D_801C62EC_98BB0C,
    0x00000000,
};

char* D_80195E00_95B620[] = {
    D_801C6334_98BB54,
    D_801C6360_98BB80,
    0x00000000,
};

char* D_80195E0C_95B62C[] = {
    D_801C6398_98BBB8,
    D_801C63F4_98BC14,
    0x00000000,
};

char* D_80195E18_95B638[] = {
    D_801C6428_98BC48,
    D_801C6454_98BC74,
    D_801C648C_98BCAC,
    D_801C64DC_98BCFC,
    D_801C6528_98BD48,
    D_801C657C_98BD9C,
    D_801C65D8_98BDF8,
    0x00000000,
};

char* D_80195E38_95B658[] = {
    D_801C65E8_98BE08,
    D_801C664C_98BE6C,
    D_801C6688_98BEA8,
    0x00000000,
};

char* D_80195E48_95B668[] = {
    D_801C66C0_98BEE0,
    D_801C66EC_98BF0C,
    D_801C6738_98BF58,
    D_801C6770_98BF90,
    0x00000000,
};

char* D_80195E5C_95B67C[] = {
    D_801C67B8_98BFD8,
    0x00000000,
};

char* D_80195E64_95B684[] = {
    D_801C67FC_98C01C,
    D_801C6820_98C040,
    D_801C685C_98C07C,
    D_801C6880_98C0A0,
    D_801C68D8_98C0F8,
    D_801C692C_98C14C,
    0x00000000,
};

char* D_80195E80_95B6A0[] = {
    D_801C6968_98C188,
    D_801C69AC_98C1CC,
    D_801C69E0_98C200,
    D_801C6A18_98C238,
    D_801C6A50_98C270,
    0x00000000,
};

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/D_801C5EB4_98B6D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/func_800E4B2C_8AA34C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/func_800E4BA0_8AA3C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/func_800E4CCC_8AA4EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/func_800E4D18_8AA538.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/func_800E4D6C_8AA58C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/func_800E4DD4_8AA5F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/func_800E4E28_8AA648.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/func_800E502C_8AA84C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/func_800E50A0_8AA8C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/func_800E510C_8AA92C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/D_801C5EDC_98B6FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/D_801C5F20_98B740.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/D_801C5F54_98B774.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/D_801C5FA4_98B7C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/D_801C5FE4_98B804.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/D_801C6028_98B848.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/D_801C6054_98B874.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/D_801C6090_98B8B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/D_801C60DC_98B8FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/D_801C6138_98B958.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/D_801C616C_98B98C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/D_801C61C8_98B9E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/D_801C6200_98BA20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/D_801C6248_98BA68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/D_801C6284_98BAA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/D_801C62BC_98BADC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/D_801C62EC_98BB0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/D_801C6334_98BB54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/D_801C6360_98BB80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/D_801C6398_98BBB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/D_801C63F4_98BC14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/D_801C6428_98BC48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/D_801C6454_98BC74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/D_801C648C_98BCAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/D_801C64DC_98BCFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/D_801C6528_98BD48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/D_801C657C_98BD9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/D_801C65D8_98BDF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/D_801C65E8_98BE08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/D_801C664C_98BE6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/D_801C6688_98BEA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/D_801C66C0_98BEE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/D_801C66EC_98BF0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/D_801C6738_98BF58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/D_801C6770_98BF90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/D_801C67B8_98BFD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/D_801C67FC_98C01C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/D_801C6820_98C040.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/D_801C685C_98C07C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/D_801C6880_98C0A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/D_801C68D8_98C0F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/D_801C692C_98C14C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/D_801C6968_98C188.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/D_801C69AC_98C1CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/D_801C69E0_98C200.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/D_801C6A18_98C238.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/D_801C6A50_98C270.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/func_800E5120_8AA940.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A9CC0/func_800E5298_8AAAB8.s")
