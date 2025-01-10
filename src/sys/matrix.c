#include "common.h"

#define COMBINE_INTEGRAL(a, b) (((a) & 0xffff0000) | (((b) >> 16)))
#define COMBINE_FRACTIONAL(a, b) (((a) << 16)) | ((b) & 0xffff)

#define F_PI ((f32) M_PI) // M_PI is a double, we want it as a single float.
#define HALF_PI (F_PI / 2.0f)

u16 sSinTable[] = {
    0, 50, 100, 150, 201, 251, 301, 351,
    402, 452, 502, 552, 603, 653, 703, 753,
    804, 854, 904, 954, 1005, 1055, 1105, 1155,
    1206, 1256, 1306, 1356, 1407, 1457, 1507, 1557,
    1607, 1658, 1708, 1758, 1808, 1858, 1909, 1959,
    2009, 2059, 2109, 2159, 2210, 2260, 2310, 2360,
    2410, 2460, 2510, 2560, 2611, 2661, 2711, 2761,
    2811, 2861, 2911, 2961, 3011, 3061, 3111, 3161,
    3211, 3261, 3311, 3361, 3411, 3461, 3511, 3561,
    3611, 3661, 3711, 3761, 3811, 3861, 3911, 3961,
    4011, 4061, 4110, 4160, 4210, 4260, 4310, 4360,
    4409, 4459, 4509, 4559, 4609, 4658, 4708, 4758,
    4808, 4857, 4907, 4957, 5006, 5056, 5106, 5155,
    5205, 5255, 5304, 5354, 5403, 5453, 5503, 5552,
    5602, 5651, 5701, 5750, 5800, 5849, 5898, 5948,
    5997, 6047, 6096, 6146, 6195, 6244, 6294, 6343,
    6392, 6442, 6491, 6540, 6589, 6639, 6688, 6737,
    6786, 6835, 6884, 6934, 6983, 7032, 7081, 7130,
    7179, 7228, 7277, 7326, 7375, 7424, 7473, 7522,
    7571, 7620, 7669, 7717, 7766, 7815, 7864, 7913,
    7961, 8010, 8059, 8108, 8156, 8205, 8254, 8302,
    8351, 8400, 8448, 8497, 8545, 8594, 8642, 8691,
    8739, 8788, 8836, 8884, 8933, 8981, 9029, 9078,
    9126, 9174, 9223, 9271, 9319, 9367, 9415, 9463,
    9512, 9560, 9608, 9656, 9704, 9752, 9800, 9848,
    9896, 9944, 9991, 10039, 10087, 10135, 10183, 10230,
    10278, 10326, 10374, 10421, 10469, 10517, 10564, 10612,
    10659, 10707, 10754, 10802, 10849, 10897, 10944, 10991,
    11039, 11086, 11133, 11181, 11228, 11275, 11322, 11369,
    11416, 11464, 11511, 11558, 11605, 11652, 11699, 11746,
    11793, 11839, 11886, 11933, 11980, 12027, 12073, 12120,
    12167, 12213, 12260, 12307, 12353, 12400, 12446, 12493,
    12539, 12586, 12632, 12678, 12725, 12771, 12817, 12864,
    12910, 12956, 13002, 13048, 13094, 13140, 13186, 13232,
    13278, 13324, 13370, 13416, 13462, 13508, 13554, 13599,
    13645, 13691, 13736, 13782, 13828, 13873, 13919, 13964,
    14010, 14055, 14100, 14146, 14191, 14236, 14282, 14327,
    14372, 14417, 14462, 14507, 14552, 14598, 14642, 14687,
    14732, 14777, 14822, 14867, 14912, 14956, 15001, 15046,
    15090, 15135, 15180, 15224, 15269, 15313, 15357, 15402,
    15446, 15491, 15535, 15579, 15623, 15667, 15712, 15756,
    15800, 15844, 15888, 15932, 15976, 16019, 16063, 16107,
    16151, 16195, 16238, 16282, 16325, 16369, 16413, 16456,
    16499, 16543, 16586, 16630, 16673, 16716, 16759, 16802,
    16846, 16889, 16932, 16975, 17018, 17061, 17104, 17146,
    17189, 17232, 17275, 17317, 17360, 17403, 17445, 17488,
    17530, 17573, 17615, 17658, 17700, 17742, 17784, 17827,
    17869, 17911, 17953, 17995, 18037, 18079, 18121, 18163,
    18204, 18246, 18288, 18330, 18371, 18413, 18454, 18496,
    18537, 18579, 18620, 18662, 18703, 18744, 18785, 18826,
    18868, 18909, 18950, 18991, 19032, 19073, 19113, 19154,
    19195, 19236, 19276, 19317, 19358, 19398, 19439, 19479,
    19519, 19560, 19600, 19640, 19681, 19721, 19761, 19801,
    19841, 19881, 19921, 19961, 20001, 20040, 20080, 20120,
    20159, 20199, 20239, 20278, 20318, 20357, 20396, 20436,
    20475, 20514, 20553, 20592, 20631, 20671, 20709, 20748,
    20787, 20826, 20865, 20904, 20942, 20981, 21020, 21058,
    21097, 21135, 21173, 21212, 21250, 21288, 21326, 21365,
    21403, 21441, 21479, 21517, 21555, 21592, 21630, 21668,
    21706, 21743, 21781, 21818, 21856, 21893, 21931, 21968,
    22005, 22042, 22080, 22117, 22154, 22191, 22228, 22265,
    22301, 22338, 22375, 22412, 22448, 22485, 22521, 22558,
    22594, 22631, 22667, 22703, 22740, 22776, 22812, 22848,
    22884, 22920, 22956, 22992, 23027, 23063, 23099, 23134,
    23170, 23205, 23241, 23276, 23312, 23347, 23382, 23417,
    23453, 23488, 23523, 23558, 23593, 23627, 23662, 23697,
    23732, 23766, 23801, 23835, 23870, 23904, 23939, 23973,
    24007, 24041, 24075, 24109, 24144, 24177, 24211, 24245,
    24279, 24313, 24346, 24380, 24414, 24447, 24480, 24514,
    24547, 24580, 24614, 24647, 24680, 24713, 24746, 24779,
    24812, 24845, 24877, 24910, 24943, 24975, 25008, 25040,
    25073, 25105, 25137, 25169, 25201, 25234, 25266, 25298,
    25330, 25361, 25393, 25425, 25457, 25488, 25520, 25551,
    25583, 25614, 25645, 25677, 25708, 25739, 25770, 25801,
    25832, 25863, 25894, 25925, 25955, 25986, 26016, 26047,
    26077, 26108, 26138, 26169, 26199, 26229, 26259, 26289,
    26319, 26349, 26379, 26409, 26438, 26468, 26498, 26527,
    26557, 26586, 26615, 26645, 26674, 26703, 26732, 26761,
    26790, 26819, 26848, 26877, 26905, 26934, 26963, 26991,
    27020, 27048, 27076, 27105, 27133, 27161, 27189, 27217,
    27245, 27273, 27301, 27329, 27356, 27384, 27411, 27439,
    27466, 27494, 27521, 27548, 27576, 27603, 27630, 27657,
    27684, 27711, 27737, 27764, 27791, 27817, 27844, 27870,
    27897, 27923, 27949, 27976, 28002, 28028, 28054, 28080,
    28106, 28131, 28157, 28183, 28208, 28234, 28259, 28285,
    28310, 28335, 28361, 28386, 28411, 28436, 28461, 28486,
    28511, 28535, 28560, 28585, 28609, 28634, 28658, 28682,
    28707, 28731, 28755, 28779, 28803, 28827, 28851, 28875,
    28898, 28922, 28946, 28969, 28993, 29016, 29039, 29062,
    29086, 29109, 29132, 29155, 29178, 29201, 29223, 29246,
    29269, 29291, 29314, 29336, 29359, 29381, 29403, 29425,
    29447, 29469, 29491, 29513, 29535, 29557, 29578, 29600,
    29621, 29643, 29664, 29686, 29707, 29728, 29749, 29770,
    29791, 29812, 29833, 29854, 29874, 29895, 29915, 29936,
    29956, 29977, 29997, 30017, 30037, 30057, 30077, 30097,
    30117, 30137, 30156, 30176, 30196, 30215, 30235, 30254,
    30273, 30292, 30312, 30331, 30350, 30368, 30387, 30406,
    30425, 30443, 30462, 30480, 30499, 30517, 30535, 30554,
    30572, 30590, 30608, 30626, 30644, 30661, 30679, 30697,
    30714, 30732, 30749, 30766, 30784, 30801, 30818, 30835,
    30852, 30869, 30886, 30902, 30919, 30936, 30952, 30969,
    30985, 31001, 31018, 31034, 31050, 31066, 31082, 31098,
    31114, 31129, 31145, 31161, 31176, 31192, 31207, 31222,
    31237, 31253, 31268, 31283, 31298, 31312, 31327, 31342,
    31357, 31371, 31386, 31400, 31414, 31429, 31443, 31457,
    31471, 31485, 31499, 31513, 31526, 31540, 31554, 31567,
    31581, 31594, 31607, 31620, 31634, 31647, 31660, 31673,
    31685, 31698, 31711, 31723, 31736, 31749, 31761, 31773,
    31785, 31798, 31810, 31822, 31834, 31846, 31857, 31869,
    31881, 31892, 31904, 31915, 31927, 31938, 31949, 31960,
    31971, 31982, 31993, 32004, 32015, 32025, 32036, 32047,
    32057, 32067, 32078, 32088, 32098, 32108, 32118, 32128,
    32138, 32148, 32157, 32167, 32176, 32186, 32195, 32205,
    32214, 32223, 32232, 32241, 32250, 32259, 32268, 32276,
    32285, 32294, 32302, 32311, 32319, 32327, 32335, 32343,
    32351, 32359, 32367, 32375, 32383, 32390, 32398, 32405,
    32413, 32420, 32427, 32435, 32442, 32449, 32456, 32463,
    32469, 32476, 32483, 32489, 32496, 32502, 32509, 32515,
    32521, 32527, 32533, 32539, 32545, 32551, 32557, 32562,
    32568, 32573, 32579, 32584, 32589, 32595, 32600, 32605,
    32610, 32615, 32619, 32624, 32629, 32633, 32638, 32642,
    32647, 32651, 32655, 32659, 32663, 32667, 32671, 32675,
    32679, 32682, 32686, 32689, 32693, 32696, 32700, 32703,
    32706, 32709, 32712, 32715, 32718, 32720, 32723, 32726,
    32728, 32730, 32733, 32735, 32737, 32739, 32741, 32743,
    32745, 32747, 32749, 32750, 32752, 32754, 32755, 32756,
    32758, 32759, 32760, 32761, 32762, 32763, 32764, 32764,
    32765, 32766, 32766, 32767, 32767, 32767, 32767, 32768,
    32768, 32767, 32767, 32767, 32767, 32766, 32766, 32765,
    32764, 32764, 32763, 32762, 32761, 32760, 32759, 32758,
    32756, 32755, 32754, 32752, 32750, 32749, 32747, 32745,
    32743, 32741, 32739, 32737, 32735, 32733, 32730, 32728,
    32726, 32723, 32720, 32718, 32715, 32712, 32709, 32706,
    32703, 32700, 32696, 32693, 32689, 32686, 32682, 32679,
    32675, 32671, 32667, 32663, 32659, 32655, 32651, 32647,
    32642, 32638, 32633, 32629, 32624, 32619, 32615, 32610,
    32605, 32600, 32595, 32589, 32584, 32579, 32573, 32568,
    32562, 32557, 32551, 32545, 32539, 32533, 32527, 32521,
    32515, 32509, 32502, 32496, 32489, 32483, 32476, 32469,
    32463, 32456, 32449, 32442, 32435, 32427, 32420, 32413,
    32405, 32398, 32390, 32383, 32375, 32367, 32359, 32351,
    32343, 32335, 32327, 32319, 32311, 32302, 32294, 32285,
    32276, 32268, 32259, 32250, 32241, 32232, 32223, 32214,
    32205, 32195, 32186, 32176, 32167, 32157, 32148, 32138,
    32128, 32118, 32108, 32098, 32088, 32078, 32067, 32057,
    32047, 32036, 32025, 32015, 32004, 31993, 31982, 31971,
    31960, 31949, 31938, 31927, 31915, 31904, 31892, 31881,
    31869, 31857, 31846, 31834, 31822, 31810, 31798, 31785,
    31773, 31761, 31749, 31736, 31723, 31711, 31698, 31685,
    31673, 31660, 31647, 31634, 31620, 31607, 31594, 31581,
    31567, 31554, 31540, 31526, 31513, 31499, 31485, 31471,
    31457, 31443, 31429, 31414, 31400, 31386, 31371, 31357,
    31342, 31327, 31312, 31298, 31283, 31268, 31253, 31237,
    31222, 31207, 31192, 31176, 31161, 31145, 31129, 31114,
    31098, 31082, 31066, 31050, 31034, 31018, 31001, 30985,
    30969, 30952, 30936, 30919, 30902, 30886, 30869, 30852,
    30835, 30818, 30801, 30784, 30766, 30749, 30732, 30714,
    30697, 30679, 30661, 30644, 30626, 30608, 30590, 30572,
    30554, 30535, 30517, 30499, 30480, 30462, 30443, 30425,
    30406, 30387, 30368, 30350, 30331, 30312, 30292, 30273,
    30254, 30235, 30215, 30196, 30176, 30156, 30137, 30117,
    30097, 30077, 30057, 30037, 30017, 29997, 29977, 29956,
    29936, 29915, 29895, 29874, 29854, 29833, 29812, 29791,
    29770, 29749, 29728, 29707, 29686, 29664, 29643, 29621,
    29600, 29578, 29557, 29535, 29513, 29491, 29469, 29447,
    29425, 29403, 29381, 29359, 29336, 29314, 29291, 29269,
    29246, 29223, 29201, 29178, 29155, 29132, 29109, 29086,
    29062, 29039, 29016, 28993, 28969, 28946, 28922, 28898,
    28875, 28851, 28827, 28803, 28779, 28755, 28731, 28707,
    28682, 28658, 28634, 28609, 28585, 28560, 28535, 28511,
    28486, 28461, 28436, 28411, 28386, 28361, 28335, 28310,
    28285, 28259, 28234, 28208, 28183, 28157, 28131, 28106,
    28080, 28054, 28028, 28002, 27976, 27949, 27923, 27897,
    27870, 27844, 27817, 27791, 27764, 27737, 27711, 27684,
    27657, 27630, 27603, 27576, 27548, 27521, 27494, 27466,
    27439, 27411, 27384, 27356, 27329, 27301, 27273, 27245,
    27217, 27189, 27161, 27133, 27105, 27076, 27048, 27020,
    26991, 26963, 26934, 26905, 26877, 26848, 26819, 26790,
    26761, 26732, 26703, 26674, 26645, 26615, 26586, 26557,
    26527, 26498, 26468, 26438, 26409, 26379, 26349, 26319,
    26289, 26259, 26229, 26199, 26169, 26138, 26108, 26077,
    26047, 26016, 25986, 25955, 25925, 25894, 25863, 25832,
    25801, 25770, 25739, 25708, 25677, 25645, 25614, 25583,
    25551, 25520, 25488, 25457, 25425, 25393, 25361, 25330,
    25298, 25266, 25234, 25201, 25169, 25137, 25105, 25073,
    25040, 25008, 24975, 24943, 24910, 24877, 24845, 24812,
    24779, 24746, 24713, 24680, 24647, 24614, 24580, 24547,
    24514, 24480, 24447, 24414, 24380, 24346, 24313, 24279,
    24245, 24211, 24177, 24144, 24109, 24075, 24041, 24007,
    23973, 23939, 23904, 23870, 23835, 23801, 23766, 23732,
    23697, 23662, 23627, 23593, 23558, 23523, 23488, 23453,
    23417, 23382, 23347, 23312, 23276, 23241, 23205, 23170,
    23134, 23099, 23063, 23027, 22992, 22956, 22920, 22884,
    22848, 22812, 22776, 22740, 22703, 22667, 22631, 22594,
    22558, 22521, 22485, 22448, 22412, 22375, 22338, 22301,
    22265, 22228, 22191, 22154, 22117, 22080, 22042, 22005,
    21968, 21931, 21893, 21856, 21818, 21781, 21743, 21706,
    21668, 21630, 21592, 21555, 21517, 21479, 21441, 21403,
    21365, 21326, 21288, 21250, 21212, 21173, 21135, 21097,
    21058, 21020, 20981, 20942, 20904, 20865, 20826, 20787,
    20748, 20709, 20671, 20631, 20592, 20553, 20514, 20475,
    20436, 20396, 20357, 20318, 20278, 20239, 20199, 20159,
    20120, 20080, 20040, 20001, 19961, 19921, 19881, 19841,
    19801, 19761, 19721, 19681, 19640, 19600, 19560, 19519,
    19479, 19439, 19398, 19358, 19317, 19276, 19236, 19195,
    19154, 19113, 19073, 19032, 18991, 18950, 18909, 18868,
    18826, 18785, 18744, 18703, 18662, 18620, 18579, 18537,
    18496, 18454, 18413, 18371, 18330, 18288, 18246, 18204,
    18163, 18121, 18079, 18037, 17995, 17953, 17911, 17869,
    17827, 17784, 17742, 17700, 17658, 17615, 17573, 17530,
    17488, 17445, 17403, 17360, 17317, 17275, 17232, 17189,
    17146, 17104, 17061, 17018, 16975, 16932, 16889, 16846,
    16802, 16759, 16716, 16673, 16630, 16586, 16543, 16499,
    16456, 16413, 16369, 16325, 16282, 16238, 16195, 16151,
    16107, 16063, 16019, 15976, 15932, 15888, 15844, 15800,
    15756, 15712, 15667, 15623, 15579, 15535, 15491, 15446,
    15402, 15357, 15313, 15269, 15224, 15180, 15135, 15090,
    15046, 15001, 14956, 14912, 14867, 14822, 14777, 14732,
    14687, 14642, 14598, 14552, 14507, 14462, 14417, 14372,
    14327, 14282, 14236, 14191, 14146, 14100, 14055, 14010,
    13964, 13919, 13873, 13828, 13782, 13736, 13691, 13645,
    13599, 13554, 13508, 13462, 13416, 13370, 13324, 13278,
    13232, 13186, 13140, 13094, 13048, 13002, 12956, 12910,
    12864, 12817, 12771, 12725, 12678, 12632, 12586, 12539,
    12493, 12446, 12400, 12353, 12307, 12260, 12213, 12167,
    12120, 12073, 12027, 11980, 11933, 11886, 11839, 11793,
    11746, 11699, 11652, 11605, 11558, 11511, 11464, 11416,
    11369, 11322, 11275, 11228, 11181, 11133, 11086, 11039,
    10991, 10944, 10897, 10849, 10802, 10754, 10707, 10659,
    10612, 10564, 10517, 10469, 10421, 10374, 10326, 10278,
    10230, 10183, 10135, 10087, 10039, 9991, 9944, 9896,
    9848, 9800, 9752, 9704, 9656, 9608, 9560, 9512,
    9463, 9415, 9367, 9319, 9271, 9223, 9174, 9126,
    9078, 9029, 8981, 8933, 8884, 8836, 8788, 8739,
    8691, 8642, 8594, 8545, 8497, 8448, 8400, 8351,
    8302, 8254, 8205, 8156, 8108, 8059, 8010, 7961,
    7913, 7864, 7815, 7766, 7717, 7669, 7620, 7571,
    7522, 7473, 7424, 7375, 7326, 7277, 7228, 7179,
    7130, 7081, 7032, 6983, 6934, 6884, 6835, 6786,
    6737, 6688, 6639, 6589, 6540, 6491, 6442, 6392,
    6343, 6294, 6244, 6195, 6146, 6096, 6047, 5997,
    5948, 5898, 5849, 5800, 5750, 5701, 5651, 5602,
    5552, 5503, 5453, 5403, 5354, 5304, 5255, 5205,
    5155, 5106, 5056, 5006, 4957, 4907, 4857, 4808,
    4758, 4708, 4658, 4609, 4559, 4509, 4459, 4409,
    4360, 4310, 4260, 4210, 4160, 4110, 4061, 4011,
    3961, 3911, 3861, 3811, 3761, 3711, 3661, 3611,
    3561, 3511, 3461, 3411, 3361, 3311, 3261, 3211,
    3161, 3111, 3061, 3011, 2961, 2911, 2861, 2811,
    2761, 2711, 2661, 2611, 2560, 2510, 2460, 2410,
    2360, 2310, 2260, 2210, 2159, 2109, 2059, 2009,
    1959, 1909, 1858, 1808, 1758, 1708, 1658, 1607,
    1557, 1507, 1457, 1407, 1356, 1306, 1256, 1206,
    1155, 1105, 1055, 1005, 954, 904, 854, 804,
    753, 703, 653, 603, 552, 502, 452, 402,
    351, 301, 251, 201, 150, 100, 50, 0
};

