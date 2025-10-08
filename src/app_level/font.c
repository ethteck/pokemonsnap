#include "common.h"

#define __ALIGNER_DF static u8 __CONCAT2__(aligner, __LINE__)[] = { 0xDF, 0, 0, 0, 0, 0, 0, 0 };

__ALIGNER_DF
u8 font_btn_z[] = {
#include "assets/app_level/font/btn_z.png.bin.c"
};

__ALIGNER_DF
u8 font_btn_z_pressed[] = {
#include "assets/app_level/font/btn_z_pressed.png.bin.c"
};

__ALIGNER_DF
u8 font_btn_r[] = {
#include "assets/app_level/font/btn_r.png.bin.c"
};

__ALIGNER_DF
u8 font_btn_r_pressed[] = {
#include "assets/app_level/font/btn_r_pressed.png.bin.c"
};

__ALIGNER_DF
u8 font_page[] = {
#include "assets/app_level/font/page.png.bin.c"
};

__ALIGNER_DF
u8 font_page_folded[] = {
#include "assets/app_level/font/page_folded.png.bin.c"
};

__ALIGNER_DF
u8 font_btn_a[] = {
#include "assets/app_level/font/btn_a.png.bin.c"
};

__ALIGNER_DF
u8 font_btn_a_pressed[] = {
#include "assets/app_level/font/btn_a_pressed.png.bin.c"
};

__ALIGNER_DF
u8 font_btn_b[] = {
#include "assets/app_level/font/btn_b.png.bin.c"
};

__ALIGNER_DF
u8 font_btn_b_pressed[] = {
#include "assets/app_level/font/btn_b_pressed.png.bin.c"
};

__ALIGNER_DF
u8 font_new_l[] = {
#include "assets/app_level/font/new_l.png.bin.c"
};

__ALIGNER_DF
u8 font_new_r[] = {
#include "assets/app_level/font/new_r.png.bin.c"
};

__ALIGNER_DF
u8 font_new_l_alt[] = {
#include "assets/app_level/font/new_l_alt.png.bin.c"
};

__ALIGNER_DF
u8 font_new_r_alt[] = {
#include "assets/app_level/font/new_r_alt.png.bin.c"
};

__ALIGNER_DF
u8 font_52BFD8[] = {
#include "assets/app_level/font/52BFD8.png.bin.c"
};

__ALIGNER_DF
u8 font_52C180[] = {
#include "assets/app_level/font/52C180.png.bin.c"
};

Bitmap font_rgb_bitmaps[] = {
    { 13, 16, 0, 0, &font_btn_z, 13, 0 },
    { 13, 16, 0, 0, &font_btn_z_pressed, 13, 0 },
    { 13, 16, 0, 0, &font_btn_r, 13, 0 },
    { 13, 16, 0, 0, &font_btn_r_pressed, 13, 0 },
    { 13, 16, 0, 0, &font_page, 13, 0 },
    { 13, 16, 0, 0, &font_page_folded, 13, 0 },
    { 13, 16, 0, 0, &font_btn_a, 13, 0 },
    { 13, 16, 0, 0, &font_btn_a_pressed, 13, 0 },
    { 13, 16, 0, 0, &font_btn_b, 13, 0 },
    { 13, 16, 0, 0, &font_btn_b_pressed, 13, 0 },
    { 13, 16, 0, 0, &font_new_l, 13, 0 },
    { 13, 16, 0, 0, &font_new_r, 13, 0 },
    { 13, 16, 0, 0, &font_new_l_alt, 13, 0 },
    { 13, 16, 0, 0, &font_new_r_alt, 13, 0 },
    { 13, 16, 0, 0, &font_52BFD8, 13, 0 },
    { 13, 16, 0, 0, &font_52C180, 13, 0 },
};

Sprite rgb_sprites = {
    0,
    0,
    208,
    13,
    1.0f,
    1.0f,
    0,
    0,
    0x228,
    0x1234,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0,
    0,
    0,
    0,
    1,
    0x10,
    0xD8,
    13,
    13,
    0,
    2,
    font_rgb_bitmaps,
    (void*) 0x803B1560,
    0,
    0,
    0,
};

u32 pad_0 = 0;

__ALIGNER_DF
u8 font_upper_a[] = {
#include "assets/app_level/font/upper_a.png.bin.c"
};

__ALIGNER_DF
u8 font_upper_b[] = {
#include "assets/app_level/font/upper_b.png.bin.c"
};

__ALIGNER_DF
u8 font_upper_c[] = {
#include "assets/app_level/font/upper_c.png.bin.c"
};

