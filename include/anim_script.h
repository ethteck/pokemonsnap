#ifndef ANIM_SCRIPT_H
#define ANIM_SCRIPT_H

#include <common.h>

typedef struct AnimLine0 {
    u32 cmd;
} AnimLine0;

typedef struct AnimLine1 {
    u32 cmd;
    f32 values[1];
} AnimLine1;

typedef struct AnimLine2 {
    u32 cmd;
    f32 values[2];
} AnimLine2;

typedef struct AnimLine3 {
    u32 cmd;
    f32 values[3];
} AnimLine3;

typedef struct AnimLine4 {
    u32 cmd;
    f32 values[4];
} AnimLine4;

typedef struct AnimLine5 {
    u32 cmd;
    f32 values[5];
} AnimLine5;

typedef struct AnimLine6 {
    u32 cmd;
    f32 values[6];
} AnimLine6;

typedef struct AnimLine7 {
    u32 cmd;
    f32 values[7];
} AnimLine7;

typedef struct AnimLine8 {
    u32 cmd;
    f32 values[8];
} AnimLine8;

typedef struct AnimLine9 {
    u32 cmd;
    f32 values[9];
} AnimLine9;

typedef struct AnimLine10 {
    u32 cmd;
    f32 values[10];
} AnimLine10;

typedef struct AnimLine12 {
    u32 cmd;
    f32 values[12];
} AnimLine12;

typedef struct AnimLineI1 {
    u32 cmd;
    u32 values[1];
} AnimLineI1;

typedef struct AnimLineI2 {
    u32 cmd;
    u32 values[2];
} AnimLineI2;

typedef struct AnimLinePtr {
    u32 cmd;
    void* ptr;
} AnimLinePtr;

typedef struct AnimLinePtr2 {
    u32 cmd;
    void* ptr[2];
} AnimLinePtr2;

#define __ANIMLINENAME __CONCAT2_3__(__ANIMFILE, animline, __LINE__)

#define ROTX (1 << (ANIM_PARAM_ROTATION_X - ANIM_PARAM_MODEL_MIN))
#define ROTY (1 << (ANIM_PARAM_ROTATION_Y - ANIM_PARAM_MODEL_MIN))
#define ROTZ (1 << (ANIM_PARAM_ROTATION_Z - ANIM_PARAM_MODEL_MIN))
#define PATH_PARAM (1 << (ANIM_PARAM_4 - ANIM_PARAM_MODEL_MIN))
#define POSX (1 << (ANIM_PARAM_POSITION_X - ANIM_PARAM_MODEL_MIN))
#define POSY (1 << (ANIM_PARAM_POSITION_Y - ANIM_PARAM_MODEL_MIN))
#define POSZ (1 << (ANIM_PARAM_POSITION_Z - ANIM_PARAM_MODEL_MIN))
#define SCALEX (1 << (ANIM_PARAM_SCALE_X - ANIM_PARAM_MODEL_MIN))
#define SCALEY (1 << (ANIM_PARAM_SCALE_Y - ANIM_PARAM_MODEL_MIN))
#define SCALEZ (1 << (ANIM_PARAM_SCALE_Z - ANIM_PARAM_MODEL_MIN))

#define IMG_INDEX (1 << (ANIM_PARAM_TEXTURE_13 - ANIM_PARAM_TEXTURE_MIN))
#define OFFSET_S (1 << (ANIM_PARAM_TEXTURE_14 - ANIM_PARAM_TEXTURE_MIN))
#define OFFSET_T (1 << (ANIM_PARAM_TEXTURE_15 - ANIM_PARAM_TEXTURE_MIN))
#define SCALE_S (1 << (ANIM_PARAM_TEXTURE_16 - ANIM_PARAM_TEXTURE_MIN))
#define SCALE_T (1 << (ANIM_PARAM_TEXTURE_17 - ANIM_PARAM_TEXTURE_MIN))
#define MAT_PARAM_5 (1 << (ANIM_PARAM_TEXTURE_18 - ANIM_PARAM_TEXTURE_MIN))
#define MAT_PARAM_6 (1 << (ANIM_PARAM_TEXTURE_19 - ANIM_PARAM_TEXTURE_MIN))
#define MAT_PARAM_7 (1 << (ANIM_PARAM_TEXTURE_20 - ANIM_PARAM_TEXTURE_MIN))
#define MAT_PARAM_8 (1 << (ANIM_PARAM_TEXTURE_21 - ANIM_PARAM_TEXTURE_MIN))

#define PRIM_COLOR (1 << (ANIM_PARAM_TEXTURE_EXTRA_37 - ANIM_PARAM_TEXTURE_EXTRA_MIN))
#define ENV_COLOR (1 << (ANIM_PARAM_TEXTURE_EXTRA_38 - ANIM_PARAM_TEXTURE_EXTRA_MIN))
#define BLEND_COLOR (1 << (ANIM_PARAM_TEXTURE_EXTRA_39 - ANIM_PARAM_TEXTURE_EXTRA_MIN))
#define LIGHT_COLOR_1 (1 << (ANIM_PARAM_TEXTURE_EXTRA_40 - ANIM_PARAM_TEXTURE_EXTRA_MIN))
#define LIGHT_COLOR_2 (1 << (ANIM_PARAM_TEXTURE_EXTRA_41 - ANIM_PARAM_TEXTURE_EXTRA_MIN))

