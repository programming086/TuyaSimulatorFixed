//
//  ThingLightSceneActionModel.h
//  ThingLightSceneKit
//
//  Copyright (c) 2014-2021 Thing (https://developer.thing.com/)

#import <Foundation/Foundation.h>
#import "ThingLightSceneFunctionModel.h"

NS_ASSUME_NONNULL_BEGIN

/// Scene action model
@interface ThingLightSceneActionModel : NSObject<NSCoding>

/// The action type, can be the followed types: lightRegionClose、lightDevice、lightGroup
@property (nonatomic, strong) NSString *actionExecutor;

/// The entity id. If action is a device, entityId is devId, and groupId for group action
@property (nonatomic, strong) NSString *entityId;

/// The entity name
@property (nonatomic, strong) NSString *entityName;

/// Describe what this action will do with origin format like the below example, you can use it to create the description
@property (nonatomic, strong) NSDictionary<NSString *, NSString *>* actionDisplayNew;

/// Execute property of the action
@property (nonatomic, strong) NSDictionary<NSString *, id>* executorProperty;

/// Local extra property of action
@property (nonatomic, strong) NSDictionary<NSString *, id>* extraProperty;

/// Whether the device bound to action is old dp
@property (nonatomic, assign) BOOL isOldDp;

@end

NS_ASSUME_NONNULL_END

