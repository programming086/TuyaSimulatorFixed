//
//  ThingLightingEnergyOverviewDataModel.h
//  ThingBuilding
//
//  Copyright (c) 2014-2021 Thing (https://developer.thing.com/)

#import <Foundation/Foundation.h>
#import "ThingLightingEnergyOverviewDataItemModel.h"

NS_ASSUME_NONNULL_BEGIN

/// Overview of energy consumption data
@interface ThingLightingEnergyOverviewDataModel : NSObject

/// Historical data statistics
@property (nonatomic, strong) NSArray<ThingLightingEnergyOverviewDataItemModel *> *history;

/// Today's statistics
@property (nonatomic, strong) NSArray<ThingLightingEnergyOverviewDataItemModel *> *today;

/// Statistics of unit area data
@property (nonatomic, strong) NSArray<ThingLightingEnergyOverviewDataItemModel *> *unit;


@end

NS_ASSUME_NONNULL_END

