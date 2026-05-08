//
//  ThingLightingProject+Lighting.h
//  ThingCommercialLightingKit
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)
//

#import <ThingCommercialLightingKit/ThingLightingProject.h>
#import "ThingLampCapacityModel.h"

NS_ASSUME_NONNULL_BEGIN

@class ThingLightingSenceTemplateModel;

@interface ThingLightingProject (Area)

/// Fetch all area model from remote.
/// @param needUnassignedArea Need unassigned area or not.
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)getAreaLevelsWithNeedUnassignedArea:(BOOL)needUnassignedArea
                                    success:(nullable void(^)(NSArray <ThingLightingAreaModel *> *areas, NSInteger totalRoomDeviceCount))success
                                    failure:(nullable ThingFailureError)failure;


/// Fetch all area model from remote.
/// @param needUnassignedArea Need unassigned area or not
/// @param needPublicArea Need public area or not
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)getAreaLevelsWithNeedUnassignedArea:(BOOL)needUnassignedArea
                             needPublicArea:(BOOL)needPublicArea
                                    success:(nullable void(^)(NSArray <ThingLightingAreaModel *> *areas, NSInteger totalRoomDeviceCount))success
                                    failure:(nullable ThingFailureError)failure;


/// Fetch all first level area model from remote
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)getAreaListWithSuccess:(nullable void(^)(NSArray <ThingLightingAreaModel *> *areas))success
                       failure:(nullable ThingFailureError)failure;


/// Fetch collected area model list, please call after use getAreaLevelsWithNeedUnassignedArea:needPublicArea:success:failure: method
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)getCollectionAreaListWithSuccess:(nullable void (^)(NSArray<ThingLightingAreaModel *> * _Nullable areaList))success
                                 failure:(nullable ThingFailureError)failure;



@end



@interface ThingLightingProject (Device)


/// After get project details, update device ota status
/// @param projectId Project ID
/// @param success Called when the task finishes successfully.
/// @param failure  If error occurred while adding the task, this block will be called.
- (void)getDeviceOTAStatusWithProjectId:(long long)projectId
                                success:(void (^)(NSArray<ThingSmartDeviceOTAModel *> *))success
                                failure:(ThingFailureError)failure;


@end

@interface ThingLightingProject (GroupOTA)

/// Query whether there are gateways that are being upgraded in batches.
/// @param projectId project id
/// @param success success
/// @param failure failure
- (void)queryBatchUpgradingGatewaryWithProjectId:(long long)projectId
                                         success:(void(^)(NSString *status))success
                                         failure:(nullable ThingFailureError)failure;

@end

@interface ThingLightingProject (Config)

- (void)getLimitInfoWithSuccess:(void (^)(NSDictionary *info))success failure:(nullable ThingFailureError)failure;

- (void)fetchPointsValidateWithSuccess:(ThingSuccessDict)success failure:(nullable ThingFailureError)failure;

- (void)fetchMechantValidateWithSuccess:(void (^)(NSArray<ThingLampCapacityModel *> *result))success failure:(nullable ThingFailureError)failure;

- (void)checkDeviceLimitWithDeviceIds:(NSArray *)deviceIds
                              success:(void (^)(NSArray<NSString *> *list))success
                              failure:(nullable ThingFailureError)failure;

- (void)fetchAlarmCountWithSuccess:(ThingSuccessBOOL)success failure:(nullable ThingFailureError)failure;

@end


@interface ThingLightingProject (Template)

- (void)fetchSceneTemplateListWithPage:(NSInteger)page
                              pageSize:(NSInteger)pageSize
                               success:(void(^)(NSArray<ThingLightingSenceTemplateModel *> *list, BOOL end))success
                               failure:(ThingFailureError)failure;

- (void)copySceneTemplateWithTemplateId:(NSString *)templateId
                                success:(ThingSuccessID)success
                                failure:(ThingFailureError)failure;

- (void)deleteSceneTemplateWithTemplateId:(NSString *)templateId
                                  success:(ThingSuccessID)success
                                  failure:(ThingFailureError)failure;

- (void)generateSceneTemplateWithTemplateId:(NSString *)templateId
                                    areaIds:(NSString *)areIds
                                    success:(void(^) (NSInteger count))success
                                    failure:(ThingFailureError)failure;

- (void)checkAvailableAreaListWithTemplateId:(NSString *)templateId
                                     success:(void (^)(NSArray *areaList))success
                                     failure:(ThingFailureError)failure;

- (void)saveOrEditSceneTemplateWithParams:(NSDictionary *)params
                                  success:(ThingSuccessID)success
                                  failure:(ThingFailureError)failure;

@end


NS_ASSUME_NONNULL_END