void hal_mtx_f2l(Mtx4f src, Mtx* dst) {
    u32 e1, e2;

    e1 = FTOFIX32(src[0][0]);
    e2 = FTOFIX32(src[0][1]);
    dst->m[0][0] = COMBINE_INTEGRAL(e1, e2);
    dst->m[2][0] = COMBINE_FRACTIONAL(e1, e2);
    e1 = FTOFIX32(src[0][2]);
    e2 = FTOFIX32(src[0][3]);
    dst->m[0][1] = COMBINE_INTEGRAL(e1, e2);
    dst->m[2][1] = COMBINE_FRACTIONAL(e1, e2);
    e1 = FTOFIX32(src[1][0]);
    e2 = FTOFIX32(src[1][1]);
    dst->m[0][2] = COMBINE_INTEGRAL(e1, e2);
    dst->m[2][2] = COMBINE_FRACTIONAL(e1, e2);
    e1 = FTOFIX32(src[1][2]);
    e2 = FTOFIX32(src[1][3]);
    dst->m[0][3] = COMBINE_INTEGRAL(e1, e2);
    dst->m[2][3] = COMBINE_FRACTIONAL(e1, e2);
    e1 = FTOFIX32(src[2][0]);
    e2 = FTOFIX32(src[2][1]);
    dst->m[1][0] = COMBINE_INTEGRAL(e1, e2);
    dst->m[3][0] = COMBINE_FRACTIONAL(e1, e2);
    e1 = FTOFIX32(src[2][2]);
    e2 = FTOFIX32(src[2][3]);
    dst->m[1][1] = COMBINE_INTEGRAL(e1, e2);
    dst->m[3][1] = COMBINE_FRACTIONAL(e1, e2);
    e1 = FTOFIX32(src[3][0]);
    e2 = FTOFIX32(src[3][1]);
    dst->m[1][2] = COMBINE_INTEGRAL(e1, e2);
    dst->m[3][2] = COMBINE_FRACTIONAL(e1, e2);
    e1 = FTOFIX32(src[3][2]);
    e2 = FTOFIX32(src[3][3]);
    dst->m[1][3] = COMBINE_INTEGRAL(e1, e2);
    dst->m[3][3] = COMBINE_FRACTIONAL(e1, e2);
}

