//
//  ThingSmartHomeMember.h
//  ThingSmartDeviceKit
//
//  Copyright (c) 2014-2024.
//

#import <Foundation/Foundation.h>
#import "ThingSmartHomeMemberModel.h"
#import "ThingSmartHomeMemberRequestModel.h"

@interface ThingSmartHomeMember : NSObject

#pragma mark - public


/// Removes a home member.
///
/// @param memberId    The member ID.
/// @param success     Called when the task is finished.
/// @param failure     Called when the task is interrupted by an error.
- (void)removeHomeMemberWithMemberId:(long long)memberId
                             success:(ThingSuccessHandler)success
                             failure:(ThingFailureError)failure;



/// Updates the home member information.
///
/// @param memberRequestModel The request model. Set the required properties.
/// @param success            Called when the task is finished.
/// @param failure            Called when the task is interrupted by an error.
- (void)updateHomeMemberInfoWithMemberRequestModel:(ThingSmartHomeMemberRequestModel *)memberRequestModel
                                           success:(ThingSuccessHandler)success
                                           failure:(ThingFailureError)failure;

/// 转移家庭拥有者
/// @param memberId 目标用户ID
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)transferHomeWithMemberId:(long long)memberId
                         success:(ThingSuccessHandler)success
                         failure:(ThingFailureError)failure;

/// Returns a list of optional rooms.
/// @param homeID The home ID.
/// @param memberID The member ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
 - (void)getAuthRoomListWithHomeId:(long long)homeID
                         memberID:(long long)memberID
                          success:(ThingSuccessList)success
                          failure:(ThingFailureError)failure;

/// Returns a list of optional scenes or automations.
/// @param homeID The home ID.
/// @param memberID The member ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)getAuthSceneListWithHomeID:(long long)homeID
                          memberID:(long long)memberID
                           success:(ThingSuccessList)success
                           failure:(ThingFailureError)failure;


/// Updates a list of rooms to which custom roles have access.
/// @param homeID The home ID.
/// @param memberID The member ID.
/// @param roomIDs A list of room IDs with permissions.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
 - (void)saveAuthRoomListWithHomeId:(long long)homeID
                          memberID:(long long)memberID
                           roomIDs:(NSArray <NSNumber *> *)roomIDs
                           success:(ThingSuccessID)success
                           failure:(ThingFailureError)failure;


/// Updates a list of scenes to which custom roles have access.
/// @param homeID The home ID.
/// @param memberID The member ID.
/// @param ruleIDs A list of scene IDs with permissions.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)saveAuthSceneListWithHomeId:(long long)homeID
                           memberID:(long long)memberID
                            ruleIDs:(NSArray <NSString *> *)ruleIDs
                            success:(ThingSuccessID)success
                            failure:(ThingFailureError)failure;

@end
