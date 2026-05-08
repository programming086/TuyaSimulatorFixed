
#import <Foundation/Foundation.h>

#import <ThingSmartCameraBase/ThingSmartLocalAudioInfoType.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartLocalAudioInfo : NSObject <ThingSmartLocalAudioInfoType>

+ (instancetype)localAudioInfoWithSampleRate:(int)sampleRate channel:(int)channel;

@end

NS_ASSUME_NONNULL_END
