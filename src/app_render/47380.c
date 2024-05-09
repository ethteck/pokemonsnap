#include "common_structs.h"
#include "app_render.h"

#include "beach/beach.h"
#if !defined(M2CTX) && !defined(PERMUTER)
#include "ld_addrs.h"
#include "string.h"
#endif
#include "world/world.h"

typedef struct Unk1C {
    /* 0x00 */ u32 id;
    /* 0x04 */ f32 scale;
    /* 0x08 */ UnkEC64Arg3* unk_8;
    /* 0x0C */ Texture*** unk_C;
    /* 0x10 */ void (*unk_10)(GObj*);
    /* 0x14 */ AnimCmd** unk_14;
    /* 0x18 */ AnimCmd*** unk_18;
} Unk1C; // size = 0x1C

typedef struct UnkV0 {
    u32 unk_00;
    f32 unk_04;
    UnkEC64Arg3* unk_08;
    Texture*** unk_0C;
    void (*unk_10)(GObj*);
} UnkV0; // substruct of Unk1C?

extern UnkV0 D_800ADBEC[];
extern GObj* D_800BDF30[];
extern s32 D_800BDF60;
extern s32 D_800BDF68[];
extern s32 D_800AC0F0; // level id?
extern UnkGoldViper D_800AC0F4;
extern Unk1C D_800ADA64[];
extern s32 D_800AE27C;
extern s32 D_800AE280;
extern char* D_800AE284[]; // Pokedex entries
extern s8 D_800AE4E4[];

// s8 D_800AE4E4[] = {
//     0,  -1, -1, 1,  2,  3,  4,  -1, -1, -1, 5,  6,  -1, 7,  -1, 8,  -1, -1, -1, -1, -1, -1, -1, -1, 9,  -1,
//     10, 11, -1, -1, -1, -1, -1, -1, -1, -1, 12, -1, 13, -1, 14, -1, -1, -1, 15, -1, -1, -1, -1, 16, 17, 18,
//     -1, 19, -1, 20, -1, 21, 22, 23, -1, -1, -1, -1, -1, -1, -1, -1, -1, 24, 25, -1, -1, 26, 27, -1, -1, 28,
//     29, 30, 31, 32, -1, 33, -1, -1, -1, 34, 35, 36, 37, -1, 38, -1, -1, -1, -1, -1, -1, -1, 39, -1, -1, -1,
//     -1, -1, -1, -1, 40, -1, -1, -1, 41, -1, 42, -1, -1, 43, -1, 44, 45, -1, 46, 47, 48, 49, -1, -1, 50, 51,
//     52, 53, 54, -1, -1, -1, 55, -1, -1, -1, -1, -1, 56, 57, 58, 59, 60, -1, 61, -1, 62, 0,  0,  0,  0,  0,
// };

