
#import <ThingSmartNetworkKit/ThingSmartNetworkKit.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(RemindService)
@interface ThingODRemindService : ThingSmartRequest

- (void)fetchCallRemindInfoWithSuccess:(nullable ThingSuccessID)success failure:(nullable ThingFailureError)failure;

- (void)fetchSMSRemindInfoWithSuccess:(nullable ThingSuccessID)success failure:(nullable ThingFailureError)failure;
@end

NS_ASSUME_NONNULL_END
