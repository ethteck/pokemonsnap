#include "common.h"

extern Gfx haunter_hd_part0_draw[];

__ALIGNER
u8 haunter_tex_hd_8019B6B8[] = {
#include "assets/tunnel/haunter/tex_hd_8019B6B8.png.bin.c"
};

__ALIGNER
u8 haunter_tex_hd_8019B8C0[] = {
#include "assets/tunnel/haunter/tex_hd_8019B8C0.png.bin.c"
};

__ALIGNER
u8 haunter_tex_hd_8019C8C8[] = {
#include "assets/tunnel/haunter/tex_hd_8019C8C8.png.bin.c"
};

__ALIGNER
u8 haunter_tex_hd_8019D8D0[] = {
#include "assets/tunnel/haunter/tex_hd_8019D8D0.png.bin.c"
};

__ALIGNER
u8 haunter_tex_hd_8019E8D8[] = {
#include "assets/tunnel/haunter/tex_hd_8019E8D8.png.bin.c"
};

__ALIGNER
u8 haunter_tex_hd_8019F8E0[] = {
#include "assets/tunnel/haunter/tex_hd_8019F8E0.png.bin.c"
};

__ALIGNER
u8 haunter_tex_hd_8019F908[] = {
#include "assets/tunnel/haunter/tex_hd_8019F908.png.bin.c"
};

__ALIGNER
u8 haunter_tex_hd_801A0910[] = {
#include "assets/tunnel/haunter/tex_hd_801A0910.png.bin.c"
};

__ALIGNER
u8 haunter_tex_hd_801A1918[] = {
#include "assets/tunnel/haunter/tex_hd_801A1918.png.bin.c"
};

#include "assets/tunnel/haunter/hd_model.vtx.inc.c"
#include "assets/tunnel/haunter/hd_first.gfx.inc.c"
#include "assets/tunnel/haunter/hd_part0_draw.gfx.inc.c"
#include "assets/tunnel/haunter/hd_part1_pre.gfx.inc.c"
#include "assets/tunnel/haunter/hd_part1_draw.gfx.inc.c"
#include "assets/tunnel/haunter/hd_part2_pre.gfx.inc.c"
#include "assets/tunnel/haunter/hd_part2_draw.gfx.inc.c"
#include "assets/tunnel/haunter/hd_part3_pre.gfx.inc.c"
#include "assets/tunnel/haunter/hd_part3_draw.gfx.inc.c"
#include "assets/tunnel/haunter/hd_part4_draw.gfx.inc.c"
#include "assets/tunnel/haunter/hd_part5_draw.gfx.inc.c"
#include "assets/tunnel/haunter/hd_part6_draw.gfx.inc.c"
#include "assets/tunnel/haunter/hd_part7_pre.gfx.inc.c"
#include "assets/tunnel/haunter/hd_part7_draw.gfx.inc.c"
#include "assets/tunnel/haunter/hd_part8_draw.gfx.inc.c"
#include "assets/tunnel/haunter/hd_part9_draw.gfx.inc.c"
#include "assets/tunnel/haunter/hd_part10_pre.gfx.inc.c"
#include "assets/tunnel/haunter/hd_part10_draw.gfx.inc.c"
#include "assets/tunnel/haunter/hd_part11_pre.gfx.inc.c"
#include "assets/tunnel/haunter/hd_part11_draw.gfx.inc.c"
#include "assets/tunnel/haunter/hd_part12_pre.gfx.inc.c"
#include "assets/tunnel/haunter/hd_part12_draw.gfx.inc.c"
#include "assets/tunnel/haunter/hd_part13_pre.gfx.inc.c"
#include "assets/tunnel/haunter/hd_part13_draw.gfx.inc.c"
#include "assets/tunnel/haunter/hd_part14_draw.gfx.inc.c"
#include "assets/tunnel/haunter/hd_part15_pre.gfx.inc.c"
#include "assets/tunnel/haunter/hd_part15_draw.gfx.inc.c"
#include "assets/tunnel/haunter/hd_part16_draw.gfx.inc.c"
#include "assets/tunnel/haunter/hd_part17_pre.gfx.inc.c"
#include "assets/tunnel/haunter/hd_part17_draw.gfx.inc.c"
#include "assets/tunnel/haunter/hd_part18_draw.gfx.inc.c"
#include "assets/tunnel/haunter/hd_part19_pre.gfx.inc.c"
#include "assets/tunnel/haunter/hd_part19_draw.gfx.inc.c"
#include "assets/tunnel/haunter/hd_part20_draw.gfx.inc.c"
#include "assets/tunnel/haunter/hd_part21_draw.gfx.inc.c"
#include "assets/tunnel/haunter/hd_part22_pre.gfx.inc.c"
#include "assets/tunnel/haunter/hd_part22_draw.gfx.inc.c"
#include "assets/tunnel/haunter/hd_part23_draw.gfx.inc.c"
#include "assets/tunnel/haunter/hd_part24_pre.gfx.inc.c"
#include "assets/tunnel/haunter/hd_part24_draw.gfx.inc.c"
#include "assets/tunnel/haunter/hd_part25_draw.gfx.inc.c"
#include "assets/tunnel/haunter/hd_part26_pre.gfx.inc.c"
#include "assets/tunnel/haunter/hd_part26_draw.gfx.inc.c"
#include "assets/tunnel/haunter/hd_part27_draw.gfx.inc.c"

