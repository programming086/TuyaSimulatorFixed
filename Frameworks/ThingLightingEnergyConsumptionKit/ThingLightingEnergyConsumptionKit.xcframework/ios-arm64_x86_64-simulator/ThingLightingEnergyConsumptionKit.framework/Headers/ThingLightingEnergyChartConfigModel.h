//
//  ThingLightingEnergyChartConfigModel.h
//  ThingBuilding
//
//  Copyright (c) 2014-2021 Thing (https://developer.thing.com/)

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

/// Configuration information of energy consumption chart
@interface ThingLightingEnergyChartConfigModel : NSObject

/// Chart number, through which the business party can query the chart configuration information
@property (nonatomic, strong) NSString *chartNo;

/// Query chart information from the server through this ID
@property (nonatomic, strong) NSString *configId;

/// User defined profile
@property (nonatomic, strong) NSString *pattern;


@end

NS_ASSUME_NONNULL_END

