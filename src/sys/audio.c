#include "audio/synthInternals.h"
#include "PR/os.h"
#include "PR/gu.h"
#include "sys/sched.h"
#include "sys/main.h"
#include "sys/dma.h"
#include "macros.h"
#include "PR/rcp.h"
#include "ld_addrs.h"
#include "ucode.h"

#define NUM_DMA_BUFFERS 4
#define MAX_BUFFERS 50
#define MAX_BUFFER_LENGTH 1024
#define AUDIO_EXTRA_SAMPLES 80

#define TREMELO_SIN 1
#define TREMELO_SQR 2
#define TREMELO_DSC_SAW 3
#define TREMELO_ASC_SAW 4
#define VIBRATO_SIN 128
#define VIBRATO_SQR 129
#define VIBRATO_DSC_SAW 130
#define VIBRATO_ASC_SAW 131
#define OSC_HIGH 0
#define OSC_LOW 1
#define TWO_PI 6.2831853f
#define OSC_STATE_COUNT 44

typedef struct {
    u8* heapBase;
    s32 heapSize;
    u16 outputRate;
    u8 maxPVoices;
    u8 maxVVoices;
    u8 maxUpdates;
    u8 maxEvents;
    u8 numSounds;
    u8 maxVoices[2];
    s8 unk_11;
    s8 unk_12;
    u8 unk_13;
    s32 bank1Start;
    s32 bank1End;
    u8* table1Start;
    s32 bank2Start;
    s32 bank2End;
    u8* table2Start;
    s32 romSbkStart;
    u8 fxType;
} AuSettings;

typedef struct {
    u8 rate;
    u8 depth;
    u8 oscCount;
} defData;

typedef struct {
    u8 halfdepth;
    u8 baseVol;
} tremSinData;

typedef struct {
    u8 curVal;
    u8 hiVal;
    u8 loVal;
} tremSqrData;

typedef struct {
    u8 baseVol;
    u8 depth;
} tremSawData;

typedef struct {
    f32 depthcents;
} vibSinData;

typedef struct {
    f32 loRatio;
    f32 hiRatio;
} vibSqrData;

typedef struct {
    s32 hicents;
    s32 centsrange;
} vibDSawData;

typedef struct {
    s32 locents;
    s32 centsrange;
} vibASawData;

typedef struct oscData_s {
    struct oscData_s* next;
    u8 type;
    u8 stateFlags;
    u16 maxCount;
    u16 curCount;
    union {
        defData def;
        tremSinData tsin;
        tremSqrData tsqr;
        tremSawData tsaw;
        vibSinData vsin;
        vibSqrData vsqr;
        vibDSawData vdsaw;
        vibASawData vasaw;
    } data;
} oscData;

typedef struct {
    u32 addr;
    u32 len;
    u32 size;
    char* ptr;
} AMDMABuffer;

typedef struct {
    u32 nBuffers;
    u32 currentBuffer;
    AMDMABuffer buffers[NUM_DMA_BUFFERS];
} AMDMAState;

typedef struct N_ALVoice_s {
    ALLink node;
    struct N_PVoice_s* pvoice;
    ALWaveTable* table;
    void* clientPrivate;
    s16 state;
    s16 priority;
    s16 fxBus;
    s16 unityPitch;
} N_ALVoice;

typedef struct {
    N_ALVoice voice;
    ALSound* sound; /* sound referenced here */
    s16 priority;
    f32 pitch;      /* current playback pitch                    */
    s32 state;      /* play state for this sound                 */
    s16 vol;        /* volume - combined with volume from bank   */
    ALPan pan;      /* pan - 0 = left, 127 = right               */
    u8 fxMix;       /* wet/dry mix - 0 = dry, 127 = wet          */
} N_ALSoundState;

s32 auCustomFXParams1[] = {
    8,      0x28a0, 0,    0x100,  9830,  -9830,  0,      0,      0,      0,      0x100, 0x180, 9830,  -9830,
    11140,  0,      0,    0x5000, 0x520, 0x1000, 16384,  -16384, 4587,   0,      0,     0,     0x5a0, 0xce0,
    8192,   -8192,  0,    0,      0,     0,      0x1440, 0x2340, 16384,  -16384, 4587,  0,     0,     0x6000,
    0x14c0, 0x1dc0, 8192, -8192,  0,     0,      0,      0,      0x1dc0, 0x2180, 8192,  -8192, 0,     0,
    0,      0,      0,    0x2560, 18000, 0,      0,      0,      0,      0x7000,
};

s32 auCustomFXParams2[] = { 14, 0x4b00, 0,      0x280,  9830, -9830, 0,    0, 0, 0, 0x3c0,  0x500,  3276, -3276, 8191, 0,
                     0,  0,      0x780,  0xa00,  3276, -3276, 5631, 0, 0, 0, 0xa00,  0xdc0,  3276, -3276, 4351, 0,
                     0,  0,      0xc80,  0x12c0, 3276, -3276, 4351, 0, 0, 0, 0xf00,  0x1900, 3276, -3276, 4095, 0,
                     0,  0,      0x1680, 0x1e00, 3276, -3276, 4095, 0, 0, 0, 0x1f40, 0x2580, 3276, -3276, 2559, 0,
                     0,  0,      0x2580, 0x2bc0, 3276, -3276, 2559, 0, 0, 0, 0x2bc0, 0x3200, 3276, -3276, 1535, 0,
                     0,  0,      0x3200, 0x3840, 3276, -3276, 1535, 0, 0, 0, 0x3840, 0x3e80, 3276, -3276, 255,  0,
                     0,  0,      0x3e80, 0x44c0, 3276, -3276, 255,  0, 0, 0, 0,      0x2580, 5000, 0,     0,    0,
                     0,  0x5000 };

s32* auCustomFXParamsTable[2] = { auCustomFXParams1, auCustomFXParams2 };

u8 auSoundPriorities[400] = { 50,  50,  50,  50,  50,  50,  50,  50,  30,  30,  50,  50,  50,  50,  90,  90,  50,  50,  50,  50,
                    90,  90,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  100, 100, 100, 100, 100, 100, 100, 100,
                    100, 100, 100, 100, 100, 100, 100, 100, 80,  80,  100, 100, 100, 100, 100, 100, 100, 100, 100, 80,
                    100, 100, 100, 100, 40,  40,  40,  40,  40,  40,  40,  40,  40,  40,  40,  40,  40,  40,  40,  40,
                    40,  40,  40,  40,  40,  40,  40,  40,  40,  40,  40,  40,  40,  40,  40,  40,  40,  40,  40,  40,
                    40,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,
                    50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,
                    50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,
                    110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110,
                    50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,
                    50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,
                    50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,
                    50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,
                    50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,
                    50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,
                    50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,
                    50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,
                    50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,
                    50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,
                    50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50,  50 };

s32 auSettingsUpdated = 0;
s32 nextDMA = 0;
s32 auSoundQuality = 1;
s32 auCurrentFxType = 0;
s32 auRestarting = 0;
s32 auFrameCounter = 1;
s16 auSampleCount[] = { 0, 0, 0, 0 };
u8 auGlobalSoundVolume = 127;
u8 auGlobalSoundReverbAmt = 0;
u32 D_800423E0 = 0x7F00;

