//
//  TuyaResidenceAccess.h
//  TuyaSmartResidenceSDK
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com/)

#import <Foundation/Foundation.h>
#import <TuyaSmartBaseKit/TuyaSmartBaseKit.h>
#import "TuyaResidencePasswordAccessModel.h"
#import "TuyaResidenceAccessRecordModel.h"
#import "TuyaResidenceAppAccessModel.h"
#import "TuyaResidenceAddPasswordAccessModel.h"
#import "TuyaResidenceAddAppAccessModel.h"

@class TuyaSmartDeviceModel;


NS_ASSUME_NONNULL_BEGIN

@interface TuyaResidenceAccess : NSObject

/// Returns a list of access control devices.
/// @param siteId  The site ID.
/// @param success Called when the task is finished. The list of TuyaSmartDeviceModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)fetchDeviceListWithSiteId:(long long)siteId
                          success:(void(^)(NSArray<TuyaSmartDeviceModel *> *devices))success
                          failure:(TYFailureError)failure;

/// Checks whether a user allowed for access is registered.
/// @param userName The email address or mobile phone number as the username.
/// @param success Called when the task is finished. Valid values returned: `Yes`: The user allowed for access is registered.; `No`: The user allowed for access is unregistered.
/// @param failure Called when the task is interrupted by an error.
- (void)checkAccessAccountWithUserName:(NSString *)userName
                               success:(TYSuccessBOOL)success
                               failure:(TYFailureError)failure;

/// Returns the membership type of an account.
/// @param siteId The site ID.
/// @param userName The email address or mobile phone number as the username.
/// @param success Called when the task is finished. Valid values returned: `0`: user allowed for access; `1`: site member; `-1`: unregistered user
/// @param failure Called when the task is interrupted by an error.
- (void)checkAccessAuthorizationWithSiteId:(long long)siteId
                                  userName:(NSString *)userName
                                   success:(void(^)(TuyaResidenceAccessMemberType result))success
                                   failure:(TYFailureError)failure;

/// Adds app users allowed for access.
/// @param appAccessModel The TuyaResidenceAddAppAccessModel object.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)addAppAccessWithModel:(TuyaResidenceAddAppAccessModel *)appAccessModel
                      success:(TYSuccessBOOL)success
                      failure:(TYFailureError)failure;

/// Returns a list of app users allowed for access.
/// @param siteId The site ID.
/// @param effective Indicates the authorization status. Valid values: `YES`: The authorization is valid. `NO`: The authorization has expired.
/// @param pageNo The page number.
/// @param pageSize The maximum number of entries to be returned per page. Valid values: `10` to `100`.
/// @param success Called when the task is finished. The list of TuyaResidenceAppAccessModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)fetchAppAccessListWithSiteId:(long long)siteId
                           effective:(BOOL)effective
                              pageNo:(NSInteger)pageNo
                            pageSize:(NSInteger)pageSize
                             success:(void(^)(NSArray<TuyaResidenceAppAccessModel *> *userList))success
                             failure:(TYFailureError)failure;

/// Returns the details of an app user allowed for access.
/// @param siteId The site ID.
/// @param accessUserId The user ID.
/// @param success Called when the task is finished. The TuyaResidenceAppAccessModel object is returned.
/// @param failure  Called when the task is interrupted by an error.
- (void)fetchAppAccessUserDetailWithSiteId:(long long)siteId
                              accessUserId:(NSString *)accessUserId
                                   success:(void(^)(TuyaResidenceAppAccessDetailModel *userDetail))success
                                   failure:(TYFailureError)failure;

/// Returns the access records of an app user.
/// @param siteId The site ID.
/// @param accessUserId The user ID.
/// @param pageNo The page number.
/// @param pageSize The maximum number of entries to be returned per page. Valid values: `10` to `100`.
/// @param success Called when the task is finished. The list of TuyaResidenceAccessRecordModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)fetchAppAccessPassRecordWithSiteId:(long long)siteId
                              accessUserId:(NSString *)accessUserId
                                    pageNo:(NSInteger)pageNo
                                  pageSize:(NSInteger)pageSize
                                   success:(void(^)(NSArray<TuyaResidenceAccessRecordModel *> *accessUserRecordList))success
                                   failure:(TYFailureError)failure;

/// Returns the total number of app users allowed for access.
/// @param siteId The site ID.
/// @param effective  Indicates whether the authorization is valid. Valid values: `Yes`: The authorization is valid. `No`: The authorization has expired.
/// @param success Called when the task is finished. The total number of app users allowed for access is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)fetchAppAccessTotalWithSiteId:(long long)siteId
                            effective:(BOOL)effective
                              success:(void(^)(NSInteger total))success
                              failure:(TYFailureError)failure;

/// Adds one or more access control devices to an app user.
/// @param siteId The site ID.
/// @param accessUserId The user ID.
/// @param deviceIdList The list of device IDs.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)addAppAccessDeviceWithSiteId:(long long)siteId
                        accessUserId:(NSString *)accessUserId
                        deviceIdList:(NSArray<NSString *> *)deviceIdList
                             success:(TYSuccessHandler)success
                             failure:(TYFailureError)failure;

/// Removes an access control device from an app user.
/// @param siteId The site ID.
/// @param accessUserId The user ID.
/// @param deviceId The device ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)removeAppAccessDeviceWithSiteId:(long long)siteId
                           accessUserId:(NSString *)accessUserId
                               deviceId:(NSString *)deviceId
                                success:(TYSuccessHandler)success
                                failure:(TYFailureError)failure;

