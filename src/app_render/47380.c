#include "common_structs.h"
#include "app_render.h"

#include "beach/beach.h"
#if !defined(M2CTX) && !defined(PERMUTER)
#include "ld_addrs.h"
#include "string.h"
#endif
#include "world/world.h"
#include "effect.h"

s32 getNumberOfPoses(void);
void func_800AB050(f32 arg0, s32 arg1, UNK_TYPE* arg2, UNK_TYPE* arg3, UNK_TYPE* arg4);

typedef struct Unk8009C604 {
    /* 0x00 */ Particle* particle;
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

extern Unkfunc_8009BDDC D_800AD4B8[67];

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
extern u8 D_800ACE04[];
extern u8 D_800ACE58[];
extern u8 D_800ACE7C[];
extern u8 D_800ACEA0[];
extern u8 D_800ACEC4[];
extern u8 D_800ACF0C[];
extern u8 D_800ACF54[];
extern u8 D_800ACFC0[];
extern u8 D_800AD038[];
extern u8 D_800AD068[];
extern u8 D_800AD0A4[];
extern u8 D_800AD0B0[];
extern u8 D_800AD11C[];
extern u8 D_800AD158[];
extern u8 D_800AD260[];
extern u8 D_800AD2D8[];
extern u8 D_800AD2FC[];
extern u8 D_800AD32C[];
extern u8 D_800AD368[];
extern u8 D_800AD38C[];
extern u8 D_800AD3C8[];
extern u8 D_800AD428[];
extern u8 D_800AD440[];
extern u8 D_800AD470[];
extern u8 D_800AD4A0[];
extern const char D_800AF420[];
extern const char D_800AF424[];
extern const char D_800AF438[];
extern const char D_800AF448[];
extern const char D_800AF45C[];
extern const char D_800AF474[];
extern const char D_800AF48C[];
extern const char D_800AF4A0[];
extern const char D_800AF4B4[];
extern const char D_800AF4C8[];
extern const char D_800AF4DC[];
extern const char D_800AF4F0[];
extern const char D_800AF500[];
extern const char D_800AF518[];
extern const char D_800AF528[];
extern const char D_800AF538[];
extern const char D_800AF54C[];
extern const char D_800AF55C[];
extern const char D_800AF570[];
extern const char D_800AF580[];
extern const char D_800AF590[];
extern const char D_800AF5A4[];
extern const char D_800AF5B4[];
extern const char D_800AF5C4[];
extern const char D_800AF5D0[];
extern const char D_800AF5DC[];
extern const char D_800AF5EC[];
extern const char D_800AF5FC[];
extern const char D_800AF610[];
extern const char D_800AF624[];
extern const char D_800AF634[];
extern const char D_800AF648[];
extern const char D_800AF65C[];
extern const char D_800AF670[];
extern const char D_800AF684[];
extern const char D_800AF698[];
extern const char D_800AF6AC[];
extern const char D_800AF6C0[];
extern const char D_800AF6D0[];
extern const char D_800AF6E4[];
extern const char D_800AF6FC[];
extern const char D_800AF714[];
extern const char D_800AF720[];
extern const char D_800AF730[];
extern const char D_800AF740[];
extern const char D_800AF74C[];
extern const char D_800AF760[];
extern const char D_800AF76C[];
extern const char D_800AF780[];
extern const char D_800AF790[];
extern const char D_800AF7A4[];
extern const char D_800AF7B4[];
extern const char D_800AF7C4[];
extern const char D_800AF7D4[];
extern const char D_800AF7E4[];
extern const char D_800AF7F4[];
extern const char D_800AF804[];
extern const char D_800AF814[];
extern const char D_800AF828[];
extern const char D_800AF83C[];
extern const char D_800AF850[];
extern const char D_800AF860[];
extern const char D_800AF874[];
extern const char D_800AF888[];
extern const char D_800AF894[];
extern const char D_800AF8A4[];
extern const char D_800AF8B8[];
extern const char D_800AF8C8[];
extern const char D_800AF8D8[];
extern const char D_800AF8E8[];
extern const char D_800AF900[];
extern const char D_800AF918[];
extern const char D_800AF930[];
extern const char D_800AF944[];
extern const char D_800AF95C[];
extern const char D_800AF96C[];
extern const char D_800AF980[];
extern const char D_800AF98C[];
extern const char D_800AF99C[];
extern const char D_800AF9B0[];
extern const char D_800AF9C4[];
extern const char D_800AF9D4[];
extern const char D_800AF9E8[];
extern const char D_800AF9FC[];
extern const char D_800AFA14[];
extern const char D_800AFA20[];
extern const char D_800AFA30[];
extern const char D_800AFA3C[];
extern const char D_800AFA4C[];
extern const char D_800AFA5C[];
extern const char D_800AFA64[];
extern const char D_800AFA78[];
extern const char D_800AFA8C[];
extern const char D_800AFA9C[];
extern const char D_800AFAAC[];
extern const char D_800AFABC[];
extern const char D_800AFAC8[];
extern const char D_800AFAD8[];
extern const char D_800AFAE4[];
extern const char D_800AFAF4[];
extern const char D_800AFB04[];
extern const char D_800AFB14[];
extern const char D_800AFB28[];
extern const char D_800AFB3C[];
extern const char D_800AFB50[];
extern const char D_800AFB60[];
extern const char D_800AFB70[];
extern const char D_800AFB84[];
extern const char D_800AFB9C[];
extern const char D_800AFBB0[];
extern const char D_800AFBC0[];
extern const char D_800AFBD0[];
extern const char D_800AFBE0[];
extern const char D_800AFBF0[];
extern const char D_800AFC00[];
extern const char D_800AFC10[];
extern const char D_800AFC28[];
extern const char D_800AFC38[];
extern const char D_800AFC48[];
extern const char D_800AFC58[];
extern const char D_800AFC68[];
extern const char D_800AFC78[];
extern const char D_800AFC88[];
extern const char D_800AFC98[];
extern const char D_800AFCA8[];
extern const char D_800AFCB4[];
extern const char D_800AFCCC[];
extern const char D_800AFCDC[];
extern const char D_800AFCEC[];
extern const char D_800AFCFC[];
extern const char D_800AFD10[];
extern const char D_800AFD24[];
extern const char D_800AFD34[];
extern const char D_800AFD40[];
extern const char D_800AFD4C[];
extern const char D_800AFD60[];
extern const char D_800AFD70[];
extern const char D_800AFD80[];
extern const char D_800AFD90[];
extern const char D_800AFDA0[];
extern const char D_800AFDB0[];
extern const char D_800AFDC0[];
extern const char D_800AFDD4[];
extern const char D_800AFDEC[];
extern const char D_800AFDFC[];
extern const char D_800AFE10[];
extern const char D_800AFE20[];
extern const char D_800AFE30[];
extern const char D_800AFE40[];
extern const char D_800AFE54[];
extern const char D_800AFE68[];
extern const char D_800AFE78[];
extern AnimCmd* D_800EAFB0;
extern AnimCmd** D_800EB0C0;
extern UnkEC64Arg3 D_800EB430;
extern Texture** D_800EB510;
extern UNK_TYPE D_8017A710;
extern UNK_TYPE D_80186E20;
extern UNK_TYPE D_80188CB0;
extern u8 D_803A71B0[];
extern u8 D_803AD580[];
void func_800A1680();
extern u8 graveler_hd_materials[];
extern u8 grimer_hd_materials[];
extern u8 kakuna_hd_materials[];
extern u8 mew_hd_materials[];
extern u32 D_800AC120[];
extern u32 D_800AC1F8[];
extern u32 D_800AC270[];
extern u32 D_800AC2DC[];
extern u32 D_800AC318[];
extern u32 D_800AC3C0[];
extern u32 D_800AC3E4[];
extern u32 D_800AC3FC[];
extern u32 D_800AC414[];
extern u32 D_800AC444[];
extern u32 D_800AC4E0[];
extern u32 D_800AC558[];
extern u32 D_800AC5D0[];
extern u32 D_800AC630[];
extern u32 D_800AC690[];
extern u32 D_800AC69C[];
extern u32 D_800AC6E4[];
extern u32 D_800AC720[];
extern u32 D_800AC75C[];
extern u32 D_800AC7D4[];
extern u32 D_800AC834[];
extern u32 D_800AC870[];
extern u32 D_800AC8D0[];
extern u32 D_800AC930[];
extern u32 D_800AC9A8[];
extern u32 D_800AC9FC[];
extern u32 D_800ACA20[];
extern u32 D_800ACA68[];
extern u32 D_800ACAD4[];
extern u32 D_800ACB1C[];
extern u32 D_800ACB94[];
extern u32 D_800ACBE8[];
extern u32 D_800ACC30[];
extern u32 D_800ACC3C[];
extern u32 D_800ACC78[];
extern u32 D_800ACCB4[];
extern u32 D_800ACCF0[];
extern u32 D_800ACCFC[];
extern u32 D_800ACD14[];
extern u32 D_800ACD20[];
extern u32 D_800ACD50[];
extern u32 D_800ACD98;
extern Unkfunc_8009BDDCSub D_800AD7DC;
extern Unkfunc_8009BDDCSub D_800AD80C;
extern Unkfunc_8009BDDCSub D_800AD818;
extern Unkfunc_8009BDDCSub D_800AD824;
extern Unkfunc_8009BDDCSub D_800AD830;
extern Unkfunc_8009BDDCSub D_800AD848;
extern Unkfunc_8009BDDCSub D_800AD860;
extern Unkfunc_8009BDDCSub D_800AD878;
extern Unkfunc_8009BDDCSub D_800AD890;
extern Unkfunc_8009BDDCSub D_800AD8A8;
extern Unkfunc_8009BDDCSub D_800AD8CC;
extern Unkfunc_8009BDDCSub D_800AD8D8;
extern Unkfunc_8009BDDCSub D_800AD8E4;
extern Unkfunc_8009BDDCSub D_800AD8F0;
extern Unkfunc_8009BDDCSub D_800AD908;
extern Unkfunc_8009BDDCSub D_800AD998;

// .data
s32 gPhotoCount = 0;

u32 D_800AC0E4_57A94[] = {
    0x00000000, 0x00000000, 0x00000000,
};

s32 D_800AC0F0 = -1; // level id?
MovementState D_800AC0F4 = { 0.0f, 0.5f, NULL, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f, 0.0f };

u32 D_800AC120[] = {
    0x00000000, 0x80121410, 0x80129980, 0x00000000,
    0x80123320, 0x80129AE0, 0x00000000, 0x80124C20,
    0x80129C10, 0x00000000, 0x8011F9D0, 0x80129750,
    0x00000000, 0x80120850, 0x00000000, 0x00000000,
    0x80125F00, 0x80129DF0, 0x42C00000, 0x80126680,
    0x80129F00, 0x42C20000, 0x80121A50, 0x80129A10,
    0x42C40000, 0x80125130, 0x80129CC0, 0x42C60000,
    0x801283C0, 0x80129FF0, 0x00000000, 0x80120DD0,
    0x80129910, 0x00000000, 0x80121F30, 0x80129A80,
    0x00000000, 0x80124710, 0x80129BA0, 0x00000000,
    0x8011F0D0, 0x801296E0, 0x00000000, 0x801202D0,
    0x80129800, 0x00000000, 0x80125B80, 0x80129D80,
    0x00000000, 0x80127090, 0x80129F80, 0xC2C80000,
    0x80126310, 0x80129EA0,
};

u32 D_800AC1F8[] = {
    0x00000000, 0x80177600, 0x8017ADF0, 0x00000000,
    0x80178070, 0x8017B0C0, 0x00000000, 0x80175AE0,
    0x8017AB20, 0x00000000, 0x80176030, 0x8017ABF0,
    0x00000000, 0x80179210, 0x8017B400, 0x42CE0000,
    0x80179780, 0x8017B500, 0x42D00000, 0x80177BC0,
    0x8017AF90, 0x42D20000, 0x801786F0, 0x8017B280,
    0x42D40000, 0x80179ED0, 0x8017B630, 0x00000000,
    0x80176500, 0x8017AC80,
};

u32 D_800AC270[] = {
    0x00000000, 0x8017E7F0, 0x80183AD0, 0x42E60000,
    0x80180830, 0x80184010, 0x00000000, 0x8017F660,
    0x80183DE0, 0x00000000, 0x8017D930, 0x80183900,
    0x00000000, 0x8017E0F0, 0x80183A20, 0x00000000,
    0x80182130, 0x801843E0, 0x42E00000, 0x80182CB0,
    0x80184580, 0x42E20000, 0x8017F000, 0x80183CB0,
    0x42E40000, 0x801815D0, 0x801841C0,
};

u32 D_800AC2DC[] = {
    0x00000000, 0x8018A750, 0x8018B670, 0x00000000,
    0x80188E30, 0x8018B3E0, 0x00000000, 0x801893F0,
    0x8018B4A0, 0x42CA0000, 0x80189FF0, 0x8018B5A0,
    0x42CC0000, 0x801883C0, 0x8018B320,
};

u32 D_800AC318[] = {
    0x00000000, 0x801803B0, 0x801865D0, 0x00000000,
    0x80182400, 0x801867B0, 0x00000000, 0x80183180,
    0x80186830, 0x00000000, 0x8017E6C0, 0x80186440,
    0x00000000, 0x8017EB60, 0x00000000, 0x00000000,
    0x80184470, 0x80186960, 0x42940000, 0x80185B30,
    0x80186A80, 0x42960000, 0x80181510, 0x00000000,
    0x42980000, 0x80183AC0, 0x801868C0, 0x42A00000,
    0x8017EFF0, 0x801864B0, 0x00000000, 0x80185230,
    0x801869E0, 0x429A0000, 0x801818B0, 0x801866D0,
    0x429C0000, 0x801821A0, 0x00000000, 0x429E0000,
    0x8017F710, 0x80186540,
};

u32 D_800AC3C0[] = {
    0x00000000, 0x801854F0, 0x801858A0, 0x00000000,
    0x80184E00, 0x80185740, 0x00000000, 0x80185290,
    0x801857F0,
};

u32 D_800AC3E4[] = {
    0x00000000, 0x801548D0, 0x00000000, 0x00000000,
    0x80156960, 0x00000000,
};

u32 D_800AC3FC[] = {
    0x00000000, 0x8015AAE0, 0x8015AEF0, 0x00000000,
    0x8015A4C0, 0x8015AE40,
};

u32 D_800AC414[] = {
    0x00000000, 0x801A66D0, 0x00000000, 0x00000000,
    0x801A08C0, 0x801A8CC0, 0x3F800000, 0x801A2280,
    0x801A8D50, 0x00000000, 0x801A4A80, 0x801A8DF0,
};

u32 D_800AC444[] = {
    0x00000000, 0x80112F20, 0x8011A2B0, 0x00000000,
    0x80113740, 0x8011A370, 0x43060000, 0x8010E190,
    0x80119A00, 0x00000000, 0x801092F0, 0x801196C0,
    0x00000000, 0x8010D410, 0x80119960, 0x00000000,
    0x801161D0, 0x8011ADE0, 0x43070000, 0x80111AA0,
    0x8011A1B0, 0x00000000, 0x8010CE10, 0x801198B0,
    0x00000000, 0x8010C370, 0x80119800, 0x00000000,
    0x801189D0, 0x8011AF80, 0x00000000, 0x80109C10,
    0x80119760, 0x00000000, 0x80117C40, 0x8011AEE0,
    0x43110000, 0x80114610, 0x8011A440,
};

u32 D_800AC4E0[] = {
    0x00000000, 0x80164440, 0x80169A60, 0x00000000,
    0x801638E0, 0x00000000, 0x00000000, 0x80163E80,
    0x00000000, 0x00000000, 0x801672A0, 0x80169C20,
    0x426C0000, 0x80167E40, 0x80169C90, 0x42700000,
    0x80164BB0, 0x80169B00, 0x42740000, 0x80166600,
    0x80169BC0, 0x42800000, 0x801690E0, 0x00000000,
    0x42780000, 0x80168870, 0x00000000, 0x427C0000,
    0x80165100, 0x00000000,
};

u32 D_800AC558[] = {
    0x00000000, 0x8016C3F0, 0x80171560, 0x00000000,
    0x8016AF90, 0x80171420, 0x00000000, 0x8016BB80,
    0x801714D0, 0x00000000, 0x8016DF30, 0x80171710,
    0x42820000, 0x8016EBE0, 0x801717D0, 0x42840000,
    0x8016C960, 0x801715F0, 0x42860000, 0x8016D3F0,
    0x80171670, 0x428C0000, 0x8016FC50, 0x00000000,
    0x42880000, 0x8016F230, 0x00000000, 0x428A0000,
    0x8016CD10, 0x00000000,
};

u32 D_800AC5D0[] = {
    0x00000000, 0x80191B20, 0x801965B0, 0x00000000,
    0x80190AC0, 0x00000000, 0x00000000, 0x80191260,
    0x00000000, 0x00000000, 0x801935B0, 0x80196830,
    0x42E80000, 0x80193CD0, 0x801968D0, 0x42EA0000,
    0x80191F40, 0x801966D0, 0x42EC0000, 0x80192340,
    0x80196770, 0x42EE0000, 0x801950B0, 0x80196960,
};

u32 D_800AC630[] = {
    0x00000000, 0x8018AD70, 0x80192E30, 0x00000000,
    0x80190AA0, 0x80193780, 0x00000000, 0x8018DA20,
    0x80193200, 0x41C00000, 0x80189BC0, 0x80192CF0,
    0x41C80000, 0x8018EBD0, 0x801933D0, 0x41D00000,
    0x8018F850, 0x80193510, 0x00000000, 0x8018BF00,
    0x80192FF0, 0x00000000, 0x801921E0, 0x801939E0,
};

u32 D_800AC690[] = {
    0x00000000, 0x8011C2E0, 0x00000000,
};

u32 D_800AC69C[] = {
    0xC2C80000, 0x8017EFB0, 0x801819E0, 0x42A80000,
    0x80180CF0, 0x00000000, 0x42AA0000, 0x801802D0,
    0x80181C20, 0x00000000, 0x8017DCF0, 0x00000000,
    0x42AC0000, 0x8017FB40, 0x80181B60, 0x00000000,
    0x8017F490, 0x80181AA0,
};

u32 D_800AC6E4[] = {
    0x00000000, 0x80161D70, 0x80163BC0, 0x420C0000,
    0x80162570, 0x00000000, 0xC2C80000, 0x80162EB0,
    0x80163E20, 0x43200000, 0x80162960, 0x80163D40,
    0xC2C80000, 0x801622F0, 0x00000000,
};

u32 D_800AC720[] = {
    0x00000000, 0x80165250, 0x00000000, 0x42140000,
    0x80165F90, 0x00000000, 0xC2C80000, 0x80167220,
    0x00000000, 0x431E0000, 0x80166B50, 0x00000000,
    0xC2C80000, 0x80165B30, 0x00000000,
};

u32 D_800AC75C[] = {
    0x00000000, 0x801949A0, 0x8019DC60, 0x00000000,
    0x801906A0, 0x8019D890, 0x00000000, 0x80191AE0,
    0x8019D9E0, 0x00000000, 0x80192C20, 0x8019DAF0,
    0x00000000, 0x80198BF0, 0x8019E110, 0x43000000,
    0x8019C270, 0x8019E3F0, 0x43010000, 0x80195A70,
    0x8019DD80, 0x43020000, 0x80197A00, 0x8019DFF0,
    0x00000000, 0x8019A950, 0x8019E260, 0x43030000,
    0x80196070, 0x8019DE50,
};

u32 D_800AC7D4[] = {
    0x42B40000, 0x80163260, 0x00000000, 0x42B60000,
    0x80163C30, 0x00000000, 0x42B80000, 0x80164410,
    0x00000000, 0x00000000, 0x801649D0, 0x00000000,
    0x00000000, 0x80162880, 0x00000000, 0x42BA0000,
    0x80166A90, 0x00000000, 0x42BC0000, 0x801653D0,
    0x00000000, 0x42BE0000, 0x801664A0, 0x00000000,
};

u32 D_800AC834[] = {
    0x00000000, 0x80156410, 0x80159880, 0x00000000,
    0x801529B0, 0x80159660, 0x42300000, 0x80154C50,
    0x801597C0, 0x42340000, 0x80153490, 0x80159700,
    0x42380000, 0x80159220, 0x80159940,
};

u32 D_800AC870[] = {
    0x00000000, 0x80168F70, 0x80171980, 0x00000000,
    0x8016A970, 0x80171A20, 0x00000000, 0x801645E0,
    0x801717A0, 0x00000000, 0x80168280, 0x801718F0,
    0x00000000, 0x8016BCD0, 0x80171A90, 0x00000000,
    0x8016E950, 0x80171BD0, 0x40E00000, 0x80164F50,
    0x80171830, 0x00000000, 0x8016DCF0, 0x80171B30,
};

u32 D_800AC8D0[] = {
    0x00000000, 0x8019F220, 0x801A94C0, 0x00000000,
    0x801A0A00, 0x801A95C0, 0x00000000, 0x80199120,
    0x801A92C0, 0x00000000, 0x8019E850, 0x801A9420,
    0x00000000, 0x801A3460, 0x801A96C0, 0x00000000,
    0x801A7210, 0x801A9820, 0x40C00000, 0x80199FC0,
    0x801A9360, 0x00000000, 0x801A4E60, 0x801A9760,
};

u32 D_800AC930[] = {
    0x42500000, 0x8016A500, 0x00000000, 0x42540000,
    0x8016B930, 0x00000000, 0x42580000, 0x8016C340,
    0x00000000, 0x00000000, 0x8016DAC0, 0x00000000,
    0x00000000, 0x8016D250, 0x00000000, 0x00000000,
    0x801697D0, 0x00000000, 0x42680000, 0x8016FDB0,
    0x00000000, 0x425C0000, 0x8016F2A0, 0x00000000,
    0x42600000, 0x8016E3F0, 0x00000000, 0x42640000,
    0x8016E7A0, 0x00000000,
};

u32 D_800AC9A8[] = {
    0x00000000, 0x801A8C10, 0x00000000, 0x00000000,
    0x801AA220, 0x801AE8C0, 0x00000000, 0x801A8250,
    0x00000000, 0x00000000, 0x801ACBD0, 0x801AE9A0,
    0x00000000, 0x801ADA80, 0x801AEB60, 0x00000000,
    0x801A9A10, 0x801AE730, 0x00000000, 0x801AB240,
    0x00000000,
};

u32 D_800AC9FC[] = {
    0x00000000, 0x801A2EF0, 0x801A5250, 0x41200000,
    0x801A47D0, 0x801A54D0, 0x00000000, 0x801A39C0,
    0x801A5380,
};

u32 D_800ACA20[] = {
    0x00000000, 0x80141F80, 0x00000000, 0x00000000,
    0x80141060, 0x80142610, 0x00000000, 0x80141C70,
    0x80142770, 0x00000000, 0x80141660, 0x801426C0,
    0x00000000, 0x80140CE0, 0x80142560, 0x00000000,
    0x80140720, 0x00000000,
};

u32 D_800ACA68[] = {
    0x00000000, 0x80133AE0, 0x00000000, 0x42240000,
    0x801329B0, 0x00000000, 0x42280000, 0x80133800,
    0x00000000, 0x422C0000, 0x80132DF0, 0x801346F0,
    0x00000000, 0x80131990, 0x80134610, 0x00000000,
    0x8012FFD0, 0x80134570, 0x00000000, 0x80130A30,
    0x00000000, 0x00000000, 0x80131240, 0x00000000,
    0x00000000, 0x80132150, 0x00000000,
};

u32 D_800ACAD4[] = {
    0x00000000, 0x80152DA0, 0x8015A380, 0x00000000,
    0x801518F0, 0x80158F80, 0x00000000, 0x801522E0,
    0x80159D40, 0x00000000, 0x801553E0, 0x8015DD50,
    0x00000000, 0x80156930, 0x8015F2B0, 0x40A00000,
    0x80153810, 0x8015C800,
};

u32 D_800ACB1C[] = {
    0x00000000, 0x80188E10, 0x00000000, 0x00000000,
    0x80189A90, 0x00000000, 0x00000000, 0x80186880,
    0x00000000, 0x00000000, 0x801870C0, 0x00000000,
    0x00000000, 0x8018B6A0, 0x00000000, 0x42B20000,
    0x8018DF00, 0x00000000, 0x431C0000, 0x80190FF0,
    0x00000000, 0x00000000, 0x801893B0, 0x00000000,
    0x00000000, 0x801878B0, 0x80191C80, 0x431D0000,
    0x8018CB70, 0x00000000,
};

u32 D_800ACB94[] = {
    0x00000000, 0x80197030, 0x00000000, 0x00000000,
    0x801978E0, 0x00000000, 0x00000000, 0x801941C0,
    0x00000000, 0x00000000, 0x80194F10, 0x00000000,
    0x00000000, 0x801988E0, 0x8019AD90, 0x41300000,
    0x80199AC0, 0x00000000, 0x00000000, 0x80195B70,
    0x00000000,
};

u32 D_800ACBE8[] = {
    0x00000000, 0x8015EBD0, 0x00000000, 0x00000000,
    0x8015EE30, 0x00000000, 0xC2C80000, 0x8015E8C0,
    0x80160260, 0x00000000, 0x8015E6A0, 0x00000000,
    0x42040000, 0x8015F3B0, 0x00000000, 0x42080000,
    0x8015F900, 0x00000000,
};

u32 D_800ACC30[] = {
    0x00000000, 0x80181F40, 0x00000000,
};

u32 D_800ACC3C[] = {
    0x00000000, 0x80159E60, 0x00000000, 0x42F60000,
    0x8015EBA0, 0x00000000, 0x42F80000, 0x8015BC10,
    0x801617D0, 0x42FA0000, 0x8015CBC0, 0x00000000,
    0x00000000, 0x8015FD10, 0x00000000,
};

u32 D_800ACC78[] = {
    0x00000000, 0x801580F0, 0x8015B8C0, 0x00000000,
    0x801572A0, 0x8015B4F0, 0x41800000, 0x8015A380,
    0x8015C410, 0x00000000, 0x80158C90, 0x8015BC90,
    0x00000000, 0x80159940, 0x8015BFA0,
};

u32 D_800ACCB4[] = {
    0x00000000, 0x8015EC20, 0x80160EC0, 0x00000000,
    0x8015E650, 0x80160BA0, 0x41700000, 0x80160160,
    0x80161860, 0x00000000, 0x8015F820, 0x80161540,
    0x00000000, 0x8015F1D0, 0x80161220,
};

u32 D_800ACCF0[] = {
    0x00000000, 0x80182580, 0x00000000,
};

u32 D_800ACCFC[] = {
    0x00000000, 0x80171780, 0x00000000, 0x00000000,
    0x80171480, 0x00000000,
};

u32 D_800ACD14[] = {
    0x00000000, 0x80177B50, 0x00000000,
};

u32 D_800ACD20[] = {
    0x00000000, 0x8017D860, 0x00000000, 0x41E00000,
    0x8017CAB0, 0x8017E2B0, 0x00000000, 0x8017DBD0,
    0x8017E8A0, 0x41D80000, 0x8017DE00, 0x00000000,
};

u32 D_800ACD50[] = {
    0x00000000, 0x80166B20, 0x8016E240, 0x00000000,
    0x801676C0, 0x8016E570, 0x00000000, 0x8016B2D0,
    0x8016F440, 0x431B0000, 0x801680F0, 0x8016E910,
    0x00000000, 0x801657B0, 0x8016DCF0, 0x00000000,
    0x8016A380, 0x8016EF90,
};

u32 D_800ACD98 = 0xC2C80000;

Struct_800ACD9C D_800ACD9C[142] = {
    { (UNK_TYPE*) &D_80186E20, "" },
    { (void*) 0x80187230, { 0, 0, 0, 0, 194, 200, 0, 0 } },
    { (void*) 0x80188ED0, { 128, 24, 164, 192, 0, 0, 0, 0 } },
    { (void*) 0x801866A0, { 128, 24, 162, 112, 0, 0, 0, 0 } },
    { (void*) 0x80185010, "" },
    { (void*) 0x80187BD0, { 128, 24, 163, 112, 0, 0, 0, 0 } },
    { (void*) 0x80185D90, { 0, 0, 0, 0, 66, 244, 0, 0 } },
    { (void*) 0x801895E0, { 0, 0, 0, 0, 67, 33, 0, 0 } },
    { (void*) 0x80188260, { 128, 24, 164, 16, 0, 0, 0, 0 } },
    { (void*) 0x80173C30, { 128, 23, 151, 96, 0, 0, 0, 0 } },
    { (void*) 0x8016E200, { 128, 23, 149, 96, 0, 0, 0, 0 } },
    { (void*) 0x8016F5B0, { 128, 23, 150, 0, 66, 252, 0, 0 } },
    { (void*) 0x80170AD0, { 128, 23, 150, 160, 0, 0, 0, 0 } },
    { (void*) 0x801765D0, { 128, 23, 152, 176, 0, 0, 0, 0 } },
    { (void*) 0x80177520, { 128, 23, 153, 64, 66, 254, 0, 0 } },
    { (void*) 0x80175390, { 128, 23, 152, 16, 66, 142, 0, 0 } },
    { (void*) 0x80179C50, { 128, 23, 184, 0, 66, 144, 0, 0 } },
    { (void*) 0x8017A420, { 128, 23, 184, 208, 66, 146, 0, 0 } },
    { (void*) 0x8017AED0, { 128, 23, 185, 128, 0, 0, 0, 0 } },
    { (void*) 0x8013E410, "" },
    { (void*) 0x8013DD40, { 128, 19, 245, 80, 0, 0, 0, 0 } },
    { (void*) 0x8013EAE0, { 128, 19, 245, 224, 0, 0, 0, 0 } },
    { (void*) 0x80173E70, { 128, 23, 77, 208, 0, 0, 0, 0 } },
    { (void*) 0x80173810, { 128, 23, 76, 224, 0, 0, 0, 0 } },
    { (void*) 0x801744D0, { 128, 23, 78, 64, 0, 0, 0, 0 } },
    { (void*) 0x801AF4B0, "" },
    { (void*) 0x801AA9D0, { 0, 0, 0, 0, 64, 0, 0, 0 } },
    { (void*) 0x801ACF90, "" },
    { (void*) 0x801AE790, "" },
    { (void*) 0x801AC250, "" },
    { (void*) 0x801AB610, "" },
    { (void*) 0x8019E4D0, "" },
    { (void*) 0x8019D4A0, { 128, 26, 3, 192, 0, 0, 0, 0 } },
    { (void*) 0x8019B160, { 128, 26, 2, 160, 0, 0, 0, 0 } },
    { (void*) 0x8019EF80, "" },
    { (void*) 0x8019C070, { 128, 26, 3, 16, 65, 136, 0, 0 } },
    { (void*) 0x80199060, "" },
    { (void*) 0x8016FCF0, "" },
    { (void*) 0x8016EAC0, "" },
    { (void*) 0x8016F350, "" },
    { (void*) 0x801742D0, { 128, 23, 122, 32, 67, 26, 0, 0 } },
    { (void*) 0x80175690, { 0, 0, 0, 0, 66, 0, 0, 0 } },
    { (void*) 0x80172FA0, { 128, 23, 120, 144, 65, 232, 0, 0 } },
    { (void*) 0x80176800, { 128, 23, 122, 192, 65, 240, 0, 0 } },
    { (void*) 0x80170740, { 128, 23, 119, 16, 65, 248, 0, 0 } },
    { (void*) 0x80171520, { 128, 23, 119, 144, 0, 0, 0, 0 } },
    { (void*) 0x80137800, { 128, 19, 238, 32, 0, 0, 0, 0 } },
    { (void*) 0x80138FD0, { 128, 19, 241, 144, 0, 0, 0, 0 } },
    { (void*) 0x80132FD0, { 128, 19, 230, 64, 0, 0, 0, 0 } },
    { (void*) 0x80136140, { 128, 19, 236, 240, 66, 214, 0, 0 } },
    { (void*) 0x8013AB20, { 128, 19, 246, 224, 66, 216, 0, 0 } },
    { (void*) 0x8013D460, { 0, 0, 0, 0, 66, 218, 0, 0 } },
    { (void*) 0x80138890, { 0, 0, 0, 0, 66, 220, 0, 0 } },
    { (void*) 0x80139AD0, { 128, 19, 244, 128, 0, 0, 0, 0 } },
    { (void*) 0x8013C2B0, { 128, 19, 250, 48, 66, 222, 0, 0 } },
    { (void*) 0x80133BF0, { 128, 19, 231, 112, 66, 76, 0, 0 } },
    { (void*) 0x800FDC70, { 0, 0, 0, 0, 66, 64, 0, 0 } },
    { (void*) 0x800FAE40, { 0, 0, 0, 0, 66, 68, 0, 0 } },
    { (void*) 0x800FBF50, { 0, 0, 0, 0, 66, 72, 0, 0 } },
    { (void*) 0x800FD080, { 0, 0, 0, 0, 65, 160, 0, 0 } },
    { (void*) 0x8013BEC0, { 0, 0, 0, 0, 65, 168, 0, 0 } },
    { (void*) 0x80139880, { 128, 19, 198, 176, 65, 176, 0, 0 } },
    { (void*) 0x8013A370, { 128, 19, 199, 160, 65, 152, 0, 0 } },
    { (void*) 0x80137D60, { 0, 0, 0, 0, 65, 184, 0, 0 } },
    { (void*) 0x8013B150, { 128, 19, 200, 48, 64, 128, 0, 0 } },
    { (void*) 0x80183D20, { 128, 24, 68, 0, 0, 0, 0, 0 } },
    { (void*) 0x8017EE10, "" },
    { (void*) 0x8017D950, "" },
    { (void*) 0x8017E460, "" },
    { (void*) 0x80183C40, "" },
    { (void*) 0x80184C20, "" },
    { (void*) 0x80182410, "" },
    { (void*) 0x80182D00, { 0, 0, 0, 0, 65, 96, 0, 0 } },
    { (void*) 0x80186450, "" },
    { (void*) 0x80181570, "" },
    { (void*) 0x80166A90, { 128, 22, 179, 0, 0, 0, 0, 0 } },
    { (void*) 0x80165010, { 128, 22, 177, 144, 0, 0, 0, 0 } },
    { (void*) 0x80165D90, { 128, 22, 178, 80, 0, 0, 0, 0 } },
    { (void*) 0x80167D20, { 128, 22, 180, 32, 64, 64, 0, 0 } },
    { (void*) 0x80168D50, { 128, 22, 180, 240, 0, 0, 0, 0 } },
    { (void*) 0x80174FC0, { 128, 23, 173, 160, 0, 0, 0, 0 } },
    { (void*) 0x80173140, { 128, 23, 163, 48, 0, 0, 0, 0 } },
    { (void*) 0x80173B00, { 128, 23, 167, 16, 0, 0, 0, 0 } },
    { (void*) 0x80176740, { 128, 23, 177, 16, 0, 0, 0, 0 } },
    { (void*) 0x801746F0, { 128, 23, 170, 160, 66, 166, 0, 0 } },
    { (void*) 0x801799E0, { 128, 23, 189, 112, 0, 0, 0, 0 } },
    { (void*) 0x801779A0, { 128, 23, 181, 128, 194, 200, 0, 0 } },
    { (void*) 0x80174B00, { 128, 23, 171, 192, 0, 0, 0, 0 } },
    { (void*) 0x80172D00, { 128, 23, 160, 176, 0, 0, 0, 0 } },
    { (void*) 0x80173360, { 128, 23, 164, 112, 0, 0, 0, 0 } },
    { (void*) 0x80175220, { 128, 23, 174, 144, 0, 0, 0, 0 } },
    { (void*) 0x80173ED0, { 128, 23, 168, 96, 66, 162, 0, 0 } },
    { (void*) 0x80178C40, { 128, 23, 186, 240, 0, 0, 0, 0 } },
    { (void*) 0x80178400, { 128, 23, 184, 176, 0, 0, 0, 0 } },
    { (void*) 0x801771D0, { 128, 23, 178, 80, 194, 200, 0, 0 } },
    { (void*) 0x80174D60, { 128, 23, 172, 176, 0, 0, 0, 0 } },
    { (void*) 0x80172F20, { 128, 23, 161, 240, 0, 0, 0, 0 } },
    { (void*) 0x80173730, { 128, 23, 165, 192, 0, 0, 0, 0 } },
    { (void*) 0x80175CB0, { 128, 23, 175, 208, 0, 0, 0, 0 } },
    { (void*) 0x801742E0, { 128, 23, 169, 128, 66, 164, 0, 0 } },
    { (void*) 0x80179310, { 128, 23, 188, 48, 0, 0, 0, 0 } },
    { (void*) 0x80178820, { 128, 23, 185, 208, 194, 200, 0, 0 } },
    { (void*) 0x8017EBA0, { 128, 24, 34, 48, 194, 200, 0, 0 } },
    { (void*) 0x8017E740, { 128, 24, 33, 192, 194, 200, 0, 0 } },
    { (void*) 0x8017F8B0, { 128, 24, 35, 16, 67, 34, 0, 0 } },
    { (void*) 0x8017FEF0, { 0, 0, 0, 0, 67, 4, 0, 0 } },
    { (void*) 0x8017F080, "" },
    { (void*) 0x80181880, "" },
    { (void*) 0x80180910, { 128, 24, 35, 192, 67, 5, 0, 0 } },
    { (void*) 0x8017BB20, { 0, 0, 0, 0, 67, 35, 0, 0 } },
    { (void*) 0x8017DA60, { 128, 24, 32, 176, 194, 200, 0, 0 } },
    { (void*) 0x8017E2E0, { 128, 24, 33, 80, 65, 144, 0, 0 } },
    { (void*) 0x801746E0, { 128, 23, 137, 32, 0, 0, 0, 0 } },
    { (void*) 0x80172370, { 128, 23, 136, 0, 0, 0, 0, 0 } },
    { (void*) 0x80172E00, { 128, 23, 136, 144, 0, 0, 0, 0 } },
    { (void*) 0x80185E70, { 128, 24, 111, 48, 0, 0, 0, 0 } },
    { (void*) 0x80184920, { 128, 24, 110, 160, 65, 80, 0, 0 } },
    { (void*) 0x80186530, { 128, 24, 111, 160, 0, 0, 0, 0 } },
    { (void*) 0x80183EE0, { 128, 24, 110, 32, 0, 0, 0, 0 } },
    { (void*) 0x80143E20, { 128, 20, 195, 0, 0, 0, 0, 0 } },
    { (void*) 0x801429B0, { 128, 20, 119, 112, 66, 200, 0, 0 } },
    { (void*) 0x80143110, { 128, 20, 145, 176, 0, 0, 0, 0 } },
    { (void*) 0x80141CF0, { 128, 20, 68, 112, 0, 0, 0, 0 } },
    { (void*) 0x80142370, { 128, 20, 93, 48, 66, 24, 0, 0 } },
    { (void*) 0x8015CED0, { 128, 21, 231, 32, 66, 28, 0, 0 } },
    { (void*) 0x8015DA00, { 0, 0, 0, 0, 66, 32, 0, 0 } },
    { (void*) 0x8015DCE0, "" },
    { (void*) 0x8014B280, "" },
    { (void*) 0x8014ABC0, { 0, 0, 0, 0, 65, 64, 0, 0 } },
    { (void*) 0x801470F0, "" },
    { (void*) 0x801462C0, "" },
    { (void*) 0x801453E0, { 0, 0, 0, 0, 194, 200, 0, 0 } },
    { (void*) 0x8012EFF0, { 128, 19, 150, 144, 194, 200, 0, 0 } },
    { (void*) 0x801368F0, { 128, 19, 155, 0, 194, 200, 0, 0 } },
    { (void*) 0x801358A0, { 128, 19, 154, 0, 194, 200, 0, 0 } },
    { (void*) 0x80133040, { 128, 19, 153, 0, 67, 21, 0, 0 } },
    { (void*) 0x8012C9E0, { 128, 19, 148, 208, 67, 22, 0, 0 } },
    { (void*) 0x8012D700, { 128, 19, 149, 160, 67, 23, 0, 0 } },
    { (void*) 0x80131D30, { 128, 19, 152, 64, 67, 24, 0, 0 } },
    { (void*) 0x8012FB60, { 128, 19, 151, 112, 194, 200, 0, 0 } },
    { (void*) 0x8014E550, { 0, 0, 0, 0, 194, 200, 0, 0 } },
    { (void*) 0x8014E650, { 0, 0, 0, 0, 194, 200, 0, 0 } },
};

Struct_800ACD9C D_800AD444[4] = {
    { (void*) 0x8017A200, { 0, 0, 0, 0, 194, 200, 0, 0 } },
    { (void*) 0x8017A350, { 0, 0, 0, 0, 194, 200, 0, 0 } },
    { (UNK_TYPE*) &D_8017A710, { 0, 0, 0, 0, 194, 200, 0, 0 } },
    { (void*) 0x8017A510, { 0, 0, 0, 0, 194, 200, 0, 0 } },
};

Struct_800ACD9C D_800AD474[6] = {
    { (void*) 0x80188820, { 0, 0, 0, 0, 194, 200, 0, 0 } },
    { (void*) 0x80188940, { 0, 0, 0, 0, 194, 200, 0, 0 } },
    { (UNK_TYPE*) &D_80188CB0, { 0, 0, 0, 0, 194, 200, 0, 0 } },
    { (void*) 0x80188AF0, { 0, 0, 0, 0, 66, 174, 0, 0 } },
    { (void*) 0x80183C10, { 0, 0, 0, 0, 66, 176, 0, 0 } },
    { (void*) 0x801836C0, { 0, 0, 0, 0, 0, 0, 0, 88 } },
};

u32 D_800AD4BC[] = {
    (u32) &D_800ACC78, 0x00000005,
};

u32 D_800AD4C4 = 0x00000059;

u32 D_800AD4C8[] = {
    (u32) &D_800ACCB4, 0x00000005,
};

u32 D_800AD4D0 = 0x0000007E;

u32 D_800AD4D4[] = {
    (u32) &D_800ACFC0, 0x0000000A,
};

u32 D_800AD4DC[] = {
    0x0000000C, (u32) &D_800AC3E4, 0x00000002, 0x0000000E,
    (u32) &D_800AC3FC, 0x00000002, 0x00000051, (u32) &D_800ACBE8,
    0x00000006, 0x00000032, (u32) &D_800AC6E4, 0x00000005,
    0x00000054, (u32) &D_800ACC3C, 0x00000005, 0x0000006D,
    (u32) &D_800ACD50, 0x00000006, 0x00000033, (u32) &D_800AC720,
    0x00000005, 0x00000085, (u32) &D_800AD11C, 0x00000005,
    0x0000007D, (u32) &D_800ACF54, 0x00000009, 0x00000092,
    (u32) &D_800AD32C, 0x00000005, 0x00000258, (u32) &D_800AD428,
    0x00000002, 0x00000090, (u32) &D_800AD2D8, 0x00000003,
    0x00000259, (u32) &D_800AD440, 0x00000004, 0x00000001,
    (u32) &D_800AC120, 0x00000012, 0x0000004E, (u32) &D_800ACAD4,
    0x00000006, 0x0000003A, (u32) &D_800AC870, 0x00000008,
    0x00000073, (u32) &D_800ACE04, 0x00000007, 0x0000005D,
    (u32) &D_800ACD14, 0x00000001, 0x0000004B, (u32) &D_800ACA68,
    0x00000009, 0x00000082, (u32) &D_800AD068, 0x00000005,
    0x00000078, (u32) &D_800ACE7C, 0x00000003, 0x00000004,
    (u32) &D_800AC1F8, 0x0000000A, 0x0000004A, (u32) &D_800ACA20,
    0x00000006, 0x0000008F, (u32) &D_800AD260, 0x0000000A,
    0x00000095, (u32) &D_800AD38C, 0x00000005, 0x00000036,
    (u32) &D_800AC7D4, 0x00000008, 0x00000081, (u32) &D_800AD038,
    0x00000004, 0x00000083, (u32) &D_800AD0A4, 0x00000001,
    0x00000005, (u32) &D_800AC270, 0x00000009, 0x00000006,
    (u32) &D_800AC2DC, 0x00000005, 0x00000071, (u32) &D_800ACD98,
    0x00000009, 0x00000038, (u32) &D_800AC834, 0x00000005,
    0x00000065, (u32) &D_800ACD20, 0x00000004, 0x00000084,
    (u32) &D_800AD0B0, 0x00000009, 0x00000097, (u32) &D_800AD3C8,
    0x00000008, 0x00000093, (u32) &D_800AD368, 0x00000003,
    0x00000034, (u32) &D_800AC75C, 0x0000000A, 0x0000003C,
    (u32) &D_800AC930, 0x0000000A, 0x0000005B, (u32) &D_800ACCFC,
    0x00000002, 0x00000019, (u32) &D_800AC444, 0x0000000D,
    0x00000010, (u32) &D_800AC414, 0x00000004, 0x00000089,
    (u32) &D_800AD158, 0x00000016, 0x00000027, (u32) &D_800AC630,
    0x00000008, 0x00000052, (u32) &D_800ACC30, 0x00000001,
    0x00000025, (u32) &D_800AC5D0, 0x00000008, 0x0000007C,
    (u32) &D_800ACF0C, 0x00000006, 0x0000002D, (u32) &D_800AC69C,
    0x00000006, 0x0000001B, (u32) &D_800AC4E0, 0x0000000A,
    0x0000001C, (u32) &D_800AC558, 0x0000000A, 0x0000005A,
    (u32) &D_800ACCF0, 0x00000001, 0x0000025B, (u32) &D_800AD4A0,
    0x00000002, 0x00000079, (u32) &D_800ACEA0, 0x00000003,
    0x0000007B, (u32) &D_800ACEC4, 0x00000006, 0x00000091,
    (u32) &D_800AD2FC, 0x00000004, 0x0000025A, (u32) &D_800AD470,
    0x00000004, 0x00000076, (u32) &D_800ACE58, 0x00000003,
    0x0000000B, (u32) &D_800AC3C0, 0x00000003, 0x00000047,
    (u32) &D_800AC9FC, 0x00000003, 0x00000046, (u32) &D_800AC9A8,
    0x00000007, 0x0000003B, (u32) &D_800AC8D0, 0x00000008,
    0x0000004F, (u32) &D_800ACB1C, 0x0000000A, 0x00000050,
    (u32) &D_800ACB94, 0x00000007, 0x00000007, (u32) &D_800AC318,
    0x0000000E, 0x00000029, (u32) &D_800AC690, 0x00000001,
};

Unkfunc_8009BDDCSub D_800AD7DC = { 0.0f, (void*) 0x800F1DF0, (void*) 0x800F1E40 };

u32 D_800AD7E8_59198[] = {
    0x00000000, 0x800F1ED0, 0x800F1F20, 0x00000000,
    0x800F1FD0, 0x800F2020, 0x00000000, 0x800F20D0,
    0x800F2110,
};

Unkfunc_8009BDDCSub D_800AD80C = { 0.0f, (void*) 0x800F55F0, (void*) 0x800F58C0 };
Unkfunc_8009BDDCSub D_800AD818 = { 0.0f, (AnimCmd**) &D_800EAFB0, (AnimCmd***) &D_800EB0C0 };
Unkfunc_8009BDDCSub D_800AD824 = { 0.0f, (void*) 0x80139CD0, (void*) 0x8013ACA0 };
Unkfunc_8009BDDCSub D_800AD830 = { 0.0f, (void*) 0x80138ED0, NULL };

u32 D_800AD83C_591EC[] = {
    0x00000000, 0x80138F20, 0x00000000,
};

Unkfunc_8009BDDCSub D_800AD848 = { 0.0f, (void*) 0x80138810, (void*) 0x80138870 };

u32 D_800AD854_59204[] = {
    0x00000000, 0x80138930, 0x80138990,
};

Unkfunc_8009BDDCSub D_800AD860 = { 0.0f, (void*) 0x80133740, (void*) 0x801338B0 };

u32 D_800AD86C_5921C[] = {
    0x00000000, 0x80134090, 0x80134150,
};

Unkfunc_8009BDDCSub D_800AD878 = { 0.0f, (void*) 0x801394A0, (void*) 0x801394B0 };

u32 D_800AD884_59234[] = {
    0x00000000, 0x80139500, 0x80139510,
};

Unkfunc_8009BDDCSub D_800AD890 = { 0.0f, (void*) 0x80139A90, (void*) 0x80139AA0 };

u32 D_800AD89C_5924C[] = {
    0x00000000, 0x80139AF0, 0x80139B00,
};

Unkfunc_8009BDDCSub D_800AD8A8 = { 0.0f, (void*) 0x80114210, (void*) 0x80114240 };

u32 D_800AD8B4_59264[] = {
    0x00000000, 0x80114280, 0x801142C0, 0x00000000,
    0x80114300, 0x80114330,
};

Unkfunc_8009BDDCSub D_800AD8CC = { 0.0f, (void*) 0x80113D00, (void*) 0x80113D30 };
Unkfunc_8009BDDCSub D_800AD8D8 = { 0.0f, (void*) 0x80114840, (void*) 0x80114980 };
Unkfunc_8009BDDCSub D_800AD8E4 = { 0.0f, (void*) 0x80115610, (void*) 0x80115C50 };
Unkfunc_8009BDDCSub D_800AD8F0 = { 0.0f, (void*) 0x801197F0, (void*) 0x80119830 };

u32 D_800AD8FC_592AC[] = {
    0x00000000, 0x801198F0, 0x80119940,
};

Unkfunc_8009BDDCSub D_800AD908 = { 0.0f, (void*) 0x80117210, (void*) 0x80117260 };

u32 D_800AD914_592C4[] = {
    0x00000000, 0x80117310, 0x80117360, 0x00000000,
    0x80117410, 0x80117480, 0x00000000, 0x80117570,
    0x801175E0, 0x00000000, 0x801176D0, 0x80117730,
    0x00000000, 0x80117840, 0x801178A0, 0x00000000,
    0x80117980, 0x801179C0, 0x00000000, 0x80117A50,
    0x80117A90, 0x00000000, 0x80117B20, 0x80117B60,
    0x00000000, 0x80117C70, 0x80117CB0, 0x00000000,
    0x80117DC0, 0x80117DF0, 0x00000000, 0x80117F10,
    0x80117F40,
};

Unkfunc_8009BDDCSub D_800AD998 = { 0.0f, (void*) 0x80118360, (void*) 0x80118390 };

Unkfunc_8009BDDC D_800AD9A4[16] = {
    { 0x3E9, (Unkfunc_8009BDDCSub*) &D_800AD7DC, 4 },
    { 0x3EA, (Unkfunc_8009BDDCSub*) &D_800AD80C, 1 },
    { 0x3EB, (Unkfunc_8009BDDCSub*) &D_800AD818, 1 },
    { 0x3EE, (Unkfunc_8009BDDCSub*) &D_800AD824, 1 },
    { 0x3F1, (Unkfunc_8009BDDCSub*) &D_800AD830, 2 },
    { 0x3F2, (Unkfunc_8009BDDCSub*) &D_800AD848, 2 },
    { 0x3F0, (Unkfunc_8009BDDCSub*) &D_800AD860, 2 },
    { 0x3F4, (Unkfunc_8009BDDCSub*) &D_800AD878, 2 },
    { 0x3F5, (Unkfunc_8009BDDCSub*) &D_800AD890, 2 },
    { 0x404, (Unkfunc_8009BDDCSub*) &D_800AD8A8, 3 },
    { 0x405, (Unkfunc_8009BDDCSub*) &D_800AD8CC, 1 },
    { 0x406, (Unkfunc_8009BDDCSub*) &D_800AD8D8, 1 },
    { 0x407, (Unkfunc_8009BDDCSub*) &D_800AD8E4, 1 },
    { 0x409, (Unkfunc_8009BDDCSub*) &D_800AD8F0, 2 },
    { 0x40D, (Unkfunc_8009BDDCSub*) &D_800AD908, 12 },
    { 0x40E, (Unkfunc_8009BDDCSub*) &D_800AD998, 1 },
};

Unk1C D_800ADA64[14] = {
    { 0x3EC, 10.0f, (void*) 0x80136AC0, NULL, (void (*)(GObj*)) renderModelTypeDFogged, NULL, NULL },
    { 0x3F6, 10.0f, (void*) 0x8013AA00, NULL, (void (*)(GObj*)) renderModelTypeBFogged, NULL, NULL },
    { 0x3FA, 10.0f, (void*) 0x801450C0, NULL, (void (*)(GObj*)) renderModelTypeDFogged, (void*) 0x801456D0, NULL },
    { 0x3FB, 10.0f, (void*) 0x801473B0, NULL, (void (*)(GObj*)) renderModelTypeBFogged, NULL, NULL },
    { 0x3FD, 2.0f, (void*) 0x80143D60, (void*) 0x80143CC0, (void (*)(GObj*)) renderModelTypeBFogged, NULL, NULL },
    { 0x3FE, 10.0f, (void*) 0x80145B08, NULL, (void (*)(GObj*)) renderModelTypeDFogged, NULL, NULL },
    { 0x3FF, 10.0f, (void*) 0x80145D60, (void*) 0x80145CC0, (void (*)(GObj*)) renderModelTypeBFogged, (void*) 0x80145EB0, (void*) 0x80145ED0 },
    { 0x400, 10.0f, (void*) 0x801460B0, (void*) 0x80146010, (void (*)(GObj*)) renderModelTypeBFogged, (void*) 0x80146200, (void*) 0x80146220 },
    { 0x401, 10.0f, (void*) 0x80146400, (void*) 0x80146360, (void (*)(GObj*)) renderModelTypeBFogged, (void*) 0x80146550, (void*) 0x80146570 },
    { 0x402, 10.0f, (void*) 0x80113830, (void*) 0x801138C0, (void (*)(GObj*)) renderModelTypeBFogged, (void*) 0x80113960, (void*) 0x80113990 },
    { 0x408, 10.0f, (void*) 0x8011AC50, NULL, (void (*)(GObj*)) renderModelTypeBFogged, NULL, NULL },
    { 0x40A, 2.0f, (void*) 0x80118820, (void*) 0x80118780, (void (*)(GObj*)) renderModelTypeBFogged, NULL, NULL },
    { 0x40B, 10.0f, (void*) 0x80119BB0, NULL, (void (*)(GObj*)) renderModelTypeBFogged, NULL, NULL },
    { 0, 0.0f, NULL, NULL, NULL, NULL, NULL },
};

UnkV0 D_800ADBEC[84] = {
    { 88, 2.0f, (void*) 0x801B2DE8, (Texture***) &grimer_hd_materials, (void (*)(GObj*)) renderModelTypeIFogged },
    { 89, 1.5f, (void*) 0x801B7300, (void*) 0x801B3160, (void (*)(GObj*)) renderModelTypeIFogged },
    { 126, 1.3f, (void*) 0x801ADFE0, (void*) 0x801A99B0, (void (*)(GObj*)) renderModelTypeJFogged },
    { 12, 1.6f, (void*) 0x801B3048, NULL, (void (*)(GObj*)) renderModelTypeBFogged },
    { 14, 2.2f, (void*) 0x8018E0C0, (Texture***) &kakuna_hd_materials, (void (*)(GObj*)) renderModelTypeBFogged },
    { 81, 2.2f, (void*) 0x80190B28, (void*) 0x8018E408, (void (*)(GObj*)) renderModelTypeDFogged },
    { 50, 2.4f, (void*) 0x80193728, (void*) 0x80190D70, (void (*)(GObj*)) renderModelTypeBFogged },
    { 84, 2.0f, (void*) 0x801B6820, (void*) 0x801B3290, (void (*)(GObj*)) renderModelTypeBFogged },
    { 109, 2.5f, (void*) 0x801BB318, (void*) 0x801B7620, (void (*)(GObj*)) renderModelTypeJFogged },
    { 51, 1.7f, (void*) 0x80196B38, NULL, (void (*)(GObj*)) renderModelTypeBFogged },
    { 133, 2.4f, (void*) 0x801BA388, (void*) 0x801B6B40, (void (*)(GObj*)) renderModelTypeBFogged },
    { 125, 1.7f, (void*) 0x8019B308, (void*) 0x80196E00, (void (*)(GObj*)) renderModelTypeJFogged },
    { 146, 1.5f, (void*) 0x801B2720, (void*) 0x801AE380, (void (*)(GObj*)) func_800A1680 },
    { 600, 1.7f, (void*) 0x8014F080, NULL, (void (*)(GObj*)) renderModelTypeBFogged },
    { 144, 1.6f, (void*) 0x801BFA00, (void*) 0x801BB610, (void (*)(GObj*)) renderModelTypeIFogged },
    { 601, 2.2f, (void*) 0x8017BFA8, NULL, (void (*)(GObj*)) renderModelTypeDFogged },
    { 1, 2.0f, (void*) 0x803AA438, (Texture***) &D_803A71B0, (void (*)(GObj*)) renderModelTypeJFogged },
    { 78, 1.2f, (void*) 0x801B66E0, (void*) 0x801B2AF0, (void (*)(GObj*)) func_800A1680 },
    { 58, 2.2f, (void*) 0x801BA960, (void*) 0x801B6AE0, (void (*)(GObj*)) renderModelTypeIFogged },
    { 115, 1.5f, (void*) 0x801BF0E8, (void*) 0x801BA620, (void (*)(GObj*)) renderModelTypeIFogged },
    { 93, 1.0f, (void*) 0x801A5CC0, NULL, (void (*)(GObj*)) renderModelTypeIFogged },
    { 75, 2.2f, (void*) 0x8018B528, (Texture***) &graveler_hd_materials, (void (*)(GObj*)) renderModelTypeIFogged },
    { 130, 2.0f, (void*) 0x8018ECF8, (void*) 0x8018B840, (void (*)(GObj*)) renderModelTypeBFogged },
    { 120, 2.0f, (void*) 0x80192480, (void*) 0x8018F040, (void (*)(GObj*)) renderModelTypeIFogged },
    { 4, 2.0f, (void*) 0x801BE8C0, (void*) 0x801BAF00, (void (*)(GObj*)) renderModelTypeJFogged },
    { 74, 2.0f, (void*) 0x80196E68, (void*) 0x80192720, (void (*)(GObj*)) renderModelTypeIFogged },
    { 143, 1.5f, (void*) 0x801C26B0, (void*) 0x801BF430, (void (*)(GObj*)) renderModelTypeJFogged },
    { 149, 2.2f, (void*) 0x8019AC90, NULL, (void (*)(GObj*)) renderModelTypeIFogged },
    { 54, 1.4f, (void*) 0x8019DEB0, NULL, (void (*)(GObj*)) renderModelTypeIFogged },
    { 129, 1.6f, (void*) 0x803B4CB0, NULL, (void (*)(GObj*)) renderModelTypeBFogged },
    { 131, 3.0f, (void*) 0x801C6118, (void*) 0x801C2BA0, (void (*)(GObj*)) renderModelTypeIFogged },
    { 5, 1.8f, (void*) 0x801C26B8, (void*) 0x801BEB80, (void (*)(GObj*)) renderModelTypeJFogged },
    { 6, 3.5f, (void*) 0x801C5B70, (void*) 0x801C2A00, (void (*)(GObj*)) renderModelTypeIFogged },
    { 113, 2.0f, (void*) 0x801C8710, (void*) 0x801C6330, (void (*)(GObj*)) renderModelTypeIFogged },
    { 56, 2.0f, (void*) 0x8019F2D0, (void*) 0x8019B0E0, (void (*)(GObj*)) renderModelTypeIFogged },
    { 101, 1.4f, (void*) 0x801A8388, (void*) 0x801A61F0, (void (*)(GObj*)) renderModelTypeDFogged },
    { 132, 2.6f, (void*) 0x801C2948, NULL, (void (*)(GObj*)) renderModelTypeIFogged },
    { 151, 2.0f, (void*) 0x8013DC80, (Texture***) &mew_hd_materials, (void (*)(GObj*)) renderModelTypeIFogged },
    { 147, 1.5f, (void*) 0x801A1FF0, (void*) 0x8019F5F0, (void (*)(GObj*)) renderModelTypeIFogged },
    { 52, 2.4f, (void*) 0x801CD8A0, (void*) 0x801C8C50, (void (*)(GObj*)) renderModelTypeBFogged },
    { 60, 1.6f, (void*) 0x8019FA48, NULL, (void (*)(GObj*)) renderModelTypeDFogged },
    { 91, 1.3f, (void*) 0x801A2458, NULL, (void (*)(GObj*)) renderModelTypeBFogged },
    { 25, 2.0f, (void*) 0x803B1B80, (Texture***) &D_803AD580, (void (*)(GObj*)) renderModelTypeJFogged },
    { 16, 2.0f, (void*) 0x801D2180, (void*) 0x801CDC40, (void (*)(GObj*)) renderModelTypeIFogged },
    { 137, 1.5f, (void*) 0x801A4628, (void*) 0x801A25F0, (void (*)(GObj*)) renderModelTypeIFogged },
    { 39, 2.2f, (void*) 0x801C48D8, (void*) 0x801C2C40, (void (*)(GObj*)) renderModelTypeIFogged },
    { 82, 2.2f, (void*) 0x801AC2F0, NULL, (void (*)(GObj*)) renderModelTypeBFogged },
    { 37, 1.7f, (void*) 0x801CA850, (void*) 0x801C60C0, (void (*)(GObj*)) renderModelTypeIFogged },
    { 124, 1.4f, (void*) 0x801C7E58, (void*) 0x801C4BA0, (void (*)(GObj*)) renderModelTypeIFogged },
    { 45, 1.5f, (void*) 0x801A86D8, (void*) 0x801A4810, (void (*)(GObj*)) renderModelTypeDFogged },
    { 27, 2.0f, (void*) 0x801A55D8, (void*) 0x801A2290, (void (*)(GObj*)) renderModelTypeIFogged },
    { 28, 2.0f, (void*) 0x801A8FB0, (void*) 0x801A5840, (void (*)(GObj*)) renderModelTypeIFogged },
    { 90, 2.2f, (void*) 0x801AB078, NULL, (void (*)(GObj*)) renderModelTypeBFogged },
    { 603, 2.0f, (void*) 0x801AC880, (void*) 0x801AB210, (void (*)(GObj*)) renderModelTypeBFogged },
    { 121, 2.2f, (void*) 0x801AC330, (void*) 0x801A92A0, (void (*)(GObj*)) renderModelTypeIFogged },
    { 123, 0.9f, (void*) 0x801D6528, NULL, (void (*)(GObj*)) renderModelTypeDFogged },
    { 145, 1.5f, (void*) 0x801AFA10, (void*) 0x801AC7C0, (void (*)(GObj*)) renderModelTypeIFogged },
    { 602, 2.0f, (void*) 0x8018A640, NULL, (void (*)(GObj*)) renderModelTypeDFogged },
    { 118, 2.0f, (void*) 0x801AEBD8, (void*) 0x801AC6D0, (void (*)(GObj*)) renderModelTypeIFogged },
    { 11, 1.8f, (void*) 0x801AEB08, (void*) 0x801ACA10, (void (*)(GObj*)) renderModelTypeBFogged },
    { 71, 2.0f, (void*) 0x801CE0B8, (void*) 0x801CACD0, (void (*)(GObj*)) renderModelTypeDFogged },
    { 70, 2.0f, (void*) 0x801CA9B8, (void*) 0x801C81D0, (void (*)(GObj*)) renderModelTypeIFogged },
    { 59, 1.4f, (void*) 0x801CF370, (void*) 0x801CABA0, (void (*)(GObj*)) renderModelTypeIFogged },
    { 79, 1.6f, (void*) 0x801B1AC0, NULL, (void (*)(GObj*)) renderModelTypeIFogged },
    { 80, 1.3f, (void*) 0x801B6810, (void*) 0x801B1E60, (void (*)(GObj*)) renderModelTypeIFogged },
    { 7, 2.2f, (void*) 0x801B1B50, (void*) 0x801AEE70, (void (*)(GObj*)) renderModelTypeBFogged },
    { 41, 2.2f, (void*) 0x803AD338, NULL, (void (*)(GObj*)) renderModelTypeIFogged },
    { 0x3E9, 10.0f, (void*) 0x800F1D10, (void*) 0x800F07A0, (void (*)(GObj*)) renderModelTypeDFogged },
    { 0x3EA, 20.0f, (void*) 0x800F5490, (void*) 0x800F41D0, (void (*)(GObj*)) renderModelTypeDFogged },
    { 0x3EB, 2.0f, (UnkEC64Arg3*) &D_800EB430, (Texture***) &D_800EB510, (void (*)(GObj*)) renderModelTypeDFogged },
    { 0x3EE, 3.0f, (void*) 0x80139A40, (void*) 0x801397C0, (void (*)(GObj*)) renderModelTypeDFogged },
    { 0x3F1, 10.0f, (void*) 0x80138DF0, NULL, (void (*)(GObj*)) renderModelTypeBFogged },
    { 0x3F2, 10.0f, (void*) 0x801382E0, (void*) 0x80138630, (void (*)(GObj*)) renderModelTypeDFogged },
    { 0x3F0, 10.0f, (void*) 0x80132F30, (void*) 0x80133250, (void (*)(GObj*)) renderModelTypeBFogged },
    { 0x3F4, 10.0f, (void*) 0x80139378, (void*) 0x80139400, (void (*)(GObj*)) renderModelTypeDFogged },
    { 0x3F5, 10.0f, (void*) 0x80139968, (void*) 0x801399F0, (void (*)(GObj*)) renderModelTypeDFogged },
    { 0x404, 30.0f, (void*) 0x801140C0, (void*) 0x80114150, (void (*)(GObj*)) renderModelTypeDFogged },
    { 0x405, 30.0f, (void*) 0x80113BA0, (void*) 0x80113C50, (void (*)(GObj*)) renderModelTypeDFogged },
    { 0x406, 10.0f, (void*) 0x80114660, (void*) 0x80114710, (void (*)(GObj*)) renderModelTypeDFogged },
    { 0x407, 10.0f, (void*) 0x80114EA0, (void*) 0x801151C0, (void (*)(GObj*)) renderModelTypeDFogged },
    { 0x409, 10.0f, (void*) 0x80119330, (void*) 0x80119210, (void (*)(GObj*)) renderModelTypeBFogged },
    { 0x40D, 2.0f, (void*) 0x80116EF0, (void*) 0x80116CF0, (void (*)(GObj*)) renderModelTypeDFogged },
    { 0x40E, 2.0f, (void*) 0x80118210, (void*) 0x80118160, (void (*)(GObj*)) renderModelTypeDFogged },
    { 0, 0.0f, NULL, NULL, NULL },
};

s32 D_800AE27C = 0;
s32 D_800AE280 = 0;

char* D_800AE284[90] = {
    (char*) &D_800AF420,
    (char*) &D_800AF424,
    (char*) &D_800AF438,
    (char*) &D_800AF448,
    (char*) &D_800AF45C,
    (char*) &D_800AF474,
    (char*) &D_800AF48C,
    (char*) &D_800AF4A0,
    (char*) &D_800AF4B4,
    (char*) &D_800AF4C8,
    (char*) &D_800AF4DC,
    (char*) &D_800AF4F0,
    (char*) &D_800AF500,
    (char*) &D_800AF518,
    (char*) &D_800AF528,
    (char*) &D_800AF538,
    (char*) &D_800AF54C,
    (char*) &D_800AF55C,
    (char*) &D_800AF570,
    (char*) &D_800AF580,
    (char*) &D_800AF590,
    (char*) &D_800AF5A4,
    (char*) &D_800AF5B4,
    (char*) &D_800AF5C4,
    (char*) &D_800AF5D0,
    (char*) &D_800AF5DC,
    (char*) &D_800AF5EC,
    (char*) &D_800AF5FC,
    (char*) &D_800AF610,
    (char*) &D_800AF624,
    (char*) &D_800AF634,
    (char*) &D_800AF648,
    (char*) &D_800AF65C,
    (char*) &D_800AF670,
    (char*) &D_800AF684,
    (char*) &D_800AF698,
    (char*) &D_800AF6AC,
    (char*) &D_800AF6C0,
    (char*) &D_800AF6D0,
    (char*) &D_800AF6E4,
    (char*) &D_800AF6FC,
    (char*) &D_800AF714,
    (char*) &D_800AF720,
    (char*) &D_800AF730,
    (char*) &D_800AF740,
    (char*) &D_800AF74C,
    (char*) &D_800AF760,
    (char*) &D_800AF76C,
    (char*) &D_800AF780,
    (char*) &D_800AF790,
    (char*) &D_800AF7A4,
    (char*) &D_800AF7B4,
    (char*) &D_800AF7C4,
    (char*) &D_800AF7D4,
    (char*) &D_800AF7E4,
    (char*) &D_800AF7F4,
    (char*) &D_800AF804,
    (char*) &D_800AF814,
    (char*) &D_800AF828,
    (char*) &D_800AF83C,
    (char*) &D_800AF850,
    (char*) &D_800AF860,
    (char*) &D_800AF874,
    (char*) &D_800AF888,
    (char*) &D_800AF894,
    (char*) &D_800AF8A4,
    (char*) &D_800AF8B8,
    (char*) &D_800AF8C8,
    (char*) &D_800AF8D8,
    (char*) &D_800AF8E8,
    (char*) &D_800AF900,
    (char*) &D_800AF918,
    (char*) &D_800AF930,
    (char*) &D_800AF944,
    (char*) &D_800AF95C,
    (char*) &D_800AF96C,
    (char*) &D_800AF980,
    (char*) &D_800AF98C,
    (char*) &D_800AF99C,
    (char*) &D_800AF9B0,
    (char*) &D_800AF9C4,
    (char*) &D_800AF9D4,
    (char*) &D_800AF9E8,
    (char*) &D_800AF9FC,
    (char*) &D_800AFA14,
    (char*) &D_800AFA20,
    (char*) &D_800AFA30,
    (char*) &D_800AFA3C,
    (char*) &D_800AFA4C,
    (char*) &D_800AFA5C,
};

u32 D_800AE3EC[] = {
    (u32) &D_800AFA64, (u32) &D_800AFA78, (u32) &D_800AFA8C, (u32) &D_800AFA9C,
    (u32) &D_800AFAAC, (u32) &D_800AFABC, (u32) &D_800AFAC8, (u32) &D_800AFAD8,
    (u32) &D_800AFAE4, (u32) &D_800AFAF4, (u32) &D_800AFB04, (u32) &D_800AFB14,
    (u32) &D_800AFB28, (u32) &D_800AFB3C, (u32) &D_800AFB50, (u32) &D_800AFB60,
    (u32) &D_800AFB70, (u32) &D_800AFB84, (u32) &D_800AFB9C, (u32) &D_800AFBB0,
    (u32) &D_800AFBC0, (u32) &D_800AFBD0, (u32) &D_800AFBE0, (u32) &D_800AFBF0,
    (u32) &D_800AFC00, (u32) &D_800AFC10, (u32) &D_800AFC28, (u32) &D_800AFC38,
    (u32) &D_800AFC48, (u32) &D_800AFC58, (u32) &D_800AFC68, (u32) &D_800AFC78,
    (u32) &D_800AFC88, (u32) &D_800AFC98, (u32) &D_800AFCA8, (u32) &D_800AFCB4,
    (u32) &D_800AFCCC, (u32) &D_800AFCDC, (u32) &D_800AFCEC, (u32) &D_800AFCFC,
    (u32) &D_800AFD10, (u32) &D_800AFD24, (u32) &D_800AFD34, (u32) &D_800AFD40,
    (u32) &D_800AFD4C, (u32) &D_800AFD60, (u32) &D_800AFD70, (u32) &D_800AFD80,
    (u32) &D_800AFD90, (u32) &D_800AFDA0, (u32) &D_800AFDB0, (u32) &D_800AFDC0,
    (u32) &D_800AFDD4, (u32) &D_800AFDEC, (u32) &D_800AFDFC, (u32) &D_800AFE10,
    (u32) &D_800AFE20, (u32) &D_800AFE30, (u32) &D_800AFE40, (u32) &D_800AFE54,
    (u32) &D_800AFE68, (u32) &D_800AFE78,
};

s8 D_800AE4E4[156] = {
    0, -1, -1, 1, 2, 3, 4, -1, -1, -1, 5, 6, -1, 7, -1, 8,
    -1, -1, -1, -1, -1, -1, -1, -1, 9, -1, 10, 11, -1, -1, -1, -1,
    -1, -1, -1, -1, 12, -1, 13, -1, 14, -1, -1, -1, 15, -1, -1, -1,
    -1, 16, 17, 18, -1, 19, -1, 20, -1, 21, 22, 23, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, 24, 25, -1, -1, 26, 27, -1, -1, 28, 29, 30,
    31, 32, -1, 33, -1, -1, -1, 34, 35, 36, 37, -1, 38, -1, -1, -1,
    -1, -1, -1, -1, 39, -1, -1, -1, -1, -1, -1, -1, 40, -1, -1, -1,
    41, -1, 42, -1, -1, 43, -1, 44, 45, -1, 46, 47, 48, 49, -1, -1,
    50, 51, 52, 53, 54, -1, -1, -1, 55, -1, -1, -1, -1, -1, 56, 57,
    58, 59, 60, -1, 61, -1, 62, 0, 0, 0, 0, 0,
};

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

static s32 padding[2];
PhotoData D_800B0598[60]; // Size: 0xD980 - All photos taken in a level
PhotoData* D_800BDF18;
u8 D_800BDF1C;
u8 D_800BDF1D;
u8 D_800BDF1E;
s32 D_800BDF20[3];
ucolor D_800BDF2C;

extern GObj* photo_PokemonObjs[];
extern s32 photo_PokemonCount;

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
extern WorldSetup tunnel_WorldSetup;
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
        case PokemonID_ZAPDOS_EGG:
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
            ret = arg0->main.pokemons[0].pokemonID;
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
        case PokemonID_ZAPDOS_EGG:
        case PokemonID_603:
        case PokemonID_GATE:
        case PokemonID_EVOLUTION_CONTROLLER:
        case PokemonID_1003:
        case PokemonID_1006:
        case PokemonID_1008:
        case PokemonID_1009:
        case PokemonID_1010:
        case PokemonID_1012:
        case PokemonID_1013:
        case PokemonID_KOFFING_SMOKE:
        case PokemonID_SMOKE_PUFF:
        case PokemonID_LAVA_SPLASH:
        case PokemonID_VOLCANO_SMOKE:
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
        arg0->specialID = pokemon->specialPoseID;
        arg0->unk_00_13 = func_8009BD4C(pokemonID, pokemon->modelAnims, D_800AD4B8, ARRAY_COUNT(D_800AD4B8));
        if (pokemon->poseID > 0) {
            arg0->poseID = pokemon->poseID;
        } else {
            sp24 = func_8009BDDC(arg0->pokemonID, arg0->unk_00_13);
            if (sp24 >= getNumberOfPoses()) {
                arg0->poseID = 0;
            } else if (sp24 > 0) {
                arg0->poseID = sp24;
            } else {
                arg0->poseID = 0;
            }
        }
    } else {
        arg0->poseID = 0;
        arg0->specialID = 0;
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
                    arg0->yaw = ((struct Mtx4Float*) csr)->v.y;
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
        arg0->yaw = model->rotation.v.y;
    }
    return true;
}