#define FOVY (1 << (ANIM_PARAM_CAMERA_FOVY - ANIM_PARAM_CAMERA_MIN))
#define EYE_PATH_PARAM (1 << (ANIM_PARAM_CAMERA_28 - ANIM_PARAM_CAMERA_MIN))
#define AT_PATH_PARAM (1 << (ANIM_PARAM_CAMERA_32 - ANIM_PARAM_CAMERA_MIN))

#define asWait(n) static AnimLine0 __ANIMLINENAME = {  ((ANIM_CMD_WAIT << 25) | (0 << 15) | n) }
#define asWaitf(n) {  ((ANIM_CMD_WAIT << 25) | (0 << 15) | n) }

#define asSetFlags(n, flags) static AnimLine0 __ANIMLINENAME = {  ((ANIM_CMD_SET_FLAGS << 25) | (flags << 15) | n) }

#define asRestart(script) static AnimLinePtr __ANIMLINENAME = {  ((ANIM_CMD_SET_ANIMATION << 25) | (0 << 15) | 0), &script }

#define asSetPath(path) static AnimLinePtr __ANIMLINENAME = {  ((ANIM_CMD_13 << 25) | (8 << 15) | 0), &path }
#define asSetPathf(path) {  ((ANIM_CMD_13 << 25) | (8 << 15) | 0), &path }

#define asSetCamPath(path, path2) static AnimLinePtr2 __ANIMLINENAME = {  ((ANIM_CMD_13 << 25) | ((0x88) << 15) | 0), &path, &path2 }
#define asSetCamPath_f(path, path2) {  ((ANIM_CMD_13 << 25) | ((0x88) << 15) | 0), &path, &path2 }

#define asEnd() static AnimLine0 __ANIMLINENAME = {  ((ANIM_CMD_END << 25) | (0 << 15) | 0) }

#define asPlaySound(duration, category, id) static AnimLine0 __ANIMLINENAME = {  ((ANIM_CMD_16 << 25) | ((((category) << 8) | (id)) << 15) | duration) }
#define asPlayEffect(duration, category, id) static AnimLine0 __ANIMLINENAME = {  ((ANIM_CMD_16 << 25) | ((((category) << 8) | (id + 1)) << 15) | duration) }

#define asBegin_0(script) static AnimLine0 script =
#define asBegin_1(script) static AnimLine1 script =
#define asBegin_2(script) static AnimLine2 script =
#define asBegin_3(script) static AnimLine3 script =
#define asBegin_4(script) static AnimLine4 script =
#define asBegin_5(script) static AnimLine5 script =
#define asBegin_6(script) static AnimLine6 script =
#define asBegin_7(script) static AnimLine7 script =
#define asBegin_8(script) static AnimLine8 script =
#define asBegin_9(script) static AnimLine9 script =
#define asBegin_10(script) static AnimLine10 script =
#define asBegin_12(script) static AnimLine12 script =
#define asBegin_I1(script) static AnimLineI1 script =
#define asBegin_ptr(script) static AnimLinePtr script =
#define asBegin_ptr2_ns(script) AnimLinePtr2 script =

#define asSetBlock_1(n, param1, val1) static AnimLine1 __ANIMLINENAME = {  ((ANIM_CMD_SET_VALUE_LAST << 25) | ((param1) << 15) | n), { val1 } }
#define asSetBlock_2(n, param1, val1, param2, val2) static AnimLine2 __ANIMLINENAME = {  ((ANIM_CMD_SET_VALUE_LAST << 25) | ((param1 | param2) << 15) | n), { val1, val2 } }
#define asSetBlock_3(n, param1, val1, param2, val2, param3, val3) static AnimLine3 __ANIMLINENAME = {  ((ANIM_CMD_SET_VALUE_LAST << 25) | ((param1 | param2 | param3) << 15) | n), { val1, val2, val3 } }
#define asSetBlock_4(n, param1, val1, param2, val2, param3, val3, param4, val4) static AnimLine4 __ANIMLINENAME = {  ((ANIM_CMD_SET_VALUE_LAST << 25) | ((param1 | param2 | param3 | param4) << 15) | n), { val1, val2, val3, val4 } }
#define asSetBlock_6(n, param1, val1, param2, val2, param3, val3, param4, val4, param5, val5, param6, val6) static AnimLine6 __ANIMLINENAME = {  ((ANIM_CMD_SET_VALUE_LAST << 25) | ((param1 | param2 | param3 | param4 | param5 | param6) << 15) | n), { val1, val2, val3, val4, val5, val6 } }
#define asSetBlock_1f(n, param1, val1) {  ((ANIM_CMD_SET_VALUE_LAST << 25) | ((param1) << 15) | n), { val1 } }
#define asSetBlock_3f(n, param1, val1, param2, val2, param3, val3) {  ((ANIM_CMD_SET_VALUE_LAST << 25) | ((param1 | param2 | param3) << 15) | n), { val1, val2, val3 } }
#define asSetBlock_4f(n, param1, val1, param2, val2, param3, val3, param4, val4) {  ((ANIM_CMD_SET_VALUE_LAST << 25) | ((param1 | param2 | param3 | param4) << 15) | n), { val1, val2, val3, val4 } }
#define asSetBlock_6f(n, param1, val1, param2, val2, param3, val3, param4, val4, param5, val5, param6, val6) {  ((ANIM_CMD_SET_VALUE_LAST << 25) | ((param1 | param2 | param3 | param4 | param5 | param6) << 15) | n), { val1, val2, val3, val4, val5, val6 } }