// Same as above, but assumes column 3 is (0, 0, 0, 1)
void hal_mtx_f2l_fixed_w(Mtx4f src, Mtx* dst) {
    u32 e1, e2;

    e1 = FTOFIX32(src[0][0]);
    e2 = FTOFIX32(src[0][1]);
    dst->m[0][0] = COMBINE_INTEGRAL(e1, e2);
    dst->m[2][0] = COMBINE_FRACTIONAL(e1, e2);
    e1 = FTOFIX32(src[0][2]);
    e2 = FTOFIX32(0.0f);
    dst->m[0][1] = COMBINE_INTEGRAL(e1, e2);
    dst->m[2][1] = COMBINE_FRACTIONAL(e1, e2);
    e1 = FTOFIX32(src[1][0]);
    e2 = FTOFIX32(src[1][1]);
    dst->m[0][2] = COMBINE_INTEGRAL(e1, e2);
    dst->m[2][2] = COMBINE_FRACTIONAL(e1, e2);
    e1 = FTOFIX32(src[1][2]);
    e2 = FTOFIX32(0.0f);
    dst->m[0][3] = COMBINE_INTEGRAL(e1, e2);
    dst->m[2][3] = COMBINE_FRACTIONAL(e1, e2);
    e1 = FTOFIX32(src[2][0]);
    e2 = FTOFIX32(src[2][1]);
    dst->m[1][0] = COMBINE_INTEGRAL(e1, e2);
    dst->m[3][0] = COMBINE_FRACTIONAL(e1, e2);
    e1 = FTOFIX32(src[2][2]);
    e2 = FTOFIX32(0.0f);
    dst->m[1][1] = COMBINE_INTEGRAL(e1, e2);
    dst->m[3][1] = COMBINE_FRACTIONAL(e1, e2);
    e1 = FTOFIX32(src[3][0]);
    e2 = FTOFIX32(src[3][1]);
    dst->m[1][2] = COMBINE_INTEGRAL(e1, e2);
    dst->m[3][2] = COMBINE_FRACTIONAL(e1, e2);
    e1 = FTOFIX32(src[3][2]);
    e2 = FTOFIX32(1.0f);
    dst->m[1][3] = COMBINE_INTEGRAL(e1, e2);
    dst->m[3][3] = COMBINE_FRACTIONAL(e1, e2);
}

s32 fast_sinf(f32 arg0) {
    s32 temp;
    s32 ret;

    temp = arg0 * 651.8986f;
    ret = sSinTable[temp & 0x7FF];

    if (temp & 0x800) {
        return -ret;
    }

    return ret;
}

s32 fast_cosf(f32 arg0) {
    s32 temp;
    s32 ret;

    temp = (arg0 + HALF_PI) * 651.8986f;
    ret = sSinTable[temp & 0x7FF];

    if (temp & 0x800) {
        return -ret;
    }

    return ret;
}

void hal_look_at_f(
    Mtx4f mf,
    f32 xEye,
    f32 yEye,
    f32 zEye,
    f32 xAt,
    f32 yAt,
    f32 zAt,
    f32 xUp,
    f32 yUp,
    f32 zUp) {
    f32 len, xLook, yLook, zLook, xRight, yRight, zRight;

    xLook = xAt - xEye;
    yLook = yAt - yEye;
    zLook = zAt - zEye;

    /* Negate because positive Z is behind us: */
    len = -1.0f / sqrtf(xLook * xLook + yLook * yLook + zLook * zLook);
    xLook *= len;
    yLook *= len;
    zLook *= len;

    /* Right = Up x Look */

    xRight = yUp * zLook - zUp * yLook;
    yRight = zUp * xLook - xUp * zLook;
    zRight = xUp * yLook - yUp * xLook;
    len = 1.0f / sqrtf(xRight * xRight + yRight * yRight + zRight * zRight);
    xRight *= len;
    yRight *= len;
    zRight *= len;

    /* Up = Look x Right */

    xUp = yLook * zRight - zLook * yRight;
    yUp = zLook * xRight - xLook * zRight;
    zUp = xLook * yRight - yLook * xRight;
    len = 1.0f / sqrtf(xUp * xUp + yUp * yUp + zUp * zUp);
    xUp *= len;
    yUp *= len;
    zUp *= len;

    mf[0][0] = xRight;
    mf[1][0] = yRight;
    mf[2][0] = zRight;
    mf[3][0] = -(xEye * xRight + yEye * yRight + zEye * zRight);

    mf[0][1] = xUp;
    mf[1][1] = yUp;
    mf[2][1] = zUp;
    mf[3][1] = -(xEye * xUp + yEye * yUp + zEye * zUp);

    mf[0][2] = xLook;
    mf[1][2] = yLook;
    mf[2][2] = zLook;
    mf[3][2] = -(xEye * xLook + yEye * yLook + zEye * zLook);

    mf[0][3] = 0;
    mf[1][3] = 0;
    mf[2][3] = 0;
    mf[3][3] = 1;
}

