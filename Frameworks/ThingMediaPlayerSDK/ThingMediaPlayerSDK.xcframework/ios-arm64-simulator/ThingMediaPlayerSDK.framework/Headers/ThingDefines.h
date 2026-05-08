#ifndef ThingDefines_h
#define ThingDefines_h
#include <stdio.h>
#include <string.h>

#define THING_EXPORT_API
#define THING_INVALID_DATA -1

// Player attribute configuration
#define PRIV_MJPEG "priv_mjpeg"                 //!< MJPEG-Private, using private MJPEG protocol
#define MIRROR "mirror"                         //!< Image mirror, true or false
#define SCALE_IMAGE_SIZE "scale_image_size"     //!< Image scaling, configured as "widthxheight" like "1920x1080"
#define TRANS_PROTOCOL "transport_protocol"     //!< Transport protocol, configured as "tcp" or "udp"
#define VIDEO_DECODER_NAME "video_decoder_name" //!< Stream type setting, configured as "mjpeg""h264""h265" etc.
#define FILTER "filter"
#define ROTATE "rotate"
typedef enum {
    THING_FORWARD = 0 ,
    THING_BACKWARD
}ThingDirection;

typedef enum {
    THING_ROTATE_NORMAL        =   0 ,                     // Normal
    THING_ROTATE_90_ANGLE      =   1 ,                     // Rotate 90 degrees counterclockwise
    THING_ROTATE_180_ANGLE     =   2 ,                     // Rotate 180 degrees counterclockwise
    THING_ROTATE_270_ANGLE     =   3 ,                     // Rotate 270 degrees counterclockwise
}ThingRotateMode;

typedef enum {
    THING_MIRROR_TYPE_FORMAT_NULL = 0,
    THING_MIRROR_TYPE_HORIZONTAL_ROTATION = 1,
    THING_MIRROR_TYPE_VERTICAL_ROTATION = 2,
}ThingMirrorType;

typedef enum{
    kThingErrCode_NoErr                 =  0,       // Error code No error
    kThingErrCode_ModuleNotInitialized  = -10000,   // Error code Not initialized
    kThingErrCode_NotExists             = -10001,   // Media player object does not exist
    kThingErrCode_InvalidParam          = -10002,   // Error code Invalid parameter
    kThingErrCode_VersionNotSupported   = -10003,
    kThingErrCode_InvalidCommand        = -20001,   // Error code Invalid command
    kThingErrCode_ParamsInvalid         = -20002,   // Error code Invalid parameter
    kThingErrCode_DataInvalid           = -20003,   // Error code Invalid data
    kThingErrCode_Interrupted           = -20004,   // Error code Operation interrupted
    /* MP4 related errors */
    kThingErrCode_Mp4NotRecording       = -30011,   // Error code Not recording file currently
    kThingErrCode_Mp4SetAVConfigFailed  = -30012,   // Error code Audio/video parameter error
    kThingErrCode_Mp4HeaderWriteFailed  = -30013,   // Error code mp4 header write failed
    kThingErrCode_Mp4TrailerWriteFailed = -30014,   // Error code mp4 trailer write failed
    kThingErrCode_CreateFileFailed      = -30015,   // Error code mp4 file creation failed
    kThingErrCode_OpenStreamFailed      = -50001,   // Stream open failed
    kThingErrCode_StreamParseFailed     = -50002,   // Stream parameter parsing failed
    kThingErrCode_Err                   =  -1,      // Error code Unknown error
}ThingErrCode;

typedef enum {
    THING_SPEED_ONE = 0,
    THING_SPEED_QYARTER,
    THING_SPEED_HALF,
    THING_SPEED_TWO,
    THING_SPEED_THREE,
    THING_SPEED_FOUR,
    THING_SPEED_EIGHT,
}THING_PLAY_SPEED_TYPE;

typedef enum {
    THING_TRANSPORT_TCP = 0,
    THING_TRANSPORT_UDP = 1,
}THING_TRANSPORT_PROTOCOL_TYPE;

typedef enum{
    THING_RUN_INFO_EVENT_MEDIA_STATE = 0,      // Player state
    THING_RUN_INFO_EVENT_STREAM = 1,           // Stream information
    THING_RUN_INFO_EVENT_CODEC = 2,            // Decoder information
    THING_RUN_INFO_EVENT_RECORD = 3,           // Recording information
    THING_RUN_INFO_EVENT_KEEP_ALIVE = 4,       // Keep alive information
    THING_RUN_INFO_EVENT_NET = 5,              // Network information
    THING_RUN_INFO_EVENT_MEDIA_PROCESS = 6,    // Media process information
    THING_RUN_INFO_EVENT_SNAPSHOT = 7,         // Snapshot information
    THING_RUN_INFO_EVENT_MAX
}THING_RUN_INFO_EVENT_TYPE_E;