u8 auHeapBuffer[0x4B000];
u32 D_80096250;
ALHeap auHeap;
void* auHeapBase;
s32 auHeapSize;
SCClient auClient;
OSMesgQueue auGameTickQueue;
OSMesgQueue auSPTaskMessageQueue;
OSMesgQueue auDMAMessageQueue;
OSMesg auGameTickMessages[1];
OSMesg auSPTaskMessages[1];
OSMesg auDMAMessages[50];
OSIoMesg audDMAIOMesgBuf[MAX_BUFFERS];
ALGlobals auGlobals;
s32 auFrequency;
s16* auDataBuffers[3];
Acmd* auCmdListPtr;
Acmd* auCmdListBuffers[2];
SCTaskAudio* auTask;
SCTaskAudio* auScTasks[2];
ALBank* D_800968B8;
s32* D_800968BC;
s32* auStartingSound;
s8* auSndpSoundId; // returned by alSndpAllocate
u8* auSoundPriority;
u8* auSoundIdleCounter;
f32* auSoundPitch;
u16* auSoundVolume;
u8* auSoundPan;
u8* auSoundReverbAmt;
ALInstrument* auSFXPlayer;
ALSndPlayer* auSoundPlayer;
ALBank* auSeqBank;
ALSeqFile* auSeqFile;
ALCSPlayer* auBGMPlayers[2];
ALCSeq* auBGMSequences[2];
u8 auGlobalSongPriority;
u8* auBGMSeqData[2];
u8* auBGMPlayerStatus;
s32* auBGMSongId;
s32 auBGMVolTimer[2];
f32 auBGMVolume[2];
f32 auSongVolRate[2];
AuSettings auCurrentSettings;
OSTime D_80096968;
oscData* freeOscStateList;

AuSettings auPublicSettings = {
    auHeapBuffer,
    sizeof(auHeapBuffer),
    32000,
    0x16,
    0x18,
    0x40,
    0x40,
    10,
    { 16, 16 },        
    0,          
    50,         
    100,        
    (s32)audio_bank2_ROM_START, 
    (s32)audio_bank2_ROM_END,
    audio_table2_ROM_START,
    (s32)audio_bank1_ROM_START, 
    (s32)audio_bank1_ROM_END,
    audio_table1_ROM_START,
    (s32)audio_sbk_ROM_START,
    AL_FX_CUSTOM
};

static void _bnkfPatchBank(ALBank* bank, s32 offset, s32 table);
static void _bnkfPatchInst(ALInstrument* i, s32 offset, s32 table);
static void _bnkfPatchSound(ALSound* s, s32 offset, s32 table);
static void _bnkfPatchWaveTable(ALWaveTable* w, s32 offset, s32 table);

void auStopAllSounds(void);
void auStopBGM(void);
void auStopSong(s32 arg0);

void alHeapInit(ALHeap* hp, u8* base, s32 len) {
    s32 extraAlign = (AL_CACHE_ALIGN + 1) - ((s32)base & AL_CACHE_ALIGN);

    if (extraAlign != AL_CACHE_ALIGN + 1)
        hp->base = base + extraAlign;
    else
        hp->base = base;

    hp->len = len;
    hp->cur = hp->base;
    hp->count = 0;
}

void* alHeapDBAlloc(u8* file, s32 line, ALHeap* hp, s32 num, s32 size) {
    s32 bytes;
    u8* ptr = 0;

    bytes = (num * size + AL_CACHE_ALIGN) & ~AL_CACHE_ALIGN;

    if ((hp->cur + bytes) <= (hp->base + hp->len)) {
        ptr = hp->cur;
        hp->cur += bytes;
    }

    return ptr;
}

void alSeqFileNew(ALSeqFile* file, u8* base) {
    s32 offset = (s32)base;
    s32 i;

    /*
     * patch the file so that offsets are pointers
     */
    for (i = 0; i < file->seqCount; i++) {
        file->seqArray[i].offset = (u8*)((u8*)file->seqArray[i].offset + offset);
    }
}

void alBnkfNew(ALBankFile* file, u8* table) {
    s32 offset = (s32)file;
    s32 woffset = (s32)table;

    s32 i;

    /*
     * patch the file so that offsets are pointers
     */
    for (i = 0; i < file->bankCount; i++) {
        file->bankArray[i] = (ALBank*)((u8*)file->bankArray[i] + offset);
        if (file->bankArray[i])
            _bnkfPatchBank(file->bankArray[i], offset, woffset);
    }
}

void _bnkfPatchBank(ALBank* bank, s32 offset, s32 table) {
    s32 i;

    if (bank->flags)
        return;

    bank->flags = 1;

    if (bank->percussion) {
        bank->percussion = (ALInstrument*)((u8*)bank->percussion + offset);
        _bnkfPatchInst(bank->percussion, offset, table);
    }

    for (i = 0; i < bank->instCount; i++) {
        bank->instArray[i] = (ALInstrument*)((u8*)bank->instArray[i] + offset);
        if (bank->instArray[i])
            _bnkfPatchInst(bank->instArray[i], offset, table);
    }
}

void _bnkfPatchInst(ALInstrument* inst, s32 offset, s32 table) {
    s32 i;

    if (inst->flags)
        return;

    inst->flags = 1;

    for (i = 0; i < inst->soundCount; i++) {
        inst->soundArray[i] = (ALSound*)((u8*)inst->soundArray[i] + offset);
        _bnkfPatchSound(inst->soundArray[i], offset, table);
    }
}

void _bnkfPatchSound(ALSound* s, s32 offset, s32 table) {
    if (s->flags)
        return;

    s->flags = 1;

    s->envelope = (ALEnvelope*)((u8*)s->envelope + offset);
    s->keyMap = (ALKeyMap*)((u8*)s->keyMap + offset);

    s->wavetable = (ALWaveTable*)((u8*)s->wavetable + offset);
    _bnkfPatchWaveTable(s->wavetable, offset, table);
}

void _bnkfPatchWaveTable(ALWaveTable* w, s32 offset, s32 table) {
    if (w->flags)
        return;

    w->flags = 1;

    w->base += table;

    if (w->type == AL_ADPCM_WAVE) {
        w->waveInfo.adpcmWave.book = (ALADPCMBook*)((u8*)w->waveInfo.adpcmWave.book + offset);
        if (w->waveInfo.adpcmWave.loop)
            w->waveInfo.adpcmWave.loop = (ALADPCMloop*)((u8*)w->waveInfo.adpcmWave.loop + offset);
    } else if (w->type == AL_RAW16_WAVE) {
        if (w->waveInfo.rawWave.loop)
            w->waveInfo.rawWave.loop = (ALRawLoop*)((u8*)w->waveInfo.rawWave.loop + offset);
    }
}

void auRomRead(u32 romAddr, void* vramAddr, u32 size) {
    OSIoMesg DmaIoMessage;

    osInvalDCache((void*)vramAddr, (s32)size);

    DmaIoMessage.hdr.pri = OS_MESG_PRI_NORMAL;
    DmaIoMessage.hdr.retQueue = &auDMAMessageQueue;
    DmaIoMessage.dramAddr = vramAddr;
    DmaIoMessage.devAddr = romAddr;
    DmaIoMessage.size = size;

    osEPiStartDma(gRomPiHandle, &DmaIoMessage, OS_READ);
    osRecvMesg(&auDMAMessageQueue, NULL, OS_MESG_BLOCK);
}

