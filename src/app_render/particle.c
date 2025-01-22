#include "app_render.h"
#include "particle.h"

extern u8 fx_colorDitherMode;
extern u8 fx_alphaDitherMode;
extern u16 fx_currentEffectID;

Particle* D_800BE1A0;
Particle* D_800BE1A8[16];
Effect* D_800BE1E8;
Effect* D_800BE1EC;
OMCamera* D_800BE1F0[4];
u8 D_800BE200[4];
DObj* D_800BE208[8];
s32 fx_ScriptBanksNum[PARTICLE_BANKS_MAX];
s32 fx_SpriteBanksNum[PARTICLE_BANKS_MAX];
EffectScript** fx_ScriptBanks[PARTICLE_BANKS_MAX];
EffectSprites** fx_SpriteBanks[PARTICLE_BANKS_MAX];
void (*fx_effectProcDefault)(Effect*, Vec3f*);
void (*fx_effectProcSetup)(Effect*);
Effect* D_800BE2B0;

Particle* fx_updateStruct(Particle*, Particle*, s32);
void fx_structFuncRun(GObj*);
void fx_draw(GObj*);
void fx_effectFuncRun(GObj*);

void fx_setupBankID(s32 bankID, s32* scriptDesc, s32* spritesDesc) { // TODO structs for these
    s32 i, j;

    if (bankID >= PARTICLE_BANKS_MAX) {
        return;
    }

    fx_ScriptBanksNum[bankID] = *scriptDesc;
    fx_SpriteBanksNum[bankID] = *spritesDesc;
    fx_ScriptBanks[bankID] = scriptDesc + 1;
    fx_SpriteBanks[bankID] = spritesDesc + 1;

    for (i = 1; i <= fx_ScriptBanksNum[bankID]; i++) {
        scriptDesc[i] = (u32) (scriptDesc) + scriptDesc[i];
    }
    for (i = 1; i <= fx_SpriteBanksNum[bankID]; i++) {
        spritesDesc[i] = (u32) (spritesDesc) + spritesDesc[i];
    }

    for (i = 0; i < fx_SpriteBanksNum[bankID]; i++) {
        for (j = 0; j < fx_SpriteBanks[bankID][i]->numFrames; j++) {
            fx_SpriteBanks[bankID][i]->data[j] += (u32) spritesDesc;
        }

        if (fx_SpriteBanks[bankID][i]->fmt == G_IM_FMT_CI) {
            if (fx_SpriteBanks[bankID][i]->flags & 1) {
                j = fx_SpriteBanks[bankID][i]->numFrames;
                fx_SpriteBanks[bankID][i]->data[j] += (u32) spritesDesc;
            } else {
                for (j = fx_SpriteBanks[bankID][i]->numFrames; j < 2 * fx_SpriteBanks[bankID][i]->numFrames; j++) {
                    fx_SpriteBanks[bankID][i]->data[j] += (u32) spritesDesc;
                }
            }
        }
    }
}

GObj* func_800A2094(s32 dlPriority, s32 arg1, OMCamera* arg2) {
    s32 i;
    Particle* temp;

    D_800BE1F0[0] = arg2;
    D_800BE200[0] = 1;
    for (i = 1; i < 4; i++) {
        D_800BE1F0[i] = 0;
    }

    D_800BE1A0 = NULL;
    for (i = 0; i < 16; i++) {
        D_800BE1A8[i] = NULL;
    }

    i = arg1 - 1;
    while (i >= 0) {
        temp = gtlMalloc(sizeof(Particle), 4);
        if (temp == NULL) {
            return NULL;
        }
        i--;
        temp->next = D_800BE1A0;
        D_800BE1A0 = temp;
    }

    if (ohFindById(-6) != NULL) {
        return NULL;
    } else {
        return ohCreateCamera(-6, fx_structFuncRun, LINK_0, 0x80000000, fx_draw, dlPriority, 0, 0, false, 1, NULL, 1, false);
    }
}

void func_800A21C0(s32 idx, OMCamera* cam, s32 arg2) {
    D_800BE1F0[idx] = cam;
    D_800BE200[idx] = arg2;
}

Particle* fx_createParticle(
    Particle* arg0, s32 bankID, s32 flags, u16 textureID, u8* bytecode, s32 lifetime,
    f32 posX, f32 posY, f32 posZ, f32 velX, f32 velY, f32 velZ,
    f32 size, f32 gravity, f32 friction, s32 argF, Effect* fx) {

    Particle* ret = D_800BE1A0;

    if (ret == NULL) {
        return NULL;
    }

    if (fx != NULL) {
        ret->effectID = fx->effectID;
    } else {
        ret->effectID = ++fx_currentEffectID;
    }

    D_800BE1A0 = ret->next;

    if (arg0 == NULL) {
        ret->next = D_800BE1A8[bankID >> 3];
        D_800BE1A8[bankID >> 3] = ret;
    } else {
        ret->next = arg0->next;
        arg0->next = ret;
    }

    ret->bankID = bankID;
    ret->flags = flags;
    ret->textureID = textureID;

    ret->pos.x = posX;
    ret->pos.y = posY;
    ret->pos.z = posZ;

    ret->vel.x = velX;
    ret->vel.y = velY;
    ret->vel.z = velZ;

    ret->size = size;
    ret->gravity = gravity;
    ret->friction = friction;

    ret->lifetime = lifetime + 1;
    ret->bytecode = bytecode;
    ret->bytecodePos = ret->returnPtr = 0;

    if (argF) {
        ret->flags |= 0x10;
    }

    if (bytecode != NULL) {
        ret->bytecodeTimer = true;
    } else {
        ret->bytecodeTimer = false;
    }

    ret->dataID = 0;

    ret->primColor.r = ret->primColor.g = ret->primColor.b = ret->primColor.a = 0xFF;
    ret->envColor.r = ret->envColor.g = ret->envColor.b = ret->envColor.a = 0;

    ret->sizeTargetLength = ret->targetPrimColorLength = ret->targetEnvColorLength = 0;
    ret->fx = fx;
    return ret;
}

Particle* fx_makeChildScriptID(Particle* particle, s32 bankID, s32 scriptID) {
    EffectScript* script;
    s32 id = bankID & 7; // TODO mod 8?

    if (id >= PARTICLE_BANKS_MAX) {
        return NULL;
    }
    if (scriptID >= fx_ScriptBanksNum[id]) {
        return NULL;
    }
    script = fx_ScriptBanks[id][scriptID];

    return fx_createParticle(particle, bankID, script->flags, script->textureID, script->bytecode, script->particleLifetime,
                             0.0f, 0.0f, 0.0f, script->vel.x, script->vel.y, script->vel.z, script->size, script->gravity,
                             script->friction, fx_SpriteBanks[id][script->textureID]->flags, NULL);
}

Particle* fx_makeParam(s32 bankID, s32 flags, u16 textureID, u8* bytecode, s32 lifetime,
                       f32 posX, f32 posY, f32 posZ, f32 velX, f32 velY, f32 velZ,
                       f32 size, f32 gravity, f32 friction, s32 argE, Effect* fx) {
    Particle* ret;

    ret = fx_createParticle(NULL, bankID, flags, textureID, bytecode, lifetime,
                            posX, posY, posZ, velX,
                            velY, velZ, size,
                            gravity, friction, argE, fx);
    if (ret != NULL) {
        fx_updateStruct(ret, 0, bankID >> 3);
    }
    return ret;
}

Particle* fx_makeCommon(s32 bankID, s32 scriptID) {
    Particle* ret;

    ret = fx_makeChildScriptID(NULL, bankID, scriptID);
    if (ret != NULL) {
        fx_updateStruct(ret, 0, bankID >> 3);
    }
    return ret;
}

Particle* fx_makePosVel(s32 bankID, s32 scriptID, f32 posX, f32 posY, f32 posZ, f32 velX, f32 velY, f32 velZ) {
    Particle* ret;
    EffectScript* script;
    s32 id = bankID & 7;

    if (id >= PARTICLE_BANKS_MAX) {
        return NULL;
    }
    if (scriptID >= fx_ScriptBanksNum[id]) {
        return NULL;
    }

    script = fx_ScriptBanks[id][scriptID];

    ret = fx_createParticle(NULL, bankID, script->flags, script->textureID, script->bytecode, script->particleLifetime,
                            posX, posY, posZ, velX, velY, velZ, script->size, script->gravity,
                            script->friction, fx_SpriteBanks[id][script->textureID]->flags, NULL);
    if (ret != NULL) {
        fx_updateStruct(ret, 0, bankID >> 3);
    }
    return ret;
}

