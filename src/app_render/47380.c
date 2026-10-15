#include "common_structs.h"
#include "app_render.h"

#include "beach/beach.h"
#if !defined(M2CTX) && !defined(PERMUTER)
#include "ld_addrs.h"
#include "string.h"
#endif
#include "world/world.h"
#include "effect.h"

// .bss
static s32 padding[2];
PhotoData D_800B0598[60]; // Size: 0xD980 - All photos taken in a level
PhotoData* D_800BDF18;
u8 D_800BDF1C;
u8 D_800BDF1D;
u8 D_800BDF1E;
s32 D_800BDF20[3];
ucolor D_800BDF2C;

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

extern AnimCmd* D_800EAFB0;
extern AnimCmd** D_800EB0C0;
extern UnkEC64Arg3 D_800EB430;
extern Texture** D_800EB510;
extern AnimCmd* D_8017A710;
extern AnimCmd* D_80186E20;
extern AnimCmd* D_80188CB0;
void func_800A1680(GObj*);
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
extern AnimCmd* D_80117C40_95060[];
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
extern AnimCmd* D_8012C9E0_4DEDB0[];
extern AnimCmd* D_8012D700_4DFAD0[];
extern AnimCmd* D_8012EFF0_4E13C0[];
extern AnimCmd* D_8012FB60_4E1F30[];
extern AnimCmd* D_80131D30_4E4100[];
extern AnimCmd* D_80133040_4E5410[];
extern AnimCmd* D_801358A0_4E7C70[];
extern AnimCmd* D_801368F0_4E8CC0[];
extern UnkEC64Arg3 D_80136AC0_C2F50[];
extern AnimCmd** D_801394D0_4EB8A0[];
extern AnimCmd** D_801395A0_4EB970[];
extern AnimCmd** D_80139690_4EBA60[];
extern AnimCmd** D_80139770_4EBB40[];
extern Texture** D_801397C0_C5C50[];
extern AnimCmd** D_80139840_4EBC10[];
extern AnimCmd** D_80139900_4EBCD0[];
extern AnimCmd** D_80139A00_4EBDD0[];
extern UnkEC64Arg3 D_80139A40_C5ED0[];
extern AnimCmd** D_80139B00_4EBED0[];
extern AnimCmd* D_80139CD0_C6160[];
extern AnimCmd** D_8013ACA0_C7130[];
extern AnimCmd* D_801548D0_E0D60[];
extern AnimCmd* D_80156960_E2DF0[];
extern AnimCmd* D_80159E60_E62F0[];
extern AnimCmd* D_8015A4C0_1A0620[];
extern AnimCmd* D_8015AAE0_1A0C40[];
extern AnimCmd** D_8015AE40_1A0FA0[];
extern AnimCmd** D_8015AEF0_1A1050[];
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
extern Texture** arcanine_hd_materials[];
extern UnkEC64Arg3 arcanine_hd_model[];
extern AnimCmd** arcanine_matanim_eat[];
extern AnimCmd** arcanine_matanim_hit[];
extern AnimCmd** arcanine_matanim_idle[];
extern AnimCmd** arcanine_matanim_jump[];
extern AnimCmd** arcanine_matanim_roar[];
extern AnimCmd** arcanine_matanim_run[];
extern AnimCmd** arcanine_matanim_shake_head[];
extern AnimCmd** arcanine_matanim_walk[];
extern AnimCmd* arcanine_modelanim_eat[];
extern AnimCmd* arcanine_modelanim_hit[];
extern AnimCmd* arcanine_modelanim_idle[];
extern AnimCmd* arcanine_modelanim_jump[];
extern AnimCmd* arcanine_modelanim_roar[];
extern AnimCmd* arcanine_modelanim_run[];
extern AnimCmd* arcanine_modelanim_shake_head[];
extern AnimCmd* arcanine_modelanim_walk[];
extern Texture** articuno_hd_materials[];
extern UnkEC64Arg3 articuno_hd_model[];
extern Texture** bulbasaur_hd_materials[];
extern UnkEC64Arg3 bulbasaur_hd_model[];
extern UnkEC64Arg3 butterfree_hd_model[];
extern Texture** chansey_hd_materials[];
extern UnkEC64Arg3 chansey_hd_model[];
extern Texture** charizard_hd_materials[];
extern UnkEC64Arg3 charizard_hd_model[];
extern AnimCmd** charizard_matanim_appear[];
extern AnimCmd** charizard_matanim_idle[];
extern AnimCmd** charizard_matanim_roar[];
extern AnimCmd** charizard_matanim_spew_fire[];
extern AnimCmd** charizard_matanim_spin[];
extern AnimCmd* charizard_modelanim_appear[];
extern AnimCmd* charizard_modelanim_idle[];
extern AnimCmd* charizard_modelanim_roar[];
extern AnimCmd* charizard_modelanim_spew_fire[];
extern AnimCmd* charizard_modelanim_spin[];
extern Texture** charmander_hd_materials[];
extern UnkEC64Arg3 charmander_hd_model[];
extern AnimCmd** charmander_matanim_fall[];
extern AnimCmd** charmander_matanim_hit[];
extern AnimCmd** charmander_matanim_howl[];
extern AnimCmd** charmander_matanim_idle[];
extern AnimCmd** charmander_matanim_jump[];
extern AnimCmd** charmander_matanim_lie[];
extern AnimCmd** charmander_matanim_roar[];
extern AnimCmd** charmander_matanim_run[];
extern AnimCmd** charmander_matanim_shake_hands[];
extern AnimCmd** charmander_matanim_walk[];
extern AnimCmd* charmander_modelanim_fall[];
extern AnimCmd* charmander_modelanim_hit[];
extern AnimCmd* charmander_modelanim_howl[];
extern AnimCmd* charmander_modelanim_idle[];
extern AnimCmd* charmander_modelanim_jump[];
extern AnimCmd* charmander_modelanim_lie[];
extern AnimCmd* charmander_modelanim_roar[];
extern AnimCmd* charmander_modelanim_run[];
extern AnimCmd* charmander_modelanim_shake_hands[];
extern AnimCmd* charmander_modelanim_walk[];
extern Texture** charmeleon_hd_materials[];
extern UnkEC64Arg3 charmeleon_hd_model[];
extern AnimCmd** charmeleon_matanim_fall[];
extern AnimCmd** charmeleon_matanim_get_up[];
extern AnimCmd** charmeleon_matanim_hit[];
extern AnimCmd** charmeleon_matanim_idle[];
extern AnimCmd** charmeleon_matanim_lie[];
extern AnimCmd** charmeleon_matanim_look_around[];
extern AnimCmd** charmeleon_matanim_roar[];
extern AnimCmd** charmeleon_matanim_run[];
extern AnimCmd** charmeleon_matanim_walk[];
extern AnimCmd* charmeleon_modelanim_fall[];
extern AnimCmd* charmeleon_modelanim_get_up[];
extern AnimCmd* charmeleon_modelanim_hit[];
extern AnimCmd* charmeleon_modelanim_idle[];
extern AnimCmd* charmeleon_modelanim_lie[];
extern AnimCmd* charmeleon_modelanim_look_around[];
extern AnimCmd* charmeleon_modelanim_roar[];
extern AnimCmd* charmeleon_modelanim_run[];
extern AnimCmd* charmeleon_modelanim_walk[];
extern UnkEC64Arg3 cloyster_hd_model[];
extern Texture** diglett_hd_materials[];
extern UnkEC64Arg3 diglett_hd_model[];
extern AnimCmd** diglett_matanim_look_around[];
extern AnimCmd** diglett_matanim_rise[];
extern AnimCmd** diglett_matanim_unburrow[];
extern AnimCmd* diglett_modelanim_burrow[];
extern AnimCmd* diglett_modelanim_look_around[];
extern AnimCmd* diglett_modelanim_rise[];
extern AnimCmd* diglett_modelanim_turn[];
extern AnimCmd* diglett_modelanim_unburrow[];
extern UnkEC64Arg3 ditto_hd_model[];
extern Texture** doduo_hd_materials[];
extern UnkEC64Arg3 doduo_hd_model[];
extern UnkEC64Arg3 dragonite_hd_model[];
extern Texture** dratini_hd_materials[];
extern UnkEC64Arg3 dratini_hd_model[];
extern UnkEC64Arg3 dugtrio_hd_model[];
extern AnimCmd* dugtrio_modelanim_burrow[];
extern AnimCmd* dugtrio_modelanim_look_around[];
extern AnimCmd* dugtrio_modelanim_rise[];
extern AnimCmd* dugtrio_modelanim_turn[];
extern AnimCmd* dugtrio_modelanim_unburrow[];
extern Texture** eevee_hd_materials[];
extern UnkEC64Arg3 eevee_hd_model[];
extern Texture** electabuzz_hd_materials[];
extern UnkEC64Arg3 electabuzz_hd_model[];
extern Texture** electrode_hd_materials[];
extern UnkEC64Arg3 electrode_hd_model[];
extern AnimCmd** electrode_matanim_dead[];
extern AnimCmd** electrode_matanim_explode[];
extern AnimCmd* electrode_modelanim_dead[];
extern AnimCmd* electrode_modelanim_explode[];
extern AnimCmd* electrode_modelanim_idle[];
extern AnimCmd* electrode_modelanim_roll[];
extern AnimCmd** evolution_controller_matanim[];
extern Texture** evolution_controller_materials[];
extern UnkEC64Arg3 evolution_controller_model[];
extern AnimCmd* evolution_controller_modelanim[];
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
extern Texture** geodude_hd_materials[];
extern UnkEC64Arg3 geodude_hd_model[];
extern Texture** goldeen_hd_materials[];
extern UnkEC64Arg3 goldeen_hd_model[];
extern Texture** graveler_hd_materials[];
extern UnkEC64Arg3 graveler_hd_model[];
extern Texture** grimer_hd_materials[];
extern UnkEC64Arg3 grimer_hd_model[];
extern Texture** growlithe_hd_materials[];
extern UnkEC64Arg3 growlithe_hd_model[];
extern AnimCmd** growlithe_matanim_eat[];
extern AnimCmd** growlithe_matanim_hit[];
extern AnimCmd** growlithe_matanim_idle[];
extern AnimCmd** growlithe_matanim_jump[];
extern AnimCmd** growlithe_matanim_roar[];
extern AnimCmd** growlithe_matanim_run[];
extern AnimCmd** growlithe_matanim_shake_head[];
extern AnimCmd** growlithe_matanim_walk[];
extern AnimCmd* growlithe_modelanim_eat[];
extern AnimCmd* growlithe_modelanim_hit[];
extern AnimCmd* growlithe_modelanim_idle[];
extern AnimCmd* growlithe_modelanim_jump[];
extern AnimCmd* growlithe_modelanim_roar[];
extern AnimCmd* growlithe_modelanim_run[];
extern AnimCmd* growlithe_modelanim_shake_head[];
extern AnimCmd* growlithe_modelanim_walk[];
extern AnimCmd** growlithe_spawner_matanim[];
extern Texture** growlithe_spawner_materials[];
extern UnkEC64Arg3 growlithe_spawner_model[];
extern AnimCmd* growlithe_spawner_modelanim[];
extern Texture** gyarados_hd_materials[];
extern UnkEC64Arg3 gyarados_hd_model[];
extern UnkEC64Arg3 haunter_hd_model[];
extern Texture** jigglypuff_hd_materials[];
extern UnkEC64Arg3 jigglypuff_hd_model[];
extern Texture** jynx_hd_materials[];
extern UnkEC64Arg3 jynx_hd_model[];
extern Texture** kakuna_hd_materials[];
extern UnkEC64Arg3 kakuna_hd_model[];
extern Texture** kangaskhan_hd_materials[];
extern UnkEC64Arg3 kangaskhan_hd_model[];
extern Texture** koffing_hd_materials[];
extern UnkEC64Arg3 koffing_hd_model[];
extern AnimCmd** koffing_smoke_matanim_hide[];
extern AnimCmd** koffing_smoke_matanim_reveal[];
extern AnimCmd** koffing_smoke_matanim_show[];
extern Texture** koffing_smoke_materials[];
extern UnkEC64Arg3 koffing_smoke_model[];
extern AnimCmd* koffing_smoke_modelanim_hide[];
extern AnimCmd* koffing_smoke_modelanim_reveal[];
extern AnimCmd* koffing_smoke_modelanim_show[];
extern Texture** lapras_hd_materials[];
extern UnkEC64Arg3 lapras_hd_model[];
extern AnimCmd** lava_splash_matanim[];
extern Texture** lava_splash_materials[];
extern UnkEC64Arg3 lava_splash_model[];
extern AnimCmd* lava_splash_modelanim[];
extern UnkEC64Arg3 magikarp_hd_model[];
extern Texture** magmar_hd_materials[];
extern UnkEC64Arg3 magmar_hd_model[];
extern AnimCmd** magmar_matanim_eat[];
extern AnimCmd** magmar_matanim_get_up[];
extern AnimCmd** magmar_matanim_hit[];
extern AnimCmd** magmar_matanim_idle[];
extern AnimCmd** magmar_matanim_look_around[];
extern AnimCmd** magmar_matanim_run[];
extern AnimCmd** magmar_matanim_spew_fire[];
extern AnimCmd** magmar_matanim_walk[];
extern AnimCmd* magmar_modelanim_eat[];
extern AnimCmd* magmar_modelanim_fall[];
extern AnimCmd* magmar_modelanim_get_up[];
extern AnimCmd* magmar_modelanim_hit[];
extern AnimCmd* magmar_modelanim_idle[];
extern AnimCmd* magmar_modelanim_lie[];
extern AnimCmd* magmar_modelanim_look_around[];
extern AnimCmd* magmar_modelanim_run[];
extern AnimCmd* magmar_modelanim_spew_fire[];
extern AnimCmd* magmar_modelanim_walk[];
extern Texture** magnemite_hd_materials[];
extern UnkEC64Arg3 magnemite_hd_model[];
extern AnimCmd** magnemite_matanim_pulse[];
extern AnimCmd* magnemite_modelanim_hit[];
extern AnimCmd* magnemite_modelanim_idle[];
extern AnimCmd* magnemite_modelanim_move[];
extern AnimCmd* magnemite_modelanim_pulse[];
extern AnimCmd* magnemite_modelanim_react[];
extern AnimCmd* magnemite_modelanim_run[];
extern UnkEC64Arg3 magneton_hd_model[];
extern AnimCmd* magneton_modelanim[];
extern Texture** mankey_hd_materials[];
extern UnkEC64Arg3 mankey_hd_model[];
extern Texture** meowth_hd_materials[];
extern UnkEC64Arg3 meowth_hd_model[];
extern Texture** metapod_hd_materials[];
extern UnkEC64Arg3 metapod_hd_model[];
extern Texture** mew_hd_materials[];
extern UnkEC64Arg3 mew_hd_model[];
extern UnkEC64Arg3 moltres_egg_model[];
extern AnimCmd* moltres_egg_modelanim_drown[];
extern AnimCmd* moltres_egg_modelanim_idle[];
extern Texture** moltres_hd_materials[];
extern UnkEC64Arg3 moltres_hd_model[];
extern AnimCmd** moltres_matanim_appear[];
extern AnimCmd** moltres_matanim_fly[];
extern AnimCmd** moltres_matanim_fly2[];
extern AnimCmd** moltres_matanim_fly_away[];
extern AnimCmd** moltres_matanim_shake_off[];
extern AnimCmd* moltres_modelanim_appear[];
extern AnimCmd* moltres_modelanim_fly[];
extern AnimCmd* moltres_modelanim_fly2[];
extern AnimCmd* moltres_modelanim_fly_away[];
extern AnimCmd* moltres_modelanim_shake_off[];
extern Texture** muk_hd_materials[];
extern UnkEC64Arg3 muk_hd_model[];
extern Texture** pidgey_hd_materials[];
extern UnkEC64Arg3 pidgey_hd_model[];
extern Texture** pikachu_hd_materials[];
extern UnkEC64Arg3 pikachu_hd_model[];
extern UnkEC64Arg3 poliwag_hd_model[];
extern Texture** porygon_hd_materials[];
extern UnkEC64Arg3 porygon_hd_model[];
extern UnkEC64Arg3 psyduck_hd_model[];
extern Texture** rapidash_hd_materials[];
extern UnkEC64Arg3 rapidash_hd_model[];
extern AnimCmd** rapidash_matanim_idle[];
extern AnimCmd** rapidash_matanim_kick[];
extern AnimCmd** rapidash_matanim_rear[];
extern AnimCmd** rapidash_matanim_run[];
extern AnimCmd** rapidash_matanim_shake_head[];
extern AnimCmd** rapidash_matanim_walk[];
extern AnimCmd* rapidash_modelanim_idle[];
extern AnimCmd* rapidash_modelanim_kick[];
extern AnimCmd* rapidash_modelanim_rear[];
extern AnimCmd* rapidash_modelanim_run[];
extern AnimCmd* rapidash_modelanim_shake_head[];
extern AnimCmd* rapidash_modelanim_walk[];
extern Texture** sandshrew_hd_materials[];
extern UnkEC64Arg3 sandshrew_hd_model[];
extern Texture** sandslash_hd_materials[];
extern UnkEC64Arg3 sandslash_hd_model[];
extern UnkEC64Arg3 scyther_hd_model[];
extern Texture** shellder2_hd_materials[];
extern UnkEC64Arg3 shellder2_hd_model[];
extern UnkEC64Arg3 shellder_hd_model[];
extern Texture** slowbro_hd_materials[];
extern UnkEC64Arg3 slowbro_hd_model[];
extern UnkEC64Arg3 slowpoke_hd_model[];
extern AnimCmd** smoke_puff_matanim[];
extern Texture** smoke_puff_materials[];
extern UnkEC64Arg3 smoke_puff_model[];
extern AnimCmd* smoke_puff_modelanim[];
extern Texture** snorlax_hd_materials[];
extern UnkEC64Arg3 snorlax_hd_model[];
extern Texture** squirtle_hd_materials[];
extern UnkEC64Arg3 squirtle_hd_model[];
extern Texture** starmie_hd_materials[];
extern UnkEC64Arg3 starmie_hd_model[];
extern Texture** staryu_hd_materials[];
extern UnkEC64Arg3 staryu_hd_model[];
extern Texture** victreebel_hd_materials[];
extern UnkEC64Arg3 victreebel_hd_model[];
extern Texture** vileplume_hd_materials[];
extern UnkEC64Arg3 vileplume_hd_model[];
extern AnimCmd** volcano_smoke_matanim[];
extern Texture** volcano_smoke_materials[];
extern UnkEC64Arg3 volcano_smoke_model[];
extern AnimCmd* volcano_smoke_modelanim[];
extern Texture** vulpix_hd_materials[];
extern UnkEC64Arg3 vulpix_hd_model[];
extern AnimCmd** vulpix_matanim_eat[];
extern AnimCmd** vulpix_matanim_fall[];
extern AnimCmd** vulpix_matanim_get_up[];
extern AnimCmd** vulpix_matanim_hit[];
extern AnimCmd** vulpix_matanim_idle[];
extern AnimCmd** vulpix_matanim_lie[];
extern AnimCmd* vulpix_modelanim_eat[];
extern AnimCmd* vulpix_modelanim_fall[];
extern AnimCmd* vulpix_modelanim_get_up[];
extern AnimCmd* vulpix_modelanim_hit[];
extern AnimCmd* vulpix_modelanim_idle[];
extern AnimCmd* vulpix_modelanim_lie[];
extern AnimCmd* vulpix_modelanim_run[];
extern AnimCmd* vulpix_modelanim_walk[];
extern Texture** weepinbell_hd_materials[];
extern UnkEC64Arg3 weepinbell_hd_model[];
extern Texture** zapdos_hd_materials[];
extern UnkEC64Arg3 zapdos_hd_model[];
extern UnkEC64Arg3 zubat_hd_model[];

