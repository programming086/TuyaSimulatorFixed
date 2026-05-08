//
//  ThingLightingEnergyChartFilterModel.h
//  ThingBuilding
//
//  Copyright (c) 2014-2021 Thing (https://developer.thing.com/)

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

/// Filter chart criteria
@interface ThingLightingEnergyChartFilterModel : NSObject

@property (nonatomic, strong) NSString *period;

/// The start timestamp is required when the period is cd / cm / cy
@property (nonatomic, assign) long long start;

/// The end timestamp is required when the period is cd / cm / cy
@property (nonatomic, assign) long long end;


@end

NS_ASSUME_NONNULL_END

