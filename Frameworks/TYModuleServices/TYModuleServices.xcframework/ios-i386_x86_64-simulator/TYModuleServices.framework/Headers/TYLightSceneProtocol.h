//
//  TYLightSceneProtocol.h
//  TYLightModuleServices
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com/)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class TuyaLightSceneModel;

@protocol TYLightSceneProtocol <NSObject>

/// 跳转至「创建灯光场景页」
- (void)createNewLightScene;

/// 跳转至「编辑灯光场景页」
/// @param scene 灯光场景模型
- (void)editLightScene:(TuyaLightSceneModel *)scene;

@end

NS_ASSUME_NONNULL_END
