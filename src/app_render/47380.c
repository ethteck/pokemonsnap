#include "common_structs.h"
#include "app_render.h"

#include "beach/beach.h"
#if !defined(M2CTX) && !defined(PERMUTER)
#include "ld_addrs.h"
#include "string.h"
#endif
#include "world/world.h"

s32 func_8009FCC0(void);
void func_800AB050(f32 arg0, s32 arg1, UNK_TYPE* arg2, UNK_TYPE* arg3, UNK_TYPE* arg4);
s32 func_80364494_5048A4(UnkRustRat* arg0, f32* arg1, f32* arg2, f32* arg3, f32* arg4);

typedef struct Unk8009C604 {
    /* 0x00 */ UnkRustRat* unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
} Unk8009C604; // size = 0xC

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

typedef struct Unkfunc_8009BDDCSub {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ AnimCmd** modelAnims;
    /* 0x08 */ AnimCmd*** matAnims;
} Unkfunc_8009BDDCSub; // size = 0xC

typedef struct Unkfunc_8009BDDC {
    /* 0x00 */ u32 pokemonID;
    /* 0x04 */ Unkfunc_8009BDDCSub* unk_04;
    /* 0x08 */ s32 unk_08; // number of unk_04 records?
} Unkfunc_8009BDDC;        // size = 0xC

typedef struct Struct_800ACD9C {
    /* 0x00 */ UNK_TYPE* unk_00;
    /* 0x04 */ char unk_04[8];
} Struct_800ACD9C; // size = 0xC

extern s32 D_800AC0F0; // level id?
extern MovementState D_800AC0F4;
extern Struct_800ACD9C D_800ACD9C[];
extern Struct_800ACD9C D_800AD444[];
extern Struct_800ACD9C D_800AD474[];
extern Unkfunc_8009BDDC D_800AD4B8[67];
extern Unkfunc_8009BDDC D_800AD9A4[16];
extern Unk1C D_800ADA64[];
extern UnkV0 D_800ADBEC[];
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
extern PhotoData* D_800BDF18;
extern u8 D_800BDF1C;
extern u8 D_800BDF1D;
extern u8 D_800BDF1E;
extern s32 D_800BDF20[3];
extern ucolor D_800BDF2C;
extern GObj* D_800BDF30[];
extern s32 D_800BDF60;

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
extern WorldSetup volcano_WorldSetup;
extern WorldSetup D_80100720;
extern WorldSetup D_8011E6CC;
extern WorldSetup D_8012A0E8;
extern WorldSetup D_8012AC90;

extern UNK_TYPE D_8013E260;
extern UNK_TYPE D_8017A780;
extern UNK_TYPE D_80188D28;
extern UNK_TYPE D_8018A6F0;
extern UNK_TYPE D_801AFD30;
extern UNK_TYPE D_8017A710;
extern UNK_TYPE D_801B1230;
extern UNK_TYPE D_801B1D40;
extern UNK_TYPE D_801B6B60;
extern UNK_TYPE D_801CE400;
extern UNK_TYPE D_8017C090;
extern UNK_TYPE D_801CF770;
extern UNK_TYPE D_801CF840;
extern UNK_TYPE D_801D6840;
extern UNK_TYPE D_80186E20;
extern UNK_TYPE D_80188CB0;

extern s32 gPokemonIdInFocus;
extern UnkThing PokemonDetector_Photo[2];
extern s32 PokemonDetector_TakenPhotoIndex;

char* getPokemonName(s32 pkmnID) {
    if (pkmnID > 0 && pkmnID <= POKEDEX_MAX) {
        return D_800AE284[pkmnID];
    }
    if (pkmnID == PokemonID_1004 || pkmnID == PokemonID_1010 || pkmnID == PokemonID_1018 || pkmnID == PokemonID_1022 ||
        pkmnID == PokemonID_KOFFING_SMOKE || pkmnID == PokemonID_1035) {
        if (checkPlayerFlag(PFID_HAS_DASH_ENGINE) == 0) {
            return "？";
        }
    }
    if (pkmnID == PokemonID_1004 || pkmnID == PokemonID_1010 || pkmnID == PokemonID_1018 || pkmnID == PokemonID_1022 ||
        pkmnID == PokemonID_KOFFING_SMOKE || pkmnID == PokemonID_1035) {
        if (!func_800BF3D4_5C274(pkmnID)) {
            return "Ｓｉｇｎ？";
        }
    }
    switch (pkmnID) {
        case PokemonID_603:
            return D_800AE284[PokemonID_SHELLDER];
        case PokemonID_1004:
        case PokemonID_1010:
        case PokemonID_1018:
        case PokemonID_1022:
        case PokemonID_KOFFING_SMOKE:
        case PokemonID_1035:
            return "Ｓｉｇｎ";
        case PokemonID_500:
        case PokemonID_MOLTRES_EGG:
        case PokemonID_601:
        case PokemonID_602:
            return "？";
        default:
            return NULL;
    }
}

