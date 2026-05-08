//
//  ThingResidenceAccess.h
//  ThingSmartResidenceSDK
//
//  Copyright (c) 2014-2021 Thing Inc. (https://developer.thing.com/)

#import <Foundation/Foundation.h>
#import <ThingSmartBaseKit/ThingSmartBaseKit.h>
#import "ThingResidencePasswordAccessModel.h"
#import "ThingResidenceAccessRecordModel.h"
#import "ThingResidenceAppAccessModel.h"
#import "ThingResidenceAddPasswordAccessModel.h"
#import "ThingResidenceAddAppAccessModel.h"

@class ThingSmartDeviceModel;


NS_ASSUME_NONNULL_BEGIN

@interface ThingResidenceAccess : NSObject

/// Returns a list of access control devices.
/// @param siteId  The site ID.
/// @param success Called when the task is finished. The list of ThingSmartDeviceModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)fetchDeviceListWithSiteId:(long long)siteId
                          success:(void(^)(NSArray<ThingSmartDeviceModel *> *devices))success
                          failure:(ThingFailureError)failure;

/// Checks whether a user allowed for access is registered.
/// @param userName The email address or mobile phone number as the username.
/// @param success Called when the task is finished. Valid values returned: `Yes`: The user allowed for access is registered.; `No`: The user allowed for access is unregistered.
/// @param failure Called when the task is interrupted by an error.
- (void)checkAccessAccountWithUserName:(NSString *)userName
                               success:(ThingSuccessBOOL)success
                               failure:(ThingFailureError)failure;

/// Returns the membership type of an account.
/// @param siteId The site ID.
/// @param userName The email address or mobile phone number as the username.
/// @param success Called when the task is finished. Valid values returned: `0`: user allowed for access; `1`: site member; `-1`: unregistered user
/// @param failure Called when the task is interrupted by an error.
- (void)checkAccessAuthorizationWithSiteId:(long long)siteId
                                  userName:(NSString *)userName
                                   success:(void(^)(ThingResidenceAccessMemberType result))success
                                   failure:(ThingFailureError)failure;

/// Adds app users allowed for access.
/// @param appAccessModel The ThingResidenceAddAppAccessModel object.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)addAppAccessWithModel:(ThingResidenceAddAppAccessModel *)appAccessModel
                      success:(ThingSuccessBOOL)success
                      failure:(ThingFailureError)failure;

/// Returns a list of app users allowed for access.
/// @param siteId The site ID.
/// @param effective Indicates the authorization status. Valid values: `YES`: The authorization is valid. `NO`: The authorization has expired.
/// @param pageNo The page number.
/// @param pageSize The maximum number of entries to be returned per page. Valid values: `10` to `100`.
/// @param success Called when the task is finished. The list of ThingResidenceAppAccessModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)fetchAppAccessListWithSiteId:(long long)siteId
                           effective:(BOOL)effective
                              pageNo:(NSInteger)pageNo
                            pageSize:(NSInteger)pageSize
                             success:(void(^)(NSArray<ThingResidenceAppAccessModel *> *userList))success
                             failure:(ThingFailureError)failure;

/// Returns the details of an app user allowed for access.
/// @param siteId The site ID.
/// @param accessUserId The user ID.
/// @param success Called when the task is finished. The ThingResidenceAppAccessModel object is returned.
/// @param failure  Called when the task is interrupted by an error.
- (void)fetchAppAccessUserDetailWithSiteId:(long long)siteId
                              accessUserId:(NSString *)accessUserId
                                   success:(void(^)(ThingResidenceAppAccessDetailModel *userDetail))success
                                   failure:(ThingFailureError)failure;

/// Returns the access records of an app user.
/// @param siteId The site ID.
/// @param accessUserId The user ID.
/// @param pageNo The page number.
/// @param pageSize The maximum number of entries to be returned per page. Valid values: `10` to `100`.
/// @param success Called when the task is finished. The list of ThingResidenceAccessRecordModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)fetchAppAccessPassRecordWithSiteId:(long long)siteId
                              accessUserId:(NSString *)accessUserId
                                    pageNo:(NSInteger)pageNo
                                  pageSize:(NSInteger)pageSize
                                   success:(void(^)(NSArray<ThingResidenceAccessRecordModel *> *accessUserRecordList))success
                                   failure:(ThingFailureError)failure;

