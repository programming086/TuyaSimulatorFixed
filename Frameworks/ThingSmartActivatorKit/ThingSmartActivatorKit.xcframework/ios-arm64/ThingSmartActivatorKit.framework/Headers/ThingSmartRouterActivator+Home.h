
#import <Foundation/Foundation.h>
#import <ThingSmartDeviceKit/ThingSmartDeviceKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartRouterActivator (Home)


/// Returns all gateway router devices for the current home.
/// @param homeId The home ID.
/// @return All home gateway router devices.
- (NSArray <ThingSmartDeviceModel *> *)autoActiveRouterDeviceListWithHomeId:(long long)homeId;


/// Adds devices to a specified home.
/// @param homeId The home ID.
/// @param devIds A list of device IDs.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)bindDeviceWithHomeId:(long long)homeId devIds:(NSArray <NSString *>*)devIds success:(ThingSuccessHandler)success failure:(ThingFailureError)failure;


@end

NS_ASSUME_NONNULL_END
