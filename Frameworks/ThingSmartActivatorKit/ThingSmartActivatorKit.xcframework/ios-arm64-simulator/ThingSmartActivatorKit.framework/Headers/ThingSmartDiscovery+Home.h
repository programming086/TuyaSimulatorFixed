
#import <Foundation/Foundation.h>
#import <ThingSmartDeviceKit/ThingSmartDeviceKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartDiscovery (Home)

/// Adds devices to a specified home.
/// @param homeId The home ID.
/// @param devIds A list of device IDs.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)bindDeviceWithHomeId:(long long)homeId devIds:(NSArray <NSString *>*)devIds success:(ThingSuccessHandler)success failure:(ThingFailureError)failure;


@end

NS_ASSUME_NONNULL_END