__ALIGNER_DF
u8 font_upper_d[] = {
#include "assets/app_level/font/upper_d.png.bin.c"
};

__ALIGNER_DF
u8 font_upper_e[] = {
#include "assets/app_level/font/upper_e.png.bin.c"
};

__ALIGNER_DF
u8 font_upper_f[] = {
#include "assets/app_level/font/upper_f.png.bin.c"
};

__ALIGNER_DF
u8 font_upper_g[] = {
#include "assets/app_level/font/upper_g.png.bin.c"
};

__ALIGNER_DF
u8 font_upper_h[] = {
#include "assets/app_level/font/upper_h.png.bin.c"
};

__ALIGNER_DF
u8 font_upper_i[] = {
#include "assets/app_level/font/upper_i.png.bin.c"
};

__ALIGNER_DF
u8 font_upper_j[] = {
#include "assets/app_level/font/upper_j.png.bin.c"
};

__ALIGNER_DF
u8 font_upper_k[] = {
#include "assets/app_level/font/upper_k.png.bin.c"
};

__ALIGNER_DF
u8 font_upper_l[] = {
#include "assets/app_level/font/upper_l.png.bin.c"
};

__ALIGNER_DF
u8 font_upper_m[] = {
#include "assets/app_level/font/upper_m.png.bin.c"
};

__ALIGNER_DF
u8 font_upper_n[] = {
#include "assets/app_level/font/upper_n.png.bin.c"
};

__ALIGNER_DF
u8 font_upper_o[] = {
#include "assets/app_level/font/upper_o.png.bin.c"
};

__ALIGNER_DF
u8 font_upper_p[] = {
#include "assets/app_level/font/upper_p.png.bin.c"
};

__ALIGNER_DF
u8 font_upper_q[] = {
#include "assets/app_level/font/upper_q.png.bin.c"
};

__ALIGNER_DF
u8 font_upper_r[] = {
#include "assets/app_level/font/upper_r.png.bin.c"
};

__ALIGNER_DF
u8 font_upper_s[] = {
#include "assets/app_level/font/upper_s.png.bin.c"
};

__ALIGNER_DF
u8 font_upper_t[] = {
#include "assets/app_level/font/upper_t.png.bin.c"
};

__ALIGNER_DF
u8 font_upper_u[] = {
#include "assets/app_level/font/upper_u.png.bin.c"
};

__ALIGNER_DF
u8 font_upper_v[] = {
#include "assets/app_level/font/upper_v.png.bin.c"
};

__ALIGNER_DF
u8 font_upper_w[] = {
#include "assets/app_level/font/upper_w.png.bin.c"
};

__ALIGNER_DF
u8 font_upper_x[] = {
#include "assets/app_level/font/upper_x.png.bin.c"
};

__ALIGNER_DF
u8 font_upper_y[] = {
#include "assets/app_level/font/upper_y.png.bin.c"
};

__ALIGNER_DF
u8 font_upper_z[] = {
#include "assets/app_level/font/upper_z.png.bin.c"
};

__ALIGNER_DF
u8 font_lower_a[] = {
#include "assets/app_level/font/lower_a.png.bin.c"
};

__ALIGNER_DF
u8 font_lower_b[] = {
#include "assets/app_level/font/lower_b.png.bin.c"
};

__ALIGNER_DF
u8 font_lower_c[] = {
#include "assets/app_level/font/lower_c.png.bin.c"
};

__ALIGNER_DF
u8 font_lower_d[] = {
#include "assets/app_level/font/lower_d.png.bin.c"
};

__ALIGNER_DF
u8 font_lower_e[] = {
#include "assets/app_level/font/lower_e.png.bin.c"
};

__ALIGNER_DF
u8 font_lower_f[] = {
#include "assets/app_level/font/lower_f.png.bin.c"
};

__ALIGNER_DF
u8 font_lower_g[] = {
#include "assets/app_level/font/lower_g.png.bin.c"
};

__ALIGNER_DF
u8 font_lower_h[] = {
#include "assets/app_level/font/lower_h.png.bin.c"
};

__ALIGNER_DF
u8 font_lower_i[] = {
#include "assets/app_level/font/lower_i.png.bin.c"
};

__ALIGNER_DF
u8 font_lower_j[] = {
#include "assets/app_level/font/lower_j.png.bin.c"
};

__ALIGNER_DF
u8 font_lower_k[] = {
#include "assets/app_level/font/lower_k.png.bin.c"
};

