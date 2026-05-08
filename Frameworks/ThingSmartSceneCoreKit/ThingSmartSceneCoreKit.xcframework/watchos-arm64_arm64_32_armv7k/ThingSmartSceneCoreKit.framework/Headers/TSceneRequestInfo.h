//
//  TSceneRequestInfo.h
//  ThingSmartSceneCoreKit
//
//  Created by mile on 2023/6/8.
//

#import <Foundation/Foundation.h>

@class ThingSmartSceneModel;

NS_ASSUME_NONNULL_BEGIN

/// It represents the request information for adding scene, editing scene, removing scene.
@interface TSceneRequestInfo : NSObject

/// Scene information model, detail see `ThingSmartSceneModel`.
@property (nonatomic, strong) ThingSmartSceneModel *sceneModel;
/// Setting needCleanGidSid flag can clears the standard information for extraProperty in the action of the scene. It will may cause scene control to become invalid. Default is NO.
@property (nonatomic, assign) BOOL needCleanGidSid;

@end

NS_ASSUME_NONNULL_END
