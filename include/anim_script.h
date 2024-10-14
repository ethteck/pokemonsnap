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

typedef struct AnimLinePtr {
    u32 cmd;
    void* ptr;
} AnimLinePtr;

#define __ANIMLINENAME __CONCAT2__(animline,__LINE__)

#define POSX (1 << 0)
#define POSY (1 << 1)
#define POSZ (1 << 2)
#define ROTX (1 << 4)
#define ROTY (1 << 5)
#define ROTZ (1 << 6)
#define SCALEX (1 << 7)
#define SCALEY (1 << 8)
#define SCALEZ (1 << 9)

#define asWait(n) static AnimLine0 __ANIMLINENAME = {  ((2 << 25) | (0 << 15) | n) }
#define asWait_f(n) {  ((2 << 25) | (0 << 15) | n) }
#define asRestart(script) static AnimLinePtr __ANIMLINENAME = {  ((14 << 25) | (0 << 15) | 0), &script }
#define asEnd() static AnimLine0 __ANIMLINENAME = {  ((0 << 25) | (0 << 15) | 0) }
#define asPlaySound(duration, category, id) static AnimLine0 __ANIMLINENAME = {  ((16 << 25) | ((((category) << 8) | (id)) << 15) | duration) }
#define asPlayEffect(duration, category, id) static AnimLine0 __ANIMLINENAME = {  ((16 << 25) | ((((category) << 8) | (id + 1)) << 15) | duration) }

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

#define asSetWithRateBlock_1(n, param1, val1, rate1) static AnimLine2 __ANIMLINENAME = {  ((5 << 25) | ((param1) << 15) | n), { val1, rate1 } }
#define asSetWithRateBlock_2(n, param1, val1, rate1, param2, val2, rate2) static AnimLine4 __ANIMLINENAME = {  ((5 << 25) | ((param1 | param2) << 15) | n), { val1, rate1, val2, rate2 } }
#define asSetWithRateBlock_3(n, param1, val1, rate1, param2, val2, rate2, param3, val3, rate3) static AnimLine6 __ANIMLINENAME = {  ((5 << 25) | ((param1 | param2 | param3) << 15) | n), { val1, rate1, val2, rate2, val3, rate3 } }
#define asSetWithRateBlock_4(n, param1, val1, rate1, param2, val2, rate2, param3, val3, rate3, param4, val4, rate4) static AnimLine8 __ANIMLINENAME = {  ((5 << 25) | ((param1 | param2 | param3 | param4) << 15) | n), { val1, rate1, val2, rate2, val3, rate3, val4, rate4 } }
#define asSetWithRateBlock_5(n, param1, val1, rate1, param2, val2, rate2, param3, val3, rate3, param4, val4, rate4, param5, val5, rate5) static AnimLine10 __ANIMLINENAME = {  ((5 << 25) | ((param1 | param2 | param3 | param4 | param5) << 15) | n), { val1, rate1, val2, rate2, val3, rate3, val4, rate4, val5, rate5 } }
#define asSetWithRateBlock_6(n, param1, val1, rate1, param2, val2, rate2, param3, val3, rate3, param4, val4, rate4, param5, val5, rate5, param6, val6, rate6) static AnimLine12 __ANIMLINENAME = {  ((5 << 25) | ((param1 | param2 | param3 | param4 | param5 | param6) << 15) | n), { val1, rate1, val2, rate2, val3, rate3, val4, rate4, val5, rate5, val6, rate6 } }
#define asSetWithRateBlock_1f(n, param1, val1, rate1) {  ((5 << 25) | ((param1) << 15) | n), { val1, rate1 } }

