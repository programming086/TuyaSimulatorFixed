//
//  ThingLightingEnergyDefaultConfigModel.h
//  ThingBuilding
//
//  Copyright (c) 2014-2021 Thing (https://developer.thing.com/)

#import <Foundation/Foundation.h>
#import "ThingLightingEnergyDefaultConfigLimitModel.h"
#import "ThingLightingEnergyDefaultConfigValueModel.h"

NS_ASSUME_NONNULL_BEGIN

/// Default scale configuration
@interface ThingLightingEnergyDefaultConfigModel : NSObject

/// Upper and lower limits of default configuration
@property (nonatomic, strong) ThingLightingEnergyDefaultConfigLimitModel *limit;

/// Default value configuration
@property (nonatomic, strong) ThingLightingEnergyDefaultConfigValueModel *defaultValue;

@end

NS_ASSUME_NONNULL_END

