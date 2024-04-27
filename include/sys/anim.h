#ifndef SYS_ANIM_H
#define SYS_ANIM_H
#include "sys/om.h"

union AnimCmd {
    u32 w;
    f32 f;
    void* ptr;
};

struct UnkEC64Arg3 {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ void* unk04;
    /* 0x08 */ Vec3f position;
    /* 0x14 */ Vec3f rotation;
    /* 0x20 */ Vec3f scale;
}; // size == 0x2C

DObj* animModelTreeNextNode(DObj*);
void animSetModelTreeAnimation(GObj* obj, union AnimCmd** animLists, f32 skipFrames);
void animSetModelTreeTextureAnimation(GObj* obj, union AnimCmd*** textureAnimLists, f32 skipFrames);
void animUpdateModelTreeAnimation(GObj* obj);
void animSetTextureAnimationSpeed(GObj* obj, f32 speed);
void anim_func_80010230(GObj* arg0, struct UnkEC64Arg3* arg1, Texture*** arg2, DObj** arg3,u8 arg4, u8 arg5, u8 arg6);
void animSetModelAnimationSpeed(GObj* obj, f32 speed);
void anim_func_8000FBC4(GObj* obj, struct UnkEC64Arg3* arg1, DObj** arg2);

#endif /* SYS_ANIM_H */