// Manually define this RODATA here until data is migrated for D_800AE284
// These are the names of all pokemon in order, used for returning their names when needed.
const char D_800AF420[] = ""; // Blank first entry as there's no Pokedex zero.
const char D_800AF424[] = "ＢＵＬＢＡＳＡＵＲ";
const char D_800AF438[] = "ＩＶＹＳＡＵＲ";
const char D_800AF448[] = "ＶＥＮＵＳＡＵＲ";
const char D_800AF45C[] = "ＣＨＡＲＭＡＮＤＥＲ";
const char D_800AF474[] = "ＣＨＡＲＭＥＬＥＯＮ";
const char D_800AF48C[] = "ＣＨＡＲＩＺＡＲＤ";
const char D_800AF4A0[] = "ＳＱＵＩＲＴＬＥ";
const char D_800AF4B4[] = "ＷＡＲＴＯＲＴＬＥ";
const char D_800AF4C8[] = "ＢＬＡＳＴＯＩＳＥ";
const char D_800AF4DC[] = "ＣＡＴＥＲＰＩＥ";
const char D_800AF4F0[] = "ＭＥＴＡＰＯＤ";
const char D_800AF500[] = "ＢＵＴＴＥＲＦＲＥＥ";
const char D_800AF518[] = "ＷＥＥＤＬＥ";
const char D_800AF528[] = "ＫＡＫＵＮＡ";
const char D_800AF538[] = "ＢＥＥＤＲＩＬＬ";
const char D_800AF54C[] = "ＰＩＤＧＥＹ";
const char D_800AF55C[] = "ＰＩＤＧＥＯＴＴＯ";
const char D_800AF570[] = "ＰＩＤＧＥＯＴ";
const char D_800AF580[] = "ＲＡＴＴＡＴＡ";
const char D_800AF590[] = "ＲＡＴＩＣＡＴＥ";
const char D_800AF5A4[] = "ＳＰＥＡＲＯＷ";
const char D_800AF5B4[] = "ＦＥＡＲＯＷ";
const char D_800AF5C4[] = "ＥＫＡＮＳ";
const char D_800AF5D0[] = "ＡＲＢＯＫ";
const char D_800AF5DC[] = "ＰＩＫＡＣＨＵ";
const char D_800AF5EC[] = "ＲＡＩＣＨＵ";
const char D_800AF5FC[] = "ＳＡＮＤＳＨＲＥＷ";
const char D_800AF610[] = "ＳＡＮＤＳＬＡＳＨ";
const char D_800AF624[] = "ＮＩＤＲＡＮｆ";
const char D_800AF634[] = "ＮＩＤＯＲＩＮＡ";
const char D_800AF648[] = "ＮＩＤＯＱＵＥＥＮ";
const char D_800AF65C[] = "ＮＩＤＯＲＡＮｍ";
const char D_800AF670[] = "ＮＩＤＯＲＩＮＯ";
const char D_800AF684[] = "ＮＩＤＯＫＩＮＧ";
const char D_800AF698[] = "ＣＬＥＦＡＩＲＹ";
const char D_800AF6AC[] = "ＣＬＥＦＡＢＬＥ";
const char D_800AF6C0[] = "ＶＵＬＰＩＸ";
const char D_800AF6D0[] = "ＮＩＮＥＴＡＬＥＳ";
const char D_800AF6E4[] = "ＪＩＧＧＬＹＰＵＦＦ";
const char D_800AF6FC[] = "ＷＩＧＧＬＹＴＵＦＦ";
const char D_800AF714[] = "ＺＵＢＡＴ";
const char D_800AF720[] = "ＧＯＬＢＡＴ";
const char D_800AF730[] = "ＯＤＤＩＳＨ";
const char D_800AF740[] = "ＧＬＯＯＭ";
const char D_800AF74C[] = "ＶＩＬＥＰＬＵＭＥ";
const char D_800AF760[] = "ＰＡＲＡＳ";
const char D_800AF76C[] = "ＰＡＲＡＳＥＣＴ";
const char D_800AF780[] = "ＶＥＮＯＮＡＴ";
const char D_800AF790[] = "ＶＥＮＯＭＯＴＨ";
const char D_800AF7A4[] = "ＤＩＧＬＥＴＴ";
const char D_800AF7B4[] = "ＤＵＧＴＲＩＯ";
const char D_800AF7C4[] = "ＭＥＯＷＴＨ";
const char D_800AF7D4[] = "ＰＥＲＳＩＡＮ";
const char D_800AF7E4[] = "ＰＳＹＤＵＣＫ";
const char D_800AF7F4[] = "ＧＯＬＤＵＣＫ";
const char D_800AF804[] = "ＭＡＮＫＥＹ";
const char D_800AF814[] = "ＰＲＩＭＥＡＰＥ";
const char D_800AF828[] = "ＧＲＯＷＬＩＴＨＥ";
const char D_800AF83C[] = "ＡＲＣＡＮＩＮＥ";
const char D_800AF850[] = "ＰＯＬＩＷＡＧ";
const char D_800AF860[] = "ＰＯＬＩＷＨＩＲＬ";
const char D_800AF874[] = "ＰＯＬＩＷＲＡＴＨ";
const char D_800AF888[] = "ＡＢＲＡ";
const char D_800AF894[] = "ＫＡＤＡＢＲＡ";
const char D_800AF8A4[] = "ＡＬＡＫＡＺＡＭ";
const char D_800AF8B8[] = "ＭＡＣＨＯＰ";
const char D_800AF8C8[] = "ＭＡＣＨＯＫＥ";
const char D_800AF8D8[] = "ＭＡＣＨＡＭＰ";
const char D_800AF8E8[] = "ＢＥＬＬＳＰＲＯＵＴ";
const char D_800AF900[] = "ＷＥＥＰＩＮＢＥＬＬ";
const char D_800AF918[] = "ＶＩＣＴＲＥＥＢＥＬ";
const char D_800AF930[] = "ＴＥＮＴＡＣＯＯＬ";
const char D_800AF944[] = "ＴＥＮＴＡＣＲＵＥＬ";
const char D_800AF95C[] = "ＧＥＯＤＵＤＥ";
const char D_800AF96C[] = "ＧＲＡＶＥＬＥＲ";
const char D_800AF980[] = "ＧＯＬＥＭ";
const char D_800AF98C[] = "ＰＯＮＹＴＡ";
const char D_800AF99C[] = "ＲＡＰＩＤＡＳＨ";
const char D_800AF9B0[] = "ＳＬＯＷＰＯＫＥ";
const char D_800AF9C4[] = "ＳＬＯＷＢＲＯ";
const char D_800AF9D4[] = "ＭＡＧＮＥＭＩＴＥ";
const char D_800AF9E8[] = "ＭＡＧＮＥＴＯＮ";
const char D_800AF9FC[] = "ＦＡＲＦＥＴＣＨ’Ｄ";
const char D_800AFA14[] = "ＤＯＤＵＯ";
const char D_800AFA20[] = "ＤＯＤＲＩＯ";
const char D_800AFA30[] = "ＳＥＥＬ";
const char D_800AFA3C[] = "ＤＥＷＧＯＮＧ";
const char D_800AFA4C[] = "ＧＲＩＭＥＲ";
const char D_800AFA5C[] = "ＭＵＫ";
const char D_800AFA64[] = "ＳＨＥＬＬＤＥＲ";
const char D_800AFA78[] = "ＣＬＯＹＳＴＥＲ";
const char D_800AFA8C[] = "ＧＡＳＴＬＹ";
const char D_800AFA9C[] = "ＨＡＵＮＴＥＲ";
const char D_800AFAAC[] = "ＧＥＮＧＡＲ";
const char D_800AFABC[] = "ＯＮＩＸ";
const char D_800AFAC8[] = "ＤＲＯＷＺＥＥ";
const char D_800AFAD8[] = "ＨＹＰＮＯ";
const char D_800AFAE4[] = "ＫＲＡＢＢＹ";
const char D_800AFAF4[] = "ＫＩＮＧＬＥＲ";
const char D_800AFB04[] = "ＶＯＬＴＯＲＢ";
const char D_800AFB14[] = "ＥＬＥＣＴＲＯＤＥ";
const char D_800AFB28[] = "ＥＸＥＧＧＣＵＴＥ";
const char D_800AFB3C[] = "ＥＸＥＧＧＵＴＯＲ";
const char D_800AFB50[] = "ＣＵＢＯＮＥ";
const char D_800AFB60[] = "ＭＡＲＯＷＡＫ";
const char D_800AFB70[] = "ＨＩＴＭＯＮＬＥＥ";
const char D_800AFB84[] = "ＨＩＴＭＯＮＣＨＡＮ";
const char D_800AFB9C[] = "ＬＩＣＫＩＴＵＮＧ";
const char D_800AFBB0[] = "ＫＯＦＦＩＮＧ";
const char D_800AFBC0[] = "ＷＥＥＺＩＮＧ";
const char D_800AFBD0[] = "ＲＨＹＨＯＲＮ";
const char D_800AFBE0[] = "ＲＨＹＤＯＮ";
const char D_800AFBF0[] = "ＣＨＡＮＳＥＹ";
const char D_800AFC00[] = "ＴＡＮＧＥＬＡ";
const char D_800AFC10[] = "ＫＡＮＧＡＳＫＨＡＮ";
const char D_800AFC28[] = "ＨＯＲＳＥＡ";
const char D_800AFC38[] = "ＳＥＡＤＲＡ";
const char D_800AFC48[] = "ＧＯＬＤＥＥＮ";
const char D_800AFC58[] = "ＳＥＡＫＩＮＧ";
const char D_800AFC68[] = "ＳＴＡＲＹＵ";
const char D_800AFC78[] = "ＳＴＡＲＭＩＥ";
const char D_800AFC88[] = "ＭＲ．ＭＩＭＥ";
const char D_800AFC98[] = "ＳＣＹＴＨＥＲ";
const char D_800AFCA8[] = "ＪＹＮＸ";
const char D_800AFCB4[] = "ＥＬＥＣＴＡＢＵＺＺ";
const char D_800AFCCC[] = "ＭＡＧＭＡＲ";
const char D_800AFCDC[] = "ＰＩＮＳＥＲ";
const char D_800AFCEC[] = "ＴＡＵＲＯＳ";
const char D_800AFCFC[] = "ＭＡＧＩＫＡＲＰ";
const char D_800AFD10[] = "ＧＹＡＲＡＤＯＳ";
const char D_800AFD24[] = "ＬＡＰＲＡＳ";
const char D_800AFD34[] = "ＤＩＴＴＯ";
const char D_800AFD40[] = "ＥＥＶＥＥ";
const char D_800AFD4C[] = "ＶＡＰＯＥＲＯＮ";
const char D_800AFD60[] = "ＪＯＬＴＥＯＮ";
const char D_800AFD70[] = "ＦＬＡＲＥＯＮ";
const char D_800AFD80[] = "ＰＯＲＹＧＯＮ";
const char D_800AFD90[] = "ＯＭＡＮＹＴＥ";
const char D_800AFDA0[] = "ＯＭＡＳＴＡＲ";
const char D_800AFDB0[] = "ＫＡＢＵＴＯ";
const char D_800AFDC0[] = "ＫＡＢＵＴＯＰＳ";
const char D_800AFDD4[] = "ＡＥＲＯＤＡＣＴＹＬ";
const char D_800AFDEC[] = "ＳＮＯＲＬＡＸ";
const char D_800AFDFC[] = "ＡＲＴＩＣＵＮＯ";
const char D_800AFE10[] = "ＺＡＰＤＯＳ";
const char D_800AFE20[] = "ＭＯＬＴＲＥＳ";
const char D_800AFE30[] = "ＤＲＡＴＩＮＩ";
const char D_800AFE40[] = "ＤＲＡＧＯＮＡＩＲ";
const char D_800AFE54[] = "ＤＲＡＧＯＮＩＴＥ";
const char D_800AFE68[] = "ＭＥＷＴＷＯ";
const char D_800AFE78[] = "ＭＥＷ";

