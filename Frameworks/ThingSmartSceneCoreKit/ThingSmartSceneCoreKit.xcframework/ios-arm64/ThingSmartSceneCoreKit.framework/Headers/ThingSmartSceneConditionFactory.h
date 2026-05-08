//
//  ThingSmartSceneConditionFactory.h
//  ThingSmartSceneKit
//
//  Copyright (c) 2014-2021 Thing Inc. (https://developer.thing.com)

#import <Foundation/Foundation.h>
#import "ThingSmartSceneCoreKit.h"
#import "ThingSmartSceneExprModel.h"


/// @brief A factory design mode for create ThingSmartSceneConditionModel.
///
/// @note In order to facilitate the handling of multiple languages, this class does not handle the actionDisplay and actionDisplayNew fields of the ThingSmartSceneConditionModel.
@interface ThingSmartSceneConditionFactory : NSObject

/// Create a device condition.
///
/// @param device The device model to create condition.
/// @param dpModel The dpModel to create condition.
/// @param exprModel Create with ThingSmartSceneConditionExprBuilder.
///
/// @return ThingSmartSceneConditionModel object.
+ (ThingSmartSceneConditionModel *)createDeviceConditionWithDevice:(ThingSmartDeviceModel *)device
                                                           dpModel:(ThingSmartSceneDPModel *)dpModel
                                                         exprModel:(ThingSmartSceneExprModel *)exprModel;

/// Create a timed type of human sensor condition, such as no movement for five minutes. Common human sensor conditions use -createDeviceConditionWithDevice:dpModel:exprModel:.
///
/// @param device The device model to create condition.
/// @param dpModel The dpModel to create condition.
/// @param exprModel Create with ThingSmartSceneConditionExprBuilder.
///
/// @return ThingSmartSceneConditionModel object.
+ (ThingSmartSceneConditionModel *)createPirConditionWithDevice:(ThingSmartDeviceModel *)device
                                                        dpModel:(ThingSmartSceneDPModel *)dpModel
                                                      exprModel:(ThingSmartSceneExprModel *)exprModel;

/// Create an whether condition.
///
/// @param city Whether condition need a city.
/// @param dpModel The dpModel to create condition.
/// @param exprModel Create with ThingSmartSceneConditionExprBuilder.
///
/// @return ThingSmartSceneConditionModel object.
+ (ThingSmartSceneConditionModel *)createWhetherConditionWithCity:(ThingSmartCityModel *)city
                                                          dpModel:(ThingSmartSceneDPModel *)dpModel
                                                        exprModel:(ThingSmartSceneExprModel *)exprModel;

/// Create a timer condition.
///
/// @param exprModel Create with ThingSmartSceneConditionExprBuilder.
///
/// @return ThingSmartSceneConditionModel object.
+ (ThingSmartSceneConditionModel *)createTimerConditionWithExprModel:(ThingSmartSceneExprModel *)exprModel;

/// Create a timer condition related to sunrise and sunset times
///
/// @param city City to be operated.
/// @param exprModel Create with ThingSmartSceneConditionExprBuilder.
///
/// @return ThingSmartSceneConditionModel object.
+ (ThingSmartSceneConditionModel *)createSunsetriseTimerConditionWithCity:(ThingSmartCityModel *)city
                                                                ExprModel:(ThingSmartSceneExprModel *)exprModel;

/// Create a GeoFence conditon,conditionModel's entityId will be assigned after scene saved, the entityId represent the geoFence id, will should be upload to server by http API to trigger the automation.
///
/// @param type The GeoFenceType, reach or leave the place.
/// @param latitude  The geo fence center latitude.
/// @param longitude The geo fence center longitude.
/// @param radius Consider latitude and longitude as the center of a circle, this property represent the radius.
/// @param geoTitle The location name.
///
/// @return ThingSmartSceneConditionModel object.
+ (ThingSmartSceneConditionModel *)createGeoFenceConditionWithGeoType:(GeoFenceType)type
                                                              geoLati:(CGFloat)latitude
                                                             geoLonti:(CGFloat)longitude
                                                            geoRadius:(CGFloat)radius
                                                             geoTitle:(NSString *)geoTitle;

/// Create an "manual execute" condition.This condition should not be saved to cloud server, when you call the API to save a smart, you should delete this type of condition first.
///
/// @return ThingSmartSceneConditionModel object.
+ (ThingSmartSceneConditionModel *)createManualExecuteCondition;

/**
 Create a duration for device's data point condition.
 
 @param deviceModel The device model to create condition.
 @param dpModel The dpModel to create condition.
 @param exprModel Create with ThingSmartSceneConditionExprBuilder.
 @param durationTime The durtion, unit is s.
 
 @return ThingSmartSceneConditionModel object.
 */
+ (ThingSmartSceneConditionModel *)calculateConditionWithDeviceModel:(ThingSmartDeviceModel *)deviceModel
                                                             dpModel:(ThingSmartSceneDPModel *)dpModel
                                                           exprModel:(ThingSmartSceneExprModel *)exprModel
                                                        durationTime:(NSTimeInterval)durationTime;

/**
 Create member going home condition.
 
 @param devId The device ID.
 @param entitySubIds The entity sub IDs.
 @param memberIds The member IDs string, each data is separated by commas.
 @param memberNames The member names string, each data is separated by commas.
 
 @return ThingSmartSceneConditionModel object.
 */
+ (ThingSmartSceneConditionModel *)memberBackHomeConditionWithDevId:(NSString *)devId
                                                       entitySubIds:(NSString *)entitySubIds
                                                          memberIds:(NSString *)memberIds
                                                        memberNames:(NSString *)memberNames;
@end

