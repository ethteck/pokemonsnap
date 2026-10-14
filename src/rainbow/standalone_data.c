#include "rainbow.h"

/* Native records in original physical order. */
extern Collider D_800EDF78_6B728[];
extern Texture** D_80116CF0_4C90C0[];
extern UnkEC64Arg3 D_80116EF0_4C92C0[];
extern AnimCmd* D_80117210_4C95E0[];
extern AnimCmd** D_80117260_4C9630[];
extern AnimCmd* D_80117310_4C96E0[];
extern AnimCmd** D_80117360_4C9730[];
extern AnimCmd* D_80117410_4C97E0[];
extern AnimCmd** D_80117480_4C9850[];
extern AnimCmd* D_80117570_4C9940[];
extern AnimCmd** D_801175E0_4C99B0[];
extern AnimCmd* D_801176D0_4C9AA0[];
extern AnimCmd** D_80117730_4C9B00[];
extern AnimCmd* D_80117840_4C9C10[];
extern AnimCmd** D_801178A0_4C9C70[];
extern AnimCmd* D_80117980_4C9D50[];
extern AnimCmd** D_801179C0_4C9D90[];
extern AnimCmd* D_80117A50_4C9E20[];
extern AnimCmd** D_80117A90_4C9E60[];
extern AnimCmd* D_80117B20_4C9EF0[];
extern AnimCmd** D_80117B60_4C9F30[];
extern AnimCmd* D_80117C70_4CA040[];
extern AnimCmd** D_80117CB0_4CA080[];
extern AnimCmd* D_80117DC0_4CA190[];
extern AnimCmd** D_80117DF0_4CA1C0[];
extern AnimCmd* D_80117F10_4CA2E0[];
extern AnimCmd** D_80117F40_4CA310[];
extern Texture** D_80118160_4CA530[];
extern UnkEC64Arg3 D_80118210_4CA5E0[];
extern AnimCmd* D_80118360_4CA730[];
extern AnimCmd** D_80118390_4CA760[];
extern AnimCmd* D_8012C9E0_4DEDB0[];
extern AnimCmd* D_8012D700_4DFAD0[];
extern AnimCmd* D_8012EFF0_4E13C0[];
extern AnimCmd* D_8012FB60_4E1F30[];
extern AnimCmd* D_80131D30_4E4100[];
extern AnimCmd* D_80133040_4E5410[];
extern AnimCmd* D_801358A0_4E7C70[];
extern AnimCmd* D_801368F0_4E8CC0[];
extern AnimCmd** D_801394D0_4EB8A0[];
extern AnimCmd** D_801395A0_4EB970[];
extern AnimCmd** D_80139690_4EBA60[];
extern AnimCmd** D_80139770_4EBB40[];
extern AnimCmd** D_80139840_4EBC10[];
extern AnimCmd** D_80139900_4EBCD0[];
extern AnimCmd** D_80139A00_4EBDD0[];
extern AnimCmd** D_80139B00_4EBED0[];
extern AnimCmd** evolution_controller_matanim[];
extern Texture** evolution_controller_materials[];
extern UnkEC64Arg3 evolution_controller_model[];
extern AnimCmd* evolution_controller_modelanim[];
extern void func_80348970_8280E0(GObj*);
extern void func_80348A04_828174(GObj*);
extern GObj* func_80348FB8_828728(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn);
extern void func_80349180_8288F0(GObj*);
extern void func_8034930C_828A7C(GObj*);
extern void func_8034935C_828ACC(GObj*);
extern void func_803493F4_828B64(GObj*);
extern void func_80349480_828BF0(GObj*);
extern void func_80349514_828C84(GObj*);
extern void func_8034956C_828CDC(GObj*);
extern void func_803495FC_828D6C(GObj*);
extern void func_80349654_828DC4(GObj*);
extern void func_803496BC_828E2C(GObj*);
extern void func_80349714_828E84(GObj*);
extern void func_8034977C_828EEC(GObj*);
extern void func_80349814_828F84(GObj*);
extern void func_803498A0_829010(GObj*);
extern void func_80349934_8290A4(GObj*);
extern void func_8034998C_8290FC(GObj*);
extern void func_80349A1C_82918C(GObj*);
extern void func_80349A74_8291E4(GObj*);
extern void func_80349ADC_82924C(GObj*);
extern void func_80349B34_8292A4(GObj*);
extern void func_80349B98_829308(GObj*);
extern void func_80349DB0_829520(GObj*);
extern void func_80349DE8_829558(GObj*);
extern void func_80349F00_829670(GObj*);
extern GObj* func_8034A064_8297D4(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn);
extern void func_8034A190_829900(GObj*);
extern AnimCmd** gate_matanim_closed[];
extern AnimCmd** gate_matanim_opened[];
extern AnimCmd** gate_matanim_opening[];
extern AnimCmd** gate_matanim_raise_bar[];
extern Texture** gate_materials[];
extern UnkEC64Arg3 gate_model[];
extern AnimCmd* gate_modelanim_closed[];
extern AnimCmd* gate_modelanim_opened[];
extern AnimCmd* gate_modelanim_opening[];
extern AnimCmd* gate_modelanim_raise_bar[];
extern void pokemonChangeBlock(GObj*, f32, f32, f32, f32, f32, f32);
extern void pokemonRemoveOne(GObj*);
extern void renderModelTypeDFogged(GObj*);
extern void renderPokemonModelTypeDFogged(GObj*);
extern AnimationHeader D_8034AED0_82A640;
extern AnimationHeader D_8034AEE4_82A654;
extern AnimationHeader D_8034AEF8_82A668;
extern AnimationHeader D_8034AF0C_82A67C;
extern CollisionModel D_8034AF20_82A690;
extern GObj* D_8034AF2C_82A69C;
extern s32 D_8034AF30_82A6A0;
extern s32 D_8034AF34_82A6A4;
extern s32 D_8034AF38_82A6A8;
extern InteractionHandler D_8034AF3C_82A6AC[2];
extern Unks16 D_8034AF5C_82A6CC;
extern PokemonAnimationSetup D_8034AF64_82A6D4;
extern PokemonInitData D_8034AF78_82A6E8;
extern PokemonDef D_8034AFAC_82A71C;
extern s32 D_8034AFC0_82A730[1];
extern s32 D_8034AFC4_82A734[1];
extern s32 D_8034AFC8_82A738[2];
extern s32 D_8034AFD0_82A740[1];
extern s32 D_8034AFD4_82A744[1];
extern s32 D_8034AFD8_82A748[2];
extern AnimationHeader D_8034AFE0_82A750;
extern AnimationHeader D_8034AFF4_82A764;
extern AnimationHeader D_8034B008_82A778;
extern AnimationHeader D_8034B01C_82A78C;
extern AnimationHeader D_8034B030_82A7A0;
extern AnimationHeader D_8034B044_82A7B4;
extern AnimationHeader D_8034B058_82A7C8;
extern AnimationHeader D_8034B06C_82A7DC;
extern s32 D_8034B080_82A7F0[2];
extern s32 D_8034B088_82A7F8[2];
extern s32 D_8034B090_82A800[2];
extern AnimationHeader D_8034B098_82A808;
extern AnimationHeader D_8034B0AC_82A81C;
extern AnimationHeader D_8034B0C0_82A830;
extern AnimationHeader D_8034B0D4_82A844;
extern AnimationHeader D_8034B0E8_82A858;
extern AnimationHeader D_8034B0FC_82A86C;
extern AnimationHeader D_8034B110_82A880;
extern AnimationHeader D_8034B124_82A894;
extern AnimationHeader D_8034B138_82A8A8;
extern AnimationHeader D_8034B14C_82A8BC;
extern AnimationHeader D_8034B160_82A8D0;
extern AnimationHeader D_8034B174_82A8E4;
extern InteractionHandler D_8034B188_82A8F8[2];
extern InteractionHandler D_8034B1A8_82A918[6];
extern InteractionHandler D_8034B208_82A978[3];
extern InteractionHandler D_8034B238_82A9A8[3];
extern InteractionHandler D_8034B268_82A9D8[3];
extern InteractionHandler D_8034B298_82AA08[3];
extern InteractionHandler D_8034B2C8_82AA38[6];
extern InteractionHandler D_8034B328_82AA98[2];
extern InteractionHandler D_8034B348_82AAB8[7];
extern InteractionHandler D_8034B3B8_82AB28[3];
extern InteractionHandler D_8034B3E8_82AB58[3];
extern InteractionHandler D_8034B418_82AB88[3];
extern InteractionHandler D_8034B448_82ABB8[3];
extern InteractionHandler D_8034B478_82ABE8[7];
extern InteractionHandler D_8034B4E8_82AC58[4];
extern Vec3f D_8034B528_82AC98;
extern Vec3f D_8034B534_82ACA4;
extern PokemonAnimationSetup D_8034B540_82ACB0;
extern PokemonInitData D_8034B554_82ACC4;
extern AnimationHeader D_8034B590_82AD00;
extern PokemonAnimationSetup D_8034B5A4_82AD14;
extern PokemonInitData D_8034B5B8_82AD28;
extern PokemonDef D_8034B5EC_82AD5C;
extern AnimationHeader D_8034B600_82AD70;
extern InteractionHandler D_8034B614_82AD84[1];
extern PokemonAnimationSetup D_8034B624_82AD94;
extern PokemonInitData D_8034B638_82ADA8;
extern s32 D_8034B670_82ADE0;
extern GObj* D_8034B674_82ADE4;

