
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ThingSmartLocalAudioInfoType <NSObject>

///sample rate, default is 8000.
@property (nonatomic, assign) int sampleRate;

///channel, default is 1.
@property (nonatomic, assign) int channel;

@end

NS_ASSUME_NONNULL_END
