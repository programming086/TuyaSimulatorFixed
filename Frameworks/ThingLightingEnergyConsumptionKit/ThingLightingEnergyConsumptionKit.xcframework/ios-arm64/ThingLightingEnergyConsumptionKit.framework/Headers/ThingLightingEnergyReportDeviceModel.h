//
//  ThingLightingEnergyReportDeviceModel.h
//  ThingSmartCommercialLightingSdk
//
//  Copyright (c) 2014-2021 Thing Inc. (https://developer.thing.com/)
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingLightingEnergyReportDeviceModel : NSObject

/// Device name
@property (nonatomic, copy) NSString *deviceName;

/// The purpose of device.
@property (nonatomic, copy) NSString *devicePurpose;

/// The total energy consumption of device.
@property (nonatomic, assign) double totalEnergy;

/// Area name(Contain last Area).
@property (nonatomic, copy) NSString *roomName;

/// The URL of icon logo.
@property (nonatomic, copy) NSString *iconUrl;

@end

NS_ASSUME_NONNULL_END
