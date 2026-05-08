
#import "ThingSmartBeaconManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartBeaconManager (ThingDeprecatedAPI)

/// Creates a group in the cloud.
/// @param groupName The group name.
/// @param productId The product ID of the device.
/// @param beaconCategory The device category.
/// @param success Called when the task is finished. The value of groupId is returned.
/// @param failure Called when the task is interrupted by an error.
+ (void)createBeaconGroupWithGroupName:(NSString *)groupName
                             productId:(NSString *)productId
                                   pcc:(NSString *)beaconCategory
                               success:(void(^)(NSString *result))success
                               failure:(void(^)(NSError *error))failure DEPRECATED_MSG_ATTRIBUTE("use `createBeaconGroupWithGroupName:homeId:productId:pcc:success:failure:` instead");


/// Activates the beacon device.
/// @param advModel The advertisingData model for the beacon device.
/// @param homeId The ID for the current home.
/// @param success Called when the task is finished. DeviceModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)activeBeacon:(ThingBLEAdvModel *)advModel homeId:(long long)homeId success:(void (^)(ThingSmartDeviceModel *deviceModel))success failure:(void(^)(NSError *error))failure __deprecated_msg("use `activateBeacon:homeId:success:failure:` instead");


/// The end of the pairing process.
- (void)stopActive __deprecated_msg("use `stopActivatingBeacons:` instead");
@end

NS_ASSUME_NONNULL_END
