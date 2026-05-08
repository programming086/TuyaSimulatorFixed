
#import "ThingSmartShareKitModel.h"

NS_ASSUME_NONNULL_BEGIN

/// Shares devices based on device types.
@interface ThingSmartHomeDeviceShare : NSObject

/// Adds a device to be shared.
/// @param requestModel Adds a device model to be shared.
/// @param success Called when the task is finished. ThingSmartShareMemberModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)addDeviceShareWithRequestModel:(ThingSmartDeviceShareRequestModel *)requestModel
                               success:(void(^)(ThingSmartShareMemberModel *model))success
                               failure:(ThingFailureError)failure;


/// Adds extra devices to be shared. The existing shared devices are not overwritten.
/// @param memberId The member ID.
/// @param devIds A list of device IDs.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)addShareWithMemberId:(NSInteger)memberId
                      devIds:(NSArray <NSString *> *)devIds
                     success:(ThingSuccessHandler)success
                     failure:(ThingFailureError)failure;


/// Returns all users who initiate device sharing for a home.
/// @param spaceId The home ID.
/// @param success Called when the task is finished. A list of ThingSmartShareMemberModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getShareMemberListWithSpaceId:(long long)spaceId
                             success:(void(^)(NSArray<ThingSmartShareMemberModel *> *list))success
                             failure:(ThingFailureError)failure;


/// Returns all users who receive shared devices.
/// @param success Called when the task is finished. A list of ThingSmartShareMemberModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getReceiveMemberListWithSuccess:(void(^)(NSArray<ThingSmartShareMemberModel *> *list))success
                                failure:(ThingFailureError)failure;


/// Returns the shared device data of a single user who initiates sharing.
/// @param memberId The member ID.
/// @param success Called when the task is finished. ThingSmartShareMemberDetailModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getShareMemberDetailWithMemberId:(NSInteger)memberId
                                 success:(void(^)(ThingSmartShareMemberDetailModel *model))success
                                 failure:(ThingFailureError)failure;


/// Returns the shared device data of a single user who receives shared devices.
/// @param memberId The member ID.
/// @param success Called when the task is finished. ThingSmartShareMemberDetailModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getReceiveMemberDetailWithMemberId:(NSInteger)memberId
                                   success:(void(^)(ThingSmartReceiveMemberDetailModel *model))success
                                   failure:(ThingFailureError)failure;



/// Removes users who initiate device sharing.
/// @param memberId The member ID.
/// @param success  Called when the task is finished.
/// @param failure  Called when the task is interrupted by an error.
- (void)removeShareMemberWithMemberId:(NSInteger)memberId
                              success:(ThingSuccessHandler)success
                              failure:(ThingFailureError)failure;


/// Removes users who receive shared devices.
/// @param memberId The member ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)removeReceiveShareMemberWithMemberId:(NSInteger)memberId
                                     success:(ThingSuccessHandler)success
                                     failure:(ThingFailureError)failure;


/// Changes the nickname of the user who initiates device sharing.
/// @param memberId The member ID.
/// @param name The nickname.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)renameShareMemberNameWithMemberId:(NSInteger)memberId
                                     name:(NSString *)name
                                  success:(ThingSuccessHandler)success
                                  failure:(ThingFailureError)failure;


/// Changes the nickname of the user who receives shared devices.
/// @param memberId The member ID.
/// @param name The nickname.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)renameReceiveShareMemberNameWithMemberId:(NSInteger)memberId
                                            name:(NSString *)name
                                         success:(ThingSuccessHandler)success
                                         failure:(ThingFailureError)failure;




/// Returns a list of users who share a specific device.
/// @param devId The device ID.
/// @param success Called when the task is finished. A list of ThingSmartShareMemberModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getDeviceShareMemberListWithDevId:(NSString *)devId
                                  success:(void(^)(NSArray<ThingSmartShareMemberModel *> *list))success
                                  failure:(ThingFailureError)failure;


/// Sends an invitation to other users to share a device.
/// @param countryCode The country code.
/// @param userAccount The user account.
/// @param devId The device ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)inviteShareWithCountryCode:(NSString *)countryCode
                       userAccount:(NSString *)userAccount
                             devId:(NSString *)devId
                           success:(ThingSuccessInt)success
                           failure:(ThingFailureError)failure;


/// Confirms the sharing invitation.
/// @param shareId The shareId that is returned by the sharing invitation API operation.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)confirmInviteShareWithShareId:(NSInteger)shareId
                              success:(ThingSuccessHandler)success
                              failure:(ThingFailureError)failure;

#pragma mark - Group Share

/// Returns a list of device-sharing users by group ID. The group ID is displayed on the panel.
/// @param groupId The group ID.
/// @param success Called when the task is finished. A list of ThingSmartShareMemberModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getGroupShareMemberListWithGroupId:(NSString *)groupId
                                   success:(void(^)(NSArray<ThingSmartShareMemberModel *> *list))success
                                   failure:(ThingFailureError)failure;


/// Shares groups to other users.
/// @param spaceId The home ID.
/// @param countryCode The country code.
/// @param userAccount The user account.
/// @param groupId The group ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)addGroupShareToMemberWithSpaceId:(long long)spaceId
                             countyCode:(NSString *)countryCode
                            userAccount:(NSString *)userAccount
                                groupId:(NSString *)groupId
                                success:(ThingSuccessID)success
                                failure:(ThingFailureError)failure;

/// Removes the device sharing group from a member.
/// @param relationId The member ID.
/// @param groupId The group ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)removeGroupShareWithRelationId:(NSInteger)relationId
                               groupId:(NSString *)groupId
                               success:(ThingSuccessHandler)success
                               failure:(ThingFailureError)failure;


/// Deletes the device that is shared.
/// @param memberId The member ID.
/// @param devId The device ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)removeDeviceShareWithMemberId:(NSInteger)memberId
                                devId:(NSString *)devId
                              success:(ThingSuccessHandler)success
                              failure:(ThingFailureError)failure;

@end

NS_ASSUME_NONNULL_END