void hal_look_at(Mtx* m, f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt, f32 xUp, f32 yUp, f32 zUp) {
    Mtx4f matrix;

    hal_look_at_f(matrix, xEye, yEye, zEye, xAt, yAt, zAt, xUp, yUp, zUp);
    hal_mtx_f2l(matrix, m);
}

void hal_look_at_roll_f(
    Mtx4f mf,
    f32 xEye,
    f32 yEye,
    f32 zEye,
    f32 xAt,
    f32 yAt,
    f32 zAt,
    f32 roll,
    f32 xUp,
    f32 yUp,
    f32 zUp) {
    f32 len;
    Vec3f look;
    Vec3f right;

    look.x = xAt - xEye;
    look.y = yAt - yEye;
    look.z = zAt - zEye;

    /* Negate because positive Z is behind us: */
    len = -1.0f / sqrtf(look.x * look.x + look.y * look.y + look.z * look.z);
    look.x *= len;
    look.y *= len;
    look.z *= len;

    /* Right = Up x Look */

    right.x = yUp * look.z - zUp * look.y;
    right.y = zUp * look.x - xUp * look.z;
    right.z = xUp * look.y - yUp * look.x;
    len = 1.0f / sqrtf(right.x * right.x + right.y * right.y + right.z * right.z);
    right.x *= len;
    right.y *= len;
    right.z *= len;

    Vec3f_func_8001A8B8(&right, &look, roll);
    xUp = (look.y * right.z) - (look.z * right.y);
    yUp = (look.z * right.x) - (look.x * right.z);
    zUp = (look.x * right.y) - (look.y * right.x);
    len = 1.0f / sqrtf(((xUp * xUp) + (yUp * yUp)) + (zUp * zUp));
    xUp = xUp * len;
    yUp = yUp * len;
    zUp = zUp * len;

    mf[0][0] = right.x;
    mf[1][0] = right.y;
    mf[2][0] = right.z;
    mf[3][0] = -(xEye * right.x + yEye * right.y + zEye * right.z);

    mf[0][1] = xUp;
    mf[1][1] = yUp;
    mf[2][1] = zUp;
    mf[3][1] = -(xEye * xUp + yEye * yUp + zEye * zUp);

    mf[0][2] = look.x;
    mf[1][2] = look.y;
    mf[2][2] = look.z;
    mf[3][2] = -(xEye * look.x + yEye * look.y + zEye * look.z);

    mf[0][3] = 0;
    mf[1][3] = 0;
    mf[2][3] = 0;
    mf[3][3] = 1;
}

void hal_look_at_roll(
    Mtx* m,
    f32 xEye,
    f32 yEye,
    f32 zEye,
    f32 xAt,
    f32 yAt,
    f32 zAt,
    f32 roll,
    f32 xUp,
    f32 yUp,
    f32 zUp) {
    Mtx4f mf;

    hal_look_at_roll_f(mf, xEye, yEye, zEye, xAt, yAt, zAt, roll, xUp, yUp, zUp);

    hal_mtx_f2l(mf, m);
}

void hal_look_at_reflect_f(
    Mtx4f mf,
    LookAt* l,
    f32 xEye,
    f32 yEye,
    f32 zEye,
    f32 xAt,
    f32 yAt,
    f32 zAt,
    f32 xUp,
    f32 yUp,
    f32 zUp) {
    f32 len, xLook, yLook, zLook, xRight, yRight, zRight;

    xLook = xAt - xEye;
    yLook = yAt - yEye;
    zLook = zAt - zEye;

    /* Negate because positive Z is behind us: */
    len = -1.0f / sqrtf(xLook * xLook + yLook * yLook + zLook * zLook);
    xLook *= len;
    yLook *= len;
    zLook *= len;

    /* Right = Up x Look */

    xRight = yUp * zLook - zUp * yLook;
    yRight = zUp * xLook - xUp * zLook;
    zRight = xUp * yLook - yUp * xLook;
    len = 1.0f / sqrtf(xRight * xRight + yRight * yRight + zRight * zRight);
    xRight *= len;
    yRight *= len;
    zRight *= len;

    /* Up = Look x Right */

    xUp = yLook * zRight - zLook * yRight;
    yUp = zLook * xRight - xLook * zRight;
    zUp = xLook * yRight - yLook * xRight;
    len = 1.0f / sqrtf(xUp * xUp + yUp * yUp + zUp * zUp);
    xUp *= len;
    yUp *= len;
    zUp *= len;

    /* reflectance vectors = Up and Right */

    l->l[0].l.dir[0] = FTOFRAC8(xRight);
    l->l[0].l.dir[1] = FTOFRAC8(yRight);
    l->l[0].l.dir[2] = FTOFRAC8(zRight);
    l->l[1].l.dir[0] = FTOFRAC8(xUp);
    l->l[1].l.dir[1] = FTOFRAC8(yUp);
    l->l[1].l.dir[2] = FTOFRAC8(zUp);
    l->l[0].l.col[0] = 0x00;
    l->l[0].l.col[1] = 0x00;
    l->l[0].l.col[2] = 0x00;
    l->l[0].l.pad1 = 0x00;
    l->l[0].l.colc[0] = 0x00;
    l->l[0].l.colc[1] = 0x00;
    l->l[0].l.colc[2] = 0x00;
    l->l[0].l.pad2 = 0x00;
    l->l[1].l.col[0] = 0x00;
    l->l[1].l.col[1] = 0x80;
    l->l[1].l.col[2] = 0x00;
    l->l[1].l.pad1 = 0x00;
    l->l[1].l.colc[0] = 0x00;
    l->l[1].l.colc[1] = 0x80;
    l->l[1].l.colc[2] = 0x00;
    l->l[1].l.pad2 = 0x00;

    mf[0][0] = xRight;
    mf[1][0] = yRight;
    mf[2][0] = zRight;
    mf[3][0] = -(xEye * xRight + yEye * yRight + zEye * zRight);

    mf[0][1] = xUp;
    mf[1][1] = yUp;
    mf[2][1] = zUp;
    mf[3][1] = -(xEye * xUp + yEye * yUp + zEye * zUp);

    mf[0][2] = xLook;
    mf[1][2] = yLook;
    mf[2][2] = zLook;
    mf[3][2] = -(xEye * xLook + yEye * yLook + zEye * zLook);

    mf[0][3] = 0;
    mf[1][3] = 0;
    mf[2][3] = 0;
    mf[3][3] = 1;
}

void hal_look_at_reflect(
    Mtx* m,
    LookAt* l,
    f32 xEye,
    f32 yEye,
    f32 zEye,
    f32 xAt,
    f32 yAt,
    f32 zAt,
    f32 xUp,
    f32 yUp,
    f32 zUp) {
    Mtx4f mf;

    hal_look_at_reflect_f(mf, l, xEye, yEye, zEye, xAt, yAt, zAt, xUp, yUp, zUp);

    hal_mtx_f2l(mf, m);
}

void hal_look_at_reflect_roll_f(
    Mtx4f mf,
    LookAt* l,
    f32 xEye,
    f32 yEye,
    f32 zEye,
    f32 xAt,
    f32 yAt,
    f32 zAt,
    f32 roll,
    f32 xUp,
    f32 yUp,
    f32 zUp) {
    f32 len;
    Vec3f look;
    Vec3f right;

    look.x = xAt - xEye;
    look.y = yAt - yEye;
    look.z = zAt - zEye;

    /* Negate because positive Z is behind us: */
    len = -1.0f / sqrtf(look.x * look.x + look.y * look.y + look.z * look.z);
    look.x *= len;
    look.y *= len;
    look.z *= len;

    /* Right = Up x Look */

    right.x = yUp * look.z - zUp * look.y;
    right.y = zUp * look.x - xUp * look.z;
    right.z = xUp * look.y - yUp * look.x;
    len = 1.0f / sqrtf(right.x * right.x + right.y * right.y + right.z * right.z);
    right.x *= len;
    right.y *= len;
    right.z *= len;

    /* Up = Look x Right */

    Vec3f_func_8001A8B8(&right, &look, roll);
    xUp = look.y * right.z - look.z * right.y;
    yUp = look.z * right.x - look.x * right.z;
    zUp = look.x * right.y - look.y * right.x;
    len = 1.0f / sqrtf(xUp * xUp + yUp * yUp + zUp * zUp);
    xUp *= len;
    yUp *= len;
    zUp *= len;

    /* reflectance vectors = Up and Right */

    l->l[0].l.dir[0] = FTOFRAC8(right.x);
    l->l[0].l.dir[1] = FTOFRAC8(right.y);
    l->l[0].l.dir[2] = FTOFRAC8(right.z);
    l->l[1].l.dir[0] = FTOFRAC8(xUp);
    l->l[1].l.dir[1] = FTOFRAC8(yUp);
    l->l[1].l.dir[2] = FTOFRAC8(zUp);
    l->l[0].l.col[0] = 0x00;
    l->l[0].l.col[1] = 0x00;
    l->l[0].l.col[2] = 0x00;
    l->l[0].l.pad1 = 0x00;
    l->l[0].l.colc[0] = 0x00;
    l->l[0].l.colc[1] = 0x00;
    l->l[0].l.colc[2] = 0x00;
    l->l[0].l.pad2 = 0x00;
    l->l[1].l.col[0] = 0x00;
    l->l[1].l.col[1] = 0x80;
    l->l[1].l.col[2] = 0x00;
    l->l[1].l.pad1 = 0x00;
    l->l[1].l.colc[0] = 0x00;
    l->l[1].l.colc[1] = 0x80;
    l->l[1].l.colc[2] = 0x00;
    l->l[1].l.pad2 = 0x00;

    mf[0][0] = right.x;
    mf[1][0] = right.y;
    mf[2][0] = right.z;
    mf[3][0] = -(xEye * right.x + yEye * right.y + zEye * right.z);

    mf[0][1] = xUp;
    mf[1][1] = yUp;
    mf[2][1] = zUp;
    mf[3][1] = -(xEye * xUp + yEye * yUp + zEye * zUp);

    mf[0][2] = look.x;
    mf[1][2] = look.y;
    mf[2][2] = look.z;
    mf[3][2] = -(xEye * look.x + yEye * look.y + zEye * look.z);

    mf[0][3] = 0;
    mf[1][3] = 0;
    mf[2][3] = 0;
    mf[3][3] = 1;
}

