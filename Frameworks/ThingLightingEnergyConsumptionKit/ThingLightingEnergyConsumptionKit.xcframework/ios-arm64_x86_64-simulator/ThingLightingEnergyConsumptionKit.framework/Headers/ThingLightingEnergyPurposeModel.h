//
//  ThingLightingEnergyPurposeModel.h
//  ThingSmartCommercialLightingSdk
//
//  Copyright (c) 2014-2021 Thing Inc. (https://developer.thing.com/)
//

#import <Foundation/Foundation.h>
#import <ThingSmartBaseKit/ThingSmartBaseKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingLightingEnergyPurposeModel : NSObject<NSCopying>

/// The purpose content code of energy.
@property (nonatomic, copy) NSString *dictCode;

/// The purpose value of energy.
@property (nonatomic, copy) NSString *dictValue;

/// The sort number of energy.
@property (nonatomic, assign) NSInteger sort;

@end

NS_ASSUME_NONNULL_END