// .data
s32 gPhotoCount = 0;

u32 D_800AC0E4_57A94[] = {
    0x00000000, 0x00000000, 0x00000000,
};

s32 D_800AC0F0 = -1; // level id?
MovementState D_800AC0F4 = { 0.0f, 0.5f, NULL, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f, 0.0f };

Unkfunc_8009BDDCSub D_800AC120[] = {
    { 0.0f, (AnimCmd**) 0x80121410, (AnimCmd***) 0x80129980 },
    { 0.0f, (AnimCmd**) 0x80123320, (AnimCmd***) 0x80129AE0 },
    { 0.0f, (AnimCmd**) 0x80124C20, (AnimCmd***) 0x80129C10 },
    { 0.0f, (AnimCmd**) 0x8011F9D0, (AnimCmd***) 0x80129750 },
    { 0.0f, (AnimCmd**) 0x80120850, NULL },
    { 0.0f, (AnimCmd**) 0x80125F00, (AnimCmd***) 0x80129DF0 },
    { 96.0f, (AnimCmd**) 0x80126680, (AnimCmd***) 0x80129F00 },
    { 97.0f, (AnimCmd**) 0x80121A50, (AnimCmd***) 0x80129A10 },
    { 98.0f, (AnimCmd**) 0x80125130, (AnimCmd***) 0x80129CC0 },
    { 99.0f, (AnimCmd**) 0x801283C0, (AnimCmd***) 0x80129FF0 },
    { 0.0f, (AnimCmd**) 0x80120DD0, (AnimCmd***) 0x80129910 },
    { 0.0f, (AnimCmd**) 0x80121F30, (AnimCmd***) 0x80129A80 },
    { 0.0f, (AnimCmd**) 0x80124710, (AnimCmd***) 0x80129BA0 },
    { 0.0f, (AnimCmd**) 0x8011F0D0, (AnimCmd***) 0x801296E0 },
    { 0.0f, (AnimCmd**) 0x801202D0, (AnimCmd***) 0x80129800 },
    { 0.0f, (AnimCmd**) 0x80125B80, (AnimCmd***) 0x80129D80 },
    { 0.0f, (AnimCmd**) 0x80127090, (AnimCmd***) 0x80129F80 },
    { -100.0f, (AnimCmd**) 0x80126310, (AnimCmd***) 0x80129EA0 },
};

Unkfunc_8009BDDCSub D_800AC1F8[] = {
    { 0.0f, charmander_modelanim_idle, charmander_matanim_idle },
    { 0.0f, charmander_modelanim_howl, charmander_matanim_howl },
    { 0.0f, charmander_modelanim_walk, charmander_matanim_walk },
    { 0.0f, charmander_modelanim_run, charmander_matanim_run },
    { 0.0f, charmander_modelanim_shake_hands, charmander_matanim_shake_hands },
    { 103.0f, charmander_modelanim_fall, charmander_matanim_fall },
    { 104.0f, charmander_modelanim_lie, charmander_matanim_lie },
    { 105.0f, charmander_modelanim_hit, charmander_matanim_hit },
    { 106.0f, charmander_modelanim_jump, charmander_matanim_jump },
    { 0.0f, charmander_modelanim_roar, charmander_matanim_roar },
};

Unkfunc_8009BDDCSub D_800AC270[] = {
    { 0.0f, charmeleon_modelanim_idle, charmeleon_matanim_idle },
    { 115.0f, charmeleon_modelanim_roar, charmeleon_matanim_roar },
    { 0.0f, charmeleon_modelanim_look_around, charmeleon_matanim_look_around },
    { 0.0f, charmeleon_modelanim_walk, charmeleon_matanim_walk },
    { 0.0f, charmeleon_modelanim_run, charmeleon_matanim_run },
    { 0.0f, charmeleon_modelanim_hit, charmeleon_matanim_hit },
    { 112.0f, charmeleon_modelanim_fall, charmeleon_matanim_fall },
    { 113.0f, charmeleon_modelanim_lie, charmeleon_matanim_lie },
    { 114.0f, charmeleon_modelanim_get_up, charmeleon_matanim_get_up },
};

Unkfunc_8009BDDCSub D_800AC2DC[] = {
    { 0.0f, charizard_modelanim_appear, charizard_matanim_appear },
    { 0.0f, charizard_modelanim_idle, charizard_matanim_idle },
    { 0.0f, charizard_modelanim_roar, charizard_matanim_roar },
    { 101.0f, charizard_modelanim_spin, charizard_matanim_spin },
    { 102.0f, charizard_modelanim_spew_fire, charizard_matanim_spew_fire },
};

