//
// TuyaSmartBLEManager.h
// TuyaSmartBLEKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)


#import "TuyaSmartBeaconManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartBeaconManager (Group)


/// Creates a group in the cloud.
/// @param groupName The group name.
/// @param homeId Current home id
/// @param productId The product ID of the device.
/// @param beaconCategory The device category.
/// @param success Called when the task is finished. The value of groupId is returned.
/// @param failure Called when the task is interrupted by an error.
+ (void)createBeaconGroupWithGroupName:(NSString *)groupName
                                homeId:(long long)homeId
                             productId:(NSString *)productId
                                   pcc:(NSString *)beaconCategory
                               success:(void(^)(NSString *result))success
                               failure:(void(^)(NSError *error))failure;


/// Adds a device to the group.
/// @param devId The device ID.
/// @param groupId The group ID.
/// @param success Called when the task is finished. The device group data is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)addDeviceToGroupWithDevId:(NSString *)devId
                          groupId:(NSString *)groupId
                          success:(void(^)(NSData *data))success
                          failure:(void(^)(NSError *error))failure;

/// Deletes a device from the group.
/// @param devId The device ID.
/// @param groupId The group ID.
/// @param success Called when the task is finished. The device group data is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)deleteDeviceFromGroupWithDevId:(NSString *)devId
                               groupId:(NSString *)groupId
                               success:(void(^)(NSData *data))success
                               failure:(void(^)(NSError *error))failure;

/// Queries device groups.
/// @param devId The device ID.
/// @param success Called when the task is finished. The device group data is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)queryGroupsWithDevId:(NSString *)devId
                     success:(void(^)(NSData *data))success
                     failure:(void(^)(NSError *error))failure;

/// Sends a DP to the group.
/// @param dps The DP command.
/// @param devId The device ID.
/// @param groupId The group ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)publishGroupDps:(NSDictionary *)dps
             firstDevId:(NSString *)devId
                groupId:(NSString *)groupId
                success:(nullable void(^)(void))success
                failure:(void(^)(NSError *error))failure;


/// Removes the group with a specific address.
/// @param groupId The group ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)removeDeviceGroupWithGroupId:(NSString *)groupId
                            success:(nullable void(^)(void))success
                             failure:(void(^)(NSError *error))failure;

/// Adds a device to the cloud.
/// @param groupId The group ID.
/// @param deviceId The device ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
+ (void)addDeviceWithGroupId:(NSString *)groupId
                    deviceId:(NSString *)deviceId
                    success:(void(^)(void))success
                     failure:(void(^)(NSError *error))failure;

/// The specified device is deleted from the group.
/// @param groupId The group ID.
/// @param deviceId The device ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)removeDeviceWithGroupId:(NSString *)groupId
                       deviceId:(NSString *)deviceId
                        success:(void(^)(void))success
                        failure:(void(^)(NSError *error))failure;


/// Removes the device from the cloud.
/// @param groupId The group ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
+ (void)removeBeaconGroupGroupId:(NSString *)groupId
                         success:(nullable void(^)(void))success
                         failure:(void(^)(NSError *error))failure;

@end

NS_ASSUME_NONNULL_END
