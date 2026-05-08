//
//  ThingSmartSceneManager.h
//  ThingSmartSceneKit
//
//  Copyright (c) 2014-2021 Thing Inc. (https://developer.thing.com)

#import <ThingSmartDeviceCoreKit/ThingSmartDeviceCoreKit.h>
#import "ThingSmartCityModel.h"
#import "ThingSmartSceneDPModel.h"
#import "ThingSmartSceneModel.h"
#import "ThingSmartSceneLogModel.h"
#import "ThingSmartSceneLogDetailModel.h"
#import "ThingSmartSceneCoreFeatureModel.h"
#import "ThingSmartHomePageSceneParams.h"
#import "ThingSmartSceneConditionCategoryListModel.h"
#import "TSceneConditionCategoryListRequestParams.h"
#import "TSceneDefined.h"
#import "TSceneRecomListParams.h"
#import "TSceneRecomHandleParams.h"
#import "TSceneDetailParams.h"

@class ThingSmartSceneManager;

/// The protocol provides delegate methods to receive changes to the scene enable or disable state.
@protocol ThingSmartSceneManagerDelegate<NSObject>

@optional

/// Called when the state of the scene changes.
///
/// @param manager The scene manager.
/// @param state   The scene state, eg: "disable、"enable".
/// @param sceneId The scene ID.
- (void)sceneManager:(ThingSmartSceneManager *)manager state:(NSString *)state sceneId:(NSString *)sceneId;

@end

/// @brief The ThingSmartSceneManager class provides many methods for developers getting the list of scenes, getting the list of conditions, getting the list of tasks, the list of cities, the list of scene log, etc.
@interface ThingSmartSceneManager : NSObject

@property (nonatomic, strong, readonly) NSMutableArray *conditionData;
@property (nonatomic, strong, readonly) NSMutableArray *statusConditionData;
@property (nonatomic, strong, readonly) NSMutableArray *actionData;
@property (nonatomic, strong, readonly) NSMutableArray *groupData;
@property (nonatomic, strong, readonly) NSMutableDictionary *deviceIdToPidMap;

/// Returns the singleton of the ThingSmartSceneManager class.
///
/// @return The ThingSmartSceneManager instance.
+ (instancetype)sharedInstance;

/// The delegate will be notified when the scene's contents change. @see ThingSmartSceneManagerDelegate.
@property (nonatomic, weak) id<ThingSmartSceneManagerDelegate> delegate;

// MARK: - Scene Base

/// Get a simple list of scenes, including tap-to-run and automation. We can judge tap-to-run and automation scene by the entityType of conditions property in ThingSmartSceneModel, The scene is tap-to-run when the entityType equal AutoTypeManual, otherwise it's automation.
///
/// @note The different between the simple scene list and scene list is less json data returned by the server.
///
/// @param homeId  The current home ID.
/// @param success When successfully get the scene list, this block will be called and return ThingSmartSceneModel list.
/// @param failure When error occurred, this block will be called and return ThingFailureError.
- (void)getSimpleSceneListWithHomeId:(long long)homeId
                             success:(ThingSceneGetListCompletion)success
                             failure:(ThingFailureError)failure;


/// Get the scene list by `ThingSmartHomePageSceneParams` request params.
/// @param homeId The home ID.
/// @param params The request params, detail see `ThingSmartHomePageSceneParams` object.
/// @param success When success, return `ThingSmartSceneModel` list.
/// @param failure When error occurred, return ThingFailureError object.
- (void)getSceneListForHomePageWithHomeId:(long long)homeId
                                   params:(ThingSmartHomePageSceneParams *)params
                                  success:(ThingSuccessList)success
                                  failure:(ThingFailureError)failure;

/// Get scene detail information according to the specify homeId and sceneId.
///
/// @param homeId  The home ID.
/// @param sceneId The scene ID.
/// @param success When successfully get scene detail, this block will be called and return ThingSmartSceneModel object.
/// @param failure When error occurred, this block will be called and return ThingFailureError.
- (void)getSceneDetailWithHomeId:(long long)homeId
                         sceneId:(NSString *)sceneId
                         success:(ThingSceneGetModelCompletion)success
                         failure:(ThingFailureError)failure;


