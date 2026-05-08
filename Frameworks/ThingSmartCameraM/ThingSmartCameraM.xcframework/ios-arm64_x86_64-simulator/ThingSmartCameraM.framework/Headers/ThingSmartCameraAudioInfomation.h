
#import <Foundation/Foundation.h>
#import <ThingSmartCameraBase/ThingSmartCameraBase.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartCameraAudioInfomation : NSObject<ThingSmartCameraAudioType>

- (instancetype)initAudioInfomation:(int)pcmdb timeStamp:(unsigned long long)nTimeStamp;

@end

NS_ASSUME_NONNULL_END
