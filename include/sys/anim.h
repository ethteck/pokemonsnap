#ifndef SYS_ANIM_H
#define SYS_ANIM_H
#include "sys/om.h"

#define ANIMATION_DISABLED (FLOAT_NEG_MAX)
#define ANIMATION_CHANGED (FLOAT_NEG_MAX / 2)
#define ANIMATION_FINISHED (FLOAT_NEG_MAX / 3)

typedef union AnimCmd {
    u32 w;
    f32 f;
    void* ptr;
} AnimCmd;

typedef struct {
    /* 0x00 */ f32 speed;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ AnimCmd** modelAnims;
    /* 0x0C */ AnimCmd*** matAnims;
    /* 0x10 */ s32* ids;
} AnimationHeader;

typedef struct UnkEC64Arg3 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ void* unk04;
    /* 0x08 */ Vec3f position;
    /* 0x14 */ Vec3f rotation;
    /* 0x20 */ Vec3f scale;
} UnkEC64Arg3; // size == 0x2C

DObj* animModelTreeNextNode(DObj*);
void anim_func_8000FBC4(GObj* obj, struct UnkEC64Arg3* arg1, DObj** arg2);
void animSetModelAnimationSpeed(GObj* obj, f32 speed);
void animSetTextureAnimationSpeed(GObj* obj, f32 speed);
void animSetModelTreeAnimation(GObj* obj, AnimCmd** animLists, f32 skipFrames);
void animSetModelTreeTextureAnimation(GObj* obj, AnimCmd*** textureAnimLists, f32 skipFrames);
void animUpdateModelTreeAnimation(GObj* obj);
void anim_func_80010230(GObj* arg0, UnkEC64Arg3* arg1, Texture*** arg2, DObj** arg3,
                        u8 arg4, u8 arg5, u8 arg6);
void animSetCameraAnimation(OMCamera* cam, AnimCmd* animList, f32 skipFrames);
void animUpdateCameraAnimation(GObj* obj);
void anim_func_8000FDA0(DObj* dobj, u8 arg1, u8 arg2, u8 arg3);
void anim_func_8000F8E4(GObj* arg0, AnimCmd** arg1, f32 arg2, UnkEC64Arg3* arg3);
void animSetModelAndTextureAnimationSpeed(GObj* obj, f32 speed);

#endif /* SYS_ANIM_H */
