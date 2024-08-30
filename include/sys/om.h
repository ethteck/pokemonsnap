#ifndef SYS_OM_H
#define SYS_OM_H

#include "PR/os.h"
#include "PR/mbi.h"
#include "PR/sp.h"
#include "types.h"

#include "sys/cmd.h"
#include "sys/interpolation.h"

// Object Manager (OM) Objects

enum MatrixType {
    MTX_TYPE_1 = 1,
    MTX_TYPE_2 = 2,
    MTX_TYPE_PERSP_FAST = 3,
    MTX_TYPE_PERSP = 4,
    MTX_TYPE_ORTHO = 5,
    MTX_TYPE_LOOKAT = 6,
    MTX_TYPE_LOOKAT_MVIEW = 7,
    MTX_TYPE_LOOKAT_ROLL = 8,
    MTX_TYPE_LOOKAT_ROLL_MVIEW = 9,
    MTX_TYPE_LOOKAT_ROLL_Z = 10,
    MTX_TYPE_LOOKAT_ROLL_Z_MVIEW = 11,
    MTX_TYPE_LOOKAT_REFLECT = 12,
    MTX_TYPE_LOOKAT_REFLECT_MVIEW = 13,
    MTX_TYPE_LOOKAT_REFLECT_ROLL = 14,
    MTX_TYPE_LOOKAT_REFLECT_ROLL_MVIEW = 15,
    MTX_TYPE_LOOKAT_REFLECT_ROLL_Z = 16,
    MTX_TYPE_LOOKAT_REFLECT_ROLL_Z_MVIEW = 17,
    MTX_TYPE_TRANSLATE = 18,
    MTX_TYPE_ROTATE_DEG = 19,
    MTX_TYPE_ROTATE_DEG_TRANSLATE = 20,
    MTX_TYPE_ROTATE_RPY_DEG = 21,
    MTX_TYPE_ROTATE_RPY_TRANSLATE_DEG = 22,
    MTX_TYPE_ROTATE = 23,
    MTX_TYPE_ROTATE_TRANSLATE = 24,
    MTX_TYPE_ROTATE_TRANSLATE_SCALE = 25,
    MTX_TYPE_ROTATE_RPY = 26,
    MTX_TYPE_ROTATE_RPY_TRANSLATE = 27,
    MTX_TYPE_ROTATE_RPY_TRANSLATE_SCALE = 28,
    MTX_TYPE_ROTATE_PYR = 29,
    MTX_TYPE_ROTATE_PYR_TRANSLATE = 30,
    MTX_TYPE_ROTATE_PYR_TRANSLATE_SCALE = 31,
    MTX_TYPE_SCALE = 32,
    MTX_TYPE_33 = 33,
    MTX_TYPE_34 = 34,
    MTX_TYPE_35 = 35,
    MTX_TYPE_36 = 36,
    MTX_TYPE_37 = 37,
    MTX_TYPE_38 = 38,
    MTX_TYPE_39 = 39,
    MTX_TYPE_40 = 40,
    MTX_TYPE_41 = 41,
    MTX_TYPE_42 = 42,
    MTX_TYPE_43 = 43,
    MTX_TYPE_44 = 44,
    MTX_TYPE_45 = 45,
    MTX_TYPE_46 = 46,
    MTX_TYPE_47 = 47,
    MTX_TYPE_48 = 48,
    MTX_TYPE_49 = 49,
    MTX_TYPE_50 = 50,
    MTX_TYPE_51 = 51,
    MTX_TYPE_52 = 52,
    MTX_TYPE_53 = 53,
    MTX_TYPE_54 = 54,
    MTX_TYPE_55 = 55,
    MTX_TYPE_56 = 56,
    MTX_TYPE_57 = 57,
    MTX_TYPE_58 = 58,
    MTX_TYPE_59 = 59,
    MTX_TYPE_60 = 60,
    MTX_TYPE_61 = 61,
    MTX_TYPE_62 = 62,
    MTX_TYPE_63 = 63,
    MTX_TYPE_64 = 64,
    MTX_TYPE_65 = 65,
    MTX_TYPE_66 = 66
};

