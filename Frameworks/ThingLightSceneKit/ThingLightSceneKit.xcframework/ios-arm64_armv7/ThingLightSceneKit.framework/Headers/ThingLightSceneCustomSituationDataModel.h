//
//  ThingLightSceneCustomSituationDataModel.h
//  ThingLightSceneKit
//
//  Copyright (c) 2014-2021 Thing (https://developer.thing.com/)
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Custom scene situation data model

@class ThingLightSceneCustomSituationDataItemModel;

@interface ThingLightSceneCustomSituationDataModel : NSObject

@property (nonatomic, assign) NSInteger iconDisplayType;

@property (nonatomic, strong) NSString *iconDisplaySize;

@property (nonatomic, strong) NSArray<ThingLightSceneCustomSituationDataItemModel *>*items;

@end

@interface ThingLightSceneCustomSituationDataItemModel : NSObject

/// The unique identifier for the situation
@property (nonatomic, assign) long long sceneId;

/// The plate identifier of the situation
@property (nonatomic, assign) long long plateId;

/// The dp code of the situation
@property (nonatomic, strong) NSString *dpCode;

/// The display size of scene icon
@property (nonatomic, strong) NSString *sceneIconDisplaySize;

/// The display type of scene icon
@property (nonatomic, assign) NSInteger sceneIconDisplayType;

/// The icon of the situation
@property (nonatomic, strong) NSString *icon;

/// The background image displayed on the situation card
@property (nonatomic, strong) NSString *selectCellBackground;

/// The name of the situation
@property (nonatomic, strong) NSString *sceneName;

/// The scene data of the situation
@property (nonatomic, strong) NSString *sceneData;

/// The scene sort number of the situation
@property (nonatomic, assign) NSInteger sort;

/// The created  time of scene
@property (nonatomic, assign) long long gmtCreate;

/// The modified time of scene
@property (nonatomic, assign) long long gmtModified;

@end

NS_ASSUME_NONNULL_END
