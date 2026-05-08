//
//  ThingSmartScenePreConditionFactory.h
//  ThingSmartSceneKit
//
//  Copyright (c) 2014-2021 Thing Inc. (https://developer.thing.com)
//

#import <Foundation/Foundation.h>
#import "ThingSmartSceneCoreKit.h"

@class TSmartScenePreconditionParam;

NS_ASSUME_NONNULL_BEGIN

/// @brief ThingSmartScenePreConditionFactory provides convenient construction methods for developers to generate precondition object.
@interface ThingSmartScenePreConditionFactory : NSObject

/// Create an all-day valid precondition.
///
/// @param sceneId The scene id. You can pass nil when create an automation scene.
/// @param conditionId The current condition id. You need to pass the original condition id when editing scene for automation scene.
/// @param loops The loop description, the data format is "1111111". Each bit indicates the Sunday to Saturday, 1 means valid, 0 means invalid.
/// @param timeZoneId The timezone id, eg:"Asia/Shanghai".
///
/// @return The ThingSmartScenePreConditionModel instance.
+ (ThingSmartScenePreConditionModel *)creatAllDayPreConditionWithSceneId:(nullable NSString *)sceneId
                                                        existConditionId:(nullable NSString *)conditionId
                                                                   loops:(NSString *)loops
                                                              timeZoneId:(NSString *)timeZoneId;

/// Create a daytime valid precondition.
/// 
/// @param sceneId The scene id. You can pass nil when create an automation scene.
/// @param conditionId The current condition id. You need to pass the original condition id when editing scene for automation scene.
/// @param loops The loop description, the data format is "1111111". Each bit indicates the Sunday to Saturday, 1 means valid, 0 means invalid.
/// @param cityId The current city id.
/// @param cityName The current city name.
/// @param timeZoneId The timezone id, eg:"Asia/Shanghai".
///
/// @return The ThingSmartScenePreConditionModel instance.
+ (ThingSmartScenePreConditionModel *)createDayTimePreConditionWithSceneId:(nullable NSString *)sceneId
                                                          existConditionId:(nullable NSString *)conditionId
                                                                     loops:(NSString *)loops
                                                                    cityId:(NSString *)cityId
                                                                  cityName:(NSString *)cityName
                                                                timeZoneId:(NSString *)timeZoneId;

/// Create a night valid precondition.
///
/// @param sceneId The scene id. You can pass nil when create an automation scene.
/// @param conditionId The current condition id. You need to pass the original condition id when editing scene for automation scene.
/// @param loops The loop description, the data format is "1111111". Each bit indicates the Sunday to Saturday, 1 means valid, 0 means invalid.
/// @param cityId The current city id.
/// @param cityName The current city name.
/// @param timeZoneId The timezone id, eg:"Asia/Shanghai".
///
/// @return The ThingSmartScenePreConditionModel instance.
+ (ThingSmartScenePreConditionModel *)createNightTimePreConditionWithSceneId:(nullable NSString *)sceneId
                                                            existConditionId:(nullable NSString *)conditionId
                                                                       loops:(NSString *)loops
                                                                      cityId:(NSString *)cityId
                                                                    cityName:(NSString *)cityName
                                                                  timeZoneId:(NSString *)timeZoneId;

/// Create a valid precondition of custom time period.
///
/// @param sceneId The scene id. You can pass nil when create an automation scene.
/// @param conditionId The current condition id. You need to pass the original condition id when editing scene for automation scene.
/// @param loops The loop description, the data format is "1111111". Each bit indicates the Sunday to Saturday, 1 means valid, 0 means invalid.
/// @param cityId The current city id.
/// @param cityName The current city name.
/// @param timeZoneId The timezone id, eg:"Asia/Shanghai".
/// @param begin The begin date. eg:"00:59".
/// @param end The end date. eg:"18:30".
///
/// @return The ThingSmartScenePreConditionModel instance.
+ (ThingSmartScenePreConditionModel *)createCustomTimePreConditionWithSceneId:(nullable NSString *)sceneId
                                                             existConditionId:(nullable NSString *)conditionId
                                                                        loops:(NSString *)loops
                                                                       cityId:(NSString *)cityId
                                                                     cityName:(NSString *)cityName
                                                                   timeZoneId:(NSString *)timeZoneId
                                                                    beginTime:(NSString *)begin
                                                                      endTime:(NSString *)end;

/// Create a precondition model for scene.
/// @param preconditionParam The parameters for precondition, detail see `TSmartScenePreconditionParam`.
///
/// @retuen The `ThingSmartScenePreConditionModel` object.
+ (ThingSmartScenePreConditionModel *)scenePreconditionWithParam:(TSmartScenePreconditionParam *)preconditionParam;

@end

NS_ASSUME_NONNULL_END

