//
//  ThingLightingEnergyQuotaStatisticDataModel.h
//  ThingBuilding
//
//  Copyright (c) 2014-2021 Thing (https://developer.thing.com/)

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

/// Quota energy use data
@interface ThingLightingEnergyQuotaStatisticDataModel : NSObject

/// Start time of annual statistics
@property (nonatomic, assign) long long yearStart;

/// End time of annual statistics
@property (nonatomic, assign) long long yearEnd;

/// Start time of season statistics
@property (nonatomic, assign) long long seasonStart;

/// End time of season statistics
@property (nonatomic, assign) long long seasonEnd;

/// Annual used energy consumption
@property (nonatomic, assign) double yearUsage;

/// Season used energy consumption
@property (nonatomic, assign) double seasonUsage;

/// Whether the annual energy consumption alarms
@property (nonatomic, assign) BOOL yearAlarm;

/// Whether the annual energy consumption warnings
@property (nonatomic, assign) BOOL yearWarning;

/// Whether the season energy consumption alarms
@property (nonatomic, assign) BOOL seasonAlarm;

/// Whether the season energy consumption warnings
@property (nonatomic, assign) BOOL seasonWarning;

/// Year reference quota
@property (nonatomic, assign) double yearRefQuota;

/// Season reference quota
@property (nonatomic, assign) double seasonRefQuota;

/// Annual electricity consumption quota
@property (nonatomic, assign) double yearLimit;

/// Quarterly quota percentage
@property (nonatomic, assign) double seasonLimit;

@end

NS_ASSUME_NONNULL_END

