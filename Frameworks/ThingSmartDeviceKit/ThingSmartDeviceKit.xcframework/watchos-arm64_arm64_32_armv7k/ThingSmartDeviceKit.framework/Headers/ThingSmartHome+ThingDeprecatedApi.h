//
//  ThingSmartHome+ThingDeprecatedApi.h
//  ThingSmartDeviceKit
//
//  Copyright (c) 2014-2024.
//

#import "ThingSmartHome.h"

NS_ASSUME_NONNULL_BEGIN

/// 已经废弃不建议使用的API
@interface ThingSmartHome (ThingDeprecatedApi)

/// After the home object is initialized, you must get the details of the home, homeModel, roomList, deviceList, and groupList to set the data.
/// @param success Called when the task is finished. ThingSmartHomeModel is returned.
/// @param failure Called when the task is interrupted by an error.
/// @deprecated This method is deprecated, it will not response panel info, you need get it by calling method `- (void)getPanelInfoWithProductID:productVersion:success:failure:` defined in ThingPanelProtocol, please use -[ThingSmartHome getHomeDataWithSuccess:failure:] instead.
- (void)getHomeDetailWithSuccess:(void (^)(ThingSmartHomeModel *homeModel))success
                         failure:(ThingFailureError)failure __deprecated_msg("This method is deprecated, it will not response panel info, you need get it by calling method `- (void)getPanelInfoWithProductID:productVersion:success:failure:` defined in ThingPanelProtocol, please use -[ThingSmartHome getHomeDataWithSuccess:failure:] instead.");


/// Adds a home member.
///
/// @param name         The member's name.
/// @param headPic      The member's avatar.
/// @param countryCode  The country code.
/// @param account      The user account.
/// @param isAdmin      Specifies whether the member is an administrator.
/// @param success      Called when the task is finished.
/// @param failure      Called when the task is interrupted by an error.
/// @deprecated This method is deprecated. Use ThingSmartHome::addHomeMemberWithName:headPic:countryCode:userAccount:role:success:failure: instead.
- (void)addHomeMemberWithName:(NSString *)name
                      headPic:(UIImage *)headPic
                  countryCode:(NSString *)countryCode
                  userAccount:(NSString *)account
                      isAdmin:(BOOL)isAdmin
                      success:(ThingSuccessDict)success
                      failure:(ThingFailureError)failure __deprecated_msg("This method is deprecated, Use [ThingSmartHome   addHomeMemberWithName:headPic:countryCode:userAccount:role:success:failure:]");

/// Adds a home member.
///
/// @param name         The member's name.
/// @param headPic      The member's avatar.
/// @param countryCode  The country code.
/// @param account      The user account.
/// @param role         The type of the home role.
/// @param success      Called when the task is finished.
/// @param failure      Called when the task is interrupted by an error.
/// @deprecated This method is deprecated. Use ThingSmartHome::addHomeMemberWithAddMemeberRequestModel:success:failure: instead.
- (void)addHomeMemberWithName:(NSString *)name
                      headPic:(UIImage *)headPic
                  countryCode:(NSString *)countryCode
                  userAccount:(NSString *)account
                         role:(ThingHomeRoleType)role
                      success:(ThingSuccessDict)success
                      failure:(ThingFailureError)failure __deprecated_msg("This method is deprecated, Use [ThingSmartHome addHomeMemberWithAddMemeberRequestModel:success:failure:]");

@end

NS_ASSUME_NONNULL_END