s32 auDMA(s32 addr, s32 len, void* state) {
    void* freeBuffer;
    AMDMAState* dState = state;
    s32 delta = 0;
    u32 bStartAddr;
    u32 bEndAddr;
    AMDMABuffer* dBuff = &dState->buffers[dState->currentBuffer];
    OSMesg dummyMesg;

    /*
     * Is it in the last buffer
     */

    bStartAddr = (u32)dBuff->addr;
    bEndAddr = (u32)bStartAddr + dBuff->len;

    if ((addr >= bStartAddr) && (addr + len <= bEndAddr)) {
        freeBuffer = dBuff->ptr + addr - dBuff->addr;
    } else {
        if (++dState->currentBuffer >= dState->nBuffers) {
            dState->currentBuffer = 0;
        }
        dBuff = &dState->buffers[dState->currentBuffer];
        freeBuffer = dBuff->ptr;
        delta = addr & 0x1;
        addr -= delta;

        dBuff->addr = addr;
        dBuff->len = dBuff->size;

        audDMAIOMesgBuf[nextDMA].hdr.pri = OS_MESG_PRI_HIGH;
        audDMAIOMesgBuf[nextDMA].hdr.retQueue = &auDMAMessageQueue;
        audDMAIOMesgBuf[nextDMA].dramAddr = freeBuffer;
        audDMAIOMesgBuf[nextDMA].devAddr = (u32)addr;
        audDMAIOMesgBuf[nextDMA].size = dBuff->size;

        osEPiStartDma(gRomPiHandle, &audDMAIOMesgBuf[nextDMA++], OS_READ);
    }
    return (int)osVirtualToPhysical(freeBuffer) + delta;
}

ALDMAproc auDMANew(AMDMAState** state) {
    int i;
    AMDMAState* dState;

    dState = (AMDMAState*)alHeapAlloc(&auHeap, 1, sizeof(AMDMAState));
    dState->currentBuffer = 0;
    dState->nBuffers = NUM_DMA_BUFFERS;
    for (i = 0; i < NUM_DMA_BUFFERS; i++) {
        dState->buffers[i].ptr = alHeapAlloc(&auHeap, 1, MAX_BUFFER_LENGTH);
        dState->buffers[i].addr = 0;
        dState->buffers[i].len = 0;
        dState->buffers[i].size = MAX_BUFFER_LENGTH;
    }
    *state = (AMDMAState*)dState;
    return auDMA;
}

f32 _depth2Cents(u8 depth) {
    f32 x = 1.03099303;
    f32 cents = 1.0;

    while (depth) {
        if (depth & 1)
            cents *= x;
        x *= x;
        depth >>= 1;
    }

    return (cents);
}

ALMicroTime initOsc(void** oscState, f32* initVal, u8 oscType, u8 oscRate, u8 oscDepth, u8 oscDelay) {
    oscData* statePtr;
    ALMicroTime deltaTime = 0;

    if (freeOscStateList) /* yes there are oscStates available */
    {
        statePtr = freeOscStateList;
        freeOscStateList = freeOscStateList->next;
        statePtr->type = oscType;
        *oscState = statePtr;

        /*
         * Convert delay into usec's, In this example, multiply by
         * 0x4000, but could easily use another conversion method.
         */
        deltaTime = oscDelay * 0x4000;

        switch (oscType) /* set the initVal */
        {
            case TREMELO_SIN:
                statePtr->curCount = 0;
                statePtr->maxCount = 259 - oscRate; /* gives values 4-259 */
                statePtr->data.tsin.halfdepth = oscDepth >> 1;
                statePtr->data.tsin.baseVol = AL_VOL_FULL - statePtr->data.tsin.halfdepth;
                *initVal = (f32)statePtr->data.tsin.baseVol;
                break;

            case TREMELO_SQR:
                statePtr->maxCount = 256 - oscRate; /* values from 1-256 */
                statePtr->curCount = statePtr->maxCount;
                statePtr->stateFlags = OSC_HIGH;
                statePtr->data.tsqr.loVal = AL_VOL_FULL - oscDepth;
                statePtr->data.tsqr.hiVal = AL_VOL_FULL;
                statePtr->data.tsqr.curVal = AL_VOL_FULL;
                *initVal = (f32)AL_VOL_FULL;
                break;

            case TREMELO_DSC_SAW:
                statePtr->maxCount = 256 - oscRate;
                statePtr->curCount = 0;
                statePtr->data.tsaw.depth = oscDepth;
                statePtr->data.tsaw.baseVol = AL_VOL_FULL;
                *initVal = (f32)statePtr->data.tsaw.baseVol;
                break;

            case TREMELO_ASC_SAW:
                statePtr->maxCount = 256 - oscRate;
                statePtr->curCount = 0;
                statePtr->data.tsaw.depth = oscDepth;
                statePtr->data.tsaw.baseVol = AL_VOL_FULL - oscDepth;
                *initVal = (f32)statePtr->data.tsaw.baseVol;
                break;

            case VIBRATO_SIN:
                statePtr->data.vsin.depthcents = _depth2Cents(oscDepth);
                statePtr->curCount = 0;
                statePtr->maxCount = 259 - oscRate; /* gives values 4-259 */
                *initVal = 1.0f;                    /* start at unity pitch */
                break;

            case VIBRATO_SQR: {
                s32 cents;
                statePtr->maxCount = 256 - oscRate; /* values from 1-256 */
                statePtr->curCount = statePtr->maxCount;
                statePtr->stateFlags = OSC_HIGH;
                cents = _depth2Cents(oscDepth);
                statePtr->data.vsqr.loRatio = alCents2Ratio(-cents);
                statePtr->data.vsqr.hiRatio = alCents2Ratio(cents);
                *initVal = statePtr->data.vsqr.hiRatio;
            } break;

            case VIBRATO_DSC_SAW: {
                s32 cents;
                statePtr->maxCount = 256 - oscRate; /* values from 1-256 */
                statePtr->curCount = statePtr->maxCount;
                cents = _depth2Cents(oscDepth);
                statePtr->data.vdsaw.hicents = cents;
                statePtr->data.vdsaw.centsrange = 2 * cents;
                *initVal = alCents2Ratio(statePtr->data.vdsaw.hicents);
            } break;

            case VIBRATO_ASC_SAW: {
                s32 cents;
                statePtr->maxCount = 256 - oscRate; /* values from 1-256 */
                statePtr->curCount = statePtr->maxCount;
                cents = _depth2Cents(oscDepth);
                statePtr->data.vasaw.locents = -cents;
                statePtr->data.vasaw.centsrange = 2 * cents;
                *initVal = alCents2Ratio(statePtr->data.vasaw.locents);
            } break;
        }
    }
    return (deltaTime); /* if there are no oscStates, return zero, but if
                           oscState was available, return delay in usecs */
}

