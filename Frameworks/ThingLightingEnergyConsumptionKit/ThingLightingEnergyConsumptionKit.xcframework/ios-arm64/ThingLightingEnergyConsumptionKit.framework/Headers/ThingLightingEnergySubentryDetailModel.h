//
//  ThingLightingEnergySubentryDetailModel.h
//  ThingSmartCommercialLightingSdk
//
//  Copyright (c) 2014-2021 Thing Inc. (https://developer.thing.com/)
//

#import <Foundation/Foundation.h>
#import "ThingLightingEnergySubentryModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingLightingEnergySubentryDetailModel : NSObject

/// The lighting energy consumption.
@property (nonatomic, strong) ThingLightingEnergySubentryModel *lightingEnergy;

/// The air conditioning energy consumption.
@property (nonatomic, strong) ThingLightingEnergySubentryModel *airConditioningEnergy;

/// The power energy consumption.
@property (nonatomic, strong) ThingLightingEnergySubentryModel *powerEnergy;

/// The special energy consumption.
@property (nonatomic, strong) ThingLightingEnergySubentryModel *specialEnergy;

/// The other energy consumption.
@property (nonatomic, strong) ThingLightingEnergySubentryModel *undefinedEnergy;

@end

NS_ASSUME_NONNULL_END
