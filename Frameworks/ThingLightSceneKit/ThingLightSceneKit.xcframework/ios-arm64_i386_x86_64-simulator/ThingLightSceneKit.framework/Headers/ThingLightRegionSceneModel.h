//
//  ThingLightRegionSceneModel.h
//  ThingLightSceneKit
//
//  Copyright (c) 2014-2021 Thing (https://developer.thing.com/)

#import <Foundation/Foundation.h>
#import "ThingLightSceneModel.h"

NS_ASSUME_NONNULL_BEGIN

/// Scene model under the region
@interface ThingLightRegionSceneModel : NSObject

/// The parent region identifier of the scene
@property (nonatomic, strong) NSString *parentRegionId;

/// The parent region name of the scene
@property (nonatomic, strong) NSString *parentRegionName;

/// The data list of all scenes
@property (nonatomic, strong) NSArray<ThingLightSceneModel *>*linkageLightSceneVOList;


@end

NS_ASSUME_NONNULL_END

