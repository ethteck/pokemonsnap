#include "../tunnel.h"
#include "5EC3E0_types.h"

extern AnimCmd* D_800FAE40_78260[];
extern AnimCmd* D_800FBF50_79370[];
extern AnimCmd* D_800FD080_7A4A0[];
extern AnimCmd* D_800FDC70_7B090[];
extern AnimCmd* D_8011C2E0_99700[];
extern UnkEC64Arg3 D_80132F30_179090[];
extern Texture** D_80133250_1793B0[];
extern AnimCmd* D_80133740_1798A0[];
extern AnimCmd** D_801338B0_179A10[];
extern AnimCmd* D_80134090_17A1F0[];
extern AnimCmd** D_80134150_17A2B0[];
extern UnkEC64Arg3 D_801382E0_17E440[];
extern Texture** D_80138630_17E790[];
extern AnimCmd* D_80138810_17E970[];
extern AnimCmd** D_80138870_17E9D0[];
extern AnimCmd* D_80138930_17EA90[];
extern AnimCmd** D_80138990_17EAF0[];
extern UnkEC64Arg3 D_80138DF0_17EF50[];
extern AnimCmd* D_80138ED0_17F030[];
extern AnimCmd* D_80138F20_17F080[];
extern UnkEC64Arg3 D_80139378_17F4D8[];
extern Texture** D_80139400_17F560[];
extern AnimCmd* D_801394A0_17F600[];
extern AnimCmd** D_801394B0_17F610[];
extern AnimCmd* D_80139500_17F660[];
extern AnimCmd** D_80139510_17F670[];
extern UnkEC64Arg3 D_80139968_17FAC8[];
extern Texture** D_801399F0_17FB50[];
extern AnimCmd* D_80139A90_17FBF0[];
extern AnimCmd** D_80139AA0_17FC00[];
extern AnimCmd* D_80139AF0_17FC50[];
extern AnimCmd** D_80139B00_17FC60[];
extern UnkEC64Arg3 D_8013AA00_180B60[];
extern AnimCmd* D_80141A90_187BF0[];
extern AnimCmd* D_8016EAC0_1B4C20[];
extern AnimCmd* D_8016F350_1B54B0[];
extern AnimCmd* D_8016FCF0_1B5E50[];
extern AnimCmd* D_80170740_1B68A0[];
extern AnimCmd* D_80171520_1B7680[];
extern AnimCmd* D_80172FA0_1B9100[];
extern AnimCmd* D_801742D0_1BA430[];
extern AnimCmd* D_80175690_1BB7F0[];
extern AnimCmd* D_80176800_1BC960[];
extern AnimCmd** D_80177710_1BD870[];
extern AnimCmd** D_80177790_1BD8F0[];
extern AnimCmd** D_80177890_1BD9F0[];
extern AnimCmd** D_80177A20_1BDB80[];
extern AnimCmd** D_80177AC0_1BDC20[];
extern AnimCmd* D_80177B50_1BDCB0[];
extern AnimCmd* D_80183EE0_1CA040[];
extern AnimCmd* D_80184920_1CAA80[];
extern AnimCmd* D_80185E70_1CBFD0[];
extern AnimCmd* D_80186530_1CC690[];
extern AnimCmd** D_80186E20_1CCF80[];
extern AnimCmd** D_80186EA0_1CD000[];
extern AnimCmd** D_80186F30_1CD090[];
extern AnimCmd** D_80186FA0_1CD100[];
extern AnimCmd* D_80188820_1CE980[];
extern AnimCmd* D_80188940_1CEAA0[];
extern AnimCmd* D_80188AF0_1CEC50[];
extern AnimCmd* D_80188CB0_1CEE10[];
extern Vtx D_80188D28_1CEE88[340];
extern UnkEC64Arg3 D_8018A640_1D07A0[];
extern Vtx D_8018A6F0_1D0850[340];
extern Struct_800AB050 D_803431F0_6402C0[336];
extern Texture** electabuzz_materials[];
extern UnkEC64Arg3 electabuzz_model[];
extern void func_802E93D0_5E64A0(GObj*);
extern void func_802E944C_5E651C(GObj*);
extern void func_802E9538_5E6608(GObj*);
extern void func_802E95E8_5E66B8(GObj*);
extern void func_802E96E8_5E67B8(GObj*);
extern void func_802E97EC_5E68BC(GObj*);
extern void func_802E9854_5E6924(GObj*);
extern void func_802E98F4_5E69C4(GObj*);
extern void func_802E9AF8_5E6BC8(GObj*);
extern void func_802E9DD8_5E6EA8(GObj*);
extern void func_802E9E54_5E6F24(GObj*);
extern void func_802E9F20_5E6FF0(GObj*);
extern void func_802EA108_5E71D8(GObj*);
extern void func_802EA1B4_5E7284(GObj*);
extern void func_802EA3EC_5E74BC(GObj*);
extern void func_802EA53C_5E760C(GObj*);
extern void func_802EA5D0_5E76A0(GObj*);
extern void func_802EA730_5E7800(GObj*);
extern void func_802EAFB0_5E8080(GObj*);
extern void func_802EB35C_5E842C(GObj*);
extern void func_802EB3E0_5E84B0(GObj*);
extern void func_802EB430_5E8500(GObj*);
extern void func_802EB7AC_5E887C(GObj*);
extern void func_802EB7E4_5E88B4(GObj*);
extern void func_802EB860_5E8930(GObj*);
extern void func_802EB908_5E89D8(GObj*);
extern void func_802EBB28_5E8BF8(GObj*);
extern void func_802EBBE0_5E8CB0(GObj*);
extern void func_802EBD20_5E8DF0(GObj*);
extern void func_802EBDBC_5E8E8C(GObj*);
extern void func_802EBF40_5E9010(GObj*);
extern void func_802EBFDC_5E90AC(GObj*);
extern void func_802EC040_5E9110(GObj*);
extern void func_802EC400_5E94D0(GObj*);
extern void func_802EC5B0_5E9680(GObj*);
extern void func_802EC760_5E9830(GObj*);
extern void func_802EC910_5E99E0(GObj*);
extern void func_802ECAC0_5E9B90(GObj*);
extern void func_802ECB3C_5E9C0C(GObj*);
extern void func_802ED620_5EA6F0(GObj*);
extern void func_802EDB3C_5EAC0C(GObj* obj);
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
extern UnkEC64Arg3 haunter_model[];
extern UnkEC64Arg3 magikarp_model[];
extern void renderModelTypeBFogged(GObj*);
extern void renderModelTypeDFogged(GObj*);
extern void renderPokemonModelTypeBFogged(GObj*);
extern void renderPokemonModelTypeDFogged(GObj*);
extern void renderPokemonModelTypeIFogged(GObj*);
extern void renderPokemonModelTypeJFogged(GObj*);
extern Texture** zapdos_materials[];
extern UnkEC64Arg3 zapdos_model[];
extern UnkEC64Arg3 zubat_model[];
extern s32 D_802EF310_5EC3E0[10];
extern AnimationHeader D_802EF338_5EC408;
extern AnimationHeader D_802EF34C_5EC41C;
extern AnimationHeader D_802EF360_5EC430;
extern AnimationHeader D_802EF374_5EC444;
extern AnimationHeader D_802EF388_5EC458;
extern AnimationHeader D_802EF39C_5EC46C;
extern AnimationHeader D_802EF3B0_5EC480;
extern AnimationHeader D_802EF3C4_5EC494;
extern AnimationHeader D_802EF3D8_5EC4A8;
extern InteractionHandler D_802EF3EC_5EC4BC[6];
extern RandomState D_802EF44C_5EC51C[3];
extern InteractionHandler D_802EF464_5EC534[2];
extern GObj* D_802EF484_5EC554;
extern GObj* D_802EF488_5EC558;
extern InteractionHandler D_802EF48C_5EC55C[6];
extern InteractionHandler D_802EF4EC_5EC5BC[3];
extern InteractionHandler D_802EF51C_5EC5EC[3];
extern InteractionHandler D_802EF54C_5EC61C[5];
extern InteractionHandler D_802EF59C_5EC66C[3];
extern InteractionHandler D_802EF5CC_5EC69C[5];
extern InteractionHandler D_802EF61C_5EC6EC[3];
extern InteractionHandler D_802EF64C_5EC71C[4];
extern InteractionHandler D_802EF68C_5EC75C[2];
extern s32 D_802EF6AC_5EC77C;
extern InteractionHandler D_802EF6B0_5EC780[5];
extern PokemonAnimationSetup D_802EF700_5EC7D0;
extern PokemonInitData D_802EF714_5EC7E4;
extern AnimationHeader D_802EF750_5EC820;
extern AnimationHeader D_802EF764_5EC834;
extern InteractionHandler D_802EF778_5EC848[1];
extern InteractionHandler2 D_802EF788_5EC858;
extern PokemonAnimationSetup D_802EF7A8_5EC878;
extern PokemonInitData D_802EF7BC_5EC88C;
extern HitBoxType4 D_802EF7F0_5EC8C0;
extern HitBoxType1 D_802EF880_5EC950;
extern Collider D_802EF908_5EC9D8[5];
extern CollisionModel D_802EF9E4_5ECAB4;
extern int D_802EF9F0_5ECAC0;
extern GObj* D_802EF9F4_5ECAC4[1];
extern s32 D_802EF9F8_5ECAC8[8];
extern AnimationHeader D_802EFA18_5ECAE8;
extern AnimationHeader D_802EFA2C_5ECAFC;
extern AnimationHeader D_802EFA40_5ECB10;
extern PokemonAnimationSetup D_802EFA54_5ECB24;
extern PokemonInitData D_802EFA68_5ECB38;
extern AnimationHeader D_802EFAA0_5ECB70;
extern AnimationHeader D_802EFAB4_5ECB84;
extern InteractionHandler2 D_802EFAC8_5ECB98;
extern PokemonAnimationSetup D_802EFAE8_5ECBB8;
extern PokemonInitData D_802EFAFC_5ECBCC;
extern s32 D_802EFB30_5ECC00[9];
extern AnimationHeader D_802EFB54_5ECC24;
extern AnimationHeader D_802EFB68_5ECC38;
extern AnimationHeader D_802EFB7C_5ECC4C;
extern AnimationHeader D_802EFB90_5ECC60;
extern GObj* D_802EFBA4_5ECC74;
extern InteractionHandler D_802EFBA8_5ECC78[2];
extern InteractionHandler D_802EFBC8_5ECC98[3];
extern PokemonAnimationSetup D_802EFBF8_5ECCC8;
extern PokemonInitData D_802EFC0C_5ECCDC;
extern s32 D_802EFC40_5ECD10[2];
extern AnimationHeader D_802EFC48_5ECD18;
extern InteractionHandler D_802EFC5C_5ECD2C[2];
extern InteractionHandler D_802EFC7C_5ECD4C[3];
extern InteractionHandler D_802EFCAC_5ECD7C[2];
extern InteractionHandler D_802EFCCC_5ECD9C[3];
extern PokemonAnimationSetup D_802EFCFC_5ECDCC;
extern PokemonInitData D_802EFD10_5ECDE0;
extern s32 D_802EFD44_5ECE14[5];
extern AnimationHeader D_802EFD58_5ECE28;
extern InteractionHandler D_802EFD6C_5ECE3C[1];
extern PokemonAnimationSetup D_802EFD7C_5ECE4C;
extern PokemonInitData D_802EFD90_5ECE60;
extern s32 D_802EFDC4_5ECE94[13];
extern AnimationHeader D_802EFDF8_5ECEC8;
extern AnimationHeader D_802EFE0C_5ECEDC;
extern AnimationHeader D_802EFE20_5ECEF0;
extern AnimationHeader D_802EFE34_5ECF04;
extern InteractionHandler D_802EFE48_5ECF18[2];
extern PokemonAnimationSetup D_802EFE68_5ECF38;
extern PokemonInitData D_802EFE7C_5ECF4C;
extern s32 D_802EFEB0_5ECF80[3];
extern AnimationHeader D_802EFEBC_5ECF8C;
extern AnimationHeader D_802EFED0_5ECFA0;
extern AnimationHeader D_802EFEE4_5ECFB4;
extern AnimationHeader D_802EFEF8_5ECFC8;
extern Struct_800AB050* D_802EFF0C_5ECFDC[2];
extern EggStruct D_802EFF14_5ECFE4;
extern GObj* D_802EFF28_5ECFF8;
extern InteractionHandler D_802EFF2C_5ECFFC[2];
extern InteractionHandler2 D_802EFF4C_5ED01C;
extern TunnelEggBursts D_802EFF6C_5ED03C;
extern PokemonAnimationSetup D_802EFF80_5ED050;
extern PokemonInitData D_802EFF94_5ED064;
extern GObj* D_802EFFD0_5ED0A0;
extern AnimationHeader D_802EFFD4_5ED0A4;
extern AnimationHeader D_802EFFE8_5ED0B8;
extern InteractionHandler2 D_802EFFFC_5ED0CC;
extern PokemonAnimationSetup D_802F001C_5ED0EC;
extern PokemonInitData D_802F0030_5ED100;
extern GObj* D_802F0070_5ED140;
extern AnimationHeader D_802F0074_5ED144;
extern AnimationHeader D_802F0088_5ED158;
extern InteractionHandler2 D_802F009C_5ED16C;
extern PokemonAnimationSetup D_802F00BC_5ED18C;
extern PokemonInitData D_802F00D0_5ED1A0;
extern AnimationHeader D_802F0110_5ED1E0;
extern AnimationHeader D_802F0124_5ED1F4;
extern AnimationHeader D_802F0138_5ED208;
extern AnimationHeader D_802F014C_5ED21C;
extern s32 D_802F0160_5ED230;
extern bool D_802F0164_5ED234;
extern InteractionHandler D_802F0168_5ED238[2];
extern TunnelGateAngles D_802F0188_5ED258;
extern PokemonAnimationSetup D_802F018C_5ED25C;
extern PokemonInitData D_802F01A0_5ED270;
extern bool D_802F01E0_5ED2B0;
extern GObj* D_802F01E4_5ED2B4;
extern AnimationHeader D_802F01F0_5ED2C0;
extern f32 D_802F0204_5ED2D4[3];
extern GObj* D_802F0210_5ED2E0;
extern OMCamera* D_802F0214_5ED2E4;
extern s32 D_802F0218_5ED2E8;
extern s32 D_802F021C_5ED2EC;
extern f32 D_802F0220_5ED2F0;
extern f32 D_802F0224_5ED2F4;
extern InteractionHandler D_802F0228_5ED2F8[2];
extern PokemonAnimationSetup D_802F0248_5ED318;
extern PokemonInitData D_802F025C_5ED32C;