/* ROM 82A640; VRAM 8034AED0. */
AnimationHeader D_8034AED0_82A640 = { 1.0f, 100.0f, gate_modelanim_closed, gate_matanim_closed, NULL };

/* ROM 82A654; VRAM 8034AEE4. */
AnimationHeader D_8034AEE4_82A654 = { 1.0f, 100.0f, gate_modelanim_raise_bar, gate_matanim_raise_bar, NULL };

/* ROM 82A668; VRAM 8034AEF8. */
AnimationHeader D_8034AEF8_82A668 = { 1.0f, 100.0f, gate_modelanim_opening, gate_matanim_opening, NULL };

/* ROM 82A67C; VRAM 8034AF0C. */
AnimationHeader D_8034AF0C_82A67C = { 1.0f, 100.0f, gate_modelanim_opened, gate_matanim_opened, NULL };

/* ROM 82A690; VRAM 8034AF20. */
CollisionModel D_8034AF20_82A690 = { 1001, D_800EDF78_6B728, 1.0f };

/* ROM 82A69C; VRAM 8034AF2C. */
GObj* D_8034AF2C_82A69C = NULL;

/* ROM 82A6A0; VRAM 8034AF30. */
s32 D_8034AF30_82A6A0 = -1;

/* ROM 82A6A4; VRAM 8034AF34. */
s32 D_8034AF34_82A6A4 = 0;

