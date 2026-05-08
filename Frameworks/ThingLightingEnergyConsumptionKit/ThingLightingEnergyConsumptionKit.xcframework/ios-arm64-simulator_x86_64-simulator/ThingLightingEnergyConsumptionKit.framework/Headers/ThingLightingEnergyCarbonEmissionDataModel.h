//
//  ThingLightingEnergyCarbonEmissionDataModel.h
//  ThingBuilding
//
//  Copyright (c) 2014-2021 Thing (https://developer.thing.com/)

#import <Foundation/Foundation.h>
#import "ThingLightingEnergyCarbonEmissionDataItemModel.h"

NS_ASSUME_NONNULL_BEGIN

/// Carbon emission data
@interface ThingLightingEnergyCarbonEmissionDataModel : NSObject

/// When the longitude and latitude are not configured for the project, the carbon emission data will not be counted
@property (nonatomic, assign) BOOL missingLocation;

/// Whether carbon emission chart function is supported
@property (nonatomic, assign) BOOL support;

/// Cumulative carbon emissions
@property (nonatomic, assign) double totalCE;

/// Carbon emissions of the year
@property (nonatomic, assign) double yearCE;

/// Carbon emissions per unit area
@property (nonatomic, assign) double unitCE;

/// Cycle carbon emissions
@property (nonatomic, assign) double periodCE;

/// Carbon emission line chart
@property (nonatomic, strong) NSArray<ThingLightingEnergyCarbonEmissionDataItemModel *>*list;


@end

NS_ASSUME_NONNULL_END