void hal_look_at_reflect_roll(
    Mtx* m,
    LookAt* l,
    f32 xEye,
    f32 yEye,
    f32 zEye,
    f32 xAt,
    f32 yAt,
    f32 zAt,
    f32 roll,
    f32 xUp,
    f32 yUp,
    f32 zUp) {
    Mtx4f mf;

    hal_look_at_reflect_roll_f(mf, l, xEye, yEye, zEye, xAt, yAt, zAt, roll, xUp, yUp, zUp);

    hal_mtx_f2l(mf, m);
}

void hal_ortho_f(Mtx4f mf, f32 l, f32 r, f32 b, f32 t, f32 n, f32 f, f32 scale) {
    s32 i, j;

    mf[0][0] = 2 / (r - l);
    mf[1][1] = 2 / (t - b);
    mf[2][2] = -2 / (f - n);
    mf[3][0] = -(r + l) / (r - l);
    mf[3][1] = -(t + b) / (t - b);
    mf[3][2] = -(f + n) / (f - n);
    mf[3][3] = 1;

    for (i = 0; i < 3; i++) {
        if (i != 0) {
            mf[i][0] = 0;
        }
        if (i != 1) {
            mf[i][1] = 0;
        }
        if (i != 2) {
            mf[i][2] = 0;
        }
        if (i != 3) {
            mf[i][3] = 0;
        }
    }

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            mf[i][j] *= scale;
        }
    }
}

void hal_ortho(Mtx* m, f32 l, f32 r, f32 b, f32 t, f32 n, f32 f, f32 scale) {
    Mtx4f mf;

    hal_ortho_f(mf, l, r, b, t, n, f, scale);

    hal_mtx_f2l(mf, m);
}

void hal_perspective_fast_f(
    Mtx4f mf,
    u16* perspNorm,
    f32 fovy,
    f32 aspect,
    f32 near,
    f32 far,
    f32 scale) {
    f32 cot;
    u16 sinAngle;
    f32 sinX, cosX;
    s32 unused[4];

    fovy *= 0.008726646f;

    sinAngle = (s32) (fovy * 651.8986f) & 0xFFF;
    // clang-format off
    do { \
        sinX = (f32) sSinTable[sinAngle & (ARRAY_COUNT(sSinTable) - 1)]; \
        if (sinAngle & 0x800) { \
            sinX = -sinX; \
        } \
        sinAngle += 0x400; \
        cosX = (f32) sSinTable[sinAngle & (ARRAY_COUNT(sSinTable) - 1)]; \
        if (sinAngle & 0x800) { \
            cosX = -cosX; \
        } \
    } while (0);
    // clang-format on
    cot = cosX / sinX;

    mf[0][0] = (cot / aspect) * scale;
    mf[1][1] = cot * scale;
    mf[2][2] = ((near + far) * scale) / (near - far);
    mf[2][3] = -scale;
    mf[3][2] = (2.0f * near * far * scale) / (near - far);
    mf[3][3] = 0.0f;

    mf[0][1] = 0;
    mf[0][2] = 0;
    mf[0][3] = 0;

    mf[1][0] = 0;
    mf[1][2] = 0;
    mf[1][3] = 0;

    mf[2][0] = 0;
    mf[2][1] = 0;

    mf[3][0] = 0;
    mf[3][1] = 0;

    if (perspNorm != NULL) {
        if (near + far <= 2.0f) {
            *perspNorm = (u16) 0xFFFF;
        } else {
            *perspNorm = (u16) ((2.0f * 65536.0f) / (near + far));
            if (*perspNorm <= 0) {
                *perspNorm = (u16) 0x0001;
            }
        }
    }
}

void hal_perspective_fast(
    Mtx* m,
    u16* perspNorm,
    f32 fovy,
    f32 aspect,
    f32 near,
    f32 far,
    f32 scale) {
    Mtx4f mf;

    hal_perspective_fast_f(mf, perspNorm, fovy, aspect, near, far, scale);

    hal_mtx_f2l(mf, m);
}

void hal_perspective_f(
    Mtx4f mf,
    u16* perspNorm,
    f32 fovy,
    f32 aspect,
    f32 near,
    f32 far,
    f32 scale) {
    s32 unused1;
    f32 cotValue;
    f32 sinValue;
    f32 cosValue;
    s32 unused3;

    fovy *= 3.1415926f / 180.0f;
    cosValue = cosf(fovy / 2);
    sinValue = sinf(fovy / 2);
    cotValue = cosValue / sinValue;

    mf[0][0] = (cotValue / aspect) * scale;
    mf[1][1] = cotValue * scale;
    mf[2][2] = ((near + far) * scale) / (near - far);
    mf[2][3] = -scale;
    mf[3][2] = (2.0f * near * far * scale) / (near - far);
    mf[3][3] = 0.0f;

    mf[0][1] = 0;
    mf[0][2] = 0;
    mf[0][3] = 0;

    mf[1][0] = 0;
    mf[1][2] = 0;
    mf[1][3] = 0;

    mf[2][0] = 0;
    mf[2][1] = 0;

    mf[3][0] = 0;
    mf[3][1] = 0;

    if (perspNorm != NULL) {
        if (near + far <= 2.0f) {
            *perspNorm = 0xFFFF;
        } else {
            *perspNorm = (2.0f * 65536.0f) / (near + far);
            if (*perspNorm <= 0) {
                *perspNorm = 1;
            }
        }
    }
}

void hal_perspective(Mtx* m, u16* perspNorm, f32 fovy, f32 aspect, f32 near, f32 far, f32 scale) {
    Mtx4f mf;

    hal_perspective_f(mf, perspNorm, fovy, aspect, near, far, scale);

    hal_mtx_f2l(mf, m);
}

void hal_scale_f(Mtx4f mf, f32 x, f32 y, f32 z) {
    s32 i, j;

    mf[0][0] = x;
    mf[1][1] = y;
    mf[2][2] = z;
    mf[3][3] = 1.0f;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (i != j) {
                mf[i][j] = 0;
            }
        }
    }
}

void hal_scale(Mtx* m, f32 x, f32 y, f32 z) {
    s32 e1, e2;

    m->m[0][1] = 0;
    m->m[2][1] = 0;
    m->m[0][3] = 0;
    m->m[2][3] = 0;
    m->m[1][0] = 0;
    m->m[3][0] = 0;

    e1 = FTOFIX32(x);
    e2 = FTOFIX32(0);
    m->m[0][0] = COMBINE_INTEGRAL(e1, e2);
    m->m[2][0] = COMBINE_FRACTIONAL(e1, e2);

    e1 = FTOFIX32(0);
    e2 = FTOFIX32(y);
    m->m[0][2] = COMBINE_INTEGRAL(e1, e2);
    m->m[2][2] = COMBINE_FRACTIONAL(e1, e2);

    e1 = FTOFIX32(z);
    e2 = FTOFIX32(0);
    m->m[1][1] = COMBINE_INTEGRAL(e1, e2);
    m->m[3][1] = COMBINE_FRACTIONAL(e1, e2);

    m->m[1][2] = 0;
    m->m[3][2] = 0;

    m->m[1][3] = 1;
    m->m[3][3] = 0;
}

void hal_scale_mul_f(Mtx4f mf, f32 x, f32 y, f32 z) {
    s32 j;

    for (j = 0; j < 4; j++) {
        if (mf[0][j] != 0.0f) {
            mf[0][j] *= x;
        }
    }

    for (j = 0; j < 4; j++) {
        if (mf[1][j] != 0.0f) {
            mf[1][j] *= y;
        }
    }

    for (j = 0; j < 4; j++) {
        if (mf[2][j] != 0.0f) {
            mf[2][j] *= z;
        }
    }
}

void hal_translate_f(Mtx4f mf, f32 x, f32 y, f32 z) {
    int i, j;

    mf[3][0] = x;
    mf[3][1] = y;
    mf[3][2] = z;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            if (i == j) {
                mf[i][j] = 1.0f;
            } else {
                mf[i][j] = 0.0f;
            }
        }
    }
    mf[3][3] = 1.0f;
}

