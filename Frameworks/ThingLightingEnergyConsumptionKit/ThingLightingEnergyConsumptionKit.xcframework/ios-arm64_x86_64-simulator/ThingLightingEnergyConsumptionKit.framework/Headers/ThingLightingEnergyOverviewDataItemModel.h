//
//  ThingLightingEnergyOverviewDataItemModel.h
//  ThingBuilding
//
//  Copyright (c) 2014-2021 Thing (https://developer.thing.com/)

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

/// Entry information for data overview
@interface ThingLightingEnergyOverviewDataItemModel : NSObject

/// Energy consumption value
@property (nonatomic, assign) double consumption;

/// Statistical time
@property (nonatomic, strong) NSString *time;

/// Statistical unit
@property (nonatomic, strong) NSString *unit;

/// Statistical item name
@property (nonatomic, strong) NSString *i18nName;


@end

NS_ASSUME_NONNULL_END