void fx_ejectStruct(Particle* particle) {
    Particle* it;
    Particle* prev;
    s32 id = particle->bankID >> 3;

    prev = NULL;
    for (it = D_800BE1A8[id]; it != NULL; it = it->next) {
        if (it == particle) {
            if (prev == NULL) {
                D_800BE1A8[id] = it->next;
            } else {
                prev->next = it->next;
            }

            if (particle->fx != NULL && (particle->flags & 4) && particle->fx->kind == 2) {
                particle->fx->effectVars.data2.unk_04--;
            }

            it->next = D_800BE1A0;
            D_800BE1A0 = it;
            return;
        }
        prev = it;
    }
}

void fx_ejectStructAll(void) {
    s32 i;
    Particle* it;
    Particle* next;

    for (i = 0; i < ARRAY_COUNT(D_800BE1A8); i++) {
        for (it = D_800BE1A8[i]; it != NULL; it = next) {
            next = it->next;
            fx_ejectStruct(it);
        }
    }
}

// fx_readFloatBigEndian
u8* func_800A27B0(u8* arg0, f32* arg1) {
    u8 sp4[4];

    sp4[0] = *arg0++;
    sp4[1] = *arg0++;
    sp4[2] = *arg0++;
    sp4[3] = *arg0++;
    *arg1 = *(f32*) sp4;
    return arg0;
}

u8* func_800A27E8(u8* arg0, u16* arg1) {
    u16 value;

    value = *arg0++;
    if (value & 0x80) {
        value = ((value & 0x7F) << 8) + *arg0++;
    }
    *arg1 = value + 1;
    return arg0;
}

void fx_rotateVel(Particle* particle, f32 angle) {
    Vec3f vel;
    f32 sinAngle;
    f32 magnitude;
    f32 pitch;
    f32 yaw;
    f32 sinPitch, cosPitch;
    f32 sinYaw, cosYaw;
    f32 cosAngle;
    f32 t;

    vel.x = particle->vel.x;
    vel.y = particle->vel.y;
    vel.z = particle->vel.z;

    pitch = atan2f(vel.y, vel.z);
    sinPitch = sinf(pitch);
    cosPitch = cosf(pitch);

    yaw = atan2f(vel.x, vel.y * sinPitch + vel.z * cosPitch);
    sinYaw = sinf(yaw);
    cosYaw = cosf(yaw);

    magnitude = sqrtf(SQ(vel.x) + SQ(vel.y) + SQ(vel.z));

    t = randFloat() * TAU;

    sinAngle = sinf(angle) * magnitude;

    vel.x = cosf(t) * sinAngle;
    vel.y = sinf(t) * sinAngle;
    vel.z = sinAngle;

    cosAngle = cosf(angle) * magnitude;

    particle->vel.x = vel.x * cosYaw + cosAngle * sinYaw;
    particle->vel.y = -vel.x * sinPitch * sinYaw + vel.y * cosPitch + cosAngle * sinPitch * cosYaw;
    particle->vel.z = -vel.x * cosPitch * sinYaw - vel.y * sinPitch + cosAngle * cosPitch * cosYaw;
}

void fx_setDistVelDObj(Particle* particle, DObj* dobj) {
    f32 dx, dy, dz;
    f32 dist;

    if (dobj == NULL) {
        return;
    }

    dx = dobj->position.v.x - particle->pos.x;
    dy = dobj->position.v.y - particle->pos.y;
    dz = dobj->position.v.z - particle->pos.z;

    dist = sqrtf(SQ(particle->vel.x) + SQ(particle->vel.y) + SQ(particle->vel.z));

    if (SQ(dx) + SQ(dy) + SQ(dz) != 0.0f) {
        dist /= sqrtf(SQ(dx) + SQ(dy) + SQ(dz));
        particle->vel.x = dx * dist;
        particle->vel.y = dy * dist;
        particle->vel.z = dz * dist;
    }
}

void fx_addDistVelMagDObj(Particle* particle, DObj* dobj, f32 magnitude) {
    f32 dx, dy, dz, dist;

    if (dobj == NULL) {
        return;
    }

    dx = dobj->position.v.x - particle->pos.x;
    dy = dobj->position.v.y - particle->pos.y;
    dz = dobj->position.v.z - particle->pos.z;

    dist = SQ(dx) + SQ(dy) + SQ(dz);
    if (dist != 0.0f) {
        dist = magnitude / dist;
        particle->vel.x += dist * dx;
        particle->vel.y += dist * dy;
        particle->vel.z += dist * dz;
    }
}

#if 0
extern u16 sSinTable[];
#define INTERP(a, b, c) a = ((a << 0x10) + (b - a) * (0x10000 / c)) >> 0x10;
#define SINCOS(inAngle, sinVal, cosVal)                  \
    {                                                    \
        u16 angle = (s32) (inAngle * 651.8986f) & 0xFFF; \
        sinVal = sSinTable[angle & 2047];                \
        if (angle & 0x800) {                             \
            sinVal = -sinVal;                            \
        }                                                \
        angle += 0x400;                                  \
        cosVal = sSinTable[angle & 2047];                \
        if (angle & 0x800) {                             \
            cosVal = -cosVal;                            \
        }                                                \
    }