s32 D_802EF310_5EC3E0[10] = { 0, 105, 207, 204, 209, 205, 393, 104, 206, 208 };

AnimationHeader D_802EF338_5EC408 = { 0.699999988f, 28.0f, D_8016FCF0_1B5E50, NULL, NULL };

AnimationHeader D_802EF34C_5EC41C = { 0.400000006f, 23.0f, D_8016EAC0_1B4C20, NULL, NULL };

AnimationHeader D_802EF360_5EC430 = { 0.550000012f, 23.0f, D_8016F350_1B54B0, NULL, D_802EF310_5EC3E0 };

AnimationHeader D_802EF374_5EC444 = { 0.300000012f, 64.0f, D_801742D0_1BA430, D_80177A20_1BDB80, &D_802EF310_5EC3E0[2] };

AnimationHeader D_802EF388_5EC458 = { 0.300000012f, 49.0f, D_80175690_1BB7F0, NULL, &D_802EF310_5EC3E0[3] };

AnimationHeader D_802EF39C_5EC46C = { 0.349999994f, 32.0f, D_80172FA0_1B9100, D_80177890_1BD9F0, &D_802EF310_5EC3E0[5] };

AnimationHeader D_802EF3B0_5EC480 = { 1.0f, 75.0f, D_80176800_1BC960, D_80177AC0_1BDC20, &D_802EF310_5EC3E0[8] };

