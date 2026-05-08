//
//  ThingSmartGroupModel+BusinessLighting.h
//  ThingSmartCommercialLightingSdk
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)
//


#import <ThingSmartDeviceCoreKit/ThingSmartGroupModel.h>
NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartGroupModel (ThingLighting)

/// The id of the packed group to which it belongs.
@property (nonatomic, strong) NSString *packedGroupId;

@end

NS_ASSUME_NONNULL_END