#define asSetWithRate_1(n, param1, val1, rate1) static AnimLine2 __ANIMLINENAME = {  ((6 << 25) | ((param1) << 15) | n), { val1, rate1 } }
#define asSetWithRate_2(n, param1, val1, rate1, param2, val2, rate2) static AnimLine4 __ANIMLINENAME = {  ((6 << 25) | ((param1 | param2) << 15) | n), { val1, rate1, val2, rate2 } }
#define asSetWithRate_3(n, param1, val1, rate1, param2, val2, rate2, param3, val3, rate3) static AnimLine6 __ANIMLINENAME = {  ((6 << 25) | ((param1 | param2 | param3) << 15) | n), { val1, rate1, val2, rate2, val3, rate3 } }
#define asSetWithRate_4(n, param1, val1, rate1, param2, val2, rate2, param3, val3, rate3, param4, val4, rate4) static AnimLine8 __ANIMLINENAME = {  ((6 << 25) | ((param1 | param2 | param3 | param4) << 15) | n), { val1, rate1, val2, rate2, val3, rate3, val4, rate4 } }
#define asSetWithRate_5(n, param1, val1, rate1, param2, val2, rate2, param3, val3, rate3, param4, val4, rate4, param5, val5, rate5) static AnimLine10 __ANIMLINENAME = {  ((6 << 25) | ((param1 | param2 | param3 | param4 | param5) << 15) | n), { val1, rate1, val2, rate2, val3, rate3, val4, rate4, val5, rate5 } }
#define asSetWithRate_6(n, param1, val1, rate1, param2, val2, rate2, param3, val3, rate3, param4, val4, rate4, param5, val5, rate5, param6, val6, rate6) static AnimLine12 __ANIMLINENAME = {  ((6 << 25) | ((param1 | param2 | param3 | param4 | param5 | param6) << 15) | n), { val1, rate1, val2, rate2, val3, rate3, val4, rate4, val5, rate5, val6, rate6 } }
#define asSetWithRate_1f(n, param1, val1, rate1) {  ((6 << 25) | ((param1) << 15) | n), { val1, rate1 } }
#define asSetWithRate_2f(n, param1, val1, rate1, param2, val2, rate2) {  ((6 << 25) | ((param1 | param2) << 15) | n), { val1, rate1, val2, rate2 } }
#define asSetWithRate_3f(n, param1, val1, rate1, param2, val2, rate2, param3, val3, rate3) {  ((6 << 25) | ((param1 | param2 | param3) << 15) | n), { val1, rate1, val2, rate2, val3, rate3 } }
#define asSetWithRate_4f(n, param1, val1, rate1, param2, val2, rate2, param3, val3, rate3, param4, val4, rate4) {  ((6 << 25) | ((param1 | param2 | param3 | param4) << 15) | n), { val1, rate1, val2, rate2, val3, rate3, val4, rate4 } }
#define asSetWithRate_5f(n, param1, val1, rate1, param2, val2, rate2, param3, val3, rate3, param4, val4, rate4, param5, val5, rate5) {  ((6 << 25) | ((param1 | param2 | param3 | param4 | param5) << 15) | n), { val1, rate1, val2, rate2, val3, rate3, val4, rate4, val5, rate5 } }
#define asSetWithRate_6f(n, param1, val1, rate1, param2, val2, rate2, param3, val3, rate3, param4, val4, rate4, param5, val5, rate5, param6, val6, rate6) {  ((6 << 25) | ((param1 | param2 | param3 | param4 | param5 | param6) << 15) | n), { val1, rate1, val2, rate2, val3, rate3, val4, rate4, val5, rate5, val6, rate6 } }

#define asSetTargetRate_1(n, param1, val1) static AnimLine1 __ANIMLINENAME = {  ((7 << 25) | ((param1) << 15) | n), { val1 } }
#define asSetTargetRate_2(n, param1, val1, param2, val2) static AnimLine2 __ANIMLINENAME = {  ((7 << 25) | ((param1 | param2) << 15) | n), { val1, val2 } }
#define asSetTargetRate_3(n, param1, val1, param2, val2, param3, val3) static AnimLine3 __ANIMLINENAME = {  ((7 << 25) | ((param1 | param2 | param3) << 15) | n), { val1, val2, val3 } }
#define asSetTargetRate_5(n, param1, val1, param2, val2, param3, val3, param4, val4, param5, val5) static AnimLine5 __ANIMLINENAME = {  ((7 << 25) | ((param1 | param2 | param3 | param4 | param5) << 15) | n), { val1, val2, val3, val4, val5 } }
#define asSetTargetRate_6(n, param1, val1, param2, val2, param3, val3, param4, val4, param5, val5, param6, val6) static AnimLine6 __ANIMLINENAME = {  ((7 << 25) | ((param1 | param2 | param3 | param4 | param5 | param6) << 15) | n), { val1, val2, val3, val4, val5, val6 } }

