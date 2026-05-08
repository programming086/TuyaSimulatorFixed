//
//  ThingLightingReplaceDeviceModel.h
//  ThingSmartCommercialLightingSdk
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingLightingReplaceDeviceModel : NSObject

/// Device ID
@property (nonatomic, copy) NSString *devId;

/// Device Saas ID （Compatible the Device ID Of Repair Work Order）
@property (nonatomic, copy) NSString *deviceSaasId;

/// Device Name
@property (nonatomic, copy) NSString *devName;

/// Device Location
@property (nonatomic, copy) NSString *deviceLocation;

/// Device Type
@property (nonatomic, copy) NSString *deviceType;

/// Device Address
@property (nonatomic, copy) NSString *address;

@end

NS_ASSUME_NONNULL_END
