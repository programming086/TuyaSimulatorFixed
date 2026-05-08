
#import <ThingSmartDeviceCoreKit/ThingSmartDeviceCoreKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString * ThingSmartCameraAdvancedAbilityCode NS_STRING_ENUM;

FOUNDATION_EXPORT ThingSmartCameraAdvancedAbilityCode const ThingSmartCameraAdvancedAbilityCodeLowPower;
FOUNDATION_EXPORT ThingSmartCameraAdvancedAbilityCode const ThingSmartCameraAdvancedAbilityCodeRemoteWakeup;

@interface ThingSmartDeviceModel (CameraAdvancedAbility)

/// Whether the device has low power ability
@property (nonatomic, assign, readonly) BOOL hasLowPowerAbility;

/// Whether the device has remote wakeup ability
@property (nonatomic, assign, readonly) BOOL hasRemoteWakeupAbility;

@end

NS_ASSUME_NONNULL_END
