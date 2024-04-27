#ifndef SYS_ANIM_H
#define SYS_ANIM_H
#include "sys/om.h"

union AnimCmd {
    u32 w;
    f32 f;
    void* ptr;
};

DObj* animModelTreeNextNode(DObj*);
void animSetModelTreeTextureAnimation(GObj* obj, union AnimCmd*** textureAnimLists, f32 skipFrames);
void animUpdateModelTreeAnimation(GObj* obj);
void animSetTextureAnimationSpeed(GObj* obj, f32 speed);

#endif /* SYS_ANIM_H */
