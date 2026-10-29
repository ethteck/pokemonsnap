#ifndef _OAKS_LAB_H
#define _OAKS_LAB_H

#include "../window/window.h"

// Data
extern Sprite lab_bg_sprite;
extern Sprite lab_oak_sprite;
extern Sprite lab_screen_sprite;
extern Sprite lab_save_error_sprite;
extern Bitmap lab_stage_tunnel_bitmaps[];
extern Bitmap lab_stage_river_bitmaps[];
extern Bitmap lab_stage_cave_bitmaps[];
extern Bitmap map_stage_rainbow_cloud_bitmaps[];
extern Bitmap lab_stage_valley_bitmaps[];
extern Bitmap lab_stage_beach_bitmaps[];
extern Sprite lab_stage_beach_sprite;
extern Bitmap lab_stage_vulcano_bitmaps[];
extern Bitmap lab_screen_album_bitmaps[]; // Report
extern Bitmap lab_screen_island_bitmaps[];
extern Bitmap lab_screen_zero_one_bitmaps[];
extern Bitmap lab_screen_end_gate_bitmaps[];
extern Bitmap lab_screen_engine_bitmaps[];
extern Bitmap lab_screen_apple_bitmaps[];
extern Sprite lab_screen_apple_sprite;
extern Bitmap lab_screen_pester_ball_bitmaps[];
extern Bitmap lab_screen_pokeflute_bitmaps[];
extern Bitmap lab_oak_mouth_0_bitmaps[];
extern Sprite lab_oak_mouth_0_sprite;
extern Bitmap lab_oak_mouth_1_bitmaps[];
extern Bitmap lab_oak_mouth_2_bitmaps[];
extern Bitmap lab_oak_mouth_3_bitmaps[];
extern Bitmap lab_oak_mouth_4_bitmaps[];
extern Bitmap lab_oak_mouth_5_bitmaps[];
extern Bitmap lab_oak_mouth_6_bitmaps[];
extern Sprite lab_oak_mouth_6_sprite;
extern Bitmap lab_oak_eyes_0_bitmaps[];
extern Bitmap lab_oak_eyes_1_bitmaps[];
extern Bitmap lab_oak_eyes_4_bitmaps[];
extern Bitmap lab_oak_eyes_5_bitmaps[];
extern Bitmap lab_oak_eyes_6_bitmaps[];
extern Bitmap lab_oak_eyes_9_bitmaps[];
extern Bitmap lab_oak_eyes_10_bitmaps[];
extern Bitmap lab_oak_eyes_11_bitmaps[];
extern Bitmap lab_oak_eyes_12_bitmaps[];
extern Sprite map_bg_sprite;
extern s32 D_80195850_95B070;
extern char* D_80195888_95B0A8[];
extern s32 D_80195894_95B0B4;
extern s32 D_801958C0_95B0E0;
extern s32 D_801958F0_95B110;
extern UIButton* D_80195CEC_95B50C[];
extern Sprite map_zero_one_9_sprite;
extern Sprite map_todd_14_sprite;
extern Sprite map_todd_17_sprite;
extern Sprite map_todd_23_sprite;
extern Sprite map_zero_one_10_sprite;
extern Sprite map_zero_one_16_sprite;
extern Sprite map_rainbow_cloud_sprite;
extern Sprite map_oak_0_sprite;
extern Sprite map_oak_3_sprite;
extern Bitmap* D_801C5474_98AC94[4];
extern Bitmap* D_801C5484_98ACA4[4];
extern s32 D_801C550C_98AD2C;
extern s32 D_801C5510_98AD30;
extern s32 D_801C5514_98AD34;
extern s32 D_801C5518_98AD38;
extern s32 D_801C551C_98AD3C;
extern s32 D_801C5520_98AD40;

// BSS
extern u8 D_801C6B10_98C330[0x40000];
extern SObj* D_80206B10_9CC330;
extern SObj* D_80206B14_9CC334;
extern SObj* D_80206B18_9CC338;
extern UIElement* D_80206B1C_9CC33C;
extern UIFrame* D_80206B20_9CC340;
extern SObj* D_80206B28_9CC348[];
extern SObj* D_80206B30_9CC350;
extern void* D_80206B40_9CC360;
extern UIButton* D_80206B44_9CC364;
extern void (*D_80206B48_9CC368)(void);
extern s32 D_80206B50_9CC370;
extern SObj* D_80206B60_9CC380;
extern SObj* D_80206B64_9CC384;
extern SObj* D_80206B68_9CC388;
extern SObj* D_80206B6C_9CC38C;
extern SObj* D_80206B70_9CC390;
extern SObj* D_80206B74_9CC394;
extern SObj* D_80206B78_9CC398;
extern SObj* D_80206B7C_9CC39C;
extern SObj* D_80206B80_9CC3A0;
extern u8 D_80206B90[];

void func_800E1A60_8A7280(void);
UIElement* func_800E1B40_8A7360(void);
UIFrame* func_800E1B4C_8A736C(void);
void func_800E1BF4_8A7414(u32 intensity);
void func_800E1C18_8A7438(s32);
void func_800E1CA0_8A74C0(GObj*);
void func_800E1D1C_8A753C(s32 arg0);
void func_800E1D68_8A7588(u32 arg0);
void func_800E1FEC_8A780C(s32);
void func_800E2058_8A7878(GObj*);
void func_800E235C_8A7B7C(s32);
void func_800E2848_8A8068(void);
void func_800E2A04_8A8224(void);
void func_800E2C0C_8A842C(GObj*);
void func_800E307C_8A889C(void);
void func_800E30B8_8A88D8(void);
void func_800E3190_8A89B0(void);
void* func_800E3230_8A8A50(void);
s32 func_800E3404_8A8C24(void);
s32 func_800E4578_8A9D98(UIElement*, char**, s32, bool);
s32 func_800E510C_8AA92C(void);
void func_800E58D0_8AB0F0(GObj*);
void func_800E5EBC_8AB6DC(void);
void func_800E5EF8_8AB718(GObj*);
void func_800E60C8_8AB8E8(void);
void func_800E60D8_8AB8F8(s32);
void func_800E614C_8AB96C(s32);
void func_800E61B4_8AB9D4(s32, s32);
s32 func_800E6404_8ABC24(void);
void func_800E66B8_8ABED8(void);

#endif
