
#import <ThingSmartDeviceCoreKit/ThingSmartDeviceCoreKit.h>
#import "ThingSmartHomeKitDevice.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartDeviceModel (ThingSmartHomeKit)

/// Find ThingSmartHomeKitDevice that associated with ThingSmartDeviceModel which has added in HomeKit.
/// @return If The device has been added to HomeKit and is reachable, will return associated ThingSmartHomeKitDevice. If not found , will reutrn nil.
/// @note When your device has been added to HomeKit, you can invoke `[[UIApplication sharedApplication] openURL:[NSURL URLWithString:@"com.apple.home://"] options:@{} completionHandler:nil];`, after user clicked the `Add To HomeKit` button in The Device Detail page.
- (nullable ThingSmartHomeKitDevice *)thingsdk_associatedHomeKitDevice __attribute__((deprecated("deprecated, use thingsdk_associatedHomeKitDeviceForHomeManager:")));

/// Find ThingSmartHomeKitDevice that associated with ThingSmartDeviceModel which has added in HomeKit.
/// @return If The device has been added to HomeKit and is reachable, will return associated ThingSmartHomeKitDevice. If not found , will reutrn nil.
/// @note When your device has been added to HomeKit, you can invoke `[[UIApplication sharedApplication] openURL:[NSURL URLWithString:@"com.apple.home://"] options:@{} completionHandler:nil];`, after user clicked the `Add To HomeKit` button in The Device Detail page.
- (nullable ThingSmartHomeKitDevice *)thingsdk_associatedHomeKitDeviceForHomeManager:(HMHomeManager *)homeManager;


 // Checks whether the device supports HomeKit integration.
 // @return YES if the device supports HomeKit, NO otherwise.
- (BOOL)supportsHomeKit;

@end
    
NS_ASSUME_NONNULL_END
