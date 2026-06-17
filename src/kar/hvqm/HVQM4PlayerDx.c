#include "dolphin/types.h"

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
void IpicBlockDec(void* obj, u8* outbuf, s32 stride, HVQM4IpicContext* ctx);

extern s32* lbl_80533FC0[];
extern u32 lbl_805B5448[];

#pragma push
#pragma dont_inline on
void IpicLineDec(void* obj, u8* outbuf, s32 stride, HVQM4IpicContext* ctx,
                 s32 blocks)
{
    u16* code_ptr;

    ctx->current = *ctx->code_ptr;
    ctx->previous = *(u8*) ctx->code_ptr;
    blocks--;

    while (blocks > 0) {
        ctx->left = ctx->current;
        code_ptr = ctx->code_ptr + 1;
        ctx->code_ptr = code_ptr;
        ctx->current = *code_ptr;
        IpicBlockDec(obj, outbuf, stride, ctx);
        outbuf += 4;
        blocks--;
    }

    ctx->left = ctx->current;
    ctx->code_ptr = (u16*) ((u8*) ctx->code_ptr + 6);
    IpicBlockDec(obj, outbuf, stride, ctx);
    ctx->left_ptr += 4;
    ctx->upper_ptr += 4;
}

// NONMATCHING: flow verified against 80461C64; remaining diff is regalloc.
void IpicPlaneDec(void* obj, s32 plane, u8* outbuf)
{
    HVQM4IpicContext ctx;
    HVQM4PlaneDesc* desc = (HVQM4PlaneDesc*) ((u8*) obj + plane * 0x38);
    u32 stride = desc->stride;
    u32 row_stride = stride * 4;
    s32 rows = desc->blocks_y;
    u32 upper_offset = desc->upper_offset;
    u32 blocks = desc->blocks_x;
    u32 middle_stride;
    u8* data;

    ctx.unk0 = (void*) plane;
    data = desc->data;
    ctx.left_ptr = data;
    ctx.code_ptr = (u16*) data;
    ctx.upper_ptr = data + upper_offset * 2;

    if (rows > 0) {
        IpicLineDec(obj, outbuf, stride, &ctx, blocks);
        outbuf += row_stride;
        rows--;
    }

    ctx.left_ptr = desc->data;
    middle_stride = stride;
    while (rows > 1) {
        IpicLineDec(obj, outbuf, middle_stride, &ctx, blocks);
        outbuf += row_stride;
        rows--;
    }

    if (rows > 0) {
        ctx.upper_ptr = (u8*) ctx.code_ptr;
        IpicLineDec(obj, outbuf, stride, &ctx, blocks);
    }
}
#pragma pop

void HVQM4InitSeqObj(HVQM4SeqObj* obj, HVQM4VideoInfo* header)
{
    obj->frame_width = header->width;
    obj->frame_height = header->height;
    obj->h_samp = header->h_samp;
    obj->v_samp = header->v_samp;
}

u32 HVQM4BuffSize(HVQM4SeqObj* obj)
{
    u32 luma_width = (u32) obj->frame_width >> 2;
    u32 chroma_width = luma_width;
    u32 luma_height;
    u32 chroma_height;

    if (obj->h_samp == 2) {
        chroma_width = (s32) luma_width >> 1;
    }

    luma_height = (u32) obj->frame_height >> 2;
    luma_width += 2;
    chroma_width += 2;
    luma_width *= luma_height + 2;

    chroma_height = luma_height;
    if (obj->v_samp == 2) {
        chroma_height = (s32) luma_height >> 1;
    }

    chroma_width *= chroma_height + 2;
    return ((luma_width + chroma_width * 2) * 2) + 0x81A0;
}

void HVQM4DecodePpic(HVQM4SeqObj* obj, void* code, void* outbuf, void* ref1)
{
    HVQM4DecodeBpic(obj, code, outbuf, ref1, outbuf);
}

#pragma push
#pragma dont_inline on
void HVQM4DecodePcm16Ch1(u8* recd, u8* outp, u32 rec_size, s32 samples,
                         s32 track)
{
    s32 offset = samples << 1;
    offset *= track;
    recd += offset;

    while (samples > 0) {
        u8 byte = *recd++;
        outp[2] = byte;
        outp[0] = byte;

        byte = *recd++;
        outp[3] = byte;
        outp[1] = byte;

        outp += 4;
        samples--;
    }
}

void HVQM4DecodePcm16Ch2(u8* recd, u8* outp, u32 rec_size, s32 samples,
                         s32 track)
{
    s32 offset = samples << 2;
    offset *= track;
    recd += offset;

    while (samples > 0) {
        outp[0] = recd[0];
        outp[1] = recd[1];
        outp[2] = recd[2];
        outp[3] = recd[3];
        recd += 4;
        outp += 4;
        samples--;
    }
}
#pragma pop