enum AnimType {
    ANIM_TYPE_NONE = 0,
    ANIM_TYPE_STEP = 1,
    ANIM_TYPE_LINEAR = 2,
    ANIM_TYPE_CUBIC = 3
};

enum AnimCommand {
    ANIM_CMD_END = 0,
    ANIM_CMD_JUMP = 1,
    ANIM_CMD_WAIT = 2,
    ANIM_CMD_SET_VALUE_LAST = 3,
    ANIM_CMD_SET_VALUE = 4,
    ANIM_CMD_SET_VALUE_WITH_RATE_LAST = 5,
    ANIM_CMD_SET_VALUE_WITH_RATE = 6,
    ANIM_CMD_SET_TARGET_RATE = 7,
    ANIM_CMD_SET_VALUE_ZERO_RATE_LAST = 8,
    ANIM_CMD_SET_VALUE_ZERO_RATE = 9,
    ANIM_CMD_SET_VALUE_AFTER_LAST = 10,
    ANIM_CMD_SET_VALUE_AFTER = 11,
    ANIM_CMD_12 = 12,
    ANIM_CMD_13 = 13,
    ANIM_CMD_SET_ANIMATION = 14,
    ANIM_CMD_SET_FLAGS = 15,
    ANIM_CMD_16 = 16,
    ANIM_CMD_17 = 17,
    ANIM_CMD_SET_EXTRA_VALUE_AFTER_LAST = 18,
    ANIM_CMD_SET_EXTRA_VALUE_AFTER = 19,
    ANIM_CMD_SET_EXTRA_VALUE_LAST = 20,
    ANIM_CMD_SET_EXTRA_VALUE = 21,
    ANIM_CMD_22 = 22,
    ANIM_CMD_23 = 23
};

enum AnimParam {
    // model
    ANIM_PARAM_MODEL_MIN = 1,
    ANIM_PARAM_ROTATION_X = 1,
    ANIM_PARAM_ROTATION_Y = 2,
    ANIM_PARAM_ROTATION_Z = 3,
    ANIM_PARAM_4 = 4,
    ANIM_PARAM_POSITION_X = 5,
    ANIM_PARAM_POSITION_Y = 6,
    ANIM_PARAM_POSITION_Z = 7,
    ANIM_PARAM_SCALE_X = 8,
    ANIM_PARAM_SCALE_Y = 9,
    ANIM_PARAM_SCALE_Z = 10,
    ANIM_PARAM_MODEL_MAX = 10,
    // texture
    ANIM_PARAM_TEXTURE_MIN = 13,
    ANIM_PARAM_TEXTURE_13 = 13,
    ANIM_PARAM_TEXTURE_14 = 14,
    ANIM_PARAM_TEXTURE_15 = 15,
    ANIM_PARAM_TEXTURE_16 = 16,
    ANIM_PARAM_TEXTURE_17 = 17,
    ANIM_PARAM_TEXTURE_18 = 18,
    ANIM_PARAM_TEXTURE_19 = 19,
    ANIM_PARAM_TEXTURE_20 = 20,
    ANIM_PARAM_TEXTURE_21 = 21,
    ANIM_PARAM_TEXTURE_22 = 22,
    ANIM_PARAM_TEXTURE_MAX = 22,
    // camera
    ANIM_PARAM_CAMERA_MIN = 25,
    ANIM_PARAM_CAMERA_XEYE = 25,
    ANIM_PARAM_CAMERA_YEYE = 26,
    ANIM_PARAM_CAMERA_ZEYE = 27,
    ANIM_PARAM_CAMERA_28 = 28,
    ANIM_PARAM_CAMERA_XAT = 29,
    ANIM_PARAM_CAMERA_YAT = 30,
    ANIM_PARAM_CAMERA_ZAT = 31,
    ANIM_PARAM_CAMERA_32 = 32,
    ANIM_PARAM_CAMERA_ROLL = 33,
    ANIM_PARAM_CAMERA_FOVY = 34,
    ANIM_PARAM_CAMERA_MAX = 34,
    // texture extra
    ANIM_PARAM_TEXTURE_EXTRA_MIN = 37,
    ANIM_PARAM_TEXTURE_EXTRA_37 = 37,
    ANIM_PARAM_TEXTURE_EXTRA_38 = 38,
    ANIM_PARAM_TEXTURE_EXTRA_39 = 39,
    ANIM_PARAM_TEXTURE_EXTRA_40 = 40,
    ANIM_PARAM_TEXTURE_EXTRA_41 = 41,
    ANIM_PARAM_TEXTURE_EXTRA_MAX = 41
};

