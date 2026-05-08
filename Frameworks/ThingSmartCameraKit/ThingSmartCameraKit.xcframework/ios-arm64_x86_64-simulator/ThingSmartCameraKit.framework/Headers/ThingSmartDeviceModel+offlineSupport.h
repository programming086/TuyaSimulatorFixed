
#import <ThingSmartDeviceCoreKit/ThingSmartDeviceCoreKit.h>

@interface ThingSmartDeviceModel (offlineSupport)

@property (nonatomic, strong, readonly) NSDictionary *offline_dps;

@property (nonatomic, assign, readonly) BOOL isSupportOfflineDp;

- (BOOL)isExitCachedDpValue:(NSString *)dpId;

@end
