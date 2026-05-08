
#import <Foundation/Foundation.h>
#import <ThingSmartDeviceKit/ThingSmartDeviceKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartPegasusActivator (Home)

/// Returns the devices that support Pegasus.
/// @param homeID The home ID.
/// @return A list of devices that support Pegasus.
+ (NSArray <ThingSmartDeviceModel *> *)pegasusDeviceListWithHomeID:(long long)homeID;


@end

NS_ASSUME_NONNULL_END
