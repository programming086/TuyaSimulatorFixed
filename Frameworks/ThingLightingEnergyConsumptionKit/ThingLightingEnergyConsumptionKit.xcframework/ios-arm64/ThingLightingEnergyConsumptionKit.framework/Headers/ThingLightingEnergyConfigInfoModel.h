//
//  ThingLightingEnergyConfigInfoModel.h
//  ThingBuilding
//
//  Copyright (c) 2014-2021 Thing (https://developer.thing.com/)

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

/// User defined configuration information
@interface ThingLightingEnergyConfigInfoModel : NSObject

/// Reset annual quota statistics (set to true when recalculate is selected)
@property (nonatomic, assign) BOOL yearReset;

/// Switch status of annual quota statistics
@property (nonatomic, assign) BOOL yearSwitch;

/// Last switch status
@property (nonatomic, assign) BOOL formerYearSwitch;

/// Annual electricity consumption quota
@property (nonatomic, assign) double yearLimit;

/// Annual statistical scope
@property (nonatomic, strong) NSArray<NSNumber *>*yearTimes;

/// Reset season quota statistics (set to true when recalculate is selected)
@property (nonatomic, assign) BOOL seasonReset;

/// Switch status of season quota statistics
@property (nonatomic, assign) BOOL seasonSwitch;

/// Last switch status
@property (nonatomic, assign) BOOL formerSeasonSwitch;

/// Quarterly quota percentage
@property (nonatomic, strong) NSArray<NSNumber *>*seasonLimit;

/// Quarterly statistics range
@property (nonatomic, strong) NSArray<NSNumber *>*seasonTimes;

/// Rated power consumption detection switch
@property (nonatomic, assign) BOOL usageSwitch;

/// Alarm ratio
@property (nonatomic, assign) double alarmRatio;

/// Warning ratio
@property (nonatomic, assign) double warningRatio;


@end

NS_ASSUME_NONNULL_END

