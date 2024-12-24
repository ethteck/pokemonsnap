#include "valley.h"

extern u32 D_802D2A90_7AC020;
extern u32 D_802D2A94_7AC024;
extern u8 D_8034C8C8_825E58[];

void func_802C6B30_7A00C0(s32 arg0, f32 arg1) {
    switch (D_802D2A90_7AC020) {
        case 0:
            D_8034C8C8_825E58[0] = auPlaySoundWithParams(0x22, 0x3800, 0x40, 1, 0x3C);
            D_802D2A90_7AC020 = 1;
            break;
        case 1:
            if ((arg0 + arg1) > 0.0f) {
                setBackgroundMusic(7);
                D_802D2A90_7AC020 = 3;
            }
            break;
        case 3:
            if (((arg0 + arg1) > 1.8f) && ((arg0 + arg1) < 2.05f)) {
                auSetSoundVolume(D_8034C8C8_825E58[0], (((arg0 + arg1) - 1.8f) * 6144.0f * 4) + 14336.0f);
            } else if ((arg0 + arg1) >= 2.05f) {
                auSetSoundVolume(D_8034C8C8_825E58[0], 0x5000);
                D_802D2A90_7AC020 = 4;
            }
            break;
        case 4:
            if (((arg0 + arg1) > 3.0f) && ((arg0 + arg1) < 3.25f)) {
                auSetSoundVolume(D_8034C8C8_825E58[0], ((3.25f - (arg0 + arg1)) * 6144.0f * 4) + 14336.0f);
            } else if ((arg0 + arg1) >= 3.25f) {
                auSetSoundVolume(D_8034C8C8_825E58[0], 0x3800);
                D_802D2A90_7AC020 = 5;
            }
            break;
        case 5:
            if (((arg0 + arg1) > 4.0f) && ((arg0 + arg1) < 4.25f)) {
                auSetSoundVolume(D_8034C8C8_825E58[0], (((arg0 + arg1) - 4.0f) * 6144.0f * 4) + 14336.0f);
            } else if ((arg0 + arg1) >= 4.25f) {
                auSetSoundVolume(D_8034C8C8_825E58[0], 0x5000);
                D_802D2A90_7AC020 = 6;
            }
            break;
        case 6:
            if (((arg0 + arg1) > 4.58f) && ((arg0 + arg1) < 5.08f)) {
                auSetSoundVolume(D_8034C8C8_825E58[0], ((5.08f - (arg0 + arg1)) * 3072.0f * 2) + 17408.0f);
            } else if ((arg0 + arg1) >= 5.08f) {
                auSetSoundVolume(D_8034C8C8_825E58[0], 0x4400);
                D_802D2A90_7AC020 = 7;
            }
            break;
        case 7:
            if (((arg0 + arg1) > 5.28f) && ((arg0 + arg1) < 5.53f)) {
                auSetSoundVolume(D_8034C8C8_825E58[0], (((arg0 + arg1) - 5.28f) * 3072.0f * 4) + 17408.0f);
            } else if ((arg0 + arg1) >= 5.53f) {
                auSetSoundVolume(D_8034C8C8_825E58[0], 0x5000);
                D_802D2A90_7AC020 = 8;
            }
            break;
        case 8:
            if (((arg0 + arg1) > 5.95f) && ((arg0 + arg1) < 6.15f)) {
                auSetSoundVolume(D_8034C8C8_825E58[0], ((6.15f - (arg0 + arg1)) * 6144.0f * 5.0f) + 14336.0f);
            } else if ((arg0 + arg1) >= 6.15f) {
                auSetSoundVolume(D_8034C8C8_825E58[0], 0x3800);
                D_802D2A90_7AC020 = 9;
            }
            break;
        case 9:
        default:
            break;
    }

    switch (D_802D2A94_7AC024) {
        case 0:
            if ((arg0 + arg1) <= 0.0f) {
                D_8034C8C8_825E58[1] = auPlaySoundWithParams(0x21, 0x4000, 0x40, 1.0f, 0x3C);
                D_802D2A94_7AC024 = 1;
            }
            break;
        default:
            break;
        case 1:
            if (((arg0 + arg1) > 0.01f) && ((arg0 + arg1) < 0.26f)) {
                auSetSoundVolume(D_8034C8C8_825E58[1], (0.26f - (arg0 + arg1)) * 16384.0f * 4);
            } else if ((arg0 + arg1) >= 0.26f) {
                auStopSound(D_8034C8C8_825E58[1]);
                D_802D2A94_7AC024 = 3;
            }
            break;
        case 3:
            if ((arg0 + arg1) > 1.9f) {
                D_8034C8C8_825E58[1] = auPlaySoundWithParams(0x21, 1, 0x40, 0.8f, 0x3C);
                D_802D2A94_7AC024 = 4;
            }
            break;
        case 4:
            if ((arg0 + arg1) < 2.1f) {
                auSetSoundVolume(D_8034C8C8_825E58[1], ((arg0 + arg1) - 1.9f) * 18432.0f * 5.0f);
            } else {
                auSetSoundVolume(D_8034C8C8_825E58[1], 0x4800);
                D_802D2A94_7AC024 = 5;
            }
            break;
        case 5:
            if (((arg0 + arg1) > 2.75f) && ((arg0 + arg1) < 2.95f)) {
                auSetSoundVolume(D_8034C8C8_825E58[1], (2.95f - (arg0 + arg1)) * 18432.0f * 5.0f);
            } else if ((arg0 + arg1) >= 2.95f) {
                auStopSound(D_8034C8C8_825E58[1]);
                D_802D2A94_7AC024 = 6;
            }
            break;
        case 6:
            if ((arg0 + arg1) > 2.98f) {
                D_8034C8C8_825E58[1] = auPlaySoundWithParams(0x21, 1, 0x40, 1.0f, 0x3C);
                D_802D2A94_7AC024 = 7;
            }
            break;
        case 7:
            if ((arg0 + arg1) < 3.23f) {
                auSetSoundVolume(D_8034C8C8_825E58[1], ((arg0 + arg1) - 2.98f) * 21504.0f * 4);
            } else {
                auSetSoundVolume(D_8034C8C8_825E58[1], 0x5400);
                D_802D2A94_7AC024 = 8;
            }
            break;
        case 8:
            if (((arg0 + arg1) > 3.8f) && ((arg0 + arg1) < 4.05f)) {
                auSetSoundVolume(D_8034C8C8_825E58[1], (4.05f - (arg0 + arg1)) * 21504.0f * 4);
            } else if ((arg0 + arg1) >= 4.05f) {
                auStopSound(D_8034C8C8_825E58[1]);
                D_802D2A94_7AC024 = 10;
            }
            break;
        case 10:
            if ((arg0 + arg1) > 4.15f) {
                D_8034C8C8_825E58[1] = auPlaySoundWithParams(0x21, 1, 0x40, 0.8f, 0x3C);
                D_802D2A94_7AC024 = 11;
            }
            break;
        case 11:
            if ((arg0 + arg1) < 4.25f) {
                auSetSoundVolume(D_8034C8C8_825E58[1], ((arg0 + arg1) - 4.15f) * 18432.0f * 5.0f);
            } else {
                auSetSoundVolume(D_8034C8C8_825E58[1], 0x4800);
                D_802D2A94_7AC024 = 12;
            }
            break;
        case 12:
            if (((arg0 + arg1) > 4.57f) && ((arg0 + arg1) < 4.77f)) {
                auSetSoundVolume(D_8034C8C8_825E58[1], (4.77f - (arg0 + arg1)) * 18432.0f * 5.0f);
            } else if ((arg0 + arg1) >= 4.77f) {
                auStopSound(D_8034C8C8_825E58[1]);
                D_802D2A94_7AC024 = 13;
            }
            break;
        case 13:
            if ((arg0 + arg1) > 5.52f) {
                D_8034C8C8_825E58[1] = auPlaySoundWithParams(0x21, 1, 0x40, 0.8f, 0x3C);
                D_802D2A94_7AC024 = 14;
            }
            break;
        case 14:
            if ((arg0 + arg1) < 5.62f) {
                auSetSoundVolume(D_8034C8C8_825E58[1], ((arg0 + arg1) - 5.52f) * 18432.0f * 10.0f);
            } else if ((arg0 + arg1) >= 5.62f) {
                D_802D2A94_7AC024 = 15;
            }
            break;
        case 15:
            if (((arg0 + arg1) > 5.62f) && ((arg0 + arg1) < 5.82f)) {
                auSetSoundVolume(D_8034C8C8_825E58[1], (5.82f - (arg0 + arg1)) * 18432.0f * 5.0f);
            } else if ((arg0 + arg1) >= 5.82f) {
                auStopSound(D_8034C8C8_825E58[1]);
                D_802D2A94_7AC024 = 16;
            }
            break;
        case 16:
            if ((arg0 + arg1) > 5.85f) {
                D_8034C8C8_825E58[1] = auPlaySoundWithParams(0x20, 1, 0x40, 1.0f, 0x3C);
                D_802D2A94_7AC024 = 17;
            }
            break;
        case 17:
            if ((arg0 + arg1) < 6.05f) {
                auSetSoundVolume(D_8034C8C8_825E58[1], ((arg0 + arg1) - 5.85f) * 23552.0f * 5.0f);
            } else {
                auSetSoundVolume(D_8034C8C8_825E58[1], 0x5C00);
                D_802D2A94_7AC024 = 18;
            }
            break;
        case 18:
            if (((arg0 + arg1) > 6.05f) && ((arg0 + arg1) < 6.25f)) {
                auSetSoundVolume(D_8034C8C8_825E58[1], (6.25f - (arg0 + arg1)) * 23552.0f * 5.0f);
            } else if ((arg0 + arg1) >= 6.25f) {
                auStopSound(D_8034C8C8_825E58[1]);
                D_802D2A94_7AC024 = 19;
            }
            break;
        case 19:
            break;
    }
}
