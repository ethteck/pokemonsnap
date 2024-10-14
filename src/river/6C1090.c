#include "common.h"
#include "river.h"

extern u32 D_802E29D0_6CA7B0;

void func_802D92B0_6C1090(s32 arg0, f32 arg1) {
    f32 temp_f0;

    switch (D_802E29D0_6CA7B0) {
        case 0:
            if (arg0 + arg1 <= 0.0f) {
                auPlaySoundWithParams(0x2C, 0x5400, 0x40, 0.6f, 30);
                auPlaySong(1, 0x15);
                D_802E29D0_6CA7B0 = 1;
            }
            break;
        case 1:
            if (arg0 + arg1 > 0.0f) {
                setBackgroundMusic(5);
                D_802E29D0_6CA7B0 = 2;
            }
            break;
        case 2:
            if (arg0 + arg1 > 2.25f) {
                auStopSong(1);
                D_802E29D0_6CA7B0 = 3;
            }
            break;
        case 3:
            if (arg0 + arg1 > 2.9f) {
                auPlaySong(1, 0x14);
                D_802E29D0_6CA7B0 = 4;
            }
            break;
        case 4:
            temp_f0 = arg0 + arg1;
            if (temp_f0 > 4.05f && temp_f0 < 4.3f) {
                auSetBGMVolume(1, ((4.3f - temp_f0) * 32512.0f) / 0.25f);
                return;
            }
            if (temp_f0 > 4.3f) {
                auStopSong(1);
                D_802E29D0_6CA7B0 = 5;
            }
            break;
        case 5:
            break;
    }
}
