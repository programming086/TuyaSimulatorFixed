//
//  ThingSmartSceneDPModel.h
//  ThingSmartSceneKit
//
//  Copyright (c) 2014-2021 Thing Inc. (https://developer.thing.com)

#import <CoreLocation/CoreLocation.h>
#import "TSmartSceneDPTypes.h"

@class ThingSmartSchemaModel;

/// @brief ThingSmartSceneDPModel provides more attributes for developers to implement the datapoint of device.
///
/// @note It is mainly used to describe the detail information of the device's data-points.
@interface ThingSmartSceneDPModel : NSObject <NSCoding, NSCopying>

/// The dp id, it maybe condition id or device id.
@property (nonatomic, assign) NSInteger dpId;

/// The product ID.This property represent the product's id this data-points belongs to. Only device's datapoints has this value.
@property (nonatomic, strong) NSString *entityId;

/// The entity name, it maybe condition name or datapoint name of device.
@property (nonatomic, strong) NSString *entityName;

/// The entity type, device as condition it will be NSInteger 1, 3 for meteorological condition, 6 for timer condition, 7 for human body detector condition, 10 for  geofencing condition.
@property (nonatomic, assign) NSInteger entityType;

/// The icon URL of condition.
@property (nonatomic, strong) NSString *iconUrl;

/// Condition's or device's data point' value range, like "value:{"unit":"","min":10,"max":1000,"scale":0,"step":1,"type":"value"}"
@property (nonatomic, strong) NSArray *valueRangeJson;

/// Properties of device, like {"id":1,"desc":"","name":"Switch","property":{"type":"bool"},"attr":3,"code":"switch_on","type":"obj","mode":"rw"}
@property (nonatomic, strong) NSString *actDetail;

/// Description of data point and selected value.
@property (nonatomic, strong) ThingSmartSchemaModel *dpModel;

/// The operation description, operators like "["=="]".
@property (nonatomic, strong) NSString *operators;

/// The condition name, code, properties. For details check the dpModel property.
@property (nonatomic, strong) NSDictionary *property;

/// The entity sub id of condition or datapoint of device, condition's subId like @"humidity", device data point's subId like "1".
@property (nonatomic, strong) NSString *entitySubId;

/// Multi control information, value is nil if not belong to any multi control group, format:[{"id":123,"groupName":"more control group 1"}]
@property (nonatomic, strong) NSArray *mcGroups;

/// Extra information about dp value's calculate type and other extra information, calType's range is ["sum","average","max","min","count","duration"].
@property (nonatomic, strong) NSDictionary *condCalExtraInfo;

#pragma mark - Logic properties blow can be ignored.
/*******Properties below are used to store user selected value, you can ignore.********/

/// The selected row, -1 means haven't selected, set by you.
@property (nonatomic, assign) NSInteger selectedRow;

/// The selected operator, -1 means haven't selected, set by you.
@property (nonatomic, assign) NSInteger selectedOperationRow;

/// The device Id，set by you.
@property (nonatomic, strong) NSString *devId;

/// The displayType of this datapoint‘s value.
@property (nonatomic, assign) SceneDisplayType displayType;

#pragma mark - Deprecated

/// Expression, eg:(("$humidity","==","comfort"), (“$dp1”，“==”，“1”), ...), set by you.
@property (nonatomic, strong) NSArray *expr __deprecated;

/// The city Id, set by you.
@property (nonatomic, strong) NSString *cityId __deprecated;

/// The city name, set by you.
@property (nonatomic, strong) NSString *cityName __deprecated;

/// The city's latitude, set by you.
@property (nonatomic, assign) CLLocationDegrees cityLatitude __deprecated;

/// The city's longitude, set by you.
@property (nonatomic, assign) CLLocationDegrees cityLongitude __deprecated;

/// The deprecated property.
@property (nonatomic, assign) NSInteger sceneDPId __deprecated;

// MARK: - Publics

/**
 Check if the datapoint property type is raw or string type.
 */
- (BOOL)isTransparentDP;

/**
 Check if the datapoint property type is raw.
 */
- (BOOL)isRawDP;

/**
 Check if the datapoint property type is string.
 */
- (BOOL)isStringDP;

/**
 Check if datapoint entity type is weather type.
 */
- (BOOL)isWeatherDP;

/**
 Check if datapoint entity subtype is sunset or sunrise type.
 */
- (BOOL)isSunsetriseDP;

/**
 The datapoint display type. Detail see `SceneDisplayType` enum definition.
 */
- (SceneDisplayType)displayType;

/**
 Check if datapoint display type is countdown. In includes h/m(hous, minute) and h/m/s(hous, minute, seconds) two display types.
 */
- (BOOL)isCountDownDP;

/**
 Check if the datapoint display type is percent or percent1. Percent type is from 0 to 100, Percent1 type is from 1 to 100.
 */
- (BOOL)isPercentDP;

/**
 Check if datapoint property unit is temperature unit, such as ℃ and ℉.
 
 @return YES when the unit is ℃ or ℉, otherwise NO.
 */
- (BOOL)isTempDP;

/**
 Return temperature type for datapoint property unit. return kSceneDPTempTypeCelsius when datapoint unit is ℃, return kSceneDPTempTypeFahrenheit when datapoint unit is ℉, otherwise return kSceneDPTempTypeNone.
 */
- (TSceneDPTempType)tempType;

/**
 This method should be called, because set properties on the object for logical processing.
 */
- (ThingSmartSceneDPModel *)modelWithEntityId:(NSString *)entityId isCondition:(BOOL)isCondition expr:(NSArray *)expr actDic:(NSDictionary *)actDic;

/**
 This method returns the selected value of data point.
 */
- (NSInteger)selectedValue;

/**
 This method returns the percentage of data point.
 */
- (NSDictionary *)percentDp;

/**
 This method converts percentage values to specific values.
 */
- (NSInteger)percentToValue;

/**
 This method converts specific values to percentage values.
 */
- (NSInteger)valueToPercent;

/**
 This method returns a specific description of the selected data point value.
 */
- (NSString *)selectedValueDisplayStr;


// MARK: - Deprecated

/**
 Check if the datapoint display type is percent or percent1. Percent type is from 0 to 100, Percent1 type is from 1 to 100. This method works the same as `isPercentDP`.
 */
- (BOOL)isPercentDisplayDP __attribute__((deprecated("Use `isPercentDP` instead.")));

@end