s32 func_8009BB4C(s32 pkmnID) {
    s32 ret;
    s32 temp = D_800AE4E4[150];

    if (pkmnID == PokemonID_603) {
        pkmnID = PokemonID_SHELLDER;
    }
    if (pkmnID > 0 && pkmnID <= POKEDEX_MAX) {
        ret = D_800AE4E4[pkmnID - 1];
    } else {
        switch (pkmnID) {
            case PokemonID_1004:
                ret = temp + 1;
                break;
            case PokemonID_1010:
                ret = temp + 2;
                break;
            case PokemonID_KOFFING_SMOKE:
                ret = temp + 3;
                break;
            case PokemonID_1022:
                ret = temp + 4;
                break;
            case PokemonID_1018:
                ret = temp + 5;
                break;
            case PokemonID_1035:
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
            ret = PokemonID_1004;
            break;
        case 0x80:
            ret = PokemonID_1018;
            break;
        case 0xA0:
            ret = PokemonID_1022;
            break;
        case 0xE0:
            ret = PokemonID_1035;
            break;
        case 0x20:
            ret = arg0->main.unk_20[0].pokemonID;
            break;
    }
    return ret;
}

s8 func_8009BD4C(s16 arg0, AnimCmd** anims, Unkfunc_8009BDDC* arg2, s32 arg3) {
    Unkfunc_8009BDDCSub* sub;
    s32 i;
    s32 j;

    for (i = 0; i < arg3; i++) {
        if (arg0 == arg2[i].pokemonID) {
            sub = arg2[i].unk_04;
            for (j = 0; j < arg2[i].unk_08; j++) {
                if (anims == sub[j].modelAnims) {
                    return j;
                }
            }
            return -1;
        }
    }
    return -1;
}

f32 func_8009BDDC(s16 pokemonID, s8 arg1) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_800AD4B8); i++) {
        if (D_800AD4B8[i].pokemonID == pokemonID) {
            return D_800AD4B8[i].unk_04[arg1].unk_00;
        }
    }
    return -1.0f;
}

