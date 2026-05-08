//
//  ThingLightingProjectManager.h
//  ThingSmartCommercialLightingSdk
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)
//

#import <Foundation/Foundation.h>
#import <ThingCommercialLightingKit/ThingCLProjectPublicEnum.h>

NS_ASSUME_NONNULL_BEGIN

@class ThingLightingProjectManager, ThingLightingProjectModel;

@protocol ThingLightingProjectManagerDelegate <NSObject>

@optional

/// The delegate when a new project is added.
/// @param manager  Instance
/// @param project  Project model
- (void)projectManager:(ThingLightingProjectManager *)manager didAddProject:(ThingLightingProjectModel *)project;

/// The delegate when an existing project is removed.
/// @param manager  Instance
/// @param projectId   Project ID
- (void)projectManager:(ThingLightingProjectManager *)manager didRemoveProject:(long long)projectId;

/// MQTT service connection success callback.
- (void)serviceConnectedSuccess;

@end

/// @brief ThingLightingProjectManager provides methds for developers to manage project list.
/// ThingLightingProjectManager is is a prerequisite for obtaining project data. It is the entrance to other functions of the SDK, providing interfaces for obtaining project lists and configurations, creating new projects, etc.
@interface ThingLightingProjectManager : NSObject

/// The project model list that read from cache
/// @warning If project list is empty, you can fetch it  by use getProjectListWithSuccess:failure: method
@property (nonatomic, strong, readonly) NSArray<ThingLightingProjectModel *> *projectList;

/// The project manager delegate
@property (nonatomic, weak) id<ThingLightingProjectManagerDelegate> delegate;


/// Get list of project  from remote.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)getProjectListWithSuccess:(nullable void(^)(NSArray<ThingLightingProjectModel *> *projectList))success
                          failure:(nullable void(^)(NSError *error))failure;

/// Create a new indoor project.
/// @param projectName Project name
/// @param leaderName Project leader name
/// @param leaderMobile Project leader mobile
/// @param detailAddress Project detail address
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)createIndoorProjectWithProjectName:(nonnull NSString *)projectName
                               networkType:(ThingLightingProjectMeshMode)networkType
                                leaderName:(nonnull NSString *)leaderName
                              leaderMobile:(nonnull NSString *)leaderMobile
                             detailAddress:(nonnull NSString *)detailAddress
                                   success:(nullable void(^)(id result))success
                                   failure:(nullable void(^)(NSError *error))failure;


/// Create a new outdoor project
/// @param projectName Project name
/// @param leaderName Project leader name
/// @param leaderMobile Project leader mobile
/// @param detailAddress Project detail address
/// @param regionLocationId Region location id that is made up of a combination of country code and first-level administrative area code,  which separated by English commas；it can be obtained through ThingLightingRegionManager.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)createOutdoorProjectWithProjectName:(nonnull NSString *)projectName
                                networkType:(ThingLightingProjectMeshMode)networkType
                                 leaderName:(nonnull NSString *)leaderName
                               leaderMobile:(nonnull NSString *)leaderMobile
                              detailAddress:(nonnull NSString *)detailAddress
                           regionLocationId:(nonnull NSString *)regionLocationId
                                    success:(nullable void(^)(id result))success
                                    failure:(nullable void(^)(NSError *error))failure;


/// Create a project.
/// @param projectType Project type
/// @param projectName Project name
/// @param leaderName Project leader name
/// @param leaderMobile Project leader mobile
/// @param detailAddress Project detail address
/// @param regionLocationId  Region location id that is made up of a combination of country code and first-level administrative area code,  which separated by English commas；it can be obtained through ThingLightingRegionManager.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)createProjectWithProjectType:(ThingLightingProjectType)projectType
                         networkType:(ThingLightingProjectMeshMode)networkType
                         projectName:(nonnull NSString *)projectName
                          leaderName:(nonnull NSString *)leaderName
                        leaderMobile:(nonnull NSString *)leaderMobile
                       detailAddress:(nonnull NSString *)detailAddress
                    regionLocationId:(nullable NSString *)regionLocationId
                             success:(nullable void(^)(id result))success
                             failure:(nullable void(^)(NSError *error))failure;

