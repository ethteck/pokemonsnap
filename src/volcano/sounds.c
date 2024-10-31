#include "volcano/volcano.h"

__ALIGNER2

s32 volcano_SoundState1 = 0;
s32 volcano_SoundState2 = 0;
s32 volcano_SoundState3 = 0;

u8 volcano_SoundHandle1;
u8 volcano_SoundHandle2;
u8 volcano_SoundHandle3;
u8 volcano_SoundHandle4;

void volcano_UpdateSounds(s32 blockCount, f32 blockPart) {
    switch (volcano_SoundState1) {
        case 0:
            if (blockCount + blockPart <= 0.0f) {
                volcano_SoundHandle1 = auPlaySoundWithParams(SOUND_ID_56, 26624, 64, 1.0f, 10);
                volcano_SoundState1 = 1;
            }
            break;
        case 1:
            if (blockCount + blockPart > 0.0f) {
                setBackgroundMusic(SONG_VOLCANO);
                volcano_SoundState1 = 2;
            }
            break;
        case 2:
            if (blockCount + blockPart > 0.01f) {
                volcano_SoundHandle3 = auPlaySoundWithParams(SOUND_ID_54, 1, 64, 1.0f, 40);
                volcano_SoundState1 = 3;
            }
            break;
        case 3:
            if (blockCount + blockPart > 0.01f && blockCount + blockPart < 0.51f) {
                auSetSoundVolume(volcano_SoundHandle3, (blockCount + blockPart - 0.01f) * 20480.0f / (0.51f - 0.01f));
            } else if (blockCount + blockPart >= 0.51f) {
                auSetSoundVolume(volcano_SoundHandle3, 20480);
                volcano_SoundState1 = 4;
            }
            break;
        case 4:
            if (blockCount + blockPart > 1.46f && blockCount + blockPart < 1.86f) {
                auSetSoundVolume(volcano_SoundHandle3, (1.86f - (blockCount + blockPart)) * 20480.0f / (1.86f - 1.46f));
            } else if (blockCount + blockPart >= 1.86f) {
                auStopSound(volcano_SoundHandle3);
                volcano_SoundState1 = 5;
            }
            break;
        case 5:
            if (blockCount + blockPart > 3.0f) {
                volcano_SoundHandle3 = auPlaySoundWithParams(SOUND_ID_54, 1, 64, 1.0f, 40);
                volcano_SoundState1 = 6;
            }
            break;
        case 6:
            if (blockCount + blockPart > 3.0f && blockCount + blockPart < 3.1f) {
                auSetSoundVolume(volcano_SoundHandle3, (blockCount + blockPart - 3.0f) * 20480.0f / (3.1f - 3.0f));
            } else if (blockCount + blockPart >= 3.1f) {
                auSetSoundVolume(volcano_SoundHandle3, 20480);
                volcano_SoundState1 = 7;
            }
            break;
        case 7:
            if (blockCount + blockPart > 4.96f && blockCount + blockPart < 5.16f) {
                auSetSoundVolume(volcano_SoundHandle3, (5.16f - (blockCount + blockPart)) * 20480.0f / (5.16f - 4.96f));
            } else if (blockCount + blockPart >= 5.16f) {
                auStopSound(volcano_SoundHandle3);
                volcano_SoundState1 = 8;
            }
            break;
        case 8:
            break;
    }

    switch (volcano_SoundState2) {
        case 0:
            if (blockCount + blockPart > 5.16f) {
                volcano_SoundHandle2 = auPlaySoundWithParams(SOUND_ID_55, 1, 64, 1.0f, 50);
                volcano_SoundState2 = 1;
            }
            break;
        case 1:
            if (blockCount + blockPart < 5.23f) {
                auSetSoundVolume(volcano_SoundHandle2, (blockCount + blockPart - 5.16f) * 22528.0f / (5.23f - 5.16f));
            } else {
                auSetSoundVolume(volcano_SoundHandle2, 22528);
                volcano_SoundState2 = 2;
            }
            break;
        case 2:
            break;
        case 3:
            break;
    }

    switch (volcano_SoundState3) {
        case 0:
            if (blockCount + blockPart > 3.25f) {
                volcano_SoundHandle4 = auPlaySoundWithParams(SOUND_ID_57, 1, 64, 1.0f, 40);
                volcano_SoundState3 = 1;
            }
            break;
        case 1:
            if (blockCount + blockPart < 3.35f) {
                auSetSoundVolume(volcano_SoundHandle4, (blockCount + blockPart - 3.25f) * 20480.0f / (3.35f - 3.25f));
            } else {
                auSetSoundVolume(volcano_SoundHandle4, 20480);
                volcano_SoundState3 = 2;
            }
            break;
        case 2:
            if (blockCount + blockPart > 3.75f && blockCount + blockPart < 3.9f) {
                auSetSoundVolume(volcano_SoundHandle4, (3.9f - (blockCount + blockPart)) * 20480.0f / (3.9f - 3.75f));
            } else if (blockCount + blockPart > 3.9f) {
                auStopSound(volcano_SoundHandle4);
                volcano_SoundState3 = 3;
            }
            break;
        case 3:
            break;
    }
}
