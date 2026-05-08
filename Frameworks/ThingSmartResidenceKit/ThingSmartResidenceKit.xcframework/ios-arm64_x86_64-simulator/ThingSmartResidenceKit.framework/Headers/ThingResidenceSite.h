//
//  ThingResidenceSite.h
//  ThingSmartResidenceKit
//
//  Copyright (c) 2014-2021 Thing Inc. (https://developer.thing.com/)

#import <Foundation/Foundation.h>
#import <ThingSmartDeviceCoreKit/ThingSmartDeviceCoreKit.h>
#import <ThingSmartUtil/ThingSmartUtil.h>
#import <ThingSmartResidenceKit/ThingResidenceExpiredAuthorModel.h>
#import <ThingSmartResidenceKit/ThingResidentSiteModelUtils.h>

@class ThingResidenceSiteModel;
@class ThingResidenceRoomModel;
@class ThingResidenceSiteMemberModel;
@class ThingResidenceSite;

NS_ASSUME_NONNULL_BEGIN

@protocol ThingResidenceSiteDelegate <NSObject>

@optional

/// The delegate of site update information, such as the name and online status.
///
/// @param site The instance.
- (void)siteDidUpdateInfo:(ThingResidenceSite *)site;

/// The delegate of updates on the shared device list.
///
/// @param site The instance.
- (void)siteDidUpdateSharedInfo:(ThingResidenceSite *)site;

/// The delegate of room update information, such as the name.
///
/// @param site The instance.
/// @param room The room model.
- (void)site:(ThingResidenceSite *)site roomInfoUpdate:(ThingResidenceRoomModel *)room;


/// The delegate of updates on the relationship among rooms, groups, and devices.
///
/// @param site The instance.
/// @param room The room model.
- (void)site:(ThingResidenceSite *)site roomRelationUpdate:(ThingResidenceRoomModel *)room;

/// The delegate that is instantiated when a new device is added.
///
/// @param site The instance.
/// @param device The device model.
- (void)site:(ThingResidenceSite *)site didAddDeivice:(ThingSmartDeviceModel *)device;

/// The delegate that is instantiated when an existing device is removed.
///
/// @param site The instance.
/// @param devId The device ID
- (void)site:(ThingResidenceSite *)site didRemoveDeivice:(NSString *)devId;

/// The delegate of device update information, such as the name.
///
/// @param site The instance.
/// @param device The device model.
- (void)site:(ThingResidenceSite *)site deviceInfoUpdate:(ThingSmartDeviceModel *)device;

/// The delegate of device DPs update.
///
/// @param site The instance.
/// @param device The device model.
/// @param dps The DPs.
- (void)site:(ThingResidenceSite *)site device:(ThingSmartDeviceModel *)device dpsUpdate:(NSDictionary *)dps;

/// The delegate of warning information updates.
///
/// @param site The instance.
/// @param device The device model.
/// @param warningInfo The warning information.
- (void)site:(ThingResidenceSite *)site device:(ThingSmartDeviceModel *)device warningInfoUpdate:(NSDictionary *)warningInfo;

/// The delegate of changes in device firmware update status.
///
/// @param site The site instance.
/// @param device The device model.
/// @param upgradeStatusModel The update status model.
- (void)site:(ThingResidenceSite *)site device:(ThingSmartDeviceModel *)device firmwareUpgradeStatusModel:(ThingSmartFirmwareUpgradeStatusModel *)upgradeStatusModel;

/// The delegate that is instantiated when a new group is added.
///
/// @param site The instance.
///  @param group The group model.
- (void)site:(ThingResidenceSite *)site didAddGroup:(ThingSmartGroupModel *)group;

/// The delegate of group DP updates.
///
/// @param site The instance.
/// @param group The group model.
/// @param dps The DPs.
- (void)site:(ThingResidenceSite *)site group:(ThingSmartGroupModel *)group dpsUpdate:(NSDictionary *)dps;

/// The delegate that is instantiated when a group is removed.
///
/// @param site The instance.
/// @param groupId The group ID.
- (void)site:(ThingResidenceSite *)site didRemoveGroup:(NSString *)groupId;

/// The delegate of the group update information, such as the name.
///
/// @param site The instance.
/// @param group The group model.
- (void)site:(ThingResidenceSite *)site groupInfoUpdate:(ThingSmartGroupModel *)group;

#pragma mark - deprecated