/// Get scene detail information with the detail request parameter infomation.
/// @param detailParams The detail request params.
/// @param success When successfully return the scene detail model.
/// @param failure When error occurred return the failure error.
- (void)fetchSceneDetailWithDetailParams:(TSceneDetailParams *)detailParams
                                 success:(ThingSceneGetModelCompletion)success
                                 failure:(ThingFailureError)failure;

/// Batch delete scenes.
/// @param sceneIds [sceneId1, sceneId2, sceneId3]
/// @param homeId The home id.
/// @param success Success callback.
/// @param failure Failure callback.
- (void)batchDeleteScenesWithSceneIds:(NSArray<NSString *> *)sceneIds
                              homeId:(long long)homeId
                             success:(ThingSuccessBOOL)success
                             failure:(ThingFailureError)failure;

/// Execute scene in the cloud.
/// @param sceneId The scene ID.
/// @param success When success, description the scene is excuted successfully.
/// @param failure When error occurred, return error.
- (void)executeSmartSceneWithId:(NSString *)sceneId
                        Success:(ThingSuccessHandler)success
                        failure:(ThingFailureError)failure;

// MARK: - Device List

/// Get the list of status condition device list.
/// @param homeId The homeID.
/// @param success When success, return device list of status condition.
/// @param failure When error occurred, return error.
- (void)getStatusConditionDeviceListWithHomeId:(long long)homeId
                                       success:(ThingSceneGetDeviceListCompletion)success
                                       failure:(ThingFailureError)failure;

/// Get condition device list in the scene with specify the current home id
///
/// @param homeId  The home ID.
/// @param success When success, return ThingSmartDeviceModel list.
/// @param failure When error occurred, return ThingFailureError.
- (void)getConditionDeviceListWithHomeId:(long long)homeId
                                 success:(ThingSceneGetDeviceListCompletion)success
                                 failure:(ThingFailureError)failure;

/// Get all device list and group list for action in the scene with specify the current home id.
///
/// @param homeId  The home ID.
/// @param success When success, return map object, including deviceList、groupList and extendsDictionary object.
/// @param failure When error occurred, return ThingFailureError.
- (void)getActionGroupListAndDeviceListWithHomeId:(long long)homeId
                                          success:(void(^)(NSDictionary *dict))success
                                          failure:(ThingFailureError)failure;

/// Get device list for recognize face condition type with specify current home id.
///
/// @param homeId  The home ID.
/// @param success When success, return ThingSmartDeviceModel list.
/// @param failure When error occurred, return ThingFailureError.
- (void)getFaceDeviceListWithHomeId:(long long)homeId
                            success:(ThingSceneGetDeviceListCompletion)success
                            failure:(ThingFailureError)failure;

/// Get device list for the member lock condition type with specify current home id.
///
/// @param homeId  The home ID.
/// @param success When success, return ThingSmartDeviceModel list for member lock condition.
/// @param failure When error occurred, return ThingFailureError.
- (void)getLockDeviceListWithHomeId:(long long)homeId
                            success:(ThingSceneGetDeviceListCompletion)success
                            failure:(ThingFailureError)failure;

// MARK: - Condition Item

/// Get all condition list for automation conditions with the specify temperature scale type, speed unit and homeId.
///
/// @param fahrenheit If YES, indicate the temperature unit is Fahrenheit, otherwise Celsius.
/// @param speedUnit  The speed unit description.
/// @param homeId     The current home ID.
/// @param success    When success, return map object, including envConditions and devConditions object.
/// @param failure    When error occurred, return ThingFailureError.
- (void)getAllConditionListWithFahrenheit:(BOOL)fahrenheit
                            windSpeedUnit:(NSString *)speedUnit
                                   homeId:(long long)homeId
                                  success:(void(^)(NSDictionary *dict))success
                                  failure:(ThingFailureError)failure;

