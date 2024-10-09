#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#include "ultra64.h"
#include "common_structs.h"

f32 __cosf(f32);
f32 __sinf(f32);

void GetInterpolatedPosition(Vec3f*, InterpData*, f32);

GObj* pokemonAddOne(struct WorldBlock* roomA, struct WorldBlock* roomB, ObjectSpawn* spawn, PokemonDef* def);
void pokemonAdd(struct WorldBlock*, struct WorldBlock*, PokemonDef* def);

s32 getLevelId(void);
void setLevelId(s32 levelID);
char* getLevelName(s32 levelIdx);

void spawnStaryuAtGeo(GObj*);
void spawnStarmieAtGeo(GObj*);
void spawnKoffingSmoke(s32 gObjID, u16 id, struct WorldBlock* roomA, struct WorldBlock* roomB, ObjectSpawn* spawn);

GObj* func_8035E1D4_4FE5E4(GObj*);

void ren_func_800192DC(GObj* obj);

void func_8009A8F0(s32);
char* getPokemonName(s32);
s32 func_8009BB4C(s32 pkmnID);
s32 func_8009BC68(void);
s32 func_8009C584(const void* a, const void* b);
s32 func_8009C5C4(const void* a, const void* b);
void func_8009CE00(void);
void func_8009FA68(OMCamera*, PhotoData*);
void func_8009FBC4(void);
void func_8009FB50(u8 arg0, u8 arg1, u8 arg2);
void func_8009FC38(PhotoData*);
void renderModelTypeAFogged(GObj*);
void renderModelTypeBFogged(GObj*);
void renderModelTypeCFogged(GObj*);
void renderModelTypeDFogged(GObj*);
void renderModelTypeIFogged(GObj*);
void renderModelTypeJFogged(GObj*);
void setBackgroundColor(u8, u8, u8);
void setFogColor(u8, u8, u8);
void setFogDistance(u16, u16);
void func_800A19D8(s32);
void func_800A1A50(Gfx**);

void func_800A1E6C(Vec3f*);
void func_800A1ED0(s32, UNK_PTR, UNK_PTR);
GObj* func_800A2094(s32, s32, OMCamera*);
void func_800A5DF4(s32, s32);
GObj* func_800A5E08(s32);

UnkPinkRat* func_800A6C48(s32, s32);
void func_800A71F8(f32, f32, f32);
void* func_800A73C0(u32 romSrcStart, u32 romSrcEnd);
s32 func_800A7460(void);
void func_800A7470(s32, s32, s32);
void func_800A7860(s32, f32);
void func_800A7F68(s32, s32);
void func_800A844C(OMCamera*, s32, s32, s32, s32);
GObj* func_800A85E8(void (*procFunc)(GObj*), s32 link, s32 dllink, Gfx* dlist);
GObj* func_800A86A4(void (*procFunc)(GObj*), s32 link, s32 dllink, Gfx* dlist);
GObj* func_800A9F10(void (*procFunc)(GObj*), s32 link, Sprite* sprite);
UnkStruct800BEDF8* func_800AA38C(s32);
UnkStruct800BEDF8* func_800AA740(s32);
void func_800AA85C(s32, s32);
void func_800AA870(s32);
void func_800AADF0(s32);
void func_800AAE28(void);
void func_800AAED0(s32);
s32 func_800AAEE8(s32);
void func_800AAF10(void);
void func_800AAF20(void);
s32 func_800AB41C(s32, u32, u32, s32);
s32 func_800AB700(s32, u32, u32, s32);
void func_800AB918(s32);
s32 func_800AB9A4(void);
void func_800ABB4C(u8 flags);
u8 func_800ABB68(void);
void func_800ABB94(void);
void func_800BFB90_5CA30(s32, s32);
void func_800BFC18_5CAB8(s32*, s32*);
s32 func_800BF244_5C0E4(void);
bool func_800BF3D4_5C274(s32);
char* getPlayerName(void);
void setPlayerName(PlayerName*);
PhotoData* func_800BF574_5C414(s32);
void func_800BF5D8_5C478(s32, PhotoData*);
PhotoData* func_800BF710_5C5B0(s32);
void func_800BF780_5C620(s32);
s32 func_800BF818_5C6B8(s32);
s32 func_800BF864_5C704(void);
PhotoData* func_800BF8BC_5C75C(s32);
s32 getAlbumCapacity(void);
PhotoData* getAlbumPhoto(s32);
void func_800BFABC_5C95C(PhotoData*, s32, s32, s32);
s32 func_800BFC5C_5CAFC(void);
void func_800BFC70_5CB10(s32 arg0);
s32 checkPlayerFlag(s32 pfid);
void setPlayerFlag(s32, s32);
s32 func_800C0290_5D130(void);
void func_800C02A0_5D140(s32);
void func_800C0314_5D1B4(s32, s32);
s32 func_800C042C_5D2CC(void);
s32 func_800C05D4_5D474(void);
void func_800C0B48_5D9E8(void);
s32 func_800C1BBC_5EA5C(void);
s32 func_oaks_lab_800E1AD8(s32);
void func_800E1C5C_AA0A0C(void);
s32 menu_new_game_entry(s32);
s32 func_800E4830_A0BDC0(s32);

s32 func_credits_801DCB24(s32);
void func_801DCBF4_98C664(void);
s32 func_801DCC74_98C6E4(s32);
s32 func_801DCC74_9D35E4(s32);
s32 album_Start(s32);
s32 func_801DD09C_A08C8C(s32);
s32 func_801DD010_AA2050(s32);
void func_801DD2D4_98CD44(s32 arg0);
GObj* func_801DD720_98D190(s32 idx);
s32 func_801E4510_993F80(void);
void func_801E4E04_994874(void);

s32 func_802BE3B0_640860(s32);

s32 func_beach_802C4740(s32);
s32 func_802C6544_79FAD4(s32);

s32 func_802D9210_6C0FF0(s32);

s32 func_802E2BB8_5DFC88(s32);

s32 func_80346EF0_826660(s32);

void bindCameraNextBlock(f32, f32, f32);
void setBackgroundMusic(s32);
void func_80356FBC_4F73CC(void);
void getLevelProgress(s32* blockCount, f32* blockPart);
void removeMainCamera(void);
OMCamera* getMainCamera(void);
void PokemonDetector_Disable(void);

void func_80363928_503D38(s32 minObjId, s32 maxObjId, s32 link, s32 arg3);
void pokemonsChangeBlock(struct WorldBlock*, struct WorldBlock*, PokemonDef*);
void pokemonRemove(struct WorldBlock*, PokemonDef*);
void func_803643E0_5047F0(OMCamera* cam);
s32 func_80364718_504B28(GObj* obj);
s32 func_803647BC_504BCC(GObj*);
void EnvSound_Cleanup(void);

#endif
