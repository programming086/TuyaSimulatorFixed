//
//  ThingLightingEnergySubentryModel.h
//  ThingSmartCommercialLightingSdk
//
//  Copyright (c) 2014-2021 Thing Inc. (https://developer.thing.com/)
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ThingLightingEnergyChartModel;

@interface ThingLightingEnergySubentryModel : NSObject

/// The total energy consumption of device(Keep two decimal places).
@property (nonatomic, copy) NSString *totalEnergy;

/// The purpose code of sub-item energy.
@property (nonatomic, assign) NSInteger purposeCode;

/// The multi-language name of sub-item energy consumption.
@property (nonatomic, copy) NSString *purposeName;

/// Unit energy consumption per month, day and hour.
@property (nonatomic, strong) NSArray <ThingLightingEnergyChartModel *>*list;

@end

NS_ASSUME_NONNULL_END