#define asSet_1(n, param1, val1) static AnimLine1 __ANIMLINENAME = {  ((ANIM_CMD_SET_VALUE << 25) | ((param1) << 15) | n), { val1 } }
#define asSet_2(n, param1, val1, param2, val2) static AnimLine2 __ANIMLINENAME = {  ((ANIM_CMD_SET_VALUE << 25) | ((param1 | param2) << 15) | n), { val1, val2 } }
#define asSet_3(n, param1, val1, param2, val2, param3, val3) static AnimLine3 __ANIMLINENAME = {  ((ANIM_CMD_SET_VALUE << 25) | ((param1 | param2 | param3) << 15) | n), { val1, val2, val3 } }
#define asSet_1f(n, param1, val1) {  ((ANIM_CMD_SET_VALUE << 25) | ((param1) << 15) | n), { val1 } }
#define asSet_2f(n, param1, val1, param2, val2) {  ((ANIM_CMD_SET_VALUE << 25) | ((param1 | param2) << 15) | n), { val1, val2 } }
#define asSet_3f(n, param1, val1, param2, val2, param3, val3) {  ((ANIM_CMD_SET_VALUE << 25) | ((param1 | param2 | param3) << 15) | n), { val1, val2, val3 } }
#define asSet_4f(n, param1, val1, param2, val2, param3, val3, param4, val4) {  ((ANIM_CMD_SET_VALUE << 25) | ((param1 | param2 | param3 | param4) << 15) | n), { val1, val2, val3, val4 } }

#define asSetWithRateBlock_2(n, param1, val1, rate1) static AnimLine2 __ANIMLINENAME = {  ((ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((param1) << 15) | n), { val1, rate1 } }
#define asSetWithRateBlock_4(n, param1, val1, rate1, param2, val2, rate2) static AnimLine4 __ANIMLINENAME = {  ((ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((param1 | param2) << 15) | n), { val1, rate1, val2, rate2 } }
#define asSetWithRateBlock_6(n, param1, val1, rate1, param2, val2, rate2, param3, val3, rate3) static AnimLine6 __ANIMLINENAME = {  ((ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((param1 | param2 | param3) << 15) | n), { val1, rate1, val2, rate2, val3, rate3 } }
#define asSetWithRateBlock_8(n, param1, val1, rate1, param2, val2, rate2, param3, val3, rate3, param4, val4, rate4) static AnimLine8 __ANIMLINENAME = {  ((ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((param1 | param2 | param3 | param4) << 15) | n), { val1, rate1, val2, rate2, val3, rate3, val4, rate4 } }
#define asSetWithRateBlock_10(n, param1, val1, rate1, param2, val2, rate2, param3, val3, rate3, param4, val4, rate4, param5, val5, rate5) static AnimLine10 __ANIMLINENAME = {  ((ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((param1 | param2 | param3 | param4 | param5) << 15) | n), { val1, rate1, val2, rate2, val3, rate3, val4, rate4, val5, rate5 } }
#define asSetWithRateBlock_12(n, param1, val1, rate1, param2, val2, rate2, param3, val3, rate3, param4, val4, rate4, param5, val5, rate5, param6, val6, rate6) static AnimLine12 __ANIMLINENAME = {  ((ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((param1 | param2 | param3 | param4 | param5 | param6) << 15) | n), { val1, rate1, val2, rate2, val3, rate3, val4, rate4, val5, rate5, val6, rate6 } }
#define asSetWithRateBlock_2f(n, param1, val1, rate1) {  ((ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((param1) << 15) | n), { val1, rate1 } }
#define asSetWithRateBlock_4f(n, param1, val1, rate1, param2, val2, rate2) {  ((ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((param1 | param2) << 15) | n), { val1, rate1, val2, rate2 } }
#define asSetWithRateBlock_6f(n, param1, val1, rate1, param2, val2, rate2, param3, val3, rate3) {  ((ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((param1 | param2 | param3) << 15) | n), { val1, rate1, val2, rate2, val3, rate3 } }
#define asSetWithRateBlock_12f(n, param1, val1, rate1, param2, val2, rate2, param3, val3, rate3, param4, val4, rate4, param5, val5, rate5, param6, val6, rate6) {  ((ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((param1 | param2 | param3 | param4 | param5 | param6) << 15) | n), { val1, rate1, val2, rate2, val3, rate3, val4, rate4, val5, rate5, val6, rate6 } }

