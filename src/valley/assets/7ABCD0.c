#include "valley/valley.h"

typedef struct SomeS16s {
    s16 data[2];
} SomeS16s;

extern AnimCmd* D_800FAE40_78260[];
extern AnimCmd* D_800FBF50_79370[];
extern AnimCmd* D_800FD080_7A4A0[];
extern AnimCmd* D_800FDC70_7B090[];
extern Texture** D_80118780_40EBB0[];
extern UnkEC64Arg3 D_80118820_40EC50[];
extern AnimCmd* D_80118D50_40F180[];
extern AnimCmd* D_80118DD0_40F200[];
extern AnimCmd* D_80118E50_40F280[];
extern AnimCmd** D_80119000_40F430[];
extern Texture** D_80119210_40F640[];
extern UnkEC64Arg3 D_80119330_40F760[];
extern AnimCmd* D_801197F0_40FC20[];
extern AnimCmd** D_80119830_40FC60[];
extern AnimCmd* D_801198F0_40FD20[];
extern AnimCmd** D_80119940_40FD70[];
extern UnkEC64Arg3 D_80119BB0_40FFE0[];
extern AnimCmd* D_80119EE0_410310[];
extern UnkEC64Arg3 D_8011AC50_411080[];
extern AnimCmd* D_8011C490_4128C0[];
extern AnimCmd* D_8012FFD0_426410[];
extern AnimCmd* D_80130A30_426E70[];
extern AnimCmd* D_80131240_427680[];
extern AnimCmd* D_80131990_427DD0[];
extern AnimCmd* D_80132150_428590[];
extern AnimCmd* D_801329B0_428DF0[];
extern AnimCmd* D_80132DF0_429230[];
extern AnimCmd* D_80133800_429C40[];
extern AnimCmd* D_80133AE0_429F20[];
extern AnimCmd** D_80134570_42A9B0[];
extern AnimCmd** D_80134610_42AA50[];
extern AnimCmd** D_801346F0_42AB30[];
extern AnimCmd* D_80137D60_42E1A0[];
extern AnimCmd* D_80139880_42FCC0[];
extern AnimCmd* D_8013A370_4307B0[];
extern AnimCmd* D_8013B150_431590[];
extern AnimCmd* D_8013BEC0_432300[];
extern AnimCmd** D_8013C6B0_432AF0[];
extern AnimCmd** D_8013C7A0_432BE0[];
extern AnimCmd** D_8013C830_432C70[];
extern AnimCmd* D_8013DD40_434180[];
extern AnimCmd* D_8013E410_434850[];
extern AnimCmd* D_8013EAE0_434F20[];
extern AnimCmd** D_8013F550_435990[];
extern AnimCmd** D_8013F5E0_435A20[];
extern AnimCmd* D_80140720_436B60[];
extern AnimCmd* D_80140CE0_437120[];
extern AnimCmd* D_80141060_4374A0[];
extern AnimCmd* D_80141660_437AA0[];
extern AnimCmd* D_80141C70_4380B0[];
extern AnimCmd* D_80141F80_4383C0[];
extern AnimCmd** D_80142560_4389A0[];
extern AnimCmd** D_80142610_438A50[];
extern AnimCmd** D_801426C0_438B00[];
extern AnimCmd** D_80142770_438BB0[];
extern AnimCmd* D_801453E0_43B820[];
extern AnimCmd* D_801462C0_43C700[];
extern AnimCmd* D_801470F0_43D530[];
extern AnimCmd* D_8014ABC0_441000[];
extern AnimCmd* D_8014B280_4416C0[];
extern AnimCmd* D_801529B0_448DF0[];
extern AnimCmd* D_80153490_4498D0[];
extern AnimCmd* D_80154C50_44B090[];
extern AnimCmd* D_80156410_44C850[];
extern AnimCmd* D_80159220_44F660[];
extern AnimCmd** D_80159660_44FAA0[];
extern AnimCmd** D_80159700_44FB40[];
extern AnimCmd** D_801597C0_44FC00[];
extern AnimCmd** D_80159880_44FCC0[];
extern AnimCmd** D_80159940_44FD80[];
extern AnimCmd* D_8015CED0_453310[];
extern AnimCmd* D_8015DA00_453E40[];
extern AnimCmd* D_8015DCE0_454120[];
extern AnimCmd** D_8015E720_454B60[];
extern AnimCmd* D_801638E0_459D20[];
extern AnimCmd* D_80163E80_45A2C0[];
extern AnimCmd* D_80164440_45A880[];
extern AnimCmd* D_80164BB0_45AFF0[];
extern AnimCmd* D_80165100_45B540[];
extern AnimCmd* D_80166600_45CA40[];
extern AnimCmd* D_801672A0_45D6E0[];
extern AnimCmd* D_80167E40_45E280[];
extern AnimCmd* D_80168870_45ECB0[];
extern AnimCmd* D_801690E0_45F520[];
extern AnimCmd** D_80169A60_45FEA0[];
extern AnimCmd** D_80169B00_45FF40[];
extern AnimCmd** D_80169BC0_460000[];
extern AnimCmd** D_80169C20_460060[];
extern AnimCmd** D_80169C90_4600D0[];
extern AnimCmd* D_8016AF90_4613D0[];
extern AnimCmd* D_8016BB80_461FC0[];
extern AnimCmd* D_8016C3F0_462830[];
extern AnimCmd* D_8016C960_462DA0[];
extern AnimCmd* D_8016CD10_463150[];
extern AnimCmd* D_8016D3F0_463830[];
extern AnimCmd* D_8016DF30_464370[];
extern AnimCmd* D_8016EBE0_465020[];
extern AnimCmd* D_8016F230_465670[];
extern AnimCmd* D_8016FC50_466090[];
extern AnimCmd** D_80171420_467860[];
extern AnimCmd** D_801714D0_467910[];
extern AnimCmd** D_80171560_4679A0[];
extern AnimCmd** D_801715F0_467A30[];
extern AnimCmd** D_80171670_467AB0[];
extern AnimCmd** D_80171710_467B50[];
extern AnimCmd** D_801717D0_467C10[];
extern AnimCmd* D_80173810_469C50[];
extern AnimCmd* D_80173E70_46A2B0[];
extern AnimCmd* D_801744D0_46A910[];
extern AnimCmd** D_80174CE0_46B120[];
extern AnimCmd** D_80174DD0_46B210[];
extern AnimCmd** D_80174E40_46B280[];
extern AnimCmd* D_80179C50_470090[];
extern AnimCmd* D_8017A420_470860[];
extern AnimCmd* D_8017AED0_471310[];
extern AnimCmd** D_8017B800_471C40[];
extern AnimCmd** D_8017B8D0_471D10[];
extern AnimCmd** D_8017B980_471DC0[];
extern AnimCmd* D_8017E6C0_474B00[];
extern AnimCmd* D_8017EB60_474FA0[];
extern AnimCmd* D_8017EFF0_475430[];
extern AnimCmd* D_8017F710_475B50[];
extern AnimCmd* D_801803B0_4767F0[];
extern AnimCmd* D_80181510_477950[];
extern AnimCmd* D_801818B0_477CF0[];
extern AnimCmd* D_801821A0_4785E0[];
extern AnimCmd* D_80182400_478840[];
extern AnimCmd* D_80183180_4795C0[];
extern AnimCmd* D_80183AC0_479F00[];
extern AnimCmd* D_80184470_47A8B0[];
extern AnimCmd* D_80185230_47B670[];
extern AnimCmd* D_80185B30_47BF70[];
extern AnimCmd** D_80186440_47C880[];
extern AnimCmd** D_801864B0_47C8F0[];
extern AnimCmd** D_80186540_47C980[];
extern AnimCmd** D_801865D0_47CA10[];
extern AnimCmd** D_801866D0_47CB10[];
extern AnimCmd** D_801867B0_47CBF0[];
extern AnimCmd** D_80186830_47CC70[];
extern AnimCmd** D_801868C0_47CD00[];
extern AnimCmd** D_80186960_47CDA0[];
extern AnimCmd** D_801869E0_47CE20[];
extern AnimCmd** D_80186A80_47CEC0[];
extern char D_802ECE00_7C6390[];
extern char D_802ECE30_7C63C0[];
extern char D_802ECE6C_7C63FC[];
extern char D_802ECEAC_7C643C[];
extern char D_802ECEEC_7C647C[];
extern char D_802ECF30_7C64C0[];
extern char D_802ECF68_7C64F8[];
extern char D_802ECFB4_7C6544[];
extern char D_802ECFF8_7C6588[];
extern char D_802ED040_7C65D0[];
extern char D_802ED08C_7C661C[];
extern char D_802ED0DC_7C666C[];
extern char D_802ED120_7C66B0[];
extern char D_802ED160_7C66F0[];
extern char D_802ED170_7C6700[];
extern Texture** D_8031F9D0_7F8F60[];
extern Texture** D_80323520_7FCAB0[];
extern Texture** D_803272B0_800840[];
extern Texture** D_8032B580_804B10[];
extern Texture** D_80333890_80CE20[];
extern Texture** D_80337D80_811310[];
extern Texture** D_8033A0C0_813650[];
extern Texture** D_8033D3F8_816988[];
extern Texture** D_80341910_81AEA0[];
extern Texture** D_803469D0_81FF60[];
extern Texture** D_80349640_822BD0[];
extern Gfx D_8034C9A0_825F30[];
extern Gfx D_8034D1E0_826770[];
extern Gfx D_8034D300_826890[];
extern Gfx D_8034D420_8269B0[];
extern Gfx D_8034D540_826AD0[];
extern Gfx D_8034D660_826BF0[];
extern Gfx D_8034D780_826D10[];
extern Gfx D_8034D8A0_826E30[];
extern Gfx D_8034D9C0_826F50[];
extern Gfx D_8034DAE0_827070[];
extern Gfx D_8034DC00_827190[];
extern Gfx D_8034DD20_8272B0[];
extern Gfx D_8034DE40_8273D0[];
extern Gfx D_8034DF60_8274F0[];
extern u16 D_803B5000[];
extern u16 D_803DA800[];
extern void contUpdate(void);
extern UnkEC64Arg3 dragonite_model[];
extern UnkEC64Arg3 dratini_model[];
extern void func_800A1A50(Gfx**);
extern void func_802C5E68_79F3F8(GObj* obj);
extern void func_802C5F70_79F500(GObj* obj);
extern void func_802C606C_79F5FC(GObj* obj);
extern void func_802C63EC_79F97C(void);
extern void func_802C653C_79FACC(s32 arg0);
extern void func_802C82C0_7A1850(GObj*);
extern void func_802C8458_7A19E8(GObj*);
extern void func_802C8594_7A1B24(GObj*);
extern void func_802C8650_7A1BE0(GObj*);
extern void func_802C8828_7A1DB8(GObj*);
extern void func_802C892C_7A1EBC(GObj*);
extern void func_802C8EA8_7A2438(GObj*);
extern void func_802C903C_7A25CC(GObj*);
extern void func_802C91AC_7A273C(GObj*);
extern GObj* func_802C957C_7A2B0C(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData);
extern void func_802C95C0_7A2B50(GObj*);
extern void func_802C9634_7A2BC4(GObj*);
extern void func_802C96A0_7A2C30(GObj*);
extern void func_802C96FC_7A2C8C(GObj*);
extern void func_802C97A4_7A2D34(GObj*);
extern GObj* func_802C97F8_7A2D88(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn);
extern void func_802C9958_7A2EE8(GObj*);
extern void func_802C9A94_7A3024(GObj*);
extern void func_802C9BD0_7A3160(GObj*);
extern void func_802C9DC4_7A3354(GObj*);
extern void func_802C9EC8_7A3458(GObj*);
extern GObj* func_802C9F90_7A3520(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData);
extern void func_802C9FD0_7A3560(GObj*);
extern void func_802CA020_7A35B0(GObj*);
extern GObj* func_802CA224_7A37B4(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn);
extern void func_802CA270_7A3800(GObj*);
extern void func_802CA2BC_7A384C(GObj*);
extern void func_802CA2F4_7A3884(GObj*);
extern void func_802CA32C_7A38BC(GObj*);
extern GObj* func_802CA688_7A3C18(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData);
extern void func_802CA768_7A3CF8(GObj*);
extern void func_802CA8A4_7A3E34(GObj*);
extern void func_802CA948_7A3ED8(GObj*);
extern void func_802CA9BC_7A3F4C(GObj*);
extern void func_802CAA2C_7A3FBC(GObj*);
extern void func_802CAB2C_7A40BC(GObj*);
extern void func_802CAC2C_7A41BC(GObj*);
extern void func_802CACE4_7A4274(GObj*);
extern void func_802CAD54_7A42E4(GObj*);
extern void func_802CAF54_7A44E4(GObj*);
extern void func_802CB008_7A4598(GObj*);
extern void func_802CB02C_7A45BC(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn);
extern void func_802CB080_7A4610(GObj*);
extern void func_802CB110_7A46A0(GObj*);
extern void func_802CB194_7A4724(GObj*);
extern void func_802CB294_7A4824(GObj*);
extern void func_802CB394_7A4924(GObj*);
extern void func_802CB404_7A4994(GObj*);
extern void func_802CB474_7A4A04(GObj*);
extern void func_802CB5AC_7A4B3C(GObj*);
extern void func_802CB614_7A4BA4(GObj*);
extern void func_802CB7F4_7A4D84(GObj*);
extern void func_802CB818_7A4DA8(GObj*);
extern void func_802CB92C_7A4EBC(GObj*);
extern void func_802CB9BC_7A4F4C(GObj*);
extern void func_802CBC74_7A5204(GObj*);
extern void func_802CBD74_7A5304(GObj*);
extern void func_802CC104_7A5694(GObj*);
extern void func_802CC320_7A58B0(GObj*);
extern void func_802CC4DC_7A5A6C(GObj*);
extern void func_802CC514_7A5AA4(GObj*);
extern GObj* func_802CC8A8_7A5E38(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData);
extern void func_802CC8E0_7A5E70(GObj* obj, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6);
extern void func_802CCA70_7A6000(GObj*);
extern void func_802CCBF8_7A6188(GObj*);
extern void func_802CCCFC_7A628C(GObj*);
extern void func_802CCD80_7A6310(GObj*);
extern void func_802CCDDC_7A636C(GObj*);
extern GObj* func_802CD704_7A6C94(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData);
extern GObj* func_802CD73C_7A6CCC(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData);
extern void func_802CD774_7A6D04(GObj*);
extern void func_802CD7C0_7A6D50(GObj*);
extern void func_802CD8A4_7A6E34(GObj*);
extern void func_802CD8DC_7A6E6C(GObj*);
extern void func_802CDA94_7A7024(GObj*);
extern void func_802CDCFC_7A728C(GObj*);
extern GObj* func_802CDE04_7A7394(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData);
extern GObj* func_802CDE3C_7A73CC(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData);
extern void func_802CDE80_7A7410(GObj*);
extern void func_802CDEFC_7A748C(GObj*);
extern void func_802CDF68_7A74F8(GObj*);
extern void func_802CDFFC_7A758C(GObj*);
extern void func_802CE090_7A7620(GObj*);
extern void func_802CE124_7A76B4(GObj*);
extern GObj* func_802CE1B8_7A7748(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn);
extern void func_802CE200_7A7790(GObj*);
extern void func_802CE328_7A78B8(GObj*);
extern void func_802CE3CC_7A795C(GObj*);
extern void func_802CE440_7A79D0(GObj*);
extern void func_802CE4B0_7A7A40(GObj*);
extern void func_802CE5B0_7A7B40(GObj*);
extern void func_802CE6B0_7A7C40(GObj*);
extern void func_802CE768_7A7CF8(GObj*);
extern void func_802CE7D8_7A7D68(GObj*);
extern void func_802CE978_7A7F08(GObj*);
extern void func_802CEA34_7A7FC4(GObj*);
extern GObj* func_802CEA58_7A7FE8(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData);
extern void func_802CEAA0_7A8030(GObj*);
extern void func_802CEB9C_7A812C(GObj*);
extern void func_802CEFB8_7A8548(GObj*);
extern void func_802CF07C_7A860C(GObj*);
extern void func_802CF388_7A8918(GObj*);
extern void func_802CF3F8_7A8988(GObj*);
extern void func_802CF48C_7A8A1C(GObj*);
extern void func_802CF594_7A8B24(GObj*);
extern void func_802CF6CC_7A8C5C(GObj*);
extern void func_802CF720_7A8CB0(GObj*);
extern void func_802CF794_7A8D24(GObj*);
extern GObj* func_802CF808_7A8D98(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData);
extern void func_802CF840_7A8DD0(GObj* obj);
extern void func_802CF8BC_7A8E4C(GObj*);
extern GObj* func_802CFA00_7A8F90(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn);
extern void func_802D0320_7A98B0(GObj* obj);
extern void func_802D07BC_7A9D4C(GObj* obj);
extern GObj* func_802D0B3C_7AA0CC(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn);
extern void func_802D0B80_7AA110(GObj*);
extern void func_802D0BFC_7AA18C(GObj*);
extern GObj* func_802D1154_7AA6E4(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData);
extern void func_802D1190(GObj* obj);
extern void func_802D11B0(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn);
extern void func_802D1200_7AA790(GObj*);
extern void func_802D129C_7AA82C(GObj*);
extern void func_802D12D4_7AA864(GObj*);
extern void func_802D130C_7AA89C(GObj*);
extern void func_802D16CC_7AAC5C(GObj*);
extern void func_802D1734_7AACC4(GObj*);
extern void func_802D1F18_7AB4A8(GObj*);
extern void func_802D21C8_7AB758(s32 arg0, u16 arg1, WorldBlock* arg2, WorldBlock* arg3, ObjectSpawn* arg4);
extern void func_802D2230_7AB7C0(GObj*);
extern void func_802D22A0_7AB830(GObj*);
extern void func_802D22D4_7AB864(GObj*);
extern void func_802D230C_7AB89C(GObj*);
extern void func_802D2344_7AB8D4(GObj*);
extern void func_802D2540_7ABAD0(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn);
extern void func_802D25E0(GObj*);
extern void func_802D2604(GObj*);
extern void func_802D2684(GObj*);
extern void func_802D2704(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn);
extern GObj* func_8035E0D4_4FE4E4(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
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
extern UnkEC64Arg3 geodude_model[];
extern UnkEC64Arg3 goldeen_model[];
extern UnkEC64Arg3 graveler_model[];
extern UnkEC64Arg3 gyarados_model[];
extern UnkEC64Arg3 magikarp_model[];
extern UnkEC64Arg3 mankey_model[];
extern void omDrawAll(void);
extern void omUpdateAll(void);
extern void pokemonChangeBlock(GObj*, f32, f32, f32, f32, f32, f32);
extern void pokemonChangeBlockOnGround(GObj*, f32, f32, f32, f32, f32, f32);
extern void pokemonRemoveOne(GObj*);
extern void renRenderModelTypeB(GObj*);
extern void renderModelTypeBFogged(GObj*);
extern void renderModelTypeDFogged(GObj*);
extern void renderPokemonModelTypeBFogged(GObj*);
extern void renderPokemonModelTypeIFogged(GObj*);
extern UnkEC64Arg3 sandshrew_model[];
extern UnkEC64Arg3 sandslash_model[];
extern UnkEC64Arg3 squirtle_model[];
extern UnkEC64Arg3 starmie_model[];
extern UnkEC64Arg3 staryu_model[];
extern EnvSoundData D_802D2740_7ABCD0[58];
extern f32 D_802D2828_7ABDB8;
extern PokemonDef D_802D282C_7ABDBC[21];
extern s32 D_802D297C_7ABF0C;
extern GObj* D_802D2980_7ABF10;
extern PokemonDef D_802D2984_7ABF14;
extern PokemonDef D_802D2994_7ABF24;
extern PokemonDef D_802D29A4_7ABF34;
extern RandomState2 D_802D29B4_7ABF44[4];
extern ScreenSettings D_802D29D4_7ABF64;
extern SceneSetup D_802D29F0_7ABF80;
extern bool D_802D2A80_7AC010;
extern GObj* D_802D2A84_7AC014;
extern u32 D_802D2A90_7AC020;
extern u32 D_802D2A94_7AC024;
extern s32 D_802D2AA0_7AC030[2];
extern s32 D_802D2AA8_7AC038[2];
extern s32 D_802D2AB0_7AC040[2];
extern s32 D_802D2AB8_7AC048[1];
extern s32 D_802D2ABC_7AC04C[1];
extern AnimationHeader D_802D2AC0_7AC050;
extern AnimationHeader D_802D2AD4_7AC064;
extern AnimationHeader D_802D2AE8_7AC078;
extern AnimationHeader D_802D2AFC_7AC08C;
extern AnimationHeader D_802D2B10_7AC0A0;
extern AnimationHeader D_802D2B24_7AC0B4;
extern AnimationHeader D_802D2B38_7AC0C8;
extern AnimationHeader D_802D2B4C_7AC0DC;
extern AnimationHeader D_802D2B60_7AC0F0;
extern RandomState D_802D2B74_7AC104[3];
extern GObj* D_802D2B8C_7AC11C;
extern GObj* D_802D2B90_7AC120;
extern InteractionHandler2 D_802D2B94_7AC124;
extern InteractionHandler D_802D2BB4_7AC144[2];
extern InteractionHandler D_802D2BD4_7AC164[2];
extern f32 D_802D2BF4_7AC184;
extern f32 D_802D2BF8_7AC188;
extern Vec3f D_802D2BFC_7AC18C;
extern s32 D_802D2C08_7AC198;
extern f32 D_802D2C0C_7AC19C;
extern InteractionHandler3 D_802D2C10_7AC1A0;
extern InteractionHandler3 D_802D2C40_7AC1D0;
extern InteractionHandler3 D_802D2C70_7AC200;
extern PokemonAnimationSetup D_802D2CA0_7AC230;
extern PokemonInitData D_802D2CB4_7AC244;
extern s32 D_802D2CF0_7AC280[2];
extern s32 D_802D2CF8_7AC288[1];
extern s32 D_802D2CFC_7AC28C[3];
extern s32 D_802D2D08_7AC298[2];
extern AnimationHeader D_802D2D10_7AC2A0;
extern AnimationHeader D_802D2D24_7AC2B4;
extern AnimationHeader D_802D2D38_7AC2C8;
extern AnimationHeader D_802D2D4C_7AC2DC;
extern AnimationHeader D_802D2D60_7AC2F0;
extern GObj* D_802D2D74_7AC304;
extern u16 D_802D2D78_7AC308;
extern InteractionHandler D_802D2D7C_7AC30C[3];
extern InteractionHandler D_802D2DAC_7AC33C[2];
extern RandomState D_802D2DCC_7AC35C[3];
extern PokemonAnimationSetup D_802D2DE4_7AC374;
extern PokemonInitData D_802D2DF8_7AC388;
extern s32 D_802D2E30_7AC3C0[2];
extern s32 D_802D2E38_7AC3C8[2];
extern s32 D_802D2E40_7AC3D0[2];
extern AnimationHeader D_802D2E48_7AC3D8;
extern AnimationHeader D_802D2E5C_7AC3EC;
extern AnimationHeader D_802D2E70_7AC400;
extern AnimationHeader D_802D2E84_7AC414;
extern AnimationHeader D_802D2E98_7AC428;
extern AnimationHeader D_802D2EAC_7AC43C;
extern RandomState D_802D2EC0_7AC450[3];
extern InteractionHandler2 D_802D2ED8_7AC468;
extern InteractionHandler D_802D2EF8_7AC488[2];
extern PokemonAnimationSetup D_802D2F18_7AC4A8;
extern PokemonInitData D_802D2F2C_7AC4BC;
extern s32 D_802D2F60_7AC4F0[2];
extern s32 D_802D2F68_7AC4F8[2];
extern s32 D_802D2F70_7AC500[3];
extern s32 D_802D2F7C_7AC50C[2];
extern s32 D_802D2F84_7AC514[2];
extern AnimationHeader D_802D2F8C_7AC51C;
extern AnimationHeader D_802D2FA0_7AC530;
extern AnimationHeader D_802D2FB4_7AC544;
extern AnimationHeader D_802D2FC8_7AC558;
extern AnimationHeader D_802D2FDC_7AC56C;
extern GObj* D_802D2FF0_7AC580;
extern u16 D_802D2FF4_7AC584;
extern InteractionHandler D_802D2FF8_7AC588[2];
extern PokemonAnimationSetup D_802D3018_7AC5A8;
extern PokemonInitData D_802D302C_7AC5BC;
extern s32 D_802D3060_7AC5F0[3];
extern s32 D_802D306C_7AC5FC[3];
extern s32 D_802D3078_7AC608[3];
extern AnimationHeader D_802D3084_7AC614;
extern AnimationHeader D_802D3098_7AC628;
extern AnimationHeader D_802D30AC_7AC63C;
extern RandomState D_802D30C0_7AC650[4];
extern Vec3f D_802D30E0_7AC670;
extern PokemonAnimationSetup D_802D30EC_7AC67C;
extern PokemonInitData D_802D3100_7AC690;
extern s32 D_802D3140_7AC6D0[1];
extern s32 D_802D3144_7AC6D4[2];
extern s32 D_802D314C_7AC6DC[2];
extern s32 D_802D3154_7AC6E4[2];
extern AnimationHeader D_802D315C_7AC6EC;
extern AnimationHeader D_802D3170_7AC700;
extern AnimationHeader D_802D3184_7AC714;
extern AnimationHeader D_802D3198_7AC728;
extern AnimationHeader D_802D31AC_7AC73C;
extern AnimationHeader D_802D31C0_7AC750;
extern AnimationHeader D_802D31D4_7AC764;
extern AnimationHeader D_802D31E8_7AC778;
extern AnimationHeader D_802D31FC_7AC78C;
extern AnimationHeader D_802D3210_7AC7A0;
extern InteractionHandler D_802D3224_7AC7B4[5];
extern RandomState D_802D3274_7AC804[4];
extern InteractionHandler2 D_802D3294_7AC824;
extern InteractionHandler D_802D32B4_7AC844[2];
extern InteractionHandler D_802D32D4_7AC864[3];
extern InteractionHandler D_802D3304_7AC894[3];
extern InteractionHandler D_802D3334_7AC8C4[4];
extern InteractionHandler D_802D3374_7AC904[4];
extern InteractionHandler3 D_802D33B4_7AC944;
extern PokemonAnimationSetup D_802D33E4_7AC974;
extern PokemonInitData D_802D33F8_7AC988;
extern s32 D_802D3430_7AC9C0[1];
extern s32 D_802D3434_7AC9C4[1];
extern s32 D_802D3438_7AC9C8[1];
extern s32 D_802D343C_7AC9CC[2];
extern s32 D_802D3444_7AC9D4[2];
extern s32 D_802D344C_7AC9DC[1];
extern AnimationHeader D_802D3450_7AC9E0;
extern AnimationHeader D_802D3464_7AC9F4;
extern AnimationHeader D_802D3478_7ACA08;
extern AnimationHeader D_802D348C_7ACA1C;
extern AnimationHeader D_802D34A0_7ACA30;
extern AnimationHeader D_802D34B4_7ACA44;
extern AnimationHeader D_802D34C8_7ACA58;
extern AnimationHeader D_802D34DC_7ACA6C;
extern AnimationHeader D_802D34F0_7ACA80;
extern AnimationHeader D_802D3504_7ACA94;
extern AnimationHeader D_802D3518_7ACAA8;
extern AnimationHeader D_802D352C_7ACABC;
extern AnimationHeader D_802D3540_7ACAD0;
extern AnimationHeader D_802D3554_7ACAE4;
extern InteractionHandler D_802D3568_7ACAF8[10];
extern RandomState D_802D3608_7ACB98[6];
extern f32 D_802D3638_7ACBC8;
extern InteractionHandler D_802D363C_7ACBCC[3];
extern InteractionHandler D_802D366C_7ACBFC[3];
extern InteractionHandler D_802D369C_7ACC2C[3];
extern InteractionHandler D_802D36CC_7ACC5C[4];
extern InteractionHandler D_802D370C_7ACC9C[2];
extern InteractionHandler D_802D372C_7ACCBC[2];
extern InteractionHandler D_802D374C_7ACCDC[2];
extern InteractionHandler D_802D376C_7ACCFC[2];
extern InteractionHandler D_802D378C_7ACD1C[2];
extern PokemonAnimationSetup D_802D37AC_7ACD3C;
extern PokemonInitData D_802D37C0_7ACD50;
extern s32 D_802D3800_7ACD90[1];
extern s32 D_802D3804_7ACD94[1];
extern AnimationHeader D_802D3808_7ACD98;
extern AnimationHeader D_802D381C_7ACDAC;
extern AnimationHeader D_802D3830_7ACDC0;
extern f32 D_802D3844_7ACDD4;
extern s32 D_802D3848_7ACDD8;
extern f32 D_802D384C_7ACDDC;
extern InteractionHandler D_802D3850_7ACDE0[3];
extern InteractionHandler2 D_802D3880_7ACE10;
extern InteractionHandler D_802D38A0_7ACE30[4];
extern InteractionHandler D_802D38E0_7ACE70[2];
extern PokemonAnimationSetup D_802D3900_7ACE90;
extern PokemonInitData D_802D3914_7ACEA4;
extern s32 D_802D3950_7ACEE0[1];
extern s32 D_802D3954_7ACEE4[1];
extern AnimationHeader D_802D3958_7ACEE8;
extern AnimationHeader D_802D396C_7ACEFC;
extern AnimationHeader D_802D3980_7ACF10;
extern InteractionHandler D_802D3994_7ACF24[2];
extern RandomStates3 D_802D39B4_7ACF44;
extern s32 D_802D39CC_7ACF5C;
extern InteractionHandler2 D_802D39D0_7ACF60;
extern InteractionHandler2 D_802D39F0_7ACF80;
extern InteractionHandler2 D_802D3A10_7ACFA0;
extern PokemonAnimationSetup D_802D3A30_7ACFC0;
extern PokemonInitData D_802D3A44_7ACFD4;
extern AnimationHeader D_802D3A80_7AD010;
extern AnimationHeader D_802D3A94_7AD024;
extern AnimationHeader D_802D3AA8_7AD038;
extern AnimationHeader D_802D3ABC_7AD04C;
extern AnimationHeader D_802D3AD0_7AD060;
extern AnimationHeader D_802D3AE4_7AD074;
extern AnimationHeader D_802D3AF8_7AD088;
extern AnimationHeader D_802D3B0C_7AD09C;
extern AnimationHeader D_802D3B20_7AD0B0;
extern GObj* D_802D3B34_7AD0C4;
extern InteractionHandler D_802D3B38_7AD0C8[3];
extern InteractionHandler D_802D3B68_7AD0F8[3];
extern InteractionHandler D_802D3B98_7AD128[3];
extern InteractionHandler D_802D3BC8_7AD158[3];
extern PokemonAnimationSetup D_802D3BF8_7AD188;
extern PokemonInitData D_802D3C0C_7AD19C;
extern s32 D_802D3C40_7AD1D0[2];
extern s32 D_802D3C48_7AD1D8[2];
extern s32 D_802D3C50_7AD1E0[3];
extern AnimationHeader D_802D3C5C_7AD1EC;
extern AnimationHeader D_802D3C70_7AD200;
extern AnimationHeader D_802D3C84_7AD214;
extern AnimationHeader D_802D3C98_7AD228;
extern AnimationHeader D_802D3CAC_7AD23C;
extern AnimationHeader D_802D3CC0_7AD250;
extern AnimationHeader D_802D3CD4_7AD264;
extern AnimationHeader D_802D3CE8_7AD278;
extern AnimationHeader D_802D3CFC_7AD28C;
extern AnimationHeader D_802D3D10_7AD2A0;
extern InteractionHandler D_802D3D24_7AD2B4[6];
extern RandomState D_802D3D84_7AD314[4];
extern InteractionHandler2 D_802D3DA4_7AD334;
extern InteractionHandler D_802D3DC4_7AD354[2];
extern InteractionHandler D_802D3DE4_7AD374[3];
extern InteractionHandler D_802D3E14_7AD3A4[3];
extern InteractionHandler D_802D3E44_7AD3D4[5];
extern InteractionHandler D_802D3E94_7AD424[5];
extern InteractionHandler4 D_802D3EE4_7AD474;
extern PokemonAnimationSetup D_802D3F24_7AD4B4;
extern PokemonInitData D_802D3F38_7AD4C8;
extern s32 D_802D3F70_7AD500[2];
extern s32 D_802D3F78_7AD508[1];
extern s32 D_802D3F7C_7AD50C[2];
extern s32 D_802D3F84_7AD514[2];
extern AnimationHeader D_802D3F8C_7AD51C;
extern AnimationHeader D_802D3FA0_7AD530;
extern AnimationHeader D_802D3FB4_7AD544;
extern AnimationHeader D_802D3FC8_7AD558;
extern AnimationHeader D_802D3FDC_7AD56C;
extern GObj* D_802D3FF0_7AD580;
extern GObj* D_802D3FF4_7AD584;
extern s32 D_802D3FF8_7AD588;
extern InteractionHandler D_802D3FFC_7AD58C[2];
extern InteractionHandler D_802D401C_7AD5AC[3];
extern InteractionHandler2 D_802D404C_7AD5DC;
extern f32 D_802D406C_7AD5FC;
extern InteractionHandler D_802D4070_7AD600[3];
extern RandomState D_802D40A0_7AD630[2];
extern InteractionHandler D_802D40B0_7AD640[2];
extern InteractionHandler D_802D40D0_7AD660[4];
extern PokemonAnimationSetup D_802D4110_7AD6A0;
extern PokemonInitData D_802D4124_7AD6B4;
extern s32 D_802D4160_7AD6F0[2];
extern AnimationHeader D_802D4168_7AD6F8;
extern AnimationHeader D_802D417C_7AD70C;
extern AnimationHeader D_802D4190_7AD720;
extern GObj* D_802D41A4_7AD734;
extern InteractionHandler D_802D41A8_7AD738[2];
extern Vec3f D_802D41C8_7AD758;
extern PokemonAnimationSetup D_802D41D4_7AD764;
extern PokemonInitData D_802D41E8_7AD778;
extern AnimationHeader D_802D4220_7AD7B0;
extern Gfx D_802D4238_7AD7C8[1];
extern u8 D_802D4240_7AD7D0[4096];
extern Gfx D_802D5240_7AE7D0[1];
extern u8 D_802D5248_7AE7D8[4096];
extern Gfx D_802D6248_7AF7D8[1];
extern u8 D_802D6250_7AF7E0[4096];
extern Gfx D_802D7250_7B07E0[1];
extern u8 D_802D7258_7B07E8[4096];
extern Gfx D_802D8258_7B17E8[1];
extern u8 D_802D8260_7B17F0[4096];
extern Gfx D_802D9260_7B27F0[1];
extern u8 D_802D9268_7B27F8[4096];
extern Gfx D_802DA268_7B37F8[1];
extern u8 D_802DA270_7B3800[4096];
extern Gfx D_802DB270_7B4800[1];
extern u8 D_802DB278_7B4808[4096];
extern Gfx D_802DC278_7B5808[1];
extern u8 D_802DC280_7B5810[4096];
extern Gfx D_802DD280_7B6810[1];
extern u8 D_802DD288_7B6818[4096];
extern Gfx D_802DE288_7B7818[1];
extern u8 D_802DE290_7B7820[4096];
extern Gfx D_802DF290_7B8820[1];
extern u8 D_802DF298_7B8828[4096];
extern Gfx D_802E0298_7B9828[1];
extern u8 D_802E02A0_7B9830[4096];
extern Gfx D_802E12A0_7BA830[1];
extern u8 D_802E12A8_7BA838[4096];
extern Gfx D_802E22A8_7BB838[1];
extern u8 D_802E22B0_7BB840[4096];
extern Gfx D_802E32B0_7BC840[1];
extern u8 D_802E32B8_7BC848[4096];
extern Gfx D_802E42B8_7BD848[1];
extern u8 D_802E42C0_7BD850[4096];
extern Gfx D_802E52C0_7BE850[1];
extern u8 D_802E52C8_7BE858[4096];
extern Gfx D_802E62C8_7BF858[1];
extern u8 D_802E62D0_7BF860[896];
extern Gfx D_802E6650_7BFBE0[1];
extern u8 D_802E6658_7BFBE8[896];
extern Bitmap D_802E69D8_7BFF68[20];
extern Sprite D_802E6B18_7C00A8;
extern Gfx D_802E6B60_7C00F0[1];
extern u8 D_802E6B68_7C00F8[1440];
extern Bitmap D_802E7108_7C0698[1];
extern Sprite D_802E7118_7C06A8;
extern Gfx D_802E7160_7C06F0[1];
extern u8 D_802E7168_7C06F8[1440];
extern Bitmap D_802E7708_7C0C98[1];
extern Sprite D_802E7718_7C0CA8;
extern Gfx D_802E7760_7C0CF0[1];
extern u8 D_802E7768_7C0CF8[1440];
extern Bitmap D_802E7D08_7C1298[1];
extern Sprite D_802E7D18_7C12A8;
extern Gfx D_802E7D60_7C12F0[1];
extern u8 D_802E7D68_7C12F8[1440];
extern Bitmap D_802E8308_7C1898[1];
extern Sprite D_802E8318_7C18A8;
extern Gfx D_802E8360_7C18F0[1];
extern u8 D_802E8368_7C18F8[1440];
extern Bitmap D_802E8908_7C1E98[1];
extern Sprite D_802E8918_7C1EA8;
extern Gfx D_802E8960_7C1EF0[1];
extern u8 D_802E8968_7C1EF8[1440];
extern Bitmap D_802E8F08_7C2498[1];
extern Sprite D_802E8F18_7C24A8;
extern Gfx D_802E8F60_7C24F0[1];
extern u8 D_802E8F68_7C24F8[2112];
extern Bitmap D_802E97A8_7C2D38[1];
extern Sprite D_802E97B8_7C2D48;
extern Gfx D_802E9800_7C2D90[1];
extern u8 D_802E9808_7C2D98[2112];
extern Bitmap D_802EA048_7C35D8[1];
extern Sprite D_802EA058_7C35E8;
extern Gfx D_802EA0A0_7C3630[1];
extern u8 D_802EA0A8_7C3638[2112];
extern Bitmap D_802EA8E8_7C3E78[1];
extern Sprite D_802EA8F8_7C3E88;
extern Gfx D_802EA940_7C3ED0[1];
extern u8 D_802EA948_7C3ED8[2112];
extern Bitmap D_802EB188_7C4718[1];
extern Sprite D_802EB198_7C4728;
extern Gfx D_802EB1E0_7C4770[1];
extern u8 D_802EB1E8_7C4778[2112];
extern Bitmap D_802EBA28_7C4FB8[1];
extern Sprite D_802EBA38_7C4FC8;
extern Gfx D_802EBA80_7C5010[1];
extern u8 D_802EBA88_7C5018[2112];
extern Bitmap D_802EC2C8_7C5858[1];
extern Sprite D_802EC2D8_7C5868;
extern Gfx D_802EC320_7C58B0[1];
extern u8 D_802EC328_7C58B8[416];
extern Bitmap D_802EC4C8_7C5A58[1];
extern Sprite D_802EC4D8_7C5A68;
extern SomeC D_802EC51C_7C5AAC[15];
extern SomeC D_802EC5D0_7C5B60[2];
extern s32 D_802EC5E8_7C5B78;
extern s32 D_802EC5EC_7C5B7C;
extern Sprite* D_802EC5F0_7C5B80[6];
extern Sprite* D_802EC608_7C5B98[6];
extern Sprite* D_802EC620_7C5BB0[6];
extern f32 D_802EC638_7C5BC8[3];
extern GObj* D_802EC644_7C5BD4;
extern OMCamera* D_802EC648_7C5BD8;
extern s32 D_802EC64C_7C5BDC;
extern f32 D_802EC650_7C5BE0;
extern f32 D_802EC654_7C5BE4;
extern InteractionHandler D_802EC658_7C5BE8[2];
extern PokemonAnimationSetup D_802EC678_7C5C08;
extern PokemonInitData D_802EC68C_7C5C1C;
extern AnimationHeader D_802EC6C0_7C5C50;
extern AnimationHeader D_802EC6D4_7C5C64;
extern AnimationHeader D_802EC6E8_7C5C78;
extern AnimationHeader D_802EC6FC_7C5C8C;
extern s32 D_802EC710_7C5CA0;
extern s32 D_802EC714_7C5CA4;
extern InteractionHandler D_802EC718_7C5CA8[2];
extern SomeS16s D_802EC738_7C5CC8;
extern PokemonAnimationSetup D_802EC73C_7C5CCC;
extern PokemonInitData D_802EC750_7C5CE0;
extern AnimationHeader D_802EC790_7C5D20;
extern PokemonAnimationSetup D_802EC7A4_7C5D34;
extern PokemonInitData D_802EC7B8_7C5D48;
extern s32 D_802EC7F0_7C5D80[1];
extern s32 D_802EC7F4_7C5D84[3];
extern s32 D_802EC800_7C5D90[3];
extern s32 D_802EC80C_7C5D9C[3];
extern AnimationHeader D_802EC818_7C5DA8;
extern AnimationHeader D_802EC82C_7C5DBC;
extern AnimationHeader D_802EC840_7C5DD0;
extern AnimationHeader D_802EC854_7C5DE4;
extern u16 D_802EC868_7C5DF8;
extern u16 D_802EC86C_7C5DFC;
extern RandomState D_802EC870_7C5E00[4];
extern s32 D_802EC890_7C5E20;
extern f32 D_802EC894_7C5E24;
extern InteractionHandler D_802EC898_7C5E28[2];
extern InteractionHandler D_802EC8B8_7C5E48[2];
extern Vec3f D_802EC8D8_7C5E68;
extern InteractionHandler D_802EC8E4_7C5E74[3];
extern Vec3f D_802EC914_7C5EA4;
extern PokemonAnimationSetup D_802EC920_7C5EB0;
extern PokemonInitData D_802EC934_7C5EC4;
extern s32 D_802EC970_7C5F00[3];
extern s32 D_802EC97C_7C5F0C[3];
extern s32 D_802EC988_7C5F18[3];
extern AnimationHeader D_802EC994_7C5F24;
extern AnimationHeader D_802EC9A8_7C5F38;
extern AnimationHeader D_802EC9BC_7C5F4C;
extern InteractionHandler D_802EC9D0_7C5F60[2];
extern RandomState D_802EC9F0_7C5F80[4];
extern Vec3f D_802ECA10_7C5FA0;
extern PokemonAnimationSetup D_802ECA1C_7C5FAC;
extern PokemonInitData D_802ECA30_7C5FC0;
extern UnkEC64Arg3 D_802ECA70_7C6000[2];
extern AnimCmd* D_802ECAC8_7C6058[1];
extern AnimationHeader D_802ECACC_7C605C;
extern PokemonDef extraStaryuDef;
extern PokemonDef extraStarmieDef;
extern RandomState D_802ECB00_7C6090[3];
extern PokemonAnimationSetup D_802ECB18_7C60A8;
extern PokemonInitData D_802ECB2C_7C60BC;

/* ROM 7ABCD0; VRAM 802D2740. */
EnvSoundData D_802D2740_7ABCD0[58] = {
    { 42, 0, 20 },
    { 30, 0, 15 },
    { 346, 1, 24 },
    { 106, 0, 24 },
    { 385, 0, 24 },
    { 245, 1, 18 },
    { 246, 1, 18 },
    { 247, 1, 14 },
    { 243, 1, 18 },
    { 244, 1, 18 },
    { 390, 0, 18 },
    { 102, 0, 18 },
    { 104, 0, 12 },
    { 345, 1, 18 },
    { 228, 1, 14 },
    { 229, 1, 14 },
    { 103, 0, 14 },
    { 101, 0, 14 },
    { 105, 0, 8 },
    { 249, 1, 20 },
    { 250, 1, 20 },
    { 156, 0, 22 },
    { 392, 0, 18 },
    { 119, 0, 15 },
    { 210, 1, 9 },
    { 211, 1, 9 },
    { 376, 0, 8 },
    { 114, 0, 8 },
    { 387, 0, 20 },
    { 391, 0, 24 },
    { 240, 1, 12 },
    { 241, 1, 12 },
    { 242, 1, 12 },
    { 115, 0, 12 },
    { 248, 1, 10 },
    { 386, 0, 10 },
    { 107, 0, 10 },
    { 230, 1, 9 },
    { 231, 1, 9 },
    { 232, 1, 9 },
    { 233, 1, 9 },
    { 374, 0, 9 },
    { 108, 0, 9 },
    { 117, 0, 9 },
    { 394, 0, 9 },
    { 388, 0, 9 },
    { 375, 0, 8 },
    { 303, 1, 20 },
    { 239, 1, 9 },
    { 111, 0, 8 },
    { 113, 0, 8 },
    { 235, 1, 9 },
    { 234, 1, 9 },
    { 236, 1, 9 },
    { 237, 1, 9 },
    { 366, 0, 8 },
    { 116, 0, 8 },
    { 389, 0, 16 },
};

/* ROM 7ABDB8; VRAM 802D2828. */
f32 D_802D2828_7ABDB8 = 0.0f;

/* ROM 7ABDBC; VRAM 802D282C. */
PokemonDef D_802D282C_7ABDBC[21] = {
    { 75, (pokemonInit) func_802C957C_7A2B0C, pokemonChangeBlockOnGround, pokemonRemoveOne },
    { 130, func_802C97F8_7A2D88, pokemonChangeBlock, pokemonRemoveOne },
    { 74, (pokemonInit) func_802C9F90_7A3520, pokemonChangeBlockOnGround, pokemonRemoveOne },
    { 129, (pokemonInit) func_802D21C8_7AB758, pokemonChangeBlock, pokemonRemoveOne },
    { 149, func_802CA224_7A37B4, pokemonChangeBlockOnGround, pokemonRemoveOne },
    { 147, (pokemonInit) func_802CA688_7A3C18, pokemonChangeBlockOnGround, pokemonRemoveOne },
    { 27, (pokemonInit) func_802CB02C_7A45BC, pokemonChangeBlockOnGround, pokemonRemoveOne },
    { 118, (pokemonInit) func_802D2540_7ABAD0, pokemonChangeBlockOnGround, pokemonRemoveOne },
    { 7, (pokemonInit) func_802CC8A8_7A5E38, func_802CC8E0_7A5E70, pokemonRemoveOne },
    { 28, (pokemonInit) func_802CEA58_7A7FE8, pokemonChangeBlockOnGround, pokemonRemoveOne },
    { 56, (pokemonInit) func_802CF808_7A8D98, pokemonChangeBlockOnGround, pokemonRemoveOne },
    { 120, (pokemonInit) func_802CD704_7A6C94, pokemonChangeBlock, func_802CD774_7A6D04 },
    { 121, (pokemonInit) func_802CDE04_7A7394, pokemonChangeBlock, pokemonRemoveOne },
    { 1036, (pokemonInit) func_802D2704, pokemonChangeBlock, pokemonRemoveOne },
    { 1003, func_8035E0D4_4FE4E4, pokemonChangeBlock, pokemonRemoveOne },
    { 1033, func_802CE1B8_7A7748, pokemonChangeBlock, pokemonRemoveOne },
    { 1034, func_802CFA00_7A8F90, pokemonChangeBlock, pokemonRemoveOne },
    { 1032, func_802D0B3C_7AA0CC, pokemonChangeBlock, pokemonRemoveOne },
    { 1001, (pokemonInit) func_802D1154_7AA6E4, pokemonChangeBlock, pokemonRemoveOne },
    { 1035, (pokemonInit) func_802D11B0, pokemonChangeBlock, pokemonRemoveOne },
    { 0, NULL, NULL, NULL }
};

/* ROM 7ABF0C; VRAM 802D297C. */
s32 D_802D297C_7ABF0C = 0;

/* ROM 7ABF10; VRAM 802D2980. */
GObj* D_802D2980_7ABF10 = NULL;

/* ROM 7ABF14; VRAM 802D2984. */
PokemonDef D_802D2984_7ABF14 = { 118, (pokemonInit) func_802D2540_7ABAD0, pokemonChangeBlockOnGround, pokemonRemoveOne };

/* ROM 7ABF24; VRAM 802D2994. */
PokemonDef D_802D2994_7ABF24 = { 147, (pokemonInit) func_802CA688_7A3C18, pokemonChangeBlockOnGround, pokemonRemoveOne };

/* ROM 7ABF34; VRAM 802D29A4. */
PokemonDef D_802D29A4_7ABF34 = { 129, (pokemonInit) func_802D21C8_7AB758, pokemonChangeBlockOnGround, pokemonRemoveOne };

/* ROM 7ABF44; VRAM 802D29B4. */
RandomState2 D_802D29B4_7ABF44[4] = {
    { 10, func_802C5E68_79F3F8 },
    { 10, func_802C5F70_79F500 },
    { 10, func_802C606C_79F5FC },
    { 70, NULL },
};

/* ROM 7ABF64; VRAM 802D29D4. */
ScreenSettings D_802D29D4_7ABF64 = { D_803B5000, D_803DA800, NULL, NULL, 320, 240, 2713 };

/* ROM 7ABF80; VRAM 802D29F0. */
SceneSetup D_802D29F0_7ABF80 = {
    { 0, omUpdateAll, omDrawAll, valley_assets_VRAM_END, 0, 1, 2, 20480, 4096, 1024, 0, 51200, 2, 16384, func_800A1A50, contUpdate },
    0,
    1088,
    0,
    0,
    0,
    0,
    92,
    0,
    NULL,
    func_802C653C_79FACC,
    0,
    0,
    0,
    136,
    0,
    88,
    0,
    144,
    func_802C63EC_79F97C
};

/* Bounded original zero alignment/storage: 4 bytes. */
char D_802D2A7C_7AC00C_padding[4] = "";

/* ROM 7AC010; VRAM 802D2A80. */
bool D_802D2A80_7AC010 = 0;

/* ROM 7AC014; VRAM 802D2A84. */
GObj* D_802D2A84_7AC014 = NULL;

/* Bounded original zero alignment/storage: 8 bytes. */
char D_802D2A88_7AC018_padding[8] = "";

/* ROM 7AC020; VRAM 802D2A90. */
u32 D_802D2A90_7AC020 = 0;

/* ROM 7AC024; VRAM 802D2A94. */
u32 D_802D2A94_7AC024 = 0;

/* Bounded original zero alignment/storage: 8 bytes. */
char D_802D2A98_7AC028_padding[8] = "";

/* ROM 7AC030; VRAM 802D2AA0. */
s32 D_802D2AA0_7AC030[2] = { 245, 390 };

/* ROM 7AC038; VRAM 802D2AA8. */
s32 D_802D2AA8_7AC038[2] = { 246, 102 };

/* ROM 7AC040; VRAM 802D2AB0. */
s32 D_802D2AB0_7AC040[2] = { 247, 104 };

/* ROM 7AC048; VRAM 802D2AB8. */
s32 D_802D2AB8_7AC048[1] = { 243 };

/* ROM 7AC04C; VRAM 802D2ABC. */
s32 D_802D2ABC_7AC04C[1] = { 244 };

/* ROM 7AC050; VRAM 802D2AC0. */
AnimationHeader D_802D2AC0_7AC050 = { 0.150000006f, 50.0f, D_80133AE0_429F20, NULL, NULL };

/* ROM 7AC064; VRAM 802D2AD4. */
AnimationHeader D_802D2AD4_7AC064 = { 0.200000003f, 9.0f, D_801329B0_428DF0, NULL, D_802D2AA0_7AC030 };

/* ROM 7AC078; VRAM 802D2AE8. */
AnimationHeader D_802D2AE8_7AC078 = { 0.150000006f, 10.0f, D_80133800_429C40, NULL, NULL };

/* ROM 7AC08C; VRAM 802D2AFC. */
AnimationHeader D_802D2AFC_7AC08C = { 0.200000003f, 30.0f, D_80132DF0_429230, D_801346F0_42AB30, D_802D2AA8_7AC038 };

/* ROM 7AC0A0; VRAM 802D2B10. */
AnimationHeader D_802D2B10_7AC0A0 = { 0.300000012f, 30.0f, D_80131990_427DD0, D_80134610_42AA50, NULL };

/* ROM 7AC0B4; VRAM 802D2B24. */
AnimationHeader D_802D2B24_7AC0B4 = { 0.300000012f, 20.0f, D_8012FFD0_426410, D_80134570_42A9B0, D_802D2AB0_7AC040 };

/* ROM 7AC0C8; VRAM 802D2B38. */
AnimationHeader D_802D2B38_7AC0C8 = { 0.300000012f, 20.0f, D_80130A30_426E70, NULL, D_802D2AB8_7AC048 };

/* ROM 7AC0DC; VRAM 802D2B4C. */
AnimationHeader D_802D2B4C_7AC0DC = { 0.270000011f, 20.0f, D_80131240_427680, NULL, NULL };

/* ROM 7AC0F0; VRAM 802D2B60. */
AnimationHeader D_802D2B60_7AC0F0 = { 0.200000003f, 20.0f, D_80132150_428590, NULL, D_802D2ABC_7AC04C };

/* ROM 7AC104; VRAM 802D2B74. */
RandomState D_802D2B74_7AC104[3] = {
    { 100, func_802C8828_7A1DB8 },
    { 100, func_802C892C_7A1EBC },
    { 0, NULL },
};

/* ROM 7AC11C; VRAM 802D2B8C. */
GObj* D_802D2B8C_7AC11C = NULL;

/* ROM 7AC120; VRAM 802D2B90. */
GObj* D_802D2B90_7AC120 = NULL;

/* ROM 7AC124; VRAM 802D2B94. */
InteractionHandler2 D_802D2B94_7AC124 = { {
    { 16, func_802C8458_7A19E8, 3000.0f, NULL },
    { 58, NULL, 0.0f, NULL },
} };

/* ROM 7AC144; VRAM 802D2BB4. */
InteractionHandler D_802D2BB4_7AC144[2] = {
    { 38, func_802C8594_7A1B24, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 7AC164; VRAM 802D2BD4. */
InteractionHandler D_802D2BD4_7AC164[2] = {
    { 38, func_802C8650_7A1BE0, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 7AC184; VRAM 802D2BF4. */
f32 D_802D2BF4_7AC184 = 0.0f;

/* ROM 7AC188; VRAM 802D2BF8. */
f32 D_802D2BF8_7AC188 = 0.0f;

/* ROM 7AC18C; VRAM 802D2BFC. */
Vec3f D_802D2BFC_7AC18C = { 0.0f, 0.0f, 0.0f };

/* ROM 7AC198; VRAM 802D2C08. */
s32 D_802D2C08_7AC198 = 0;

/* ROM 7AC19C; VRAM 802D2C0C. */
f32 D_802D2C0C_7AC19C = 0.0f;

/* ROM 7AC1A0; VRAM 802D2C10. */
InteractionHandler3 D_802D2C10_7AC1A0 = { {
    { 41, func_802C903C_7A25CC, 0.0f, NULL },
    { 42, func_802C91AC_7A273C, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
} };

/* ROM 7AC1D0; VRAM 802D2C40. */
InteractionHandler3 D_802D2C40_7AC1D0 = { {
    { 40, func_802C8EA8_7A2438, 0.0f, NULL },
    { 42, func_802C91AC_7A273C, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
} };

/* ROM 7AC200; VRAM 802D2C70. */
InteractionHandler3 D_802D2C70_7AC200 = { {
    { 40, func_802C8EA8_7A2438, 0.0f, NULL },
    { 41, func_802C903C_7A25CC, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
} };

/* ROM 7AC230; VRAM 802D2CA0. */
PokemonAnimationSetup D_802D2CA0_7AC230 = { &D_802D2B10_7AC0A0, func_802C82C0_7A1850, 0, { 0, 0, 0 }, NULL, NULL };

/* ROM 7AC244; VRAM 802D2CB4. */
PokemonInitData D_802D2CB4_7AC244 = { graveler_model, D_8031F9D0_7F8F60, renderPokemonModelTypeBFogged, &D_802D2CA0_7AC230, { 2.20000005f, 2.20000005f, 2.20000005f }, { 0.0f, 205.0f, 10.0f }, 65.0f, 37, 0, 0, 0, { 0, 0, 0 } };

/* Bounded original zero alignment/storage: 8 bytes. */
char D_802D2CE8_7AC278_padding[8] = "";

/* ROM 7AC280; VRAM 802D2CF0. */
s32 D_802D2CF0_7AC280[2] = { 346, 385 };

/* ROM 7AC288; VRAM 802D2CF8. */
s32 D_802D2CF8_7AC288[1] = { 346 };

/* ROM 7AC28C; VRAM 802D2CFC. */
s32 D_802D2CFC_7AC28C[3] = { 346, 106, 385 };

/* ROM 7AC298; VRAM 802D2D08. */
s32 D_802D2D08_7AC298[2] = { 0, 385 };

/* ROM 7AC2A0; VRAM 802D2D10. */
AnimationHeader D_802D2D10_7AC2A0 = { 0.25f, 57.0f, D_8013BEC0_432300, NULL, D_802D2CF0_7AC280 };

/* ROM 7AC2B4; VRAM 802D2D24. */
AnimationHeader D_802D2D24_7AC2B4 = { 0.25f, 56.0f, D_80139880_42FCC0, D_8013C6B0_432AF0, NULL };

/* ROM 7AC2C8; VRAM 802D2D38. */
AnimationHeader D_802D2D38_7AC2C8 = { 0.25f, 51.0f, D_8013A370_4307B0, D_8013C7A0_432BE0, D_802D2CF8_7AC288 };

/* ROM 7AC2DC; VRAM 802D2D4C. */
AnimationHeader D_802D2D4C_7AC2DC = { 0.5f, 100.0f, D_80137D60_42E1A0, NULL, D_802D2CFC_7AC28C };

/* ROM 7AC2F0; VRAM 802D2D60. */
AnimationHeader D_802D2D60_7AC2F0 = { 0.319999993f, 70.0f, D_8013B150_431590, D_8013C830_432C70, D_802D2D08_7AC298 };

/* ROM 7AC304; VRAM 802D2D74. */
GObj* D_802D2D74_7AC304 = NULL;

/* ROM 7AC308; VRAM 802D2D78. */
u16 D_802D2D78_7AC308 = 0;

/* ROM 7AC30C; VRAM 802D2D7C. */
InteractionHandler D_802D2D7C_7AC30C[3] = {
    { 9, func_802C96FC_7A2C8C, 0.0f, NULL },
    { 13, func_802C96FC_7A2C8C, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 7AC33C; VRAM 802D2DAC. */
InteractionHandler D_802D2DAC_7AC33C[2] = {
    { 30, func_802C9634_7A2BC4, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 7AC35C; VRAM 802D2DCC. */
RandomState D_802D2DCC_7AC35C[3] = {
    { 100, func_802C96A0_7A2C30 },
    { 100, func_802C97A4_7A2D34 },
    { 0, NULL },
};

/* ROM 7AC374; VRAM 802D2DE4. */
PokemonAnimationSetup D_802D2DE4_7AC374 = { &D_802D2D24_7AC2B4, func_802C95C0_7A2B50, 0, { 0, 0, 0 }, NULL, NULL };

/* ROM 7AC388; VRAM 802D2DF8. */
PokemonInitData D_802D2DF8_7AC388 = { gyarados_model, D_80323520_7FCAB0, renderPokemonModelTypeBFogged, &D_802D2DE4_7AC374, { 2.0f, 2.0f, 2.0f }, { 0.0f, 710.0f, 391.0f }, 128.0f, 37, 0, 0, 0, { 0, 0, 0 } };

/* Bounded original zero alignment/storage: 4 bytes. */
char D_802D2E2C_7AC3BC_padding[4] = "";

/* ROM 7AC3C0; VRAM 802D2E30. */
s32 D_802D2E30_7AC3C0[2] = { 229, 103 };

/* ROM 7AC3C8; VRAM 802D2E38. */
s32 D_802D2E38_7AC3C8[2] = { 228, 101 };

/* ROM 7AC3D0; VRAM 802D2E40. */
s32 D_802D2E40_7AC3D0[2] = { 0, 105 };

/* ROM 7AC3D8; VRAM 802D2E48. */
AnimationHeader D_802D2E48_7AC3D8 = { 0.699999988f, 30.0f, D_80141F80_4383C0, NULL, NULL };

/* ROM 7AC3EC; VRAM 802D2E5C. */
AnimationHeader D_802D2E5C_7AC3EC = { 0.5f, 29.0f, D_80141060_4374A0, D_80142610_438A50, D_802D2E30_7AC3C0 };

/* ROM 7AC400; VRAM 802D2E70. */
AnimationHeader D_802D2E70_7AC400 = { 0.5f, 19.0f, D_80141C70_4380B0, D_80142770_438BB0, NULL };

/* ROM 7AC414; VRAM 802D2E84. */
AnimationHeader D_802D2E84_7AC414 = { 0.5f, 19.0f, D_80141660_437AA0, D_801426C0_438B00, D_802D2E38_7AC3C8 };

/* ROM 7AC428; VRAM 802D2E98. */
AnimationHeader D_802D2E98_7AC428 = { 0.5f, 29.0f, D_80140CE0_437120, D_80142560_4389A0, NULL };

/* ROM 7AC43C; VRAM 802D2EAC. */
AnimationHeader D_802D2EAC_7AC43C = { 0.699999988f, 30.0f, D_80140720_436B60, NULL, D_802D2E40_7AC3D0 };

/* ROM 7AC450; VRAM 802D2EC0. */
RandomState D_802D2EC0_7AC450[3] = {
    { 100, func_802C9DC4_7A3354 },
    { 100, func_802C9EC8_7A3458 },
    { 0, NULL },
};

/* ROM 7AC468; VRAM 802D2ED8. */
InteractionHandler2 D_802D2ED8_7AC468 = { {
    { 16, func_802C9A94_7A3024, 3000.0f, NULL },
    { 58, NULL, 0.0f, NULL },
} };

/* ROM 7AC488; VRAM 802D2EF8. */
InteractionHandler D_802D2EF8_7AC488[2] = {
    { 9, func_802C9BD0_7A3160, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 7AC4A8; VRAM 802D2F18. */
PokemonAnimationSetup D_802D2F18_7AC4A8 = { &D_802D2E98_7AC428, func_802C9958_7A2EE8, 0, { 0, 0, 0 }, NULL, NULL };

/* ROM 7AC4BC; VRAM 802D2F2C. */
PokemonInitData D_802D2F2C_7AC4BC = { geodude_model, D_8032B580_804B10, renderPokemonModelTypeIFogged, &D_802D2F18_7AC4A8, { 2.0f, 2.0f, 2.0f }, { 0.0f, 169.0f, 3.0f }, 45.0f, 37, 0, 0, 0, { 0, 0, 0 } };

/* ROM 7AC4F0; VRAM 802D2F60. */
s32 D_802D2F60_7AC4F0[2] = { 249, 392 };

/* ROM 7AC4F8; VRAM 802D2F68. */
s32 D_802D2F68_7AC4F8[2] = { 250, 119 };

/* ROM 7AC500; VRAM 802D2F70. */
s32 D_802D2F70_7AC500[3] = { 249, 250, 119 };

/* ROM 7AC50C; VRAM 802D2F7C. */
s32 D_802D2F7C_7AC50C[2] = { 0, 119 };

/* ROM 7AC514; VRAM 802D2F84. */
s32 D_802D2F84_7AC514[2] = { 0, 119 };

/* ROM 7AC51C; VRAM 802D2F8C. */
AnimationHeader D_802D2F8C_7AC51C = { 0.5f, 43.0f, D_8014B280_4416C0, NULL, D_802D2F60_7AC4F0 };

/* ROM 7AC530; VRAM 802D2FA0. */
AnimationHeader D_802D2FA0_7AC530 = { 0.5f, 21.0f, D_8014ABC0_441000, NULL, D_802D2F68_7AC4F8 };

/* ROM 7AC544; VRAM 802D2FB4. */
AnimationHeader D_802D2FB4_7AC544 = { 0.5f, 190.0f, D_801470F0_43D530, NULL, D_802D2F70_7AC500 };

/* ROM 7AC558; VRAM 802D2FC8. */
AnimationHeader D_802D2FC8_7AC558 = { 0.5f, 60.0f, D_801462C0_43C700, NULL, D_802D2F7C_7AC50C };

/* ROM 7AC56C; VRAM 802D2FDC. */
AnimationHeader D_802D2FDC_7AC56C = { 0.5f, 60.0f, D_801453E0_43B820, NULL, D_802D2F84_7AC514 };

/* ROM 7AC580; VRAM 802D2FF0. */
GObj* D_802D2FF0_7AC580 = NULL;

/* ROM 7AC584; VRAM 802D2FF4. */
u16 D_802D2FF4_7AC584 = 0;

/* ROM 7AC588; VRAM 802D2FF8. */
InteractionHandler D_802D2FF8_7AC588[2] = {
    { 28, func_802CA020_7A35B0, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 7AC5A8; VRAM 802D3018. */
PokemonAnimationSetup D_802D3018_7AC5A8 = { &D_802D2F8C_7AC51C, func_802C9FD0_7A3560, 0, { 0, 0, 0 }, NULL, NULL };

/* ROM 7AC5BC; VRAM 802D302C. */
PokemonInitData D_802D302C_7AC5BC = { dragonite_model, NULL, renderPokemonModelTypeIFogged, &D_802D3018_7AC5A8, { 2.20000005f, 2.20000005f, 2.20000005f }, { 0.0f, 277.0f, 0.0f }, 142.0f, 37, 0, 0, 0, { 0, 0, 0 } };

/* ROM 7AC5F0; VRAM 802D3060. */
s32 D_802D3060_7AC5F0[3] = { 248, 386, 107 };

/* ROM 7AC5FC; VRAM 802D306C. */
s32 D_802D306C_7AC5FC[3] = { 0, 386, 107 };

/* ROM 7AC608; VRAM 802D3078. */
s32 D_802D3078_7AC608[3] = { 248, 386, 107 };

/* ROM 7AC614; VRAM 802D3084. */
AnimationHeader D_802D3084_7AC614 = { 0.5f, 50.0f, D_8015CED0_453310, D_8015E720_454B60, D_802D3060_7AC5F0 };

/* ROM 7AC628; VRAM 802D3098. */
AnimationHeader D_802D3098_7AC628 = { 0.649999976f, 45.0f, D_8015DA00_453E40, NULL, D_802D306C_7AC5FC };

/* ROM 7AC63C; VRAM 802D30AC. */
AnimationHeader D_802D30AC_7AC63C = { 0.400000006f, 65.0f, D_8015DCE0_454120, NULL, D_802D3078_7AC608 };

/* ROM 7AC650; VRAM 802D30C0. */
RandomState D_802D30C0_7AC650[4] = {
    { 20, func_802CA2BC_7A384C },
    { 30, func_802CA2F4_7A3884 },
    { 50, func_802CA32C_7A38BC },
    { 0, NULL },
};

/* ROM 7AC670; VRAM 802D30E0. */
Vec3f D_802D30E0_7AC670 = { 0.0f, 0.0f, 0.0f };

/* ROM 7AC67C; VRAM 802D30EC. */
PokemonAnimationSetup D_802D30EC_7AC67C = { &D_802D3084_7AC614, func_802CA270_7A3800, 0, { 0, 0, 0 }, NULL, NULL };

/* ROM 7AC690; VRAM 802D3100. */
PokemonInitData D_802D3100_7AC690 = { dratini_model, D_80337D80_811310, renderPokemonModelTypeIFogged, &D_802D30EC_7AC67C, { 1.5f, 1.5f, 1.5f }, { 0.0f, 0.0f, 0.0f }, 50.0f, 37, 0, 0, 0, { 0, 0, 0 } };

/* Bounded original zero alignment/storage: 12 bytes. */
char D_802D3134_7AC6C4_padding[12] = "";

/* ROM 7AC6D0; VRAM 802D3140. */
s32 D_802D3140_7AC6D0[1] = { 230 };

/* ROM 7AC6D4; VRAM 802D3144. */
s32 D_802D3144_7AC6D4[2] = { 232, 374 };

/* ROM 7AC6DC; VRAM 802D314C. */
s32 D_802D314C_7AC6DC[2] = { 233, 117 };

/* ROM 7AC6E4; VRAM 802D3154. */
s32 D_802D3154_7AC6E4[2] = { 231, 108 };

/* ROM 7AC6EC; VRAM 802D315C. */
AnimationHeader D_802D315C_7AC6EC = { 0.5f, 40.0f, D_80164440_45A880, D_80169A60_45FEA0, NULL };

/* ROM 7AC700; VRAM 802D3170. */
AnimationHeader D_802D3170_7AC700 = { 0.400000006f, 32.0f, D_801638E0_459D20, NULL, NULL };

/* ROM 7AC714; VRAM 802D3184. */
AnimationHeader D_802D3184_7AC714 = { 1.29999995f, 32.0f, D_80163E80_45A2C0, NULL, NULL };

/* ROM 7AC728; VRAM 802D3198. */
AnimationHeader D_802D3198_7AC728 = { 0.5f, 52.0f, D_801672A0_45D6E0, D_80169C20_460060, NULL };

/* ROM 7AC73C; VRAM 802D31AC. */
AnimationHeader D_802D31AC_7AC73C = { 0.449999988f, 53.0f, D_80167E40_45E280, D_80169C90_4600D0, D_802D3140_7AC6D0 };

/* ROM 7AC750; VRAM 802D31C0. */
AnimationHeader D_802D31C0_7AC750 = { 0.5f, 48.0f, D_80164BB0_45AFF0, D_80169B00_45FF40, NULL };

/* ROM 7AC764; VRAM 802D31D4. */
AnimationHeader D_802D31D4_7AC764 = { 0.5f, 58.0f, D_80166600_45CA40, D_80169BC0_460000, NULL };

/* ROM 7AC778; VRAM 802D31E8. */
AnimationHeader D_802D31E8_7AC778 = { 1.0f, 64.0f, D_801690E0_45F520, NULL, D_802D3144_7AC6D4 };

/* ROM 7AC78C; VRAM 802D31FC. */
AnimationHeader D_802D31FC_7AC78C = { 0.5f, 37.0f, D_80168870_45ECB0, NULL, D_802D314C_7AC6DC };

/* ROM 7AC7A0; VRAM 802D3210. */
AnimationHeader D_802D3210_7AC7A0 = { 0.5f, 105.0f, D_80165100_45B540, NULL, D_802D3154_7AC6E4 };

/* ROM 7AC7B4; VRAM 802D3224. */
InteractionHandler D_802D3224_7AC7B4[5] = {
    { 9, func_802CAC2C_7A41BC, 0.0f, NULL },
    { 13, func_802CACE4_7A4274, 0.0f, NULL },
    { 14, func_802CAD54_7A42E4, 0.0f, NULL },
    { 15, func_802CB008_7A4598, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 7AC804; VRAM 802D3274. */
RandomState D_802D3274_7AC804[4] = {
    { 100, func_802CA9BC_7A3F4C },
    { 100, func_802CAA2C_7A3FBC },
    { 100, func_802CAB2C_7A40BC },
    { 0, NULL },
};

/* ROM 7AC824; VRAM 802D3294. */
InteractionHandler2 D_802D3294_7AC824 = { {
    { 16, func_802CA8A4_7A3E34, 3500.0f, NULL },
    { 58, NULL, 0.0f, NULL },
} };

/* ROM 7AC844; VRAM 802D32B4. */
InteractionHandler D_802D32B4_7AC844[2] = {
    { 20, func_802CA948_7A3ED8, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 7AC864; VRAM 802D32D4. */
InteractionHandler D_802D32D4_7AC864[3] = {
    { 9, func_802CAC2C_7A41BC, 0.0f, NULL },
    { 13, func_802CACE4_7A4274, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 7AC894; VRAM 802D3304. */
InteractionHandler D_802D3304_7AC894[3] = {
    { 9, func_802CAC2C_7A41BC, 0.0f, NULL },
    { 13, func_802CACE4_7A4274, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 7AC8C4; VRAM 802D3334. */
InteractionHandler D_802D3334_7AC8C4[4] = {
    { 9, func_802CAC2C_7A41BC, 0.0f, NULL },
    { 13, func_802CACE4_7A4274, 0.0f, NULL },
    { 14, func_802CAD54_7A42E4, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 7AC904; VRAM 802D3374. */
InteractionHandler D_802D3374_7AC904[4] = {
    { 9, func_802CAC2C_7A41BC, 0.0f, NULL },
    { 13, func_802CACE4_7A4274, 0.0f, NULL },
    { 14, func_802CAF54_7A44E4, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 7AC944; VRAM 802D33B4. */
InteractionHandler3 D_802D33B4_7AC944 = { {
    { 9, func_802CAC2C_7A41BC, 0.0f, NULL },
    { 13, func_802CACE4_7A4274, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
} };

/* ROM 7AC974; VRAM 802D33E4. */
PokemonAnimationSetup D_802D33E4_7AC974 = { &D_802D315C_7AC6EC, func_802CA768_7A3CF8, 0, { 0, 0, 0 }, NULL, NULL };

/* ROM 7AC988; VRAM 802D33F8. */
PokemonInitData D_802D33F8_7AC988 = { sandshrew_model, D_8033A0C0_813650, renderPokemonModelTypeIFogged, &D_802D33E4_7AC974, { 2.0f, 2.0f, 2.0f }, { 0.0f, 110.0f, 0.0f }, 34.0f, 37, 0, 0, 0, { 0, 0, 0 } };

/* Bounded original zero alignment/storage: 4 bytes. */
char D_802D342C_7AC9BC_padding[4] = "";

/* ROM 7AC9C0; VRAM 802D3430. */
s32 D_802D3430_7AC9C0[1] = { 235 };

/* ROM 7AC9C4; VRAM 802D3434. */
s32 D_802D3434_7AC9C4[1] = { 234 };

/* ROM 7AC9C8; VRAM 802D3438. */
s32 D_802D3438_7AC9C8[1] = { 236 };

/* ROM 7AC9CC; VRAM 802D343C. */
s32 D_802D343C_7AC9CC[2] = { 237, 366 };

/* ROM 7AC9D4; VRAM 802D3444. */
s32 D_802D3444_7AC9D4[2] = { 0, 116 };

/* ROM 7AC9DC; VRAM 802D344C. */
s32 D_802D344C_7AC9DC[1] = { 237 };

/* ROM 7AC9E0; VRAM 802D3450. */
AnimationHeader D_802D3450_7AC9E0 = { 0.5f, 30.0f, D_801803B0_4767F0, D_801865D0_47CA10, NULL };

/* ROM 7AC9F4; VRAM 802D3464. */
AnimationHeader D_802D3464_7AC9F4 = { 0.5f, 52.0f, D_80182400_478840, D_801867B0_47CBF0, NULL };

/* ROM 7ACA08; VRAM 802D3478. */
AnimationHeader D_802D3478_7ACA08 = { 0.5f, 48.0f, D_80183180_4795C0, D_80186830_47CC70, D_802D3430_7AC9C0 };

/* ROM 7ACA1C; VRAM 802D348C. */
AnimationHeader D_802D348C_7ACA1C = { 0.5f, 30.0f, D_8017E6C0_474B00, D_80186440_47C880, NULL };

/* ROM 7ACA30; VRAM 802D34A0. */
AnimationHeader D_802D34A0_7ACA30 = { 0.5f, 16.0f, D_8017EB60_474FA0, NULL, NULL };

/* ROM 7ACA44; VRAM 802D34B4. */
AnimationHeader D_802D34B4_7ACA44 = { 0.5f, 60.0f, D_80184470_47A8B0, D_80186960_47CDA0, NULL };

/* ROM 7ACA58; VRAM 802D34C8. */
AnimationHeader D_802D34C8_7ACA58 = { 0.5f, 40.0f, D_80185B30_47BF70, D_80186A80_47CEC0, D_802D3434_7AC9C4 };

/* ROM 7ACA6C; VRAM 802D34DC. */
AnimationHeader D_802D34DC_7ACA6C = { 0.5f, 30.0f, D_80181510_477950, NULL, NULL };

/* ROM 7ACA80; VRAM 802D34F0. */
AnimationHeader D_802D34F0_7ACA80 = { 0.5f, 52.0f, D_80183AC0_479F00, D_801868C0_47CD00, D_802D3438_7AC9C8 };

/* ROM 7ACA94; VRAM 802D3504. */
AnimationHeader D_802D3504_7ACA94 = { 0.5f, 40.0f, D_8017EFF0_475430, D_801864B0_47C8F0, D_802D343C_7AC9CC };

/* ROM 7ACAA8; VRAM 802D3518. */
AnimationHeader D_802D3518_7ACAA8 = { 0.5f, 44.0f, D_80185230_47B670, D_801869E0_47CE20, NULL };

/* ROM 7ACABC; VRAM 802D352C. */
AnimationHeader D_802D352C_7ACABC = { 0.5f, 36.0f, D_801818B0_477CF0, D_801866D0_47CB10, D_802D3444_7AC9D4 };

/* ROM 7ACAD0; VRAM 802D3540. */
AnimationHeader D_802D3540_7ACAD0 = { 0.5f, 40.0f, D_801821A0_4785E0, NULL, NULL };

/* ROM 7ACAE4; VRAM 802D3554. */
AnimationHeader D_802D3554_7ACAE4 = { 0.5f, 80.0f, D_8017F710_475B50, D_80186540_47C980, D_802D344C_7AC9DC };

/* ROM 7ACAF8; VRAM 802D3568. */
InteractionHandler D_802D3568_7ACAF8[10] = {
    { 9, func_802CB474_7A4A04, 0.0f, NULL },
    { 10, func_802CB474_7A4A04, 0.0f, NULL },
    { 13, func_802CB5AC_7A4B3C, 0.0f, NULL },
    { 26, func_802CB194_7A4724, 0.0f, NULL },
    { 14, func_802CB614_7A4BA4, 0.0f, NULL },
    { 15, func_802CB7F4_7A4D84, 0.0f, NULL },
    { 5, func_802CB818_7A4DA8, 0.0f, NULL },
    { 6, func_802CB818_7A4DA8, 0.0f, NULL },
    { 7, func_802CB818_7A4DA8, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 7ACB98; VRAM 802D3608. */
RandomState D_802D3608_7ACB98[6] = {
    { 200, func_802CB110_7A46A0 },
    { 100, func_802CB394_7A4924 },
    { 100, func_802CB404_7A4994 },
    { 300, func_802CB294_7A4824 },
    { 200, func_802CB194_7A4724 },
    { 0, NULL },
};

/* ROM 7ACBC8; VRAM 802D3638. */
f32 D_802D3638_7ACBC8 = 0.0f;

/* ROM 7ACBCC; VRAM 802D363C. */
InteractionHandler D_802D363C_7ACBCC[3] = {
    { 9, func_802CB474_7A4A04, 0.0f, NULL },
    { 13, func_802CB5AC_7A4B3C, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 7ACBFC; VRAM 802D366C. */
InteractionHandler D_802D366C_7ACBFC[3] = {
    { 9, func_802CB474_7A4A04, 0.0f, NULL },
    { 13, func_802CB5AC_7A4B3C, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 7ACC2C; VRAM 802D369C. */
InteractionHandler D_802D369C_7ACC2C[3] = {
    { 9, func_802CB474_7A4A04, 0.0f, NULL },
    { 13, func_802CB5AC_7A4B3C, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 7ACC5C; VRAM 802D36CC. */
InteractionHandler D_802D36CC_7ACC5C[4] = {
    { 16, func_802CB9BC_7A4F4C, 200.0f, NULL },
    { 9, func_802CBD74_7A5304, 0.0f, NULL },
    { 13, func_802CBC74_7A5204, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 7ACC9C; VRAM 802D370C. */
InteractionHandler D_802D370C_7ACC9C[2] = {
    { 16, func_802CB92C_7A4EBC, 700.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 7ACCBC; VRAM 802D372C. */
InteractionHandler D_802D372C_7ACCBC[2] = {
    { 16, func_802CC104_7A5694, 1700.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 7ACCDC; VRAM 802D374C. */
InteractionHandler D_802D374C_7ACCDC[2] = {
    { 9, func_802CC4DC_7A5A6C, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 7ACCFC; VRAM 802D376C. */
InteractionHandler D_802D376C_7ACCFC[2] = {
    { 16, func_802CC320_7A58B0, 1500.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 7ACD1C; VRAM 802D378C. */
InteractionHandler D_802D378C_7ACD1C[2] = {
    { 9, func_802CC514_7A5AA4, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 7ACD3C; VRAM 802D37AC. */
PokemonAnimationSetup D_802D37AC_7ACD3C = { &D_802D3450_7AC9E0, func_802CB080_7A4610, 0, { 0, 0, 0 }, NULL, NULL };

/* ROM 7ACD50; VRAM 802D37C0. */
PokemonInitData D_802D37C0_7ACD50 = { squirtle_model, D_80349640_822BD0, renderPokemonModelTypeBFogged, &D_802D37AC_7ACD3C, { 2.20000005f, 2.20000005f, 2.20000005f }, { 0.0f, 95.0f, 0.0f }, 25.0f, 37, 0, 0, 0, { 0, 0, 0 } };

/* Bounded original zero alignment/storage: 12 bytes. */
char D_802D37F4_7ACD84_padding[12] = "";

/* ROM 7ACD90; VRAM 802D3800. */
s32 D_802D3800_7ACD90[1] = { 345 };

/* ROM 7ACD94; VRAM 802D3804. */
s32 D_802D3804_7ACD94[1] = { 345 };

/* ROM 7ACD98; VRAM 802D3808. */
AnimationHeader D_802D3808_7ACD98 = { 0.699999988f, 93.0f, D_8013E410_434850, NULL, NULL };

/* ROM 7ACDAC; VRAM 802D381C. */
AnimationHeader D_802D381C_7ACDAC = { 0.699999988f, 93.0f, D_8013DD40_434180, D_8013F550_435990, D_802D3800_7ACD90 };

/* ROM 7ACDC0; VRAM 802D3830. */
AnimationHeader D_802D3830_7ACDC0 = { 0.899999976f, 75.0f, D_8013EAE0_434F20, D_8013F5E0_435A20, D_802D3804_7ACD94 };

/* ROM 7ACDD4; VRAM 802D3844. */
f32 D_802D3844_7ACDD4 = 1.0f;

/* ROM 7ACDD8; VRAM 802D3848. */
s32 D_802D3848_7ACDD8 = 0;

/* ROM 7ACDDC; VRAM 802D384C. */
f32 D_802D384C_7ACDDC = 0.0f;

/* ROM 7ACDE0; VRAM 802D3850. */
InteractionHandler D_802D3850_7ACDE0[3] = {
    { 9, func_802CCD80_7A6310, 0.0f, NULL },
    { 13, func_802CCD80_7A6310, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 7ACE10; VRAM 802D3880. */
InteractionHandler2 D_802D3880_7ACE10 = { {
    { 16, func_802CCBF8_7A6188, 6000.0f, NULL },
    { 58, NULL, 0.0f, NULL },
} };

/* ROM 7ACE30; VRAM 802D38A0. */
InteractionHandler D_802D38A0_7ACE30[4] = {
    { 24, func_802CCDDC_7A636C, 0.0f, NULL },
    { 9, func_802CCCFC_7A628C, 0.0f, NULL },
    { 13, func_802CCCFC_7A628C, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 7ACE70; VRAM 802D38E0. */
InteractionHandler D_802D38E0_7ACE70[2] = {
    { 24, func_802CCDDC_7A636C, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 7ACE90; VRAM 802D3900. */
PokemonAnimationSetup D_802D3900_7ACE90 = { &D_802D3808_7ACD98, func_802CCA70_7A6000, 0, { 0, 0, 0 }, NULL, NULL };

/* ROM 7ACEA4; VRAM 802D3914. */
PokemonInitData D_802D3914_7ACEA4 = { staryu_model, D_803272B0_800840, renderPokemonModelTypeIFogged, &D_802D3900_7ACE90, { 2.0f, 2.0f, 2.0f }, { 0.0f, -5.0f, 0.0f }, 40.0f, 37, 0, 0, 0, { 0, 0, 0 } };

/* Bounded original zero alignment/storage: 8 bytes. */
char D_802D3948_7ACED8_padding[8] = "";

/* ROM 7ACEE0; VRAM 802D3950. */
s32 D_802D3950_7ACEE0[1] = { 303 };

/* ROM 7ACEE4; VRAM 802D3954. */
s32 D_802D3954_7ACEE4[1] = { 303 };

/* ROM 7ACEE8; VRAM 802D3958. */
AnimationHeader D_802D3958_7ACEE8 = { 0.800000012f, 80.0f, D_80173E70_46A2B0, D_80174DD0_46B210, NULL };

/* ROM 7ACEFC; VRAM 802D396C. */
AnimationHeader D_802D396C_7ACEFC = { 0.800000012f, 80.0f, D_80173810_469C50, D_80174CE0_46B120, D_802D3950_7ACEE0 };

/* ROM 7ACF10; VRAM 802D3980. */
AnimationHeader D_802D3980_7ACF10 = { 0.800000012f, 80.0f, D_801744D0_46A910, D_80174E40_46B280, D_802D3954_7ACEE4 };

/* ROM 7ACF24; VRAM 802D3994. */
InteractionHandler D_802D3994_7ACF24[2] = {
    { 9, NULL, 0.0f, func_802CDA94_7A7024 },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 7ACF44; VRAM 802D39B4. */
RandomStates3 D_802D39B4_7ACF44 = { {
    { 100, func_802CD8A4_7A6E34 },
    { 100, func_802CD8DC_7A6E6C },
    { 0, NULL },
} };

/* ROM 7ACF5C; VRAM 802D39CC. */
s32 D_802D39CC_7ACF5C = 0;

/* ROM 7ACF60; VRAM 802D39D0. */
InteractionHandler2 D_802D39D0_7ACF60 = { {
    { 34, func_802CDCFC_7A728C, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
} };

/* ROM 7ACF80; VRAM 802D39F0. */
InteractionHandler2 D_802D39F0_7ACF80 = { {
    { 35, func_802CDCFC_7A728C, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
} };

/* ROM 7ACFA0; VRAM 802D3A10. */
InteractionHandler2 D_802D3A10_7ACFA0 = { {
    { 36, func_802CDCFC_7A728C, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
} };

/* ROM 7ACFC0; VRAM 802D3A30. */
PokemonAnimationSetup D_802D3A30_7ACFC0 = { &D_802D3958_7ACEE8, func_802CD7C0_7A6D50, 0, { 0, 0, 0 }, NULL, NULL };

/* ROM 7ACFD4; VRAM 802D3A44. */
PokemonInitData D_802D3A44_7ACFD4 = { starmie_model, D_80341910_81AEA0, renderPokemonModelTypeIFogged, &D_802D3A30_7ACFC0, { 2.20000005f, 2.20000005f, 2.20000005f }, { 0.0f, 10.0f, 0.0f }, 63.0f, 37, 0, 0, 0, { 0, 0, 0 } };

/* Bounded original zero alignment/storage: 8 bytes. */
char D_802D3A78_7AD008_padding[8] = "";

/* ROM 7AD010; VRAM 802D3A80. */
AnimationHeader D_802D3A80_7AD010 = { 0.5f, 100.0f, D_801198F0_40FD20, D_80119940_40FD70, NULL };

/* ROM 7AD024; VRAM 802D3A94. */
AnimationHeader D_802D3A94_7AD024 = { 0.75f, 100.0f, D_801198F0_40FD20, D_80119940_40FD70, NULL };

/* ROM 7AD038; VRAM 802D3AA8. */
AnimationHeader D_802D3AA8_7AD038 = { 1.0f, 100.0f, D_801198F0_40FD20, D_80119940_40FD70, NULL };

/* ROM 7AD04C; VRAM 802D3ABC. */
AnimationHeader D_802D3ABC_7AD04C = { 1.5f, 100.0f, D_801198F0_40FD20, D_80119940_40FD70, NULL };

/* ROM 7AD060; VRAM 802D3AD0. */
AnimationHeader D_802D3AD0_7AD060 = { 2.0f, 100.0f, D_801198F0_40FD20, D_80119940_40FD70, NULL };

/* ROM 7AD074; VRAM 802D3AE4. */
AnimationHeader D_802D3AE4_7AD074 = { 0.5f, 10.0f, D_801197F0_40FC20, D_80119830_40FC60, NULL };

/* ROM 7AD088; VRAM 802D3AF8. */
AnimationHeader D_802D3AF8_7AD088 = { 0.75f, 10.0f, D_801197F0_40FC20, D_80119830_40FC60, NULL };

/* ROM 7AD09C; VRAM 802D3B0C. */
AnimationHeader D_802D3B0C_7AD09C = { 1.0f, 10.0f, D_801197F0_40FC20, D_80119830_40FC60, NULL };

/* ROM 7AD0B0; VRAM 802D3B20. */
AnimationHeader D_802D3B20_7AD0B0 = { 1.5f, 10.0f, D_801197F0_40FC20, D_80119830_40FC60, NULL };

/* ROM 7AD0C4; VRAM 802D3B34. */
GObj* D_802D3B34_7AD0C4 = NULL;

/* ROM 7AD0C8; VRAM 802D3B38. */
InteractionHandler D_802D3B38_7AD0C8[3] = {
    { 37, func_802CDEFC_7A748C, 0.0f, NULL },
    { 43, func_802CDF68_7A74F8, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 7AD0F8; VRAM 802D3B68. */
InteractionHandler D_802D3B68_7AD0F8[3] = {
    { 43, func_802CDFFC_7A758C, 0.0f, NULL },
    { 37, func_802CDF68_7A74F8, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 7AD128; VRAM 802D3B98. */
InteractionHandler D_802D3B98_7AD128[3] = {
    { 43, func_802CE090_7A7620, 0.0f, NULL },
    { 37, func_802CDFFC_7A758C, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 7AD158; VRAM 802D3BC8. */
InteractionHandler D_802D3BC8_7AD158[3] = {
    { 43, func_802CE124_7A76B4, 0.0f, NULL },
    { 37, func_802CE090_7A7620, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 7AD188; VRAM 802D3BF8. */
PokemonAnimationSetup D_802D3BF8_7AD188 = { &D_802D3A80_7AD010, func_802CDE80_7A7410, 0, { 0, 0, 0 }, NULL, NULL };

/* ROM 7AD19C; VRAM 802D3C0C. */
PokemonInitData D_802D3C0C_7AD19C = { D_80119330_40F760, D_80119210_40F640, renderModelTypeBFogged, &D_802D3BF8_7AD188, { 10.0f, 10.0f, 10.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f, 0, 0, 0, 0, { 0, 0, 0 } };

/* ROM 7AD1D0; VRAM 802D3C40. */
s32 D_802D3C40_7AD1D0[2] = { 0, 375 };

/* ROM 7AD1D8; VRAM 802D3C48. */
s32 D_802D3C48_7AD1D8[2] = { 0, 388 };

/* ROM 7AD1E0; VRAM 802D3C50. */
s32 D_802D3C50_7AD1E0[3] = { 0, 394, 375 };

/* ROM 7AD1EC; VRAM 802D3C5C. */
AnimationHeader D_802D3C5C_7AD1EC = { 0.300000012f, 60.0f, D_8016C3F0_462830, D_80171560_4679A0, NULL };

/* ROM 7AD200; VRAM 802D3C70. */
AnimationHeader D_802D3C70_7AD200 = { 1.0f, 60.0f, D_8016AF90_4613D0, D_80171420_467860, NULL };

/* ROM 7AD214; VRAM 802D3C84. */
AnimationHeader D_802D3C84_7AD214 = { 2.0f, 60.0f, D_8016BB80_461FC0, D_801714D0_467910, NULL };

/* ROM 7AD228; VRAM 802D3C98. */
AnimationHeader D_802D3C98_7AD228 = { 1.0f, 85.0f, D_8016DF30_464370, D_80171710_467B50, NULL };

/* ROM 7AD23C; VRAM 802D3CAC. */
AnimationHeader D_802D3CAC_7AD23C = { 0.600000024f, 37.0f, D_8016EBE0_465020, D_801717D0_467C10, NULL };

/* ROM 7AD250; VRAM 802D3CC0. */
AnimationHeader D_802D3CC0_7AD250 = { 0.699999988f, 8.0f, D_8016C960_462DA0, D_801715F0_467A30, NULL };

/* ROM 7AD264; VRAM 802D3CD4. */
AnimationHeader D_802D3CD4_7AD264 = { 0.349999994f, 30.0f, D_8016D3F0_463830, D_80171670_467AB0, NULL };

/* ROM 7AD278; VRAM 802D3CE8. */
AnimationHeader D_802D3CE8_7AD278 = { 0.319999993f, 34.0f, D_8016FC50_466090, NULL, D_802D3C40_7AD1D0 };

/* ROM 7AD28C; VRAM 802D3CFC. */
AnimationHeader D_802D3CFC_7AD28C = { 0.379999995f, 30.0f, D_8016F230_465670, NULL, D_802D3C48_7AD1D8 };

/* ROM 7AD2A0; VRAM 802D3D10. */
AnimationHeader D_802D3D10_7AD2A0 = { 0.400000006f, 45.0f, D_8016CD10_463150, NULL, D_802D3C50_7AD1E0 };

/* ROM 7AD2B4; VRAM 802D3D24. */
InteractionHandler D_802D3D24_7AD2B4[6] = {
    { 9, func_802CE6B0_7A7C40, 0.0f, NULL },
    { 13, func_802CE768_7A7CF8, 0.0f, NULL },
    { 14, func_802CE7D8_7A7D68, 0.0f, NULL },
    { 26, func_802CE6B0_7A7C40, 0.0f, NULL },
    { 15, func_802CEA34_7A7FC4, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 7AD314; VRAM 802D3D84. */
RandomState D_802D3D84_7AD314[4] = {
    { 100, func_802CE440_7A79D0 },
    { 100, func_802CE4B0_7A7A40 },
    { 100, func_802CE5B0_7A7B40 },
    { 0, NULL },
};

/* ROM 7AD334; VRAM 802D3DA4. */
InteractionHandler2 D_802D3DA4_7AD334 = { {
    { 16, func_802CE328_7A78B8, 2500.0f, NULL },
    { 58, NULL, 0.0f, NULL },
} };

/* ROM 7AD354; VRAM 802D3DC4. */
InteractionHandler D_802D3DC4_7AD354[2] = {
    { 39, func_802CE3CC_7A795C, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 7AD374; VRAM 802D3DE4. */
InteractionHandler D_802D3DE4_7AD374[3] = {
    { 9, func_802CE6B0_7A7C40, 0.0f, NULL },
    { 13, func_802CE768_7A7CF8, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 7AD3A4; VRAM 802D3E14. */
InteractionHandler D_802D3E14_7AD3A4[3] = {
    { 9, func_802CE6B0_7A7C40, 0.0f, NULL },
    { 13, func_802CE768_7A7CF8, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 7AD3D4; VRAM 802D3E44. */
InteractionHandler D_802D3E44_7AD3D4[5] = {
    { 9, func_802CE6B0_7A7C40, 0.0f, NULL },
    { 13, func_802CE768_7A7CF8, 0.0f, NULL },
    { 14, func_802CE7D8_7A7D68, 0.0f, NULL },
    { 26, func_802CE6B0_7A7C40, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 7AD424; VRAM 802D3E94. */
InteractionHandler D_802D3E94_7AD424[5] = {
    { 9, func_802CE6B0_7A7C40, 0.0f, NULL },
    { 13, func_802CE768_7A7CF8, 0.0f, NULL },
    { 14, func_802CE978_7A7F08, 0.0f, NULL },
    { 26, func_802CE6B0_7A7C40, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 7AD474; VRAM 802D3EE4. */
InteractionHandler4 D_802D3EE4_7AD474 = { {
    { 9, func_802CE6B0_7A7C40, 0.0f, NULL },
    { 13, func_802CE768_7A7CF8, 0.0f, NULL },
    { 26, func_802CE6B0_7A7C40, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
} };

/* ROM 7AD4B4; VRAM 802D3F24. */
PokemonAnimationSetup D_802D3F24_7AD4B4 = { &D_802D3C5C_7AD1EC, func_802CE200_7A7790, 0, { 0, 0, 0 }, NULL, NULL };

/* ROM 7AD4C8; VRAM 802D3F38. */
PokemonInitData D_802D3F38_7AD4C8 = { sandslash_model, D_8033D3F8_816988, renderPokemonModelTypeIFogged, &D_802D3F24_7AD4B4, { 2.0f, 2.0f, 2.0f }, { 0.0f, 178.0f, 20.0f }, 50.0f, 37, 0, 0, 0, { 0, 0, 0 } };

/* Bounded original zero alignment/storage: 4 bytes. */
char D_802D3F6C_7AD4FC_padding[4] = "";

/* ROM 7AD500; VRAM 802D3F70. */
s32 D_802D3F70_7AD500[2] = { 240, 109 };

/* ROM 7AD508; VRAM 802D3F78. */
s32 D_802D3F78_7AD508[1] = { 241 };

/* ROM 7AD50C; VRAM 802D3F7C. */
s32 D_802D3F7C_7AD50C[2] = { 242, 115 };

/* ROM 7AD514; VRAM 802D3F84. */
s32 D_802D3F84_7AD514[2] = { 242, 115 };

/* ROM 7AD51C; VRAM 802D3F8C. */
AnimationHeader D_802D3F8C_7AD51C = { 0.449999988f, 74.0f, D_80156410_44C850, D_80159880_44FCC0, D_802D3F70_7AD500 };

/* ROM 7AD530; VRAM 802D3FA0. */
AnimationHeader D_802D3FA0_7AD530 = { 0.400000006f, 20.0f, D_801529B0_448DF0, D_80159660_44FAA0, D_802D3F78_7AD508 };

/* ROM 7AD544; VRAM 802D3FB4. */
AnimationHeader D_802D3FB4_7AD544 = { 0.400000006f, 70.0f, D_80154C50_44B090, D_801597C0_44FC00, D_802D3F7C_7AD50C };

/* ROM 7AD558; VRAM 802D3FC8. */
AnimationHeader D_802D3FC8_7AD558 = { 0.400000006f, 65.0f, D_80153490_4498D0, D_80159700_44FB40, D_802D3F84_7AD514 };

/* ROM 7AD56C; VRAM 802D3FDC. */
AnimationHeader D_802D3FDC_7AD56C = { 0.300000012f, 30.0f, D_80159220_44F660, D_80159940_44FD80, NULL };

/* ROM 7AD580; VRAM 802D3FF0. */
GObj* D_802D3FF0_7AD580 = NULL;

/* ROM 7AD584; VRAM 802D3FF4. */
GObj* D_802D3FF4_7AD584 = NULL;

/* ROM 7AD588; VRAM 802D3FF8. */
s32 D_802D3FF8_7AD588 = 0;

/* ROM 7AD58C; VRAM 802D3FFC. */
InteractionHandler D_802D3FFC_7AD58C[2] = {
    { 33, func_802CEB9C_7A812C, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 7AD5AC; VRAM 802D401C. */
InteractionHandler D_802D401C_7AD5AC[3] = {
    { 9, func_802CF07C_7A860C, 0.0f, NULL },
    { 13, func_802CEFB8_7A8548, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 7AD5DC; VRAM 802D404C. */
InteractionHandler2 D_802D404C_7AD5DC = { {
    { 9, func_802CF07C_7A860C, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
} };

/* ROM 7AD5FC; VRAM 802D406C. */
f32 D_802D406C_7AD5FC = 0.0f;

/* ROM 7AD600; VRAM 802D4070. */
InteractionHandler D_802D4070_7AD600[3] = {
    { 9, func_802CF3F8_7A8988, 0.0f, NULL },
    { 13, func_802CF48C_7A8A1C, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 7AD630; VRAM 802D40A0. */
RandomState D_802D40A0_7AD630[2] = {
    { 10, func_802CF388_7A8918 },
    { 0, NULL },
};

/* ROM 7AD640; VRAM 802D40B0. */
InteractionHandler D_802D40B0_7AD640[2] = {
    { 33, func_802CF594_7A8B24, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 7AD660; VRAM 802D40D0. */
InteractionHandler D_802D40D0_7AD660[4] = {
    { 33, func_802CF6CC_7A8C5C, 0.0f, NULL },
    { 13, func_802CF720_7A8CB0, 0.0f, NULL },
    { 9, func_802CF794_7A8D24, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 7AD6A0; VRAM 802D4110. */
PokemonAnimationSetup D_802D4110_7AD6A0 = { &D_802D3F8C_7AD51C, func_802CEAA0_7A8030, 0, { 0, 0, 0 }, NULL, NULL };

/* ROM 7AD6B4; VRAM 802D4124. */
PokemonInitData D_802D4124_7AD6B4 = { mankey_model, D_80333890_80CE20, renderPokemonModelTypeIFogged, &D_802D4110_7AD6A0, { 2.0f, 2.0f, 2.0f }, { 0.0f, 109.0f, 0.0f }, 27.0f, 5, 0, 0, 0, { 0, 0, 0 } };

/* Bounded original zero alignment/storage: 8 bytes. */
char D_802D4158_7AD6E8_padding[8] = "";

/* ROM 7AD6F0; VRAM 802D4160. */
s32 D_802D4160_7AD6F0[2] = { 0, 42 };

/* ROM 7AD6F8; VRAM 802D4168. */
AnimationHeader D_802D4168_7AD6F8 = { 0.5f, 100.0f, D_80118DD0_40F200, NULL, NULL };

/* ROM 7AD70C; VRAM 802D417C. */
AnimationHeader D_802D417C_7AD70C = { 0.5f, 100.0f, D_80118D50_40F180, NULL, NULL };

/* ROM 7AD720; VRAM 802D4190. */
AnimationHeader D_802D4190_7AD720 = { 0.75f, 59.0f, D_80118E50_40F280, D_80119000_40F430, D_802D4160_7AD6F0 };

/* ROM 7AD734; VRAM 802D41A4. */
GObj* D_802D41A4_7AD734 = NULL;

/* ROM 7AD738; VRAM 802D41A8. */
InteractionHandler D_802D41A8_7AD738[2] = {
    { 29, func_802CF8BC_7A8E4C, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 7AD758; VRAM 802D41C8. */
Vec3f D_802D41C8_7AD758 = { 0.0f, 0.0f, 0.0f };

/* ROM 7AD764; VRAM 802D41D4. */
PokemonAnimationSetup D_802D41D4_7AD764 = { &D_802D4168_7AD6F8, func_802CF840_7A8DD0, 0, { 0, 0, 0 }, NULL, NULL };

/* ROM 7AD778; VRAM 802D41E8. */
PokemonInitData D_802D41E8_7AD778 = { D_80118820_40EC50, D_80118780_40EBB0, renderModelTypeBFogged, &D_802D41D4_7AD764, { 2.0f, 2.0f, 2.0f }, { 0.0f, -42.0f, 0.0f }, 27.0f, 0, 0, 0, 0, { 0, 0, 0 } };

/* Bounded original zero alignment/storage: 4 bytes. */
char D_802D421C_7AD7AC_padding[4] = "";

/* ROM 7AD7B0; VRAM 802D4220. */
AnimationHeader D_802D4220_7AD7B0 = { 0.0f, 100.0f, D_8011C490_4128C0, NULL, NULL };

/* Bounded original zero alignment/storage: 4 bytes. */
char D_802D4234_7AD7C4_padding[4] = "";

/* ROM 7AD7C8; VRAM 802D4238. */
Gfx D_802D4238_7AD7C8[1] = {
#include "build/assets/native/gfx/D_802D4238_7AD7C8.dl.inc.c"
};

/* ROM 7AD7D0; VRAM 802D4240. */
u8 D_802D4240_7AD7D0[4096] = {
#include "build/assets/valley/7ABCD0/802D4240.rgba16.inc.c"
};

/* ROM 7AE7D0; VRAM 802D5240. */
Gfx D_802D5240_7AE7D0[1] = {
#include "build/assets/native/gfx/D_802D5240_7AE7D0.dl.inc.c"
};

/* ROM 7AE7D8; VRAM 802D5248. */
u8 D_802D5248_7AE7D8[4096] = {
#include "build/assets/valley/7ABCD0/802D5248.rgba16.inc.c"
};

/* ROM 7AF7D8; VRAM 802D6248. */
Gfx D_802D6248_7AF7D8[1] = {
#include "build/assets/native/gfx/D_802D6248_7AF7D8.dl.inc.c"
};

/* ROM 7AF7E0; VRAM 802D6250. */
u8 D_802D6250_7AF7E0[4096] = {
#include "build/assets/valley/7ABCD0/802D6250.rgba16.inc.c"
};

/* ROM 7B07E0; VRAM 802D7250. */
Gfx D_802D7250_7B07E0[1] = {
#include "build/assets/native/gfx/D_802D7250_7B07E0.dl.inc.c"
};

/* ROM 7B07E8; VRAM 802D7258. */
u8 D_802D7258_7B07E8[4096] = {
#include "build/assets/valley/7ABCD0/802D7258.rgba16.inc.c"
};

/* ROM 7B17E8; VRAM 802D8258. */
Gfx D_802D8258_7B17E8[1] = {
#include "build/assets/native/gfx/D_802D8258_7B17E8.dl.inc.c"
};

/* ROM 7B17F0; VRAM 802D8260. */
u8 D_802D8260_7B17F0[4096] = {
#include "build/assets/valley/7ABCD0/802D8260.rgba16.inc.c"
};

/* ROM 7B27F0; VRAM 802D9260. */
Gfx D_802D9260_7B27F0[1] = {
#include "build/assets/native/gfx/D_802D9260_7B27F0.dl.inc.c"
};

/* ROM 7B27F8; VRAM 802D9268. */
u8 D_802D9268_7B27F8[4096] = {
#include "build/assets/valley/7ABCD0/802D9268.rgba16.inc.c"
};

/* ROM 7B37F8; VRAM 802DA268. */
Gfx D_802DA268_7B37F8[1] = {
#include "build/assets/native/gfx/D_802DA268_7B37F8.dl.inc.c"
};

/* ROM 7B3800; VRAM 802DA270. */
u8 D_802DA270_7B3800[4096] = {
#include "build/assets/valley/7ABCD0/802DA270.rgba16.inc.c"
};

/* ROM 7B4800; VRAM 802DB270. */
Gfx D_802DB270_7B4800[1] = {
#include "build/assets/native/gfx/D_802DB270_7B4800.dl.inc.c"
};

/* ROM 7B4808; VRAM 802DB278. */
u8 D_802DB278_7B4808[4096] = {
#include "build/assets/valley/7ABCD0/802DB278.rgba16.inc.c"
};

/* ROM 7B5808; VRAM 802DC278. */
Gfx D_802DC278_7B5808[1] = {
#include "build/assets/native/gfx/D_802DC278_7B5808.dl.inc.c"
};

/* ROM 7B5810; VRAM 802DC280. */
u8 D_802DC280_7B5810[4096] = {
#include "build/assets/valley/7ABCD0/802DC280.rgba16.inc.c"
};

/* ROM 7B6810; VRAM 802DD280. */
Gfx D_802DD280_7B6810[1] = {
#include "build/assets/native/gfx/D_802DD280_7B6810.dl.inc.c"
};

/* ROM 7B6818; VRAM 802DD288. */
u8 D_802DD288_7B6818[4096] = {
#include "build/assets/valley/7ABCD0/802DD288.rgba16.inc.c"
};

/* ROM 7B7818; VRAM 802DE288. */
Gfx D_802DE288_7B7818[1] = {
#include "build/assets/native/gfx/D_802DE288_7B7818.dl.inc.c"
};

/* ROM 7B7820; VRAM 802DE290. */
u8 D_802DE290_7B7820[4096] = {
#include "build/assets/valley/7ABCD0/802DE290.rgba16.inc.c"
};

/* ROM 7B8820; VRAM 802DF290. */
Gfx D_802DF290_7B8820[1] = {
#include "build/assets/native/gfx/D_802DF290_7B8820.dl.inc.c"
};

/* ROM 7B8828; VRAM 802DF298. */
u8 D_802DF298_7B8828[4096] = {
#include "build/assets/valley/7ABCD0/802DF298.rgba16.inc.c"
};

/* ROM 7B9828; VRAM 802E0298. */
Gfx D_802E0298_7B9828[1] = {
#include "build/assets/native/gfx/D_802E0298_7B9828.dl.inc.c"
};

/* ROM 7B9830; VRAM 802E02A0. */
u8 D_802E02A0_7B9830[4096] = {
#include "build/assets/valley/7ABCD0/802E02A0.rgba16.inc.c"
};

/* ROM 7BA830; VRAM 802E12A0. */
Gfx D_802E12A0_7BA830[1] = {
#include "build/assets/native/gfx/D_802E12A0_7BA830.dl.inc.c"
};

/* ROM 7BA838; VRAM 802E12A8. */
u8 D_802E12A8_7BA838[4096] = {
#include "build/assets/valley/7ABCD0/802E12A8.rgba16.inc.c"
};

/* ROM 7BB838; VRAM 802E22A8. */
Gfx D_802E22A8_7BB838[1] = {
#include "build/assets/native/gfx/D_802E22A8_7BB838.dl.inc.c"
};

/* ROM 7BB840; VRAM 802E22B0. */
u8 D_802E22B0_7BB840[4096] = {
#include "build/assets/valley/7ABCD0/802E22B0.rgba16.inc.c"
};

/* ROM 7BC840; VRAM 802E32B0. */
Gfx D_802E32B0_7BC840[1] = {
#include "build/assets/native/gfx/D_802E32B0_7BC840.dl.inc.c"
};

/* ROM 7BC848; VRAM 802E32B8. */
u8 D_802E32B8_7BC848[4096] = {
#include "build/assets/valley/7ABCD0/802E32B8.rgba16.inc.c"
};

/* ROM 7BD848; VRAM 802E42B8. */
Gfx D_802E42B8_7BD848[1] = {
#include "build/assets/native/gfx/D_802E42B8_7BD848.dl.inc.c"
};

/* ROM 7BD850; VRAM 802E42C0. */
u8 D_802E42C0_7BD850[4096] = {
#include "build/assets/valley/7ABCD0/802E42C0.rgba16.inc.c"
};

/* ROM 7BE850; VRAM 802E52C0. */
Gfx D_802E52C0_7BE850[1] = {
#include "build/assets/native/gfx/D_802E52C0_7BE850.dl.inc.c"
};

/* ROM 7BE858; VRAM 802E52C8. */
u8 D_802E52C8_7BE858[4096] = {
#include "build/assets/valley/7ABCD0/802E52C8.rgba16.inc.c"
};

/* ROM 7BF858; VRAM 802E62C8. */
Gfx D_802E62C8_7BF858[1] = {
#include "build/assets/native/gfx/D_802E62C8_7BF858.dl.inc.c"
};

/* ROM 7BF860; VRAM 802E62D0. */
u8 D_802E62D0_7BF860[896] = {
#include "build/assets/valley/7ABCD0/802E62D0.rgba16.inc.c"
};

/* ROM 7BFBE0; VRAM 802E6650. */
Gfx D_802E6650_7BFBE0[1] = {
#include "build/assets/native/gfx/D_802E6650_7BFBE0.dl.inc.c"
};

/* ROM 7BFBE8; VRAM 802E6658. */
u8 D_802E6658_7BFBE8[896] = {
#include "build/assets/valley/7ABCD0/802E6658.rgba16.inc.c"
};

/* ROM 7BFF68; VRAM 802E69D8. */
Bitmap D_802E69D8_7BFF68[20] = {
    { 64, 64, 0, 0, D_802D4240_7AD7D0, 32, 0 },
    { 62, 64, 0, 0, D_802D5248_7AE7D8, 32, 0 },
    { 64, 64, 0, 0, D_802D6250_7AF7E0, 32, 0 },
    { 62, 64, 0, 0, D_802D7258_7B07E8, 32, 0 },
    { 64, 64, 0, 0, D_802D8260_7B17F0, 32, 0 },
    { 62, 64, 0, 0, D_802D9268_7B27F8, 32, 0 },
    { 64, 64, 0, 0, D_802DA270_7B3800, 32, 0 },
    { 62, 64, 0, 0, D_802DB278_7B4808, 32, 0 },
    { 64, 64, 0, 0, D_802DC280_7B5810, 32, 0 },
    { 62, 64, 0, 0, D_802DD288_7B6818, 32, 0 },
    { 64, 64, 0, 0, D_802DE290_7B7820, 32, 0 },
    { 62, 64, 0, 0, D_802DF298_7B8828, 32, 0 },
    { 64, 64, 0, 0, D_802E02A0_7B9830, 32, 0 },
    { 62, 64, 0, 0, D_802E12A8_7BA838, 32, 0 },
    { 64, 64, 0, 0, D_802E22B0_7BB840, 32, 0 },
    { 62, 64, 0, 0, D_802E32B8_7BC848, 32, 0 },
    { 64, 64, 0, 0, D_802E42C0_7BD850, 32, 0 },
    { 62, 64, 0, 0, D_802E52C8_7BE858, 32, 0 },
    { 64, 64, 0, 0, D_802E62D0_7BF860, 7, 0 },
    { 62, 64, 0, 0, D_802E6658_7BFBE8, 7, 0 },
};

/* ROM 7C00A8; VRAM 802E6B18. */
Sprite D_802E6B18_7C00A8 = {
    0,
    0,
    126,
    295,
    1.0f,
    1.0f,
    0,
    0,
    0x200,
    4660,
    255,
    255,
    255,
    255,
    0,
    0,
    NULL,
    0,
    1,
    20,
    264,
    32,
    32,
    0,
    2,
    D_802E69D8_7BFF68,
    D_8034C9A0_825F30,
    NULL,
    0,
    0,
};

/* Bounded original zero alignment/storage: 4 bytes. */
char D_802E6B5C_7C00EC_padding[4] = "";

/* ROM 7C00F0; VRAM 802E6B60. */
Gfx D_802E6B60_7C00F0[1] = {
#include "build/assets/native/gfx/D_802E6B60_7C00F0.dl.inc.c"
};

/* ROM 7C00F8; VRAM 802E6B68. */
u8 D_802E6B68_7C00F8[1440] = {
#include "build/assets/valley/7ABCD0/802E6B68.rgba16.inc.c"
};

/* ROM 7C0698; VRAM 802E7108. */
Bitmap D_802E7108_7C0698[1] = {
    { 36, 36, 0, 0, D_802E6B68_7C00F8, 20, 0 },
};

/* ROM 7C06A8; VRAM 802E7118. */
Sprite D_802E7118_7C06A8 = {
    0,
    0,
    36,
    20,
    1.0f,
    1.0f,
    0,
    0,
    0x200,
    4660,
    255,
    255,
    255,
    255,
    0,
    0,
    NULL,
    0,
    1,
    1,
    36,
    20,
    20,
    0,
    2,
    D_802E7108_7C0698,
    D_8034D1E0_826770,
    NULL,
    0,
    0,
};

/* Bounded original zero alignment/storage: 4 bytes. */
char D_802E715C_7C06EC_padding[4] = "";

/* ROM 7C06F0; VRAM 802E7160. */
Gfx D_802E7160_7C06F0[1] = {
#include "build/assets/native/gfx/D_802E7160_7C06F0.dl.inc.c"
};

/* ROM 7C06F8; VRAM 802E7168. */
u8 D_802E7168_7C06F8[1440] = {
#include "build/assets/valley/7ABCD0/802E7168.rgba16.inc.c"
};

/* ROM 7C0C98; VRAM 802E7708. */
Bitmap D_802E7708_7C0C98[1] = {
    { 36, 36, 0, 0, D_802E7168_7C06F8, 20, 0 },
};

/* ROM 7C0CA8; VRAM 802E7718. */
Sprite D_802E7718_7C0CA8 = {
    0,
    0,
    36,
    20,
    1.0f,
    1.0f,
    0,
    0,
    0x200,
    4660,
    255,
    255,
    255,
    255,
    0,
    0,
    NULL,
    0,
    1,
    1,
    36,
    20,
    20,
    0,
    2,
    D_802E7708_7C0C98,
    D_8034D300_826890,
    NULL,
    0,
    0,
};

/* Bounded original zero alignment/storage: 4 bytes. */
char D_802E775C_7C0CEC_padding[4] = "";

/* ROM 7C0CF0; VRAM 802E7760. */
Gfx D_802E7760_7C0CF0[1] = {
#include "build/assets/native/gfx/D_802E7760_7C0CF0.dl.inc.c"
};

/* ROM 7C0CF8; VRAM 802E7768. */
u8 D_802E7768_7C0CF8[1440] = {
#include "build/assets/valley/7ABCD0/802E7768.rgba16.inc.c"
};

/* ROM 7C1298; VRAM 802E7D08. */
Bitmap D_802E7D08_7C1298[1] = {
    { 36, 36, 0, 0, D_802E7768_7C0CF8, 20, 0 },
};

/* ROM 7C12A8; VRAM 802E7D18. */
Sprite D_802E7D18_7C12A8 = {
    0,
    0,
    36,
    20,
    1.0f,
    1.0f,
    0,
    0,
    0x200,
    4660,
    255,
    255,
    255,
    255,
    0,
    0,
    NULL,
    0,
    1,
    1,
    36,
    20,
    20,
    0,
    2,
    D_802E7D08_7C1298,
    D_8034D420_8269B0,
    NULL,
    0,
    0,
};

/* Bounded original zero alignment/storage: 4 bytes. */
char D_802E7D5C_7C12EC_padding[4] = "";

/* ROM 7C12F0; VRAM 802E7D60. */
Gfx D_802E7D60_7C12F0[1] = {
#include "build/assets/native/gfx/D_802E7D60_7C12F0.dl.inc.c"
};

/* ROM 7C12F8; VRAM 802E7D68. */
u8 D_802E7D68_7C12F8[1440] = {
#include "build/assets/valley/7ABCD0/802E7D68.rgba16.inc.c"
};

/* ROM 7C1898; VRAM 802E8308. */
Bitmap D_802E8308_7C1898[1] = {
    { 36, 36, 0, 0, D_802E7D68_7C12F8, 20, 0 },
};

/* ROM 7C18A8; VRAM 802E8318. */
Sprite D_802E8318_7C18A8 = {
    0,
    0,
    36,
    20,
    1.0f,
    1.0f,
    0,
    0,
    0x200,
    4660,
    255,
    255,
    255,
    255,
    0,
    0,
    NULL,
    0,
    1,
    1,
    36,
    20,
    20,
    0,
    2,
    D_802E8308_7C1898,
    D_8034D540_826AD0,
    NULL,
    0,
    0,
};

/* Bounded original zero alignment/storage: 4 bytes. */
char D_802E835C_7C18EC_padding[4] = "";

/* ROM 7C18F0; VRAM 802E8360. */
Gfx D_802E8360_7C18F0[1] = {
#include "build/assets/native/gfx/D_802E8360_7C18F0.dl.inc.c"
};

/* ROM 7C18F8; VRAM 802E8368. */
u8 D_802E8368_7C18F8[1440] = {
#include "build/assets/valley/7ABCD0/802E8368.rgba16.inc.c"
};

/* ROM 7C1E98; VRAM 802E8908. */
Bitmap D_802E8908_7C1E98[1] = {
    { 36, 36, 0, 0, D_802E8368_7C18F8, 20, 0 },
};

/* ROM 7C1EA8; VRAM 802E8918. */
Sprite D_802E8918_7C1EA8 = {
    0,
    0,
    36,
    20,
    1.0f,
    1.0f,
    0,
    0,
    0x200,
    4660,
    255,
    255,
    255,
    255,
    0,
    0,
    NULL,
    0,
    1,
    1,
    36,
    20,
    20,
    0,
    2,
    D_802E8908_7C1E98,
    D_8034D660_826BF0,
    NULL,
    0,
    0,
};

/* Bounded original zero alignment/storage: 4 bytes. */
char D_802E895C_7C1EEC_padding[4] = "";

/* ROM 7C1EF0; VRAM 802E8960. */
Gfx D_802E8960_7C1EF0[1] = {
#include "build/assets/native/gfx/D_802E8960_7C1EF0.dl.inc.c"
};

/* ROM 7C1EF8; VRAM 802E8968. */
u8 D_802E8968_7C1EF8[1440] = {
#include "build/assets/valley/7ABCD0/802E8968.rgba16.inc.c"
};

/* ROM 7C2498; VRAM 802E8F08. */
Bitmap D_802E8F08_7C2498[1] = {
    { 36, 36, 0, 0, D_802E8968_7C1EF8, 20, 0 },
};

/* ROM 7C24A8; VRAM 802E8F18. */
Sprite D_802E8F18_7C24A8 = {
    0,
    0,
    36,
    20,
    1.0f,
    1.0f,
    0,
    0,
    0x200,
    4660,
    255,
    255,
    255,
    255,
    0,
    0,
    NULL,
    0,
    1,
    1,
    36,
    20,
    20,
    0,
    2,
    D_802E8F08_7C2498,
    D_8034D780_826D10,
    NULL,
    0,
    0,
};

/* Bounded original zero alignment/storage: 4 bytes. */
char D_802E8F5C_7C24EC_padding[4] = "";

/* ROM 7C24F0; VRAM 802E8F60. */
Gfx D_802E8F60_7C24F0[1] = {
#include "build/assets/native/gfx/D_802E8F60_7C24F0.dl.inc.c"
};

/* ROM 7C24F8; VRAM 802E8F68. */
u8 D_802E8F68_7C24F8[2112] = {
#include "build/assets/valley/7ABCD0/802E8F68.rgba16.inc.c"
};

/* ROM 7C2D38; VRAM 802E97A8. */
Bitmap D_802E97A8_7C2D38[1] = {
    { 42, 44, 0, 0, D_802E8F68_7C24F8, 24, 0 },
};

/* ROM 7C2D48; VRAM 802E97B8. */
Sprite D_802E97B8_7C2D48 = {
    0,
    0,
    42,
    24,
    1.0f,
    1.0f,
    0,
    0,
    0x200,
    4660,
    255,
    255,
    255,
    255,
    0,
    0,
    NULL,
    0,
    1,
    1,
    36,
    24,
    24,
    0,
    2,
    D_802E97A8_7C2D38,
    D_8034D8A0_826E30,
    NULL,
    0,
    0,
};

/* Bounded original zero alignment/storage: 4 bytes. */
char D_802E97FC_7C2D8C_padding[4] = "";

/* ROM 7C2D90; VRAM 802E9800. */
Gfx D_802E9800_7C2D90[1] = {
#include "build/assets/native/gfx/D_802E9800_7C2D90.dl.inc.c"
};

/* ROM 7C2D98; VRAM 802E9808. */
u8 D_802E9808_7C2D98[2112] = {
#include "build/assets/valley/7ABCD0/802E9808.rgba16.inc.c"
};

/* ROM 7C35D8; VRAM 802EA048. */
Bitmap D_802EA048_7C35D8[1] = {
    { 42, 44, 0, 0, D_802E9808_7C2D98, 24, 0 },
};

/* ROM 7C35E8; VRAM 802EA058. */
Sprite D_802EA058_7C35E8 = {
    0,
    0,
    42,
    24,
    1.0f,
    1.0f,
    0,
    0,
    0x200,
    4660,
    255,
    255,
    255,
    255,
    0,
    0,
    NULL,
    0,
    1,
    1,
    36,
    24,
    24,
    0,
    2,
    D_802EA048_7C35D8,
    D_8034D9C0_826F50,
    NULL,
    0,
    0,
};

/* Bounded original zero alignment/storage: 4 bytes. */
char D_802EA09C_7C362C_padding[4] = "";

/* ROM 7C3630; VRAM 802EA0A0. */
Gfx D_802EA0A0_7C3630[1] = {
#include "build/assets/native/gfx/D_802EA0A0_7C3630.dl.inc.c"
};

/* ROM 7C3638; VRAM 802EA0A8. */
u8 D_802EA0A8_7C3638[2112] = {
#include "build/assets/valley/7ABCD0/802EA0A8.rgba16.inc.c"
};

/* ROM 7C3E78; VRAM 802EA8E8. */
Bitmap D_802EA8E8_7C3E78[1] = {
    { 42, 44, 0, 0, D_802EA0A8_7C3638, 24, 0 },
};

/* ROM 7C3E88; VRAM 802EA8F8. */
Sprite D_802EA8F8_7C3E88 = {
    0,
    0,
    42,
    24,
    1.0f,
    1.0f,
    0,
    0,
    0x200,
    4660,
    255,
    255,
    255,
    255,
    0,
    0,
    NULL,
    0,
    1,
    1,
    36,
    24,
    24,
    0,
    2,
    D_802EA8E8_7C3E78,
    D_8034DAE0_827070,
    NULL,
    0,
    0,
};

/* Bounded original zero alignment/storage: 4 bytes. */
char D_802EA93C_7C3ECC_padding[4] = "";

/* ROM 7C3ED0; VRAM 802EA940. */
Gfx D_802EA940_7C3ED0[1] = {
#include "build/assets/native/gfx/D_802EA940_7C3ED0.dl.inc.c"
};

/* ROM 7C3ED8; VRAM 802EA948. */
u8 D_802EA948_7C3ED8[2112] = {
#include "build/assets/valley/7ABCD0/802EA948.rgba16.inc.c"
};

/* ROM 7C4718; VRAM 802EB188. */
Bitmap D_802EB188_7C4718[1] = {
    { 42, 44, 0, 0, D_802EA948_7C3ED8, 24, 0 },
};

/* ROM 7C4728; VRAM 802EB198. */
Sprite D_802EB198_7C4728 = {
    0,
    0,
    42,
    24,
    1.0f,
    1.0f,
    0,
    0,
    0x200,
    4660,
    255,
    255,
    255,
    255,
    0,
    0,
    NULL,
    0,
    1,
    1,
    36,
    24,
    24,
    0,
    2,
    D_802EB188_7C4718,
    D_8034DC00_827190,
    NULL,
    0,
    0,
};

/* Bounded original zero alignment/storage: 4 bytes. */
char D_802EB1DC_7C476C_padding[4] = "";

/* ROM 7C4770; VRAM 802EB1E0. */
Gfx D_802EB1E0_7C4770[1] = {
#include "build/assets/native/gfx/D_802EB1E0_7C4770.dl.inc.c"
};

/* ROM 7C4778; VRAM 802EB1E8. */
u8 D_802EB1E8_7C4778[2112] = {
#include "build/assets/valley/7ABCD0/802EB1E8.rgba16.inc.c"
};

/* ROM 7C4FB8; VRAM 802EBA28. */
Bitmap D_802EBA28_7C4FB8[1] = {
    { 42, 44, 0, 0, D_802EB1E8_7C4778, 24, 0 },
};

/* ROM 7C4FC8; VRAM 802EBA38. */
Sprite D_802EBA38_7C4FC8 = {
    0,
    0,
    42,
    24,
    1.0f,
    1.0f,
    0,
    0,
    0x200,
    4660,
    255,
    255,
    255,
    255,
    0,
    0,
    NULL,
    0,
    1,
    1,
    36,
    24,
    24,
    0,
    2,
    D_802EBA28_7C4FB8,
    D_8034DD20_8272B0,
    NULL,
    0,
    0,
};

/* Bounded original zero alignment/storage: 4 bytes. */
char D_802EBA7C_7C500C_padding[4] = "";

/* ROM 7C5010; VRAM 802EBA80. */
Gfx D_802EBA80_7C5010[1] = {
#include "build/assets/native/gfx/D_802EBA80_7C5010.dl.inc.c"
};

/* ROM 7C5018; VRAM 802EBA88. */
u8 D_802EBA88_7C5018[2112] = {
#include "build/assets/valley/7ABCD0/802EBA88.rgba16.inc.c"
};

/* ROM 7C5858; VRAM 802EC2C8. */
Bitmap D_802EC2C8_7C5858[1] = {
    { 42, 44, 0, 0, D_802EBA88_7C5018, 24, 0 },
};

/* ROM 7C5868; VRAM 802EC2D8. */
Sprite D_802EC2D8_7C5868 = {
    0,
    0,
    42,
    24,
    1.0f,
    1.0f,
    0,
    0,
    0x200,
    4660,
    255,
    255,
    255,
    255,
    0,
    0,
    NULL,
    0,
    1,
    1,
    36,
    24,
    24,
    0,
    2,
    D_802EC2C8_7C5858,
    D_8034DE40_8273D0,
    NULL,
    0,
    0,
};

/* Bounded original zero alignment/storage: 4 bytes. */
char D_802EC31C_7C58AC_padding[4] = "";

/* ROM 7C58B0; VRAM 802EC320. */
Gfx D_802EC320_7C58B0[1] = {
#include "build/assets/native/gfx/D_802EC320_7C58B0.dl.inc.c"
};

/* ROM 7C58B8; VRAM 802EC328. */
u8 D_802EC328_7C58B8[416] = {
#include "build/assets/valley/7ABCD0/802EC328.rgba16.inc.c"
};

/* ROM 7C5A58; VRAM 802EC4C8. */
Bitmap D_802EC4C8_7C5A58[1] = {
    { 13, 16, 0, 0, D_802EC328_7C58B8, 13, 0 },
};

/* ROM 7C5A68; VRAM 802EC4D8. */
Sprite D_802EC4D8_7C5A68 = {
    0,
    0,
    13,
    13,
    1.0f,
    1.0f,
    0,
    0,
    0x201,
    4660,
    255,
    255,
    255,
    255,
    0,
    0,
    NULL,
    0,
    1,
    1,
    36,
    13,
    13,
    0,
    2,
    D_802EC4C8_7C5A58,
    D_8034DF60_8274F0,
    NULL,
    0,
    0,
};

/* ROM 7C5AAC; VRAM 802EC51C. */
SomeC D_802EC51C_7C5AAC[15] = {
    { D_802ECE00_7C6390, 0, 0, { 0, 162 }, D_8034E080_827610 },
    { D_802ECE30_7C63C0, 0, 0, { 0, 0 }, NULL },
    { D_802ECE6C_7C63FC, 0, 0, { 0, 0 }, NULL },
    { D_802ECEAC_7C643C, 0, 1, { 0, 0 }, NULL },
    { D_802ECEEC_7C647C, 0, 0, { 0, 0 }, NULL },
    { D_802ECF30_7C64C0, 0, 0, { 0, 0 }, NULL },
    { D_802ECF68_7C64F8, 0, 0, { 0, 0 }, NULL },
    { D_802ECFB4_7C6544, 0, 1, { 0, 0 }, NULL },
    { D_802ECFF8_7C6588, 0, 0, { 0, 0 }, D_8034E080_827610 },
    { D_802ED040_7C65D0, 0, 0, { 0, 0 }, NULL },
    { D_802ED08C_7C661C, 0, 0, { 0, 0 }, NULL },
    { D_802ED0DC_7C666C, 1, 0, { 0, 0 }, NULL },
    { D_802ED120_7C66B0, 0, 0, { 0, 174 }, NULL },
    { D_802ED160_7C66F0, 0, 0, { 0, 0 }, NULL },
    { NULL, 0, 0, { 0, 0 }, NULL },
};

/* ROM 7C5B60; VRAM 802EC5D0. */
SomeC D_802EC5D0_7C5B60[2] = {
    { D_802ED170_7C6700, 0, 0, { 0, 0 }, NULL },
    { NULL, 0, 0, { 0, 0 }, NULL },
};

/* ROM 7C5B78; VRAM 802EC5E8. */
s32 D_802EC5E8_7C5B78 = 0;

/* ROM 7C5B7C; VRAM 802EC5EC. */
s32 D_802EC5EC_7C5B7C = 0;

/* ROM 7C5B80; VRAM 802EC5F0. */
Sprite* D_802EC5F0_7C5B80[6] = { &D_802E8318_7C18A8, &D_802E8918_7C1EA8, &D_802E8F18_7C24A8, &D_802E8918_7C1EA8, &D_802E8318_7C18A8, NULL };

/* ROM 7C5B98; VRAM 802EC608. */
Sprite* D_802EC608_7C5B98[6] = { &D_802E7118_7C06A8, &D_802E7718_7C0CA8, &D_802E7D18_7C12A8, &D_802E7718_7C0CA8, &D_802E7118_7C06A8, NULL };

/* ROM 7C5BB0; VRAM 802EC620. */
Sprite* D_802EC620_7C5BB0[6] = { &D_802E97B8_7C2D48, &D_802EA058_7C35E8, &D_802EA8F8_7C3E88, &D_802EB198_7C4728, &D_802EBA38_7C4FC8, &D_802EC2D8_7C5868 };

/* ROM 7C5BC8; VRAM 802EC638. */
f32 D_802EC638_7C5BC8[3] = { 0.100000001f, 0.5f, 1.0f };

/* ROM 7C5BD4; VRAM 802EC644. */
GObj* D_802EC644_7C5BD4 = NULL;

/* ROM 7C5BD8; VRAM 802EC648. */
OMCamera* D_802EC648_7C5BD8 = NULL;

/* ROM 7C5BDC; VRAM 802EC64C. */
s32 D_802EC64C_7C5BDC = 0;

/* ROM 7C5BE0; VRAM 802EC650. */
f32 D_802EC650_7C5BE0 = -1.0f;

/* ROM 7C5BE4; VRAM 802EC654. */
f32 D_802EC654_7C5BE4 = -1.0f;

/* ROM 7C5BE8; VRAM 802EC658. */
InteractionHandler D_802EC658_7C5BE8[2] = {
    { 32, func_802D07BC_7A9D4C, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 7C5C08; VRAM 802EC678. */
PokemonAnimationSetup D_802EC678_7C5C08 = { &D_802D4220_7AD7B0, func_802D0320_7A98B0, 0, { 0, 0, 0 }, NULL, NULL };

/* ROM 7C5C1C; VRAM 802EC68C. */
PokemonInitData D_802EC68C_7C5C1C = { D_8011AC50_411080, NULL, renderModelTypeBFogged, &D_802EC678_7C5C08, { 10.0f, 10.0f, 10.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f, 0, 0, 0, 0, { 0, 0, 0 } };

/* ROM 7C5C50; VRAM 802EC6C0. */
AnimationHeader D_802EC6C0_7C5C50 = { 1.0f, 100.0f, gate_modelanim_closed, gate_matanim_closed, NULL };

/* ROM 7C5C64; VRAM 802EC6D4. */
AnimationHeader D_802EC6D4_7C5C64 = { 1.0f, 100.0f, gate_modelanim_raise_bar, gate_matanim_raise_bar, NULL };

/* ROM 7C5C78; VRAM 802EC6E8. */
AnimationHeader D_802EC6E8_7C5C78 = { 1.0f, 100.0f, gate_modelanim_opening, gate_matanim_opening, NULL };

/* ROM 7C5C8C; VRAM 802EC6FC. */
AnimationHeader D_802EC6FC_7C5C8C = { 1.0f, 100.0f, gate_modelanim_opened, gate_matanim_opened, NULL };

/* ROM 7C5CA0; VRAM 802EC710. */
s32 D_802EC710_7C5CA0 = -1;

/* ROM 7C5CA4; VRAM 802EC714. */
s32 D_802EC714_7C5CA4 = 0;

/* ROM 7C5CA8; VRAM 802EC718. */
InteractionHandler D_802EC718_7C5CA8[2] = {
    { 16, func_802D0BFC_7AA18C, 2000.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 7C5CC8; VRAM 802EC738. */
SomeS16s D_802EC738_7C5CC8 = { { 1001, 0 } };

/* ROM 7C5CCC; VRAM 802EC73C. */
PokemonAnimationSetup D_802EC73C_7C5CCC = { &D_802EC6C0_7C5C50, func_802D0B80_7AA110, 0, { 0, 0, 0 }, NULL, NULL };

/* ROM 7C5CE0; VRAM 802EC750. */
PokemonInitData D_802EC750_7C5CE0 = { gate_model, gate_materials, renderModelTypeDFogged, &D_802EC73C_7C5CCC, { 10.0f, 10.0f, 10.0f }, { 0.0f, 0.0f, 0.0f }, 0.00999999978f, 0, 0, 0, 0, { 0, 0, 0 } };

/* Bounded original zero alignment/storage: 12 bytes. */
char D_802EC784_7C5D14_padding[12] = "";

/* ROM 7C5D20; VRAM 802EC790. */
AnimationHeader D_802EC790_7C5D20 = { 0.0f, 100.0f, D_80119EE0_410310, NULL, NULL };

/* ROM 7C5D34; VRAM 802EC7A4. */
PokemonAnimationSetup D_802EC7A4_7C5D34 = { &D_802EC790_7C5D20, func_802D1190, 0, { 0, 0, 0 }, NULL, NULL };

/* ROM 7C5D48; VRAM 802EC7B8. */
PokemonInitData D_802EC7B8_7C5D48 = { D_80119BB0_40FFE0, NULL, renderPokemonModelTypeBFogged, &D_802EC7A4_7C5D34, { 10.0f, 10.0f, 10.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f, 68, 0, 0, 0, { 0, 0, 0 } };

/* Bounded original zero alignment/storage: 4 bytes. */
char D_802EC7EC_7C5D7C_padding[4] = "";

/* ROM 7C5D80; VRAM 802EC7F0. */
s32 D_802EC7F0_7C5D80[1] = { 211 };

/* ROM 7C5D84; VRAM 802EC7F4. */
s32 D_802EC7F4_7C5D84[3] = { 210, 376, 114 };

/* ROM 7C5D90; VRAM 802EC800. */
s32 D_802EC800_7C5D90[3] = { 211, 376, 114 };

/* ROM 7C5D9C; VRAM 802EC80C. */
s32 D_802EC80C_7C5D9C[3] = { 0, 376, 114 };

/* ROM 7C5DA8; VRAM 802EC818. */
AnimationHeader D_802EC818_7C5DA8 = { 0.5f, 60.0f, D_800FDC70_7B090, NULL, D_802EC7F0_7C5D80 };

/* ROM 7C5DBC; VRAM 802EC82C. */
AnimationHeader D_802EC82C_7C5DBC = { 0.5f, 65.0f, D_800FAE40_78260, NULL, D_802EC7F4_7C5D84 };

/* ROM 7C5DD0; VRAM 802EC840. */
AnimationHeader D_802EC840_7C5DD0 = { 0.5f, 59.0f, D_800FBF50_79370, NULL, D_802EC800_7C5D90 };

/* ROM 7C5DE4; VRAM 802EC854. */
AnimationHeader D_802EC854_7C5DE4 = { 0.5f, 50.0f, D_800FD080_7A4A0, NULL, D_802EC80C_7C5D9C };

/* ROM 7C5DF8; VRAM 802EC868. */
u16 D_802EC868_7C5DF8 = 0;

/* ROM 7C5DFC; VRAM 802EC86C. */
u16 D_802EC86C_7C5DFC = 0;

/* ROM 7C5E00; VRAM 802EC870. */
RandomState D_802EC870_7C5E00[4] = {
    { 20, func_802D129C_7AA82C },
    { 50, func_802D12D4_7AA864 },
    { 30, func_802D130C_7AA89C },
    { 0, NULL },
};

/* ROM 7C5E20; VRAM 802EC890. */
s32 D_802EC890_7C5E20 = 0;

/* ROM 7C5E24; VRAM 802EC894. */
f32 D_802EC894_7C5E24 = 0.0f;

/* ROM 7C5E28; VRAM 802EC898. */
InteractionHandler D_802EC898_7C5E28[2] = {
    { 16, func_802D16CC_7AAC5C, 1800.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 7C5E48; VRAM 802EC8B8. */
InteractionHandler D_802EC8B8_7C5E48[2] = {
    { 10, func_802D1734_7AACC4, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 7C5E68; VRAM 802EC8D8. */
Vec3f D_802EC8D8_7C5E68 = { 0.0f, 0.0f, 0.0f };

/* ROM 7C5E74; VRAM 802EC8E4. */
InteractionHandler D_802EC8E4_7C5E74[3] = {
    { 9, func_802D1F18_7AB4A8, 0.0f, NULL },
    { 10, func_802D1F18_7AB4A8, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 7C5EA4; VRAM 802EC914. */
Vec3f D_802EC914_7C5EA4 = { 0.0f, 0.0f, 0.0f };

/* ROM 7C5EB0; VRAM 802EC920. */
PokemonAnimationSetup D_802EC920_7C5EB0 = { &D_802EC82C_7C5DBC, func_802D1200_7AA790, 0, { 0, 0, 0 }, NULL, NULL };

/* ROM 7C5EC4; VRAM 802EC934. */
PokemonInitData D_802EC934_7C5EC4 = { magikarp_model, NULL, renderPokemonModelTypeBFogged, &D_802EC920_7C5EB0, { 1.60000002f, 1.60000002f, 1.60000002f }, { 0.0f, -40.0f, -11.0f }, 35.0f, 37, 0, 0, 0, { 0, 0, 0 } };

/* Bounded original zero alignment/storage: 8 bytes. */
char D_802EC968_7C5EF8_padding[8] = "";

/* ROM 7C5F00; VRAM 802EC970. */
s32 D_802EC970_7C5F00[3] = { 239, 111, 113 };

/* ROM 7C5F0C; VRAM 802EC97C. */
s32 D_802EC97C_7C5F0C[3] = { 0, 111, 113 };

/* ROM 7C5F18; VRAM 802EC988. */
s32 D_802EC988_7C5F18[3] = { 239, 111, 113 };

/* ROM 7C5F24; VRAM 802EC994. */
AnimationHeader D_802EC994_7C5F24 = { 0.430000007f, 60.0f, D_80179C50_470090, D_8017B800_471C40, D_802EC970_7C5F00 };

/* ROM 7C5F38; VRAM 802EC9A8. */
AnimationHeader D_802EC9A8_7C5F38 = { 0.649999976f, 45.0f, D_8017A420_470860, D_8017B8D0_471D10, D_802EC97C_7C5F0C };

/* ROM 7C5F4C; VRAM 802EC9BC. */
AnimationHeader D_802EC9BC_7C5F4C = { 0.5f, 70.0f, D_8017AED0_471310, D_8017B980_471DC0, D_802EC988_7C5F18 };

/* ROM 7C5F60; VRAM 802EC9D0. */
InteractionHandler D_802EC9D0_7C5F60[2] = {
    { 31, func_802D22A0_7AB830, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 7C5F80; VRAM 802EC9F0. */
RandomState D_802EC9F0_7C5F80[4] = {
    { 30, func_802D22D4_7AB864 },
    { 50, func_802D230C_7AB89C },
    { 20, func_802D2344_7AB8D4 },
    { 0, NULL },
};

/* ROM 7C5FA0; VRAM 802ECA10. */
Vec3f D_802ECA10_7C5FA0 = { 0.0f, 0.0f, 0.0f };

/* ROM 7C5FAC; VRAM 802ECA1C. */
PokemonAnimationSetup D_802ECA1C_7C5FAC = { &D_802EC994_7C5F24, func_802D2230_7AB7C0, 0, { 0, 0, 0 }, NULL, D_802EC9D0_7C5F60 };

/* ROM 7C5FC0; VRAM 802ECA30. */
PokemonInitData D_802ECA30_7C5FC0 = { goldeen_model, D_803469D0_81FF60, renderPokemonModelTypeIFogged, &D_802ECA1C_7C5FAC, { 2.0f, 2.0f, 2.0f }, { 0.0f, 28.0f, -1.70000005f }, 23.0f, 37, 0, 0, 0, { 0, 0, 0 } };

/* Bounded original zero alignment/storage: 12 bytes. */
char D_802ECA64_7C5FF4_padding[12] = "";

/* ROM 7C6000; VRAM 802ECA70. */
UnkEC64Arg3 D_802ECA70_7C6000[2] = {
    { 0, NULL, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 1.0f, 1.0f, 1.0f } },
    { 18, NULL, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
};

/* ROM 7C6058; VRAM 802ECAC8. */
AnimCmd* D_802ECAC8_7C6058[1] = { NULL };

/* ROM 7C605C; VRAM 802ECACC. */
AnimationHeader D_802ECACC_7C605C = { 0.0f, 1.0f, D_802ECAC8_7C6058, NULL, NULL };

/* ROM 7C6070; VRAM 802ECAE0. */
PokemonDef extraStaryuDef = { 120, (pokemonInit) func_802CD73C_7A6CCC, pokemonChangeBlock, pokemonRemoveOne };

/* ROM 7C6080; VRAM 802ECAF0. */
PokemonDef extraStarmieDef = { 121, (pokemonInit) func_802CDE3C_7A73CC, pokemonChangeBlock, pokemonRemoveOne };

/* ROM 7C6090; VRAM 802ECB00. */
RandomState D_802ECB00_7C6090[3] = {
    { 70, func_802D2604 },
    { 30, func_802D2684 },
    { 0, NULL },
};

/* ROM 7C60A8; VRAM 802ECB18. */
PokemonAnimationSetup D_802ECB18_7C60A8 = { NULL, func_802D25E0, 0, { 0, 0, 0 }, NULL, NULL };

/* ROM 7C60BC; VRAM 802ECB2C. */
PokemonInitData D_802ECB2C_7C60BC = { D_802ECA70_7C6000, NULL, renRenderModelTypeB, &D_802ECB18_7C60A8, { 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f, 0, 0, 0, 0, { 0, 0, 0 } };
