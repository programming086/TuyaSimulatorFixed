//
//  ThingSmartScene.h
//  ThingSmartSceneKit
//
//  Copyright (c) 2014-2021 Thing Inc. (https://developer.thing.com)

#import <ThingSmartUtil/ThingSmartUtil.h>
#import "ThingSmartSceneModel.h"
#import "ThingSmartSceneActionModel.h"
#import "ThingSmartSceneConditionModel.h"
#import "TSceneDefined.h"
#import "TSceneRequestInfo.h"

/// @brief ThingSmartScene is used to add, edit delete and execute scenes. 
@interface ThingSmartScene : NSObject

/// Class method for initialize ThingSmartScene by ThingSmartSceneModel.
///
/// @param sceneModel scene model.
/// @return instance of ThingSmartScene.
+ (instancetype)sceneWithSceneModel:(ThingSmartSceneModel *)sceneModel;

/// Instance method for initialize ThingSmartScene by ThingSmartSceneModel.
///
/// @param sceneModel scene model.
/// @return instance of ThingSmartScene.
- (instancetype)initWithSceneModel:(ThingSmartSceneModel *)sceneModel;

/// Don't initialize an instance with init method.
///
/// @return This method will return an unavailable instance.
- (instancetype)init NS_UNAVAILABLE;

// MARK: - Scene Base

/// Add a scene by all param
///
/// @param name               The scene name.
/// @param homeId             The home id.
/// @param background         The background image url.
/// @param showFirstPage      Show the scene in index page or not.
/// @param preConditionList   preconditions, like valid time period.
/// @param conditionList      Condition list.
/// @param actionList         Action list.
/// @param matchType          Match all conditions/any condition will execute the automation.
/// @param success            When success return ThingSmartSceneModel.
/// @param failure            When failure return ThingFailureError.
+ (void)addNewSceneWithName:(NSString *)name
                     homeId:(long long)homeId
                 background:(NSString *)background
              showFirstPage:(BOOL)showFirstPage
           preConditionList:(NSArray<ThingSmartScenePreConditionModel*> *)preConditionList
              conditionList:(NSArray<ThingSmartSceneConditionModel*> *)conditionList
                 actionList:(NSArray<ThingSmartSceneActionModel*> *)actionList
                  matchType:(ThingSmartConditionMatchType)matchType
                    success:(void (^)(ThingSmartSceneModel *sceneModel))success
                    failure:(ThingFailureError)failure;

/// Add a new scene.Use a sceneModel with complete information of a scene.
///
/// @param sceneModel     ThingSmartSceneModel
/// @param homeId         The home id.
/// @param success        When success return ThingSmartSceneModel.
/// @param failure        When failure return ThingFailureError.
+ (void)addNewSceneWithSceneModel:(ThingSmartSceneModel *)sceneModel
                           homeId:(long long)homeId
                          success:(void (^)(ThingSmartSceneModel *sceneModel))success
                          failure:(ThingFailureError)failure;

/// Add a new scene. Use a sceneModel with complete information of a scene. Setting needCleanGidSid at will may cause scene control to become invalid.
///
/// @param sceneModel         ThingSmartSceneModel
/// @param needCleanGidSid    The flag means need to clean sid and gid in scene extraProperty.
/// @param homeId             The home id.
/// @param success            When success return ThingSmartSceneModel.
/// @param failure            When failure return ThingFailureError.
+ (void)addNewSceneWithSceneModel:(ThingSmartSceneModel *)sceneModel
                  needCleanGidSid:(BOOL)needCleanGidSid
                           homeId:(long long)homeId
                          success:(void (^)(ThingSmartSceneModel *sceneModel))success
                          failure:(ThingFailureError)failure;

/// Add a scene.
/// @param sceneInfo The added scene attributes.
/// @param homeID The home ID.
/// @param success When success, return `ThingSmartSceneModel` object.
/// @param failure When error occurred, return error.
+ (void)addScene:(TSceneRequestInfo *)sceneInfo
          homeID:(long long)homeID
         success:(ThingSceneGetModelCompletion)success
         failure:(ThingFailureError)failure;