s32 func_8009BF48(PokemonPhotoData* arg0, GObj* arg1) {
    Pokemon* pokemon = GET_POKEMON(arg1);
    s32 pokemonID;
    DObj* model = arg1->data.dobj;
    s32 i;
    s32 unused[2];
    s32 sp24;

    pokemonID = pokemon->id;
    if ((arg1->flags & GOBJ_FLAG_HIDDEN) || !pokemon->tangible) {
        return false;
    }
    if (func_80364718_504B28(arg1)) {
        return false;
    }

    switch (pokemonID) {
        case PokemonID_MOLTRES_EGG:
        case PokemonID_601:
        case PokemonID_602:
        case PokemonID_603:
        case PokemonID_GATE:
        case PokemonID_1002:
        case PokemonID_1003:
        case PokemonID_1006:
        case PokemonID_1008:
        case PokemonID_1009:
        case PokemonID_1010:
        case PokemonID_1012:
        case PokemonID_1013:
        case PokemonID_KOFFING_SMOKE:
        case PokemonID_SMOKE_PUFF:
        case PokemonID_1030:
        case PokemonID_1031:
        case PokemonID_1033:
        case PokemonID_1037:
        case PokemonID_1038:
            break;
        default:
            if (pokemonID <= 0 || pokemonID > POKEDEX_MAX) {
                return false;
            }
            break;
    }

    arg0->pokemonID = pokemonID;
    if (pokemonID < PokemonID_1000) {
        arg0->unk_00_19 = pokemon->unk_10E;
        arg0->unk_00_13 = func_8009BD4C(pokemonID, pokemon->modelAnims, D_800AD4B8, ARRAY_COUNT(D_800AD4B8));
        if (pokemon->unk_10C > 0) {
            arg0->unk_03 = pokemon->unk_10C;
        } else {
            sp24 = func_8009BDDC(arg0->pokemonID, arg0->unk_00_13);
            if (sp24 >= func_8009FCC0()) {
                arg0->unk_03 = 0;
            } else if (sp24 > 0) {
                arg0->unk_03 = sp24;
            } else {
                arg0->unk_03 = 0;
            }
        }
    } else {
        arg0->unk_03 = 0;
        arg0->unk_00_19 = 0;
        arg0->unk_00_13 = func_8009BD4C(pokemonID, pokemon->modelAnims, D_800AD9A4, ARRAY_COUNT(D_800AD9A4));
    }

    arg0->animationTime = arg1->animationTime;
    if (model->unk_4C != NULL) {
        uintptr_t csr = (uintptr_t) model->unk_4C->data;
        for (i = 0; i < 3; i++) {
            switch (model->unk_4C->kinds[i]) {
                case 0:
                    break;
                case 1:
                    arg0->position.x = ((struct Mtx3Float*) csr)->v.x;
                    arg0->position.y = ((struct Mtx3Float*) csr)->v.y;
                    arg0->position.z = ((struct Mtx3Float*) csr)->v.z;
                    csr += sizeof(union Mtx3fi);
                    break;
                case 2:
                    arg0->yaw = ((struct Mtx4Float*) csr)->f[2];
                    csr += sizeof(struct Mtx4Float);
                    break;
                case 3:
                    csr += sizeof(struct Mtx3Float);
                    break;
            }
        }
    } else {
        arg0->position.x = model->position.v.x;
        arg0->position.y = model->position.v.y;
        arg0->position.z = model->position.v.z;
        arg0->yaw = model->rotation.f[2];
    }
    return true;
}

void func_8009C25C(UnkThing* arg0, u8 objIndex) {
    GObj* obj;
    s32 i = 0;
    obj = omGObjListHead[objIndex];

    while (obj != NULL && i < ARRAY_COUNT(arg0->main.unk_20)) {
        if (func_8009BF48(&arg0->main.unk_20[i], obj) != 0) {
            arg0->pokemonObjects[i] = obj;
            i++;
        }
        obj = obj->next;
    }
}

s32 func_8009C304(ItemPhotoData* arg0, GObj* obj) {
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
        arg0->itemType = 3;
        arg0->animationTime = (s32) obj->animationTime;
    } else if (payload == D_800EDAE0) {
        arg0->itemType = 4;
        arg0->animationTime = (s32) obj->animationTime;
    } else if (payload == D_800E9168) {
        arg0->itemType = 1;
        arg0->animationTime = (s32) dobj->firstChild->mobjList->timePassed;
    } else if (payload == D_800EAF00) {
        arg0->itemType = 2;
        arg0->animationTime = (s32) dobj->firstChild->mobjList->timePassed & 0xF;
        arg0->animationTime |= ((s32) ((dobj->scale.v.x * 15.0f) / 0.1f) * 16);
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
            (func_8009C304(&arg0->main.unk_140[i], obj) != 0)) {
            i++;
        }
        obj = obj->next;
    }
}

void func_8009C4F4(UnkThing* arg0, MovementState* arg1, OMCamera* arg2) {
    arg0->main.levelID = getLevelId();
    arg0->main.unk_00_16 = arg1->block->index;
    arg0->main.unk_04.f32 = getGlobalTime();
    arg0->main.unk_08.x = arg2->viewMtx.lookAt.eye.x;
    arg0->main.unk_08.y = arg2->viewMtx.lookAt.eye.y;
    arg0->main.unk_08.z = arg2->viewMtx.lookAt.eye.z;
    arg0->main.unk_14.x = arg2->viewMtx.lookAt.at.x;
    arg0->main.unk_14.y = arg2->viewMtx.lookAt.at.y;
    arg0->main.unk_14.z = arg2->viewMtx.lookAt.at.z;
}