DObjPayloadTypeI haunter_hd_gfxdata[] = {
    { NULL, haunter_hd_first },
    { haunter_hd_part1_pre, haunter_hd_part1_draw },
    { haunter_hd_part2_pre, haunter_hd_part2_draw },
    { haunter_hd_part3_pre, haunter_hd_part3_draw },
    { NULL, haunter_hd_part4_draw },
    { NULL, haunter_hd_part5_draw },
    { NULL, haunter_hd_part6_draw },
    { haunter_hd_part7_pre, haunter_hd_part7_draw },
    { NULL, haunter_hd_part8_draw },
    { NULL, haunter_hd_part9_draw },
    { haunter_hd_part10_pre, haunter_hd_part10_draw },
    { haunter_hd_part11_pre, haunter_hd_part11_draw },
    { haunter_hd_part12_pre, haunter_hd_part12_draw },
    { haunter_hd_part13_pre, haunter_hd_part13_draw },
    { NULL, haunter_hd_part14_draw },
    { haunter_hd_part15_pre, haunter_hd_part15_draw },
    { NULL, haunter_hd_part16_draw },
    { haunter_hd_part17_pre, haunter_hd_part17_draw },
    { NULL, haunter_hd_part18_draw },
    { haunter_hd_part19_pre, haunter_hd_part19_draw },
    { NULL, haunter_hd_part20_draw },
    { NULL, haunter_hd_part21_draw },
    { haunter_hd_part22_pre, haunter_hd_part22_draw },
    { NULL, haunter_hd_part23_draw },
    { haunter_hd_part24_pre, haunter_hd_part24_draw },
    { NULL, haunter_hd_part25_draw },
    { haunter_hd_part26_pre, haunter_hd_part26_draw },
    { NULL, haunter_hd_part27_draw },
};

