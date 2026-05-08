//
//  ThingLightingEnergyChartModel.h
//  ThingSmartCommercialLightingSdk
//
//  Copyright (c) 2014-2021 Thing Inc. (https://developer.thing.com/)
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingLightingEnergyChartModel : NSObject

/// The name of XAxis in Line chart view.
@property (nonatomic, copy) NSString *name;

/// The value of energy consumption(Keep two decimal places).
@property (nonatomic, copy) NSString *energy;

/// The sort of energy consumption.
@property (nonatomic, assign) NSInteger sort;

/// The time of this data.
@property (nonatomic, assign) long long time;

@end

NS_ASSUME_NONNULL_END
