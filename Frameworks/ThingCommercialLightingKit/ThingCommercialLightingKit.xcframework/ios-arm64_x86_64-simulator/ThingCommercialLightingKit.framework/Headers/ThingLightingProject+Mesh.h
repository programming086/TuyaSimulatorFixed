//
//  ThingLightingProject+Mesh.h
//  ThingCLMeshManageModule
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)
//

#import <ThingCommercialLightingKit/ThingLightingProject.h>

#import <ThingSmartUtil/ThingSmartUtil.h>

@class ThingSmartBleMeshModel;

NS_ASSUME_NONNULL_BEGIN

@interface ThingLightingProject (Mesh)


- (void)connectTargetMesh:(NSString *)meshId;


/// Obtain network management list data
/// - Parameters:
///   - success: Success callback
///   - failure: Failure callback
- (void)fecthMeshManageListWithSuccess:(nullable void(^)(NSArray<ThingSmartBleMeshModel *> *array))success
                               failure:(nullable void(^)(NSError *error))failure;


/// Create a SIG Mesh
/// - Parameters:
///   - name: name
///   - success: Success callback
///   - failure: Failure callback
- (void)createMeshWithName:(NSString *)name
                   success:(nullable ThingSuccessID)success
                   failure:(nullable void(^)(NSError *error))failure;


/// Bind SIG Mesh and area
/// - Parameters:
///   - meshId: meshId
///   - areaId: areaId
///   - success: Success callback
///   - failure: Failure callback
- (void)bindMeshAndAreaWithMeshId:(NSString *)meshId
                           areaId:(long long)areaId
                          success:(nullable ThingSuccessID)success
                          failure:(nullable void(^)(NSError *error))failure;

/// Unbind SIG Mesh and area
/// - Parameters:
///   - meshId: meshId
///   - areaId: areaId
///   - success: Success callback
///   - failure: Failure callback
- (void)unbindMeshAndAreaWithMeshId:(NSString *)meshId
                             areaId:(long long)areaId
                            success:(nullable ThingSuccessID)success
                            failure:(nullable void(^)(NSError *error))failure;


/// Delete SIG Mesh
/// - Parameters:
///   - meshId: SIG Mesh id
///   - success: Success callback
///   - failure: Failure callback
- (void)deleteMeshWithMeshId:(NSString *)meshId
                     success:(nullable ThingSuccessID)success
                     failure:(nullable void(^)(NSError *error))failure;


/// Get the area and devices bound to the SIG Mesh.
/// - Parameters:
///   - meshId: SIG Mesh id
///   - success: Success callback
///   - failure: Failure callback
- (void)fetchMeshStatisticsWithMeshId:(NSString *)meshId
                              success:(nullable ThingSuccessID)success
                              failure:(nullable void(^)(NSError *error))failure;

/// Get the areas associated with the SIG Mesh, do not return the sub-level areas
/// - Parameters:
///   - meshId: SIG Mesh id
///   - includeStatic: Does it include statistical information
///   - offsetKey: Paging Key
///   - success: Success callback
///   - failure: Failure callback
- (void)fetchMeshBindAreasWithMeshId:(NSString *)meshId
                       includeStatic:(BOOL)includeStatic
                             success:(nullable void(^)(NSArray<ThingLightingAreaModel *> *areaList))success
                             failure:(nullable void(^)(NSError *error))failure;


/// Upate SIG Mesh information
/// - Parameters:
///   - meshId: SIG Mesh id
///   - name: SIG Mesh name
///   - success: Success callback
///   - failure: Failure callback
- (void)updateMeshNameWithMeshId:(NSString *)meshId
                            name:(NSString *)name
                         success:(nullable ThingSuccessID)success
                         failure:(nullable void(^)(NSError *error))failure;

#pragma mark - Mesh List

/// Get the Sig mesh model list
/// @param success Called when the task finishes successfully.
/// @param failure Failure callback
- (void)getSIGMeshListWithSuccess:(void(^)(NSArray <ThingSmartBleMeshModel *> *list))success
                          failure:(ThingFailureError)failure;

/// Get the private Mesh model list
/// @param success Success callback
/// @param failure Failure callback
- (void)getMeshListWithSuccess:(void(^)(NSArray <ThingSmartBleMeshModel *> *list))success
                       failure:(ThingFailureError)failure;

/// Get both the SIG Mesh and private mesh lists simultaneously.
- (void)getSIGMeshAndMeshListWithSuccess:(void(^)(NSArray <ThingSmartBleMeshModel *> *list))success
                                 failure:(ThingFailureError)failure;

#pragma mark - Compatible

/// Add mesh to projects created for commercial version 1.x.
/// - Parameters:
///   - success: Success callback
///   - failure: Failure callback
- (void)createMeshForLegacyProject:(nullable ThingSuccessID)success
                           failure:(nullable void(^)(NSError *error))failure;


@end

NS_ASSUME_NONNULL_END
