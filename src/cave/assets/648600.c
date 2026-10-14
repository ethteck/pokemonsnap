#include "common.h"
#include "ld_addrs.h"
#include "world/world.h"
#include "app_level/app_level.h"
#include "cave/cave.h"

typedef struct Bytes3 {
    u8 unk_00[3];
} Bytes3;
typedef struct Bytes12 {
    u8 unk_00[12];
} Bytes12;

/* Native records in original physical order. */
extern AnimCmd* D_800FAE40_78260[];
extern AnimCmd* D_800FBF50_79370[];
extern AnimCmd* D_800FD080_7A4A0[];
extern AnimCmd* D_800FDC70_7B090[];
extern AnimCmd* D_801092F0_86710[];
extern AnimCmd* D_80109C10_87030[];
extern AnimCmd* D_8010C370_89790[];
extern AnimCmd* D_8010CE10_8A230[];
extern AnimCmd* D_8010D410_8A830[];
extern AnimCmd* D_8010E190_8B5B0[];
extern AnimCmd* D_80111AA0_8EEC0[];
extern AnimCmd* D_80112F20_90340[];
extern AnimCmd* D_80113740_90B60[];
extern AnimCmd* D_80114610_91A30[];
extern AnimCmd* D_801161D0_935F0[];
extern AnimCmd* D_80117C40_95060[];
extern AnimCmd* D_801189D0_95DF0[];
extern AnimCmd** D_801196C0_96AE0[];
extern AnimCmd** D_80119760_96B80[];
extern AnimCmd** D_80119800_96C20[];
extern AnimCmd** D_801198B0_96CD0[];
extern AnimCmd** D_80119960_96D80[];
extern AnimCmd** D_80119A00_96E20[];
extern AnimCmd** D_8011A1B0_975D0[];
extern AnimCmd** D_8011A2B0_976D0[];
extern AnimCmd** D_8011A370_97790[];
extern AnimCmd** D_8011A440_97860[];
extern AnimCmd** D_8011ADE0_98200[];
extern AnimCmd** D_8011AEE0_98300[];
extern AnimCmd** D_8011AF80_983A0[];
extern AnimCmd* D_8011C2E0_99700[];
extern AnimCmd* D_8011F0D0_9C4F0[];
extern AnimCmd* D_8011F9D0_9CDF0[];
extern AnimCmd* D_801202D0_9D6F0[];
extern AnimCmd* D_80120850_9DC70[];
extern AnimCmd* D_80120DD0_9E1F0[];
extern AnimCmd* D_80121410_9E830[];
extern AnimCmd* D_80121A50_9EE70[];
extern AnimCmd* D_80121F30_9F350[];
extern AnimCmd* D_80123320_A0740[];
extern AnimCmd* D_80124710_A1B30[];
extern AnimCmd* D_80124C20_A2040[];
extern AnimCmd* D_80125130_A2550[];
extern AnimCmd* D_80125B80_A2FA0[];
extern AnimCmd* D_80125F00_A3320[];
extern AnimCmd* D_80126310_A3730[];
extern AnimCmd* D_80126680_A3AA0[];
extern AnimCmd* D_80127090_A44B0[];
extern AnimCmd* D_801283C0_A57E0[];
extern AnimCmd** D_801296E0_A6B00[];
extern AnimCmd** D_80129750_A6B70[];
extern AnimCmd** D_80129800_A6C20[];
extern AnimCmd** D_80129910_A6D30[];
extern AnimCmd** D_80129980_A6DA0[];
extern AnimCmd** D_80129A10_A6E30[];
extern AnimCmd** D_80129A80_A6EA0[];
extern AnimCmd** D_80129AE0_A6F00[];
extern AnimCmd** D_80129BA0_A6FC0[];
extern AnimCmd** D_80129C10_A7030[];
extern AnimCmd** D_80129CC0_A70E0[];
extern AnimCmd** D_80129D80_A71A0[];
extern AnimCmd** D_80129DF0_A7210[];
extern AnimCmd** D_80129EA0_A72C0[];
extern AnimCmd** D_80129F00_A7320[];
extern AnimCmd** D_80129F80_A73A0[];
extern AnimCmd** D_80129FF0_A7410[];
extern UnkEC64Arg3 D_801450C0_210E70[];
extern AnimCmd* D_801456D0_211480[];
extern AnimCmd* D_801572A0_223050[];
extern AnimCmd* D_801580F0_223EA0[];
extern AnimCmd* D_80158C90_224A40[];
extern AnimCmd* D_80159940_2256F0[];
extern AnimCmd* D_8015A380_226130[];
extern AnimCmd** D_8015B4F0_2272A0[];
extern AnimCmd** D_8015B8C0_227670[];
extern AnimCmd** D_8015BC90_227A40[];
extern AnimCmd** D_8015BFA0_227D50[];
extern AnimCmd** D_8015C410_2281C0[];
extern AnimCmd* D_8015E650_22A400[];
extern AnimCmd* D_8015EC20_22A9D0[];
extern AnimCmd* D_8015F1D0_22AF80[];
extern AnimCmd* D_8015F820_22B5D0[];
extern AnimCmd* D_80160160_22BF10[];
extern AnimCmd** D_80160BA0_22C950[];
extern AnimCmd** D_80160EC0_22CC70[];
extern AnimCmd** D_80161220_22CFD0[];
extern AnimCmd** D_80161540_22D2F0[];
extern AnimCmd** D_80161860_22D610[];
extern AnimCmd* D_801657B0_231560[];
extern AnimCmd* D_80166B20_2328D0[];
extern AnimCmd* D_801676C0_233470[];
extern AnimCmd* D_801680F0_233EA0[];
extern AnimCmd* D_8016A380_236130[];
extern AnimCmd* D_8016B2D0_237080[];
extern AnimCmd** D_8016DCF0_239AA0[];
extern AnimCmd** D_8016E240_239FF0[];
extern AnimCmd** D_8016E570_23A320[];
extern AnimCmd** D_8016E910_23A6C0[];
extern AnimCmd** D_8016EF90_23AD40[];
extern AnimCmd** D_8016F440_23B1F0[];
extern AnimCmd* D_80172370_23E120[];
extern AnimCmd* D_80172E00_23EBB0[];
extern AnimCmd* D_801746E0_240490[];
extern AnimCmd** D_80178800_2445B0[];
extern AnimCmd** D_80178890_244640[];
extern AnimCmd** D_80178920_2446D0[];
extern AnimCmd* D_8017A200_245FB0[4];
extern AnimCmd* D_8017A350_246100[4];
extern AnimCmd* D_8017A510_2462C0[4];
extern AnimCmd* D_8017A710_2464C0[4];
extern Vtx D_8017A780_246530[328];
extern UnkEC64Arg3 D_8017BFA8_247D58[5];
extern Vtx D_8017C090_247E40[328];
extern AnimCmd* D_8017D950_249700[];
extern AnimCmd* D_8017E460_24A210[];
extern AnimCmd* D_8017EE10_24ABC0[];
extern AnimCmd* D_80181570_24D320[];
extern AnimCmd* D_80182410_24E1C0[];
extern AnimCmd* D_80182D00_24EAB0[];
extern AnimCmd* D_80183C40_24F9F0[];
extern AnimCmd* D_80184C20_2509D0[];
extern AnimCmd* D_80186450_252200[];
extern AnimCmd* D_80189BC0_255970[];
extern AnimCmd* D_8018AD70_256B20[];
extern AnimCmd* D_8018BF00_257CB0[];
extern AnimCmd* D_8018DA20_2597D0[];
extern AnimCmd* D_8018EBD0_25A980[];
extern AnimCmd* D_8018F850_25B600[];
extern AnimCmd* D_80190AA0_25C850[];
extern AnimCmd* D_801921E0_25DF90[];
extern AnimCmd** D_80192CF0_25EAA0[];
extern AnimCmd** D_80192E30_25EBE0[];
extern AnimCmd** D_80192FF0_25EDA0[];
extern AnimCmd** D_80193200_25EFB0[];
extern AnimCmd** D_801933D0_25F180[];
extern AnimCmd** D_80193510_25F2C0[];
extern AnimCmd** D_80193780_25F530[];
extern AnimCmd** D_801939E0_25F790[];
extern AnimCmd* D_80199060_264E10[];
extern AnimCmd* D_8019B160_266F10[];
extern AnimCmd* D_8019C070_267E20[];
extern AnimCmd* D_8019D4A0_269250[];
extern AnimCmd* D_8019E4D0_26A280[];
extern AnimCmd* D_8019EF80_26AD30[];
extern AnimCmd** D_801A02A0_26C050[];
extern AnimCmd** D_801A0310_26C0C0[];
extern AnimCmd** D_801A03C0_26C170[];
extern AnimCmd* D_801A2EF0_26ECA0[];
extern AnimCmd* D_801A39C0_26F770[];
extern AnimCmd* D_801A47D0_270580[];
extern AnimCmd** D_801A5250_271000[];
extern AnimCmd** D_801A5380_271130[];
extern AnimCmd** D_801A54D0_271280[];
extern AnimCmd* D_801A8250_274000[];
extern AnimCmd* D_801A8C10_2749C0[];
extern AnimCmd* D_801A9A10_2757C0[];
extern AnimCmd* D_801AA220_275FD0[];
extern AnimCmd* D_801AB240_276FF0[];
extern AnimCmd* D_801ACBD0_278980[];
extern AnimCmd* D_801ADA80_279830[];
extern AnimCmd** D_801AE730_27A4E0[];
extern AnimCmd** D_801AE8C0_27A670[];
extern AnimCmd** D_801AE9A0_27A750[];
extern AnimCmd** D_801AEB60_27A910[];
extern Texture** D_80317620_699AD0[];
extern Texture** D_8031C830_69ECE0[];
extern Texture** D_80321A30_6A3EE0[];
extern Texture** D_803265E0_6A8A90[];
extern Texture** D_8032E0F0_6B05A0[];
extern Texture** D_80331450_6B3900[];
extern UnkEC64Arg3 D_80335F98_6B8448[];
extern Texture** D_80336310_6B87C0[];
extern Texture** D_8033AB80_6BD030[];
extern Struct_800AB050 D_8033E210_6C06C0[324];
extern u16 D_803B5000[];
extern u16 D_803DA800[];
extern UnkEC64Arg3 articuno_model[];
extern Texture** bulbasaur_materials[];
extern UnkEC64Arg3 bulbasaur_model[];
extern void contUpdate(void);
extern UnkEC64Arg3 ditto_model[];
extern void func_800A1A50(Gfx** gfx);
extern void func_802BDD00_6401B0(GObj* obj);
extern void func_802BE22C_6406DC(void);
extern void func_802BE3A8_640858(s32 arg0);
extern void func_802BE898_640D48(GObj* obj);
extern void func_802BE8D4_640D84(GObj* obj);
extern void func_802BE944_640DF4(GObj* obj);
extern void func_802BE9B4_640E64(GObj* obj);
extern void func_802BEA24_640ED4(GObj* obj);
extern void func_802BEB24_640FD4(GObj* obj);
extern void func_802BEBBC_64106C(GObj* obj);
extern void func_802BEC34_6410E4(GObj* obj);
extern void func_802BED04_6411B4(GObj* obj);
extern void func_802BEEF4_6413A4(GObj* obj);
extern void func_802BEF18_6413C8(GObj* obj);
extern GObj* func_802BEFD8_641488(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData);
extern void func_802BF020_6414D0(GObj* arg0);
extern void func_802BF0B4_641564(GObj* obj);
extern void func_802BF124_6415D4(GObj* obj);
extern void func_802BF220_6416D0(GObj* obj);
extern void func_802BF2D0_641780(GObj* obj);
extern void func_802BF338_6417E8(GObj* obj);
extern GObj* func_802BF55C_641A0C(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData);
extern void func_802BF5A0_641A50(GObj* obj);
extern void func_802BF68C_641B3C(GObj* obj);
extern void func_802BF7B4_641C64(GObj* obj);
extern void func_802BF824_641CD4(GObj* obj);
extern void func_802BF894_641D44(GObj* obj);
extern void func_802BFA3C_641EEC(GObj* obj);
extern void func_802BFBF0_6420A0(GObj* obj);
extern GObj* func_802BFDA0_642250(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData);
extern void func_802BFDE0_642290(GObj* obj);
extern void func_802BFE34_6422E4(GObj* obj);
extern void func_802BFEF0_6423A0(GObj* obj);
extern void func_802C00B0_642560(GObj* obj);
extern GObj* func_802C0104_6425B4(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData);
extern void func_802C0220_6426D0(GObj* obj);
extern void func_802C0330_6427E0(GObj* obj);
extern void func_802C0510_6429C0(GObj* obj);
extern void func_802C0630_642AE0(GObj* obj);
extern void func_802C06BC_642B6C(GObj* obj);
extern void func_802C0748_642BF8(GObj* obj);
extern GObj* func_802C07D4_642C84(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData);
extern void func_802C0888_642D38(GObj* obj);
extern void func_802C0AF0_642FA0(GObj* obj);
extern void func_802C0BB0_643060(GObj* obj);
extern void func_802C0D34_6431E4(GObj* obj);
extern void func_802C0E80_643330(GObj* obj);
extern void func_802C1018_6434C8(GObj* obj);
extern GObj* func_802C10C8_643578(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData);
extern void func_802C1100_6435B0(GObj* obj);
extern void func_802C1124_6435D4(GObj* obj);
extern void func_802C1178_643628(GObj* obj);
extern void func_802C11E8_643698(GObj* obj);
extern void func_802C12E4_643794(GObj* obj);
extern void func_802C134C_6437FC(GObj* obj);
extern GObj* func_802C13B4_643864(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData);
extern GObj* func_802C13EC_64389C(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData);
extern void func_802C14C4_643974(GObj* obj);
extern void func_802C1794_643C44(GObj* obj);
extern void func_802C1818_643CC8(GObj* obj);
extern void func_802C189C_643D4C(GObj* obj);
extern void func_802C1920_643DD0(GObj* obj);
extern void func_802C19BC_643E6C(GObj* obj);
extern void func_802C1AC8_643F78(GObj* obj);
extern void func_802C2504_6449B4(GObj* obj);
extern void func_802C25D8_644A88(GObj* obj);
extern void func_802C2854_644D04(GObj* obj);
extern void func_802C28D0_644D80(GObj* obj);
extern void func_802C294C_644DFC(GObj* obj);
extern GObj* func_802C2994_644E44(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData);
extern void func_802C29D0_644E80(GObj* obj);
extern void func_802C2BDC_64508C(GObj* obj);
extern void func_802C2D98_645248(GObj* obj);
extern void func_802C2EBC_64536C(GObj* obj);
extern void func_802C2FF4_6454A4(GObj* obj);
extern void func_802C30B8_645568(GObj* obj);
extern void func_802C31D0_645680(GObj* obj);
extern GObj* func_802C3250_645700(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData);
extern void func_802C3290_645740(GObj*);
extern GObj* func_802C3388_645838(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData);
extern void func_802C33C0_645870(GObj* arg0);
extern void func_802C3840_645CF0(GObj* obj);
extern void func_802C3874_645D24(GObj*);
extern void func_802C3E74_646324(GObj* obj);
extern void func_802C3EDC_64638C(GObj* obj);
extern void func_802C3FD8_646488(GObj* obj);
extern void func_802C413C_6465EC(GObj* obj);
extern GObj* func_802C465C_646B0C(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData);
extern void func_802C46A0_646B50(GObj* obj);
extern void func_802C46F0_646BA0(GObj* obj);
extern GObj* func_802C49A8_646E58(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn);
extern void func_802C49F0_646EA0(GObj* obj);
extern void func_802C4AA8_646F58(GObj* obj);
extern void func_802C4B04_646FB4(GObj* obj);
extern GObj* func_802C4E64_647314(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn);
extern void func_802C4EF4_6473A4(GObj* obj);
extern void func_802C5188_647638(GObj* obj);
extern void func_802C5380_647830(GObj* obj);
extern void func_802C53F4_6478A4(GObj* obj);
extern void func_802C5468_647918(GObj* obj);
extern GObj* func_802C5548_6479F8(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData);
extern void func_802C5580_647A30(GObj* obj);
extern void func_802C55D4_647A84(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn);
extern void func_802C569C_647B4C(GObj* obj);
extern GObj* func_802C5B28_647FD8(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData);
extern GObj* func_8035E0D4_4FE4E4(s32 objID, u16 id, WorldBlock* block, WorldBlock* arg3, ObjectSpawn* arg4);
extern void func_beach_802C5620(GObj* arg0);
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
extern UnkEC64Arg3 grimer_model[];
extern UnkEC64Arg3 jigglypuff_model[];
extern UnkEC64Arg3 koffing_model[];
extern UnkEC64Arg3 magikarp_model[];
extern UnkEC64Arg3 muk_model[];
extern void omDrawAll(void);
extern void omUpdateAll(void);
extern Texture** pikachu_materials[];
extern UnkEC64Arg3 pikachu_model[];
extern void pokemonChangeBlock(GObj* pokemonObj, f32 prevBlockX, f32 prevBlockY, f32 prevBlockZ, f32 currBlockX, f32 currBlockY, f32 currBlockZ);
extern void pokemonChangeBlockOnGround(GObj* pokemonObj, f32 prevBlockX, f32 prevBlockY, f32 prevBlockZ, f32 currBlockX, f32 currBlockY, f32 currBlockZ);
extern void pokemonRemoveOne(GObj* obj);
extern void renderModelTypeDFogged(GObj* arg0);
extern void renderPokemonModelTypeBFogged(GObj* arg0);
extern void renderPokemonModelTypeDFogged(GObj* arg0);
extern void renderPokemonModelTypeIFogged(GObj* arg0);
extern void renderPokemonModelTypeJFogged(GObj* arg0);
extern UnkEC64Arg3 victreebel_model[];
extern UnkEC64Arg3 weepinbell_model[];
extern UnkEC64Arg3 zubat_model[];
extern EnvSoundData D_802C6150_648600[57];
extern PokemonDef D_802C6234_6486E4[18];
extern u16 D_802C6354_648804;
extern PokemonDef D_802C6358_648808;
extern RandomState2 D_802C6368_648818[2];
extern s32 D_802C6378_648828;
extern ScreenSettings D_802C637C_64882C;
extern SceneSetup D_802C6398_648848;
extern u32 D_802C6430_6488E0;
extern s32 D_802C6440_6488F0[1];
extern s32 D_802C6444_6488F4[1];
extern s32 D_802C6448_6488F8[1];
extern s32 D_802C644C_6488FC[1];
extern s32 D_802C6450_648900[2];
extern s32 D_802C6458_648908[1];
extern s32 D_802C645C_64890C[1];
extern s32 D_802C6460_648910[2];
extern s32 D_802C6468_648918[2];
extern AnimationHeader D_802C6470_648920;
extern AnimationHeader D_802C6484_648934;
extern AnimationHeader D_802C6498_648948;
extern AnimationHeader D_802C64AC_64895C;
extern AnimationHeader D_802C64C0_648970;
extern AnimationHeader D_802C64D4_648984;
extern AnimationHeader D_802C64E8_648998;
extern AnimationHeader D_802C64FC_6489AC;
extern AnimationHeader D_802C6510_6489C0;
extern AnimationHeader D_802C6524_6489D4;
extern AnimationHeader D_802C6538_6489E8;
extern AnimationHeader D_802C654C_6489FC;
extern AnimationHeader D_802C6560_648A10;
extern AnimationHeader D_802C6574_648A24;
extern AnimationHeader D_802C6588_648A38;
extern AnimationHeader D_802C659C_648A4C;
extern AnimationHeader D_802C65B0_648A60;
extern AnimationHeader D_802C65C4_648A74;
extern PokemonDef D_802C65D8_648A88;
extern InteractionHandler D_802C65E8_648A98[9];
extern InteractionHandler D_802C6678_648B28[8];
extern InteractionHandler D_802C66F8_648BA8[3];
extern InteractionHandler D_802C6728_648BD8[5];
extern InteractionHandler D_802C6778_648C28[3];
extern InteractionHandler D_802C67A8_648C58[4];
extern RandomState D_802C67E8_648C98[5];
extern PokemonAnimationSetup D_802C6810_648CC0;
extern PokemonInitData D_802C6824_648CD4;
extern s32 D_802C6860_648D10[1];
extern s32 D_802C6864_648D14[1];
extern s32 D_802C6868_648D18[2];
extern AnimationHeader D_802C6870_648D20;
extern AnimationHeader D_802C6884_648D34;
extern AnimationHeader D_802C6898_648D48;
extern AnimationHeader D_802C68AC_648D5C;
extern AnimationHeader D_802C68C0_648D70;
extern AnimationHeader D_802C68D4_648D84;
extern AnimationHeader D_802C68E8_648D98;
extern AnimationHeader D_802C68FC_648DAC;
extern AnimationHeader D_802C6910_648DC0;
extern InteractionHandler D_802C6924_648DD4[4];
extern RandomState D_802C6964_648E14[3];
extern InteractionHandler D_802C697C_648E2C[3];
extern PokemonAnimationSetup D_802C69AC_648E5C;
extern PokemonInitData D_802C69C0_648E70;
extern s32 D_802C6A00_648EB0[1];
extern s32 D_802C6A04_648EB4[1];
extern s32 D_802C6A08_648EB8[1];
extern s32 D_802C6A0C_648EBC[1];
extern s32 D_802C6A10_648EC0[1];
extern s32 D_802C6A14_648EC4[1];
extern AnimationHeader D_802C6A18_648EC8;
extern AnimationHeader D_802C6A2C_648EDC;
extern AnimationHeader D_802C6A40_648EF0;
extern AnimationHeader D_802C6A54_648F04;
extern AnimationHeader D_802C6A68_648F18;
extern AnimationHeader D_802C6A7C_648F2C;
extern AnimationHeader D_802C6A90_648F40;
extern f32 D_802C6AA4_648F54;
extern InteractionHandler D_802C6AA8_648F58[3];
extern InteractionHandler D_802C6AD8_648F88[3];
extern InteractionHandler D_802C6B08_648FB8[2];
extern RandomState D_802C6B28_648FD8[4];
extern PokemonAnimationSetup D_802C6B48_648FF8;
extern PokemonInitData D_802C6B5C_64900C;
extern s32 D_802C6B90_649040[4];
extern s32 D_802C6BA0_649050[1];
extern AnimationHeader D_802C6BA4_649054;
extern AnimationHeader D_802C6BB8_649068;
extern AnimationHeader D_802C6BCC_64907C;
extern InteractionHandler D_802C6BE0_649090[3];
extern InteractionHandler D_802C6C10_6490C0[2];
extern InteractionHandler D_802C6C30_6490E0[2];
extern PokemonAnimationSetup D_802C6C50_649100;
extern PokemonInitData D_802C6C64_649114;
extern s32 D_802C6CA0_649150[2];
extern s32 D_802C6CA8_649158[2];
extern s32 D_802C6CB0_649160[2];
extern s32 D_802C6CB8_649168[2];
extern s32 D_802C6CC0_649170[2];
extern s32 D_802C6CC8_649178[3];
extern AnimationHeader D_802C6CD4_649184;
extern AnimationHeader D_802C6CE8_649198;
extern AnimationHeader D_802C6CFC_6491AC;
extern AnimationHeader D_802C6D10_6491C0;
extern AnimationHeader D_802C6D24_6491D4;
extern AnimationHeader D_802C6D38_6491E8;
extern GObj* D_802C6D4C_6491FC[4];
extern u8 D_802C6D5C_64920C[4];
extern InteractionHandler3 D_802C6D60_649210;
extern InteractionHandler D_802C6D90_649240[2];
extern InteractionHandler6 D_802C6DB0_649260;
extern InteractionHandler5 D_802C6E10_6492C0;
extern InteractionHandler5 D_802C6E60_649310;
extern InteractionHandler5 D_802C6EB0_649360;
extern PokemonAnimationSetup D_802C6F00_6493B0;
extern PokemonInitData D_802C6F14_6493C4;
extern s32 D_802C6F50_649400[1];
extern s32 D_802C6F54_649404[1];
extern s32 D_802C6F58_649408[2];
extern AnimationHeader D_802C6F60_649410;
extern AnimationHeader D_802C6F74_649424;
extern AnimationHeader D_802C6F88_649438;
extern AnimationHeader D_802C6F9C_64944C;
extern AnimationHeader D_802C6FB0_649460;
extern PokemonDef D_802C6FC4_649474;
extern InteractionHandler D_802C6FD4_649484[4];
extern RandomState D_802C7014_6494C4[3];
extern PokemonAnimationSetup D_802C702C_6494DC;
extern PokemonInitData D_802C7040_6494F0;
extern s32 D_802C7080_649530[1];
extern s32 D_802C7084_649534[1];
extern s32 D_802C7088_649538[1];
extern AnimationHeader D_802C708C_64953C;
extern AnimationHeader D_802C70A0_649550;
extern AnimationHeader D_802C70B4_649564;
extern AnimationHeader D_802C70C8_649578;
extern AnimationHeader D_802C70DC_64958C;
extern InteractionHandler D_802C70F0_6495A0[3];
extern RandomState D_802C7120_6495D0[3];
extern PokemonAnimationSetup D_802C7138_6495E8;
extern PokemonInitData D_802C714C_6495FC;
extern PokemonAnimationSetup D_802C7180_649630;
extern PokemonInitData D_802C7194_649644;
extern s32 D_802C71D0_649680[1];
extern s32 D_802C71D4_649684[3];
extern s32 D_802C71E0_649690[3];
extern s32 D_802C71EC_64969C[1];
extern s32 D_802C71F0_6496A0[1];
extern s32 D_802C71F4_6496A4[1];
extern s32 D_802C71F8_6496A8[1];
extern AnimationHeader D_802C71FC_6496AC;
extern AnimationHeader D_802C7210_6496C0;
extern AnimationHeader D_802C7224_6496D4;
extern AnimationHeader D_802C7238_6496E8;
extern AnimationHeader D_802C724C_6496FC;
extern AnimationHeader D_802C7260_649710;
extern AnimationHeader D_802C7274_649724;
extern AnimationHeader D_802C7288_649738;
extern f32 D_802C729C_64974C;
extern GObj* D_802C72A0_649750[4];
extern InteractionHandler7 D_802C72B0_649760;
extern InteractionHandler4 D_802C7320_6497D0;
extern InteractionHandler4 D_802C7360_649810;
extern InteractionHandler4 D_802C73A0_649850;
extern InteractionHandler D_802C73E0_649890[3];
extern Vec3f D_802C7410_6498C0;
extern InteractionHandler6 D_802C741C_6498CC;
extern Bytes3 D_802C747C_64992C;
extern Bytes12 D_802C7480_649930;
extern InteractionHandler6 D_802C748C_64993C;
extern InteractionHandler3 D_802C74EC_64999C;
extern InteractionHandler3 D_802C751C_6499CC;
extern InteractionHandler D_802C754C_6499FC[3];
extern PokemonAnimationSetup D_802C757C_649A2C;
extern PokemonInitData D_802C7590_649A40;
extern s32 D_802C75D0_649A80[2];
extern AnimationHeader D_802C75D8_649A88;
extern GObj* D_802C75EC_649A9C;
extern GObj* D_802C75F0_649AA0;
extern InteractionHandler D_802C75F4_649AA4[2];
extern InteractionHandler D_802C7614_649AC4[2];
extern InteractionHandler D_802C7634_649AE4[4];
extern InteractionHandler2 D_802C7674_649B24;
extern InteractionHandler D_802C7694_649B44[4];
extern InteractionHandler4 D_802C76D4_649B84;
extern PokemonAnimationSetup D_802C7714_649BC4;
extern PokemonInitData D_802C7728_649BD8;
extern s32 D_802C7760_649C10[1];
extern s32 D_802C7764_649C14[3];
extern s32 D_802C7770_649C20[3];
extern s32 D_802C777C_649C2C[3];
extern AnimationHeader D_802C7788_649C38;
extern AnimationHeader D_802C779C_649C4C;
extern AnimationHeader D_802C77B0_649C60;
extern AnimationHeader D_802C77C4_649C74;
extern InteractionHandler D_802C77D8_649C88[1];
extern PokemonAnimationSetup D_802C77E8_649C98;
extern PokemonInitData D_802C77FC_649CAC;
extern s32 D_802C7830_649CE0[1];
extern s32 D_802C7834_649CE4[3];
extern s32 D_802C7840_649CF0[1];
extern s32 D_802C7844_649CF4[2];
extern s32 D_802C784C_649CFC[2];
extern s32 D_802C7854_649D04[1];
extern s32 D_802C7858_649D08[2];
extern s32 D_802C7860_649D10[3];
extern AnimationHeader D_802C786C_649D1C;
extern AnimationHeader D_802C7880_649D30;
extern AnimationHeader D_802C7894_649D44;
extern AnimationHeader D_802C78A8_649D58;
extern AnimationHeader D_802C78BC_649D6C;
extern AnimationHeader D_802C78D0_649D80;
extern AnimationHeader D_802C78E4_649D94;
extern AnimationHeader D_802C78F8_649DA8;
extern AnimationHeader D_802C790C_649DBC;
extern AnimationHeader D_802C7920_649DD0;
extern AnimationHeader D_802C7934_649DE4;
extern AnimationHeader D_802C7948_649DF8;
extern AnimationHeader D_802C795C_649E0C;
extern InteractionHandler D_802C7970_649E20[1];
extern f32 D_802C7980_649E30;
extern InteractionHandler4 D_802C7984_649E34;
extern Vec3f D_802C79C4_649E74;
extern InteractionHandler8 D_802C79D0_649E80;
extern InteractionHandler5 D_802C7A50_649F00;
extern PokemonAnimationSetup D_802C7AA0_649F50;
extern PokemonInitData D_802C7AB4_649F64;
extern s32 D_802C7AF0_649FA0[4];
extern s32 D_802C7B00_649FB0[2];
extern s32 D_802C7B08_649FB8[2];
extern AnimationHeader D_802C7B10_649FC0;
extern AnimationHeader D_802C7B24_649FD4;
extern AnimationHeader D_802C7B38_649FE8;
extern GObj* D_802C7B4C_649FFC;
extern InteractionHandler D_802C7B50_64A000[2];
extern InteractionHandler D_802C7B78_64A028[1];
extern PokemonAnimationSetup D_802C7B88_64A038;
extern PokemonInitData D_802C7B9C_64A04C;
extern AnimationHeader D_802C7BD0_64A080;
extern AnimationHeader D_802C7BE4_64A094;
extern AnimationHeader D_802C7BF8_64A0A8;
extern AnimationHeader D_802C7C0C_64A0BC;
extern Struct_800AB050* D_802C7C20_64A0D0[2];
extern EggStruct D_802C7C28_64A0D8;
extern GObj* D_802C7C3C_64A0EC;
extern InteractionHandler D_802C7C40_64A0F0[6];
extern InteractionHandler D_802C7CA8_64A158[1];
extern PokemonAnimationSetup D_802C7CB8_64A168;
extern PokemonInitData D_802C7CCC_64A17C;
extern s32 D_802C7D00_64A1B0[1];
extern s32 D_802C7D04_64A1B4[1];
extern s32 D_802C7D08_64A1B8[1];
extern s32 D_802C7D0C_64A1BC[2];
extern s32 D_802C7D14_64A1C4[2];
extern AnimationHeader D_802C7D1C_64A1CC;
extern AnimationHeader D_802C7D30_64A1E0;
extern AnimationHeader D_802C7D44_64A1F4;
extern AnimationHeader D_802C7D58_64A208;
extern AnimationHeader D_802C7D6C_64A21C;
extern AnimationHeader D_802C7D80_64A230;
extern InteractionHandler D_802C7D94_64A244[4];
extern InteractionHandler D_802C7DDC_64A28C[4];
extern InteractionHandler D_802C7E1C_64A2CC[3];
extern InteractionHandler D_802C7E4C_64A2FC[3];
extern InteractionHandler D_802C7E7C_64A32C[3];
extern PokemonAnimationSetup D_802C7EAC_64A35C;
extern PokemonInitData D_802C7EC0_64A370;
extern s32 D_802C7F00_64A3B0[2];
extern AnimationHeader D_802C7F08_64A3B8;
extern PokemonAnimationSetup D_802C7F1C_64A3CC;
extern PokemonInitData D_802C7F30_64A3E0;
extern AnimationHeader D_802C7F70_64A420;
extern AnimationHeader D_802C7F84_64A434;
extern AnimationHeader D_802C7F98_64A448;
extern AnimationHeader D_802C7FAC_64A45C;
extern s32 D_802C7FC0_64A470;
extern s32 D_802C7FC4_64A474;
extern InteractionHandler D_802C7FC8_64A478[2];
extern UnkBlueShark D_802C7FE8_64A498;
extern PokemonAnimationSetup D_802C7FEC_64A49C;
extern PokemonInitData D_802C8000_64A4B0;
extern s32 D_802C8040_64A4F0;
extern GObj* D_802C8044_64A4F4;

