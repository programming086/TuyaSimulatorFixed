//
//  ThingLightScene.h
//  ThingLightSceneKit
//
//  Copyright (c) 2014-2021 Thing (https://developer.thing.com/)

#import <ThingSmartUtil/ThingSmartUtil.h>

NS_ASSUME_NONNULL_BEGIN

@class ThingLightSceneModel;

@interface ThingLightScene : NSObject

+ (instancetype)sceneWithSceneModel:(ThingLightSceneModel *)sceneModel;

- (ThingLightSceneModel *)cacheSceneModel;

/// Execute the lighting scene
///
/// @param gid The unique identifier for the location
/// @param success Callback for successful request
/// @param failure Callback for failed request
- (void)executeLightSceneWithGid:(long long)gid 
                         success:(ThingSuccessHandler)success
                         failure:(void(^)(NSError *error))failure;

/// Delete the lighting scene
///
/// @param gid The unique identifier for the location
/// @param success Callback for successful request
/// @param failure Callback for failed request
- (void)deleteLightSceneWithGid:(long long)gid 
                        success:(void(^)(BOOL result))success 
                        failure:(void(^)(NSError *error))failure;

/// Adjust the overall brightness of the lighting scene
///
/// @param gid The unique identifier for the location
/// @param originPercent The origin percent of the lighting scene
/// @param targetPercent The target percent of the lighting scene
/// @param success Callback for successful request
/// @param failure Callback for failed request
- (void)updateLightSceneBrightWithGid:(long long)gid 
                        originPercent:(NSInteger)originPercent 
                        targetPercent:(NSInteger)targetPercent 
                              success:(void(^)(BOOL result))success 
                              failure:(void(^)(NSError *error))failure;

@end

NS_ASSUME_NONNULL_END
