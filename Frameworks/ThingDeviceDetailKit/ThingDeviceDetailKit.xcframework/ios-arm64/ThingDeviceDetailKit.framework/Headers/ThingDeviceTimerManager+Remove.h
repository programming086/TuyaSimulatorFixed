
#import "ThingDeviceTimerManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingDeviceTimerManager (Remove)

- (void)generalRemoveTimer:(ThingDeviceTimerRemoveParams *)params success:(void(^)(void))success failure:(void(^)(NSError *error))failure;
- (void)specialRemoveTimer:(ThingDeviceTimerRemoveParams *)params success:(void(^)(void))success failure:(void(^)(NSError *error))failure;

@end

NS_ASSUME_NONNULL_END