ALMicroTime updateOsc(void* oscState, f32* updateVal) {
    f32 tmpFlt;
    oscData* statePtr = (oscData*)oscState;
    ALMicroTime deltaTime = AL_USEC_PER_FRAME; /* in this example callback every */
                                               /* frame, but could be at any interval */

    switch (statePtr->type)                    /* perform update calculations */
    {
        case TREMELO_SIN:
            statePtr->curCount++;
            if (statePtr->curCount >= statePtr->maxCount)
                statePtr->curCount = 0;
            tmpFlt = (f32)statePtr->curCount / (f32)statePtr->maxCount;
            tmpFlt = sinf(tmpFlt * TWO_PI);
            tmpFlt = tmpFlt * (f32)statePtr->data.tsin.halfdepth;
            *updateVal = (f32)statePtr->data.tsin.baseVol + tmpFlt;
            break;

        case TREMELO_SQR:
            if (statePtr->stateFlags == OSC_HIGH) {
                *updateVal = (f32)statePtr->data.tsqr.loVal;
                statePtr->stateFlags = OSC_LOW;
            } else {
                *updateVal = (f32)statePtr->data.tsqr.hiVal;
                statePtr->stateFlags = OSC_HIGH;
            }
            deltaTime *= statePtr->maxCount;
            break;

        case TREMELO_DSC_SAW:
            statePtr->curCount++;
            if (statePtr->curCount > statePtr->maxCount)
                statePtr->curCount = 0;

            tmpFlt = (f32)statePtr->curCount / (f32)statePtr->maxCount;
            tmpFlt *= (f32)statePtr->data.tsaw.depth;
            *updateVal = (f32)statePtr->data.tsaw.baseVol - tmpFlt;
            break;

        case TREMELO_ASC_SAW:
            statePtr->curCount++;
            if (statePtr->curCount > statePtr->maxCount)
                statePtr->curCount = 0;
            tmpFlt = (f32)statePtr->curCount / (f32)statePtr->maxCount;
            tmpFlt *= (f32)statePtr->data.tsaw.depth;
            *updateVal = (f32)statePtr->data.tsaw.baseVol + tmpFlt;
            break;

        case VIBRATO_SIN:
            /* calculate a sin value (from -1 to 1) and multiply it by depthcents.
               Then convert cents to ratio. */

            statePtr->curCount++;
            if (statePtr->curCount >= statePtr->maxCount)
                statePtr->curCount = 0;
            tmpFlt = (f32)statePtr->curCount / (f32)statePtr->maxCount;
            tmpFlt = sinf(tmpFlt * TWO_PI) * statePtr->data.vsin.depthcents;
            *updateVal = alCents2Ratio((s32)tmpFlt);
            break;

        case VIBRATO_SQR:
            if (statePtr->stateFlags == OSC_HIGH) {
                statePtr->stateFlags = OSC_LOW;
                *updateVal = statePtr->data.vsqr.loRatio;
            } else {
                statePtr->stateFlags = OSC_HIGH;
                *updateVal = statePtr->data.vsqr.hiRatio;
            }
            deltaTime *= statePtr->maxCount;
            break;

        case VIBRATO_DSC_SAW:
            statePtr->curCount++;
            if (statePtr->curCount > statePtr->maxCount)
                statePtr->curCount = 0;
            tmpFlt = (f32)statePtr->curCount / (f32)statePtr->maxCount;
            tmpFlt *= (f32)statePtr->data.vdsaw.centsrange;
            tmpFlt = (f32)statePtr->data.vdsaw.hicents - tmpFlt;
            *updateVal = alCents2Ratio((s32)tmpFlt);
            break;

        case VIBRATO_ASC_SAW:
            statePtr->curCount++;
            if (statePtr->curCount > statePtr->maxCount)
                statePtr->curCount = 0;
            tmpFlt = (f32)statePtr->curCount / (f32)statePtr->maxCount;
            tmpFlt *= (f32)statePtr->data.vasaw.centsrange;
            tmpFlt += (f32)statePtr->data.vasaw.locents;
            *updateVal = alCents2Ratio((s32)tmpFlt);
            break;
    }

    return (deltaTime);
}

void stopOsc(void* oscState) {
    ((oscData*)oscState)->next = freeOscStateList;
    freeOscStateList = (oscData*)oscState;
}

void auInit(void) {
    scAddClient(&auClient, &auGameTickQueue, auGameTickMessages, 1);
    osCreateMesgQueue(&auDMAMessageQueue, auDMAMessages, 50);
    osCreateMesgQueue(&auSPTaskMessageQueue, auSPTaskMessages, 1);
    osSendMesg(&auSPTaskMessageQueue, (OSMesg)NULL, OS_MESG_BLOCK);
}

void auLoadAssets(void) {
    s32 tmp;
    ALBankFile* bankFile;
    s32 i;
    s32 len;

    bzero(auCurrentSettings.heapBase, auCurrentSettings.heapSize);
    alHeapInit(&auHeap, auCurrentSettings.heapBase, auCurrentSettings.heapSize);

    // load sfx bank
    if ((u32)auCurrentSettings.bank2Start >= 0x80000000U) {
        auSeqBank = (ALBank*)auCurrentSettings.bank2Start;
    } else {
        len = auCurrentSettings.bank2End - auCurrentSettings.bank2Start;
        bankFile = alHeapAlloc(&auHeap, 1, len);
        auRomRead((u32)auCurrentSettings.bank2Start, bankFile, len);
        alBnkfNew(bankFile, auCurrentSettings.table2Start);
        auSeqBank = bankFile->bankArray[0];
    }

    if ((u32)auCurrentSettings.bank1Start >= 0x80000000U) {
        D_800968B8 = (ALBank*)auCurrentSettings.bank1Start;
    } else {
        len = auCurrentSettings.bank1End - auCurrentSettings.bank1Start;
        bankFile = alHeapAlloc(&auHeap, 1, len);
        auRomRead((u32)auCurrentSettings.bank1Start, bankFile, len);
        alBnkfNew(bankFile, auCurrentSettings.table1Start);
        D_800968B8 = bankFile->bankArray[0];
    }

    // load sequnces
    if ((u32)auCurrentSettings.romSbkStart >= 0x80000000U) {
        auSeqFile = (ALSeqFile*)auCurrentSettings.romSbkStart;
    } else {
        auSeqFile = alHeapAlloc(&auHeap, 1, 4);
        auRomRead((u32)auCurrentSettings.romSbkStart, auSeqFile, 4);
        tmp = auSeqFile->seqCount * sizeof(ALSeqData) + 4;
        len = tmp;
        auSeqFile = alHeapAlloc(&auHeap, 1, len);
        auRomRead(tmp = (u32)auCurrentSettings.romSbkStart, auSeqFile, len);
        alSeqFileNew(auSeqFile, (u8*)auCurrentSettings.romSbkStart);
    }

    // get maximal seq length
    for (i = 0, len = 0; i < auSeqFile->seqCount; i++) {
        auSeqFile->seqArray[i].len += auSeqFile->seqArray[i].len & 1;
        if (len < auSeqFile->seqArray[i].len) {
            len = auSeqFile->seqArray[i].len;
        }
    }

    for (i = 0; i < 2; i++) {
        auBGMSeqData[i] = alHeapAlloc(&auHeap, 1, len);
    }

    auCmdListBuffers[0] = alHeapAlloc(&auHeap, 1, 0x8000);
    auCmdListBuffers[1] = alHeapAlloc(&auHeap, 1, 0x8000);

    auScTasks[0] = alHeapAlloc(&auHeap, 1, sizeof(SCTaskAudio));
    auScTasks[1] = alHeapAlloc(&auHeap, 1, sizeof(SCTaskAudio));

    auDataBuffers[0] = alHeapAlloc(&auHeap, 1, 0xE60);
    auDataBuffers[1] = alHeapAlloc(&auHeap, 1, 0xE60);
    auDataBuffers[2] = alHeapAlloc(&auHeap, 1, 0xE60);
}

