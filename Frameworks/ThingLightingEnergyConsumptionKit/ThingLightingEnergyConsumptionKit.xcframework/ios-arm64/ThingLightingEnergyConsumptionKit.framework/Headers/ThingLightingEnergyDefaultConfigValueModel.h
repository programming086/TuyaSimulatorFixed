//
//  ThingLightingEnergyDefaultConfigValueModel.h
//  ThingLightingEnergyConsumptionKit
//
//  Created by tong san on 2021/11/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Default scale configuration
@interface ThingLightingEnergyDefaultConfigValueModel : NSObject

/// Quota ratio in the first quarter
@property (nonatomic, assign) double q1;

/// Quota ratio in the second quarter
@property (nonatomic, assign) double q2;

/// Quota ratio in the third quarter
@property (nonatomic, assign) double q3;

/// Quota ratio in the fourth quarter
@property (nonatomic, assign) double q4;

/// Alarm ratio
@property (nonatomic, assign) double alarm;

/// Warning ratio
@property (nonatomic, assign) double warning;

@end

NS_ASSUME_NONNULL_END
