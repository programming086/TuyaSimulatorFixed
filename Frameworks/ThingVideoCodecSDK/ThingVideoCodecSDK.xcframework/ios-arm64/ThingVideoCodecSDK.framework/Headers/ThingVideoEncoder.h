
#import <CoreMedia/CoreMedia.h>
#import <Foundation/Foundation.h>

#include "ThingVideoCodecDefines.h"

@protocol ThingVideoEncoderDelegate;

@interface ThingVideoEncoder : NSObject

@property (nonatomic,   weak) id<ThingVideoEncoderDelegate>   delegate; //propert have setter

- (instancetype)init NS_UNAVAILABLE;
/**
    create video encoder by codecid
 */
- (instancetype)initWithCodecId:(THING_VIDEO_CODEC_ID)codec ;

/**
    initialize the video encoder
 */
- (int)initializeWithWidth:(int)width height:(int)height frameRate:(int)frameRate ;

/**
    encode one video frame.
 */
- (int)encodeWithFrame:(void*)frame width:(int)width height:(int)height pixelFormat:(THING_PIXEL_FORMAT)pixelFormat timestamp:(long long)timestamp ;


@end

@protocol ThingVideoEncoderDelegate <NSObject>
@optional

- (void)videoEncoder:(ThingVideoEncoder*)videoDecoder onVideoEncodedStreamRecvWithStream:(unsigned char *)stream ength:(int)length frameType:(int)frameType captimestamp:(long long) captimestamp ;

@end
