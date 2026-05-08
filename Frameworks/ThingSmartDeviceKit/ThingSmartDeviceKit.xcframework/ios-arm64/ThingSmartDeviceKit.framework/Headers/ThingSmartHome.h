//
//  ThingSmartHome.h
//  ThingSmartDeviceKit
//
//  Copyright (c) 2014-2024.
//

#import <Foundation/Foundation.h>
#import "ThingSmartHomeModel.h"
#import <ThingSmartDeviceCoreKit/ThingSmartDeviceCoreKit.h>
#import "ThingSmartRoomModel.h"
#import "ThingSmartHomeMemberModel.h"
#import "ThingSmartHomeAddMemberRequestModel.h"

@class ThingSmartHome;

@protocol ThingSmartHomeDelegate <NSObject>

@optional


/// The delegate of home update information, such as the name and online status.
///
/// @param home The instance.
- (void)homeDidUpdateInfo:(ThingSmartHome *)home;

/// The delegate of updates on the shared device list.
///
/// @param home The instance.
- (void)homeDidUpdateSharedInfo:(ThingSmartHome *)home;


/// The delegate that is instantiated when a new room is added.
///
/// @param home The instance.
/// @param room The room model.
- (void)home:(ThingSmartHome *)home didAddRoom:(ThingSmartRoomModel *)room;


/// The delegate that is instantiated when an existing room is removed.
///
/// @param home The instance.
/// @param roomId The room ID.
- (void)home:(ThingSmartHome *)home didRemoveRoom:(long long)roomId;


/// The delegate of room update information, such as the name.
///
/// @param home The instance.
/// @param room The room model.
- (void)home:(ThingSmartHome *)home roomInfoUpdate:(ThingSmartRoomModel *)room;


/// The delegate of updates on the relationship among rooms, groups, and devices.
///
/// @param home The instance.
/// @param room The room model.
- (void)home:(ThingSmartHome *)home roomRelationUpdate:(ThingSmartRoomModel *)room;


/// The delegate that is instantiated when a new device is added.
///
/// @param home The instance.
/// @param device The device model.
- (void)home:(ThingSmartHome *)home didAddDeivice:(ThingSmartDeviceModel *)device;


/// The delegate that is instantiated when an existing device is removed.
///
/// @param home The instance.
/// @param devId The device ID
- (void)home:(ThingSmartHome *)home didRemoveDeivice:(NSString *)devId;


/// The delegate of device update information, such as the name.
///
/// @param home The instance.
/// @param device The device model.
- (void)home:(ThingSmartHome *)home deviceInfoUpdate:(ThingSmartDeviceModel *)device;


/// The delegate of device DPs update.
///
/// @param home The instance.
/// @param device The device model.
/// @param dps The DPs.
- (void)home:(ThingSmartHome *)home device:(ThingSmartDeviceModel *)device dpsUpdate:(NSDictionary *)dps;


/// The delegate of warning information updates.
///
/// @param home The instance.
/// @param device The device model.
/// @param warningInfo The warning information.
- (void)home:(ThingSmartHome *)home device:(ThingSmartDeviceModel *)device warningInfoUpdate:(NSDictionary *)warningInfo;


/// The delegate of changes in device firmware update status.
///
/// @param home The home instance.
/// @param device The device model.
/// @param upgradeStatusModel The update status model.
- (void)home:(ThingSmartHome *)home device:(ThingSmartDeviceModel *)device firmwareUpgradeStatusModel:(ThingSmartFirmwareUpgradeStatusModel *)upgradeStatusModel;


/// The delegate of over-the-air (OTA) updates for homes or shared devices.
/// @param home The home instance.
/// @param otaModelList The OTA model list.
- (void)home:(ThingSmartHome *)home didUpdateOTAModelList:(NSArray<ThingSmartDeviceOTAModel *> *)otaModelList;

/// The delegate that is instantiated when a new group is added.
///
/// @param home The instance.
///  @param group The group model.
- (void)home:(ThingSmartHome *)home didAddGroup:(ThingSmartGroupModel *)group;


/// The delegate of group DP updates.
///
/// @param home The instance.
/// @param group The group model.
/// @param dps The DPs.
- (void)home:(ThingSmartHome *)home group:(ThingSmartGroupModel *)group dpsUpdate:(NSDictionary *)dps;


/// The delegate that is instantiated when a group is removed.
///
/// @param home The instance.
/// @param groupId The group ID.
- (void)home:(ThingSmartHome *)home didRemoveGroup:(NSString *)groupId;


/// The delegate of the group update information, such as the name.
///
/// @param home The instance.
/// @param group The group model.
- (void)home:(ThingSmartHome *)home groupInfoUpdate:(ThingSmartGroupModel *)group;

#pragma mark - deprecated

