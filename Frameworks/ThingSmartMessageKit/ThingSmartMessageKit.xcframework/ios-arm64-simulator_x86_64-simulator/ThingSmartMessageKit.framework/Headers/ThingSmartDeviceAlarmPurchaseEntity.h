
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ThingSmartDeviceAlarmServicePurchaseStatus) {
    ThingSmartDeviceAlarmServicePurchaseStatusUnknown = -1,
    ThingSmartDeviceAlarmServicePurchaseStatusNotBuy = 0,
    ThingSmartDeviceAlarmServicePurchaseStatusBuy = 1,
    ThingSmartDeviceAlarmServicePurchaseStatusOverDue = 2,
    ThingSmartDeviceAlarmServicePurchaseStatusUsageExceeded = 3,
};

@interface ThingSmartDeviceAlarmPurchaseEntity : NSObject
/// The expiration date of the service package
@property (nonatomic, assign) NSInteger expireDate;
/// The current status of service purchasing
@property (nonatomic, assign) ThingSmartDeviceAlarmServicePurchaseStatus packageStatus;
/// Number of services remaining
@property (nonatomic, assign) NSInteger remainingTimes;
/// A description of the service package
@property (nonatomic, strong) NSString *packageDesc;
@end

NS_ASSUME_NONNULL_END
