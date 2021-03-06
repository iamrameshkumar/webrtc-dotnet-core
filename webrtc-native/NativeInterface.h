#pragma once

// TODO: Split this into a pixel-format and codec; 
// need to figure out how to pick a different codec in the factory.
enum class VideoFrameFormat
{
    RGBA32,
    BGRA32,
    ARGB32,
    ABGR32,
    CpuTexture,
    GpuTextureD3D11
};

// Definitions of callback functions.
typedef void(*IncomingVideoFrameCallback)(
    const void* texture,
    const uint8_t* data_y,
    const uint8_t* data_u,
    const uint8_t* data_v,
    const uint8_t* data_a,
    int stride_y,
    int stride_u,
    int stride_v,
    int stride_a,
    uint32_t width,
    uint32_t height,
    uint64_t timeStampUS);

typedef void(*LocalDataChannelReadyCallback)(const char* label);

typedef void(*DataAvailableCallback)(const char* label, const uint8_t* data, int length, bool is_binary);

typedef void(*FailureCallback)(const char* msg);

typedef void(*LocalSdpReadyToSendCallback)(const char* type, const char* sdp);

typedef void(*IceCandidateReadyToSendCallback)(const char* candidate,
    const int sdp_mline_index,
    const char* sdp_mid);

typedef void(*AudioBusReadyCallback)(const void* audio_data,
    int bits_per_sample,
    int sample_rate,
    int number_of_channels,
    int number_of_frames);

typedef void(*StateChangedCallback)(int state);

typedef void(*VideoFrameEncodedCallback)(int video_track_id, const void *pixels);

typedef void(*RemoteTrackChangedCallback)(const char* track_id, int media_kind, int change_kind);

typedef void(*LogSink)(const char* message, int severity);

