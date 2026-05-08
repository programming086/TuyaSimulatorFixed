//
//  ThingCLProject.h
//  ThingCLProjectKit
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)
//

#import <Foundation/Foundation.h>
#import <ThingSmartUtil/ThingSmartUtil.h>

@class ThingLightingProjectModel;
@class ThingLightingVasModel;

NS_ASSUME_NONNULL_BEGIN


@interface ThingCLProject : NSObject


/// Project model read from cache, which need to use  getProjectDetailWithSuccess:failure: method.
@property (nonatomic, strong, readonly, nullable) ThingLightingProjectModel *model;


- (instancetype)init NS_UNAVAILABLE;


/// Get ThingLightingProject instance.
/// @param projectId The project ID.
+ (instancetype)projectWithProjectId:(long long)projectId;


/// Get ThingLightingProject instance.
/// @param projectId The project ID.
- (instancetype)initWithProjectId:(long long)projectId NS_DESIGNATED_INITIALIZER;


/// Get project model from remote.
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)getProjectInfoWithSuccess:(nullable void(^)(id result))success
                          failure:(nullable void(^)(NSError *error))failure;


/// Update project info.
/// @param projectName project name
/// @param leaderName project leader name
/// @param leaderMobile project leader mobile
/// @param detailAddress project detail address
/// @param regionLocationId region location id that is made up of a combination of country code and first-level administrative area code,  which separated by English commas；it can be obtained through ThingLightingRegionManager.
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)updateProjectInfoWithProjectName:(nonnull NSString *)projectName
                              leaderName:(nonnull NSString *)leaderName
                            leaderMobile:(nonnull NSString *)leaderMobile
                           detailAddress:(nonnull NSString *)detailAddress
                        regionLocationId:(nullable NSString *)regionLocationId
                                 success:(nullable void(^)(id result))success
                                 failure:(nullable void(^)(NSError *error))failure;


/// Delete project.
/// @param password user password
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)deleteProjectWithPassword:(nonnull NSString *)password
                          success:(nullable void(^)(void))success
                          failure:(nullable void(^)(NSError *error))failure;



/// Delete project.
/// @param key the key
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)deleteProjectWithKey:(NSString *)key
                     success:(void(^)(void))success
                     failure:(void(^)(NSError *error))failure;


- (void)queryVasListWithSuccess:(void(^)(NSArray<ThingLightingVasModel *> *))success failure:(void(^)(NSError *error))failure;



@end

NS_ASSUME_NONNULL_END