void auCreatePlayers(void) {
    ALSynConfig synConfig;
    ALSeqpConfig seqConfig;
    ALSndpConfig sndpConfig;
    s32 i;
    s32 j;

    auHeapBase = auHeap.cur;
    auHeapSize = auHeap.count;

    synConfig.maxVVoices = auCurrentSettings.maxVVoices;
    synConfig.maxPVoices = auCurrentSettings.maxPVoices;
    synConfig.maxUpdates = auCurrentSettings.maxUpdates;
    synConfig.dmaproc = auDMANew;
    synConfig.outputRate = osAiSetFrequency(auCurrentSettings.outputRate);
    synConfig.heap = &auHeap;

    auCurrentFxType = auCurrentSettings.fxType;

    if (auCurrentFxType < AL_FX_CUSTOM) {
        synConfig.fxType = auCurrentFxType;
    } else {
        synConfig.fxType = AL_FX_CUSTOM;
        synConfig.params = auCustomFXParamsTable[auCurrentFxType - AL_FX_CUSTOM];
    }

    alInit(&auGlobals, &synConfig);

    auFrequency = (s32)(synConfig.outputRate / (f32)60) + 1;
    if (auFrequency & 0xf) {
        auFrequency = (auFrequency & ~0xf) + 0x10;
    }

    auSFXPlayer = D_800968B8->instArray[0];

    auSoundPlayer = alHeapAlloc(&auHeap, 1, sizeof(ALSndPlayer));
    auSndpSoundId = alHeapAlloc(&auHeap, 1, auCurrentSettings.numSounds);
    D_800968BC = alHeapAlloc(&auHeap, 1, auCurrentSettings.numSounds * 4);
    auStartingSound = alHeapAlloc(&auHeap, 1, auCurrentSettings.numSounds * 4);
    auSoundPriority = alHeapAlloc(&auHeap, 1, auCurrentSettings.numSounds);
    auSoundIdleCounter = alHeapAlloc(&auHeap, 1, auCurrentSettings.numSounds);
    auSoundPitch = alHeapAlloc(&auHeap, 1, auCurrentSettings.numSounds * 4);
    auSoundVolume = alHeapAlloc(&auHeap, 1, auCurrentSettings.numSounds * 2);
    auSoundPan = alHeapAlloc(&auHeap, 1, auCurrentSettings.numSounds);
    auSoundReverbAmt = alHeapAlloc(&auHeap, 1, auCurrentSettings.numSounds);

    for (i = 0; i < auCurrentSettings.numSounds; i++) {
        D_800968BC[i] = -1;
        auStartingSound[i] = -1;
        auSndpSoundId[i] = -1;
        auSoundPriority[i] = 0;
        auSoundIdleCounter[i] = 255;
        auSoundPitch[i] = 1.0f;
        auSoundVolume[i] = 0x7FFF;
        auSoundPan[i] = 64;
        auSoundReverbAmt[i] = 0;
    }

    sndpConfig.maxEvents = auCurrentSettings.maxEvents;
    sndpConfig.maxSounds = auCurrentSettings.numSounds;
    sndpConfig.heap = &auHeap;
    alSndpNew(auSoundPlayer, &sndpConfig);

    auBGMPlayerStatus = alHeapAlloc(&auHeap, 1, 2);
    auBGMSongId = alHeapAlloc(&auHeap, 1, 8);

    auGlobalSongPriority = auCurrentSettings.unk_13;

    freeOscStateList = alHeapAlloc(&auHeap, sizeof(oscData), OSC_STATE_COUNT);
    for (j = 0; j < OSC_STATE_COUNT - 1; j++) {
        freeOscStateList[j].next = &freeOscStateList[j + 1];
    }
    freeOscStateList[j].next = NULL;

    for (i = 0; i < 2; i++) {
        seqConfig.maxVoices = auCurrentSettings.maxVoices[i];
        seqConfig.maxEvents = auCurrentSettings.maxEvents;
        seqConfig.maxChannels = 16;
        seqConfig.heap = &auHeap;
        seqConfig.initOsc = initOsc;
        seqConfig.updateOsc = updateOsc;
        seqConfig.stopOsc = stopOsc;

        auBGMPlayers[i] = alHeapAlloc(&auHeap, 1, sizeof(ALCSPlayer));
        alCSPNew(auBGMPlayers[i], &seqConfig);
        alCSPSetBank(auBGMPlayers[i], auSeqBank);
        auBGMSequences[i] = alHeapAlloc(&auHeap, 1, sizeof(ALCSeq));
        auBGMPlayerStatus[i] = 0;
        auBGMSongId[i] = -1;
        auBGMVolTimer[i] = 0;
        auBGMVolume[i] = 32512.0f;
        auSongVolRate[i] = 0.0f;
    }
}