Particle* fx_updateStruct(Particle* arg0, Particle* arg1, s32 arg2) {
    UnkPinkRat* pinkRat;
    Particle* temp_v0;
    s32 unused1;
    u8* var_s1;
    u16 unused2;
    u16 sp94;
    f32 var_f18;
    f32 var_f2;
    s32 sp88;
    s32 temp_s0;
    f32 sp80;
    f32 sp7C;
    f32 unused3;
    f32 nv;
    f32 sp70;
    f32 temp_f16_3;
    f32 temp_f2_2;
    f32 unused4;
    Particle* next;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    u8 var_v1;
    u8 temp_a0;
    f32 sp44;

    if (arg0->flags & 0x800) {
        return arg0->next;
    }

    if (arg0->unk_0C != 0) {
        if (--arg0->unk_0C == 0) {
            var_s1 = &arg0->scriptPtr[arg0->unk_18];
            while (true) {
                temp_a0 = *var_s1++;
                if (temp_a0 >= 0x80) {
                    sp94 = 0;
                    var_v1 = temp_a0 & 0xF8;
                    if (var_v1 >= 0x99) {
                        var_v1 = temp_a0 & 0xF0;
                        if (var_v1 != 0xC0 && var_v1 != 0xD0) {
                            var_v1 = temp_a0;
                        }
                    }
                    switch (var_v1) {
                        case 0x80:
                            if (temp_a0 & 1) {
                                var_s1 = func_800A27B0(var_s1, &arg0->unk_20.x);
                            }
                            if (temp_a0 & 2) {
                                var_s1 = func_800A27B0(var_s1, &arg0->unk_20.y);
                            }
                            if (temp_a0 & 4) {
                                var_s1 = func_800A27B0(var_s1, &arg0->unk_20.z);
                            }
                            break;
                        case 0x88:
                            if (temp_a0 & 1) {
                                var_s1 = func_800A27B0(var_s1, &sp80);
                                arg0->unk_20.x += sp80;
                            }
                            if (temp_a0 & 2) {
                                var_s1 = func_800A27B0(var_s1, &sp80);
                                arg0->unk_20.y += sp80;
                            }
                            if (temp_a0 & 4) {
                                var_s1 = func_800A27B0(var_s1, &sp80);
                                arg0->unk_20.z += sp80;
                            }
                            break;
                        case 0x90:
                            if (temp_a0 & 1) {
                                var_s1 = func_800A27B0(var_s1, &arg0->unk_2C.x);
                            }
                            if (temp_a0 & 2) {
                                var_s1 = func_800A27B0(var_s1, &arg0->unk_2C.y);
                            }
                            if (temp_a0 & 4) {
                                var_s1 = func_800A27B0(var_s1, &arg0->unk_2C.z);
                            }
                            break;
                        case 0x98:
                            if (temp_a0 & 1) {
                                var_s1 = func_800A27B0(var_s1, &sp80);
                                arg0->unk_2C.x += sp80;
                            }
                            if (temp_a0 & 2) {
                                var_s1 = func_800A27B0(var_s1, &sp80);
                                arg0->unk_2C.y += sp80;
                            }
                            if (temp_a0 & 4) {
                                var_s1 = func_800A27B0(var_s1, &sp80);
                                arg0->unk_2C.z += sp80;
                            }
                            break;
                        case 0xA0:
                            var_s1 = func_800A27B0(func_800A27E8(var_s1, &arg0->unk_0E), &arg0->unk_44);
                            if (arg0->unk_0E == 1) {
                                arg0->unk_0E = 0;
                                arg0->unk_40 = arg0->unk_44;
                            }
                            break;
                        case 0xA1:
                            arg0->flags = *var_s1++;
                            break;
                        case 0xA2:
                            var_s1 = func_800A27B0(var_s1, &arg0->unk_38);
                            if (arg0->unk_38 == 0.0f) {
                                arg0->flags &= ~1;
                            } else {
                                arg0->flags |= 1;
                            }
                            break;
                        case 0xA3:
                            var_s1 = func_800A27B0(var_s1, &arg0->unk_3C);
                            if (arg0->unk_3C == 1.0f) {
                                arg0->flags &= ~2;
                            } else {
                                arg0->flags |= 2;
                            }
                            break;
                        case 0xA4:
                            temp_s0 = *var_s1++;
                            temp_s0 <<= 8;
                            temp_s0 += *var_s1++;
                            temp_v0 = fx_makeChildScriptID(&arg0->next, arg0->unk_08, temp_s0);
                            if (temp_v0 != NULL) {
                                temp_v0->unk_20.x = arg0->unk_20.x;
                                temp_v0->unk_20.y = arg0->unk_20.y;
                                temp_v0->unk_20.z = arg0->unk_20.z;
                                temp_v0->unk_04 = arg0->unk_04;
                                temp_v0->unk_58 = arg0->unk_58;
                                fx_updateStruct(temp_v0, arg0, (s32) arg0->unk_08 >> 3);
                            }
                            break;
                        case 0xA5:
                            temp_s0 = *var_s1++;
                            temp_s0 <<= 8;
                            temp_s0 += *var_s1++;
                            pinkRat = fx_createEffect(arg0->unk_08, temp_s0);
                            if (pinkRat != NULL) {
                                pinkRat->unk_14.x = arg0->unk_20.x;
                                pinkRat->unk_14.y = arg0->unk_20.y;
                                pinkRat->unk_14.z = arg0->unk_20.z;
                                pinkRat->unk_04 = arg0->unk_04;
                            }
                            break;
                        case 0xA6:
                            temp_s0 = *var_s1++;
                            temp_s0 <<= 8;
                            temp_s0 += *var_s1++;
                            sp88 = *var_s1++;
                            sp88 <<= 8;
                            sp88 += *var_s1++;
                            arg0->unk_1E = temp_s0 + (s32) (randFloat() * sp88);
                            break;
                        case 0xA7:
                            temp_s0 = *var_s1++;
                            if (temp_s0 >= (s32) (randFloat() * 100.0f)) {
                                arg0->unk_1E = 1;
                                goto EXIT;
                            }
                            break;
                        case 0xA8:
                            var_s1 = func_800A27B0(var_s1, &sp80);
                            arg0->unk_20.x += sp80 * randFloat();
                            var_s1 = func_800A27B0(var_s1, &sp80);
                            arg0->unk_20.y += sp80 * randFloat();
                            var_s1 = func_800A27B0(var_s1, &sp80);
                            arg0->unk_20.z += sp80 * randFloat();
                            break;
                        case 0xA9:
                            var_s1 = func_800A27B0(var_s1, &sp80);
                            fx_rotateVel(arg0, sp80);
                            break;
                        case 0xAA:
                            temp_s0 = *var_s1++;
                            temp_s0 <<= 8;
                            temp_s0 += *var_s1++;
                            sp88 = *var_s1++;
                            sp88 <<= 8;
                            sp88 += *var_s1++;
                            temp_s0 += (s32) (sp88 * randFloat());
                            temp_v0 = fx_makeChildScriptID(&arg0->next, arg0->unk_08, temp_s0);
                            if (temp_v0 != NULL) {
                                temp_v0->unk_20.x = arg0->unk_20.x;
                                temp_v0->unk_20.y = arg0->unk_20.y;
                                temp_v0->unk_20.z = arg0->unk_20.z;
                                temp_v0->unk_04 = arg0->unk_04;
                                temp_v0->unk_58 = arg0->unk_58;
                                fx_updateStruct(temp_v0, arg0, (s32) arg0->unk_08 >> 3);
                            }
                            break;
                        case 0xAB:
                            var_s1 = func_800A27B0(var_s1, &sp80);
                            arg0->unk_2C.x *= sp80;
                            arg0->unk_2C.y *= sp80;
                            arg0->unk_2C.z *= sp80;
                            break;
                        case 0xAC:
                            var_s1 = func_800A27B0(func_800A27B0(func_800A27E8(var_s1, &arg0->unk_0E), &arg0->unk_44), &sp80);
                            arg0->unk_44 += sp80 * randFloat();
                            if (arg0->unk_0E == 1) {
                                arg0->unk_0E = 0;
                                arg0->unk_40 = arg0->unk_44;
                            }
                            break;
                        case 0xAD:
                            arg0->flags |= 0x80;
                            break;
                        case 0xAE:
                            arg0->flags &= ~0x60;
                            break;
                        case 0xAF:
                            arg0->flags &= ~0x40;
                            arg0->flags |= 0x20;
                            break;
                        case 0xB0:
                            arg0->flags &= ~0x20;
                            arg0->flags |= 0x40;
                            break;
                        case 0xB1:
                            arg0->flags |= 0x60;
                            break;
                        case 0xB2:
                            arg0->flags |= 0x200;
                            break;
                        case 0xB3:
                            arg0->flags &= ~0x400;
                            break;
                        case 0xB4:
                            arg0->flags |= 0x400;
                            break;
                        case 0xB5:
                            arg0->flags |= 0x100;
                            break;
                        case 0xB6:
                            arg0->flags &= ~0x100;
                            break;
                        case 0xB7:
                            temp_s0 = *var_s1++;
                            fx_setDistVelDObj(arg0, D_800BE204[temp_s0 - 1]);
                            break;
                        case 0xB8:
                            temp_s0 = *var_s1++;
                            var_s1 = func_800A27B0(var_s1, &sp80);
                            fx_addDistVelMagDObj(arg0, D_800BE204[temp_s0 - 1], sp80);
                            break;
                        case 0xB9:
                            temp_s0 = *var_s1++;
                            temp_s0 <<= 8;
                            temp_s0 += *var_s1++;
                            temp_v0 = fx_makeChildScriptID(&arg0->next, arg0->unk_08, temp_s0);
                            if (temp_v0 != NULL) {
                                temp_v0->unk_20.x = arg0->unk_20.x;
                                temp_v0->unk_20.y = arg0->unk_20.y;
                                temp_v0->unk_20.z = arg0->unk_20.z;
                                temp_v0->unk_2C.x = arg0->unk_2C.x;
                                temp_v0->unk_2C.y = arg0->unk_2C.y;
                                temp_v0->unk_2C.z = arg0->unk_2C.z;
                                temp_v0->unk_04 = arg0->unk_04;
                                temp_v0->unk_58 = arg0->unk_58;
                                fx_updateStruct(temp_v0, arg0, arg0->unk_08 >> 3);
                            }
                            break;
                        case 0xBA:
                            sp80 = *var_s1++;
                            arg0->unk_4C.r += sp80 * randFloat();
                            sp80 = *var_s1++;
                            arg0->unk_4C.g += sp80 * randFloat();
                            sp80 = *var_s1++;
                            arg0->unk_4C.b += sp80 * randFloat();
                            sp80 = *var_s1++;
                            arg0->unk_4C.a += sp80 * randFloat();

                            if (arg0->unk_10 == 0) {
                                arg0->unk_48 = arg0->unk_4C;
                            }
                            break;
                        case 0xBB:
                            sp80 = *var_s1++;
                            arg0->unk_54.r += sp80 * randFloat();
                            sp80 = *var_s1++;
                            arg0->unk_54.g += sp80 * randFloat();
                            sp80 = *var_s1++;
                            arg0->unk_54.b += sp80 * randFloat();
                            sp80 = *var_s1++;
                            arg0->unk_54.a += sp80 * randFloat();
                            if (arg0->unk_12 == 0) {
                                arg0->unk_50 = arg0->unk_54;
                            }
                            break;
                        case 0xBC:
                            arg0->unk_0B = *var_s1++;
                            sp80 = *var_s1++;
                            arg0->unk_0B += sp80 * randFloat();
                            break;
                        case 0xBD:
                            var_s1 = func_800A27B0(var_s1, &sp80);
                            var_s1 = func_800A27B0(var_s1, &sp7C);
                            sp80 += sp7C * randFloat();
                            sp7C = sqrtf(SQ(arg0->unk_2C.x) + SQ(arg0->unk_2C.y) + SQ(arg0->unk_2C.z));
                            sp80 /= sp7C;
                            arg0->unk_2C.x *= sp80;
                            arg0->unk_2C.y *= sp80;
                            arg0->unk_2C.z *= sp80;
                            break;
                        case 0xBE:
                            var_s1 = func_800A27B0(var_s1, &sp80);
                            arg0->unk_2C.x *= sp80;
                            var_s1 = func_800A27B0(var_s1, &sp80);
                            arg0->unk_2C.y *= sp80;
                            var_s1 = func_800A27B0(var_s1, &sp80);
                            arg0->unk_2C.z *= sp80;
                            break;
                        case 0xBF:
                            temp_s0 = *var_s1++ - 1;
                            arg0->flags = arg0->flags | 0x8000 | (temp_s0 << 0xC);
                            break;
                        case 0xC0:
                            var_s1 = func_800A27E8(var_s1, &arg0->unk_10);
                            arg0->unk_4C = arg0->unk_48;
                            if (temp_a0 & 1) {
                                arg0->unk_4C.r = *var_s1++;
                            }
                            if (temp_a0 & 2) {
                                arg0->unk_4C.g = *var_s1++;
                            }
                            if (temp_a0 & 4) {
                                arg0->unk_4C.b = *var_s1++;
                            }
                            if (temp_a0 & 8) {
                                arg0->unk_4C.a = *var_s1++;
                            }
                            if (arg0->unk_10 == 1) {
                                arg0->unk_48 = arg0->unk_4C;
                                arg0->unk_10 = 0;
                            }
                            break;
                        case 0xD0:
                            var_s1 = func_800A27E8(var_s1, &arg0->unk_12);
                            arg0->unk_54 = arg0->unk_50;
                            if (temp_a0 & 1) {
                                arg0->unk_54.r = *var_s1++;
                            }
                            if (temp_a0 & 2) {
                                arg0->unk_54.g = *var_s1++;
                            }
                            if (temp_a0 & 4) {
                                arg0->unk_54.b = *var_s1++;
                            }
                            if (temp_a0 & 8) {
                                arg0->unk_54.a = *var_s1++;
                            }
                            if (arg0->unk_12 == 1) {
                                arg0->unk_50 = arg0->unk_54;
                                arg0->unk_12 = 0;
                            }
                            break;
                        case 0xFA:
                            arg0->unk_09 = *var_s1++;
                            arg0->unk_1C = var_s1 - arg0->scriptPtr;
                            break;
                        case 0xFB:
                            if (--arg0->unk_09 != 0) {
                                var_s1 = &arg0->scriptPtr[arg0->unk_1C];
                            }
                            break;
                        case 0xFC:
                            arg0->unk_1A = var_s1 - arg0->scriptPtr;
                            break;
                        case 0xFD:
                            var_s1 = &arg0->scriptPtr[arg0->unk_1A];
                            break;
                        case 0xFE:
                        case 0xFF:
                            arg0->unk_1E = 1;
                            goto EXIT;
                    }
                } else {
                    sp94 = temp_a0 & 0x1F;
                    if (temp_a0 & 0x20) {
                        sp94 = (*var_s1++) + (sp94 << 8);
                    }
                    if ((temp_a0 & 0xC0) && ((temp_a0 & 0xC0) == 0x40)) {
                        arg0->unk_0B = *var_s1++;
                    }
                }
                if (sp94 != 0) {
                EXIT:
                    arg0->unk_18 = var_s1 - arg0->scriptPtr;
                    arg0->unk_0C = sp94;
                    break;
                }
            }
        }
    }

    if (arg0->unk_0E != 0) {
        arg0->unk_40 += (arg0->unk_44 - arg0->unk_40) / arg0->unk_0E;
        arg0->unk_0E--;
    }

    if (arg0->unk_10 != 0) {
        INTERP(arg0->unk_48.r, arg0->unk_4C.r, arg0->unk_10);
        INTERP(arg0->unk_48.g, arg0->unk_4C.g, arg0->unk_10);
        INTERP(arg0->unk_48.b, arg0->unk_4C.b, arg0->unk_10);
        INTERP(arg0->unk_48.a, arg0->unk_4C.a, arg0->unk_10);
        arg0->unk_10 = arg0->unk_10 - 1;
    }

    if (arg0->unk_12 != 0) {
        INTERP(arg0->unk_50.r, arg0->unk_54.r, arg0->unk_12);
        INTERP(arg0->unk_50.g, arg0->unk_54.g, arg0->unk_12);
        INTERP(arg0->unk_50.b, arg0->unk_54.b, arg0->unk_12);
        INTERP(arg0->unk_50.a, arg0->unk_54.a, arg0->unk_12);
        arg0->unk_12 = arg0->unk_12 - 1;
    }

    if (--arg0->unk_1E == 0) {
        if (arg1 == NULL) {
            D_800BE1A8[arg2] = arg0->next;
        } else {
            arg1->next = arg0->next;
        }
        next = arg0->next;
        if ((arg0->unk_58 != NULL) && (arg0->flags & 4) && (arg0->unk_58->unk_08 == 2)) {
            arg0->unk_58->unk_4C.data2.unk_04--;
        }

        arg0->next = D_800BE1A0;
        D_800BE1A0 = arg0;
        return next;
    }

    if (arg0->flags & 4) {
        pinkRat = arg0->unk_58;

        SINCOS(arg0->unk_38, sp5C, sp54);
        SINCOS(arg0->unk_3C, sp58, sp50);

        sp5C *= 1.0f / 0x8000;
        sp54 *= 1.0f / 0x8000;
        sp58 *= 1.0f / 0x8000;
        sp50 *= 1.0f / 0x8000;

        arg0->unk_2C.z += pinkRat->unk_4C.data1.x;

        sp70 = ABS(pinkRat->unk_38);
        var_f2 = ABS(pinkRat->unk_3C);

        SINCOS(var_f2, var_f18, sp44);

        sp70 += arg0->unk_2C.z * (var_f18 / sp44);
        sp70 *= arg0->unk_2C.y;
        arg0->unk_2C.x += pinkRat->unk_2C;

        SINCOS(arg0->unk_2C.x, var_f18, sp44);

        sp70 *= 1.0f / 0x8000;
        temp_f2_2 = sp70 * sp44;
        temp_f2_2 = temp_f2_2 + temp_f2_2;
        nv = sp70 * var_f18;

        arg0->unk_20.x = temp_f2_2 * sp50 + arg0->unk_2C.z * sp58 + pinkRat->unk_14.x;
        arg0->unk_20.y = -temp_f2_2 * sp5C * sp58 + nv * sp54 + arg0->unk_2C.z * sp5C * sp50 + pinkRat->unk_14.y;
        arg0->unk_20.z = -temp_f2_2 * sp54 * sp58 - nv * sp5C + arg0->unk_2C.z * sp54 * sp50 + pinkRat->unk_14.z;
    } else {
        if (arg0->flags & 1) {
            arg0->unk_2C.y -= arg0->unk_38;
        }
        if (arg0->flags & 2) {
            arg0->unk_2C.x *= arg0->unk_3C;
            arg0->unk_2C.y *= arg0->unk_3C;
            arg0->unk_2C.z *= arg0->unk_3C;
        }
        arg0->unk_20.x += arg0->unk_2C.x;
        arg0->unk_20.y += arg0->unk_2C.y;
        arg0->unk_20.z += arg0->unk_2C.z;
    }
    if (arg0->flags & 0x8000) {
        temp_s0 = (arg0->flags & 0x7000) >> 12;
        if (D_800BE204[temp_s0] != NULL) {
            D_800BE204[temp_s0]->unk_1C.x = arg0->unk_20.x;
            D_800BE204[temp_s0]->unk_1C.y = arg0->unk_20.y;
            D_800BE204[temp_s0]->unk_1C.z = arg0->unk_20.z;
        }
    }
    return arg0->next;
}
#else
Particle* fx_updateStruct(Particle* arg0, Particle* arg1, s32 arg2);
#pragma GLOBAL_ASM("asm/nonmatchings/app_render/particle/fx_updateStruct.s")
#endif