void func_8009C25C(UnkThing* arg0, u8 objIndex) {
    GObj* obj;
    s32 i = 0;
    obj = omGObjListHead[objIndex];

    while (obj != NULL && i < ARRAY_COUNT(arg0->main.pokemons)) {
        if (func_8009BF48(&arg0->main.pokemons[i], obj) != 0) {
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
    if (obj->flags & GOBJ_FLAG_HIDDEN) {
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
        if (!(obj->flags & GOBJ_FLAG_HIDDEN) &&
            (func_803647BC_504BCC(obj) == 0) &&
            (func_8009C304(&arg0->main.items[i], obj) != 0)) {
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

s32 func_80364494_5048A4(Particle* particle, f32* x, f32* y, f32* z, f32* s);

void func_8009C604(UnkThing* arg0) {
    s32 i;
    s32 count;
    Particle* particle;
    f32 x, y, z, s;
    s32 unused;
    Unk8009C604 sp60[100];

    count = 0;
    for (i = 0; i < ARRAY_COUNT(D_800BE1A8); i++) {
        for (particle = D_800BE1A8[i]; particle != NULL; particle = particle->next) {
            if (func_80364494_5048A4(particle, &x, &y, &z, &s) || (s16) (particle->size * 128.0f) == 0 || particle->primColor.a == 0) {
                if (0) {
                } // TODO fake match
                continue;
            }
            sp60[count].particle = particle;
            sp60[count].unk_04 = particle->size * s;
            sp60[count].unk_08 = z;
            count++;
            if (count >= 100) {
                break;
            }
        }
        if (count >= 100) {
            break;
        }
    }

    particle = sp60[count - i - 1].particle; // TODO fake match

    if (count > 32) {
        qsort2(sp60, count, sizeof(Unk8009C604), func_8009C5C4);
        count = 32;
    }

    qsort2(sp60, count, sizeof(Unk8009C604), func_8009C584);
    for (i = 0; i < count; i++) {
        particle = sp60[count - i - 1].particle;
        arg0->main.effects[i].textureID = particle->textureID;
        arg0->main.effects[i].dataID = particle->dataID;
        arg0->main.effects[i].unk_03 = (particle->flags >> 4) & 0xFF;
        arg0->main.effects[i].bankID = particle->bankID & 7;
        arg0->main.effects[i].posX = particle->pos.x * 8.0f;
        arg0->main.effects[i].posY = particle->pos.y * 8.0f;
        arg0->main.effects[i].posZ = particle->pos.z * 8.0f;
        arg0->main.effects[i].size = particle->size * 128.0f;
        arg0->main.effects[i].primColor = particle->primColor;
    }
}

void func_8009C8E4(OMCamera* arg0, MovementState* arg1, UnkThing* arg2) {
    s32 i;

    // clang-format off
    for (i = 0; i < ARRAY_COUNT(arg2->main.items); i++) { arg2->main.items[i].itemType = -1; }
    // clang-format on

    // clang-format off
    for (i = 0; i < ARRAY_COUNT(arg2->main.effects); i++) { arg2->main.effects[i].textureID = -1; }
    // clang-format on

    for (i = 0; i < ARRAY_COUNT(arg2->main.pokemons); i++) {
        arg2->main.pokemons[i].pokemonID = -1;
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

    for (i = 0; i < ARRAY_COUNT(temp_s4->items); i++) {
        memcpy(&temp_s4->items[i], &sp38->main.items[i], sizeof(temp_s4->items[0]));
    }

    for (i = 0; i < ARRAY_COUNT(temp_s4->effects); i++) {
        memcpy(&temp_s4->effects[i], &sp38->main.effects[i], sizeof(temp_s4->effects[0]));
    }

    if (pokemonObj == NULL) {
        for (i = 0; i < ARRAY_COUNT(temp_s4->pokemons); i++) {
            memcpy(&temp_s4->pokemons[i], &sp38->main.pokemons[i], sizeof(temp_s4->pokemons[0]));
        }
    } else {
        sp34 = gPokemonIdInFocus;
        // TODO clean if
        if (sp34 == PokemonID_1004 || sp34 == PokemonID_1018 || sp34 == PokemonID_1022 || (cond = true, sp34 == PokemonID_1035)) {
            for (i = 0; i < ARRAY_COUNT(temp_s4->pokemons); i++) {
                memcpy(&temp_s4->pokemons[i], &sp38->main.pokemons[i], sizeof(temp_s4->pokemons[0]));
            }
        } else {
            for (i = 0; i < ARRAY_COUNT(sp38->pokemonObjects); i++) {
                if (pokemonObj == sp38->pokemonObjects[i]) {
                    cond = false;
                    break;
                }
            }

            if (cond) {
                for (i = 0; i < ARRAY_COUNT(temp_s4->pokemons); i++) {
                    memcpy(&temp_s4->pokemons[i], &sp38->main.pokemons[i], sizeof(temp_s4->pokemons[0]));
                }
            } else {
                idx = 1;
                for (i = 0; i < ARRAY_COUNT(temp_s4->pokemons); i++) {
                    if (pokemonObj == sp38->pokemonObjects[i]) {
                        memcpy(&temp_s4->pokemons[0], &sp38->main.pokemons[i], sizeof(temp_s4->pokemons[0]));
                    } else {
                        memcpy(&temp_s4->pokemons[idx], &sp38->main.pokemons[i], sizeof(temp_s4->pokemons[1]));
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
    dobj->rotation.v.x = dobj->rotation.v.z = 0.0f;
    dobj->rotation.v.y = arg2->euler.y;
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
    arg0->collisionModels = NULL;
    createWorld(arg0, 99, 100, 126, D_800BDF1D, D_800BDF1C, func_8009D0B4, 0, 0);
    setSkyBoxAnimationSpeed(0.0f);
}

void func_8009D1E8(u32 romStart, s32 romEnd, s32 ramDst) {
    if (romEnd >= romStart) {
        dmaReadRom((void*) romStart, (void*) ramDst, romEnd - romStart);
    }
}

void func_8009D21C(s32 bankID, s32* spritesDesc) {
    s32 i, j;

    if (bankID >= PARTICLE_BANKS_MAX) {
        return;
    }

    fx_SpriteBanksNum[bankID] = *spritesDesc;
    fx_SpriteBanks[bankID] = (EffectSprites**) (spritesDesc + 1);

    for (i = 1; i <= fx_SpriteBanksNum[bankID]; i++) {
        spritesDesc[i] = (u32) (spritesDesc) + spritesDesc[i];
    }

    for (i = 0; i < fx_SpriteBanksNum[bankID]; i++) {
        for (j = 0; j < fx_SpriteBanks[bankID][i]->numFrames; j++) {
            fx_SpriteBanks[bankID][i]->data[j] += (u32) spritesDesc;
        }
        if (fx_SpriteBanks[bankID][i]->fmt == G_IM_FMT_CI) {
            if (fx_SpriteBanks[bankID][i]->flags & 1) {
                j = fx_SpriteBanks[bankID][i]->numFrames;
                fx_SpriteBanks[bankID][i]->data[j] += (u32) spritesDesc;
            } else {
                for (j = fx_SpriteBanks[bankID][i]->numFrames; j < 2 * fx_SpriteBanks[bankID][i]->numFrames; j++) {
                    fx_SpriteBanks[bankID][i]->data[j] += (u32) spritesDesc;
                }
            }
        }
    }
}

void func_8009D37C(u8 levelID) {
    if (levelID < 0) {
        return;
    }

    switch (levelID) {
        case SCENE_BEACH:
            func_8009D184(&D_8011B914);
            func_8009D1E8((u32) fx_img_beach_ROM_START, (u32) fx_img_beach_ROM_END, (s32) &D_801D6840);
            func_8009D21C(0, &D_801D6840);
            D_800BDF2C.r = 0xFF;
            D_800BDF2C.g = 0xFF;
            D_800BDF2C.b = 0xFF;
            D_800BDF2C.a = 0;
            break;
        case SCENE_TUNNEL:
            func_8009D184(&tunnel_WorldSetup);
            func_8009D1E8((u32) fx_img_tunnel_ROM_START, (u32) fx_img_tunnel_ROM_END, (s32) &D_801B1230);
            func_8009D21C(0, &D_801B1230);
            D_800BDF2C.r = 0x80;
            D_800BDF2C.g = 0x80;
            D_800BDF2C.b = 0;
            D_800BDF2C.a = 0;
            memcpy(&D_801AFD30, &D_80188D28, 0x1500);
            break;
        case SCENE_CAVE:
            func_8009D184(&D_8012A0E8);
            func_8009D1E8((u32) fx_img_cave_ROM_START, (u32) fx_img_cave_ROM_END, (s32) &D_801CF840);
            func_8009D21C(0, &D_801CF840);
            D_800BDF2C.r = 0xFF;
            D_800BDF2C.g = 0xFF;
            D_800BDF2C.b = 0xFF;
            D_800BDF2C.a = 0;
            memcpy(&D_801CE400, &D_8017A780, 0x1440);
            break;
        case SCENE_RIVER:
            func_8009D184(&D_8012AC90);
            func_8009D1E8((u32) fx_img_river_ROM_START, (u32) fx_img_river_ROM_END, (s32) &D_801B6B60);
            func_8009D21C(0, &D_801B6B60);
            D_800BDF2C.r = 0x80;
            D_800BDF2C.g = 0x80;
            D_800BDF2C.b = 0x80;
            D_800BDF2C.a = 0;
            break;
        case SCENE_VOLCANO:
            func_8009D184(&volcano_WorldSetup);
            func_8009D1E8((u32) fx_img_volcano_ROM_START, (u32) fx_img_volcano_ROM_END, (s32) &D_801CF770);
            func_8009D21C(0, &D_801CF770);
            D_800BDF2C.r = 0xFF;
            D_800BDF2C.g = 0;
            D_800BDF2C.b = 0;
            D_800BDF2C.a = 0;
            break;
        case SCENE_VALLEY:
            func_8009D184(&D_80100720);
            func_8009D1E8((u32) fx_img_valley_ROM_START, (u32) fx_img_valley_ROM_END, (s32) &D_801B1D40);
            func_8009D21C(0, &D_801B1D40);
            D_800BDF2C.r = 0x80;
            D_800BDF2C.g = 0x80;
            D_800BDF2C.b = 0x80;
            D_800BDF2C.a = 0;
            break;
        case SCENE_RAINBOW:
            func_8009D184(&D_800F5DA0);
            func_8009D1E8((u32) fx_img_rainbow_ROM_START, (u32) fx_img_rainbow_ROM_END, (s32) &D_8013E260);
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
                                     model->rotation.v.x, model->rotation.v.y, model->rotation.v.z,
                                     model->scale.v.x, model->scale.v.y, model->scale.v.z);
    guMtxCatF(sp74, spB4, spB4);
    model->position.v.x = spB4[3][0];
    model->position.v.y = spB4[3][1];
    model->position.v.z = spB4[3][2];
    model->rotation.v.y += arg0->yaw;
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
        case PokemonID_ZAPDOS_EGG:
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

    photo_PokemonCount = 0;

    for (i = 0; i < ARRAY_COUNT(photoData->pokemons); i++) {
        if (photoData->pokemons[i].pokemonID < 0) {
            return;
        }
        for (it = D_800ADBEC; it->unk_00 != 0; it++) {
            if (it->unk_00 == photoData->pokemons[i].pokemonID) {
                gobj = func_8009D9A0(&photoData->pokemons[i], it->unk_04, it->unk_08, it->unk_0C, it->unk_10);
                if ((photoData->pokemons[i].pokemonID > 0 && photoData->pokemons[i].pokemonID <= POKEDEX_MAX) ||
                    photoData->pokemons[i].pokemonID == PokemonID_603 ||
                    photoData->pokemons[i].pokemonID == PokemonID_MOLTRES_EGG ||
                    photoData->pokemons[i].pokemonID == PokemonID_601 ||
                    photoData->pokemons[i].pokemonID == PokemonID_ZAPDOS_EGG) {
                    photo_PokemonObjs[photo_PokemonCount] = gobj;
                    photo_PokemonIndexes[photo_PokemonCount] = i;
                    photo_PokemonCount++;
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

    for (i = 0; i < ARRAY_COUNT(photoData->items); i++) {
        temp_s3 = photoData->items[i].animationTime;
        switch (photoData->items[i].itemType) {
            case 1:
                func_8009E110(
                    func_8009E050(&photoData->items[i], &D_800E9138, &D_800E8EB8, renderModelTypeBFogged),
                    NULL,
                    &D_800E91C0,
                    temp_s3);
                break;
            case 2:
                gobj = func_8009E050(&photoData->items[i], &D_800EAED0, &D_800EAC58, renderModelTypeBFogged);
                func_8009E110(gobj, NULL, &D_800EAF60, temp_s3 & 0xF);
                gobj->data.dobj->scale.v.x = (gobj->data.dobj->scale.v.x * (temp_s3 >> 4)) / 15.0f;
                gobj->data.dobj->scale.v.y = (gobj->data.dobj->scale.v.y * (temp_s3 >> 4)) / 15.0f;
                gobj->data.dobj->scale.v.z = (gobj->data.dobj->scale.v.z * (temp_s3 >> 4)) / 15.0f;
                break;
            case 3:
                func_8009E110(
                    func_8009E050(&photoData->items[i], &D_800EB430, &D_800EB510, renderModelTypeDFogged),
                    &D_800EAFB0,
                    &D_800EB0C0,
                    temp_s3);
                break;
            case 4:
                func_8009E110(
                    func_8009E050(&photoData->items[i], &D_800EDAB0, &D_800EDB90, renderModelTypeDFogged),
                    &D_800ED5B0,
                    &D_800ED6B0,
                    temp_s3);
                break;
            default:
                return;
        }
    }
}

void func_8009E3D0(GObj* gobj) {
    EffectPhotoData* fx;
    u8* lastPalette;
    u32 lastAlphaCompare;
    s32 lastBlendAlpha;
    s32 lastTextureLUT;
    Mtx4f viewMtx;
    Mtx4f projMtx;
    EffectSprites* sprites;
    OMCamera* cam;
    u8* lastTexture;
    f32 z;
    f32 y;
    u8** pal;
    f32 w;
    f32 invW;
    f32 sx;
    f32 scaleX;
    f32 scaleY;
    f32 vscaleX;
    f32 vtransX;
    f32 vscaleY;
    f32 vtransY;
    f32 vscaleZ;
    f32 vtransZ;
    s32 dsdx;
    s32 dtdy;
    f32 sy;
    f32 sz;
    f32 left;
    f32 right;
    f32 top;
    f32 bottom;
    s32 i;
    s32 fmt;
    s32 siz;
    s32 width;
    s32 height;
    s32 cms;
    s32 cmt;
    u8* palette;
    u8 masks;
    u8 maskt;
    u32 alphaCompare;
    u16 flags;
    u8* texture;

    fx = gobj->userData;
    cam = omCurrentCamera->data.cam;

    gDPPipeSync(gMainGfxPos[0]++);
    gDPSetCycleType(gMainGfxPos[0]++, G_CYC_1CYCLE);
    gDPSetRenderMode(gMainGfxPos[0]++, G_RM_AA_ZB_XLU_SURF, G_RM_NOOP2);
    gDPSetColorDither(gMainGfxPos[0]++, G_CD_MAGICSQ);
    gDPSetAlphaDither(gMainGfxPos[0]++, G_AD_PATTERN);
    gDPSetEnvColor(gMainGfxPos[0]++, D_800BDF2C.r, D_800BDF2C.g, D_800BDF2C.b, D_800BDF2C.a);
    gDPSetTexturePersp(gMainGfxPos[0]++, G_TP_PERSP);
    gDPSetDepthSource(gMainGfxPos[0]++, G_ZS_PIXEL);
    gDPSetTextureLUT(gMainGfxPos[0]++, G_TT_NONE);
    gtlCombineAllDLists();

    hal_look_at_f(viewMtx, cam->viewMtx.lookAt.eye.x, cam->viewMtx.lookAt.eye.y, cam->viewMtx.lookAt.eye.z,
                  cam->viewMtx.lookAt.at.x, cam->viewMtx.lookAt.at.y, cam->viewMtx.lookAt.at.z,
                  cam->viewMtx.lookAt.up.x, cam->viewMtx.lookAt.up.y, cam->viewMtx.lookAt.up.z);
    hal_perspective_fast_f(projMtx, NULL, cam->perspMtx.persp.fovy, cam->perspMtx.persp.aspect,
                           cam->perspMtx.persp.near, cam->perspMtx.persp.far, cam->perspMtx.persp.scale);
    guMtxCatF(viewMtx, projMtx, projMtx);

    vscaleX = cam->vp.vp.vscale[0];
    vscaleY = -cam->vp.vp.vscale[1];
    vscaleZ = cam->vp.vp.vscale[2];
    vtransX = cam->vp.vp.vtrans[0];
    vtransY = cam->vp.vp.vtrans[1];
    vtransZ = cam->vp.vp.vtrans[2];

    scaleX = sqrtf(SQ(projMtx[0][0]) + SQ(projMtx[1][0]) + SQ(projMtx[2][0]));
    scaleY = sqrtf(SQ(projMtx[0][1]) + SQ(projMtx[1][1]) + SQ(projMtx[2][1]));

    lastTexture = NULL;
    gDPPipeSync(gMainGfxPos[0]++);
    gDPSetCycleType(gMainGfxPos[0]++, G_CYC_1CYCLE);
    gDPSetRenderMode(gMainGfxPos[0]++, G_RM_AA_ZB_XLU_SURF, G_RM_NOOP2);
    gDPSetTexturePersp(gMainGfxPos[0]++, G_TP_NONE);
    gDPSetDepthSource(gMainGfxPos[0]++, G_ZS_PRIM);
    gDPSetColorDither(gMainGfxPos[0]++, G_CD_MAGICSQ);
    gDPSetAlphaDither(gMainGfxPos[0]++, G_AD_PATTERN);
    gDPSetEnvColor(gMainGfxPos[0]++, D_800BDF2C.r, D_800BDF2C.g, D_800BDF2C.b, D_800BDF2C.a);

    lastPalette = NULL;
    lastAlphaCompare = -1;
    lastBlendAlpha = -1;
    lastTextureLUT = -1;

    for (i = 0; i < 32; i++) {
        if (fx[i].textureID < 0) {
            continue;
        }
        left = fx[i].posX * 0.125f;
        top = fx[i].posY * 0.125f;
        z = fx[i].posZ * 0.125f;
        sx = projMtx[0][0] * left + projMtx[1][0] * top + projMtx[2][0] * z + projMtx[3][0];
        sy = projMtx[0][1] * left + projMtx[1][1] * top + projMtx[2][1] * z + projMtx[3][1];
        sz = projMtx[0][2] * left + projMtx[1][2] * top + projMtx[2][2] * z + projMtx[3][2];
        invW = projMtx[0][3] * left + projMtx[1][3] * top + projMtx[2][3] * z + projMtx[3][3];
        if (invW == 0.0f) {
            continue;
        }
        invW = 1.0f / invW;
        sx *= invW;
        sy *= invW;
        sz *= invW;
        if (sx < -1.0f || sx > 1.0f || sy < -1.0f || sy > 1.0f || sz < -1.0f || sz > 1.0f) {
            continue;
        }

        invW *= (fx[i].size / 128.0f);
        right = invW * scaleX + sx;
        bottom = invW * scaleY + sy;
        sx = sx * vscaleX + vtransX;
        right = right * vscaleX + vtransX;
        if (sx < right) {
            left = sx - (right - sx);
        } else {
            left = right;
            right = sx - (right - sx);
        }
        sy = sy * vscaleY + vtransY;
        bottom = bottom * vscaleY + vtransY;
        if (sy < bottom) {
            top = sy - (bottom - sy);
        } else {
            top = bottom;
            bottom = sy - (bottom - sy);
        }

        sz = sz * vscaleZ + vtransZ;
        flags = fx[i].unk_03 << 4;
        fmt = fx_SpriteBanks[fx[i].bankID][fx[i].textureID]->fmt;
        siz = fx_SpriteBanks[fx[i].bankID][fx[i].textureID]->siz;
        width = fx_SpriteBanks[fx[i].bankID][fx[i].textureID]->width;
        height = fx_SpriteBanks[fx[i].bankID][fx[i].textureID]->height;
        texture = fx_SpriteBanks[fx[i].bankID][fx[i].textureID]->data[fx[i].dataID];
        if (fmt == G_IM_FMT_CI) {
            pal = &fx_SpriteBanks[fx[i].bankID][fx[i].textureID]->data[fx_SpriteBanks[fx[i].bankID][fx[i].textureID]->numFrames];
            if (!(flags & 0x10)) {
                palette = pal[fx[i].dataID];
            } else {
                palette = pal[0];
            }
        }

        dsdx = (width * 4096.0f) / (right - left);
        dtdy = (height * 4096.0f) / (bottom - top);

        if (flags & 0x20) {
            dsdx *= 2;
            cms = G_TX_MIRROR;
            switch (width) {
                case 2:
                    masks = 1;
                    break;
                case 4:
                    masks = 2;
                    break;
                case 8:
                    masks = 3;
                    break;
                case 16:
                    masks = 4;
                    break;
                case 32:
                    masks = 5;
                    break;
                case 64:
                    masks = 6;
                    break;
                case 128:
                    masks = 7;
                    break;
                case 256:
                    masks = 8;
                    break;
                default:
                    masks = 0;
                    break;
            }
        } else {
            cms = G_TX_CLAMP;
            masks = 0;
        }

        if (flags & 0x40) {
            dtdy *= 2;
            cmt = G_TX_MIRROR;
            switch (height) {
                case 2:
                    maskt = 1;
                    break;
                case 4:
                    maskt = 2;
                    break;
                case 8:
                    maskt = 3;
                    break;
                case 16:
                    maskt = 4;
                    break;
                case 32:
                    maskt = 5;
                    break;
                case 64:
                    maskt = 6;
                    break;
                case 128:
                    maskt = 7;
                    break;
                case 256:
                    maskt = 8;
                    break;
                default:
                    maskt = 0;
                    break;
            }
        } else {
            cmt = G_TX_CLAMP;
            maskt = 0;
        }

        if (fmt == G_IM_FMT_CI) {
            if (palette != lastPalette) {
                gDPLoadTLUT_pal256(gMainGfxPos[0]++, palette);
                lastPalette = palette;
            }
            if (lastTextureLUT != G_TT_RGBA16) {
                gDPSetTextureLUT(gMainGfxPos[0]++, G_TT_RGBA16);
                lastTextureLUT = G_TT_RGBA16;
            }
        } else if (lastTextureLUT != G_TT_NONE) {
            gDPSetTextureLUT(gMainGfxPos[0]++, G_TT_NONE);
            lastTextureLUT = G_TT_NONE;
        }

        if (texture != lastTexture) {
            switch (siz) {
                case G_IM_SIZ_4b:
                    gDPLoadTextureBlock_4b(gMainGfxPos[0]++, texture, fmt, width, height, 0, cms, cmt, masks, maskt, G_TX_NOLOD, G_TX_NOLOD);
                    break;
                case G_IM_SIZ_8b:
                    gDPLoadTextureBlock(gMainGfxPos[0]++, texture, fmt, G_IM_SIZ_8b, width, height, 0, cms, cmt, masks, maskt, G_TX_NOLOD, G_TX_NOLOD);
                    break;
                case G_IM_SIZ_16b:
                    gDPLoadTextureBlock(gMainGfxPos[0]++, texture, fmt, G_IM_SIZ_16b, width, height, 0, cms, cmt, masks, maskt, G_TX_NOLOD, G_TX_NOLOD);
                    break;
                case G_IM_SIZ_32b:
                    gDPLoadTextureBlock(gMainGfxPos[0]++, texture, fmt, G_IM_SIZ_32b, width, height, 0, cms, cmt, masks, maskt, G_TX_NOLOD, G_TX_NOLOD);
                    break;
            }
            lastTexture = texture;
        }

        gDPSetPrimColor(gMainGfxPos[0]++, 0, 0, fx[i].primColor.r, fx[i].primColor.g, fx[i].primColor.b, fx[i].primColor.a);
        if (flags & 0x80) {
            gDPSetCombineLERP(gMainGfxPos[0]++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT,
                              PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT,
                              PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT,
                              PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT);
        } else if (flags & 0x100) {
            gDPSetCombineLERP(gMainGfxPos[0]++, NOISE, 0, TEXEL0, 0,
                              TEXEL0, 0, PRIMITIVE, 0,
                              NOISE, 0, TEXEL0, 0,
                              TEXEL0, 0, PRIMITIVE, 0);
        } else {
            gDPSetCombineMode(gMainGfxPos[0]++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
        }

        if (flags & 0x400) {
            alphaCompare = G_AC_DITHER;
        } else {
            alphaCompare = G_AC_THRESHOLD;
            if (lastBlendAlpha != 8) {
                gDPSetBlendColor(gMainGfxPos[0]++, 0, 0, 0, 8);
                lastBlendAlpha = 8;
            }
        }
        if (lastAlphaCompare != alphaCompare) {
            gDPSetAlphaCompare(gMainGfxPos[0]++, alphaCompare);
            lastAlphaCompare = alphaCompare;
        }

        gDPSetPrimDepth(gMainGfxPos[0]++, (s32) (sz * 32.0f), 0);
        gSPScisTextureRectangle(gMainGfxPos[0]++, (s32) left, (s32) top, (s32) right, (s32) bottom, G_TX_RENDERTILE, 0, 0, dsdx, dtdy);
    }

    gDPPipeSync(gMainGfxPos[0]++);
    gDPSetTexturePersp(gMainGfxPos[0]++, G_TP_PERSP);
    gDPSetDepthSource(gMainGfxPos[0]++, G_ZS_PIXEL);
    if (lastTextureLUT != G_TT_NONE) {
        gDPSetTextureLUT(gMainGfxPos[0]++, G_TT_NONE);
    }
}

void func_8009FA00(OMCamera* cam, PhotoData* photoData) {
    GObj* gobj;

    gobj = omAddGObj(OBJID_128, NULL, D_800BDF1E, 0x80000000);
    gobj->userData = &photoData->effects;
    omLinkGObjDL(gobj, func_8009E3D0, D_800BDF1C, 0, -1);
}

void initObjectsOnPhoto(OMCamera* cam, PhotoData* photoData) {
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
    temp_v0 = func_800A73C0((u32) fx_img_common_ROM_START, (u32) fx_img_common_ROM_END);
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
