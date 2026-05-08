//
//  TuyaResidenceSite.h
//  TuyaSmartResidenceKit
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com/)

#import <Foundation/Foundation.h>
#import <TuyaSmartDeviceCoreKit/TuyaSmartDeviceCoreKit.h>
#import <TuyaSmartUtil/TuyaSmartUtil.h>
#import <TuyaSmartResidenceKit/TuyaResidenceExpiredAuthorModel.h>
#import <TuyaSmartResidenceKit/TuyaResidentSiteModelUtils.h>

@class TuyaResidenceSiteModel;
@class TuyaResidenceRoomModel;
@class TuyaResidenceSiteMemberModel;
@class TuyaResidenceSite;

NS_ASSUME_NONNULL_BEGIN

@protocol TuyaResidenceSiteDelegate <NSObject>

@optional

/// The delegate of site update information, such as the name and online status.
///
/// @param site The instance.
- (void)siteDidUpdateInfo:(TuyaResidenceSite *)site;

/// The delegate of updates on the shared device list.
///
/// @param site The instance.
- (void)siteDidUpdateSharedInfo:(TuyaResidenceSite *)site;

/// The delegate of room update information, such as the name.
///
/// @param site The instance.
/// @param room The room model.
- (void)site:(TuyaResidenceSite *)site roomInfoUpdate:(TuyaResidenceRoomModel *)room;


/// The delegate of updates on the relationship among rooms, groups, and devices.
///
/// @param site The instance.
/// @param room The room model.
- (void)site:(TuyaResidenceSite *)site roomRelationUpdate:(TuyaResidenceRoomModel *)room;

/// The delegate that is instantiated when a new device is added.
///
/// @param site The instance.
/// @param device The device model.
- (void)site:(TuyaResidenceSite *)site didAddDeivice:(TuyaSmartDeviceModel *)device;

/// The delegate that is instantiated when an existing device is removed.
///
/// @param site The instance.
/// @param devId The device ID
- (void)site:(TuyaResidenceSite *)site didRemoveDeivice:(NSString *)devId;

/// The delegate of device update information, such as the name.
///
/// @param site The instance.
/// @param device The device model.
- (void)site:(TuyaResidenceSite *)site deviceInfoUpdate:(TuyaSmartDeviceModel *)device;

/// The delegate of device DPs update.
///
/// @param site The instance.
/// @param device The device model.
/// @param dps The DPs.
- (void)site:(TuyaResidenceSite *)site device:(TuyaSmartDeviceModel *)device dpsUpdate:(NSDictionary *)dps;

/// The delegate of warning information updates.
///
/// @param site The instance.
/// @param device The device model.
/// @param warningInfo The warning information.
- (void)site:(TuyaResidenceSite *)site device:(TuyaSmartDeviceModel *)device warningInfoUpdate:(NSDictionary *)warningInfo;

/// The delegate of changes in device firmware update status.
///
/// @param site The site instance.
/// @param device The device model.
/// @param upgradeStatusModel The update status model.
- (void)site:(TuyaResidenceSite *)site device:(TuyaSmartDeviceModel *)device firmwareUpgradeStatusModel:(TuyaSmartFirmwareUpgradeStatusModel *)upgradeStatusModel;

/// The delegate that is instantiated when a new group is added.
///
/// @param site The instance.
///  @param group The group model.
- (void)site:(TuyaResidenceSite *)site didAddGroup:(TuyaSmartGroupModel *)group;

/// The delegate of group DP updates.
///
/// @param site The instance.
/// @param group The group model.
/// @param dps The DPs.
- (void)site:(TuyaResidenceSite *)site group:(TuyaSmartGroupModel *)group dpsUpdate:(NSDictionary *)dps;

/// The delegate that is instantiated when a group is removed.
///
/// @param site The instance.
/// @param groupId The group ID.
- (void)site:(TuyaResidenceSite *)site didRemoveGroup:(NSString *)groupId;

/// The delegate of the group update information, such as the name.
///
/// @param site The instance.
/// @param group The group model.
- (void)site:(TuyaResidenceSite *)site groupInfoUpdate:(TuyaSmartGroupModel *)group;

#pragma mark - deprecated

/// The delegate of changes in device firmware update status.
///
/// @param site The instance.
/// @param device The device model.
/// @param upgradeStatus The update status.
/// @deprecated This method is deprecated. Use TuyaResidenceSiteDelegate::home:device:firmwareUpgradeStatusModel: instead.
- (void)site:(TuyaResidenceSite *)site device:(TuyaSmartDeviceModel *)device upgradeStatus:(TuyaSmartDeviceUpgradeStatus)upgradeStatus __deprecated_msg("This method is deprecated, Use site:device:firmwareUpgradeStatusModel: instead");

@end

@interface TuyaResidenceSite : NSObject

@property (nonatomic, strong, readonly) TuyaResidenceSiteModel *siteModel;

@property (nonatomic, assign, readonly) long long siteId;

@property (nonatomic, weak) id <TuyaResidenceSiteDelegate> delegate;

@property (nonatomic, copy, readonly) NSArray <TuyaResidenceRoomModel *> *roomList;

