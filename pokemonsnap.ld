SECTIONS
{
    /* 0x00000000 0-40 [40] */
    .data_0 0x0 : AT(0x0) {
        build/bin/0.o(.data);
    }

    /* 0x00000000 40-1000 [FC0] */
    .data_40 0x40 : AT(0x40) {
        build/bin/40.o(.data);
    }

    /* 0x80000400 1000-1520 [520] */
    .text80000400_app 0x80000400 : AT(0x1000) {
        build/asm/app_1000.o(.text80000400_app);
    }

    /* 0x80000920 1520-5FF0 [4AD0] */
    .text80000920_app 0x80000920 : AT(0x1520) {
        build/asm/app_1520.o(.text80000920_app);
    }

    /* 0x800053F0 5FF0-8450 [2460] */
    .text800053F0_app 0x800053F0 : AT(0x5FF0) {
        build/asm/app_5FF0.o(.text800053F0_app);
    }

    /* 0x80007850 8450-8820 [3D0] */
    .text80007850_app 0x80007850 : AT(0x8450) {
        build/asm/app_8450.o(.text80007850_app);
    }

    /* 0x80007C20 8820-8A80 [260] */
    .text80007C20_app 0x80007C20 : AT(0x8820) {
        build/asm/app_8820.o(.text80007C20_app);
    }

    /* 0x80007E80 8A80-C2F0 [3870] */
    .text80007E80_app 0x80007E80 : AT(0x8A80) {
        build/asm/app_8A80.o(.text80007E80_app);
    }

    /* 0x8000B6F0 C2F0-C5B0 [2C0] */
    .text8000B6F0_app 0x8000B6F0 : AT(0xC2F0) {
        build/asm/app_C2F0.o(.text8000B6F0_app);
    }

    /* 0x8000B9B0 C5B0-D150 [BA0] */
    .text8000B9B0_app 0x8000B9B0 : AT(0xC5B0) {
        build/asm/app_C5B0.o(.text8000B9B0_app);
    }

    /* 0x8000C550 D150-11E30 [4CE0] */
    .text8000C550_app 0x8000C550 : AT(0xD150) {
        build/asm/app_D150.o(.text8000C550_app);
    }

    /* 0x80011230 11E30-1A560 [8730] */
    .text80011230_app 0x80011230 : AT(0x11E30) {
        build/asm/app_11E30.o(.text80011230_app);
    }

    /* 0x80019960 1A560-1AF60 [A00] */
    .text80019960_app 0x80019960 : AT(0x1A560) {
        build/asm/app_1A560.o(.text80019960_app);
    }

    /* 0x8001A360 1AF60-20940 [59E0] */
    .text8001A360_app 0x8001A360 : AT(0x1AF60) {
        build/asm/app_1AF60.o(.text8001A360_app);
    }

    /* 0x8001FD40 20940-245DC [3C9C] */
    .text8001FD40_app 0x8001FD40 : AT(0x20940) {
        build/asm/app_20940.o(.text8001FD40_app);
    }

    /* 0x800239DC 245DC-26D40 [2764] */
    .text800239DC_app 0x800239DC : AT(0x245DC) {
        build/asm/app_245DC.o(.text800239DC_app);
    }

    /* 0x80026140 26D40-294C0 [2780] */
    .text80026140_app 0x80026140 : AT(0x26D40) {
        build/asm/app_26D40.o(.text80026140_app);
    }

    /* 0x800288C0 294C0-29570 [B0] */
    .text800288C0_app 0x800288C0 : AT(0x294C0) {
        build/asm/app_294C0.o(.text800288C0_app);
    }

    /* 0x80028970 29570-295C0 [50] */
    .text80028970_app 0x80028970 : AT(0x29570) {
        build/asm/app_29570.o(.text80028970_app);
    }

    /* 0x800289C0 295C0-29610 [50] */
    .text800289C0_app 0x800289C0 : AT(0x295C0) {
        build/asm/app_295C0.o(.text800289C0_app);
    }

    /* 0x80028A10 29610-2AF90 [1980] */
    .text80028A10_app 0x80028A10 : AT(0x29610) {
        build/asm/app_29610.o(.text80028A10_app);
    }

    /* 0x8002A390 2AF90-2B060 [D0] */
    .text8002A390_app 0x8002A390 : AT(0x2AF90) {
        build/asm/app_2AF90.o(.text8002A390_app);
    }

    /* 0x8002A460 2B060-2B0C0 [60] */
    .text8002A460_app 0x8002A460 : AT(0x2B060) {
        build/asm/app_2B060.o(.text8002A460_app);
    }

    /* 0x8002A4C0 2B0C0-2B100 [40] */
    .text8002A4C0_app 0x8002A4C0 : AT(0x2B0C0) {
        build/asm/app_2B0C0.o(.text8002A4C0_app);
    }

    /* 0x8002A500 2B100-2B120 [20] */
    .text8002A500_app 0x8002A500 : AT(0x2B100) {
        build/asm/app_2B100.o(.text8002A500_app);
    }

    /* 0x8002A520 2B120-2B1B0 [90] */
    .text8002A520_app 0x8002A520 : AT(0x2B120) {
        build/asm/app_2B120.o(.text8002A520_app);
    }

    /* 0x8002A5B0 2B1B0-2B240 [90] */
    .text8002A5B0_app 0x8002A5B0 : AT(0x2B1B0) {
        build/asm/app_2B1B0.o(.text8002A5B0_app);
    }

    /* 0x8002A640 2B240-2B2A0 [60] */
    .text8002A640_app 0x8002A640 : AT(0x2B240) {
        build/asm/app_2B240.o(.text8002A640_app);
    }

    /* 0x8002A6A0 2B2A0-2EA70 [37D0] */
    .text8002A6A0_app 0x8002A6A0 : AT(0x2B2A0) {
        build/asm/app_2B2A0.o(.text8002A6A0_app);
    }

    /* 0x8002DE70 2EA70-2EB10 [A0] */
    .text8002DE70_app 0x8002DE70 : AT(0x2EA70) {
        build/asm/app_2EA70.o(.text8002DE70_app);
    }

    /* 0x8002DF10 2EB10-2ED30 [220] */
    .text8002DF10_app 0x8002DF10 : AT(0x2EB10) {
        build/asm/app_2EB10.o(.text8002DF10_app);
    }

    /* 0x8002E130 2ED30-32D60 [4030] */
    .text8002E130_app 0x8002E130 : AT(0x2ED30) {
        build/asm/app_2ED30.o(.text8002E130_app);
    }

    /* 0x80032160 32D60-32DF0 [90] */
    .text80032160_app 0x80032160 : AT(0x32D60) {
        build/asm/app_32D60.o(.text80032160_app);
    }

    /* 0x800321F0 32DF0-32ED0 [E0] */
    .text800321F0_app 0x800321F0 : AT(0x32DF0) {
        build/asm/app_32DF0.o(.text800321F0_app);
    }

    /* 0x800322D0 32ED0-33040 [170] */
    .text800322D0_app 0x800322D0 : AT(0x32ED0) {
        build/asm/app_32ED0.o(.text800322D0_app);
    }

    /* 0x80032440 33040-33110 [D0] */
    .text80032440_app 0x80032440 : AT(0x33040) {
        build/asm/app_33040.o(.text80032440_app);
    }

    /* 0x80032510 33110-331B0 [A0] */
    .text80032510_app 0x80032510 : AT(0x33110) {
        build/asm/app_33110.o(.text80032510_app);
    }

    /* 0x800325B0 331B0-33230 [80] */
    .text800325B0_app 0x800325B0 : AT(0x331B0) {
        build/asm/app_331B0.o(.text800325B0_app);
    }

    /* 0x80032630 33230-33380 [150] */
    .text80032630_app 0x80032630 : AT(0x33230) {
        build/asm/app_33230.o(.text80032630_app);
    }

    /* 0x80032780 33380-33580 [200] */
    .text80032780_app 0x80032780 : AT(0x33380) {
        build/asm/app_33380.o(.text80032780_app);
    }

    /* 0x80032980 33580-33AD0 [550] */
    .text80032980_app 0x80032980 : AT(0x33580) {
        build/asm/app_33580.o(.text80032980_app);
    }

    /* 0x80032ED0 33AD0-33BE0 [110] */
    .text80032ED0_app 0x80032ED0 : AT(0x33AD0) {
        build/asm/app_33AD0.o(.text80032ED0_app);
    }

    /* 0x00000000 33BE0-46270 [12690] */
    .data_33BE0 0x33BE0 : AT(0x33BE0) {
        build/bin/33BE0.o(.data);
    }

    /* 0x8009A8C0 46270-47330 [10C0] */
    .text8009A8C0_app_render 0x8009A8C0 : AT(0x46270) {
        build/asm/app_render_46270.o(.text8009A8C0_app_render);
    }

    /* 0x8009B980 47330-47380 [50] */
    .text8009B980_app_render 0x8009B980 : AT(0x47330) {
        build/src/app_render_47330.o(.text);
    }

    /* 0x8009B9D0 47380-4D880 [6500] */
    .text8009B9D0_app_render 0x8009B9D0 : AT(0x47380) {
        build/asm/app_render_47380.o(.text8009B9D0_app_render);
    }

    /* 0x800A1ED0 4D880-52D70 [54F0] */
    .text800A1ED0_app_render 0x800A1ED0 : AT(0x4D880) {
        build/asm/app_render_4D880.o(.text800A1ED0_app_render);
    }

    /* 0x800A73C0 52D70-56880 [3B10] */
    .text800A73C0_app_render 0x800A73C0 : AT(0x52D70) {
        build/asm/app_render_52D70.o(.text800A73C0_app_render);
    }

    /* 0x800AAED0 56880-568D0 [50] */
    .text800AAED0_app_render 0x800AAED0 : AT(0x56880) {
        build/src/app_render_56880.o(.text);
    }

    /* 0x800AAF20 568D0-57580 [CB0] */
    .text800AAF20_app_render 0x800AAF20 : AT(0x568D0) {
        build/asm/app_render_568D0.o(.text800AAF20_app_render);
    }

    /* 0x00000000 57580-5BF20 [49A0] */
    .data_57580 0x57580 : AT(0x57580) {
        build/bin/57580.o(.data);
    }

    /* 0x800BF080 5BF20-5EF80 [3060] */
    .text800BF080_more_funcs 0x800BF080 : AT(0x5BF20) {
        build/asm/more_funcs_5BF20.o(.text800BF080_more_funcs);
    }

    /* 0x00000000 5EF80-5F050 [D0] */
    .data_5EF80 0x5EF80 : AT(0x5EF80) {
        build/bin/5EF80.o(.data);
    }

    /* 0x800E18A0 5F050-617A0 [2750] */
    .text800E18A0_level_low 0x800E18A0 : AT(0x5F050) {
        build/asm/level_low_5F050.o(.text800E18A0_level_low);
    }

    /* 0x800E3FF0 617A0-617F0 [50] */
    .text800E3FF0_level_low 0x800E3FF0 : AT(0x617A0) {
        build/src/level_low_617A0.o(.text);
    }

    /* 0x800E4040 617F0-64280 [2A90] */
    .text800E4040_level_low 0x800E4040 : AT(0x617F0) {
        build/asm/level_low_617F0.o(.text800E4040_level_low);
    }

    /* 0x00000000 64280-4F0610 [48C390] */
    .data_64280 0x64280 : AT(0x64280) {
        build/bin/64280.o(.data);
    }

    /* 0x80350200 4F0610-4F8B30 [8520] */
    .text80350200_app_level 0x80350200 : AT(0x4F0610) {
        build/asm/app_level_4F0610.o(.text80350200_app_level);
    }

    /* 0x80358720 4F8B30-4FCFC0 [4490] */
    .text80358720_app_level 0x80358720 : AT(0x4F8B30) {
        build/asm/app_level_4F8B30.o(.text80358720_app_level);
    }

    /* 0x8035CBB0 4FCFC0-503C10 [6C50] */
    .text8035CBB0_app_level 0x8035CBB0 : AT(0x4FCFC0) {
        build/asm/app_level_4FCFC0.o(.text8035CBB0_app_level);
    }

    /* 0x80363800 503C10-5047F0 [BE0] */
    .text80363800_app_level 0x80363800 : AT(0x503C10) {
        build/asm/app_level_503C10.o(.text80363800_app_level);
    }

    /* 0x803643E0 5047F0-506290 [1AA0] */
    .text803643E0_app_level 0x803643E0 : AT(0x5047F0) {
        build/asm/app_level_5047F0.o(.text803643E0_app_level);
    }

    /* 0x80365E80 506290-5064F0 [260] */
    .text80365E80_app_level 0x80365E80 : AT(0x506290) {
        build/asm/app_level_506290.o(.text80365E80_app_level);
    }

    /* 0x803660E0 5064F0-506DD0 [8E0] */
    .text803660E0_app_level 0x803660E0 : AT(0x5064F0) {
        build/asm/app_level_5064F0.o(.text803660E0_app_level);
    }

    /* 0x803669C0 506DD0-506FB0 [1E0] */
    .text803669C0_app_level 0x803669C0 : AT(0x506DD0) {
        build/asm/app_level_506DD0.o(.text803669C0_app_level);
    }

    /* 0x00000000 506FB0-55C110 [55160] */
    .data_506FB0 0x506FB0 : AT(0x506FB0) {
        build/bin/506FB0.o(.data);
    }

    /* 0x802C40A0 55C110-55C870 [760] */
    .text802C40A0_beach_code 0x802C40A0 : AT(0x55C110) {
        build/asm/beach_code_55C110.o(.text802C40A0_beach_code);
    }

    /* 0x802C4800 55C870-55D1C0 [950] */
    .text802C4800_beach_code 0x802C4800 : AT(0x55C870) {
        build/asm/beach_code_55C870.o(.text802C4800_beach_code);
    }

    /* 0x802C5150 55D1C0-55F350 [2190] */
    .text802C5150_beach_code 0x802C5150 : AT(0x55D1C0) {
        build/asm/beach_code_55D1C0.o(.text802C5150_beach_code);
    }

    /* 0x802C72E0 55F350-55FB80 [830] */
    .text802C72E0_beach_code 0x802C72E0 : AT(0x55F350) {
        build/asm/beach_code_55F350.o(.text802C72E0_beach_code);
    }

    /* 0x802C7B10 55FB80-560620 [AA0] */
    .text802C7B10_beach_code 0x802C7B10 : AT(0x55FB80) {
        build/asm/beach_code_55FB80.o(.text802C7B10_beach_code);
    }

    /* 0x802C85B0 560620-561B30 [1510] */
    .text802C85B0_beach_code 0x802C85B0 : AT(0x560620) {
        build/asm/beach_code_560620.o(.text802C85B0_beach_code);
    }

    /* 0x802C9AC0 561B30-562110 [5E0] */
    .text802C9AC0_beach_code 0x802C9AC0 : AT(0x561B30) {
        build/asm/beach_code_561B30.o(.text802C9AC0_beach_code);
    }

    /* 0x802CA0A0 562110-562370 [260] */
    .text802CA0A0_beach_code 0x802CA0A0 : AT(0x562110) {
        build/asm/beach_code_562110.o(.text802CA0A0_beach_code);
    }

    /* 0x802CA300 562370-563E80 [1B10] */
    .text802CA300_beach_code 0x802CA300 : AT(0x562370) {
        build/asm/beach_code_562370.o(.text802CA300_beach_code);
    }

    /* 0x00000000 563E80-5DF5D0 [7B750] */
    .data_563E80 0x563E80 : AT(0x563E80) {
        build/bin/563E80.o(.data);
    }

    /* 0x802E2500 5DF5D0-5E0A70 [14A0] */
    .text802E2500_tunnel_code 0x802E2500 : AT(0x5DF5D0) {
        build/asm/tunnel_code_5DF5D0.o(.text802E2500_tunnel_code);
    }

    /* 0x802E39A0 5E0A70-5E1C10 [11A0] */
    .text802E39A0_tunnel_code 0x802E39A0 : AT(0x5E0A70) {
        build/asm/tunnel_code_5E0A70.o(.text802E39A0_tunnel_code);
    }

    /* 0x802E4B40 5E1C10-5E21C0 [5B0] */
    .text802E4B40_tunnel_code 0x802E4B40 : AT(0x5E1C10) {
        build/asm/tunnel_code_5E1C10.o(.text802E4B40_tunnel_code);
    }

    /* 0x802E50F0 5E21C0-5E4750 [2590] */
    .text802E50F0_tunnel_code 0x802E50F0 : AT(0x5E21C0) {
        build/asm/tunnel_code_5E21C0.o(.text802E50F0_tunnel_code);
    }

    /* 0x802E7680 5E4750-5E64A0 [1D50] */
    .text802E7680_tunnel_code 0x802E7680 : AT(0x5E4750) {
        build/asm/tunnel_code_5E4750.o(.text802E7680_tunnel_code);
    }

    /* 0x802E93D0 5E64A0-5E8930 [2490] */
    .text802E93D0_tunnel_code 0x802E93D0 : AT(0x5E64A0) {
        build/asm/tunnel_code_5E64A0.o(.text802E93D0_tunnel_code);
    }

    /* 0x802EB860 5E8930-5EA6F0 [1DC0] */
    .text802EB860_tunnel_code 0x802EB860 : AT(0x5E8930) {
        build/asm/tunnel_code_5E8930.o(.text802EB860_tunnel_code);
    }

    /* 0x802ED620 5EA6F0-5EAFD0 [8E0] */
    .text802ED620_tunnel_code 0x802ED620 : AT(0x5EA6F0) {
        build/asm/tunnel_code_5EA6F0.o(.text802ED620_tunnel_code);
    }

    /* 0x00000000 5EAFD0-6401B0 [551E0] */
    .data_5EAFD0 0x5EAFD0 : AT(0x5EAFD0) {
        build/bin/5EAFD0.o(.data);
    }

    /* 0x802BDD00 6401B0-640900 [750] */
    .text802BDD00_cave_code 0x802BDD00 : AT(0x6401B0) {
        build/asm/cave_code_6401B0.o(.text802BDD00_cave_code);
    }

    /* 0x802BE450 640900-640CD0 [3D0] */
    .text802BE450_cave_code 0x802BE450 : AT(0x640900) {
        build/asm/cave_code_640900.o(.text802BE450_cave_code);
    }

    /* 0x802BE820 640CD0-6414D0 [800] */
    .text802BE820_cave_code 0x802BE820 : AT(0x640CD0) {
        build/asm/cave_code_640CD0.o(.text802BE820_cave_code);
    }

    /* 0x802BF020 6414D0-641A50 [580] */
    .text802BF020_cave_code 0x802BF020 : AT(0x6414D0) {
        build/asm/cave_code_6414D0.o(.text802BF020_cave_code);
    }

    /* 0x802BF5A0 641A50-642290 [840] */
    .text802BF5A0_cave_code 0x802BF5A0 : AT(0x641A50) {
        build/asm/cave_code_641A50.o(.text802BF5A0_cave_code);
    }

    /* 0x802BFDE0 642290-6438F0 [1660] */
    .text802BFDE0_cave_code 0x802BFDE0 : AT(0x642290) {
        build/asm/cave_code_642290.o(.text802BFDE0_cave_code);
    }

    /* 0x802C1440 6438F0-645740 [1E50] */
    .text802C1440_cave_code 0x802C1440 : AT(0x6438F0) {
        build/asm/cave_code_6438F0.o(.text802C1440_cave_code);
    }

    /* 0x802C3290 645740-646B50 [1410] */
    .text802C3290_cave_code 0x802C3290 : AT(0x645740) {
        build/asm/cave_code_645740.o(.text802C3290_cave_code);
    }

    /* 0x802C46A0 646B50-646EA0 [350] */
    .text802C46A0_cave_code 0x802C46A0 : AT(0x646B50) {
        build/asm/cave_code_646B50.o(.text802C46A0_cave_code);
    }

    /* 0x802C49F0 646EA0-647360 [4C0] */
    .text802C49F0_cave_code 0x802C49F0 : AT(0x646EA0) {
        build/asm/cave_code_646EA0.o(.text802C49F0_cave_code);
    }

    /* 0x802C4EB0 647360-648600 [12A0] */
    .text802C4EB0_cave_code 0x802C4EB0 : AT(0x647360) {
        build/asm/cave_code_647360.o(.text802C4EB0_cave_code);
    }

    /* 0x00000000 648600-6C05E0 [77FE0] */
    .data_648600 0x648600 : AT(0x648600) {
        build/bin/648600.o(.data);
    }

    /* 0x802D8800 6C05E0-6C1090 [AB0] */
    .text802D8800_river_code 0x802D8800 : AT(0x6C05E0) {
        build/asm/river_code_6C05E0.o(.text802D8800_river_code);
    }

    /* 0x802D92B0 6C1090-6C22E0 [1250] */
    .text802D92B0_river_code 0x802D92B0 : AT(0x6C1090) {
        build/asm/river_code_6C1090.o(.text802D92B0_river_code);
    }

    /* 0x802DA500 6C22E0-6C26F0 [410] */
    .text802DA500_river_code 0x802DA500 : AT(0x6C22E0) {
        build/asm/river_code_6C22E0.o(.text802DA500_river_code);
    }

    /* 0x802DA910 6C26F0-6C3980 [1290] */
    .text802DA910_river_code 0x802DA910 : AT(0x6C26F0) {
        build/asm/river_code_6C26F0.o(.text802DA910_river_code);
    }

    /* 0x802DBBA0 6C3980-6C4CD0 [1350] */
    .text802DBBA0_river_code 0x802DBBA0 : AT(0x6C3980) {
        build/asm/river_code_6C3980.o(.text802DBBA0_river_code);
    }

    /* 0x802DCEF0 6C4CD0-6C66E0 [1A10] */
    .text802DCEF0_river_code 0x802DCEF0 : AT(0x6C4CD0) {
        build/asm/river_code_6C4CD0.o(.text802DCEF0_river_code);
    }

    /* 0x802DE900 6C66E0-6C6A70 [390] */
    .text802DE900_river_code 0x802DE900 : AT(0x6C66E0) {
        build/asm/river_code_6C66E0.o(.text802DE900_river_code);
    }

    /* 0x802DEC90 6C6A70-6C7CD0 [1260] */
    .text802DEC90_river_code 0x802DEC90 : AT(0x6C6A70) {
        build/asm/river_code_6C6A70.o(.text802DEC90_river_code);
    }

    /* 0x802DFEF0 6C7CD0-6C85D0 [900] */
    .text802DFEF0_river_code 0x802DFEF0 : AT(0x6C7CD0) {
        build/asm/river_code_6C7CD0.o(.text802DFEF0_river_code);
    }

    /* 0x802E07F0 6C85D0-6C9EB0 [18E0] */
    .text802E07F0_river_code 0x802E07F0 : AT(0x6C85D0) {
        build/asm/river_code_6C85D0.o(.text802E07F0_river_code);
    }

    /* 0x802E20D0 6C9EB0-6CA400 [550] */
    .text802E20D0_river_code 0x802E20D0 : AT(0x6C9EB0) {
        build/asm/river_code_6C9EB0.o(.text802E20D0_river_code);
    }

    /* 0x00000000 6CA400-7272E0 [5CEE0] */
    .data_6CA400 0x6CA400 : AT(0x6CA400) {
        build/bin/6CA400.o(.data);
    }

    /* 0x802D60E0 7272E0-729CA0 [29C0] */
    .text802D60E0_volcano_code 0x802D60E0 : AT(0x7272E0) {
        build/asm/volcano_code_7272E0.o(.text802D60E0_volcano_code);
    }

    /* 0x802D8AA0 729CA0-72AF00 [1260] */
    .text802D8AA0_volcano_code 0x802D8AA0 : AT(0x729CA0) {
        build/asm/volcano_code_729CA0.o(.text802D8AA0_volcano_code);
    }

    /* 0x802D9D00 72AF00-72BCE0 [DE0] */
    .text802D9D00_volcano_code 0x802D9D00 : AT(0x72AF00) {
        build/asm/volcano_code_72AF00.o(.text802D9D00_volcano_code);
    }

    /* 0x802DAAE0 72BCE0-72C7A0 [AC0] */
    .text802DAAE0_volcano_code 0x802DAAE0 : AT(0x72BCE0) {
        build/asm/volcano_code_72BCE0.o(.text802DAAE0_volcano_code);
    }

    /* 0x802DB5A0 72C7A0-72D260 [AC0] */
    .text802DB5A0_volcano_code 0x802DB5A0 : AT(0x72C7A0) {
        build/asm/volcano_code_72C7A0.o(.text802DB5A0_volcano_code);
    }

    /* 0x802DC060 72D260-72E4E0 [1280] */
    .text802DC060_volcano_code 0x802DC060 : AT(0x72D260) {
        build/asm/volcano_code_72D260.o(.text802DC060_volcano_code);
    }

    /* 0x802DD2E0 72E4E0-72E9F0 [510] */
    .text802DD2E0_volcano_code 0x802DD2E0 : AT(0x72E4E0) {
        build/asm/volcano_code_72E4E0.o(.text802DD2E0_volcano_code);
    }

    /* 0x802DD7F0 72E9F0-72F100 [710] */
    .text802DD7F0_volcano_code 0x802DD7F0 : AT(0x72E9F0) {
        build/asm/volcano_code_72E9F0.o(.text802DD7F0_volcano_code);
    }

    /* 0x802DDF00 72F100-72F590 [490] */
    .text802DDF00_volcano_code 0x802DDF00 : AT(0x72F100) {
        build/asm/volcano_code_72F100.o(.text802DDF00_volcano_code);
    }

    /* 0x802DE390 72F590-72F770 [1E0] */
    .text802DE390_volcano_code 0x802DE390 : AT(0x72F590) {
        build/asm/volcano_code_72F590.o(.text802DE390_volcano_code);
    }

    /* 0x802DE570 72F770-72FFE0 [870] */
    .text802DE570_volcano_code 0x802DE570 : AT(0x72F770) {
        build/asm/volcano_code_72F770.o(.text802DE570_volcano_code);
    }

    /* 0x802DEDE0 72FFE0-730480 [4A0] */
    .text802DEDE0_volcano_code 0x802DEDE0 : AT(0x72FFE0) {
        build/asm/volcano_code_72FFE0.o(.text802DEDE0_volcano_code);
    }

    /* 0x802DF280 730480-731E80 [1A00] */
    .text802DF280_volcano_code 0x802DF280 : AT(0x730480) {
        build/asm/volcano_code_730480.o(.text802DF280_volcano_code);
    }

    /* 0x00000000 731E80-79F1B0 [6D330] */
    .data_731E80 0x731E80 : AT(0x731E80) {
        build/bin/731E80.o(.data);
    }

    /* 0x802C5C20 79F1B0-7A00C0 [F10] */
    .text802C5C20_valley_code 0x802C5C20 : AT(0x79F1B0) {
        build/asm/valley_code_79F1B0.o(.text802C5C20_valley_code);
    }

    /* 0x802C6B30 7A00C0-7A1850 [1790] */
    .text802C6B30_valley_code 0x802C6B30 : AT(0x7A00C0) {
        build/asm/valley_code_7A00C0.o(.text802C6B30_valley_code);
    }

    /* 0x802C82C0 7A1850-7A2B50 [1300] */
    .text802C82C0_valley_code 0x802C82C0 : AT(0x7A1850) {
        build/asm/valley_code_7A1850.o(.text802C82C0_valley_code);
    }

    /* 0x802C95C0 7A2B50-7A2DD0 [280] */
    .text802C95C0_valley_code 0x802C95C0 : AT(0x7A2B50) {
        build/asm/valley_code_7A2B50.o(.text802C95C0_valley_code);
    }

    /* 0x802C9840 7A2DD0-7A3560 [790] */
    .text802C9840_valley_code 0x802C9840 : AT(0x7A2DD0) {
        build/asm/valley_code_7A2DD0.o(.text802C9840_valley_code);
    }

    /* 0x802C9FD0 7A3560-7A3800 [2A0] */
    .text802C9FD0_valley_code 0x802C9FD0 : AT(0x7A3560) {
        build/asm/valley_code_7A3560.o(.text802C9FD0_valley_code);
    }

    /* 0x802CA270 7A3800-7A4610 [E10] */
    .text802CA270_valley_code 0x802CA270 : AT(0x7A3800) {
        build/asm/valley_code_7A3800.o(.text802CA270_valley_code);
    }

    /* 0x802CB080 7A4610-7A5F10 [1900] */
    .text802CB080_valley_code 0x802CB080 : AT(0x7A4610) {
        build/asm/valley_code_7A4610.o(.text802CB080_valley_code);
    }

    /* 0x802CC980 7A5F10-7A6D50 [E40] */
    .text802CC980_valley_code 0x802CC980 : AT(0x7A5F10) {
        build/asm/valley_code_7A5F10.o(.text802CC980_valley_code);
    }

    /* 0x802CD7C0 7A6D50-7A7410 [6C0] */
    .text802CD7C0_valley_code 0x802CD7C0 : AT(0x7A6D50) {
        build/asm/valley_code_7A6D50.o(.text802CD7C0_valley_code);
    }

    /* 0x802CDE80 7A7410-7A7790 [380] */
    .text802CDE80_valley_code 0x802CDE80 : AT(0x7A7410) {
        build/asm/valley_code_7A7410.o(.text802CDE80_valley_code);
    }

    /* 0x802CE200 7A7790-7A8030 [8A0] */
    .text802CE200_valley_code 0x802CE200 : AT(0x7A7790) {
        build/asm/valley_code_7A7790.o(.text802CE200_valley_code);
    }

    /* 0x802CEAA0 7A8030-7AA790 [2760] */
    .text802CEAA0_valley_code 0x802CEAA0 : AT(0x7A8030) {
        build/asm/valley_code_7A8030.o(.text802CEAA0_valley_code);
    }

    /* 0x802D1200 7AA790-7ABB10 [1380] */
    .text802D1200_valley_code 0x802D1200 : AT(0x7AA790) {
        build/asm/valley_code_7AA790.o(.text802D1200_valley_code);
    }

    /* 0x802D2580 7ABB10-7ABCD0 [1C0] */
    .text802D2580_valley_code 0x802D2580 : AT(0x7ABB10) {
        build/asm/valley_code_7ABB10.o(.text802D2580_valley_code);
    }

    /* 0x00000000 7ABCD0-825E30 [7A160] */
    .data_7ABCD0 0x7ABCD0 : AT(0x7ABCD0) {
        build/bin/7ABCD0.o(.data);
    }

    /* 0x803466C0 825E30-826710 [8E0] */
    .text803466C0_rainbow_code 0x803466C0 : AT(0x825E30) {
        build/asm/rainbow_code_825E30.o(.text803466C0_rainbow_code);
    }

    /* 0x80346FA0 826710-8288F0 [21E0] */
    .text80346FA0_rainbow_code 0x80346FA0 : AT(0x826710) {
        build/asm/rainbow_code_826710.o(.text80346FA0_rainbow_code);
    }

    /* 0x80349180 8288F0-829670 [D80] */
    .text80349180_rainbow_code 0x80349180 : AT(0x8288F0) {
        build/asm/rainbow_code_8288F0.o(.text80349180_rainbow_code);
    }

    /* 0x80349F00 829670-829900 [290] */
    .text80349F00_rainbow_code 0x80349F00 : AT(0x829670) {
        build/asm/rainbow_code_829670.o(.text80349F00_rainbow_code);
    }

    /* 0x8034A190 829900-82A280 [980] */
    .text8034A190_rainbow_code 0x8034A190 : AT(0x829900) {
        build/asm/rainbow_code_829900.o(.text8034A190_rainbow_code);
    }

    /* 0x00000000 82A280-83D730 [134B0] */
    .data_82A280 0x82A280 : AT(0x82A280) {
        build/bin/82A280.o(.data);
    }

    /* 0x80369F80 83D730-843790 [6060] */
    .text80369F80_unk_end_level 0x80369F80 : AT(0x83D730) {
        build/asm/unk_end_level_83D730.o(.text80369F80_unk_end_level);
    }

    /* 0x8036FFE0 843790-8486E0 [4F50] */
    .text8036FFE0_unk_end_level 0x8036FFE0 : AT(0x843790) {
        build/asm/unk_end_level_843790.o(.text8036FFE0_unk_end_level);
    }

    /* 0x80374F30 8486E0-848BC0 [4E0] */
    .text80374F30_unk_end_level 0x80374F30 : AT(0x8486E0) {
        build/asm/unk_end_level_8486E0.o(.text80374F30_unk_end_level);
    }

    /* 0x00000000 848BC0-87A0B0 [314F0] */
    .data_848BC0 0x848BC0 : AT(0x848BC0) {
        build/bin/848BC0.o(.data);
    }

    /* 0x801DC8C0 87A0B0-87A330 [280] */
    .text801DC8C0_unk_end_level_2 0x801DC8C0 : AT(0x87A0B0) {
        build/asm/unk_end_level_2_87A0B0.o(.text801DC8C0_unk_end_level_2);
    }

    /* 0x801DCB40 87A330-87D1A0 [2E70] */
    .text801DCB40_unk_end_level_2 0x801DCB40 : AT(0x87A330) {
        build/asm/unk_end_level_2_87A330.o(.text801DCB40_unk_end_level_2);
    }

    /* 0x801DF9B0 87D1A0-8817E0 [4640] */
    .text801DF9B0_unk_end_level_2 0x801DF9B0 : AT(0x87D1A0) {
        build/asm/unk_end_level_2_87D1A0.o(.text801DF9B0_unk_end_level_2);
    }

    /* 0x00000000 8817E0-8A70E0 [25900] */
    .data_8817E0 0x8817E0 : AT(0x8817E0) {
        build/bin/8817E0.o(.data);
    }

    /* 0x800E18C0 8A70E0-8A8A50 [1970] */
    .text800E18C0_unk_end_level_3 0x800E18C0 : AT(0x8A70E0) {
        build/asm/unk_end_level_3_8A70E0.o(.text800E18C0_unk_end_level_3);
    }

    /* 0x800E3230 8A8A50-8AAF60 [2510] */
    .text800E3230_unk_end_level_3 0x800E3230 : AT(0x8A8A50) {
        build/asm/unk_end_level_3_8A8A50.o(.text800E3230_unk_end_level_3);
    }

    /* 0x800E5740 8AAF60-8ABEF0 [F90] */
    .text800E5740_unk_end_level_3 0x800E5740 : AT(0x8AAF60) {
        build/asm/unk_end_level_3_8AAF60.o(.text800E5740_unk_end_level_3);
    }

    /* 0x00000000 8ABEF0-A084B0 [15C5C0] */
    .data_8ABEF0 0x8ABEF0 : AT(0x8ABEF0) {
        build/bin/8ABEF0.o(.data);
    }

    /* 0x800E1970 A084B0-A08D10 [860] */
    .text800E1970_unk_end_level_3 0x800E1970 : AT(0xA084B0) {
        build/asm/unk_end_level_3_A084B0.o(.text800E1970_unk_end_level_3);
    }

    /* 0x00000000 A08D10-AA0650 [97940] */
    .data_A08D10 0xA08D10 : AT(0xA08D10) {
        build/bin/A08D10.o(.data);
    }

    /* 0x800E18A0 AA0650-AA0A60 [410] */
    .text800E18A0_intro_code 0x800E18A0 : AT(0xAA0650) {
        build/asm/intro_code_AA0650.o(.text800E18A0_intro_code);
    }

    /* 0x00000000 AA0A60-1000000 [55F5A0] */
    .data_AA0A60 0xAA0A60 : AT(0xAA0A60) {
        build/bin/AA0A60.o(.data);
    }

}