//
//  TSmartSceneActionInfoBuilder.h
//  ThingSmartSceneCoreKit
//
//  Created by mile on 2023/9/7.
//

#import <Foundation/Foundation.h>
#import "TSmartSceneActionInfoProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface TSmartSceneActionInfoBuilder : NSObject <TSmartSceneActionInfoProtocol>

@property (nonatomic, strong, readonly) ThingSmartSceneCoreFeatureModel *feature;
@property (nonatomic, strong, readonly) ThingSmartSceneCoreActionDpModel *actionDp;
@property (nonatomic, strong, readonly) NSString *dpId;

- (instancetype)initWithFeature:(ThingSmartSceneCoreFeatureModel *)feature actionDp:(ThingSmartSceneCoreActionDpModel *)actionDp;

@end

@interface TSmartSceneActionBoolBuidler : TSmartSceneActionInfoBuilder
@end

@interface TSmartSceneActionUneditableBuidler : TSmartSceneActionInfoBuilder
@end

@interface TSmartSceneActionColouredLightBuidler : TSmartSceneActionInfoBuilder
@end

@interface TSmartSceneActionWhiteLightBuidler : TSmartSceneActionInfoBuilder
@end

@interface TSmartSceneActionEnumBuidler : TSmartSceneActionInfoBuilder
@end

@interface TSmartSceneActionToggleBuidler : TSmartSceneActionInfoBuilder
@end

@interface TSmartSceneActionStepBuidler : TSmartSceneActionInfoBuilder
@end

@interface TSmartSceneActionPercentBuidler : TSmartSceneActionInfoBuilder
@end

@interface TSmartSceneActionCountdownBuidler : TSmartSceneActionInfoBuilder
@end

@interface TSmartSceneActionValueBuidler : TSmartSceneActionInfoBuilder
@end

NS_ASSUME_NONNULL_END