#define asSetZeroRateBlock_1(n, param1, val1) static AnimLine1 __ANIMLINENAME = {  ((8 << 25) | ((param1) << 15) | n), { val1 } }
#define asSetZeroRateBlock_2(n, param1, val1, param2, val2) static AnimLine2 __ANIMLINENAME = {  ((8 << 25) | ((param1 | param2) << 15) | n), { val1, val2 } }
#define asSetZeroRateBlock_3(n, param1, val1, param2, val2, param3, val3) static AnimLine3 __ANIMLINENAME = {  ((8 << 25) | ((param1 | param2 | param3) << 15) | n), { val1, val2, val3 } }
#define asSetZeroRateBlock_4(n, param1, val1, param2, val2, param3, val3, param4, val4) static AnimLine4 __ANIMLINENAME = {  ((8 << 25) | ((param1 | param2 | param3 | param4) << 15) | n), { val1, val2, val3, val4 } }
#define asSetZeroRateBlock_5(n, param1, val1, param2, val2, param3, val3, param4, val4, param5, val5) static AnimLine5 __ANIMLINENAME = {  ((8 << 25) | ((param1 | param2 | param3 | param4 | param5) << 15) | n), { val1, val2, val3, val4, val5 } }
#define asSetZeroRateBlock_6(n, param1, val1, param2, val2, param3, val3, param4, val4, param5, val5, param6, val6) static AnimLine6 __ANIMLINENAME = {  ((8 << 25) | ((param1 | param2 | param3 | param4 | param5 | param6) << 15) | n), { val1, val2, val3, val4, val5, val6 } }
#define asSetZeroRateBlock_1f(n, param1, val1) {  ((8 << 25) | ((param1) << 15) | n), { val1 } }
#define asSetZeroRateBlock_6f(n, param1, val1, param2, val2, param3, val3, param4, val4, param5, val5, param6, val6) {  ((8 << 25) | ((param1 | param2 | param3 | param4 | param5 | param6) << 15) | n), { val1, val2, val3, val4, val5, val6 } }

#define asSetZeroRate_1(n, param1, val1) static AnimLine1 __ANIMLINENAME = {  ((9 << 25) | ((param1) << 15) | n), { val1 } }
#define asSetZeroRate_2(n, param1, val1, param2, val2) static AnimLine2 __ANIMLINENAME = {  ((9 << 25) | ((param1 | param2) << 15) | n), { val1, val2 } }
#define asSetZeroRate_3(n, param1, val1, param2, val2, param3, val3) static AnimLine3 __ANIMLINENAME = {  ((9 << 25) | ((param1 | param2 | param3) << 15) | n), { val1, val2, val3 } }
#define asSetZeroRate_4(n, param1, val1, param2, val2, param3, val3, param4, val4) static AnimLine4 __ANIMLINENAME = {  ((9 << 25) | ((param1 | param2 | param3 | param4) << 15) | n), { val1, val2, val3, val4 } }
#define asSetZeroRate_5(n, param1, val1, param2, val2, param3, val3, param4, val4, param5, val5) static AnimLine5 __ANIMLINENAME = {  ((9 << 25) | ((param1 | param2 | param3 | param4 | param5) << 15) | n), { val1, val2, val3, val4, val5 } }
#define asSetZeroRate_1f(n, param1, val1) {  ((9 << 25) | ((param1) << 15) | n), { val1 } }
#define asSetZeroRate_2f(n, param1, val1, param2, val2) {  ((9 << 25) | ((param1 | param2) << 15) | n), { val1, val2 } }
#define asSetZeroRate_3f(n, param1, val1, param2, val2, param3, val3) {  ((9 << 25) | ((param1 | param2 | param3) << 15) | n), { val1, val2, val3 } }
#define asSetZeroRate_4f(n, param1, val1, param2, val2, param3, val3, param4, val4) {  ((9 << 25) | ((param1 | param2 | param3 | param4) << 15) | n), { val1, val2, val3, val4 } }
#define asSetZeroRate_5f(n, param1, val1, param2, val2, param3, val3, param4, val4, param5, val5) {  ((9 << 25) | ((param1 | param2 | param3 | param4 | param5) << 15) | n), { val1, val2, val3, val4, val5 } }
#define asSetZeroRate_6f(n, param1, val1, param2, val2, param3, val3, param4, val4, param5, val5, param6, val6) {  ((9 << 25) | ((param1 | param2 | param3 | param4 | param5 | param6) << 15) | n), { val1, val2, val3, val4, val5, val6 } }
#define asSetZeroRate_7f(n, param1, val1, param2, val2, param3, val3, param4, val4, param5, val5, param6, val6, param7, val7) {  ((9 << 25) | ((param1 | param2 | param3 | param4 | param5 | param6 | param7) << 15) | n), { val1, val2, val3, val4, val5, val6, val7 } }