#define asSetWithRate_2(n, param1, val1, rate1) static AnimLine2 __ANIMLINENAME = {  ((ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((param1) << 15) | n), { val1, rate1 } }
#define asSetWithRate_4(n, param1, val1, rate1, param2, val2, rate2) static AnimLine4 __ANIMLINENAME = {  ((ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((param1 | param2) << 15) | n), { val1, rate1, val2, rate2 } }
#define asSetWithRate_6(n, param1, val1, rate1, param2, val2, rate2, param3, val3, rate3) static AnimLine6 __ANIMLINENAME = {  ((ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((param1 | param2 | param3) << 15) | n), { val1, rate1, val2, rate2, val3, rate3 } }
#define asSetWithRate_8(n, param1, val1, rate1, param2, val2, rate2, param3, val3, rate3, param4, val4, rate4) static AnimLine8 __ANIMLINENAME = {  ((ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((param1 | param2 | param3 | param4) << 15) | n), { val1, rate1, val2, rate2, val3, rate3, val4, rate4 } }
#define asSetWithRate_10(n, param1, val1, rate1, param2, val2, rate2, param3, val3, rate3, param4, val4, rate4, param5, val5, rate5) static AnimLine10 __ANIMLINENAME = {  ((ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((param1 | param2 | param3 | param4 | param5) << 15) | n), { val1, rate1, val2, rate2, val3, rate3, val4, rate4, val5, rate5 } }
#define asSetWithRate_12(n, param1, val1, rate1, param2, val2, rate2, param3, val3, rate3, param4, val4, rate4, param5, val5, rate5, param6, val6, rate6) static AnimLine12 __ANIMLINENAME = {  ((ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((param1 | param2 | param3 | param4 | param5 | param6) << 15) | n), { val1, rate1, val2, rate2, val3, rate3, val4, rate4, val5, rate5, val6, rate6 } }
#define asSetWithRate_2f(n, param1, val1, rate1) {  ((ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((param1) << 15) | n), { val1, rate1 } }
#define asSetWithRate_4f(n, param1, val1, rate1, param2, val2, rate2) {  ((ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((param1 | param2) << 15) | n), { val1, rate1, val2, rate2 } }
#define asSetWithRate_6f(n, param1, val1, rate1, param2, val2, rate2, param3, val3, rate3) {  ((ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((param1 | param2 | param3) << 15) | n), { val1, rate1, val2, rate2, val3, rate3 } }
#define asSetWithRate_8f(n, param1, val1, rate1, param2, val2, rate2, param3, val3, rate3, param4, val4, rate4) {  ((ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((param1 | param2 | param3 | param4) << 15) | n), { val1, rate1, val2, rate2, val3, rate3, val4, rate4 } }
#define asSetWithRate_10f(n, param1, val1, rate1, param2, val2, rate2, param3, val3, rate3, param4, val4, rate4, param5, val5, rate5) {  ((ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((param1 | param2 | param3 | param4 | param5) << 15) | n), { val1, rate1, val2, rate2, val3, rate3, val4, rate4, val5, rate5 } }
#define asSetWithRate_12f(n, param1, val1, rate1, param2, val2, rate2, param3, val3, rate3, param4, val4, rate4, param5, val5, rate5, param6, val6, rate6) {  ((ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((param1 | param2 | param3 | param4 | param5 | param6) << 15) | n), { val1, rate1, val2, rate2, val3, rate3, val4, rate4, val5, rate5, val6, rate6 } }

#define asSetTargetRate_1(n, param1, val1) static AnimLine1 __ANIMLINENAME = {  ((ANIM_CMD_SET_TARGET_RATE << 25) | ((param1) << 15) | n), { val1 } }
#define asSetTargetRate_2(n, param1, val1, param2, val2) static AnimLine2 __ANIMLINENAME = {  ((ANIM_CMD_SET_TARGET_RATE << 25) | ((param1 | param2) << 15) | n), { val1, val2 } }
#define asSetTargetRate_3(n, param1, val1, param2, val2, param3, val3) static AnimLine3 __ANIMLINENAME = {  ((ANIM_CMD_SET_TARGET_RATE << 25) | ((param1 | param2 | param3) << 15) | n), { val1, val2, val3 } }
#define asSetTargetRate_4(n, param1, val1, param2, val2, param3, val3, param4, val4) static AnimLine4 __ANIMLINENAME = {  ((ANIM_CMD_SET_TARGET_RATE << 25) | ((param1 | param2 | param3 | param4) << 15) | n), { val1, val2, val3, val4 } }
#define asSetTargetRate_5(n, param1, val1, param2, val2, param3, val3, param4, val4, param5, val5) static AnimLine5 __ANIMLINENAME = {  ((ANIM_CMD_SET_TARGET_RATE << 25) | ((param1 | param2 | param3 | param4 | param5) << 15) | n), { val1, val2, val3, val4, val5 } }
#define asSetTargetRate_6(n, param1, val1, param2, val2, param3, val3, param4, val4, param5, val5, param6, val6) static AnimLine6 __ANIMLINENAME = {  ((ANIM_CMD_SET_TARGET_RATE << 25) | ((param1 | param2 | param3 | param4 | param5 | param6) << 15) | n), { val1, val2, val3, val4, val5, val6 } }

