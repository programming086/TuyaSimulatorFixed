//
//  ThingLightingEnergyItemModel.h
//  ThingSmartCommercialLightingSdk
//
//  Copyright (c) 2014-2021 Thing Inc. (https://developer.thing.com/)
//


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ThingLightingEnergyPurposeType) {
    ThingLightingEnergyPurpose_LIGHTING = 2,            // Lighting socket
    ThingLightingEnergyPurpose_AIR_CONDITIONING = 3,    // Air conditioner
    ThingLightingEnergyPurpose_POWER = 4,               // Power
    ThingLightingEnergyPurpose_SPECIAL = 5,             // Special
    ThingLightingEnergyPurpose_OTHER = -1,              // Other
};

@interface ThingLightingEnergyItemModel : NSObject

/// The purpose code of sub-item energy.
@property (nonatomic, assign) NSInteger purposeCode;

/// The multi-language name of sub-item energy consumption.
@property (nonatomic, copy) NSString *i18nName;

/// The value of sub-item energy consumption.
@property (nonatomic, assign) double energy;

@end

NS_ASSUME_NONNULL_END
