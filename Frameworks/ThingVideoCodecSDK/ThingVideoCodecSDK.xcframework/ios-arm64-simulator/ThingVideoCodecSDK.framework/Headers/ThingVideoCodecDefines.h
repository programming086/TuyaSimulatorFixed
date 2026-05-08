
#ifndef ThingVideoCodecDefines_h
#define ThingVideoCodecDefines_h
#include <string.h>


#define ThingVideoCodecSDK_version "1.9.2"

/**
 Description Supported decoding formats
 */
typedef enum{
    THING_VIDEO_CODEC_UNKNOW = -1,
    THING_VIDEO_CODEC_H264,
    THING_VIDEO_CODEC_H265,
    THING_VIDEO_CODEC_MJPEG
}THING_VIDEO_CODEC_ID;

/**
 Description Supported YUV output formats
 Convert the J422P format after MJPEG decoding to one of 420P, NV12, or pixelBuffer
 */
typedef enum{
    THING_PIXEL_UNKNOW = -1,
    THING_PIXEL_YUV420P,
    THING_PIXEL_NV12,
    THING_PIXEL_PIXELBUFFER       // Format for IOS hardware decoding and rendering
}THING_PIXEL_FORMAT;

typedef enum{
    kThingVideoCodecErrCode_NoError                     = 0,               // No decoding error
    kThingVideoCodecErrCode_DecodeFailed                = -40300,          // General decoding error
    kThingVideoCodecErrCode_ErrorInput                  = -40301,          // Input error
    kThingVideoCodecErrCode_ErrorOutput                 = -40302,          // Output error
    kThingVideoCodecErrCode_PixelFormat_Unsupported     = -40303,           // Unsupported
    kThingVideoCodecErrCode_NotInitialized              = -40304,           // not initialize
}ThingVideoCodecErrCode;



#endif /* ThingVideoCodecDefines_h */
