//
//  ThingLightingEnergyModel.h
//  ThingSmartCommercialLightingSdk
//
//  Copyright (c) 2014-2021 Thing Inc. (https://developer.thing.com/)
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ThingLightingEnergyItemModel;

@interface ThingLightingEnergyModel : NSObject

/// The sort of energy consumption.
@property (nonatomic, assign) NSInteger sort;

/// The time stamp of energy consumption
@property (nonatomic, assign) long time;

/// The total energy consumption of device
@property (nonatomic, assign) double totalEnergy;

/// Category energy consumption. For example special electricity、HVAC、Power consumption
@property (nonatomic, strong) NSArray <ThingLightingEnergyItemModel *>*data;

@end

NS_ASSUME_NONNULL_END