#define asSetZeroRateBlock_1(n, param1, val1) static AnimLine1 __ANIMLINENAME = {  ((ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((param1) << 15) | n), { val1 } }
#define asSetZeroRateBlock_2(n, param1, val1, param2, val2) static AnimLine2 __ANIMLINENAME = {  ((ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((param1 | param2) << 15) | n), { val1, val2 } }
#define asSetZeroRateBlock_3(n, param1, val1, param2, val2, param3, val3) static AnimLine3 __ANIMLINENAME = {  ((ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((param1 | param2 | param3) << 15) | n), { val1, val2, val3 } }
#define asSetZeroRateBlock_4(n, param1, val1, param2, val2, param3, val3, param4, val4) static AnimLine4 __ANIMLINENAME = {  ((ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((param1 | param2 | param3 | param4) << 15) | n), { val1, val2, val3, val4 } }
#define asSetZeroRateBlock_5(n, param1, val1, param2, val2, param3, val3, param4, val4, param5, val5) static AnimLine5 __ANIMLINENAME = {  ((ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((param1 | param2 | param3 | param4 | param5) << 15) | n), { val1, val2, val3, val4, val5 } }
#define asSetZeroRateBlock_6(n, param1, val1, param2, val2, param3, val3, param4, val4, param5, val5, param6, val6) static AnimLine6 __ANIMLINENAME = {  ((ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((param1 | param2 | param3 | param4 | param5 | param6) << 15) | n), { val1, val2, val3, val4, val5, val6 } }
#define asSetZeroRateBlock_1f(n, param1, val1) { ((ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((param1) << 15) | n), { val1 } }
#define asSetZeroRateBlock_2f(n, param1, val1, param2, val2) { ((ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((param1 | param2) << 15) | n), { val1, val2 } }
#define asSetZeroRateBlock_3f(n, param1, val1, param2, val2, param3, val3) { ((ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((param1 | param2 | param3) << 15) | n), { val1, val2, val3 } }
#define asSetZeroRateBlock_4f(n, param1, val1, param2, val2, param3, val3, param4, val4) { ((ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((param1 | param2 | param3 | param4) << 15) | n), { val1, val2, val3, val4 } }
#define asSetZeroRateBlock_5f(n, param1, val1, param2, val2, param3, val3, param4, val4, param5, val5) { ((ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((param1 | param2 | param3 | param4 | param5) << 15) | n), { val1, val2, val3, val4, val5 } }
#define asSetZeroRateBlock_6f(n, param1, val1, param2, val2, param3, val3, param4, val4, param5, val5, param6, val6) {  ((ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((param1 | param2 | param3 | param4 | param5 | param6) << 15) | n), { val1, val2, val3, val4, val5, val6 } }

#define asSetZeroRate_1(n, param1, val1) static AnimLine1 __ANIMLINENAME = {  ((ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((param1) << 15) | n), { val1 } }
#define asSetZeroRate_2(n, param1, val1, param2, val2) static AnimLine2 __ANIMLINENAME = {  ((ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((param1 | param2) << 15) | n), { val1, val2 } }
#define asSetZeroRate_3(n, param1, val1, param2, val2, param3, val3) static AnimLine3 __ANIMLINENAME = {  ((ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((param1 | param2 | param3) << 15) | n), { val1, val2, val3 } }
#define asSetZeroRate_4(n, param1, val1, param2, val2, param3, val3, param4, val4) static AnimLine4 __ANIMLINENAME = {  ((ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((param1 | param2 | param3 | param4) << 15) | n), { val1, val2, val3, val4 } }
#define asSetZeroRate_5(n, param1, val1, param2, val2, param3, val3, param4, val4, param5, val5) static AnimLine5 __ANIMLINENAME = {  ((ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((param1 | param2 | param3 | param4 | param5) << 15) | n), { val1, val2, val3, val4, val5 } }
#define asSetZeroRate_1f(n, param1, val1) {  ((ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((param1) << 15) | n), { val1 } }
#define asSetZeroRate_2f(n, param1, val1, param2, val2) {  ((ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((param1 | param2) << 15) | n), { val1, val2 } }
#define asSetZeroRate_3f(n, param1, val1, param2, val2, param3, val3) {  ((ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((param1 | param2 | param3) << 15) | n), { val1, val2, val3 } }
#define asSetZeroRate_4f(n, param1, val1, param2, val2, param3, val3, param4, val4) {  ((ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((param1 | param2 | param3 | param4) << 15) | n), { val1, val2, val3, val4 } }
#define asSetZeroRate_5f(n, param1, val1, param2, val2, param3, val3, param4, val4, param5, val5) {  ((ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((param1 | param2 | param3 | param4 | param5) << 15) | n), { val1, val2, val3, val4, val5 } }
#define asSetZeroRate_6f(n, param1, val1, param2, val2, param3, val3, param4, val4, param5, val5, param6, val6) {  ((ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((param1 | param2 | param3 | param4 | param5 | param6) << 15) | n), { val1, val2, val3, val4, val5, val6 } }
#define asSetZeroRate_7f(n, param1, val1, param2, val2, param3, val3, param4, val4, param5, val5, param6, val6, param7, val7) {  ((ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((param1 | param2 | param3 | param4 | param5 | param6 | param7) << 15) | n), { val1, val2, val3, val4, val5, val6, val7 } }