/* ROM 648600; VRAM 802C6150. */
EnvSoundData D_802C6150_648600[57] = {
    { 145, 0, 22 },
    { 213, 1, 20 },
    { 214, 1, 20 },
    { 152, 1, 30 },
    { 216, 1, 28 },
    { 217, 1, 28 },
    { 332, 1, 14 },
    { 333, 1, 14 },
    { 334, 1, 14 },
    { 149, 0, 14 },
    { 150, 0, 14 },
    { 103, 0, 14 },
    { 210, 1, 8 },
    { 211, 1, 8 },
    { 376, 0, 8 },
    { 114, 0, 8 },
    { 196, 1, 12 },
    { 198, 1, 12 },
    { 197, 1, 12 },
    { 132, 0, 15 },
    { 366, 0, 8 },
    { 134, 0, 18 },
    { 139, 0, 18 },
    { 119, 0, 15 },
    { 306, 1, 12 },
    { 307, 1, 12 },
    { 308, 1, 12 },
    { 372, 0, 8 },
    { 263, 1, 18 },
    { 354, 1, 15 },
    { 264, 1, 12 },
    { 265, 1, 10 },
    { 266, 1, 10 },
    { 127, 0, 12 },
    { 360, 0, 12 },
    { 371, 0, 10 },
    { 335, 1, 12 },
    { 336, 1, 12 },
    { 337, 1, 12 },
    { 338, 1, 12 },
    { 339, 1, 12 },
    { 340, 1, 12 },
    { 341, 1, 12 },
    { 321, 1, 12 },
    { 322, 1, 12 },
    { 323, 1, 12 },
    { 136, 0, 12 },
    { 188, 1, 26 },
    { 106, 0, 26 },
    { 107, 0, 26 },
    { 153, 0, 26 },
    { 328, 1, 18 },
    { 329, 1, 22 },
    { 330, 1, 22 },
    { 331, 1, 22 },
    { 309, 1, 8 },
    { 133, 0, 8 },
};

