#ifndef TUNNEL_1A6630_DECLARATIONS_H
#define TUNNEL_1A6630_DECLARATIONS_H

#include "common.h"
#include "anim_script.h"

struct tunnel_1A6630_Animation80160500 {
    AnimLine1 command_80160500;
    AnimLine0 command_80160508;
    AnimLinePtr command_8016050C;
};

struct tunnel_1A6630_Animation80160514 {
    AnimLine1 command_80160514;
    AnimLine0 command_8016051C;
    AnimLinePtr command_80160520;
};

struct tunnel_1A6630_Animation80160528 {
    AnimLine1 command_80160528;
    AnimLine0 command_80160530;
    AnimLinePtr command_80160534;
};

struct tunnel_1A6630_Animation8016053C {
    AnimLine1 command_8016053C;
    AnimLine1 command_80160544;
    AnimLine1 command_8016054C;
    AnimLine0 command_80160554;
    AnimLinePtr command_80160558;
};

struct tunnel_1A6630_Animation80160560 {
    AnimLine1 command_80160560;
    AnimLine0 command_80160568;
    AnimLinePtr command_8016056C;
};

struct tunnel_1A6630_Animation80160574 {
    AnimLine1 command_80160574;
    AnimLine0 command_8016057C;
    AnimLinePtr command_80160580;
};

struct tunnel_1A6630_Animation80160588 {
    AnimLine1 command_80160588;
    AnimLine0 command_80160590;
    AnimLinePtr command_80160594;
};

struct tunnel_1A6630_Animation8016059C {
    AnimLine1 command_8016059C;
    AnimLine0 command_801605A4;
    AnimLinePtr command_801605A8;
};

struct tunnel_1A6630_Animation801605B0 {
    AnimLineI1 command_801605B0;
    AnimLineI1 command_801605B8;
    AnimLine0 command_801605C0;
    AnimLinePtr command_801605C4;
};

extern AnimCmd** D_801604D0_1A6630[12];
extern struct tunnel_1A6630_Animation80160500 D_80160500_1A6660;
extern struct tunnel_1A6630_Animation80160514 D_80160514_1A6674;
extern struct tunnel_1A6630_Animation80160528 D_80160528_1A6688;
extern struct tunnel_1A6630_Animation8016053C D_8016053C_1A669C;
extern struct tunnel_1A6630_Animation80160560 D_80160560_1A66C0;
extern struct tunnel_1A6630_Animation80160574 D_80160574_1A66D4;
extern struct tunnel_1A6630_Animation80160588 D_80160588_1A66E8;
extern struct tunnel_1A6630_Animation8016059C D_8016059C_1A66FC;
extern struct tunnel_1A6630_Animation801605B0 D_801605B0_1A6710;
extern AnimCmd* D_801605CC_1A672C[1];
extern AnimCmd* D_801605D0_1A6730[2];
extern AnimCmd* D_801605D8_1A6738[1];
extern AnimCmd* D_801605DC_1A673C[1];
extern AnimCmd* D_801605E0_1A6740[1];
extern AnimCmd* D_801605E4_1A6744[2];
extern AnimCmd* D_801605EC_1A674C[1];

#endif