/// Get all condition list for automation conditions with the specify temperature scale type, speed unit and homeId.
/// @param homeId The home ID.
/// @param params The request category list params, include fahrenheit, speedUnit, detail see `TSceneConditionCategoryListRequestParams` object.
/// @param success When success, return `ThingSmartSceneConditionCategoryListModel` object, including envConditions and devConditions object.
/// @param failure When error occurred, return ThingFailureError.
- (void)getConditionCategoryListWihtHomeId:(long long)homeId
                   conditionCategoryParams:(TSceneConditionCategoryListRequestParams *)params
                                   success:(void (^)(ThingSmartSceneConditionCategoryListModel *categoryListModel))success
                                   failure:(ThingFailureError)failure;

// MARK: - Data Points

/// Gets the dp list of status condition devices with specify current homeId and devId.
///
/// @param devId The device ID.
/// @param gid The home ID.
/// @param success When success, return `ThingSmartSceneDPModel` list.
/// @param failure When error occurred, return ThingFailureError object.
- (void)getStatusConditionDPListWithDevId:(NSString *)devId
                                      gid:(long long)gid
                                  success:(ThingSceneGetDPListCompletion)success
                                  failure:(ThingFailureError)failure;

/// Get device dp list for condition in the scene with specify the device id.
///
/// @param devId   The device ID.
/// @param success When success, return ThingSmartSceneDPModel list. The ThingSmartSceneDPModel object describes the datapoint data of the device.
/// @param failure When error occurred, return ThingFailureError.
- (void)getCondicationDeviceDPListWithDevId:(NSString *)devId
                                    success:(ThingSceneGetDPListCompletion)success
                                    failure:(ThingFailureError)failure;

/// Get device data point list for action in the scene with specify the device id.
///
/// @param devId   The device ID.
/// @param success When success, return ThingSmartSceneCoreFeatureModel list.
/// @param failure When error occurred, return ThingFailureError.
- (void)getNewActionDeviceDPListWithDevId:(NSString *)devId
                                  success:(ThingSceneGetFeatureListCompletion)success
                                  failure:(ThingFailureError)failure;

/// Get group datapoint list for action in the scene with specify the current group id.
///
/// @param groupId The group ID.
/// @param success When success, return ThingSmartSceneCoreFeatureModel list.
/// @param failure When error occurred, return ThingFailureError.
- (void)getNewActionGroupDPListWithGroupId:(NSString *)groupId
                                   success:(ThingSceneGetFeatureListCompletion)success
                                   failure:(ThingFailureError)failure;

// MARK: - City

/// Get city list with specify the current country code. If you are out of China, we suggest you use latitude and longitude to get the city information.
///
/// @param countryCode The country code.
/// @param success     When success, return ThingSmartCityModel list.
/// @param failure     When error occurred, return ThingFailureError.
- (void)getCityListWithCountryCode:(NSString *)countryCode
                           success:(ThingSceneGetCityListCompletion)success
                           failure:(ThingFailureError)failure;

/// Get city detail information with specify the latitude and longitude.
///
/// @param latitude  The latitude.
/// @param longitude The longitude.
/// @param success   When success, return ThingSmartCityModel list.
/// @param failure   When error occurred, return ThingFailureError.
- (void)getCityInfoWithLatitude:(NSString *)latitude
                      longitude:(NSString *)longitude
                        success:(ThingSceneGetCityInfoCompletion)success
                        failure:(ThingFailureError)failure;

/// Get city detail information with specify the city id.
///
/// @param cityId  The city ID.
/// @param success When success, return ThingSmartCityModel list.
/// @param failure When error occurred, return ThingFailureError.
- (void)getCityInfoWithCityId:(NSString *)cityId
                      success:(ThingSceneGetCityInfoCompletion)success
                      failure:(ThingFailureError)failure;

// MARK: - Log

/// Get all scene linkage logs, including reminder of successful or failed scene execution、push information and so on.
///
/// @param homeId         The home ID.
/// @param startTime      The start date.
/// @param endTime        The end date.
/// @param size           The number of items to be queried.
/// @param lastId         The id of the last query item.
/// @param lastRecordTime The record date of the last query item.
/// @param success        When success, return ThingSmartSceneLogModel list.
/// @param failure        When error occurred, return ThingFailureError.
- (void)getSmartSceneLogWithHomeId:(long long)homeId
                         startTime:(long long)startTime
                           endTime:(long long)endTime
                              size:(NSInteger)size
                            lastId:(NSString *)lastId
                    lastRecordTime:(long long)lastRecordTime
                           success:(ThingSceneLogCompletion)success
                           failure:(ThingFailureError)failure;

