//
//  ThingLightingRegionModel.h
//  ThingSmartCommercialLightingSdk
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingLightingRegionModel : NSObject

/// Country Code
@property (nonatomic, copy) NSString *countryCode;

/// Region ID
@property (nonatomic, copy) NSString *locationId;

/// Region name
@property (nonatomic, copy) NSString *name;

/// Name initials
@property (nonatomic, copy) NSString *pinyinInitials;

/// Superior administrative region ID
@property (nonatomic, copy) NSString *parentId;

/// List of lower administrative regions
@property (nonatomic, copy) NSArray<ThingLightingRegionModel *> *children;

@end

NS_ASSUME_NONNULL_END
