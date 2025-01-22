#ifndef _EFFECT_H_
#define _EFFECT_H_

#include "types.h"
#include "common_structs.h"

#define PARTICLE_BANKS_MAX 8

enum ParticleFlags {
    PARTICLE_FLAG_PAUSE = 0x800
};

typedef struct EffectScript {
    /* 0x00 */ u16 kind; // Effect kind
    /* 0x02 */ u16 textureID;
    /* 0x04 */ u16 effectLifetime;
    /* 0x06 */ u16 particleLifetime;
    /* 0x08 */ u32 flags;
    /* 0x0C */ f32 gravity;
    /* 0x10 */ f32 friction;
    /* 0x14 */ Vec3f vel;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 size;
    /* 0x30 */ u8 bytecode[1]; // variable length
} EffectScript;                // size > 0x30

typedef struct ParticleScriptDesc {
    /* 0x00 */ s32 count;
    /* 0x04 */ EffectScript* scripts[1]; // variable length
} ParticleScriptDesc;                    // size > 0x4

typedef struct EffectSprites {
    /* 0x00 */ u32 numFrames;
    /* 0x04 */ s32 fmt;
    /* 0x08 */ s32 siz;
    /* 0x0C */ s32 width;
    /* 0x10 */ s32 height;
    /* 0x14 */ s32 flags;
    /* 0x18 */ u8* data[1]; // variable length
} EffectSprites;

typedef struct ParticleSpritesDesc {
    /* 0x00 */ s32 count;
    /* 0x04 */ EffectSprites* sprites[1]; // variable length
} ParticleSpritesDesc;                    // size > 0x4

typedef struct Particle {
    /* 0x00 */ struct Particle* next;
    /* 0x04 */ u16 effectID;
    /* 0x06 */ u16 flags;
    /* 0x08 */ u8 bankID;
    /* 0x09 */ u8 loopCount;
    /* 0x0A */ u8 textureID;
    /* 0x0B */ u8 dataID;
    /* 0x0C */ u16 bytecodeTimer;
    /* 0x0E */ u16 sizeTargetLength;
    /* 0x10 */ u16 targetPrimColorLength;
    /* 0x12 */ u16 targetEnvColorLength;
    /* 0x14 */ u8* bytecode;
    /* 0x18 */ u16 bytecodePos;
    /* 0x1A */ u16 returnPtr;
    /* 0x1C */ u16 loopPtr;
    /* 0x1E */ u16 lifetime;
    /* 0x20 */ Vec3f pos;
    /* 0x2C */ Vec3f vel;
    /* 0x38 */ f32 gravity;
    /* 0x3C */ f32 friction;
    /* 0x40 */ f32 size;
    /* 0x44 */ f32 sizeTarget;
    /* 0x48 */ ucolor primColor;
    /* 0x4C */ ucolor targetPrimColor;
    /* 0x50 */ ucolor envColor;
    /* 0x54 */ ucolor targetEnvColor;
    /* 0x58 */ Effect* fx;
} Particle; // size = 0x5C

extern Particle* D_800BE1A8[16];
extern s32 fx_ScriptBanksNum[PARTICLE_BANKS_MAX];
extern s32 fx_SpriteBanksNum[PARTICLE_BANKS_MAX];
extern EffectSprites** fx_SpriteBanks[PARTICLE_BANKS_MAX];

void fx_setupBankID(s32 bankID, UNK_PTR scriptDesc, UNK_PTR spritesDesc);
void fx_setDitherModes(s32 color, s32 alpha);
GObj* fx_allocEffects(s32 num);
void fx_getPosVelDObj(Vec3f* pos, Vec3f* vel, DObj* dobj);
Effect* fx_createEffect(s32 bankID, s32 scriptID);
void fx_ejectEffectDObj(GObj* obj);
void fx_translatePosAll(f32, f32, f32);

#endif
