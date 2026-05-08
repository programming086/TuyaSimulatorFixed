
#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#include "ThingCameraDefines.h"
#include "mp4_recorder_interface.h"

@interface ThingCameraAVMuxer : NSObject

typedef enum{
    kThingCameraAVMuxer_NoErr =  0,
    kThingCameraAVMuxer_Err =  -1,
    kThingCameraAVMuxer_InvalidParam =  -2,
    kThingCameraAVMuxer_Unsupported =  -3,
    kThingCameraAVMuxer_Undefined_Behavior = -4
}kThingCameraAVMuxerErrCode;

enum enMuxerColorFmt {
    MUXER_COLOR_NV12 = 0,   //YYYY YYYY UVUV
    MUXER_COLOR_I420,       //YYYY YYYY UUVV
};


enum enVideoCodecFmt {
    MUXER_CODEC_H264 = 0,
    MUXER_CODEC_H265
};

enum enAudioCodecFmt {
    MUXER_CODEC_AAC = 0,
};

- (instancetype)initWithVideoPath:(const char*)video_path file_name:(const char*)file_name rotate:(int)rotate;

- (int)addVideoTrack: (int)out_video_codec width:(int)width height:(int)height fps:(int)fps bitrate:(int)bitrate color_fmt:(int) color_fmt;

- (int)addAudioTrack: (int)out_audio_codec sample_rate:(int)sampleRate channel:(int)channels bitwidth:(int)bitwidth pcmFormat:(int)pcm_fmt;

- (int)startRecord;

- (int)sendAudioFrameWithPcmData:(const unsigned char *)pcmData size:(int)uSize;

- (int)sendVideoFrameWithPixbufferData:(const char *)pixBuffer timestamp:(long long)timestamp;

- (CVPixelBufferRef)sendVideoFrameWithYuvData:(const uint8_t *)y u:(const uint8_t *)u v:(const uint8_t *)v width:(int)width height:(int)height  timestamp:(long long)timestamp type:(MP4_COLOR_FORMAT_E)type realtime:(bool)realtime;
- (int)stopRecord;
@end