/* ROM 6486E4; VRAM 802C6234. */
PokemonDef D_802C6234_6486E4[18] = {
    { 1, (pokemonInit) func_802BEFD8_641488, pokemonChangeBlockOnGround, pokemonRemoveOne },
    { 132, (pokemonInit) func_802BF55C_641A0C, pokemonChangeBlockOnGround, pokemonRemoveOne },
    { 70, (pokemonInit) func_802BFDA0_642250, pokemonChangeBlockOnGround, pokemonRemoveOne },
    { 71, (pokemonInit) func_802C0104_6425B4, pokemonChangeBlockOnGround, pokemonRemoveOne },
    { 39, (pokemonInit) func_802C2994_644E44, pokemonChangeBlock, pokemonRemoveOne },
    { 109, (pokemonInit) func_802C07D4_642C84, pokemonChangeBlock, pokemonRemoveOne },
    { 144, func_802C49A8_646E58, pokemonChangeBlock, pokemonRemoveOne },
    { 601, func_802C4E64_647314, pokemonChangeBlock, pokemonRemoveOne },
    { 124, (pokemonInit) func_802C5548_6479F8, pokemonChangeBlock, pokemonRemoveOne },
    { 88, (pokemonInit) func_802C10C8_643578, pokemonChangeBlockOnGround, pokemonRemoveOne },
    { 89, (pokemonInit) func_802C13EC_64389C, pokemonChangeBlockOnGround, pokemonRemoveOne },
    { 41, (pokemonInit) func_802C3250_645700, pokemonChangeBlock, pokemonRemoveOne },
    { 25, (pokemonInit) func_802C465C_646B0C, pokemonChangeBlock, pokemonRemoveOne },
    { 129, (pokemonInit) func_802C3388_645838, pokemonChangeBlockOnGround, pokemonRemoveOne },
    { 1003, func_8035E0D4_4FE4E4, pokemonChangeBlock, pokemonRemoveOne },
    { 1018, (pokemonInit) func_802C55D4_647A84, pokemonChangeBlock, pokemonRemoveOne },
    { 1001, (pokemonInit) func_802C5B28_647FD8, pokemonChangeBlock, pokemonRemoveOne },
    { 0, NULL, NULL, NULL }
};

/* ROM 648804; VRAM 802C6354. */
u16 D_802C6354_648804 = 0;

