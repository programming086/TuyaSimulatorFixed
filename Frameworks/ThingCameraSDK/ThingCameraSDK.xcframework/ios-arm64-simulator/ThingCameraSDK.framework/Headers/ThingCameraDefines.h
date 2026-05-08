
#ifndef __THINGCAMERADEFINES_H__
#define __THINGCAMERADEFINES_H__





#define ThingCameraSDK_version "7.5.2"




#define UNINITIALIZED -1

typedef enum {
    P2P_TYPE_PPCS = 2,
    P2P_TYPE_THING = 4,
    P2P_TYPE_THING_V4 = 8,
    P2P_TYPE_UNKNOWN,
} P2PType;

typedef enum {
    SIMPLE_CAMERA,
    STATION_CAMERA,

    MEDIA_PLAYER,

    P2PV4_CAMERA,

} ThingDeviceType;

typedef enum {
    REQ_OPEN_VIDEO  = 0 ,               // open local video
    REQ_CLOSE_VIDEO = 1 ,               // close local video
    REQ_OPEN_AUDIO  = 2 ,               // open local audio
    REQ_CLOSE_AUDIO = 3                 // close local audio
}ThingRequestType;


typedef enum {
    THING_CONNECTION_MODE_UNKNOWN = 0,
    THING_CONNECTION_MODE_P2P,
    THING_CONNECTION_MODE_RELAY
}ThingConnectMode;


typedef enum {
    CAMERA_FRONT = 0,
    CAMERA_BACK = 1 ,
}ThingCameraID;

typedef enum{
    Thing_AV_CODEC_UNKNOWN         = 0x00,
    
    Thing_AV_CODEC_VIDEO_MPEG4     = 0x10,
    Thing_AV_CODEC_VIDEO_H263      = 0x11,
    Thing_AV_CODEC_VIDEO_H264      = 0x12,
    Thing_AV_CODEC_VIDEO_MJPEG     = 0x13,
    Thing_AV_CODEC_VIDEO_H265      = 0x14,
    
    Thing_AV_CODEC_AUDIO_ADPCM     = 0X80,
    Thing_AV_CODEC_AUDIO_PCM       = 0x81,
    Thing_AV_CODEC_AUDIO_AAC_RAW   = 0x82,
    Thing_AV_CODEC_AUDIO_AAC_ADTS  = 0x83,
    Thing_AV_CODEC_AUDIO_AAC_LATM  = 0x84,
    Thing_AV_CODEC_AUDIO_G711U     = 0x85,
    Thing_AV_CODEC_AUDIO_G711A     = 0x86,
    Thing_AV_CODEC_AUDIO_G726      = 0x87,
    Thing_AV_CODEC_AUDIO_SPEEX     = 0x88,
    Thing_AV_CODEC_AUDIO_MP3       = 0x89,
}Thing_AV_CODEC_ID;

typedef struct tagThingVideoFrameInfo{
    int type ;         // sub video index
    // -1    -- full
    // 1    --
    // 2    --
    int index ;
    int codecid;
    int nWidth;
    int nHeight;

    int nFrameRate;
    int nIsKeyFrame;
    char *sei;
    int nSeiSize;
    unsigned long long nTimeStamp;
    unsigned long long nDuration;
    unsigned long long nProgress;
    int nFragmentId ;
    int nRotationSei;
}ThingVideoFrameInfo;

typedef enum{

    THING_EVENT_TYPE_NETWORK = 1,     //网络状态信息
    THING_EVENT_TYPE_PREVIEW = 2      //预览过程信息

}THING_EVENT_TYPE_E;

typedef enum {
    EVENT_FRAGMENTCHANGED = 1            // fragment changed
}THING_TASK_EVENT;

typedef enum{
    THING_EVENT_NETWORK_QUALITY = 1, //network quality between 0 to 100，<=50 indicate normal
    THING_RUN_INFO_EVENT_MAX
}THING_EVENT_ERROR_CODE_E;

typedef struct{
    THING_EVENT_TYPE_E ulEventType;
    int ulError;
    long long valueInfo;
    char strInfo[256];
}ThingEventInfo;


// 新增枚举类型
typedef enum {
    ThingVideoCodecH264,
    ThingVideoCodecH265
}ThingVideoCodecType;

typedef enum {
    ThingAudioCodecG711A,
    ThingAudioCodecG711U,
      ThingAudioCodecPCM
}
ThingAudioCodecType;

