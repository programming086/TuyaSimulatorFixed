//
//  ThingSmartSceneConditionExprBuilder.h
//  ThingSmartSceneKit
//
//  Copyright (c) 2014-2021 Thing Inc. (https://developer.thing.com)

#import <Foundation/Foundation.h>
#import "ThingSmartSceneExprModel.h"
#import "TSmartSceneConditionTypes.h"

NS_ASSUME_NONNULL_BEGIN

/// @brief Create ThingSmartSceneExprModel by difference type values.
@interface ThingSmartSceneConditionExprBuilder : NSObject

/// Create a exprModel with bool value and condition type.
///
/// @param type Whether type or device's dpId.
/// @param isTrue BOOL value
/// @param exprType To distinguish the entity type.
/// 
/// @return A ThingSmartSceneExprModel object.
+ (ThingSmartSceneExprModel *)createBoolExprWithType:(NSString *)type
                                              isTrue:(BOOL)isTrue
                                            exprType:(ExprType)exprType;

/// Create a exprModel with enum string value and condition type.
///
/// @param type Whether type or device's dpId.
/// @param chooseValue enum string value, get it in ThingSmartSceneDPModel.dpModel.property.range
/// @param exprType To distinguish the entity type.
///
/// @return A ThingSmartSceneExprModel object.
+ (ThingSmartSceneExprModel *)createEnumExprWithType:(NSString *)type
                                         chooseValue:(NSString *)chooseValue
                                            exprType:(ExprType)exprType;

/// Create exprModel like "temp <= 40".
///
/// @param type Whether type or device's dpId.
/// @param operateString @">=",@"<=",@"=="
/// @param value selected value
/// @param exprType To distinguish the entity type.
///
/// @return A ThingSmartSceneExprModel object.
+ (ThingSmartSceneExprModel *)createValueExprWithType:(NSString *)type
                                             operater:(NSString *)operateString
                                          chooseValue:(NSInteger)value
                                             exprType:(ExprType)exprType;

/// Create exprModel like "rawType".
///
/// @param type Whether type or device's dpId.
/// @param exprType To distinguish the entity type.
///
/// @return A ThingSmartSceneExprModel object.
+ (ThingSmartSceneExprModel *)createRawExprWithType:(NSString *)type
                                           exprType:(ExprType)exprType;

/// Create timer condition.
///
/// @param timeZoneId timeZoneId like @"Asia/Shanghai".
/// @param loops eg: @"0111110", each character represent from Sunday to Monday. @"0000000" represent only once.
/// @param date eg: @"20190501".
/// @param time eg: @"20:40".
///
/// @return A ThingSmartSceneExprModel object.
+ (ThingSmartSceneExprModel *)createTimerExprWithTimeZoneId:(NSString *)timeZoneId
                                                      loops:(NSString *)loops
                                                       date:(NSString *)date
                                                       time:(NSString *)time;

/// Create a timer condition's expression related to sunrise or sunset times, For example, "x minutes before sunrise". "at sunrise" is still handled as a normal weather condition.
///
/// @param city City that needs to be set.
/// @param type Identify sunrise or sunset.
/// @param minutes From -300 minutes to 300 minutes.
///
/// @return A ThingSmartSceneExprModel object.
+ (ThingSmartSceneExprModel *)createSunsetriseTimerExprWithCity:(ThingSmartCityModel *)city
                                                           type:(SunType)type
                                                   deltaMinutes:(NSInteger)minutes;

/// create a geofence condition's expression.
///
/// @param type The geofence type.
///
/// @return A ThingSmartExprModel object.
+ (ThingSmartSceneExprModel *)buildGeofenceExprWithType:(GeoFenceType)type;

/// Create a calculate condition's expression for device.
/// @param dpId The dpId of device to be controlled.
/// @param dpType The type of datapoint. You can only pass `bool` or `enum`.
/// @param selectedValue The selected value for datapoint.
+ (ThingSmartSceneExprModel *)buildCalculateExprWithDpId:(NSString *)dpId dpType:(NSString *)dpType selectedValue:(id)selectedValue;


/// Generate member back to home condition's expression.
/// @param memberIds All the name of member, separated by a comma.
/// @return Expression object, additional data be required in member back to home condition.
+ (ThingSmartSceneExprModel *)buildMemberBackHomeExprWithMemberIds:(NSString *)memberIds;

@end

NS_ASSUME_NONNULL_END