@property (nonatomic, copy, readonly) NSArray <TuyaSmartDeviceModel *> *deviceList;

@property (nonatomic, copy, readonly) NSArray <TuyaSmartGroupModel *> *groupList;

@property (nonatomic, copy, readonly) NSArray <TuyaSmartDeviceModel *> *sharedDeviceList;

@property (nonatomic, copy, readonly) NSArray <TuyaSmartGroupModel *>  *sharedGroupList;

@property (nonatomic, copy, readonly) NSArray <TuyaSmartDeviceOTAModel *> *deviceOtaList;

/// Initializes a site.
/// @param siteId The site ID.
/// @return The initialized instance.
+ (instancetype)siteWithSiteId:(long long)siteId;

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)new NS_UNAVAILABLE;

#pragma mark - Site
/// Adds a site.
/// @param siteName    The name of the site to be added.
/// @param geoName     The name of the city where the site is located.
/// @param rooms       The list of rooms.
/// @param latitude    The latitude of the site.
/// @param longitude   The longitude of the site.
/// @param success     Called when the task is finished.
/// @param failure     Called when the task is interrupted by an error.
+ (void)createSiteWithName:(NSString *)siteName
                   geoName:(NSString *)geoName
                     rooms:(NSArray <NSString *>*)rooms
                  latitude:(double)latitude
                 longitude:(double)longitude
                   success:(TYSuccessLongLong)success
                   failure:(nullable TYFailureError)failure;

/// After a site object is initialized, you must get the details of the site, such as siteModel, roomList, deviceList, and groupList, to configure its data.
/// @param success Called when the task is finished. TuyaResidenceSiteModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)fetchSiteDetailWithSuccess:(void (^)(TuyaResidenceSiteModel *siteModel))success
                           failure:(nullable TYFailureError)failure;

/// Returns a list of sites. To get site details, you must initialize a site and call fetchSiteDetailWithSuccess: failure:.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
+ (void)fetchSiteListWithSuccess:(void(^)(NSArray <TuyaResidenceSiteModel *> *sites))success
                         failure:(nullable TYFailureError)failure;

/// Returns a list of rooms on a specific site.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)fetchSiteRoomCountWithSuccess:(TYSuccessID)success
                              failure:(nullable TYFailureError)failure;

/// Updates site information.
/// @param siteName The name of the site to be updated.
/// @param geoName The name of the city where the site is located.
/// @param latitude The latitude of the site.
/// @param longitude The longitude of the site.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)updateSiteInfoWitSiteName:(NSString *)siteName
                          geoName:(NSString *)geoName
                         latitude:(double)latitude
                        longitude:(double)longitude
                          success:(TYSuccessHandler)success
                          failure:(nullable TYFailureError)failure;

/// Adds a room.
/// @param roomName The name of the room to be added.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)addSiteRoomWithRoomName:(NSString *)roomName
                        success:(TYSuccessHandler)success
                        failure:(nullable TYFailureError)failure;

/// Transfers the ownership of a site.
/// @param memberId The member ID.
/// @param headPicImage The avatar of the owner.
/// @param memberName The name of the member.
/// @param role The role of the member.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)updateSiteMemberInfoWithMemberId:(long long)memberId
                            headPicImage:(UIImage * _Nullable)headPicImage
                              memberName:(NSString *)memberName
                                    role:(TYSiteRoleType)role
                                 success:(TYSuccessHandler)success
                                 failure:(nullable TYFailureError)failure;

/// Removes a site. The owner's member ID of the site is required.
/// @param ownerId The owener ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)removeSiteWithOwnerId:(long long)ownerId
                      success:(TYSuccessHandler)success
                      failure:(nullable TYFailureError)failure;


/// Returns a list of expired records.
/// @param pageSize The maximum number of entries to be returned per page. Valid values: `1` to `100`.
/// @param pageNo The page number. The value starts from `1` and is incremented by `1`.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)fetchExpiredListWithPageSize:(NSInteger)pageSize
                              pageNo:(NSInteger)pageNo
                             success:(void (^)(NSArray<TuyaResidenceExpiredAuthorModel *> *list))success
                             failure:(nullable TYFailureError)failure;

#pragma mark - Site member
/// Returns a list of site members.
/// @note No owner status is returned for the business-side home members.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)fetchSiteResidentListWithSuccess:(void (^)(NSArray<TuyaResidenceSiteMemberModel *> *list))success
                                 failure:(nullable TYFailureError)failure;

/// Removes a site member.
/// @param memberId    The member ID.
/// @param success     Called when the task is finished.
/// @param failure     Called when the task is interrupted by an error.
- (void)removeMemberWithMemberId:(long long)memberId
                         success:(TYSuccessHandler)success
                         failure:(nullable TYFailureError)failure;

/// Returns the details of the current logged-in user for the current site.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)fetchLoginedSiteMemberInfoWithSuccess:(void(^)(TuyaResidenceSiteMemberModel *model))success
                                      failure:(nullable TYFailureError)failure;


@end

NS_ASSUME_NONNULL_END

