//
//  ThingLightingEnergyDefaultConfigLimitModel.h
//  ThingLightingEnergyConsumptionKit
//
//  Created by tong san on 2021/11/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingLightingEnergyDefaultConfigLimitModel : NSObject

/// Upper and lower limits of alarm proportion
@property (nonatomic, strong) NSArray<NSNumber *>*alarm;

/// Upper and lower limits of warning proportion
@property (nonatomic, strong) NSArray<NSNumber *>*warning;

/// Upper and lower limits of annual power consumption quota
@property (nonatomic, strong) NSArray<NSNumber *>*yearLimit;

@end

NS_ASSUME_NONNULL_END