Unkfunc_8009BDDCSub D_800AC318[] = {
    { 0.0f, (AnimCmd**) 0x801803B0, (AnimCmd***) 0x801865D0 },
    { 0.0f, (AnimCmd**) 0x80182400, (AnimCmd***) 0x801867B0 },
    { 0.0f, (AnimCmd**) 0x80183180, (AnimCmd***) 0x80186830 },
    { 0.0f, (AnimCmd**) 0x8017E6C0, (AnimCmd***) 0x80186440 },
    { 0.0f, (AnimCmd**) 0x8017EB60, NULL },
    { 0.0f, (AnimCmd**) 0x80184470, (AnimCmd***) 0x80186960 },
    { 74.0f, (AnimCmd**) 0x80185B30, (AnimCmd***) 0x80186A80 },
    { 75.0f, (AnimCmd**) 0x80181510, NULL },
    { 76.0f, (AnimCmd**) 0x80183AC0, (AnimCmd***) 0x801868C0 },
    { 80.0f, (AnimCmd**) 0x8017EFF0, (AnimCmd***) 0x801864B0 },
    { 0.0f, (AnimCmd**) 0x80185230, (AnimCmd***) 0x801869E0 },
    { 77.0f, (AnimCmd**) 0x801818B0, (AnimCmd***) 0x801866D0 },
    { 78.0f, (AnimCmd**) 0x801821A0, NULL },
    { 79.0f, (AnimCmd**) 0x8017F710, (AnimCmd***) 0x80186540 },
};

Unkfunc_8009BDDCSub D_800AC3C0[] = {
    { 0.0f, (AnimCmd**) 0x801854F0, (AnimCmd***) 0x801858A0 },
    { 0.0f, (AnimCmd**) 0x80184E00, (AnimCmd***) 0x80185740 },
    { 0.0f, (AnimCmd**) 0x80185290, (AnimCmd***) 0x801857F0 },
};

Unkfunc_8009BDDCSub D_800AC3E4[] = {
    { 0.0f, D_801548D0_E0D60, NULL },
    { 0.0f, D_80156960_E2DF0, NULL },
};

Unkfunc_8009BDDCSub D_800AC3FC[] = {
    { 0.0f, D_8015AAE0_1A0C40, D_8015AEF0_1A1050 },
    { 0.0f, D_8015A4C0_1A0620, D_8015AE40_1A0FA0 },
};

Unkfunc_8009BDDCSub D_800AC414[] = {
    { 0.0f, D_801A66D0_132B60, NULL },
    { 0.0f, D_801A08C0_12CD50, D_801A8CC0_135150 },
    { 1.0f, D_801A2280_12E710, D_801A8D50_1351E0 },
    { 0.0f, D_801A4A80_130F10, D_801A8DF0_135280 },
};

Unkfunc_8009BDDCSub D_800AC444[] = {
    { 0.0f, D_80112F20_90340, D_8011A2B0_976D0 },
    { 0.0f, D_80113740_90B60, D_8011A370_97790 },
    { 134.0f, D_8010E190_8B5B0, D_80119A00_96E20 },
    { 0.0f, D_801092F0_86710, D_801196C0_96AE0 },
    { 0.0f, D_8010D410_8A830, D_80119960_96D80 },
    { 0.0f, D_801161D0_935F0, D_8011ADE0_98200 },
    { 135.0f, D_80111AA0_8EEC0, D_8011A1B0_975D0 },
    { 0.0f, D_8010CE10_8A230, D_801198B0_96CD0 },
    { 0.0f, D_8010C370_89790, D_80119800_96C20 },
    { 0.0f, D_801189D0_95DF0, D_8011AF80_983A0 },
    { 0.0f, D_80109C10_87030, D_80119760_96B80 },
    { 0.0f, D_80117C40_95060, D_8011AEE0_98300 },
    { 145.0f, D_80114610_91A30, D_8011A440_97860 },
};

Unkfunc_8009BDDCSub D_800AC4E0[] = {
    { 0.0f, (AnimCmd**) 0x80164440, (AnimCmd***) 0x80169A60 },
    { 0.0f, (AnimCmd**) 0x801638E0, NULL },
    { 0.0f, (AnimCmd**) 0x80163E80, NULL },
    { 0.0f, (AnimCmd**) 0x801672A0, (AnimCmd***) 0x80169C20 },
    { 59.0f, (AnimCmd**) 0x80167E40, (AnimCmd***) 0x80169C90 },
    { 60.0f, (AnimCmd**) 0x80164BB0, (AnimCmd***) 0x80169B00 },
    { 61.0f, (AnimCmd**) 0x80166600, (AnimCmd***) 0x80169BC0 },
    { 64.0f, (AnimCmd**) 0x801690E0, NULL },
    { 62.0f, (AnimCmd**) 0x80168870, NULL },
    { 63.0f, (AnimCmd**) 0x80165100, NULL },
};

Unkfunc_8009BDDCSub D_800AC558[] = {
    { 0.0f, (AnimCmd**) 0x8016C3F0, (AnimCmd***) 0x80171560 },
    { 0.0f, (AnimCmd**) 0x8016AF90, (AnimCmd***) 0x80171420 },
    { 0.0f, (AnimCmd**) 0x8016BB80, (AnimCmd***) 0x801714D0 },
    { 0.0f, (AnimCmd**) 0x8016DF30, (AnimCmd***) 0x80171710 },
    { 65.0f, (AnimCmd**) 0x8016EBE0, (AnimCmd***) 0x801717D0 },
    { 66.0f, (AnimCmd**) 0x8016C960, (AnimCmd***) 0x801715F0 },
    { 67.0f, (AnimCmd**) 0x8016D3F0, (AnimCmd***) 0x80171670 },
    { 70.0f, (AnimCmd**) 0x8016FC50, NULL },
    { 68.0f, (AnimCmd**) 0x8016F230, NULL },
    { 69.0f, (AnimCmd**) 0x8016CD10, NULL },
};

Unkfunc_8009BDDCSub D_800AC5D0[] = {
    { 0.0f, vulpix_modelanim_idle, vulpix_matanim_idle },
    { 0.0f, vulpix_modelanim_walk, NULL },
    { 0.0f, vulpix_modelanim_run, NULL },
    { 0.0f, vulpix_modelanim_hit, vulpix_matanim_hit },
    { 116.0f, vulpix_modelanim_fall, vulpix_matanim_fall },
    { 117.0f, vulpix_modelanim_lie, vulpix_matanim_lie },
    { 118.0f, vulpix_modelanim_get_up, vulpix_matanim_get_up },
    { 119.0f, vulpix_modelanim_eat, vulpix_matanim_eat },
};

Unkfunc_8009BDDCSub D_800AC630[] = {
    { 0.0f, (AnimCmd**) 0x8018AD70, (AnimCmd***) 0x80192E30 },
    { 0.0f, (AnimCmd**) 0x80190AA0, (AnimCmd***) 0x80193780 },
    { 0.0f, (AnimCmd**) 0x8018DA20, (AnimCmd***) 0x80193200 },
    { 24.0f, (AnimCmd**) 0x80189BC0, (AnimCmd***) 0x80192CF0 },
    { 25.0f, (AnimCmd**) 0x8018EBD0, (AnimCmd***) 0x801933D0 },
    { 26.0f, (AnimCmd**) 0x8018F850, (AnimCmd***) 0x80193510 },
    { 0.0f, (AnimCmd**) 0x8018BF00, (AnimCmd***) 0x80192FF0 },
    { 0.0f, (AnimCmd**) 0x801921E0, (AnimCmd***) 0x801939E0 },
};

Unkfunc_8009BDDCSub D_800AC690[] = {
    { 0.0f, (AnimCmd**) 0x8011C2E0, NULL },
};

Unkfunc_8009BDDCSub D_800AC69C[] = {
    { -100.0f, (AnimCmd**) 0x8017EFB0, (AnimCmd***) 0x801819E0 },
    { 84.0f, (AnimCmd**) 0x80180CF0, NULL },
    { 85.0f, (AnimCmd**) 0x801802D0, (AnimCmd***) 0x80181C20 },
    { 0.0f, (AnimCmd**) 0x8017DCF0, NULL },
    { 86.0f, (AnimCmd**) 0x8017FB40, (AnimCmd***) 0x80181B60 },
    { 0.0f, (AnimCmd**) 0x8017F490, (AnimCmd***) 0x80181AA0 },
};

Unkfunc_8009BDDCSub D_800AC6E4[] = {
    { 0.0f, diglett_modelanim_look_around, diglett_matanim_look_around },
    { 35.0f, diglett_modelanim_turn, NULL },
    { -100.0f, diglett_modelanim_unburrow, diglett_matanim_unburrow },
    { 160.0f, diglett_modelanim_rise, diglett_matanim_rise },
    { -100.0f, diglett_modelanim_burrow, NULL },
};

Unkfunc_8009BDDCSub D_800AC720[] = {
    { 0.0f, dugtrio_modelanim_look_around, NULL },
    { 37.0f, dugtrio_modelanim_turn, NULL },
    { -100.0f, dugtrio_modelanim_unburrow, NULL },
    { 158.0f, dugtrio_modelanim_rise, NULL },
    { -100.0f, dugtrio_modelanim_burrow, NULL },
};

Unkfunc_8009BDDCSub D_800AC75C[] = {
    { 0.0f, D_801949A0_120E30, D_8019DC60_12A0F0 },
    { 0.0f, D_801906A0_11CB30, D_8019D890_129D20 },
    { 0.0f, D_80191AE0_11DF70, D_8019D9E0_129E70 },
    { 0.0f, D_80192C20_11F0B0, D_8019DAF0_129F80 },
    { 0.0f, D_80198BF0_125080, D_8019E110_12A5A0 },
    { 128.0f, D_8019C270_128700, D_8019E3F0_12A880 },
    { 129.0f, D_80195A70_121F00, D_8019DD80_12A210 },
    { 130.0f, D_80197A00_123E90, D_8019DFF0_12A480 },
    { 0.0f, D_8019A950_126DE0, D_8019E260_12A6F0 },
    { 131.0f, D_80196070_122500, D_8019DE50_12A2E0 },
};

Unkfunc_8009BDDCSub D_800AC7D4[] = {
    { 90.0f, (AnimCmd**) 0x80163260, NULL },
    { 91.0f, (AnimCmd**) 0x80163C30, NULL },
    { 92.0f, (AnimCmd**) 0x80164410, NULL },
    { 0.0f, (AnimCmd**) 0x801649D0, NULL },
    { 0.0f, (AnimCmd**) 0x80162880, NULL },
    { 93.0f, (AnimCmd**) 0x80166A90, NULL },
    { 94.0f, (AnimCmd**) 0x801653D0, NULL },
    { 95.0f, (AnimCmd**) 0x801664A0, NULL },
};

Unkfunc_8009BDDCSub D_800AC834[] = {
    { 0.0f, (AnimCmd**) 0x80156410, (AnimCmd***) 0x80159880 },
    { 0.0f, (AnimCmd**) 0x801529B0, (AnimCmd***) 0x80159660 },
    { 44.0f, (AnimCmd**) 0x80154C50, (AnimCmd***) 0x801597C0 },
    { 45.0f, (AnimCmd**) 0x80153490, (AnimCmd***) 0x80159700 },
    { 46.0f, (AnimCmd**) 0x80159220, (AnimCmd***) 0x80159940 },
};

Unkfunc_8009BDDCSub D_800AC870[] = {
    { 0.0f, growlithe_modelanim_idle, growlithe_matanim_idle },
    { 0.0f, growlithe_modelanim_roar, growlithe_matanim_roar },
    { 0.0f, growlithe_modelanim_walk, growlithe_matanim_walk },
    { 0.0f, growlithe_modelanim_run, growlithe_matanim_run },
    { 0.0f, growlithe_modelanim_hit, growlithe_matanim_hit },
    { 0.0f, growlithe_modelanim_eat, growlithe_matanim_eat },
    { 7.0f, growlithe_modelanim_shake_head, growlithe_matanim_shake_head },
    { 0.0f, growlithe_modelanim_jump, growlithe_matanim_jump },
};