enum GObjFlag {
    GOBJ_FLAG_HIDDEN = 0x01,
    GOBJ_FLAG_2 = 0x02,
    GOBJ_FLAG_40 = 0x40
};

enum CameraFlags {
    CAMERA_FLAG_1 = 0x01,
    CAMERA_FLAG_2 = 0x02,
    CAMERA_FLAG_4 = 0x04,
    CAMERA_FLAG_8 = 0x08,
    CAMERA_FLAG_10 = 0x10,
    CAMERA_FLAG_20 = 0x20,
    CAMERA_FLAG_40 = 0x40,
    CAMERA_FLAG_80 = 0x80
};

struct Unk80046A88 {
    /* 0x00 */ u8 unk00;
    /* 0x04 */ Gfx* unk04[4];
}; // sizeof == 0x14

typedef struct GObjThread {
    /* 0x000 */ struct GObjThread* next;
    /* 0x008 */ OSThread osThread;
    /* 0x1B8 */ u64* osStack;
    /* 0x1BC */ u32 stackSize;
} GObjThread; // size == 0x1C0

/// This is the node for the allocated stack for a `struct GObjThread`
typedef struct ThreadStackNode {
    /* 0x00 */ struct ThreadStackNode* next;
    /* 0x04 */ u32 stackSize;
    /* 0x08 */ u64 stack[1];
} ThreadStackNode; // size == 0x08 + VLA

typedef void (*GObjFunc)(struct GObj*);

typedef struct GObjProcess {
    /* 0x00 */ struct GObjProcess* next; // Points to next process in free or object process list
    /* 0x04 */ struct GObjProcess* prev; // Points to previous process in object process list
    /* 0x08 */ struct GObjProcess* nextInPriorityList;
    /* 0x0C */ struct GObjProcess* prevInPriorityList;
    /* 0x10 */ s32 priority;
    /* 0x14 */ u8 kind;
    /* 0x15 */ u8 paused;
    /* 0x18 */ struct GObj* object;
    // following two fields are typed via kind
    /* 0x1C */ union {
        struct GObjThread* thread;
        GObjFunc cb;
    } unk_1C;
    /* 0x20 */ GObjFunc function;
} GObjProcess; // size == 0x24

struct DObj;
struct GObj;

typedef struct GObj {
    /* 0x00 */ u32 id;
    /* 0x04 */ struct GObj* next;
    /* 0x08 */ struct GObj* prev;
    /* 0x0C */ u8 link;
    /* 0x0D */ u8 dlLink;
    /* 0x0E */ u8 lastDrawFrame;
    // 0 : NULL
    // 1 : DObj
    // 2 : SObj
    // 3 : OMCamera
    /* 0x0F */ u8 type;
    /* 0x10 */ u32 priority;
    /* 0x14 */ GObjFunc fnUpdate;
    /* 0x18 */ struct GObjProcess* processListHead;
    /* 0x1C */ struct GObjProcess* processListTail;
    /* 0x20 */ struct GObj* nextDl;
    /* 0x24 */ struct GObj* prevDl;
    /* 0x28 */ u32 dlPriority;
    /* 0x2C */ GObjFunc fnRender;
    /* 0x30 */ s32 dlLinkBitMask;
    /* 0x34 */ s32 cameraTag;
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ GObjCmdList cmdList;
    /* 0x48 */ union {
        struct OMCamera* cam;
        struct SObj* sobj;
        struct DObj* dobj;
        void* any;
    } data;
    /* 0x4C */ f32 animationTime;
    /* 0x50 */ u32 flags;
    /* 0x54 */ void (*fnAnimCallback)(struct DObj*, s32, f32);
    /* 0x58 */ void* userData;
} GObj; // size >= 0x5C

