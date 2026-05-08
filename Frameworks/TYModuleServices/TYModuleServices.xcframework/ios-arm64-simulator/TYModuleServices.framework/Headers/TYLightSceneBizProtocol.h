//
//  TYLightSceneBizProtocol.h
//  TYLightModuleServices
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com/)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class TuyaLightSceneModel;

@protocol TYLightSceneBizProtocol <NSObject>

/// 执行灯光场景
- (void)executeLightScene:(TuyaLightSceneModel *)sceneModel
                  success:(void(^)(BOOL success))success
                  failure:(void(^)(NSError * _Nonnull error))failure;

/// 获取灯光场景列表
- (void)getLightSceneListWithSuccess:(void(^)(NSArray<TuyaLightSceneModel *> * _Nonnull scenes))success
                             failure:(void(^)(NSError * _Nonnull error))failure;
                             
@end

NS_ASSUME_NONNULL_END