Unkfunc_8009BDDCSub D_800AC8D0[] = {
    { 0.0f, arcanine_modelanim_idle, arcanine_matanim_idle },
    { 0.0f, arcanine_modelanim_roar, arcanine_matanim_roar },
    { 0.0f, arcanine_modelanim_walk, arcanine_matanim_walk },
    { 0.0f, arcanine_modelanim_run, arcanine_matanim_run },
    { 0.0f, arcanine_modelanim_hit, arcanine_matanim_hit },
    { 0.0f, arcanine_modelanim_eat, arcanine_matanim_eat },
    { 6.0f, arcanine_modelanim_shake_head, arcanine_matanim_shake_head },
    { 0.0f, arcanine_modelanim_jump, arcanine_matanim_jump },
};

Unkfunc_8009BDDCSub D_800AC930[] = {
    { 52.0f, (AnimCmd**) 0x8016A500, NULL },
    { 53.0f, (AnimCmd**) 0x8016B930, NULL },
    { 54.0f, (AnimCmd**) 0x8016C340, NULL },
    { 0.0f, (AnimCmd**) 0x8016DAC0, NULL },
    { 0.0f, (AnimCmd**) 0x8016D250, NULL },
    { 0.0f, (AnimCmd**) 0x801697D0, NULL },
    { 58.0f, (AnimCmd**) 0x8016FDB0, NULL },
    { 55.0f, (AnimCmd**) 0x8016F2A0, NULL },
    { 56.0f, (AnimCmd**) 0x8016E3F0, NULL },
    { 57.0f, (AnimCmd**) 0x8016E7A0, NULL },
};

Unkfunc_8009BDDCSub D_800AC9A8[] = {
    { 0.0f, (AnimCmd**) 0x801A8C10, NULL },
    { 0.0f, (AnimCmd**) 0x801AA220, (AnimCmd***) 0x801AE8C0 },
    { 0.0f, (AnimCmd**) 0x801A8250, NULL },
    { 0.0f, (AnimCmd**) 0x801ACBD0, (AnimCmd***) 0x801AE9A0 },
    { 0.0f, (AnimCmd**) 0x801ADA80, (AnimCmd***) 0x801AEB60 },
    { 0.0f, (AnimCmd**) 0x801A9A10, (AnimCmd***) 0x801AE730 },
    { 0.0f, (AnimCmd**) 0x801AB240, NULL },
};

Unkfunc_8009BDDCSub D_800AC9FC[] = {
    { 0.0f, (AnimCmd**) 0x801A2EF0, (AnimCmd***) 0x801A5250 },
    { 10.0f, (AnimCmd**) 0x801A47D0, (AnimCmd***) 0x801A54D0 },
    { 0.0f, (AnimCmd**) 0x801A39C0, (AnimCmd***) 0x801A5380 },
};

Unkfunc_8009BDDCSub D_800ACA20[] = {
    { 0.0f, (AnimCmd**) 0x80141F80, NULL },
    { 0.0f, (AnimCmd**) 0x80141060, (AnimCmd***) 0x80142610 },
    { 0.0f, (AnimCmd**) 0x80141C70, (AnimCmd***) 0x80142770 },
    { 0.0f, (AnimCmd**) 0x80141660, (AnimCmd***) 0x801426C0 },
    { 0.0f, (AnimCmd**) 0x80140CE0, (AnimCmd***) 0x80142560 },
    { 0.0f, (AnimCmd**) 0x80140720, NULL },
};

Unkfunc_8009BDDCSub D_800ACA68[] = {
    { 0.0f, (AnimCmd**) 0x80133AE0, NULL },
    { 41.0f, (AnimCmd**) 0x801329B0, NULL },
    { 42.0f, (AnimCmd**) 0x80133800, NULL },
    { 43.0f, (AnimCmd**) 0x80132DF0, (AnimCmd***) 0x801346F0 },
    { 0.0f, (AnimCmd**) 0x80131990, (AnimCmd***) 0x80134610 },
    { 0.0f, (AnimCmd**) 0x8012FFD0, (AnimCmd***) 0x80134570 },
    { 0.0f, (AnimCmd**) 0x80130A30, NULL },
    { 0.0f, (AnimCmd**) 0x80131240, NULL },
    { 0.0f, (AnimCmd**) 0x80132150, NULL },
};

Unkfunc_8009BDDCSub D_800ACAD4[] = {
    { 0.0f, rapidash_modelanim_idle, rapidash_matanim_idle },
    { 0.0f, rapidash_modelanim_walk, rapidash_matanim_walk },
    { 0.0f, rapidash_modelanim_run, rapidash_matanim_run },
    { 0.0f, rapidash_modelanim_shake_head, rapidash_matanim_shake_head },
    { 0.0f, rapidash_modelanim_kick, rapidash_matanim_kick },
    { 5.0f, rapidash_modelanim_rear, rapidash_matanim_rear },
};

Unkfunc_8009BDDCSub D_800ACB1C[] = {
    { 0.0f, (AnimCmd**) 0x80188E10, NULL },
    { 0.0f, (AnimCmd**) 0x80189A90, NULL },
    { 0.0f, (AnimCmd**) 0x80186880, NULL },
    { 0.0f, (AnimCmd**) 0x801870C0, NULL },
    { 0.0f, (AnimCmd**) 0x8018B6A0, NULL },
    { 89.0f, (AnimCmd**) 0x8018DF00, NULL },
    { 156.0f, (AnimCmd**) 0x80190FF0, NULL },
    { 0.0f, (AnimCmd**) 0x801893B0, NULL },
    { 0.0f, (AnimCmd**) 0x801878B0, (AnimCmd***) 0x80191C80 },
    { 157.0f, (AnimCmd**) 0x8018CB70, NULL },
};

Unkfunc_8009BDDCSub D_800ACB94[] = {
    { 0.0f, (AnimCmd**) 0x80197030, NULL },
    { 0.0f, (AnimCmd**) 0x801978E0, NULL },
    { 0.0f, (AnimCmd**) 0x801941C0, NULL },
    { 0.0f, (AnimCmd**) 0x80194F10, NULL },
    { 0.0f, (AnimCmd**) 0x801988E0, (AnimCmd***) 0x8019AD90 },
    { 11.0f, (AnimCmd**) 0x80199AC0, NULL },
    { 0.0f, (AnimCmd**) 0x80195B70, NULL },
};

Unkfunc_8009BDDCSub D_800ACBE8[] = {
    { 0.0f, magnemite_modelanim_move, NULL },
    { 0.0f, magnemite_modelanim_idle, NULL },
    { -100.0f, magnemite_modelanim_pulse, magnemite_matanim_pulse },
    { 0.0f, magnemite_modelanim_run, NULL },
    { 33.0f, magnemite_modelanim_hit, NULL },
    { 34.0f, magnemite_modelanim_react, NULL },
};

Unkfunc_8009BDDCSub D_800ACC30[] = {
    { 0.0f, magneton_modelanim, NULL },
};

Unkfunc_8009BDDCSub D_800ACC3C[] = {
    { 0.0f, D_80159E60_E62F0, NULL },
    { 123.0f, D_8015EBA0_EB030, NULL },
    { 124.0f, D_8015BC10_E80A0, D_801617D0_EDC60 },
    { 125.0f, D_8015CBC0_E9050, NULL },
    { 0.0f, D_8015FD10_EC1A0, NULL },
};

Unkfunc_8009BDDCSub D_800ACC78[] = {
    { 0.0f, (AnimCmd**) 0x801580F0, (AnimCmd***) 0x8015B8C0 },
    { 0.0f, (AnimCmd**) 0x801572A0, (AnimCmd***) 0x8015B4F0 },
    { 16.0f, (AnimCmd**) 0x8015A380, (AnimCmd***) 0x8015C410 },
    { 0.0f, (AnimCmd**) 0x80158C90, (AnimCmd***) 0x8015BC90 },
    { 0.0f, (AnimCmd**) 0x80159940, (AnimCmd***) 0x8015BFA0 },
};

Unkfunc_8009BDDCSub D_800ACCB4[] = {
    { 0.0f, (AnimCmd**) 0x8015EC20, (AnimCmd***) 0x80160EC0 },
    { 0.0f, (AnimCmd**) 0x8015E650, (AnimCmd***) 0x80160BA0 },
    { 15.0f, (AnimCmd**) 0x80160160, (AnimCmd***) 0x80161860 },
    { 0.0f, (AnimCmd**) 0x8015F820, (AnimCmd***) 0x80161540 },
    { 0.0f, (AnimCmd**) 0x8015F1D0, (AnimCmd***) 0x80161220 },
};

Unkfunc_8009BDDCSub D_800ACCF0[] = {
    { 0.0f, (AnimCmd**) 0x80182580, NULL },
};

Unkfunc_8009BDDCSub D_800ACCFC[] = {
    { 0.0f, (AnimCmd**) 0x80171780, NULL },
    { 0.0f, (AnimCmd**) 0x80171480, NULL },
};

Unkfunc_8009BDDCSub D_800ACD14[] = {
    { 0.0f, (AnimCmd**) 0x80177B50, NULL },
};

Unkfunc_8009BDDCSub D_800ACD20[] = {
    { 0.0f, electrode_modelanim_idle, NULL },
    { 28.0f, electrode_modelanim_explode, electrode_matanim_explode },
    { 0.0f, electrode_modelanim_dead, electrode_matanim_dead },
    { 27.0f, electrode_modelanim_roll, NULL },
};

Unkfunc_8009BDDCSub D_800ACD50[] = {
    { 0.0f, (AnimCmd**) 0x80166B20, (AnimCmd***) 0x8016E240 },
    { 0.0f, (AnimCmd**) 0x801676C0, (AnimCmd***) 0x8016E570 },
    { 0.0f, (AnimCmd**) 0x8016B2D0, (AnimCmd***) 0x8016F440 },
    { 155.0f, (AnimCmd**) 0x801680F0, (AnimCmd***) 0x8016E910 },
    { 0.0f, (AnimCmd**) 0x801657B0, (AnimCmd***) 0x8016DCF0 },
    { 0.0f, (AnimCmd**) 0x8016A380, (AnimCmd***) 0x8016EF90 },
};

Unkfunc_8009BDDCSub D_800ACD98[] = {
    { -100.0f, &D_80186E20, NULL },
    { 0.0f, D_80187230_1136C0, NULL },
    { -100.0f, D_80188ED0_115360, D_8018A4C0_116950 },
    { 0.0f, D_801866A0_112B30, D_8018A270_116700 },
    { 0.0f, D_80185010_1114A0, NULL },
    { 0.0f, D_80187BD0_114060, D_8018A370_116800 },
    { 0.0f, D_80185D90_112220, NULL },
    { 122.0f, D_801895E0_115A70, NULL },
    { 161.0f, D_80188260_1146F0, D_8018A410_1168A0 },
};

Unkfunc_8009BDDCSub D_800ACE04[] = {
    { 0.0f, D_80173C30_1000C0, D_80179760_105BF0 },
    { 0.0f, D_8016E200_FA690, D_80179560_1059F0 },
    { 0.0f, D_8016F5B0_FBA40, D_80179600_105A90 },
    { 126.0f, D_80170AD0_FCF60, D_801796A0_105B30 },
    { 0.0f, D_801765D0_102A60, D_801798B0_105D40 },
    { 0.0f, D_80177520_1039B0, D_80179940_105DD0 },
    { 127.0f, D_80175390_101820, D_80179810_105CA0 },
};

Unkfunc_8009BDDCSub D_800ACE58[] = {
    { 71.0f, (AnimCmd**) 0x80179C50, (AnimCmd***) 0x8017B800 },
    { 72.0f, (AnimCmd**) 0x8017A420, (AnimCmd***) 0x8017B8D0 },
    { 73.0f, (AnimCmd**) 0x8017AED0, (AnimCmd***) 0x8017B980 },
};

Unkfunc_8009BDDCSub D_800ACE7C[] = {
    { 0.0f, (AnimCmd**) 0x8013E410, NULL },
    { 0.0f, (AnimCmd**) 0x8013DD40, (AnimCmd***) 0x8013F550 },
    { 0.0f, (AnimCmd**) 0x8013EAE0, (AnimCmd***) 0x8013F5E0 },
};