typedef struct OMMtx {
    /* 0x00 */ struct OMMtx* next;
    /* 0x04 */ u8 kind;
    /* 0x05 */ u8 unk05;
    /* 0x08 */ Mtx unk08;
} OMMtx; // size == 0x48

typedef struct Mtx3Float {
    /* 0x00 */ OMMtx* mtx;
    /* 0x04 */ Vec3f v;
} Mtx3Float; // size == 0x10

struct Mtx3Int {
    /* 0x00 */ struct OMMtx* mtx;
    /* 0x04 */ struct Vec3i v;
}; // size == 0x10

union Mtx3fi {
    struct Mtx3Float f;
    struct Mtx3Int i;
}; // size == 0x10

typedef struct Mtx4Float {
    /* 0x00 */ struct OMMtx* mtx;
    /* 0x04 */ f32 f[4];
} Mtx4Float; // size == 0x14

struct MtxCameraPersp {
    /* 0x00 */ struct OMMtx* mtx;
    /* 0x04 */ u16 perspNorm;
    /* 0x08 */ f32 fovy;
    /* 0x0C */ f32 aspect;
    /* 0x10 */ f32 near;
    /* 0x14 */ f32 far;
    /* 0x18 */ f32 scale;
}; // size == 0x1C

struct MtxCameraOrtho {
    /* 0x00 */ struct OMMtx* mtx;
    /* 0x04 */ f32 l;
    /* 0x08 */ f32 r;
    /* 0x0C */ f32 b;
    /* 0x10 */ f32 t;
    /* 0x14 */ f32 n;
    /* 0x18 */ f32 f;
    /* 0x1C */ f32 scale;
}; // size == 0x20

struct MtxCameraLookAt {
    /* 0x00 */ struct OMMtx* mtx;
    /* 0x04 */ Vec3f eye;
    /* 0x10 */ Vec3f at;
    /* 0x1C */ Vec3f up;
}; // size == 0x28;

struct MtxCameraLookAtRoll {
    /* 0x00 */ struct OMMtx* mtx;
    /* 0x04 */ f32 xEye;
    /* 0x08 */ f32 yEye;
    /* 0x0C */ f32 zEye;
    /* 0x10 */ f32 xAt;
    /* 0x14 */ f32 yAt;
    /* 0x18 */ f32 zAt;
    /* 0x1C */ f32 roll;
}; // size == 0x20;

/// This stores up to 3 `Mtx3Int`/`Mtx3Float`/`Mtx4Float` structures in the VLA data
/// based on the kind id in the `kinds` arrays:
/// Kind 1 - `struct Mtx3Int` or `union Mtx3fi`
/// Kind 2 - `struct Mtx4Float`
/// Kind 3 - `struct Mtx3Float`
struct DObjDynamicStore {
    /* 0x00 */ u8 kinds[3];
    /* 0x03 */ u8 pad;
    /* 0x04 */ u8 data[1];
}; // size == 4 + VLA

typedef struct DObjPayloadTypeC {
    /* 0x00 */ s32 dlistID;
    /* 0x04 */ Gfx* dlist;
} DObjPayloadTypeC; // size = 0x08

typedef struct DObjPayloadTypeE {
    /* 0x00 */ f32 maxSqDist;
    /* 0x04 */ Gfx* dlist;
} DObjPayloadTypeE; // size = 0x08

typedef struct DObjPayloadTypeG {
    /* 0x00 */ f32 maxSqDist;
    /* 0x04 */ DObjPayloadTypeC* payloadTypeC;
} DObjPayloadTypeG; // size = 0x08

