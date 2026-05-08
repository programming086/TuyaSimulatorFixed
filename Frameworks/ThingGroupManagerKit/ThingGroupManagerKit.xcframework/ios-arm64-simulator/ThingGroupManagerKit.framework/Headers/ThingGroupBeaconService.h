
#import "ThingGroupBaseService.h"
#import "ThingGroupServiceProtocol.h"
#import <ThingSmartDeviceCoreKit/ThingSmartDeviceCoreKit.h>


NS_ASSUME_NONNULL_BEGIN

/// Local Beacon operation error domain
extern NSErrorDomain const ThingBluetoothBeaconErrorDomain;

@interface ThingGroupBeaconService : ThingGroupBaseService <ThingGroupServiceProtocol>

/// Group ID, available only through "modifying group initialization"
@property (nonatomic, copy, readonly, nullable) NSString *groupId;
/// 1. The group page entered from the device, input parameter
@property (nonatomic, copy, readonly, nullable) NSString *devId;

/// Devices that can be added to the Beacon group
/// @param deviceModel The device model
- (BOOL)isBeaconGroupSupportDevice:(ThingSmartDeviceModel *)deviceModel;

#pragma mark - Timer -
/// Cancel the timer
- (void)timerInvalidate;
@end

NS_ASSUME_NONNULL_END
