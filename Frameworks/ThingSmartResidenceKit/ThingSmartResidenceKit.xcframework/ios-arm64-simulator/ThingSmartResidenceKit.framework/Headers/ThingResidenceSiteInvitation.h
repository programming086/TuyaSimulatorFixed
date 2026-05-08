//
//  ThingResidenceSiteInvitation.h
//  ThingSmartResidenceKit
//
//  Copyright (c) 2014-2021 Thing Inc. (https://developer.thing.com/)

#import <Foundation/Foundation.h>
#import <ThingSmartBaseKit/ThingSmartBaseKit.h>
#import "ThingResidenceInvitationResultModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingResidenceSiteInvitation : NSObject

/// Invites a member by using an invitation code.
/// @param createRequestModel The request model.
/// @param success Called when the task is finished. ThingSmartHomeInvitationResultModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)invitationMemberWithCreateRequestModel:(ThingResidenceInvitationCreateRequestModel *)createRequestModel
                                       success:(void(^)(ThingResidenceInvitationResultModel *invitationResultModel))success
                                       failure:(ThingFailureError)failure;

/// Joins a site.
/// @param invitationCode The invitation code.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)joinSiteWithInvitationCode:(NSString *)invitationCode
                           success:(ThingSuccessBOOL)success
                           failure:(ThingFailureError)failure;

/// Invites a member.
/// @param siteId The site ID.
/// @param nickName The nickname of the member to be invited.
/// @param userName The username of the member. It can be a mobile phone number or email address. For a mobile phone number, the value must be prefixed with the country code in the format of `country code-phone number`. Example: `00-1234567`.
/// @param isAdmin Specifies whether the member is an administrator. Valid values:`0`: normal user;`1`: administrator.This parameter is invalid for business-side rooms.
/// @param isAutoAccept Specifies whether to enable automatic acceptance. This parameter is valid only for business-side rooms.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)addMemberWithSiteId:(long long)siteId
                   nickName:(NSString *)nickName
                   userName:(NSString *)userName
                    isAdmin:(BOOL)isAdmin
               isAutoAccept:(BOOL)isAutoAccept
                    success:(ThingSuccessHandler)success
                    failure:(ThingFailureError)failure;


/// Cancels an invitation.
/// @param invitationID The invitation ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)cancelInvitationWithInvitationID:(NSNumber *)invitationID
                                 success:(ThingSuccessBOOL)success
                                 failure:(ThingFailureError)failure;

/// Returns a list of invitation records.
/// @param siteID The site ID.
/// @param success Called when the task is finished. The list of ThingResidenceInvitationRecordModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)fetchInvitationRecordListWithSiteID:(long long)siteID
                                    success:(void(^)(NSArray<ThingResidenceInvitationRecordModel *> *invitationRecordList))success
                                    failure:(ThingFailureError)failure;

@end

NS_ASSUME_NONNULL_END
