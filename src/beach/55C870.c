#include "common.h"
#include "beach.h"

void func_beach_802C4800(s32 arg0, f32 arg1) {
    switch (D_beach_802CC0D0) {
        case 0:
            if (arg0 + arg1 <= 0.0f) {
                D_beach_80347578 = auPlaySoundWithParams(0x2B, 0x3400, 0x2C, 0.4f, 0x28);
                D_beach_80347579 = auPlaySoundWithParams(0x2B, 0x3400, 0x54, 0.5f, 0x28);
                D_beach_802CC0D0 = 1;
            }
            break;
        case 1:
            if (arg0 + arg1 > 0.0f) {
                setBackgroundMusic(0);
                D_beach_802CC0D0 = 2;
            }
            break;
        case 2:
            if ((arg0 + arg1) > 1.75f && (arg0 + arg1) < 2.0f) {
                D_beach_8034757C = ((2.0f - (arg0 + arg1)) * 5120.0f * 4.0f) + 8192.0f;
                auSetSoundVolume(D_beach_80347578, D_beach_8034757C);
                auSetSoundVolume(D_beach_80347579, D_beach_8034757C);
            } else if ((arg0 + arg1) >= 2.0f) {
                auSetSoundVolume(D_beach_80347578, 0x2000);
                auSetSoundVolume(D_beach_80347579, 0x2000);
                D_beach_802CC0D0 = 3;
            }
            break;
        case 3:
            if ((arg0 + arg1) > 3.2f && (arg0 + arg1) < 3.3f) {
                D_beach_8034757C = (((arg0 + arg1) - 3.2f) * 5120.0f * 10.0f) + 8192.0f;
                auSetSoundVolume(D_beach_80347578, D_beach_8034757C);
                auSetSoundVolume(D_beach_80347579, D_beach_8034757C);
            } else if ((arg0 + arg1) >= 3.3f) {
                auSetSoundVolume(D_beach_80347578, 0x3400);
                auSetSoundVolume(D_beach_80347579, 0x3400);
                D_beach_802CC0D0 = 4;
            }
            break;
        case 4:
            if ((arg0 + arg1) > 6.5f && (arg0 + arg1) < 7.0f) {
                D_beach_8034757C = ((7.0f - (arg0 + arg1)) * 5120.0f * 2) + 8192.0f;
                auSetSoundVolume(D_beach_80347578, D_beach_8034757C);
                auSetSoundVolume(D_beach_80347579, D_beach_8034757C);
            } else if ((arg0 + arg1) > 7.0f) {
                auSetSoundVolume(D_beach_80347578, 0x2000);
                auSetSoundVolume(D_beach_80347579, 0x2000);
                D_beach_802CC0D0 = 5;
            }
            break;
        case 5:
            break;
    }

    switch (D_beach_802CC0D4) {
        case 3:
            break;
        case 0:
            if ((arg0 + arg1) >= 3.85f) {
                D_beach_8034757B = auPlaySoundWithParams(0x22, 0x10, 0x40, 1.0f, 0x28);
                D_beach_802CC0D4 = 1;
            }
            break;
        case 1:
            if (arg0 + arg1 < 4.1f) {
                auSetSoundVolume(D_beach_8034757B, (((arg0 + arg1) - 3.85f) * 16384.0f * 4.0f));
            } else {
                auSetSoundVolume(D_beach_8034757B, 0x4000);
                D_beach_802CC0D4 = 2;
            }
            break;
        case 2:
            if ((arg0 + arg1) > 4.4f && (arg0 + arg1) < 4.65f) {
                auSetSoundVolume(D_beach_8034757B, ((4.65f - (arg0 + arg1)) * 16384.0f * 4.0f));
            } else if ((arg0 + arg1) > 4.65f) {
                auStopSound(D_beach_8034757B);
                D_beach_802CC0D4 = 3;
            }
            break;
    }

    switch (D_beach_802CC0D8) {
        case 0:
            if (arg0 + arg1 > 0.0f) {
                D_beach_8034757A = auPlaySoundWithParams(0x2D, 0x3800, 0x40, 1.0f, 0);
                D_beach_802CC0D8 = 2;
                break;
            }
        case 4:
            break;
        case 2:
            if ((arg0 + arg1) > 4.15f) {
                auSetSoundVolume(D_beach_8034757A, 0x4800);
                D_beach_802CC0D8 = 3;
            }
            break;
        case 3:
            if ((arg0 + arg1) > 4.45f) {
                auSetSoundVolume(D_beach_8034757A, 0x3800);
                D_beach_802CC0D8 = 4;
            }
            break;
    }
}
