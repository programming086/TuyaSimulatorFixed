//
//  ThingLightAreaModel.h
//  ThingLightSceneKit
//
//  Copyright (c) 2014-2021 Thing (https://developer.thing.com/)

#import <Foundation/Foundation.h>
#import <ThingSmartDeviceCoreKit/ThingSmartDeviceModel.h>
#import <ThingSmartDeviceCoreKit/ThingSmartGroupModel.h>

NS_ASSUME_NONNULL_BEGIN

/// Area model
@interface ThingLightAreaModel : NSObject

/// The unique identifier for the light area
@property (nonatomic, assign) long long roomId;

/// The name of the light area
@property (nonatomic, strong) NSString *name;

/// The displayOrder of the light area
@property (nonatomic, assign) NSInteger displayOrder;

/// The device list of the light area
@property (nonatomic, strong) NSMutableArray<ThingSmartDeviceModel *>*deviceList;

/// The group list of the light area
@property (nonatomic, strong) NSMutableArray<ThingSmartGroupModel *>*groupList;

/// Lamp device entity list, include device status and more other info
@property (nonatomic, strong) NSMutableArray *deviceEntityList;


@end

NS_ASSUME_NONNULL_END

