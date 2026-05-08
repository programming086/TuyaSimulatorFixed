
#import <ThingSmartBeaconKit/ThingSmartBeaconKit.h>
#import <ThingSmartDeviceCoreKit/ThingSmartDeviceCoreKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingBleBeaconSceneDpAction : NSObject

@property (nonatomic, strong, nonnull) ThingSmartDeviceModel *deviceModel;
@property (nonatomic, strong, nonnull) NSDictionary *dps;
@property (nonatomic, assign) NSInteger delayMills;
@property (nonatomic, copy, nullable) ThingSuccessHandler success;
@property (nonatomic, copy, nullable) ThingFailureError failure;

@end


@interface ThingSmartBeaconManager (BatchDp)


- (void)batchPublishDps:(NSArray<ThingBleBeaconSceneDpAction *> *)dpActions retryCount:(NSInteger)retryCount;

@end

NS_ASSUME_NONNULL_END
