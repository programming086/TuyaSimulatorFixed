//
//  ThingLightSceneManager.h
//  ThingLightSceneKit
//
//  Copyright (c) 2014-2021 Thing (https://developer.thing.com/)

#import <Foundation/Foundation.h>
#import "ThingLightSceneEnums.h"
#import "ThingLightSceneModel.h"
#import "ThingLightScenePreviewResultModel.h"
#import "ThingLightAreaModel.h"
#import "ThingLightSceneActionModel.h"
#import "ThingLightSceneSituationModel.h"
#import "ThingLightSceneCustomSituationModel.h"
#import "ThingLightSceneIconsModel.h"
#import "ThingLightSceneFunctionModel.h"
#import "ThingLightRegionSceneModel.h"
#import "ThingLightSceneMusicLibModel.h"
#import "ThingLightSceneTempValueModel.h"

NS_ASSUME_NONNULL_BEGIN

@class ThingLightSceneManager;

@protocol ThingLightSceneManagerDelegate<NSObject>

@optional

/// This method will be called when the state of the scene changed.
///
/// @param manager The  scene manager.
/// @param state The scene state, eg: "update、"delete".
/// @param sceneId The scene ID.
- (void)sceneManager:(ThingLightSceneManager *)manager state:(NSString *)state sceneId:(NSString *)sceneId;

@end

@interface ThingLightSceneManager : NSObject

+ (instancetype)sharedInstance;

@property (nonatomic, weak) id<ThingLightSceneManagerDelegate> delegate;

/// Get a list of regions and standard devices
///
/// @param areas  All devices in the place
/// @param success Callback for successful request
/// @param failure Callback for failed request
- (void)filterDevicesWithAreas:(NSArray <ThingLightAreaModel *>*)areas
                       success:(void(^)(NSArray<ThingLightAreaModel *>*areas))success
                       failure:(void(^)(NSError *error))failure;

/// Get a list of all lighting scenes
///
/// @param gid The unique identifier for the location
/// @param success Callback for successful request
/// @param failure Callback for failed request
- (void)getAllLightSceneListWithGid:(long long)gid
                            success:(void(^)(NSArray<ThingLightSceneModel *>*scenes))success
                            failure:(void(^)(NSError *error))failure;

/// Get a list of all lighting scenes from disk
///
/// @param gid The unique identifier for the location
/// @param success Callback for successful request
- (void)getAllLightSceneListFromDiskWithGid:(long long)gid
                                    success:(void(^)(NSArray<ThingLightSceneModel *>*scenes))success;

/// Get a list of lighting scenes in a certain region
///
/// @param gid The unique identifier for the location
/// @param parentRegionId The parent region ID of the lighting scene
/// @param success Callback for successful request
/// @param failure Callback for failed request
- (void)getLightSceneListWithGid:(long long)gid
                  parentRegionId:(NSString * _Nullable)parentRegionId
                         success:(void(^)(NSArray<ThingLightSceneModel *>*scenes))success
                         failure:(void(^)(NSError *error))failure;

/// Get a list of lighting scenes in all regions
///
/// @param gid The unique identifier for the location
/// @param success Callback for successful request
/// @param failure Callback for failed request
- (void)getLightRegionSceneListWithGid:(long long)gid
                               success:(void(^)(NSArray<ThingLightRegionSceneModel *>*regionScenes))success
                               failure:(void(^)(NSError *error))failure;

/// Get a list for the details of  lighting scenes on current family
///
/// @param gid The unique identifier for the location
/// @param success Callback for successful request
/// @param failure Callback for failed request
- (void)getAllLightSceneDetailsWithGid:(long long)gid
                               success:(void(^)(NSArray<ThingLightSceneModel *>*scenes))success 
                               failure:(ThingFailureError)failure;

/// High power of the device
///
/// @param gid The unique identifier for the location
/// @param params The params of request
/// @param success Callback for successful request
/// @param failure Callback for failed request
- (void)getLightSceneBizSupportWithGid:(long long)gid
                                params:(NSDictionary *)params
                               success:(ThingSuccessList)success
                               failure:(ThingFailureError)failure;
