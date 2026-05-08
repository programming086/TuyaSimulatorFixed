
#ifndef ThingSmartCameraDefines_h
#define ThingSmartCameraDefines_h

#ifdef __cplusplus
#define IPC_EXTERN        extern "C" __attribute__((visibility ("default")))
#else
#define IPC_EXTERN        extern __attribute__((visibility ("default")))
#endif

#import <Foundation/Foundation.h>

typedef enum
{
    THING_MEDIA_CODEC_UNKNOWN           = 0x00,
    THING_MEDIA_CODEC_VIDEO_MPEG4       = 0x4C,
    THING_MEDIA_CODEC_VIDEO_H263        = 0x4D,
    THING_MEDIA_CODEC_VIDEO_H264        = 0x4E,
    THING_MEDIA_CODEC_VIDEO_MJPEG       = 0x4F,
    THING_MEDIA_CODEC_VIDEO_H265        = 0x50,

}THING_ENUM_CODECID;

typedef struct {
    THING_ENUM_CODECID      codec_id;           // [^en]video coding mode[$en]
    unsigned long          timeStamp;          // [^en]video time stamp[$en]
} ThingSmartVideoStreamInfo;

typedef struct {
    // sub video index
    // 0    -- full
    // 1    -- ball
    // 2    -- bolt
    int type;
    int codecid;
    int nWidth;
    int nHeight;
    /// video view index in splitInfo, -1 is not splited
    int index;
    
    int nFrameRate;
    unsigned long long nTimeStamp;
    unsigned long long nDuration;
    unsigned long long nProgress;
    int nFragmentId;
    int sei_rotation;
    char *sei;
    int nSeiSize;
} ThingSmartVideoFrameInfo;

typedef struct {
    int codecid;
    int nChannelNum;
    int nSampleRate;
    int nBitWidth;
    unsigned long long nTimeStamp;
    unsigned long long nDuration;
    unsigned long long nProgress;
} ThingSmartAudioFrameInfo;

typedef enum {
    Thing_ERROR_NONE,                      // 0
    Thing_ERROR_CONNECT_FAILED,            // 1    [^en]connect failed[$en]
    Thing_ERROR_CONNECT_DISCONNECT,        // 2    [^en]connect did disconnected[$en]
    Thing_ERROR_ENTER_PLAYBACK_FAILED,     // 3    [^en]connect playback channel failed[$en]
    Thing_ERROR_START_PREVIEW_FAILED,      // 4    [^en]preview failed. if the connection is broken during the preview process, it will alse call back this error.[$en]
    Thing_ERROR_START_PLAYBACK_FAILED,     // 5    [^en]playback failed. if the connection is broken during the playback process, it will alse call back this error.[$en]
    Thing_ERROR_PAUSE_PLAYBACK_FAILED,     // 6    [^en]pause playabck failed[$en]
    Thing_ERROR_RESUME_PLAYBACK_FAILED,    // 7    [^en]resume playabck failed[$en]
    Thing_ERROR_ENABLE_MUTE_FAILED,        // 8    [^en]mute failed.[$en]
    Thing_ERROR_START_TALK_FAILED,         // 9    [^en]start talk to device failed[$en]
    Thing_ERROR_SNAPSHOOT_FAILED,          // 10   [^en]get screenshot failed[$en]
    Thing_ERROR_RECORD_FAILED,             // 11   [^en]record video failed[$en]
    Thing_ERROR_ENABLE_HD_FAILED,          // 12   [^en]set definition state failed[$en]
    Thing_ERROR_GET_HD_FAILED,             // 13   [^en]get definition state failed[$en]
    Thing_ERROR_QUERY_RECORD_DAY_FAILED,   // 14   [^en] query video record date failed[$en]
    Thing_ERROR_QUERY_TIMESLICE_FAILED,    // 15   [^en]query video record slice failed[$en]
    Thing_ERROR_QUERY_EVENTLIST_SIFT_FAILED, // 16   [^en]query video event sift failed[$en]
    Thing_ERROR_SET_PLAYBACK_SPEED_FAILED,    // 17   [^en]set playabck speed failed[$en]
    Thing_ERROR_START_VIDEO_TALK_FAILED,    // 18  start video talk failed
    Thing_ERROR_STOP_VIDEO_TALK_FAILED,    // 19  stop video talk failed
    Thing_ERROR_PAUSE_VIDEO_TALK_FAILED,    // 20  pause video talk failed
    Thing_ERROR_RESUME_VIDEO_TALK_FAILED,    // 21  resume video talk failed
} ThingCameraErrorCode;

