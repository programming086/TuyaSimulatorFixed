//
//  ThingSmartSceneConditionModel+CheckDevice.h
//  ThingSmartSceneKit
//
//  Copyright (c) 2014-2021 Thing Inc. (https://developer.thing.com)

#import "ThingSmartSceneConditionModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartSceneConditionModel (CheckDevice)

///// Check whether the equipment is abnormal. Returns yes if the condition does not contain a device.
///// @return YES: Device is normal or this is not a device, NO：Device is abnormal.
- (BOOL)checkWhetherDeviceIsNormal;

///// Whether the current condition content is a device.
- (BOOL)cd_isDevice;

@end

NS_ASSUME_NONNULL_END