/// The delegate of the update on the relationship between homes and rooms. (deprecated)
///
/// @param home The instance.
/// @deprecated This method is deprecated. Use ThingSmartHomeDelegate::home:didAddRoom: or ThingSmartHomeDelegate::home:didRemoveRoom: instead.
- (void)homeDidUpdateRoomInfo:(ThingSmartHome *)home __deprecated_msg("Use -[ThingSmartHomeDelegate home:didAddRoom:] or [ThingSmartHomeDelegate home:didRemoveRoom:] instead.");

/// The delegate of changes in device firmware update status.
///
/// @param home The instance.
/// @param device The device model.
/// @param upgradeStatus The update status.
/// @deprecated This method is deprecated. Use ThingSmartHomeDelegate::home:device:firmwareUpgradeStatusModel: instead.
- (void)home:(ThingSmartHome *)home device:(ThingSmartDeviceModel *)device upgradeStatus:(ThingSmartDeviceUpgradeStatus)upgradeStatus __deprecated_msg("This method is deprecated, Use home:device:firmwareUpgradeStatusModel: instead");

@end

@interface ThingSmartHome : NSObject
@property (nonatomic, assign, readonly) long long homeId;
@property (nonatomic, weak) id <ThingSmartHomeDelegate> delegate;

@property (nonatomic, strong, readonly) ThingSmartHomeModel *homeModel;

@property (nonatomic, copy, readonly) NSArray <ThingSmartRoomModel *> *roomList;

@property (nonatomic, copy, readonly) NSArray <ThingSmartDeviceModel *> *deviceList;

@property (nonatomic, copy, readonly) NSArray <ThingSmartDeviceModel *> *localDeviceList;

@property (nonatomic, copy, readonly) NSArray <ThingSmartGroupModel *> *groupList;

@property (nonatomic, copy, readonly) NSArray <ThingSmartDeviceModel *> *sharedDeviceList;

@property (nonatomic, copy, readonly) NSArray <ThingSmartGroupModel *>  *sharedGroupList;

@property (nonatomic, copy, readonly) NSArray <ThingSmartDeviceOTAModel *> *deviceOtaList;

/// Initializes the home.
///
/// @param homeId The home ID.
/// @return The instance.
+ (instancetype)homeWithHomeId:(long long)homeId;

- (instancetype)init NS_UNAVAILABLE;

#pragma mark - Home

/// After the home object is initialized, you must get the details of the home, homeModel, roomList, deviceList, and groupList to set the data.
/// @param success Called when the task is finished. ThingSmartHomeModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getHomeDataWithSuccess:(void (^)(ThingSmartHomeModel *homeModel))success
                       failure:(ThingFailureError)failure;

/// get local devices
/// @param success Called when the task is finished
/// @param failure Called when the task is interrupted by an error
- (void)getHomeLocalDevicesWithSuccess:(ThingSuccessHandler)success failure:(ThingFailureError)failure;

/// get local device config info
/// @param devId devId of local device
/// @param success Called when the task is finished
/// @param failure Called when the task is interrupted by an error
- (void)getLoalDeviceConfigWithDevId:(NSString *)devId
                             success:(ThingSuccessDict)success
                             failure:(ThingFailureError)failure;

- (void)getHomeDeviceSortWithSuccess:(ThingSuccessHandler)success
                             failure:(ThingFailureError)failure;

/// After the home details are returned, the device OTA update status is changed.
/// @param homeId The home ID.
/// @param success Called when the task is finished.
/// @param failure  Called when the task is interrupted by an error.
- (void)getDeviceOTAStatusWithHomeId:(long long)homeId
                             success:(void (^)(NSArray<ThingSmartDeviceOTAModel *> *))success
                             failure:(ThingFailureError)failure;


/// Updates the home information. API version 2.0 is used.
///
/// @param homeName    The home name.
/// @param geoName     The city name.
/// @param latitude    The latitude.
/// @param longitude   The longitude.
/// @param success     Called when the task is finished.
/// @param failure     Called when the task is interrupted by an error.
- (void)updateHomeInfoWithName:(NSString *)homeName
                       geoName:(NSString *)geoName
                      latitude:(double)latitude
                     longitude:(double)longitude
                       success:(ThingSuccessHandler)success
                       failure:(ThingFailureError)failure;



/// Updates the home information. API version 3.0 is used.
///
/// @param homeName    The home name.
/// @param geoName     The city name.
/// @param latitude    The latitude.
/// @param longitude   The longitude.
/// @param rooms       The array of room names.
/// @param overWriteRoom     NSDictionary only supports "overWriteRoom":boolean.
/// @param success     Called when the task is finished.
/// @param failure     Called when the task is interrupted by an error.
- (void)updateHomeInfoWithName:(NSString *)homeName
                       geoName:(NSString *)geoName
                      latitude:(double)latitude
                     longitude:(double)longitude
                         rooms:(NSArray *)rooms
                 overWriteRoom:(BOOL)overWriteRoom
                       success:(ThingSuccessHandler)success
                       failure:(ThingFailureError)failure;