Unkfunc_8009BDDCSub D_800ACEA0[] = {
    { 0.0f, (AnimCmd**) 0x80173E70, (AnimCmd***) 0x80174DD0 },
    { 0.0f, (AnimCmd**) 0x80173810, (AnimCmd***) 0x80174CE0 },
    { 0.0f, (AnimCmd**) 0x801744D0, (AnimCmd***) 0x80174E40 },
};

Unkfunc_8009BDDCSub D_800ACEC4[] = {
    { 0.0f, D_801AF4B0_13B940, NULL },
    { 0.0f, D_801AA9D0_136E60, NULL },
    { 2.0f, D_801ACF90_139420, NULL },
    { 0.0f, D_801AE790_13AC20, NULL },
    { 0.0f, D_801AC250_1386E0, NULL },
    { 0.0f, D_801AB610_137AA0, NULL },
};

Unkfunc_8009BDDCSub D_800ACF0C[] = {
    { 0.0f, (AnimCmd**) 0x8019E4D0, NULL },
    { 0.0f, (AnimCmd**) 0x8019D4A0, (AnimCmd***) 0x801A03C0 },
    { 0.0f, (AnimCmd**) 0x8019B160, (AnimCmd***) 0x801A02A0 },
    { 0.0f, (AnimCmd**) 0x8019EF80, NULL },
    { 0.0f, (AnimCmd**) 0x8019C070, (AnimCmd***) 0x801A0310 },
    { 17.0f, (AnimCmd**) 0x80199060, NULL },
};

Unkfunc_8009BDDCSub D_800ACF54[] = {
    { 0.0f, (AnimCmd**) 0x8016FCF0, NULL },
    { 0.0f, (AnimCmd**) 0x8016EAC0, NULL },
    { 0.0f, (AnimCmd**) 0x8016F350, NULL },
    { 0.0f, (AnimCmd**) 0x801742D0, (AnimCmd***) 0x80177A20 },
    { 154.0f, (AnimCmd**) 0x80175690, NULL },
    { 32.0f, (AnimCmd**) 0x80172FA0, (AnimCmd***) 0x80177890 },
    { 29.0f, (AnimCmd**) 0x80176800, (AnimCmd***) 0x80177AC0 },
    { 30.0f, (AnimCmd**) 0x80170740, (AnimCmd***) 0x80177710 },
    { 31.0f, (AnimCmd**) 0x80171520, (AnimCmd***) 0x80177790 },
};

Unkfunc_8009BDDCSub D_800ACFC0[] = {
    { 0.0f, magmar_modelanim_idle, magmar_matanim_idle },
    { 0.0f, magmar_modelanim_look_around, magmar_matanim_look_around },
    { 0.0f, magmar_modelanim_walk, magmar_matanim_walk },
    { 0.0f, magmar_modelanim_run, magmar_matanim_run },
    { 107.0f, magmar_modelanim_hit, magmar_matanim_hit },
    { 108.0f, magmar_modelanim_fall, NULL },
    { 109.0f, magmar_modelanim_lie, NULL },
    { 110.0f, magmar_modelanim_get_up, magmar_matanim_get_up },
    { 0.0f, magmar_modelanim_eat, magmar_matanim_eat },
    { 111.0f, magmar_modelanim_spew_fire, magmar_matanim_spew_fire },
};

Unkfunc_8009BDDCSub D_800AD038[] = {
    { 51.0f, D_800FDC70_7B090, NULL },
    { 48.0f, D_800FAE40_78260, NULL },
    { 49.0f, D_800FBF50_79370, NULL },
    { 50.0f, D_800FD080_7A4A0, NULL },
};

Unkfunc_8009BDDCSub D_800AD068[] = {
    { 20.0f, (AnimCmd**) 0x8013BEC0, NULL },
    { 21.0f, (AnimCmd**) 0x80139880, (AnimCmd***) 0x8013C6B0 },
    { 22.0f, (AnimCmd**) 0x8013A370, (AnimCmd***) 0x8013C7A0 },
    { 19.0f, (AnimCmd**) 0x80137D60, NULL },
    { 23.0f, (AnimCmd**) 0x8013B150, (AnimCmd***) 0x8013C830 },
};

Unkfunc_8009BDDCSub D_800AD0A4[] = {
    { 4.0f, D_80183D20_1101B0, D_80184400_110890 },
};

Unkfunc_8009BDDCSub D_800AD0B0[] = {
    { 0.0f, (AnimCmd**) 0x8017EE10, NULL },
    { 0.0f, (AnimCmd**) 0x8017D950, NULL },
    { 0.0f, (AnimCmd**) 0x8017E460, NULL },
    { 0.0f, (AnimCmd**) 0x80183C40, NULL },
    { 0.0f, (AnimCmd**) 0x80184C20, NULL },
    { 0.0f, (AnimCmd**) 0x80182410, NULL },
    { 0.0f, (AnimCmd**) 0x80182D00, NULL },
    { 14.0f, (AnimCmd**) 0x80186450, NULL },
    { 0.0f, (AnimCmd**) 0x80181570, NULL },
};

Unkfunc_8009BDDCSub D_800AD11C[] = {
    { 0.0f, D_80166A90_F2F20, D_8016B300_F7790 },
    { 0.0f, D_80165010_F14A0, D_8016B190_F7620 },
    { 0.0f, D_80165D90_F2220, D_8016B250_F76E0 },
    { 0.0f, D_80167D20_F41B0, D_8016B420_F78B0 },
    { 3.0f, D_80168D50_F51E0, D_8016B4F0_F7980 },
};

Unkfunc_8009BDDCSub D_800AD158[] = {
    { 0.0f, (AnimCmd**) 0x80174FC0, (AnimCmd***) 0x8017ADA0 },
    { 0.0f, (AnimCmd**) 0x80173140, (AnimCmd***) 0x8017A330 },
    { 0.0f, (AnimCmd**) 0x80173B00, (AnimCmd***) 0x8017A710 },
    { 0.0f, (AnimCmd**) 0x80176740, (AnimCmd***) 0x8017B110 },
    { 0.0f, (AnimCmd**) 0x801746F0, (AnimCmd***) 0x8017AAA0 },
    { 83.0f, (AnimCmd**) 0x801799E0, (AnimCmd***) 0x8017BD70 },
    { 0.0f, (AnimCmd**) 0x801779A0, (AnimCmd***) 0x8017B580 },
    { -100.0f, (AnimCmd**) 0x80174B00, (AnimCmd***) 0x8017ABC0 },
    { 0.0f, (AnimCmd**) 0x80172D00, (AnimCmd***) 0x8017A0B0 },
    { 0.0f, (AnimCmd**) 0x80173360, (AnimCmd***) 0x8017A470 },
    { 0.0f, (AnimCmd**) 0x80175220, (AnimCmd***) 0x8017AE90 },
    { 0.0f, (AnimCmd**) 0x80173ED0, (AnimCmd***) 0x8017A860 },
    { 81.0f, (AnimCmd**) 0x80178C40, (AnimCmd***) 0x8017BAF0 },
    { 0.0f, (AnimCmd**) 0x80178400, (AnimCmd***) 0x8017B8B0 },
    { 0.0f, (AnimCmd**) 0x801771D0, (AnimCmd***) 0x8017B250 },
    { -100.0f, (AnimCmd**) 0x80174D60, (AnimCmd***) 0x8017ACB0 },
    { 0.0f, (AnimCmd**) 0x80172F20, (AnimCmd***) 0x8017A1F0 },
    { 0.0f, (AnimCmd**) 0x80173730, (AnimCmd***) 0x8017A5C0 },
    { 0.0f, (AnimCmd**) 0x80175CB0, (AnimCmd***) 0x8017AFD0 },
    { 0.0f, (AnimCmd**) 0x801742E0, (AnimCmd***) 0x8017A980 },
    { 82.0f, (AnimCmd**) 0x80179310, (AnimCmd***) 0x8017BC30 },
    { 0.0f, (AnimCmd**) 0x80178820, (AnimCmd***) 0x8017B9D0 },
};

Unkfunc_8009BDDCSub D_800AD260[] = {
    { -100.0f, D_8017EBA0_10B030, D_80182230_10E6C0 },
    { -100.0f, D_8017E740_10ABD0, D_801821C0_10E650 },
    { -100.0f, D_8017F8B0_10BD40, D_80182310_10E7A0 },
    { 162.0f, D_8017FEF0_10C380, NULL },
    { 132.0f, D_8017F080_10B510, NULL },
    { 0.0f, D_80181880_10DD10, NULL },
    { 0.0f, D_80180910_10CDA0, D_801823C0_10E850 },
    { 133.0f, D_8017BB20_107FB0, NULL },
    { 163.0f, D_8017DA60_109EF0, D_801820B0_10E540 },
    { -100.0f, D_8017E2E0_10A770, D_80182150_10E5E0 },
};

Unkfunc_8009BDDCSub D_800AD2D8[] = {
    { 18.0f, (AnimCmd**) 0x801746E0, (AnimCmd***) 0x80178920 },
    { 0.0f, (AnimCmd**) 0x80172370, (AnimCmd***) 0x80178800 },
    { 0.0f, (AnimCmd**) 0x80172E00, (AnimCmd***) 0x80178890 },
};

Unkfunc_8009BDDCSub D_800AD2FC[] = {
    { 0.0f, (AnimCmd**) 0x80185E70, (AnimCmd***) 0x80186F30 },
    { 0.0f, (AnimCmd**) 0x80184920, (AnimCmd***) 0x80186EA0 },
    { 13.0f, (AnimCmd**) 0x80186530, (AnimCmd***) 0x80186FA0 },
    { 0.0f, (AnimCmd**) 0x80183EE0, (AnimCmd***) 0x80186E20 },
};

Unkfunc_8009BDDCSub D_800AD32C[] = {
    { 0.0f, moltres_modelanim_fly, moltres_matanim_fly },
    { 0.0f, moltres_modelanim_fly2, moltres_matanim_fly2 },
    { 100.0f, moltres_modelanim_shake_off, moltres_matanim_shake_off },
    { 0.0f, moltres_modelanim_appear, moltres_matanim_appear },
    { 0.0f, moltres_modelanim_fly_away, moltres_matanim_fly_away },
};

Unkfunc_8009BDDCSub D_800AD368[] = {
    { 38.0f, (AnimCmd**) 0x8015CED0, (AnimCmd***) 0x8015E720 },
    { 39.0f, (AnimCmd**) 0x8015DA00, NULL },
    { 40.0f, (AnimCmd**) 0x8015DCE0, NULL },
};

Unkfunc_8009BDDCSub D_800AD38C[] = {
    { 0.0f, (AnimCmd**) 0x8014B280, NULL },
    { 0.0f, (AnimCmd**) 0x8014ABC0, NULL },
    { 12.0f, (AnimCmd**) 0x801470F0, NULL },
    { 0.0f, (AnimCmd**) 0x801462C0, NULL },
    { 0.0f, (AnimCmd**) 0x801453E0, NULL },
};

Unkfunc_8009BDDCSub D_800AD3C8[] = {
    { -100.0f, D_8012EFF0_4E13C0, D_80139690_4EBA60 },
    { -100.0f, D_801368F0_4E8CC0, D_80139B00_4EBED0 },
    { -100.0f, D_801358A0_4E7C70, D_80139A00_4EBDD0 },
    { -100.0f, D_80133040_4E5410, D_80139900_4EBCD0 },
    { 149.0f, D_8012C9E0_4DEDB0, D_801394D0_4EB8A0 },
    { 150.0f, D_8012D700_4DFAD0, D_801395A0_4EB970 },
    { 151.0f, D_80131D30_4E4100, D_80139840_4EBC10 },
    { 152.0f, D_8012FB60_4E1F30, D_80139770_4EBB40 },
};

Unkfunc_8009BDDCSub D_800AD428[] = {
    { -100.0f, moltres_egg_modelanim_idle, NULL },
    { -100.0f, moltres_egg_modelanim_drown, NULL },
};

Unkfunc_8009BDDCSub D_800AD440[] = {
    { -100.0f, (AnimCmd**) 0x8017A200, NULL },
    { -100.0f, (AnimCmd**) 0x8017A350, NULL },
    { -100.0f, &D_8017A710, NULL },
    { -100.0f, (AnimCmd**) 0x8017A510, NULL },
};

