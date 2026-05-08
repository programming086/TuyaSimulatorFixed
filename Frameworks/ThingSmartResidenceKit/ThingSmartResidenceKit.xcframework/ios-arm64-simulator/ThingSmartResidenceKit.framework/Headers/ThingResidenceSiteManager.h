//
//  ThingResidenceSiteManager.h
//  ThingSmartResidenceKit
//
//  Copyright (c) 2014-2021 Thing Inc. (https://developer.thing.com/)

#import <Foundation/Foundation.h>
#import <ThingSmartUtil/ThingSmartUtil.h>
#import <ThingSmartResidenceKit/ThingResidenceExpiredAuthorModel.h>
#import <ThingSmartResidenceKit/ThingResidentSiteModelUtils.h>
#import <UIKit/UIKit.h>

@class ThingResidenceSiteModel;
@class ThingResidenceSiteMemberModel;
@class ThingResidenceInvitationResultModel;
@class ThingResidenceInvitationCreateRequestModel;

NS_ASSUME_NONNULL_BEGIN

@interface ThingResidenceSiteManager : NSObject

/// 转让站点（C2C）
/// @param siteId siteId
/// @param headPicImage 用户头像
/// @param memberId memberId
/// @param memberName memberName
/// @param role role
/// @param success success
/// @param failure failure
- (void)updateSiteMemberInfoWithSiteId:(long long)siteId
                              memberId:(long long)memberId
                          headPicImage:(UIImage *)headPicImage
                            memberName:(NSString *)memberName
                                  role:(ThingSiteRoleType)role
                               success:(ThingSuccessHandler)success
                               failure:(ThingFailureError)failure;

#pragma mark - ouyangcheng

///
/// Join more than one home.
/// @param list    A list of homes.
/// @param isAccept Accept
/// @param success     Called when the task is finished.
/// @param failure     Called when the task is interrupted by an error.
- (void)joinFamilyWithHomeIdList:(NSArray <ThingResidenceSiteModel *> *)list
                          action:(BOOL)isAccept
                         success:(ThingSuccessBOOL)success
                         failure:(ThingFailureError)failure;

@end

NS_ASSUME_NONNULL_END