__ALIGNER_DF
u8 font_lower_l[] = {
#include "assets/app_level/font/lower_l.png.bin.c"
};

__ALIGNER_DF
u8 font_lower_m[] = {
#include "assets/app_level/font/lower_m.png.bin.c"
};

__ALIGNER_DF
u8 font_lower_n[] = {
#include "assets/app_level/font/lower_n.png.bin.c"
};

__ALIGNER_DF
u8 font_lower_o[] = {
#include "assets/app_level/font/lower_o.png.bin.c"
};

__ALIGNER_DF
u8 font_lower_p[] = {
#include "assets/app_level/font/lower_p.png.bin.c"
};

__ALIGNER_DF
u8 font_lower_q[] = {
#include "assets/app_level/font/lower_q.png.bin.c"
};

__ALIGNER_DF
u8 font_lower_r[] = {
#include "assets/app_level/font/lower_r.png.bin.c"
};

__ALIGNER_DF
u8 font_lower_s[] = {
#include "assets/app_level/font/lower_s.png.bin.c"
};

__ALIGNER_DF
u8 font_lower_t[] = {
#include "assets/app_level/font/lower_t.png.bin.c"
};

__ALIGNER_DF
u8 font_lower_u[] = {
#include "assets/app_level/font/lower_u.png.bin.c"
};

__ALIGNER_DF
u8 font_lower_v[] = {
#include "assets/app_level/font/lower_v.png.bin.c"
};

__ALIGNER_DF
u8 font_lower_w[] = {
#include "assets/app_level/font/lower_w.png.bin.c"
};

__ALIGNER_DF
u8 font_lower_x[] = {
#include "assets/app_level/font/lower_x.png.bin.c"
};

__ALIGNER_DF
u8 font_lower_y[] = {
#include "assets/app_level/font/lower_y.png.bin.c"
};

__ALIGNER_DF
u8 font_lower_z[] = {
#include "assets/app_level/font/lower_z.png.bin.c"
};

__ALIGNER_DF
u8 font_numeral_1[] = {
#include "assets/app_level/font/numeral_1.png.bin.c"
};

__ALIGNER_DF
u8 font_numeral_2[] = {
#include "assets/app_level/font/numeral_2.png.bin.c"
};

__ALIGNER_DF
u8 font_numeral_3[] = {
#include "assets/app_level/font/numeral_3.png.bin.c"
};

__ALIGNER_DF
u8 font_numeral_4[] = {
#include "assets/app_level/font/numeral_4.png.bin.c"
};

__ALIGNER_DF
u8 font_numeral_5[] = {
#include "assets/app_level/font/numeral_5.png.bin.c"
};

__ALIGNER_DF
u8 font_numeral_6[] = {
#include "assets/app_level/font/numeral_6.png.bin.c"
};

__ALIGNER_DF
u8 font_numeral_7[] = {
#include "assets/app_level/font/numeral_7.png.bin.c"
};

__ALIGNER_DF
u8 font_numeral_8[] = {
#include "assets/app_level/font/numeral_8.png.bin.c"
};

__ALIGNER_DF
u8 font_numeral_9[] = {
#include "assets/app_level/font/numeral_9.png.bin.c"
};

__ALIGNER_DF
u8 font_numeral_0[] = {
#include "assets/app_level/font/numeral_0.png.bin.c"
};

__ALIGNER_DF
u8 font_arrowup[] = {
#include "assets/app_level/font/arrowup.png.bin.c"
};

__ALIGNER_DF
u8 font_arrowdown[] = {
#include "assets/app_level/font/arrowdown.png.bin.c"
};

__ALIGNER_DF
u8 font_52FA70[] = {
#include "assets/app_level/font/52FA70.png.bin.c"
};

__ALIGNER_DF
u8 font_asciitilde[] = {
#include "assets/app_level/font/asciitilde.png.bin.c"
};

__ALIGNER_DF
u8 font_exclam[] = {
#include "assets/app_level/font/exclam.png.bin.c"
};

__ALIGNER_DF
u8 font_at[] = {
#include "assets/app_level/font/at.png.bin.c"
};

__ALIGNER_DF
u8 font_numbersign[] = {
#include "assets/app_level/font/numbersign.png.bin.c"
};

__ALIGNER_DF
u8 font_dollar[] = {
#include "assets/app_level/font/dollar.png.bin.c"
};

__ALIGNER_DF
u8 font_percent[] = {
#include "assets/app_level/font/percent.png.bin.c"
};