void auThreadMain(UNUSED void* arg) {
    s32 i;
    s32 j;
    s32 bufferIndex;
    s32 sp70 = 0;
    s32 startTime;

    auInit();
    auCurrentSettings = auPublicSettings;
    auLoadAssets();
    auCreatePlayers();
    auPublicSettings = auCurrentSettings;
    osSendMesg(&gThreadingQueue, (OSMesg)1, OS_MESG_NOBLOCK);

    while (TRUE) {
        startTime = osGetCount();
        i = auFrameCounter & 1;
        auTask = auScTasks[i];
        auCmdListPtr = auCmdListBuffers[i];

        bufferIndex = auFrameCounter % 3;
        auSampleCount[bufferIndex] = 16 + (auFrequency - sp70 + AUDIO_EXTRA_SAMPLES) & ~0x0f;
        if (auSampleCount[bufferIndex] < auFrequency - 16) {
            auSampleCount[bufferIndex] = auFrequency - 16;
        }

        D_80096968 = osGetTime();
        auCmdListPtr = alAudioFrame(auCmdListPtr, &j, (s16*)osVirtualToPhysical(auDataBuffers[bufferIndex]), auSampleCount[bufferIndex]);

        auTask->info.type = SC_TASK_TYPE_AUDIO;
        auTask->info.priority = 80;
        auTask->info.fnCheck = NULL;
        auTask->info.unk18 = 1;
        auTask->info.retVal = 0;
        auTask->info.mq = &auSPTaskMessageQueue;

        auTask->task.t.type = M_AUDTASK;
        auTask->task.t.flags = 0;
        auTask->task.t.data_ptr = (u64*)auCmdListBuffers[i];
        auTask->task.t.data_size = (auCmdListPtr - auCmdListBuffers[i]) * sizeof(Acmd);
        auTask->task.t.ucode_boot = gRspBootCode;
        auTask->task.t.ucode_boot_size = sizeof(gRspBootCode);
        auTask->task.t.ucode = (u64*)aspMainTextStart;
        auTask->task.t.ucode_size = 0x1000;
        auTask->task.t.ucode_data = (u64*)aspMainDataStart;
        auTask->task.t.ucode_data_size = 0x800;
        auTask->task.t.dram_stack = NULL;
        auTask->task.t.dram_stack_size = 0;
        auTask->task.t.yield_data_ptr = NULL;
        auTask->task.t.yield_data_size = 0;
        auTask->task.t.output_buff = NULL;
        auTask->task.t.output_buff_size = NULL;

        D_80096250 = (osGetCount() - startTime) / 2971;
        // wait for next game tick
        osRecvMesg(&auGameTickQueue, NULL, OS_MESG_BLOCK);

        sp70 = IO_READ(AI_LEN_REG) >> 2;
        // wait until sp task is done
        osRecvMesg(&auSPTaskMessageQueue, NULL, OS_MESG_BLOCK);

        bufferIndex = (auFrameCounter - 1) % 3;
        if (auSoundQuality == 0) {
            // deliberately reduce the sampling rate by half
            for (i = 0; i < 2 * auSampleCount[bufferIndex]; i += 2) {
                j = (auDataBuffers[bufferIndex][i] + auDataBuffers[bufferIndex][i + 1]) / 2;
                auDataBuffers[bufferIndex][i] = j;
                auDataBuffers[bufferIndex][i + 1] = j;
            }
        }

        osWritebackDCacheAll();
        osAiSetNextBuffer(auDataBuffers[bufferIndex], auSampleCount[bufferIndex] << 2);

        for (i = 0; i < nextDMA; i++) {
            osRecvMesg(&auDMAMessageQueue, NULL, OS_MESG_NOBLOCK);
        }

        osWritebackDCacheAll();
        osSendMesg(&scTaskQueue, (OSMesg)auTask, OS_MESG_NOBLOCK);
        auFrameCounter++;
        nextDMA = 0;

        // update sfx player
        for (i = 0; i < auCurrentSettings.numSounds; i++) {
            if (auSndpSoundId[i] == -1) {
                if (auStartingSound[i] >= 0) {
                    N_ALSoundState* sState;
                    auSndpSoundId[i] = alSndpAllocate(auSoundPlayer, auSFXPlayer->soundArray[auStartingSound[i]]);
                    alSndpSetSound(auSoundPlayer, auSndpSoundId[i]);
                    sState = auSoundPlayer->sndState;
                    sState[auSndpSoundId[i]].pitch = auSoundPitch[i];
                    sState[auSndpSoundId[i]].pan = auSoundPan[i];
                    sState[auSndpSoundId[i]].fxMix = auSoundReverbAmt[i] + auGlobalSoundReverbAmt;
                    sState[auSndpSoundId[i]].vol =
                        (auSoundVolume[i] * sState[auSndpSoundId[i]].sound->sampleVolume * auGlobalSoundVolume) >> 14;
                    alSndpPlay(auSoundPlayer);
                    alSndpSetPriority(auSoundPlayer, auSndpSoundId[i], auSoundPriority[i]);
                    auStartingSound[i] = -1;
                }
            } else {
                alSndpSetSound(auSoundPlayer, auSndpSoundId[i]);
                if (alSndpGetState(auSoundPlayer) == AL_STOPPED) {
                    alSndpDeallocate(auSoundPlayer, auSndpSoundId[i]);
                    auSndpSoundId[i] = -1;
                    D_800968BC[i] = -1;
                }
            }
        }

        // update BGM Players
        for (i = 0; i < 2; i++) {
            switch (auBGMPlayerStatus[i]) {
                case 1:
                    if (auBGMPlayers[i]->state != AL_STOPPED) {
                        alCSPStop(auBGMPlayers[i]);
                    } else {
                        if (auBGMSongId[i] < 0) {
                            auBGMPlayerStatus[i]--;
                        } else {
                            auRomRead((u32)auSeqFile->seqArray[auBGMSongId[i]].offset, auBGMSeqData[i],
                                      auSeqFile->seqArray[auBGMSongId[i]].len);
                            auBGMPlayerStatus[i]++;
                        }
                    }
                    break;
                case 2:
                    alCSeqNew(auBGMSequences[i], auBGMSeqData[i]);
                    alCSPSetSeq(auBGMPlayers[i], auBGMSequences[i]);
                    alCSPPlay(auBGMPlayers[i]);
                    for (j = 0; j < 16; j++) {
                        alCSPSetChlPriority(auBGMPlayers[i], j, auGlobalSongPriority);
                    }
                    auBGMPlayerStatus[i]++;
                    break;
                case 3:
                    if (auBGMPlayers[i]->state == AL_STOPPED) {
                        auBGMPlayerStatus[i] = 0;
                        auBGMSongId[i] = -1;
                    }
                    break;
            }
        }

        // update volume controller
        for (i = 0; i < 2; i++) {
            if (auBGMVolTimer[i] != 0) {
                auBGMVolTimer[i]--;
                auBGMVolume[i] += auSongVolRate[i];
                if (auBGMVolume[i] < 0.0f) {
                    auBGMVolume[i] = 0.0f;
                } else if (auBGMVolume[i] > 32512.0f) {
                    auBGMVolume[i] = 32512.0f;
                }
                alCSPSetVol(auBGMPlayers[i], auBGMVolume[i]);
            }
        }

        if (auSettingsUpdated) {
            j = auCurrentSettings.numSounds + 2;
            for (i = 0; i < auCurrentSettings.numSounds; i++) {
                if (auSndpSoundId[i] == -1) {
                    j--;
                }
            }

            for (i = 0; i < 2; i++) {
                if (auBGMPlayerStatus[i] == 0) {
                    j--;
                }
            }

            if (j == 0) {
                // everything is stopped
                // wait until sp task is done
                osRecvMesg(&auSPTaskMessageQueue, NULL, OS_MESG_BLOCK);
                osSendMesg(&auSPTaskMessageQueue, (OSMesg)0, OS_MESG_BLOCK);
                alClose(&auGlobals);
                // reload everything
                auCurrentSettings = auPublicSettings;
                auLoadAssets();
                auCreatePlayers();
                auPublicSettings = auCurrentSettings;
                auSettingsUpdated = FALSE;
                sp70 = 0;
                osSendMesg(&gThreadingQueue, (OSMesg)1, OS_MESG_NOBLOCK);
            } else {
                auStopBGM();
                auStopAllSounds();
            }
        }

        if (auRestarting) {
            j = auCurrentSettings.numSounds + 2;
            for (i = 0; i < auCurrentSettings.numSounds; i++) {
                if (auSndpSoundId[i] == -1) {
                    j--;
                }
            }

            for (i = 0; i < 2; i++) {
                if (auBGMPlayerStatus[i] == 0) {
                    j--;
                }
            }

            if (j == 0) {
                osRecvMesg(&auSPTaskMessageQueue, NULL, OS_MESG_BLOCK);
                osSendMesg(&auSPTaskMessageQueue, (OSMesg)0, OS_MESG_BLOCK);
                alClose(&auGlobals);
                // don't reload assets
                // reset heap
                auHeap.cur = auHeapBase;
                auHeap.count = auHeapSize;

                auCreatePlayers();
                auPublicSettings = auCurrentSettings;
                auRestarting = 0;
                sp70 = IO_READ(AI_LEN_REG) >> 2;
            } else {
                auStopBGM();
                auStopAllSounds();
            }
        }
    }
}

void auSetHighSoundQuality(void) {
    auSoundQuality = 1;
}

void auSetLowSoundQuality(void) {
    auSoundQuality = 0;
}

void auSetSoundQuality(s32 quality) {
    auSoundQuality = quality;
}

void auSetReverbType(s32 fxType) {
    if (fxType != auCurrentFxType) {
        auRestarting++;
        auCurrentSettings.fxType = fxType;
    }
}

void auStopBGM(void) {
    s32 i;

    for (i = 0; i < 2; i++) {
        auStopSong(i);
    }
}

u32 auPlaySong(s32 playerID, u32 songID) {
    if (songID < auSeqFile->seqCount) {
        OSIntMask mask = osSetIntMask(OS_IM_NONE);
        auBGMPlayerStatus[playerID] = 1;
        auBGMSongId[playerID] = songID;
        osSetIntMask(mask);
        return songID;
    } else {
        return -1;
    }
}

