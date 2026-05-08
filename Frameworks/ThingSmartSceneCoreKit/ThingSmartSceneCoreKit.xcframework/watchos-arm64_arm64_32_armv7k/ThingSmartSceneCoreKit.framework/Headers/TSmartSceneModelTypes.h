//
//  TSmartSceneModelTypes.h
//  ThingSmartSceneCoreKit
//
//  Created by mile on 2023/8/3.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// The various biz sources for recommend scene.
typedef NS_ENUM(NSInteger, TSceneRecomBizType) {
    /// Unknown recommend source.
    TSceneRecomBizTypeUnknown = 0,
    /// Scene recommend source.
    TSceneRecomBizTypeScene,
    /// energy recommend source.
    TSceneRecomBizTypeEnergy,
    /// The warning recommend source.
    TSceneRecomBizTypeWarning
};

/// Describes whether the type of scene
typedef NS_ENUM(NSUInteger, ThingSmartSceneRuleGenre) {
    ThingSmartSceneRuleGenreNone = 0,
    ThingSmartSceneRuleGenreManual,
    ThingSmartSceneRuleGenreAuto
};

NS_ASSUME_NONNULL_END