__ALIGNER_DF
u8 font_ampersand[] = {
#include "assets/app_level/font/ampersand.png.bin.c"
};

__ALIGNER_DF
u8 font_asterisk[] = {
#include "assets/app_level/font/asterisk.png.bin.c"
};

__ALIGNER_DF
u8 font_parenleft[] = {
#include "assets/app_level/font/parenleft.png.bin.c"
};

__ALIGNER_DF
u8 font_parenright[] = {
#include "assets/app_level/font/parenright.png.bin.c"
};

__ALIGNER_DF
u8 font_underscore[] = {
#include "assets/app_level/font/underscore.png.bin.c"
};

__ALIGNER_DF
u8 font_plus[] = {
#include "assets/app_level/font/plus.png.bin.c"
};

__ALIGNER_DF
u8 font_equal[] = {
#include "assets/app_level/font/equal.png.bin.c"
};

__ALIGNER_DF
u8 font_hyphen[] = {
#include "assets/app_level/font/hyphen.png.bin.c"
};

__ALIGNER_DF
u8 font_quotesingle[] = {
#include "assets/app_level/font/quotesingle.png.bin.c"
};

__ALIGNER_DF
u8 font_quotedbl[] = {
#include "assets/app_level/font/quotedbl.png.bin.c"
};

__ALIGNER_DF
u8 font_semicolon[] = {
#include "assets/app_level/font/semicolon.png.bin.c"
};

__ALIGNER_DF
u8 font_colon[] = {
#include "assets/app_level/font/colon.png.bin.c"
};

__ALIGNER_DF
u8 font_slash[] = {
#include "assets/app_level/font/slash.png.bin.c"
};

__ALIGNER_DF
u8 font_period[] = {
#include "assets/app_level/font/period.png.bin.c"
};

__ALIGNER_DF
u8 font_comma[] = {
#include "assets/app_level/font/comma.png.bin.c"
};

__ALIGNER_DF
u8 font_question[] = {
#include "assets/app_level/font/question.png.bin.c"
};

__ALIGNER_DF
u8 font_less[] = {
#include "assets/app_level/font/less.png.bin.c"
};

__ALIGNER_DF
u8 font_greater[] = {
#include "assets/app_level/font/greater.png.bin.c"
};

__ALIGNER_DF
u8 font_male[] = {
#include "assets/app_level/font/male.png.bin.c"
};

__ALIGNER_DF
u8 font_female[] = {
#include "assets/app_level/font/female.png.bin.c"
};

__ALIGNER_DF
u8 font_PK[] = {
#include "assets/app_level/font/PK.png.bin.c"
};

__ALIGNER_DF
u8 font_MN[] = {
#include "assets/app_level/font/MN.png.bin.c"
};

__ALIGNER_DF
u8 font_pokedollar[] = {
#include "assets/app_level/font/pokedollar.png.bin.c"
};

__ALIGNER_DF
u8 font_bracketleft[] = {
#include "assets/app_level/font/bracketleft.png.bin.c"
};

__ALIGNER_DF
u8 font_bracketright[] = {
#include "assets/app_level/font/bracketright.png.bin.c"
};

__ALIGNER_DF
u8 font_eacute[] = {
#include "assets/app_level/font/eacute.png.bin.c"
};

__ALIGNER_DF
u8 font_arrowright[] = {
#include "assets/app_level/font/arrowright.png.bin.c"
};

__ALIGNER_DF
u8 font_arrowleft[] = {
#include "assets/app_level/font/arrowleft.png.bin.c"
};

__ALIGNER_DF
u8 font_5317F8[] = {
#include "assets/app_level/font/5317F8.png.bin.c"
};

__ALIGNER_DF
u8 font_5318D0[] = {
#include "assets/app_level/font/5318D0.png.bin.c"
};

__ALIGNER_DF
u8 font_5319A8[] = {
#include "assets/app_level/font/5319A8.png.bin.c"
};

__ALIGNER_DF
u8 font_531A80[] = {
#include "assets/app_level/font/531A80.png.bin.c"
};

__ALIGNER_DF
u8 font_531B58[] = {
#include "assets/app_level/font/531B58.png.bin.c"
};

__ALIGNER_DF
u8 font_531C30[] = {
#include "assets/app_level/font/531C30.png.bin.c"
};

__ALIGNER_DF
u8 font_531D08[] = {
#include "assets/app_level/font/531D08.png.bin.c"
};

__ALIGNER_DF
u8 font_531DE0[] = {
#include "assets/app_level/font/531DE0.png.bin.c"
};