/// Removes a home.
///
/// @param success     Called when the task is finished.
/// @param failure     Called when the task is interrupted by an error.
- (void)dismissHomeWithSuccess:(ThingSuccessHandler)success
                       failure:(ThingFailureError)failure;


/// Sorts devices and groups for the home.
/// @param orderList The order list [@{@"bizId": @"XXX", @"bizType": @"XXX"},@{@"bizId": @"XXX",@"bizType": @"XXX"}], where bizId is the device's device ID or group's group ID, device's bizType = @"6" group's bizType = @"5".
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)sortDeviceOrGroupWithOrderList:(NSArray<NSDictionary *> *)orderList
                               success:(ThingSuccessHandler)success
                               failure:(ThingFailureError)failure;

/// Update releations for the home
/// including how many rooms in the home,
/// how many devices and groups in the room,
/// how many groups in the mesh
/// how many devices in the group,
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)updateReleationsWithSuccess:(ThingSuccessHandler)success
                                 failure:(ThingFailureError)failure;


#pragma mark - Room

/// Get room List.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)getRoomListWithSuccess:(nullable ThingSuccessHandler)success
                       failure:(nullable ThingFailureError)failure;
/// Adds a new room.
///
/// @param name        The room name.
/// @param success     Called when the task is finished.
/// @param failure     Called when the task is interrupted by an error.
- (void)addHomeRoomWithName:(NSString *_Nonnull)name
                    success:(ThingSuccessHandler _Nullable )success
                    failure:(ThingFailureError _Nullable )failure __deprecated_msg("This method is deprecated, Use [ThingSmartHome addHomeRoomWithName:completion:failure:] instead");

/// Adds a new room.
///
/// @param name        The room name.
/// @param roomTagId   Can associate multiple rooms with the same tag (room tag will be available in the future).
/// @param success     Called when the task is finished.
/// @param failure     Called when the task is interrupted by an error.
- (void)addHomeRoomWithName:(NSString *_Nonnull)name
                  roomTagId:(long long)roomTagId
                    success:(ThingSuccessHandler _Nullable )success
                    failure:(ThingFailureError _Nullable)failure;

/// Adds a new room.
///
/// @param name        The room name.
/// @param completion     Called when the task is finished.
/// @param failure     Called when the task is interrupted by an error.
- (void)addHomeRoomWithName:(NSString *_Nonnull)name
                 completion:(void(^_Nullable)(ThingSmartRoomModel * _Nonnull roomModel))completion
                    failure:(ThingFailureError _Nullable )failure;


/// Remove a room
///
/// @param roomId      The home ID.
/// @param success     Called when the task is finished.
/// @param failure     Called when the task is interrupted by an error.
- (void)removeHomeRoomWithRoomId:(long long)roomId
                         success:(ThingSuccessHandler)success
                         failure:(ThingFailureError)failure;


/// Sorts the homes.
///
/// @param roomList    A list of homes.
/// @param success     Called when the task is finished.
/// @param failure     Called when the task is interrupted by an error.
- (void)sortRoomList:(NSArray <ThingSmartRoomModel *> *)roomList
             success:(ThingSuccessHandler)success
             failure:(ThingFailureError)failure;


#pragma mark - home member

/// Returns a list of home members
///
/// @param success     Called when the task is finished. A list of ThingSmartHomeMemberModel is returned.
/// @param failure     Called when the task is interrupted by an error.
- (void)getHomeMemberListWithSuccess:(void(^)(NSArray <ThingSmartHomeMemberModel *> *memberList))success
                             failure:(ThingFailureError)failure;


/// Adds a home member.
///
/// @param requestModel The member model.
/// @param success      Called when the task is finished.
/// @param failure      Called when the task is interrupted by an error.
- (void)addHomeMemberWithAddMemeberRequestModel:(ThingSmartHomeAddMemberRequestModel *)requestModel
                                        success:(ThingSuccessDict)success
                                        failure:(ThingFailureError)failure;

/// Accepts or rejects to share the home.
///
/// @param accept       A Boolean value that specifies whether to accept the invitation.
/// @param success      Called when the task is finished.
/// @param failure      Called when the task is interrupted by an error.
- (void)joinFamilyWithAccept:(BOOL)accept
                     success:(ThingSuccessBOOL)success
                     failure:(ThingFailureError)failure;


/// Synchronizes the home device list.
///
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)syncHomeDeviceListWithSuccess:(ThingSuccessHandler)success
                              failure:(ThingFailureError)failure;

@end