extern PhotoData D_800B0598[60]; // Size: 0xD980 - All photos taken in a level
extern UnkThing* D_800BDF18;
extern u8 D_800BDF1C;
extern u8 D_800BDF1D;
extern u8 D_800BDF1E;
extern s32 D_800BDF20[3];
extern ucolor D_800BDF2C;

extern Texture** D_800E8EB8;
extern UnkEC64Arg3 D_800E9138;
extern UNK_PTR* D_800E9168;
extern AnimCmd** D_800E91C0;
extern Texture** D_800EAC58;
extern UnkEC64Arg3 D_800EAED0;
extern UNK_PTR* D_800EAF00;
extern AnimCmd** D_800EAF60;
extern AnimCmd* D_800EAFB0;
extern AnimCmd** D_800EB0C0;
extern UnkEC64Arg3 D_800EB430;
extern UNK_PTR* D_800EB460;
extern Texture** D_800EB510;
extern AnimCmd* D_800ED5B0;
extern AnimCmd** D_800ED6B0;
extern UNK_PTR* D_800EDAE0;
extern UnkEC64Arg3 D_800EDAB0;
extern Texture** D_800EDB90;

extern WorldSetup D_800F5DA0;
extern WorldSetup D_800FFFB8;
extern WorldSetup D_80100720;
extern WorldSetup D_8011E6CC;
extern WorldSetup D_8012A0E8;
extern WorldSetup D_8012AC90;

extern UNK_TYPE D_8013E260;
extern UNK_TYPE D_8017A780;
extern UNK_TYPE D_80188D28;
extern UNK_TYPE D_801AFD30;
extern UNK_TYPE D_801B1230;
extern UNK_TYPE D_801B1D40;
extern UNK_TYPE D_801B6B60;
extern UNK_TYPE D_801CE400;
extern UNK_TYPE D_801CF770;
extern UNK_TYPE D_801CF840;
extern UNK_TYPE D_801D6840;

extern s32 D_803AE770; // pokemon ID
extern UnkThing D_803AE788[];
extern s32 D_803AEF30; // photo idx

char* getPokemonName(s32 pkmnID) {
    if (pkmnID > 0 && pkmnID <= POKEDEX_MAX) {
        return D_800AE284[pkmnID];
    }
    if (pkmnID == 0x3EC || pkmnID == 0x3F2 || pkmnID == 0x3FA || pkmnID == 0x3FE || pkmnID == 0x404 ||
        pkmnID == 0x40B) {
        if (func_800BFCA0_5CB40(5) == 0) {
            return "？";
        }
    }
    if (pkmnID == 0x3EC || pkmnID == 0x3F2 || pkmnID == 0x3FA || pkmnID == 0x3FE || pkmnID == 0x404 ||
        pkmnID == 0x40B) {
        if (func_800BF3D4_5C274(pkmnID) == 0) {
            return "Ｓｉｇｎ？";
        }
    }
    switch (pkmnID) {
        case 0x25B:
            return D_800AE284[PokemonID_SHELLDER];
        case 0x3EC:
        case 0x3F2:
        case 0x3FA:
        case 0x3FE:
        case 0x404:
        case 0x40B:
            return "Ｓｉｇｎ";
        case 0x1F4:
        case 0x258:
        case 0x259:
        case 0x25A:
            return "？";
        default:
            return NULL;
    }
}

s32 func_8009BB4C(s32 pkmnID) {
    s32 ret;
    s32 temp = D_800AE4E4[150];

    if (pkmnID == 0x25B) {
        pkmnID = PokemonID_SHELLDER;
    }
    if (pkmnID > 0 && pkmnID <= POKEDEX_MAX) {
        ret = D_800AE4E4[pkmnID - 1];
    } else {
        switch (pkmnID) {
            case 0x3EC:
                ret = temp + 1;
                break;
            case 0x3F2:
                ret = temp + 2;
                break;
            case 0x404:
                ret = temp + 3;
                break;
            case 0x3FE:
                ret = temp + 4;
                break;
            case 0x3FA:
                ret = temp + 5;
                break;
            case 0x40B:
                ret = temp + 6;
                break;
            default:
                ret = -1;
                break;
        }
    }
    return ret;
}

s32 func_8009BBF4(void) {
    return D_800AE27C;
}