__ALIGNER_DF
u8 font_531EB8[] = {
#include "assets/app_level/font/531EB8.png.bin.c"
};

__ALIGNER_DF
u8 font_531F90[] = {
#include "assets/app_level/font/531F90.png.bin.c"
};

__ALIGNER_DF
u8 font_532068[] = {
#include "assets/app_level/font/532068.png.bin.c"
};

__ALIGNER_DF
u8 font_532140[] = {
#include "assets/app_level/font/532140.png.bin.c"
};

__ALIGNER_DF
u8 font_532218[] = {
#include "assets/app_level/font/532218.png.bin.c"
};

__ALIGNER_DF
u8 font_5322F0[] = {
#include "assets/app_level/font/5322F0.png.bin.c"
};

__ALIGNER_DF
u8 font_5323C8[] = {
#include "assets/app_level/font/5323C8.png.bin.c"
};

__ALIGNER_DF
u8 font_5324A0[] = {
#include "assets/app_level/font/5324A0.png.bin.c"
};

__ALIGNER_DF
u8 font_532578[] = {
#include "assets/app_level/font/532578.png.bin.c"
};

__ALIGNER_DF
u8 font_532650[] = {
#include "assets/app_level/font/532650.png.bin.c"
};

__ALIGNER_DF
u8 font_532728[] = {
#include "assets/app_level/font/532728.png.bin.c"
};

__ALIGNER_DF
u8 font_532800[] = {
#include "assets/app_level/font/532800.png.bin.c"
};

__ALIGNER_DF
u8 font_5328D8[] = {
#include "assets/app_level/font/5328D8.png.bin.c"
};

__ALIGNER_DF
u8 font_5329B0[] = {
#include "assets/app_level/font/5329B0.png.bin.c"
};

__ALIGNER_DF
u8 font_532A88[] = {
#include "assets/app_level/font/532A88.png.bin.c"
};

__ALIGNER_DF
u8 font_532B60[] = {
#include "assets/app_level/font/532B60.png.bin.c"
};

__ALIGNER_DF
u8 font_532C38[] = {
#include "assets/app_level/font/532C38.png.bin.c"
};

__ALIGNER_DF
u8 font_532D10[] = {
#include "assets/app_level/font/532D10.png.bin.c"
};

__ALIGNER_DF
u8 font_532DE8[] = {
#include "assets/app_level/font/532DE8.png.bin.c"
};

__ALIGNER_DF
u8 font_532EC0[] = {
#include "assets/app_level/font/532EC0.png.bin.c"
};

__ALIGNER_DF
u8 font_532F98[] = {
#include "assets/app_level/font/532F98.png.bin.c"
};

__ALIGNER_DF
u8 font_533070[] = {
#include "assets/app_level/font/533070.png.bin.c"
};

__ALIGNER_DF
u8 font_533148[] = {
#include "assets/app_level/font/533148.png.bin.c"
};