void auStopSong(s32 playerId) {
    OSIntMask mask = osSetIntMask(OS_IM_NONE);
    auBGMPlayerStatus[playerId] = 1;
    auBGMSongId[playerId] = -1;
    osSetIntMask(mask);
}

void auSetBGMVolume(s32 playerID, u32 vol) {
    if (vol > 0x7F00) {
        vol = 0x7F00;
    }

    alCSPSetVol(auBGMPlayers[playerID], vol);
    auBGMVolume[playerID] = vol;
    auBGMVolTimer[playerID] = 0;
}

void auSetBGMVolumeSmooth(s32 playerID, u32 vol, u32 time) {
    if (vol > 0x7F00) {
        vol = 0x7F00;
    }

    if (time != 0) {
        auBGMVolTimer[playerID] = time;
        auSongVolRate[playerID] = (vol - auBGMVolume[playerID]) / time;
    } else {
        auSetBGMVolume(playerID, vol);
    }
}

void auSetBGMReverb(s32 playerID, u32 reverb) {
    s32 i;

    if (reverb > 127) {
        reverb = 127;
    }

    for (i = 0; i < 16; i++) {
        alCSPSetChlFXMix(auBGMPlayers[playerID], i, reverb);
    }
}

void auSetBGMPriority(s32 playerID, u8 priority) {
    s32 i;

    if (priority > 127) {
        priority = 127;
    }
    auGlobalSongPriority = priority;

    for (i = 0; i < 16; i++) {
        alCSPSetChlPriority(auBGMPlayers[playerID], i, priority);
    }
}

