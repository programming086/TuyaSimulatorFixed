//
//  ThingSmartDeviceModel+LocalProperty.h
//  ThingSmartDeviceCoreKit
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)
//

#import <ThingSmartDeviceCoreKit/ThingSmartDeviceCoreKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartDeviceModel (LocalProperty)

- (void)meshSubDevLoadCacheProperties;
- (void)zigbeeSubDevLoadCacheProperties;

/// Core cache retains local data - specific field
/// @param properties Field array of type NSString
- (void)loadCacheWithProperties:(NSArray<NSString *> *)properties;

@end

NS_ASSUME_NONNULL_END