typedef enum {
    //ThingSyncModeAudioMasterClock,  // Represents the audio master clock synchronization mode.
    //ThingSyncModeVideoMasterClock,  // Represents the video master clock synchronization mode.
    //ThingSyncModeSystemMasterClock, // Represents the system master clock synchronization mode.
    ThingSyncModeAudioOnly,            // Represents audio-only mode without synchronization.
    ThingSyncModeVideoOnly             // Represents video-only mode without synchronization.
} ThingSyncMode;

typedef struct tagThingAudioFrameInfo{
    int codecid;
    int nChannelNum;
    int nSampleRate;
    int nBitWidth;
    unsigned long long nTimeStamp;
    unsigned long long nDuration;
    unsigned long long nProgress;
    bool bShowProgressOnly ;
    int pcmdb ;
}ThingAudioFrameInfo;

typedef void (*ConnectCallback)(void* user);

typedef enum{
    /************************** New error codes range from -40000 to -50000, do not add new error codes in the range 0 to -40000 ****************/
    kThingErrCode_NoErr                  =  0,       // No error code

    kThingErrCode_FragmentEnd            =  1,       // Fragment playback end notification
    /**************** Network status event codes (10000 ~ -10099) ***********************************/
    kThingErrCode_NetStatusGood          =  100000,  //

    kThingErrCode_Err                    =  -1,      // General error code
    kThingErrCode_CameraNotInitialized   = -10000,   // Error code Camera object not created
    kThingErrCode_NotConnected           = -10001,   // Error code Device not connected
    kThingErrCode_SessionInvalid         = -10002,   // Invalid p2p session error code
    kThingErrCode_TimeOut                = -10003,   // Timeout error code
    kThingErrCode_ConnectionCancelled    = -10004,   // Connection cancelled error code

    kThingErrCode_DeviceNotOnline        = -10006,   // Device not online error code
    kThingErrCode_CancelByUser           = -10007,   // User cancelled operation error code
    kThingErrCode_InvalidCommand         = -20001,   // Invalid command error code
    kThingErrCode_ParamsInvalid          = -20002,   // Invalid parameters error code
    kThingErrCode_DataInvalid            = -20003,   // Invalid data error code
    kThingErrCode_Interrupted            = -20004,   // Operation interrupted error code
    kThingErrCode_OperationNotAllowed    = -20005,   // Operation not allowed error code
    kThingErrCode_VersionNotSupported    = -20006,   // Current app version does not support this protocol [need to upgrade the app]
    kThingErrCode_Busy                   = -20007,   // Device currently busy error code [e.g. intercom already occupied by others]
    kThingErrCode_OutOfMemory            = -20008,   // Out of memory error code
    kThingErrCode_DownloadFailed         = -30001,   // File download failed error code
    kThingErrCode_NotPlayBacking         = -30002,   // Not in playback state error code
    kThingErrCode_SetPlaySpeedFailed     = -30003,   // Failed to set playback speed error code
    kThingErrCode_NotPlayCloudDataing    = -30004,   // Not in cloud storage playback state error code
    kThingErrCode_DelPlaybackDataFiled   = -30005,   // Delete playback data failed error code
    kThingErrCode_DownLoadFragmentError  = -30006,   // Playback data download time slice too long or zero error code
    kThingErrCode_JpgSupportedOnly       = -30007,   // Unsupported format, playback images only support jpg files error code
    kThingErrCode_PLDownLoadStateError   = -30008,   // Playback download, state error error code
    kThingErrCode_DownLoadImageFailed    = -30009,   // Playback download, state error error code
    kThingErrCode_CurlError              = -30010,   // Curl connection error error code
    /* MP4 related errors */
    kThingErrCode_Mp4NotRecording        = -30011,   // Not currently recording error code
    kThingErrCode_Mp4SetAVConfigFailed   = -30012,   // Audio and video parameter error error code
    kThingErrCode_Mp4HeaderWriteFailed   = -30013,   // mp4 file header write failed error code
    kThingErrCode_Mp4TrailerWriteFailed  = -30014,   // mp4 file trailer write failed error code
    kThingErrCode_StartAudioTalkFailed   = -30050,   // Start intercom failed error code
    kThingErrCode_ResponseReturnErr      = -30060,   // Device end response returned error error code
    kThingErrCode_ErrOccurDataTransport  = -30061,   // Error occurred during data transport error code
    kThingErrCode_FileNotExists          = -30062,   // File does not exist error code
    kThingErrCode_CreateFileFailed       = -30063,   // Failed to create local file, please check if the path exists error code
    kThingErrCode_TooManyFilesDownload   = -30064,   // Too many files downloading or zero error code
    kThingErrCode_DeleteFilesFailed      = -30065,   // Delete files failed error code
    /* jpeg related errors */
    kThingErrCode_JpegFilterInitFailed   = -30080,   // ffmpeg compile option bsfs does not support mjpeg2jpeg error code
    kThingErrCode_AvformatOpenFailed     = -30081,   // ffmpeg compile option demuxers does not support mjpeg format error code
    kThingErrCode_FirstIFrameNotArrived  = -30082,   // First I-frame not received error code
    kThingErrCode_FilterNotSupportCodec  = -30083,   // Currently only supports mjpeg stream error code
    /* Cloud storage download errors */
    kThingErrCode_CloudDataAVParamChanged  = -30090,   // Cloud storage download segment has audio and video parameter changes, download not supported error code

    /**************** CameraSDK general error codes (-40000 ~ -40199) ***********************************/
    /*
        Such as insufficient memory, failed to create thread, create semaphore, execution failed, illegal input parameters, insufficient permissions, etc.
        System errors, interface call errors, etc.
    */
    kThingErrCode_GeneralFailed = -40000,               // CameraSDK general error
    kThingErrCode_GeneralEmptyParam = -40001,           // Empty parameter
    kThingErrCode_GeneralJsonParseFailed = -40002,      // JSON parsing failed
    kThingErrCode_GeneralNoAudioCapability = -40003,    // cameraConfig does not define audio capabilities

    /******************* Media stream processing related error codes (-40200 ~ -40299) ***********************************/
    /*
        Such as packet loss, frame loss, etc.
    */
    kThingErrCode_MediaFailed  = -40200,							  // Media stream processing general error
    kThingErrCode_MediaReadNetworkTimeout  = -40201,    // Network data fetch timeout
    kThingErrCode_MediaNeedMoreData  = -40202, 			// Need more data
    kThingErrCode_MediaDecodeTimeout  = -40203,         // Decode timeout
    kThingErrCode_MediaStuttering  = -40204,            // Stuttering
    kThingErrCode_MediaBreakByUser  = -40205,           // Media stream processing interrupted by user
    kThingErrCode_MediaBreakByDevice  = -40206,         // Media stream processing device anomaly
    // !!!! cube version is 40201
    kThingErrCode_LocalDataAVParamChanged    = -40220,   // Playback download audio and video parameters changed, download stopped error code

    /******************* Decoding process related error codes (-40300 ~ -40399) ***********************************/
    /*
        Such as data input errors, decoding abnormalities, etc.
    */
    kThingErrCode_DecodeFailed  = -40300, // Decoding processing general error
    /*
     Error codes defined in video_codec_sdk
    kThingErrCode_DecodeErrorInput   = -40301,          // Wrong input
    kThingErrCode_DecodeErrorOutput  = -40302,          // Wrong output
    kThingErrCode_DecodeUnsupportPixelFormat  = -40303, // Unsupported pixel format
    */

    /******************* Cloud storage related error codes (-40400 ~ -40599) ***********************************/
    /*
        Such as download failure, domain name expiration, URL authentication failure, etc.
    */
    kThingErrCode_CloudFailed  = -40400,               // Cloud storage general error
    kThingErrCode_CloudUrlUnavailable  = -40401,       // Cloud URL unavailable
    kThingErrCode_CloudNoDataExits     = -40402,       // No cloud storage data in the broadcast time slice

    /******************* Recording related error codes (-40600 ~ -40799) ***********************************/
    /*
        Such as failed to create audio track, failed to create video track, etc.
    */
    kThingErrCode_RecordFailed  = -40600, // Recording general error

    /******************* Upload and download (album business) related error codes (-40800 ~ -40999) ***********************************/
    /*
        Such as download failure, download
    */
    kThingErrCode_UpDownloadFailed  = -40800, // Upload and download general error

    /******************* Interaction with device related error codes (-41000 ~ -41199) ***********************************/
    /*
        Such as device busy, device anomalies, etc.
    */
    kThingErrCode_DeviceFailed  = -41000, 				 // Device general error
    kThingErrCode_DeviceNoResponse  = -41001,      // Device no response

}ThingErrCode;

