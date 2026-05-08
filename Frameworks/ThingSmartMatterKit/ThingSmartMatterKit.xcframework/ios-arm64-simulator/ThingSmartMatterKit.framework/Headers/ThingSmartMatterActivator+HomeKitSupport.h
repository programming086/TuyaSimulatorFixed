
#import "ThingSmartMatterActivator.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartMatterActivator (HomeKitSupport)

/// Pair matter device into Homekit.When success,you can only check device In Home App.
///
/// - Parameter matterCode: The matter QRCode string or Manual Code string.
///   - success: Called when the task is finished.
///   - failure: Called when the task is interrupted by an error.
- (void)pairDeviceInHomeKit:(NSString *)matterCode success:(ThingSuccessHandler)success failure:(ThingFailureError)failure;

@end

NS_ASSUME_NONNULL_END
