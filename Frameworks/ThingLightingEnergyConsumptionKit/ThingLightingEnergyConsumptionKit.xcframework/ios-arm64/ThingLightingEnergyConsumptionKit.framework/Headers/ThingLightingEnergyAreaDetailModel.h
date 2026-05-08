//
//  ThingLightingEnergyAreaDetailModel.h
//  ThingSmartCommercialLightingSdk
//
//  Copyright (c) 2014-2021 Thing Inc. (https://developer.thing.com/)
//

#import <Foundation/Foundation.h>

@class ThingLightingEnergyModel;

NS_ASSUME_NONNULL_BEGIN

@interface ThingLightingEnergyAreaDetailModel : NSObject

/// The total energy consumption of device.
@property (nonatomic, assign) double totalEnergy;

/// The average energy consumption of device.
@property (nonatomic, assign) double averageEnergy;

/// The energy consumption difference value year-on-year.
@property (nonatomic, assign) double tbValue;

/// The energy consumption difference value month on month.
@property (nonatomic, assign) double hbValue;

/// The energy consumption difference percentage year-on-year.
@property (nonatomic, assign) double tb;

/// The energy consumption difference percentage month on month.
@property (nonatomic, assign) double hb;

/// Unit energy consumption per month, day and hour.
@property (nonatomic, strong) NSArray <ThingLightingEnergyModel *> *data;

@end

NS_ASSUME_NONNULL_END