Bitmap font_mono_bitmaps[] = {
    { 9, 16, 0, 0, &font_upper_a, 13, 0 },
    { 9, 16, 0, 0, &font_upper_b, 13, 0 },
    { 9, 16, 0, 0, &font_upper_c, 13, 0 },
    { 9, 16, 0, 0, &font_upper_d, 13, 0 },
    { 9, 16, 0, 0, &font_upper_e, 13, 0 },
    { 9, 16, 0, 0, &font_upper_f, 13, 0 },
    { 9, 16, 0, 0, &font_upper_g, 13, 0 },
    { 9, 16, 0, 0, &font_upper_h, 13, 0 },
    { 9, 16, 0, 0, &font_upper_i, 13, 0 },
    { 9, 16, 0, 0, &font_upper_j, 13, 0 },
    { 9, 16, 0, 0, &font_upper_k, 13, 0 },
    { 9, 16, 0, 0, &font_upper_l, 13, 0 },
    { 9, 16, 0, 0, &font_upper_m, 13, 0 },
    { 9, 16, 0, 0, &font_upper_n, 13, 0 },
    { 9, 16, 0, 0, &font_upper_o, 13, 0 },
    { 9, 16, 0, 0, &font_upper_p, 13, 0 },
    { 9, 16, 0, 0, &font_upper_q, 13, 0 },
    { 9, 16, 0, 0, &font_upper_r, 13, 0 },
    { 9, 16, 0, 0, &font_upper_s, 13, 0 },
    { 9, 16, 0, 0, &font_upper_t, 13, 0 },
    { 9, 16, 0, 0, &font_upper_u, 13, 0 },
    { 9, 16, 0, 0, &font_upper_v, 13, 0 },
    { 9, 16, 0, 0, &font_upper_w, 13, 0 },
    { 9, 16, 0, 0, &font_upper_x, 13, 0 },
    { 9, 16, 0, 0, &font_upper_y, 13, 0 },
    { 9, 16, 0, 0, &font_upper_z, 13, 0 },
    { 9, 16, 0, 0, &font_lower_a, 13, 0 },
    { 9, 16, 0, 0, &font_lower_b, 13, 0 },
    { 9, 16, 0, 0, &font_lower_c, 13, 0 },
    { 9, 16, 0, 0, &font_lower_d, 13, 0 },
    { 9, 16, 0, 0, &font_lower_e, 13, 0 },
    { 9, 16, 0, 0, &font_lower_f, 13, 0 },
    { 9, 16, 0, 0, &font_lower_g, 13, 0 },
    { 9, 16, 0, 0, &font_lower_h, 13, 0 },
    { 9, 16, 0, 0, &font_lower_i, 13, 0 },
    { 9, 16, 0, 0, &font_lower_j, 13, 0 },
    { 9, 16, 0, 0, &font_lower_k, 13, 0 },
    { 9, 16, 0, 0, &font_lower_l, 13, 0 },
    { 9, 16, 0, 0, &font_lower_m, 13, 0 },
    { 9, 16, 0, 0, &font_lower_n, 13, 0 },
    { 9, 16, 0, 0, &font_lower_o, 13, 0 },
    { 9, 16, 0, 0, &font_lower_p, 13, 0 },
    { 9, 16, 0, 0, &font_lower_q, 13, 0 },
    { 9, 16, 0, 0, &font_lower_r, 13, 0 },
    { 9, 16, 0, 0, &font_lower_s, 13, 0 },
    { 9, 16, 0, 0, &font_lower_t, 13, 0 },
    { 9, 16, 0, 0, &font_lower_u, 13, 0 },
    { 9, 16, 0, 0, &font_lower_v, 13, 0 },
    { 9, 16, 0, 0, &font_lower_w, 13, 0 },
    { 9, 16, 0, 0, &font_lower_x, 13, 0 },
    { 9, 16, 0, 0, &font_lower_y, 13, 0 },
    { 9, 16, 0, 0, &font_lower_z, 13, 0 },
    { 9, 16, 0, 0, &font_numeral_1, 13, 0 },
    { 9, 16, 0, 0, &font_numeral_2, 13, 0 },
    { 9, 16, 0, 0, &font_numeral_3, 13, 0 },
    { 9, 16, 0, 0, &font_numeral_4, 13, 0 },
    { 9, 16, 0, 0, &font_numeral_5, 13, 0 },
    { 9, 16, 0, 0, &font_numeral_6, 13, 0 },
    { 9, 16, 0, 0, &font_numeral_7, 13, 0 },
    { 9, 16, 0, 0, &font_numeral_8, 13, 0 },
    { 9, 16, 0, 0, &font_numeral_9, 13, 0 },
    { 9, 16, 0, 0, &font_numeral_0, 13, 0 },
    { 9, 16, 0, 0, &font_arrowup, 13, 0 },
    { 9, 16, 0, 0, &font_arrowdown, 13, 0 },
    { 9, 16, 0, 0, &font_52FA70, 13, 0 },
    { 9, 16, 0, 0, &font_asciitilde, 13, 0 },
    { 9, 16, 0, 0, &font_exclam, 13, 0 },
    { 9, 16, 0, 0, &font_at, 13, 0 },
    { 9, 16, 0, 0, &font_numbersign, 13, 0 },
    { 9, 16, 0, 0, &font_dollar, 13, 0 },
    { 9, 16, 0, 0, &font_percent, 13, 0 },
    { 9, 16, 0, 0, &font_ampersand, 13, 0 },
    { 9, 16, 0, 0, &font_asterisk, 13, 0 },
    { 9, 16, 0, 0, &font_parenleft, 13, 0 },
    { 9, 16, 0, 0, &font_parenright, 13, 0 },
    { 9, 16, 0, 0, &font_underscore, 13, 0 },
    { 9, 16, 0, 0, &font_plus, 13, 0 },
    { 9, 16, 0, 0, &font_equal, 13, 0 },
    { 9, 16, 0, 0, &font_hyphen, 13, 0 },
    { 9, 16, 0, 0, &font_quotesingle, 13, 0 },
    { 9, 16, 0, 0, &font_quotedbl, 13, 0 },
    { 9, 16, 0, 0, &font_semicolon, 13, 0 },
    { 9, 16, 0, 0, &font_colon, 13, 0 },
    { 9, 16, 0, 0, &font_slash, 13, 0 },
    { 9, 16, 0, 0, &font_period, 13, 0 },
    { 9, 16, 0, 0, &font_comma, 13, 0 },
    { 9, 16, 0, 0, &font_question, 13, 0 },
    { 9, 16, 0, 0, &font_less, 13, 0 },
    { 9, 16, 0, 0, &font_greater, 13, 0 },
    { 9, 16, 0, 0, &font_male, 13, 0 },
    { 9, 16, 0, 0, &font_female, 13, 0 },
    { 9, 16, 0, 0, &font_PK, 13, 0 },
    { 9, 16, 0, 0, &font_MN, 13, 0 },
    { 9, 16, 0, 0, &font_pokedollar, 13, 0 },
    { 9, 16, 0, 0, &font_bracketleft, 13, 0 },
    { 9, 16, 0, 0, &font_bracketright, 13, 0 },
    { 9, 16, 0, 0, &font_eacute, 13, 0 },
    { 9, 16, 0, 0, &font_arrowright, 13, 0 },
    { 9, 16, 0, 0, &font_arrowleft, 13, 0 },
    { 9, 16, 0, 0, &font_5317F8, 13, 0 },
    { 9, 16, 0, 0, &font_5318D0, 13, 0 },
    { 9, 16, 0, 0, &font_5319A8, 13, 0 },
    { 9, 16, 0, 0, &font_531A80, 13, 0 },
    { 9, 16, 0, 0, &font_531B58, 13, 0 },
    { 9, 16, 0, 0, &font_531C30, 13, 0 },
    { 9, 16, 0, 0, &font_531D08, 13, 0 },
    { 9, 16, 0, 0, &font_531DE0, 13, 0 },
    { 9, 16, 0, 0, &font_531EB8, 13, 0 },
    { 9, 16, 0, 0, &font_531F90, 13, 0 },
    { 9, 16, 0, 0, &font_532068, 13, 0 },
    { 9, 16, 0, 0, &font_532140, 13, 0 },
    { 9, 16, 0, 0, &font_532218, 13, 0 },
    { 9, 16, 0, 0, &font_5322F0, 13, 0 },
    { 9, 16, 0, 0, &font_5323C8, 13, 0 },
    { 9, 16, 0, 0, &font_5324A0, 13, 0 },
    { 9, 16, 0, 0, &font_532578, 13, 0 },
    { 9, 16, 0, 0, &font_532650, 13, 0 },
    { 9, 16, 0, 0, &font_532728, 13, 0 },
    { 9, 16, 0, 0, &font_532800, 13, 0 },
    { 9, 16, 0, 0, &font_5328D8, 13, 0 },
    { 9, 16, 0, 0, &font_5329B0, 13, 0 },
    { 9, 16, 0, 0, &font_532A88, 13, 0 },
    { 9, 16, 0, 0, &font_532B60, 13, 0 },
    { 9, 16, 0, 0, &font_532C38, 13, 0 },
    { 9, 16, 0, 0, &font_532D10, 13, 0 },
    { 9, 16, 0, 0, &font_532DE8, 13, 0 },
    { 9, 16, 0, 0, &font_532EC0, 13, 0 },
    { 9, 16, 0, 0, &font_532F98, 13, 0 },
    { 9, 16, 0, 0, &font_533070, 13, 0 },
    { 9, 16, 0, 0, &font_533148, 13, 0 },
};

