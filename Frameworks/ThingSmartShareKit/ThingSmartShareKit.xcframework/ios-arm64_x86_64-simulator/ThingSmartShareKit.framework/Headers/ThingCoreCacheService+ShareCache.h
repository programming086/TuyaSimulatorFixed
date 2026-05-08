
#import <ThingSmartDeviceCoreKit/ThingCoreCacheService.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingCoreCacheService (ShareCache)

#pragma mark - shared device and group

/// Returns a list of shared devices, determined by the `isShare` field, which is modified within the ThingSmartDeviceKit.
/// The synchronous queue.
- (NSArray <ThingSmartDeviceModel *> *)getSharedDeviceList;

/// Returns a list of shared groups, determined by the `isShare` field, which is modified within the ThingSmartDeviceKit.
/// The synchronous queue.
- (NSArray <ThingSmartGroupModel *> *)getSharedGroupList;

/// Updates the device sharing list.
/// The asynchronous queue.
///
/// @param deviceList The device sharing list.
- (void)updateSharedDeviceList:(NSArray <ThingSmartDeviceModel *> *)deviceList;

/// Updates the group sharing list.
/// The asynchronous queue.
///
/// @param groupList The group sharing list.
- (void)updateSharedGroupList:(NSArray <ThingSmartGroupModel *> *)groupList;

/// This is a type of device that supports special sharing, such as sharing the home and sharing the device at the same time.
/// 
- (NSArray <NSString *> *)getSpecialSharedDevIds __deprecated_msg("This method is deprecated; it will always return an empty array. Instead, retrieve the list of devices in the home and use the isDeviceShared: method to check if each device is shared.");


/// Valid whether the device is shared, based on the results of the server side.
/// @param deviceId the device id
- (BOOL)isDeviceShared:(NSString *)deviceId;

/// Valid whether the group is shared, based on the results of the server side.
/// @param groupId the group id
- (BOOL)isGroupShared:(NSString *)groupId;

/// Get all shared device ids, based on the results of the server side.
- (NSArray <NSString *> *)getAllSharedDeviceIds;

/// Get all shared group ids, based on the results of the server side.
- (NSArray <NSString *> *)getAllSharedGroupIds;

@end

NS_ASSUME_NONNULL_END