typedef struct DObjPayloadTypeI {
    /* 0x00 */ Gfx* unk_00;
    /* 0x04 */ Gfx* unk_04;
} DObjPayloadTypeI; // size = 0x08

typedef struct DObjPayloadTypeJ {
    /* 0x00 */ s32 dlistID;
    /* 0x04 */ Gfx* unk_04;
    /* 0x08 */ Gfx* unk_08;
} DObjPayloadTypeJ; // size = 0x0C

typedef struct DObj {
    /* 0x00 */ struct DObj* nextFree;
    /* 0x04 */ struct GObj* obj;
    /* 0x08 */ struct DObj* next;
    /* 0x0C */ struct DObj* prev;
    /* 0x10 */ struct DObj* firstChild;
    /* 0x14 */ struct DObj* parent; // checked with `1` for a top level
    /* 0x18 */ struct Mtx3Float position;
    /* 0x28 */ struct Mtx4Float rotation;
    /* 0x3C */ struct Mtx3Float scale;
    /* 0x4C */ struct DObjDynamicStore* unk_4C;
    /* 0x50 */ union {
        void* any;
        Gfx* dlist;
        DObjPayloadTypeC* typeC;
        DObjPayloadTypeE* typeE;
        Gfx** typeF;
        DObjPayloadTypeG* typeG;
        DObjPayloadTypeC** typeH;
        DObjPayloadTypeI* typeI;
        DObjPayloadTypeJ* typeJ;
        DObjPayloadTypeI** typeK;
        DObjPayloadTypeJ** typeL;
    } payload;
    /* 0x54 */ u8 flags;
    /* 0x55 */ u8 animCBReceiver;
    /* 0x56 */ u8 numMatrices;
    /* 0x57 */ u8 unk_57;
    /* 0x58 */ struct OMMtx* matrices[5];
    /* 0x6C */ struct AObj* aobjList;
    /* 0x70 */ union AnimCmd* animList;
    /* 0x74 */ f32 timeLeft; // time until next animation command
    /* 0x78 */ f32 animSpeed;
    /* 0x7C */ f32 timePassed;
    /* 0x80 */ struct MObj* mobjList;
    /* 0x84 */ u32 unk84;
} DObj; // size == 0x88, but it's dynamic..?

typedef struct AObj {
    /* 0x00 */ struct AObj* next;
    /* 0x04 */ u8 paramID;
    /* 0x05 */ u8 kind;
    /* 0x08 */ f32 invDuration;
    /* 0x0C */ f32 time;
    /* 0x10 */ f32 initialValue;
    /* 0x14 */ f32 targetValue;
    /* 0x18 */ f32 rate;
    /* 0x1C */ f32 targetRate;
    /* 0x20 */ InterpData* unk_20;
} AObj; // size == 0x24