Sprite mono_sprites = {
    0,
    0,
    117,
    130,
    1.0f,
    1.0f,
    0,
    0,
    0x0228,
    0x1234,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0,
    0,
    0,
    0,
    1,
    0x82,
    0x0630,
    13,
    13,
    4,
    1,
    font_mono_bitmaps,
    (void*) 0x803B1C20,
    0,
    0,
    0
};

u32 Msg_CameraObject = 0;
u32 Msg_PosX = 0;
u32 Msg_PosY = 0;
u32 Msg_PrintDelay = 0;
u32 Msg_MessageLength = 0;
u8 Msg_TextColorR = 0xFF;
u8 Msg_TextColorG = 0xFF;
u8 Msg_TextColorB = 0xFF;
u8 Msg_TextColorA = 0xFF;
u32 Msg_LineSpacing = 4;
u32 Msg_IsInteractive = 0;
u32 Msg_IsPrinted = 0;
u32 Msg_ShadowEnabled = 1;
u32 Msg_BlinkEnabled = 0;
f32 Msg_BlinkAlpha = 1.0f;
u32 Msg_BlinkState = 0;
f32 Message_ScaleX = 1.0f;
f32 Message_ScaleY = 1.0f;
u32 Msg_SpecialHandler = 0;

u8 D_803936B8_533AC8[] = {
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0xFF,
    0x40,
    0x42,
    0x50,
    0x44,
    0x45,
    0x46,
    0x47,
    0x4F,
    0x49,
    0x4A,
    0x48,
    0x4C,
    0x55,
    0x4E,
    0x54,
    0x53,
    0x3D,
    0x34,
    0x35,
    0x36,
    0x37,
    0x38,
    0x39,
    0x3A,
    0x3B,
    0x3C,
    0x52,
    0x51,
    0x57,
    0x4D,
    0x58,
    0x56,
    0x43,
    0x00,
    0x01,
    0x02,
    0x03,
    0x04,
    0x05,
    0x06,
    0x07,
    0x08,
    0x09,
    0x0A,
    0x0B,
    0x0C,
    0x0D,
    0x0E,
    0x0F,
    0x10,
    0x11,
    0x12,
    0x13,
    0x14,
    0x15,
    0x16,
    0x17,
    0x18,
    0x19,
    0x5E,
    0x5F,
    0xFF,
    0xFF,
    0x4B,
    0xFF,
    0x1A,
    0x1B,
    0x1C,
    0x1D,
    0x1E,
    0x1F,
    0x20,
    0x21,
    0x22,
    0x23,
    0x24,
    0x25,
    0x26,
    0x27,
    0x28,
    0x29,
    0x2A,
    0x2B,
    0x2C,
    0x2D,
    0x2E,
    0x2F,
    0x30,
    0x31,
    0x32,
    0x33,
    0xFF,
    0xFF,
    0xFF,
    0x41,
    0xFF,
};