#define asSetAfterBlock_1(n, param1, val1) static AnimLine1 __ANIMLINENAME = {  ((10 << 25) | ((param1) << 15) | n), { val1 } }
#define asSetAfterBlock_2(n, param1, val1, param2, val2) static AnimLine2 __ANIMLINENAME = {  ((10 << 25) | ((param1 | param2) << 15) | n), { val1, val2 } }
#define asSetAfterBlock_3(n, param1, val1, param2, val2, param3, val3) static AnimLine3 __ANIMLINENAME = {  ((10 << 25) | ((param1 | param2 | param3) << 15) | n), { val1, val2, val3 } }
#define asSetAfterBlock_4(n, param1, val1, param2, val2, param3, val3, param4, val4) static AnimLine4 __ANIMLINENAME = {  ((10 << 25) | ((param1 | param2 | param3 | param4) << 15) | n), { val1, val2, val3, val4 } }
#define asSetAfterBlock_5(n, param1, val1, param2, val2, param3, val3, param4, val4, param5, val5) static AnimLine5 __ANIMLINENAME = {  ((10 << 25) | ((param1 | param2 | param3 | param4 | param5) << 15) | n), { val1, val2, val3, val4, val5 } }
#define asSetAfterBlock_6(n, param1, val1, param2, val2, param3, val3, param4, val4, param5, val5, param6, val6) static AnimLine6 __ANIMLINENAME = {  ((10 << 25) | ((param1 | param2 | param3 | param4 | param5 | param6) << 15) | n), { val1, val2, val3, val4, val5, val6 } }
#define asSetAfterBlock_7(n, param1, val1, param2, val2, param3, val3, param4, val4, param5, val5, param6, val6, param7, val7) static AnimLine7 __ANIMLINENAME = {  ((10 << 25) | ((param1 | param2 | param3 | param4 | param5 | param6 | param7) << 15) | n), { val1, val2, val3, val4, val5, val6, val7 } }
#define asSetAfterBlock_8(n, param1, val1, param2, val2, param3, val3, param4, val4, param5, val5, param6, val6, param7, val7, param8, val8) static AnimLine8 __ANIMLINENAME = {  ((10 << 25) | ((param1 | param2 | param3 | param4 | param5 | param6 | param7 | param8) << 15) | n), { val1, val2, val3, val4, val5, val6, val7, val8 } }
#define asSetAfterBlock_9(n, param1, val1, param2, val2, param3, val3, param4, val4, param5, val5, param6, val6, param7, val7, param8, val8, param9, val9) static AnimLine8 __ANIMLINENAME = {  ((10 << 25) | ((param1 | param2 | param3 | param4 | param5 | param6 | param7 | param8 | param9) << 15) | n), { val1, val2, val3, val4, val5, val6, val7, val8, val9 } }
#define asSetAfterBlock_3f(n, param1, val1, param2, val2, param3, val3) {  ((10 << 25) | ((param1 | param2 | param3) << 15) | n), { val1, val2, val3 } }
#define asSetAfterBlock_6f(n, param1, val1, param2, val2, param3, val3, param4, val4, param5, val5, param6, val6) {  ((10 << 25) | ((param1 | param2 | param3 | param4 | param5 | param6) << 15) | n), { val1, val2, val3, val4, val5, val6 } }

#define asSetAfter_3(n, param1, val1, param2, val2, param3, val3) static AnimLine3 __ANIMLINENAME = {  ((11 << 25) | ((param1 | param2 | param3) << 15) | n), { val1, val2, val3 } }
#define asSetAfter_3f(n, param1, val1, param2, val2, param3, val3) {  ((11 << 25) | ((param1 | param2 | param3) << 15) | n), { val1, val2, val3 } }
#define asSetAfter_9f(n, param1, val1, param2, val2, param3, val3, param4, val4, param5, val5, param6, val6, param7, val7, param8, val8, param9, val9) {  ((11 << 25) | ((param1 | param2 | param3 | param4 | param5 | param6 | param7 | param8 | param9) << 15) | n), { val1, val2, val3, val4, val5, val6, val7, val8, val9} }

#define asSkip_1(n, param1) static AnimLine0 __ANIMLINENAME = {  ((12 << 25) | ((param1) << 15) | n) }
#define asSkip_2(n, param1, param2) static AnimLine0 __ANIMLINENAME = {  ((12 << 25) | ((param1 | param2) << 15) | n) }

#endif