/// Get scene linkage log list of specified device.
///
/// @param devId          The device ID.
/// @param homeId         The home ID.
/// @param startTime      The start date.
/// @param endTime        The end date.
/// @param size           The number of items to be queried.
/// @param lastId         The id of the last query item.
/// @param lastRecordTime The record date of the last query item.
/// @param success        When success, return ThingSmartSceneLogModel list.
/// @param failure        When error occurred, return ThingFailureError.
- (void)getSmartSceneLogOfDeviceWithDevId:(NSString *)devId
                                   homeId:(long long)homeId
                                startTime:(long long)startTime
                                  endTime:(long long)endTime
                                     size:(NSInteger)size
                                   lastId:(NSString *)lastId
                           lastRecordTime:(long long)lastRecordTime
                                  success:(ThingSceneLogCompletion)success
                                  failure:(ThingFailureError)failure;

/// Get scene log detail information by the homeId, eventId, startTime, endTime, returnType.
///
/// @param homeId     The home ID.
/// @param eventId    The event ID.
/// @param startTime  The start date.
/// @param endTime    The end date.
/// @param returnType The return type. Return the all details when you pass the type equal 1, and return failure details when you pass the type equal 0.
/// @param success    When success, return ThingSmartSceneLogDetailModel list.
/// @param failure    When error occurred, return ThingFailureError.
- (void)getSmartSceneLogDetailWithHomeId:(long long)homeId
                                 eventId:(NSString *)eventId
                               startTime:(long long)startTime
                                 endTime:(long long)endTime
                              returnType:(long long)returnType
                                 success:(ThingSceneLogDetailListCompletion)success
                                 failure:(ThingFailureError)failure;

/// Check the user has new logs under the current home.
/// @param homeId The home ID.
/// @param success Success callback. Return YES if the user has new logs under current home, otherwise NO.
/// @param failure Failure callback. Return error When the home ID is invalid.
- (void)hasNewLogsWithHomeId:(long long)homeId success:(nullable ThingSuccessBOOL)success failure:(nullable ThingFailureError)failure;

// MARK: - Room

/// Remove scenes in the specified room.
/// @param roomId The room id.
/// @param sceneIds The scene id list, eg: "id1,id2,id3"
/// @param success Success callback.
/// @param failure Failure callback.
- (void)removeSceneWithHomeId:(long long)homeId
                       roomId:(NSString *)roomId
                     sceneIds:(NSString *)sceneIds
                      success:(ThingSuccessBOOL)success
                      failure:(ThingFailureError)failure;

/// Sort scenes in the specified room.
/// @param roomId The room id.
/// @param sceneIds The scene id list, eg: "id1,id2,id3"
/// @param success Success callback.
/// @param failure Failure callback.
- (void)sortSceneWithHomeId:(long long)homeId
                       room:(NSString *)roomId
                   sceneIds:(NSString *)sceneIds
                    success:(ThingSuccessBOOL)success
                    failure:(ThingFailureError)failure;

/// Batch save scenes in specified rooms.
/// @param gid The home id.
/// @param ruleIds The scene id list.
/// @param roomIds The room id list.
/// @param success Success callback.
/// @param failure Failure callback.
- (void)batchSaveSceneInRoomsWithGid:(long long)gid
                             ruleIds:(NSArray<NSString *> *)ruleIds
                             roomIds:(NSArray<NSString *> *)roomIds
                             success:(ThingSuccessBOOL)success
                             failure:(ThingFailureError)failure;

// MARK: - Top Recommend

/// Get top recommend scene list with the specify homeId.
///
/// @param homeId  The home ID.
/// @param success When success, return ThingSmartSceneModel list.
/// @param failure When error occurred, return ThingFailureError.
- (void)getTopRecommendedSceneListWithHomeId:(long long)homeId
                                     success:(void(^)(NSArray<ThingSmartSceneModel *> *list))success
                                     failure:(ThingFailureError)failure;

