
#import <ThingSmartDeviceCoreKit/ThingSmartDeviceCoreKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartDevice (LowPowerDPPublish)

- (BOOL)meetsLowPowerPublishDpsCondition;

- (void)publishLowPowerDps:(NSDictionary *)dps success:(nullable ThingSuccessBOOL)success failure:(nullable ThingFailureError)failure;

@end

NS_ASSUME_NONNULL_END