#define asSetAfterBlock_1(n, param1, val1) static AnimLine1 __ANIMLINENAME = {  ((ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((param1) << 15) | n), { val1 } }
#define asSetAfterBlock_2(n, param1, val1, param2, val2) static AnimLine2 __ANIMLINENAME = {  ((ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((param1 | param2) << 15) | n), { val1, val2 } }
#define asSetAfterBlock_3(n, param1, val1, param2, val2, param3, val3) static AnimLine3 __ANIMLINENAME = {  ((ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((param1 | param2 | param3) << 15) | n), { val1, val2, val3 } }
#define asSetAfterBlock_4(n, param1, val1, param2, val2, param3, val3, param4, val4) static AnimLine4 __ANIMLINENAME = {  ((ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((param1 | param2 | param3 | param4) << 15) | n), { val1, val2, val3, val4 } }
#define asSetAfterBlock_5(n, param1, val1, param2, val2, param3, val3, param4, val4, param5, val5) static AnimLine5 __ANIMLINENAME = {  ((ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((param1 | param2 | param3 | param4 | param5) << 15) | n), { val1, val2, val3, val4, val5 } }
#define asSetAfterBlock_6(n, param1, val1, param2, val2, param3, val3, param4, val4, param5, val5, param6, val6) static AnimLine6 __ANIMLINENAME = {  ((ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((param1 | param2 | param3 | param4 | param5 | param6) << 15) | n), { val1, val2, val3, val4, val5, val6 } }
#define asSetAfterBlock_7(n, param1, val1, param2, val2, param3, val3, param4, val4, param5, val5, param6, val6, param7, val7) static AnimLine7 __ANIMLINENAME = {  ((ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((param1 | param2 | param3 | param4 | param5 | param6 | param7) << 15) | n), { val1, val2, val3, val4, val5, val6, val7 } }
#define asSetAfterBlock_8(n, param1, val1, param2, val2, param3, val3, param4, val4, param5, val5, param6, val6, param7, val7, param8, val8) static AnimLine8 __ANIMLINENAME = {  ((ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((param1 | param2 | param3 | param4 | param5 | param6 | param7 | param8) << 15) | n), { val1, val2, val3, val4, val5, val6, val7, val8 } }
#define asSetAfterBlock_9(n, param1, val1, param2, val2, param3, val3, param4, val4, param5, val5, param6, val6, param7, val7, param8, val8, param9, val9) static AnimLine9 __ANIMLINENAME = {  ((ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((param1 | param2 | param3 | param4 | param5 | param6 | param7 | param8 | param9) << 15) | n), { val1, val2, val3, val4, val5, val6, val7, val8, val9 } }
#define asSetAfterBlock_1f(n, param1, val1) {  ((ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((param1) << 15) | n), { val1 } }
#define asSetAfterBlock_2f(n, param1, val1, param2, val2) { ((ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((param1 | param2) << 15) | n), { val1, val2 } }
#define asSetAfterBlock_3f(n, param1, val1, param2, val2, param3, val3) {  ((ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((param1 | param2 | param3) << 15) | n), { val1, val2, val3 } }
#define asSetAfterBlock_4f(n, param1, val1, param2, val2, param3, val3, param4, val4) {  ((ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((param1 | param2 | param3 | param4) << 15) | n), { val1, val2, val3, val4 } }
#define asSetAfterBlock_5f(n, param1, val1, param2, val2, param3, val3, param4, val4, param5, val5) {  ((ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((param1 | param2 | param3 | param4 | param5) << 15) | n), { val1, val2, val3, val4, val5 } }
#define asSetAfterBlock_6f(n, param1, val1, param2, val2, param3, val3, param4, val4, param5, val5, param6, val6) {  ((ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((param1 | param2 | param3 | param4 | param5 | param6) << 15) | n), { val1, val2, val3, val4, val5, val6 } }
#define asSetAfterBlock_7f(n, param1, val1, param2, val2, param3, val3, param4, val4, param5, val5, param6, val6, param7, val7) {  ((ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((param1 | param2 | param3 | param4 | param5 | param6 | param7) << 15) | n), { val1, val2, val3, val4, val5, val6, val7 } }
#define asSetAfterBlock_8f(n, param1, val1, param2, val2, param3, val3, param4, val4, param5, val5, param6, val6, param7, val7, param8, val8) {  ((ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((param1 | param2 | param3 | param4 | param5 | param6 | param7 | param8) << 15) | n), { val1, val2, val3, val4, val5, val6, val7, val8 } }
#define asSetAfterBlock_9f(n, param1, val1, param2, val2, param3, val3, param4, val4, param5, val5, param6, val6, param7, val7, param8, val8, param9, val9) {  ((ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((param1 | param2 | param3 | param4 | param5 | param6 | param7 | param8 | param9) << 15) | n), { val1, val2, val3, val4, val5, val6, val7, val8, val9 } }