void fx_structFuncRun(GObj* obj) {
    u32 flags = obj->flags;
    s32 i;
    Particle* prev;
    Particle* it;
    Particle* next;

    for (i = 0; i < 16; i++, flags >>= 1) {
        if (flags & 0x10000) {
            continue;
        }

        prev = NULL;
        it = D_800BE1A8[i];
        while (it != NULL) {
            next = fx_updateStruct(it, prev, i);
            if (it->next == next) {
                prev = it;
                it = next;
            } else {
                it = next;
            }
        }
    }
}

#if 0
void fx_draw(GObj* camObj) {
    Particle* var_s7;
    ParticleAnimData* v0;
    s32 sp2D4;
    s32 sp2D0;
    s32 sp2CC;
    s32 sp2C8;
    Mtx4f sp288;
    Mtx4f sp248;
    f32 var_f24;
    f32 var_f16;
    f32 var_f26;
    f32 var_f18;
    f32 temp_f12;
    f32 temp_f14;
    f32 temp_f28;

    f32 temp_f0;
    f32 temp_f22;
    f32 sp220;
    f32 sp21C;
    f32 sp218;
    f32 sp214;
    f32 sp210;
    f32 sp20C;
    f32 sp208;
    f32 sp204;
    s32 sp200;
    s32 sp1FC;
    s32 sp1F8;
    s32 sp1F4;
    s32 sp1C8;
    s32 sp1C4;

    s32 j;
    s32 var_s2;

    s32 temp_fp;
    s32 temp_t4;
    s32 temp_s3;
    s32 temp_s5;
    s32 var_s6;
    s32 var_s1;
    s32 var_t2;
    s32 var_a1_2;
    s32 var_a0;

    f32 temp_f20;
    f32 temp_f2;

    for (sp1F8 = 0; sp1F8 < 4; sp1F8++) {
        var_s2 = 0;

        if (D_800BE1F0[sp1F8] == NULL) {
            continue;
        }

        hal_look_at_roll_f(sp288, D_800BE1F0[sp1F8]->viewMtx.lookAtRoll.xEye,
                           D_800BE1F0[sp1F8]->viewMtx.lookAtRoll.yEye,
                           D_800BE1F0[sp1F8]->viewMtx.lookAtRoll.zEye,
                           D_800BE1F0[sp1F8]->viewMtx.lookAtRoll.xAt,
                           D_800BE1F0[sp1F8]->viewMtx.lookAtRoll.yAt,
                           D_800BE1F0[sp1F8]->viewMtx.lookAtRoll.zAt,
                           D_800BE1F0[sp1F8]->viewMtx.lookAtRoll.roll,
                           0.0f, 1.0f, 0.0f);
        hal_perspective_fast_f(sp248, NULL,
                               D_800BE1F0[sp1F8]->perspMtx.persp.fovy,
                               D_800BE1F0[sp1F8]->perspMtx.persp.aspect,
                               D_800BE1F0[sp1F8]->perspMtx.persp.near,
                               D_800BE1F0[sp1F8]->perspMtx.persp.far,
                               D_800BE1F0[sp1F8]->perspMtx.persp.scale);
        guMtxCatF(sp288, sp248, sp248);

        sp2C8 = -1;
        sp2CC = -1;
        sp2D0 = -1;
        sp2D4 = 0;

        sp218 = D_800BE1F0[sp1F8]->vp.vp.vscale[0];
        sp210 = -D_800BE1F0[sp1F8]->vp.vp.vscale[1];
        sp208 = D_800BE1F0[sp1F8]->vp.vp.vscale[2];
        sp214 = D_800BE1F0[sp1F8]->vp.vp.vtrans[0];
        sp20C = D_800BE1F0[sp1F8]->vp.vp.vtrans[1];
        sp204 = D_800BE1F0[sp1F8]->vp.vp.vtrans[2];

        sp220 = sqrtf(SQ(sp248[0][0]) + SQ(sp248[1][0]) + SQ(sp248[2][0]));
        temp_f0 = sqrtf(SQ(sp248[0][1]) + SQ(sp248[1][1]) + SQ(sp248[2][1]));

        gDPPipeSync(gMainGfxPos[0]++);
        gDPSetCycleType(gMainGfxPos[0]++, G_CYC_1CYCLE);
        if (D_800BE200[sp1F8]) {
            gDPSetRenderMode(gMainGfxPos[0]++, G_RM_AA_ZB_XLU_SURF, G_RM_NOOP2);
        } else {
            gDPSetRenderMode(gMainGfxPos[0]++, G_RM_XLU_SURF, G_RM_NOOP2);
        }
        gDPSetTexturePersp(gMainGfxPos[0]++, G_TP_NONE);
        gDPSetDepthSource(gMainGfxPos[0]++, G_ZS_PRIM);
        gDPSetColorDither(gMainGfxPos[0]++, fx_colorDitherMode);
        gDPSetAlphaDither(gMainGfxPos[0]++, fx_alphaDitherMode);

        for (j = 0; j < 16; j++) {
            for (var_s7 = D_800BE1A8[j]; var_s7 != NULL; var_s7 = var_s7->next) {
                if (var_s7->unk_40 == 0.0f) {
                    continue;
                }
                temp_f12 = (sp248[0][0] * var_s7->unk_20.x + sp248[1][0] * var_s7->unk_20.y + sp248[2][0] * var_s7->unk_20.z + sp248[3][0]);
                temp_f20 = sp248[0][3] * var_s7->unk_20.x + sp248[1][3] * var_s7->unk_20.y + sp248[2][3] * var_s7->unk_20.z + sp248[3][3];

                if (temp_f20 == 0.0f) {
                    continue;
                }

                temp_f2 = 1.0f / temp_f20;
                temp_f12 *= temp_f2;
                temp_f14 = (sp248[0][1] * var_s7->unk_20.x + sp248[1][1] * var_s7->unk_20.y + sp248[2][1] * var_s7->unk_20.z + sp248[3][1]) * temp_f2;
                temp_f28 = (sp248[0][2] * var_s7->unk_20.x + sp248[1][2] * var_s7->unk_20.y + sp248[2][2] * var_s7->unk_20.z + sp248[3][2]) * temp_f2;

                if (temp_f12 < -1.0f || temp_f12 > 1.0f || temp_f14 < -1.0f || temp_f14 > 1.0f || temp_f28 < -1.0f || temp_f28 > 1.0f) {
                    continue;
                }

                var_f16 = (temp_f2 * var_s7->unk_40 * sp220 + temp_f12) * sp218 + sp214;
                temp_f12 = temp_f12 * sp218 + sp214;
                if (var_f16 > temp_f12) {
                    var_f24 = temp_f12 - (var_f16 - temp_f12);
                } else {
                    var_f24 = var_f16;
                    var_f16 = temp_f12 - (var_f16 - temp_f12);
                }

                var_f18 = (temp_f2 * var_s7->unk_40 * temp_f0 + temp_f14) * sp210 + sp20C;
                temp_f14 = temp_f14 * sp210 + sp20C;
                if (var_f18 > temp_f14) {
                    var_f26 = temp_f14 - (var_f18 - temp_f14);
                } else {
                    var_f26 = var_f18;
                    var_f18 = temp_f14 - (var_f18 - temp_f14);
                }

                v0 = fx_SpriteBanks[var_s7->unk_08 & 7][var_s7->unk_0A];
                temp_fp = v0->unk_04;
                temp_t4 = v0->unk_08;
                temp_s3 = v0->unk_0C;
                temp_s5 = v0->unk_10;
                sp1C8 = v0->unk_18[var_s7->unk_0B];
                if (temp_fp == 2) {
                    if (!(var_s7->flags & 0x10)) {
                        sp1C4 = v0->unk_18[v0->unk_00 + var_s7->unk_0B];
                    } else {
                        sp1C4 = v0->unk_18[v0->unk_00];
                    }
                }

                sp200 = (temp_s3 * 4096.0f) / (var_f16 - var_f24);
                sp1FC = (temp_s5 * 4096.0f) / (var_f18 - var_f26);

                if (var_s7->flags & 0x20) {
                    sp200 *= 2;
                    sp1F4 = 1;
                    switch (temp_s3) {
                        case 2:
                            var_s1 = 1;
                            break;
                        case 4:
                            var_s1 = 2;
                            break;
                        case 8:
                            var_s1 = 3;
                            break;
                        case 16:
                            var_s1 = 4;
                            break;
                        case 32:
                            var_s1 = 5;
                            break;
                        case 64:
                            var_s1 = 6;
                            break;
                        case 128:
                            var_s1 = 7;
                            break;
                        case 256:
                            var_s1 = 8;
                            break;
                        default:
                            var_s1 = 0;
                            break;
                    }
                } else {
                    sp1F4 = 2;
                    var_s1 = 0;
                }

                if (var_s7->flags & 0x40) {
                    sp1FC *= 2;
                    var_s6 = 1;
                    switch (temp_s5) {
                        case 2:
                            var_t2 = 1;
                            break;
                        case 4:
                            var_t2 = 2;
                            break;
                        case 8:
                            var_t2 = 3;
                            break;
                        case 16:
                            var_t2 = 4;
                            break;
                        case 32:
                            var_t2 = 5;
                            break;
                        case 64:
                            var_t2 = 6;
                            break;
                        case 128:
                            var_t2 = 7;
                            break;
                        case 256:
                            var_t2 = 8;
                            break;
                        default:
                            var_t2 = 0;
                            break;
                    }
                } else {
                    var_s6 = 2;
                    var_t2 = 0;
                }

                if (temp_fp == 2) {
                    if (sp1C4 != sp2D4) {
                        gDPLoadTLUT_pal256(gMainGfxPos[0]++, sp1C4);
                        sp2D4 = sp1C4;
                    }
                    if (sp2C8 != 1) {
                        gDPSetTextureLUT(gMainGfxPos[0]++, G_TT_RGBA16);
                        sp2C8 = 1;
                    }
                } else if (sp2C8 != 0) {
                    gDPSetTextureLUT(gMainGfxPos[0]++, G_TT_NONE);
                    sp2C8 = 0;
                }

                if (sp1C8 != var_s2) {
                    switch (temp_t4) {
                        case 0:
                            gDPLoadTextureBlock_4b(gMainGfxPos[0]++, sp1C8, temp_fp, temp_s3, temp_s5, 0, sp1F4, var_s6, var_s1, var_t2, G_TX_NOLOD, G_TX_NOLOD);
                            if (temp_s3 * temp_s5 >= 0x1000) {
                                sp2D4 = 0;
                            }
                            break;
                        case 1:
                            gDPLoadTextureBlock(gMainGfxPos[0]++, sp1C8, temp_fp, G_IM_SIZ_8b, temp_s3, temp_s5, 0, sp1F4, var_s6, var_s1, var_t2, G_TX_NOLOD, G_TX_NOLOD);
                            if (temp_s3 * temp_s5 >= 0x800) {
                                sp2D4 = 0;
                            }
                            break;
                        case 2:
                            gDPLoadTextureBlock(gMainGfxPos[0]++, sp1C8, temp_fp, G_IM_SIZ_16b, temp_s3, temp_s5, 0, sp1F4, var_s6, var_s1, var_t2, G_TX_NOLOD, G_TX_NOLOD);
                            if (temp_s3 * temp_s5 >= 0x400) {
                                sp2D4 = 0;
                            }
                            break;
                        case 3:
                            gDPLoadTextureBlock(gMainGfxPos[0]++, sp1C8, temp_fp, G_IM_SIZ_32b, temp_s3, temp_s5, 0, sp1F4, var_s6, var_s1, var_t2, G_TX_NOLOD, G_TX_NOLOD);
                            if (temp_s3 * temp_s5 >= 0x200) {
                                sp2D4 = 0;
                            }
                            break;
                    }
                    var_s2 = sp1C8;
                }

                gDPSetPrimColor(gMainGfxPos[0]++, 0, 0, var_s7->unk_48.r, var_s7->unk_48.g, var_s7->unk_48.b, var_s7->unk_48.a);
                if (var_s7->flags & 0x80) {
                    gDPSetEnvColor(gMainGfxPos[0]++, var_s7->unk_50.r, var_s7->unk_50.g, var_s7->unk_50.b, var_s7->unk_50.a);
                    gDPSetCombineLERP(gMainGfxPos[0]++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT,
                                      PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT,
                                      PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT,
                                      PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT);
                } else if (var_s7->flags & 0x100) {
                    gDPSetCombineLERP(gMainGfxPos[0]++, NOISE, 0, TEXEL0, 0,
                                      TEXEL0, 0, PRIMITIVE, 0,
                                      NOISE, 0, TEXEL0, 0,
                                      TEXEL0, 0, PRIMITIVE, 0);
                } else {
                    gDPSetCombineMode(gMainGfxPos[0]++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
                }

                if (var_s7->flags & 0x400) {
                    var_a1_2 = 3;
                } else {
                    var_a1_2 = 1;
                    if (var_s7->flags & 0x200) {
                        var_a0 = var_s7->unk_50.a;
                    } else {
                        var_a0 = 8;
                    }
                    if (sp2CC != var_a0) {
                        gDPSetBlendColor(gMainGfxPos[0]++, 0, 0, 0, var_a0);
                        sp2CC = var_a0;
                    }
                }

                if (sp2D0 != var_a1_2) {
                    gDPSetAlphaCompare(gMainGfxPos[0]++, var_a1_2);
                    sp2D0 = var_a1_2;
                }

                gDPSetPrimDepth(gMainGfxPos[0]++, (s32) ((sp204 + temp_f28 * sp208) * 32.0f), 0);
                gSPScisTextureRectangle(gMainGfxPos[0]++, (s32) var_f24, (s32) var_f26, (s32) var_f16, (s32) var_f18, G_TX_RENDERTILE, 0, 0, sp200, sp1FC);
            }
        }
    }

    if (sp2C8 != 0) {
        gDPSetTextureLUT(gMainGfxPos[0]++, G_TT_NONE);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/app_render/particle/fx_draw.s")
#endif

void fx_addAttachDObj(s32 bankID, DObj* dobj) {
    if (bankID > 0 && bankID <= ARRAY_COUNT(D_800BE208)) {
        D_800BE208[bankID - 1] = dobj;
    }
}

void fx_setDitherModes(s32 color, s32 alpha) {
    fx_colorDitherMode = color;
    fx_alphaDitherMode = alpha;
}

GObj* fx_allocEffects(s32 num) {
    s32 i;

    D_800BE1E8 = D_800BE1EC = NULL;

    for (i = num - 1; i >= 0; i--) {
        Effect* fx = gtlMalloc(sizeof(Effect), 4);
        if (fx == NULL) {
            return NULL;
        }
        fx->next = D_800BE1E8;
        D_800BE1E8 = fx;
    }

    return omAddGObj(-7, fx_effectFuncRun, LINK_0, 0x80000000);
}

void fx_getPosVelDObj(Vec3f* pos, Vec3f* vel, DObj* dobj) {
    Mtx4f dst;
    Mtx4f tmp;
    f32 x, y, z;
    s32 i;
    uintptr_t csr;
    struct Mtx3Float* var_s0;
    struct Mtx4Float* var_t1;
    struct Mtx3Float* var_t0;

    guMtxIdentF(dst);
    do {
        if (dobj->scale.v.x != 1.0f || dobj->scale.v.y != 1.0f || dobj->scale.v.z != 1.0f) {
            hal_scale_f(tmp, dobj->scale.v.x, dobj->scale.v.y, dobj->scale.v.z);
            guMtxCatF(dst, tmp, dst);
        }
        if (dobj->rotation.v.x != 0.0f || dobj->rotation.v.y != 0.0f || dobj->rotation.v.z != 0.0f) {
            hal_rotate_rpy_f(tmp, dobj->rotation.v.x, dobj->rotation.v.y, dobj->rotation.v.z);
            guMtxCatF(dst, tmp, dst);
        }
        if (dobj->position.v.x != 0.0f || dobj->position.v.y != 0.0f || dobj->position.v.z != 0.0f) {
            hal_translate_f(tmp, dobj->position.v.x, dobj->position.v.y, dobj->position.v.z);
            guMtxCatF(dst, tmp, dst);
        }

        if (dobj->unk_4C != NULL) {
            var_s0 = NULL;
            var_t1 = NULL;
            var_t0 = NULL;
            csr = (uintptr_t) dobj->unk_4C->data;
            for (i = 0; i < 3; i++) {
                switch (dobj->unk_4C->kinds[i]) {
                    case 0:
                        break;
                    case 1:
                        var_s0 = (void*) csr;
                        csr += sizeof(union Mtx3fi);
                        break;
                    case 2:
                        var_t1 = (void*) csr;
                        csr += sizeof(struct Mtx4Float);
                        break;
                    case 3:
                        var_t0 = (void*) csr;
                        csr += sizeof(struct Mtx3Float);
                        break;
                }
            }

            if (var_t0 != NULL && (var_t0->v.x != 1.0f || var_t0->v.y != 1.0f || var_t0->v.z != 1.0f)) {
                hal_scale_f(tmp, var_t0->v.x, var_t0->v.y, var_t0->v.z);
                guMtxCatF(dst, tmp, dst);
            }
            if (var_t1 != NULL && (var_t1->v.x != 0.0f || var_t1->v.y != 0.0f || var_t1->v.z != 0.0f)) {
                hal_rotate_rpy_f(tmp, var_t1->v.x, var_t1->v.y, var_t1->v.z);
                guMtxCatF(dst, tmp, dst);
            }
            if (var_s0 != NULL && (var_s0->v.x != 0.0f || var_s0->v.y != 0.0f || var_s0->v.z != 0.0f)) {
                hal_translate_f(tmp, var_s0->v.x, var_s0->v.y, var_s0->v.z);
                guMtxCatF(dst, tmp, dst);
            }
        }
        dobj = dobj->parent;
    } while ((uintptr_t) dobj != 1);

    pos->x = dst[3][0];
    pos->y = dst[3][1];
    pos->z = dst[3][2];
    // clang-format off
    x = vel->x; y = vel->y; z = vel->z;
    // clang-format on
    if (dst[0][0] != 0.0f || dst[1][0] != 0.0f || dst[2][0] != 0.0f) {
        guNormalize(&dst[0][0], &dst[1][0], &dst[2][0]);
    }
    if (dst[0][1] != 0.0f || dst[1][1] != 0.0f || dst[2][1] != 0.0f) {
        guNormalize(&dst[0][1], &dst[1][1], &dst[2][1]);
    }
    if (dst[0][2] != 0.0f || dst[1][2] != 0.0f || dst[2][2] != 0.0f) {
        guNormalize(&dst[0][2], &dst[1][2], &dst[2][2]);
    }
    vel->x = dst[0][0] * x + dst[1][0] * y + dst[2][0] * z;
    vel->y = dst[0][1] * x + dst[1][1] * y + dst[2][1] * z;
    vel->z = dst[0][2] * x + dst[1][2] * y + dst[2][2] * z;
}

#if 0
void fx_effectFuncRun(GObj* obj) {
    UnkPinkRat* ptr;
    Vec3f sp128;
    Vec3f sp11C;
    f32 sp108;
    f32 angle1;
    f32 spFC;
    f32 spF8;
    f32 angle2; // move this
    f32 spF4;
    f32 spF0;
    f32 spEC;
    f32 spDC;
    f32 spB8;
    f32 spB4;
    f32 var_f20;
    f32 var_f24;
    f32 temp_f26;
    f32 temp_f28;
    f32 temp_f20;

    f32 temp_f0;

    f32 temp_f22, temp_f0_6,
        spD0, spCC, temp_f12, spC8;

    f32 var_f14, var_f16, var_f18;

    f32 temp_f0_8;
    f32 temp_f28_4;
    f32 temp_f22_2;
    f32 var_f24_3;
    UnkPinkRat* next;

    f32 nv1;

    f32 x, y, z;
    f32 x1, y1, z1;

    for (ptr = D_800BE1EC, D_800BE2B0 = NULL; ptr != NULL;) {
        if (obj->flags & (1 << (16 + (ptr->unk_09 >> 3)))) {
            D_800BE2B0 = ptr;
            ptr = ptr->next;
            continue;
        }
        if (ptr->unk_06 & 0x800) {
            D_800BE2B0 = ptr;
            ptr = ptr->next;
            continue;
        }

        if (ptr->unk_40 < 0.0f) {
            ptr->unk_44 -= ptr->unk_40;
        } else {
            ptr->unk_44 += randFloat() * ptr->unk_40;
        }

        if (ptr->unk_44 >= 1.0f) {
            sp11C.x = ptr->unk_20.x;
            sp11C.y = ptr->unk_20.y;
            sp11C.z = ptr->unk_20.z;
            if (ptr->dobj != NULL) {
                fx_getPosVelDObj(&sp128, &sp11C, ptr->dobj);
                ptr->unk_14.x = sp128.x;
                ptr->unk_14.y = sp128.y;
                ptr->unk_14.z = sp128.z;
            }
            spDC = randFloat() * TAU;
            spB8 = TAU / (s32) ptr->unk_44;
        }

        while (ptr->unk_44 >= 1.0f) {
            switch (ptr->unk_08) {
                case 0:
                case 3:
                case 4:
                    x = sp11C.x;
                    y = sp11C.y;
                    z = sp11C.z;

                    angle1 = atan2f(y, z);
                    spFC = sinf(angle1);
                    spF8 = cosf(angle1);

                    angle2 = atan2f(x, y * spFC + z * spF8);
                    spF4 = sinf(angle2);
                    spF0 = cosf(angle2);

                    sp108 = sqrtf(SQ(x) + SQ(y) + SQ(z));

                    if (ptr->unk_38 < 0.0f) {
                        spB4 = 1.0f;
                        var_f20 = -ptr->unk_38;
                    } else {
                        spB4 = randFloat();
                        if (ptr->unk_08 != 0) {
                            spB4 = sqrtf(spB4);
                        }
                        var_f20 = ptr->unk_38 * spB4;
                    }

                    if (ptr->unk_3C < 0.0f) {
                        spDC += spB8;
                        var_f24 = -ptr->unk_3C;
                    } else {
                        spDC = randFloat() * TAU;
                        var_f24 = ptr->unk_3C * spB4;
                    }

                    spEC = __cosf(spDC) * var_f20;
                    temp_f26 = __sinf(spDC) * var_f20;
                    temp_f28 = __sinf(var_f24) * sp108;

                    temp_f20 = __cosf(spDC) * temp_f28;
                    temp_f22 = __sinf(spDC) * temp_f28;
                    temp_f0_6 = __cosf(var_f24) * sp108;

                    spD0 = ptr->unk_14.x;
                    spD0 += spEC * spF0 + 0;
                    spCC = -spEC * spFC * spF4 + temp_f26 * spF8 + 0 + ptr->unk_14.y;
                    spC8 = ptr->unk_14.z + (-spEC * spF8 * spF4 - temp_f26 * spFC + 0);

                    nv1 = temp_f0_6 * spFC * spF0;
                    var_f14 = temp_f20 * spF0 + temp_f0_6 * spF4;
                    var_f16 = -temp_f20 * spFC * spF4 + temp_f22 * spF8 + nv1;
                    var_f18 = -temp_f20 * spF8 * spF4 - temp_f22 * spFC + temp_f0_6 * spF8 * spF0;

                    if (ptr->unk_08 == 3) {
                        var_f14 *= spB4;
                        var_f16 *= spB4;
                        var_f18 *= spB4;
                    }
                    fx_makeParam(ptr->unk_09, ptr->unk_06, ptr->unk_0A, ptr->unk_10, ptr->unk_0C,
                                  spD0, spCC, spC8,
                                  var_f14, var_f16, var_f18,
                                  ptr->unk_34, ptr->unk_2C, ptr->unk_30, 0, ptr);
                    break;
                case 1:
                    temp_f0 = randFloat();
                    x1 = ptr->unk_14.x + temp_f0 * (ptr->unk_4C.data1.x - ptr->unk_14.x);
                    y1 = ptr->unk_14.y + temp_f0 * (ptr->unk_4C.data1.y - ptr->unk_14.y);
                    z1 = ptr->unk_14.z + temp_f0 * (ptr->unk_4C.data1.z - ptr->unk_14.z);
                    fx_makeParam(ptr->unk_09, ptr->unk_06, ptr->unk_0A, ptr->unk_10, ptr->unk_0C,
                                  x1, y1, z1,
                                  sp11C.x, sp11C.y, sp11C.z, ptr->unk_34, ptr->unk_2C, ptr->unk_30, 0, ptr);
                    break;
                case 2:
                    x = sp11C.x;
                    y = sp11C.y;
                    z = sp11C.z;
                    temp_f0_8 = atan2f(y, z);
                    temp_f28_4 = atan2f(x, y * __sinf(temp_f0_8) + z * __cosf(temp_f0_8));
                    temp_f22_2 = sqrtf(SQ(x) + SQ(y) + SQ(z));
                    if (ptr->unk_38 < 0.0f) {
                        var_f24_3 = 1.0f;
                    } else {
                        var_f24_3 = randFloat();
                    }
                    if (ptr->unk_3C < 0.0f) {
                        spDC += spB8;
                    } else {
                        spDC = randFloat() * 6.2831855f;
                    }
                    ptr->unk_4C.data2.unk_00 = temp_f22_2;
                    if (fx_makeParam(ptr->unk_09, ptr->unk_06 | 4, ptr->unk_0A, ptr->unk_10, ptr->unk_0C,
                                      0, 0, 0,
                                      spDC, var_f24_3, 0, ptr->unk_34, temp_f0_8, temp_f28_4, 0, ptr) != NULL) {
                        ptr->unk_4C.data2.unk_04++;
                    }
                    break;
                default:
                    if (fx_effectProcDefault != NULL) {
                        fx_effectProcDefault(ptr, &sp11C);
                    }
                    break;
            }

            ptr->unk_44 -= 1.0f;
        }

        if (ptr->unk_0E != 0 && --ptr->unk_0E == 0) {
            if (ptr->unk_08 == 2 && ptr->unk_4C.data2.unk_04 != 0) {
                ptr->unk_0E = 1;
                ptr->unk_40 = 0.0f;
                goto END;
            } else {
                if (D_800BE2B0 == NULL) {
                    D_800BE1EC = ptr->next;
                } else {
                    D_800BE2B0->next = ptr->next;
                }
                next = ptr->next;
                ptr->next = D_800BE1E8;
                D_800BE1E8 = ptr;
                ptr = next;
            }
        } else {
        END:
            D_800BE2B0 = ptr;
            ptr = ptr->next;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/app_render/particle/fx_effectFuncRun.s")
void fx_effectFuncRun(GObj* obj);
#endif

Effect* fx_getEffect(void) {
    Effect* ret;

    ret = D_800BE1E8;
    if (ret == NULL) {
        return NULL;
    }

    D_800BE1E8 = ret->next;
    ret->next = D_800BE1EC;
    D_800BE1EC = ret;
    if (D_800BE2B0 == NULL) {
        D_800BE2B0 = ret;
    }

    ret->effectID = ++fx_currentEffectID;
    return ret;
}

Effect* fx_createEffect(s32 bankID, s32 scriptID) {
    Effect* ret;
    s32 id = bankID & 7;
    s32 unused;

    if (id >= PARTICLE_BANKS_MAX) {
        return NULL;
    }
    if (scriptID >= fx_ScriptBanksNum[id]) {
        return NULL;
    }

    ret = fx_getEffect();
    if (ret != NULL) {
        ret->kind = fx_ScriptBanks[id][scriptID]->kind;
        ret->bankID = bankID;
        ret->flags = fx_ScriptBanks[id][scriptID]->flags;
        ret->textureID = fx_ScriptBanks[id][scriptID]->textureID;
        ret->particleLifetime = fx_ScriptBanks[id][scriptID]->particleLifetime;
        ret->effectLifetime = fx_ScriptBanks[id][scriptID]->effectLifetime;
        ret->pos.x = 0.0f;
        ret->pos.y = 0.0f;
        ret->pos.z = 0.0f;
        ret->vel.x = fx_ScriptBanks[id][scriptID]->vel.x;
        ret->vel.y = fx_ScriptBanks[id][scriptID]->vel.y;
        ret->vel.z = fx_ScriptBanks[id][scriptID]->vel.z;
        ret->gravity = fx_ScriptBanks[id][scriptID]->gravity;
        ret->friction = fx_ScriptBanks[id][scriptID]->friction;
        ret->size = fx_ScriptBanks[id][scriptID]->size;
        ret->bytecode = fx_ScriptBanks[id][scriptID]->bytecode;
        ret->unk_38 = fx_ScriptBanks[id][scriptID]->unk_20;
        ret->unk_3C = fx_ScriptBanks[id][scriptID]->unk_24;
        ret->unk_40 = fx_ScriptBanks[id][scriptID]->unk_28;
        ret->unk_44 = 0.0f;
        if (fx_SpriteBanks[id][fx_ScriptBanks[id][scriptID]->textureID]->flags != 0) {
            ret->flags |= 0x10;
        }
        ret->dobj = NULL;

        switch (ret->kind) {
            case 0:
            case 3:
            case 4:
                break;
            case 1:
                ret->effectVars.move.x = ret->pos.x + ret->vel.x;
                ret->effectVars.move.y = ret->pos.y + ret->vel.y;
                ret->effectVars.move.z = ret->pos.z + ret->vel.z;
                break;
            case 2:
                ret->effectVars.data2.unk_04 = 0;
                break;
            default:
                if (fx_effectProcSetup != NULL) {
                    fx_effectProcSetup(ret);
                }
                break;
        }
    }
    return ret;
}

void fx_ejectEffect(Effect* fx) {
    Effect* prev = NULL;
    Effect* it = D_800BE1EC;

    while (it != NULL) {
        if (it == fx) {
            if (fx->kind == 2 && fx->effectVars.data2.unk_04 != 0) {
                fx->effectLifetime = 1;
                fx->unk_40 = 0.0f;
                return;
            }
            if (prev == NULL) {
                D_800BE1EC = it->next;
            } else {
                prev->next = it->next;
            }
            it->next = D_800BE1E8;
            D_800BE1E8 = it;
            return;
        }
        prev = it;
        it = it->next;
    }
}

void fx_ejectEffectAll(void) {
    Effect* it = D_800BE1EC;

    while (it != NULL) {
        Effect* next = it->next;

        fx_ejectEffect(it);
        it = next;
    }
}

void fx_setEffectProcs(void (*procSetup)(Effect*), void (*procBase)(Effect*, Vec3f*)) {
    fx_effectProcSetup = procSetup;
    fx_effectProcDefault = procBase;
}

void fx_ejectStructID(u16 effectID, s32 linkID) {
    Particle* it;
    Particle* next;
    Particle* prev;
    Effect* it2;
    Effect* next2;
    Effect* prev2;

    prev = NULL;
    for (it = D_800BE1A8[linkID]; it != NULL; it = next) {
        next = it->next;
        if (it->effectID == effectID) {
            if (prev == NULL) {
                D_800BE1A8[linkID] = it->next;
            } else {
                prev->next = it->next;
            }
            if (it->fx != NULL && (it->flags & 4) && it->fx->kind == 2) {
                it->fx->effectVars.data2.unk_04--;
            }
            it->next = D_800BE1A0;
            D_800BE1A0 = it;
        } else {
            prev = it;
        }
    }

    prev2 = NULL;
    for (it2 = D_800BE1EC; it2 != NULL; it2 = next2) {
        next2 = it2->next;
        if (it2->effectID == effectID) {
            if (it2->kind == 2 && it2->effectVars.data2.unk_04 != 0) {
                it2->unk_40 = 0.0f;
                it2->effectLifetime = 1;
                prev2 = it2;
            } else {
                if (prev2 == NULL) {
                    D_800BE1EC = it2->next;
                } else {
                    prev2->next = it2->next;
                }
                it2->next = D_800BE1E8;
                D_800BE1E8 = it2;
            }
        } else {
            prev2 = it2;
        }
    }
}

void fx_ejectStructSelf(Particle* particle) {
    fx_ejectStructID(particle->effectID, particle->bankID >> 3);
}

void fx_ejectStructEffect(Effect* fx) {
    fx_ejectStructID(fx->effectID, fx->bankID >> 3);
}

void fx_ejectEffectDObj(GObj* obj) {
    DObj* dobj;
    Effect* it;
    Effect* next;

    if (obj->type == 1) {
        for (dobj = obj->data.dobj; dobj != NULL; dobj = animModelTreeNextNode(dobj)) {
            for (it = D_800BE1EC; it != NULL; it = next) {
                next = it->next;
                if (it->dobj == dobj) {
                    fx_ejectEffect(it);
                }
            }
        }
    }
}

void fx_translatePosAll(f32 dx, f32 dy, f32 dz) {
    Particle* particle;
    Effect* fx;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_800BE1A8); i++) {
        for (particle = D_800BE1A8[i]; particle != NULL; particle = particle->next) {
            particle->pos.x += dx;
            particle->pos.y += dy;
            particle->pos.z += dz;
        }
    }

    for (fx = D_800BE1EC; fx != NULL; fx = fx->next) {
        fx->pos.x += dx;
        fx->pos.y += dy;
        fx->pos.z += dz;
    }
}

void fx_pauseAllID(u16 effectID, s32 linkID) {
    Particle* particle;
    Effect* fx;

    for (particle = D_800BE1A8[linkID]; particle != NULL; particle = particle->next) {
        if (particle->effectID == effectID) {
            particle->flags |= PARTICLE_FLAG_PAUSE;
        }
    }

    for (fx = D_800BE1EC; fx != NULL; fx = fx->next) {
        if (fx->effectID == effectID) {
            fx->flags |= PARTICLE_FLAG_PAUSE;
        }
    }
}

void fx_resumeAllID(u16 effectID, s32 linkID) {
    Particle* particle;
    Effect* fx;

    for (particle = D_800BE1A8[linkID]; particle != NULL; particle = particle->next) {
        if (particle->effectID == effectID) {
            particle->flags &= ~PARTICLE_FLAG_PAUSE;
        }
    }

    for (fx = D_800BE1EC; fx != NULL; fx = fx->next) {
        if (fx->effectID == effectID) {
            fx->flags &= ~PARTICLE_FLAG_PAUSE;
        }
    }
}