void hal_translate(Mtx* m, f32 x, f32 y, f32 z) {
    u32 e1, e2;

    m->m[0][0] = COMBINE_INTEGRAL(FTOFIX32(1.0F), FTOFIX32(0.0F));
    m->m[2][0] = COMBINE_FRACTIONAL(FTOFIX32(1.0F), FTOFIX32(0.0F));

    m->m[0][1] = COMBINE_INTEGRAL(FTOFIX32(0.0F), FTOFIX32(0.0F));
    m->m[2][1] = COMBINE_FRACTIONAL(FTOFIX32(0.0F), FTOFIX32(0.0F));

    m->m[0][2] = COMBINE_INTEGRAL(FTOFIX32(0.0F), FTOFIX32(1.0F));
    m->m[2][2] = COMBINE_FRACTIONAL(FTOFIX32(0.0F), FTOFIX32(1.0F));

    m->m[0][3] = COMBINE_INTEGRAL(FTOFIX32(0.0F), FTOFIX32(0.0F));
    m->m[2][3] = COMBINE_FRACTIONAL(FTOFIX32(0.0F), FTOFIX32(0.0F));

    m->m[1][0] = COMBINE_INTEGRAL(FTOFIX32(0.0F), FTOFIX32(0.0F));
    m->m[3][0] = COMBINE_FRACTIONAL(FTOFIX32(0.0F), FTOFIX32(0.0F));

    m->m[1][1] = COMBINE_INTEGRAL(FTOFIX32(1.0F), FTOFIX32(0.0F));
    m->m[3][1] = COMBINE_FRACTIONAL(FTOFIX32(1.0F), FTOFIX32(0.0F));

    e1 = FTOFIX32(x);
    e2 = FTOFIX32(y);
    m->m[1][2] = COMBINE_INTEGRAL(e1, e2);
    m->m[3][2] = COMBINE_FRACTIONAL(e1, e2);

    e1 = FTOFIX32(z);
    m->m[1][3] = COMBINE_INTEGRAL(e1, FTOFIX32(1.0F));
    m->m[3][3] = COMBINE_FRACTIONAL(e1, FTOFIX32(1.0F));
}

void hal_rotate_f(Mtx4f mf, f32 a, f32 x, f32 y, f32 z) {
    f32 sine;
    f32 cosine;
    f32 ab, bc, ca, t;

    guNormalize(&x, &y, &z);
    sine = sinf(a);
    cosine = cosf(a);
    t = (1.0f - cosine);
    ab = x * y * t;
    bc = y * z * t;
    ca = z * x * t;

    t = x * x;
    mf[0][0] = t + cosine * (1 - t);
    mf[2][1] = bc - x * sine;
    mf[1][2] = bc + x * sine;

    t = y * y;
    mf[1][1] = t + cosine * (1 - t);
    mf[2][0] = ca + y * sine;
    mf[0][2] = ca - y * sine;

    t = z * z;
    mf[2][2] = t + cosine * (1 - t);
    mf[1][0] = ab - z * sine;
    mf[0][1] = ab + z * sine;

    mf[0][3] = 0.0f;
    mf[1][3] = 0.0f;
    mf[2][3] = 0.0f;

    mf[3][0] = 0.0f;
    mf[3][1] = 0.0f;
    mf[3][2] = 0.0f;
    mf[3][3] = 1.0f;
}

void hal_rotate(Mtx* m, f32 a, f32 x, f32 y, f32 z) {
    Mtx4f mf;

    hal_rotate_f(mf, a, x, y, z);

    hal_mtx_f2l_fixed_w(mf, m);
}

void hal_rotate_translate_f(Mtx4f mf, f32 dx, f32 dy, f32 dz, f32 angle, f32 rx, f32 ry, f32 rz) {
    hal_rotate_f(mf, angle, rx, ry, rz);
    mf[3][0] = dx;
    mf[3][1] = dy;
    mf[3][2] = dz;
}

void hal_rotate_translate(Mtx* m, f32 dx, f32 dy, f32 dz, f32 angle, f32 rx, f32 ry, f32 rz) {
    Mtx4f mf;

    hal_rotate_translate_f(mf, dx, dy, dz, angle, rx, ry, rz);
    hal_mtx_f2l_fixed_w(mf, m);
}

void hal_rotate_translate_scale_f(
    Mtx4f mf,
    f32 dx,
    f32 dy,
    f32 dz,
    f32 angle,
    f32 rx,
    f32 ry,
    f32 rz,
    f32 sx,
    f32 sy,
    f32 sz) {
    hal_rotate_f(mf, angle, rx, ry, rz);
    mf[3][0] = dx;
    mf[3][1] = dy;
    mf[3][2] = dz;
    hal_scale_mul_f(mf, sx, sy, sz);
}

void hal_rotate_translate_scale(
    Mtx* m,
    f32 dx,
    f32 dy,
    f32 dz,
    f32 angle,
    f32 rx,
    f32 ry,
    f32 rz,
    f32 sx,
    f32 sy,
    f32 sz) {
    Mtx4f mf;

    hal_rotate_translate_scale_f(mf, dx, dy, dz, angle, rx, ry, rz, sx, sy, sz);
    hal_mtx_f2l_fixed_w(mf, m);
}

void hal_rotate_rpy_f(Mtx4f mf, f32 r, f32 p, f32 h) {
    f32 sinr, sinp, sinh;
    f32 cosr, cosp, cosh;

    sinr = sinf(r);
    cosr = cosf(r);
    sinp = sinf(p);
    cosp = cosf(p);
    sinh = sinf(h);
    cosh = cosf(h);

    mf[0][0] = cosp * cosh;
    mf[0][1] = cosp * sinh;
    mf[0][2] = -sinp;

    mf[1][0] = sinr * sinp * cosh - cosr * sinh;
    mf[1][1] = sinr * sinp * sinh + cosr * cosh;
    mf[1][2] = sinr * cosp;

    mf[2][0] = cosr * sinp * cosh + sinr * sinh;
    mf[2][1] = cosr * sinp * sinh - sinr * cosh;
    mf[2][2] = cosr * cosp;

    mf[3][2] = 0.0f;
    mf[3][1] = 0.0f;
    mf[3][0] = 0.0f;

    mf[3][3] = 1.0f;
    mf[2][3] = 0.0f;
    mf[1][3] = 0.0f;
    mf[0][3] = 0.0f;
}

void hal_rotate_rpy(Mtx* m, f32 r, f32 p, f32 h) {
    s32 sinr, sinp, siny;
    s32 cosr, cosp, cosy;
    u16 indexr, indexp, indexy;
    u32 e1, e2;

    hal_get_sin_cos_u_short(sinr, cosr, r, indexr);
    hal_get_sin_cos_u_short(sinp, cosp, p, indexp);
    hal_get_sin_cos_u_short(siny, cosy, h, indexy);

    // [0, 0] -> [0, 3]
    e1 = (cosp * cosy) >> 14;
    e2 = (cosp * siny) >> 14;
    m->m[0][0] = COMBINE_INTEGRAL(e1, e2);
    m->m[2][0] = COMBINE_FRACTIONAL(e1, e2);

    e1 = -sinp * 2;
    m->m[0][1] = COMBINE_INTEGRAL(e1, FTOFIX32(0.0F));
    m->m[2][1] = COMBINE_FRACTIONAL(e1, FTOFIX32(0.0F));

    // [1, 0] -> [1, 3]
    e1 = ((((sinr * sinp) >> 15) * cosy) >> 14) - ((cosr * siny) >> 14);
    e2 = ((((sinr * sinp) >> 15) * siny) >> 14) + ((cosr * cosy) >> 14);
    m->m[0][2] = COMBINE_INTEGRAL(e1, e2);
    m->m[2][2] = COMBINE_FRACTIONAL(e1, e2);

    e1 = (sinr * cosp) >> 14;
    m->m[0][3] = COMBINE_INTEGRAL(e1, FTOFIX32(0.0F));
    m->m[2][3] = COMBINE_FRACTIONAL(e1, FTOFIX32(0.0F));

    // [2, 0] -> [2, 3]
    e1 = ((((cosr * sinp) >> 15) * cosy) >> 14) + ((sinr * siny) >> 14);
    e2 = ((((cosr * sinp) >> 15) * siny) >> 14) - ((sinr * cosy) >> 14);

    m->m[1][0] = COMBINE_INTEGRAL(e1, e2);
    m->m[3][0] = COMBINE_FRACTIONAL(e1, e2);

    e1 = (cosr * cosp) >> 14;
    m->m[1][1] = COMBINE_INTEGRAL(e1, FTOFIX32(0.0F));
    m->m[3][1] = COMBINE_FRACTIONAL(e1, FTOFIX32(0.0F));

    m->m[1][2] = COMBINE_INTEGRAL(FTOFIX32(0.0F), FTOFIX32(0.0F));
    m->m[3][2] = COMBINE_FRACTIONAL(FTOFIX32(0.0F), FTOFIX32(0.0F));

    m->m[1][3] = COMBINE_INTEGRAL(FTOFIX32(0.0F), FTOFIX32(1.0F));
    m->m[3][3] = COMBINE_FRACTIONAL(FTOFIX32(0.0F), FTOFIX32(1.0F));
}

void hal_rotate_rpy_translate_f(Mtx4f mf, f32 dx, f32 dy, f32 dz, f32 r, f32 p, f32 h) {
    hal_rotate_rpy_f(mf, r, p, h);
    mf[3][0] = dx;
    mf[3][1] = dy;
    mf[3][2] = dz;
}