#define asSetAfter_1(n, param1, val1) static AnimLine1 __ANIMLINENAME = {  ((ANIM_CMD_SET_VALUE_AFTER << 25) | ((param1) << 15) | n), { val1 } }
#define asSetAfter_2(n, param1, val1, param2, val2) static AnimLine2 __ANIMLINENAME = {  ((ANIM_CMD_SET_VALUE_AFTER << 25) | ((param1 | param2) << 15) | n), { val1, val2 } }
#define asSetAfter_3(n, param1, val1, param2, val2, param3, val3) static AnimLine3 __ANIMLINENAME = {  ((ANIM_CMD_SET_VALUE_AFTER << 25) | ((param1 | param2 | param3) << 15) | n), { val1, val2, val3 } }
#define asSetAfter_4(n, param1, val1, param2, val2, param3, val3, param4, val4) static AnimLine4 __ANIMLINENAME = { ((ANIM_CMD_SET_VALUE_AFTER << 25) | ((param1 | param2 | param3 | param4) << 15) | n), { val1, val2, val3, val4 } }
#define asSetAfter_5(n, param1, val1, param2, val2, param3, val3, param4, val4, param5, val5) static AnimLine5 __ANIMLINENAME = { ((ANIM_CMD_SET_VALUE_AFTER << 25) | ((param1 | param2 | param3 | param4 | param5) << 15) | n), { val1, val2, val3, val4, val5 } }
#define asSetAfter_6(n, param1, val1, param2, val2, param3, val3, param4, val4, param5, val5, param6, val6) static AnimLine6 __ANIMLINENAME = { ((ANIM_CMD_SET_VALUE_AFTER << 25) | ((param1 | param2 | param3 | param4 | param5 | param6) << 15) | n), { val1, val2, val3, val4, val5, val6} }
#define asSetAfter_7(n, param1, val1, param2, val2, param3, val3, param4, val4, param5, val5, param6, val6, param7, val7) static AnimLine7 __ANIMLINENAME = { ((ANIM_CMD_SET_VALUE_AFTER << 25) | ((param1 | param2 | param3 | param4 | param5 | param6 | param7) << 15) | n), { val1, val2, val3, val4, val5, val6, val7 } }
#define asSetAfter_8(n, param1, val1, param2, val2, param3, val3, param4, val4, param5, val5, param6, val6, param7, val7, param8, val8) static AnimLine8 __ANIMLINENAME = { ((ANIM_CMD_SET_VALUE_AFTER << 25) | ((param1 | param2 | param3 | param4 | param5 | param6 | param7 | param8) << 15) | n), { val1, val2, val3, val4, val5, val6, val7, val8 } }
#define asSetAfter_1f(n, param1, val1) {  ((ANIM_CMD_SET_VALUE_AFTER << 25) | ((param1) << 15) | n), { val1 } }
#define asSetAfter_2f(n, param1, val1, param2, val2) {  ((ANIM_CMD_SET_VALUE_AFTER << 25) | ((param1 | param2) << 15) | n), { val1, val2 } }
#define asSetAfter_3f(n, param1, val1, param2, val2, param3, val3) {  ((ANIM_CMD_SET_VALUE_AFTER << 25) | ((param1 | param2 | param3) << 15) | n), { val1, val2, val3 } }
#define asSetAfter_4f(n, param1, val1, param2, val2, param3, val3, param4, val4) { ((ANIM_CMD_SET_VALUE_AFTER << 25) | ((param1 | param2 | param3 | param4) << 15) | n), { val1, val2, val3, val4 } }
#define asSetAfter_5f(n, param1, val1, param2, val2, param3, val3, param4, val4, param5, val5) {  ((ANIM_CMD_SET_VALUE_AFTER << 25) | ((param1 | param2 | param3 | param4 | param5) << 15) | n), { val1, val2, val3, val4, val5 } }
#define asSetAfter_6f(n, param1, val1, param2, val2, param3, val3, param4, val4, param5, val5, param6, val6) { ((ANIM_CMD_SET_VALUE_AFTER << 25) | ((param1 | param2 | param3 | param4 | param5 | param6) << 15) | n), { val1, val2, val3, val4, val5, val6} }
#define asSetAfter_7f(n, param1, val1, param2, val2, param3, val3, param4, val4, param5, val5, param6, val6, param7, val7) { ((ANIM_CMD_SET_VALUE_AFTER << 25) | ((param1 | param2 | param3 | param4 | param5 | param6 | param7) << 15) | n), { val1, val2, val3, val4, val5, val6, val7 } }
#define asSetAfter_9f(n, param1, val1, param2, val2, param3, val3, param4, val4, param5, val5, param6, val6, param7, val7, param8, val8, param9, val9) {  ((ANIM_CMD_SET_VALUE_AFTER << 25) | ((param1 | param2 | param3 | param4 | param5 | param6 | param7 | param8 | param9) << 15) | n), { val1, val2, val3, val4, val5, val6, val7, val8, val9} }

