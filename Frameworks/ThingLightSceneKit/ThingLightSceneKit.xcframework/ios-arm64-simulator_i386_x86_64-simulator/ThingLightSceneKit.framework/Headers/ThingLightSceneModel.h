//
//  ThingLightSceneModel.h
//  ThingLightSceneKit
//
//  Copyright (c) 2014-2021 Thing (https://developer.thing.com/)

#import <Foundation/Foundation.h>
#import "ThingLightSceneEnums.h"
#import "ThingLightSceneActionModel.h"

NS_ASSUME_NONNULL_BEGIN

/// Scene model
@interface ThingLightSceneModel : NSObject<NSCoding>

/// The unique identifier for the scene
@property (nonatomic, strong) NSString *sceneId;

/// The actual rule identifier for the scene
@property (nonatomic, strong) NSString *actualRuleId;

/// The owner identifier of the scene
@property (nonatomic, strong) NSString *ownerId;

/// The user identifier of the scene
@property (nonatomic, strong) NSString *uid;

/// The unique code for the scene
@property (nonatomic, strong) NSString *code;

/// The parent region identifier of the scene
@property (nonatomic, strong) NSString *parentRegionId;

/// The icon of the scene
@property (nonatomic, strong) NSString *icon;

/// The click icon of the scene
@property (nonatomic, strong) NSString *clickIcon;

/// The name of the scene
@property (nonatomic, strong) NSString *name;

/// The scene type of the scene
@property (nonatomic, assign) ThingLightSceneType sceneType;

/// The status of the scene
@property (nonatomic, assign) BOOL status;

/// The start and stop state of the scene
@property (nonatomic, assign) BOOL enabled;

/// The sequence number of the scene
@property (nonatomic, assign) NSInteger sort;

/// The background image of the scene
@property (nonatomic, strong) NSString *background;

/// The display color of the scene
@property (nonatomic, strong) NSString *displayColor;

/// Whether the scene brightness is visible
@property (nonatomic, assign) BOOL brightVisible;

/// The bright percent of the scene
@property (nonatomic, assign) NSInteger brightPercent;

/// Whether the scene has already obtained details
@property (nonatomic, assign) BOOL cached;

/// The actions of the scene
@property (nonatomic, strong) NSArray<ThingLightSceneActionModel *>*actions;


@end

NS_ASSUME_NONNULL_END