Unkfunc_8009BDDCSub D_800AD470[] = {
    { -100.0f, (AnimCmd**) 0x80188820, NULL },
    { -100.0f, (AnimCmd**) 0x80188940, NULL },
    { -100.0f, &D_80188CB0, NULL },
    { -100.0f, (AnimCmd**) 0x80188AF0, NULL },
};

Unkfunc_8009BDDCSub D_800AD4A0[] = {
    { 87.0f, (AnimCmd**) 0x80183C10, NULL },
    { 88.0f, (AnimCmd**) 0x801836C0, NULL },
};

Unkfunc_8009BDDC D_800AD4B8[] = {
    { PokemonID_GRIMER, D_800ACC78, ARRAY_COUNT(D_800ACC78) },
    { PokemonID_MUK, D_800ACCB4, ARRAY_COUNT(D_800ACCB4) },
    { PokemonID_MAGMAR, D_800ACFC0, ARRAY_COUNT(D_800ACFC0) },
    { PokemonID_BUTTERFREE, D_800AC3E4, ARRAY_COUNT(D_800AC3E4) },
    { PokemonID_KAKUNA, D_800AC3FC, ARRAY_COUNT(D_800AC3FC) },
    { PokemonID_MAGNEMITE, D_800ACBE8, ARRAY_COUNT(D_800ACBE8) },
    { PokemonID_DIGLETT, D_800AC6E4, ARRAY_COUNT(D_800AC6E4) },
    { PokemonID_DODUO, D_800ACC3C, ARRAY_COUNT(D_800ACC3C) },
    { PokemonID_KOFFING, D_800ACD50, ARRAY_COUNT(D_800ACD50) },
    { PokemonID_DUGTRIO, D_800AC720, ARRAY_COUNT(D_800AC720) },
    { PokemonID_EEVEE, D_800AD11C, ARRAY_COUNT(D_800AD11C) },
    { PokemonID_ELECTABUZZ, D_800ACF54, ARRAY_COUNT(D_800ACF54) },
    { PokemonID_MOLTRES, D_800AD32C, ARRAY_COUNT(D_800AD32C) },
    { PokemonID_MOLTRES_EGG, D_800AD428, ARRAY_COUNT(D_800AD428) },
    { PokemonID_ARTICUNO, D_800AD2D8, ARRAY_COUNT(D_800AD2D8) },
    { PokemonID_601, D_800AD440, ARRAY_COUNT(D_800AD440) },
    { PokemonID_BULBASAUR, D_800AC120, ARRAY_COUNT(D_800AC120) },
    { PokemonID_RAPIDASH, D_800ACAD4, ARRAY_COUNT(D_800ACAD4) },
    { PokemonID_GROWLITHE, D_800AC870, ARRAY_COUNT(D_800AC870) },
    { PokemonID_KANGASKHAN, D_800ACE04, ARRAY_COUNT(D_800ACE04) },
    { PokemonID_HAUNTER, D_800ACD14, ARRAY_COUNT(D_800ACD14) },
    { PokemonID_GRAVELER, D_800ACA68, ARRAY_COUNT(D_800ACA68) },
    { PokemonID_GYARADOS, D_800AD068, ARRAY_COUNT(D_800AD068) },
    { PokemonID_STARYU, D_800ACE7C, ARRAY_COUNT(D_800ACE7C) },
    { PokemonID_CHARMANDER, D_800AC1F8, ARRAY_COUNT(D_800AC1F8) },
    { PokemonID_GEODUDE, D_800ACA20, ARRAY_COUNT(D_800ACA20) },
    { PokemonID_SNORLAX, D_800AD260, ARRAY_COUNT(D_800AD260) },
    { PokemonID_DRAGONITE, D_800AD38C, ARRAY_COUNT(D_800AD38C) },
    { PokemonID_PSYDUCK, D_800AC7D4, ARRAY_COUNT(D_800AC7D4) },
    { PokemonID_MAGIKARP, D_800AD038, ARRAY_COUNT(D_800AD038) },
    { PokemonID_LAPRAS, D_800AD0A4, ARRAY_COUNT(D_800AD0A4) },
    { PokemonID_CHARMELEON, D_800AC270, ARRAY_COUNT(D_800AC270) },
    { PokemonID_CHARIZARD, D_800AC2DC, ARRAY_COUNT(D_800AC2DC) },
    { PokemonID_CHANSEY, D_800ACD98, ARRAY_COUNT(D_800ACD98) },
    { PokemonID_MANKEY, D_800AC834, ARRAY_COUNT(D_800AC834) },
    { PokemonID_ELECTRODE, D_800ACD20, ARRAY_COUNT(D_800ACD20) },
    { PokemonID_DITTO, D_800AD0B0, ARRAY_COUNT(D_800AD0B0) },
    { PokemonID_MEW, D_800AD3C8, ARRAY_COUNT(D_800AD3C8) },
    { PokemonID_DRATINI, D_800AD368, ARRAY_COUNT(D_800AD368) },
    { PokemonID_MEOWTH, D_800AC75C, ARRAY_COUNT(D_800AC75C) },
    { PokemonID_POLIWAG, D_800AC930, ARRAY_COUNT(D_800AC930) },
    { PokemonID_CLOYSTER, D_800ACCFC, ARRAY_COUNT(D_800ACCFC) },
    { PokemonID_PIKACHU, D_800AC444, ARRAY_COUNT(D_800AC444) },
    { PokemonID_PIDGEY, D_800AC414, ARRAY_COUNT(D_800AC414) },
    { PokemonID_PORYGON, D_800AD158, ARRAY_COUNT(D_800AD158) },
    { PokemonID_JIGGLYPUFF, D_800AC630, ARRAY_COUNT(D_800AC630) },
    { PokemonID_MAGNETON, D_800ACC30, ARRAY_COUNT(D_800ACC30) },
    { PokemonID_VULPIX, D_800AC5D0, ARRAY_COUNT(D_800AC5D0) },
    { PokemonID_JYNX, D_800ACF0C, ARRAY_COUNT(D_800ACF0C) },
    { PokemonID_VILEPLUME, D_800AC69C, ARRAY_COUNT(D_800AC69C) },
    { PokemonID_SANDSHREW, D_800AC4E0, ARRAY_COUNT(D_800AC4E0) },
    { PokemonID_SANDSLASH, D_800AC558, ARRAY_COUNT(D_800AC558) },
    { PokemonID_SHELLDER, D_800ACCF0, ARRAY_COUNT(D_800ACCF0) },
    { PokemonID_603, D_800AD4A0, ARRAY_COUNT(D_800AD4A0) },
    { PokemonID_STARMIE, D_800ACEA0, ARRAY_COUNT(D_800ACEA0) },
    { PokemonID_SCYTHER, D_800ACEC4, ARRAY_COUNT(D_800ACEC4) },
    { PokemonID_ZAPDOS, D_800AD2FC, ARRAY_COUNT(D_800AD2FC) },
    { PokemonID_ZAPDOS_EGG, D_800AD470, ARRAY_COUNT(D_800AD470) },
    { PokemonID_GOLDEEN, D_800ACE58, ARRAY_COUNT(D_800ACE58) },
    { PokemonID_METAPOD, D_800AC3C0, ARRAY_COUNT(D_800AC3C0) },
    { PokemonID_VICTREEBEL, D_800AC9FC, ARRAY_COUNT(D_800AC9FC) },
    { PokemonID_WEEPINBELL, D_800AC9A8, ARRAY_COUNT(D_800AC9A8) },
    { PokemonID_ARCANINE, D_800AC8D0, ARRAY_COUNT(D_800AC8D0) },
    { PokemonID_SLOWPOKE, D_800ACB1C, ARRAY_COUNT(D_800ACB1C) },
    { PokemonID_SLOWBRO, D_800ACB94, ARRAY_COUNT(D_800ACB94) },
    { PokemonID_SQUIRTLE, D_800AC318, ARRAY_COUNT(D_800AC318) },
    { PokemonID_ZUBAT, D_800AC690, ARRAY_COUNT(D_800AC690) },
};

Unkfunc_8009BDDCSub D_800AD7DC[] = {
    { 0.0f, gate_modelanim_closed, gate_matanim_closed },
    { 0.0f, gate_modelanim_raise_bar, gate_matanim_raise_bar },
    { 0.0f, gate_modelanim_opening, gate_matanim_opening },
    { 0.0f, gate_modelanim_opened, gate_matanim_opened },
};

Unkfunc_8009BDDCSub D_800AD80C[] = {
    { 0.0f, evolution_controller_modelanim, evolution_controller_matanim },
};

Unkfunc_8009BDDCSub D_800AD818[] = {
    { 0.0f, &D_800EAFB0, &D_800EB0C0 },
};

Unkfunc_8009BDDCSub D_800AD824[] = {
    { 0.0f, D_80139CD0_C6160, D_8013ACA0_C7130 },
};

Unkfunc_8009BDDCSub D_800AD830[] = {
    { 0.0f, (AnimCmd**) 0x80138ED0, NULL },
    { 0.0f, (AnimCmd**) 0x80138F20, NULL },
};

Unkfunc_8009BDDCSub D_800AD848[] = {
    { 0.0f, (AnimCmd**) 0x80138810, (AnimCmd***) 0x80138870 },
    { 0.0f, (AnimCmd**) 0x80138930, (AnimCmd***) 0x80138990 },
};

Unkfunc_8009BDDCSub D_800AD860[] = {
    { 0.0f, (AnimCmd**) 0x80133740, (AnimCmd***) 0x801338B0 },
    { 0.0f, (AnimCmd**) 0x80134090, (AnimCmd***) 0x80134150 },
};

Unkfunc_8009BDDCSub D_800AD878[] = {
    { 0.0f, (AnimCmd**) 0x801394A0, (AnimCmd***) 0x801394B0 },
    { 0.0f, (AnimCmd**) 0x80139500, (AnimCmd***) 0x80139510 },
};

Unkfunc_8009BDDCSub D_800AD890[] = {
    { 0.0f, (AnimCmd**) 0x80139A90, (AnimCmd***) 0x80139AA0 },
    { 0.0f, (AnimCmd**) 0x80139AF0, (AnimCmd***) 0x80139B00 },
};

Unkfunc_8009BDDCSub D_800AD8A8[] = {
    { 0.0f, koffing_smoke_modelanim_show, koffing_smoke_matanim_show },
    { 0.0f, koffing_smoke_modelanim_reveal, koffing_smoke_matanim_reveal },
    { 0.0f, koffing_smoke_modelanim_hide, koffing_smoke_matanim_hide },
};

Unkfunc_8009BDDCSub D_800AD8CC[] = {
    { 0.0f, smoke_puff_modelanim, smoke_puff_matanim },
};

Unkfunc_8009BDDCSub D_800AD8D8[] = {
    { 0.0f, lava_splash_modelanim, lava_splash_matanim },
};

Unkfunc_8009BDDCSub D_800AD8E4[] = {
    { 0.0f, volcano_smoke_modelanim, volcano_smoke_matanim },
};

Unkfunc_8009BDDCSub D_800AD8F0[] = {
    { 0.0f, (AnimCmd**) 0x801197F0, (AnimCmd***) 0x80119830 },
    { 0.0f, (AnimCmd**) 0x801198F0, (AnimCmd***) 0x80119940 },
};

Unkfunc_8009BDDCSub D_800AD908[] = {
    { 0.0f, D_80117210_4C95E0, D_80117260_4C9630 },
    { 0.0f, D_80117310_4C96E0, D_80117360_4C9730 },
    { 0.0f, D_80117410_4C97E0, D_80117480_4C9850 },
    { 0.0f, D_80117570_4C9940, D_801175E0_4C99B0 },
    { 0.0f, D_801176D0_4C9AA0, D_80117730_4C9B00 },
    { 0.0f, D_80117840_4C9C10, D_801178A0_4C9C70 },
    { 0.0f, D_80117980_4C9D50, D_801179C0_4C9D90 },
    { 0.0f, D_80117A50_4C9E20, D_80117A90_4C9E60 },
    { 0.0f, D_80117B20_4C9EF0, D_80117B60_4C9F30 },
    { 0.0f, D_80117C70_4CA040, D_80117CB0_4CA080 },
    { 0.0f, D_80117DC0_4CA190, D_80117DF0_4CA1C0 },
    { 0.0f, D_80117F10_4CA2E0, D_80117F40_4CA310 },
};