typedef struct Texture {
    ///* 0x00 */ f32 unk00;
    /* 0x00 */ u16 pad00;
    /* 0x02 */ u8 fmt;             // SetTextureImage format?
    /* 0x03 */ u8 paletteBitDepth; // SetTextureImage size?
    /* 0x04 */ u8** images;        // should this be a pointer to an array of images (sprite set)?
    /* 0x08 */ u16 scale;
    /* 0x0A */ u16 unk0A;
    /* 0x0C */ u16 widthMain;
    /* 0x0E */ u16 heightMain;
    /* 0x10 */ s32 unk_10; // could be f32??
    /* 0x14 */ f32 unk_14;
    // next three part of vec3f?
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 scaleS;
    /* 0x20 */ f32 scaleT;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ u8** palettes; // image pointers?
    /* 0x30 */ u16 flags;     // command flags?
    /* 0x32 */ u8 unk_32;     // texture image format?
    /* 0x33 */ u8 unk_33;
    /* 0x34 */ u16 blockWidth;
    /* 0x36 */ u16 blockHeight;
    /* 0x38 */ u16 widthAux;
    /* 0x3A */ u16 heightAux;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ char unk_48[0x4];
    /* 0x4C */ u32 unk_4C;
    /* 0x50 */ u8 primR; // primitive color r
    /* 0x51 */ u8 primG; // primitive color g
    /* 0x52 */ u8 primB; // primitive color b
    /* 0x53 */ u8 primA; // primitive color a
    /* 0x54 */ u8 unk_54;
    /* 0x55 */ u8 minLodValue;
    /* 0x56 */ u8 unk_56;
    /* 0x57 */ u8 unk_57;
    /* 0x58 */ u8 envR;         // env color r
    /* 0x59 */ u8 envG;         // env color g
    /* 0x5A */ u8 envB;         // env color b
    /* 0x5B */ u8 envA;         // env color a
    /* 0x5C */ u8 blendR;       // blend color r
    /* 0x5D */ u8 blendG;       // blend color g
    /* 0x5E */ u8 blendB;       // blend color b
    /* 0x5F */ u8 blendA;       // blend color a
    /* 0x60 */ u32 lightColor1; // light 1 color?
    /* 0x64 */ u32 lightColor2; // light 2 color?
    /* 0x68 */ s32 unk68;
    /* 0x6C */ s32 unk6C;
    /* 0x70 */ s32 unk70;
    /* 0x74 */ s32 unk74;
} Texture; // size == 0x78

typedef struct MObj {
    /* 0x00 */ struct MObj* next;
    /* 0x04 */ u32 pad04;
    /* 0x08 */ struct Texture texture;
    /* 0x80 */ u16 imageIndex;
    /* 0x82 */ u16 nextImageIndex;
    /* 0x84 */ f32 lodLevel;
    /* 0x88 */ f32 paletteIndex;
    /* 0x8C */ u32 pad8C;
    /* 0x90 */ struct AObj* aobjList;
    /* 0x94 */ union AnimCmd* animList;
    /* 0x98 */ f32 timeLeft;
    /* 0x9C */ f32 animSpeed;
    /* 0xA0 */ f32 timePassed;
    /* 0xA4 */ u32 padA4;
} MObj; // size = 0xA8

typedef struct SObj {
    /* 0x00 */ struct SObj* nextFree;
    /* 0x04 */ struct GObj* obj;
    /* 0x08 */ struct SObj* next;
    /* 0x0C */ struct SObj* prev;
    /* 0x10 */ Sprite sprite;
    /* 0x54 */ s32 unk_54;
    /* 0x58 */ struct SObj* unk_58;
    /* 0x5C */ UNK_PTR unk_5C;
} SObj; // size >= 0x5C

typedef struct OMCamera {
    /* 0x00 */ struct OMCamera* nextFree;
    /* 0x04 */ struct GObj* obj;
    /* 0x08 */ Vp vp;
    /* 0x18 */ union {
        struct MtxCameraPersp persp;
        struct MtxCameraOrtho ortho;
    } perspMtx;
    /* 0x38 */ union {
        struct MtxCameraLookAt lookAt;
        struct MtxCameraLookAtRoll lookAtRoll;
    } viewMtx;
    /* 0x60 */ s32 numMatrices;
    /* 0x64 */ struct OMMtx* matrices[2];
    /* 0x6C */ struct AObj* aobjList;
    /* 0x70 */ union AnimCmd* animList;
    /* 0x74 */ f32 timeLeft;
    /* 0x78 */ f32 animSpeed;
    /* 0x7C */ f32 timePassed;
    /* 0x80 */ s32 flags;   // attr flags?
    /* 0x84 */ s32 bgColor; // color?
    /* 0x88 */ void (*fnPreRender)(struct OMCamera*, s32);
    /* 0x8C */ s32 unk_8C;
} OMCamera; // size >= 0x90

