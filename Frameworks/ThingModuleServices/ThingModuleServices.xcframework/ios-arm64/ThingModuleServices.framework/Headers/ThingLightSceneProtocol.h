//
//  ThingLightSceneProtocol.h
//  ThingLightModuleServices
//
//  Copyright (c) 2014-2021 Thing Inc. (https://developer.thing.com/)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ThingLightSceneModel;

@protocol ThingLightSceneProtocol <NSObject>

/// 跳转至「创建灯光场景页」
- (void)createNewLightScene;

/// 跳转至「编辑灯光场景页」
/// @param scene 灯光场景模型
- (void)editLightScene:(ThingLightSceneModel *)scene;

@end

NS_ASSUME_NONNULL_END
