
#import <Foundation/Foundation.h>
#import <ThingSmartDeviceCoreKit/ThingSmartDeviceCoreKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSIGMeshRemoteControlGroupAddDeviceManager : NSObject

// The localId here refers to the local ID of the group
- (instancetype)initWithLocalId:(NSString *)localId timeout:(NSInteger)timeout;

- (void)addDeviceId:(NSString *)deviceId success:(void(^)(void))success failure:(void(^)(NSError *error))failure;

#pragma mark - ThingBluetoothInterfaceGroupServiceProtocol Notification Callbacks
/**
 Add devices to a sigmesh remote control group.
 If a device's local groups exceed 8, it will first delete invalid groups and then re-add the device.
 When adding a device to a group or removing it from a group, you need to listen to ThingBluetoothInterfaceGroupServiceProtocol. However, both ThingBluetoothInterfaceService and ThingBluetoothBleMesh have a single delegate; setting the delegate internally will lead to overwriting, which might cause unnecessary issues.
 */

// Callback for adding a device to a group
- (void)didAddDevice:(ThingSmartDeviceModel *)device toGroup:(ThingSmartGroupModel *)group error:(NSError *)error;

// Fetch the list of local groups for the device
- (void)didFetchDevice:(ThingSmartDeviceModel *)device groupList:(NSArray<NSString *> *)groupList;

// Callback for removing a device from a group
- (void)didRemoveDevice:(ThingSmartDeviceModel *)device toGroup:(ThingSmartGroupModel *)group error:(NSError *)error;


@end

NS_ASSUME_NONNULL_END