/// Delete a home recommended scene.
///
/// @param homeId              The home id.
/// @param recommendId   The top recommend scene id.
/// @param success            When success return id object.
/// @param failure            When failure return ThingFailureError.
- (void)removeTopRecommendSceneWithHomeId:(long long)homeId
                              recommendId:(NSString *)recommendId
                                  success:(ThingSuccessID)success
                                  failure:(ThingFailureError)failure;

// MARK: - Recommend List

/// Get recommend scene list.
/// @param homeId Home ID.
/// @param params The request params object, detail see `TSceneRecomListParams`
/// @param success The success callback.
/// @param failure The failure callback.
- (void)getRecomSceneList:(long long)homeId
           recomListParam:(TSceneRecomListParams *)params
                  success:(void(^)(NSArray<ThingSmartSceneModel *> *list))success
                  failure:(ThingFailureError)failure;

/// Return the corresponding recommended scene dictionary according to the device id list.
/// @param deviceIDs The device IDs array.
/// @param homeId The home ID.
/// @param success The success callback.
/// @param failure The failure callback.
- (void)fetchRecommendListForDeviceIDs:(NSArray<NSString *> *)deviceIDs
                                homeId:(long long)homeId
                               success:(void (^)(NSDictionary<NSString *,ThingSmartSceneModel *> *dict))success
                               failure:(ThingFailureError)failure;

/// Get recommend scene list with the specify homeId and deviceId.
/// @param homeId The home ID.
/// @param deviceId The device ID.
/// @param count The request count.
/// @param success When success, return ThingSmartSceneModel list.
/// @param failure When error occurred, return ThingFailureError.
- (void)getRecommendedSceneListWithHomeId:(long long)homeId
                                 deviceId:(NSString *)deviceId
                                    count:(NSInteger)count
                                  success:(void(^)(NSArray<ThingSmartSceneModel *> *list))success
                                  failure:(ThingFailureError)failure;

// MARK: - Recommend Detail

/// Request recommended scene details based on recommended scene id.
/// @param sceneId scene id
/// @param homeId home id
/// @param success Success callback.
/// @param failure Failure callback.
- (void)getRecommendSceneDetailWithSceneId:(NSString *)sceneId
                                    homeId:(long long)homeId
                                   success:(void (^)(ThingSmartSceneModel *sceneModel))success
                                   failure:(ThingFailureError)failure;

/// Unlike the recommend scene.
/// @param homeId The home ID.
/// @param params The unlike request params. Detail see `TSceneRecomHandleParams`.
/// @param success The success callback.
/// @param failure The failure callback.
- (void)unlikeRecommend:(long long)homeId
      recomHandleParams:(TSceneRecomHandleParams *)params
                success:(ThingSuccessBOOL)success
                failure:(ThingFailureError)failure;

/// Return the cached device recommended scene list
/// @param homeId home id
- (NSDictionary<NSString *, ThingSmartSceneModel *> *)getCacheRecommendDeviceListWithHomeId:(long long)homeId;

// MARK: - Sort

/// Sort the scene list by the current home id.
///
/// @param homeId      The home ID.
/// @param sceneIdList The scene list that to be sorted.
/// @param success     When success, return ThingSuccessHandler.
/// @param failure     When error occurred, return ThingFailureError.
- (void)sortSceneWithHomeId:(long long)homeId
                sceneIdList:(NSArray<NSString *> *)sceneIdList
                    success:(ThingSuccessHandler)success
                    failure:(ThingFailureError)failure;

// MARK: - Other

/// Determine whether to display security actions based on the AppId
/// @param success When success, return YES if the App should show security action item, otherwise NO.
/// @param failure When error occurred, return NSError object.
- (void)getSceneSecurityActionSwitch:(ThingSuccessBOOL)success
                             failure:(ThingFailureError)failure;

/// Get scene background icons URL list.
///
/// @param success When success, return URL list.
/// @param failure When error occurred, return ThingFailureError.
- (void)getSmartSceneBackgroundCoverWithsuccess:(ThingSuccessList)success
                                        failure:(ThingFailureError)failure;

