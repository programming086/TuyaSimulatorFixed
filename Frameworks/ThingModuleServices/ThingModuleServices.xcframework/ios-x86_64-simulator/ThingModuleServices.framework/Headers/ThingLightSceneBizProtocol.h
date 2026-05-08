//
//  ThingLightSceneBizProtocol.h
//  ThingLightModuleServices
//
//  Copyright (c) 2014-2021 Thing Inc. (https://developer.thing.com/)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ThingLightSceneModel;

@protocol ThingLightSceneBizProtocol <NSObject>

/// 执行灯光场景
- (void)executeLightScene:(ThingLightSceneModel *)sceneModel
                  success:(void(^)(BOOL success))success
                  failure:(void(^)(NSError * _Nonnull error))failure;

/// 获取灯光场景列表
- (void)getLightSceneListWithSuccess:(void(^)(NSArray<ThingLightSceneModel *> * _Nonnull scenes))success
                             failure:(void(^)(NSError * _Nonnull error))failure;
                             
@end

NS_ASSUME_NONNULL_END