UnkEC64Arg3 haunter_hd_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &haunter_hd_gfxdata[0],
      { 0.0, 13.986921310424805, -0.0012039999710395932 },
      { 0.008035999722778797, 0.031557001173496246, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &haunter_hd_gfxdata[1],
      { -445.5500183105469, 461.78802490234375, -60.60594177246094 },
      { -0.0002690000110305846, 6.600000051548705e-05, 0.007542000152170658 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &haunter_hd_gfxdata[2],
      { 444.5999755859375, 468.0870666503906, -77.54595184326172 },
      { 0.0036619999445974827, -0.0002800000074785203, -0.009353999979794025 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &haunter_hd_gfxdata[3],
      { -0.008635999634861946, -118.74478149414062, 286.8546142578125 },
      { 0.0040790000930428505, 0.0, 0.0 },
      { 0.9997280240058899, 1.0, 1.0 } },
    { 3,
      &haunter_hd_gfxdata[4],
      { 0.0, -4.679656028747559, 13.806319236755371 },
      { 0.993340015411377, 0.0, 0.0 },
      { 1.0023750066757202, 1.0, 0.9962810277938843 } },
    { 4,
      &haunter_hd_gfxdata[5],
      { 0.0, -3.1979920864105225, 126.40042114257812 },
      { 0.02899100072681904, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &haunter_hd_gfxdata[6],
      { 0.0, -7.600318908691406, 127.99945068359375 },
      { 0.017156999558210373, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &haunter_hd_gfxdata[7],
      { 0.0, -304.5583801269531, -295.9149475097656 },
      { -0.0337739996612072, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &haunter_hd_gfxdata[8],
      { 0.0, -155.40017700195312, -300.0 },
      { -0.028970999643206596, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &haunter_hd_gfxdata[9],
      { 0.0, -159.5999755859375, -287.0 },
      { -0.038874998688697815, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &haunter_hd_gfxdata[10],
      { 565.2498779296875, 128.2196044921875, -110.7843246459961 },
      { -0.001475999946705997, -0.0005910000181756914, -0.0050039999186992645 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &haunter_hd_gfxdata[11],
      { 551.949951171875, -219.7643280029297, -171.10150146484375 },
      { -0.0008270000107586384, -0.003289999905973673, -0.00801400002092123 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &haunter_hd_gfxdata[12],
      { -555.7500610351562, 131.51646423339844, -124.75369262695312 },
      { 0.000678999989759177, 0.0019039999460801482, 0.00836899969726801 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &haunter_hd_gfxdata[13],
      { -544.3501586914062, -225.93768310546875, -183.1607208251953 },
      { 0.0, 0.00011899999663000926, 0.006525000091642141 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &haunter_hd_gfxdata[14],
      { -825.1290283203125, -712.7662353515625, -91.54348754882812 },
      { 0.2647410035133362, 3.138585090637207, 0.0034080001059919596 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &haunter_hd_gfxdata[15],
      { -152.37521362304688, 60.144187927246094, -309.7442626953125 },
      { -0.07867400348186493, -0.011006999760866165, 0.31024500727653503 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &haunter_hd_gfxdata[16],
      { -146.86724853515625, -35.78376770019531, -70.82901000976562 },
      { 0.1552789956331253, -0.2714259922504425, -0.2587690055370331 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &haunter_hd_gfxdata[17],
      { 1.3911720514297485, 113.4947280883789, -381.9764709472656 },
      { 0.22650699317455292, -0.13043899834156036, 0.08380399644374847 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &haunter_hd_gfxdata[18],
      { -9.499931335449219, 72.44987487792969, -218.9999542236328 },
      { -0.6442649960517883, 0.22493299841880798, 0.2697789967060089 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &haunter_hd_gfxdata[19],
      { 121.0805435180664, -10.581827163696289, -355.1956787109375 },
      { 0.25798800587654114, -0.029663000255823135, 0.36833998560905457 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &haunter_hd_gfxdata[20],
      { 64.04161071777344, -73.13050842285156, -224.23744201660156 },
      { -0.4019930064678192, 0.23167599737644196, -0.07774099707603455 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &haunter_hd_gfxdata[21],
      { 790.5907592773438, -720.8728637695312, 323.22943115234375 },
      { -0.25782498717308044, 0.0011249999515712261, -0.0011500000255182385 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &haunter_hd_gfxdata[22],
      { -152.3751678466797, 60.144187927246094, 309.7442321777344 },
      { 0.07772800326347351, 0.00891599990427494, 0.30379199981689453 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &haunter_hd_gfxdata[23],
      { -146.87001037597656, -35.779998779296875, 70.83000183105469 },
      { 0.07547599822282791, 0.4285829961299896, -0.20314399898052216 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &haunter_hd_gfxdata[24],
      { 1.391219973564148, 113.49468231201172, 381.9763488769531 },
      { -0.22264499962329865, 0.13038000464439392, 0.08229800313711166 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &haunter_hd_gfxdata[25],
      { -9.811639785766602, 72.42851257324219, 219.47149658203125 },
      { 0.5078340172767639, -0.00028899998869746923, -0.00028700000257231295 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &haunter_hd_gfxdata[26],
      { 121.0806884765625, -10.58192253112793, 355.1956481933594 },
      { -0.25270000100135803, 0.02520100027322769, 0.36914101243019104 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &haunter_hd_gfxdata[27],
      { 63.43000030517578, -73.73999786376953, 223.42999267578125 },
      { 0.4540649950504303, -0.3316890001296997, -0.5148950219154358 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