s32 func_8009BC00(void) {
    return D_800AE280;
}

s32 func_8009BC0C(s32 arg0) {
    s32 i;

    for (i = 0; i < D_800AE280 && i < ARRAY_COUNT(D_800BDF20); i++) {
        if (arg0 == D_800BDF20[i]) {
            return 0;
        }
    }
    return 1;
}

s32 func_8009BC68(void) {
    return gPhotoCount;
}

PhotoData* func_8009BC74(void) {
    return D_800B0598;
}

PhotoData* func_8009BC80(s32 photoIndex) {
    if (photoIndex < 0 || gPhotoCount < photoIndex) {
        return NULL;
    }
    return &D_800B0598[photoIndex];
}

s32 func_8009BCC4(UnkThing* arg0) {
    s32 temp_v0;
    s32 ret;

    if (arg0->main.levelID < 0) {
        return -1;
    }
    switch (arg0->main.unk_00_16 & 0xE0) {
        default:
            ret = -1;
            break;
        case 0x60:
            ret = 0x3EC;
            break;
        case 0x80:
            ret = 0x3FA;
            break;
        case 0xA0:
            ret = 0x3FE;
            break;
        case 0xE0:
            ret = 0x40B;
            break;
        case 0x20:
            ret = arg0->main.unk_20[0].pokemonID;
            break;
    }
    return ret;
}

typedef struct Unkfunc_8009BD4C {
    u32 unk_00;
    struct Unkfunc_8009BD4C* next;
    s32 unk_08;
} Unkfunc_8009BD4C;

s8 func_8009BD4C(s16 arg0, Unkfunc_8009BD4C* arg1, Unkfunc_8009BD4C* arg2, s32 arg3) {
    Unkfunc_8009BD4C* next;
    s32 i;
    s32 j;

    for (i = 0; i < arg3; i++) {
        if (arg0 == arg2[i].unk_00) {
            next = arg2[i].next; // TODO: This var seems necessary, but using it seems to break things.
            for (j = 0; j < arg2[i].unk_08; j++, next++) {
                if (arg1 == arg2[i].next[j].next) {
                    return j;
                }
            }
            return -1;
        }
    }
    return -1;
}

#ifdef NON_MATCHING
typedef struct Unkfunc_8009BDDC {
    s32 unk_00;    // Id?
    Vec3f* unk_04; // Size of 0xC, floats?
    s32 unk_10;    // number of unk_04 records?
} Unkfunc_8009BDDC;

extern s32 D_800AD4B8;    // 0x58;
extern Vec3f* D_800AD4BC; // 5 values here
extern s32 D_800AD4C0;    // = 5; // number of D_800AD4BC records

extern s32 D_800AD4C4;    // = 0x59
extern Vec3f* D_800AD4C8; // 5 values here
extern s32 D_800AD4CC;    // = 5; // number of D_800AD4C8 records
extern s32 D_800AD4D0;    // = 0x7E;
extern Vec3f* D_800AD4D4; // 10 values here
extern s32 D_800AD4D8;    // = 10;
extern Unkfunc_8009BDDC D_800AD4DC[64];

