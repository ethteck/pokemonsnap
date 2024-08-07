#include "common.h"

#include "app_level/app_level.h"

extern u32 D_802C6430_6488E0;
extern u8 D_8033E148_6C05F8;

void func_802BE450_640900(s32 arg0, f32 arg1) {
    switch (D_802C6430_6488E0) {
        case 0:
            if (arg0 + arg1 <= 0.0f) {
                auSetBGMExtraReverb(0, 0x14);
                auSetSoundGlobalReverb(0x3C);
                D_8033E148_6C05F8 = auPlaySoundWithParams(0x21, 0x3800, 0x40, 1.f, 0x14);
                D_802C6430_6488E0 = 1;
            }
            break;
        case 1:
            if (arg0 + arg1 > 0.0f) {
                setBackgroundMusic(0xD);
                D_802C6430_6488E0 = 2;
            }
            break;
        case 2:
            if (arg0 + arg1 > 0.0f && arg0 + arg1 < 0.025f) {
                auSetSoundVolume(D_8033E148_6C05F8, ((0.025f - (arg0 + arg1)) * 4096.0f * 40.0f) + 10240.0f);
            } else if (arg0 + arg1 >= 0.025f) {
                auSetSoundVolume(D_8033E148_6C05F8, 0x2800);
                D_802C6430_6488E0 = 3;
            }
            break;
        case 3:
            if (arg0 + arg1 > 0.5f && arg0 + arg1 < 1.0f) {
                auSetSoundVolume(D_8033E148_6C05F8, (1.0f - (arg0 + arg1)) * 10240.0f * 2);
            } else if (arg0 + arg1 >= 1.0f) {
                auStopSound(D_8033E148_6C05F8);
                D_802C6430_6488E0 = 4;
            }
            break;
        case 4:
            if (arg0 + arg1 > 2.0f) {
                auPlaySong(1, 0xF);
                D_802C6430_6488E0 = 5;
            }
            break;
        case 5:
            if (arg0 + arg1 > 3.0f) {
                auStopSong(1);
                D_802C6430_6488E0 = 6;
            }
            break;
        case 6:
            break;
    }
}
