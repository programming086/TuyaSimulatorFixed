//
//  ThingLightingRepairDeviceConfigModel.h
//  ThingSmartCommercialLightingSdk
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingLightingRepairDeviceConfigItemModel : NSObject

// Item ID
@property (nonatomic, copy) NSString *itemId;
// Item name
@property (nonatomic, copy) NSString *name;

@property (nonatomic, copy) NSString *title;

@end

@interface ThingLightingRepairDeviceConfigModel : NSObject

/// The groups of device repaired
@property (nonatomic, copy) NSArray<ThingLightingRepairDeviceConfigItemModel *> *joinGroups;

/// The scenes of device repaired
@property (nonatomic, copy) NSArray<ThingLightingRepairDeviceConfigItemModel *> *joinScenes;

/// The linkages of device repaired
@property (nonatomic, copy) NSArray<ThingLightingRepairDeviceConfigItemModel *> *joinLinkages;

/// The schedule of device repaired
@property (nonatomic, copy) NSArray<ThingLightingRepairDeviceConfigItemModel *> *joinSchedules;

/// The gateway of device repaired
@property (nonatomic, strong) ThingLightingRepairDeviceConfigItemModel *gateway;

@end

NS_ASSUME_NONNULL_END