/// Returns the total number of app users allowed for access.
/// @param siteId The site ID.
/// @param effective  Indicates whether the authorization is valid. Valid values: `Yes`: The authorization is valid. `No`: The authorization has expired.
/// @param success Called when the task is finished. The total number of app users allowed for access is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)fetchAppAccessTotalWithSiteId:(long long)siteId
                            effective:(BOOL)effective
                              success:(void(^)(NSInteger total))success
                              failure:(ThingFailureError)failure;

/// Adds one or more access control devices to an app user.
/// @param siteId The site ID.
/// @param accessUserId The user ID.
/// @param deviceIdList The list of device IDs.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)addAppAccessDeviceWithSiteId:(long long)siteId
                        accessUserId:(NSString *)accessUserId
                        deviceIdList:(NSArray<NSString *> *)deviceIdList
                             success:(ThingSuccessHandler)success
                             failure:(ThingFailureError)failure;

/// Removes an access control device from an app user.
/// @param siteId The site ID.
/// @param accessUserId The user ID.
/// @param deviceId The device ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)removeAppAccessDeviceWithSiteId:(long long)siteId
                           accessUserId:(NSString *)accessUserId
                               deviceId:(NSString *)deviceId
                                success:(ThingSuccessHandler)success
                                failure:(ThingFailureError)failure;

/// Removes an app user allowed for access.
/// @param siteId The site ID.
/// @param accessUserId The user ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)removeAppAccessWithSiteId:(long long)siteId
                     accessUserId:(NSString *)accessUserId
                          success:(ThingSuccessHandler)success
                          failure:(ThingFailureError)failure;

/// Modifies the details of an app user allowed for access.
/// @param siteId The site ID.
/// @param accessUserId The user ID.
/// @param nickName The nickname of the user.
/// @param userType The type of user.
/// @param startTime The start time.
/// @param endTime  The end time.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)updateAppAccessWithSiteId:(long long)siteId
                     accessUserId:(NSString *)accessUserId
                         nickName:(NSString *)nickName
                         userType:(ThingResidenceAccessUserType)userType
                        startTime:(long)startTime
                          endTime:(long)endTime
                          success:(ThingSuccessHandler)success
                          failure:(ThingFailureError)failure;

/// Adds a user allowed for access with a password.
/// @param requstModel The model of an access request.
/// @param success Called when the task is finished. The authorized group ID is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)addPasswordAccessWithModel:(ThingResidenceAddPasswordAccessModel *)requstModel
                           success:(ThingSuccessHandler)success
                           failure:(ThingFailureError)failure;

/// Returns a list of users allowed for access with a password.
/// @param siteId The site ID.
/// @param effective Indicates whether the password is valid. Valid values: `Yes`: The password is valid. `No`: The password has expired.
/// @param pageNo The page number.
/// @param pageSize The maximum number of entries to be returned per page.
/// @param success Called when the task is finished. The list of ThingResidencePasswordAccessModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)fetchPasswordAccessListWithSiteId:(long long)siteId
                                effective:(BOOL)effective
                                   pageNo:(NSInteger)pageNo
                                 pageSize:(NSInteger)pageSize
                                  success:(void (^)(NSArray<ThingResidencePasswordAccessModel *> *accessPasswordList))success
                                  failure:(ThingFailureError)failure;

/// Returns the details of users allowed for access.
/// @param siteId The site ID.
/// @param authGroupId The ID of the authorized group.
/// @param success Called when the task is finished. The ThingResidencePasswordAccessModel object is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)fetchPasswordAccessUserDetailWithSiteId:(long long)siteId
                                    authGroupId:(NSString *)authGroupId
                                        success:(void (^)(ThingResidencePasswordAccessModel *accessPasswordModel))success
                                        failure:(ThingFailureError)failure;