s32 func_8009C584(const void* a, const void* b) {
    const Unk8009C604* a1 = a;
    const Unk8009C604* b1 = b;

    if (a1->unk_08 < b1->unk_08) {
        return -1;
    } else if (b1->unk_08 < a1->unk_08) {
        return 1;
    }

    return 0;
}

s32 func_8009C5C4(const void* a, const void* b) {
    const Unk8009C604* a1 = a;
    const Unk8009C604* b1 = b;

    if (b1->unk_04 < a1->unk_04) {
        return -1;
    } else if (a1->unk_04 < b1->unk_04) {
        return 1;
    }

    return 0;
}

void func_8009C604(UnkThing* arg0) {
    s32 i;
    s32 count;
    UnkRustRat* ptr;
    f32 sp520, sp51C, sp518, sp514;
    s32 unused;
    Unk8009C604 sp60[100];

    count = 0;
    for (i = 0; i < ARRAY_COUNT(D_800BE1A8); i++) {
        for (ptr = D_800BE1A8[i]; ptr != NULL; ptr = ptr->next) {
            if (func_80364494_5048A4(ptr, &sp520, &sp51C, &sp518, &sp514) || (s16) (ptr->unk_40 * 128.0f) == 0 || ptr->unk_48.a == 0) {
                if (0) {
                } // TODO fake match
                continue;
            }
            sp60[count].unk_00 = ptr;
            sp60[count].unk_04 = ptr->unk_40 * sp514;
            sp60[count].unk_08 = sp518;
            count++;
            if (count >= 100) {
                break;
            }
        }
        if (count >= 100) {
            break;
        }
    }

    ptr = sp60[count - i - 1].unk_00; // TODO fake match

    if (count > 32) {
        qsort2(sp60, count, sizeof(Unk8009C604), func_8009C5C4);
        count = 32;
    }

    qsort2(sp60, count, sizeof(Unk8009C604), func_8009C584);
    for (i = 0; i < count; i++) {
        ptr = sp60[count - i - 1].unk_00;
        arg0->main.unk_1A0[i].unk_00 = ptr->unk_0A;
        arg0->main.unk_1A0[i].unk_01 = ptr->unk_0B;
        arg0->main.unk_1A0[i].unk_03 = (ptr->flags >> 4) & 0xFF;
        arg0->main.unk_1A0[i].unk_02 = ptr->unk_08 & 7;
        arg0->main.unk_1A0[i].unk_04 = ptr->unk_20.x * 8.0f;
        arg0->main.unk_1A0[i].unk_06 = ptr->unk_20.y * 8.0f;
        arg0->main.unk_1A0[i].unk_08 = ptr->unk_20.z * 8.0f;
        arg0->main.unk_1A0[i].unk_0A = ptr->unk_40 * 128.0f;
        arg0->main.unk_1A0[i].unk_0C = ptr->unk_48;
    }
}

void func_8009C8E4(OMCamera* arg0, MovementState* arg1, UnkThing* arg2) {
    s32 i;

    // clang-format off
    for (i = 0; i < ARRAY_COUNT(arg2->main.unk_140); i++) { arg2->main.unk_140[i].itemType = -1; }
    // clang-format on

    // clang-format off
    for (i = 0; i < ARRAY_COUNT(arg2->main.unk_1A0); i++) { arg2->main.unk_1A0[i].unk_00 = -1; }
    // clang-format on

    for (i = 0; i < ARRAY_COUNT(arg2->main.unk_20); i++) {
        arg2->main.unk_20[i].pokemonID = -1;
        arg2->pokemonObjects[i] = NULL;
    }

    arg2->pokemonInFocus = NULL;
    func_803643E0_5047F0(arg0);
    func_8009C4F4(arg2, arg1, arg0);
    func_8009C25C(arg2, 3);
    func_8009C450(arg2, 4);
    func_8009C604(arg2);
}