typedef NS_ENUM(NSUInteger, ThingSmartCameraPlayMode) {
    ThingSmartCameraPlayModeNone,
    ThingSmartCameraPlayModePreview,     // [^en]live[$en]
    ThingSmartCameraPlayModePlayback     // [^en]playback[$en]
};

typedef NS_ENUM(NSUInteger, ThingSmartCameraTalkbackMode) {
    ThingSmartCameraTalkbackNone,
    ThingSmartCameraTalkbackOneWay,
    ThingSmartCameraTalkbackTwoWay
};

typedef NS_ENUM(NSUInteger, ThingSmartCameraDefinition) {
    ThingSmartCameraDefinitionProflow    = 0x1,      // [^en]Data Save[$en] [^zh]省流量[$zh]
    ThingSmartCameraDefinitionStandard   = 0x2,      // [^en]SD[$en] [^zh]标清[$zh]
    ThingSmartCameraDefinitionHigh       = 0x4,      // [^en]HD[$en] [^zh]高清[$zh]
    ThingSmartCameraDefinitionSuper      = 0x8,      // [^en]FHD[$en] [^zh]超清[$zh]
    ThingSmartCameraDefinitionSSuper     = 0x10,     // [^en]FFHD[$en] [^zh]超超清[$zh]
    ThingSmartCameraDefinitionAuto       = 0x20,     // [^en]FFHD[$en] [^zh]自动切换清晰度[$zh]
    ThingSmartCameraDefinitionAudioOnly  = 0xFFFF    // [^en]Audio Only[$en] [^zh]语音模式[$zh]
};

typedef NS_ENUM(NSUInteger, ThingSmartCameraPlayBackSpeed) {
    ThingSmartCameraPlayBackSpeed_05TIMES = 0,   // [^en]0.5 times [$en]
    ThingSmartCameraPlayBackSpeed_10TIMES,       // [^en]1.0 times [$en]
    ThingSmartCameraPlayBackSpeed_15TIMES,       // [^en]1.5 times [$en]
    ThingSmartCameraPlayBackSpeed_20TIMES,       // [^en]2.0 times [$en]
    ThingSmartCameraPlayBackSpeed_25TIMES,       // [^en]2.5 times [$en]
    ThingSmartCameraPlayBackSpeed_30TIMES,       // [^en]3.0 times [$en]
    ThingSmartCameraPlayBackSpeed_35TIMES,       // [^en]3.5 times [$en]
    ThingSmartCameraPlayBackSpeed_40TIMES,       // [^en]4.0 times [$en]
    ThingSmartCameraPlayBackSpeed_80TIMES,       // [^en]8.0 times [$en]
    ThingSmartCameraPlayBackSpeed_160TIMES,      // [^en]16.0 times [$en]
    ThingSmartCameraPlayBackSpeed_320TIMES,      // [^en]32.0 times [$en]
    ThingSmartCameraPlayBackSpeed_AISpeed      // [^en]AISpeed [$en]
};


typedef NS_ENUM(NSInteger, ThingCameraAudioEffectType) {
    ThingCameraAudioEffectTypeNone = 0,
    ThingCameraAudioEffectTypeBrother,
    ThingCameraAudioEffectTypeUncle,
    ThingCameraAudioEffectTypeRobot,
    ThingCameraAudioEffectTypeLolita
};


typedef NS_ENUM(NSInteger, ThingCameraConnectionType) {
    ThingCameraConnectionTypeUnknown = 0,
    ThingCameraConnectionTypeP2P,
    ThingCameraConnectionTypeRelay
};

#endif /* ThingSmartCameraDefines_h */