@end

@class ThingLightingProjectConfigModel, ThingLightingProjectSpaceItemModel, ThingLightingProjectValidationItemModel;

/// @brief ThingLightingProjectManager+ProjectConfig category provides methds for developers to get project config, area config and valid input range.
@interface ThingLightingProjectManager (ProjectConfig)

/// Get list of project config  from remote.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)getProjectConfigListWithSuccess:(nullable void(^)(NSArray<ThingLightingProjectConfigModel *> *configList))success
                                failure:(nullable void(^)(NSError *error))failure;


/// Get list of project config  from cache.
/// @return Project config list
- (NSArray<ThingLightingProjectConfigModel *> *)getProjectConfigListFromCache;


/// Get list of space attributes from cache.
/// @param projectId Project ID
/// @return Space attributes model list
- (NSArray<ThingLightingProjectSpaceItemModel *> *)getSpaceAttributesWithProjectId:(long long)projectId;


/// Get a space attribute from cache.
/// @param projectId Project ID
/// @param roomLevel Area level
/// @return Space item model
- (ThingLightingProjectSpaceItemModel *)getSpaceItemModelWithProjectId:(long long)projectId roomLevel:(NSInteger)roomLevel;


/// Get previous space attribute from cache.
/// @param projectId Project ID
/// @param roomLevel Area level
/// @return Space attributes model
- (ThingLightingProjectSpaceItemModel *)getPreSpaceItemModelWithProjectId:(long long)projectId roomLevel:(NSInteger)roomLevel;


/// Get next space attribute from cache.
/// @param projectId Project ID
/// @param roomLevel Area level
/// @return Space attributes model
- (ThingLightingProjectSpaceItemModel *)getNextSpaceItemModelWithProjectId:(long long)projectId roomLevel:(NSInteger)roomLevel;


/// Check whether it is the first level space.
/// @param projectId  Project ID
/// @param roomLevel Area level
- (BOOL)isFirstLevelWithProjectId:(long long)projectId roomLevel:(NSInteger)roomLevel;


/// Check whether it is the last level space.
/// @param projectId Project ID
/// @param roomLevel Area level
- (BOOL)isLastLevelWithProjectId:(long long)projectId roomLevel:(NSInteger)roomLevel;


/// Get the valid range of input according to the code.
/// @param projectId Project ID
/// @param code  Validation code
- (ThingLightingProjectValidationItemModel *)getValidationItemModelWithProjectId:(long long)projectId code:(NSString *)code;

@end

#pragma mark - Validation Config Code

FOUNDATION_EXPORT NSString * const ThingLightingProjectValidationCodeSceneName;
FOUNDATION_EXPORT NSString * const ThingLightingProjectValidationCodeProjectAddress;
FOUNDATION_EXPORT NSString * const ThingLightingProjectValidationCodeProjectMeshMode;
FOUNDATION_EXPORT NSString * const ThingLightingProjectValidationCodeAreaName;
FOUNDATION_EXPORT NSString * const ThingLightingProjectValidationCodeLinkageName;
FOUNDATION_EXPORT NSString * const ThingLightingProjectValidationCodeLeaderMobile;
FOUNDATION_EXPORT NSString * const ThingLightingProjectValidationCodeCalendarName;
FOUNDATION_EXPORT NSString * const ThingLightingProjectValidationCodeLeaderName;
FOUNDATION_EXPORT NSString * const ThingLightingProjectValidationCodeGroupName;
FOUNDATION_EXPORT NSString * const ThingLightingProjectValidationCodeProjectName;

NS_ASSUME_NONNULL_END