AnimationHeader D_802EF3C4_5EC494 = { 1.0f, 100.0f, D_80170740_1B68A0, D_80177710_1BD870, NULL };

AnimationHeader D_802EF3D8_5EC4A8 = { 1.0f, 170.0f, D_80171520_1B7680, D_80177790_1BD8F0, &D_802EF310_5EC3E0[9] };

InteractionHandler D_802EF3EC_5EC4BC[6] = {
    { 9, func_802E96E8_5E67B8, 0.0f, NULL },
    { 13, func_802E97EC_5E68BC, 0.0f, NULL },
    { 10, func_802E9854_5E6924, 0.0f, NULL },
    { 14, func_802E98F4_5E69C4, 0.0f, NULL },
    { 16, func_802E9AF8_5E6BC8, 500.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

RandomState D_802EF44C_5EC51C[3] = {
    { 100, func_802E9538_5E6608 },
    { 100, func_802E95E8_5E66B8 },
    { 0, NULL },
};

InteractionHandler D_802EF464_5EC534[2] = {
    { 52, func_802E944C_5E651C, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

GObj* D_802EF484_5EC554 = NULL;

GObj* D_802EF488_5EC558 = NULL;

InteractionHandler D_802EF48C_5EC55C[6] = {
    { 9, func_802E96E8_5E67B8, 0.0f, NULL },
    { 13, func_802E97EC_5E68BC, 0.0f, NULL },
    { 10, func_802E9854_5E6924, 0.0f, NULL },
    { 14, func_802E98F4_5E69C4, 0.0f, NULL },
    { 15, func_802E98F4_5E69C4, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

InteractionHandler D_802EF4EC_5EC5BC[3] = {
    { 9, func_802E96E8_5E67B8, 0.0f, NULL },
    { 13, func_802E97EC_5E68BC, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

InteractionHandler D_802EF51C_5EC5EC[3] = {
    { 9, func_802E96E8_5E67B8, 0.0f, NULL },
    { 13, func_802E97EC_5E68BC, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

InteractionHandler D_802EF54C_5EC61C[5] = {
    { 9, func_802E96E8_5E67B8, 0.0f, NULL },
    { 13, func_802E97EC_5E68BC, 0.0f, NULL },
    { 10, func_802E9854_5E6924, 0.0f, NULL },
    { 22, func_802E9538_5E6608, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

InteractionHandler D_802EF59C_5EC66C[3] = {
    { 9, func_802E96E8_5E67B8, 0.0f, NULL },
    { 13, func_802E97EC_5E68BC, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

InteractionHandler D_802EF5CC_5EC69C[5] = {
    { 9, func_802E96E8_5E67B8, 0.0f, NULL },
    { 13, func_802E97EC_5E68BC, 0.0f, NULL },
    { 10, func_802E9854_5E6924, 0.0f, NULL },
    { 14, func_802E98F4_5E69C4, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

InteractionHandler D_802EF61C_5EC6EC[3] = {
    { 9, func_802E9E54_5E6F24, 0.0f, NULL },
    { 13, func_802E9F20_5E6FF0, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

InteractionHandler D_802EF64C_5EC71C[4] = {
    { 9, func_802E9E54_5E6F24, 0.0f, NULL },
    { 13, func_802E9F20_5E6FF0, 0.0f, NULL },
    { 37, func_802E9DD8_5E6EA8, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

InteractionHandler D_802EF68C_5EC75C[2] = {
    { 37, func_802E9DD8_5E6EA8, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

s32 D_802EF6AC_5EC77C = 0;

InteractionHandler D_802EF6B0_5EC780[5] = {
    { 9, func_802EA108_5E71D8, 0.0f, NULL },
    { 13, func_802EA1B4_5E7284, 0.0f, NULL },
    { 10, func_802EA1B4_5E7284, 0.0f, NULL },
    { 49, NULL, 0.0f, func_802EA3EC_5E74BC },
    { 58, NULL, 0.0f, NULL },
};

PokemonAnimationSetup D_802EF700_5EC7D0 = { &D_802EF338_5EC408, func_802E93D0_5E64A0, 0, { 0, 0, 0 }, NULL, NULL };

PokemonInitData D_802EF714_5EC7E4 = { electabuzz_model, electabuzz_materials, renderPokemonModelTypeJFogged, &D_802EF700_5EC7D0, { 1.70000005f, 1.70000005f, 1.70000005f }, { 0.0f, 150.0f, 0.0f }, 58.0f, 37, 0, 0, 0, { 0, 0, 0 } };

char D_802EF748_5EC818_padding[8] = "";

AnimationHeader D_802EF750_5EC820 = { 1.0f, 100.0f, D_80133740_1798A0, D_801338B0_179A10, NULL };

AnimationHeader D_802EF764_5EC834 = { 1.0f, 100.0f, D_80134090_17A1F0, D_80134150_17A2B0, NULL };

InteractionHandler D_802EF778_5EC848[1] = {
    { 58, NULL, 0.0f, NULL },
};

InteractionHandler2 D_802EF788_5EC858 = { {
    { 50, func_802EA5D0_5E76A0, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
} };

PokemonAnimationSetup D_802EF7A8_5EC878 = { &D_802EF764_5EC834, func_802EA53C_5E760C, 0, { 0, 0, 0 }, NULL, NULL };

PokemonInitData D_802EF7BC_5EC88C = { D_80132F30_179090, D_80133250_1793B0, renderModelTypeBFogged, &D_802EF7A8_5EC878, { 10.0f, 10.0f, 10.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f, 0, 0, 0, 0, { 0, 0, 0 } };

HitBoxType4 D_802EF7F0_5EC8C0 = {
    4,
    {
        { 0.0f, 0.0f, 0.0f, 0.0f },
        { 0.0f, 0.0f, 0.0f, 0.0f },
        { 0.0f, 0.0f, 0.0f, 0.0f },
        { 0.0f, 0.0f, 0.0f, 0.0f },
    },
    {
        { 0.0f, 0.0f, 0.0f, 0.0f },
        { 0.0f, 0.0f, 0.0f, 0.0f },
        { 0.0f, 0.0f, 0.0f, 0.0f },
        { 0.0f, 0.0f, 0.0f, 0.0f },
    },
    0.5f,
    0.5f,
    0.5f,

};

HitBoxType1 D_802EF880_5EC950 = {
    1,
    {
        { 0.0f, 0.0f, 0.0f, 0.0f },
        { 0.0f, 0.0f, 0.0f, 0.0f },
        { 0.0f, 0.0f, 0.0f, 0.0f },
        { 0.0f, 0.0f, 0.0f, 0.0f },
    },
    {
        { 0.0f, 0.0f, 0.0f, 0.0f },
        { 0.0f, 0.0f, 0.0f, 0.0f },
        { 0.0f, 0.0f, 0.0f, 0.0f },
        { 0.0f, 0.0f, 0.0f, 0.0f },
    },
    1.0f,

};

Collider D_802EF908_5EC9D8[5] = {
    { 0, NULL, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 1.0f, 1.0f, 1.0f } },
    { 1, NULL, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 1.0f, 1.0f, 1.0f } },
    { 2, (HitBox*) &D_802EF7F0_5EC8C0, { 0.0f, 3.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 5.0f, 6.0f, 1.0f } },
    { 1, (HitBox*) &D_802EF880_5EC950, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 3.0f, 3.0f, 3.0f } },
    { 18, NULL, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
};

CollisionModel D_802EF9E4_5ECAB4 = { 1009, D_802EF908_5EC9D8, 1.0f };

int D_802EF9F0_5ECAC0 = 0;

GObj* D_802EF9F4_5ECAC4[1] = { NULL };

s32 D_802EF9F8_5ECAC8[8] = { 0, 0, 0, 51, 49, 0, 51, 50 };

AnimationHeader D_802EFA18_5ECAE8 = { 0.0f, 1.0f, D_80138ED0_17F030, NULL, NULL };

AnimationHeader D_802EFA2C_5ECAFC = { 0.300000012f, 50.0f, D_80138ED0_17F030, NULL, &D_802EF9F8_5ECAC8[2] };

AnimationHeader D_802EFA40_5ECB10 = { 0.300000012f, 50.0f, D_80138F20_17F080, NULL, &D_802EF9F8_5ECAC8[5] };

PokemonAnimationSetup D_802EFA54_5ECB24 = { &D_802EFA18_5ECAE8, func_802EA730_5E7800, 0, { 0, 0, 0 }, NULL, NULL };

PokemonInitData D_802EFA68_5ECB38 = { D_80138DF0_17EF50, NULL, renderModelTypeBFogged, &D_802EFA54_5ECB24, { 10.0f, 10.0f, 10.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f, 0, 0, 0, 0, { 0, 0, 0 } };

char D_802EFA9C_5ECB6C_padding[4] = "";

AnimationHeader D_802EFAA0_5ECB70 = { 1.0f, 100.0f, D_80138810_17E970, D_80138870_17E9D0, NULL };

AnimationHeader D_802EFAB4_5ECB84 = { 1.0f, 100.0f, D_80138930_17EA90, D_80138990_17EAF0, NULL };

InteractionHandler2 D_802EFAC8_5ECB98 = { {
    { 47, func_802EB35C_5E842C, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
} };

PokemonAnimationSetup D_802EFAE8_5ECBB8 = { &D_802EFAB4_5ECB84, func_802EAFB0_5E8080, 0, { 0, 0, 0 }, NULL, NULL };

PokemonInitData D_802EFAFC_5ECBCC = { D_801382E0_17E440, D_80138630_17E790, renderPokemonModelTypeDFogged, &D_802EFAE8_5ECBB8, { 10.0f, 10.0f, 10.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f, 64, 0, 0, 0, { 0, 0, 0 } };

s32 D_802EFB30_5ECC00[9] = { 0, 119, 0, 119, 137, 0, 119, 0, 119 };

AnimationHeader D_802EFB54_5ECC24 = { 1.0f, 30.0f, D_80185E70_1CBFD0, D_80186F30_1CD090, D_802EFB30_5ECC00 };

AnimationHeader D_802EFB68_5ECC38 = { 1.0f, 120.0f, D_80184920_1CAA80, D_80186EA0_1CD000, &D_802EFB30_5ECC00[2] };

AnimationHeader D_802EFB7C_5ECC4C = { 1.0f, 45.0f, D_80186530_1CC690, D_80186FA0_1CD100, &D_802EFB30_5ECC00[5] };

AnimationHeader D_802EFB90_5ECC60 = { 0.5f, 75.0f, D_80183EE0_1CA040, D_80186E20_1CCF80, &D_802EFB30_5ECC00[7] };

GObj* D_802EFBA4_5ECC74 = NULL;

InteractionHandler D_802EFBA8_5ECC78[2] = {
    { 53, func_802EB7AC_5E887C, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

InteractionHandler D_802EFBC8_5ECC98[3] = {
    { 28, func_802EB430_5E8500, 0.0f, NULL },
    { 53, func_802EB7E4_5E88B4, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

PokemonAnimationSetup D_802EFBF8_5ECCC8 = { &D_802EFB54_5ECC24, func_802EB3E0_5E84B0, 0, { 0, 0, 0 }, NULL, NULL };

PokemonInitData D_802EFC0C_5ECCDC = { zapdos_model, zapdos_materials, renderPokemonModelTypeIFogged, &D_802EFBF8_5ECCC8, { 1.5f, 1.5f, 1.5f }, { 0.0f, 0.0f, 0.0f }, 60.0f, 37, 0, 0, 0, { 0, 0, 0 } };

s32 D_802EFC40_5ECD10[2] = { 309, 133 };

AnimationHeader D_802EFC48_5ECD18 = { 2.0f, 64.0f, D_8011C2E0_99700, NULL, D_802EFC40_5ECD10 };

InteractionHandler D_802EFC5C_5ECD2C[2] = {
    { 16, func_802EB908_5E89D8, 1500.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

InteractionHandler D_802EFC7C_5ECD4C[3] = {
    { 9, NULL, 0.0f, func_802EBB28_5E8BF8 },
    { 13, NULL, 0.0f, func_802EBB28_5E8BF8 },
    { 58, NULL, 0.0f, NULL },
};

InteractionHandler D_802EFCAC_5ECD7C[2] = {
    { 37, func_802EB908_5E89D8, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

InteractionHandler D_802EFCCC_5ECD9C[3] = {
    { 9, NULL, 0.0f, func_802EBB28_5E8BF8 },
    { 13, NULL, 0.0f, func_802EBB28_5E8BF8 },
    { 58, NULL, 0.0f, NULL },
};

PokemonAnimationSetup D_802EFCFC_5ECDCC = { &D_802EFC48_5ECD18, func_802EB860_5E8930, 0, { 0, 0, 0 }, NULL, NULL };

PokemonInitData D_802EFD10_5ECDE0 = { zubat_model, NULL, renderPokemonModelTypeIFogged, &D_802EFCFC_5ECDCC, { 2.20000005f, 2.20000005f, 2.20000005f }, { 0.0f, 42.0f, 0.0f }, 33.0f, 37, 0, 0, 0, { 0, 0, 0 } };

s32 D_802EFD44_5ECE14[5] = { 0, 0, 0, 0, 151 };

AnimationHeader D_802EFD58_5ECE28 = { 0.5f, 74.0f, D_80177B50_1BDCB0, NULL, &D_802EFD44_5ECE14[3] };

InteractionHandler D_802EFD6C_5ECE3C[1] = {
    { 58, NULL, 0.0f, NULL },
};

PokemonAnimationSetup D_802EFD7C_5ECE4C = { &D_802EFD58_5ECE28, func_802EBBE0_5E8CB0, 0, { 0, 0, 0 }, NULL, NULL };

PokemonInitData D_802EFD90_5ECE60 = { haunter_model, NULL, renderPokemonModelTypeBFogged, &D_802EFD7C_5ECE4C, { 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f, 37, 0, 0, 0, { 0, 0, 0 } };

s32 D_802EFDC4_5ECE94[13] = { 0, 0, 0, 211, 210, 376, 114, 211, 376, 114, 0, 376, 114 };

AnimationHeader D_802EFDF8_5ECEC8 = { 0.5f, 60.0f, D_800FDC70_7B090, NULL, &D_802EFDC4_5ECE94[3] };

AnimationHeader D_802EFE0C_5ECEDC = { 0.5f, 65.0f, D_800FAE40_78260, NULL, &D_802EFDC4_5ECE94[4] };

AnimationHeader D_802EFE20_5ECEF0 = { 0.5f, 59.0f, D_800FBF50_79370, NULL, &D_802EFDC4_5ECE94[7] };

AnimationHeader D_802EFE34_5ECF04 = { 0.5f, 50.0f, D_800FD080_7A4A0, NULL, &D_802EFDC4_5ECE94[10] };

InteractionHandler D_802EFE48_5ECF18[2] = {
    { 16, func_802EBDBC_5E8E8C, 500.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

PokemonAnimationSetup D_802EFE68_5ECF38 = { &D_802EFE0C_5ECEDC, func_802EBD20_5E8DF0, 0, { 0, 0, 0 }, NULL, NULL };

PokemonInitData D_802EFE7C_5ECF4C = { magikarp_model, NULL, renderPokemonModelTypeBFogged, &D_802EFE68_5ECF38, { 1.60000002f, 1.60000002f, 1.60000002f }, { 0.0f, -40.0f, -11.0f }, 35.0f, 37, 0, 0, 0, { 0, 0, 0 } };

s32 D_802EFEB0_5ECF80[3] = { 0, 134, 139 };

AnimationHeader D_802EFEBC_5ECF8C = { 0.5f, 60.0f, D_80188820_1CE980, NULL, NULL };

AnimationHeader D_802EFED0_5ECFA0 = { 0.800000012f, 60.0f, D_80188940_1CEAA0, NULL, NULL };

AnimationHeader D_802EFEE4_5ECFB4 = { 1.0f, 60.0f, D_80188CB0_1CEE10, NULL, D_802EFEB0_5ECF80 };

AnimationHeader D_802EFEF8_5ECFC8 = { 0.800000012f, 60.0f, D_80188AF0_1CEC50, NULL, NULL };

Struct_800AB050* D_802EFF0C_5ECFDC[2] = { D_803431F0_6402C0, (Struct_800AB050*) D_8018A6F0_1D0850 };

EggStruct D_802EFF14_5ECFE4 = { (Struct_800AB050*) D_80188D28_1CEE88, D_802EFF0C_5ECFDC, 336, 2, 0.0f };

GObj* D_802EFF28_5ECFF8 = NULL;

InteractionHandler D_802EFF2C_5ECFFC[2] = {
    { 41, func_802EC040_5E9110, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

InteractionHandler2 D_802EFF4C_5ED01C = { {
    { 50, func_802EBFDC_5E90AC, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
} };

TunnelEggBursts D_802EFF6C_5ED03C = { { 30, 40, 40, 40, 40 } };

PokemonAnimationSetup D_802EFF80_5ED050 = { &D_802EFEBC_5ECF8C, func_802EBF40_5E9010, 0, { 0, 0, 0 }, NULL, NULL };

PokemonInitData D_802EFF94_5ED064 = { D_8018A640_1D07A0, NULL, renderPokemonModelTypeDFogged, &D_802EFF80_5ED050, { 2.0f, 2.0f, 2.0f }, { 0.0f, 200.0f, 0.0f }, 50.0f, 37, 0, 0, 0, { 0, 0, 0 } };

char D_802EFFC8_5ED098_padding[8] = "";

GObj* D_802EFFD0_5ED0A0 = NULL;

AnimationHeader D_802EFFD4_5ED0A4 = { 1.0f, 100.0f, D_80139500_17F660, D_80139510_17F670, NULL };

AnimationHeader D_802EFFE8_5ED0B8 = { 1.0f, 100.0f, D_801394A0_17F600, D_801394B0_17F610, NULL };

InteractionHandler2 D_802EFFFC_5ED0CC = { {
    { 48, func_802EC5B0_5E9680, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
} };

PokemonAnimationSetup D_802F001C_5ED0EC = { &D_802EFFD4_5ED0A4, func_802EC400_5E94D0, 0, { 0, 0, 0 }, NULL, NULL };

PokemonInitData D_802F0030_5ED100 = { D_80139378_17F4D8, D_80139400_17F560, renderModelTypeDFogged, &D_802F001C_5ED0EC, { 10.0f, 10.0f, 10.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f, 64, 0, 0, 0, { 0, 0, 0 } };

char D_802F0064_5ED134_padding[12] = "";

GObj* D_802F0070_5ED140 = NULL;

AnimationHeader D_802F0074_5ED144 = { 1.0f, 100.0f, D_80139AF0_17FC50, D_80139B00_17FC60, NULL };

AnimationHeader D_802F0088_5ED158 = { 1.0f, 100.0f, D_80139A90_17FBF0, D_80139AA0_17FC00, NULL };

InteractionHandler2 D_802F009C_5ED16C = { {
    { 48, func_802EC910_5E99E0, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
} };

PokemonAnimationSetup D_802F00BC_5ED18C = { &D_802F0074_5ED144, func_802EC760_5E9830, 0, { 0, 0, 0 }, NULL, NULL };

PokemonInitData D_802F00D0_5ED1A0 = { D_80139968_17FAC8, D_801399F0_17FB50, renderModelTypeDFogged, &D_802F00BC_5ED18C, { 10.0f, 10.0f, 10.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f, 64, 0, 0, 0, { 0, 0, 0 } };

char D_802F0104_5ED1D4_padding[12] = "";

AnimationHeader D_802F0110_5ED1E0 = { 1.0f, 100.0f, gate_modelanim_closed, gate_matanim_closed, NULL };

AnimationHeader D_802F0124_5ED1F4 = { 1.0f, 100.0f, gate_modelanim_raise_bar, gate_matanim_raise_bar, NULL };

AnimationHeader D_802F0138_5ED208 = { 1.0f, 100.0f, gate_modelanim_opening, gate_matanim_opening, NULL };

AnimationHeader D_802F014C_5ED21C = { 1.0f, 100.0f, gate_modelanim_opened, gate_matanim_opened, NULL };

s32 D_802F0160_5ED230 = -1;

bool D_802F0164_5ED234 = 0;

InteractionHandler D_802F0168_5ED238[2] = {
    { 16, func_802ECB3C_5E9C0C, 2000.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

TunnelGateAngles D_802F0188_5ED258 = { { 1001, 0 } };

PokemonAnimationSetup D_802F018C_5ED25C = { &D_802F0110_5ED1E0, func_802ECAC0_5E9B90, 0, { 0, 0, 0 }, NULL, NULL };

PokemonInitData D_802F01A0_5ED270 = { gate_model, gate_materials, renderModelTypeDFogged, &D_802F018C_5ED25C, { 10.0f, 10.0f, 10.0f }, { 0.0f, 0.0f, 0.0f }, 0.00999999978f, 0, 0, 0, 0, { 0, 0, 0 } };

char D_802F01D4_5ED2A4_padding[12] = "";

bool D_802F01E0_5ED2B0 = 0;

GObj* D_802F01E4_5ED2B4 = NULL;

char D_802F01E8_5ED2B8_padding[8] = "";

AnimationHeader D_802F01F0_5ED2C0 = { 0.0f, 100.0f, D_80141A90_187BF0, NULL, NULL };

f32 D_802F0204_5ED2D4[3] = { 0.100000001f, 0.5f, 1.0f };

GObj* D_802F0210_5ED2E0 = NULL;

OMCamera* D_802F0214_5ED2E4 = NULL;

s32 D_802F0218_5ED2E8 = 0;

s32 D_802F021C_5ED2EC = -1;

f32 D_802F0220_5ED2F0 = -1.0f;

f32 D_802F0224_5ED2F4 = -1.0f;

InteractionHandler D_802F0228_5ED2F8[2] = {
    { 54, func_802EDB3C_5EAC0C, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

PokemonAnimationSetup D_802F0248_5ED318 = { &D_802F01F0_5ED2C0, func_802ED620_5EA6F0, 0, { 0, 0, 0 }, NULL, NULL };

PokemonInitData D_802F025C_5ED32C = { D_8013AA00_180B60, NULL, renderModelTypeBFogged, &D_802F0248_5ED318, { 10.0f, 10.0f, 10.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f, 0, 0, 0, 0, { 0, 0, 0 } };