void HVQM4DecodeAdp8xCh2(u32* state, u8* recd, u8* outp, u32 rec_size,
                         u32 samples, s32 track)
{
    s32 left;
    u8* data;
    u32 offset;
    s32 has_header;
    s32 right;

    if (recd == NULL) {
        return;
    }

    has_header = (rec_size >> 7) & 1;
    rec_size = (u32) lbl_80533FC0[rec_size & 3];
    offset = samples * 2;
    if (has_header) {
        offset += 4;
        lbl_805B5448[0] = track;
    }

    offset *= lbl_805B5448[0];
    data = recd + offset;

    if (has_header) {
        state[0] = (s16) ((data[0] << 8) | data[1]);
        state[2] = (s16) ((data[2] << 8) | data[3]);
        data += 4;
    }

    left = state[0];
    right = state[2];
    while (samples > 0) {
        left += ((s32*) rec_size)[data[0]];
        if (left < -0x8000) {
            left = -0x8000;
        }
        if (left > 0x7FFF) {
            left = 0x7FFF;
        }
        ((s16*) outp)[1] = left;

        right += ((s32*) rec_size)[data[1]];
        if (right < -0x8000) {
            right = -0x8000;
        }
        if (right > 0x7FFF) {
            right = 0x7FFF;
        }
        ((s16*) outp)[0] = right;

        data += 2;
        outp += 4;
        samples--;
    }

    state[0] = left;
    state[2] = right;
}

HVQM4DecSound* HVQM4DecSoundCreate(HVQM4AudioInfo* info)
{
    HVQM4DecSound* handle = HVQM4Alloc(sizeof(HVQM4DecSound));
    if (handle == NULL) {
        return NULL;
    }

    handle->info = *info;
    handle->format = handle->info.format;
    return handle;
}

BOOL HVQM4DecSoundClose(HVQM4DecSound* handle)
{
    if (handle == NULL) {
        return FALSE;
    }

    HVQM4Free(handle);
    return TRUE;
}

u32 HVQM4DecSoundDecode(HVQM4DecSound* handle, HVQM4RecHeader* rech,
                        u32 samples, void* recd, s32 track, void* outp)
{
    u32 decoded_size;
    u32 decode_samples;
    u32 format;
    u32 rec_size;

    if (handle == NULL) {
        return 0;
    }
    if (outp == NULL) {
        return 0;
    }

    format = handle->info.format;
    rec_size = rech->audio_size;
    decode_samples = samples;
    if (format & 0x80) {
        decode_samples = samples >> 1;
    }

    if (handle->info.channels == 1) {
        decoded_size = samples * 4;
        switch (format & 0x7F) {
        case 0:
            HVQM4DecodeAdpcmCh1(handle->state, recd, outp, rec_size,
                                decode_samples, track);
            break;
        case 1:
            HVQM4DecodePcm16Ch1(recd, outp, rec_size, decode_samples, track);
            break;
        default:
            decoded_size = 0;
            break;
        }
    } else {
        decoded_size = samples * 4;
        switch (format & 0x7F) {
        case 0:
            HVQM4DecodeAdpcmCh2(handle->state, recd, outp, rec_size,
                                decode_samples, track);
            break;
        case 1:
            HVQM4DecodePcm16Ch2(recd, outp, rec_size, decode_samples, track);
            break;
        case 4:
            HVQM4DecodeAdp8xCh2(handle->state, recd, outp, rec_size,
                                decode_samples, track);
            break;
        default:
            decoded_size = 0;
            break;
        }
    }

    return decoded_size;
}

u32 HVQM4DecSoundMaxDecodeSize(HVQM4DecSound* handle, u32 max_audio_record_size,
                               u32 tracks)
{
    u32 format;
    u32 bytes_per_sample;
    u32 size;

    if (handle == NULL) {
        return 0;
    }
    if (max_audio_record_size == 0) {
        return 0;
    }
    if (tracks == 0) {
        return 0;
    }

    format = handle->format;
    switch (format & 0x7F) {
    case 0:
        bytes_per_sample = 4;
        break;
    case 1:
        bytes_per_sample = 16;
        break;
    case 4:
        bytes_per_sample = 8;
        break;
    default:
        bytes_per_sample = 4;
        break;
    }

    size = (max_audio_record_size * 8) / bytes_per_sample;
    size += 2;
    size /= tracks;
    if (handle->info.channels == 1) {
        size *= 2;
    }
    size *= 2;
    size += 0x1F;
    size &= ~0x1F;
    if (format & 0x80) {
        size *= 2;
    }

    return size;
}
