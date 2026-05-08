
#import <CoreMedia/CoreMedia.h>
#import <Foundation/Foundation.h>
#include "ThingVideoCodecDefines.h"

@protocol ThingVideoDecoderDelegate;

@interface ThingVideoDecoder : NSObject

@property (nonatomic,   weak) id<ThingVideoDecoderDelegate>   delegate; //propert have setter

- (int)initWithTypeId:(THING_VIDEO_CODEC_ID)videoDecoderId did:(NSString*)did width:(int)width height:(int)height;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithCodecId:(THING_VIDEO_CODEC_ID)codec ;


- (int)decodeWithStream:(unsigned char *)stream length:(int)len ;

@end

@protocol ThingVideoDecoderDelegate <NSObject>
@optional

- (void)videoDecoder:(ThingVideoDecoder*)videoDecoder onVideoFrameRecvedWithPixel:(void*)pixel width:(int)width height:(int)height pixelFromat:(THING_PIXEL_FORMAT)pixelFormat;

@end