s32 makePhoto(GObj* pokemonObj) {
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

    if (pokemonObj != NULL) {
        D_800AE27C++;

        for (i = 0; i < D_800AE280 && i < ARRAY_COUNT(D_800BDF20); i++) {
            if (D_800BDF20[i] == gPokemonIdInFocus) {
                break;
            }
        }

        if (i >= D_800AE280 && i < 3) {
            D_800BDF20[D_800AE280] = gPokemonIdInFocus;
            D_800AE280++;
        }
    }

    temp_s4 = &D_800B0598[gPhotoCount];
    sp38 = &PokemonDetector_Photo[PokemonDetector_TakenPhotoIndex];
    memcpy(temp_s4, sp38, 0x20);

    for (i = 0; i < ARRAY_COUNT(temp_s4->unk_140); i++) {
        memcpy(&temp_s4->unk_140[i], &sp38->main.unk_140[i], sizeof(temp_s4->unk_140[0]));
    }

    for (i = 0; i < ARRAY_COUNT(temp_s4->unk_1A0); i++) {
        memcpy(&temp_s4->unk_1A0[i], &sp38->main.unk_1A0[i], sizeof(temp_s4->unk_1A0[0]));
    }

    if (pokemonObj == NULL) {
        for (i = 0; i < ARRAY_COUNT(temp_s4->unk_20); i++) {
            memcpy(&temp_s4->unk_20[i], &sp38->main.unk_20[i], sizeof(temp_s4->unk_20[0]));
        }
    } else {
        sp34 = gPokemonIdInFocus;
        // TODO clean if
        if (sp34 == PokemonID_1004 || sp34 == PokemonID_1018 || sp34 == PokemonID_1022 || (cond = true, sp34 == PokemonID_1035)) {
            for (i = 0; i < ARRAY_COUNT(temp_s4->unk_20); i++) {
                memcpy(&temp_s4->unk_20[i], &sp38->main.unk_20[i], sizeof(temp_s4->unk_20[0]));
            }
        } else {
            for (i = 0; i < ARRAY_COUNT(sp38->pokemonObjects); i++) {
                if (pokemonObj == sp38->pokemonObjects[i]) {
                    cond = false;
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
                    if (pokemonObj == sp38->pokemonObjects[i]) {
                        memcpy(&temp_s4->unk_20[0], &sp38->main.unk_20[i], sizeof(temp_s4->unk_20[0]));
                    } else {
                        memcpy(&temp_s4->unk_20[idx], &sp38->main.unk_20[i], sizeof(temp_s4->unk_20[1]));
                        idx++;
                    }
                }
            }
        }

        switch (sp34) {
            // TODO bitfield pieces?
            default:
                temp_s4->unk_00_16 |= 0x20;
                break;
            case PokemonID_1004:
                temp_s4->unk_00_16 |= 0x40 | 0x20;
                break;
            case PokemonID_1018:
                temp_s4->unk_00_16 |= 0x80;
                break;
            case PokemonID_1022:
                temp_s4->unk_00_16 |= 0x80 | 0x20;
                break;
            case PokemonID_1035:
                temp_s4->unk_00_16 |= 0x80 | 0x40 | 0x20;
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

    gobj = omAddGObj(OBJID_128, NULL, D_800BDF1E, 0x80000000);
    omLinkGObjDL(gobj, arg3->unk_10, D_800BDF1C, 0x80000000, -1);
    anim_func_80010230(gobj, arg3->unk_8, arg3->unk_C, NULL, 0x1C, 0, 0);
    if (arg3->unk_14 != NULL) {
        animSetModelTreeAnimation(gobj, arg3->unk_14, world_func_800E21A8(D_800BDF18->unk_04.f32));
        animSetModelAnimationSpeed(gobj, 0.0f);
        if (arg3->unk_18 != NULL) {
            animSetModelTreeTextureAnimation(gobj, arg3->unk_18, world_func_800E21A8(D_800BDF18->unk_04.f32));
            animSetTextureAnimationSpeed(gobj, 0.0f);
        }
        animUpdateModelTreeAnimation(gobj);
    }
    dobj = gobj->data.dobj;
    dobj->position.v.x = (arg2->translation.x + (arg0->descriptor->worldPos.x - arg1->descriptor->worldPos.x)) * 100.0f;
    dobj->position.v.y = (arg2->translation.y + (arg0->descriptor->worldPos.y - arg1->descriptor->worldPos.y)) * 100.0f;
    dobj->position.v.z = (arg2->translation.z + (arg0->descriptor->worldPos.z - arg1->descriptor->worldPos.z)) * 100.0f;
    dobj->rotation.f[1] = dobj->rotation.f[3] = 0.0f;
    dobj->rotation.f[2] = arg2->euler.y;
    temp_f0 = arg3->scale * 0.1f;
    dobj->scale.v.x = dobj->scale.v.y = dobj->scale.v.z = temp_f0;
    if (arg3->id == PokemonID_1018 && (D_800BDF18->unk_00_16 & 0xE0) != 0x80) { // todo bitfield
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
    createWorld(arg0, 99, 100, 126, D_800BDF1D, D_800BDF1C, func_8009D0B4, 0, 0);
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
            func_8009D184(&volcano_WorldSetup);
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

void func_8009D65C(PhotoData* photoData) {
    WorldBlock** worldBlocks;
    s32 i;
    f32 var_f2;

    if (photoData->levelID >= 0) {
        if (D_800AC0F0 != photoData->levelID) {
            if (D_800AC0F0 >= 0) {
                destroyWorld();
            }
            func_8009A8F0(photoData->levelID);
            func_8009D37C(photoData->levelID);
            D_800AC0F0 = photoData->levelID;
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
                        worldBlocks[i]->descriptor->gfx->unk_08 != NULL) {
                        animSetModelTreeTextureAnimation(
                            worldBlocks[i]->blockModel,
                            worldBlocks[i]->descriptor->gfx->unk_08,
                            world_func_800E21A8(photoData->unk_04.f32));
                        animUpdateModelTreeAnimation(worldBlocks[i]->blockModel);
                    }
                }
            }
        }

        if (photoData->levelID == SCENE_RAINBOW) {
            var_f2 = (photoData->unk_04.f32 * TAU) / 10000.0f;
        } else {
            var_f2 = 0.0f;
        }

        switch (photoData->levelID) {
            case SCENE_BEACH:
            case SCENE_VOLCANO:
            case SCENE_RIVER:
            case SCENE_VALLEY:
            case SCENE_RAINBOW:
                setSkyBoxPos(photoData->unk_08.x, photoData->unk_08.y, photoData->unk_08.z, var_f2, world_func_800E21A8(photoData->unk_04.f32));
                break;
        }
        D_800AC0F4.moveTime = 0.0f;
        D_800AC0F4.speedMult = 0.0f;
        D_800AC0F4.cpTime = 0.5f;
        Movement_Init(&D_800AC0F4, photoData->unk_00_16 & 0xF, NULL, NULL);

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

void func_8009D8A8(OMCamera* cam, PhotoData* photoData) {
    Vec3f sp24;
    f32 temp_f2;

    cam->perspMtx.persp.fovy = 30.0f;
    cam->perspMtx.persp.near = 10.0f;
    cam->perspMtx.persp.far = 25600.0f;

    cam->viewMtx.lookAt.eye.x = photoData->unk_08.x;
    cam->viewMtx.lookAt.eye.y = photoData->unk_08.y;
    cam->viewMtx.lookAt.eye.z = photoData->unk_08.z;

    cam->viewMtx.lookAt.at.x = photoData->unk_14.x;
    cam->viewMtx.lookAt.at.y = photoData->unk_14.y;
    cam->viewMtx.lookAt.at.z = photoData->unk_14.z;

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

GObj* func_8009D9A0(PokemonPhotoData* arg0, f32 arg1, UnkEC64Arg3* arg2, Texture*** arg3, void (*arg4)(GObj*)) {
    GObj* gobj;
    Unkfunc_8009BDDC* v00;
    s32 i;
    Mtx4f spB4;
    Mtx4f sp74;
    DObj* model;
    s32 sp6C;

    if (D_800AD9A4) {
    } // TODO fake match
    gobj = omAddGObj(OBJID_128, NULL, D_800BDF1E, 0x80000000);
    if (arg0->pokemonID == PokemonID_MAGNETON) {
        omLinkGObjDL(gobj, arg4, D_800BDF1C, 1, -1);
    } else {
        omLinkGObjDL(gobj, arg4, D_800BDF1C, 0x80000000, -1);
    }
    anim_func_80010230(gobj, arg2, arg3, NULL, MTX_TYPE_ROTATE_RPY_TRANSLATE_SCALE, 0, 0);

    if (arg2) {
    } // TODO fake match

    if (arg0->pokemonID < PokemonID_1000) {
        v00 = D_800AD4B8;
        sp6C = ARRAY_COUNT(D_800AD4B8);
    } else {
        v00 = D_800AD9A4;
        sp6C = ARRAY_COUNT(D_800AD9A4);
    }

    for (i = 0; i < sp6C; i++) {
        if (v00[i].pokemonID == arg0->pokemonID) {
            if (v00[i].unk_04[arg0->unk_00_13].modelAnims != NULL) {
                animSetModelTreeAnimation(gobj, v00[i].unk_04[arg0->unk_00_13].modelAnims, arg0->animationTime);
                animSetModelAnimationSpeed(gobj, 0.0f);
            }
            if (v00[i].unk_04[arg0->unk_00_13].matAnims != NULL) {
                animSetModelTreeTextureAnimation(gobj, v00[i].unk_04[arg0->unk_00_13].matAnims, arg0->animationTime);
                animSetTextureAnimationSpeed(gobj, 0.0f);
            }
            animUpdateModelTreeAnimation(gobj);
        }
    }

    model = gobj->data.dobj;
    arg1 *= 0.1f;
    hal_rotate_rpy_translate_scale_f(spB4, arg0->position.x, arg0->position.y, arg0->position.z, 0.0f, arg0->yaw, 0.0f, arg1, arg1, arg1);
    hal_rotate_rpy_translate_scale_f(sp74, model->position.v.x, model->position.v.y, model->position.v.z,
                                     model->rotation.f[1], model->rotation.f[2], model->rotation.f[3],
                                     model->scale.v.x, model->scale.v.y, model->scale.v.z);
    guMtxCatF(sp74, spB4, spB4);
    model->position.v.x = spB4[3][0];
    model->position.v.y = spB4[3][1];
    model->position.v.z = spB4[3][2];
    model->rotation.f[2] += arg0->yaw;
    model->scale.v.x *= arg1;
    model->scale.v.y *= arg1;
    model->scale.v.z *= arg1;

    switch (arg0->pokemonID) {
        case PokemonID_CHANSEY:
            if (D_800ACD9C[arg0->unk_00_13].unk_00 == &D_80186E20) {
                model->scale.v.x *= 0.5f;
                model->scale.v.y *= 0.5f;
                model->scale.v.z *= 0.5f;
            }
            break;
        case PokemonID_602:
            if (D_800AD474[arg0->unk_00_13].unk_00 == &D_80188CB0) {
                f32 f2;
                if (arg0->animationTime < 0 || arg0->animationTime > 60.0f) {
                    f2 = 1.0f;
                } else {
                    f2 = arg0->animationTime / 60.0f;
                }
                if (f2 < 0.0f) {
                    f2 = 0.0f;
                }
                if (f2 > 1.0f) {
                    f2 = 1.0f;
                }
                func_800AB050(f2, 0x150, &D_80188D28, &D_801AFD30, &D_8018A6F0);
            } else {
                memcpy(&D_80188D28, &D_801AFD30, 0x1500);
            }
            break;
        case PokemonID_601:
            if (D_800AD444[arg0->unk_00_13].unk_00 == &D_8017A710) {
                f32 f2;
                if (arg0->animationTime < 0 || arg0->animationTime > 60.0f) {
                    f2 = 1.0f;
                } else {
                    f2 = arg0->animationTime / 60.0f;
                }
                if (f2 < 0.0f) {
                    f2 = 0.0f;
                }
                if (f2 > 1.0f) {
                    f2 = 1.0f;
                }
                func_800AB050(f2, 0x144, &D_8017A780, &D_801CE400, &D_8017C090);
            } else {
                memcpy(&D_8017A780, &D_801CE400, 0x1440);
            }
            break;
    }

    return gobj;
}

void func_8009DEF0(PhotoData* photoData) {
    UnkV0* it;
    GObj* gobj;
    s32 i;

    D_800BDF60 = 0;

    for (i = 0; i < ARRAY_COUNT(photoData->unk_20); i++) {
        if (photoData->unk_20[i].pokemonID < 0) {
            return;
        }
        for (it = D_800ADBEC; it->unk_00 != 0; it++) {
            if (it->unk_00 == photoData->unk_20[i].pokemonID) {
                gobj = func_8009D9A0(&photoData->unk_20[i], it->unk_04, it->unk_08, it->unk_0C, it->unk_10);
                if ((photoData->unk_20[i].pokemonID > 0 && photoData->unk_20[i].pokemonID <= POKEDEX_MAX) ||
                    photoData->unk_20[i].pokemonID == PokemonID_603 ||
                    photoData->unk_20[i].pokemonID == PokemonID_MOLTRES_EGG ||
                    photoData->unk_20[i].pokemonID == PokemonID_601 ||
                    photoData->unk_20[i].pokemonID == PokemonID_602) {
                    D_800BDF30[D_800BDF60] = gobj;
                    D_800BDF68[D_800BDF60] = i;
                    D_800BDF60++;
                }
                break;
            }
        }
    }
}

GObj* func_8009E050(ItemPhotoData* arg0, UnkEC64Arg3* arg1, Texture*** arg2, void (*arg3)(GObj*)) {
    GObj* gobj;
    DObj* dobj;

    gobj = omAddGObj(OBJID_128, NULL, D_800BDF1E, 0x80000000);
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

void func_8009E1CC(PhotoData* photoData) {
    GObj* gobj;
    f32 temp_f0;
    s32 i;
    u8 temp_s3;

    for (i = 0; i < ARRAY_COUNT(photoData->unk_140); i++) {
        temp_s3 = photoData->unk_140[i].animationTime;
        switch (photoData->unk_140[i].itemType) {
            case 1:
                func_8009E110(
                    func_8009E050(&photoData->unk_140[i], &D_800E9138, &D_800E8EB8, renderModelTypeBFogged),
                    NULL,
                    &D_800E91C0,
                    temp_s3);
                break;
            case 2:
                gobj = func_8009E050(&photoData->unk_140[i], &D_800EAED0, &D_800EAC58, renderModelTypeBFogged);
                func_8009E110(gobj, NULL, &D_800EAF60, temp_s3 & 0xF);
                gobj->data.dobj->scale.v.x = (gobj->data.dobj->scale.v.x * (temp_s3 >> 4)) / 15.0f;
                gobj->data.dobj->scale.v.y = (gobj->data.dobj->scale.v.y * (temp_s3 >> 4)) / 15.0f;
                gobj->data.dobj->scale.v.z = (gobj->data.dobj->scale.v.z * (temp_s3 >> 4)) / 15.0f;
                break;
            case 3:
                func_8009E110(
                    func_8009E050(&photoData->unk_140[i], &D_800EB430, &D_800EB510, renderModelTypeDFogged),
                    &D_800EAFB0,
                    &D_800EB0C0,
                    temp_s3);
                break;
            case 4:
                func_8009E110(
                    func_8009E050(&photoData->unk_140[i], &D_800EDAB0, &D_800EDB90, renderModelTypeDFogged),
                    &D_800ED5B0,
                    &D_800ED6B0,
                    temp_s3);
                break;
            default:
                return;
        }
    }
}

void func_8009E3D0(GObj*);
#pragma GLOBAL_ASM("asm/nonmatchings/app_render/47380/func_8009E3D0.s")

void func_8009FA00(OMCamera* cam, PhotoData* photoData) {
    GObj* gobj;

    gobj = omAddGObj(OBJID_128, NULL, D_800BDF1E, 0x80000000);
    gobj->userData = &photoData->unk_1A0;
    omLinkGObjDL(gobj, func_8009E3D0, D_800BDF1C, 0, -1);
}

void func_8009FA68(OMCamera* cam, PhotoData* photoData) {
    GObj* next;
    GObj* it;
    s32 levelID = photoData->levelID;

    if (levelID >= 0) {
        if (levelID == SCENE_CAVE) {
            cam->flags |= CAMERA_FLAG_2;
            cam->bgColor = 0x05080401;
        } else {
            cam->flags &= ~CAMERA_FLAG_2;
        }

        it = omGObjListHead[D_800BDF1E];
        while (it != NULL) {
            next = it->next;
            omDeleteGObj(it);
            it = next;
        }

        D_800BDF18 = photoData;
        func_8009D65C(photoData);
        func_8009DEF0(photoData);
        func_8009E1CC(photoData);
        func_8009FA00(cam, photoData);
        func_8009D8A8(cam, photoData);
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
