#ifndef SYS_AUDIO_H
#define SYS_AUDIO_H

void auThreadMain(void* arg);
void auSetSoundQuality(s32 quality);
void auSetReverbType(s32 fxType);
void auStopBGM(void);
u32 auPlaySong(s32 playerID, u32 songID);
void auStopSong(s32 playerID);
void auSetBGMVolume(s32 playerID, u32 vol);
void auSetBGMVolumeSmooth(s32 playerID, u32 vol, u32 time);
s32 auIsBGMPlaying(s32 playerID);
void auSetBGMExtraReverb(s32 playerID, s8 reverbAmt);
void auSetBGMChannelVolume(s32 playerID, u8 chan, s8 vol);
void auSetBGMTempo(s32 playerID, s32 tempo);
s32 auPlaySound(u32 soundID);
s32 auPlaySoundWithParams(u32 soundID, s32 volume, s32 pan, f32 pitch, s32 reverbAmt);
void auStopAllSounds(void);
void auSetSoundVolume(s32 handle, u32 vol);
void auSetSoundPan(s32 handle, u32 arg1);
void auStopSound(s32 handle);
s32 auPlaySoundWithVolume(u32 soundID, u32 vol);
void auSetSoundGlobalVolume(u8 vol);
void auSetCurrentSoundsGlobalVolume(u8 vol);
void auSetSoundGlobalReverb(u8 reverbAmt);

#endif /* SYS_AUDIO_H */
