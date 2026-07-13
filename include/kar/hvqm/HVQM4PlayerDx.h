#ifndef KAR_HVQM_HVQM4PLAYERDX_H
#define KAR_HVQM_HVQM4PLAYERDX_H

#include <dolphin/types.h>

typedef struct HVQM4AudioInfo {
    u8 channels;
    u8 reserved1;
    u8 format;
    u8 reserved3;
    u32 samples_per_sec;
} HVQM4AudioInfo;

typedef struct HVQM4RecHeader {
    u16 video_size;
    u16 audio_size;
} HVQM4RecHeader;

typedef struct HVQM4VideoInfo {
    u16 width;
    u16 height;
    u8 h_samp;
    u8 v_samp;
} HVQM4VideoInfo;

typedef struct HVQM4SeqObj {
    void* ws;
    u16 frame_width;
    u16 frame_height;
    u8 h_samp;
    u8 v_samp;
} HVQM4SeqObj;

typedef struct HVQM4DecSound {
    HVQM4AudioInfo info;
    u32 state[6];
    u32 format;
} HVQM4DecSound;

typedef struct HVQM4IpicContext {
    void* unk0;
    u8* left_ptr;
    u16* code_ptr;
    u8* upper_ptr;
    u16 current;
    u16 left;
    u8 previous;
} HVQM4IpicContext;

typedef struct HVQM4PlaneDesc {
    u8 pad0[4];
    u8* data;
    u16 blocks_x;
    u16 blocks_y;
    u16 upper_offset;
    u8 padE[0x28 - 0xE];
    u16 stride;
} HVQM4PlaneDesc;

typedef struct HVQM4BitStream {
    u32* input;
    void* unk4;
    u32 cache;
    s32 bit;
    s32* tree;
} HVQM4BitStream;

typedef struct HVQM4StreamCursor {
    void* base;
    u32 size;
    void* current;
    u32 offset;
} HVQM4StreamCursor;

void* HVQM4Alloc(u32 size);
void HVQM4Free(void* ptr);
void HVQM4DecodeAdpcmCh1(u32* state, void* recd, void* outp, u32 rec_size,
                         u32 samples, s32 track);
void HVQM4DecodeAdpcmCh2(u32* state, void* recd, void* outp, u32 rec_size,
                         u32 samples, s32 track);
void HVQM4DecodeAdp8xCh2(u32* state, u8* recd, u8* outp, u32 rec_size,
                         u32 samples, s32 track);
void HVQM4DecodeBpic(HVQM4SeqObj* obj, void* code, void* outbuf, void* ref2,
                     void* ref1);
void HVQM4DecodePpic(HVQM4SeqObj* obj, void* code, void* outbuf, void* ref1);
void HVQM4InitSeqObj(HVQM4SeqObj* obj, HVQM4VideoInfo* header);
u32 HVQM4BuffSize(HVQM4SeqObj* obj);
HVQM4DecSound* HVQM4DecSoundCreate(HVQM4AudioInfo* info);
BOOL HVQM4DecSoundClose(HVQM4DecSound* handle);
u32 HVQM4DecSoundDecode(HVQM4DecSound* handle, HVQM4RecHeader* rech,
                        u32 samples, void* recd, s32 track, void* outp);
u32 HVQM4DecSoundMaxDecodeSize(HVQM4DecSound* handle, u32 max_audio_record_size,
                               u32 tracks);
void IpicBlockDec(void* obj, u8* outbuf, s32 stride, HVQM4IpicContext* ctx);
s16 _readTree(s32* tree, HVQM4BitStream* stream);

#endif
