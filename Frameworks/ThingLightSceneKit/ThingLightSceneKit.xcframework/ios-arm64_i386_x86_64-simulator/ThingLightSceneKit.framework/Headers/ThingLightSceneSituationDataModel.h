//
//  ThingLightSceneSituationDataModel.h
//  ThingLightSceneKit
//
//  Copyright (c) 2014-2021 Thing (https://developer.thing.com/)

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

/// Scene situation data model
@interface ThingLightSceneSituationDataModel : NSObject

/// The unique identifier for the situation
@property (nonatomic, assign) long long situationId;

/// The plate key of the situation
@property (nonatomic, strong) NSString *plateKey;

/// The icon of the situation
@property (nonatomic, strong) NSString *icon;

/// The name of the situation
@property (nonatomic, strong) NSString *name;

/// The dp code of the situation
@property (nonatomic, strong) NSString *dpCode;

/// The background image displayed on the situation card
@property (nonatomic, strong) NSString *selectCellBackground;

/// The scene number of the situation
@property (nonatomic, strong) NSString *sceneNum;

/// The scene data of the situation
@property (nonatomic, strong) NSString *sceneData;

/// The scene picture of the situation
@property (nonatomic, strong) NSString *panelScenePic;

/// The scene entity picture of the situation
@property (nonatomic, strong) NSString *panelEntityPic;


@end

NS_ASSUME_NONNULL_END