/// Get scene custom style resource list, including color、icon and background. The return result map object, contain coverColors、coverIconList and coverPics.
///
/// @param success When success, return map object, including coverColors、coverIconList and coverPics object.
/// @param failure When error occurred, return ThingFailureError.
- (void)getSmartSceneCustomStyleListWithSuccess:(ThingSuccessDict)success
                                        failure:(ThingFailureError)failure;

/// Get a scenes list of other types, such as lighting, community, real estate.
/// @param homeId The home ID.
/// @param success When success, return ThingSmartSceneBizEntryModel list.s
/// @param failure When error occurred, return error.
- (void)getSceneBizEntryListWithHomeId:(NSString *)homeId
                               success:(ThingSuccessList)success
                               failure:(ThingFailureError)failure;

// MARK: - Handle

/// clean scene caches
- (void)cleanSceneCache;

/// Remove all geofence registered in the apple system for automation scene when user logout.
- (void)removeAllGeoFence;

/// Cancel the request being executed.
- (void)cancelRequest;

- (void)replaceConidtionData:(NSArray *)conditions;

- (void)replaceActionData:(NSArray *)actions;

- (void)replaceGroupData:(NSArray *)groups;

- (void)sceneListWithHomeID:(long long)homeID completion:(void (^)(NSArray<ThingSmartSceneModel *> *list))completion;


// MARK: - Recommend(Deprecated)

/// Get more recommended scenes, use cache
/// @param homeId The home ID
/// @param successHandler When successfully update recommended scenes, this block will be called and return id object.
/// @param failureError When error occurred, this block will be called and return ThingFailureError.
- (void)updateMatchingRecommendWithHomeId:(long long)homeId
                                  success:(ThingSuccessID)successHandler
                                  failure:(ThingFailureError)failureError;

/// Get more recommended scenes, cache less
/// @param homeId The home ID
/// @param successHandler When successfully update recommended scenes, this block will be called and return id object.
/// @param failureError When error occurred, this block will be called and return ThingFailureError.
- (void)updateMatchingDialogRecommendWithHomeId:(long long)homeId
                                        success:(ThingSuccessID)successHandler
                                        failure:(ThingFailureError)failureError;

/// Get recommend scene list with the specify homeId.
///
/// @param homeId  The home ID.
/// @param success When success, return ThingSmartSceneModel list.
/// @param failure When error occurred, return ThingFailureError.
- (void)getRecommendedSceneListWithHomeId:(long long)homeId
                                  success:(void(^)(NSArray<ThingSmartSceneModel *> *list))success
                                  failure:(ThingFailureError)failure;

/// Get collection scene list with the specify homeId.
///
/// @param homeId  The home ID.
/// @param success When success, return ThingSmartSceneModel list.
/// @param failure When error occurred, return ThingFailureError.
- (void)getCollectionSceneListWithHomeId:(long long)homeId
                                 success:(ThingSuccessList)success
                                 failure:(ThingFailureError)failure;

/// Return the corresponding recommended scene dictionary according to the device id list.
/// @param devIds deviceId list
/// @param homeId home id
/// @param success Success callback.
/// @param failure Failure callback.
- (void)getRecommendDeviceListWithDevIds:(NSArray<NSString *> *)devIds
                                  homeId:(long long)homeId
                                 success:(void (^)(NSDictionary<NSString *,ThingSmartSceneModel *> *dict))success
                                 failure:(ThingFailureError)failure;

// MARK: - Deprecated

/// Get a list of scenes, including tap-to-run and automation. We can judge tap-to-run and automation scene by the entityType of conditions property in ThingSmartSceneModel, The scene is tap-to-run when the entityType equal AutoTypeManual, otherwise it's automation.
///
/// @see For more information about the entityType, you can see ThingSmartSceneConditionModel class.
///
/// @param homeId  The current home ID.
/// @param success When successfully get the scene list, this block will be called and return ThingSmartSceneModel list.
/// @param failure When error occurred, this block will be called and return ThingFailureError.
- (void)getSceneListWithHomeId:(long long)homeId
                       success:(void(^)(NSArray<ThingSmartSceneModel *> *list))success
                       failure:(ThingFailureError)failure __deprecated_msg("This method is deprecated, Use -getSimpleSceneListWithHomeId:success:failure instead");

