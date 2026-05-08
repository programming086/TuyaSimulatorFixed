
#import <Foundation/Foundation.h>
#import <ThingSmartDeviceKit/ThingSmartDeviceKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartAutoActivator (Home)

/// Returns all devices for the current home that supports the password-free pairing function.
/// @param homeId The home ID.
/// @return All devices in the home that supports the password-free pairing function.
- (NSArray <ThingSmartDeviceModel *> *)autoActiveSupportedDeviceListWithHomeId:(long long)homeId;

/// Returns all gateway router devices for the current home.
/// @param homeId The home ID.
/// @return A list of all home gateway router devices.
/// @deprecated This method is deprecated. Use ThingSmartRouterActivator::autoActiveRouterDeviceListWithHomeId: instead.
- (NSArray <ThingSmartDeviceModel *> *)autoActiveRouterDeviceListWithHomeId:(long long)homeId __deprecated_msg("Use -[ThingSmartRouterActivator autoActiveRouterDeviceListWithHomeId:] instead.");


/// Adds devices to a specified home.
/// @param homeId The home ID.
/// @param devIds A list of device IDs.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)bindDeviceWithHomeId:(long long)homeId devIds:(NSArray <NSString *>*)devIds success:(ThingSuccessHandler)success failure:(ThingFailureError)failure;

@end

NS_ASSUME_NONNULL_END