/// The delegate of changes in device firmware update status.
///
/// @param site The instance.
/// @param device The device model.
/// @param upgradeStatus The update status.
/// @deprecated This method is deprecated. Use ThingResidenceSiteDelegate::home:device:firmwareUpgradeStatusModel: instead.
- (void)site:(ThingResidenceSite *)site device:(ThingSmartDeviceModel *)device upgradeStatus:(ThingSmartDeviceUpgradeStatus)upgradeStatus __deprecated_msg("This method is deprecated, Use site:device:firmwareUpgradeStatusModel: instead");

@end

@interface ThingResidenceSite : NSObject

@property (nonatomic, strong, readonly) ThingResidenceSiteModel *siteModel;

@property (nonatomic, assign, readonly) long long siteId;

@property (nonatomic, weak) id <ThingResidenceSiteDelegate> delegate;

@property (nonatomic, copy, readonly) NSArray <ThingResidenceRoomModel *> *roomList;

@property (nonatomic, copy, readonly) NSArray <ThingSmartDeviceModel *> *deviceList;

@property (nonatomic, copy, readonly) NSArray <ThingSmartGroupModel *> *groupList;

@property (nonatomic, copy, readonly) NSArray <ThingSmartDeviceModel *> *sharedDeviceList;

@property (nonatomic, copy, readonly) NSArray <ThingSmartGroupModel *>  *sharedGroupList;

@property (nonatomic, copy, readonly) NSArray <ThingSmartDeviceOTAModel *> *deviceOtaList;

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
                   success:(ThingSuccessLongLong)success
                   failure:(nullable ThingFailureError)failure;

/// After a site object is initialized, you must get the details of the site, such as siteModel, roomList, deviceList, and groupList, to configure its data.
/// @param success Called when the task is finished. ThingResidenceSiteModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)fetchSiteDetailWithSuccess:(void (^)(ThingResidenceSiteModel *siteModel))success
                           failure:(nullable ThingFailureError)failure;

/// Returns a list of sites. To get site details, you must initialize a site and call fetchSiteDetailWithSuccess: failure:.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
+ (void)fetchSiteListWithSuccess:(void(^)(NSArray <ThingResidenceSiteModel *> *sites))success
                         failure:(nullable ThingFailureError)failure;

/// Returns a list of rooms on a specific site.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)fetchSiteRoomCountWithSuccess:(ThingSuccessID)success
                              failure:(nullable ThingFailureError)failure;

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
                          success:(ThingSuccessHandler)success
                          failure:(nullable ThingFailureError)failure;

/// Adds a room.
/// @param roomName The name of the room to be added.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)addSiteRoomWithRoomName:(NSString *)roomName
                        success:(ThingSuccessHandler)success
                        failure:(nullable ThingFailureError)failure;

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
                                    role:(ThingSiteRoleType)role
                                 success:(ThingSuccessHandler)success
                                 failure:(nullable ThingFailureError)failure;

/// Removes a site. The owner's member ID of the site is required.
/// @param ownerId The owener ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)removeSiteWithOwnerId:(long long)ownerId
                      success:(ThingSuccessHandler)success
                      failure:(nullable ThingFailureError)failure;


/// Returns a list of expired records.
/// @param pageSize The maximum number of entries to be returned per page. Valid values: `1` to `100`.
/// @param pageNo The page number. The value starts from `1` and is incremented by `1`.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)fetchExpiredListWithPageSize:(NSInteger)pageSize
                              pageNo:(NSInteger)pageNo
                             success:(void (^)(NSArray<ThingResidenceExpiredAuthorModel *> *list))success
                             failure:(nullable ThingFailureError)failure;

#pragma mark - Site member
/// Returns a list of site members.
/// @note No owner status is returned for the business-side home members.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)fetchSiteResidentListWithSuccess:(void (^)(NSArray<ThingResidenceSiteMemberModel *> *list))success
                                 failure:(nullable ThingFailureError)failure;

/// Removes a site member.
/// @param memberId    The member ID.
/// @param success     Called when the task is finished.
/// @param failure     Called when the task is interrupted by an error.
- (void)removeMemberWithMemberId:(long long)memberId
                         success:(ThingSuccessHandler)success
                         failure:(nullable ThingFailureError)failure;

/// Returns the details of the current logged-in user for the current site.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)fetchLoginedSiteMemberInfoWithSuccess:(void(^)(ThingResidenceSiteMemberModel *model))success
                                      failure:(nullable ThingFailureError)failure;


@end

NS_ASSUME_NONNULL_END

