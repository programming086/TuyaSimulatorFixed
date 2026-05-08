//
//  ThingSmartHomeDeviceShare+ThingDeprecatedApi.h
//  ThingSmartDeviceKit
//
//  Copyright (c) 2014-2024.
//

#import <ThingSmartShareKit/ThingSmartShareKit.h>
#import "ThingSmartHomeDeviceShare.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartHomeDeviceShare (ThingDeprecatedApi)

/// Adds a sharing task.
/// @param homeId The home ID.
/// @param countryCode The country code.
/// @param userAccount The user account.
/// @param devIds A list of device IDs.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
/// @deprecated This method is deprecated. Use ThingSmartHomeDeviceShare::addDeviceShareWithRequestModel:success:failure: instead.
- (void)addShareWithHomeId:(long long)homeId
               countryCode:(NSString *)countryCode
               userAccount:(NSString *)userAccount
                    devIds:(NSArray <NSString *> *)devIds
                   success:(void(^)(ThingSmartShareMemberModel *model))success
                   failure:(ThingFailureError)failure __deprecated_msg("This method is deprecated, Use [ThingSmartHomeDeviceShare   addDeviceShareWithRequestModel:success:failure:]");


/// Adds a task to share a single device.
/// @param homeId The home ID.
/// @param countryCode The country code.
/// @param userAccount The user account.
/// @param devId The device ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
/// @deprecated This method is deprecated. Use ThingSmartHomeDeviceShare::addDeviceShareWithRequestModel:success:failure: instead.
- (void)addDeviceShareWithHomeId:(long long)homeId
                     countryCode:(NSString *)countryCode
                     userAccount:(NSString *)userAccount
                           devId:(NSString *)devId
                         success:(void(^)(ThingSmartShareMemberModel *model))success
                         failure:(ThingFailureError)failure __deprecated_msg("This method is deprecated, Use [ThingSmartHomeDeviceShare   addDeviceShareWithRequestModel:success:failure:]");


/// Returns sharing information of the group.
/// @param groupId The group ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)getShareGroupFromInfoWithGroupId:(NSString *)groupId
                                 success:(ThingSuccessID)success
                                 failure:(ThingFailureError)failure __deprecated_msg("This method is deprecated, Use [ThingSmartGroup getShareGroupFromInfoWithSuccess:failure:]");

/// Removes sharing groups.
/// @param groupId The group ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)removeShareGroupWithGroupId:(NSString *)groupId
                            success:(ThingSuccessID)success
                            failure:(ThingFailureError)failure __deprecated_msg("This method is deprecated, Use [ThingSmartGroup removeShareGroupWithSuccess:failure:] Instead");

/// Returns the users who initiate device sharing.
/// @param devId The device ID.
/// @param success Called when the task is finished. ThingSmartReceivedShareUserModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getShareInfoWithDevId:(NSString *)devId
                      success:(void(^)(ThingSmartReceivedShareUserModel *model))success
                      failure:(ThingFailureError)failure __deprecated_msg("This method is deprecated, Use [ThingSmartDevice - (void)getShareInfoWitSuccess:failure:]");

/// Removes the device that is shared and received.
/// @param devId   The device ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)removeReceiveDeviceShareWithDevId:(NSString *)devId
                                  success:(ThingSuccessHandler)success
                                  failure:(ThingFailureError)failure __deprecated_msg("This method is deprecated, Use [ThingSmartDevice removeReceiveDeviceShareWithSuccess:failure:]");

/// Returns all users who initiate device sharing for a home.
/// @param homeId The home ID.
/// @param success Called when the task is finished. A list of ThingSmartShareMemberModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getShareMemberListWithHomeId:(long long)homeId
                             success:(void(^)(NSArray<ThingSmartShareMemberModel *> *list))success
                             failure:(ThingFailureError)failure __deprecated_msg("This method is deprecated, Use [ThingSmartHomeDeviceShare getShareMemberListWithSpaceId:success:failure:]");

/// Shares groups to other users.
/// @param homeId The home ID.
/// @param countryCode The country code.
/// @param userAccount The user account.
/// @param groupId The group ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)addGroupShareToMemberWithHomeId:(long long)homeId
                             countyCode:(NSString *)countryCode
                            userAccount:(NSString *)userAccount
                                groupId:(NSString *)groupId
                                success:(ThingSuccessID)success
                                failure:(ThingFailureError)failure __deprecated_msg("This method is deprecated, Use [ThingSmartHomeDeviceShare addGroupShareToMemberWithSpaceId:countyCode:userAccount:groupId:success:failure:]");

@end

NS_ASSUME_NONNULL_END