typedef enum{
    kThingSessionStatus_Connected        =  0,       // Connection successful
    kThingSessionStatus_ConnectTimeout   = -3,       // Connection timeout
    kThingSessionStatus_ClosedRemote     = -12,      // Connection closed
    kThingSessionStatus_ClosedTimeOut    = -13,      // Connection timeout
    kThingSessionStatus_ClosedCalled     = -14,      // Connection closed
}ThingSessionStatus;

typedef enum{

    kThingVideoClarityProflow            = 0x1,      // 省流量
    kThingVideoClarityStandard           = 0x2,      // 标清
    kThingVideoClarityHigh               = 0x4,      // 高清
    kThingVideoClaritySuperHigh          = 0x8,      // 超清
    kThingVideoClarityAuto               = 0x20,     // 自动清晰度（仅p2p4.0支持）
    kThingVideoClarityAudioOnly          = 0xFFFF,   // 语音模式(只有语音没有视频)

}ThingVideoClarityMode;

typedef enum{
    Thing_VIDEO_CLARITY_PROFLOW            = 0x1,      // Low data usage
    Thing_VIDEO_CLARITY_STANDARD           = 0x2,      // Standard definition
    Thing_VIDEO_CLARITY_HIGH               = 0x4,      // High definition
    Thing_VIDEO_CLARITY_S_HIGH             = 0x8,      // Ultra high definition
    Thing_VIDEO_CLARITY_SS_HIGH            = 0x10,     // Super ultra high definition
}TRANSFER_VIDEO_CLARITY_TYPE_E;