/* ROM 648808; VRAM 802C6358. */
PokemonDef D_802C6358_648808 = { 129, (pokemonInit) func_802C3388_645838, pokemonChangeBlockOnGround, pokemonRemoveOne };

/* ROM 648818; VRAM 802C6368. */
RandomState2 D_802C6368_648818[2] = {
    { 3, func_802BDD00_6401B0 },
    { 7, NULL },
};

/* ROM 648828; VRAM 802C6378. */
s32 D_802C6378_648828 = 0;

/* ROM 64882C; VRAM 802C637C. */
ScreenSettings D_802C637C_64882C = { D_803B5000, D_803DA800, NULL, NULL, 320, 240, 2713 };

/* ROM 648848; VRAM 802C6398. */
SceneSetup D_802C6398_648848 = {
    { 0, omUpdateAll, omDrawAll, (Vtx*) cave_assets_VRAM_END, 0, 1, 2, 20480, 8192, 1024, 0, 51200, 2, 16384, func_800A1A50, contUpdate },
    0,
    1088,
    0,
    0,
    0,
    0,
    92,
    0,
    NULL,
    func_802BE3A8_640858,
    0,
    0,
    0,
    136,
    0,
    88,
    0,
    144,
    func_802BE22C_6406DC
};

/* Bounded original zero-filled native record alignment (12 bytes). */
char D_802C6424_6488D4_padding[12] = "";

/* ROM 6488E0; VRAM 802C6430. */
u32 D_802C6430_6488E0 = 0;

/* Bounded original zero-filled native record alignment (12 bytes). */
char D_802C6434_6488E4_padding[12] = "";

/* ROM 6488F0; VRAM 802C6440. */
s32 D_802C6440_6488F0[1] = { 224 };

/* ROM 6488F4; VRAM 802C6444. */
s32 D_802C6444_6488F4[1] = { 227 };

/* ROM 6488F8; VRAM 802C6448. */
s32 D_802C6448_6488F8[1] = { 226 };

/* ROM 6488FC; VRAM 802C644C. */
s32 D_802C644C_6488FC[1] = { 225 };

/* ROM 648900; VRAM 802C6450. */
s32 D_802C6450_648900[2] = { 223, 366 };

/* ROM 648908; VRAM 802C6458. */
s32 D_802C6458_648908[1] = { 196 };

/* ROM 64890C; VRAM 802C645C. */
s32 D_802C645C_64890C[1] = { 198 };

/* ROM 648910; VRAM 802C6460. */
s32 D_802C6460_648910[2] = { 197, 366 };

/* ROM 648918; VRAM 802C6468. */
s32 D_802C6468_648918[2] = { 0, 132 };

/* ROM 648920; VRAM 802C6470. */
AnimationHeader D_802C6470_648920 = { 1.0f, 120.0f, D_80121410_9E830, D_80129980_A6DA0, NULL };

/* ROM 648934; VRAM 802C6484. */
AnimationHeader D_802C6484_648934 = { 1.0f, 320.0f, D_80123320_A0740, D_80129AE0_A6F00, NULL };

/* ROM 648948; VRAM 802C6498. */
AnimationHeader D_802C6498_648948 = { 1.0f, 50.0f, D_80124C20_A2040, D_80129C10_A7030, D_802C6440_6488F0 };

/* ROM 64895C; VRAM 802C64AC. */
AnimationHeader D_802C64AC_64895C = { 1.25f, 80.0f, D_8011F9D0_9CDF0, D_80129750_A6B70, NULL };

/* ROM 648970; VRAM 802C64C0. */
AnimationHeader D_802C64C0_648970 = { 2.07999992f, 80.0f, D_80120850_9DC70, NULL, NULL };

/* ROM 648984; VRAM 802C64D4. */
AnimationHeader D_802C64D4_648984 = { 0.699999988f, 80.0f, D_80125F00_A3320, D_80129DF0_A7210, D_802C6444_6488F4 };

/* ROM 648998; VRAM 802C64E8. */
AnimationHeader D_802C64E8_648998 = { 1.0f, 70.0f, D_80126680_A3AA0, D_80129F00_A7320, D_802C6448_6488F8 };

/* ROM 6489AC; VRAM 802C64FC. */
AnimationHeader D_802C64FC_6489AC = { 0.75f, 20.0f, D_80121A50_9EE70, D_80129A10_A6E30, NULL };

/* ROM 6489C0; VRAM 802C6510. */
AnimationHeader D_802C6510_6489C0 = { 1.0f, 142.0f, D_80125130_A2550, D_80129CC0_A70E0, D_802C644C_6488FC };

/* ROM 6489D4; VRAM 802C6524. */
AnimationHeader D_802C6524_6489D4 = { 1.0f, 176.0f, D_801283C0_A57E0, D_80129FF0_A7410, D_802C6450_648900 };

/* ROM 6489E8; VRAM 802C6538. */
AnimationHeader D_802C6538_6489E8 = { 1.0f, 120.0f, D_80120DD0_9E1F0, D_80129910_A6D30, NULL };

/* ROM 6489FC; VRAM 802C654C. */
AnimationHeader D_802C654C_6489FC = { 1.0f, 320.0f, D_80121F30_9F350, D_80129A80_A6EA0, NULL };

/* ROM 648A10; VRAM 802C6560. */
AnimationHeader D_802C6560_648A10 = { 1.0f, 50.0f, D_80124710_A1B30, D_80129BA0_A6FC0, D_802C6458_648908 };

/* ROM 648A24; VRAM 802C6574. */
AnimationHeader D_802C6574_648A24 = { 1.25f, 80.0f, D_8011F0D0_9C4F0, D_801296E0_A6B00, NULL };

/* ROM 648A38; VRAM 802C6588. */
AnimationHeader D_802C6588_648A38 = { 2.07999992f, 80.0f, D_801202D0_9D6F0, D_80129800_A6C20, NULL };

/* ROM 648A4C; VRAM 802C659C. */
AnimationHeader D_802C659C_648A4C = { 0.75f, 80.0f, D_80125B80_A2FA0, D_80129D80_A71A0, D_802C645C_64890C };

/* ROM 648A60; VRAM 802C65B0. */
AnimationHeader D_802C65B0_648A60 = { 1.0f, 176.0f, D_80127090_A44B0, D_80129F80_A73A0, D_802C6460_648910 };

/* ROM 648A74; VRAM 802C65C4. */
AnimationHeader D_802C65C4_648A74 = { 0.75f, 57.0f, D_80126310_A3730, D_80129EA0_A72C0, D_802C6468_648918 };

/* ROM 648A88; VRAM 802C65D8. */
PokemonDef D_802C65D8_648A88 = { 132, (pokemonInit) func_802BF55C_641A0C, pokemonChangeBlockOnGround, pokemonRemoveOne };

