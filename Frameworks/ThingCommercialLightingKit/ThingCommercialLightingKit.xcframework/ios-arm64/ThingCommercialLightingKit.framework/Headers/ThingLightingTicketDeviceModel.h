//
//  ThingLightingTicketDeviceModel.h
//  ThingSmartCommercialLightingSdk
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingLightingTicketDeviceModel : NSObject

/// Device ID
@property (nonatomic, copy) NSString *devId;

/// Device Saas ID(compatible the saas device ID of work order detail)
@property (nonatomic, copy) NSString *deviceSaasId;

/// Device name
@property (nonatomic, copy) NSString *devName;

/// Device location
@property (nonatomic, copy) NSString *deviceLocation;

/// Device type
@property (nonatomic, copy) NSString *deviceType;

/// Device address(It may not be accurate)
@property (nonatomic, copy) NSString *address;

@end

NS_ASSUME_NONNULL_END
