#include "world/world.h"
#include "anim_script.h"

struct bank_64420_Animation800E91C8 {
    AnimLine1 command_800E91C8;
    AnimLine1 command_800E91D0;
    AnimLine1 command_800E91D8;
    AnimLine1 command_800E91E0;
    AnimLine1 command_800E91E8;
    AnimLine1 command_800E91F0;
    AnimLine1 command_800E91F8;
    AnimLine1 command_800E9200;
    AnimLine1 command_800E9208;
    AnimLinePtr command_800E9210;
};

struct bank_64420_Animation800EAF68 {
    AnimLine1 command_800EAF68;
    AnimLine1 command_800EAF70;
    AnimLine1 command_800EAF78;
    AnimLine1 command_800EAF80;
    AnimLine1 command_800EAF88;
    AnimLine1 command_800EAF90;
    AnimLine1 command_800EAF98;
    AnimLinePtr command_800EAFA0;
};

struct bank_64420_Animation800EAFC0 {
    AnimLine0 command_800EAFC0;
    AnimLine0 command_800EAFC4;
    AnimLine0 command_800EAFC8;
};

struct bank_64420_Animation800EAFCC {
    AnimLine2 command_800EAFCC;
    AnimLine1 command_800EAFD8;
    AnimLine4 command_800EAFE0;
    AnimLine4 command_800EAFF4;
    AnimLine2 command_800EB008;
    AnimLine2 command_800EB014;
    AnimLine0 command_800EB020;
};

struct bank_64420_Animation800EB024 {
    AnimLine2 command_800EB024;
    AnimLine1 command_800EB030;
    AnimLine2 command_800EB038;
    AnimLine1 command_800EB044;
    AnimLine4 command_800EB04C;
    AnimLine1 command_800EB060;
    AnimLine2 command_800EB068;
    AnimLine1 command_800EB074;
    AnimLine2 command_800EB07C;
    AnimLine0 command_800EB088;
};

struct bank_64420_Animation800EB08C {
    AnimLine4 command_800EB08C;
    AnimLine1 command_800EB0A0;
    AnimLine2 command_800EB0A8;
    AnimLine0 command_800EB0B4;
};

struct bank_64420_Animation800EB0D0 {
    AnimLineI1 command_800EB0D0;
    AnimLineI1 command_800EB0D8;
    AnimLineI1 command_800EB0E0;
    AnimLine0 command_800EB0E8;
};

struct bank_64420_Animation800ED5C0 {
    AnimLine2 command_800ED5C0;
    AnimLine1 command_800ED5CC;
    AnimLine4 command_800ED5D4;
    AnimLine4 command_800ED5E8;
    AnimLine2 command_800ED5FC;
    AnimLine2 command_800ED608;
    AnimLine0 command_800ED614;
};

struct bank_64420_Animation800ED618 {
    AnimLine2 command_800ED618;
    AnimLine1 command_800ED624;
    AnimLine2 command_800ED62C;
    AnimLine1 command_800ED638;
    AnimLine4 command_800ED640;
    AnimLine1 command_800ED654;
    AnimLine2 command_800ED65C;
    AnimLine1 command_800ED668;
    AnimLine2 command_800ED670;
    AnimLine0 command_800ED67C;
};

struct bank_64420_Animation800ED680 {
    AnimLine4 command_800ED680;
    AnimLine1 command_800ED694;
    AnimLine2 command_800ED69C;
    AnimLine0 command_800ED6A8;
};

struct bank_64420_Animation800ED6C0 {
    AnimLineI1 command_800ED6C0;
    AnimLineI1 command_800ED6C8;
    AnimLineI1 command_800ED6D0;
    AnimLine0 command_800ED6D8;
};

