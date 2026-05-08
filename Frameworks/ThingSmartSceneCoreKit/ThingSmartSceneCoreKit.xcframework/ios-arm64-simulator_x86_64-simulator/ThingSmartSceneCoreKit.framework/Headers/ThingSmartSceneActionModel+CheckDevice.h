//
//  ThingSmartSceneActionModel+CheckDevice.h
//  ThingSmartSceneKit
//
//  Copyright (c) 2014-2021 Thing Inc. (https://developer.thing.com)

#import "ThingSmartSceneActionModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartSceneActionModel (CheckDevice)

///// Check whether the device is abnormal (offline/removed). Returns yes if the action does not contain a device.
///// @return YES: Device is normal or this is not a device, NO: device is abnormal.
- (BOOL)checkWhetherDeviceIsNormal;

@end

NS_ASSUME_NONNULL_END
