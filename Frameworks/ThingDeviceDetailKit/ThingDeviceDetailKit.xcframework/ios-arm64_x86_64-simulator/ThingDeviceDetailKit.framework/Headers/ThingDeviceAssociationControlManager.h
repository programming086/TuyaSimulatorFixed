
#import <Foundation/Foundation.h>
#import "ThingDeviceAssociationControlConstants.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingDeviceAssociationControlManager : NSObject


#pragma mark - Multi-Control Association

/// Check if a device supports multi-control association.
/// - Parameter deviceId: Device ID
+ (BOOL)checkSupportMultiControl:(NSString *)deviceId;

/// Retrieve multi-control data point information for a device.
/// - Parameters:
///   - deviceId: Device ID
///   - success: Success callback
///   - failure: Failure callback
+ (void)getMultiControlDpWithDeviceId:(NSString *)deviceId success:(nullable void(^)(NSArray<ThingMultiControlDpInfo *> * _Nullable infos))success failure:(nullable void(^)(NSError *error))failure;

/// Retrieve multi-control group information for a device's data point.
/// - Parameters:
///   - deviceId: Device ID
///   - dpId: Multi-control data point ID
///   - success: Success callback
///   - failure: Failure callback
+ (void)getMultiControlGroupWithDeviceId:(NSString *)deviceId dpId:(long long)dpId success:(nullable void(^)(ThingMultiControlGroupInfo * _Nullable info))success failure:(nullable void(^)(NSError *error))failure;

/// Update the enable status of a multi-control group.
/// - Parameters:
///   - multiControlGroupId: Multi-control group ID
///   - enable: Enable status
///   - success: Success callback
///   - failure: Failure callback
+ (void)updateMultiControlGroupStatus:(long long)multiControlGroupId enable:(BOOL)enable success:(nullable void(^)(BOOL result))success failure:(nullable void(^)(NSError *error))failure;

/// Get devices in a home that support multi-control.
/// - Parameters:
///   - spaceId: Home ID
///   - success: Success callback
///   - failure: Failure callback
+ (void)getMultiControlDevicesWithSpaceId:(long long)spaceId success:(nullable void(^)(NSArray<ThingMultiControlDevice *> * _Nullable devices))success failure:(nullable void(^)(NSError *error))failure;

/// Get devices that can form a multi-control group with the specified device.
/// - Parameters:
///   - deviceId: Device ID
///   - spaceId: Home ID
///   - success: Success callback
///   - failure: Failure callback
+ (void)getMultiControlDevicesWithDeviceId:(NSString *)deviceId spaceId:(long long)spaceId success:(nullable void(^)(NSArray<ThingMultiControlDevice *> * _Nullable devices))success failure:(nullable void(^)(NSError *error))failure;

/// Get available data point information for forming a multi-control group with another device.
/// - Parameters:
///   - deviceId: Device ID
///   - targetDeviceId: Target device ID
///   - targetDpId: Target device data point ID
///   - spaceId: Home ID
///   - success: Success callback
///   - failure: Failure callback
+ (void)getAvailableMultiControlDpWithDeviceId:(NSString *)deviceId targetDevice:(NSString *)targetDeviceId targetDpId:(long long)targetDpId spaceId:(long long)spaceId success:(nullable void(^)(ThingMultiControlDeviceDpsInfo * _Nullable info))success failure:(nullable void(^)(NSError *error))failure;

/// Update multi-control group details.
/// - Parameters:
///   - multiControlGroupId: Multi-control group ID
///   - name: Group name
///   - spaceId: Home ID
///   - deviceDps: List of device and data point IDs
///   - success: Success callback
///   - failure: Failure callback
+ (void)updateMultiControlGroup:(long long)multiControlGroupId name:(NSString *)name spaceId:(long long)spaceId deviceDps:(NSArray<NSDictionary *> *)deviceDps success:(nullable void(^)(ThingMultiControlGroup *result))success failure:(nullable void(^)(NSError *error))failure;


