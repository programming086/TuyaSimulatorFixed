//
//  ThingLightingEnergyBuildingAreaModel.h
//  ThingBuilding
//
//  Copyright (c) 2014-2021 Thing (https://developer.thing.com/)

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

/// Energy building area 
@interface ThingLightingEnergyBuildingAreaModel : NSObject

/// building area
@property (nonatomic, assign) double buildingArea;

/// HVAC area
@property (nonatomic, assign) double hvacArea;

/// The Maximum value that can be set for space area, which is used for space editing verification
@property (nonatomic, assign) double areaUpperLimit;

/// The minimum value that can be set for space area, which is used for space editing verification
@property (nonatomic, assign) double areaLowerLimit;

@end

NS_ASSUME_NONNULL_END

