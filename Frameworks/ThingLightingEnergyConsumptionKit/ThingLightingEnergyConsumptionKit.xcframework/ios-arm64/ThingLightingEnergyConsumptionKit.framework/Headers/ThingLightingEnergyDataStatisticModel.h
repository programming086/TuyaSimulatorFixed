//
//  ThingLightingEnergyDataStatisticModel.h
//  ThingBuilding
//
//  Copyright (c) 2014-2021 Thing (https://developer.thing.com/)

#import <Foundation/Foundation.h>
#import "ThingLightingEnergyCarbonEmissionDataItemModel.h"

NS_ASSUME_NONNULL_BEGIN

/// energy data statistic
@interface ThingLightingEnergyDataStatisticModel : NSObject

/// Total consumed energy consumption
@property (nonatomic, assign) double total;

/// Total planned usage
@property (nonatomic, assign) double consumed;

/// Total remaining
@property (nonatomic, assign) double remained;

/// Used scale
@property (nonatomic, assign) double usedRate;

/// Year alarm ratio
@property (nonatomic, assign) BOOL yearAlarm;

/// Year warning ratio
@property (nonatomic, assign) BOOL yearWarning;

/// Season alarm ratio
@property (nonatomic, assign) BOOL seasonAlarm;

/// Season warning ratio
@property (nonatomic, assign) BOOL seasonWarning;

/// Year reference quota
@property (nonatomic, assign) double yearRefQuota;

@end

NS_ASSUME_NONNULL_END

