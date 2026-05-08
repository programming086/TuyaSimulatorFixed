//
//  ThingLightingEnergyRankModel.h
//  ThingSmartCommercialLightingSdk
//
//  Copyright (c) 2014-2021 Thing Inc. (https://developer.thing.com/)
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingLightingEnergyRankModel : NSObject

/// The name of sub-item energy consumption.
@property (nonatomic, copy) NSString *rankName;

/// The value of sub-item energy consumption(Keep two decimal places).
@property (nonatomic, assign) double rankValue;

/// The percent of sub-item energy consumption(Keep two decimal places).
@property (nonatomic, assign) double percent;

@end

NS_ASSUME_NONNULL_END