/// Edit a existed scene with all param
///
/// @param name               The scene name.
/// @param background         The background image url.
/// @param showFirstPage      Show the scene in index page or not.
/// @param preConditionList   preconditions, like valid time period.
/// @param conditionList      Condition list.
/// @param actionList         Action list.
/// @param matchType          Match all conditions/any condition will execute the automation.
/// @param success            When success return ThingSuccessHandler.
/// @param failure            When failure return ThingFailureError.
- (void)modifySceneWithName:(NSString *)name
                 background:(NSString *)background
              showFirstPage:(BOOL)showFirstPage
           preConditionList:(NSArray<ThingSmartScenePreConditionModel*> *)preConditionList
              conditionList:(NSArray<ThingSmartSceneConditionModel*> *)conditionList
                 actionList:(NSArray<ThingSmartSceneActionModel*> *)actionList
                  matchType:(ThingSmartConditionMatchType)matchType
                    success:(ThingSuccessHandler)success
                    failure:(ThingFailureError)failure;

/// Edit a existed scene.Use a sceneModel with complete information of a scene.
///
/// @param sceneModel   ThingSmartSceneModel
/// @param success      When success return ThingSuccessHandler.
/// @param failure      When failure return ThingFailureError.
- (void)modifySceneWithSceneModel:(ThingSmartSceneModel *)sceneModel
                          success:(ThingSuccessHandler)success
                          failure:(ThingFailureError)failure;

/// Edit a existed scene.Use a sceneModel with complete information of a scene.
/// This method is not recommended for saving scenes. Setting needCleanGidSid at will may cause scene control to become invalid.
///
/// @param sceneModel       ThingSmartSceneModel
/// @param needCleanGidSid  needCleanGidSid
/// @param success          When success return ThingSuccessHandler.
/// @param failure          When failure return ThingFailureError.
- (void)modifySceneWithSceneModel:(ThingSmartSceneModel *)sceneModel
                  needCleanGidSid:(BOOL)needCleanGidSid
                          success:(ThingSuccessHandler)success
                          failure:(ThingFailureError)failure;

/// Edit a existed scene. Use a sceneModel with complete information of a scene.
/// This method is not recommended for saving scenes. Setting needCleanGidSid at will may cause scene control to become invalid.
///
/// @param sceneModel       ThingSmartSceneModel
/// @param needCleanGidSid  needCleanGidSid
/// @param success          When success return ThingSmartSceneModel.
/// @param failure          When failure return ThingFailureError.
- (void)editSceneWithSceneModel:(ThingSmartSceneModel *)sceneModel
                needCleanGidSid:(BOOL)needCleanGidSid
                        success:(void (^)(ThingSmartSceneModel *sceneModel))success
                        failure:(ThingFailureError)failure;


/// Edit a existed scene. Use a scene infomation with complete information of a scene.
/// This method is not recommended for saving scenes. 
/// @param sceneInfo The edited scene attributes.
/// @param success When success, return `ThingSmartSceneModel` object.
/// @param failure When error occurred, return error.
- (void)editScene:(TSceneRequestInfo *)sceneInfo
          success:(ThingSceneGetModelCompletion)success
          failure:(ThingFailureError)failure;

/// Delete a existed scene.
/// @param homeId   current homeId
/// @param success  When success return ThingSuccessBOOL.
/// @param failure  When failure return ThingFailureError.
- (void)deleteSceneWithHomeId:(long long)homeId
                      success:(ThingSuccessBOOL)success
                      failure:(ThingFailureError)failure;

/// Execute a scene.
///
/// @param success            When success return ThingSuccessHandler.
/// @param failure            When failure return ThingFailureError.
- (void)executeSceneWithSuccess:(ThingSuccessHandler)success
                        failure:(ThingFailureError)failure;

/// Disable an automation, which will not executed automatically.
///
/// @param success            When success return ThingSuccessHandler.
/// @param failure            When failure return ThingFailureError.
- (void)disableSceneWithSuccess:(ThingSuccessHandler)success
                        failure:(ThingFailureError)failure;

/// Enable an automation, which will be executed while the conditions are matched.
///
/// @param success            When success return ThingSuccessHandler.
/// @param failure            When failure return ThingFailureError.
- (void)enableSceneWithSuccess:(ThingSuccessHandler)success
                       failure:(ThingFailureError)failure;

// MARK: - Recommend