typedef enum tagMediaProcessErrorE {
    THING_DATA_RECV_ERROR = 0,           /**<  Media stream retrieval failed */
    THING_DATA_RECV_TIME_OUT = 1,        /**<  Media stream retrieval timed out */
    PLAYER_RUN_INFO_MAX
}THING_MEDIA_PROCESS_ERROR_E;


/* Player state enumeration */
typedef enum tagThingMediaStateErrorE{
    
/*
* SetDataSource()->THING_MEDIA_STATE_INITIALIZED
*/
    THING_MEDIA_STATE_IDLE           =   0,              // Idle
    
/*
*  Open()->THING_MEDIA_STATE_PREPARING->THING_MEDIA_STATE_PREPARED
*/
    THING_MEDIA_STATE_INITIALIZED   =   1,              // Initialized
    
/*
 * Close() -> THING_MEDIA_STATE_INITIALIZED
 */
    THING_MEDIA_STATE_PREPARING     =   2,              // Preparing
    
/*
 * Close() -> THING_MEDIA_STATE_INITIALIZED
 * Start() -> THING_MEDIA_STATE_RUNNING
 */
    THING_MEDIA_STATE_PREPARED   =   3,                // Prepared (first frame ready)
        
/*
 * Pause() -> THING_MEDIA_STATE_PAUSED
 * Close() -> THING_MEDIA_STATE_INITIALIZED
 */
    THING_MEDIA_STATE_RUNNING            =   4,        // Running
    
/*
 * Open() -> THING_MEDIA_STATE_PREPARING -> THING_MEDIA_STATE_PREPARED
 * Close()      -> THING_MEDIA_STATE_INITIALIZED
 */
    THING_MEDIA_STATE_COMPLETE           =   5,        // Playback complete
    
/*
 * Play()             -> THING_MEDIA_STATE_RUNNING
 * Close()      -> THING_MEDIA_STATE_INITIALIZED
 */
    THING_MEDIA_STATE_PAUSED             =   6,        // Paused
    
/*
 * Not yet implemented
 */
    THING_MEDIA_STATE_ERROR              =   7,         // Error
}THING_MEDIA_STATE_ERROR_E;

typedef struct{
    THING_RUN_INFO_EVENT_TYPE_E ulRunInfoType;
    int ulError;
    unsigned long ulReserved;
    char strInfo[256];
}ThingMsgRunInfo;

typedef enum tagThingPlayerFluency {
    THING_PICTURE_REAL = 0,                /**< Prioritize real-time, do not wait for decode */
    THING_PICTURE_FLUENCY = 1,             /**< Prioritize fluency, ensure smooth video, cache 3s of video */
    THING_PICTURE_BALANCE = 2,             /**< Balance mode, between real-time and fluency, cache 1s of video */
} THING_PLAYER_PICTURE_FLUENCY_E;

typedef enum {
    PIX_FMT_YUV420P,
    PIX_FMT_NV12,
    PIX_FMT_CV_PIXEL_BUFFER
}MpPixFormat;

typedef struct {
    long long codec_id;
    long long time_stamp;
    long long duration;
    unsigned char* decoded[3];
    void* platform_data;
    int width;
    int height;
    int fps;
    MpPixFormat pixel_format;
    int angle_;
    bool is_mirror;
}ThingVideoFrame;

typedef struct{
    char handle_name[64] ;
    long long time_stamp ;
    unsigned char *data ;
    int size ;
}ThingDataFrame;

typedef enum StretchMode {
    STRETCH_MODE_NONE = 0,         ///< No stretching
    STRETCH_MODE_CROP,            ///< Crop the image
    STRETCH_MODE_STRETCH,         ///< Stretch the image
    STRETCH_MODE_FIT,             ///< Fit the image
};

typedef enum tagMediaOutputType {
    MediaOutputTypeJpeg,
    MediaOutputTypeMp4
} MediaOutputType;

typedef struct tagMediaOutConfig {
    MediaOutputType type;               ///< Output type,
    int output_width;               ///< Output width in pixels
    int output_height;              ///< Output height in pixels
    char output_path[256];          ///< Output file path
    char output_name[256];          ///< Output file name
    char output_thumbnail[256];     ///< Output thumbnail path
    ThingRotateMode rotate_mode;    ///< Rotation mode
    int stretch_mode;               ///< Stretch mode
    bool is_mute;                   ///< Mute flag
    int min_duration;              ///< min duration 
} MediaOutConfig;

typedef enum tagMediaSourceType {
    ThingMediaSourceImage,
    ThingMediaSourceAudio,
    ThingMediaSourceVideo,
    ThingMediaSourceUnknow
}ThingMediaSourceType;

typedef struct MediaSource {
    ThingMediaSourceType type;
    char path[256];
    char name[256];
    bool loop; // 以该输入源的时长为主
    int x;  //起始位置x
    int y;  //起始位置y
    int z_index;              // 叠加层级，值越大越在上层
    char filter_chain[256];   // 应用于此输入源的滤镜
    int min_duration;         // 最小录制时长(秒)，用于控制循环次数
}ThingMediaSource;

#endif /* ThingDefines_h */
