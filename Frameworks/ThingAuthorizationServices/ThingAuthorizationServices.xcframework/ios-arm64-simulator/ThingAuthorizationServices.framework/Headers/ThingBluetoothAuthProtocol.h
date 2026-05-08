
#import <Foundation/Foundation.h>
#import "ThingPrivacyAuthCustomConfig.h"

/** Bluetooth permission status
 *
 *  ThingCBAuthorizationStateUnknown：unknown status
 *  ThingCBAuthorizationStateResetting：Resetting, temporarily lost with system services
 *  ThingCBAuthorizationStateUnsupported： not support Bluetooth
 *  ThingCBAuthorizationStateUnauthorized：Unauthorized
 *  ThingCBAuthorizationStatePoweredOff：closure
 *  ThingCBAuthorizationStatePoweredOn：Enabled and available
 */
typedef NS_ENUM(NSInteger, ThingCBAuthorizationState) {
    ThingCBAuthorizationStateUnknown = 0,
    ThingCBAuthorizationStateResetting,
    ThingCBAuthorizationStateUnsupported,
    ThingCBAuthorizationStateUnauthorized,
    ThingCBAuthorizationStatePoweredOff,
    ThingCBAuthorizationStatePoweredOn
};

typedef NS_ENUM(NSInteger, ThingCBAuthorizationStatus) {
    ThingCBAuthorizationStatusUnable = -1,
    ThingCBAuthorizationStatusNotDetermined = 0,
    ThingCBAuthorizationStatusRestricted,
    ThingCBAuthorizationStatusDenied,
    ThingCBAuthorizationStatusAllowedAlways
};

NS_ASSUME_NONNULL_BEGIN

typedef void (^ThingBLEPowerStateChangedBlock)(ThingCBAuthorizationState state);

@protocol ThingBluetoothAuthProtocol <NSObject>

/// Singleton
+ (instancetype)shared;

/// Get the system Bluetooth switch status
///
/// This state is unstable and only one copy of the system state is stored.
/// The exact state should be obtained through the addObserver:bleStateChanged: method
///
/// Note: This status may return to PoweredOff or PoweredOn only when the APP Bluetooth permission status is AllowedAlways;
/// When the APP Bluetooth permission status is NotDetermined or Denied, this status returns Unauthorized;
/// Note the use of singleton calls
- (ThingCBAuthorizationState)systemPowerStatus;

/// Get the system Bluetooth switch status
+ (ThingCBAuthorizationState)systemPowerStatus;

/// Get APP Bluetooth permission status
/// Note the use of singleton calls
- (ThingCBAuthorizationStatus)authorizationState;

/// Get APP Bluetooth permission status
+ (ThingCBAuthorizationStatus)authorizationState;

/// Whether to enable the ability to use UI pop-up windows to explain permissions
/// Note the use of singleton calls
- (void)setEnableUI;

/// Whether to enable the ability to use UI pop-up windows to explain permissions
+ (void)setEnableUI;

/// Request Bluetooth permission (trigger system pop-up window)
/// Note the use of singleton calls
- (void)requestBluetoothAuthorizationWithCompletionHandler:(void(^)(ThingCBAuthorizationState state))completionHandler;

/// Request Bluetooth permission (trigger system pop-up window)
+ (void)requestBluetoothAuthorizationWithCompletionHandler:(void(^)(ThingCBAuthorizationState state))completionHandler;

/// Request Bluetooth permissions based on the source (trigger landing page)
///
/// Note the use of singleton calls
/// @param source source
/// @param completionHandler completionHandler
- (void)requestAuthorizationWithSource:(NSString *)source
                     completionHandler:(void(^)(ThingCBAuthorizationState state, ThingCBAuthorizationStatus status))completionHandler;

- (void)requestAuthorizationWithSource:(NSString *)source
                                config:(nullable ThingPrivacyAuthCustomConfig *)config
                     completionHandler:(void(^)(ThingCBAuthorizationState state, ThingCBAuthorizationStatus status))completionHandler;

+ (void)requestAuthorizationWithSource:(NSString *)source
                     completionHandler:(void(^)(ThingCBAuthorizationState state, ThingCBAuthorizationStatus status))completionHandler;

/// Note the use of singleton calls
- (void)addObserver:(id)observer bleStateChanged:(ThingBLEPowerStateChangedBlock)callback;
+ (void)addObserver:(id)observer bleStateChanged:(ThingBLEPowerStateChangedBlock)callback;

#pragma mark - deprecated

/// Check Bluetooth permissions
- (ThingCBAuthorizationState)bluetoothAuthorizationState __deprecated_msg("This method is deprecated, Use systemPowerStatus: instead");

/// Check Bluetooth permissions
+ (ThingCBAuthorizationState)bluetoothAuthorizationState __deprecated_msg("This method is deprecated, Use systemPowerStatus: instead");

/// Check Bluetooth permissions
- (ThingCBAuthorizationStatus)bluetoothAuthorizationStatus __deprecated_msg("This method is deprecated, Use authorizationState: instead");

/// Check Bluetooth permissions
+ (ThingCBAuthorizationStatus)bluetoothAuthorizationStatus __deprecated_msg("This method is deprecated, Use authorizationState: instead");

/// Get Bluetooth permissions
/// @param completionHandler completionHandler
- (void)getBluetoothAuthorizationStatusWithCompletionHandler:(void(^)(ThingCBAuthorizationStatus status))completionHandler __deprecated_msg("This method is deprecated, Use authorizationState: instead");

/// Get Bluetooth permissions
/// @param completionHandler completionHandler
+ (void)getBluetoothAuthorizationStatusWithCompletionHandler:(void(^)(ThingCBAuthorizationStatus status))completionHandler __deprecated_msg("This method is deprecated, Use authorizationState: instead");

/// Get Bluetooth permissions
/// @param completionHandler completionHandler
- (void)getBluetoothAuthorizationStateWithCompletionHandler:(void(^)(ThingCBAuthorizationState state))completionHandler __deprecated_msg("This method is deprecated, Use systemPowerStatus: instead");

/// Get Bluetooth permissions
/// @param completionHandler completionHandler
+ (void)getBluetoothAuthorizationStateWithCompletionHandler:(void(^)(ThingCBAuthorizationState state))completionHandler __deprecated_msg("This method is deprecated, Use systemPowerStatus: instead");

@end

NS_ASSUME_NONNULL_END
