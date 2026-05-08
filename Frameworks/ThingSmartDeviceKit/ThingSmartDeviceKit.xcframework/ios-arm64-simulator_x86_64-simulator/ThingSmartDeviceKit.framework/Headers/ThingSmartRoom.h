//
//  ThingSmartRoom.h
//  ThingSmartDeviceKit
//
//  Copyright (c) 2014-2024.
//

#import <Foundation/Foundation.h>
#import "ThingSmartRoomModel.h"
#import <ThingSmartDeviceCoreKit/ThingSmartDeviceCoreKit.h>

@interface ThingSmartRoom : NSObject

/// The room model.
@property (nonatomic, strong, readonly) ThingSmartRoomModel *roomModel;

/// The device list.
@property (nonatomic, strong, readonly) NSArray <ThingSmartDeviceModel *> *deviceList;

/// The group list.
@property (nonatomic, strong, readonly) NSArray <ThingSmartGroupModel *> *groupList;


/// Returns the room instance.
///
/// @param roomId The room ID.
/// @param homeId The home ID.
/// @return The instance.
+ (instancetype)roomWithRoomId:(long long)roomId homeId:(long long)homeId;


/// Returns the room instance.
///
/// @param roomId The room ID.
/// @param homeId The home ID.
/// @return The instance.
- (instancetype)initWithRoomId:(long long)roomId homeId:(long long)homeId NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;


/// Renames the room.
///
/// @param roomName    The room name.
/// @param success     Called when the task is finished.
/// @param failure     Called when the task is interrupted by an error.
- (void)updateRoomName:(NSString *)roomName success:(ThingSuccessHandler)success failure:(ThingFailureError)failure;

/// Edits the room icon.
///
/// @param icon The room icon.
/// @param success  Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)updateIcon:(UIImage *)icon success:(nullable ThingSuccessHandler)success failure:(nullable ThingFailureError)failure;

/// Adds a device to the room.
///
/// @param deviceId    The device ID.
/// @param success     Called when the task is finished.
/// @param failure     Called when the task is interrupted by an error.
- (void)addDeviceWithDeviceId:(NSString *)deviceId success:(ThingSuccessHandler)success failure:(ThingFailureError)failure;


/// Removes a device from the room.
///
/// @param deviceId    The device ID.
/// @param success     Called when the task is finished.
/// @param failure     Called when the task is interrupted by an error.
- (void)removeDeviceWithDeviceId:(NSString *)deviceId success:(ThingSuccessHandler)success failure:(ThingFailureError)failure;


/// Adds a group to the room.
///
/// @param groupId     The group ID.
/// @param success     Called when the task is finished.
/// @param failure     Called when the task is interrupted by an error.
- (void)addGroupWithGroupId:(NSString *)groupId success:(ThingSuccessHandler)success failure:(ThingFailureError)failure;


/// Removes a group from the room
///
/// @param groupId     The group ID.
/// @param success     Called when the task is finished.
/// @param failure     Called when the task is interrupted by an error.
- (void)removeGroupWithGroupId:(NSString *)groupId success:(ThingSuccessHandler)success failure:(ThingFailureError)failure;


/// Modifies the relationships between rooms, groups, and devices in a call.
///
/// @param deviceGroupList  A list of devices or groups.
/// @param success          Called when the task is finished.
/// @param failure          Called when the task is interrupted by an error.
- (void)saveBatchRoomRelationWithDeviceGroupList:(NSArray <NSString *> *)deviceGroupList
                                         success:(ThingSuccessHandler)success
                                         failure:(ThingFailureError)failure;


/// Sort groups and devices in the room.
/// @param deviceGroupList A list of devices or groups.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)sortDeviceRelationWithList:(nonnull NSArray<NSString *> *)deviceGroupList
                           success:(nullable ThingSuccessHandler)success
                           failure:(nullable ThingFailureError)failure;



/// Incremental batch add devices and groups belonging room
/// @param deviceGroupList A list of devices or groups.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)increaseRoomRelationWithDeviceGroupList:(nonnull NSArray <NSString *> *)deviceGroupList
                                        success:(nullable ThingSuccessHandler)success
                                        failure:(nullable ThingFailureError)failure;
@end