typedef struct {
    /* 0x00 */ struct GObjThread* threads;
    /* 0x04 */ s32 numThreads;
    /* 0x08 */ u32 threadStackSize;
    /* 0x0C */ struct ThreadStackNode* stacks;
    /* 0x10 */ u32 numStacks;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ GObjProcess* processes;
    /* 0x1C */ s32 numProcesses;
    /* 0x20 */ struct GObj* commons;
    /* 0x24 */ s32 numObjects;
    /* 0x28 */ s32 objectSize;
    /* 0x2C */ OMMtx* matrices;
    /* 0x30 */ s32 numMatrices;
    /* 0x34 */ void* cleanupFn; // void(*)(struct DObjDynamicStore *)
    /* 0x38 */ struct AObj* aobjs;
    /* 0x3C */ s32 numAObjs;
    /* 0x40 */ struct MObj* mobjs;
    /* 0x44 */ s32 numMObjs;
    /* 0x48 */ struct DObj* dobjs;
    /* 0x4C */ s32 numDObjs;
    /* 0x50 */ s32 dobjSize;
    /* 0x54 */ struct SObj* sobjs;
    /* 0x58 */ s32 numSObjs;
    /* 0x5C */ s32 sobjSize;
    /* 0x60 */ struct OMCamera* cameras;
    /* 0x64 */ s32 numCameras;
    /* 0x68 */ s32 cameraSize;
} OMSetup; // size == 0x6C

GObjProcess* omCreateProcess(GObj* obj, void (*func)(struct GObj*), u8 kind, u32 pri);
void omDeleteGObj(GObj* obj);
void omLinkGObjDLCamera(GObj* obj, void (*renderFunc)(GObj*), u32 dlPriority, s32 arg3, s32 arg4);
OMCamera* omGObjSetCamera(GObj* obj);
DObj* omGObjAddDObj(GObj* obj, void* arg1);
void omEndProcess(GObjProcess* proc);
GObj* omAddGObj(u32 id, void (*fnUpdate)(GObj*), u8 link, u32 priority);
OMMtx* omDObjAppendMtx(DObj* dobj, u8 kind, u8 arg2);
OMMtx* omCameraAddMtx(OMCamera* arg0, u8 kind, u8 arg2);
void omDObjRemoveAllMObj(DObj* dobj);
SObj* omGObjAddSprite(GObj* obj, Sprite* sprite);
void omLinkGObjDL(GObj* obj, void (*arg1)(GObj*), u8 dlLink, u32 dlPriority, s32 cameraTag);
void omLinkGObjDLCamera(GObj* obj, void (*renderFunc)(GObj*), u32 dlPriority, s32 dlLinkBitMask, s32 cameraTag);
void omGObjRemoveSprite(SObj* obj);
void omDObjRemove(DObj* dobj);
DObj* omDObjAddChild(DObj* arg0, void* arg1);
DObj* omDObjAddSibling(DObj* dobj, void* arg1);
void omDrawAll(void);
void omUpdateAll(void);
void omCreateObjects(OMSetup* setup);
AObj* omMObjAddAObj(MObj* mobj, u8 paramID);
AObj* omCameraAddAObj(OMCamera* obj, u8 paramID);
MObj* omDObjAddMObj(DObj* dobj, Texture* arg1);
void omDObjResetAnimation(DObj* dobj);
AObj* omDObjAddAObj(DObj* dobj, u8 paramID);
void omMObjResetAObjList(MObj* mobj);
OMMtx* omDObjAddMtx(DObj* dobj, u8 kind, u8 arg2, s32 index);
void omMoveGObjDL(GObj* arg0, u8 dlLink, u32 dlPriority);
void omMoveGObjDLHead(GObj* arg0, u8 dlLink, u32 dlPriority);

extern GObj* omCurrentObject;
extern GObj* omCurrentCamera;
extern GObj* omRenderedObject;
extern GObj* omGObjListHead[];
extern OSMesgQueue omProcessWaitQueue;
extern GObjProcess* omCurrentProcess;
extern struct Unk80046A88 omD_8004AC78[32];
extern GObj* omGObjListDlHead[33];

#endif /* SYS_OM_H */
