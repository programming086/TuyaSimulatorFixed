//
//  ThingSmartUser+ThingCLMember.h
//  ThingCommercialLightingKit
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)
//

#import <ThingSmartBaseKit/ThingSmartBaseKit.h>

@class ThingLightingAreaModel;
@class ThingMemberModel;
@class ThingLightingProjectModel;

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartUser (ThingCLMember)


/// Add member
/// - Parameters:
///   - account: account
///   - nickName: nickName
///   - password: password（MD5）
///   - countryCode: country code
///   - success: Success callback
///   - failure: Failure callback
- (void)addNewMemberWithAccout:(NSString *)account
                      nickName:(NSString *)nickName
                      password:(NSString *)password
                   countryCode:(NSString *)countryCode
                       success:(nullable ThingSuccessID)success
                       failure:(nullable ThingFailureError)failure;


/// Get member list
/// - Parameters:
///   - roleCode: Role type code
///   - success: Success callback
///   - failure: Failure callback
- (void)fetchMemberListWithRoleCode:(NSString *)roleCode
                            success:(nullable void(^)(NSArray<ThingMemberModel *> *array))success
                            failure:(nullable ThingFailureError)failure;


/// Search members
/// - Parameters:
///   - keyword: Keyword, account, or nickname
///   - success: Success callback
///   - failure: Failure callback
- (void)searchMemberWithKeyword:(NSString *)keyword
                        success:(nullable void(^)(NSArray<ThingMemberModel *> *array))success
                        failure:(nullable ThingFailureError)failure;



/// Get the list of projects for which a specific member has been authorized
/// - Parameters:
///   - uid: member uid
///   - success: Success callback
///   - failure: Failure callback
- (void)fetchAuthorizedProjectsWithUid:(NSString *)uid
                               success:(nullable void(^)(NSArray<ThingLightingProjectModel *> *array))success
                               failure:(nullable ThingFailureError)failure;



/// Get the list of roles for member list filtering and setting member roles
/// - Parameters:
///   - filter: Whether filtering is required
///   - success: Success callback
///   - failure: Failure callback
- (void)fetchRoleListWithFilter:(BOOL)filter
                        success:(nullable void(^)(NSArray<NSDictionary *> *array))success
                        failure:(nullable ThingFailureError)failure;


/// Set member permissions
/// - Parameters:
///   - uid: member uid
///   - roleCode: Role code
///   - success: Success callback
///   - failure: Failure callback
- (void)setMemberRoleWithUid:(NSString *)uid
                    roleCode:(NSString *)roleCode
                     success:(nullable ThingSuccessID)success
                     failure:(nullable ThingFailureError)failure;



/// Grant projects authorization to a member
/// - Parameters:
///   - uid: member uid
///   - gids: Project ID, separated by commas if there are multiple.
///   - success: Success callback
///   - failure: Failure callback
- (void)authorizeProjectsWithUid:(NSString *)uid
                      projectIds:(NSString *)projectIds
                         success:(nullable ThingSuccessID)success
                         failure:(nullable ThingFailureError)failure;


/// Revoke project authorization
/// - Parameters:
///   - uid: Member uid
///   - projectId: Project ID
///   - success: Success callback
///   - failure: Failure callback
- (void)cancelAuthorizationProjectsWithUid:(NSString *)uid
                                 projectId:(NSString *)projectId
                                   success:(nullable ThingSuccessID)success
                                   failure:(nullable ThingFailureError)failure;


/// Get the areas authorized for the current member's projects
/// - Parameters:
///   - uid: Member uid
///   - projectId: Project ID
///   - success: Success callback
///   - failure: Failure callback
- (void)fetchAuthorizedAreasWithUid:(NSString *)uid
                          projectId:(long long)projectId
                            success:(nullable void(^)(NSArray<NSNumber *> *array))success
                            failure:(nullable ThingFailureError)failure;

/// Delete member
/// - Parameters:
///   - uid: member uid
///   - success: Success callback
///   - failure: Failure callback
- (void)deleteMemberWithUid:(NSString *)uid
                    success:(nullable ThingSuccessID)success
                    failure:(nullable ThingFailureError)failure;



/// Get the list of projects for the currently logged-in account
/// - Parameters:
///   - success: Success callback
///   - failure: Failure callback
- (void)fetchProjectListWihtSuccess:(nullable void(^)(NSArray<ThingLightingProjectModel *> *array))success failure:(nullable ThingFailureError)failure;


/// Get all areas under the project
/// - Parameters:
///   - projectId: Project ID
///   - success: Success callback
///   - failure: Failure callback
- (void)fetchAreasWithProjectId:(long long)projectId
                        success:(nullable void(^)(NSArray<ThingLightingAreaModel *> * _Nullable areas))success
                        failure:(ThingFailureError)failure;



/// Modify the area authorization for the project
/// - Parameters:
///   - uid: member uid
///   - projectId: Project ID
///   - areaIds: Area ID list
///   - success: Success callback
///   - failure: Failure callback
- (void)modifyAuthorizedAreasWithUid:(NSString *)uid
                           projectId:(long long)projectId
                             areaIds:(NSArray<NSNumber *> *)areaIds
                             success:(nullable ThingSuccessID)success
                             failure:(nullable ThingFailureError)failure;

@end

NS_ASSUME_NONNULL_END