/// Removes an app user allowed for access.
/// @param siteId The site ID.
/// @param accessUserId The user ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)removeAppAccessWithSiteId:(long long)siteId
                     accessUserId:(NSString *)accessUserId
                          success:(TYSuccessHandler)success
                          failure:(TYFailureError)failure;

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
                         userType:(TuyaResidenceAccessUserType)userType
                        startTime:(long)startTime
                          endTime:(long)endTime
                          success:(TYSuccessHandler)success
                          failure:(TYFailureError)failure;

/// Adds a user allowed for access with a password.
/// @param requstModel The model of an access request.
/// @param success Called when the task is finished. The authorized group ID is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)addPasswordAccessWithModel:(TuyaResidenceAddPasswordAccessModel *)requstModel
                           success:(TYSuccessHandler)success
                           failure:(TYFailureError)failure;

/// Returns a list of users allowed for access with a password.
/// @param siteId The site ID.
/// @param effective Indicates whether the password is valid. Valid values: `Yes`: The password is valid. `No`: The password has expired.
/// @param pageNo The page number.
/// @param pageSize The maximum number of entries to be returned per page.
/// @param success Called when the task is finished. The list of TuyaResidencePasswordAccessModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)fetchPasswordAccessListWithSiteId:(long long)siteId
                                effective:(BOOL)effective
                                   pageNo:(NSInteger)pageNo
                                 pageSize:(NSInteger)pageSize
                                  success:(void (^)(NSArray<TuyaResidencePasswordAccessModel *> *accessPasswordList))success
                                  failure:(TYFailureError)failure;

/// Returns the details of users allowed for access.
/// @param siteId The site ID.
/// @param authGroupId The ID of the authorized group.
/// @param success Called when the task is finished. The TuyaResidencePasswordAccessModel object is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)fetchPasswordAccessUserDetailWithSiteId:(long long)siteId
                                    authGroupId:(NSString *)authGroupId
                                        success:(void (^)(TuyaResidencePasswordAccessModel *accessPasswordModel))success
                                        failure:(TYFailureError)failure;

/// Returns the access records of users.
/// @param siteId The site ID.
/// @param authGroupId The ID of the authorized group.
/// @param pageNo The page number.
/// @param pageSize The maximum number of entries to be returned per page.
/// @param success Called when the task is finished. The list of TuyaResidenceAccessRecordModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)fetchPasswordAccessPassRecordWithSiteId:(long long)siteId
                                    authGroupId:(NSString *)authGroupId
                                         pageNo:(NSInteger)pageNo
                                       pageSize:(NSInteger)pageSize
                                        success:(void(^)(NSArray<TuyaResidenceAccessRecordModel *> *accessUserRecordList))success
                                        failure:(TYFailureError)failure;

/// Returns the total number of users allowed for access with a password.
/// @param siteId The site ID.
/// @param effective Indicates whether the password is valid. Valid values: `Yes`: The password is valid. `No`: The password has expired.
/// @param success Called when the task is finished. The total number of password access entries is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)fetchPasswordAccessTotalWithSiteId:(long long)siteId
                                 effective:(BOOL)effective
                                   success:(void(^)(NSInteger total))success
                                   failure:(TYFailureError)failure;

/// Removes users allowed for access with a password. The target device must be online. You can call the method [TuyaSmartDevice deviceWithDeviceId:deviceId] to check the device details including its status.
/// @param siteId The site ID.
/// @param authGroupId The ID of the authorized group.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)removePasswordAccessWithSiteId:(long long)siteId
                           authGroupId:(NSString *)authGroupId
                               success:(TYSuccessHandler)success
                               failure:(TYFailureError)failure;

/// Adds one or more devices to users allowed for access with a password. The target devices must be online. You can call the method [TuyaSmartDevice deviceWithDeviceId:deviceId] to check the device details including their status.
/// @param siteId The site ID.
/// @param authGroupId The ID of the authorized group.
/// @param deviceIdList The list of device IDs.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)addPasswordAccessDeviceWithSiteId:(long long)siteId
                              authGroupId:(NSString *)authGroupId
                             deviceIdList:(NSArray<NSString *> *)deviceIdList
                                  success:(TYSuccessHandler)success
                                  failure:(TYFailureError)failure;

/// Updates password information. The target devices must be online. You can call the method [TuyaSmartDevice deviceWithDeviceId:deviceId] to check device details including their status.
/// @param siteId The site ID.
/// @param authGroupId The ID of the authorized group.
/// @param doorPassword The TuyaResidenceAccessDoorPasswordModel object.
/// @param deviceIdList The list of device IDs.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)updatePasswordAccessValidityWithSiteId:(long long)siteId
                                   authGroupId:(NSString *)authGroupId
                                  doorPassword:(TuyaResidenceBasePasswordInfoModel *)doorPassword
                                  deviceIdList:(NSArray<NSString *> *)deviceIdList
                                       success:(TYSuccessHandler)success
                                       failure:(TYFailureError)failure;

/// Updates the nickname of a user allowed for access with a password.
/// @param siteId The site ID.
/// @param authGroupId The ID of the authorized group.
/// @param nickName The nickname of the user.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)updatePasswordAccessNicknameWithSiteId:(long long)siteId
                                   authGroupId:(NSString *)authGroupId
                                      nickName:(NSString *)nickName
                                       success:(TYSuccessHandler)success
                                       failure:(TYFailureError)failure;

/// Removes a device from a user allowed for access with a password. The target device must be online. You can call the method [TuyaSmartDevice deviceWithDeviceId:deviceId] to check the device details including its status.
/// @param siteId The site ID.
/// @param authGroupId The ID of the authorized group.
/// @param deviceId The device ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)removePasswordAccessDeviceWithSiteId:(long long)siteId
                                 authGroupId:(NSString *)authGroupId
                                    deviceId:(NSString *)deviceId
                                     success:(TYSuccessHandler)success
                                     failure:(TYFailureError)failure;

@end

NS_ASSUME_NONNULL_END
