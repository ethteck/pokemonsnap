#include "tunnel.h"

u32 D_802EE1E0_5EB2B0 = 0;
u32 D_802EE1E4_5EB2B4 = 0;
u32 D_802EE1E8_5EB2B8 = 0;
u8 D_802EE1EC_5EB2BC = 0;
u8 D_802EE1F0_5EB2C0 = 0;

extern s32 D_803430F8_6401C8;
extern u8 D_803430FC_6401CC;
extern u8 D_803430FD_6401CD;

void func_802E2C70_5DFD40(s32 blockCount, f32 blockPart) {
    switch (D_802EE1E0_5EB2B0) {
        case 0:
            if (blockCount + blockPart >= 0.0f) {
                auPlaySong(BGM_PLAYER_AUX, SONG_ID_21);
                auSetBGMChannelVolume(BGM_PLAYER_MAIN, 6, D_802EE1EC_5EB2BC);
                auSetBGMChannelVolume(BGM_PLAYER_MAIN, 7, D_802EE1EC_5EB2BC);
                auSetBGMChannelVolume(BGM_PLAYER_MAIN, 8, D_802EE1EC_5EB2BC);
                auSetBGMChannelVolume(BGM_PLAYER_MAIN, 9, D_802EE1EC_5EB2BC);
                auSetBGMChannelVolume(BGM_PLAYER_MAIN, 10, D_802EE1EC_5EB2BC);
                auSetBGMChannelVolume(BGM_PLAYER_MAIN, 11, D_802EE1EC_5EB2BC);
                auSetBGMChannelVolume(BGM_PLAYER_MAIN, 12, D_802EE1EC_5EB2BC);
                D_802EE1E0_5EB2B0 = 1;
            }
            break;
        case 1:
            if (blockCount + blockPart > 0.0f) {
                setBackgroundMusic(SONG_ID_4);
                D_802EE1E0_5EB2B0 = 2;
            }
            break;
        case 2:
            if (blockCount + blockPart > 0.9f) {
                auSetBGMVolumeSmooth(BGM_PLAYER_AUX, 0, 60);
                D_802EE1E0_5EB2B0 = 3;
            }
            break;
        case 3:
            if (blockCount + blockPart >= 0.93f) {
                auStopSong(BGM_PLAYER_AUX);
                D_802EE1E0_5EB2B0 = 4;
            }
            break;
        case 4:
            if (blockCount + blockPart > 0.93f && blockCount + blockPart < 1.13f) {
                D_802EE1EC_5EB2BC = (u32)((blockCount + blockPart - 0.93f) * 127 / (1.13f - 0.93f));
                auSetBGMChannelVolume(BGM_PLAYER_MAIN, 6, D_802EE1EC_5EB2BC);
            } else if (blockCount + blockPart > 1.13f) {
                auSetBGMChannelVolume(BGM_PLAYER_MAIN, 6, 127);
                D_802EE1E0_5EB2B0 = 5;
            }
            break;
        case 5:
            if (blockCount + blockPart > 2.0f && blockCount + blockPart < 2.1f) {
                D_802EE1EC_5EB2BC = (u32)((blockCount + blockPart - 2.0f) * 127 / (2.1f - 2.0f));
                auSetBGMChannelVolume(BGM_PLAYER_MAIN, 7, D_802EE1EC_5EB2BC);
                auSetBGMChannelVolume(BGM_PLAYER_MAIN, 12, D_802EE1EC_5EB2BC);
            } else if (blockCount + blockPart > 2.1f) {
                auSetBGMChannelVolume(BGM_PLAYER_MAIN, 7, 127);
                auSetBGMChannelVolume(BGM_PLAYER_MAIN, 12, 127);
                D_802EE1E0_5EB2B0 = 6;
            }
            break;
        case 6:
            if (blockCount + blockPart > 2.9f && blockCount + blockPart < 4.3f) {
                if (D_803430F8_6401C8) {
                    D_803430FD_6401CD = auPlaySoundWithParams(SOUND_ID_47, 0x7000, 64, 1.0f, 0);
                    D_802EE1E0_5EB2B0 = 7;
                }
            } else if (blockCount + blockPart > 4.3f) {
                if (!D_803430F8_6401C8) {
                    D_802EE1E0_5EB2B0 = 8;
                }
            }
            break;
        case 7:
            if (blockCount + blockPart > 2.9f && blockCount + blockPart < 4.3f) {
                if (D_803430F8_6401C8) {
                    if (D_802EE1F0_5EB2C0 < 127) {
                        D_802EE1F0_5EB2C0++;
                    } else {
                        D_802EE1F0_5EB2C0 = 127;
                        D_802EE1E0_5EB2B0 = 8;
                    }
                    auSetBGMChannelVolume(BGM_PLAYER_MAIN, 8, D_802EE1F0_5EB2C0);
                    auSetBGMChannelVolume(BGM_PLAYER_MAIN, 9, D_802EE1F0_5EB2C0);
                    auSetBGMChannelVolume(BGM_PLAYER_MAIN, 10, D_802EE1F0_5EB2C0);
                    auSetBGMChannelVolume(BGM_PLAYER_MAIN, 11, D_802EE1F0_5EB2C0);
                }
            } else if (blockCount + blockPart > 4.3f) {
                if (D_803430F8_6401C8) {
                    if (D_802EE1F0_5EB2C0 < 127) {
                        D_802EE1F0_5EB2C0 = 127;
                        auSetBGMChannelVolume(BGM_PLAYER_MAIN, 8, D_802EE1F0_5EB2C0);
                        auSetBGMChannelVolume(BGM_PLAYER_MAIN, 9, D_802EE1F0_5EB2C0);
                        auSetBGMChannelVolume(BGM_PLAYER_MAIN, 10, D_802EE1F0_5EB2C0);
                        auSetBGMChannelVolume(BGM_PLAYER_MAIN, 11, D_802EE1F0_5EB2C0);
                    }
                }
                D_802EE1E0_5EB2B0 = 8;
            }
            break;
        case 8:
            if (blockCount + blockPart > 5.0f && blockCount + blockPart < 5.3f) {
                D_802EE1EC_5EB2BC = (u32)((5.3f - (blockCount + blockPart)) * 127 / (5.3f - 5.0f));
                auSetBGMChannelVolume(BGM_PLAYER_MAIN, 7, D_802EE1EC_5EB2BC);
                auSetBGMChannelVolume(BGM_PLAYER_MAIN, 12, D_802EE1EC_5EB2BC);
                if (D_803430F8_6401C8) {
                    auSetBGMChannelVolume(BGM_PLAYER_MAIN, 8, D_802EE1EC_5EB2BC);
                    auSetBGMChannelVolume(BGM_PLAYER_MAIN, 9, D_802EE1EC_5EB2BC);
                    auSetBGMChannelVolume(BGM_PLAYER_MAIN, 10, D_802EE1EC_5EB2BC);
                    auSetBGMChannelVolume(BGM_PLAYER_MAIN, 11, D_802EE1EC_5EB2BC);
                    auSetSoundVolume(D_803430FD_6401CD, D_802EE1EC_5EB2BC * 0x7000 >> 7);
                }
            } else if (blockCount + blockPart > 5.3f) {
                auSetBGMChannelVolume(BGM_PLAYER_MAIN, 7, 0);
                auSetBGMChannelVolume(BGM_PLAYER_MAIN, 12, 0);
                if (D_803430F8_6401C8) {
                    auSetBGMChannelVolume(BGM_PLAYER_MAIN, 8, 0);
                    auSetBGMChannelVolume(BGM_PLAYER_MAIN, 9, 0);
                    auSetBGMChannelVolume(BGM_PLAYER_MAIN, 10, 0);
                    auSetBGMChannelVolume(BGM_PLAYER_MAIN, 11, 0);
                    if (auPlayingSound[D_803430FD_6401CD] == SOUND_ID_47) {
                        auStopSound(D_803430FD_6401CD);
                    }
                }
                D_802EE1E0_5EB2B0 = 9;
            }
            break;
        case 9:
            break;
    }

    switch (D_802EE1E4_5EB2B4) {
        case 0:
            if (blockCount + blockPart > 0.925f) {
                auSetBGMExtraReverb(BGM_PLAYER_MAIN, 20);
                auSetSoundGlobalReverb(50);
                auPlaySoundWithParams(SOUND_ID_52, 0x6800, 0, 0.7f, 0);
                D_802EE1E4_5EB2B4 = 1;
            }
            break;
        case 1:
            if (blockCount + blockPart > 0.93f) {
                auPlaySoundWithParams(SOUND_ID_52, 0x6800, 127, 0.8f, 0);
                D_802EE1E4_5EB2B4 = 2;
            }
            break;
        case 2:
            if (blockCount + blockPart > 5.365f) {
                auSetSoundGlobalReverb(0);
                auSetBGMExtraReverb(BGM_PLAYER_MAIN, 0);                
                auPlaySoundWithParams(SOUND_ID_52, 0x6800, 0, 0.7f, 20);
                D_802EE1E4_5EB2B4 = 3;
            }
            break;
        case 3:
            if (blockCount + blockPart > 5.37f) {
                auPlaySoundWithParams(SOUND_ID_52, 0x6800, 127, 0.8f, 20);
                D_802EE1E4_5EB2B4 = 4;
            }
            break;
        case 4:
            break;
    }

    switch (D_802EE1E8_5EB2B8) {
        case 0:
            if (blockCount + blockPart > 1.9f && blockCount + blockPart < 3.05f) {
                if (D_803430F8_6401C8) {
                    D_803430FC_6401CC = auPlaySoundWithParams(SOUND_ID_48, 0x7800, 64, 0.7f, 0);
                    D_802EE1E8_5EB2B8 = 1;
                }
            } else if (blockCount + blockPart > 2.97f) {
                D_802EE1E8_5EB2B8 = 2;
            }
            break;
        case 1:
            if (blockCount + blockPart > 3.05f && blockCount + blockPart < 3.105f) {
                if (D_803430F8_6401C8) {
                    auSetSoundVolume(D_803430FC_6401CC, (3.105f - (blockCount + blockPart)) * 0x7800 / (3.105f - 3.05f));
                }
            } else if (blockCount + blockPart > 3.105f) {
                if (D_803430F8_6401C8) {
                    if (auPlayingSound[D_803430FC_6401CC] == SOUND_ID_48) {
                        auStopSound(D_803430FC_6401CC);
                    }
                    D_802EE1E8_5EB2B8 = 2;
                }
            }
            break;
        case 2:
            break;
    }
}