void hal_rotate_rpy_translate(Mtx* m, f32 dx, f32 dy, f32 dz, f32 r, f32 p, f32 h) {
    s32 sinr, sinp, siny;
    s32 cosr, cosp, cosy;
    u16 indexr, indexp, indexy;
    u32 e1, e2;

    hal_get_sin_cos_u_short(sinr, cosr, r, indexr);
    hal_get_sin_cos_u_short(sinp, cosp, p, indexp);
    hal_get_sin_cos_u_short(siny, cosy, h, indexy);

    // [0, 0] -> [0, 3]
    e1 = (cosp * cosy) >> 14;
    e2 = (cosp * siny) >> 14;
    m->m[0][0] = COMBINE_INTEGRAL(e1, e2);
    m->m[2][0] = COMBINE_FRACTIONAL(e1, e2);

    e1 = -sinp * 2;
    m->m[0][1] = COMBINE_INTEGRAL(e1, FTOFIX32(0.0F));
    m->m[2][1] = COMBINE_FRACTIONAL(e1, FTOFIX32(0.0F));

    // [1, 0] -> [1, 3]
    e1 = ((((sinr * sinp) >> 15) * cosy) >> 14) - ((cosr * siny) >> 14);
    e2 = ((((sinr * sinp) >> 15) * siny) >> 14) + ((cosr * cosy) >> 14);
    m->m[0][2] = COMBINE_INTEGRAL(e1, e2);
    m->m[2][2] = COMBINE_FRACTIONAL(e1, e2);

    e1 = (sinr * cosp) >> 14;
    m->m[0][3] = COMBINE_INTEGRAL(e1, FTOFIX32(0.0F));
    m->m[2][3] = COMBINE_FRACTIONAL(e1, FTOFIX32(0.0F));

    // [2, 0] -> [2, 3]
    e1 = ((((cosr * sinp) >> 15) * cosy) >> 14) + ((sinr * siny) >> 14);
    e2 = ((((cosr * sinp) >> 15) * siny) >> 14) - ((sinr * cosy) >> 14);

    m->m[1][0] = COMBINE_INTEGRAL(e1, e2);
    m->m[3][0] = COMBINE_FRACTIONAL(e1, e2);

    e1 = (cosr * cosp) >> 14;
    m->m[1][1] = COMBINE_INTEGRAL(e1, FTOFIX32(0.0F));
    m->m[3][1] = COMBINE_FRACTIONAL(e1, FTOFIX32(0.0F));

    // [3, 0] -> [3, 3]
    // [3, 0] -> [3, 3]
    e1 = FTOFIX32(dx);
    e2 = FTOFIX32(dy);
    m->m[1][2] = COMBINE_INTEGRAL(e1, e2);
    m->m[3][2] = COMBINE_FRACTIONAL(e1, e2);

    e1 = FTOFIX32(dz);
    m->m[1][3] = COMBINE_INTEGRAL(e1, FTOFIX32(1.0F));
    m->m[3][3] = COMBINE_FRACTIONAL(e1, FTOFIX32(1.0F));
}

void hal_rotate_rpy_translate_scale_f(
    Mtx4f mf,
    f32 dx,
    f32 dy,
    f32 dz,
    f32 r,
    f32 p,
    f32 h,
    f32 sx,
    f32 sy,
    f32 sz) {
    hal_rotate_rpy_f(mf, r, p, h);
    mf[3][0] = dx;
    mf[3][1] = dy;
    mf[3][2] = dz;
    hal_scale_mul_f(mf, sx, sy, sz);
}

void hal_rotate_rpy_translate_scale(
    Mtx* m,
    f32 dx,
    f32 dy,
    f32 dz,
    f32 r,
    f32 p,
    f32 h,
    f32 sx,
    f32 sy,
    f32 sz) {
    s32 sinr, sinp, siny;
    s32 cosr, cosp, cosy;
    s32 scalex, scaley, scalez;
    u16 indexr, indexp, indexy;
    u32 e1, e2;

    hal_get_sin_cos_u_short(sinr, cosr, r, indexr);
    hal_get_sin_cos_u_short(sinp, cosp, p, indexp);
    hal_get_sin_cos_u_short(siny, cosy, h, indexy);

    scalex = sx * 256;
    scaley = sy * 256;
    scalez = sz * 256;

    // [0, 0] -> [0, 3]
    e1 = (((cosp * cosy) >> 14) * scalex) >> 8;
    e2 = (((cosp * siny) >> 14) * scalex) >> 8;
    m->m[0][0] = COMBINE_INTEGRAL(e1, e2);
    m->m[2][0] = COMBINE_FRACTIONAL(e1, e2);

    e1 = (-sinp * scalex) >> 7;
    m->m[0][1] = COMBINE_INTEGRAL(e1, FTOFIX32(0.0F));
    m->m[2][1] = COMBINE_FRACTIONAL(e1, FTOFIX32(0.0F));

    // [1, 0] -> [1, 3]
    e1 = ((((((sinr * sinp) >> 15) * cosy) >> 14) - ((cosr * siny) >> 14)) * scaley) >> 8;
    e2 = ((((((sinr * sinp) >> 15) * siny) >> 14) + ((cosr * cosy) >> 14)) * scaley) >> 8;
    m->m[0][2] = COMBINE_INTEGRAL(e1, e2);
    m->m[2][2] = COMBINE_FRACTIONAL(e1, e2);

    e1 = (((sinr * cosp) >> 14) * scaley) >> 8;
    m->m[0][3] = COMBINE_INTEGRAL(e1, FTOFIX32(0.0F));
    m->m[2][3] = COMBINE_FRACTIONAL(e1, FTOFIX32(0.0F));

    // [2, 0] -> [2, 3]
    e1 = ((((((cosr * sinp) >> 15) * cosy) >> 14) + ((sinr * siny) >> 14)) * scalez) >> 8;
    e2 = ((((((cosr * sinp) >> 15) * siny) >> 14) - ((sinr * cosy) >> 14)) * scalez) >> 8;
    m->m[1][0] = COMBINE_INTEGRAL(e1, e2);
    m->m[3][0] = COMBINE_FRACTIONAL(e1, e2);

    e1 = (((cosr * cosp) >> 14) * scalez) >> 8;
    m->m[1][1] = COMBINE_INTEGRAL(e1, FTOFIX32(0.0F));
    m->m[3][1] = COMBINE_FRACTIONAL(e1, FTOFIX32(0.0F));

    // [3, 0] -> [3, 3]
    e1 = FTOFIX32(dx);
    e2 = FTOFIX32(dy);
    m->m[1][2] = COMBINE_INTEGRAL(e1, e2);
    m->m[3][2] = COMBINE_FRACTIONAL(e1, e2);

    e1 = FTOFIX32(dz);
    m->m[1][3] = COMBINE_INTEGRAL(e1, FTOFIX32(1.0F));
    m->m[3][3] = COMBINE_FRACTIONAL(e1, FTOFIX32(1.0F));
}

void hal_rotate_pyr_f(Mtx4f mf, f32 r, f32 p, f32 h) {
    f32 sinr, sinp, sinh;
    f32 cosr, cosp, cosh;
    UNUSED u32 pad[4];

    sinr = sinf(r);
    cosr = cosf(r);
    sinp = sinf(p);
    cosp = cosf(p);
    sinh = sinf(h);
    cosh = cosf(h);

    mf[0][0] = cosh * cosp;
    mf[0][1] = cosr * sinh * cosp + sinr * sinp;
    mf[0][2] = sinr * sinh * cosp - cosr * sinp;

    mf[1][0] = -sinh;
    mf[1][1] = cosr * cosh;
    mf[1][2] = sinr * cosh;

    mf[2][0] = cosh * sinp;
    mf[2][1] = cosr * sinh * sinp - sinr * cosp;
    mf[2][2] = sinr * sinh * sinp + cosr * cosp;

    mf[0][3] = 0;
    mf[1][3] = 0;
    mf[2][3] = 0;

    mf[3][0] = 0;
    mf[3][1] = 0;
    mf[3][2] = 0;
    mf[3][3] = 1;
}

void hal_rotate_pyr(Mtx* m, f32 r, f32 p, f32 h) {
    Mtx4f mf;

    hal_rotate_pyr_f(mf, r, p, h);
    hal_mtx_f2l_fixed_w(mf, m);
}

void hal_rotate_pyr_translate_f(Mtx4f mf, f32 dx, f32 dy, f32 dz, f32 r, f32 p, f32 h) {
    hal_rotate_pyr_f(mf, r, p, h);
    mf[3][0] = dx;
    mf[3][1] = dy;
    mf[3][2] = dz;
}

void hal_rotate_pyr_translate(Mtx* m, f32 dx, f32 dy, f32 dz, f32 r, f32 p, f32 h) {
    Mtx4f mf;

    hal_rotate_pyr_translate_f(mf, dx, dy, dz, r, p, h);
    hal_mtx_f2l_fixed_w(mf, m);
}

void hal_rotate_pyr_translate_scale_f(
    Mtx4f mf,
    f32 dx,
    f32 dy,
    f32 dz,
    f32 r,
    f32 p,
    f32 h,
    f32 sx,
    f32 sy,
    f32 sz) {
    hal_rotate_pyr_f(mf, r, p, h);
    mf[3][0] = dx;
    mf[3][1] = dy;
    mf[3][2] = dz;
    hal_scale_mul_f(mf, sx, sy, sz);
}

void hal_rotate_pyr_translate_scale(
    Mtx* m,
    f32 dx,
    f32 dy,
    f32 dz,
    f32 r,
    f32 p,
    f32 h,
    f32 sx,
    f32 sy,
    f32 sz) {
    Mtx4f mf;

    hal_rotate_pyr_translate_scale_f(mf, dx, dy, dz, r, p, h, sx, sy, sz);
    hal_mtx_f2l_fixed_w(mf, m);
}

// rotate pitch yaw?
void hal_rotate_py_f(Mtx4f mf, f32 p, f32 h) {
    f32 sinp, sinh;
    f32 cosp, cosh;

    sinp = sinf(p);
    cosp = cosf(p);
    sinh = sinf(h);
    cosh = cosf(h);

    mf[0][0] = cosp * cosh;
    mf[0][1] = cosp * sinh;
    mf[0][2] = -sinp;

    mf[1][0] = -sinh;
    mf[1][1] = cosh;
    mf[1][2] = 0;

    mf[2][0] = sinp * cosh;
    mf[2][1] = sinp * sinh;
    mf[2][2] = cosp;

    mf[0][3] = mf[1][3] = mf[2][3] = mf[3][0] = mf[3][1] = mf[3][2] = 0;

    mf[3][3] = 1.0f;
}