/* ROM 82A6A8; VRAM 8034AF38. */
s32 D_8034AF38_82A6A8 = 0;

/* ROM 82A6AC; VRAM 8034AF3C. */
InteractionHandler D_8034AF3C_82A6AC[2] = {
    { 16, func_80348A04_828174, 5000.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 82A6CC; VRAM 8034AF5C. */
Unks16 D_8034AF5C_82A6CC = { { 151, 1001, 0 } };

/* ROM 82A6D4; VRAM 8034AF64. */
PokemonAnimationSetup D_8034AF64_82A6D4 = { &D_8034AED0_82A640, func_80348970_8280E0, 0, { 0, 0, 0 }, NULL, NULL };

/* ROM 82A6E8; VRAM 8034AF78. */
PokemonInitData D_8034AF78_82A6E8 = { gate_model, gate_materials, renderModelTypeDFogged, &D_8034AF64_82A6D4, { 10.0f, 10.0f, 10.0f }, { 0.0f, 0.0f, 0.0f }, 0.00999999978f, 0, 0, 0, 0, { 0, 0, 0 } };

/* ROM 82A71C; VRAM 8034AFAC. */
PokemonDef D_8034AFAC_82A71C = { 1001, func_80348FB8_828728, pokemonChangeBlock, pokemonRemoveOne };

/* Original zero-filled inter-record alignment/storage (4 bytes). */
char D_8034AFBC_82A72C_padding[4] = "";

/* ROM 82A730; VRAM 8034AFC0. */
s32 D_8034AFC0_82A730[1] = { 349 };

/* ROM 82A734; VRAM 8034AFC4. */
s32 D_8034AFC4_82A734[1] = { 351 };

/* ROM 82A738; VRAM 8034AFC8. */
s32 D_8034AFC8_82A738[2] = { 350, 147 };

/* ROM 82A740; VRAM 8034AFD0. */
s32 D_8034AFD0_82A740[1] = { 349 };

/* ROM 82A744; VRAM 8034AFD4. */
s32 D_8034AFD4_82A744[1] = { 351 };

/* ROM 82A748; VRAM 8034AFD8. */
s32 D_8034AFD8_82A748[2] = { 352, 145 };

/* ROM 82A750; VRAM 8034AFE0. */
AnimationHeader D_8034AFE0_82A750 = { 0.5f, 70.0f, D_8012EFF0_4E13C0, D_80139690_4EBA60, NULL };

/* ROM 82A764; VRAM 8034AFF4. */
AnimationHeader D_8034AFF4_82A764 = { 0.649999976f, 135.0f, D_801368F0_4E8CC0, D_80139B00_4EBED0, D_8034AFC0_82A730 };

/* ROM 82A778; VRAM 8034B008. */
AnimationHeader D_8034B008_82A778 = { 0.800000012f, 140.0f, D_801358A0_4E7C70, D_80139A00_4EBDD0, D_8034AFC4_82A734 };

/* ROM 82A78C; VRAM 8034B01C. */
AnimationHeader D_8034B01C_82A78C = { 0.600000024f, 110.0f, D_80133040_4E5410, D_80139900_4EBCD0, D_8034AFC8_82A738 };

/* ROM 82A7A0; VRAM 8034B030. */
AnimationHeader D_8034B030_82A7A0 = { 0.5f, 40.0f, D_8012C9E0_4DEDB0, D_801394D0_4EB8A0, NULL };

/* ROM 82A7B4; VRAM 8034B044. */
AnimationHeader D_8034B044_82A7B4 = { 0.5f, 80.0f, D_8012D700_4DFAD0, D_801395A0_4EB970, D_8034AFD0_82A740 };

/* ROM 82A7C8; VRAM 8034B058. */
AnimationHeader D_8034B058_82A7C8 = { 0.5f, 90.0f, D_80131D30_4E4100, D_80139840_4EBC10, D_8034AFD4_82A744 };

/* ROM 82A7DC; VRAM 8034B06C. */
AnimationHeader D_8034B06C_82A7DC = { 0.75f, 200.0f, D_8012FB60_4E1F30, D_80139770_4EBB40, D_8034AFD8_82A748 };

/* ROM 82A7F0; VRAM 8034B080. */
s32 D_8034B080_82A7F0[2] = { 0, 148 };

/* ROM 82A7F8; VRAM 8034B088. */
s32 D_8034B088_82A7F8[2] = { 0, 155 };

/* ROM 82A800; VRAM 8034B090. */
s32 D_8034B090_82A800[2] = { 0, 154 };

/* ROM 82A808; VRAM 8034B098. */
AnimationHeader D_8034B098_82A808 = { 0.5f, 10.0f, D_80117980_4C9D50, D_801179C0_4C9D90, NULL };

/* ROM 82A81C; VRAM 8034B0AC. */
AnimationHeader D_8034B0AC_82A81C = { 0.600000024f, 110.0f, D_80117B20_4C9EF0, D_80117B60_4C9F30, D_8034B088_82A7F8 };

/* ROM 82A830; VRAM 8034B0C0. */
AnimationHeader D_8034B0C0_82A830 = { 0.800000012f, 140.0f, D_80117DC0_4CA190, D_80117DF0_4CA1C0, NULL };

/* ROM 82A844; VRAM 8034B0D4. */
AnimationHeader D_8034B0D4_82A844 = { 0.5f, 40.0f, D_801176D0_4C9AA0, D_80117730_4C9B00, NULL };

/* ROM 82A858; VRAM 8034B0E8. */
AnimationHeader D_8034B0E8_82A858 = { 0.600000024f, 25.0f, D_80117410_4C97E0, D_80117480_4C9850, D_8034B080_82A7F0 };

/* ROM 82A86C; VRAM 8034B0FC. */
AnimationHeader D_8034B0FC_82A86C = { 0.5f, 10.0f, D_80117210_4C95E0, D_80117260_4C9630, D_8034B090_82A800 };

/* ROM 82A880; VRAM 8034B110. */
AnimationHeader D_8034B110_82A880 = { 0.5f, 10.0f, D_80117A50_4C9E20, D_80117A90_4C9E60, NULL };

/* ROM 82A894; VRAM 8034B124. */
AnimationHeader D_8034B124_82A894 = { 0.600000024f, 110.0f, D_80117C70_4CA040, D_80117CB0_4CA080, D_8034B088_82A7F8 };

/* ROM 82A8A8; VRAM 8034B138. */
AnimationHeader D_8034B138_82A8A8 = { 0.800000012f, 140.0f, D_80117F10_4CA2E0, D_80117F40_4CA310, NULL };

/* ROM 82A8BC; VRAM 8034B14C. */
AnimationHeader D_8034B14C_82A8BC = { 0.5f, 40.0f, D_80117840_4C9C10, D_801178A0_4C9C70, NULL };

/* ROM 82A8D0; VRAM 8034B160. */
AnimationHeader D_8034B160_82A8D0 = { 0.600000024f, 25.0f, D_80117570_4C9940, D_801175E0_4C99B0, D_8034B080_82A7F0 };

/* ROM 82A8E4; VRAM 8034B174. */
AnimationHeader D_8034B174_82A8E4 = { 0.5f, 10.0f, D_80117310_4C96E0, D_80117360_4C9730, D_8034B090_82A800 };

/* ROM 82A8F8; VRAM 8034B188. */
InteractionHandler D_8034B188_82A8F8[2] = {
    { 30, func_8034935C_828ACC, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 82A918; VRAM 8034B1A8. */
InteractionHandler D_8034B1A8_82A918[6] = {
    { 9, NULL, 0.0f, func_80349DB0_829520 },
    { 13, NULL, 0.0f, func_80349DE8_829558 },
    { 28, func_80349480_828BF0, 0.0f, NULL },
    { 29, func_8034956C_828CDC, 0.0f, NULL },
    { 32, func_803496BC_828E2C, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 82A978; VRAM 8034B208. */
InteractionHandler D_8034B208_82A978[3] = {
    { 31, func_8034930C_828A7C, 0.0f, NULL },
    { 32, func_80349514_828C84, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 82A9A8; VRAM 8034B238. */
InteractionHandler D_8034B238_82A9A8[3] = {
    { 31, func_8034930C_828A7C, 0.0f, NULL },
    { 33, func_80349480_828BF0, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 82A9D8; VRAM 8034B268. */
InteractionHandler D_8034B268_82A9D8[3] = {
    { 31, func_80349654_828DC4, 0.0f, NULL },
    { 32, func_803495FC_828D6C, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 82AA08; VRAM 8034B298. */
InteractionHandler D_8034B298_82AA08[3] = {
    { 31, func_80349654_828DC4, 0.0f, NULL },
    { 33, func_8034956C_828CDC, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 82AA38; VRAM 8034B2C8. */
InteractionHandler D_8034B2C8_82AA38[6] = {
    { 9, NULL, 0.0f, func_80349DB0_829520 },
    { 13, NULL, 0.0f, func_80349DE8_829558 },
    { 28, func_80349480_828BF0, 0.0f, NULL },
    { 29, func_8034956C_828CDC, 0.0f, NULL },
    { 33, func_803493F4_828B64, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 82AA98; VRAM 8034B328. */
InteractionHandler D_8034B328_82AA98[2] = {
    { 30, func_8034977C_828EEC, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 82AAB8; VRAM 8034B348. */
InteractionHandler D_8034B348_82AAB8[7] = {
    { 9, NULL, 0.0f, func_80349DB0_829520 },
    { 13, NULL, 0.0f, func_80349DE8_829558 },
    { 31, func_80349714_828E84, 0.0f, NULL },
    { 28, func_803498A0_829010, 0.0f, NULL },
    { 29, func_8034998C_8290FC, 0.0f, NULL },
    { 32, func_80349ADC_82924C, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 82AB28; VRAM 8034B3B8. */
InteractionHandler D_8034B3B8_82AB28[3] = {
    { 31, func_80349714_828E84, 0.0f, NULL },
    { 32, func_80349934_8290A4, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 82AB58; VRAM 8034B3E8. */
InteractionHandler D_8034B3E8_82AB58[3] = {
    { 31, func_80349714_828E84, 0.0f, NULL },
    { 33, func_803498A0_829010, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 82AB88; VRAM 8034B418. */
InteractionHandler D_8034B418_82AB88[3] = {
    { 31, func_80349A74_8291E4, 0.0f, NULL },
    { 32, func_80349A1C_82918C, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 82ABB8; VRAM 8034B448. */
InteractionHandler D_8034B448_82ABB8[3] = {
    { 31, func_80349A74_8291E4, 0.0f, NULL },
    { 33, func_8034998C_8290FC, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 82ABE8; VRAM 8034B478. */
InteractionHandler D_8034B478_82ABE8[7] = {
    { 9, NULL, 0.0f, func_80349DB0_829520 },
    { 13, NULL, 0.0f, func_80349DE8_829558 },
    { 31, func_80349714_828E84, 0.0f, NULL },
    { 28, func_803498A0_829010, 0.0f, NULL },
    { 29, func_8034998C_8290FC, 0.0f, NULL },
    { 33, func_80349814_828F84, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 82AC58; VRAM 8034B4E8. */
InteractionHandler D_8034B4E8_82AC58[4] = {
    { 30, func_80349B98_829308, 0.0f, NULL },
    { 31, func_80349B34_8292A4, 0.0f, NULL },
    { 34, func_80349714_828E84, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 82AC98; VRAM 8034B528. */
Vec3f D_8034B528_82AC98 = { 0.0f, 0.0f, 0.0f };

/* ROM 82ACA4; VRAM 8034B534. */
Vec3f D_8034B534_82ACA4 = { 0.0f, 0.0f, 0.0f };

/* ROM 82ACB0; VRAM 8034B540. */
PokemonAnimationSetup D_8034B540_82ACB0 = { &D_8034B098_82A808, func_80349180_8288F0, 0, { 0, 0, 0 }, NULL, NULL };

/* ROM 82ACC4; VRAM 8034B554. */
PokemonInitData D_8034B554_82ACC4 = { D_80116EF0_4C92C0, D_80116CF0_4C90C0, renderModelTypeDFogged, &D_8034B540_82ACB0, { 2.0f, 2.0f, 2.0f }, { 0.0f, 0.0f, 0.0f }, 36.0f, 0, 0, 0, 0, { 0, 0, 0 } };

/* Original zero-filled inter-record alignment/storage (8 bytes). */
char D_8034B588_82ACF8_padding[8] = "";

/* ROM 82AD00; VRAM 8034B590. */
AnimationHeader D_8034B590_82AD00 = { 0.5f, 60.0f, evolution_controller_modelanim, evolution_controller_matanim, NULL };

/* ROM 82AD14; VRAM 8034B5A4. */
PokemonAnimationSetup D_8034B5A4_82AD14 = { &D_8034B590_82AD00, func_80349F00_829670, 0, { 0, 0, 0 }, NULL, NULL };

/* ROM 82AD28; VRAM 8034B5B8. */
PokemonInitData D_8034B5B8_82AD28 = { evolution_controller_model, evolution_controller_materials, renderPokemonModelTypeDFogged, &D_8034B5A4_82AD14, { 10.0f, 10.0f, 10.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f, 0, 0, 0, 0, { 0, 0, 0 } };

/* ROM 82AD5C; VRAM 8034B5EC. */
PokemonDef D_8034B5EC_82AD5C = { 1002, func_8034A064_8297D4, pokemonChangeBlock, pokemonRemoveOne };

/* Original zero-filled inter-record alignment/storage (4 bytes). */
char D_8034B5FC_82AD6C_padding[4] = "";

/* ROM 82AD70; VRAM 8034B600. */
AnimationHeader D_8034B600_82AD70 = { 0.100000001f, 50.0f, D_80118360_4CA730, D_80118390_4CA760, NULL };

/* ROM 82AD84; VRAM 8034B614. */
InteractionHandler D_8034B614_82AD84[1] = {
    { 58, NULL, 0.0f, NULL },
};

/* ROM 82AD94; VRAM 8034B624. */
PokemonAnimationSetup D_8034B624_82AD94 = { &D_8034B600_82AD70, func_8034A190_829900, 0, { 0, 0, 0 }, NULL, NULL };

/* ROM 82ADA8; VRAM 8034B638. */
PokemonInitData D_8034B638_82ADA8 = { D_80118210_4CA5E0, D_80118160_4CA530, renderModelTypeDFogged, &D_8034B624_82AD94, { 2.0f, 2.0f, 2.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f, 0, 0, 0, 0, { 0, 0, 0 } };

/* Original zero-filled inter-record alignment/storage (4 bytes). */
char D_8034B66C_82ADDC_padding[4] = "";

/* ROM 82ADE0; VRAM 8034B670. */
s32 D_8034B670_82ADE0 = 0;

/* ROM 82ADE4; VRAM 8034B674. */
GObj* D_8034B674_82ADE4 = NULL;

/* Original zero-filled trailing alignment/storage (8 bytes). */
char D_8034B678_82ADE8_padding[8] = "";