u8 D_80393738_533B48[] = {
    0x08,
    0x07,
    0x08,
    0x08,
    0x07,
    0x07,
    0x07,
    0x07,
    0x05,
    0x08,
    0x07,
    0x06,
    0x08,
    0x08,
    0x08,
    0x07,
    0x08,
    0x07,
    0x06,
    0x08,
    0x08,
    0x08,
    0x08,
    0x08,
    0x08,
    0x07,
    0x07,
    0x06,
    0x05,
    0x06,
    0x06,
    0x06,
    0x05,
    0x06,
    0x02,
    0x04,
    0x05,
    0x02,
    0x08,
    0x06,
    0x06,
    0x05,
    0x06,
    0x05,
    0x04,
    0x06,
    0x06,
    0x06,
    0x07,
    0x05,
    0x06,
    0x06,
    0x03,
    0x07,
    0x08,
    0x08,
    0x07,
    0x06,
    0x07,
    0x06,
    0x06,
    0x08,
    0x08,
    0x08,
    0x08,
    0x03,
    0x08,
    0x08,
    0x06,
    0x08,
    0x07,
    0x08,
    0x04,
    0x04,
    0x06,
    0x08,
    0x05,
    0x05,
    0x02,
    0x05,
    0x02,
    0x02,
    0x05,
    0x02,
    0x02,
    0x06,
    0x05,
    0x05,
    0x08,
    0x07,
    0x08,
    0x08,
    0x08,
    0x04,
    0x04,
    0x06,
    0x08,
    0x07,
    0x00,
    0x00,
};

s16 D_8039379C_533BAC[] = {
    0xA2A5,
    0xA2A7,
    0xA1A1,
    0xA1C1,
    0xA1AA,
    0xA1F7,
    0xA1F4,
    0xA1F0,
    0xA1F3,
    0xA1F5,
    0xA1F6,
    0xA1CA,
    0xA1CB,
    0xA1B2,
    0xA1DC,
    0xA1E1,
    0xA1BC,
    0xA1C7,
    0xA1C9,
    0xA1A8,
    0xA1A7,
    0xA1BF,
    0xA1A5,
    0xA1A4,
    0xA1A9,
    0xA1E3,
    0xA1E4,
    0xA1E9,
    0xA1EA,
    0xA2F7,
    0xA2F8,
    0xA2F9,
    0xA1CE,
    0xA1CF,
    0xA6C5,
    0xA2AA,
    0xA2AB,
    0x0000,
};

u32 Msg_FrameCounter = 0;