#pragma mark - Double-Control Association

/// Check if a device supports double-control association.
/// - Parameter deviceId: Device ID
+ (BOOL)checkSupportDoubleControl:(NSString *)deviceId;

/// Retrieve double-control group information for a device.
/// - Parameters:
///   - deviceId: Device ID
///   - spaceId: Home ID
///   - success: Success callback
///   - failure: Failure callback
+ (void)getDoubleControlGroupWithDeviceId:(NSString *)deviceId spaceId:(long long)spaceId success:(nullable void(^)(ThingDoubleControlGroup * _Nullable info))success failure:(nullable void(^)(NSError *error))failure;

/// Remove a slave device from a double-control association.
/// - Parameters:
///   - deviceId: Device ID
///   - spaceId: Home ID
///   - success: Success callback
///   - failure: Failure callback
+ (void)removeDoubleControlSlaveDeviceWithDeviceId:(NSString *)deviceId spaceId:(long long)spaceId success:(nullable void(^)(void))success failure:(nullable void(^)(NSError *error))failure;

/// Get a list of slave devices that can form a double-control association with a main device.
/// - Parameters:
///   - mainDeviceId: Main device ID
///   - spaceId: Home ID
///   - success: Success callback
///   - failure: Failure callback
+ (void)getDoubleControlAvailableSlaveDevicesWithMainDeviceId:(NSString *)mainDeviceId spaceId:(long long)spaceId success:(nullable void(^)(NSArray<ThingDoubleControlDevice *> * _Nullable devices))success failure:(nullable void(^)(NSError *error))failure;

/// Update the association of slave devices with a main device for double-control.
/// - Parameters:
///   - mainDeviceId: Main device ID
///   - slaveDeviceIds: List of slave device IDs
///   - spaceId: Home ID
///   - success: Success callback
///   - failure: Failure callback
+ (void)updateDoubleControlWithMainDeviceId:(NSString *)mainDeviceId slaveDeviceIds:(NSArray<NSString *> *)slaveDeviceIds spaceId:(long long)spaceId success:(nullable void(^)(void))success failure:(nullable void(^)(NSError *error))failure;

/// Retrieve the data point relationship between main and slave devices for double-control.
/// - Parameters:
///   - mainDeviceId: Main device ID
///   - slaveDeviceId: Slave device ID
///   - spaceId: Home ID
///   - success: Success callback
///   - failure: Failure callback
+ (void)getDoubleControlDPRelationWithMainDeviceId:(NSString *)mainDeviceId slaveDeviceId:(NSString *)slaveDeviceId spaceId:(long long)spaceId success:(nullable void(^)(ThingDoubleControlDPRelation * _Nullable relation))success failure:(nullable void(^)(NSError *error))failure;

/// Retrieve localized data point information for a device.
/// - Parameters:
///   - deviceId: Device ID
///   - spaceId: Home ID
///   - success: Success callback
///   - failure: Failure callback
+ (void)getLocalizedDpInfoWithDeviceId:(NSString *)deviceId spaceId:(long long)spaceId success:(nullable void(^)(NSArray<ThingDoubleControlDPInfo *> * _Nullable infos))success failure:(nullable void(^)(NSError *error))failure;

/// Update the data point relationships for double-control association.
/// - Parameters:
///   - mainDeviceId: Main device ID
///   - slaveDeviceId: Slave device ID
///   - relations: Map of relationships between main and slave device data points
///   - spaceId: Home ID
///   - success: Success callback
///   - failure: Failure callback
+ (void)updateDoubleControlDpRelationWithMainDeviceId:(NSString *)mainDeviceId slaveDeviceId:(NSString *)slaveDeviceId relations:(NSDictionary<NSString *, NSString *> *)relations spaceId:(long long)spaceId success:(nullable void(^)(void))success failure:(nullable void(^)(NSError *error))failure;

@end

NS_ASSUME_NONNULL_END