typedef enum{
    Thing_VIDEO_OUTPUT_FORMAT_RAWDATA,                 // Video raw stream (H.264/H.265)
    Thing_VIDEO_OUTPUT_FORMAT_YUV,                     // Decoded data
}ThingVideoOutputFormat;

typedef enum{
    Thing_AUDIO_OUTPUT_FORMAT_RAWDATA,                 // Audio raw stream (G.711a/u/pcm/aac)
    Thing_AUDIO_OUTPUT_FORMAT_PCM,                     // Decoded data
}ThingAudioOutputFormat;

typedef struct __fragmentSection__{
    int startTime ;
    int endTime ;
}FragmentSection;

typedef enum {
    Thing_SPEED_05TIMES = 0,                   // 0.5x speed
    Thing_SPEED_10TIMES,                   // Normal speed
    Thing_SPEED_15TIMES,                   // 1.5x speed
    Thing_SPEED_20TIMES,                   // 2.0x speed
    Thing_SPEED_25TIMES,                   // 2.5x speed
    Thing_SPEED_30TIMES,                   // 3.0x speed
    Thing_SPEED_35TIMES,                   // 3.5x speed
    Thing_SPEED_40TIMES,                   // 4.0x speed
    Thing_SPEED_80TIMES,                  // 8.0x speed
    Thing_SPEED_160TIMES,                 // 16.0x speed
    Thing_SPEED_320TIMES,                 // 32.0x speed
    Thing_SPEED_025TIMES = 20,             //0.25倍速
} ThingPlayBackSpeedMode;

typedef enum
{
    Thing_PLAYBACK_EVENT_TYPE_NONE = 0,                // No event
    Thing_PLAYBACK_EVENT_TYPE_MD,                      // Motion detection
    Thing_PLAYBACK_EVENT_TYPE_FACE,                    // Face detection
    Thing_PLAYBACK_EVENT_TYPE_BODY,                    // Human body detection
    Thing_PLAYBACK_EVENT_TYPE_MAX
}ThingPlayBackEventType;

typedef enum {
    Thing_ROTATE_NORMAL        =   0 ,                     // Normal
    Thing_ROTATE_90_ANGLE      =   1 ,                     // Clockwise 90 degrees
    Thing_ROTATE_180_ANGLE     =   2 ,                     // Clockwise 180 degrees
    Thing_ROTATE_270_ANGLE     =   3 ,                     // Clockwise 270 degrees
}ThingRotateMode;

typedef enum{
    Thing_SMART_NET_WEAK       = 0,       // Other than wifi, 4g, 5g networks
    Thing_SMART_NET_WIFI       = 1,       // wifi
    Thing_SMART_NET_GPRS_4G    = 2,       // 4G
    Thing_SMART_NET_GPRS_5G    = 3,       // 5G
    Thing_SMART_NET_UNKNOWN    = 4,       // To be extended, currently not supported
}ThingSmartNetType;

typedef enum {
    Thing_MIRROR_CLOSE        =   0 ,      // Close mirror
    Thing_MIRROR_HORIZONTAL   =   1 ,      // Horizontal mirror
    Thing_MIRROR_VERTICALLY   =   2 ,      // Vertical mirror
}ThingMirrorMode;

#endif // __TYDEFINES_H__
