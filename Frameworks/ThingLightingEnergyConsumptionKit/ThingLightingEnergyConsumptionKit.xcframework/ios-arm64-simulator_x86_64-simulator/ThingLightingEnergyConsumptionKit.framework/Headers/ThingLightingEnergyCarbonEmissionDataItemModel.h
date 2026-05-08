//
//  ThingLightingEnergyCarbonEmissionDataItemModel.h
//  ThingBuilding
//
//  Copyright (c) 2014-2021 Thing (https://developer.thing.com/)

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

/// Carbon emission chart data item
@interface ThingLightingEnergyCarbonEmissionDataItemModel : NSObject

/// chart time
@property (nonatomic, assign) long long time;

/// chart value
@property (nonatomic, assign) double value;


@end

NS_ASSUME_NONNULL_END

