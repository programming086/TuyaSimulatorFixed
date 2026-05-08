//
// ThingSmartSceneManager+Home.h
// ThingSmartSceneKit
//
// Copyright (c) 2014-2021 Thing Inc. (https://developer.thing.com/)

#import <ThingSmartSceneCoreKit/ThingSmartSceneCoreKit.h>
#import <ThingSmartDeviceKit/ThingSmartDeviceKit.h>

@interface ThingSmartSceneManager (Home)

/// Get action device list in the current room with the specify room id.
///
/// @param roomId The room ID.
///
/// @retrun The ThingSmartDeviceModel list, the more information you can see ThingSmartDeviceModel class.
- (NSArray<ThingSmartDeviceModel *> *)getActionDeviceListWithRoomId:(long long)roomId;

/// Get condition device list for the current room in the scene with specify room id.
///
/// @param roomId The room ID.
///
/// @return The ThingSmartDeviceModel list, the more information you can see ThingSmartDeviceModel class.
- (NSArray<ThingSmartDeviceModel *> *)getConditionDeviceListWithRoomId:(long long)roomId;

/// Get group list for action in the scene with specify the current room id.
///
/// @param roomId The room ID.
///
/// @return The ThingSmartGroupModel list for action in the scene, more information you can see ThingSmartGroupModel class.
- (NSArray<ThingSmartGroupModel *> *)getActionGroupListWithRoomId:(long long)roomId;

/// Get status condition device list for action in the scene with specify the current room id.
/// @param roomId The room ID.
/// 
/// @return The ThingSmartDeviceModel list, the more information you can see ThingSmartDeviceModel class.
- (NSArray<ThingSmartDeviceModel *> *)statusConditionDeviceListWithRoomId:(long long)roomId;

@end