#define asSkip_0(n) static AnimLine0 __ANIMLINENAME = {  ((ANIM_CMD_12 << 25) | ((0) << 15) | n) }
#define asSkip_1(n, param1) static AnimLine0 __ANIMLINENAME = {  ((ANIM_CMD_12 << 25) | ((param1) << 15) | n) }
#define asSkip_2(n, param1, param2) static AnimLine0 __ANIMLINENAME = {  ((ANIM_CMD_12 << 25) | ((param1 | param2) << 15) | n) }
#define asSkip_3(n, param1, param2, param3) static AnimLine0 __ANIMLINENAME = {  ((ANIM_CMD_12 << 25) | ((param1 | param2 | param3) << 15) | n) }

#define asSetVisible_1(n, b1) static AnimLine1 __ANIMLINENAME = {  ((ANIM_CMD_17 << 25) | ((1) << 15) | n), { ((1 << b1)) } }
#define asSetVisible_2(n, b1, b2) static AnimLine1 __ANIMLINENAME = {  ((ANIM_CMD_17 << 25) | ((1) << 15) | n), { ((1 << b1) | (1 << b2)) } }
#define asSetVisible_3(n, b1, b2, b3) static AnimLine1 __ANIMLINENAME = {  ((ANIM_CMD_17 << 25) | ((1) << 15) | n), { ((1 << b1) | (1 << b2) | (1 << b3)) } }
#define asSetVisible_4(n, b1, b2, b3, b4) static AnimLine1 __ANIMLINENAME = {  ((ANIM_CMD_17 << 25) | ((1) << 15) | n), { ((1 << b1) | (1 << b2) | (1 << b3) | (1 << b4)) } }
#define asSetVisible_2f(n, b1, b2) {  ((ANIM_CMD_17 << 25) | ((1) << 15) | n), { ((1 << b1) | (1 << b2)) } }
#define asSetVisible_3f(n, b1, b2, b3) { ((ANIM_CMD_17 << 25) | ((1) << 15) | n), { ((1 << b1) | (1 << b2) | (1 << b3)) } }
#define asSetVisible_4f(n, b1, b2, b3, b4) {  ((ANIM_CMD_17 << 25) | ((1) << 15) | n), { ((1 << b1) | (1 << b2) | (1 << b3) | (1 << b4)) } }

#define asSetExtraBlock_1(n, param1, r, g, b, a) static AnimLineI1 __ANIMLINENAME = {  ((ANIM_CMD_SET_EXTRA_VALUE_LAST << 25) | ((param1) << 15) | n), { (r << 24) | (g << 16) | (b << 8) | a } }
#define asSetExtraBlock_1f(n, param1, r, g, b, a) {  ((ANIM_CMD_SET_EXTRA_VALUE_LAST << 25) | ((param1) << 15) | n), { (r << 24) | (g << 16) | (b << 8) | a } }

#define asSetExtra_1(n, param1, r, g, b, a) static AnimLineI1 __ANIMLINENAME = {  ((ANIM_CMD_SET_EXTRA_VALUE << 25) | ((param1) << 15) | n), { (r << 24) | (g << 16) | (b << 8) | a } }
#define asSetExtra_1f(n, param1, r, g, b, a) {  ((ANIM_CMD_SET_EXTRA_VALUE << 25) | ((param1) << 15) | n), { (r << 24) | (g << 16) | (b << 8) | a } }

#define asSetExtraAfterBlock_2(n, param1, r1, g1, b1, a1, param2, r2, g2, b2, a2) static AnimLineI2 __ANIMLINENAME = {  ((ANIM_CMD_SET_EXTRA_VALUE_AFTER_LAST << 25) | ((param1 | param2) << 15) | n), { (r1 << 24) | (g1 << 16) | (b1 << 8) | a1, (r2 << 24) | (g2 << 16) | (b2 << 8) | a2 } }

#endif