Unkfunc_8009BDDCSub D_800AD998[] = {
    { 0.0f, D_80118360_4CA730, D_80118390_4CA760 },
};

Unkfunc_8009BDDC D_800AD9A4[] = {
    { PokemonID_GATE, D_800AD7DC, ARRAY_COUNT(D_800AD7DC) },
    { PokemonID_EVOLUTION_CONTROLLER, D_800AD80C, ARRAY_COUNT(D_800AD80C) },
    { PokemonID_1003, D_800AD818, ARRAY_COUNT(D_800AD818) },
    { PokemonID_1006, D_800AD824, ARRAY_COUNT(D_800AD824) },
    { PokemonID_1009, D_800AD830, ARRAY_COUNT(D_800AD830) },
    { PokemonID_1010, D_800AD848, ARRAY_COUNT(D_800AD848) },
    { PokemonID_1008, D_800AD860, ARRAY_COUNT(D_800AD860) },
    { PokemonID_1012, D_800AD878, ARRAY_COUNT(D_800AD878) },
    { PokemonID_1013, D_800AD890, ARRAY_COUNT(D_800AD890) },
    { PokemonID_KOFFING_SMOKE, D_800AD8A8, ARRAY_COUNT(D_800AD8A8) },
    { PokemonID_SMOKE_PUFF, D_800AD8CC, ARRAY_COUNT(D_800AD8CC) },
    { PokemonID_LAVA_SPLASH, D_800AD8D8, ARRAY_COUNT(D_800AD8D8) },
    { PokemonID_VOLCANO_SMOKE, D_800AD8E4, ARRAY_COUNT(D_800AD8E4) },
    { PokemonID_1033, D_800AD8F0, ARRAY_COUNT(D_800AD8F0) },
    { PokemonID_1037, D_800AD908, ARRAY_COUNT(D_800AD908) },
    { PokemonID_1038, D_800AD998, ARRAY_COUNT(D_800AD998) },
};

Unk1C D_800ADA64[] = {
    { PokemonID_1004, 10.0f, D_80136AC0_C2F50, NULL, renderModelTypeDFogged, NULL, NULL },
    { PokemonID_1014, 10.0f, (UnkEC64Arg3*) 0x8013AA00, NULL, renderModelTypeBFogged, NULL, NULL },
    { PokemonID_1018, 10.0f, (UnkEC64Arg3*) 0x801450C0, NULL, renderModelTypeDFogged, (AnimCmd**) 0x801456D0, NULL },
    { PokemonID_1019, 10.0f, (UnkEC64Arg3*) 0x801473B0, NULL, renderModelTypeBFogged, NULL, NULL },
    { PokemonID_1021, 2.0f, (UnkEC64Arg3*) 0x80143D60, (Texture***) 0x80143CC0, renderModelTypeBFogged, NULL, NULL },
    { PokemonID_1022, 10.0f, (UnkEC64Arg3*) 0x80145B08, NULL, renderModelTypeDFogged, NULL, NULL },
    { PokemonID_1023, 10.0f, (UnkEC64Arg3*) 0x80145D60, (Texture***) 0x80145CC0, renderModelTypeBFogged, (AnimCmd**) 0x80145EB0, (AnimCmd***) 0x80145ED0 },
    { PokemonID_1024, 10.0f, (UnkEC64Arg3*) 0x801460B0, (Texture***) 0x80146010, renderModelTypeBFogged, (AnimCmd**) 0x80146200, (AnimCmd***) 0x80146220 },
    { PokemonID_1025, 10.0f, (UnkEC64Arg3*) 0x80146400, (Texture***) 0x80146360, renderModelTypeBFogged, (AnimCmd**) 0x80146550, (AnimCmd***) 0x80146570 },
    { PokemonID_GROWLITHE_SPAWNER, 10.0f, growlithe_spawner_model, growlithe_spawner_materials, renderModelTypeBFogged, growlithe_spawner_modelanim, growlithe_spawner_matanim },
    { PokemonID_1032, 10.0f, (UnkEC64Arg3*) 0x8011AC50, NULL, renderModelTypeBFogged, NULL, NULL },
    { PokemonID_1034, 2.0f, (UnkEC64Arg3*) 0x80118820, (Texture***) 0x80118780, renderModelTypeBFogged, NULL, NULL },
    { PokemonID_1035, 10.0f, (UnkEC64Arg3*) 0x80119BB0, NULL, renderModelTypeBFogged, NULL, NULL },
    { 0, 0.0f, NULL, NULL, NULL, NULL, NULL },
};

UnkV0 D_800ADBEC[] = {
    { PokemonID_GRIMER, 2.0f, grimer_hd_model, grimer_hd_materials, renderModelTypeIFogged },
    { PokemonID_MUK, 1.5f, muk_hd_model, muk_hd_materials, renderModelTypeIFogged },
    { PokemonID_MAGMAR, 1.3f, magmar_hd_model, magmar_hd_materials, renderModelTypeJFogged },
    { PokemonID_BUTTERFREE, 1.6f, butterfree_hd_model, NULL, renderModelTypeBFogged },
    { PokemonID_KAKUNA, 2.2f, kakuna_hd_model, kakuna_hd_materials, renderModelTypeBFogged },
    { PokemonID_MAGNEMITE, 2.2f, magnemite_hd_model, magnemite_hd_materials, renderModelTypeDFogged },
    { PokemonID_DIGLETT, 2.4f, diglett_hd_model, diglett_hd_materials, renderModelTypeBFogged },
    { PokemonID_DODUO, 2.0f, doduo_hd_model, doduo_hd_materials, renderModelTypeBFogged },
    { PokemonID_KOFFING, 2.5f, koffing_hd_model, koffing_hd_materials, renderModelTypeJFogged },
    { PokemonID_DUGTRIO, 1.7f, dugtrio_hd_model, NULL, renderModelTypeBFogged },
    { PokemonID_EEVEE, 2.4f, eevee_hd_model, eevee_hd_materials, renderModelTypeBFogged },
    { PokemonID_ELECTABUZZ, 1.7f, electabuzz_hd_model, electabuzz_hd_materials, renderModelTypeJFogged },
    { PokemonID_MOLTRES, 1.5f, moltres_hd_model, moltres_hd_materials, func_800A1680 },
    { PokemonID_MOLTRES_EGG, 1.7f, moltres_egg_model, NULL, renderModelTypeBFogged },
    { PokemonID_ARTICUNO, 1.6f, articuno_hd_model, articuno_hd_materials, renderModelTypeIFogged },
    { PokemonID_601, 2.2f, (UnkEC64Arg3*) 0x8017BFA8, NULL, renderModelTypeDFogged },
    { PokemonID_BULBASAUR, 2.0f, bulbasaur_hd_model, bulbasaur_hd_materials, renderModelTypeJFogged },
    { PokemonID_RAPIDASH, 1.2f, rapidash_hd_model, rapidash_hd_materials, func_800A1680 },
    { PokemonID_GROWLITHE, 2.2f, growlithe_hd_model, growlithe_hd_materials, renderModelTypeIFogged },
    { PokemonID_KANGASKHAN, 1.5f, kangaskhan_hd_model, kangaskhan_hd_materials, renderModelTypeIFogged },
    { PokemonID_HAUNTER, 1.0f, haunter_hd_model, NULL, renderModelTypeIFogged },
    { PokemonID_GRAVELER, 2.2f, graveler_hd_model, graveler_hd_materials, renderModelTypeIFogged },
    { PokemonID_GYARADOS, 2.0f, gyarados_hd_model, gyarados_hd_materials, renderModelTypeBFogged },
    { PokemonID_STARYU, 2.0f, staryu_hd_model, staryu_hd_materials, renderModelTypeIFogged },
    { PokemonID_CHARMANDER, 2.0f, charmander_hd_model, charmander_hd_materials, renderModelTypeJFogged },
    { PokemonID_GEODUDE, 2.0f, geodude_hd_model, geodude_hd_materials, renderModelTypeIFogged },
    { PokemonID_SNORLAX, 1.5f, snorlax_hd_model, snorlax_hd_materials, renderModelTypeJFogged },
    { PokemonID_DRAGONITE, 2.2f, dragonite_hd_model, NULL, renderModelTypeIFogged },
    { PokemonID_PSYDUCK, 1.4f, psyduck_hd_model, NULL, renderModelTypeIFogged },
    { PokemonID_MAGIKARP, 1.6f, magikarp_hd_model, NULL, renderModelTypeBFogged },
    { PokemonID_LAPRAS, 3.0f, lapras_hd_model, lapras_hd_materials, renderModelTypeIFogged },
    { PokemonID_CHARMELEON, 1.8f, charmeleon_hd_model, charmeleon_hd_materials, renderModelTypeJFogged },
    { PokemonID_CHARIZARD, 3.5f, charizard_hd_model, charizard_hd_materials, renderModelTypeIFogged },
    { PokemonID_CHANSEY, 2.0f, chansey_hd_model, chansey_hd_materials, renderModelTypeIFogged },
    { PokemonID_MANKEY, 2.0f, mankey_hd_model, mankey_hd_materials, renderModelTypeIFogged },
    { PokemonID_ELECTRODE, 1.4f, electrode_hd_model, electrode_hd_materials, renderModelTypeDFogged },
    { PokemonID_DITTO, 2.6f, ditto_hd_model, NULL, renderModelTypeIFogged },
    { PokemonID_MEW, 2.0f, mew_hd_model, mew_hd_materials, renderModelTypeIFogged },
    { PokemonID_DRATINI, 1.5f, dratini_hd_model, dratini_hd_materials, renderModelTypeIFogged },
    { PokemonID_MEOWTH, 2.4f, meowth_hd_model, meowth_hd_materials, renderModelTypeBFogged },
    { PokemonID_POLIWAG, 1.6f, poliwag_hd_model, NULL, renderModelTypeDFogged },
    { PokemonID_CLOYSTER, 1.3f, cloyster_hd_model, NULL, renderModelTypeBFogged },
    { PokemonID_PIKACHU, 2.0f, pikachu_hd_model, pikachu_hd_materials, renderModelTypeJFogged },
    { PokemonID_PIDGEY, 2.0f, pidgey_hd_model, pidgey_hd_materials, renderModelTypeIFogged },
    { PokemonID_PORYGON, 1.5f, porygon_hd_model, porygon_hd_materials, renderModelTypeIFogged },
    { PokemonID_JIGGLYPUFF, 2.2f, jigglypuff_hd_model, jigglypuff_hd_materials, renderModelTypeIFogged },
    { PokemonID_MAGNETON, 2.2f, magneton_hd_model, NULL, renderModelTypeBFogged },
    { PokemonID_VULPIX, 1.7f, vulpix_hd_model, vulpix_hd_materials, renderModelTypeIFogged },
    { PokemonID_JYNX, 1.4f, jynx_hd_model, jynx_hd_materials, renderModelTypeIFogged },
    { PokemonID_VILEPLUME, 1.5f, vileplume_hd_model, vileplume_hd_materials, renderModelTypeDFogged },
    { PokemonID_SANDSHREW, 2.0f, sandshrew_hd_model, sandshrew_hd_materials, renderModelTypeIFogged },
    { PokemonID_SANDSLASH, 2.0f, sandslash_hd_model, sandslash_hd_materials, renderModelTypeIFogged },
    { PokemonID_SHELLDER, 2.2f, shellder_hd_model, NULL, renderModelTypeBFogged },
    { PokemonID_603, 2.0f, shellder2_hd_model, shellder2_hd_materials, renderModelTypeBFogged },
    { PokemonID_STARMIE, 2.2f, starmie_hd_model, starmie_hd_materials, renderModelTypeIFogged },
    { PokemonID_SCYTHER, 0.9f, scyther_hd_model, NULL, renderModelTypeDFogged },
    { PokemonID_ZAPDOS, 1.5f, zapdos_hd_model, zapdos_hd_materials, renderModelTypeIFogged },
    { PokemonID_ZAPDOS_EGG, 2.0f, (UnkEC64Arg3*) 0x8018A640, NULL, renderModelTypeDFogged },
    { PokemonID_GOLDEEN, 2.0f, goldeen_hd_model, goldeen_hd_materials, renderModelTypeIFogged },
    { PokemonID_METAPOD, 1.8f, metapod_hd_model, metapod_hd_materials, renderModelTypeBFogged },
    { PokemonID_VICTREEBEL, 2.0f, victreebel_hd_model, victreebel_hd_materials, renderModelTypeDFogged },
    { PokemonID_WEEPINBELL, 2.0f, weepinbell_hd_model, weepinbell_hd_materials, renderModelTypeIFogged },
    { PokemonID_ARCANINE, 1.4f, arcanine_hd_model, arcanine_hd_materials, renderModelTypeIFogged },
    { PokemonID_SLOWPOKE, 1.6f, slowpoke_hd_model, NULL, renderModelTypeIFogged },
    { PokemonID_SLOWBRO, 1.3f, slowbro_hd_model, slowbro_hd_materials, renderModelTypeIFogged },
    { PokemonID_SQUIRTLE, 2.2f, squirtle_hd_model, squirtle_hd_materials, renderModelTypeBFogged },
    { PokemonID_ZUBAT, 2.2f, zubat_hd_model, NULL, renderModelTypeIFogged },
    { PokemonID_GATE, 10.0f, gate_model, gate_materials, renderModelTypeDFogged },
    { PokemonID_EVOLUTION_CONTROLLER, 20.0f, evolution_controller_model, evolution_controller_materials, renderModelTypeDFogged },
    { PokemonID_1003, 2.0f, &D_800EB430, &D_800EB510, renderModelTypeDFogged },
    { PokemonID_1006, 3.0f, D_80139A40_C5ED0, D_801397C0_C5C50, renderModelTypeDFogged },
    { PokemonID_1009, 10.0f, (UnkEC64Arg3*) 0x80138DF0, NULL, renderModelTypeBFogged },
    { PokemonID_1010, 10.0f, (UnkEC64Arg3*) 0x801382E0, (Texture***) 0x80138630, renderModelTypeDFogged },
    { PokemonID_1008, 10.0f, (UnkEC64Arg3*) 0x80132F30, (Texture***) 0x80133250, renderModelTypeBFogged },
    { PokemonID_1012, 10.0f, (UnkEC64Arg3*) 0x80139378, (Texture***) 0x80139400, renderModelTypeDFogged },
    { PokemonID_1013, 10.0f, (UnkEC64Arg3*) 0x80139968, (Texture***) 0x801399F0, renderModelTypeDFogged },
    { PokemonID_KOFFING_SMOKE, 30.0f, koffing_smoke_model, koffing_smoke_materials, renderModelTypeDFogged },
    { PokemonID_SMOKE_PUFF, 30.0f, smoke_puff_model, smoke_puff_materials, renderModelTypeDFogged },
    { PokemonID_LAVA_SPLASH, 10.0f, lava_splash_model, lava_splash_materials, renderModelTypeDFogged },
    { PokemonID_VOLCANO_SMOKE, 10.0f, volcano_smoke_model, volcano_smoke_materials, renderModelTypeDFogged },
    { PokemonID_1033, 10.0f, (UnkEC64Arg3*) 0x80119330, (Texture***) 0x80119210, renderModelTypeBFogged },
    { PokemonID_1037, 2.0f, D_80116EF0_4C92C0, D_80116CF0_4C90C0, renderModelTypeDFogged },
    { PokemonID_1038, 2.0f, D_80118210_4CA5E0, D_80118160_4CA530, renderModelTypeDFogged },
    { 0, 0.0f, NULL, NULL, NULL },
};

