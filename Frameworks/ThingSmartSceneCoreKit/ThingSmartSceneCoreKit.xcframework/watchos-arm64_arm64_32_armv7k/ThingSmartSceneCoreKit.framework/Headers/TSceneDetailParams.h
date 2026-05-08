//
//  TSceneDetailParams.h
//  ThingSmartSceneCoreKit
//
//  Created by mile on 2023/12/19.
//

#import <Foundation/Foundation.h>
#import "TSmartSceneModelTypes.h"

NS_ASSUME_NONNULL_BEGIN

/// The class represents parameters object for query scene details.
@interface TSceneDetailParams : NSObject

/// The scene ID.
@property (nonatomic, copy) NSString *sceneId;
/// The home ID.
@property (nonatomic, assign) long long gid;
/// This property indicates whether the scene contains room information.
@property (nonatomic, assign) BOOL supportHome;
/// The type of scene, detail see `ThingSmartSceneRuleGenre`.
@property (nonatomic, assign) ThingSmartSceneRuleGenre ruleGenre;

@end

NS_ASSUME_NONNULL_END