/// Returns the access records of users.
/// @param siteId The site ID.
/// @param authGroupId The ID of the authorized group.
/// @param pageNo The page number.
/// @param pageSize The maximum number of entries to be returned per page.
/// @param success Called when the task is finished. The list of ThingResidenceAccessRecordModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)fetchPasswordAccessPassRecordWithSiteId:(long long)siteId
                                    authGroupId:(NSString *)authGroupId
                                         pageNo:(NSInteger)pageNo
                                       pageSize:(NSInteger)pageSize
                                        success:(void(^)(NSArray<ThingResidenceAccessRecordModel *> *accessUserRecordList))success
                                        failure:(ThingFailureError)failure;

/// Returns the total number of users allowed for access with a password.
/// @param siteId The site ID.
/// @param effective Indicates whether the password is valid. Valid values: `Yes`: The password is valid. `No`: The password has expired.
/// @param success Called when the task is finished. The total number of password access entries is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)fetchPasswordAccessTotalWithSiteId:(long long)siteId
                                 effective:(BOOL)effective
                                   success:(void(^)(NSInteger total))success
                                   failure:(ThingFailureError)failure;

/// Removes users allowed for access with a password. The target device must be online. You can call the method [ThingSmartDevice deviceWithDeviceId:deviceId] to check the device details including its status.
/// @param siteId The site ID.
/// @param authGroupId The ID of the authorized group.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)removePasswordAccessWithSiteId:(long long)siteId
                           authGroupId:(NSString *)authGroupId
                               success:(ThingSuccessHandler)success
                               failure:(ThingFailureError)failure;

/// Adds one or more devices to users allowed for access with a password. The target devices must be online. You can call the method [ThingSmartDevice deviceWithDeviceId:deviceId] to check the device details including their status.
/// @param siteId The site ID.
/// @param authGroupId The ID of the authorized group.
/// @param deviceIdList The list of device IDs.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)addPasswordAccessDeviceWithSiteId:(long long)siteId
                              authGroupId:(NSString *)authGroupId
                             deviceIdList:(NSArray<NSString *> *)deviceIdList
                                  success:(ThingSuccessHandler)success
                                  failure:(ThingFailureError)failure;

/// Updates password information. The target devices must be online. You can call the method [ThingSmartDevice deviceWithDeviceId:deviceId] to check device details including their status.
/// @param siteId The site ID.
/// @param authGroupId The ID of the authorized group.
/// @param doorPassword The ThingResidenceAccessDoorPasswordModel object.
/// @param deviceIdList The list of device IDs.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)updatePasswordAccessValidityWithSiteId:(long long)siteId
                                   authGroupId:(NSString *)authGroupId
                                  doorPassword:(ThingResidenceBasePasswordInfoModel *)doorPassword
                                  deviceIdList:(NSArray<NSString *> *)deviceIdList
                                       success:(ThingSuccessHandler)success
                                       failure:(ThingFailureError)failure;

/// Updates the nickname of a user allowed for access with a password.
/// @param siteId The site ID.
/// @param authGroupId The ID of the authorized group.
/// @param nickName The nickname of the user.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)updatePasswordAccessNicknameWithSiteId:(long long)siteId
                                   authGroupId:(NSString *)authGroupId
                                      nickName:(NSString *)nickName
                                       success:(ThingSuccessHandler)success
                                       failure:(ThingFailureError)failure;

/// Removes a device from a user allowed for access with a password. The target device must be online. You can call the method [ThingSmartDevice deviceWithDeviceId:deviceId] to check the device details including its status.
/// @param siteId The site ID.
/// @param authGroupId The ID of the authorized group.
/// @param deviceId The device ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)removePasswordAccessDeviceWithSiteId:(long long)siteId
                                 authGroupId:(NSString *)authGroupId
                                    deviceId:(NSString *)deviceId
                                     success:(ThingSuccessHandler)success
                                     failure:(ThingFailureError)failure;

@end

NS_ASSUME_NONNULL_END