/// Get a weather condition list for automation conditions with the specify temperature scale type. If Fahrenheit is YES, indicates that the temperature unit you use is Fahrenheit, otherwise you use is Celsius.
///
/// @param fahrenheit If YES, indicate the temperature unit is Fahrenheit, otherwise Celsius.
/// @param success    When success, return ThingSmartSceneDPModel list.
/// @param failure    When error occurred, return ThingFailureError.
///
/// @deprecated This method is deprecated, Use getAllConditionListWithFahrenheit:windSpeedUnit:homeId:success:failure instead.
- (void)getConditionListWithFahrenheit:(BOOL)fahrenheit
                               success:(void(^)(NSArray<ThingSmartSceneDPModel *> *list))success
                               failure:(ThingFailureError)failure __deprecated_msg("This method is deprecated, Use -getAllConditionListWithFahrenheit:windSpeedUnit:homeId:success:failure instead");

/// Get all condition list for automation conditions, including weather condition、device condition and so on.
///
/// @param fahrenheit If YES, indicate the temperature unit is Fahrenheit, otherwise Celsius.
/// @param homeId     The current home ID.
/// @param success    When success, return map object, including envConditions and devConditions object.
/// @param failure    When error occurred, return ThingFailureError.
///
/// @deprecated This method is deprecated, Use getAllConditionListWithFahrenheit:windSpeedUnit:homeId:success:failure instead.
- (void)getAllConditionListWithFahrenheit:(BOOL)fahrenheit
                                   homeId:(long long)homeId
                                  success:(void(^)(NSDictionary *dict))success
                                  failure:(ThingFailureError)failure __deprecated_msg("This method is deprecated, Use -getAllConditionListWithFahrenheit:windSpeedUnit:homeId:success:failure instead");

/// Get device data point list for action in the scene with specify the device id.
///
/// @param devId   The device ID.
/// @param success When success, return ThingSmartSceneDPModel list.
/// @param failure When error occurred, return ThingFailureError.
- (void)getActionDeviceDPListWithDevId:(NSString *)devId
                               success:(void(^)(NSArray<ThingSmartSceneDPModel *> *list))success
                               failure:(ThingFailureError)failure __deprecated_msg("This method is deprecated, Use -getNewActionDeviceDPListWithDevId:success:failure: instead");

/// Get group datapoint list for action in the scene with specify the current group id.
///
/// @param groupId The group ID.
/// @param success When success, return ThingSmartSceneDPModel list.
/// @param failure When error occurred, return ThingFailureError.
- (void)getActionGroupDPListWithGroupId:(NSString *)groupId
                                success:(void(^)(NSArray<ThingSmartSceneDPModel *> *list))success
                                failure:(ThingFailureError)failure __deprecated_msg("This method is deprecated, Use -getNewActionGroupDPListWithGroupId:success:failure: instead");

/// Batch delete scenes.
/// @param params @{"ruleIds" : "id1,id2,id3"}.
/// @param commons Common params.
/// @param success Success callback.
/// @param failure Failure callback.
- (void)deleteBatchSmartScenesWithParams:(NSDictionary *)params
                            commonParams:(NSDictionary *)commons
                                 success:(ThingSuccessHandler)success
                                 failure:(ThingFailureError)failure __deprecated_msg("This method is deprecated, Use -batchDeleteScenesWithSceneIds:homeId:success:failure: instead");

/// Get action device list in the scene with specify the current home id.
///
/// @param homeId  The current home ID.
/// @param success When success, return ThingSmartDeviceModel list.
/// @param failure When error occurred, return ThingFailureError.
- (void)getActionDeviceListWithHomeId:(long long)homeId
                              success:(void(^)(NSArray<ThingSmartDeviceModel *> *list))success
                              failure:(ThingFailureError)failure __deprecated_msg("This method is deprecated, Use -getActionGroupListAndDeviceListWithHomeId:success:failure instead");
@end
