
#import <ThingSmartBLEMeshKit/ThingSmartBLEMeshKit.h>

NS_ASSUME_NONNULL_BEGIN

/// @brief The Bluetooth mesh activator category for the Bluetooth mesh manager.
///
/// This API provides multiple group management functions. For example, devices can be added to groups or removed from groups.
@interface ThingSmartSIGMeshManager (Group)

/// Adds a device to a group.
/// @param devId The device ID.
/// @param groupAddress The group address.
- (void)addDeviceToGroupWithDevId:(NSString *)devId
                     groupAddress:(uint32_t)groupAddress;

/// A new way to add device to group.
/// @param devId The device ID.
/// @param groupAddress The group address.
/// @param isAdd Whether to add device.
/// @param mainDevId Current device ID.
/// @param categoryCode The Specific Code.
- (void)handleDeviceToGroupWithDevId:(NSString *)devId groupAddress:(uint32_t)groupAddress isAdd:(BOOL)isAdd mainDevId:(NSString *)mainDevId categoryCode:(NSString *)categoryCode;

- (NSMutableArray<NSString *> *)findAllDevicesByVendorIdArray:(NSArray *)vendorIdArray;

/// Removes a device from a group.
/// @param devId The device ID.
/// @param groupAddress The group address.
- (void)deleteDeviceToGroupWithDevId:(NSString *)devId
                        groupAddress:(uint32_t)groupAddress;

/// Queries the devices in the group based on the group address.
/// @param groupAddress The group address.
- (void)queryGroupMemberWithGroupAddress:(uint32_t)groupAddress;


/// Queries the group list.
/// @param devId The device ID.
- (void)queryGroupListWithDevid:(NSString *)devId;

/// 获取sigmesh子设备列表
- (NSMutableArray<NSString *> *)getSIGMeshSubDeviceList;

@end

NS_ASSUME_NONNULL_END