extern u32 D_800E6C70_64420[2];
extern u8 D_800E6C78_64428[512];
extern u32 D_800E6E78_64628[2];
extern u8 D_800E6E80_64630[1024];
extern u32 D_800E7280_64A30[2];
extern u8 D_800E7288_64A38[1024];
extern u32 D_800E7688_64E38[2];
extern u8 D_800E7690_64E40[1024];
extern u32 D_800E7A90_65240[2];
extern u8 D_800E7A98_65248[1024];
extern u32 D_800E7E98_65648[2];
extern u8 D_800E7EA0_65650[1024];
extern u32 D_800E82A0_65A50[2];
extern u8 D_800E82A8_65A58[1024];
extern u32 D_800E86A8_65E58[2];
extern u8 D_800E86B0_65E60[1024];
extern u32 D_800E8AB0_66260[2];
extern u8 D_800E8AB8_66268[1024];
extern Texture** D_800E8EB8[2];
extern u8* D_800E8EC0_66670[8];
extern Texture D_800E8EE0_66690;
extern Texture* D_800E8F58_66708[2];
extern Vtx D_800E8F60_66710[12];
extern Gfx D_800E9020_667D0[35];
extern UnkEC64Arg3 D_800E9138[3];
extern u32 D_800E91BC_6696C[1];
extern AnimCmd** D_800E91C0[2];
extern struct bank_64420_Animation800E91C8 D_800E91C8_66978;
extern AnimCmd* D_800E9218_669C8[1];
extern u32 D_800E921C_669CC[1];
extern u32 D_800E9220_669D0[2];
extern u8 D_800E9228_669D8[512];
extern u32 D_800E9428_66BD8[2];
extern u8 D_800E9430_66BE0[1024];
extern u32 D_800E9830_66FE0[2];
extern u8 D_800E9838_66FE8[1024];
extern u32 D_800E9C38_673E8[2];
extern u8 D_800E9C40_673F0[1024];
extern u32 D_800EA040_677F0[2];
extern u8 D_800EA048_677F8[1024];
extern u32 D_800EA448_67BF8[2];
extern u8 D_800EA450_67C00[1024];
extern u32 D_800EA850_68000[2];
extern u8 D_800EA858_68008[1024];
extern Texture** D_800EAC58[2];
extern u8* D_800EAC60_68410[6];
extern Texture D_800EAC78_68428;
extern Texture* D_800EACF0_684A0[2];
extern Vtx D_800EACF8_684A8[12];
extern Gfx D_800EADB8_68568[35];
extern UnkEC64Arg3 D_800EAED0[3];
extern u32 D_800EAF54_68704[3];
extern AnimCmd** D_800EAF60[2];
extern struct bank_64420_Animation800EAF68 D_800EAF68_68718;
extern AnimCmd* D_800EAFA8_68758[1];
extern u32 D_800EAFAC_6875C[1];
extern AnimCmd* D_800EAFB0[4];
extern struct bank_64420_Animation800EAFC0 D_800EAFC0_68770;
extern struct bank_64420_Animation800EAFCC D_800EAFCC_6877C;
extern struct bank_64420_Animation800EB024 D_800EB024_687D4;
extern struct bank_64420_Animation800EB08C D_800EB08C_6883C;
extern u32 D_800EB0B8_68868[2];
extern AnimCmd** D_800EB0C0[4];
extern struct bank_64420_Animation800EB0D0 D_800EB0D0_68880;
extern AnimCmd* D_800EB0EC_6889C[1];
extern Vtx D_800EB0F0_688A0[24];
extern Gfx D_800EB270_68A20[10];
extern Gfx D_800EB2C0_68A70[11];
extern Gfx D_800EB318_68AC8[11];
extern Gfx D_800EB370_68B20[12];
extern Gfx D_800EB3D0_68B80[6];
extern DObjPayloadTypeC D_800EB400_68BB0[2];
extern DObjPayloadTypeC D_800EB410_68BC0[2];
extern DObjPayloadTypeC D_800EB420_68BD0[2];
extern UnkEC64Arg3 D_800EB430[5];
extern u32 D_800EB50C_68CBC[1];
extern Texture** D_800EB510[4];
extern Texture D_800EB520_68CD0;
extern Texture* D_800EB598_68D48[2];
extern u32 D_800EB5A0_68D50[2];
extern u8 D_800EB5A8_68D58[4096];
extern u32 D_800EC5A8_69D58[2];
extern u8 D_800EC5B0_69D60[4096];
extern AnimCmd* D_800ED5B0[4];
extern struct bank_64420_Animation800ED5C0 D_800ED5C0_6AD70;
extern struct bank_64420_Animation800ED618 D_800ED618_6ADC8;
extern struct bank_64420_Animation800ED680 D_800ED680_6AE30;
extern u32 D_800ED6AC_6AE5C[1];
extern AnimCmd** D_800ED6B0[4];
extern struct bank_64420_Animation800ED6C0 D_800ED6C0_6AE70;
extern AnimCmd* D_800ED6DC_6AE8C[1];
extern Vtx D_800ED6E0_6AE90[24];
extern Gfx D_800ED860_6B010[15];
extern Gfx D_800ED8D8_6B088[15];
extern Gfx D_800ED950_6B100[15];
extern Gfx D_800ED9C8_6B178[16];
extern Gfx D_800EDA48_6B1F8[7];
extern DObjPayloadTypeC D_800EDA80_6B230[2];
extern DObjPayloadTypeC D_800EDA90_6B240[2];
extern DObjPayloadTypeC D_800EDAA0_6B250[2];
extern UnkEC64Arg3 D_800EDAB0[5];
extern u32 D_800EDB8C_6B33C[1];
extern Texture** D_800EDB90[4];
extern Texture D_800EDBA0_6B350;
extern Texture* D_800EDC18_6B3C8[2];
extern Vtx D_800EDC20_6B3D0[9];
extern Gfx D_800EDCB0_6B460[13];
extern Gfx D_800EDD18_6B4C8[5];
extern HitBoxType4 D_800EDD40_6B4F0;
extern HitBoxType4 D_800EDDD0_6B580;
extern HitBoxType4 D_800EDE60_6B610;
extern HitBoxType1 D_800EDEF0_6B6A0;
extern Collider D_800EDF78_6B728[9];
extern u32 D_800EE104_6B8B4[3];