s32 D_800AE27C = 0;
s32 D_800AE280 = 0;

char* D_800AE284[] = {
    "",
    "ＢＵＬＢＡＳＡＵＲ",
    "ＩＶＹＳＡＵＲ",
    "ＶＥＮＵＳＡＵＲ",
    "ＣＨＡＲＭＡＮＤＥＲ",
    "ＣＨＡＲＭＥＬＥＯＮ",
    "ＣＨＡＲＩＺＡＲＤ",
    "ＳＱＵＩＲＴＬＥ",
    "ＷＡＲＴＯＲＴＬＥ",
    "ＢＬＡＳＴＯＩＳＥ",
    "ＣＡＴＥＲＰＩＥ",
    "ＭＥＴＡＰＯＤ",
    "ＢＵＴＴＥＲＦＲＥＥ",
    "ＷＥＥＤＬＥ",
    "ＫＡＫＵＮＡ",
    "ＢＥＥＤＲＩＬＬ",
    "ＰＩＤＧＥＹ",
    "ＰＩＤＧＥＯＴＴＯ",
    "ＰＩＤＧＥＯＴ",
    "ＲＡＴＴＡＴＡ",
    "ＲＡＴＩＣＡＴＥ",
    "ＳＰＥＡＲＯＷ",
    "ＦＥＡＲＯＷ",
    "ＥＫＡＮＳ",
    "ＡＲＢＯＫ",
    "ＰＩＫＡＣＨＵ",
    "ＲＡＩＣＨＵ",
    "ＳＡＮＤＳＨＲＥＷ",
    "ＳＡＮＤＳＬＡＳＨ",
    "ＮＩＤＲＡＮｆ",
    "ＮＩＤＯＲＩＮＡ",
    "ＮＩＤＯＱＵＥＥＮ",
    "ＮＩＤＯＲＡＮｍ",
    "ＮＩＤＯＲＩＮＯ",
    "ＮＩＤＯＫＩＮＧ",
    "ＣＬＥＦＡＩＲＹ",
    "ＣＬＥＦＡＢＬＥ",
    "ＶＵＬＰＩＸ",
    "ＮＩＮＥＴＡＬＥＳ",
    "ＪＩＧＧＬＹＰＵＦＦ",
    "ＷＩＧＧＬＹＴＵＦＦ",
    "ＺＵＢＡＴ",
    "ＧＯＬＢＡＴ",
    "ＯＤＤＩＳＨ",
    "ＧＬＯＯＭ",
    "ＶＩＬＥＰＬＵＭＥ",
    "ＰＡＲＡＳ",
    "ＰＡＲＡＳＥＣＴ",
    "ＶＥＮＯＮＡＴ",
    "ＶＥＮＯＭＯＴＨ",
    "ＤＩＧＬＥＴＴ",
    "ＤＵＧＴＲＩＯ",
    "ＭＥＯＷＴＨ",
    "ＰＥＲＳＩＡＮ",
    "ＰＳＹＤＵＣＫ",
    "ＧＯＬＤＵＣＫ",
    "ＭＡＮＫＥＹ",
    "ＰＲＩＭＥＡＰＥ",
    "ＧＲＯＷＬＩＴＨＥ",
    "ＡＲＣＡＮＩＮＥ",
    "ＰＯＬＩＷＡＧ",
    "ＰＯＬＩＷＨＩＲＬ",
    "ＰＯＬＩＷＲＡＴＨ",
    "ＡＢＲＡ",
    "ＫＡＤＡＢＲＡ",
    "ＡＬＡＫＡＺＡＭ",
    "ＭＡＣＨＯＰ",
    "ＭＡＣＨＯＫＥ",
    "ＭＡＣＨＡＭＰ",
    "ＢＥＬＬＳＰＲＯＵＴ",
    "ＷＥＥＰＩＮＢＥＬＬ",
    "ＶＩＣＴＲＥＥＢＥＬ",
    "ＴＥＮＴＡＣＯＯＬ",
    "ＴＥＮＴＡＣＲＵＥＬ",
    "ＧＥＯＤＵＤＥ",
    "ＧＲＡＶＥＬＥＲ",
    "ＧＯＬＥＭ",
    "ＰＯＮＹＴＡ",
    "ＲＡＰＩＤＡＳＨ",
    "ＳＬＯＷＰＯＫＥ",
    "ＳＬＯＷＢＲＯ",
    "ＭＡＧＮＥＭＩＴＥ",
    "ＭＡＧＮＥＴＯＮ",
    "ＦＡＲＦＥＴＣＨ’Ｄ",
    "ＤＯＤＵＯ",
    "ＤＯＤＲＩＯ",
    "ＳＥＥＬ",
    "ＤＥＷＧＯＮＧ",
    "ＧＲＩＭＥＲ",
    "ＭＵＫ",
    "ＳＨＥＬＬＤＥＲ",
    "ＣＬＯＹＳＴＥＲ",
    "ＧＡＳＴＬＹ",
    "ＨＡＵＮＴＥＲ",
    "ＧＥＮＧＡＲ",
    "ＯＮＩＸ",
    "ＤＲＯＷＺＥＥ",
    "ＨＹＰＮＯ",
    "ＫＲＡＢＢＹ",
    "ＫＩＮＧＬＥＲ",
    "ＶＯＬＴＯＲＢ",
    "ＥＬＥＣＴＲＯＤＥ",
    "ＥＸＥＧＧＣＵＴＥ",
    "ＥＸＥＧＧＵＴＯＲ",
    "ＣＵＢＯＮＥ",
    "ＭＡＲＯＷＡＫ",
    "ＨＩＴＭＯＮＬＥＥ",
    "ＨＩＴＭＯＮＣＨＡＮ",
    "ＬＩＣＫＩＴＵＮＧ",
    "ＫＯＦＦＩＮＧ",
    "ＷＥＥＺＩＮＧ",
    "ＲＨＹＨＯＲＮ",
    "ＲＨＹＤＯＮ",
    "ＣＨＡＮＳＥＹ",
    "ＴＡＮＧＥＬＡ",
    "ＫＡＮＧＡＳＫＨＡＮ",
    "ＨＯＲＳＥＡ",
    "ＳＥＡＤＲＡ",
    "ＧＯＬＤＥＥＮ",
    "ＳＥＡＫＩＮＧ",
    "ＳＴＡＲＹＵ",
    "ＳＴＡＲＭＩＥ",
    "ＭＲ．ＭＩＭＥ",
    "ＳＣＹＴＨＥＲ",
    "ＪＹＮＸ",
    "ＥＬＥＣＴＡＢＵＺＺ",
    "ＭＡＧＭＡＲ",
    "ＰＩＮＳＥＲ",
    "ＴＡＵＲＯＳ",
    "ＭＡＧＩＫＡＲＰ",
    "ＧＹＡＲＡＤＯＳ",
    "ＬＡＰＲＡＳ",
    "ＤＩＴＴＯ",
    "ＥＥＶＥＥ",
    "ＶＡＰＯＥＲＯＮ",
    "ＪＯＬＴＥＯＮ",
    "ＦＬＡＲＥＯＮ",
    "ＰＯＲＹＧＯＮ",
    "ＯＭＡＮＹＴＥ",
    "ＯＭＡＳＴＡＲ",
    "ＫＡＢＵＴＯ",
    "ＫＡＢＵＴＯＰＳ",
    "ＡＥＲＯＤＡＣＴＹＬ",
    "ＳＮＯＲＬＡＸ",
    "ＡＲＴＩＣＵＮＯ",
    "ＺＡＰＤＯＳ",
    "ＭＯＬＴＲＥＳ",
    "ＤＲＡＴＩＮＩ",
    "ＤＲＡＧＯＮＡＩＲ",
    "ＤＲＡＧＯＮＩＴＥ",
    "ＭＥＷＴＷＯ",
    "ＭＥＷ",
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
extern UNK_TYPE D_801B1230;
extern UNK_TYPE D_801B1D40;
extern UNK_TYPE D_801B6B60;
extern UNK_TYPE D_801CE400;
extern UNK_TYPE D_8017C090;
extern UNK_TYPE D_801CF770;
extern UNK_TYPE D_801CF840;
extern UNK_TYPE D_801D6840;

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
            if (D_800ACD98[arg0->unk_00_13].modelAnims == &D_80186E20) {
                model->scale.v.x *= 0.5f;
                model->scale.v.y *= 0.5f;
                model->scale.v.z *= 0.5f;
            }
            break;
        case PokemonID_ZAPDOS_EGG:
            if (D_800AD470[arg0->unk_00_13].modelAnims == &D_80188CB0) {
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
            if (D_800AD440[arg0->unk_00_13].modelAnims == &D_8017A710) {
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