/* ROM 648A98; VRAM 802C65E8. */
InteractionHandler D_802C65E8_648A98[9] = {
    { 9, func_802BEB24_640FD4, 0.0f, NULL },
    { 13, func_802BEBBC_64106C, 0.0f, NULL },
    { 10, func_802BEC34_6410E4, 0.0f, NULL },
    { 14, func_802BED04_6411B4, 0.0f, NULL },
    { 15, func_802BEEF4_6413A4, 0.0f, NULL },
    { 5, func_802BEF18_6413C8, 0.0f, NULL },
    { 6, func_802BEF18_6413C8, 0.0f, NULL },
    { 7, func_802BEF18_6413C8, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 648B28; VRAM 802C6678. */
InteractionHandler D_802C6678_648B28[8] = {
    { 9, func_802BEB24_640FD4, 0.0f, NULL },
    { 13, func_802BEBBC_64106C, 0.0f, NULL },
    { 10, func_802BEC34_6410E4, 0.0f, NULL },
    { 14, func_802BED04_6411B4, 0.0f, NULL },
    { 5, func_802BEF18_6413C8, 0.0f, NULL },
    { 6, func_802BEF18_6413C8, 0.0f, NULL },
    { 7, func_802BEF18_6413C8, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 648BA8; VRAM 802C66F8. */
InteractionHandler D_802C66F8_648BA8[3] = {
    { 9, func_802BEB24_640FD4, 0.0f, NULL },
    { 13, func_802BEBBC_64106C, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 648BD8; VRAM 802C6728. */
InteractionHandler D_802C6728_648BD8[5] = {
    { 9, func_802BEB24_640FD4, 0.0f, NULL },
    { 13, func_802BEBBC_64106C, 0.0f, NULL },
    { 10, func_802BEC34_6410E4, 0.0f, NULL },
    { 14, func_802BED04_6411B4, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 648C28; VRAM 802C6778. */
InteractionHandler D_802C6778_648C28[3] = {
    { 9, func_802BEB24_640FD4, 0.0f, NULL },
    { 13, func_802BEBBC_64106C, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 648C58; VRAM 802C67A8. */
InteractionHandler D_802C67A8_648C58[4] = {
    { 9, func_802BEB24_640FD4, 0.0f, NULL },
    { 13, func_802BEBBC_64106C, 0.0f, NULL },
    { 10, func_802BEC34_6410E4, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 648C98; VRAM 802C67E8. */
RandomState D_802C67E8_648C98[5] = {
    { 100, func_802BE8D4_640D84 },
    { 100, func_802BEA24_640ED4 },
    { 100, func_802BE944_640DF4 },
    { 100, func_802BE9B4_640E64 },
    { 0, NULL },
};

/* ROM 648CC0; VRAM 802C6810. */
PokemonAnimationSetup D_802C6810_648CC0 = { &D_802C6538_6489E8, func_802BE898_640D48, 0, { 0, 0, 0 }, NULL, NULL };

/* ROM 648CD4; VRAM 802C6824. */
PokemonInitData D_802C6824_648CD4 = { bulbasaur_model, bulbasaur_materials, renderPokemonModelTypeJFogged, &D_802C6810_648CC0, { 2.0f, 2.0f, 2.0f }, { 0.0f, 88.0f, 5.0f }, 45.0f, 37, 0, 0, 0, { 0, 0, 0 } };

/* Bounded original zero-filled native record alignment (8 bytes). */
char D_802C6858_648D08_padding[8] = "";

/* ROM 648D10; VRAM 802C6860. */
s32 D_802C6860_648D10[1] = { 306 };

/* ROM 648D14; VRAM 802C6864. */
s32 D_802C6864_648D14[1] = { 307 };

/* ROM 648D18; VRAM 802C6868. */
s32 D_802C6868_648D18[2] = { 308, 372 };

/* ROM 648D20; VRAM 802C6870. */
AnimationHeader D_802C6870_648D20 = { 0.5f, 96.0f, D_8017EE10_24ABC0, NULL, NULL };

/* ROM 648D34; VRAM 802C6884. */
AnimationHeader D_802C6884_648D34 = { 0.5f, 30.0f, D_8017D950_249700, NULL, NULL };

/* ROM 648D48; VRAM 802C6898. */
AnimationHeader D_802C6898_648D48 = { 0.600000024f, 30.0f, D_8017E460_24A210, NULL, NULL };

/* ROM 648D5C; VRAM 802C68AC. */
AnimationHeader D_802C68AC_648D5C = { 0.5f, 40.0f, D_80183C40_24F9F0, NULL, D_802C6860_648D10 };

/* ROM 648D70; VRAM 802C68C0. */
AnimationHeader D_802C68C0_648D70 = { 0.699999988f, 75.0f, D_80184C20_2509D0, NULL, D_802C6864_648D14 };

/* ROM 648D84; VRAM 802C68D4. */
AnimationHeader D_802C68D4_648D84 = { 0.600000024f, 30.0f, D_80182410_24E1C0, NULL, NULL };

/* ROM 648D98; VRAM 802C68E8. */
AnimationHeader D_802C68E8_648D98 = { 0.600000024f, 60.0f, D_80182D00_24EAB0, NULL, NULL };

/* ROM 648DAC; VRAM 802C68FC. */
AnimationHeader D_802C68FC_648DAC = { 0.600000024f, 85.0f, D_80186450_252200, NULL, D_802C6868_648D18 };

/* ROM 648DC0; VRAM 802C6910. */
AnimationHeader D_802C6910_648DC0 = { 0.75f, 50.0f, D_80181570_24D320, NULL, NULL };

/* ROM 648DD4; VRAM 802C6924. */
InteractionHandler D_802C6924_648DD4[4] = {
    { 9, func_802BF220_6416D0, 0.0f, NULL },
    { 13, func_802BF2D0_641780, 0.0f, NULL },
    { 14, func_802BF338_6417E8, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 648E14; VRAM 802C6964. */
RandomState D_802C6964_648E14[3] = {
    { 100, func_802BF0B4_641564 },
    { 100, func_802BF124_6415D4 },
    { 0, NULL },
};

/* ROM 648E2C; VRAM 802C697C. */
InteractionHandler D_802C697C_648E2C[3] = {
    { 9, func_802BF220_6416D0, 0.0f, NULL },
    { 13, func_802BF2D0_641780, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 648E5C; VRAM 802C69AC. */
PokemonAnimationSetup D_802C69AC_648E5C = { &D_802C6870_648D20, func_802BF020_6414D0, 0, { 0, 0, 0 }, NULL, NULL };

/* ROM 648E70; VRAM 802C69C0. */
PokemonInitData D_802C69C0_648E70 = { ditto_model, NULL, renderPokemonModelTypeIFogged, &D_802C69AC_648E5C, { 2.5999999f, 2.5999999f, 2.5999999f }, { 0.0f, 30.0f, 0.0f }, 23.0f, 37, 0, 0, 0, { 0, 0, 0 } };

/* Bounded original zero-filled native record alignment (12 bytes). */
char D_802C69F4_648EA4_padding[12] = "";

/* ROM 648EB0; VRAM 802C6A00. */
s32 D_802C6A00_648EB0[1] = { 328 };

/* ROM 648EB4; VRAM 802C6A04. */
s32 D_802C6A04_648EB4[1] = { 328 };

/* ROM 648EB8; VRAM 802C6A08. */
s32 D_802C6A08_648EB8[1] = { 329 };

/* ROM 648EBC; VRAM 802C6A0C. */
s32 D_802C6A0C_648EBC[1] = { 330 };

/* ROM 648EC0; VRAM 802C6A10. */
s32 D_802C6A10_648EC0[1] = { 331 };

/* ROM 648EC4; VRAM 802C6A14. */
s32 D_802C6A14_648EC4[1] = { 331 };

/* ROM 648EC8; VRAM 802C6A18. */
AnimationHeader D_802C6A18_648EC8 = { 0.5f, 59.0f, D_801A8C10_2749C0, NULL, NULL };

/* ROM 648EDC; VRAM 802C6A2C. */
AnimationHeader D_802C6A2C_648EDC = { 0.5f, 59.0f, D_801AA220_275FD0, D_801AE8C0_27A670, D_802C6A00_648EB0 };

/* ROM 648EF0; VRAM 802C6A40. */
AnimationHeader D_802C6A40_648EF0 = { 0.5f, 35.0f, D_801A8250_274000, NULL, D_802C6A04_648EB4 };

/* ROM 648F04; VRAM 802C6A54. */
AnimationHeader D_802C6A54_648F04 = { 0.5f, 65.0f, D_801ACBD0_278980, D_801AE9A0_27A750, D_802C6A08_648EB8 };

/* ROM 648F18; VRAM 802C6A68. */
AnimationHeader D_802C6A68_648F18 = { 0.5f, 25.0f, D_801ADA80_279830, D_801AEB60_27A910, D_802C6A0C_648EBC };

/* ROM 648F2C; VRAM 802C6A7C. */
AnimationHeader D_802C6A7C_648F2C = { 0.5f, 30.0f, D_801A9A10_2757C0, D_801AE730_27A4E0, D_802C6A10_648EC0 };

/* ROM 648F40; VRAM 802C6A90. */
AnimationHeader D_802C6A90_648F40 = { 0.5f, 80.0f, D_801AB240_276FF0, NULL, D_802C6A14_648EC4 };

/* ROM 648F54; VRAM 802C6AA4. */
f32 D_802C6AA4_648F54 = 0.0f;

/* ROM 648F58; VRAM 802C6AA8. */
InteractionHandler D_802C6AA8_648F58[3] = {
    { 9, func_802BF894_641D44, 0.0f, NULL },
    { 13, func_802BF894_641D44, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 648F88; VRAM 802C6AD8. */
InteractionHandler D_802C6AD8_648F88[3] = {
    { 9, func_802BFA3C_641EEC, 0.0f, NULL },
    { 13, func_802BFA3C_641EEC, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 648FB8; VRAM 802C6B08. */
InteractionHandler D_802C6B08_648FB8[2] = {
    { 30, func_802BFBF0_6420A0, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 648FD8; VRAM 802C6B28. */
RandomState D_802C6B28_648FD8[4] = {
    { 100, func_802BF824_641CD4 },
    { 100, func_802BF7B4_641C64 },
    { 100, func_802BF68C_641B3C },
    { 0, NULL },
};

/* ROM 648FF8; VRAM 802C6B48. */
PokemonAnimationSetup D_802C6B48_648FF8 = { &D_802C6A18_648EC8, func_802BF5A0_641A50, 0, { 0, 0, 0 }, NULL, NULL };

/* ROM 64900C; VRAM 802C6B5C. */
PokemonInitData D_802C6B5C_64900C = { weepinbell_model, D_8033AB80_6BD030, renderPokemonModelTypeIFogged, &D_802C6B48_648FF8, { 2.0f, 2.0f, 2.0f }, { 0.0f, 0.0f, 0.0f }, 45.0f, 37, 0, 0, 0, { 0, 0, 0 } };

/* ROM 649040; VRAM 802C6B90. */
s32 D_802C6B90_649040[4] = { 188, 106, 107, 153 };

/* ROM 649050; VRAM 802C6BA0. */
s32 D_802C6BA0_649050[1] = { 188 };

/* ROM 649054; VRAM 802C6BA4. */
AnimationHeader D_802C6BA4_649054 = { 0.699999988f, 102.0f, D_801A2EF0_26ECA0, D_801A5250_271000, NULL };

/* ROM 649068; VRAM 802C6BB8. */
AnimationHeader D_802C6BB8_649068 = { 0.5f, 59.0f, D_801A47D0_270580, D_801A54D0_271280, D_802C6B90_649040 };

/* ROM 64907C; VRAM 802C6BCC. */
AnimationHeader D_802C6BCC_64907C = { 0.699999988f, 80.0f, D_801A39C0_26F770, D_801A5380_271130, D_802C6BA0_649050 };

/* ROM 649090; VRAM 802C6BE0. */
InteractionHandler D_802C6BE0_649090[3] = {
    { 9, func_802C00B0_642560, 0.0f, NULL },
    { 13, func_802C00B0_642560, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 6490C0; VRAM 802C6C10. */
InteractionHandler D_802C6C10_6490C0[2] = {
    { 29, func_802BFE34_6422E4, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 6490E0; VRAM 802C6C30. */
InteractionHandler D_802C6C30_6490E0[2] = {
    { 31, func_802BFEF0_6423A0, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 649100; VRAM 802C6C50. */
PokemonAnimationSetup D_802C6C50_649100 = { &D_802C6BA4_649054, func_802BFDE0_642290, 0, { 0, 0, 0 }, NULL, NULL };

/* ROM 649114; VRAM 802C6C64. */
PokemonInitData D_802C6C64_649114 = { victreebel_model, D_80336310_6B87C0, renderPokemonModelTypeDFogged, &D_802C6C50_649100, { 2.0f, 2.0f, 2.0f }, { 0.0f, 0.0f, 0.0f }, 87.0f, 37, 0, 0, 0, { 0, 0, 0 } };

/* Bounded original zero-filled native record alignment (8 bytes). */
char D_802C6C98_649148_padding[8] = "";

/* ROM 649150; VRAM 802C6CA0. */
s32 D_802C6CA0_649150[2] = { 334, 150 };

/* ROM 649158; VRAM 802C6CA8. */
s32 D_802C6CA8_649158[2] = { 332, 149 };

/* ROM 649160; VRAM 802C6CB0. */
s32 D_802C6CB0_649160[2] = { 333, 150 };

/* ROM 649168; VRAM 802C6CB8. */
s32 D_802C6CB8_649168[2] = { 333, 150 };

/* ROM 649170; VRAM 802C6CC0. */
s32 D_802C6CC0_649170[2] = { 333, 150 };

/* ROM 649178; VRAM 802C6CC8. */
s32 D_802C6CC8_649178[3] = { 334, 149, 103 };

/* ROM 649184; VRAM 802C6CD4. */
AnimationHeader D_802C6CD4_649184 = { 0.5f, 50.0f, D_80166B20_2328D0, D_8016E240_239FF0, D_802C6CA0_649150 };

/* ROM 649198; VRAM 802C6CE8. */
AnimationHeader D_802C6CE8_649198 = { 0.5f, 100.0f, D_801676C0_233470, D_8016E570_23A320, D_802C6CA8_649158 };

/* ROM 6491AC; VRAM 802C6CFC. */
AnimationHeader D_802C6CFC_6491AC = { 0.340000004f, 180.0f, D_8016B2D0_237080, D_8016F440_23B1F0, D_802C6CB0_649160 };

/* ROM 6491C0; VRAM 802C6D10. */
AnimationHeader D_802C6D10_6491C0 = { 0.340000004f, 160.0f, D_801680F0_233EA0, D_8016E910_23A6C0, D_802C6CB8_649168 };

/* ROM 6491D4; VRAM 802C6D24. */
AnimationHeader D_802C6D24_6491D4 = { 0.330000013f, 120.0f, D_801657B0_231560, D_8016DCF0_239AA0, D_802C6CC0_649170 };

/* ROM 6491E8; VRAM 802C6D38. */
AnimationHeader D_802C6D38_6491E8 = { 0.5f, 100.0f, D_8016A380_236130, D_8016EF90_23AD40, D_802C6CC8_649178 };

/* ROM 6491FC; VRAM 802C6D4C. */
GObj* D_802C6D4C_6491FC[4] = { NULL, NULL, NULL, NULL };

/* ROM 64920C; VRAM 802C6D5C. */
u8 D_802C6D5C_64920C[4] = { 0, 0, 0, 0 };

/* ROM 649210; VRAM 802C6D60. */
InteractionHandler3 D_802C6D60_649210 = { {
    { 9, func_802C0510_6429C0, 0.0f, NULL },
    { 13, func_802C0510_6429C0, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
} };

/* ROM 649240; VRAM 802C6D90. */
InteractionHandler D_802C6D90_649240[2] = {
    { 16, func_802C0330_6427E0, 4000.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 649260; VRAM 802C6DB0. */
InteractionHandler6 D_802C6DB0_649260 = { {
    { 9, func_802C0510_6429C0, 0.0f, NULL },
    { 13, func_802C0510_6429C0, 0.0f, NULL },
    { 5, func_802C0630_642AE0, 0.0f, NULL },
    { 6, func_802C06BC_642B6C, 0.0f, NULL },
    { 7, func_802C0748_642BF8, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
} };

/* ROM 6492C0; VRAM 802C6E10. */
InteractionHandler5 D_802C6E10_6492C0 = { {
    { 9, func_802C0510_6429C0, 0.0f, NULL },
    { 13, func_802C0510_6429C0, 0.0f, NULL },
    { 6, func_802C06BC_642B6C, 0.0f, NULL },
    { 7, func_802C0748_642BF8, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
} };

/* ROM 649310; VRAM 802C6E60. */
InteractionHandler5 D_802C6E60_649310 = { {
    { 9, func_802C0510_6429C0, 0.0f, NULL },
    { 13, func_802C0510_6429C0, 0.0f, NULL },
    { 5, func_802C0630_642AE0, 0.0f, NULL },
    { 7, func_802C0748_642BF8, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
} };

/* ROM 649360; VRAM 802C6EB0. */
InteractionHandler5 D_802C6EB0_649360 = { {
    { 9, func_802C0510_6429C0, 0.0f, NULL },
    { 13, func_802C0510_6429C0, 0.0f, NULL },
    { 5, func_802C0630_642AE0, 0.0f, NULL },
    { 6, func_802C06BC_642B6C, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
} };

/* ROM 6493B0; VRAM 802C6F00. */
PokemonAnimationSetup D_802C6F00_6493B0 = { &D_802C6CD4_649184, func_802C0220_6426D0, 0, { 0, 0, 0 }, NULL, NULL };

/* ROM 6493C4; VRAM 802C6F14. */
PokemonInitData D_802C6F14_6493C4 = { koffing_model, D_80321A30_6A3EE0, renderPokemonModelTypeJFogged, &D_802C6F00_6493B0, { 2.5f, 2.5f, 2.5f }, { 0.0f, 146.0f, 0.0f }, 34.0f, 37, 0, 0, 0, { 0, 0, 0 } };

/* Bounded original zero-filled native record alignment (8 bytes). */
char D_802C6F48_6493F8_padding[8] = "";

/* ROM 649400; VRAM 802C6F50. */
s32 D_802C6F50_649400[1] = { 213 };

/* ROM 649404; VRAM 802C6F54. */
s32 D_802C6F54_649404[1] = { 214 };

/* ROM 649408; VRAM 802C6F58. */
s32 D_802C6F58_649408[2] = { 0, 152 };

/* ROM 649410; VRAM 802C6F60. */
AnimationHeader D_802C6F60_649410 = { 0.5f, 36.0f, D_801580F0_223EA0, D_8015B8C0_227670, NULL };

/* ROM 649424; VRAM 802C6F74. */
AnimationHeader D_802C6F74_649424 = { 0.5f, 36.0f, D_801572A0_223050, D_8015B4F0_2272A0, NULL };

/* ROM 649438; VRAM 802C6F88. */
AnimationHeader D_802C6F88_649438 = { 0.800000012f, 36.0f, D_8015A380_226130, D_8015C410_2281C0, D_802C6F50_649400 };

/* ROM 64944C; VRAM 802C6F9C. */
AnimationHeader D_802C6F9C_64944C = { 0.5f, 36.0f, D_80158C90_224A40, D_8015BC90_227A40, D_802C6F54_649404 };

/* ROM 649460; VRAM 802C6FB0. */
AnimationHeader D_802C6FB0_649460 = { 0.5f, 36.0f, D_80159940_2256F0, D_8015BFA0_227D50, D_802C6F58_649408 };

/* ROM 649474; VRAM 802C6FC4. */
PokemonDef D_802C6FC4_649474 = { 89, (pokemonInit) func_802C13B4_643864, pokemonChangeBlock, pokemonRemoveOne };

/* ROM 649484; VRAM 802C6FD4. */
InteractionHandler D_802C6FD4_649484[4] = {
    { 9, func_802C0D34_6431E4, 0.0f, NULL },
    { 13, func_802C0E80_643330, 0.0f, NULL },
    { 24, NULL, 0.0f, func_802C1018_6434C8 },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 6494C4; VRAM 802C7014. */
RandomState D_802C7014_6494C4[3] = {
    { 100, func_802C0AF0_642FA0 },
    { 100, func_802C0BB0_643060 },
    { 0, NULL },
};

/* ROM 6494DC; VRAM 802C702C. */
PokemonAnimationSetup D_802C702C_6494DC = { &D_802C6F60_649410, func_802C0888_642D38, 0, { 0, 0, 0 }, NULL, NULL };

/* ROM 6494F0; VRAM 802C7040. */
PokemonInitData D_802C7040_6494F0 = { grimer_model, D_80317620_699AD0, renderPokemonModelTypeIFogged, &D_802C702C_6494DC, { 2.0f, 2.0f, 2.0f }, { 0.0f, 90.0f, 0.0f }, 65.0f, 37, 0, 0, 0, { 0, 0, 0 } };

/* Bounded original zero-filled native record alignment (12 bytes). */
char D_802C7074_649524_padding[12] = "";

/* ROM 649530; VRAM 802C7080. */
s32 D_802C7080_649530[1] = { 216 };

/* ROM 649534; VRAM 802C7084. */
s32 D_802C7084_649534[1] = { 217 };

/* ROM 649538; VRAM 802C7088. */
s32 D_802C7088_649538[1] = { 216 };

/* ROM 64953C; VRAM 802C708C. */
AnimationHeader D_802C708C_64953C = { 0.5f, 30.0f, D_8015EC20_22A9D0, D_80160EC0_22CC70, NULL };

/* ROM 649550; VRAM 802C70A0. */
AnimationHeader D_802C70A0_649550 = { 0.5f, 30.0f, D_8015E650_22A400, D_80160BA0_22C950, NULL };

/* ROM 649564; VRAM 802C70B4. */
AnimationHeader D_802C70B4_649564 = { 0.5f, 30.0f, D_80160160_22BF10, D_80161860_22D610, D_802C7080_649530 };

/* ROM 649578; VRAM 802C70C8. */
AnimationHeader D_802C70C8_649578 = { 0.5f, 30.0f, D_8015F820_22B5D0, D_80161540_22D2F0, D_802C7084_649534 };

/* ROM 64958C; VRAM 802C70DC. */
AnimationHeader D_802C70DC_64958C = { 0.5f, 30.0f, D_8015F1D0_22AF80, D_80161220_22CFD0, D_802C7088_649538 };

/* ROM 6495A0; VRAM 802C70F0. */
InteractionHandler D_802C70F0_6495A0[3] = {
    { 9, func_802C12E4_643794, 0.0f, NULL },
    { 13, func_802C134C_6437FC, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 6495D0; VRAM 802C7120. */
RandomState D_802C7120_6495D0[3] = {
    { 100, func_802C1178_643628 },
    { 100, func_802C11E8_643698 },
    { 0, NULL },
};

/* ROM 6495E8; VRAM 802C7138. */
PokemonAnimationSetup D_802C7138_6495E8 = { &D_802C708C_64953C, func_802C1124_6435D4, 0, { 0, 0, 0 }, NULL, NULL };

/* ROM 6495FC; VRAM 802C714C. */
PokemonInitData D_802C714C_6495FC = { muk_model, D_8031C830_69ECE0, renderPokemonModelTypeIFogged, &D_802C7138_6495E8, { 1.5f, 1.5f, 1.5f }, { 0.0f, 90.0f, -28.0f }, 126.0f, 37, 0, 0, 0, { 0, 0, 0 } };

/* ROM 649630; VRAM 802C7180. */
PokemonAnimationSetup D_802C7180_649630 = { &D_802C708C_64953C, func_802C1100_6435B0, 0, { 0, 0, 0 }, NULL, NULL };

/* ROM 649644; VRAM 802C7194. */
PokemonInitData D_802C7194_649644 = { muk_model, D_8031C830_69ECE0, renderPokemonModelTypeIFogged, &D_802C7180_649630, { 1.5f, 1.5f, 1.5f }, { 0.0f, 90.0f, -28.0f }, 126.0f, 37, 0, 0, 0, { 0, 0, 0 } };

/* Bounded original zero-filled native record alignment (8 bytes). */
char D_802C71C8_649678_padding[8] = "";

/* ROM 649680; VRAM 802C71D0. */
s32 D_802C71D0_649680[1] = { 338 };

/* ROM 649684; VRAM 802C71D4. */
s32 D_802C71D4_649684[3] = { 339, 340, 341 };

/* ROM 649690; VRAM 802C71E0. */
s32 D_802C71E0_649690[3] = { 339, 340, 341 };

/* ROM 64969C; VRAM 802C71EC. */
s32 D_802C71EC_64969C[1] = { 341 };

/* ROM 6496A0; VRAM 802C71F0. */
s32 D_802C71F0_6496A0[1] = { 336 };

/* ROM 6496A4; VRAM 802C71F4. */
s32 D_802C71F4_6496A4[1] = { 337 };

/* ROM 6496A8; VRAM 802C71F8. */
s32 D_802C71F8_6496A8[1] = { 335 };

/* ROM 6496AC; VRAM 802C71FC. */
AnimationHeader D_802C71FC_6496AC = { 0.270000011f, 50.0f, D_8018AD70_256B20, D_80192E30_25EBE0, D_802C71D0_649680 };

/* ROM 6496C0; VRAM 802C7210. */
AnimationHeader D_802C7210_6496C0 = { 0.5f, 180.0f, D_80190AA0_25C850, D_80193780_25F530, D_802C71D4_649684 };

/* ROM 6496D4; VRAM 802C7224. */
AnimationHeader D_802C7224_6496D4 = { 0.5f, 120.0f, D_8018DA20_2597D0, D_80193200_25EFB0, D_802C71E0_649690 };

/* ROM 6496E8; VRAM 802C7238. */
AnimationHeader D_802C7238_6496E8 = { 0.5f, 120.0f, D_80189BC0_255970, D_80192CF0_25EAA0, D_802C71EC_64969C };

/* ROM 6496FC; VRAM 802C724C. */
AnimationHeader D_802C724C_6496FC = { 0.469999999f, 100.0f, D_8018EBD0_25A980, D_801933D0_25F180, D_802C71F0_6496A0 };

/* ROM 649710; VRAM 802C7260. */
AnimationHeader D_802C7260_649710 = { 0.5f, 180.0f, D_8018F850_25B600, D_80193510_25F2C0, NULL };

/* ROM 649724; VRAM 802C7274. */
AnimationHeader D_802C7274_649724 = { 0.699999988f, 220.0f, D_8018BF00_257CB0, D_80192FF0_25EDA0, D_802C71F4_6496A4 };

/* ROM 649738; VRAM 802C7288. */
AnimationHeader D_802C7288_649738 = { 0.5f, 60.0f, D_801921E0_25DF90, D_801939E0_25F790, D_802C71F8_6496A8 };

/* ROM 64974C; VRAM 802C729C. */
f32 D_802C729C_64974C = 0.0f;

/* ROM 649750; VRAM 802C72A0. */
GObj* D_802C72A0_649750[4] = { NULL, NULL, NULL, NULL };

/* ROM 649760; VRAM 802C72B0. */
InteractionHandler7 D_802C72B0_649760 = { {
    { 9, NULL, 0.0f, func_802C1920_643DD0 },
    { 13, NULL, 0.0f, func_802C1920_643DD0 },
    { 5, func_802C1794_643C44, 0.0f, NULL },
    { 6, func_802C1818_643CC8, 0.0f, NULL },
    { 7, func_802C189C_643D4C, 0.0f, NULL },
    { 32, func_802C19BC_643E6C, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
} };

/* ROM 6497D0; VRAM 802C7320. */
InteractionHandler4 D_802C7320_6497D0 = { {
    { 6, func_802C1818_643CC8, 0.0f, NULL },
    { 7, func_802C189C_643D4C, 0.0f, NULL },
    { 32, func_802C19BC_643E6C, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
} };

/* ROM 649810; VRAM 802C7360. */
InteractionHandler4 D_802C7360_649810 = { {
    { 5, func_802C1794_643C44, 0.0f, NULL },
    { 7, func_802C189C_643D4C, 0.0f, NULL },
    { 32, func_802C19BC_643E6C, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
} };

/* ROM 649850; VRAM 802C73A0. */
InteractionHandler4 D_802C73A0_649850 = { {
    { 6, func_802C1818_643CC8, 0.0f, NULL },
    { 5, func_802C1794_643C44, 0.0f, NULL },
    { 32, func_802C19BC_643E6C, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
} };

/* ROM 649890; VRAM 802C73E0. */
InteractionHandler D_802C73E0_649890[3] = {
    { 9, func_802C1AC8_643F78, 0.0f, NULL },
    { 13, func_802C1AC8_643F78, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 6498C0; VRAM 802C7410. */
Vec3f D_802C7410_6498C0 = { 0.0f, 0.0f, 0.0f };

/* ROM 6498CC; VRAM 802C741C. */
InteractionHandler6 D_802C741C_6498CC = { {
    { 9, func_802C2504_6449B4, 0.0f, NULL },
    { 13, func_802C2504_6449B4, 0.0f, NULL },
    { 5, func_802C25D8_644A88, 0.0f, NULL },
    { 6, func_802C25D8_644A88, 0.0f, NULL },
    { 7, func_802C25D8_644A88, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
} };

/* ROM 64992C; VRAM 802C747C. */
Bytes3 D_802C747C_64992C = { { 3, 4, 5 } };

/* ROM 649930; VRAM 802C7480. */
Bytes12 D_802C7480_649930 = { { 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 } };

/* ROM 64993C; VRAM 802C748C. */
InteractionHandler6 D_802C748C_64993C = { {
    { 9, NULL, 0.0f, func_802C1920_643DD0 },
    { 13, NULL, 0.0f, func_802C1920_643DD0 },
    { 5, func_802C2854_644D04, 0.0f, NULL },
    { 6, func_802C28D0_644D80, 0.0f, NULL },
    { 7, func_802C294C_644DFC, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
} };

/* ROM 64999C; VRAM 802C74EC. */
InteractionHandler3 D_802C74EC_64999C = { {
    { 6, func_802C28D0_644D80, 0.0f, NULL },
    { 7, func_802C294C_644DFC, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
} };

/* ROM 6499CC; VRAM 802C751C. */
InteractionHandler3 D_802C751C_6499CC = { {
    { 5, func_802C2854_644D04, 0.0f, NULL },
    { 7, func_802C294C_644DFC, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
} };

/* ROM 6499FC; VRAM 802C754C. */
InteractionHandler D_802C754C_6499FC[3] = {
    { 6, func_802C28D0_644D80, 0.0f, NULL },
    { 5, func_802C2854_644D04, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 649A2C; VRAM 802C757C. */
PokemonAnimationSetup D_802C757C_649A2C = { &D_802C71FC_6496AC, func_802C14C4_643974, 0, { 0, 0, 0 }, NULL, NULL };

/* ROM 649A40; VRAM 802C7590. */
PokemonInitData D_802C7590_649A40 = { jigglypuff_model, D_8032E0F0_6B05A0, renderPokemonModelTypeIFogged, &D_802C757C_649A2C, { 2.20000005f, 2.20000005f, 2.20000005f }, { 0.0f, 107.0f, 0.0f }, 29.0f, 37, 0, 0, 0, { 0, 0, 0 } };

/* Bounded original zero-filled native record alignment (12 bytes). */
char D_802C75C4_649A74_padding[12] = "";

/* ROM 649A80; VRAM 802C75D0. */
s32 D_802C75D0_649A80[2] = { 309, 133 };

/* ROM 649A88; VRAM 802C75D8. */
AnimationHeader D_802C75D8_649A88 = { 2.0f, 64.0f, D_8011C2E0_99700, NULL, D_802C75D0_649A80 };

/* ROM 649A9C; VRAM 802C75EC. */
GObj* D_802C75EC_649A9C = NULL;

/* ROM 649AA0; VRAM 802C75F0. */
GObj* D_802C75F0_649AA0 = NULL;

/* ROM 649AA4; VRAM 802C75F4. */
InteractionHandler D_802C75F4_649AA4[2] = {
    { 16, func_802C2BDC_64508C, 4000.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 649AC4; VRAM 802C7614. */
InteractionHandler D_802C7614_649AC4[2] = {
    { 16, func_802C2BDC_64508C, 8000.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 649AE4; VRAM 802C7634. */
InteractionHandler D_802C7634_649AE4[4] = {
    { 24, NULL, 0.0f, func_802C2D98_645248 },
    { 9, NULL, 0.0f, func_802C31D0_645680 },
    { 13, NULL, 0.0f, func_802C31D0_645680 },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 649B24; VRAM 802C7674. */
InteractionHandler2 D_802C7674_649B24 = { {
    { 16, func_802C2EBC_64536C, 3000.0f, NULL },
    { 58, NULL, 0.0f, NULL },
} };

/* ROM 649B44; VRAM 802C7694. */
InteractionHandler D_802C7694_649B44[4] = {
    { 16, func_802C2FF4_6454A4, 4000.0f, NULL },
    { 9, NULL, 0.0f, func_802C31D0_645680 },
    { 13, NULL, 0.0f, func_802C31D0_645680 },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 649B84; VRAM 802C76D4. */
InteractionHandler4 D_802C76D4_649B84 = { {
    { 9, func_802C30B8_645568, 0.0f, func_802C31D0_645680 },
    { 13, func_802C30B8_645568, 0.0f, func_802C31D0_645680 },
    { 33, func_802C30B8_645568, 0.0f, func_802C31D0_645680 },
    { 58, NULL, 0.0f, NULL },
} };

/* ROM 649BC4; VRAM 802C7714. */
PokemonAnimationSetup D_802C7714_649BC4 = { &D_802C75D8_649A88, func_802C29D0_644E80, 0, { 0, 0, 0 }, NULL, NULL };

/* ROM 649BD8; VRAM 802C7728. */
PokemonInitData D_802C7728_649BD8 = { zubat_model, NULL, renderPokemonModelTypeIFogged, &D_802C7714_649BC4, { 2.20000005f, 2.20000005f, 2.20000005f }, { 0.0f, 42.0f, 0.0f }, 33.0f, 37, 0, 0, 0, { 0, 0, 0 } };

/* Bounded original zero-filled native record alignment (4 bytes). */
char D_802C775C_649C0C_padding[4] = "";

/* ROM 649C10; VRAM 802C7760. */
s32 D_802C7760_649C10[1] = { 211 };

/* ROM 649C14; VRAM 802C7764. */
s32 D_802C7764_649C14[3] = { 210, 376, 114 };

/* ROM 649C20; VRAM 802C7770. */
s32 D_802C7770_649C20[3] = { 211, 376, 114 };

/* ROM 649C2C; VRAM 802C777C. */
s32 D_802C777C_649C2C[3] = { 0, 376, 114 };

/* ROM 649C38; VRAM 802C7788. */
AnimationHeader D_802C7788_649C38 = { 0.5f, 60.0f, D_800FDC70_7B090, NULL, D_802C7760_649C10 };

/* ROM 649C4C; VRAM 802C779C. */
AnimationHeader D_802C779C_649C4C = { 0.5f, 65.0f, D_800FAE40_78260, NULL, D_802C7764_649C14 };

/* ROM 649C60; VRAM 802C77B0. */
AnimationHeader D_802C77B0_649C60 = { 0.5f, 59.0f, D_800FBF50_79370, NULL, D_802C7770_649C20 };

/* ROM 649C74; VRAM 802C77C4. */
AnimationHeader D_802C77C4_649C74 = { 0.5f, 50.0f, D_800FD080_7A4A0, NULL, D_802C777C_649C2C };

/* ROM 649C88; VRAM 802C77D8. */
InteractionHandler D_802C77D8_649C88[1] = {
    { 58, NULL, 0.0f, NULL },
};

/* ROM 649C98; VRAM 802C77E8. */
PokemonAnimationSetup D_802C77E8_649C98 = { &D_802C779C_649C4C, func_802C3290_645740, 0, { 0, 0, 0 }, NULL, NULL };

/* ROM 649CAC; VRAM 802C77FC. */
PokemonInitData D_802C77FC_649CAC = { magikarp_model, NULL, renderPokemonModelTypeBFogged, &D_802C77E8_649C98, { 1.60000002f, 1.60000002f, 1.60000002f }, { 0.0f, -40.0f, -11.0f }, 35.0f, 37, 0, 0, 0, { 0, 0, 0 } };

/* ROM 649CE0; VRAM 802C7830. */
s32 D_802C7830_649CE0[1] = { 266 };

/* ROM 649CE4; VRAM 802C7834. */
s32 D_802C7834_649CE4[3] = { 264, 127, 360 };

/* ROM 649CF0; VRAM 802C7840. */
s32 D_802C7840_649CF0[1] = { 263 };

/* ROM 649CF4; VRAM 802C7844. */
s32 D_802C7844_649CF4[2] = { 265, 371 };

/* ROM 649CFC; VRAM 802C784C. */
s32 D_802C784C_649CFC[2] = { 267, 268 };

/* ROM 649D04; VRAM 802C7854. */
s32 D_802C7854_649D04[1] = { 354 };

/* ROM 649D08; VRAM 802C7858. */
s32 D_802C7858_649D08[2] = { 0, 138 };

/* ROM 649D10; VRAM 802C7860. */
s32 D_802C7860_649D10[3] = { 264, 127, 360 };

/* ROM 649D1C; VRAM 802C786C. */
AnimationHeader D_802C786C_649D1C = { 0.430000007f, 40.0f, D_80112F20_90340, D_8011A2B0_976D0, NULL };

/* ROM 649D30; VRAM 802C7880. */
AnimationHeader D_802C7880_649D30 = { 0.5f, 80.0f, D_80113740_90B60, D_8011A370_97790, D_802C7830_649CE0 };

/* ROM 649D44; VRAM 802C7894. */
AnimationHeader D_802C7894_649D44 = { 0.300000012f, 63.0f, D_8010E190_8B5B0, D_80119A00_96E20, D_802C7834_649CE4 };

/* ROM 649D58; VRAM 802C78A8. */
AnimationHeader D_802C78A8_649D58 = { 0.349999994f, 12.0f, D_801092F0_86710, D_801196C0_96AE0, NULL };

/* ROM 649D6C; VRAM 802C78BC. */
AnimationHeader D_802C78BC_649D6C = { 0.600000024f, 16.0f, D_8010D410_8A830, D_80119960_96D80, NULL };

/* ROM 649D80; VRAM 802C78D0. */
AnimationHeader D_802C78D0_649D80 = { 0.600000024f, 120.0f, D_801161D0_935F0, D_8011ADE0_98200, D_802C7840_649CF0 };

/* ROM 649D94; VRAM 802C78E4. */
AnimationHeader D_802C78E4_649D94 = { 0.300000012f, 36.0f, D_80111AA0_8EEC0, D_8011A1B0_975D0, D_802C7844_649CF4 };

/* ROM 649DA8; VRAM 802C78F8. */
AnimationHeader D_802C78F8_649DA8 = { 0.400000006f, 5.0f, D_8010CE10_8A230, D_801198B0_96CD0, NULL };

/* ROM 649DBC; VRAM 802C790C. */
AnimationHeader D_802C790C_649DBC = { 0.400000006f, 35.0f, D_8010C370_89790, D_80119800_96C20, NULL };

/* ROM 649DD0; VRAM 802C7920. */
AnimationHeader D_802C7920_649DD0 = { 0.400000006f, 75.0f, D_801189D0_95DF0, D_8011AF80_983A0, D_802C784C_649CFC };

/* ROM 649DE4; VRAM 802C7934. */
AnimationHeader D_802C7934_649DE4 = { 0.600000024f, 64.0f, D_80109C10_87030, D_80119760_96B80, D_802C7854_649D04 };

/* ROM 649DF8; VRAM 802C7948. */
AnimationHeader D_802C7948_649DF8 = { 0.600000024f, 16.0f, D_80117C40_95060, D_8011AEE0_98300, D_802C7858_649D08 };

/* ROM 649E0C; VRAM 802C795C. */
AnimationHeader D_802C795C_649E0C = { 0.300000012f, 63.0f, D_80114610_91A30, D_8011A440_97860, D_802C7860_649D10 };

/* ROM 649E20; VRAM 802C7970. */
InteractionHandler D_802C7970_649E20[1] = {
    { 58, NULL, 0.0f, NULL },
};

/* ROM 649E30; VRAM 802C7980. */
f32 D_802C7980_649E30 = 0.0f;

/* ROM 649E34; VRAM 802C7984. */
InteractionHandler4 D_802C7984_649E34 = { {
    { 9, NULL, 0.0f, func_802C3840_645CF0 },
    { 13, NULL, 0.0f, func_802C3840_645CF0 },
    { 34, func_802C3874_645D24, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
} };

/* ROM 649E74; VRAM 802C79C4. */
Vec3f D_802C79C4_649E74 = { 0.0f, 0.0f, 0.0f };

/* ROM 649E80; VRAM 802C79D0. */
InteractionHandler8 D_802C79D0_649E80 = { {
    { 9, func_802C3E74_646324, 0.0f, NULL },
    { 13, func_802C3E74_646324, 0.0f, NULL },
    { 10, func_802C3E74_646324, 0.0f, NULL },
    { 5, func_802C3EDC_64638C, 0.0f, NULL },
    { 6, func_802C3EDC_64638C, 0.0f, NULL },
    { 7, func_802C3EDC_64638C, 0.0f, NULL },
    { 35, func_802C3FD8_646488, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
} };

/* ROM 649F00; VRAM 802C7A50. */
InteractionHandler5 D_802C7A50_649F00 = { {
    { 9, func_802C3E74_646324, 0.0f, NULL },
    { 13, func_802C3E74_646324, 0.0f, NULL },
    { 10, func_802C3E74_646324, 0.0f, NULL },
    { 36, func_802C413C_6465EC, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
} };

/* ROM 649F50; VRAM 802C7AA0. */
PokemonAnimationSetup D_802C7AA0_649F50 = { &D_802C786C_649D1C, func_802C33C0_645870, 0, { 0, 0, 0 }, NULL, NULL };

/* ROM 649F64; VRAM 802C7AB4. */
PokemonInitData D_802C7AB4_649F64 = { pikachu_model, pikachu_materials, renderPokemonModelTypeJFogged, &D_802C7AA0_649F50, { 2.0f, 2.0f, 2.0f }, { 0.0f, 76.0f, 0.0f }, 22.0f, 37, 0, 0, 0, { 0, 0, 0 } };

/* Bounded original zero-filled native record alignment (8 bytes). */
char D_802C7AE8_649F98_padding[8] = "";

/* ROM 649FA0; VRAM 802C7AF0. */
s32 D_802C7AF0_649FA0[4] = { 0, 134, 139, 119 };

/* ROM 649FB0; VRAM 802C7B00. */
s32 D_802C7B00_649FB0[2] = { 0, 119 };

/* ROM 649FB8; VRAM 802C7B08. */
s32 D_802C7B08_649FB8[2] = { 0, 119 };

/* ROM 649FC0; VRAM 802C7B10. */
AnimationHeader D_802C7B10_649FC0 = { 0.5f, 87.0f, D_801746E0_240490, D_80178920_2446D0, D_802C7AF0_649FA0 };

/* ROM 649FD4; VRAM 802C7B24. */
AnimationHeader D_802C7B24_649FD4 = { 0.400000006f, 40.0f, D_80172370_23E120, D_80178800_2445B0, D_802C7B00_649FB0 };

/* ROM 649FE8; VRAM 802C7B38. */
AnimationHeader D_802C7B38_649FE8 = { 0.5f, 116.0f, D_80172E00_23EBB0, D_80178890_244640, D_802C7B08_649FB8 };

/* ROM 649FFC; VRAM 802C7B4C. */
GObj* D_802C7B4C_649FFC = NULL;

/* ROM 64A000; VRAM 802C7B50. */
InteractionHandler D_802C7B50_64A000[2] = {
    { 28, func_802C46F0_646BA0, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* Bounded original zero-filled native record alignment (8 bytes). */
char D_802C7B70_64A020_padding[8] = "";

/* ROM 64A028; VRAM 802C7B78. */
InteractionHandler D_802C7B78_64A028[1] = {
    { 58, NULL, 0.0f, NULL },
};

/* ROM 64A038; VRAM 802C7B88. */
PokemonAnimationSetup D_802C7B88_64A038 = { &D_802C7B10_649FC0, func_802C46A0_646B50, 0, { 0, 0, 0 }, NULL, NULL };

/* ROM 64A04C; VRAM 802C7B9C. */
PokemonInitData D_802C7B9C_64A04C = { articuno_model, D_803265E0_6A8A90, renderPokemonModelTypeIFogged, &D_802C7B88_64A038, { 1.60000002f, 1.60000002f, 1.60000002f }, { 0.0f, 150.0f, 0.0f }, 69.0f, 37, 0, 0, 0, { 0, 0, 0 } };

/* ROM 64A080; VRAM 802C7BD0. */
AnimationHeader D_802C7BD0_64A080 = { 0.300000012f, 60.0f, D_8017A200_245FB0, NULL, NULL };

/* ROM 64A094; VRAM 802C7BE4. */
AnimationHeader D_802C7BE4_64A094 = { 1.0f, 60.0f, D_8017A350_246100, NULL, NULL };

/* ROM 64A0A8; VRAM 802C7BF8. */
AnimationHeader D_802C7BF8_64A0A8 = { 2.0f, 60.0f, D_8017A710_2464C0, NULL, NULL };

/* ROM 64A0BC; VRAM 802C7C0C. */
AnimationHeader D_802C7C0C_64A0BC = { 0.5f, 60.0f, D_8017A510_2462C0, NULL, NULL };

/* ROM 64A0D0; VRAM 802C7C20. */
Struct_800AB050* D_802C7C20_64A0D0[2] = { D_8033E210_6C06C0, (Struct_800AB050*) D_8017C090_247E40 };

/* ROM 64A0D8; VRAM 802C7C28. */
EggStruct D_802C7C28_64A0D8 = { (Struct_800AB050*) D_8017A780_246530, D_802C7C20_64A0D0, 324, 2, 0.0f };

/* ROM 64A0EC; VRAM 802C7C3C. */
GObj* D_802C7C3C_64A0EC = NULL;

/* ROM 64A0F0; VRAM 802C7C40. */
InteractionHandler D_802C7C40_64A0F0[6] = {
    { 9, func_802C4AA8_646F58, 0.0f, NULL },
    { 13, func_802C4AA8_646F58, 0.0f, NULL },
    { 5, func_802C4B04_646FB4, 0.0f, NULL },
    { 6, func_802C4B04_646FB4, 0.0f, NULL },
    { 7, func_802C4B04_646FB4, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* Bounded original zero-filled native record alignment (8 bytes). */
char D_802C7CA0_64A150_padding[8] = "";

/* ROM 64A158; VRAM 802C7CA8. */
InteractionHandler D_802C7CA8_64A158[1] = {
    { 58, NULL, 0.0f, NULL },
};

/* ROM 64A168; VRAM 802C7CB8. */
PokemonAnimationSetup D_802C7CB8_64A168 = { &D_802C7BD0_64A080, func_802C49F0_646EA0, 0, { 0, 0, 0 }, NULL, NULL };

/* ROM 64A17C; VRAM 802C7CCC. */
PokemonInitData D_802C7CCC_64A17C = { D_8017BFA8_247D58, NULL, renderPokemonModelTypeDFogged, &D_802C7CB8_64A168, { 2.20000005f, 2.20000005f, 2.20000005f }, { 0.0f, 250.0f, 0.0f }, 55.0f, 37, 0, 0, 0, { 0, 0, 0 } };

/* ROM 64A1B0; VRAM 802C7D00. */
s32 D_802C7D00_64A1B0[1] = { 321 };

/* ROM 64A1B4; VRAM 802C7D04. */
s32 D_802C7D04_64A1B4[1] = { 322 };

/* ROM 64A1B8; VRAM 802C7D08. */
s32 D_802C7D08_64A1B8[1] = { 323 };

/* ROM 64A1BC; VRAM 802C7D0C. */
s32 D_802C7D0C_64A1BC[2] = { 0, 136 };

/* ROM 64A1C4; VRAM 802C7D14. */
s32 D_802C7D14_64A1C4[2] = { 0, 136 };

/* ROM 64A1CC; VRAM 802C7D1C. */
AnimationHeader D_802C7D1C_64A1CC = { 0.400000006f, 60.0f, D_8019E4D0_26A280, NULL, NULL };

/* ROM 64A1E0; VRAM 802C7D30. */
AnimationHeader D_802C7D30_64A1E0 = { 0.400000006f, 36.0f, D_8019D4A0_269250, D_801A03C0_26C170, D_802C7D00_64A1B0 };

/* ROM 64A1F4; VRAM 802C7D44. */
AnimationHeader D_802C7D44_64A1F4 = { 0.5f, 30.0f, D_8019B160_266F10, D_801A02A0_26C050, D_802C7D04_64A1B4 };

/* ROM 64A208; VRAM 802C7D58. */
AnimationHeader D_802C7D58_64A208 = { 1.0f, 90.0f, D_8019EF80_26AD30, NULL, D_802C7D08_64A1B8 };

/* ROM 64A21C; VRAM 802C7D6C. */
AnimationHeader D_802C7D6C_64A21C = { 1.0f, 120.0f, D_8019C070_267E20, D_801A0310_26C0C0, D_802C7D0C_64A1BC };

/* ROM 64A230; VRAM 802C7D80. */
AnimationHeader D_802C7D80_64A230 = { 1.0f, 120.0f, D_80199060_264E10, NULL, D_802C7D14_64A1C4 };

/* ROM 64A244; VRAM 802C7D94. */
InteractionHandler D_802C7D94_64A244[4] = {
    { 5, func_802C5188_647638, 0.0f, NULL },
    { 6, func_802C5188_647638, 0.0f, NULL },
    { 7, func_802C5188_647638, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* Bounded original zero-filled native record alignment (8 bytes). */
char D_802C7DD4_64A284_padding[8] = "";

/* ROM 64A28C; VRAM 802C7DDC. */
InteractionHandler D_802C7DDC_64A28C[4] = {
    { 5, func_802C5380_647830, 0.0f, NULL },
    { 6, func_802C53F4_6478A4, 0.0f, NULL },
    { 7, func_802C5468_647918, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 64A2CC; VRAM 802C7E1C. */
InteractionHandler D_802C7E1C_64A2CC[3] = {
    { 6, func_802C53F4_6478A4, 0.0f, NULL },
    { 7, func_802C5468_647918, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 64A2FC; VRAM 802C7E4C. */
InteractionHandler D_802C7E4C_64A2FC[3] = {
    { 5, func_802C5380_647830, 0.0f, NULL },
    { 7, func_802C5468_647918, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 64A32C; VRAM 802C7E7C. */
InteractionHandler D_802C7E7C_64A32C[3] = {
    { 6, func_802C53F4_6478A4, 0.0f, NULL },
    { 5, func_802C5380_647830, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 64A35C; VRAM 802C7EAC. */
PokemonAnimationSetup D_802C7EAC_64A35C = { &D_802C7D1C_64A1CC, func_802C4EF4_6473A4, 0, { 0, 0, 0 }, NULL, NULL };

/* ROM 64A370; VRAM 802C7EC0. */
PokemonInitData D_802C7EC0_64A370 = { D_80335F98_6B8448, D_80331450_6B3900, renderPokemonModelTypeIFogged, &D_802C7EAC_64A35C, { 1.39999998f, 1.39999998f, 1.39999998f }, { 0.0f, 135.0f, 0.0f }, 71.0f, 37, 0, 0, 0, { 0, 0, 0 } };

/* Bounded original zero-filled native record alignment (12 bytes). */
char D_802C7EF4_64A3A4_padding[12] = "";

/* ROM 64A3B0; VRAM 802C7F00. */
s32 D_802C7F00_64A3B0[2] = { 0, 145 };

/* ROM 64A3B8; VRAM 802C7F08. */
AnimationHeader D_802C7F08_64A3B8 = { 0.5f, 100.0f, D_801456D0_211480, NULL, D_802C7F00_64A3B0 };

/* ROM 64A3CC; VRAM 802C7F1C. */
PokemonAnimationSetup D_802C7F1C_64A3CC = { &D_802C7F08_64A3B8, func_802C5580_647A30, 0, { 0, 0, 0 }, NULL, NULL };

/* ROM 64A3E0; VRAM 802C7F30. */
PokemonInitData D_802C7F30_64A3E0 = { D_801450C0_210E70, NULL, renderPokemonModelTypeDFogged, &D_802C7F1C_64A3CC, { 10.0f, 10.0f, 10.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f, 4, 0, 0, 0, { 0, 0, 0 } };

/* Bounded original zero-filled native record alignment (12 bytes). */
char D_802C7F64_64A414_padding[12] = "";

/* ROM 64A420; VRAM 802C7F70. */
AnimationHeader D_802C7F70_64A420 = { 1.0f, 100.0f, gate_modelanim_closed, gate_matanim_closed, NULL };

/* ROM 64A434; VRAM 802C7F84. */
AnimationHeader D_802C7F84_64A434 = { 1.0f, 100.0f, gate_modelanim_raise_bar, gate_matanim_raise_bar, NULL };

/* ROM 64A448; VRAM 802C7F98. */
AnimationHeader D_802C7F98_64A448 = { 1.0f, 100.0f, gate_modelanim_opening, gate_matanim_opening, NULL };

/* ROM 64A45C; VRAM 802C7FAC. */
AnimationHeader D_802C7FAC_64A45C = { 1.0f, 100.0f, gate_modelanim_opened, gate_matanim_opened, NULL };

/* ROM 64A470; VRAM 802C7FC0. */
s32 D_802C7FC0_64A470 = -1;

/* ROM 64A474; VRAM 802C7FC4. */
s32 D_802C7FC4_64A474 = 0;

/* ROM 64A478; VRAM 802C7FC8. */
InteractionHandler D_802C7FC8_64A478[2] = {
    { 16, func_802C569C_647B4C, 2000.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 64A498; VRAM 802C7FE8. */
UnkBlueShark D_802C7FE8_64A498 = { 1001, 0 };

/* ROM 64A49C; VRAM 802C7FEC. */
PokemonAnimationSetup D_802C7FEC_64A49C = { &D_802C7F70_64A420, func_beach_802C5620, 0, { 0, 0, 0 }, NULL, NULL };

/* ROM 64A4B0; VRAM 802C8000. */
PokemonInitData D_802C8000_64A4B0 = { gate_model, gate_materials, renderModelTypeDFogged, &D_802C7FEC_64A49C, { 10.0f, 10.0f, 10.0f }, { 0.0f, 0.0f, 0.0f }, 0.00999999978f, 0, 0, 0, 0, { 0, 0, 0 } };

/* Bounded original zero-filled native record alignment (12 bytes). */
char D_802C8034_64A4E4_padding[12] = "";

/* ROM 64A4F0; VRAM 802C8040. */
s32 D_802C8040_64A4F0 = 0;

/* ROM 64A4F4; VRAM 802C8044. */
GObj* D_802C8044_64A4F4 = NULL;

/* Bounded zero-filled end alignment (8 bytes). */
char D_802C8048_64A4F8_padding[8] = "";