/// Scene modes of the single lamp
///
/// @param gid The unique identifier for the location
/// @param devId The unique identifier for the single lamp
/// @param success Callback for successful request
/// @param failure Callback for failed request
- (void)getLightSceneSituationListWithGid:(long long)gid
                                    devId:(NSString *)devId
                                  success:(void(^)(NSArray<ThingLightSceneSituationModel *>*situations))success
                                  failure:(void(^)(NSError *error))failure;

/// Scene modes of the group lamp
///
/// @param gid The unique identifier for the location
/// @param groupId The unique identifier for the group lamp
/// @param success Callback for successful request
/// @param failure Callback for failed request
- (void)getLightSceneSituationListByGroupWithGid:(long long)gid
                                         groupId:(NSString *)groupId
                                         success:(void(^)(NSArray<ThingLightSceneSituationModel *>*situations))success
                                         failure:(void(^)(NSError *error))failure;

/// Custom lights corresponding to single lamp
///
/// @param gid The unique identifier for the location
/// @param devId The unique identifier for the selected single lamp
/// @param success Callback for successful request
/// @param failure Callback for failed request
- (void)getLightSceneFunctionListWithGid:(long long)gid
                                   devId:(NSString *)devId
                                 success:(void(^)(NSArray<ThingLightSceneFunctionModel *>*functions))success
                                 failure:(void(^)(NSError *error))failure;

/// Custom lights corresponding to group lamp
///
/// @param gid The unique identifier for the location
/// @param groupId The unique identifier for the selected group lamp
/// @param success Callback for successful request
/// @param failure Callback for failed request
- (void)getLightSceneFunctionListByGroupWithGid:(long long)gid
                                        groupId:(NSString *)groupId
                                        success:(void(^)(NSArray<ThingLightSceneFunctionModel *>*functions))success
                                        failure:(void(^)(NSError *error))failure;

/// The details of the lighting scene
///
/// @param gid The unique identifier for the location
/// @param code The unique code of the lighting scene
/// @param success Callback for successful request
/// @param failure Callback for failed request
- (void)getLightSceneDetailWithGid:(long long)gid
                              code:(NSString *)code
                           success:(void(^)(ThingLightSceneModel *sceneModel))success
                           failure:(void(^)(NSError *error))failure;

/// Create a lighting scene
///
/// @param gid The unique identifier for the location
/// @param parentRegionId The parent region ID of the lighting scene
/// @param name The name of the lighting scene
/// @param icon The icon of the lighting scene
/// @param actions Actions of the lighting scene
/// @param success Callback for successful request
/// @param failure Callback for failed request
- (void)createLightSceneWithGid:(long long)gid
                 parentRegionId:(NSString *)parentRegionId
                           name:(NSString *)name
                           icon:(NSString *)icon
                        actions:(NSArray<ThingLightSceneActionModel *>*)actions
                        success:(void(^)(ThingLightSceneModel *sceneModel))success
                        failure:(void(^)(NSError *error))failure;

/// Edit the lighting scene
///
/// @param gid The unique identifier for the location
/// @param sceneExpr The model of the edited lighting scene
/// @param success Callback for successful request
/// @param failure Callback for failed request
- (void)editLightSceneWithGid:(long long)gid
                    sceneExpr:(ThingLightSceneModel *)sceneExpr
                      success:(void(^)(ThingLightSceneModel *sceneModel))success
                      failure:(void(^)(NSError *error))failure;

/// Preview the lighting scene
///
/// @param gid The unique identifier for the location
/// @param actions Actions of the lighting scene
/// @param parentRegionId The parent region ID of the lighting scene
/// @param type The preview type of the lighting scene
/// @param success Callback for successful request
/// @param failure Callback for failed request
- (void)previewLightSceneWithGid:(long long)gid
                         actions:(NSArray<ThingLightSceneActionModel *>*)actions
                  parentRegionId:(NSString *)parentRegionId
                            type:(ThingLightScenePreviewType)type
                         success:(void(^)(ThingLightScenePreviewResultModel *resultModel))success
                         failure:(void(^)(NSError *error))failure;