s32 auIsBGMPlaying(s32 playerID) {
    if (auBGMPlayerStatus[playerID] != 0 && auBGMSongId[playerID] >= 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}

void auSetBGMExtraReverb(s32 playerID, s8 arg1) {
    alCSPSetPlayerFXMix(auBGMPlayers[playerID], arg1);
}

void auSetBGMChannelVolume(s32 playerID, u8 chan, s8 arg2) {
    alCSPSetChlExtraVol(auBGMPlayers[playerID], chan, arg2);
}

void auSetBGMTempo(s32 playerID, s32 tempo) {
    alCSPSetTempo(auBGMPlayers[playerID], tempo);
}

s32 auGetBGMTempo(s32 playerID) {
    return alCSPGetTempo(auBGMPlayers[playerID]);
}

s32 auStealSound(u8 priority) {
    s32 i;
    s32 t0 = 0;
    s32 ret = -1;

    for (i = 0; i < auCurrentSettings.numSounds; i++) {
        if (auSndpSoundId[i] < 0 && auStartingSound[i] < 0) {
            // free slot
            return i;
        }
    }

    for (i = 0; i < auCurrentSettings.numSounds; i++) {
        if (auSoundPriority[i] < priority) {
            priority = auSoundPriority[i];
            ret = i;
            t0 = auSoundIdleCounter[i];
        } else if (auSoundPriority[i] == priority) {
            if (t0 < auSoundIdleCounter[i]) {
                t0 = auSoundIdleCounter[i];
                ret = i;
            }
        }
    }

    if (ret >= 0) {
        OSIntMask mask = osSetIntMask(OS_IM_NONE);
        alSndpSetSound(auSoundPlayer, auSndpSoundId[ret]);
        alSndpStop(auSoundPlayer);
        osSetIntMask(mask);
    }

    return ret;
}

s32 auPlaySound(u32 soundID) {
    s32 i;

    for (i = 0; i < auCurrentSettings.numSounds; i++) {
        if (auSoundIdleCounter[i] < 255) {
            auSoundIdleCounter[i]++;
        }
    }

    if (soundID < auSFXPlayer->soundCount) {
        i = auStealSound(auSoundPriorities[soundID]);
        if (i >= 0) {
            OSIntMask mask = osSetIntMask(OS_IM_NONE);
            D_800968BC[i] = soundID;
            auStartingSound[i] = soundID;
            auSoundIdleCounter[i] = 0;
            auSoundPriority[i] = auSoundPriorities[soundID];
            auSoundPitch[i] = 1.0f;
            auSoundVolume[i] = 0x7FFF;
            auSoundPan[i] = 64;
            auSoundReverbAmt[i] = 0;
            osSetIntMask(mask);
        }
        return i;
    } else {
        return -1;
    }
}

s32 auPlaySoundWithParams(u32 soundID, s32 volume, s32 pan, f32 pitch, s32 reverbAmt) {
    s32 i;
    OSIntMask mask = osSetIntMask(OS_IM_NONE);

    i = auPlaySound(soundID);

    if (i >= 0) {
        auSoundPitch[i] = pitch;
        auSoundVolume[i] = volume;
        auSoundPan[i] = pan;
        auSoundReverbAmt[i] = reverbAmt;
        osSetIntMask(mask);
        return i;
    } else {
        osSetIntMask(mask);
        return -1;
    }
}

void auStopAllSounds(void) {
    s32 i;
    OSIntMask mask = osSetIntMask(OS_IM_NONE);

    for (i = 0; i < auCurrentSettings.numSounds; i++) {
        if (auSndpSoundId[i] != -1) {
            alSndpSetSound(auSoundPlayer, auSndpSoundId[i]);
            alSndpStop(auSoundPlayer);
        }
        D_800968BC[i] = -1;
        auStartingSound[i] = -1;
    }
    osSetIntMask(mask);
}

void func_80022C0C(u32 arg0) {
    if (arg0 > 0x7F00) {
        arg0 = 0x7F00;
    }
    D_800423E0 = arg0;
}

void auSetSoundVolume(s32 handle, u32 vol) {
    if (auSndpSoundId[handle] != -1) {
        OSIntMask mask = osSetIntMask(OS_IM_NONE);
        alSndpSetSound(auSoundPlayer, auSndpSoundId[handle]);
        if (alSndpGetState(auSoundPlayer) == AL_PLAYING || auStartingSound[handle] >= 0) {
            if (vol > 0x7FFF) {
                vol = 0x7FFF;
            }
            auSoundVolume[handle] = vol;
            vol = (vol * ((N_ALSoundState*)auSoundPlayer->sndState)[auSndpSoundId[handle]].sound->sampleVolume * auGlobalSoundVolume) >>
                  14;
            alSndpSetVol(auSoundPlayer, vol);
        }
        osSetIntMask(mask);
    }
}

void auSetSoundPan(s32 handle, u32 pan) {
    if (auSndpSoundId[handle] != -1) {
        OSIntMask mask = osSetIntMask(OS_IM_NONE);
        alSndpSetSound(auSoundPlayer, auSndpSoundId[handle]);
        if (alSndpGetState(auSoundPlayer) == AL_PLAYING || auStartingSound[handle] >= 0) {
            if (pan > 127) {
                pan = 127;
            }
            alSndpSetPan(auSoundPlayer, pan);
        }
        osSetIntMask(mask);
    }
}

void auSetSoundReverb(s32 arg0, u32 arg1) {
    if (auSndpSoundId[arg0] != -1) {
        OSIntMask mask = osSetIntMask(OS_IM_NONE);
        alSndpSetSound(auSoundPlayer, auSndpSoundId[arg0]);
        if (alSndpGetState(auSoundPlayer) == AL_PLAYING || auStartingSound[arg0] >= 0) {
            if (arg1 > 127) {
                arg1 = 127;
            }
            alSndpSetFXMix(auSoundPlayer, arg1);
        }
        osSetIntMask(mask);
    }
}

void auSetSoundPitch(s32 i, f32 arg1) {
    if (auSndpSoundId[i] != -1) {
        OSIntMask mask = osSetIntMask(OS_IM_NONE);
        alSndpSetSound(auSoundPlayer, auSndpSoundId[i]);
        if (alSndpGetState(auSoundPlayer) == AL_PLAYING || auStartingSound[i] >= 0) {
            if (arg1 > 2.0) {
                arg1 = 2.0;
            }
            alSndpSetPitch(auSoundPlayer, arg1);
        }
        osSetIntMask(mask);
    }
}

void auStopSound(s32 i) {
    if (auSndpSoundId[i] != -1) {
        OSIntMask mask = osSetIntMask(OS_IM_NONE);
        alSndpSetSound(auSoundPlayer, auSndpSoundId[i]);
        alSndpStop(auSoundPlayer);
        osSetIntMask(mask);
    }
    D_800968BC[i] = -1;
    auStartingSound[i] = -1;
}

void auSetSoundPriority(s32 i, u8 priority) {
    if (auSndpSoundId[i] != -1) {
        auSoundPriority[i] = priority;
        alSndpSetPriority(auSoundPlayer, auSndpSoundId[i], priority);
    }
}

void func_800230DC(void) {
    auSettingsUpdated = TRUE;
}

s32 func_800230EC(void) {
    return auSettingsUpdated;
}

s32 func_800230F8(void) {
    return auRestarting;
}

s32 func_80023104(void) {
    return auRestarting | auSettingsUpdated;
}

void func_8002311C(void) {
    osRecvMesg(&gThreadingQueue, NULL, OS_MESG_NOBLOCK);
    auSettingsUpdated = 1;
    osRecvMesg(&gThreadingQueue, NULL, OS_MESG_BLOCK);
}

s32 func_80023168(u32 soundID, u32 reverbAmt) {
    s32 i;

    for (i = 0; i < auCurrentSettings.numSounds; i++) {
        if (auSoundIdleCounter[i] < 255) {
            auSoundIdleCounter[i]++;
        }
    }

    if (soundID < auSFXPlayer->soundCount) {
        i = auStealSound(auSoundPriorities[soundID]);
        if (i >= 0) {
            OSIntMask mask = osSetIntMask(OS_IM_NONE);
            D_800968BC[i] = soundID;
            auStartingSound[i] = soundID;
            auSoundIdleCounter[i] = 0;
            auSoundPriority[i] = auSoundPriorities[soundID];
            auSoundPitch[i] = 1.0f;
            auSoundVolume[i] = 0x7FFF;
            auSoundPan[i] = 64;
            if (reverbAmt > 127) {
                reverbAmt = 127;
            }
            auSoundReverbAmt[i] = reverbAmt;
            osSetIntMask(mask);
        }
        return i;
    } else {
        return -1;
    }
}

s32 auPlaySoundWithVolume(u32 soundID, u32 vol) {
    s32 i;

    for (i = 0; i < auCurrentSettings.numSounds; i++) {
        if (auSoundIdleCounter[i] < 255) {
            auSoundIdleCounter[i]++;
        }
    }

    if (soundID < auSFXPlayer->soundCount) {
        i = auStealSound(auSoundPriorities[soundID]);
        if (i >= 0) {
            OSIntMask mask = osSetIntMask(OS_IM_NONE);
            D_800968BC[i] = soundID;
            auStartingSound[i] = soundID;
            auSoundIdleCounter[i] = 0;
            auSoundPriority[i] = auSoundPriorities[soundID];
            auSoundPitch[i] = 1.0f;
            auSoundVolume[i] = vol;
            auSoundPan[i] = 64;
            auSoundReverbAmt[i] = 0;
            osSetIntMask(mask);
        }
        return i;
    } else {
        return -1;
    }
}

void auSetSoundGlobalVolume(u8 arg0) {
    UNUSED s32 temp;
    s32 i;
    OSIntMask mask;

    if (arg0 > 127) {
        arg0 = 127;
    }

    auGlobalSoundVolume = arg0;
    mask = osSetIntMask(OS_IM_NONE);
    for (i = 0; i < auCurrentSettings.numSounds; i++) {
        if (auSndpSoundId[i] != -1) {
            alSndpSetSound(auSoundPlayer, auSndpSoundId[i]);
            if (alSndpGetState(auSoundPlayer) == AL_PLAYING || auStartingSound[i] >= 0) {
                s32 vol = (auSoundVolume[i] * ((N_ALSoundState*)auSoundPlayer->sndState)[auSndpSoundId[i]].sound->sampleVolume *
                           auGlobalSoundVolume) >>
                          14;
                alSndpSetVol(auSoundPlayer, vol);
            }
        }
    }
    osSetIntMask(mask);
}

void auSetCurrentSoundsGlobalVolume(u8 arg0) {
    UNUSED s32 temp;
    s32 i;
    OSIntMask mask;

    mask = osSetIntMask(OS_IM_NONE);
    for (i = 0; i < auCurrentSettings.numSounds; i++) {
        if (auSndpSoundId[i] != -1) {
            alSndpSetSound(auSoundPlayer, auSndpSoundId[i]);
            if (alSndpGetState(auSoundPlayer) == AL_PLAYING || auStartingSound[i] >= 0) {
                alSndpSetVol(auSoundPlayer,
                             (auSoundVolume[i] *
                              ((N_ALSoundState*)auSoundPlayer->sndState)[auSndpSoundId[i]].sound->sampleVolume * arg0) >>
                                 14);
            }
        }
    }
    osSetIntMask(mask);
}

void auSetCurrentSoundsGlobalReverb(u8 arg0) {
    s32 i;
    OSIntMask mask;

    if (arg0 > 127) {
        arg0 = 127;
    }

    mask = osSetIntMask(OS_IM_NONE);
    for (i = 0; i < auCurrentSettings.numSounds; i++) {
        if (auSndpSoundId[i] != -1) {
            alSndpSetSound(auSoundPlayer, auSndpSoundId[i]);
            if (alSndpGetState(auSoundPlayer) == AL_PLAYING || auStartingSound[i] >= 0) {
                alSndpSetFXMix(auSoundPlayer, arg0);
            }
        }
    }
    osSetIntMask(mask);
}

void auSetSoundGlobalReverb(u8 arg0) {
    UNUSED s32 temp;
    s32 i;
    OSIntMask mask;

    if (arg0 > 127) {
        arg0 = 127;
    }

    mask = osSetIntMask(OS_IM_NONE);
    for (i = 0; i < auCurrentSettings.numSounds; i++) {
        if (auSndpSoundId[i] != -1) {
            alSndpSetSound(auSoundPlayer, auSndpSoundId[i]);
            if (alSndpGetState(auSoundPlayer) == AL_PLAYING || auStartingSound[i] >= 0) {
                u8 a1 = auSoundReverbAmt[i] + arg0;
                if (a1 > 127) {
                    a1 = 127;
                }
                alSndpSetFXMix(auSoundPlayer, a1);
            }
        }
    }
    auGlobalSoundReverbAmt = arg0;
    osSetIntMask(mask);
}

ALBank* func_800239CC(void) {
    return D_800968B8;
}