f32 func_8009BDDC(s16 arg0, s8 arg1) {
    s32 i;
    u32 test = arg0;

    if (test == D_800AD4B8) {
        return D_800AD4BC[arg1].x;
    }
    if (test == D_800AD4C4) {
        return D_800AD4C8[arg1].x;
    } /* One Line diff */
    if (test == D_800AD4D0) {
        return D_800AD4D4[arg1].x;
    }

    for (i = 0; i < ARRAY_COUNT(D_800AD4DC); i++) {
        if (test == D_800AD4DC[i].unk_00) {
            return D_800AD4DC[i].unk_04[arg1].x;
        }
    }
    return -1.0f;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/app_render/47380/func_8009BDDC.s")
#endif

s32 func_8009BF48(UnkThingSub*, GObj*);
#pragma GLOBAL_ASM("asm/nonmatchings/app_render/47380/func_8009BF48.s")

void func_8009C25C(UnkThing* arg0, u8 objIndex) {
    GObj* obj;
    s32 i = 0;
    obj = omGObjListHead[objIndex];

    while (obj != NULL && i < ARRAY_COUNT(arg0->main.unk_20)) {
        if (func_8009BF48(&arg0->main.unk_20[i], obj) != 0) {
            arg0->unk_3A4[i] = obj;
            i++;
        }
        obj = obj->next;
    }
}

s32 func_8009C304(UnkThingSub2* arg0, GObj* obj) {
    DObj* dobj;
    u8 temp_t3;
    UNK_PTR* payload;

    dobj = obj->data.dobj;
    if (obj->flags & 1) {
        return 0;
    }

    arg0->pos.x = dobj->position.v.x;
    arg0->pos.y = dobj->position.v.y;
    arg0->pos.z = dobj->position.v.z;

    payload = dobj->firstChild->payload.any;
    if (payload == D_800EB460) {
        arg0->unk_00 = 3;
        arg0->unk_01 = (s32) obj->animationTime;
    } else if (payload == D_800EDAE0) {
        arg0->unk_00 = 4;
        arg0->unk_01 = (s32) obj->animationTime;
    } else if (payload == D_800E9168) {
        arg0->unk_00 = 1;
        arg0->unk_01 = (s32) dobj->firstChild->mobjList->timePassed;
    } else if (payload == D_800EAF00) {
        arg0->unk_00 = 2;
        arg0->unk_01 = (s32) dobj->firstChild->mobjList->timePassed & 0xF;
        arg0->unk_01 |= ((s32) ((dobj->scale.v.x * 15.0f) / 0.1f) * 16);
    } else {
        return 0;
    }

    return 1;
}

void func_8009C450(UnkThing* arg0, u8 objIndex) {
    GObj* obj;
    s32 i;

    i = 0;
    obj = omGObjListHead[objIndex];
    while (obj != NULL && i < 6) {
        if (!(obj->flags & 1) &&
            (func_803647BC_504BCC(obj) == 0) &&
            (func_8009C304(&arg0->main.unk_140[i], obj) != 0))
        {
            i++;
        }
        obj = obj->next;
    }
}

void func_8009C4F4(UnkThing* arg0, UnkGoldViper* arg1, OMCamera* arg2) {
    arg0->main.levelID = getLevelId();
    arg0->main.unk_00_16 = arg1->unk_08->index;
    arg0->main.unk_04 = world_func_800E219C();
    arg0->main.unk_08.x = arg2->viewMtx.lookAt.eye.x;
    arg0->main.unk_08.y = arg2->viewMtx.lookAt.eye.y;
    arg0->main.unk_08.z = arg2->viewMtx.lookAt.eye.z;
    arg0->main.unk_14.x = arg2->viewMtx.lookAt.at.x;
    arg0->main.unk_14.y = arg2->viewMtx.lookAt.at.y;
    arg0->main.unk_14.z = arg2->viewMtx.lookAt.at.z;
}

// Used in a qsort to diff Vec3f's Z vals.
s32 func_8009C584(const void* a, const void* b) {
    const Vec3f* a1 = a;
    const Vec3f* b1 = b;

    if (a1->z < b1->z) {
        return -1;
    } else if (b1->z < a1->z) {
        return 1;
    }

    return 0;
}

// Used in a qsort to diff Vec3f's Y vals.
s32 func_8009C5C4(const void* a, const void* b) {
    const Vec3f* a1 = a;
    const Vec3f* b1 = b;

    if (b1->y < a1->y) {
        return -1;
    } else if (a1->y < b1->y) {
        return 1;
    }

    return 0;
}

void func_8009C604(UnkThing* arg0);
#pragma GLOBAL_ASM("asm/nonmatchings/app_render/47380/func_8009C604.s")

void func_8009C8E4(OMCamera* arg0, UnkGoldViper* arg1, UnkThing* arg2) {
    s32 i;

    // clang-format off
    for (i = 0; i < ARRAY_COUNT(arg2->main.unk_140); i++) { arg2->main.unk_140[i].unk_00 = -1; }
    // clang-format on

    // clang-format off
    for (i = 0; i < ARRAY_COUNT(arg2->main.unk_1A0); i++) { arg2->main.unk_1A0[i].unk_00 = -1; }
    // clang-format on

    for (i = 0; i < ARRAY_COUNT(arg2->main.unk_20); i++) {
        arg2->main.unk_20[i].pokemonID = -1;
        arg2->unk_3A4[i] = NULL;
    }

    arg2->unk_3A0 = 0;
    func_803643E0_5047F0(arg0);
    func_8009C4F4(arg2, arg1, arg0);
    func_8009C25C(arg2, 3);
    func_8009C450(arg2, 4);
    func_8009C604(arg2);
}

s32 func_8009C9E8(GObj* gobj) {
    UNUSED s32 pad[3];
    UnkThing* sp38;
    s32 sp34;
    PhotoData* temp_s4;
    s32 cond;
    s32 idx;
    s32 i;

    if (gPhotoCount < 0 || gPhotoCount >= 60) {
        return 0;
    }

    if (gobj != NULL) {
        D_800AE27C++;

        for (i = 0; i < D_800AE280 && i < ARRAY_COUNT(D_800BDF20); i++) {
            if (D_800BDF20[i] == D_803AE770) {
                break;
            }
        }

        if (i >= D_800AE280 && i < 3) {
            D_800BDF20[D_800AE280] = D_803AE770;
            D_800AE280++;
        }
    }

    temp_s4 = &D_800B0598[gPhotoCount];
    sp38 = &D_803AE788[D_803AEF30];
    memcpy(temp_s4, sp38, 0x20);

    for (i = 0; i < ARRAY_COUNT(temp_s4->unk_140); i++) {
        memcpy(&temp_s4->unk_140[i], &sp38->main.unk_140[i], sizeof(temp_s4->unk_140[0]));
    }

    for (i = 0; i < ARRAY_COUNT(temp_s4->unk_1A0); i++) {
        memcpy(&temp_s4->unk_1A0[i], &sp38->main.unk_1A0[i], sizeof(temp_s4->unk_1A0[0]));
    }

    if (gobj == NULL) {
        for (i = 0; i < ARRAY_COUNT(temp_s4->unk_20); i++) {
            memcpy(&temp_s4->unk_20[i], &sp38->main.unk_20[i], sizeof(temp_s4->unk_20[0]));
        }
    } else {
        sp34 = D_803AE770;
        if (sp34 == 0x3EC || sp34 == 0x3FA || sp34 == 0x3FE || (cond = TRUE, sp34 == 0x40B)) {
            for (i = 0; i < ARRAY_COUNT(temp_s4->unk_20); i++) {
                memcpy(&temp_s4->unk_20[i], &sp38->main.unk_20[i], sizeof(temp_s4->unk_20[0]));
            }
        } else {
            for (i = 0; i < ARRAY_COUNT(sp38->unk_3A4); i++) {
                if (gobj == sp38->unk_3A4[i]) {
                    cond = FALSE;
                    break;
                }
            }

            if (cond) {
                for (i = 0; i < ARRAY_COUNT(temp_s4->unk_20); i++) {
                    memcpy(&temp_s4->unk_20[i], &sp38->main.unk_20[i], sizeof(temp_s4->unk_20[0]));
                }
            } else {
                idx = 1;
                for (i = 0; i < ARRAY_COUNT(temp_s4->unk_20); i++) {
                    if (gobj == sp38->unk_3A4[i]) {
                        memcpy(&temp_s4->unk_20[0], &sp38->main.unk_20[i], sizeof(temp_s4->unk_20[0]));
                    } else {
                        memcpy(&temp_s4->unk_20[idx], &sp38->main.unk_20[i], sizeof(temp_s4->unk_20[1]));
                        idx++;
                    }
                }
            }
        }

        switch (sp34) {
            default:
                temp_s4->unk_00_16 |= 0x20;
                break;
            case 0x3EC:
                temp_s4->unk_00_16 |= 0x60;
                break;
            case 0x3FA:
                temp_s4->unk_00_16 |= 0x80;
                break;
            case 0x3FE:
                temp_s4->unk_00_16 |= 0xA0;
                break;
            case 0x40B:
                temp_s4->unk_00_16 |= 0xE0;
                break;
        }
    }
    gPhotoCount++;
    return 1;
}

// & 0xFFs and temp required to match
void func_8009CDC0(u8* arg0, s32 arg1) {
    if (arg0 != NULL) {
        s32 prev = *arg0;

        *arg0 = (arg1 & 1) & 0xFF | (prev & 0xFF & ~1);
    }
}

s32 func_8009CDE4(u8* arg0) {
    if (arg0 != NULL) {
        return *arg0 & 1;
    }
    return 0;
}

void func_8009CE00(void) {
    s32 i;

    gPhotoCount = 0;
    D_800AE27C = 0;
    D_800AE280 = 0;

    for (i = 0; i < ARRAY_COUNT(D_800BDF20); i++) {
        D_800BDF20[i] = -1;
    }

    for (i = 0; i < ARRAY_COUNT(D_800B0598); i++) {
        D_800B0598[i].levelID = -1;
        D_800B0598[i].unk_00_24 = 0;
    }
}

GObj* func_8009CEAC(WorldBlock* arg0, WorldBlock* arg1, ObjectSpawn* arg2, Unk1C* arg3) {
    DObj* dobj;
    GObj* gobj;
    f32 temp_f0;

    gobj = omAddGObj(0x80, NULL, D_800BDF1E, 0x80000000);
    omLinkGObjDL(gobj, arg3->unk_10, D_800BDF1C, 0x80000000, -1);
    anim_func_80010230(gobj, arg3->unk_8, arg3->unk_C, NULL, 0x1C, 0, 0);
    if (arg3->unk_14 != NULL) {
        animSetModelTreeAnimation(gobj, arg3->unk_14, world_func_800E21A8(D_800BDF18->main.unk_04));
        animSetModelAnimationSpeed(gobj, 0.0f);
        if (arg3->unk_18 != NULL) {
            animSetModelTreeTextureAnimation(gobj, arg3->unk_18, world_func_800E21A8(D_800BDF18->main.unk_04));
            animSetTextureAnimationSpeed(gobj, 0.0f);
        }
        animUpdateModelTreeAnimation(gobj);
    }
    dobj = gobj->data.dobj;
    dobj->position.v.x = (arg2->translation.x + (arg0->descriptor->unk_04.x - arg1->descriptor->unk_04.x)) * 100.0f;
    dobj->position.v.y = (arg2->translation.y + (arg0->descriptor->unk_04.y - arg1->descriptor->unk_04.y)) * 100.0f;
    dobj->position.v.z = (arg2->translation.z + (arg0->descriptor->unk_04.z - arg1->descriptor->unk_04.z)) * 100.0f;
    dobj->rotation.f[1] = dobj->rotation.f[3] = 0.0f;
    dobj->rotation.f[2] = arg2->euler.y;
    temp_f0 = arg3->scale * 0.1f;
    dobj->scale.v.x = dobj->scale.v.y = dobj->scale.v.z = temp_f0;
    if (arg3->id == 0x3FA && (D_800BDF18->main.unk_00_16 & 0xE0) != 0x80) { // todo bitfield
        dobj->firstChild->flags |= 1;
    }
    return gobj;
}

void func_8009D0B4(WorldBlock* b1, WorldBlock* b2) {
    ObjectSpawn* spawn;
    Unk1C* var_a3;

    if (b1 != NULL) {
        if (b1->descriptor != NULL) {
            if (b1->descriptor->spawn != NULL) {
                for (spawn = b1->descriptor->spawn; spawn->id != -1; spawn++) {
                    for (var_a3 = D_800ADA64; var_a3->id != 0; var_a3++) {
                        // TODO: stupid id ^ 0 required to match
                        if ((spawn->id ^ 0) == var_a3->id) {
                            func_8009CEAC(b1, b2, spawn, var_a3);
                            break;
                        }
                    }
                }
            }
        }
    }
}

void func_8009D184(WorldSetup* arg0) {
    arg0->unk_0C = NULL;
    createWorld(arg0, 0x63, 0x64, 0x7E, D_800BDF1D, D_800BDF1C, func_8009D0B4, 0, 0);
    func_800E1A78_5F228(0.0f);
}

void func_8009D1E8(u32 arg0, s32 arg1, s32 arg2) {
    if (arg1 >= arg0) {
        dmaReadRom((void*) arg0, (void*) arg2, arg1 - arg0);
    }
}

void func_8009D21C(s32 arg0, s32* arg1);
#pragma GLOBAL_ASM("asm/nonmatchings/app_render/47380/func_8009D21C.s")

void func_8009D37C(u8 levelID) {
    if (levelID < 0) {
        return;
    }

    switch (levelID) {
        case SCENE_BEACH:
            func_8009D184(&D_8011B914);
            func_8009D1E8((u32) AB8780_ROM_START, (u32) AB8780_ROM_END, (s32) &D_801D6840);
            func_8009D21C(0, &D_801D6840);
            D_800BDF2C.r = 0xFF;
            D_800BDF2C.g = 0xFF;
            D_800BDF2C.b = 0xFF;
            D_800BDF2C.a = 0;
            break;
        case SCENE_TUNNEL:
            func_8009D184(&D_8011E6CC);
            func_8009D1E8((u32) ABEBD0_ROM_START, (u32) ABEBD0_ROM_END, (s32) &D_801B1230);
            func_8009D21C(0, &D_801B1230);
            D_800BDF2C.r = 0x80;
            D_800BDF2C.g = 0x80;
            D_800BDF2C.b = 0;
            D_800BDF2C.a = 0;
            memcpy(&D_801AFD30, &D_80188D28, 0x1500);
            break;
        case SCENE_CAVE:
            func_8009D184(&D_8012A0E8);
            func_8009D1E8((u32) AC6A80_ROM_START, (u32) AC6A80_ROM_END, (s32) &D_801CF840);
            func_8009D21C(0, &D_801CF840);
            D_800BDF2C.r = 0xFF;
            D_800BDF2C.g = 0xFF;
            D_800BDF2C.b = 0xFF;
            D_800BDF2C.a = 0;
            memcpy(&D_801CE400, &D_8017A780, 0x1440);
            break;
        case SCENE_RIVER:
            func_8009D184(&D_8012AC90);
            func_8009D1E8((u32) AC8830_ROM_START, (u32) AC8830_ROM_END, (s32) &D_801B6B60);
            func_8009D21C(0, &D_801B6B60);
            D_800BDF2C.r = 0x80;
            D_800BDF2C.g = 0x80;
            D_800BDF2C.b = 0x80;
            D_800BDF2C.a = 0;
            break;
        case SCENE_VOLCANO:
            func_8009D184(&D_800FFFB8);
            func_8009D1E8((u32) ACF9A0_ROM_START, (u32) ACF9A0_ROM_END, (s32) &D_801CF770);
            func_8009D21C(0, &D_801CF770);
            D_800BDF2C.r = 0xFF;
            D_800BDF2C.g = 0;
            D_800BDF2C.b = 0;
            D_800BDF2C.a = 0;
            break;
        case SCENE_VALLEY:
            func_8009D184(&D_80100720);
            func_8009D1E8((u32) AD1640_ROM_START, (u32) AD1640_ROM_END, (s32) &D_801B1D40);
            func_8009D21C(0, &D_801B1D40);
            D_800BDF2C.r = 0x80;
            D_800BDF2C.g = 0x80;
            D_800BDF2C.b = 0x80;
            D_800BDF2C.a = 0;
            break;
        case SCENE_RAINBOW:
            func_8009D184(&D_800F5DA0);
            func_8009D1E8((u32) ADD5D0_ROM_START, (u32) ADD5D0_ROM_END, (s32) &D_8013E260);
            func_8009D21C(0, &D_8013E260);
            D_800BDF2C.r = 0xFF;
            D_800BDF2C.g = 0xFF;
            D_800BDF2C.b = 0xFF;
            D_800BDF2C.a = 0;
            break;
    }
}

void func_8009D65C(UnkThing* arg0) {
    WorldBlock** worldBlocks;
    s32 i;
    f32 var_f2;

    if (arg0->main.levelID >= 0) {
        if (D_800AC0F0 != arg0->main.levelID) {
            if (D_800AC0F0 >= 0) {
                destroyWorld();
            }
            func_8009A8F0(arg0->main.levelID);
            func_8009D37C(arg0->main.levelID);
            D_800AC0F0 = arg0->main.levelID;
        }
        worldBlocks = getWorldBlocks();

        for (i = 0; worldBlocks != NULL && i < MAX_BLOCKS; i++) {
            if (worldBlocks[i] == NULL) {
                break;
            }
            if (worldBlocks[i]->blockModel != NULL) {
                if (worldBlocks[i]->descriptor != NULL) {
                    if (worldBlocks[i]->descriptor->gfx != NULL &&
                        worldBlocks[i]->descriptor->gfx->textures != NULL &&
                        worldBlocks[i]->descriptor->gfx->unk_08 != NULL)
                    {
                        animSetModelTreeTextureAnimation(
                            worldBlocks[i]->blockModel,
                            worldBlocks[i]->descriptor->gfx->unk_08,
                            world_func_800E21A8(arg0->main.unk_04)
                        );
                        animUpdateModelTreeAnimation(worldBlocks[i]->blockModel);
                    }
                }
            }
        }

        if (arg0->main.levelID == SCENE_RAINBOW) {
            var_f2 = (arg0->main.unk_04 * TAU) / 10000.0f;
        } else {
            var_f2 = 0.0f;
        }

        switch (arg0->main.levelID) {
            case SCENE_BEACH:
            case SCENE_VOLCANO:
            case SCENE_RIVER:
            case SCENE_VALLEY:
            case SCENE_RAINBOW:
                setSkyBoxPos(arg0->main.unk_08.x, arg0->main.unk_08.y, arg0->main.unk_08.z, var_f2, world_func_800E21A8(arg0->main.unk_04));
                break;
        }
        D_800AC0F4.unk_00 = 0.0f;
        D_800AC0F4.unk_28 = 0.0f;
        D_800AC0F4.unk_04 = 0.5f;
        func_800E3EE8_61698(&D_800AC0F4, arg0->main.unk_00_16 & 0xF, NULL, NULL);

        worldBlocks = getWorldBlocks();
        for (i = 0; worldBlocks != NULL && i < MAX_BLOCKS; i++) {
            if (worldBlocks[i] == NULL) {
                break;
            }
            if (worldBlocks[i]->blockModel != NULL) {
                worldBlocks[i]->blockModel->flags &= ~1;
            }
        }
    }
}

void func_8009D8A8(OMCamera* cam, UnkThing* arg1) {
    Vec3f sp24;
    f32 temp_f2;

    cam->perspMtx.persp.fovy = 30.0f;
    cam->perspMtx.persp.near = 10.0f;
    cam->perspMtx.persp.far = 25600.0f;

    cam->viewMtx.lookAt.eye.x = arg1->main.unk_08.x;
    cam->viewMtx.lookAt.eye.y = arg1->main.unk_08.y;
    cam->viewMtx.lookAt.eye.z = arg1->main.unk_08.z;

    cam->viewMtx.lookAt.at.x = arg1->main.unk_14.x;
    cam->viewMtx.lookAt.at.y = arg1->main.unk_14.y;
    cam->viewMtx.lookAt.at.z = arg1->main.unk_14.z;

    cam->viewMtx.lookAt.up.y = 1.0f;
    cam->viewMtx.lookAt.up.x = cam->viewMtx.lookAt.up.z = 0.0f;

    sp24.x = cam->viewMtx.lookAt.eye.x - cam->viewMtx.lookAt.at.x;
    sp24.z = cam->viewMtx.lookAt.eye.z - cam->viewMtx.lookAt.at.z;
    temp_f2 = 1.0f / sqrtf(SQ(sp24.x) + SQ(sp24.z));
    sp24.y = 1.0f;
    sp24.x *= temp_f2;
    sp24.z *= temp_f2;
    Vec3fNormalize(&sp24);
    func_800A1E6C(&sp24);
}

GObj* func_8009D9A0(UnkThingSub*, f32 arg1, UnkEC64Arg3* arg2, Texture*** arg3, void (*arg4)(GObj*));
#pragma GLOBAL_ASM("asm/nonmatchings/app_render/47380/func_8009D9A0.s")

void func_8009DEF0(UnkThing* arg0) {
    UnkV0* it;
    GObj* gobj;
    s32 i;

    D_800BDF60 = 0;

    for (i = 0; i < ARRAY_COUNT(arg0->main.unk_20); i++) {
        if (arg0->main.unk_20[i].pokemonID < 0) {
            return;
        }
        for(it = D_800ADBEC; it->unk_00 != 0; it++) {
            if (it->unk_00 == arg0->main.unk_20[i].pokemonID) {
                gobj = func_8009D9A0(&arg0->main.unk_20[i], it->unk_04, it->unk_08, it->unk_0C, it->unk_10);
                if ((arg0->main.unk_20[i].pokemonID > 0 && arg0->main.unk_20[i].pokemonID <= POKEDEX_MAX) ||
                    arg0->main.unk_20[i].pokemonID == 0x25B ||
                    arg0->main.unk_20[i].pokemonID == 0x258 ||
                    arg0->main.unk_20[i].pokemonID == 0x259 ||
                    arg0->main.unk_20[i].pokemonID == 0x25A)
                {
                    D_800BDF30[D_800BDF60] = gobj;
                    D_800BDF68[D_800BDF60] = i;
                    D_800BDF60++;
                }
                break;
            }
        }
    }
}

GObj* func_8009E050(UnkThingSub2* arg0, UnkEC64Arg3* arg1, Texture*** arg2, void (*arg3)(GObj*)) {
    GObj* gobj;
    DObj* dobj;

    gobj = omAddGObj(0x80, NULL, D_800BDF1E, 0x80000000);
    omLinkGObjDL(gobj, arg3, D_800BDF1C, 0x80000000, -1);
    anim_func_80010230(gobj, arg1, arg2, NULL, 0x1C, 0, 0);
    dobj = gobj->data.dobj;
    dobj->position.v.x = arg0->pos.x;
    dobj->position.v.y = arg0->pos.y;
    dobj->position.v.z = arg0->pos.z;
    dobj->scale.v.x = dobj->scale.v.y = dobj->scale.v.z = 0.1f;

    return gobj;
}

void func_8009E110(GObj* gobj, AnimCmd** animLists, AnimCmd*** textureAnimLists, u8 skipFrames) {
    if (animLists != NULL) {
        animSetModelTreeAnimation(gobj, animLists, skipFrames);
        animSetModelAnimationSpeed(gobj, 0.0f);
    }
    if (textureAnimLists != NULL) {
        animSetModelTreeTextureAnimation(gobj, textureAnimLists, skipFrames);
        animSetTextureAnimationSpeed(gobj, 0.0f);
    }
    animUpdateModelTreeAnimation(gobj);
}

void func_8009E1CC(UnkThing* arg0) {
    GObj* gobj;
    f32 temp_f0;
    s32 i;
    u8 temp_s3;

    for (i = 0; i < ARRAY_COUNT(arg0->main.unk_140); i++) {
        temp_s3 = arg0->main.unk_140[i].unk_01;
        switch (arg0->main.unk_140[i].unk_00) {
            case 1:
                func_8009E110(
                    func_8009E050(&arg0->main.unk_140[i], &D_800E9138, &D_800E8EB8, renderModelTypeBFogged),
                    NULL,
                    &D_800E91C0,
                    temp_s3
                );
                break;
            case 2:
                gobj = func_8009E050(&arg0->main.unk_140[i], &D_800EAED0, &D_800EAC58, renderModelTypeBFogged);
                func_8009E110(gobj, NULL, &D_800EAF60, temp_s3 & 0xF);
                gobj->data.dobj->scale.v.x = (gobj->data.dobj->scale.v.x * (temp_s3 >> 4)) / 15.0f;
                gobj->data.dobj->scale.v.y = (gobj->data.dobj->scale.v.y * (temp_s3 >> 4)) / 15.0f;
                gobj->data.dobj->scale.v.z = (gobj->data.dobj->scale.v.z * (temp_s3 >> 4)) / 15.0f;
                break;
            case 3:
                func_8009E110(
                    func_8009E050(&arg0->main.unk_140[i], &D_800EB430, &D_800EB510, renderModelTypeDFogged),
                    &D_800EAFB0,
                    &D_800EB0C0,
                    temp_s3
                );
                break;
            case 4:
                func_8009E110(
                    func_8009E050(&arg0->main.unk_140[i], &D_800EDAB0, &D_800EDB90, renderModelTypeDFogged),
                    &D_800ED5B0,
                    &D_800ED6B0,
                    temp_s3
                );
                break;
            default:
                return;
        }
    }
}

void func_8009E3D0(GObj*);
#pragma GLOBAL_ASM("asm/nonmatchings/app_render/47380/func_8009E3D0.s")

void func_8009FA00(OMCamera* arg0, UnkThing* arg1) {
    GObj* gobj;

    gobj = omAddGObj(0x80, NULL, D_800BDF1E, 0x80000000);
    gobj->userData = &arg1->main.unk_1A0;
    omLinkGObjDL(gobj, func_8009E3D0, D_800BDF1C, 0, -1);
}

void func_8009FA68(OMCamera* cam, UnkThing* arg1) {
    GObj* temp_s1;
    GObj* var_s0;
    s32 levelID = arg1->main.levelID;

    if (levelID >= 0) {
        if (levelID == SCENE_CAVE) {
            cam->flags |= 2;
            cam->bgColor = 0x05080401;
        } else {
            cam->flags &= ~2;
        }
        var_s0 = omGObjListHead[D_800BDF1E];
        if (var_s0 != NULL) {
            do {
                temp_s1 = var_s0->next;
                omDeleteGObj(var_s0);
                var_s0 = temp_s1;
            } while (temp_s1 != NULL);
        }
        D_800BDF18 = arg1;
        func_8009D65C(arg1);
        func_8009DEF0(arg1);
        func_8009E1CC(arg1);
        func_8009FA00(cam, arg1);
        func_8009D8A8(cam, arg1);
    }
}

void func_8009FB50(u8 arg0, u8 arg1, u8 arg2) {
    s32* temp_v0;

    D_800BDF1C = arg0;
    D_800BDF1D = arg1;
    D_800BDF1E = arg2;
    D_800AC0F0 = -1;
    temp_v0 = func_800A73C0((u32) AB5980_ROM_START, (u32) AB5980_ROM_END);
    if (temp_v0 != NULL) {
        func_8009D21C(3, temp_v0);
    }
}

void func_8009FBC4(void) {
    GObj* curObj;
    GObj* nextObj;

    destroyWorld();
    curObj = omGObjListHead[D_800BDF1E];
    while (curObj != NULL) {
        nextObj = curObj->next;
        omDeleteGObj(curObj);
        curObj = nextObj;
    }
    D_800AC0F0 = -1;
}

void func_8009FC2C(s32 arg0) {
    D_800AC0F0 = arg0;
}

void func_8009FC38(PhotoData* arg0) {
    if (arg0->levelID != D_800AC0F0) {
        if (D_800AC0F0 >= 0) {
            destroyWorld();
        }
        func_8009A8F0(arg0->levelID);
        func_8009D37C(arg0->levelID);
        D_800AC0F0 = arg0->levelID;
    }
}