/// Execute a recommended scene.
///
/// @param homeId              The home id.
/// @param success            When success return ThingSuccessHandler.
/// @param failure            When failure return ThingFailureError.
- (void)triggerRecommendSceneWithHomeId:(long long)homeId
                                success:(ThingSuccessHandler)success
                                failure:(ThingFailureError)failure;

/// Delete a recommended scene.
///
/// @param homeId              The home id.
/// @param success            When success return ThingSuccessHandler.
/// @param failure            When failure return ThingFailureError.
- (void)removeRecommendSceneWithHomeId:(long long)homeId
                               success:(ThingSuccessHandler)success
                               failure:(ThingFailureError)failure;

/// Save a recommended scene, this scene can be modified by user. this scene will become a normal scene after save successfully, and the recommended scene will not show anymore.
///
/// @param homeId              The home id.
/// @param success            When success return ThingSuccessHandler.
/// @param failure            When failure return ThingFailureError.
- (void)saveRecommendSceneWithHomeId:(long long)homeId
                             success:(void (^)(ThingSmartSceneModel *sceneModel))success
                             failure:(ThingFailureError)failure;

// MARK: - Other

/// Cancel the request being executed.
- (void)cancelRequest;

// MARK: - Deprecated

/// Delete a existed scene.
///
/// @param success            When success return ThingSuccessHandler.
/// @param failure            When failure return ThingFailureError.
- (void)deleteSceneWithSuccess:(ThingSuccessHandler)success
                       failure:(ThingFailureError)failure __deprecated_msg("This method is deprecated, Use -[ThingSmartScene deleteSceneWithHomeId:success:failure:] instead");

/// Add a scene by all param, (deprecated).
///
/// @param name               The scene name.
/// @param homeId            The home id.
/// @param background        The background image url.
/// @param showFirstPage      Show the scene in index page or not.
/// @param conditionList      Condition list.
/// @param actionList         Action list.
/// @param matchType          Match all conditions/any condition will execute the automation.
/// @param success            When success return ThingSmartSceneModel.
/// @param failure            When failure return ThingFailureError.
///
/// @deprecated This method is deprecated, Use -[ThingSmartScene addNewSceneWithName:homeId:background:showFirstPage:preConditionList:conditionList:actionList:matchType:success:failure:] instead
+ (void)addNewSceneWithName:(NSString *)name
                     homeId:(long long)homeId
                 background:(NSString *)background
              showFirstPage:(BOOL)showFirstPage
              conditionList:(NSArray<ThingSmartSceneConditionModel*> *)conditionList
                 actionList:(NSArray<ThingSmartSceneActionModel*> *)actionList
                  matchType:(ThingSmartConditionMatchType)matchType
                    success:(void (^)(ThingSmartSceneModel *sceneModel))success
                    failure:(ThingFailureError)failure __deprecated_msg("This method is deprecated, Use -[ThingSmartScene addNewSceneWithName:homeId:background:showFirstPage:preConditionList:conditionList:actionList:matchType:success:failure:] instead");

/// Edit an existed scene with all param, (deprecated).
///
/// @param name               The scene name.
/// @param background        The background image url.
/// @param showFirstPage      Show the scene in index page or not.
/// @param conditionList      Condition list.
/// @param actionList         Action list.
/// @param matchType          Match all conditions/any condition will execute the automation.
/// @param success            When success return ThingSuccessHandler.
/// @param failure            When failure return ThingFailureError.
///
/// @deprecated This method is deprecated, Use -[ThingSmartScene modifySceneWithName:background:showFirstPage:preConditionList:conditionList:actionList:matchType:success:failure:] instead.
- (void)modifySceneWithName:(NSString *)name
                 background:(NSString *)background
              showFirstPage:(BOOL)showFirstPage
              conditionList:(NSArray<ThingSmartSceneConditionModel*> *)conditionList
                 actionList:(NSArray<ThingSmartSceneActionModel*> *)actionList
                  matchType:(ThingSmartConditionMatchType)matchType
                    success:(ThingSuccessHandler)success
                    failure:(ThingFailureError)failure __deprecated_msg("This method is deprecated, Use -[ThingSmartScene modifySceneWithName:background:showFirstPage:preConditionList:conditionList:actionList:matchType:success:failure:] instead");
@end