void hal_rotate_py(Mtx* m, f32 p, f32 h) {
    Mtx4f mf;

    hal_rotate_py_f(mf, p, h);
    hal_mtx_f2l_fixed_w(mf, m);
}

void hal_rotate_py_translate_f(Mtx4f mf, f32 dx, f32 dy, f32 dz, f32 p, f32 h) {
    hal_rotate_py_f(mf, p, h);
    mf[3][0] = dx;
    mf[3][1] = dy;
    mf[3][2] = dz;
}

void hal_rotate_py_translate(Mtx* m, f32 dx, f32 dy, f32 dz, f32 p, f32 h) {
    Mtx4f mf;

    hal_rotate_py_translate_f(mf, dx, dy, dz, p, h);
    hal_mtx_f2l_fixed_w(mf, m);
}

// roll pitch
void hal_rotate_rp_f(Mtx4f mf, f32 r, f32 p) {
    f32 sinr, sinp;
    f32 cosr, cosp;

    sinr = sinf(r);
    cosr = cosf(r);
    sinp = sinf(p);
    cosp = cosf(p);

    mf[0][0] = cosp;
    mf[0][1] = 0;
    mf[0][2] = -sinp;

    mf[1][0] = sinp * sinr;
    mf[1][1] = cosr;
    mf[1][2] = cosp * sinr;

    mf[2][0] = sinp * cosr;
    mf[2][1] = -sinr;
    mf[2][2] = cosp * cosr;

    mf[0][3] = mf[1][3] = mf[2][3] = mf[3][0] = mf[3][1] = mf[3][2] = 0;

    mf[3][3] = 1.0f;
}

void hal_rotate_rp(Mtx* m, f32 p, f32 h) {
    Mtx4f mf;

    hal_rotate_rp_f(mf, p, h);
    hal_mtx_f2l_fixed_w(mf, m);
}

void hal_rotate_rp_translate_f(Mtx4f mf, f32 dx, f32 dy, f32 dz, f32 r, f32 p) {
    hal_rotate_rp_f(mf, r, p);
    mf[3][0] = dx;
    mf[3][1] = dy;
    mf[3][2] = dz;
}

void hal_rotate_rp_translate(Mtx* m, f32 dx, f32 dy, f32 dz, f32 r, f32 p) {
    Mtx4f mf;

    hal_rotate_rp_translate_f(mf, dx, dy, dz, r, p);
    hal_mtx_f2l_fixed_w(mf, m);
}

// this has to be a fake matching, but whatever: it's unused
void hal_rotate_yaw_f(Mtx4f mf, f32 h) {
    f32 sinh;
    f32 cosh;

    sinh = sinf(h);
    cosh = cosf(h);

    mf[0][0] = mf[1][1] = cosh;
    mf[0][1] = sinh;

    mf[1][0] = -sinh;
    mf[1][1] = cosh; // necessary for matching

    mf[2][1] = 0;
    mf[2][0] = 0;

    mf[1][2] = 0;
    mf[0][2] = 0;

    mf[3][2] = 0;
    mf[3][1] = 0;
    mf[3][0] = 0;

    mf[2][3] = 0;
    mf[1][3] = 0;
    mf[0][3] = 0;

    mf[2][2] = mf[3][3] = 1;
}

void hal_rotate_yaw(Mtx* m, f32 h) {
    Mtx4f mf;

    hal_rotate_yaw_f(mf, h);
    hal_mtx_f2l_fixed_w(mf, m);
}

void hal_rotate_yaw_translate_f(Mtx4f mf, f32 dx, f32 dy, f32 dz, f32 h) {
    hal_rotate_yaw_f(mf, h);
    mf[3][0] = dx;
    mf[3][1] = dy;
    mf[3][2] = dz;
}

void hal_rotate_yaw_translate(Mtx* m, f32 dx, f32 dy, f32 dz, f32 h) {
    Mtx4f mf;

    hal_rotate_yaw_translate_f(mf, dx, dy, dz, h);
    hal_mtx_f2l_fixed_w(mf, m);
}

void hal_rotate_pitch_f(Mtx4f mf, f32 p) {
    f32 sinp;
    f32 cosp;

    sinp = sinf(p);
    cosp = cosf(p);

    mf[0][0] = mf[2][2] = cosp;

    mf[0][2] = -sinp;
    mf[2][0] = sinp;

    mf[2][2] = cosp; // necessary for matching

    mf[2][1] = 0;
    mf[1][0] = 0;

    mf[1][2] = 0;
    mf[0][1] = 0;

    mf[3][2] = 0;
    mf[3][1] = 0;
    mf[3][0] = 0;

    mf[2][3] = 0;
    mf[1][3] = 0;
    mf[0][3] = 0;

    mf[1][1] = mf[3][3] = 1;
}

void hal_rotate_pitch(Mtx* m, f32 p) {
    Mtx4f mf;

    hal_rotate_pitch_f(mf, p);
    hal_mtx_f2l_fixed_w(mf, m);
}

void hal_rotate_pitch_translate_f(Mtx4f mf, f32 dx, f32 dy, f32 dz, f32 p) {
    hal_rotate_pitch_f(mf, p);
    mf[3][0] = dx;
    mf[3][1] = dy;
    mf[3][2] = dz;
}

void hal_rotate_pitch_translate(Mtx* m, f32 dx, f32 dy, f32 dz, f32 p) {
    Mtx4f mf;

    hal_rotate_pitch_translate_f(mf, dx, dy, dz, p);
    hal_mtx_f2l_fixed_w(mf, m);
}

void hal_rotate_f_deg(Mtx4f mf, f32 a, f32 x, f32 y, f32 z) {
    hal_rotate_f(mf, (a * M_PI_F) / 180.0f, x, y, z);
}

void hal_rotate_deg(Mtx* m, f32 a, f32 x, f32 y, f32 z) {
    Mtx4f mf;

    hal_rotate_f(mf, (a * M_PI_F) / 180.0f, x, y, z);
    hal_mtx_f2l_fixed_w(mf, m);
}

void hal_rotate_translate_f_deg(
    Mtx4f mf,
    f32 dx,
    f32 dy,
    f32 dz,
    f32 a,
    f32 rx,
    f32 ry,
    f32 rz) {
    hal_rotate_translate_f(mf, dx, dy, dz, (a * M_PI_F) / 180.0f, rx, ry, rz);
}

void hal_rotate_translate_deg(Mtx* m, f32 dx, f32 dy, f32 dz, f32 a, f32 rx, f32 ry, f32 rz) {
    Mtx4f mf;

    hal_rotate_translate_f(mf, dx, dy, dz, (a * M_PI_F) / 180.0f, rx, ry, rz);
    hal_mtx_f2l_fixed_w(mf, m);
}

void hal_rotate_rpy_f_deg(Mtx4f mf, f32 r, f32 p, f32 h) {
    hal_rotate_rpy_f(mf, (r * M_PI_F) / 180.0f, (p * M_PI_F) / 180.0f, (h * M_PI_F) / 180.0f);
}

void hal_rotate_rpy_deg(Mtx* m, f32 r, f32 p, f32 h) {
    Mtx4f mf;

    hal_rotate_rpy_f(mf, (r * M_PI_F) / 180.0f, (p * M_PI_F) / 180.0f, (h * M_PI_F) / 180.0f);
    hal_mtx_f2l_fixed_w(mf, m);
}

void hal_rotate_rpy_translate_f_deg(Mtx4f mf, f32 dx, f32 dy, f32 dz, f32 r, f32 p, f32 h) {
    hal_rotate_rpy_translate_f(
        mf, dx, dy, dz, (r * M_PI_F) / 180.0f, (p * M_PI_F) / 180.0f, (h * M_PI_F) / 180.0f);
}

void hal_rotate_rpy_translate_deg(Mtx* m, f32 dx, f32 dy, f32 dz, f32 r, f32 p, f32 h) {
    Mtx4f mf;

    hal_rotate_rpy_translate_f(
        mf, dx, dy, dz, (r * M_PI_F) / 180.0f, (p * M_PI_F) / 180.0f, (h * M_PI_F) / 180.0f);
    hal_mtx_f2l_fixed_w(mf, m);
}

void func_8001EA90(Mtx4f m,
                   f32 x, f32 y, f32 z,
                   f32 rotX, f32 rotY, f32 rotZ,
                   f32 renScaleX, f32 renScaleY, f32 renScaleZ,
                   f32 scaleX, f32 scaleY, f32 scaleZ);
#pragma GLOBAL_ASM("asm/nonmatchings/sys/matrix/func_8001EA90.s")

void func_8001ECD0(Mtx* m,
                   f32 x, f32 y, f32 z,
                   f32 rotX, f32 rotY, f32 rotZ,
                   f32 renScaleX, f32 renScaleY, f32 renScaleZ,
                   f32 scaleX, f32 scaleY, f32 scaleZ) {
    Mtx4f sp40;

    func_8001EA90(sp40, x, y, z, rotX, rotY, rotZ, renScaleX, renScaleY, renScaleZ, scaleX, scaleY, scaleZ);
    hal_mtx_f2l_fixed_w(sp40, m);
}
