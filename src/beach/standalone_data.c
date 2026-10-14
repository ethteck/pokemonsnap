#include "beach.h"

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
extern UnkEC64Arg3 D_80136AC0_C2F50[];
extern AnimCmd* D_80138C50_C50E0[];
extern Texture** D_801397C0_C5C50[];
extern UnkEC64Arg3 D_80139A40_C5ED0[];
extern AnimCmd* D_80139CD0_C6160[];
extern AnimCmd** D_8013ACA0_C7130[];
extern AnimCmd* D_80159E60_E62F0[];
extern AnimCmd* D_8015BC10_E80A0[];
extern AnimCmd* D_8015CBC0_E9050[];
extern AnimCmd* D_8015EBA0_EB030[];
extern AnimCmd* D_8015FD10_EC1A0[];
extern AnimCmd** D_801617D0_EDC60[];
extern AnimCmd* D_80165010_F14A0[];
extern AnimCmd* D_80165D90_F2220[];
extern AnimCmd* D_80166A90_F2F20[];
extern AnimCmd* D_80167D20_F41B0[];
extern AnimCmd* D_80168D50_F51E0[];
extern AnimCmd** D_8016B190_F7620[];
extern AnimCmd** D_8016B250_F76E0[];
extern AnimCmd** D_8016B300_F7790[];
extern AnimCmd** D_8016B420_F78B0[];
extern AnimCmd** D_8016B4F0_F7980[];
extern AnimCmd* D_8016E200_FA690[];
extern AnimCmd* D_8016F5B0_FBA40[];
extern AnimCmd* D_80170AD0_FCF60[];
extern AnimCmd* D_80173C30_1000C0[];
extern AnimCmd* D_80175390_101820[];
extern AnimCmd* D_801765D0_102A60[];
extern AnimCmd* D_80177520_1039B0[];
extern AnimCmd** D_80179560_1059F0[];
extern AnimCmd** D_80179600_105A90[];
extern AnimCmd** D_801796A0_105B30[];
extern AnimCmd** D_80179760_105BF0[];
extern AnimCmd** D_80179810_105CA0[];
extern AnimCmd** D_801798B0_105D40[];
extern AnimCmd** D_80179940_105DD0[];
extern AnimCmd* D_8017BB20_107FB0[];
extern AnimCmd* D_8017DA60_109EF0[];
extern AnimCmd* D_8017E2E0_10A770[];
extern AnimCmd* D_8017E740_10ABD0[];
extern AnimCmd* D_8017EBA0_10B030[];
extern AnimCmd* D_8017F080_10B510[];
extern AnimCmd* D_8017F8B0_10BD40[];
extern AnimCmd* D_8017FEF0_10C380[];
extern AnimCmd* D_80180910_10CDA0[];
extern AnimCmd* D_80181880_10DD10[];
extern AnimCmd** D_801820B0_10E540[];
extern AnimCmd** D_80182150_10E5E0[];
extern AnimCmd** D_801821C0_10E650[];
extern AnimCmd** D_80182230_10E6C0[];
extern AnimCmd** D_80182310_10E7A0[];
extern AnimCmd** D_801823C0_10E850[];
extern AnimCmd* D_80183D20_1101B0[];
extern AnimCmd** D_80184400_110890[];
extern AnimCmd* D_80185010_1114A0[];
extern AnimCmd* D_80185D90_112220[];
extern AnimCmd* D_801866A0_112B30[];
extern AnimCmd* D_80186E20_1132B0[];
extern AnimCmd* D_80187230_1136C0[];
extern AnimCmd* D_80187BD0_114060[];
extern AnimCmd* D_80188260_1146F0[];
extern AnimCmd* D_80188ED0_115360[];
extern AnimCmd* D_801895E0_115A70[];
extern AnimCmd** D_8018A270_116700[];
extern AnimCmd** D_8018A370_116800[];
extern AnimCmd** D_8018A410_1168A0[];
extern AnimCmd** D_8018A4C0_116950[];
extern AnimCmd* D_801906A0_11CB30[];
extern AnimCmd* D_80191AE0_11DF70[];
extern AnimCmd* D_80192C20_11F0B0[];
extern AnimCmd* D_801949A0_120E30[];
extern AnimCmd* D_80195A70_121F00[];
extern AnimCmd* D_80196070_122500[];
extern AnimCmd* D_80197A00_123E90[];
extern AnimCmd* D_80198BF0_125080[];
extern AnimCmd* D_8019A950_126DE0[];
extern AnimCmd* D_8019C270_128700[];
extern AnimCmd** D_8019D890_129D20[];
extern AnimCmd** D_8019D9E0_129E70[];
extern AnimCmd** D_8019DAF0_129F80[];
extern AnimCmd** D_8019DC60_12A0F0[];
extern AnimCmd** D_8019DD80_12A210[];
extern AnimCmd** D_8019DE50_12A2E0[];
extern AnimCmd** D_8019DFF0_12A480[];
extern AnimCmd** D_8019E110_12A5A0[];
extern AnimCmd** D_8019E260_12A6F0[];
extern AnimCmd** D_8019E3F0_12A880[];
extern AnimCmd* D_801A08C0_12CD50[];
extern AnimCmd* D_801A2280_12E710[];
extern AnimCmd* D_801A4A80_130F10[];
extern AnimCmd* D_801A66D0_132B60[];
extern AnimCmd** D_801A8CC0_135150[];
extern AnimCmd** D_801A8D50_1351E0[];
extern AnimCmd** D_801A8DF0_135280[];
extern AnimCmd* D_801AA9D0_136E60[];
extern AnimCmd* D_801AB610_137AA0[];
extern AnimCmd* D_801AC250_1386E0[];
extern AnimCmd* D_801ACF90_139420[];
extern AnimCmd* D_801AE790_13AC20[];
extern AnimCmd* D_801AF4B0_13B940[];
extern u16 D_803B5000[];
extern u16 D_803DA800[];
extern void Pokemon_ChangeBlockAndRemove(GObj*, f32, f32, f32, f32, f32, f32);
extern void beachSpawnMagikarpAtGObj(GObj* obj);
extern Vtx butterfree_hd_vtx[];
extern UnkEC64Arg3 butterfree_model[];
extern AnimCmd* butterfree_photo_pose0[];
extern AnimCmd* butterfree_photo_pose1[];
extern Texture** chansey_materials[];
extern UnkEC64Arg3 chansey_model[];
extern void contUpdate(void);
extern Texture** doduo_materials[];
extern UnkEC64Arg3 doduo_model[];
extern Texture** eevee_materials[];
extern UnkEC64Arg3 eevee_model[];
extern void func_800A1A50(Gfx**);
extern GObj* func_8035E0D4_4FE4E4(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
extern void func_beach_802C45C0(void);
extern void func_beach_802C4738(s32 arg0);
extern void func_beach_802C56C8(GObj* obj);
extern void func_beach_802C5700(GObj* obj);
extern void func_beach_802C5828(GObj* obj);
extern void func_beach_802C5884(GObj* obj);
extern void func_beach_802C58B8(GObj* obj);
extern void func_beach_802C58EC(GObj* obj);
extern void func_beach_802C594C(GObj* obj);
extern void func_beach_802C59C0(GObj* obj);
extern void func_beach_802C5A20(GObj* obj);
extern void func_beach_802C5A94(GObj* obj);
extern void func_beach_802C5AF4(GObj* obj);
extern void func_beach_802C5C28(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn);
extern void func_beach_802C5DAC(GObj* obj);
extern void func_beach_802C5E88(GObj* obj);
extern void func_beach_802C5EF8(GObj* obj);
extern void func_beach_802C5FF8(GObj* obj);
extern void func_beach_802C60E8(GObj* obj);
extern void func_beach_802C6210(GObj* obj);
extern void func_beach_802C62E4(GObj* obj);
extern void func_beach_802C6478(GObj* obj);
extern void func_beach_802C649C(GObj* obj);
extern void func_beach_802C6580(GObj* obj);
extern void func_beach_802C6700(GObj* obj);
extern void func_beach_802C67E0(GObj* obj);
extern void func_beach_802C6854(GObj* obj);
extern void func_beach_802C6944(GObj* arg0);
extern void func_beach_802C6A3C(GObj* obj);
extern void func_beach_802C6B28(GObj* obj);
extern void func_beach_802C6B8C(GObj* obj);
extern void func_beach_802C6C60(GObj* obj);
extern void func_beach_802C6CC4(GObj* obj);
extern void func_beach_802C6D9C(GObj* obj);
extern void func_beach_802C6EC0(GObj* obj);
extern void func_beach_802C6F6C(GObj* obj);
extern void func_beach_802C7050(GObj* obj);
extern void func_beach_802C70C0(GObj* obj);
extern void func_beach_802C7130(GObj* obj);
extern void func_beach_802C71E8(GObj* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6);
extern void func_beach_802C7270(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn);
extern void func_beach_802C72E0(GObj* obj);
extern void func_beach_802C737C(GObj* obj);
extern void func_beach_802C73EC(GObj* obj);
extern void func_beach_802C74EC(GObj* obj);
extern void func_beach_802C755C(GObj* obj);
extern void func_beach_802C762C(GObj* obj);
extern void func_beach_802C77CC(GObj* obj);
extern void func_beach_802C77F0(GObj* obj);
extern void func_beach_802C79DC(GObj* obj);
extern void func_beach_802C7A60(GObj* obj);
extern void func_beach_802C7AD0(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn);
extern void func_beach_802C7B10(GObj* obj);
extern void func_beach_802C7CF0(GObj* obj);
extern void func_beach_802C7E38(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn);
extern void func_beach_802C7E70(GObj* obj);
extern void func_beach_802C8028(GObj* obj);
extern void func_beach_802C8274(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn);
extern void func_beach_802C82B0(GObj* obj);
extern void func_beach_802C8354(GObj* obj);
extern void func_beach_802C84A4(GObj* obj);
extern void func_beach_802C8570(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn);
extern void func_beach_802C85B0(GObj* arg0);
extern void func_beach_802C86A8(GObj* obj);
extern void func_beach_802C8900(GObj* obj);
extern void func_beach_802C8AAC(GObj* obj);
extern void func_beach_802C8C30(GObj* obj);
extern void func_beach_802C8C58(GObj* obj);
extern void func_beach_802C8CC0(GObj* obj);
extern void func_beach_802C8D3C(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn);
extern void func_beach_802C8D74(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn);
extern void func_beach_802C8DB0(GObj* obj);
extern void func_beach_802C8F48(GObj* obj);
extern void func_beach_802C914C(GObj* obj);
extern void func_beach_802C91CC(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn);
extern void func_beach_802C9204(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn);
extern void func_beach_802C9240(GObj* obj);
extern void func_beach_802C92BC(GObj* obj);
extern void func_beach_802C93B8(GObj* obj);
extern void func_beach_802C943C(GObj* arg0);
extern void func_beach_802C9580(GObj* obj);
extern void func_beach_802C95F0(GObj* obj);
extern void func_beach_802C96F0(GObj* obj);
extern void func_beach_802C9760(GObj* obj);
extern void func_beach_802C9978(GObj* obj);
extern void func_beach_802C999C(GObj* obj);
extern void func_beach_802C9A7C(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn);
extern void func_beach_802C9AC0(GObj* obj);
extern void func_beach_802C9AE4(GObj* obj);
extern void func_beach_802C9B40(GObj* obj);
extern void func_beach_802C9B9C(GObj* obj);
extern void func_beach_802C9BF8(GObj* obj);
extern void func_beach_802C9CF8(GObj* obj);
extern void func_beach_802C9DCC(GObj* obj);
extern void func_beach_802C9EBC(GObj* obj);
extern void func_beach_802C9F9C(GObj* obj);
extern void func_beach_802CA05C(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn);
extern void func_beach_802CA148(GObj* obj);
extern void func_beach_802CA198(GObj* obj);
extern void func_beach_802CA1BC(GObj* obj);
extern void func_beach_802CA23C(GObj* obj);
extern void func_beach_802CA2BC(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn);
extern void func_beach_802CA300(GObj* obj);
extern void func_beach_802CA418(s32 gObjId, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn);
extern void func_beach_802CA450(GObj* obj);
extern void func_beach_802CA4CC(GObj* obj);
extern void func_beach_802CAB14(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn);
extern void func_beach_802CAB50(GObj* obj);
extern void func_beach_802CAC48(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn);
extern void func_beach_802CACD4(GObj* obj);
extern void func_beach_802CADCC(GObj* obj);
extern void func_beach_802CAF1C(GObj* obj);
extern void func_beach_802CAFEC(GObj* obj);
extern void func_beach_802CB054(GObj* obj);
extern void func_beach_802CB36C(GObj* obj);
extern void func_beach_802CB3DC(GObj* obj);
extern void func_beach_802CB44C(GObj* obj);
extern void func_beach_802CB520(GObj* obj);
extern void func_beach_802CB594(GObj* obj);
extern void func_beach_802CB784(GObj* obj);
extern void func_beach_802CB874(GObj* obj);
extern void func_beach_802CB9E0(GObj* obj);
extern void func_beach_802CBC4C(GObj* obj);
extern void func_beach_802CBCA8(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn);
extern void func_beach_802CBCE0(GObj* obj);
extern void func_beach_802CBDA0(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn);
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
extern Texture** kangaskhan_materials[];
extern UnkEC64Arg3 kangaskhan_model[];
extern Texture** lapras_materials[];
extern UnkEC64Arg3 lapras_model[];
extern UnkEC64Arg3 magikarp_model[];
extern Texture** meowth_materials[];
extern UnkEC64Arg3 meowth_model[];
extern void omDrawAll(void);
extern void omUpdateAll(void);
extern Texture** pidgey_materials[];
extern UnkEC64Arg3 pidgey_model[];
extern Texture** pikachu_materials[];
extern UnkEC64Arg3 pikachu_model[];
extern void pokemonChangeBlock(GObj*, f32, f32, f32, f32, f32, f32);
extern void pokemonChangeBlockOnGround(GObj*, f32, f32, f32, f32, f32, f32);
extern void pokemonRemoveOne(GObj*);
extern void renRenderModelTypeB(GObj*);
extern void renderModelTypeDFogged(GObj*);
extern void renderPokemonModelTypeBFogged(GObj*);
extern void renderPokemonModelTypeDFogged(GObj*);
extern void renderPokemonModelTypeIFogged(GObj*);
extern void renderPokemonModelTypeJFogged(GObj*);
extern UnkEC64Arg3 scyther_model[];
extern Texture** snorlax_materials[];
extern UnkEC64Arg3 snorlax_model[];
extern EnvSoundData D_beach_802CBE10[53];
extern PokemonDef beachPokemonData[17];
extern PokemonDef D_beach_802CBFF4;
extern RandomState2 D_beach_802CC004[2];
extern u16 D_beach_802CC014;
extern s32 D_beach_802CC018;
extern ScreenSettings D_beach_802CC01C;
extern SceneSetup D_beach_802CC038;
extern s32 D_beach_802CC0D0;
extern s32 D_beach_802CC0D4;
extern s32 D_beach_802CC0D8;
extern s32 D_beach_802CC0E0;
extern GObj* D_beach_802CC0E4;
extern s32 D_beach_802CC0F0[1];
extern s32 D_beach_802CC0F4[1];
extern s32 D_beach_802CC0F8[1];
extern s32 D_beach_802CC0FC[1];
extern s32 D_beach_802CC100[1];
extern s32 D_beach_802CC104[2];
extern AnimationHeader D_beach_802CC10C;
extern AnimationHeader D_beach_802CC120;
extern AnimationHeader D_beach_802CC134;
extern AnimationHeader D_beach_802CC148;
extern AnimationHeader D_beach_802CC15C;
extern AnimationHeader D_beach_802CC170;
extern AnimationHeader D_beach_802CC184;
extern AnimationHeader D_beach_802CC198;
extern AnimationHeader D_beach_802CC1AC;
extern AnimationHeader D_beach_802CC1C0;
extern InteractionHandler D_beach_802CC1D4[6];
extern InteractionHandler D_beach_802CC234[3];
extern InteractionHandler D_beach_802CC264[3];
extern InteractionHandler D_beach_802CC294[3];
extern RandomState D_beach_802CC2C4[3];
extern PokemonAnimationSetup D_beach_802CC2DC;
extern PokemonInitData D_beach_802CC2F0;
extern s32 D_beach_802CC330[1];
extern s32 D_beach_802CC334[1];
extern s32 D_beach_802CC338[1];
extern s32 D_beach_802CC33C[1];
extern s32 D_beach_802CC340[1];
extern AnimationHeader D_beach_802CC344;
extern AnimationHeader D_beach_802CC358;
extern AnimationHeader D_beach_802CC36C;
extern AnimationHeader D_beach_802CC380;
extern AnimationHeader D_beach_802CC394;
extern AnimationHeader D_beach_802CC3A8;
extern AnimationHeader D_beach_802CC3BC;
extern AnimationHeader D_beach_802CC3D0;
extern AnimationHeader D_beach_802CC3E4;
extern AnimationHeader D_beach_802CC3F8;
extern InteractionHandler D_beach_802CC40C[10];
extern RandomState D_beach_802CC4AC[3];
extern InteractionHandler D_beach_802CC4C4[3];
extern InteractionHandler D_beach_802CC4F4[3];
extern InteractionHandler D_beach_802CC524[4];
extern InteractionHandler D_beach_802CC564[3];
extern InteractionHandler D_beach_802CC594[3];
extern InteractionHandler D_beach_802CC5C4[8];
extern InteractionHandler D_beach_802CC644[7];
extern InteractionHandler D_beach_802CC6B4[3];
extern InteractionHandler D_beach_802CC6E4[3];
extern InteractionHandler D_beach_802CC714[7];
extern InteractionHandler D_beach_802CC784[3];
extern InteractionHandler D_beach_802CC7B4[3];
extern InteractionHandler D_beach_802CC7E4[2];
extern InteractionHandler D_beach_802CC804[2];
extern InteractionHandler D_beach_802CC824[3];
extern InteractionHandler D_beach_802CC854[2];
extern InteractionHandler D_beach_802CC874[3];
extern InteractionHandler D_beach_802CC8A4[3];
extern InteractionHandler D_beach_802CC8D4[3];
extern InteractionHandler D_beach_802CC904[3];
extern InteractionHandler D_beach_802CC934[2];
extern PokemonAnimationSetup D_beach_802CC954;
extern PokemonInitData D_beach_802CC968;
extern s32 D_beach_802CC9A0[1];
extern s32 D_beach_802CC9A4[2];
extern AnimationHeader D_beach_802CC9AC;
extern AnimationHeader D_beach_802CC9C0;
extern AnimationHeader D_beach_802CC9D4;
extern AnimationHeader D_beach_802CC9E8;
extern AnimationHeader D_beach_802CC9FC;
extern InteractionHandler D_beach_802CCA10[9];
extern RandomState D_beach_802CCAA0[3];
extern InteractionHandler D_beach_802CCAB8[3];
extern InteractionHandler D_beach_802CCAE8[4];
extern InteractionHandler D_beach_802CCB28[8];
extern InteractionHandler D_beach_802CCBA8[5];
extern InteractionHandler D_beach_802CCBF8[3];
extern InteractionHandler D_beach_802CCC28[4];
extern InteractionHandler D_beach_802CCC68[4];
extern InteractionHandler D_beach_802CCCA8[3];
extern PokemonAnimationSetup D_beach_802CCCD8;
extern PokemonInitData D_beach_802CCCEC;
extern s32 D_beach_802CCD20[1];
extern AnimationHeader D_beach_802CCD24;
extern AnimationHeader D_beach_802CCD38;
extern AnimationHeader D_beach_802CCD4C;
extern InteractionHandler D_beach_802CCD60[3];
extern PokemonAnimationSetup D_beach_802CCD90;
extern PokemonInitData D_beach_802CCDA4;
extern s32 D_beach_802CCDE0[2];
extern AnimationHeader D_beach_802CCDE8;
extern s32 D_beach_802CCDFC;
extern s32 D_beach_802CCE00;
extern s32 D_beach_802CCE04;
extern AnimationHeader D_beach_802CCE08;
extern InteractionHandler D_beach_802CCE1C[2];
extern PokemonAnimationSetup D_beach_802CCE3C;
extern PokemonInitData D_beach_802CCE50;
extern s32 D_beach_802CCE90[3];
extern s32 D_beach_802CCE9C[1];
extern s32 D_beach_802CCEA0[4];
extern AnimationHeader D_beach_802CCEB0;
extern AnimationHeader D_beach_802CCEC4;
extern AnimationHeader D_beach_802CCED8;
extern AnimationHeader D_beach_802CCEEC;
extern AnimationHeader D_beach_802CCF00;
extern InteractionHandler D_beach_802CCF14[3];
extern InteractionHandler D_beach_802CCF44[2];
extern PokemonAnimationSetup D_beach_802CCF64;
extern PokemonInitData D_beach_802CCF78;
extern s32 D_beach_802CCFB0[2];
extern s32 D_beach_802CCFB8[2];
extern AnimationHeader D_beach_802CCFC0;
extern AnimationHeader D_beach_802CCFD4;
extern AnimationHeader D_beach_802CCFE8;
extern AnimationHeader D_beach_802CCFFC;
extern InteractionHandler D_beach_802CD010[3];
extern InteractionHandler D_beach_802CD040[2];
extern s32 D_beach_802CD060;
extern InteractionHandler D_beach_802CD064[5];
extern InteractionHandler D_beach_802CD0B4[3];
extern InteractionHandler D_beach_802CD0E4[2];
extern PokemonAnimationSetup D_beach_802CD104;
extern PokemonInitData D_beach_802CD118;
extern s32 D_beach_802CD150[2];
extern s32 D_beach_802CD158[2];
extern s32 D_beach_802CD160[2];
extern AnimationHeader D_beach_802CD168;
extern AnimationHeader D_beach_802CD17C;
extern AnimationHeader D_beach_802CD190;
extern AnimationHeader D_beach_802CD1A4;
extern AnimationHeader D_beach_802CD1B8;
extern AnimationHeader D_beach_802CD1CC;
extern InteractionHandler D_beach_802CD1E4[3];
extern InteractionHandler D_beach_802CD214[3];
extern PokemonAnimationSetup D_beach_802CD244;
extern PokemonInitData D_beach_802CD258;
extern s32 D_beach_802CD290[2];
extern s32 D_beach_802CD298[2];
extern s32 D_beach_802CD2A0[2];
extern AnimationHeader D_beach_802CD2A8;
extern AnimationHeader D_beach_802CD2BC;
extern AnimationHeader D_beach_802CD2D0;
extern AnimationHeader D_beach_802CD2E4;
extern AnimationHeader D_beach_802CD2F8;
extern AnimationHeader D_beach_802CD30C;
extern AnimationHeader D_beach_802CD320;
extern AnimationHeader D_beach_802CD334;
extern AnimationHeader D_beach_802CD348;
extern InteractionHandler D_beach_802CD35C[8];
extern RandomState D_beach_802CD3DC[3];
extern InterpData* D_beach_802CD3F4;
extern InteractionHandler D_beach_802CD3F8[4];
extern InteractionHandler D_beach_802CD438[4];
extern InteractionHandler D_beach_802CD478[3];
extern InteractionHandler D_beach_802CD4A8[4];
extern InteractionHandler D_beach_802CD4E8[3];
extern InteractionHandler D_beach_802CD518[3];
extern PokemonAnimationSetup D_beach_802CD548;
extern PokemonInitData D_beach_802CD55C;
extern s32 D_beach_802CD590[2];
extern s32 D_beach_802CD598[2];
extern s32 D_beach_802CD5A0[1];
extern s32 D_beach_802CD5A4[1];
extern AnimationHeader D_beach_802CD5A8;
extern AnimationHeader D_beach_802CD5BC;
extern AnimationHeader D_beach_802CD5D0;
extern AnimationHeader D_beach_802CD5E4;
extern AnimationHeader D_beach_802CD5F8;
extern AnimationHeader D_beach_802CD60C;
extern AnimationHeader D_beach_802CD620;
extern InteractionHandler D_beach_802CD634[6];
extern InteractionHandler D_beach_802CD694[3];
extern InteractionHandler D_beach_802CD6C4[3];
extern InteractionHandler D_beach_802CD6F4[7];
extern RandomState D_beach_802CD764[2];
extern RandomState D_beach_802CD774[4];
extern PokemonAnimationSetup D_beach_802CD794;
extern PokemonInitData D_beach_802CD7A8;
extern UnkEC64Arg3 D_beach_802CD7E0[2];
extern PokemonDef D_beach_802CD838;
extern PokemonDef D_beach_802CD848;
extern InteractionHandler D_beach_802CD858[6];
extern RandomState D_beach_802CD8B8[3];
extern PokemonAnimationSetup D_beach_802CD8D0;
extern PokemonInitData D_beach_802CD8E4;
extern AnimationHeader D_beach_802CD920;
extern PokemonAnimationSetup D_beach_802CD934;
extern PokemonInitData D_beach_802CD948;
extern AnimationHeader D_beach_802CD980;
extern AnimationHeader D_beach_802CD994;
extern AnimationHeader D_beach_802CD9A8;
extern AnimationHeader D_beach_802CD9BC;
extern s32 D_beach_802CD9D0;
extern s32 D_beach_802CD9D4;
extern InteractionHandler D_beach_802CD9D8[2];
extern UnkBlueShark D_beach_802CD9F8;
extern PokemonAnimationSetup D_beach_802CD9FC;
extern PokemonInitData D_beach_802CDA10;
extern s32 D_beach_802CDA50[1];
extern s32 D_beach_802CDA54[3];
extern s32 D_beach_802CDA60[3];
extern s32 D_beach_802CDA6C[3];
extern AnimationHeader D_802CDA78_565AE8;
extern AnimationHeader D_beach_802CDA8C;
extern AnimationHeader D_802CDAA0_565B10;
extern AnimationHeader D_beach_802CDAB4;
extern InteractionHandler D_802CDAC8_565B38[1];
extern PokemonAnimationSetup D_beach_802CDAD8;
extern PokemonInitData D_beach_802CDAEC;
extern s32 D_beach_802CDB20[1];
extern s32 D_beach_802CDB24[3];
extern s32 D_beach_802CDB30[1];
extern s32 D_beach_802CDB34[2];
extern s32 D_beach_802CDB3C[2];
extern s32 D_beach_802CDB44[1];
extern s32 D_beach_802CDB48[2];
extern s32 D_beach_802CDB50[3];
extern AnimationHeader D_beach_802CDB5C;
extern AnimationHeader D_beach_802CDB70;
extern AnimationHeader D_beach_802CDB84;
extern AnimationHeader D_802CDB98_565C08;
extern AnimationHeader D_beach_802CDBAC;
extern AnimationHeader D_beach_802CDBC0;
extern AnimationHeader D_beach_802CDBD4;
extern AnimationHeader D_beach_802CDBE8;
extern AnimationHeader D_beach_802CDBFC;
extern AnimationHeader D_beach_802CDC10;
extern AnimationHeader D_802CDC24_565C94;
extern AnimationHeader D_802CDC38_565CA8;
extern AnimationHeader D_802CDC4C_565CBC;
extern InteractionHandler D_beach_802CDC60[2];
extern InteractionHandler D_beach_802CDC80[2];
extern InteractionHandler D_beach_802CDCA0[3];
extern InteractionHandler D_beach_802CDCD0[7];
extern InteractionHandler D_beach_802CDD40[4];
extern InteractionHandler D_beach_802CDD80[11];
extern RandomState D_beach_802CDE30[3];
extern InteractionHandler D_beach_802CDE48[3];
extern InteractionHandler D_beach_802CDE78[8];
extern InteractionHandler D_beach_802CDEF8[10];
extern InteractionHandler D_beach_802CDF98[4];
extern InteractionHandler D_beach_802CDFD8[4];
extern Vec3f D_beach_802CE018;
extern PokemonAnimationSetup D_beach_802CE024;
extern PokemonInitData D_beach_802CE038;
extern AnimationHeader D_beach_802CE070;
extern InteractionHandler D_802CE084_5660F4[1];
extern PokemonAnimationSetup D_beach_802CE094;
extern PokemonInitData D_beach_802CE0A8;
extern PokemonDef D_beach_802CE0DC;

/* ROM 563E80; VRAM 802CBE10. */
EnvSoundData D_beach_802CBE10[53] = {
    { 253, 1, 7 },
    { 342, 1, 8 },
    { 343, 1, 8 },
    { 344, 1, 8 },
    { 117, 0, 8 },
    { 142, 0, 8 },
    { 143, 0, 6 },
    { 254, 1, 8 },
    { 255, 1, 8 },
    { 110, 0, 8 },
    { 260, 1, 10 },
    { 261, 1, 10 },
    { 262, 1, 10 },
    { 105, 0, 10 },
    { 104, 0, 10 },
    { 293, 1, 10 },
    { 294, 1, 10 },
    { 295, 1, 10 },
    { 355, 1, 10 },
    { 296, 1, 10 },
    { 297, 1, 10 },
    { 125, 0, 7 },
    { 210, 1, 8 },
    { 211, 1, 8 },
    { 376, 0, 8 },
    { 114, 0, 8 },
    { 383, 2, 40 },
    { 251, 1, 10 },
    { 252, 1, 10 },
    { 366, 0, 10 },
    { 121, 0, 10 },
    { 122, 0, 10 },
    { 298, 1, 9 },
    { 299, 1, 9 },
    { 300, 1, 9 },
    { 301, 1, 9 },
    { 302, 1, 9 },
    { 263, 1, 8 },
    { 264, 1, 10 },
    { 265, 1, 8 },
    { 266, 1, 8 },
    { 267, 2, 8 },
    { 268, 2, 8 },
    { 371, 0, 8 },
    { 127, 0, 10 },
    { 360, 0, 10 },
    { 256, 1, 8 },
    { 257, 1, 7 },
    { 124, 0, 7 },
    { 52, 1, 15 },
    { 304, 1, 10 },
    { 363, 0, 10 },
    { 388, 0, 10 },
};

/* ROM 563F54; VRAM 802CBEE4. */
PokemonDef beachPokemonData[17] = {
    { 12, (pokemonInit) func_beach_802C7E38, pokemonChangeBlock, pokemonRemoveOne },
    { 84, (pokemonInit) func_beach_802C8570, pokemonChangeBlock, pokemonRemoveOne },
    { 133, (pokemonInit) func_beach_802C7AD0, Pokemon_ChangeBlockAndRemove, NULL },
    { 115, (pokemonInit) func_beach_802CA05C, pokemonChangeBlockOnGround, pokemonRemoveOne },
    { 143, (pokemonInit) func_beach_802C5C28, pokemonChangeBlockOnGround, pokemonRemoveOne },
    { 131, (pokemonInit) func_beach_802C8274, pokemonChangeBlock, pokemonRemoveOne },
    { 113, (pokemonInit) func_beach_802C9A7C, pokemonChangeBlockOnGround, pokemonRemoveOne },
    { 52, (pokemonInit) func_beach_802C7270, func_beach_802C71E8, pokemonRemoveOne },
    { 16, (pokemonInit) func_beach_802C8D3C, pokemonChangeBlock, pokemonRemoveOne },
    { 123, (pokemonInit) func_beach_802C91CC, pokemonChangeBlock, pokemonRemoveOne },
    { 129, (pokemonInit) func_beach_802CAC48, pokemonChangeBlockOnGround, pokemonRemoveOne },
    { 25, (pokemonInit) func_beach_802CBCA8, pokemonChangeBlockOnGround, pokemonRemoveOne },
    { 1003, func_8035E0D4_4FE4E4, pokemonChangeBlock, pokemonRemoveOne },
    { 1004, (pokemonInit) func_beach_802CA418, pokemonChangeBlock, pokemonRemoveOne },
    { 1005, (pokemonInit) func_beach_802CA2BC, pokemonChangeBlock, pokemonRemoveOne },
    { 1001, (pokemonInit) func_beach_802CAB14, pokemonChangeBlock, pokemonRemoveOne },
    { 0, NULL, NULL, NULL }
};

/* ROM 564064; VRAM 802CBFF4. */
PokemonDef D_beach_802CBFF4 = { 129, (pokemonInit) func_beach_802CAC48, pokemonChangeBlockOnGround, pokemonRemoveOne };

/* ROM 564074; VRAM 802CC004. */
RandomState2 D_beach_802CC004[2] = {
    { 3, beachSpawnMagikarpAtGObj },
    { 7, NULL },
};

/* ROM 564084; VRAM 802CC014. */
u16 D_beach_802CC014 = 0;

/* ROM 564088; VRAM 802CC018. */
s32 D_beach_802CC018 = 0;

/* ROM 56408C; VRAM 802CC01C. */
ScreenSettings D_beach_802CC01C = { D_803B5000, D_803DA800, NULL, NULL, 320, 240, 2713 };

/* ROM 5640A8; VRAM 802CC038. */
SceneSetup D_beach_802CC038 = {
    { 0, omUpdateAll, omDrawAll, butterfree_hd_vtx, 0, 1, 2, 20480, 3072, 1024, 0, 51200, 2, 16384, func_800A1A50, contUpdate },
    0,
    1088,
    0,
    0,
    0,
    0,
    92,
    0,
    NULL,
    func_beach_802C4738,
    0,
    0,
    0,
    136,
    0,
    88,
    0,
    144,
    func_beach_802C45C0
};

/* Original zero-filled inter-record alignment/storage (12 bytes). */
char D_802CC0C4_564134_padding[12] = "";

/* ROM 564140; VRAM 802CC0D0. */
s32 D_beach_802CC0D0 = 0;

/* ROM 564144; VRAM 802CC0D4. */
s32 D_beach_802CC0D4 = 0;

/* ROM 564148; VRAM 802CC0D8. */
s32 D_beach_802CC0D8 = 0;

/* Original zero-filled inter-record alignment/storage (4 bytes). */
char D_802CC0DC_56414C_padding[4] = "";

/* ROM 564150; VRAM 802CC0E0. */
s32 D_beach_802CC0E0 = 0;

/* ROM 564154; VRAM 802CC0E4. */
GObj* D_beach_802CC0E4 = NULL;

/* Original zero-filled inter-record alignment/storage (8 bytes). */
char D_802CC0E8_564158_padding[8] = "";

/* ROM 564160; VRAM 802CC0F0. */
s32 D_beach_802CC0F0[1] = { 294 };

/* ROM 564164; VRAM 802CC0F4. */
s32 D_beach_802CC0F4[1] = { 293 };

/* ROM 564168; VRAM 802CC0F8. */
s32 D_beach_802CC0F8[1] = { 295 };

/* ROM 56416C; VRAM 802CC0FC. */
s32 D_beach_802CC0FC[1] = { 355 };

/* ROM 564170; VRAM 802CC100. */
s32 D_beach_802CC100[1] = { 297 };

/* ROM 564174; VRAM 802CC104. */
s32 D_beach_802CC104[2] = { 296, 125 };

/* ROM 56417C; VRAM 802CC10C. */
AnimationHeader D_beach_802CC10C = { 0.100000001f, 25.0f, D_8017EBA0_10B030, D_80182230_10E6C0, D_beach_802CC0F0 };

/* ROM 564190; VRAM 802CC120. */
AnimationHeader D_beach_802CC120 = { 0.200000003f, 8.0f, D_8017E740_10ABD0, D_801821C0_10E650, NULL };

/* ROM 5641A4; VRAM 802CC134. */
AnimationHeader D_beach_802CC134 = { 0.150000006f, 40.0f, D_8017F8B0_10BD40, D_80182310_10E7A0, D_beach_802CC0F4 };

/* ROM 5641B8; VRAM 802CC148. */
AnimationHeader D_beach_802CC148 = { 0.230000004f, 24.0f, D_8017FEF0_10C380, NULL, D_beach_802CC0F8 };

/* ROM 5641CC; VRAM 802CC15C. */
AnimationHeader D_beach_802CC15C = { 0.200000003f, 20.0f, D_8017F080_10B510, NULL, D_beach_802CC0FC };

/* ROM 5641E0; VRAM 802CC170. */
AnimationHeader D_beach_802CC170 = { 0.200000003f, 36.0f, D_80181880_10DD10, NULL, NULL };

/* ROM 5641F4; VRAM 802CC184. */
AnimationHeader D_beach_802CC184 = { 0.419999987f, 71.0f, D_80180910_10CDA0, D_801823C0_10E850, D_beach_802CC100 };

/* ROM 564208; VRAM 802CC198. */
AnimationHeader D_beach_802CC198 = { 0.200000003f, 71.0f, D_8017BB20_107FB0, NULL, NULL };

/* ROM 56421C; VRAM 802CC1AC. */
AnimationHeader D_beach_802CC1AC = { 0.200000003f, 19.0f, D_8017DA60_109EF0, D_801820B0_10E540, D_beach_802CC104 };

/* ROM 564230; VRAM 802CC1C0. */
AnimationHeader D_beach_802CC1C0 = { 0.200000003f, 8.0f, D_8017E2E0_10A770, D_80182150_10E5E0, NULL };

/* ROM 564244; VRAM 802CC1D4. */
InteractionHandler D_beach_802CC1D4[6] = {
    { 9, func_beach_802C5884, 0.0f, NULL },
    { 13, func_beach_802C58B8, 0.0f, NULL },
    { 5, func_beach_802C58EC, 0.0f, NULL },
    { 6, func_beach_802C59C0, 0.0f, NULL },
    { 7, func_beach_802C5A94, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 5642A4; VRAM 802CC234. */
InteractionHandler D_beach_802CC234[3] = {
    { 6, func_beach_802C5A20, 0.0f, NULL },
    { 7, func_beach_802C5AF4, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 5642D4; VRAM 802CC264. */
InteractionHandler D_beach_802CC264[3] = {
    { 5, func_beach_802C594C, 0.0f, NULL },
    { 7, func_beach_802C5AF4, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 564304; VRAM 802CC294. */
InteractionHandler D_beach_802CC294[3] = {
    { 5, func_beach_802C594C, 0.0f, NULL },
    { 6, func_beach_802C5A20, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 564334; VRAM 802CC2C4. */
RandomState D_beach_802CC2C4[3] = {
    { 100, func_beach_802C5700 },
    { 100, func_beach_802C5828 },
    { 0, NULL },
};

/* ROM 56434C; VRAM 802CC2DC. */
PokemonAnimationSetup D_beach_802CC2DC = { &D_beach_802CC10C, func_beach_802C56C8, 0, { 0, 0, 0 }, NULL, NULL };

/* ROM 564360; VRAM 802CC2F0. */
PokemonInitData D_beach_802CC2F0 = { snorlax_model, snorlax_materials, renderPokemonModelTypeJFogged, &D_beach_802CC2DC, { 1.5f, 1.5f, 1.5f }, { 0.0f, 82.0f, 0.0f }, 105.0f, 53, 54, 0, 0, { 0, 0, 0 } };

/* Original zero-filled inter-record alignment/storage (12 bytes). */
char D_802CC324_564394_padding[12] = "";

/* ROM 5643A0; VRAM 802CC330. */
s32 D_beach_802CC330[1] = { 299 };

/* ROM 5643A4; VRAM 802CC334. */
s32 D_beach_802CC334[1] = { 300 };

/* ROM 5643A8; VRAM 802CC338. */
s32 D_beach_802CC338[1] = { 298 };

/* ROM 5643AC; VRAM 802CC33C. */
s32 D_beach_802CC33C[1] = { 302 };

/* ROM 5643B0; VRAM 802CC340. */
s32 D_beach_802CC340[1] = { 301 };

/* ROM 5643B4; VRAM 802CC344. */
AnimationHeader D_beach_802CC344 = { 0.319999993f, 50.0f, D_801949A0_120E30, D_8019DC60_12A0F0, NULL };

/* ROM 5643C8; VRAM 802CC358. */
AnimationHeader D_beach_802CC358 = { 0.560000002f, 60.0f, D_801906A0_11CB30, D_8019D890_129D20, NULL };

/* ROM 5643DC; VRAM 802CC36C. */
AnimationHeader D_beach_802CC36C = { 0.449999988f, 24.0f, D_80191AE0_11DF70, D_8019D9E0_129E70, NULL };

/* ROM 5643F0; VRAM 802CC380. */
AnimationHeader D_beach_802CC380 = { 0.330000013f, 68.0f, D_80192C20_11F0B0, D_8019DAF0_129F80, D_beach_802CC330 };

/* ROM 564404; VRAM 802CC394. */
AnimationHeader D_beach_802CC394 = { 0.5f, 70.0f, D_80198BF0_125080, D_8019E110_12A5A0, D_beach_802CC334 };

/* ROM 564418; VRAM 802CC3A8. */
AnimationHeader D_beach_802CC3A8 = { 0.419999987f, 59.0f, D_8019C270_128700, D_8019E3F0_12A880, D_beach_802CC338 };

/* ROM 56442C; VRAM 802CC3BC. */
AnimationHeader D_beach_802CC3BC = { 0.180000007f, 30.0f, D_80195A70_121F00, D_8019DD80_12A210, NULL };

/* ROM 564440; VRAM 802CC3D0. */
AnimationHeader D_beach_802CC3D0 = { 0.280000001f, 55.0f, D_80197A00_123E90, D_8019DFF0_12A480, D_beach_802CC33C };

/* ROM 564454; VRAM 802CC3E4. */
AnimationHeader D_beach_802CC3E4 = { 0.209999993f, 33.0f, D_8019A950_126DE0, D_8019E260_12A6F0, D_beach_802CC340 };

/* ROM 564468; VRAM 802CC3F8. */
AnimationHeader D_beach_802CC3F8 = { 1.0f, 150.0f, D_80196070_122500, D_8019DE50_12A2E0, NULL };

/* ROM 56447C; VRAM 802CC40C. */
InteractionHandler D_beach_802CC40C[10] = {
    { 9, func_beach_802C5FF8, 0.0f, NULL },
    { 13, func_beach_802C60E8, 0.0f, NULL },
    { 10, func_beach_802C6210, 0.0f, NULL },
    { 14, func_beach_802C62E4, 0.0f, NULL },
    { 15, func_beach_802C6478, 0.0f, NULL },
    { 5, func_beach_802C649C, 0.0f, NULL },
    { 6, func_beach_802C649C, 0.0f, NULL },
    { 7, func_beach_802C649C, 0.0f, NULL },
    { 16, func_beach_802C6580, 333.333344f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 56451C; VRAM 802CC4AC. */
RandomState D_beach_802CC4AC[3] = {
    { 100, func_beach_802C5E88 },
    { 100, func_beach_802C5EF8 },
    { 0, NULL },
};

/* ROM 564534; VRAM 802CC4C4. */
InteractionHandler D_beach_802CC4C4[3] = {
    { 9, func_beach_802C5FF8, 0.0f, NULL },
    { 13, func_beach_802C60E8, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 564564; VRAM 802CC4F4. */
InteractionHandler D_beach_802CC4F4[3] = {
    { 9, func_beach_802C5FF8, 0.0f, NULL },
    { 13, func_beach_802C60E8, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 564594; VRAM 802CC524. */
InteractionHandler D_beach_802CC524[4] = {
    { 9, func_beach_802C5FF8, 0.0f, NULL },
    { 13, func_beach_802C60E8, 0.0f, NULL },
    { 10, func_beach_802C6210, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 5645D4; VRAM 802CC564. */
InteractionHandler D_beach_802CC564[3] = {
    { 9, func_beach_802C5FF8, 0.0f, NULL },
    { 13, func_beach_802C60E8, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 564604; VRAM 802CC594. */
InteractionHandler D_beach_802CC594[3] = {
    { 9, func_beach_802C5FF8, 0.0f, NULL },
    { 13, func_beach_802C60E8, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 564634; VRAM 802CC5C4. */
InteractionHandler D_beach_802CC5C4[8] = {
    { 9, func_beach_802C5FF8, 0.0f, NULL },
    { 13, func_beach_802C60E8, 0.0f, NULL },
    { 10, func_beach_802C6210, 0.0f, NULL },
    { 5, func_beach_802C649C, 0.0f, NULL },
    { 6, func_beach_802C649C, 0.0f, NULL },
    { 7, func_beach_802C649C, 0.0f, NULL },
    { 14, func_beach_802C62E4, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 5646B4; VRAM 802CC644. */
InteractionHandler D_beach_802CC644[7] = {
    { 9, func_beach_802C6700, 0.0f, NULL },
    { 13, func_beach_802C67E0, 0.0f, NULL },
    { 16, func_beach_802C6944, 400.0f, NULL },
    { 5, func_beach_802C6854, 0.0f, NULL },
    { 6, func_beach_802C6854, 0.0f, NULL },
    { 7, func_beach_802C6854, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 564724; VRAM 802CC6B4. */
InteractionHandler D_beach_802CC6B4[3] = {
    { 9, func_beach_802C6700, 0.0f, NULL },
    { 13, func_beach_802C67E0, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 564754; VRAM 802CC6E4. */
InteractionHandler D_beach_802CC6E4[3] = {
    { 9, func_beach_802C6A3C, 0.0f, NULL },
    { 13, func_beach_802C6B28, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 564784; VRAM 802CC714. */
InteractionHandler D_beach_802CC714[7] = {
    { 9, func_beach_802C6A3C, 0.0f, NULL },
    { 13, func_beach_802C6B28, 0.0f, NULL },
    { 16, func_beach_802C6944, 400.0f, NULL },
    { 5, func_beach_802C6B8C, 0.0f, NULL },
    { 6, func_beach_802C6B8C, 0.0f, NULL },
    { 7, func_beach_802C6B8C, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 5647F4; VRAM 802CC784. */
InteractionHandler D_beach_802CC784[3] = {
    { 9, func_beach_802C6A3C, 0.0f, NULL },
    { 13, func_beach_802C6B28, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 564824; VRAM 802CC7B4. */
InteractionHandler D_beach_802CC7B4[3] = {
    { 9, func_beach_802C6A3C, 0.0f, NULL },
    { 13, func_beach_802C6B28, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 564854; VRAM 802CC7E4. */
InteractionHandler D_beach_802CC7E4[2] = {
    { 28, func_beach_802C6C60, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 564874; VRAM 802CC804. */
InteractionHandler D_beach_802CC804[2] = {
    { 16, func_beach_802C6CC4, 700.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 564894; VRAM 802CC824. */
InteractionHandler D_beach_802CC824[3] = {
    { 9, func_beach_802C5FF8, 0.0f, NULL },
    { 13, func_beach_802C60E8, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 5648C4; VRAM 802CC854. */
InteractionHandler D_beach_802CC854[2] = {
    { 16, func_beach_802C6D9C, 666.666687f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 5648E4; VRAM 802CC874. */
InteractionHandler D_beach_802CC874[3] = {
    { 9, func_beach_802C6EC0, 0.0f, NULL },
    { 13, func_beach_802C6F6C, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 564914; VRAM 802CC8A4. */
InteractionHandler D_beach_802CC8A4[3] = {
    { 9, func_beach_802C6EC0, 0.0f, NULL },
    { 13, func_beach_802C6F6C, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 564944; VRAM 802CC8D4. */
InteractionHandler D_beach_802CC8D4[3] = {
    { 9, func_beach_802C6EC0, 0.0f, NULL },
    { 13, func_beach_802C6F6C, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 564974; VRAM 802CC904. */
InteractionHandler D_beach_802CC904[3] = {
    { 29, func_beach_802C7050, 0.0f, NULL },
    { 36, func_beach_802C70C0, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 5649A4; VRAM 802CC934. */
InteractionHandler D_beach_802CC934[2] = {
    { 9, func_beach_802C7130, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 5649C4; VRAM 802CC954. */
PokemonAnimationSetup D_beach_802CC954 = { &D_beach_802CC344, func_beach_802C5DAC, 0, { 0, 0, 0 }, NULL, NULL };

/* ROM 5649D8; VRAM 802CC968. */
PokemonInitData D_beach_802CC968 = { meowth_model, meowth_materials, renderPokemonModelTypeBFogged, &D_beach_802CC954, { 2.4000001f, 2.4000001f, 2.4000001f }, { 0.0f, 107.0f, -5.0f }, 21.0f, 37, 0, 0, 0, { 0, 0, 0 } };

/* Original zero-filled inter-record alignment/storage (4 bytes). */
char D_802CC99C_564A0C_padding[4] = "";

/* ROM 564A10; VRAM 802CC9A0. */
s32 D_beach_802CC9A0[1] = { 254 };

/* ROM 564A14; VRAM 802CC9A4. */
s32 D_beach_802CC9A4[2] = { 255, 110 };

/* ROM 564A1C; VRAM 802CC9AC. */
AnimationHeader D_beach_802CC9AC = { 0.340000004f, 70.0f, D_80166A90_F2F20, D_8016B300_F7790, NULL };

/* ROM 564A30; VRAM 802CC9C0. */
AnimationHeader D_beach_802CC9C0 = { 1.0f, 40.0f, D_80165010_F14A0, D_8016B190_F7620, NULL };

/* ROM 564A44; VRAM 802CC9D4. */
AnimationHeader D_beach_802CC9D4 = { 1.0f, 38.0f, D_80165D90_F2220, D_8016B250_F76E0, NULL };

/* ROM 564A58; VRAM 802CC9E8. */
AnimationHeader D_beach_802CC9E8 = { 0.529999971f, 36.0f, D_80167D20_F41B0, D_8016B420_F78B0, D_beach_802CC9A0 };

/* ROM 564A6C; VRAM 802CC9FC. */
AnimationHeader D_beach_802CC9FC = { 0.300000012f, 66.0f, D_80168D50_F51E0, D_8016B4F0_F7980, D_beach_802CC9A4 };

/* ROM 564A80; VRAM 802CCA10. */
InteractionHandler D_beach_802CCA10[9] = {
    { 9, func_beach_802C74EC, 0.0f, NULL },
    { 13, func_beach_802C74EC, 0.0f, NULL },
    { 10, func_beach_802C755C, 0.0f, NULL },
    { 14, func_beach_802C762C, 0.0f, NULL },
    { 5, func_beach_802C77F0, 0.0f, NULL },
    { 6, func_beach_802C77F0, 0.0f, NULL },
    { 7, func_beach_802C77F0, 0.0f, NULL },
    { 15, func_beach_802C77CC, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 564B10; VRAM 802CCAA0. */
RandomState D_beach_802CCAA0[3] = {
    { 100, func_beach_802C737C },
    { 100, func_beach_802C73EC },
    { 0, NULL },
};

/* ROM 564B28; VRAM 802CCAB8. */
InteractionHandler D_beach_802CCAB8[3] = {
    { 9, func_beach_802C74EC, 0.0f, NULL },
    { 13, func_beach_802C74EC, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 564B58; VRAM 802CCAE8. */
InteractionHandler D_beach_802CCAE8[4] = {
    { 9, func_beach_802C74EC, 0.0f, NULL },
    { 13, func_beach_802C74EC, 0.0f, NULL },
    { 10, func_beach_802C755C, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 564B98; VRAM 802CCB28. */
InteractionHandler D_beach_802CCB28[8] = {
    { 9, func_beach_802C74EC, 0.0f, NULL },
    { 13, func_beach_802C74EC, 0.0f, NULL },
    { 10, func_beach_802C755C, 0.0f, NULL },
    { 14, func_beach_802C762C, 0.0f, NULL },
    { 5, func_beach_802C77F0, 0.0f, NULL },
    { 6, func_beach_802C77F0, 0.0f, NULL },
    { 7, func_beach_802C77F0, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 564C18; VRAM 802CCBA8. */
InteractionHandler D_beach_802CCBA8[5] = {
    { 9, func_beach_802C74EC, 0.0f, NULL },
    { 13, func_beach_802C74EC, 0.0f, NULL },
    { 10, func_beach_802C755C, 0.0f, NULL },
    { 14, func_beach_802C762C, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 564C68; VRAM 802CCBF8. */
InteractionHandler D_beach_802CCBF8[3] = {
    { 9, func_beach_802C74EC, 0.0f, NULL },
    { 13, func_beach_802C74EC, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 564C98; VRAM 802CCC28. */
InteractionHandler D_beach_802CCC28[4] = {
    { 32, func_beach_802C7A60, 0.0f, NULL },
    { 9, func_beach_802C79DC, 0.0f, NULL },
    { 13, func_beach_802C79DC, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 564CD8; VRAM 802CCC68. */
InteractionHandler D_beach_802CCC68[4] = {
    { 32, func_beach_802C7A60, 0.0f, NULL },
    { 9, func_beach_802C79DC, 0.0f, NULL },
    { 13, func_beach_802C79DC, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 564D18; VRAM 802CCCA8. */
InteractionHandler D_beach_802CCCA8[3] = {
    { 9, func_beach_802C74EC, 0.0f, NULL },
    { 13, func_beach_802C74EC, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 564D48; VRAM 802CCCD8. */
PokemonAnimationSetup D_beach_802CCCD8 = { &D_beach_802CC9AC, func_beach_802C72E0, 0, { 0, 0, 0 }, NULL, NULL };

/* ROM 564D5C; VRAM 802CCCEC. */
PokemonInitData D_beach_802CCCEC = { eevee_model, eevee_materials, renderPokemonModelTypeBFogged, &D_beach_802CCCD8, { 2.4000001f, 2.4000001f, 2.4000001f }, { 0.0f, 80.0f, 0.0f }, 22.0f, 37, 0, 0, 0, { 0, 0, 0 } };

/* ROM 564D90; VRAM 802CCD20. */
s32 D_beach_802CCD20[1] = { 253 };

/* ROM 564D94; VRAM 802CCD24. */
AnimationHeader D_beach_802CCD24 = { 0.300000012f, 100.0f, butterfree_photo_pose0, NULL, NULL };

/* ROM 564DA8; VRAM 802CCD38. */
AnimationHeader D_beach_802CCD38 = { 0.300000012f, 100.0f, butterfree_photo_pose1, NULL, D_beach_802CCD20 };

/* ROM 564DBC; VRAM 802CCD4C. */
AnimationHeader D_beach_802CCD4C = { 0.349999994f, 100.0f, butterfree_photo_pose0, NULL, NULL };

/* ROM 564DD0; VRAM 802CCD60. */
InteractionHandler D_beach_802CCD60[3] = {
    { 8, func_beach_802C7CF0, 0.0f, NULL },
    { 12, func_beach_802C7CF0, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 564E00; VRAM 802CCD90. */
PokemonAnimationSetup D_beach_802CCD90 = { &D_beach_802CCD24, func_beach_802C7B10, 0, { 0, 0, 0 }, NULL, NULL };

/* ROM 564E14; VRAM 802CCDA4. */
PokemonInitData D_beach_802CCDA4 = { butterfree_model, NULL, renderPokemonModelTypeBFogged, &D_beach_802CCD90, { 1.60000002f, 1.60000002f, 1.60000002f }, { 0.0f, 0.0f, 0.0f }, 40.0f, 7, 0, 0, 0, { 0, 0, 0 } };

/* Original zero-filled inter-record alignment/storage (8 bytes). */
char D_802CCDD8_564E48_padding[8] = "";

/* ROM 564E50; VRAM 802CCDE0. */
s32 D_beach_802CCDE0[2] = { 0, 383 };

/* ROM 564E58; VRAM 802CCDE8. */
AnimationHeader D_beach_802CCDE8 = { 0.5f, 265.0f, D_80183D20_1101B0, D_80184400_110890, D_beach_802CCDE0 };

/* ROM 564E6C; VRAM 802CCDFC. */
s32 D_beach_802CCDFC = 0;

/* ROM 564E70; VRAM 802CCE00. */
s32 D_beach_802CCE00 = 0;

/* ROM 564E74; VRAM 802CCE04. */
s32 D_beach_802CCE04 = 0;

/* ROM 564E78; VRAM 802CCE08. */
AnimationHeader D_beach_802CCE08 = { 0.0f, 0.0f, D_80183D20_1101B0, D_80184400_110890, NULL };

/* ROM 564E8C; VRAM 802CCE1C. */
InteractionHandler D_beach_802CCE1C[2] = {
    { 24, func_beach_802C8028, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 564EAC; VRAM 802CCE3C. */
PokemonAnimationSetup D_beach_802CCE3C = { &D_beach_802CCE08, func_beach_802C7E70, 0, { 0, 0, 0 }, NULL, NULL };

/* ROM 564EC0; VRAM 802CCE50. */
PokemonInitData D_beach_802CCE50 = { lapras_model, lapras_materials, renderPokemonModelTypeIFogged, &D_beach_802CCE3C, { 3.0f, 3.0f, 3.0f }, { 0.0f, -40.0f, -150.0f }, 100.0f, 37, 0, 0, 0, { 0, 0, 0 } };

/* Original zero-filled inter-record alignment/storage (12 bytes). */
char D_802CCE84_564EF4_padding[12] = "";

/* ROM 564F00; VRAM 802CCE90. */
s32 D_beach_802CCE90[3] = { 343, 143, 342 };

/* ROM 564F0C; VRAM 802CCE9C. */
s32 D_beach_802CCE9C[1] = { 344 };

/* ROM 564F10; VRAM 802CCEA0. */
s32 D_beach_802CCEA0[4] = { 342, 117, 142, 143 };

/* ROM 564F20; VRAM 802CCEB0. */
AnimationHeader D_beach_802CCEB0 = { 1.0f, 80.0f, D_80159E60_E62F0, NULL, D_beach_802CCE90 };

/* ROM 564F34; VRAM 802CCEC4. */
AnimationHeader D_beach_802CCEC4 = { 1.0f, 120.0f, D_8015EBA0_EB030, NULL, D_beach_802CCE9C };

/* ROM 564F48; VRAM 802CCED8. */
AnimationHeader D_beach_802CCED8 = { 0.5f, 65.0f, D_8015BC10_E80A0, D_801617D0_EDC60, NULL };

/* ROM 564F5C; VRAM 802CCEEC. */
AnimationHeader D_beach_802CCEEC = { 1.0f, 136.0f, D_8015CBC0_E9050, NULL, NULL };

/* ROM 564F70; VRAM 802CCF00. */
AnimationHeader D_beach_802CCF00 = { 1.0f, 72.0f, D_8015FD10_EC1A0, NULL, D_beach_802CCEA0 };

/* ROM 564F84; VRAM 802CCF14. */
InteractionHandler D_beach_802CCF14[3] = {
    { 9, func_beach_802C84A4, 0.0f, NULL },
    { 13, func_beach_802C84A4, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 564FB4; VRAM 802CCF44. */
InteractionHandler D_beach_802CCF44[2] = {
    { 16, func_beach_802C8354, 1000.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 564FD4; VRAM 802CCF64. */
PokemonAnimationSetup D_beach_802CCF64 = { &D_beach_802CCEB0, func_beach_802C82B0, 0, { 0, 0, 0 }, NULL, NULL };

/* ROM 564FE8; VRAM 802CCF78. */
PokemonInitData D_beach_802CCF78 = { doduo_model, doduo_materials, renderPokemonModelTypeBFogged, &D_beach_802CCF64, { 2.0f, 2.0f, 2.0f }, { 0.0f, 300.0f, 0.0f }, 40.0f, 37, 0, 0, 0, { 0, 0, 0 } };

/* Original zero-filled inter-record alignment/storage (4 bytes). */
char D_802CCFAC_56501C_padding[4] = "";

/* ROM 565020; VRAM 802CCFB0. */
s32 D_beach_802CCFB0[2] = { 256, 124 };

/* ROM 565028; VRAM 802CCFB8. */
s32 D_beach_802CCFB8[2] = { 257, 124 };

/* ROM 565030; VRAM 802CCFC0. */
AnimationHeader D_beach_802CCFC0 = { 0.400000006f, 50.0f, D_801A66D0_132B60, NULL, D_beach_802CCFB0 };

/* ROM 565044; VRAM 802CCFD4. */
AnimationHeader D_beach_802CCFD4 = { 0.300000012f, 51.0f, D_801A08C0_12CD50, D_801A8CC0_135150, NULL };

/* ROM 565058; VRAM 802CCFE8. */
AnimationHeader D_beach_802CCFE8 = { 0.330000013f, 48.0f, D_801A2280_12E710, D_801A8D50_1351E0, D_beach_802CCFB8 };

/* ROM 56506C; VRAM 802CCFFC. */
AnimationHeader D_beach_802CCFFC = { 0.330000013f, 32.0f, D_801A4A80_130F10, D_801A8DF0_135280, NULL };

/* ROM 565080; VRAM 802CD010. */
InteractionHandler D_beach_802CD010[3] = {
    { 9, NULL, 0.0f, func_beach_802C8900 },
    { 13, NULL, 0.0f, func_beach_802C8900 },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 5650B0; VRAM 802CD040. */
InteractionHandler D_beach_802CD040[2] = {
    { 16, func_beach_802C86A8, 1000.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 5650D0; VRAM 802CD060. */
s32 D_beach_802CD060 = 0;

/* ROM 5650D4; VRAM 802CD064. */
InteractionHandler D_beach_802CD064[5] = {
    { 9, func_beach_802C8AAC, 0.0f, NULL },
    { 13, func_beach_802C8AAC, 0.0f, NULL },
    { 37, NULL, 0.0f, func_beach_802C8C30 },
    { 38, NULL, 0.0f, func_beach_802C8C58 },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 565124; VRAM 802CD0B4. */
InteractionHandler D_beach_802CD0B4[3] = {
    { 9, func_beach_802C8CC0, 0.0f, NULL },
    { 31, func_beach_802C86A8, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 565154; VRAM 802CD0E4. */
InteractionHandler D_beach_802CD0E4[2] = {
    { 16, func_beach_802C86A8, 666.666687f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 565174; VRAM 802CD104. */
PokemonAnimationSetup D_beach_802CD104 = { &D_beach_802CCFD4, func_beach_802C85B0, 0, { 0, 0, 0 }, NULL, NULL };

/* ROM 565188; VRAM 802CD118. */
PokemonInitData D_beach_802CD118 = { pidgey_model, pidgey_materials, renderPokemonModelTypeIFogged, &D_beach_802CD104, { 2.0f, 2.0f, 2.0f }, { 0.0f, 74.0f, -2.0f }, 30.0f, 37, 0, 0, 0, { 0, 0, 0 } };

/* Original zero-filled inter-record alignment/storage (4 bytes). */
char D_802CD14C_5651BC_padding[4] = "";

/* ROM 5651C0; VRAM 802CD150. */
s32 D_beach_802CD150[2] = { 304, 363 };

/* ROM 5651C8; VRAM 802CD158. */
s32 D_beach_802CD158[2] = { 304, 388 };

/* ROM 5651D0; VRAM 802CD160. */
s32 D_beach_802CD160[2] = { 0, 363 };

/* ROM 5651D8; VRAM 802CD168. */
AnimationHeader D_beach_802CD168 = { 1.0f, 129.0f, D_801AF4B0_13B940, NULL, D_beach_802CD150 };

/* ROM 5651EC; VRAM 802CD17C. */
AnimationHeader D_beach_802CD17C = { 1.0f, 108.0f, D_801AA9D0_136E60, NULL, NULL };

/* ROM 565200; VRAM 802CD190. */
AnimationHeader D_beach_802CD190 = { 0.649999976f, 111.0f, D_801ACF90_139420, NULL, D_beach_802CD158 };

/* ROM 565214; VRAM 802CD1A4. */
AnimationHeader D_beach_802CD1A4 = { 1.0f, 108.0f, D_801AE790_13AC20, NULL, NULL };

/* ROM 565228; VRAM 802CD1B8. */
AnimationHeader D_beach_802CD1B8 = { 1.0f, 108.0f, D_801AC250_1386E0, NULL, D_beach_802CD160 };

/* ROM 56523C; VRAM 802CD1CC. */
AnimationHeader D_beach_802CD1CC = { 1.0f, 108.0f, D_801AB610_137AA0, NULL, NULL };

/* Original zero-filled inter-record alignment/storage (4 bytes). */
char D_802CD1E0_565250_padding[4] = "";

/* ROM 565254; VRAM 802CD1E4. */
InteractionHandler D_beach_802CD1E4[3] = {
    { 9, func_beach_802C8F48, 0.0f, NULL },
    { 10, func_beach_802C8F48, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 565284; VRAM 802CD214. */
InteractionHandler D_beach_802CD214[3] = {
    { 9, NULL, 0.0f, func_beach_802C914C },
    { 13, NULL, 0.0f, func_beach_802C914C },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 5652B4; VRAM 802CD244. */
PokemonAnimationSetup D_beach_802CD244 = { &D_beach_802CD17C, func_beach_802C8DB0, 0, { 0, 0, 0 }, NULL, NULL };

/* ROM 5652C8; VRAM 802CD258. */
PokemonInitData D_beach_802CD258 = { scyther_model, NULL, renderPokemonModelTypeDFogged, &D_beach_802CD244, { 0.899999976f, 0.899999976f, 0.899999976f }, { 0.0f, 60.0f, 0.0f }, 63.0f, 37, 0, 0, 0, { 0, 0, 0 } };

/* Original zero-filled inter-record alignment/storage (4 bytes). */
char D_802CD28C_5652FC_padding[4] = "";

/* ROM 565300; VRAM 802CD290. */
s32 D_beach_802CD290[2] = { 0, 121 };

/* ROM 565308; VRAM 802CD298. */
s32 D_beach_802CD298[2] = { 252, 366 };

/* ROM 565310; VRAM 802CD2A0. */
s32 D_beach_802CD2A0[2] = { 251, 122 };

/* ROM 565318; VRAM 802CD2A8. */
AnimationHeader D_beach_802CD2A8 = { 0.5f, 28.0f, D_80186E20_1132B0, NULL, NULL };

/* ROM 56532C; VRAM 802CD2BC. */
AnimationHeader D_beach_802CD2BC = { 1.0f, 60.0f, D_80187230_1136C0, NULL, NULL };

/* ROM 565340; VRAM 802CD2D0. */
AnimationHeader D_beach_802CD2D0 = { 0.400000006f, 20.0f, D_80188ED0_115360, D_8018A4C0_116950, NULL };

/* ROM 565354; VRAM 802CD2E4. */
AnimationHeader D_beach_802CD2E4 = { 0.5f, 40.0f, D_801866A0_112B30, D_8018A270_116700, NULL };

/* ROM 565368; VRAM 802CD2F8. */
AnimationHeader D_beach_802CD2F8 = { 0.5f, 36.0f, D_80185010_1114A0, NULL, NULL };

/* ROM 56537C; VRAM 802CD30C. */
AnimationHeader D_beach_802CD30C = { 0.5f, 42.0f, D_80187BD0_114060, D_8018A370_116800, D_beach_802CD290 };

/* ROM 565390; VRAM 802CD320. */
AnimationHeader D_beach_802CD320 = { 0.400000006f, 16.0f, D_80185D90_112220, NULL, NULL };

/* ROM 5653A4; VRAM 802CD334. */
AnimationHeader D_beach_802CD334 = { 0.5f, 60.0f, D_801895E0_115A70, NULL, D_beach_802CD298 };

/* ROM 5653B8; VRAM 802CD348. */
AnimationHeader D_beach_802CD348 = { 0.400000006f, 24.0f, D_80188260_1146F0, D_8018A410_1168A0, D_beach_802CD2A0 };

/* ROM 5653CC; VRAM 802CD35C. */
InteractionHandler D_beach_802CD35C[8] = {
    { 9, func_beach_802C96F0, 0.0f, NULL },
    { 13, func_beach_802C96F0, 0.0f, NULL },
    { 10, func_beach_802C9760, 0.0f, NULL },
    { 15, func_beach_802C9978, 0.0f, NULL },
    { 5, func_beach_802C999C, 0.0f, NULL },
    { 6, func_beach_802C999C, 0.0f, NULL },
    { 7, func_beach_802C999C, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 56544C; VRAM 802CD3DC. */
RandomState D_beach_802CD3DC[3] = {
    { 100, func_beach_802C9580 },
    { 100, func_beach_802C95F0 },
    { 0, NULL },
};

/* ROM 565464; VRAM 802CD3F4. */
InterpData* D_beach_802CD3F4 = NULL;

/* ROM 565468; VRAM 802CD3F8. */
InteractionHandler D_beach_802CD3F8[4] = {
    { 9, func_beach_802C943C, 0.0f, NULL },
    { 13, func_beach_802C943C, 0.0f, NULL },
    { 33, func_beach_802C93B8, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 5654A8; VRAM 802CD438. */
InteractionHandler D_beach_802CD438[4] = {
    { 9, func_beach_802C943C, 0.0f, NULL },
    { 13, func_beach_802C943C, 0.0f, NULL },
    { 34, func_beach_802C92BC, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 5654E8; VRAM 802CD478. */
InteractionHandler D_beach_802CD478[3] = {
    { 9, func_beach_802C96F0, 0.0f, NULL },
    { 13, func_beach_802C96F0, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 565518; VRAM 802CD4A8. */
InteractionHandler D_beach_802CD4A8[4] = {
    { 9, func_beach_802C96F0, 0.0f, NULL },
    { 13, func_beach_802C96F0, 0.0f, NULL },
    { 10, func_beach_802C9760, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 565558; VRAM 802CD4E8. */
InteractionHandler D_beach_802CD4E8[3] = {
    { 9, func_beach_802C96F0, 0.0f, NULL },
    { 13, func_beach_802C96F0, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 565588; VRAM 802CD518. */
InteractionHandler D_beach_802CD518[3] = {
    { 9, func_beach_802C96F0, 0.0f, NULL },
    { 13, func_beach_802C96F0, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 5655B8; VRAM 802CD548. */
PokemonAnimationSetup D_beach_802CD548 = { &D_beach_802CD2E4, func_beach_802C9240, 0, { 0, 0, 0 }, NULL, NULL };

/* ROM 5655CC; VRAM 802CD55C. */
PokemonInitData D_beach_802CD55C = { chansey_model, chansey_materials, renderPokemonModelTypeIFogged, &D_beach_802CD548, { 2.0f, 2.0f, 2.0f }, { 0.0f, 210.0f, 0.0f }, 50.0f, 37, 0, 0, 0, { 0, 0, 0 } };

/* ROM 565600; VRAM 802CD590. */
s32 D_beach_802CD590[2] = { 0, 105 };

/* ROM 565608; VRAM 802CD598. */
s32 D_beach_802CD598[2] = { 261, 104 };

/* ROM 565610; VRAM 802CD5A0. */
s32 D_beach_802CD5A0[1] = { 260 };

/* ROM 565614; VRAM 802CD5A4. */
s32 D_beach_802CD5A4[1] = { 262 };

/* ROM 565618; VRAM 802CD5A8. */
AnimationHeader D_beach_802CD5A8 = { 0.25f, 60.0f, D_80173C30_1000C0, D_80179760_105BF0, NULL };

/* ROM 56562C; VRAM 802CD5BC. */
AnimationHeader D_beach_802CD5BC = { 0.800000012f, 80.0f, D_8016E200_FA690, D_80179560_1059F0, NULL };

/* ROM 565640; VRAM 802CD5D0. */
AnimationHeader D_beach_802CD5D0 = { 0.680000007f, 50.0f, D_8016F5B0_FBA40, D_80179600_105A90, D_beach_802CD590 };

/* ROM 565654; VRAM 802CD5E4. */
AnimationHeader D_beach_802CD5E4 = { 0.379999995f, 107.0f, D_80170AD0_FCF60, D_801796A0_105B30, D_beach_802CD598 };

/* ROM 565668; VRAM 802CD5F8. */
AnimationHeader D_beach_802CD5F8 = { 0.449999988f, 40.0f, D_801765D0_102A60, D_801798B0_105D40, D_beach_802CD5A0 };

/* ROM 56567C; VRAM 802CD60C. */
AnimationHeader D_beach_802CD60C = { 0.5f, 98.0f, D_80177520_1039B0, D_80179940_105DD0, NULL };

/* ROM 565690; VRAM 802CD620. */
AnimationHeader D_beach_802CD620 = { 1.0f, 120.0f, D_80175390_101820, D_80179810_105CA0, D_beach_802CD5A4 };

/* ROM 5656A4; VRAM 802CD634. */
InteractionHandler D_beach_802CD634[6] = {
    { 9, func_beach_802C9DCC, 0.0f, NULL },
    { 13, func_beach_802C9DCC, 0.0f, NULL },
    { 5, func_beach_802C9EBC, 0.0f, NULL },
    { 6, func_beach_802C9EBC, 0.0f, NULL },
    { 7, func_beach_802C9EBC, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 565704; VRAM 802CD694. */
InteractionHandler D_beach_802CD694[3] = {
    { 9, func_beach_802C9BF8, 0.0f, NULL },
    { 13, func_beach_802C9BF8, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 565734; VRAM 802CD6C4. */
InteractionHandler D_beach_802CD6C4[3] = {
    { 9, func_beach_802C9DCC, 0.0f, NULL },
    { 13, func_beach_802C9DCC, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 565764; VRAM 802CD6F4. */
InteractionHandler D_beach_802CD6F4[7] = {
    { 9, func_beach_802C9DCC, 0.0f, NULL },
    { 13, func_beach_802C9DCC, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
    { 9, func_beach_802C9DCC, 0.0f, NULL },
    { 13, func_beach_802C9DCC, 0.0f, NULL },
    { 16, func_beach_802C9F9C, 500.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 5657D4; VRAM 802CD764. */
RandomState D_beach_802CD764[2] = {
    { 100, func_beach_802C9CF8 },
    { 0, NULL },
};

/* ROM 5657E4; VRAM 802CD774. */
RandomState D_beach_802CD774[4] = {
    { 100, func_beach_802C9AE4 },
    { 100, func_beach_802C9B40 },
    { 100, func_beach_802C9B9C },
    { 0, NULL },
};

/* ROM 565804; VRAM 802CD794. */
PokemonAnimationSetup D_beach_802CD794 = { &D_beach_802CD5A8, func_beach_802C9AC0, 0, { 0, 0, 0 }, NULL, NULL };

/* ROM 565818; VRAM 802CD7A8. */
PokemonInitData D_beach_802CD7A8 = { kangaskhan_model, kangaskhan_materials, renderPokemonModelTypeIFogged, &D_beach_802CD794, { 1.5f, 1.5f, 1.5f }, { 0.0f, 235.0f, 0.0f }, 104.0f, 37, 0, 0, 0, { 0, 0, 0 } };

/* Original zero-filled inter-record alignment/storage (4 bytes). */
char D_802CD7DC_56584C_padding[4] = "";

/* ROM 565850; VRAM 802CD7E0. */
UnkEC64Arg3 D_beach_802CD7E0[2] = {
    { 0, NULL, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 1.0f, 1.0f, 1.0f } },
    { 18, NULL, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } },
};

/* ROM 5658A8; VRAM 802CD838. */
PokemonDef D_beach_802CD838 = { 16, (pokemonInit) func_beach_802C8D74, pokemonChangeBlock, pokemonRemoveOne };

/* ROM 5658B8; VRAM 802CD848. */
PokemonDef D_beach_802CD848 = { 123, (pokemonInit) func_beach_802C9204, pokemonChangeBlock, pokemonRemoveOne };

/* ROM 5658C8; VRAM 802CD858. */
InteractionHandler D_beach_802CD858[6] = {
    { 9, func_beach_802CA198, 0.0f, NULL },
    { 13, func_beach_802CA198, 0.0f, NULL },
    { 10, func_beach_802CA198, 0.0f, NULL },
    { 14, func_beach_802CA198, 0.0f, NULL },
    { 16, func_beach_802CA198, 1000.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 565928; VRAM 802CD8B8. */
RandomState D_beach_802CD8B8[3] = {
    { 70, func_beach_802CA1BC },
    { 30, func_beach_802CA23C },
    { 0, NULL },
};

/* ROM 565940; VRAM 802CD8D0. */
PokemonAnimationSetup D_beach_802CD8D0 = { NULL, func_beach_802CA148, 0, { 0, 0, 0 }, NULL, NULL };

/* ROM 565954; VRAM 802CD8E4. */
PokemonInitData D_beach_802CD8E4 = { D_beach_802CD7E0, NULL, renRenderModelTypeB, &D_beach_802CD8D0, { 2.0f, 2.0f, 2.0f }, { 0.0f, 17.0f, -2.0f }, 17.0f, 1, 0, 0, 0, { 0, 0, 0 } };

/* Original zero-filled inter-record alignment/storage (8 bytes). */
char D_802CD918_565988_padding[8] = "";

/* ROM 565990; VRAM 802CD920. */
AnimationHeader D_beach_802CD920 = { 0.0f, 100.0f, D_80138C50_C50E0, NULL, NULL };

/* ROM 5659A4; VRAM 802CD934. */
PokemonAnimationSetup D_beach_802CD934 = { &D_beach_802CD920, func_beach_802CA300, 0, { 0, 0, 0 }, NULL, NULL };

/* ROM 5659B8; VRAM 802CD948. */
PokemonInitData D_beach_802CD948 = { D_80136AC0_C2F50, NULL, renderPokemonModelTypeDFogged, &D_beach_802CD934, { 10.0f, 10.0f, 10.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f, 64, 0, 0, 0, { 0, 0, 0 } };

/* Original zero-filled inter-record alignment/storage (4 bytes). */
char D_802CD97C_5659EC_padding[4] = "";

/* ROM 5659F0; VRAM 802CD980. */
AnimationHeader D_beach_802CD980 = { 1.0f, 100.0f, gate_modelanim_closed, gate_matanim_closed, NULL };

/* ROM 565A04; VRAM 802CD994. */
AnimationHeader D_beach_802CD994 = { 1.0f, 100.0f, gate_modelanim_raise_bar, gate_matanim_raise_bar, NULL };

/* ROM 565A18; VRAM 802CD9A8. */
AnimationHeader D_beach_802CD9A8 = { 1.0f, 100.0f, gate_modelanim_opening, gate_matanim_opening, NULL };

/* ROM 565A2C; VRAM 802CD9BC. */
AnimationHeader D_beach_802CD9BC = { 1.0f, 100.0f, gate_modelanim_opened, gate_matanim_opened, NULL };

/* ROM 565A40; VRAM 802CD9D0. */
s32 D_beach_802CD9D0 = -1;

/* ROM 565A44; VRAM 802CD9D4. */
s32 D_beach_802CD9D4 = 0;

/* ROM 565A48; VRAM 802CD9D8. */
InteractionHandler D_beach_802CD9D8[2] = {
    { 16, func_beach_802CA4CC, 2000.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 565A68; VRAM 802CD9F8. */
UnkBlueShark D_beach_802CD9F8 = { 1001, 0 };

/* ROM 565A6C; VRAM 802CD9FC. */
PokemonAnimationSetup D_beach_802CD9FC = { &D_beach_802CD980, func_beach_802CA450, 0, { 0, 0, 0 }, NULL, NULL };

/* ROM 565A80; VRAM 802CDA10. */
PokemonInitData D_beach_802CDA10 = { gate_model, gate_materials, renderModelTypeDFogged, &D_beach_802CD9FC, { 10.0f, 10.0f, 10.0f }, { 0.0f, 0.0f, 0.0f }, 0.00999999978f, 0, 0, 0, 0, { 0, 0, 0 } };

/* Original zero-filled inter-record alignment/storage (12 bytes). */
char D_802CDA44_565AB4_padding[12] = "";

/* ROM 565AC0; VRAM 802CDA50. */
s32 D_beach_802CDA50[1] = { 211 };

/* ROM 565AC4; VRAM 802CDA54. */
s32 D_beach_802CDA54[3] = { 210, 376, 114 };

/* ROM 565AD0; VRAM 802CDA60. */
s32 D_beach_802CDA60[3] = { 211, 376, 114 };

/* ROM 565ADC; VRAM 802CDA6C. */
s32 D_beach_802CDA6C[3] = { 0, 376, 114 };

/* ROM 565AE8; VRAM 802CDA78. */
AnimationHeader D_802CDA78_565AE8 = { 0.5f, 60.0f, D_800FDC70_7B090, NULL, D_beach_802CDA50 };

/* ROM 565AFC; VRAM 802CDA8C. */
AnimationHeader D_beach_802CDA8C = { 0.5f, 65.0f, D_800FAE40_78260, NULL, D_beach_802CDA54 };

/* ROM 565B10; VRAM 802CDAA0. */
AnimationHeader D_802CDAA0_565B10 = { 0.5f, 59.0f, D_800FBF50_79370, NULL, D_beach_802CDA60 };

/* ROM 565B24; VRAM 802CDAB4. */
AnimationHeader D_beach_802CDAB4 = { 0.5f, 50.0f, D_800FD080_7A4A0, NULL, D_beach_802CDA6C };

/* ROM 565B38; VRAM 802CDAC8. */
InteractionHandler D_802CDAC8_565B38[1] = {
    { 58, NULL, 0.0f, NULL },
};

/* ROM 565B48; VRAM 802CDAD8. */
PokemonAnimationSetup D_beach_802CDAD8 = { &D_beach_802CDA8C, func_beach_802CAB50, 0, { 0, 0, 0 }, NULL, NULL };

/* ROM 565B5C; VRAM 802CDAEC. */
PokemonInitData D_beach_802CDAEC = { magikarp_model, NULL, renderPokemonModelTypeBFogged, &D_beach_802CDAD8, { 1.60000002f, 1.60000002f, 1.60000002f }, { 0.0f, -40.0f, -11.0f }, 35.0f, 37, 0, 0, 0, { 0, 0, 0 } };

/* ROM 565B90; VRAM 802CDB20. */
s32 D_beach_802CDB20[1] = { 266 };

/* ROM 565B94; VRAM 802CDB24. */
s32 D_beach_802CDB24[3] = { 264, 127, 360 };

/* ROM 565BA0; VRAM 802CDB30. */
s32 D_beach_802CDB30[1] = { 263 };

/* ROM 565BA4; VRAM 802CDB34. */
s32 D_beach_802CDB34[2] = { 265, 371 };

/* ROM 565BAC; VRAM 802CDB3C. */
s32 D_beach_802CDB3C[2] = { 267, 268 };

/* ROM 565BB4; VRAM 802CDB44. */
s32 D_beach_802CDB44[1] = { 354 };

/* ROM 565BB8; VRAM 802CDB48. */
s32 D_beach_802CDB48[2] = { 0, 138 };

/* ROM 565BC0; VRAM 802CDB50. */
s32 D_beach_802CDB50[3] = { 264, 127, 360 };

/* ROM 565BCC; VRAM 802CDB5C. */
AnimationHeader D_beach_802CDB5C = { 0.430000007f, 40.0f, D_80112F20_90340, D_8011A2B0_976D0, NULL };

/* ROM 565BE0; VRAM 802CDB70. */
AnimationHeader D_beach_802CDB70 = { 0.5f, 80.0f, D_80113740_90B60, D_8011A370_97790, D_beach_802CDB20 };

/* ROM 565BF4; VRAM 802CDB84. */
AnimationHeader D_beach_802CDB84 = { 0.300000012f, 63.0f, D_8010E190_8B5B0, D_80119A00_96E20, D_beach_802CDB24 };

/* ROM 565C08; VRAM 802CDB98. */
AnimationHeader D_802CDB98_565C08 = { 0.349999994f, 12.0f, D_801092F0_86710, D_801196C0_96AE0, NULL };

/* ROM 565C1C; VRAM 802CDBAC. */
AnimationHeader D_beach_802CDBAC = { 0.600000024f, 16.0f, D_8010D410_8A830, D_80119960_96D80, NULL };

/* ROM 565C30; VRAM 802CDBC0. */
AnimationHeader D_beach_802CDBC0 = { 0.600000024f, 120.0f, D_801161D0_935F0, D_8011ADE0_98200, D_beach_802CDB30 };

/* ROM 565C44; VRAM 802CDBD4. */
AnimationHeader D_beach_802CDBD4 = { 0.300000012f, 36.0f, D_80111AA0_8EEC0, D_8011A1B0_975D0, D_beach_802CDB34 };

/* ROM 565C58; VRAM 802CDBE8. */
AnimationHeader D_beach_802CDBE8 = { 0.400000006f, 5.0f, D_8010CE10_8A230, D_801198B0_96CD0, NULL };

/* ROM 565C6C; VRAM 802CDBFC. */
AnimationHeader D_beach_802CDBFC = { 0.400000006f, 35.0f, D_8010C370_89790, D_80119800_96C20, NULL };

/* ROM 565C80; VRAM 802CDC10. */
AnimationHeader D_beach_802CDC10 = { 0.400000006f, 75.0f, D_801189D0_95DF0, D_8011AF80_983A0, D_beach_802CDB3C };

/* ROM 565C94; VRAM 802CDC24. */
AnimationHeader D_802CDC24_565C94 = { 0.600000024f, 64.0f, D_80109C10_87030, D_80119760_96B80, D_beach_802CDB44 };

/* ROM 565CA8; VRAM 802CDC38. */
AnimationHeader D_802CDC38_565CA8 = { 0.600000024f, 16.0f, D_80117C40_95060, D_8011AEE0_98300, D_beach_802CDB48 };

/* ROM 565CBC; VRAM 802CDC4C. */
AnimationHeader D_802CDC4C_565CBC = { 0.300000012f, 63.0f, D_80114610_91A30, D_8011A440_97860, D_beach_802CDB50 };

/* ROM 565CD0; VRAM 802CDC60. */
InteractionHandler D_beach_802CDC60[2] = {
    { 26, func_beach_802CB44C, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 565CF0; VRAM 802CDC80. */
InteractionHandler D_beach_802CDC80[2] = {
    { 30, func_beach_802CADCC, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 565D10; VRAM 802CDCA0. */
InteractionHandler D_beach_802CDCA0[3] = {
    { 9, func_beach_802CAF1C, 0.0f, NULL },
    { 13, func_beach_802CAF1C, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 565D40; VRAM 802CDCD0. */
InteractionHandler D_beach_802CDCD0[7] = {
    { 9, func_beach_802CAFEC, 0.0f, NULL },
    { 13, func_beach_802CAFEC, 0.0f, NULL },
    { 10, func_beach_802CAFEC, 0.0f, NULL },
    { 5, func_beach_802CB054, 0.0f, NULL },
    { 6, func_beach_802CB054, 0.0f, NULL },
    { 7, func_beach_802CB054, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 565DB0; VRAM 802CDD40. */
InteractionHandler D_beach_802CDD40[4] = {
    { 9, func_beach_802CAFEC, 0.0f, NULL },
    { 13, func_beach_802CAFEC, 0.0f, NULL },
    { 10, func_beach_802CAFEC, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 565DF0; VRAM 802CDD80. */
InteractionHandler D_beach_802CDD80[11] = {
    { 14, func_beach_802CB520, 0.0f, NULL },
    { 15, func_beach_802CB520, 0.0f, NULL },
    { 9, func_beach_802CB44C, 0.0f, NULL },
    { 13, func_beach_802CB44C, 0.0f, NULL },
    { 26, func_beach_802CB44C, 0.0f, NULL },
    { 10, func_beach_802CB44C, 0.0f, NULL },
    { 5, func_beach_802CB784, 0.0f, NULL },
    { 6, func_beach_802CB784, 0.0f, NULL },
    { 7, func_beach_802CB784, 0.0f, NULL },
    { 35, func_beach_802CB874, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 565EA0; VRAM 802CDE30. */
RandomState D_beach_802CDE30[3] = {
    { 1, func_beach_802CB36C },
    { 1, func_beach_802CB3DC },
    { 0, NULL },
};

/* ROM 565EB8; VRAM 802CDE48. */
InteractionHandler D_beach_802CDE48[3] = {
    { 9, func_beach_802CB44C, 0.0f, NULL },
    { 13, func_beach_802CB44C, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 565EE8; VRAM 802CDE78. */
InteractionHandler D_beach_802CDE78[8] = {
    { 9, func_beach_802CB44C, 0.0f, NULL },
    { 13, func_beach_802CB44C, 0.0f, NULL },
    { 10, func_beach_802CB44C, 0.0f, NULL },
    { 26, func_beach_802CB44C, 0.0f, NULL },
    { 5, func_beach_802CB784, 0.0f, NULL },
    { 6, func_beach_802CB784, 0.0f, NULL },
    { 7, func_beach_802CB784, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 565F68; VRAM 802CDEF8. */
InteractionHandler D_beach_802CDEF8[10] = {
    { 35, func_beach_802CB874, 0.0f, NULL },
    { 14, func_beach_802CB594, 0.0f, NULL },
    { 9, func_beach_802CB44C, 0.0f, NULL },
    { 13, func_beach_802CB44C, 0.0f, NULL },
    { 10, func_beach_802CB44C, 0.0f, NULL },
    { 26, func_beach_802CB44C, 0.0f, NULL },
    { 5, func_beach_802CB784, 0.0f, NULL },
    { 6, func_beach_802CB784, 0.0f, NULL },
    { 7, func_beach_802CB784, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 566008; VRAM 802CDF98. */
InteractionHandler D_beach_802CDF98[4] = {
    { 9, func_beach_802CB9E0, 0.0f, NULL },
    { 10, func_beach_802CB9E0, 0.0f, NULL },
    { 13, func_beach_802CB9E0, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 566048; VRAM 802CDFD8. */
InteractionHandler D_beach_802CDFD8[4] = {
    { 9, func_beach_802CBC4C, 0.0f, NULL },
    { 10, func_beach_802CBC4C, 0.0f, NULL },
    { 13, func_beach_802CBC4C, 0.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

/* ROM 566088; VRAM 802CE018. */
Vec3f D_beach_802CE018 = { 0.0f, 0.0f, 0.0f };

/* ROM 566094; VRAM 802CE024. */
PokemonAnimationSetup D_beach_802CE024 = { &D_beach_802CDB5C, func_beach_802CACD4, 0, { 0, 0, 0 }, NULL, NULL };

/* ROM 5660A8; VRAM 802CE038. */
PokemonInitData D_beach_802CE038 = { pikachu_model, pikachu_materials, renderPokemonModelTypeJFogged, &D_beach_802CE024, { 2.0f, 2.0f, 2.0f }, { 0.0f, 76.0f, 0.0f }, 22.0f, 37, 0, 0, 0, { 0, 0, 0 } };

/* Original zero-filled inter-record alignment/storage (4 bytes). */
char D_802CE06C_5660DC_padding[4] = "";

/* ROM 5660E0; VRAM 802CE070. */
AnimationHeader D_beach_802CE070 = { 0.600000024f, 112.0f, D_80139CD0_C6160, D_8013ACA0_C7130, NULL };

/* ROM 5660F4; VRAM 802CE084. */
InteractionHandler D_802CE084_5660F4[1] = {
    { 58, NULL, 0.0f, NULL },
};

/* ROM 566104; VRAM 802CE094. */
PokemonAnimationSetup D_beach_802CE094 = { &D_beach_802CE070, func_beach_802CBCE0, 0, { 0, 0, 0 }, NULL, NULL };

/* ROM 566118; VRAM 802CE0A8. */
PokemonInitData D_beach_802CE0A8 = { D_80139A40_C5ED0, D_801397C0_C5C50, renderModelTypeDFogged, &D_beach_802CE094, { 3.0f, 3.0f, 3.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f, 0, 0, 0, 0, { 0, 0, 0 } };

/* ROM 56614C; VRAM 802CE0DC. */
PokemonDef D_beach_802CE0DC = { 1006, (pokemonInit) func_beach_802CBDA0, pokemonChangeBlock, pokemonRemoveOne };

/* Original zero-filled trailing alignment/storage (4 bytes). */
char D_802CE0EC_56615C_padding[4] = "";