/// Preview the effect of overall brightness adjustment
///
/// @param gid The unique identifier for the location
/// @param actions The preview data collection of the lighting scene
/// @param originPercent The origin percent of the lighting scene
/// @param targetPercent The target percent of the lighting scene
/// @param success Callback for successful request
/// @param failure Callback for failed request
- (void)previewLightSceneBrightWithGid:(long long)gid
                               actions:(NSArray<ThingLightSceneActionModel *>*)actions
                         originPercent:(NSInteger)originPercent
                         targetPercent:(NSInteger)targetPercent
                               success:(void(^)(ThingLightScenePreviewResultModel *resultModel))success
                               failure:(void(^)(NSError *error))failure;

/// Sort the lighting scene
///
/// @param gid The unique identifier for the location
/// @param parentRegionId The parent region ID of the lighting scene
/// @param codes Codes of all lighting scenes in order
/// @param success Callback for successful request
/// @param failure Callback for failed request
- (void)sortLightSceneWithGid:(long long)gid
               parentRegionId:(NSString *)parentRegionId
                        codes:(NSArray<NSString *>*)codes
                      success:(void(^)(NSArray<ThingLightSceneModel *>*scenes))success
                      failure:(void(^)(NSError *error))failure;

/// Whether the lighting scene is associated with a schedule
///
/// @param gid The unique identifier for the location
/// @param code The unique code of the lighting scene
/// @param success Callback for successful request
/// @param failure Callback for failed request
- (void)lightSceneBindScheduleWithGid:(long long)gid
                                 code:(NSString *)code
                              success:(void(^)(BOOL result))success
                              failure:(void(^)(NSError *error))failure;

/// The icon List of the lighting scene
///
/// @param gid The unique identifier for the location
/// @param success Callback for successful request
/// @param failure Callback for failed request
- (void)lightSceneIconsWithGid:(long long)gid
                       success:(void(^)(ThingLightSceneIconsModel *iconsModel))success
                       failure:(void(^)(NSError *error))failure;

/// Get the certain high power of device
///
/// @param gid The unique identifier for the location
/// @param bizId The unique identifier for the selected equipment
/// @param bizType The equipment type, single lamp = 0, group lamp = 1
/// @param abilityCode The ability code of the selected equipment
/// @param success Callback for successful request
/// @param failure Callback for failed request
- (void)getLightSceneHighPowerWithGid:(long long)gid
                                bizId:(NSString *)bizId
                              bizType:(long long)bizType
                          abilityCode:(NSString *)abilityCode
                              success:(ThingSuccessList)success
                              failure:(ThingFailureError)failure;

/// Get the certain high power of device
///
/// @param bizId The unique identifier for the selected equipment
/// @param bizType The equipment type, single lamp = 0, group lamp = 1
/// @param libType The library type of the selected equipment
/// @param libVersion The library version of the selected equipment
/// @param libDataType The library data type of the selected equipment
/// @param success Callback for successful request
/// @param failure Callback for failed request
- (void)getPanelLibraryDataWithBizId:(NSString *)bizId
                             bizType:(NSInteger)bizType
                             libType:(NSString *)libType
                          libVersion:(NSString *)libVersion
                         libDataType:(NSInteger)libDataType
                             success:(ThingSuccessList)success
                             failure:(ThingFailureError)failure;

/// Get the key points for colour temperature of devices
///
/// @param gid The unique identifier for the location
/// @param areaId The unique identifier for the area
/// @param success Callback for successful request
/// @param failure Callback for failed request
- (void)getDevicesTempKeyPointsWithGid:(long long)gid
                                areaId:(long long)areaId
                               success:(void(^)(NSArray<ThingLightSceneTempValueModel *>*values))success
                               failure:(ThingFailureError)failure;

/// clean scene caches
- (void)cleanSceneCache;

@end

NS_ASSUME_NONNULL_END
