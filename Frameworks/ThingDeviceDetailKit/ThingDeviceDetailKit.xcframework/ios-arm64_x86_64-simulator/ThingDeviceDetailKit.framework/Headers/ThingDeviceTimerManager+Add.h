
#import "ThingDeviceTimerManager.h"
#import "ThingDeviceTimerOperator.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingDeviceTimerManager (Add)

- (void)generalAddTimer:(ThingDeviceTimerAddParams *)params success:(void(^)(NSString *timerId))success failure:(void(^)(NSError *error))failure;

- (void)specialAddTimer:(ThingDeviceTimerAddParams *)params success:(void(^)(NSString *timerId))success failure:(void(^)(NSError *error))failure;

@end

NS_ASSUME_NONNULL_END
