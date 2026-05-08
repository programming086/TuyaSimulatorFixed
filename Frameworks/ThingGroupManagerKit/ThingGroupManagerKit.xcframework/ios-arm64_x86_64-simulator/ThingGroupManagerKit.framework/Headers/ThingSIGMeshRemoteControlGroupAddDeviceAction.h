
#import <Foundation/Foundation.h>
#import <ThingSmartDeviceCoreKit/ThingSmartDeviceCoreKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSIGMeshRemoteControlGroupAddDeviceAction : NSObject

- (instancetype)initWithDeviceId:(NSString *)deviceId localId:(NSString *)localId timeout:(NSInteger)timeout success:(void(^)(void))success failure:(void(^)(NSError *error))failure;

- (void)add;

#pragma mark - ThingBluetoothInterfaceGroupServiceProtocol 
/**
 Add devices to a sigmesh remote control group.
 If a device's local groups exceed 8, it will first delete invalid groups and then re-add the device.
 When adding a device to a group or removing it from a group, you need to listen to ThingBluetoothInterfaceGroupServiceProtocol. However, both ThingBluetoothInterfaceService and ThingBluetoothBleMesh have a single delegate; setting the delegate internally will lead to overwriting, which might cause unnecessary issues.
 */

// Callback for adding a device to a group
- (void)didAddToGroupWithError:(NSError *)error;

// Fetch the list of local groups for the device
- (void)didFetchGroupList:(NSArray<NSString *> *)groupList;

// Callback for removing a device from a group, where the group might only have localId with a value.
- (void)didRemoveFromGroup:(ThingSmartGroupModel *)group error:(NSError *)error;


@end

NS_ASSUME_NONNULL_END
