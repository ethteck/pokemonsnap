#include "volcano/volcano.h"

s32 D_802E37F0_7349F0 = 0;
s32 D_802E37F4_7349F4 = 0;
s32 D_802E37F8_7349F8 = 0;

extern u8 D_8034E0F8_79F2F8;
extern u8 D_8034E0F9_79F2F9;
extern u8 D_8034E0FA_79F2FA;
extern u8 D_8034E0FB_79F2FB;

void volcano_UpdateSounds(s32 blockCount, f32 blockPart) {
    switch (D_802E37F0_7349F0) {
        case 0:
            if (blockCount + blockPart <= 0.0f) {
                D_8034E0F8_79F2F8 = auPlaySoundWithParams(SOUND_ID_56, 26624, 64, 1.0f, 10);
                D_802E37F0_7349F0 = 1;
            }
            break;
        case 1:
            if (blockCount + blockPart > 0.0f) {
                setBackgroundMusic(SONG_VOLCANO);
                D_802E37F0_7349F0 = 2;
            }
            break;
        case 2:
            if (blockCount + blockPart > 0.01f) {
                D_8034E0FA_79F2FA = auPlaySoundWithParams(SOUND_ID_54, 1, 64, 1.0f, 40);
                D_802E37F0_7349F0 = 3;
            }
            break;
        case 3:
            if (blockCount + blockPart > 0.01f && blockCount + blockPart < 0.51f) {
                auSetSoundVolume(D_8034E0FA_79F2FA, (blockCount + blockPart - 0.01f) * 20480.0f / (0.51f - 0.01f));
            } else if (blockCount + blockPart >= 0.51f) {
                auSetSoundVolume(D_8034E0FA_79F2FA, 20480);
                D_802E37F0_7349F0 = 4;
            }
            break;
        case 4:
            if (blockCount + blockPart > 1.46f && blockCount + blockPart < 1.86f) {
                auSetSoundVolume(D_8034E0FA_79F2FA, (1.86f - (blockCount + blockPart)) * 20480.0f / (1.86f - 1.46f));
            } else if (blockCount + blockPart >= 1.86f) {
                auStopSound(D_8034E0FA_79F2FA);
                D_802E37F0_7349F0 = 5;
            }
            break;
        case 5:
            if (blockCount + blockPart > 3.0f) {
                D_8034E0FA_79F2FA = auPlaySoundWithParams(SOUND_ID_54, 1, 64, 1.0f, 40);
                D_802E37F0_7349F0 = 6;
            }
            break;
        case 6:
            if (blockCount + blockPart > 3.0f && blockCount + blockPart < 3.1f) {
                auSetSoundVolume(D_8034E0FA_79F2FA, (blockCount + blockPart - 3.0f) * 20480.0f / (3.1f - 3.0f));
            } else if (blockCount + blockPart >= 3.1f) {
                auSetSoundVolume(D_8034E0FA_79F2FA, 20480);
                D_802E37F0_7349F0 = 7;
            }
            break;
        case 7:
            if (blockCount + blockPart > 4.96f && blockCount + blockPart < 5.16f) {
                auSetSoundVolume(D_8034E0FA_79F2FA, (5.16f - (blockCount + blockPart)) * 20480.0f / (5.16f - 4.96f));
            } else if (blockCount + blockPart >= 5.16f) {
                auStopSound(D_8034E0FA_79F2FA);
                D_802E37F0_7349F0 = 8;
            }
            break;
        case 8:
            break;
    }

    switch (D_802E37F4_7349F4) {
        case 0:
            if (blockCount + blockPart > 5.16f) {
                D_8034E0F9_79F2F9 = auPlaySoundWithParams(SOUND_ID_55, 1, 64, 1.0f, 50);
                D_802E37F4_7349F4 = 1;
            }
            break;
        case 1:
            if (blockCount + blockPart < 5.23f) {
                auSetSoundVolume(D_8034E0F9_79F2F9, (blockCount + blockPart - 5.16f) * 22528.0f / (5.23f - 5.16f));
            } else {
                auSetSoundVolume(D_8034E0F9_79F2F9, 22528);
                D_802E37F4_7349F4 = 2;
            }
            break;
        case 2:
            break;
        case 3:
            break;
    }

    switch (D_802E37F8_7349F8) {
        case 0:
            if (blockCount + blockPart > 3.25f) {
                D_8034E0FB_79F2FB = auPlaySoundWithParams(SOUND_ID_57, 1, 64, 1.0f, 40);
                D_802E37F8_7349F8 = 1;
            }
            break;
        case 1:
            if (blockCount + blockPart < 3.35f) {
                auSetSoundVolume(D_8034E0FB_79F2FB, (blockCount + blockPart - 3.25f) * 20480.0f / (3.35f - 3.25f));
            } else {
                auSetSoundVolume(D_8034E0FB_79F2FB, 20480);
                D_802E37F8_7349F8 = 2;
            }
            break;
        case 2:
            if (blockCount + blockPart > 3.75f && blockCount + blockPart < 3.9f) {
                auSetSoundVolume(D_8034E0FB_79F2FB, (3.9f - (blockCount + blockPart)) * 20480.0f / (3.9f - 3.75f));
            } else if (blockCount + blockPart > 3.9f) {
                auStopSound(D_8034E0FB_79F2FB);
                D_802E37F8_7349F8 = 3;
            }
            break;
        case 3:
            break;
    }
}
