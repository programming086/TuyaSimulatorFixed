//
//  ThingSmartHomeInvitation.h
//  ThingSmartDeviceKit
//
//  Copyright (c) 2014-2024.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartHomeInvitation : NSObject

/// Invites new members by invitation code.
/// @param createRequestModel The request model.
/// @param success Called when the task is finished. ThingSmartHomeInvitationResultModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)createInvitationWithCreateRequestModel:(ThingSmartHomeInvitationCreateRequestModel *)createRequestModel
                                       success:(void(^)(ThingSmartHomeInvitationResultModel *invitationResultModel))success
                                       failure:(ThingFailureError)failure;

/// Cancels an invitation.
/// @param invitationID The invitation ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)cancelInvitationWithInvitationID:(NSNumber *)invitationID
                                 success:(ThingSuccessBOOL)success
                                 failure:(ThingFailureError)failure;

/// Reinvites members.
/// @param reinviteRequestModel The reinvitation request model.
/// @param success Called when the task is finished. ThingSmartHomeInvitationResultModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)reinviteInvitationWithReinviteRquestModel:(ThingSmartHomeInvitationReinviteRequestModel *)reinviteRequestModel
                                          success:(void(^)(ThingSmartHomeInvitationResultModel *invitationResultModel))success
                                          failure:(ThingFailureError)failure;

/// Returns a list of invitation records.
/// @param homeID The home ID.
/// @param success Called when the task is finished. A list of ThingSmartHomeInvitationRecordModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)fetchInvitationRecordListWithHomeID:(long long)homeID
                                    success:(void(^)(NSArray<ThingSmartHomeInvitationRecordModel *> *invitationRecordList))success
                                    failure:(ThingFailureError)failure;

/// Updates invitation information.
/// @param invitationInfoRequestModel The invitation information request model.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)updateInvitationInfoWithInvitationInfoRequestModel:(ThingSmartHomeInvitationInfoRequestModel *)invitationInfoRequestModel
                                                   success:(ThingSuccessBOOL)success
                                                   failure:(ThingFailureError)failure;


/// Returns home information of the invitee.
/// @param invitationCode The invitation code.
/// @param success Called when the task is finished. ThingSmartHomeModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)fetchInvitationHomeInfoWithInvitationCode:(NSString *)invitationCode
                                          success:(void(^)(ThingSmartHomeModel *homeModel))success
                                          failure:(ThingFailureError)failure;

/// Joins the home.
/// @param invitationCode The invitation code.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)joinHomeWithInvitationCode:(NSString *)invitationCode
                           success:(ThingSuccessBOOL)success
                           failure:(ThingFailureError)failure;
@end

NS_ASSUME_NONNULL_END
